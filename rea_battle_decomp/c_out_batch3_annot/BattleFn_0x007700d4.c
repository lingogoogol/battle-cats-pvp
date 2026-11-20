// ELF VMA: 0x007700d4 | Ghidra Addr: 0x008700d4 | BodySize: 264

int BattleFn_0x007700d4(long *param_1,int param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  
  plVar5 = (long *)*param_1;
  plVar1 = (long *)param_1[1];
  if (plVar5 == plVar1) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    do {
      lVar3 = *plVar5;
      if ((*(char *)(lVar3 + 0x65) != '\0') && (0 < *(int *)(lVar3 + 0x30))) {
        lVar6 = 0;
        do {
          if (*(int *)(lVar3 + lVar6 * 4 + 0x18) == param_2) {
            if (*(int *)(lVar3 + 0x10) != -1) {
              lVar3 = func_0x007fd748();
              uVar2 = func_0x009a9f0c(&UNK_0033b850 + lVar3,*(undefined4 *)(*plVar5 + 0x10),param_3)  /* field_off=0x33b850 */
              ;
              lVar3 = *plVar5;
              if ((uVar2 & 1) == 0) goto LAB_00870168;
            }
            iVar4 = *(int *)(*(long *)(param_1[0x37] + (long)param_2 * 0x18) +
                            (long)*(int *)(lVar3 + lVar6 * 4 + 0x24) * 4) + iVar4;
          }
LAB_00870168:
          lVar6 = lVar6 + 1;
        } while (lVar6 < *(int *)(lVar3 + 0x30));
      }
      plVar5 = plVar5 + 2;
    } while (plVar5 != plVar1);
  }
  return iVar4;
}


