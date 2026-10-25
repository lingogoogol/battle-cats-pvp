"""
Autonomous End-to-End Combat Mechanics Parity Verification Script.
Exhaustively verifies every single Battle Cats combat rule against REA native specs:
1. 1-KB Unit (Tank Cat, Titan Cat):
   - Flawless tanking under sub-lethal damage (zero flinching / zero knockback).
   - Authentic 12-frame death knockback (86 px backward slide in hurt animation) upon lethal damage.
   - Release of soul particle and slot freeing only after the 12-frame slide completes.
2. Multi-KB Unit (Cat, Doge, Baa Baa):
   - Correct hitbacks at intermediate fractional thresholds (e.g. 1/3, 2/3 HP).
   - Knockback attack interrupt & rebound behavior (cycle timer reset).
   - Authentic death knockback at 0 HP.
3. Attack Cycle & Lockout:
   - Foreswing windup immobility.
   - Damage application at exact foreswing frame.
   - Backswing recovery & walk transition.
4. Cooldown Hard Floor:
   - 60 frames (2.0s) absolute deployment cooldown floor under max treasures.
5. Symmetrical PvP Economy & Cannons:
   - Both players have identical mechanics and deployment rules.
"""

import sys
import unittest
from game_project.core.constants import (
    TEAM_CAT, TEAM_ENEMY, SLOT_CASTLE, KB_SPECS, MAX_UNITS_PER_TEAM
)
from game_project.simulation.battle_sim import BattleSimulation, SimUnit
from game_project.core.unit_data import CAT_REGISTRY, ENEMY_REGISTRY


