# Phase 9 — Phase 8 疑點修正與證據重審報告 (PHASE8_CORRECTIONS.md)

**執行環境**：`E:\rea\phase9\`  
**分析目標**：`libnative-lib.so` (AArch64)  
**審計原則**：嚴格依據真實機器碼二進位指令，全面修正並釐清 Phase 8 的不精確或推測性結論。

---

## 1. 疑點一：Frame Pacing、Frame Rate 與 Simulation Tick Rate 之區分

在 Phase 8 中，報告將 `0x0098f094` 發現的 `0x3d088889` ($0.033333335\text{ 秒} \approx 1/30$) 宣稱為「固定 30 TPS 模擬步進已證實」。  
經 Phase 9 二進位重新審計，此結論存在觀念混淆，特此更正：

```armasm
0x0098f07c:  bl       #0xac3360            ; 取當前時間: now = steady_clock::now()
0x0098f080:  sub      x8, x0, x19          ; elapsed_ns = now - frame_start
0x0098f084:  scvtf    s0, x8               ; 轉為浮點數
0x0098f08c:  movk     w8, #0x4e6e, lsl #16 ; 1.0e9f
0x0098f094:  mov      w8, #0x8889
0x0098f098:  movk     w8, #0x3d08, lsl #16 ; 0x3d088889 (1.0f / 30.0f)
0x0098f09c:  fdiv     s0, s0, s1           ; elapsed_sec = elapsed_ns / 1.0e9f
0x0098f0a4:  fcmp     s0, s1               ; 比較: elapsed_sec 與 33.33ms
0x0098f0a8:  b.pl     #0x98f184            ; 若超時則跳過休眠 (防止累積掉幀)
0x0098f0b0:  fsub     s8, s1, s0           ; sleep_sec = (1.0f / 30.0f) - elapsed_sec
0x0098f0c0:  bl       #0xabe624            ; 呼叫 nanosleep
```

### 概念精確切分：
1. **Frame Pacing (休眠節流 / 幀率限制)**：
   上述代碼本質為 **Frame Pacing 節流器**。其目的在於當一幀的主迴圈（渲染 + 輸入 + 運算）在小於 33.33 毫秒內完成時，主動呼叫 `nanosleep` 休眠剩餘時間，避免手機 CPU/GPU 無限空轉耗電，將實體渲染幀率上限鎖定在 **30 FPS**。
2. **Simulation Tick Rate (模擬步進頻率 / TPS)**：
   戰鬥模擬邏輯是否嚴格以 $1\text{ Frame} = 1\text{ Tick}$ 步進，取決於各子系統內部狀態機計時器（Timer Counter）是否以整數幀 `1` 累加。
3. **更正聲明**：
   `0x0098f094` 的二進位實證確立的是 **「引擎主迴圈具備 30 FPS 硬編碼休眠節流」**，戰鬥模擬步進則是依賴於主迴圈每次調度時以整數幀驅動，兩者不可混為一談。

---

## 2. 疑點二：`0x004e0064` 指令與 `CSEL` NZCV 旗標來源驗證

在 Phase 8 的審查中，曾提出「`0x004e0070` 的 `CSEL` 使用 `eq` 條件，但前方的 `mov w21, #4` 不會修改 NZCV 旗標」的疑問。  
經 Phase 9 提取 `0x004e0010` 至 `0x004e0074` 的原始 Opcode 二進位位元組，精確還原 NZCV 旗標的產生機制：

### 原始機器碼與指令對照：
```armasm
0x004e0010:  68424039  ldrb     w8, [x19, #0x10]     ; 自閉包載入 is_win
0x004e0014:  68020034  cbz      w8, #0x4e0060        ; 若 is_win == 0，跳轉至 0x4e0060 (不修改 NZCV)
... (勝利路徑省略)
0x004e0034:  68424039  ldrb     w8, [x19, #0x10]     ; 勝利路徑重新載入 is_win
0x004e0038:  95048052  mov      w21, #0x24           ; w21 = 36
0x004e003c:  0a000014  b        #0x4e0064            ; 跳至 0x4e0064

; --- 失敗路徑匯入點 ---
0x004e0060:  95008052  mov      w21, #4              ; w21 = 4 (不修改 NZCV)

; --- 旗標產生核心指令 ---
0x004e0064:  1f010071  cmp      w8, #0               ; 【機器碼 1f 01 00 71】subs wzr, w8, #0
0x004e0068:  48028052  mov      w8, #0x12            ; w8 = 18 (不修改 NZCV)
0x004e006c:  09028052  mov      w9, #0x10            ; w9 = 16 (不修改 NZCV)
0x004e0070:  3601889a  csel     x22, x9, x8, eq      ; 依據 0x4e0064 的 cmp 結果選擇
```

