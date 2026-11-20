"""
Official Unit Sprite and Skeletal Animation Manager for The Battle Cats.
Provides 100% authentic PONOS 2D skeletal animation rendering via PonosAnimationPlayer:
- All 9 Player Cats (000_f ~ 008_f) with official .imgcut + .mamodel + .maanim (00=walk, 01=idle, 02=attack, 03=kb).
- All Chapter 1 Enemies (000_e ~ 015_e, 018_e, 021_e, 022_e, 186_e) with official .imgcut + .mamodel + .maanim.
- Symmetrical Team Orientation for PvP & Custom Units:
  * Units on Team 0 (Right Castle marching LEFT) naturally face LEFT (flip_h = False).
  * Units on Team 1 (Left Castle marching RIGHT) face RIGHT (flip_h = True).
- Supports custom user-created characters (either custom Ponos skeletal rigs or custom sprite sheets).
Zero broken connected-component slicing or detached body parts.
"""

import os
import math
import pygame
from typing import Dict, List, Tuple, Optional, Any
from ..core.constants import GROUND_Y, TEAM_CAT, TEAM_ENEMY, KNOCKBACK_FRAMES_DEFAULT, UNIT_RENDER_SCALE
from ..simulation.battle_sim import SimUnit
from ..anim_engine.ponos_anim_player import PonosAnimationPlayer

def to_32bit_scaled(surf: pygame.Surface, target_size: Tuple[int, int]) -> pygame.Surface:
    """Safely converts surface to 32-bit SRCALPHA and smooth scales."""
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return pygame.transform.smoothscale(s32, target_size)
    return pygame.transform.smoothscale(surf, target_size)

