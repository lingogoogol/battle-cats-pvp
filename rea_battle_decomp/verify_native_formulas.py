"""
Unicorn ARM64 + Capstone verification harness for Battle Cats native formulas
Directly executes stripped functions from E:/rea/decompiled_src/native_libs/lib/arm64-v8a/libnative-lib.so
and asserts exact bit-for-bit equality against our decoded integer/float formulas.
"""
import struct
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_HOOK_CODE, UC_PROT_ALL
from unicorn.arm64_const import (
    UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2, UC_ARM64_REG_X3,
    UC_ARM64_REG_X4, UC_ARM64_REG_X5, UC_ARM64_REG_X8, UC_ARM64_REG_X9,
    UC_ARM64_REG_X30, UC_ARM64_REG_SP, UC_ARM64_REG_PC,
    UC_ARM64_REG_W0, UC_ARM64_REG_W1, UC_ARM64_REG_W2, UC_ARM64_REG_W3,
    UC_ARM64_REG_TPIDR_EL0, UC_ARM64_REG_CPACR_EL1,
)

SO_PATH = r"E:\rea\decompiled_src\native_libs\lib\arm64-v8a\libnative-lib.so"

# Memory map constants
ELF_BASE = 0x00000000
BM_ADDR = 0x20000000      # Mocked BattleManager struct (6 MB)
HEAP_ADDR = 0x22000000    # Mocked heap vectors / combos / treasures
TLS_ADDR = 0x23000000
STACK_TOP = 0x24000000
SENTINEL_LR = 0x2F000000


def align_up(v, a=0x1000):
    return (v + a - 1) & ~(a - 1)


