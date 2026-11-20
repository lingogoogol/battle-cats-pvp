// ELF VMA: 0x5d5498
// Ghidra Addr: 0x006d5498 (ImageBase=0x100000)
// Size: 5628 bytes


undefined4
BattleFn_0x005d5498(long param_1,int param_2,ulong param_3,int param_4,uint param_5,int param_6,
                   ulong param_7,ulong param_8,byte param_9,byte param_10,byte param_11,
                   byte param_12,byte param_13,byte param_14,byte param_15,undefined8 param_16,
                   byte param_17,int param_18,int param_19)

{
  int *piVar1;
  uint *puVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  long lVar18;
  undefined8 *puVar19;
  long lVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  ulong uVar24;
  int *piVar25;
  int *piVar26;
  uint *puVar27;
  uint *puVar28;
  int *piVar29;
  uint *puVar30;
  ulong uVar31;
  long lVar32;
  uint *puVar33;
  ulong uVar34;
  undefined8 *puVar35;
  int *piVar36;
  uint *puVar37;
  int *piVar38;
  int *piVar39;
  uint *puVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined1 auVar43 [16];
  ulong uStack_198;
  ulong uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  ulong uStack_160;
  undefined8 uStack_158;
  undefined8 *puStack_150;
  ulong uStack_140;
  undefined8 uStack_138;
  undefined8 *puStack_130;
  ulong uStack_120;
  undefined8 uStack_118;
  undefined8 *puStack_110;
  byte bStack_108;
  undefined8 uStack_107;
  undefined7 uStack_ff;
  undefined1 uStack_f8;
  undefined1 uStack_f7;
  undefined6 uStack_f6;
  undefined1 uStack_e9;
  undefined1 auStack_e8 [8];
  undefined8 uStack_e0;
  uint uStack_d0;
  byte bStack_cc;
  undefined4 uStack_c8;
  byte bStack_c4;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 uStack_b8;
  byte bStack_b4;
  undefined4 uStack_b0;
  byte bStack_ac;
  undefined4 uStack_a8;
  byte bStack_a4;
  undefined4 uStack_a0;
  byte bStack_9c;
  undefined4 uStack_98;
  byte bStack_94;
  undefined4 uStack_90;
  byte bStack_8c;
  undefined4 uStack_88;
  byte bStack_84;
  undefined4 uStack_80;
  byte bStack_7c;
  undefined4 uStack_78;
  byte bStack_74;
  long lStack_70;
  
  lVar18 = tpidr_el0;
  lStack_70 = *(long *)(lVar18 + 0x28);
  uVar34 = param_3 & 0xffffffff;
  uVar13 = func_0x00a58fe8(1,param_4);
  if ((uVar13 & 1) == 0) {
    uVar5 = 0;
  }
  else {
    bStack_cc = func_0x00a5b3a4(1,param_4);
    bStack_cc = bStack_cc & 1;
    uStack_d0 = 1;
    bStack_c4 = func_0x00a5b484(1,param_4);
    bStack_c4 = bStack_c4 & 1;
    uStack_c8 = 2;
    uVar3 = func_0x00a5b564(1,param_4);
    uStack_c0 = 4;
    uStack_bc = CONCAT31(uStack_bc._1_3_,uVar3) & 0xffffff01;
    bStack_b4 = func_0x00a5b644(1,param_4);
    bStack_b4 = bStack_b4 & 1;
    uStack_b8 = 8;
    bStack_ac = func_0x00a5b7a0(1,param_4);
    bStack_ac = bStack_ac & 1;
    uStack_b0 = 0x10;
    bStack_a4 = func_0x00a5b880(1,param_4);
    bStack_a4 = bStack_a4 & 1;
    uStack_a8 = 0x20;
    bStack_9c = func_0x00a5b960(1,param_4);
    bStack_9c = bStack_9c & 1;
    uStack_a0 = 0x40;
    bStack_94 = func_0x00a5bab0(1,param_4);
    bStack_94 = bStack_94 & 1;
    uStack_98 = 0x80;
    bStack_8c = func_0x00a5b6c0(1,param_4);
    bStack_8c = bStack_8c & 1;
    uStack_90 = 0x100;
    bStack_84 = func_0x00a5b9d0(1,param_4);
    bStack_84 = bStack_84 & 1;
    uStack_88 = 0x200;
    bStack_7c = func_0x00a5ba40(1,param_4);
    bStack_7c = bStack_7c & 1;
    uStack_80 = 0x400;
    bStack_74 = func_0x00a5bb20(1,param_4);
    bStack_74 = bStack_74 & 1;
    uStack_78 = 0x800;
    func_0x0064f2e0(auStack_e8,&uStack_d0,0xc,&uStack_e9);
    uVar13 = func_0x00a58934(0,uVar34);
    uVar13 = uVar13 & 0xffffffff;
    uVar5 = func_0x005ab2d8(0,uVar34);
    uVar6 = func_0x005abf1c(0,uVar5);
    param_3 = (ulong)param_5;
    iVar7 = func_0x00a5a3d8(0,uVar34,param_3);
    if (param_6 == 2) {
      uVar31 = (ulong)((iVar7 * param_19) / 500);
    }
    else {
      iVar7 = (iVar7 * param_19) / 100;
      uVar31 = (ulong)iVar7;
      if (param_6 == 1) {
        bStack_108 = 0x20;
        uStack_f7 = 0;
        uStack_ff = 0x735f735f657661;
        uStack_f8 = 0x74;
        uStack_107 = 0x775f656c74746162;
        param_3 = 0x1e;
        iVar8 = func_0x008e3f14(param_1 + 0x1478,&bStack_108,0x1e);
        lVar20 = SUB168(SEXT816((long)iVar7 * (long)iVar8) * SEXT816(-0x5c28f5c28f5c28f5),8) +
                 (long)iVar7 * (long)iVar8;
        uVar31 = (lVar20 >> 6) - (lVar20 >> 0x3f);
        if ((bStack_108 & 1) != 0) {
          func_0x00bc3350(CONCAT62(uStack_f6,CONCAT11(uStack_f7,uStack_f8)));
        }
      }
    }
    if ((param_7 & 1) != 0) {
      param_3 = 1;
      func_0x00a6073c(1,param_4,1);
      uVar31 = uVar31 << 1;
    }
    iVar7 = func_0x00a5a220(0,uVar34);
    iVar8 = func_0x00a5a194(0,uVar34);
    iVar9 = func_0x00a5e1a8(0,uVar34);
    if (iVar7 <= (iVar9 * iVar8) / 100) {
      iVar7 = func_0x00a5a194(0,uVar34);
      iVar8 = func_0x00a5e1a8(0,uVar34);
      if (99 < iVar8 * iVar7) {
        iVar7 = func_0x00a5e234(0,uVar34);
        iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x15,uVar13);
        func_0x00a5e234(0,uVar34);
        param_3 = uVar13;
        func_0x008700d4(param_1 + 0x4407e8,0x15,uVar13);
        uVar31 = (long)(uVar31 * (long)(iVar7 + iVar8 + 100)) / 100;
      }
    }
    uVar10 = func_0x00a5e2c0(0,uVar34);
    if ((uVar10 >> 1 & 1) != 0) {
      param_3 = 0x12;
      iVar7 = func_0x006535d4(param_1 + 0x1538,uVar13,0x12,0,0);
      uVar31 = (long)(uVar31 * (long)(iVar7 + 100)) / 100;
    }
    iVar7 = func_0x00a60c98(0,uVar34);
    if ((0 < iVar7) && (iVar7 = func_0x00a60d78(0,uVar34), 0 < iVar7)) {
      iVar7 = func_0x00a60e04(0,uVar34);
      uVar31 = (long)(uVar31 * (long)iVar7) / 100;
    }
    if ((param_8 & 1) != 0) {
      iVar7 = func_0x00a5f28c(0,uVar34);
      func_0x00a5f28c(0,uVar34);
      param_3 = 1;
      func_0x00a614dc(1,param_4,1);
      uVar31 = (long)(uVar31 * (long)(iVar7 + 100)) / 100;
    }
    if ((param_4 == 0) || (iVar7 = func_0x005aad10(), iVar7 == param_4)) {
      uVar14 = func_0x00a5ea34(0,uVar34);
      uVar24 = uVar31 << 2;
      if ((uVar14 & 1) == 0) {
        uVar24 = uVar31;
      }
LAB_006d599c:
      if (1 < (int)uVar6) {
        param_3 = 0;
        iVar7 = func_0x00653884(param_1 + 0x1538,uVar13,0,0,auStack_e8,0);
        if (0 < iVar7) {
          iVar8 = func_0x00a645a8(0,uVar13,uVar6,1,0xffffffff,param_5,1,0);
          param_3 = (ulong)uVar6;
          func_0x00a645a8(0,uVar13,param_3,1,0xffffffff,param_5,1,0);
          uVar24 = uVar24 + (long)((iVar8 * iVar7) / 100);
        }
      }
      uVar31 = func_0x00a5b644(1,param_4);
      uVar13 = uVar24;
      if (0 < (long)uVar24) {
        uVar13 = 1;
      }
      uStack_198 = uVar24;
      if ((param_7 & 1) == 0) {
        uStack_198 = uVar13;
      }
      if ((uVar31 & 1) == 0) {
        uStack_198 = uVar24;
      }
      if (param_2 != 3) {
        if (param_2 == 2) {
          uVar13 = func_0x00a60218(1,param_4);
          goto LAB_006d5ad4;
        }
        if (param_2 == 1) {
          uVar13 = func_0x00a5f900(1,param_4);
          goto LAB_006d5ad4;
        }
LAB_006d5b00:
        uVar6 = func_0x00a5b644(1,param_4);
        uStack_198 = uStack_198 & ((long)uStack_198 >> 0x3f ^ 0xffffffffffffffffU);
        if (param_18 < 1 || ((uVar6 ^ 0xffffffff) & 1) != 0) goto LAB_006d5e04;
        puVar21 = *(undefined8 **)(param_1 + 0x838f8);
        puVar23 = (undefined8 *)(param_1 + 0x838f8);
        while (puVar19 = puVar23, puVar21 != (undefined8 *)0x0) {
          while (puVar35 = puVar21, puVar23 = puVar35, *(int *)(puVar35 + 4) <= param_4) {
            if (param_4 <= *(int *)(puVar35 + 4)) goto LAB_006d5cd4;
            puVar21 = (undefined8 *)puVar35[1];
            if ((undefined8 *)puVar35[1] == (undefined8 *)0x0) {
              puVar19 = puVar35 + 1;
              goto LAB_006d5b70;
            }
          }
          puVar21 = (undefined8 *)*puVar35;
        }
LAB_006d5b70:
        puVar35 = (undefined8 *)func_0x00bc3330(0x40);
        *(int *)(puVar35 + 4) = param_4;
        puVar35[6] = 0;
        puVar35[7] = 0;
        puVar35[5] = 0;
        *puVar35 = 0;
        puVar35[1] = 0;
        puVar35[2] = puVar23;
        *puVar19 = puVar35;
        lVar20 = **(long **)(param_1 + 0x838f0);
        puVar23 = puVar35;
        if (lVar20 != 0) {
          *(long *)(param_1 + 0x838f0) = lVar20;
          puVar23 = (undefined8 *)*puVar19;
        }
        func_0x0040a8c0(*(undefined8 *)(param_1 + 0x838f8),puVar23);
        *(long *)(param_1 + 0x83900) = *(long *)(param_1 + 0x83900) + 1;
LAB_006d5cd4:
        piVar38 = (int *)puVar35[6];
        if (piVar38 < (int *)puVar35[7]) {
          piVar39 = piVar38 + 1;
          *piVar38 = param_18;
LAB_006d5df0:
          puVar35[6] = piVar39;
          func_0x00a61c08(1,param_4,1);
          goto LAB_006d5e04;
        }
        piVar36 = (int *)puVar35[5];
        lVar20 = (long)piVar38 - (long)piVar36 >> 2;
        uVar13 = lVar20 + 1;
        if (uVar13 >> 0x3e != 0) goto LAB_006d6a14;
        uVar24 = (long)puVar35[7] - (long)piVar36;
        uVar31 = (long)uVar24 >> 1;
        if (uVar31 <= uVar13) {
          uVar31 = uVar13;
        }
        if (0x7ffffffffffffffb < uVar24) {
          uVar31 = 0x3fffffffffffffff;
        }
        if (uVar31 == 0) {
          lVar32 = 0;
LAB_006d5d40:
          piVar26 = (int *)(lVar32 + lVar20 * 4);
          piVar39 = piVar26 + 1;
          *piVar26 = param_18;
          if ((long)piVar38 - (long)piVar36 != 0) {
            uVar13 = ((long)piVar38 - (long)piVar36) - 4;
            piVar25 = piVar26;
            if ((0x1b < uVar13) &&
               (0x1f < (ulong)((long)piVar38 + (-((long)piVar38 - (long)piVar36) - lVar32)))) {
              piVar29 = piVar38 + -4;
              uVar13 = (uVar13 >> 2) + 1;
              uVar14 = uVar13 & 0x7ffffffffffffff8;
              piVar38 = piVar38 + -uVar14;
              piVar25 = piVar26 + -uVar14;
              piVar26 = piVar26 + -4;
              uVar24 = uVar14;
              do {
                piVar1 = piVar29 + -2;
                uVar42 = *(undefined8 *)(piVar29 + -4);
                uVar41 = *(undefined8 *)(piVar29 + 2);
                uVar17 = *(undefined8 *)piVar29;
                uVar24 = uVar24 - 8;
                piVar29 = piVar29 + -8;
                *(undefined8 *)(piVar26 + -2) = *(undefined8 *)piVar1;
                *(undefined8 *)(piVar26 + -4) = uVar42;
                *(undefined8 *)(piVar26 + 2) = uVar41;
                *(undefined8 *)piVar26 = uVar17;
                piVar26 = piVar26 + -8;
              } while (uVar24 != 0);
              piVar26 = piVar25;
              if (uVar13 == uVar14) goto LAB_006d5ddc;
            }
            do {
              piVar38 = piVar38 + -1;
              piVar26 = piVar25 + -1;
              *piVar26 = *piVar38;
              piVar25 = piVar26;
            } while (piVar38 != piVar36);
          }
LAB_006d5ddc:
          puVar35[5] = piVar26;
          puVar35[6] = piVar39;
          puVar35[7] = lVar32 + uVar31 * 4;
          if (piVar36 != (int *)0x0) {
            func_0x00bc3350(piVar36);
          }
          goto LAB_006d5df0;
        }
        if (uVar31 >> 0x3e == 0) {
          lVar32 = func_0x00bc3330(uVar31 << 2);
          goto LAB_006d5d40;
        }
LAB_006d6a48:
        if (*(long *)(lVar18 + 0x28) == lStack_70) {
          uVar17 = func_0x0040fc1c();
          func_0x0065b710(auStack_e8,uStack_e0);
          if (*(long *)(lVar18 + 0x28) == lStack_70) {
            func_0x00bbf40c(uVar17);
          }
        }
        goto LAB_006d6b94;
      }
      uVar13 = func_0x00a602ac(1,param_4);
LAB_006d5ad4:
      if ((uVar13 & 1) == 0) goto LAB_006d5b00;
      uStack_198 = 0;
      *(undefined8 *)(param_1 + (long)param_4 * 1000 + 0x901b0) = 0x100000000;
LAB_006d5e04:
      uVar6 = func_0x00a5a068(0,uVar34);
      puVar35 = (undefined8 *)(ulong)uVar6;
      iVar7 = func_0x00a5a068(1,param_4);
      puVar21 = (undefined8 *)(param_1 + 0x2a18);
      puVar22 = *(undefined8 **)(param_1 + 0x2a18);
      puVar19 = puVar22;
      puVar23 = puVar21;
      while (puVar16 = puVar23, puVar19 != (undefined8 *)0x0) {
        while (puVar15 = puVar19, *(int *)(puVar15 + 4) <= iVar7) {
          if (iVar7 <= *(int *)(puVar15 + 4)) goto LAB_006d5ed0;
          puVar19 = (undefined8 *)puVar15[1];
          if ((undefined8 *)puVar15[1] == (undefined8 *)0x0) {
            puVar23 = puVar15 + 1;
            puVar16 = puVar15;
            goto LAB_006d5e74;
          }
        }
        puVar23 = puVar15;
        puVar19 = (undefined8 *)*puVar15;
      }
LAB_006d5e74:
      puVar15 = (undefined8 *)func_0x00bc3330(0x40);
      *(int *)(puVar15 + 4) = iVar7;
      puVar15[6] = 0;
      puVar15[7] = 0;
      puVar15[5] = 0;
      *puVar15 = 0;
      puVar15[1] = 0;
      puVar15[2] = puVar16;
      *puVar23 = puVar15;
      puVar19 = puVar15;
      if (**(long **)(param_1 + 0x2a10) != 0) {
        *(long *)(param_1 + 0x2a10) = **(long **)(param_1 + 0x2a10);
        puVar19 = (undefined8 *)*puVar23;
      }
      func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2a18),puVar19);
      puVar22 = *(undefined8 **)(param_1 + 0x2a18);
      *(long *)(param_1 + 0x2a20) = *(long *)(param_1 + 0x2a20) + 1;
