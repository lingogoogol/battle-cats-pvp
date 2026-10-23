"""
Native Damage Engine.
Clean-room model reverse-engineered from AArch64 libnative-lib.so:
- Scale Permille: Battle_ApplyDamageToUnit (0x004c6800 ~ 0x004c681c) using magic division constant 0x10624dd3.
- Damage & Barrier & Knockback Pipeline (0x004c6340 ~ 0x004c659c).
- Kill Unit (0x008b6f50).
"""

from typing import Dict, Any, Optional

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
    def calculate_damage(cls, base_damage: int, multiplier_permille: int = 1000) -> int:
        """Calculates final damage scaled by permille multiplier."""
        scaled = cls.scale_permille(multiplier_permille, base_damage)
        return max(0, scaled)
