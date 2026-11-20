// ELF VMA: 0x5d4f44
// Ghidra Addr: 0x006d4f44 (ImageBase=0x100000)
// Size: 432 bytes


long * BattleFn_0x005d4f44(ulong *param_1,long *param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  
  lVar14 = param_1[1] - *param_1;
  lVar11 = lVar14 >> 3;
  uVar1 = lVar11 + 1;
  if (uVar1 >> 0x3d != 0) {
    BattleFn_0x005d50f4(param_1);
LAB_006d50f0:
                    /* WARNING: Subroutine does not return */
    NoRet_0x0030fc1c();
  }
  uVar3 = param_1[2] - *param_1;
  uVar4 = (long)uVar3 >> 2;
  if (uVar4 <= uVar1) {
    uVar4 = uVar1;
  }
  if (0x7ffffffffffffff7 < uVar3) {
    uVar4 = 0x1fffffffffffffff;
  }
  if (uVar4 == 0) {
    lVar2 = 0;
  }
  else {
    if (uVar4 >> 0x3d != 0) goto LAB_006d50f0;
    lVar2 = func_0x00bc3330(uVar4 << 3);
  }
  lVar7 = *param_2;
  *param_2 = 0;
  plVar6 = (long *)(lVar2 + lVar11 * 8);
  plVar13 = (long *)*param_1;
  plVar12 = (long *)param_1[1];
  uVar1 = lVar2 + uVar4 * 8;
  plVar10 = plVar6 + 1;
  *plVar6 = lVar7;
  lVar11 = (long)plVar12 - (long)plVar13;
  if (lVar11 == 0) {
    *param_1 = (ulong)plVar6;
    param_1[1] = (ulong)plVar10;
    param_1[2] = uVar1;
    goto joined_r0x006d50e0;
  }
  uVar4 = lVar11 - 8;
  plVar5 = plVar6;
  if ((uVar4 < 0x78) ||
     (((long *)((long)plVar12 + (-8 - (uVar4 & 0xfffffffffffffff8))) < plVar6 &&
      ((long *)((lVar14 - (uVar4 & 0xfffffffffffffff8)) + lVar2 + -8) < plVar12)))) {
LAB_006d5068:
    do {
      plVar12 = plVar12 + -1;
      lVar11 = *plVar12;
      *plVar12 = 0;
      plVar5 = plVar5 + -1;
      *plVar5 = lVar11;
    } while (plVar12 != plVar13);
  }
  else {
    plVar9 = plVar12 + -2;
    uVar4 = (uVar4 >> 3) + 1;
    uVar8 = uVar4 & 0x3ffffffffffffffc;
    plVar5 = plVar6 + -uVar8;
    plVar12 = plVar12 + -uVar8;
    plVar6 = plVar6 + -2;
    uVar3 = uVar8;
    do {
      lVar7 = plVar9[-1];
      lVar2 = plVar9[-2];
      lVar14 = plVar9[1];
      lVar11 = *plVar9;
      uVar3 = uVar3 - 4;
      plVar9[-1] = 0;
      plVar9[-2] = 0;
      plVar9[1] = 0;
      *plVar9 = 0;
      plVar9 = plVar9 + -4;
      plVar6[-1] = lVar7;
      plVar6[-2] = lVar2;
      plVar6[1] = lVar14;
      *plVar6 = lVar11;
      plVar6 = plVar6 + -4;
    } while (uVar3 != 0);
    if (uVar4 != uVar8) goto LAB_006d5068;
  }
  plVar6 = (long *)*param_1;
  plVar13 = (long *)param_1[1];
  *param_1 = (ulong)plVar5;
  param_1[1] = (ulong)plVar10;
  param_1[2] = uVar1;
  plVar12 = plVar13;
  while (plVar13 != plVar6) {
    plVar13 = plVar13 + -1;
    lVar11 = *plVar13;
    *plVar13 = 0;
    plVar12 = plVar6;
    if (lVar11 != 0) {
      func_0x00bc3350();
    }
  }
joined_r0x006d50e0:
  if (plVar12 != (long *)0x0) {
    func_0x00bc3350(plVar12);
  }
  return plVar10;
}