LAB_006d5ed0:
      lVar20 = puVar15[5];
      puVar23 = puVar21;
      while (puVar19 = puVar23, puVar22 != (undefined8 *)0x0) {
        while (puVar16 = puVar22, *(int *)(puVar16 + 4) <= iVar7) {
          if (iVar7 <= *(int *)(puVar16 + 4)) goto LAB_006d5f6c;
          puVar22 = (undefined8 *)puVar16[1];
          if ((undefined8 *)puVar16[1] == (undefined8 *)0x0) {
            puVar23 = puVar16 + 1;
            puVar19 = puVar16;
            goto LAB_006d5f14;
          }
        }
        puVar23 = puVar16;
        puVar22 = (undefined8 *)*puVar16;
      }
LAB_006d5f14:
      puVar16 = (undefined8 *)func_0x00bc3330(0x40);
      *(int *)(puVar16 + 4) = iVar7;
      puVar16[6] = 0;
      puVar16[7] = 0;
      puVar16[5] = 0;
      *puVar16 = 0;
      puVar16[1] = 0;
      puVar16[2] = puVar19;
      *puVar23 = puVar16;
      puVar19 = puVar16;
      if (**(long **)(param_1 + 0x2a10) != 0) {
        *(long *)(param_1 + 0x2a10) = **(long **)(param_1 + 0x2a10);
        puVar19 = (undefined8 *)*puVar23;
      }
      func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2a18),puVar19);
      *(long *)(param_1 + 0x2a20) = *(long *)(param_1 + 0x2a20) + 1;
