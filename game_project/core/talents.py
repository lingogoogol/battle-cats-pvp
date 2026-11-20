"""
Official PONOS Battle Cats Talent & Ultra Talent Engine (`SkillAcquisition.csv`).
Parses authentic talent definitions for all 187 talent-enabled cats (up to 8 slots A..H,
including Ultra Talents `limit == 1`), provides Traditional Chinese labels & effect descriptions,
and applies enabled talents deterministically to a unit spec.
"""

import csv
import os
from typing import Dict, List, Any, Optional

DEFAULT_SKILL_ACQ_PATH = r"E:\rea\game_project\data\official_extracted_data\SkillAcquisition.csv"

# Official PONOS SkillAcquisition.csv abilityID -> Traditional Chinese name
TALENT_NAMES_TW: Dict[int, str] = {
    1: "攻擊力下降",
    2: "使動作停止",
    3: "使動作變慢",
    5: "善於攻擊",
    6: "很耐打",
    7: "超大傷害",
    8: "打飛敵人",
    10: "攻擊力上升",
    11: "死前存活",
    13: "會心一擊",
    14: "終結不死",
    15: "破壞護盾",
    16: "獲得金錢2倍",
    17: "波動攻擊",
    18: "攻擊力下降耐性",
    19: "動作停止耐性",
    20: "動作變慢耐性",
    21: "打飛耐性",
    22: "波動傷害耐性",
    25: "生產費用減少",
    26: "再生產時間縮短",
    27: "移動速度上升",
    29: "詛咒無效",
    30: "詛咒耐性",
    31: "基本攻擊力上升",
    32: "基本體力上升",
    33: "對象屬性：紅色敵人",
    34: "對象屬性：漂浮敵人",
    35: "對象屬性：黑色敵人",
    36: "對象屬性：鋼鐵敵人",
    37: "對象屬性：天使敵人",
    38: "對象屬性：異星戰士",
    39: "對象屬性：不死生物",
    40: "對象屬性：古代種",
    41: "對象屬性：無屬性",
    44: "攻擊力下降無效",
    45: "動作停止無效",
    46: "動作變慢無效",
    47: "打飛無效",
    48: "波動傷害無效",
    49: "傳送無效",
    50: "渾身一擊",
    51: "攻擊無效",
    52: "毒擊耐性",
    53: "毒擊無效",
    54: "烈波耐性",
    55: "烈波傷害無效",
    56: "烈波攻擊",
    57: "對象屬性：惡魔",
    58: "破壞惡魔盾",
    59: "靈魂攻擊",
    60: "古代詛咒",
    61: "攻擊間隔縮短",
    62: "小波動",
    63: "超生命體特效",
    64: "超獸特效",
    65: "小烈波",
    66: "超賢者特效",
    67: "爆波攻擊",
    68: "爆波無效",
    69: "鋼鐵殺手",
}

TRAIT_TALENT_MAP: Dict[int, str] = {
    33: "red",
    34: "floating",
    35: "black",
    36: "metal",
    37: "angel",
    38: "alien",
    39: "zombie",
    40: "relic",
    41: "traitless",
    57: "aku",
}


