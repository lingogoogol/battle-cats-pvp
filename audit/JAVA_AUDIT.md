# 《貓咪大戰爭》Java 反編譯完整性稽核報告 (JAVA_AUDIT.md)

- **稽核對象**：`E:\rea\decompiled_src\java\sources\`
- **反編譯引擎**：JADX v1.5.6 (REA Headless Integration)
- **總分析類別數**：15,221 類別 (總輸出 Java 檔案數：22,997 個)

---

## 一、 反編譯品質統計與成功率

| 指標 | 數值 | 比例 | 備註 |
| :--- | :--- | :--- | :--- |
| **總類別數** | 15,221 | 100% | 涵蓋 `classes.dex` 至 `classes5.dex` |
| **無致命錯誤類別** | 15,145 | 99.50% | 語法結構完整 materialization |
| **具硬性反編譯錯誤 (Hard Errors)** | 76 | 0.50% | 出現 `JadxRuntimeException` / `Method dump skipped` |
| **錯誤出現總次數** | 106 處 | - | 分佈於 76 個類別中 |

---

## 二、 JADX 硬性錯誤 (Hard Errors) 根因與受影響檔案分析

經全面搜尋原始碼中包含 `/* JADX ERROR: ... */` 及 `Method dump skipped` 的檔案，所有失敗皆**高度集中於第三方高度混淆的 SDK**，非 Ponos 原廠遊戲本體代碼：

### 1. 主要錯誤類型
1. **`JadxOverflowException in pass: RegionMakerVisitor`**：控制流圖（CFG）因高強度混淆循環展開導致堆疊深度溢出。
2. **`Type inference failed` / `Types fix failed`**：暫存器重用與位元組碼變形導致型態推斷矛盾。
3. **`JadxRuntimeException in pass: ModVisitor`**：變數作用域與合成存取器解析衝突。

### 2. 受影響前 20 大檔案清單

| 受影響檔案路徑 | 錯誤數 | 模組歸屬 | 錯誤類型特徵 |
| :--- | :--- | :--- | :--- |
| `com\facebook\ads\redexgen\core\ZZ.java` | 3 | Facebook Audience Network | `ProcessVariables jadx.core.utils.exception` |
| `androidx\exifinterface\media\a.java` | 2 | AndroidX Media | `RegionMakerVisitor java.lang.UnsupportedOperationException` |
| `com\facebook\ads\redexgen\core\AnonymousClass10.java` | 2 | Facebook Audience Network | 控制流過於複雜，方法主體被跳過 |
| `com\google\android\exoplayer2\extractor\mp4\FragmentedMp4Extractor2.java` | 2 | Google ExoPlayer | 方法反編譯超時/跳過 |
| `com\google\android\gms\internal\ads\zzagg.java` | 2 | Google Mobile Ads | `Type inference failed (JadxOverflowException)` |
| `com\google\android\gms\internal\ads\zzaik.java` | 2 | Google Mobile Ads | `Type inference failed` |
| `com\google\android\gms\internal\ads\zzane.java` | 2 | Google Mobile Ads | `RegionMakerVisitor` |
| `com\google\android\gms\internal\ads\zzaob.java` | 2 | Google Mobile Ads | `RegionMakerVisitor` |
| `com\google\android\gms\internal\ads\zzgl.java` | 2 | Google Mobile Ads | `Types fix failed` |
| `com\google\android\gms\internal\ads\zzsn.java` | 2 | Google Mobile Ads | `Type inference failed` |
| `com\google\android\gms\internal\gtm\zzte.java` | 2 | Google Tag Manager | `Types fix failed` |
| `com\google\android\gms\internal\play_billing\zzo.java` | 2 | Google Play Billing | `RegionMakerVisitor` |
| `com\google\android\gms\measurement\internal\zzgl.java` | 2 | Google Analytics | `Type inference failed` |
| `com\google\android\recaptcha\internal\zzen.java` | 2 | Google reCAPTCHA | `RegionMakerVisitor` |
| `com\google\protobuf\a0.java` | 2 | Google Protobuf | `Type inference failed` |
| `com\ironsource\adqualitysdk\sdk\i\hx.java` | 2 | IronSource SDK | 方法主體跳過 |
| `com\ironsource\adqualitysdk\sdk\i\kb.java` | 2 | IronSource SDK | `RegionMakerVisitor` |
| `com\pubmatic\sdk\openwrap\core\POBBiddingManager.java` | 2 | PubMatic OpenWrap | `ModVisitor JadxRuntimeException` |
| `com\unity3d\ads\core\data\manager\TransactionEventManager.java` | 2 | Unity Ads | `RegionMakerVisitor` |
| `com\unity3d\ads\gatewayclient\CommonGatewayClient.java` | 2 | Unity Ads | `RegionMakerVisitor` |

---

## 三、 Ponos 原廠代碼 (`jp.co.ponos.*`) 完整性稽核

針對核心遊戲與橋接套件 `jp.co.ponos` 進行專項稽核：

- **Ponos 類別總數**：53 個 Java 檔案（位於 `sources\jp\co\ponos\battlecats\` 及 `sources\jp\co\ponos\battlecatstw\`）。
- **硬性反編譯錯誤**：**0 個**。所有 Ponos 類別的方法皆成功反編譯為 Java 語法。
- **警告標記**：
  - `battlecats\MyActivity.java`：僅 1 處非破壞性警告（多變數型態推斷 fallback）。
  - `battlecats\p0.java`：15 處暫存器命名重疊警告。
- **核心檔案還原狀態**：
  1. `MyActivity.java`（3,500+ 行）：完整還原了與 `native-lib` 銜接的所有 58 個 JNI 外部聲明、生命週期回呼（`onCreate`, `onResume`, `onDestroy`）、權限請求、以及通知推播邏輯。
  2. `IronSourceImplementation.java`（300+ 行）：廣告載入與獎勵觸發橋接完整。
  3. `TapjoyImplementation.java`（450+ 行）：虛擬幣與積分牆橋接完整。
  4. `GooglePlayImplementation.java`：Google Play 登入與成就介面完整。

---

## 四、 混淆防護 (ProGuard / R8) 狀態與限制

1. **套件與類別名破壞**：
   大量底層類別已被 R8/ProGuard 重新命名為單字母或扁平化套件（如 `a/`, `b/`, `u1/`, `v2/`）。
2. **區域變數與參數名遺失**：
   編譯時除錯符號（LineNumberTable / LocalVariableTable）已被剥除，參數皆為合成名稱（如 `i10`, `str2`, `f11`）。
3. **不可等同於原始碼恢復**：
   反編譯產出的 Java 程式碼是 Dalvik 位元組碼的**衍生語法表示（Derived Semantic Representation）**，並非 Ponos 開發者原始撰寫的工程原始碼（缺乏原始註解、原始常數巨集、私有內部類別原始架構）。
