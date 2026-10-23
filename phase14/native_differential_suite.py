"""
Phase 14 Native Multi-Function Differential Verification Suite.
Executes real AArch64 binary code from libnative-lib.so in Unicorn Engine.
Verifies:
1. Battle_GetTargetType (0x00957c8c)
2. Battle_GetAttackTimer (0x00959b50)
3. Battle_SetAttackTimer (0x00959b90)
4. Battle_GetUnitHP (0x00959880)
5. Battle_SetUnitHP (0x009598bc)
6. Battle_SetUnitAlive (0x00959950)
7. Battle_GetCastleHP (0x0095a068)
"""

import os
import sys
import struct
import unittest
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_PROT_ALL, UC_PROT_READ, UC_PROT_WRITE, UC_PROT_EXEC
from unicorn.arm64_const import (
    UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2, UC_ARM64_REG_X3,
    UC_ARM64_REG_SP, UC_ARM64_REG_PC, UC_ARM64_REG_X30
)

SO_PATH = r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so"

class Phase14NativeHarness:
    BATTLEFIELD_BASE = 0x00b0ef20
    STACK_TOP = 0x7fff8000
    RET_MAGIC = 0xdead0000

    def __init__(self):
        with open(SO_PATH, "rb") as f:
            self.so_data = f.read()

        self.uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
        # Map code page 0x006fd000 (for GetBattlefieldBase @ 0x006fd748)
        self.uc.mem_map(0x006fd000, 0x2000, UC_PROT_READ | UC_PROT_EXEC)
        self.uc.mem_write(0x006fd000, self.so_data[0x006fd000:0x006fd000 + 0x2000])

        # Map code pages 0x00957000 ~ 0x0095c000 (covering all combat functions)
        self.uc.mem_map(0x00957000, 0x5000, UC_PROT_READ | UC_PROT_EXEC)
        self.uc.mem_write(0x00957000, self.so_data[0x00957000:0x00957000 + 0x5000])

        # Map battlefield memory buffer at 0x00b0e000
        self.uc.mem_map(0x00b00000, 0x200000, UC_PROT_READ | UC_PROT_WRITE)
        self.uc.mem_write(0x00b00000, b'\x00' * 0x200000)

        # Map stack and magic ret trap
        self.uc.mem_map(0x7fff0000, 0x10000, UC_PROT_READ | UC_PROT_WRITE)
        self.uc.mem_map(0xdead0000, 0x1000, UC_PROT_READ | UC_PROT_EXEC)
        self.uc.mem_write(0xdead0000, b'\x00\x00\x00\x00') # Halt trap

    def reset_state(self):
        self.uc.mem_write(0x00b00000, b'\x00' * 0x200000)
        self.uc.reg_write(UC_ARM64_REG_SP, self.STACK_TOP)
        self.uc.reg_write(UC_ARM64_REG_X30, self.RET_MAGIC)

    def write_field(self, team: int, slot: int, offset: int, value: int):
        ea = self.BATTLEFIELD_BASE + (team * 51000) + (slot * 1000) + offset
        val_packed = struct.pack("<i", value)
        self.uc.mem_write(ea, val_packed)

    def read_field(self, team: int, slot: int, offset: int) -> int:
        ea = self.BATTLEFIELD_BASE + (team * 51000) + (slot * 1000) + offset
        data = self.uc.mem_read(ea, 4)
        return struct.unpack("<i", data)[0]

    def call_native(self, addr: int, a0: int = 0, a1: int = 0, a2: int = 0) -> int:
        self.uc.reg_write(UC_ARM64_REG_SP, self.STACK_TOP)
        self.uc.reg_write(UC_ARM64_REG_X30, self.RET_MAGIC)
        self.uc.reg_write(UC_ARM64_REG_X0, a0)
        self.uc.reg_write(UC_ARM64_REG_X1, a1)
        self.uc.reg_write(UC_ARM64_REG_X2, a2)
        self.uc.reg_write(UC_ARM64_REG_PC, addr)
        # Execute until return to RET_MAGIC
        self.uc.emu_start(addr, self.RET_MAGIC, timeout=2000000, count=200)
        ret_val = self.uc.reg_read(UC_ARM64_REG_X0)
        # Handle 32-bit signed
        return ((ret_val + 0x80000000) & 0xffffffff) - 0x80000000

