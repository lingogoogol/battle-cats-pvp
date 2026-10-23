# 《貓咪大戰爭》Android 運行時環境與實機測試報告 (ANDROID_RUNTIME_TEST.md)

- **測試主機環境**：Windows x64
- **待測標的**：`E:\rea\decompiled_src\test_rebuilt.apk` (33,069,333 Bytes)
- **目標 ABI**：`arm64-v8a` (64 位元 ARM 架構)
- **目標 SDK 要求**：`minSdkVersion 24` (Android 7.0+), `targetSdkVersion 36`
- **稽核時間**：2026-10-15 01:24:30 (Local)

---

## 一、 測試前置環境檢驗 (Pre-flight Inspection)

### 1. ADB 橋接與終端環境
- **執行指令**：`Get-Command adb` / `adb devices`
- **檢驗結果**：
  ```text
  CommandNotFoundException: 無法將 'adb' 辨識為 Cmdlet、函數、指令檔或可執行程式的名稱。
  ```
- **判定**：本機未安裝 Android SDK Platform-Tools，`PATH` 中無 `adb.exe`。

### 2. 連接設備與模擬器檢測
- **檢驗結果**：未偵測到任何執行中的本機 Android 模擬器（如 Google AVD、雷電、夜神）或 USB 實體 Android 偵錯設備。

### 3. 重建 APK 簽章狀態
- **待測檔案**：`E:\rea\decompiled_src\test_rebuilt.apk`
- **簽章狀態**：**Unsigned (未簽名)**。
- **Android 系統要求**：Android 套件管理器（PackageManagerService）強制要求所有安裝的 APK 必須具有有效的 V2/V3 簽名，未簽名 APK 無法被任何實體設備安裝。

### 4. Split APK 架構約束
- 原始應用程式採用 Google Play Feature Split 架構：
  - `jp.co.ponos.battlecatstw.apk`：僅含 Base DEX 與基本 Manifest。
  - `config.arm64_v8a.apk`：包含 `libnative-lib.so`。
  - `InstallPack.apk`：包含 `DataLocal.pack` 等遊戲資產。
- 若僅安裝 `test_rebuilt.apk`（單一 Base APK），執行時將立即觸發 `java.lang.UnsatisfiedLinkError: Couldn't load native-lib` 崩潰。

---

## 二、 運行測試矩陣與狀態判定 (Test Execution Matrix)

依據驗收標準：「**無法執行的測試標記 BLOCKED，不得宣稱 PASS**」，各階段實測結論如下：

| 測試階段 | 預期驗證行為 | 實測狀態 | 阻塞根因 (Blocking Reason) |
| :--- | :--- | :--- | :--- |
| **1. APK 簽名驗證** | 使用 `apksigner verify` 檢查認證 | **【BLOCKED】** | APK 為 Apktool 產物，尚未注入 Debug/Release Keystore 簽章 |
| **2. 設備安裝 (Install)** | `adb install-multiple` 或 `pm install` | **【BLOCKED】** | 本機環境無可用 ADB 服務或連接之 Android 設備 |
| **3. 冷啟動 (Cold Launch)** | `am start -n jp.co.ponos.battlecats/.MyActivity` | **【BLOCKED】** | 無執行環境，未建立 Dalvik/ART 虛擬機 |
| **4. 進入遊戲選單 (Menu)** | 觀察初始資源解鎖與選單畫面 | **【BLOCKED】** | 依賴啟動測試，受前項連帶阻塞 |
| **5. 進入戰鬥場景 (Battle)** | 點擊關卡、載入單位與觸發戰鬥迴圈 | **【BLOCKED】** | 依賴選單測試，受前項連帶阻塞 |

---

## 三、 後續解鎖測試之必要前置條件

若需在未來的階段中完成實機動態執行，必須依序準備：
1. 配置包含 `adb.exe` 的 Android SDK 環境。
2. 啟動支援 `arm64-v8a` 的 Android 模擬器或連接實體手機（需開啟 USB 偵錯）。
3. 使用 `keytool` 與 `apksigner` 對 `test_rebuilt.apk` 進行自簽：
   ```powershell
   apksigner sign --ks debug.keystore --ks-pass pass:android test_rebuilt.apk
   ```
4. 將 `config.arm64_v8a.apk` 中的原生 `.so` 檔案與 `InstallPack.apk` 中的資產合併封裝，以解決 Split APK 缺少 Native 庫的鏈結崩潰。
