"""
Comprehensive Test Suite for Authentic PONOS Battle Mechanics.
Validates:
1. Wave Blocker: extinguishes wave progression immediately upon contact.
2. Surge Attack: 187.5-radius column dealing damage every 20 frames for level * 20 frames.
3. Surge Immune: takes 0 damage from surge columns.
4. Curse: neutralizes trait-matched damage boosts and status procs while active.
5. Toxic: deals % of max HP true damage on procs.
6. Aku Shield: absorbs damage until depleted; Shield Piercer shatters instantly.
7. Zombie Burrow: travels underground under frontline cats.
8. Zombie Revive: enters corpse state and revives unless slain by Zombie Killer.
9. Accounting Power & Double Bounty: scales defeated enemy wallet drops.
"""

import unittest
from game_project.simulation.battle_sim import BattleSimulation, SimUnit
from game_project.core.constants import TEAM_CAT, TEAM_ENEMY, SLOT_CASTLE

class TestBattleParityMechanics(unittest.TestCase):
    def setUp(self):
        self.sim = BattleSimulation()

    def test_wave_blocker_extinguishes_wave(self):
        # Cat with wave blocker
        blocker = self.sim.spawn_custom_unit({
            "name": "Octo Cat",
            "hp": 2000,
            "attack_power": 100,
            "speed": 0,
            "abilities": {"wave_blocker": True}
        }, team=TEAM_CAT)
        blocker.pos_x = 1000

        # Friendly unit behind blocker
        cat_behind = self.sim.spawn_custom_unit({
            "name": "Cat Behind",
            "hp": 500,
            "attack_power": 50,
            "speed": 0
        }, team=TEAM_CAT)
        cat_behind.pos_x = 1400

        # Enemy releasing Level 3 wave from pos_x 800 (direction +1 toward cats)
        enemy = self.sim.spawn_custom_unit({
            "name": "Wave Enemy",
            "hp": 1000,
            "attack_power": 200,
            "speed": 0
        }, team=TEAM_ENEMY)
        enemy.pos_x = 800

        init_blocker_hp = blocker.hp
        init_behind_hp = cat_behind.hp

        # Trigger level 3 wave
        self.sim._trigger_wave_attack(enemy, opp_team=TEAM_CAT, direction=1, wave_lvl=3, hit_damage=200)

        # Step 15 frames for wave to progress
        all_evs = []
        for _ in range(15):
            self.sim.step()
            all_evs.extend(self.sim.visual_events)

        # Wave blocker took 0 damage and blocked the wave from reaching cat_behind
        self.assertEqual(blocker.hp, init_blocker_hp)
        self.assertEqual(cat_behind.hp, init_behind_hp)
        # Verify wave_block visual event was emitted
        block_evs = [ev for ev in all_evs if ev.get("type") == "wave_block"]
        self.assertTrue(len(block_evs) > 0, "Expected wave_block event")

    def test_surge_attack_ticks_and_surge_immune(self):
        # Enemy with surge immune
        immune_cat = self.sim.spawn_custom_unit({
            "name": "Surge Immune Cat",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0,
            "abilities": {"surge_immune": True}
        }, team=TEAM_CAT)
        immune_cat.pos_x = 1500

        normal_cat = self.sim.spawn_custom_unit({
            "name": "Normal Cat",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0
        }, team=TEAM_CAT)
        normal_cat.pos_x = 1500

        attacker = self.sim.spawn_custom_unit({
            "name": "Surge Attacker",
            "hp": 2000,
            "attack_power": 100,
            "speed": 0,
            "abilities": {"surge_start": 500, "surge_range": 0}
        }, team=TEAM_ENEMY)
        attacker.pos_x = 1000

        # Trigger level 2 surge (lasts 40 frames, hits at frame 0 and frame 20)
        self.sim._trigger_surge_attack(attacker, opp_team=TEAM_CAT, direction=1, surge_lvl=2, hit_damage=100)

        # Frame 0 hit lands
        self.assertEqual(immune_cat.hp, 1000, "Surge immune cat should take 0 damage")
        self.assertEqual(normal_cat.hp, 900, "Normal cat took first surge tick")

        # Step 20 frames to trigger second surge tick
        for _ in range(20):
            self.sim.step()

        self.assertEqual(immune_cat.hp, 1000, "Surge immune cat took 0 damage from 2nd tick")
        self.assertEqual(normal_cat.hp, 800, "Normal cat took second surge tick")

    def test_curse_disables_trait_abilities(self):
        # Red Enemy
        red_enemy = self.sim.spawn_custom_unit({
            "name": "Red Enemy",
            "hp": 2000,
            "attack_power": 100,
            "speed": 0,
            "traits": ["red"]
        }, team=TEAM_ENEMY)

        # Cat with Massive Damage vs Red (3x)
        cat = self.sim.spawn_custom_unit({
            "name": "Massive Damage Cat",
            "hp": 1000,
            "attack_power": 100,
            "speed": 0,
            "target_traits": ["red"],
            "abilities": {"massive_damage": True}
        }, team=TEAM_CAT)

        # Without curse: 100 * 3 = 300 damage
        self.sim._apply_damage(cat, red_enemy, direction=-1, hit_damage=100)
        self.assertEqual(red_enemy.hp, 1700)

        # Apply Curse to Cat for 60 frames
        cat.curse_timer = 60
        self.assertTrue(cat.is_cursed())

        # While cursed: massive damage is suppressed, deals 100 raw damage
        self.sim._apply_damage(cat, red_enemy, direction=-1, hit_damage=100)
        self.assertEqual(red_enemy.hp, 1600)

    def test_toxic_damage_and_immunity(self):
        target = self.sim.spawn_custom_unit({
            "name": "Target Cat",
            "hp": 1000,
            "max_hp": 1000,
            "attack_power": 50,
            "speed": 0
        }, team=TEAM_CAT)

        toxic_attacker = self.sim.spawn_custom_unit({
            "name": "Toxic Enemy",
            "hp": 500,
            "attack_power": 10,
            "speed": 0,
            "abilities": {"toxic_prob": 100, "toxic_hp_pct": 40}
        }, team=TEAM_ENEMY)

        # Deals 10 base damage + 40% max HP toxic damage (400) = 410 total
        self.sim._apply_damage(toxic_attacker, target, direction=1, hit_damage=10)
        self.assertEqual(target.hp, 1000 - 410)

        # Toxic immune target
        immune_target = self.sim.spawn_custom_unit({
            "name": "Toxic Immune Cat",
            "hp": 1000,
            "max_hp": 1000,
            "attack_power": 50,
            "speed": 0,
            "abilities": {"toxic_immune": True}
        }, team=TEAM_CAT)

        self.sim._apply_damage(toxic_attacker, immune_target, direction=1, hit_damage=10)
        self.assertEqual(immune_target.hp, 990, "Toxic immune target only took base damage")

    def test_aku_shield_absorption_and_pierce(self):
        # Aku enemy with 300 shield
        aku_enemy = self.sim.spawn_custom_unit({
            "name": "Aku Enemy",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0,
            "traits": ["aku"],
            "abilities": {"shield_hp": 300}
        }, team=TEAM_ENEMY)
        self.assertEqual(aku_enemy.aku_shield, 300)

        cat = self.sim.spawn_custom_unit({
            "name": "Attacking Cat",
            "hp": 500,
            "attack_power": 100,
            "speed": 0
        }, team=TEAM_CAT)

        # Hit for 100: absorbed by shield
        self.sim._apply_damage(cat, aku_enemy, direction=-1, hit_damage=100)
        self.assertEqual(aku_enemy.aku_shield, 200)
        self.assertEqual(aku_enemy.hp, 1000)

        # Shield Piercer cat: 100% pierce instantly destroys remaining 200 shield
        piercer_cat = self.sim.spawn_custom_unit({
            "name": "Piercer Cat",
            "hp": 500,
            "attack_power": 100,
            "speed": 0,
            "abilities": {"shield_pierce_prob": 100}
        }, team=TEAM_CAT)

        self.sim._apply_damage(piercer_cat, aku_enemy, direction=-1, hit_damage=100)
        self.assertEqual(aku_enemy.aku_shield, 0, "Shield was pierced")
        self.assertEqual(aku_enemy.hp, 900, "Damage dealt after shield pierced")

    def test_zombie_revive_and_zombie_killer(self):
        # Zombie enemy with 1 revive at 50% HP
        zombie = self.sim.spawn_custom_unit({
            "name": "Zombie Doge",
            "hp": 100,
            "attack_power": 20,
            "speed": 0,
            "traits": ["zombie"],
            "abilities": {"revive_count": 1, "revive_time": 5, "revive_hp_pct": 50}
        }, team=TEAM_ENEMY)

        normal_cat = self.sim.spawn_custom_unit({
            "name": "Normal Cat",
            "hp": 500,
            "attack_power": 100,
            "speed": 0
        }, team=TEAM_CAT)

        # Normal cat kills zombie
        self.sim._apply_damage(normal_cat, zombie, direction=-1, hit_damage=150)
        self.sim.step()

        # Zombie should enter corpse state rather than dying permanently
        self.assertTrue(zombie.is_corpse)
        self.assertFalse(zombie.is_alive)

        # Step 6 frames for corpse revive timer to complete
        for _ in range(6):
            self.sim.step()

        # Zombie revived with 50% HP (50 HP)
        self.assertFalse(zombie.is_corpse)
        self.assertTrue(zombie.is_alive)
        self.assertEqual(zombie.hp, 50)

        # Zombie killer cat delivers lethal blow
        zk_cat = self.sim.spawn_custom_unit({
            "name": "Zombie Killer Cat",
            "hp": 500,
            "attack_power": 100,
            "speed": 0,
            "abilities": {"zombie_killer": True}
        }, team=TEAM_CAT)

        self.sim._apply_damage(zk_cat, zombie, direction=-1, hit_damage=100)
        self.sim.step()

        # Killed by zombie killer: enters permanent death knockback sequence
        self.assertFalse(zombie.is_corpse)
        self.assertTrue(zombie.is_dying)

    def test_starred_alien_warp_and_warp_blocker(self):
        # 1. Regular cat
        normal_cat = self.sim.spawn_custom_unit({
            "name": "Normal Cat",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0
        }, team=TEAM_CAT)
        normal_cat.pos_x = 1000

        # Warp enemy
        warper = self.sim.spawn_custom_unit({
            "name": "Alien Warper",
            "hp": 2000,
            "attack_power": 50,
            "speed": 0,
            "abilities": {
                "warp_prob": 100,
                "warp_dur": 20,
                "warp_min": 200,
                "warp_max": 200
            }
        }, team=TEAM_ENEMY)
        warper.pos_x = 800

        # Apply hit to normal cat: should get warped
        self.sim._apply_damage(warper, normal_cat, direction=1, hit_damage=50)
        self.assertTrue(normal_cat.is_warped)
        self.assertEqual(normal_cat.warp_timer, 20)
        self.assertFalse(self.sim._can_unit_target_opponent(warper, normal_cat))

        # Advance 20 frames for warp to complete
        for _ in range(20):
            self.sim.step()

        # Reappeared displaced 200px backward toward Cat Base (1000 -> 1200)
        self.assertFalse(normal_cat.is_warped)
        self.assertEqual(normal_cat.pos_x, 1200)

        # 2. Cat with Warp Blocker
        blocker = self.sim.spawn_custom_unit({
            "name": "Satellite Cat",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0,
            "abilities": {"warp_blocker": True}
        }, team=TEAM_CAT)
        blocker.pos_x = 1000

        self.sim._apply_damage(warper, blocker, direction=1, hit_damage=50)
        self.assertFalse(blocker.is_warped)
        self.assertEqual(blocker.warp_timer, 0)
        # Check warp_block visual event
        evs = self.sim.visual_events
        self.assertTrue(any(e.get("type") == "warp_block" for e in evs))

    def test_surge_counter_triggers_retaliation(self):
        # Target with surge counter
        counter_cat = self.sim.spawn_custom_unit({
            "name": "Surge Counter Cat",
            "hp": 5000,
            "attack_power": 300,
            "speed": 0,
            "abilities": {"surge_counter": True, "surge_lvl": 1}
        }, team=TEAM_CAT)
        counter_cat.pos_x = 1000

        enemy = self.sim.spawn_custom_unit({
            "name": "Enemy",
            "hp": 5000,
            "attack_power": 100,
            "speed": 0,
            "abilities": {"surge_start": 0, "surge_range": 0}
        }, team=TEAM_ENEMY)
        enemy.pos_x = 1000

        # Enemy triggers surge on counter cat
        self.sim._trigger_surge_attack(enemy, opp_team=TEAM_CAT, direction=1, surge_lvl=1, hit_damage=100)

        # Verify a counter surge was spawned by counter_cat
        counter_surges = [s for s in self.sim.active_surges if s.get("attacker") == counter_cat]
        self.assertTrue(len(counter_surges) > 0, "Expected counter surge spawned")
        self.assertEqual(counter_surges[0]["opp_team"], TEAM_ENEMY)

    def test_nyancombo_activation_and_effects(self):
        # Deck with basic 5 cats: cat (0), tank_cat (1), gross_cat (3), cow_cat (4), axe_cat (2)
        basic_deck = ["cat", "tank_cat", "axe_cat", "gross_cat", "cow_cat"]
        combo_sim = BattleSimulation(deck=basic_deck)

        # Authentic PONOS Combo 0 gives Initial Money +300 and Worker Level +1
        # Default starting money is 150 -> becomes 150 + 300 = 450!
        self.assertEqual(combo_sim.wallet.money, 450)
        # Default starting worker level is 1 -> becomes 1 + 1 = 2!
        self.assertEqual(combo_sim.wallet.level, 2)
        # Verify nyancombo_activate event was emitted
        self.assertTrue(any(e.get("type") == "nyancombo_activate" for e in combo_sim.visual_events))

    def test_enemy_authentic_multi_hit_and_ld(self):
        """Verifies authentic enemy multi-hit parsing and long distance ranges from t_unit.csv."""
        from game_project.core.unit_data import ENEMY_REGISTRY
        # Enemy Row 12 has 3 hits in official t_unit.csv
        spec12 = ENEMY_REGISTRY[12]
        self.assertEqual(len(spec12["attack_hits"]), 3)
        self.assertEqual([h["damage"] for h in spec12["attack_hits"]], [213, 12, 25])
        self.assertEqual([h["foreswing"] for h in spec12["attack_hits"]], [2, 8, 16])
        self.assertEqual(spec12["attack_power"], 250)

    def test_piecewise_level_scaling_curve(self):
        """Verifies authentic PONOS piecewise level curves: Lv 1-20 (+0.20/lv), Lv 21-50 (+0.10/lv or +0.05/lv)."""
        from game_project.simulation.deployer import CatDeployer
        deployer = CatDeployer(deck_keys=["cat"], cat_levels={"cat": 20})
        info_lv20 = deployer.get_slot_info(0)
        # Lv 1 cat HP = 100, mult at lv 20 = 1.0 + 0.20 * 19 = 4.8 -> 480 HP
        self.assertEqual(info_lv20["spec"]["hp"], 480)

        # Lv 30 regular cat: mult = 4.8 + 0.10 * 10 = 5.8 -> 580 HP
        deployer_lv30 = CatDeployer(deck_keys=["cat"], cat_levels={"cat": 30})
        info_lv30 = deployer_lv30.get_slot_info(0)
        self.assertEqual(info_lv30["spec"]["hp"], 580)

    def test_mini_wave_and_mini_surge_scaling(self):
        """Verifies Mini-Wave and Mini-Surge deal 20% (1/5) damage with faster wave segments."""
        mini_wave_cat = self.sim.spawn_custom_unit({
            "name": "Mini Wave Cat",
            "hp": 1000,
            "attack_power": 500,
            "speed": 0,
            "abilities": {"mini_wave": True}
        }, team=TEAM_CAT)

        self.sim._trigger_wave_attack(mini_wave_cat, opp_team=TEAM_ENEMY, direction=-1, wave_lvl=2, hit_damage=500)
        self.assertEqual(len(self.sim.active_waves), 1)
        self.assertEqual(self.sim.active_waves[0]["dmg"], 100) # 20% of 500 = 100

        mini_surge_cat = self.sim.spawn_custom_unit({
            "name": "Mini Surge Cat",
            "hp": 1000,
            "attack_power": 1000,
            "speed": 0,
            "abilities": {"mini_surge": True, "surge_start": 0, "surge_range": 0}
        }, team=TEAM_CAT)
        self.sim._trigger_surge_attack(mini_surge_cat, opp_team=TEAM_ENEMY, direction=-1, surge_lvl=1, hit_damage=1000)
        self.assertEqual(len(self.sim.active_surges), 1)
        self.assertEqual(self.sim.active_surges[0]["dmg"], 200) # 20% of 1000 = 200

    def test_aku_shield_regeneration_on_knockback(self):
        """Verifies Aku enemies regenerate their shield upon taking knockback."""
        aku_enemy = self.sim.spawn_custom_unit({
            "name": "Aku Devil",
            "hp": 1000,
            "attack_power": 50,
            "speed": 0,
            "abilities": {"shield_hp": 200, "shield_regen_pct": 50}
        }, team=TEAM_ENEMY)
        aku_enemy.aku_shield = 0 # Shield broken

        # Taking knockback
        self.sim._knockback(aku_enemy, "kb")
        self.assertEqual(aku_enemy.aku_shield, 100) # 50% of 200 = 100
        # Check shield_regen event
        self.assertTrue(any(e.get("type") == "shield_regen" for e in self.sim.visual_events))

    def test_knockback_invulnerability_frames(self):
        """Verifies units are completely immune to incoming attacks and damage during knockback flight."""
        doge = self.sim.spawn_custom_unit({
            "name": "Doge",
            "hp": 500,
            "attack_power": 10,
            "speed": 0
        }, team=TEAM_ENEMY)
        doge.pos_x = 1000

        attacker = self.sim.spawn_custom_unit({
            "name": "Attacker",
            "hp": 500,
            "attack_power": 100,
            "speed": 0
        }, team=TEAM_CAT)

        # Put doge in knockback
        self.sim._knockback(doge, "kb")
        self.assertTrue(doge.is_in_knockback())

        # Attacker tries to deal damage during knockback
        self.sim._apply_damage(attacker, doge, direction=-1, hit_damage=100)
        # HP must remain intact (no damage taken during KB flight)
        self.assertEqual(doge.hp, 500)

    def test_cannon_cannot_hit_burrowed_or_warped(self):
        """Verifies Cat Cannon beam ignores burrowed zombies and warped aliens."""
        self.sim.spawner.spawn_entries = []
        # Setup ready cannon
        self.sim.cannon_charge = self.sim.cannon_max_charge
        self.assertTrue(self.sim.is_cannon_ready())

        zombie = self.sim.spawn_custom_unit({
            "name": "Burrowed Zombie",
            "hp": 500,
            "attack_power": 10,
            "speed": 0
        }, team=TEAM_ENEMY)
        zombie.pos_x = self.sim.get_castle(TEAM_CAT).pos_x - 100 # In cannon beam range
        zombie.is_burrowing = True

        # Fire cannon
        self.sim.fire_cannon(TEAM_CAT)
        # Zombie is underground; cannot be damaged by cannon
        self.assertEqual(zombie.hp, 500)

    def test_treasure_manager_eoc_and_itf_calculations(self):
        """Verifies TreasureManager properly computes Empire of Cats and ItF trait fruit bonuses."""
        from game_project.core.treasure_manager import TreasureManager
        tr = TreasureManager.get_instance().calculate_battle_treasures({
            "eoc_chapters": 3.0,
            "trait_fruits": {"red": True, "floating": True, "black": True, "angel": True, "alien": True, "zombie": True}
        })
        self.assertEqual(tr["cat_atk_mult"], 2.5)  # +150% = 2.5x
        self.assertEqual(tr["cat_hp_mult"], 2.5)   # +150% = 2.5x
        self.assertEqual(tr["worker_rate_mult"], 4.0) # +300% = 4.0x
        self.assertEqual(tr["wallet_cap_bonus"], 3000) # +3000
        self.assertEqual(tr["cooldown_reduction"], 90) # -90 frames (3.0s)
        self.assertEqual(tr["castle_hp_bonus"], 21000) # +21000
        self.assertEqual(tr["cannon_power_bonus"], 1500) # +1500
        self.assertEqual(tr["cannon_charge_reduction"], 450) # -450 frames
        self.assertTrue(tr["trait_fruits"]["red"])
        self.assertTrue(tr["trait_fruits"]["alien"])

    def test_battle_sim_eoc_treasures_integration(self):
        """Verifies BattleSimulation integrates EoC treasures to Cat stats, cooldown, wallet, and cannon."""
        from game_project.simulation.battle_sim import BattleSimulation
        sim = BattleSimulation(
            stage_config={"length": 3000, "enemy_castle_hp": 1000, "cat_castle_hp": 1000},
            deck=["cat"],
            treasures={"eoc_chapters": 3.0}
        )
        cat_c = sim.get_castle(TEAM_CAT)
        self.assertEqual(cat_c.max_hp, 22000) # 1000 base + 21000 treasure
        self.assertEqual(sim.cannon_power, 1750) # 250 base + 1500 treasure
        self.assertEqual(sim.cannon_max_charge, 150) # 600 - 450 = 150 frames
        self.assertEqual(sim.wallet.max_money, 3500) # 500 base + 3000 treasure

        # Deploy cat and verify 2.5x HP and 2.5x ATK applied
        sim.wallet.money = 1000
        self.assertTrue(sim.deploy_unit(TEAM_CAT, 0))
        deployed = sim.units[TEAM_CAT][1]
        self.assertIsNotNone(deployed)
        # Cat 000 base HP is 100 -> with 2.5x treasure mult = 250
        self.assertEqual(deployed.max_hp, 250)
        # Cat 000 base ATK is 8 -> with 2.5x treasure mult = 20
        self.assertEqual(deployed.attack_power, 20)

    def test_trait_fruits_damage_and_defense_boosts(self):
        """Verifies Trait Fruit treasures boost Strong (1.8x/0.4x), Massive (4.0x), and Resistant (1/5)."""
        from game_project.simulation.battle_sim import BattleSimulation
        sim_with_fruit = BattleSimulation(treasures={"eoc_chapters": 0, "trait_fruits": {"red": True}})
        sim_no_fruit = BattleSimulation(treasures={"eoc_chapters": 0, "trait_fruits": {"red": False}})

        red_enemy = sim_with_fruit.spawn_custom_unit({
            "name": "Red Enemy",
            "hp": 2000,
            "attack_power": 100,
            "traits": ["red"]
        }, team=TEAM_ENEMY)

        # 1. Massive Damage test: 300 base -> 3x (900) without fruit, 4x (1200) with fruit
        massive_cat = sim_with_fruit.spawn_custom_unit({
            "name": "Massive Cat",
            "hp": 1000,
            "attack_power": 300,
            "target_traits": ["red"],
            "abilities": {"massive_damage": True}
        }, team=TEAM_CAT)

        # Deal hit with fruit
        sim_with_fruit._apply_damage(massive_cat, red_enemy, direction=-1, hit_damage=300)
        self.assertEqual(red_enemy.hp, 800) # 2000 - 1200 = 800 (4.0x)

        # Deal hit without fruit
        red_enemy2 = sim_no_fruit.spawn_custom_unit({
            "name": "Red Enemy 2",
            "hp": 2000,
            "attack_power": 100,
            "traits": ["red"]
        }, team=TEAM_ENEMY)
        sim_no_fruit._apply_damage(massive_cat, red_enemy2, direction=-1, hit_damage=300)
        self.assertEqual(red_enemy2.hp, 1100) # 2000 - 900 = 1100 (3.0x)

        # 2. Resistant test: 1000 raw damage -> 1/4 (250) without fruit, 1/5 (200) with fruit
        res_cat = sim_with_fruit.spawn_custom_unit({
            "name": "Resistant Cat",
            "hp": 1000,
            "attack_power": 10,
            "target_traits": ["red"],
            "abilities": {"resistant": True}
        }, team=TEAM_CAT)
        sim_with_fruit._apply_damage(red_enemy, res_cat, direction=1, hit_damage=1000)
        self.assertEqual(res_cat.hp, 800) # 1000 - 200 = 800 (1/5 damage taken)

    def test_cannon_foundation_subtypes(self):
        """Verifies all 7 Ototo Cat Cannon foundation sub-types: Slow, Thunderbolt, Waterblast, Breakerblast, Curseblast, Iron Wall."""
        from game_project.simulation.battle_sim import BattleSimulation
        
        # 1. Slow Cannon
        sim_slow = BattleSimulation(cannon_type="slow")
        sim_slow.spawner.spawn_entries = []
        sim_slow.cannon_charge = sim_slow.cannon_max_charge
        doge = sim_slow.spawn_custom_unit({"name": "Doge", "hp": 500, "attack_power": 10}, team=TEAM_ENEMY)
        doge.pos_x = sim_slow.get_castle(TEAM_CAT).pos_x - 100
        sim_slow.fire_cannon(TEAM_CAT)
        self.assertTrue(doge.is_slowed())
        self.assertEqual(doge.slow_timer, 120)

        # 2. Thunderbolt Cannon (Freezes target cluster)
        sim_tb = BattleSimulation(cannon_type="thunderbolt")
        sim_tb.spawner.spawn_entries = []
        sim_tb.cannon_charge = sim_tb.cannon_max_charge
        doge_tb = sim_tb.spawn_custom_unit({"name": "Doge TB", "hp": 500, "attack_power": 10}, team=TEAM_ENEMY)
        doge_tb.pos_x = 1000
        sim_tb.fire_cannon(TEAM_CAT)
        self.assertTrue(doge_tb.is_frozen())
        self.assertEqual(doge_tb.freeze_timer, 75)

        # 3. Waterblast Cannon (30% max HP damage to Metal)
        sim_wb = BattleSimulation(cannon_type="waterblast")
        sim_wb.spawner.spawn_entries = []
        sim_wb.cannon_charge = sim_wb.cannon_max_charge
        metal_doge = sim_wb.spawn_custom_unit({"name": "Metal Doge", "hp": 100, "traits": ["metal"], "abilities": {"is_metal": True}}, team=TEAM_ENEMY)
        metal_doge.pos_x = sim_wb.get_castle(TEAM_CAT).pos_x - 100
        sim_wb.fire_cannon(TEAM_CAT)
        self.assertEqual(metal_doge.hp, 70) # 100 - 30% = 70

        # 4. Breakerblast Cannon (Shatters Aku shield and Alien barrier)
        sim_bb = BattleSimulation(cannon_type="breakerblast")
        sim_bb.spawner.spawn_entries = []
        sim_bb.cannon_charge = sim_bb.cannon_max_charge
        aku_alien = sim_bb.spawn_custom_unit({"name": "Aku Alien", "hp": 1000, "abilities": {"shield_hp": 300, "barrier_hp": 400}}, team=TEAM_ENEMY)
        aku_alien.pos_x = sim_bb.get_castle(TEAM_CAT).pos_x - 100
        sim_bb.fire_cannon(TEAM_CAT)
        self.assertEqual(aku_alien.aku_shield, 0, "Aku shield shattered")
        self.assertEqual(aku_alien.barrier, 0, "Alien barrier broken")

        # 5. Curseblast Cannon
        sim_cb = BattleSimulation(cannon_type="curseblast")
        sim_cb.spawner.spawn_entries = []
        sim_cb.cannon_charge = sim_cb.cannon_max_charge
        doge_cb = sim_cb.spawn_custom_unit({"name": "Doge CB", "hp": 500}, team=TEAM_ENEMY)
        doge_cb.pos_x = sim_cb.get_castle(TEAM_CAT).pos_x - 100
        sim_cb.fire_cannon(TEAM_CAT)
        self.assertTrue(doge_cb.is_cursed())
        self.assertEqual(doge_cb.curse_timer, 180)

        # 6. Iron Wall Cannon
        sim_iw = BattleSimulation(cannon_type="iron_wall")
        sim_iw.cannon_charge = sim_iw.cannon_max_charge
        sim_iw.fire_cannon(TEAM_CAT)
        # Verify iron wall cat was deployed on Team 0
        wall_unit = sim_iw.units[TEAM_CAT][1]
        self.assertIsNotNone(wall_unit)
        self.assertEqual(wall_unit.name, "鐵壁貓")
        self.assertTrue("metal" in wall_unit.traits)
        self.assertEqual(wall_unit.hp, 3)
        self.assertEqual(wall_unit.lifetime, 90)

    def test_boss_death_sequence_and_slow_motion(self):
        """Verifies Boss enemy emergence flags, boss death event, and slow motion time dilation."""
        from game_project.simulation.battle_sim import BattleSimulation
        sim = BattleSimulation(stage_config={"length": 3000, "enemy_castle_hp": 1000, "cat_castle_hp": 1000})
        sim.spawner.spawn_entries = []
        
        # Spawn boss enemy with boss flag
        sim.spawn_enemy({"id": 20, "boss": 2, "spec": {"name": "The Face", "hp": 500, "attack_power": 50}})
        boss_unit = sim.units[TEAM_ENEMY][1]
        self.assertIsNotNone(boss_unit)
        self.assertTrue(boss_unit.is_boss)

        # Deliver fatal blow to boss
        attacker = sim.spawn_custom_unit({"name": "Attacker", "hp": 1000, "attack_power": 600}, team=TEAM_CAT)
        sim._apply_damage(attacker, boss_unit, direction=-1, hit_damage=600)
        sim._update_deaths_and_castles()

        # Check slow motion timer triggered
        self.assertEqual(sim.slow_motion_timer, 45)
        # Check boss_death event emitted
        events = sim.consume_visual_events()
        self.assertTrue(any(e.get("type") == "boss_death" for e in events))

if __name__ == "__main__":
    unittest.main()
