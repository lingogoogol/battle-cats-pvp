# Phase 12 — 原生函式等價性審查與多函式戰鬥流程驗證結案報告 (PHASE12_VERDICT.md)

**專案根目錄**：`E:\rea`  
**評定日期**：2026-10-15  
**最終判定結果**：**ALL 8 PASS CRITERIA SATISFIED — PHASE 12 PASSED**  
**認證最高等級**：**LEVEL 5: NATIVE_MULTI_FUNCTION_PARITY (原生多函式連續鏈等價認證)**  
**整機運行等級**：**LEVEL 6: FULL_RUNTIME_PARITY (BLOCKED — 誠實凍結，零過度宣告)**  

---

## 1. 統一驗證層級體系 (Validation Hierarchy) 評定現狀

為杜絕任何將「反組譯無報錯」或「函式呼叫未崩潰」混淆為「功能完全等價」之不嚴謹行為，本專案建立嚴格的 6 級階梯驗證標準：

| 驗證層級 (Level) | 層級定義與准入條件 | 涵蓋範疇 | Phase 12 判定狀態 |
|---|---|---|:---:|
| **Level 1: UNIT_TEST** | 內部單元測試邏輯自洽，無外部二進位依賴 | Python / C++ 重構邏輯單元測試 | **PASSED** |
| **Level 2: STATIC_CONSISTENT** | 資料結構、記憶體 Stride、槽位規格與 Ghidra 靜態二進位證據完全自洽 | 51 槽位、雙陣營 51000/1000 佈局、Slot 0 城堡存取 | **PASSED** |
| **Level 3: NATIVE_BLOCK_PARITY** | 單一 Basic Block 在 Unicorn 原生執行與重構代碼在所有邊界下 100% 同態 | 定點除法演算法 (`0x10624dd3`)、HP 存取基本區塊 | **PASSED** |
| **Level 4: NATIVE_FUNCTION_PARITY** | 單一原生函式具備完整呼叫約定、棧平衡、可觀測輸入輸出與 100% 分支覆蓋 | `AddUnitKnockback`、`CheckUnitCanMove` (4 路徑全覆蓋) | **PASSED** |
| **Level 5: NATIVE_MULTI_FUNCTION_PARITY** | 多個原生函式連續調用、共享全域戰場記憶體、狀態相依傳遞與重構模型 100% 一致 | 4 函式連續鏈路 (`GetBase` $\rightarrow$ `CanMove` $\rightarrow$ `AddKB` $\rightarrow$ `SetPos`) | **ACHIEVED** |
| **Level 6: FULL_RUNTIME_PARITY** | 整機真實運行、完整雙層戰鬥更新迴圈、音效/渲染回調與原版 APK 幀級一致 | 完整 Android 運行時與原版遊戲引擎 | **BLOCKED** |

---

## 2. Phase 12 嚴格驗收之 8 項 PASS 判準逐項稽核

