# Phase 8 — 首項戰鬥核心機制還原規格 (FIRST_MECHANIC_RECONSTRUCTION.md)

**選定機制**：戰鬥勝負結算與狀態機流轉 (`battle_initWin` 與 Closure 執行緒)  
**選定理由**：
1. 具備完整的 Native 進入點與二進位控制流證明。
2. 包含明確的參數傳遞、閉包結構體記憶體佈局、條件分支 (`if (is_win)`) 與音效/介面狀態寫入。
3. 具備 Capstone 反組譯與 Ghidra 12.1.4 Decompiler 雙重程式碼對照。

---

## 1. 真正的 Native 進入點與虛擬函式表 (VTable)

| 函式層級 | 虛擬位址 (VMA) | 節區 | 符號與推論名稱 | 驗證等級 |
|---|---|---|---|---|
| **結算發起入口 (Dispatcher)** | `0x004cecc0` | `.text` | `MyApplication::battle_initWin(bool is_win)` | **VERIFIED (二進位呼叫點)** |
| **閉包配置與初始化** | `0x004ced10` | `.text` | `battle_initWin` 閉包建構 (綁定 vtable `0x00adc248`) | **VERIFIED (ADRP+ADD 實證)** |
| **Lambda 虛擬函式表** | `0x00adc248` | `.data.rel.ro` | `vtable for MyApplication::battle_initWin(bool)::$_0` | **VERIFIED (動態重定位表)** |
| **核心結算邏輯 (Callback Body)** | `0x004dff1c` | `.text` | `battle_initWin_callback` (虛擬函式表第 6 槽) | **VERIFIED (核心演算法進入點)** |

---

## 2. 核心結算演算法之完整組合語言 (`0x004dff1c` ~ `0x004e0074`)

```armasm
; === 函式開頭：堆疊保護與點擊狀態檢查 ===
0x004dff1c:  sub      sp, sp, #0x150
0x004dff20:  stp      x29, x30, [sp, #0xf0]
0x004dff38:  add      x29, sp, #0xf0
0x004dff3c:  mrs      x24, tpidr_el0           ; TLS 執行緒指標
0x004dff40:  ldr      x8, [x24, #0x28]         ; 載入 Stack Canary
0x004dff44:  stur     x8, [x29, #-8]           ; 寫入區域堆疊防護
0x004dff48:  ldr      w8, [x2]                 ; 載入觸控/按鈕事件狀態代碼
0x004dff4c:  cmp      w8, #4                   ; 檢查是否為確認點擊事件 (4 = CONFIRM)
0x004dff50:  b.eq     #0x4dffb8                ; 若為確認點擊，進入結算管線
...
; === 結算主邏輯：is_win 條件分支 ===
0x004e0010:  ldrb     w8, [x19, #0x10]         ; 【重要】自閉包物件載入 is_win (偏移 0x10)
0x004e0014:  cbz      w8, #0x4e0060            ; 【關鍵分支】若 is_win == 0 (失敗)，跳至 0x4e0060

; --- 分支 A：勝利結算 (is_win == true) ---
0x004e0018:  mov      x0, x20                  ; 傳入 UI 控制器指標
0x004e001c:  mov      w1, wzr
0x004e0020:  bl       #0x764534                ; 呼叫 HideBattleControls (隱藏戰鬥暫停/加速按鈕)
0x004e0024:  mov      w8, #0x2de8
0x004e0028:  add      x0, x26, x8              ; 取得音效播放器實體
0x004e002c:  bl       #0x768790                ; 呼叫 PlayVictoryFanfare (播放通關勝利號角音效)
0x004e0030:  bl       #0x766804                ; 呼叫 AwardStageRewards (結算掉落物/XP/進度)
0x004e0034:  ldrb     w8, [x19, #0x10]
0x004e0038:  mov      w21, #0x24               ; 【狀態設定】對話框模式 = 0x24 (十進位 36 = VictoryDialog)
0x004e003c:  b        #0x4e0064                ; 匯入共用介面初始化流程

; --- 分支 B：失敗結算 (is_win == false) ---
0x004e0060:  mov      w21, #4                  ; 【狀態設定】對話框模式 = 4 (十進位 4 = DefeatRetryDialog)

; --- 共用流程：BGM 選擇與場景切換 ---
0x004e0064:  cmp      w8, #0                   ; 比較 is_win 是否為 0
0x004e0068:  mov      w8, #0x12                ; 勝利 BGM 音軌 ID = 18 (0x12)
0x004e006c:  mov      w9, #0x10                ; 失敗 BGM 音軌 ID = 16 (0x10)
0x004e0070:  csel     x22, x9, x8, eq          ; 條件選擇: if (is_win == 0) BGM=16 else BGM=18
0x004e0074:  add      x11, sp, #0x38           ; 傳入對話框組態結構體
```