LAB_006d5f6c:
      lVar32 = puVar16[6];
      param_3 = lVar32 - lVar20 >> 2;
      lVar20 = func_0x00bc38e0(lVar20,puVar35,param_3);
      puVar19 = (undefined8 *)*puVar21;
      puVar23 = puVar21;
      if (lVar20 != 0) {
        lVar32 = lVar20;
      }
      while (puVar22 = puVar23, puVar19 != (undefined8 *)0x0) {
        while (puVar16 = puVar19, *(int *)(puVar16 + 4) <= iVar7) {
          if (iVar7 <= *(int *)(puVar16 + 4)) goto LAB_006d6028;
          puVar19 = (undefined8 *)puVar16[1];
          if ((undefined8 *)puVar16[1] == (undefined8 *)0x0) {
            puVar23 = puVar16 + 1;
            puVar22 = puVar16;
            goto LAB_006d5fd0;
          }
        }
        puVar23 = puVar16;
        puVar19 = (undefined8 *)*puVar16;
      }
LAB_006d5fd0:
      puVar16 = (undefined8 *)func_0x00bc3330(0x40);
      *(int *)(puVar16 + 4) = iVar7;
      puVar16[6] = 0;
      puVar16[7] = 0;
      puVar16[5] = 0;
      *puVar16 = 0;
      puVar16[1] = 0;
      puVar16[2] = puVar22;
      *puVar23 = puVar16;
      puVar19 = puVar16;
      if (**(long **)(param_1 + 0x2a10) != 0) {
        *(long *)(param_1 + 0x2a10) = **(long **)(param_1 + 0x2a10);
        puVar19 = (undefined8 *)*puVar23;
      }
      func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2a18),puVar19);
      *(long *)(param_1 + 0x2a20) = *(long *)(param_1 + 0x2a20) + 1;
