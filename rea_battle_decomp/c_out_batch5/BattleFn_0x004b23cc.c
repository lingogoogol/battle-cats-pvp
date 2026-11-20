// ELF VMA: 0x4b23cc
// Ghidra Addr: 0x005b23cc (ImageBase=0x100000)
// Size: 592 bytes


void BattleFn_0x004b23cc(long param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  long lVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  long lVar12;
  byte *pbVar13;
  byte bStack_c0;
  undefined4 uStack_bf;
  undefined3 uStack_bb;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  byte bStack_a8;
  undefined4 uStack_a7;
  undefined3 uStack_a3;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  ulong auStack_90 [2];
  undefined8 *puStack_80;
  byte abStack_78 [16];
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined3 uStack_5c;
  long lStack_58;
  
  pbVar13 = &bStack_c0;
  lVar7 = tpidr_el0;
  lStack_58 = *(long *)(lVar7 + 0x28);
  if (param_2 != 0) {
    bVar8 = false;
    goto LAB_005b25f0;
  }
  iVar9 = func_0x005abf1c(0,param_3);
  bVar8 = false;
  if (iVar9 < 2) goto LAB_005b25f0;
  func_0x005abf04(0,param_3);
  func_0x0062d750();
  func_0x00bc33f0(abStack_78);
  pbVar11 = (byte *)func_0x00bc3400(abStack_78,0,&UNK_00289d15);
  bVar6 = *pbVar11;
  uVar2 = *(undefined8 *)(pbVar11 + 8);
  uVar3 = *(undefined8 *)(pbVar11 + 0x10);
  pbVar11[8] = 0;
  pbVar11[9] = 0;
  pbVar11[10] = 0;
  pbVar11[0xb] = 0;
  pbVar11[0xc] = 0;
  pbVar11[0xd] = 0;
  pbVar11[0xe] = 0;
  pbVar11[0xf] = 0;
  pbVar11[0x10] = 0;
  pbVar11[0x11] = 0;
  pbVar11[0x12] = 0;
  pbVar11[0x13] = 0;
  pbVar11[0x14] = 0;
  pbVar11[0x15] = 0;
  pbVar11[0x16] = 0;
  pbVar11[0x17] = 0;
  uVar5 = *(undefined4 *)(pbVar11 + 1);
  uVar4 = *(undefined4 *)(pbVar11 + 4);
  pbVar11[0] = 0;
  pbVar11[1] = 0;
  pbVar11[2] = 0;
  pbVar11[3] = 0;
  pbVar11[4] = 0;
  pbVar11[5] = 0;
  pbVar11[6] = 0;
  pbVar11[7] = 0;
  uStack_60._0_3_ = (undefined3)uVar5;
  uStack_60._3_1_ = (undefined1)uVar4;
  uStack_5c = (undefined3)((uint)uVar4 >> 8);
  if ((abStack_78[0] & 1) != 0) {
    func_0x00bc3350(uStack_68);
  }
  lVar12 = func_0x007fd748();
  puStack_80 = (undefined8 *)func_0x00bc3330(0x30);
  *(undefined4 *)((long)puStack_80 + 0x1f) = 0x65707974;
  auStack_90[1] = 0x23;
  auStack_90[0] = 0x31;
  puStack_80[1] = 0x7469646e6f635f66;
  *puStack_80 = 0x615f656c74746162;
  puStack_80[3] = 0x745f6e6f69746375;
  puStack_80[2] = 0x646f72705f6e6f69;
  *(undefined1 *)((long)puStack_80 + 0x23) = 0;
  iVar9 = func_0x008e3f14(lVar12 + 0x1478,auStack_90,0);
  if ((auStack_90[0] & 1) != 0) {
    func_0x00bc3350(puStack_80);
  }
  iVar1 = *(int *)(param_1 + (long)param_3 * 4 + 0x108) + 1;
  if (iVar9 == 0) {
    lVar12 = func_0x007fd748();
    if ((bVar6 & 1) == 0) {
      uStack_a7 = uStack_60;
      uStack_a3 = uStack_5c;
      bStack_a8 = bVar6;
      uStack_a0 = uVar2;
      uStack_98 = uVar3;
    }
    else {
      func_0x0040a850(&bStack_a8,uVar3,uVar2);
    }
    iVar10 = func_0x008e3f14(lVar12 + 0x1478,&bStack_a8,2);
    iVar9 = 0;
    if (iVar10 != 0) {
      iVar9 = iVar1 / iVar10;
    }
    bVar8 = iVar1 == iVar9 * iVar10;
    if ((bStack_a8 & 1) != 0) {
      pbVar13 = &bStack_a8;
      goto LAB_005b25d0;
    }
  }
  else {
    lVar12 = func_0x007fd748();
    if ((bVar6 & 1) == 0) {
      uStack_bf = uStack_60;
      uStack_bb = uStack_5c;
      bStack_c0 = bVar6;
      uStack_b8 = uVar2;
      uStack_b0 = uVar3;
    }
    else {
      func_0x0040a850(&bStack_c0,uVar3,uVar2);
    }
    iVar9 = func_0x008e3f14(lVar12 + 0x1478,&bStack_c0,2);
    bVar8 = iVar1 == iVar9;
    if ((bStack_c0 & 1) != 0) {
LAB_005b25d0:
      func_0x00bc3350(*(undefined8 *)(pbVar13 + 0x10));
    }
  }
  if ((bVar6 & 1) != 0) {
    func_0x00bc3350(uVar3);
  }
LAB_005b25f0:
  if (*(long *)(lVar7 + 0x28) != lStack_58) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380(bVar8);
  }
  return;
}


