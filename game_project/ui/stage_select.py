"""
Stage Selection UI Screen - Authentic Battle Cats World Map Edition.
Renders official map000_00.png background and all 48 stages of Empire of Cats Ch. 1
loaded directly from OfficialDataParser (stage00.csv ~ stage47.csv and StageName_tw.csv).
Zero synthetic JSON dependencies.
"""

import os
import pygame
from typing import Tuple, Optional, List, Dict, Any
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, COLOR_GOLD, COLOR_GRAY, COLOR_GREEN, COLOR_RED
)
from ..core.save_manager import SaveManager
from ..core.official_data_parser import OfficialDataParser, StageData
from ..assets.asset_manager import AssetManager
from ..audio.sound_manager import SoundManager

def to_32bit(surf: pygame.Surface) -> pygame.Surface:
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return s32
    return surf

class StageSelectUI:
    STAGES_PER_PAGE = 6
    TOTAL_PAGES = 8

    def __init__(self, save_mgr: SaveManager):
        self.save_mgr = save_mgr
        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 26, bold=True)
        self.card_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)
        self.info_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 14)
        self.btn_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 16, bold=True)

        self.btn_back = pygame.Rect(20, 8, 64, 64)
        self.btn_prev = pygame.Rect(420, 645, 120, 40)
        self.btn_next = pygame.Rect(740, 645, 120, 40)

        self.current_page = 0 # 0..7

        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()
        self.parser = OfficialDataParser.get_instance()

        self.map_bg = None
        self._init_map_bg()

        self.hdr_bar = None
        self.hdr_title = None
        self._init_header()

        self.btn_back_surf = None
        self._init_back_btn()

        # Compute card layout: 2 rows of 3 cards
        # Canvas: 1280 x 720
        self.card_w, self.card_h = 360, 235
        self.cards_per_row = 3
        self.start_x = (SCREEN_WIDTH - (3 * self.card_w + 2 * 30)) // 2
        self.row1_y = 110
        self.row2_y = 375

    def _init_map_bg(self):
        map_surf = self.asset_mgr.get_texture("map000_00")
        if map_surf is None:
            p = r"E:\rea\game_project\assets\official_extracted\map000_00.png"
            if os.path.exists(p):
                try:
                    map_surf = pygame.image.load(p)
                except Exception:
                    pass
        if map_surf is not None:
            try:
                scaled = to_32bit(pygame.transform.smoothscale(map_surf, (SCREEN_WIDTH, SCREEN_HEIGHT)))
                dim = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
                dim.fill((16, 20, 28, 175))
                scaled.blit(dim, (0, 0))
                self.map_bg = scaled
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
                # Cut 6: 301, 113, 297, 46 ("關卡選擇" / ステージ選択)
                title_cut = im8.subsurface((301, 113, 297, 46))

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
            except Exception:
                pass

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

    def get_stage_rect(self, slot_idx: int) -> pygame.Rect:
        row = slot_idx // self.cards_per_row
        col = slot_idx % self.cards_per_row
        x = self.start_x + col * (self.card_w + 30)
        y = self.row1_y if row == 0 else self.row2_y
        return pygame.Rect(x, y, self.card_w, self.card_h)

    def handle_click(self, mouse_pos: Tuple[int, int]) -> Optional[Dict[str, Any]]:
        # Back button
        if self.btn_back.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return {"action": "back"}

        # Previous Page
        if self.btn_prev.collidepoint(mouse_pos) and self.current_page > 0:
            self.sound_mgr.play_sfx("button_click")
            self.current_page -= 1
            return None

        # Next Page
        if self.btn_next.collidepoint(mouse_pos) and self.current_page < self.TOTAL_PAGES - 1:
            self.sound_mgr.play_sfx("button_click")
            self.current_page += 1
            return None

        # Check stage cards on current page
        start_stage_id = self.current_page * self.STAGES_PER_PAGE + 1
        for slot_idx in range(self.STAGES_PER_PAGE):
            stage_id = start_stage_id + slot_idx
            if stage_id > 48:
                break

            rect = self.get_stage_rect(slot_idx)
            if rect.collidepoint(mouse_pos):
                if self.save_mgr.is_stage_unlocked(stage_id):
                    self.sound_mgr.play_sfx("button_click")
                    stage_data = self.parser.get_stage(stage_id)
                    if stage_data:
                        return {
                            "action": "play",
                            "stage_id": stage_id,
                            "stage_config": stage_data.to_dict()
                        }
        return None

    def render(self, screen: pygame.Surface):
        # 1. Background
        if self.map_bg:
            screen.blit(self.map_bg, (0, 0))
        else:
            screen.fill((20, 24, 32))

        # 2. Header Bar & Title
        if self.hdr_bar is not None:
            screen.blit(self.hdr_bar, (0, 0))
        if self.hdr_title is not None:
            screen.blit(self.hdr_title, (SCREEN_WIDTH // 2 - self.hdr_title.get_width() // 2, 6))
        else:
            title_surf = self.title_font.render("世界篇 第 1 章：關卡選擇", True, COLOR_GOLD)
            screen.blit(title_surf, (SCREEN_WIDTH // 2 - title_surf.get_width() // 2, 28))

        # Back button (Official round button)
        mx, my = pygame.mouse.get_pos()
        if self.btn_back_surf is not None:
            screen.blit(self.btn_back_surf, (self.btn_back.x, self.btn_back.y))
        else:
            back_hover = self.btn_back.collidepoint((mx, my))
            back_col = (70, 75, 90) if back_hover else (45, 50, 65)
            pygame.draw.rect(screen, back_col, self.btn_back, border_radius=8)
            pygame.draw.rect(screen, COLOR_GOLD if back_hover else COLOR_GRAY, self.btn_back, width=2, border_radius=8)
            b_txt = self.btn_font.render("< 返回", True, COLOR_WHITE)
            screen.blit(b_txt, (self.btn_back.centerx - b_txt.get_width() // 2, self.btn_back.centery - b_txt.get_height() // 2))

        # 3. Render 6 stage cards for current page
        start_stage_id = self.current_page * self.STAGES_PER_PAGE + 1
        for slot_idx in range(self.STAGES_PER_PAGE):
            stage_id = start_stage_id + slot_idx
            if stage_id > 48:
                break

            card_r = self.get_stage_rect(slot_idx)
            unlocked = self.save_mgr.is_stage_unlocked(stage_id)
            cleared = self.save_mgr.is_stage_cleared(stage_id)
            hover = card_r.collidepoint((mx, my)) and unlocked

            stage_data = self.parser.get_stage(stage_id)
            stage_name = stage_data.name if stage_data else f"關卡 {stage_id}"
            stg_len = stage_data.length if stage_data else 3000
            stg_hp = stage_data.enemy_castle_hp if stage_data else 500
            stg_max_e = stage_data.max_enemy_count if stage_data else 3
            stg_spawns = len(stage_data.spawners) if stage_data else 0

            # Card background
            if unlocked:
                card_bg_col = (45, 50, 68) if hover else (32, 36, 50)
                border_col = COLOR_GOLD if hover else ((100, 180, 120) if cleared else (80, 90, 115))
            else:
                card_bg_col = (24, 26, 34)
                border_col = (50, 55, 65)

            pygame.draw.rect(screen, card_bg_col, card_r, border_radius=12)
            pygame.draw.rect(screen, border_col, card_r, width=2, border_radius=12)

            # Stage Title
            title_text = f"第 {stage_id} 關：{stage_name}"
            title_color = COLOR_WHITE if unlocked else (120, 120, 130)
            st_surf = self.card_font.render(title_text, True, title_color)
            screen.blit(st_surf, (card_r.x + 18, card_r.y + 16))

            # Status Badge
            if not unlocked:
                badge_surf = self.info_font.render("[ 未解鎖 ]", True, COLOR_RED)
            elif cleared:
                badge_surf = self.info_font.render("[ 已通關 ★ ]", True, COLOR_GOLD)
            else:
                badge_surf = self.info_font.render("[ 可進攻 ▶ ]", True, COLOR_GREEN)
            screen.blit(badge_surf, (card_r.right - badge_surf.get_width() - 18, card_r.y + 18))

            # Separator line
            pygame.draw.line(screen, (60, 65, 80), (card_r.x + 18, card_r.y + 50), (card_r.right - 18, card_r.y + 50), 1)

            # Stage Stats
            stat_color = (200, 205, 215) if unlocked else (100, 105, 115)
            stat1 = self.info_font.render(f"戰場長度: {stg_len} px", True, stat_color)
            stat2 = self.info_font.render(f"敵城體力: {stg_hp:,} HP", True, stat_color)
            stat3 = self.info_font.render(f"敵軍上限: {stg_max_e} 體 (波次: {stg_spawns})", True, stat_color)
            screen.blit(stat1, (card_r.x + 18, card_r.y + 65))
            screen.blit(stat2, (card_r.x + 18, card_r.y + 92))
            screen.blit(stat3, (card_r.x + 18, card_r.y + 119))

            # Action button
            act_r = pygame.Rect(card_r.x + 18, card_r.bottom - 46, card_r.width - 36, 32)
            if unlocked:
                act_bg = (180, 140, 40) if hover else (55, 110, 75)
                act_lbl = "點擊進攻 (ATTACK)" if hover else ("再次作戰" if cleared else "開始戰鬥")
                pygame.draw.rect(screen, act_bg, act_r, border_radius=6)
                pygame.draw.rect(screen, COLOR_GOLD if hover else COLOR_GREEN, act_r, width=1, border_radius=6)
                lbl_s = self.btn_font.render(act_lbl, True, COLOR_WHITE)
            else:
                pygame.draw.rect(screen, (35, 38, 48), act_r, border_radius=6)
                lbl_s = self.btn_font.render("請先通關前一關卡", True, (110, 115, 125))
            screen.blit(lbl_s, (act_r.centerx - lbl_s.get_width() // 2, act_r.centery - lbl_s.get_height() // 2))

        # 4. Pagination Controls
        prev_hover = self.btn_prev.collidepoint((mx, my)) and self.current_page > 0
        prev_bg = (70, 75, 90) if prev_hover else (45, 50, 65)
        prev_txt_col = COLOR_WHITE if self.current_page > 0 else (100, 100, 110)
        pygame.draw.rect(screen, prev_bg, self.btn_prev, border_radius=6)
        pygame.draw.rect(screen, COLOR_GOLD if prev_hover else COLOR_GRAY, self.btn_prev, width=1, border_radius=6)
        p_txt = self.btn_font.render("< 上一頁", True, prev_txt_col)
        screen.blit(p_txt, (self.btn_prev.centerx - p_txt.get_width() // 2, self.btn_prev.centery - p_txt.get_height() // 2))

        page_str = f"第 {self.current_page + 1} / {self.TOTAL_PAGES} 頁"
        page_s = self.card_font.render(page_str, True, COLOR_GOLD)
        screen.blit(page_s, (SCREEN_WIDTH // 2 - page_s.get_width() // 2, 652))

        next_hover = self.btn_next.collidepoint((mx, my)) and self.current_page < self.TOTAL_PAGES - 1
        next_bg = (70, 75, 90) if next_hover else (45, 50, 65)
        next_txt_col = COLOR_WHITE if self.current_page < self.TOTAL_PAGES - 1 else (100, 100, 110)
        pygame.draw.rect(screen, next_bg, self.btn_next, border_radius=6)
        pygame.draw.rect(screen, COLOR_GOLD if next_hover else COLOR_GRAY, self.btn_next, width=1, border_radius=6)
        n_txt = self.btn_font.render("下一頁 >", True, next_txt_col)
        screen.blit(n_txt, (self.btn_next.centerx - n_txt.get_width() // 2, self.btn_next.centery - n_txt.get_height() // 2))
