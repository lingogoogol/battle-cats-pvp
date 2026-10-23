# 戰鬥結算機制規格參考文件 (mechanic_reference.md)

**參考二進位**：`libnative-lib.so` (AArch64)  
**函式參考位址**：
- `0x004cecc0` (`MyApplication::battle_initWin`)
- `0x004ced10` (Closure 建構與 VTable 綁定)
- `0x004dff1c` (`MyApplication::battle_initWin_callback`)

---

## 1. 機制規格定義 (Mechanic Specification)

### 狀態枚舉 (State Enums)
```python
class SettlementDialogMode:
    NONE = 0
    DEFEAT_RETRY = 4       # 原版常量: 0x04 (w21 = 4)
    VICTORY_REWARDS = 36   # 原版常量: 0x24 (w21 = 0x24)

class BackgroundMusicTrack:
    NONE = 0
    DEFEAT_BGM = 16        # 原版常量: 0x10 (w9 = 0x10)
    VICTORY_BGM = 18       # 原版常量: 0x12 (w8 = 0x12)

class ButtonActionCode:
    PRESSED = 1
    HOVER = 2
    RELEASED = 3
    CONFIRMED = 4          # 原版常量: cmp w8, #4
```

### 記憶體模型 (Memory Model)
```c
struct WinLossClosure {
    void* vtable_ptr;      // 0x00: 0x00adc248
    void* app_singleton;   // 0x08: g_pApplication 指標
    uint8_t is_win;        // 0x10: 1=VICTORY, 0=DEFEAT
};
```

---

## 2. 演算法邏輯流程 (Algorithm Pipeline)

1. **事件驗證**：
   - 接收按鈕觸控事件代碼 `event_code`。
   - 若 `event_code != CONFIRMED (4)`，直接忽略，不觸發結算狀態變更。
2. **分支判定**：
   - 自閉包結構體偏移 `0x10` 讀取 `is_win`。
   - 若 `is_win != 0`（勝利）：
     - 隱藏戰鬥操作 HUD（`HideBattleControls()`）。
     - 播放通關勝利號角音效（`PlayVictoryFanfare()`）。
     - 分發關卡掉落獎勵、經驗值與首通旗標（`AwardStageRewards()`）。
     - 設定結果對話框模式為 `VICTORY_REWARDS (36)`。
     - 設定背景音樂為 `VICTORY_BGM (18)`。
   - 若 `is_win == 0`（失敗）：
     - 設定結果對話框模式為 `DEFEAT_RETRY (4)`。
     - 設定背景音樂為 `DEFEAT_BGM (16)`。
3. **場景結算與退出**：
   - 應用背景音樂與對話框模式。
   - 將戰鬥場景標記為結算完成，準備返回大地圖。
