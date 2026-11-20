// ELF VMA: 0x4abf1c
// Ghidra Addr: 0x005abf1c (ImageBase=0x100000)
// Size: 136 bytes


undefined4 BattleFn_0x004abf1c(int param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  if (param_1 == 1) {
    lVar2 = func_0x007fd748();
    uVar3 = func_0x005b1be4(lVar2 + 0x2838);
    if ((uVar3 & 1) == 0) {
      return 0;
    }
    lVar2 = func_0x007fd748();
    iVar1 = func_0x005ab37c(1,param_2);
    puVar4 = (undefined4 *)(lVar2 + (long)iVar1 * 4 + 0x49604);
  }
  else {
    if ((param_1 != 0) || (9 < param_2)) {
      return 0;
    }
    lVar2 = func_0x007fd748();
    puVar4 = (undefined4 *)(&UNK_00327f50 + lVar2 + (ulong)param_2 * 4);
  }
  return *puVar4;
}


