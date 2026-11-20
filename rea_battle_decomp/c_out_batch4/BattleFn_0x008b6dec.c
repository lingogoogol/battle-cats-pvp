// ELF VMA: 0x8b6dec
// Ghidra Addr: 0x009b6dec (ImageBase=0x100000)
// Size: 8992 bytes


ulong BattleFn_0x008b6dec(long param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                         int param_7,int param_8)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  int extraout_w1;
  int extraout_w1_00;
  int extraout_w1_01;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  ulong auStack_a0 [2];
  undefined8 *puStack_90;
  ulong auStack_80 [2];
  undefined8 *puStack_70;
  long lStack_68;
  
  lVar1 = tpidr_el0;
  lStack_68 = *(long *)(lVar1 + 0x28);
  if (param_3 == -1) {
    uVar14 = 0xfffffffe;
  }
  else {
    iVar9 = param_3 + -2;
    uVar14 = 1;
    do {
      iVar4 = func_0x00a58874(param_2,uVar14);
      iVar7 = (int)uVar14;
      if (iVar4 == 0) {
        func_0x00a58978(param_2,uVar14,2,iVar9);
        func_0x00a590fc(param_2,uVar14,0);
        if ((param_2 == 1) && (iVar4 = BattleFn_0x004aad10(), iVar4 == iVar7)) {
          iVar4 = 0xc80;
          iVar8 = 1;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x9e538) + -0xaf0;
          iVar8 = param_2;
          if (param_2 != 0) {
            iVar4 = 0xaf0;
          }
        }
        func_0x00a591dc(iVar8,uVar14,iVar4);
        func_0x00a597a4(param_2,uVar14,0x1180);
        lVar12 = param_1 + (long)param_2 * 51000 + uVar14 * 1000;
        *(int *)(lVar12 + 0x8391c) = param_5;
        iVar4 = func_0x0043ea60((param_6 - param_5 & (param_6 - param_5 >> 0x1f ^ 0xffffffffU)) + 1)
        ;
        *(int *)(lVar12 + 0x8391c) = *(int *)(lVar12 + 0x8391c) + iVar4;
        *(int *)(lVar12 + 0x83920) = param_4;
        func_0x00a59830(param_2,uVar14,0);
        func_0x00a60414(param_2,uVar14,0);
        func_0x00a61d74(param_2,uVar14,0);
        func_0x00a598bc(param_2,uVar14,0);
        func_0x00a59950(param_2,uVar14,0);
        func_0x00a59b90(param_2,uVar14,0);
        uVar5 = func_0x00a6548c(param_2,iVar9,param_7);
        func_0x00a59ca8(param_2,uVar14,uVar5);
        uVar5 = func_0x00a65514(param_2,iVar9,param_7);
        func_0x00a59d88(param_2,uVar14,uVar5);
        uVar5 = func_0x00a656d8(param_2,iVar9,param_7);
        func_0x00a59e68(param_2,uVar14,uVar5);
        uVar5 = func_0x00a65760(param_2,iVar9,param_7);
        func_0x00a59ef4(param_2,uVar14,uVar5);
        uVar6 = func_0x00a657e8(param_2,iVar9,param_7);
        func_0x00a59f88(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a65878(param_2,iVar9,param_7);
        func_0x00a5a01c(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a632d8(param_2,iVar9,param_7,param_4 + 1,param_8);
        func_0x00a5a1d4(param_2,uVar14,uVar5);
        uVar5 = func_0x00a5a194(param_2,uVar14);
        func_0x00a5a260(param_2,uVar14,uVar5);
        uVar5 = func_0x00a64374(param_2,iVar9,param_7);
        func_0x00a5a340(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6441c(param_2,iVar9,param_7);
        func_0x00a5a38c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a64d60(param_2,iVar9,param_7);
        func_0x00a5a5dc(param_2,uVar14,uVar5);
        uVar5 = func_0x00a64e28(param_2,iVar9,param_7);
        func_0x00a5a668(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6537c(param_2,iVar9,param_7);
        func_0x00a5a6f4(param_2,uVar14,uVar5);
        uVar5 = func_0x00a65404(param_2,iVar9,param_7);
        func_0x00a5a740(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6559c(param_2,iVar9,param_7);
        func_0x00a5a82c(param_2,uVar14,uVar5);
        if (param_2 == 1) {
          iVar4 = BattleFn_0x004aad10();
          uVar5 = BattleFn_0x009645a8(1,iVar9,param_7,param_4 + 1,param_8,0,0,iVar7 == iVar4);
          func_0x00a5a434(1,uVar14,0,uVar5);
          uVar5 = BattleFn_0x00964cb4(1,iVar9,param_7,0);
          func_0x00a5a78c(1,uVar14,0,uVar5);
          uVar6 = func_0x00a65624(1,iVar9,param_7,0);
          func_0x00a5a8dc(1,uVar14,0,uVar6 & 1);
          iVar4 = BattleFn_0x004aad10();
          bVar2 = iVar7 == iVar4;
        }
        else {
          uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,0,0,0);
          func_0x00a5a434(param_2,uVar14,0,uVar5);
          uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,0);
          func_0x00a5a78c(param_2,uVar14,0,uVar5);
          uVar6 = func_0x00a65624(param_2,iVar9,param_7,0);
          func_0x00a5a8dc(param_2,uVar14,0,uVar6 & 1);
          bVar2 = false;
        }
        uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,1,0,bVar2);
        func_0x00a5a434(param_2,uVar14,1,uVar5);
        uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,1);
        func_0x00a5a78c(param_2,uVar14,1,uVar5);
        uVar6 = func_0x00a65624(param_2,iVar9,param_7,1);
        func_0x00a5a8dc(param_2,uVar14,1,uVar6 & 1);
        bVar2 = false;
        if (param_2 == 1) {
          iVar4 = BattleFn_0x004aad10();
          bVar2 = iVar7 == iVar4;
        }
        uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,2,0,bVar2);
        func_0x00a5a434(param_2,uVar14,2,uVar5);
        uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,2);
        func_0x00a5a78c(param_2,uVar14,2,uVar5);
        uVar6 = func_0x00a65624(param_2,iVar9,param_7,2);
        func_0x00a5a8dc(param_2,uVar14,2,uVar6 & 1);
        uVar6 = func_0x00a67af0(param_2,iVar9,param_7,1);
        func_0x00a5bb90(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67bb0(param_2,iVar9,param_7,1);
        func_0x00a5bc10(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67c70(param_2,iVar9,param_7,1);
        func_0x00a5bc5c(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67d30(param_2,iVar9,param_7,1);
        func_0x00a5bca8(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a66964(param_2,iVar9,param_7);
        func_0x00a5bcf4(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a68030(param_2,iVar9,param_7,1);
        func_0x00a5bd74(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67df0(param_2,iVar9,param_7,1);
        func_0x00a5bdc0(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a64258(param_2,iVar9,param_7,1);
        func_0x00a5be0c(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a64318(param_2,iVar9,param_7,1);
        func_0x00a5be58(param_2,uVar14,uVar5);
        uVar6 = func_0x00a67eb0(param_2,iVar9,param_7,1);
        func_0x00a5bea4(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a695b8(param_2,iVar9,param_7,1);
        func_0x00a5bef0(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a69678(param_2,iVar9,param_7,1);
        func_0x00a5bf3c(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67f70(param_2,iVar9,param_7,1);
        func_0x00a5bf88(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a68634(param_2,iVar9,param_7,1);
        func_0x00a5bfd4(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a6948c(param_2,iVar9,param_7);
        func_0x00a5c090(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a694f0(param_2,iVar9,param_7);
        func_0x00a5c14c(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a69554(param_2,iVar9,param_7);
        func_0x00a5c208(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a69738(param_2,iVar9,param_7);
        func_0x00a5c29c(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a66aac(param_2,iVar9,param_7);
        func_0x00a5c330(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a668c0(param_2,iVar9,param_7);
        func_0x00a5c3bc(param_2,uVar14,uVar5);
        uVar5 = func_0x00a66748(param_2,iVar9,param_7,0xffffffff);
        func_0x00a5c408(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a110(param_2,iVar9,param_7,0xffffffff);
        func_0x00a5c454(param_2,uVar14,uVar5);
        uVar5 = func_0x00a666a0(param_2,iVar9,param_7);
        func_0x00a5c5a8(param_2,uVar14,uVar5);
        uVar6 = func_0x00a663bc(param_2,iVar9,param_7);
        func_0x00a5c664(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a66578(param_2,iVar9,param_7);
        func_0x00a5c744(param_2,uVar14,uVar6 & 1);
        bVar3 = param_2 != 0;
        uVar5 = 0;
        bVar2 = param_7 < 2;
        if (!bVar3 && 1 < param_7) {
          uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x00653738(param_1 + 0x1538,iVar9,7,0,0);
          }
        }
        func_0x00a5c81c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a66184(param_2,iVar9,param_7);
        func_0x00a5c888(param_2,uVar14,uVar5);
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,0);
        func_0x00a5c9b8(param_2,uVar14,0,uVar6 & 1);
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,0);
        func_0x00a5cb2c(param_2,uVar14,0,uVar5);
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,0);
        func_0x00a5cca0(param_2,uVar14,0,uVar5);
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,1);
        func_0x00a5c9b8(param_2,uVar14,1,uVar6 & 1);
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,1);
        func_0x00a5cb2c(param_2,uVar14,1,uVar5);
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,1);
        func_0x00a5cca0(param_2,uVar14,1,uVar5);
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,2);
        func_0x00a5c9b8(param_2,uVar14,2,uVar6 & 1);
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,2);
        func_0x00a5cb2c(param_2,uVar14,2,uVar5);
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,2);
        func_0x00a5cca0(param_2,uVar14,2,uVar5);
        uVar5 = func_0x00a6756c(param_2,iVar9,param_7);
        func_0x00a5cd88(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a400(param_2,iVar9,param_7);
        func_0x00a5ce14(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a4a8(param_2,iVar9,param_7);
        func_0x00a5cea0(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a550(param_2,iVar9,param_7);
        func_0x00a5cf2c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68b54(param_2,iVar9,param_7);
        func_0x00a5d088(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a5f8(param_2,iVar9,param_7);
        func_0x00a5d114(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68240(param_2,iVar9,param_7);
        func_0x00a5d1e0(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a654(param_2,iVar9,param_7);
        func_0x00a5d26c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a724(param_2,iVar9,param_7);
        func_0x00a5d2f8(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a7f4(param_2,iVar9,param_7);
        func_0x00a5d384(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68310(param_2,iVar9,param_7);
        func_0x00a5d3d0(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68bb0(param_2,iVar9,param_7);
        func_0x00a5d41c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a8c4(param_2,iVar9,param_7);
        func_0x00a5d4a8(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a920(param_2,iVar9,param_7);
        func_0x00a5d534(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a97c(param_2,iVar9,param_7);
        func_0x00a5d5c0(param_2,uVar14,uVar5);
        func_0x00a5d64c(param_2,uVar14,100);
        func_0x00a5d6d8(param_2,uVar14,0);
        if (bVar3 || bVar2) {
          uVar6 = func_0x00a688b0(param_2,iVar9,param_7);
          func_0x00a5d76c(param_2,uVar14,uVar6 & 1);
          func_0x00a5d7f8(param_2,uVar14,100);
          uVar11 = 0;
          iVar4 = param_2;
LAB_009b7b78:
          func_0x00a5d88c(iVar4,uVar14,uVar11);
        }
        else {
          lVar12 = param_1 + (long)param_2 * 0x1f0;
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          if (((uVar10 & 1) != 0) &&
             (iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,5,0,0), 0 < iVar4)) {
            func_0x00a5d41c(0,uVar14,100);
            puStack_70 = (undefined8 *)func_0x00bc3330(0x30);
            auStack_80[1] = 0x20;
            auStack_80[0] = 0x31;
            puStack_70[1] = 0x5f68746165645f66;
            *puStack_70 = 0x615f656c74746162;
            puStack_70[3] = 0x65636e6174736964;
            puStack_70[2] = 0x5f6f6e61636c6f76;
            *(undefined1 *)(puStack_70 + 4) = 0;
            uVar5 = func_0x008e3f14(auStack_80,param_1 + 0x1478,auStack_80,600);
            func_0x00a5d4a8(0,uVar14,uVar5);
            if ((auStack_80[0] & 1) != 0) {
              func_0x00bc3350(puStack_70);
            }
            puStack_90 = (undefined8 *)func_0x00bc3330(0x20);
            puStack_90[1] = 0x5f68746165645f66;
            *puStack_90 = 0x615f656c74746162;
            *(undefined8 *)((long)puStack_90 + 0x15) = 0x68746469775f6f6e;
            *(undefined8 *)((long)puStack_90 + 0xd) = 0x61636c6f765f6874;
            auStack_a0[1] = 0x1d;
            auStack_a0[0] = 0x21;
            *(undefined1 *)((long)puStack_90 + 0x1d) = 0;
            uVar5 = func_0x008e3f14(param_1 + 0x1478,auStack_a0,4000);
            func_0x00a5d534(0,uVar14,uVar5);
            if ((auStack_a0[0] & 1) != 0) {
              func_0x00bc3350(puStack_90);
            }
            func_0x00a5d5c0(0,uVar14,1);
            func_0x00a5d64c(0,uVar14,iVar4 * 5);
            func_0x00a5d6d8(0,uVar14,1);
          }
          uVar6 = func_0x00a688b0(0,iVar9,param_7);
          func_0x00a5d76c(0,uVar14,uVar6 & 1);
          func_0x00a5d7f8(0,uVar14,100);
          func_0x00a5d88c(0,uVar14,0);
          uVar10 = func_0x00a5d724(0,uVar14);
          if ((((uVar10 & 1) == 0) &&
              (uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14), (uVar10 & 1) != 0)) &&
             (iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,0x11,0,0), 0 < iVar4)) {
            func_0x00a5d76c(0,uVar14,1);
            func_0x00a5d7f8(0,uVar14,iVar4);
            iVar4 = 0;
            uVar11 = 1;
            goto LAB_009b7b78;
          }
        }
        uVar5 = func_0x00a68cc4(param_2,iVar9,param_7);
        func_0x00a5d918(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6a9d8(param_2,iVar9,param_7);
        func_0x00a5d9a4(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6aa80(param_2,iVar9,param_7);
        func_0x00a5da30(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68968(param_2,iVar9,param_7);
        func_0x00a5dabc(param_2,uVar14,uVar5);
        func_0x00a5db08(param_2,uVar14,0xffffffff);
        uVar5 = func_0x00a66034(param_2,iVar9,param_7);
        func_0x00a5dc24(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6ab28(param_2,iVar9,param_7);
        func_0x00a5dcb0(param_2,uVar14,uVar5);
        uVar5 = func_0x00a660dc(param_2,iVar9,param_7);
        func_0x00a5dd84(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6abd0(param_2,iVar9,param_7);
        func_0x00a5de10(param_2,uVar14,uVar5);
        uVar5 = func_0x00a65e64(param_2,iVar9,param_7);
        func_0x00a5dee4(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6ac78(param_2,iVar9,param_7);
        func_0x00a5df70(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6ad20(param_2,iVar9,param_7);
        func_0x00a5dffc(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68448(param_2,iVar9,param_7);
        func_0x00a5e0d0(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6ae2c(param_2,iVar9,param_7);
        func_0x00a5e15c(param_2,uVar14,uVar5);
        uVar5 = func_0x00a65f0c(param_2,iVar9,param_7);
        func_0x00a5e1e8(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6aed4(param_2,iVar9,param_7);
        func_0x00a5e274(param_2,uVar14,uVar5);
        uVar6 = func_0x00a66450(param_2,iVar9,param_7);
        func_0x00a5e570(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a664e4(param_2,iVar9,param_7);
        func_0x00a5e650(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a6660c(param_2,iVar9,param_7);
        func_0x00a5e730(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67a78(param_2,iVar9,param_7);
        func_0x00a5e810(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67a00(param_2,iVar9,param_7);
        func_0x00a5e8f0(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a662e4(param_2,iVar9,param_7);
        func_0x00a5e9e8(param_2,uVar14,uVar5);
        uVar6 = func_0x00a6622c(param_2,iVar9,param_7);
        func_0x00a5ea7c(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a671ac(param_2,iVar9,param_7);
        func_0x00a5eb38(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a67134(param_2,iVar9,param_7);
        func_0x00a5ec18(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a6743c(param_2,iVar9,param_7);
        func_0x00a5ecf8(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a686f4(param_2,iVar9,param_7);
        func_0x00a5edd8(param_2,uVar14,uVar6 & 1);
        func_0x00a5ef28(param_2,uVar14,0,0);
        if (((!bVar3 && !bVar2) && (uVar6 & 1) == 0) &&
           (uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14),
           (uVar10 & 1) != 0)) {
          iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,10,0,0);
          iVar7 = func_0x006535d4(param_1 + 0x1538,iVar9,10,1,0);
          if ((0 < iVar4) && (0 < iVar7)) {
            func_0x00a5edd8(0,uVar14,1);
            func_0x00a5ef28(0,uVar14,iVar4,iVar7);
          }
        }
        uVar5 = func_0x00a672f8(param_2,iVar9,param_7);
        func_0x00a5f120(param_2,uVar14,uVar5);
        uVar5 = func_0x00a685a8(param_2,iVar9,param_7);
        func_0x00a5f1f4(param_2,uVar14,uVar5);
        uVar5 = func_0x00a680f0(param_2,iVar9,param_7);
        func_0x00a5f240(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6af7c(param_2,iVar9,param_7);
        func_0x00a5f2cc(param_2,uVar14,uVar5);
        uVar6 = func_0x00a68788(param_2,iVar9,param_7);
        func_0x00a5f318(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a6881c(param_2,iVar9,param_7);
        func_0x00a5f3d4(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a6b024(param_2,iVar9,param_7);
        func_0x00a5f4ac(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6b0b0(param_2,iVar9,param_7);
        func_0x00a5f580(param_2,uVar14,uVar5);
        uVar6 = func_0x00a689ec(param_2,iVar9,param_7);
        func_0x00a5f65c(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a68a80(param_2,iVar9,param_7);
        func_0x00a5f734(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6b13c(param_2,iVar9,param_7);
        func_0x00a5f828(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6b198(param_2,iVar9,param_7);
        func_0x00a5f8b4(param_2,uVar14,uVar5);
        uVar6 = func_0x00a67240(param_2,iVar9,param_7);
        func_0x00a5f9dc(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a68af0(param_2,iVar9,param_7);
        func_0x00a5fcc0(param_2,uVar14,uVar6 & 1);
        uVar6 = func_0x00a6b1f4(param_2,iVar9,param_7);
        func_0x00a5fde8(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a68c0c(param_2,iVar9,param_7);
        func_0x00a5fe74(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6b348(param_2,iVar9,param_7,param_8);
        func_0x00a5ff00(param_2,uVar14,uVar5);
        uVar5 = func_0x00a68c68(param_2,iVar9,param_7);
        func_0x00a5ff8c(param_2,uVar14,uVar5);
        uVar6 = func_0x00a67384(param_2,iVar9,param_7);
        func_0x00a60020(param_2,uVar14,uVar6 & 1);
        uVar5 = func_0x00a68198(param_2,iVar9,param_7);
        func_0x00a600ac(param_2,uVar14,uVar5);
        uVar5 = func_0x00a6b4d0(param_2,iVar9,param_7);
        func_0x00a60138(param_2,uVar14,uVar5);
        func_0x00a62ccc(param_2,uVar14,0);
        func_0x00a62d58(param_2,uVar14,0);
        if (((!bVar3 && !bVar2) &&
            (uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14),
            (uVar10 & 1) != 0)) &&
           (uVar10 = func_0x006532b8(param_1 + 0x1538,iVar9,0xd), (uVar10 & 1) != 0)) {
          uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xd,0,0);
          func_0x00a62ccc(0,uVar14,uVar5);
          uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xd,1,0);
          func_0x00a62d58(0,uVar14,uVar5);
        }
        func_0x00a6073c(param_2,uVar14,0);
        func_0x00a607d0(param_2,uVar14,0);
        func_0x00a608e8(param_2,uVar14,0);
        func_0x00a609c8(param_2,uVar14,0);
        func_0x00a60a54(param_2,uVar14,0);
        func_0x00a60ae0(param_2,uVar14,0);
        func_0x00a60bc0(param_2,uVar14,0);
        func_0x00a60c4c(param_2,uVar14,0);
        lVar12 = param_1 + (long)param_2 * 51000 + uVar14 * 1000;
        *(undefined4 *)(lVar12 + 0x83a04) = 0;
        func_0x00a59ab0(param_2,uVar14,0);
        func_0x00a60cd8(param_2,uVar14,0);
        func_0x00a60db8(param_2,uVar14,0);
        func_0x00a60ed0(param_2,uVar14,0);
        func_0x00a60e44(param_2,uVar14,0);
        *(undefined4 *)(lVar12 + 0x83a40) = 0;
        *(undefined4 *)(lVar12 + 0x83a3c) = 0;
        *(undefined4 *)(lVar12 + 0x83a48) = 0;
        func_0x00a614dc(param_2,uVar14,0);
        func_0x00a61568(param_2,uVar14,0);
        func_0x00a61730(param_2,uVar14,0);
        uVar5 = func_0x00a6b348(param_2,iVar9,param_7,param_8);
        func_0x00a617bc(param_2,uVar14,uVar5);
        func_0x00a618d4(param_2,uVar14,0);
        func_0x00a61b20(param_2,uVar14,0);
        func_0x00a61c08(param_2,uVar14,0);
        func_0x00a61c94(param_2,uVar14,0);
        func_0x00a61434(param_2,uVar14,0,0);
        func_0x00a61434(param_2,uVar14,1,0);
        func_0x00a61434(param_2,uVar14,2,0);
        func_0x00a61434(param_2,uVar14,3,0);
        func_0x00a61434(param_2,uVar14,4,0);
        *(undefined8 *)(lVar12 + 0x83a78) = 0;
        *(undefined8 *)(lVar12 + 0x83a80) = 0;
        *(undefined4 *)(lVar12 + 0x83a88) = 0;
        func_0x00a61140(param_2,uVar14,0);
        func_0x00a612ac(param_2,uVar14,0);
        func_0x00a60f80(param_2,uVar14,0);
        func_0x00a61020(param_2,uVar14,0);
        func_0x00a610ac(param_2,uVar14,0);
        uVar10 = func_0x00a66e54(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x12,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x15,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fc2c(param_2,uVar14,0);
        func_0x00a62754(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a62754(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a5fc2c(param_2,uVar14,1);
        }
        uVar10 = func_0x00a66f0c(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x13,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x14,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fb04(param_2,uVar14,0);
        func_0x00a627e0(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a627e0(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a5fb04(param_2,uVar14,1);
        }
        uVar10 = func_0x00a66fc4(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x14,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xe,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fb98(param_2,uVar14,0);
        func_0x00a6286c(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a6286c(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a5fb98(param_2,uVar14,1);
        }
        uVar10 = func_0x00a6707c(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x15,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,8,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fa70(param_2,uVar14,0);
        func_0x00a628f8(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a628f8(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a5fa70(param_2,uVar14,1);
        }
        uVar10 = func_0x00a669f4(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x16,0);
          if (bVar3 || bVar2) goto LAB_009b8a18;
          iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,6,0,0);
          iVar4 = iVar7 + iVar4;
LAB_009b8a40:
          iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x1a,iVar9);
          iVar7 = iVar4 + 100;
          if (iVar8 < 1) {
            iVar7 = iVar4;
          }
        }
        else {
          iVar4 = 100;
LAB_009b8a18:
          iVar7 = iVar4;
          if (param_2 == 0) goto LAB_009b8a40;
        }
        func_0x00a5f948(param_2,uVar14,0);
        func_0x00a62984(param_2,uVar14,0);
        if (iVar7 < 100) {
          func_0x00a62984(param_2,uVar14,iVar7);
        }
        else {
          func_0x00a5f948(param_2,uVar14,1);
        }
        uVar5 = func_0x00a63984(param_2,iVar9,param_7,0x18,0);
        func_0x00a62a10(param_2,uVar14,uVar5);
        uVar10 = func_0x00a674b4(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x1e,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xf,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fd54(param_2,uVar14,0);
        func_0x00a62a9c(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a62a9c(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a5fd54(param_2,uVar14,1);
        }
        uVar10 = func_0x00a683b4(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x34,0);
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xc,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a601cc(param_2,uVar14,0);
        func_0x00a62b28(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a62b28(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a601cc(param_2,uVar14,1);
        }
        uVar10 = func_0x00a684f0(param_2,iVar9,param_7);
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x36,0);
          if (bVar3 || bVar2) goto LAB_009b8c48;
          iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x17,0,0);
          iVar4 = iVar7 + iVar4;
LAB_009b8c70:
          iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x1c,iVar9);
          iVar7 = iVar4 + 100;
          if (iVar8 < 1) {
            iVar7 = iVar4;
          }
        }
        else {
          iVar4 = 100;
LAB_009b8c48:
          iVar7 = iVar4;
          if (param_2 == 0) goto LAB_009b8c70;
        }
        func_0x00a60260(param_2,uVar14,0);
        func_0x00a62bb4(param_2,uVar14,0);
        if (iVar7 < 100) {
          func_0x00a62bb4(param_2,uVar14,iVar7);
        }
        else {
          func_0x00a60260(param_2,uVar14,1);
        }
        uVar10 = func_0x00a68d6c(param_2,iVar9,param_7);
        iVar4 = 100;
        if ((uVar10 & 1) == 0) {
          iVar4 = 0;
        }
        if ((!bVar3 && !bVar2) && (uVar10 & 1) == 0) {
          iVar4 = func_0x00653738(param_1 + 0x1538,iVar9,0x19,0,0);
        }
        func_0x00a602f4(param_2,uVar14,0);
        func_0x00a62c40(param_2,uVar14,0);
        if (iVar4 < 100) {
          func_0x00a62c40(param_2,uVar14,iVar4);
        }
        else {
          func_0x00a602f4(param_2,uVar14,1);
        }
        uVar10 = func_0x00a6b26c(param_2,iVar9,param_7);
        func_0x00a60388(param_2,uVar14,0);
        if ((uVar10 & 1) != 0) {
          func_0x00a60388(param_2,uVar14,1);
        }
        lVar12 = param_1 + (long)param_2 * 0x1f0;
        uVar10 = func_0x005b1be4(lVar12 + 0x2648);
        if ((uVar10 & 1) == 0) {
          uVar5 = func_0x009cbce0(*(long *)(param_1 + 0x9e560) + (long)param_8 * 0x38);
          func_0x00a59a04(param_2,uVar14,uVar5);
          uVar10 = func_0x00a59560(param_2,uVar14);
          if ((uVar10 & 1) != 0) {
            iVar7 = func_0x00a5780c(1);
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);
            iVar4 = (int)((ulong)((long)(extraout_w1 * 0x49c) * -0x51eb851f) >> 0x20);
            uVar5 = BattleFn_0x004ab0a8();
            iVar8 = func_0x00646668(&UNK_00327fa0 + param_1,uVar5);
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);
            func_0x00a591dc(param_2,uVar14,
                            ((iVar4 >> 5) - (iVar4 >> 0x1f)) + iVar7 +
                            (extraout_w1_00 * iVar8) / 10 + (extraout_w1_01 * 0x7f) / 10);
          }
          lVar13 = param_1 + (long)param_3 * 0x1c4;
          func_0x00a61e7c(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7224));
          func_0x00a62004(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x722c));
          func_0x00a62124(param_2,uVar14,0);
          func_0x00a6226c(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7234));
          func_0x00a62340(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7230));
          func_0x00a62414(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7228));
          func_0x00a625c4(param_2,uVar14,0);
          func_0x00a626a4(param_2,uVar14,0);
          uVar5 = func_0x009cbd14(*(long *)(param_1 + 0x9e560) + (long)param_8 * 0x38);
          func_0x00a59c1c(param_2,uVar14,uVar5);
          if (!bVar3 && !bVar2) goto LAB_009b8f94;
LAB_009b9038:
          func_0x00a62de4(param_2,uVar14,0);
          func_0x00a62e70(param_2,uVar14,0);
          uVar5 = 0;
        }
        else {
          func_0x00a59a04(param_2,uVar14,0);
          if (bVar3 || bVar2) goto LAB_009b9038;
LAB_009b8f94:
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xb,0,0);
          }
          func_0x00a62de4(0,uVar14,uVar5);
          func_0x00a62e70(0,uVar14,0);
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0x18,0,0);
          }
        }
        func_0x00a62efc(param_2,uVar14,uVar5);
        param_1 = param_1 + (long)param_2 * 0x1f0;
        *(int *)(param_1 + 0x281c) = *(int *)(param_1 + 0x281c) + 1;
        func_0x00a5a0a8(param_2,uVar14);
        func_0x00a5a0f4(param_2,uVar14,0);
        uVar10 = func_0x00a59f40(param_2,uVar14);
        uVar5 = 10;
        if ((uVar10 & 1) == 0) {
          iVar9 = func_0x00a59e28(param_2,uVar14);
          uVar5 = 0;
          if (-1 < iVar9) {
            uVar5 = 10;
          }
        }
        func_0x00a58be4(param_2,uVar14,uVar5);
        goto LAB_009b90d4;
      }
      uVar14 = (ulong)(iVar7 + 1U);
    } while (iVar7 + 1U != 0x33);
    uVar14 = 0xffffffff;
  }
LAB_009b90d4:
  if (*(long *)(lVar1 + 0x28) == lStack_68) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


