"""
Phase 16 UI, Animation, Rendering and Game Lifecycle Test Suite.
Validates Main Menu, Stage Selection, Save Persistence, State Machine, and Flow Transitions.
"""

import os
import sys
import unittest
import tempfile
import pygame

os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
os.environ["SDL_VIDEODRIVER"] = "dummy"
sys.path.insert(0, r"E:\rea")

from game_project.core.constants import SCREEN_WIDTH, SCREEN_HEIGHT
from game_project.core.save_manager import SaveManager
from game_project.ui.main_menu import MainMenuUI
from game_project.ui.stage_select import StageSelectUI
from game_project.ui.settlement_dialog import SettlementDialog
from game_project.main import run_game

class TestPhase16Lifecycle(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        pygame.init()
        pygame.font.init()

    def setUp(self):
        self.temp_save_file = tempfile.NamedTemporaryFile(suffix=".json", delete=False)
        self.temp_save_file.close()
        self.save_mgr = SaveManager(filepath=self.temp_save_file.name)

    def tearDown(self):
        if os.path.exists(self.temp_save_file.name):
            os.remove(self.temp_save_file.name)

    def test_01_save_manager_progression(self):
        """Validates save file serialization, progression unlocking, and sound toggles."""
        self.assertTrue(self.save_mgr.is_stage_unlocked(1))
        # Stage 2 is locked if Stage 1 not cleared
        self.save_mgr.data["cleared_stages"] = []
        self.assertFalse(self.save_mgr.is_stage_unlocked(2))

        # Clear Stage 1
        self.save_mgr.mark_stage_cleared(1)
        self.assertTrue(self.save_mgr.is_stage_unlocked(2), "Stage 2 did not unlock after clearing Stage 1")

        # Reload from disk
        reloaded = SaveManager(filepath=self.temp_save_file.name)
        self.assertIn(1, reloaded.data["cleared_stages"])

        # Toggle sound
        s1 = self.save_mgr.toggle_sound()
        s2 = self.save_mgr.toggle_sound()
        self.assertNotEqual(s1, s2)

    def test_02_main_menu_interactions(self):
        """Tests button clicks on Main Menu."""
        menu = MainMenuUI(self.save_mgr)
        act_start = menu.handle_click(menu.btn_start.center)
        self.assertEqual(act_start, "start")

        act_sound = menu.handle_click(menu.btn_sound.center)
        self.assertEqual(act_sound, "sound_toggle")

        act_exit = menu.handle_click(menu.btn_exit.center)
        self.assertEqual(act_exit, "exit")

    def test_03_stage_select_interactions(self):
        """Tests stage selection cards and unlocking logic."""
        self.save_mgr.data["cleared_stages"] = [1]
        stg_sel = StageSelectUI(self.save_mgr)

        # Click on Stage 1 (unlocked)
        res1 = stg_sel.handle_click(stg_sel.card_rects[0].center)
        self.assertIsNotNone(res1)
        self.assertEqual(res1["action"], "play")
        self.assertEqual(res1["stage_config"]["id"], 1)

        # Click on Back button
        res_back = stg_sel.handle_click(stg_sel.btn_back.center)
        self.assertEqual(res_back["action"], "back")

    def test_04_settlement_dialog_dual_buttons(self):
        """Tests restart and stage select buttons in settlement dialog."""
        dialog = SettlementDialog()
        act_restart = dialog.handle_click(dialog.btn_restart.center)
        self.assertEqual(act_restart, "restart")

        act_stage_select = dialog.handle_click(dialog.btn_stage_select.center)
        self.assertEqual(act_stage_select, "stage_select")

    def test_05_capture_menu_and_stage_select_screenshots(self):
        """Renders Menu and Stage Select and captures evidence screenshots."""
        surface = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
        
        # 1. Main Menu
        menu = MainMenuUI(self.save_mgr)
        menu.render(surface, frame=45)
        menu_path = r"E:\rea\game_project\screenshots\04_main_menu.png"
        pygame.image.save(surface, menu_path)
        self.assertTrue(os.path.exists(menu_path))

        # 2. Stage Select
        stage_sel = StageSelectUI(self.save_mgr)
        stage_sel.render(surface)
        stage_path = r"E:\rea\game_project\screenshots\05_stage_select.png"
        pygame.image.save(surface, stage_path)
        self.assertTrue(os.path.exists(stage_path))

if __name__ == "__main__":
    unittest.main()
