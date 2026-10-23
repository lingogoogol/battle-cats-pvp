/**
 * The Battle Cats - Web Edition & Room-Code Multiplayer Client (app.js)
 * Renders 100% authentic PONOS .imgcut + .mamodel + .maanim 2D skeletal animations,
 * official UI atlases (img001_tw, img002_tw, nyankoCastle_*, 000_a, battle_soul_000),
 * 4-digit Room Code matchmaking, and In-Browser Custom Character Studio.
 */

const SCREEN_W = 1280;
const SCREEN_H = 720;
const GROUND_Y = 500;
const TEAM_CAT = 0;   // Right Castle (P1 Host)
const TEAM_ENEMY = 1; // Left Castle (P2 Guest)

// Global App State
let RIGS = {};
let BASE_CATS = [];
let CUSTOM_UNITS = [];
let SELECTED_DECK = [];
let IMAGES = {};

let currentRoomCode = "";
let myTeam = TEAM_CAT;
let roomState = null;
let eventSource = null;
let pollTimer = null;

// Camera & UI State
let cameraX = 1200;
let isDraggingCam = false;
let dragStartX = 0;
let dragStartCamX = 0;
let manualCameraHold = 0;
let activeRow = 0; // 0 = slots 0..4, 1 = slots 5..9
let clientTick = 0;
let previewFrame = 0;
let selectedRarityFilter = "ALL";
let selectedCatLevel = 1;
let inspectedItem = null;
let formationPreviewAnim = "walk";

// Active Visual FX on Client Canvas
let fxHitSparks = [];
let fxDeathSouls = [];
let fxCannonBeams = [];
let fxFloatingTexts = [];
let fxWaves = [];
let unitVisualState = new Map();

// Preload Official Textures
const CORE_TEXTURES = {
  bg000: "/assets/bg000.png",
  img001: "/assets/img001_tw.png",
  img002: "/assets/img002_tw.png",
  fc000: "/assets/fc000.png",
  ec000: "/assets/ec000_tw.png",
  castle_turret: "/assets/nyankoCastle_000_00.png",
  castle_beam: "/assets/nyankoCastle_001_00_00.png",
  castle_plaque: "/assets/nyankoCastle_002_00.png",
  castle_base: "/assets/nyankoCastle_003_00.png",
  hit_a: "/assets/000_a.png",
  soul: "/assets/battle_soul_000.png",
};
for (let i = 0; i < 9; i++) {
  CORE_TEXTURES[`uni_${i}`] = `/assets/uni00${i}_f00.png`;
}

function loadImage(key, url) {
  if (IMAGES[key]) return IMAGES[key];
  const img = new Image();
  img.src = url;
  IMAGES[key] = img;
  return img;
}

function showToast(msg) {
  const box = document.getElementById("toastBox");
  box.textContent = msg;
  box.style.display = "block";
  clearTimeout(box._timer);
  box._timer = setTimeout(() => {
    box.style.display = "none";
  }, 3200);
}

function switchTab(tabName) {
  document.querySelectorAll(".view-section").forEach(el => el.classList.remove("active"));
  document.querySelectorAll(".tab-btn").forEach(el => el.classList.remove("active"));
  document.getElementById(`view-${tabName}`).classList.add("active");
  if (tabName === "lobby") {
    document.getElementById("tabLobbyBtn").classList.add("active");
    refreshRoomList();
  } else if (tabName === "battle") {
    document.getElementById("tabBattleBtn").classList.add("active");
  } else if (tabName === "studio") {
    document.getElementById("tabStudioBtn").classList.add("active");
  }
}

// ============================================================================
// 1. BOOTSTRAP & DECK / STUDIO MANAGEMENT
// ============================================================================

async function initApp() {
  Object.entries(CORE_TEXTURES).forEach(([k, u]) => loadImage(k, u));

  try {
    const res = await fetch("/api/bootstrap");
    const data = await res.json();
    RIGS = data.rigs || {};
    BASE_CATS = data.base_cats || [];
    CUSTOM_UNITS = data.custom_units || [];

    // Preload all rig sprite sheets & official unit portrait icons
    Object.values(RIGS).forEach(r => {
      loadImage(`rig_${r.code}`, r.png);
    });
    BASE_CATS.forEach(c => {
      if (c.icon) {
        loadImage(`icon_${c.icon}`, `/assets/${c.icon}.png`);
      }
    });

    // Populate Studio Rig Selector with all 38 official cat rigs + enemy rigs
    const cuRigEl = document.getElementById("cuRig");
    if (cuRigEl && BASE_CATS.length > 0) {
      const existingValues = new Set(Array.from(cuRigEl.options).map(o => o.value));
      BASE_CATS.forEach(c => {
        if (c.rig && !existingValues.has(c.rig)) {
          const opt = document.createElement("option");
          opt.value = c.rig;
          opt.textContent = `${c.rig} - ${c.name} (${c.rarity_label})`;
          cuRigEl.appendChild(opt);
          existingValues.add(c.rig);
        }
      });
    }

    const port = window.location.port || "8080";
    const shareUrl = data.public_url || `http://${data.lan_ip || window.location.hostname}:${port}`;
    const urlEl = document.getElementById("shareUrlBox");
    if (urlEl) urlEl.textContent = shareUrl;

    // Initialize balanced multi-rarity 10-slot default deck (Meatshields + Rare/SR/EX/Uber/Legend)
    const defaultKeys = [
      "cat", "tank_cat", "rare_pogo", "rare_salon", "sr_swimmer",
      "sr_kotatsu", "ex_bahamut", "uber_balrog", "uber_hanzo", "legend_momoco",
    ];
    SELECTED_DECK = [];
    defaultKeys.forEach(k => {
      if (BASE_CATS.some(c => c.key === k) && SELECTED_DECK.length < 10) {
        SELECTED_DECK.push(k);
      }
    });
    BASE_CATS.forEach(c => {
      if (!SELECTED_DECK.includes(c.key) && SELECTED_DECK.length < 10) {
        SELECTED_DECK.push(c.key);
      }
    });

    renderDeckSelector();
    renderCustomUnitLibrary();
    renderRoomListUI(data.rooms || []);

    // Check URL hash or query for ?room=XXXX
    const urlParams = new URLSearchParams(window.location.search);
    const autoRoom = urlParams.get("room");
    const forceTeam = urlParams.get("team");
    if (autoRoom) {
      document.getElementById("joinRoomCodeInput").value = autoRoom;
      if (forceTeam !== null) {
        const stRes = await fetch(`/api/room/state?room=${encodeURIComponent(autoRoom)}`);
        if (stRes.ok) {
          const stData = await stRes.json();
          enterBattleRoom(autoRoom, parseInt(forceTeam, 10) || TEAM_CAT, stData);
        }
      } else {
        await joinRoomByCode();
      }
    }
  } catch (err) {
    console.error("Bootstrap error:", err);
  }

  setupBattleControls();
  requestAnimationFrame(renderLoop);
  if (new URLSearchParams(window.location.search).get("oneshot") !== "1") {
    setInterval(refreshRoomList, 4000);
  }
}

function getLevelScaleFactor(level = selectedCatLevel) {
  return 1.0 + 0.2 * (Math.max(1, level) - 1);
}

function changeCatLevel(val) {
  selectedCatLevel = Math.max(1, Math.min(50, parseInt(val, 10) || 1));
  renderDeckSelector();
  if (inspectedItem) {
    const allItems = getAllSelectableUnits();
    const updated = allItems.find(x => x.key === inspectedItem.key);
    if (updated) inspectCat(updated);
  }
  if (currentRoomCode) {
    sendRoomAction("SET_LEVEL", selectedCatLevel);
  }
  const mult = getLevelScaleFactor(selectedCatLevel).toFixed(1);
  showToast(`已切換貓咪等級為 Lv.${selectedCatLevel} (${mult}x 官方成長公式)`);
}

function getAllSelectableUnits() {
  const lvScale = getLevelScaleFactor(selectedCatLevel);
  return [
    ...BASE_CATS.map(c => {
      const rawHits = Array.isArray(c.attack_hits) ? c.attack_hits : [];
      const scaledHits = rawHits.map(h => ({
        ...h,
        damage: Math.max(1, Math.round((h.damage || 1) * lvScale)),
      }));
      const scaledAp = scaledHits.length > 0
        ? scaledHits.reduce((acc, h) => acc + h.damage, 0)
        : Math.max(1, Math.round((c.ap || 100) * lvScale));
      return {
        key: c.key,
        name: c.name,
        cost: c.cost,
        base_hp: c.hp || 1000,
        base_ap: c.ap || 100,
        hp: Math.max(1, Math.round((c.hp || 1000) * lvScale)),
        ap: scaledAp,
        attack_hits: scaledHits,
        range: c.range || 140,
        speed: c.speed || 10,
        kb_count: c.kb_count || 3,
        foreswing: c.foreswing || 10,
        tba: c.tba || 30,
        cd_frames: c.cd_frames || 60,
        is_area: !!c.is_area,
        rig: c.rig || "000_f",
        icon: c.icon || "uni000_f00",
        rarity: c.rarity || "normal",
        rarity_label: c.rarity_label || "基本",
        scale: c.scale || 0.62,
        traits: c.traits || [],
        target_traits: c.target_traits || [],
        abilities: c.abilities || {},
        desc: c.desc || "",
        custom: false,
      };
    }),
    ...CUSTOM_UNITS.map(cu => ({
      key: cu.key || cu.id,
      name: cu.name,
      cost: cu.cost || 300,
      base_hp: cu.hp || 10000,
      base_ap: cu.ap || 2000,
      hp: cu.hp || 10000,
      ap: cu.ap || 2000,
      attack_hits: [],
      range: cu.range || 250,
      speed: cu.speed || 20,
      kb_count: cu.kb_count || 3,
      foreswing: cu.pre_atk_frames || 10,
      tba: cu.tba_frames || 20,
      cd_frames: cu.cd_frames || 60,
      is_area: cu.is_area_attack !== false,
      rig: cu.base_rig || "004_f",
      icon: "",
      rarity: "custom",
      rarity_label: "自製",
      scale: cu.scale || 0.72,
      traits: [],
      target_traits: [],
      abilities: cu.abilities || {},
      desc: "玩家於角色工坊自訂的專屬原創角色。",
      custom: true,
    })),
  ];
}

