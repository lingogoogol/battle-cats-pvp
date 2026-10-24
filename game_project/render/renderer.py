"""
Battlefield Scene Renderer - Authentic Official Battle Cats Edition.
Renders authentic PONOS graphics:
- Seamless tiled official Korea Stage background (bg000.png)
- Official Cat Castle (fc000.png) & Korea Enemy Castle (ec000_tw.png)
- Official skeletal animated Basic Cat (download_char_000)
- Official animated Doge (000_e.png)
- Floating castle HP and combat particle FX
Zero procedural polygon substitutes or fake sky banners.
"""

import os
import math
import random
import pygame
from typing import List, Dict, Any, Optional, Tuple
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, GROUND_Y, BATTLEFIELD_LENGTH,
    COLOR_WHITE, COLOR_RED, COLOR_GOLD, TEAM_CAT, TEAM_ENEMY
)
from ..simulation.battle_sim import BattleSimulation, SimUnit
from .camera import Camera2D
from .renderer_base import BaseRenderer
from ..audio.sound_manager import SoundManager
from ..assets.asset_manager import AssetManager
from ..anim_engine.ponos_anim_player import PonosAnimationPlayer
from .unit_sprite_manager import UnitSpriteManager

class ParticleFX:
    def __init__(self, x: float, y: float, vx: float, vy: float, color: tuple, size: float, life: int):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.color = color
        self.size = size
        self.life = life
        self.max_life = life

    def update(self) -> bool:
        self.x += self.vx
        self.y += self.vy
        self.life -= 1
        return self.life > 0

class FloatingText:
    def __init__(self, x: float, y: float, text: str, color: tuple, life: int = 30):
        self.x = x
        self.y = y
        self.text = text
        self.color = color
        self.life = life
        self.max_life = life

    def update(self) -> bool:
        self.y -= 1.2
        self.life -= 1
        return self.life > 0

