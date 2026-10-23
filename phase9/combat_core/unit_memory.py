"""
Native-Equivalent Unit Memory Layout and Flat Array Accessor
Reconstructed from libnative-lib.so (0x00959800 - 0x0095a200 & 0x008b6f50)
"""

from enum import IntEnum
from typing import Dict, Tuple

class NativeUnitField(IntEnum):
    UNIT_ID         = 0x00083924  # 0x0095a194
    POSITION_X      = 0x00083950  # 0x00959800 / 0x00959830
    CURRENT_HP      = 0x00083960  # 0x0095987c / 0x009598bc
    IS_ALIVE        = 0x00083964  # 0x00959908 / 0x00959950
    TARGET_REF      = 0x00083A08  # 0x0095999c / 0x00959a04
    ATTACK_STATE    = 0x00083A0C  # 0x00959a70 / 0x00959ab0
    ATTACK_TIMER    = 0x00083AC8  # 0x00959b50 / 0x00959b90
    ATTACK_INTERVAL = 0x00083ACC  # 0x00959bdc / 0x00959c1c
    KNOCKBACK_STATE = 0x00083AD4  # 0x00959c68 / 0x00959ca8
    SPEED           = 0x00083ADC  # 0x00959d48 / 0x00959d88
    STATUS_SLOW     = 0x00083B00  # 0x00959e28 / 0x00959e68
    STATUS_FREEZE   = 0x00083B04  # 0x00959eb4 / 0x00959ef4
    STATUS_WEAKEN   = 0x00083B08  # 0x00959f40 / 0x00959f88
    STATUS_BARRIER  = 0x00083B0C  # 0x00959fd4 / 0x0095a01c
    CASTLE_HP       = 0x00083CC8  # 0x0095a068 / 0x0095a0a8

class BattlefieldMemory:
    """
    Implements the 2D flat memory addressing architecture used by the Ponos engine:
      base_addr + (team * TEAM_STRIDE) + (unit_index * UNIT_STRIDE) + FIELD_OFFSET
    """
    TEAM_STRIDE = 50996  # 0xc738 bytes per team (mov w8, #0xc738)
    UNIT_STRIDE = 1000   # 0x3e8 bytes per unit entity (mov w9, #0x3e8)
    MAX_UNITS = 50

    def __init__(self):
        # Sparse dictionary simulating continuous 32-bit memory cells: (team, unit_index, field_offset) -> int32
        self._memory: Dict[Tuple[int, int, int], int] = {}
        self.castle_hp = [10000, 10000] # Team 0 (Cat Base), Team 1 (Enemy Base)

    def _read_field(self, team: int, unit_index: int, field: NativeUnitField) -> int:
        return self._memory.get((team, unit_index, int(field)), 0)

    def _write_field(self, team: int, unit_index: int, field: NativeUnitField, value: int):
        self._memory[(team, unit_index, int(field))] = int(value)

    # 1. HP Accessors (0x0095987c & 0x009598bc)
    def get_unit_hp(self, team: int, unit_index: int) -> int:
        """Native equivalent of 0x0095987c: ldr w0, [x8, #0x83960]"""
        return self._read_field(team, unit_index, NativeUnitField.CURRENT_HP)

    def set_unit_hp(self, team: int, unit_index: int, hp: int):
        """Native equivalent of 0x009598bc: str w19, [x8, #0x83960]"""
        self._write_field(team, unit_index, NativeUnitField.CURRENT_HP, max(0, hp))

    # 2. IsAlive Accessors (0x00959908 & 0x00959950)
    def is_unit_alive(self, team: int, unit_index: int) -> bool:
        """Native equivalent of 0x00959908: cmp w8, #0; cset w0, ne"""
        return self._read_field(team, unit_index, NativeUnitField.IS_ALIVE) != 0

    def set_unit_alive(self, team: int, unit_index: int, alive: bool):
        """Native equivalent of 0x00959950: and w21, w2, #1; str w21, [x8, #0x83964]"""
        self._write_field(team, unit_index, NativeUnitField.IS_ALIVE, 1 if alive else 0)

    # 3. Position Accessors (0x00959800 & 0x00959830)
    def get_unit_position(self, team: int, unit_index: int) -> int:
        """Native equivalent of 0x00959800: ldr w0, [x8, #0x83950]"""
        return self._read_field(team, unit_index, NativeUnitField.POSITION_X)

    def set_unit_position(self, team: int, unit_index: int, pos: int):
        """Native equivalent of 0x00959830: str w19, [x8, #0x83950]"""
        self._write_field(team, unit_index, NativeUnitField.POSITION_X, pos)

    # 4. Target Accessors (0x0095999c & 0x00959a04)
    def get_unit_target(self, team: int, unit_index: int) -> int:
        """Native equivalent of 0x0095999c: ldr w0, [x8, #0x83a08]"""
        return self._read_field(team, unit_index, NativeUnitField.TARGET_REF)

    def set_unit_target(self, team: int, unit_index: int, target: int):
        """Native equivalent of 0x00959a04: str w19, [x8, #0x83a08]"""
        self._write_field(team, unit_index, NativeUnitField.TARGET_REF, target)

    # 5. Attack Timer Accessors (0x00959b50 & 0x00959b90)
    def get_attack_timer(self, team: int, unit_index: int) -> int:
        """Native equivalent of 0x00959b50: ldr w0, [x8, #0x83ac8]"""
        return self._read_field(team, unit_index, NativeUnitField.ATTACK_TIMER)

    def set_attack_timer(self, team: int, unit_index: int, timer: int):
        """Native equivalent of 0x00959b90: str w19, [x8, #0x83ac8]"""
        self._write_field(team, unit_index, NativeUnitField.ATTACK_TIMER, timer)

    # 6. Knockback Accessors (0x00959c68 & 0x00959ca8)
    def get_knockback(self, team: int, unit_index: int) -> int:
        """Native equivalent of 0x00959c68: ldr w0, [x8, #0x83ad4]"""
        return self._read_field(team, unit_index, NativeUnitField.KNOCKBACK_STATE)

    def set_knockback(self, team: int, unit_index: int, kb: int):
        """Native equivalent of 0x00959ca8: str w19, [x8, #0x83ad4]"""
        self._write_field(team, unit_index, NativeUnitField.KNOCKBACK_STATE, kb)

    # 7. Unit Death Clean-up (0x008b6f50 - 0x008b6fa8)
    def kill_unit(self, team: int, unit_index: int):
        """
        Native equivalent of Battle_KillUnit (0x008b6f50):
          0x008b6f88: SetUnitHP(team, unit, 0)
          0x008b6f98: SetUnitAlive(team, unit, 0)
          0x008b6fa8: SetUnitAttackTimer(team, unit, 0)
        """
        self.set_unit_hp(team, unit_index, 0)
        self.set_unit_alive(team, unit_index, False)
        self.set_attack_timer(team, unit_index, 0)