function getAbilityTags(item) {
  const ab = item.abilities || {};
  const tags = [];
  tags.push(item.is_area ? "範圍攻擊" : "單體攻擊");
  if (Array.isArray(item.attack_hits) && item.attack_hits.length > 1) {
    tags.push(`${item.attack_hits.length}段連續攻擊`);
  }
  if (ab.ld_start && ab.ld_range) {
    const r1 = Math.min(ab.ld_start, ab.ld_start + ab.ld_range);
    const r2 = Math.max(ab.ld_start, ab.ld_start + ab.ld_range);
    tags.push(`遠方攻擊 (${r1}~${r2})`);
  }
  if (ab.crit_prob > 0) tags.push(`暴擊 ${ab.crit_prob}%`);
  if (ab.savage_blow_prob > 0) tags.push(`渾身一擊 ${ab.savage_blow_prob}%`);
  if (ab.wave_prob > 0) tags.push(`Lv.${ab.wave_lvl || 2} 波動 ${ab.wave_prob}%`);
  if (ab.surge_prob > 0) tags.push(`Lv.${ab.surge_lvl || 1} 烈波 ${ab.surge_prob}%`);
  if (ab.freeze_prob > 0) tags.push(`暫停 ${ab.freeze_prob}%`);
  if (ab.slow_prob > 0) tags.push(`緩速 ${ab.slow_prob}%`);
  if (ab.kb_prob > 0) tags.push(`擊退 ${ab.kb_prob}%`);
  if (ab.weaken_prob > 0) tags.push(`降攻 ${ab.weaken_prob}%`);
  if (ab.strengthen_hp_pct > 0) tags.push(`血量${ab.strengthen_hp_pct}%攻擊+${ab.strengthen_boost_pct}%`);
  if (ab.survive_prob > 0) tags.push(`死前存活 ${ab.survive_prob}%`);
  if (ab.insane_damage) tags.push("極度傷害 (5x)");
  else if (ab.massive_damage) tags.push("超大傷害 (3x)");
  if (ab.insanely_tough) tags.push("極度耐打 (1/6)");
  else if (ab.resistant) tags.push("很耐打 (1/4)");
  if (ab.strong || ab.strong_against) tags.push("善於攻擊");
  if (ab.zombie_killer) tags.push("終結不死");
  if (ab.barrier_break_prob > 0) tags.push(`破盾 ${ab.barrier_break_prob}%`);
  if (ab.wave_immune) tags.push("波動免疫");
  if (ab.freeze_immune) tags.push("暫停免疫");
  if (ab.slow_immune) tags.push("緩速免疫");
  if (ab.kb_immune) tags.push("擊退免疫");
  return tags;
}

function syncDeckIfInRoom() {
  if (currentRoomCode) {
    sendRoomAction("UPDATE_DECK", SELECTED_DECK);
  }
}

function setFormationPreviewAnim(animName) {
  formationPreviewAnim = animName;
  previewFrame = 0;
  ["Walk", "Attack", "Idle", "Kb"].forEach(suffix => {
    const btn = document.getElementById(`animBtn${suffix}`);
    if (btn) {
      btn.style.background = suffix.toLowerCase() === animName ? "#2b426b" : "#1d283e";
      btn.style.color = suffix.toLowerCase() === animName ? "#ffcc33" : "#dce6f7";
    }
  });
}

function inspectCat(item) {
  if (!item) return;
  inspectedItem = item;
  previewFrame = 0;

  const badgeEl = document.getElementById("inspRarityBadge");
  if (badgeEl) {
    badgeEl.className = `rarity-badge rarity-${item.rarity}`;
    badgeEl.textContent = item.rarity_label;
  }
  const nameEl = document.getElementById("inspName");
  if (nameEl) nameEl.textContent = `${item.name} (Lv.${item.custom ? 1 : selectedCatLevel})`;

  let hitBreakdownHtml = "";
  if (Array.isArray(item.attack_hits) && item.attack_hits.length > 1) {
    const parts = item.attack_hits.map(h => h.damage.toLocaleString()).join(" + ");
    hitBreakdownHtml = `<div style="color:#ffd166;font-size:11px;">多段傷害拆解：<strong>${parts}</strong>（共 ${item.attack_hits.length} 段）</div>`;
  }

  const statsEl = document.getElementById("inspStats");
  if (statsEl) {
    statsEl.innerHTML = `
      <div>費用：<strong style="color:#ffe066;">${item.cost} 元</strong> ｜ 再產生：<strong>${(item.cd_frames / 30).toFixed(2)} 秒</strong> ｜ KB：<strong>${item.kb_count || 3}</strong></div>
      <div>體力 (HP)：<strong style="color:#7bed9f;">${item.hp.toLocaleString()}</strong> ｜ 總攻擊力 (AP)：<strong style="color:#ff9f43;">${item.ap.toLocaleString()}</strong></div>
      ${hitBreakdownHtml}
      <div>射程：<strong>${item.range} (${item.is_area ? "範圍攻擊" : "單體攻擊"})</strong> ｜ 跑速：<strong>${item.speed}</strong> ｜ 出手：<strong>${item.foreswing || 10}F</strong></div>
    `;
  }
  const abEl = document.getElementById("inspAbilities");
  if (abEl) {
    abEl.innerHTML = getAbilityTags(item)
      .map(t => `<span class="ability-tag">${t}</span>`)
      .join("");
  }
  const descEl = document.getElementById("inspDesc");
  if (descEl) {
    descEl.textContent = item.desc ? item.desc.replace(/\|/g, " ") : "官方貓咪大戰爭正版授權數據角色。";
  }
}

function applyDeckPreset(mode) {
  const allItems = getAllSelectableUnits();
  const byKey = new Map(allItems.map(i => [i.key, i]));
  let keys = [];
  if (mode === "balanced" || mode === "all_star") {
    keys = [
      "cat", "tank_cat", "rare_pogo", "rare_salon", "sr_swimmer",
      "sr_kotatsu", "ex_bahamut", "uber_balrog", "uber_hanzo", "legend_momoco",
    ];
  } else if (mode === "normal_ex") {
    keys = [
      "cat", "tank_cat", "axe_cat", "gross_cat", "cow_cat",
      "bird_cat", "fish_cat", "lizard_cat", "titan_cat", "ex_bahamut",
    ];
  } else if (mode === "uber_legend") {
    keys = [
      "cat", "tank_cat", "rare_pogo", "uber_balrog", "uber_ice_queen",
      "uber_cat_machine", "uber_hanzo", "legend_momoco", "legend_assassin", "legend_shirou",
    ];
  } else if (mode === "rush") {
    keys = [
      "cat", "cow_cat", "ex_ninja", "rare_pogo", "sr_swimmer",
      "ex_valkyrie", "uber_balrog", "uber_hanzo", "uber_tornado_dragon", "legend_assassin",
    ];
  }
  SELECTED_DECK = keys.filter(k => byKey.has(k)).slice(0, 10);
  renderDeckSelector();
  syncDeckIfInRoom();
  showToast("已套用推薦編隊並同步至房間！");
}

function sortDeckByCost() {
  const allItems = getAllSelectableUnits();
  const costMap = new Map(allItems.map(i => [i.key, i.cost]));
  SELECTED_DECK.sort((a, b) => (costMap.get(a) || 0) - (costMap.get(b) || 0));
  renderDeckSelector();
  syncDeckIfInRoom();
  showToast("已依生產費用由低到高排序出陣編隊！");
}

function clearDeckSelection() {
  if (SELECTED_DECK.length > 1) {
    SELECTED_DECK = [SELECTED_DECK[0]];
    renderDeckSelector();
    syncDeckIfInRoom();
    showToast("已清空編隊（保留第 1 格基本角色）");
  }
}

function renderDeckSelector() {
  const allItems = getAllSelectableUnits();
  const byKey = new Map(allItems.map(i => [i.key, i]));
  if (!inspectedItem && allItems.length > 0) {
    inspectCat(byKey.get(SELECTED_DECK[0]) || allItems[0]);
  }

  // 1. Render 10-Slot 2-Row Visual Formation Tray (#formationTray10)
  const trayEl = document.getElementById("formationTray10");
  if (trayEl) {
    trayEl.innerHTML = "";
    const hotkeys = ["1", "2", "3", "4", "5", "Q", "W", "E", "R", "T"];
    for (let i = 0; i < 10; i++) {
      const k = SELECTED_DECK[i];
      const item = k ? byKey.get(k) : null;
      const slotDiv = document.createElement("div");
      if (item) {
        slotDiv.className = "formation-slot-card filled";
        const iconHtml = item.icon
          ? `<img class="slot-icon-img" src="/assets/${item.icon}.png" alt="${item.name}">`
          : `<div style="height:48px;display:flex;align-items:center;justify-content:center;color:#ff9ff3;font-weight:900;font-size:13px;">★ 自製</div>`;
        slotDiv.innerHTML = `
          <span class="slot-hotkey">${hotkeys[i]}</span>
          <span class="slot-remove" title="點擊從編隊移除">✕</span>
          ${iconHtml}
          <div class="slot-name"><span class="rarity-badge rarity-${item.rarity}" style="font-size:9px;padding:0 4px;margin-right:3px;">${item.rarity_label}</span>${item.name}</div>
          <div class="slot-cost">${item.cost} 元</div>
        `;
        slotDiv.onclick = () => {
          inspectCat(item);
          if (SELECTED_DECK.length <= 1) {
            showToast("出陣牌組至少需保留 1 隻角色！");
            return;
          }
          SELECTED_DECK.splice(i, 1);
          renderDeckSelector();
          syncDeckIfInRoom();
        };
      } else {
        slotDiv.className = "formation-slot-card";
        slotDiv.innerHTML = `
          <span class="slot-hotkey">${hotkeys[i]}</span>
          <div style="color:#657794;font-size:12px;font-weight:700;text-align:center;">空位 Slot ${i + 1}<br><span style="font-size:10px;color:#4a5a75;">點擊下方角色加入</span></div>
        `;
      }
      trayEl.appendChild(slotDiv);
    }
  }

  // 2. Render Rarity Filter Tabs (#rarityTabsContainer)
  const tabsEl = document.getElementById("rarityTabsContainer");
  if (tabsEl) {
    const rarityDefs = [
      { id: "ALL", label: "全部角色" },
      { id: "normal", label: "基本" },
      { id: "ex", label: "EX" },
      { id: "rare", label: "稀有" },
      { id: "super_rare", label: "激稀有" },
      { id: "uber_rare", label: "超激稀有" },
      { id: "legend_rare", label: "傳說稀有" },
      { id: "custom", label: "自製角色" },
    ];
    tabsEl.innerHTML = "";
    rarityDefs.forEach(rt => {
      const cnt = rt.id === "ALL" ? allItems.length : allItems.filter(x => x.rarity === rt.id).length;
      if (rt.id === "custom" && cnt === 0) return;
      const btn = document.createElement("button");
      btn.type = "button";
      btn.className = "rarity-tab" + (selectedRarityFilter === rt.id ? " active" : "");
      btn.textContent = `${rt.label} (${cnt})`;
      btn.onclick = () => {
        selectedRarityFilter = rt.id;
        renderDeckSelector();
      };
      tabsEl.appendChild(btn);
    });
  }

  // 3. Render Filtered Multi-Rarity Cat Roster Grid (#deckChipsContainer)
  const container = document.getElementById("deckChipsContainer");
  if (container) {
    container.innerHTML = "";
    const filtered = selectedRarityFilter === "ALL"
      ? allItems
      : allItems.filter(x => x.rarity === selectedRarityFilter);

    filtered.forEach(item => {
      const card = document.createElement("div");
      const slotIdx = SELECTED_DECK.indexOf(item.key);
      const isSel = slotIdx >= 0;
      card.className = "unit-chip" + (isSel ? " selected" : "");
      const iconHtml = item.icon
        ? `<img class="chip-icon" src="/assets/${item.icon}.png" alt="${item.name}">`
        : `<div class="chip-icon" style="display:flex;align-items:center;justify-content:center;color:#ff9ff3;font-weight:900;font-size:12px;">自製</div>`;
      const abTags = getAbilityTags(item).slice(0, 2).join("・");
      card.innerHTML = `
        ${iconHtml}
        <div class="chip-info">
          <div style="display:flex;align-items:center;gap:4px;">
            <span class="rarity-badge rarity-${item.rarity}">${item.rarity_label}</span>
            <span class="chip-title">${item.name}</span>
          </div>
          <div class="chip-meta">費用 <strong style="color:#ffe066;">${item.cost}元</strong> ｜ 射程 ${item.range}</div>
          <div class="chip-meta" style="color:#7bed9f;">HP ${item.hp.toLocaleString()} / AP ${item.ap.toLocaleString()}</div>
          <div class="chip-meta" style="color:#8ec5ff;font-size:10px;">${abTags}</div>
        </div>
      `;
      card.onclick = () => {
        inspectCat(item);
        const idx = SELECTED_DECK.indexOf(item.key);
        if (idx >= 0) {
          if (SELECTED_DECK.length > 1) {
            SELECTED_DECK.splice(idx, 1);
          } else {
            showToast("出陣牌組至少需保留 1 隻角色！");
          }
        } else {
          if (SELECTED_DECK.length >= 10) {
            showToast("牌組已滿 10 隻！請先點擊上方編隊格或已選角色取消勾選。");
            return;
          }
          SELECTED_DECK.push(item.key);
        }
        renderDeckSelector();
        syncDeckIfInRoom();
      };
      container.appendChild(card);
    });
  }

  const lbl = document.getElementById("deckCountLabel");
  if (lbl) lbl.textContent = `已選 ${SELECTED_DECK.length} / 10`;
}

