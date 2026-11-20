// ELF VMA: 0x4b21ec
// Ghidra Addr: 0x005b21ec (ImageBase=0x100000)
// Size: 72 bytes


uint BattleFn_0x004b21ec(long param_1,int param_2)

{
  long lVar1;
  
  lVar1 = param_1 + (long)param_2 * 4;
  return (uint)(*(byte *)(param_1 + 0x3e) ^ *(byte *)(lVar1 + 0x16)) << 0x10 |
         (uint)(*(byte *)(param_1 + 0x3f) ^ *(byte *)(lVar1 + 0x17)) << 0x18 |
         (uint)(*(byte *)(param_1 + 0x3d) ^ *(byte *)(lVar1 + 0x15)) << 8 |
         (uint)(*(byte *)(param_1 + 0x3c) ^ *(byte *)(lVar1 + 0x14));
}


