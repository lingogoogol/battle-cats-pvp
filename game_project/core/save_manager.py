"""
Local Save Data and Progression Manager.
Handles JSON persistence for stage progression, unlocked cats, and game settings.
Completely offline; zero proprietary server dependencies.
"""

import os
import json
from typing import Dict, Any, List

SAVE_FILE_PATH = r"E:\rea\game_project\data\save_data.json"

class SaveManager:
    DEFAULT_SAVE: Dict[str, Any] = {
        "version": "1.0.0",
        "xp": 2500,                   # Starting XP for upgrades
        "cat_food": 30,               # Cans
        "leadership": 100,            # Current Energy
        "max_leadership": 100,        # Max Energy
        "cleared_stages": [1],        # Stage 1 cleared by default in dev
        "unlocked_cats": [0, 1, 2, 3, 4, 5, 6, 7, 8], # Cat 0..8 (Basic to Titan)
        "cat_levels": {str(i): 1 for i in range(9)},   # Lv 1 default
        "formation_deck": [0, 1, 2, 3, 4, 5, 6, 7, 8, -1], # 10 battle slots
        "base_levels": {
            "worker_cat": 1,
            "wallet": 1,
            "cannon_power": 1,
            "cannon_charge": 1,
            "castle_hp": 1
        },
        "treasures": {
            "eoc_chapters": 3.0,
            "trait_fruits": {
                "red": True,
                "floating": True,
                "black": True,
                "angel": True,
                "alien": True,
                "zombie": True
            }
        },
        "cannon_type": "normal",
        "sound_enabled": True,
        "volume": 0.8,
        "total_victories": 0,
        "high_scores": {}
    }

    def __init__(self, filepath: str = SAVE_FILE_PATH):
        self.filepath = filepath
        self.data: Dict[str, Any] = self.load()

    def load(self) -> Dict[str, Any]:
        if not os.path.exists(self.filepath):
            return dict(self.DEFAULT_SAVE)
        try:
            with open(self.filepath, "r", encoding="utf-8") as f:
                data = json.load(f)
            # Merge with default to guarantee keys exist
            merged = dict(self.DEFAULT_SAVE)
            merged.update(data)
            return merged
        except Exception as e:
            print(f"[!] Warning: Error reading save file '{self.filepath}' ({e}). Resetting to default.")
            return dict(self.DEFAULT_SAVE)

    def save(self):
        try:
            os.makedirs(os.path.dirname(self.filepath), exist_ok=True)
            with open(self.filepath, "w", encoding="utf-8") as f:
                json.dump(self.data, f, indent=2, ensure_ascii=False)
        except Exception as e:
            print(f"[!] Error writing save file '{self.filepath}': {e}")

    def mark_stage_cleared(self, stage_id: int):
        if stage_id not in self.data["cleared_stages"]:
            self.data["cleared_stages"].append(stage_id)
        self.data["total_victories"] = self.data.get("total_victories", 0) + 1
        # Unlock cats based on stage threshold
        # Cat 1 unlocked at Stage 1, Cat 2 at Stage 3, Cat 3 at Stage 5, etc.
        for cat_id in range(9):
            if cat_id not in self.data.get("unlocked_cats", []):
                self.data["unlocked_cats"].append(cat_id)
        self.save()

    @property
    def xp(self) -> int:
        return self.data.get("xp", 0)

    @property
    def cat_food(self) -> int:
        return self.data.get("cat_food", 0)

    @property
    def leadership(self) -> int:
        return self.data.get("leadership", 100)

    @property
    def max_leadership(self) -> int:
        return self.data.get("max_leadership", 100)

    def add_xp(self, amount: int):
        self.data["xp"] = max(0, self.data.get("xp", 0) + amount)
        self.save()

    def spend_xp(self, amount: int) -> bool:
        if self.data.get("xp", 0) >= amount:
            self.data["xp"] -= amount
            self.save()
            return True
        return False

    def get_cat_level(self, cat_id: int) -> int:
        levels = self.data.get("cat_levels", {})
        return levels.get(str(cat_id), 1)

    def upgrade_cat(self, cat_id: int, cost: int) -> bool:
        if self.spend_xp(cost):
            levels = self.data.setdefault("cat_levels", {})
            cur = levels.get(str(cat_id), 1)
            levels[str(cat_id)] = cur + 1
            self.save()
            return True
        return False

    def get_deck(self) -> List[int]:
        deck = self.data.get("formation_deck", [])
        if not deck or len(deck) != 10:
            deck = [0, 1, 2, 3, 4, 5, 6, 7, 8, -1]
            self.data["formation_deck"] = deck
            self.save()
        return list(deck)

    def set_deck_slot(self, slot_idx: int, cat_id: int):
        deck = self.get_deck()
        if 0 <= slot_idx < len(deck):
            deck[slot_idx] = cat_id
            self.data["formation_deck"] = deck
            self.save()

    def get_base_level(self, part: str) -> int:
        base = self.data.get("base_levels", {})
        return base.get(part, 1)

    def upgrade_base_part(self, part: str, cost: int) -> bool:
        if self.spend_xp(cost):
            base = self.data.setdefault("base_levels", {})
            cur = base.get(part, 1)
            base[part] = cur + 1
            self.save()
            return True
        return False

    def is_stage_unlocked(self, stage_id: int) -> bool:
        if stage_id == 1:
            return True
        # Stage N is unlocked if Stage N-1 was cleared
        return (stage_id - 1) in self.data.get("cleared_stages", [])

    def is_stage_cleared(self, stage_id: int) -> bool:
        return stage_id in self.data.get("cleared_stages", [])

    def toggle_sound(self) -> bool:
        self.data["sound_enabled"] = not self.data.get("sound_enabled", True)
        self.save()
        return self.data["sound_enabled"]

    def get_treasure_config(self) -> Dict[str, Any]:
        return self.data.get("treasures", {
            "eoc_chapters": 3.0,
            "trait_fruits": {"red": True, "floating": True, "black": True, "angel": True, "alien": True, "zombie": True}
        })

    def set_treasure_config(self, config: Dict[str, Any]):
        self.data["treasures"] = dict(config)
        self.save()

    def get_cannon_type(self) -> str:
        return self.data.get("cannon_type", "normal")

    def set_cannon_type(self, ctype: str):
        self.data["cannon_type"] = str(ctype)
        self.save()

