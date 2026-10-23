# 《貓咪大戰爭》v15.6.1 原版渲染與動畫架構逆向規格書 (ORIGINAL_RENDER_ARCHITECTURE.md)

**專案根目錄**：`E:\rea`  
**建立日期**：2026-10-15  
**依據二進位與資產**：`libnative-lib.so` (SHA-256: `6f82...baa0f`)、`Shader.vsh`、`Shader.fsh`、`ImageDataLocal.list`、`ImageLocal.list`  
**核心準則**：以原版 OpenGL ES 2.0 着色器、座標系統、Atlas 與骨骼動畫規格為唯一標準。對因加密暫時無法取得原版圖集之資產，嚴格標記為 `BLOCKED_SUBSTITUTE`，禁止宣稱達到視覺一致性。

---

## 一、虛擬畫布與視窗投影视角 (Viewport & Coordinate Spaces)

### 1.1 座標空間定義
原版《貓咪大戰爭》採用三層分級座標轉換體系：

```
[ 戰場世界邏輯座標 (Battlefield World) ] 
       │ 
       ▼ (相機位移 Camera Offset: -camera_x, 0)
[ 虛擬畫布視口座標 (Virtual Canvas Space: 1280×720 / 960×640) ]
       │ 
       ▼ (Orthographic Projection Matrix * ModelView Matrix)
[ 螢幕 NDC 剪裁空間 (Normalized Device Coordinates: [-1, 1]) ]
       │ 
       ▼ (GL Viewport Transform)
[ 實體設備像素 (Device Pixels) ]
```

### 1.2 戰場佈局與地面基準線 (Ground Baseline)
- **虛擬畫布解析度**：基準為 `1280 × 720`（16:9 橫向標準）。
- **地面基準線 (Ground Line)**：
  - 縱向 Y 軸座標：定於 `Y = 510`（自頂部向下計算，佔畫面高度之 70.83%）。
  - 角色、城堡、敵人之腳底接觸點（Pivot Foot Anchor）強制對齊此基準線。
  - 所有實體移動僅在 X 軸進行（一維戰線推進），Y 軸僅在擊退（Knockback 拋物線彈跳）與特定浮空動作時產生偏移。
- **戰場長度 (Stage Distance)**：
  - 由關卡 CSV（如 `MapStageDataA_000.csv`）定義，世界篇第一章第 1 關「韓國」標準戰場長度為 `2400` 邏輯距離單位。
  - 我方城堡中心位於 `X = 200`，敵方城堡中心位於 `X = 2200`（戰線有效交戰長度 2000 單位）。
- **相機捲動邊界 (Camera Pan Range)**：
  - 相機視野寬度：`1280` 像素。
  - 可平移範圍：`X_min = 0` 至 `X_max = Stage_Length - 1280`。
  - 初始狀態：通常居中於我方城堡或畫面左端（`Camera_X = 0`）。

### 1.3 城堡與角色尺寸比例規格
- **我方/敵方城堡 (Castles)**：
  - 碰撞判定寬度：`160` 邏輯像素。
  - 視覺外觀寬度：`240 ~ 280` 像素；外觀高度：`320 ~ 360` 像素。
  - 城堡血條位置：位於城堡頂部上方 `20` 像素處，標準寬度 `180` 像素、高度 `12` 像素。
- **單位尺寸比例 (Unit Dimensions)**：
  - 基本貓（Cat / unit001）：碰撞寬度 `40` 像素，外觀約 `80 × 80` 像素。
  - 柴犬（Doge / enemy001）：碰撞寬度 `50` 像素，外觀約 `85 × 75` 像素。
  - 坦克貓（Tank Cat / unit002）：碰撞寬度 `50` 像素，外觀約 `90 × 130` 像素。

---

## 二、PONOS 專屬 2D 骨骼動畫檔案規格

原版動畫管線由三位一體的檔案組合構成（封裝於 `ImageDataLocal.pack`）：

```
[ Texture Atlas (PNG) ] ──> [.imgcut (切片定義)] ──> [.mamodel (骨骼層次)] ──> [.maanim (關鍵影格)]
```

### 2.1 `.imgcut` 貼圖切片規格 (Texture Atlas Slicing)
`.imgcut` 為純文字 CSV 結構，定義單張 PNG 紋理圖集（Sprite Sheet）之矩形切割區塊：
- **第 1 行**：切片總數 `N`（整數）。
- **第 2 至 N+1 行**：各部件切片矩形定義：
  ```csv
  part_x, part_y, width, height, [part_name]
  ```
  - `part_x, part_y`：在主 PNG 圖集中的左上角像素座標。
  - `width, height`：切片之寬度與高度。

### 2.2 `.mamodel` 骨骼層次模型規格 (Skeletal Hierarchy)
`.mamodel` 定義角色的骨骼樹狀結構與初始靜態變換（Rest Pose）：
- **第 1 行**：骨骼部件總數 `M`。
- **第 2 至 M+1 行**：各骨骼部件參數：
  ```csv
  parent_id, unit_cut_id, z_order, pos_x, pos_y, pivot_x, pivot_y, scale_x, scale_y, angle, opacity, glow
  ```
  - `parent_id`：父部件索引（`-1` 為根節點，遵循層級父子變換矩陣）。
  - `unit_cut_id`：對應之 `.imgcut` 切片 ID。
  - `z_order`：繪圖深度排序（由小至大繪製）。
  - `pos_x, pos_y`：相對父節點之偏移座標。
  - `pivot_x, pivot_y`：旋轉與縮放中心錨點。
  - `scale_x, scale_y`：初始縮放千分比（1000 = 100%）。
  - `angle`：初始旋轉角度（0 ~ 3600，即十分之一度）。
  - `opacity`：不透明度（0 ~ 1000）。

