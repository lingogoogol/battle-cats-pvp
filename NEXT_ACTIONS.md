# 《貓咪大戰爭》重建工程：後續演進路線圖 (NEXT_ACTIONS.md)

**專案狀態**：Phase 13 ~ Phase 17 全部目標皆已圓滿交付並通過驗收。

---

## 後續可選進階演進任務 (Future Milestones)

1. **[進階資料管線] 動態金鑰注入與封包批次導出工具 (Optional Key Injector)**
   - 透過 Frida 或靜態還原 Native 計算 MD5 金鑰之確切演算法，實現原版 `DataLocal.pack` 與 `UnitLocal.pack` 之自動批次解碼為 JSON，導入全量 700+ 貓咪數據。

2. **[進階渲染] 骨骼層次動畫引擎 (Skeletal Hierarchy Animation)**
   - 原版採用基於特定 CSV/Atlas 之 2D 骨骼分塊層次旋轉與位移。可進一步研發對相應骨骼格式的解析器，達成原版 1:1 骨骼動作。

3. **[磁碟維護] C 槽快取清理**
   - 經使用者正式授權後，清理 `C:\Users\吳建廷\.cache` (1.47 GB) 與 `.gradle` (1.20 GB) 以釋放系統空間。
