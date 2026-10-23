"""
Cat Deployment and Cooldown Controller - Authentic Ponos Battle Cats Edition.
Manages player 10-slot battle deck, cooldown timers, production authorization,
and Level-scaled combat specifications from SaveManager.
"""

from typing import List, Dict, Any, Optional, Union
from ..core.unit_data import CAT_REGISTRY

_CAT_IDX_TO_KEY = {
    0: "cat", 1: "tank_cat", 2: "axe_cat", 3: "gross_cat", 4: "cow_cat",
    5: "bird_cat", 6: "fish_cat", 7: "lizard_cat", 8: "titan_cat"
}

DEFAULT_CORE_DECK = [0, 1, 2, 3, 4, 5, 6, 7, 8, -1]

class CatDeployer:
    def __init__(self, deck_keys: Optional[List[Union[str, int]]] = None, cat_levels: Optional[Dict[str, int]] = None, registry: Optional[Dict[Union[str, int], Dict[str, Any]]] = None):
        if deck_keys is None:
            deck_keys = list(DEFAULT_CORE_DECK)
        self.registry = registry if registry is not None else CAT_REGISTRY
        self.deck_keys = [_CAT_IDX_TO_KEY.get(k, k) if isinstance(k, int) and k in _CAT_IDX_TO_KEY and self.registry is CAT_REGISTRY else k for k in deck_keys]
        self.cat_levels = cat_levels or {}

        # Track cooldown frames for each deck slot
        self.cooldowns = [0] * len(self.deck_keys)
        self.max_cooldowns = []

        for k in self.deck_keys:
            spec = self._lookup_spec(k)
            if spec is not None:
                self.max_cooldowns.append(spec.get("cooldown_frames", 90))
            else:
                self.max_cooldowns.append(999999)

    def set_deck(self, deck_keys: List[Union[str, int]]):
        self.deck_keys = [
            _CAT_IDX_TO_KEY.get(k, k) if isinstance(k, int) and k in _CAT_IDX_TO_KEY and self.registry is CAT_REGISTRY else k
            for k in deck_keys[:10]
        ]
        self.cooldowns = [0] * len(self.deck_keys)
        self.max_cooldowns = []
        for k in self.deck_keys:
            spec = self._lookup_spec(k)
            if spec is not None:
                self.max_cooldowns.append(spec.get("cooldown_frames", 90))
            else:
                self.max_cooldowns.append(999999)

    def _lookup_spec(self, key: Any) -> Optional[Dict[str, Any]]:
        if key is None or key == -1:
            return None
        if isinstance(key, dict):
            return key
        if key in self.registry:
            return self.registry[key]
        if key in CAT_REGISTRY:
            return CAT_REGISTRY[key]
        return None

    def update(self):
        """Decrements cooldown timers by 1 frame."""
        for i in range(len(self.cooldowns)):
            if self.cooldowns[i] > 0:
                self.cooldowns[i] -= 1

    def get_slot_info(self, idx: int) -> Optional[Dict[str, Any]]:
        if not (0 <= idx < len(self.deck_keys)):
            return None
        key = self.deck_keys[idx]
        base_spec = self._lookup_spec(key)
        if base_spec is None:
            return None

        # Calculate level scaling (supports per-unit level or global "__default__" level)
        cat_id_str = str(base_spec.get("id", key))
        default_lv = self.cat_levels.get("__default__", 1)
        level = self.cat_levels.get(cat_id_str, self.cat_levels.get(str(key), default_lv))
        scale_factor = 1.0 + 0.2 * (level - 1)

        scaled_spec = dict(base_spec)
        scaled_spec["level"] = level
        scaled_spec["hp"] = int(base_spec["hp"] * scale_factor)
        scaled_spec["attack_power"] = int(base_spec["attack_power"] * scale_factor)
        if base_spec.get("attack_hits"):
            scaled_hits = []
            for h in base_spec["attack_hits"]:
                sh = dict(h)
                sh["damage"] = max(1, int(h["damage"] * scale_factor))
                scaled_hits.append(sh)
            scaled_spec["attack_hits"] = scaled_hits
            scaled_spec["attack_power"] = sum(sh["damage"] for sh in scaled_hits)
        cost = base_spec.get("cost", max(50, base_spec.get("money_drop", 100)))

        return {
            "key": key if not isinstance(key, dict) else base_spec.get("id", "custom"),
            "id": base_spec.get("id", key),
            "name": base_spec.get("name", str(key)),
            "level": level,
            "cost": cost,
            "current_cd": self.cooldowns[idx],
            "max_cd": self.max_cooldowns[idx],
            "cd_ratio": self.cooldowns[idx] / max(1, self.max_cooldowns[idx]),
            "texture_code": base_spec.get("texture_code", "000_f"),
            "icon_code": base_spec.get("icon_code", "uni000_f00"),
            "rarity": base_spec.get("rarity", 0),
            "rarity_label": base_spec.get("rarity_label", "基本"),
            "is_custom": bool(base_spec.get("is_custom", False)),
            "tint_rgb": base_spec.get("tint_rgb"),
            "spec": scaled_spec
        }

    def can_deploy(self, idx: int, current_money: int, has_free_slot: bool) -> bool:
        if not (0 <= idx < len(self.deck_keys)):
            return False
        if not has_free_slot:
            return False
        if self.cooldowns[idx] > 0:
            return False
        base_spec = self._lookup_spec(self.deck_keys[idx])
        if base_spec is None:
            return False
        cost = base_spec.get("cost", max(50, base_spec.get("money_drop", 100)))
        return current_money >= cost

    def trigger_cooldown(self, idx: int):
        if 0 <= idx < len(self.cooldowns):
            self.cooldowns[idx] = self.max_cooldowns[idx]