function renderFormationPreview() {
  const pCanvas = document.getElementById("formationPreviewCanvas");
  if (!pCanvas || !inspectedItem) return;
  const ctx = pCanvas.getContext("2d");
  ctx.clearRect(0, 0, pCanvas.width, pCanvas.height);

  // Subtle ground line
  ctx.strokeStyle = "rgba(255, 204, 51, 0.35)";
  ctx.lineWidth = 2;
  ctx.beginPath();
  ctx.moveTo(20, 152);
  ctx.lineTo(pCanvas.width - 20, 152);
  ctx.stroke();

  const rigCode = inspectedItem.rig || "000_f";
  const rigObj = RIGS[rigCode] || RIGS["000_f"];
  const isEnemyRig = rigObj ? !!rigObj.is_enemy : rigCode.includes("_e");
  const baseScale = inspectedItem.scale || 0.62;
  const previewScale = Math.min(0.58, baseScale * 0.78);
  renderSkeletalRig(ctx, rigCode, formationPreviewAnim, previewFrame, pCanvas.width * 0.52, 150, previewScale, isEnemyRig);
}

function renderCustomUnitLibrary() {
  const listEl = document.getElementById("customUnitLibraryList");
  if (!listEl) return;
  listEl.innerHTML = "";
  CUSTOM_UNITS.forEach(cu => {
    const row = document.createElement("div");
    row.className = "room-item";
    row.style.cursor = "pointer";
    row.innerHTML = `
      <div>
        <strong style="color:var(--gold-bright);">${cu.name}</strong>
        <span style="font-size:12px;color:#9fb1cc;margin-left:8px;">[${cu.base_rig || "004_f"}] HP:${cu.hp} AP:${cu.ap} 射程:${cu.range} 費用:${cu.cost}元</span>
      </div>
      <button type="button">載入編輯</button>
    `;
    row.onclick = () => {
      document.getElementById("cuName").value = cu.name || "";
      document.getElementById("cuId").value = cu.key || cu.id || "";
      document.getElementById("cuRig").value = cu.base_rig || "004_f";
      document.getElementById("cuScale").value = cu.scale || 0.7;
      document.getElementById("cuArea").value = cu.is_area_attack !== false ? "true" : "false";
      document.getElementById("cuHp").value = cu.hp || 10000;
      document.getElementById("cuAp").value = cu.ap || 2000;
      document.getElementById("cuRange").value = cu.range || 250;
      document.getElementById("cuSpeed").value = cu.speed || 20;
      document.getElementById("cuCost").value = cu.cost || 400;
      document.getElementById("cuCd").value = cu.cd_frames || 60;
      const ab = cu.abilities || {};
      document.getElementById("cuWaveProb").value = ab.wave_prob || 0;
      document.getElementById("cuWaveLvl").value = ab.wave_lvl || 2;
      document.getElementById("cuCritProb").value = ab.crit_prob || 0;
      document.getElementById("cuFreezeProb").value = ab.freeze_prob || 0;
      document.getElementById("cuFreezeFrames").value = ab.freeze_frames || 60;
    };
    listEl.appendChild(row);
  });
}

async function saveCustomUnit() {
  const spec = {
    id: document.getElementById("cuId").value.trim() || `custom_${Date.now()}`,
    name: document.getElementById("cuName").value.trim() || "自製英雄貓",
    base_rig: document.getElementById("cuRig").value,
    scale: parseFloat(document.getElementById("cuScale").value) || 0.72,
    is_area_attack: document.getElementById("cuArea").value === "true",
    hp: parseInt(document.getElementById("cuHp").value, 10) || 10000,
    ap: parseInt(document.getElementById("cuAp").value, 10) || 2000,
    range: parseInt(document.getElementById("cuRange").value, 10) || 260,
    speed: parseInt(document.getElementById("cuSpeed").value, 10) || 24,
    cost: parseInt(document.getElementById("cuCost").value, 10) || 400,
    cd_frames: parseInt(document.getElementById("cuCd").value, 10) || 60,
    kb_count: 3,
    pre_atk_frames: 10,
    tba_frames: 20,
    attack_anim_frames: 24,
    abilities: {
      wave_prob: parseInt(document.getElementById("cuWaveProb").value, 10) || 0,
      wave_lvl: parseInt(document.getElementById("cuWaveLvl").value, 10) || 2,
      crit_prob: parseInt(document.getElementById("cuCritProb").value, 10) || 0,
      freeze_prob: parseInt(document.getElementById("cuFreezeProb").value, 10) || 0,
      freeze_frames: parseInt(document.getElementById("cuFreezeFrames").value, 10) || 60,
    },
  };

  try {
    const res = await fetch("/api/custom_unit", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ spec }),
    });
    const data = await res.json();
    if (data.ok) {
      CUSTOM_UNITS = data.custom_units || [];
      if (!SELECTED_DECK.includes(data.key)) {
        if (SELECTED_DECK.length >= 10) SELECTED_DECK.pop();
        SELECTED_DECK.push(data.key);
      }
      renderDeckSelector();
      renderCustomUnitLibrary();
      showToast(`已儲存自製角色「${spec.name}」並加入出陣牌組！`);
    } else {
      showToast(data.error || "儲存失敗");
    }
  } catch (err) {
    showToast("儲存發生錯誤: " + err.message);
  }
}

function updateStudioPreview() {
  previewFrame = 0;
}

// ============================================================================
// 2. ROOM CODE MATCHMAKING (CREATE / JOIN BY ROOM CODE)
// ============================================================================

async function refreshRoomList() {
  try {
    const res = await fetch("/api/room/list");
    const data = await res.json();
    renderRoomListUI(data.rooms || []);
    if (data.public_url) {
      const urlEl = document.getElementById("shareUrlBox");
      if (urlEl) urlEl.textContent = data.public_url;
    }
  } catch (_) {}
}

function renderRoomListUI(rooms) {
  const el = document.getElementById("activeRoomList");
  if (!el) return;
  if (!rooms || rooms.length === 0) {
    el.innerHTML = `<div style="color:#7788a3;font-size:13px;padding:6px 0;">目前尚無房間，請點擊右側「建立對戰房間」取得 4 位數房號！</div>`;
    return;
  }
  el.innerHTML = "";
  rooms.forEach(r => {
    const div = document.createElement("div");
    div.className = "room-item";
    const statusLabel = r.vs_ai
      ? "單人 vs AI 進行中"
      : r.status === "WAITING"
      ? "等待對手輸入房號加入..."
      : `對戰中 (${r.host_name} vs ${r.guest_name})`;
    div.innerHTML = `
      <div>
        <span class="code-pill">房號 ${r.room_code}</span>
        <span style="font-size:13px;color:#c5d4eb;margin-left:10px;">房主: ${r.host_name} ｜ ${statusLabel}</span>
      </div>
      <button onclick="joinRoomDirect('${r.room_code}')">加入此房號</button>
    `;
    el.appendChild(div);
  });
}

async function createRoom(vsAi = false) {
  const playerName = document.getElementById("hostPlayerName").value.trim() || "P1 房主";
  const customCode = document.getElementById("customRoomCodeInput").value.trim();
  try {
    const res = await fetch("/api/room/create", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        player_name: playerName,
        room_code: customCode,
        vs_ai: vsAi,
        deck: SELECTED_DECK,
        cat_level: selectedCatLevel,
        custom_units: CUSTOM_UNITS,
      }),
    });
    const data = await res.json();
    if (data.ok) {
      enterBattleRoom(data.room_code, TEAM_CAT, data.state);
      showToast(vsAi ? `已開啟單人 AI 練習房（房號 ${data.room_code}）！` : `房間建立成功！請把房號【${data.room_code}】告訴朋友！`);
    }
  } catch (err) {
    showToast("建立房間失敗: " + err.message);
  }
}

async function joinRoomByCode() {
  const code = document.getElementById("joinRoomCodeInput").value.trim();
  if (!code) {
    showToast("請先輸入 4 位數房號！");
    return;
  }
  await joinRoomDirect(code);
}

async function joinRoomDirect(code) {
  const playerName = document.getElementById("joinPlayerName").value.trim() || "P2 挑戰者";
  try {
    const res = await fetch("/api/room/join", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        room_code: code,
        player_name: playerName,
        deck: SELECTED_DECK,
        custom_units: CUSTOM_UNITS,
      }),
    });
    const data = await res.json();
    if (!data.ok) {
      showToast(data.error || `找不到房號 ${code}`);
      return;
    }
    enterBattleRoom(data.room_code, TEAM_ENEMY, data.state);
    showToast(`成功加入房號【${data.room_code}】！你操作左側主堡 (P2)！`);
  } catch (err) {
    showToast("加入房間失敗: " + err.message);
  }
}

function enterBattleRoom(roomCode, team, initialState) {
  currentRoomCode = roomCode;
  myTeam = team;
  roomState = initialState;
  fxHitSparks = [];
  fxDeathSouls = [];
  fxCannonBeams = [];
  fxFloatingTexts = [];
  fxWaves = [];

  // Position camera near our own castle initially with full castle margin
  const stageLen = (initialState && initialState.length) || 2600;
  cameraX = team === TEAM_CAT ? Math.max(-70, stageLen - SCREEN_W + 60) : -60;

  document.getElementById("currentRoomCodeDisplay").textContent = roomCode;
  switchTab("battle");

  // Connect to SSE stream for 30 FPS updates
  if (eventSource) {
    eventSource.close();
    eventSource = null;
  }
  if (pollTimer) {
    clearInterval(pollTimer);
    pollTimer = null;
  }

  if (new URLSearchParams(window.location.search).get("oneshot") === "1") {
    onReceiveRoomState(initialState);
    return;
  }

  try {
    eventSource = new EventSource(`/api/room/stream?room=${encodeURIComponent(roomCode)}`);
    eventSource.onmessage = ev => {
      try {
        const st = JSON.parse(ev.data);
        onReceiveRoomState(st);
      } catch (_) {}
    };
  } catch (e) {
    // Fallback to fast polling
    let lastEvId = 0;
    pollTimer = setInterval(async () => {
      if (!currentRoomCode) return;
      try {
        const r = await fetch(`/api/room/state?room=${encodeURIComponent(currentRoomCode)}&since=${lastEvId}`);
        if (r.ok) {
          const st = await r.json();
          lastEvId = st.last_event_id || lastEvId;
          onReceiveRoomState(st);
        }
      } catch (_) {}
    }, 35);
  }
}

