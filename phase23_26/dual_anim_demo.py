"""
Phase 24: Dual Character Interactive Animation Demo.
Plays authentic Basic Cat and authentic Enemy (186_e) animations simultaneously.
Supports interactive controls:
  [1] Enemy Walk
  [2] Enemy Idle
  [3] Enemy Attack
  [4] Enemy Knockback
  [D] Toggle Debug Bounding Boxes & Pivot Points
  [SPACE] Pause / Play
  [ESC] Quit
"""

import os
import sys
import pygame

sys.path.append(r"E:\rea\game_project")
from anim_engine.ponos_anim_player import PonosAnimationPlayer

CAT_PNG = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.png"
CAT_IMGCUT = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.imgcut"
CAT_MAMODEL = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000.mamodel"
CAT_WALK = r"E:\rea\game_assets\recovered_assets\download_cat\download_char_000_walkR.maanim"

ENEMY_PNG = r"E:\rea\phase23_26\enemy_186\186_e.png"
ENEMY_IMGCUT = r"E:\rea\phase23_26\enemy_186\186_e.imgcut"
ENEMY_MAMODEL = r"E:\rea\phase23_26\enemy_186\186_e.mamodel"
ENEMY_ANIMS = {
    "walk": r"E:\rea\phase23_26\enemy_186\186_e00.maanim",
    "idle": r"E:\rea\phase23_26\enemy_186\186_e01.maanim",
    "attack": r"E:\rea\phase23_26\enemy_186\186_e02.maanim",
    "kb": r"E:\rea\phase23_26\enemy_186\186_e03.maanim"
}

def run_demo(auto_frames: int = 0, save_screenshot_path: str = ""):
    pygame.init()
    pygame.font.init()
    font = pygame.font.SysFont("Arial", 16)
    title_font = pygame.font.SysFont("Arial", 20, bold=True)
    
    screen_w, screen_h = 960, 540
    if auto_frames > 0:
        screen = pygame.display.set_mode((screen_w, screen_h), pygame.HIDDEN)
    else:
        screen = pygame.display.set_mode((screen_w, screen_h))
        pygame.display.set_caption("Phase 24: Authentic Battle Cats 2D Animation Demo (Cat vs Enemy 186)")

    clock = pygame.time.Clock()
    
    # Load players
    cat_player = PonosAnimationPlayer(CAT_PNG, CAT_IMGCUT, CAT_MAMODEL, {"walk": CAT_WALK})
    enemy_player = PonosAnimationPlayer(ENEMY_PNG, ENEMY_IMGCUT, ENEMY_MAMODEL, ENEMY_ANIMS)
    enemy_player.set_animation("walk")
    
    cat_x = 220
    cat_y = 360
    enemy_x = 740
    enemy_y = 360
    
    paused = False
    debug_mode = False
    frame_count = 0
    running = True

    while running:
        dt = clock.tick(30)
        frame_count += 1
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                elif event.key == pygame.K_SPACE:
                    paused = not paused
                elif event.key == pygame.K_d:
                    debug_mode = not debug_mode
                elif event.key == pygame.K_1:
                    enemy_player.set_animation("walk")
                elif event.key == pygame.K_2:
                    enemy_player.set_animation("idle")
                elif event.key == pygame.K_3:
                    enemy_player.set_animation("attack")
                elif event.key == pygame.K_4:
                    enemy_player.set_animation("kb")

        if not paused:
            cat_player.update(1.0)
            enemy_player.update(1.0)

        # Draw Background
        screen.fill((235, 238, 242)) # Light neutral arena background
        
        # Ground line
        pygame.draw.line(screen, (160, 165, 175), (0, 370), (screen_w, 370), 3)
        pygame.draw.rect(screen, (220, 223, 230), (0, 373, screen_w, screen_h - 373))

        # Render Cat
        cat_player.render(screen, cat_x, cat_y, scale=1.5, flip_h=False)
        
        # Render Enemy 186
        enemy_player.render(screen, enemy_x, enemy_y, scale=1.1, flip_h=True)

        # Debug overlay
        if debug_mode:
            # Cat anchor
            pygame.draw.circle(screen, (0, 200, 0), (cat_x, cat_y), 5)
            # Enemy anchor
            pygame.draw.circle(screen, (200, 0, 0), (enemy_x, enemy_y), 5)
            # Origin labels
            lbl_c = font.render(f"Cat Root ({cat_x}, {cat_y}) Frame {cat_player.current_frame:.1f}", True, (0, 120, 0))
            lbl_e = font.render(f"Enemy 186 ({enemy_x}, {enemy_y}) Anim: {enemy_player.current_anim_name} Frame {enemy_player.current_frame:.1f}", True, (150, 0, 0))
            screen.blit(lbl_c, (cat_x - 80, cat_y + 15))
            screen.blit(lbl_e, (enemy_x - 120, enemy_y + 15))

        # UI Info Header
        title = title_font.render("Authentic Battle Cats 2D Skeletal Animation (PONOS Engine Rebuilt)", True, (30, 30, 40))
        screen.blit(title, (20, 20))
        
        src_cat = font.render(f"[Basic Cat] Source: DownloadLocal.pack (download_char_000) | Anim: Walk", True, (60, 70, 85))
        src_enemy = font.render(f"[Enemy 186] Source: NumberLocal.pack + ImageDataLocal.pack | State: {enemy_player.current_anim_name.upper()}", True, (60, 70, 85))
        ctrls = font.render("Controls: [1] Walk  [2] Idle  [3] Attack  [4] Knockback  [D] Debug Overlay  [SPACE] Pause  [ESC] Exit", True, (100, 105, 115))
        
        screen.blit(src_cat, (20, 50))
        screen.blit(src_enemy, (20, 72))
        screen.blit(ctrls, (20, screen_h - 35))

        if not auto_frames:
            pygame.display.flip()

        if auto_frames > 0 and frame_count >= auto_frames:
            if save_screenshot_path:
                os.makedirs(os.path.dirname(os.path.abspath(save_screenshot_path)), exist_ok=True)
                pygame.image.save(screen, save_screenshot_path)
                print(f"Demo snapshot saved to: {save_screenshot_path}")
            running = False

    pygame.quit()

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--auto", type=int, default=0, help="Run headless for N frames")
    parser.add_argument("--save", type=str, default="", help="Save final frame to path")
    args = parser.parse_args()
    run_demo(auto_frames=args.auto, save_screenshot_path=args.save)
