"""
Official Battle Cats Top HUD.
Renders authentic top-right money wallet and pause button.
Zero procedural sky bars or fake health banners.
"""

import os
import pygame
from ..core.constants import (
    SCREEN_WIDTH, COLOR_WHITE, COLOR_GOLD, TEAM_CAT, TEAM_ENEMY
)
from ..simulation.battle_sim import BattleSimulation
from ..assets.asset_manager import AssetManager

class BattleHUD:
    HUD_HEIGHT = 70

    def __init__(self):
        self.font = pygame.font.SysFont("Microsoft JhengHei, Arial", 14, bold=True)
        self.dollar_font = pygame.font.SysFont("Impact, Arial", 28, bold=True)
        self.asset_mgr = AssetManager.get_instance()
        
        # Load authentic digit cuts from img001_tw.png
        self.im1 = self.asset_mgr.get_texture("img001_tw")
        self.im2 = self.asset_mgr.get_texture("img002_tw")

        self.digit_cuts = {
            '0': (1, 1, 30, 42), '1': (33, 1, 30, 42), '2': (65, 1, 30, 42),
            '3': (97, 1, 30, 42), '4': (129, 1, 30, 42), '5': (161, 1, 30, 42),
            '6': (193, 1, 30, 42), '7': (225, 1, 30, 42), '8': (1, 45, 30, 42),
            '9': (33, 45, 30, 42), '/': (66, 45, 29, 42), 'unit': (102, 45, 30, 42)
        }
        self.opt_rect = pygame.Rect(SCREEN_WIDTH - 72, 14, 58, 58)

    def render(self, surface: pygame.Surface, sim: BattleSimulation, local_team: int = TEAM_CAT, net_status: str = ""):
        # 1. Top Right Pause / Options Button
        if self.im2 is not None:
            try:
                opt_sub = self.im2.subsurface((519, 256, 58, 58))
                surface.blit(opt_sub, self.opt_rect)
            except Exception:
                pass

        # 2. Top Right Authentic Battle Cats Money Wallet (Local Player's Wallet)
        local_wallet = sim.wallets.get(local_team, sim.wallet)
        cur_money, max_money, _, _ = local_wallet.get_status()
        cur_str = str(cur_money)
        max_str = str(max_money)

        cur_x = SCREEN_WIDTH - 85

        if self.im1 is not None:
            try:
                # Render official currency unit (元) on the far right
                unit_rec = self.digit_cuts['unit']
                cur_x -= unit_rec[2]
                surface.blit(self.im1.subsurface(unit_rec), (cur_x, 18))
                cur_x -= 4

                # Render max money digits (right to left)
                for ch in reversed(max_str):
                    if ch in self.digit_cuts:
                        rec = self.digit_cuts[ch]
                        sub = self.im1.subsurface(rec)
                        cur_x -= (rec[2] + 2)
                        surface.blit(sub, (cur_x, 18))

                # Render slash
                slash_rec = self.digit_cuts['/']
                cur_x -= (slash_rec[2] + 4)
                surface.blit(self.im1.subsurface(slash_rec), (cur_x, 18))

                # Render current money digits
                for ch in reversed(cur_str):
                    if ch in self.digit_cuts:
                        rec = self.digit_cuts[ch]
                        sub = self.im1.subsurface(rec)
                        cur_x -= (rec[2] + 2)
                        surface.blit(sub, (cur_x, 18))
            except Exception:
                pass
        else:
            money_str = f"{cur_money} / {max_money} 元"
            m_surf = self.dollar_font.render(money_str, True, COLOR_GOLD)
            surface.blit(m_surf, (SCREEN_WIDTH - 85 - m_surf.get_width(), 20))

        # 3. In 2-Player PvP mode, render Opponent's Authentic Wallet on the Top-Left
        if getattr(sim, "pvp_mode", False) and getattr(sim, "p2_wallet", None) is not None:
            opp_team = TEAM_ENEMY if local_team == TEAM_CAT else TEAM_CAT
            opp_wallet = sim.wallets.get(opp_team, sim.p2_wallet)
            p2_cur, p2_max, p2_lvl, _ = opp_wallet.get_status()
            p2_cur_str = str(p2_cur)
            p2_max_str = str(p2_max)
            lx = 18
            if self.im1 is not None:
                try:
                    for ch in p2_cur_str:
                        if ch in self.digit_cuts:
                            rec = self.digit_cuts[ch]
                            surface.blit(self.im1.subsurface(rec), (lx, 18))
                            lx += rec[2] + 2
                    slash_rec = self.digit_cuts['/']
                    surface.blit(self.im1.subsurface(slash_rec), (lx, 18))
                    lx += slash_rec[2] + 4
                    for ch in p2_max_str:
                        if ch in self.digit_cuts:
                            rec = self.digit_cuts[ch]
                            surface.blit(self.im1.subsurface(rec), (lx, 18))
                            lx += rec[2] + 2
                    unit_rec = self.digit_cuts['unit']
                    surface.blit(self.im1.subsurface(unit_rec), (lx + 2, 18))
                except Exception:
                    pass
            if net_status:
                p2_tag = self.font.render(net_status, True, (120, 255, 180))
            else:
                p2_tag = self.font.render(f"對手錢包 Lv.{p2_lvl} | 按 N 開啟跨電腦連線對戰 (Online PvP)", True, COLOR_WHITE)
            pill = pygame.Surface((p2_tag.get_width() + 16, p2_tag.get_height() + 6), pygame.SRCALPHA)
            pill.fill((18, 22, 32, 185))
            surface.blit(pill, (14, 62))
            surface.blit(p2_tag, (22, 65))
