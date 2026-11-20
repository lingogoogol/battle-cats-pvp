// ELF VMA: 0x005dfef0 | Ghidra Addr: 0x006dfef0 | BodySize: 912

void BattleFn_0x005dfef0(long param_1)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  
  iVar10 = *(int *)(param_1 + 0x10f8);
  *(undefined4 *)(param_1 + 0x10f8) = 0;
  iVar4 = func_0x005ab154();
  if ((iVar4 == 0) && (uVar11 = func_0x005b1be4(param_1 + 0x2838), (uVar11 & 1) == 0)) {
    piVar2 = (int *)(param_1 + 0x838d0);
    lVar12 = *(long *)(param_1 + 0x9e568);
    iVar4 = *piVar2 + -1;
    *piVar2 = iVar4;
    if (lVar12 == *(long *)(param_1 + 0x9e560)) {
      uVar11 = 0;
    }
    else {
      lVar13 = 0;
      lVar14 = 0;
      uVar15 = 0;
      do {
        uVar11 = func_0x005aacc8();
        if (((uVar11 & 1) == 0) ||
           (iVar4 = func_0x005aacf0(),
           *(int *)((long)__DT_JMPREL + param_1 + (long)iVar4 * 0x1c4 + 0x723c) == 0)) {
          iVar6 = func_0x00a5a220(1,0);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
          iVar4 = *(int *)(param_1 + 0x9005c);
          iVar7 = func_0x009cbcc8(*(long *)(param_1 + 0x9e560) + lVar13);
          bVar3 = false;
          if (iVar6 <= (iVar7 * iVar4) / 100) goto LAB_006e0048;
        }
        else {
          uVar5 = func_0x005aad10();
          iVar4 = func_0x00a59b50(1,uVar5);  /* 0x959b50:[slot*1000,team*51000|off=0x83ac8|ldr w0, [x8, x9]] */
          iVar6 = func_0x009cbcc8(*(long *)(param_1 + 0x9e560) + lVar13);
          if (iVar4 < iVar6) {
            bVar3 = false;
          }
          else {
LAB_006e0048:
            bVar3 = true;
            lVar12 = *(long *)(param_1 + 0x838d8) + lVar14;
            *(int *)(lVar12 + 8) = *(int *)(lVar12 + 8) + iVar10;
          }
        }
        iVar4 = *(int *)(*(long *)(param_1 + 0x838d8) + lVar14 + 8);
        iVar6 = func_0x009cbd24(*(long *)(param_1 + 0x9e560) + lVar13);
        if ((iVar4 < iVar6) &&
           (lVar12 = *(long *)(param_1 + 0x838d8), *(int *)(lVar12 + lVar14) < 2)) {
LAB_006dff78:
          iVar4 = 1;
LAB_006dff7c:
          *(int *)(lVar12 + lVar14) = iVar4;
        }
        else if (bVar3) {
          iVar4 = func_0x009cbca8();
          if ((iVar4 == 0) ||
             (iVar4 = *(int *)(*(long *)(param_1 + 0x838d8) + lVar14 + 4),
             iVar6 = func_0x009cbca8(*(long *)(param_1 + 0x9e560) + lVar13), iVar4 < iVar6)) {
            lVar12 = *(long *)(param_1 + 0x838d8);
            iVar4 = *(int *)(lVar12 + lVar14) + -1;
            goto LAB_006dff7c;
          }
        }
        else {
          iVar4 = func_0x009cbd1c(*(long *)(param_1 + 0x9e560) + lVar13);
          if (iVar4 == 0) {
            lVar12 = *(long *)(param_1 + 0x838d8);
            goto LAB_006dff78;
          }
        }
        lVar12 = *(long *)(param_1 + 0x9e560);
        uVar15 = uVar15 + 1;
        lVar14 = lVar14 + 0xc;
        lVar13 = lVar13 + 0x38;
        uVar11 = (*(long *)(param_1 + 0x9e568) - lVar12 >> 3) * 0x6db6db6db6db6db7;
      } while (uVar15 <= uVar11 && uVar11 - uVar15 != 0);
      iVar4 = *piVar2;
    }
    if (iVar4 < 1) {
      iVar10 = 0;
      lVar13 = 0x32;
      lVar14 = 0x90428;
      do {
        piVar1 = (int *)(param_1 + lVar14);
        lVar14 = lVar14 + 1000;
        if (*piVar1 != 0) {
          iVar10 = iVar10 + 1;
        }
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
      if (iVar10 < *(int *)(param_1 + 0x9e54c)) {
        lVar14 = (uVar11 & 0xffffffff) * 0x40 + (uVar11 & 0xffffffff) * -8;
        lVar13 = ((uVar11 & 0xffffffff) + (uVar11 & 0xffffffff) * 2) * 4;
        do {
          iVar10 = (int)uVar11;
          uVar11 = (ulong)(iVar10 - 1);
          if (iVar10 < 1) {
            return;
          }
          piVar1 = (int *)(*(long *)(param_1 + 0x838d8) + -0xc + lVar13);
          lVar14 = lVar14 + -0x38;
          lVar13 = lVar13 + -0xc;
        } while (0 < *piVar1);
        uVar5 = func_0x009cbc88(lVar12 + lVar14);
        uVar8 = func_0x009cbcd0(*(long *)(param_1 + 0x9e560) + lVar14);
        uVar9 = func_0x009cbcd8(*(long *)(param_1 + 0x9e560) + lVar14);
        iVar10 = func_0x009b6dec(param_1,1,uVar5,0,uVar8,uVar9,0,uVar11);
        if (-1 < iVar10) {
          iVar10 = func_0x0043ea60((*(int *)(param_1 + 0x9e544) - *(int *)(param_1 + 0x9e540)) + 1);
          *piVar2 = *(int *)(param_1 + 0x9e540) + iVar10;
          iVar10 = func_0x009cbcc0(*(long *)(param_1 + 0x9e560) + lVar14);
          iVar4 = func_0x009cbcb8(*(long *)(param_1 + 0x9e560) + lVar14);
          iVar10 = func_0x0043ea60((iVar10 - iVar4) + 1);
          iVar4 = func_0x009cbcb8(*(long *)(param_1 + 0x9e560) + lVar14);
          lVar12 = *(long *)(param_1 + 0x9e560);
          piVar2 = (int *)(*(long *)(param_1 + 0x838d8) + lVar13);
          *piVar2 = iVar4 + iVar10;
          piVar2[1] = piVar2[1] + 1;
          iVar10 = func_0x009cbc90(lVar12 + lVar14);
          if (*(int *)(param_1 + (long)iVar10 * 4 + 0xd978) == 0) {
            iVar10 = func_0x009cbc90(*(long *)(param_1 + 0x9e560) + lVar14);
            *(undefined4 *)(param_1 + (long)iVar10 * 4 + 0xd978) = 1;
          }
        }
      }
    }
  }
  return;
}


