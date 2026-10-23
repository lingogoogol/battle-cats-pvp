"""
Official Battle Cats Unit Data Definitions and Specifications.
Backed 100% by official reverse engineered data from DataLocal.pack:
- Cats: unit001.csv ~ unit009.csv, Unit_Explanation*_tw.csv, unitbuy.csv
- Enemies: t_unit.csv, Enemyname.tsv, EnemyPictureBook_tw.csv
- Stages: stage00.csv ~ stage47.csv, StageName_tw.csv

Zero synthetic or guessed values.
"""

from typing import Dict, Any, Union, Optional
from .official_data_parser import OfficialDataParser, CatData, EnemyData, StageData

_parser = OfficialDataParser.get_instance()

_cat_keys = [
    "cat", "tank_cat", "axe_cat", "gross_cat",
    "cow_cat", "bird_cat", "fish_cat", "lizard_cat", "titan_cat"
]

_enemy_name_to_key = {
    "狗仔": "doge",
    "扭扭蛇": "snache",
    "團結筷子幫": "baa_baa",
    "河馬將": "hippoe",
    "豬野郎": "pigge",
    "企鵝大哥": "jackie_peng",
    "大猩猩": "gory",
    "咩咩": "sheep",
    "斑海豹桑": "sir_seal",
    "臉君": "the_face",
    "看板小妹": "ms_sign"
}

# 1. Official 9 Core Cats + 29 Expanded Cats across all 6 Rarities (Loaded dynamically from unit*.csv)
CAT_REGISTRY: Dict[Union[str, int], Dict[str, Any]] = {}
OFFICIAL_CAT_KEYS = []

for i, key in enumerate(_cat_keys):
    cat_data = _parser.get_cat(i)
    if cat_data:
        spec = cat_data.to_dict()
        spec["key"] = key
        CAT_REGISTRY[key] = spec
        CAT_REGISTRY[i] = spec
        CAT_REGISTRY[spec["texture_code"]] = spec
        OFFICIAL_CAT_KEYS.append(key)

for u_key, cat_data in _parser.get_expanded_cats().items():
    if u_key in CAT_REGISTRY:
        continue
    spec = cat_data.to_dict()
    spec["key"] = u_key
    CAT_REGISTRY[u_key] = spec
    CAT_REGISTRY[spec["id"]] = spec
    CAT_REGISTRY[spec["texture_code"]] = spec
    OFFICIAL_CAT_KEYS.append(u_key)

# 2. Official Enemies (Loaded dynamically from t_unit.csv)
ENEMY_REGISTRY: Dict[Union[str, int], Dict[str, Any]] = {}
ROW_TO_ENEMY_KEY: Dict[int, str] = {}

for rid, enemy_data in _parser.get_all_enemies().items():
    spec = enemy_data.to_dict()
    ENEMY_REGISTRY[rid] = spec
    ENEMY_REGISTRY[spec["texture_code"]] = spec
    if enemy_data.name in _enemy_name_to_key:
        k = _enemy_name_to_key[enemy_data.name]
        ENEMY_REGISTRY[k] = spec
        ROW_TO_ENEMY_KEY[rid] = k

# 3. Stage registry
STAGE_REGISTRY: Dict[int, Dict[str, Any]] = {
    sid: s.to_dict() for sid, s in _parser.get_all_stages().items()
}

def get_cat_spec(key_or_id: Union[str, int]) -> Optional[Dict[str, Any]]:
    return CAT_REGISTRY.get(key_or_id)

def get_enemy_spec(key_or_id: Union[str, int]) -> Optional[Dict[str, Any]]:
    return ENEMY_REGISTRY.get(key_or_id)

def get_stage_spec(stage_id: int) -> Optional[Dict[str, Any]]:
    return STAGE_REGISTRY.get(stage_id)

def register_custom_unit(unit_key: str, spec: Dict[str, Any], as_cat: bool = True, as_enemy: bool = True) -> Dict[str, Any]:
    """
    Registers a user-created custom character into CAT_REGISTRY and/or ENEMY_REGISTRY
    so it can be deployed in standard battles, custom stages, or 2-player PvP battles.
    """
    normalized = {
        "key": unit_key,
        "id": spec.get("id", unit_key),
        "name": spec.get("name", unit_key),
        "description": spec.get("description", "Custom Unit"),
        "hp": int(spec.get("hp", 500)),
        "knockback_count": int(spec.get("knockback_count", 3)),
        "speed": int(spec.get("speed", 10)),
        "attack_power": int(spec.get("attack_power", 50)),
        "attack_interval": int(spec.get("attack_interval", 20)),
        "attack_range": int(spec.get("attack_range", 150)),
        "cost": int(spec.get("cost", 150)),
        "cooldown_frames": int(spec.get("cooldown_frames", 90)),
        "money_drop": int(spec.get("money_drop", spec.get("cost", 150) // 2)),
        "target_type": spec.get("target_type", "single"),
        "attack_windup": int(spec.get("attack_windup", 8)),
        "attack_anim_len": int(spec.get("attack_anim_len", max(15, int(spec.get("attack_windup", 8)) + 7))),
        "color": tuple(spec.get("color", (240, 240, 240))),
        "radius": int(spec.get("radius", 20)),
        "texture_code": spec.get("texture_code", "000_f"),
        "icon_code": spec.get("icon_code", "uni000_f00"),
        "traits": list(spec.get("traits", ["traitless"])),
        "target_traits": list(spec.get("target_traits", [])),
        "abilities": dict(spec.get("abilities", {})),
        "custom_rig": spec.get("custom_rig", None),
        "is_custom": bool(spec.get("is_custom", True)),
        "render_scale": float(spec.get("render_scale", spec.get("scale", 0.62))),
        "tint_rgb": spec.get("tint_rgb", None),
    }
    if as_cat:
        CAT_REGISTRY[unit_key] = normalized
        CAT_REGISTRY[normalized["id"]] = normalized
        CAT_REGISTRY[str(normalized["id"])] = normalized
    if as_enemy:
        ENEMY_REGISTRY[unit_key] = normalized
        ENEMY_REGISTRY[normalized["id"]] = normalized
        ENEMY_REGISTRY[str(normalized["id"])] = normalized
    return normalized