function onReceiveRoomState(st) {
  roomState = st;

  // Synchronize 60/120 FPS client-side unit visual interpolators
  const activeIds = new Set();
  if (st && Array.isArray(st.units)) {
    st.units.forEach(u => {
      activeIds.add(u.id);
      let vis = unitVisualState.get(u.id);
      const atkId = u.atk_id || 0;
      if (!vis || vis.key !== u.key) {
        vis = {
          key: u.key,
          renderX: u.x,
          targetX: u.x,
          localAf: u.af,
          anim: u.anim,
          atkId: atkId,
        };
        unitVisualState.set(u.id, vis);
      } else {
        vis.targetX = u.x;
        if (vis.anim !== u.anim || (u.anim === "attack" && vis.atkId !== atkId)) {
          vis.anim = u.anim;
          vis.atkId = atkId;
          vis.localAf = u.af;
        } else if (Math.abs(vis.localAf - u.af) > 3.0) {
          vis.localAf = u.af;
        }
      }
    });
  }
  for (const k of unitVisualState.keys()) {
    if (!activeIds.has(k)) unitVisualState.delete(k);
  }

  const statusEl = document.getElementById("battleStatusText");
  if (statusEl) {
    const roleStr = myTeam === TEAM_CAT ? "你操作：右側貓咪主堡 (P1)" : "你操作：左側主堡 (P2)";
    if (st.status === "WAITING") {
      statusEl.textContent = `等待朋友輸入房號【${st.room_code}】加入中... (${roleStr})`;
      statusEl.style.color = "#ffe680";
    } else if (st.status === "PLAYING") {
      statusEl.textContent = `${st.host_name} vs ${st.guest_name} ｜ ${roleStr}`;
      statusEl.style.color = "#82e0aa";
    } else if (st.status === "FINISHED") {
      const winText = st.winner === myTeam ? "勝利 VICTORY!" : "敗北 DEFEAT!";
      statusEl.textContent = `對戰結束：${winText}（可點擊右側「重新開局」）`;
      statusEl.style.color = "#ffcc33";
    }
  }

  // Process newly arrived combat visual events
  if (Array.isArray(st.events)) {
    st.events.forEach(item => {
      const ev = item.ev;
      if (!ev) return;
      if (ev.type === "damage") {
        // Authentic PONOS Battle Cats: NO floating damage text pops up on attack;
        // only the official 000_a.png hit spark and critical hit star appear.
        const jy = (Math.random() - 0.5) * 18;
        const hitX = ev.x + (ev.team === TEAM_CAT ? -32 : 32);
        fxHitSparks.push({
          x: hitX + (Math.random() - 0.5) * 14,
          y: GROUND_Y - 28 + jy,
          isCrit: !!ev.is_crit,
          age: 0,
        });
      } else if (ev.type === "death") {
        fxDeathSouls.push({
          x: ev.x,
          y: GROUND_Y - 30,
          age: 0,
        });
      } else if (ev.type === "cannon_beam") {
        fxCannonBeams.push({
          startX: ev.start_x,
          endX: ev.end_x,
          castleX: ev.castle_x || ev.start_x,
          team: ev.team || 0,
          age: 0,
          maxLife: 28,
        });
      } else if (ev.type === "wave_proc" || ev.type === "wave_attack") {
        const dir = ev.direction || (ev.end_x !== undefined && ev.start_x !== undefined ? (ev.end_x < ev.start_x ? -1 : 1) : -1);
        fxWaves.push({
          startX: ev.start_x,
          dir: dir,
          lvl: ev.level || 2,
          team: ev.team || 0,
          age: 0,
        });
      }
    });
  }
}

async function sendRoomAction(action, payload = null) {
  if (!currentRoomCode) return;
  try {
    await fetch("/api/room/action", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        room_code: currentRoomCode,
        team: myTeam,
        action,
        payload,
      }),
    });
  } catch (_) {}
}

function triggerRematch() {
  sendRoomAction("REMATCH");
}

function changeBattleSpeed(val) {
  sendRoomAction("SET_SPEED", parseFloat(val) || 1.0);
  showToast(`已切換對戰速度為 ${val}x`);
}

function copyRoomCode() {
  if (!currentRoomCode) return;
  navigator.clipboard.writeText(currentRoomCode);
  showToast(`已複製房號：${currentRoomCode}`);
}

// ============================================================================
// 3. AUTHENTIC PONOS 2D SKELETAL ANIMATION EVALUATOR (.imgcut + .mamodel + .maanim)
// ============================================================================

function evalPolynomialEase(kfs, kfIdx, localFrame) {
  let high = kfIdx;
  let low = kfIdx;
  for (let j = kfIdx - 1; j >= 0; j--) {
    if (kfs[j][2] === 3) low = j;
    else break;
  }
  for (let j = kfIdx + 1; j < kfs.length; j++) {
    high = j;
    if (kfs[j][2] !== 3) break;
  }
  let sum = 0.0;
  for (let j = low; j <= high; j++) {
    let val = kfs[j][1] * 4096.0;
    for (let k = low; k <= high; k++) {
      if (k !== j) {
        const denom = kfs[j][0] - kfs[k][0];
        if (denom !== 0) {
          val = (val * (localFrame - kfs[k][0])) / denom;
        }
      }
    }
    sum += val;
  }
  return sum / 4096.0;
}

function evalTrackValue(track, frame) {
  const kfs = track.kfs;
  if (!kfs || kfs.length === 0) return null;
  const intFrame = Math.floor(frame);
  const startF = kfs[0][0];
  const endF = kfs[kfs.length - 1][0];
  if (intFrame < startF) return null;

  const span = endF - startF;
  let localF = intFrame;
  if (intFrame < endF || span <= 0) {
    localF = intFrame;
  } else if (track.loop === -1) {
    localF = ((intFrame - startF) % span) + startF;
  } else if (track.loop >= 1) {
    if ((intFrame - startF) / span < track.loop) {
      localF = ((intFrame - startF) % span) + startF;
    } else {
      localF = endF;
    }
  } else {
    localF = endF;
  }

  if (startF === endF) return kfs[0][1];
  if (localF >= endF) return kfs[kfs.length - 1][1];

  for (let i = 0; i < kfs.length - 1; i++) {
    const kf1 = kfs[i];
    const kf2 = kfs[i + 1];
    if (kf1[0] <= localF && localF < kf2[0]) {
      const fSpan = kf2[0] - kf1[0];
      const easeMode = kf1[2];
      const easePower = kf1[3];
      if (fSpan <= 0 || easeMode === 1) return kf1[1];
      const t = (localF - kf1[0]) / fSpan;
      let rawVal;
      if (easeMode === 0) {
        rawVal = kf1[1] + t * (kf2[1] - kf1[1]);
      } else if (easeMode === 2) {
        let factor;
        if (easePower >= 0) {
          factor = 1.0 - Math.sqrt(Math.max(0.0, 1.0 - Math.pow(t, easePower)));
        } else {
          factor = Math.sqrt(Math.max(0.0, 1.0 - Math.pow(1.0 - t, -easePower)));
        }
        rawVal = kf1[1] + factor * (kf2[1] - kf1[1]);
      } else if (easeMode === 3) {
        rawVal = evalPolynomialEase(kfs, i, localF);
      } else if (easeMode === 4) {
        const factor = (1.0 - Math.cos((t * Math.PI) / 2.0)) / 2.0;
        rawVal = kf1[1] + factor * (kf2[1] - kf1[1]);
      } else {
        rawVal = kf1[1] + t * (kf2[1] - kf1[1]);
      }
      return Math.trunc(rawVal);
    }
  }
  return kfs[kfs.length - 1][1];
}

