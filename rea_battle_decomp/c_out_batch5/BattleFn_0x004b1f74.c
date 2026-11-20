// ELF VMA: 0x4b1f74
// Ghidra Addr: 0x005b1f74 (ImageBase=0x100000)
// Size: 172 bytes


int BattleFn_0x004b1f74(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = func_0x0057a024(4);
  iVar2 = func_0x0057a024(4);
  iVar3 = func_0x0057a024(4);
  iVar4 = 2000;
  if (iVar1 < 7) {
    iVar4 = 1000;
  }
  iVar5 = -2000;
  if (iVar1 < 7) {
    iVar5 = 4000;
  }
  return iVar5 + iVar2 * iVar4 +
         ((uint)(*(byte *)(param_1 + 0x11) ^ *(byte *)(param_1 + 0xe)) << 0x10 |
          (uint)(*(byte *)(param_1 + 0x10) ^ *(byte *)(param_1 + 0xf)) << 0x18 |
          (uint)(*(byte *)(param_1 + 0x12) ^ *(byte *)(param_1 + 0xd)) << 8 |
         (uint)(*(byte *)(param_1 + 0x13) ^ *(byte *)(param_1 + 0xc))) * (iVar5 + iVar3 * iVar4);
}


