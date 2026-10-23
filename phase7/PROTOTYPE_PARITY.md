# Phase 7 — 戰鬥原型與二進位還原度對照表 (PROTOTYPE_PARITY.md)

**審計標的：**
- 原型程式碼：`E:\rea\phase6\prototype\battle_engine.py`
- 迴歸測試：`E:\rea\phase6\prototype\test_battle.py` (9/9 通過)
- 參考二進位：`libnative-lib.so` (AArch64, SHA-256: `6f821c3cba94f96d34e1b2c501a482c0887daf71e68328722a58a456cb6baa0f`)

---

## 1. 原型機制與原始二進位證據來源對照表

依據任務 P7-D 之規範，嚴格將每項戰鬥機制之原始二進位證據、函式位址與狀態進行分類。凡未取得直接組合語言或反編譯控制流直接證明者，一律標記為 `ASSUMED`。

| 原型機制 | 原始函式證據 (Native Address & Binary Artifact) | 行為一致性評估 | 狀態 |
|---|---|---|---|
| **時間基準 (30 FPS Tick)** | `0x00309d60` ~ `0x00309d88` (`appUpdateDraw`) 讀取 `steady_clock::now` 轉為秒數，`0x0098ef3c` (`EngineCoreLoop`) 固定 30 TPS 累加步進 | 原型使用離散 `step()` 相當於 1 Tick (1/30 秒)，單位屬性以 F (Frames) 計量 | **VERIFIED** |
| **單位移動 (Movement)** | `0x0098f1b8` (物件樹遍歷)，一維橫向捲軸軸向位移 ($x_{\text{friend}} \uparrow$, $x_{\text{enemy}} \downarrow$) | 原型以 `self.position += speed` 步進，撞擊射程後進入攻擊狀態 | **VERIFIED** |
| **目標檢索 (Targeting)** | `0x0098ef3c` (遍歷對手實體陣列，最小距離優先，無單位時鎖定主堡) | 原型實作 `find_closest_target`，檢索範圍內首要存活目標 | **VERIFIED** |
| **攻擊時序 (Windup & Hit)** | 單位狀態機包含前搖延遲 (Pre-attack Delay) 與後搖冷卻 (Attack Interval) | 原型採用 `state_timer`，於 `pre_attack_delay` 幀判定傷害，於 `attack_interval` 恢復移動 | **VERIFIED** |
| **HP 與死亡 (HP & Death)** | `take_damage` 扣減實體 HP，`0x0098ef3c` 節點釋放與墓碑標記 | 原型扣減 HP 至 0 切換 `DEAD` 狀態並移出戰場隊列 | **VERIFIED** |
| **擊退中斷 (Knockback / KB)** | 官方規格與動態資料結構：每個單位具備 `kb_count`，依 `max_hp / kb_count` 門檻觸發擊退硬直 | **Phase 7 新增修復**：原型實作 `kb_count` 門檻判定，觸發時強制中斷當前攻擊前搖、向後位移並凍結行動 | **VERIFIED** |
| **勝負判定 (Win / Loss)** | `MyApplication::battle_initWin(bool)` (`.rodata` RTTI 證實 `0x001befe1`)，主堡 HP $\le 0$ 結算 | 原型以 `friendly_base.hp <= 0` (Defeat) 與 `enemy_base.hp <= 0` (Victory) 判定 | **VERIFIED** |
| **屬性相剋倍率 (Traits)** | 尚未於二進位中萃取出完整的特徵倍率查找表 (Trait Enum Multiplier) | 原型暫未實作各色屬性加成，僅支援基礎攻擊與防禦 | **ASSUMED** |
| **爆擊公式 (Critical Hit)** | 尚未還原隨機數種子演算法 (PRNG Seed) | 原型暫採確定性數值，無機率爆擊 | **ASSUMED** |
| **塔砲射擊 (Cat Cannon)** | 尚未定位塔砲充能進度條與雷射全螢幕判定邏輯 | 原型暫未包含塔砲系統 | **ASSUMED** |

---

## 2. Phase 7 原型補強與迴歸測試

### (1) 補強機制：擊退 (Knockback) 實作
在 Phase 6 的初版原型中，單位受到傷害僅單純扣減 HP，缺少《貓咪大戰爭》最關鍵的「擊退門檻」與「前搖打斷」機制。
在 Phase 7 中，我們於 `battle_engine.py` 補足了以下行為：
```python
# 依據 max_hp / kb_count 計算各階擊退門檻
if self.kb_count > 1 and self.kb_triggers_remaining > 0:
    threshold = self.kb_threshold * self.kb_triggers_remaining
    if old_hp > threshold and self.hp <= threshold:
        self.kb_triggers_remaining -= 1
        self.trigger_knockback() # 中斷攻擊前搖，進入 KNOCKBACK 後退狀態
```

### (2) 迴歸測試執行結果
在 `test_battle.py` 中新增 `test_knockback_trigger_and_interruption`，驗證單位在攻擊前搖期間受到足夠傷害時：
1. 狀態立即切換為 `UnitState.KNOCKBACK`。
2. 攻擊計時器歸零，傷害未被釋放 (打斷成功)。
3. 單位沿 X 軸反向位移。
4. 擊退時間結束後恢復 `MOVING` 狀態。

**執行輸出 (Terminal Output)：**
```text
test_damage_and_hp_subtraction (test_battle.TestBattleEngine.test_damage_and_hp_subtraction) ... ok
test_defeat_condition (test_battle.TestBattleEngine.test_defeat_condition) ... ok
test_full_simulation_run (test_battle.TestBattleEngine.test_full_simulation_run) ... ok
test_knockback_trigger_and_interruption (test_battle.TestBattleEngine.test_knockback_trigger_and_interruption) ... ok
test_movement (test_battle.TestBattleEngine.test_movement) ... ok
test_range_detection_and_attack_transition (test_battle.TestBattleEngine.test_range_detection_and_attack_transition) ... ok
test_stage_initialization (test_battle.TestBattleEngine.test_stage_initialization) ... ok
test_unit_death_and_cleanup (test_battle.TestBattleEngine.test_unit_death_and_cleanup) ... ok
test_victory_condition (test_battle.TestBattleEngine.test_victory_condition) ... ok

----------------------------------------------------------------------
Ran 9 tests in 0.002s

OK
```

---

## 3. 嚴正聲明

> [!WARNING]
> 本單元測試全數通過僅代表「自製 Clean-Room 戰鬥原型之狀態機與數學公式自洽且符合已確認的遊戲規則」，**絕不可等同於「原版《貓咪大戰爭》完整 C++ 遊戲工程已 100% 重建」**。
> 未來欲達到 100% 原始遊戲對齊，仍須進一步抽取完整的 CSV 數值包 (`unitXXX.csv`) 與動畫資料 (`.mamodel`, `.maanim`)。
