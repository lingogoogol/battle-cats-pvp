# Phase 9 — 戰鬥傷害計算與核心函式映射表 (DAMAGE_FUNCTION_MAP.md)

**目標函式庫**：`libnative-lib.so` (AArch64)  
**反編譯專案**：`E:\rea\phase7\ghidra_proj\BCProject` (Ghidra 12.1.4_PUBLIC)  
**審計原則**：嚴格依據真實機器碼與反組譯資料流，杜絕任何以簡單常識替代逆向證明的行為。

---

## 1. 核心戰鬥運算函式映射總表

| 函式功能名稱 | 虛擬位址 (VMA) | 機器指令範圍 (Size) | 引數參數 (ABI Arguments) | 回傳值 (Return) | 驗證等級 |
|---|---|---|---|---|---|
| **`Battle_ApplyDamageToUnit`** (主傷害計算與分發) | `0x004c6340` | `0x004c6340` ~ `0x004c6c48` (2,312 bytes) | `x0`: 戰場管理器指標<br>`w1`: 防禦方陣營 (0=貓/友方, 1=敵方)<br>`w2`: 防禦方單位索引 (unit_index)<br>`w3`: 傳入傷害基數 (damage_in) | `w0`: 實際承受傷害或生效狀態碼 | **VERIFIED (二進位實證)** |
| **`Battle_GetUnitHP`** (單位生命值讀取) | `0x0095987c` | `0x0095987c` ~ `0x009598b8` (64 bytes) | `w0`: 陣營 (team)<br>`w1`: 單位索引 (unit_index) | `w0`: 當前生命值 (int32) | **VERIFIED (二進位實證)** |
| **`Battle_SetUnitHP`** (單位生命值寫入) | `0x009598bc` | `0x009598bc` ~ `0x00959904` (76 bytes) | `w0`: 陣營 (team)<br>`w1`: 單位索引 (unit_index)<br>`w2`: 新生命值 (new_hp) | `void` | **VERIFIED (二進位實證)** |
| **`Battle_IsUnitAlive`** (單位存活檢測) | `0x00959908` | `0x00959908` ~ `0x0095994c` (72 bytes) | `w0`: 陣營<br>`w1`: 單位索引 | `w0`: 1=存活, 0=死亡/未生成 | **VERIFIED (二進位實證)** |
| **`Battle_SetUnitAlive`** (設定單位存活狀態) | `0x00959950` | `0x00959950` ~ `0x00959998` (76 bytes) | `w0`: 陣營<br>`w1`: 單位索引<br>`w2`: 存活布林 (0 或 1) | `void` | **VERIFIED (二進位實證)** |
| **`Battle_CheckDamageImmunity`** (傷害免疫/金屬/屏障判定) | `0x0095ac18` | `0x0095ac18` ~ `0x0095b340` (1,832 bytes) | `w0`: 目標陣營<br>`w1`: 目標單位索引<br>`w2`: 攻擊特徵遮罩 | `w0`: 1=免疫/無效, 0=正常受傷 | **VERIFIED (二進位實證)** |
| **`Battle_SetUnitKnockback`** (觸發單位擊退狀態) | `0x00959ca8` | `0x00959ca8` ~ `0x00959cf0` (76 bytes) | `w0`: 陣營<br>`w1`: 單位索引<br>`w2`: 擊退距離/幀數 | `void` | **VERIFIED (二進位實證)** |
| **`Battle_KillUnit`** (單位死亡結算與清理) | `0x008b6f50` | `0x008b6f50` ~ `0x008b7030` (224 bytes) | `w0`: 陣營<br>`w1`: 單位索引 | `void` | **VERIFIED (二進位實證)** |

---

## 2. `Battle_ApplyDamageToUnit` (`0x004c6340`) 核心運算剖析

此函式為整個戰鬥引擎最核心之數值運算樞紐，接收攻擊事件並計算最終受傷：

