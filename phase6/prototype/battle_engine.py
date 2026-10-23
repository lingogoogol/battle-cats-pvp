"""
Battle Cats Reverse-Engineered Core Battle Engine (Clean-Room Prototype)
Target Reference: Ponos Battle Cats 30 FPS deterministic battle mechanics.
Includes: Movement, Target Selection, Attack Windup/Cooldown, HP/Death, Knockback, Win/Loss.
"""

from enum import Enum, auto
from typing import List, Optional

class Team(Enum):
    FRIENDLY = auto()
    ENEMY = auto()

class UnitState(Enum):
    MOVING = auto()
    ATTACKING = auto()
    KNOCKBACK = auto()
    DEAD = auto()

class Unit:
    def __init__(
        self,
        name: str,
        team: Team,
        hp: int,
        attack_power: int,
        range_: float,
        speed: float,
        attack_interval: int,
        pre_attack_delay: int,
        position: float = 0.0,
        kb_count: int = 1,
        kb_distance: float = 50.0,
        kb_duration: int = 10
    ):
        self.name = name
        self.team = team
        self.max_hp = hp
        self.hp = hp
        self.attack_power = attack_power
        self.range = range_
        self.speed = speed
        self.attack_interval = attack_interval      # Total ticks between attacks
        self.pre_attack_delay = pre_attack_delay    # Ticks before damage connects
        self.position = position
        
        # Knockback (KB) mechanics
        self.kb_count = max(1, kb_count)
        self.kb_distance = kb_distance
        self.kb_duration = kb_duration
        self.kb_threshold = self.max_hp / self.kb_count
        self.kb_triggers_remaining = self.kb_count - 1
        self.kb_timer = 0
        self.kb_step = kb_distance / max(1, kb_duration)
        
        self.state = UnitState.MOVING
        self.state_timer = 0
        self.damage_dealt_this_cycle = False
        self.current_target: Optional['Unit'] = None

    def is_alive(self) -> bool:
        return self.hp > 0

    def trigger_knockback(self):
        """Interrupts actions and puts unit into KNOCKBACK state."""
        self.state = UnitState.KNOCKBACK
        self.kb_timer = self.kb_duration
        self.state_timer = 0
        self.damage_dealt_this_cycle = False
        self.current_target = None

    def take_damage(self, amount: int):
        if not self.is_alive():
            return
            
        old_hp = self.hp
        self.hp = max(0, self.hp - amount)
        
        if self.hp == 0:
            self.state = UnitState.DEAD
            return

        # Check if crossed a knockback threshold
        # Thresholds: max_hp * (k / kb_count) for k in [kb_count-1, ..., 1]
        if self.kb_count > 1 and self.kb_triggers_remaining > 0:
            threshold = self.kb_threshold * self.kb_triggers_remaining
            if old_hp > threshold and self.hp <= threshold:
                self.kb_triggers_remaining -= 1
                self.trigger_knockback()

    def update(self, battlefield: 'BattleStage'):
        if not self.is_alive():
            self.state = UnitState.DEAD
            return

        # 1. Handling Knockback state
        if self.state == UnitState.KNOCKBACK:
            self.kb_timer -= 1
            # Push backwards away from enemy
            if self.team == Team.FRIENDLY:
                self.position = max(0.0, self.position - self.kb_step)
            else:
                self.position = min(battlefield.width, self.position + self.kb_step)
                
            if self.kb_timer <= 0:
                self.state = UnitState.MOVING
                self.state_timer = 0
            return

        # 2. Handling Moving state
        if self.state == UnitState.MOVING:
            target = battlefield.find_closest_target(self)
            if target and battlefield.get_distance(self, target) <= self.range:
                # Enter attack mode
                self.state = UnitState.ATTACKING
                self.state_timer = 0
                self.damage_dealt_this_cycle = False
                self.current_target = target
            else:
                # Move forward along the 1D track
                if self.team == Team.FRIENDLY:
                    self.position = min(battlefield.width, self.position + self.speed)
                else:
                    self.position = max(0.0, self.position - self.speed)

        # 3. Handling Attacking state
        elif self.state == UnitState.ATTACKING:
            self.state_timer += 1
            
            # Deal damage at the pre-attack frame
            if not self.damage_dealt_this_cycle and self.state_timer >= self.pre_attack_delay:
                # Re-validate target
                target = self.current_target
                if target and target.is_alive() and battlefield.get_distance(self, target) <= self.range:
                    target.take_damage(self.attack_power)
                else:
                    # Target died or knocked back; try closest target if still in range
                    fallback = battlefield.find_closest_target(self)
                    if fallback and battlefield.get_distance(self, fallback) <= self.range:
                        fallback.take_damage(self.attack_power)
                self.damage_dealt_this_cycle = True

            # Check if attack cycle is finished
            if self.state_timer >= self.attack_interval:
                self.state = UnitState.MOVING
                self.state_timer = 0
                self.damage_dealt_this_cycle = False
                self.current_target = None


