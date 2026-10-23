# 《貓咪大戰爭》v15.6.1 重建工程：客觀技術阻塞與邊界清單 (BLOCKERS.md)

**最後更新**：2026-10-15  
**專案根目錄**：`E:\rea`  
**核心準則**：所有無法在本機完全閉環的項目均誠實標記為 `BLOCKED`，禁止宣稱未經驗證之成果。

---

## 一、客觀外部阻塞項清冊 (External & Environmental Blockers)

### 1. [BLOCKER-01] 官方私有伺服器與付費交易
- **性質**：PONOS 官方私有端點、登入鑑權與 Google Play 結帳連線。
- **影響**：線上轉蛋抽卡、雲端存檔同步、官方伺服器即時推播。
- **處理策略**：嚴格限定於本機單機離線環境（Offline Local Sandbox），以本地 JSON 存檔管理器持久化進度，絕不嘗試連線或修改官方伺服器。

### 2. [BLOCKER-02] 核心加密封包資料區塊 (`.pack` Payloads)
- **性質**：`DataLocal.pack`、`ImageLocal.pack`、`ImageDataLocal.pack`、`UnitLocal.pack` 之動態 AES-128 密文。
- **影響**：雖然 `.list` 索引清單已 100% 解密，但原版 9,071 個動畫片段 (`.mamodel`, `.maanim`)、928 個背景精靈 (`bg059.png` 等) 與 8,905 個官方 CSV 數值區塊密鑰受限。
- **處理策略**：
  - 資產清冊標記為 **`BLOCKED`**。
  - 渲染層對所有自製圖元附加 **`[BLOCKED_SUBSTITUTE]`** 標籤，嚴禁宣稱原版素材已還原。
  - 預留動態金鑰注入介面，日後透過動態記憶體分析或使用者提供之明文無縫導入。

### 3. [BLOCKER-03] 官方實機標準參考截圖缺失 (Authentic Visual Baseline)
- **性質**：本地目錄 `E:\rea\references\official_v15_6_1/` 缺少繁中版 v15.6.1 實機標準 1280×720 無浮水印截圖。
- **影響**：無法進行真實原版逐像素對齊與色彩空間差分計算。
- **處理策略**：
  - 視覺評級標記為 **`BLOCKED_AWAITING_INPUT (0.0% Verified)`**。
  - 在 `compare_visuals.py` 生成的側並側比對圖中，以顯著紅色提示卡標示待提供規格與路徑。
  - 嚴禁使用 AI 繪圖、爬蟲模糊圖或自行繪製畫面冒充官方原版。

### 4. [BLOCKER-04] 主機 C 槽極限空間限制 (Critical Disk Space)
- **性質**：主機 C 槽剩餘空間低於 0.05 GB（臨界紅線）。
- **影響**：禁止任何寫入 C 槽之編譯、暫存或安裝大型 Android 模擬器行為。
- **處理策略**：
  - 所有環境變數強制重定向至 E 槽：`$env:TEMP = "E:\rea\temp"`, `$env:TMP = "E:\rea\temp"`, `$env:PIP_CACHE_DIR = "E:\rea\temp\pip_cache"`。
  - 嚴禁未經使用者授權刪除 C 槽既有檔案。

---

## 二、自主推進與已閉環項目 (Unblocked Operational Capabilities)

- **原生指令與記憶體多函式鏈驗證**：Phase 12 原生調用鏈 (Unicorn 10/10 PASS)。
- **解耦遊戲工程架構**：獨立 `audio`（25 個原版 OGG）、`assets`（114 個原版 PNG）、`render`、`simulation`、`ui`。
- **自動化回歸測試**：全套 6 大測試套件 (**100% PASS, 0 FAILURES**)。
- **十項維度側並側比對系統**：`compare_visuals.py` 自動生成標準比對圖檔。
