// ELF VMA: 0x004ab2d8 | Ghidra Addr: 0x005ab2d8 | BodySize: 164

int BattleFn_0x004ab2d8(int param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0x15;
  if (param_1 != 0) {
    iVar3 = 10;
  }
  do {
    iVar1 = func_0x005ab37c(param_1,iVar4);
    lVar2 = func_0x007fd748();
    if (iVar1 == *(int *)(lVar2 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x83908)) {
      return iVar4;
    }
    iVar4 = iVar4 + 1;
  } while (iVar3 != iVar4);
  return -1;
}


