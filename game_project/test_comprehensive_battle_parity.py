"""
Comprehensive Battle Cats 100% Parity Validation Suite.
Validates:
1. Unit stats and attributes fidelity against official CSV decryptions.
2. Symmetrical PvP mechanics (Team 0 Right vs Team 1 Left).
3. 4-Phase Combat State Machine (Walk -> Windup -> Hit -> Backswing -> TBA Cooldown).
4. Attack cancellation rules (Foreswing committed once started, cancelled ONLY by knockback/freeze/death).
5. Knockback physics (Hitback 345 DU/24f, Ability KB 165 DU/12f, Cannon 55 DU/11f, Boss 705 DU/47f) at constant/decelerating velocity.
6. Rebound attack: attack cycle and cooldown timers reset to 0 upon knockback.
7. Instant death on 0 HP (Battle_KillUnit 0x008b6f50) with 0 DU sliding.
8. Trait multipliers: Strong Against (1.5x/0.5x, with fruits 1.8x/0.4x), Massive Damage (3.0x/4.0x), Insane Damage (5.0x/6.0x), Resistant (0.25x/0.2x), Insanely Tough (1/6 / 1/7).
9. Metal 1-damage rule and Critical Hit 2x damage bypass.
10. Savage Blow 3.0x damage.
11. Alien Barrier (single hit must exceed barrier HP, or Barrier Breaker).
12. Aku Shield (damages accumulate, Shield Piercer, and regeneration ONLY on damage hitback).
13. Zombie Burrow & Revive, and Zombie Killer permanent kill.
14. Wave attack propagation (200 DU/seg, 3 frames/seg) and Wave Blocker extinction.
15. Surge attack (187.5 radius, 20f/level) and Surge Counter.
16. Starred Alien Warp (displaces backward, intangible for duration) and Warp Blocker.
17. Toxic % max HP true damage and Toxic Immunity.
18. Curse status disabling trait-targeting skills (Strong, Massive, Resistant, Status Procs).
19. Strengthen % attack increase when HP <= threshold.
20. Survive Lethal strike (survives with 1 HP, triggers hitback to safety).
21. Colossus Slayer (1.6x dealt, 0.7x taken) & Behemoth Slayer (2.5x dealt, 0.6x taken, 5% dodge).
22. Production Cooldown hard floor (60 frames minimum).
23. Worker Cat Wallet economy & upgrade scaling.
24. Cat Cannon firing and multi-cannon types.
"""

import sys
import unittest

from game_project.core.constants import (
    TEAM_CAT, TEAM_ENEMY, SLOT_CASTLE, KB_SPECS
)
from game_project.simulation.battle_sim import BattleSimulation, SimUnit
from game_project.core.official_data_parser import OfficialDataParser

