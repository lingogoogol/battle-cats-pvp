# Phase 10 — 戰場實體與 HP 記憶體佈局形式化證明 (MEMORY_LAYOUT_PROOF.md)

**分析對象**：`libnative-lib.so` (AArch64) 實體存取核心模組 (`0x00959800` ~ `0x0095a200`)  
**驗證方式**：逐指令暫存器追蹤 + Unicorn ARM64 記憶體讀寫實測  
**關鍵修正**：**更正 Phase 9 Team Stride 50,996 的進位誤差，確立真實 Stride 為 51,000 bytes (`0xc738`)**

---

## 1. 核心定址常數與更正證明

在 Phase 9 報告中，曾提及 Team Stride 為 50,996 bytes。在 Phase 10 引入原生機器碼解析與 Unicorn 差異測試後，捕獲到 4 位元組的計算偏差，特此嚴格更正：

- 指令機器碼：`08 e7 98 52` $\rightarrow$ `mov w8, #0xc738`
- 十六進位數值：`0xC738`
- 十進位精確換算：
  $$0\text{xC738} = (12 \times 4096) + (7 \times 256) + (3 \times 16) + 8 = 49152 + 1792 + 48 + 8 = \mathbf{51,000}$$
- **結構意義**：
  $$\frac{51,000\text{ bytes}}{1,000\text{ bytes/unit}} = \mathbf{51\text{ 單位槽位}}$$
  精確對應《貓咪大戰爭》官方規範中：1 個主城槽位 + 最大 50 隻戰場部署貓咪/敵人的上限！

---

## 2. HP 讀寫函式逐步定址計算 (Step-by-Step Address Proof)

以 `Battle_GetUnitHP` (`0x0095987c`) 與 `Battle_SetUnitHP` (`0x009598bc`) 為例，展示暫存器資料流與有效記憶體位址（Effective Address）的推導過程：

### (1) 指令序列與暫存器狀態表 (Getter @ `0x0095987c`)
```armasm
0x0095987c: stp  x29, x30, [sp, #-0x20]! ; 保存幀指標與返回位址
0x00959880: stp  x20, x19, [sp, #0x10]   ; 保存被呼叫者保存暫存器
0x00959884: mov  x29, sp
0x00959888: mov  w19, w1                 ; 【暫存器來源】w19 = unit_index (引數2)
0x0095988c: mov  w20, w0                 ; 【暫存器來源】w20 = team (引數1: 0=貓咪, 1=敵人)
0x00959890: bl   #0x6fd748               ; 呼叫單例指標取得函式，回傳 x0 = Battlefield_Base
0x00959894: mov  w8, #0xc738             ; w8 = 51000 (陣營跨度)
0x00959898: mov  w9, #0x3e8              ; w9 = 1000  (單位跨度)
0x0095989c: smaddl x8, w20, w8, x0       ; x8 = x0 + (signed(w20) * 51000)
0x009598a0: smaddl x8, w19, w9, x8       ; x8 = x8 + (signed(w19) * 1000)
0x009598a4: mov  w9, #0x3960             ; w9 低 16 位元 = 0x3960
0x009598a8: movk w9, #8, lsl #16         ; w9 高 16 位元 = 0x0008 -> w9 = 0x83960
0x009598ac: ldr  w0, [x8, x9]            ; 【核心讀取】自 (x8 + 0x83960) 載入 32 位元整數至 w0
0x009598b0: ldp  x20, x19, [sp, #0x10]   ; 恢復暫存器
0x009598b4: ldp  x29, x30, [sp], #0x20
0x009598b8: ret
```

### (2) 逐步位址推導
1. **單例基底取得**：
   - 呼叫 `0x6fd748`，其指令為 `adrp x0, #0xb0e000; add x0, x0, #0xf20; ret`。
   - 回傳 `x0 = 0x00b0ef20`，此位址位於 ELF `LOAD[3]` 之 `.bss` 全域未初始化資料段（大小達 4.6 MB）。
   - 定義 $\text{Battlefield\_Base} = \texttt{0x00b0ef20}$。
2. **陣營偏移量計算**：
   - `smaddl x8, w20, w8, x0` 執行：
     $$\text{Team\_Offset} = \text{team} \times 51,000$$
     $$\text{Addr}_1 = \text{Battlefield\_Base} + \text{Team\_Offset}$$
3. **單位槽位偏移量計算**：
   - `smaddl x8, w19, w9, x8` 執行：
     $$\text{Unit\_Offset} = \text{unit\_index} \times 1,000$$
     $$\text{Addr}_2 = \text{Addr}_1 + \text{Unit\_Offset} = \text{Battlefield\_Base} + (\text{team} \times 51,000) + (\text{unit\_index} \times 1,000)$$
4. **欄位有效位址（Effective Address, EA）**：
   - `ldr w0, [x8, x9]` 採用暫存器偏移定址，$\text{EA} = x8 + x9$：
     $$\mathbf{EA(HP)} = \text{Battlefield\_Base} + (\text{team} \times 51,000) + (\text{unit\_index} \times 1,000) + \mathbf{0x83960}$$

---

## 3. Battlefield Base 與 Unit Base 物件結構關係

針對「HP offset 到底相對哪個基底指標？兩者是否為同一物件？」的疑問，形式化證明如下：

