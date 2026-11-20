"""
2D Horizontal Scrolling Camera Controller.
Supports keyboard panning, mouse drag, and auto-focus on frontline combat.
"""

import random
from ..core.constants import SCREEN_WIDTH, BATTLEFIELD_LENGTH, BATTLE_WORLD_SCALE

class Camera2D:
    def __init__(self, viewport_width: int = SCREEN_WIDTH, world_width: int = BATTLEFIELD_LENGTH, world_scale: float = BATTLE_WORLD_SCALE):
        self.viewport_width = viewport_width
        self.world_width = world_width
        self.world_scale = float(world_scale)
        self.max_offset_x = max(0.0, world_width * self.world_scale - viewport_width)
        # In official Battle Cats, the camera initially focuses on the Player's Castle on the RIGHT
        self.offset_x = float(self.max_offset_x)
        self.is_dragging = False
        self.drag_start_mouse_x = 0
        self.drag_start_offset_x = 0
        self.shake_timer = 0
        self.shake_intensity = 0.0
        self.shake_dx = 0.0
        self.shake_dy = 0.0

    def trigger_shake(self, frames: int = 15, intensity: float = 8.0):
        self.shake_timer = max(self.shake_timer, frames)
        self.shake_intensity = max(self.shake_intensity, intensity)

    def update_shake(self):
        if self.shake_timer > 0:
            decay = self.shake_timer / 15.0
            self.shake_dx = random.uniform(-1.0, 1.0) * self.shake_intensity * decay
            self.shake_dy = random.uniform(-1.0, 1.0) * self.shake_intensity * decay
            self.shake_timer -= 1
        else:
            self.shake_dx = 0.0
            self.shake_dy = 0.0

    def world_to_screen_x(self, world_x: float) -> int:
        return int(world_x * self.world_scale - self.offset_x + self.shake_dx)

    def world_to_screen_dx(self, world_dx: float) -> float:
        return world_dx * self.world_scale

    def screen_to_world_x(self, screen_x: int) -> float:
        return (screen_x + self.offset_x) / self.world_scale

    def pan(self, dx: float):
        self.offset_x = max(0.0, min(float(self.max_offset_x), self.offset_x + dx))

    def snap_to_target_x(self, target_world_x: float):
        """Immediately centers camera on target_world_x without smoothing."""
        desired_offset = target_world_x * self.world_scale - (self.viewport_width / 2)
        self.offset_x = max(0.0, min(float(self.max_offset_x), desired_offset))

    def set_target_x(self, target_world_x: float):
        """Centers camera on target_world_x smoothly."""
        desired_offset = target_world_x * self.world_scale - (self.viewport_width / 2)
        desired_offset = max(0.0, min(float(self.max_offset_x), desired_offset))
        # Smooth interpolation
        self.offset_x += (desired_offset - self.offset_x) * 0.1

    def handle_mouse_down(self, mouse_x: int):
        self.is_dragging = True
        self.drag_start_mouse_x = mouse_x
        self.drag_start_offset_x = self.offset_x

    def handle_mouse_move(self, mouse_x: int):
        if self.is_dragging:
            delta = self.drag_start_mouse_x - mouse_x
            self.offset_x = max(0.0, min(float(self.max_offset_x), self.drag_start_offset_x + delta))

    def handle_mouse_up(self):
        self.is_dragging = False
