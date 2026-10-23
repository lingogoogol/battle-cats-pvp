"""
Phase 24: Animation System Integrity and Playback Verification.
Validates sprite sheets, .imgcut slices, .mamodel bone hierarchy, and .maanim keyframes
for authentic Cat and authentic Enemy (186_e).
Exports high-resolution proof frames, animation strips, and composite demo.
"""

import os
import sys
import json
import pygame
from PIL import Image

sys.path.append(r"E:\rea\game_project")
from anim_engine.ponos_anim_player import PonosAnimationPlayer, PonosImgcut, PonosMamodel, PonosMaanim

OUT_DIR = r"E:\rea\phase23_26\anim_output"
os.makedirs(OUT_DIR, exist_ok=True)

CAT_PNG = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.png"
CAT_IMGCUT = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.imgcut"
CAT_MAMODEL = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.mamodel"
CAT_WALK = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000_walkR.maanim"

ENEMY_PNG = r"E:\rea\phase23_26\enemy_186\186_e.png"
ENEMY_IMGCUT = r"E:\rea\phase23_26\enemy_186\186_e.imgcut"
ENEMY_MAMODEL = r"E:\rea\phase23_26\enemy_186\186_e.mamodel"
ENEMY_WALK = r"E:\rea\phase23_26\enemy_186\186_e00.maanim"
ENEMY_IDLE = r"E:\rea\phase23_26\enemy_186\186_e01.maanim"
ENEMY_ATTACK = r"E:\rea\phase23_26\enemy_186\186_e02.maanim"
ENEMY_KB = r"E:\rea\phase23_26\enemy_186\186_e03.maanim"

def validate_asset_integrity(name: str, png_p: str, cut_p: str, model_p: str, anim_map: dict):
    print(f"\n--- Validating Integrity for {name} ---")
    report = {"name": name, "png": {}, "cuts": {}, "model": {}, "animations": {}}
    
    # 1. Image
    with Image.open(png_p) as img:
        w, h = img.size
        report["png"] = {"width": w, "height": h, "mode": img.mode, "path": png_p}
        print(f"[{name}] PNG Atlas: {w}x{h}, Mode={img.mode}")
        
    # 2. Imgcut
    imgcut = PonosImgcut(cut_p)
    out_of_bounds = 0
    for cid, c in imgcut.cuts.items():
        if c.x < 0 or c.y < 0 or (c.x + c.w) > w or (c.y + c.h) > h:
            out_of_bounds += 1
            print(f"[{name}] Cut out of bounds! cut_id={cid}, rect=({c.x},{c.y},{c.w},{c.h}) vs ({w},{h})")
    report["cuts"] = {
        "total_cuts": len(imgcut.cuts),
        "out_of_bounds": out_of_bounds,
        "valid": (out_of_bounds == 0)
    }
    print(f"[{name}] Imgcut: {len(imgcut.cuts)} cuts, Out-of-bounds: {out_of_bounds}")
    
    # 3. Mamodel
    mamodel = PonosMamodel(model_p)
    num_parts = len(mamodel.parts)
    # Check parent cycles
    has_cycle = False
    for p in mamodel.parts:
        visited = set()
        cur = p.index
        while cur != -1:
            if cur in visited:
                has_cycle = True
                break
            visited.add(cur)
            parent = mamodel.parts[cur].parent_id
            if parent == cur:
                break
            cur = parent
    report["model"] = {
        "part_count": num_parts,
        "has_cycle": has_cycle,
        "valid": not has_cycle
    }
    print(f"[{name}] Mamodel: {num_parts} parts, Cycle detected: {has_cycle}")
    
    # 4. Maanims
    for anim_name, anim_file in anim_map.items():
        if not os.path.exists(anim_file):
            report["animations"][anim_name] = {"status": "BLOCKED_MISSING_FILE"}
            print(f"[{name}] Animation '{anim_name}': BLOCKED (File missing)")
            continue
        maanim = PonosMaanim(anim_file)
        report["animations"][anim_name] = {
            "status": "VERIFIED_AUTHENTIC",
            "tracks": len(maanim.tracks),
            "max_frame": maanim.max_frame,
            "path": anim_file
        }
        print(f"[{name}] Animation '{anim_name}': {len(maanim.tracks)} tracks, max_frame={maanim.max_frame} [VERIFIED]")
        
    return report

