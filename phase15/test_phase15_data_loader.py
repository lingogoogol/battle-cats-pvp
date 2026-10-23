"""
Phase 15 Data Loader & Stage Pipeline Test Suite.
Validates Schema Validation, Fallback Resilience, and Multi-Stage Simulation.
"""

import os
import sys
import unittest
import tempfile
import json

os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
sys.path.insert(0, r"E:\rea")

from game_project.core.data_loader import GameDataLoader
from game_project.simulation.battle_sim import BattleSimulation

class TestPhase15DataLoader(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        GameDataLoader.export_default_datasets(r"E:\rea\game_project\data")

    def test_01_load_valid_datasets(self):
        """Loads units and stages from disk and checks data integrity."""
        cats = GameDataLoader.load_unit_registry(r"E:\rea\game_project\data\cat_units.json", {})
        self.assertIn("cat", cats)
        self.assertIn("tank_cat", cats)
        self.assertIn("cow_cat", cats)
        self.assertEqual(cats["cat"]["cost"], 50)

        for s_name in ["stage_01_korea.json", "stage_02_mongolia.json", "stage_03_philippines.json"]:
            path = os.path.join(r"E:\rea\game_project\data\stages", s_name)
            stg = GameDataLoader.load_stage_config(path)
            self.assertGreater(stg["length"], 1000)
            self.assertGreater(stg["cat_castle_hp"], 0)
            self.assertGreater(stg["enemy_castle_hp"], 0)

    def test_02_schema_validation_rejection(self):
        """Rejects corrupted or incomplete unit specifications."""
        bad_spec = {
            "name": "Corrupt Cat",
            "hp": -50, # Invalid negative HP
            "attack_power": 10
            # Missing speed, attack_range, etc.
        }
        valid = GameDataLoader._validate_unit_spec("bad_cat", bad_spec)
        self.assertFalse(valid, "Corrupted unit spec was not rejected by validator")

    def test_03_fallback_resilience(self):
        """Falls back gracefully when reading nonexistent or broken JSON."""
        res = GameDataLoader.load_unit_registry(r"E:\rea\game_project\data\nonexistent_cat.json", {"fallback": 123})
        self.assertEqual(res, {"fallback": 123})

        stg = GameDataLoader.load_stage_config(r"E:\rea\game_project\data\nonexistent_stage.json")
        self.assertIsNotNone(stg)
        self.assertIn("name", stg)

    def test_04_multi_stage_simulation_runs(self):
        """Runs battle simulations using all 3 imported test stages."""
        for s_name in ["stage_01_korea.json", "stage_02_mongolia.json", "stage_03_philippines.json"]:
            path = os.path.join(r"E:\rea\game_project\data\stages", s_name)
            stg = GameDataLoader.load_stage_config(path)
            sim = BattleSimulation(stage_config=stg)
            
            # Step 100 frames with auto cat spawn
            for _ in range(100):
                if sim.wallet.money >= 50:
                    sim.spawn_cat(0)
                sim.step()
                
            self.assertEqual(sim.current_frame, 100)
            self.assertFalse(sim.game_over)
            self.assertGreater(sim.get_castle(0).hp, 0)

if __name__ == "__main__":
    unittest.main()
