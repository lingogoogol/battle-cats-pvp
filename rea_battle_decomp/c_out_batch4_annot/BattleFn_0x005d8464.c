// ELF VMA: 0x5d8464
// Ghidra Addr: 0x006d8464 (ImageBase=0x100000)
// Size: 6016 bytes


undefined4
BattleFn_0x005d8464(long param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                   int param_6,uint param_7,ulong param_8,byte param_9,byte param_10,byte param_11,
                   byte param_12,byte param_13,byte param_14,byte param_15,byte param_16,
                   byte param_17,byte param_18,int param_19)

{
  long lVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 uVar16;
  long lVar17;
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
  
  lVar1 = tpidr_el0;
  lStack_70 = *(long *)(lVar1 + 0x28);
  uVar5 = BattleFn_0x004ab2d8(0,param_4);
  BattleFn_0x004abf1c(0,uVar5);
  uVar13 = func_0x00a58fe8(0,param_4,param_3);  /* 0x958fe8:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
  uVar5 = 0;
  if ((uVar13 & 1) == 0) goto LAB_006d96b0;
  bStack_cc = func_0x00a5b3a4(1,param_3);  /* 0x95b3a4:[slot*1000,team*0x1f0,team*51000|off=0x8394c|ldr w8, [x8, x9]] */
  bStack_cc = bStack_cc & 1;
  uStack_d0 = 1;
  bStack_c4 = func_0x00a5b484(1,param_3);  /* 0x95b484:[slot*1000,team*0x1f0,team*51000|off=0x839ac|ldr w8, [x8, x9]] */
  bStack_c4 = bStack_c4 & 1;
  uStack_c8 = 2;
  uVar3 = func_0x00a5b564(1,param_3);  /* 0x95b564:[slot*1000,team*0x1f0,team*51000|off=0x839b0|ldr w8, [x8, x9]] */
  uStack_c0 = 4;
  uStack_bc = CONCAT31(uStack_bc._1_3_,uVar3) & 0xffffff01;
  bStack_b4 = func_0x00a5b644(1,param_3);  /* 0x95b644:[slot*1000,team*0x1f0,team*51000|off=|ldr w8, [x8]] */
  bStack_b4 = bStack_b4 & 1;
  uStack_b8 = 8;
  bStack_ac = func_0x00a5b7a0(1,param_3);  /* 0x95b7a0:[slot*1000,team*0x1f0,team*51000|off=0x839bc|ldr w8, [x8, x9]] */
  bStack_ac = bStack_ac & 1;
  uStack_b0 = 0x10;
  bStack_a4 = func_0x00a5b880(1,param_3);  /* 0x95b880:[slot*1000,team*0x1f0,team*51000|off=0x839c0|ldr w8, [x8, x9]] */
  bStack_a4 = bStack_a4 & 1;
  uStack_a8 = 0x20;
  bStack_9c = func_0x00a5b960(1,param_3);  /* 0x95b960:[slot*1000,team*0x1f0,team*51000|off=0x839c4|ldr w8, [x8, x9]] */
  bStack_9c = bStack_9c & 1;
  uStack_a0 = 0x40;
  bStack_94 = func_0x00a5bab0(1,param_3);  /* 0x95bab0:[slot*1000,team*0x1f0,team*51000|off=0x83b50|ldr w8, [x8, x9]] */
  bStack_94 = bStack_94 & 1;
  uStack_98 = 0x80;
  bStack_8c = func_0x00a5b6c0(1,param_3);  /* 0x95b6c0:[slot*1000,team*0x1f0,team*51000|off=0x839b8|ldr w8, [x8, x9]] */
  bStack_8c = bStack_8c & 1;
  uStack_90 = 0x100;
  bStack_84 = func_0x00a5b9d0(1,param_3);  /* 0x95b9d0:[slot*1000,team*0x1f0,team*51000|off=0x83abc|ldr w8, [x8, x9]] */
  bStack_84 = bStack_84 & 1;
  uStack_88 = 0x200;
  bStack_7c = func_0x00a5ba40(1,param_3);  /* 0x95ba40:[slot*1000,team*0x1f0,team*51000|off=0x83b48|ldr w8, [x8, x9]] */
  bStack_7c = bStack_7c & 1;
  uStack_80 = 0x400;
  bStack_74 = func_0x00a5bb20(1,param_3);  /* 0x95bb20:[slot*1000,team*0x1f0,team*51000|off=0x83c10|ldr w8, [x8, x9]] */
  bStack_74 = bStack_74 & 1;
  uStack_78 = 0x800;
  func_0x0064f2e0(auStack_e8,&uStack_d0,0xc,&uStack_e9);
  uVar5 = func_0x00a58934(0,param_4);  /* 0x958934:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
  uVar6 = BattleFn_0x004ab2d8(0,param_4);
  iVar7 = BattleFn_0x004abf1c(0,uVar6);
  iVar8 = func_0x00a5a3d8(1,param_3,param_5);  /* 0x95a3d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
  if (param_6 == 2) {
    uVar13 = (ulong)((iVar8 * param_19) / 500);
  }
  else {
    iVar8 = (iVar8 * param_19) / 100;
    uVar13 = (ulong)iVar8;
    if (param_6 == 1) {
      bStack_108 = 0x20;
      uStack_f7 = 0;
      uStack_ff = 0x735f735f657661;  /* ascii(0x735f735f657661)='ave_s_s' */
      uStack_f8 = 0x74;
      uStack_107 = 0x775f656c74746162;  /* ascii(0x775f656c74746162)='battle_w' */
      iVar9 = func_0x008e3f14(param_1 + 0x1478,&bStack_108,0x1e);
      lVar17 = SUB168(SEXT816((long)iVar8 * (long)iVar9) * SEXT816(-0x5c28f5c28f5c28f5),8) +
               (long)iVar8 * (long)iVar9;
      uVar13 = (lVar17 >> 6) - (lVar17 >> 0x3f);
      if ((bStack_108 & 1) != 0) {
        func_0x00bc3350(CONCAT62(uStack_f6,CONCAT11(uStack_f7,uStack_f8)));
      }
    }
  }
  if ((param_7 & 1) != 0) {
    func_0x00a6073c(0,param_4,1);  /* 0x96073c:[slot*1000,team*51000|off=0x839a0|str w21, [x8, x9]] */
    uVar13 = uVar13 << 1;
  }
  iVar8 = func_0x00a5a220(1,param_3);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
  iVar9 = func_0x00a5a194(1,param_3);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
  iVar10 = func_0x00a5e1a8(1,param_3);  /* 0x95e1a8:[slot*1000,team*51000|off=0x83a24|ldr w0, [x8, x9]] */
  if (iVar8 <= (iVar10 * iVar9) / 100) {
    iVar8 = func_0x00a5a194(1,param_3);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
    iVar9 = func_0x00a5e1a8(1,param_3);  /* 0x95e1a8:[slot*1000,team*51000|off=0x83a24|ldr w0, [x8, x9]] */
    if (99 < iVar9 * iVar8) {
      iVar8 = func_0x00a5e234(1,param_3);  /* 0x95e234:[slot*1000,team*51000|off=0x83a28|ldr w0, [x8, x9]] */
      func_0x00a5e234(1,param_3);  /* 0x95e234:[slot*1000,team*51000|off=0x83a28|ldr w0, [x8, x9]] */
      uVar13 = (long)(uVar13 * (long)(iVar8 + 100)) / 100;
    }
  }
  iVar8 = func_0x00a60c98(1,param_3);  /* 0x960c98:[slot*1000,team*51000|off=0x83a34|ldr w0, [x8, x9]] */
  if ((0 < iVar8) && (iVar8 = func_0x00a60d78(1,param_3), 0 < iVar8)) {  /* 0x960d78:[slot*1000,team*51000|off=0x83a38|ldr w0, [x8, x9]] */
    iVar8 = func_0x00a60e04(1,param_3);  /* 0x960e04:[slot*1000,team*51000|off=0x83a44|ldr w0, [x8, x9]] */
    uVar13 = (long)(uVar13 * (long)iVar8) / 100;
  }
  if ((param_8 & 1) != 0) {
    iVar8 = func_0x00a5f28c(1,param_3);  /* 0x95f28c:[slot*1000,team*51000|off=0x83b98|ldr w0, [x8, x9]] */
    func_0x00a5f28c(1,param_3);  /* 0x95f28c:[slot*1000,team*51000|off=0x83b98|ldr w0, [x8, x9]] */
    func_0x00a614dc(0,param_4,1);  /* 0x9614dc:[slot*1000,team*51000|off=0x83ba0|str w21, [x8, x9]] */
    uVar13 = (long)(uVar13 * (long)(iVar8 + 100)) / 100;
  }
  if (param_4 == 0) {
    uVar15 = func_0x00a5ea34(1,param_3);  /* 0x95ea34:[slot*1000,team*51000|off=0x839f4|ldr w8, [x8, x9]] */
    uVar14 = uVar13 << 2;
    if ((uVar15 & 1) == 0) {
      uVar14 = uVar13;
    }
LAB_006d8984:
    if (param_2 == 1) {
      iVar8 = func_0x00a62944(0,param_4);  /* 0x962944:[slot*1000,team*51000|off=0x83b7c|ldr w0, [x8, x9]] */
      if (0 < iVar8) {
        iVar8 = func_0x00a62944(0,param_4);  /* 0x962944:[slot*1000,team*51000|off=0x83b7c|ldr w0, [x8, x9]] */
        func_0x00a62944(0,param_4);  /* 0x962944:[slot*1000,team*51000|off=0x83b7c|ldr w0, [x8, x9]] */
        goto LAB_006d8b44;
      }
    }
    else if (param_2 == 3) {
      iVar8 = func_0x00a62c00(0,param_4);  /* 0x962c00:[slot*1000,team*51000|off=0x83cdc|ldr w0, [x8, x9]] */
      if (0 < iVar8) {
        iVar8 = func_0x00a62c00(0,param_4);  /* 0x962c00:[slot*1000,team*51000|off=0x83cdc|ldr w0, [x8, x9]] */
        func_0x00a62c00(0,param_4);  /* 0x962c00:[slot*1000,team*51000|off=0x83cdc|ldr w0, [x8, x9]] */
        goto LAB_006d8b44;
      }
    }
    else if ((param_2 == 2) && (iVar8 = func_0x00a62b74(0,param_4), 0 < iVar8)) {  /* 0x962b74:[slot*1000,team*51000|off=0x83bdc|ldr w0, [x8, x9]] */
      iVar8 = func_0x00a62b74(0,param_4);  /* 0x962b74:[slot*1000,team*51000|off=0x83bdc|ldr w0, [x8, x9]] */
      func_0x00a62b74(0,param_4);  /* 0x962b74:[slot*1000,team*51000|off=0x83bdc|ldr w0, [x8, x9]] */
LAB_006d8b44:
      uVar14 = (long)(uVar14 * (long)(100 - iVar8)) / 100;
    }
    if ((1 < iVar7) && (iVar7 = func_0x00653884(param_1 + 0x1538,uVar5,1,0,auStack_e8,0), 0 < iVar7)
       ) {
      uVar14 = (long)(uVar14 * (long)(100 - iVar7)) / 100;
    }
    uVar5 = func_0x0062b458(param_1 + 0x21b8);
    iVar7 = func_0x0067c144(param_1 + 0x421a50,uVar5);
    uVar5 = func_0x0062b3b4(param_1 + 0x21b8);
    iVar8 = func_0x0067c168(param_1 + 0x421a50,uVar5);
    bVar4 = func_0x008b18c4(param_1 + 0x468,0xffffffff,0xffffffff,0xffffffff);
    iVar7 = iVar7 + 1;
    bVar2 = (bVar4 & *(int *)(param_1 + 0x4b4) != -1) != 0;
    if (bVar2) {
      iVar7 = 1;
    }
    iVar9 = 1;
    if (!bVar2) {
      iVar9 = iVar8 + 1;
    }
    if (param_4 != 0) {
      uVar13 = func_0x00a5b3a4(1,1,param_3);  /* 0x95b3a4:[slot*1000,team*0x1f0,team*51000|off=0x8394c|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,100,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b484(1,param_3);  /* 0x95b484:[slot*1000,team*0x1f0,team*51000|off=0x839ac|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x65,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b564(1,param_3);  /* 0x95b564:[slot*1000,team*0x1f0,team*51000|off=0x839b0|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x66,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b644(1,param_3);  /* 0x95b644:[slot*1000,team*0x1f0,team*51000|off=|ldr w8, [x8]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x67,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b7a0(1,param_3);  /* 0x95b7a0:[slot*1000,team*0x1f0,team*51000|off=0x839bc|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x68,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b880(1,param_3);  /* 0x95b880:[slot*1000,team*0x1f0,team*51000|off=0x839c0|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x69,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b960(1,param_3);  /* 0x95b960:[slot*1000,team*0x1f0,team*51000|off=0x839c4|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x6a,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5bab0(1,param_3);  /* 0x95bab0:[slot*1000,team*0x1f0,team*51000|off=0x83b50|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x6b,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b6c0(1,param_3);  /* 0x95b6c0:[slot*1000,team*0x1f0,team*51000|off=0x839b8|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x6c,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5b9d0(1,param_3);  /* 0x95b9d0:[slot*1000,team*0x1f0,team*51000|off=0x83abc|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x6d,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5ba40(1,param_3);  /* 0x95ba40:[slot*1000,team*0x1f0,team*51000|off=0x83b48|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0x6e,iVar7);
        if (iVar8 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar8)) / 10000;
        }
      }
      uVar13 = func_0x00a5bb20(1,param_3);  /* 0x95bb20:[slot*1000,team*0x1f0,team*51000|off=0x83c10|ldr w8, [x8, x9]] */
      if ((uVar13 & 1) != 0) {
        uVar16 = func_0x0062b5dc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar16,0x6f,iVar7);
        if (iVar7 != 0) {
          uVar14 = (long)(uVar14 * (long)(10000 - iVar7)) / 10000;
        }
      }
      if (param_2 == 1) {
        uVar16 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar16,0xc9,iVar9);
      }
      else {
        if (param_2 != 2) goto LAB_006d90a8;
        uVar16 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar16,0xcb,iVar9);
      }
      if (iVar7 != 0) {
        uVar14 = (long)(uVar14 * (long)(10000 - iVar7)) / 10000;
      }
    }
