"""
DEPRECATED / SUPERSEDED MODULE.
All procedural vector graphics have been permanently retired to satisfy the Zero Fabrication constraint.
Rendering is handled exclusively by UnitSpriteManager (render/unit_sprite_manager.py)
using authentic decrypted textures (000_f.png~008_f.png, 000_e.png~015_e.png)
and official PONOS 2D Skeletal Models (PonosAnimationPlayer).
"""

from .unit_sprite_manager import UnitSpriteManager

# Aliased for backward compatibility if ever called
UnitSpriteDrawer = UnitSpriteManager
