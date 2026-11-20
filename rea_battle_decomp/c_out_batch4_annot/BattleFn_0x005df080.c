// ELF VMA: 0x5df080
// Ghidra Addr: 0x006df080 (ImageBase=0x100000)
// Size: 368 bytes


void BattleFn_0x005df080(ulong *param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulong uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  long lVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  puVar12 = (undefined4 *)param_1[1];
  if (puVar12 < (undefined4 *)param_1[2]) {
    puVar14 = puVar12 + 1;
    *puVar12 = *param_2;
    goto LAB_006df1c8;
  }
  puVar11 = (undefined4 *)*param_1;
  lVar13 = (long)puVar12 - (long)puVar11 >> 2;
  uVar4 = lVar13 + 1;
  if (uVar4 >> 0x3e != 0) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00341cdc(param_1);
  }
  uVar3 = (long)param_1[2] - (long)puVar11;
  uVar7 = (long)uVar3 >> 1;
  if (uVar7 <= uVar4) {
    uVar7 = uVar4;
  }
  if (0x7ffffffffffffffb < uVar3) {
    uVar7 = 0x3fffffffffffffff;
  }
  if (uVar7 == 0) {
    lVar2 = 0;
  }
  else {
    if (uVar7 >> 0x3e != 0) {
                    /* WARNING: Subroutine does not return */
      NoRet_0x0030fc1c();
    }
    lVar2 = func_0x00bc3330(uVar7 << 2);
  }
  puVar6 = (undefined4 *)(lVar2 + lVar13 * 4);
  puVar14 = puVar6 + 1;
  *puVar6 = *param_2;
  if ((long)puVar12 - (long)puVar11 != 0) {
    uVar4 = ((long)puVar12 - (long)puVar11) - 4;
    puVar5 = puVar6;
    if ((0x1b < uVar4) &&
       (0x1f < (ulong)((long)puVar12 + (-((long)puVar12 - (long)puVar11) - lVar2)))) {
      puVar10 = (undefined8 *)(puVar12 + -4);
      uVar4 = (uVar4 >> 2) + 1;
      uVar9 = uVar4 & 0x7ffffffffffffff8;
      puVar12 = puVar12 + -uVar9;
      puVar5 = puVar6 + -uVar9;
      puVar8 = (undefined8 *)(puVar6 + -4);
      uVar3 = uVar9;
      do {
        puVar1 = puVar10 + -1;
        uVar17 = puVar10[-2];
        uVar16 = puVar10[1];
        uVar15 = *puVar10;
        uVar3 = uVar3 - 8;
        puVar10 = puVar10 + -4;
        puVar8[-1] = *puVar1;
        puVar8[-2] = uVar17;
        puVar8[1] = uVar16;
        *puVar8 = uVar15;
        puVar8 = puVar8 + -4;
      } while (uVar3 != 0);
      puVar6 = puVar5;
      if (uVar4 == uVar9) goto LAB_006df1b4;
    }
    do {
      puVar12 = puVar12 + -1;
      puVar6 = puVar5 + -1;
      *puVar6 = *puVar12;
      puVar5 = puVar6;
    } while (puVar12 != puVar11);
  }
LAB_006df1b4:
  *param_1 = (ulong)puVar6;
  param_1[1] = (ulong)puVar14;
  param_1[2] = lVar2 + uVar7 * 4;
  if (puVar11 != (undefined4 *)0x0) {
    func_0x00bc3350(puVar11);
  }
LAB_006df1c8:
  param_1[1] = (ulong)puVar14;
  return;
}


