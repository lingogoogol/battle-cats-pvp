# 《貓咪大戰爭》遊戲資產與格式分析報告 (ASSET_ANALYSIS.md)

- **資產根目錄**：`E:\rea\decompiled_src\game_assets\assets\`
- **分析範圍**：255 個資產檔案、8 組核心 `.pack` / `.list` 資料包、GLSL 著色器與音訊資源
- **稽核規範**：嚴格區分「已解碼明文格式」與「加密封包資料」，禁止宣稱未解密資料為已還原。

---

## 一、 資產分類總覽

遊戲中的資產分為兩大類：
1. **直接可讀取資產 (Directly Accessible Assets)**：明文儲存於 APK `assets/` 根目錄，不需金鑰解密。
2. **受保護的加密封包 (Encrypted Pack Archives)**：成對出現的 `.pack` 與 `.list` 檔案，需經由 `libnative-lib.so` 解密與解包。

---

## 二、 直接可讀取資產驗收 (100% 明文還原)

### 1. OpenGL ES 著色器 (`.vsh`, `.fsh`)
- [`assets/Shader.vsh`](file:///E:/rea/decompiled_src/game_assets/assets/Shader.vsh)：頂點著色器 (Vertex Shader, GLSL)
  - 核心變數：`attribute vec2 position`, `attribute vec4 color`, `attribute vec2 uv`
  - 轉換矩陣：`uniform mat4 projection`, `uniform mat4 modelview`
  - 渲染計算：`gl_Position = projection * modelview * vec4(position, 0.0, 1.0);`
- [`assets/Shader.fsh`](file:///E:/rea/decompiled_src/game_assets/assets/Shader.fsh)：片段著色器 (Fragment Shader, GLSL)
  - 紋理取樣：`texture2D(texture, uvVarying) * colorVarying`

### 2. 音訊資源 (`.ogg`, `.caf`)
- 共收錄 **42 個音訊檔案**，總計約 55 MB。
- **背景音樂 (BGM)**：採用標準 Ogg Vorbis 編碼（如 `snd000.ogg` 主題曲 2.07 MB、`snd178.ogg` 戰鬥曲 2.56 MB），任何播放器皆可直接播放。
- **打擊與介面音效 (SFX)**：採用 Core Audio Format (`.caf`)，對應攻擊、升級、按鈕音效。

### 3. Web UI 與純文字設定
- 網頁介面：`charaname.html`, `user_info.html`, `slotname.html`, `style.css`。
- 設定檔案：`remote_config_defaults.json`, `camp_url.config`。

---

## 三、 受保護的 `.pack` 與 `.list` 格式深層分析

遊戲全部核心業務數據（關卡、數值、怪物能力、抽卡池、動畫骨架）皆儲存於以下 8 組封包中：

| 封包主檔 (`.pack`) | 索引清單 (`.list`) | 封包大小 (Bytes) | 索引大小 (Bytes) | 內部包含之邏輯資產 (依 C++ 符號) |
| :--- | :--- | :--- | :--- | :--- |
| `DataLocal.pack` | `DataLocal.list` | 8,724,672 | 267,344 | `AbilityData.csv`, `All_day_event.tsv`, `CC_*.csv` (關卡與城堡數值) |
| `UnitLocal.pack` | `UnitLocal.list` | 919,840 | 9,024 | 貓咪與敵人單位狀態 (HP、攻擊力、射程、攻速、升級金幣) |
| `ImageDataLocal.pack` | `ImageDataLocal.list` | 21,493,832 | 314,240 | 戰鬥單位精靈圖塊與動畫切割資料 (maanim, mamodel) |
| `ImageLocal.pack` | `ImageLocal.list` | 30,259,808 | 29,456 | 全景地圖、大張選單圖、活動圖 |
| `MapLocal.pack` | `MapLocal.list` | 2,054,320 | 41,840 | 世界篇、未來篇、宇宙篇關卡地圖組態 |
| `NumberLocal.pack` | `NumberLocal.list` | 3,582,960 | 6,128 | 數值表、多語系文字對照 |
| `resLocal.pack` | `resLocal.list` | 1,526,256 | 42,416 | 本地字體、UI 元件佈局 |
| `DownloadLocal.pack` | `DownloadLocal.list` | 9,888 | 192 | 額外下載資產臨時清單 |

### 封包結構與防護機制
1. **區塊對齊特徵**：
   經十六進位檢驗，所有 `.pack` 與 `.list` 檔案長度皆嚴格對齊 16 位元組（AES 區塊大小，如 `DownloadLocal.list` 為 192 bytes = 12 × 16）。
2. **索引機制 (`.list`)**：
   `.list` 解密後為結構化二進位或 CSV 文字表，包含多筆記錄：`[檔名 (UTF-8/ASCII)] [在 .pack 中的起始 Offset] [檔案大小 Length]`。
3. **加解密演算法**：
   由 `libnative-lib.so` 中的資產子系統在呼叫 `AAssetManager_open` 載入記憶體後，經由自研/標準 AES-128-ECB 演算法進行解密。

---

## 四、 嚴格審計判定 (Audit Verdict)

> [!CAUTION]
> **真實還原狀態認定**：
> 雖然已完整提取出全部 `.pack` 與 `.list` 二進位檔案（總計約 108 MB），但**在未執行解密演算法解出內部個別 CSV、TSV 與 PNG 之前，這些核心數據仍處於「加密封存狀態」**。
> 本次稽核**不得且絕不**宣稱這些封包內的數千個內部 CSV 檔案已無損解碼還原。