LAB_006d90a8:
    uVar12 = func_0x00a5b644(0,param_4);  /* 0x95b644:[slot*1000,team*0x1f0,team*51000|off=|ldr w8, [x8]] */
    uVar13 = uVar14 & ((long)uVar14 >> 0x3f ^ 0xffffffffffffffffU);
    if (((param_7 | uVar12 ^ 0xffffffff) & 1) == 0 && 1 < (long)uVar14) {
      uVar13 = 1;
    }
    bVar4 = func_0x00a5ac18(1,param_3,param_4);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
    if ((param_4 != 0) && ((bVar4 & param_16 & 1) != 0)) {
      uVar14 = func_0x00a60184(0,param_4);  /* 0x960184:[slot*1000,team*51000|off=0x83bd0|ldr w8, [x8, x9]] */
      if ((uVar14 & 1) == 0) {
        iVar7 = func_0x00a5a194(0,param_4);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
        iVar8 = func_0x00a5d0d4(1,param_3);  /* 0x95d0d4:[slot*1000,team*51000|off=0x83bb8|ldr w0, [x8, x9]] */
        iVar7 = func_0x0043ed6c((iVar8 * iVar7) / 100,1);
        iVar8 = func_0x00a62ae8(0,param_4);  /* 0x962ae8:[slot*1000,team*51000|off=0x83bd8|ldr w0, [x8, x9]] */
        uVar14 = SUB168(SEXT816((long)(100 - iVar8) * (long)iVar7) * SEXT816(-0x5c28f5c28f5c28f5),8)
                 + (long)(100 - iVar8) * (long)iVar7;
        iVar7 = func_0x0043ed6c((int)(uVar14 >> 6) - (int)((long)uVar14 >> 0x3f),1);
        uVar16 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar8 = func_0x00629258(uVar16,0xcd,iVar9);
        lVar17 = (long)iVar7;
        if (iVar8 != 0) {
          lVar17 = ((long)iVar7 * (long)(10000 - iVar8)) / 10000;
        }
        func_0x00a61730(0,param_4,1);  /* 0x961730:[slot*1000,team*51000|off=0x83bbc|str w21, [x8, x9]] */
        func_0x00a62ae8(0,param_4);  /* 0x962ae8:[slot*1000,team*51000|off=0x83bd8|ldr w0, [x8, x9]] */
        uVar13 = lVar17 + uVar13;
      }
      else {
        func_0x00a60f1c(0,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
    if (param_2 == 1) {
      uVar14 = func_0x00a5f900(0,param_4);  /* 0x95f900:[slot*1000,team*51000|off=0x83a60|ldr w8, [x8, x9]] */
LAB_006d924c:
      if ((uVar14 & 1) != 0) {
        uVar13 = 0;
        param_1 = param_1 + (long)param_4 * 1000;
        *(undefined4 *)(param_1 + 0x83a78) = 0;
        *(undefined4 *)(param_1 + 0x83a7c) = 1;
      }
    }
    else {
      if (param_2 == 3) {
        uVar14 = func_0x00a602ac(0,param_4);  /* 0x9602ac:[slot*1000,team*51000|off=0x83c94|ldr w8, [x8, x9]] */
        goto LAB_006d924c;
      }
      if (param_2 == 2) {
        uVar14 = func_0x00a60218(0,param_4);  /* 0x960218:[slot*1000,team*51000|off=0x83bd4|ldr w8, [x8, x9]] */
        goto LAB_006d924c;
      }
    }
    func_0x00a60488(0,param_4,uVar13 & 0xffffffff);  /* 0x960488:[slot*1000,team*51000|off=0x83954,0x83ac8,0x83b10,0x83b10,0x83b14|ldr w10, [x8, x9] ; str w10, [x8, x9] ; ldr w10, [x8, x9] ; str w10, [x8, x9]] */
    uVar5 = 1;
  }
  else {
    uVar14 = func_0x00a5c0dc(1,param_3);  /* 0x95c0dc:[slot*1000,team*0x1f0,team*51000|off=0x83c40|ldr w8, [x8, x9]] */
    if ((uVar14 & 1) == 0) {
LAB_006d89c4:
      bVar2 = false;
LAB_006d89c8:
      iVar8 = func_0x00a61c54(0,param_4);  /* 0x961c54:[slot*1000,team*51000|off=0x83cb0|ldr w0, [x8, x9]] */
      if (iVar8 < 1) {
        uVar14 = func_0x00a5ac18(0,param_4,param_3);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if (((uVar14 & 1) == 0) && (uVar14 = func_0x00a5db54(0,param_4), (uVar14 & 1) == 0)) {  /* 0x95db54:[slot*1000,team*51000|off=0x83c60|ldr w8, [x8, x9]] */
          if (!bVar2) {
LAB_006d9614:
            iVar8 = func_0x00a62c8c(0,param_4);  /* 0x962c8c:[slot*1000,team*51000|off=0x83cb4|ldr w0, [x8, x9]] */
            if (0 < iVar8) {
              iVar8 = func_0x0043ea60(100);
              iVar9 = func_0x00a62c8c(0,param_4);  /* 0x962c8c:[slot*1000,team*51000|off=0x83cb4|ldr w0, [x8, x9]] */
              if (iVar8 < iVar9) {
                uVar5 = func_0x00a62d18(0,param_4);  /* 0x962d18:[slot*1000,team*51000|off=0x83cb8|ldr w0, [x8, x9]] */
                func_0x00a61c94(0,param_4,uVar5);  /* 0x961c94:[slot*1000,team*51000|off=0x83cb0|str w19, [x8, x9]] */
                func_0x00a61648(0,param_4,1);  /* 0x961648:[slot*1000,team*51000|off=0x83bac|str w19, [x8, x9]] */
                func_0x0040cb78(&uStack_d0,&UNK_002a0641);  /* UNK_2a0641(vma=0x1a0641)='u32=0xe6a885e5(3869804005) f32=-3.979e+23' */
                func_0x00a62c8c(0,param_4);  /* 0x962c8c:[slot*1000,team*51000|off=0x83cb4|ldr w0, [x8, x9]] */
                goto LAB_006d9690;
              }
            }
            uVar14 = func_0x00a5ac18(1,param_3,param_4);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            if ((uVar14 & 1) != 0) {
              if (param_2 == 3) {
                uVar14 = func_0x00a602ac(0,param_4);  /* 0x9602ac:[slot*1000,team*51000|off=0x83c94|ldr w8, [x8, x9]] */
LAB_006d9740:
                if ((uVar14 & 1) != 0) goto LAB_006d97a8;
              }
              else {
                if (param_2 == 2) {
                  uVar14 = func_0x00a60218(0,param_4);  /* 0x960218:[slot*1000,team*51000|off=0x83bd4|ldr w8, [x8, x9]] */
                  goto LAB_006d9740;
                }
                if (param_2 == 1) {
                  uVar14 = func_0x00a5f900(0,param_4);  /* 0x95f900:[slot*1000,team*51000|off=0x83a60|ldr w8, [x8, x9]] */
                  goto LAB_006d9740;
                }
              }
              BattleFn_0x005d6da0(param_1,1,param_3,param_4,0x19,param_9 & 1,param_10 & 1,
                                  param_11 & 1,param_12 & 1,param_13 & 1,param_14 & 1,param_18 & 1,0
                                 );
            }
LAB_006d97a8:
            uVar14 = func_0x00a5eba8(0,param_4);  /* 0x95eba8:[slot*1000,team*0x1f0,team*51000|off=0x83ac0|ldr w8, [x8, x9]] */
            if (((uVar14 & 1) != 0) && (uVar14 = func_0x00a5b9d0(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95b9d0:[slot*1000,team*0x1f0,team*51000|off=0x83abc|ldr w8, [x8, x9]] */
              iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x16,uVar5);
              func_0x0040cb78(&uStack_d0,&UNK_002a79d3);  /* UNK_2a79d3(vma=0x1a79d3)='u32=0xe594ade9(3851726313) f32=-8.776e+22' */
              func_0x008700d4(param_1 + 0x4407e8,0x16,uVar5);
              iVar8 = (int)((ulong)((long)iVar8 * -0x51eb851f) >> 0x20);
              uVar13 = (((long)uVar13 / 10) * (long)(((iVar8 >> 5) - (iVar8 >> 0x1f)) + 5)) / 5;
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            uVar14 = func_0x00a5ec88(0,param_4);  /* 0x95ec88:[slot*1000,team*0x1f0,team*51000|off=0x83b4c|ldr w8, [x8, x9]] */
            if (((uVar14 & 1) != 0) && (uVar14 = func_0x00a5ba40(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95ba40:[slot*1000,team*0x1f0,team*51000|off=0x83b48|ldr w8, [x8, x9]] */
              iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x17,uVar5);
              func_0x0040cb78(&uStack_d0,&UNK_0028ed3d);  /* UNK_28ed3d(vma=0x18ed3d)='u32=0xe5bfbde4(3854548452) f32=-1.132e+23' */
              func_0x008700d4(param_1 + 0x4407e8,0x17,uVar5);
              iVar8 = (int)((ulong)((long)iVar8 * -0x51eb851f) >> 0x20);
              uVar13 = (((long)uVar13 / 5) * (long)(((iVar8 >> 5) - (iVar8 >> 0x1f)) + 5)) / 5;
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            uVar14 = func_0x00a5ed68(0,param_4);  /* 0x95ed68:[slot*1000,team*0x1f0,team*51000|off=0x83c1c|ldr w8, [x8, x9]] */
            if (((uVar14 & 1) != 0) && (uVar14 = func_0x00a5c020(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95c020:[slot*1000,team*0x1f0,team*51000|off=0x83c18|ldr w8, [x8, x9]] */
              iVar8 = func_0x00a5efb8(0,param_4);  /* 0x95efb8:[slot*1000,team*0x1f0,team*51000|off=0x83c1c,0x83ca0,0x83ca0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w0, [x8, x9]] */
              func_0x0040cb78(&uStack_d0,&UNK_0028ed17);  /* UNK_28ed17(vma=0x18ed17)='u32=0xe785b6e8(3884300008) f32=-1.263e+24' */
              func_0x00a5efb8(0,param_4);  /* 0x95efb8:[slot*1000,team*0x1f0,team*51000|off=0x83c1c,0x83ca0,0x83ca0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w0, [x8, x9]] */
              uVar13 = (long)(uVar13 * (long)iVar8) / 100;
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            uVar14 = func_0x00a5f364(0,param_4);  /* 0x95f364:[slot*1000,team*0x1f0,team*51000|off=0x83c44|ldr w8, [x8, x9]] */
            if (((uVar14 & 1) != 0) && (uVar14 = func_0x00a5c0dc(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95c0dc:[slot*1000,team*0x1f0,team*51000|off=0x83c40|ldr w8, [x8, x9]] */
              func_0x0040cb78(abStack_120,&UNK_0029f87c);  /* UNK_29f87c(vma=0x19f87c)='battle_super_beast_hunter_df' */
              iVar8 = func_0x008e3f14(param_1 + 0x1478,abStack_120,700);
              if ((abStack_120[0] & 1) != 0) {
                func_0x00bc3350(uStack_110);
              }
              func_0x0040cb78(&uStack_d0,&UNK_0029213f);  /* UNK_29213f(vma=0x19213f)='u32=0xe785b6e8(3884300008) f32=-1.263e+24' */
              func_0x0040cb78(abStack_138,&UNK_0029f87c);  /* UNK_29f87c(vma=0x19f87c)='battle_super_beast_hunter_df' */
              func_0x008e3f14(param_1 + 0x1478,abStack_138,700);
              uVar13 = (long)(uVar13 * (long)iVar8) / 1000;
              if ((abStack_138[0] & 1) != 0) {
                func_0x00bc3350(uStack_128);
              }
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            uVar14 = func_0x00a5f5ec(0,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
            if (((uVar14 & 1) != 0) && (uVar14 = func_0x00a5c198(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
              func_0x0040cb78(abStack_150,&UNK_0028ad7d);  /* UNK_28ad7d(vma=0x18ad7d)='battle_super_sage_hunter_damage2' */
              iVar8 = func_0x008e3f14(param_1 + 0x1478,abStack_150,700);
              if ((abStack_150[0] & 1) != 0) {
                func_0x00bc3350(uStack_140);
              }
              func_0x0040cb78(&uStack_d0,&UNK_002a582a);  /* UNK_2a582a(vma=0x1a582a)='u32=0xe885b6e8(3901077224) f32=-5.052e+24' */
              func_0x0040cb78(abStack_168,&UNK_0028ad7d);  /* UNK_28ad7d(vma=0x18ad7d)='battle_super_sage_hunter_damage2' */
              func_0x008e3f14(param_1 + 0x1478,abStack_168,700);
              uVar13 = (long)(uVar13 * (long)iVar8) / 1000;
              if ((abStack_168[0] & 1) != 0) {
                func_0x00bc3350(uStack_158);
              }
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            uVar12 = func_0x008700d4(param_1 + 0x4407e8,0x19,uVar5);
            if ((0 < (int)uVar12) && (uVar14 = func_0x00a5c254(1,param_3), (uVar14 & 1) != 0)) {  /* 0x95c254:[slot*1000,team*51000|off=0x83cd8|ldr w8, [x8, x9]] */
              func_0x0040cb78(&uStack_d0,&UNK_00290f45);  /* UNK_290f45(vma=0x190f45)='u32=0xe4aa80e6(3836379366) f32=-2.516e+22' */
              lVar17 = uVar13 * 1000;
              uVar13 = 0;
              if ((ulong)uVar12 != 0) {
                uVar13 = lVar17 / (long)(ulong)uVar12;
              }
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            iVar8 = func_0x00a5fe34(0,param_4);  /* 0x95fe34:[slot*1000,team*51000|off=0x83b10|ldr w0, [x8, x9]] */
            if ((0 < iVar8) && ((param_15 & 1) != 0)) {
              func_0x00a60660(0,param_4,2);  /* 0x960660:[slot*1000,team*51000|off=0x83b14|str w19, [x8, x9]] */
            }
            iVar8 = func_0x00a6177c(0,param_4);  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
            uVar14 = uVar13;
            if ((0 < iVar8) && ((param_17 & 1) != 0)) {
              func_0x00a61848(0,param_4,2);  /* 0x961848:[slot*1000,team*51000|off=0x83c04|str w19, [x8, x9]] */
            }
            goto LAB_006d8984;
          }
        }
        else {
          iVar8 = func_0x00a61528(0,param_4);  /* 0x961528:[slot*1000,team*51000|off=0x83ba4|ldr w0, [x8, x9]] */
          if (iVar8 < 1) {
            iVar8 = func_0x0043ea60(100);
            iVar9 = func_0x00a6006c(0,param_4);  /* 0x96006c:[slot*1000,team*51000|off=0x83b9c|ldr w0, [x8, x9]] */
            if (iVar8 < iVar9) {
              uVar5 = func_0x006d6b98(param_1,param_4,param_3);
              iVar7 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar5,100);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
              iVar8 = func_0x00a600f8(0,param_4);  /* 0x9600f8:[slot*1000,team*51000|off=0x83ba8|ldr w0, [x8, x9]] */
              func_0x00a61568(0,param_4,(iVar8 * (iVar7 + 0x5dc)) / 0x5dc);  /* 0x961568:[slot*1000,team*51000|off=0x83ba4|str w19, [x8, x9]] */
              func_0x00a61648(0,param_4,1);  /* 0x961648:[slot*1000,team*51000|off=0x83bac|str w19, [x8, x9]] */
              func_0x0040cb78(&uStack_d0,&UNK_00289e7e);  /* UNK_289e7e(vma=0x189e7e)='u32=0xe99e9be5(3919485925) f32=-2.397e+25' */
              func_0x00a6006c(0,param_4);  /* 0x96006c:[slot*1000,team*51000|off=0x83b9c|ldr w0, [x8, x9]] */
              func_0x00a6006c(0,param_4);  /* 0x96006c:[slot*1000,team*51000|off=0x83b9c|ldr w0, [x8, x9]] */
LAB_006d9690:
              if ((uStack_d0 & 1) != 0) {
                func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
              }
            }
            else if (!bVar2) {
              uVar6 = func_0x006d6b98(param_1,param_4,param_3);
              uVar14 = func_0x00a5e500(0,param_4);  /* 0x95e500:[slot*1000,team*0x1f0,team*51000|off=0x839c8|ldr w8, [x8, x9]] */
              if ((uVar14 & 1) != 0) {
                iVar8 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar6,100);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
                if (iVar7 < 2) {
                  iVar9 = 0;
                }
                else {
                  iVar9 = func_0x00653884(param_1 + 0x1538,uVar5,2,1,auStack_e8,0);
                }
                iVar10 = func_0x008700d4(param_1 + 0x4407e8,0xe,uVar5);
                func_0x0040cb78(&uStack_d0,&UNK_00294690);  /* UNK_294690(vma=0x194690)='u32=0xe38182e3(3816915683) f32=-4.778e+21' */
                func_0x008700d4(param_1 + 0x4407e8,0xe,uVar5);
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
                uVar14 = BattleFn_0x004ab294();
                uVar13 = (((((long)(uVar13 * (long)(0x5dc - iVar8)) / 3000) * (long)(100 - iVar10))
                          / 100) * (long)(100 - iVar9)) / 100;
                if ((uVar14 & 1) != 0) {
                  uVar11 = func_0x00a5aa1c(0,param_4);  /* 0x95aa1c:[team*0x1f0|off=|] */
                  uVar11 = func_0x00999ef0(param_1 + 0x400,0x10,uVar11);
                  func_0x00a5a9c8(0,param_4,uVar11);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                }
              }
              uVar14 = func_0x00a5e5e0(0,param_4);  /* 0x95e5e0:[slot*1000,team*0x1f0,team*51000|off=0x839e0|ldr w8, [x8, x9]] */
              if ((uVar14 & 1) != 0) {
                iVar8 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar6,100);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
                if (iVar7 < 2) {
                  iVar9 = 0;
                }
                else {
                  iVar9 = func_0x00653884(param_1 + 0x1538,uVar5,4,0,auStack_e8,0);
                }
                iVar10 = func_0x008700d4(param_1 + 0x4407e8,0x10,uVar5);
                func_0x0040cb78(&uStack_d0,&UNK_002a584e);  /* UNK_2a584e(vma=0x1a584e)='u32=0xe39389e6(3818097126) f32=-5.443e+21' */
                func_0x008700d4(param_1 + 0x4407e8,0x10,uVar5);
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
                uVar14 = BattleFn_0x004ab294();
                uVar13 = (((((long)(uVar13 * (long)(0x5dc - iVar8)) / 6000) * (long)(100 - iVar10))
                          / 100) * (long)(100 - iVar9)) / 100;
                if ((uVar14 & 1) != 0) {
                  uVar11 = func_0x00a5aa1c(0,param_4);  /* 0x95aa1c:[team*0x1f0|off=|] */
                  uVar11 = func_0x00999ef0(param_1 + 0x400,0x11,uVar11);
                  func_0x00a5a9c8(0,param_4,uVar11);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                }
              }
              uVar14 = func_0x00a5e7a0(0,param_4);  /* 0x95e7a0:[slot*1000,team*0x1f0,team*51000|off=0x83b88|ldr w8, [x8, x9]] */
              if ((uVar14 & 1) != 0) {
                iVar8 = func_0x00a1fb18(&UNK_00290568 + param_1,uVar6,100);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
                func_0x0040cb78(&uStack_d0,&UNK_00292160);  /* UNK_292160(vma=0x192160)='u32=0xe685b6e8(3867522792) f32=-3.157e+23' */
                if ((uStack_d0 & 1) != 0) {
                  func_0x00bc3350(CONCAT44(uStack_bc,uStack_c0));
                }
                uVar14 = BattleFn_0x004ab294();
                uVar13 = (long)(uVar13 * (long)(0x834 - iVar8)) / 0x3138;
                if ((uVar14 & 1) != 0) {
                  uVar6 = func_0x00a5aa1c(0,param_4);  /* 0x95aa1c:[team*0x1f0|off=|] */
                  uVar6 = func_0x00999ef0(param_1 + 0x400,0x12,uVar6);
                  func_0x00a5a9c8(0,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                }
              }
              goto LAB_006d9614;
            }
          }
        }
      }
    }
    else {
      iVar8 = func_0x00a61ae0(0,param_4);  /* 0x961ae0:[slot*1000,team*51000|off=0x83c50|ldr w0, [x8, x9]] */
      if (iVar8 < 1) {
        iVar8 = func_0x0043ea60(100);
        iVar9 = func_0x00a5f444(0,param_4);  /* 0x95f444:[slot*1000,team*0x1f0,team*51000|off=0x83c48|ldr w0, [x8, x9]] */
        if (iVar9 <= iVar8) goto LAB_006d89c4;
        uVar6 = func_0x00a5f518(0,param_4);  /* 0x95f518:[slot*1000,team*0x1f0,team*51000|off=0x83c4c|ldr w0, [x8, x9]] */
        func_0x00a61b20(0,param_4,uVar6);  /* 0x961b20:[slot*1000,team*51000|off=0x83c50|str w19, [x8, x9]] */
        func_0x00a61648(0,param_4,1);  /* 0x961648:[slot*1000,team*51000|off=0x83bac|str w19, [x8, x9]] */
        func_0x00a5f444(0,param_4);  /* 0x95f444:[slot*1000,team*0x1f0,team*51000|off=0x83c48|ldr w0, [x8, x9]] */
        func_0x00a5f444(0,param_4);  /* 0x95f444:[slot*1000,team*0x1f0,team*51000|off=0x83c48|ldr w0, [x8, x9]] */
        bVar2 = true;
        goto LAB_006d89c8;
      }
    }
    uVar5 = 0;
  }
  func_0x0065b710(auStack_e8,uStack_e0);
LAB_006d96b0:
  if (*(long *)(lVar1 + 0x28) != lStack_70) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return uVar5;
}


