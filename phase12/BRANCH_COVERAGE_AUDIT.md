# Phase 12 — 控制流程圖與原生分支覆蓋率審計報告 (BRANCH_COVERAGE_AUDIT.md)

**審計目標**：使用 Unicorn Block Hook 與 Code Hook 追蹤目標原生函式之真實基本區塊（Basic Blocks）與控制流跳轉邊（Branch Edges）執行軌跡。  
**分析函式**：
1. `Battle_CheckUnitCanMove` (`0x0095a494` ~ `0x0095a53c`)
2. `Battle_AddUnitKnockback` (`0x00959cf4` ~ `0x00959d44`)

---

## 1. `Battle_CheckUnitCanMove` 控制流程圖 (CFG) 形式化分解

經 Ghidra 與 Capstone 完整指令還原，該函式由 6 個內部基本區塊與 1 個子函式區塊構成：

```text
[Block 0: 0x0095a494 ~ 0x0095a4c8] (入口與第一旗標讀取)
  │  指令: stp, mov sp, bl #0x6fd748, ldr w8, [x8, #0x8395c]
  │  決策: 0x0095a4c8: cbz w8, #0x95a528
  ├── [Edge 1A: Taken] (w8 == 0, 實體停止/死亡) ──────────────┐
  └── [Edge 1B: Fallthrough] (w8 != 0)                          │
        │                                                       │
[Block 1: 0x0095a4cc ~ 0x0095a4f4] (第二旗標讀取)                │
  │  指令: sxtw, bl #0x6fd748, ldr w8, [x8, #0x83aec]          │
  │  決策: 0x0095a4f4: cbz w8, #0x95a530                        │
  ├── [Edge 2A: Taken] (w8 == 0, 正常前進) ─────────┐          │
  └── [Edge 2B: Fallthrough] (w8 != 0)              │          │
        │                                           │          │
[Block 2: 0x0095a4f8 ~ 0x0095a524] (第三旗標讀取與狀態判定) │          │
  │  指令: bl #0x6fd748, ldr w8, [x8, #0x83af0]     │          │
  │  決策: cmp w8, #0; cinc w0, w8, ne              │          │
  │        [Condition 3A]: w8 == 0 -> w0 = 2 (緩速) │          │
  │        [Condition 3B]: w8 != 0 -> w0 = 3 (特殊) │          │
  │  跳轉: b #0x95a534 ─────────────────────────────┼─────┐    │
        │                                           │     │    │
        ├───────────────────────────────────────────┘     │    │
[Block 4: 0x0095a530] (正常前進賦值)                      │    │
  │  指令: mov w0, #1                                      │    │
  │  穿透: 0x0095a534 ─────────────────────────────────────┤    │
        │                                                  │    │
        ├──────────────────────────────────────────────────┼────┘
[Block 3: 0x0095a528 ~ 0x0095a52c] (停步賦值)             │
  │  指令: mov w0, wzr; b #0x95a534                        │
  │  跳轉: 0x0095a534 ─────────────────────────────────────┘
        │
[Block 5: 0x0095a534 ~ 0x0095a53c] (函式出口)
     指令: ldp x20, x19; ldp x29, x30; ret
```

---

## 2. Unicorn 執行軌跡比對與覆蓋率度量 (Coverage Measurement)

透過 Unicorn 註冊 `UC_HOOK_BLOCK` 追蹤 4 組測試向量之實際基本區塊執行鏈：

| 測試路徑標號 | 注入旗標組合 `(flag_95c, flag_aec, flag_af0)` | 實際執行之基本區塊鏈 (Block Trace) | 判定回傳值 `w0` | 跳轉邊激活 (Active Edge) |
|:---:|:---:|---|:---:|:---:|
| **Path 1** | `(0, 0, 0)` | `0x95a494` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4ac` $\rightarrow$ `0x95a528` $\rightarrow$ `0x95a534` | **`0`** | **Edge 1A (Taken)** |
| **Path 2** | `(1, 0, 0)` | `0x95a494` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4ac` $\rightarrow$ `0x95a4cc` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4d8` $\rightarrow$ `0x95a530` | **`1`** | **Edge 1B + Edge 2A (Taken)** |
| **Path 3** | `(1, 1, 0)` | `0x95a494` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4ac` $\rightarrow$ `0x95a4cc` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4d8` $\rightarrow$ `0x95a4f8` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4fc` $\rightarrow$ `0x95a534` | **`2`** | **Edge 2B + Condition 3A** |
| **Path 4** | `(1, 1, 1)` | `0x95a494` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4ac` $\rightarrow$ `0x95a4cc` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4d8` $\rightarrow$ `0x95a4f8` $\rightarrow$ `0x6fd748` $\rightarrow$ `0x95a4fc` $\rightarrow$ `0x95a534` | **`3`** | **Edge 2B + Condition 3B** |

### 覆蓋率計算：
1. **基本區塊覆蓋率 (Block Coverage)**：
   - 總基本區塊數：6 個內部區塊 + 1 個子函式區塊 = **7 個**
   - 實際執行區塊數：**7 / 7**
   - **Block Coverage = 100.0%**
2. **分支邊覆蓋率 (Branch Edge Coverage)**：
   - 總決策邊數：Edge 1A, Edge 1B, Edge 2A, Edge 2B, Cond 3A, Cond 3B = **6 條**
   - 實際激活邊數：**6 / 6**
   - **Branch Edge Coverage = 100.0%**
3. **未執行路徑 (Unexecuted Paths)**：**0 (無任何死代碼或阻斷路徑)**。

---

## 3. `Battle_AddUnitKnockback` 控制流程審計

- **CFG 結構**：包含 2 個內部區塊（Prologue/Store 與 Load/Epilogue）以及子函式 `0x6fd748`。
- **分支性質**：無內部條件分支指令（`b.cond` 或 `cbz`），為標準**無條件直線控制流（Unconditional Linear Flow）**。
- **Block Coverage**：**3 / 3 (100.0%)**。
