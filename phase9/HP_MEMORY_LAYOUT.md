# Phase 9 — 戰鬥實體與生命值記憶體佈局 (HP_MEMORY_LAYOUT.md)

**分析目標**：還原《貓咪大戰爭》二進位核心中戰場陣列、單位實體結構與生命值 (HP) 記憶體欄位佈局。  
**參考二進位**：`libnative-lib.so` (AArch64)  
**反組譯實證位址**：`0x00959800` ~ `0x0095a200` 及 `0x008b6f28`

---

## 1. 戰場階層定址模型 (Battlefield Addressing Model)

在二進位中，戰場管理器採用雙重維度之扁平化陣列結構（Flat 2D Array），由全域管理器指標基底定址：

```text
Battlefield_Base (由 0x6fd748 回傳於 x0)
  ├── Team[0]: 我方/貓咪陣營 (偏移 +0x00000)
  │     ├── Unit[0] (槽位長度 1,000 bytes)
  │     ├── Unit[1]
  │     └── ... (最大支援 50 個實體槽位)
  └── Team[1]: 敵方/敵軍陣營 (偏移 +0x0C738 = 50,996 bytes)
        ├── Unit[0]
        ├── Unit[1]
        └── ...
```

### 定址公式組合語言實證 (`0x00959894` ~ `0x009598a0`)
```armasm
0x00959890:  bl       #0x6fd748                ; x0 = Battlefield_Base
0x00959894:  mov      w8, #0xc738             ; 陣營跨度: 50,996 bytes
0x00959898:  mov      w9, #0x3e8              ; 單位跨度: 1,000 bytes
0x0095989c:  smaddl   x8, w20, w8, x0         ; x8 = x0 + (team * 50996)
0x009598a0:  smaddl   x8, w19, w9, x8         ; x8 = x8 + (unit_index * 1000)
```
$$\text{Unit Address} = \text{Battlefield\_Base} + (\text{team} \times 50996) + (\text{unit\_index} \times 1000)$$

---

## 2. 單位實體欄位記憶體佈局表 (Unit Memory Layout)

在計算出單位基底位址後，原版以高階偏移量存取各成員欄位：

| 欄位絕對偏移 (Field Offset) | 相對實體基底 (Relative) | 欄位名稱 (Field Name) | 資料型別 (Type) | 存取函式 (Getter / Setter) | 實證組合語言 |
|---|---|---|---|---|---|
| `+0x00083924` | `+0x1C` | **`Unit_ID`** | `int32` | `0x0095a194` (Get) | `ldr w0, [x8, x9]` |
| `+0x00083950` | `+0x48` | **`Position_X`** (座標) | `int32` (定點數) | `0x00959800` (Get)<br>`0x00959830` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| **`+0x00083960`** | **`+0x58`** | **`Current_HP`** (生命值) | **`int32` (4 bytes)** | **`0x0095987c` (Get)<br>`0x009598bc` (Set)** | **`ldr w0, [x8, x9]`<br>`str w19, [x8, x9]`** |
| `+0x00083964` | `+0x5C` | **`Is_Alive`** (存活旗標) | `uint8` / `int32` | `0x00959908` (Get)<br>`0x00959950` (Set) | `cset w0, ne`<br>`str w21, [x8, x9]` |
| `+0x00083A08` | `+0x100` | **`Target_Ref`** (目標索引) | `int32` | `0x0095999c` (Get)<br>`0x00959a04` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083A0C` | `+0x104` | **`Attack_State`** (攻擊狀態) | `int32` (Enum) | `0x00959a70` (Get)<br>`0x00959ab0` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083AC8` | `+0x1C0` | **`Attack_Timer`** (前搖計時) | `int32` | `0x00959b50` (Get)<br>`0x00959b90` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083ACC` | `+0x1C4` | **`Attack_Interval`** (TBA間隔) | `int32` | `0x00959bdc` (Get)<br>`0x00959c1c` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083AD4` | `+0x1CC` | **`Knockback_State`** (擊退距離) | `int32` | `0x00959c68` (Get)<br>`0x00959ca8` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083ADC` | `+0x1D4` | **`Speed`** (移動速度) | `int32` | `0x00959d48` (Get)<br>`0x00959d88` (Set) | `ldr w0, [x8, x9]`<br>`str w19, [x8, x9]` |
| `+0x00083B00` | `+0x1F8` | **`Status_Slow`** (減速狀態) | `int32` | `0x00959e28` (Get)<br>`0x00959e68` (Set) | `ldr w0, [x8, x9]` |
| `+0x00083B04` | `+0x1FC` | **`Status_Freeze`** (暫停/凍結) | `int32` | `0x00959eb4` (Get)<br>`0x00959ef4` (Set) | `ldr w0, [x8, x9]` |
| `+0x00083B08` | `+0x200` | **`Status_Weaken`** (攻擊力下降) | `int32` | `0x00959f40` (Get)<br>`0x00959f88` (Set) | `ldr w0, [x8, x9]` |
| `+0x00083B0C` | `+0x204` | **`Status_Barrier`** (護盾強度) | `int32` | `0x00959fd4` (Get)<br>`0x0095a01c` (Set) | `ldr w0, [x8, x9]` |
| `+0x00083CC8` | `+0x3C0` | **`Castle_HP`** (主堡生命值) | `int32` | `0x0095a068` (Get)<br>`0x0095a0a8` (Set) | `ldr w0, [x8, x9]` |

---

## 3. 生命值 (HP) 讀寫核心行為總結

1. **型別定義**：HP 欄位為標準 **32 位元有符號整數 (`int32_t`)**，位於單位基底之 `+0x00083960` 偏移。
2. **生命值讀取**：由 `0x0095987c` 執行 `ldr w0, [x8, x9]` 取得當前數值。
3. **生命值更新**：由 `0x009598bc` 執行 `str w19, [x8, x9]` 寫入新生命值。
4. **歸零狀態連動**：當 HP 降為 0 時，原版代碼必然連動修改 `+0x00083964` (Is_Alive) 與 `+0x00083AC8` (Attack_Timer) 為 0，並觸發實體消亡管線。
