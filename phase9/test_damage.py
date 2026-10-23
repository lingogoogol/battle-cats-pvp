"""
Comprehensive Test Suite for Phase 9 Native Combat Damage Engine
Tests normal, boundary, and extreme inputs against reverse-engineered AArch64 binary logic.
"""

import unittest
from combat_core import BattlefieldMemory, NativeDamageEngine, NativeUnitField

class TestNativeDamageEngine(unittest.TestCase):

    def setUp(self):
        self.bf = BattlefieldMemory()
        self.engine = NativeDamageEngine()
        
        # Setup test unit: Team 1 (Enemy), Unit 0, HP = 100, Alive = True
        self.bf.set_unit_hp(team=1, unit_index=0, hp=100)
        self.bf.set_unit_alive(team=1, unit_index=0, alive=True)
        self.bf.set_unit_position(team=1, unit_index=0, pos=500)

    def test_magic_division_permille_parity(self):
        """Verifies ARM64 compiler division by 1000 magic constant 0x10624dd3 >> 38."""
        test_cases = [
            (100, 1000, 100),
            (250, 1000, 250),
            (100, 1500, 150),
            (200, 3000, 600),    # Massive damage (3.0x)
            (400, 250, 100),     # Resistant (0.25x)
            (999, 1000, 999),
            (1, 1000, 1),
            (0, 1000, 0),
            (100, 0, 0),
            (12345, 1234, 15233) # 12345 * 1234 // 1000 = 15233.73 -> 15233
        ]
        for base, permille, expected in test_cases:
            scaled = self.engine.calculate_permille_scaling(base, permille)
            self.assertEqual(scaled, expected, f"Failed for {base} * {permille} / 1000")

    def test_normal_damage_application(self):
        """Tests standard damage application and memory writeback (0x004c6414 - 0x004c659c)."""
        res = self.engine.apply_damage_to_unit(
            battlefield=self.bf,
            target_team=1,
            target_unit=0,
            base_damage=35,
            multiplier_permille=1000
        )
        self.assertEqual(res.initial_hp, 100)
        self.assertEqual(res.scaled_damage, 35)
        self.assertEqual(res.remaining_hp, 65)
        self.assertFalse(res.is_killed)
        self.assertFalse(res.is_knockback_triggered)
        # Verify direct memory read
        self.assertEqual(self.bf.get_unit_hp(1, 0), 65)
        self.assertTrue(self.bf.is_unit_alive(1, 0))

    def test_death_and_cleanup_trigger(self):
        """Tests unit death when HP reaches 0 and Battle_KillUnit clean-up (0x008b6f50)."""
        res = self.engine.apply_damage_to_unit(
            battlefield=self.bf,
            target_team=1,
            target_unit=0,
            base_damage=120, # Overkill
            multiplier_permille=1000
        )
        self.assertEqual(res.remaining_hp, 0)
        self.assertTrue(res.is_killed)
        # Verify that Battle_KillUnit zeroed out all 3 fields:
        self.assertEqual(self.bf.get_unit_hp(1, 0), 0)
        self.assertFalse(self.bf.is_unit_alive(1, 0))
        self.assertEqual(self.bf.get_attack_timer(1, 0), 0)

    def test_exact_hp_depletion_boundary(self):
        """Tests boundary when incoming damage exactly equals current HP."""
        res = self.engine.apply_damage_to_unit(
            battlefield=self.bf,
            target_team=1,
            target_unit=0,
            base_damage=100,
            multiplier_permille=1000
        )
        self.assertEqual(res.remaining_hp, 0)
        self.assertTrue(res.is_killed)
        self.assertFalse(self.bf.is_unit_alive(1, 0))

    def test_knockback_threshold_trigger(self):
        """Tests knockback state setter when damage exceeds threshold (0x00959ca8)."""
        res = self.engine.apply_damage_to_unit(
            battlefield=self.bf,
            target_team=1,
            target_unit=0,
            base_damage=40,
            multiplier_permille=1000,
            kb_threshold=33
        )
        self.assertEqual(res.remaining_hp, 60)
        self.assertTrue(res.is_knockback_triggered)
        self.assertEqual(self.bf.get_knockback(1, 0), 1)

    def test_barrier_absorption_and_break(self):
        """Tests barrier defense immunity check (0x0095ac18)."""
        # Set 500 barrier
        self.bf._write_field(1, 0, NativeUnitField.STATUS_BARRIER, 500)
        
        # 1. Damage less than barrier (300 < 500) -> absorbed
        res1 = self.engine.apply_damage_to_unit(self.bf, 1, 0, base_damage=300)
        self.assertTrue(res1.is_immune)
        self.assertEqual(res1.scaled_damage, 0)
        self.assertEqual(self.bf.get_unit_hp(1, 0), 100) # Unchanged
        
        # 2. Damage exceeding barrier (600 >= 500) -> breaks barrier and damages unit
        res2 = self.engine.apply_damage_to_unit(self.bf, 1, 0, base_damage=600)
        self.assertFalse(res2.is_immune)
        self.assertTrue(res2.is_killed)
        self.assertEqual(self.bf._read_field(1, 0, NativeUnitField.STATUS_BARRIER), 0)

    def test_attack_on_dead_unit_ignored(self):
        """Tests that damage is ignored on dead / non-spawned units."""
        self.bf.set_unit_alive(1, 0, False)
        res = self.engine.apply_damage_to_unit(self.bf, 1, 0, base_damage=50)
        self.assertTrue(res.is_immune)
        self.assertEqual(res.scaled_damage, 0)

if __name__ == '__main__':
    unittest.main()
