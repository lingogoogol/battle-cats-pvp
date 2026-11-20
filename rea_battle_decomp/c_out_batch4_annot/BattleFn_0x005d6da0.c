// ELF VMA: 0x5d6da0
// Ghidra Addr: 0x006d6da0 (ImageBase=0x100000)
// Size: 5540 bytes


void BattleFn_0x005d6da0(long param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                        int param_6,int param_7,int param_8,int param_9,byte param_10,byte param_11,
                        byte param_12)

{
  int iVar1;
  long lVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  undefined8 uVar12;
  ulong uStack_300;
  undefined8 uStack_2f8;
  undefined8 *puStack_2f0;
  ulong uStack_2e0;
  undefined8 uStack_2d8;
  undefined8 *puStack_2d0;
  ulong uStack_2c0;
  undefined8 uStack_2b8;
  undefined8 *puStack_2b0;
  ulong uStack_2a0;
  undefined8 uStack_298;
  undefined8 *puStack_290;
  ulong uStack_280;
  undefined8 uStack_278;
  undefined8 *puStack_270;
  ulong uStack_260;
  undefined8 uStack_258;
  undefined8 *puStack_250;
  ulong uStack_240;
  undefined8 uStack_238;
  undefined8 *puStack_230;
  ulong uStack_220;
  undefined8 uStack_218;
  undefined8 *puStack_210;
  ulong uStack_200;
  undefined8 uStack_1f8;
  undefined8 *puStack_1f0;
  ulong uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 *puStack_1d0;
  ulong uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 *puStack_1b0;
  ulong uStack_1a0;
  undefined8 uStack_198;
  undefined8 *puStack_190;
  ulong uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  byte bStack_160;
  undefined8 uStack_15f;
  undefined6 uStack_157;
  undefined1 uStack_151;
  undefined1 uStack_150;
  undefined6 uStack_14f;
  undefined1 uStack_149;
  byte bStack_148;
  undefined8 uStack_147;
  undefined6 uStack_13f;
  undefined1 uStack_139;
  undefined1 uStack_138;
  undefined6 uStack_137;
  undefined1 uStack_131;
  ulong uStack_130;
  undefined8 uStack_128;
  undefined8 *puStack_120;
  ulong uStack_110;
  undefined8 uStack_108;
  undefined8 *puStack_100;
  ulong uStack_f0;
  undefined8 uStack_e8;
  undefined8 *puStack_e0;
  ulong uStack_d0;
  undefined8 uStack_c8;
  undefined8 *puStack_c0;
  ulong uStack_b0;
  undefined8 uStack_a8;
  undefined8 *puStack_a0;
  ulong uStack_90;
  undefined8 uStack_88;
  undefined8 *puStack_80;
  long lStack_78;
  
  lVar2 = tpidr_el0;
  lStack_78 = *(long *)(lVar2 + 0x28);
  iVar10 = 1;
  iVar1 = 1 - param_2;
  uVar4 = func_0x0062b3b4(param_1 + 0x21b8);
  iVar5 = func_0x0067c168(param_1 + 0x421a50,uVar4);
  uVar4 = func_0x00a58934(param_2,param_3);  /* 0x958934:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
  bVar3 = func_0x008b18c4(param_1 + 0x468,0xffffffff,0xffffffff,0xffffffff);
  if ((bVar3 & *(int *)(param_1 + 0x4b4) != -1) == 0) {
    iVar10 = iVar5 + 1;
  }
  if (param_6 != 1) goto LAB_006d7054;
  uVar11 = func_0x00a5fa28(iVar1,param_4);  /* 0x95fa28:[slot*1000,team*51000|off=0x83a68|ldr w8, [x8, x9]] */
  if ((uVar11 & 1) == 0) {
    func_0x00a607d0(iVar1,param_4,1);  /* 0x9607d0:[slot*1000,team*51000|off=0x839f8|str w21, [x8, x9]] */
    uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
    if ((uVar11 & 1) == 0) {
      uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
      if (((uVar11 & 1) == 0) || (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) == 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
        func_0x00a6085c(iVar1,param_4,0);  /* 0x96085c:[slot*1000,team*51000|off=0x83c6c|str w19, [x8, x9]] */
      }
      else {
        puStack_a0 = (undefined8 *)func_0x00bc3330(0x30);
        *(undefined2 *)(puStack_a0 + 4) = 0x6b63;
        uStack_a8 = 0x22;
        uStack_b0 = 0x31;
        *(undefined1 *)((long)puStack_a0 + 0x22) = 0;
        puStack_a0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
        *puStack_a0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
        puStack_a0[3] = 0x61626b636f6e6b5f;  /* ascii(0x61626b636f6e6b5f)='_knockba' */
        puStack_a0[2] = 0x7265746e75685f65;  /* ascii(0x7265746e75685f65)='e_hunter' */
        uVar6 = func_0x008e3f14(&uStack_b0,param_1 + 0x1478,&uStack_b0,0x32);
        func_0x00a6085c(iVar1,param_4,uVar6);  /* 0x96085c:[slot*1000,team*51000|off=0x83c6c|str w19, [x8, x9]] */
        if ((uStack_b0 & 1) != 0) {
          func_0x00bc3350(puStack_a0);
        }
      }
      goto LAB_006d7054;
    }
    uVar11 = func_0x00a5f5ec(param_2,param_3);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
    if (((uVar11 & 1) == 0) && (uVar11 = func_0x00a5c198(iVar1,param_4), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
      puStack_80 = (undefined8 *)func_0x00bc3330(0x20);
      puStack_80[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
      *puStack_80 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
      *(undefined8 *)((long)puStack_80 + 0x13) = 0x6b6361626b636f6e;  /* ascii(0x6b6361626b636f6e)='nockback' */
      *(undefined8 *)((long)puStack_80 + 0xb) = 0x6b5f656761735f72;  /* ascii(0x6b5f656761735f72)='r_sage_k' */
      uStack_88 = 0x1b;
      uStack_90 = 0x21;
      *(undefined1 *)((long)puStack_80 + 0x1b) = 0;
      uVar6 = func_0x008e3f14(&uStack_90,param_1 + 0x1478,&uStack_90,0x32);
      func_0x00a6085c(iVar1,param_4,uVar6);  /* 0x96085c:[slot*1000,team*51000|off=0x83c6c|str w19, [x8, x9]] */
      if ((uStack_90 & 1) != 0) {
        func_0x00bc3350(puStack_80);
      }
    }
    else {
      func_0x00a6085c(iVar1,param_4,0);  /* 0x96085c:[slot*1000,team*51000|off=0x83c6c|str w19, [x8, x9]] */
    }
    iVar5 = func_0x00a58874(param_2,param_3);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
    if ((iVar5 != 2) || (uVar11 = BattleFn_0x004ab294(), (uVar11 & 1) == 0)) goto LAB_006d7054;
    uVar6 = func_0x00a5aa1c(param_2,param_3);  /* 0x95aa1c:[team*0x1f0|off=|] */
    uVar12 = 3;
  }
  else {
    func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
    uVar11 = BattleFn_0x004ab294();
    if ((param_2 == 0) || ((uVar11 & 1) == 0)) goto LAB_006d7054;
    uVar12 = 8;
    uVar6 = 1;
  }
  uVar6 = func_0x00999ef0(param_1 + 0x400,uVar12,uVar6);
  func_0x00a5a9c8(iVar1,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
LAB_006d7054:
  iVar5 = func_0x00a1fb18(&UNK_00290568 + param_1,param_5,100);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
  if (param_7 == 1) {
    uVar11 = func_0x00a5fabc(iVar1,param_4);  /* 0x95fabc:[slot*1000,team*51000|off=0x83a6c|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar9 = func_0x00a5dc70(param_2,param_3);  /* 0x95dc70:[slot*1000,team*51000|off=0x839d4|ldr w0, [x8, x9]] */
      uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
      if ((uVar11 & 1) == 0) {
        iVar7 = func_0x00a627a0(iVar1,param_4);  /* 0x9627a0:[slot*1000,team*51000|off=0x83b70|ldr w0, [x8, x9]] */
        if (iVar7 != 0) {
          iVar7 = func_0x00a627a0(iVar1,param_4);  /* 0x9627a0:[slot*1000,team*51000|off=0x83b70|ldr w0, [x8, x9]] */
          func_0x00a627a0(iVar1,param_4);  /* 0x9627a0:[slot*1000,team*51000|off=0x83b70|ldr w0, [x8, x9]] */
          iVar9 = ((100 - iVar7) * iVar9) / 100;
        }
        uVar12 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar12,0xca,iVar10);
        if (iVar7 != 0) {
          iVar9 = ((10000 - iVar7) * iVar9) / 10000;
        }
        uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_100 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_100[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_100 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_100 + 0x17) = 0x657a656572665f72;  /* ascii(0x657a656572665f72)='r_freeze' */
          *(undefined8 *)((long)puStack_100 + 0xf) = 0x65746e75685f6567;  /* ascii(0x65746e75685f6567)='ge_hunte' */
          uStack_108 = 0x1f;
          uStack_110 = 0x21;
          *(undefined1 *)((long)puStack_100 + 0x1f) = 0;
          iVar7 = func_0x008e3f14(&uStack_110,param_1 + 0x1478,&uStack_110,0x32);
          if ((uStack_110 & 1) != 0) {
            func_0x00bc3350(puStack_100);
          }
          puStack_120 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_120 + 0x1f) = 0;
          uStack_128 = 0x1f;
          uStack_130 = 0x21;
          puStack_120[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_120 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_120 + 0x17) = 0x657a656572665f72;  /* ascii(0x657a656572665f72)='r_freeze' */
          *(undefined8 *)((long)puStack_120 + 0xf) = 0x65746e75685f6567;  /* ascii(0x65746e75685f6567)='ge_hunte' */
          func_0x008e3f14(&uStack_130,param_1 + 0x1478,&uStack_130,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_130 & 1) != 0) {
            func_0x00bc3350(puStack_120);
          }
        }
      }
      else {
        iVar7 = func_0x008700d4(param_1 + 0x4407e8,0x13,uVar4);
        iVar9 = ((iVar7 + 100) * ((iVar9 * (iVar5 + 0x5dc)) / 0x5dc)) / 100;
        func_0x008700d4(param_1 + 0x4407e8,0x13,uVar4);
        uVar11 = func_0x00a5f5ec(param_2,param_3);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) == 0) && (uVar11 = func_0x00a5c198(iVar1,param_4), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_c0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_c0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_c0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          puStack_c0[2] = 0x657a656572665f65;  /* ascii(0x657a656572665f65)='e_freeze' */
          uStack_c8 = 0x18;
          uStack_d0 = 0x21;
          *(undefined1 *)(puStack_c0 + 3) = 0;
          iVar7 = func_0x008e3f14(&uStack_d0,param_1 + 0x1478,&uStack_d0,0x32);
          if ((uStack_d0 & 1) != 0) {
            func_0x00bc3350(puStack_c0);
          }
          puStack_e0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_e0[2] = 0x657a656572665f65;  /* ascii(0x657a656572665f65)='e_freeze' */
          uStack_e8 = 0x18;
          uStack_f0 = 0x21;
          puStack_e0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_e0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined1 *)(puStack_e0 + 3) = 0;
          func_0x008e3f14(param_1 + 0x1478,&uStack_f0,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_f0 & 1) != 0) {
            func_0x00bc3350(puStack_e0);
          }
        }
        iVar7 = func_0x00a58874(param_2,param_3);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((iVar7 == 2) && (uVar11 = BattleFn_0x004ab294(), (uVar11 & 1) != 0)) {
          uVar6 = func_0x00a5aa1c(param_2,param_3);  /* 0x95aa1c:[team*0x1f0|off=|] */
          uVar6 = func_0x00999ef0(param_1 + 0x400,1,uVar6);
          func_0x00a5a9c8(iVar1,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
        }
      }
      func_0x00a608e8(iVar1,param_4,iVar9);  /* 0x9608e8:[slot*1000,team*51000|off=0x839fc|str w19, [x8, x9]] */
      func_0x00a609c8(iVar1,param_4,iVar9);  /* 0x9609c8:[slot*1000,team*51000|off=0x83a10|str w19, [x8, x9]] */
      BattleFn_0x005ce4cc(param_1,iVar1,param_4,1);
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      uVar11 = BattleFn_0x004ab294();
      if ((param_2 != 0) && ((uVar11 & 1) != 0)) {
        uVar6 = func_0x00999ef0(param_1 + 0x400,6,1);
        func_0x00a5a9c8(iVar1,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
  }
  if (param_8 == 1) {
    uVar11 = func_0x00a5fb50(iVar1,param_4);  /* 0x95fb50:[slot*1000,team*51000|off=0x83a70|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar9 = func_0x00a5ddd0(param_2,param_3);  /* 0x95ddd0:[slot*1000,team*51000|off=0x839dc|ldr w0, [x8, x9]] */
      uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
      if ((uVar11 & 1) == 0) {
        iVar7 = func_0x00a6282c(iVar1,param_4);  /* 0x96282c:[slot*1000,team*51000|off=0x83b74|ldr w0, [x8, x9]] */
        if (iVar7 != 0) {
          iVar7 = func_0x00a6282c(iVar1,param_4);  /* 0x96282c:[slot*1000,team*51000|off=0x83b74|ldr w0, [x8, x9]] */
          func_0x00a6282c(iVar1,param_4);  /* 0x96282c:[slot*1000,team*51000|off=0x83b74|ldr w0, [x8, x9]] */
          iVar9 = ((100 - iVar7) * iVar9) / 100;
        }
        uVar12 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar12,200,iVar10);
        if (iVar7 != 0) {
          iVar9 = ((10000 - iVar7) * iVar9) / 10000;
        }
        uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_170 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_170[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_170 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_170 + 0x15) = 0x776f6c735f726574;  /* ascii(0x776f6c735f726574)='ter_slow' */
          *(undefined8 *)((long)puStack_170 + 0xd) = 0x6e75685f65676173;  /* ascii(0x6e75685f65676173)='sage_hun' */
          uStack_178 = 0x1d;
          uStack_180 = 0x21;
          *(undefined1 *)((long)puStack_170 + 0x1d) = 0;
          iVar7 = func_0x008e3f14(&uStack_180,param_1 + 0x1478,&uStack_180,0x32);
          if ((uStack_180 & 1) != 0) {
            func_0x00bc3350(puStack_170);
          }
          puStack_190 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_190 + 0x1d) = 0;
          uStack_198 = 0x1d;
          uStack_1a0 = 0x21;
          puStack_190[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_190 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_190 + 0x15) = 0x776f6c735f726574;  /* ascii(0x776f6c735f726574)='ter_slow' */
          *(undefined8 *)((long)puStack_190 + 0xd) = 0x6e75685f65676173;  /* ascii(0x6e75685f65676173)='sage_hun' */
          func_0x008e3f14(&uStack_1a0,param_1 + 0x1478,&uStack_1a0,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_1a0 & 1) != 0) {
            func_0x00bc3350(puStack_190);
          }
        }
      }
      else {
        iVar7 = func_0x008700d4(param_1 + 0x4407e8,0x12,uVar4);
        iVar9 = ((iVar7 + 100) * ((iVar9 * (iVar5 + 0x5dc)) / 0x5dc)) / 100;
        func_0x008700d4(param_1 + 0x4407e8,0x12,uVar4);
        uVar11 = func_0x00a5f5ec(param_2,param_3);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) == 0) && (uVar11 = func_0x00a5c198(iVar1,param_4), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          bStack_148 = 0x2c;
          uStack_13f = 0x735f72657075;  /* ascii(0x735f72657075)='uper_s' */
          uStack_147 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          uStack_139 = 0x61;
          uStack_138 = 0x67;
          uStack_137 = 0x776f6c735f65;  /* ascii(0x776f6c735f65)='e_slow' */
          uStack_131 = 0;
          iVar7 = func_0x008e3f14(param_1 + 0x1478,&bStack_148,0x32);
          if ((bStack_148 & 1) != 0) {
            func_0x00bc3350(CONCAT17(uStack_131,CONCAT61(uStack_137,uStack_138)));
          }
          uStack_149 = 0;
          bStack_160 = 0x2c;
          uStack_157 = 0x735f72657075;  /* ascii(0x735f72657075)='uper_s' */
          uStack_15f = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          uStack_151 = 0x61;
          uStack_150 = 0x67;
          uStack_14f = 0x776f6c735f65;  /* ascii(0x776f6c735f65)='e_slow' */
          func_0x008e3f14(param_1 + 0x1478,&bStack_160,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((bStack_160 & 1) != 0) {
            func_0x00bc3350(CONCAT17(uStack_149,CONCAT61(uStack_14f,uStack_150)));
          }
        }
        iVar7 = func_0x00a58874(param_2,param_3);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((iVar7 == 2) && (uVar11 = BattleFn_0x004ab294(), (uVar11 & 1) != 0)) {
          uVar6 = func_0x00a5aa1c(param_2,param_3);  /* 0x95aa1c:[team*0x1f0|off=|] */
          uVar6 = func_0x00999ef0(param_1 + 0x400,2,uVar6);
          func_0x00a5a9c8(iVar1,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
        }
      }
      func_0x00a60ae0(iVar1,param_4,iVar9);  /* 0x960ae0:[slot*1000,team*51000|off=0x83a00|str w19, [x8, x9]] */
      func_0x00a60bc0(iVar1,param_4,iVar9);  /* 0x960bc0:[slot*1000,team*51000|off=0x83a14|str w19, [x8, x9]] */
      BattleFn_0x005ce4cc(param_1,iVar1,param_4,1);
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      uVar11 = BattleFn_0x004ab294();
      if ((param_2 != 0) && ((uVar11 & 1) != 0)) {
        uVar6 = func_0x00999ef0(param_1 + 0x400,7,1);
        func_0x00a5a9c8(iVar1,param_4,uVar6);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
  }
  if (param_9 == 1) {
    uVar11 = func_0x00a5fbe4(iVar1,param_4);  /* 0x95fbe4:[slot*1000,team*51000|off=0x83a74|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar9 = func_0x00a5df30(param_2,param_3);  /* 0x95df30:[slot*1000,team*51000|off=0x83a1c|ldr w0, [x8, x9]] */
      uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
      if ((uVar11 & 1) == 0) {
        iVar7 = func_0x00a62714(iVar1,param_4);  /* 0x962714:[slot*1000,team*51000|off=0x83b6c|ldr w0, [x8, x9]] */
        if (iVar7 != 0) {
          iVar7 = func_0x00a62714(iVar1,param_4);  /* 0x962714:[slot*1000,team*51000|off=0x83b6c|ldr w0, [x8, x9]] */
          func_0x00a62714(iVar1,param_4);  /* 0x962714:[slot*1000,team*51000|off=0x83b6c|ldr w0, [x8, x9]] */
          iVar9 = ((100 - iVar7) * iVar9) / 100;
        }
        uVar12 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar7 = func_0x00629258(uVar12,0xcc,iVar10);
        if (iVar7 != 0) {
          iVar9 = ((10000 - iVar7) * iVar9) / 10000;
        }
        uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_1f0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_1f0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_1f0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_1f0 + 0x17) = 0x6e656b6165775f72;  /* ascii(0x6e656b6165775f72)='r_weaken' */
          *(undefined8 *)((long)puStack_1f0 + 0xf) = 0x65746e75685f6567;  /* ascii(0x65746e75685f6567)='ge_hunte' */
          uStack_1f8 = 0x1f;
          uStack_200 = 0x21;
          *(undefined1 *)((long)puStack_1f0 + 0x1f) = 0;
          iVar7 = func_0x008e3f14(&uStack_200,param_1 + 0x1478,&uStack_200,0x32);
          if ((uStack_200 & 1) != 0) {
            func_0x00bc3350(puStack_1f0);
          }
          puStack_210 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_210 + 0x1f) = 0;
          uStack_218 = 0x1f;
          uStack_220 = 0x21;
          puStack_210[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_210 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_210 + 0x17) = 0x6e656b6165775f72;  /* ascii(0x6e656b6165775f72)='r_weaken' */
          *(undefined8 *)((long)puStack_210 + 0xf) = 0x65746e75685f6567;  /* ascii(0x65746e75685f6567)='ge_hunte' */
          func_0x008e3f14(&uStack_220,param_1 + 0x1478,&uStack_220,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_220 & 1) != 0) {
            func_0x00bc3350(puStack_210);
          }
        }
      }
      else {
        iVar7 = func_0x008700d4(param_1 + 0x4407e8,0x14,uVar4);
        iVar9 = ((iVar7 + 100) * ((iVar9 * (iVar5 + 0x5dc)) / 0x5dc)) / 100;
        func_0x008700d4(param_1 + 0x4407e8,0x14,uVar4);
        uVar11 = func_0x00a5f5ec(param_2,param_3);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) == 0) && (uVar11 = func_0x00a5c198(iVar1,param_4), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_1b0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_1b0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_1b0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          puStack_1b0[2] = 0x6e656b6165775f65;  /* ascii(0x6e656b6165775f65)='e_weaken' */
          uStack_1b8 = 0x18;
          uStack_1c0 = 0x21;
          *(undefined1 *)(puStack_1b0 + 3) = 0;
          iVar7 = func_0x008e3f14(&uStack_1c0,param_1 + 0x1478,&uStack_1c0,0x32);
          if ((uStack_1c0 & 1) != 0) {
            func_0x00bc3350(puStack_1b0);
          }
          puStack_1d0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_1d0[2] = 0x6e656b6165775f65;  /* ascii(0x6e656b6165775f65)='e_weaken' */
          uStack_1d8 = 0x18;
          uStack_1e0 = 0x21;
          *(undefined1 *)(puStack_1d0 + 3) = 0;
          puStack_1d0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_1d0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          func_0x008e3f14(param_1 + 0x1478,&uStack_1e0,0x32);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_1e0 & 1) != 0) {
            func_0x00bc3350(puStack_1d0);
          }
        }
        iVar7 = func_0x00a58874(param_2,param_3);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((iVar7 == 2) && (uVar11 = func_0x00999ab8(param_1 + 0x400), (uVar11 & 1) != 0)) {
          uVar4 = func_0x00a5aa1c(param_2,param_3);  /* 0x95aa1c:[team*0x1f0|off=|] */
          uVar4 = func_0x00999ef0(param_1 + 0x400,0,uVar4);
          func_0x00a5a9c8(iVar1,param_4,uVar4);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
        }
      }
      func_0x00a60cd8(iVar1,param_4,iVar9);  /* 0x960cd8:[slot*1000,team*51000|off=0x83a34|str w19, [x8, x9]] */
      func_0x00a60db8(iVar1,param_4,iVar9);  /* 0x960db8:[slot*1000,team*51000|off=0x83a38|str w19, [x8, x9]] */
      uVar4 = func_0x00a5dfbc(param_2,param_3);  /* 0x95dfbc:[slot*1000,team*51000|off=0x83a20|ldr w0, [x8, x9]] */
      func_0x00a60e44(iVar1,param_4,uVar4);  /* 0x960e44:[slot*1000,team*51000|off=0x83a44|str w19, [x8, x9]] */
      BattleFn_0x005ce4cc(param_1,iVar1,param_4,2);
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      uVar11 = BattleFn_0x004ab294();
      if ((param_2 != 0) && ((uVar11 & 1) != 0)) {
        uVar4 = func_0x00999ef0(param_1 + 0x400,5,1);
        func_0x00a5a9c8(iVar1,param_4,uVar4);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
  }
  if ((param_10 & 1) != 0) {
    uVar11 = func_0x00a5ffd8(iVar1,param_4);  /* 0x95ffd8:[slot*1000,team*51000|off=0x83b44|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar9 = func_0x00a5cdd4(param_2,param_3);  /* 0x95cdd4:[slot*1000,team*51000|off=0x83b28|ldr w0, [x8, x9]] */
      uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
      if ((uVar11 & 1) == 0) {
        iVar7 = func_0x00a629d0(iVar1,param_4);  /* 0x9629d0:[slot*1000,team*51000|off=0x83b80|ldr w0, [x8, x9]] */
        if (iVar7 != 0) {
          iVar7 = func_0x00a629d0(iVar1,param_4);  /* 0x9629d0:[slot*1000,team*51000|off=0x83b80|ldr w0, [x8, x9]] */
          func_0x00a629d0(iVar1,param_4);  /* 0x9629d0:[slot*1000,team*51000|off=0x83b80|ldr w0, [x8, x9]] */
          iVar9 = ((100 - iVar7) * iVar9) / 100;
        }
        uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_230 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_230[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_230 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_230 + 0x15) = 0x707261775f726574;  /* ascii(0x707261775f726574)='ter_warp' */
          *(undefined8 *)((long)puStack_230 + 0xd) = 0x6e75685f65676173;  /* ascii(0x6e75685f65676173)='sage_hun' */
          uStack_238 = 0x1d;
          uStack_240 = 0x21;
          *(undefined1 *)((long)puStack_230 + 0x1d) = 0;
          iVar7 = func_0x008e3f14(&uStack_240,param_1 + 0x1478,&uStack_240,0x46);
          if ((uStack_240 & 1) != 0) {
            func_0x00bc3350(puStack_230);
          }
          puStack_250 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_250 + 0x1d) = 0;
          uStack_258 = 0x1d;
          uStack_260 = 0x21;
          puStack_250[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_250 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_250 + 0x15) = 0x707261775f726574;  /* ascii(0x707261775f726574)='ter_warp' */
          *(undefined8 *)((long)puStack_250 + 0xd) = 0x6e75685f65676173;  /* ascii(0x6e75685f65676173)='sage_hun' */
          func_0x008e3f14(&uStack_260,param_1 + 0x1478,&uStack_260,0x46);
          iVar9 = ((100 - iVar7) * iVar9) / 100;
          if ((uStack_260 & 1) != 0) {
            func_0x00bc3350(puStack_250);
          }
        }
      }
      func_0x00a612ac(iVar1,param_4,iVar9);  /* 0x9612ac:[slot*1000,team*51000|off=0x83b34|str w19, [x8, x9]] */
      iVar9 = func_0x00a5ce60(param_2,param_3);  /* 0x95ce60:[slot*1000,team*51000|off=0x83b2c|ldr w0, [x8, x9]] */
      iVar7 = func_0x00a5ceec(param_2,param_3);  /* 0x95ceec:[slot*1000,team*51000|off=0x83b30|ldr w0, [x8, x9]] */
      iVar8 = func_0x00a5ce60(param_2,param_3);  /* 0x95ce60:[slot*1000,team*51000|off=0x83b2c|ldr w0, [x8, x9]] */
      iVar7 = func_0x0043ea60((iVar7 - iVar8) + 1);
      func_0x00a6138c(iVar1,param_4,iVar7 + iVar9);  /* 0x96138c:[slot*1000,team*51000|off=0x83b38|str w19, [x8, x9]] */
      func_0x00a6134c(iVar1,param_4);  /* 0x96134c:[slot*1000,team*51000|off=0x83b38|ldr w0, [x8, x9]] */
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
    }
  }
  if ((param_11 & 1) != 0) {
    uVar11 = func_0x00a5fd0c(iVar1,param_4);  /* 0x95fd0c:[slot*1000,team*51000|off=0x83b5c|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar9 = func_0x00a5e11c(param_2,param_3);  /* 0x95e11c:[slot*1000,team*51000|off=0x83b58|ldr w0, [x8, x9]] */
      uVar11 = func_0x005b1be4(param_1 + (long)param_2 * 0x1f0 + 0x2648);
      if ((uVar11 & 1) == 0) {
        iVar5 = func_0x00a62a5c(iVar1,param_4);  /* 0x962a5c:[slot*1000,team*51000|off=0x83b84|ldr w0, [x8, x9]] */
        if (iVar5 != 0) {
          iVar5 = func_0x00a62a5c(iVar1,param_4);  /* 0x962a5c:[slot*1000,team*51000|off=0x83b84|ldr w0, [x8, x9]] */
          func_0x00a62a5c(iVar1,param_4);  /* 0x962a5c:[slot*1000,team*51000|off=0x83b84|ldr w0, [x8, x9]] */
          iVar9 = ((100 - iVar5) * iVar9) / 100;
        }
        uVar12 = func_0x0062b6bc(param_1 + 0x21b8);
        iVar10 = func_0x00629258(uVar12,0xce,iVar10);
        if (iVar10 != 0) {
          iVar9 = ((10000 - iVar10) * iVar9) / 10000;
        }
        uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_2b0 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_2b0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_2b0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_2b0 + 0x16) = 0x65737275635f7265;  /* ascii(0x65737275635f7265)='er_curse' */
          *(undefined8 *)((long)puStack_2b0 + 0xe) = 0x746e75685f656761;  /* ascii(0x746e75685f656761)='age_hunt' */
          uStack_2b8 = 0x1e;
          uStack_2c0 = 0x21;
          *(undefined1 *)((long)puStack_2b0 + 0x1e) = 0;
          iVar10 = func_0x008e3f14(&uStack_2c0,param_1 + 0x1478,&uStack_2c0,0x32);
          if ((uStack_2c0 & 1) != 0) {
            func_0x00bc3350(puStack_2b0);
          }
          puStack_2d0 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_2d0 + 0x1e) = 0;
          uStack_2d8 = 0x1e;
          uStack_2e0 = 0x21;
          puStack_2d0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_2d0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_2d0 + 0x16) = 0x65737275635f7265;  /* ascii(0x65737275635f7265)='er_curse' */
          *(undefined8 *)((long)puStack_2d0 + 0xe) = 0x746e75685f656761;  /* ascii(0x746e75685f656761)='age_hunt' */
          func_0x008e3f14(&uStack_2e0,param_1 + 0x1478,&uStack_2e0,0x32);
          iVar9 = ((100 - iVar10) * iVar9) / 100;
          if ((uStack_2e0 & 1) != 0) {
            func_0x00bc3350(puStack_2d0);
          }
        }
      }
      else {
        iVar9 = (iVar9 * (iVar5 + 0x5dc)) / 0x5dc;
        uVar11 = func_0x00a5f5ec(param_2,param_3);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
        if (((uVar11 & 1) == 0) && (uVar11 = func_0x00a5c198(iVar1,param_4), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
          puStack_270 = (undefined8 *)func_0x00bc3330(0x20);
          puStack_270[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_270 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_270 + 0xf) = 0x65737275635f6567;  /* ascii(0x65737275635f6567)='ge_curse' */
          uStack_278 = 0x17;
          uStack_280 = 0x21;
          *(undefined1 *)((long)puStack_270 + 0x17) = 0;
          iVar10 = func_0x008e3f14(&uStack_280,param_1 + 0x1478,&uStack_280,0x32);
          if ((uStack_280 & 1) != 0) {
            func_0x00bc3350(puStack_270);
          }
          puStack_290 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_290 + 0x17) = 0;
          puStack_290[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
          *puStack_290 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
          *(undefined8 *)((long)puStack_290 + 0xf) = 0x65737275635f6567;  /* ascii(0x65737275635f6567)='ge_curse' */
          uStack_298 = 0x17;
          uStack_2a0 = 0x21;
          func_0x008e3f14(&uStack_2a0,param_1 + 0x1478,&uStack_2a0,0x32);
          iVar9 = ((100 - iVar10) * iVar9) / 100;
          if ((uStack_2a0 & 1) != 0) {
            func_0x00bc3350(puStack_290);
          }
        }
        iVar10 = func_0x00a58874(param_2,param_3);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((iVar10 == 2) && (uVar11 = func_0x00999ab8(param_1 + 0x400), (uVar11 & 1) != 0)) {
          uVar4 = func_0x00a5aa1c(param_2,param_3);  /* 0x95aa1c:[team*0x1f0|off=|] */
          uVar4 = func_0x00999ef0(param_1 + 0x400,4,uVar4);
          func_0x00a5a9c8(iVar1,param_4,uVar4);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
        }
      }
      func_0x00a60f80(iVar1,param_4,iVar9);  /* 0x960f80:[slot*1000,team*51000|off=0x83b60|str w19, [x8, x9]] */
      func_0x00a61020(iVar1,param_4,iVar9);  /* 0x961020:[slot*1000,team*51000|off=0x83b64|str w19, [x8, x9]] */
      BattleFn_0x005ce4cc(param_1,iVar1,param_4,4);
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      uVar11 = BattleFn_0x004ab294();
      if ((param_2 != 0) && ((uVar11 & 1) != 0)) {
        uVar4 = func_0x00999ef0(param_1 + 0x400,9,1);
        func_0x00a5a9c8(iVar1,param_4,uVar4);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
  }
  if ((param_4 != 0) && ((param_12 & 1) != 0)) {
    uVar11 = func_0x00a60340(iVar1,param_4);  /* 0x960340:[slot*1000,team*51000|off=0x83cec|ldr w8, [x8, x9]] */
    if ((uVar11 & 1) == 0) {
      iVar10 = func_0x00a5f874(param_2,param_3);  /* 0x95f874:[slot*1000,team*51000|off=0x83ce4|ldr w0, [x8, x9]] */
      uVar11 = func_0x00a5f5ec(iVar1,param_4);  /* 0x95f5ec:[slot*1000,team*0x1f0,team*51000|off=0x83c68|ldr w8, [x8, x9]] */
      if (((uVar11 & 1) != 0) && (uVar11 = func_0x00a5c198(param_2,param_3), (uVar11 & 1) != 0)) {  /* 0x95c198:[slot*1000,team*0x1f0,team*51000|off=0x83c64|ldr w8, [x8, x9]] */
        puStack_2f0 = (undefined8 *)func_0x00bc3330(0x30);
        *(undefined2 *)(puStack_2f0 + 4) = 0x6b63;
        uStack_2f8 = 0x22;
        uStack_300 = 0x31;
        *(undefined1 *)((long)puStack_2f0 + 0x22) = 0;
        puStack_2f0[1] = 0x6761735f72657075;  /* ascii(0x6761735f72657075)='uper_sag' */
        *puStack_2f0 = 0x735f656c74746162;  /* ascii(0x735f656c74746162)='battle_s' */
        puStack_2f0[3] = 0x61626b636f6e6b5f;  /* ascii(0x61626b636f6e6b5f)='_knockba' */
        puStack_2f0[2] = 0x7265746e75685f65;  /* ascii(0x7265746e75685f65)='e_hunter' */
        iVar5 = func_0x008e3f14(&uStack_300,param_1 + 0x1478,&uStack_300,0x32);
        iVar10 = ((100 - iVar5) * iVar10) / 100;
        if ((uStack_300 & 1) != 0) {
          func_0x00bc3350(puStack_2f0);
        }
      }
      func_0x00a61dc0(iVar1,param_4,iVar10);  /* 0x961dc0:[slot*1000,team*51000|off=0x83ce8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
    }
    else {
      func_0x00a60f1c(iVar1,param_4);  /* 0x960f1c:[slot*1000,team*51000|off=0x83a9c,0x83aa0|str wzr, [x8, x9] ; str w10, [x8, x9]] */
      uVar11 = BattleFn_0x004ab294();
      if ((param_2 != 0) && ((uVar11 & 1) != 0)) {
        uVar4 = func_0x00999ef0(param_1 + 0x400,0x13,1);
        func_0x00a5a9c8(iVar1,param_4,uVar4);  /* 0x95a9c8:[slot*1000,team*51000|off=0x83ca8|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
      }
    }
  }
  if (*(long *)(lVar2 + 0x28) == lStack_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


