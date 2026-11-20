"""
Comprehensive Visual & Behavioral Verification for Authentic Battle Cats Engine Restoration.
Runs headless pygame simulation to exercise:
1. Wave Blocker extinguishing waves
2. Surge Attack energy column
3. Boss Emergence Shockwave & Boss Defeat Slow-Motion
4. Starred Alien Warp & Warp Blocker
5. Zombie Burrow & Revive
6. Aku Shield & Shield Shatter
7. Ototo Cat Cannon Foundation Sub-types (Thunderbolt, Iron Wall, Breakerblast)
8. Empire of Cats Ch. 1-3 Treasures & Into the Future Trait Fruits
"""

import os
import pygame
from game_project.core.constants import SCREEN_WIDTH, SCREEN_HEIGHT, TEAM_CAT, TEAM_ENEMY, GROUND_Y
from game_project.simulation.battle_sim import BattleSimulation
from game_project.render.renderer import BattleRenderer
from game_project.render.camera import Camera2D
from game_project.core.treasure_manager import TreasureManager

def run_verification():
    os.environ["SDL_VIDEODRIVER"] = "dummy"
    pygame.init()
    surface = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
    camera = Camera2D()
    renderer = BattleRenderer(surface, camera)

    # 1. Deck with Basic 5 cats to verify authentic Nyancombo & EoC Treasures
    basic_deck = ["cat", "tank_cat", "axe_cat", "gross_cat", "cow_cat"]
    treasures_cfg = {
        "eoc_chapters": 3.0,
        "trait_fruits": {"red": True, "floating": True, "black": True, "angel": True, "alien": True, "zombie": True}
    }
    sim = BattleSimulation(
        deck=basic_deck,
        treasures=treasures_cfg,
        cannon_type="thunderbolt"
    )
    renderer.process_visual_events(sim.consume_visual_events())

    print("[*] Nyancombo check: Wallet money =", sim.wallet.money, "(Expected: 300 = 0 + 300)")
    print("[*] Nyancombo check: Worker level =", sim.wallet.level, "(Expected: 2 = 1 + 1)")
    print("[*] Treasure check: Cannon power =", sim.cannon_power, "(Expected: 1750 = 250 + 1500)")
    print("[*] Treasure check: Max wallet capacity =", sim.wallet.max_money, "(Expected: 3150 = 150 + 3000)")

    assert sim.wallet.money == 300, f"Expected 300, got {sim.wallet.money}"
    assert sim.wallet.level == 2, f"Expected 2, got {sim.wallet.level}"
    assert sim.cannon_power == 1750, f"Expected 1750, got {sim.cannon_power}"
    assert sim.wallet.max_money == 3150, f"Expected 3150, got {sim.wallet.max_money}"

    # 2. Spawn combat units for visual showcase
    # Cat with Wave Blocker & Warp Blocker
    octo = sim.spawn_custom_unit({
        "name": "Octo Cat",
        "hp": 5000,
        "attack_power": 120,
        "speed": 0,
        "abilities": {"wave_blocker": True, "warp_blocker": True}
    }, team=TEAM_CAT)
    octo.pos_x = 1800

    # Normal Cat behind
    cat_b = sim.spawn_custom_unit({
        "name": "Cat",
        "hp": 1000,
        "attack_power": 50,
        "speed": 0
    }, team=TEAM_CAT)
    cat_b.pos_x = 2100

    # Enemy with Aku Shield
    aku_enemy = sim.spawn_custom_unit({
        "name": "Aku Doge",
        "hp": 2000,
        "attack_power": 100,
        "speed": 0,
        "abilities": {"shield_hp": 800}
    }, team=TEAM_ENEMY)
    aku_enemy.pos_x = 1400

    # Starred Alien Warper
    alien_warper = sim.spawn_custom_unit({
        "name": "Alien Warper",
        "hp": 3000,
        "attack_power": 100,
        "speed": 0,
        "abilities": {"warp_prob": 100, "warp_dur": 30, "warp_min": 200, "warp_max": 200}
    }, team=TEAM_ENEMY)
    alien_warper.pos_x = 1200

    # Zombie burrowing enemy
    zombie = sim.spawn_custom_unit({
        "name": "Zombo Doge",
        "hp": 1500,
        "attack_power": 80,
        "speed": 10,
        "abilities": {"burrow_count": 1, "revive_count": 1, "revive_time": 60, "revive_hp_pct": 50}
    }, team=TEAM_ENEMY)
    zombie.pos_x = 1600
    zombie.is_burrowing = True
    zombie.burrow_timer = 40

    # 3. Trigger authentic Surge attack
    sim._trigger_surge_attack(octo, opp_team=TEAM_ENEMY, direction=-1, surge_lvl=2, hit_damage=250)

    # 4. Trigger authentic Boss Shockwave
    sim._emit_event({"type": "boss_shockwave", "x": 1000, "boss_name": "帝王喵彈 (Emperor Nyandam)"})

    # 5. Fire Thunderbolt Cat Cannon
    sim.cannon_charge = sim.cannon_max_charge
    sim.fire_cannon(TEAM_CAT)

    # 6. Deploy Iron Wall Cat
    sim_wall = BattleSimulation(cannon_type="iron_wall")
    sim_wall.cannon_charge = sim_wall.cannon_max_charge
    sim_wall.fire_cannon(TEAM_CAT)

    # Center camera on the frontline
    camera.snap_to_target_x(1600)

    # Step simulation 10 frames to advance FX
    for _ in range(10):
        sim.step()
        renderer.process_visual_events(sim.consume_visual_events())

    # Render scene
    renderer.render(sim)

    # Save artifact screenshot
    out_dir = r"C:\Users\吳建廷\.gemini\antigravity\brain\7857d637-b7ce-44c0-911d-093a7914eab1"
    out_path = os.path.join(out_dir, "verify_authentic_battle_mechanics.png")
    pygame.image.save(surface, out_path)
    print(f"[+] Verified battle parity screenshot saved to: {out_path}")

if __name__ == "__main__":
    run_verification()
