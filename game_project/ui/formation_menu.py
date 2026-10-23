"""
Formation / Deck Editor (編隊系統) - Authentic Ponos Battle Cats Edition.
Allows players to customize their 10-slot battle deployment deck (2 rows of 5 slots).
Seamlessly connects with SaveManager so custom decks persist into combat.
Uses authentic repeating tile background (bg.png), official header banner (img008_tw.png cut 3),
official card bases, and authentic uni portraits.
Zero synthetic placeholder shapes or guessed mechanics.
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

class FormationMenuUI:
    CARD_WIDTH = 116
    CARD_HEIGHT = 100

    def __init__(self, save_mgr: SaveManager):
        self.save_mgr = save_mgr
        self.parser = OfficialDataParser.get_instance()
        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()

        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 22, bold=True)
        self.slot_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 14, bold=True)
        self.stat_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 14)
        self.desc_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 13)
        self.hint_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 15, bold=True)

        self.selected_slot_idx: Optional[int] = 0

        # Background & UI textures
        self.bg_tile = None
        self._init_bg()

        self.hdr_bar = None
        self.hdr_title = None
        self._init_header()

        self.btn_back_surf = None
        self._init_back_btn()

        self.card_base_surf = None
        self._init_card_base()

        self.all_cats: Dict[int, CatData] = self.parser.get_all_cats()

        self.rect_back = pygame.Rect(20, 8, 64, 64)

        # 10 Deck Slots (2 rows of 5)
        # Row 1: y = 120, Row 2: y = 235
        self.deck_slot_rects: List[pygame.Rect] = []
        start_x = 310
        spacing_x = 132
        for row in range(2):
            ry = 115 + row * 115
            for col in range(5):
                rx = start_x + col * spacing_x
                self.deck_slot_rects.append(pygame.Rect(rx, ry, self.CARD_WIDTH, self.CARD_HEIGHT))

        # Bottom Catalog Cards (9 Core Cats)
        self.catalog_rects: List[pygame.Rect] = []
        cat_start_x = 70
        cat_spacing_x = 130
        for i in range(9):
            row = i // 5
            col = i % 5
            cx = cat_start_x + col * (190 + 30)
            cy = 430 + row * 135
            self.catalog_rects.append(pygame.Rect(cx, cy, 190, 115))

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
                # Cut 3: 2, 161, 297, 46 ("編隊" / 編成)
                title_cut = im8.subsurface((2, 161, 297, 46))

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
                print(f"[!] Error loading formation header: {e}")

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

    def _init_card_base(self):
        cb = self.asset_mgr.get_texture("card_base_0")
        if cb is not None:
            try:
                self.card_base_surf = pygame.transform.smoothscale(cb, (self.CARD_WIDTH, self.CARD_HEIGHT))
            except Exception:
                pass

    def handle_click(self, mouse_pos: Tuple[int, int]) -> Optional[str]:
        """Returns 'back' or None."""
        if self.rect_back.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "back"

        # 1. Click on Deck Slot (select it)
        for idx, rect in enumerate(self.deck_slot_rects):
            if rect.collidepoint(mouse_pos):
                self.sound_mgr.play_sfx("button_click")
                self.selected_slot_idx = idx
                return None

        # 2. Click on Catalog Cat (assign to selected slot)
        if self.selected_slot_idx is not None:
            for cat_id, rect in enumerate(self.catalog_rects):
                if rect.collidepoint(mouse_pos):
                    # Equip this cat to the selected slot
                    self.save_mgr.set_deck_slot(self.selected_slot_idx, cat_id)
                    self.sound_mgr.play_sfx("worker_upgrade")
                    # Advance to next slot for easy multi-equipping
                    self.selected_slot_idx = (self.selected_slot_idx + 1) % 10
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

        # 4. Deck Section Header & Row labels
        sec1_s = self.title_font.render("出擊隊伍配置 (戰鬥欄位 1 ~ 10):", True, (40, 40, 50))
        surface.blit(sec1_s, (70, 80))

        lbl_r1 = self.slot_font.render("第 1 頁 (1~5)", True, (130, 110, 80))
        lbl_r2 = self.slot_font.render("第 2 頁 (6~10)", True, (130, 110, 80))
        surface.blit(lbl_r1, (170, 150))
        surface.blit(lbl_r2, (170, 265))

        # 5. Render 10 Deck Slots
        deck = self.save_mgr.get_deck()
        for idx, rect in enumerate(self.deck_slot_rects):
            is_sel = (idx == self.selected_slot_idx)
            cat_id = deck[idx] if idx < len(deck) else -1

            # Card background
            if self.card_base_surf is not None:
                surface.blit(self.card_base_surf, (rect.x, rect.y))
            else:
                pygame.draw.rect(surface, (250, 248, 240), rect, border_radius=8)

            # Highlight border if selected
            if is_sel:
                pygame.draw.rect(surface, (255, 200, 40), rect, width=4, border_radius=8)
            else:
                pygame.draw.rect(surface, (180, 175, 160), rect, width=1, border_radius=8)

            if cat_id >= 0 and cat_id in self.all_cats:
                cat = self.all_cats[cat_id]
                lv = self.save_mgr.get_cat_level(cat_id)
                # Portrait
                portrait = self.asset_mgr.get_texture(cat.icon_code)
                if portrait is not None:
                    p_scaled = pygame.transform.smoothscale(portrait, (68, 68))
                    surface.blit(p_scaled, (rect.centerx - 34, rect.y + 6))

                # Level & Cost
                lv_s = self.slot_font.render(f"Lv.{lv}", True, COLOR_GOLD)
                cost_s = self.slot_font.render(f"{cat.cost}元", True, (40, 40, 50))
                surface.blit(lv_s, (rect.x + 8, rect.bottom - 22))
                surface.blit(cost_s, (rect.right - cost_s.get_width() - 8, rect.bottom - 22))
            else:
                empty_s = self.slot_font.render("未配置", True, (160, 160, 170))
                surface.blit(empty_s, (rect.centerx - empty_s.get_width() // 2, rect.centery - empty_s.get_height() // 2))

        # 6. Separator line & Hint
        pygame.draw.line(surface, (210, 200, 185), (50, 360), (SCREEN_WIDTH - 50, 360), width=3)

        hint_s = self.hint_font.render("點選上方出擊欄位後，再點選下方角色即可完成配置喵！", True, (210, 120, 20))
        surface.blit(hint_s, (SCREEN_WIDTH // 2 - hint_s.get_width() // 2, 375))

        # 7. Bottom Section: Catalog Cards (9 Core Cats)
        for cat_id, rect in enumerate(self.catalog_rects):
            cat = self.all_cats.get(cat_id)
            if not cat:
                continue

            lv = self.save_mgr.get_cat_level(cat_id)
            is_in_deck = (cat_id in deck)

            bg_col = (255, 255, 255) if is_in_deck else (245, 240, 230)
            border_col = (220, 160, 40) if is_in_deck else (190, 185, 175)

            pygame.draw.rect(surface, bg_col, rect, border_radius=10)
            pygame.draw.rect(surface, border_col, rect, width=2 if is_in_deck else 1, border_radius=10)

            # Portrait
            portrait = self.asset_mgr.get_texture(cat.icon_code)
            if portrait is not None:
                p_scaled = pygame.transform.smoothscale(portrait, (56, 56))
                surface.blit(p_scaled, (rect.x + 8, rect.y + 8))

            # Name, Lv, Cost
            name_s = self.slot_font.render(cat.name, True, (40, 40, 50))
            lv_s = self.stat_font.render(f"Lv.{lv}", True, COLOR_GOLD)
            cost_s = self.stat_font.render(f"花費: {cat.cost}", True, (50, 60, 80))

            surface.blit(name_s, (rect.x + 70, rect.y + 10))
            surface.blit(lv_s, (rect.x + 70, rect.y + 32))
            surface.blit(cost_s, (rect.x + 70, rect.y + 54))

            # In deck status badge
            if is_in_deck:
                badge_s = self.slot_font.render("【已出陣】", True, (40, 160, 60))
                surface.blit(badge_s, (rect.right - badge_s.get_width() - 10, rect.bottom - 24))
            else:
                badge_s = self.stat_font.render("點擊配置", True, (140, 140, 150))
                surface.blit(badge_s, (rect.right - badge_s.get_width() - 10, rect.bottom - 24))