def _format_talent_summary(aid: int, max_vals: List[int]) -> str:
    m1, m2, m3, m4 = max_vals[0], max_vals[1], max_vals[2], max_vals[3]
    if aid == 1:
        return f"+{m1}% 機率 / +{m2}F" if m1 else f"+{m2}F 降攻時間"
    if aid in (2, 3, 60):
        return f"+{m1}% / {m2}F" if m1 else f"+{m2}F 持續時間"
    if aid in (8, 11, 13, 15, 58):
        return f"+{m1}%"
    if aid == 10:
        return f"血量≤{100 - m1 if 0 < m1 < 100 else m1}% 攻+{m2}%"
    if aid == 17:
        return f"{m1}% Lv.{max(1, m2)} 波動"
    if aid in (18, 19, 20, 21, 22, 30, 52, 54):
        return f"減輕 {m1}%"
    if aid == 25:
        return f"費用 -{m1}元"
    if aid == 26:
        return f"冷卻 -{(m1 * 2) / 30.0:.2f}秒"
    if aid == 27:
        return f"跑速 +{m1}"
    if aid == 31:
        return f"攻擊力 +{m1}%"
    if aid == 32:
        return f"體力 +{m1}%"
    if aid == 50:
        return f"{m1}% 機率 (+{m2}% 傷)"
    if aid == 51:
        return f"{m1}% 機率 ({m2}F)"
    if aid in (56, 65):
        kind = "小烈波" if aid == 65 else "烈波"
        return f"{m1}% Lv.{max(1, m2)} {kind}"
    if aid == 61:
        return f"攻頻 -{m1}F"
    if aid == 62:
        return f"{m1}% Lv.{max(1, m2)} 小波動"
    if aid == 64:
        return f"超獸特效 ({m1}% 迴避 {m2}F)" if m1 else "超獸特效"
    if aid == 67:
        return f"{m1}% 爆波 (@{m2 // 4}射程)"
    return "開啟"


class TalentCatalog:
    """Singleton catalog of official PONOS Talents parsed from SkillAcquisition.csv."""

    _instance: Optional["TalentCatalog"] = None

    def __init__(self, csv_path: str = DEFAULT_SKILL_ACQ_PATH):
        self.by_uid: Dict[int, List[Dict[str, Any]]] = {}
        self._load(csv_path)

    @classmethod
    def get_instance(cls) -> "TalentCatalog":
        if cls._instance is None:
            cls._instance = TalentCatalog()
        return cls._instance

    def _load(self, csv_path: str):
        if not os.path.isfile(csv_path):
            return
        with open(csv_path, "r", encoding="utf-8", errors="ignore") as f:
            reader = csv.reader(f)
            next(reader, None)  # skip header
            for row in reader:
                if len(row) < 16 or not row[0].strip().isdigit():
                    continue
                uid = int(row[0].strip())
                talents: List[Dict[str, Any]] = []
                for slot in range(8):
                    base = 2 + slot * 14
                    if base + 13 >= len(row):
                        break
                    aid = int(row[base].strip() or 0)
                    if aid <= 0:
                        continue
                    max_lv = max(1, int(row[base + 1].strip() or 1))
                    # max values at max talent level: max_1..max_4 are at base+3, base+5, base+7, base+9
                    m1 = int(row[base + 3].strip() or 0)
                    m2 = int(row[base + 5].strip() or 0)
                    m3 = int(row[base + 7].strip() or 0)
                    m4 = int(row[base + 9].strip() or 0)
                    is_ultra = int(row[base + 13].strip() or 0) == 1
                    name = TALENT_NAMES_TW.get(aid, f"本能 #{aid}")
                    summary = _format_talent_summary(aid, [m1, m2, m3, m4])
                    talents.append({
                        "idx": len(talents),
                        "ability_id": aid,
                        "name": name,
                        "summary": summary,
                        "max_lv": max_lv,
                        "max_vals": [m1, m2, m3, m4],
                        "is_ultra": is_ultra,
                        "default_enabled": True,
                    })
                if talents:
                    self.by_uid[uid] = talents

    def get_talents(self, uid: int) -> List[Dict[str, Any]]:
        return [dict(t) for t in self.by_uid.get(uid, [])]


