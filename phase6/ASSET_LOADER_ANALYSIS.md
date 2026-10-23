# 《貓咪大戰爭》資產載入路徑與加密機制分析 (ASSET_LOADER_ANALYSIS.md)

- **目標二進位**：`libnative-lib.so`
- **對應模組**：檔案系統橋接器 (`fsInit`) 與封包目錄管理器 (`0x006f74a0`)
- **分析方法**：Capstone ARM64 反組譯、十六進位結構稽核與 NDK Asset API 調用追蹤

---

## 一、 資產橋接初始化路徑 (fsInit)

從 Java 層傳遞 Android 原生 `AssetManager` 至 C++ 核心之流程如下：

```arm64
; Java_jp_co_ponos_battlecats_MyActivity_fsInit (0x00309e10)
0x00309e10:  mov   x1, x2              ; 取得 Java AssetManager 物件引用
0x00309e14:  b     #0x450dc8           ; 跳轉至 AssetManager 註冊函式

; AssetManager 註冊常式 (0x00450dc8)
0x00450dc8:  stp   x29, x30, [sp, #-0x10]!
0x00450dd0:  bl    #0xac56c0           ; 調用 NDK AAssetManager_fromJava(env, jobject)
0x00450dd4:  adrp  x8, #0xb0d000
0x00450dd8:  str   x0, [x8, #0x238]    ; 將 AAssetManager* 指標儲存於全域 0xb0d238
0x00450ddc:  ldp   x29, x30, [sp], #0x10
0x00450de0:  ret
```

經此流程後，原生層正式取得直接存取 APK 內部 `assets/` 目錄的句柄。

---

## 二、 核心資料封包目錄註冊機制 (`0x006f74a0`)

在遊戲初始化時，二進位代碼透過 `0x006f74a0` 構建靜態封包目錄表（Asset Archive Table）：

```arm64
; 核心封包目錄註冊片段 (0x006f74a0 - 0x006f7654)
0x006f74c0:  adrp  x9, #0x18b000
0x006f74c4:  add   x9, x9, #0xcb5      ; 載入字串 "DataLocal.pack" (0x0018bcb5)
...
0x006f7628:  adrp  x9, #0x18f000
0x006f762c:  add   x9, x9, #0xec3      ; 載入字串 "UnitLocal.list" (0x0018fec3)
...
0x006f7648:  adrp  x9, #0x1a7000
0x006f764c:  add   x9, x9, #0xb50      ; 載入字串 "UnitLocal.pack" (0x001a7b50)
```

在此函式中，系統將 `DataLocal`, `UnitLocal`, `ImageDataLocal`, `ImageLocal`, `MapLocal`, `NumberLocal`, `resLocal` 依序加入內部陣列，為每個封包配置一個解碼上下文結構。

---

## 三、 `.pack` 與 `.list` 加密機制實證

1. **對齊特徵 (Alignment)**：
   經十六進位檢驗，全部 `.list` 與 `.pack` 檔案尺寸皆為 **16 位元組之整數倍**：
   - `DownloadLocal.list`：192 Bytes = $12 \times 16$
   - `UnitLocal.list`：9,024 Bytes = $564 \times 16$
   - `DataLocal.list`：267,344 Bytes = $16,709 \times 16$
   - `DataLocal.pack`：8,724,672 Bytes = $545,292 \times 16$
2. **密碼學模式 (Cipher Mode)**：
   高階統計頻率與區塊重複分析證實採用 **AES-128-ECB 模式**（因其不具 IV 向量，故相同明文區塊產生相同密文特徵）。
3. **未解密阻塞原因 (Blocker)**：
   解密金鑰由 `libnative-lib.so` 在執行時動態計算（依據特定字串之 MD5 雜湊）。在未動態 Hook 記憶體或完整提取靜態金鑰前，這些封包無法直接轉為明文 CSV 檔案。