```text
Battlefield Singleton (全域戰場單例，基底: Battlefield_Base @ 0x00b0ef20)
│
├── [0x00000 ~ 0x838FF] 戰場全域環境資料 (關卡設定、背景、城池屬性、砲台狀態等約 538 KB)
│
└── [0x83900 開始] 戰鬥實體陣列區段 (Unit Entity Storage Section)
      │
      ├── Team[0]: 貓咪友軍陣營區間 (長度: 51,000 bytes)
      │     ├── Unit[00] (長度: 1,000 bytes) -> 我方城堡實體
      │     ├── Unit[01] (長度: 1,000 bytes) -> 貓咪第 1 號槽位
      │     └── Unit[50] (長度: 1,000 bytes) -> 貓咪第 50 號槽位
      │
      └── Team[1]: 敵軍陣營區間 (長度: 51,000 bytes)
            ├── Unit[00] (長度: 1,000 bytes) -> 敵方城堡實體
            ├── Unit[01] (長度: 1,000 bytes) -> 敵人第 1 號槽位
            └── Unit[50] (長度: 1,000 bytes) -> 敵人第 50 號槽位
```

### 結構性結論：
1. **單一扁平緩衝區**：戰場管理器與實體單位並非分散於多個動態配置的小型 `new` 物件，而是整合在一個連續配置的靜態扁平記憶體物件中。
2. **Unit Base 定義**：
   若定義單一單位的起始基底為：
   $$\text{Unit\_Base} = \text{Battlefield\_Base} + \mathbf{0x83900} + (\text{team} \times 51,000) + (\text{unit\_index} \times 1,000)$$
   則各實體屬性在 1,000 位元組單位槽位內之**相對偏移量（Relative Struct Offset）**為：
   - `+0x024`：Unit ID (`0x83924 - 0x83900 = 0x24`)
   - `+0x050`：Position X (`0x83950 - 0x83900 = 0x50`)
   - `+0x060`：**Current HP** (`0x83960 - 0x83900 = 0x60`)
   - `+0x064`：Is Alive (`0x83964 - 0x83900 = 0x64`)
   - `+0x108`：Target Reference (`0x83a08 - 0x83900 = 0x108`)
   - `+0x10C`：Attack State (`0x83a0c - 0x83900 = 0x10C`)
   - `+0x1C8`：Attack Timer (`0x83ac8 - 0x83900 = 0x1C8`)
   - `+0x1CC`：Attack Interval (`0x83acc - 0x83900 = 0x1CC`)
   - `+0x1D4`：Knockback State (`0x83ad4 - 0x83900 = 0x1D4`)
   - `+0x1DC`：Speed (`0x83adc - 0x83900 = 0x1DC`)
   - `+0x200`：Status Slow (`0x83b00 - 0x83900 = 0x200`)
   - `+0x204`：Status Freeze (`0x83b04 - 0x83900 = 0x204`)
   - `+0x208`：Status Weaken (`0x83b08 - 0x83900 = 0x208`)
   - `+0x20C`：Status Barrier (`0x83b0c - 0x83900 = 0x20C`)
   - `+0x3C8`：Castle HP (`0x83cc8 - 0x83900 = 0x3C8` = 968)
   - `+0x3CC`：Castle Shield (`0x83ccc - 0x83900 = 0x3CC` = 972)
3. **槽位容納驗證**：所有欄位最大相對偏移為 `972 bytes < 1,000 bytes`，100% 完整容納於單一單位槽位內。

---

## 4. 索引邊界、記憶體重疊與讀寫寬度審計

| 審核維度 | 二進位實證依據 | 形式化分析與邊界判定 |
|---|---|---|
| **有效索引範圍** | `0x00959898: mov w9, #0x3e8`<br>`0x00959894: mov w8, #0xc738` | $\text{單位數上限} = 51,000 / 1,000 = 51$。<br>合法索引範圍為：$\mathbf{0 \le \text{unit\_index} \le 50}$。<br>其中索引 0 為城堡/主堡，1 ~ 50 為最大 50 隻戰場實體。 |
| **陣營重疊檢驗** | $\text{Team}_0: [\text{Base}, \text{Base} + 51,000)$<br>$\text{Team}_1: [\text{Base} + 51,000, \text{Base} + 102,000)$ | 陣營 0 的終點為 $\text{Base} + 50,999$，陣營 1 的起點為 $\text{Base} + 51,000$。<br>兩者交集為空集（$\text{Team}_0 \cap \text{Team}_1 = \emptyset$），**絕對無任何記憶體重疊**。 |
| **讀寫位元組寬度** | `0x009598ac: ldr w0, [x8, x9]`<br>`0x009598f4: str w19, [x8, x9]` | 指令使用 32 位元通用暫存器 `w0`、`w19`、`w21`。<br>全域 34 組 Getter/Setter 無一使用 `ldrb` 或 `ldrh`。<br>所有屬性讀寫寬度均嚴格為 **4 位元組 (32-bit Word)**。 |
| **邊界安全檢查** | `Battle_GetUnitHP` 無 `cmp / b.hi` 分支 | 二進位內部為求高頻迴圈性能，Getter/Setter 本身**省略了邊界檢查**，完全依賴外部生成管理器保證 $0 \le \text{unit\_index} \le 50$。若索引傳入 51，將跨界存取至 Team 1 實體。 |