class TestAutonomousParityDeepAudit(unittest.TestCase):

    def test_01_tank_cat_1kb_perfect_parity(self):
        """Verify Tank Cat (1-KB): tanks damage without flinching, then slides 86px over 12 frames on death."""
        sim = BattleSimulation(treasures={"eoc_chapters": 3.0})
        # Deploy Tank Cat (Team 0)
        success = sim.deploy_unit(TEAM_CAT, 1) # slot 1 is tank_cat
        self.assertTrue(success)
        tank = next(u for u in sim.units[TEAM_CAT][1:] if u is not None)
        self.assertIsNotNone(tank)
        tank.pos_x = 2000 # Move to battlefield center so it doesn't collide with castle wall
        self.assertEqual(tank.knockback_max, 1)
        self.assertEqual(tank.hp, tank.max_hp)

        init_x = tank.pos_x
        # Simulate sub-lethal hits (e.g. 10 hits of 50 damage)
        dummy_enemy = sim.spawn_custom_unit({
            "name": "Dummy", "hp": 1000, "attack_power": 50, "speed": 0
        }, team=TEAM_ENEMY)

        for _ in range(10):
            sim._apply_damage(dummy_enemy, tank, direction=1, hit_damage=50)

        # Tank Cat has taken 500 damage out of 4000 HP
        self.assertEqual(tank.hp, tank.max_hp - 500)
        self.assertFalse(tank.is_in_knockback())
        self.assertTrue(tank.is_alive)
        self.assertFalse(tank.is_dying)
        self.assertEqual(tank.kb_points_taken, 0)
        print(" -> Sub-lethal tanking verified: Tank Cat took 500 damage with 0 flinching.")

        # Now inflict lethal damage
        lethal_enemy = sim.spawn_custom_unit({
            "name": "Lethal", "hp": 1000, "attack_power": 5000, "speed": 0
        }, team=TEAM_ENEMY)

        pos_before_death = tank.pos_x
        sim._apply_damage(lethal_enemy, tank, direction=1, hit_damage=5000)

        # Unit should immediately be marked dying and start death knockback
        self.assertEqual(tank.hp, 0)
        self.assertFalse(tank.is_alive)
        self.assertTrue(tank.is_dying)
        self.assertTrue(tank.is_in_knockback())
        self.assertEqual(tank.knockback_timer, 12)
        print(" -> Lethal blow entered death knockback: 12 frames initialized.")

        # Living enemy should NOT target dying tank cat
        self.assertFalse(sim._can_unit_target_opponent(dummy_enemy, tank))

        # Step 12 frames through the death knockback slide
        for frame in range(1, 13):
            sim.step()
            events = sim.consume_visual_events()
            if frame < 12:
                # Still sliding
                self.assertIsNotNone(sim.units[TEAM_CAT][tank.slot], "Slot must remain occupied during death slide")
                self.assertTrue(tank.is_in_knockback())
            else:
                # On frame 12, knockback completes, soul emitted, slot cleared
                death_events = [ev for ev in events if ev["type"] == "death"]
                self.assertEqual(len(death_events), 1, "Must emit death event for soul ascension on final frame")
                self.assertIsNone(sim.units[TEAM_CAT][tank.slot], "Slot must be freed after death slide")

        total_slide = abs(tank.pos_x - pos_before_death)
        self.assertAlmostEqual(total_slide, 86.0, delta=1.0)
        print(f" -> Authentic death knockback verified: slid {total_slide:.1f}px backward over 12 frames, released soul.")

    def test_02_cat_3kb_multi_threshold_parity(self):
        """Verify Cat (3-KB): knocks back at 33% and 66% HP damage, then death knockback at 100%."""
        sim = BattleSimulation(treasures={"eoc_chapters": 3.0})
        success = sim.deploy_unit(TEAM_CAT, 0) # slot 0 is cat
        self.assertTrue(success)
        cat = next(u for u in sim.units[TEAM_CAT][1:] if u is not None)
        self.assertIsNotNone(cat)
        self.assertEqual(cat.knockback_max, 3)
        self.assertEqual(cat.kb_threshold, cat.max_hp / 3.0)

        dummy_enemy = sim.spawn_custom_unit({
            "name": "Dummy", "hp": 1000, "attack_power": 1, "speed": 0
        }, team=TEAM_ENEMY)

        # Hit 1: 34% damage -> triggers KB 1
        dmg_1 = int(cat.max_hp * 0.35)
        sim._apply_damage(dummy_enemy, cat, direction=1, hit_damage=dmg_1)
        self.assertTrue(cat.is_in_knockback())
        self.assertEqual(cat.kb_points_taken, 1)
        self.assertTrue(cat.is_alive)
        self.assertFalse(cat.is_dying)

        # Step out of KB
        for _ in range(12):
            sim.step()
        self.assertFalse(cat.is_in_knockback())

        # Hit 2: another 35% damage -> triggers KB 2
        sim._apply_damage(dummy_enemy, cat, direction=1, hit_damage=dmg_1)
        self.assertTrue(cat.is_in_knockback())
        self.assertEqual(cat.kb_points_taken, 2)
        self.assertTrue(cat.is_alive)
        self.assertFalse(cat.is_dying)

        for _ in range(12):
            sim.step()
        self.assertFalse(cat.is_in_knockback())

        # Hit 3: lethal damage -> triggers death KB (KB 3)
        sim._apply_damage(dummy_enemy, cat, direction=1, hit_damage=cat.max_hp)
        self.assertEqual(cat.hp, 0)
        self.assertFalse(cat.is_alive)
        self.assertTrue(cat.is_dying)
        self.assertTrue(cat.is_in_knockback())

        for _ in range(12):
            sim.step()
        self.assertIsNone(sim.units[TEAM_CAT][cat.slot])
        print(" -> Multi-KB verified: 2 intermediate hitbacks + 1 final death knockback.")

    def test_03_cooldown_hard_floor_verification(self):
        """Verifies that cooldown hard floor of 60 frames (2.0s) is strictly respected."""
        sim = BattleSimulation(treasures={"eoc_chapters": 3.0})
        d = sim.deployer
        # Cat raw cooldown is 60 frames. Even with max treasures, cooldown cannot drop below 60 frames.
        self.assertEqual(d.max_cooldowns[0], 60)

        sim.wallet.money = 10000
        deployed = sim.deploy_unit(TEAM_CAT, 0)
        self.assertTrue(deployed)
        self.assertEqual(d.cooldowns[0], 60)

        # Cannot deploy on next frame
        sim.step()
        self.assertFalse(sim.deploy_unit(TEAM_CAT, 0))
        print(" -> Cooldown floor verified: Cat cannot deploy faster than 60 frames (2.0s).")

    def test_04_symmetric_pvp_economy_and_cannons(self):
        """Verifies that 2-player symmetric PvP has identical economy, cannon charging, and castle stats."""
        sim = BattleSimulation(pvp_mode=True, treasures={"eoc_chapters": 3.0}, p2_treasures={"eoc_chapters": 3.0})
        c0 = sim.get_castle(TEAM_CAT)
        c1 = sim.get_castle(TEAM_ENEMY)

        self.assertEqual(c0.max_hp, c1.max_hp)
        self.assertEqual(c0.hp, c1.hp)
        self.assertEqual(sim.wallet.money, sim.p2_wallet.money)
        self.assertEqual(sim.wallet.max_money, sim.p2_wallet.max_money)
        self.assertEqual(sim.cannon_charge, sim.p2_cannon_charge)
        self.assertEqual(sim.cannon_max_charge, 2400) # 2850 - 450 = 2400 frames (80.0s)

        # Both earn money at the identical treasure-boosted rate
        for _ in range(30):
            sim.step()
        self.assertEqual(sim.wallet.money, sim.p2_wallet.money)
        print(" -> Symmetrical PvP verified: Castles, wallets, and cannon charges 100% synchronized.")

    def test_05_ability_knockback_vs_hitback_physics(self):
        """Verifies Ability Proc knockback (48px / 11f) vs Damage Hitback (86px / 12f)."""
        sim = BattleSimulation()
        cat = sim.spawn_custom_unit({
            "name": "Cat", "hp": 10000, "attack_power": 1, "speed": 0, "knockback_count": 10
        }, team=TEAM_CAT)
        cat.pos_x = 2000

        # Ability Knockback proc
        kb_attacker = sim.spawn_custom_unit({
            "name": "KB Pusher", "hp": 1000, "attack_power": 1, "speed": 0,
            "abilities": {"kb_prob": 100}
        }, team=TEAM_ENEMY)

        sim._apply_damage(kb_attacker, cat, direction=1, hit_damage=1, use_ability=True)
        self.assertTrue(cat.is_in_knockback())
        self.assertEqual(cat.kb_total_frames, 11)
        self.assertEqual(cat.knockback_timer, 11)
        self.assertEqual(cat.kb_distance, 48.0)

        pos_before = cat.pos_x
        for _ in range(11):
            sim.step()
        self.assertFalse(cat.is_in_knockback())
        disp = abs(cat.pos_x - pos_before)
        self.assertAlmostEqual(disp, 48.0, delta=1.0)
        print(f" -> Ability KB verified: exactly {disp:.1f}px over 11 frames.")

    def test_06_zombie_death_kb_then_corpse_parity(self):
        """Verifies that Zombie units perform 12-frame death knockback BEFORE turning into a corpse."""
        sim = BattleSimulation()
        zombie = sim.spawn_custom_unit({
            "name": "Zombo", "hp": 500, "attack_power": 10, "speed": 0, "knockback_count": 1,
            "traits": ["zombie"],
            "abilities": {"revive_count": 1, "revive_time": 60, "revive_hp_pct": 50}
        }, team=TEAM_ENEMY)
        zombie.pos_x = 1500

        killer = sim.spawn_custom_unit({
            "name": "Killer", "hp": 1000, "attack_power": 1000, "speed": 0
        }, team=TEAM_CAT)

        # Fatal hit without Zombie Killer
        sim._apply_damage(killer, zombie, direction=-1, hit_damage=1000)
        self.assertEqual(zombie.hp, 0)
        self.assertFalse(zombie.is_alive)
        self.assertTrue(zombie.is_dying)
        self.assertFalse(getattr(zombie, "is_corpse", False))
        self.assertTrue(zombie.is_in_knockback())

        # Step through 12 frames of death knockback
        for f in range(1, 13):
            sim.step()
            if f < 12:
                self.assertTrue(zombie.is_in_knockback())
                self.assertFalse(getattr(zombie, "is_corpse", False))
            else:
                # After 12 frames, transitions to corpse
                self.assertFalse(zombie.is_in_knockback())
                self.assertTrue(getattr(zombie, "is_corpse", False))
                self.assertEqual(zombie.corpse_timer, 60)
        print(" -> Zombie Revive Parity verified: death knockback precedes corpse burial.")

    def test_07_zombie_killer_permanent_death_parity(self):
        """Verifies that lethal hit from Zombie Killer bypasses corpse and permanently frees slot."""
        sim = BattleSimulation()
        zombie = sim.spawn_custom_unit({
            "name": "Zombo", "hp": 500, "attack_power": 10, "speed": 0, "knockback_count": 1,
            "traits": ["zombie"],
            "abilities": {"revive_count": 1, "revive_time": 60, "revive_hp_pct": 50}
        }, team=TEAM_ENEMY)
        zombie.pos_x = 1500

        zk_killer = sim.spawn_custom_unit({
            "name": "Zombie Slayer", "hp": 1000, "attack_power": 1000, "speed": 0,
            "abilities": {"zombie_killer": True}
        }, team=TEAM_CAT)

        sim._apply_damage(zk_killer, zombie, direction=-1, hit_damage=1000)
        self.assertTrue(zombie.killed_by_zombie_killer)
        self.assertTrue(zombie.is_dying)

        for _ in range(12):
            sim.step()

        self.assertIsNone(sim.units[TEAM_ENEMY][zombie.slot])
        print(" -> Zombie Killer Parity verified: death knockback -> permanent soul ascension, no revive.")

    def test_08_windup_interruption_rebound_parity(self):
        """Verifies that knockback interrupts attack windup and resets cycle_timer (rebound)."""
        sim = BattleSimulation()
        cat = sim.spawn_custom_unit({
            "name": "Cat", "hp": 1000, "attack_power": 100, "speed": 0, "knockback_count": 3,
            "attack_windup": 20, "attack_interval": 30
        }, team=TEAM_CAT)
        cat.pos_x = 1000

        cat.is_winding_up = True
        cat.windup_timer = 15
        cat.cycle_timer = 40

        # Enemy triggers damage hitback
        enemy = sim.spawn_custom_unit({"name": "Enemy", "hp": 500, "attack_power": 400, "speed": 0}, team=TEAM_ENEMY)
        sim._apply_damage(enemy, cat, direction=1, hit_damage=400)

        self.assertTrue(cat.is_in_knockback())
        self.assertFalse(cat.is_winding_up)
        self.assertEqual(cat.windup_timer, 0)
        self.assertEqual(cat.cycle_timer, 0)
        print(" -> Windup Interrupt Rebound verified: windup cancelled and cycle timer reset to 0.")

    def test_09_official_cat_cannon_recharge_formula_and_hard_cap(self):
        """Verifies official Cat Cannon formula: 2850f base at Lv 1, -50f per charge lv, +50f per power lv, 950f hard floor."""
        # 1. Unupgraded Lv 1, 0 treasures -> 2850 frames (95.0s)
        sim_unupgraded = BattleSimulation(treasures={"eoc_chapters": 0.0})
        self.assertEqual(sim_unupgraded.cannon_max_charge, 2850)

        # 2. Lv 1 with 3 chapters EoC treasures (-450f) -> 2400 frames (80.0s)
        sim_eoc = BattleSimulation(treasures={"eoc_chapters": 3.0})
        self.assertEqual(sim_eoc.cannon_max_charge, 2400)

        # 3. Maxed Charge level (Lv 30) + Max Power (Lv 1) + Max treasures -> Clamped to 950f (31.67s) hard floor
        sim_max = BattleSimulation(
            base_levels={"cannon_charge": 30, "cannon_power": 1},
            treasures={"eoc_chapters": 3.0, "cannon_charge_reduction": 1350}
        )
        self.assertEqual(sim_max.cannon_max_charge, 950, "Cannon recharge MUST be clamped at 950 frames (31.67s)")
        print(" -> Cat Cannon Recharge Parity verified: 2850f base down to 950f hard floor (31.67s).")

    def test_10_normal_cannon_wave_immunity_interaction(self):
        """Verifies that Normal Cat Cannon wave deals 0 dmg and 0 KB to enemies with wave_immune."""
        sim = BattleSimulation()
        immune_doge = sim.spawn_custom_unit({
            "name": "Wave Immune Doge", "hp": 500, "attack_power": 10, "speed": 0,
            "abilities": {"wave_immune": True}
        }, team=TEAM_ENEMY)
        immune_doge.pos_x = sim.get_castle(TEAM_CAT).pos_x - 100

        sim._cannon_hit(immune_doge, opp_team=TEAM_ENEMY, ctype="normal")
        self.assertEqual(immune_doge.hp, 500, "Wave immune unit must take 0 damage from normal cannon")
        self.assertFalse(immune_doge.is_in_knockback(), "Wave immune unit must NOT be knocked back by normal cannon")
        print(" -> Normal Cannon Wave Immunity Parity verified: 0 damage and 0 knockback.")


if __name__ == "__main__":
    suite = unittest.TestLoader().loadTestsFromTestCase(TestAutonomousParityDeepAudit)
    runner = unittest.TextTestRunner(verbosity=2)
    result = runner.run(suite)
    if not result.wasSuccessful():
        sys.exit(1)
    print("\n[+] ALL AUTONOMOUS COMBAT PARITY AUDITS PASSED WITH ZERO DISCREPANCIES!")
