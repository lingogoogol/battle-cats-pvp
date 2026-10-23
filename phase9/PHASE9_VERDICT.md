# Phase 9 — 驗收總結裁定書 (PHASE9_VERDICT.md)

**專案名稱**：《貓咪大戰爭》Native 核心深度逆向與可執行性重建  
**專案目錄**：`E:\rea`  
**階段標的**：Phase 9 — 原版核心戰鬥運算逆向與 HP 系統重建  
**驗收基準**：8 項嚴格驗收指標（P9-F）  
**評定日期**：2026-10-15  
**最終總結裁定**：**ACCEPT (驗收通過 / 靜態等價自洽)**

---

## 1. 8 項驗收準則逐項審核矩陣 (Acceptance Audit Matrix)

| 編號 | 驗收檢驗項目 | 審查依據與交付檔案 | 檢驗實證結果 | 判定 |
|:---:|:---|:---|:---|:---:|
| **1** | **Phase 8 疑點修正與重審** | [`PHASE8_CORRECTIONS.md`](file:///E:/rea/phase9/PHASE8_CORRECTIONS.md) | 1. 嚴格切分 Frame Pacing 節流（30 FPS, `0x0098f094` 處 33.33ms 休眠）與 Simulation Tick Rate。<br>2. 驗證 `0x004e0064` 機器碼為 `1f 01 00 71` (`cmp w8, #0`)，證實其為 `0x004e0070` `CSEL ... eq` 提供精確 NZCV 條件旗標。<br>3. 澄清 `0x00766804` 為通用 UI 事件分發器 (`UIElement::DispatchEvent`)，撤回無二進位根據之關卡獎勵推測。<br>4. 追蹤 `is_win` 於 `0x004ced28` 寫入閉包，於 `0x004e0010` 讀取之完整生命週期。 | **PASS** |
| **2** | **定位真實戰鬥傷害與 HP 函式** | [`DAMAGE_FUNCTION_MAP.md`](file:///E:/rea/phase9/DAMAGE_FUNCTION_MAP.md)<br>[`HP_MEMORY_LAYOUT.md`](file:///E:/rea/phase9/HP_MEMORY_LAYOUT.md) | 1. 定位主傷害分發核心 `Battle_ApplyDamageToUnit` (`0x004c6340` ~ `0x004c6c48`, 長度 2,312 位元組)。<br>2. 定位真實 HP 讀寫核心：`Battle_GetUnitHP` (`0x0095987c`) 與 `Battle_SetUnitHP` (`0x009598bc`)。<br>3. 證實防禦方陣營推導指令 `x22 = 1 - target_team` (`0x004c6388`)。<br>4. 拒絕以結算彈窗或勝負回調代替真實戰鬥運算。 | **PASS** |
| **3** | **提供完整可追溯之指令與資料流證據** | [`decompiled_c/`](file:///E:/rea/phase9/decompiled_c/)<br>[`COMBAT_CALL_GRAPH.md`](file:///E:/rea/phase9/COMBAT_CALL_GRAPH.md) | 1. 解析陣營跨度 Stride = 50,996 bytes (`0xc738`) 與單位跨度 Stride = 1,000 bytes (`0x3e8`)。<br>2. 證實編譯器定點數千分比除法常數 `0x10624dd3` (`(x * M) >> 38`)。<br>3. 透過 Ghidra Headless 輸出 6 組重要函式之真實反編譯 C 原始碼。<br>4. 完整繪製自 `EngineCoreLoop` 經傷害分發至死亡結算之 Mermaid 呼叫關係圖。 | **PASS** |
| **4** | **實作乾淨且獨立之可執行傷害模組** | [`combat_core/`](file:///E:/rea/phase9/combat_core/)<br>([`unit_memory.py`](file:///E:/rea/phase9/combat_core/unit_memory.py)<br>[`damage_engine.py`](file:///E:/rea/phase9/combat_core/damage_engine.py)) | 1. 實作獨立記憶體緩衝模型 `BattlefieldMemory`，精確遵循原版雙維度定址步進。<br>2. 實作原生除法定點數千分比運算 (`scale_permille`) 與位元遮罩。<br>3. 實作生命值安全寫回、擊退門檻判定與死亡清理機制，無外部未受控依賴。 | **PASS** |
| **5** | **執行自動化單元測試並記錄日誌** | [`test_damage.py`](file:///E:/rea/phase9/test_damage.py)<br>[`DAMAGE_PARITY_REPORT.md`](file:///E:/rea/phase9/DAMAGE_PARITY_REPORT.md) | 1. 建立涵蓋除法魔術常數、標準扣血、致死清理、極值邊界、擊退觸發、護盾防禦及死亡免疫等 7 大測試案例。<br>2. 7/7 測試全數通過（`Ran 7 tests in 0.001s, OK`）。<br>3. 測試輸入條件、Native 指令對應、預期輸出與實際輸出完整存檔。 | **PASS** |
| **6** | **嚴格標記等價性等級** | [`DAMAGE_PARITY_REPORT.md`](file:///E:/rea/phase9/DAMAGE_PARITY_REPORT.md)<br>[`RUNTIME_STATUS.md`](file:///E:/rea/phase9/RUNTIME_STATUS.md) | 1. 明確標記模組當前狀態為 **`STATIC_CONSISTENT` (靜態規格自洽)**。<br>2. 嚴正聲明 **`PARITY_UNVERIFIED` (動態未比對)**，絕不因 Python 測試通過而虛假聲稱與原版執行期 100% 動態等價。<br>3. 標記 Android 執行期動態測試為 **`BLOCKED`**，深入分析 host 磁碟與 ARM64 轉譯限制。 | **PASS** |
| **7** | **保護既有資產與原始檔案** | 目錄結構稽核 | 1. `catAPKPure.xapk` 及解包之 `base.apk`、`libnative-lib.so` SHA-256 完整保留無修改。<br>2. Phase 1~8 之所有稽核報告、原型與 Ghidra 專案資料夾全部完整留存。 | **PASS** |
| **8** | **絕無捏造之逆向數據與結果** | 全 Phase 9 交付物 | 1. 所有 10 個核心實體欄位偏移（如 `0x83960`、`0x83964`、`0x83950` 等）皆源自 `0x00959800` ~ `0x0095a200` 之 AArch64 指令。<br>2. Max HP 與 KB Count 明確標示為 `INFERRED`（由 CSV 載入），不偽稱為原生記憶體獨立欄位。 | **PASS** |

---

## 2. 核心技術突破與里程碑成果

1. **從「周邊外圍結算」正式跨入「核心數值運算」**：
   - 徹底揮別過去僅能分析 JNI 外層回調與勝負彈窗之侷限，成功破譯位於 `libnative-lib.so` 深層之戰鬥數值引擎 `Battle_ApplyDamageToUnit` (`0x004c6340`)。
2. **完整破譯戰場實體記憶體模型**：
   - 確認戰場為二維連續緩衝區，以 `50,996` 位元組區隔陣營，`1,000` 位元組區隔實體槽位。
   - 提取包含生命值、存活旗標、一維定點座標、狀態機計時器在內之 10 項關鍵欄位與 Getter/Setter 函式表。
3. **還原原版定點數千分比運算引擎**：
   - 逆向出編譯器針對除以 1000 之優化常數 `0x10624dd3` 與位移指令，證實《貓咪大戰爭》全戰鬥屬性皆採千分比（Permille, 1000 = 100%）定點數架構運算，並在自研模組中達成 0 誤差靜態自洽。

---

## 3. 當前限制與後續階段（Phase 10）建議規劃

1. **當前技術瓶頸**：
   - 主機 C 槽剩餘空間嚴重不足（僅 0.48 GB），且二進位庫為純 64 位元 ARM 架構（`arm64-v8a`），無法在 x86_64 主機無轉譯器情況下直接執行二進位動態調用。
2. **Phase 10 後續推進路徑**：
   - **推進方向 A（實體機動態比對）**：引入 USB 連接之實體 ARM64 Android 設備，配置輕量化 Platform-Tools，針對真實執行期記憶體進行動態 Dump 比對。
   - **推進方向 B（移動與攻擊狀態機逆向）**：接續解析 `0x00959800`（座標更新）與 `0x00959a70`（攻擊計時器更新），還原單位在戰場上的推進碰撞與攻擊前搖/後搖時間判定。
   - **推進方向 C（二進位隔離調用）**：評估利用 QEMU User-Mode 或 Unicorn Engine 構建輕量級 AArch64 指令級執行器，直接單元呼叫 `0x004c6340` 進行執行期黑箱輸入輸出比對。
