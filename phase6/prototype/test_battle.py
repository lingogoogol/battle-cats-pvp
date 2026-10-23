"""
Unit Tests for Battle Cats Clean-Room Battle Simulator Prototype
Includes tests for Movement, Target Selection, Attack Cycles, Knockback (KB), and Win/Loss.
"""

import unittest
from battle_engine import BattleStage, Unit, Team, UnitState

def make_basic_cat(pos=0.0, kb_count=3):
    # Standard Cat (Basic Cat / 貓咪):
    # HP=100, Damage=20, Range=140, Speed=10, Attack Interval=30 ticks, Pre-attack Delay=8 ticks, KB=3
    return Unit(
        name="Cat",
        team=Team.FRIENDLY,
        hp=100,
        attack_power=20,
        range_=140.0,
        speed=10.0,
        attack_interval=30,
        pre_attack_delay=8,
        position=pos,
        kb_count=kb_count,
        kb_distance=60.0,
        kb_duration=10
    )

def make_doge(pos=2000.0, kb_count=3):
    # Standard Doge (賈修 / 柴犬):
    # HP=90, Damage=15, Range=100, Speed=8, Attack Interval=30 ticks, Pre-attack Delay=6 ticks, KB=3
    return Unit(
        name="Doge",
        team=Team.ENEMY,
        hp=90,
        attack_power=15,
        range_=100.0,
        speed=8.0,
        attack_interval=30,
        pre_attack_delay=6,
        position=pos,
        kb_count=kb_count,
        kb_distance=50.0,
        kb_duration=10
    )

class TestBattleEngine(unittest.TestCase):

    def setUp(self):
        self.stage = BattleStage(width=1000.0, base_hp=500)

    def test_stage_initialization(self):
        self.assertEqual(self.stage.friendly_base.position, 0.0)
        self.assertEqual(self.stage.enemy_base.position, 1000.0)
        self.assertEqual(self.stage.friendly_base.hp, 500)
        self.assertEqual(self.stage.enemy_base.hp, 500)
        self.assertFalse(self.stage.is_game_over())

    def test_movement(self):
        cat = make_basic_cat(0.0)
        self.stage.spawn_friendly(cat, position=0.0)
        
        # Step 5 ticks
        for _ in range(5):
            self.stage.step()
            
        # Cat moves 10 units per tick -> 5 * 10 = 50.0
        self.assertEqual(cat.position, 50.0)
        self.assertEqual(cat.state, UnitState.MOVING)

    def test_range_detection_and_attack_transition(self):
        cat = make_basic_cat(pos=400.0)
        doge = make_doge(pos=520.0)  # Distance = 120
        
        self.stage.spawn_friendly(cat, position=400.0)
        self.stage.spawn_enemy(doge, position=520.0)
        
        # 1 step:
        # Distance is 120. Cat range is 140 -> Cat enters ATTACKING.
        # Doge range is 100 -> Doge is out of range, continues MOVING.
        self.stage.step()
        self.assertEqual(cat.state, UnitState.ATTACKING)
        self.assertEqual(doge.state, UnitState.MOVING)

    def test_damage_and_hp_subtraction(self):
        cat = make_basic_cat(pos=400.0)
        doge = make_doge(pos=480.0)  # Distance = 80, in range for both
        
        self.stage.spawn_friendly(cat, position=400.0)
        self.stage.spawn_enemy(doge, position=480.0)
        
        initial_doge_hp = doge.hp
        
        # Pre-attack delay is 8 ticks for cat.
        # At tick 9, damage connects.
        for _ in range(12):
            self.stage.step()
            
        # Cat damage (20) applied to Doge (90 -> 70)
        self.assertEqual(doge.hp, initial_doge_hp - 20)

    def test_knockback_trigger_and_interruption(self):
        # Test unit knockback threshold: Cat HP=100, KB=3 -> Threshold = 100/3 = 33.33
        # When HP drops from 100 to <= 66.66, triggers KB 1.
        cat = make_basic_cat(pos=300.0, kb_count=3)
        self.stage.spawn_friendly(cat, position=300.0)
        
        # Force cat into ATTACKING state
        cat.state = UnitState.ATTACKING
        cat.state_timer = 5 # 5 of 8 windup ticks elapsed
        
        # Apply 40 damage (HP becomes 60 <= 66.66 threshold)
        cat.take_damage(40)
        
        # Cat should be in KNOCKBACK state, and attack windup should be aborted
        self.assertEqual(cat.state, UnitState.KNOCKBACK)
        self.assertEqual(cat.state_timer, 0)
        self.assertFalse(cat.damage_dealt_this_cycle)
        
        # Step through knockback (10 ticks)
        initial_pos = cat.position
        for _ in range(10):
            self.stage.step()
            
        # Cat should be pushed backwards towards 0 (left)
        self.assertLess(cat.position, initial_pos)
        # After 10 ticks, should return to MOVING
        self.assertEqual(cat.state, UnitState.MOVING)

    def test_unit_death_and_cleanup(self):
        cat = make_basic_cat(pos=400.0)
        doge = make_doge(pos=450.0)
        doge.hp = 10  # low HP so 1 hit kills
        
        self.stage.spawn_friendly(cat, position=400.0)
        self.stage.spawn_enemy(doge, position=450.0)
        
        # Step past damage and attack animation duration (30 ticks)
        for _ in range(35):
            self.stage.step()
            
        # Doge should be dead and removed from active enemy list
        self.assertEqual(len(self.stage.enemy_units), 0)
        self.assertEqual(cat.state, UnitState.MOVING)  # Cat finishes swing and resumes moving

    def test_victory_condition(self):
        cat = make_basic_cat(pos=900.0)  # Close to enemy base at 1000.0
        self.stage.spawn_friendly(cat, position=900.0)
        self.stage.enemy_base.hp = 20    # 1 hit from cat will destroy it
        
        # Cat range is 140, distance is 100 -> in range!
        # Step until cat deals damage (8-12 ticks)
        for _ in range(15):
            self.stage.step()
            
        self.assertTrue(self.stage.is_victory())
        self.assertTrue(self.stage.is_game_over())
        self.assertFalse(self.stage.is_defeat())

    def test_defeat_condition(self):
        doge = make_doge(pos=50.0)       # Close to friendly base at 0.0
        self.stage.spawn_enemy(doge, position=50.0)
        self.stage.friendly_base.hp = 10 # 1 hit from doge will destroy it
        
        for _ in range(15):
            self.stage.step()
            
        self.assertTrue(self.stage.is_defeat())
        self.assertTrue(self.stage.is_game_over())
        self.assertFalse(self.stage.is_victory())

    def test_full_simulation_run(self):
        cat = make_basic_cat(0.0)
        doge = make_doge(500.0)
        self.stage.spawn_friendly(cat, position=0.0)
        self.stage.spawn_enemy(doge, position=500.0)
        
        max_ticks = 500
        while not self.stage.is_game_over() and self.stage.ticks < max_ticks:
            self.stage.step()
            
        self.assertGreater(self.stage.ticks, 20)
        # Verify that either a unit took damage or base took damage
        self.assertTrue(cat.hp < cat.max_hp or doge.hp < doge.max_hp)


if __name__ == '__main__':
    unittest.main()
