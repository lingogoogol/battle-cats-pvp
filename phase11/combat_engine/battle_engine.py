"""
IntegratedBattleEngine - Unified clean-room battle engine orchestrating Phase 9-11 verified logic.
Covers 8 core loop steps:
    1. Unit State Initialization
    2. Battlefield Position Read
    3. Movement and Knockback Update
    4. Attack Condition Check
    5. Attack Timer Update
    6. Damage Calculation
    7. HP Writeback
    8. Death & Castle Depletion Evaluation
"""

from .unit_memory import BattlefieldMemory
from .damage_engine import NativeDamageEngine

class IntegratedBattleEngine:
    def __init__(self, battlefield_length=6000):
        self.mem = BattlefieldMemory()
        self.battlefield_length = battlefield_length
        self.current_frame = 0
        
        # Unit static specs cache (representing CSV / config data)
        # [INFERRED]: Range, attack cooldown and base damage are loaded from asset CSVs
        self.unit_specs = {} # key: (team, slot) -> dict of specs

        # Initialize Castles (Slot 0 for each team)
        # Cat Castle at Position 0
        self.initialize_unit(team=0, slot=0, unit_id=0, hp=100000, speed=0, 
                            attack_range=0, attack_interval=0, base_damage=0, pos_x=0)
        # Enemy Castle at Position battlefield_length
        self.initialize_unit(team=1, slot=0, unit_id=0, hp=100000, speed=0, 
                            attack_range=0, attack_interval=0, base_damage=0, pos_x=battlefield_length)

    def initialize_unit(self, team: int, slot: int, unit_id: int, hp: int, speed: int, 
                        attack_range: int, attack_interval: int, base_damage: int, pos_x: int):
        """Step 1: Unit State Initialization [VERIFIED memory layout]"""
        self.mem.set_unit_alive(team, slot, True)
        self.mem.set_unit_hp(team, slot, hp)
        self.mem.set_position_x(team, slot, pos_x)
        self.mem.set_speed(team, slot, speed)
        self.mem.set_knockback_state(team, slot, 0)
        self.mem.set_attack_timer(team, slot, 0)
        self.mem.set_move_flag(team, slot, 1) # 1 = can move
        
        self.unit_specs[(team, slot)] = {
            'unit_id': unit_id,
            'max_hp': hp,
            'attack_range': attack_range,
            'attack_interval': attack_interval,
            'base_damage': base_damage,
            'kb_threshold': hp // 3 if hp > 0 else 1 # [ASSUMED]: 3 KBs default
        }

    def step_frame(self) -> dict:
        """
        Executes one complete battle frame simulation (corresponds to 1 game tick).
        Returns a frame log of events and unit states.
        """
        self.current_frame += 1
        frame_log = {
            'frame': self.current_frame,
            'events': [],
            'states': {}
        }

        # Step 2 & 3: Movement & Knockback Update [VERIFIED in 0x005c8c70 ~ 0x005c8d50]
        self._update_movement_and_knockback(frame_log)

        # Step 4, 5, 6, 7: Attack and Damage Pipeline [VERIFIED in 0x004c6340]
        self._update_attacks_and_damage(frame_log)

        # Step 8: Death & Victory Evaluation [VERIFIED in 0x008b6f50]
        self._evaluate_deaths_and_castle(frame_log)

        # Snapshot active states
        for team in (0, 1):
            for slot in range(BattlefieldMemory.MAX_UNITS_PER_TEAM):
                if self.mem.is_unit_alive(team, slot):
                    frame_log['states'][(team, slot)] = {
                        'hp': self.mem.get_unit_hp(team, slot),
                        'pos_x': self.mem.get_position_x(team, slot),
                        'kb': self.mem.get_knockback_state(team, slot),
                        'atk_timer': self.mem.get_attack_timer(team, slot)
                    }

        return frame_log

    def _update_movement_and_knockback(self, log: dict):
        """
        Implements 51-slot loop from 0x005c8ad4 and 0x005c9360.
        Outer loop iterates slots 1..50 (Slot 0 Castle does not move).
        """
        for team in (0, 1):
            opp_team = 1 - team
            # Find closest enemy or enemy castle position
            opp_positions = [
                self.mem.get_position_x(opp_team, s) 
                for s in range(BattlefieldMemory.MAX_UNITS_PER_TEAM) 
                if self.mem.is_unit_alive(opp_team, s)
            ]

            for slot in range(1, BattlefieldMemory.MAX_UNITS_PER_TEAM):
                if not self.mem.is_unit_alive(team, slot):
                    continue

                kb = self.mem.get_knockback_state(team, slot)
                if kb > 0:
                    # In Knockback state: decrement timer by 1 via add_knockback(-1) [VERIFIED 0x00959cf4]
                    self.mem.add_knockback(team, slot, -1)
                    # Pushes unit back [ASSUMED: 10 pixels per frame during knockback]
                    curr_pos = self.mem.get_position_x(team, slot)
                    kb_dir = -1 if team == 0 else 1
                    self.mem.set_position_x(team, slot, curr_pos + kb_dir * 10)
                    log['events'].append(f"Team {team} Slot {slot} Knockback active: remaining={kb-1}")
                    continue

                # Check stopping distance against closest enemy/castle [VERIFIED 0x005ce084]
                specs = self.unit_specs.get((team, slot), {})
                atk_range = specs.get('attack_range', 140)
                curr_pos = self.mem.get_position_x(team, slot)

                # Check if in range of any enemy
                in_range = False
                for opp_pos in opp_positions:
                    dist = abs(curr_pos - opp_pos)
                    if dist <= atk_range:
                        in_range = True
                        break

                if in_range:
                    # Unit stopped to attack
                    self.mem.set_move_flag(team, slot, 0)
                else:
                    # Unit free to advance [VERIFIED 0x0095a494]
                    self.mem.set_move_flag(team, slot, 1)
                    speed = self.mem.get_speed(team, slot)
                    move_dir = 1 if team == 0 else -1
                    new_pos = curr_pos + move_dir * speed
                    self.mem.set_position_x(team, slot, new_pos)

    def _update_attacks_and_damage(self, log: dict):
        """
        Executes attack cooldown and damage application matching Battle_ApplyDamageToUnit.
        """
        for team in (0, 1):
            opp_team = 1 - team
            for slot in range(1, BattlefieldMemory.MAX_UNITS_PER_TEAM):
                if not self.mem.is_unit_alive(team, slot):
                    continue

                timer = self.mem.get_attack_timer(team, slot)
                specs = self.unit_specs.get((team, slot), {})
                atk_interval = specs.get('attack_interval', 30)
                atk_range = specs.get('attack_range', 140)
                base_dmg = specs.get('base_damage', 100)
                curr_pos = self.mem.get_position_x(team, slot)

                if timer > 0:
                    # Cooldown countdown [VERIFIED 0x00959b50]
                    self.mem.set_attack_timer(team, slot, timer - 1)
                    continue

                # Timer is 0: Check if can launch attack
                # Find valid target in range (prioritize closest enemy, fallback to Castle Slot 0)
                target_slot = None
                min_dist = 999999
                for s in range(BattlefieldMemory.MAX_UNITS_PER_TEAM):
                    if self.mem.is_unit_alive(opp_team, s):
                        dist = abs(curr_pos - self.mem.get_position_x(opp_team, s))
                        if dist <= atk_range and dist < min_dist:
                            min_dist = dist
                            target_slot = s

                if target_slot is not None:
                    # Trigger attack!
                    self.mem.set_attack_timer(team, slot, atk_interval)
                    kb_thresh = self.unit_specs.get((opp_team, target_slot), {}).get('kb_threshold', 100)
                    
                    # Execute Damage Application [VERIFIED 0x004c6340]
                    res = NativeDamageEngine.apply_damage(
                        self.mem, target_team=opp_team, target_unit=target_slot,
                        base_damage=base_dmg, multiplier_permille=1000,
                        kb_threshold=kb_thresh
                    )
                    log['events'].append(
                        f"ATTACK: Team {team} Slot {slot} attacked Opponent Team {opp_team} Slot {target_slot} "
                        f"for {res['final_damage']} dmg (Remaining HP={res['remaining_hp']}, Killed={res['killed']}, KB={res['knockback']})"
                    )

    def _evaluate_deaths_and_castle(self, log: dict):
        """
        Step 8: Checks castle destruction and victory.
        """
        for team in (0, 1):
            castle_hp = self.mem.get_unit_hp(team, 0)
            if castle_hp <= 0:
                log['events'].append(f"VICTORY: Team {1 - team} destroyed Castle of Team {team}!")
                log['winner'] = 1 - team
                return
