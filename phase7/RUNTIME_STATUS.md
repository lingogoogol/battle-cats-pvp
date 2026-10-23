# Phase 7 — Android 執行環境調查與動態測試狀態 (RUNTIME_STATUS.md)

**執行環境調查基準：**
- 作業系統：Windows 11 (Host)
- 磁碟空間狀態：C 槽剩餘 0.48 GB，E 槽剩餘 9.22 GB
- 分析目標：`catAPKPure.xapk` (繁中版 v15.6.1, Split APK 架構)
- 測試狀態：**BLOCKED (動態執行阻塞)**

---

## 1. 執行環境組態與阻塞因素審查 (Obstacle Audit)

依據 Phase 7 P7-E 之規範，全面盤點本機動態測試所需的各項依賴與當前阻礙原因：

| 檢驗項目 | 當前狀態 | 阻塞等級 | 詳細原因分析 |
|---|---|---|---|
| **Android SDK Platform-Tools (ADB)** | **未安裝 / 缺失** | **CRITICAL** | 系統 PATH 與 E 槽均無 `adb.exe`。無法執行 `adb devices`、`adb install-multiple` 或 Logcat 監控。 |
| **ARM64 執行實體 (Emulator / Device)** | **無可用實體** | **CRITICAL** | 本機未運行任何 Android 模擬器 (BlueStacks, LDPlayer, MuMu 或 Android Studio AVD)，亦無透過 USB 啟用偵錯之 ARM64 實體手機。 |
| **主機磁碟空間瓶頸** | **高度受限** | **HIGH** | C 槽僅剩 **0.48 GB**。標準 Android Studio AVD 建立系統映像檔需至少 8~15 GB 磁碟空間，強行在 C 槽建立將引發 Host OS 崩潰。 |
| **Split APK 簽章與安裝架構** | **結構隔離** | **HIGH** | 遊戲為 App Bundle Split APK (`base.apk` + `config.arm64_v8a.apk` + `config.xxhdpi.apk`)。若僅重組 `base.apk` 並以 Debug 密鑰簽章，將因與其餘 Split APK 密鑰不符觸發 `INSTALL_PARSE_FAILED_INCONSISTENT_CERTIFICATES`。 |
| **二進位架構相容性** | **嚴格 ARM64** | **MEDIUM** | `libnative-lib.so` 僅提供 `arm64-v8a`，常見的 x86_64 PC 模擬器若無 ARM 轉譯器 (如 libndk_translation / Houdini) 將在 JNI 載入時觸發 `java.lang.UnsatisfiedLinkError`。 |

> **結論判定：**
> 依據原則「**若目前沒有可用的 ARM64 執行環境，明確列出阻塞原因及下一步，不得假裝完成動態測試**」，目前動態啟動與 Logcat 截圖測試狀態判定為 **BLOCKED**。任何宣稱已在 Android 模擬器內啟動成功之說法均屬捏造，在此嚴格予以排除。

---

## 2. Split APK 完整測試標準作業程序 (SOP)

為使未來具備實機或模擬器環境時能立即重現測試，制定以下完整部署指令流程：

### 步驟 1：部署 Platform-Tools (至 E 槽)
```powershell
# 下載 Google 官方 platform-tools 至 E:\rea\tools\
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/platform-tools-latest-windows.zip" -OutFile "E:\rea\tools\platform-tools.zip"
Expand-Archive -Path "E:\rea\tools\platform-tools.zip" -DestinationPath "E:\rea\tools\"
$env:PATH += ";E:\rea\tools\platform-tools"
```

### 步驟 2：Split APK 全包批次重簽章 (Batch Re-signing)
為防止簽章不一致導致安裝失敗，所有 Split 分包必須使用同一個 Keystore 重新簽署：
```powershell
# 產生測試金鑰
keytool -genkeypair -v -keystore E:\rea\test.keystore -alias testkey -alg RSA -keysize 2048 -validity 10000 -storepass password -keypass password -dname "CN=Test, OU=Dev, O=REA, L=Taipei, ST=Taiwan, C=TW"

# 對所有 Split 分包執行 zipalign 與 apksigner
apksigner sign --ks E:\rea\test.keystore --ks-pass pass:password --out E:\rea\signed\base.apk E:\rea\unpacked\base.apk
apksigner sign --ks E:\rea\test.keystore --ks-pass pass:password --out E:\rea\signed\config.arm64_v8a.apk E:\rea\unpacked\config.arm64_v8a.apk
apksigner sign --ks E:\rea\test.keystore --ks-pass pass:password --out E:\rea\signed\config.xxhdpi.apk E:\rea\unpacked\config.xxhdpi.apk
```

### 步驟 3：多分包聯合原子安裝 (Atomic Multiple Installation)
```powershell
adb install-multiple E:\rea\signed\base.apk E:\rea\signed\config.arm64_v8a.apk E:\rea\signed\config.xxhdpi.apk
```

### 步驟 4：Logcat 即時監視與崩潰堆疊擷取
```powershell
adb logcat -c
adb shell monkey -p jp.co.ponos.battlecatstw -c android.intent.category.LAUNCHER 1
adb logcat -s "BattleCats" "DEBUG" "AndroidRuntime"
```

---

## 3. 現有資產與原始二進位保護確認

- 原始 XAPK (`E:\rea\catAPKPure.xapk`)：已驗證未被覆寫，SHA-256 保持原始雜湊。
- 解開之 APK 分包與 Native `.so`：均處於 `E:\rea\decompiled_src\` 唯讀工作副本，原始資料受完整防護。
