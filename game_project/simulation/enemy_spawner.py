"""
Official Battle Cats Stage Wave Spawner.
Implements authentic PONOS wave spawning logic parsed directly from stageXX.csv:
- max_enemies concurrent unit cap
- timed start frame
- min_interval / max_interval randomized respawn cooldowns
- infinite (count=0) vs limited (count>0) spawns
- castle HP percentage triggers (spawn when castle HP% <= threshold)
- boss wave shockwave flags
- magnification multipliers
"""

import random
from typing import List, Dict, Any, Optional, Tuple, Union
from ..core.official_data_parser import OfficialDataParser
from ..core.unit_data import ROW_TO_ENEMY_KEY

class EnemySpawnEntry:
    def __init__(self, spec: Dict[str, Any]):
        self.enemy_id: int = spec.get("enemy_id", 2)
        self.enemy_key: str = spec.get("enemy_key") or ROW_TO_ENEMY_KEY.get(self.enemy_id, "doge")
        self.total_count: int = spec.get("count", 0) # 0 means infinite
        self.start_frame: int = spec.get("start_frame", 0)
        self.min_interval: int = max(1, spec.get("min_interval", 60))
        self.max_interval: int = max(self.min_interval, spec.get("max_interval", 60))
        self.magnification: int = spec.get("magnification", spec.get("mag_pct", 100))
        self.castle_hp_pct: int = spec.get("castle_hp_pct", 100)
        self.boss_flag: int = spec.get("boss_flag", 0)

        # Runtime dynamic tracking
        self.spawned_count: int = 0
        self.respawn_timer: int = 0

    def can_spawn(self, current_frame: int, castle_hp_pct_cur: float) -> bool:
        # Check start frame
        if current_frame < self.start_frame:
            return False

        # Check total count limit
        if self.total_count > 0 and self.spawned_count >= self.total_count:
            return False

        # Check castle HP trigger threshold: spawns when current HP% <= trigger%
        if castle_hp_pct_cur > self.castle_hp_pct:
            return False

        # First spawn immediately upon conditions met
        if self.spawned_count == 0:
            return True

        # Subsequent spawns adhere to interval timer
        return self.respawn_timer <= 0

    def record_spawn(self):
        self.spawned_count += 1
        self.respawn_timer = random.randint(self.min_interval, self.max_interval)

    def tick(self):
        if self.respawn_timer > 0:
            self.respawn_timer -= 1


class StageWaveSpawner:
    def __init__(self, stage_config: Optional[Dict[str, Any]] = None):
        if stage_config is None:
            stage_config = self.get_default_stage()
        self.config = stage_config
        self.max_enemies: int = stage_config.get("max_enemy_count", stage_config.get("max_enemies", 3))
        self.spawn_entries: List[EnemySpawnEntry] = [
            EnemySpawnEntry(s) for s in stage_config.get("spawns", [])
        ]

    @staticmethod
    def get_default_stage() -> Dict[str, Any]:
        """Official Chapter 1 Stage 1: 韓國 (Korea) loaded via OfficialDataParser"""
        parser = OfficialDataParser.get_instance()
        stage_1 = parser.get_stage(1)
        if stage_1:
            return stage_1.to_dict()
        return {
            "id": 1,
            "name": "韓國",
            "length": 3000,
            "cat_castle_hp": 1000,
            "enemy_castle_hp": 500,
            "max_enemy_count": 3,
            "spawns": [
                {"enemy_id": 2, "enemy_key": "doge", "count": 1, "start_frame": 0, "min_interval": 60, "max_interval": 80, "castle_hp_pct": 100, "boss_flag": 0, "magnification": 100},
                {"enemy_id": 2, "enemy_key": "doge", "count": 0, "start_frame": 300, "min_interval": 90, "max_interval": 150, "castle_hp_pct": 100, "boss_flag": 0, "magnification": 100},
                {"enemy_id": 23, "enemy_key": "ms_sign", "count": 0, "start_frame": 13500, "min_interval": 13500, "max_interval": 13500, "castle_hp_pct": 100, "boss_flag": 0, "magnification": 100}
            ]
        }

    def update(self, current_frame: int, enemy_castle_hp: int, enemy_castle_max_hp: int, current_active_enemies: int = 0) -> List[Dict[str, Any]]:
        """
        Evaluates simulation frame, castle status, and field unit cap.
        Returns a list of spawn descriptors: [{"key": str, "id": int, "mag": int, "boss": int}]
        """
        to_spawn = []
        cur_hp_pct = (enemy_castle_hp / max(1, enemy_castle_max_hp)) * 100.0

        for entry in self.spawn_entries:
            entry.tick()
            if current_active_enemies + len(to_spawn) >= self.max_enemies:
                continue

            if entry.can_spawn(current_frame, cur_hp_pct):
                to_spawn.append({
                    "key": entry.enemy_key,
                    "id": entry.enemy_id,
                    "mag": entry.magnification,
                    "boss": entry.boss_flag
                })
                entry.record_spawn()

        return to_spawn
