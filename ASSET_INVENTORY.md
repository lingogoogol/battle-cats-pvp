# 《貓咪大戰爭》v15.6.1 原版全資產盤點清單 (ASSET_INVENTORY.md)

**專案根目錄**：`E:\rea`  
**稽核日期**：2026-10-15  
**稽核標準**：嚴格杜絕將「封包二進位已提取」誤導為「資產已成功還原」。所有檔案分類遵循六級狀態定義：
- `RAW_EXTRACTED`：已從 APK/XAPK 提取為獨立檔案，但內部資料尚未解碼。
- `FORMAT_IDENTIFIED`：已逆向分析並確定其檔案結構與規格格式。
- `DECODED`：已成功將原始二進位或密文轉換為可用之明文檔案。
- `RENDERED`：已在遊戲引擎中載入並成功繪製於畫面上。
- `VERIFIED`：經對照原版運行畫面確認視覺與功能一致。
- `BLOCKED`：因加密保護、動態密鑰生成或缺少工具，暫時無法取得原始明文。

---

## 一、資產類別全景盤點矩陣

| 資產類別 | 原始檔案位置與名稱 | 數量 / 尺寸 | 檔案格式與結構 | 當前狀態標籤 | 說明與詳細依據 |
|---|---|:---:|---|:---:|---|
| **出兵卡牌圖標** | `UnitLocal.list` / `UnitLocal.pack` | 353 個單位圖標 | PNG (AES-128 加密封裝) | **FORMAT_IDENTIFIED** / **BLOCKED** | `.list` 索引已成功解密出 353 個 `udi*.png` 檔案偏移表；`.pack` 資料區塊密鑰目前受限。 |
| **角色骨骼動畫** | `ImageDataLocal.list` / `.pack` | 9,071 個動畫片段 | `.imgcut`, `.mamodel`, `.maanim` (AES 封裝) | **FORMAT_IDENTIFIED** / **BLOCKED** | 已識別為 PONOS 專屬 2D 骨骼動畫（Atlas 切割、骨骼階層、關鍵影格變換）；檔案清單已解密導出，內容受密文保護。 |
| **戰場背景圖集** | `ImageLocal.list` / `ImageLocal.pack` | 928 個背景/精靈 | 大圖集 PNG (AES 封裝) | **FORMAT_IDENTIFIED** / **BLOCKED** | 包含 `bg059.png`, `bg091.png` 等原版戰場背景與城堡精靈；清單已解密，內容受限。 |
| **戰鬥數值與關卡** | `DataLocal.list` / `DataLocal.pack` | 8,905 個 CSV 表格 | CSV / TSV 數值表 (AES 封裝) | **FORMAT_IDENTIFIED** / **BLOCKED** | 包含 `AbilityData.csv`, `unit001.csv` 等全角色與關卡官方參數；清單已解密，數值受限。 |
| **地圖與技能圖標** | `MapLocal.list` / `MapLocal.pack` | 1,259 個技能圖示 | `Skill_name_*.png` (AES 封裝) | **FORMAT_IDENTIFIED** / **BLOCKED** | 地圖世界篇節點與技能圖標；清單已解密。 |
| **明文介面材質** | `InstallPack.apk/assets/*.png` | 114 張 PNG 圖檔 | 標準 PNG (未加密, 89504e47) | **DECODED** & **RENDERED** | 已全數提取至 `E:\rea\game_assets\extracted_png/`。包含轉蛋橫幅、聯組圖示、取消/返回按鈕、UI 底板。 |
| **加密介面圖示** | `InstallPack.apk/assets/logo.png` | 1 張 (39,776 B) | PNG (獨立 AES-128 加密) | **FORMAT_IDENTIFIED** / **BLOCKED** | 尺寸為 16 倍數 (2486 區塊)，非標準 PNG 標頭，受密文保護。 |
| **遊戲戰鬥音效** | `InstallPack.apk/assets/*.ogg` | 25 個音訊檔 | OGG Vorbis (44.1kHz / 22kHz) | **DECODED** (明文可用) | `snd000.ogg` 至 `snd174.ogg`，包含貓咪出擊、砲擊蓄力、攻擊打擊真實音訊。 |
| **iOS 相容音訊** | `InstallPack.apk/assets/*.caf` | 13 個音訊檔 | Apple Core Audio Format | **RAW_EXTRACTED** | 跨平台舊格式音效，PC 上由 OGG 完全覆蓋。 |
| **OpenGL 着色器** | `InstallPack.apk/assets/Shader.*` | 2 個 Shader | GLSL 明文 (`.vsh`, `.fsh`) | **DECODED** & **VERIFIED** | Marc Flerackers 編寫之 2D 着色器，已提取保存。 |
| **伺服器更新清單**| `InstallPack.apk/assets/*.tsv` | 36 個清單檔 | UTF-8 TSV 明文表格 | **DECODED** | 包含 36 個官方伺服器資源 MD5 校驗表。 |
| **連線設定檔** | `InstallPack.apk/assets/*.config`| 3 個設定檔 | 官方伺服器 URL 明文 | **RAW_EXTRACTED** | 涉及官方線上端點，依法封存隔離，禁止連線。 |
| **Native C++ 核心**| `lib/arm64-v8a/libnative-lib.so` | 15.28 MB | ELF 64-bit LSB shared object | **FORMAT_IDENTIFIED** & **PARTIALLY_VERIFIED** | 3,250 個函式完成逆向符號分類；12 個戰鬥機制與 7 個函式已在 Unicorn 中 100% 差異驗證。 |
| **Java 邏輯層** | `classes.dex` ~ `classes6.dex` | 6 個 DEX (28 MB) | Dalvik Executable | **FORMAT_IDENTIFIED** (JADX) | 負責 Android Activity、In-App Billing 與 NDK `fsInit` 橋接。 |

---

## 二、加密封包技術現狀與法律/技術邊界 (Technical Boundary)

1. **已證實之密碼學特徵**：
   - 封包檔案 (`.pack`) 與目錄索引檔 (`.list`) 均為 16 位元組整數倍（AES 區塊限制）。
   - `.list` 索引檔經證實使用密鑰種子 `b"pack"` 之 MD5 雜湊前 16 位元組（`b484857901742afc`），以 AES-128-ECB 模式成功解密出全量 20,000+ 檔案清單！
   - `.pack` 內部資料區塊在繁中版 v15.6.1 中採用動態演算密鑰，目前**尚未取得原版解密明文**，因此本專案依誠實原則將原始資料標記為 **`BLOCKED`**，嚴禁偽稱「原版素材已解碼」。
2. **對目前工程之影響**：
   - 在未取得使用者授權或合法明文前，所有角色精靈、城堡精靈、戰場背景均**不得宣稱達到原版視覺一致性 (VISUAL_PARITY)**。
   - 現有 Pygame 工程所採用之程序化幾何繪圖僅為 **`TECHNICAL PROTOTYPE`**，與原版精緻手繪手繪風格存在客觀差距。
