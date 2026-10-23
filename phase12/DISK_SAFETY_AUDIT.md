# Phase 12 — 磁碟空間安全防護與暫存重導向稽核報告 (DISK_SAFETY_AUDIT.md)

**稽核日期**：2026-10-15  
**主機作業系統**：Windows 11 (x86_64)  
**磁碟當前狀態**：
- **C 槽可用空間**：**0.11 GB** (極端緊繃狀態，瀕臨臨界值)
- **E 槽可用空間**：**9.93 GB** (空間相對充足)

---

## 1. 暫存路徑盤點與重導向防護措施

為徹底根除後續分析、編譯、直譯器與工具向 C 槽寫入暫存檔導致系統崩潰的風險，全專案採取**強制重導向至 E 槽**之保護策略：

| 工具與執行環境 | 預設寫入路徑 (C 槽) | 重導向至安全路徑 (E 槽) | 配置方式與環境變數 |
|---|---|---|---|
| **系統全域暫存 (TEMP / TMP)** | `C:\Users\<User>\AppData\Local\Temp` | `E:\rea\temp` | `$env:TEMP = "E:\rea\temp"`<br>`$env:TMP = "E:\rea\temp"` |
| **Python 字節碼快取 (__pycache__)** | 各腳本同級目錄或預設快取 | `E:\rea\temp\pycache` | `$env:PYTHONPYCACHEPREFIX = "E:\rea\temp\pycache"` |
| **Python 包管理器 (Pip)** | `C:\Users\<User>\AppData\Local\pip\cache` | `E:\rea\temp\pip_cache` | `--cache-dir E:\rea\temp\pip_cache`<br>`$env:PIP_CACHE_DIR = "E:\rea\temp\pip_cache"` |
| **Java 虛擬機 (Ghidra / JVM Temp)** | `C:\Users\<User>\AppData\Local\Temp` | `E:\rea\temp` | `$env:_JAVA_OPTIONS = "-Djava.io.tmpdir=E:\rea\temp"` |
| **Ghidra 專案與分析快取** | 預設使用者目錄 | `E:\rea\phase7\ghidra_proj` | 所有專案檔、日誌與匯出完全限定在 E 槽 |
| **Python 虛擬環境 (Venv)** | `C:\Users\<User>\AppData\...` | `E:\rea\venv` | 完整 site-packages 與執行檔均位於 E 槽 |

---

## 2. 工具與虛擬環境寫入行為安全檢查

1. **虛擬環境檢查 (`E:\rea\venv`)**：
   - 經檢查，Python 3.11 虛擬環境直接建立於 `E:\rea\venv`，包含 Unicorn 2.1.4 與 Capstone 5.0.7 之輪子與動態庫，執行過程中對 C 槽之寫入為 **0 bytes**。
2. **二進位提取與測試日誌**：
   - Phase 10、Phase 11、Phase 12 之 `native_emulation`、`combat_engine`、`evidence_bundle` 產物全部寫入 `E:\rea\phase12\`，未觸及 C 槽。

---

## 3. C 槽潛在可清理快取候選清單（供使用者評估，未獲同意前絕不刪除）

依據規範，嚴禁任意刪除系統檔案或專案資產。以下為透過安全掃描識別之外部快取目錄（合計約 **3.03 GB**）：

| 候選快取目錄路徑 | 佔用容量 (MB) | 內容用途說明 | 清理風險等級與建議 |
|---|---|---|---|
| `C:\Users\吳建廷\.cache` | **1,469.20 MB** (~1.47 GB) | 第三方開發工具、pip、huggingface 等外部快取檔案 | **低風險**：僅為下載暫存，若需釋放空間可由使用者確認後清理。 |
| `C:\Users\吳建廷\.gradle` | **1,197.26 MB** (~1.20 GB) | 歷史 Gradle 建置快取與 wrapper 檔案 | **低風險**：僅為 Android/Java 舊建置快取，下次建置會重下載。 |
| `C:\Users\吳建廷\AppData\Local\Temp` | **272.63 MB** | Windows 系統各應用程式殘留暫存檔 | **極低風險**：可透過 Windows 磁碟清理工具安全清除。 |
| `C:\Users\吳建廷\.nuget` | **92.55 MB** | .NET NuGet 套件本機快取 | **低風險**：重編譯 .NET 時可重新取得。 |
| `C:\Users\吳建廷\.android` | **3.45 MB** | Android AVD/ADB debug key 設定 | **不建議清理**：包含除錯金鑰與組態。 |

> [!CAUTION]
> **本專案承諾**：
> 1. 上述清單僅供使用者參考，在取得使用者明確指示前，**Antigravity 絕不擅自刪除任何上述項目**。
> 2. 嚴格保護 `E:\rea` 下所有原始 APK (`catAPKPure.xapk`)、原始 SO (`libnative-lib.so`)、Ghidra 專案及 Phase 1 ~ 11 之所有報告與測試產出。
> 3. 後續工作嚴格限制於已配置的 E 槽環境中進行，不下載大型模擬器映像檔。