function renderSkeletalRig(ctx, rigCode, animName, frame, rootX, rootY, scale = 0.62, flipH = false) {
  const rig = RIGS[rigCode] || RIGS["000_f"];
  if (!rig) return;
  const sheet = loadImage(`rig_${rig.code}`, rig.png);
  if (!sheet || !sheet.complete || sheet.naturalWidth === 0) return;

  const model = rig.model;
  const su = model.scale_unit || 1000;
  const au = model.angle_unit || 3600;
  const alu = model.alpha_unit || 1000;
  const rawParts = model.parts;
  const numParts = rawParts.length;
  const effScale = scale;

  // 1. Initialize runtime part state from base model
  const parts = new Array(numParts);
  for (let i = 0; i < numParts; i++) {
    const p = rawParts[i];
    parts[i] = {
      index: p[0],
      parent: p[1],
      unit: p[2],
      cut: p[3],
      z: p[4],
      baseX: p[5],
      baseY: p[6],
      basePx: p[7],
      basePy: p[8],
      baseSx: p[9],
      baseSy: p[10],
      baseRot: p[11],
      baseAlpha: p[12],
      glow: p[13],
      x: p[5],
      y: p[6],
      px: p[7],
      py: p[8],
      gsca: su,
      sx: p[9],
      sy: p[10],
      rot: p[11],
      alpha: p[12],
      hFlip: false,
      vFlip: false,
    };
  }

  // 2. Apply animation tracks at integer 30 FPS frame (matching tbcml UnitAnimation.set_frame)
  const intFrame = Math.floor(frame);
  const anim = (rig.anims && (rig.anims[animName] || rig.anims.walk)) || null;
  if (anim && anim.tracks) {
    for (let t = 0; t < anim.tracks.length; t++) {
      const tr = anim.tracks[t];
      const pid = tr.part;
      if (pid >= 0 && pid < numParts) {
        const val = evalTrackValue(tr, intFrame);
        if (val !== null) {
          const pt = parts[pid];
          switch (tr.mod) {
            case 0: pt.parent = val; break;
            case 1: pt.unit = val; break;
            case 2: pt.cut = val; break;
            case 3: pt.z = val * numParts + pt.index; break;
            case 4: pt.x = pt.baseX + val; break;
            case 5: pt.y = pt.baseY + val; break;
            case 6: pt.px = pt.basePx + val; break;
            case 7: pt.py = pt.basePy + val; break;
            case 8: pt.gsca = val; break;
            case 9: pt.sx = Math.trunc((val * pt.baseSx) / su); break;
            case 10: pt.sy = Math.trunc((val * pt.baseSy) / su); break;
            case 11: pt.rot = pt.baseRot + val; break;
            case 12: pt.alpha = Math.trunc((val * pt.baseAlpha) / alu); break;
            case 13: pt.hFlip = !!val; break;
            case 14: pt.vFlip = !!val; break;
          }
        }
      }
    }
  }

  // 3. Exact PONOS tbcml 2x3 Affine Matrix Hierarchy (tbcml/core/anim/model_part.py lines 327-357, 467-572)
  function getRealScale(idx) {
    const p = parts[idx];
    const gk = su ? p.gsca / su : 1.0;
    const sx = (su ? p.sx / su : 1.0) * gk * (p.hFlip ? -1.0 : 1.0);
    const sy = (su ? p.sy / su : 1.0) * gk * (p.vFlip ? -1.0 : 1.0);
    return [sx, sy];
  }

  function getRecursiveScale(idx, visited = new Set()) {
    if (visited.has(idx) || idx < 0 || idx >= numParts) return [1.0, 1.0];
    visited.add(idx);
    const p = parts[idx];
    const [sx, sy] = getRealScale(idx);
    if (p.parent >= 0 && p.parent < numParts && p.parent !== idx) {
      const [psx, psy] = getRecursiveScale(p.parent, visited);
      return [sx * psx, sy * psy];
    }
    return [sx, sy];
  }

  function getRecursiveAlpha(idx, visited = new Set()) {
    if (visited.has(idx) || idx < 0 || idx >= numParts) return 1.0;
    visited.add(idx);
    const p = parts[idx];
    const a = alu ? p.alpha / alu : 1.0;
    if (p.parent >= 0 && p.parent < numParts && p.parent !== idx) {
      return getRecursiveAlpha(p.parent, visited) * a;
    }
    return a;
  }

  function getBaseP0Size() {
    if (numParts > 0) {
      const p0 = parts[0];
      return [su ? p0.baseSx / su : 1.0, su ? p0.baseSy / su : 1.0];
    }
    return [1.0, 1.0];
  }

  function getMatrix(idx, visited = new Set()) {
    if (visited.has(idx) || idx < 0 || idx >= numParts) {
      return [1.0, 0.0, 0.0, 0.0, 1.0, 0.0];
    }
    visited.add(idx);
    const p = parts[idx];
    let m;
    let tSizX = effScale;
    let tSizY = effScale;

    if (p.parent >= 0 && p.parent < numParts && p.parent !== idx) {
      m = [...getMatrix(p.parent, visited)];
      const [parentRecSx, parentRecSy] = getRecursiveScale(p.parent);
      tSizX = parentRecSx * effScale;
      tSizY = parentRecSy * effScale;
    } else {
      m = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0];
    }

    if (p.index !== 0) {
      const tx = p.x * tSizX;
      const ty = p.y * tSizY;
      m[2] += m[0] * tx + m[1] * ty;
      m[5] += m[3] * tx + m[4] * ty;
    } else {
      let d0 = 0.0;
      let d1 = 0.0;
      if (model.ints && model.ints.length > 0 && model.ints[0].length >= 4) {
        d0 = model.ints[0][2];
        d1 = model.ints[0][3];
      }
      const [baseP0X, baseP0Y] = getBaseP0Size();
      const p3X = d0 * baseP0X * effScale;
      const p3Y = d1 * baseP0Y * effScale;
      const [recP0X, recP0Y] = getRecursiveScale(0);
      const px = p.px * recP0X * effScale;
      const py = p.py * recP0Y * effScale;
      const x = px - p3X;
      const y = py - p3Y;
      m[2] += m[0] * x + m[1] * y;
      m[5] += m[3] * x + m[4] * y;
    }

    if (p.rot !== 0) {
      const degrees = (p.rot / au) * 360.0;
      const rad = (degrees * Math.PI) / 180.0;
      const sinR = Math.sin(rad);
      const cosR = Math.cos(rad);
      const f0 = m[0] * cosR + m[1] * sinR;
      const f1 = m[3] * cosR + m[4] * sinR;
      const f2 = m[0] * -sinR + m[1] * cosR;
      const f3 = m[3] * -sinR + m[4] * cosR;
      m[0] = f0;
      m[3] = f1;
      m[1] = f2;
      m[4] = f3;
    }
    return m;
  }

  const order = [];
  for (let i = 0; i < numParts; i++) {
    order.push(i);
  }
  order.sort((a, b) => parts[a].z - parts[b].z || a - b);

  // 4. Draw sorted bone cuts onto Canvas using exact tbcml affine transform
  ctx.save();
  ctx.translate(rootX, rootY);
  if (flipH) {
    ctx.scale(-1, 1);
  }

  for (let k = 0; k < order.length; k++) {
    const i = order[k];
    const p = parts[i];
    if (p.parent < 0 || p.unit < 0 || p.cut < 0) continue;
    const cut = rig.cuts[p.cut];
    if (!cut || cut[2] <= 0 || cut[3] <= 0) continue;

    const alpha = Math.max(0.0, Math.min(1.0, getRecursiveAlpha(i)));
    if (alpha <= 0.01) continue;

    const [recSx, recSy] = getRecursiveScale(i);
    const scx = Math.abs(recSx * effScale);
    const scy = Math.abs(recSy * effScale);
    if (scx < 1e-4 || scy < 1e-4) continue;

    const m = getMatrix(i);
    const flipX = recSx < 0 ? -1.0 : 1.0;
    const flipY = recSy < 0 ? -1.0 : 1.0;
    const tM0 = m[0] * flipX;
    const tM1 = m[1] * flipY;
    const tM3 = m[3] * flipX;
    const tM4 = m[4] * flipY;

    ctx.save();
    ctx.transform(tM0, tM3, tM1, tM4, m[2], m[5]);
    ctx.globalAlpha = alpha;
    if (p.glow === 1 || p.glow === 2 || p.glow === 3 || p.glow === -1) {
      ctx.globalCompositeOperation = "lighter";
    }
    ctx.drawImage(
      sheet,
      cut[0],
      cut[1],
      cut[2],
      cut[3],
      -p.px * scx,
      -p.py * scy,
      cut[2] * scx,
      cut[3] * scy
    );
    ctx.restore();
  }

  ctx.restore();
}

// ============================================================================
// 4. BATTLEFIELD & OFFICIAL UI RENDERER (1280x720)
// ============================================================================

function drawSubImage(ctx, img, sx, sy, sw, sh, dx, dy, dw, dh, flipH = false) {
  if (!img || !img.complete || img.naturalWidth === 0) return;
  ctx.save();
  if (flipH) {
    ctx.translate(dx + dw, dy);
    ctx.scale(-1, 1);
    ctx.drawImage(img, sx, sy, sw, sh, 0, 0, dw, dh);
  } else {
    ctx.drawImage(img, sx, sy, sw, sh, dx, dy, dw, dh);
  }
  ctx.restore();
}

function renderBattleScene() {
  const canvas = document.getElementById("battleCanvas");
  if (!canvas) return;
  const ctx = canvas.getContext("2d");
  ctx.clearRect(0, 0, SCREEN_W, SCREEN_H);

  const st = roomState;
  const stageLen = (st && st.length) || 2600;

  // Auto-follow frontline if player isn't manually dragging camera
  if (manualCameraHold > 0) {
    manualCameraHold--;
  } else if (st && st.units && st.units.length > 0 && !isDraggingCam) {
    const myUnits = st.units.filter(u => u.team === myTeam);
    if (myUnits.length > 0) {
      const leadX = myTeam === TEAM_CAT
        ? Math.min(...myUnits.map(u => u.x))
        : Math.max(...myUnits.map(u => u.x));
      const targetCam = Math.max(-70, Math.min(stageLen - SCREEN_W + 70, leadX - SCREEN_W * 0.5));
      cameraX += (targetCam - cameraX) * 0.08;
    }
  }
  cameraX = Math.max(-70, Math.min(stageLen - SCREEN_W + 70, cameraX));
  const worldToScreenX = wx => wx - cameraX;

  // 1. Seamless Tiled Official Korea Stage Background (bg000.png: sky + grass + brown soil at bottom)
  const bg = IMAGES.bg000;
  if (bg && bg.complete && bg.naturalWidth > 0) {
    const scale = SCREEN_H / 510.0;
    const tileW = Math.round(768 * scale);
    const tileH = SCREEN_H;
    const rawOff = Math.floor(cameraX * 0.7) % tileW;
    const offset = (rawOff + tileW) % tileW;
    for (let x = -offset - tileW; x < SCREEN_W + tileW; x += tileW) {
      ctx.drawImage(bg, 1, 1, 768, 510, x, 0, tileW, tileH);
    }
  } else {
    ctx.fillStyle = "#87ceeb";
    ctx.fillRect(0, 0, SCREEN_W, GROUND_Y);
    ctx.fillStyle = "#7ec850";
    ctx.fillRect(0, GROUND_Y, SCREEN_W, 44);
    ctx.fillStyle = "#916b46";
    ctx.fillRect(0, GROUND_Y + 44, SCREEN_W, SCREEN_H - GROUND_Y - 44);
  }

  // 2. Castles & Modular Cat Cannon Turret
  const team0 = st && st.teams && st.teams["0"];
  const team1 = st && st.teams && st.teams["1"];
  const rightCastleX = worldToScreenX((team0 && team0.castle_x) || stageLen - 120);
  const leftCastleX = worldToScreenX((team1 && team1.castle_x) || 120);

  const ratio1 = team1 ? Math.min(1, team1.cannon_charge / Math.max(1, team1.cannon_max)) : 0;
  const ratio0 = team0 ? Math.min(1, team0.cannon_charge / Math.max(1, team0.cannon_max)) : 0;
  const topY1 = drawModularCatCastle(ctx, leftCastleX, true, team1 ? team1.cannon_anim : 0, ratio1);
  const topY0 = drawModularCatCastle(ctx, rightCastleX, false, team0 ? team0.cannon_anim : 0, ratio0);

  // Official Castle HP Digits (img001_tw.png cuts, NO synthetic green health bar)
  if (team1) drawCastleHp(ctx, leftCastleX, topY1 - 24, team1.castle_hp, team1.castle_max_hp);
  if (team0) drawCastleHp(ctx, rightCastleX, topY0 - 24, team0.castle_hp, team0.castle_max_hp);

  // 3. Cat Cannon Range Line & Icon on Battlefield when Local Player's Cannon is 100% Ready
  const myHud = st && st.teams && st.teams[String(myTeam)];
  if (myHud && myHud.cannon_charge >= myHud.cannon_max && IMAGES.img002 && IMAGES.img002.complete) {
    const cRange = (st && st.cannon_range) || 800;
    const rangeWorldX = myTeam === TEAM_CAT
      ? Math.max(60, myHud.castle_x - 30 - cRange)
      : Math.min(stageLen - 60, myHud.castle_x + 30 + cRange);
    const rSx = worldToScreenX(rangeWorldX);
    drawSubImage(ctx, IMAGES.img002, 441, 260, 9, 98, rSx - 4, GROUND_Y - 120, 9, 120);
    drawSubImage(ctx, IMAGES.img002, 442, 421, 69, 85, rSx - 28, GROUND_Y - 178, 56, 68, myTeam === TEAM_ENEMY);
  }

  // 4. Units (Sorted by slot for authentic depth layering, using 60/120 FPS smooth interpolation
  //    and PONOS's native .mamodel shadow part without synthetic ellipse or shadow-lifting kbY)
  if (st && Array.isArray(st.units)) {
    const sortedUnits = [...st.units].sort((a, b) => a.slot - b.slot);
    sortedUnits.forEach(u => {
      const vis = unitVisualState.get(u.id);
      const drawWorldX = vis ? vis.renderX : u.x;
      const drawAf = vis ? vis.localAf : u.af;
      // Shift visual root forward by dir * 48px so melee units (range=110..140) clash nose-to-nose
      const visualWorldX = drawWorldX + (u.team === TEAM_CAT ? -48 : 48);
      const sx = worldToScreenX(visualWorldX);
      if (sx < -240 || sx > SCREEN_W + 240) return;

      const zOff = (u.slot % 5) * 2 - 4;
      const rigObj = RIGS[u.rig] || RIGS["000_f"];
      const isEnemyRig = rigObj ? !!rigObj.is_enemy : u.rig.includes("_e");
      const flipH = isEnemyRig ? u.team === TEAM_CAT : u.team === TEAM_ENEMY;
      renderSkeletalRig(ctx, u.rig, u.anim, drawAf, sx, GROUND_Y + 4 + zOff, u.scale || 0.62, flipH);

      // Authentic Freeze Bind & Slow Status Icons (bg00.imgcut cuts 17, 18, 13)
      if (u.frz > 0 && IMAGES.bg000 && IMAGES.bg000.complete) {
        const fCut = Math.floor(clientTick / 4) % 2 === 0 ? [933, 248, 60, 60] : [871, 248, 60, 60];
        drawSubImage(ctx, IMAGES.bg000, fCut[0], fCut[1], fCut[2], fCut[3], sx - 36, GROUND_Y - 68 + zOff, 72, 72);
      } else if (u.slw > 0 && IMAGES.bg000 && IMAGES.bg000.complete) {
        drawSubImage(ctx, IMAGES.bg000, 772, 248, 45, 50, sx - 22, GROUND_Y - 76 + zOff, 45, 50);
      }
    });
  }

  // 5. Combat FX (Wave Pillars, Cat Cannon Laser & Shockwave Pillars, Hit Sparks, Death Souls)
  renderCombatFX(ctx, worldToScreenX);

  // 6. Bottom Deploy Bar UI & Top Wallet HUD
  renderDeployBar(ctx, myHud);
  renderTopHud(ctx, st);
}

