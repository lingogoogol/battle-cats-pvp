"""
Battle Cats Worker Cat Wallet & Economy Manager (Native ARM64 Parity)
Restored directly from libnative-lib.so ARM64 functions:
- WorkerCost   (0x4b1f74): centi-yen upgrade cost from out-of-battle Efficiency Lv (up4 = lv - 1) and in-battle Worker Lv (0..7)
- MaxWallet    (0x4b1cc8): ((wk_lv*5 + 10) * (up5*10000 + 10000)) // 10 + tr4_centi, scaled by Nyancombo (cb9)
- WorkerIncome (0x4b2028): ((((wk_lv + 10) * (up4*10 + 25)) // 10 + tr3_centi) * (cb8 + 100)) // 100 centi-yen/frame

All native math operates in integer centi-yen (100 centi-yen = 1 displayed yen) at 30 FPS.
"""

from typing import Optional, Tuple


class WorkerCatWallet:
    """Manages integer centi-yen currency generation, upgrades, and capacity limits."""

    MAX_IN_BATTLE_LEVEL = 8

    def __init__(
        self,
        initial_money: int = 0,
        efficiency_level: int = 1,
        wallet_level: int = 1,
    ):
        self.level: int = 1  # In-battle Worker Cat Lv 1..8 (native 0-based: 0..7)
        self.max_level: int = self.MAX_IN_BATTLE_LEVEL
        self.efficiency_level: int = max(1, int(efficiency_level))  # Out-of-battle up4 (1-based)
        self.wallet_level: int = max(1, int(wallet_level))          # Out-of-battle up5 (1-based)

        self.tr3_centi: int = 0
        self.tr4_centi: int = 0
        self.combo_income_pct: int = 0
        self.combo_wallet_pct: int = 0

        self.income_multiplier: float = 1.0
        self.max_money_bonus: int = 0
        self.income_centi_per_frame: int = 25
        self.rate_per_tick_float: float = 0.25
        self.max_money_centi: int = 10000
        self.max_money: int = 100
        self.upgrade_cost_centi: Optional[int] = 4000
        self.upgrade_cost: Optional[int] = 40

        self._update_level_stats()
        self.money_centi: int = max(0, int(initial_money) * 100)

    @property
    def money(self) -> int:
        return self.money_centi // 100

    @money.setter
    def money(self, value: int):
        # Allow sandbox/test overrides without clamping below explicit assignment
        self.money_centi = max(0, int(value) * 100)

    def set_treasure_bonuses(
        self,
        rate_mult: float = 1.0,
        cap_bonus: int = 0,
        *,
        tr3_centi: Optional[int] = None,
        tr4_centi: Optional[int] = None,
    ):
        """Applies EoC Kyushu (income centi-yen/frame) & Shikoku (wallet centi-yen) treasures."""
        self.income_multiplier = float(rate_mult)
        if tr3_centi is not None:
            self.tr3_centi = max(0, int(tr3_centi))
        else:
            # rate_mult = 1.0 + eoc_ch -> eoc_ch * 100 centi-yen/frame (3 EoC ch = 300)
            self.tr3_centi = max(0, int(round((self.income_multiplier - 1.0) * 100.0)))

        if tr4_centi is not None:
            self.tr4_centi = max(0, int(tr4_centi))
        else:
            self.tr4_centi = max(0, int(cap_bonus) * 100)

        self.max_money_bonus = self.tr4_centi // 100
        self._update_level_stats()

    def set_combo_bonuses(self, income_pct: int = 0, wallet_pct: int = 0):
        """Applies Nyancombo worker income (type 8) & wallet cap (type 9) percentage boosts."""
        self.combo_income_pct = int(income_pct)
        self.combo_wallet_pct = int(wallet_pct)
        self._update_level_stats()

    def _update_level_stats(self):
        self.level = max(1, min(self.max_level, int(self.level)))
        wk_lv = self.level - 1
        up4 = max(0, int(self.efficiency_level) - 1)
        up5 = max(0, int(self.wallet_level) - 1)

        # Native 0x4b1cc8: MaxWallet in centi-yen
        raw_max_centi = ((wk_lv * 5 + 10) * (up5 * 10000 + 10000)) // 10
        self.max_money_centi = max(
            0, ((raw_max_centi + self.tr4_centi) * (self.combo_wallet_pct + 100)) // 100
        )
        self.max_money = self.max_money_centi // 100

        # Native 0x4b1f74: WorkerCost in centi-yen
        if wk_lv >= self.max_level - 1:
            self.upgrade_cost_centi = None
            self.upgrade_cost = None
        else:
            step = 1000 if up4 < 7 else 2000
            base = 4000 if up4 < 7 else -2000
            unit_cost = base + up4 * step
            self.upgrade_cost_centi = unit_cost + wk_lv * unit_cost
            self.upgrade_cost = self.upgrade_cost_centi // 100

        # Native 0x4b2028: WorkerIncome in centi-yen per frame
        self.income_centi_per_frame = (
            (((wk_lv + 10) * (up4 * 10 + 25)) // 10 + self.tr3_centi)
            * (self.combo_income_pct + 100)
        ) // 100
        self.rate_per_tick_float = self.income_centi_per_frame / 100.0

    @property
    def rate_per_tick(self) -> int:
        """Returns integer yen rate per tick for backwards-compatibility and UI display."""
        return max(1, int(round(self.rate_per_tick_float)))

    def update(self):
        """Called every simulation tick (30 FPS). Adds exact native centi-yen income."""
        if self.money_centi < self.max_money_centi:
            self.money_centi = min(
                self.max_money_centi, self.money_centi + self.income_centi_per_frame
            )

    def can_afford(self, amount: int) -> bool:
        return self.money_centi >= int(amount) * 100

    def spend(self, amount: int) -> bool:
        amount_centi = int(amount) * 100
        if self.money_centi >= amount_centi:
            self.money_centi -= amount_centi
            return True
        return False

    def add_money(self, amount: int):
        self.money_centi = min(self.max_money_centi, self.money_centi + int(amount) * 100)

    def can_upgrade(self) -> bool:
        return self.upgrade_cost_centi is not None and self.money_centi >= self.upgrade_cost_centi

    def upgrade_worker(self) -> bool:
        if self.upgrade_cost_centi is None or self.level >= self.max_level:
            return False  # Already max level (Lv 8)
        if self.money_centi >= self.upgrade_cost_centi:
            self.money_centi -= self.upgrade_cost_centi
            self.level += 1
            self._update_level_stats()
            return True
        return False

    @property
    def max_capacity(self) -> int:
        return self.max_money

    def get_status(self) -> Tuple[int, int, int, int]:
        return (self.level, self.money, self.max_money, self.upgrade_cost or 0)
