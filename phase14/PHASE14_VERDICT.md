# Phase 14 — 深度完善原版戰鬥引擎結案報告 (PHASE14_VERDICT.md)

**專案根目錄**：`E:\rea`  
**評定日期**：2026-10-15  
**最終判定結果**：**PHASE 14 COMPLETED & VERIFIED**  
**核心進展**：原版十二項戰鬥機制形式化逆向、7 個原生二進位函式 Unicorn 差異測試 100% 通過、資料驅動單體/範圍攻擊與狀態機全面整合。

---

## 一、Phase 14 任務完成矩陣

| 子任務項目 | 規範要求 | 交付產物與實證代碼 | 驗收結果 |
|---|---|---|:---:|
| **14.1 Native 戰鬥機制還原** | 依序研究 12 項戰鬥規則，記錄原始位址、分支與證據等級 | [COMBAT_MECHANICS_AUDIT.md](file:///E:/rea/phase14/COMBAT_MECHANICS_AUDIT.md) | **PASS** |
| **14.2 建立更完整的單位系統** | 資料驅動模型、範圍攻擊與單體攻擊區分、狀態機與效果 | [unit_data.py](file:///E:/rea/game_project/core/unit_data.py)<br>[battle_sim.py](file:///E:/rea/game_project/simulation/battle_sim.py) | **PASS** |
| **14.3 原生差異測試** | Unicorn AArch64 真實二進位執行，涵蓋目標選擇、冷卻、HP、活躍、城堡 HP | [native_differential_suite.py](file:///E:/rea/phase14/native_differential_suite.py)<br>[phase14_differential_log.txt](file:///E:/rea/phase14/evidence_bundle/phase14_differential_log.txt) | **PASS** |
| **14.4 戰鬥引擎整合與驗收** | 範圍攻擊/單體攻擊/擊退中斷前搖/狀態效果測試 | [test_phase14_mechanics.py](file:///E:/rea/phase14/test_phase14_mechanics.py)<br>[test_playable.py](file:///E:/rea/game_project/test_playable.py) | **PASS** |

---

## 二、原生差異測試 (Native Differential Testing) 實證記錄

於 Unicorn Engine 2.1.4 (AArch64) 執行來自 `libnative-lib.so` 之真實機器碼，完全無人工 Stub：

1. **`Battle_GetTargetType` (`0x00957c8c`, 52 bytes)**:
   - 驗證讀取 `+0x8394c`，正確區分單體攻擊（`0`）與範圍攻擊（`1`）。
2. **`Battle_GetAttackTimer` (`0x00959b50`, 64 bytes) & `Battle_SetAttackTimer` (`0x00959b90`, 76 bytes)**:
   - 驗證多槽位與多數值對 `+0x83ac8` 之寫入與回讀，100% 吻合。
3. **`Battle_GetUnitHP` (`0x0095987c`, 64 bytes) & `Battle_SetUnitHP` (`0x009598bc`, 68 bytes)**:
   - 驗證單位生命值對 `+0x83960` 之精確寫入與回讀。
4. **`Battle_SetUnitAlive` (`0x00959950`, 76 bytes)**:
   - 驗證單位活躍狀態對 `+0x83964` 之布林掩碼回寫。
5. **`Battle_GetCastleHP` (`0x0095a068`, 64 bytes)**:
   - 驗證城堡生命值對 `+0x83cc8` 之精確存取。

**測試結果**：**5 / 5 套件，涵蓋 7 組原始二進位位址，零 Mismatch，零反例**。

---

## 三、二進位切片與證據集存檔 (Evidence Bundle)
- `evidence_bundle/gettarget_0x957c8c.bin` (52B)
- `evidence_bundle/getatktimer_0x959b50.bin` (64B)
- `evidence_bundle/setatktimer_0x959b90.bin` (76B)
- `evidence_bundle/gethp_0x95987c.bin` (64B)
- `evidence_bundle/sethp_0x9598bc.bin` (68B)
- `evidence_bundle/setalive_0x959950.bin` (76B)
- `evidence_bundle/getcastlehp_0x95a068.bin` (64B)
- `evidence_bundle/disassembly_phase14.txt` (全 7 函式反組譯指令列表)
- `evidence_bundle/phase14_differential_log.txt` (真實差異測試執行日誌)