class UnitSpriteManager:
    _instance: Optional['UnitSpriteManager'] = None

    @classmethod
    def get_instance(cls, asset_dir: Optional[str] = None) -> 'UnitSpriteManager':
        if cls._instance is None:
            cls._instance = UnitSpriteManager(asset_dir)
        return cls._instance

    def __init__(self, asset_dir: Optional[str] = None):
        if asset_dir is None:
            asset_dir = r"E:\rea\game_project\assets\official_extracted"
        self.asset_dir = asset_dir

        # 1. Official Skeletal Animation Players (keyed by texture_code e.g. '000_f', '000_e', '018_e' and aliases 'cat_0', 'enemy_18')
        self.skeletal_players: Dict[str, PonosAnimationPlayer] = {}

        # 2. Cat Sprites & Enemy Sprites dictionaries (populated by rendering actual skeletal frames for full compatibility)
        self.cat_sprites: Dict[int, Dict[str, Any]] = {}
        self.enemy_sprites: Dict[int, Dict[str, Any]] = {}

        self._init_skeletal_players()
        self._init_all_cats()
        self._init_all_enemies()
        self.hit_flash_timers: Dict[str, int] = {}

    def _load_rig(self, base_dir: str, code: str) -> Optional[PonosAnimationPlayer]:
        png_p = os.path.join(base_dir, f"{code}.png")
        cut_p = os.path.join(base_dir, f"{code}_tw.imgcut")
        if not os.path.isfile(cut_p):
            cut_p = os.path.join(base_dir, f"{code}.imgcut")
        model_p = os.path.join(base_dir, f"{code}.mamodel")
        if not (os.path.isfile(png_p) and os.path.isfile(cut_p) and os.path.isfile(model_p)):
            return None

        anims = {}
        for anim_name, suffix in [("walk", "00"), ("idle", "01"), ("attack", "02"), ("kb", "03")]:
            ap = os.path.join(base_dir, f"{code}{suffix}.maanim")
            if os.path.isfile(ap):
                anims[anim_name] = ap

        try:
            player = PonosAnimationPlayer(png_p, cut_p, model_p, anims)
            player.set_animation("walk")
            return player
        except Exception as e:
            print(f"[!] Warning: failed to load skeletal rig {code}: {e}")
            return None

    def register_custom_rig(self, code: str, png_path: str, imgcut_path: str, mamodel_path: str, anim_paths: Dict[str, str]) -> Optional[PonosAnimationPlayer]:
        """Registers a user-created custom character skeletal rig for battle/PvP."""
        try:
            player = PonosAnimationPlayer(png_path, imgcut_path, mamodel_path, anim_paths)
            player.set_animation("walk")
            self.skeletal_players[code] = player
            return player
        except Exception as e:
            print(f"[!] Warning: failed to register custom rig {code}: {e}")
            return None

    def _init_skeletal_players(self):
        """Initializes all decrypted official 2D skeletal rigs (`000_f`~`008_f`, `000_e`~`022_e`, `186_e`)."""
        # 1. All 9 Player Cats (000_f ~ 008_f) and Evolved forms (000_c ~ 008_c)
        for cid in range(9):
            for form in ("f", "c"):
                code = f"{cid:03d}_{form}"
                p = self._load_rig(self.asset_dir, code)
                if p is not None:
                    self.skeletal_players[code] = p
                    if form == "f":
                        self.skeletal_players[f"cat_{cid}"] = p

        # 2. All Chapter 1 Enemies (000_e ~ 024_e)
        for eid in range(25):
            code = f"{eid:03d}_e"
            p = self._load_rig(self.asset_dir, code)
            if p is not None:
                self.skeletal_players[code] = p
                self.skeletal_players[f"enemy_{eid}"] = p

        # 3. Enemy 186 (Master A. / 師父 - 186_e)
        p_dir = r"E:\rea\phase23_26\enemy_186"
        p186 = self._load_rig(p_dir, "186_e")
        if p186 is not None:
            self.skeletal_players["186_e"] = p186
            self.skeletal_players["enemy_186"] = p186

    @property
    def enemy186_player(self) -> Optional[PonosAnimationPlayer]:
        return self.skeletal_players.get("enemy_186")

    def _bake_skeletal_frames(self, player: PonosAnimationPlayer, flip_h: bool, scale: float = UNIT_RENDER_SCALE) -> Dict[str, Any]:
        """Pre-renders representative frames for legacy inspection tests while live rendering uses real-time PonosAnimationPlayer."""
        out: Dict[str, Any] = {"walk": [], "attack": [], "kb": [], "walk_rate": 4, "scale": scale, "player": player}
        for anim_key, sample_frames in [("walk", [0, 4, 8, 12]), ("attack", [0, 4, 8, 12]), ("kb", [0])]:
            if anim_key in player.animations:
                player.set_animation(anim_key)
                for f in sample_frames:
                    surf = pygame.Surface((180, 180), pygame.SRCALPHA)
                    player.current_frame = float(f)
                    player.render(surf, 90, 160, scale=scale, flip_h=flip_h)
                    out[anim_key].append(surf)
        player.set_animation("walk")
        return out

    def _init_all_cats(self):
        for cid in range(9):
            code = f"{cid:03d}_f"
            p = self.skeletal_players.get(code)
            if p is not None:
                self.cat_sprites[cid] = self._bake_skeletal_frames(p, flip_h=False, scale=UNIT_RENDER_SCALE)

    def _init_all_enemies(self):
        enemy_ids = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 18, 21, 22]
        for eid in enemy_ids:
            code = f"{eid:03d}_e"
            p = self.skeletal_players.get(code)
            if p is not None:
                self.enemy_sprites[eid] = self._bake_skeletal_frames(p, flip_h=False, scale=UNIT_RENDER_SCALE)

    def trigger_hit_flash(self, unit_id: str, frames: int = 3):
        self.hit_flash_timers[unit_id] = frames

    def get_player_for_unit(self, unit: Any) -> Optional[PonosAnimationPlayer]:
        if isinstance(unit, str):
            from game_project.core.unit_data import CAT_REGISTRY, ENEMY_REGISTRY
            spec = CAT_REGISTRY.get(unit) or ENEMY_REGISTRY.get(unit) or {}
            tc = spec.get("texture_code", "")
            if tc:
                if tc in self.skeletal_players:
                    return self.skeletal_players[tc]
                loaded = self._load_rig(self.asset_dir, tc)
                if loaded is not None:
                    self.skeletal_players[tc] = loaded
                    return loaded
            return self.skeletal_players.get(unit)

        # 1. Check custom_rig or explicit texture_code
        custom_rig = unit.spec.get("custom_rig")
        if isinstance(custom_rig, dict) and unit.key not in self.skeletal_players:
            self.register_custom_rig(
                unit.key,
                custom_rig["png"],
                custom_rig["imgcut"],
                custom_rig["mamodel"],
                custom_rig.get("anims", {})
            )
        if unit.key in self.skeletal_players:
            return self.skeletal_players[unit.key]

        tc = getattr(unit, "texture_code", "") or unit.spec.get("texture_code", "")
        if tc:
            if tc in self.skeletal_players:
                return self.skeletal_players[tc]
            loaded = self._load_rig(self.asset_dir, tc)
            if loaded is not None:
                self.skeletal_players[tc] = loaded
                return loaded

        if unit.team == TEAM_CAT:
            cid = self._resolve_cat_id(unit)
            return self.skeletal_players.get(f"{cid:03d}_f") or self.skeletal_players.get(f"cat_{cid}")
        else:
            eid = self._resolve_enemy_id(unit)
            return self.skeletal_players.get(f"{eid:03d}_e") or self.skeletal_players.get(f"enemy_{eid}")

    def draw_unit(self, surface: pygame.Surface, unit: SimUnit, sx: int, sy: int, frame: int):
        is_kb = unit.is_in_knockback()
        is_atk = unit.is_in_attack_anim() if hasattr(unit, "is_in_attack_anim") else unit.is_winding_up
        is_moving = getattr(unit, "is_moving", True)

        skel = self.get_player_for_unit(unit)
        if skel is not None:
            # Official Ponos Cat rigs (*_f, *_c) are authored facing LEFT.
            # Official Ponos Enemy rigs (*_e) in official_extracted are facing RIGHT.
            img_name = getattr(skel.imgcut, "png_name", "").lower()
            is_enemy_rig = ("_e" in img_name)
            if is_enemy_rig:
                # Naturally faces RIGHT (Team 1); flip if deployed on Team 0 (marching LEFT)
                flip_h = (unit.team == TEAM_CAT)
            else:
                # Naturally faces LEFT (Team 0); flip if deployed on Team 1 (marching RIGHT)
                flip_h = (unit.team == TEAM_ENEMY)

            if is_kb and "kb" in skel.animations:
                skel.set_animation("kb")
                skel.current_frame = float(getattr(unit, "anim_frame", 0.0))
            elif is_atk and "attack" in skel.animations:
                skel.set_animation("attack")
                skel.current_frame = float(getattr(unit, "anim_frame", frame))
            elif not is_moving:
                if "idle" in skel.animations:
                    skel.set_animation("idle")
                    skel.current_frame = float(getattr(unit, "anim_frame", frame))
                else:
                    skel.set_animation("walk")
                    skel.current_frame = 0.0
            else:
                skel.set_animation("walk")
                skel.current_frame = float(getattr(unit, "anim_frame", frame))

            # Scale factor: all official models use uniform UNIT_RENDER_SCALE (1.125 = 720/640) matching native .mamodel proportions
            base_scale = unit.spec.get("render_scale", UNIT_RENDER_SCALE)
            z_off = (unit.slot % 5) * 2 - 4
            # Unit root aligns 1:1 with pos_x and CheckRange hitboxes (matching web/app.js)
            skel.render(surface, sx, sy + 4 + z_off, scale=base_scale, flip_h=flip_h)
            return

    def _resolve_cat_id(self, unit: SimUnit) -> int:
        spec_id = unit.spec.get("id")
        if isinstance(spec_id, int) and 0 <= spec_id < 9:
            return spec_id

        tc = getattr(unit, "texture_code", "") or unit.spec.get("texture_code", "")
        if tc and len(tc) >= 3 and tc[:3].isdigit():
            return int(tc[:3])

        key_map = {
            "cat": 0, "tank_cat": 1, "axe_cat": 2, "gross_cat": 3,
            "cow_cat": 4, "bird_cat": 5, "fish_cat": 6, "lizard_cat": 7, "titan_cat": 8
        }
        return key_map.get(unit.key, 0)

    def _resolve_enemy_id(self, unit: SimUnit) -> int:
        ec = unit.spec.get("enemy_code")
        if isinstance(ec, int):
            return ec

        tc = getattr(unit, "texture_code", "") or unit.spec.get("texture_code", "")
        if tc and len(tc) >= 3 and tc[:3].isdigit():
            return int(tc[:3])

        spec_id = unit.spec.get("id")
        if isinstance(spec_id, int):
            return max(0, spec_id - 2)

        key_map = {
            "doge": 0, "snache": 1, "those_guys": 2, "hippoe": 3, "pigge": 4,
            "jackie_peng": 5, "gory": 6, "baa_baa": 7, "sheep": 7, "sir_seal": 8,
            "le_boin": 9, "kang_roo": 10, "teacher_bear": 11, "croco": 12,
            "shy_boy": 13, "one_horn": 14, "the_face": 18, "ms_sign": 21, "moth": 22
        }
        return key_map.get(unit.key, 0)