function drawModularCatCastle(ctx, sx, isLeftTeam, cannonAnim, cannonRatio = 0) {
  const baseImg = IMAGES.castle_base;
  const turretImg = IMAGES.castle_turret;
  const plaqueImg = IMAGES.castle_plaque;
  const beamImg = IMAGES.castle_beam;

  const cw = Math.round(128 * 1.3);  // 166
  const ch = Math.round(256 * 1.3);  // 333
  const bw = Math.round(128 * 1.3);  // 166
  const bh = Math.round(128 * 1.3);  // 166
  const fcX = Math.round(sx - cw / 2);
  const fcY = GROUND_Y - ch;

  if (baseImg && baseImg.complete && turretImg && turretImg.complete) {
    let recoilX = 0;
    let liftOffset = 0;
    if (cannonAnim > 0) {
      recoilX = cannonAnim > 24 && cannonAnim % 2 === 0 ? (isLeftTeam ? 4 : -4) : 0;
    } else if (cannonRatio >= 1.0) {
      liftOffset = Math.round(Math.sin(clientTick * 0.2) * 1.5);
    }

    // 1. Full Turret Head + Radar Dish (nyankoCastle_000_00.png is 128x256, aligned with fc000.png)
    drawSubImage(ctx, turretImg, 0, 0, 128, 256, fcX + recoilX, fcY + liftOffset, cw, ch, isLeftTeam);
    // 2. Full Lower Castle Base (nyankoCastle_003_00.png is 128x128 at GROUND_Y - bh)
    drawSubImage(ctx, baseImg, 0, 0, 128, 128, Math.round(sx - bw / 2), GROUND_Y - bh, bw, bh, isLeftTeam);
    // 3. Full Hanging Cat Paw Plaque (nyankoCastle_002_00.png is 128x128 at exact same origin GROUND_Y - bh)
    if (plaqueImg && plaqueImg.complete) {
      drawSubImage(ctx, plaqueImg, 0, 0, 128, 128, Math.round(sx - bw / 2), GROUND_Y - bh, bw, bh, isLeftTeam);
    }
    // 4. Muzzle flash ONLY while actively firing (cannonAnim > 16)
    if (cannonAnim > 16 && beamImg && beamImg.complete) {
      const mx = isLeftTeam ? sx + 44 : sx - 44;
      const my = GROUND_Y - 195 + liftOffset;
      drawSubImage(ctx, beamImg, 154, 157, 84, 84, mx - 55, my - 55, 110, 110);
    }
    return fcY;
  } else if (IMAGES.fc000 && IMAGES.fc000.complete) {
    drawSubImage(ctx, IMAGES.fc000, 0, 0, 128, 256, fcX, fcY, cw, ch, isLeftTeam);
    return fcY;
  }
  return fcY;
}

function drawCastleHp(ctx, sx, y, hp, maxHp) {
  const hpStr = `${hp}/${maxHp}`;
  const im1 = IMAGES.img001;
  if (im1 && im1.complete && im1.naturalWidth > 0) {
    const charW = 15;
    const totalW = hpStr.length * charW;
    // Clamp horizontal position so HP digits are never clipped off the left/right screen edge
    let bx = Math.max(10, Math.min(SCREEN_W - totalW - 10, Math.round(sx - totalW / 2)));
    for (let i = 0; i < hpStr.length; i++) {
      const ch = hpStr[i];
      if (ch === "/") {
        // Official Castle HP '/' slash in img001_tw.imgcut cut 126: (474, 89, 14, 18)
        drawSubImage(ctx, im1, 474, 89, 14, 18, bx, y, 15, 20);
      } else {
        const d = ch.charCodeAt(0) - 48;
        if (d >= 0 && d <= 9) {
          drawSubImage(ctx, im1, 255 + d * 16, 89, 14, 18, bx, y, 15, 20);
        }
      }
      bx += charW;
    }
  } else {
    ctx.font = "900 16px Impact, Arial";
    ctx.textAlign = "center";
    ctx.strokeStyle = "#000";
    ctx.lineWidth = 3;
    ctx.strokeText(hpStr, sx, y + 16);
    ctx.fillStyle = "#fff";
    ctx.fillText(hpStr, sx, y + 16);
  }
}

function advanceClientFX30Fps() {
  for (let i = fxWaves.length - 1; i >= 0; i--) {
    fxWaves[i].age++;
    if (fxWaves[i].age > fxWaves[i].lvl * 4 + 14) fxWaves.splice(i, 1);
  }
  for (let i = fxCannonBeams.length - 1; i >= 0; i--) {
    fxCannonBeams[i].age++;
    if (fxCannonBeams[i].age >= fxCannonBeams[i].maxLife) fxCannonBeams.splice(i, 1);
  }
  for (let i = fxHitSparks.length - 1; i >= 0; i--) {
    fxHitSparks[i].age++;
    if (fxHitSparks[i].age >= 11) fxHitSparks.splice(i, 1);
  }
  for (let i = fxDeathSouls.length - 1; i >= 0; i--) {
    fxDeathSouls[i].age++;
    if (fxDeathSouls[i].age >= 45) fxDeathSouls.splice(i, 1);
  }
  for (let i = fxFloatingTexts.length - 1; i >= 0; i--) {
    fxFloatingTexts[i].age++;
    if (fxFloatingTexts[i].age >= 26) fxFloatingTexts.splice(i, 1);
  }
}

function renderCombatFX(ctx, worldToScreenX) {
  // 1. Wave Attack Pillars (bg00.imgcut cuts 7..12 for Blue Wave, cuts 1..6 for Pink Wave)
  const blueWaveCuts = [
    [888, 83, 56, 80],
    [946, 83, 56, 80],
    [772, 165, 56, 80],
    [830, 165, 56, 80],
    [888, 165, 56, 80],
    [946, 165, 56, 80],
  ];
  const pinkWaveCuts = [
    [772, 1, 56, 80],
    [830, 1, 56, 80],
    [888, 1, 56, 80],
    [946, 1, 56, 80],
    [772, 83, 56, 80],
    [830, 83, 56, 80],
  ];
  for (let i = fxWaves.length - 1; i >= 0; i--) {
    const w = fxWaves[i];
    const waveCuts = w.team === TEAM_ENEMY ? pinkWaveCuts : blueWaveCuts;
    for (let lv = 0; lv < w.lvl; lv++) {
      const trig = lv * 4;
      const localAge = w.age - trig;
      if (localAge >= 0 && localAge < 12 && IMAGES.bg000 && IMAGES.bg000.complete) {
        const px = worldToScreenX(w.startX + w.dir * (lv * 130 + 60));
        const cIdx = Math.min(waveCuts.length - 1, Math.floor(localAge / 2));
        const wc = waveCuts[cIdx];
        drawSubImage(ctx, IMAGES.bg000, wc[0], wc[1], wc[2], wc[3], px - 45, GROUND_Y - 132, 90, 138, w.dir > 0);
      }
    }
  }

  // 2. Cat Cannon Laser Beam & Sweeping Shockwave Explosion Pillars (nyankoCastle_001_00_00.png)
  const pillarCuts = [
    [78, 156, 74, 41, 96, 54],
    [1, 1, 74, 111, 96, 144],
    [154, 23, 74, 131, 96, 170],
    [2, 114, 74, 131, 96, 170],
    [78, 23, 74, 131, 96, 170],
  ];
  for (let i = fxCannonBeams.length - 1; i >= 0; i--) {
    const cb = fxCannonBeams[i];
    const sSx = worldToScreenX(cb.startX);
    const cSx = worldToScreenX(cb.castleX);
    if (cb.age <= 12 && IMAGES.castle_beam && IMAGES.castle_beam.complete) {
      const muzzleX = cb.team === TEAM_CAT ? cSx - 44 : cSx + 44;
      const muzzleY = GROUND_Y - 195;
      drawSubImage(ctx, IMAGES.castle_beam, 154, 157, 84, 84, muzzleX - 55, muzzleY - 55, 110, 110);
      // Vertical laser beam cut (145, 249, 110, 6 rotated 90 deg)
      ctx.save();
      ctx.translate(sSx, muzzleY);
      ctx.rotate(Math.PI / 2);
      ctx.drawImage(IMAGES.castle_beam, 145, 249, 110, 6, 0, -8, GROUND_Y - muzzleY, 16);
      ctx.restore();
    }
    const dist = Math.abs(cb.endX - cb.startX);
    const dir = cb.endX < cb.startX ? -1 : 1;
    const stepPx = 72;
    const count = Math.max(1, Math.floor(dist / stepPx) + 1);
    for (let p = 0; p < count; p++) {
      const trig = Math.floor((p / count) * 14);
      const lAge = cb.age - trig;
      if (lAge >= 0 && lAge < 12 && IMAGES.castle_beam && IMAGES.castle_beam.complete) {
        const psx = worldToScreenX(cb.startX + dir * p * stepPx);
        const cIdx = Math.min(pillarCuts.length - 1, Math.floor(lAge / 2));
        const pc = pillarCuts[cIdx];
        drawSubImage(ctx, IMAGES.castle_beam, pc[0], pc[1], pc[2], pc[3], psx - pc[4] / 2, GROUND_Y - pc[5] + 8, pc[4], pc[5]);
      }
    }
  }

  // 3. Hit Sparks & Critical Hit Stars (000_a.png)
  const hitCuts = [
    [1, 1, 55, 47],
    [1, 50, 55, 47],
    [1, 99, 55, 47],
    [1, 148, 55, 47],
    [1, 197, 55, 47],
  ];
  for (let i = fxHitSparks.length - 1; i >= 0; i--) {
    const hs = fxHitSparks[i];
    const sx = worldToScreenX(hs.x);
    if (IMAGES.hit_a && IMAGES.hit_a.complete) {
      const idx = Math.min(hitCuts.length - 1, Math.floor(hs.age / 2));
      const c = hitCuts[idx];
      drawSubImage(ctx, IMAGES.hit_a, c[0], c[1], c[2], c[3], sx - 33, hs.y - 28, 66, 56);
      if (hs.isCrit) {
        drawSubImage(ctx, IMAGES.hit_a, 58, 133, 50, 46, sx - 31, hs.y - 38, 62, 58);
      }
    }
  }

  // 4. Ascending Winged Halo Death Souls (battle_soul_000.png vertical cuts 1, 1 + i*58, 48, 56)
  const soulCuts = [
    [1, 1, 48, 56],
    [1, 59, 48, 56],
    [1, 117, 48, 56],
    [1, 175, 48, 56],
  ];
  for (let i = fxDeathSouls.length - 1; i >= 0; i--) {
    const ds = fxDeathSouls[i];
    const sx = worldToScreenX(ds.x) + Math.sin((ds.age * Math.PI) / 8.0) * 10;
    const sy = ds.y - ds.age * 2.5;
    if (IMAGES.soul && IMAGES.soul.complete) {
      const c = soulCuts[Math.floor(ds.age / 3) % 4];
      ctx.save();
      if (ds.age > 30) ctx.globalAlpha = Math.max(0, 1 - (ds.age - 30) / 15.0);
      drawSubImage(ctx, IMAGES.soul, c[0], c[1], c[2], c[3], sx - 29, sy - 34, 58, 68);
      ctx.restore();
    }
  }
}

