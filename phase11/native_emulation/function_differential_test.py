import os
import sys
import unittest

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'phase10')))

import unicorn
from unicorn import arm64_const
from combat_core import BattlefieldMemory

SO_PATH = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

class NativeFunctionHarness:
    def __init__(self):
        with open(SO_PATH, 'rb') as f:
            self.so_data = f.read()

        # Extract real function bytes
        self.code_add_kb = self.so_data[0x959cf4 : 0x959d48]       # 84 bytes
        self.code_can_move = self.so_data[0x95a494 : 0x95a53c + 4] # 172 bytes
        self.code_callee = self.so_data[0x6fd748 : 0x6fd748 + 12]   # 12 bytes

    def _setup_mu(self):
        mu = unicorn.Uc(unicorn.UC_ARCH_ARM64, unicorn.UC_MODE_ARM)
        
        # 1. Map code pages
        mu.mem_map(0x950000, 0x10000) # Contains functions
        mu.mem_map(0x6fd000, 0x10000) # Contains 0x6fd748 callee
        mu.mem_write(0x6fd748, self.code_callee)
        
        # 2. Map stack page
        STACK_BASE = 0x7fff0000
        mu.mem_map(STACK_BASE, 0x10000)
        mu.reg_write(arm64_const.UC_ARM64_REG_SP, STACK_BASE + 0x8000)
        
        # 3. Map BSS singleton page (0x00b0e000 + 0xf20 = 0x00b0ef20)
        mu.mem_map(0x00b00000, 0x100000)
        
        # 4. Exit harness
        EXIT_ADDR = 0x958000
        mu.mem_write(EXIT_ADDR, b'\x1f\x20\x03\xd5') # nop
        mu.reg_write(arm64_const.UC_ARM64_REG_X30, EXIT_ADDR)
        
        return mu, EXIT_ADDR

    def run_add_knockback(self, team: int, unit: int, initial_kb: int, delta: int) -> int:
        mu, exit_addr = self._setup_mu()
        mu.mem_write(0x959cf4, self.code_add_kb)
        
        BF_BASE = 0x00b0ef20
        target_ea = BF_BASE + (team * 0xc738) + (unit * 0x3e8) + 0x83ad4
        mu.mem_write(target_ea, initial_kb.to_bytes(4, 'little', signed=True))
        
        mu.reg_write(arm64_const.UC_ARM64_REG_W0, team & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W1, unit & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W2, delta & 0xffffffff)
        
        mu.emu_start(0x959cf4, exit_addr)
        
        written_bytes = mu.mem_read(target_ea, 4)
        return int.from_bytes(written_bytes, 'little', signed=True)

    def run_check_can_move(self, team: int, unit: int, flag_95c: int, flag_aec: int) -> int:
        mu, exit_addr = self._setup_mu()
        mu.mem_write(0x95a494, self.code_can_move)
        
        BF_BASE = 0x00b0ef20
        unit_base = BF_BASE + (team * 0xc738) + (unit * 0x3e8)
        mu.mem_write(unit_base + 0x8395c, flag_95c.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x83aec, flag_aec.to_bytes(4, 'little', signed=True))
        
        mu.reg_write(arm64_const.UC_ARM64_REG_W0, team & 0xffffffff)
        mu.reg_write(arm64_const.UC_ARM64_REG_W1, unit & 0xffffffff)
        
        mu.emu_start(0x95a494, exit_addr)
        res_w0 = mu.reg_read(arm64_const.UC_ARM64_REG_W0)
        return res_w0

class TestFullFunctionDifferential(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.harness = NativeFunctionHarness()

    def test_add_knockback_matrix(self):
        # Test vector combinations across teams, units, and deltas
        vectors = [
            # (team, unit, initial, delta)
            (0, 1, 10, -1),   # Standard frame decay
            (0, 1, 1, -1),    # Decay to zero
            (0, 1, 0, 15),    # Trigger new knockback
            (1, 5, 20, -1),   # Enemy team decay
            (1, 50, 0, 30),   # Slot 50 knockback trigger
            (0, 0, 0, 0),     # Castle immunity / 0 delta
            (1, 10, 5, -5),   # Exact depletion
            (0, 25, -10, 5),  # Negative boundary
        ]
        
        for team, unit, init_kb, delta in vectors:
            native_res = self.harness.run_add_knockback(team, unit, init_kb, delta)
            
            # Python model
            py_mem = BattlefieldMemory()
            py_mem.set_knockback_state(team, unit, init_kb)
            # Replicate native in-place add
            curr = py_mem.get_knockback_state(team, unit)
            py_mem.set_knockback_state(team, unit, curr + delta)
            py_res = py_mem.get_knockback_state(team, unit)
            
            self.assertEqual(native_res, py_res, f"Mismatch: Team {team}, Unit {unit}, Init {init_kb}, Delta {delta}")
            print(f"  [PASS] AddKnockback: ({team}, {unit}, {init_kb}, {delta}) -> Native={native_res}, Py={py_res}")

    def test_can_move_branch_coverage(self):
        # Path A: Stopped/Dead (flag_95c == 0) -> Returns 0
        res_a = self.harness.run_check_can_move(0, 1, flag_95c=0, flag_aec=0)
        self.assertEqual(res_a, 0)
        print("  [PASS] CanMove Branch A (flag_95c=0) -> w0=0 (Stopped)")

        # Path B: Normal Forward (flag_95c != 0, flag_aec == 0) -> Returns 1
        res_b = self.harness.run_check_can_move(0, 1, flag_95c=1, flag_aec=0)
        self.assertEqual(res_b, 1)
        print("  [PASS] CanMove Branch B (flag_95c=1, flag_aec=0) -> w0=1 (Normal Forward)")

        # Path C: Slow / Special State (flag_95c != 0, flag_aec != 0) -> Returns 2
        res_c = self.harness.run_check_can_move(0, 1, flag_95c=1, flag_aec=1)
        self.assertEqual(res_c, 2)
        print("  [PASS] CanMove Branch C (flag_95c=1, flag_aec=1) -> w0=2 (Special / Slow)")

if __name__ == '__main__':
    unittest.main(verbosity=2)