### 旗標流轉嚴密證明：
1. `0x004e0064` 的真實機器碼為 `1f 01 00 71`，在 AArch64 中解碼為 **`cmp w8, #0`**（等價於 `subs wzr, w8, #0`）。此指令直接根據暫存器 `w8` 與 `0` 的差值設定 PSTATE 的 **NZCV 條件旗標**！
2. **失敗路徑**：由 `0x004e0014: cbz w8, #0x4e0060` 跳來時，`w8` 必為 `0`。到達 `0x4e0064: cmp w8, #0` 時，計算 $0 - 0 = 0$，設定 **$Z = 1$ (Zero Flag 置位)**。後續兩條 `mov` 指令不影響 PSTATE。因此在 `0x4e0070: csel x22, x9, x8, eq` 執行時，條件 `eq` ($Z == 1$) 成立，精確選中第一運算元 `x9`（`0x10` = 16）。
3. **勝利路徑**：由 `0x4e0034` 載入 `w8 = is_win`（非零，如 1）並跳至 `0x4e0064: cmp w8, #0`，計算 $1 - 0 = 1 \ne 0$，設定 **$Z = 0$**。在 `csel ..., eq` 執行時條件不成立，選中第二運算元 `x8`（`0x12` = 18）。
4. **結論**：該 `CSEL` 的條件旗標來源完全由 `0x004e0064` 的 `cmp w8, #0` 決定，邏輯 100% 閉環自洽。

---

## 3. 疑點三：`0x004e0030: bl #0x766804` 真實函式功能澄清

在 Phase 8 中，曾因該呼叫鄰近勝利音效播放函式 `0x768790`，而推測性命名為 `AwardStageRewards`。  
經 Phase 9 針對 `0x00766804` 的完整指令審查：
```armasm
0x00766804:  sub      sp, sp, #0x40
0x00766824:  str      w9, [x0, #0x60]          ; 設定 UI 物件狀態 flag = 2
0x00766828:  ldr      w8, [x0, #0xa8]          ; 載入元件 ID
0x00766834:  ldr      x0, [x0, #0x50]          ; 載入監聽器/回調委託指標 listener
0x0076683c:  cbz      x0, #0x766878            ; 若無 listener 則返回
0x00766840:  ldr      x8, [x0]                 ; 載入 listener vtable
0x00766850:  ldr      x8, [x8, #0x30]          ; 載入 vtable+0x30 虛擬函式
0x00766854:  blr      x8                       ; listener->OnAction(...)
```
- **真實功能**：此函式為標準的 **UI 元件事件分發器 (`UIElement::DispatchEvent`)**，負責將確認點擊事件分發給監聽者，並非直接在二進位中寫死關卡獎勵運算。
- **更正**：撤回「`0x766804` 是發放獎勵函式」之未證實推測，更正為 **「UI 事件通知虛擬調用」**。

---

## 4. 疑點四：`is_win` 資料來源與生命週期完整追蹤

- **建構與寫入位置**：`0x004ced10` ~ `0x004ced28` (`MyApplication::battle_initWin`)
  ```armasm
  0x004ced10:  adrp     x8, #0xadc000
  0x004ced14:  add      x10, x8, #0x248         ; 載入 Lambda VTable 指標
  0x004ced18:  ldr      x8, [sp, #0xf8]         ; 自外層戰鬥結束判斷函式傳入的 bool
  0x004ced1c:  stp      x10, x9, [sp, #0x1d0]   ; +0x00 = vtable, +0x08 = this
  0x004ced24:  and      x8, x8, #1              ; 強制位元遮罩為 0 或 1
  0x004ced28:  str      x8, [sp, #0x1e0]        ; +0x10 = is_win
  ```
- **讀取位置**：`0x004e0010` (`ldrb w8, [x19, #0x10]`)
- **生命週期**：由戰鬥場景核心於判定敵方城堡或我方城堡 HP 歸零後呼叫 `battle_initWin` 建立閉包，儲存於堆疊並傳入回調管線。