function drawSmallCostDigits(ctx, costVal, rightX, y, isBright) {
  const im1 = IMAGES.img001;
  if (!im1 || !im1.complete || im1.naturalWidth === 0) return;
  const str = String(costVal);
  // Draw "元" on the right
  if (isBright) {
    drawSubImage(ctx, im1, 1, 176, 22, 26, rightX - 14, y, 14, 18);
  } else {
    drawSubImage(ctx, im1, 241, 148, 22, 26, rightX - 14, y, 14, 18);
  }
  let curX = rightX - 15;
  for (let i = str.length - 1; i >= 0; i--) {
    const d = str.charCodeAt(i) - 48;
    if (d >= 0 && d <= 9) {
      curX -= 12;
      if (isBright) {
        drawSubImage(ctx, im1, 41 + d * 20, 148, 18, 26, curX, y, 12, 18);
      } else {
        drawSubImage(ctx, im1, 25 + d * 20, 176, 18, 26, curX, y, 12, 18);
      }
    }
  }
}

function drawBigWalletDigits(ctx, curMoney, maxMoney, startX, y, alignRight = true) {
  const im1 = IMAGES.img001;
  if (!im1 || !im1.complete || im1.naturalWidth === 0) return;
  const digitCuts = {
    "0": [1, 1, 30, 42],
    "1": [33, 1, 30, 42],
    "2": [65, 1, 30, 42],
    "3": [97, 1, 30, 42],
    "4": [129, 1, 30, 42],
    "5": [161, 1, 30, 42],
    "6": [193, 1, 30, 42],
    "7": [225, 1, 30, 42],
    "8": [1, 45, 30, 42],
    "9": [33, 45, 30, 42],
    "/": [66, 45, 29, 42],
    unit: [102, 45, 30, 42],
  };

  const curStr = String(curMoney);
  const maxStr = String(maxMoney);
  if (alignRight) {
    let curX = startX;
    // '元'
    const uRec = digitCuts.unit;
    curX -= uRec[2];
    drawSubImage(ctx, im1, uRec[0], uRec[1], uRec[2], uRec[3], curX, y, uRec[2], uRec[3]);
    curX -= 4;
    for (let i = maxStr.length - 1; i >= 0; i--) {
      const rec = digitCuts[maxStr[i]];
      if (rec) {
        curX -= rec[2] + 2;
        drawSubImage(ctx, im1, rec[0], rec[1], rec[2], rec[3], curX, y, rec[2], rec[3]);
      }
    }
    const sRec = digitCuts["/"];
    curX -= sRec[2] + 4;
    drawSubImage(ctx, im1, sRec[0], sRec[1], sRec[2], sRec[3], curX, y, sRec[2], sRec[3]);
    for (let i = curStr.length - 1; i >= 0; i--) {
      const rec = digitCuts[curStr[i]];
      if (rec) {
        curX -= rec[2] + 2;
        drawSubImage(ctx, im1, rec[0], rec[1], rec[2], rec[3], curX, y, rec[2], rec[3]);
      }
    }
  } else {
    let lx = startX;
    for (let i = 0; i < curStr.length; i++) {
      const rec = digitCuts[curStr[i]];
      if (rec) {
        drawSubImage(ctx, im1, rec[0], rec[1], rec[2], rec[3], lx, y, rec[2], rec[3]);
        lx += rec[2] + 2;
      }
    }
    const sRec = digitCuts["/"];
    drawSubImage(ctx, im1, sRec[0], sRec[1], sRec[2], sRec[3], lx, y, sRec[2], sRec[3]);
    lx += sRec[2] + 4;
    for (let i = 0; i < maxStr.length; i++) {
      const rec = digitCuts[maxStr[i]];
      if (rec) {
        drawSubImage(ctx, im1, rec[0], rec[1], rec[2], rec[3], lx, y, rec[2], rec[3]);
        lx += rec[2] + 2;
      }
    }
    const uRec = digitCuts.unit;
    drawSubImage(ctx, im1, uRec[0], uRec[1], uRec[2], uRec[3], lx + 2, y, uRec[2], uRec[3]);
  }
}

function renderDeployBar(ctx, myHud) {
  if (!myHud) return;
  const im1 = IMAGES.img001;
  const im2 = IMAGES.img002;
  const blinkPhase = Math.floor(clientTick / 6) % 2 === 1;

  // 1. Left: Official Worker Cat Upgrade Button (16, 586, 168, 112) over bg000.png's natural brown soil
  const wMax = myHud.worker_lv >= 8 || myHud.worker_cost === null || myHud.worker_cost <= 0;
  const wCan = !wMax && myHud.money >= myHud.worker_cost;
  if (im2 && im2.complete) {
    if (wCan) {
      drawSubImage(ctx, im2, blinkPhase ? 197 : 1, 1, 194, 121, 16, 586, 168, 112);
    } else if (wMax) {
      drawSubImage(ctx, im2, 1, 1, 194, 121, 16, 586, 168, 112);
    } else {
      drawSubImage(ctx, im2, 393, 1, 194, 121, 16, 586, 168, 112);
    }
  }
  if (im1 && im1.complete) {
    const useBrightLvl = wCan || wMax;
    if (useBrightLvl) {
      drawSubImage(ctx, im1, 1, 89, 68, 27, 32, 598, 52, 20);
      const lv = Math.min(8, Math.max(1, myHud.worker_lv));
      drawSubImage(ctx, im1, 75 + lv * 20, 89, 18, 27, 86, 598, 14, 20);
    } else {
      drawSubImage(ctx, im1, 21, 118, 68, 27, 32, 598, 52, 20);
      const lv = Math.min(7, Math.max(1, myHud.worker_lv));
      drawSubImage(ctx, im1, 95 + lv * 20, 118, 18, 27, 86, 598, 14, 20);
    }
    if (wMax) {
      drawSubImage(ctx, im1, 449, 45, 62, 26, 34, 672, 46, 20);
    } else {
      drawSmallCostDigits(ctx, myHud.worker_cost, 97, 672, wCan);
    }
  }

  // 2. Center: Authentic PONOS 2-Row ("2段表示") 10-Card Formation Grid (5 columns x 2 rows)
  const cards = myHud.cards || [];
  const cw = 110;
  const ch = 82;
  const startX = 329;
  const stepX = 128;

  for (let row = 0; row < 2; row++) {
    const cy = row === 0 ? 528 : 620;
    for (let col = 0; col < 5; col++) {
      const slotIdx = row * 5 + col;
      const card = cards[slotIdx];
      const cx = startX + col * stepX;

      if (card) {
        const canBuy = myHud.money >= card.cost && card.cd <= 0;

        // IMPORTANT: Draw img002_tw cut 49 (134, 410, 126, 101) BEFORE the unit portrait
        // because cut 49 has a solid white center with a golden outer glow!
        if (canBuy && im2 && im2.complete) {
          drawSubImage(ctx, im2, 134, 410, 126, 101, cx - 7, cy - 7, cw + 14, ch + 14);
        }

        let drawnPortrait = false;
        if (card.icon && !card.custom) {
          const iconImg = loadImage(`icon_${card.icon}`, `/assets/${card.icon}.png`);
          if (iconImg && iconImg.complete && iconImg.naturalWidth > 0) {
            drawSubImage(ctx, iconImg, 9, 21, 110, 85, cx, cy, cw, ch);
            drawnPortrait = true;
          }
        }
        if (!drawnPortrait) {
          const baseIdx = ["cat", "tank_cat", "axe_cat", "gross_cat", "cow_cat", "bird_cat", "fish_cat", "lizard_cat", "titan_cat"].indexOf(card.key);
          if (baseIdx >= 0 && IMAGES[`uni_${baseIdx}`] && IMAGES[`uni_${baseIdx}`].complete) {
            // Crop exact (9, 21, 110, 85) from 128x128 uni00*_f00.png to remove transparent padding
            drawSubImage(ctx, IMAGES[`uni_${baseIdx}`], 9, 21, 110, 85, cx, cy, cw, ch);
            drawnPortrait = true;
          } else if (card.rig && card.rig.includes("_")) {
            const numPart = parseInt(card.rig.split("_")[0], 10);
            const isCatRig = !card.rig.includes("_e");
            if (isCatRig && !isNaN(numPart) && numPart >= 0 && numPart < 9 && IMAGES[`uni_${numPart}`] && IMAGES[`uni_${numPart}`].complete) {
              drawSubImage(ctx, IMAGES[`uni_${numPart}`], 9, 21, 110, 85, cx, cy, cw, ch);
              drawnPortrait = true;
            }
          }
        }

        if (!drawnPortrait) {
          // Authentic PONOS-styled card frame for custom units using Boss/Enemy rigs (e.g. 018_e, 015_e)
          ctx.fillStyle = "#e6dec3";
          ctx.fillRect(cx, cy, cw, ch);
          ctx.strokeStyle = "#111111";
          ctx.lineWidth = 3;
          ctx.strokeRect(cx + 1.5, cy + 1.5, cw - 3, ch - 3);
          ctx.save();
          ctx.beginPath();
          ctx.rect(cx + 3, cy + 3, cw - 6, ch - 6);
          ctx.clip();
          const rigObj = RIGS[card.rig] || RIGS["000_f"];
          const isEnemyRig = rigObj ? !!rigObj.is_enemy : (card.rig || "").includes("_e");
          renderSkeletalRig(ctx, card.rig || "000_f", "idle", 0, cx + cw * 0.45, cy + ch - 8, 0.34, isEnemyRig);
          ctx.restore();
          // Golden price tag box in bottom-right matching uni00*_f00.png
          ctx.fillStyle = "#f5b915";
          ctx.fillRect(cx + cw - 56, cy + ch - 23, 53, 20);
          ctx.strokeStyle = "#111";
          ctx.lineWidth = 1.5;
          ctx.strokeRect(cx + cw - 56, cy + ch - 23, 53, 20);
        }

        // Dim card when on cooldown or insufficient money (portrait remains clearly visible)
        if (!canBuy) {
          ctx.fillStyle = "rgba(0, 0, 0, 0.50)";
          ctx.fillRect(cx + 2, cy + 2, cw - 4, ch - 4);
        }

        if (card.custom) {
          ctx.fillStyle = "rgba(22, 16, 38, 0.86)";
          ctx.fillRect(cx + 3, cy + 3, cw - 6, 16);
          ctx.font = "700 11px Microsoft JhengHei, sans-serif";
          ctx.textAlign = "center";
          ctx.fillStyle = "#ff9ff3";
          ctx.fillText(card.name.slice(0, 8), cx + cw / 2, cy + 14);
        }

        if (card.cd > 0) {
          const ratio = Math.max(0, Math.min(1, 1 - card.cd / Math.max(1, card.max_cd)));
          ctx.fillStyle = "#141820";
          ctx.fillRect(cx + 10, cy + ch / 2 - 6, cw - 20, 12);
          ctx.fillStyle = "#48dbfb";
          ctx.fillRect(cx + 12, cy + ch / 2 - 4, Math.round((cw - 24) * ratio), 8);
        }

        drawSmallCostDigits(ctx, card.cost, cx + cw - 5, cy + ch - 21, myHud.money >= card.cost);
      } else {
        // Empty Formation Slot (authentic dark translucent slot box)
        ctx.fillStyle = "rgba(18, 16, 14, 0.55)";
        ctx.fillRect(cx, cy, cw, ch);
        ctx.strokeStyle = "rgba(10, 10, 10, 0.85)";
        ctx.lineWidth = 3;
        ctx.strokeRect(cx + 1.5, cy + 1.5, cw - 3, ch - 3);
      }
    }
  }

  // 3. Right: Official Cat Cannon Button (1096, 586, 168, 112)
  const cReady = myHud.cannon_charge >= myHud.cannon_max;
  if (im2 && im2.complete) {
    if (cReady) {
      drawSubImage(ctx, im2, blinkPhase ? 197 : 1, 124, 194, 130, 1096, 586, 168, 112);
      drawSubImage(ctx, im2, blinkPhase ? 312 : 185, 260, 125, 55, 1124, 644, 112, 48);
    } else {
      drawSubImage(ctx, im2, 393, 124, 194, 130, 1096, 586, 168, 112);
      const stepCount = Math.floor((myHud.cannon_charge / Math.max(1, myHud.cannon_max)) * 10);
      if (stepCount > 0) {
        const srcH = Math.round((130 * stepCount) / 10.0);
        const dstH = Math.round((112 * stepCount) / 10.0);
        drawSubImage(ctx, im2, 1, 124 + (130 - srcH), 194, srcH, 1096, 586 + (112 - dstH), 168, dstH);
      }
    }
  }
}

