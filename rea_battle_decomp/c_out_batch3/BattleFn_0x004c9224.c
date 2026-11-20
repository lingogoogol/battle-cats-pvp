// ELF VMA: 0x004c9224 | Ghidra Addr: 0x005c9224 | BodySize: 23780

/* WARNING: Type propagation algorithm not settling */

void BattleFn_0x004c9224(long param_1,ulong param_2)

{
  uint *puVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  long lVar11;
  undefined6 uVar12;
  bool bVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  uint uVar25;
  uint uVar26;
  undefined8 uVar27;
  uint *puVar28;
  ulong uVar29;
  undefined8 *puVar30;
  long *plVar31;
  int *piVar32;
  undefined4 *puVar33;
  long lVar34;
  undefined8 *puVar35;
  uint *puVar36;
  undefined4 *puVar37;
  int extraout_var;
  undefined **ppuVar38;
  uint **ppuVar39;
  undefined8 *puVar40;
  uint *puVar41;
  undefined8 *puVar42;
  undefined8 *puVar43;
  uint *puVar44;
  uint *puVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  uint uVar48;
  undefined8 *puVar49;
  long *plVar50;
  uint *puVar51;
  long *plVar52;
  uint *puVar53;
  byte *pbVar54;
  int *piVar55;
  byte *pbVar56;
  ulong uVar57;
  byte *pbVar58;
  byte *pbVar59;
  byte *pbVar60;
  long lVar61;
  byte *pbVar62;
  long lVar63;
  ulong uVar64;
  long *plVar65;
  undefined *puVar66;
  byte *pbVar67;
  undefined *puVar68;
  byte *pbVar69;
  double dVar70;
  long lStack_240;
  long lStack_238;
  long lStack_230;
  undefined1 uStack_221;
  byte bStack_220;
  undefined2 uStack_21f;
  undefined1 uStack_21d;
  undefined8 uStack_210;
  ulong uStack_208;
  undefined *puStack_200;
  ulong uStack_1f8;
  byte bStack_1f0;
  undefined2 uStack_1ef;
  undefined1 uStack_1ed;
  undefined8 uStack_1e0;
  ulong uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  ulong auStack_1c0 [2];
  undefined8 uStack_1b0;
  undefined1 auStack_1a8 [8];
  undefined8 uStack_1a0;
  undefined *puStack_190;
  long lStack_188;
  ulong uStack_180;
  undefined **ppuStack_170;
  uint *puStack_160;
  uint *puStack_158;
  uint *puStack_150;
  byte bStack_148;
  uint **ppuStack_140;
  undefined8 uStack_138;
  ulong uStack_130;
  undefined *puStack_120;
  ulong uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  byte bStack_100;
  undefined7 uStack_ff;
  undefined1 uStack_f8;
  undefined2 uStack_f7;
  undefined1 uStack_f5;
  undefined8 uStack_f0;
  ulong uStack_e8;
  undefined *puStack_e0;
  ulong uStack_d8;
  undefined8 uStack_d0;
  undefined *puStack_c0;
  undefined4 auStack_b8 [2];
  undefined8 uStack_b0;
  byte bStack_a0;
  undefined1 uStack_9f;
  undefined2 uStack_9e;
  undefined1 uStack_9c;
  undefined1 uStack_9b;
  undefined1 uStack_9a;
  undefined1 uStack_99;
  byte bStack_98;
  undefined1 uStack_97;
  undefined2 uStack_96;
  short sStack_94;
  short sStack_92;
  byte bStack_90;
  undefined5 uStack_8f;
  undefined1 uStack_8a;
  undefined1 uStack_89;
  long lStack_88;
  
  lVar11 = tpidr_el0;
  lStack_88 = *(long *)(lVar11 + 0x28);
  auStack_1c0[0] = CONCAT44(auStack_1c0[0]._4_4_,0x642504);
  uVar14 = func_0x007ac230(0);
  func_0x00416d84(&bStack_a0,auStack_1c0,0,uVar14);
  ppuStack_140 = (uint **)CONCAT26(sStack_92,
                                   CONCAT24(sStack_94,
                                            CONCAT22(uStack_96,CONCAT11(uStack_97,bStack_98))));
  bStack_148 = bStack_a0;
  puStack_160 = (uint *)CONCAT17(puStack_160._7_1_,0x440000000000);
  uStack_138 = CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90)));
  puStack_160 = (uint *)CONCAT35(puStack_160._5_3_,0x4970614d0a);
  bStack_1f0 = 4;
  bStack_a0 = 0;
  uStack_9f = 0;
  uStack_9e = 0;
  uStack_9c = 0;
  uStack_9b = 0;
  uStack_9a = 0;
  uStack_99 = 0;
  bStack_98 = 0;
  uStack_97 = 0;
  uStack_96 = 0;
  sStack_94 = 0;
  sStack_92 = 0;
  bStack_90 = 0;
  uStack_8f = 0;
  uStack_8a = 0;
  uStack_89 = 0;
  uStack_1ef = 0x6425;
  uStack_1ed = 0;
  uVar14 = func_0x007ac5b8();
  func_0x00416d84(&uStack_1d8,&bStack_1f0,0,uVar14);
  uStack_110 = uStack_1d0;
  uStack_118 = uStack_1d8;
  uStack_21d = 0;
  uStack_1d8 = 0;
  uStack_1d0 = 0;
  uStack_130 = CONCAT17(uStack_130._7_1_,0x6c6576654c0a);
  uStack_108 = uStack_1c8;
  bStack_220 = 4;
  uStack_1c8 = 0;
  uStack_21f = 0x6425;
  uVar14 = func_0x007ac380();
  func_0x00416d84(&uStack_208,&bStack_220,0,uVar14);
  puStack_e0 = puStack_200;
  uStack_e8 = uStack_208;
  uStack_f5 = 0;
  bStack_100 = 0x14;
  uStack_f7 = 0x7865;
  uStack_208 = 0;
  puStack_200 = (undefined *)0x0;
  uStack_ff = 0x6e496567617453;
  uStack_f8 = 100;
  uStack_d8 = uStack_1f8;
  uStack_1f8 = 0;
  func_0x004fed18(auStack_1a8,&puStack_160,3,&uStack_221);
  if ((uStack_e8 & 1) != 0) {
    func_0x00bc3350(uStack_d8);
  }
  if ((bStack_100 & 1) != 0) {
    func_0x00bc3350(uStack_f0);
  }
  if ((uStack_118 & 1) != 0) {
    func_0x00bc3350(uStack_108);
  }
  if ((uStack_130 & 1) != 0) {
    func_0x00bc3350(puStack_120);
  }
  if ((bStack_148 & 1) != 0) {
    func_0x00bc3350(uStack_138);
  }
  if (((ulong)puStack_160 & 1) != 0) {
    func_0x00bc3350(puStack_150);
  }
  if ((uStack_208 & 1) != 0) {
    func_0x00bc3350(uStack_1f8);
  }
  if ((bStack_220 & 1) != 0) {
    func_0x00bc3350(uStack_210);
  }
  if ((uStack_1d8 & 1) != 0) {
    func_0x00bc3350(uStack_1c8);
  }
  if ((bStack_1f0 & 1) != 0) {
    func_0x00bc3350(uStack_1e0);
  }
  if ((bStack_a0 & 1) != 0) {
    func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
  }
  if ((auStack_1c0[0] & 1) != 0) {
    func_0x00bc3350(uStack_1b0);
  }
  func_0x00636320(0x47,auStack_1a8);
  piVar55 = (int *)(&UNK_003bb728 + param_1);
  plVar52 = (long *)(&UNK_00382598 + param_1);
  *(undefined2 *)(param_1 + 0x858) = 0;
  puVar45 = (uint *)(&UNK_0032c9f4 + param_1);
  puVar42 = (undefined8 *)(param_1 + 0x10a0);
  puVar53 = (uint *)(&UNK_00325c48 + param_1);
  puVar1 = (uint *)(param_1 + 0x83684);
  func_0x0058c04c(param_1 + 0x1098,*(undefined8 *)(param_1 + 0x10a0));
  iVar16 = 0;
  *(undefined8 **)(param_1 + 0x1098) = puVar42;
  *(undefined8 *)(param_1 + 0x10a8) = 0;
  *(undefined8 *)(param_1 + 0x10a0) = 0;
  do {
    uVar14 = func_0x006e31e0(iVar16);
    puVar49 = (undefined8 *)*puVar42;
    puVar40 = puVar42;
    while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
      while (puVar40 = puVar49, *(int *)((long)puVar40 + 0x1c) <= iVar16) {
        if (iVar16 <= *(int *)((long)puVar40 + 0x1c)) goto LAB_005c951c;
        puVar49 = (undefined8 *)puVar40[1];
        if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
          puVar43 = puVar40 + 1;
          goto LAB_005c957c;
        }
      }
      puVar49 = (undefined8 *)*puVar40;
    }
LAB_005c957c:
    puVar49 = (undefined8 *)func_0x00bc3330(0x28);
    puVar49[2] = puVar40;
    *(int *)((long)puVar49 + 0x1c) = iVar16;
    *(undefined4 *)(puVar49 + 4) = 0;
    *puVar49 = 0;
    puVar49[1] = 0;
    *puVar43 = puVar49;
    puVar40 = puVar49;
    if (**(long **)(param_1 + 0x1098) != 0) {
      *(long *)(param_1 + 0x1098) = **(long **)(param_1 + 0x1098);
      puVar40 = (undefined8 *)*puVar43;
    }
    func_0x0040a8c0(*(undefined8 *)(param_1 + 0x10a0),puVar40);
    *(long *)(param_1 + 0x10a8) = *(long *)(param_1 + 0x10a8) + 1;
    puVar40 = puVar49;
LAB_005c951c:
    iVar16 = iVar16 + 1;
    *(undefined4 *)(puVar40 + 4) = uVar14;
  } while (iVar16 != 0x113);
  for (iVar16 = 0; iVar15 = func_0x00650e5c(param_1 + 0x1538), iVar16 < iVar15; iVar16 = iVar16 + 1)
  {
    uVar14 = func_0x006519c8(param_1 + 0x1538,iVar16);
    iVar15 = iVar16 + 30000;
    puVar49 = (undefined8 *)*puVar42;
    puVar40 = puVar42;
    while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
      while (puVar40 = puVar49, *(int *)((long)puVar40 + 0x1c) <= iVar15) {
        if (iVar15 <= *(int *)((long)puVar40 + 0x1c)) goto LAB_005c95ec;
        puVar49 = (undefined8 *)puVar40[1];
        if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
          puVar43 = puVar40 + 1;
          goto LAB_005c9664;
        }
      }
      puVar49 = (undefined8 *)*puVar40;
    }
LAB_005c9664:
    puVar49 = (undefined8 *)func_0x00bc3330(0x28);
    puVar49[2] = puVar40;
    *(int *)((long)puVar49 + 0x1c) = iVar15;
    *(undefined4 *)(puVar49 + 4) = 0;
    *puVar49 = 0;
    puVar49[1] = 0;
    *puVar43 = puVar49;
    puVar40 = puVar49;
    if (**(long **)(param_1 + 0x1098) != 0) {
      *(long *)(param_1 + 0x1098) = **(long **)(param_1 + 0x1098);
      puVar40 = (undefined8 *)*puVar43;
    }
    func_0x0040a8c0(*(undefined8 *)(param_1 + 0x10a0),puVar40);
    *(long *)(param_1 + 0x10a8) = *(long *)(param_1 + 0x10a8) + 1;
    puVar40 = puVar49;
LAB_005c95ec:
    *(undefined4 *)(puVar40 + 4) = uVar14;
  }
  *(undefined4 *)(&UNK_00327f24 + param_1) = 0xffffffff;
  *(undefined8 *)(&UNK_00327f1c + param_1) = 0xffffffffffffffff;
  if ((param_2 & 1) == 0) {
    func_0x005ab128(2);
    uVar27 = func_0x0044c16c();
    func_0x0044e014(uVar27,0xffffffff);
    func_0x006ee0d0(param_1 + 0xe0);
  }
  iVar16 = func_0x007ac230(0);
  plVar50 = *(long **)(param_1 + 0x2618);
  if (plVar50 != (long *)0x0) {
    puVar44 = (uint *)(param_1 + 0x2618);
    do {
      if ((int)plVar50[4] <= iVar16) {
        if (iVar16 <= (int)plVar50[4]) {
          uVar17 = func_0x007ac230(0);
          puVar41 = *(uint **)puVar44;
          puVar51 = puVar44;
          puVar36 = puVar44;
          if (*(uint **)puVar44 == (uint *)0x0) goto LAB_005c9778;
          goto LAB_005c9754;
        }
        plVar50 = plVar50 + 1;
      }
      plVar50 = (long *)*plVar50;
    } while (plVar50 != (long *)0x0);
  }
LAB_005c9a00:
  uVar27 = func_0x0044c16c();
  func_0x0044e35c(uVar27,8,0);
  goto LAB_005c9a10;
  while (puVar49 = (undefined8 *)*puVar30, puVar40 = puVar30,
        (undefined8 *)*puVar30 != (undefined8 *)0x0) {
LAB_005cca4c:
    puVar30 = puVar49;
    puVar43 = puVar30;
    if (*(int *)(puVar30 + 4) <= iVar15) {
      if (iVar15 <= *(int *)(puVar30 + 4)) goto LAB_005ccb7c;
      puVar49 = (undefined8 *)puVar30[1];
      if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
        puVar40 = puVar30 + 1;
        break;
      }
      goto LAB_005cca4c;
    }
  }
LAB_005cca70:
  puVar30 = (undefined8 *)func_0x00bc3330(0x40);
  *(int *)(puVar30 + 4) = iVar15;
  puVar30[7] = 0;
  puVar30[6] = 0;
  puVar30[5] = puVar30 + 6;
  *puVar30 = 0;
  puVar30[1] = 0;
  puVar30[2] = puVar43;
  *puVar40 = puVar30;
  puVar49 = puVar30;
  if (**(long **)(&UNK_0032c640 + param_1) != 0) {
    *(long *)(&UNK_0032c640 + param_1) = **(long **)(&UNK_0032c640 + param_1);
    puVar49 = (undefined8 *)*puVar40;
  }
  func_0x0040a8c0(*(undefined8 *)(&UNK_0032c648 + param_1),puVar49);
  *(long *)(&UNK_0032c650 + param_1) = *(long *)(&UNK_0032c650 + param_1) + 1;
LAB_005ccb7c:
  puVar40 = puVar30 + 6;
  puVar49 = (undefined8 *)*puVar40;
  while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
    while (puVar40 = puVar49, *(int *)((long)puVar40 + 0x1c) <= (int)uVar5) {
      if ((int)uVar5 <= *(int *)((long)puVar40 + 0x1c)) goto LAB_005ccc20;
      puVar49 = (undefined8 *)puVar40[1];
      if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
        puVar43 = puVar40 + 1;
        goto LAB_005ccbc8;
      }
    }
    puVar49 = (undefined8 *)*puVar40;
  }
LAB_005ccbc8:
  puVar49 = (undefined8 *)func_0x00bc3330(0x28);
  *(undefined1 *)(puVar49 + 4) = 0;
  *puVar49 = 0;
  puVar49[1] = 0;
  *(uint *)((long)puVar49 + 0x1c) = uVar5;
  puVar49[2] = puVar40;
  *puVar43 = puVar49;
  puVar40 = puVar49;
  if (*(long *)puVar30[5] != 0) {
    puVar30[5] = *(long *)puVar30[5];
    puVar40 = (undefined8 *)*puVar43;
  }
  func_0x0040a8c0(puVar30[6],puVar40);
  puVar30[7] = puVar30[7] + 1;
  puVar40 = puVar49;
LAB_005ccc20:
  *(undefined1 *)(puVar40 + 4) = 1;
  iVar15 = *(int *)(&UNK_00327f0c + param_1);
  puVar49 = *(undefined8 **)(&UNK_0032c630 + param_1);
  puVar40 = (undefined8 *)(&UNK_0032c630 + param_1);
  while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
    while (puVar30 = puVar49, *(int *)(puVar30 + 4) <= iVar15) {
      if (iVar15 <= *(int *)(puVar30 + 4)) goto LAB_005cccdc;
      puVar49 = (undefined8 *)puVar30[1];
      if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
        puVar40 = puVar30 + 1;
        puVar43 = puVar30;
        goto LAB_005ccc74;
      }
    }
    puVar40 = puVar30;
    puVar49 = (undefined8 *)*puVar30;
  }
LAB_005ccc74:
  puVar30 = (undefined8 *)func_0x00bc3330(0x40);
  *(int *)(puVar30 + 4) = iVar15;
  puVar30[7] = 0;
  puVar30[6] = 0;
  puVar30[5] = puVar30 + 6;
  *puVar30 = 0;
  puVar30[1] = 0;
  puVar30[2] = puVar43;
  *puVar40 = puVar30;
  lVar63 = **(long **)(&UNK_0032c628 + param_1);
  puVar49 = puVar30;
  if (lVar63 != 0) {
    *(long *)(&UNK_0032c628 + param_1) = lVar63;
    puVar49 = (undefined8 *)*puVar40;
  }
  func_0x0040a8c0(*(undefined8 *)(&UNK_0032c630 + param_1),puVar49);
  *(long *)(&UNK_0032c638 + param_1) = *(long *)(&UNK_0032c638 + param_1) + 1;
LAB_005cccdc:
  puVar40 = puVar30 + 6;
  puVar49 = (undefined8 *)*puVar40;
  while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
    while (puVar40 = puVar49, *(int *)((long)puVar40 + 0x1c) <= (int)uVar5) {
      if ((int)uVar5 <= *(int *)((long)puVar40 + 0x1c)) goto LAB_005ccd80;
      puVar49 = (undefined8 *)puVar40[1];
      if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
        puVar43 = puVar40 + 1;
        goto LAB_005ccd28;
      }
    }
    puVar49 = (undefined8 *)*puVar40;
  }
LAB_005ccd28:
  puVar49 = (undefined8 *)func_0x00bc3330(0x28);
  *(undefined1 *)(puVar49 + 4) = 0;
  *puVar49 = 0;
  puVar49[1] = 0;
  *(uint *)((long)puVar49 + 0x1c) = uVar5;
  puVar49[2] = puVar40;
  *puVar43 = puVar49;
  puVar40 = puVar49;
  if (*(long *)puVar30[5] != 0) {
    puVar30[5] = *(long *)puVar30[5];
    puVar40 = (undefined8 *)*puVar43;
  }
  func_0x0040a8c0(puVar30[6],puVar40);
  puVar30[7] = puVar30[7] + 1;
  puVar40 = puVar49;
LAB_005ccd80:
  *(undefined1 *)(puVar40 + 4) = 0;
  func_0x00a0b124(0x1f,*(undefined4 *)(&UNK_00327f0c + param_1),uVar5,0,0);
LAB_005ccd9c:
  uVar25 = func_0x006d3c94(param_1,*(int *)(&UNK_003bb798 + param_1) + 6,0);
  *(uint *)(&UNK_003bb79c + param_1) = uVar25;
  if (uVar25 != 1) {
    iVar15 = *(int *)(&UNK_00327f0c + param_1);
    if ((iVar15 == 3) || ((&UNK_0032c658)[param_1] == '\0')) {
      iVar15 = *(int *)(&UNK_003bb798 + param_1);
      puStack_160 = (uint *)func_0x00bc3330(0x10);
      puStack_158 = puStack_160 + 4;
      *puStack_160 = 0;
      puStack_160[1] = iVar15 + 6;
      puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
      puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
      puStack_160[2] = 0;
      puStack_160[3] = uVar25;
      puStack_150 = puStack_158;
      if (puVar40 < puVar49) {
        *puVar40 = 0;
        puVar40[1] = 0;
        puVar40[2] = 0;
        puVar40[1] = puStack_158;
        *puVar40 = puStack_160;
        puVar40[2] = puStack_158;
        *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
      }
      else {
        uVar27 = func_0x005df9b8(puVar42,&puStack_160);
        *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
        if (puStack_160 != (uint *)0x0) {
          puStack_158 = puStack_160;
          func_0x00bc3350();
        }
      }
      iVar15 = func_0x007acdd4(uVar5,0);
      if ((iVar15 == 1) && (*(int *)(&UNK_003bb79c + param_1) == 2)) {
        func_0x007accc4(uVar5,0);
        uVar14 = func_0x006efca4();
        func_0x00a0b124(0x5e,uVar14,0,0,0);
      }
    }
    else {
      uVar25 = 1;
      if (6 < iVar15) {
        uVar25 = 2;
      }
      uVar20 = 0;
      if (2 < iVar15) {
        uVar20 = uVar25;
      }
      puStack_160 = (uint *)func_0x00bc3330(0xc);
      *puStack_160 = 3;
      puStack_160[1] = uVar20;
      puStack_158 = puStack_160 + 3;
      puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
      puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
      puStack_160[2] = uVar5;
      puStack_150 = puStack_158;
      if (puVar40 < puVar49) {
        *puVar40 = 0;
        puVar40[1] = 0;
        puVar40[2] = 0;
        puVar40[1] = puStack_158;
        *puVar40 = puStack_160;
        puVar40[2] = puStack_158;
        *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
      }
      else {
        uVar27 = func_0x005df9b8(puVar42,&puStack_160);
        *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
        if (puStack_160 != (uint *)0x0) {
          puStack_158 = puStack_160;
          func_0x00bc3350();
        }
      }
      if ((uVar64 & 1) == 0) {
        uVar14 = *(undefined4 *)(&UNK_00327f0c + param_1);
        uVar18 = func_0x00a206ac(uVar14,uVar5);
        uVar64 = func_0x00a20824(uVar14,uVar18);
        if ((uVar64 & 1) != 0) {
          uVar25 = func_0x00a206ac(*(undefined4 *)(&UNK_00327f0c + param_1),uVar5);
          puStack_160 = (uint *)func_0x00bc3330(0xc);
          puStack_158 = puStack_160 + 3;
          *puStack_160 = 4;
          puStack_160[1] = uVar20;
          puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
          puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
          puStack_160[2] = uVar25;
          puStack_150 = puStack_158;
          if (puVar40 < puVar49) {
            *puVar40 = 0;
            puVar40[1] = 0;
            puVar40[2] = 0;
            puVar40[1] = puStack_158;
            *puVar40 = puStack_160;
            puVar40[2] = puStack_158;
            *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
          }
          else {
            uVar27 = func_0x005df9b8(puVar42,&puStack_160);
            *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
            if (puStack_160 != (uint *)0x0) {
              puStack_158 = puStack_160;
              func_0x00bc3350();
            }
          }
          if (uVar5 == 0x2f) {
            bStack_a0 = 5;
            uStack_9f = 0;
            uStack_9e = 0;
            uStack_9c = (undefined1)uVar20;
            uStack_9b = 0;
            uStack_9a = 0;
            uStack_99 = 0;
            func_0x005cf6c0(&puStack_160,&bStack_a0,2);
            func_0x005cf664(puVar42,&puStack_160);
joined_r0x005cd43c:
            if (puStack_160 != (uint *)0x0) {
              puStack_158 = puStack_160;
              func_0x00bc3350();
            }
          }
        }
      }
    }
  }
