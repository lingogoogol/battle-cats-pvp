"""
Official Battle Cats Deployment Bar UI.
Renders authentic Worker Cat button, Cat Cannon button, and authentic deployment cards with official PONOS uni portraits and digit cuts.
Zero distorted repeating paw graphics or homemade placeholder text.
"""

import os
import pygame
from typing import Optional, Tuple, Dict, Any, Callable
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, COLOR_GOLD, COLOR_GRAY, COLOR_RED, TEAM_CAT, TEAM_ENEMY
)
from ..simulation.battle_sim import BattleSimulation
from ..assets.asset_manager import AssetManager
from ..audio.sound_manager import SoundManager

def to_32bit(surf: pygame.Surface) -> pygame.Surface:
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return s32
    return surf

class DeployBarUI:
    BAR_HEIGHT = 135
    CARD_WIDTH = 114
    CARD_HEIGHT = 92

    UNIT_PORTRAIT_MAP = {
        "cat": "uni000_f00",
        "tank_cat": "uni001_f00",
        "axe_cat": "uni002_f00",
        "gross_cat": "uni003_f00",
        "cow_cat": "uni004_f00",
        "bird_cat": "uni005_f00",
        "fish_cat": "uni006_f00",
        "lizard_cat": "uni007_f00",
        "titan_cat": "uni008_f00",
        0: "uni000_f00",
        1: "uni001_f00",
        2: "uni002_f00",
        3: "uni003_f00",
        4: "uni004_f00",
        5: "uni005_f00",
        6: "uni006_f00",
        7: "uni007_f00",
        8: "uni008_f00",
    }

    def __init__(self):
        self.bar_top = SCREEN_HEIGHT - self.BAR_HEIGHT

        # 1. Worker Cat button on Left
        self.worker_btn_rect = pygame.Rect(16, self.bar_top + 10, 168, 112)

        # 2. Cat Cannon button on Right
        self.cannon_btn_rect = pygame.Rect(SCREEN_WIDTH - 184, self.bar_top + 10, 168, 112)

        # 3. 5 Unit Card Slots in Center
        self.card_rects = []
        start_x = 200
        spacing = 14
        for i in range(5):
            r = pygame.Rect(start_x + i * (self.CARD_WIDTH + spacing), self.bar_top + 18, self.CARD_WIDTH, self.CARD_HEIGHT)
            self.card_rects.append(r)

        # 4. Deck Page Switch Button (between cards and Cannon)
        self.current_page = 0
        self.page_btn_rect = pygame.Rect(854, self.bar_top + 30, 96, 68)
        self.page_font = pygame.font.SysFont("Impact, Arial", 18, bold=True)
        self.page_sub_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 12, bold=True)

        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()

        self.im1 = self.asset_mgr.get_texture("img001_tw")
        self.im2 = self.asset_mgr.get_texture("img002_tw")
        self.card_bg = self.asset_mgr.get_texture("card_bg")

        self.w_on = None
        self.w_blink = None
        self.w_off = None
        self.c_full = None
        self.c_blink = None
        self.c_off = None
        self.c_ready_font_on = None
        self.c_ready_font_blink = None
        self.summon_ok_badge = None
        self.yellow_border = None
        self.card_portraits: Dict[Any, pygame.Surface] = {}

        # Official digit cuts
        self.small_digits: Dict[str, pygame.Surface] = {}
        self.small_digits_dark: Dict[str, pygame.Surface] = {}
        self.level_label: Optional[pygame.Surface] = None
        self.level_label_dark: Optional[pygame.Surface] = None
        self.level_digits: Dict[str, pygame.Surface] = {}
        self.level_digits_dark: Dict[str, pygame.Surface] = {}
        self.max_badge: Optional[pygame.Surface] = None

        self.cd_font = pygame.font.SysFont("Impact, Arial", 22, bold=True)
        self._init_textures()

    def _init_textures(self):
        if self.im2 is not None:
            try:
                # Worker Cat cuts from img002_tw.imgcut (lines 10, 11, 29)
                raw_w_on = to_32bit(self.im2.subsurface((1, 1, 194, 121)))
                self.w_on = pygame.transform.smoothscale(raw_w_on, (168, 112))
                raw_w_blink = to_32bit(self.im2.subsurface((197, 1, 194, 121)))
                self.w_blink = pygame.transform.smoothscale(raw_w_blink, (168, 112))
                raw_w_off = to_32bit(self.im2.subsurface((393, 1, 194, 121)))
                self.w_off = pygame.transform.smoothscale(raw_w_off, (168, 112))

                # Cat Cannon cuts from img002_tw.imgcut (lines 12..25)
                # (1, 124, 194, 130) is the full colored button formed by the 10%..100% charge slices
                raw_c_full = to_32bit(self.im2.subsurface((1, 124, 194, 130)))
                self.c_full = pygame.transform.smoothscale(raw_c_full, (168, 112))
                raw_c_blink = to_32bit(self.im2.subsurface((197, 124, 194, 130)))
                self.c_blink = pygame.transform.smoothscale(raw_c_blink, (168, 112))
                raw_c_off = to_32bit(self.im2.subsurface((393, 124, 194, 130)))
                self.c_off = pygame.transform.smoothscale(raw_c_off, (168, 112))

                # Official "發射就緒" blinking text cuts (lines 14, 15)
                raw_rf_on = to_32bit(self.im2.subsurface((185, 260, 125, 55)))
                self.c_ready_font_on = pygame.transform.smoothscale(raw_rf_on, (112, 48))
                raw_rf_blink = to_32bit(self.im2.subsurface((312, 260, 125, 55)))
                self.c_ready_font_blink = pygame.transform.smoothscale(raw_rf_blink, (112, 48))

                # Official "可召喚" badge (line 58: 185,374,87,31)
                raw_sok = to_32bit(self.im2.subsurface((185, 374, 87, 31)))
                self.summon_ok_badge = pygame.transform.smoothscale(raw_sok, (72, 25))

                raw_yb = to_32bit(self.im2.subsurface((134, 410, 126, 101)))
                self.yellow_border = pygame.transform.smoothscale(raw_yb, (self.CARD_WIDTH + 10, self.CARD_HEIGHT + 10))
            except Exception:
                pass

        if self.im1 is not None:
            try:
                # Small digits for card cost (img001_tw.imgcut lines 40..61)
                for i in range(10):
                    sub = to_32bit(self.im1.subsurface((41 + i * 20, 148, 18, 26)))
                    self.small_digits[str(i)] = pygame.transform.smoothscale(sub, (12, 18))
                    sub_d = to_32bit(self.im1.subsurface((25 + i * 20, 176, 18, 26)))
                    self.small_digits_dark[str(i)] = pygame.transform.smoothscale(sub_d, (12, 18))

                sub_yen = to_32bit(self.im1.subsurface((1, 176, 22, 26)))
                self.small_digits["元"] = pygame.transform.smoothscale(sub_yen, (14, 18))
                sub_yen_d = to_32bit(self.im1.subsurface((241, 148, 22, 26)))
                self.small_digits_dark["元"] = pygame.transform.smoothscale(sub_yen_d, (14, 18))

                # Worker cat level digits (bright: lines 18..28, dark: lines 29..39)
                raw_lbl = to_32bit(self.im1.subsurface((1, 89, 68, 27)))
                self.level_label = pygame.transform.smoothscale(raw_lbl, (52, 20))
                raw_lbl_d = to_32bit(self.im1.subsurface((21, 118, 68, 27)))
                self.level_label_dark = pygame.transform.smoothscale(raw_lbl_d, (52, 20))

                for i in range(9):
                    sub = to_32bit(self.im1.subsurface((75 + i * 20, 89, 18, 27)))
                    self.level_digits[str(i)] = pygame.transform.smoothscale(sub, (14, 20))
                sub_9 = to_32bit(self.im1.subsurface((1, 118, 18, 27)))
                self.level_digits["9"] = pygame.transform.smoothscale(sub_9, (14, 20))

                for i in range(8):
                    sub_d = to_32bit(self.im1.subsurface((95 + i * 20, 118, 18, 27)))
                    self.level_digits_dark[str(i)] = pygame.transform.smoothscale(sub_d, (14, 20))
                self.level_digits_dark["8"] = pygame.transform.smoothscale(to_32bit(self.im1.subsurface((1, 147, 18, 27))), (14, 20))
                self.level_digits_dark["9"] = pygame.transform.smoothscale(to_32bit(self.im1.subsurface((21, 147, 18, 27))), (14, 20))

                # MAX badge
                raw_max = to_32bit(self.im1.subsurface((449, 45, 62, 26)))
                self.max_badge = pygame.transform.smoothscale(raw_max, (46, 20))
            except Exception:
                pass

        # Pre-cache all unit portraits
        for u_key, tex_name in self.UNIT_PORTRAIT_MAP.items():
            tex = self.asset_mgr.get_texture(tex_name)
            if tex is not None:
                try:
                    crop_rect = (9, 21, 110, 85)
                    sub = to_32bit(tex.subsurface(crop_rect))
                    scaled = pygame.transform.smoothscale(sub, (self.CARD_WIDTH, self.CARD_HEIGHT))
                    self.card_portraits[u_key] = scaled
                except Exception:
                    pass

    def _get_portrait_for_unit(self, unit_key: Any, info: Dict[str, Any]) -> Optional[pygame.Surface]:
        if unit_key in self.card_portraits:
            return self.card_portraits[unit_key]
        uid = info.get("id")
        if uid in self.card_portraits:
            return self.card_portraits[uid]
        spec = info.get("spec", {})
        base_id = spec.get("base_unit_id", uid)
        if base_id in self.card_portraits:
            return self.card_portraits[base_id]
        tex_code = str(spec.get("texture_code", ""))
        if tex_code and "_" in tex_code:
            try:
                num = int(tex_code.split("_")[0])
                if num in self.card_portraits:
                    return self.card_portraits[num]
            except Exception:
                pass
        return self.card_portraits.get("cat")

    def handle_click(
        self,
        mouse_pos: Tuple[int, int],
        sim: BattleSimulation,
        team: int = TEAM_CAT,
        action_callback: Optional[Callable[[str, Any], None]] = None
    ) -> bool:
        if sim.game_over:
            return False

        wallet = sim.wallets.get(team, sim.wallet)
        deployer = sim.deployers.get(team, sim.deployer)

        # 1. Worker Cat upgrade
        if self.worker_btn_rect.collidepoint(mouse_pos):
            if action_callback is not None:
                cur_money, _, _, up_cost = wallet.get_status()
                if up_cost > 0 and cur_money >= up_cost:
                    action_callback("UPGRADE_WORKER", None)
                    self.sound_mgr.play("wallet_up")
                    return True
                return False
            success = wallet.upgrade_worker()
            if success:
                self.sound_mgr.play("wallet_up")
            return success

        # 2. Cat Cannon click
        if self.cannon_btn_rect.collidepoint(mouse_pos):
            if action_callback is not None:
                if sim.is_cannon_ready(team):
                    action_callback("FIRE_CANNON", None)
                    self.sound_mgr.play("cannon_fire")
                    return True
                return False
            fired = sim.fire_cannon(team)
            if fired:
                self.sound_mgr.play("cannon_fire")
            return fired

        # 3. Deck Page Toggle Button click
        if self.page_btn_rect.collidepoint(mouse_pos):
            self.current_page = 1 - self.current_page
            self.sound_mgr.play("button_click")
            return True

        # 4. Deploy Cards (Page offset applied)
        for idx, rect in enumerate(self.card_rects):
            if rect.collidepoint(mouse_pos):
                actual_idx = self.current_page * 5 + idx
                if actual_idx < len(deployer.deck_keys):
                    if action_callback is not None:
                        if deployer.can_deploy(actual_idx, wallet.money, has_free_slot=(sim.find_free_slot(team) is not None)):
                            action_callback("SPAWN_UNIT", actual_idx)
                            self.sound_mgr.play("deploy")
                            return True
                        return False
                    success = sim.deploy_unit(team, actual_idx)
                    if success:
                        self.sound_mgr.play("deploy")
                    return success
        return False

    def render(self, surface: pygame.Surface, sim: BattleSimulation, team: int = TEAM_CAT):
        tray_rect = pygame.Rect(0, self.bar_top, SCREEN_WIDTH, self.BAR_HEIGHT)
        # 1. Authentic Dark Slate Tray Base
        pygame.draw.rect(surface, (24, 26, 32), tray_rect)
        pygame.draw.line(surface, (60, 66, 80), (0, self.bar_top), (SCREEN_WIDTH, self.bar_top), 3)

        wallet = sim.wallets.get(team, sim.wallet)
        deployer = sim.deployers.get(team, sim.deployer)
        cur_money, max_money, w_lvl, up_cost = wallet.get_status()
        can_upgrade = (up_cost > 0 and cur_money >= up_cost)
        blink_phase = ((sim.current_frame // 6) % 2) == 1

        # 2. Worker Cat Button (Authentic Ponos img002_tw + img001_tw cuts)
        if self.w_on is not None and self.w_off is not None:
            if can_upgrade:
                w_btn = self.w_blink if (blink_phase and self.w_blink is not None) else self.w_on
            else:
                w_btn = self.w_off
            surface.blit(w_btn, self.worker_btn_rect)

            # Overlay Level (Bright when affordable/MAX, Dark when not affordable)
            use_bright_lvl = can_upgrade or (up_cost <= 0)
            lbl_surf = self.level_label if use_bright_lvl else (self.level_label_dark or self.level_label)
            lvl_dict = self.level_digits if use_bright_lvl else (self.level_digits_dark or self.level_digits)
            if lbl_surf is not None and lvl_dict:
                surface.blit(lbl_surf, (self.worker_btn_rect.x + 16, self.worker_btn_rect.y + 12))
                lvl_ch = str(w_lvl)
                if lvl_ch in lvl_dict:
                    surface.blit(lvl_dict[lvl_ch], (self.worker_btn_rect.x + 70, self.worker_btn_rect.y + 12))

            # Overlay Cost or MAX badge
            if up_cost > 0:
                cost_str = str(up_cost)
                dig_dict = self.small_digits if can_upgrade else self.small_digits_dark
                bx = self.worker_btn_rect.x + 18
                by = self.worker_btn_rect.bottom - 26
                for ch in cost_str:
                    if ch in dig_dict:
                        surface.blit(dig_dict[ch], (bx, by))
                        bx += 13
                if "元" in dig_dict:
                    surface.blit(dig_dict["元"], (bx, by))
            elif self.max_badge is not None:
                surface.blit(self.max_badge, (self.worker_btn_rect.x + 18, self.worker_btn_rect.bottom - 26))

        else:
            btn_col = (45, 75, 110) if can_upgrade else (35, 40, 50)
            pygame.draw.rect(surface, btn_col, self.worker_btn_rect, border_radius=8)
            pygame.draw.rect(surface, COLOR_GOLD if can_upgrade else (60, 68, 80), self.worker_btn_rect, width=2, border_radius=8)

        # 3. Cat Cannon Button (Authentic Ponos 10%..100% bottom-up charge slices + "發射就緒" blinking cuts)
        cannon_ready = sim.is_cannon_ready(team)
        cannon_ratio = sim.get_cannon_ratio(team)
        if self.c_full is not None and self.c_off is not None:
            if cannon_ready:
                c_btn = self.c_blink if (blink_phase and self.c_blink is not None) else self.c_full
                surface.blit(c_btn, self.cannon_btn_rect)
                # Official "發射就緒" blinking font cut from img002_tw.imgcut (lines 14-15)
                rf_surf = self.c_ready_font_blink if (blink_phase and self.c_ready_font_blink is not None) else self.c_ready_font_on
                if rf_surf is not None:
                    rx = self.cannon_btn_rect.centerx - rf_surf.get_width() // 2
                    ry = self.cannon_btn_rect.bottom - rf_surf.get_height() - 4
                    surface.blit(rf_surf, (rx, ry))
            else:
                # Base OFF grey button
                surface.blit(self.c_off, self.cannon_btn_rect)
                # Progressive 10-step bottom-up colored charge slices (10%..90% in 10% steps)
                step_count = int(cannon_ratio * 10)
                if step_count > 0:
                    fill_h = int((self.cannon_btn_rect.height * step_count) / 10.0)
                    if 0 < fill_h <= self.cannon_btn_rect.height:
                        src_y = self.cannon_btn_rect.height - fill_h
                        src_rect = pygame.Rect(0, src_y, self.cannon_btn_rect.width, fill_h)
                        dst_pos = (self.cannon_btn_rect.x, self.cannon_btn_rect.y + src_y)
                        surface.blit(self.c_full, dst_pos, area=src_rect)
        else:
            pygame.draw.rect(surface, (45, 65, 90) if cannon_ready else (35, 40, 50), self.cannon_btn_rect, border_radius=8)
            pygame.draw.rect(surface, COLOR_GOLD if cannon_ready else (60, 68, 80), self.cannon_btn_rect, width=2, border_radius=8)

        # 4. Deploy Card Slots (5 slots per page)
        for idx, rect in enumerate(self.card_rects):
            actual_idx = self.current_page * 5 + idx
            has_unit = actual_idx < len(deployer.deck_keys)

            # Slot recess background
            pygame.draw.rect(surface, (15, 17, 22), rect, border_radius=4)

            info = deployer.get_slot_info(actual_idx)
            if not has_unit or info is None:
                pygame.draw.rect(surface, (45, 50, 62), rect, width=2, border_radius=4)
                continue

            unit_key = deployer.deck_keys[actual_idx]
            cost = info["cost"]
            cd_ratio = info["cd_ratio"]
            can_afford = (cur_money >= cost)
            is_ready = (cd_ratio == 0 and can_afford)

            # A. Draw Unit Portrait
            portrait = self._get_portrait_for_unit(unit_key, info)
            if portrait is not None:
                surface.blit(portrait, rect)
            else:
                pygame.draw.rect(surface, (40, 45, 55), rect, border_radius=4)

            # B. If NOT affordable, dim the portrait
            if not can_afford:
                dim_surf = pygame.Surface((rect.width, rect.height), pygame.SRCALPHA)
                dim_surf.fill((0, 0, 0, 120))
                surface.blit(dim_surf, rect)

            # C. Authentic Ponos Cooldown Gauge Bar & Dark Sweep
            if cd_ratio > 0:
                shade_h = int(rect.height * cd_ratio)
                shade_rect = pygame.Rect(rect.x, rect.bottom - shade_h, rect.width, shade_h)
                shade_surf = pygame.Surface((rect.width, shade_h), pygame.SRCALPHA)
                shade_surf.fill((0, 0, 0, 165))
                surface.blit(shade_surf, shade_rect)

                # Authentic Ponos horizontal recharge bar across middle of card
                bar_w = rect.width - 16
                bar_h = 10
                bar_x = rect.x + 8
                bar_y = rect.centery - bar_h // 2
                pygame.draw.rect(surface, (15, 20, 28), (bar_x - 2, bar_y - 2, bar_w + 4, bar_h + 4), border_radius=3)
                fill_w = max(2, int(bar_w * (1.0 - cd_ratio)))
                pygame.draw.rect(surface, (80, 220, 255), (bar_x, bar_y, fill_w, bar_h), border_radius=2)
                pygame.draw.rect(surface, (220, 245, 255), (bar_x - 1, bar_y - 1, bar_w + 2, bar_h + 2), width=1, border_radius=3)

            # D. Ready state: Glowing yellow selection frame
            if is_ready and self.yellow_border is not None:
                yb_x = rect.x - 5
                yb_y = rect.y - 5
                surface.blit(self.yellow_border, (yb_x, yb_y))
            else:
                border_c = (70, 75, 88) if can_afford else (40, 44, 52)
                pygame.draw.rect(surface, border_c, rect, width=2, border_radius=4)

            # E. Cost display at bottom right of card
            cost_str = str(cost)
            dig_dict = self.small_digits if can_afford else self.small_digits_dark
            if dig_dict:
                total_w = len(cost_str) * 13 + 15
                px = rect.right - total_w - 4
                py = rect.bottom - 22
                for ch in cost_str:
                    if ch in dig_dict:
                        surface.blit(dig_dict[ch], (px, py))
                        px += 13
                if "元" in dig_dict:
                    surface.blit(dig_dict["元"], (px, py))

        # 5. Deck Page Toggle Button
        pygame.draw.rect(surface, (30, 36, 48), self.page_btn_rect, border_radius=8)
        pygame.draw.rect(surface, (90, 130, 180), self.page_btn_rect, width=2, border_radius=8)

        # Page text e.g. "1 / 2"
        p_txt = f"{self.current_page + 1} / 2"
        p_surf = self.page_font.render(p_txt, True, (255, 230, 100))
        surface.blit(p_surf, (self.page_btn_rect.centerx - p_surf.get_width() // 2, self.page_btn_rect.y + 10))

        sub_lbl = self.page_sub_font.render("隊伍切換", True, (200, 215, 230))
        surface.blit(sub_lbl, (self.page_btn_rect.centerx - sub_lbl.get_width() // 2, self.page_btn_rect.y + 36))
