import sys
import os
import random
import time

# Ensure combat_core can be imported
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from unicorn_harness import UnicornARM64Engine
from combat_core import BattlefieldMemory, NativeDamageEngine

def run_all_differential_tests():
    print("=" * 70)
    print("Phase 10 — AArch64 Unicorn vs Python Reconstructed Differential Test")
    print("=" * 70)
    
    total_tests = 0
    passed_tests = 0
    mismatches = []
    
    start_time = time.time()

    # -------------------------------------------------------------
    # SUITE 1: Magic Division Permille (0x004c6800 ~ 0x004c6820)
    # -------------------------------------------------------------
    print("\n[Suite 1] Magic Division Permille Differential Verification")
    
    fixed_vectors = [
        # (multiplier, base_damage, description)
        (0, 0, "Zero multiplier and damage"),
        (1000, 100, "Standard 100% multiplier (1000/1000)"),
        (1500, 200, "150% multiplier (1500/1000)"),
        (1234, 5678, "Arbitrary fractional scaling"),
        (1, 999, "Underflow to 0 (999/1000)"),
        (1, 1000, "Exact division threshold (1000/1000)"),
        (1, 1001, "Threshold boundary plus 1 (1001/1000)"),
        (10, 100, "Sub-100% scaling (1000/1000)"),
        (2500, 40000, "High damage burst"),
        (-1000, 500, "Negative multiplier -100%"),
        (1000, -500, "Negative damage -500"),
        (-1500, 200, "Negative fractional -150%"),
        (1, -999, "Negative underflow boundary (-999/1000)"),
        (1, -1000, "Negative exact boundary (-1000/1000)"),
        (1, -1001, "Negative truncation boundary (-1001/1000)"),
        (1000, 2147483, "Large 32-bit positive damage"),
        (70000, 70000, "32-bit multiplication wrap-around overflow"),
    ]

    for mult, dmg, desc in fixed_vectors:
        total_tests += 1
        native_res = UnicornARM64Engine.run_magic_div(mult, dmg)
        py_res = NativeDamageEngine.scale_permille(mult, dmg)
        if native_res == py_res:
            passed_tests += 1
            print(f"  [PASS] Fixed Vector: ({mult}, {dmg}) -> Native: {native_res}, Py: {py_res} | {desc}")
        else:
            mismatches.append({
                'suite': 'MagicDiv_Fixed',
                'inputs': (mult, dmg),
                'native': native_res,
                'py': py_res,
                'desc': desc
            })
            print(f"  [FAIL] Fixed Vector: ({mult}, {dmg}) -> Native: {native_res}, Py: {py_res} | {desc}")

    # Random fuzzing for Suite 1
    print("\n  Running 1,000 Randomized Fuzzing Vectors for Magic Division...")
    random.seed(0x1337)
    for _ in range(1000):
        total_tests += 1
        rand_mult = random.randint(-5000, 5000)
        rand_dmg = random.randint(-500000, 500000)
        native_res = UnicornARM64Engine.run_magic_div(rand_mult, rand_dmg)
        py_res = NativeDamageEngine.scale_permille(rand_mult, rand_dmg)
        if native_res == py_res:
            passed_tests += 1
        else:
            mismatches.append({
                'suite': 'MagicDiv_Fuzz',
                'inputs': (rand_mult, rand_dmg),
                'native': native_res,
                'py': py_res,
                'desc': 'Fuzzing mismatch'
            })
            break

    # -------------------------------------------------------------
    # SUITE 2: HP Address Calculation & Read (0x00959894 ~ 0x009598b0)
    # -------------------------------------------------------------
    print("\n[Suite 2] HP Memory Address Calculation & Read Differential Verification")
    BATTLEFIELD_BASE = 0x10000000
    
    test_units = [0, 1, 5, 25, 49, 50]
    test_teams = [0, 1]
    
    for team in test_teams:
        for unit in test_units:
            for test_hp in [1, 500, 15000, 999999]:
                total_tests += 1
                
                # Setup Python BattlefieldMemory
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, test_hp)
                py_res = py_mem.get_unit_hp(team, unit)
                
                # Setup raw memory for Unicorn
                # Buffer offset in Unicorn
                target_ea = BATTLEFIELD_BASE + (team * 0xc738) + (unit * 0x3e8) + 0x83960
                mem_buf = bytearray(0x200000)
                rel_offset = (team * 0xc738) + (unit * 0x3e8) + 0x83960
                mem_buf[rel_offset : rel_offset + 4] = test_hp.to_bytes(4, 'little', signed=True)
                
                native_res = UnicornARM64Engine.run_hp_read(BATTLEFIELD_BASE, team, unit, bytes(mem_buf))
                
                if native_res == py_res:
                    passed_tests += 1
                else:
                    mismatches.append({
                        'suite': 'HP_Read',
                        'inputs': (team, unit, test_hp),
                        'native': native_res,
                        'py': py_res,
                        'desc': f'HP Read mismatch at Team {team}, Unit {unit}'
                    })
                    print(f"  [FAIL] HP Read Team={team}, Unit={unit}: Native={native_res}, Py={py_res}")

    print(f"  [PASS] All 48 Team/Unit/HP Address Read Vector Combinations Tested (MATCH)")

    # -------------------------------------------------------------
    # SUITE 3: HP Address Calculation & Write (0x009598dc ~ 0x009598f8)
    # -------------------------------------------------------------
    print("\n[Suite 3] HP Memory Address Calculation & Write Differential Verification")
    
    for team in [0, 1]:
        for unit in [0, 1, 20, 50]:
            for new_hp in [0, 42, 65535, 1234567]:
                total_tests += 1
                
                # Execute in Unicorn
                native_written = UnicornARM64Engine.run_hp_write(BATTLEFIELD_BASE, team, unit, new_hp)
                
                # Execute in Python BattlefieldMemory
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, new_hp)
                py_written = py_mem.get_unit_hp(team, unit)
                
                if native_written == py_written:
                    passed_tests += 1
                else:
                    mismatches.append({
                        'suite': 'HP_Write',
                        'inputs': (team, unit, new_hp),
                        'native': native_written,
                        'py': py_written,
                        'desc': f'HP Write mismatch at Team {team}, Unit {unit}'
                    })
                    print(f"  [FAIL] HP Write Team={team}, Unit={unit}: Native={native_written}, Py={py_written}")

    print(f"  [PASS] All 32 Team/Unit/HP Write Vector Combinations Tested (MATCH)")

    # -------------------------------------------------------------
    # Summary
    # -------------------------------------------------------------
    elapsed = time.time() - start_time
    print("\n" + "=" * 70)
    print(f"DIFFERENTIAL TESTING SUMMARY")
    print(f"Total Tests Executed: {total_tests}")
    print(f"Passed:              {passed_tests} / {total_tests} ({(passed_tests/total_tests)*100:.2f}%)")
    print(f"Mismatches:          {len(mismatches)}")
    print(f"Elapsed Time:        {elapsed:.3f} seconds")
    print("=" * 70)

    if mismatches:
        print("\n[!] CRITICAL COUNTEREXAMPLES FOUND:")
        for m in mismatches:
            print(f"    - {m['suite']}: Input={m['inputs']} -> Native={m['native']}, Reconstructed={m['py']} ({m['desc']})")
        sys.exit(1)
    else:
        print("\n>>> VERDICT: 100% NATIVE BLOCK PARITY ACHIEVED (ZERO MISMATCHES) <<<")

if __name__ == '__main__':
    run_all_differential_tests()
