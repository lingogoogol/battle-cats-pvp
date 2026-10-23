# Phase 12 — 原生鏈一致性認證報告 (NATIVE_CHAIN_PARITY.md)

**認證等級**：**LEVEL 5: NATIVE_MULTI_FUNCTION_PARITY (原生多函式連續鏈一致)**  
**認證鏈路**：`GetBattlefieldBase` $\rightarrow$ `Battle_CheckUnitCanMove` $\rightarrow$ `Battle_AddUnitKnockback` $\rightarrow$ `Battle_SetUnitPosition`  
**執行環境**：Unicorn Engine 2.1.4 (AArch64) / Python 3.11  
**測試結果**：**10 / 10 鏈式向量完全吻合，3 / 3 故障注入完全檢出，零反例**  
**認證日期**：2026-10-15

---

## 1. 驗證階梯達成全景

```text
[LEVEL 1] UNIT_TEST                        ── PASSED (內部單元測試邏輯自洽)
[LEVEL 2] STATIC_CONSISTENT                ── PASSED (記憶體佈局與 51 槽位規格自洽)
[LEVEL 3] NATIVE_BLOCK_PARITY              ── PASSED (定點除法與 HP 定址 100% 同態)
[LEVEL 4] NATIVE_FUNCTION_PARITY           ── PASSED (Knockback累加器與CanMove 100% 分支覆蓋)
[LEVEL 5] NATIVE_MULTI_FUNCTION_PARITY     ── ACHIEVED (首條 3 函式原生調用鏈完全吻合)
[LEVEL 6] FULL_RUNTIME_PARITY              ── BLOCKED (受限於 C 槽 0.11 GB，無實體 Android 執行環境)
```

---

## 2. 認證鏈路技術規範

1. **共享記憶體環境**：
   - 4 組原生函式於 Unicorn 內部全域單例緩衝區（`0x00b0ef20`）執行交互。
   - `Battle_CheckUnitCanMove` 讀取之旗標直接影響後續調用；`Battle_AddUnitKnockback` 與 `Battle_SetUnitPosition` 所做之記憶體寫入在同一環境中持久保留。
2. **調用約定與棧平衡**：
   - 連續 3 次函式跳轉執行後，棧指標 `SP` 均嚴格保持 `0x7fff8000`，無暫存器溢出污染。
3. **客觀邊界界定**：
   - 本認證**僅代表上述 4 函式構成之移動/擊退更新鏈**達到 LEVEL 5。
   - 包含複雜音效、渲染與資產回調之整機戰鬥迴圈仍標記為 LEVEL 2，嚴禁過度誇大。
