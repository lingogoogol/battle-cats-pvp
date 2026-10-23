# 《貓咪大戰爭》核心戰鬥系統逆向分析 (BATTLE_SYSTEM_ANALYSIS.md)

- **目標二進位**：`libnative-lib.so`
- **對照實作**：`E:\rea\phase6\prototype\battle_engine.py` (經單元測試驗證通過)
- **幀率基準**：30 FPS (固定步長 `dt = 1/30` 秒)

---

## 一、 核心戰鬥子系統細部剖析

### 1. 戰鬥初始化 (Battle Initialization)
- **確認入口**：`BattleInit` / `0x0018cb41` 及場景建構常式
- **證據等級**：**【已確認 (Confirmed)】**
- **資料結構**：
  - 舞台長度（Stage Length）：預設標準長度範圍約 1000 ~ 6000 像素。
  - 我方城堡（Cat Base）：位置 `X = 0`，HP 隨關卡等級增長。
  - 敵方城堡（Enemy Base）：位置 `X = Stage_Length`，HP 隨關卡設定。
  - 初始金錢與上限：初始 0 金幣，錢包容量依研究所升級等級判定。

### 2. 單位建立與狀態更新 (Unit Creation & State Update)
- **確認入口**：`MyApplication::battle_createButton` (`0x001bf6ba`)
- **證據等級**：**【已確認 (Confirmed)】**
- **行為機制**：
  - 當玩家點擊下方 UI 的出擊按鈕（`BattleButton`），檢查目前金錢 $\ge$ 該單位消耗量，且冷卻計時器為 0。
  - 扣除金幣後，以 `new Unit()` 實例化單位，將其加入至 `std::vector<Unit*>` 我方部隊實體隊列中。
  - 狀態機定義：三態循環 `MOVING` (移動) $\rightarrow$ `ATTACKING` (攻擊發動) $\rightarrow$ `RECOVERY` (攻擊後搖/冷卻) $\rightarrow$ `MOVING`。

### 3. 單位移動機制 (Unit Movement)
- **確認入口**：單位狀態機內部前進步進
- **證據等級**：**【已確認 (Confirmed)】**
- **計算公式**：
  - 我方單位：$X_{t+1} = \min(X_t + \text{Speed}, \text{StageLength})$
  - 敵方單位：$X_{t+1} = \max(0, X_t - \text{Speed})$
  - 碰撞推進：單位本體彼此不產生物理推擠阻擋（可疊怪），僅依據目標城堡或最前線敵人的距離決定停步。

### 4. 攻擊目標選擇 (Target Selection)
- **確認入口**：`battleCheckLogic` (`0x001c11a1`)
- **證據等級**：**【已確認 (Confirmed)】**
- **選擇邏輯**：
  - 1D 距離計算：$\text{Dist} = |X_{\text{attacker}} - X_{\text{target}}|$。
  - 遍歷對方存活實體：尋找在攻擊範圍內（$\text{Dist} \le \text{Range}$）最近之敵方單位。
  - 若敵方無單位在前線，則目標直接選定為敵方城堡（Base）。

### 5. 攻擊時序與傷害判定 (Attack Timing & Damage Calculation)
- **確認入口**：`battleCheckLogic`
- **證據等級**：**【已確認 (Confirmed)】**
- **時序切分**：
  1. **前搖 (Pre-Attack Delay, 幀數 $F_{\text{pre}}$)**：進入 `ATTACKING` 狀態後，播放攻擊起手動作。
  2. **打擊幀 (Hit Frame, $t = F_{\text{pre}}$)**：在此精確 tick 扣除目標 HP；若是範圍攻擊（Area Attack），則對射程內所有敵軍造成同等傷害。
  3. **後搖與頻率 (Attack Interval / Cooldown, $F_{\text{int}}$)**：動作收招，計時器達 $F_{\text{int}}$ 後方可再次前進或攻擊。

### 6. HP 更新、擊退 (Knockback) 與死亡判定 (Death)
- **確認入口**：單位受傷處理常式
- **證據等級**：**【已確認 (Confirmed)】**
- **機制剖析**：
  - 每次受傷：$\text{HP}_{\text{new}} = \max(0, \text{HP}_{\text{current}} - \text{Damage})$。
  - 擊退（KB, Knockback）：若累積傷害跨越 $\text{MaxHP} / \text{KB\_Count}$ 閥值，中斷當前攻擊動作，向後強制位移一段距離。
  - 死亡判定：當 $\text{HP} \le 0$，狀態設為 `DEAD`，播放消散靈魂動畫，並從活動實體列表移除。

### 7. 勝負判定 (Victory & Defeat)
- **確認入口**：`battle_initWin` (`0x001befe1`)、`BattleFinishWinSE` (`0x00191540`)、`BattleFinishLoseSE` (`0x0019aa08`)
- **證據等級**：**【已確認 (Confirmed)】**
- **判定規則**：
  - 敵方城堡 $\text{HP} \le 0$：觸發 `battle_initWin`，播放勝利號角，結算統率力、XP 與道具獎勵。
  - 我方城堡 $\text{HP} \le 0$：觸發失敗結算，彈出 `BattleContinue`（是否花費 30 貓罐頭接關復活）。
