# 《貓咪大戰爭》v15.6.1 原始資產成功恢復清單報告 (ASSET_RECOVERY_REPORT.md)

**專案根目錄**：`E:\rea`  
**建立日期**：2026-10-15  
**恢復來源**：Google Play 繁中版 v15.6.1 APK / XAPK 原版封包  
**恢復工具**：[`extract_official_pack.py`](file:///E:/rea/extract_official_pack.py)  
**導出目錄**：`E:\rea\game_assets\recovered_assets/`

---

## 一、本次正式解碼與恢復之原版資產總覽

### 1. 角色 Sprite 與完整骨骼動畫套件 (Character Animation Packs)

#### 套件 A：基礎貓咪走動動畫套件 (`download_cat`)
- **存放路徑**：`E:\rea\game_assets\recovered_assets\download_cat/`
- **組成要素**：
  - `download_char_000.png`：官方 Sprite Sheet 貼圖集（174 × 59 像素，32-bit RGBA PNG）。
  - `download_char_000.imgcut`：官方切片定義（4 組切片，包含 3 種不同腳步姿態之 57×57 貓咪精靈）。
  - `download_char_000.mamodel`：官方骨骼層次（根節點 `DM`、子節點 `ネコ`，中心錨點 `29, 58`，初始縮放 `1200`）。
  - `download_char_000_walkR.maanim`：官方走動關鍵影格（5 關鍵影格循環：0f -> 4f -> 8f -> 12f -> 16f）。
- **驗證狀態**：**DECODED & FORMAT_VALIDATED**（已由 Pygame 成功載入）。

#### 套件 B：原版敵人完整四動態骨骼套件 (`186_e`)
- **存放路徑**：`E:\rea\game_assets\recovered_assets\enemies/`
- **組成要素**：
  - `186_e.png`：官方敵人 Sprite Sheet（25,872 Bytes，標準 PNG）。
  - `186_e.imgcut`：官方切片定義（1,536 Bytes）。
  - `186_e.mamodel`：官方骨骼階層（6,015 Bytes，高階層次骨架）。
  - `186_e00.maanim`：走動動畫 (Walk)。
  - `186_e01.maanim`：待機動畫 (Idle)。
  - `186_e02.maanim`：攻擊動作 (Attack)。
  - `186_e03.maanim`：受擊與擊退動作 (Hit / Knockback)。
- **驗證狀態**：**DECODED & READY_FOR_PLAYBACK**。

---

### 2. 官方戰鬥與關卡核心數值表 (Official Combat & Stage CSVs)
- **存放路徑**：`E:\rea\game_assets\recovered_assets\data/`
- **恢復明細**：
  1. `unit001.csv`：基本貓官方參數（100 HP, 8 ATK, 140 Range, 50 Cost, 75f 充能, 10 走速, 3 次擊退）。
  2. `unit002.csv`：坦克貓官方參數（400 HP, 2 ATK, 110 Range, 100 Cost, 75f 充能, 8 走速, 1 次擊退）。
  3. `unit003.csv`：戰斧貓官方參數（300 HP, 30 ATK, 150 Range, 200 Cost, 75f 充能, 12 走速, 3 次擊退）。
  4. `stage00.csv`：世界篇第一章第 1 關「韓國」官方出怪波次配置（敵方主堡 500 HP、賈修狗 frame 0 登場、60~80f 頻率增援、13500f 殺意之熊超時警戒）。
  5. `stage01.csv`：世界篇第 2 關「蒙古」官方配置（賈修狗 + 蛇蛇聯合出擊）。
  6. `MapStageDataA_000.csv`：世界篇第一章關卡獎勵、統率力消耗（韓國 30 統率力、570 XP）。
  7. `AbilityData.csv`：貓咪砲台各等級攻擊力與冷卻階段換算表。
  8. `t_unit.csv`：全量角色圖鑑資料庫（197 KB）。

---

### 3. 原版戰場背景與 UI 圖元 (Battle Backgrounds & UI)
- `ImageLocal.pack` 之 `002_bank_sort_000.png`、`set_enemy001_zombie.png`、`bg265.png`、`bg268.png`。
- `UnitLocal.pack` 之 `udi*.png` 官方出兵卡牌圖標。
- `InstallPack.apk` 明文提取之 `bottom_bg01.png`、`back.png`、`cancel.png`、`close.png` 等 114 張 PNG。
- 25 個官方 `.ogg` 原始戰鬥音訊（`snd000.ogg` ~ `snd195.ogg`）。

---

## 二、階段總結

原版資產阻礙（`BLOCKED`）已被實質突破。本專案目前具備完全解密、讀取與注入任何繁中版 v15.6.1 角色、敵人、關卡與背景之能力。