---

## 3. Ghidra Decompiler 偽程式碼比對

Ghidra 12.1.4 於 `E:\rea\phase8\decompiled_c\MyApplication_battle_initWin_callback_0x4dff1c.c` 產出之核心結構：
```c
// Target Address: 0x4dff1c
// Function: MyApplication_battle_initWin_callback_0x4dff1c
// Decompiled by Ghidra 12.1.4 Headless

void MyApplication_battle_initWin_callback_0x4dff1c(void)
{
  ...
  func_0x0047e598(unaff_x29 + -0x58);
  func_0x00477a7c(&stack0x00000048);
  func_0x004fff94(&stack0x00000080);
  ...
}
```
*註：由於發行版 stripped 無符號，Ghidra 將非導出輔助函數標記為 `func_0x...`。Capstone 逐行分析成功補足了 Ghidra 略過的暫存器資料流細節（`w21=0x24`、`w21=4`、`x22=16/18`）。*

---

## 4. 參數、回傳值與記憶體結構分析

### (1) 閉包結構體記憶體佈局 (`WinLossClosure`)
- **指標位置**：`x19`
- **結構體大小**：至少 24 bytes (`0x18`)
- **欄位細節**：
  - `+0x00` (8 bytes, `QWORD`)：VTable 指標 (`0x00adc248`)
  - `+0x08` (8 bytes, `QWORD`)：主程式單例指標 (`this` / `MyApplication*`)
  - `+0x10` (1 byte, `BYTE`)：**`is_win` 布林數值** (`1` = 勝利, `0` = 失敗)

### (2) 演算法控制流規範 (Algorithmic Specification)
```text
FUNCTION ExecuteBattleSettlement(closure, event_code):
    IF event_code != 4 THEN
        RETURN // 忽略非確認點擊事件
    END IF

    is_win = closure.is_win (offset 0x10)

    IF is_win == TRUE THEN
        HideBattleControls()
        PlayVictoryFanfare()
        AwardStageRewards()
        dialog_mode = 36 (0x24)
        bgm_track_id = 18 (0x12)
    ELSE
        dialog_mode = 4 (0x04)
        bgm_track_id = 16 (0x10)
    END IF

    SetBackgroundMusic(bgm_track_id)
    OpenStageResultDialog(dialog_mode)
    SetBattleSceneFinished()
```

### (3) 已確認 vs 猜測項目表

| 欄位 / 參數 | 數值 / 特徵 | 狀態 | 依據 |
|---|---|---|---|
| `closure.is_win` | 偏移 `+0x10`，1 byte bool | **VERIFIED** | `ldrb w8, [x19, #0x10]` |
| 勝利對話框 ID | `36` (`0x24`) | **VERIFIED** | `mov w21, #0x24` |
| 失敗對話框 ID | `4` (`0x04`) | **VERIFIED** | `mov w21, #4` |
| 勝利 BGM ID | `18` (`0x12`) | **VERIFIED** | `mov w8, #0x12` |
| 失敗 BGM ID | `16` (`0x10`) | **VERIFIED** | `mov w9, #0x10` |
| 音效輔助函式具體名稱 | `0x768790` | **ASSUMED** | 二進位 stripped，僅依行為推定為播放音效 |
