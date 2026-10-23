"""
Phase 10 — Multi-Tier Combat Verification Test Suite
Explicitly categorizes tests into:
  - LEVEL 1: UNIT_TEST (Internal logic self-consistency)
  - LEVEL 2: STATIC_CONSISTENT (Layout & constants matching Ghidra/assembly)
  - LEVEL 3: NATIVE_BLOCK_PARITY (Unicorn emulation of real extracted AArch64 opcodes)
  - LEVEL 4: FULL_RUNTIME_PARITY (Whole Android OS dynamic execution -> BLOCKED)
"""

import unittest
import sys
import os

# Add paths
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), 'native_emulation')))
sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

from combat_core import BattlefieldMemory, NativeDamageEngine
from unicorn_harness import UnicornARM64Engine

# ==============================================================================
# LEVEL 1: UNIT_TEST
# ==============================================================================
class TestLevel1_UnitTests(unittest.TestCase):
    """
    Level 1: Reconstructed combat rules unit tests (retaining Phase 6-9 logic).
    """
    def setUp(self):
        self.mem = BattlefieldMemory()
        # Initialize target unit (Team 1, Unit 1)
        self.mem.set_unit_alive(1, 1, True)
        self.mem.set_unit_hp(1, 1, 1000)

    def test_normal_damage_application(self):
        res = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, 
                                             base_damage=250, multiplier_permille=1000)
        self.assertTrue(res['applied'])
        self.assertEqual(res['final_damage'], 250)
        self.assertEqual(res['remaining_hp'], 750)
        self.assertFalse(res['killed'])
        self.assertEqual(self.mem.get_unit_hp(1, 1), 750)

    def test_death_and_cleanup_trigger(self):
        res = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, 
                                             base_damage=1200, multiplier_permille=1000)
        self.assertTrue(res['applied'])
        self.assertEqual(res['remaining_hp'], 0)
        self.assertTrue(res['killed'])
        # Verify Battle_KillUnit zeroed out all 3 fields
        self.assertEqual(self.mem.get_unit_hp(1, 1), 0)
        self.assertFalse(self.mem.is_unit_alive(1, 1))
        self.assertEqual(self.mem.get_attack_timer(1, 1), 0)

    def test_knockback_threshold_trigger(self):
        res = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, 
                                             base_damage=400, multiplier_permille=1000, 
                                             kb_threshold=333)
        self.assertTrue(res['applied'])
        self.assertTrue(res['knockback'])
        self.assertEqual(self.mem.get_knockback_state(1, 1), 1)

    def test_barrier_absorption_and_break(self):
        self.mem.set_barrier(1, 1, 500)
        # 1. Damage less than barrier -> absorbed
        res1 = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, 
                                              base_damage=300, multiplier_permille=1000)
        self.assertEqual(res1['reason'], 'BARRIER_ABSORBED')
        self.assertEqual(self.mem.get_unit_hp(1, 1), 1000)
        
        # 2. Damage exceeding barrier -> breaks barrier and inflicts damage
        res2 = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, 
                                              base_damage=600, multiplier_permille=1000)
        self.assertEqual(res2['reason'], 'DAMAGE_APPLIED')
        self.assertEqual(self.mem.get_barrier(1, 1), 0)
        self.assertEqual(self.mem.get_unit_hp(1, 1), 400)

    def test_damage_on_dead_unit_ignored(self):
        self.mem.set_unit_alive(1, 1, False)
        res = NativeDamageEngine.apply_damage(self.mem, target_team=1, target_unit=1, base_damage=500)
        self.assertFalse(res['applied'])
        self.assertEqual(res['reason'], 'UNIT_NOT_ALIVE')