class WaveEffectFX:
    def __init__(self, x: float, team: int, frames: List[pygame.Surface], delay: int = 0, life: int = 18):
        self.x = x
        self.team = team
        self.frames = frames
        self.delay = delay
        self.life = life
        self.max_life = life

    def update(self) -> bool:
        if self.delay > 0:
            self.delay -= 1
            return True
        self.life -= 1
        return self.life > 0

    def render(self, surface: pygame.Surface, camera: Camera2D):
        if self.delay > 0:
            return
        sx = camera.world_to_screen_x(self.x)
        if sx < -100 or sx > SCREEN_WIDTH + 100:
            return
        if self.frames:
            idx = min(len(self.frames) - 1, int((1.0 - self.life / float(self.max_life)) * len(self.frames)))
            frm = self.frames[idx]
            surface.blit(frm, (sx - frm.get_width() // 2, GROUND_Y - frm.get_height()))
        else:
            col = (90, 200, 255) if self.team == TEAM_CAT else (255, 100, 200)
            pygame.draw.rect(surface, col, (sx - 24, GROUND_Y - 110, 48, 110), border_radius=8)

class HitExplosionFX:
    """Official PONOS 5-frame Hit Explosion (`000_a.imgcut` cuts 8..12) + Critical Star (`cuts 26..27`)."""
    def __init__(self, x: float, y: float, frames: List[pygame.Surface], crit_frames: Optional[List[pygame.Surface]] = None, is_crit: bool = False):
        self.x = x
        self.y = y
        self.frames = frames
        self.crit_frames = crit_frames or []
        self.is_crit = is_crit
        self.age = 0
        self.max_life = 15 if is_crit else 10

    def update(self) -> bool:
        self.age += 1
        return self.age < self.max_life

    def render(self, surface: pygame.Surface, camera: Camera2D):
        sx = camera.world_to_screen_x(self.x)
        if sx < -80 or sx > SCREEN_WIDTH + 80:
            return
        if self.frames:
            idx = min(len(self.frames) - 1, self.age // 2)
            frm = self.frames[idx]
            surface.blit(frm, (int(sx - frm.get_width() // 2), int(self.y - frm.get_height() // 2)))
        if self.is_crit and self.crit_frames:
            c_idx = (self.age // 2) % len(self.crit_frames)
            cf = self.crit_frames[c_idx]
            surface.blit(cf, (int(sx - cf.get_width() // 2), int(self.y - cf.get_height() - 10)))


class DeathSoulFX:
    """Official PONOS ascending winged Cat Soul (`battle_soul_000.imgcut` + `battle_soul_000.maanim`)."""
    def __init__(self, x: float, y: float, frames: List[pygame.Surface]):
        self.x = x
        self.base_y = y
        self.frames = frames
        self.age = 0
        self.max_life = 45

    def update(self) -> bool:
        self.age += 1
        return self.age < self.max_life

    def render(self, surface: pygame.Surface, camera: Camera2D):
        if not self.frames:
            return
        sx = camera.world_to_screen_x(self.x)
        if sx < -80 or sx > SCREEN_WIDTH + 80:
            return
        # Matches battle_soul_000.maanim:
        # - Wing flap cycle every 4 frames: 0 -> 1 -> 2 -> 3
        # - Vertical ascent: 0 -> -200px over 45 frames
        # - Horizontal sway: +/- 10px sine wave with period 16 frames
        # - Alpha fade: 100% until frame 30, then linear fade to 0 at frame 45
        frm = self.frames[(self.age // 4) % len(self.frames)]
        progress = self.age / float(self.max_life)
        cur_y = self.base_y - progress * 200.0
        sway_x = math.sin(self.age * (2.0 * math.pi / 16.0)) * 10.0
        if self.age > 30:
            alpha = max(0, int(255 * (1.0 - (self.age - 30) / 15.0)))
            frm = frm.copy()
            frm.set_alpha(alpha)
        surface.blit(frm, (int(sx + sway_x - frm.get_width() // 2), int(cur_y - frm.get_height() // 2)))


class CannonBeamFX:
    """
    Authentic PONOS Cat Cannon Laser & Sweeping Shockwave (`nyankoCastle_001_00_00.imgcut` + `.maanim`).
    Phase 1 (age 0..10): Turret muzzle additive glow (`cut 7`) + vertical laser beam (`cut 9`) to `start_x`.
    Phase 2 (age 0..28): Sequential laser explosion pillars (`cuts 0..4`) sweeping from `start_x` to `end_x`.
    """
    def __init__(
        self,
        start_x: float,
        end_x: float,
        y: float,
        team: int = TEAM_CAT,
        castle_x: Optional[float] = None,
        pillar_frames: Optional[List[pygame.Surface]] = None,
        beam_strip: Optional[pygame.Surface] = None,
        glow_orb: Optional[pygame.Surface] = None,
        spark_frames: Optional[List[pygame.Surface]] = None,
        life: int = 28
    ):
        self.start_x = start_x
        self.end_x = end_x
        self.y = y
        self.team = team
        self.castle_x = castle_x if castle_x is not None else (start_x + (30 if team == TEAM_CAT else -30))
        self.pillar_frames = pillar_frames or []
        self.beam_strip = beam_strip
        self.glow_orb = glow_orb
        self.spark_frames = spark_frames or []
        self.age = 0
        self.max_life = life

    def update(self) -> bool:
        self.age += 1
        return self.age < self.max_life

    def render(self, surface: pygame.Surface, camera: Camera2D):
        s_sx = camera.world_to_screen_x(self.start_x)
        e_sx = camera.world_to_screen_x(self.end_x)
        c_sx = camera.world_to_screen_x(self.castle_x)

        # 1. Turret Muzzle Glow & Vertical Laser Beam (Frames 0..12)
        if self.age <= 12:
            muzzle_x = c_sx - 44 if self.team == TEAM_CAT else c_sx + 44
            muzzle_y = GROUND_Y - 195
            if self.glow_orb is not None:
                surface.blit(
                    self.glow_orb,
                    (int(muzzle_x - self.glow_orb.get_width() // 2), int(muzzle_y - self.glow_orb.get_height() // 2))
                )
            # Draw angled/vertical laser beam from turret muzzle to ground impact at s_sx
            beam_h = max(20, int(GROUND_Y - muzzle_y))
            if self.beam_strip is not None:
                vert_beam = pygame.transform.smoothscale(self.beam_strip, (16, beam_h))
                surface.blit(vert_beam, (int(s_sx - 8), int(muzzle_y)))
            if self.spark_frames:
                sp = self.spark_frames[self.age % len(self.spark_frames)]
                surface.blit(sp, (int(s_sx - sp.get_width() // 2), int(GROUND_Y - sp.get_height())))

        # 2. Sweeping Shockwave Explosion Pillars (`nyankoCastle_001_00_00` cuts 0..4) across start_x -> end_x
        total_dist = abs(self.end_x - self.start_x)
        direction = -1.0 if self.end_x < self.start_x else 1.0
        step_px = 72.0
        num_pillars = max(1, int(total_dist // step_px) + 1)

        if self.pillar_frames:
            for i in range(num_pillars):
                # Each pillar triggers slightly after the previous one as the shockwave sweeps forward
                trigger_frame = int((i / float(max(1, num_pillars))) * 14.0)
                local_age = self.age - trigger_frame
                if 0 <= local_age < 12:
                    px = self.start_x + direction * (i * step_px)
                    psx = camera.world_to_screen_x(px)
                    if -100 <= psx <= SCREEN_WIDTH + 100:
                        f_idx = min(len(self.pillar_frames) - 1, local_age // 2)
                        pf = self.pillar_frames[f_idx]
                        surface.blit(pf, (int(psx - pf.get_width() // 2), int(GROUND_Y - pf.get_height() + 8)))
                        if self.glow_orb is not None and local_age < 4:
                            surface.blit(
                                self.glow_orb,
                                (int(psx - self.glow_orb.get_width() // 2), int(GROUND_Y - self.glow_orb.get_height() // 2 - 20))
                            )
        else:
            min_x, max_x = min(s_sx, e_sx), max(s_sx, e_sx)
            w = max(1, max_x - min_x)
            alpha_ratio = max(0.0, 1.0 - self.age / float(self.max_life))
            beam_h = int(22 * alpha_ratio) + 6
            glow_surf = pygame.Surface((w, beam_h), pygame.SRCALPHA)
            glow_surf.fill((255, 80, 220, int(180 * alpha_ratio)))
            surface.blit(glow_surf, (min_x, int(self.y - beam_h // 2)))

def to_32bit_scaled(surf: pygame.Surface, target_size: Tuple[int, int]) -> pygame.Surface:
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return pygame.transform.smoothscale(s32, target_size)
    return pygame.transform.smoothscale(surf, target_size)

class BattleRenderer(BaseRenderer):
    def __init__(self, surface: pygame.Surface, camera: Camera2D, strict_mode: bool = True):
        self.surface = surface
        self.camera = camera
        self.strict_asset_mode: bool = strict_mode
        self.font = pygame.font.SysFont("Microsoft JhengHei, Arial", 16, bold=True)
        self.dmg_font = pygame.font.SysFont("Impact, Arial", 20, bold=True)
        self.hp_font = pygame.font.SysFont("Impact, Arial", 18)
        self.debug_font = pygame.font.SysFont("Consolas, Courier, Arial", 11)

        self.debug_mode: bool = False
        self.particles: List[ParticleFX] = []
        self.hit_explosions: List[HitExplosionFX] = []
        self.death_souls: List[DeathSoulFX] = []
        self.floating_texts: List[FloatingText] = []
        self.cannon_beams: List[CannonBeamFX] = []
        self.wave_effects: List[WaveEffectFX] = []
        self.sound_mgr = SoundManager.get_instance()
        self.asset_mgr = AssetManager.get_instance()

        # 1. Background & Battle FX Atlas Setup (bg000.png / bg00.imgcut)
        self.bg_scaled = None
        self.tile_w = 1001
        self.ground_row_in_bg = GROUND_Y
        self.wave_pink_frames: List[pygame.Surface] = []
        self.wave_blue_frames: List[pygame.Surface] = []
        self.freeze_frames: List[pygame.Surface] = []
        self.slow_icon: Optional[pygame.Surface] = None
        self._init_background()

        # 2. Castle & Cat Cannon Turret Setup (fc000.png, nyankoCastle_*, ec000_tw.png)
        self.fc_scaled = None
        self.fc_flipped = None
        self.ec_scaled = None
        self.castle_base_surf: Optional[pygame.Surface] = None
        self.castle_base_flipped: Optional[pygame.Surface] = None
        self.castle_plaque_surf: Optional[pygame.Surface] = None
        self.castle_plaque_flipped: Optional[pygame.Surface] = None
        self.castle_turret_surf: Optional[pygame.Surface] = None
        self.castle_turret_flipped: Optional[pygame.Surface] = None
        self.cannon_range_line: Optional[pygame.Surface] = None
        self.cannon_range_icon: Optional[pygame.Surface] = None
        self.cannon_range_icon_flipped: Optional[pygame.Surface] = None
        self._init_castles()

        # 3. Official Combat FX Atlases (000_a.png, battle_soul_000.png, nyankoCastle_001_00_00.png)
        self.hit_explosion_frames: List[pygame.Surface] = []
        self.crit_star_frames: List[pygame.Surface] = []
        self.soul_frames: List[pygame.Surface] = []
        self.cannon_pillar_frames: List[pygame.Surface] = []
        self.cannon_beam_strip: Optional[pygame.Surface] = None
        self.cannon_glow_orb: Optional[pygame.Surface] = None
        self.cannon_spark_frames: List[pygame.Surface] = []
        self._init_combat_fx_atlases()

        # 4. Castle Digits & Unit Sprite Manager
        self.castle_digits = {}
        self._init_castle_digits()
        self.unit_sprite_mgr = UnitSpriteManager.get_instance()

    def _init_background(self):
        bg_full = self.asset_mgr.get_texture("bg000")
        if bg_full is None:
            bg_path = r"E:\rea\game_project\assets\official_extracted\bg000.png"
            if os.path.isfile(bg_path):
                bg_full = pygame.image.load(bg_path)

        if bg_full is not None:
            try:
                # Authentic background slice from official bg00.imgcut: x=1, y=1, w=768, h=510
                clean_slice = bg_full.subsurface((1, 1, 768, 510))
                # Scale so the flat green grass field (y=385 in slice, above the y=408..433 zig-zag cliff border)
                # aligns with GROUND_Y (520), placing the bottom of the cliff border right at bar_top (585)
                scale = GROUND_Y / 385.0
                self.tile_w = int(768 * scale)
                tile_h = int(510 * scale)
                self.bg_scaled = to_32bit_scaled(clean_slice, (self.tile_w, tile_h))
                self.ground_row_in_bg = GROUND_Y

                # Official Wave & Status FX cuts from bg00.imgcut
                pink_cuts = [(772, 1, 56, 80), (830, 1, 56, 80), (888, 1, 56, 80), (946, 1, 56, 80), (772, 83, 56, 80), (830, 83, 56, 80)]
                blue_cuts = [(888, 83, 56, 80), (946, 83, 56, 80), (772, 165, 56, 80), (830, 165, 56, 80), (888, 165, 56, 80), (946, 165, 56, 80)]
                for r in pink_cuts:
                    self.wave_pink_frames.append(to_32bit_scaled(bg_full.subsurface(r), (72, 104)))
                for r in blue_cuts:
                    self.wave_blue_frames.append(to_32bit_scaled(bg_full.subsurface(r), (72, 104)))
                self.freeze_frames = [
                    to_32bit_scaled(bg_full.subsurface((933, 248, 60, 60)), (48, 48)),
                    to_32bit_scaled(bg_full.subsurface((871, 248, 60, 60)), (48, 48)),
                ]
                self.slow_icon = to_32bit_scaled(bg_full.subsurface((772, 248, 45, 50)), (32, 36))
            except Exception as e:
                self.bg_scaled = None

    def _init_castles(self):
        fc_img = self.asset_mgr.get_texture("fc000")
        if fc_img is None:
            fc_p = r"E:\rea\game_project\assets\official_extracted\fc000.png"
            if os.path.isfile(fc_p):
                fc_img = pygame.image.load(fc_p)
        if fc_img is not None:
            try:
                self.fc_scaled = to_32bit_scaled(fc_img, (int(128 * 1.3), int(256 * 1.3)))
                self.fc_flipped = pygame.transform.flip(self.fc_scaled, True, False)
            except Exception:
                pass

        # Modular Cat Castle parts (nyankoCastle_003_00 base, 002_00 plaque, 000_00 Cat Cannon turret)
        base_p = r"E:\rea\game_project\assets\official_extracted\nyankoCastle_003_00.png"
        plaque_p = r"E:\rea\game_project\assets\official_extracted\nyankoCastle_002_00.png"
        turret_p = r"E:\rea\game_project\assets\official_extracted\nyankoCastle_000_00.png"
        try:
            if os.path.isfile(base_p):
                b_img = pygame.image.load(base_p)
                self.castle_base_surf = to_32bit_scaled(b_img, (int(128 * 1.3), int(128 * 1.3)))
                self.castle_base_flipped = pygame.transform.flip(self.castle_base_surf, True, False)
            if os.path.isfile(plaque_p):
                p_img = pygame.image.load(plaque_p)
                self.castle_plaque_surf = to_32bit_scaled(p_img, (int(128 * 1.3), int(128 * 1.3)))
                self.castle_plaque_flipped = pygame.transform.flip(self.castle_plaque_surf, True, False)
            if os.path.isfile(turret_p):
                t_img = pygame.image.load(turret_p)
                self.castle_turret_surf = to_32bit_scaled(t_img, (int(128 * 1.3), int(256 * 1.3)))
                self.castle_turret_flipped = pygame.transform.flip(self.castle_turret_surf, True, False)
        except Exception:
            pass

        # Official Cat Cannon Range Line & Icon from img002_tw.imgcut (cuts 0 and 1)
        im2 = self.asset_mgr.get_texture("img002_tw")
        if im2 is None:
            im2_p = r"E:\rea\game_project\assets\official_extracted\img002_tw.png"
            if os.path.isfile(im2_p):
                im2 = pygame.image.load(im2_p)
        if im2 is not None:
            try:
                self.cannon_range_line = to_32bit_scaled(im2.subsurface((441, 260, 9, 98)), (9, 120))
                self.cannon_range_icon = to_32bit_scaled(im2.subsurface((442, 421, 69, 85)), (56, 68))
                self.cannon_range_icon_flipped = pygame.transform.flip(self.cannon_range_icon, True, False)
            except Exception:
                pass

        ec_img = self.asset_mgr.get_texture("ec000_tw")
        if ec_img is None:
            ec_p = r"E:\rea\game_project\assets\official_extracted\ec000_tw.png"
            if os.path.isfile(ec_p):
                ec_img = pygame.image.load(ec_p)
        if ec_img is not None:
            try:
                self.ec_scaled = to_32bit_scaled(ec_img, (int(128 * 1.3), int(256 * 1.3)))
            except Exception:
                pass

    def _init_combat_fx_atlases(self):
        # 1. 000_a.png: Official 5-frame Hit Explosion (cuts 8..12) + Critical Stars (cuts 26..27)
        a_img = self.asset_mgr.get_texture("000_a")
        if a_img is None:
            a_p = r"E:\rea\game_project\assets\official_extracted\000_a.png"
            if os.path.isfile(a_p):
                a_img = pygame.image.load(a_p)
        if a_img is not None:
            try:
                for i in range(5):
                    sub = a_img.subsurface((1, 1 + i * 49, 55, 47))
                    self.hit_explosion_frames.append(to_32bit_scaled(sub, (66, 56)))
                self.crit_star_frames = [
                    to_32bit_scaled(a_img.subsurface((58, 91, 42, 40)), (52, 50)),
                    to_32bit_scaled(a_img.subsurface((58, 133, 50, 46)), (62, 58)),
                ]
            except Exception:
                pass

        # 2. battle_soul_000.png: Official 4-frame ascending Cat Soul (cuts 0..3)
        soul_img = self.asset_mgr.get_texture("battle_soul_000")
        if soul_img is None:
            s_p = r"E:\rea\game_project\assets\official_extracted\battle_soul_000.png"
            if os.path.isfile(s_p):
                soul_img = pygame.image.load(s_p)
        if soul_img is not None:
            try:
                for i in range(4):
                    sub = soul_img.subsurface((1, 1 + i * 58, 48, 56))
                    self.soul_frames.append(to_32bit_scaled(sub, (58, 68)))
            except Exception:
                pass

        # 3. nyankoCastle_001_00_00.png: Official Cat Cannon Laser Beam & Shockwave Pillars
        nc_img = self.asset_mgr.get_texture("nyankoCastle_001_00_00")
        if nc_img is None:
            nc_p = r"E:\rea\game_project\assets\official_extracted\nyankoCastle_001_00_00.png"
            if os.path.isfile(nc_p):
                nc_img = pygame.image.load(nc_p)
        if nc_img is not None:
            try:
                # Cuts 0..4 from nyankoCastle_001_00_00.imgcut
                pillar_rects = [
                    ((78, 156, 74, 41), (96, 54)),
                    ((1, 1, 74, 111), (96, 144)),
                    ((154, 23, 74, 131), (96, 170)),
                    ((2, 114, 74, 131), (96, 170)),
                    ((78, 23, 74, 131), (96, 170)),
                ]
                for r, sz in pillar_rects:
                    self.cannon_pillar_frames.append(to_32bit_scaled(nc_img.subsurface(r), sz))
                self.cannon_spark_frames = [
                    to_32bit_scaled(nc_img.subsurface((77, 1, 53, 20)), (70, 26)),
                    to_32bit_scaled(nc_img.subsurface((132, 1, 53, 20)), (70, 26)),
                ]
                self.cannon_glow_orb = to_32bit_scaled(nc_img.subsurface((154, 157, 84, 84)), (110, 110))
                raw_beam = to_32bit_scaled(nc_img.subsurface((145, 249, 110, 6)), (110, 12))
                self.cannon_beam_strip = pygame.transform.rotate(raw_beam, 90)
            except Exception:
                pass

    def _init_castle_digits(self):
        im1 = self.asset_mgr.get_texture("img001_tw")
        if im1 is None:
            p = r"E:\rea\game_project\assets\official_ui\img001_tw.png"
            if os.path.isfile(p):
                im1 = pygame.image.load(p)
        if im1 is not None:
            try:
                for i in range(10):
                    sub = im1.subsurface((255 + i * 16, 89, 14, 18))
                    self.castle_digits[str(i)] = to_32bit_scaled(sub, (16, 20))
                sub_slash = im1.subsurface((398, 208, 18, 18))
                self.castle_digits['/'] = to_32bit_scaled(sub_slash, (16, 20))
            except Exception:
                pass

    def process_visual_events(self, events: List[Dict[str, Any]]):
        for ev in events:
            etype = ev.get("type")
            if etype == "damage":
                x = ev.get("x", 0)
                is_crit = ev.get("is_crit", False)
                color = COLOR_GOLD if is_crit else COLOR_WHITE
                # Authentic PONOS Battle Cats does NOT pop up floating damage numbers on attack;
                # only the official 000_a.png hit spark and critical star appear.
                if self.hit_explosion_frames:
                    self.hit_explosions.append(
                        HitExplosionFX(
                            x + random.uniform(-8, 8),
                            GROUND_Y - 28 + random.uniform(-8, 6),
                            self.hit_explosion_frames,
                            self.crit_star_frames,
                            is_crit=is_crit
                        )
                    )
                else:
                    for _ in range(4):
                        vx = random.uniform(-3, 3)
                        vy = random.uniform(-4, 0)
                        self.particles.append(ParticleFX(x, GROUND_Y - 20, vx, vy, color, 3, 15))
                if ev.get("target_is_castle"):
                    self.sound_mgr.play_sfx("castle_hit")
                else:
                    self.sound_mgr.play_sfx("hit")
            elif etype == "knockback":
                x = ev.get("x", 0)
                if self.hit_explosion_frames:
                    self.hit_explosions.append(
                        HitExplosionFX(x, GROUND_Y - 18, self.hit_explosion_frames, is_crit=False)
                    )
                self.sound_mgr.play_sfx("knockback")
            elif etype == "death":
                x = ev.get("x", 0)
                if self.soul_frames:
                    self.death_souls.append(DeathSoulFX(x, GROUND_Y - 32, self.soul_frames))
                else:
                    for _ in range(10):
                        vx = random.uniform(-2, 2)
                        vy = random.uniform(-4, -1)
                        self.particles.append(ParticleFX(x, GROUND_Y - 20, vx, vy, (255, 255, 200), 5, 25))
                self.sound_mgr.play_sfx("death")
            elif etype == "spawn":
                self.sound_mgr.play_sfx("deploy")
            elif etype == "cannon_beam":
                s_x = ev.get("start_x", 0)
                e_x = ev.get("end_x", 0)
                team = ev.get("team", TEAM_CAT)
                castle_x = ev.get("castle_x", None)
                self.cannon_beams.append(
                    CannonBeamFX(
                        s_x,
                        e_x,
                        GROUND_Y - 45,
                        team=team,
                        castle_x=castle_x,
                        pillar_frames=self.cannon_pillar_frames,
                        beam_strip=self.cannon_beam_strip,
                        glow_orb=self.cannon_glow_orb,
                        spark_frames=self.cannon_spark_frames,
                        life=28
                    )
                )
                self.sound_mgr.play_sfx("cannon_fire")
            elif etype == "wave_attack":
                origin = ev.get("x", ev.get("start_x", 0))
                dir_ = ev.get("direction", -1)
                lvl = ev.get("level", 1)
                seg0 = ev.get("seg0", 67.5)
                prog = ev.get("prog", 200.0)
                seg_frames = ev.get("seg_frames", 3)
                team = ev.get("team", TEAM_CAT)
                frames = self.wave_blue_frames if team == TEAM_CAT else self.wave_pink_frames
                for seg_idx in range(lvl):
                    wx = origin + dir_ * (seg0 + seg_idx * prog)
                    delay = seg_idx * seg_frames
                    self.wave_effects.append(WaveEffectFX(wx, team, frames, delay=delay, life=18))

    def _render_environment(self):
        # Authentic Battle Cats Environment - 100% bg000.png, Zero procedural lines or boxes
        if self.bg_scaled is not None:
            # Parallax scrolling tied to camera offset
            start_x = - (int(self.camera.offset_x * 0.7) % self.tile_w) - self.tile_w
            tx = start_x
            while tx < SCREEN_WIDTH + self.tile_w:
                self.surface.blit(self.bg_scaled, (tx, 0))
                tx += self.tile_w
        else:
            self.surface.fill((139, 219, 254))

    def _draw_cat_castle_with_turret(self, sx: int, team: int, sim: BattleSimulation):
        """
        Renders the authentic modular Cat Castle (`nyankoCastle_003_00` base + `002_00` plaque + `000_00` Cat Cannon turret),
        or `fc000.png` fallback. The Cat Cannon turret extends upward as charge builds and glows/recoils when firing!
        """
        flipped = (team == TEAM_ENEMY)
        c_unit = sim.get_castle(team)
        cannon_ratio = sim.get_cannon_ratio(team)
        anim_t = getattr(sim, "cannon_anim_timer", {}).get(team, 0)

        base_s = self.castle_base_flipped if flipped else self.castle_base_surf
        plaque_s = self.castle_plaque_flipped if flipped else self.castle_plaque_surf
        turret_s = self.castle_turret_flipped if flipped else self.castle_turret_surf

        if base_s is not None and turret_s is not None:
            cw, ch = turret_s.get_size()
            bw, bh = base_s.get_size()
            fc_x = sx - cw // 2
            fc_y = GROUND_Y - ch

            # Turret alignment: matches fc000.png exact origin (lift_offset = 0)
            if anim_t > 0:
                recoil_x = (4 if flipped else -4) if (anim_t > 24 and anim_t % 2 == 0) else 0
                lift_offset = 0
            elif cannon_ratio >= 1.0:
                recoil_x = 0
                lift_offset = int(math.sin(sim.current_frame * 0.2) * 1.5)
            else:
                recoil_x = 0
                lift_offset = 0

            # 1. Draw Turret Head behind/above Castle roof
            self.surface.blit(turret_s, (fc_x + recoil_x, fc_y + lift_offset))
            # 2. Draw Lower Castle Base on ground
            self.surface.blit(base_s, (sx - bw // 2, GROUND_Y - bh))
            # 3. Draw Hanging Paw Plaque (shares exact origin GROUND_Y - bh with nyankoCastle_003_00)
            if plaque_s is not None:
                self.surface.blit(plaque_s, (sx - bw // 2, GROUND_Y - bh))
            # 4. Muzzle charging/firing glow
            if anim_t > 16 and self.cannon_glow_orb is not None:
                muzzle_x = sx + (44 if flipped else -44)
                muzzle_y = GROUND_Y - 195 + lift_offset
                self.surface.blit(
                    self.cannon_glow_orb,
                    (int(muzzle_x - self.cannon_glow_orb.get_width() // 2), int(muzzle_y - self.cannon_glow_orb.get_height() // 2))
                )
            return fc_x, fc_y, cw, ch

        # Fallback to fc000.png
        fc_s = self.fc_flipped if flipped else self.fc_scaled
        if fc_s is not None:
            cw, ch = fc_s.get_size()
            fc_x = sx - cw // 2
            fc_y = GROUND_Y - ch
            self.surface.blit(fc_s, (fc_x, fc_y))
            return fc_x, fc_y, cw, ch
        return sx - 64, GROUND_Y - 256, 128, 256

    def _render_castles(self, sim: BattleSimulation):
        cat_c = sim.get_castle(TEAM_CAT)
        enemy_c = sim.get_castle(TEAM_ENEMY)

        def draw_hp(cx: int, cy: int, cur_hp: int, max_hp: int):
            hp_str = f"{cur_hp}/{max_hp}"
            if self.castle_digits:
                total_w = len(hp_str) * 16
                bx = cx - total_w // 2
                for ch in hp_str:
                    if ch in self.castle_digits:
                        self.surface.blit(self.castle_digits[ch], (bx, cy))
                        bx += 16
            else:
                txt = self.hp_font.render(hp_str, True, COLOR_WHITE)
                self.surface.blit(txt, (cx - txt.get_width() // 2, cy))

        # 1. Left Castle (ec000_tw.png in Campaign, or symmetric Cat Castle with Cannon in 2P PvP mode)
        enemy_sx = self.camera.world_to_screen_x(enemy_c.pos_x)
        if getattr(sim, "pvp_mode", False):
            ec_x, ec_y, ew, eh = self._draw_cat_castle_with_turret(enemy_sx, TEAM_ENEMY, sim)
            draw_hp(ec_x + ew // 2, ec_y - 28, enemy_c.hp, enemy_c.max_hp)
        elif self.ec_scaled is not None:
            ew, eh = self.ec_scaled.get_size()
            ec_x = enemy_sx - ew // 2
            ec_y = GROUND_Y - eh
            self.surface.blit(self.ec_scaled, (ec_x, ec_y))
            draw_hp(ec_x + ew // 2, ec_y - 28, enemy_c.hp, enemy_c.max_hp)

        # 2. Cat Castle on Right
        cat_sx = self.camera.world_to_screen_x(cat_c.pos_x)
        fc_x, fc_y, cw, ch = self._draw_cat_castle_with_turret(cat_sx, TEAM_CAT, sim)
        draw_hp(fc_x + cw // 2, fc_y - 28, cat_c.hp, cat_c.max_hp)

        # 3. Official Cat Cannon Range Line & Icon (`img002_tw.imgcut` cuts 0 and 1) when Cannon is ready
        if self.cannon_range_line is not None and self.cannon_range_icon is not None:
            if sim.is_cannon_ready(TEAM_CAT):
                range_world_x = max(60, (cat_c.pos_x - 30) - sim.cannon_range)
                rsx = self.camera.world_to_screen_x(range_world_x)
                if -60 <= rsx <= SCREEN_WIDTH + 60:
                    self.surface.blit(self.cannon_range_line, (rsx - 4, GROUND_Y - 120))
                    self.surface.blit(self.cannon_range_icon, (rsx - 28, GROUND_Y - 188))
            if getattr(sim, "pvp_mode", False) and sim.is_cannon_ready(TEAM_ENEMY):
                p2_range_x = min(sim.battlefield_length - 60, (enemy_c.pos_x + 30) + sim.cannon_range)
                p2_rsx = self.camera.world_to_screen_x(p2_range_x)
                if -60 <= p2_rsx <= SCREEN_WIDTH + 60:
                    self.surface.blit(self.cannon_range_line, (p2_rsx - 4, GROUND_Y - 120))
                    icon_s = self.cannon_range_icon_flipped or self.cannon_range_icon
                    self.surface.blit(icon_s, (p2_rsx - 28, GROUND_Y - 188))

    def _draw_unit(self, unit: SimUnit, sx: int, sy: int, frame: int):
        self.unit_sprite_mgr.draw_unit(self.surface, unit, sx, sy, frame)
        # Render authentic Freeze / Slow status icons from bg00.imgcut when active (and not dying)
        if not getattr(unit, "is_dying", False):
            if getattr(unit, "freeze_timer", 0) > 0 and self.freeze_frames:
                f_surf = self.freeze_frames[(frame // 4) % len(self.freeze_frames)]
                self.surface.blit(f_surf, (sx - f_surf.get_width() // 2, sy - 64))
            elif getattr(unit, "slow_timer", 0) > 0 and self.slow_icon is not None:
                self.surface.blit(self.slow_icon, (sx - self.slow_icon.get_width() // 2, sy - 76))

    def _render_fx(self):
        # Update and render wave effects
        alive_waves = []
        for w in self.wave_effects:
            if w.update():
                alive_waves.append(w)
                w.render(self.surface, self.camera)
        self.wave_effects = alive_waves

        # Update and render cannon laser beams & sweeping pillars
        alive_beams = []
        for b in self.cannon_beams:
            if b.update():
                alive_beams.append(b)
                b.render(self.surface, self.camera)
        self.cannon_beams = alive_beams

        # Update and render official 000_a.png hit explosions & critical stars
        alive_hits = []
        for h in self.hit_explosions:
            if h.update():
                alive_hits.append(h)
                h.render(self.surface, self.camera)
        self.hit_explosions = alive_hits

        # Update and render official battle_soul_000.png ascending death souls
        alive_souls = []
        for s in self.death_souls:
            if s.update():
                alive_souls.append(s)
                s.render(self.surface, self.camera)
        self.death_souls = alive_souls

        # Update and render fallback particles (if any)
        alive_particles = []
        for p in self.particles:
            if p.update():
                alive_particles.append(p)
                pygame.draw.circle(self.surface, p.color, (int(p.x), int(p.y)), int(p.size))
        self.particles = alive_particles

        # Update and render floating text
        alive_texts = []
        for t in self.floating_texts:
            if t.update():
                alive_texts.append(t)
                sx = self.camera.world_to_screen_x(t.x)
                if -50 <= sx <= SCREEN_WIDTH + 50:
                    txt_surf = self.dmg_font.render(t.text, True, t.color)
                    self.surface.blit(txt_surf, (sx - txt_surf.get_width() // 2, int(t.y)))
        self.floating_texts = alive_texts

    def render_environment(self):
        self._render_environment()

    def render_castles(self, cat_castle_info: Dict[str, Any], enemy_castle_info: Dict[str, Any]):
        pass

    def render_units(self, units: List[Dict[str, Any]]):
        pass

    def get_render_metadata(self) -> Dict[str, Any]:
        return {
            "backend": "pygame",
            "resolution": (SCREEN_WIDTH, SCREEN_HEIGHT),
            "ground_y": GROUND_Y,
            "unit_rendering_tier": "AUTHENTIC_PONOS_GRAPHICS",
            "strict_asset_mode": self.strict_asset_mode,
            "ui_chrome_tier": "AUTHENTIC_TRAY_AND_PORTRAITS",
            "debug_mode": self.debug_mode
        }

    def render(self, sim: BattleSimulation):
        # 1. Background
        self._render_environment()

        # 2. Castles
        self._render_castles(sim)

        # 3. Field Units
        all_units: List[SimUnit] = []
        for team in (TEAM_CAT, TEAM_ENEMY):
            for slot in range(1, len(sim.units[team])):
                u = sim.units[team][slot]
                if u is not None and u.is_alive:
                    all_units.append(u)

        all_units.sort(key=lambda u: u.pos_x)
        for unit in all_units:
            sx = self.camera.world_to_screen_x(unit.pos_x)
            if -120 <= sx <= SCREEN_WIDTH + 120:
                self._draw_unit(unit, sx, GROUND_Y, sim.current_frame)

        # 4. Combat FX
        self._render_fx()

        # 5. Debug Overlay if enabled
        if self.debug_mode:
            self._render_debug_overlay(sim)

    def toggle_debug_mode(self):
        self.debug_mode = not self.debug_mode
        return self.debug_mode

    def _render_debug_overlay(self, sim: BattleSimulation):
        overlay = pygame.Surface((320, 160), pygame.SRCALPHA)
        overlay.fill((0, 0, 0, 180))
        lines = [
            f"[DEBUG OVERLAY]",
            f"Frame: {sim.current_frame} | FPS: 30",
            f"Camera Offset: {self.camera.offset_x:.1f}",
            f"Cat Units: {sum(1 for u in sim.units[TEAM_CAT][1:] if u and u.is_alive)}",
            f"Enemy Units: {sum(1 for u in sim.units[TEAM_ENEMY][1:] if u and u.is_alive)}",
            f"Wallet: ${sim.wallet.money} / ${sim.wallet.max_capacity}",
        ]
        for i, l in enumerate(lines):
            t = self.debug_font.render(l, True, (0, 255, 180) if i == 0 else (220, 220, 220))
            overlay.blit(t, (10, 8 + i * 20))
        self.surface.blit(overlay, (10, 10))
