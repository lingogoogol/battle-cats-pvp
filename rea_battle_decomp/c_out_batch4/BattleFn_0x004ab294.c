// ELF VMA: 0x4ab294
// Ghidra Addr: 0x005ab294 (ImageBase=0x100000)
// Size: 68 bytes


bool BattleFn_0x004ab294(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = func_0x007fd748();
  uVar2 = func_0x00999ab8(lVar1 + 0x400);
  if ((uVar2 & 1) != 0) {
    lVar1 = func_0x007fd748();
    return *(int *)(lVar1 + 0x836bc) != 4;
  }
  return false;
}


