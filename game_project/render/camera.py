"""
2D Horizontal Scrolling Camera Controller.
Supports keyboard panning, mouse drag, and auto-focus on frontline combat.
"""

from ..core.constants import SCREEN_WIDTH, BATTLEFIELD_LENGTH

class Camera2D:
    def __init__(self, viewport_width: int = SCREEN_WIDTH, world_width: int = BATTLEFIELD_LENGTH):
        self.viewport_width = viewport_width
        self.world_width = world_width
        self.max_offset_x = max(0, world_width - viewport_width)
        # In official Battle Cats, the camera initially focuses on the Player's Castle on the RIGHT
        self.offset_x = float(self.max_offset_x)
        self.is_dragging = False
        self.drag_start_mouse_x = 0
        self.drag_start_offset_x = 0

    def world_to_screen_x(self, world_x: float) -> int:
        return int(world_x - self.offset_x)

    def screen_to_world_x(self, screen_x: int) -> float:
        return screen_x + self.offset_x

    def pan(self, dx: float):
        self.offset_x = max(0.0, min(float(self.max_offset_x), self.offset_x + dx))

    def snap_to_target_x(self, target_world_x: float):
        """Immediately centers camera on target_world_x without smoothing."""
        desired_offset = target_world_x - (self.viewport_width / 2)
        self.offset_x = max(0.0, min(float(self.max_offset_x), desired_offset))

    def set_target_x(self, target_world_x: float):
        """Centers camera on target_world_x smoothly."""
        desired_offset = target_world_x - (self.viewport_width / 2)
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
