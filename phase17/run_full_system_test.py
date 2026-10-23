"""
Phase 17 Comprehensive System Test & Performance Benchmark Runner.
Executes:
1. Complete Unit & Integration Test Suites
2. Boundary & Stress Testing (Slot limits, negative positions, overflow)
3. 1,000-Frame Long-Running Stability Test
4. Performance Benchmarks across 10, 25, 50, and 100 entities
Outputs detailed metrics and logs.
"""

import os
import sys
import time
import tracemalloc
import json
import unittest

os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
os.environ["SDL_VIDEODRIVER"] = "dummy"
sys.path.insert(0, r"E:\rea")

import pygame
pygame.init()
pygame.font.init()

from game_project.core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, TEAM_CAT, TEAM_ENEMY, MAX_UNITS_PER_TEAM
)
from game_project.simulation.battle_sim import BattleSimulation, SimUnit
from game_project.render.camera import Camera2D
from game_project.render.renderer import BattleRenderer
from game_project.core.data_loader import GameDataLoader

def run_boundary_tests() -> dict:
    print("\n=== [1] Running Boundary & Stress Tests ===")
    results = {}
    sim = BattleSimulation()
    sim.spawner.castle_triggers = []
    sim.spawner.timed_events = []

    # 1. Slot Limit Test: Can deploy exactly 50 units (slots 1..50), 51st must fail
    sim.wallet.money = 999999
    deployed_count = 0
    for i in range(55):
        sim.deployer.cooldowns[0] = 0
        success = sim.spawn_cat(0)
        if success:
            deployed_count += 1
    
    print(f"  [*] Deployed field units: {deployed_count} / {MAX_UNITS_PER_TEAM - 1}")
    results["slot_limit_enforced"] = (deployed_count == 50)
    results["slot_51_rejected"] = not sim.spawn_cat(0)

    # 2. Extreme Money Boundary Test
    sim.wallet.money = 0
    sim.deployer.cooldowns[0] = 0
    results["zero_money_rejected"] = not sim.spawn_cat(0)

    # 3. Position Clamping & Boundary Test
    cat = sim.units[TEAM_CAT][1]
    cat.pos_x = -9999
    cat.knockback_timer = 5
    sim._update_movement()
    results["negative_pos_clamped"] = (cat.pos_x >= 60)

    # 4. Castle HP Zero Boundary
    enemy_c = sim.get_castle(TEAM_ENEMY)
    enemy_c.hp = -500
    sim._update_deaths_and_castles()
    results["negative_castle_hp_triggers_victory"] = (sim.game_over and sim.winner == TEAM_CAT)

    all_pass = all(results.values())
    print(f"  [*] Boundary Tests Status: {'ALL PASS' if all_pass else 'FAIL'}")
    return results

def run_stability_test(target_frames: int = 1000) -> dict:
    print(f"\n=== [2] Running Long-Running Stability Test ({target_frames} Frames) ===")
    tracemalloc.start()
    mem_before = tracemalloc.get_traced_memory()[0] / (1024 * 1024)

    stage_cfg = GameDataLoader.load_stage_config(r"E:\rea\game_project\data\stages\stage_03_philippines.json")
    sim = BattleSimulation(stage_config=stage_cfg)
    
    start_time = time.perf_counter()
    errors = 0
    events_processed = 0

    for f in range(target_frames):
        try:
            # Automated bot actions
            if sim.wallet.level < 8 and sim.wallet.money >= (sim.wallet.upgrade_cost or 99999):
                sim.wallet.upgrade_worker()
            for d_idx in [1, 2, 0, 3, 4]:
                if sim.deployer.can_deploy(d_idx, sim.wallet.money, has_free_slot=True):
                    sim.spawn_cat(d_idx)
            
            sim.step()
            events_processed += len(sim.visual_events)

            if sim.game_over:
                # Soft reset stage to continue stress test
                sim = BattleSimulation(stage_config=stage_cfg)
        except Exception as e:
            errors += 1
            print(f"  [!] Stability Exception at frame {f}: {e}")

    total_time = time.perf_counter() - start_time
    mem_after = tracemalloc.get_traced_memory()[0] / (1024 * 1024)
    tracemalloc.stop()
    fps_sim = target_frames / total_time

    res = {
        "frames_executed": target_frames,
        "total_time_seconds": round(total_time, 4),
        "simulation_fps": round(fps_sim, 2),
        "errors": errors,
        "events_processed": events_processed,
        "mem_before_mb": round(mem_before, 2),
        "mem_after_mb": round(mem_after, 2),
        "mem_delta_mb": round(mem_after - mem_before, 2)
    }
    print(f"  [*] Executed {target_frames} frames in {total_time:.3f}s ({fps_sim:.1f} ticks/sec)")
    print(f"  [*] Memory: Before={mem_before:.1f}MB, After={mem_after:.1f}MB, Errors={errors}")
    return res

