import unittest
import os
import sys

sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

from combat_engine import IntegratedBattleEngine

class TestCombatIntegration(unittest.TestCase):
    def setUp(self):
        self.engine = IntegratedBattleEngine(battlefield_length=1000)

    def test_castle_initialization(self):
        # Verify Castles at Slot 0
        mem = self.engine.mem
        # Team 0 Castle
        self.assertTrue(mem.is_unit_alive(0, 0))
        self.assertEqual(mem.get_unit_hp(0, 0), 100000)
        self.assertEqual(mem.get_position_x(0, 0), 0)
        
        # Team 1 Castle
        self.assertTrue(mem.is_unit_alive(1, 0))
        self.assertEqual(mem.get_unit_hp(1, 0), 100000)
        self.assertEqual(mem.get_position_x(1, 0), 1000)

    def test_multi_step_encounter_combat_and_victory(self):
        # Deploy Basic Cat (Team 0, Slot 1)
        # HP=1500, Speed=10, Range=140, Interval=20, Damage=400
        self.engine.initialize_unit(
            team=0, slot=1, unit_id=1, hp=1500, speed=10,
            attack_range=140, attack_interval=20, base_damage=400, pos_x=50
        )

        # Deploy Doge (Team 1, Slot 1)
        # HP=600, Speed=8, Range=110, Interval=15, Damage=150
        self.engine.initialize_unit(
            team=1, slot=1, unit_id=2, hp=600, speed=8,
            attack_range=110, attack_interval=15, base_damage=150, pos_x=950
        )

        # Step simulation until encounter
        doge_killed = False
        knockback_seen = False
        cat_attacked_castle = False

        print("\n--- Running Multi-Step Combat Integration Simulation ---")
        for frame in range(1, 150):
            log = self.engine.step_frame()
            if log['events']:
                for ev in log['events']:
                    print(f"[Frame {frame:03d}] {ev}")
                    if "KB=True" in ev:
                        knockback_seen = True
                    if "Killed=True" in ev and "Team 1 Slot 1" in ev:
                        doge_killed = True
                    if "Opponent Team 1 Slot 0" in ev:
                        cat_attacked_castle = True

            if doge_killed and cat_attacked_castle:
                break

        # Verification of complete battle cycle:
        # 1. Knockback was triggered upon heavy hit
        self.assertTrue(knockback_seen, "Knockback should be triggered when damage >= threshold")
        
        # 2. Doge was successfully killed and cleaned up
        self.assertTrue(doge_killed, "Doge should be killed after accumulating lethal damage")
        self.assertFalse(self.engine.mem.is_unit_alive(1, 1), "Doge alive flag must be 0")
        self.assertEqual(self.engine.mem.get_unit_hp(1, 1), 0, "Doge HP must be 0")
        
        # 3. Cat resumed advancing and reached enemy castle
        self.assertTrue(cat_attacked_castle, "Cat should reach enemy castle and inflict damage")
        self.assertLess(self.engine.mem.get_unit_hp(1, 0), 100000, "Enemy castle HP should be depleted")
        print(f"Simulation Test Passed! Final Enemy Castle HP: {self.engine.mem.get_unit_hp(1, 0)} / 100000")

if __name__ == '__main__':
    unittest.main(verbosity=2)
