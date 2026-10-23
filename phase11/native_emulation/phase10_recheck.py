import os
import sys
import struct
import hashlib
import random

# Add venv/paths
sys.path.insert(0, os.path.abspath(r'E:\rea\phase10\native_emulation'))
sys.path.insert(0, os.path.abspath(r'E:\rea\phase10'))

import unicorn
from unicorn import arm64_const
from unicorn_harness import UnicornARM64Engine
from combat_core import BattlefieldMemory, NativeDamageEngine

SO_PATH = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'
PHASE10_BUNDLE = r'E:\rea\phase10\evidence_bundle'
RANDOM_SEED = 0x1337

def run_independent_recheck():
    results = {}
    
    # 1. SHA-256
    with open(SO_PATH, 'rb') as f:
        so_data = f.read()
    so_hash = hashlib.sha256(so_data).hexdigest()
    results['so_sha256'] = so_hash
    print(f"[1] SO SHA-256: {so_hash}")

    # 2. ELF Program Header mapping
    e_phoff = struct.unpack_from('<Q', so_data, 32)[0]
    e_phentsize = struct.unpack_from('<H', so_data, 54)[0]
    e_phnum = struct.unpack_from('<H', so_data, 56)[0]
    
    load_segments = []
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack_from('<IIQQQQQQ', so_data, off)
        if p_type == 1: # PT_LOAD
            load_segments.append({
                'index': i,
                'offset': p_offset,
                'vaddr': p_vaddr,
                'filesz': p_filesz,
                'memsz': p_memsz,
                'flags': p_flags
            })
    results['load_segments'] = load_segments
    print(f"[2] PT_LOAD Segments Parsed: {len(load_segments)}")

    def vma_to_offset(vma):
        for seg in load_segments:
            if seg['vaddr'] <= vma < seg['vaddr'] + seg['memsz']:
                return vma - seg['vaddr'] + seg['offset']
        return None

    # 3 & 4. Re-extract and compare with evidence_bundle
    snippets = [
        ('magic_div_0x4c6800.bin', 0x004c6800, 32),
        ('hp_read_0x959894.bin', 0x00959894, 28),
        ('hp_write_0x9598dc.bin', 0x009598dc, 28)
    ]
    
    extraction_matches = True
    snippet_data = {}
    for filename, vma, size in snippets:
        calc_offset = vma_to_offset(vma)
        re_extracted = so_data[calc_offset : calc_offset + size]
        bundle_path = os.path.join(PHASE10_BUNDLE, filename)
        with open(bundle_path, 'rb') as f:
            bundle_bytes = f.read()
        match = (re_extracted == bundle_bytes)
        snippet_data[filename] = {
            'vma': hex(vma),
            'offset': hex(calc_offset),
            'size': size,
            'match': match,
            'hex': re_extracted.hex()
        }
        if not match:
            extraction_matches = False
        print(f"[3-4] Snippet {filename}: VMA={hex(vma)} -> Offset={hex(calc_offset)} ({size} bytes) Match={match}")

    results['extraction'] = snippet_data
    results['extraction_matches'] = extraction_matches

    # 5, 6, 7. Execute Differential Tests with separate counts
    stats = {
        'magic_div': {'fixed_count': 0, 'fixed_pass': 0, 'fuzz_count': 0, 'fuzz_pass': 0, 'regs': 'w0, w23 -> w23'},
        'hp_read': {'count': 0, 'pass': 0, 'regs': 'x0, w20, w19 -> w0'},
        'hp_write': {'count': 0, 'pass': 0, 'regs': 'x0, w21, w20, w19 -> memory'}
    }

    # Snippet 1 Fixed
    fixed_vectors = [
        (0, 0), (1000, 100), (1500, 200), (1234, 5678), 
        (1, 999), (1, 1000), (1, 1001), (10, 100), (2500, 40000),
        (-1000, 500), (1000, -500), (-1500, 200), (1, -999), (1, -1000), (1, -1001),
        (1000, 2147483), (70000, 70000)
    ]
    for mult, dmg in fixed_vectors:
        stats['magic_div']['fixed_count'] += 1
        native = UnicornARM64Engine.run_magic_div(mult, dmg)
        py_res = NativeDamageEngine.scale_permille(mult, dmg)
        if native == py_res:
            stats['magic_div']['fixed_pass'] += 1

    # Snippet 1 Fuzz
    random.seed(RANDOM_SEED)
    for _ in range(1000):
        stats['magic_div']['fuzz_count'] += 1
        mult = random.randint(-5000, 5000)
        dmg = random.randint(-500000, 500000)
        native = UnicornARM64Engine.run_magic_div(mult, dmg)
        py_res = NativeDamageEngine.scale_permille(mult, dmg)
        if native == py_res:
            stats['magic_div']['fuzz_pass'] += 1

    # Snippet 2 HP Read
    BATTLEFIELD_BASE = 0x10000000
    test_units = [0, 1, 5, 25, 49, 50]
    test_teams = [0, 1]
    for team in test_teams:
        for unit in test_units:
            for hp in [1, 500, 15000, 999999]:
                stats['hp_read']['count'] += 1
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, hp)
                py_val = py_mem.get_unit_hp(team, unit)
                
                mem_buf = bytearray(0x200000)
                rel_offset = (team * 0xc738) + (unit * 0x3e8) + 0x83960
                mem_buf[rel_offset : rel_offset + 4] = hp.to_bytes(4, 'little', signed=True)
                native_val = UnicornARM64Engine.run_hp_read(BATTLEFIELD_BASE, team, unit, bytes(mem_buf))
                if native_val == py_val:
                    stats['hp_read']['pass'] += 1

    # Snippet 3 HP Write
    for team in [0, 1]:
        for unit in [0, 1, 20, 50]:
            for new_hp in [0, 42, 65535, 1234567]:
                stats['hp_write']['count'] += 1
                native_written = UnicornARM64Engine.run_hp_write(BATTLEFIELD_BASE, team, unit, new_hp)
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, new_hp)
                py_val = py_mem.get_unit_hp(team, unit)
                if native_written == py_val:
                    stats['hp_write']['pass'] += 1

    results['stats'] = stats
    print(f"[5-8] Differential Test Results:")
    print(f"      - Magic Div: Fixed={stats['magic_div']['fixed_pass']}/{stats['magic_div']['fixed_count']}, Fuzz={stats['magic_div']['fuzz_pass']}/{stats['magic_div']['fuzz_count']}")
    print(f"      - HP Read:   {stats['hp_read']['pass']}/{stats['hp_read']['count']}")
    print(f"      - HP Write:  {stats['hp_write']['pass']}/{stats['hp_write']['count']}")

    # 9 & 10. Mutation Testing
    mutations = [
        {
            'name': 'Mutate Magic Constant (0x10624dd3 -> 0x10624dd2)',
            'type': 'magic_div',
            'test_input': (1500, 200)
        },
        {
            'name': 'Mutate Shift Count (38 -> 37)',
            'fn': lambda m, d: int((m * d * 0x10624dd3) >> 37),
            'type': 'magic_div',
            'test_input': (1000, 100)
        },
        {
            'name': 'Mutate Team Stride (51000 -> 50996)',
            'type': 'hp_read',
            'stride_team': 50996,
            'test_input': (1, 3, 45000)
        },
        {
            'name': 'Mutate Unit Stride (1000 -> 1004)',
            'type': 'hp_read',
            'stride_unit': 1004,
            'test_input': (0, 5, 12000)
        },
        {
            'name': 'Remove Sign Bit Correction on Negative Division',
            'fn': lambda m, d: ((m * d) * 0x10624dd3) >> 38,
            'type': 'magic_div',
            'test_input': (1, -1001)
        }
    ]

    mutation_results = []
    all_mutations_detected = True

    print("\n[9-10] Executing Mutation Testing...")
    for mut in mutations:
        detected = False
        native_out = None
        mutated_out = None
        
        if mut['type'] == 'magic_div':
            m, d = mut['test_input']
            native_out = UnicornARM64Engine.run_magic_div(m, d)
            if 'Shift' in mut['name']:
                # mutate shift
                w9 = (m * d) & 0xffffffff
                if w9 >= 0x80000000: w9 -= 0x100000000
                mutated_out = ((w9 * 0x10624dd3) >> 37) & 0xffffffff
                if mutated_out >= 0x80000000: mutated_out -= 0x100000000
            elif 'Constant' in mut['name']:
                w9 = (m * d) & 0xffffffff
                if w9 >= 0x80000000: w9 -= 0x100000000
                prod = w9 * 0x10624dd2
                sign = 1 if prod < 0 else 0
                mutated_out = (prod >> 38) + sign
            elif 'Sign Bit' in mut['name']:
                w9 = (m * d) & 0xffffffff
                if w9 >= 0x80000000: w9 -= 0x100000000
                prod = w9 * 0x10624dd3
                # Omit sign bit
                mutated_out = prod >> 38
            detected = (native_out != mutated_out)
        
        elif mut['type'] == 'hp_read':
            team, unit, hp = mut['test_input']
            stride_t = mut.get('stride_team', 51000)
            stride_u = mut.get('stride_unit', 1000)
            
            # Unicorn reads from real hardware address formula: 51000 * team + 1000 * unit + 0x83960
            mem_buf = bytearray(0x200000)
            native_ea = (team * 51000) + (unit * 1000) + 0x83960
            mem_buf[native_ea : native_ea + 4] = hp.to_bytes(4, 'little', signed=True)
            native_out = UnicornARM64Engine.run_hp_read(BATTLEFIELD_BASE, team, unit, bytes(mem_buf))
            
            # Mutated Python calculation reads from wrong offset in buffer
            mutated_ea = (team * stride_t) + (unit * stride_u) + 0x83960
            mutated_out = int.from_bytes(mem_buf[mutated_ea : mutated_ea + 4], 'little', signed=True)
            detected = (native_out != mutated_out)

        if not detected:
            all_mutations_detected = False
            
        res_entry = {
            'name': mut['name'],
            'inputs': mut['test_input'],
            'native_out': native_out,
            'mutated_out': mutated_out,
            'detected': detected
        }
        mutation_results.append(res_entry)
        status = "DETECTED (PASS)" if detected else "NOT DETECTED (FAIL)"
        print(f"      - {mut['name']}: Native={native_out}, Mutated={mutated_out} -> {status}")

    results['mutations'] = mutation_results
    results['all_mutations_detected'] = all_mutations_detected
    return results

if __name__ == '__main__':
    res = run_independent_recheck()
    print("\n[+] Independent Recheck Complete. All mutations detected:", res['all_mutations_detected'])
