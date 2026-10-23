"""
NativeDamageEngine - Clean-room model of The Battle Cats combat damage calculation.
Corresponds to Battle_ApplyDamageToUnit (0x004c6340) and Battle_KillUnit (0x008b6f50).
"""

from .unit_memory import BattlefieldMemory

class NativeDamageEngine:
    MAGIC_M = 0x10624dd3  # Compiler magic constant for division by 1000

    @classmethod
    def scale_permille(cls, multiplier: int, damage: int) -> int:
        """
        Replicates AArch64 binary instructions at 0x004c6800 ~ 0x004c681c:
            mul      w9, w0, w23
            mov      w8, #0x4dd3
            movk     w8, #0x1062, lsl #16
            smull    x8, w9, w8
            lsr      x9, x8, #0x3f
            asr      x8, x8, #0x26
            add      w23, w8, w9
        """
        # 1. 32-bit signed multiply modulo 2^32
        w9 = (multiplier * damage) & 0xffffffff
        if w9 >= 0x80000000:
            w9 -= 0x100000000

        # 2. 64-bit signed multiplication with magic constant
        prod = w9 * cls.MAGIC_M

        # 3. Extract sign bit (bit 63)
        sign_bit = 1 if prod < 0 else 0

        # 4. Arithmetic shift right by 38
        shifted = prod >> 38

        # 5. Add sign bit to correct towards-zero truncation
        res = (shifted + sign_bit) & 0xffffffff
        if res >= 0x80000000:
            res -= 0x100000000

        return res

    @classmethod
    def apply_damage(cls, mem: BattlefieldMemory, target_team: int, target_unit: int, 
                     base_damage: int, multiplier_permille: int = 1000, 
                     kb_threshold: int = None) -> dict:
        """
        Executes damage application matching Battle_ApplyDamageToUnit.
        """
        # 1. Verify unit is alive (0x004c6410: tbz w8, #0, #0x4c6c1c)
        if not mem.is_unit_alive(target_team, target_unit):
            return {
                'applied': False,
                'reason': 'UNIT_NOT_ALIVE',
                'final_damage': 0,
                'remaining_hp': 0,
                'killed': False,
                'knockback': False
            }

        # 2. Compute scaled damage via magic division (0x004c6800 ~ 0x004c681c)
        scaled_damage = cls.scale_permille(multiplier_permille, base_damage)
        if scaled_damage < 0:
            scaled_damage = 0

        # 3. Check barrier / immunity (0x004c6434: bl #0x95ac18)
        barrier = mem.get_barrier(target_team, target_unit)
        if barrier > 0:
            if scaled_damage < barrier:
                # Barrier absorbs damage completely
                return {
                    'applied': True,
                    'reason': 'BARRIER_ABSORBED',
                    'final_damage': 0,
                    'remaining_hp': mem.get_unit_hp(target_team, target_unit),
                    'killed': False,
                    'knockback': False,
                    'barrier_remaining': barrier
                }
            else:
                # Barrier breaks
                mem.set_barrier(target_team, target_unit, 0)

        # 4. Read current HP (0x004c641c: bl #0x95987c)
        current_hp = mem.get_unit_hp(target_team, target_unit)

        # 5. Calculate new HP
        new_hp = current_hp - scaled_damage
        killed = False
        knockback = False

        # 6. Branch on HP depletion vs Survival
        if new_hp <= 0:
            new_hp = 0
            killed = True
            # Trigger Battle_KillUnit (0x008b6f50)
            cls.kill_unit(mem, target_team, target_unit)
        else:
            # Write back new HP (0x004c659c: bl #0x9598bc)
            mem.set_unit_hp(target_team, target_unit, new_hp)
            
            # Check knockback threshold trigger (0x00959ca8: bl #0x959ca8)
            if kb_threshold and scaled_damage >= kb_threshold:
                knockback = True
                mem.set_knockback_state(target_team, target_unit, 1)

        return {
            'applied': True,
            'reason': 'DAMAGE_APPLIED',
            'final_damage': scaled_damage,
            'remaining_hp': new_hp,
            'killed': killed,
            'knockback': knockback
        }

    @staticmethod
    def kill_unit(mem: BattlefieldMemory, team: int, unit: int):
        """
        Executes Battle_KillUnit (0x008b6f50):
            0x008b6f88: bl #0x9598bc (SetUnitHP -> 0)
            0x008b6f98: bl #0x959950 (SetUnitAlive -> 0)
            0x008b6fa8: bl #0x959b90 (SetUnitAttackTimer -> 0)
        """
        mem.set_unit_hp(team, unit, 0)
        mem.set_unit_alive(team, unit, False)
        mem.set_attack_timer(team, unit, 0)