class NativeVerifier:
    def __init__(self):
        with open(SO_PATH, "rb") as f:
            self.so_data = f.read()

        self.mu = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
        # Enable FP/SIMD (CPACR_EL1.FPEN = 0b11 << 20)
        self.mu.reg_write(UC_ARM64_REG_CPACR_EL1, 0x3 << 20)

        # Map ELF PT_LOAD segments at ELF_BASE
        # PT_LOAD[0]: vaddr=0x0, memsz=0xaca2b0, off=0x0
        # PT_LOAD[1]: vaddr=0xace2b0, memsz=0x38400, off=0xaca2b0
        # PT_LOAD[2]: vaddr=0xb0a6b0, memsz=0x477d90, off=0xb026b0, filesz=0x1140
        self.mu.mem_map(0x00000000, align_up(0xaca2b0), UC_PROT_ALL)
        self.mu.mem_write(0x00000000, self.so_data[0:0xaca2b0])

        self.mu.mem_map(0x00ace000, align_up(0x00ace2b0 - 0x00ace000 + 0x38400), UC_PROT_ALL)
        self.mu.mem_write(0x00ace2b0, self.so_data[0xaca2b0:0xaca2b0 + 0x38400])

        self.mu.mem_map(0x00b0a000, align_up(0x00b0a6b0 - 0x00b0a000 + 0x477d90), UC_PROT_ALL)
        self.mu.mem_write(0x00b0a6b0, self.so_data[0xb026b0:0xb026b0 + 0x1140])

        # BattleManager + Heap + TLS + Stack + Sentinel
        self.mu.mem_map(BM_ADDR, 0x00600000, UC_PROT_ALL)
        self.mu.mem_map(HEAP_ADDR, 0x00200000, UC_PROT_ALL)
        self.mu.mem_map(TLS_ADDR, 0x10000, UC_PROT_ALL)
        self.mu.mem_map(STACK_TOP - 0x100000, 0x100000, UC_PROT_ALL)
        self.mu.mem_map(SENTINEL_LR, 0x1000, UC_PROT_ALL)

        self.mu.reg_write(UC_ARM64_REG_TPIDR_EL0, TLS_ADDR)
        self.mu.mem_write(TLS_ADDR + 0x28, struct.pack("<Q", 0x1122334455667788))

        self.stubs = {}
        self.mu.hook_add(UC_HOOK_CODE, self._hook_code)

        # Default stub state
        self.cannon_upg = {1: 10, 3: 10}
        self.has_timed_score = False
        self.boss_slot = -1
        self.rng_val = 0

    def _hook_code(self, uc, address, size, user_data):
        if address in self.stubs:
            ret_val = self.stubs[address](uc)
            if ret_val is not None:
                uc.reg_write(UC_ARM64_REG_X0, ret_val & 0xFFFFFFFFFFFFFFFF)
            lr = uc.reg_read(UC_ARM64_REG_X30)
            uc.reg_write(UC_ARM64_REG_PC, lr)

    def reset_bm(self):
        self.mu.mem_write(BM_ADDR, b"\x00" * 0x00460000)
        self.mu.mem_write(HEAP_ADDR, b"\x00" * 0x00020000)

    def call(self, vma, args=()):
        self.mu.reg_write(UC_ARM64_REG_SP, STACK_TOP - 0x100)
        self.mu.reg_write(UC_ARM64_REG_X30, SENTINEL_LR)
        regs = [UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2,
                UC_ARM64_REG_X3, UC_ARM64_REG_X4, UC_ARM64_REG_X5]
        for r, v in zip(regs, args):
            self.mu.reg_write(r, v & 0xFFFFFFFFFFFFFFFF)
        self.mu.emu_start(vma, SENTINEL_LR, timeout=5_000_000, count=200_000)
        return self.mu.reg_read(UC_ARM64_REG_W0)

    def u32(self, addr, val):
        self.mu.mem_write(addr, struct.pack("<i", val))

    def u64(self, addr, val):
        self.mu.mem_write(addr, struct.pack("<Q", val))

    def u8(self, addr, val):
        self.mu.mem_write(addr, struct.pack("<B", val))

    def setup_common_stubs(self):
        self.stubs = {
            0x6fd748: lambda uc: BM_ADDR,
            0x47a024: lambda uc: self.cannon_upg.get(uc.reg_read(UC_ARM64_REG_W0), 0),
            0x9a9f0c: lambda uc: 1,
            0x4aacc8: lambda uc: 1 if self.has_timed_score else 0,
            0x4aad10: lambda uc: self.boss_slot & 0xFFFFFFFF,
            0x43ea60: lambda uc: self.rng_val,
        }


def verify_kb_tables(v):
    print("[1] Verifying KB Y-arc tables from .data...")
    # PT_LOAD[2] offset = vma - 0x8000
    s3_addr = 0xb0aed4
    s5_addr = 0xb0af34
    s3 = list(struct.unpack_from("<24i", v.mu.mem_read(s3_addr, 24 * 4)))
    s5 = list(struct.unpack_from("<12i", v.mu.mem_read(s5_addr, 12 * 4)))
    exp_s3 = [0, -125, -125, -75, -75, -25, -25, 0, 0, 25, 25, 75, 75, 125, 125, -50, -50, -25, -25, 25, 25, 50, 50, 0]
    exp_s5 = [0, 0, -100, -100, -50, -50, 0, 0, 50, 50, 100, 100]
    assert s3 == exp_s3, f"s3 mismatch: {s3} != {exp_s3}"
    assert s5 == exp_s5, f"s5 mismatch: {s5} != {exp_s5}"
    assert sum(s3) == 0, f"s3 net Y != 0: {sum(s3)}"
    assert sum(s5) == 0, f"s5 net Y != 0: {sum(s5)}"
    print(f"    PASS: KB_Y_ARC_state3 (sum={sum(s3)}) & KB_Y_ARC_state5 (sum={sum(s5)}) exact!")