# ==============================================================================
# LEVEL 2: STATIC_CONSISTENT
# ==============================================================================
class TestLevel2_StaticConsistent(unittest.TestCase):
    """
    Level 2: Verifies memory model constants, stride formulas, and field offsets 
    derived from static disassembly of 0x00959800 ~ 0x0095a200.
    """
    def test_memory_stride_and_slot_count(self):
        # 0xc738 == 51000
        self.assertEqual(BattlefieldMemory.TEAM_STRIDE, 51000)
        # 0x3e8 == 1000
        self.assertEqual(BattlefieldMemory.UNIT_STRIDE, 1000)
        # Capacity: 51 slots
        self.assertEqual(BattlefieldMemory.MAX_UNITS_PER_TEAM, 51)
        # Total per team equals team stride
        self.assertEqual(BattlefieldMemory.MAX_UNITS_PER_TEAM * BattlefieldMemory.UNIT_STRIDE, 51000)

    def test_field_offsets_conformance(self):
        # Verify field offsets against AArch64 mov + movk disassembly
        self.assertEqual(BattlefieldMemory.OFFSET_POSITION_X, 0x83950)
        self.assertEqual(BattlefieldMemory.OFFSET_CURRENT_HP, 0x83960)
        self.assertEqual(BattlefieldMemory.OFFSET_IS_ALIVE, 0x83964)
        self.assertEqual(BattlefieldMemory.OFFSET_TARGET_REF, 0x83a08)
        self.assertEqual(BattlefieldMemory.OFFSET_ATTACK_STATE, 0x83a0c)
        self.assertEqual(BattlefieldMemory.OFFSET_ATTACK_TIMER, 0x83ac8)
        self.assertEqual(BattlefieldMemory.OFFSET_ATTACK_INTERVAL, 0x83acc)
        self.assertEqual(BattlefieldMemory.OFFSET_KNOCKBACK_STATE, 0x83ad4)
        self.assertEqual(BattlefieldMemory.OFFSET_SPEED, 0x83adc)
        self.assertEqual(BattlefieldMemory.OFFSET_STATUS_BARRIER, 0x83b0c)
        self.assertEqual(BattlefieldMemory.OFFSET_CASTLE_HP, 0x83cc8)

    def test_team_memory_non_overlapping(self):
        mem = BattlefieldMemory()
        # Write unique canary to last slot of Team 0 (Unit 50)
        mem.set_unit_hp(0, 50, 0x11223344)
        # Write unique canary to first slot of Team 1 (Unit 0)
        mem.set_unit_hp(1, 0, 0x55667788)
        
        # Verify no mutual corruption
        self.assertEqual(mem.get_unit_hp(0, 50), 0x11223344)
        self.assertEqual(mem.get_unit_hp(1, 0), 0x55667788)


# ==============================================================================
# LEVEL 3: NATIVE_BLOCK_PARITY
# ==============================================================================
class TestLevel3_NativeBlockParity(unittest.TestCase):
    """
    Level 3: Differential tests comparing Python reconstructed math against 
    Unicorn emulator executing raw AArch64 machine code from libnative-lib.so.
    """
    def test_magic_division_fixed_vectors(self):
        vectors = [
            (0, 0), (1000, 100), (1500, 200), (1234, 5678), 
            (1, 999), (1, 1000), (1, 1001), (-1000, 500), 
            (1, -999), (1, -1000), (1, -1001), (70000, 70000)
        ]
        for mult, dmg in vectors:
            native = UnicornARM64Engine.run_magic_div(mult, dmg)
            reconstructed = NativeDamageEngine.scale_permille(mult, dmg)
            self.assertEqual(native, reconstructed, f"Mismatch for ({mult}, {dmg}): native={native}, py={reconstructed}")

    def test_hp_address_read_native_parity(self):
        BASE = 0x10000000
        for team in [0, 1]:
            for unit in [0, 1, 25, 50]:
                test_hp = 50000 + team * 100 + unit
                
                # Raw memory setup for Unicorn
                mem_buf = bytearray(0x200000)
                rel_offset = (team * 0xc738) + (unit * 0x3e8) + 0x83960
                mem_buf[rel_offset : rel_offset + 4] = test_hp.to_bytes(4, 'little', signed=True)
                
                native_val = UnicornARM64Engine.run_hp_read(BASE, team, unit, bytes(mem_buf))
                
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, test_hp)
                py_val = py_mem.get_unit_hp(team, unit)
                
                self.assertEqual(native_val, py_val)

    def test_hp_address_write_native_parity(self):
        BASE = 0x10000000
        for team in [0, 1]:
            for unit in [0, 10, 50]:
                val = 778899 + team * 10 + unit
                native_written = UnicornARM64Engine.run_hp_write(BASE, team, unit, val)
                
                py_mem = BattlefieldMemory()
                py_mem.set_unit_hp(team, unit, val)
                py_val = py_mem.get_unit_hp(team, unit)
                
                self.assertEqual(native_written, py_val)


# ==============================================================================
# LEVEL 4: FULL_RUNTIME_PARITY
# ==============================================================================
class TestLevel4_FullRuntimeParity(unittest.TestCase):
    """
    Level 4: Full dynamic Android in-engine parity.
    Marked as BLOCKED due to host C: drive storage and ARM64 translation limits.
    """
    @unittest.skip("BLOCKED: Requires Android ARM64 runtime with ADB instrumentation (Host C: drive constrained, 0.47 GB free)")
    def test_full_android_apk_dynamic_parity(self):
        pass


if __name__ == '__main__':
    unittest.main(verbosity=2)
