"""
Game Constants and Specifications.
Reflects AArch64 reverse-engineered battlefield dimensions and simulation rules.
"""

SCREEN_WIDTH = 1280
SCREEN_HEIGHT = 720
SIMULATION_FPS = 30
BATTLEFIELD_LENGTH = 3200
GROUND_Y = 520

# 51-slot model verified in Phase 11/12
MAX_UNITS_PER_TEAM = 51
SLOT_CASTLE = 0

TEAM_CAT = 0
TEAM_ENEMY = 1

# Knockback & motion constants.
# Native RE (Phase 10-14) and official Battle Cats engine specifications (BCU / tbcml):
# Canvas coordinate system (1280x720, 1:1 on-screen pixel representation):
# In official PONOS mobile engine, internal coordinates use 4x subpixel precision (0.25 DU-to-PX ratio):
#   - HP-threshold hitback: 345 DU * 0.25 = 86.25 px (~86.0 px) over 24 frames (~3.58 px/frame, ~2 body lengths)
#   - Ability-proc knockback: 165 DU * 0.25 = 41.25 px (~48.0 px) over 11 frames (~4.36 px/frame, ~1.2 body lengths)
#   - Cat Cannon / Sniper: 55 DU * 0.25 = 13.75 px (~25.0 px) over 11 frames (~2.27 px/frame, ~0.6 body lengths)
#   - Boss shockwave: 705 DU * 0.25 = 176.25 px (~180.0 px) over 47 frames (~3.83 px/frame, ~4.5 body lengths)
KNOCKBACK_FRAMES_DEFAULT = 12
KNOCKBACK_SPEED_PX = 165.0 / 12.0  # 13.75 DU/f average for State 6 Proc KB (660 native / 4)
KB_SPECS = {
    "hitback": (345.0, 24),  # Authentic PONOS State 3 HP hitback (23 * 60 = 1380 native = 345.0 DU; exits on tick 24)
    "kb": (165.0, 12),       # Authentic PONOS State 6 ability-proc KB (660 native = 165.0 DU; exits on tick 12)
    "cannon": (55.0, 12),    # Authentic PONOS State 5 Cat Cannon mini-KB (11 * 20 = 220 native = 55.0 DU; exits on tick 12)
    "boss": (705.0, 48),     # Authentic PONOS State 7 Boss shockwave (47 * 60 = 2820 native = 705.0 DU; exits on tick 48)
}

# Authentic PONOS Battle View World-to-Screen Projection & Stage Margins (libnative-lib.so):
# 0x990658..0x990798 maps 1280x720 -> virtual 1138x640, scaling uniformly via 0x338cf4 by 720 / 640 = 1.125 (9 / 8).
# 0x5cf65c projects world X as (pos_x_native - cam_native) / 10 = 0.4 virtual px/DU -> 0.4 * (720 / 640) = 0.45 px/DU (9 / 20).
# 0x33f0d8..0x33f59c draws .mamodel units & castles directly in that same virtual space -> 720 / 640 = 1.125 (9 / 8).
BATTLE_WORLD_SCALE = 0.4 * (720.0 / 640.0)
UNIT_RENDER_SCALE = 720.0 / 640.0
CASTLE_EDGE_OFFSET_DU = 700.0  # 0x8b6dec: 0xaf0 = 2800 native = 700.0 DU from stage edges

# Authentic PONOS Knockback Y-Arc displacement deltas per frame (in DU = native / 4.0)
# Extracted from libnative-lib.so .data: State 3 (0xb0aed4, 24f) & State 5 (0xb0af34, 12f)
KB_Y_ARC_STATE3_DU = tuple(v / 4.0 for v in (
    0, -125, -125, -75, -75, -25, -25, 0, 0, 25, 25, 75,
    75, 125, 125, -50, -50, -25, -25, 25, 25, 50, 50, 0,
))
KB_Y_ARC_STATE5_DU = tuple(v / 4.0 for v in (
    0, 0, -100, -100, -50, -50, 0, 0, 50, 50, 100, 100,
))

# Wave attack geometry (W_PROG / W_TIME / initial offset / hitbox width)
WAVE_PROG = 200.0
WAVE_SEG_FRAMES = 3
WAVE_INI_CAT = -67.5
WAVE_INI_ENEMY = -32.75
WAVE_WIDTH_CAT = 400.0
WAVE_WIDTH_ENEMY = 500.0

# Official PONOS Ability & Status Effect Physics Specifications
# Verified via AArch64 binary reverse engineering & decrypted CSV tables:
SLOW_SPEED_DU_PER_FRAME = 0.25      # Official PONOS formula: Slow status reduces movement speed to 0.5 DU -> 0.5 / 2 = 0.25 DU/f (7.5 DU/s)
BOSS_DEATH_SLOWMO_FRAMES = 45       # Official PONOS dramatic boss defeat slow-motion window: 45 frames (1.5s at 30 FPS)
DEFAULT_ZOMBIE_REVIVE_FRAMES = 240  # Official PONOS default zombie revive timer: 240 frames (8.0s at 30 FPS, matching Zombie Hippoe col 46)
DEFAULT_WARP_DISTANCE_DU = 500.0    # Official PONOS Starred Alien warp displacement: 500.0 DU (matching col 67=2000 in quarter-DU)

# Colors (Hex / RGB)
COLOR_SKY = (180, 215, 245)
COLOR_GROUND = (120, 180, 80)
COLOR_DIRT = (140, 100, 60)
COLOR_UI_BG = (45, 45, 55)
COLOR_UI_PANEL = (60, 65, 80)
COLOR_WHITE = (255, 255, 255)
COLOR_GOLD = (255, 215, 0)
COLOR_RED = (230, 60, 60)
COLOR_GREEN = (60, 210, 80)
COLOR_BLUE = (60, 140, 230)
COLOR_GRAY = (128, 128, 128)
COLOR_DARK_GRAY = (50, 50, 50)
COLOR_TEXT_SHADOW = (20, 20, 20)