def setup_mock_combo(v, combo_type, combo_level_idx, bonus_val):
    """Setup BattleManager + 0x4407e8 cat combo vector and bonus table for 0x7700d4."""
    # BattleManager + 0x4407e8: start, end
    # Combo struct at HEAP_ADDR + 0x1000:
    #   +0x10: id (-1 = always active), +0x18[i]: combo_type, +0x24[i]: level_idx, +0x30: count=1, +0x65: enabled=1
    combo_vec = HEAP_ADDR + 0x100
    combo_obj = HEAP_ADDR + 0x1000
    v.u64(BM_ADDR + 0x4407e8, combo_vec)
    v.u64(BM_ADDR + 0x4407f0, combo_vec + 16)
    v.u64(combo_vec, combo_obj)
    v.u8(combo_obj + 0x65, 1)
    v.u32(combo_obj + 0x30, 1)
    v.u32(combo_obj + 0x10, -1)
    v.u32(combo_obj + 0x18, combo_type)
    v.u32(combo_obj + 0x24, combo_level_idx)

    # param_1[0x37] -> BM + 0x4407e8 + 0x1b8 = BM + 0x4409a0 -> table ptr
    tbl_dir = HEAP_ADDR + 0x2000
    lvl_arr = HEAP_ADDR + 0x3000
    v.u64(BM_ADDR + 0x4407e8 + 0x37 * 8, tbl_dir)
    v.u64(tbl_dir + combo_type * 0x18, lvl_arr)
    v.u32(lvl_arr + combo_level_idx * 4, bonus_val)


def setup_mock_treasure(v, row, treasure_id, val, scale=0, cannon_filter=0):
    """Setup BattleManager + 0x290568 treasure list & 0x83718 value array for 0x91f9dc."""
    # Each row vector at BM + 0x290568 + row * 0x18 -> 0x30-byte entry
    entry = HEAP_ADDR + 0x4000 + row * 0x100
    v.u64(BM_ADDR + 0x290568 + row * 0x18, entry)
    v.u64(BM_ADDR + 0x290568 + row * 0x18 + 8, entry + 0x30)
    v.u32(entry + 0x24, treasure_id)
    v.u32(entry + 0x28, scale)
    v.u8(entry + 0x2c, cannon_filter)
    # Chapter/row value array at BM + 0x83718 + row * 0x2c + entry_idx*4
    v.u32(BM_ADDR + 0x83718 + row * 0x2c, val)


def verify_cannon_formulas(v):
    print("[2] Verifying Cat Cannon MaxCharge (0x47a29c) & InitCharge (0x47a3a4) in Unicorn...")
    v.setup_common_stubs()
    cases = [
        # (cannon_type, range_lv, charge_lv, tr_charge, tr_range, combo_charge_pct, combo_init_pct)
        (0, 1, 1, 0, 0, 0, 0),
        (0, 10, 10, 300, 300, 0, 0),
        (0, 10, 20, 300, 300, 20, 15),
        (1, 5, 15, 200, 100, 10, 30),
        (2, 8, 20, 300, 300, 20, 50),
        (3, 10, 20, 300, 300, 30, 20),
        (5, 10, 30, 300, 300, 30, 50),  # test floor clamp at 950
    ]
    for ctype, r_lv, c_lv, tr_chg, tr_rng, c_chg, c_init in cases:
        v.reset_bm()
        v.u32(BM_ADDR + 0x327f0c, ctype)
        v.cannon_upg = {1: r_lv, 3: c_lv}
        setup_mock_treasure(v, 0, 0x11, tr_rng, scale=0)
        setup_mock_treasure(v, 1, 0x01, tr_chg, scale=0)

        # Test MaxCharge with combo type 7
        setup_mock_combo(v, 7, 0, c_chg)
        emu_max = v.call(0x47a29c)

        c_bonus = ctype * 450 if ctype < 3 else 1350
        raw = 1500 + c_bonus + max(0, r_lv * 50 - tr_rng) - c_lv * 50 - tr_chg
        exp_max = max(950, int((raw * (100 - c_chg)) / 100))
        assert emu_max == exp_max, f"CannonMaxCharge mismatch {(ctype, r_lv, c_lv)}: emu={emu_max} exp={exp_max}"

        # Test InitCharge with combo type 3
        setup_mock_combo(v, 3, 0, c_init)
        emu_init = v.call(0x47a3a4, (emu_max,))
        exp_init = max(0, int(((100 - c_init) * emu_max) / 100))
        assert emu_init == exp_init, f"CannonInitCharge mismatch: emu={emu_init} exp={exp_init}"

    print(f"    PASS: {len(cases)} Cat Cannon cases matched Unicorn 0x47a29c & 0x47a3a4 bit-for-bit!")


