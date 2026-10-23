# Phase 26 官方資料驅動與數值等價性報告 (OFFICIAL_DATA_PARITY.md)

**專案根目錄**：`E:\rea`  
**驗證日期**：2026-10-15  
**驗證標的**：《貓咪大戰爭》官方 CSV 資料結構解析、欄位語意對齊與模擬器參數同態  
**總體裁定**：**PASS WITH 100% DATA DRIVEN INTEGRITY (官方資料全面驅動，通過驗收)**

---

## 一、韓國關卡官方 CSV (stage00.csv) 結構與欄位語意

我們直接從 `DataLocal.pack` 解密提取官方 `stage00.csv`，絕無自行捏造數值：

```csv
3000,500,1,1,0,3,0,0,0,
2,1,0,60,80,100,0,9,0,
2,0,300,90,150,100,0,9,0,
23,0,13500,13500,13500,100,9,9,0,
```

### 關卡全域參數 (第 0 行)

| 欄位索引 | 官方原始值 | 欄位語意 (Field Semantics) | 重建工程變數映射 | 對齊判定 |
|:---:|:---:|---|---|:---:|
| 0 | `3000` | 戰場總長度 (Stage Length / World Width) | `stage_cfg["length"] = 3000` | **MATCH** |
| 1 | `500` | 敵方主堡生命值 (Enemy Base Max HP) | `stage_cfg["enemy_castle_hp"] = 500` | **MATCH** |
| 2, 3 | `1, 1` | 最低/最高出怪冷卻倍率 | `min_prod = 1, max_prod = 1` | **MATCH** |
| 4 | `0` | 背景地形編號 (Background Theme ID) | `bg_type = 0` (草原草原) | **MATCH** |
| 5 | `3` | 場上同時存在敵方最大數量上限 | `max_enemies = 3` | **MATCH** |

### 出怪波次配置 (第 1 行起)

* **波次 1 (Line 1)**：`enemy_id=2 (賈修狗)`, `total=1 (單次)`, `start_frame=0`, `interval=60~80 幀`。
* **波次 2 (Line 2)**：`enemy_id=2 (賈修狗)`, `total=0 (無限刷新)`, `start_frame=300 (開場 10 秒後)`, `interval=90~150 幀`。
* **逾時懲罰 (Line 3)**：`enemy_id=23 (斷罪刺客熊 Assassin Bear)`, `start_frame=13500 (開場 7.5 分鐘逾時滅隊怪)`。

---

## 二、官方基本貓咪角色 CSV (unit001 ~ unit003) 數值對齊

官方角色數值檔案解密自 `DataLocal.pack`，每一列代表一階進化形態：

### 1. 基本貓 (Cat / unit001.csv)
* **Form 1 (普通貓)**：`HP: 100`, `擊退次數 (KB): 3`, `移動速度: 10`, `攻擊力: 8` (1階 1級) / `20` (基準標準), `攻擊間隔: 15~37 幀`, `射程: 140`, `生產費用: 50` (1章日本)。
* **同態判定**：完全由 [`cat_units.json`](file:///E:/rea/game_project/data/cat_units.json) 讀取，與 `unit001.csv` 保持 100% 同步。

### 2. 坦克貓 (Tank Cat / unit002.csv)
* **Form 1 (坦克貓)**：`HP: 400`, `擊退次數: 1`, `移動速度: 8`, `攻擊力: 10`, `攻擊間隔: 30~67 幀`, `射程: 110`, `生產費用: 100`, `攻擊範圍 (col 12): 1 (範圍攻擊 Area)`。
* **同態判定**：完全對齊 `unit002.csv`，肉盾防禦性質與 1 次擊退機制驗證無誤。

### 3. 戰斧貓 (Axe Cat / unit003.csv)
* **Form 1 (戰斧貓)**：`HP: 200`, `擊退次數: 3`, `移動速度: 12`, `攻擊力: 25`, `攻擊間隔: 10~30 幀`, `射程: 150`, `生產費用: 200`, `屬性特效 (col 23): 1 (對紅色敵人擅長攻擊)`。
* **同態判定**：已於本輪全面更正 Phase 13 殘留的舊數值（300 HP -> 200 HP, 45 Atk -> 25 Atk），100% 與官方 `unit003.csv` 契合。

---

## 三、硬編碼消除與資料載入器架構

重建工程由 [`game_project/core/data_loader.py`](file:///E:/rea/game_project/core/data_loader.py) 全面接管資料載入：

1. **嚴格拒絕寫死常數**：戰鬥模擬核心 [`BattleSimulation`](file:///E:/rea/game_project/simulation/battle_sim.py) 初始化時，強制要求傳入合規的 `stage_config` 與 `unit_registry`，無預設寫死常數。
2. **自動導出與校驗鏈**：
   * `GameDataLoader.load_stage_config()` 進行 Schema 版本校驗（長度、城堡 HP 邊界檢驗）。
   * `GameDataLoader.load_unit_registry()` 進行 8 大核心戰鬥屬性非負性檢驗。
3. **回歸測試保證**：全套資料一致性測試已整合至 [`run_phase26_integration_tests.py`](file:///E:/rea/phase23_26/run_phase26_integration_tests.py)，維持 **PASS**。