def apply_talents_to_spec(
    spec: Dict[str, Any],
    disabled_indices: Optional[set] = None,
) -> Dict[str, Any]:
    """
    Applies all enabled official PONOS Talents (at max talent level) to an already level-scaled unit spec.
    `disabled_indices` is an optional set of talent `idx` integers turned OFF by the player.
    """
    talents = spec.get("talents")
    if not talents:
        return spec

    disabled = disabled_indices or set()
    out = dict(spec)
    ab = dict(spec.get("abilities") or {})
    target_traits = list(spec.get("target_traits") or [])
    hits = [dict(h) for h in (spec.get("attack_hits") or [])]

    hp_bonus_pct = 0
    atk_bonus_pct = 0

    for t in talents:
        if t.get("idx") in disabled:
            continue
        aid = int(t.get("ability_id", 0))
        mv = t.get("max_vals", [0, 0, 0, 0])
        m1 = mv[0] if len(mv) > 0 else 0
        m2 = mv[1] if len(mv) > 1 else 0
        m3 = mv[2] if len(mv) > 2 else 0
        m4 = mv[3] if len(mv) > 3 else 0

        if aid == 32:  # HP Up %
            hp_bonus_pct += m1
        elif aid == 31:  # ATK Up %
            atk_bonus_pct += m1
        elif aid == 25:  # Cost Down
            out["cost"] = max(10, int(out.get("cost", 50)) - m1)
        elif aid == 26:  # Cooldown Down (pair frames -> *2 frames, min 60f)
            out["cooldown_frames"] = max(60, int(out.get("cooldown_frames", 60)) - m1 * 2)
        elif aid == 27:  # Move Speed Up
            out["speed"] = max(1, int(out.get("speed", 10)) + m1)
        elif aid == 61:  # TBA Down
            out["attack_interval"] = max(0, int(out.get("attack_interval", 0)) - m1)
        elif aid in TRAIT_TALENT_MAP:
            tr = TRAIT_TALENT_MAP[aid]
            if tr not in target_traits:
                target_traits.append(tr)
        elif aid == 1:  # Weaken
            ab["weaken_prob"] = min(100, int(ab.get("weaken_prob", 0)) + m1)
            ab["weaken_dur"] = int(ab.get("weaken_dur", 0)) + m2
            if m3 > 0 and not ab.get("weaken_pct"):
                ab["weaken_pct"] = m3
        elif aid == 2:  # Freeze
            ab["freeze_prob"] = min(100, int(ab.get("freeze_prob", 0)) + m1)
            ab["freeze_dur"] = int(ab.get("freeze_dur", 0)) + m2
        elif aid == 3:  # Slow
            ab["slow_prob"] = min(100, int(ab.get("slow_prob", 0)) + m1)
            ab["slow_dur"] = int(ab.get("slow_dur", 0)) + m2
        elif aid == 5:
            ab["strong"] = True
        elif aid == 6:
            ab["resistant"] = True
        elif aid == 7:
            ab["massive_damage"] = True
        elif aid == 8:  # KB
            ab["kb_prob"] = min(100, int(ab.get("kb_prob", 0)) + m1)
        elif aid == 10:  # Strengthen
            if m1 > 0 and not ab.get("strengthen_hp_pct"):
                ab["strengthen_hp_pct"] = 100 - m1 if m1 < 100 else m1
            ab["strengthen_boost_pct"] = int(ab.get("strengthen_boost_pct", 0)) + m2
        elif aid == 11:  # Survive
            ab["survive_prob"] = min(100, int(ab.get("survive_prob", 0)) + m1)
        elif aid == 13:  # Crit
            ab["crit_prob"] = min(100, int(ab.get("crit_prob", 0)) + m1)
        elif aid == 14:
            ab["zombie_killer"] = True
        elif aid == 15:  # Barrier Breaker
            ab["barrier_break_prob"] = min(100, int(ab.get("barrier_break_prob", 0)) + m1)
        elif aid == 16:
            ab["extra_money"] = True
        elif aid == 17:  # Wave
            ab["wave_prob"] = min(100, int(ab.get("wave_prob", 0)) + m1)
            ab["wave_lvl"] = max(int(ab.get("wave_lvl", 0)), max(1, m2))
        elif aid == 29:
            ab["curse_immune"] = True
        elif aid == 44:
            ab["weaken_immune"] = True
        elif aid == 45:
            ab["freeze_immune"] = True
        elif aid == 46:
            ab["slow_immune"] = True
        elif aid == 47:
            ab["kb_immune"] = True
        elif aid == 48:
            ab["wave_immune"] = True
        elif aid == 49:
            ab["warp_immune"] = True
            ab["warp_blocker"] = True
        elif aid == 50:  # Savage Blow
            ab["savage_blow_prob"] = min(100, int(ab.get("savage_blow_prob", 0)) + m1)
            ab["savage_blow_boost"] = max(int(ab.get("savage_blow_boost", 0)), m2 or 200)
        elif aid == 51:  # Dodge
            ab["dodge_prob"] = min(100, int(ab.get("dodge_prob", 0)) + m1)
            ab["dodge_dur"] = max(int(ab.get("dodge_dur", 0)), m2 or 30)
        elif aid == 53:
            ab["toxic_immune"] = True
        elif aid == 55:
            ab["surge_immune"] = True
        elif aid in (56, 65):  # Surge / Mini-Surge
            ab["surge_prob"] = min(100, int(ab.get("surge_prob", 0)) + m1)
            ab["surge_lvl"] = max(int(ab.get("surge_lvl", 0)), max(1, m2))
            if m3 > 0:
                ab["surge_start"] = m3 // 4
            if m4 > 0:
                ab["surge_range"] = m4 // 4
            if aid == 65:
                ab["mini_surge"] = True
        elif aid == 58:  # Shield Pierce
            ab["shield_pierce_prob"] = min(100, int(ab.get("shield_pierce_prob", 0)) + m1)
        elif aid == 59:
            ab["soul_strike"] = True
        elif aid == 60:  # Curse
            ab["curse_prob"] = min(100, int(ab.get("curse_prob", 0)) + m1)
            ab["curse_dur"] = int(ab.get("curse_dur", 0)) + m2
        elif aid == 62:  # Mini-Wave
            ab["wave_prob"] = min(100, int(ab.get("wave_prob", 0)) + m1)
            ab["wave_lvl"] = max(int(ab.get("wave_lvl", 0)), max(1, m2))
            ab["mini_wave"] = True
        elif aid == 63:
            ab["colossus_slayer"] = True
        elif aid == 64:
            ab["behemoth_slayer"] = True
            if m1 > 0:
                ab["behemoth_dodge_prob"] = max(int(ab.get("behemoth_dodge_prob", 0)), m1)
                ab["behemoth_dodge_dur"] = max(int(ab.get("behemoth_dodge_dur", 0)), m2 or 30)
        elif aid == 66:
            ab["sage_slayer"] = True
        elif aid == 67:  # Explosion (e.g. Awakened Bahamut!)
            ab["explosion_prob"] = min(100, int(ab.get("explosion_prob", 0)) + m1)
            if m2 > 0:
                ab["explosion_start"] = m2 // 4
            ab["explosion_width"] = max(int(ab.get("explosion_width", 0)), m3 // 4)
        elif aid == 68:
            ab["explosion_immune"] = True
        elif aid == 69:
            ab["metal_killer_pct"] = max(int(ab.get("metal_killer_pct", 0)), m1 or 5)

    if hp_bonus_pct > 0:
        out["hp"] = max(1, (int(out.get("hp", 100)) * (100 + hp_bonus_pct)) // 100)
    if atk_bonus_pct > 0:
        if hits:
            for h in hits:
                h["damage"] = max(1, (int(h.get("damage", 1)) * (100 + atk_bonus_pct)) // 100)
            out["attack_hits"] = hits
            out["attack_power"] = sum(h["damage"] for h in hits)
        else:
            out["attack_power"] = max(1, (int(out.get("attack_power", 1)) * (100 + atk_bonus_pct)) // 100)
    elif hits:
        out["attack_hits"] = hits

    out["abilities"] = ab
    out["target_traits"] = target_traits
    return out