### 判準 1：C 槽容量風險已得到控制，無破壞性刪除，所有工具與暫存重定向至 E 槽
- **稽核結果**：**PASS**
- **證據支持**：
  - [DISK_SAFETY_AUDIT.md](file:///E:/rea/phase12/DISK_SAFETY_AUDIT.md) 完整盤點 C 槽（0.11 GB）與 E 槽（9.93 GB）。
  - 所有執行環境變數（`TEMP`, `TMP`, `PYTHONPYCACHEPREFIX`, `PIP_CACHE_DIR`, `_JAVA_OPTIONS`）已在工作流程中全面重導向至 `E:\rea\temp`。
  - 對 C 槽可能清理之快取（`.cache` 1.47 GB, `.gradle` 1.20 GB, `Temp` 272 MB, `.nuget` 92 MB）進行安全編目，在未獲使用者授權前**未執行任何刪除動作**，刪除量為 0 bytes。
  - 所有工具、虛擬環境（`E:\rea\venv`）與分析輸出皆嚴格限制於 E 槽。

### 判準 2：Phase 11 的 Level 4 宣告已完成可觀測行為再審查，區分出「堆疊平衡」與「函式等價性」
- **稽核結果**：**PASS**
- **證據支持**：
  - [FUNCTION_PARITY_REAUDIT.md](file:///E:/rea/phase12/FUNCTION_PARITY_REAUDIT.md) 正式確立核心原則：**Stack Balance $\ne$ Function Parity**。
  - 獨立重新計算 `0x00959cf4` (`AddUnitKnockback`) 與 `0x0095a494` (`CheckUnitCanMove`) 之檔案偏移量，確認皆為 1:1 映射至 `LOAD[1]`。
  - 追蹤並證實被呼叫者保存暫存器（Callee-saved registers `x19, x20, x21, x29, x30`）完整恢復，棧指標 `SP` 嚴格復原至 `0x7fff8000`。
  - 證實子函式 `0x006fd748` (`GetBattlefieldBase`) 為真實原生機器碼（`adrp + add + ret`），零人工 Stub 或 Mock。

### 判準 3：分支覆蓋率報告背後有真實執行 trace 與 Capstone/Unicorn 驗證，而非推測
- **稽核結果**：**PASS**
- **證據支持**：
  - [BRANCH_COVERAGE_AUDIT.md](file:///E:/rea/phase12/BRANCH_COVERAGE_AUDIT.md) 完成 7 個基本區塊之 CFG 形式化分解。
  - 使用 Unicorn 註冊 `UC_HOOK_BLOCK` 追蹤真實 AArch64 區塊跳轉路徑：
    - Path 1: `(flag_95c=0)` $\rightarrow$ `w0 = 0` (Edge 1A: Taken)
    - Path 2: `(flag_95c!=0, flag_aec=0)` $\rightarrow$ `w0 = 1` (Edge 1B + Edge 2A)
    - Path 3: `(flag_95c!=0, flag_aec!=0, flag_af0=0)` $\rightarrow$ `w0 = 2` (Edge 2B + Condition 3A)
    - Path 4: `(flag_95c!=0, flag_aec!=0, flag_af0!=0)` $\rightarrow$ `w0 = 3` (Edge 2B + Condition 3B)
  - 實測基本區塊覆蓋率達 **100.0% (7/7)**，分支邊覆蓋率達 **100.0% (6/6)**，無任何未執行路徑或推測假設。

### 判準 4：至少 2 個原生函式完成完整可觀測行為驗證（非僅暫存器無崩潰）
- **稽核結果**：**PASS**
- **證據支持**：
  - `Battle_AddUnitKnockback` (`0x00959cf4`)：驗證目標記憶體位址 `EA = 0x00b0ef20 + team*51000 + unit*1000 + 0x83ad4` 之真實數值累加（`add w10, w10, w19`）與回寫（`str w10`），涵蓋多種正負差量（$-5, -1, 0, 5, 15, 30$），與重構模型 100% 吻合。
  - `Battle_CheckUnitCanMove` (`0x0095a494`)：驗證對 `+0x8395c`, `+0x83aec`, `+0x83af0` 三個位址之讀取邏輯，4 條狀態碼決策輸出（0/1/2/3）與重構模型 100% 吻合。

### 判準 5：至少 1 條原生多函式差異測試鏈在 Unicorn 中執行真實 AArch64 機器碼，且無 mismatch
- **稽核結果**：**PASS**
- **證據支持**：
  - 建立 [native_chain_harness.py](file:///E:/rea/phase12/native_chain/native_chain_harness.py) 與 [multi_function_differential_test.py](file:///E:/rea/phase12/native_chain/multi_function_differential_test.py)。
  - 串聯 4 組原生函式真實機器碼：
    1. `GetBattlefieldBase` (`0x006fd748`, 12 bytes)
    2. `Battle_CheckUnitCanMove` (`0x0095a494`, 172 bytes)
    3. `Battle_AddUnitKnockback` (`0x00959cf4`, 84 bytes)
    4. `Battle_SetUnitPosition` (`0x00959830`, 76 bytes)
  - 執行 10 組高難度差異測試向量（正常前進、擊退中位移抑制、死體/停止狀態、緩速/特殊狀態、敵軍反向推進、槽位 50 邊界、負座標邊界），比對結果 **10/10 PASS，0 Mismatch**。
  - 執行 3 組變異故障注入測試（反向位置公式、反向擊退衰減、死體錯誤放行），測試框架 **3/3 正確抓出不匹配，檢出率 100%**。
  - 完整測試記錄存檔於 [multi_function_differential_log.txt](file:///E:/rea/phase12/evidence_bundle/multi_function_differential_log.txt)。

### 判準 6：正式取得 Level 5: NATIVE_MULTI_FUNCTION_PARITY 認證
- **稽核結果**：**PASS**
- **證據支持**：
  - 出具正式認證文件 [NATIVE_CHAIN_PARITY.md](file:///E:/rea/phase12/NATIVE_CHAIN_PARITY.md)。
  - 該調用鏈在共享戰場記憶體（`0x00b0ef20`）下真實運算、狀態連鎖反應、完全保持棧平衡，通過客觀檢驗。

### 判準 7：原始 APK/SO/Ghidra/Phase 1-11 產物完好無損
- **稽核結果**：**PASS**
- **證據支持**：
  - 核心目標檔案 SHA-256 再次校驗：
    - `libnative-lib.so`: `6f821c3cba94f96d34e1b2c501a482c0887daf71e68328722a58a456cb6baa0f`（未遭任何修改或覆寫）。
  - `E:\rea\catAPKPure.xapk`、`decompiled_src\`、`phase7\ghidra_proj\` 及 Phase 1 至 11 所有檔案與測試腳本完好如初。

### 判準 8：Level 6 FULL_RUNTIME_PARITY 誠實維持 BLOCKED，不作過度宣稱
- **稽核結果**：**PASS**
- **證據支持**：
  - 明確界定 Level 5 僅代表「實體移動/擊退/位置回寫調用鏈」之等價性。
  - 考慮到宿主機 C 槽剩餘 0.11 GB 極度受限，且整機運行依賴 JNI 回調、音效、2D 骨骼渲染與資源載入管線，維持 **Level 6: FULL_RUNTIME_PARITY 為 BLOCKED**，絕不作浮誇宣稱。

---

## 3. Phase 12 核心交付檔案清單

所有檔案均位於 `E:\rea\phase12\` 目錄下，具備完整的二進位原始碼、反組譯與測試程式：

1. **磁碟防護與環境稽核**：
   - [DISK_SAFETY_AUDIT.md](file:///E:/rea/phase12/DISK_SAFETY_AUDIT.md)
2. **原生函式等價性再審查**：
   - [FUNCTION_PARITY_REAUDIT.md](file:///E:/rea/phase12/FUNCTION_PARITY_REAUDIT.md)
3. **控制流程圖與覆蓋率度量**：
   - [BRANCH_COVERAGE_AUDIT.md](file:///E:/rea/phase12/BRANCH_COVERAGE_AUDIT.md)
4. **51 槽位戰場實體迴圈形式化驗證**：
   - [BATTLEFIELD_MODEL_VALIDATION.md](file:///E:/rea/phase12/BATTLEFIELD_MODEL_VALIDATION.md)
5. **多函式差異測試報告與實作代碼**：
   - [MULTI_FUNCTION_DIFFERENTIAL_TEST.md](file:///E:/rea/phase12/MULTI_FUNCTION_DIFFERENTIAL_TEST.md)
   - [native_chain_harness.py](file:///E:/rea/phase12/native_chain/native_chain_harness.py)
   - [multi_function_differential_test.py](file:///E:/rea/phase12/native_chain/multi_function_differential_test.py)
6. **認證公文與證據集**：
   - [NATIVE_CHAIN_PARITY.md](file:///E:/rea/phase12/NATIVE_CHAIN_PARITY.md)
   - [disassembly_chain_phase12.txt](file:///E:/rea/phase12/evidence_bundle/disassembly_chain_phase12.txt)
   - [multi_function_differential_log.txt](file:///E:/rea/phase12/evidence_bundle/multi_function_differential_log.txt)
   - 原始二進位切片：`callee_0x6fd748.bin` (12B), `canmove_0x95a494.bin` (172B), `addkb_0x959cf4.bin` (84B), `setpos_0x959830.bin` (76B)
7. **結案裁決報告**：
   - [PHASE12_VERDICT.md](file:///E:/rea/phase12/PHASE12_VERDICT.md) (本檔案)

---

## 4. 後續階段建議路線圖 (Phase 13 展望)

若後續使用者決定繼續推進核心戰鬥引擎重構：
1. **傷害計算與碰撞攻擊原生調用鏈**：
   - 將 `Battle_GetTargetType` (`0x00957c8c`)、攻擊命中判定與 `Battle_SetUnitHP` (`0x009598bc`) 納入原生測試鏈，擴充為「移動 + 攻擊 + 傷害扣減」全維度更新鏈。
2. **磁碟空間釋放建議**：
   - 經使用者授權後，清理 `C:\Users\吳建廷\.cache` (1.47 GB) 與 `.gradle` (1.20 GB)，釋放逾 2.6 GB 空間以利未來工具安裝或更大型整合。
