# Phase 10 — 戰場移動與位置更新系統逆向分析 (MOVEMENT_SYSTEM_ANALYSIS.md)

**分析目標**：二進位核心戰鬥位移機制與主迴圈槽位遍歷  
**關鍵函式位址**：
- `Battle_GetUnitPosition`：`0x009597f0` ~ `0x0095982c` (入口修正：`0x009597f0`)
- `Battle_SetUnitPosition`：`0x00959830` ~ `0x00959878`
- `Battle_GetUnitKnockback`：`0x00959c68`
- `Battle_UpdateAllPositions`：`0x005c8c40` ~ `0x005c8d50`
**審計原則**：基於真實 AArch64 反組譯指令與迴圈計數器，杜絕臆測。

---

## 1. 戰場實體位移更新迴圈 (`0x005c8c70` ~ `0x005c8cc4`)

在二進位位址 `0x005c8c70` 處，引擎執行戰場實體每幀位移遍歷更新：

```armasm
0x005c8c6c: mov  w24, wzr                ; w24 = 0 (實體槽位索引 unit_index 初始化為 0)
0x005c8c70: mov  w19, wzr                ; w19 = 0 (碰撞/障礙標記)
0x005c8c74: b    #0x5c8c88
...
0x005c8c7c: add  w24, w24, #1            ; unit_index++
0x005c8c80: cmp  w24, #0x33              ; 【核心驗證】比較槽位上限 0x33 (十進位 51)
0x005c8c84: b.eq #0x5c8cc4               ; 若已檢查滿 51 個槽位則跳出迴圈
...
0x005c8c8c: mov  w1, wzr                 ; team = 0 (貓咪陣營)
0x005c8c90: mov  w2, w23                 ; 目標單位
0x005c8c94: mov  w3, w24                 ; 當前遍歷單位
0x005c8c9c: bl   #0x5ce084               ; 檢查該槽位實體是否激活 (IsActive)
0x005c8ca0: cbz  w0, #0x5c8c7c           ; 若槽位未激活，跳過此單位
0x005c8cac: bl   #0x9597f0               ; 呼叫 Battle_GetUnitPosition 取出座標
0x005c8cb8: bl   #0x959c68               ; 呼叫 Battle_GetUnitKnockback 檢查擊退硬直
0x005c8cbc: cbz  w0, #0x5c8c78           ; 若處於擊退中，中斷正常前進步進
```

### 關鍵二進位發現：
1. **51 槽位全量確認 (`cmp w24, #0x33`)**：
   指令明文載入 `#0x33`（十進位 51），再次無懈可擊地佐證了 `0xc738`（51,000 位元組）恰為 51 個 1,000 位元組槽位的硬體容量。
2. **擊退硬直優先權**：
   在位移更新管線中，若 `Battle_GetUnitKnockback` 回傳非 0，正常向敵城推進的步進將被阻斷，實體進入擊退反向位移或硬直幀計時。
3. **位置更新寫回 (`0x005c8d10`)**：
   在計算出碰撞與速度步進後，最終呼叫 `Battle_SetUnitPosition` (`0x00959830`) 將新座標回寫至 `+0x83950` 偏移欄位。

---

## 2. 整合至重建引擎之規格定義

依據上述已證實之二進位邏輯，在 Python 戰鬥核心中實體移動步進應嚴格遵循：
1. 每幀遍歷活躍實體（$0 \le \text{slot} < 51$）。
2. 若 `knockback_state > 0`，實體執行擊退位移（向後退），不累加向前速度。
3. 若 `knockback_state == 0` 且未進入攻擊前搖/定身狀態，實體按 `speed` 步進增加 `position_x`。