LAB_006d6028:
      if (lVar32 == puVar16[6]) {
        puVar23 = (undefined8 *)*puVar21;
        while (puVar19 = puVar21, puVar23 != (undefined8 *)0x0) {
          while (puVar22 = puVar23, *(int *)(puVar22 + 4) <= iVar7) {
            if (iVar7 <= *(int *)(puVar22 + 4)) goto LAB_006d60cc;
            puVar23 = (undefined8 *)puVar22[1];
            if ((undefined8 *)puVar22[1] == (undefined8 *)0x0) {
              puVar21 = puVar22 + 1;
              puVar19 = puVar22;
              goto LAB_006d6074;
            }
          }
          puVar21 = puVar22;
          puVar23 = (undefined8 *)*puVar22;
        }
LAB_006d6074:
        puVar22 = (undefined8 *)func_0x00bc3330(0x40);
        *(int *)(puVar22 + 4) = iVar7;
        puVar22[6] = 0;
        puVar22[7] = 0;
        puVar22[5] = 0;
        *puVar22 = 0;
        puVar22[1] = 0;
        puVar22[2] = puVar19;
        *puVar21 = puVar22;
        puVar23 = puVar22;
        if (**(long **)(param_1 + 0x2a10) != 0) {
          *(long *)(param_1 + 0x2a10) = **(long **)(param_1 + 0x2a10);
          puVar23 = (undefined8 *)*puVar21;
        }
        func_0x0040a8c0(*(undefined8 *)(param_1 + 0x2a18),puVar23);
        *(long *)(param_1 + 0x2a20) = *(long *)(param_1 + 0x2a20) + 1;
LAB_006d60cc:
        puVar33 = (uint *)puVar22[6];
        if (puVar33 < (uint *)puVar22[7]) {
          puVar40 = puVar33 + 1;
          *puVar33 = uVar6;
        }
        else {
          puVar37 = (uint *)puVar22[5];
          lVar20 = (long)puVar33 - (long)puVar37 >> 2;
          uVar13 = lVar20 + 1;
          if (uVar13 >> 0x3e != 0) {
            if (*(long *)(lVar18 + 0x28) != lStack_70) goto LAB_006d6b94;
            func_0x00441cdc(puVar22 + 5);
LAB_006d6a14:
            if (*(long *)(lVar18 + 0x28) != lStack_70) goto LAB_006d6b94;
            func_0x00441cdc(puVar35 + 5);
LAB_006d6a30:
            if (*(long *)(lVar18 + 0x28) != lStack_70) goto LAB_006d6b94;
            func_0x0040fc1c();
            goto LAB_006d6a48;
          }
          uVar24 = (long)puVar22[7] - (long)puVar37;
          uVar31 = (long)uVar24 >> 1;
          if (uVar31 <= uVar13) {
            uVar31 = uVar13;
          }
          if (0x7ffffffffffffffb < uVar24) {
            uVar31 = 0x3fffffffffffffff;
          }
          if (uVar31 == 0) {
            lVar32 = 0;
          }
          else {
            if (uVar31 >> 0x3e != 0) goto LAB_006d6a30;
            lVar32 = func_0x00bc3330(uVar31 << 2);
          }
          puVar28 = (uint *)(lVar32 + lVar20 * 4);
          puVar40 = puVar28 + 1;
          *puVar28 = uVar6;
          if ((long)puVar33 - (long)puVar37 != 0) {
            uVar13 = ((long)puVar33 - (long)puVar37) - 4;
            puVar27 = puVar28;
            if ((0x1b < uVar13) &&
               (0x1f < (ulong)((long)puVar33 + (-((long)puVar33 - (long)puVar37) - lVar32)))) {
              puVar30 = puVar33 + -4;
              uVar13 = (uVar13 >> 2) + 1;
              uVar14 = uVar13 & 0x7ffffffffffffff8;
              puVar33 = puVar33 + -uVar14;
              puVar27 = puVar28 + -uVar14;
              puVar28 = puVar28 + -4;
              uVar24 = uVar14;
              do {
                puVar2 = puVar30 + -2;
                uVar42 = *(undefined8 *)(puVar30 + -4);
                uVar41 = *(undefined8 *)(puVar30 + 2);
                uVar17 = *(undefined8 *)puVar30;
                uVar24 = uVar24 - 8;
                puVar30 = puVar30 + -8;
                *(undefined8 *)(puVar28 + -2) = *(undefined8 *)puVar2;
                *(undefined8 *)(puVar28 + -4) = uVar42;
                *(undefined8 *)(puVar28 + 2) = uVar41;
                *(undefined8 *)puVar28 = uVar17;
                puVar28 = puVar28 + -8;
              } while (uVar24 != 0);
              puVar28 = puVar27;
              if (uVar13 == uVar14) goto LAB_006d61d4;
            }
            do {
              puVar33 = puVar33 + -1;
              puVar28 = puVar27 + -1;
              *puVar28 = *puVar33;
              puVar27 = puVar28;
            } while (puVar33 != puVar37);
          }
LAB_006d61d4:
          puVar22[5] = puVar28;
          puVar22[6] = puVar40;
          puVar22[7] = lVar32 + uVar31 * 4;
          if (puVar37 != (uint *)0x0) {
            func_0x00bc3350(puVar37);
          }
        }
        puVar22[6] = puVar40;
      }
      param_3 = uStack_198;
      func_0x00a60488(1,param_4,uStack_198);
      uVar13 = func_0x00a5c6d4(0,uVar34);
      if ((uVar13 & 1) != 0) {
        *(undefined4 *)(param_1 + (long)param_4 * 1000 + 0x9013c) = 1;
      }
      uVar13 = func_0x00a5eac8(0,uVar34);
      if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b960(1,param_4), (uVar13 & 1) != 0)) {
        param_3 = 1;
        func_0x00a625c4(1,param_4,1);
      }
      bVar4 = func_0x005ab294();
      uVar5 = 1;
      if (((bVar4 & uStack_198 != 0) == 1) && (param_2 - 1U < 3)) {
        param_3 = func_0x00999ef0(param_1 + 0x400,param_2 + 9,1);
        param_3 = param_3 & 0xffffffff;
        func_0x00a5a9c8(1,param_4,param_3);
      }
    }
    else {
      param_3 = uVar34;
      uVar24 = func_0x00a5ac18(1,param_4,uVar34);
      if ((uVar24 & 1) == 0) {
LAB_006d5c4c:
        uVar24 = func_0x00a5ac18(0,uVar34,param_4);
        if ((uVar24 & 1) != 0) {
          uVar5 = BattleFn_0x005d6b98(param_1,uVar34,param_4);
          uVar24 = func_0x00a5e500(0,uVar34);
          if ((uVar24 & 1) != 0) {
            iVar7 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar5,100);
            if ((int)uVar6 < 2) {
              iVar8 = 0;
            }
            else {
              iVar8 = func_0x00653884(param_1 + 0x1538,uVar13,2,0,auStack_e8,0);
            }
            iVar9 = func_0x008700d4(param_1 + 0x4407e8,0xe,uVar13);
            func_0x008700d4(param_1 + 0x4407e8,0xe,uVar13);
            uVar10 = func_0x005ab294();
            uVar31 = (((long)(uVar31 * (long)(iVar7 + iVar8 + 0x5dc)) / 1000) * (long)(iVar9 + 100))
                     / 100;
            if (param_2 == 0 && ((uVar10 ^ 0xffffffff) & 1) == 0) {
              uVar11 = func_0x00a5aa1c(0,uVar34);
              uVar11 = func_0x00999ef0(param_1 + 0x400,0xd,uVar11);
              func_0x00a5a9c8(1,param_4,uVar11);
            }
          }
          uVar24 = func_0x00a5e6c0(0,uVar34);
          if ((uVar24 & 1) != 0) {
            iVar7 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar5,100);
            if ((int)uVar6 < 2) {
              iVar8 = 0;
            }
            else {
              iVar8 = func_0x00653884(param_1 + 0x1538,uVar13,3,0,auStack_e8,0);
            }
            iVar9 = func_0x008700d4(param_1 + 0x4407e8,0xf,uVar13);
            func_0x008700d4(param_1 + 0x4407e8,0xf,uVar13);
            uVar10 = func_0x005ab294();
            uVar31 = (((long)(uVar31 * (long)(iVar7 + iVar8 + 900)) / 300) * (long)(iVar9 + 100)) /
                     100;
            if (param_2 == 0 && ((uVar10 ^ 0xffffffff) & 1) == 0) {
              uVar11 = func_0x00a5aa1c(0,uVar34);
              uVar11 = func_0x00999ef0(param_1 + 0x400,0xe,uVar11);
              func_0x00a5a9c8(1,param_4,uVar11);
            }
          }
          uVar24 = func_0x00a5e880(0,uVar34);
          if ((uVar24 & 1) == 0) {
LAB_006d6578:
            if (param_2 == 3) {
              uVar24 = func_0x00a602ac(1,param_4);
            }
            else if (param_2 == 2) {
              uVar24 = func_0x00a60218(1,param_4);
            }
            else {
              if (param_2 != 1) goto LAB_006d65c4;
              uVar24 = func_0x00a5f900(1,param_4);
            }
            if ((uVar24 & 1) != 0) goto LAB_006d6620;
          }
          else {
            iVar7 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar5,100);
            uVar10 = func_0x005ab294();
            uVar31 = (long)(uVar31 * (long)(iVar7 + 0x5dc)) / 300;
            if (param_2 != 0 || ((uVar10 ^ 0xffffffff) & 1) != 0) goto LAB_006d6578;
            uVar11 = func_0x00a5aa1c(0,uVar34);
            uVar11 = func_0x00999ef0(param_1 + 0x400,0xf,uVar11);
            func_0x00a5a9c8(1,param_4,uVar11);
          }