LAB_005ccdcc:
  *(undefined4 *)(&UNK_0032c9fc + param_1) = 1;
  goto LAB_005ccdd0;
code_r0x005cdf1c:
  uVar64 = uVar64 + 4;
  if (((long)puStack_158 - (long)puStack_160 & 0x3fffffffcU) == uVar64) goto LAB_005ce0e4;
  goto LAB_005cdf14;
  while (puVar41 = *(uint **)puVar28, puVar36 = puVar28, *(uint **)puVar28 != (uint *)0x0) {
LAB_005c9754:
    puVar28 = puVar41;
    puVar51 = puVar28;
    if ((int)puVar28[8] <= (int)uVar17) {
      if ((int)uVar17 <= (int)puVar28[8]) goto LAB_005c98d8;
      puVar41 = *(uint **)(puVar28 + 2);
      if (*(uint **)(puVar28 + 2) == (uint *)0x0) {
        puVar36 = puVar28 + 2;
        break;
      }
      goto LAB_005c9754;
    }
  }
LAB_005c9778:
  puVar28 = (uint *)func_0x00bc3330(0x160);
  puVar28[8] = uVar17;
  puVar28[0x56] = 0;
  puVar28[0x57] = 0;
  puVar28[0] = 0;
  puVar28[1] = 0;
  puVar28[2] = 0;
  puVar28[3] = 0;
  puVar28[0x44] = 0;
  puVar28[0x45] = 0;
  puVar28[0x42] = 0;
  puVar28[0x43] = 0;
  puVar28[0x48] = 0;
  puVar28[0x49] = 0;
  puVar28[0x46] = 0;
  puVar28[0x47] = 0;
  puVar28[0x10] = 0;
  puVar28[0x11] = 0;
  puVar28[0xe] = 0;
  puVar28[0xf] = 0;
  puVar28[0x14] = 0;
  puVar28[0x15] = 0;
  puVar28[0x12] = 0;
  puVar28[0x13] = 0;
  puVar28[0x18] = 0;
  puVar28[0x19] = 0;
  puVar28[0x16] = 0;
  puVar28[0x17] = 0;
  puVar28[0x1c] = 0;
  puVar28[0x1d] = 0;
  puVar28[0x1a] = 0;
  puVar28[0x1b] = 0;
  puVar28[0x20] = 0;
  puVar28[0x21] = 0;
  puVar28[0x1e] = 0;
  puVar28[0x1f] = 0;
  puVar28[0x24] = 0;
  puVar28[0x25] = 0;
  puVar28[0x22] = 0;
  puVar28[0x23] = 0;
  puVar28[0x28] = 0;
  puVar28[0x29] = 0;
  puVar28[0x26] = 0;
  puVar28[0x27] = 0;
  puVar28[0x2c] = 0;
  puVar28[0x2d] = 0;
  puVar28[0x2a] = 0;
  puVar28[0x2b] = 0;
  puVar28[0x30] = 0;
  puVar28[0x31] = 0;
  puVar28[0x2e] = 0;
  puVar28[0x2f] = 0;
  puVar28[0x34] = 0;
  puVar28[0x35] = 0;
  puVar28[0x32] = 0;
  puVar28[0x33] = 0;
  puVar28[0x38] = 0;
  puVar28[0x39] = 0;
  puVar28[0x36] = 0;
  puVar28[0x37] = 0;
  puVar28[0x3c] = 0;
  puVar28[0x3d] = 0;
  puVar28[0x3a] = 0;
  puVar28[0x3b] = 0;
  puVar28[0x40] = 0;
  puVar28[0x41] = 0;
  puVar28[0x3e] = 0;
  puVar28[0x3f] = 0;
  puVar28[0xc] = 0;
  puVar28[0xd] = 0;
  puVar28[10] = 0;
  puVar28[0xb] = 0;
  puVar28[0x4c] = 0;
  puVar28[0x4d] = 0;
  puVar28[0x4a] = 0;
  puVar28[0x4b] = 0;
  puVar28[0x50] = 0;
  puVar28[0x51] = 0;
  puVar28[0x4e] = 0;
  puVar28[0x4f] = 0;
  puVar28[0x54] = 0;
  puVar28[0x55] = 0;
  puVar28[0x52] = 0;
  puVar28[0x53] = 0;
  *(uint **)(puVar28 + 4) = puVar51;
  *(uint **)puVar36 = puVar28;
  puVar41 = puVar28;
  if (**(long **)(param_1 + 0x2610) != 0) {
    *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
    puVar41 = *(uint **)puVar36;
  }
  func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar41);
  *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
LAB_005c98d8:
  if (*(long *)(puVar28 + 0x4a) == *(long *)(puVar28 + 0x48)) goto LAB_005c9a00;
  iVar16 = func_0x007ac230(0);
  puVar51 = *(uint **)puVar44;
  puVar41 = puVar44;
  while (puVar36 = puVar41, puVar51 != (uint *)0x0) {
    while (puVar41 = puVar51, (int)puVar41[8] <= iVar16) {
      if (iVar16 <= (int)puVar41[8]) {
        uVar17 = puVar41[0x45];
        goto joined_r0x005ca2d0;
      }
      puVar51 = *(uint **)(puVar41 + 2);
      if (*(uint **)(puVar41 + 2) == (uint *)0x0) {
        puVar36 = puVar41 + 2;
        goto LAB_005c9934;
      }
    }
    puVar51 = *(uint **)puVar41;
  }
LAB_005c9934:
  puVar40 = (undefined8 *)func_0x00bc3330(0x160);
  *(int *)(puVar40 + 4) = iVar16;
  puVar40[0x2b] = 0;
  *puVar40 = 0;
  puVar40[1] = 0;
  puVar40[0x22] = 0;
  puVar40[0x21] = 0;
  puVar40[0x24] = 0;
  puVar40[0x23] = 0;
  puVar40[8] = 0;
  puVar40[7] = 0;
  puVar40[10] = 0;
  puVar40[9] = 0;
  puVar40[0xc] = 0;
  puVar40[0xb] = 0;
  puVar40[0xe] = 0;
  puVar40[0xd] = 0;
  puVar40[0x10] = 0;
  puVar40[0xf] = 0;
  puVar40[0x12] = 0;
  puVar40[0x11] = 0;
  puVar40[0x14] = 0;
  puVar40[0x13] = 0;
  puVar40[0x16] = 0;
  puVar40[0x15] = 0;
  puVar40[0x18] = 0;
  puVar40[0x17] = 0;
  puVar40[0x1a] = 0;
  puVar40[0x19] = 0;
  puVar40[0x1c] = 0;
  puVar40[0x1b] = 0;
  puVar40[0x1e] = 0;
  puVar40[0x1d] = 0;
  puVar40[0x20] = 0;
  puVar40[0x1f] = 0;
  puVar40[6] = 0;
  puVar40[5] = 0;
  puVar40[0x26] = 0;
  puVar40[0x25] = 0;
  puVar40[0x28] = 0;
  puVar40[0x27] = 0;
  puVar40[0x2a] = 0;
  puVar40[0x29] = 0;
  puVar40[2] = puVar41;
  *(undefined8 **)puVar36 = puVar40;
  puVar42 = puVar40;
  if (**(long **)(param_1 + 0x2610) != 0) {
    *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
    puVar42 = *(undefined8 **)puVar36;
  }
  func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar42);
  *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
  uVar17 = *(uint *)((long)puVar40 + 0x114);
joined_r0x005ca2d0:
  if (uVar17 == 0) {
    uVar17 = func_0x007ac230(0);
    puVar51 = *(uint **)puVar44;
    puVar41 = puVar44;
    while (puVar36 = puVar41, puVar51 != (uint *)0x0) {
      while (puVar28 = puVar51, puVar41 = puVar28, (int)puVar28[8] <= (int)uVar17) {
        if ((int)uVar17 <= (int)puVar28[8]) goto LAB_005cc890;
        puVar51 = *(uint **)(puVar28 + 2);
        if (*(uint **)(puVar28 + 2) == (uint *)0x0) {
          puVar36 = puVar28 + 2;
          goto LAB_005ca324;
        }
      }
      puVar51 = *(uint **)puVar28;
    }
LAB_005ca324:
    puVar28 = (uint *)func_0x00bc3330(0x160);
    puVar28[8] = uVar17;
    puVar28[0x56] = 0;
    puVar28[0x57] = 0;
    puVar28[0] = 0;
    puVar28[1] = 0;
    puVar28[2] = 0;
    puVar28[3] = 0;
    puVar28[0x44] = 0;
    puVar28[0x45] = 0;
    puVar28[0x42] = 0;
    puVar28[0x43] = 0;
    puVar28[0x48] = 0;
    puVar28[0x49] = 0;
    puVar28[0x46] = 0;
    puVar28[0x47] = 0;
    puVar28[0x10] = 0;
    puVar28[0x11] = 0;
    puVar28[0xe] = 0;
    puVar28[0xf] = 0;
    puVar28[0x14] = 0;
    puVar28[0x15] = 0;
    puVar28[0x12] = 0;
    puVar28[0x13] = 0;
    puVar28[0x18] = 0;
    puVar28[0x19] = 0;
    puVar28[0x16] = 0;
    puVar28[0x17] = 0;
    puVar28[0x1c] = 0;
    puVar28[0x1d] = 0;
    puVar28[0x1a] = 0;
    puVar28[0x1b] = 0;
    puVar28[0x20] = 0;
    puVar28[0x21] = 0;
    puVar28[0x1e] = 0;
    puVar28[0x1f] = 0;
    puVar28[0x24] = 0;
    puVar28[0x25] = 0;
    puVar28[0x22] = 0;
    puVar28[0x23] = 0;
    puVar28[0x28] = 0;
    puVar28[0x29] = 0;
    puVar28[0x26] = 0;
    puVar28[0x27] = 0;
    puVar28[0x2c] = 0;
    puVar28[0x2d] = 0;
    puVar28[0x2a] = 0;
    puVar28[0x2b] = 0;
    puVar28[0x30] = 0;
    puVar28[0x31] = 0;
    puVar28[0x2e] = 0;
    puVar28[0x2f] = 0;
    puVar28[0x34] = 0;
    puVar28[0x35] = 0;
    puVar28[0x32] = 0;
    puVar28[0x33] = 0;
    puVar28[0x38] = 0;
    puVar28[0x39] = 0;
    puVar28[0x36] = 0;
    puVar28[0x37] = 0;
    puVar28[0x3c] = 0;
    puVar28[0x3d] = 0;
    puVar28[0x3a] = 0;
    puVar28[0x3b] = 0;
    puVar28[0x40] = 0;
    puVar28[0x41] = 0;
    puVar28[0x3e] = 0;
    puVar28[0x3f] = 0;
    puVar28[0xc] = 0;
    puVar28[0xd] = 0;
    puVar28[10] = 0;
    puVar28[0xb] = 0;
    puVar28[0x4c] = 0;
    puVar28[0x4d] = 0;
    puVar28[0x4a] = 0;
    puVar28[0x4b] = 0;
    puVar28[0x50] = 0;
    puVar28[0x51] = 0;
    puVar28[0x4e] = 0;
    puVar28[0x4f] = 0;
    puVar28[0x54] = 0;
    puVar28[0x55] = 0;
    puVar28[0x52] = 0;
    puVar28[0x53] = 0;
    *(uint **)(puVar28 + 4) = puVar41;
    *(uint **)puVar36 = puVar28;
    puVar41 = puVar28;
    if (**(long **)(param_1 + 0x2610) != 0) {
      *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
      puVar41 = *(uint **)puVar36;
    }
    func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar41);
    *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
LAB_005cc890:
    uVar17 = func_0x007ac230(0);
    puVar41 = *(uint **)puVar44;
    while (puVar51 = puVar44, puVar41 != (uint *)0x0) {
      while (puVar36 = puVar41, puVar44 = puVar36, (int)puVar36[8] <= (int)uVar17) {
        if ((int)uVar17 <= (int)puVar36[8]) goto LAB_005cc988;
        puVar41 = *(uint **)(puVar36 + 2);
        if (*(uint **)(puVar36 + 2) == (uint *)0x0) {
          puVar51 = puVar36 + 2;
          goto LAB_005cc8dc;
        }
      }
      puVar41 = *(uint **)puVar36;
    }
LAB_005cc8dc:
    puVar36 = (uint *)func_0x00bc3330(0x160);
    puVar36[8] = uVar17;
    puVar36[0x56] = 0;
    puVar36[0x57] = 0;
    puVar36[0] = 0;
    puVar36[1] = 0;
    puVar36[2] = 0;
    puVar36[3] = 0;
    puVar36[0x44] = 0;
    puVar36[0x45] = 0;
    puVar36[0x42] = 0;
    puVar36[0x43] = 0;
    puVar36[0x48] = 0;
    puVar36[0x49] = 0;
    puVar36[0x46] = 0;
    puVar36[0x47] = 0;
    puVar36[0x10] = 0;
    puVar36[0x11] = 0;
    puVar36[0xe] = 0;
    puVar36[0xf] = 0;
    puVar36[0x14] = 0;
    puVar36[0x15] = 0;
    puVar36[0x12] = 0;
    puVar36[0x13] = 0;
    puVar36[0x18] = 0;
    puVar36[0x19] = 0;
    puVar36[0x16] = 0;
    puVar36[0x17] = 0;
    puVar36[0x1c] = 0;
    puVar36[0x1d] = 0;
    puVar36[0x1a] = 0;
    puVar36[0x1b] = 0;
    puVar36[0x20] = 0;
    puVar36[0x21] = 0;
    puVar36[0x1e] = 0;
    puVar36[0x1f] = 0;
    puVar36[0x24] = 0;
    puVar36[0x25] = 0;
    puVar36[0x22] = 0;
    puVar36[0x23] = 0;
    puVar36[0x28] = 0;
    puVar36[0x29] = 0;
    puVar36[0x26] = 0;
    puVar36[0x27] = 0;
    puVar36[0x2c] = 0;
    puVar36[0x2d] = 0;
    puVar36[0x2a] = 0;
    puVar36[0x2b] = 0;
    puVar36[0x30] = 0;
    puVar36[0x31] = 0;
    puVar36[0x2e] = 0;
    puVar36[0x2f] = 0;
    puVar36[0x34] = 0;
    puVar36[0x35] = 0;
    puVar36[0x32] = 0;
    puVar36[0x33] = 0;
    puVar36[0x38] = 0;
    puVar36[0x39] = 0;
    puVar36[0x36] = 0;
    puVar36[0x37] = 0;
    puVar36[0x3c] = 0;
    puVar36[0x3d] = 0;
    puVar36[0x3a] = 0;
    puVar36[0x3b] = 0;
    puVar36[0x40] = 0;
    puVar36[0x41] = 0;
    puVar36[0x3e] = 0;
    puVar36[0x3f] = 0;
    puVar36[0xc] = 0;
    puVar36[0xd] = 0;
    puVar36[10] = 0;
    puVar36[0xb] = 0;
    puVar36[0x4c] = 0;
    puVar36[0x4d] = 0;
    puVar36[0x4a] = 0;
    puVar36[0x4b] = 0;
    puVar36[0x50] = 0;
    puVar36[0x51] = 0;
    puVar36[0x4e] = 0;
    puVar36[0x4f] = 0;
    puVar36[0x54] = 0;
    puVar36[0x55] = 0;
    puVar36[0x52] = 0;
    puVar36[0x53] = 0;
    *(uint **)(puVar36 + 4) = puVar44;
    *(uint **)puVar51 = puVar36;
    puVar44 = puVar36;
    if (**(long **)(param_1 + 0x2610) != 0) {
      *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
      puVar44 = *(uint **)puVar51;
    }
    func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar44);
    *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
LAB_005cc988:
    iVar16 = func_0x0043ea60((ulong)(*(long *)(puVar36 + 0x4a) - *(long *)(puVar36 + 0x48)) >> 2);
    if ((ulong)(*(long *)(puVar28 + 0x4a) - *(long *)(puVar28 + 0x48) >> 2) <= (ulong)(long)iVar16)
    {
LAB_005ceee8:
      if (*(long *)(lVar11 + 0x28) == lStack_88) {
                    /* WARNING: Subroutine does not return */
        NoRet_0x00370c38(puVar28 + 0x48);
      }
      goto LAB_005cf480;
    }
    iVar16 = *(int *)(*(long *)(puVar28 + 0x48) + (long)iVar16 * 4);
    if (iVar16 != -1) {
      uVar27 = func_0x0044c16c();
      func_0x0044e35c(uVar27,iVar16,0);
    }
  }
  else {
    uVar17 = func_0x007ac230(0);
    puVar51 = *(uint **)puVar44;
    puVar41 = puVar44;
    while (puVar36 = puVar41, puVar51 != (uint *)0x0) {
      while (puVar28 = puVar51, puVar41 = puVar28, (int)puVar28[8] <= (int)uVar17) {
        if ((int)uVar17 <= (int)puVar28[8]) goto LAB_005cc62c;
        puVar51 = *(uint **)(puVar28 + 2);
        if (*(uint **)(puVar28 + 2) == (uint *)0x0) {
          puVar36 = puVar28 + 2;
          goto LAB_005ca070;
        }
      }
      puVar51 = *(uint **)puVar28;
    }
LAB_005ca070:
    puVar28 = (uint *)func_0x00bc3330(0x160);
    puVar28[8] = uVar17;
    puVar28[0x56] = 0;
    puVar28[0x57] = 0;
    puVar28[0] = 0;
    puVar28[1] = 0;
    puVar28[2] = 0;
    puVar28[3] = 0;
    puVar28[0x44] = 0;
    puVar28[0x45] = 0;
    puVar28[0x42] = 0;
    puVar28[0x43] = 0;
    puVar28[0x48] = 0;
    puVar28[0x49] = 0;
    puVar28[0x46] = 0;
    puVar28[0x47] = 0;
    puVar28[0x10] = 0;
    puVar28[0x11] = 0;
    puVar28[0xe] = 0;
    puVar28[0xf] = 0;
    puVar28[0x14] = 0;
    puVar28[0x15] = 0;
    puVar28[0x12] = 0;
    puVar28[0x13] = 0;
    puVar28[0x18] = 0;
    puVar28[0x19] = 0;
    puVar28[0x16] = 0;
    puVar28[0x17] = 0;
    puVar28[0x1c] = 0;
    puVar28[0x1d] = 0;
    puVar28[0x1a] = 0;
    puVar28[0x1b] = 0;
    puVar28[0x20] = 0;
    puVar28[0x21] = 0;
    puVar28[0x1e] = 0;
    puVar28[0x1f] = 0;
    puVar28[0x24] = 0;
    puVar28[0x25] = 0;
    puVar28[0x22] = 0;
    puVar28[0x23] = 0;
    puVar28[0x28] = 0;
    puVar28[0x29] = 0;
    puVar28[0x26] = 0;
    puVar28[0x27] = 0;
    puVar28[0x2c] = 0;
    puVar28[0x2d] = 0;
    puVar28[0x2a] = 0;
    puVar28[0x2b] = 0;
    puVar28[0x30] = 0;
    puVar28[0x31] = 0;
    puVar28[0x2e] = 0;
    puVar28[0x2f] = 0;
    puVar28[0x34] = 0;
    puVar28[0x35] = 0;
    puVar28[0x32] = 0;
    puVar28[0x33] = 0;
    puVar28[0x38] = 0;
    puVar28[0x39] = 0;
    puVar28[0x36] = 0;
    puVar28[0x37] = 0;
    puVar28[0x3c] = 0;
    puVar28[0x3d] = 0;
    puVar28[0x3a] = 0;
    puVar28[0x3b] = 0;
    puVar28[0x40] = 0;
    puVar28[0x41] = 0;
    puVar28[0x3e] = 0;
    puVar28[0x3f] = 0;
    puVar28[0xc] = 0;
    puVar28[0xd] = 0;
    puVar28[10] = 0;
    puVar28[0xb] = 0;
    puVar28[0x4c] = 0;
    puVar28[0x4d] = 0;
    puVar28[0x4a] = 0;
    puVar28[0x4b] = 0;
    puVar28[0x50] = 0;
    puVar28[0x51] = 0;
    puVar28[0x4e] = 0;
    puVar28[0x4f] = 0;
    puVar28[0x54] = 0;
    puVar28[0x55] = 0;
    puVar28[0x52] = 0;
    puVar28[0x53] = 0;
    *(uint **)(puVar28 + 4) = puVar41;
    *(uint **)puVar36 = puVar28;
    puVar41 = puVar28;
    if (**(long **)(param_1 + 0x2610) != 0) {
      *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
      puVar41 = *(uint **)puVar36;
    }
    func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar41);
    *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
