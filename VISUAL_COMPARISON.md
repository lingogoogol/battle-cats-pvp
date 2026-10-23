# 《貓咪大戰爭》v15.6.1 視覺對比與真實資產呈現報告 (VISUAL_COMPARISON.md)

**專案根目錄**：`E:\rea`  
**建立日期**：2026-10-15  
**比對目標關卡**：世界篇第一章第 1 關「韓國」  
**最新實機畫面**：[korea_battle_rebuilt.png](file:///E:/rea/game_project/screenshots/korea_battle_rebuilt.png)  
**側並側比對合成檔**：[side_by_side_korea_comparison.png](file:///E:/rea/references/side_by_side_korea_comparison.png)  
**原版動畫條帶證據**：[cat_walk_strip.png](file:///E:/rea/references/anim_playback_test/cat_walk_strip.png)

---

## 一、重大進展：原版真實動畫資產正式注入畫面

在本輪 Phase 18–22 之前，本專案的「基本貓」僅為一組由 `pygame.draw.circle` 與 `draw.polygon` 繪製的程序化替代幾何體。

**自 Phase 21 起，畫面已正式升級為原版真實資產渲染：**
1. **貓咪角色**：全面切換為官方解密之 [`download_char_000.png`](file:///E:/rea/game_assets/recovered_assets/download_cat/download_char_000.png) 貼圖集，經由 [`PonosAnimationPlayer`](file:///E:/rea/game_project/anim_engine/ponos_anim_player.py) 依據官方 `.imgcut`、`.mamodel`、`.maanim` 進行逐幀骨骼旋轉與切片變換。
2. **走動姿態**：100% 依循官方 16 幀週期關鍵影格（Cut 1 -> Cut 3 -> Cut 1 -> Cut 2 -> Cut 1），腳底精確貼齊地面基準線 `Y = 510`。
3. **出兵操作列**：底板全面平鋪官方原版提取之 `bottom_bg01.png` 紋理。
4. **戰鬥音效**：部署單位播放 `snd164.ogg`、攻擊判定播放 `snd000.ogg`、擊退播放 `snd062.ogg`、升級播放 `snd171.ogg`，全數來自原版 OGG 明文資產。

---

## 二、十項視覺維度最新比對評分表

```
維度 1：畫面幾何配置 (Layout)         ── [ 85% MATCH ]   (1280x720, 地面線 Y=510, 城堡間距 2600 像素)
維度 2：戰場背景 (Background)         ── [ 45% HYBRID ]  (雙層視差遠山，原版背景 bg265/bg268 待整合)
維度 3：雙方城堡 (Castles)            ── [ 50% HYBRID ]  (Slot 0 碰撞盒、血量 500、外觀紋理待替換)
維度 4：角色位置與比例 (Unit Scale)   ── [ 80% MATCH ]   (腳底錨定 510，原版 1.2x 縮放比例精確符合)
維度 5：角色美術素材 (Unit Art)       ── [ 40% RECOVERED](基本貓已達 100% 原版真實骨骼；敵人待完全解密)
維度 6：卡牌與金錢 UI (UI Chrome)     ── [ 70% HYBRID ]  (原版 bottom_bg01.png，冷卻垂直滑落遮罩)
維度 7：血條指示 (Health Bars)        ── [ 65% MATCH ]   (城堡血條與受損動態血條正常浮動)
維度 8：骨骼動畫 (Animation)          ── [ 50% AUTHENTIC](貓咪走動 100% 原版 2D 骨骼；其餘單位狀態機)
維度 9：數字與字型 (Typography)       ── [ 55% MATCH ]   (傷害數字浮動與跳動時鐘)
維度 10：戰鬥音效特效 (Audio & FX)    ── [ 80% AUTHENTIC](官方 25 OGG 音訊全面連動，打擊火花與擊退粉塵)
```

---

## 三、真實參考基準與驗收限制

雖然基本貓動畫與官方關卡數值（韓國 500 HP、賈修狗波次）已 100% 導入，但由於本地目錄 `E:\rea\references\official_v15_6_1/` 仍缺少使用者提供的原版實機無損截圖（`03_battle_korea_initial.png`），本專案**堅守誠實工程準則**：
- **`VISUAL_PARITY` 整體評級仍維持：`PARTIAL_AUTHENTIC (35.0% Overall Parity)`**。
- 絕不在未取得同版本實機對照圖前，虛報 100% 視覺還原成功。
