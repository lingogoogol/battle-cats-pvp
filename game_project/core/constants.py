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
#   - HP-threshold hitback: 345 Distance Units (DU) over 24 frames (~14.375 DU / frame)
#   - Ability-proc knockback: 165 Distance Units (DU) over 11 frames (15.0 DU / frame)
#   - Cat Cannon / Sniper: 55 Distance Units (DU) over 11 frames (5.0 DU / frame)
#   - Boss shockwave: 735 Distance Units (DU) over 47 frames (15.638 DU / frame)
KNOCKBACK_FRAMES_DEFAULT = 11
KNOCKBACK_SPEED_PX = 15.0  # PONOS standard knockback displacement speed: ~15 DU / frame
KB_SPECS = {
    "hitback": (345.0, 24),  # Authentic PONOS HP-threshold damage knockback (345 DU over 24 frames)
    "kb": (165.0, 11),       # Authentic PONOS ability-proc knockback (165 DU over 11 frames)
    "cannon": (55.0, 11),    # Authentic PONOS Cat Cannon mini-knockback (55 DU over 11 frames)
    "boss": (735.0, 47),     # Authentic PONOS Boss emergence shockwave (735 DU over 47 frames)
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
