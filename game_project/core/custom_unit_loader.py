"""
Custom Character & PvP Unit Loader.
Allows players to create and load custom characters (JSON or Python API)
with full Ponos combat stats, traits, abilities, and skeletal animations
for 1P Battle or 2-Player Symmetric PvP.
"""

import os
import json
from typing import List, Dict, Any, Optional
from .constants import UNIT_RENDER_SCALE
from .unit_data import register_custom_unit, CAT_REGISTRY, ENEMY_REGISTRY
from ..render.unit_sprite_manager import UnitSpriteManager

DEFAULT_CUSTOM_UNITS_DIR = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
    "custom_units"
)


class CustomUnitLoader:
    """Loads user-created custom characters from JSON files and registers their stats & skeletal rigs."""
    LOADED_RAW_SPECS: Dict[str, Dict[str, Any]] = {}

    @staticmethod
    def load_from_dict(data: Dict[str, Any]) -> str:
        key = str(data.get("key") or data.get("id") or "custom_unit").strip()
        raw_id = data.get("id", 900)
        unit_id = int(raw_id) if str(raw_id).lstrip("-").isdigit() else 900
        name = str(data.get("name", key))
        base_rig = str(data.get("base_rig") or data.get("texture_code") or "000_f").strip()

        # Inherit authentic windup and maanim attack length from base_rig if available
        rig_ref = CAT_REGISTRY.get(base_rig) or ENEMY_REGISTRY.get(base_rig) or {}
        default_windup = rig_ref.get("attack_windup", 8)
        default_anim_len = rig_ref.get("attack_anim_len", max(default_windup + 3, 15))

        abilities = dict(data.get("abilities", {}))
        if "freeze_frames" in abilities and "freeze_dur" not in abilities:
            abilities["freeze_dur"] = int(abilities["freeze_frames"])

        data_copy = dict(data)
        data_copy["key"] = key
        data_copy["base_rig"] = base_rig
        CustomUnitLoader.LOADED_RAW_SPECS[key] = data_copy

        spec_dict = {
            "key": key,
            "id": unit_id if unit_id != 900 else key,
            "name": name,
            "hp": int(data.get("hp", 1000)),
            "attack_power": int(data.get("ap", data.get("attack_power", 200))),
            "speed": int(data.get("speed", 10)),
            "attack_range": int(data.get("range", data.get("attack_range", 150))),
            "cost": int(data.get("cost", 150)),
            "cooldown_frames": int(data.get("cd_frames", data.get("cooldown_frames", 60))),
            "knockback_count": int(data.get("kb_count", data.get("knockback_count", 3))),
            "radius": int(data.get("width", data.get("radius", 32))),
            "target_type": "area" if data.get("is_area_attack", True) else "single",
            "attack_windup": int(data.get("pre_atk_frames", data.get("attack_windup", default_windup))),
            "attack_interval": int(data.get("tba_frames", data.get("attack_interval", 30))),
            "attack_anim_len": int(data.get("attack_anim_frames", data.get("attack_anim_len", default_anim_len))),
            "texture_code": base_rig,
            "traits": list(data.get("traits", [])),
            "target_traits": list(data.get("target_traits", [])),
            "abilities": abilities,
            "is_custom": True,
            "render_scale": float(data.get("scale", data.get("render_scale", UNIT_RENDER_SCALE))),
            "tint_rgb": data.get("tint_rgb", None),
        }
        register_custom_unit(key, spec_dict, as_cat=True, as_enemy=True)

        # Register skeletal animation rig if custom files or base_rig_key are provided
        sprite_mgr = UnitSpriteManager.get_instance()
        rig_cfg = data.get("skeletal_rig")
        if isinstance(rig_cfg, dict):
            png_path = rig_cfg.get("png_path", "")
            imgcut_path = rig_cfg.get("imgcut_path", "")
            mamodel_path = rig_cfg.get("mamodel_path", "")
            maanim_paths = rig_cfg.get("maanim_paths", {})
            if png_path and os.path.isfile(png_path):
                sprite_mgr.register_custom_rig(
                    code=key,
                    png_path=png_path,
                    imgcut_path=imgcut_path,
                    mamodel_path=mamodel_path,
                    anim_paths=maanim_paths,
                )
        elif "base_rig" in data:
            # Alias an existing extracted Ponos skeletal rig (e.g. "002_f", "008_f", "018_e", "014_e")
            base_prefix = str(data["base_rig"]).strip()
            ext_dir = r"E:\rea\game_project\assets\official_extracted"
            png_p = os.path.join(ext_dir, f"{base_prefix}.png")
            cut_p = os.path.join(ext_dir, f"{base_prefix}.imgcut")
            mod_p = os.path.join(ext_dir, f"{base_prefix}.mamodel")
            anims = {}
            for st_key, sfx in (("walk", "00"), ("idle", "01"), ("attack", "02"), ("kb", "03")):
                ap = os.path.join(ext_dir, f"{base_prefix}{sfx}.maanim")
                if os.path.isfile(ap):
                    anims[st_key] = ap
            if os.path.isfile(png_p) and os.path.isfile(cut_p) and os.path.isfile(mod_p):
                sprite_mgr.register_custom_rig(
                    code=key,
                    png_path=png_p,
                    imgcut_path=cut_p,
                    mamodel_path=mod_p,
                    anim_paths=anims,
                )

        return key

    @classmethod
    def load_all(cls, directory: str = DEFAULT_CUSTOM_UNITS_DIR) -> List[str]:
        loaded_keys: List[str] = []
        if not os.path.isdir(directory):
            return loaded_keys

        for fname in sorted(os.listdir(directory)):
            if not fname.lower().endswith(".json"):
                continue
            fpath = os.path.join(directory, fname)
            try:
                with open(fpath, "r", encoding="utf-8") as f:
                    payload = json.load(f)
                units_list = payload if isinstance(payload, list) else payload.get("units", [payload])
                for item in units_list:
                    if isinstance(item, dict) and "key" in item:
                        k = cls.load_from_dict(item)
                        loaded_keys.append(k)
            except Exception as e:
                print(f"[!] Failed to load custom unit file {fpath}: {e}")
        return loaded_keys

    @classmethod
    def export_all_specs(cls) -> List[Dict[str, Any]]:
        """Exports all loaded custom character definitions for network PvP synchronization."""
        if not cls.LOADED_RAW_SPECS:
            cls.load_all()
        return list(cls.LOADED_RAW_SPECS.values())

    @classmethod
    def sync_specs_from_list(cls, specs: List[Dict[str, Any]]) -> List[str]:
        """Registers custom character definitions received from a remote peer in Online PvP."""
        synced: List[str] = []
        for item in specs:
            if isinstance(item, dict) and "key" in item:
                k = cls.load_from_dict(item)
                synced.append(k)
        return synced
