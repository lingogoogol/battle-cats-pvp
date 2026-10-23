"""
Wallet and Worker Cat Economy Simulation.
Handles real-time money generation, capacity upgrades, and expenditures.
"""

from typing import Tuple

class WorkerCatWallet:
    LEVELS = [
        # (Level, MaxMoney, MoneyPerTick, UpgradeCost)
        (1, 500, 1, 100),
        (2, 800, 2, 200),
        (3, 1200, 3, 400),
        (4, 1800, 4, 800),
        (5, 2600, 5, 1500),
        (6, 3600, 6, 2500),
        (7, 5000, 7, 4000),
        (8, 7000, 9, None)  # Max Level
    ]

    def __init__(self, initial_money: int = 100):
        self.level = 1
        self.money = initial_money
        self._update_level_stats()

    def _update_level_stats(self):
        idx = self.level - 1
        _, self.max_money, self.rate_per_tick, self.upgrade_cost = self.LEVELS[idx]

    def update(self):
        """Called every simulation tick (30 FPS). Generates passive income."""
        if self.money < self.max_money:
            self.money = min(self.max_money, self.money + self.rate_per_tick)

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
            return False # Already max level
        if self.spend(self.upgrade_cost):
            self.level += 1
            self._update_level_stats()
            return True
        return False

    @property
    def max_capacity(self) -> int:
        return self.max_money

    def get_status(self) -> Tuple[int, int, int, int]:
        """Returns (current_money, max_money, worker_level, next_upgrade_cost)"""
        return self.money, self.max_money, self.level, self.upgrade_cost or 0
