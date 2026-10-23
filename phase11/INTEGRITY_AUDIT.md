# Phase 11 — 功能驗證層級完整性與正確性稽核報告 (INTEGRITY_AUDIT.md)

**審計原則**：嚴格切分各子模組實際達成之一致性等級，嚴禁以單一子模組之進度概括全引擎，堅守工程客觀性。

---

## 1. 6 級驗證體系標準定義 (Validation Tier Definitions)

| 等級代碼 | 等級名稱 | 判定標準與技術門檻 |
|:---:|:---|:---|
| **LEVEL 1** | **UNIT_TEST** | 自行編寫單元測試，驗證內部重組程式碼之輸入輸出邏輯自洽。 |
| **LEVEL 2** | **STATIC_CONSISTENT** | 重組結構之記憶體佈局、常數、欄位偏移量與條件分支完全符合反組譯/反編譯之二進位靜態規格。 |
| **LEVEL 3** | **NATIVE_BLOCK_PARITY** | 提取原版 AArch64 純算術或定址指令切片，於 CPU 模擬器中執行，在相同輸入下與重組邏輯達成 100% 輸出一致（含極端邊界與模糊測試）。 |
| **LEVEL 4** | **NATIVE_FUNCTION_PARITY** | 提取原版完整函式（含真實 Prologue、Epilogue、棧幀平衡、真實子函式跳轉與完整條件分支），於模擬器中覆蓋 100% 分支路徑，達成全生命週期一致。 |
| **LEVEL 5** | **NATIVE_MULTI_FUNCTION_PARITY** | 多個原生函式相互調用並在統一虛擬環境中完成多步狀態推進比對。 |
| **LEVEL 6** | **FULL_RUNTIME_PARITY** | 在合法 Android 系統執行期環境中注入相同輸入，實測與原版遊戲記憶體及封包完全等價。 |

---

## 2. 戰鬥系統各子功能獨立評定矩陣 (Feature Parity Matrix)

依據本專案截至 Phase 11 之真實測試數據，逐項獨立評定：

| 子功能模組名稱 | 原始二進位位址 (VMA) | 當前達成之最高等級 | 實測佐證檔案與依據 | 備註與邊界說明 |
|---|---|:---:|---|---|
| **千分比除法運算 (`magic_div`)** | `0x004c6800` ~ `0x004c681c` | **LEVEL 3** (NATIVE_BLOCK) | [`DIFFERENTIAL_TEST.md`](file:///E:/rea/phase10/DIFFERENTIAL_TEST.md) (1,017 組測試 0 反例) | 涵蓋向零截斷與 32-bit 乘法溢位環繞 |
| **生命值定址讀取 (`GetUnitHP`)** | `0x00959894` ~ `0x009598b0` | **LEVEL 3** (NATIVE_BLOCK) | [`DIFFERENTIAL_TEST.md`](file:///E:/rea/phase10/DIFFERENTIAL_TEST.md) (48 組測試 0 反例) | 覆蓋雙陣營與 51 槽位定址 |
| **生命值定址寫入 (`SetUnitHP`)** | `0x009598dc` ~ `0x009598f8` | **LEVEL 3** (NATIVE_BLOCK) | [`DIFFERENTIAL_TEST.md`](file:///E:/rea/phase10/DIFFERENTIAL_TEST.md) (32 組測試 0 反例) | 覆蓋記憶體真實回寫 |
| **擊退計時累加器 (`AddKnockback`)** | `0x00959cf4` ~ `0x00959d44` | **LEVEL 4** (NATIVE_FUNCTION) | [`FUNCTION_DIFFERENTIAL_TEST.md`](file:///E:/rea/phase11/FUNCTION_DIFFERENTIAL_TEST.md) | 包含完整棧幀、子函式 `0x6fd748` 調用與棧平衡 |
| **移動許可與狀態檢查 (`CanMove`)** | `0x0095a494` ~ `0x0095a53c` | **LEVEL 4** (NATIVE_FUNCTION) | [`FUNCTION_DIFFERENTIAL_TEST.md`](file:///E:/rea/phase11/FUNCTION_DIFFERENTIAL_TEST.md) | 覆蓋 3 個條件分支路徑，分支覆蓋率 100% |
| **位置座標讀寫 (`Get/SetPosition`)** | `0x009597f0` / `0x00959830` | **LEVEL 2** (STATIC_CONSISTENT) | 機器碼反組譯與單元測試自洽 | 定址與 HP 完全對稱（偏移 `+0x83950`） |
| **51 槽位遍歷外迴圈** | `0x005c8ad4` / `0x005c9360` | **LEVEL 2** (STATIC_CONSISTENT) | 反組譯圖譜與暫存器 `x23` 追蹤 | 證實 `cmp x23, #0x33` 終止條件 |
| **單位死亡除役清理 (`KillUnit`)** | `0x008b6f50` | **LEVEL 2** (STATIC_CONSISTENT) | 證實三核心欄位歸零寫入 | 內部包含動畫與音效間接回調 |
| **多步驟戰鬥引擎 (`IntegratedEngine`)** | `combat_engine/` | **LEVEL 2** (STATIC_CONSISTENT) | [`test_integration.py`](file:///E:/rea/phase11/test_integration.py) (8 步驟測試通過) | 宏觀調度由 Python 組織已驗證模組 |
| **Android 系統完整動態等價** | 整個 APK / SO 運行時 | **LEVEL 6 (BLOCKED)** | [`ANDROID_RUNTIME_ASSESSMENT.md`](file:///E:/rea/phase11/ANDROID_RUNTIME_ASSESSMENT.md) | 主機 C 槽剩餘 0.08 GB，動態環境無法建立 |

---

## 3. 誠信聲明與客觀邊界

> [!IMPORTANT]
> **嚴正聲明：拒絕虛誇驗證層次**
> 
> 1. 本專案成功將 `Battle_AddUnitKnockback` 與 `Battle_CheckUnitCanMove` 推進至 **LEVEL 4 (NATIVE_FUNCTION_PARITY)**，這是逆向工程的重大實質里程碑。
> 2. 但絕不得因此宣稱「整個戰鬥引擎已達 Level 4」。宏觀多步驟調度器目前仍位於 **LEVEL 2 (STATIC_CONSISTENT)**，部分周邊數值（如動畫延遲、擊退位移速度）仍標記為 **ASSUMED**。
> 3. 在未實際運行 Android 系統前，**LEVEL 6 (FULL_RUNTIME_PARITY) 維持嚴格標記為 BLOCKED**。
