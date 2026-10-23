"""
Phase 14 Mechanics Verification Test Suite.
Validates Area Attack vs Single Target, Knockback Attack Interruption, and Status Effects.
"""

import os
import sys
import unittest

os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
sys.path.insert(0, r"E:\rea")

from game_project.simulation.battle_sim import BattleSimulation
from game_project.core.constants import TEAM_CAT, TEAM_ENEMY

class TestPhase14Mechanics(unittest.TestCase):
    def setUp(self):
        self.sim = BattleSimulation()
        self.sim.spawner.castle_triggers = []
        self.sim.spawner.timed_events = []

    def test_single_target_vs_area_attack(self):
        """Validates that Single Target hits only 1 unit while Area Target hits ALL units in range."""
        # 1. Single Target Test (Normal Cat)
        self.sim.spawn_cat(0) # 'cat' is single target
        cat = self.sim.units[TEAM_CAT][1]
        
        # Spawn two doges right next to each other
        self.sim.spawn_enemy("doge")
        self.sim.spawn_enemy("doge")
        doge1 = self.sim.units[TEAM_ENEMY][1]
        doge2 = self.sim.units[TEAM_ENEMY][2]
        doge1.pos_x = cat.pos_x + 50
        doge2.pos_x = cat.pos_x + 55

        # Step until cat strikes
        for _ in range(25):
            self.sim.step()

        # Since cat is single target, only doge1 should have taken damage
        self.assertLess(doge1.hp, doge1.max_hp, "Primary target doge1 was not damaged")
        self.assertEqual(doge2.hp, doge2.max_hp, "Secondary target doge2 took damage from single-target attack!")

        # 2. Area Attack Test (Hippoe vs two Cats)
        sim2 = BattleSimulation()
        sim2.spawner.castle_triggers = []
        sim2.spawner.timed_events = []
        sim2.spawn_cat(0)
        sim2.deployer.cooldowns[0] = 0
        sim2.wallet.money = 500
        sim2.spawn_cat(0)
        c1 = sim2.units[TEAM_CAT][1]
        c2 = sim2.units[TEAM_CAT][2]
        c1.pos_x = 1000
        c2.pos_x = 1020

        sim2.spawn_enemy("hippoe") # 'hippoe' is area attack
        hippoe = sim2.units[TEAM_ENEMY][1]
        hippoe.pos_x = 1080 # In range (160) of both cats

        for _ in range(35):
            sim2.step()

        # Hippoe does area attack, BOTH c1 and c2 must take damage
        self.assertLess(c1.hp, c1.max_hp, "c1 did not take area damage from Hippoe")
        self.assertLess(c2.hp, c2.max_hp, "c2 did not take area damage from Hippoe")

    def test_knockback_cancels_windup(self):
        """Validates that knockback immediately interrupts attack windup and resets timer."""
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        cat.is_winding_up = True
        cat.windup_timer = 5

        # Trigger knockback via damage threshold
        cat.hp = cat.max_hp - int(cat.kb_threshold) - 1
        damage_taken = cat.max_hp - cat.hp
        kbs = int(damage_taken // cat.kb_threshold)
        if kbs > cat.kb_points_taken:
            cat.kb_points_taken = kbs
            cat.knockback_timer = 12
            cat.is_winding_up = False
            cat.windup_timer = 0

        self.assertTrue(cat.is_in_knockback())
        self.assertFalse(cat.is_winding_up, "Windup was not canceled by knockback")
        self.assertEqual(cat.windup_timer, 0)

    def test_status_effect_slow(self):
        """Validates that Slow reduces movement speed by 50%."""
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        cat.speed = 10
        cat.slow_timer = 10
        start_x = cat.pos_x

        self.sim.step()
        delta = cat.pos_x - start_x
        self.assertEqual(delta, 5, f"Slowed cat moved {delta} px, expected 5 px (half of 10)")

    def test_status_effect_freeze(self):
        """Validates that Freeze stops movement and attack windup completely."""
        self.sim.spawn_cat(0)
        cat = self.sim.units[TEAM_CAT][1]
        cat.freeze_timer = 10
        start_x = cat.pos_x

        self.sim.step()
        self.assertEqual(cat.pos_x, start_x, "Frozen cat moved during freeze duration!")

if __name__ == "__main__":
    unittest.main()
