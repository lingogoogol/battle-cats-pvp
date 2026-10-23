# 《貓咪大戰爭》繁中版 v15.6.1 逆向工程資產清單 (INVENTORY.md)

- **目標檔案**：`E:\rea\catAPKPure.xapk`
- **套件名稱**：`jp.co.ponos.battlecatstw`
- **版本號**：Version Name `15.6.1` / Version Code `1506011`
- **目標 SDK**：`targetSdkVersion 36`, `minSdkVersion 24`
- **稽核時間**：2026-10-15
- **工作目錄**：`E:\rea`

---

## 一、 原始 XAPK 與 Split APK 清單

| 檔案相對路徑 | 原始大小 (Bytes) | SHA-256 雜湊值 | 說明 |
| :--- | :--- | :--- | :--- |
| `catAPKPure.xapk` | 157,271,732 | `d9c6451754edbc9622c20568cd4816060ded3bde347e7d188659c1024672a2e5` | APKPure 封裝之完整 XAPK 檔案 |
| `extracted_xapk\jp.co.ponos.battlecatstw.apk` | 28,146,315 | `c8784b44705e019179472614228fd6ad6aaff8de732b7cd6eb1ef3340c9edad8` | 核心主程式 (Base APK)，包含 DEX 與主要清單 |
| `extracted_xapk\config.arm64_v8a.apk` | 15,287,361 | `73ef3cf2c8e68ec43a7accea890fb2c5725919a23c0142f0293602474bf611ca` | 原生二進位函式庫 Split APK (ARM64-v8a) |
| `extracted_xapk\InstallPack.apk` | 113,481,180 | `b634243531e89aefa4a5d94e0377eb7dafafe61a1e7934ab3e6bc01988e9be44` | 遊戲核心資料包 Split APK (含 `.pack`、音效、著色器) |
| `extracted_xapk\config.en.apk` | 49,561 | `8a302f58f3b7be0a5d99f162ff1cf0b7babd543bfa9a1e030e018089164becea` | 英文語系配置 Split APK |
| `extracted_xapk\config.mdpi.apk` | 149,889 | `973b5596391197632337910212d7bef0801c40f265dc9c1efefd559aa0f5f7cc` | mdpi 螢幕解析度資源 Split APK |

---

## 二、 DEX 核心位元組碼清單

從 `jp.co.ponos.battlecatstw.apk` 提取出的 5 個 Dalvik Executable 檔案：

| DEX 檔案 | 大小 (Bytes) | SHA-256 雜湊值 | 類別範疇 |
| :--- | :--- | :--- | :--- |
| `classes.dex` | 7,602,308 | `35053311176bc4151d63fc75487227184b0cf102974c4bcfb904c24b79151e80` | Ponos 核心遊戲邏輯、UI、Android 架構組件 |
| `classes2.dex` | 205,704 | `d4616b35a4513f6d5519feaec1a2c429fff14fbe38fec4437dfb2d77c53f0b9f` | AndroidX 與啟動支援庫 |
| `classes3.dex` | 7,925,800 | `965ee392e8bc7a1d1aff1fc0b4b512e6a8d2d8e52836f478a862e34f41842cc2` | Google Play Services、Firebase、第三方 SDK |
| `classes4.dex` | 6,369,532 | `670f8c41cb1ffc2041593a087a02b6cc08b406ea85c5c65c45b4aea5d7bcf26a` | 廣告聚合庫 (AppLovin, IronSource, UnityAds, Tapjoy) |
| `classes5.dex` | 2,506,068 | `f3b4e4ec3dacb5891c106336eecf86b9faf89d157b177aa789986ceec87467e1` | 輔助網路協議與序列化模組 (Protobuf, gRPC 相關) |

---

## 三、 Native Library 清單 (`lib/arm64-v8a`)

從 `config.arm64_v8a.apk` 提取之 64 位元動態連結庫：

