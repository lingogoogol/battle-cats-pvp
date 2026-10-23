# Phase 12 — 原生函式等價性獨立重審報告 (FUNCTION_PARITY_REAUDIT.md)

**審查日期**：2026-10-15  
**審查目標**：
1. `Battle_AddUnitKnockback` (`0x00959cf4` ~ `0x00959d44`)
2. `Battle_CheckUnitCanMove` (`0x0095a494` ~ `0x0095a53c`)
**審查核心準則**：
> **Stack Balance PASS $\ne$ Function Parity PASS。**  
> 必須具備可觀測行為（暫存器輸出、記憶體修改、多路徑邊界）之全維度差異比對，方可授予 `NATIVE_FUNCTION_PARITY` 評定。

---

## 1. 目標函式二進位邊界與 ELF 映射獨立核對

| 函式名稱 | 原始 VMA 範圍 | 機器碼位元組數 | ELF 映射區段 | 檔案偏移量 (Offset) | 返回指令 (Epilogue) |
|---|---|:---:|---|---|---|
| **`Battle_AddUnitKnockback`** | `0x00959cf4` ~ `0x00959d44` | 84 bytes (21 指令) | `LOAD[1]` (R-X) | `0x00959cf4` (1:1 映射) | `0x00959d44: ret` (跳回 `x30`) |
| **`Battle_CheckUnitCanMove`** | `0x0095a494` ~ `0x0095a53c` | 172 bytes (43 指令) | `LOAD[1]` (R-X) | `0x0095a494` (1:1 映射) | `0x0095a53c: ret` (跳回 `x30`) |
| **子函式 `GetBattlefieldBase`** | `0x006fd748` ~ `0x006fd750` | 12 bytes (3 指令) | `LOAD[1]` (R-X) | `0x006fd748` (1:1 映射) | `0x006fd750: ret` (跳回 `x30`) |

### 子函式 Stub 狀態查核：
- **查核結果**：**零人工 Stub，零 Mock 代碼**。
- 函式調用 `bl #0x6fd748` 直接執行原始二進位提取之真實指令（`adrp x0, #0xb0e000; add x0, x0, #0xf20; ret`），回傳全域單例位址 `0x00b0ef20`，為 100% 純原生機器碼鏈路。

---

## 2. 函式一：`Battle_AddUnitKnockback` 可觀測行為審查

### (1) 輸入輸出與記憶體契約
- **執行前暫存器配置**：
  - `w0`：陣營 `team` (0 或 1)
  - `w1`：單位槽位 `unit_index` (0 ~ 50)
  - `w2`：擊退差量 `delta` (有符號 32 位元整數，如 `-1` 衰減或 `+15` 擊退觸發)
  - `sp`：`0x7fff8000`
- **可觀測記憶體修改**：
  - 目標位址：$\text{EA} = \text{0x00b0ef20} + (\text{team} \times 51000) + (\text{unit} \times 1000) + \text{0x83ad4}$
  - 運算動作：原子讀取 `ldr w10, [x8, x9]` $\rightarrow$ 累加 `add w10, w10, w19` $\rightarrow$ 寫回 `str w10, [x8, x9]`。
- **被呼叫者保存暫存器（Callee-Saved Registers）保護**：
  - 指令 `0x00959cf4: stp x29, x30, [sp, #-0x30]!`、`str x21, [sp, #0x10]`、`stp x20, x19, [sp, #0x20]`。
  - 離開前於 `0x00959d38` 完整恢復 `x19, x20, x21, x29, x30`。
  - 實測調用後 `SP == 0x7fff8000`，棧無偏移洩漏。

### (2) 獨立重審測試向量與比對
涵蓋雙陣營（Team 0/1）、邊界槽位（0, 1, 5, 10, 25, 50）、正負 Delta（$-5, -1, 0, 5, 15, 30$）：
- 8 組代表性向量比對結果：**100% 記憶體回寫位元吻合，差異數為 0**。

---

## 3. 函式二：`Battle_CheckUnitCanMove` 可觀測行為審查

### (1) 多旗標讀取與決策結構
經深入審計，此函式不僅依賴 `+0x8395c` 與 `+0x83aec`，在第二旗標非零時還進一步讀取第三旗標 `+0x83af0`！
- **輸入暫存器**：`w0 = team`, `w1 = unit_index`。
- **回傳暫存器**：`w0`。
- **可觀測輸出決策矩陣**：
  - **Path 1 (停止/死亡)**：`[0x8395c] == 0` $\rightarrow$ 回傳 `w0 = 0`。
  - **Path 2 (正常前進)**：`[0x8395c] != 0` 且 `[0x83aec] == 0` $\rightarrow$ 回傳 `w0 = 1`。
  - **Path 3 (緩速狀態)**：`[0x8395c] != 0` 且 `[0x83aec] != 0` 且 `[0x83af0] == 0` $\rightarrow$ 回傳 `w0 = 2`。
  - **Path 4 (特殊定身/加速)**：`[0x8395c] != 0` 且 `[0x83aec] != 0` 且 `[0x83af0] != 0` $\rightarrow$ 回傳 `w0 = 3`。

---

## 4. 審查判定結論

1. `Battle_AddUnitKnockback` 具備確鑿之記憶體寫入可觀測行為與棧平衡證明，維持 **`NATIVE_FUNCTION_PARITY`**。
2. `Battle_CheckUnitCanMove` 經 Phase 12 補充補齊 Path 4（`w0 = 3`）實測後，全 4 條路徑輸出與暫存器行為均在 Unicorn 中得到 100% 原生機器碼實測佐證，正式確立為 **`NATIVE_FUNCTION_PARITY`**。