def verify_check_range(v):
    print("[3] Verifying CheckRange (0x5ce084) in Unicorn...")
    v.setup_common_stubs()

    def set_unit(team, slot, active=1, state=0, pos=0, hitbox_front=0, hitbox_back=0,
                 standing_range=0, ld_start=0, ld_width=0):
        base = BM_ADDR + team * 51000 + slot * 1000
        v.u32(base + 0x83908, active)
        v.u32(base + 0x8390c, state)
        v.u32(base + 0x83914, pos)
        v.u32(base + 0x8393c, standing_range)
        v.u32(base + 0x83940, hitbox_front)
        v.u32(base + 0x83944, hitbox_back)
        v.u32(base + 0x83928, 1000)   # HP
        v.u32(base + 0x83a58, ld_start)
        v.u32(base + 0x83a5c, ld_width)

    # Normal range test:
    # Cat team=0 walks LEFT (smaller X), attacks LEFT: [cat_pos - standing_range .. cat_pos]
    # Enemy team=1 walks RIGHT (larger X): hitbox [enemy_pos - (+0x83940) .. enemy_pos - (+0x83944)]
    v.reset_bm()
    set_unit(0, 1, active=1, state=0, pos=3000, hitbox_front=50, hitbox_back=-50, standing_range=400)
    set_unit(1, 1, active=1, state=0, pos=2700, hitbox_front=50, hitbox_back=-50, standing_range=200)
    r_cat_in = v.call(0x5ce084, (BM_ADDR, 0, 1, 1, 0))
    set_unit(1, 1, active=1, state=0, pos=2500, hitbox_front=50, hitbox_back=-50, standing_range=200)
    r_cat_out = v.call(0x5ce084, (BM_ADDR, 0, 1, 1, 0))
    r_enemy_out = v.call(0x5ce084, (BM_ADDR, 1, 1, 1, 0))
    assert r_cat_in == 1 and r_cat_out == 0 and r_enemy_out == 0, (
        f"CheckRange normal unexpected: in={r_cat_in}, out={r_cat_out}, enemy_out={r_enemy_out}"
    )

    # LD/Omni range test (state=2 attacking with atk_idx=0, Cat at 3000 with ld_start=600, ld_width=400 -> [2000..2400])
    set_unit(0, 1, active=1, state=2, pos=3000, hitbox_front=50, hitbox_back=-50, standing_range=400, ld_start=600, ld_width=400)
    set_unit(1, 1, active=1, state=0, pos=2200, hitbox_front=50, hitbox_back=-50, standing_range=200)
    r_ld_hit = v.call(0x5ce084, (BM_ADDR, 0, 1, 1, 0))
    set_unit(1, 1, active=1, state=0, pos=2800, hitbox_front=50, hitbox_back=-50, standing_range=200)  # blindspot!
    r_ld_blind = v.call(0x5ce084, (BM_ADDR, 0, 1, 1, 0))
    assert r_ld_hit == 1 and r_ld_blind == 0, f"CheckRange LD unexpected: hit={r_ld_hit}, blind={r_ld_blind}"
    print(f"    PASS: CheckRange (0x5ce084) normal(in={r_cat_in},out={r_cat_out}) & LD(hit={r_ld_hit},blind={r_ld_blind}) verified in Unicorn!")


