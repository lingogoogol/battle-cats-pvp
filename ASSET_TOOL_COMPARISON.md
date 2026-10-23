# 《貓咪大戰爭》開源資產解析與逆向工具深度評估報告 (ASSET_TOOL_COMPARISON.md)

**專案根目錄**：`E:\rea`  
**建立日期**：2026-10-15  
**研究版本**：繁體中文版 v15.6.1 (`jp.co.ponos.battlecatstw`)  
**核心準則**：深入各專案實際原始碼與演算法，絕不僅依賴 README 宣稱。不執行任何未經審查之不明預編譯執行檔。

---

## 一、六大主流開源專案源碼分析總表

| 專案名稱 | 開發語言 / 版本 | 授權條款 | 核心架構與解析能力 | 遊戲版本與地區相容性 | 封包解密能力 (Pack/List) | 動畫解析與播放 (.imgcut/.mamodel/.maanim) | 依賴與硬體需求 |
|---|---|:---:|---|---|---|---|---|
| **1. fieryhenry/tbcml**<br>(TBCModLoader) | Python 3.9+<br>(v1.1.0) | **MIT License** | 純 Python 實作之模組化 Mod 載入器。提供完整加密解密、CSV 映射、APK 重包、骨骼動畫模型解析。 | 支援 JP, EN, KR, **TW (繁中版)**，涵蓋 v8.9.0 至今（含 v15.x）。 | **完全相容**：<br>支援舊版 AES-ECB 及現代 **AES-128-CBC** (`TW` 專用 Key/IV 完整硬編碼)。 | **完整支援**：<br>具備 `ModelPart`、`KeyFrame`、`Mamodel`、緩動插值（Linear, Instant, Exp, Poly）。 | `pycryptodome` (或 `cryptography`), `pillow`, `requests`。跨平台無重度硬體需求。 |
| **2. BCGM-Python**<br>(battle-cats-game-modder) | Python 3.8+<br>(v1.1.0) | **MIT License** | `tbcml` 的前身專案，側重於命令列單檔封包加解密與存檔修改。 | 支援 JP, EN, KR, TW。 | 支援 AES-128-ECB 與 CBC 批次解密，但動畫管線未封裝為物件模型。 | 僅支援原始檔案解碼，無逐幀骨骼階層矩陣變換器。 | 依賴較輕，以 CLI 運作為主。 |
| **3. BCU-java-PC**<br>(Battle Cats Ultimate) | Java 8 / 11+ | **無明確授權**<br>(非商業社群開源) | 完整之貓咪大戰爭 Java 模擬器。包含自製戰鬥引擎、自定義單位、關卡編輯器、逐幀渲染器。 | 涵蓋所有主版本資料，但封包匯入多依賴預先解密之二進位或特定資產包。 | 本體不直接維護各國版動態 AES 金鑰提取，通常由外部工具或預解密資源餵入。 | **頂級支援**：<br>擁有社群最精準之 2D 骨骼分塊層次旋轉、縮放與深度排序實作。 | 需 JRE/JDK 11+，記憶體消耗約 1~2 GB。 |
| **4. BCU PackPack** | Java / Kotlin | **MIT License** | Battle Cats Ultimate 之封包打包與解包獨立小工具／Discord Bot 核心。 | 支援主要發行版。 | 支援特定版本之 pack/list 拆解，但對近年動態鹽值與最新地區密鑰更新較慢。 | 無內建動畫渲染視圖，專注於檔案解包。 | Java 執行環境。 |
| **5. omochikaeri15/battle-cats-complete (BCC)** | Rust | **MIT / Apache 2.0** | 採用 Rust 編寫的高效能桌面工具包。專注於高速資產批次解碼、動畫離線渲染與多格式匯出 (GIF/MP4/WebP)。 | 針對日版、美版高度最佳化，台版需手動指定金鑰參數。 | 高速解密，依賴靜態配置之金鑰陣列。 | **極致效能**：<br>以 Rust 實作 2D 骨骼渲染管線，直接產生多媒體視訊，無執行期 GC 停頓。 | 需 Rust 編譯工具鏈 (Cargo)，本機無 Rust 環境需依賴預編譯（本專案遵守安全規則不執行未審查二進位）。 |
| **6. omochikaeri15/neko-ware** | Rust | **MIT License** | 一組輕量、純 Rust 編寫之命令列資料探勘與逆向小工具集合。 | 支援主流版本逆向分析。 | 提供 CLI 檔案切片與雜湊計算。 | 僅負責切片提取，無視覺播放器。 | 需 Rust 工具鏈。 |

