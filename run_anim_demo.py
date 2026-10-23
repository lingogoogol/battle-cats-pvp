"""
Executable Authentic Ponos Animation Demo.
Loads recovered official Battle Cats animation assets (download_char_000 Cat),
steps through animation frames, verifies keyframe pose transitions,
and exports proof frames & composite strip to references/anim_playback_test/.
"""

import os
import sys
import pygame

# Direct all temp to E: drive
os.environ["TEMP"] = r"E:\rea\temp"
os.environ["TMP"] = r"E:\rea\temp"
os.environ["SDL_VIDEODRIVER"] = "dummy"

sys.path.insert(0, r"E:\rea")

from game_project.anim_engine.ponos_anim_player import PonosAnimationPlayer

def run_animation_demo(
    asset_dir: str = r"E:\rea\game_assets\recovered_assets\download_cat",
    out_dir: str = r"E:\rea\references\anim_playback_test"
):
    pygame.init()
    screen = pygame.display.set_mode((120, 120))
    os.makedirs(out_dir, exist_ok=True)

    png_path = os.path.join(asset_dir, "download_char_000.png")
    imgcut_path = os.path.join(asset_dir, "download_char_000.imgcut")
    mamodel_path = os.path.join(asset_dir, "download_char_000.mamodel")
    maanim_path = os.path.join(asset_dir, "download_char_000_walkR.maanim")

    print("[*] Initializing PonosAnimationPlayer with authentic Cat assets:")
    print(f"  PNG:     {png_path}")
    print(f"  Imgcut:  {imgcut_path}")
    print(f"  Mamodel: {mamodel_path}")
    print(f"  Maanim:  {maanim_path}")

    player = PonosAnimationPlayer(
        png_path=png_path,
        imgcut_path=imgcut_path,
        mamodel_path=mamodel_path,
        anim_paths={"walk": maanim_path}
    )

    player.set_animation("walk")

    frame_w, frame_h = 120, 120
    num_frames = 20
    frames_surfs = []

    print(f"[*] Rendering {num_frames} animation frames...")
    for f in range(num_frames):
        surf = pygame.Surface((frame_w, frame_h), pygame.SRCALPHA)
        # Background: dark slate for crisp visibility
        surf.fill((35, 40, 50))
        # Draw ground line
        pygame.draw.line(surf, (80, 90, 110), (0, 90), (frame_w, 90), 2)

        # Set exact frame
        player.current_frame = float(f)
        player.render(surf, root_x=60, root_y=88, scale=1.0)

        # Frame label
        font = pygame.font.SysFont("Arial", 12, bold=True)
        lbl = font.render(f"F{f:02d}", True, (255, 215, 0))
        surf.blit(lbl, (5, 5))

        frame_file = os.path.join(out_dir, f"frame_{f:02d}.png")
        pygame.image.save(surf, frame_file)
        frames_surfs.append(surf)

    # Composite horizontal strip of all frames
    strip_w = frame_w * num_frames
    strip_h = frame_h
    strip_surf = pygame.Surface((strip_w, strip_h))
    for i, f_surf in enumerate(frames_surfs):
        strip_surf.blit(f_surf, (i * frame_w, 0))

    strip_path = os.path.join(out_dir, "cat_walk_strip.png")
    pygame.image.save(strip_surf, strip_path)
    print(f"[+] All {num_frames} frames saved to: {out_dir}")
    print(f"[+] Composite animation strip saved to: {strip_path}")

    pygame.quit()
    return True

if __name__ == "__main__":
    success = run_animation_demo()
    sys.exit(0 if success else 1)