LAB_005cc62c:
    if (puVar28[0x45] == 1) {
      uVar17 = func_0x007ac230(0);
      puVar41 = *(uint **)puVar44;
      while (puVar51 = puVar44, puVar41 != (uint *)0x0) {
        while (puVar36 = puVar41, puVar44 = puVar36, (int)puVar36[8] <= (int)uVar17) {
          if ((int)uVar17 <= (int)puVar36[8]) goto LAB_005cc9d0;
          puVar41 = *(uint **)(puVar36 + 2);
          if (*(uint **)(puVar36 + 2) == (uint *)0x0) {
            puVar51 = puVar36 + 2;
            goto LAB_005cc684;
          }
        }
        puVar41 = *(uint **)puVar36;
      }
LAB_005cc684:
      puVar36 = (uint *)func_0x00bc3330(0x160);
      puVar36[8] = uVar17;
      puVar36[0x56] = 0;
      puVar36[0x57] = 0;
      puVar36[0] = 0;
      puVar36[1] = 0;
      puVar36[2] = 0;
      puVar36[3] = 0;
      puVar36[0x44] = 0;
      puVar36[0x45] = 0;
      puVar36[0x42] = 0;
      puVar36[0x43] = 0;
      puVar36[0x48] = 0;
      puVar36[0x49] = 0;
      puVar36[0x46] = 0;
      puVar36[0x47] = 0;
      puVar36[0x10] = 0;
      puVar36[0x11] = 0;
      puVar36[0xe] = 0;
      puVar36[0xf] = 0;
      puVar36[0x14] = 0;
      puVar36[0x15] = 0;
      puVar36[0x12] = 0;
      puVar36[0x13] = 0;
      puVar36[0x18] = 0;
      puVar36[0x19] = 0;
      puVar36[0x16] = 0;
      puVar36[0x17] = 0;
      puVar36[0x1c] = 0;
      puVar36[0x1d] = 0;
      puVar36[0x1a] = 0;
      puVar36[0x1b] = 0;
      puVar36[0x20] = 0;
      puVar36[0x21] = 0;
      puVar36[0x1e] = 0;
      puVar36[0x1f] = 0;
      puVar36[0x24] = 0;
      puVar36[0x25] = 0;
      puVar36[0x22] = 0;
      puVar36[0x23] = 0;
      puVar36[0x28] = 0;
      puVar36[0x29] = 0;
      puVar36[0x26] = 0;
      puVar36[0x27] = 0;
      puVar36[0x2c] = 0;
      puVar36[0x2d] = 0;
      puVar36[0x2a] = 0;
      puVar36[0x2b] = 0;
      puVar36[0x30] = 0;
      puVar36[0x31] = 0;
      puVar36[0x2e] = 0;
      puVar36[0x2f] = 0;
      puVar36[0x34] = 0;
      puVar36[0x35] = 0;
      puVar36[0x32] = 0;
      puVar36[0x33] = 0;
      puVar36[0x38] = 0;
      puVar36[0x39] = 0;
      puVar36[0x36] = 0;
      puVar36[0x37] = 0;
      puVar36[0x3c] = 0;
      puVar36[0x3d] = 0;
      puVar36[0x3a] = 0;
      puVar36[0x3b] = 0;
      puVar36[0x40] = 0;
      puVar36[0x41] = 0;
      puVar36[0x3e] = 0;
      puVar36[0x3f] = 0;
      puVar36[0xc] = 0;
      puVar36[0xd] = 0;
      puVar36[10] = 0;
      puVar36[0xb] = 0;
      puVar36[0x4c] = 0;
      puVar36[0x4d] = 0;
      puVar36[0x4a] = 0;
      puVar36[0x4b] = 0;
      puVar36[0x50] = 0;
      puVar36[0x51] = 0;
      puVar36[0x4e] = 0;
      puVar36[0x4f] = 0;
      puVar36[0x54] = 0;
      puVar36[0x55] = 0;
      puVar36[0x52] = 0;
      puVar36[0x53] = 0;
      *(uint **)(puVar36 + 4) = puVar44;
      *(uint **)puVar51 = puVar36;
      puVar44 = puVar36;
      if (**(long **)(param_1 + 0x2610) != 0) {
        *(long *)(param_1 + 0x2610) = **(long **)(param_1 + 0x2610);
        puVar44 = *(uint **)puVar51;
      }
      func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2618),puVar44);
      *(long *)(param_1 + 0x2620) = *(long *)(param_1 + 0x2620) + 1;
LAB_005cc9d0:
      piVar4 = *(int **)(puVar36 + 0x4a);
      for (piVar32 = *(int **)(puVar36 + 0x48); piVar32 != piVar4; piVar32 = piVar32 + 1) {
        iVar16 = *piVar32;
        if (iVar16 != -1) {
          uVar27 = func_0x0044c16c();
          func_0x0044e35c(uVar27,iVar16,0);
        }
      }
    }
  }
LAB_005c9a10:
  puVar42 = (undefined8 *)(&UNK_003825a0 + param_1);
  uVar64 = 1;
  do {
    if (((*(int *)(param_1 + uVar64 * 1000 + 0x90040) != 0) &&
        (lVar61 = param_1 + uVar64 * 1000, *(int *)(lVar61 + 0x90044) != 4)) &&
       (uVar29 = func_0x005aad10(), uVar64 != (uVar29 & 0xffffffff))) {
      *(undefined8 *)(lVar61 + 0x90044) = 4;
      *(undefined4 *)(param_1 + uVar64 * 1000 + 0x90060) = 0;
      iVar16 = func_0x00a58934(1,uVar64 & 0xffffffff);
      puVar49 = (undefined8 *)*puVar42;
      puVar40 = puVar42;
      if (puVar49 != (undefined8 *)0x0) {
        do {
          puVar43 = puVar49 + 1;
          if (iVar16 <= *(int *)((long)puVar49 + 0x1c)) {
            puVar40 = puVar49;
            puVar43 = puVar49;
          }
          puVar49 = (undefined8 *)*puVar43;
        } while (puVar49 != (undefined8 *)0x0);
        if (puVar40 != puVar42) {
          puVar49 = puVar42;
          if (*(int *)((long)puVar40 + 0x1c) <= iVar16) {
            puVar49 = puVar40;
          }
          if (puVar42 != puVar49) {
            iVar16 = func_0x00a58934(1,uVar64 & 0xffffffff);
            puVar49 = (undefined8 *)*puVar42;
            puVar40 = puVar42;
            while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
              while (puVar30 = puVar49, *(int *)((long)puVar30 + 0x1c) <= iVar16) {
                if (iVar16 <= *(int *)((long)puVar30 + 0x1c)) goto LAB_005c9c44;
                puVar49 = (undefined8 *)puVar30[1];
                if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
                  puVar40 = puVar30 + 1;
                  puVar43 = puVar30;
                  goto LAB_005c9bf0;
                }
              }
              puVar40 = puVar30;
              puVar49 = (undefined8 *)*puVar30;
            }
LAB_005c9bf0:
            puVar30 = (undefined8 *)func_0x00bc3330(0x28);
            *(int *)((long)puVar30 + 0x1c) = iVar16;
            *(undefined4 *)(puVar30 + 4) = 0;
            *puVar30 = 0;
            puVar30[1] = 0;
            puVar30[2] = puVar43;
            *puVar40 = puVar30;
            puVar49 = puVar30;
            if (*(long *)*plVar52 != 0) {
              *plVar52 = *(long *)*plVar52;
              puVar49 = (undefined8 *)*puVar40;
            }
            func_0x0040a8c0(*(undefined8 *)(&UNK_003825a0 + param_1),puVar49);
            *(long *)(&UNK_003825a8 + param_1) = *(long *)(&UNK_003825a8 + param_1) + 1;
LAB_005c9c44:
            *(int *)(puVar30 + 4) = *(int *)(puVar30 + 4) + 1;
            goto LAB_005c9c60;
          }
        }
      }
      iVar16 = func_0x00a58934(1,uVar64 & 0xffffffff);
      puVar49 = (undefined8 *)*puVar42;
      puVar40 = puVar42;
      while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
        while (puVar30 = puVar49, *(int *)((long)puVar30 + 0x1c) <= iVar16) {
          if (iVar16 <= *(int *)((long)puVar30 + 0x1c)) goto LAB_005c9c58;
          puVar49 = (undefined8 *)puVar30[1];
          if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
            puVar40 = puVar30 + 1;
            puVar43 = puVar30;
            goto LAB_005c9b40;
          }
        }
        puVar40 = puVar30;
        puVar49 = (undefined8 *)*puVar30;
      }
LAB_005c9b40:
      puVar30 = (undefined8 *)func_0x00bc3330(0x28);
      *(int *)((long)puVar30 + 0x1c) = iVar16;
      *(undefined4 *)(puVar30 + 4) = 0;
      *puVar30 = 0;
      puVar30[1] = 0;
      puVar30[2] = puVar43;
      *puVar40 = puVar30;
      puVar49 = puVar30;
      if (*(long *)*plVar52 != 0) {
        *plVar52 = *(long *)*plVar52;
        puVar49 = (undefined8 *)*puVar40;
      }
      func_0x0040a8c0(*(undefined8 *)(&UNK_003825a0 + param_1),puVar49);
      *(long *)(&UNK_003825a8 + param_1) = *(long *)(&UNK_003825a8 + param_1) + 1;
LAB_005c9c58:
      *(undefined4 *)(puVar30 + 4) = 1;
    }
LAB_005c9c60:
    uVar29 = func_0x005aad10();
    if ((uVar64 == (uVar29 & 0xffffffff)) &&
       (uVar29 = func_0x00a5fc78(1,uVar64 & 0xffffffff), (uVar29 & 1) == 0)) {
      func_0x00a58be4(1,uVar64 & 0xffffffff,0x11);
    }
    uVar64 = uVar64 + 1;
  } while (uVar64 != 0x33);
  puVar40 = (undefined8 *)*plVar52;
  while (puVar40 != puVar42) {
    uVar14 = *(undefined4 *)((long)puVar40 + 0x1c);
    puVar28 = (uint *)(ulong)*(uint *)(puVar40 + 4);
    puStack_160 = (uint *)0x0;
    puStack_158 = (uint *)0x0;
    puStack_150 = (uint *)0x0;
    uVar18 = func_0x007ac380();
    bStack_a0 = (byte)uVar18;
    uStack_9f = (undefined1)((uint)uVar18 >> 8);
    uStack_9e = (undefined2)((uint)uVar18 >> 0x10);
    lVar61 = func_0x007fd748();
    if (*(int *)(&UNK_00327f0c + lVar61) == 3) {
      uVar18 = func_0x007ac5b8();
    }
    else {
      uVar18 = 0;
    }
    uStack_9c = (undefined1)uVar18;
    uStack_9b = (undefined1)((uint)uVar18 >> 8);
    uStack_9a = (undefined1)((uint)uVar18 >> 0x10);
    uStack_99 = (undefined1)((uint)uVar18 >> 0x18);
    bStack_98 = (byte)uVar14;
    uStack_97 = (undefined1)((uint)uVar14 >> 8);
    uStack_96 = (undefined2)((uint)uVar14 >> 0x10);
    uVar14 = func_0x007ac230(0);
    sStack_94 = (short)uVar14;
    sStack_92 = (short)((uint)uVar14 >> 0x10);
    func_0x005df888(&puStack_160,&bStack_a0,&bStack_90,4);
    puVar44 = puStack_160;
    lStack_238 = 0;
    lStack_230 = 0;
    lStack_240 = 0;
    plVar52 = (long *)((long)puStack_158 - (long)puStack_160);
    if (plVar52 != (long *)0x0) {
      if ((long)plVar52 < 0) {
        if (*(long *)(lVar11 + 0x28) != lStack_88) goto LAB_005cf480;
        func_0x00441cdc(&lStack_240);
        goto LAB_005ceecc;
      }
      lStack_240 = func_0x00bc3330(plVar52);
      lVar61 = lStack_240 + (long)plVar52;
      lStack_238 = lStack_240;
      lStack_230 = lVar61;
      func_0x00bc35f0(lStack_240,puVar44,plVar52);
      lStack_238 = lVar61;
    }
    func_0x007d79dc(&UNK_0032c0b8 + param_1,0x16,&lStack_240,puVar28);
    if (lStack_240 != 0) {
      lStack_238 = lStack_240;
      func_0x00bc3350();
    }
    if (puStack_160 != (uint *)0x0) {
      puStack_158 = puStack_160;
      func_0x00bc3350();
    }
    puVar49 = (undefined8 *)puVar40[1];
    puVar43 = puVar40;
    if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
      do {
        puVar40 = (undefined8 *)puVar43[2];
        bVar13 = (undefined8 *)*puVar40 != puVar43;
        puVar43 = puVar40;
      } while (bVar13);
    }
    else {
      do {
        puVar40 = puVar49;
        puVar49 = (undefined8 *)*puVar40;
      } while ((undefined8 *)*puVar40 != (undefined8 *)0x0);
    }
  }
  uVar17 = func_0x007ad45c();
  uVar25 = (uint)param_2;
  if (((uVar17 | uVar25) & 1) == 0) {
    func_0x00a50034(param_1);
  }
  uVar64 = func_0x0070c220(param_1 + 0xad0);
  if ((uVar64 & 1) != 0) {
    func_0x0070c3ec(param_1 + 0xad0,0);
  }
  *(undefined1 *)(param_1 + 0x220) = 0;
  uVar64 = func_0x009d0178(*(undefined8 *)(param_1 + 0x7c0));
  if ((uVar64 & 1) != 0) {
    iVar16 = func_0x009d06fc(*(undefined8 *)(param_1 + 0x7c0));
    iVar15 = func_0x009d095c(*(undefined8 *)(param_1 + 0x7c0));
    iVar19 = func_0x009d0f60(*(undefined8 *)(param_1 + 0x7c0));
    *(bool *)(param_1 + 0x220) = iVar19 < iVar15 + iVar16;
    iVar16 = func_0x009d095c(*(undefined8 *)(param_1 + 0x7c0));
    uVar27 = *(undefined8 *)(param_1 + 0x7c0);
    uVar14 = func_0x007ac380();
    iVar15 = func_0x009d0c28(uVar27,uVar14);
    *(uint *)(param_1 + 0x836e0) = (uint)(iVar15 < iVar16);
    func_0x009d2238(*(undefined8 *)(param_1 + 0x7c0));
    func_0x00634b6c(param_1 + 0x668);
  }
  func_0x005ab174(1);
  uVar14 = func_0x0057a480();
  *(undefined4 *)(param_1 + 0x836c8) = uVar14;
  iVar15 = func_0x007ac230(0);
  iVar16 = *(int *)(param_1 + 0x836c8);
  if (iVar15 == 3000) {
    iVar15 = func_0x0082b458(*(undefined8 *)(param_1 + 0x21b0),&DAT_0107c688,100,500);
    iVar16 = (iVar15 * iVar16) / 100;
    *(int *)(param_1 + 0x836c8) = iVar16;
  }
  func_0x00abedcc(param_1 + 0xc2d8,iVar16);
  iVar16 = func_0x00abed88(param_1 + 0xc2d8);
  if (0x5f5e0fe < iVar16) {
    func_0x00abed54(param_1 + 0xc2d8,99999999);
  }
  (&UNK_004021f0)[param_1] = 0;
  if ((param_2 & 1) == 0) {
    lVar63 = 0;
    for (lVar61 = 0; lVar34 = func_0x007fd748(),
        lVar61 < (int)((ulong)(*(long *)(lVar34 + 0x4407f0) - *(long *)(lVar34 + 0x4407e8)) >> 4);
        lVar61 = lVar61 + 1) {
      lVar34 = func_0x007fd748();
      if (*(char *)(*(long *)(*(long *)(lVar34 + 0x4407e8) + lVar63) + 0x65) != '\0') {
        lVar34 = func_0x007fd748();
        func_0x007d78c0(&UNK_0032c0b8 + param_1,0xf,
                        *(undefined4 *)(*(long *)(*(long *)(lVar34 + 0x4407e8) + lVar63) + 0x14));
        lVar34 = func_0x007fd748();
        func_0x007d78f4(&UNK_0032c0b8 + param_1,0xf,
                        *(undefined4 *)(*(long *)(*(long *)(lVar34 + 0x4407e8) + lVar63) + 0x14),1,0
                        ,0);
      }
      lVar63 = lVar63 + 0x10;
    }
  }
  uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
  uVar20 = func_0x007a95d8(uVar27,*(undefined4 *)(&UNK_00338948 + param_1));
  if (*(int *)(&UNK_00327f0c + param_1) != 99) {
    lVar61 = func_0x007fd748();
    uVar64 = func_0x007ab618(&UNK_0032b898 + lVar61,uVar20);
    if ((uVar64 & 1) != 0) {
      puVar42 = (undefined8 *)(&UNK_0038fc48 + param_1);
      puVar40 = (undefined8 *)*puVar42;
      while (puVar49 = puVar42, puVar40 != (undefined8 *)0x0) {
        while (puVar42 = puVar40, *(int *)((long)puVar42 + 0x1c) <= (int)uVar20) {
          if ((int)uVar20 <= *(int *)((long)puVar42 + 0x1c)) goto LAB_005ca1c0;
          puVar40 = (undefined8 *)puVar42[1];
          if ((undefined8 *)puVar42[1] == (undefined8 *)0x0) {
            puVar49 = puVar42 + 1;
            goto LAB_005c9ff0;
          }
        }
        puVar40 = (undefined8 *)*puVar42;
      }
LAB_005c9ff0:
      puVar40 = (undefined8 *)func_0x00bc3330(0x28);
      *(uint *)((long)puVar40 + 0x1c) = uVar20;
      *(undefined4 *)(puVar40 + 4) = 0;
      *puVar40 = 0;
      puVar40[1] = 0;
      puVar40[2] = puVar42;
      *puVar49 = puVar40;
      lVar61 = **(long **)(&UNK_0038fc40 + param_1);
      puVar42 = puVar40;
      if (lVar61 != 0) {
        *(long *)(&UNK_0038fc40 + param_1) = lVar61;
        puVar42 = (undefined8 *)*puVar49;
      }
      func_0x0040a8c0(*(undefined8 *)(&UNK_0038fc48 + param_1),puVar42);
      *(long *)(&UNK_0038fc50 + param_1) = *(long *)(&UNK_0038fc50 + param_1) + 1;
      puVar42 = puVar40;
LAB_005ca1c0:
      *(int *)(puVar42 + 4) = *(int *)(puVar42 + 4) + 1;
      iVar16 = func_0x007ab978(&UNK_0032b898 + param_1,uVar20);
      if (iVar16 != 0) {
        plVar50 = (long *)(&UNK_0038fc90 + param_1);
        for (plVar52 = (long *)*plVar50; plVar52 != (long *)0x0; plVar52 = (long *)*plVar52) {
          if (*(int *)(plVar52 + 4) <= (int)uVar20) {
            if ((int)uVar20 <= *(int *)(plVar52 + 4)) goto LAB_005ca3e4;
            plVar52 = plVar52 + 1;
          }
        }
        dVar70 = (double)func_0x0045e350();
        iVar16 = func_0x007ab978(&UNK_0032b898 + param_1,uVar20);
        plVar52 = (long *)*plVar50;
        while (plVar65 = plVar50, plVar52 != (long *)0x0) {
          while (plVar50 = plVar52, (int)plVar50[4] <= (int)uVar20) {
            if ((int)uVar20 <= (int)plVar50[4]) goto LAB_005ca3d0;
            plVar52 = (long *)plVar50[1];
            if ((long *)plVar50[1] == (long *)0x0) {
              plVar65 = plVar50 + 1;
              goto LAB_005ca274;
            }
          }
          plVar52 = (long *)*plVar50;
        }
LAB_005ca274:
        plVar31 = (long *)func_0x00bc3330(0x30);
        *(uint *)(plVar31 + 4) = uVar20;
        plVar31[5] = 0;
        *plVar31 = 0;
        plVar31[1] = 0;
        plVar31[2] = (long)plVar50;
        *plVar65 = (long)plVar31;
        plVar52 = plVar31;
        if (**(long **)(&UNK_0038fc88 + param_1) != 0) {
          *(long *)(&UNK_0038fc88 + param_1) = **(long **)(&UNK_0038fc88 + param_1);
          plVar52 = (long *)*plVar65;
        }
        func_0x0040a8c0(*(undefined8 *)(&UNK_0038fc90 + param_1),plVar52);
        *(long *)(&UNK_0038fc98 + param_1) = *(long *)(&UNK_0038fc98 + param_1) + 1;
        plVar50 = plVar31;
LAB_005ca3d0:
        plVar50[5] = (long)(dVar70 + (double)(iVar16 * 0x3c));
      }
    }
  }
LAB_005ca3e4:
  if ((*(int *)(param_1 + 0x4a570) == 0) && (*(int *)(param_1 + 0xc8b4) == 0)) {
    *(undefined1 *)(param_1 + 0x222) = 1;
  }
  puVar42 = (undefined8 *)(&UNK_0032c688 + param_1);
  plVar50 = (long *)*puVar42;
  plVar52 = *(long **)(&UNK_0032c690 + param_1);
  puVar45[0] = 0;
  puVar45[1] = 0;
  while (plVar65 = plVar52, plVar65 != plVar50) {
    plVar52 = plVar65 + -3;
    if (*plVar52 != 0) {
      plVar65[-2] = *plVar52;
      func_0x00bc3350();
    }
  }
  *(long **)(&UNK_0032c690 + param_1) = plVar50;
  iVar16 = func_0x007ac230(0);
  if ((((iVar16 == 3000) && (iVar16 = func_0x007ac380(), iVar16 == 6)) &&
      ((&UNK_00447598)[param_1] != '\0')) &&
     (iVar16 = func_0x009cd640(0xfffffffe,0,6,0,0), iVar16 == 0)) {
    (&UNK_00447598)[param_1] = 0;
  }
  if (*(int *)(&UNK_00327f0c + param_1) == 3) {
    uVar5 = *puVar1;
    iVar16 = func_0x007ac230(0);
    func_0x00a0b124(2,0,0,0,0);
    func_0x007d78f4(&UNK_0032c0b8 + param_1,0,iVar16,1,uVar25 & 1,0);
    func_0x007d78f4(&UNK_0032c0b8 + param_1,1,uVar5 + iVar16 * 100,1,uVar25 & 1,0);
    func_0x007d78f4(&UNK_0032c0b8 + param_1,9,iVar16 / 1000,1,uVar25 & 1,0);
    iVar15 = func_0x007abd78(0);
    if (iVar15 == -0x17) {
      iVar15 = func_0x007ac5b8();
      func_0x007d78f4(&UNK_0032c0b8 + param_1,0x1e,iVar15 + uVar5 * 10,1,uVar25 & 1,0);
    }
    uVar26 = func_0x007ab580(&UNK_0032b898 + param_1,iVar16);
    if (0 < (int)uVar26) {
      uVar21 = 0;
      uVar48 = 1;
      do {
        if ((uVar48 & uVar26) != 0) {
          func_0x007d78f4(&UNK_0032c0b8 + param_1,0x14,uVar21,1,uVar25 & 1,0);
        }
        uVar48 = 2 << (ulong)(uVar21 & 0x1f);
        uVar21 = uVar21 + 1;
      } while ((int)uVar48 <= (int)uVar26);
    }
    uVar14 = *(undefined4 *)(&UNK_00327f0c + param_1);
    uVar26 = *puVar53;
    uVar18 = *(undefined4 *)(&UNK_00383744 + param_1);
    *(undefined4 *)(param_1 + 0x836d8) = 0;
    *(undefined4 *)(&UNK_00327f10 + param_1) = uVar14;
    *(uint *)(&UNK_00325c4c + param_1) = uVar26;
    *(undefined4 *)(param_1 + 0x836d0) = 0xffffffff;
    uVar27 = func_0x007a95b8(uVar18);
    uVar26 = func_0x007b0ec0(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),
                             *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
    if (uVar26 == *puVar1) {
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      func_0x007b14a0(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),
                      *(undefined4 *)(&UNK_0038ff5c + param_1),1,uVar17 & 1);
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      uVar14 = func_0x007b0ec0(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),
                               *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
      *(undefined4 *)(param_1 + 0x83700) = uVar14;
      *(undefined8 *)(&UNK_0032c9ec + param_1) = 0xffffffff00000000;
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      func_0x007b0e64(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),
                      *(undefined4 *)(&UNK_0038ff5c + param_1),1,uVar17 & 1);
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      iVar19 = func_0x007b0ec0(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),
                               *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
      puVar49 = (undefined8 *)(param_1 + 0x23c8);
      iVar15 = *(int *)(&UNK_0038ef30 + param_1);
      puVar43 = *(undefined8 **)(param_1 + 0x23c8);
      puVar40 = puVar49;
      while (puVar30 = puVar40, puVar43 != (undefined8 *)0x0) {
        while (puVar35 = puVar43, *(int *)(puVar35 + 4) <= iVar15) {
          if (iVar15 <= *(int *)(puVar35 + 4)) goto LAB_005cbd74;
          puVar43 = (undefined8 *)puVar35[1];
          if ((undefined8 *)puVar35[1] == (undefined8 *)0x0) {
            puVar40 = puVar35 + 1;
            puVar30 = puVar35;
            goto LAB_005cac4c;
          }
        }
        puVar40 = puVar35;
        puVar43 = (undefined8 *)*puVar35;
      }
