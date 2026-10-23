# 《貓咪大戰爭》Native 函式與位址映射表 (NATIVE_FUNCTION_MAP.md)

- **目標二進位**：`E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so`
- **架構**：ARM64 (AArch64 Little-Endian)
- **分析工具**：Capstone 5.0.9 + pyelftools
- **分析範圍**：JNI 導出層、應用程式單例層、資產載入層與核心運算層

---

## 一、 核心導出函式與內部調用映射表

| 層級 | 符號名稱 / 內部位址 | 虛擬位址 (VMA) | 尺寸 (Bytes) | 內部關鍵調用目標 (Callees) | 經證實職責 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **JNI 入口** | `MyActivity_appInit` | `0x00309c5c` | 208 | `0x43d620`, `0x431f48`, `0xac3330`, `0x98ef34` | 檢查單例 `0xb0b850`，配置 32B 堆疊記憶體，初始化 Application 物件 |
| **JNI 入口** | `MyActivity_appUpdateDraw` | `0x00309d2c` | 228 | `0xac3360`, `0x9909c4`, `0xac3370` | 讀取奈秒時間差，計算 `dt`，驅動主遊戲更新迴圈與 OpenGL 渲染 |
| **JNI 入口** | `MyActivity_fsInit` | `0x00309e10` | 8 | `0x450dc8` | 傳入 Java `AssetManager` 物件，轉入底層 NDK Asset 封裝 |
| **JNI 入口** | `MyActivity_gfxInit` | `0x00309e18` | 276 | `0x464c14`, `0xabf1b0`, `0xac3320` | 初始化 OpenGL ES 著色器程式、建立 FBO 與頂點緩衝區 |
| **JNI 入口** | `MyActivity_appTouch` | `0x0030a098` | 192 | `0x990934` | 解析觸控類型 (DOWN/UP/MOVE) 與座標 `(x, y)`，分發至輸入隊列 |
| **JNI 入口** | `MyActivity_kill` | `0x0030a388` | 112 | `0x98f214`, `0x98fa6c`, `0xabf1b0` | 清空單例 `0xb0b850`，釋放紋理快取與遊戲狀態機 |
| **內部核心** | `Application::Application` | `0x0098ef34` | ~512 | `0xace2c8` (vtable) | C++ 應用程式主物件建構子，註冊各子系統虛擬函式表 |
| **內部核心** | `Application::Update` | `0x009909c4` | ~384 | 狀態機分發指針 | 依據目前場景狀態（標題、選單、戰鬥），分發更新邏輯 |
| **內部核心** | `Application::OnTouch` | `0x00990934` | ~160 | 視圖樹點擊命中測試 | 遍歷當前 UI 視圖或戰鬥圖層，觸發點擊回調 |
| **內部核心** | `AssetManager::InitBridge` | `0x00450dc8` | 24 | `0xac56c0` (`AAssetManager_fromJava`) | 將 Java 引用轉化為原生 `AAssetManager*` 並儲存於全域 `0xb0d238` |
| **內部資產** | `AssetCatalog::RegisterPacks` | `0x006f74a0` | 512+ | `0xac3420`, `0xac3410`, `0x6f67b0` | 註冊 `DataLocal.pack`, `UnitLocal.pack`, `MapLocal.pack` 等表單 |
| **內部資產** | `ArchiveManager::Cleanup` | `0x006f67b0` | 256 | `0xac3350` (`operator delete`) | 遍歷清理資產目錄清單中的 `std::string` 與緩衝區 |

---

## 二、 戰鬥子系統 RTTI 與符號定位

經深入 `.rodata` 掃描，遊戲編譯期保留之戰鬥核心類別與方法簽章明確定位於以下位址：

```text
0x001beec8:  BattleTextureContext (戰鬥紋理快取上下文)
0x001befe1:  MyApplication::battle_initWin (戰鬥勝利介面與結算初始化)
0x001bf6ba:  MyApplication::battle_createButton (戰鬥中貓咪出擊按鈕生成)
0x001c11a1:  MyApplication::battleCheckLogic (戰鬥主邏輯碰撞與勝負校驗)
0x001decf9:  MyApplication::showBattleResume (斷線或離開重返戰鬥提示)
0x0018cb41:  BattleInit (戰鬥初始化情境建構)
0x001a4d0a:  BattleStartSE (戰鬥開場號角音效觸發)
0x00191540:  BattleFinishWinSE (戰鬥勝利號角音效)
0x0019aa08:  BattleFinishLoseSE (戰鬥失敗號角音效)
0x0019a403:  BattleXPx2 (戰鬥經驗雙倍結算處理)
0x001a0527:  BattleContinue (戰鬥接關與貓罐頭復活處理)
```
