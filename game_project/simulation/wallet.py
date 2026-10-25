"""
Wallet and Worker Cat Economy Simulation - Authentic Ponos Battle Cats Edition.
Handles real-time money generation, capacity upgrades, and expenditures.
Supports official PONOS Treasure multipliers (Kyushu Worker Cat Rate, Shikoku Giant Safe Capacity).

Replaced synthetic LEVELS [(1, 500, 1, 100), (2, 800, 2, 200), ...] integer jumps
with authentic PONOS continuous sub-cent accumulator:
- Base generation rate: 46.125 cents/sec (184.5 cents/sec with 3-chapter Kyushu +300%)
- Piecewise scaling: +5% of baseline per in-battle Worker Cat level (1.0..1.35x)
- Sub-cent floating accumulator prevents discrete step truncation
- Base capacities: [500, 800, 1200, 1800, 2600, 3600, 5000, 7000]
- Upgrade costs: [100, 200, 400, 800, 1500, 2500, 4000, None]
"""

from typing import Tuple, Optional, List

class WorkerCatWallet:
    # Official in-battle capacities (before Shikoku treasure bonuses)
    BASE_CAPACITIES = [500, 800, 1200, 1800, 2600, 3600, 5000, 7000]
    # Official in-battle upgrade costs
    UPGRADE_COSTS = [100, 200, 400, 800, 1500, 2500, 4000, None]
    # Raw baseline generation rate before treasures: 46.125 cents/sec (1.5375 cents/frame @ 30 FPS)
    BASE_RATE_PER_SEC = 46.125

    # Backwards-compatible tuple table for external inspections
    LEVELS = [
        (1, 500, 6, 100),
        (2, 800, 6, 200),
        (3, 1200, 7, 400),
        (4, 1800, 7, 800),
        (5, 2600, 7, 1500),
        (6, 3600, 8, 2500),
        (7, 5000, 8, 4000),
        (8, 7000, 8, None)
    ]

    def __init__(self, initial_money: int = 100):
        self.level = 1
        self.money = initial_money
        self._sub_cents = 0.0
        self.income_multiplier = 1.0
        self.max_money_bonus = 0
        self.rate_per_tick_float = self.BASE_RATE_PER_SEC / 30.0
        self._update_level_stats()

    def set_treasure_bonuses(self, rate_mult: float = 1.0, cap_bonus: int = 0):
        self.income_multiplier = float(rate_mult)
        self.max_money_bonus = int(cap_bonus)
        self._update_level_stats()

    def _update_level_stats(self):
        idx = min(7, max(0, self.level - 1))
        self.max_money = self.BASE_CAPACITIES[idx] + self.max_money_bonus
        self.upgrade_cost = self.UPGRADE_COSTS[idx]
        # Authentic Battle Cats formula: +5% of baseline per in-game level
        level_scaling = 1.0 + 0.05 * (self.level - 1)
        rate_per_sec = self.BASE_RATE_PER_SEC * self.income_multiplier * level_scaling
        self.rate_per_tick_float = rate_per_sec / 30.0

    @property
    def rate_per_tick(self) -> int:
        """Returns integer rate per tick for backwards-compatibility and UI display."""
        return max(1, int(round(self.rate_per_tick_float)))

    def update(self):
        """Called every simulation tick (30 FPS). Generates passive income with sub-cent accumulator."""
        if self.money < self.max_money:
            self._sub_cents += self.rate_per_tick_float
            cents = int(self._sub_cents)
            if cents > 0:
                self.money = min(self.max_money, self.money + cents)
                self._sub_cents -= cents

    def can_afford(self, amount: int) -> bool:
        return self.money >= amount

    def spend(self, amount: int) -> bool:
        if self.can_afford(amount):
            self.money -= amount
            return True
        return False

    def add_money(self, amount: int):
        self.money = min(self.max_money, self.money + amount)

    def upgrade_worker(self) -> bool:
        if self.upgrade_cost is None:
            return False  # Already max level (Lv 8)
        if self.spend(self.upgrade_cost):
            self.level += 1
            self._update_level_stats()
            return True
        return False

    @property
    def max_capacity(self) -> int:
        return self.max_money

    def get_status(self) -> Tuple[int, int, int, int]:
        return (self.level, self.money, self.max_money, self.upgrade_cost or 0)
