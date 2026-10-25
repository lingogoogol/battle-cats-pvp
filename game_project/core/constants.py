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
# Canvas coordinate system (1280x720, battlefield length 3200):
#   - HP-threshold hitback: 86.0 pixels over 12 frames (~7.167 px/frame, ~1.5 body lengths)
#   - Ability-proc knockback: 48.0 pixels over 11 frames (~4.364 px/frame, ~1 body length)
#   - Cat Cannon / Sniper: 25.0 pixels over 8 frames (~3.125 px/frame, ~0.5 body length)
#   - Boss shockwave: 180.0 pixels over 47 frames (~3.830 px/frame)
KNOCKBACK_FRAMES_DEFAULT = 11
KNOCKBACK_SPEED_PX = 4.364  # Authentic ability KB displacement speed (~4.36 px/frame)
KB_SPECS = {
    "hitback": (86.0, 12),   # Authentic PONOS HP-threshold damage knockback (86px over 12 frames)
    "kb": (48.0, 11),        # Authentic PONOS ability-proc knockback (48px over 11 frames)
    "cannon": (25.0, 8),     # Authentic PONOS Cat Cannon mini-knockback (25px over 8 frames)
    "boss": (180.0, 47),     # Authentic PONOS Boss emergence shockwave (180px over 47 frames)
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