class BaseTower(Unit):
    """Main Base Tower on battlefield. Immovable and cannot be knocked back."""
    def __init__(self, name: str, team: Team, hp: int, position: float):
        super().__init__(
            name=name,
            team=team,
            hp=hp,
            attack_power=0,
            range_=0.0,
            speed=0.0,
            attack_interval=999999,
            pre_attack_delay=999999,
            position=position,
            kb_count=1
        )

    def trigger_knockback(self):
        # Base towers cannot be knocked back
        pass

    def update(self, battlefield: 'BattleStage'):
        if self.hp <= 0:
            self.state = UnitState.DEAD


class BattleStage:
    """Represents a 1D Battle Cats battlefield stage."""
    def __init__(self, width: float = 2000.0, base_hp: int = 5000):
        self.width = width
        self.friendly_base = BaseTower("Cat Base", Team.FRIENDLY, base_hp, position=0.0)
        self.enemy_base = BaseTower("Dog Base", Team.ENEMY, base_hp, position=width)
        
        self.friendly_units: List[Unit] = []
        self.enemy_units: List[Unit] = []
        self.ticks = 0

    def spawn_friendly(self, unit: Unit, position: Optional[float] = None):
        unit.team = Team.FRIENDLY
        if position is not None:
            unit.position = position
        self.friendly_units.append(unit)

    def spawn_enemy(self, unit: Unit, position: Optional[float] = None):
        unit.team = Team.ENEMY
        if position is not None:
            unit.position = position
        self.enemy_units.append(unit)

    def get_distance(self, u1: Unit, u2: Unit) -> float:
        return abs(u1.position - u2.position)

    def find_closest_target(self, attacker: Unit) -> Optional[Unit]:
        """Find closest opponent unit; if none, target the opposing base."""
        if attacker.team == Team.FRIENDLY:
            alive_enemies = [u for u in self.enemy_units if u.is_alive()]
            if alive_enemies:
                return min(alive_enemies, key=lambda e: abs(e.position - attacker.position))
            return self.enemy_base
        else:
            alive_friendlies = [u for u in self.friendly_units if u.is_alive()]
            if alive_friendlies:
                return min(alive_friendlies, key=lambda f: abs(f.position - attacker.position))
            return self.friendly_base

    def step(self):
        self.ticks += 1
        
        # 1. Update all units
        for u in self.friendly_units:
            u.update(self)
        for u in self.enemy_units:
            u.update(self)
            
        # 2. Clean up dead units
        self.friendly_units = [u for u in self.friendly_units if u.is_alive()]
        self.enemy_units = [u for u in self.enemy_units if u.is_alive()]

    def is_victory(self) -> bool:
        return self.enemy_base.hp <= 0

    def is_defeat(self) -> bool:
        return self.friendly_base.hp <= 0

    def is_game_over(self) -> bool:
        return self.is_victory() or self.is_defeat()
