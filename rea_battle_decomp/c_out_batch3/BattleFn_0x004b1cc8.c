// ELF VMA: 0x004b1cc8 | Ghidra Addr: 0x005b1cc8 | BodySize: 412

uint BattleFn_0x004b1cc8(long param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  long *plVar15;
  undefined8 uVar16;
  
  lVar14 = func_0x007fd748();
  uVar10 = func_0x007ac230(0);
  plVar15 = (long *)func_0x00633678(lVar14 + 0x668,uVar10,0);
  if (plVar15 == (long *)0x0) {
    iVar11 = func_0x0057a024(5);
    bVar1 = *(byte *)(param_1 + 0xe);
    bVar2 = *(byte *)(param_1 + 0x11);
    bVar3 = *(byte *)(param_1 + 0x10);
    bVar4 = *(byte *)(param_1 + 0xd);
    bVar5 = *(byte *)(param_1 + 0x13);
    bVar6 = *(byte *)(param_1 + 0xf);
    bVar7 = *(byte *)(param_1 + 0x12);
    bVar8 = *(byte *)(param_1 + 0xc);
    lVar14 = func_0x007fd748();
    iVar13 = BattleFn_0x0091f9dc(&UNK_00290568 + lVar14,4);
    lVar14 = func_0x007fd748();
    iVar12 = BattleFn_0x007700d4(lVar14 + 0x4407e8,9,0xffffffff);
    uVar9 = (((int)((((uint)(bVar2 ^ bVar1) << 0x10 | (uint)(bVar3 ^ bVar6) << 0x18 |
                      (uint)(bVar7 ^ bVar4) << 8 | (uint)(bVar5 ^ bVar8)) * 5 + 10) *
                   (iVar11 * 10000 + 10000)) / 10 + iVar13) * (iVar12 + 100)) / 100;
    return uVar9 & ((int)uVar9 >> 0x1f ^ 0xffffffffU);
  }
  if ((int *)plVar15[1] == (int *)*plVar15) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00370c38();
  }
  iVar11 = *(int *)*plVar15;
  lVar14 = func_0x007fd748();
  uVar10 = func_0x007ac230(0);
  lVar14 = func_0x006335e0(lVar14 + 0x668,uVar10);
  if (*(int *)(lVar14 + 0x60) == 1) {
    uVar16 = 0xcf;
  }
  else {
    lVar14 = func_0x007fd748();
    uVar10 = func_0x007ac230(0);
    lVar14 = func_0x006335e0(lVar14 + 0x668,uVar10);
    if (*(int *)(lVar14 + 0x60) != 2) goto LAB_005b1e3c;
    uVar16 = 0xf7;
  }
  iVar13 = func_0x006e31e0(uVar16);
  iVar11 = iVar13 + iVar11;
LAB_005b1e3c:
  if (0x98967e < iVar11) {
    iVar11 = 9999999;
  }
  return iVar11 * 100;
}