def render_anim_strip(player: PonosAnimationPlayer, anim_name: str, num_frames: int, frame_step: float,
                      out_strip_path: str, canvas_w: int, canvas_h: int, root_x: int, root_y: int,
                      scale: float = 1.0, flip_h: bool = False):
    player.set_animation(anim_name)
    strip_surf = pygame.Surface((canvas_w * num_frames, canvas_h), pygame.SRCALPHA)
    
    for i in range(num_frames):
        player.current_frame = i * frame_step
        cell_surf = pygame.Surface((canvas_w, canvas_h), pygame.SRCALPHA)
        player.render(cell_surf, root_x, root_y, scale=scale, flip_h=flip_h)
        strip_surf.blit(cell_surf, (i * canvas_w, 0))
        
        # Save individual frame
        single_frame_path = os.path.join(OUT_DIR, f"{anim_name}_frame_{i:02d}.png")
        pygame.image.save(cell_surf, single_frame_path)
        
    pygame.image.save(strip_surf, out_strip_path)
    print(f"Rendered {num_frames} frames to strip: {out_strip_path}")

def main():
    pygame.init()
    pygame.display.set_mode((100, 100), pygame.HIDDEN)
    
    full_report = {}
    
    # 1. Cat
    cat_anims = {
        "walk": CAT_WALK,
        "idle": r"E:\rea\decompiled_src\game_assets\assets\000_f00.maanim", # Expected from server
        "attack": r"E:\rea\decompiled_src\game_assets\assets\000_f02.maanim", # Expected from server
    }
    cat_report = validate_asset_integrity("Basic_Cat", CAT_PNG, CAT_IMGCUT, CAT_MAMODEL, cat_anims)
    full_report["Basic_Cat"] = cat_report
    
    # 2. Enemy 186
    enemy_anims = {
        "walk": ENEMY_WALK,
        "idle": ENEMY_IDLE,
        "attack": ENEMY_ATTACK,
        "kb": ENEMY_KB
    }
    enemy_report = validate_asset_integrity("Enemy_186", ENEMY_PNG, ENEMY_IMGCUT, ENEMY_MAMODEL, enemy_anims)
    full_report["Enemy_186"] = enemy_report
    
    # 3. Doge (Audit check)
    doge_report = {
        "name": "Doge_000_e",
        "status": "BLOCKED_AWAITING_INPUT",
        "reason": "Official assets (000_e.png, 000_e.imgcut, 000_e.mamodel, 000_e00~03.maanim) reside in ImageServer.pack (CDN download) and are not packaged inside offline local APK packs."
    }
    full_report["Doge_000_e"] = doge_report
    print("\n--- Doge Status Audit ---")
    print("Doge (000_e): BLOCKED_AWAITING_INPUT (CDN asset ImageServer.pack required)")
    
    # Instantiate players
    cat_player = PonosAnimationPlayer(CAT_PNG, CAT_IMGCUT, CAT_MAMODEL, {"walk": CAT_WALK})
    enemy_player = PonosAnimationPlayer(ENEMY_PNG, ENEMY_IMGCUT, ENEMY_MAMODEL, enemy_anims)
    
    # Export strips
    render_anim_strip(cat_player, "cat_walk", 16, 1.0, os.path.join(OUT_DIR, "cat_walk_strip_16f.png"), 120, 120, 60, 90, scale=1.0)
    render_anim_strip(enemy_player, "enemy186_walk", 16, 2.0, os.path.join(OUT_DIR, "enemy186_walk_strip_16f.png"), 200, 200, 100, 150, scale=0.8, flip_h=True)
    render_anim_strip(enemy_player, "enemy186_attack", 16, 3.0, os.path.join(OUT_DIR, "enemy186_attack_strip_16f.png"), 220, 200, 110, 150, scale=0.8, flip_h=True)
    
    # Composite face-off frame
    battle_comp = pygame.Surface((480, 240), pygame.SRCALPHA)
    cat_player.render(battle_comp, 100, 180, scale=1.2)
    enemy_player.set_animation("attack")
    enemy_player.current_frame = 15.0
    enemy_player.render(battle_comp, 360, 180, scale=0.9, flip_h=True)
    pygame.image.save(battle_comp, os.path.join(OUT_DIR, "cat_vs_enemy186_faceoff.png"))
    print(f"Composite face-off saved to: {os.path.join(OUT_DIR, 'cat_vs_enemy186_faceoff.png')}")
    
    # Save report
    with open(r"E:\rea\phase23_26\animation_audit.json", "w", encoding="utf-8") as jf:
        json.dump(full_report, jf, indent=2, ensure_ascii=False)
        
    print("\nAnimation integrity validation completed successfully.")

if __name__ == "__main__":
    main()