LAB_005cac4c:
      puVar35 = (undefined8 *)func_0x00bc3330(0xa0);
      *(int *)(puVar35 + 4) = iVar15;
      puVar35[0x13] = 0;
      *puVar35 = 0;
      puVar35[1] = 0;
      puVar35[2] = puVar30;
      puVar35[6] = 0;
      puVar35[5] = 0;
      puVar35[8] = 0;
      puVar35[7] = 0;
      puVar35[10] = 0;
      puVar35[9] = 0;
      puVar35[0xc] = 0;
      puVar35[0xb] = 0;
      puVar35[0xe] = 0;
      puVar35[0xd] = 0;
      puVar35[0x10] = 0;
      puVar35[0xf] = 0;
      puVar35[0x12] = 0;
      puVar35[0x11] = 0;
      *puVar40 = puVar35;
      puVar43 = puVar35;
      if (**(long **)(param_1 + 0x23c0) != 0) {
        *(long *)(param_1 + 0x23c0) = **(long **)(param_1 + 0x23c0);
        puVar43 = (undefined8 *)*puVar40;
      }
      func_0x0040a8c0(*(undefined8 *)(param_1 + 0x23c8),puVar43);
      *(long *)(param_1 + 0x23d0) = *(long *)(param_1 + 0x23d0) + 1;
LAB_005cbd74:
      iVar15 = func_0x007b7ff8(puVar35 + 5,*(undefined4 *)(&UNK_0038ef34 + param_1));
      if (iVar19 == iVar15) {
        uVar23 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
        uVar18 = *(undefined4 *)(&UNK_00338948 + param_1);
        uVar14 = *(undefined4 *)(&UNK_0038ff5c + param_1);
        iVar15 = *(int *)(&UNK_0038ef30 + param_1);
        puVar40 = (undefined8 *)*puVar49;
        while (puVar43 = puVar49, puVar40 != (undefined8 *)0x0) {
          while (puVar30 = puVar40, *(int *)(puVar30 + 4) <= iVar15) {
            if (iVar15 <= *(int *)(puVar30 + 4)) goto LAB_005cbef0;
            puVar40 = (undefined8 *)puVar30[1];
            if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
              puVar49 = puVar30 + 1;
              puVar43 = puVar30;
              goto LAB_005cbdf8;
            }
          }
          puVar49 = puVar30;
          puVar40 = (undefined8 *)*puVar30;
        }
LAB_005cbdf8:
        puVar30 = (undefined8 *)func_0x00bc3330(0xa0);
        *(int *)(puVar30 + 4) = iVar15;
        puVar30[0x13] = 0;
        *puVar30 = 0;
        puVar30[1] = 0;
        puVar30[2] = puVar43;
        puVar30[6] = 0;
        puVar30[5] = 0;
        puVar30[8] = 0;
        puVar30[7] = 0;
        puVar30[10] = 0;
        puVar30[9] = 0;
        puVar30[0xc] = 0;
        puVar30[0xb] = 0;
        puVar30[0xe] = 0;
        puVar30[0xd] = 0;
        puVar30[0x10] = 0;
        puVar30[0xf] = 0;
        puVar30[0x12] = 0;
        puVar30[0x11] = 0;
        *puVar49 = puVar30;
        puVar40 = puVar30;
        if (**(long **)(param_1 + 0x23c0) != 0) {
          *(long *)(param_1 + 0x23c0) = **(long **)(param_1 + 0x23c0);
          puVar40 = (undefined8 *)*puVar49;
        }
        func_0x0040a8c0(*(undefined8 *)(param_1 + 0x23c8),puVar40);
        *(long *)(param_1 + 0x23d0) = *(long *)(param_1 + 0x23d0) + 1;
LAB_005cbef0:
        iVar15 = func_0x007b7ff8(puVar30 + 5,*(undefined4 *)(&UNK_0038ef34 + param_1));
        func_0x007b0be4(uVar23,uVar18,uVar14,iVar15 + -1,uVar17 & 1);
        if ((*(int *)(&UNK_0038ff5c + param_1) == 0) &&
           (iVar15 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1)), iVar15 == 0)) {
          uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
          func_0x007af340(uVar27,*(int *)(&UNK_00338948 + param_1) + 1,0,1);
        }
        *(undefined4 *)(param_1 + 0x836d0) = 0;
        func_0x006e3770(0x16,0x1e,0);
        func_0x007d78f4(&UNK_0032c0b8 + param_1,3,*(undefined4 *)(&UNK_0038ff5c + param_1),1,
                        uVar25 & 1,uVar17 & 1);
        func_0x006e3770(0x69,1,0);
        puStack_160 = (uint *)&UNK_002974c3;
        puStack_158 = (uint *)((ulong)puStack_158 & 0xffffffff00000000);
        puStack_150 = (uint *)0x0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,4);
        bStack_98 = 0x2d;
        uStack_97 = 0xf7;
        uStack_96 = 0x29;
        sStack_94 = 0;
        sStack_92 = 0;
        func_0x00bc5cd0(&puStack_158,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        iVar15 = func_0x007ac230(0);
        ppuStack_140 = (uint **)&UNK_0029a3d5;
        uStack_138 = (ulong)uStack_138._4_4_ << 0x20;
        uStack_130 = 0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,1);
        bStack_98 = (byte)iVar15;
        uStack_97 = (undefined1)((uint)iVar15 >> 8);
        uStack_96 = (undefined2)((uint)iVar15 >> 0x10);
        sStack_94 = (short)(iVar15 >> 0x1f);
        sStack_92 = sStack_94;
        func_0x00bc5cd0(&uStack_138,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        puStack_120 = &UNK_00290d7a;
        uStack_118 = uStack_118 & 0xffffffff00000000;
        uStack_110 = 0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,4);
        bStack_98 = 0xdd;
        uStack_97 = 0xa3;
        uStack_96 = 0x29;
        sStack_94 = 0;
        sStack_92 = 0;
        func_0x00bc5cd0(&uStack_118,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        iVar15 = func_0x007ac380();
        bStack_100 = 0x62;
        uStack_ff = 0x2984;
        uStack_f8 = 0;
        uStack_f7 = 0;
        uStack_f5 = 0;
        uStack_f0 = 0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,1);
        bStack_98 = (byte)iVar15;
        uStack_97 = (undefined1)((uint)iVar15 >> 8);
        uStack_96 = (undefined2)((uint)iVar15 >> 0x10);
        sStack_94 = (short)(iVar15 >> 0x1f);
        sStack_92 = sStack_94;
        func_0x00bc5cd0(&uStack_f8,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        puStack_e0 = &UNK_00291fc1;
        uStack_d8 = uStack_d8 & 0xffffffff00000000;
        uStack_d0 = 0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,4);
        bStack_98 = 0x98;
        uStack_97 = 0x77;
        uStack_96 = 0x2a;
        sStack_94 = 0;
        sStack_92 = 0;
        func_0x00bc5cd0(&uStack_d8,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        iVar15 = func_0x007ac5b8();
        puStack_c0 = &UNK_002a6836;
        auStack_b8[0] = 0;
        uStack_b0 = 0;
        bStack_a0 = 0;
        uStack_9f = 0;
        uStack_9e = 0;
        func_0x00bc5cc0(&bStack_a0,1);
        bStack_98 = (byte)iVar15;
        uStack_97 = (undefined1)((uint)iVar15 >> 8);
        uStack_96 = (undefined2)((uint)iVar15 >> 0x10);
        sStack_94 = (short)(iVar15 >> 0x1f);
        sStack_92 = sStack_94;
        func_0x00bc5cd0(auStack_b8,&bStack_a0);
        func_0x00bc5cc0(&bStack_a0,0);
        lVar61 = func_0x007fd748();
        func_0x0082572c(*(undefined8 *)(lVar61 + 0x21a0),&UNK_0098c17f,0x1e,0,&puStack_160,6);
        func_0x00bc5cc0(auStack_b8,0);
        func_0x00bc5cc0(&uStack_d8,0);
        func_0x00bc5cc0(&uStack_f8,0);
        func_0x00bc5cc0(&uStack_118,0);
        func_0x00bc5cc0(&uStack_138,0);
        func_0x00bc5cc0(&puStack_158,0);
      }
      puVar33 = (undefined4 *)(param_1 + 0x4af14);
    }
    else {
      puVar33 = (undefined4 *)(param_1 + 0x83700);
    }
    *puVar33 = 0xffffffff;
    if ((uVar17 & 1) == 0) {
      uVar64 = func_0x009d0178(*(undefined8 *)(param_1 + 0x7c0));
      if (((uVar64 & 1) == 0) ||
         (uVar64 = func_0x009d2228(*(undefined8 *)(param_1 + 0x7c0)), (uVar64 & 1) == 0)) {
        uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
        func_0x009ce358(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                        *(undefined4 *)(&UNK_0038ff5c + param_1),1,0);
        uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
        iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                                 *(undefined4 *)(&UNK_0038ff5c + param_1),0);
        if (9999 < iVar15) {
          uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
          func_0x009cdc30(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                          *(undefined4 *)(&UNK_0038ff5c + param_1),9999,0);
          bVar13 = false;
          goto LAB_005cc3e8;
        }
      }
      bVar13 = false;
    }
    else {
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                               *(undefined4 *)(&UNK_0038ff5c + param_1),1);
      if (iVar15 < 9999) {
        uVar23 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
        uVar18 = *(undefined4 *)(&UNK_00338948 + param_1);
        uVar25 = *puVar1;
        uVar14 = *(undefined4 *)(&UNK_0038ff5c + param_1);
        iVar19 = func_0x00a7039c(param_1 + 0x2c8,0xffffffff,0,0);
        uVar24 = func_0x0043ed6c(iVar19 + 1,iVar15);
        func_0x009cdc30(uVar23,uVar18,uVar25,uVar14,uVar24,1);
      }
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      iVar19 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                               *(undefined4 *)(&UNK_0038ff5c + param_1),1);
      bVar13 = iVar15 < iVar19;
    }