class TestPhase14NativeDifferential(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.harness = Phase14NativeHarness()

    def setUp(self):
        self.harness.reset_state()

    def test_native_get_target_type(self):
        """0x00957c8c: Battle_GetTargetType(team) reads offset +0x8394c"""
        # Set team 0 to Single (0) and team 1 to Area (1)
        self.harness.write_field(team=0, slot=0, offset=0x8394c, value=0)
        self.harness.write_field(team=1, slot=0, offset=0x8394c, value=1)

        res0 = self.harness.call_native(0x00957c8c, a0=0)
        res1 = self.harness.call_native(0x00957c8c, a0=1)
        self.assertEqual(res0, 0, "Native Battle_GetTargetType Team 0 mismatch")
        self.assertEqual(res1, 1, "Native Battle_GetTargetType Team 1 mismatch")

    def test_native_attack_timer_accessors(self):
        """0x00959b90 (SetAttackTimer) & 0x00959b50 (GetAttackTimer) accessing +0x83ac8"""
        # Test across multiple slots and timer values
        vectors = [(0, 1, 45), (1, 5, 120), (0, 50, 0), (1, 25, 300)]
        for team, slot, timer in vectors:
            # Call Native Setter
            self.harness.call_native(0x00959b90, a0=team, a1=slot, a2=timer)
            # Check raw memory
            mem_val = self.harness.read_field(team, slot, 0x83ac8)
            self.assertEqual(mem_val, timer, f"Raw memory mismatch at +0x83ac8 for ({team}, {slot})")
            # Call Native Getter
            get_val = self.harness.call_native(0x00959b50, a0=team, a1=slot)
            self.assertEqual(get_val, timer, f"Native Getter mismatch for ({team}, {slot})")

    def test_native_unit_hp_accessors(self):
        """0x009598bc (SetUnitHP) & 0x0095987c (GetUnitHP) accessing +0x83960"""
        vectors = [(0, 1, 5000), (1, 10, 850), (0, 49, 1), (1, 50, 120000)]
        for team, slot, hp in vectors:
            self.harness.call_native(0x009598bc, a0=team, a1=slot, a2=hp)
            mem_val = self.harness.read_field(team, slot, 0x83960)
            self.assertEqual(mem_val, hp, f"HP memory mismatch for ({team}, {slot})")
            get_val = self.harness.call_native(0x0095987c, a0=team, a1=slot)
            self.assertEqual(get_val, hp, f"HP Native Getter mismatch for ({team}, {slot})")

    def test_native_unit_alive_setter(self):
        """0x00959950 (SetUnitAlive) accessing +0x83964"""
        for state in [1, 0, 1]:
            self.harness.call_native(0x00959950, a0=0, a1=7, a2=state)
            mem_val = self.harness.read_field(team=0, slot=7, offset=0x83964)
            self.assertEqual(mem_val, state, f"Alive state mismatch for slot 7 state={state}")

    def test_native_castle_hp_getter(self):
        """0x0095a068 (GetCastleHP) accessing +0x83cc8"""
        self.harness.write_field(team=0, slot=0, offset=0x83cc8, value=99999)
        self.harness.write_field(team=1, slot=0, offset=0x83cc8, value=45000)

        res0 = self.harness.call_native(0x0095a068, a0=0, a1=0)
        res1 = self.harness.call_native(0x0095a068, a0=1, a1=0)
        self.assertEqual(res0, 99999, "Cat castle HP getter mismatch")
        self.assertEqual(res1, 45000, "Enemy castle HP getter mismatch")

if __name__ == "__main__":
    unittest.main()