### 2.3 `.maanim` 關鍵影格動畫軌道 (Animation Keyframe Tracks)
`.maanim` 定義角色各骨骼在時間軸（幀數）上的動態變換數值：
- **檔案頭**：動畫段落與軌道總數。
- **軌道資料區塊**：
  - 每個部件對應多個變換屬性通道（Modification Types）：
    - `0`：切片替換 (`unit_cut_id`)
    - `1`：X 軸位移 (`pos_x`)
    - `2`：Y 軸位移 (`pos_y`)
    - `3`：旋轉中心 X (`pivot_x`)
    - `4`：旋轉中心 Y (`pivot_y`)
    - `5`：X 軸縮放 (`scale_x`)
    - `6`：Y 軸縮放 (`scale_y`)
    - `7`：旋轉角度 (`angle`)
    - `8`：不透明度 (`opacity`)
  - 每個屬性包含關鍵影格清單：
    ```csv
    frame_index, value, easing_type
    ```
    - `frame_index`：動畫影格索引（原版標準動畫時鐘以 30 FPS 計）。
    - `value`：當前屬性數值。
    - `easing_type`：插值方式（0: 常數即時步進、1: 線性插值、2: 貝茲緩動曲線）。

---

## 三、戰鬥模擬與視覺渲染同步協議 (Simulation-Render Sync Protocol)

原版採用嚴格的「邏輯步進驅動視覺」原則：

| 戰鬥模擬狀態 (Simulation Logic) | 視覺動畫狀態 (Animation State) | 音效與特效同步 (Audio / FX) |
|---|---|---|
| **空閒/推進 (Walking / Advancing)** | 循環播放 `_walk.maanim` | 無或環境音 |
| **進入攻擊前搖 (Attack Windup)** | 觸發 `_attack.maanim` 前段影格 (Frame 0 ~ Attack_Frame) | 播放攻擊蓄力/叫聲 |
| **攻擊判定生效 (Damage Dispatch)** | 抵達攻擊瞬發影格 (Damage Frame) | 播放打擊音效 (`snd000.ogg`)，生成打擊火花 |
| **攻擊後搖/冷卻 (Cooldown Idle)** | 播放 `_attack.maanim` 收招影格，其後切換至站立硬直 | 無 |
| **受到擊退 (Knockback Trigger)** | 中斷當前攻擊動畫，強制切入受擊跳躍 (拋物線擊退位移) | 播放受擊音效 (`snd062.ogg`) |
| **生命值歸零 (Death Pipeline)** | 觸發死亡靈魂升天動畫，本體漸變透明消失 | 播放陣亡散落音效 |

---

## 四、UI 配置與原版比例規範 (UI Chrome & Layout Rules)

在 `1280 × 720` 基準畫布下：
1. **頂部資訊條 (Top Bar)**：
   - 己方金錢顯示：位於右上方 `X = 960 ~ 1240, Y = 20 ~ 60`。
   - 格式：「`現在金額 / 最大上限 元`」（原版採黃金立體邊框字型）。
2. **底部出兵操作列 (Bottom Deploy Bar)**：
   - 佔用區域：`Y = 560 ~ 720`（底層黑色/紋理遮罩，高 160 像素）。
   - 左下角：工作狂貓錢包按鈕（`X = 20, Y = 580`，尺寸 `110 × 120` 像素），顯示當前錢包等級與升級所需花費。
   - 中央出兵卡牌區：
     - 上下兩排，每排 5 張卡牌（世界篇第一章標準解鎖下排 5 格）。
     - 單張卡牌尺寸：`96 × 68` 像素，間距 `12` 像素。
     - 卡牌冷卻覆蓋層：由下而上半透明灰色遮罩，隨冷卻進度垂直下降。
     - 金錢不足狀態：卡牌變暗反灰。
   - 右下角：貓咪砲按鈕（蓄力條滿時高亮發光，點擊發射全場雷射）。

---

## 五、受限資產與替代標籤規範 (Asset Substitution Protocol)

由於目前 `*.pack` 處於加密保護狀態（`BLOCKED`）：
1. **所有自製幾何形狀（方形、圓形、程序向量）必須在渲染層明確附加 `[BLOCKED_SUBSTITUTE]` 元數據標記**。
2. **UI 元素優先注入已解碼之 114 張官方原版 PNG**：
   - 按鈕圖標使用 `back.png`, `cancel.png`, `close.png`。
   - UI 底板使用 `bottom_bg01.png`, `charaname_bg01.png`。
   - 音效使用 `extracted_audio/` 內 25 個官方 `.ogg` 檔案。
3. **未解密之角色與城堡精靈**：
   - 在渲染器中採用嚴格符合原版比例的「標註式外觀邊界盒（Authentic Silhouette Bounding Box）」，保留原版中心錨點與物理尺寸，絕不宣稱視覺還原已完成。