function renderTopHud(ctx, st) {
  if (!st || !st.teams) return;
  const myHud = st.teams[String(myTeam)];
  const oppTeam = myTeam === TEAM_CAT ? TEAM_ENEMY : TEAM_CAT;
  const oppHud = st.teams[String(oppTeam)];

  // 1. Official Top-Left Pause Button (img002_tw.png 519, 256, 58, 58)
  if (IMAGES.img002 && IMAGES.img002.complete) {
    drawSubImage(ctx, IMAGES.img002, 519, 256, 58, 58, 16, 14, 58, 58);
  }

  // 2. Top-Right: Local Player's Authentic Gold Bitmap Wallet
  if (myHud) {
    drawBigWalletDigits(ctx, myHud.money, myHud.max_money, SCREEN_W - 18, 16, true);
  }

  // 3. Compact PvP Room & Opponent Status Pill next to Top-Left Pause Button
  const pillTxt = `【房號 ${st.room_code}】${myTeam === TEAM_CAT ? "P1 右側主堡" : "P2 左側主堡"} ｜ 對手錢包 Lv.${oppHud ? oppHud.worker_lv : 1} (${oppHud ? oppHud.money : 0}元)`;
  ctx.font = "700 13px Microsoft JhengHei, sans-serif";
  const tw = ctx.measureText(pillTxt).width;
  ctx.fillStyle = "rgba(18, 22, 32, 0.78)";
  ctx.fillRect(84, 22, tw + 20, 26);
  ctx.strokeStyle = "rgba(255, 204, 51, 0.55)";
  ctx.lineWidth = 1.5;
  ctx.strokeRect(84, 22, tw + 20, 26);
  ctx.fillStyle = "#7bed9f";
  ctx.textAlign = "left";
  ctx.fillText(pillTxt, 94, 39);

  // Waiting / Victory Banner Overlay on Canvas
  if (st.status === "WAITING") {
    ctx.fillStyle = "rgba(10, 14, 24, 0.72)";
    ctx.fillRect(SCREEN_W / 2 - 290, 160, 580, 130);
    ctx.strokeStyle = "#ffcc33";
    ctx.lineWidth = 3;
    ctx.strokeRect(SCREEN_W / 2 - 290, 160, 580, 130);
    ctx.textAlign = "center";
    ctx.font = "900 28px Microsoft JhengHei, sans-serif";
    ctx.fillStyle = "#ffcc33";
    ctx.fillText(`房間已建立！房號：${st.room_code}`, SCREEN_W / 2, 210);
    ctx.font = "700 16px Microsoft JhengHei, sans-serif";
    ctx.fillStyle = "#fff";
    ctx.fillText("請讓朋友打開此網頁並輸入上方 4 位數房號即可立即開戰！", SCREEN_W / 2, 255);
  } else if (st.game_over) {
    ctx.fillStyle = "rgba(10, 14, 24, 0.78)";
    ctx.fillRect(SCREEN_W / 2 - 240, 170, 480, 120);
    ctx.strokeStyle = "#ffcc33";
    ctx.lineWidth = 3;
    ctx.strokeRect(SCREEN_W / 2 - 240, 170, 480, 120);
    ctx.textAlign = "center";
    ctx.font = "900 36px Microsoft JhengHei, sans-serif";
    ctx.fillStyle = st.winner === myTeam ? "#2ecc71" : "#ff4757";
    ctx.fillText(st.winner === myTeam ? "勝利 VICTORY!" : "敗北 DEFEAT!", SCREEN_W / 2, 228);
    ctx.font = "700 15px Microsoft JhengHei, sans-serif";
    ctx.fillStyle = "#fff";
    ctx.fillText("點擊上方「重新開局 (Rematch)」可立即再戰一場", SCREEN_W / 2, 266);
  }
}

// ============================================================================
// 5. STUDIO PREVIEW & INPUT EVENT HANDLERS
// ============================================================================

function renderStudioPreview() {
  const pCanvas = document.getElementById("previewCanvas");
  if (!pCanvas) return;
  const ctx = pCanvas.getContext("2d");
  ctx.clearRect(0, 0, pCanvas.width, pCanvas.height);

  const rigCode = document.getElementById("cuRig").value || "004_f";
  const scale = parseFloat(document.getElementById("cuScale").value) || 0.75;
  const animName = document.getElementById("previewAnimSelect").value || "walk";

  renderSkeletalRig(ctx, rigCode, animName, previewFrame, 240, 235, scale, false);
}

function setupBattleControls() {
  const canvas = document.getElementById("battleCanvas");
  if (!canvas) return;

  canvas.addEventListener("mousedown", e => {
    const rect = canvas.getBoundingClientRect();
    const mx = ((e.clientX - rect.left) / rect.width) * SCREEN_W;
    const my = ((e.clientY - rect.top) / rect.height) * SCREEN_H;

    if (my >= 522) {
      // Deploy Bar Clicks (Worker Cat, 10-Card 2-Row Formation Grid, Cat Cannon)
      if (mx >= 16 && mx <= 184 && my >= 586 && my <= 698) {
        sendRoomAction("UPGRADE_WORKER");
      } else if (mx >= 1096 && mx <= 1264 && my >= 586 && my <= 698) {
        sendRoomAction("FIRE_CANNON");
      } else {
        const cw = 110;
        const ch = 82;
        const startX = 329;
        const stepX = 128;
        for (let row = 0; row < 2; row++) {
          const cy = row === 0 ? 528 : 620;
          for (let col = 0; col < 5; col++) {
            const cx = startX + col * stepX;
            if (mx >= cx && mx <= cx + cw && my >= cy && my <= cy + ch) {
              sendRoomAction("SPAWN_UNIT", row * 5 + col);
              return;
            }
          }
        }
      }
    } else {
      isDraggingCam = true;
      dragStartX = mx;
      dragStartCamX = cameraX;
      manualCameraHold = 120;
    }
  });

  window.addEventListener("mousemove", e => {
    if (!isDraggingCam) return;
    const rect = canvas.getBoundingClientRect();
    const mx = ((e.clientX - rect.left) / rect.width) * SCREEN_W;
    cameraX = dragStartCamX - (mx - dragStartX) * 1.4;
    manualCameraHold = 120;
  });

  window.addEventListener("mouseup", () => {
    isDraggingCam = false;
  });

  window.addEventListener("keydown", e => {
    if (document.activeElement && ["INPUT", "SELECT", "TEXTAREA"].includes(document.activeElement.tagName)) {
      return;
    }
    const row1Keys = ["1", "2", "3", "4", "5"];
    const row2NumKeys = ["6", "7", "8", "9", "0"];
    const row2LetKeys = ["q", "w", "e", "r", "t"];
    const kLower = e.key.toLowerCase();
    if (row1Keys.includes(e.key)) {
      sendRoomAction("SPAWN_UNIT", row1Keys.indexOf(e.key));
    } else if (row2NumKeys.includes(e.key)) {
      sendRoomAction("SPAWN_UNIT", 5 + row2NumKeys.indexOf(e.key));
    } else if (row2LetKeys.includes(kLower)) {
      sendRoomAction("SPAWN_UNIT", 5 + row2LetKeys.indexOf(kLower));
    } else if (kLower === "z") {
      sendRoomAction("UPGRADE_WORKER");
    } else if (e.key === " ") {
      e.preventDefault();
      sendRoomAction("FIRE_CANNON");
    } else if (e.key === "ArrowLeft" || kLower === "a") {
      cameraX -= 45;
      manualCameraHold = 90;
    } else if (e.key === "ArrowRight" || kLower === "d") {
      cameraX += 45;
      manualCameraHold = 90;
    }
  });
}

let lastTickTime = performance.now();
let lastRenderTime = performance.now();
const FRAME_MS_30FPS = 1000.0 / 30.0;

function renderLoop(now = performance.now()) {
  const dt = Math.min(0.1, Math.max(0.0, (now - lastRenderTime) / 1000.0));
  lastRenderTime = now;

  // Advance 60/120 FPS smooth unit positions & continuous animation clocks
  const speedMult = (roomState && roomState.speed_mult) || 1.0;
  const df = dt * 30.0 * speedMult;
  previewFrame += dt * 30.0;

  if (roomState && roomState.status === "PLAYING" && !roomState.game_over && Array.isArray(roomState.units)) {
    roomState.units.forEach(u => {
      const vis = unitVisualState.get(u.id);
      if (!vis) return;
      if (!(u.frz > 0 && u.anim !== "kb")) {
        vis.localAf += df;
        if (u.anim === "attack") {
          const rigObj = RIGS[u.rig];
          const maxAtkF = (rigObj && rigObj.anims && rigObj.anims.attack && rigObj.anims.attack.max_frame) || 30;
          if (vis.localAf > maxAtkF) vis.localAf = maxAtkF;
        }
      }
      const dir = u.team === TEAM_CAT ? -1.0 : 1.0;
      if (u.anim === "walk" && !(u.frz > 0)) {
        const effSpd = u.slw > 0 ? 0.5 : Math.max(0.5, (u.spd || 10.0) * 0.5);
        vis.renderX += dir * effSpd * df;
      } else if (u.anim === "kb") {
        vis.renderX -= dir * 7.0 * df;
      }
      const errX = vis.targetX - vis.renderX;
      if (Math.abs(errX) > 80.0) {
        vis.renderX = vis.targetX;
      } else {
        vis.renderX += errX * Math.min(1.0, dt * 18.0);
      }
    });
  }

  const elapsed = now - lastTickTime;
  if (elapsed >= FRAME_MS_30FPS) {
    const ticks = Math.min(4, Math.floor(elapsed / FRAME_MS_30FPS));
    lastTickTime += ticks * FRAME_MS_30FPS;
    for (let t = 0; t < ticks; t++) {
      clientTick++;
      advanceClientFX30Fps();
    }
  }

  const lobbySec = document.getElementById("view-lobby");
  if (lobbySec && lobbySec.classList.contains("active")) {
    renderFormationPreview();
  }
  const battleSec = document.getElementById("view-battle");
  if (battleSec && battleSec.classList.contains("active")) {
    renderBattleScene();
  }
  const studioSec = document.getElementById("view-studio");
  if (studioSec && studioSec.classList.contains("active")) {
    renderStudioPreview();
  }

  requestAnimationFrame(renderLoop);
}

window.addEventListener("DOMContentLoaded", initApp);