LAB_005cc3e8:
    uVar14 = func_0x0063ee24(param_1 + 0x1328);
    func_0x0063d870(&puStack_160,param_1 + 0x1328,uVar14);
    uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
    iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                             *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
    if ((((iVar15 == 1) &&
         (iVar15 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1)), iVar15 == -0x13)) &&
        (*(int *)(&UNK_00338948 + param_1) == 0)) &&
       (((*(int *)(&UNK_0038ff5c + param_1) == 0 &&
         (((long)puStack_158 - (long)puStack_160 & 0x3fffffffcU) == 4)) &&
        ((uVar25 = *puStack_160, uVar25 == *puVar1 && ((uVar25 == 0x30 || (uVar25 == 0)))))))) {
      uVar14 = func_0x0063ee24(param_1 + 0x1328);
      func_0x0063ec90(0,param_1 + 0x1328,uVar14);
    }
    if (puStack_160 != (uint *)0x0) {
      puStack_158 = puStack_160;
      func_0x00bc3350();
    }
    iVar15 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
    if (((iVar15 == 0) && (*(int *)(&UNK_00338948 + param_1) == 0x30)) &&
       (uVar25 = *puVar1, iVar15 = func_0x007af4ac(0,0x30), uVar25 == iVar15 - 1U)) {
      uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
      iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                               *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
      if (iVar15 == 1) {
        *(undefined4 *)(param_1 + 0x836d8) = 1;
        *(undefined4 *)(&UNK_0032c9ec + param_1) = 1;
      }
    }
    iVar15 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
    if ((iVar15 == -9) &&
       (iVar15 = *(int *)(&UNK_00338948 + param_1), iVar19 = func_0x007afdb0(),
       iVar15 == iVar19 + -1)) {
      uVar25 = *puVar1;
      iVar15 = func_0x007afdb0(0xfffffff7);
      iVar15 = func_0x007af4ac(0xfffffff7,iVar15 + -1);
      if (uVar25 == iVar15 - 1U) {
        uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
        iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                                 *(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
        if (iVar15 == 1) {
          *(undefined4 *)(param_1 + 0x836d8) = 1;
        }
      }
    }
  }
  else {
    if (*(int *)(&UNK_00327f0c + param_1) == 99) {
      uVar5 = *(uint *)(&UNK_004021fc + param_1);
      uVar26 = *(uint *)(&UNK_004021f4 + param_1);
      (&UNK_004021f0)[param_1] = 1;
      *(undefined4 *)(param_1 + 0x836d0) = 0xffffffff;
      if ((uVar26 < 0x52) && (*puVar53 < 0xc)) {
        lVar61 = param_1 + (ulong)uVar26 * 0x30 + (ulong)*puVar53 * 4;
        if (*(int *)(&UNK_0046aa58 + lVar61) < 9999) {
          *(int *)(&UNK_0046aa58 + lVar61) = *(int *)(&UNK_0046aa58 + lVar61) + 1;
        }
      }
      uVar64 = func_0x00769620(param_1);
      if ((uVar64 & 1) == 0) {
        uVar64 = func_0x0063fc28(param_1 + 0x12c8);
        if ((uVar64 & 1) == 0) {
          uVar64 = func_0x0099ae20(param_1 + 0x420);
          if ((uVar64 & 1) != 0) {
            func_0x0099afac(param_1 + 0x420);
          }
        }
        else {
          uVar14 = func_0x007ac230(0);
          func_0x00700898(param_1 + 0x2e38,uVar14);
          *(undefined4 *)(param_1 + 0x836d8) = 1;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x1490) = 1;
      }
      func_0x00a0b124(5,*(undefined4 *)(&UNK_004021f4 + param_1),*puVar53,0,0);
      func_0x007d78f4(&UNK_0032c0b8 + param_1,0,*(int *)(&UNK_004021f4 + param_1) + 4000,1,
                      uVar25 & 1,0);
      func_0x007d78f4(&UNK_0032c0b8 + param_1,1,
                      *puVar53 + *(int *)(&UNK_004021f4 + param_1) * 100 + 400000,1,uVar25 & 1,0);
      func_0x007d78f4(&UNK_0032c0b8 + param_1,9,4,1,uVar25 & 1,0);
      uVar21 = func_0x007ab580(&UNK_0032b898 + param_1,*(int *)(&UNK_004021f4 + param_1) + 4000);
      iVar16 = uVar26 + 4000;
      if (0 < (int)uVar21) {
        uVar26 = 0;
        uVar48 = 1;
        do {
          if ((uVar48 & uVar21) != 0) {
            func_0x007d78f4(&UNK_0032c0b8 + param_1,0x14,uVar26,1,uVar25 & 1,0);
          }
          uVar48 = 2 << (ulong)(uVar26 & 0x1f);
          uVar26 = uVar26 + 1;
        } while ((int)uVar48 <= (int)uVar21);
      }
    }
    else {
      uVar5 = *puVar1;
      iVar16 = func_0x007ac230(0);
      iVar15 = *(int *)(&UNK_00327f0c + param_1);
      uVar26 = *puVar1;
      lVar61 = param_1 + (long)iVar15 * 0xd0;
      *(int *)(&UNK_00327f10 + param_1) = iVar15;
      *(uint *)(&UNK_00325c4c + param_1) = *puVar53;
      pcVar2 = (char *)(lVar61 + 0xc988 + (long)(int)uVar26 * 4);
      if (((*(char *)(lVar61 + 0xca56) == pcVar2[2] && *(char *)(lVar61 + 0xca57) == pcVar2[3]) &&
          *(char *)(lVar61 + 0xca55) == pcVar2[1]) && *(char *)(lVar61 + 0xca54) == *pcVar2) {
        func_0x00a0b124(1,(long)iVar15,(long)(int)uVar26,0,0);
      }
      if ((((&UNK_0032c658)[param_1] == '\0') && ((&UNK_0032c666)[param_1] == '\0')) &&
         ((&UNK_0032c667)[param_1] == '\0')) {
        func_0x00a0b124(0x21,*(undefined4 *)(&UNK_00327f0c + param_1),*puVar1,0,0);
      }
      func_0x007d78f4(&UNK_0032c0b8 + param_1,0,iVar16,1,uVar25 & 1,0);
      func_0x007d78f4(&UNK_0032c0b8 + param_1,1,uVar5 + iVar16 * 100,1,uVar25 & 1,0);
      func_0x007d78f4(&UNK_0032c0b8 + param_1,9,iVar16 / 1000,1,uVar25 & 1,0);
      uVar26 = *(uint *)(&UNK_00327f0c + param_1);
      lVar61 = param_1 + 0xc95c;
      *(undefined4 *)(param_1 + 0x836d8) = 0;
      bVar6 = *(byte *)(param_1 + 0xc986);
      pbVar60 = (byte *)(lVar61 + (long)(int)uVar26 * 4);
      bVar7 = *(byte *)(param_1 + 0xc987);
      bVar8 = *(byte *)(param_1 + 0xc985);
      uVar25 = (uint)(bVar6 ^ pbVar60[2]) << 0x10 | (uint)(bVar7 ^ pbVar60[3]) << 0x18 |
               (uint)(bVar8 ^ pbVar60[1]) << 8 | (uint)(*(byte *)(param_1 + 0xc984) ^ *pbVar60);
      if (uVar25 == *puVar1) {
        iVar15 = uVar25 + 1;
        *pbVar60 = *(byte *)(param_1 + 0xc984) ^ (byte)iVar15;
        pbVar60[1] = bVar8 ^ (byte)((uint)iVar15 >> 8);
        pbVar60[2] = bVar6 ^ (byte)((uint)iVar15 >> 0x10);
        pbVar60[3] = bVar7 ^ (byte)((uint)iVar15 >> 0x18);
        pbVar60 = (byte *)(lVar61 + (long)*(int *)(&UNK_00327f0c + param_1) * 4);
        lVar63 = param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 4;
        *(uint *)(param_1 + 0x83700) =
             (uint)(*(byte *)(param_1 + 0xc986) ^ pbVar60[2]) << 0x10 |
             (uint)(*(byte *)(param_1 + 0xc987) ^ pbVar60[3]) << 0x18 |
             (uint)(*(byte *)(param_1 + 0xc985) ^ pbVar60[1]) << 8 |
             (uint)(*(byte *)(param_1 + 0xc984) ^ *pbVar60);
        *(undefined8 *)(&UNK_0032c9ec + param_1) = 0xffffffff00000000;
        *(int *)(lVar63 + 0xc934) = *(int *)(lVar63 + 0xc934) + 1;
        uVar26 = *(uint *)(&UNK_00327f0c + param_1);
        *(undefined4 *)(param_1 + 0x4af14) = 0xffffffff;
        pbVar60 = (byte *)(lVar61 + (long)(int)uVar26 * 4);
        if (((uint)(*(byte *)(param_1 + 0xc986) ^ pbVar60[2]) << 0x10 |
             (uint)(*(byte *)(param_1 + 0xc987) ^ pbVar60[3]) << 0x18 |
             (uint)(*(byte *)(param_1 + 0xc985) ^ pbVar60[1]) << 8 |
            (uint)(*(byte *)(param_1 + 0xc984) ^ *pbVar60)) == 0x30) {
          lVar63 = 0;
          *(undefined4 *)(&UNK_0032c9ec + param_1) = 1;
          *(undefined4 *)(param_1 + 0x836d8) = 1;
          *(undefined4 *)(param_1 + (long)(int)uVar26 * 4 + 0xc934) = 0x2f;
          pbVar60 = (byte *)(param_1 + 0x4af18);
          uVar26 = *(uint *)(&UNK_00327f0c + param_1);
          uVar25 = *(uint *)(param_1 + 0x83700);
          do {
            bVar6 = pbVar60[0xfe];
            bVar7 = pbVar60[0xff];
            bVar8 = pbVar60[0xfd];
            bVar9 = pbVar60[0xfc];
            if (((((uint)(bVar6 ^ pbVar60[0x3e]) << 0x10 | (uint)(bVar7 ^ pbVar60[0x3f]) << 0x18 |
                   (uint)(bVar8 ^ pbVar60[0x3d]) << 8 | (uint)(bVar9 ^ pbVar60[0x3c])) == uVar26) &&
                (((uint)(pbVar60[2] ^ bVar6) << 0x10 | (uint)(pbVar60[3] ^ bVar7) << 0x18 |
                  (uint)(pbVar60[1] ^ bVar8) << 8 | (uint)(*pbVar60 ^ bVar9)) == uVar25)) &&
               (((pbVar60[6] == bVar6 && pbVar60[7] == bVar7) && pbVar60[5] == bVar8) &&
                pbVar60[4] == bVar9)) {
              *(int *)(&UNK_0032c9f0 + param_1) = (int)lVar63;
            }
            lVar63 = lVar63 + 1;
            pbVar60 = pbVar60 + 0x100;
          } while (lVar63 != 0x36c);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x83700) = 0xffffffff;
      }
      lVar63 = param_1 + 0xc988 + (long)(int)uVar26 * 0xd0;
      pbVar60 = (byte *)(lVar63 + (long)(int)*puVar1 * 4);
      bVar6 = *(byte *)(lVar63 + 0xcd);
      bVar7 = *(byte *)(lVar63 + 0xce);
      bVar8 = *(byte *)(lVar63 + 0xcf);
      iVar15 = (*(byte *)(lVar63 + 0xcc) ^ *pbVar60) + 1;
      iVar19 = iVar15 + (uint)(bVar6 ^ pbVar60[1]) * 0x100;
      *pbVar60 = *(byte *)(lVar63 + 0xcc) ^ (byte)iVar15;
      iVar15 = iVar19 + (uint)(bVar7 ^ pbVar60[2]) * 0x10000;
      pbVar60[1] = bVar6 ^ (byte)((uint)iVar19 >> 8);
      pbVar60[2] = bVar7 ^ (byte)((uint)iVar15 >> 0x10);
      pbVar60[3] = (bVar8 ^ pbVar60[3]) + (char)((uint)iVar15 >> 0x18) ^ bVar8;
      lVar63 = param_1 + 0xc988 + (long)*(int *)(&UNK_00327f0c + param_1) * 0xd0;
      pbVar60 = (byte *)(lVar63 + (long)(int)*puVar1 * 4);
      bVar6 = *(byte *)(lVar63 + 0xcf);
      bVar7 = *(byte *)(lVar63 + 0xcd);
      bVar8 = *(byte *)(lVar63 + 0xcc);
      if (9999 < (int)((uint)(*(byte *)(lVar63 + 0xce) ^ pbVar60[2]) << 0x10 |
                       (uint)(bVar6 ^ pbVar60[3]) << 0x18 | (uint)(bVar7 ^ pbVar60[1]) << 8 |
                      (uint)(bVar8 ^ *pbVar60))) {
        pbVar60[2] = *(byte *)(lVar63 + 0xce);
        *pbVar60 = bVar8 ^ 0xf;
        pbVar60[1] = bVar7 ^ 0x27;
        pbVar60[3] = bVar6;
      }
      iVar15 = func_0x007abd78(0);
      uVar14 = func_0x007ac264(0);
      uVar18 = func_0x007ac380();
      iVar19 = func_0x009cd640(iVar15,uVar14,uVar18,0,0);
      if (((iVar19 == 1) && (iVar15 + 7U < 6)) &&
         (((1 << (ulong)(iVar15 + 7U & 0x1f) & 0x31U) != 0 &&
          (iVar15 = func_0x007ac380(), iVar15 == 0x2f)))) {
        uVar14 = func_0x007ac230(0);
        func_0x00700898(param_1 + 0x2e38,uVar14);
      }
      uVar25 = *(uint *)(&UNK_00327f0c + param_1);
      uVar64 = (ulong)uVar25;
      if (((uVar64 == 0 && *puVar1 != 0) && (uVar64 != 0 || -1 < (int)*puVar1)) || (0 < (int)uVar25)
         ) {
        uVar26 = *(uint *)(param_1 + 0x83700);
        if (uVar26 != 0xffffffff) {
          pbVar62 = (byte *)(lVar61 + uVar64 * 4);
          pbVar60 = (byte *)(param_1 + 0x4af18);
          lVar61 = 0x36c;
          do {
            if (((uint)(pbVar60[0xfe] ^ pbVar60[0x3e]) << 0x10 |
                 (uint)(pbVar60[0xff] ^ pbVar60[0x3f]) << 0x18 |
                 (uint)(pbVar60[0xfd] ^ pbVar60[0x3d]) << 8 | (uint)(pbVar60[0xfc] ^ pbVar60[0x3c]))
                == uVar25) {
              uVar21 = (uint)(pbVar60[2] ^ pbVar60[0xfe]) << 0x10 |
                       (uint)(pbVar60[3] ^ pbVar60[0xff]) << 0x18 |
                       (uint)(pbVar60[1] ^ pbVar60[0xfd]) << 8 | (uint)(*pbVar60 ^ pbVar60[0xfc]);
              if (((uint)(*(byte *)(param_1 + 0xc986) ^ pbVar62[2]) << 0x10 |
                   (uint)(*(byte *)(param_1 + 0xc987) ^ pbVar62[3]) << 0x18 |
                   (uint)(*(byte *)(param_1 + 0xc985) ^ pbVar62[1]) << 8 |
                  (uint)(*(byte *)(param_1 + 0xc984) ^ *pbVar62)) == 0x30) {
                if (uVar21 == uVar26) {
                  iVar15 = func_0x005cf5fc(pbVar60,1);
                  if (iVar15 != 0) {
LAB_005cb124:
                    *(undefined4 *)(&UNK_0032c9e8 + param_1) = 1;
                  }
                  break;
                }
              }
              else if (uVar21 == uVar26) goto LAB_005cb124;
            }
            lVar61 = lVar61 + -1;
            pbVar60 = pbVar60 + 0x100;
          } while (lVar61 != 0);
        }
        func_0x0098a1a8(param_1);
        uVar64 = (ulong)*(uint *)(&UNK_00327f0c + param_1);
      }
      uVar64 = func_0x0078a22c(param_1,uVar64);
      if (((uVar64 & 1) != 0) && ((&UNK_0032c667)[param_1] != '\0')) {
        puStack_160 = (uint *)((ulong)puStack_160 & 0xffffffffffff0000);
        (&UNK_0032c668)[param_1] = 0xff;
        (&UNK_0032c66a)[param_1] = 1;
        bStack_a0 = 0;
        uStack_9f = 0;
        func_0x00a0a85c(1,&puStack_160,&bStack_a0);
        if ((bStack_a0 & 1) != 0) {
          func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
        }
        if (((ulong)puStack_160 & 1) != 0) {
          func_0x00bc3350(puStack_150);
        }
        puStack_160 = (uint *)((ulong)puStack_160 & 0xffffffffffff0000);
        bStack_a0 = 0;
        uStack_9f = 0;
        func_0x00a0a85c(0x21,&puStack_160,&bStack_a0);
        if ((bStack_a0 & 1) != 0) {
          func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
        }
        if (((ulong)puStack_160 & 1) != 0) {
          func_0x00bc3350(puStack_150);
        }
      }
    }
    bVar13 = false;
  }
  piVar32 = (int *)func_0x00a0a0e8(param_1 + 0x1248,uVar20,uVar5);
  if ((piVar32 != (int *)0x0) &&
     (iVar15 = *piVar32, iVar19 = func_0x00a0a1f0(param_1 + 0x1248,uVar20), iVar19 < iVar15)) {
    puStack_160 = (uint *)func_0x00bc3330(0xc);
    *puStack_160 = 10;
    puStack_160[1] = uVar20;
    puStack_158 = puStack_160 + 3;
    puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
    puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
    puStack_160[2] = uVar5;
    puStack_150 = puStack_158;
    if (puVar40 < puVar49) {
      *puVar40 = 0;
      puVar40[1] = 0;
      puVar40[2] = 0;
      puVar40[1] = puStack_158;
      *puVar40 = puStack_160;
      puVar40[2] = puStack_158;
      *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
    }
    else {
      uVar27 = func_0x005df9b8(puVar42,&puStack_160);
      *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
      if (puStack_160 != (uint *)0x0) {
        puStack_158 = puStack_160;
        func_0x00bc3350();
      }
    }
    puVar33 = (undefined4 *)func_0x00a0a0e8(param_1 + 0x1248,uVar20,uVar5);
    func_0x00a0a26c(param_1 + 0x1248,uVar20,uVar5,*puVar33);
  }
  uVar14 = func_0x007a9764(iVar16);
  uVar18 = func_0x007a9a18(iVar16);
  iVar15 = func_0x009cd640(uVar14,uVar18,uVar5,*(undefined4 *)(&UNK_0038ff5c + param_1),uVar17 & 1);
  if ((iVar15 == 1) && (iVar15 = func_0x0063fce0(param_1 + 0x12c8,iVar16,uVar5), 0 < iVar15)) {
    puStack_160 = (uint *)func_0x00bc3330(4);
    puStack_158 = puStack_160 + 1;
    *puStack_160 = 9;
    puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
    puStack_150 = puStack_158;
    if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
      *puVar40 = 0;
      puVar40[1] = 0;
      puVar40[2] = 0;
      puVar40[1] = puStack_158;
      *puVar40 = puStack_160;
      puVar40[2] = puStack_158;
      *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
    }
    else {
      uVar27 = func_0x005df9b8(puVar42,&puStack_160);
      *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
      if (puStack_160 != (uint *)0x0) {
        puStack_158 = puStack_160;
        func_0x00bc3350();
      }
    }
  }
  lVar61 = param_1 + (long)(int)uVar5 * 0xbc;
  puVar66 = &UNK_00383748 + lVar61;
  pbVar62 = &UNK_00383802 + lVar61;
  bVar6 = *pbVar62;
  pbVar69 = &UNK_00383803 + lVar61;
  bVar7 = *pbVar69;
  pbVar60 = &UNK_00383801 + lVar61;
  bVar8 = *pbVar60;
  pbVar67 = &UNK_00383800 + lVar61;
  bVar9 = *pbVar67;
  uVar25 = (uint)(bVar6 ^ (&UNK_0038376a)[lVar61]) << 0x10 |
           (uint)(bVar7 ^ (&UNK_0038376b)[lVar61]) << 0x18 |
           (uint)(bVar8 ^ (&UNK_00383769)[lVar61]) << 8;
  if ((uVar25 | (bVar9 ^ (&UNK_00383768)[lVar61]) & 0xfe) == 0xfffffffc) {
    iVar15 = 0;
    uVar20 = *puVar45;
    uVar25 = 5;
    do {
      uVar26 = uVar25;
      if (iVar15 != 0) {
        uVar26 = uVar25 + 1;
      }
      pbVar54 = puVar66 + (ulong)uVar26 * 4;
      uVar26 = (uint)(bVar6 ^ pbVar54[2]) << 0x10 | (uint)(bVar7 ^ pbVar54[3]) << 0x18 |
               (uint)(bVar8 ^ pbVar54[1]) << 8 | (uint)(bVar9 ^ *pbVar54);
      if (uVar26 == 0xffffffff) goto LAB_005cb48c;
      iVar15 = iVar15 + 1;
      uVar20 = uVar20 + uVar26;
      uVar25 = uVar25 + 3;
      *puVar45 = uVar20;
    } while (iVar15 != 0xb);
    iVar15 = 0;
LAB_005cb48c:
    iVar19 = func_0x0043ea60();
    *puVar45 = 0;
    *(int *)(&UNK_0032c9f8 + param_1) = iVar19;
    if (iVar15 != 0) {
      bVar6 = *pbVar67;
      iVar22 = 0;
      bVar7 = *pbVar62;
      bVar8 = *pbVar69;
      bVar9 = *pbVar60;
      uVar25 = 0;
      do {
        iVar3 = iVar22;
        if (iVar22 != 0) {
          iVar3 = iVar22 + 1;
        }
        pbVar54 = puVar66 + (ulong)(iVar3 + 5) * 4;
        uVar25 = CONCAT12(bVar7 ^ pbVar54[2],CONCAT11(bVar9 ^ pbVar54[1],bVar6 ^ *pbVar54)) + uVar25
                 + (uint)(bVar8 ^ pbVar54[3]) * 0x1000000;
        *puVar45 = uVar25;
        *(int *)(&UNK_003bb798 + param_1) = iVar3;
        if (iVar19 < (int)uVar25) {
          (&UNK_0038f61c)[param_1] = 0;
          uVar20 = func_0x009ce864(iVar16,uVar5);
          uVar25 = (uint)(*pbVar62 ^ (&UNK_0038376a)[lVar61]) << 0x10 |
                   (uint)(*pbVar69 ^ (&UNK_0038376b)[lVar61]) << 0x18 |
                   (uint)(*pbVar60 ^ (&UNK_00383769)[lVar61]) << 8 |
                   (uint)(*pbVar67 ^ (&UNK_00383768)[lVar61]);
          if ((uVar20 & 1) == 0 && uVar25 == 0xfffffffd) {
            puVar49 = *(undefined8 **)(&UNK_003bb738 + param_1);
            puVar40 = (undefined8 *)(&UNK_003bb738 + param_1);
            while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
              while (puVar30 = puVar49, *(int *)(puVar30 + 4) <= iVar16) {
                if (iVar16 <= *(int *)(puVar30 + 4)) goto LAB_005cc730;
                puVar49 = (undefined8 *)puVar30[1];
                if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
                  puVar40 = puVar30 + 1;
                  puVar43 = puVar30;
                  goto LAB_005cbe70;
                }
              }
              puVar40 = puVar30;
              puVar49 = (undefined8 *)*puVar30;
            }
LAB_005cbe70:
            puVar30 = (undefined8 *)func_0x00bc3330(0x40);
            puVar30[7] = 0;
            *(int *)(puVar30 + 4) = iVar16;
            puVar30[6] = 0;
            puVar30[5] = puVar30 + 6;
            *puVar30 = 0;
            puVar30[1] = 0;
            puVar30[2] = puVar43;
            *puVar40 = puVar30;
            puVar49 = puVar30;
            if (**(long **)(&UNK_003bb730 + param_1) != 0) {
              *(long *)(&UNK_003bb730 + param_1) = **(long **)(&UNK_003bb730 + param_1);
              puVar49 = (undefined8 *)*puVar40;
            }
            func_0x0040a8c0(*(undefined8 *)(&UNK_003bb738 + param_1),puVar49);
            *(long *)(&UNK_003bb740 + param_1) = *(long *)(&UNK_003bb740 + param_1) + 1;
LAB_005cc730:
            puVar40 = puVar30 + 6;
            puVar49 = (undefined8 *)*puVar40;
            while (puVar43 = puVar40, puVar49 != (undefined8 *)0x0) {
              while (puVar40 = puVar49, *(int *)((long)puVar40 + 0x1c) <= (int)uVar5) {
                if ((int)uVar5 <= *(int *)((long)puVar40 + 0x1c)) goto LAB_005cc7d4;
                puVar49 = (undefined8 *)puVar40[1];
                if ((undefined8 *)puVar40[1] == (undefined8 *)0x0) {
                  puVar43 = puVar40 + 1;
                  goto LAB_005cc77c;
                }
              }
              puVar49 = (undefined8 *)*puVar40;
            }
LAB_005cc77c:
            puVar49 = (undefined8 *)func_0x00bc3330(0x28);
            *(undefined1 *)(puVar49 + 4) = 0;
            *puVar49 = 0;
            puVar49[1] = 0;
            *(uint *)((long)puVar49 + 0x1c) = uVar5;
            puVar49[2] = puVar40;
            *puVar43 = puVar49;
            puVar40 = puVar49;
            if (*(long *)puVar30[5] != 0) {
              puVar30[5] = *(long *)puVar30[5];
              puVar40 = (undefined8 *)*puVar43;
            }
            func_0x0040a8c0(puVar30[6],puVar40);
            puVar30[7] = puVar30[7] + 1;
            puVar40 = puVar49;
LAB_005cc7d4:
            *(undefined1 *)(puVar40 + 4) = 1;
            uVar25 = func_0x006d3c94(param_1,*(int *)(&UNK_003bb798 + param_1) + 6,0);
            iVar15 = *(int *)(&UNK_003bb798 + param_1);
            *(uint *)(&UNK_003bb79c + param_1) = uVar25;
            puStack_160 = (uint *)func_0x00bc3330(0x10);
            puStack_158 = puStack_160 + 4;
            *puStack_160 = 0;
            puStack_160[1] = iVar15 + 6;
            puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
            puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
            puStack_160[2] = 0;
            puStack_160[3] = uVar25;
            puStack_150 = puStack_158;
            if (puVar40 < puVar49) {
LAB_005cc834:
              *puVar40 = 0;
              puVar40[1] = 0;
              puVar40[2] = 0;
              puVar40[1] = puStack_150;
              *puVar40 = puStack_160;
              puVar40[2] = puStack_150;
              *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
              puStack_158 = puStack_150;
              goto LAB_005ccdcc;
            }
            uVar27 = func_0x005df9b8(puVar42,&puStack_160);
LAB_005cc86c:
            *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
            goto joined_r0x005cd43c;
          }
          if (uVar25 == 0xfffffffc) {
            uVar25 = func_0x006d3c94(param_1,*(int *)(&UNK_003bb798 + param_1) + 6,0);
            iVar15 = *(int *)(&UNK_003bb798 + param_1);
            *(uint *)(&UNK_003bb79c + param_1) = uVar25;
            puStack_160 = (uint *)func_0x00bc3330(0x10);
            puStack_158 = puStack_160 + 4;
            *puStack_160 = 0;
            puStack_160[1] = iVar15 + 6;
            puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
            puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
            puStack_160[2] = 0;
            puStack_160[3] = uVar25;
            puStack_150 = puStack_158;
            if (puVar40 < puVar49) goto LAB_005cc834;
            uVar27 = func_0x005df9b8(puVar42,&puStack_160);
            goto LAB_005cc86c;
          }
          uVar64 = func_0x005af784(1);
          if ((uVar64 & 1) != 0) {
            (&UNK_0038f61c)[param_1] = 1;
            goto LAB_005ccdcc;
          }
          puVar45[0] = 0;
          puVar45[1] = 0;
          break;
        }
        iVar22 = iVar22 + 3;
      } while (iVar15 * 3 != iVar22);
    }
  }
  else {
    if ((2 < *(int *)(&UNK_00327f0c + param_1) - 4U) || ((&UNK_0032c658)[param_1] != '\0')) {
      if ((((uint)((&UNK_0038375e)[lVar61] ^ bVar6) << 0x10 |
            (uint)((&UNK_0038375f)[lVar61] ^ bVar7) << 0x18 |
            (uint)((&UNK_0038375d)[lVar61] ^ bVar8) << 8 | (uint)((&UNK_0038375c)[lVar61] ^ bVar9))
           != 0xffffffff) && ((&UNK_0032c666)[param_1] == '\0')) {
        if (((int)(uVar25 | bVar9 ^ (&UNK_00383768)[lVar61]) < 0) ||
           ((char)((&UNK_0038376f)[lVar61] ^ bVar7) < '\0')) {
          iVar15 = 1;
        }
        else {
          iVar19 = func_0x005cf74c(puVar66,0xc);
          iVar15 = 2;
          if (-1 < iVar19) {
            iVar15 = 3;
          }
        }
        iVar19 = 0;
        *(undefined4 *)(&UNK_003bb798 + param_1) = 0;
        puVar40 = (undefined8 *)(&UNK_0032c648 + param_1);
        do {
          *(undefined4 *)(&UNK_0032c9fc + param_1) = 0;
          if (iVar19 == 0) {
            uVar14 = 0;
            pbVar54 = &UNK_0038375c + lVar61;
            pbVar56 = &UNK_0038375d + lVar61;
            pbVar58 = &UNK_0038375e + lVar61;
            pbVar59 = &UNK_0038375f + lVar61;
LAB_005cb980:
            *puVar45 = (uint)(*pbVar62 ^ *pbVar58) << 0x10 | (uint)(*pbVar69 ^ *pbVar59) << 0x18 |
                       (uint)(*pbVar60 ^ *pbVar56) << 8 | (uint)(*pbVar67 ^ *pbVar54);
            *(undefined4 *)(&UNK_003bb798 + param_1) = uVar14;
          }
          else {
            if (iVar19 == 1) {
              uVar14 = 4;
              pbVar54 = &UNK_0038376c + lVar61;
              pbVar56 = &UNK_0038376d + lVar61;
              pbVar58 = &UNK_0038376e + lVar61;
              pbVar59 = &UNK_0038376f + lVar61;
              goto LAB_005cb980;
            }
            if (iVar19 == 2) {
              uVar14 = 7;
              pbVar54 = &UNK_00383778 + lVar61;
              pbVar56 = &UNK_00383779 + lVar61;
              pbVar58 = &UNK_0038377a + lVar61;
              pbVar59 = &UNK_0038377b + lVar61;
              goto LAB_005cb980;
            }
          }
          uVar14 = func_0x0043ea60(100);
          *(undefined4 *)(&UNK_0032c9f8 + param_1) = uVar14;
          uVar64 = func_0x005af784(1);
          if (((uVar64 & 1) != 0) &&
             ((*(int *)(&UNK_00327f0c + param_1) == 3 ||
              (uVar64 = func_0x0063fc28(param_1 + 0x12c8), (uVar64 & 1) != 0)))) {
            *puVar45 = 100;
          }
          if (*(int *)(&UNK_0032c9f8 + param_1) < (int)*puVar45) {
            (&UNK_0038f61c)[param_1] = 0;
            if ((&UNK_0032c658)[param_1] == '\0') {
              uVar64 = 1;
              if ((iVar19 != 0) || (*piVar55 == -1)) goto LAB_005ccd9c;
LAB_005cba64:
              if (CONCAT13(*pbVar69 ^ (&UNK_0038376b)[lVar61],
                           CONCAT12(*pbVar62 ^ (&UNK_0038376a)[lVar61],
                                    CONCAT11(*pbVar60 ^ (&UNK_00383769)[lVar61],
                                             *pbVar67 ^ (&UNK_00383768)[lVar61]))) - 1U < 2) {
                if (*piVar55 != -1) {
                  iVar22 = *(int *)(&UNK_00327f0c + param_1);
                  if ((iVar22 == 99) || (iVar22 == 3)) {
                    iVar22 = func_0x007acdd4(uVar5,0);
                    if (iVar22 != 0) {
LAB_005cbb54:
                      if (*piVar55 == -1) goto LAB_005cbbcc;
                      iVar22 = *(int *)(&UNK_00327f0c + param_1);
                      goto LAB_005cbb6c;
                    }
                    iVar22 = *piVar55;
                    uVar14 = func_0x007ac5b8();
                    uVar64 = func_0x009ce3bc(iVar22,uVar5,uVar14,
                                             (uint)(*pbVar62 ^ (&UNK_0038376a)[lVar61]) << 0x10 |
                                             (uint)(*pbVar69 ^ (&UNK_0038376b)[lVar61]) << 0x18 |
                                             (uint)(*pbVar60 ^ (&UNK_00383769)[lVar61]) << 8 |
                                             (uint)(*pbVar67 ^ (&UNK_00383768)[lVar61]),uVar17 & 1);
                    if ((uVar64 & 1) != 0) goto LAB_005cbb54;
                    iVar15 = *piVar55;
                    uVar14 = func_0x007ac5b8();
                    uVar25 = func_0x005cf74c(puVar66,8);
LAB_005ccb54:
                    uVar64 = 1;
                    func_0x009ce698(iVar15,uVar5,uVar14,uVar25,1,uVar17 & 1);
                    goto LAB_005ccd9c;
                  }
LAB_005cbb6c:
                  if (((iVar22 == 99) || (iVar22 == 3)) &&
                     ((iVar22 = func_0x007acdd4(uVar5,0), iVar22 == 1 ||
                      ((iVar22 = func_0x007acdd4(uVar5,0), iVar22 == 2 ||
                       (iVar22 = func_0x007acdd4(uVar5,0), iVar22 == 3)))))) {
                    func_0x007accc4(uVar5,0);
                    uVar64 = func_0x006efe3c();
                    if ((uVar64 & 1) == 0) {
                      iVar15 = *piVar55;
                      uVar14 = func_0x007ac5b8();
                      uVar25 = (uint)(*pbVar62 ^ (&UNK_0038376a)[lVar61]) << 0x10 |
                               (uint)(*pbVar69 ^ (&UNK_0038376b)[lVar61]) << 0x18 |
                               (uint)(*pbVar60 ^ (&UNK_00383769)[lVar61]) << 8 |
                               (uint)(*pbVar67 ^ (&UNK_00383768)[lVar61]);
                      goto LAB_005ccb54;
                    }
                  }
                }
LAB_005cbbcc:
                iVar22 = *(int *)(&UNK_00327f0c + param_1);
                if ((iVar22 != 3) && (puVar49 = puVar40, (&UNK_0032c658)[param_1] != '\0')) {
                  while (puVar43 = (undefined8 *)*puVar49, puVar30 = puVar49,
                        (undefined8 *)*puVar49 != (undefined8 *)0x0) {
                    while (puVar30 = puVar43, puVar49 = puVar30, *(int *)(puVar30 + 4) <= iVar22) {
                      if (iVar22 <= *(int *)(puVar30 + 4)) goto LAB_005cbc84;
                      puVar43 = (undefined8 *)puVar30[1];
                      if ((undefined8 *)puVar30[1] == (undefined8 *)0x0) {
                        puVar49 = puVar30 + 1;
                        goto LAB_005cbc1c;
                      }
                    }
                  }
LAB_005cbc1c:
                  puVar35 = (undefined8 *)func_0x00bc3330(0x40);
                  *(int *)(puVar35 + 4) = iVar22;
                  puVar35[7] = 0;
                  puVar35[6] = 0;
                  puVar35[5] = puVar35 + 6;
                  *puVar35 = 0;
                  puVar35[1] = 0;
                  puVar35[2] = puVar30;
                  *puVar49 = puVar35;
                  puVar43 = puVar35;
                  if (**(long **)(&UNK_0032c640 + param_1) != 0) {
                    *(long *)(&UNK_0032c640 + param_1) = **(long **)(&UNK_0032c640 + param_1);
                    puVar43 = (undefined8 *)*puVar49;
                  }
                  func_0x0040a8c0(*(undefined8 *)(&UNK_0032c648 + param_1),puVar43);
                  *(long *)(&UNK_0032c650 + param_1) = *(long *)(&UNK_0032c650 + param_1) + 1;
                  puVar30 = puVar35;
LAB_005cbc84:
                  puVar49 = puVar30 + 6;
                  puVar43 = (undefined8 *)*puVar49;
                  while (puVar35 = puVar49, puVar43 != (undefined8 *)0x0) {
                    while (puVar49 = puVar43, *(int *)((long)puVar49 + 0x1c) <= (int)uVar5) {
                      if ((int)uVar5 <= *(int *)((long)puVar49 + 0x1c)) {
                        cVar10 = *(char *)(puVar49 + 4);
                        goto joined_r0x005cbd30;
                      }
                      puVar43 = (undefined8 *)puVar49[1];
                      if ((undefined8 *)puVar49[1] == (undefined8 *)0x0) {
                        puVar35 = puVar49 + 1;
                        goto LAB_005cbccc;
                      }
                    }
                    puVar43 = (undefined8 *)*puVar49;
                  }
LAB_005cbccc:
                  puVar43 = (undefined8 *)func_0x00bc3330(0x28);
                  *(undefined1 *)(puVar43 + 4) = 0;
                  *puVar43 = 0;
                  puVar43[1] = 0;
                  *(uint *)((long)puVar43 + 0x1c) = uVar5;
                  puVar43[2] = puVar49;
                  *puVar35 = puVar43;
                  puVar49 = puVar43;
                  if (*(long *)puVar30[5] != 0) {
                    puVar30[5] = *(long *)puVar30[5];
                    puVar49 = (undefined8 *)*puVar35;
                  }
                  func_0x0040a8c0(puVar30[6],puVar49);
                  puVar30[7] = puVar30[7] + 1;
                  cVar10 = *(char *)(puVar43 + 4);
joined_r0x005cbd30:
                  if (cVar10 == '\0') {
                    uVar14 = *(undefined4 *)(&UNK_00327f0c + param_1);
                    uVar18 = func_0x00a206ac(uVar14,uVar5);
                    uVar64 = func_0x00a20824(uVar14,uVar18);
                    uVar64 = uVar64 & 0xffffffff;
                    iVar15 = *(int *)(&UNK_00327f0c + param_1);
                    puVar49 = (undefined8 *)*puVar40;
                    puVar43 = puVar40;
                    if ((undefined8 *)*puVar40 == (undefined8 *)0x0) goto LAB_005cca70;
                    goto LAB_005cca4c;
                  }
                }
                uVar64 = func_0x005af784(1);
                if ((uVar64 & 1) == 0) goto LAB_005cb924;
                (&UNK_0038f61c)[param_1] = 1;
                goto LAB_005ccdcc;
              }
            }
            else if (iVar19 == 0) goto LAB_005cba64;
            uVar64 = 1;
            goto LAB_005ccd9c;
          }
LAB_005cb924:
          iVar19 = iVar19 + 1;
        } while (iVar19 != iVar15);
        goto LAB_005ccdd0;
      }
    }
    uVar64 = func_0x0078a1b4(param_1);
    if (((uVar64 & 1) != 0) && ((&UNK_0032c666)[param_1] != '\0')) {
      (&UNK_0032c669)[param_1] = 1;
      func_0x0080d4f4(param_1);
      uVar64 = (ulong)puStack_160 >> 0x18;
      puStack_160 = (uint *)CONCAT53((uint5)uVar64 & 0xffffffff00,0x303104);
      bStack_a0 = 0x2a;
      uStack_97 = 0xaa;
      uStack_96 = 0x83e3;
      sStack_94 = 0xe390;
      uStack_9f = 0xe3;
      uStack_9e = 0x9583;
      uStack_9c = 0xe3;
      uStack_9b = 0x82;
      uStack_9a = 0xa3;
      uStack_99 = 0xe3;
      bStack_98 = 0x83;
      sStack_92 = 0xb982;
      bStack_90 = 0xe3;
      uStack_8f = 0xbc83e3bf82;
      uStack_8a = 0;
      func_0x00a0a85c(1,&puStack_160,&bStack_a0);
      if ((bStack_a0 & 1) != 0) {
        func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
      }
      if (((ulong)puStack_160 & 1) != 0) {
        func_0x00bc3350(puStack_150);
      }
      bStack_a0 = 0x2a;
      puStack_160 = (uint *)CONCAT44(puStack_160._4_4_,0x303104);
      uStack_97 = 0xaa;
      uStack_96 = 0x83e3;
      sStack_94 = -0x1c70;
      uStack_9f = 0xe3;
      uStack_9e = 0x9583;
      uStack_9c = 0xe3;
      uStack_9b = 0x82;
      uStack_9a = 0xa3;
      uStack_99 = 0xe3;
      bStack_98 = 0x83;
      sStack_92 = -0x467e;
      bStack_90 = 0xe3;
      uStack_8f = 0xbc83e3bf82;
      uStack_8a = 0;
      func_0x00a0a85c(0x21,&puStack_160,&bStack_a0);
      if ((bStack_a0 & 1) != 0) {
        func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
      }
      if (((ulong)puStack_160 & 1) != 0) {
        func_0x00bc3350(puStack_150);
      }
      lVar63 = func_0x007fd748();
      iVar15 = func_0x006efac4(&UNK_0032b880 + lVar63,0x1ce);
      if (iVar15 != -1) {
        lVar63 = func_0x007fd748();
        lVar34 = func_0x007fd748();
        iVar15 = func_0x006efac4(&UNK_0032b880 + lVar34,0x1ce);
        *(undefined4 *)(&UNK_0038efd4 + lVar63 + (long)iVar15 * 4) = 1;
      }
      lVar63 = func_0x007fd748();
      *(undefined4 *)(lVar63 + 0x4a418) = 1;
      puStack_160 = (uint *)func_0x00bc3330(4);
      puStack_158 = puStack_160 + 1;
      *puStack_160 = 7;
      puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
      puStack_150 = puStack_158;
      if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
        *puVar40 = 0;
        puVar40[1] = 0;
        puVar40[2] = 0;
        puVar40[1] = puStack_158;
        *puVar40 = puStack_160;
        puVar40[2] = puStack_158;
        *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
      }
      else {
        uVar27 = func_0x005df9b8(puVar42,&puStack_160);
        *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
        if (puStack_160 != (uint *)0x0) {
          puStack_158 = puStack_160;
          func_0x00bc3350();
        }
      }
    }
  }
