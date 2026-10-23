# 《貓咪大戰爭》逆向還原與網頁聯機對戰版 (The Battle Cats Rebuilt)

[![Python 3.10+](https://img.shields.io/badge/python-3.10+-blue.svg)](https://www.python.org/downloads/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Platform: Web & Desktop](https://img.shields.io/badge/platform-Web%20%7C%20Windows%20%7C%20macOS%20%7C%20Linux-green.svg)]()

本專案是《貓咪大戰爭》（The Battle Cats）官方繁中版 v15.6.1 的 **100% 官方數據逆向還原、純 Python / Pygame 桌面版與 HTML5 Canvas 4 位數房號網頁聯機對戰版**。

所有戰鬥邏輯、傷害公式、狀態異常、多段攻擊判定（`pre1 / pre2 / pre3`）與 2D 骨骼動畫運算皆嚴格對齊 PONOS 官方原版與 `tbcml` 逆向工程規範。

---

## 🌟 核心特色 (Key Features)

1. **4 位數房號極簡連線對戰 (Web PvP by Room Code)**
   - 玩家 1 點擊「建立房間」（或自訂如 `1234`）取得 4 位數房號。
   - 玩家 2 打開網頁輸入房號，一秒加入對戰！
   - P1 操作右側貓咪主堡（向左進攻），P2 操作左側主堡（向右進攻）。
   - 支援免費自動 Cloudflare 穿透隧道，朋友即便在不同網路、校園網或用手機也能直接輸入網址開戰。

2. **100% 官方 2D 骨骼動畫引擎 (.imgcut + .mamodel + .maanim)**
   - 嚴格重現 PONOS 官方 2×3 仿射矩陣（Affine Transform `[m0, m1, m2, m3, m4, m5]`）、遞迴縮放與 Alpha 階層計算。
   - 完美支援負縮放骨骼鏡像翻轉（如星光桃子右上臂、衛宮士郎干將莫邪軌跡、狂亂姆特蓄力氣彈）。
   - 30 FPS 整數幀求值搭配 60/120Hz 畫面平滑位移插值。

3. **6 大稀有度 38 隻官方貓咪完整收錄**
   - 涵蓋 **基本、EX、稀有、激稀有、超激稀有、傳說稀有** 各至少 5～9 隻貓咪。
   - 支援原版多段攻擊（Multi-Hit，如星光桃子 `300 + 600 + 3500`、衛宮士郎 `3000 + 3000`、番長貓 `145 * 3`）。
   - 支援各段獨立遠方範圍（LD）、特技觸發旗標（`use_ability`）與各稀有度特性（極度傷害 5x、極度耐打 1/6、渾身一擊、波動、烈波、降攻、破盾、死前存活等）。

4. **開戰前配隊選角與等級切換系統 (Formation & Level Scaling)**
   - 支援原版雙排 10 格出陣編隊卡槽（上排 1~5、下排 6~10）。
   - 支援「**貓咪等級切換**」（Lv.1 官方原始 CSV 數值、Lv.10、Lv.20、Lv.30 實戰標準、Lv.50 滿等）。
   - 提供推薦編隊預設按鈕（全稀有度精銳隊、低費快攻隊、超激傳說大軍、依費用排序）。

5. **網頁內建「自製角色工坊」(Custom Character Creator)**
   - 在瀏覽器中即可直接自訂角色名稱、HP、AP、攻擊射程、跑速、費用、冷卻、波動、暴擊、暫停等屬性。
   - 可挑選 38 隻官方外觀骨骼模型並即時預覽動作。
   - 儲存後立即存檔於 `custom_units/*.json`，進入房間後**自動同步給對手**，立即上場實戰！

6. **雙重端支援 (Web & Desktop)**
   - 既是高效輕量的網頁 WebSocket / HTTP 伺服器，也是原汁原味的 Pygame 桌面遊戲。

---

## 🚀 快速上手 (Quick Start)

### 1. 複製儲存庫 (Clone Repository)
```bash
git clone https://github.com/wu7010506-lang/battle-cats-pvp.git
cd battle-cats-pvp
```

### 2. 安裝環境依賴 (Install Dependencies)
建議使用 Python 3.10 或更高版本：
```bash
pip install -r requirements.txt
```

### 3. 一鍵啟動遊戲 (Run)

#### 🌐 模式 A：網頁房號聯機對戰版（推薦，支援跨電腦與朋友對戰）
- **Windows 一鍵雙擊**：執行根目錄的 `run_web.bat`。
- **命令列執行**：
  ```bash
  python -m game_project.web_server 8080
  ```
- **開啟遊戲**：
  - 本機瀏覽器開啟：`http://127.0.0.1:8080`
  - 區網內其他電腦/手機：`http://<你的內網IP>:8080`
  - 終端機也會自動輸出 Cloudflare 公開網址（若有提供），點開即可讓外網朋友免裝環境直接用瀏覽器遊玩！

#### 🖥️ 模式 B：桌面 Pygame 原版視窗
- **Windows 一鍵雙擊**：執行根目錄的 `run_game.bat`。
- **命令列執行**：
  ```bash
  python -m game_project.main
  ```

#### 🧪 模式 C：執行全套自動化回歸測試
```bash
python game_project/test_playable.py
```
（包含 21 項嚴格測試：多段攻擊傷害與出招幀校驗、各稀有度角色載入、TCP 聯機 Lockstep、貓咪砲機制、特技觸發等，全數 100% 通過）。

---

## 🎮 操作指南 (Controls)

### 網頁對戰版 (Web Edition)
- **召喚角色**：點擊下方出陣卡槽，或使用鍵盤快速鍵：
  - 上排 1～5 格：`1`, `2`, `3`, `4`, `5`
  - 下排 6～10 格：`Q`, `W`, `E`, `R`, `T`（或 `6`, `7`, `8`, `9`, `0`）
- **升級工作狂貓**：按 `Z` 鍵或點擊左下角工作狂貓頭像。
- **發射貓咪砲**：充能 100% 後按 `空白鍵 (Space)` 或點擊右下角貓咪砲圖示。
- **戰場平移**：滑鼠拖曳畫面，或按鍵盤 `←` / `→`（或 `A` / `D`）。

---

## 🛠️ 開發與修改指南 (How to Modify & Contribute)

歡迎朋友一起修改與擴充！以下是專案核心程式碼架構：

```text
battle-cats-pvp/
├── game_project/
│   ├── web_server.py            # 網頁版房號伺服器 (HTTP / SSE / Action API)
│   ├── web/
│   │   ├── index.html           # 網頁主介面（大廳、配隊選角、對戰畫布、工坊）
│   │   └── app.js               # HTML5 Canvas 骨骼渲染與 30 FPS 戰鬥引擎
│   ├── anim_engine/
│   │   └── ponos_anim_player.py # 官方 .imgcut + .mamodel + .maanim 骨骼動畫播放器
│   ├── core/
│   │   ├── official_data_parser.py # 官方 unitXXX.csv / Enemy.csv 逆向解析器
│   │   ├── unit_data.py         # 38 隻官方角色註冊表與屬性
│   │   ├── custom_unit_loader.py # 自製角色 JSON 載入與跨端同步
│   │   └── constants.py         # 遊戲常數、傷害位移、狀態異常定義
│   ├── simulation/
│   │   ├── battle_sim.py        # 戰鬥狀態機（四段攻擊流程、擊退、特技判定）
│   │   └── deployer.py          # 隊伍卡牌冷卻、花費、等級成長倍率計算
│   ├── assets/official_extracted/ # 官方解包材質圖集、骨骼模型與動作檔
│   ├── custom_units/            # 自製角色存檔目錄 (*.json)
│   └── test_playable.py         # 自動化單元測試
├── run_web.bat                  # 網頁伺服器一鍵啟動腳本
├── run_game.bat                 # 桌面遊戲一鍵啟動腳本
├── requirements.txt             # Python 依賴清單
└── README.md
```

### 常見修改情境：
1. **修改官方貓咪數值或特技**：
   - 編輯 `game_project/core/official_data_parser.py` 或 `game_project/core/unit_data.py`。
2. **新增原創自製角色**：
   - 直接在網頁上的「自製角色工坊」新增並儲存；或在 `game_project/custom_units/` 建立新的 `.json` 檔案。
3. **調整戰鬥物理與傷害運算**：
   - 編輯 `game_project/simulation/battle_sim.py` 中的 `_update_attacks` 與 `_apply_damage`。
4. **調整前端畫面、字體與特效**：
   - 編輯 `game_project/web/app.js` 與 `game_project/web/index.html`。

---

## 📜 授權協議 (License)

本專案之開源重構程式碼基於 MIT 授權條款釋出。遊戲內所涉及之《貓咪大戰爭》原始美術材質與音效商標著作權屬 PONOS Corporation 所有，僅供逆向工程研究、教育研討與同好交流使用。
