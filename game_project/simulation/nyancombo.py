"""
Authentic Ponos Cat Combo (にゃんコンボ / Nyancombo) Evaluator.
Parsed directly from NyancomboData.csv.
Evaluates Row 1 (deck slots 0..4) to activate authentic team buffs:
- Initial Money (Type 5: Sm +300, Med +500, Lg +1000)
- Worker Cat Initial Level (Type 4: Sm +1, Med +2, Lg +3)
- Attack Power Up (Type 0: Sm +10%, Med +15%, Lg +20%)
- HP / Defense Up (Type 1: Sm +10%, Med +15%, Lg +20%)
- Unit Speed Up (Type 2: Sm +10%, Med +15%)
- Unit Cooldown Reduction (Type 7: Sm -26f, Med -52f)
- Cannon Initial Charge (Type 3: Sm +20%, Med +30%, Lg +50%)
- Cannon Power (Type 6: Sm +20%, Med +50%, Lg +100%)
- Accounting Bounty Drop (Type 9: Sm +10%, Med +20%)
- Castle HP (Type 10: Sm +20%, Med +50%, Lg +100%)
"""

import os
from typing import List, Dict, Any, Optional, Tuple, Set
from ..core.official_data_parser import DEFAULT_OFFICIAL_DATA_DIR

COMBO_NAMES = {
    0: ("攻擊力提升", "atk_mult"),
    1: ("體力提升", "hp_mult"),
    2: ("移動速度提升", "spd_mult"),
    3: ("貓咪砲初始充能", "cannon_charge_rate"),
    4: ("工作狂貓初始等級", "worker_level"),
    5: ("初期所持金增加", "initial_money"),
    6: ("貓咪砲攻擊力", "cannon_power_mult"),
    7: ("角色冷卻縮短", "cooldown_reduction"),
    9: ("獲得金錢增加", "accounting_mult"),
    10: ("城堡體力增加", "castle_hp_mult"),
    11: ("「善於攻擊」效果提升", "strong_boost"),
    12: ("「超大傷害」效果提升", "massive_boost"),
    13: ("「很耐打」效果提升", "resistant_boost"),
}

COMBO_MAGNITUDES = {
    # type: (Small, Medium, Large)
    0: (0.10, 0.15, 0.20),      # Atk Up
    1: (0.10, 0.15, 0.20),      # HP Up
    2: (0.10, 0.15, 0.20),      # Spd Up
    3: (0.20, 0.30, 0.50),      # Cannon Initial Charge ratio
    4: (1, 2, 3),               # Worker Cat Level
    5: (300, 500, 1000),        # Initial Money
    6: (0.20, 0.50, 1.00),      # Cannon Power
    7: (26, 52, 78),            # Cooldown frames reduction
    9: (0.10, 0.20, 0.30),      # Money Drop
    10: (0.20, 0.50, 1.00),     # Castle HP
    11: (0.10, 0.20, 0.30),     # Strong Boost
    12: (0.10, 0.20, 0.30),     # Massive Boost
    13: (0.10, 0.20, 0.30),     # Resistant Boost
}

SIZE_LABELS = {0: "小", 1: "中", 2: "大"}

class NyancomboRule:
    def __init__(self, combo_id: int, units: List[Tuple[int, int]], combo_type: int, size: int):
        self.combo_id = combo_id
        # units: list of (unit_id, min_form)
        self.units = units
        self.combo_type = combo_type
        self.size = size
        type_info = COMBO_NAMES.get(combo_type, (f"聯組 {combo_type}", f"type_{combo_type}"))
        self.name = type_info[0]
        self.effect_key = type_info[1]
        mags = COMBO_MAGNITUDES.get(combo_type, (0.10, 0.20, 0.30))
        self.magnitude = mags[min(size, len(mags) - 1)]

    def is_active(self, deck_unit_forms: List[Optional[Tuple[int, int]]]) -> bool:
        """
        deck_unit_forms: list of up to 5 items in Row 1: (unit_id, current_form) or None.
        A combo is satisfied if every required unit in `self.units` exists in the row
        with current_form >= min_form.
        """
        row_map: Dict[int, int] = {}
        for entry in deck_unit_forms:
            if entry is not None:
                uid, form = entry
                row_map[uid] = max(row_map.get(uid, 0), form)

        for req_uid, req_form in self.units:
            if req_uid not in row_map:
                return False
            if row_map[req_uid] < req_form:
                return False
        return True