LAB_006d65c4:
          BattleFn_0x005d6da0(param_1,0,uVar34,param_4,uVar5,param_9 & 1,param_10 & 1,param_11 & 1,
                              param_12 & 1,param_13 & 1,param_14 & 1,0,0);
        }
LAB_006d6620:
        uVar24 = func_0x00a5eba8(0,uVar34);
        if (((uVar24 & 1) != 0) && (uVar24 = func_0x00a5b9d0(1,param_4), (uVar24 & 1) != 0)) {
          iVar7 = func_0x008700d4(param_1 + 0x4407e8,0x16,uVar13);
          func_0x008700d4(param_1 + 0x4407e8,0x16,uVar13);
          uVar31 = (long)(uVar31 * (long)(iVar7 + 100) * 5) / 100;
        }
        uVar24 = func_0x00a5ec88(0,uVar34);
        if (((uVar24 & 1) != 0) && (uVar24 = func_0x00a5ba40(1,param_4), (uVar24 & 1) != 0)) {
          iVar7 = func_0x008700d4(param_1 + 0x4407e8,0x17,uVar13);
          func_0x008700d4(param_1 + 0x4407e8,0x17,uVar13);
          uVar31 = (long)(uVar31 * (long)(iVar7 + 100) * 5) / 100;
        }
        uVar24 = func_0x00a5ed68(0,uVar34);
        if (((uVar24 & 1) != 0) && (uVar24 = func_0x00a5c020(1,param_4), (uVar24 & 1) != 0)) {
          iVar7 = func_0x00a5ee48(0,uVar34);
          func_0x00a5ee48(0,uVar34);
          uVar31 = (long)(uVar31 * (long)iVar7) / 100;
        }
        uVar24 = func_0x00a5f364(0,uVar34);
        if (((uVar24 & 1) != 0) && (uVar24 = func_0x00a5c0dc(1,param_4), (uVar24 & 1) != 0)) {
          puStack_110 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_110[1] = 0x6165625f72657075;
          *puStack_110 = 0x735f656c74746162;
          *(undefined8 *)((long)puStack_110 + 0x11) = 0x7265746e75685f74;
          *(undefined8 *)((long)puStack_110 + 9) = 0x736165625f726570;
          uStack_118 = 0x19;
          uStack_120 = 0x21;
          *(undefined1 *)((long)puStack_110 + 0x19) = 0;
          iVar7 = func_0x008e3f14(param_1 + 0x1478,&uStack_120,0x640);
          if ((uStack_120 & 1) != 0) {
            func_0x00bc3350(puStack_110);
          }
          puStack_130 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_130 + 0x19) = 0;
          uStack_138 = 0x19;
          uStack_140 = 0x21;
          puStack_130[1] = 0x6165625f72657075;
          *puStack_130 = 0x735f656c74746162;
          *(undefined8 *)((long)puStack_130 + 0x11) = 0x7265746e75685f74;
          *(undefined8 *)((long)puStack_130 + 9) = 0x736165625f726570;
          func_0x008e3f14(param_1 + 0x1478,&uStack_140,0x640);
          uVar31 = (long)(uVar31 * (long)iVar7) / 1000;
          if ((uStack_140 & 1) != 0) {
            func_0x00bc3350(puStack_130);
          }
        }
        uVar24 = func_0x00a5f5ec(0,uVar34);
        if (((uVar24 & 1) != 0) && (uVar24 = func_0x00a5c198(1,param_4), (uVar24 & 1) != 0)) {
          puStack_150 = (undefined8 *)func_0x00bc3330(0x30);
          puStack_150[1] = 0x6761735f72657075;
          *puStack_150 = 0x735f656c74746162;
          puStack_150[3] = 0x316567616d61645f;
          puStack_150[2] = 0x7265746e75685f65;
          uStack_158 = 0x20;
          uStack_160 = 0x31;
          *(undefined1 *)(puStack_150 + 4) = 0;
          iVar7 = func_0x008e3f14(param_1 + 0x1478,&uStack_160,0x640);
          if ((uStack_160 & 1) != 0) {
            func_0x00bc3350(puStack_150);
          }
          puStack_170 = (undefined8 *)func_0x00bc3330(0x30);
          *(undefined1 *)(puStack_170 + 4) = 0;
          uStack_178 = 0x20;
          uStack_180 = 0x31;
          puStack_170[1] = 0x6761735f72657075;
          *puStack_170 = 0x735f656c74746162;
          puStack_170[3] = 0x316567616d61645f;
          puStack_170[2] = 0x7265746e75685f65;
          func_0x008e3f14(param_1 + 0x1478,&uStack_180,0x640);
          uVar31 = (long)(uVar31 * (long)iVar7) / 1000;
          if ((uStack_180 & 1) != 0) {
            func_0x00bc3350(puStack_170);
          }
        }
        param_3 = uVar13;
        uVar10 = func_0x008700d4(param_1 + 0x4407e8,0x19,uVar13);
        if ((0 < (int)uVar10) && (uVar24 = func_0x00a5c254(1,param_4), (uVar24 & 1) != 0)) {
          uVar31 = (long)(uVar31 * uVar10) / 1000;
        }
        iVar7 = func_0x00a5fe34(1,param_4);
        if ((0 < iVar7) && ((param_15 & 1) != 0)) {
          param_3 = 2;
          func_0x00a60660(1,param_4,2);
        }
        iVar7 = func_0x00a6177c(1,param_4);
        uVar24 = uVar31;
        if ((0 < iVar7) && ((param_17 & 1) != 0)) {
          param_3 = 2;
          func_0x00a61848(1,param_4,2);
        }
        goto LAB_006d599c;
      }
      iVar7 = func_0x00a61528(1,param_4);
      if (iVar7 < 1) {
        iVar7 = func_0x0043ea60(100);
        iVar8 = func_0x00a6006c(1,param_4);
        if (iVar8 <= iVar7) goto LAB_006d5c4c;
        uVar5 = func_0x00a600f8(1,param_4);
        func_0x00a61568(1,param_4,uVar5);
        param_3 = 1;
        func_0x00a61648(1,param_4,1);
        func_0x0040cb78(&uStack_d0,&UNK_0028fd53);
        func_0x00a6006c(1,param_4);
        func_0x00a6006c(1,param_4);
        if ((uStack_d0 & 1) != 0) {
          func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
        }
      }
      uVar5 = 0;
    }
    func_0x0065b710(auStack_e8,uStack_e0);
  }
  if (*(long *)(lVar18 + 0x28) == lStack_70) {
    return uVar5;
  }
