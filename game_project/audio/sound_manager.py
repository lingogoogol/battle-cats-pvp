"""
Official Audio Manager for The Battle Cats.
Separates authentic BGM streaming (OGG Vorbis via pygame.mixer.music)
and authentic SFX playback (WAV via pygame.mixer.Sound) converted from official LPCM CAF files.
Zero synthetic beeps.
"""

import os
import pygame
from typing import Dict, Optional

class SoundManager:
    _instance: Optional['SoundManager'] = None

    def __init__(self, audio_dir: Optional[str] = None, enabled: bool = True):
        if audio_dir is None:
            audio_dir = r"E:\rea\game_project\assets\audio"
        self.audio_dir = audio_dir
        self.enabled = enabled
        self.initialized = False
        self.sfx_sounds: Dict[str, pygame.mixer.Sound] = {}
        self.current_bgm: Optional[str] = None
        self.sfx_volume = 0.8
        self.bgm_volume = 0.6

        if not self.enabled:
            return

        try:
            if not pygame.mixer.get_init():
                pygame.mixer.init(frequency=44100, size=-16, channels=2, buffer=512)
            self.initialized = True
            self._load_all_sfx()
        except Exception:
            self.initialized = False
            self.enabled = False

    @classmethod
    def get_instance(cls) -> 'SoundManager':
        if cls._instance is None:
            cls._instance = SoundManager()
        return cls._instance

    def _load_all_sfx(self):
        if not self.initialized or not os.path.isdir(self.audio_dir):
            return

        # Authentic PONOS SFX Mapping (converted from original LPCM CAF)
        sfx_files = {
            "click": "snd167.wav",
            "button_click": "snd167.wav",
            "btn_click": "snd167.wav",
            "cancel": "snd167.wav",
            "deploy": "snd168.wav",
            "hit": "snd169.wav",
            "critical": "snd170.wav",
            "crit": "snd170.wav",
            "castle_hit": "snd137.wav",
            "knockback": "snd139.wav",
            "wallet_up": "snd188.wav",
            "cannon_ready": "snd190.wav",
            "cannon_fire": "snd065.wav",
            "victory": "snd170.wav",
            "defeat": "snd062.ogg",
            "death": "snd139.wav",
            "boss_shockwave": "snd034.ogg",
            "boss_death": "snd189.wav",
            "thunderbolt": "snd194.wav",
            "shield_break": "snd188.wav",
            "barrier_break": "snd188.wav",
            "wave": "snd164.ogg",
            "surge": "snd186.ogg",
        }

        for key, fname in sfx_files.items():
            fpath = os.path.join(self.audio_dir, fname)
            if os.path.isfile(fpath):
                try:
                    snd = pygame.mixer.Sound(fpath)
                    snd.set_volume(self.sfx_volume)
                    self.sfx_sounds[key] = snd
                except Exception:
                    pass

    def play(self, key: str):
        """Plays a one-shot SFX sound."""
        if not self.enabled or not self.initialized:
            return
        snd = self.sfx_sounds.get(key)
        if snd:
            try:
                snd.play()
            except Exception:
                pass

    def play_sfx(self, key: str):
        self.play(key)

    def play_bgm(self, track_name: str, loop: bool = True):
        """
        Plays streaming BGM via pygame.mixer.music.
        Supported tracks: 'battle' (snd000.ogg), 'menu' (snd062.ogg), 'boss' (snd034.ogg).
        """
        if not self.enabled or not self.initialized:
            return

        bgm_map = {
            "menu": "snd000.ogg",
            "stage_select": "snd000.ogg",
            "battle": "snd034.ogg",
            "eoc_battle": "snd034.ogg",
            "boss": "snd062.ogg",
            "moon_boss": "snd062.ogg"
        }

        fn = bgm_map.get(track_name, track_name)
        if not fn.endswith(".ogg"):
            fn += ".ogg"
        fpath = os.path.join(self.audio_dir, fn)

        if os.path.isfile(fpath):
            try:
                if self.current_bgm == track_name and pygame.mixer.music.get_busy():
                    return
                pygame.mixer.music.load(fpath)
                pygame.mixer.music.set_volume(self.bgm_volume)
                pygame.mixer.music.play(-1 if loop else 0)
                self.current_bgm = track_name
            except Exception:
                pass

    def stop_bgm(self):
        if self.initialized:
            try:
                pygame.mixer.music.stop()
                self.current_bgm = None
            except Exception:
                pass

    def stop_all(self):
        if self.initialized:
            try:
                pygame.mixer.stop()
                pygame.mixer.music.stop()
                self.current_bgm = None
            except Exception:
                pass

    def set_sfx_volume(self, vol: float):
        self.sfx_volume = max(0.0, min(1.0, vol))
        for s in self.sfx_sounds.values():
            s.set_volume(self.sfx_volume)

    def set_bgm_volume(self, vol: float):
        self.bgm_volume = max(0.0, min(1.0, vol))
        if self.initialized:
            pygame.mixer.music.set_volume(self.bgm_volume)
