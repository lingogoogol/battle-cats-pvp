# Phase 8 — 機制功能等價與原版一致性審計報告 (PARITY_EVIDENCE.md)

**審計項目**：戰鬥勝負結算機制 (`MyApplication::battle_initWin` 與 `battle_initWin_callback`)  
**實作檔案**：[`mechanic_rebuild.py`](file:///E:/rea/phase8/mechanic_rebuild.py)  
**測試檔案**：[`test_mechanic.py`](file:///E:/rea/phase8/test_mechanic.py) (5/5 PASS)  
**評定狀態**：**STATIC_CONSISTENT (靜態邏輯自洽)**  

---

## 1. 嚴正聲明：一致性等級定義與邊界

依據 Phase 8 規範要求，嚴格區分「原型測試通過」與「原版行為一致」之界線：

| 等級代碼 | 定義標準 | 當前機制判定 | 判定理由 |
|---|---|---|---|
| **VERIFIED_PARITY** | 在合法 Android 執行環境中動態執行原版二進位函式，以相同輸入引數比對暫存器、記憶體及日誌，且兩者輸出完全一致。 | **未達成 (NOT CLAIMED)** | 本機缺乏 ARM64 模擬環境與 ADB 工具鏈，無法進行 JNI 注入或 Hook 動態對照。 |
| **STATIC_CONSISTENT** | 重建程式碼嚴格依據 AArch64 二進位反組譯與 Ghidra 反編譯所得之暫存器資料流、常數與條件分支進行 1:1 實作，且通過自製規格測試。 | **ACHIEVED (已達成)** | 條件分支、常數即值 (36, 4, 18, 16) 及位移操作均有二進位指令為證。 |
| **UNVERIFIED_HEURISTIC** | 依據一般遊戲常識或外部 Wiki 描述自行推論之邏輯，無二進位碼依據。 | **REJECTED (已排除)** | 本機制不採納任何未經反組譯證實之假設。 |

> [!WARNING]
> 本單元測試 5/5 全數通過僅代表「自製 Clean-Room 結算模組符合已逆向確認之函式規格（Specification-Compliant）」，**絕不宣稱為已完成動態原版一致性比對（VERIFIED_PARITY）**。

---

## 2. 輸入與輸出映射對照表 (I/O Parity Table)

以下為重建程式碼與 Native 二進位反組譯邏輯之精確對照：

| 測試情境 (Scenario) | 輸入參數 (Inputs) | 原版 Native 指令行為 (AArch64 Disassembly) | 重建實作輸出 (`mechanic_rebuild.py`) | 靜態一致性 |
|---|---|---|---|---|
| **正常勝利結算** | `is_win = True`, `event_code = 4` | `0x004e0018`: 呼叫隱藏 HUD<br>`0x004e002c`: 呼叫勝利號角<br>`0x004e0030`: 呼叫獎勵發放<br>`0x004e0038`: `mov w21, #0x24` (36)<br>`0x004e0068`: `mov w8, #0x12` (18) | `dialog_mode = 36`<br>`bgm_track = 18`<br>`fanfare_played = True`<br>`rewards_awarded = True`<br>`controls_hidden = True` | **MATCH (完全一致)** |
| **正常失敗結算** | `is_win = False`, `event_code = 4` | `0x004e0014`: `cbz w8, #0x4e0060`<br>`0x004e0060`: `mov w21, #4`<br>`0x004e006c`: `mov w9, #0x10` (16)<br>`0x004e0070`: `csel x22, x9, x8, eq` | `dialog_mode = 4`<br>`bgm_track = 16`<br>`fanfare_played = False`<br>`rewards_awarded = False`<br>`controls_hidden = True` | **MATCH (完全一致)** |
| **未確認點擊事件** | `event_code in [0, 1, 2, 3, 99]` | `0x004dff4c`: `cmp w8, #4`<br>`0x004dff50`: `b.eq #0x4dffb8`<br>非 4 則跳出，不執行結算 | `handled = False`<br>狀態維持 `NONE`，無任何副作用寫入 | **MATCH (完全一致)** |
| **閉包位元遮罩極值** | `is_win = 3` (奇數)<br>`is_win = 2` (偶數) | `0x004ced24`: `and x8, x8, #1`<br>`0x004e0014`: `cbz w8` 僅檢查 LSB 是否為 0 | `3 & 1 = 1` $\rightarrow$ 判定為勝利<br>`2 & 1 = 0` $\rightarrow$ 判定為失敗 | **MATCH (完全一致)** |

---

## 3. 測試執行紀錄 (Command & Terminal Logs)

- **測試命令**：`python -m unittest discover -s "E:\rea\phase8" -p "test_*.py" -v`
- **執行時間**：2026-10-15T02:06:12+08:00
- **終端輸出**：
```text
test_closure_bitmask_extreme_inputs (test_mechanic.TestBattleSettlementMechanic.test_closure_bitmask_extreme_inputs) ... ok
test_normal_defeat_flow (test_mechanic.TestBattleSettlementMechanic.test_normal_defeat_flow) ... ok
test_normal_victory_flow (test_mechanic.TestBattleSettlementMechanic.test_normal_victory_flow) ... ok
test_settlement_idempotency (test_mechanic.TestBattleSettlementMechanic.test_settlement_idempotency) ... ok
test_unconfirmed_button_events_ignored (test_mechanic.TestBattleSettlementMechanic.test_unconfirmed_button_events_ignored) ... ok

----------------------------------------------------------------------
Ran 5 tests in 0.000s

OK
```
