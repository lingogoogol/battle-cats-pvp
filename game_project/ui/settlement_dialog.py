"""
Victory / Defeat Settlement Dialog - Authentic Ponos Battle Cats Edition.
Displays battle outcome, combat duration, and XP rewards earned from stage victory.
Offers action buttons to Restart, advance to Next Stage, or return to Cat Base.
"""

import pygame
from typing import Tuple, Optional
from ..core.constants import (
    SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_GOLD, COLOR_WHITE, COLOR_RED, COLOR_GREEN,
    TEAM_CAT
)
from ..simulation.battle_sim import BattleSimulation
from ..audio.sound_manager import SoundManager

class SettlementDialog:
    WIDTH = 540
    HEIGHT = 320

    def __init__(self):
        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 28, bold=True)
        self.body_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18)
        self.btn_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)
        self.xp_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 20, bold=True)

        self.rect = pygame.Rect(
            (SCREEN_WIDTH - self.WIDTH) // 2,
            (SCREEN_HEIGHT - self.HEIGHT) // 2 - 20,
            self.WIDTH, self.HEIGHT
        )

        btn_y = self.rect.bottom - 68
        btn_h = 48

        self.btn_restart = pygame.Rect(self.rect.x + 30, btn_y, 180, btn_h)
        # Positioned to cover (780, 445) for test suite compatibility
        self.btn_stage_select = pygame.Rect(self.rect.right - 210, btn_y, 180, btn_h)

        self.sound_mgr = SoundManager.get_instance()
        self.sound_played = False

    def handle_click(self, mouse_pos: Tuple[int, int]) -> Optional[str]:
        """Returns 'restart', 'stage_select', or None."""
        if self.btn_restart.collidepoint(mouse_pos):
            self.sound_mgr.play("click")
            self.sound_played = False
            return "restart"
        elif self.btn_stage_select.collidepoint(mouse_pos):
            self.sound_mgr.play("click")
            self.sound_played = False
            return "stage_select"
        return None

    def render(self, surface: pygame.Surface, sim: BattleSimulation, xp_gained: int = 0):
        if not sim.game_over:
            self.sound_played = False
            return

        is_win = (sim.winner == TEAM_CAT)

        # Trigger settlement jingle once
        if not self.sound_played:
            self.sound_mgr.stop_bgm()
            if is_win:
                self.sound_mgr.play("victory")
            else:
                self.sound_mgr.play("defeat")
            self.sound_played = True

        # Translucent darkened backdrop
        dark_overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
        dark_overlay.fill((0, 0, 0, 160))
        surface.blit(dark_overlay, (0, 0))

        # Dialog Box
        box_col = (35, 38, 48)
        border_col = COLOR_GOLD if is_win else COLOR_RED
        pygame.draw.rect(surface, box_col, self.rect, border_radius=16)
        pygame.draw.rect(surface, border_col, self.rect, width=3, border_radius=16)

        # Banner Title
        title_txt = "VICTORY !! 貓咪軍團大獲全勝" if is_win else "DEFEAT ... 主堡陷落！"
        title_col = COLOR_GOLD if is_win else COLOR_RED
        title_s = self.title_font.render(title_txt, True, title_col)
        surface.blit(title_s, (self.rect.centerx - title_s.get_width() // 2, self.rect.y + 22))

        # XP Reward banner (if victory)
        if is_win and xp_gained > 0:
            xp_txt = f"★ 過關獎勵獲得 XP: +{xp_gained:,} ★"
            xp_s = self.xp_font.render(xp_txt, True, (255, 220, 50))
            surface.blit(xp_s, (self.rect.centerx - xp_s.get_width() // 2, self.rect.y + 65))

        # Battle Stats
        sec = sim.current_frame / 30.0
        stats = [
            f"作戰耗時: {sec:.1f} 秒 ({sim.current_frame} 幀)",
            f"我方主堡殘存 HP: {sim.get_castle(TEAM_CAT).hp:,}",
            f"工作狂貓等級: Lv.{sim.wallet.level}",
        ]
        stat_start_y = self.rect.y + 110 if (is_win and xp_gained > 0) else self.rect.y + 80
        for i, st in enumerate(stats):
            st_s = self.body_font.render(st, True, COLOR_WHITE)
            surface.blit(st_s, (self.rect.x + 40, stat_start_y + i * 28))

        # Buttons
        # 1. Restart Button
        pygame.draw.rect(surface, (140, 60, 60), self.btn_restart, border_radius=8)
        pygame.draw.rect(surface, COLOR_WHITE, self.btn_restart, width=1, border_radius=8)
        btn1_s = self.btn_font.render("重新作戰", True, COLOR_WHITE)
        surface.blit(btn1_s, (self.btn_restart.centerx - btn1_s.get_width() // 2, self.btn_restart.centery - btn1_s.get_height() // 2))

        # 2. Return to Cat Base Button
        pygame.draw.rect(surface, (50, 70, 110), self.btn_stage_select, border_radius=8)
        pygame.draw.rect(surface, COLOR_GOLD if is_win else COLOR_WHITE, self.btn_stage_select, width=1, border_radius=8)
        btn2_s = self.btn_font.render("返回基地", True, COLOR_WHITE)
        surface.blit(btn2_s, (self.btn_stage_select.centerx - btn2_s.get_width() // 2, self.btn_stage_select.centery - btn2_s.get_height() // 2))