LAB_006d6b94:
  auVar43 = func_0x00bc3380();
  lVar18 = auVar43._0_8_;
  param_3 = param_3 & 0xffffffff;
  uVar34 = auVar43._8_8_ & 0xffffffff;
  uVar13 = func_0x00a5b334(0);
  if ((uVar13 & 1) == 0) {
    uVar6 = 0;
    uVar5 = 0x19;
  }
  else {
    uVar13 = func_0x00a5b3a4(1,param_3);
    uVar5 = 0x19;
    if ((uVar13 & 1) == 0) {
      uVar6 = 0;
    }
    else {
      uVar10 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0xc);
      uVar6 = uVar10 & ((int)uVar10 >> 0x1f ^ 0xffffffffU);
      uVar5 = 0xc;
      if ((int)uVar10 < 0) {
        uVar5 = 0x19;
      }
    }
  }
  uVar13 = func_0x00a5b414(0,uVar34);
  uVar10 = uVar6;
  if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b484(1,param_3), (uVar13 & 1) != 0)) {
    uVar12 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0xe);
    uVar10 = uVar12;
    if ((int)uVar12 <= (int)uVar6) {
      uVar10 = uVar6;
    }
    if ((int)uVar6 <= (int)uVar12) {
      uVar5 = 0xe;
    }
  }
  uVar13 = func_0x00a5b4f4(0,uVar34);
  uVar6 = uVar10;
  if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b564(1,param_3), (uVar13 & 1) != 0)) {
    uVar12 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0xd);
    uVar6 = uVar12;
    if ((int)uVar12 <= (int)uVar10) {
      uVar6 = uVar10;
    }
    if ((int)uVar10 <= (int)uVar12) {
      uVar5 = 0xd;
    }
  }
  uVar13 = func_0x00a5b730(0,uVar34);
  uVar10 = uVar6;
  if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b7a0(1,param_3), (uVar13 & 1) != 0)) {
    uVar12 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0xf);
    uVar10 = uVar12;
    if ((int)uVar12 <= (int)uVar6) {
      uVar10 = uVar6;
    }
    if ((int)uVar6 <= (int)uVar12) {
      uVar5 = 0xf;
    }
  }
  uVar13 = func_0x00a5b5d4(0,uVar34);
  uVar6 = uVar10;
  if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b644(1,param_3), (uVar13 & 1) != 0)) {
    uVar12 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0x13);
    uVar6 = uVar12;
    if ((int)uVar12 <= (int)uVar10) {
      uVar6 = uVar10;
    }
    if ((int)uVar10 <= (int)uVar12) {
      uVar5 = 0x13;
    }
  }
  uVar13 = func_0x00a5b8f0(0,uVar34);
  uVar10 = uVar6;
  if (((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b960(1,param_3), (uVar13 & 1) != 0)) {
    uVar12 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0x14);
    uVar10 = uVar12;
    if ((int)uVar12 <= (int)uVar6) {
      uVar10 = uVar6;
    }
    if ((int)uVar6 <= (int)uVar12) {
      uVar5 = 0x14;
    }
  }
  uVar13 = func_0x00a5b810(0,uVar34);
  if ((((uVar13 & 1) != 0) && (uVar13 = func_0x00a5b880(1,param_3), (uVar13 & 1) != 0)) &&
     (iVar7 = func_0x00a1f9dc(&UNK_00290568 + lVar18,0x15), (int)uVar10 <= iVar7)) {
    uVar5 = 0x15;
  }
  return uVar5;
}


