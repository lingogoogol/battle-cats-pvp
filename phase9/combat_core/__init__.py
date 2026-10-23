"""
Phase 9 Clean-Room Combat Core Module
Reconstructed directly from libnative-lib.so AArch64 disassembly & Ghidra decompilation.
"""

from .unit_memory import BattlefieldMemory, NativeUnitField
from .damage_engine import NativeDamageEngine, DamageCalculationResult

__all__ = [
    "BattlefieldMemory",
    "NativeUnitField",
    "NativeDamageEngine",
    "DamageCalculationResult"
]
