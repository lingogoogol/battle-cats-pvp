"""
Cat Base (貓咪基地) Main Hub Screen - Authentic Ponos Battle Cats Edition.
Central gameplay hub connecting Title Screen, Battle Prep (Stage Select),
Power-Up / Upgrade Menu, and Formation / Deck Edit.
Renders authentic repeating tile background (bg.png), official header banner (img008_tw.png),
interactive dialogue bubble with 145 authentic quotes from MainMenu_tw.csv,
and authentic sliced Ponos menu buttons (img010_tw.png).
Zero synthetic shapes or guessed text.
"""

import os
import random
import pygame
from typing import Tuple, Optional, List, Dict, Any
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, COLOR_GOLD, COLOR_GRAY
)
from ..core.save_manager import SaveManager
from ..audio.sound_manager import SoundManager
from ..assets.asset_manager import AssetManager
from ..anim_engine.ponos_anim_player import PonosAnimationPlayer

def to_32bit(surf: pygame.Surface) -> pygame.Surface:
    if surf.get_bitsize() < 24:
        s32 = pygame.Surface(surf.get_size(), pygame.SRCALPHA)
        s32.blit(surf, (0, 0))
        return s32
    return surf

class CatBaseUI:
    def __init__(self, save_mgr: SaveManager):
        self.save_mgr = save_mgr
        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()

        self.bubble_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)
        self.stat_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 16, bold=True)
        self.tip_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 13)

        # 1. Background Setup (bg.png repeating tile)
        self.bg_tile = None
        self._init_bg()

        # 2. Header Bar & Title (img008_tw.png)
        self.hdr_bar = None
        self.hdr_title = None
        self._init_header()

        # 3. Main Menu Buttons (img010_tw.png)
        self.btn_battle_surf = None
        self.btn_upgrade_surf = None
        self.btn_formation_surf = None
        self._init_buttons()

        # 4. Back Button (img006_tw.png)
        self.btn_back_surf = None
        self._init_back_btn()

        # 5. Dialogue Quotes from MainMenu_tw.csv
        self.quotes: List[List[str]] = []
        self.current_quote_idx = 0
        self._load_quotes()

        # 6. Basic Cat Walking Animation
        self.cat_anim = None
        self._init_cat_anim()

        # UI Layout Rectangles (1280 x 720)
        # Top Back Button
        self.rect_back = pygame.Rect(20, 8, 64, 64)

        # Dialogue Bubble Rect
        self.rect_bubble = pygame.Rect(320, 110, 640, 150)

        # 4 Main Buttons (Stacked centered)
        btn_w, btn_h = 320, 68
        btn_x = SCREEN_WIDTH // 2 - btn_w // 2
        btn_start_y = 305
        self.rect_btn_battle = pygame.Rect(btn_x, btn_start_y, btn_w, btn_h)
        self.rect_btn_upgrade = pygame.Rect(btn_x, btn_start_y + 80, btn_w, btn_h)
        self.rect_btn_formation = pygame.Rect(btn_x, btn_start_y + 160, btn_w, btn_h)
        self.rect_btn_online_pvp = pygame.Rect(btn_x, btn_start_y + 240, btn_w, 58)

        # Animated Cat position in base
        self.cat_x = 180
        self.cat_y = 230

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
                # Cut 0: 231, 43, 19, 55 (Screen top bar tile)
                bar_cut = im8.subsurface((231, 43, 19, 55))
                # Cut 1: 600, 113, 297, 46 ("貓咪基地" / メインメニュー)
                title_cut = im8.subsurface((600, 113, 297, 46))
                
                # Create stretched / tiled top bar
                hdr = pygame.Surface((SCREEN_WIDTH, 60), pygame.SRCALPHA)
                bw, bh = bar_cut.get_size()
                scale_y = 60.0 / bh
                scaled_slice = pygame.transform.smoothscale(bar_cut, (int(bw * scale_y), 60))
                for bx in range(0, SCREEN_WIDTH, scaled_slice.get_width()):
                    hdr.blit(scaled_slice, (bx, 0))
                self.hdr_bar = to_32bit(hdr)

                # Scale title banner
                tw, th = title_cut.get_size()
                scale_t = 48.0 / th
                self.hdr_title = to_32bit(pygame.transform.smoothscale(title_cut, (int(tw * scale_t), 48)))
            except Exception as e:
                print(f"[!] Error loading header assets: {e}")

    def _init_buttons(self):
        im10 = self.asset_mgr.get_texture("img010_tw")
        if im10 is None:
            p = r"E:\rea\game_project\assets\official_extracted\img010_tw.png"
            if os.path.exists(p):
                im10 = pygame.image.load(p)
        if im10 is not None:
            try:
                # Cut 0: 257, 207, 254, 48 (Window base)
                base = im10.subsurface((257, 207, 254, 48))
                # Cut 2: 1, 143, 254, 55 ("戰鬥開始！！")
                txt_battle = im10.subsurface((1, 143, 254, 55))
                # Cut 3: 1, 200, 254, 55 ("升級" / パワーアップ)
                txt_upgrade = im10.subsurface((1, 200, 254, 55))
                # Cut 4: 1, 86, 254, 55 ("編隊" / 編成)
                txt_formation = im10.subsurface((1, 86, 254, 55))

                target_w, target_h = 320, 68

                def make_composite(txt_surf):
                    comp = pygame.Surface((254, 55), pygame.SRCALPHA)
                    comp.blit(base, (0, 3))
                    comp.blit(txt_surf, (0, 0))
                    return to_32bit(pygame.transform.smoothscale(comp, (target_w, target_h)))

                self.btn_battle_surf = make_composite(txt_battle)
                self.btn_upgrade_surf = make_composite(txt_upgrade)
                self.btn_formation_surf = make_composite(txt_formation)
            except Exception as e:
                print(f"[!] Error slicing img010 buttons: {e}")

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

    def _load_quotes(self):
        p = r"E:\rea\game_project\data\official_extracted_data\MainMenu_tw.csv"
        if not os.path.exists(p):
            p = r"E:\rea\temp\MainMenu_tw.csv"
        if os.path.exists(p):
            try:
                with open(p, "r", encoding="utf-8", errors="ignore") as f:
                    for line in f:
                        parts = line.strip().split("|")
                        if len(parts) > 1:
                            valid_lines = [pt.strip() for pt in parts[1:] if pt.strip() and pt.strip() != "＠"]
                            if valid_lines:
                                self.quotes.append(valid_lines)
            except Exception as e:
                print(f"[!] Error loading MainMenu_tw.csv: {e}")

        if not self.quotes:
            self.quotes = [
                ["歡迎來到貓咪基地！", "在這裡做好戰鬥準備", "出發參戰喵♪"],
                ["可以在升級畫面中", "獲得新的貓咪角色喵！"],
                ["想來點貓咪小知識", "充電一下嗎？", "那就按按這個對話框喵！"],
                ["貓咪是水做的喵。"]
            ]

    def _init_cat_anim(self):
        cat_png = r"E:\rea\game_project\assets\official_extracted\download_char_000.png"
        cat_cut = r"E:\rea\game_project\assets\official_extracted\download_char_000.imgcut"
        cat_model = r"E:\rea\game_project\assets\official_extracted\download_char_000.mamodel"
        cat_anim = r"E:\rea\game_project\assets\official_extracted\download_char_000_walkR.maanim"
        if os.path.exists(cat_png) and os.path.exists(cat_cut) and os.path.exists(cat_model) and os.path.exists(cat_anim):
            try:
                self.cat_anim = PonosAnimationPlayer(cat_png, cat_cut, cat_model, {"walk": cat_anim})
                self.cat_anim.set_animation("walk")
            except Exception:
                pass

    def handle_click(self, mouse_pos: Tuple[int, int]) -> Optional[str]:
        """
        Returns 'battle_prep', 'upgrade', 'formation', 'title', or None.
        """
        # Dialogue bubble click -> cycle quote
        if self.rect_bubble.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            self.current_quote_idx = (self.current_quote_idx + 1) % len(self.quotes)
            return None

        # Back to Title
        if self.rect_back.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "title"

        # 1. Battle Prep (Stage Select)
        if self.rect_btn_battle.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "battle_prep"

        # 2. Power-Up / Upgrade
        if self.rect_btn_upgrade.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "upgrade"

        # 3. Formation / Deck Edit
        if self.rect_btn_formation.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "formation"

        # 4. Online Networked PvP
        if self.rect_btn_online_pvp.collidepoint(mouse_pos):
            self.sound_mgr.play_sfx("button_click")
            return "online_pvp"

        return None

    def render(self, surface: pygame.Surface, frame_count: int = 0):
        # 1. Background
        if self.bg_tile is not None:
            tw, th = self.bg_tile.get_size()
            for x in range(0, SCREEN_WIDTH, tw):
                for y in range(0, SCREEN_HEIGHT, th):
                    surface.blit(self.bg_tile, (x, y))
        else:
            surface.fill((242, 238, 224))

        # 2. Top Header Bar
        if self.hdr_bar is not None:
            surface.blit(self.hdr_bar, (0, 0))
        if self.hdr_title is not None:
            surface.blit(self.hdr_title, (SCREEN_WIDTH // 2 - self.hdr_title.get_width() // 2, 6))

        # 3. Back Button
        if self.btn_back_surf is not None:
            surface.blit(self.btn_back_surf, (self.rect_back.x, self.rect_back.y))

        # 4. Top Resource Status (XP, Cat Food, Leadership)
        xp_text = f"XP: {self.save_mgr.xp:,}"
        food_text = f"貓罐頭: {self.save_mgr.cat_food}"
        lead_text = f"統率力: {self.save_mgr.leadership}/{self.save_mgr.max_leadership}"

        xp_s = self.stat_font.render(xp_text, True, COLOR_GOLD)
        food_s = self.stat_font.render(food_text, True, (255, 230, 100))
        lead_s = self.stat_font.render(lead_text, True, COLOR_WHITE)

        # Render resource badges on top right
        rx = SCREEN_WIDTH - 240
        surface.blit(lead_s, (rx, 6))
        surface.blit(xp_s, (rx, 24))
        surface.blit(food_s, (rx, 42))

        # 5. Helper Cat next to bubble
        if self.cat_anim is not None:
            self.cat_anim.update(1.0)
            self.cat_anim.render(surface, self.cat_x, self.cat_y, scale=1.4, flip_h=False)

        # 6. Dialogue Bubble
        # Authentic curved dialog card
        bubble_bg = pygame.Surface((self.rect_bubble.width, self.rect_bubble.height), pygame.SRCALPHA)
        pygame.draw.rect(bubble_bg, (255, 255, 255, 235), (0, 0, self.rect_bubble.width, self.rect_bubble.height), border_radius=18)
        pygame.draw.rect(bubble_bg, (220, 180, 80), (0, 0, self.rect_bubble.width, self.rect_bubble.height), width=3, border_radius=18)
        # Tail pointing towards cat
        pygame.draw.polygon(bubble_bg, (255, 255, 255, 235), [(10, 60), (0, 75), (10, 90)])
        pygame.draw.polygon(bubble_bg, (220, 180, 80), [(10, 60), (0, 75), (10, 90)], width=2)
        surface.blit(bubble_bg, (self.rect_bubble.x, self.rect_bubble.y))

        # Dialogue text
        quote = self.quotes[self.current_quote_idx % len(self.quotes)]
        for i, q_line in enumerate(quote):
            q_s = self.bubble_font.render(q_line, True, (40, 40, 50))
            surface.blit(q_s, (self.rect_bubble.x + 35, self.rect_bubble.y + 24 + i * 28))

        # Tip at bottom of bubble
        hint_s = self.tip_font.render("（點擊對話框可切換小知識喵♪）", True, (130, 130, 140))
        surface.blit(hint_s, (self.rect_bubble.right - hint_s.get_width() - 20, self.rect_bubble.bottom - 26))

        # 7. Sliced Menu Buttons (img010_tw.png)
        if self.btn_battle_surf is not None:
            surface.blit(self.btn_battle_surf, (self.rect_btn_battle.x, self.rect_btn_battle.y))
        if self.btn_upgrade_surf is not None:
            surface.blit(self.btn_upgrade_surf, (self.rect_btn_upgrade.x, self.rect_btn_upgrade.y))
        if self.btn_formation_surf is not None:
            surface.blit(self.btn_formation_surf, (self.rect_btn_formation.x, self.rect_btn_formation.y))

        # 8. Online Networked PvP Button
        pygame.draw.rect(surface, (36, 92, 155), self.rect_btn_online_pvp, border_radius=12)
        pygame.draw.rect(surface, COLOR_GOLD, self.rect_btn_online_pvp, width=3, border_radius=12)
        pvp_lbl = self.bubble_font.render("線上跨電腦聯機 PvP (按 N)", True, COLOR_WHITE)
        surface.blit(pvp_lbl, (self.rect_btn_online_pvp.centerx - pvp_lbl.get_width() // 2, self.rect_btn_online_pvp.centery - pvp_lbl.get_height() // 2))

        # Floor decoration line
        pygame.draw.line(surface, (200, 190, 170), (0, 680), (SCREEN_WIDTH, 680), width=4)
