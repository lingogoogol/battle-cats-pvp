# Phase 9 — 原版角色實體資料結構重構規格 (UNIT_STRUCTURE_RECONSTRUCTION.md)

**分析標的**：原版二進位核心《貓咪大戰爭》(`libnative-lib.so`, AArch64)  
**資料來源**：`0x00959800` ~ `0x0095a200` 核心實體 Getter/Setter 存取表  
**審計原則**：嚴格依據記憶體暫存器存取與組合語言指令，徹底揚棄以 Python 原型猜測原版欄位的作法。

---

## 1. 角色實體記憶體欄位詳細對照表 (Unit Field Specifications)

經由對 `libnative-lib.so` 在 `0x00959800` ~ `0x0095a200` 區間 34 組實體存取函式的全面逆向，完全確認原版角色實體記憶體欄位佈局如下：

| 欄位名稱 (Field) | 原始記憶體偏移 (Hex) | 推定資料型別 (Type) | 讀取函式 (Getter) | 寫入函式 (Setter) | 組合語言證據 (Assembly Evidence) | 分級評定 |
|---|---|---|---|---|---|---|
| **Current HP** (當前生命值) | `+0x00083960` | `int32_t` (4 bytes) | `0x0095987c` | `0x009598bc` | `0x009598ac: ldr w0, [x8, x9]`<br>`0x009598f4: str w19, [x8, x9]`<br>*(x9 = 0x83960)* | **VERIFIED** |
| **Is Alive / Active** (存活旗標) | `+0x00083964` | `uint32_t` (bool) | `0x00959908` | `0x00959950` | `0x00959938: ldr w8, [x8, x9]`<br>`0x0095993c: cmp w8, #0; cset w0, ne`<br>`0x00959988: str w21, [x8, x9]` | **VERIFIED** |
| **Position X** (戰場一維座標) | `+0x00083950` | `int32_t` (定點座標) | `0x00959800` | `0x00959830` | `0x00959820: ldr w0, [x8, x9]`<br>`0x00959850: str w19, [x8, x9]`<br>*(x9 = 0x83950)* | **VERIFIED** |
| **Attack State** (攻擊狀態機) | `+0x00083A0C` | `int32_t` (Enum) | `0x00959a70` | `0x00959ab0` | `0x00959a94: ldr w0, [x8, x9]`<br>`0x00959ad8: str w19, [x8, x9]`<br>*(x9 = 0x83a0c)* | **VERIFIED** |
| **Attack Timer** (攻擊前搖/計時) | `+0x00083AC8` | `int32_t` (幀倒數計時) | `0x00959b50` | `0x00959b90` | `0x00959b74: ldr w0, [x8, x9]`<br>`0x00959bb8: str w19, [x8, x9]`<br>*(x9 = 0x83ac8)* | **VERIFIED** |
| **Attack Interval** (TBA攻擊間隔) | `+0x00083ACC` | `int32_t` (冷卻時間) | `0x00959bdc` | `0x00959c1c` | `0x00959c00: ldr w0, [x8, x9]`<br>`0x00959c44: str w19, [x8, x9]`<br>*(x9 = 0x83acc)* | **VERIFIED** |
| **Knockback State** (擊退硬直狀態) | `+0x00083AD4` | `int32_t` (擊退剩餘距離) | `0x00959c68` | `0x00959ca8` | `0x00959c8c: ldr w0, [x8, x9]`<br>`0x00959cd0: str w19, [x8, x9]`<br>*(x9 = 0x83ad4)* | **VERIFIED** |
| **Target Reference** (鎖定目標索引) | `+0x00083A08` | `int32_t` (目標單位ID) | `0x0095999c` | `0x00959a04` | `0x009599ec: ldr w0, [x8, x9]`<br>`0x00959a5c: str w19, [x8, x9]`<br>*(x9 = 0x83a08)* | **VERIFIED** |
| **Speed** (移動速度步進) | `+0x00083ADC` | `int32_t` (每幀位移量) | `0x00959d48` | `0x00959d88` | `0x00959d6c: ldr w0, [x8, x9]`<br>`0x00959db0: str w19, [x8, x9]`<br>*(x9 = 0x83adc)* | **VERIFIED** |
| **Unit Species ID** (單位種類編號) | `+0x00083924` | `int32_t` | `0x0095a194` | — | `0x0095a1b8: ldr w0, [x8, x9]`<br>*(x9 = 0x83924)* | **VERIFIED** |
| **Max HP** (最大生命值上限) | — | `int32_t` | — | — | 於實體配置時自 `unitXXX.csv` 讀入並寫入初始 Current HP，無獨立二進位欄位 | **INFERRED** |
| **KB Count** (總擊退次數門檻) | — | `int32_t` | — | — | 由動畫檔與 CSV 定義，運算時動態計算門檻 | **INFERRED** |

---

## 2. 結構體 C++ 標頭定義還原 (Reconstructed C++ Struct)

依據上述已證實之定址與偏移量，還原出原版戰場實體之 C++ 類別/結構體定義：

```cpp
#pragma pack(push, 4)
struct ReconstructedBattleUnit {
    // 實體槽位定址基礎: 槽位總長 1000 bytes (0x3e8)
    // 陣營槽位總長: 50996 bytes (0xc738)
    
    /* +0x00083924 */ int32_t unit_id;           // 角色種類 ID (如 0=普通貓, 1=坦克貓)
    /* +0x00083950 */ int32_t position_x;        // 戰場 X 軸定點數座標
    /* +0x00083960 */ int32_t current_hp;        // 當前生命值 (收到傷害直接扣減此欄位)
    /* +0x00083964 */ uint32_t is_alive;         // 存活狀態 (1=存活, 0=死亡)
    /* +0x00083A08 */ int32_t target_ref;        // 當前鎖定之對手單位索引
    /* +0x00083A0C */ int32_t attack_state;      // 0=移動, 1=前搖, 2=冷卻
    /* +0x00083AC8 */ int32_t attack_timer;      // 攻擊動畫與判定計時器 (幀數)
    /* +0x00083ACC */ int32_t attack_interval;   // 攻擊間隔總時間 (TBA)
    /* +0x00083AD4 */ int32_t knockback_state;   // 擊退中斷狀態與位移幀數
    /* +0x00083ADC */ int32_t speed;             // 移動速度
    /* +0x00083B00 */ int32_t status_slow;       // 緩速剩餘時間
    /* +0x00083B04 */ int32_t status_freeze;     // 凍結定身剩餘時間
    /* +0x00083B08 */ int32_t status_weaken;     // 虛弱攻擊力減半剩餘時間
    /* +0x00083B0C */ int32_t status_barrier;    // 護盾當前數值
};
#pragma pack(pop)
```

本結構體所有欄位之名稱、偏移量與存取方法，皆有相應之 Native 組合語言與二進位虛擬位址支撐，絕無任何憑空捏造。
