// ELF VMA: 0x9632d8
// Ghidra Addr: 0x00a632d8 (ImageBase=0x100000)
// Size: 1708 bytes


ulong BattleFn_0x009632d8(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar11;
  long lVar12;
  uint uVar13;
  undefined *puVar10;
  
  lVar6 = func_0x007fd748();
  uVar7 = BattleFn_0x004b1be4(lVar6 + (long)param_1 * 0x1f0 + 0x2648);
  if ((uVar7 & 1) != 0) {
    if ((int)param_4 < 1) {
      lVar6 = 0;
    }
    else {
      lVar6 = func_0x007fd748();
      lVar6 = (long)*(int *)(lVar6 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 + 0x9e578)
              * 100;
      if (param_4 != 1) {
        uVar13 = 1;
        do {
          func_0x007fd748();
          if (uVar13 < 200) {
            lVar8 = func_0x007fd748();
            iVar4 = *(int *)(lVar8 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 + 0x9e578);
            lVar8 = func_0x007fd748();
            lVar6 = lVar6 + (long)*(int *)(&UNK_00447634 +
                                          lVar8 + (long)param_2 * 0x50 +
                                          (ulong)((uVar13 & 0xff) / 10) * 4) * (long)iVar4;
          }
          uVar13 = uVar13 + 1;
        } while (param_4 != uVar13);
      }
      lVar6 = (lVar6 + 0x32) / 100;
    }
    lVar8 = func_0x007fd748();
    iVar4 = func_0x00a1f9dc(&UNK_00290568 + lVar8,9);
    lVar8 = func_0x007fd748();
    iVar5 = func_0x008700d4(&UNK_004407e8 + lVar8,1,param_2);
    uVar7 = (((lVar6 * iVar4) / 100 + lVar6) * (long)(iVar5 + 100)) / 100;
    iVar4 = BattleFn_0x00963984(param_1,param_2,param_3,0x20,0);
    if (1 < param_3) {
      iVar5 = func_0x007abd78(0);
      if (iVar5 == 0) {
LAB_00a63550:
        uVar11 = 9;
      }
      else {
        func_0x007fd748();
        uVar9 = func_0x00769620();
        if ((uVar9 & 1) != 0) goto LAB_00a63550;
        iVar5 = func_0x007abd78(0);
        if (iVar5 != -9) {
          func_0x007fd748();
          uVar9 = func_0x007696a4();
          if ((uVar9 & 1) == 0) {
            func_0x007fd748();
            uVar9 = func_0x0079b9f4();
            if ((uVar9 & 1) == 0) goto LAB_00a637e4;
          }
        }
        uVar11 = 0x10;
      }
      lVar6 = func_0x007fd748();
      iVar5 = func_0x006535d4(lVar6 + 0x1538,param_2,uVar11,0,0);
      iVar4 = iVar5 + iVar4;
    }
LAB_00a637e4:
    if (0 < iVar4) {
      uVar7 = (long)(uVar7 * (iVar4 + 100)) / 100;
    }
    goto LAB_00a63960;
  }
  lVar6 = func_0x007fd748();
  if ((*(int *)(&UNK_00327f0c + lVar6) < 3) &&
     (lVar6 = func_0x007fd748(), (&UNK_0032c658)[lVar6] == '\0')) {
    lVar8 = func_0x007fd748();
    lVar6 = (long)param_2 + 2;
    iVar4 = *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x7178);
    lVar8 = func_0x007fd748();
    lVar12 = ((long)*(int *)(&DAT_00c0b464 + (long)*(int *)(&UNK_00327f0c + lVar8) * 4) + 10) *
             (long)iVar4 + 5;
    lVar8 = SUB168(SEXT816(lVar12) * SEXT816(0x6666666666666667),8);
    lVar12 = lVar12 / 10 + (lVar12 >> 0x3f);
LAB_00a63630:
    uVar7 = lVar12 - (lVar8 >> 0x3f);
  }
  else {
    lVar6 = func_0x007fd748();
    iVar4 = *(int *)(&UNK_00327f0c + lVar6);
    lVar8 = func_0x007fd748();
    lVar6 = (long)param_2 + 2;
    iVar5 = *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x7178);
    lVar8 = func_0x007fd748();
    iVar1 = func_0x009cbcf8(*(long *)(lVar8 + 0x9e560) + (long)param_5 * 0x38);
    uVar7 = ((long)iVar5 * (long)iVar1 + 0x32) / 100;
    if (iVar4 == 3) {
      lVar8 = func_0x007fd748();
      uVar2 = func_0x007ac230(0);
      uVar3 = func_0x007ac5b8();
      iVar4 = func_0x007ab460(&UNK_0032b898 + lVar8,uVar2,uVar3);
      lVar12 = uVar7 * (long)iVar4;
      lVar8 = SUB168(SEXT816(lVar12) * ZEXT816(0xa3d70a3d70a3d70b),8);
      lVar12 = lVar12 / 100 + (lVar12 >> 0x3f);
      goto LAB_00a63630;
    }
  }
  lVar8 = func_0x007fd748();
  uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
  lVar8 = func_0x007fd748();
  if ((uVar9 & 1) == 0) {
    if (*(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x71c0) == 0) goto LAB_00a636e4;
LAB_00a63684:
    lVar8 = func_0x007fd748();
    uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
    if (((uVar9 & 1) == 0) &&
       (lVar8 = func_0x007fd748(), *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) != 0
       )) goto LAB_00a636e4;
    lVar6 = func_0x007fd748();
    iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x10);
    lVar6 = func_0x007fd748();
    puVar10 = &UNK_00290568 + lVar6;
    uVar11 = 0x10;
  }
  else {
    if (*(int *)(lVar8 + lVar6 * 0x760 + 0x9e5cc) != 0) goto LAB_00a63684;
    func_0x007fd748();
LAB_00a636e4:
    lVar8 = func_0x007fd748();
    uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
    lVar8 = func_0x007fd748();
    if ((uVar9 & 1) == 0) {
      if (*(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x71c0) != 0) {
LAB_00a63734:
        lVar8 = func_0x007fd748();
        uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
        if (((uVar9 & 1) == 0) &&
           (lVar8 = func_0x007fd748(),
           *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 1)) {
          lVar6 = func_0x007fd748();
          iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x12);
          lVar6 = func_0x007fd748();
          puVar10 = &UNK_00290568 + lVar6;
          uVar11 = 0x12;
          goto LAB_00a6392c;
        }
      }
    }
    else {
      if (*(int *)(lVar8 + lVar6 * 0x760 + 0x9e5cc) != 0) goto LAB_00a63734;
      func_0x007fd748();
    }
    lVar8 = func_0x007fd748();
    uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
    if (((uVar9 & 1) == 0) &&
       (lVar8 = func_0x007fd748(), *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 2
       )) {
      lVar6 = func_0x007fd748();
      iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x16);
      lVar6 = func_0x007fd748();
      puVar10 = &UNK_00290568 + lVar6;
      uVar11 = 0x16;
    }
    else {
      lVar8 = func_0x007fd748();
      uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
      if (((uVar9 & 1) == 0) &&
         (lVar8 = func_0x007fd748(),
         *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 3)) {
        lVar6 = func_0x007fd748();
        iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x17);
        lVar6 = func_0x007fd748();
        puVar10 = &UNK_00290568 + lVar6;
        uVar11 = 0x17;
      }
      else {
        lVar8 = func_0x007fd748();
        uVar9 = BattleFn_0x004b1be4(lVar8 + 0x2838);
        if (((uVar9 & 1) != 0) ||
           (lVar8 = func_0x007fd748(),
           *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) != 4)) goto LAB_00a63960;
        lVar6 = func_0x007fd748();
        iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x18);
        lVar6 = func_0x007fd748();
        puVar10 = &UNK_00290568 + lVar6;
        uVar11 = 0x18;
      }
    }
  }
LAB_00a6392c:
  iVar5 = func_0x00a1f9dc(puVar10,uVar11);
  uVar7 = (long)(uVar7 * (long)(iVar4 - iVar5)) / 100 + uVar7;
LAB_00a63960:
  return uVar7 & 0xffffffff;
}