LAB_005ccdd0:
  if (((&UNK_0032c658)[param_1] == '\0') && ((param_2 & 1) == 0)) {
    uVar27 = *(undefined8 *)(param_1 + 0x7c0);
    *(undefined8 *)(&UNK_003bb7c0 + param_1) = 0xffffffffffffffff;
    *(undefined8 *)(&UNK_003bb7a8 + param_1) = 0xffffffffffffffff;
    *(undefined8 *)(&UNK_003bb7a0 + param_1) = 0xffffffffffffffff;
    *(undefined8 *)(&UNK_003bb7b8 + param_1) = 0xffffffffffffffff;
    *(undefined8 *)(&UNK_003bb7b0 + param_1) = 0xffffffffffffffff;
    uVar64 = func_0x009d0178(uVar27);
    if ((uVar64 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x836e0) = 0;
    }
    if (((uint)(*pbVar62 ^ (&UNK_00383786)[lVar61]) << 0x10 |
         (uint)(*pbVar69 ^ (&UNK_00383787)[lVar61]) << 0x18 |
         (uint)(*pbVar60 ^ (&UNK_00383785)[lVar61]) << 8 |
        (uint)(*pbVar67 ^ (&UNK_00383784)[lVar61])) == 1) {
      if (*(int *)(&UNK_00327f0c + param_1) - 4U < 3) {
        piVar55 = (int *)(&UNK_003bbb80 +
                         param_1 + (ulong)(*(int *)(&UNK_00327f0c + param_1) - 4U) * 0xcc +
                         (long)(int)*puVar1 * 4);
      }
      else {
        if (*(int *)(&UNK_003bb794 + param_1) == -1) goto LAB_005cd65c;
        piVar55 = (int *)(&UNK_003afae0 +
                         param_1 + (long)*(int *)(&UNK_003bb794 + param_1) * 0xf0 +
                         (long)(int)*puVar1 * 0x10 + (long)*(int *)(&UNK_0038ff5c + param_1) * 4);
      }
      uVar25 = *(uint *)(param_1 + 0x836fc);
      iVar15 = *piVar55;
      if ((int)uVar25 < 0x2329) {
        iVar19 = 10000 - uVar25;
      }
      else if (uVar25 >> 3 < 0x947) {
        iVar19 = 1000 - (uVar25 - 9000 & 0xffff) / 10;
      }
      else {
        iVar19 = 0;
      }
      uVar25 = *puVar1;
      *(int *)(param_1 + 0x836dc) = iVar19;
      if (iVar15 < iVar19) {
        lVar61 = param_1 + (long)(int)uVar25 * 0xbc;
        bVar6 = (&UNK_00383802)[lVar61];
        bVar7 = (&UNK_00383803)[lVar61];
        bVar8 = (&UNK_00383801)[lVar61];
        bVar9 = (&UNK_00383800)[lVar61];
        if (((uint)(bVar6 ^ (&UNK_00383796)[lVar61]) << 0x10 |
             (uint)(bVar7 ^ (&UNK_00383797)[lVar61]) << 0x18 |
             (uint)(bVar8 ^ (&UNK_00383795)[lVar61]) << 8 | (uint)(bVar9 ^ (&UNK_00383794)[lVar61]))
            == 0xffffffff) {
          lVar63 = 1;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837a2)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837a3)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837a1)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837a0)[lVar61])) == 0xffffffff) {
          lVar63 = 2;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837ae)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837af)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837ad)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837ac)[lVar61])) == 0xffffffff) {
          lVar63 = 3;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837ba)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837bb)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837b9)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837b8)[lVar61])) == 0xffffffff) {
          lVar63 = 4;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837c6)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837c7)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837c5)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837c4)[lVar61])) == 0xffffffff) {
          lVar63 = 5;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837d2)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837d3)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837d1)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837d0)[lVar61])) == 0xffffffff) {
          lVar63 = 6;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837de)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837df)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837dd)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837dc)[lVar61])) == 0xffffffff) {
          lVar63 = 7;
        }
        else if (((uint)(bVar6 ^ (&UNK_003837ea)[lVar61]) << 0x10 |
                  (uint)(bVar7 ^ (&UNK_003837eb)[lVar61]) << 0x18 |
                  (uint)(bVar8 ^ (&UNK_003837e9)[lVar61]) << 8 |
                 (uint)(bVar9 ^ (&UNK_003837e8)[lVar61])) == 0xffffffff) {
          lVar63 = 8;
        }
        else {
          lVar63 = 9;
          if (((uint)(bVar6 ^ (&UNK_003837f6)[lVar61]) << 0x10 |
               (uint)(bVar7 ^ (&UNK_003837f7)[lVar61]) << 0x18 |
               (uint)(bVar8 ^ (&UNK_003837f5)[lVar61]) << 8 |
              (uint)(bVar9 ^ (&UNK_003837f4)[lVar61])) != 0xffffffff) {
            lVar63 = 10;
          }
        }
        puVar68 = &UNK_00383788 + (long)(int)uVar5 * 0xbc;
        lVar61 = 0;
        puVar66 = &UNK_003bb7a0;
        do {
          pbVar54 = puVar68 + param_1;
          uVar25 = (uint)(*pbVar62 ^ pbVar54[2]) << 0x10 | (uint)(*pbVar69 ^ pbVar54[3]) << 0x18 |
                   (uint)(*pbVar60 ^ pbVar54[1]) << 8 | (uint)(*pbVar67 ^ *pbVar54);
          if ((int)uVar25 <= *(int *)(param_1 + 0x836dc) && iVar15 < (int)uVar25) {
            uVar25 = func_0x006d3c94(param_1,lVar61 + 0x11U & 0xffffffff,1);
            *(uint *)(puVar66 + param_1) = uVar25;
            if (uVar25 != 1) {
              puStack_160 = (uint *)func_0x00bc3330(0x10);
              puStack_158 = puStack_160 + 4;
              puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
              puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
              *puStack_160 = 0;
              puStack_160[1] = (uint)(lVar61 + 0x11U);
              puStack_160[2] = 1;
              puStack_160[3] = uVar25;
              puStack_150 = puStack_158;
              if (puVar40 < puVar49) {
                *puVar40 = 0;
                puVar40[1] = 0;
                puVar40[2] = 0;
                puVar40[1] = puStack_158;
                *puVar40 = puStack_160;
                puVar40[2] = puStack_158;
                *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
              }
              else {
                uVar27 = func_0x005df9b8(puVar42,&puStack_160);
                *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
                if (puStack_160 != (uint *)0x0) {
                  puStack_158 = puStack_160;
                  func_0x00bc3350();
                }
              }
            }
          }
          lVar61 = lVar61 + 3;
          puVar66 = puVar66 + 4;
          puVar68 = puVar68 + 0xc;
        } while (lVar63 * 3 != lVar61);
        if (*(int *)(&UNK_00327f0c + param_1) - 4U < 3) {
          iVar19 = *(int *)(param_1 + 0x836dc);
          lVar61 = param_1 + (ulong)(*(int *)(&UNK_00327f0c + param_1) - 4U) * 0xcc +
                   (long)(int)*puVar1 * 4;
          uVar25 = 0x3bbb80;
LAB_005cd60c:
          *(int *)(lVar61 + (ulong)uVar25) = iVar19;
        }
        else {
          iVar19 = *(int *)(param_1 + 0x836dc);
          if (*(int *)(&UNK_003bb794 + param_1) != -1) {
            uVar25 = 0x3afae0;
            lVar61 = param_1 + (long)*(int *)(&UNK_003bb794 + param_1) * 0xf0 +
                     (long)(int)*puVar1 * 0x10 + (long)*(int *)(&UNK_0038ff5c + param_1) * 4;
            goto LAB_005cd60c;
          }
        }
        uVar25 = *puVar1;
        *(undefined4 *)(param_1 + 0x836e0) = 1;
      }
      func_0x007d78f4(&UNK_0032c0b8 + param_1,0x12,
                      *(int *)(&UNK_003bb794 + param_1) * 1000 + uVar25 * 10 +
                      *(int *)(&UNK_0038ff5c + param_1),iVar19,0,0);
    }
  }
