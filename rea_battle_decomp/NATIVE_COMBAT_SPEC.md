# Battle Cats Native Combat Engine Specification (`libnative-lib.so` ARM64)

> **Source Binary**: `E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so` (strictly read-only; analyzed via Ghidra 12.1.4 Headless `-noanalysis -readOnly`, Capstone, and Unicorn Engine ARM64 emulation).
> **Coordinate Convention**: Ghidra `ImageBase = 0x100000`, so `Ghidra Addr = ELF VMA + 0x100000`. In `PT_LOAD[2]` (`.data`, `vaddr = 0xb0a6b0`, `off = 0xb026b0`), `file_off = ELF VMA - 0x8000` (e.g., Ghidra `0x00c0xxxx` = ELF `0x00b0xxxx`).
> **Scope**: Pure reverse-engineered native specification stored under `E:\rea\rea_battle_decomp\`. Neither `E:\rea\game_project\` nor `E:\rea\rea\` was modified.

---

## 1. Decompilation Pipeline & Coverage

| Output Directory / Tool | Role | Key Artifacts |
| :--- | :--- | :--- |
| `E:\rea\rea_battle_decomp\c_out\` | Batch 1 targeted decompilation | `Battle_AttackHitDispatch_vma_0x004c5e0c.c`, `Battle_DamageEngine_vma_0x004c6340.c`, `Battle_Sub5DF080_vma_0x004c8660.c`, `Battle_SpawnOrInitUnit_vma_0x008b6dec.c` |
| `E:\rea\rea_battle_decomp\c_out_batch2\` & `c_out_batch2_annot\` | Batch 2 core combat functions & annotated refs | `BattleFn_0x005c731c.c`, `BattleFn_0x005ce084.c`, `BattleFn_0x005ce63c.c`, `BattleFn_0x005d5498.c`, `BattleFn_0x005d6da0.c`, `BattleFn_0x005d8464.c`, `BattleFn_0x005d9d6c.c`, `BattleFn_0x005da618.c`, `BattleFn_0x005db2c0.c`, `BattleFn_0x004c3f24.c`, `BattleFn_0x0090ebc4.c`, `BattleFn_0x009157fc.c` |
| `E:\rea\rea_battle_decomp\DecompileBattleEngineBatch3.java` | Ghidra Headless script (4 `NoReturn`, 38 boundaries, 30 functions `OK` in `_summary_batch3.txt`) | Marks `NoRet` helpers `0x311610` (`__throw_out_of_range`), `0x370c38`, `0xabf40c` (`_Unwind_Resume`), `0xac3380` (`__stack_chk_fail`) |
| `E:\rea\rea_battle_decomp\c_out_batch3\` & `c_out_batch3_annot\` | Batch 3 helpers & subsystems (`30` `OK` decompilations, `514` unique callees logged by `resolve_refs.py`) | `0x47a29c`, `0x47a3a4`, `0x4bd678`, `0x4bdba0`, `0x4c1e04`, `0x4c2188`, `0x4c32c4`, `0x4c3918`, `0x4c4088`, `0x4c51bc`, `0x529258`, `0x5535d4`, `0x553738`, `0x553884`, `0x5dbc18`, `0x5dd3f0`, `0x5dd600`, `0x5dfef0`, `0x7700d4`, `0x91f9dc`, `0x91fb18`, etc. |
| `E:\rea\rea_battle_decomp\verify_native_formulas.py` | Unicorn ARM64 + Capstone verification harness | Directly executes ELF machine code at `0x47a29c`, `0x47a3a4`, `0x5ce084`, `0x91f9dc`, `0x7700d4`, `0x958df4`, `0x95c8d4`, `0x95ca20`, `0x95cb8c` and verifies `.data` tables |

---

## 2. Verified `.data` & `.rodata` Constants

### `.data` (`PT_LOAD[2]`, ELF `0x00b0xxxx` = Ghidra `0x00c0xxxx`)

| ELF VMA | Size / Type | Verified Value(s) | Meaning |
| :--- | :--- | :--- | :--- |
| `0xb0ad78` | `int32` | `1500` | `surge_width` (total Surge hitbox width = `±750` around `surge_x`) |
| `0xb0ad7c` | `int32` | `15` | `surge_delay` (frames before first Surge tick) |
| `0xb0ad80` | `int32` | `20` | `surge_interval` (frames per active Surge tick / duration unit per level) |
| `0xb0ad84` | `int32` | `10` | `surge_end_extra` (linger frames after active ticks end) |
| `0xb0ad88` | `int32` | `-250` | `surge_offset` (Surge center adjustment vs target size `+0x83940`) |
| `0xb0aed0` | `int32` | `544` | Verified `.data` constant |
| `0xb0aed4` | `int32[24]` | `[0, -125, -125, -75, -75, -25, -25, 0, 0, 25, 25, 75, 75, 125, 125, -50, -50, -25, -25, 25, 25, 50, 50, 0]` | `KB_Y_ARC_state3` (per-frame Y deltas for state `3` damage KB; sum = `0`) |
| `0xb0af34` | `int32[12]` | `[0, 0, -100, -100, -50, -50, 0, 0, 50, 50, 100, 100]` | `KB_Y_ARC_state5` (per-frame Y deltas for state `5` Cannon KB; sum = `0`) |
| `0xb0b310` | `int32` | `160` | `wave_step` (also used in Castle pulse offset scaling) |

### `.rodata` Multi-Hit LD Lookup Tables (used by `0x95ca20`, `0x95cb8c`, `0x95c8d4`)

| ELF VMA | Slot Offsets Indexed by `atk_idx` (`0, 1, 2`) | Role |
| :--- | :--- | :--- |
| `0x1ea8dc` | `[0x83a58, 0x83c34, 0x83c38]` | `is_ld` check field offsets (`0x95c8d4`) |
| `0x1ea8e8` | `[0x83a58, 0x83c24, 0x83c28]` | `ld_start` field offsets (`0x95ca20`) |
| `0x1ea8f4` | `[0x83a5c, 0x83c2c, 0x83c30]` | `ld_width` field offsets (`0x95cb8c`) |

---

## 3. Core Memory Layout (`BattleManager` = `BM`)

### Global `BattleManager` Fields

| Offset from `BM` | Access / Interpretation |
| :--- | :--- |
| `+0x400` / `+0x468` / `+0x4b4` | Audio/SFX manager (`0x999ef0`) & stage/boss flags (`0x8b18c4`) |
| `+0x1478` | Gamedata key-value lookup (`0x8e3f14`: e.g. `"battle_wave_s_st"`, `"battle_death_volcano_time"`, `"battle_super_beast_hunter"`, `"battle_super_sage_hunter_damage1"`, `"battle_super_sage_hunter_knockback"`, `"battle_super_sage_hunter_freeze"`, `"battle_super_sage_hunter_slow"`, `"battle_super_sage_hunter_weaken"`, `"battle_super_sage_hunter_warp"`, `"battle_super_sage_hunter_curse"`, `"battle_super_sage_freeze"`, `"battle_super_sage_slow"`, `"battle_super_sage_weaken"`, `"battle_super_sage_curse"`, `"battle_super_sage_knockback"`) |
| `+0x1538` | Talent store (`0x5535d4`, `0x553738`, `0x553884`) |
| `+0x21b8` | Talent Orb container (`0x62b3b4`, `0x62b6bc` -> `0x529258`) |
| `+0x2648 + team*0x1f0` | Curse / trait-disable check state (`0x5b1be4`) |
| `+0x26b4 + idx*4` | Unit summon/spirit cooldown array (cleared to `0` on unit death when `+0x83c5c >= 0` and no other alive matching unit) |
| `+0x2a10..+0x2a20` | Hit-tracking RB-tree (`std::map<slot, vector<unit_uid>>`) |
| `+0x83688` | Frame counter (used e.g. `% 5` for Castle collapse VFX) |
| `+0x83718 + row*0x2c` | Per-chapter/row Treasure value array (read by `0x91f9dc`) |
| `+0x838f0..+0x83900` | Shield/barrier/hit RB-tree (`param_18` tracking at `+0x83c74`) |
| `+0x9c778` | Visual/explosion VFX ring buffer (`0x10`-byte entries, `5` entries starting `+0x32*0x10` for castle collapse) |
| `+0x9ce78` / `+0x9ce7c` / `+0x9ce80` | Castle pulse array (`team*0xb4 + idx*0xc`) |
| `+0x290568 + row*0x18` | Treasure definition vectors (`std::vector` of `0x30`-byte entries: `+0x24` `id`, `+0x28` `scale`, `+0x2c` `cannon_filter`); NOTE: Ghidra displays `&UNK_00290568 + param_1`, which Capstone confirms is struct offset `BM + 0x290568` |
| `+0x327f0c` | Equipped Cat Cannon type (`0..N`: `<=2 -> ctype*450`, else `1350`) |
| `+0x333dfc..+0x333e28` | Wave pillar fixed array (`200` slots, stride `0x30`) |
| `+0x338900..+0x338910` | Active Surge vector (`std::vector<Surge*>`, `0x48`-byte Surge objects) |
| `+0x338918..+0x338928` | Active Spirit/Conjure vector |
| `+0x338930..+0x338940` | Active Explosion vector (`0x40`-byte Explosion objects) |
| `+0x38816c..+0x388198` | Pre-rolled hit proc booleans (`12` `int32` flags populated by `BattleFn_0x005da618`) |
| `+0x4407e8` | Cat Combo manager (`0x7700d4`; combo list vector at `+0x00..+0x08`, table dir at `+0x1b8` = `+0x37*8`) |

### Per-Unit Slot Fields (`base = BM + team * 51000 + slot * 1000`, `51` slots per team starting at `+0x83908`)

> Team `0` = Cat (walks left toward `X = 0`), Team `1` = Enemy (walks right toward Cat Base). Slot `0` in each team includes Base/Castle state fields.

| Offset | Type | Verified Usage |
| :--- | :--- | :--- |
| `+0x83908` | `int32` | Active flag / Unit UID (`0` = inactive/freed on death completion) |
| `+0x8390c` | `int32` | Unit state (`0`=Walk, `1`=Idle, `2`=Attack, `3`=Damage KB, `4`=Death, `5`=Cannon KB, `6`=Proc KB, `7`=Freeze-break/heavy KB, `0xb/0xc/0xd`=Burrow, `0xe/0xf/0x10`=Revive, `0x12/0x13/0x14`=Warp, `0x15`=Death Surge); `0x958df4` targetable iff state in `{0, 1, 2, 0xb, 0xd, 0x10}` |
| `+0x83910` | `int32` | Current state frame counter |
| `+0x83914` | `int32` | World X position |
| `+0x83918` / `+0x8391c` | `int32` | Y / offset fields (`+0x8391c` used in VFX Y = `val * 4 + 0x1cc`; `+0x83918` used in Castle collapse VFX) |
| `+0x83920` | `int32` | Castle pulse threshold (`<= frame >> 2`) |
| `+0x83924` / `+0x83928` | `int32` | Max HP (`+0x83924`) / Current HP (`+0x83928`) |
| `+0x8392c` / `+0x83930` | `int32` | Castle attack state / Castle attack frame |
| `+0x83934` / `+0x83938` | `int32` | Team-0 field `+0x83934` (`0x9579e0`) & slot field `+0x83938`: on Cat (`team = 0`) death when `+0x83cbc > 0 && +0x83938 > 0`, reduces `+0x83938` by `(+0x83cbc * (+0x83934)) / 1000` (clamped `>= 1`) |
| `+0x8393c` | `int32` | Standing attack range |
| `+0x83940` / `+0x83944` | `int32` | Hitbox front offset / Hitbox back offset (`CheckRange` enemy bounds `[e_pos - front .. e_pos - back]`) |
| `+0x83948` / `+0x8394c` | `uint32` | Primary traits / trait flags (checked by `0x95ac18` and `0x95b334/a4`) |
| `+0x83954` | `int32` | HP write/sync field in `0x960488` |
| `+0x839a0` / `+0x83ba0` | `int32` | Crit hit trigger flag (`+0x839a0`), Savage Blow trigger flag (`+0x83ba0`) |
| `+0x839a4` / `+0x839a8` / `+0x83be0` | `int32` | Wave proc `%`, Wave level, Mini-Wave flag (`== 1`) |
| `+0x839ac..+0x839c4` | `int32` | Target trait & ability flags (`+0x839b4` Metal, `+0x839c4` bit checked with `+0x83ab8` -> target `+0x83ab4 = 1`, `+0x839c8` Strong Against, `+0x839e4` Massive Damage) |
| `+0x839cc` / `+0x839d0` / `+0x839d8` | `int32` | Freeze `%`, Slow `%`, Crit `%` |
| `+0x839d4` / `+0x839dc` | `int32` | Freeze duration, Slow duration |
| `+0x839e8` | `int32` | Knockback `%` |
| `+0x839f0` | `int32` | Flag written to target `+0x9013c = 1` when attacker `+0x839f0` bit 0 set (`+0x69c` from enemy slot 0) |
| `+0x839f4` | `int32` | Base Destroyer (`4x` damage vs castle / slot 0) |
| `+0x839f8` | `int32` | Knockback active/blocked flag written by `0x5d6da0` (`0x9607d0`) |
| `+0x839fc` / `+0x83a10` | `int32` | Freeze timer / Freeze max timer |
| `+0x83a00` / `+0x83a14` | `int32` | Slow timer / Slow max timer |
| `+0x83a18` / `+0x83a1c` / `+0x83a20` | `int32` | Weaken `%`, Weaken duration, Weaken damage `%` multiplier (written to `+0x83a44`) |
| `+0x83a24` / `+0x83a28` | `int32` | Strengthen HP `%` threshold (`+0x83a24`; bit 1 also gates talent `0x12`), Strengthen `+ATK%` (`+0x83a28`) |
| `+0x83a34` / `+0x83a38` / `+0x83a44` | `int32` | Weaken remaining timer, max timer, `%` ATK multiplier |
| `+0x83a58` / `+0x83a5c` | `int32` | Hit 0 LD/Omni start (`+0x83a58`, also `!= 0` = is_ld), width (`+0x83a5c`) |
| `+0x83c24`..`+0x83c38` | `int32` | Multi-hit 1 & 2 LD start (`+0x83c24/28`), width (`+0x83c2c/30`), enable (`+0x83c34/38`) |
| `+0x83a60` / `+0x83bd4` / `+0x83c94` | `int32` | Barrier / Shield checks for `param_2 == 1 / 2 / 3` |
| `+0x83a68` / `+0x83a6c` / `+0x83a70` / `+0x83a74` | `int32` | Immunities: KB (`+0x83a68`), Freeze (`+0x83a6c`), Slow (`+0x83a70`), Weaken (`+0x83a74`) |
| `+0x83a90` / `+0x83aa4` | `int32` | Survive lethal strike / Zombie Revive fields (`8b6dec`, `5dd600`) |
| `+0x83a9c` / `+0x83aa0` | `int32` | Cleared by `0x960f1c` when status blocked by immunity (`0x5d6da0`) |
| `+0x83ab4` / `+0x83ab8` | `int32` | Target `+0x83ab4 = 1` if attacker `+0x83ab8` & target `+0x839c4` |
| `+0x83abc` / `+0x83ac0` | `int32` | Witch trait (`+0x83abc`) & Witch Killer (`+0x83ac0`, `5x`) |
| `+0x83b04` / `+0x83b0c` | `int32` | Death animation / Death sound flag (`bit 0` -> sound `8`) |
| `+0x83b18` / `+0x83b24` | `int32` | Barrier Breaker `%`, Warp `%` |
| `+0x83b28` / `+0x83b2c` / `+0x83b30` / `+0x83b34` / `+0x83b38` | `int32` | Warp duration, min dist, max dist, active timer (`+0x83b34`), rolled delta (`+0x83b38`) |
| `+0x83b44` / `+0x83b48` / `+0x83b4c` | `int32` | Warp immunity (`+0x83b44`), Eva Angel trait (`+0x83b48`), Eva Angel Killer (`+0x83b4c`, `5x`) |
| `+0x83b54` / `+0x83b58` / `+0x83b5c` / `+0x83b60` / `+0x83b64` | `int32` | Curse `%`, Curse duration, Curse immunity (`+0x83b5c`), Curse timer (`+0x83b60`), Curse max (`+0x83b64`) |
| `+0x83b6c` / `+0x83b70` / `+0x83b74` / `+0x83b78` / `+0x83b80` / `+0x83b84` | `int32` | Resistances (`%`): Weaken (`+0x83b6c`), Freeze (`+0x83b70`), Slow (`+0x83b74`), KB (`+0x83b78`), Warp (`+0x83b80`), Curse (`+0x83b84`) |
| `+0x83b8c` | `int32` | Insane Damage (`5x..6x`) |
| `+0x83b94` / `+0x83b98` | `int32` | Savage Blow `%`, Savage Blow `+ATK%` |
| `+0x83b9c` / `+0x83ba4` / `+0x83ba8` / `+0x83bac` | `int32` | Dodge `%`, active timer, duration, trigger flag |
| `+0x83bb4` | `int32` | Toxic `%` |
| `+0x83bc0` / `+0x83bc4` / `+0x83bc8` / `+0x83bcc` / `+0x83c54` | `int32` | Surge `%`, start, width, level (`+0x83bcc`), Mini-Surge (`+0x83c54 != 0`) |
| `+0x83be4` / `+0x83c74` | `int32` | Shield Piercing `%`, Aku Shield (`+0x83c74`) |
| `+0x83bf0` / `+0x83bf4` / `+0x83bf8` / `+0x83bfc` / `+0x83c70` / `+0x83cac` | `int32` | Death Surge `%`, start, width, level, damage (`+0x83c70`), Mini/flag (`+0x83cac`) |
| `+0x83c18` / `+0x83c1c` / `+0x83c9c` | `int32` | Colossus trait (`+0x83c18`), Colossus Slayer (`+0x83c1c`), Colossus Slayer damage `%` (`+0x83c9c`) |
| `+0x83c40` / `+0x83c44` | `int32` | Behemoth trait (`+0x83c40`), Behemoth Slayer (`+0x83c44`) |
| `+0x83c5c` | `int32` | Unit slot-link index (>=0 clears `BM + 0x26b4 + idx*4 = 0` on death) |
| `+0x83c64` / `+0x83c68` | `int32` | Sage Slayer (`+0x83c64`), Sage trait (`+0x83c68`) |
| `+0x83c6c` / `+0x83c88` / `+0x83c8c` / `+0x83c90` | `int32` | KB resist applied (`+0x83c6c`), Explosion `%`, start, width |
| `+0x83ca8` / `+0x83cbc` / `+0x83cc8` / `+0x83cd8` | `int32` | SFX slot (`+0x83ca8`), `+0x83cbc` (`0x962da4` scaled reduction on `+0x83938` at Cat death), Unit type/ID (`+0x83cc8`), Enemy trait flag (`+0x83cd8`) |
| `+0x83ce0` / `+0x83ce4` / `+0x83ce8` / `+0x83cec` | `int32` | Attacker state/proc return (`+0x83ce0`), Cannon/KB param (`+0x83ce4`/`+0x83ce8`), Cannon/KB immunity (`+0x83cec`) |
| `+0x9013c` / `+0x901b0` / `+0x901c0` | `int32` | Target feedback fields (`0x901c0` = `0` normal, `1` LD, `2` state `0xe`) |

---

## 4. Exact Verified Formulas & State Machines

### 4.1 Cat Cannon Charge (`0x47a29c`, `0x47a3a4`)
Called with no `this` (fetches `BM = 0x6fd748()`):
- `ctype = *(int32*)(BM + 0x327f0c)`
- `c_bonus = (ctype <= 2) ? (ctype * 450) : 1350`
- `lv_range = GetCannonUpg(1)` (`0x47a024(1)`), `lv_charge = GetCannonUpg(3)` (`0x47a024(3)`)
- `tr_range = 0x91f9dc(BM + 0x290568, 0x11)`, `tr_charge = 0x91f9dc(BM + 0x290568, 0x01)`
- `combo_7 = 0x7700d4(BM + 0x4407e8, 7, -1)`
```c
int32_t CannonMaxCharge() {
    int32_t raw = 1500 + c_bonus + max(0, 50 * lv_range - tr_range) - 50 * lv_charge - tr_charge;
    int32_t scaled = (raw * (100 - combo_7)) / 100;
    return max(950, scaled);
}
int32_t CannonInitCharge(int32_t max_charge) {
    int32_t combo_3 = CatComboSum(BM + 0x4407e8, 3, -1); // 0x7700d4(..., 3, -1)
    return max(0, ((100 - combo_3) * max_charge) / 100);
}
```

### 4.2 Targetability & Range Check (`0x958df4`, `0x5ce084`, `0x95c8d4`, `0x95ca20`, `0x95cb8c`)
- **Targetable (`0x958df4(team, slot)`)**: active `!= 0` AND `state (+0x8390c) in {0, 1, 2, 0xb, 0xd, 0x10}`.
- **Attacking Cat (`team = 0`) vs Enemy (`team = 1`)**:
  - Target interval: `[t_min, t_max] = [e_pos - (+0x83940), e_pos - (+0x83944)]`.
  - If `atk_state == 0` OR `!is_ld` (`0x95c8d4`): attacker interval is `[cat_pos - standing_range (+0x8393c), cat_pos]`.
  - If `is_ld` (`!= 0`): multi-hit index `atk_idx in {0, 1, 2}` selects `(ld_start, ld_width)` via `.rodata` tables `0x1ea8e8` / `0x1ea8f4` (`[cat_pos - ld_start - ld_width .. cat_pos - ld_start]` or inverted sign for negative width/Omni). Overlap succeeds iff `atk_min <= t_max && atk_max >= t_min`.

### 4.3 Cat Attack Dispatch & Proc Roll Table (`0x5d9d6c`, `0x5da618`)
1. `BattleFn_0x005da618` zeros `BM + 0x38816c..0x388198` (`12` ints) and rolls `rand(100) < pct` for each proc (`KB 0x839e8`, `Freeze 0x839cc`, `Slow 0x839d0`, `Crit 0x839d8`, `Weaken 0x83a18`, `Savage 0x83b94`, `Warp 0x83b24`, `BarrierBreak 0x83b18`, `Curse 0x83b54`, `Toxic 0x83bb4`, `ShieldPierce 0x83be4`, plus trailing `rand(100)` roll).
2. Loops target slots in `[param_3[0] .. param_3[1])`, calling `BattleFn_0x005d5498(BM, 0, attacker_slot, enemy_slot, atk_idx, wave_type=0, kb_bool, savage_bool, ...)`.
3. **Wave roll (`+0x839a4` %)**: scans `200` slots at `BM + 0x333dfc` (stride `0x30`) for an empty slot, sets `type = 1`, `team = 0`, `mini = (+0x83be0 == 1)`, `pos = +0x83914`, `lv = +0x839a8`, `atk_idx`, `dmg = +0x83c70`, and copies the 12 rolled proc booleans.
4. **Surge roll (`+0x83bc0` %)**: allocates `0x48` bytes pushed to `BM + 0x338900`, `type = 0`, `pos = (+0x83914 - (+0x83bc4)) +/- rand(+0x83bc8)`, `lv = +0x83bcc`, `dmg = +0x83c70`, `mini = (+0x83c54 != 0)`, copies the 12 proc booleans.
5. **Explosion roll (`+0x83c88` %)**: allocates `0x40` bytes pushed to `BM + 0x338930`, `pos = (+0x83914 - (+0x83c8c)) +/- rand(+0x83c90)`, copies proc booleans.

### 4.4 Cat -> Enemy Damage Calculation (`0x5d5498` & `0x5d6b98`)
1. **Base / Wave Scaling**:
   - Normal (`param_6 == 0`): `dmg = (raw_atk * param_19) / 100`
   - Mini-Wave/Sub-wave (`param_6 == 2`): `dmg = (raw_atk * param_19) / 500` (`20%`)
   - Surge (`param_6 == 1`): `dmg = (((raw_atk * param_19) / 100) * gamedata("battle_wave_s_st")) / 100`
2. **Critical Hit (`param_7 & 1`)**: sets target `+0x839a0 = 1`, `dmg *= 2` (`<< 1`).
3. **Strengthen**: if `cur_hp <= (+0x83a24 * max_hp) / 100 && (+0x83a24 * max_hp) > 99`, `dmg = (dmg * (+0x83a28 + combo_0x15 + 100)) / 100`.
4. **Talent `0x12`**: if `+0x83a24` bit 1 set, `dmg = (dmg * (talent_0x12 + 100)) / 100`.
5. **Attacker Weakened**: if `+0x83a34 > 0 && +0x83a38 > 0`, `dmg = (dmg * (+0x83a44)) / 100`.
6. **Savage Blow (`param_8 & 1`)**: sets target `+0x83ba0 = 1`, `dmg = (dmg * (+0x83b98 + 100)) / 100`.
7. **Target Trait Multipliers (non-Castle / non-slot-0)** using `0x5d6b98` highest matching treasure ID (`{0x19, 0xc, 0xe, 0xd, 0xf, 0x13, 0x14, 0x15}`):
   - **Strong Against (`+0x839c8`)**: `(((dmg * (tr_val + orb_2 + 1500)) / 1000) * (combo_0xe + 100)) / 100`
   - **Massive Damage (`+0x839e4`)**: `(((dmg * (tr_val + orb_3 + 900)) / 300) * (combo_0xf + 100)) / 100`
   - **Insane Damage (`+0x83b8c`)**: `(dmg * (tr_val + 1500)) / 300`
   - **Witch Killer (`+0x83ac0` vs `+0x83abc`)**: `(dmg * (combo_0x16 + 100) * 5) / 100`
   - **Eva Angel Killer (`+0x83b4c` vs `+0x83b48`)**: `(dmg * (combo_0x17 + 100) * 5) / 100`
   - **Colossus Slayer (`+0x83c1c` vs `+0x83c18`)**: `(dmg * (+0x83c9c)) / 100`
   - **Behemoth Slayer (`+0x83c44` vs `+0x83c40`)**: `(dmg * gamedata("battle_super_beast_hunter")) / 1000` (and Dodge check at `+0x83ba4` / `+0x83b9c`)
   - **Sage Slayer (`+0x83c68` vs `+0x83c64`)**: `(dmg * gamedata("battle_super_sage_hunter_damage1")) / 1000`
   - **Combo `0x19` (vs `+0x83cd8`)**: `(dmg * combo_0x19) / 1000`
8. **Base / Castle & Post-Multipliers**:
   - **Base Destroyer (`+0x839f4`)**: `dmg *= 4` (if Castle or matching slot).
   - **Talent Orb `0` (`0x553884`)**: `dmg += (orb_val * dmg_or_stat) / 100`.
   - **Metal (`+0x839b4`)**: if non-crit and `dmg > 0`, clamps `dmg = 1`.
   - **Barrier / Shield**: checked by `param_2` (`1 -> +0x83a60`, `2 -> +0x83bd4`, `3 -> +0x83c94`); if intact, zeroes damage and writes `+0x901b0 = 0x100000000` (`Barrier`/`Shield` block). If not blocked, runs `BattleFn_0x005d6da0` for status procs.

### 4.5 Status Procs & Resistance (`0x5d6da0`)
- Applies Freeze (`+0x839fc/+0x83a10`, combo `0x13`, orb `0xca`), Slow (`+0x83a00/+0x83a14`, combo `0x12`, orb `0xc8`), Weaken (`+0x83a34/+0x83a38` + power `+0x83a44 = +0x83a20`, combo `0x14`, orb `0xcc`), Warp (`+0x83b34/+0x83b38`), Curse (`+0x83b60/+0x83b64`, orb `0xce`), and Knockback (`+0x83ce8 = +0x83ce4`), after Treasure scaling `(dur * (tr_val + 1500)) / 1500`.
- Each effect is blocked by its immunity flag (`0x83a68/6c/70/74`, `0x83b44/5c`, `0x83cec`), scaled by `(100 - resist) / 100` (`0x83b70/74/6c/80/84`, `0x83c6c` KB), and adjusted by Sage penalty (`battle_super_sage_*`) or Sage Slayer reduction (`battle_super_sage_hunter_*`, `(100 - gamedata_pct) / 100`) depending on target/attacker Sage status. Attacker Curse (`0x5b1be4`) disables Treasure/Combo/Slayer duration bonuses.

### 4.6 Knockback Trajectories & Death Surge (`0x5dbc18`, `0x5dd3f0`, `0x5dd600`, `0x8b95b4`)
- **State `3` (Damage KB)**: `24`-frame animation (`0x8b95b4`: `(frame + 1) % 24`), X step `±60`, Y offset = `KB_Y_ARC_state3[frame]` (`0xb0aed4`, net `0`).
- **State `5` (Cat Cannon KB)**: `12`-frame duration, X step `±20`, Y offset = `KB_Y_ARC_state5[frame]` (`0xb0af34`, net `0`).
- **State `6` (Proc KB)**: `12`-frame duration, no Y bounce (`0` net Y):
  ```c
  // For each frame f (1..12), verified at 0x5dd600 (ELF 0x5de874..0x5de920):
  int32_t base = ((12 - f) % 12) * 10; // Sum = 660 px across 12 frames
  int32_t after_tr = (base * tr_kb) / 1000 + base;
  int32_t after_cb = (after_tr * (combo_0x11 + 100)) / 100;
  int32_t dx = ((100 - resist) * after_cb) / 100; // Also uses +0x83c6c / +0x83b78
  ```
- **State `7`**: X step `±60`, Y offset = `KB_Y_ARC_state3[frame >> 1]`.
- **Death (`state 4`) & Death Surge (`state 0x15`)**:
  - `state 4` plays soul effect (`0x6ee0f4`) + sound `8` (if `+0x83b0c & 1`), waits `max` frames, clears `+0x83c5c` slot cooldown `BM + 0x26b4 + idx*4 = 0`, adjusts `+0x83938` (`+0x83938 -= (+0x83cbc * +0x83934) / 1000`, clamped `>= 1`) when `team == 0 && +0x83cbc > 0 && +0x83938 > 0`, and zeroes `+0x83908` / `+0x83978` / `+0x83974`.
  - `state 0x15` waits `battle_death_volcano_time` frames (clamped by team `+0x27f8`), then spawns a Death Surge (`type = 2`) into `BM + 0x338900` at `(pos - (+0x83bf4)) +/- rand(+0x83bf8)`, duration level `+0x83bfc`, damage `+0x83c70`, `mini = (+0x83cac != 0)`.

### 4.7 Surge Hit Timing (`0x4c32c4`, `0x5db6ac`)
- Spawns with `delay = 15` (`0xb0ad7c`) frames before first tick.
- Active window ticks every `20` (`0xb0ad80`) frames for `lv * 20` active frames + `10` (`0xb0ad84`) linger frames.
- Hit X window: `[surge_x - 750, surge_x + 750)` (`surge_width = 1500` at `0xb0ad78`), target center adjusted by `surge_offset = -250` (`0xb0ad88`) + target size `+0x83940`. Dispatches to `0x5d8464` (Enemy surge) or `0x5d5498` (Cat surge).

### 4.8 Core Per-Frame Loop, Single-Target Tie-Breaker & Stage Spawner (`0x5cbf84`, `0x5c731c`, `0x5dbc18`, `0x5dfef0`, `0x4bf8e8`)
- **Per-Frame Update Order (`0x5cbf84`)**: runs inside speedup loop (`boost_speed` ticks) -> `0x5dfef0` (Enemy Wave Spawner) -> `0x4bd678` (Unit Status/Timer Tick across both teams `0..1`, slots `0..50`) -> `0x5dbc18(BM, GD, 0)` (Team 0 unit AI/movement/attack) -> `0x4bdba0` (Sniper the Cat item turret/projectile when `0x5af784(5)` active) -> `0x5dd600(BM, GD, 1)` (Team 1 unit/enemy AI/movement/attack).
- **Single-Target Attack Tie-Breaking (`0x5cbf84`)**: When a unit has Single Target (not Area Attack), it collects all targetable opposing slots (`0..50`) overlapping `CheckRange`, finds the minimum horizontal distance (`min_dist`), collects all slots tied at `*piVar50 == min_dist`, and selects one uniformly at random via `rand(tied_count)` (`0x43ea60`).
- **Stage Enemy Spawner (`0x5dfef0`)**:
  - Skipped if battle ended (`0x5ab154() != 0`) or Team 1 wallet flag bit `0` set (`0x4b1be4(BM + 0x2838) & 1 != 0`).
  - Decrements global spawn cooldown timer `*(i32*)(BM + 0x838d0)`.
  - For each wave entry (`0x38`-byte descriptor at `BM + 0x9e560`, runtime state `0xc`-byte entry at `BM + 0x838d8`: `[+0: remaining/countdown, +4: spawned_count, +8: condition_timer]`): checks enemy Castle HP % trigger (`enemy_castle_hp <= (trigger_pct * max_hp) / 100`) or Boss-HP trigger, updates spawn countdowns, and if live active enemies (`slot 1..50` with `+0x90428 != 0`) `< *(i32*)(BM + 0x9e54c)` (max enemies), spawns via `0x8b6dec` (`func_0x009b6dec`) and sets random respawn delay `*(BM + 0x9e540) + rand(diff + 1)` into `BM + 0x838d0`.
- **Screen Shake (`0x4bf8e8`)**: applies decaying horizontal/vertical offsets starting at `±80 / ±40 / ±20`.

### 4.9 Enemy -> Cat Defense (`0x5d8464`) & Wave Blocker (`0x5db2c0`, `0x5db4b4`)
- `0x5db2c0` advances wave slots (`200` slots, stride `0x30` at `BM + 0x333dfc`), dispatching Team 0 waves to `0x5d5498` and Team 1 waves via `0x5db4b4` -> `0x5d8464`.
- **Wave Blocker (`+0x83a64` via `0x95f994`)**: in `0x5db4b4` (when Cat has Wave Blocker) and in `0x4c6340` (vs Cat Cannon Wave/Subtypes), zeroes out the wave slot (`+0x333dfc`), clears wave procs, and writes `+0x83a80 = 0x100000000` (blocked indicator).

### 4.10 Unit Spawn, HP & Stat Table Lookup (`0x8b6dec`, `0x9632d8`, `0x9645a8`, `0x964cb4`)
- **Spawn (`0x8b6dec`)**: allocates first free slot in `1..50` (`0x32`), initializes stats, multi-hit frame triggers (`0..2`), abilities, talent orbs, and resistances.
- **Stat Table Lookup (`0x964cb4(team, id, form, idx)`)**:
  - Cat (`team 0`, `(0x4b1be4(BM + team*0x1f0 + 0x2648) & 1) != 0`): reads `BM + (unitId + 2) * 0x760 + form * 0x1d8 + UNK_002ea9e4[idx] * 4 + 0x9e578` where `UNK_002ea9e4` (`0x1ea9e4`) = `[13, 61, 62, 12]`.
  - Enemy (`bit 0 == 0`): reads `BM + (enemyId + 2) * 0x1c4 + UNK_002ea9f0[idx] * 4 + 0x233118` where `UNK_002ea9f0` (`0x1ea9f0`) = `[12, 57, 58, 63]`. (`UNK_002ea9cc` = `[3, 59, 60, 3, 55, 56]`, `UNK_002ea9d8` = `[3, 55, 56, 13, 61, 62]`).
- **Unit HP (`0x9632d8`) & ATK (`0x9645a8`)**:
  - **Cat HP (`0x9632d8`)**: iterates `i = 1..level-1`, summing `base * growth_bracket[i / 10]` (`BM + unitId*0x50 + (i/10)*4 + 0x447634`) onto `base * 100`, then `lv_stat = (sum + 50) / 100`. Applies Treasure bonus (`0x91f9dc`, Defense category `9`), Cat Combo (`0x7700d4`, Defense `1`), Talent `0x20` bonus (`0x963984`), and True/Ultra Form (`form > 1`) Catfruit/Orb bonus (`0x5535d4`).
  - **Cat ATK (`0x9645a8`)**: same level-growth sum using `UNK_002ea9cc[hitIdx] * 4 + 0x9e578` (`hitIdx in {0,1,2}`), then Treasure category `10`, Cat Combo `0`, Talent `0x1f` (`31`), and `form > 1` bonus (`0x5535d4(..., 1, 0)`).
  - **Enemy HP (`0x9632d8`) & ATK (`0x9645a8`)**: when difficulty `*(i32*)(BM + 0x327f0c) < 3` and flag `*(u8*)(BM + 0x32c658) == 0`, computes `((DAT_00c0b464[diff] + 10) * base + 5) / 10`, where `DAT_00c0b464` (`.data` `0xb0b464`) = `[0, 5, 30, 5, 0, 0, 0, 0]`. Otherwise reads crown multiplier via `0x8cbcf8(stage_entry)`.

### 4.11 Economy, Worker Cat, Cooldowns & XOR Anti-Cheat Memory (`0x4b1bf4..0x4b26a4`)
- **XOR Byte-Swapped Storage (`0x4b1bf4` Money at `+0x4..0xb`, `0x4b1f30` Worker Level at `+0xc..0x13`, `0x4b21ec`/`0x4b2234` Slot Cooldown at `+0x14 + slot*4` with key at `+0x3c..0x3f`)**:
  ```c
  // Decoder verified at 0x4b1bf4 (Money), 0x4b1f30 (Worker Lv), 0x4b21ec (Slot Cooldown):
  uint32_t decode_xor(const uint8_t *enc, const uint8_t *key) {
      return ((uint32_t)(enc[1] ^ key[2]) << 16) | ((uint32_t)(enc[0] ^ key[3]) << 24) |
             ((uint32_t)(enc[2] ^ key[1]) << 8)  |  (uint32_t)(enc[3] ^ key[0]);
  }
  ```
- **Worker Cat Upgrade Cost (`0x4b1f74`)**: takes `up4 = UpgradeLevel(4)` (`0x47a024(4)`). If `up4 < 7`, `base = 4000, step = 1000`; else `base = -2000, step = 2000` (in centi-yen `x100`). Cost = `(base + up4 * step) + worker_lv * (base + up4 * step)` (`worker_lv` is `0`-indexed).
- **Worker Income per Frame (`0x4b2028`)**: `((((worker_lv + 10) * (up4 * 10 + 25)) / 10 + treasure_3) * (combo_8 + 100)) / 100`. Added to wallet via `0x4b1e64`, clamped to `[0, MaxWallet]`.
- **Max Wallet (`0x4b1cc8`)**: `raw = ((worker_lv * 5 + 10) * (UpgradeLevel(5) * 10000 + 10000)) / 10`; `max(0, ((raw + treasure_4) * (combo_9 + 100)) / 100)` (unless overridden by stage drop/limit rule at `0x533678`).

### 4.12 Cat Cannon Firing, 8 Ototo Subtypes & Sniper the Cat (`0x4bbf4c..0x4bdba0`, `0x4c5e0c`, `0x4c6340`, `0x4c8660`)
- **Firing Trigger (`0x4c8660`)**: requires cannon ready (`0x957a4c(0) == 0 && 0x9578c8(0) == 0`), sets fired flag `BM + 0x2818 = 1` and active beam state (`0x9578fc(0, state)`):
  - Style `0` (Normal Beam) -> state `1`, SE `25` (`0x19`)
  - Style `1` (Slow Beam) -> state `3`, SE `60` (`0x3c`)
  - Style `2` (Iron Wall) -> spawns barrier Cat unit (`0x9b6dec`) ahead of furthest enemy (min `3200`), state `6`, SE `61` (`0x3d`)
  - Style `3` (Thunderbolt) -> targets frontmost non-base Cat (`pos - range/2`), state `4`, SE `37` (`0x25`)
  - Style `4` (Waterblast) -> targets frontmost non-base Cat (`pos - range/2`), state `7`, SE `65` (`0x41`)
  - Style `5` (Holy Blast) -> state `9`, SE `84` (`0x54`)
  - Style `6` (Breakerblast) -> finds frontmost enemy (`min 3200`), state `11` (`0xb`), SE `19` (`0x13`)
  - Style `7` (Curseblast) -> state `12` (`0xc`), SE `124` (`0x7c`)
- **Beam/Effect Tick (`0x4c5e0c` -> `0x4c6340`)**: sweeps across active opposing units (`slot 1..50`) matching beam window (`DAT_00c0b310 = [160, -960, -960, -448]` for traveling beam states `3` & `12`), applying Dodge, Wave Blocker (`0x95f994`), or status procs (`0x5d6da0`) & Holy Blast zombie burrow unburrow (`state 0xc`).
- **Sniper the Cat (`0x4bdba0`)**: active when `0x5af784(5) & 1 != 0`; tracks highest-X targetable enemy (`slot 1..50`), slews barrel angle at `1.0°/frame`, and fires every `300` frames.

---

## 5. Unicorn ARM64 & Capstone Direct Verification

Executed via `& "E:\rea\venv\Scripts\python.exe" E:\rea\rea_battle_decomp\verify_native_formulas.py`:

| Check | Native Addresses / Sections Executed | Result |
| :--- | :--- | :--- |
| `[1] KB_Y_ARC tables` | `.data` `0xb0aed4` (`24` ints) & `0xb0af34` (`12` ints) | Exact match; both net Y sums = `0` |
| `[2] CannonMaxCharge & InitCharge` | `0x47a29c`, `0x47a3a4`, `0x91f9dc`, `0x7700d4` (`7` test cases incl. `950` clamp) | Bit-for-bit match in Unicorn ARM64 |
| `[3] CheckRange (normal & LD)` | `0x5ce084`, `0x958df4`, `0x95c8d4`, `0x95ca20`, `0x95cb8c` | Exact `in=1, out=0, enemy_out=0`, `ld_hit=1, ld_blind=0` |
| `[4] State 6 Proc KB` | `0x5dd600` (`0x5de874..0x5de920`) | `12`-frame total DX = `660` (`base`), `858` (`+300` Treasure) |
| `[5] XOR Getters/Setters & Economy` | `0x4b1bf4`, `0x4b1f30`, `0x4b21ec`, `0x4b2234`, `0x4b1f74`, `0x4b2028`, `0x4b1cc8` | Roundtrip XOR + `4` worker economy cases matched bit-for-bit |
| `[6] Unit/Enemy HP & Stat Lookup` | `0x9632d8`, `0x964cb4`, `.data` `0xb0b464` (`DAT_00c0b464`), `.rodata` `0x1ea9f0` | Cat HP (`30348`), Enemy HP (`3750`), & `0x964cb4` (`777`) exact in Unicorn |
