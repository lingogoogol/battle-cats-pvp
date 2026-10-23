"""
Comprehensive Test Suite for Phase 8 Battle Settlement Mechanic Reconstruction
Tests normal, boundary, and extreme inputs against reverse-engineered native behavior.
"""

import unittest
from mechanic_rebuild import (
    BattleSettlementController,
    SettlementDialogMode,
    BackgroundMusicTrack,
    ButtonActionCode,
    WinLossClosure
)

class TestBattleSettlementMechanic(unittest.TestCase):

    def setUp(self):
        self.controller = BattleSettlementController()

    def test_normal_victory_flow(self):
        # 1. Dispatcher creates closure
        closure = self.controller.battle_initWin(is_win=True)
        self.assertEqual(closure.vtable_ptr, 0x00adc248)
        self.assertEqual(closure.is_win, 1)

        # 2. Callback executed on confirmed button click (code = 4)
        result = self.controller.battle_initWin_callback(closure, event_code=ButtonActionCode.CONFIRMED)
        
        # Verify state transition matches AArch64 0x004e0018 - 0x004e003c
        self.assertTrue(result.handled)
        self.assertEqual(result.dialog_mode, SettlementDialogMode.VICTORY_REWARDS) # 36
        self.assertEqual(result.bgm_track, BackgroundMusicTrack.VICTORY_BGM)       # 18
        self.assertTrue(result.controls_hidden)
        self.assertTrue(result.fanfare_played)
        self.assertTrue(result.rewards_awarded)

    def test_normal_defeat_flow(self):
        closure = self.controller.battle_initWin(is_win=False)
        self.assertEqual(closure.vtable_ptr, 0x00adc248)
        self.assertEqual(closure.is_win, 0)

        result = self.controller.battle_initWin_callback(closure, event_code=ButtonActionCode.CONFIRMED)
        
        # Verify state transition matches AArch64 0x004e0060 - 0x004e0070
        self.assertTrue(result.handled)
        self.assertEqual(result.dialog_mode, SettlementDialogMode.DEFEAT_RETRY)    # 4
        self.assertEqual(result.bgm_track, BackgroundMusicTrack.DEFEAT_BGM)        # 16
        self.assertTrue(result.controls_hidden)
        self.assertFalse(result.fanfare_played)
        self.assertFalse(result.rewards_awarded)

    def test_unconfirmed_button_events_ignored(self):
        closure = self.controller.battle_initWin(is_win=True)
        
        # Test event codes != 4 (Native cmp w8, #4)
        for code in [ButtonActionCode.PRESSED, ButtonActionCode.HOVER, ButtonActionCode.RELEASED, 0, 99]:
            result = self.controller.battle_initWin_callback(closure, event_code=code)
            self.assertFalse(result.handled)
            self.assertEqual(result.dialog_mode, SettlementDialogMode.NONE)
            self.assertEqual(result.bgm_track, BackgroundMusicTrack.NONE)
            self.assertFalse(result.fanfare_played)
            self.assertFalse(result.rewards_awarded)

    def test_closure_bitmask_extreme_inputs(self):
        # Native AArch64 0x004ced24: and x8, x8, #1
        # Test odd vs even integer values mimicking raw uint8 register reads
        controller = BattleSettlementController()
        
        # is_win = 3 (binary 00000011 -> (3 & 1) == 1 -> Victory)
        closure_odd = WinLossClosure(vtable_ptr=0x00adc248, app_ptr=0x0, is_win=3)
        res_odd = controller.battle_initWin_callback(closure_odd, event_code=4)
        self.assertEqual(res_odd.dialog_mode, SettlementDialogMode.VICTORY_REWARDS)

        # is_win = 2 (binary 00000010 -> (2 & 1) == 0 -> Defeat)
        closure_even = WinLossClosure(vtable_ptr=0x00adc248, app_ptr=0x0, is_win=2)
        res_even = controller.battle_initWin_callback(closure_even, event_code=4)
        self.assertEqual(res_even.dialog_mode, SettlementDialogMode.DEFEAT_RETRY)

    def test_settlement_idempotency(self):
        # Repeated callbacks after settlement should remain stable
        closure = self.controller.battle_initWin(is_win=True)
        res1 = self.controller.battle_initWin_callback(closure, event_code=4)
        res2 = self.controller.battle_initWin_callback(closure, event_code=4)
        self.assertEqual(res1.dialog_mode, res2.dialog_mode)
        self.assertEqual(res1.bgm_track, res2.bgm_track)

if __name__ == '__main__':
    unittest.main()
