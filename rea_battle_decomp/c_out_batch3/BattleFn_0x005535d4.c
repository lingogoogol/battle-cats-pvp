// ELF VMA: 0x005535d4 | Ghidra Addr: 0x006535d4 | BodySize: 356

undefined4 BattleFn_0x005535d4(long *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  long extraout_x8;
  long *plVar5;
  int iVar6;
  int iVar7;
  
  lVar2 = func_0x007fd748();
  uVar3 = func_0x008b18c4(lVar2 + 0x468,0xffffffff,0xffffffff,0xffffffff);
  if ((uVar3 & 1) != 0) {
    return param_5;
  }
  iVar6 = 0;
  iVar7 = -1;
LAB_0065364c:
  plVar4 = (long *)param_1[0x10];
  for (plVar5 = plVar4; plVar5 != (long *)0x0; plVar5 = (long *)*plVar5) {
    if (*(int *)(plVar5 + 4) <= param_2) {
      if (param_2 <= *(int *)(plVar5 + 4)) goto LAB_00653684;
      plVar5 = plVar5 + 1;
    }
  }
  if (-1 < iVar6) {
    return param_5;
  }
  goto LAB_006536ac;
LAB_00653684:
  if (param_2 < (int)plVar4[4]) {
    plVar4 = (long *)*plVar4;
  }
  else {
    if (param_2 <= (int)plVar4[4]) goto LAB_0065370c;
    plVar4 = (long *)plVar4[1];
  }
  if (plVar4 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00311610(&UNK_00289c18);
  }
  goto LAB_00653684;
LAB_0065370c:
  if ((int)plVar4[5] <= iVar6) {
    return param_5;
  }
LAB_006536ac:
  uVar3 = func_0x00651898(uVar3,param_2,iVar6);
  iVar1 = (int)uVar3;
  if (iVar1 != -1) {
    if ((ulong)(param_1[1] - *param_1 >> 3) <= (ulong)(long)iVar1) {
      func_0x0065b92c(param_1);
      lVar2 = extraout_x8;
LAB_00653730:
                    /* WARNING: Subroutine does not return */
      NoRet_0x00370c38(lVar2 + 0x10);
    }
    lVar2 = *(long *)(*param_1 + (long)iVar1 * 8);
    if ((*(int *)(lVar2 + 0xc) == param_3) && (iVar7 < *(int *)(lVar2 + 4))) {
      if ((ulong)(*(long *)(lVar2 + 0x18) - *(long *)(lVar2 + 0x10) >> 2) <= (ulong)(long)param_4)
      goto LAB_00653730;
      param_5 = *(undefined4 *)(*(long *)(lVar2 + 0x10) + (long)param_4 * 4);
      iVar7 = *(int *)(lVar2 + 4);
    }
  }
  iVar6 = iVar6 + 1;
  goto LAB_0065364c;
}


