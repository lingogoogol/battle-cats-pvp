// ELF VMA: 0x0091fb18 | Ghidra Addr: 0x00a1fb18 | BodySize: 304

int BattleFn_0x0091fb18(long param_1,int param_2,int param_3)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  uVar5 = 0;
  iVar4 = 0;
  lVar6 = 0x83718;
  do {
    plVar3 = (long *)(param_1 + uVar5 * 0x18);
    lVar1 = *plVar3;
    if (plVar3[1] != lVar1) {
      lVar8 = 0;
      uVar7 = 0;
      do {
        if ((*(int *)(lVar1 + lVar8 + 0x24) == param_2) &&
           ((*(char *)(lVar1 + lVar8 + 0x2c) == '\0' ||
            (lVar1 = func_0x007fd748(), uVar5 == *(uint *)(&UNK_00327f0c + lVar1))))) {
          lVar1 = func_0x007fd748();
          iVar4 = (*(int *)(lVar1 + lVar6 + uVar7 * 4) * param_3) / 100 + iVar4;
        }
        lVar1 = *plVar3;
        uVar7 = uVar7 + 1;
        lVar8 = lVar8 + 0x30;
        uVar2 = (plVar3[1] - lVar1 >> 4) * -0x5555555555555555;
      } while (uVar7 <= uVar2 && uVar2 - uVar7 != 0);
    }
    uVar5 = uVar5 + 1;
    lVar6 = lVar6 + 0x2c;
  } while (uVar5 != 10);
  return iVar4;
}


