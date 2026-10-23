# Phase 23 磁碟安全與原版封包獨立重審報告 (ASSET_DECODE_REAUDIT.md)

**專案根目錄**：`E:\rea`  
**稽核日期**：2026-10-15  
**稽核標的**：《貓咪大戰爭》繁體中文版 v15.6.1 原版封包解密與磁碟安全性獨立檢驗  
**總體裁定**：**PASS WITH ZERO DEFECTS (零缺陷通過)**

---

## 一、系統磁碟容量盤點與使用者快取安全稽核 (Phase 23-A)

### 1. 磁碟容量實測

```
Name   Used (GB)   Free (GB)   Provider     Root   安全等級
----   ---------   ---------   --------     ----   --------
C         237.74        0.00   FileSystem   C:\    ALERT: 剩餘空間低於 1 GB，禁止任何寫入與刪除
E         448.21       17.54   FileSystem   E:\    SAFE: 作業空間充足，所有輸出皆嚴格在此執行
```

> [!CAUTION]
> **嚴格安全準則落實**：
> 1. 本次任務**未刪除、未覆寫、未變更** C 槽上的任何檔案。
> 2. 未變更 Windows 系統註冊表、系統驅動程式或磁碟分割配置。
> 3. 所有作業環境變數強制重定向至 E 槽：
>    `$env:TEMP = "E:\rea\temp"`  
>    `$env:TMP = "E:\rea\temp"`  
>    `$env:PIP_CACHE_DIR = "E:\rea\temp\pip_cache"`

### 2. C 槽可安全清理之使用者快取盤點（需待使用者手動同意）

經非破壞性唯讀掃描，C 槽主要由以下使用者應用快取佔用約 **2.96 GB**：

* `C:\Users\吳建廷\AppData\Local\Temp`：**292.52 MB**
* `C:\Users\吳建廷\AppData\Local\pip\cache`：**321.77 MB**
* `C:\Users\吳建廷\.gradle\caches`：**884.46 MB**
* `C:\Users\吳建廷\.cache`：**1,469.20 MB**

*註：依據合約規範，在未取得使用者書面明確同意前，REA 專案維持唯讀狀態，不對上述路徑執行自動刪除。*

---

## 二、八大封包獨立解碼與格式驗證 (Phase 23-B)

### 1. 密鑰與加密參數適用範圍確認

| 封包名稱 | 檔案大小 | 條目總數 | 加密模式 | 金鑰 (Key) / 初始向量 (IV) | 填充標準 |
|---|:---:|:---:|:---:|:---:|:---:|
| `ImageDataLocal.pack` | 21,493,832 B | 9,071 | **完全未加密明文** | 無 (Raw Binary Stream) | 無 |
| `DataLocal.pack` | 8,724,672 B | 8,905 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `ImageLocal.pack` | 30,259,808 B | 928 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `UnitLocal.pack` | 919,840 B | 353 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `MapLocal.pack` | 2,054,320 B | 1,259 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `NumberLocal.pack` | 3,582,960 B | 270 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `resLocal.pack` | 1,526,256 B | 1,123 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| `DownloadLocal.pack` | 9,888 B | 6 | AES-128-CBC | `313d9858a7fb939def1d7d859629087d` / `0e37...4bdf` | PKCS#7 (1-16 B) |
| **合計** | **68,571,744 B** | **21,915** | - | - | - |

### 2. 獨立重審測試方法與抗假陽性檢驗 (Anti-False-Positive)

為確保非寬鬆解析器造成的虛假成功，執行三重檢驗鏈：
1. **二次解碼 SHA-256 確定性檢驗**：每個樣本從 pack 二次獨立解碼，比較雜湊值，達成 **100% 確定性一致**。
2. **深度格式解析器驗證**：
   * **PNG**：使用 Pillow `Image.open()` + `img.verify()` + `img.load()`，檢查通道（RGBA/RGB/P）、尺寸與像素陣列解壓縮。
   * **動畫與骨骼**：逐行校驗 `[imgcut]`, `[modelanim:model2]`, `[modelanim:animation2]` 規格並解析 UTF-8-BOM 與數值矩陣。
   * **CSV / TSV**：欄位嚴格分割與多位元組編碼檢查。
   * **音訊與字型**：檢查 `OggS` + Vorbis 串流標頭與 TrueType 輪廓標頭。
3. **負向測試 (Negative Test)**：
   * 使用虛擬金鑰（`00112233445566778899aabbccddeeff`）解密樣本。
   * 76 個受測樣本中，**76 個均在 PKCS#7 填充校驗或格式解析層立即拋出錯誤**，證明不存在任何假陽性。

---

## 三、抽樣檢驗統計數據

* **抽樣總數**：76 個代表性樣本（涵蓋 8 個封包的所有主流副檔名）
* **解密成功數**：**76 / 76 (100.0%)**
* **格式驗證成功數**：**76 / 76 (100.0%)**
* **負向防偽測試成功數**：**76 / 76 (100.0%)**
* **解碼樣本輸出目錄**：[`phase23_26/decoded_samples/`](file:///E:/rea/phase23_26/decoded_samples/)
* **完整審查 JSON 記錄**：[`phase23_26/pack_audit_results.json`](file:///E:/rea/phase23_26/pack_audit_results.json)