LAB_005cd65c:
  if ((*(int *)(&UNK_00327f0c + param_1) != 3) && (*(int *)(&UNK_00327f0c + param_1) != 99)) {
    if (*(int *)(param_1 + 0xc2f4) == 0 && *puVar1 == 0) {
      *(undefined4 *)(param_1 + 0xc2f4) = 1;
    }
    puVar45[0] = 0;
    puVar45[1] = 0;
    *(undefined4 *)(&UNK_0032c9fc + param_1) = 0;
    *(undefined8 *)(param_1 + 0x836cc) = 0xffffffff00000000;
    uVar27 = *(undefined8 *)(param_1 + 0x21b0);
    if ((DAT_0107c750 & 1) == 0) {
      puStack_158 = puRam000000000107c758;
      puStack_160 = (uint *)CONCAT71(uRam000000000107c751,DAT_0107c750);
      puStack_150 = puRam000000000107c760;
    }
    else {
      func_0x0040a850(&puStack_160,puRam000000000107c760,puRam000000000107c758);
    }
    uStack_9b = 0;
    bStack_a0 = 8;
    uStack_9f = 0x61;
    uStack_9e = 0x6572;
    uStack_9c = 0x61;
    uVar14 = func_0x0097a5e0(uVar27,&puStack_160,&bStack_a0,1,9);
    if ((bStack_a0 & 1) != 0) {
      func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
    }
    uVar64 = func_0x0097a5a4(*(undefined4 *)(&UNK_00327f0c + param_1),uVar14);
    if ((uVar64 & 1) == 0) {
LAB_005cd840:
      uVar25 = 0x23;
      uVar20 = 0x32;
      uVar26 = 0x46;
    }
    else {
      uStack_97 = 0;
      bStack_a0 = 0x10;
      uStack_9f = 0x74;
      uStack_9e = 0x6572;
      uStack_9c = 0x61;
      uStack_9b = 0x73;
      uStack_9a = 0x75;
      uStack_99 = 0x72;
      bStack_98 = 0x65;
      uVar25 = func_0x0097a5e0(uVar27,&puStack_160,&bStack_a0,0x23,100);
      if ((bStack_a0 & 1) != 0) {
        func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
      }
      bStack_a0 = 0xc;
      uStack_9f = 0x7a;
      uStack_9e = 0x6d6f;
      uStack_9c = 0x62;
      uStack_9b = 0x69;
      uStack_9a = 0x65;
      uStack_99 = 0;
      uVar20 = func_0x0097a5e0(uVar27,&puStack_160,&bStack_a0,0x32,100);
      if ((bStack_a0 & 1) != 0) {
        func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
      }
      uStack_97 = 0;
      bStack_a0 = 0x10;
      uStack_9f = 0x66;
      uStack_9e = 0x7365;
      uStack_9c = 0x74;
      uStack_9b = 0x69;
      uStack_9a = 0x76;
      uStack_99 = 0x61;
      bStack_98 = 0x6c;
      uVar26 = func_0x0097a5e0(uVar27,&puStack_160,&bStack_a0,0x46,100);
      if ((bStack_a0 & 1) != 0) {
        func_0x00bc3350(CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90))));
      }
      if (((int)uVar20 <= (int)uVar25) || ((int)uVar26 <= (int)uVar20)) goto LAB_005cd840;
    }
    if (((ulong)puStack_160 & 1) != 0) {
      func_0x00bc3350(puStack_150);
    }
    uVar14 = *(undefined4 *)(&UNK_00327f0c + param_1);
    *puVar45 = uVar25;
    uVar18 = func_0x00a206ac(uVar14,uVar5);
    uVar64 = func_0x00a20824(uVar14,uVar18);
    if ((uVar64 & 1) != 0) {
      *puVar45 = uVar20;
    }
    if (((((&UNK_0032c975)[param_1] != '\0') &&
         (lVar61 = param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 4,
         0x18 < (int)((uint)(*(byte *)(param_1 + 0xc986) ^ *(byte *)(lVar61 + 0xc95e)) << 0x10 |
                      (uint)(*(byte *)(param_1 + 0xc987) ^ *(byte *)(lVar61 + 0xc95f)) << 0x18 |
                      (uint)(*(byte *)(param_1 + 0xc985) ^ *(byte *)(lVar61 + 0xc95d)) << 8 |
                     (uint)(*(byte *)(param_1 + 0xc984) ^ *(byte *)(lVar61 + 0xc95c))))) &&
        (0 < *(int *)(param_1 + 0xc2f4))) && (*puVar1 == *(uint *)(&UNK_0032c798 + lVar61))) {
      *puVar45 = uVar26;
    }
    uVar64 = func_0x0080ddb4(param_1);
    if ((uVar64 & 1) != 0) {
      *puVar45 = uVar26;
    }
    uVar64 = func_0x005af784(1);
    if ((uVar64 & 1) != 0) {
      *puVar45 = 100;
    }
    iVar15 = func_0x007ac230(0);
    if ((iVar15 == 3000) && (iVar15 = func_0x007ac380(), iVar15 < 3)) {
      *puVar45 = 100;
    }
    iVar15 = func_0x0043ea60(100);
    *(int *)(&UNK_0032c9f8 + param_1) = iVar15;
    if (iVar15 < (int)*puVar45) {
      uVar20 = func_0x0043ea60(100);
      lVar61 = param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 200;
      pbVar60 = (byte *)(lVar61 + 0xd1a8 + (long)*(int *)(param_1 + 0x836d4) * 4);
      bVar6 = *(byte *)(lVar61 + 0xd26e);
      bVar7 = *(byte *)(lVar61 + 0xd26f);
      *(uint *)(&UNK_0032c9fc + param_1) = uVar20;
      uVar25 = (uint)(bVar6 ^ pbVar60[2]) << 0x10 | (uint)(bVar7 ^ pbVar60[3]) << 0x18 |
               (uint)(*(byte *)(lVar61 + 0xd26d) ^ pbVar60[1]) << 8 |
               (uint)(*(byte *)(lVar61 + 0xd26c) ^ *pbVar60);
      if (uVar25 == 1) {
        uVar14 = 2;
        if (0x45 < (int)uVar20) {
          uVar14 = 3;
        }
      }
      else if (uVar25 == 0) {
        if ((int)uVar20 < 0x2d) {
          uVar14 = 1;
        }
        else {
          uVar14 = 2;
          if (0x4a < uVar20) {
            uVar14 = 3;
          }
        }
      }
      else {
        uVar14 = 3;
      }
      *(undefined4 *)(param_1 + 0x836cc) = uVar14;
      uVar64 = func_0x005af784(1);
      if ((uVar64 & 1) != 0) {
        lVar61 = param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 200;
        pbVar60 = (byte *)(lVar61 + 0xd1a8 + (long)*(int *)(param_1 + 0x836d4) * 4);
        if ((((uint)(*(byte *)(lVar61 + 0xd26e) ^ pbVar60[2]) << 0x10 |
              (uint)(*(byte *)(lVar61 + 0xd26f) ^ pbVar60[3]) << 0x18 |
              (uint)(*(byte *)(lVar61 + 0xd26d) ^ pbVar60[1]) << 8 |
             (uint)(*(byte *)(lVar61 + 0xd26c) ^ *pbVar60)) == 3) ||
           ((iVar15 = func_0x007ac230(0), iVar15 == 3000 && (iVar15 = func_0x007ac380(), iVar15 < 3)
            ))) {
          uVar14 = 0;
          (&UNK_0038f61c)[param_1] = 1;
          *(undefined4 *)(&UNK_0032c9fc + param_1) = 1;
        }
        else {
          uVar14 = 3;
        }
        *(undefined4 *)(param_1 + 0x836cc) = uVar14;
      }
      if (*(int *)(param_1 + 0xc2f4) == 1) {
        *(undefined4 *)(param_1 + 0xc2f4) = 2;
      }
      iVar15 = func_0x007ac230(0);
      if ((iVar15 == 3000) && (iVar15 = func_0x007ac380(), iVar15 < 3)) {
        *(undefined4 *)(param_1 + 0x836cc) = 3;
      }
      lVar61 = param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 200;
      pbVar60 = (byte *)(lVar61 + 0xd1a8 + (long)*(int *)(param_1 + 0x836d4) * 4);
      bVar6 = *(byte *)(lVar61 + 0xd26e);
      bVar7 = *(byte *)(lVar61 + 0xd26f);
      bVar8 = *(byte *)(lVar61 + 0xd26d);
      iVar15 = *(int *)(param_1 + 0x836cc);
      if ((int)((uint)(bVar6 ^ pbVar60[2]) << 0x10 | (uint)(bVar7 ^ pbVar60[3]) << 0x18 |
                (uint)(bVar8 ^ pbVar60[1]) << 8 | (uint)(*(byte *)(lVar61 + 0xd26c) ^ *pbVar60)) <
          iVar15) {
        *pbVar60 = *(byte *)(lVar61 + 0xd26c) ^ (byte)iVar15;
        pbVar60[1] = bVar8 ^ (byte)((uint)iVar15 >> 8);
        pbVar60[2] = bVar6 ^ (byte)((uint)iVar15 >> 0x10);
        pbVar60[3] = bVar7 ^ (byte)((uint)iVar15 >> 0x18);
        puStack_160 = (uint *)func_0x00bc3330(4);
        puStack_158 = puStack_160 + 1;
        *puStack_160 = 1;
        puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
        puStack_150 = puStack_158;
        if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
          *puVar40 = 0;
          puVar40[1] = 0;
          puVar40[2] = 0;
          puVar40[1] = puStack_158;
          *puVar40 = puStack_160;
          puVar40[2] = puStack_158;
          *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
        }
        else {
          uVar27 = func_0x005df9b8(puVar42,&puStack_160);
          *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
          if (puStack_160 != (uint *)0x0) {
            puStack_158 = puStack_160;
            func_0x00bc3350();
          }
        }
        puVar66 = &UNK_00290568 + param_1;
        if (0 < (int)((ulong)(*(long *)((long)(puVar66 +
                                              (long)*(int *)(&UNK_00327f0c + param_1) * 0x18) + 8) -
                             *(long *)(puVar66 + (long)*(int *)(&UNK_00327f0c + param_1) * 0x18)) >>
                     4) * -0x55555555) {
          uVar25 = 0;
          do {
            lVar61 = 0;
            while( true ) {
              func_0x00a1f908(&puStack_160,puVar66,*(undefined4 *)(&UNK_00327f0c + param_1),uVar25);
              lVar63 = (long)(int)puStack_160;
              if (puStack_158 != (uint *)0x0) {
                puStack_150 = puStack_158;
                func_0x00bc3350();
              }
              if (lVar63 <= lVar61) break;
              func_0x00a1f908(&puStack_160,puVar66,*(undefined4 *)(&UNK_00327f0c + param_1),uVar25);
              uVar26 = puStack_158[lVar61];
              uVar20 = *(uint *)(param_1 + 0x836d4);
              puStack_150 = puStack_158;
              func_0x00bc3350();
              lVar61 = lVar61 + 1;
              if (uVar26 == uVar20) {
                if (*(int *)(param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 0x2c +
                             (ulong)uVar25 * 4 + 0x83718) == 0) {
                  func_0x00808488(param_1);
                  if (*(int *)(param_1 + (long)*(int *)(&UNK_00327f0c + param_1) * 0x2c +
                               (ulong)uVar25 * 4 + 0x83718) == 0) {
                    func_0x00808488();
                  }
                  else {
                    *(uint *)(param_1 + 0x836d0) = uVar25;
                  }
                }
                goto LAB_005cdddc;
              }
            }
            uVar25 = uVar25 + 1;
          } while ((int)uVar25 <
                   (int)((ulong)(*(long *)((long)(puVar66 +
                                                 (long)*(int *)(&UNK_00327f0c + param_1) * 0x18) + 8
                                          ) -
                                *(long *)(puVar66 + (long)*(int *)(&UNK_00327f0c + param_1) * 0x18))
                        >> 4) * -0x55555555);
        }
LAB_005cdddc:
        puVar45[0] = 0;
        puVar45[1] = 100;
      }
    }
  }
  iVar15 = func_0x007abd78(0);
  if (iVar15 == -6) {
    iVar15 = 30000 - *(int *)(param_1 + 0x836fc);
    iVar15 = iVar15 * iVar15;
    if (29999 < *(int *)(param_1 + 0x836fc)) {
      iVar15 = 0;
    }
    *(int *)(param_1 + 0x32cc) = iVar15;
    iVar19 = func_0x007ac380();
    if (*(int *)(&UNK_00382530 + param_1 + (long)iVar19 * 4) < iVar15) {
      uVar14 = *(undefined4 *)(param_1 + 0x32cc);
      iVar15 = func_0x007ac380();
      *(undefined4 *)(&UNK_00382530 + param_1 + (long)iVar15 * 4) = uVar14;
    }
  }
  uVar14 = *(undefined4 *)(&UNK_00327f0c + param_1);
  uVar18 = *(undefined4 *)(&UNK_0038ff5c + param_1);
  iVar15 = func_0x007abd78(0);
  if (iVar15 == -0xb) {
    iVar16 = func_0x007ac380();
    iVar16 = *(int *)(&UNK_00381ef0 + (long)iVar16 * 4 + param_1);
    iVar15 = func_0x007ac380();
    uVar5 = *(int *)(&UNK_00381ef0 + (long)iVar15 * 4 + param_1) % 100;
    iVar16 = iVar16 / 100;
  }
  func_0x007bc478(&puStack_160,&UNK_0032c670 + param_1,uVar14,iVar16,uVar5,uVar18);
  puVar45 = puStack_160;
  if (0 < (int)((ulong)((long)puStack_158 - (long)puStack_160) >> 2)) {
    uVar64 = 0;
LAB_005cdf14:
    if (*(int *)((long)puStack_160 + uVar64) == 0) goto code_r0x005cdf1c;
    lVar61 = 0;
    puVar53 = puStack_158;
    do {
      if (0 < (int)puVar45[lVar61]) {
        iVar16 = 0;
        do {
          puVar33 = (undefined4 *)func_0x00bc3330(4);
          bStack_a0 = (byte)puVar33;
          uStack_9f = (undefined1)((ulong)puVar33 >> 8);
          uStack_9e = (undefined2)((ulong)puVar33 >> 0x10);
          uStack_9c = (undefined1)((ulong)puVar33 >> 0x20);
          uStack_9b = (undefined1)((ulong)puVar33 >> 0x28);
          uStack_9a = (undefined1)((ulong)puVar33 >> 0x30);
          uStack_99 = (undefined1)((ulong)puVar33 >> 0x38);
          puVar37 = puVar33 + 1;
          *puVar33 = (int)lVar61;
          plVar52 = *(long **)(&UNK_0032c6a8 + param_1);
          bStack_98 = (byte)puVar37;
          uStack_97 = (undefined1)((ulong)puVar37 >> 8);
          uStack_96 = (undefined2)((ulong)puVar37 >> 0x10);
          sStack_94 = (short)((ulong)puVar37 >> 0x20);
          sStack_92 = (short)((ulong)puVar37 >> 0x30);
          uStack_8f = (undefined5)((ulong)puVar37 >> 8);
          uStack_8a = (undefined1)((ulong)puVar37 >> 0x30);
          uStack_89 = (undefined1)((ulong)puVar37 >> 0x38);
          bStack_90 = bStack_98;
          if (plVar52 < *(long **)(&UNK_0032c6b0 + param_1)) {
            *plVar52 = 0;
            plVar52[1] = 0;
            plVar52[2] = 0;
            plVar52[1] = (long)puVar37;
            *plVar52 = (long)puVar33;
            plVar52[2] = (long)puVar37;
            *(long **)(&UNK_0032c6a8 + param_1) = plVar52 + 3;
          }
          else {
            uVar27 = func_0x005df9b8(&UNK_0032c6a0 + param_1,&bStack_a0);
            uVar12 = CONCAT15(uStack_9b,
                              CONCAT14(uStack_9c,CONCAT22(uStack_9e,CONCAT11(uStack_9f,bStack_a0))))
            ;
            lVar63 = CONCAT17(uStack_99,CONCAT16(uStack_9a,uVar12));
            *(undefined8 *)(&UNK_0032c6a8 + param_1) = uVar27;
            if (lVar63 != 0) {
              bStack_98 = bStack_a0;
              uStack_97 = uStack_9f;
              uStack_96 = uStack_9e;
              sStack_94 = (short)((uint6)uVar12 >> 0x20);
              sStack_92 = (short)((ulong)lVar63 >> 0x30);
              func_0x00bc3350();
            }
          }
          iVar16 = iVar16 + 1;
          puVar45 = puStack_160;
          puVar53 = puStack_158;
        } while (iVar16 < (int)puStack_160[lVar61]);
      }
      lVar61 = lVar61 + 1;
    } while (lVar61 < (int)((ulong)((long)puVar53 - (long)puVar45) >> 2));
    bStack_a0 = 6;
    uStack_9f = 0;
    uStack_9e = 0;
    func_0x0046fe84(&puStack_160,puVar45,&bStack_a0);
    puVar45 = puStack_160;
    plVar52 = *(long **)(&UNK_0032c690 + param_1);
    if (plVar52 < *(long **)(&UNK_0032c698 + param_1)) {
      *plVar52 = 0;
      plVar52[1] = 0;
      plVar52[2] = 0;
      lVar61 = (long)puStack_158 - (long)puStack_160;
      if (lVar61 == 0) {
LAB_005ce050:
        plVar52 = plVar52 + 3;
        *(long **)(&UNK_0032c690 + param_1) = plVar52;
        goto LAB_005ce070;
      }
      puVar28 = puStack_160;
      if (-1 < lVar61) {
        lVar63 = func_0x00bc3330(lVar61);
        *plVar52 = lVar63;
        plVar52[1] = lVar63;
        plVar52[2] = lVar63 + lVar61;
        func_0x00bc35f0(lVar63,puVar45,lVar61);
        plVar52[1] = lVar63 + lVar61;
        goto LAB_005ce050;
      }
LAB_005ceecc:
      if (*(long *)(lVar11 + 0x28) != lStack_88) goto LAB_005cf480;
      func_0x00441cdc(plVar52);
      goto LAB_005ceee8;
    }
    plVar52 = (long *)func_0x005dfbc4(puVar42,&puStack_160);
LAB_005ce070:
    *(long **)(&UNK_0032c690 + param_1) = plVar52;
    puVar45 = puStack_160;
    if ((int)((ulong)((long)puStack_158 - (long)puStack_160) >> 2) < 2) goto LAB_005ce0e0;
    iVar16 = 0;
    lVar61 = 1;
    puVar53 = puStack_158;
    while (puVar45[lVar61] == 0) {
LAB_005ce09c:
      lVar61 = lVar61 + 1;
      if ((int)((ulong)((long)puVar53 - (long)puVar45) >> 2) <= lVar61) goto LAB_005ce0e0;
    }
    if (iVar16 < 4) {
      uVar27 = func_0x006e447c(7,(int)lVar61 + -1);
      func_0x006e3770(uVar27,puStack_160[lVar61],0);
      iVar16 = iVar16 + 1;
      puVar45 = puStack_160;
      puVar53 = puStack_158;
      goto LAB_005ce09c;
    }
    goto LAB_005ce0e4;
  }
LAB_005ce0e0:
  if (puVar45 != (uint *)0x0) {
LAB_005ce0e4:
    puStack_158 = puVar45;
    func_0x00bc3350(puVar45);
  }
  iVar16 = func_0x007abd78(0);
  if (*(int *)(&UNK_00327f0c + param_1) == 3) {
    if ((*(char *)(param_1 + 0x32c9) == '\0') &&
       ((0xd < iVar16 + 0x13U || ((1 << (ulong)(iVar16 + 0x13U & 0x1f) & 0x2205U) == 0)))) {
      func_0x006f8570(param_1 + 0x17f0);
      uVar14 = func_0x007ac614(*(undefined4 *)(&UNK_00325c58 + param_1),(&UNK_0032c97b)[param_1]);
      func_0x006f6900(param_1 + 0x17f0,uVar14);
      uVar64 = func_0x006f6a48(param_1 + 0x17f0);
      if ((uVar64 & 1) != 0) {
        bStack_a0 = 8;
        uStack_9f = 0;
        uStack_9e = 0;
        iVar16 = func_0x006f84c8(param_1 + 0x17f0);
        lVar61 = func_0x006f84f0(param_1 + 0x17f0,iVar16 + -1);
        puVar33 = (undefined4 *)func_0x006f3eb8(param_1 + 0x17f0,*(undefined4 *)(lVar61 + 0x10));
        uVar14 = *puVar33;
        uStack_9c = (undefined1)uVar14;
        uStack_9b = (undefined1)((uint)uVar14 >> 8);
        uStack_9a = (undefined1)((uint)uVar14 >> 0x10);
        uStack_99 = (undefined1)((uint)uVar14 >> 0x18);
        func_0x005cf6c0(&puStack_160,&bStack_a0,2);
        func_0x005cf664(puVar42,&puStack_160);
        if (puStack_160 != (uint *)0x0) {
          puStack_158 = puStack_160;
          func_0x00bc3350();
        }
        iVar16 = func_0x006f84c8(param_1 + 0x17f0);
        lVar61 = func_0x006f84f0(param_1 + 0x17f0,iVar16 + -1);
        uVar14 = *(undefined4 *)(lVar61 + 0x10);
        uVar18 = func_0x006f69b0(param_1 + 0x17f0);
        func_0x00a0b124(0x4f,uVar14,uVar18,0,0);
      }
    }
    if ((*(int *)(&UNK_00327f0c + param_1) == 3) && (*(int *)(param_1 + 0x836d0) == 0)) {
      puStack_160 = (uint *)func_0x00bc3330(4);
      puStack_158 = puStack_160 + 1;
      *puStack_160 = 0xb;
      puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
      puStack_150 = puStack_158;
      if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
        *puVar40 = 0;
        puVar40[1] = 0;
        puVar40[2] = 0;
        puVar40[1] = puStack_158;
        *puVar40 = puStack_160;
        puVar40[2] = puStack_158;
        *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
      }
      else {
        uVar27 = func_0x005df9b8(puVar42,&puStack_160);
        *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
        if (puStack_160 != (uint *)0x0) {
          puStack_158 = puStack_160;
          func_0x00bc3350();
        }
      }
      *(undefined4 *)(param_1 + 0x836d0) = 0xffffffff;
    }
  }
  if ((uVar17 & 1) != 0) {
    iVar16 = func_0x00a7039c(param_1 + 0x2c8,0xffffffff,0,0);
    uVar27 = func_0x007a95b8(*(undefined4 *)(&UNK_00383744 + param_1));
    iVar15 = func_0x009cd640(uVar27,*(undefined4 *)(&UNK_00338948 + param_1),*puVar1,
                             *(undefined4 *)(&UNK_0038ff5c + param_1),1);
    uVar14 = func_0x007ac230(0);
    uVar18 = func_0x007ac380();
    func_0x009cd2b4(&puStack_160,&UNK_003bb7d8 + param_1,uVar14,uVar18);
    uVar29 = (ulong)iVar16;
    uVar64 = (long)puStack_158 - (long)puStack_160;
    if ((uVar29 < (ulong)((long)uVar64 >> 3)) && (puStack_160[uVar29 * 2] != 0xffffffff)) {
      iVar19 = func_0x006e437c();
      uVar64 = (long)puStack_158 - (long)puStack_160;
    }
    else {
      iVar19 = -1;
    }
    uVar57 = uVar64 >> 3 & 0xffffffff;
    uVar64 = uVar64 >> 3;
    do {
      uVar57 = uVar57 - 1;
      iVar22 = (int)uVar64;
      uVar17 = iVar22 - 1;
      uVar64 = (ulong)uVar17;
      if (iVar22 < 1) {
        uVar17 = 0xffffffff;
        break;
      }
    } while (puStack_160[(uVar57 & 0xffffffff) * 2] == 0xffffffff);
    if ((bVar13) && ((int)(iVar15 - 1U) <= (int)uVar17)) {
      if (iVar19 != -1) {
        func_0x006e3770(iVar19,puStack_160[uVar29 * 2 + 1],0);
        uVar25 = puStack_160[uVar29 * 2 + 1];
        puVar37 = (undefined4 *)func_0x00bc3330(0x10);
        puVar33 = puVar37 + 4;
        *puVar37 = 0xc;
        puVar37[1] = iVar16;
        puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
        puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
        bStack_98 = (byte)puVar33;
        uStack_97 = (undefined1)((ulong)puVar33 >> 8);
        uStack_96 = (undefined2)((ulong)puVar33 >> 0x10);
        sStack_94 = (short)((ulong)puVar33 >> 0x20);
        sStack_92 = (short)((ulong)puVar33 >> 0x30);
        uStack_8f = (undefined5)((ulong)puVar33 >> 8);
        uStack_8a = (undefined1)((ulong)puVar33 >> 0x30);
        uStack_89 = (undefined1)((ulong)puVar33 >> 0x38);
        puVar37[2] = iVar19;
        puVar37[3] = uVar25;
        bStack_a0 = (byte)puVar37;
        uStack_9f = (undefined1)((ulong)puVar37 >> 8);
        uStack_9e = (undefined2)((ulong)puVar37 >> 0x10);
        uStack_9c = (undefined1)((ulong)puVar37 >> 0x20);
        uStack_9b = (undefined1)((ulong)puVar37 >> 0x28);
        uStack_9a = (undefined1)((ulong)puVar37 >> 0x30);
        uStack_99 = (undefined1)((ulong)puVar37 >> 0x38);
        bStack_90 = bStack_98;
        if (puVar40 < puVar49) {
          *puVar40 = 0;
          puVar40[1] = 0;
          puVar40[2] = 0;
          puVar40[1] = puVar33;
          *puVar40 = puVar37;
          puVar40[2] = puVar33;
          *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
        }
        else {
          uVar27 = func_0x005df9b8(puVar42,&bStack_a0);
          uVar12 = CONCAT15(uStack_9b,
                            CONCAT14(uStack_9c,CONCAT22(uStack_9e,CONCAT11(uStack_9f,bStack_a0))));
          lVar61 = CONCAT17(uStack_99,CONCAT16(uStack_9a,uVar12));
          *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
          if (lVar61 != 0) {
            bStack_98 = bStack_a0;
            uStack_97 = uStack_9f;
            uStack_96 = uStack_9e;
            sStack_94 = (short)((uint6)uVar12 >> 0x20);
            sStack_92 = (short)((ulong)lVar61 >> 0x30);
            func_0x00bc3350();
          }
        }
      }
      if (iVar15 - 1U == uVar17) {
        puVar33 = (undefined4 *)func_0x00bc3330(4);
        bStack_a0 = (byte)puVar33;
        uStack_9f = (undefined1)((ulong)puVar33 >> 8);
        uStack_9e = (undefined2)((ulong)puVar33 >> 0x10);
        uStack_9c = (undefined1)((ulong)puVar33 >> 0x20);
        uStack_9b = (undefined1)((ulong)puVar33 >> 0x28);
        uStack_9a = (undefined1)((ulong)puVar33 >> 0x30);
        uStack_99 = (undefined1)((ulong)puVar33 >> 0x38);
        puVar37 = puVar33 + 1;
        *puVar33 = 0xd;
        puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
        bStack_98 = (byte)puVar37;
        uStack_97 = (undefined1)((ulong)puVar37 >> 8);
        uStack_96 = (undefined2)((ulong)puVar37 >> 0x10);
        sStack_94 = (short)((ulong)puVar37 >> 0x20);
        sStack_92 = (short)((ulong)puVar37 >> 0x30);
        uStack_8f = (undefined5)((ulong)puVar37 >> 8);
        uStack_8a = (undefined1)((ulong)puVar37 >> 0x30);
        uStack_89 = (undefined1)((ulong)puVar37 >> 0x38);
        bStack_90 = bStack_98;
        if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
          *puVar40 = 0;
          puVar40[1] = 0;
          puVar40[2] = 0;
          puVar40[1] = puVar37;
          *puVar40 = puVar33;
          puVar40[2] = puVar37;
          *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
        }
        else {
          uVar27 = func_0x005df9b8(puVar42,&bStack_a0);
          uVar12 = CONCAT15(uStack_9b,
                            CONCAT14(uStack_9c,CONCAT22(uStack_9e,CONCAT11(uStack_9f,bStack_a0))));
          lVar61 = CONCAT17(uStack_99,CONCAT16(uStack_9a,uVar12));
          *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
          if (lVar61 != 0) {
            bStack_98 = bStack_a0;
            uStack_97 = uStack_9f;
            uStack_96 = uStack_9e;
            sStack_94 = (short)((uint6)uVar12 >> 0x20);
            sStack_92 = (short)((ulong)lVar61 >> 0x30);
            func_0x00bc3350();
          }
        }
      }
    }
    if (iVar16 == 9) {
      puVar33 = (undefined4 *)func_0x00bc3330(4);
      bStack_a0 = (byte)puVar33;
      uStack_9f = (undefined1)((ulong)puVar33 >> 8);
      uStack_9e = (undefined2)((ulong)puVar33 >> 0x10);
      uStack_9c = (undefined1)((ulong)puVar33 >> 0x20);
      uStack_9b = (undefined1)((ulong)puVar33 >> 0x28);
      uStack_9a = (undefined1)((ulong)puVar33 >> 0x30);
      uStack_99 = (undefined1)((ulong)puVar33 >> 0x38);
      puVar37 = puVar33 + 1;
      *puVar33 = 0x10;
      puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
      bStack_98 = (byte)puVar37;
      uStack_97 = (undefined1)((ulong)puVar37 >> 8);
      uStack_96 = (undefined2)((ulong)puVar37 >> 0x10);
      sStack_94 = (short)((ulong)puVar37 >> 0x20);
      sStack_92 = (short)((ulong)puVar37 >> 0x30);
      uStack_8f = (undefined5)((ulong)puVar37 >> 8);
      uStack_8a = (undefined1)((ulong)puVar37 >> 0x30);
      uStack_89 = (undefined1)((ulong)puVar37 >> 0x38);
      bStack_90 = bStack_98;
      if (*(undefined8 **)(&UNK_0032c698 + param_1) <= puVar40) {
        uVar27 = func_0x005df9b8(puVar42,&bStack_a0);
        goto LAB_005ce5f0;
      }
LAB_005ce5c0:
      *puVar40 = 0;
      puVar40[1] = 0;
      puVar40[2] = 0;
      puVar40[1] = CONCAT26(sStack_92,
                            CONCAT24(sStack_94,CONCAT22(uStack_96,CONCAT11(uStack_97,bStack_90))));
      *puVar40 = CONCAT17(uStack_99,
                          CONCAT16(uStack_9a,
                                   CONCAT15(uStack_9b,
                                            CONCAT14(uStack_9c,
                                                     CONCAT22(uStack_9e,
                                                              CONCAT11(uStack_9f,bStack_a0))))));
      puVar40[2] = CONCAT17(uStack_89,CONCAT16(uStack_8a,CONCAT51(uStack_8f,bStack_90)));
      *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
      bStack_98 = bStack_90;
    }
    else {
      if (iVar16 == 0) {
        puVar33 = (undefined4 *)func_0x00bc3330(4);
        bStack_a0 = (byte)puVar33;
        uStack_9f = (undefined1)((ulong)puVar33 >> 8);
        uStack_9e = (undefined2)((ulong)puVar33 >> 0x10);
        uStack_9c = (undefined1)((ulong)puVar33 >> 0x20);
        uStack_9b = (undefined1)((ulong)puVar33 >> 0x28);
        uStack_9a = (undefined1)((ulong)puVar33 >> 0x30);
        uStack_99 = (undefined1)((ulong)puVar33 >> 0x38);
        puVar37 = puVar33 + 1;
        *puVar33 = 0xe;
        puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
        bStack_98 = (byte)puVar37;
        uStack_97 = (undefined1)((ulong)puVar37 >> 8);
        uStack_96 = (undefined2)((ulong)puVar37 >> 0x10);
        sStack_94 = (short)((ulong)puVar37 >> 0x20);
        sStack_92 = (short)((ulong)puVar37 >> 0x30);
        uStack_8f = (undefined5)((ulong)puVar37 >> 8);
        uStack_8a = (undefined1)((ulong)puVar37 >> 0x30);
        uStack_89 = (undefined1)((ulong)puVar37 >> 0x38);
        bStack_90 = bStack_98;
        if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) goto LAB_005ce5c0;
        uVar27 = func_0x005df9b8(puVar42,&bStack_a0);
      }
      else {
        if (9 < iVar16) goto LAB_005ce60c;
        puVar33 = (undefined4 *)func_0x00bc3330(4);
        bStack_a0 = (byte)puVar33;
        uStack_9f = (undefined1)((ulong)puVar33 >> 8);
        uStack_9e = (undefined2)((ulong)puVar33 >> 0x10);
        uStack_9c = (undefined1)((ulong)puVar33 >> 0x20);
        uStack_9b = (undefined1)((ulong)puVar33 >> 0x28);
        uStack_9a = (undefined1)((ulong)puVar33 >> 0x30);
        uStack_99 = (undefined1)((ulong)puVar33 >> 0x38);
        puVar37 = puVar33 + 1;
        *puVar33 = 0xf;
        puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
        bStack_98 = (byte)puVar37;
        uStack_97 = (undefined1)((ulong)puVar37 >> 8);
        uStack_96 = (undefined2)((ulong)puVar37 >> 0x10);
        sStack_94 = (short)((ulong)puVar37 >> 0x20);
        sStack_92 = (short)((ulong)puVar37 >> 0x30);
        uStack_8f = (undefined5)((ulong)puVar37 >> 8);
        uStack_8a = (undefined1)((ulong)puVar37 >> 0x30);
        uStack_89 = (undefined1)((ulong)puVar37 >> 0x38);
        bStack_90 = bStack_98;
        if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) goto LAB_005ce5c0;
        uVar27 = func_0x005df9b8(puVar42,&bStack_a0);
      }
