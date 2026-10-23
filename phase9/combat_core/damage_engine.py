"""
Phase 9 Native Damage Calculation Engine
Reconstructed directly from Battle_ApplyDamageToUnit (0x004c6340 - 0x004c6c48)
"""

from dataclasses import dataclass
from .unit_memory import BattlefieldMemory, NativeUnitField

@dataclass
class DamageCalculationResult:
    target_team: int
    target_unit: int
    initial_hp: int
    scaled_damage: int
    remaining_hp: int
    is_knockback_triggered: bool
    is_killed: bool
    is_immune: bool

class NativeDamageEngine:
    """
    Implements the exact damage calculation, scaling, and HP mutation logic
    found in Battle_ApplyDamageToUnit (0x004c6340).
    """

    @staticmethod
    def calculate_permille_scaling(base_damage: int, multiplier_permille: int) -> int:
        """
        Reconstructs the AArch64 compiler-optimized division by 1000 (0x004c6800 - 0x004c681c):
          mul   w9, w0, w23
          mov   w8, #0x4dd3; movk w8, #0x1062, lsl #16  (w8 = 0x10624dd3)
          smull x8, w9, w8
          asr   x8, x8, #0x26                            (>> 38)
          add   w23, w8, w9
        """
        if base_damage <= 0 or multiplier_permille <= 0:
            return 0
        product = base_damage * multiplier_permille
        # Exact ARM64 magic division: (product * 0x10624dd3) >> 38
        quotient = (product * 0x10624dd3) >> 38
        return int(quotient)

    def apply_damage_to_unit(
        self,
        battlefield: BattlefieldMemory,
        target_team: int,
        target_unit: int,
        base_damage: int,
        multiplier_permille: int = 1000,
        kb_threshold: int = 0
    ) -> DamageCalculationResult:
        """
        Equivalent to Battle_ApplyDamageToUnit (0x004c6340).
        """
        # 1. Check if unit is alive (0x004c6410)
        if not battlefield.is_unit_alive(target_team, target_unit):
            return DamageCalculationResult(
                target_team=target_team,
                target_unit=target_unit,
                initial_hp=0,
                scaled_damage=0,
                remaining_hp=0,
                is_knockback_triggered=False,
                is_killed=False,
                is_immune=True
            )

        # 2. Check barrier / immunity (0x004c6434: bl #0x95ac18)
        barrier = battlefield._read_field(target_team, target_unit, NativeUnitField.STATUS_BARRIER)
        if barrier > 0:
            # Barrier absorption logic
            if base_damage < barrier:
                # Barrier absorbs all damage
                return DamageCalculationResult(
                    target_team=target_team,
                    target_unit=target_unit,
                    initial_hp=battlefield.get_unit_hp(target_team, target_unit),
                    scaled_damage=0,
                    remaining_hp=battlefield.get_unit_hp(target_team, target_unit),
                    is_knockback_triggered=False,
                    is_killed=False,
                    is_immune=True
                )
            else:
                # Barrier breaks
                battlefield._write_field(target_team, target_unit, NativeUnitField.STATUS_BARRIER, 0)

        # 3. Read current HP (0x004c641c: bl #0x95987c)
        initial_hp = battlefield.get_unit_hp(target_team, target_unit)

        # 4. Calculate damage with permille scaling (0x004c6800 - 0x004c681c)
        final_damage = self.calculate_permille_scaling(base_damage, multiplier_permille)

        # 5. Deduct HP (clamped at 0)
        remaining_hp = max(0, initial_hp - final_damage)

        # 6. Write back new HP (0x004c659c: bl #0x9598bc)
        battlefield.set_unit_hp(target_team, target_unit, remaining_hp)

        # 7. Check death vs knockback
        is_killed = (remaining_hp == 0)
        is_kb = False

        if is_killed:
            # 0x008b6f50: Battle_KillUnit
            battlefield.kill_unit(target_team, target_unit)
        else:
            # Check if crossed knockback threshold
            if kb_threshold > 0 and (initial_hp - remaining_hp) >= kb_threshold:
                # 0x00959ca8: Battle_SetUnitKnockback
                battlefield.set_knockback(target_team, target_unit, 1)
                is_kb = True

        return DamageCalculationResult(
            target_team=target_team,
            target_unit=target_unit,
            initial_hp=initial_hp,
            scaled_damage=final_damage,
            remaining_hp=remaining_hp,
            is_knockback_triggered=is_kb,
            is_killed=is_killed,
            is_immune=False
        )
