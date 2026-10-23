"""
Asset Manager Module.
Loads and caches authentic extracted PNG graphics from v15.6.1 APK and Packs.
Maintains strict provenance tracking, lazy loading for large catalogs, and logs fallback events.
"""

import os
import datetime
import pygame
from typing import Dict, Optional, Tuple, List

AUDIT_LOG_PATH = r"E:\rea\visual_audit\ASSET_FALLBACK_AUDIT.log"

class AssetManager:
    _instance: Optional['AssetManager'] = None

    def __init__(self, dirs: Optional[List[str]] = None):
        if dirs is None:
            self.dirs = [
                r"E:\rea\game_project\assets\official_extracted",
                r"E:\rea\game_project\assets\official_ui",
                r"E:\rea\game_assets\extracted_png"
            ]
            self.lazy_dirs = [
                r"E:\rea\visual_audit\extracted_pngs"
            ]
        else:
            self.dirs = dirs
            self.lazy_dirs = []

        self.textures: Dict[str, pygame.Surface] = {}
        self.asset_status: Dict[str, str] = {}
        self.asset_sources: Dict[str, str] = {}
        self.file_index: Dict[str, str] = {}

        self._index_lazy_dirs()
        self._load_extracted_assets()

    @classmethod
    def get_instance(cls) -> 'AssetManager':
        if cls._instance is None:
            cls._instance = AssetManager()
        return cls._instance

    def _index_lazy_dirs(self):
        for directory in self.lazy_dirs:
            if not os.path.isdir(directory):
                continue
            for fname in os.listdir(directory):
                if fname.lower().endswith(('.png', '.jpg')):
                    fpath = os.path.join(directory, fname)
                    base_name = os.path.splitext(fname)[0].lower()
                    self.file_index[base_name] = fpath
                    if ".pack_" in base_name:
                        pure_name = base_name.split(".pack_")[-1]
                        if pure_name not in self.file_index:
                            self.file_index[pure_name] = fpath
                    elif "installpack_" in base_name:
                        pure_name = base_name.replace("installpack_", "")
                        if pure_name not in self.file_index:
                            self.file_index[pure_name] = fpath

    def _load_extracted_assets(self):
        for directory in self.dirs:
            if not os.path.isdir(directory):
                continue

            for fname in os.listdir(directory):
                if fname.lower().endswith(('.png', '.jpg')):
                    fpath = os.path.join(directory, fname)
                    try:
                        surf = pygame.image.load(fpath)
                        base_name = os.path.splitext(fname)[0].lower()
                        self.textures[base_name] = surf
                        self.asset_status[base_name] = "AUTHENTIC_DECODED"
                        self.asset_sources[base_name] = fpath

                        if ".pack_" in base_name:
                            pure_name = base_name.split(".pack_")[-1]
                            if pure_name not in self.textures:
                                self.textures[pure_name] = surf
                                self.asset_status[pure_name] = "AUTHENTIC_DECODED"
                                self.asset_sources[pure_name] = fpath
                        elif "installpack_" in base_name:
                            pure_name = base_name.replace("installpack_", "")
                            if pure_name not in self.textures:
                                self.textures[pure_name] = surf
                                self.asset_status[pure_name] = "AUTHENTIC_DECODED"
                                self.asset_sources[pure_name] = fpath

                    except Exception:
                        pass

    def get_texture(self, name: str, size: Optional[Tuple[int, int]] = None) -> Optional[pygame.Surface]:
        key = name.lower()
        if key.endswith(('.png', '.jpg')):
            key = os.path.splitext(key)[0]

        surf = self.textures.get(key)
        if surf is None:
            # Check lazy index
            fpath = self.file_index.get(key)
            if fpath and os.path.isfile(fpath):
                try:
                    surf = pygame.image.load(fpath)
                    self.textures[key] = surf
                    self.asset_status[key] = "AUTHENTIC_DECODED"
                    self.asset_sources[key] = fpath
                except Exception:
                    surf = None

        if surf is None:
            self.log_fallback_event(
                component="AssetManager",
                asset_name=name,
                status="MISSING_LOCALLY",
                reason="Asset not present in offline local packs or extracted directory",
                action="STRICT_FALLBACK_TRIGGERED"
            )
            return None

        if size is not None and (surf.get_width() != size[0] or surf.get_height() != size[1]):
            return pygame.transform.smoothscale(surf, size)
        return surf

    def get_status(self, name: str) -> str:
        key = name.lower()
        if key.endswith(('.png', '.jpg')):
            key = os.path.splitext(key)[0]
        if key in self.textures or key in self.file_index:
            return "AUTHENTIC_DECODED"
        return "CDN_OFFLINE_ABSENT"

    def has_texture(self, name: str) -> bool:
        key = name.lower()
        if key.endswith(('.png', '.jpg')):
            key = os.path.splitext(key)[0]
        return (key in self.textures) or (key in self.file_index)

    def log_fallback_event(self, component: str, asset_name: str, status: str, reason: str, action: str):
        os.makedirs(os.path.dirname(AUDIT_LOG_PATH), exist_ok=True)
        ts = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_line = f"[{ts}] [{component}] ASSET='{asset_name}' STATUS='{status}' REASON='{reason}' ACTION='{action}'\n"
        try:
            with open(AUDIT_LOG_PATH, "a", encoding="utf-8") as f:
                f.write(log_line)
        except Exception:
            pass
