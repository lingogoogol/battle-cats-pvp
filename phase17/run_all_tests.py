"""
Master Test Suite Runner.
Executes all regression tests across Phase 12-17 and reports consolidated metrics.
"""

import os
import sys
import time
import subprocess

TEST_FILES = [
    r"E:\rea\game_project\test_playable.py",
    r"E:\rea\phase14\test_phase14_mechanics.py",
    r"E:\rea\phase14\native_differential_suite.py",
    r"E:\rea\phase15\test_phase15_data_loader.py",
    r"E:\rea\phase16\test_phase16_ui_lifecycle.py",
    r"E:\rea\phase12\native_chain\multi_function_differential_test.py"
]

def run_suite():
    print("=" * 70)
    print("        THE BATTLE CATS REBUILT: FULL AUTOMATED REGRESSION SUITE       ")
    print("=" * 70)

    all_passed = True
    total_start = time.perf_counter()

    for tf in TEST_FILES:
        name = os.path.basename(tf)
        t0 = time.perf_counter()
        res = subprocess.run([sys.executable, tf], capture_output=True, text=True)
        dt = time.perf_counter() - t0
        passed = (res.returncode == 0)
        status = "PASS" if passed else "FAIL"
        if not passed:
            all_passed = False
        print(f"[{status:4}] {name:40} ({dt:.3f}s)")
        if not passed:
            print("  --- STDERR ---")
            print(res.stderr[:400])

    total_dt = time.perf_counter() - total_start
    print("=" * 70)
    verdict = "ALL 6 SUITES PASSED (0 FAILURES)" if all_passed else "FAILURES DETECTED"
    print(f"Overall Verdict: {verdict} in {total_dt:.3f}s")
    print("=" * 70)
    return all_passed

if __name__ == "__main__":
    success = run_suite()
    sys.exit(0 if success else 1)
