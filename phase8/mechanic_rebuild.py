"""
Phase 8 Clean-Room Independent Reconstruction of Battle Settlement Mechanic
Reference: Ponos Battle Cats libnative-lib.so (0x004cecc0 & 0x004dff1c)
"""

from dataclasses import dataclass
from enum import IntEnum
from typing import Optional

class SettlementDialogMode(IntEnum):
    NONE = 0
    DEFEAT_RETRY = 4       # Native constant: 0x04 (mov w21, #4)
    VICTORY_REWARDS = 36   # Native constant: 0x24 (mov w21, #0x24)

class BackgroundMusicTrack(IntEnum):
    NONE = 0
    DEFEAT_BGM = 16        # Native constant: 0x10 (mov w9, #0x10)
    VICTORY_BGM = 18       # Native constant: 0x12 (mov w8, #0x12)

class ButtonActionCode(IntEnum):
    PRESSED = 1
    HOVER = 2
    RELEASED = 3
    CONFIRMED = 4          # Native check: cmp w8, #4

@dataclass
class WinLossClosure:
    """
    Simulates the 24-byte heap closure allocated in 0x004ced10.
    Memory offsets:
      +0x00: vtable pointer (0x00adc248)
      +0x08: application singleton pointer
      +0x10: is_win (uint8)
    """
    vtable_ptr: int
    app_ptr: int
    is_win: int  # Stored as unsigned 8-bit integer (0 or 1)

@dataclass
class SettlementResult:
    handled: bool
    dialog_mode: SettlementDialogMode
    bgm_track: BackgroundMusicTrack
    controls_hidden: bool
    fanfare_played: bool
    rewards_awarded: bool

class BattleSettlementController:
    """
    Independent functional equivalent implementation of the battle result pipeline.
    """
    def __init__(self):
        self.active_dialog = SettlementDialogMode.NONE
        self.current_bgm = BackgroundMusicTrack.NONE
        self.controls_visible = True
        self.fanfare_played = False
        self.rewards_awarded = False
        self.settlement_finished = False

    def battle_initWin(self, is_win: bool) -> WinLossClosure:
        """
        Equivalent to Native dispatcher at 0x004cecc0 / 0x004ced10.
        Packs vtable pointer (0x00adc248) and is_win flag into closure struct.
        """
        # In Native AArch64 (0x004ced24): and x8, x8, #1
        packed_win = 1 if is_win else 0
        return WinLossClosure(
            vtable_ptr=0x00adc248,
            app_ptr=0x00b0b850,
            is_win=packed_win
        )

    def battle_initWin_callback(self, closure: WinLossClosure, event_code: int) -> SettlementResult:
        """
        Equivalent to Native callback at 0x004dff1c.
        Checks confirmation button code and dispatches Victory vs Defeat actions.
        """
        # Native check at 0x004dff4c: cmp w8, #4
        if event_code != ButtonActionCode.CONFIRMED:
            # Unconfirmed event: ignored by state machine
            return SettlementResult(
                handled=False,
                dialog_mode=self.active_dialog,
                bgm_track=self.current_bgm,
                controls_hidden=not self.controls_visible,
                fanfare_played=self.fanfare_played,
                rewards_awarded=self.rewards_awarded
            )

        # Native branch at 0x004e0010: ldrb w8, [x19, #0x10]; cbz w8, #0x4e0060
        is_win = (closure.is_win & 1) != 0

        if is_win:
            # === VICTORY PATH ===
            # 0x004e0020: HideBattleControls
            self.controls_visible = False
            # 0x004e002c: PlayVictoryFanfare
            self.fanfare_played = True
            # 0x004e0030: AwardStageRewards
            self.rewards_awarded = True
            # 0x004e0038: mov w21, #0x24 (36)
            self.active_dialog = SettlementDialogMode.VICTORY_REWARDS
            # 0x004e0070: csel x22, x9, x8, eq -> 0x12 (18)
            self.current_bgm = BackgroundMusicTrack.VICTORY_BGM
        else:
            # === DEFEAT PATH ===
            self.controls_visible = False
            self.fanfare_played = False
            self.rewards_awarded = False
            # 0x004e0060: mov w21, #4
            self.active_dialog = SettlementDialogMode.DEFEAT_RETRY
            # 0x004e0070: csel x22, x9, x8, eq -> 0x10 (16)
            self.current_bgm = BackgroundMusicTrack.DEFEAT_BGM

        self.settlement_finished = True

        return SettlementResult(
            handled=True,
            dialog_mode=self.active_dialog,
            bgm_track=self.current_bgm,
            controls_hidden=not self.controls_visible,
            fanfare_played=self.fanfare_played,
            rewards_awarded=self.rewards_awarded
        )