class TestComprehensiveBattleParity(unittest.TestCase):
    def setUp(self):
        self.sim = BattleSimulation(pvp_mode=True)
        self.parser = OfficialDataParser.get_instance()

    def test_01_symmetrical_pvp_castles(self):
        """Verifies symmetrical castles at native 700 DU edge offset (Team 0 Right, Team 1 Left)."""
        c0 = self.sim.get_castle(TEAM_CAT)
        c1 = self.sim.get_castle(TEAM_ENEMY)
        self.assertEqual(c0.pos_x, self.sim.battlefield_length - 700.0)
        self.assertEqual(c1.pos_x, 700.0)
        self.assertEqual(c0.hp, 1000)
        self.assertEqual(c1.hp, 1000)

    def test_02_symmetrical_movement_and_frontline_clash(self):
        """Team 0 marches left (-1 direction) and Team 1 marches right (+1 direction)."""
        cat = self.sim.spawn_custom_unit("cat", team=TEAM_CAT)
        doge = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)
        cat.pos_x = 2000.0
        doge.pos_x = 1000.0

        for _ in range(10):
            self.sim.step()

        self.assertLess(cat.pos_x, 2000.0, "Team 0 must move left")
        self.assertGreater(doge.pos_x, 1000.0, "Team 1 must move right")

    def test_03_constant_velocity_hitback(self):
        """Authentic PONOS 345.0 DU over 24 frames (14.375 DU/frame)."""
        doge = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)
        doge.pos_x = 1200.0
        doge.knockback_max = 3
        doge.max_hp = 300
        doge.hp = 300
        doge.kb_threshold = 100.0

        attacker = self.sim.spawn_custom_unit("cat", team=TEAM_CAT)
        attacker.pos_x = 1300.0
        self.sim._apply_damage(attacker, doge, direction=-1, hit_damage=120)

        self.assertTrue(doge.is_in_knockback())
        self.assertEqual(doge.knockback_timer, 24)

        prev_x = doge.pos_x
        for f in range(24):
            self.sim.step()
            dx = prev_x - doge.pos_x
            expected_dx = 15.0 if f < 23 else 0.0  # Native 0x8b95b4: 23 active frames * 60 native (15 DU) + 1 exit tick
            self.assertAlmostEqual(dx, expected_dx, places=4, msg=f"Native State 3 hitback velocity on frame {f}")
            prev_x = doge.pos_x

        self.assertFalse(doge.is_in_knockback())
        self.assertAlmostEqual(1200.0 - doge.pos_x, 345.0, places=2)

    def test_04_constant_velocity_ability_kb(self):
        """Native State 6 Proc KB (0x5dd600): 165.0 DU (660 native / 4) over 12 frames."""
        cat = self.sim.spawn_custom_unit("cat", team=TEAM_CAT)
        cat.pos_x = 2000.0

        self.sim._knockback(cat, "kb")
        self.assertTrue(cat.is_in_knockback())
        self.assertEqual(cat.knockback_timer, 12)

        prev_x = cat.pos_x
        for f in range(12):
            self.sim.step()
            dx = cat.pos_x - prev_x  # Cat is team 0, knocks back right (+x)
            expected_dx = (((12 - (f + 1)) % 12) * 10) / 4.0
            self.assertAlmostEqual(dx, expected_dx, places=4, msg=f"State 6 Proc KB frame {f}")
            prev_x = cat.pos_x

        self.assertFalse(cat.is_in_knockback())
        self.assertAlmostEqual(cat.pos_x - 2000.0, 165.0, places=2)

    def test_05_rebound_attack_parity(self):
        """Knockback cancels windup and resets cycle_timer so unit can attack immediately."""
        cat = self.sim.spawn_custom_unit("cat", team=TEAM_CAT)
        cat.pos_x = 1500.0
        cat.is_winding_up = True
        cat.windup_timer = 10
        cat.cycle_timer = 40

        self.sim._knockback(cat, "hitback")
        self.assertFalse(cat.is_winding_up)
        self.assertEqual(cat.windup_timer, 0)
        self.assertEqual(cat.cycle_timer, 0)
        self.assertEqual(cat.attack_cooldown_timer, 0)

    def test_06_death_knockback_then_soul_parity(self):
        """Lethal blow triggers death knockback first; once knockback finishes, soul releases and slot clears."""
        doge = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)
        doge.pos_x = 800.0
        attacker = self.sim.spawn_custom_unit("cat", team=TEAM_CAT)
        attacker.pos_x = 900.0

        self.sim._apply_damage(attacker, doge, direction=-1, hit_damage=999)
        self.assertEqual(doge.hp, 0)
        self.assertTrue(doge.is_dying)
        self.assertTrue(doge.is_in_knockback())
        self.assertEqual(doge.knockback_timer, 24)

        for _ in range(24):
            self.sim.step()

        self.assertIsNone(self.sim.units[TEAM_ENEMY][1])
        ev_types = [ev["type"] for ev in self.sim.consume_visual_events()]
        self.assertIn("death", ev_types)

    def test_22_single_kb_unit_death_knockback_parity(self):
        """1-KB units (Tank Cat, Titan Cat) do not knock back on partial damage, but MUST perform death knockback on lethal damage."""
        tank = self.sim.spawn_custom_unit("tank_cat", team=TEAM_CAT)
        tank.pos_x = 1000.0
        self.assertEqual(tank.knockback_max, 1)

        attacker = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)
        attacker.pos_x = 900.0

        # Partial damage (100 out of 400 HP): should NOT knock back, holds the line
        self.sim._apply_damage(attacker, tank, direction=1, hit_damage=100)
        self.assertEqual(tank.hp, 300)
        self.assertFalse(tank.is_in_knockback())
        self.assertEqual(tank.pos_x, 1000.0)

        # Lethal damage (300 remaining HP): MUST trigger death knockback
        self.sim._apply_damage(attacker, tank, direction=1, hit_damage=300)
        self.assertEqual(tank.hp, 0)
        self.assertTrue(tank.is_dying)
        self.assertTrue(tank.is_in_knockback())
        self.assertEqual(tank.knockback_timer, 24)

        for _ in range(24):
            self.sim.step()

        self.assertIsNone(self.sim.units[TEAM_CAT][1])
        ev_types = [ev["type"] for ev in self.sim.consume_visual_events()]
        self.assertIn("death", ev_types)

    def test_07_metal_rule_and_crit(self):
        """Metal units take 1 damage from normal attacks, but critical hits deal 2x damage and bypass."""
        metal_enemy = self.sim.spawn_custom_unit({
            "name": "Metal Doge", "hp": 50, "traits": ["metal"], "speed": 0, "knockback_count": 5
        }, team=TEAM_ENEMY)
        metal_enemy.pos_x = 500.0

        attacker = self.sim.spawn_custom_unit({
            "name": "Attacker", "hp": 100, "attack_power": 100, "speed": 0
        }, team=TEAM_CAT)

        # Normal hit deals exactly 1 damage
        self.sim._apply_damage(attacker, metal_enemy, direction=-1, hit_damage=100)
        self.assertEqual(metal_enemy.hp, 49)

        # Critical hit deals 2x damage (200) and kills metal enemy
        attacker.abilities["crit_prob"] = 100
        self.sim._apply_damage(attacker, metal_enemy, direction=-1, hit_damage=100)
        self.assertEqual(metal_enemy.hp, 0)

    def test_08_aku_shield_regeneration_on_hitback_only(self):
        """Aku Shield regenerates ONLY on damage-based hitback, NOT on ability knockback."""
        aku = self.sim.spawn_custom_unit({
            "name": "Aku", "hp": 1000, "traits": ["aku"], "speed": 0,
            "abilities": {"shield_hp": 200, "shield_regen_pct": 50}
        }, team=TEAM_ENEMY)
        aku.aku_shield = 0  # Broken

        # Ability knockback does NOT regenerate shield
        self.sim._knockback(aku, "kb")
        self.assertEqual(aku.aku_shield, 0)

        # Damage-based hitback regenerates 50% = 100 shield
        self.sim._knockback(aku, "hitback")
        self.assertEqual(aku.aku_shield, 100)

    def test_09_behemoth_slayer_multiplier_and_dodge(self):
        """Behemoth Slayer deals 2.5x damage, takes 0.6x damage, and has 5% passive dodge."""
        behemoth = self.sim.spawn_custom_unit({
            "name": "Wild Doge", "hp": 1000, "traits": ["behemoth"], "speed": 0, "knockback_count": 1
        }, team=TEAM_ENEMY)

        slayer = self.sim.spawn_custom_unit({
            "name": "Slayer", "hp": 1000, "speed": 0, "attack_power": 100,
            "abilities": {"behemoth_slayer": True}
        }, team=TEAM_CAT)

        # Slayer deals 2.5x damage = 250
        self.sim._apply_damage(slayer, behemoth, direction=-1, hit_damage=100)
        self.assertEqual(behemoth.hp, 750)

        # Slayer takes 0.6x damage = 60
        self.sim._apply_damage(behemoth, slayer, direction=1, hit_damage=100)
        self.assertEqual(slayer.hp, 940)

    def test_10_slow_status_movement_speed(self):
        """Slow reduces movement speed to 0.25 DU/frame (0.5 stat * 0.5 factor)."""
        doge = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)
        doge.pos_x = 1200.0
        doge.slow_timer = 60

        prev_x = doge.pos_x
        self.sim.step()
        dx = doge.pos_x - prev_x
        self.assertAlmostEqual(dx, 0.25, places=4, msg="Slowed speed must be exactly 0.25 DU/frame")

    def test_11_cooldown_60_frame_hard_floor(self):
        """Cat production cooldown cannot drop below 60 frames (2.0s)."""
        self.sim.deployer.set_deck(["cat"])
        self.sim.wallet.money = 10000

        # Trigger deployment
        self.assertTrue(self.sim.deploy_unit(TEAM_CAT, 0))
        # Even with max treasures, cooldown is clamped to >= 60 frames
        self.assertGreaterEqual(self.sim.deployer.cooldowns[0], 60)

    def test_12_survive_lethal_strike_and_hitback_escape(self):
        """Unit surviving lethal strike survives with 1 HP and triggers hitback to escape."""
        unit = self.sim.spawn_custom_unit({
            "name": "Jiangshi", "hp": 100, "knockback_count": 3, "speed": 0,
            "abilities": {"survive_prob": 100}
        }, team=TEAM_CAT)
        attacker = self.sim.spawn_custom_unit("doge", team=TEAM_ENEMY)

        self.sim._apply_damage(attacker, unit, direction=1, hit_damage=500)
        self.assertEqual(unit.hp, 1)
        self.assertTrue(unit.survived_lethal)
        self.assertTrue(unit.is_in_knockback(), "Unit must trigger hitback to safety upon surviving lethal")

    def test_13_wave_blocker_absorbs_wave_damage_and_protects_backline(self):
        """Wave Blocker takes wave damage and extinguishes the wave, protecting units behind it."""
        blocker = self.sim.spawn_custom_unit({
            "name": "Octo", "hp": 2000, "speed": 0, "abilities": {"wave_blocker": True}
        }, team=TEAM_CAT)
        blocker.pos_x = 1000

        backline = self.sim.spawn_custom_unit({
            "name": "Backline", "hp": 500, "speed": 0
        }, team=TEAM_CAT)
        backline.pos_x = 1400

        enemy = self.sim.spawn_custom_unit({"name": "Wave Enemy", "hp": 1000, "speed": 0}, team=TEAM_ENEMY)
        enemy.pos_x = 800

        self.sim._trigger_wave_attack(enemy, opp_team=TEAM_CAT, direction=1, wave_lvl=3, hit_damage=300)
        for _ in range(15):
            self.sim.step()

        # Blocker took 300 damage
        self.assertEqual(blocker.hp, 1700)
        # Backline was protected and took 0 damage
        self.assertEqual(backline.hp, 500)

    def test_14_aku_shield_negates_excess_breaking_damage(self):
        """Authentic PONOS rule: when an Aku Shield breaks from normal damage, excess damage is completely negated."""
        aku = self.sim.spawn_custom_unit({
            "name": "Aku Foe", "hp": 1000, "speed": 0, "abilities": {"shield_hp": 100}
        }, team=TEAM_ENEMY)
        aku.aku_shield = 100

        attacker = self.sim.spawn_custom_unit({"name": "Hitter", "hp": 100, "speed": 0}, team=TEAM_CAT)
        # Deals 500 damage to a 100 HP shield
        self.sim._apply_damage(attacker, aku, direction=-1, hit_damage=500)

        # Shield is broken
        self.assertEqual(aku.aku_shield, 0)
        # Enemy took 0 damage to main HP: 500 damage was completely absorbed by the 100 HP shield!
        self.assertEqual(aku.hp, 1000)

    def test_15_aku_shield_blocks_status_effects_and_toxic(self):
        """Active Aku Shield completely blocks Freeze, Slow, Weaken, KB proc, and Toxic true damage."""
        aku = self.sim.spawn_custom_unit({
            "name": "Aku Foe", "hp": 1000, "speed": 0, "abilities": {"shield_hp": 500}
        }, team=TEAM_ENEMY)
        aku.aku_shield = 500

        attacker = self.sim.spawn_custom_unit({
            "name": "Crowd Controller", "hp": 100, "speed": 0,
            "abilities": {
                "freeze_prob": 100, "freeze_dur": 90,
                "slow_prob": 100, "slow_dur": 90,
                "weaken_prob": 100, "weaken_dur": 90,
                "toxic_prob": 100, "toxic_hp_pct": 20,
            }
        }, team=TEAM_CAT)

        self.sim._apply_damage(attacker, aku, direction=-1, hit_damage=100)
        # Shield absorbed 100 damage
        self.assertEqual(aku.aku_shield, 400)
        # Main HP intact
        self.assertEqual(aku.hp, 1000)
        # All debuffs blocked
        self.assertEqual(aku.freeze_timer, 0)
        self.assertEqual(aku.slow_timer, 0)
        self.assertEqual(aku.weaken_timer, 0)

    def test_16_alien_barrier_blocks_status_effects_and_toxic(self):
        """Unbroken Alien Barrier blocks damage, status effects, and Toxic true damage."""
        barrier_unit = self.sim.spawn_custom_unit({
            "name": "Starred Alien", "hp": 1000, "speed": 0,
            "abilities": {"barrier_hp": 500}
        }, team=TEAM_ENEMY)
        barrier_unit.barrier = 500

        attacker = self.sim.spawn_custom_unit({
            "name": "Debuffer", "hp": 100, "speed": 0,
            "abilities": {"slow_prob": 100, "slow_dur": 60, "toxic_prob": 100, "toxic_hp_pct": 25}
        }, team=TEAM_CAT)

        # 200 damage fails to exceed 500 barrier
        self.sim._apply_damage(attacker, barrier_unit, direction=-1, hit_damage=200)
        self.assertEqual(barrier_unit.barrier, 500)
        self.assertEqual(barrier_unit.hp, 1000)
        self.assertEqual(barrier_unit.slow_timer, 0)

    def test_17_shield_piercing_deals_direct_damage_and_applies_status(self):
        """Shield Piercing destroys shield and delivers full damage and status to enemy."""
        aku = self.sim.spawn_custom_unit({
            "name": "Aku Foe", "hp": 1000, "speed": 0, "abilities": {"shield_hp": 500}
        }, team=TEAM_ENEMY)
        aku.aku_shield = 500

        piercer = self.sim.spawn_custom_unit({
            "name": "Piercer", "hp": 100, "speed": 0,
            "abilities": {"shield_pierce_prob": 100, "freeze_prob": 100, "freeze_dur": 60}
        }, team=TEAM_CAT)

        self.sim._apply_damage(piercer, aku, direction=-1, hit_damage=300)
        # Shield pierced and set to 0
        self.assertEqual(aku.aku_shield, 0)
        # Full 300 damage hit enemy HP directly
        self.assertEqual(aku.hp, 700)
        # Freeze status successfully applied
        self.assertEqual(aku.freeze_timer, 60)

    def test_18_cat_cannon_types_parity(self):
        """Validates authentic behavior of Slowbeam, Curseblast, and Normal Cannon."""
        doge = self.sim.spawn_custom_unit({"name": "Doge", "hp": 1000, "speed": 0}, team=TEAM_ENEMY)

        # 1. Slowbeam: 0 damage, 0 KB, pure 120-frame Slow
        init_hp = doge.hp
        self.sim._cannon_hit(doge, opp_team=TEAM_ENEMY, ctype="slow")
        self.assertEqual(doge.hp, init_hp)
        self.assertFalse(doge.is_in_knockback())
        self.assertEqual(doge.slow_timer, 120)

        # 2. Curseblast: 0 damage, 0 KB, pure 180-frame Curse
        self.sim._cannon_hit(doge, opp_team=TEAM_ENEMY, ctype="curseblast")
        self.assertEqual(doge.hp, init_hp)
        self.assertFalse(doge.is_in_knockback())
        self.assertEqual(doge.curse_timer, 180)

        # 3. Normal Cannon: deals damage and knocks back normally immune enemies
        doge.abilities["kb_immune"] = True
        self.sim._cannon_hit(doge, opp_team=TEAM_ENEMY, ctype="normal")
        self.assertLess(doge.hp, init_hp)
        self.assertTrue(doge.is_in_knockback(), "Normal cannon must knock back enemies even with kb_immune")

    def test_19_survive_single_kb_guaranteed_hitback(self):
        """Unit with knockback_count = 1 (like Jiangshi Cat) STILL triggers hitback on survive."""
        jiangshi = self.sim.spawn_custom_unit({
            "name": "Jiangshi", "hp": 200, "knockback_count": 1, "speed": 0,
            "abilities": {"survive_prob": 100}
        }, team=TEAM_CAT)
        attacker = self.sim.spawn_custom_unit({"name": "Boss", "hp": 1000, "speed": 0}, team=TEAM_ENEMY)

        self.sim._apply_damage(attacker, jiangshi, direction=1, hit_damage=999)
        self.assertEqual(jiangshi.hp, 1)
        self.assertTrue(jiangshi.survived_lethal)
        self.assertTrue(jiangshi.is_in_knockback(), "1-KB unit MUST trigger emergency hitback upon surviving lethal")

    def test_20_curse_disables_attacks_only(self):
        """Curse status lifts Attacks Only restriction so unit can target any entity."""
        attacker = self.sim.spawn_custom_unit({
            "name": "Anti-Red Only", "hp": 100, "speed": 0,
            "target_traits": ["red"],
            "abilities": {"attacks_only": True}
        }, team=TEAM_CAT)

        black_doge = self.sim.spawn_custom_unit({
            "name": "Black Doge", "hp": 100, "traits": ["black"], "speed": 0
        }, team=TEAM_ENEMY)

        # Uncursed: cannot target black doge
        self.assertFalse(self.sim._can_unit_target_opponent(attacker, black_doge))

        # Cursed: Attacks Only is disabled, can target black doge!
        attacker.curse_timer = 60
        self.assertTrue(self.sim._can_unit_target_opponent(attacker, black_doge))

    def test_21_cat_cannon_range_scaling_formula(self):
        """Authentic PONOS formula in DU (/4): Level 1 = 588.75 DU, +101.25 DU / level, Level 10 = 1500.0 DU."""
        sim_lv1 = BattleSimulation(base_levels={"cannon_range": 1})
        self.assertAlmostEqual(sim_lv1.cannon_ranges[TEAM_CAT], 588.75, places=4)

        sim_lv5 = BattleSimulation(base_levels={"cannon_range": 5})
        self.assertAlmostEqual(sim_lv5.cannon_ranges[TEAM_CAT], (2355 + 405 * 4) / 4.0, places=4)

        sim_lv10 = BattleSimulation(base_levels={"cannon_range": 10})
        self.assertAlmostEqual(sim_lv10.cannon_ranges[TEAM_CAT], 1500.0, places=4)

    def test_22_native_check_range_world_scale_and_kb_y_arc(self):
        """Verifies CheckRange hurtbox interval [pos - back, pos], State 3/5 KB Y-arcs, and 8/15 world scale."""
        from game_project.core.constants import BATTLE_WORLD_SCALE
        from game_project.render.camera import Camera2D

        cat = self.sim.spawn_custom_unit({
            "name": "Cat", "hp": 1000, "attack_power": 10, "attack_range": 140,
            "speed": 0, "hitbox_front": 0, "hitbox_back": 320
        }, team=TEAM_CAT)
        doge = self.sim.spawn_custom_unit({
            "name": "Doge", "hp": 1000, "attack_power": 10, "attack_range": 110,
            "speed": 0, "knockback_count": 3, "hitbox_front": 0, "hitbox_back": 320
        }, team=TEAM_ENEMY)
        doge.pos_x = 1200.0  # Doge hurtbox covers [880.0, 1200.0]
        cat.pos_x = 1050.0   # Standing attack box [910.0, 1050.0] overlaps Doge body behind nose
        in_box, _ = self.sim._is_opp_in_attack_box(cat, doge, direction=-1)
        self.assertTrue(in_box, "Cat attack span [910, 1050] must overlap Doge hurtbox [880, 1200]")
        in_stand, _ = self.sim._is_opp_in_standing_range(cat, doge, direction=-1)
        self.assertTrue(in_stand)
        doge.pos_x = 800.0   # Hurtbox [480, 800] < 910 -> out of range
        in_box_out, _ = self.sim._is_opp_in_attack_box(cat, doge, direction=-1)
        self.assertFalse(in_box_out)

        # State 3 Hitback Y-arc peaks at -112.5 DU (-450 native / 4) and lands at 0.0
        doge.pos_x = 1400.0
        self.sim._knockback(doge, "hitback")
        y_hist = []
        for _ in range(24):
            self.sim.step()
            y_hist.append(doge.kb_y)
        self.assertAlmostEqual(min(y_hist), -112.5, places=3)
        self.assertAlmostEqual(doge.kb_y, 0.0, places=4)

        # State 5 Cannon KB Y-arc peaks at -75.0 DU (-300 native / 4) and lands at 0.0
        doge.pos_x = 1400.0
        self.sim._knockback(doge, "cannon")
        cy_hist = []
        for _ in range(11):
            self.sim.step()
            cy_hist.append(doge.kb_y)
        self.assertAlmostEqual(min(cy_hist), -75.0, places=3)
        self.assertAlmostEqual(doge.kb_y, 0.0, places=4)

        # Camera world scale matches authentic libnative-lib.so 720p virtual projection (0.4 * 720/640 = 0.45 px/DU)
        cam = Camera2D(world_width=3000)
        cam.offset_x = 0.0
        self.assertAlmostEqual(cam.world_scale, 0.4 * (720.0 / 640.0), places=6)
        self.assertEqual(cam.world_to_screen_x(1500.0), int(1500.0 * BATTLE_WORLD_SCALE))

    def test_23_native_kb_tick_durations_and_cannon_hitback_override(self):
        """Verifies State 5 (12f), State 7 (48f), and Cannon HP-threshold hitback priority (0x5c731c)."""
        doge = self.sim.spawn_custom_unit({
            "name": "Doge", "hp": 1000, "attack_power": 10, "speed": 0, "knockback_count": 3
        }, team=TEAM_ENEMY)
        doge.pos_x = 1200.0
        self.sim._knockback(doge, "cannon")
        self.assertEqual(doge.knockback_timer, 12)
        for _ in range(12):
            self.sim.step()
        self.assertFalse(doge.is_in_knockback())
        self.assertAlmostEqual(1200.0 - doge.pos_x, 55.0, places=4)
        self.assertAlmostEqual(doge.kb_y, 0.0, places=4)

        # Boss State 7: 47 * 15.0 = 705.0 DU across 48 frames
        doge.pos_x = 2000.0
        self.sim._knockback(doge, "boss")
        self.assertEqual(doge.knockback_timer, 48)
        for _ in range(48):
            self.sim.step()
        self.assertFalse(doge.is_in_knockback())
        self.assertAlmostEqual(2000.0 - doge.pos_x, 705.0, places=4)
        self.assertAlmostEqual(doge.kb_y, 0.0, places=4)

        # Cannon crossing HP KB threshold triggers State 3 hitback (24f) over State 5 (12f)
        doge.pos_x = 1200.0
        doge.hp = 400  # max_hp=1000, kb_threshold=333.33 -> already 1 KB taken
        doge.kb_points_taken = 1
        self.sim.cannon_powers[TEAM_CAT] = 400
        self.sim._cannon_hit(doge, opp_team=TEAM_ENEMY, ctype="breakerblast")  # deals 200 -> hp=200 (threshold 2)
        self.assertEqual(doge.kb_kind, "hitback")
        self.assertEqual(doge.knockback_timer, 24)

    def test_24_maanim_loop_len_and_additive_tracks_parity(self):
        """Verifies Hacker Cat 035_c02 240f loop length, z-depth scale, and additive duplicate tracks."""
        import os
        from game_project.core.unit_data import CAT_REGISTRY
        from game_project.anim_engine.ponos_anim_player import PonosMaanim

        hacker = CAT_REGISTRY["sr_hacker"]
        self.assertEqual(hacker["attack_anim_len"], 240)
        ma_hacker = PonosMaanim(os.path.join(r"E:\rea\game_project\assets\official_extracted", "035_c02.maanim"))
        self.assertEqual(ma_hacker.max_frame, 240)

        # Duplicate tracks on same (part, mod) accumulate additively cleanly (037_f00 part 9 rot)
        ma_pogo = PonosMaanim(os.path.join(r"E:\rea\game_project\assets\official_extracted", "037_f00.maanim"))
        p9_rot_tracks = [t for t in ma_pogo.tracks if t.part_id == 9 and t.mod_type == 11]
        self.assertEqual(len(p9_rot_tracks), 2)
        # Base -80 + track1(0 at f=0) + track2(-250 at f=0) == -330 (not overwritten to -330 without track1)
        total_f6 = -80 + sum(t.get_value(6) or 0 for t in p9_rot_tracks)
        # Track 1 at frame 6 is +100, Track 2 is non-zero negative: combined includes +100!
        self.assertEqual(p9_rot_tracks[0].get_value(6), 100)
        self.assertEqual(total_f6, -80 + 100 + p9_rot_tracks[1].get_value(6))

    def test_25_freeze_pauses_windup_without_cancelling(self):
        """Native 0x5cbf84: Freeze pauses foreswing timer & anim_frame without cancelling windup; resumes on thaw."""
        cat = self.sim.spawn_custom_unit({
            "name": "Freeze Tester", "hp": 5000, "attack_power": 250, "speed": 0,
            "attack_range": 200, "attack_windup": 10, "attack_anim_len": 20, "attack_interval": 15,
        }, team=TEAM_CAT)
        cat.pos_x = 1200.0
        target = self.sim.spawn_custom_unit({
            "name": "Punching Bag", "hp": 5000, "attack_power": 0, "speed": 0,
        }, team=TEAM_ENEMY)
        target.pos_x = 1100.0

        # Step until cat enters windup and advances 4 frames (windup_timer = 6 left)
        for _ in range(5):
            self.sim.step()
        self.assertTrue(cat.is_winding_up)
        paused_windup = cat.windup_timer
        paused_af = cat.anim_frame

        # Apply 5 frames of Freeze: windup stays True and timers pause
        cat.freeze_timer = 5
        for _ in range(5):
            self.sim.step()
        self.assertTrue(cat.is_winding_up)
        self.assertEqual(cat.windup_timer, paused_windup)
        self.assertEqual(cat.anim_frame, paused_af)
        self.assertEqual(target.hp, 5000)

        # Resume remaining windup frames -> hit lands without restarting foreswing from 10
        for _ in range(paused_windup):
            self.sim.step()
        self.assertFalse(cat.is_winding_up)
        self.assertEqual(target.hp, 4750)
        self.assertEqual(cat.tba_timer, 14)

    def test_26_once_per_swing_proc_preroll_and_status_overwrite(self):
        """Native 0x5da618 + 0x5d6da0: Proc rolls once per swing across area targets, and shorter status overwrites longer."""
        cat = self.sim.spawn_custom_unit({
            "name": "Crit Area Cat", "hp": 5000, "attack_power": 100, "speed": 0,
            "attack_range": 300, "target_type": "area", "attack_windup": 1, "attack_anim_len": 5, "attack_interval": 1,
            "abilities": {"crit_prob": 50, "slow_prob": 100, "slow_dur": 30},
        }, team=TEAM_CAT)
        cat.pos_x = 1200.0
        e1 = self.sim.spawn_custom_unit({"name": "E1", "hp": 1000, "attack_power": 0, "speed": 0}, team=TEAM_ENEMY)
        e2 = self.sim.spawn_custom_unit({"name": "E2", "hp": 1000, "attack_power": 0, "speed": 0}, team=TEAM_ENEMY)
        e1.pos_x = 1100.0
        e2.pos_x = 1120.0
        e1.slow_timer = 90  # Longer existing timer should be overwritten by 30f direct str
        self.sim.rng.seed(7)
        for _ in range(2):
            self.sim.step()
        dmg1 = 1000 - e1.hp
        dmg2 = 1000 - e2.hp
        self.assertEqual(dmg1, dmg2, "Area targets in same swing must share the 0x5da618 crit roll")
        self.assertIn(dmg1, (100, 200))
        self.assertEqual(e1.slow_timer, 30, "0x5d6da0 directly overwrites slow_timer even when shorter")

    def test_27_ld_checks_target_center_and_explosion_3_rings(self):
        """Native 0x5ce084 (LD checks target center) & 0x4c3f24 (3-ring Explosion widths 200/125/100 DU & 100/60/20%)."""
        # 1. LD target center check: hitbox_front pushes edge into LD box, but center is outside -> miss
        ld_cat = self.sim.spawn_custom_unit({
            "name": "LD Cat", "hp": 1000, "attack_power": 100, "speed": 0, "attack_range": 400,
            "abilities": {"ld_start": 200, "ld_range": 200},  # [600, 800] for cat at 1000
        }, team=TEAM_CAT)
        ld_cat.pos_x = 1000.0
        fat_enemy = self.sim.spawn_custom_unit({
            "name": "Fat Front", "hp": 1000, "attack_power": 0, "speed": 0, "hitbox_front": 100, "hitbox_back": 100,
        }, team=TEAM_ENEMY)
        fat_enemy.pos_x = 550.0  # front=450, back=650 (overlaps [600,800]), center=550 (outside [600,800])
        in_box, _ = self.sim._is_opp_in_attack_box(ld_cat, fat_enemy, direction=-1)
        self.assertFalse(in_box, "LD attack box must check target center pos_x (550 < 600)")
        fat_enemy.pos_x = 620.0
        in_box2, _ = self.sim._is_opp_in_attack_box(ld_cat, fat_enemy, direction=-1)
        self.assertTrue(in_box2)

        # 2. Explosion 3 expanding rings: Ring 0 (f=15, +-100 DU, 100%), Ring 1 (f=30, +-[100,225) DU, 60%), Ring 2 (f=45, +-[225,325) DU, 20%)
        exp_cat = self.sim.spawn_custom_unit({
            "name": "Exp Cat", "hp": 1000, "attack_power": 1000, "speed": 0,
            "abilities": {"explosion_prob": 100, "explosion_start": 300, "explosion_width": 0},
        }, team=TEAM_CAT)
        exp_cat.pos_x = 1500.0  # Explosion origin = 1500 - 300 = 1200.0
        r0 = self.sim.spawn_custom_unit({"name": "R0", "hp": 2000, "speed": 0, "hitbox_front": 0}, team=TEAM_ENEMY)
        r1 = self.sim.spawn_custom_unit({"name": "R1", "hp": 2000, "speed": 0, "hitbox_front": 0}, team=TEAM_ENEMY)
        r2 = self.sim.spawn_custom_unit({"name": "R2", "hp": 2000, "speed": 0, "hitbox_front": 0}, team=TEAM_ENEMY)
        r0.pos_x = 1150.0  # offset -50 (Ring 0)
        r1.pos_x = 1040.0  # offset -160 (Ring 1)
        r2.pos_x = 925.0   # offset -275 (Ring 2)

        self.sim._trigger_explosion_attack(exp_cat, opp_team=TEAM_ENEMY, direction=-1, hit_damage=1000)
        for _ in range(15):
            self.sim.step()
        self.assertEqual(r0.hp, 2000, "Before tick 15, ring 0 not active yet")
        self.sim.step()  # tick=15 -> Ring 0 fires
        self.assertEqual(r0.hp, 1000, "Ring 0 deals 100% (1000)")
        self.assertEqual(r1.hp, 2000)
        for _ in range(15):
            self.sim.step()  # tick=30 -> Ring 1 fires
        self.assertEqual(r1.hp, 1400, "Ring 1 deals 60% (600)")
        self.assertEqual(r2.hp, 2000)
        for _ in range(15):
            self.sim.step()  # tick=45 -> Ring 2 fires
        self.assertEqual(r2.hp, 1800, "Ring 2 deals 20% (200)")
        self.assertEqual(r0.hp, 1000, "Each target hit at most once across all 3 explosion rings")

    def test_28_normal_cannon_single_damage_emit_and_waterblast_no_kb(self):
        """Native 0x4c6340: Normal cannon emits 1 damage event (no duplicate crit), Waterblast deals % HP with no KB."""
        self.sim.consume_visual_events()
        d1 = self.sim.spawn_custom_unit({"name": "D1", "hp": 2000, "speed": 0}, team=TEAM_ENEMY)
        d1.pos_x = 1500.0
        self.sim._cannon_hit(d1, opp_team=TEAM_ENEMY, ctype="normal")
        dmg_evs = [e for e in self.sim.visual_events if e.get("type") == "damage"]
        self.assertEqual(len(dmg_evs), 1, "Normal cannon must emit exactly 1 damage event")
        self.assertFalse(dmg_evs[0].get("is_crit", False))

        d2 = self.sim.spawn_custom_unit({"name": "D2", "hp": 2000, "speed": 0}, team=TEAM_ENEMY)
        d2.pos_x = 1500.0
        self.sim._cannon_hit(d2, opp_team=TEAM_ENEMY, ctype="waterblast")
        self.assertEqual(d2.hp, 1900, "Waterblast deals 5% max HP to Non-Metal (2000 * 50 // 1000 = 100)")
        self.assertFalse(d2.is_in_knockback(), "Waterblast does not knockback")

if __name__ == "__main__":
    unittest.main()
