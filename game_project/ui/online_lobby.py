"""
In-Game Online PvP Lobby & IP Connect Modal (`online_lobby.py`).
Allows two players on separate computers (LAN / Internet) to Host or Join an Online PvP room,
type/paste the Host's IP:Port, automatically synchronize custom characters (`custom_units/*.json`),
and transition into a frame-synchronized lockstep battle.
"""

import pygame
from typing import Optional, Dict, Any
from ..core.constants import SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, COLOR_GOLD
from ..network.pvp_net import get_local_ip


class OnlineLobbyOverlay:
    def __init__(self):
        self.visible: bool = False
        self.lan_ip: str = get_local_ip()
        self.ip_input: str = f"{self.lan_ip}:7777"
        self.host_port: int = 7777
        self.input_active: bool = True

        self.title_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 28, bold=True)
        self.font = pygame.font.SysFont("Microsoft JhengHei, Arial", 18, bold=True)
        self.small_font = pygame.font.SysFont("Microsoft JhengHei, Arial", 14)
        self.mono_font = pygame.font.SysFont("Consolas, Courier, Arial", 22, bold=True)

        # Modal layout
        self.panel_rect = pygame.Rect(SCREEN_WIDTH // 2 - 340, SCREEN_HEIGHT // 2 - 220, 680, 440)
        self.btn_host = pygame.Rect(self.panel_rect.x + 40, self.panel_rect.y + 135, 280, 56)
        self.input_box = pygame.Rect(self.panel_rect.x + 40, self.panel_rect.y + 265, 360, 48)
        self.btn_join = pygame.Rect(self.panel_rect.x + 420, self.panel_rect.y + 265, 220, 48)
        self.btn_close = pygame.Rect(self.panel_rect.right - 130, self.panel_rect.bottom - 58, 100, 40)

    def toggle(self):
        self.visible = not self.visible
        if self.visible:
            self.lan_ip = get_local_ip()

    def handle_keydown(self, event: pygame.event.Event) -> Optional[Dict[str, Any]]:
        if not self.visible:
            return None
        if event.key == pygame.K_ESCAPE:
            self.visible = False
            return {"action": "close"}
        if event.key == pygame.K_RETURN:
            return self._parse_join_action()
        if event.key == pygame.K_BACKSPACE:
            self.ip_input = self.ip_input[:-1]
            return None
        if event.key == pygame.K_v and (event.mod & pygame.KMOD_CTRL):
            try:
                if pygame.scrap.get_init():
                    clip = pygame.scrap.get(pygame.SCRAP_TEXT)
                    if clip:
                        txt = clip.decode("utf-8", errors="ignore").strip("\x00 \r\n\t")
                        self.ip_input = txt
            except Exception:
                pass
            return None
        ch = event.unicode
        if ch and (ch.isalnum() or ch in ".:-_"):
            if len(self.ip_input) < 42:
                self.ip_input += ch
        return None

    def _parse_join_action(self) -> Dict[str, Any]:
        raw = self.ip_input.strip()
        if ":" in raw:
            host_part, port_part = raw.rsplit(":", 1)
            try:
                port = int(port_part)
            except ValueError:
                port = 7777
        else:
            host_part = raw or "127.0.0.1"
            port = 7777
        return {"action": "connect", "host": host_part.strip() or "127.0.0.1", "port": port}

    def handle_click(self, mouse_pos) -> Optional[Dict[str, Any]]:
        if not self.visible:
            return None
        if self.btn_close.collidepoint(mouse_pos):
            self.visible = False
            return {"action": "close"}
        if self.btn_host.collidepoint(mouse_pos):
            return {"action": "host", "port": self.host_port}
        if self.btn_join.collidepoint(mouse_pos):
            return self._parse_join_action()
        if self.input_box.collidepoint(mouse_pos):
            self.input_active = True
            return None
        return None

    def render(self, surface: pygame.Surface, net_session=None, custom_unit_count: int = 0):
        if not self.visible:
            return

        # Dim backdrop
        dim = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
        dim.fill((0, 0, 0, 175))
        surface.blit(dim, (0, 0))

        # Main modal panel
        pygame.draw.rect(surface, (26, 30, 42), self.panel_rect, border_radius=14)
        pygame.draw.rect(surface, COLOR_GOLD, self.panel_rect, width=3, border_radius=14)

        title = self.title_font.render("線上跨電腦聯機對戰 (Online PvP)", True, COLOR_GOLD)
        surface.blit(title, (self.panel_rect.centerx - title.get_width() // 2, self.panel_rect.y + 20))

        sub = self.small_font.render(
            f"支援區域網路 (LAN) / 虛擬區網 (Radmin/Tailscale/ZeroTier) / 公網 IP 直連 | 已載入 {custom_unit_count} 個自製角色 (連線自動同步)",
            True, (190, 215, 240)
        )
        surface.blit(sub, (self.panel_rect.centerx - sub.get_width() // 2, self.panel_rect.y + 62))

        # Section 1: Host
        host_lbl = self.font.render(f"【方式 A：建立房間 (當 P1 右側主堡)】 本機區網 IP: {self.lan_ip}:{self.host_port}", True, COLOR_WHITE)
        surface.blit(host_lbl, (self.panel_rect.x + 40, self.panel_rect.y + 100))

        pygame.draw.rect(surface, (42, 115, 75), self.btn_host, border_radius=10)
        pygame.draw.rect(surface, (110, 235, 160), self.btn_host, width=2, border_radius=10)
        h_txt = self.font.render("建立房間 (Host Port 7777)", True, COLOR_WHITE)
        surface.blit(h_txt, (self.btn_host.centerx - h_txt.get_width() // 2, self.btn_host.centery - h_txt.get_height() // 2))

        # Section 2: Client Join
        join_lbl = self.font.render("【方式 B：加入朋友房間 (當 P2 左側主堡)】 輸入房主 IP:Port 後點擊連線：", True, COLOR_WHITE)
        surface.blit(join_lbl, (self.panel_rect.x + 40, self.panel_rect.y + 225))

        pygame.draw.rect(surface, (16, 18, 26), self.input_box, border_radius=8)
        pygame.draw.rect(surface, (90, 180, 255) if self.input_active else (80, 90, 110), self.input_box, width=2, border_radius=8)
        ip_surf = self.mono_font.render(self.ip_input + ("|" if (pygame.time.get_ticks() // 400) % 2 == 0 else ""), True, (255, 245, 180))
        surface.blit(ip_surf, (self.input_box.x + 14, self.input_box.centery - ip_surf.get_height() // 2))

        pygame.draw.rect(surface, (45, 95, 165), self.btn_join, border_radius=10)
        pygame.draw.rect(surface, (120, 195, 255), self.btn_join, width=2, border_radius=10)
        j_txt = self.font.render("連線加入 (Connect)", True, COLOR_WHITE)
        surface.blit(j_txt, (self.btn_join.centerx - j_txt.get_width() // 2, self.btn_join.centery - j_txt.get_height() // 2))

        # Live Network Status Bar
        status_rect = pygame.Rect(self.panel_rect.x + 40, self.panel_rect.y + 335, 600, 38)
        pygame.draw.rect(surface, (18, 22, 30), status_rect, border_radius=6)
        if net_session is not None:
            st_col = (100, 255, 160) if net_session.state == "READY" else ((255, 110, 110) if net_session.state == "ERROR" else (255, 220, 110))
            st_str = net_session.status_message
        else:
            st_col = (170, 180, 200)
            st_str = "狀態：尚未連線（可隨時點擊上方按鈕建立房間或連入朋友電腦）"
        st_surf = self.small_font.render(st_str, True, st_col)
        surface.blit(st_surf, (status_rect.x + 12, status_rect.centery - st_surf.get_height() // 2))

        # Close button
        pygame.draw.rect(surface, (90, 45, 50), self.btn_close, border_radius=8)
        pygame.draw.rect(surface, (180, 100, 110), self.btn_close, width=2, border_radius=8)
        c_txt = self.small_font.render("關閉 (ESC)", True, COLOR_WHITE)
        surface.blit(c_txt, (self.btn_close.centerx - c_txt.get_width() // 2, self.btn_close.centery - c_txt.get_height() // 2))
