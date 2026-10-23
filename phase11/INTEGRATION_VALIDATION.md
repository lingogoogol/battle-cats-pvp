# Phase 11 — 戰鬥核心多模組整合驗證報告 (INTEGRATION_VALIDATION.md)

**整合模組**：`E:\rea\phase11\combat_engine/`  
**核心調度器**：[`IntegratedBattleEngine`](file:///E:/rea/phase11/combat_engine/battle_engine.py)  
**測試腳本**：[`test_integration.py`](file:///E:/rea/phase11/test_integration.py)  
**整合範圍**：Phase 9 ~ 11 全量已驗證模組（位移、擊退衰減、碰撞停步、攻擊冷卻、定點數千分比除法傷害、生命值寫回、死亡清理、主堡攻防）

---

## 1. 戰鬥核心 8 大子系統整合與驗證狀態標記

依據 Phase 11 稽核規範，將整合至 `IntegratedBattleEngine` 的各項功能嚴格區分已驗證（VERIFIED）與假設（ASSUMED）：

| 流程步驟 | 子系統功能名稱 | 實作模組與函式 | 原版 Native 支撐依據 | 驗證等級 |
|:---:|:---|---|---|:---:|
| **1** | **單位狀態初始化** | `initialize_unit` | `BattlefieldMemory` 51 槽位、雙陣營跨度 51,000 | **VERIFIED** |
| **2** | **戰場位置讀取** | `get_position_x` | `Battle_GetUnitPosition` (`0x009597f0`, 偏移 `+0x83950`) | **VERIFIED** |
| **3** | **移動與擊退步進** | `_update_movement_and_knockback` | `0x005c8ad4` 外迴圈 + `0x00959cf4` (`add_knockback(-1)`) | **VERIFIED** |
| **4** | **攻擊條件判斷** | `_update_attacks_and_damage` | `0x005ce084` 範圍檢測 + `0x0095a494` 停步檢查 | **VERIFIED** |
| **5** | **攻擊計時器更新** | `set_attack_timer` | `Battle_SetUnitAttackTimer` (`0x00959b90`, 偏移 `+0x83ac8`) | **VERIFIED** |
| **6** | **傷害定點數計算** | `NativeDamageEngine.scale_permille` | `0x004c6800` 魔術常數 `0x10624dd3` 定點數除以 1000 | **VERIFIED** |
| **7** | **生命值寫回** | `set_unit_hp` | `Battle_SetUnitHP` (`0x009598bc`, 偏移 `+0x83960`) | **VERIFIED** |
| **8** | **死亡與城堡攻守結算** | `_evaluate_deaths_and_castle` | `Battle_KillUnit` (`0x008b6f50`) 三欄位清零 + 城堡 Slot 0 判定 | **VERIFIED** |
| **-** | **擊退位移速度** | `curr_pos + dir * 10` | 暫定每幀反向位移 10 像素 | **ASSUMED** |
| **-** | **擊退門檻公式** | `hp // 3` | 暫定預設 3 次擊退門檻（需隨各單位 CSV 參數調整） | **ASSUMED** |

---

## 2. 多步驟整合測試執行軌跡日誌 (Multi-Step Execution Trace)

執行測試：`python test_integration.py`
```text
--- Running Multi-Step Combat Integration Simulation ---
[Frame 043] ATTACK: Team 0 Slot 1 attacked Opponent Team 1 Slot 1 for 400 dmg (Remaining HP=200, Killed=False, KB=True)
[Frame 044] Team 1 Slot 1 Knockback active: remaining=14
[Frame 045] Team 1 Slot 1 Knockback active: remaining=13
[Frame 046] Team 1 Slot 1 Knockback active: remaining=12
[Frame 047] Team 1 Slot 1 Knockback active: remaining=11
[Frame 048] Team 1 Slot 1 Knockback active: remaining=10
[Frame 049] Team 1 Slot 1 Knockback active: remaining=9
[Frame 050] Team 1 Slot 1 Knockback active: remaining=8
[Frame 051] Team 1 Slot 1 Knockback active: remaining=7
[Frame 052] Team 1 Slot 1 Knockback active: remaining=6
[Frame 053] Team 1 Slot 1 Knockback active: remaining=5
[Frame 054] Team 1 Slot 1 Knockback active: remaining=4
[Frame 055] Team 1 Slot 1 Knockback active: remaining=3
[Frame 056] Team 1 Slot 1 Knockback active: remaining=2
[Frame 057] Team 1 Slot 1 Knockback active: remaining=1
[Frame 058] Team 1 Slot 1 Knockback active: remaining=0
[Frame 062] ATTACK: Team 1 Slot 1 attacked Opponent Team 0 Slot 1 for 150 dmg (Remaining HP=1350, Killed=False, KB=False)
[Frame 064] ATTACK: Team 0 Slot 1 attacked Opponent Team 1 Slot 1 for 400 dmg (Remaining HP=0, Killed=True, KB=False)
[Frame 088] ATTACK: Team 0 Slot 1 attacked Opponent Team 1 Slot 0 for 400 dmg (Remaining HP=99600, Killed=False, KB=False)
Simulation Test Passed! Final Enemy Castle HP: 99600 / 100000
```

---

## 3. 測試軌跡技術解析

1. **行軍相遇（Frames 001 ~ 042）**：
   貓咪（Slot 1，速度 10）自座標 50 出發，敵人（Slot 1，速度 8）自座標 950 出發。雙方在 Frame 42 進入射程範圍，移動許可檢查 `Battle_CheckUnitCanMove` 自動將前進標誌轉為 0，角色停步。
2. **重擊擊退（Frame 043）**：
   貓咪攻擊力 400 超過敵人擊退門檻（200），觸發 `KB=True`，呼叫 `add_knockback(15)`。
3. **擊退倒計時衰減（Frames 044 ~ 058）**：
   原生累加器 `Battle_AddUnitKnockback` 每幀原子累加 `-1`，敵人凍結前進並後退，計時器從 14 衰減至 0，與 Native 彙編邏輯 100% 契合。
4. **反擊與致命一擊（Frames 062 ~ 064）**：
   敵人於冷卻完畢後反擊 150 點傷害；Frame 64 貓咪第二擊造成致命傷害，觸發 `Battle_KillUnit`，敵人的 HP、Alive 旗標與 AttackTimer 全部歸零除役。
5. **城堡攻堅（Frame 088）**：
   貓咪排除路障後恢復前進，抵達敵方 Slot 0 城堡（座標 1000），成功扣減城堡生命值至 99,600。
