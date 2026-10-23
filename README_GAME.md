# 《貓咪大戰爭》重構工程：桌面遊戲遊玩與架構指南 (README_GAME.md)

本工程是《貓咪大戰爭》(The Battle Cats) 繁中版 v15.6.1 的高保真、獨立可編輯、可編譯、可執行的 Python/Pygame 桌面重構版本。所有戰鬥邏輯、記憶體定址與傷害演算法皆嚴格具備 AArch64 原生機器碼與 Unicorn 差異測試的數學級實證支持。

---

## 一、一鍵啟動遊戲 (Quick Start)

### 1. Windows 批次檔啟動
在專案根目錄下直接雙擊或在命令列執行：
```powershell
E:\rea\run_game.bat
```

### 2. 透過 Python 虛擬環境直接執行
```powershell
$env:PYTHONPATH = "E:\rea"
& "E:\rea\venv\Scripts\python.exe" "E:\rea\game_project\main.py"
```

### 3. 命令列常用參數
- **無頭測試模式（適合自動化 CI 或無螢幕環境）**：
  ```powershell
  & "E:\rea\venv\Scripts\python.exe" "E:\rea\game_project\main.py" --headless --auto-play --frames 300 --screenshot "E:\rea\game_project\screenshots\test.png"
  ```
- **直接進入特定狀態（跳過主選單）**：
  ```powershell
  & "E:\rea\venv\Scripts\python.exe" "E:\rea\game_project\main.py" --state stage_select
  ```

---

## 二、遊戲操作與熱鍵指南

| 操作行為 | 鍵盤熱鍵 | 滑鼠操作 |
|---|:---:|---|
| **部署卡牌 1 (普通貓)** | `1` 或小鍵盤 `1` | 點擊底部第 1 張卡牌 |
| **部署卡牌 2 (坦克貓)** | `2` 或小鍵盤 `2` | 點擊底部第 2 張卡牌 |
| **部署卡牌 3 (戰斧貓)** | `3` 或小鍵盤 `3` | 點擊底部第 3 張卡牌 |
| **部署卡牌 4 (牛貓)** | `4` 或小鍵盤 `4` | 點擊底部第 4 張卡牌 |
| **部署卡牌 5 (蜥蜴貓)** | `5` 或小鍵盤 `5` | 點擊底部第 5 張卡牌 |
| **升級工作狂貓 (提高金錢上限與速度)** | `U` | 點擊左下角工作狂貓按鈕 |
| **戰場鏡頭平移 (滑動視野)** | `A` / `D` 或 `←` / `→` | 在戰場空白處按住滑鼠左鍵水平拖曳 |
| **重新開始本場戰鬥** | `R` | 結算彈窗點擊「重新開始」按鈕 |
| **返回上一層 (關卡選擇 / 選單 / 退出)**| `ESC` | 點擊「返回」或結算彈窗「關卡選擇」按鈕 |

---

## 三、自動化測試與基準效能執行

執行全套端到端自動化測試與壓力基準：
```powershell
# 1. 執行全專案 6 大套件回歸測試 (100% PASS)
& "E:\rea\venv\Scripts\python.exe" "E:\rea\phase17\run_all_tests.py"

# 2. 執行邊界、長效 1000 幀穩定性與效能基準測試
& "E:\rea\venv\Scripts\python.exe" "E:\rea\phase17\run_full_system_test.py"
```

---

## 四、資料驅動自訂擴展 (Data-Driven Customization)

所有實體數值與關卡參數皆為開放之 JSON 格式，位於 `game_project/data/`：
- `cat_units.json`：貓咪生命值、攻擊力、射程、前搖、攻頻、擊退次數、目標型別（單體 `single` / 範圍 `area`）。
- `enemy_units.json`：敵方各兵種數值與擊殺金錢掉落。
- `stages/stage_*.json`：關卡長度、城堡生命值、定時敵軍波次、城堡血量門檻觸發首領事件。

修改後遊戲啟動時將自動進行 Schema 驗證，即刻生效！