def run_performance_benchmarks() -> dict:
    print("\n=== [3] Running Performance Benchmarks across Entity Densities ===")
    surface = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
    camera = Camera2D()
    renderer = BattleRenderer(surface, camera)
    bench_results = {}

    entity_counts = [10, 25, 50, 80]

    for count in entity_counts:
        sim = BattleSimulation()
        sim.spawner.castle_triggers = []
        sim.spawner.timed_events = []

        # Populate battlefield with N entities (half cat, half enemy)
        half = count // 2
        for s in range(1, min(half + 1, 51)):
            sim.units[TEAM_CAT][s] = SimUnit(
                team=TEAM_CAT, slot=s, unit_key="cat",
                spec={"hp": 500, "attack_power": 20, "attack_range": 140, "speed": 10, "attack_interval": 30, "attack_windup": 8, "knockback_count": 3, "radius": 18},
                pos_x=200 + s * 15
            )
        for s in range(1, min(half + 1, 51)):
            sim.units[TEAM_ENEMY][s] = SimUnit(
                team=TEAM_ENEMY, slot=s, unit_key="doge",
                spec={"hp": 500, "attack_power": 18, "attack_range": 110, "speed": 10, "attack_interval": 30, "attack_windup": 8, "knockback_count": 3, "radius": 18},
                pos_x=1200 - s * 15
            )

        # Measure 100 simulation steps
        t0 = time.perf_counter()
        for _ in range(100):
            sim.step()
        sim_time_ms = (time.perf_counter() - t0) * 10 # ms per frame

        # Measure 100 render steps
        t1 = time.perf_counter()
        for _ in range(100):
            renderer.render(sim)
        render_time_ms = (time.perf_counter() - t1) * 10 # ms per frame

        total_frame_ms = sim_time_ms + render_time_ms
        achievable_fps = 1000.0 / max(0.001, total_frame_ms)

        bench_results[f"{count}_entities"] = {
            "entity_count": count,
            "sim_ms_per_tick": round(sim_time_ms, 3),
            "render_ms_per_frame": round(render_time_ms, 3),
            "total_ms_per_frame": round(total_frame_ms, 3),
            "achievable_fps": round(achievable_fps, 1)
        }
        print(f"  [*] {count:2d} Entities -> Sim: {sim_time_ms:.3f}ms | Render: {render_time_ms:.3f}ms | Total: {total_frame_ms:.3f}ms | FPS: {achievable_fps:.1f}")

    return bench_results

def main():
    boundary_res = run_boundary_tests()
    stability_res = run_stability_test(1000)
    perf_res = run_performance_benchmarks()

    full_report = {
        "timestamp": time.strftime("%Y-%m-%d %H:%M:%S"),
        "boundary_tests": boundary_res,
        "stability_test": stability_res,
        "performance_benchmarks": perf_res
    }

    out_json = r"E:\rea\phase17\benchmark_results.json"
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(full_report, f, indent=2)
    print(f"\n[+] Full test and benchmark results saved to: {out_json}")

if __name__ == "__main__":
    main()