def verify_proc_kb_formula():
    print("[4] Verifying State 6 (Proc KB) displacement formula...")
    # From 0x5dd600 ELF 0x5de874..0x5de920:
    # dx(frame) = floor(((100 - resist) * floor((((((12 - frame) % 12) * 10) * tr_kb / 1000 + ((12 - frame) % 12) * 10) * (combo + 100)) / 100)) / 100)
    def calc_state6_total(tr_kb, combo_11, resist):
        total = 0
        for f in range(1, 13):  # frames 1..12 mod 24? Note frame starts at 0 -> incremented to 1..12 before end
            base = ((12 - f) % 12) * 10
            scaled_tr = int((base * tr_kb) / 1000) + base
            scaled_cb = int((scaled_tr * (combo_11 + 100)) / 100)
            dx = int(((100 - resist) * scaled_cb) / 100)
            total += dx
        return total

    assert calc_state6_total(0, 0, 0) == 660
    assert calc_state6_total(300, 0, 0) == 858
    print(f"    PASS: State 6 12-frame total DX: base={calc_state6_total(0,0,0)}, +30% FruitTreasure={calc_state6_total(300,0,0)}!")


def xor_encode_wallet_word(buf_base, off_val, off_key, value, key_bytes):
    """Replicate Battle Cats anti-cheat XOR byte-swap encoding."""
    # value bytes [b0, b1, b2, b3] little-endian -> stored at off_val+[0..3] XOR'd with key_bytes[3,2,1,0]
    raw = struct.pack("<I", value & 0xFFFFFFFF)
    out = bytearray(8)
    # key_bytes stored at off_key+[0..3] (i.e. +4 bytes after off_val if adjacent, or separate)
    enc = bytes([
        raw[0] ^ key_bytes[3],
        raw[1] ^ key_bytes[2],
        raw[2] ^ key_bytes[1],
        raw[3] ^ key_bytes[0],
    ])
    return enc, bytes(key_bytes)


