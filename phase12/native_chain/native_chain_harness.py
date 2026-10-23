import os
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'phase11')))

import unicorn
from unicorn import arm64_const
from combat_engine import BattlefieldMemory

SO_PATH = r'E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so'

class NativeChainHarness:
    def __init__(self):
        with open(SO_PATH, 'rb') as f:
            self.so_data = f.read()

        # Extract genuine native machine code
        self.code_callee = self.so_data[0x6fd748 : 0x6fd748 + 12]  # GetBattlefieldBase (12 bytes)
        self.code_setpos = self.so_data[0x959830 : 0x95987c]        # SetUnitPosition (76 bytes)
        self.code_addkb  = self.so_data[0x959cf4 : 0x959d48]        # AddUnitKnockback (84 bytes)
        self.code_canmove= self.so_data[0x95a494 : 0x95a540]        # CheckUnitCanMove (172 bytes)

    def run_native_battle_step(self, team: int, unit: int, initial_pos: int, speed: int, 
                               flag_95c: int, flag_aec: int, flag_af0: int, initial_kb: int) -> dict:
        """
        Executes a real 3-function native sequence in Unicorn:
            Step 1: CheckUnitCanMove(team, unit) -> can_move
            Step 2: If kb > 0: AddUnitKnockback(team, unit, -1)
            Step 3: If can_move == 1 and kb == 0: SetUnitPosition(team, unit, initial_pos + speed)
        Returns observable outputs:
            can_move, final_kb, final_pos, sp_balanced
        """
        mu = unicorn.Uc(unicorn.UC_ARCH_ARM64, unicorn.UC_MODE_ARM)

        # 1. Map code pages at actual VMA
        mu.mem_map(0x6fd000, 0x10000)
        mu.mem_write(0x6fd748, self.code_callee)

        mu.mem_map(0x950000, 0x10000)
        mu.mem_write(0x959830, self.code_setpos)
        mu.mem_write(0x959cf4, self.code_addkb)
        mu.mem_write(0x95a494, self.code_canmove)

        # 2. Map stack
        STACK_BASE = 0x7fff0000
        mu.mem_map(STACK_BASE, 0x10000)
        SP = STACK_BASE + 0x8000

        # 3. Map BSS singleton page
        mu.mem_map(0x00b00000, 0x100000)
        BF_BASE = 0x00b0ef20

        # 4. Exit trap
        EXIT_ADDR = 0x958000
        mu.mem_write(EXIT_ADDR, b'\x1f\x20\x03\xd5') # nop

        # 5. Populate initial unit memory
        unit_base = BF_BASE + (team * 0xc738) + (unit * 0x3e8)
        mu.mem_write(unit_base + 0x83950, initial_pos.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x8395c, flag_95c.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x83aec, flag_aec.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x83af0, flag_af0.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x83ad4, initial_kb.to_bytes(4, 'little', signed=True))
        mu.mem_write(unit_base + 0x83adc, speed.to_bytes(4, 'little', signed=True))

        def call_native(func_addr, w0, w1, w2=0):
            mu.reg_write(arm64_const.UC_ARM64_REG_SP, SP)
            mu.reg_write(arm64_const.UC_ARM64_REG_X30, EXIT_ADDR)
            mu.reg_write(arm64_const.UC_ARM64_REG_W0, w0 & 0xffffffff)
            mu.reg_write(arm64_const.UC_ARM64_REG_W1, w1 & 0xffffffff)
            mu.reg_write(arm64_const.UC_ARM64_REG_W2, w2 & 0xffffffff)
            mu.emu_start(func_addr, EXIT_ADDR)
            res_w0 = mu.reg_read(arm64_const.UC_ARM64_REG_W0)
            sp_after = mu.reg_read(arm64_const.UC_ARM64_REG_SP)
            assert sp_after == SP, f"Stack balance violation in {hex(func_addr)}: {hex(sp_after)} != {hex(SP)}"
            return res_w0

        # --- EXECUTE NATIVE CHAIN ---
        # 1. Native Call: CheckUnitCanMove
        can_move = call_native(0x95a494, team, unit)

        # 2. Native Call: Knockback update
        curr_kb = initial_kb
        if curr_kb > 0:
            call_native(0x959cf4, team, unit, -1)
            curr_kb = int.from_bytes(mu.mem_read(unit_base + 0x83ad4, 4), 'little', signed=True)

        # 3. Native Call: Position update
        curr_pos = initial_pos
        if can_move == 1 and initial_kb == 0:
            new_pos = initial_pos + speed
            call_native(0x959830, team, unit, new_pos)
            curr_pos = int.from_bytes(mu.mem_read(unit_base + 0x83950, 4), 'little', signed=True)

        final_kb = int.from_bytes(mu.mem_read(unit_base + 0x83ad4, 4), 'little', signed=True)
        final_pos = int.from_bytes(mu.mem_read(unit_base + 0x83950, 4), 'little', signed=True)

        return {
            'can_move': can_move,
            'final_kb': final_kb,
            'final_pos': final_pos,
            'sp_balanced': True
        }

    @staticmethod
    def run_reconstructed_battle_step(team: int, unit: int, initial_pos: int, speed: int, 
                                      flag_95c: int, flag_aec: int, flag_af0: int, initial_kb: int) -> dict:
        """
        Equivalent clean-room reconstructed step in Python.
        """
        mem = BattlefieldMemory()
        mem.set_position_x(team, unit, initial_pos)
        mem.set_move_flag(team, unit, flag_95c)
        mem.set_speed(team, unit, speed)
        mem.set_knockback_state(team, unit, initial_kb)
        
        # Simulate check_can_move
        can_move = 0
        if flag_95c != 0:
            if flag_aec == 0:
                can_move = 1
            else:
                can_move = 3 if flag_af0 != 0 else 2

        # Knockback step
        curr_kb = initial_kb
        if curr_kb > 0:
            curr_kb = mem.add_knockback(team, unit, -1)

        # Position step
        curr_pos = initial_pos
        if can_move == 1 and initial_kb == 0:
            curr_pos = initial_pos + speed
            mem.set_position_x(team, unit, curr_pos)

        return {
            'can_move': can_move,
            'final_kb': mem.get_knockback_state(team, unit),
            'final_pos': mem.get_position_x(team, unit),
            'sp_balanced': True
        }