| 函式庫名稱 | 大小 (Bytes) | SHA-256 雜湊值 | 功能判定 |
| :--- | :--- | :--- | :--- |
| `libnative-lib.so` | 11,551,232 | `6f821c3cba94f96d34e1b2c501a482c0887daf71e68328722a58a456cb6baa0f` | **★ 遊戲核心引擎** (Ponos 自研 C++，OpenGL ES 渲染) |
| `libsigner.so` | 1,145,112 | `fb279ea3d929928055c8cb90e3a3c213939869a51ffafe6d587a072c530c5736` | 網路請求簽章與防篡改模組 |
| `libapplovin-native-crash-reporter.so` | 867,928 | `6b8a1c73a73b6d916921a46f6b99e3e1a93c13af1455e6f736dfa4757b644a51` | AppLovin 崩潰回報 |
| `libcrashlytics-common.so` | 864,616 | `2f759a20ed003c50ff4120f7ca3ee56e603bfba6f656fdb617136561bc409ef7` | Firebase Crashlytics 基礎模組 |
| `libcrashlytics-handler.so` | 222,056 | `064bb16f99de2ea43e9c4f5dc3e94f411b96fbed709149b266479774da7f3f7c` | Crashlytics 信號處理器 |
| `libcrashlytics.so` | 231,960 | `d1f4639c66971f821e356e629fcedbba4ad1395ab0e38d0ca3b5070e7283feb7` | Crashlytics NDK 主介面 |
| `libcrashlytics-trampoline.so` | 4,744 | `908e549f7a9b02f71ea0a4bcb77dfbf8dbc1123378da8fc384582fc7608159be` | Crashlytics 跳躍輔助庫 |
| `libdatastore_shared_counter.so` | 7,112 | `d3e48717c9aa147e0ab21063ba0e8e0211cabf8bf40b222640829519edbf58e1` | 共享計數器 |
| `libtapjoy.so` | 300,632 | `573f3b20fef1d7a5a86636b2a3525eaeedb1f2f48be2fd87e330a850ee5fb797` | Tapjoy 原生廣告庫 |

---

## 四、 遊戲資料包資產清單 (`assets/`)

從 `InstallPack.apk` 提取之核心資料包與索引表：

| 檔案名稱 | 大小 (Bytes) | SHA-256 雜湊值 | 格式說明 |
| :--- | :--- | :--- | :--- |
| `DataLocal.pack` | 8,724,672 | `0d51b44eb255afd0713a6f02c8a623648c9bb6b0e28cbe91627b675055a3e9bf` | 關卡、文字、全域設定加密資料包 (AES-128-ECB) |
| `DataLocal.list` | 267,344 | `a1231a21416defb2dc52bc67f7d27d5f512f0d51307a82af0cd04c89ec9dc9fe` | `DataLocal.pack` 內部子檔名、偏移與大小對照索引 |
| `UnitLocal.pack` | 919,840 | `990d8005442335680baf2d5ad9b38e2eb4beb55e989c6ce84370be9df2ee898f` | 貓咪與敵人單位屬性資料包 (加密) |
| `UnitLocal.list` | 9,024 | `5c4cb0715fbfe665dad33b45f196126eefbeda7d6bb213bc2b63aaf9960bc333` | `UnitLocal.pack` 索引檔 |
| `ImageDataLocal.pack` | 21,493,832 | `f5699a649abfdbecce7c4f7d56ea0948cd71189378c95b73b42474cc1a450e35` | 角色動作、圖塊、UI 貼圖包 (加密) |
| `ImageDataLocal.list` | 314,240 | `be7156b51f00a685c0c09114ba30c631161c2ff2fb68e5de12767dd3f9b67410` | `ImageDataLocal.pack` 索引檔 |
| `ImageLocal.pack` | 30,259,808 | `94105c57f4f9f05b914c467557ad02b7dc1bb8f97e0447846dbdb01075d9dffd` | 大圖背景、場景圖片資料包 (加密) |
| `ImageLocal.list` | 29,456 | `85723830b8bb42223adef6628d58ffa0cb39d58f33688853c7c831a8b88ede0e` | `ImageLocal.pack` 索引檔 |
| `MapLocal.pack` | 2,054,320 | `8b183a6fffeeea0e6c92578cb472e3bfbee06455eeb8f7073e2fc33858e9c84a` | 地圖資料包 (加密) |
| `MapLocal.list` | 41,840 | `daa8ef8bf3815751218a56326a0673ff6ce26d1d1359c392184058fa86934eb3` | `MapLocal.pack` 索引檔 |
| `NumberLocal.pack` | 3,582,960 | `b0c60f1473b3a73e4765fbc6f27a02c4d0fbb347d12443b9dadf8cb97eb486b1` | 數值對照表資料包 (加密) |
| `NumberLocal.list` | 6,128 | `642629353db6fcf39115f4222bc0e8cb38d0cbaa424305b74e4d32f27c939396` | `NumberLocal.pack` 索引檔 |
| `resLocal.pack` | 1,526,256 | `72b0d546dbd58185a45621ac3598d7a12342e068556f3f4dcd745148397d5f58` | 本機資源包 (加密) |
| `resLocal.list` | 42,416 | `478edd302c3a5648a650fdd128a7eab41f4244d0ba6dad1b7f8b5ff882478df9` | `resLocal.pack` 索引檔 |
| `DownloadLocal.pack` | 9,888 | `09ee3de04710c048a546813bc845b3157590c1c13707303143b1faf1baa36757` | 下載資源包 (加密) |
| `DownloadLocal.list` | 192 | `1b2b09c06327cd9a60ee47e4fcac5e8f6e0d9b74e0726e14979fa2846fe88696` | `DownloadLocal.pack` 索引檔 |