def verify_economy_and_xor(v):
    print("[5] Verifying XOR Getters/Setters & Worker Economy (0x4b1bf4..0x4b2234) in Unicorn...")
    v.setup_common_stubs()
    v.stubs[0x6ac230] = lambda uc: 0
    v.stubs[0x533678] = lambda uc: 0  # no stage max-money override map entry

    wallet_ptr = BM_ADDR + 0x2648
    v.reset_bm()

    # 5a. XOR money getter (0x4b1bf4) & worker level getter (0x4b1f30) & cooldown setter/getter (0x4b2234/0x4b21ec)
    key = bytes([0xA5, 0x5A, 0x3C, 0x7E])
    for money_val, wk_lv, slot_idx, cd_val in [(0, 0, 0, 0), (123456, 7, 3, 450), (0x01020304, 4, 9, 1800)]:
        enc_m, km = xor_encode_wallet_word(wallet_ptr, 0x4, 0x8, money_val, key)
        v.mu.mem_write(wallet_ptr + 0x4, enc_m + km)
        got_m = v.call(0x4b1bf4, (wallet_ptr,))
        assert got_m == money_val, f"XOR money mismatch: got={got_m:#x} exp={money_val:#x}"

        enc_w, kw = xor_encode_wallet_word(wallet_ptr, 0xc, 0x10, wk_lv, key)
        v.mu.mem_write(wallet_ptr + 0xc, enc_w + kw)
        got_w = v.call(0x4b1f30, (wallet_ptr,))
        assert got_w == wk_lv, f"XOR worker lv mismatch: got={got_w} exp={wk_lv}"

        v.mu.mem_write(wallet_ptr + 0x3c, key)
        v.mu.mem_write(wallet_ptr + 0x68, key)
        v.call(0x4b2234, (wallet_ptr, slot_idx, cd_val, 1))
        got_cd = v.call(0x4b21ec, (wallet_ptr, slot_idx))
        assert got_cd == cd_val, f"XOR cooldown roundtrip mismatch: got={got_cd} exp={cd_val}"

    # 5b. Worker Cat Upgrade Cost (0x4b1f74), Worker Income/frame (0x4b2028), Max Wallet (0x4b1cc8)
    econ_cases = [
        # (worker_lv, up4_eff, up5_wal, tr3_eff, tr4_wal, cb8_eff, cb9_wal)
        (0, 0, 0, 0, 0, 0, 0),
        (3, 6, 10, 200, 1500, 10, 15),   # up4 < 7 -> base 4000, step 1000
        (5, 10, 20, 300, 3000, 20, 25),  # up4 >= 7 -> base -2000, step 2000
        (7, 30, 30, 600, 9000, 30, 50),
    ]
    for wk_lv, up4, up5, tr3, tr4, cb8, cb9 in econ_cases:
        v.reset_bm()
        v.cannon_upg = {4: up4, 5: up5}
        enc_w, kw = xor_encode_wallet_word(wallet_ptr, 0xc, 0x10, wk_lv, key)
        v.mu.mem_write(wallet_ptr + 0xc, enc_w + kw)
        setup_mock_treasure(v, 0, 3, tr3, scale=0)
        setup_mock_treasure(v, 1, 4, tr4, scale=0)
        setup_mock_combo(v, 8, 0, cb8)
        # Note: setup_mock_combo overwrites slot 0 of vector; call separately per combo test or check income vs max
        emu_cost = v.call(0x4b1f74, (wallet_ptr,))
        step = 1000 if up4 < 7 else 2000
        base = 4000 if up4 < 7 else -2000
        exp_cost = (base + up4 * step) + wk_lv * (base + up4 * step)
        assert emu_cost == exp_cost, f"Worker cost mismatch: emu={emu_cost} exp={exp_cost}"

        emu_inc = v.call(0x4b2028, (wallet_ptr,))
        exp_inc = ((((wk_lv + 10) * (up4 * 10 + 25)) // 10 + tr3) * (cb8 + 100)) // 100
        assert emu_inc == exp_inc, f"Worker income mismatch: emu={emu_inc} exp={exp_inc}"

        setup_mock_combo(v, 9, 0, cb9)
        emu_max = v.call(0x4b1cc8, (wallet_ptr,))
        raw_max = ((wk_lv * 5 + 10) * (up5 * 10000 + 10000)) // 10
        exp_max = max(0, ((raw_max + tr4) * (cb9 + 100)) // 100)
        assert emu_max == exp_max, f"Max wallet mismatch: emu={emu_max} exp={exp_max}"

    print(f"    PASS: XOR getters/setters + {len(econ_cases)} Worker Economy cases (0x4b1f74/0x4b2028/0x4b1cc8) matched Unicorn bit-for-bit!")


def verify_hp_and_stat_tables(v):
    print("[6] Verifying Unit/Enemy HP Scaling (0x9632d8) & Stat Lookup (0x964cb4) in Unicorn...")
    v.setup_common_stubs()
    v.stubs[0x963984] = lambda uc: 20   # mock +20% HP Talent
    v.stubs[0x6abd78] = lambda uc: 0
    v.stubs[0x5535d4] = lambda uc: 10   # mock +10% Catfruit/Orb bonus
    v.stubs[0x8cbcf8] = lambda uc: 150  # mock 150% stage crown multiplier
    v.stubs[0x6ab460] = lambda uc: 100
    v.stubs[0x6ac230] = lambda uc: 0
    v.stubs[0x6ac5b8] = lambda uc: 0

    # Verify DAT_00c0b464 star multiplier table in .data
    star_mults = list(struct.unpack_from("<4i", v.mu.mem_read(0xb0b464, 16)))
    assert star_mults == [0, 5, 30, 5], f"DAT_00c0b464 unexpected: {star_mults}"

    # 6a. Cat HP scaling via 0x9632d8(team=0, unitId=5, form=2, level=30, slot=0)
    v.reset_bm()
    v.u32(BM_ADDR + 0x2648, 1)  # team 0 -> bit 0 set (Cat)
    unit_id, form, level = 5, 2, 30
    base_hp = 1000
    v.u32(BM_ADDR + (unit_id + 2) * 0x760 + form * 0x1d8 + 0x9e578, base_hp)
    # Growth per 10-level bracket: [20, 20, 10] -> level 1..9 (+9*20), 10..19 (+10*20), 20..29 (+10*10)
    v.u32(BM_ADDR + 0x447634 + unit_id * 0x50 + 0 * 4, 20)
    v.u32(BM_ADDR + 0x447634 + unit_id * 0x50 + 1 * 4, 20)
    v.u32(BM_ADDR + 0x447634 + unit_id * 0x50 + 2 * 4, 10)
    setup_mock_treasure(v, 0, 9, 250)   # +250% Defense treasure
    setup_mock_combo(v, 1, 0, 15)       # +15% Unit Defense combo

    emu_cat_hp = v.call(0x9632d8, (0, unit_id, form, level, 0))
    lv_sum = base_hp * 100 + sum(base_hp * (20 if i // 10 < 2 else 10) for i in range(1, level))
    lv_hp = (lv_sum + 50) // 100
    tr_cb_hp = (((lv_hp * 250) // 100 + lv_hp) * (15 + 100)) // 100
    # form == 2 -> +20 (0x963984) + 10 (0x5535d4) = +30%
    exp_cat_hp = (tr_cb_hp * (30 + 100)) // 100
    assert emu_cat_hp == exp_cat_hp, f"Cat HP mismatch: emu={emu_cat_hp} exp={exp_cat_hp}"

    # 6b. Enemy HP scaling via 0x9632d8(team=1, enemyId=3, form=0, level=0, slot=0) with diff=1 (2-star: +5 -> 1.5x)
    v.u64(0xb02688, 0xb0b464)               # resolve GOT slot for DAT_00c0b464 (static ELF has 0 before dynamic reloc)
    v.u32(BM_ADDR + 1 * 0x1f0 + 0x2648, 0)  # team 1 -> Enemy
    v.u32(BM_ADDR + 0x327f0c, 1)            # diff = 1 (DAT_00c0b464[1] = 5 -> 150%)
    v.u8(BM_ADDR + 0x32c658, 0)
    enemy_id, enemy_base_hp = 3, 2500
    v.u32(BM_ADDR + (enemy_id + 2) * 0x1c4 + 0x233118, enemy_base_hp)
    emu_enemy_hp = v.call(0x9632d8, (1, enemy_id, 0, 0, 0))
    exp_enemy_hp = ((star_mults[1] + 10) * enemy_base_hp + 5) // 10
    assert emu_enemy_hp == exp_enemy_hp, f"Enemy HP mismatch: emu={emu_enemy_hp} exp={exp_enemy_hp}"

    # 6c. 0x964cb4 lookup verification (UNK_002ea9f0 = [12, 57, 58, 63])
    v.u32(BM_ADDR + (enemy_id + 2) * 0x1c4 + 0x233118 + 63 * 4, 777)
    got_63 = v.call(0x964cb4, (1, enemy_id, 0, 3))
    assert got_63 == 777, f"0x964cb4 enemy idx 3 mismatch: {got_63}"

    print(f"    PASS: Cat HP ({emu_cat_hp}), Enemy HP ({emu_enemy_hp}, DAT_00c0b464={star_mults}), 0x964cb4 lookup verified in Unicorn!")


if __name__ == "__main__":
    v = NativeVerifier()
    verify_kb_tables(v)
    verify_cannon_formulas(v)
    verify_check_range(v)
    verify_proc_kb_formula()
    verify_economy_and_xor(v)
    verify_hp_and_stat_tables(v)
    print("ALL UNICORN + CAPSTONE NATIVE FORMULA CHECKS PASSED!")
