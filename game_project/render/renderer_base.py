"""
Abstract Base Renderer Interface.
Decouples game simulation and scene state from specific rendering backends (Pygame, OpenGL, Vulkan, Headless).
"""

from abc import ABC, abstractmethod
from typing import List, Dict, Any

class BaseRenderer(ABC):
    @abstractmethod
    def render_environment(self):
        """Renders battlefield background and ground lines."""
        pass

    @abstractmethod
    def render_castles(self, cat_castle_info: Dict[str, Any], enemy_castle_info: Dict[str, Any]):
        """Renders friendly and hostile base castles."""
        pass

    @abstractmethod
    def render_units(self, units: List[Dict[str, Any]]):
        """Renders active field units with animations and HP indicators."""
        pass

    @abstractmethod
    def process_visual_events(self, events: List[Dict[str, Any]]):
        """Handles visual and audio events triggered by simulation ticks."""
        pass

    @abstractmethod
    def get_render_metadata(self) -> Dict[str, Any]:
        """Returns rendering metrics and asset status classification."""
        pass
