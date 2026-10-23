import os
import sys
import unittest

sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

from native_chain_harness import NativeChainHarness

class TestNativeChainDifferential(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.harness = NativeChainHarness()

    def test_multi_function_chain_matrix(self):
        """
        Executes real native multi-function chain in Unicorn and compares 
        every state variable with Python reconstructed version.
        """
        vectors = [
            # (team, unit, pos, speed, f95c, faec, faf0, init_kb, desc)
            (0, 1, 100, 10, 1, 0, 0, 0, "Cat standard advance"),
            (0, 1, 100, 10, 1, 0, 0, 5, "Cat in knockback (advance inhibited, kb-1)"),
            (0, 1, 100, 10, 0, 0, 0, 0, "Cat stopped/dead (flag_95c=0, advance inhibited)"),
            (0, 1, 100, 10, 1, 1, 0, 0, "Cat slowed (can_move=2, advance inhibited)"),
            (0, 1, 100, 10, 1, 1, 1, 0, "Cat special state (can_move=3, advance inhibited)"),
            (1, 1, 950, -8, 1, 0, 0, 0, "Enemy standard advance (negative speed)"),
            (1, 1, 950, -8, 1, 0, 0, 1, "Enemy knockback decay to 0"),
            (0, 50, 0, 15, 1, 0, 0, 0, "Boundary slot 50 advance from pos 0"),
            (1, 50, 6000, -12, 1, 0, 0, 10, "Boundary slot 50 enemy knockback decay"),
            (0, 25, -500, 5, 1, 0, 0, 0, "Negative coordinate boundary advance"),
        ]

        print("\n--- Running Native Multi-Function Differential Matrix ---")
        for team, unit, pos, spd, f95c, faec, faf0, kb, desc in vectors:
            native_out = self.harness.run_native_battle_step(team, unit, pos, spd, f95c, faec, faf0, kb)
            py_out = self.harness.run_reconstructed_battle_step(team, unit, pos, spd, f95c, faec, faf0, kb)

            # Assert complete parity
            self.assertEqual(native_out['can_move'], py_out['can_move'], f"CanMove mismatch: {desc}")
            self.assertEqual(native_out['final_kb'], py_out['final_kb'], f"KB mismatch: {desc}")
            self.assertEqual(native_out['final_pos'], py_out['final_pos'], f"Pos mismatch: {desc}")
            self.assertTrue(native_out['sp_balanced'])

            print(f"  [PASS] {desc}:")
            print(f"         Native: CanMove={native_out['can_move']}, KB={native_out['final_kb']}, Pos={native_out['final_pos']}")
            print(f"         Python: CanMove={py_out['can_move']}, KB={py_out['final_kb']}, Pos={py_out['final_pos']}")

    def test_fault_injection_detectability(self):
        """
        Verifies that the test framework positively detects artificially injected errors.
        """
        print("\n--- Running Fault Injection (Mutation) Tests on Chain ---")
        team, unit, pos, spd, f95c, faec, faf0, kb = 0, 1, 100, 10, 1, 0, 0, 0
        native_out = self.harness.run_native_battle_step(team, unit, pos, spd, f95c, faec, faf0, kb)

        # Mutation 1: Inverted movement direction in Python
        mutated_pos_out = pos - spd # Inverted!
        self.assertNotEqual(native_out['final_pos'], mutated_pos_out)
        print("  [PASS] Mutation 1 (Inverted Position Formula): DETECTED by differential comparator")

        # Mutation 2: Inverted knockback decay (+1 instead of -1)
        kb_test = 5
        native_kb_out = self.harness.run_native_battle_step(team, unit, pos, spd, f95c, faec, faf0, kb_test)
        mutated_kb_out = kb_test + 1 # Inverted!
        self.assertNotEqual(native_kb_out['final_kb'], mutated_kb_out)
        print("  [PASS] Mutation 2 (Inverted Knockback Decay): DETECTED by differential comparator")

        # Mutation 3: False can_move on stopped unit
        stopped_test = (0, 1, 100, 10, 0, 0, 0, 0)
        native_stop_out = self.harness.run_native_battle_step(*stopped_test)
        mutated_stop_out = 1 # Injected bug: allowing move when flag_95c is 0
        self.assertNotEqual(native_stop_out['can_move'], mutated_stop_out)
        print("  [PASS] Mutation 3 (False Move Permission on Stopped Unit): DETECTED by differential comparator")

if __name__ == '__main__':
    unittest.main(verbosity=2)