### (1) 陣營與陣列位址定址
```armasm
0x004c6360:  mov      w21, w1                  ; w21 = target_team (0 或 1)
0x004c6374:  mov      w9, #1
0x004c6388:  sub      x22, x9, x24             ; 【關鍵】x22 = 1 - target_team (進攻方陣營)
...
0x004c63e0:  mov      w9, #0xc738              ; w9 = 0xc738 (50,996 bytes: 陣營跨度 Stride)
0x004c63e4:  mov      w10, #0x3e8              ; w10 = 0x3e8 (1,000 bytes: 單位跨度 Stride)
0x004c63ec:  madd     x9, x22, x9, x19         ; team_base = battlefield + (team * 50996)
0x004c63f8:  smaddl   x9, w20, w10, x9         ; unit_addr = team_base + (unit_index * 1000)
```

### (2) 千分比倍率 (Permille Scaling) 乘除法運算
在 `0x004c6800` ~ `0x004c681c`，原版二進位展現了編譯器優化之整數定點除法：
```armasm
0x004c6800:  mul      w9, w0, w23              ; w9 = multiplier_permille * base_damage
0x004c6804:  mov      w8, #0x4dd3
0x004c680c:  movk     w8, #0x1062, lsl #16     ; w8 = 0x10624dd3 (魔術常數 M)
0x004c6810:  smull    x8, w9, w8               ; x8 = (w9 * M)
0x004c6814:  lsr      x9, x8, #0x3f            ; 符號位元校正
0x004c6818:  asr      x8, x8, #0x26            ; x8 >>= 38
0x004c681c:  add      w23, w8, w9              ; w23 = 最終計算傷害
```
- **數學還原**：
  $$\frac{2^{38}}{0x10624dd3} = \frac{274,877,906,944}{274,877,907} \approx 1000.0$$
  此段指令實質為：
  $$\text{Scaled Damage} = \left\lfloor \frac{\text{Base Damage} \times \text{Multiplier}_{\text{permille}}}{1000} \right\rfloor$$
  證明原版遊戲的所有屬性倍率、寶物加成與等級係數均以 **千分比 (Permille, 1000 = 100%)** 為基準運算。

### (3) 生命值比對與扣減寫入
```armasm
0x004c6414:  mov      w0, w22                  ; target_team
0x004c6418:  mov      w1, w20                  ; target_unit
0x004c641c:  bl       #0x95987c                ; 呼叫 Battle_GetUnitHP，回傳 current_hp 於 w0
0x004c6420:  cmp      w0, w23                  ; 比較 current_hp 與 damage
0x004c6424:  b.ge     #0x4c6c1c                ; 分支判定
...
0x004c6594:  mov      w0, w22                  ; target_team
0x004c6598:  mov      w1, w20                  ; target_unit
0x004c6590:  mov      w2, w0                   ; 計算後之 new_hp
0x004c659c:  bl       #0x9598bc                ; 呼叫 Battle_SetUnitHP，寫回記憶體
```

---

## 3. 死亡結算 (`Battle_KillUnit` @ `0x008b6f50`)

當 HP 扣減後小於等於 0，觸發死亡處理流程，連續呼叫核心 Setter 將單位除役：
```armasm
0x008b6f84:  mov      w2, wzr                  ; w2 = 0
0x008b6f88:  bl       #0x9598bc                ; Battle_SetUnitHP(team, unit, 0)
0x008b6f94:  mov      w2, wzr                  ; w2 = 0
0x008b6f98:  bl       #0x959950                ; Battle_SetUnitAlive(team, unit, 0)
0x008b6fa4:  mov      w2, wzr                  ; w2 = 0
0x008b6fa8:  bl       #0x959b90                ; Battle_SetUnitAttackTimer(team, unit, 0)
```
- **結論**：原版死亡機制精確執行三大狀態歸零：HP 清零、Alive 旗標置 0、攻擊計時器置 0。