class NyancomboManager:
    _instance: Optional['NyancomboManager'] = None

    def __init__(self, data_dir: str = DEFAULT_OFFICIAL_DATA_DIR):
        self.combos: List[NyancomboRule] = []
        self._load_combos(data_dir)

    @classmethod
    def get_instance(cls, data_dir: str = DEFAULT_OFFICIAL_DATA_DIR) -> 'NyancomboManager':
        if cls._instance is None:
            cls._instance = NyancomboManager(data_dir)
        return cls._instance

    def _load_combos(self, data_dir: str):
        csv_p = os.path.join(data_dir, "NyancomboData.csv")
        if not os.path.isfile(csv_p):
            return
        with open(csv_p, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                line = line.strip().split("//")[0]
                if not line:
                    continue
                parts = [int(p.strip()) for p in line.split(",") if p.strip().lstrip("-").isdigit()]
                if len(parts) < 15:
                    continue
                combo_id = parts[0]
                # Columns 3..12 are 5 slots of (unit_id, form)
                req_units = []
                for s in range(5):
                    u_col = 3 + s * 2
                    f_col = 4 + s * 2
                    if u_col < len(parts) and f_col < len(parts):
                        uid = parts[u_col]
                        ufm = parts[f_col]
                        if uid >= 0:
                            req_units.append((uid, max(0, ufm)))
                combo_type = parts[13]
                size = parts[14]
                if req_units and combo_type in COMBO_NAMES:
                    self.combos.append(NyancomboRule(combo_id, req_units, combo_type, size))

    def evaluate_deck(self, row1_units: List[Optional[Tuple[int, int]]]) -> List[NyancomboRule]:
        """Returns all activated Nyancombos for the given first row (up to 5 units)."""
        active = []
        for c in self.combos:
            if c.is_active(row1_units):
                active.append(c)
        return active

    def calculate_combo_effects(self, active_combos: List[NyancomboRule]) -> Dict[str, Any]:
        """
        Aggregates effects:
        - initial_money (int): extra starting wallet money
        - worker_level (int): extra starting worker cat level
        - atk_mult (float): atk multiplier (1.0 + sum of boosts)
        - hp_mult (float): hp multiplier (1.0 + sum of boosts)
        - spd_mult (float): speed multiplier (1.0 + sum of boosts)
        - cooldown_reduction (int): frames reduced from cooldowns
        - cannon_charge_rate (float): initial cannon charge fraction
        - cannon_power_mult (float): cannon power multiplier
        - accounting_mult (float): bounty money multiplier
        - castle_hp_mult (float): castle hp multiplier
        """
        effects: Dict[str, Any] = {
            "initial_money": 0,
            "worker_level": 0,
            "atk_mult": 1.0,
            "hp_mult": 1.0,
            "spd_mult": 1.0,
            "cooldown_reduction": 0,
            "cannon_charge_rate": 0.0,
            "cannon_power_mult": 1.0,
            "accounting_mult": 1.0,
            "castle_hp_mult": 1.0,
            "strong_boost": 0.0,
            "massive_boost": 0.0,
            "resistant_boost": 0.0,
            "active_combos": [],
        }

        for c in active_combos:
            effects["active_combos"].append({
                "id": c.combo_id,
                "name": c.name,
                "size": SIZE_LABELS.get(c.size, "小"),
                "type": c.combo_type,
                "magnitude": c.magnitude,
            })
            if c.effect_key == "initial_money":
                effects["initial_money"] += int(c.magnitude)
            elif c.effect_key == "worker_level":
                effects["worker_level"] += int(c.magnitude)
            elif c.effect_key == "cooldown_reduction":
                effects["cooldown_reduction"] += int(c.magnitude)
            elif c.effect_key == "cannon_charge_rate":
                effects["cannon_charge_rate"] = min(1.0, effects["cannon_charge_rate"] + float(c.magnitude))
            elif c.effect_key in ("atk_mult", "hp_mult", "spd_mult", "cannon_power_mult", "accounting_mult", "castle_hp_mult"):
                effects[c.effect_key] += float(c.magnitude)
            elif c.effect_key in ("strong_boost", "massive_boost", "resistant_boost"):
                effects[c.effect_key] += float(c.magnitude)

        return effects
