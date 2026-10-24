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
# Native RE (Phase 10-12) verified the per-frame KB timer decrement (+0x83AD4, `add w10, -1`);
# distance/duration tables follow the PONOS interrupt table used by BCU (KB_DIS / KB_TIME):
#   normal KB / death KB: 165 units over 11 frames, boss shockwave: 705 units over 47 frames.
KNOCKBACK_FRAMES_DEFAULT = 11
KNOCKBACK_SPEED_PX = 15  # legacy average speed (165 / 11)
KB_SPECS = {
    "hitback": (330.0, 11),  # Authentic PONOS HP-threshold heavy damage knockback (~330 units over 11 frames)
    "kb": (165.0, 11),       # Authentic PONOS ability-proc knockback (~165 units over 11 frames)
    "cannon": (55.0, 8),     # Authentic PONOS Cat Cannon mini-knockback (~55 units over 8 frames)
    "death": (165.0, 11),    # Authentic PONOS death knockback before soul release (11 frames)
    "boss": (705.0, 47),     # Authentic PONOS Boss emergence shockwave (~705 units over 47 frames)
}

# Wave attack geometry (W_PROG / W_TIME / initial offset / hitbox width)
WAVE_PROG = 200.0
WAVE_SEG_FRAMES = 3
WAVE_INI_CAT = -67.5
WAVE_INI_ENEMY = -32.75
WAVE_WIDTH_CAT = 400.0
WAVE_WIDTH_ENEMY = 500.0

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
