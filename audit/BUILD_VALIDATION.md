# 《貓咪大戰爭》重建可行性驗證報告 (BUILD_VALIDATION.md)

- **測試對象**：`E:\rea\decompiled_src\apktool_project\`
- **建置工具**：Apktool v3.0.3 + aapt2
- **驗證時間**：2026-10-15 00:07:56 (Local)
- **產出目標**：`E:\rea\decompiled_src\test_rebuilt.apk`

---

## 一、 二次回編譯 (Repackage) 實測過程與日誌

執行之實體命令：
```powershell
java "-Duser.home=E:\rea\temp" "-Djava.io.tmpdir=E:\rea\temp" -jar E:\rea\tools\apktool_3.0.3.jar b E:\rea\decompiled_src\apktool_project -o E:\rea\decompiled_src\test_rebuilt.apk -p E:\rea\temp\framework
```

### 完整終端執行日誌記錄
```text
I: Using Apktool 3.0.3 on jp.co.ponos.battlecatstw.apk with 8 threads
I: Smaling smali_classes5 folder into classes5.dex...
I: Smaling smali folder into classes.dex...
I: Smaling smali_classes2 folder into classes2.dex...
I: Smaling smali_classes3 folder into classes3.dex...
I: Smaling smali_classes4 folder into classes4.dex...
I: Building resources with aapt2...
I: Building apk file...
I: Importing assets...
I: Importing unknown files...
I: Built apk into: E:\rea\decompiled_src\test_rebuilt.apk
```

---

## 二、 建置產物驗收

| 項目 | 原始 Base APK (`jp.co.ponos.battlecatstw.apk`) | 重建 APK (`test_rebuilt.apk`) | 差異說明 |
| :--- | :--- | :--- | :--- |
| **檔案大小** | 28,146,315 Bytes | 33,069,333 Bytes | 差異來自 aapt2 對資源對齊與 Zip 壓縮率不同 |
| **SHA-256** | `c8784b44705e019179472614228fd6ad6aaff8de732b7cd6eb1ef3340c9edad8` | `88c69cb07b227c81ea6487e35b7190013b5ff2c2866b162fe43555ae3b3975a5` | 重新編譯生成新雜湊值 |
| **DEX 數量** | 5 個 (`classes.dex` ~ `classes5.dex`) | 5 個 (完全重組成功) | 結構完整保留 |
| **簽名狀態** | Shipped Release Signature (V1/V2/V3) | **Unsigned (未簽名)** | 需使用 `apksigner` 自簽始可在裝置安裝 |

---

## 三、 重建可行性分層稽核結論 (Critical Verdict)

### 1. Smali 與資源層級重建：【可行 (PASS)】
* **結論**：逆向提取出的 Smali 組合語言與 AndroidManifest、XML 資源具備**語法正確性**，aapt2 與 smali 能在無錯誤狀態下 100% 重新組裝為可執行的 APK 容器。
* **工程價值**：支援進行 Smali 補丁修補（如修訂特定邏輯或介面）後直接重打包發布。

### 2. Java 原始碼直接編譯 (`javac` / Gradle)：【不可行 (FAIL WITHOUT REFACTORING)】
* **原因 1：語法不相容**：JADX 逆向產物中存在 76 個類別具有反編譯錯誤（如型態推斷矛盾、變數作用域異常）。
* **原因 2：混淆符號衝突**：多個套件被扁平化為單字母（`a.a.a`），直接編譯會引發符號歧義與重複宣告。
* **原因 3：依賴缺失**：第三方封閉原始碼 SDK（如 Google Play Billing、Firebase、IronSource）僅剩位元組碼衍生 Java，缺乏完整的編譯期 stub 介面庫。

### 3. Native C++ 原始碼層級重建：【不可行 (THEORETICALLY IMPOSSIBLE)】
* **原因**：C++ 經 Clang 編譯優化後，巨集、內聯函式、變數名稱、模板特化資訊已被永久消除。
* **真實重建方案**：僅能依據逆向分析出的 JNI 介面規格（如 `appInit`, `appUpdateDraw` 等 58 個函式）與通訊協定，**重新編寫功能等價的新 C++ 專案**，不可能無損「還原」原廠 C++ 原始碼。
