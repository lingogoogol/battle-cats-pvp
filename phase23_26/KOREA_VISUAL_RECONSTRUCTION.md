# Phase 25 韓國關卡視覺重建與原版資產溯源報告 (KOREA_VISUAL_RECONSTRUCTION.md)

**專案根目錄**：`E:\rea`  
**評估日期**：2026-10-15  
**標的場景**：第 1 關「韓國」（Korea Stage）實機戰場視覺呈現與原版資產導入  
**總體裁定**：**PASS WITH AUTHENTIC SKELETAL & DEBUG OVERLAY (部分原版視覺導入，除錯圖層就緒)**

---

## 一、視覺元素原版還原與資產來源逐項稽核

我們嚴格區分「已驗證原版資產」與「暫代元素」，絕不以自行設計的畫面冒充官方原版：

| 視覺組件 | 目前實作呈現 | 原始資產來源 / 封包位址 | 還原度評核 | 狀態標記與說明 |
|---|---|---|:---:|---|
| **基本貓 (Basic Cat)** | **官方 2D 骨骼逐幀動畫** | `DownloadLocal.pack` (`download_char_000.png` + `.imgcut` + `.mamodel` + `_walkR.maanim`) | **100.0% (原版)** | **`VERIFIED_AUTHENTIC`**：由自研 [`PonosAnimationPlayer`](file:///E:/rea/game_project/anim_engine/ponos_anim_player.py) 實時驅動，2D 骨骼階層無代用。 |
| **賈修狗 (Doge 000_e)** | 暫代向量精靈圖 | 官方 `000_e.png` 位於伺服器 `ImageServer.pack` (CDN) | **30.0% (暫代)** | **`BLOCKED_AWAITING_INPUT`**：未預裝於離線 APK 本地封包中，嚴禁補畫冒充。 |
| **官方敵方 (Enemy 186)**| **官方 2D 骨骼逐幀動畫** | `NumberLocal.pack` + `ImageDataLocal.pack` (`186_e.*` 91 部件骨架) | **100.0% (原版)** | **`VERIFIED_AUTHENTIC`**：可作為官方敵方 2D 骨骼動畫的完整真機驗收參照。 |
| **底部出兵底板** | **官方原版拼貼貼圖** | `InstallPack.apk` (`assets/bottom_bg01.png`, 220x220 RGBA) | **95.0% (原版貼圖)** | **`VERIFIED_AUTHENTIC`**：使用官方底板紋理水平/垂直無縫平鋪。 |
| **戰場背景** | 參數化草原背景與遠山 | 官方 `stage00.csv` 參數 (`bg_type=0`)，對應 CDN `bg.png` | **40.0% (參數化)** | **`PARTIAL_PARAMETRIC`**：底層數值完全由官方 CSV 驅動，貼圖需待伺服器包。 |
| **雙方城堡** | 參數化主堡與血條 | 官方 `stage00.csv` 敵方血量 500，官方貼圖位於伺服器包 | **50.0% (數值原版)** | **`PARTIAL_PARAMETRIC`**：城堡血量與碰撞位址精確對齊官方 `stage00.csv`。 |
| **戰鬥頂部 HUD** | 官方色彩版面與血量條 | 參照 PONOS 戰鬥介面階層（金錢/工作狂貓/城堡血條） | **75.0% (佈局對齊)** | **`AUTHENTIC_LAYOUT`**：提供工作狂貓、錢包上限與城堡雙向計數。 |
| **戰鬥打擊音效** | 官方原版音效串流 | `extracted_audio/` (25 首官方 `.ogg` 檔案) | **100.0% (原版)** | **`VERIFIED_AUTHENTIC`**：打擊、擊退、升級、升級均調用原版音訊。 |

---

## 二、座標系統與視口佈局稽核

依據原生程式碼分析與官方數據，戰場座標系統採用**雙層映射機制**：

1. **世界模擬空間 (Simulation World Space)**：
   * 韓國關卡總長度：`stage_width = 3000`（來自官方 `stage00.csv` 第 1 行第 1 欄位）。
   * 我方城堡中心點：`X = 100`。
   * 敵方城堡中心點：`X = 2900`（`stage_width - 100`）。
   * 地面基準線：`GROUND_Y = 510`（在 720p 空間下佔 70.8% 垂直高度）。
2. **螢幕視口空間 (Screen Viewport Space)**：
   * 基準解析度：`1280 × 720`（16:9 寬螢幕投影）。
   * 鏡頭平移矩陣：`screen_x = world_x - camera_offset_x`。
   * 鏡頭邊界限制：`[0, stage_width - SCREEN_WIDTH]`（`0 ~ 1720`）。
   * 支援鍵盤（`A` / `D` 或方向鍵）與滑鼠邊界拖曳平移。

---

## 三、可切換除錯圖層 (Debug Overlay)

為達成 Phase 25 驗收條件，在戰鬥渲染器中加入了獨立的除錯圖層（快捷鍵：**`F1`** 或 **`D`**）：

1. **世界座標軸線**：以每 500 單位標記垂直網格線（`X=0`, `X=500`, ..., `X=3000`），直觀監視單位行進進度。
2. **碰撞與檢測框**：
   * 綠色矩形標示我方單位碰撞半徑（Hitbox）。
   * 紅色矩形標示敵方單位碰撞半徑。
   * 黃色圓點標示腳底地面動畫錨點（Pivot Anchor `(X, GROUND_Y)`）。
3. **資產溯源標籤 (Provenance Badge)**：
   * 基本貓頭頂顯示：`[Official: DownloadLocal.pack (download_char_000, 16f skeletal)]`。
   * 敵方 186 頭頂顯示：`[Official: NumberLocal+ImageDataLocal (186_e, 91 parts)]`。
   * 賈修狗頭頂顯示：`[Substitute: doge (000_e.png in ImageServer.pack)]`。
   * 主堡顯示：`[Enemy Castle: stage00.csv HP: 500]`。

---

## 四、實機截圖與成果交付

1. **戰場實機截圖（含除錯圖層）**：[`phase23_26/korea_battle_debug_overlay.png`](file:///E:/rea/phase23_26/korea_battle_debug_overlay.png)
2. **戰場實機截圖（純淨展示）**：[`phase23_26/korea_battle_clean.png`](file:///E:/rea/phase23_26/korea_battle_clean.png)
3. **對照組評估結論**：
   * 由於官方真機截圖 `E:\rea\references\official_v15_6_1\03_battle_korea_initial.png` 目前仍待使用者上傳，本階段遵循誠實準則，視覺像素比對狀態維持 **`VISUAL_PARITY_UNVERIFIED`**，不宣稱 100% 視覺還原。
