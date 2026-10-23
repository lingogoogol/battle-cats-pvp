# Phase 24 原版骨骼動畫正確性驗證報告 (ORIGINAL_ANIMATION_VALIDATION.md)

**專案根目錄**：`E:\rea`  
**驗證日期**：2026-10-15  
**驗證標的**：《貓咪大戰爭》原版 2D 骨骼動畫檔案規格與雙角色實時播放  
**總體裁定**：**PASS WITH AUTHENTIC SKELETAL PLAYBACK (骨骼動畫播放實證通過)**

---

## 一、動畫資產溯源與完整性稽核

依照專案嚴格原則，所有動畫必須能追溯至原始 APK 封包二進位位址，**嚴禁以自繪、補畫或 AI 生成充當原版**：

| 角色名稱 | 檔案類型 | 原始封包來源 | 檔名 | 規格細節 | 驗證狀態 |
|---|:---:|:---:|:---:|:---:|:---:|
| **基本貓 (Basic Cat)** | 精靈貼圖 (Atlas) | `DownloadLocal.pack` (off: 3600, sz: 6192) | `download_char_000.png` | 174x59, RGBA | **VERIFIED** |
| 基本貓 (Basic Cat) | 切割定義 (Imgcut) | `DownloadLocal.pack` (off: 3216, sz: 256) | `download_char_000.imgcut` | 4 Cuts | **VERIFIED** (Cut3 右側超出2px，已容錯處理) |
| 基本貓 (Basic Cat) | 骨骼模型 (Mamodel) | `DownloadLocal.pack` (off: 3472, sz: 128) | `download_char_000.mamodel` | 2 部件 (Root, Body) | **VERIFIED** (無循環階層) |
| 基本貓 (Basic Cat) | 行走動畫 (Walk) | `DownloadLocal.pack` (off: 9792, sz: 96) | `download_char_000_walkR.maanim` | 1 軌道, 16 幀循環 | **VERIFIED** |
| 基本貓 (Basic Cat) | 待機動畫 (Idle) | *原版 CDN 伺服器包* | `000_f00.maanim` | - | **BLOCKED_AWAITING_INPUT** (未內裝於離線安裝包) |
| 基本貓 (Basic Cat) | 攻擊動畫 (Attack) | *原版 CDN 伺服器包* | `000_f02.maanim` | - | **BLOCKED_AWAITING_INPUT** (未內裝於離線安裝包) |
| **賈修狗 (Doge 000_e)**| 全套動畫 (Walk/Atk) | *原版 CDN 伺服器包* | `000_e.*` | - | **BLOCKED_AWAITING_INPUT** (隸屬伺服器 `ImageServer.pack`) |
| **官方敵方 (Enemy 186)**| 精靈貼圖 (Atlas) | `NumberLocal.pack` (off: 2790736, sz: 43712)| `186_e.png` | 502x305, P模式 (調色盤) | **VERIFIED** |
| 官方敵方 (Enemy 186)| 切割定義 (Imgcut) | `ImageDataLocal.pack` (off: 21469113, sz: 1536)| `186_e.imgcut` | 45 Cuts, 0 越界 | **VERIFIED** |
| 官方敵方 (Enemy 186)| 骨骼模型 (Mamodel) | `ImageDataLocal.pack` (off: 21470649, sz: 6015)| `186_e.mamodel` | 91 部件 (階層骨架) | **VERIFIED** (無循環階層) |
| 官方敵方 (Enemy 186)| 行走動畫 (Walk) | `ImageDataLocal.pack` (off: 21476664, sz: 5465)| `186_e00.maanim` | 96 軌道, 16 幀循環 | **VERIFIED** |
| 官方敵方 (Enemy 186)| 待機動畫 (Idle) | `ImageDataLocal.pack` (off: 21482129, sz: 2086)| `186_e01.maanim` | 42 軌道, 16 幀循環 | **VERIFIED** |
| 官方敵方 (Enemy 186)| 攻擊動畫 (Attack) | `ImageDataLocal.pack` (off: 21484215, sz: 15015)| `186_e02.maanim` | 154 軌道, 49 幀時序 | **VERIFIED** |
| 官方敵方 (Enemy 186)| 擊退動畫 (Knockback)| `ImageDataLocal.pack` (off: 21499230, sz: 1782)| `186_e03.maanim` | 50 軌道, 1 幀響應 | **VERIFIED** |

---

## 二、PONOS 2D 骨骼動畫運算規範審查

自研播放器 [`PonosAnimationPlayer`](file:///E:/rea/game_project/anim_engine/ponos_anim_player.py) 依循 PONOS 核心動畫規範：

1. **坐標與比例空間**：
   * 縮放單位：`1000 = 1.0x`。
   * 旋轉單位：`3600 = 360.0°`（以 0.1° 為步長）。
   * 部件錨點（Pivot）：基於切片局部坐標系計算偏移。
2. **階層矩陣變換**：
   * 採用 DAG 深度遍歷或遞迴解析 `parent_id`。
   * 全域位置由父節點變換矩陣複合子節點局部偏移量 `(root_x, root_y)`。
3. **關鍵幀插值**：
   * `ease_mode == 0`：階梯式瞬間跳轉（用於替換切片 `mod_type == 2`）。
   * `ease_mode == 1`：線性內插（用於坐標、旋轉、縮放與不透明度）。

---

## 三、驗收交付物與實體產物

1. **驗證腳本**：[`phase23_26/validate_animations.py`](file:///E:/rea/phase23_26/validate_animations.py)
2. **互動展示程式**：[`phase23_26/dual_anim_demo.py`](file:///E:/rea/phase23_26/dual_anim_demo.py) 與批次啟動器 [`run_dual_anim_demo.bat`](file:///E:/rea/phase23_26/run_dual_anim_demo.bat)
3. **導出驗證影格條帶**：
   * 基本貓行走 16 幀條帶：[`phase23_26/anim_output/cat_walk_strip_16f.png`](file:///E:/rea/phase23_26/anim_output/cat_walk_strip_16f.png)
   * 敵方 186 行走 16 幀條帶：[`phase23_26/anim_output/enemy186_walk_strip_16f.png`](file:///E:/rea/phase23_26/anim_output/enemy186_walk_strip_16f.png)
   * 敵方 186 攻擊 16 幀條帶：[`phase23_26/anim_output/enemy186_attack_strip_16f.png`](file:///E:/rea/phase23_26/anim_output/enemy186_attack_strip_16f.png)
   * 雙角色實機對峙幀：[`phase23_26/anim_output/cat_vs_enemy186_faceoff.png`](file:///E:/rea/phase23_26/anim_output/cat_vs_enemy186_faceoff.png)
   * 實機動態執行截圖：[`phase23_26/anim_output/dual_anim_demo_snapshot.png`](file:///E:/rea/phase23_26/anim_output/dual_anim_demo_snapshot.png)
4. **完整審查 JSON**：[`phase23_26/animation_audit.json`](file:///E:/rea/phase23_26/animation_audit.json)
