// ELF VMA: 0x4b1f30
// Ghidra Addr: 0x005b1f30 (ImageBase=0x100000)
// Size: 68 bytes


uint BattleFn_0x004b1f30(long param_1)

{
  return (uint)(*(byte *)(param_1 + 0x11) ^ *(byte *)(param_1 + 0xe)) << 0x10 |
         (uint)(*(byte *)(param_1 + 0x10) ^ *(byte *)(param_1 + 0xf)) << 0x18 |
         (uint)(*(byte *)(param_1 + 0x12) ^ *(byte *)(param_1 + 0xd)) << 8 |
         (uint)(*(byte *)(param_1 + 0x13) ^ *(byte *)(param_1 + 0xc));
}


