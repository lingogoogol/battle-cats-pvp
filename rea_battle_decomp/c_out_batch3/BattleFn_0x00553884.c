// ELF VMA: 0x00553884 | Ghidra Addr: 0x00653884 | BodySize: 476

int BattleFn_0x00553884(long *param_1,int param_2,int param_3,int param_4,long *param_5,int param_6)

{
  long *plVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long extraout_x8;
  long *plVar7;
  int iVar8;
  
  lVar4 = func_0x007fd748();
  uVar5 = func_0x008b18c4(lVar4 + 0x468,0xffffffff,0xffffffff,0xffffffff);
  if ((uVar5 & 1) != 0) {
    return param_6;
  }
  iVar8 = 0;
LAB_00653918:
  plVar6 = (long *)param_1[0x10];
  for (plVar7 = plVar6; plVar7 != (long *)0x0; plVar7 = (long *)*plVar7) {
    if (*(int *)(plVar7 + 4) <= param_2) {
      if (param_2 <= *(int *)(plVar7 + 4)) goto LAB_00653950;
      plVar7 = plVar7 + 1;
    }
  }
  if (-1 < iVar8) {
    return param_6;
  }
  goto LAB_00653978;
LAB_00653950:
  if (param_2 < (int)plVar6[4]) {
    plVar6 = (long *)*plVar6;
  }
  else {
    if (param_2 <= (int)plVar6[4]) goto LAB_00653a2c;
    plVar6 = (long *)plVar6[1];
  }
  if (plVar6 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00311610(&UNK_00289c18);
  }
  goto LAB_00653950;
LAB_00653a2c:
  if ((int)plVar6[5] <= iVar8) {
    return param_6;
  }
LAB_00653978:
  uVar5 = func_0x00651898(uVar5,param_2,iVar8);
  iVar3 = (int)uVar5;
  if (iVar3 != -1) {
    if ((ulong)(param_1[1] - *param_1 >> 3) <= (ulong)(long)iVar3) {
      func_0x0065b92c(param_1);
      lVar4 = extraout_x8;
LAB_00653a58:
                    /* WARNING: Subroutine does not return */
      NoRet_0x00370c38(lVar4 + 0x10);
    }
    lVar4 = *(long *)(*param_1 + (long)iVar3 * 8);
    if ((*(int *)(lVar4 + 0xc) == param_3) && (plVar7 = (long *)*param_5, plVar7 != param_5 + 1)) {
      do {
        if ((*(byte *)(plVar7 + 4) & 1) != 0) {
          if ((ulong)(param_1[7] - param_1[6] >> 2) <= (ulong)(long)*(int *)(lVar4 + 8)) {
                    /* WARNING: Subroutine does not return */
            NoRet_0x00370c38(param_1 + 6);
          }
          if ((*(uint *)(param_1[6] + (long)*(int *)(lVar4 + 8) * 4) &
              *(uint *)((long)plVar7 + 0x1c)) != 0) {
            if ((ulong)(*(long *)(lVar4 + 0x18) - *(long *)(lVar4 + 0x10) >> 2) <=
                (ulong)(long)param_4) goto LAB_00653a58;
            param_6 = *(int *)(*(long *)(lVar4 + 0x10) + (long)param_4 * 4) + param_6;
            break;
          }
        }
        plVar6 = plVar7;
        plVar1 = (long *)plVar7[1];
        if ((long *)plVar7[1] == (long *)0x0) {
          do {
            plVar7 = (long *)plVar6[2];
            bVar2 = (long *)*plVar7 != plVar6;
            plVar6 = plVar7;
          } while (bVar2);
        }
        else {
          do {
            plVar7 = plVar1;
            plVar1 = (long *)*plVar7;
          } while ((long *)*plVar7 != (long *)0x0);
        }
      } while (plVar7 != param_5 + 1);
    }
  }
  iVar8 = iVar8 + 1;
  goto LAB_00653918;
}


