// ELF VMA: 0x4ab0a8
// Ghidra Addr: 0x005ab0a8 (ImageBase=0x100000)
// Size: 96 bytes


undefined4 BattleFn_0x004ab0a8(void)

{
  long lVar1;
  undefined4 *puVar2;
  
  lVar1 = func_0x007fd748();
  if (*(int *)(&UNK_00327f0c + lVar1) != 3) {
    lVar1 = func_0x007fd748();
    if (*(int *)(&UNK_00327f0c + lVar1) != 99) {
      lVar1 = func_0x007fd748();
      puVar2 = (undefined4 *)(lVar1 + 0x836d4);
      goto LAB_005ab0fc;
    }
  }
  lVar1 = func_0x007fd748();
  puVar2 = (undefined4 *)(lVar1 + 0x8370c);
LAB_005ab0fc:
  return *puVar2;
}


