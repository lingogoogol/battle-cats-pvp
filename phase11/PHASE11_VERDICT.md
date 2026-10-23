# Phase 11 — 驗收總結裁定書 (PHASE11_VERDICT.md)

**專案名稱**：《貓咪大戰爭》戰鬥狀態機逆向與 Native 多函式整合驗證  
**工作目錄**：`E:\rea`  
**階段標的**：Phase 11 — 戰鬥狀態機逆向與 Native 多函式整合驗證  
**評定日期**：2026-10-15  
**最終總結裁定**：**PASS (驗收通過 / 達成 NATIVE_FUNCTION_PARITY 與戰鬥核心整合)**

---

## 1. 9 大核心驗收指標逐項審核表 (Acceptance Audit Matrix)

| 編號 | 驗收檢驗指標 | 審查依據與交付檔案 | 實證結果 | 判定 |
|:---:|:---|:---|:---|:---:|
| **1** | **Phase 10 成果獨立重驗** | [`PHASE10_INDEPENDENT_RECHECK.md`](file:///E:/rea/phase11/PHASE10_INDEPENDENT_RECHECK.md)<br>[`phase10_recheck.py`](file:///E:/rea/phase11/native_emulation/phase10_recheck.py) | 1. 重新核對 SO SHA-256 (`6f821c3c...`) 100% 一致。<br>2. 獨立自 ELF PT_LOAD 導出 1:1 映射。<br>3. 重新提取 3 段機器碼並與 Phase 10 evidence_bundle 比對無誤。<br>4. 在全新 Unicorn 實例中分別重跑 1,017 + 48 + 32 = **1,097 組測試全部通過**。 | **PASS** |
| **2** | **變異測試有效性驗證** | [`PHASE10_INDEPENDENT_RECHECK.md`](file:///E:/rea/phase11/PHASE10_INDEPENDENT_RECHECK.md) | 1. 注入 5 組缺陷（常數微調、位移計數、陣營跨度 50996、單位跨度 1004、移除符號修正）。<br>2. **變異捕捉率 5/5 (100%)**，無一漏檢，證實差異測試之高敏度。 | **PASS** |
| **3** | **51 槽位迴圈邊界二進位實證** | [`BATTLE_SLOT_LOOP.md`](file:///E:/rea/phase11/BATTLE_SLOT_LOOP.md)<br>[`disassembly_bundle_phase11.txt`](file:///E:/rea/phase11/evidence_bundle/disassembly_bundle_phase11.txt) | 1. 提取指令 `0x005c8b00: cmp x23, #0x33` 與 `0x005c8c80: cmp w24, #0x33`，證實 51 槽位邊界。<br>2. 證實外迴圈 `mov w23, #1`（跳過 Slot 0 靜態城堡），內迴圈 `mov w24, wzr`（偵測敵方城堡受擊與碰撞）。<br>3. 證實雙陣營迴圈完全鏡像對稱。 | **PASS** |
| **4** | **移動/狀態更新函式深度逆向** | [`MOVEMENT_STATE_MACHINE.md`](file:///E:/rea/phase11/MOVEMENT_STATE_MACHINE.md) | 1. 完整逆向 6 大函式（`Get/SetPosition`, `AddKnockback`, `GetSpeed`, `CanMove`）。<br>2. 釐清座標、速度與計時器全為 32 位元有符號整數定點數。<br>3. 明確標示 VERIFIED / INFERRED / ASSUMED 邊界。 | **PASS** |
| **5** | **多分支原生函式差異測試** | [`FUNCTION_DIFFERENTIAL_TEST.md`](file:///E:/rea/phase11/FUNCTION_DIFFERENTIAL_TEST.md)<br>[`function_differential_test.py`](file:///E:/rea/phase11/native_emulation/function_differential_test.py) | 1. 在 Unicorn 中執行完整原生函式 `Battle_AddUnitKnockback` (`0x00959cf4`)，達成 100% 棧平衡與零人工 Stub（子函式 `0x6fd748` 亦為真實原生機器碼）。<br>2. 在 `Battle_CheckUnitCanMove` (`0x0095a494`) 達成 **3 個主要條件分支 100% Branch Coverage**，零反例。 | **PASS** |
| **6** | **可執行戰鬥核心原型整合** | [`combat_engine/`](file:///E:/rea/phase11/combat_engine/)<br>[`test_integration.py`](file:///E:/rea/phase11/test_integration.py)<br>[`INTEGRATION_VALIDATION.md`](file:///E:/rea/phase11/INTEGRATION_VALIDATION.md) | 1. 構建整合 8 大步驟之 `IntegratedBattleEngine`。<br>2. 執行可重現的多步驟對戰模擬：驗證行軍遭遇、重擊擊退硬直衰減、冷卻反擊、致死除役清理與城堡攻堅扣血。 | **PASS** |
| **7** | **驗證層級客觀標記** | [`INTEGRITY_AUDIT.md`](file:///E:/rea/phase11/INTEGRITY_AUDIT.md) | 1. 建立 Level 1 ~ Level 6 嚴謹階梯體系。<br>2. 兩項函式取得 **LEVEL 4 (NATIVE_FUNCTION_PARITY)**。<br>3. 引擎宏觀架構客觀標示為 LEVEL 2，**LEVEL 6 (FULL_RUNTIME_PARITY) 維持 BLOCKED**，絕不虛誇。 | **PASS** |
| **8** | **原始資產完好保留** | 目錄完整性稽核 | 1. 原始 APK/XAPK、`libnative-lib.so` SHA-256 完好，Phase 1~10 成果完全保留。 | **PASS** |
| **9** | **獨立審查證據庫** | [`evidence_bundle/`](file:///E:/rea/phase11/evidence_bundle/) | 1. 保存 5 組原始機器碼 `.bin` 檔案、Capstone 反組譯文字檔與 3 份測試原始日誌。 | **PASS** |

---

## 2. Phase 11 重大技術里程碑

1. **從「指令級」正式跨越至「完整函式級（NATIVE_FUNCTION_PARITY）」**：
   - 突破單純算術與定址模擬，首次成功在虛擬 CPU 中建立具備真實函式呼叫棧、真實子函式調用（`0x6fd748`）、棧平衡還原與 100% 條件分支覆蓋的完整原生函式差異測試。
2. **揭開 51 槽位戰場實體更新之謎**：
   - 徹底搞清 Slot 0（固定城堡）與 Slot 1..50（部署實體）在雙層迴圈中的精確行為模式，解釋了外迴圈為何從 1 開始而內迴圈從 0 開始的物理語意。
3. **戰鬥引擎首度實現全流程可運作閉環**：
   - 實現首個結合真實二進位位址定址、千分比傷害運算、擊退原子衰減與城堡攻堅的可單步除錯整合戰鬥引擎。
