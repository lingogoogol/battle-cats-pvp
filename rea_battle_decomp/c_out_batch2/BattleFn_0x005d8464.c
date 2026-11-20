// ELF VMA: 0x5d8464
// Ghidra Addr: 0x006d8464 (ImageBase=0x100000)
// Size: 6016 bytes


/* WARNING: Possible PIC construction at 0x006da9bc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006da9e4: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006da9c0) */
/* WARNING: Removing unreachable block (ram,0x006da9dc) */
/* WARNING: Removing unreachable block (ram,0x006da9e8) */

ulong BattleFn_0x005d8464(ulong param_1,uint param_2,ulong param_3,uint param_4,ulong param_5,
                         uint param_6,uint param_7,ulong param_8,byte param_9,byte param_10,
                         byte param_11,byte param_12,byte param_13,byte param_14,byte param_15,
                         byte param_16,byte param_17,byte param_18,int param_19)

{
  uint *puVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined1 uVar16;
  byte bVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  undefined4 uVar27;
  int iVar28;
  ulong uVar29;
  long lVar30;
  undefined8 *puVar31;
  undefined8 *puVar32;
  undefined8 uVar33;
  long *plVar34;
  long lVar35;
  undefined1 *puVar36;
  undefined4 *puVar37;
  long lVar38;
  ulong uVar39;
  long lVar40;
  undefined *puVar41;
  long *plVar42;
  ulong uVar43;
  ulong uVar44;
  ulong unaff_x25;
  ulong uVar45;
  ulong uVar46;
  long *plVar47;
  ulong uVar48;
  undefined1 auVar49 [16];
  byte abStack_270 [16];
  undefined8 uStack_260;
  byte bStack_258;
  undefined7 uStack_257;
  undefined1 uStack_250;
  undefined2 uStack_24f;
  undefined1 uStack_24d;
  undefined8 uStack_248;
  ushort auStack_240 [8];
  undefined8 uStack_230;
  byte abStack_228 [16];
  undefined8 uStack_218;
  long lStack_210;
  undefined1 *puStack_200;
  code *pcStack_1f8;
  long *plStack_1f0;
  ulong uStack_1e8;
  ulong uStack_1e0;
  ulong uStack_1d8;
  ulong uStack_1d0;
  ulong uStack_1c8;
  long *plStack_1c0;
  long lStack_1b8;
  ulong uStack_1b0;
  ulong uStack_1a8;
  uint uStack_1a0;
  byte bStack_198;
  byte bStack_190;
  byte bStack_188;
  undefined1 uStack_180;
  int iStack_178;
  undefined4 uStack_174;
  uint uStack_170;
  uint uStack_16c;
  byte abStack_168 [16];
  undefined8 uStack_158;
  byte abStack_150 [16];
  undefined8 uStack_140;
  byte abStack_138 [16];
  undefined8 uStack_128;
  byte abStack_120 [16];
  undefined8 uStack_110;
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
  
  lVar40 = tpidr_el0;
  uVar43 = (ulong)param_2;
  lStack_70 = *(long *)(lVar40 + 0x28);
  uVar45 = param_8 & 0xffffffff;
  uVar46 = (ulong)param_6;
  plVar47 = (long *)(param_5 & 0xffffffff);
  uVar39 = (ulong)param_4;
  plVar42 = (long *)(param_3 & 0xffffffff);
  uStack_16c = param_7;
  uVar25 = param_4;
  uVar18 = func_0x005ab2d8(0,param_4);
  func_0x005abf1c(0,uVar18);
  plVar34 = plVar42;
  uVar29 = func_0x00a58fe8(0,uVar39);
  uVar44 = 0;
  if ((uVar29 & 1) != 0) {
    uStack_170 = param_2;
    bStack_cc = func_0x00a5b3a4(1,plVar42);
    bStack_cc = bStack_cc & 1;
    uStack_d0 = 1;
    bStack_c4 = func_0x00a5b484(1,plVar42);
    bStack_c4 = bStack_c4 & 1;
    uStack_c8 = 2;
    uVar16 = func_0x00a5b564(1,plVar42);
    uStack_c0 = 4;
    uStack_bc = CONCAT31(uStack_bc._1_3_,uVar16) & 0xffffff01;
    bStack_b4 = func_0x00a5b644(1,plVar42);
    bStack_b4 = bStack_b4 & 1;
    uStack_b8 = 8;
    bStack_ac = func_0x00a5b7a0(1,plVar42);
    bStack_ac = bStack_ac & 1;
    uStack_b0 = 0x10;
    bStack_a4 = func_0x00a5b880(1,plVar42);
    bStack_a4 = bStack_a4 & 1;
    uStack_a8 = 0x20;
    bStack_9c = func_0x00a5b960(1,plVar42);
    bStack_9c = bStack_9c & 1;
    uStack_a0 = 0x40;
    bStack_94 = func_0x00a5bab0(1,plVar42);
    bStack_94 = bStack_94 & 1;
    uStack_98 = 0x80;
    bStack_8c = func_0x00a5b6c0(1,plVar42);
    bStack_8c = bStack_8c & 1;
    uStack_90 = 0x100;
    bStack_84 = func_0x00a5b9d0(1,plVar42);
    bStack_84 = bStack_84 & 1;
    uStack_88 = 0x200;
    bStack_7c = func_0x00a5ba40(1,plVar42);
    bStack_7c = bStack_7c & 1;
    uStack_80 = 0x400;
    bStack_74 = func_0x00a5bb20(1,plVar42);
    bStack_74 = bStack_74 & 1;
    uVar25 = (uint)&uStack_e9;
    uStack_78 = 0x800;
    func_0x0064f2e0(auStack_e8,&uStack_d0,0xc);
    uVar18 = func_0x00a58934(0,uVar39);
    uVar19 = func_0x005ab2d8(0,uVar39);
    uVar20 = func_0x005abf1c(0,uVar19);
    unaff_x25 = (ulong)uVar20;
    iVar21 = func_0x00a5a3d8(1,plVar42);
    plVar34 = plVar47;
    if (param_6 == 2) {
      uVar43 = (ulong)((iVar21 * param_19) / 500);
    }
    else {
      iVar21 = (iVar21 * param_19) / 100;
      uVar43 = (ulong)iVar21;
      if (param_6 == 1) {
        bStack_108 = 0x20;
        uStack_f7 = 0;
        uStack_ff = 0x735f735f657661;
        uStack_f8 = 0x74;
        uStack_107 = 0x775f656c74746162;
        plVar34 = (long *)0x1e;
        iVar22 = func_0x008e3f14(param_1 + 0x1478,&bStack_108);
        lVar35 = SUB168(SEXT816((long)iVar21 * (long)iVar22) * SEXT816(-0x5c28f5c28f5c28f5),8) +
                 (long)iVar21 * (long)iVar22;
        uVar43 = (lVar35 >> 6) - (lVar35 >> 0x3f);
        if ((bStack_108 & 1) != 0) {
          func_0x00bc3350(CONCAT62(uStack_f6,CONCAT11(uStack_f7,uStack_f8)));
        }
      }
    }
    if ((uStack_16c & 1) != 0) {
      plVar34 = (long *)0x1;
      func_0x00a6073c(0,uVar39);
      uVar43 = uVar43 << 1;
    }
    uVar23 = func_0x00a5a220(1,plVar42);
    uVar46 = (ulong)uVar23;
    uVar24 = func_0x00a5a194(1,plVar42);
    plVar47 = (long *)(ulong)uVar24;
    iVar21 = func_0x00a5e1a8(1,plVar42);
    if ((int)uVar23 <= (int)(iVar21 * uVar24) / 100) {
      uVar23 = func_0x00a5a194(1,plVar42);
      uVar46 = (ulong)uVar23;
      iVar21 = func_0x00a5e1a8(1,plVar42);
      if (99 < (int)(iVar21 * uVar23)) {
        uVar23 = func_0x00a5e234(1,plVar42);
        uVar46 = (ulong)uVar23;
        func_0x00a5e234(1,plVar42);
        uVar43 = (long)(uVar43 * (long)(int)(uVar23 + 100)) / 100;
      }
    }
    iVar21 = func_0x00a60c98(1,plVar42);
    if ((0 < iVar21) && (iVar21 = func_0x00a60d78(1,plVar42), 0 < iVar21)) {
      iVar21 = func_0x00a60e04(1,plVar42);
      uVar43 = (long)(uVar43 * (long)iVar21) / 100;
    }
    if ((param_8 & 1) != 0) {
      uVar23 = func_0x00a5f28c(1,plVar42);
      uVar45 = (ulong)uVar23;
      func_0x00a5f28c(1,plVar42);
      plVar34 = (long *)0x1;
      func_0x00a614dc(0,uVar39);
      uVar43 = (long)(uVar43 * (long)(int)(uVar23 + 100)) / 100;
    }
    if (param_4 == 0) {
      uVar44 = func_0x00a5ea34(1,plVar42);
      uVar29 = uVar43 << 2;
      if ((uVar44 & 1) == 0) {
        uVar29 = uVar43;
      }
LAB_006d8984:
      if (uStack_170 == 1) {
        iVar21 = func_0x00a62944(0,param_4);
        if (0 < iVar21) {
          iVar21 = func_0x00a62944(0,param_4);
          func_0x00a62944(0,param_4);
          goto LAB_006d8b44;
        }
      }
      else if (uStack_170 == 3) {
        iVar21 = func_0x00a62c00(0,param_4);
        if (0 < iVar21) {
          iVar21 = func_0x00a62c00(0,param_4);
          func_0x00a62c00(0,param_4);
          goto LAB_006d8b44;
        }
      }
      else if ((uStack_170 == 2) && (iVar21 = func_0x00a62b74(0,param_4), 0 < iVar21)) {
        iVar21 = func_0x00a62b74(0,param_4);
        func_0x00a62b74(0,param_4);
LAB_006d8b44:
        uVar29 = (long)(uVar29 * (long)(100 - iVar21)) / 100;
      }
      if ((1 < (int)uVar20) &&
         (iVar21 = func_0x00653884(param_1 + 0x1538,uVar18,1,0,auStack_e8,0), 0 < iVar21)) {
        uVar29 = (long)(uVar29 * (long)(100 - iVar21)) / 100;
      }
      uVar46 = 0x21b8;
      uVar18 = func_0x0062b458(param_1 + 0x21b8);
      iVar21 = func_0x0067c144(param_1 + 0x421a50,uVar18);
      uVar18 = func_0x0062b3b4(param_1 + 0x21b8);
      uVar23 = func_0x0067c168(param_1 + 0x421a50,uVar18);
      uVar45 = (ulong)uVar23;
      uVar25 = 0xffffffff;
      bVar17 = func_0x008b18c4(param_1 + 0x468,0xffffffff,0xffffffff);
      uVar20 = iVar21 + 1;
      bVar4 = (bVar17 & *(int *)(param_1 + 0x4b4) != -1) != 0;
      if (bVar4) {
        uVar20 = 1;
      }
      unaff_x25 = (ulong)uVar20;
      iVar21 = 1;
      if (!bVar4) {
        iVar21 = uVar23 + 1;
      }
      if (param_4 != 0) {
        uVar43 = func_0x00a5b3a4(1,1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,100,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b484(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x65,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b564(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x66,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b644(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x67,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b7a0(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x68,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b880(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x69,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b960(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6a,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5bab0(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6b,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b6c0(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6c,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5b9d0(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6d,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5ba40(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6e,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        uVar43 = func_0x00a5bb20(1,plVar42);
        if ((uVar43 & 1) != 0) {
          uVar33 = func_0x0062b5dc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0x6f,unaff_x25);
          if (iVar22 != 0) {
            uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
          }
        }
        if (uStack_170 == 1) {
          uVar33 = func_0x0062b6bc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0xc9,iVar21);
        }
        else {
          if (uStack_170 != 2) goto LAB_006d90a8;
          uVar33 = func_0x0062b6bc(param_1 + 0x21b8);
          iVar22 = func_0x00629258(uVar33,0xcb,iVar21);
        }
        if (iVar22 != 0) {
          uVar29 = (long)(uVar29 * (long)(10000 - iVar22)) / 10000;
        }
      }
LAB_006d90a8:
      uVar20 = func_0x00a5b644(0,param_4);
      uVar43 = uVar29 & ((long)uVar29 >> 0x3f ^ 0xffffffffffffffffU);
      if (((uStack_16c | uVar20 ^ 0xffffffff) & 1) == 0 && 1 < (long)uVar29) {
        uVar43 = 1;
      }
      bVar17 = func_0x00a5ac18(1,plVar42,param_4);
      if ((param_4 != 0) && ((bVar17 & param_16 & 1) != 0)) {
        uVar29 = func_0x00a60184(0,param_4);
        if ((uVar29 & 1) == 0) {
          uVar20 = func_0x00a5a194(0,param_4);
          unaff_x25 = (ulong)uVar20;
          iVar22 = func_0x00a5d0d4(1,plVar42);
          iVar22 = func_0x0043ed6c((int)(iVar22 * uVar20) / 100,1);
          iVar26 = func_0x00a62ae8(0,param_4);
          uVar29 = SUB168(SEXT816((long)(100 - iVar26) * (long)iVar22) *
                          SEXT816(-0x5c28f5c28f5c28f5),8) + (long)(100 - iVar26) * (long)iVar22;
          iVar22 = func_0x0043ed6c((int)(uVar29 >> 6) - (int)((long)uVar29 >> 0x3f),1);
          uVar33 = func_0x0062b6bc(param_1 + 0x21b8);
          iVar21 = func_0x00629258(uVar33,0xcd,iVar21);
          plVar42 = (long *)(long)iVar22;
          if (iVar21 != 0) {
            plVar42 = (long *)(((long)iVar22 * (long)(10000 - iVar21)) / 10000);
          }
          func_0x00a61730(0,param_4,1);
          func_0x00a62ae8(0,param_4);
          uVar43 = (long)plVar42 + uVar43;
        }
        else {
          func_0x00a60f1c(0,param_4);
        }
      }
      if (uStack_170 == 1) {
        uVar29 = func_0x00a5f900(0,param_4);
LAB_006d924c:
        if ((uVar29 & 1) != 0) {
          uVar43 = 0;
          lVar35 = param_1 + (long)(int)param_4 * 1000;
          *(undefined4 *)(lVar35 + 0x83a78) = 0;
          *(undefined4 *)(lVar35 + 0x83a7c) = 1;
        }
      }
      else {
        if (uStack_170 == 3) {
          uVar29 = func_0x00a602ac(0,param_4);
          goto LAB_006d924c;
        }
        if (uStack_170 == 2) {
          uVar29 = func_0x00a60218(0,param_4);
          goto LAB_006d924c;
        }
      }
      plVar34 = (long *)(uVar43 & 0xffffffff);
      func_0x00a60488(0,param_4);
      uVar44 = 1;
    }
    else {
      uVar29 = func_0x00a5c0dc(1,plVar42);
      if ((uVar29 & 1) == 0) {
LAB_006d89c4:
        uVar46 = 0;
LAB_006d89c8:
        iVar21 = func_0x00a61c54(0,param_4);
        if (iVar21 < 1) {
          plVar34 = plVar42;
          uVar29 = func_0x00a5ac18(0,param_4);
          if (((uVar29 & 1) == 0) && (uVar29 = func_0x00a5db54(0,param_4), (uVar29 & 1) == 0)) {
            if ((int)uVar46 == 0) {
LAB_006d9614:
              iVar21 = func_0x00a62c8c(0,param_4);
              if (0 < iVar21) {
                uVar23 = func_0x0043ea60(100);
                uVar45 = (ulong)uVar23;
                iVar21 = func_0x00a62c8c(0,param_4);
                if ((int)uVar23 < iVar21) {
                  uVar18 = func_0x00a62d18(0,param_4);
                  func_0x00a61c94(0,param_4,uVar18);
                  plVar34 = (long *)0x1;
                  func_0x00a61648(0,param_4);
                  func_0x0040cb78(&uStack_d0,&UNK_002a0641);
                  func_0x00a62c8c(0,param_4);
                  goto LAB_006d9690;
                }
              }
              uVar29 = func_0x00a5ac18(1,plVar42,param_4);
              if ((uVar29 & 1) != 0) {
                if (uStack_170 == 3) {
                  uVar29 = func_0x00a602ac(0,param_4);
LAB_006d9740:
                  if ((uVar29 & 1) != 0) goto LAB_006d97a8;
                }
                else {
                  if (uStack_170 == 2) {
                    uVar29 = func_0x00a60218(0,param_4);
                    goto LAB_006d9740;
                  }
                  if (uStack_170 == 1) {
                    uVar29 = func_0x00a5f900(0,param_4);
                    goto LAB_006d9740;
                  }
                }
                uStack_1a0 = param_12 & 1;
                bStack_188 = param_18 & 1;
                bStack_190 = param_14 & 1;
                bStack_198 = param_13 & 1;
                uStack_180 = 0;
                BattleFn_0x005d6da0(param_1,1,plVar42,param_4,0x19,param_9 & 1,param_10 & 1,
                                    param_11 & 1);
              }
LAB_006d97a8:
              uVar29 = func_0x00a5eba8(0,param_4);
              if (((uVar29 & 1) != 0) && (uVar29 = func_0x00a5b9d0(1,plVar42), (uVar29 & 1) != 0)) {
                iVar21 = func_0x008700d4(param_1 + 0x4407e8,0x16,uVar18);
                func_0x0040cb78(&uStack_d0,&UNK_002a79d3);
                func_0x008700d4(param_1 + 0x4407e8,0x16,uVar18);
                iVar21 = (int)((ulong)((long)iVar21 * -0x51eb851f) >> 0x20);
                uVar43 = (((long)uVar43 / 10) * (long)(((iVar21 >> 5) - (iVar21 >> 0x1f)) + 5)) / 5;
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              uVar29 = func_0x00a5ec88(0,param_4);
              if (((uVar29 & 1) != 0) && (uVar29 = func_0x00a5ba40(1,plVar42), (uVar29 & 1) != 0)) {
                iVar21 = func_0x008700d4(param_1 + 0x4407e8,0x17,uVar18);
                func_0x0040cb78(&uStack_d0,&UNK_0028ed3d);
                func_0x008700d4(param_1 + 0x4407e8,0x17,uVar18);
                iVar21 = (int)((ulong)((long)iVar21 * -0x51eb851f) >> 0x20);
                uVar43 = (((long)uVar43 / 5) * (long)(((iVar21 >> 5) - (iVar21 >> 0x1f)) + 5)) / 5;
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              uVar29 = func_0x00a5ed68(0,param_4);
              if (((uVar29 & 1) != 0) && (uVar29 = func_0x00a5c020(1,plVar42), (uVar29 & 1) != 0)) {
                iVar21 = func_0x00a5efb8(0,param_4);
                func_0x0040cb78(&uStack_d0,&UNK_0028ed17);
                func_0x00a5efb8(0,param_4);
                uVar43 = (long)(uVar43 * (long)iVar21) / 100;
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              uVar29 = func_0x00a5f364(0,param_4);
              if (((uVar29 & 1) != 0) && (uVar29 = func_0x00a5c0dc(1,plVar42), (uVar29 & 1) != 0)) {
                func_0x0040cb78(abStack_120,&UNK_0029f87c);
                iVar21 = func_0x008e3f14(param_1 + 0x1478,abStack_120,700);
                if ((abStack_120[0] & 1) != 0) {
                  func_0x00bc3350(uStack_110);
                }
                func_0x0040cb78(&uStack_d0,&UNK_0029213f);
                func_0x0040cb78(abStack_138,&UNK_0029f87c);
                func_0x008e3f14(param_1 + 0x1478,abStack_138,700);
                uVar43 = (long)(uVar43 * (long)iVar21) / 1000;
                if ((abStack_138[0] & 1) != 0) {
                  func_0x00bc3350(uStack_128);
                }
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              uVar29 = func_0x00a5f5ec(0,param_4);
              if (((uVar29 & 1) != 0) && (uVar29 = func_0x00a5c198(1,plVar42), (uVar29 & 1) != 0)) {
                func_0x0040cb78(abStack_150,&UNK_0028ad7d);
                iVar21 = func_0x008e3f14(param_1 + 0x1478,abStack_150,700);
                if ((abStack_150[0] & 1) != 0) {
                  func_0x00bc3350(uStack_140);
                }
                func_0x0040cb78(&uStack_d0,&UNK_002a582a);
                func_0x0040cb78(abStack_168,&UNK_0028ad7d);
                func_0x008e3f14(param_1 + 0x1478,abStack_168,700);
                uVar43 = (long)(uVar43 * (long)iVar21) / 1000;
                if ((abStack_168[0] & 1) != 0) {
                  func_0x00bc3350(uStack_158);
                }
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              uVar25 = func_0x008700d4(param_1 + 0x4407e8,0x19,uVar18);
              if ((0 < (int)uVar25) && (uVar29 = func_0x00a5c254(1,plVar42), (uVar29 & 1) != 0)) {
                func_0x0040cb78(&uStack_d0,&UNK_00290f45);
                lVar35 = uVar43 * 1000;
                uVar43 = 0;
                if ((ulong)uVar25 != 0) {
                  uVar43 = lVar35 / (long)(ulong)uVar25;
                }
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              iVar21 = func_0x00a5fe34(0,param_4);
              if ((0 < iVar21) && ((param_15 & 1) != 0)) {
                func_0x00a60660(0,param_4,2);
              }
              iVar21 = func_0x00a6177c(0,param_4);
              uVar29 = uVar43;
              if ((0 < iVar21) && ((param_17 & 1) != 0)) {
                func_0x00a61848(0,param_4,2);
              }
              goto LAB_006d8984;
            }
          }
          else {
            iVar21 = func_0x00a61528(0,param_4);
            if (iVar21 < 1) {
              uVar23 = func_0x0043ea60(100);
              uVar45 = (ulong)uVar23;
              iVar21 = func_0x00a6006c(0,param_4);
              if ((int)uVar23 < iVar21) {
                uVar18 = BattleFn_0x005d6b98(param_1,param_4,plVar42);
                uVar20 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar18,100);
                param_1 = (ulong)uVar20;
                iVar21 = func_0x00a600f8(0,param_4);
                func_0x00a61568(0,param_4,(int)(iVar21 * (uVar20 + 0x5dc)) / 0x5dc);
                plVar34 = (long *)0x1;
                func_0x00a61648(0,param_4);
                func_0x0040cb78(&uStack_d0,&UNK_00289e7e);
                func_0x00a6006c(0,param_4);
                func_0x00a6006c(0,param_4);
LAB_006d9690:
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
              }
              else if ((int)uVar46 == 0) {
                uStack_174 = BattleFn_0x005d6b98(param_1,param_4,plVar42);
                uVar29 = func_0x00a5e500(0,param_4);
                if ((uVar29 & 1) != 0) {
                  iStack_178 = func_0x00a1fb18(&UNK_00290568 + param_1,uStack_174,100);
                  if ((int)uVar20 < 2) {
                    plVar47 = (long *)0x0;
                  }
                  else {
                    uVar25 = 1;
                    uVar29 = func_0x00653884(param_1 + 0x1538,uVar18,2,1,auStack_e8,0);
                    plVar47 = (long *)(uVar29 & 0xffffffff);
                  }
                  uVar46 = 0x4407e8;
                  iVar21 = func_0x008700d4(param_1 + 0x4407e8,0xe,uVar18);
                  func_0x0040cb78(&uStack_d0,&UNK_00294690);
                  func_0x008700d4(param_1 + 0x4407e8,0xe,uVar18);
                  if ((uStack_d0 & 1) != 0) {
                    func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                  }
                  uVar29 = func_0x005ab294();
                  uVar43 = (((((long)(uVar43 * (long)(0x5dc - iStack_178)) / 3000) *
                             (long)(100 - iVar21)) / 100) * (long)(100 - (int)plVar47)) / 100;
                  if ((uVar29 & 1) != 0) {
                    uVar19 = func_0x00a5aa1c(0,param_4);
                    uVar19 = func_0x00999ef0(param_1 + 0x400,0x10,uVar19);
                    func_0x00a5a9c8(0,param_4,uVar19);
                  }
                }
                uVar29 = func_0x00a5e5e0(0,param_4);
                if ((uVar29 & 1) != 0) {
                  iStack_178 = func_0x00a1fb18(&UNK_00290568 + param_1,uStack_174,100);
                  if ((int)uVar20 < 2) {
                    plVar47 = (long *)0x0;
                  }
                  else {
                    uVar25 = 0;
                    uVar29 = func_0x00653884(param_1 + 0x1538,uVar18,4,0,auStack_e8,0);
                    plVar47 = (long *)(uVar29 & 0xffffffff);
                  }
                  uVar46 = 0x4407e8;
                  iVar21 = func_0x008700d4(param_1 + 0x4407e8,0x10,uVar18);
                  func_0x0040cb78(&uStack_d0,&UNK_002a584e);
                  func_0x008700d4(param_1 + 0x4407e8,0x10,uVar18);
                  if ((uStack_d0 & 1) != 0) {
                    func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                  }
                  uVar29 = func_0x005ab294();
                  uVar43 = (((((long)(uVar43 * (long)(0x5dc - iStack_178)) / 6000) *
                             (long)(100 - iVar21)) / 100) * (long)(100 - (int)plVar47)) / 100;
                  if ((uVar29 & 1) != 0) {
                    uVar19 = func_0x00a5aa1c(0,param_4);
                    uVar19 = func_0x00999ef0(param_1 + 0x400,0x11,uVar19);
                    func_0x00a5a9c8(0,param_4,uVar19);
                  }
                }
                uVar29 = func_0x00a5e7a0(0,param_4);
                if ((uVar29 & 1) != 0) {
                  iVar21 = func_0x00a1fb18(&UNK_00290568 + param_1,uStack_174,100);
                  func_0x0040cb78(&uStack_d0,&UNK_00292160);
                  if ((uStack_d0 & 1) != 0) {
                    func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                  }
                  uVar29 = func_0x005ab294();
                  uVar43 = (long)(uVar43 * (long)(0x834 - iVar21)) / 0x3138;
                  if ((uVar29 & 1) != 0) {
                    uVar19 = func_0x00a5aa1c(0,param_4);
                    uVar19 = func_0x00999ef0(param_1 + 0x400,0x12,uVar19);
                    func_0x00a5a9c8(0,param_4,uVar19);
                  }
                }
                goto LAB_006d9614;
              }
            }
          }
        }
      }
      else {
        iVar21 = func_0x00a61ae0(0,param_4);
        if (iVar21 < 1) {
          uVar23 = func_0x0043ea60(100);
          uVar45 = (ulong)uVar23;
          iVar21 = func_0x00a5f444(0,param_4);
          if (iVar21 <= (int)uVar23) goto LAB_006d89c4;
          uVar19 = func_0x00a5f518(0,param_4);
          func_0x00a61b20(0,param_4,uVar19);
          plVar34 = (long *)0x1;
          func_0x00a61648(0,param_4);
          func_0x00a5f444(0,param_4);
          func_0x00a5f444(0,param_4);
          uVar46 = 1;
          goto LAB_006d89c8;
        }
      }
      uVar44 = 0;
    }
    func_0x0065b710(auStack_e8,uStack_e0);
  }
  if (*(long *)(lVar40 + 0x28) == lStack_70) {
    return uVar44;
  }
  auVar49 = func_0x00bc3380();
  uVar29 = auVar49._8_8_;
  lVar30 = auVar49._0_8_;
  pcStack_1f8 = BattleFn_0x005d9d6c;
  lVar35 = tpidr_el0;
  lStack_210 = *(long *)(lVar35 + 0x28);
  uVar48 = uVar29 & 0xffffffff;
  puStack_200 = &stack0xffffffffffffffa0;
  plStack_1f0 = plVar47;
  uStack_1e8 = uVar46;
  uStack_1e0 = uVar45;
  uStack_1d8 = unaff_x25;
  uStack_1d0 = uVar44;
  uStack_1c8 = uVar43;
  plStack_1c0 = plVar42;
  lStack_1b8 = lVar40;
  uStack_1b0 = param_1;
  uStack_1a8 = uVar39;
  func_0x00a589e0(abStack_228,0);
  if ((int)uVar25 < 1) {
    auStack_240[0] = 0;
  }
  else {
    bStack_258 = 0x14;
    uStack_24f = 0x29ae;
    uStack_257 = 0xe79e9be5642528;
    uStack_250 = 0x9b;
    uStack_24d = 0;
    func_0x00416d84(auStack_240,&bStack_258,0,uVar25 + 1);
    if ((auStack_240[0] & 1) != 0) {
      func_0x00bc3350(uStack_230);
    }
    if ((bStack_258 & 1) != 0) {
      func_0x00bc3350(uStack_248);
    }
  }
  if ((abStack_228[0] & 1) != 0) {
    func_0x00bc3350(uStack_218);
  }
  uVar39 = (ulong)uVar25;
  uVar43 = (ulong)uVar25;
  BattleFn_0x005da618(lVar30,0,uVar48,uVar39);
  iVar21 = *(int *)(&UNK_0038816c + lVar30);
  iVar22 = *(int *)(&UNK_00388180 + lVar30);
  bVar4 = iVar21 != 0;
  bVar5 = iVar22 != 0;
  bVar6 = *(int *)(&UNK_00388170 + lVar30) != 0;
  bVar7 = *(int *)(&UNK_00388174 + lVar30) != 0;
  bVar8 = *(int *)(&UNK_00388178 + lVar30) != 0;
  bVar9 = *(int *)(&UNK_0038817c + lVar30) != 0;
  bVar10 = *(int *)(&UNK_00388184 + lVar30) != 0;
  bVar11 = *(int *)(&UNK_0038818c + lVar30) != 0;
  bVar12 = *(int *)(&UNK_00388188 + lVar30) != 0;
  bVar13 = *(int *)(&UNK_00388190 + lVar30) != 0;
  bVar14 = *(int *)(&UNK_00388194 + lVar30) != 0;
  bVar15 = *(int *)(&UNK_00388198 + lVar30) != 0;
  uVar18 = func_0x00a5f6cc(0,uVar48);
  lVar40 = *plVar34;
  if (plVar34[1] != lVar40) {
    uVar44 = 0;
    do {
      uVar20 = *(uint *)(lVar40 + uVar44 * 4);
      func_0x00a589e0(abStack_270,1,uVar20);
      if ((abStack_270[0] & 1) != 0) {
        func_0x00bc3350(uStack_260);
      }
      uVar39 = (ulong)uVar20;
      uVar45 = BattleFn_0x005d5498(lVar30,0,uVar48,uVar39,uVar43,0,iVar21 != 0,iVar22 != 0);
      if ((uVar45 & 1) != 0) {
        uVar45 = func_0x00a58fa0(0,uVar48);
        if (((uVar45 & 1) == 0) || (iVar26 = func_0x00a58ba4(1,uVar20), iVar26 != 0xe)) {
          uVar45 = func_0x00a5c8d4(0,uVar48,uVar43);
          lVar40 = lVar30 + (long)(int)uVar20 * 1000;
          if ((uVar45 & 1) == 0) {
            *(undefined4 *)(lVar40 + 0x901c0) = 0;
          }
          else {
            *(undefined4 *)(lVar40 + 0x901c0) = 1;
          }
        }
        else {
          *(undefined4 *)(lVar30 + (long)(int)uVar20 * 1000 + 0x901c0) = 2;
        }
      }
      lVar40 = *plVar34;
      uVar44 = uVar44 + 1;
    } while (uVar44 < (ulong)(plVar34[1] - lVar40 >> 2));
  }
  uVar44 = func_0x00a5a878(0,uVar48);
  if ((uVar44 & 1) != 0) {
    plVar42 = (long *)(&UNK_00338900 + lVar30);
    iVar21 = func_0x00a5c4a0(0,uVar48);
    uVar19 = auVar49._8_4_;
    if (0 < iVar21) {
      iVar21 = func_0x0043ea60(100);
      func_0x00a5c37c(0,uVar48);
      func_0x00a5c4a0(0,uVar48);
      func_0x00a5c4a0(0,uVar48);
      iVar22 = func_0x00a5c4a0(0,uVar48);
      if (iVar21 < iVar22) {
        lVar40 = 0;
        puVar41 = &UNK_00333e28 + lVar30;
LAB_006da144:
        if ((*(int *)(puVar41 + -0x2c) != 0) || (*(int *)(puVar41 + -0x24) != 0)) goto LAB_006da134;
        iVar21 = func_0x00a5c37c(0,uVar48);
        *(undefined4 *)(puVar41 + -0x2c) = 1;
        *(undefined4 *)(puVar41 + -0x28) = uVar19;
        *puVar41 = iVar21 == 1;
        *(undefined8 *)(puVar41 + -0x24) = 1;
        uVar27 = func_0x00a5919c(0,uVar29 & 0xffffffff);
        *(undefined4 *)(puVar41 + -0x1c) = uVar27;
        uVar27 = func_0x00a5c4e0(0,uVar48);
        *(undefined4 *)(puVar41 + -0x18) = uVar27;
        *(uint *)(puVar41 + -0x14) = uVar25;
        puVar41[-0x10] = bVar4;
        puVar41[-8] = bVar5;
        *(undefined4 *)(puVar41 + -4) = uVar18;
        puVar41[-0xf] = bVar6;
        puVar41[-0xe] = bVar7;
        puVar41[-0xd] = bVar8;
        puVar41[-0xc] = bVar9;
        puVar41[-0xb] = bVar10;
        puVar41[-10] = bVar11;
        puVar41[-9] = bVar12;
        puVar41[-7] = bVar13;
        puVar41[-6] = bVar14;
        lVar38 = 0x33;
        puVar41[-5] = bVar15;
        puVar36 = &UNK_003881a0 + (lVar30 - lVar40);
        do {
          lVar38 = lVar38 + -1;
          *puVar36 = 0;
          puVar36 = puVar36 + 200;
        } while (lVar38 != 0);
      }
    }
LAB_006da204:
    iVar21 = func_0x00a5d1a0(0,uVar48);
    if (0 < iVar21) {
      iVar21 = func_0x0043ea60(100);
      func_0x00a5d1a0(0,uVar48);
      func_0x00a5d1a0(0,uVar29 & 0xffffffff);
      iVar22 = func_0x00a5d1a0(0,uVar29 & 0xffffffff);
      if (iVar21 < iVar22) {
        puVar31 = (undefined8 *)func_0x00bc3330(0x48);
        puVar31[8] = 0;
        bStack_258 = (byte)puVar31;
        uStack_257 = (undefined7)((ulong)puVar31 >> 8);
        puVar31[1] = 0;
        *puVar31 = 0;
        puVar31[3] = 0;
        puVar31[2] = 0;
        puVar3 = *(undefined8 **)(&UNK_00338908 + lVar30);
        puVar32 = *(undefined8 **)(&UNK_00338910 + lVar30);
        puVar31[5] = 0;
        puVar31[4] = 0;
        puVar31[7] = 0;
        puVar31[6] = 0;
        puVar31[6] = puVar31 + 7;
        if (puVar3 < puVar32) {
          puVar32 = puVar3 + 1;
          *puVar3 = puVar31;
          *(undefined8 **)(&UNK_00338908 + lVar30) = puVar32;
        }
        else {
          puVar32 = (undefined8 *)func_0x005c8c54(plVar42,&bStack_258);
          lVar40 = CONCAT71(uStack_257,bStack_258);
          *(undefined8 **)(&UNK_00338908 + lVar30) = puVar32;
          bStack_258 = 0;
          uStack_257 = 0;
          if (lVar40 != 0) {
            func_0x0058c04c(lVar40 + 0x30,*(undefined8 *)(lVar40 + 0x38));
            func_0x00bc3350(lVar40);
            puVar32 = *(undefined8 **)(&UNK_00338908 + lVar30);
          }
        }
        if (puVar32 != (undefined8 *)*plVar42) {
          puVar37 = (undefined4 *)puVar32[-1];
          *puVar37 = 0;
          puVar37[1] = uVar19;
          puVar37[2] = 0;
          iVar21 = func_0x00a5919c(0,uVar29 & 0xffffffff);
          iVar22 = func_0x00a5d22c(0,uVar48);
          func_0x00a5d2b8(0,uVar48);
          func_0x0043ecf8();
          iVar26 = func_0x0043ea60();
          iVar28 = func_0x00a5d2b8(0,uVar48);
          if (*(long *)(&UNK_00338908 + lVar30) != *plVar42) {
            iVar2 = -iVar26;
            if (iVar28 < 1) {
              iVar2 = iVar26;
            }
            *(int *)(*(long *)(*(long *)(&UNK_00338908 + lVar30) + -8) + 0xc) =
                 (iVar21 - iVar22) + iVar2;
            uVar27 = func_0x00a5d344(0,uVar48);
            if (*(long *)(&UNK_00338908 + lVar30) != *plVar42) {
              lVar40 = *(long *)(*(long *)(&UNK_00338908 + lVar30) + -8);
              *(bool *)(lVar40 + 0x18) = bVar4;
              *(bool *)(lVar40 + 0x20) = bVar5;
              *(undefined4 *)(lVar40 + 0x10) = uVar27;
              *(uint *)(lVar40 + 0x14) = uVar25;
              *(bool *)(lVar40 + 0x19) = bVar6;
              *(bool *)(lVar40 + 0x1a) = bVar7;
              *(bool *)(lVar40 + 0x1b) = bVar8;
              *(bool *)(lVar40 + 0x1c) = bVar9;
              *(bool *)(lVar40 + 0x1d) = bVar10;
              *(bool *)(lVar40 + 0x1e) = bVar11;
              *(bool *)(lVar40 + 0x1f) = bVar12;
              *(bool *)(lVar40 + 0x21) = bVar13;
              *(bool *)(lVar40 + 0x23) = bVar15;
              *(bool *)(lVar40 + 0x22) = bVar14;
              *(undefined4 *)(lVar40 + 0x24) = uVar18;
              iVar21 = func_0x00a5d160(0,uVar48);
              if (*(long *)(&UNK_00338908 + lVar30) != *plVar42) {
                lVar40 = *(long *)(*(long *)(&UNK_00338908 + lVar30) + -8);
                *(bool *)(lVar40 + 0x28) = iVar21 != 0;
                *(undefined4 *)(lVar40 + 0x2c) = 0;
                goto LAB_006da3e0;
              }
            }
          }
        }
        if (*(long *)(lVar35 + 0x28) == lStack_210) {
          uVar33 = func_0x005c8c40(plVar42);
          BattleFn_0x005daa18(&bStack_258);
          if (*(long *)(lVar35 + 0x28) == lStack_210) {
            func_0x00bbf40c(uVar33);
          }
        }
        goto LAB_006da614;
      }
    }
LAB_006da3e0:
    uVar44 = func_0x00a5d8d8(0,uVar48);
    if (0 < (int)uVar44) {
      iVar21 = func_0x0043ea60(100);
      func_0x00a5d8d8(0,uVar48);
      func_0x00a5d8d8(0,uVar48);
      uVar44 = func_0x00a5d8d8(0,uVar48);
      if (iVar21 < (int)uVar44) {
        puVar31 = (undefined8 *)func_0x00bc3330(0x40);
        bStack_258 = (byte)puVar31;
        uStack_257 = (undefined7)((ulong)puVar31 >> 8);
        puVar31[5] = 0;
        puVar31[4] = 0;
        puVar31[1] = 0;
        *puVar31 = 0;
        puVar3 = *(undefined8 **)(&UNK_00338938 + lVar30);
        puVar32 = *(undefined8 **)(&UNK_00338940 + lVar30);
        puVar31[3] = 0;
        puVar31[2] = 0;
        puVar31[7] = 0;
        puVar31[6] = 0;
        puVar31[5] = puVar31 + 6;
        if (puVar3 < puVar32) {
          puVar32 = puVar3 + 1;
          *puVar3 = puVar31;
          *(undefined8 **)(&UNK_00338938 + lVar30) = puVar32;
        }
        else {
          puVar32 = (undefined8 *)func_0x006e0280(&UNK_00338930 + lVar30,&bStack_258);
          lVar40 = CONCAT71(uStack_257,bStack_258);
          *(undefined8 **)(&UNK_00338938 + lVar30) = puVar32;
          bStack_258 = 0;
          uStack_257 = 0;
          if (lVar40 != 0) {
            func_0x005c8e50(lVar40 + 0x28,*(undefined8 *)(lVar40 + 0x30));
            func_0x00bc3350(lVar40);
            puVar32 = *(undefined8 **)(&UNK_00338938 + lVar30);
          }
        }
        puVar37 = (undefined4 *)puVar32[-1];
        *puVar37 = 0;
        puVar37[1] = uVar19;
        puVar37[2] = 0;
        iVar22 = func_0x00a5919c(0,uVar48);
        iVar26 = func_0x00a5d964(0,uVar48);
        func_0x00a5d9f0(0,uVar48);
        func_0x0043ecf8();
        iVar28 = func_0x0043ea60();
        uVar44 = func_0x00a5d9f0(0,uVar48);
        iVar21 = -iVar28;
        if ((int)uVar44 < 1) {
          iVar21 = iVar28;
        }
        lVar40 = *(long *)(*(long *)(&UNK_00338938 + lVar30) + -8);
        *(int *)(lVar40 + 0xc) = (iVar22 - iVar26) + iVar21;
        *(uint *)(lVar40 + 0x10) = uVar25;
        *(bool *)(lVar40 + 0x14) = bVar4;
        *(bool *)(lVar40 + 0x1c) = bVar5;
        *(bool *)(lVar40 + 0x15) = bVar6;
        *(bool *)(lVar40 + 0x16) = bVar7;
        *(bool *)(lVar40 + 0x17) = bVar8;
        *(bool *)(lVar40 + 0x18) = bVar9;
        *(bool *)(lVar40 + 0x19) = bVar10;
        *(bool *)(lVar40 + 0x1a) = bVar11;
        *(bool *)(lVar40 + 0x1b) = bVar12;
        *(bool *)(lVar40 + 0x1d) = bVar13;
        *(bool *)(lVar40 + 0x1f) = bVar15;
        *(bool *)(lVar40 + 0x1e) = bVar14;
        *(undefined4 *)(lVar40 + 0x20) = uVar18;
      }
    }
  }
  if (*(long *)(lVar35 + 0x28) == lStack_210) {
    return uVar44;
  }
LAB_006da614:
  auVar49 = func_0x00bc3380();
  lVar40 = auVar49._0_8_;
  uVar44 = uVar43 & 0xffffffff;
  uVar45 = auVar49._8_8_ & 0xffffffff;
  puVar1 = (uint *)(&UNK_0038816c + lVar40);
  *(undefined8 *)(&UNK_00388184 + lVar40) = 0;
  *(undefined8 *)(&UNK_0038817c + lVar40) = 0;
  *(undefined8 *)(&UNK_00388194 + lVar40) = 0;
  *(undefined8 *)(&UNK_0038818c + lVar40) = 0;
  *(undefined8 *)(&UNK_00388174 + lVar40) = 0;
  puVar1[0] = 0;
  puVar1[1] = 0;
  uVar29 = func_0x00a5a878(auVar49._8_8_ & 0xffffffff,uVar43 & 0xffffffff,uVar39 & 0xffffffff);
  if ((uVar29 & 1) == 0) {
    return uVar29;
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5e9a8(uVar45,uVar44);
  *puVar1 = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5e960(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5e9a8(uVar45,uVar44);
    func_0x00a5e9a8(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5c568(uVar45,uVar44);
  *(uint *)(&UNK_00388170 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5c520(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5c568(uVar45,uVar44);
    func_0x00a5c568(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5dbe4(uVar45,uVar44);
  *(uint *)(&UNK_00388174 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5db9c(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5dbe4(uVar45,uVar44);
    func_0x00a5dbe4(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5dd44(uVar45,uVar44);
  *(uint *)(&UNK_00388178 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5dcfc(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5dd44(uVar45,uVar44);
    func_0x00a5dd44(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5dea4(uVar45,uVar44);
  *(uint *)(&UNK_0038817c + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5de5c(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5dea4(uVar45,uVar44);
    func_0x00a5dea4(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5cfc0(uVar45,uVar44);
  *(uint *)(&UNK_00388180 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5cf78(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5cfc0(uVar45,uVar44);
    func_0x00a5cfc0(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5cd48(uVar45,uVar44);
  *(uint *)(&UNK_00388184 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5cd00(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5cd48(uVar45,uVar44);
    func_0x00a5cd48(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5f0e0(uVar45,uVar44);
  *(uint *)(&UNK_00388188 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5f098(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5f0e0(uVar45,uVar44);
    func_0x00a5f0e0(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5e090(uVar45,uVar44);
  *(uint *)(&UNK_0038818c + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5e048(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5e090(uVar45,uVar44);
    func_0x00a5e090(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5d048(uVar45,uVar44);
  *(uint *)(&UNK_00388190 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5d000(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5d048(uVar45,uVar44);
    func_0x00a5d048(uVar45,uVar44);
  }
  iVar21 = func_0x0043ea60(100);
  iVar22 = func_0x00a5f1b4(uVar45,uVar44);
  *(uint *)(&UNK_00388194 + lVar40) = (uint)(iVar21 < iVar22);
  uVar29 = func_0x00a5f16c(uVar45,uVar44);
  if ((uVar29 & 1) != 0) {
    func_0x00a5f1b4(uVar45,uVar44);
    func_0x00a5f1b4(uVar45,uVar44);
  }
  func_0x0043ea60(100);
  lVar40 = func_0x007fd748();
  return (ulong)*(uint *)(lVar40 + (long)auVar49._8_4_ * 51000 + (long)(int)uVar43 * 1000 + 0x83ce0)
  ;
LAB_006da134:
  lVar40 = lVar40 + -1;
  puVar41 = puVar41 + 0x30;
  if (lVar40 == -200) goto LAB_006da204;
  goto LAB_006da144;
}


