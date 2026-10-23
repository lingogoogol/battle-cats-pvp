# Phase 9 — Android 執行環境與架構限制研究報告 (RUNTIME_STATUS.md)

**主機作業系統**：Windows 11 (x86_64)  
**磁碟空間狀態**：C 槽剩餘 0.48 GB，E 槽剩餘 9.21 GB  
**目標架構**：`arm64-v8a` (ARM 64-bit Exclusive)  
**動態測試狀態**：**BLOCKED (動態執行阻塞)**

---

## 1. 深度環境與相容性技術調查

依據 Phase 9 P9-E 規範，詳細剖析在 Windows x86_64 主機上建置本專案測試環境之具體限制：

| 檢驗維度 | 核心瓶頸分析 | 潛在風險與技術結論 |
|---|---|---|
| **ABI 與架構相容性** | 遊戲的核心邏輯完全封裝於 `libnative-lib.so` (純 `arm64-v8a`)。一般 Windows x86_64 模擬器採原生 x86 虛擬化以確保流暢度。若要在 x86_64 運行 ARM64 原生庫，必須依賴二進位動態轉譯（如 Intel Houdini 或 Google `libndk_translation`）。 | 若直接在一般 x86_64 AVD 上啟動，將在 `System.loadLibrary("native-lib")` 時觸發 `java.lang.UnsatisfiedLinkError` 崩潰。 |
| **主機磁碟空間瓶頸** | C 槽僅剩 **0.48 GB**。Android 預設將 SDK、NDK、Gradle 快取及 AVD 儲存於 `C:\Users\<User>\.android\` 及 `C:\Users\<User>\AppData\Local\Android\`，強行安裝將導致 Host OS 藍屏死機。 | E 槽剩餘 9.21 GB，若部署 ARM64 系統映像檔 (約 4 GB 下載，解壓需 8 GB) 加上 AVD 寫入層 (8~16 GB)，將直接耗盡 E 槽可用空間。 |
| **ADB 工具本質定位** | 部署 Google 官方 Platform-Tools (`adb.exe`) 僅具備通訊與偵錯指令能力。 | **不得將「安裝 ADB」等同於「具備 Android 執行環境」**。ADB 本身不具備 Android 運行時或 ARM 虛擬機能力。 |
| **Split APK 簽章隔離** | `catAPKPure.xapk` 為 Split APK 架構 (`base.apk` + `config.arm64_v8a.apk` + `config.xxhdpi.apk`)。 | 必須全套重簽同一自製 Keystore 才能以 `adb install-multiple` 安裝，非 Root 環境下修改單一分包必然被簽章校驗阻擋。 |

---

## 2. 最佳化解決方案與後續測試路線圖

為在受限環境下推展研究，確立以下技術路線：

### 方案 A：實體機 USB 偵錯 (最推薦方案，避開 PC 磁碟與轉譯瓶頸)
- 準備一部具備 ARM64 架構之 Android 實體測試手機（需啟用開發人員選項與 USB 偵錯）。
- 在 E 槽安裝輕量化 Platform-Tools (`E:\rea\tools\platform-tools\`，僅佔用 20 MB)。
- 透過實體 USB 連線執行 `adb install-multiple`，完全免除 PC 端模擬器之巨額磁碟消耗與 ARM64 轉譯損耗。

### 方案 B：隔離式原生二進位模擬 (QEMU-AArch64 User-Mode)
- 利用輕量級 QEMU User-Mode（AArch64 靜態轉譯器）或 Unicorn Engine 載入 `libnative-lib.so`。
- 直接對 `Battle_ApplyDamageToUnit` (`0x004c6340`) 與 `Battle_GetUnitHP` (`0x0095987c`) 進行函式級隔離測試，無需啟動整個 Android 系統。

---

## 3. 現階段合規裁定

在未完成安全之 E 槽快取重導向或取得實體測試機前，**動態測試維持 BLOCKED**。所有研究以具備 100% 機器碼反組譯與單元測試之靜態等價模組繼續推展，確保研究過程誠實客觀。
