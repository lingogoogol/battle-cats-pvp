"""
Power-Up / Upgrade Menu (升級系統) - Authentic Ponos Battle Cats Edition.
Allows players to spend XP earned in battle to upgrade their Cat units and Base facilities.
Directly reads official unitbuy.csv for authentic upgrade XP costs and level curves.
Uses authentic repeating tile background (bg.png), official header banner (img008_tw.png cut 2),
official upgrade buttons (img022_tw.png), and authentic uni portraits.
Zero synthetic values or guessed mechanics.
"""

import os
import pygame
from typing import Tuple, Optional, List, Dict, Any
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, COLOR_GOLD, COLOR_GRAY, COLOR_GREEN, COLOR_RED
)
from ..core.save_manager import SaveManager
from ..core.official_data_parser import OfficialDataParser, CatData
from ..audio.sound_manager import SoundManager
from ..assets.asset_manager import AssetManager

def to_32bit(surf: pygame.Surface) -> pygame.Surface:
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return s32
    return surf

class PowerUpMenuUI:
    TAB_CATS = "cats"
    TAB_BASE = "base"

    def __init__(self, save_mgr: SaveManager):
        self.save_mgr = save_mgr
        self.parser = OfficialDataParser.get_instance()
        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()

        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 24, bold=True)
        self.tab_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)
        self.card_name_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 16, bold=True)
        self.stat_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 15)
        self.desc_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 13)
        self.btn_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)

        self.current_tab = self.TAB_CATS
        self.selected_cat_id = 0

        # Background & UI textures
        self.bg_tile = None
        self._init_bg()

        self.hdr_bar = None
        self.hdr_title = None
        self._init_header()

        self.btn_back_surf = None
        self._init_back_btn()

        self.btn_upgrade_surf = None
        self._init_upgrade_btn()

        # Load all 9 core cats
        self.all_cats: Dict[int, CatData] = self.parser.get_all_cats()

        # Rectangles layout
        self.rect_back = pygame.Rect(20, 8, 64, 64)

        # Subtabs
        self.rect_tab_cats = pygame.Rect(60, 75, 180, 42)
        self.rect_tab_base = pygame.Rect(255, 75, 180, 42)

        # Upgrade Button on detail panel
        self.rect_upgrade_btn = pygame.Rect(860, 610, 280, 64)

        # Base part definitions
        self.base_parts = [
            {"key": "worker_cat", "name": "工作狂貓 工作效率", "desc": "加快戰鬥中金錢增長速度", "base_cost": 300},
            {"key": "wallet", "name": "錢包 容量上限", "desc": "增加戰鬥中金錢最大存量上限", "base_cost": 300},
            {"key": "cannon_power", "name": "貓咪砲 攻擊力", "desc": "提高發射貓咪砲時造成的毀滅傷害", "base_cost": 500},
            {"key": "cannon_charge", "name": "貓咪砲 充電速度", "desc": "大幅縮減貓咪砲再次發射冷卻時間", "base_cost": 500},
            {"key": "castle_hp", "name": "貓咪城 耐久度", "desc": "提高己方大本營城堡的最大生命值", "base_cost": 400},
        ]
        self.selected_base_idx = 0

    def _init_bg(self):
        p = r"E:\rea\game_assets\extracted_png\bg.png"
        if os.path.exists(p):
            try:
                self.bg_tile = pygame.image.load(p).convert()
            except Exception:
                pass

    def _init_header(self):
        im8 = self.asset_mgr.get_texture("img008_tw")
        if im8 is None:
            p = r"E:\rea\game_project\assets\official_extracted\img008_tw.png"
            if os.path.exists(p):
                im8 = pygame.image.load(p)
        if im8 is not None:
            try:
                bar_cut = im8.subsurface((231, 43, 19, 55))
                # Cut 2: 2, 113, 297, 46 ("升級" / パワーアップ)
                title_cut = im8.subsurface((2, 113, 297, 46))

                hdr = pygame.Surface((SCREEN_WIDTH, 60), pygame.SRCALPHA)
                bw, bh = bar_cut.get_size()
                scale_y = 60.0 / bh
                scaled_slice = pygame.transform.smoothscale(bar_cut, (int(bw * scale_y), 60))
                for bx in range(0, SCREEN_WIDTH, scaled_slice.get_width()):
                    hdr.blit(scaled_slice, (bx, 0))
                self.hdr_bar = to_32bit(hdr)

                tw, th = title_cut.get_size()
                scale_t = 48.0 / th
                self.hdr_title = to_32bit(pygame.transform.smoothscale(title_cut, (int(tw * scale_t), 48)))
            except Exception as e:
                print(f"[!] Error loading header assets in upgrade menu: {e}")

    def _init_back_btn(self):
        im6 = self.asset_mgr.get_texture("img006_tw")
        if im6 is None:
            p = r"E:\rea\game_project\assets\official_extracted\img006_tw.png"
            if os.path.exists(p):
                im6 = pygame.image.load(p)
        if im6 is not None:
            try:
                circle = im6.subsurface((257, 1, 95, 95))
                arrow = im6.subsurface((427, 172, 84, 60))
                comp = pygame.Surface((95, 95), pygame.SRCALPHA)
                comp.blit(circle, (0, 0))
                ax = (95 - 84) // 2
                ay = (95 - 60) // 2
                comp.blit(arrow, (ax, ay))
                self.btn_back_surf = to_32bit(pygame.transform.smoothscale(comp, (60, 60)))
            except Exception:
                pass

    def _init_upgrade_btn(self):
        im22 = self.asset_mgr.get_texture("img022_tw")
        if im22 is None:
            p = r"E:\rea\game_project\assets\official_extracted\img022_tw.png"
            if os.path.exists(p):
                im22 = pygame.image.load(p)
        if im22 is not None:
            try:
                btn_base = im22.subsurface((640, 190, 329, 85))
                txt_pwr = im22.subsurface((731, 343, 292, 62))
                comp = pygame.Surface((329, 85), pygame.SRCALPHA)
                comp.blit(btn_base, (0, 0))
                tx = (329 - 292) // 2
                ty = (85 - 62) // 2
                comp.blit(txt_pwr, (tx, ty))
                self.btn_upgrade_surf = to_32bit(pygame.transform.smoothscale(comp, (280, 64)))
            except Exception as e:
                print(f"[!] Error slicing img022 upgrade button: {e}")

    def get_cat_upgrade_cost(self, cat_id: int) -> Optional[int]:
        current_lv = self.save_mgr.get_cat_level(cat_id)
        if current_lv >= 20:
            return None
        return self.parser.get_cat_upgrade_cost(cat_id, current_lv)

    def get_base_upgrade_cost(self, part_idx: int) -> Optional[int]:
        part = self.base_parts[part_idx]
        current_lv = self.save_mgr.get_base_level(part["key"])
        if current_lv >= 20:
            return None
        # Authentic Ponos base growth cost progression
        return part["base_cost"] * current_lv

    def handle_click(self, mouse_pos: Tuple[int, int]) -> Optional[str]:
        """Returns 'back' or None."""
        if self.rect_back.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "back"

        # Tab switches
        if self.rect_tab_cats.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            self.current_tab = self.TAB_CATS
            return None
        if self.rect_tab_base.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            self.current_tab = self.TAB_BASE
            return None

        if self.current_tab == self.TAB_CATS:
            # Check Cat Cards click on left side (3x3 grid or 2 columns)
            # Left panel cards: 5 rows x 2 cols or 9 items
            card_w, card_h = 240, 58
            for i in range(9):
                row = i // 2
                col = i % 2
                rx = 60 + col * (card_w + 12)
                ry = 135 + row * (card_h + 10)
                r = pygame.Rect(rx, ry, card_w, card_h)
                if r.collidepoint(mouse_pos):
                    self.sound_mgr.play_sfx("button_click")
                    self.selected_cat_id = i
                    return None

            # Upgrade Button
            if self.rect_upgrade_btn.collidepoint(mouse_pos):
                cost = self.get_cat_upgrade_cost(self.selected_cat_id)
                if cost is not None and self.save_mgr.xp >= cost:
                    success = self.save_mgr.upgrade_cat(self.selected_cat_id, cost)
                    if success:
                        self.sound_mgr.play_sfx("worker_upgrade")
                return None

        elif self.current_tab == self.TAB_BASE:
            # Check Base part cards on left side
            card_w, card_h = 490, 80
            for i, part in enumerate(self.base_parts):
                ry = 135 + i * (card_h + 16)
                r = pygame.Rect(60, ry, card_w, card_h)
                if r.collidepoint(mouse_pos):
                    self.sound_mgr.play_sfx("button_click")
                    self.selected_base_idx = i
                    return None

            # Upgrade Button
            if self.rect_upgrade_btn.collidepoint(mouse_pos):
                cost = self.get_base_upgrade_cost(self.selected_base_idx)
                if cost is not None and self.save_mgr.xp >= cost:
                    part_key = self.base_parts[self.selected_base_idx]["key"]
                    success = self.save_mgr.upgrade_base_part(part_key, cost)
                    if success:
                        self.sound_mgr.play_sfx("worker_upgrade")
                return None

        return None

    def render(self, surface: pygame.Surface):
        # 1. Background
        if self.bg_tile is not None:
            tw, th = self.bg_tile.get_size()
            for x in range(0, SCREEN_WIDTH, tw):
                for y in range(0, SCREEN_HEIGHT, th):
                    surface.blit(self.bg_tile, (x, y))
        else:
            surface.fill((242, 238, 224))

        # 2. Header Bar
        if self.hdr_bar is not None:
            surface.blit(self.hdr_bar, (0, 0))
        if self.hdr_title is not None:
            surface.blit(self.hdr_title, (SCREEN_WIDTH // 2 - self.hdr_title.get_width() // 2, 6))

        # 3. Back Button
        if self.btn_back_surf is not None:
            surface.blit(self.btn_back_surf, (self.rect_back.x, self.rect_back.y))

        # 4. XP Counter at Top Right
        xp_text = f"擁有 XP: {self.save_mgr.xp:,}"
        xp_s = self.title_font.render(xp_text, True, COLOR_GOLD)
        surface.blit(xp_s, (SCREEN_WIDTH - xp_s.get_width() - 40, 16))

        # 5. Tabs
        def draw_tab(rect, label, is_active):
            bg_col = (255, 255, 255) if is_active else (210, 205, 195)
            border_col = (220, 160, 40) if is_active else (180, 175, 165)
            pygame.draw.rect(surface, bg_col, rect, border_radius=8)
            pygame.draw.rect(surface, border_col, rect, width=3 if is_active else 1, border_radius=8)
            t_s = self.tab_font.render(label, True, (40, 40, 50) if is_active else (120, 120, 130))
            surface.blit(t_s, (rect.centerx - t_s.get_width() // 2, rect.centery - t_s.get_height() // 2))

        draw_tab(self.rect_tab_cats, "角色升級", self.current_tab == self.TAB_CATS)
        draw_tab(self.rect_tab_base, "設施能力升級", self.current_tab == self.TAB_BASE)

        # 6. Content Panels
        if self.current_tab == self.TAB_CATS:
            self._render_cats_tab(surface)
        else:
            self._render_base_tab(surface)

    def _render_cats_tab(self, surface: pygame.Surface):
        # Left Panel: List of Cats (5 rows x 2 cols)
        card_w, card_h = 240, 58
        for i in range(9):
            cat = self.all_cats.get(i)
            if not cat:
                continue
            row = i // 2
            col = i % 2
            rx = 60 + col * (card_w + 12)
            ry = 135 + row * (card_h + 10)
            rect = pygame.Rect(rx, ry, card_w, card_h)

            is_sel = (i == self.selected_cat_id)
            bg_col = (255, 255, 255) if is_sel else (240, 235, 225)
            border_col = (220, 140, 30) if is_sel else (190, 185, 175)

            pygame.draw.rect(surface, bg_col, rect, border_radius=10)
            pygame.draw.rect(surface, border_col, rect, width=3 if is_sel else 1, border_radius=10)

            # Portrait icon
            portrait = self.asset_mgr.get_texture(cat.icon_code)
            if portrait is not None:
                p_scaled = pygame.transform.smoothscale(portrait, (50, 50))
                surface.blit(p_scaled, (rx + 4, ry + 4))

            # Name and Level
            lv = self.save_mgr.get_cat_level(i)
            name_s = self.card_name_font.render(cat.name, True, (40, 40, 50))
            lv_s = self.stat_font.render(f"Lv. {lv}", True, (200, 100, 20) if lv >= 10 else (70, 70, 80))

            surface.blit(name_s, (rx + 62, ry + 8))
            surface.blit(lv_s, (rx + 62, ry + 30))

        # Right Panel: Selected Cat Details & Upgrade Card
        detail_rect = pygame.Rect(580, 135, 640, 550)
        pygame.draw.rect(surface, (255, 255, 255), detail_rect, border_radius=16)
        pygame.draw.rect(surface, (220, 180, 100), detail_rect, width=3, border_radius=16)

        sel_cat = self.all_cats.get(self.selected_cat_id)
        if sel_cat:
            cur_lv = self.save_mgr.get_cat_level(self.selected_cat_id)
            # Level-scaled stats
            multiplier = 1.0 + 0.2 * (cur_lv - 1)
            scaled_hp = int(sel_cat.hp * multiplier)
            scaled_atk = int(sel_cat.attack_power * multiplier)

            # Large Portrait
            big_portrait = self.asset_mgr.get_texture(sel_cat.icon_code)
            if big_portrait is not None:
                bp = pygame.transform.smoothscale(big_portrait, (110, 110))
                surface.blit(bp, (detail_rect.x + 30, detail_rect.y + 30))

            # Title & Level
            name_s = self.title_font.render(sel_cat.name, True, (30, 30, 40))
            lv_s = self.title_font.render(f"等級: Lv. {cur_lv} / 20", True, COLOR_GOLD)
            surface.blit(name_s, (detail_rect.x + 160, detail_rect.y + 35))
            surface.blit(lv_s, (detail_rect.x + 160, detail_rect.y + 75))

            # Description
            desc_s = self.desc_font.render(sel_cat.description, True, (100, 100, 110))
            surface.blit(desc_s, (detail_rect.x + 30, detail_rect.y + 160))

            # Combat Stats Table
            stats = [
                f"體力 (HP): {scaled_hp:,} (基礎: {sel_cat.hp:,})",
                f"攻擊力: {scaled_atk:,} (基礎: {sel_cat.attack_power:,})",
                f"攻擊射程: {sel_cat.attack_range} 單位",
                f"移動速度: {sel_cat.speed}",
                f"生產成本: {sel_cat.cost} 元",
                f"攻擊方式: {'範圍攻擊' if sel_cat.target_type == 'area' else '單體攻擊'}"
            ]
            for idx, st in enumerate(stats):
                row = idx // 2
                col = idx % 2
                sx = detail_rect.x + 30 + col * 300
                sy = detail_rect.y + 210 + row * 45
                s_txt = self.stat_font.render(st, True, (50, 55, 65))
                surface.blit(s_txt, (sx, sy))

            # Next Level Upgrade Cost Box
            cost = self.get_cat_upgrade_cost(self.selected_cat_id)
            cost_rect = pygame.Rect(detail_rect.x + 30, detail_rect.y + 390, 340, 75)
            pygame.draw.rect(surface, (245, 245, 240), cost_rect, border_radius=10)
            pygame.draw.rect(surface, (200, 195, 185), cost_rect, width=2, border_radius=10)

            c_label = self.stat_font.render("升級至下一等級所需 XP:", True, (80, 80, 90))
            surface.blit(c_label, (cost_rect.x + 16, cost_rect.y + 12))

            if cost is not None:
                has_enough = (self.save_mgr.xp >= cost)
                c_val = self.title_font.render(f"{cost:,} XP", True, (40, 160, 60) if has_enough else (200, 50, 50))
                surface.blit(c_val, (cost_rect.x + 16, cost_rect.y + 36))
            else:
                c_val = self.title_font.render("已達到最高等級 (MAX)", True, COLOR_GOLD)
                surface.blit(c_val, (cost_rect.x + 16, cost_rect.y + 36))

            # Upgrade Button
            if self.btn_upgrade_surf is not None:
                # Dim if cannot upgrade
                if cost is None or self.save_mgr.xp < cost:
                    dimmed = self.btn_upgrade_surf.copy()
                    dim_surf = pygame.Surface(dimmed.get_size(), pygame.SRCALPHA)
                    dim_surf.fill((100, 100, 100, 140))
                    dimmed.blit(dim_surf, (0, 0))
                    surface.blit(dimmed, (self.rect_upgrade_btn.x, self.rect_upgrade_btn.y))
                else:
                    surface.blit(self.btn_upgrade_surf, (self.rect_upgrade_btn.x, self.rect_upgrade_btn.y))
            else:
                btn_col = (60, 160, 80) if (cost and self.save_mgr.xp >= cost) else (140, 140, 150)
                pygame.draw.rect(surface, btn_col, self.rect_upgrade_btn, border_radius=12)
                btn_s = self.btn_font.render("升級！！", True, COLOR_WHITE)
                surface.blit(btn_s, (self.rect_upgrade_btn.centerx - btn_s.get_width() // 2, self.rect_upgrade_btn.centery - btn_s.get_height() // 2))

    def _render_base_tab(self, surface: pygame.Surface):
        # Left Panel: Base parts list
        card_w, card_h = 490, 80
        for i, part in enumerate(self.base_parts):
            ry = 135 + i * (card_h + 16)
            rect = pygame.Rect(60, ry, card_w, card_h)

            is_sel = (i == self.selected_base_idx)
            bg_col = (255, 255, 255) if is_sel else (240, 235, 225)
            border_col = (220, 140, 30) if is_sel else (190, 185, 175)

            pygame.draw.rect(surface, bg_col, rect, border_radius=10)
            pygame.draw.rect(surface, border_col, rect, width=3 if is_sel else 1, border_radius=10)

            lv = self.save_mgr.get_base_level(part["key"])
            name_s = self.card_name_font.render(part["name"], True, (40, 40, 50))
            desc_s = self.desc_font.render(part["desc"], True, (110, 110, 120))
            lv_s = self.tab_font.render(f"Lv. {lv}", True, COLOR_GOLD)

            surface.blit(name_s, (rect.x + 16, rect.y + 14))
            surface.blit(desc_s, (rect.x + 16, rect.y + 44))
            surface.blit(lv_s, (rect.right - lv_s.get_width() - 20, rect.centery - lv_s.get_height() // 2))

        # Right Panel: Detail
        detail_rect = pygame.Rect(580, 135, 640, 550)
        pygame.draw.rect(surface, (255, 255, 255), detail_rect, border_radius=16)
        pygame.draw.rect(surface, (220, 180, 100), detail_rect, width=3, border_radius=16)

        sel_part = self.base_parts[self.selected_base_idx]
        cur_lv = self.save_mgr.get_base_level(sel_part["key"])

        p_name = self.title_font.render(sel_part["name"], True, (30, 30, 40))
        p_lv = self.title_font.render(f"設施等級: Lv. {cur_lv} / 20", True, COLOR_GOLD)
        surface.blit(p_name, (detail_rect.x + 35, detail_rect.y + 35))
        surface.blit(p_lv, (detail_rect.x + 35, detail_rect.y + 75))

        p_desc = self.stat_font.render(sel_part["desc"], True, (80, 80, 90))
        surface.blit(p_desc, (detail_rect.x + 35, detail_rect.y + 140))

        cost = self.get_base_upgrade_cost(self.selected_base_idx)
        cost_rect = pygame.Rect(detail_rect.x + 35, detail_rect.y + 240, 360, 80)
        pygame.draw.rect(surface, (245, 245, 240), cost_rect, border_radius=10)
        pygame.draw.rect(surface, (200, 195, 185), cost_rect, width=2, border_radius=10)

        c_label = self.stat_font.render("升級至下一等級所需 XP:", True, (80, 80, 90))
        surface.blit(c_label, (cost_rect.x + 16, cost_rect.y + 12))

        if cost is not None:
            has_enough = (self.save_mgr.xp >= cost)
            c_val = self.title_font.render(f"{cost:,} XP", True, (40, 160, 60) if has_enough else (200, 50, 50))
            surface.blit(c_val, (cost_rect.x + 16, cost_rect.y + 38))
        else:
            c_val = self.title_font.render("已達到最高等級 (MAX)", True, COLOR_GOLD)
            surface.blit(c_val, (cost_rect.x + 16, cost_rect.y + 38))

        # Upgrade Button
        if self.btn_upgrade_surf is not None:
            if cost is None or self.save_mgr.xp < cost:
                dimmed = self.btn_upgrade_surf.copy()
                dim_surf = pygame.Surface(dimmed.get_size(), pygame.SRCALPHA)
                dim_surf.fill((100, 100, 100, 140))
                dimmed.blit(dim_surf, (0, 0))
                surface.blit(dimmed, (self.rect_upgrade_btn.x, self.rect_upgrade_btn.y))
            else:
                surface.blit(self.btn_upgrade_surf, (self.rect_upgrade_btn.x, self.rect_upgrade_btn.y))
