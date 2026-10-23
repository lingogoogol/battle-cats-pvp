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
        w9 = (multiplier * damage) & 0xffffffff
        if w9 >= 0x80000000:
            w9 -= 0x100000000

        prod = w9 * cls.MAGIC_M
        sign_bit = 1 if prod < 0 else 0
        shifted = prod >> 38
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
        if not mem.is_unit_alive(target_team, target_unit):
            return {
                'applied': False,
                'reason': 'UNIT_NOT_ALIVE',
                'final_damage': 0,
                'remaining_hp': 0,
                'killed': False,
                'knockback': False
            }

        scaled_damage = cls.scale_permille(multiplier_permille, base_damage)
        if scaled_damage < 0:
            scaled_damage = 0

        current_hp = mem.get_unit_hp(target_team, target_unit)
        new_hp = current_hp - scaled_damage
        killed = False
        knockback = False

        if new_hp <= 0:
            new_hp = 0
            killed = True
            cls.kill_unit(mem, target_team, target_unit)
        else:
            mem.set_unit_hp(target_team, target_unit, new_hp)
            if kb_threshold and scaled_damage >= kb_threshold:
                knockback = True
                mem.set_knockback_state(target_team, target_unit, 15) # default 15 frames knockback

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
