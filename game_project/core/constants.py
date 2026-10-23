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

# Knockback & motion constants verified in Phase 10-12
KNOCKBACK_FRAMES_DEFAULT = 12
KNOCKBACK_SPEED_PX = 8

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