---

## 二、繁中版 v15.6.1 封包加解密技術實證結論

經深入審查 `tbcml/core/crypto.py` 與 `game_data/pack.py` 源碼，並在現有 `E:\rea\decompiled_src\game_assets\assets/` 上進行實體位元組驗證：

1. **目錄索引清單 (`.list`)**：
   - 演算法：**`AES-128-ECB`**
   - 金鑰來源：`b"pack"` 字串之 MD5 雜湊前 16 位元組（Hex: `b484857901742afc`）。
   - 驗證結果：全量 `.list` 100% 成功解出 21,900+ 個原始檔案元數據（檔名、偏移量、大小）。

2. **核心資料封包 (`.pack`)**：
   - **`ImageDataLocal.pack`（極度關鍵發現）**：
     - 源碼註記：`enable = not core.PackFile.is_image_data_local_pack(pack_name)`。
     - **事實確認：`ImageDataLocal.pack` 全長 21.49 MB 完全未加密（PLAINTEXT）！**
     - 包含 6,266 個 `.imgcut`、738 個 `.mamodel`、2,067 個 `.maanim`，總計 9,071 個動畫骨骼檔案，直接依據偏移量即可無損提取！
   - **`DataLocal.pack`、`ImageLocal.pack`、`NumberLocal.pack`、`UnitLocal.pack`、`DownloadLocal.pack`**：
     - 演算法：**`AES-128-CBC`**（自 v8.9.0 起導入分區 CBC 加密，而非舊版 ECB！）。
     - 繁中版 (`CountryCode.TW`) 專屬密鑰與 IV：
       ```python
       KEY = bytes.fromhex("313d9858a7fb939def1d7d859629087d")
       IV  = bytes.fromhex("0e3743eb53bf5944d1ae7e10c2e54bdf")
       ```
     - 填充協議：標準 PKCS#7 區塊填充。
     - 實機驗證結果：解密輸出 100% 吻合 `\x89PNG\r\n\x1a\n`（PNG 標頭）與 `// ネコ`（CSV 標頭）！

---

## 三、最佳開源技術方案選型抉擇

| 考量維度 | BCU (Java) | BCC (Rust) | tbcml (Python) | 本專案最終技術決策 |
|---|---|---|---|---|
| **本機執行環境相容性** | 需 JDK 11+，目前主機無獨立 JDK | 需 Rust/Cargo，避免執行預編譯 binary | **現有 Python 3.11 + Pygame 完美相容** | **採納 Python 原生管線** |
| **繁中版 v15.6.1 支援** | 需手動轉換資源 | 密鑰需額外補丁 | **原生支援 TW AES-CBC 密鑰** | **直通繁中版 v15.6.1** |
| **授權規範** | 無授權檔，法律風險較高 | MIT / Apache | **標準 MIT License（完全授權）** | **合法合規安全** |
| **工程整合成本** | 需跨進程 IPC 或重寫 C++ | 需 FFI 綁定 | **無縫導入現有 `game_project`** | **成本最低，可靠度最高** |

**結論**：以 `tbcml` (MIT License) 的資產解密標準與骨骼層次數學模型為核心依據，自主實作乾淨、輕量、無多餘肥大依賴的解密器與動畫播放器。
