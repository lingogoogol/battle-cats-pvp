# Phase 10 — Android 執行期環境與本機轉譯可行性評估報告 (ANDROID_RUNTIME_ASSESSMENT.md)

**主機環境**：Windows 11 (x86_64)  
**磁碟狀態**：C 槽剩餘 **0.47 GB**，E 槽剩餘 **9.11 GB**  
**目標 ABI**：`arm64-v8a` (64 位元 ARM 原生庫)  
**動態驗證狀態**：**FULL_RUNTIME_PARITY = BLOCKED (明確標記)**

---

## 1. Windows 本機 Android 執行期方案全景評估

依據 Phase 10 10F 指令，全面盤點不依賴實體手機、於本機建立 Android 11 x86_64 運行時並具備 ARM 二進位轉譯能力之方案可行性：

| 方案名稱 | 運作原理與轉譯技術 | 磁碟空間需求 | 本機相容性與瓶頸評估 | 可行性判定 |
|---|---|---|---|:---:|
| **Google 官方 AVD 模擬器**<br>(Android Studio SDK) | 採用 x86_64 系統映像檔，內建 Google `libndk_translation` 將 AArch64 指令動態 JIT 轉譯至 x86_64。 | 下載 3.5 GB，解壓縮與 AVD 唯讀底層約 8 GB，建立寫入層需 8~16 GB（**總計需 15~20 GB**）。 | E 槽目前僅剩 **9.11 GB**，若強行部署將耗盡磁碟並觸發 I/O 死鎖；C 槽僅剩 0.47 GB，無法承擔 Android 預設組態。 | **不可行 (容量不足)** |
| **Windows Subsystem for Android (WSA)** | 微軟官方 Hyper-V 容器化子系統，內建 Intel Bridge Technology (IBT) 轉譯。 | 需 10 GB 以上，且 Appx 封裝強制綁定系統磁區（C 槽）。 | 微軟已於 2024 年終止支援，且無法將系統安裝目錄完全自 C 槽剝離，極易導致 Host OS 空間枯竭。 | **不可行 (技術淘汰/硬碟不足)** |
| **第三方模擬器**<br>(MuMu, BlueStacks, LDPlayer) | 自訂 VirtualBox / QEMU 內核，整合 Houdini 或 ndk_translation 轉譯器。 | 初始安裝需 4~6 GB，虛擬磁碟映像隨寫入膨脹至 10~20 GB。 | 安裝程式會強行向 `C:\ProgramData` 與 `C:\Users` 寫入數 GB 快取，具高度損壞 Host C 槽開機檔案之風險。 | **不可行 (高崩潰風險)** |
| **輕量化 CPU 模擬 (Unicorn Engine)**<br>*(Phase 10 已採用)* | 輕量化純 CPU 指令級模擬器，直接在 Python 內部載入 AArch64 機器碼，無需整個 Android OS。 | **僅需 50 MB**（已全部安裝於 `E:\rea\venv`，完全避開 C 槽）。 | 針對純演算法、記憶體讀寫、定點數運算區塊可達到 100% 原生模擬，無系統呼叫開銷。 | **已成功運作 (Phase 10C)** |

---

## 2. 磁碟空間與安全性防線

為保護使用者之作業系統安全，本專案嚴格遵守以下操作原則：
1. **嚴禁任何軟體向 C 槽寫入**：C 槽 0.47 GB 為作業系統虛擬記憶體分頁檔（pagefile.sys）之最低運作門檻，任何向 C 槽下載大型 Android 映像檔之行為皆被視為高危操作並嚴格禁止。
2. **所有快取與虛擬環境完全局限於 E 槽**：
   - Python 虛擬環境：`E:\rea\venv\`
   - Pip 快取：`E:\rea\temp\pip_cache\`
   - 逆向工程成果與測試：`E:\rea\phase10\`

---

## 3. 現階段合規裁定與後續建議

- **裁定聲明**：在未取得外部大容量儲存裝置或連接實體 ARM64 測試手機前，**FULL_RUNTIME_PARITY 維持標記為 BLOCKED**。
- **嚴正承諾**：絕不將「Unicorn 原生指令區塊測試通過（NATIVE_BLOCK_PARITY）」偽稱為「完整遊戲 APK 執行期等價（FULL_RUNTIME_PARITY）」。兩者等級明確切分，確保工程誠實性。
