// ELF VMA: 0x0091f9dc | Ghidra Addr: 0x00a1f9dc | BodySize: 316

int BattleFn_0x0091f9dc(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  
  uVar7 = 0;
  iVar6 = 0;
  lVar8 = 0x83718;
  do {
    plVar10 = (long *)(param_1 + uVar7 * 0x18);
    lVar3 = *plVar10;
    if (plVar10[1] != lVar3) {
      lVar5 = 0;
      uVar9 = 0;
      do {
        if (*(int *)(lVar3 + lVar5 + 0x24) == param_2) {
          if (*(char *)(lVar3 + lVar5 + 0x2c) != '\0') {
            lVar3 = func_0x007fd748();
            if (uVar7 != *(uint *)(&UNK_00327f0c + lVar3)) goto LAB_00a1fa64;  /* field_off=0x327f0c */
            lVar3 = *plVar10;
          }
          iVar1 = *(int *)(lVar3 + lVar5 + 0x28);
          lVar3 = func_0x007fd748();
          iVar2 = *(int *)(lVar3 + lVar8 + uVar9 * 4);
          if (iVar1 != 0) {
            iVar2 = (iVar2 * iVar1) / 100;
          }
          iVar6 = iVar2 + iVar6;
        }
LAB_00a1fa64:
        lVar3 = *plVar10;
        uVar9 = uVar9 + 1;
        lVar5 = lVar5 + 0x30;
        uVar4 = (plVar10[1] - lVar3 >> 4) * -0x5555555555555555;  /* ascii(0x5555555555555555)='UUUUUUUU' */
      } while (uVar9 <= uVar4 && uVar4 - uVar9 != 0);
    }
    uVar7 = uVar7 + 1;
    lVar8 = lVar8 + 0x2c;
    if (uVar7 == 10) {
      return iVar6;
    }
  } while( true );
}


