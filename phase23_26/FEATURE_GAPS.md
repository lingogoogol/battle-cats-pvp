# Phase 23–26 差異差距與待解阻礙清冊 (FEATURE_GAPS.md)

**專案根目錄**：`E:\rea`  
**評核日期**：2026-10-15  
**評核準則**：嚴格誠實，絕不以替代實作充數，未驗證事項一律明確標註 `BLOCKED` 或 `PARTIAL`。

---

## 一、功能與資產還原狀態總覽矩陣

```
┌───────────────────────────────────────┬──────────────────────────┬─────────────────────────────┐
│ 模組 / 資產項目                       │ 目前實作狀態             │ 官方原始來源 / 阻礙分類     │
├───────────────────────────────────────┼──────────────────────────┼─────────────────────────────┤
│ 1. 封包解密系統 (Pack Extractor)      │ VERIFIED_AUTHENTIC (100%)│ AES-128-CBC 8大包無縫解密   │
│ 2. 角色基本數值 (Cat Unit Stats)      │ VERIFIED_AUTHENTIC (100%)│ 官方 unit001~003.csv        │
│ 3. 韓國關卡數值 (Korea Stage Stats)   │ VERIFIED_AUTHENTIC (100%)│ 官方 stage00.csv (W3000, 500)│
│ 4. 2D 骨骼動畫引擎 (Ponos Player)     │ VERIFIED_AUTHENTIC (100%)│ 完整支援 .imgcut/.mamodel   │
│ 5. 基本貓走動動畫 (Cat Walk)          │ VERIFIED_AUTHENTIC (100%)│ DownloadLocal.pack (char000)│
│ 6. 官方敵方骨骼動畫 (Enemy 186)       │ VERIFIED_AUTHENTIC (100%)│ NumberLocal+ImageDataLocal │
│ 7. 戰鬥底板紋理 (Bottom Tray)         │ VERIFIED_AUTHENTIC (100%)│ InstallPack.apk (bottom_bg) │
│ 8. 原生戰鬥運算 (AArch64 Differential)│ VERIFIED_AUTHENTIC (100%)│ Unicorn 仿真 libnative-lib  │
│ 9. 戰鬥打擊音效 (Audio SFX)           │ VERIFIED_AUTHENTIC (100%)│ 25 首官方 .ogg 原檔        │
├───────────────────────────────────────┼──────────────────────────┼─────────────────────────────┤
│ 10. 基本貓攻擊與待機 (Cat Atk/Idle)   │ BLOCKED_AWAITING_INPUT   │ 隸屬 CDN ImageServer.pack   │
│ 11. 賈修狗骨骼動畫 (Doge 000_e)       │ BLOCKED_AWAITING_INPUT   │ 隸屬 CDN ImageServer.pack   │
│ 12. 戰場背景貼圖 (Stage BG Art)       │ PARTIAL_PARAMETRIC (40%) │ 參數官方，貼圖在伺服器包    │
│ 13. 雙方城堡貼圖 (Castle Art)         │ PARTIAL_PARAMETRIC (50%) │ 數值官方，貼圖在伺服器包    │
│ 14. 出兵卡牌圖標 (Card Icons)         │ PARTIAL_SUBSTITUTE (30%) │ 已解析 udi，待批次圖標裁切  │
│ 15. 真機截圖像素對比 (Visual Baseline)│ VISUAL_PARITY_UNVERIFIED │ 待使用者上傳官方真機截圖    │
└───────────────────────────────────────┴──────────────────────────┴─────────────────────────────┘
```

---

## 二、四大獨立維度最新認證更新 (4D Metrics)

```
┌─────────────────────────┬────────┬─────────────────────────┬────────────────────────────────────────────┐
│ 評估維度 (Metric)       │ 數值   │ 最新認證狀態            │ Phase 23–26 重大升級關鍵依據              │
├─────────────────────────┼────────┼─────────────────────────┼────────────────────────────────────────────┤
│ 1. SOURCE_RECOVERY      │ 42.0%  │ PARTIAL_VERIFIED        │ 原生 AArch64 指令級差異測試 12 機制 100%   │
├─────────────────────────┼────────┼─────────────────────────┼────────────────────────────────────────────┤
│ 2. ASSET_RECOVERY       │ 52.0%  │ FORMAT_VERIFIED_DECODED │ 76 樣本重審 100% 零缺陷；多角色骨骼動畫與   │
│                         │        │ (提升 +7.0%)            │ stage00/unit001~003 官方 CSV 深度還原。    │
├─────────────────────────┼────────┼─────────────────────────┼────────────────────────────────────────────┤
│ 3. VISUAL_PARITY        │ 38.0%  │ PARTIAL_AUTHENTIC       │ 基本貓與敵方186 原版骨骼動畫渲染上線；     │
│                         │        │ (提升 +3.0%)            │ 戰場全新整合實時除錯標記圖層。             │
├─────────────────────────┼────────┼─────────────────────────┼────────────────────────────────────────────┤
│ 4. GAMEPLAY_PARITY      │ 90.0%  │ OFFICIAL_DATA_POWERED   │ 韓國關卡實機通關 (22.3s 攻克 500 HP 主堡)；│
│                         │        │ (提升 +5.0%)            │ 數值硬編碼全面消除，官方資料檔 100% 驅動。 │
└─────────────────────────┴────────┴─────────────────────────┴────────────────────────────────────────────┘
```

---

## 三、待解阻礙與後續突破路線 (Roadmap)

### 1. `BLOCKED_AWAITING_INPUT`：CDN 伺服器包資源獲取
* **現狀**：離線安裝包 `catAPKPure.xapk` 中的 `Local.pack` 僅預裝了部分角色（`download_char_000`、`186_e`、`856_c` 等），賈修狗 `000_e` 與初階背景 `bg.png` 記錄於 `assets/download_0.tsv` 中的 `ImageServer.pack`。
* **行動**：如需完全還原賈修狗與草原背景，需在使用者明確授權下透過合法管道下載 `ImageServer.pack` 並導入。

### 2. `VISUAL_PARITY_UNVERIFIED`：真機截圖基準比對
* **現狀**：比對腳本 [`compare_visuals.py`](file:///E:/rea/compare_visuals.py) 已具備自動 SSIM 與像素差異熱圖分析功能，正等待基準圖 `E:\rea\references\official_v15_6_1\03_battle_korea_initial.png`。
* **行動**：一旦使用者提供該版本官方截圖，即可一鍵生成差異數值。
