"""
Main Menu UI Screen - Authentic Official Battle Cats Edition.
Renders official Traditional Chinese game title logo (img011_logo.png),
official chapter buttons (img011_00_chapter_button.png, img011_01_chapter_japan.png),
authentic scrolling subtitle ticker from TitleMessage.csv,
and authentic skeletal animated Basic Cat walking along the ground line.
Zero generic procedural sky rects or Arial title text.
"""

import os
import pygame
from typing import Tuple, Optional, List
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

class MainMenuUI:
    def __init__(self, save_mgr: SaveManager):
        self.save_mgr = save_mgr
        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 32, bold=True)
        self.subtitle_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 20, bold=True)
        self.btn_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 20, bold=True)
        self.ver_font = pygame.font.SysFont("Consolas, Courier, Arial", 13)

        self.asset_mgr = AssetManager.get_instance()
        self.sound_mgr = SoundManager.get_instance()

        # 1. Background Setup (bg000.png)
        self.bg_surf = None
        self._init_bg()

        # 2. Official Logo (img011_logo.png)
        self.logo_surf = None
        self._init_logo()

        # 3. Chapter 1 Banner Button (img011_01_chapter_japan.png)
        self.bnr_surf = None
        self._init_banner()

        # 4. Title Subtitle Messages (TitleMessage.csv)
        self.messages: List[str] = []
        self._init_messages()

        # 5. Basic Cat Animation Player
        self.cat_anim = None
        self._init_cat_anim()

        # 6. Buttons
        btn_w, btn_h = 360, 64
        center_x = SCREEN_WIDTH // 2 - btn_w // 2
        start_y = 420

        self.btn_start = pygame.Rect(center_x, start_y, btn_w, btn_h)
        self.btn_sound = pygame.Rect(center_x, start_y + 80, btn_w, btn_h)
        self.btn_exit = pygame.Rect(center_x, start_y + 160, btn_w, btn_h)

    def _init_bg(self):
        bg = self.asset_mgr.get_texture("bg000")
        if bg is None:
            p = r"E:\rea\game_project\assets\official_extracted\bg000.png"
            if os.path.exists(p):
                bg = pygame.image.load(p)
        if bg is not None:
            try:
                sl = bg.subsurface((1, 1, 768, 510))
                scale = SCREEN_HEIGHT / 510.0
                bw = int(768 * scale)
                self.bg_surf = to_32bit(pygame.transform.smoothscale(sl, (bw, SCREEN_HEIGHT)))
            except Exception:
                pass

    def _init_logo(self):
        lg = self.asset_mgr.get_texture("img011_logo")
        if lg is None:
            p = r"E:\rea\game_project\assets\official_extracted\img011_logo.png"
            if os.path.exists(p):
                lg = pygame.image.load(p)
        if lg is not None:
            try:
                w = 560
                h = int(lg.get_height() * (w / lg.get_width()))
                self.logo_surf = to_32bit(pygame.transform.smoothscale(lg, (w, h)))
            except Exception:
                pass

    def _init_banner(self):
        bnr = self.asset_mgr.get_texture("img011_01_chapter_japan")
        if bnr is None:
            p = r"E:\rea\game_project\assets\official_extracted\img011_01_chapter_japan.png"
            if os.path.exists(p):
                bnr = pygame.image.load(p)
        if bnr is not None:
            try:
                self.bnr_surf = to_32bit(pygame.transform.smoothscale(bnr, (360, 64)))
            except Exception:
                pass

    def _init_messages(self):
        p = r"E:\rea\game_project\data\official_extracted_data\TitleMessage.csv"
        if not os.path.exists(p):
            p = r"E:\rea\temp\TitleMessage.csv"
        if os.path.exists(p):
            try:
                with open(p, "r", encoding="utf-8", errors="ignore") as f:
                    for line in f:
                        line = line.strip()
                        if "|" in line:
                            msg = line.split("|", 1)[1].replace("<br>", " ")
                            if msg and msg not in self.messages:
                                self.messages.append(msg)
            except Exception:
                pass
        if not self.messages:
            self.messages = [
                "寶物收集完成的話 貓咪們的能力就會大幅提升！",
                "侵略全世界中！",
                "全世界中還有正在沉睡著 未被找到的寶物呀",
                "突破第1章後 將能得到強力角色唷！"
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
        """Returns action string: 'start', 'sound_toggle', 'exit', or None."""
        if self.btn_start.collidepoint(mouse_pos):
            self.sound_mgr.play("click")
            return "start"
        elif self.btn_sound.collidepoint(mouse_pos):
            self.sound_mgr.play("click")
            enabled = self.save_mgr.toggle_sound()
            self.sound_mgr.enabled = enabled
            return "sound_toggle"
        elif self.btn_exit.collidepoint(mouse_pos):
            self.sound_mgr.play("click")
            return "exit"
        return None

    def render(self, surface: pygame.Surface, frame: int):
        # 1. Background
        if self.bg_surf is not None:
            bw = self.bg_surf.get_width()
            bx = 0
            while bx < SCREEN_WIDTH:
                surface.blit(self.bg_surf, (bx, 0))
                bx += bw
            overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
            overlay.fill((0, 0, 0, 45))
            surface.blit(overlay, (0, 0))
        else:
            surface.fill((139, 219, 254))

        # 2. Authentic Logo
        if self.logo_surf is not None:
            surface.blit(self.logo_surf, (SCREEN_WIDTH // 2 - self.logo_surf.get_width() // 2, 35))
        else:
            title_txt = "貓 咪 大 戰 爭"
            t_surf = self.title_font.render(title_txt, True, COLOR_GOLD)
            surface.blit(t_surf, (SCREEN_WIDTH // 2 - t_surf.get_width() // 2, 80))

        # 3. Subtitle Ticker (from TitleMessage.csv)
        if self.messages:
            msg_idx = (frame // 120) % len(self.messages)
            msg = self.messages[msg_idx]
            msg_s = self.subtitle_font.render(msg, True, (255, 245, 180))
            # Background pill for readability
            pill_rect = pygame.Rect(
                SCREEN_WIDTH // 2 - msg_s.get_width() // 2 - 20,
                350,
                msg_s.get_width() + 40,
                38
            )
            pygame.draw.rect(surface, (20, 20, 30, 180), pill_rect, border_radius=19)
            pygame.draw.rect(surface, COLOR_GOLD, pill_rect, width=2, border_radius=19)
            surface.blit(msg_s, (SCREEN_WIDTH // 2 - msg_s.get_width() // 2, 356))

        # 4. Animated Basic Cat walking across bottom ground
        ground_y = 660
        cat_pos = (frame * 3) % (SCREEN_WIDTH + 200) - 80
        if self.cat_anim is not None:
            self.cat_anim.current_frame = float(frame % 16)
            self.cat_anim.render(surface, int(cat_pos), ground_y, scale=1.2, flip_h=False)

        # 5. Action Buttons
        # Start button
        if self.bnr_surf is not None:
            surface.blit(self.bnr_surf, (self.btn_start.x, self.btn_start.y))
        else:
            pygame.draw.rect(surface, (40, 140, 60), self.btn_start, border_radius=12)
            pygame.draw.rect(surface, COLOR_GOLD, self.btn_start, width=2, border_radius=12)
            lbl_start = self.btn_font.render("進入貓咪基地 (Start Game)", True, COLOR_WHITE)
            surface.blit(lbl_start, (self.btn_start.centerx - lbl_start.get_width() // 2, self.btn_start.centery - lbl_start.get_height() // 2))

        # Sound button
        pygame.draw.rect(surface, (45, 60, 90), self.btn_sound, border_radius=12)
        pygame.draw.rect(surface, COLOR_WHITE, self.btn_sound, width=2, border_radius=12)
        snd_label = f"音效: {'開啟 (ON)' if self.save_mgr.data.get('sound_enabled', True) else '關閉 (OFF)'}"
        lbl_snd = self.btn_font.render(snd_label, True, COLOR_WHITE)
        surface.blit(lbl_snd, (self.btn_sound.centerx - lbl_snd.get_width() // 2, self.btn_sound.centery - lbl_snd.get_height() // 2))

        # Exit button
        pygame.draw.rect(surface, (140, 50, 50), self.btn_exit, border_radius=12)
        pygame.draw.rect(surface, COLOR_WHITE, self.btn_exit, width=2, border_radius=12)
        lbl_exit = self.btn_font.render("離開遊戲 (Exit)", True, COLOR_WHITE)
        surface.blit(lbl_exit, (self.btn_exit.centerx - lbl_exit.get_width() // 2, self.btn_exit.centery - lbl_exit.get_height() // 2))

        # Version stamp
        v_s = self.ver_font.render("v15.6.1 Traditional Chinese Parity Edition - Ponos Authentic Architecture", True, (210, 220, 235))
        surface.blit(v_s, (SCREEN_WIDTH - v_s.get_width() - 20, SCREEN_HEIGHT - 24))
