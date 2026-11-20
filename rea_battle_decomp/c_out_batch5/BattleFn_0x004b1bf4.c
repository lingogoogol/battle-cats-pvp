// ELF VMA: 0x4b1bf4
// Ghidra Addr: 0x005b1bf4 (ImageBase=0x100000)
// Size: 68 bytes


uint BattleFn_0x004b1bf4(long param_1)

{
  return (uint)(*(byte *)(param_1 + 9) ^ *(byte *)(param_1 + 6)) << 0x10 |
         (uint)(*(byte *)(param_1 + 8) ^ *(byte *)(param_1 + 7)) << 0x18 |
         (uint)(*(byte *)(param_1 + 10) ^ *(byte *)(param_1 + 5)) << 8 |
         (uint)(*(byte *)(param_1 + 0xb) ^ *(byte *)(param_1 + 4));
}