LAB_005ce5f0:
      uVar12 = CONCAT15(uStack_9b,
                        CONCAT14(uStack_9c,CONCAT22(uStack_9e,CONCAT11(uStack_9f,bStack_a0))));
      lVar61 = CONCAT17(uStack_99,CONCAT16(uStack_9a,uVar12));
      *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
      if (lVar61 != 0) {
        bStack_98 = bStack_a0;
        uStack_97 = uStack_9f;
        uStack_96 = uStack_9e;
        sStack_94 = (short)((uint6)uVar12 >> 0x20);
        sStack_92 = (short)((ulong)lVar61 >> 0x30);
        func_0x00bc3350();
      }
    }
LAB_005ce60c:
    func_0x00a6fe10(param_1 + 0x2c8,0xffffffff,0,0);
    if (puStack_160 != (uint *)0x0) {
      puStack_158 = puStack_160;
      func_0x00bc3350();
    }
  }
  uVar64 = func_0x009d0178(*(undefined8 *)(param_1 + 0x7c0));
  if ((uVar64 & 1) != 0) {
    uVar17 = func_0x009d1c08(*(undefined8 *)(param_1 + 0x7c0));
    iVar16 = func_0x009d06fc(*(undefined8 *)(param_1 + 0x7c0));
    lVar61 = func_0x008e8424(param_1 + 400,uVar17);
    iVar15 = func_0x008e5518(param_1 + 0x1d8,uVar17);
    if (lVar61 != 0) {
      puVar53 = *(uint **)(lVar61 + 0x10);
      for (puVar45 = *(uint **)(lVar61 + 8); puVar45 != puVar53; puVar45 = puVar45 + 0x12) {
        if (((int)puVar45[1] <= iVar16) &&
           (uVar64 = func_0x008e87d0(param_1 + 400,uVar17,*puVar45), (uVar64 & 1) == 0)) {
          func_0x008e8a3c(param_1 + 400,uVar17,*puVar45,1);
          uVar25 = *puVar45;
          puStack_160 = (uint *)func_0x00bc3330(0xc);
          puStack_158 = puStack_160 + 3;
          *puStack_160 = 0x11;
          puStack_160[1] = uVar17;
          puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
          puVar49 = *(undefined8 **)(&UNK_0032c698 + param_1);
          puStack_160[2] = uVar25;
          puStack_150 = puStack_158;
          if (puVar40 < puVar49) {
            *puVar40 = 0;
            puVar40[1] = 0;
            puVar40[2] = 0;
            puVar40[1] = puStack_158;
            *puVar40 = puStack_160;
            puVar40[2] = puStack_158;
            *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
          }
          else {
            uVar27 = func_0x005df9b8(puVar42,&puStack_160);
            *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
            if (puStack_160 != (uint *)0x0) {
              puStack_158 = puStack_160;
              func_0x00bc3350();
            }
          }
          if (puVar45[2] == 1) {
            iVar19 = func_0x006efac4(&UNK_0032b880 + param_1,puVar45[3]);
            if (iVar19 != -1) {
              iVar19 = func_0x006efac4(&UNK_0032b880 + param_1,puVar45[3]);
              *(undefined4 *)(&UNK_0038efd4 + param_1 + (long)iVar19 * 4) = 1;
            }
          }
          else if (puVar45[2] == 0) {
            func_0x006e3770(puVar45[3],puVar45[4],0);
          }
          func_0x008ec950(param_1 + 400,uVar17,*puVar45,iVar15 <= iVar16);
        }
      }
    }
  }
  if ((&UNK_0038f61c)[param_1] != '\0') {
    (&UNK_0038f61c)[param_1] = 0;
    func_0x006e3770(1,1,0);
    puStack_160 = (uint *)func_0x00bc3330(4);
    puStack_158 = puStack_160 + 1;
    *puStack_160 = 2;
    puVar40 = *(undefined8 **)(&UNK_0032c690 + param_1);
    puStack_150 = puStack_158;
    if (puVar40 < *(undefined8 **)(&UNK_0032c698 + param_1)) {
      *puVar40 = 0;
      puVar40[1] = 0;
      puVar40[2] = 0;
      puVar40[1] = puStack_158;
      *puVar40 = puStack_160;
      puVar40[2] = puStack_158;
      *(undefined8 **)(&UNK_0032c690 + param_1) = puVar40 + 3;
    }
    else {
      uVar27 = func_0x005df9b8(puVar42,&puStack_160);
      *(undefined8 *)(&UNK_0032c690 + param_1) = uVar27;
      if (puStack_160 != (uint *)0x0) {
        puStack_158 = puStack_160;
        func_0x00bc3350();
      }
    }
  }
  if (*(int *)(param_1 + 0xc2e8) == 0) {
    func_0x00a0b124(0,0,0,0,0);
  }
  uVar14 = func_0x007ac230(0);
  uVar64 = func_0x0092e590(param_1 + 0xa38,uVar14,*puVar1);
  if ((uVar64 & 1) != 0) {
    func_0x0092e8a4(param_1 + 0xa38,3);
  }
  *(int *)(param_1 + 0xc2e8) = 1;
  *(undefined4 *)(param_1 + 0xc30c) = 1;
  *(undefined4 *)(&UNK_00388168 + param_1) = 0;
  *(undefined4 *)(&UNK_0032ca00 + param_1) = 0;
  func_0x005cf794();
  func_0x00aad648(param_1);
  func_0x00800498(param_1,*(undefined1 *)(param_1 + 0x3269),1);
  uVar64 = func_0x0045e31c();
  if ((uVar64 & 1) != 0) {
    uVar14 = func_0x007ac230(0);
    uVar64 = func_0x007abbf4(&UNK_0032b898 + param_1,uVar14);
    if ((uVar64 & 1) != 0) {
      if (*(long *)(param_1 + 0x2190) != 0) {
        func_0x00834c98(*(long *)(param_1 + 0x2190),0);
      }
      uVar27 = func_0x0099dc54();
      func_0x0045e350();
      uVar64 = func_0x009a0d0c(uVar27,0x6c);
      if (((((uVar64 & 1) != 0) &&
           (iVar16 = func_0x006e31e0(6), *(int *)(param_1 + 0x836c8) + iVar16 < 100000000)) &&
          (*(long *)(param_1 + 0x2190) != 0)) &&
         (uVar64 = func_0x0083566c(*(long *)(param_1 + 0x2190),0,0), lVar61 = lRam0000000000c0b8b8,
         (uVar64 & 1) != 0)) {
        puStack_160 = (uint *)0x0;
        *(undefined1 *)(param_1 + 0x858) = 1;
        if ((param_2 & 1) == 0) {
          if (lVar61 == 0) {
            lVar61 = 0;
          }
          else {
            lVar61 = func_0x00bc3a90(lVar61,&PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                     &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
          }
          iVar15 = func_0x0043dc7c(param_1);
          iVar16 = iVar15 + -0xf9;
          if (0xf9 < iVar15) {
            iVar16 = iVar15 + -0xfa;
          }
          iVar16 = iVar16 >> 1;
          func_0x009aeed0(&bStack_a0,0x3f800000,lVar61 + 0x18,iVar16 + 0x7d,0x19c,0xfa,0x36,0x1a,
                          0x1b);
          func_0x005cf9d0(&puStack_160,&bStack_a0);
          func_0x0059683c(&bStack_a0);
          (**(code **)(*(long *)puStack_160 + 0x10))(puStack_160,1);
          puVar45 = puStack_160;
          func_0x009ae2ac(auStack_1c0,lVar61 + 0x18,0xffffff9f,0,0x18);
          uVar64 = auStack_1c0[0];
          auStack_1c0[0] = 0;
          bStack_a0 = (byte)uVar64;
          uStack_9f = (undefined1)(uVar64 >> 8);
          uStack_9e = (undefined2)(uVar64 >> 0x10);
          uStack_9c = (undefined1)(uVar64 >> 0x20);
          uStack_9b = (undefined1)(uVar64 >> 0x28);
          uStack_9a = (undefined1)(uVar64 >> 0x30);
          uStack_99 = (undefined1)(uVar64 >> 0x38);
          plVar52 = (long *)func_0x009ae1e4(puVar45,&bStack_a0);
          (**(code **)(*plVar52 + 0x10))(plVar52,1);
          func_0x00590ae0(&bStack_a0);
          func_0x00590b2c(auStack_1c0);
          puVar45 = puStack_160;
          func_0x009ae2ac(auStack_1c0,lVar61 + 0x18,0x14,0,0x19);
          uVar64 = auStack_1c0[0];
          auStack_1c0[0] = 0;
          bStack_a0 = (byte)uVar64;
          uStack_9f = (undefined1)(uVar64 >> 8);
          uStack_9e = (undefined2)(uVar64 >> 0x10);
          uStack_9c = (undefined1)(uVar64 >> 0x20);
          uStack_9b = (undefined1)(uVar64 >> 0x28);
          uStack_9a = (undefined1)(uVar64 >> 0x30);
          uStack_99 = (undefined1)(uVar64 >> 0x38);
          plVar52 = (long *)func_0x009ae1e4(puVar45,&bStack_a0);
          (**(code **)(*plVar52 + 0x10))(plVar52,1);
          func_0x00590ae0(&bStack_a0);
          func_0x00590b2c(auStack_1c0);
          puVar45 = puStack_160;
          func_0x009ae2ac(auStack_1c0,lVar61 + 0x18,0,0xffffffe4,0x1c);
          uVar64 = auStack_1c0[0];
          auStack_1c0[0] = 0;
          bStack_a0 = (byte)uVar64;
          uStack_9f = (undefined1)(uVar64 >> 8);
          uStack_9e = (undefined2)(uVar64 >> 0x10);
          uStack_9c = (undefined1)(uVar64 >> 0x20);
          uStack_9b = (undefined1)(uVar64 >> 0x28);
          uStack_9a = (undefined1)(uVar64 >> 0x30);
          uStack_99 = (undefined1)(uVar64 >> 0x38);
          plVar52 = (long *)func_0x009ae1e4(puVar45,&bStack_a0);
          (**(code **)(*plVar52 + 0x10))(plVar52,1);
          func_0x00590ae0(&bStack_a0);
          func_0x00590b2c(auStack_1c0);
          uVar47 = 0x36;
          uVar46 = 0xfa;
          iVar15 = 0x181;
          uVar27 = 0xcb;
        }
        else {
          if (lVar61 == 0) {
            lVar61 = 0;
          }
          else {
            lVar61 = func_0x00bc3a90(lVar61,&PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                     &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc220,0);
          }
          func_0x00868790(param_1 + 0x2de8);
          iVar16 = func_0x00866898();
          func_0x00868790(param_1 + 0x2de8);
          func_0x00866898();
          func_0x009aeed0(&bStack_a0,0x3f800000,lVar61 + 0x18,iVar16 + 0x78,extraout_var + -0x1c,
                          0xe7,0x32,0x1a,0x1b);
          func_0x005cf9d0(&puStack_160,&bStack_a0);
          func_0x0059683c(&bStack_a0);
          (**(code **)(*(long *)puStack_160 + 0x10))(puStack_160,1);
          puVar45 = puStack_160;
          func_0x009ae2ac(auStack_1c0,lVar61 + 0x18,0xffffffa8,0,0x18);
          uVar64 = auStack_1c0[0];
          auStack_1c0[0] = 0;
          bStack_a0 = (byte)uVar64;
          uStack_9f = (undefined1)(uVar64 >> 8);
          uStack_9e = (undefined2)(uVar64 >> 0x10);
          uStack_9c = (undefined1)(uVar64 >> 0x20);
          uStack_9b = (undefined1)(uVar64 >> 0x28);
          uStack_9a = (undefined1)(uVar64 >> 0x30);
          uStack_99 = (undefined1)(uVar64 >> 0x38);
          plVar52 = (long *)func_0x009ae1e4(puVar45,&bStack_a0);
          (**(code **)(*plVar52 + 0x10))(plVar52,1);
          func_0x009ae278(0x3f70a3d7,0x3f70a3d7);
          func_0x00590ae0(&bStack_a0);
          func_0x00590b2c(auStack_1c0);
          puVar45 = puStack_160;
          func_0x009ae2ac(auStack_1c0,lVar61 + 0x18,0x13,0,0x19);
          uVar64 = auStack_1c0[0];
          auStack_1c0[0] = 0;
          bStack_a0 = (byte)uVar64;
          uStack_9f = (undefined1)(uVar64 >> 8);
          uStack_9e = (undefined2)(uVar64 >> 0x10);
          uStack_9c = (undefined1)(uVar64 >> 0x20);
          uStack_9b = (undefined1)(uVar64 >> 0x28);
          uStack_9a = (undefined1)(uVar64 >> 0x30);
          uStack_99 = (undefined1)(uVar64 >> 0x38);
          plVar52 = (long *)func_0x009ae1e4(puVar45,&bStack_a0);
          (**(code **)(*plVar52 + 0x10))(plVar52,1);
          func_0x009ae278(0x3f70a3d7,0x3f70a3d7);
          iVar16 = iVar16 + 5;
          iVar15 = extraout_var + -0x35;
          func_0x00590ae0(&bStack_a0);
          func_0x00590b2c(auStack_1c0);
          uVar47 = 0x32;
          uVar46 = 0xe7;
          uVar27 = 0xd;
        }
        puVar45 = puStack_160;
        ppuStack_170 = &puStack_190;
        puStack_160 = (uint *)0x0;
        bStack_a0 = (byte)puVar45;
        uStack_9f = (undefined1)((ulong)puVar45 >> 8);
        uStack_9e = (undefined2)((ulong)puVar45 >> 0x10);
        uStack_9c = (undefined1)((ulong)puVar45 >> 0x20);
        uStack_9b = (undefined1)((ulong)puVar45 >> 0x28);
        uStack_9a = (undefined1)((ulong)puVar45 >> 0x30);
        uStack_99 = (undefined1)((ulong)puVar45 >> 0x38);
        puStack_190 = &UNK_00bdc248;
        uStack_180 = param_2 & 1;
        lStack_188 = param_1;
        uVar27 = func_0x00864608(param_1 + 0x2e18,uVar27,iVar16,iVar15,uVar46,uVar47,&bStack_a0,
                                 &puStack_190);
        func_0x00864534(uVar27,0);
        if (ppuStack_170 == &puStack_190) {
          lVar61 = 4;
          ppuVar38 = &puStack_190;
LAB_005ced74:
          (**(code **)(*ppuVar38 + lVar61 * 8))();
        }
        else if (ppuStack_170 != (undefined **)0x0) {
          lVar61 = 5;
          ppuVar38 = ppuStack_170;
          goto LAB_005ced74;
        }
        func_0x00590ae0(&bStack_a0);
        func_0x00590b2c(&puStack_160);
      }
    }
  }
  func_0x00a2420c(param_1 + 0x1970,3);
  uVar64 = func_0x0070c220(param_1 + 0xad0);
  if (((uVar64 & 1) != 0) && (uVar64 = func_0x0070f530(param_1 + 0xad0), (uVar64 & 1) != 0)) {
    uVar27 = *(undefined8 *)(param_1 + 0x1070);
    uVar14 = func_0x0070d90c(param_1 + 0xad0);
    uVar18 = func_0x0070ea4c(param_1 + 0xad0,0xffffffff);
    puStack_160 = (uint *)&UNK_00bdc4c8;
    ppuStack_140 = &puStack_160;
    func_0x0070e114(param_1 + 0xad0,uVar27,uVar14,uVar18,&puStack_160);
    if (ppuStack_140 == &puStack_160) {
      lVar61 = 4;
      ppuVar39 = &puStack_160;
    }
    else {
      if (ppuStack_140 == (uint **)0x0) goto LAB_005cee44;
      lVar61 = 5;
      ppuVar39 = ppuStack_140;
    }
    (**(code **)(*ppuVar39 + lVar61 * 2))();
  }
LAB_005cee44:
  if ((param_2 & 1) != 0) {
    func_0x00a0b124(100,0,0,0,0);
  }
  func_0x00636300(0x48);
  func_0x0043e748(auStack_1a8,uStack_1a0);
  if (*(long *)(lVar11 + 0x28) == lStack_88) {
    return;
  }
LAB_005cf480:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


