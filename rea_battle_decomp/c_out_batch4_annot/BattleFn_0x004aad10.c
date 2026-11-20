// ELF VMA: 0x4aad10
// Ghidra Addr: 0x005aad10 (ImageBase=0x100000)
// Size: 128 bytes


int BattleFn_0x004aad10(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = func_0x007fd748();
  if (0 < *(int *)(lVar2 + 0x9e550)) {
    func_0x007fd748();
    iVar3 = 0;
    do {
      iVar1 = func_0x00a588f4(1,iVar3);
      lVar2 = func_0x007fd748();
      if (iVar1 == *(int *)(lVar2 + 0x9e550)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      func_0x007fd748();
    } while (iVar3 != 0x33);
  }
  return -1;
}


