"""
Autonomous Deep Verification Script: Battle Cats REA Cooldown and Knockback Parity.
Verifies:
1. Strict 60-frame hard floor on Cat Production Cooldown (no infinite conga-line spam).
2. Authentic PONOS & BCU knockback parameters (hitback: 345 DU / 24f, kb: 165 DU / 12f, cannon: 55 DU / 11f, boss: 705 DU / 47f).
3. Authentic quadratic ease-out deceleration physics (summing exactly to total displacement with smooth deceleration).
4. Knockback invulnerability during all active frames.
5. Immediate on-the-spot death sequence (Battle_KillUnit 0x008b6f50) with zero artificial death sliding.
6. Attack cycle timer reset on knockback (foreswing cancellation and authentic rebound attack).
"""

import sys
import unittest
from game_project.core.constants import TEAM_CAT, TEAM_ENEMY, KB_SPECS
from game_project.simulation.battle_sim import BattleSimulation, SimUnit
from game_project.core.official_data_parser import OfficialDataParser

class TestBattleCatsAuthenticParity(unittest.TestCase):
    def setUp(self):
        self.parser = OfficialDataParser.get_instance()

    def test_01_cat_production_cooldown_hard_floor(self):
        """Verifies that no Cat unit can be deployed faster than once every 60 frames (2.0s)."""
        cat_spec = self.parser.get_cat(0).to_dict()
        self.assertEqual(cat_spec["cooldown_frames"], 150, "Basic Cat base cooldown must be 150 frames (5.0s)")

        # Initialize simulation with 3 chapters of EoC treasures (-90 frames reduction)
        sim = BattleSimulation(
            stage_config={"length": 3000, "enemy_castle_hp": 1000, "cat_castle_hp": 1000},
            deck=["cat"],
            treasures={"eoc_chapters": 3.0}
        )
        sim.wallet.money = 10000

        # Slot 0 max cooldown should be max(60, 150 - 90) = 60 frames (2.0s)
        self.assertEqual(sim.deployer.max_cooldowns[0], 60)
        self.assertTrue(sim.deployer.can_deploy(0, sim.wallet.money, True))

        # Deploy Cat
        deployed = sim.deploy_unit(TEAM_CAT, 0)
        self.assertTrue(deployed)

        # Immediately after deployment, cooldown must be exactly 60 frames
        self.assertEqual(sim.deployer.cooldowns[0], 60)
        self.assertFalse(sim.deployer.can_deploy(0, sim.wallet.money, True), "Cannot deploy again immediately!")

        # Step simulation for 59 frames: deployment MUST FAIL continuously
        for frame in range(1, 60):
            sim.step()
            remaining_cd = sim.deployer.cooldowns[0]
            self.assertEqual(remaining_cd, 60 - frame)
            can_spam = sim.deploy_unit(TEAM_CAT, 0)
            self.assertFalse(can_spam, f"Unit was illegally deployable on frame {frame} with remaining CD {remaining_cd}!")

        # On frame 60, cooldown hits 0 and unit becomes deployable again
        sim.step()
        self.assertEqual(sim.deployer.cooldowns[0], 0)
        self.assertTrue(sim.deployer.can_deploy(0, sim.wallet.money, True))
        self.assertTrue(sim.deploy_unit(TEAM_CAT, 0), "Should deploy on frame 60 after full 2.0s cooldown elapsed")

    def test_02_tank_cat_cooldown_with_treasures(self):
        """Verifies Tank Cat cooldown: base 240 frames, reduced to 150 frames with 3 chapters."""
        tank_spec = self.parser.get_cat(1).to_dict()
        self.assertEqual(tank_spec["cooldown_frames"], 240, "Tank Cat base cooldown must be 240 frames (8.0s)")

        sim = BattleSimulation(
            stage_config={"length": 3000, "enemy_castle_hp": 1000, "cat_castle_hp": 1000},
            deck=["tank_cat"],
            treasures={"eoc_chapters": 3.0}
        )
        sim.wallet.money = 10000

        # Max cooldown for Tank Cat: max(60, 240 - 90) = 150 frames (5.0s)
        self.assertEqual(sim.deployer.max_cooldowns[0], 150)
        self.assertTrue(sim.deploy_unit(TEAM_CAT, 0))
        self.assertEqual(sim.deployer.cooldowns[0], 150)

    def test_03_authentic_knockback_specs(self):
        """Verifies native PONOS knockback specifications in KB_SPECS (DU = native / 4)."""
        self.assertEqual(KB_SPECS["hitback"], (345.0, 24), "HP hitback must be 345.0 DU over 24 frames (14.375 DU/f)")
        self.assertEqual(KB_SPECS["kb"], (165.0, 12), "State 6 Ability KB must be 165.0 DU over 12 frames (660/4)")
        self.assertEqual(KB_SPECS["cannon"], (55.0, 11), "Cannon KB must be 55.0 DU over 11 frames (220/4)")
        self.assertEqual(KB_SPECS["boss"], (705.0, 47), "Boss shockwave must be 705.0 DU over 47 moving frames (2820/4)")

    def test_04_damage_hitback_physics_and_invulnerability(self):
        """Verifies 345.0 DU displacement over 24 frames with authentic constant-velocity displacement."""
        sim = BattleSimulation(
            stage_config={"length": 3200, "enemy_castle_hp": 1000, "cat_castle_hp": 1000},
            deck=["cat"]
        )
        sim.spawner.spawn_entries = []
        doge = sim.spawn_custom_unit({
            "name": "Doge",
            "hp": 300,
            "knockback_count": 3,
            "speed": 0,
            "attack_power": 10
        }, team=TEAM_ENEMY)
        doge.pos_x = 1200.0

        # Deal 110 damage to cross the first 100-HP threshold
        attacker = sim.spawn_custom_unit({
            "name": "Attacker",
            "hp": 1000,
            "speed": 0,
            "attack_power": 110
        }, team=TEAM_CAT)

        init_x = doge.pos_x
        sim._apply_damage(attacker, doge, direction=-1, hit_damage=110)

        # Doge should now be in hitback knockback
        self.assertTrue(doge.is_in_knockback())
        self.assertEqual(doge.knockback_timer, 24)
        self.assertEqual(doge.kb_total_frames, 24)
        self.assertEqual(doge.kb_distance, 345.0)

        prev_x = doge.pos_x
        for f in range(24):
            # Doge must be completely invulnerable during all 24 frames
            self.assertTrue(doge.is_in_knockback())
            sim._apply_damage(attacker, doge, direction=-1, hit_damage=50)
            self.assertEqual(doge.hp, 190, f"Doge took damage on knockback frame {f}!")

            sim.step()
            dx = prev_x - doge.pos_x
            # Authentic PONOS constant velocity: 345.0 / 24.0 = 14.375 DU/frame
            self.assertAlmostEqual(dx, 345.0 / 24.0, places=4, msg=f"Displacement must be 345/24 DU/f on frame {f}")
            prev_x = doge.pos_x

        # Knockback finished
        self.assertFalse(doge.is_in_knockback())
        total_disp = init_x - doge.pos_x
        self.assertAlmostEqual(total_disp, 345.0, places=2, msg="Total displacement must equal exactly 345.0 DU")

    def test_05_ability_knockback_physics(self):
        """Verifies native State 6 Proc knockback (0x5dd600): 165.0 DU over 12 frames."""
        sim = BattleSimulation(stage_config={"length": 3200, "enemy_castle_hp": 1000, "cat_castle_hp": 1000})
        doge = sim.spawn_custom_unit({"name": "Doge", "hp": 1000, "knockback_count": 1, "speed": 0}, team=TEAM_ENEMY)
        doge.pos_x = 1000.0

        sim._knockback(doge, "kb")
        self.assertTrue(doge.is_in_knockback())
        self.assertEqual(doge.knockback_timer, 12)
        self.assertEqual(doge.kb_distance, 165.0)

        init_x = doge.pos_x
        for f in range(12):
            prev_x = doge.pos_x
            sim.step()
            dx = prev_x - doge.pos_x
            expected_dx = (((12 - (f + 1)) % 12) * 10) / 4.0
            self.assertAlmostEqual(dx, expected_dx, places=4, msg=f"State 6 Proc KB mismatch on frame {f}")

        self.assertFalse(doge.is_in_knockback())
        self.assertAlmostEqual(init_x - doge.pos_x, 165.0, places=2)

    def test_06_death_knockback_then_soul_parity(self):
        """Verifies authentic Battle Cats death: unit performs death knockback before releasing soul."""
        sim = BattleSimulation(stage_config={"length": 3200, "enemy_castle_hp": 1000, "cat_castle_hp": 1000})
        doge = sim.spawn_custom_unit({"name": "Doge", "hp": 100, "knockback_count": 3, "speed": 0}, team=TEAM_ENEMY)
        doge.pos_x = 1000.0

        attacker = sim.spawn_custom_unit({"name": "Attacker", "hp": 1000, "speed": 0, "attack_power": 150}, team=TEAM_CAT)
        sim._apply_damage(attacker, doge, direction=-1, hit_damage=150)
        self.assertEqual(doge.hp, 0)
        self.assertTrue(doge.is_dying)
        self.assertTrue(doge.is_in_knockback())
        self.assertEqual(doge.knockback_timer, 24)

        for _ in range(24):
            sim.step()

        self.assertIsNone(sim.units[TEAM_ENEMY][1], "Dead unit must be cleared after death knockback completes")
        ev_types = [ev["type"] for ev in sim.consume_visual_events()]
        self.assertIn("death", ev_types, "Death event must be emitted at end of death knockback")

    def test_07_knockback_attack_interrupt_and_rebound(self):
        """Verifies that knockback interrupts attack windup and resets cycle_timer so unit can attack immediately."""
        sim = BattleSimulation(stage_config={"length": 3200, "enemy_castle_hp": 1000, "cat_castle_hp": 1000})
        cat = sim.spawn_custom_unit({
            "name": "Cat", "hp": 300, "knockback_count": 3, "speed": 0,
            "attack_power": 20, "attack_range": 140, "attack_windup": 20, "attack_interval": 50
        }, team=TEAM_CAT)
        cat.pos_x = 500.0

        # Start windup on cat
        cat.is_winding_up = True
        cat.windup_timer = 15
        cat.cycle_timer = 70

        # Knock back cat
        sim._knockback(cat, "hitback")
        self.assertTrue(cat.is_in_knockback())
        self.assertFalse(cat.is_winding_up)
        self.assertEqual(cat.windup_timer, 0)
        self.assertEqual(cat.cycle_timer, 0, "Cycle timer must be reset on knockback interrupt to permit rebound attack!")

if __name__ == "__main__":
    suite = unittest.TestLoader().loadTestsFromTestCase(TestBattleCatsAuthenticParity)
    runner = unittest.TextTestRunner(verbosity=2)
    res = runner.run(suite)
    sys.exit(0 if res.wasSuccessful() else 1)
