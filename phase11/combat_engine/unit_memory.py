"""
BattlefieldMemory - Clean-room model of The Battle Cats battlefield entity memory.
Reflects verified AArch64 layout:
- Team Stride: 51,000 bytes (0xc738)
- Unit Stride: 1,000 bytes (0x3e8)
- 51 slots per team (Slot 0 = Castle, Slots 1..50 = Units)
"""

import struct

class BattlefieldMemory:
    TEAM_STRIDE = 0xc738      # 51,000 bytes per team
    UNIT_STRIDE = 0x3e8       # 1,000 bytes per unit slot
    MAX_UNITS_PER_TEAM = 51   # Slot 0 (Castle) + Slots 1..50 (Units)
    
    # Absolute field offsets as accessed in 0x00959800 ~ 0x0095a600
    OFFSET_UNIT_ID         = 0x83924
    OFFSET_NEXT_POSITION   = 0x83938
    OFFSET_POSITION_X      = 0x83950
    OFFSET_MOVE_FLAG       = 0x8395c
    OFFSET_CURRENT_HP      = 0x83960
    OFFSET_IS_ALIVE        = 0x83964
    OFFSET_TARGET_REF      = 0x83a08
    OFFSET_ATTACK_STATE    = 0x83a0c
    OFFSET_ATTACK_TIMER    = 0x83ac8
    OFFSET_ATTACK_INTERVAL = 0x83acc
    OFFSET_KNOCKBACK_STATE = 0x83ad4
    OFFSET_SPEED           = 0x83adc
    OFFSET_MOVE_SPECIAL    = 0x83aec
    OFFSET_STATUS_SLOW     = 0x83b00
    OFFSET_STATUS_FREEZE   = 0x83b04
    OFFSET_STATUS_WEAKEN   = 0x83b08
    OFFSET_STATUS_BARRIER  = 0x83b0c
    OFFSET_CASTLE_HP       = 0x83cc8

    def __init__(self, size=0x150000):
        self.buffer = bytearray(size)

    def _calc_address(self, team: int, unit_index: int, field_offset: int) -> int:
        if team not in (0, 1):
            raise ValueError(f"Invalid team: {team}. Expected 0 or 1.")
        if not (0 <= unit_index < self.MAX_UNITS_PER_TEAM):
            raise IndexError(f"Unit index {unit_index} out of range [0, {self.MAX_UNITS_PER_TEAM - 1}].")
        return (team * self.TEAM_STRIDE) + (unit_index * self.UNIT_STRIDE) + field_offset

    def _read_int32(self, addr: int) -> int:
        return struct.unpack_from('<i', self.buffer, addr)[0]

    def _write_int32(self, addr: int, val: int):
        val = ((val + 0x80000000) & 0xffffffff) - 0x80000000
        struct.pack_into('<i', self.buffer, addr, val)

    # --- Accessors ---

    def get_unit_hp(self, team: int, unit_index: int) -> int:
        addr = self._calc_address(team, unit_index, self.OFFSET_CURRENT_HP)
        return self._read_int32(addr)

    def set_unit_hp(self, team: int, unit_index: int, hp: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_CURRENT_HP)
        self._write_int32(addr, hp)

    def is_unit_alive(self, team: int, unit_index: int) -> bool:
        addr = self._calc_address(team, unit_index, self.OFFSET_IS_ALIVE)
        return self._read_int32(addr) != 0

    def set_unit_alive(self, team: int, unit_index: int, alive: bool):
        addr = self._calc_address(team, unit_index, self.OFFSET_IS_ALIVE)
        self._write_int32(addr, 1 if alive else 0)

    def get_position_x(self, team: int, unit_index: int) -> int:
        addr = self._calc_address(team, unit_index, self.OFFSET_POSITION_X)
        return self._read_int32(addr)

    def set_position_x(self, team: int, unit_index: int, pos: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_POSITION_X)
        self._write_int32(addr, pos)

    def get_attack_timer(self, team: int, unit_index: int) -> int:
        addr = self._calc_address(team, unit_index, self.OFFSET_ATTACK_TIMER)
        return self._read_int32(addr)

    def set_attack_timer(self, team: int, unit_index: int, timer: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_ATTACK_TIMER)
        self._write_int32(addr, timer)

    def get_knockback_state(self, team: int, unit_index: int) -> int:
        addr = self._calc_address(team, unit_index, self.OFFSET_KNOCKBACK_STATE)
        return self._read_int32(addr)

    def set_knockback_state(self, team: int, unit_index: int, kb: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_KNOCKBACK_STATE)
        self._write_int32(addr, kb)

    def add_knockback(self, team: int, unit_index: int, delta: int) -> int:
        """Atomic in-place knockback accumulator matching 0x00959cf4"""
        addr = self._calc_address(team, unit_index, self.OFFSET_KNOCKBACK_STATE)
        val = self._read_int32(addr) + delta
        self._write_int32(addr, val)
        return val

    def get_speed(self, team: int, unit_index: int) -> int:
        addr = self._calc_address(team, unit_index, self.OFFSET_SPEED)
        return self._read_int32(addr)

    def set_speed(self, team: int, unit_index: int, speed: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_SPEED)
        self._write_int32(addr, speed)

    def check_can_move(self, team: int, unit_index: int) -> int:
        """Matches Battle_CheckUnitCanMove @ 0x0095a494"""
        addr_95c = self._calc_address(team, unit_index, self.OFFSET_MOVE_FLAG)
        if self._read_int32(addr_95c) == 0:
            return 0
        addr_aec = self._calc_address(team, unit_index, self.OFFSET_MOVE_SPECIAL)
        if self._read_int32(addr_aec) != 0:
            return 2
        return 1

    def set_move_flag(self, team: int, unit_index: int, flag: int):
        addr = self._calc_address(team, unit_index, self.OFFSET_MOVE_FLAG)
        self._write_int32(addr, flag)
