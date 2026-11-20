// ELF VMA: 0x005cbf84 | Ghidra Addr: 0x006cbf84 | BodySize: 4804

/* WARNING: Removing unreachable block (ram,0x006cc930) */
/* WARNING: Removing unreachable block (ram,0x006cc934) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void BattleFn_0x005cbf84(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  long lVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  undefined4 uVar25;
  long *plVar26;
  ulong uVar27;
  long *plVar28;
  undefined8 *puVar29;
  ulong uVar30;
  long lVar31;
  ulong uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 *puVar35;
  bool bVar36;
  undefined1 uVar37;
  long *plVar38;
  long lVar39;
  long lVar40;
  undefined1 *puVar41;
  ulong uVar42;
  ulong uVar43;
  ulong uVar44;
  long *unaff_x19;
  int *piVar45;
  byte unaff_w20;
  int iVar46;
  int iVar47;
  long *plVar48;
  long *plVar49;
  int *piVar50;
  int *unaff_x22;
  undefined4 *puVar51;
  long unaff_x23;
  int *piVar52;
  uint uVar53;
  int iVar54;
  long *plVar55;
  undefined8 *puVar56;
  long *unaff_x28;
  long unaff_x29;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float fVar65;
  float fVar66;
  undefined8 unaff_d8;
  float unaff_s9;
  undefined8 unaff_d10;
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  long *in_stack_00000018;
  int *in_stack_00000020;
  int *in_stack_00000028;
  undefined8 *in_stack_00000030;
  undefined8 *in_stack_00000038;
  long in_stack_00000040;
  int *in_stack_00000048;
  int *in_stack_00000050;
  int *in_stack_00000058;
  int *in_stack_00000060;
  undefined8 in_stack_00000068;
  long *in_stack_00000070;
  long *in_stack_00000078;
  undefined8 *in_stack_00000080;
  long *in_stack_00000088;
  long *in_stack_00000090;
  long *in_stack_00000098;
  int *in_stack_000000a0;
  long in_stack_000000a8;
  long in_stack_000000b0;
  int *in_stack_000000b8;
  long *in_stack_000000c0;
  uint *in_stack_000000c8;
  long *in_stack_000000d0;
  long *in_stack_000000d8;
  long *in_stack_000000e0;
  long *in_stack_000000e8;
  ulong in_stack_000000f0;
  undefined8 in_stack_000000f8;
  long *in_stack_00000100;
  long *in_stack_00000108;
  long *in_stack_00000110;
  long in_stack_00000148;
  long *in_stack_00000150;
  undefined8 *in_stack_00000158;
  long in_stack_00000160;
  int *in_stack_00000170;
  long *in_stack_00000180;
  long *in_stack_00000188;
  long *in_stack_00000190;
  byte in_stack_000001a0;
  undefined7 uStack00000000000001b0;
  undefined1 uStack00000000000001b7;
  long in_stack_000001b8;
  ulong in_stack_000001c0;
  undefined8 in_stack_000001c8;
  undefined8 *in_stack_000001d0;
  long in_stack_000001d8;
  long in_stack_000001e0;
  long in_stack_000001e8;
  byte in_stack_00000238;
  undefined8 in_stack_00000248;
  byte in_stack_00000250;
  undefined8 in_stack_00000260;
  ulong in_stack_00000300;
  undefined8 in_stack_00000310;
  long *plVar67;
  long *plVar68;
  long *in_stack_00000338;
  long *plVar69;
  undefined8 in_stack_00000350;
  
  do {
    uVar32 = func_0x005c14c8(unaff_x19);
    if ((((uVar32 & 1) != 0) &&
        (iVar23 = (int)unaff_x19[unaff_x23 * 0x18e7 + 0x10727] + -1,
        0 < (int)unaff_x19[unaff_x23 * 0x18e7 + 0x10727])) &&
       (*(int *)(unaff_x19 + unaff_x23 * 0x18e7 + 0x10727) = iVar23, (unaff_w20 & iVar23 == 0) == 1)
       ) {
      uVar33 = func_0x0044c16c();
      func_0x0044e35c(uVar33,0x1c,0);
    }
    unaff_x23 = 1;
    bVar14 = unaff_w20 & 1;
    unaff_w20 = 0;
    if (bVar14 == 0) {
      do {
        if (0 < (int)unaff_x19[0x106dd]) {
          *(int *)(unaff_x19 + 0x106dd) = (int)unaff_x19[0x106dd] + -1;
        }
        lVar31 = 0x32;
        piVar52 = in_stack_00000028;
        do {
          if (0 < *piVar52) {
            *piVar52 = *piVar52 + -1;
          }
          if (0 < piVar52[3]) {
            piVar52[3] = piVar52[3] + -1;
          }
          lVar31 = lVar31 + -1;
          piVar52 = piVar52 + 6;
        } while (lVar31 != 0);
        func_0x005bbf4c(unaff_x19);
        func_0x005bc3b4(unaff_x19,in_stack_00000148);
        func_0x005bc54c(unaff_x19,in_stack_00000148);
        func_0x005bc6bc(unaff_x19,in_stack_00000148);
        func_0x005bc854(unaff_x19,in_stack_00000148);
        func_0x005bc9ec(unaff_x19,in_stack_00000148);
        func_0x005bcc2c(unaff_x19,in_stack_00000148);
        func_0x005bce6c(unaff_x19,in_stack_00000148);
        func_0x005bd09c(unaff_x19,in_stack_00000148);
        func_0x005aa700(unaff_x19 + 0x10e,in_stack_00000148);
        func_0x0063fdd4(&stack0x00000348,in_stack_00000350);
        func_0x0063fdd4(&stack0x00000330,in_stack_00000338);
        plVar38 = in_stack_00000338;
LAB_006c81ec:
        in_stack_00000068._4_4_ = in_stack_00000068._4_4_ + 1;
        if (in_stack_00000058[0x378] <= in_stack_00000068._4_4_) {
LAB_006cbfe0:
          func_0x005b69a4(unaff_x19);
          uVar53 = in_stack_000000c8[0x76];
          uVar19 = uVar53 + 1;
          in_stack_000000c8[0x78] = in_stack_000000c8[0x78] + 1;
          in_stack_000000c8[0x76] = uVar19;
          if (uVar19 == 3) {
            uVar25 = 1;
LAB_006cc038:
            *(undefined4 *)(in_stack_000000a8 + 0x1968) = uVar25;
          }
          else if (4 < (int)uVar53) {
            uVar25 = 0;
            in_stack_000000c8[0x76] = 0;
            goto LAB_006cc038;
          }
          if (*in_stack_000000a0 != 0) {
            if ((*in_stack_000000a0 != 1) ||
               (iVar23 = in_stack_000000a0[1], in_stack_000000a0[1] = iVar23 + 1,
               iVar23 + 1 != in_stack_000000a0[2])) goto LAB_006c7690;
            uVar33 = func_0x0044c16c();
            func_0x0044e014(uVar33,0xffffffff);
            if (in_stack_000000a0[3] != -1) {
              func_0x005b1674(in_stack_00000190 + 0x8d742,0,1);
            }
          }
          in_stack_000000a0[0] = 0;
          in_stack_000000a0[1] = 0;
          in_stack_000000a0[2] = 0;
          in_stack_000000a0[3] = -1;
          unaff_x19 = in_stack_00000190;
LAB_006c7690:
          *(float *)(in_stack_00000040 + 4) = *(float *)(in_stack_00000040 + 4) + 0.5;
          *(float *)(in_stack_00000040 + 0xc) = *(float *)(in_stack_00000040 + 0xc) + 0.5;
          *(int *)(in_stack_000000a8 + 0x1f84) = *(int *)(in_stack_000000a8 + 0x1f84) + 1;
          iVar23 = func_0x005ab154();
          if (iVar23 == 0) {
            func_0x005b1608(unaff_x19 + 0x8d742);
          }
          uVar32 = func_0x00685844(unaff_x19,*(undefined4 *)(in_stack_000000a8 + 8));
          if ((uVar32 & 1) == 0) {
LAB_006c7a20:
            plVar26 = (long *)0x0;
          }
          else {
            plVar26 = (long *)0x1;
            iVar23 = 0;
            if (1 < *(int *)(in_stack_000000a8 + 0x3ed8)) {
              iVar23 = *(int *)(in_stack_000000a8 + 0x3ed8) + -1;
            }
            *(int *)(in_stack_000000a8 + 0x3ed8) = iVar23;
          }
LAB_006c7a24:
          if (*(long *)(in_stack_000000b0 + 0x28) == *(long *)(unaff_x29 + -0x38)) {
            return;
          }
LAB_006cdcd8:
                    /* WARNING: Subroutine does not return */
          NoRet_0x00ac3380(plVar26);
        }
LAB_006c8204:
        iVar23 = func_0x005ab154();
        if ((iVar23 == 0) && (uVar32 = func_0x009d0178(unaff_x19[0xf8]), (uVar32 & 1) != 0)) {
          uVar25 = func_0x009d095c(unaff_x19[0xf8]);
          func_0x006347c4(unaff_x19 + 0xcd,uVar25);
        }
        uVar32 = unaff_x19[0x4e8] - unaff_x19[0x4e7];
        if ((uVar32 != 0) && (0 < (int)(uVar32 >> 3))) {
          uVar32 = uVar32 >> 3 & 0xffffffff;
          lVar40 = uVar32 * 8;
          unaff_x28 = (long *)(uVar32 + 1);
          lVar31 = uVar32 * -8;
          do {
            lVar40 = lVar40 + -8;
            lVar39 = unaff_x19[0x4e7] + lVar40;
            iVar23 = *(int *)(lVar39 + 4);
            if (iVar23 < 1) {
              iVar23 = *(int *)(unaff_x19[0x4e7] + lVar40);
              iVar24 = func_0x005abf04(0,iVar23);
              uVar15 = func_0x00a92ff4((long)unaff_x19 + (long)iVar24 * 8 + 0x47aac);
              in_stack_00000188 = (long *)((long)iVar23 * 4);
              *(int *)((long)in_stack_00000098 + (long)in_stack_00000188) =
                   *(int *)((long)in_stack_00000098 + (long)in_stack_00000188) + -1;
              uVar16 = func_0x005ab37c(0,iVar23);
              iVar24 = func_0x005ab37c(0,iVar23);
              iVar17 = func_0x005abf1c(0,iVar23);
              lVar39 = in_stack_00000090[(long)iVar24 * 0xec + (long)iVar17 * 0x3b + 7];
              iVar24 = func_0x005ab37c(0,iVar23);
              iVar17 = func_0x005abf1c(0,iVar23);
              uVar25 = *(undefined4 *)
                        ((long)in_stack_00000090 +
                        (long)iVar17 * 0x1d8 + (long)iVar24 * 0x760 + 0x3c);
              uVar18 = func_0x005abf1c(0,iVar23);
              func_0x009b6dec(unaff_x19,0,uVar16,uVar15,(int)lVar39,uVar25,uVar18,0);
              *(int *)((long)in_stack_00000098 + (long)in_stack_00000188) =
                   *(int *)((long)in_stack_00000098 + (long)in_stack_00000188) + 1;
              lVar39 = unaff_x19[0x4e7] + lVar40;
              lVar3 = lVar31 + (unaff_x19[0x4e8] - unaff_x19[0x4e7]);
              if (lVar39 + 8 != unaff_x19[0x4e8]) {
                func_0x00bc33e0(lVar39,lVar39 + 8,lVar3);
              }
              unaff_x19[0x4e8] = lVar39 + lVar3;
            }
            else {
              *(int *)(lVar39 + 4) = iVar23 + -1;
            }
            unaff_x28 = (long *)((long)unaff_x28 + -1);
            lVar31 = lVar31 + 8;
          } while ((long *)0x1 < unaff_x28);
        }
        iVar23 = 0;
        do {
          func_0x00a625c4(0,iVar23,0);  /* 0x9625c4:[slot*1000,team*0x1f0,team*51000|off=0x83ab4|str w20, [x8, x9]] */
          func_0x00a60660(0,iVar23,0);  /* 0x960660:[slot*1000,team*51000|off=0x83b14|str w19, [x8, x9]] */
          func_0x00a61848(0,iVar23,0);  /* 0x961848:[slot*1000,team*51000|off=0x83c04|str w19, [x8, x9]] */
          iVar23 = iVar23 + 1;
        } while (iVar23 != 0x33);
        iVar23 = 0;
        do {
          func_0x00a625c4(1,iVar23,0);  /* 0x9625c4:[slot*1000,team*0x1f0,team*51000|off=0x83ab4|str w20, [x8, x9]] */
          func_0x00a60660(1,iVar23,0);  /* 0x960660:[slot*1000,team*51000|off=0x83b14|str w19, [x8, x9]] */
          func_0x00a61848(1,iVar23,0);  /* 0x961848:[slot*1000,team*51000|off=0x83c04|str w19, [x8, x9]] */
          iVar23 = iVar23 + 1;
        } while (iVar23 != 0x33);
        iVar23 = func_0x005ab154();
        if (((iVar23 == 0) && (uVar32 = func_0x005d0ad4(unaff_x19), (uVar32 & 1) != 0)) &&
           ((int)unaff_x19[0x65a] != 0x7fffffff)) {
          iVar23 = (int)unaff_x19[0x65a] + 1;
          *(int *)(in_stack_00000190 + 0x65a) = iVar23;
          iVar24 = func_0x005aaca0();
          unaff_x19 = in_stack_00000190;
          if ((iVar24 <= iVar23) && (iVar23 = func_0x005ab154(), iVar23 != 4)) {
            uVar33 = func_0x0044c16c();
            func_0x0044e014(uVar33,0xffffffff);
            uVar33 = func_0x0044c16c();
            uVar32 = func_0x00999ab8(in_stack_00000190 + 0x80);
            uVar25 = 0xbd;
            if ((uVar32 & 1) == 0) {
              uVar25 = 0x39;
            }
            func_0x0044e35c(uVar33,uVar25,0);
            func_0x006ee0d0(in_stack_00000190 + 0x1c);
            uVar25 = *(undefined4 *)((long)in_stack_00000190 + 0x383744);
            in_stack_00000050[0x18] = 0;
            uVar33 = func_0x007a95b8(uVar25);
            iVar23 = func_0x009cd640(uVar33,(int)*in_stack_00000018,*in_stack_00000050,
                                     *(undefined4 *)((long)in_stack_00000190 + 0x38ff5c),0);
            func_0x00a0b124(0x1e,iVar23 < 1,0,0,0);
            uVar33 = func_0x007a95b8(*(undefined4 *)((long)in_stack_00000190 + 0x383744));
            func_0x009ce358(uVar33,(int)*in_stack_00000018,*in_stack_00000050,
                            *(undefined4 *)((long)in_stack_00000190 + 0x38ff5c),1,0);
            uVar33 = func_0x007a95b8(*(undefined4 *)((long)in_stack_00000190 + 0x383744));
            iVar23 = func_0x009cd640(uVar33,(int)*in_stack_00000018,*in_stack_00000050,
                                     *(undefined4 *)((long)in_stack_00000190 + 0x38ff5c),0);
            if (9999 < iVar23) {
              uVar33 = func_0x007a95b8(*(undefined4 *)((long)in_stack_00000190 + 0x383744));
              func_0x009cdc30(uVar33,(int)*in_stack_00000018,*in_stack_00000050,
                              *(undefined4 *)((long)in_stack_00000190 + 0x38ff5c),9999,0);
            }
            func_0x005cf794(in_stack_00000190);
            func_0x005ab174(4);
            iVar23 = func_0x007ac230(0);
            func_0x007d78f4(in_stack_00000190 + 0x65817,0,iVar23,1,0,0);
            func_0x007d78f4(in_stack_00000190 + 0x65817,1,*in_stack_00000050 + iVar23 * 100,1,0,0);
            func_0x007d78f4(in_stack_00000190 + 0x65817,9,iVar23 / 1000,1,0,0);
            func_0x007d78f4(in_stack_00000190 + 0x65817,0x15,*in_stack_00000050 + iVar23 * 100,
                            *(undefined4 *)((long)in_stack_00000190 + 0x32cc),0,0);
            iVar23 = func_0x007abd78(0);
            if (iVar23 == 4) {
              iVar23 = func_0x0095baa8(in_stack_00000190[0x42b],(int)*in_stack_00000018);
              if (iVar23 < *(int *)((long)in_stack_00000190 + 0x32cc)) {
LAB_006c8730:
                in_stack_00000050[0x17] = 1;
              }
            }
            else {
              uVar33 = func_0x00590bb8(in_stack_00000190 + 0x65b,in_stack_00000018);
              piVar52 = (int *)func_0x005cf538(uVar33,in_stack_00000050);
              iVar23 = *(int *)((long)in_stack_00000190 + 0x32cc);
              if (*piVar52 < iVar23) {
                uVar33 = func_0x00590bb8(in_stack_00000190 + 0x65b,in_stack_00000018);
                piVar52 = (int *)func_0x005cf538(uVar33,in_stack_00000050);
                *piVar52 = iVar23;
                goto LAB_006c8730;
              }
            }
            func_0x005d0b20(in_stack_00000190);
            func_0x00a50034(in_stack_00000190);
          }
        }
        else {
          iVar23 = func_0x005ab154();
          if ((iVar23 == 0) && (uVar32 = func_0x009d0178(unaff_x19[0xf8]), (uVar32 & 1) != 0)) {
            func_0x009d1f6c(unaff_x19[0xf8]);
            uVar32 = func_0x009d2228(unaff_x19[0xf8]);
            if (((uVar32 & 1) != 0) &&
               ((uVar32 = func_0x009d1f90(unaff_x19[0xf8]), (uVar32 & 1) != 0 &&
                (iVar23 = func_0x005ab154(), iVar23 == 0)))) {
              in_stack_00000050[0xf] = 0;
              in_stack_00000050[0x10] = 0;
              *(undefined8 *)(in_stack_000000a0 + 2) = in_stack_00000008;
              *(undefined8 *)in_stack_000000a0 = in_stack_00000000;
              BattleFn_0x004c9224(unaff_x19,0);
              func_0x005d0b20(unaff_x19);
            }
          }
        }
        in_stack_00000048[0xd] = (int)((float)in_stack_00000048[0xd] + unaff_s9);
        iVar23 = func_0x005ab154();
        if (iVar23 == 3) goto LAB_006c81ec;
        in_stack_00000050[1] = in_stack_00000050[1] + 1;
        iVar23 = func_0x005ab154();
        if (iVar23 == 0) {
          iVar23 = 30000;
          if (in_stack_00000050[0x1e] < 29999) {
            iVar23 = in_stack_00000050[0x1e] + 1;
          }
          in_stack_00000050[0x1e] = iVar23;
        }
        BattleFn_0x005dfef0(unaff_x19);
        BattleFn_0x004bd678(unaff_x19,in_stack_00000148);
        BattleFn_0x005dbc18(unaff_x19,in_stack_00000148,0);
        BattleFn_0x004bdba0(unaff_x19);
        uVar53 = 1;
        BattleFn_0x005dd600(unaff_x19,in_stack_00000148,1);
        uVar19 = 0;
        do {
          uVar32 = func_0x00a59560(1,uVar19);  /* 0x959560:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w8, [x8, x9]] */
          if (((uVar32 & 1) != 0) && (iVar23 = func_0x00a59a70(1,uVar19), iVar23 == 0)) break;  /* 0x959a70:[slot*1000,team*51000|off=0x83a0c|ldr w0, [x8, x9]] */
          bVar13 = uVar19 < 0x32;
          uVar19 = uVar19 + 1;
          uVar53 = (uint)bVar13;
        } while (uVar19 != 0x33);
        lVar31 = -0x32;
        lVar40 = 0x83cf0;
        do {
          if ((*(int *)((long)in_stack_00000190 + lVar40) != 0) &&
             (iVar23 = func_0x00a58ba4(0,(int)lVar31 + 0x33), iVar23 == 7)) {  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
            uVar53 = 1;
            break;
          }
          bVar13 = lVar31 != -1;
          lVar31 = lVar31 + 1;
          lVar40 = lVar40 + 1000;
        } while (bVar13);
        uVar25 = 0;
        bVar13 = true;
        do {
          bVar12 = bVar13;
          iVar23 = 1;
          do {
            iVar24 = func_0x00a58874(uVar25,iVar23);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            if (iVar24 != 0) {
              iVar24 = func_0x00a58ba4(uVar25,iVar23);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
              if ((iVar24 == 1) || (iVar24 = func_0x00a58ba4(uVar25,iVar23), iVar24 == 0)) {  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
                iVar24 = func_0x00a59d48(uVar25,iVar23);  /* 0x959d48:[slot*1000,team*51000|off=0x83adc|ldr w0, [x8, x9]] */
                if (iVar24 < 1) {
                  iVar24 = func_0x00a59c68(uVar25,iVar23);  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                  if (iVar24 == 0) {
                    BattleFn_0x005dd300(in_stack_00000190,uVar25,iVar23);
                  }
                }
                else {
                  func_0x00a59dd4(uVar25,iVar23,0xffffffff);  /* 0x959dd4:[slot*1000,team*51000|off=0x83adc|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                  iVar24 = func_0x00a59d48(uVar25,iVar23);  /* 0x959d48:[slot*1000,team*51000|off=0x83adc|ldr w0, [x8, x9]] */
                  if (iVar24 == 0) {
                    func_0x00a58be4(uVar25,iVar23,4);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                    func_0x00a590fc(uVar25,iVar23,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                  }
                }
                iVar24 = func_0x00a58ba4(uVar25,iVar23);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
                if ((iVar24 == 0) && (iVar24 = func_0x00a58d4c(uVar25,iVar23), iVar24 == 0)) {  /* 0x958d4c:[slot*1000,team*51000|off=0x83930|ldr w0, [x8, x9]] */
                  func_0x00a58be4(uVar25,iVar23,1);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                }
              }
              iVar24 = func_0x00a58ba4(uVar25,iVar23);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
              if (iVar24 == 0) {
                iVar24 = 0;
                do {
                  iVar17 = func_0x006ce084(in_stack_00000190,uVar25,iVar23,iVar24,0);
                  if (iVar17 != 0) {
                    if ((((iVar24 == 0) ||
                         (uVar32 = func_0x00a5b960(uVar25,iVar23), (uVar32 & 1) == 0)) ||  /* 0x95b960:[slot*1000,team*0x1f0,team*51000|off=0x839c4|ldr w8, [x8, x9]] */
                        (iVar24 = func_0x00a61e14(uVar25,iVar23), iVar24 == 0)) ||  /* 0x961e14:[slot*1000,team*0x1f0,team*51000|off=0x83a8c|ldr w0, [x8, x9]] */
                       ((uVar53 != 0 && (uVar32 = func_0x00a59560(1,iVar23), (uVar32 & 1) != 0)))) {  /* 0x959560:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w8, [x8, x9]] */
                      func_0x00a58be4(uVar25,iVar23,1);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                      func_0x00a590fc(uVar25,iVar23,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                    }
                    else {
                      iVar24 = func_0x00a61e14(uVar25,iVar23);  /* 0x961e14:[slot*1000,team*0x1f0,team*51000|off=0x83a8c|ldr w0, [x8, x9]] */
                      if (0 < iVar24) {
                        func_0x00a61ee8(uVar25,iVar23,0xffffffff);  /* 0x961ee8:[slot*1000,team*0x1f0,team*51000|off=0x83a8c,0x83a8c|ldr w22, [x8, x9] ; str w20, [x8, x9]] */
                      }
                      func_0x00a58be4(uVar25,iVar23,0xb);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                      func_0x00a590fc(uVar25,iVar23,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                      uVar15 = func_0x00a5919c(uVar25,iVar23);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                      func_0x00a624e8(uVar25,iVar23,uVar15);  /* 0x9624e8:[slot*1000,team*0x1f0,team*51000|off=0x83a90|str w19, [x8, x9]] */
                    }
                    break;
                  }
                  iVar24 = iVar24 + 1;
                } while (iVar24 != 0x33);
              }
              else {
                iVar24 = func_0x00a58ba4(uVar25,iVar23);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
                if ((iVar24 == 0xc) &&
                   (iVar24 = func_0x006ce084(in_stack_00000190,uVar25,iVar23,0,0), iVar24 != 0)) {
                  func_0x00a58be4(uVar25,iVar23,0xd);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                  func_0x00a590fc(uVar25,iVar23,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                  break;
                }
              }
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 0x33);
          uVar25 = 1;
          bVar13 = false;
        } while (bVar12);
        if (*(int *)(in_stack_00000040 + 0x218) == 1) {
          *(undefined4 *)(in_stack_00000040 + 0x218) = 0;
        }
        puVar51 = (undefined4 *)0x1;
        in_stack_00000188 = (long *)CONCAT44(in_stack_00000188._4_4_,uVar53);
        do {
          if ((int)in_stack_000000d8[(long)puVar51 * 0x7d] != 0) {
            if ((*(int *)((long)in_stack_000000d8 + (long)puVar51 * 1000 + 4) == 1) &&
               (*(int *)((long)in_stack_000000d8 + (long)puVar51 * 1000 + 0xf4) < 1)) {
              func_0x009b95b4(in_stack_00000190,in_stack_00000148,0,(ulong)puVar51 & 0xffffffff);
              uVar32 = func_0x00a5c5f4(0,(ulong)puVar51 & 0xffffffff);  /* 0x95c5f4:[slot*1000,team*0x1f0,team*51000|off=0x839ec|ldr w8, [x8, x9]] */
              if ((uVar32 & 1) == 0) {
                iVar23 = 0;
                bVar13 = false;
                do {
                  iVar24 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,iVar23,0)
                  ;
                  if (iVar24 != 0) {
                    uVar33 = func_0x00a597f0(0,(ulong)puVar51 & 0xffffffff);  /* 0x9597f0:[slot*1000,team*51000|off=0x83950|ldr w0, [x8, x9]] */
                    if (((int)uVar33 == 0) &&
                       (iVar24 = func_0x00a59c68(uVar33,(ulong)puVar51 & 0xffffffff), iVar24 != 0))  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                    goto LAB_006c911c;
                    bVar13 = true;
                  }
                  iVar23 = iVar23 + 1;
                } while (iVar23 != 0x33);
                if (!bVar13) {
                  iVar23 = func_0x00a58d4c(0,(ulong)puVar51 & 0xffffffff);  /* 0x958d4c:[slot*1000,team*51000|off=0x83930|ldr w0, [x8, x9]] */
                  uVar33 = 0;
                  if (0 < iVar23) goto LAB_006c9120;
                }
              }
              else {
                func_0x00a5ac18(0,(ulong)puVar51 & 0xffffffff,0);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                iVar23 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,0,0);
                if (iVar23 == 0) {
                  bVar13 = false;
LAB_006c9050:
                  iVar23 = 1;
                  do {
                    uVar32 = func_0x00a5ac18(0,(ulong)puVar51 & 0xffffffff,iVar23);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                    if ((((uVar32 & 1) != 0) || (iVar24 = func_0x005aad10(), iVar23 == iVar24)) &&
                       (iVar24 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,
                                                 iVar23,0), iVar24 != 0)) {
                      uVar33 = func_0x00a597f0(0,(ulong)puVar51 & 0xffffffff);  /* 0x9597f0:[slot*1000,team*51000|off=0x83950|ldr w0, [x8, x9]] */
                      if (((int)uVar33 == 0) &&
                         (iVar24 = func_0x00a59c68(uVar33,(ulong)puVar51 & 0xffffffff), iVar24 != 0)  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                         ) goto LAB_006c911c;
                      bVar13 = true;
                    }
                    iVar23 = iVar23 + 1;
                  } while (iVar23 != 0x33);
                  if (bVar13) goto LAB_006c8b4c;
                  iVar23 = 0;
                  do {
                    iVar24 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,iVar23,
                                             0);
                    if (iVar24 != 0) goto LAB_006c8b4c;
                    iVar23 = iVar23 + 1;
                  } while (iVar23 != 0x33);
                  uVar33 = 0;
                }
                else {
                  uVar33 = func_0x00a597f0(0,(ulong)puVar51 & 0xffffffff);  /* 0x9597f0:[slot*1000,team*51000|off=0x83950|ldr w0, [x8, x9]] */
                  if (((int)uVar33 != 0) ||
                     (iVar23 = func_0x00a59c68(uVar33,(ulong)puVar51 & 0xffffffff), iVar23 == 0)) {  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                    bVar13 = true;
                    goto LAB_006c9050;
                  }
LAB_006c911c:
                  uVar33 = 2;
                }
LAB_006c9120:
                func_0x00a58be4(0,(ulong)puVar51 & 0xffffffff,uVar33);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                func_0x00a590fc(0,(ulong)puVar51 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
              }
            }
LAB_006c8b4c:
            iVar23 = func_0x00a58ba4(0,(ulong)puVar51 & 0xffffffff);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
            if ((iVar23 == 2) &&
               (iVar23 = func_0x00a608a8(0,(ulong)puVar51 & 0xffffffff), iVar23 < 1)) {  /* 0x9608a8:[slot*1000,team*51000|off=0x839fc|ldr w0, [x8, x9]] */
              func_0x009b95b4(in_stack_00000190,in_stack_00000148,0,(ulong)puVar51 & 0xffffffff);
              uVar33 = func_0x00a590bc(0,(ulong)puVar51 & 0xffffffff);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
              if ((int)uVar33 == 0) {
                iVar23 = func_0x00a59c68(uVar33,(ulong)puVar51 & 0xffffffff);  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                if (iVar23 == 0) {
                  BattleFn_0x005dd300(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff);
                }
                else {
                  func_0x00a58be4(0,(ulong)puVar51 & 0xffffffff,1);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                }
              }
              else {
                iVar23 = func_0x00a5a494(0,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                if (0 < iVar23) {
                  iVar23 = 1;
LAB_006c8bb4:
                  piVar52 = (int *)(ulong)(iVar23 - 1);
                  iVar24 = func_0x00a590bc(0,(ulong)puVar51 & 0xffffffff);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
                  iVar17 = func_0x00a5a540(0,(ulong)puVar51 & 0xffffffff,piVar52);  /* 0x95a540:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
                  if (iVar24 != iVar17) goto code_r0x006c8be0;
                  iVar24 = func_0x00a5a494(0,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                  if (iVar24 == iVar23) {
                    uVar25 = func_0x00a5a59c(0,(ulong)puVar51 & 0xffffffff);  /* 0x95a59c:[slot*1000,team*51000|off=0x83938|ldr w0, [x8, x9]] */
                    func_0x00a59830(0,(ulong)puVar51 & 0xffffffff,uVar25);  /* 0x959830:[slot*1000,team*51000|off=0x83950|str w19, [x8, x9]] */
                    iVar23 = func_0x00a59c68(0,(ulong)puVar51 & 0xffffffff);  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                    if (0 < iVar23) {
                      func_0x00a59cf4(0,(ulong)puVar51 & 0xffffffff,0xffffffff);  /* 0x959cf4:[slot*1000,team*51000|off=0x83ad4|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                    }
                  }
                  in_stack_00000170[0x67] = 0;
                  iVar23 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,0,piVar52
                                          );
                  if (iVar23 != 0) {
                    uVar32 = func_0x00a5c5f4(0,(ulong)puVar51 & 0xffffffff);  /* 0x95c5f4:[slot*1000,team*0x1f0,team*51000|off=0x839ec|ldr w8, [x8, x9]] */
                    if ((uVar32 & 1) != 0) {
                      func_0x00a5ac18(0,(ulong)puVar51 & 0xffffffff,0);  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                    }
                    iVar23 = *in_stack_000000b8;
                    *(undefined4 *)(in_stack_00000190 + (long)in_stack_00000170[0x67] + 0x51795) = 0
                    ;
                    iVar24 = in_stack_00000170[0x67];
                    *(int *)((long)in_stack_00000190 + (long)iVar24 * 8 + 0x28bcac) =
                         iVar23 - in_stack_000000b8[0xb];
                    in_stack_00000170[0x67] = iVar24 + 1;
                  }
                  uVar32 = 1;
                  piVar50 = in_stack_00000020;
                  do {
                    iVar23 = func_0x006ce084(in_stack_00000190,0,(ulong)puVar51 & 0xffffffff,
                                             uVar32 & 0xffffffff,piVar52);
                    if ((iVar23 != 0) &&
                       (((uVar30 = func_0x00a5c5f4(0,(ulong)puVar51 & 0xffffffff), (uVar30 & 1) == 0  /* 0x95c5f4:[slot*1000,team*0x1f0,team*51000|off=0x839ec|ldr w8, [x8, x9]] */
                         || (uVar30 = func_0x00a5ac18(0,(ulong)puVar51 & 0xffffffff,  /* 0x95ac18:[slot*1000,team*0x1f0,team*51000|off=0x83b60,0x83b64,0x83948,0x8394c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                                                      uVar32 & 0xffffffff), (uVar30 & 1) != 0)) ||
                        (uVar30 = func_0x005aad10(), uVar32 == (uVar30 & 0xffffffff))))) {
                      *(int *)(in_stack_00000190 + (long)in_stack_00000170[0x67] + 0x51795) =
                           (int)uVar32;
                      iVar17 = in_stack_00000170[0x67];
                      iVar23 = *piVar50;
                      iVar24 = piVar50[0xb];
                      in_stack_00000170[0x67] = iVar17 + 1;
                      *(int *)((long)in_stack_00000190 + (long)(&UNK_0028bcac + (long)iVar17 * 8)) =  /* UNK_28bcac(vma=0x18bcac)='tMessage' */
                           iVar23 - iVar24;
                    }
                    uVar32 = uVar32 + 1;
                    piVar50 = piVar50 + 0xfa;
                  } while (uVar32 != 0x33);
                  if (in_stack_00000170[0x67] < 1) goto LAB_006c8afc;
                  plVar26 = (long *)func_0x00a5c2e8(0,(ulong)puVar51 & 0xffffffff);  /* 0x95c2e8:[slot*1000,team*51000|off=0x83958|ldr w8, [x8, x9]] */
                  if (((ulong)plVar26 & 1) != 0) {
                    plVar38 = (long *)0x0;
                    plVar28 = (long *)0x0;
                    plVar69 = (long *)0x0;
                    if (in_stack_00000170[0x67] < 1) {
                      lVar31 = 0;
                      goto LAB_006c92ac;
                    }
                    plVar55 = (long *)0x0;
                    piVar50 = (int *)0x0;
                    plVar49 = (long *)0x0;
                    plVar68 = plVar28;
                    in_stack_00000338 = plVar38;
                    do {
                      plVar48 = plVar49;
                      if (plVar55 <= in_stack_00000338) {
                        lVar31 = (long)in_stack_00000338 - (long)plVar49;
                        plVar67 = (long *)(lVar31 >> 2);
                        puVar2 = (undefined1 *)((long)plVar67 + 1);
                        if ((ulong)puVar2 >> 0x3e != 0) goto LAB_006ccc30;
                        puVar41 = (undefined1 *)((long)plVar55 - (long)plVar49 >> 1);
                        if (puVar41 <= puVar2) {
                          puVar41 = puVar2;
                        }
                        if (0x7ffffffffffffffb < (ulong)((long)plVar55 - (long)plVar49)) {
                          puVar41 = (undefined1 *)0x3fffffffffffffff;
                        }
                        if (puVar41 == (undefined1 *)0x0) {
                          plVar26 = (long *)0x0;
LAB_006c8f54:
                          plVar28 = (long *)((long)plVar26 + (long)plVar67 * 4);
                          plVar38 = (long *)((long)plVar28 + 4);
                          *(int *)plVar28 = (int)in_stack_00000190[(long)piVar50 + 0x51795];
                          plVar48 = plVar28;
                          if ((long)in_stack_00000338 - (long)plVar49 != 0) {
                            uVar32 = ((long)in_stack_00000338 - (long)plVar49) - 4;
                            if (0xab < uVar32) {
                              piVar45 = (int *)((long)in_stack_00000338 + -4);
                              uVar27 = (long)plVar26 + lVar31 + -4;
                              uVar30 = (long)piVar45 - (long)plVar49 & 0xfffffffffffffffc;
                              if (((uVar27 - uVar30 <= uVar27) &&
                                  ((int *)((long)piVar45 - uVar30) <= piVar45)) &&
                                 ((undefined1 *)0x1f <
                                  (undefined1 *)
                                  ((long)in_stack_00000338 + (-lVar31 - (long)plVar26)))) {
                                uVar32 = (uVar32 >> 2) + 1;
                                uVar27 = uVar32 & 0x7ffffffffffffff8;
                                plVar48 = (long *)((long)plVar28 + uVar27 * -4);
                                plVar28 = plVar28 + -2;
                                plVar69 = in_stack_00000338 + -2;
                                uVar30 = uVar27;
                                do {
                                  plVar55 = plVar69 + -1;
                                  lVar39 = plVar69[-2];
                                  lVar40 = plVar69[1];
                                  lVar31 = *plVar69;
                                  uVar30 = uVar30 - 8;
                                  plVar69 = plVar69 + -4;
                                  plVar28[-1] = *plVar55;
                                  plVar28[-2] = lVar39;
                                  plVar28[1] = lVar40;
                                  *plVar28 = lVar31;
                                  plVar28 = plVar28 + -4;
                                } while (uVar30 != 0);
                                in_stack_00000338 = (long *)((long)in_stack_00000338 + uVar27 * -4);
                                plVar28 = plVar48;
                                if (uVar32 == uVar27) goto LAB_006c8fa0;
                              }
                            }
                            do {
                              in_stack_00000338 = (long *)((long)in_stack_00000338 + -4);
                              plVar48 = (long *)((long)plVar28 + -4);
                              *(int *)plVar48 = *(int *)in_stack_00000338;
                              plVar28 = plVar48;
                            } while (in_stack_00000338 != plVar49);
                          }
LAB_006c8fa0:
                          plVar55 = (long *)((long)plVar26 + (long)puVar41 * 4);
                          unaff_x28 = plVar38;
                          plVar28 = plVar48;
                          plVar69 = plVar55;
                          if (plVar49 != (long *)0x0) {
                            plVar26 = (long *)func_0x00bc3350(plVar49);
                          }
                          goto LAB_006c8ec8;
                        }
                        plVar28 = plVar67;
                        plVar38 = in_stack_00000338;
                        if ((ulong)puVar41 >> 0x3e == 0) {
                          plVar26 = (long *)func_0x00bc3330((long)puVar41 << 2);
                          goto LAB_006c8f54;
                        }
                        goto LAB_006ccc4c;
                      }
                      plVar38 = (long *)((long)in_stack_00000338 + 4);
                      *(int *)in_stack_00000338 = (int)in_stack_00000190[(long)piVar50 + 0x51795];
                      plVar28 = plVar68;
LAB_006c8ec8:
                      piVar50 = (int *)((long)piVar50 + 1);
                      plVar49 = plVar48;
                      plVar68 = plVar28;
                      in_stack_00000338 = plVar38;
                    } while ((long)piVar50 < (long)in_stack_00000170[0x67]);
                    lVar31 = 0;
                    lVar40 = (long)plVar38 - (long)plVar28;
                    if (lVar40 == 0) {
LAB_006c92ac:
                      func_0x006d9d6c(in_stack_00000190,(ulong)puVar51 & 0xffffffff,&stack0x00000208
                                      ,piVar52);
                      if (lVar31 != 0) {
                        func_0x00bc3350();
                      }
                      if (plVar28 == (long *)0x0) goto LAB_006c8afc;
                      goto LAB_006c9354;
                    }
                    if (-1 < lVar40) {
                      lVar31 = func_0x00bc3330(lVar40);
                      func_0x00bc35f0(lVar31,plVar28,lVar40);
                      goto LAB_006c92ac;
                    }
                    if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
                    goto LAB_006cdcd8;
                    func_0x00441cdc(&stack0x00000208);
                    plVar67 = plVar28;
                    goto LAB_006ccce4;
                  }
                  uVar19 = in_stack_00000170[0x67];
                  uVar32 = (ulong)uVar19;
                  in_stack_00000080[3] = 0;
                  in_stack_00000080[2] = 0;
                  in_stack_00000080[5] = 0;
                  in_stack_00000080[4] = 0;
                  in_stack_00000080[1] = 0;
                  *in_stack_00000080 = 0;
                  if (1 < (int)uVar19) {
                    uVar30 = 1;
                    piVar50 = in_stack_00000060;
                    uVar27 = 0;
                    do {
                      uVar42 = uVar27 + 1;
                      iVar23 = *(int *)((long)in_stack_00000190 + uVar27 * 8 + 0x28bcac);
                      if ((long)uVar42 < (long)(int)uVar32) {
                        uVar43 = uVar27 & 0xffffffff;
                        piVar45 = piVar50;
                        uVar44 = uVar30;
                        iVar24 = iVar23;
                        do {
                          iVar17 = *piVar45;
                          uVar19 = (uint)uVar44;
                          if (iVar17 <= iVar24) {
                            uVar19 = (uint)uVar43;
                          }
                          uVar43 = (ulong)uVar19;
                          uVar44 = uVar44 + 1;
                          if (iVar17 <= iVar24) {
                            iVar17 = iVar24;
                          }
                          piVar45 = piVar45 + 2;
                          iVar24 = iVar17;
                        } while ((uVar32 & 0xffffffff) != uVar44);
                      }
                      else {
                        uVar43 = uVar27 & 0xffffffff;
                      }
                      uVar32 = -(uVar43 >> 0x1f) & 0xfffffff800000000 | uVar43 << 3;
                      uVar30 = uVar30 + 1;
                      in_stack_00000170[0x66] = iVar23;
                      piVar50 = piVar50 + 2;
                      in_stack_00000170[0x65] = (int)in_stack_00000190[uVar27 + 0x51795];
                      in_stack_00000190[uVar27 + 0x51795] =
                           *(long *)((long)in_stack_00000190 + (long)(&UNK_0028bca8 + uVar32));  /* UNK_28bca8(vma=0x18bca8)='limitMessage' */
                      *(long *)((long)in_stack_00000190 + (long)(&UNK_0028bca8 + uVar32)) =  /* UNK_28bca8(vma=0x18bca8)='limitMessage' */
                           *in_stack_00000078;
                      uVar19 = in_stack_00000170[0x67];
                      uVar32 = (ulong)(int)uVar19;
                      uVar27 = uVar42;
                    } while ((long)uVar42 < (long)(uVar32 - 1));
                  }
                  if ((int)uVar19 < 1) {
                    uVar32 = 0;
                  }
                  else {
                    uVar30 = 0;
                    piVar50 = in_stack_00000170;
                    do {
                      uVar32 = uVar30;
                      if (*piVar50 != *in_stack_00000170) break;
                      uVar30 = uVar30 + 1;
                      uVar32 = (ulong)uVar19;
                      piVar50 = piVar50 + 2;
                    } while (uVar19 != uVar30);
                  }
                  iVar23 = func_0x0043ea60(uVar32);
                  plVar28 = (long *)func_0x00bc3330(4);
                  *(int *)plVar28 = (int)in_stack_00000190[(long)iVar23 + 0x51795];
                  piVar50 = (int *)func_0x00bc3330(4);
                  *piVar50 = (int)*plVar28;
                  func_0x006d9d6c(in_stack_00000190,(ulong)puVar51 & 0xffffffff,&stack0x00000220,
                                  piVar52);
                  if (piVar50 != (int *)0x0) {
                    func_0x00bc3350();
                  }
LAB_006c9354:
                  func_0x00bc3350(plVar28);
                }
              }
            }
          }
LAB_006c8afc:
          puVar51 = (undefined4 *)((long)puVar51 + 1);
        } while (puVar51 != (undefined4 *)0x33);
        puVar51 = (undefined4 *)0x1;
        in_stack_00000338 = plVar38;
LAB_006c9394:
        if ((int)in_stack_00000190[(long)puVar51 * 0x7d + 0x12008] != 0) {
          uVar33 = func_0x00a58ba4(1,(ulong)puVar51 & 0xffffffff);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
          if (((int)uVar33 == 1) &&
             (iVar23 = func_0x00a608a8(uVar33,(ulong)puVar51 & 0xffffffff), iVar23 < 1)) {  /* 0x9608a8:[slot*1000,team*51000|off=0x839fc|ldr w0, [x8, x9]] */
            func_0x009b95b4(in_stack_00000190,in_stack_00000148,1,(ulong)puVar51 & 0xffffffff);
            iVar23 = func_0x006ce084(in_stack_00000190,1,(ulong)puVar51 & 0xffffffff,0,0);
            if (iVar23 == 0) {
              bVar13 = false;
LAB_006c9988:
              iVar23 = 1;
              do {
                iVar24 = func_0x006ce084(in_stack_00000190,1,(ulong)puVar51 & 0xffffffff,iVar23,0);
                if (iVar24 != 0) {
                  uVar32 = func_0x00a5b960(1,(ulong)puVar51 & 0xffffffff);  /* 0x95b960:[slot*1000,team*0x1f0,team*51000|off=0x839c4|ldr w8, [x8, x9]] */
                  if ((((uVar32 & 1) != 0) &&
                      (iVar24 = func_0x00a61e14(1,(ulong)puVar51 & 0xffffffff), iVar24 != 0)) &&  /* 0x961e14:[slot*1000,team*0x1f0,team*51000|off=0x83a8c|ldr w0, [x8, x9]] */
                     ((uVar53 == 0 ||
                      (uVar32 = func_0x00a59560(1,(ulong)puVar51 & 0xffffffff), (uVar32 & 1) == 0)))  /* 0x959560:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w8, [x8, x9]] */
                     ) {
                    iVar23 = func_0x00a61e14(1,(ulong)puVar51 & 0xffffffff);  /* 0x961e14:[slot*1000,team*0x1f0,team*51000|off=0x83a8c|ldr w0, [x8, x9]] */
                    if (0 < iVar23) {
                      func_0x00a61ee8(1,(ulong)puVar51 & 0xffffffff,0xffffffff);  /* 0x961ee8:[slot*1000,team*0x1f0,team*51000|off=0x83a8c,0x83a8c|ldr w22, [x8, x9] ; str w20, [x8, x9]] */
                    }
                    func_0x00a58be4(1,(ulong)puVar51 & 0xffffffff,0xb);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                    func_0x00a590fc(1,(ulong)puVar51 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                    uVar25 = func_0x00a5919c(1,(ulong)puVar51 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                    func_0x00a624e8(1,(ulong)puVar51 & 0xffffffff,uVar25);  /* 0x9624e8:[slot*1000,team*0x1f0,team*51000|off=0x83a90|str w19, [x8, x9]] */
                    goto LAB_006c93d0;
                  }
                  bVar13 = true;
                  iVar24 = func_0x00a597f0(1,(ulong)puVar51 & 0xffffffff);  /* 0x9597f0:[slot*1000,team*51000|off=0x83950|ldr w0, [x8, x9]] */
                  if ((iVar24 == 0) &&
                     (iVar24 = func_0x00a59c68(1,(ulong)puVar51 & 0xffffffff), iVar24 != 0))  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
                  goto LAB_006c9a14;
                }
                iVar23 = iVar23 + 1;
              } while (iVar23 != 0x33);
              if ((bVar13) || (iVar23 = func_0x00a58d4c(1,(ulong)puVar51 & 0xffffffff), iVar23 < 1))  /* 0x958d4c:[slot*1000,team*51000|off=0x83930|ldr w0, [x8, x9]] */
              goto LAB_006c93d0;
              uVar33 = 0;
            }
            else {
              bVar13 = true;
              iVar23 = func_0x00a597f0(1,(ulong)puVar51 & 0xffffffff);  /* 0x9597f0:[slot*1000,team*51000|off=0x83950|ldr w0, [x8, x9]] */
              if ((iVar23 != 0) ||
                 (iVar23 = func_0x00a59c68(1,(ulong)puVar51 & 0xffffffff), iVar23 == 0))  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
              goto LAB_006c9988;
LAB_006c9a14:
              uVar33 = 2;
            }
            func_0x00a58be4(1,(ulong)puVar51 & 0xffffffff,uVar33);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            func_0x00a590fc(1,(ulong)puVar51 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
          }
LAB_006c93d0:
          iVar23 = func_0x00a58ba4(1,(ulong)puVar51 & 0xffffffff);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
          if ((iVar23 != 2) || (iVar23 = func_0x00a608a8(1,(ulong)puVar51 & 0xffffffff), 0 < iVar23)  /* 0x9608a8:[slot*1000,team*51000|off=0x839fc|ldr w0, [x8, x9]] */
             ) goto LAB_006c9388;
          func_0x009b95b4(in_stack_00000190,in_stack_00000148,1,(ulong)puVar51 & 0xffffffff);
          iVar23 = func_0x00a590bc(1,(ulong)puVar51 & 0xffffffff);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          if (iVar23 == 0) {
            iVar23 = func_0x00a59c68(1,(ulong)puVar51 & 0xffffffff);  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
            if (iVar23 == 0) {
              BattleFn_0x005dd300(in_stack_00000190,1,(ulong)puVar51 & 0xffffffff);
            }
            else {
              func_0x00a58be4(1,(ulong)puVar51 & 0xffffffff,1);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            }
            goto LAB_006c9388;
          }
          iVar23 = func_0x00a5a494(1,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          if (iVar23 < 1) goto LAB_006c9388;
          piVar52 = (int *)0x0;
LAB_006c9458:
          iVar23 = func_0x00a590bc(1,(ulong)puVar51 & 0xffffffff);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          iVar24 = func_0x00a5a540(1,(ulong)puVar51 & 0xffffffff,piVar52);  /* 0x95a540:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
          if (iVar23 != iVar24) goto LAB_006c9440;
          iVar23 = func_0x00a5a494(1,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          if ((int)piVar52 == iVar23 + -1) {
            uVar25 = func_0x00a5a59c(1,(ulong)puVar51 & 0xffffffff);  /* 0x95a59c:[slot*1000,team*51000|off=0x83938|ldr w0, [x8, x9]] */
            func_0x00a59830(1,(ulong)puVar51 & 0xffffffff,uVar25);  /* 0x959830:[slot*1000,team*51000|off=0x83950|str w19, [x8, x9]] */
            iVar23 = func_0x00a59c68(1,(ulong)puVar51 & 0xffffffff);  /* 0x959c68:[slot*1000,team*51000|off=0x83ad4|ldr w0, [x8, x9]] */
            if (0 < iVar23) {
              func_0x00a59cf4(1,(ulong)puVar51 & 0xffffffff,0xffffffff);  /* 0x959cf4:[slot*1000,team*51000|off=0x83ad4|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
            }
          }
          uVar32 = 0;
          in_stack_00000170[0x67] = 0;
          plVar49 = in_stack_000000c0;
          do {
            iVar23 = func_0x006ce084(in_stack_00000190,1,(ulong)puVar51 & 0xffffffff,
                                     uVar32 & 0xffffffff,piVar52);
            if (iVar23 != 0) {
              *(int *)(in_stack_00000190 + (long)in_stack_00000170[0x67] + 0x51795) = (int)uVar32;
              iVar24 = in_stack_00000170[0x67];
              iVar23 = *(int *)((long)plVar49 + -0x2c);
              lVar31 = *plVar49;
              in_stack_00000170[0x67] = iVar24 + 1;
              *(int *)((long)in_stack_00000190 + (long)(&UNK_0028bcac + (long)iVar24 * 8)) =  /* UNK_28bcac(vma=0x18bcac)='tMessage' */
                   (int)lVar31 + iVar23;
            }
            uVar32 = uVar32 + 1;
            plVar49 = plVar49 + 0x7d;
          } while (uVar32 != 0x33);
          if (in_stack_00000170[0x67] < 1) goto LAB_006c9440;
          plVar26 = (long *)func_0x00a5c2e8(1,(ulong)puVar51 & 0xffffffff);  /* 0x95c2e8:[slot*1000,team*51000|off=0x83958|ldr w8, [x8, x9]] */
          if (((ulong)plVar26 & 1) == 0) {
            uVar19 = in_stack_00000170[0x67];
            uVar32 = (ulong)uVar19;
            in_stack_00000080[3] = 0;
            in_stack_00000080[2] = 0;
            in_stack_00000080[5] = 0;
            in_stack_00000080[4] = 0;
            in_stack_00000080[1] = 0;
            *in_stack_00000080 = 0;
            if (1 < (int)uVar19) {
              uVar30 = 1;
              piVar50 = in_stack_00000060;
              uVar27 = 0;
              do {
                uVar42 = uVar27 + 1;
                iVar23 = *(int *)((long)in_stack_00000190 + uVar27 * 8 + 0x28bcac);
                if ((long)uVar42 < (long)(int)uVar32) {
                  uVar43 = uVar27 & 0xffffffff;
                  piVar45 = piVar50;
                  uVar44 = uVar30;
                  iVar24 = iVar23;
                  do {
                    iVar17 = *piVar45;
                    uVar19 = (uint)uVar44;
                    if (iVar24 <= iVar17) {
                      uVar19 = (uint)uVar43;
                    }
                    uVar43 = (ulong)uVar19;
                    uVar44 = uVar44 + 1;
                    if (iVar24 <= iVar17) {
                      iVar17 = iVar24;
                    }
                    piVar45 = piVar45 + 2;
                    iVar24 = iVar17;
                  } while ((uVar32 & 0xffffffff) != uVar44);
                }
                else {
                  uVar43 = uVar27 & 0xffffffff;
                }
                uVar32 = -(uVar43 >> 0x1f) & 0xfffffff800000000 | uVar43 << 3;
                uVar30 = uVar30 + 1;
                in_stack_00000170[0x66] = iVar23;
                piVar50 = piVar50 + 2;
                in_stack_00000170[0x65] = (int)in_stack_00000190[uVar27 + 0x51795];
                in_stack_00000190[uVar27 + 0x51795] =
                     *(long *)((long)in_stack_00000190 + (long)(&UNK_0028bca8 + uVar32));  /* UNK_28bca8(vma=0x18bca8)='limitMessage' */
                *(long *)((long)in_stack_00000190 + (long)(&UNK_0028bca8 + uVar32)) =  /* UNK_28bca8(vma=0x18bca8)='limitMessage' */
                     *in_stack_00000078;
                uVar19 = in_stack_00000170[0x67];
                uVar32 = (ulong)(int)uVar19;
                uVar27 = uVar42;
              } while ((long)uVar42 < (long)(uVar32 - 1));
            }
            if ((int)uVar19 < 1) {
              uVar32 = 0;
            }
            else {
              uVar30 = 0;
              piVar50 = in_stack_00000170;
              do {
                uVar32 = uVar30;
                if (*piVar50 != *in_stack_00000170) break;
                uVar30 = uVar30 + 1;
                uVar32 = (ulong)uVar19;
                piVar50 = piVar50 + 2;
              } while (uVar19 != uVar30);
            }
            iVar23 = func_0x0043ea60(uVar32);
            plVar67 = (long *)func_0x00bc3330(4);
            *(int *)plVar67 = (int)in_stack_00000190[(long)iVar23 + 0x51795];
            piVar50 = (int *)func_0x00bc3330(4);
            *piVar50 = (int)*plVar67;
            func_0x006daa58(in_stack_00000190,(ulong)puVar51 & 0xffffffff,&stack0x000001f0,piVar52);
            if (piVar50 != (int *)0x0) {
              func_0x00bc3350();
            }
LAB_006c9438:
            func_0x00bc3350(plVar67);
            goto LAB_006c9440;
          }
          in_stack_00000338 = (long *)0x0;
          plVar67 = (long *)0x0;
          plVar69 = (long *)0x0;
          if (in_stack_00000170[0x67] < 1) {
            in_stack_000001d8 = 0;
            in_stack_000001e0 = 0;
            in_stack_000001e8 = 0;
LAB_006c9888:
            func_0x006daa58(in_stack_00000190,(ulong)puVar51 & 0xffffffff,&stack0x000001d8,piVar52);
            if (in_stack_000001d8 != 0) {
              in_stack_000001e0 = in_stack_000001d8;
              func_0x00bc3350();
            }
            if (plVar67 == (long *)0x0) goto LAB_006c9440;
            goto LAB_006c9438;
          }
          plVar55 = (long *)0x0;
          piVar50 = (int *)0x0;
          plVar28 = (long *)0x0;
          plVar38 = in_stack_00000338;
          do {
            unaff_x28 = in_stack_00000190 + (long)piVar50;
            if (plVar38 < plVar55) {
              in_stack_00000338 = (long *)((long)plVar38 + 4);
              *(int *)plVar38 = (int)unaff_x28[0x51795];
              plVar38 = plVar28;
            }
            else {
              plVar48 = (long *)((long)plVar38 - (long)plVar28);
              uVar32 = ((long)plVar48 >> 2) + 1;
              if (uVar32 >> 0x3e != 0) {
                if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
                goto LAB_006cdcd8;
                func_0x00441cdc(&stack0x00000330);
                func_0x0040cb78(&stack0x00000300,&UNK_0028ad6b);  /* UNK_28ad6b(vma=0x18ad6b)='battle_tutorial_2' */
                func_0x0045e320(&stack0x00000330,&stack0x00000300);
                *(undefined **)(unaff_x29 + -0x100) = &UNK_00be1fa8;  /* field_off=0xbe1fa8 */
                *(long **)(unaff_x29 + -0xf8) = in_stack_00000190;
                *(long *)(unaff_x29 + -0xe0) = unaff_x29 + -0x100;
                uVar33 = func_0x00868168(in_stack_00000190 + 0x5bd,&stack0x00000330,0,0,4,
                                         unaff_x29 + -0x100);
                func_0x00866ca4(uVar33,&stack0x000003c0);
                (*(code *)&UNK_006d4d9c)();  /* field_off=0x6d4d9c */
                plVar38 = *(long **)(unaff_x29 + -0xe0);
                if (plVar38 == (long *)(unaff_x29 + -0x100)) {
                  lVar31 = 4;
                  plVar38 = (long *)(unaff_x29 + -0x100);
LAB_006ccaa8:
                  (**(code **)(*plVar38 + lVar31 * 8))();
                }
                else if (plVar38 != (long *)0x0) {
                  lVar31 = 5;
                  goto LAB_006ccaa8;
                }
                if (((ulong)plVar67 & 1) != 0) {
                  func_0x00bc3350(plVar69);
                }
                if ((in_stack_00000300 & 1) != 0) {
                  func_0x00bc3350(in_stack_00000310);
                }
                *(undefined1 *)plVar28 = 1;
                *(int *)((long)in_stack_00000190 + 0x224) =
                     *(int *)((long)in_stack_00000190 + 0x224) + 1;
                (**(code **)(*in_stack_00000190 + 0x38))();
                goto LAB_006c7a20;
              }
              uVar30 = (long)plVar55 - (long)plVar28 >> 1;
              if (uVar30 <= uVar32) {
                uVar30 = uVar32;
              }
              if (0x7ffffffffffffffb < (ulong)((long)plVar55 - (long)plVar28)) {
                uVar30 = 0x3fffffffffffffff;
              }
              if (uVar30 == 0) {
                plVar26 = (long *)0x0;
              }
              else {
                if (uVar30 >> 0x3e != 0) {
                  if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
                  goto LAB_006cdcd8;
                  func_0x0040fc1c();
                  goto LAB_006cc9b4;
                }
                plVar26 = (long *)func_0x00bc3330(uVar30 << 2);
              }
              plVar69 = (long *)((long)plVar26 + ((long)plVar48 >> 2) * 4);
              in_stack_00000338 = (long *)((long)plVar69 + 4);
              *(int *)plVar69 = (int)unaff_x28[0x51795];
              plVar49 = plVar69;
              if ((long)plVar38 - (long)plVar28 != 0) {
                uVar32 = ((long)plVar38 - (long)plVar28) - 4;
                if (0xab < uVar32) {
                  piVar45 = (int *)((long)plVar38 + -4);
                  uVar27 = (long)piVar45 - (long)plVar28 & 0xfffffffffffffffc;
                  if ((((undefined1 *)((long)plVar26 + (long)plVar48) + -4 + -uVar27 <=
                        (undefined1 *)((long)plVar26 + (long)plVar48) + -4) &&
                      ((int *)((long)piVar45 - uVar27) <= piVar45)) &&
                     ((undefined1 *)0x1f <
                      (undefined1 *)((long)plVar38 + (-(long)plVar48 - (long)plVar26)))) {
                    uVar32 = (uVar32 >> 2) + 1;
                    uVar42 = uVar32 & 0x7ffffffffffffff8;
                    plVar49 = (long *)((long)plVar69 + uVar42 * -4);
                    plVar69 = plVar69 + -2;
                    plVar55 = plVar38 + -2;
                    uVar27 = uVar42;
                    do {
                      plVar68 = plVar55 + -1;
                      lVar39 = plVar55[-2];
                      lVar40 = plVar55[1];
                      lVar31 = *plVar55;
                      uVar27 = uVar27 - 8;
                      plVar55 = plVar55 + -4;
                      plVar69[-1] = *plVar68;
                      plVar69[-2] = lVar39;
                      plVar69[1] = lVar40;
                      *plVar69 = lVar31;
                      plVar69 = plVar69 + -4;
                    } while (uVar27 != 0);
                    plVar38 = (long *)((long)plVar38 + uVar42 * -4);
                    plVar69 = plVar49;
                    if (uVar32 == uVar42) goto LAB_006c9680;
                  }
                }
                do {
                  plVar38 = (long *)((long)plVar38 + -4);
                  plVar49 = (long *)((long)plVar69 + -4);
                  *(int *)plVar49 = *(int *)plVar38;
                  plVar69 = plVar49;
                } while (plVar38 != plVar28);
              }
LAB_006c9680:
              plVar55 = (long *)((long)plVar26 + uVar30 * 4);
              plVar38 = plVar49;
              unaff_x28 = in_stack_00000338;
              plVar67 = plVar49;
              plVar69 = plVar55;
              if (plVar28 != (long *)0x0) {
                plVar26 = (long *)func_0x00bc3350(plVar28);
              }
            }
            piVar50 = (int *)((long)piVar50 + 1);
            plVar28 = plVar38;
            plVar38 = in_stack_00000338;
          } while ((long)piVar50 < (long)in_stack_00000170[0x67]);
          in_stack_000001e0 = 0;
          in_stack_000001e8 = 0;
          in_stack_000001d8 = 0;
          lVar31 = (long)in_stack_00000338 - (long)plVar67;
          if (lVar31 == 0) goto LAB_006c9888;
          if (-1 < lVar31) {
            in_stack_000001d8 = func_0x00bc3330(lVar31);
            lVar40 = in_stack_000001d8 + lVar31;
            in_stack_000001e0 = in_stack_000001d8;
            in_stack_000001e8 = lVar40;
            func_0x00bc35f0(in_stack_000001d8,plVar67,lVar31);
            in_stack_000001e0 = lVar40;
            goto LAB_006c9888;
          }
          if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
          goto LAB_006cdcd8;
          plVar26 = (long *)func_0x00441cdc(&stack0x000001d8);
          plVar68 = plVar67;
LAB_006ccc30:
          if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
          goto LAB_006cdcd8;
          plVar26 = (long *)func_0x00441cdc(&stack0x00000330);
          plVar48 = plVar49;
          plVar28 = plVar67;
          plVar38 = in_stack_00000338;
LAB_006ccc4c:
          plVar67 = plVar68;
          if (*(long *)(in_stack_000000b0 + 0x28) != *(long *)(unaff_x29 + -0x38))
          goto LAB_006cdcd8;
          func_0x0040fc1c();
          piVar45 = (int *)((long)plVar28 + 4);
          iVar23 = *piVar45;
          *piVar45 = iVar23 + 1;
          if (0x16 < iVar23) {
            plVar26 = (long *)(**(code **)(*in_stack_00000190 + 0x38))();
            piVar45[0] = 0;
            piVar45[1] = 0;
            ((int *)((long)plVar28 + 0xc))[0] = 0;
            ((int *)((long)plVar28 + 0xc))[1] = 0;
            *(undefined1 *)plVar28 = 1;
            *(undefined4 *)((long)in_stack_00000188 + 4) = 1;
            if (*in_stack_000000a0 == 0) {
LAB_006cc530:
              uVar33 = func_0x0044c16c(plVar26);
              func_0x0044e744(uVar33,0x32);
            }
            goto LAB_006c7a20;
          }
          uVar19 = piVar50[0x28];
          if (0 < (int)uVar19) {
            piVar50[0x28] = uVar19 + 1;
            if (((uVar19 < 5) || (lVar31 = *plVar38, piVar50[0x28] = 0, (int)lVar31 == 0x30)) ||
               ((in_stack_000000c8[0x56] == 3 || (in_stack_000000c8[0x56] == 99))))
            goto LAB_006c7ae4;
            (**(code **)(*in_stack_00000190 + 0x38))(in_stack_00000190);
            *(undefined1 *)(plVar28 + 9) = 1;
            func_0x005b1674(in_stack_00000190 + 0x8d742,1,1);
            if ((int)in_stack_00000188[3] - 1U < 2) {
              plVar26 = (long *)0x0;
              *(undefined4 *)(in_stack_00000188 + 3) = 0;
              goto LAB_006c7a24;
            }
            goto LAB_006c7a20;
          }
          puVar51 = (undefined4 *)((long)in_stack_00000190 + 0x328214);
          uVar19 = *(uint *)(in_stack_00000190 + 0x6506e);
          if (0 < (int)uVar19) {
            *(uint *)(in_stack_00000190 + 0x6506e) = uVar19 + 1;
            if (uVar19 < 5) goto LAB_006c7ae4;
            *(undefined4 *)(in_stack_00000190 + 0x6506e) = 0;
            (**(code **)(*in_stack_00000190 + 0x38))(in_stack_00000190);
            *(undefined1 *)((long)plVar38 + 0x9ec) = 1;
            func_0x008003f4(in_stack_00000190,1);
            func_0x008de0f0(in_stack_00000190 + 0x8d337);
            plVar26 = (long *)0x0;
            if (*in_stack_000000a0 == 0) goto LAB_006cc530;
            goto LAB_006c7a24;
          }
          uVar19 = in_stack_000000c8[0x38];
          if ((int)uVar19 < 1) {
            uVar19 = in_stack_000000c8[0x3b];
            if ((int)uVar19 < 1) {
              uVar19 = in_stack_000000c8[0x3d];
              if ((int)uVar19 < 1) {
LAB_006cc9b4:
                if ((((int)in_stack_00000190[0x65077] < 1) &&
                    (*(int *)((long)in_stack_00000190 + 0x3283bc) < 1)) &&
                   (((int)in_stack_00000190[0x65078] < 1 &&
                    ((((((*(int *)((long)in_stack_00000190 + 0x3283c4) < 1 &&
                         ((int)in_stack_00000190[0x65079] < 1)) &&
                        (*(int *)((long)in_stack_00000190 + 0x3283cc) < 1)) &&
                       (((int)in_stack_00000190[0x6507a] < 1 &&
                        (*(int *)((long)in_stack_00000190 + 0x3283d4) < 1)))) &&
                      ((int)in_stack_00000190[0x6507b] < 1)) &&
                     (*(int *)((long)in_stack_00000190 + 0x3283dc) < 1)))))) {
LAB_006ccce4:
                  if (*(char *)((long)plVar38 + 0x9c4) == '\0') {
                    func_0x009b9144(in_stack_00000190);
                  }
                  func_0x006df1f0(in_stack_00000190,0);
                  iVar23 = (int)*plVar48;
                  iVar24 = in_stack_00000050[5];
                  if (iVar23 < 0) {
                    iVar23 = iVar23 + 1;
                  }
                  iVar21 = func_0x0043dc7c(in_stack_00000190);
                  iVar17 = *(int *)(&DAT_00c0b3ac + (long)piVar50[0x28] * 4);
                  if (iVar17 < 0) {
                    iVar17 = iVar17 + 1;
                  }
                  fVar57 = (float)(((iVar23 >> 1) - iVar24) / 10 + -0x41) +
                           (float)(iVar21 + -0x3c0) * 0.5;
                  fVar60 = (float)(int)(-0x18 - (in_stack_000000c8[0x73] +
                                                 *(int *)((long)plVar28 + 0xd4) +
                                                 in_stack_000000c8[10] + (iVar17 >> 1)));
                  fVar63 = (float)in_stack_00000190[0x685];
                  fVar65 = (float)((ulong)in_stack_00000190[0x685] >> 0x20);
                  fVar64 = (float)in_stack_00000190[0x684];
                  fVar66 = (float)((ulong)in_stack_00000190[0x684] >> 0x20);
                  fVar58 = (float)in_stack_00000190[0x686];
                  fVar61 = fVar58 + fVar63 * fVar60 + fVar64 * fVar57;
                  fVar59 = (float)((ulong)in_stack_00000190[0x686] >> 0x20);
                  fVar62 = fVar59 + fVar65 * fVar60 + fVar66 * fVar57;
                  *piVar50 = (int)fVar61;
                  piVar50[1] = (int)fVar62;
                  *(ulong *)(piVar50 + 2) =
                       CONCAT44((int)((fVar59 + fVar65 * (fVar60 + 131.0) +
                                                fVar66 * (fVar57 + 131.0)) - fVar62),
                                (int)((fVar58 + fVar63 * (fVar60 + 131.0) +
                                                fVar64 * (fVar57 + 131.0)) - fVar61));
                  uVar32 = func_0x00805fcc(in_stack_00000190);
                  if ((uVar32 & 1) == 0) {
                    uVar32 = func_0x00807844(in_stack_00000190);
                    if ((uVar32 & 1) == 0) {
                      uVar37 = 0;
                      goto LAB_006cce28;
                    }
                  }
                  else if (((char)in_stack_00000058[7] != '\0') ||
                          ((char)in_stack_00000058[8] != '\0')) {
                    uVar37 = 1;
LAB_006cce28:
                    *(undefined1 *)((long)in_stack_00000058 + 0x1d) = uVar37;
                  }
                  if (*in_stack_00000048 == 0) {
                    pcVar1 = (char *)((long)in_stack_00000190 + 0x32a48c);
                    if (*(char *)((long)in_stack_00000058 + 0x1f) == '\0') {
                      uVar32 = 0;
                      do {
                        uVar30 = func_0x00805fcc(in_stack_00000190);
                        if ((((uVar30 & 1) != 0) &&
                            (uVar30 = func_0x0098aef0(in_stack_00000190,
                                                      *(undefined4 *)
                                                       ((long)in_stack_00000190 +
                                                       uVar32 * 0x10 + 0x327de4),
                                                      (int)in_stack_00000190[uVar32 * 2 + 0x64fbd],
                                                      *(undefined4 *)
                                                       ((long)in_stack_00000190 +
                                                       uVar32 * 0x10 + 0x327dec),
                                                      (int)in_stack_00000190[uVar32 * 2 + 0x64fbe]),
                            (uVar30 & 1) != 0)) &&
                           (uVar30 = func_0x005af168(uVar32 & 0xffffffff), (uVar30 & 1) != 0)) {
                          if ((uVar32 != *(uint *)(plVar38 + 0x139)) ||
                             (*(char *)((long)plVar38 + 0x9c4) == '\0')) {
                            *(int *)(plVar38 + 0x139) = (int)uVar32;
                            uVar33 = func_0x005ace18();
                            func_0x006e437c((int)plVar38[0x139]);
                            func_0x006e5ed0(&stack0x00000330);
                            func_0x0044fe48(&stack0x00000300,uVar33,&stack0x00000330,&DAT_00c0bf30,
                                            0x1e,1,0,0);
                            func_0x005ace98(in_stack_00000190 +
                                            (long)*(int *)((long)in_stack_00000190 + 0x32a4fc) * 2 +
                                            0xe6c,&stack0x00000300);
                            func_0x0043f7ec(&stack0x00000300);
                            if (((ulong)plVar67 & 1) != 0) {
                              func_0x00bc3350(plVar69);
                            }
                            lVar40 = (long)*(int *)((long)in_stack_00000190 + 0x32a4fc);
                            lVar31 = lVar40 + -1;
                            in_stack_00000188 = (long *)(lVar40 * 0x18);
                            plVar26 = in_stack_00000190 + lVar40 * 2 + 0xe6e;
                            do {
                              uVar33 = func_0x005ace18();
                              func_0x006e437c((int)plVar38[0x139]);
                              func_0x006e5f48(&stack0x00000330);
                              func_0x0044fe48(&stack0x00000300,uVar33,
                                              (undefined1 *)
                                              ((long)(plVar67 +
                                                     (long)*(int *)((long)in_stack_00000190 +
                                                                   0x32a4fc) * -3) +
                                              (long)in_stack_00000188),&DAT_00c0bf30,0x1e,1,0,0);
                              func_0x005ace98(plVar26,&stack0x00000300);
                              func_0x0043f7ec(&stack0x00000300);
                              func_0x0040f80c(&stack0x00000330);
                              lVar31 = lVar31 + 1;
                              plVar26 = plVar26 + 2;
                              in_stack_00000188 = in_stack_00000188 + 3;
                            } while (lVar31 < (long)*(int *)((long)in_stack_00000190 + 0x32a4fc) + 2
                                    );
                            if (((int)plVar38[0x139] == 0) &&
                               (*(char *)((long)in_stack_000000c8 + 0x14b) == '\0')) {
                              func_0x009ea87c(in_stack_00000190 + 0x5eb,0);
                              func_0x0040cb78(&stack0x00000300,&UNK_0029b4e1);  /* UNK_29b4e1(vma=0x19b4e1)='speedup_message' */
                              func_0x0045e320(&stack0x00000330,&stack0x00000300);
                              func_0x009eaa70(in_stack_00000190 + 0x5eb,0,&stack0x00000330,0x1e,
                                              0x2c6);
                              if (((ulong)plVar67 & 1) != 0) {
                                func_0x00bc3350(plVar69);
                              }
                              if ((in_stack_00000300 & 1) != 0) {
                                func_0x00bc3350(in_stack_00000310);
                              }
                            }
                          }
                          *(undefined1 *)((long)plVar38 + 0x9c4) = 1;
                        }
                        uVar32 = uVar32 + 1;
                      } while (uVar32 != 6);
                      if (*(char *)((long)plVar38 + 0x9c4) != '\0') {
                        *(undefined4 *)(in_stack_00000190 + 0x654a0) = 5;
                      }
                    }
                    if ((*in_stack_00000048 == 0) &&
                       (*(char *)((long)in_stack_00000058 + 0x1f) == '\0')) {
                      if ((char)unaff_x22[0x14] == '\0') {
                        uVar32 = func_0x005c14c8(in_stack_00000190);
                        if ((((uVar32 & 1) == 0) ||
                            (uVar32 = func_0x00805fcc(in_stack_00000190), (uVar32 & 1) == 0)) ||
                           (uVar32 = func_0x0098aef0(in_stack_00000190,*puVar51,puVar51[1],
                                                     puVar51[2],puVar51[3]), (uVar32 & 1) == 0)) {
                          *pcVar1 = '\0';
                        }
                        else if (*pcVar1 == '\0') {
                          uVar33 = func_0x0044c16c();
                          func_0x0044e35c(uVar33,10,0);
                          *pcVar1 = '\x01';
                        }
                        uVar32 = func_0x005c1960(in_stack_00000190);
                        if ((((uVar32 & 1) == 0) ||
                            (uVar32 = func_0x00805fcc(in_stack_00000190), (uVar32 & 1) == 0)) ||
                           (uVar32 = func_0x0098aef0(in_stack_00000190,puVar51[4],puVar51[5],
                                                     puVar51[6],puVar51[7]), (uVar32 & 1) == 0)) {
                          *(undefined1 *)((long)in_stack_00000190 + 0x32a48d) = 0;
                        }
                        else if (*(char *)((long)in_stack_00000190 + 0x32a48d) == '\0') {
                          uVar33 = func_0x0044c16c();
                          func_0x0044e35c(uVar33,10,0);
                          *(undefined1 *)((long)in_stack_00000190 + 0x32a48d) = 1;
                        }
                      }
                      uVar32 = func_0x00805fcc(in_stack_00000190);
                      if (((uVar32 & 1) == 0) ||
                         (uVar32 = func_0x0098aef0(in_stack_00000190,puVar51[0xc],puVar51[0xd],
                                                   puVar51[0xe],puVar51[0xf]), (uVar32 & 1) == 0)) {
                        *(undefined1 *)((long)in_stack_00000190 + 0x32a48f) = 0;
                      }
                      else if (*(char *)((long)in_stack_00000190 + 0x32a48f) == '\0') {
                        uVar33 = func_0x0044c16c();
                        func_0x0044e35c(uVar33,10,0);
                        *(undefined1 *)((long)in_stack_00000190 + 0x32a48f) = 1;
                      }
                      uVar32 = func_0x005c14c8(in_stack_00000190);
                      if (((((uVar32 & 1) == 0) ||
                           (uVar32 = func_0x00807844(in_stack_00000190), (uVar32 & 1) == 0)) ||
                          (uVar32 = func_0x0098aef0(in_stack_00000190,*puVar51,puVar51[1],puVar51[2]
                                                    ,puVar51[3]), (uVar32 & 1) == 0)) ||
                         (*(char *)((long)plVar38 + 0x9c4) != '\0')) {
                        uVar32 = func_0x005c1960(in_stack_00000190);
                        if ((((uVar32 & 1) == 0) ||
                            (uVar32 = func_0x00807844(in_stack_00000190), (uVar32 & 1) == 0)) ||
                           ((uVar32 = func_0x0098aef0(in_stack_00000190,puVar51[4],puVar51[5],
                                                      puVar51[6],puVar51[7]), (uVar32 & 1) == 0 ||
                            (*(char *)((long)plVar38 + 0x9c4) != '\0')))) {
                          uVar32 = func_0x00807844(in_stack_00000190);
                          if (((((uVar32 & 1) != 0) &&
                               (uVar32 = func_0x0098aef0(in_stack_00000190,puVar51[0xc],puVar51[0xd]
                                                         ,puVar51[0xe],puVar51[0xf]),
                               (uVar32 & 1) != 0)) ||
                              (uVar32 = func_0x00807850(in_stack_00000190), (uVar32 & 1) != 0)) &&
                             (*(char *)((long)plVar38 + 0x9c4) == '\0')) {
                            uVar33 = func_0x0044c16c();
                            func_0x0044e35c(uVar33,0xb,0);
                            iVar23 = puVar51[0x57];
                            *(undefined1 *)((long)plVar38 + 0x9c4) = 0;
                            *(undefined4 *)(in_stack_00000190 + 0x654a0) = 0;
                            puVar51[0x57] = iVar23 + 1;
                            goto LAB_006c7ae4;
                          }
                          uVar32 = func_0x00807844(in_stack_00000190);
                          if ((((uVar32 & 1) == 0) ||
                              (uVar32 = func_0x0098aef0(in_stack_00000190,in_stack_000000c8[0xc],
                                                        in_stack_000000c8[0xd],
                                                        in_stack_000000c8[0xe],
                                                        in_stack_000000c8[0xf]), (uVar32 & 1) == 0))
                             || (uVar32 = func_0x005af168(0), (uVar32 & 1) == 0)) {
                            uVar32 = func_0x00807844(in_stack_00000190);
                            if ((((uVar32 & 1) == 0) ||
                                (uVar32 = func_0x0098aef0(in_stack_00000190,in_stack_000000c8[0x18],
                                                          in_stack_000000c8[0x19],
                                                          in_stack_000000c8[0x1a],
                                                          in_stack_000000c8[0x1b]),
                                (uVar32 & 1) == 0)) ||
                               (uVar32 = func_0x005af0d8(3), (uVar32 & 1) == 0)) {
                              uVar32 = func_0x00807844(in_stack_00000190);
                              if ((((uVar32 & 1) == 0) ||
                                  (uVar32 = func_0x0098aef0(in_stack_00000190,
                                                            in_stack_000000c8[0x20],
                                                            in_stack_000000c8[0x21],
                                                            in_stack_000000c8[0x22],
                                                            in_stack_000000c8[0x23]),
                                  (uVar32 & 1) == 0)) ||
                                 (uVar32 = func_0x005af0d8(5), (uVar32 & 1) == 0)) {
                                uVar32 = func_0x00807844(in_stack_00000190);
                                if (((((((uVar32 & 1) == 0) ||
                                       (uVar32 = func_0x0098aef0(in_stack_00000190,*piVar50,
                                                                 piVar50[1],piVar50[2],piVar50[3]),
                                       (uVar32 & 1) == 0)) ||
                                      (*(char *)((long)plVar38 + 0x9c4) != '\0')) ||
                                     ((((int)*plVar38 == 0x30 || (in_stack_000000c8[0x56] == 3)) ||
                                      ((in_stack_000000c8[0x56] == 99 ||
                                       (((char)piVar50[0x3fc] != '\0' ||
                                        (*(char *)((long)piVar50 + 0xffe) != '\0')))))))) ||
                                    (*(char *)((long)piVar50 + 0xfff) != '\0')) ||
                                   ((iVar23 = func_0x007abd78(0), iVar23 == -7 &&
                                    (iVar23 = func_0x007ac380(), iVar23 == 0x2f)))) {
                                  if (((char)in_stack_00000058[7] == '\0') &&
                                     (((*in_stack_00000048 == 0 &&
                                       (*(char *)((long)in_stack_00000058 + 0x1d) == '\0')) &&
                                      (*(char *)((long)in_stack_00000058 + 0x1e) == '\0')))) {
                                    uVar19 = 0;
                                    if (*in_stack_00000058 == 0) {
LAB_006cd4c8:
                                      *in_stack_000000c8 = uVar19;
                                    }
                                    else if (*in_stack_00000058 == 1) {
                                      uVar19 = 5;
                                      goto LAB_006cd4c8;
                                    }
                                    uVar32 = 0;
                                    bVar13 = *(char *)((long)unaff_x28 + 1) == '\0';
                                    in_stack_00000188 = in_stack_00000190 + 0x65492;
                                    do {
                                      iVar23 = 0;
                                      if ((uVar32 < 5) && (!bVar13)) {
                                        func_0x0040cb78(&stack0x00000250,&UNK_0028fc2d);  /* UNK_28fc2d(vma=0x18fc2d)='battle_slot_2lines_line' */
                                        iVar23 = func_0x008e3f14(in_stack_00000190 + 0x28f,
                                                                 &stack0x00000250,0x5a);
                                        iVar23 = -iVar23;
                                        if ((in_stack_00000250 & 1) != 0) {
                                          func_0x00bc3350(in_stack_00000260);
                                        }
                                      }
                                      uVar19 = *in_stack_000000c8;
                                      if (*(char *)((long)unaff_x28 + 1) != '\0') {
                                        uVar19 = 0;
                                      }
                                      uVar30 = uVar32 + uVar19;
                                      uVar27 = func_0x00805fcc(in_stack_00000190);
                                      iVar24 = (int)uVar30;
                                      if ((uVar27 & 1) == 0) {
LAB_006cd634:
                                        *(undefined1 *)((long)in_stack_00000188 + uVar32) = 0;
                                      }
                                      else {
                                        iVar17 = *(int *)(&DAT_00c0aea8 + (long)iVar24 * 4);
                                        iVar21 = func_0x0043dc7c(in_stack_00000190);
                                        uVar27 = func_0x0098aef0(in_stack_00000190,
                                                                 (int)((double)iVar17 +
                                                                      (double)(iVar21 + -0x3c0) *
                                                                      0.5),
                                                                 iVar23 + in_stack_000000c8[0x73] +
                                                                 *piVar52 + -1,0x6e,0x58);
                                        if ((uVar27 & 1) == 0) goto LAB_006cd634;
                                        if (*(char *)((long)in_stack_00000188 + uVar32) == '\0') {
                                          uVar33 = func_0x0044c16c();
                                          func_0x0044e35c(uVar33,10,0);
                                          *(undefined1 *)((long)in_stack_00000188 + uVar32) = 1;
                                          iVar17 = func_0x005abf04(0,uVar30 & 0xffffffff);
                                          uVar25 = func_0x005abf1c(0,uVar30 & 0xffffffff);
                                          if ((-1 < iVar17) &&
                                             (iVar24 != *(int *)((long)in_stack_00000190 + 0x13d4)))
                                          {
                                            *(int *)((long)in_stack_00000190 + 0x13d4) = iVar24;
                                            uVar33 = func_0x005ace18();
                                            func_0x0062d830(&stack0x00000330,iVar17,uVar25);
                                            func_0x0044fe48(&stack0x00000300,uVar33,&stack0x00000330
                                                            ,&DAT_00c0bf30,0x1e,1,0,0);
                                            func_0x005ace98(in_stack_00000148 + 0x16008,
                                                            &stack0x00000300);
                                            func_0x0043f7ec(&stack0x00000300);
                                            if (((ulong)plVar67 & 1) != 0) {
                                              func_0x00bc3350(plVar69);
                                            }
                                            func_0x00606b54(in_stack_00000148 + 0x16018);
                                            func_0x00606b54(in_stack_00000148 + 0x16028);
                                            func_0x00606b54(in_stack_00000148 + 0x16038);
                                            func_0x00a51138(in_stack_00000190,
                                                            in_stack_00000148 + 0x16018,iVar17,0);
                                          }
                                        }
                                        else if (iVar24 == *(int *)((long)in_stack_00000190 + 0x13d4
                                                                   )) {
                                          *(int *)(in_stack_00000190 + 0x27a) =
                                               (int)in_stack_00000190[0x27a] + 1;
                                          uVar30 = func_0x006cdfa4();
                                          if ((uVar30 & 1) != 0) {
                                            *(undefined1 *)unaff_x28 = 1;
                                            *(undefined4 *)(in_stack_00000190 + 0x27b) = 3;
                                          }
                                        }
                                      }
                                      uVar30 = func_0x00807844(in_stack_00000190);
                                      if ((uVar30 & 1) != 0) {
                                        iVar24 = *(int *)(&DAT_00c0aea8 + (long)iVar24 * 4);
                                        iVar17 = func_0x0043dc7c(in_stack_00000190);
                                        uVar30 = func_0x0098aef0(in_stack_00000190,
                                                                 (int)((double)iVar24 +
                                                                      (double)(iVar17 + -0x3c0) *
                                                                      0.5),
                                                                 iVar23 + in_stack_000000c8[0x73] +
                                                                 *piVar52 + -1,0x6e,0x58);
                                        if ((((uVar30 & 1) != 0) &&
                                            (*(char *)((long)plVar38 + 0x9c4) == '\0')) &&
                                           (uVar30 = func_0x006cdfa4(in_stack_00000190),
                                           (uVar30 & 1) == 0)) {
                                          *(undefined1 *)((long)plVar38 + 0x9c4) = 0;
                                          lVar31 = (long)in_stack_00000190 + uVar32 * 4;
                                          *(undefined4 *)(in_stack_00000190 + 0x654a0) = 0;
                                          *(int *)(&UNK_003283b8 + lVar31) =  /* field_off=0x3283b8 */
                                               *(int *)(&UNK_003283b8 + lVar31) + 1;  /* field_off=0x3283b8 */
                                          break;
                                        }
                                      }
                                      uVar32 = uVar32 + 1;
                                      bVar13 = *(char *)((long)unaff_x28 + 1) == '\0';
                                      uVar30 = 10;
                                      if (bVar13) {
                                        uVar30 = 5;
                                      }
                                    } while (uVar32 < uVar30);
                                  }
                                }
                                else if (0 < *(int *)((long)in_stack_00000180 + 0x1c)) {
                                  *(undefined1 *)((long)plVar38 + 0x9c4) = 0;
                                  *(undefined4 *)(in_stack_00000190 + 0x654a0) = 0;
                                  uVar33 = func_0x0044c16c();
                                  func_0x0044e35c(uVar33,0xb,0);
                                  piVar50[0x28] = piVar50[0x28] + 1;
                                  BattleFn_0x004c5990(in_stack_00000190);
                                }
                                goto LAB_006c7ae4;
                              }
                              in_stack_000000c8[0x3d] = in_stack_000000c8[0x3d] + 1;
                            }
                            else {
                              in_stack_000000c8[0x3b] = in_stack_000000c8[0x3b] + 1;
                            }
                          }
                          else {
                            in_stack_000000c8[0x38] = in_stack_000000c8[0x38] + 1;
                          }
                          uVar33 = func_0x0044c16c();
                          uVar34 = 0xb;
                        }
                        else {
                          *(undefined1 *)((long)plVar38 + 0x9c4) = 0;
                          *(undefined4 *)(in_stack_00000190 + 0x654a0) = 0;
                          iVar23 = func_0x005b1f30(in_stack_00000190 + 0x4c9);
                          if (iVar23 != 7) {
                            iVar23 = func_0x005b1bf4(in_stack_00000190 + 0x4c9);
                            iVar24 = func_0x005b1f74(in_stack_00000190 + 0x4c9);
                            if (iVar24 <= iVar23) {
                              unaff_x22[0x15] = 0;
                              iVar23 = func_0x005b1f74(in_stack_00000190 + 0x4c9);
                              BattleFn_0x004b1e64(in_stack_00000190 + 0x4c9,-iVar23);
                              func_0x005b217c(in_stack_00000190 + 0x4c9,1);
                              in_stack_00000050[0x19] = 0xe;
                              uVar33 = func_0x0044c16c();
                              func_0x0044e35c(uVar33,0x13,0);
                              goto LAB_006c7ae4;
                            }
                          }
                          uVar33 = func_0x0044c16c();
                          uVar34 = 0xf;
                        }
                        func_0x0044e35c(uVar33,uVar34,0);
                      }
                      else {
                        BattleFn_0x004c8660(in_stack_00000190,1);
                      }
                    }
                  }
                }
                else {
                  uVar32 = 0;
                  uVar19 = 5;
                  if (*(char *)((long)unaff_x28 + 1) != '\0') {
                    uVar19 = 10;
                  }
                  uVar30 = (ulong)uVar19;
                  do {
                    if (0 < *(int *)((long)in_stack_00000190 + (long)(&UNK_003283b8 + uVar32 * 4)))  /* field_off=0x3283b8 */
                    {
                      uVar30 = uVar32 & 0xffffffff;
                      uVar27 = uVar32;
                      break;
                    }
                    uVar32 = uVar32 + 1;
                    uVar27 = uVar30;
                  } while (uVar30 != uVar32);
                  lVar31 = (long)in_stack_00000190 + uVar30 * 4;
                  iVar23 = *(int *)(&UNK_003283b8 + lVar31);  /* field_off=0x3283b8 */
                  *(uint *)(&UNK_003283b8 + lVar31) = iVar23 + 1U;  /* field_off=0x3283b8 */
                  if (5 < iVar23 + 1U) {
                    *(undefined4 *)(&UNK_003283b8 + lVar31) = 0;  /* field_off=0x3283b8 */
                    func_0x009aa848(in_stack_00000190 + 0x6770a);
                    if ((*in_stack_00000058 == 0) || (*(char *)((long)unaff_x28 + 1) != '\0')) {
                      uVar27 = uVar27 & 0xffffffff;
                    }
                    else {
                      if (*in_stack_00000058 != 1) goto LAB_006c7ae4;
                      uVar27 = (ulong)((int)uVar27 + 5);
                    }
                    func_0x009b99a0(in_stack_00000190,0,uVar27,1);
                  }
                }
              }
              else {
                in_stack_000000c8[0x3d] = uVar19 + 1;
                if (4 < uVar19) {
                  in_stack_000000c8[0x3d] = 0;
                  uVar19 = func_0x005af784(5);
                  func_0x005af72c(5,(uVar19 ^ 0xffffffff) & 1);
                }
              }
            }
            else {
              in_stack_000000c8[0x3b] = uVar19 + 1;
              if (4 < uVar19) {
                in_stack_000000c8[0x3b] = 0;
                uVar19 = func_0x005af784(3);
                func_0x005af72c(3,(uVar19 ^ 0xffffffff) & 1);
              }
            }
          }
          else {
            in_stack_000000c8[0x38] = uVar19 + 1;
            if (4 < uVar19) {
              in_stack_000000c8[0x38] = 0;
              uVar32 = func_0x005af658();
              if ((((uVar32 & 1) == 0) || (uVar32 = func_0x005af784(0), (uVar32 & 1) == 0)) ||
                 (*(char *)((long)in_stack_000000c8 + 0x14b) != '\0')) {
                uVar19 = func_0x005af784(0);
                func_0x005af72c(0,(uVar19 ^ 0xffffffff) & 1);
                *(undefined1 *)((long)in_stack_000000c8 + 0x14b) = 0;
              }
              else {
                *(undefined1 *)((long)in_stack_000000c8 + 0x14b) = 1;
              }
              if (((int)*in_stack_00000180 == 0) && (*(int *)((long)in_stack_00000190 + 0x224) == 3)
                 ) {
                *(undefined4 *)((long)in_stack_00000190 + 0x224) = 4;
              }
            }
          }
LAB_006c7ae4:
          uVar32 = func_0x005af784(0);
          if ((uVar32 & 1) == 0) {
            iVar23 = 1;
LAB_006c7b48:
            in_stack_00000058[0x378] = iVar23;
          }
          else {
            if (*(char *)((long)in_stack_000000c8 + 0x14b) == '\0') {
              iVar23 = 2;
              goto LAB_006c7b48;
            }
            func_0x0040cb78(&stack0x00000238,&UNK_00290f39);  /* UNK_290f39(vma=0x190f39)='boost_speed' */
            iVar23 = func_0x008e3f14(in_stack_00000190 + 0x28f,&stack0x00000238,3);
            in_stack_00000058[0x378] = iVar23;
            if ((in_stack_00000238 & 1) != 0) {
              func_0x00bc3350(in_stack_00000248);
            }
          }
          bVar14 = func_0x005af784(3);
          iVar23 = piVar50[0x33];
          *(byte *)(unaff_x22 + 0x14) = bVar14 & 1;
          if (iVar23 == 1) {
            in_stack_00000050[0xa9] = in_stack_00000050[0xa8];
            plVar26 = in_stack_00000190 + 0x107a2;
            lVar31 = 0x32;
            do {
              if (((int)plVar26[-4] != 0) && ((int)*plVar26 != 0)) {
                *(int *)plVar26 = *(int *)((long)plVar26 + -4);
              }
              lVar31 = lVar31 + -1;
              plVar26 = plVar26 + 0x7d;
            } while (lVar31 != 0);
            piVar50[0x33] = 0;
          }
          if (piVar50[0x36] == 1) {
            in_stack_000000c8[0x54] = in_stack_000000c8[0x54] + 1;
            func_0x005b2234(in_stack_00000190 + 0x4c9,0,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,1,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,2,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,3,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,4,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,5,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,6,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,7,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,8,0,1);
            func_0x005b2234(in_stack_00000190 + 0x4c9,9,0,1);
            if (0x707 < (int)in_stack_000000c8[0x54]) {
              piVar50[0x36] = 0;
              in_stack_000000c8[0x54] = 0;
            }
          }
          iVar23 = func_0x005ab154();
          if (iVar23 != 0) {
            *(undefined1 *)(unaff_x22 + 0x14) = 0;
            in_stack_00000058[0x378] = 1;
            piVar50[0x36] = 0;
            in_stack_000000c8[0x54] = 0;
          }
          func_0x005bf8e8(in_stack_00000190,in_stack_00000058[6]);
          iVar23 = *(int *)((long)in_stack_00000190 + 0x341c);
          iVar24 = in_stack_00000050[0x1c] * 100;
          if (iVar23 < iVar24) {
            *(int *)((long)in_stack_00000190 + 0x341c) = iVar24;
          }
          else {
            iVar24 = func_0x005ba6d4(in_stack_00000190);
            if (iVar24 < iVar23) {
              iVar24 = func_0x005ba6d4(in_stack_00000190);
              *(int *)((long)in_stack_00000190 + 0x341c) = iVar24;
            }
            else {
              iVar24 = *(int *)((long)in_stack_00000190 + 0x341c);
            }
          }
          in_stack_000000c8[1] = iVar24 / 100;
          fVar57 = (float)(int)*plVar48 + -9600.0 / (((float)iVar24 / 100.0) / 100.0);
          if ((float)in_stack_00000050[5] <= fVar57) {
            if (in_stack_00000050[5] < 0) {
              iVar23 = 0;
              goto LAB_006c7db0;
            }
          }
          else {
            iVar23 = (int)fVar57;
LAB_006c7db0:
            in_stack_00000050[5] = iVar23;
            *in_stack_00000048 = 0;
            iVar23 = func_0x005ab154();
            if (iVar23 == 0) {
              func_0x005ab128();
            }
          }
          in_stack_00000018 = in_stack_00000190 + 0x67129;
          if ((int)in_stack_00000190[0x1079e] == 0) {
            bVar13 = false;
          }
          else {
            plVar26 = in_stack_00000190 + 0x1081b;
            uVar32 = 1;
            do {
              uVar30 = uVar32;
              if (uVar30 == 0x32) break;
              lVar31 = *plVar26;
              plVar26 = plVar26 + 0x7d;
              uVar32 = uVar30 + 1;
            } while ((int)lVar31 != 0);
            bVar13 = 0x31 < uVar30;
          }
          uVar19 = func_0x009aafb8(in_stack_00000190 + 0x6770a);
          lVar31 = func_0x007fd748();
          uVar25 = func_0x007ac230(0);
          plVar26 = (long *)func_0x00633678(lVar31 + 0x668,uVar25,7);
          if (plVar26 == (long *)0x0) {
            if (bVar13 || (uVar19 & 1) != 0) goto LAB_006c7e70;
LAB_006c7e8c:
            if (((in_stack_000000a0[0xc6] & 0xfffffffeU) != 2) ||
               (iVar23 = in_stack_000000a0[0xc5], iVar24 = iVar23 + -1,
               in_stack_000000a0[0xc5] = iVar24, iVar24 == 0 || iVar23 < 1)) {
              in_stack_000000a0[0xc6] = 0;
            }
          }
          else {
            if ((int *)plVar26[1] == (int *)*plVar26) {
              if (*(long *)(in_stack_000000b0 + 0x28) == *(long *)(unaff_x29 + -0x38)) {
                    /* WARNING: Subroutine does not return */
                NoRet_0x00370c38();
              }
              goto LAB_006cdcd8;
            }
            if ((!bVar13 && (uVar19 & 1) == 0) && (int)in_stack_00000190[0x67713] < *(int *)*plVar26
               ) goto LAB_006c7e8c;
LAB_006c7e70:
            in_stack_000000a0[0xc5] = 0;
            in_stack_000000a0[0xc6] = 1;
          }
          uVar19 = *(uint *)(in_stack_00000190 + 0x39c);
          if (-1 < (int)uVar19) {
            iVar23 = -1;
            if (uVar19 < 0x32) {
              iVar23 = uVar19 + 1;
            }
            *(int *)(in_stack_00000190 + 0x39c) = iVar23;
          }
          in_stack_000000d0 = in_stack_00000190 + 0x704b3;
          in_stack_00000088 = in_stack_00000190 + 0x67123;
          in_stack_00000170 = (int *)((long)in_stack_00000190 + 0x28bcac);
          in_stack_000000e0 = in_stack_00000190 + 0x13cac;
          in_stack_00000180 = in_stack_00000190 + 0x13c31;
          unaff_x22 = (int *)((long)in_stack_00000190 + 0x9004c);
          in_stack_00000108 = in_stack_00000190 + 0x139fc;
          in_stack_000000e8 = in_stack_00000190 + 0x1071b;
          in_stack_000000d8 = in_stack_00000190 + 0x10721;
          BattleFn_0x004c5d04(in_stack_00000190);
          if ((int)in_stack_00000190[599] == -1) {
            BattleFn_0x004c51bc(in_stack_00000190);
          }
          lVar31 = 0;
          bVar13 = true;
          do {
            bVar12 = bVar13;
            piVar52 = (int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x2704);
            if ((*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26b4) == 1) &&
               (*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26dc) == 0)) {
              *piVar52 = *piVar52 + 1;
            }
            if (((int)in_stack_00000190[lVar31 * 0x3e + 0x4d7] == 1) &&
               ((int)in_stack_00000190[lVar31 * 0x3e + 0x4dc] == 0)) {
              *(int *)(in_stack_00000190 + lVar31 * 0x3e + 0x4e1) =
                   (int)in_stack_00000190[lVar31 * 0x3e + 0x4e1] + 1;
            }
            if ((*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26bc) == 1) &&
               (*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26e4) == 0)) {
              *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x270c) =
                   *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x270c) + 1;
            }
            if (((int)in_stack_00000190[lVar31 * 0x3e + 0x4d8] == 1) &&
               ((int)in_stack_00000190[lVar31 * 0x3e + 0x4dd] == 0)) {
              *(int *)(in_stack_00000190 + lVar31 * 0x3e + 0x4e2) =
                   (int)in_stack_00000190[lVar31 * 0x3e + 0x4e2] + 1;
            }
            if ((*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26c4) == 1) &&
               (*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26ec) == 0)) {
              *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x2714) =
                   *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x2714) + 1;
            }
            if (((int)in_stack_00000190[lVar31 * 0x3e + 0x4d9] == 1) &&
               ((int)in_stack_00000190[lVar31 * 0x3e + 0x4de] == 0)) {
              *(int *)(in_stack_00000190 + lVar31 * 0x3e + 0x4e3) =
                   (int)in_stack_00000190[lVar31 * 0x3e + 0x4e3] + 1;
            }
            if ((*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26cc) == 1) &&
               (*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26f4) == 0)) {
              *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x271c) =
                   *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x271c) + 1;
            }
            if (((int)in_stack_00000190[lVar31 * 0x3e + 0x4da] == 1) &&
               ((int)in_stack_00000190[lVar31 * 0x3e + 0x4df] == 0)) {
              *(int *)(in_stack_00000190 + lVar31 * 0x3e + 0x4e4) =
                   (int)in_stack_00000190[lVar31 * 0x3e + 0x4e4] + 1;
            }
            if ((*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26d4) == 1) &&
               (*(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x26fc) == 0)) {
              *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x2724) =
                   *(int *)((long)in_stack_00000190 + lVar31 * 0x1f0 + 0x2724) + 1;
            }
            if (((int)in_stack_00000190[lVar31 * 0x3e + 0x4db] == 1) &&
               ((int)in_stack_00000190[lVar31 * 0x3e + 0x4e0] == 0)) {
              *(int *)(in_stack_00000190 + lVar31 * 0x3e + 0x4e5) =
                   (int)in_stack_00000190[lVar31 * 0x3e + 0x4e5] + 1;
            }
            lVar31 = 1;
            bVar13 = false;
          } while (bVar12);
          uVar32 = func_0x009d0178(in_stack_00000190[0xf8]);
          if ((uVar32 & 1) != 0) {
            func_0x00634980(in_stack_00000190 + 0xcd);
          }
          unaff_x19 = in_stack_00000190;
          if (in_stack_00000058[0x378] < 1) goto LAB_006cbfe0;
          unaff_s9 = 6.0;
          in_stack_00000098 = in_stack_00000190 + 0x4ea;
          in_stack_00000068._4_4_ = 0;
          in_stack_00000038 = (undefined8 *)&stack0x00000338;
          in_stack_00000030 = (undefined8 *)&stack0x00000350;
          in_stack_00000160 = in_stack_00000148 + 0x2478;
          in_stack_00000150 = in_stack_00000190 + 0x1071f;
          in_stack_00000110 = in_stack_00000190 + 0x704b4;
          in_stack_00000158 = (undefined8 *)((ulong)&stack0x000001a0 | 1);
          in_stack_00000078 = in_stack_00000190 + 0x517c8;
          in_stack_00000060 = (int *)((long)in_stack_00000190 + 0x28bcb4);
          in_stack_000000c0 = in_stack_00000190 + 0x10728;
          in_stack_00000020 = (int *)((long)in_stack_00000190 + 0x90434);
          in_stack_00000100 = in_stack_00000190 + 0x13bc8;
          in_stack_00000070 = in_stack_00000190 + 0x13b8c;
          in_stack_00000028 = (int *)(in_stack_000000a8 + 0x4f4);
          unaff_d8 = 1;
          in_stack_00000008 = 0xffffffff00000000;
          in_stack_00000000 = 0;
          unaff_d10 = 0x400000001;
          in_stack_00000090 = in_stack_00000190 + 0x13caf;
          in_stack_000000f8 = 0x1b;
          in_stack_000000f0 = 0x21;
          in_stack_000000b8 = unaff_x22;
          goto LAB_006c8204;
        }
LAB_006c9388:
        puVar51 = (undefined4 *)((long)puVar51 + 1);
        if (puVar51 != (undefined4 *)0x33) goto LAB_006c9394;
        iVar23 = 0;
        do {
          uVar32 = func_0x00a59560(1,iVar23);  /* 0x959560:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w8, [x8, x9]] */
          if ((uVar32 & 1) != 0) {
            iVar24 = func_0x00a59a70(1,iVar23);  /* 0x959a70:[slot*1000,team*51000|off=0x83a0c|ldr w0, [x8, x9]] */
            if (iVar24 == 0) {
              iVar24 = func_0x00a5999c(1,iVar23);  /* 0x95999c:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w0, [x8, x9]] */
              if (iVar24 == 2) {
                func_0x005b095c(in_stack_00000190 + 0x21a,1);
              }
              uVar33 = func_0x0044c16c();
              func_0x0044e35c(uVar33,0x2d,0);
              iVar24 = 1;
              do {
                uVar32 = func_0x00a58fe8(0,iVar24,0xffffffff);  /* 0x958fe8:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                if (((uVar32 & 1) != 0) && (uVar32 = func_0x00a5fda0(0,iVar24), (uVar32 & 1) == 0))  /* 0x95fda0:[slot*1000,team*51000|off=0x83ad8|ldr w8, [x8, x9]] */
                {
                  func_0x00a58be4(0,iVar24,7);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                  func_0x00a590fc(0,iVar24,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                }
                iVar24 = iVar24 + 1;
              } while (iVar24 != 0x33);
            }
            func_0x00a59afc(1,iVar23,1);  /* 0x959afc:[slot*1000,team*51000|off=0x83a0c|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
            iVar24 = func_0x00a59a70(1,iVar23);  /* 0x959a70:[slot*1000,team*51000|off=0x83a0c|ldr w0, [x8, x9]] */
            iVar17 = func_0x004400b4(in_stack_00000148 + 0x1040);
            if (iVar17 <= iVar24) {
              uVar25 = func_0x004400b4(in_stack_00000148 + 0x1040);
              func_0x00a59ab0(1,iVar23,uVar25);  /* 0x959ab0:[slot*1000,team*51000|off=0x83a0c|str w19, [x8, x9]] */
            }
          }
          iVar23 = iVar23 + 1;
        } while (iVar23 != 0x33);
        BattleFn_0x004c1e04(in_stack_00000190);
        BattleFn_0x004c2188(in_stack_00000190);
        BattleFn_0x004c32c4(in_stack_00000190);
        BattleFn_0x004c3918(in_stack_00000190);
        BattleFn_0x004c4088(in_stack_00000190);
        BattleFn_0x004c5e0c(in_stack_00000190,0);
        BattleFn_0x004c5e0c(in_stack_00000190,1);
        *in_stack_00000038 = 0;
        in_stack_00000038[1] = 0;
        *in_stack_00000030 = 0;
        in_stack_00000030[1] = 0;
        uVar32 = func_0x005aacc8();
        if ((uVar32 & 1) == 0) {
          uVar32 = 0;
        }
        else {
          uVar32 = func_0x005aad10();
        }
        bVar13 = false;
        lVar31 = 0;
        uVar32 = uVar32 & 0xffffffff;
        bVar12 = true;
        do {
          bVar36 = bVar12;
          uVar30 = 0;
          lVar40 = lVar31 * 0x18;
          in_stack_00000188 = (long *)(&stack0x00000338 + lVar40);
          do {
            uVar27 = func_0x00a610f8(lVar31,uVar30 & 0xffffffff);  /* 0x9610f8:[slot*1000,team*51000|off=0x83b1c|ldr w8, [x8, x9]] */
            if ((uVar27 & 1) != 0) {
              func_0x00a61218(lVar31,uVar30 & 0xffffffff,1);  /* 0x961218:[slot*1000,team*51000|off=0x83b20|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
              iVar23 = func_0x00a6118c(lVar31,uVar30 & 0xffffffff);  /* 0x96118c:[slot*1000,team*51000|off=0x83b20|ldr w0, [x8, x9]] */
              iVar24 = func_0x0044003c(in_stack_00000148 + 9000);
              if (iVar24 <= iVar23) {
                func_0x00a61140(lVar31,uVar30 & 0xffffffff,0);  /* 0x961140:[slot*1000,team*51000|off=0x83b1c|str w21, [x8, x9]] */
              }
            }
            iVar23 = func_0x00a61894(lVar31,uVar30 & 0xffffffff);  /* 0x961894:[slot*1000,team*51000|off=0x83c08|ldr w0, [x8, x9]] */
            if (iVar23 != 0) {
              func_0x00a619ac(lVar31,uVar30 & 0xffffffff,1);  /* 0x9619ac:[slot*1000,team*51000|off=0x83c0c|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
              iVar23 = func_0x00a61920(lVar31,uVar30 & 0xffffffff);  /* 0x961920:[slot*1000,team*51000|off=0x83c0c|ldr w0, [x8, x9]] */
              iVar24 = func_0x00a61894(lVar31,uVar30 & 0xffffffff);  /* 0x961894:[slot*1000,team*51000|off=0x83c08|ldr w0, [x8, x9]] */
              iVar24 = func_0x0044003c(in_stack_00000160 + (long)iVar24 * 0x38 + -0x38);
              if (iVar24 <= iVar23) {
                func_0x00a618d4(lVar31,uVar30 & 0xffffffff,0);  /* 0x9618d4:[slot*1000,team*51000|off=0x83c08|str w19, [x8, x9]] */
              }
            }
            plVar38 = in_stack_00000150;
            if (bVar13) {
LAB_006c9d90:
              do {
                plVar38 = (long *)*plVar38;
                if (plVar38 == (long *)0x0) goto LAB_006c9f10;
              } while ((long)uVar30 < (long)(int)plVar38[4]);
              if ((long)(int)plVar38[4] < (long)uVar30) {
                plVar38 = plVar38 + 1;
                goto LAB_006c9d90;
              }
              in_stack_000001d0 = (undefined8 *)func_0x00bc3330(0x20);
              in_stack_000001c8 = in_stack_000000f8;
              in_stack_000001c0 = in_stack_000000f0;
              in_stack_000001d0[1] = 0x6c696b5f6c617465;  /* ascii(0x6c696b5f6c617465)='etal_kil' */
              *in_stack_000001d0 = 0x6d5f656c74746162;  /* ascii(0x6d5f656c74746162)='battle_m' */
              *(undefined8 *)((long)in_stack_000001d0 + 0x13) = 0x657079745f70685f;  /* ascii(0x657079745f70685f)='_hp_type' */
              *(undefined8 *)((long)in_stack_000001d0 + 0xb) = 0x72656c6c696b5f6c;  /* ascii(0x72656c6c696b5f6c)='l_killer' */
              *(undefined1 *)((long)in_stack_000001d0 + 0x1b) = 0;
              iVar23 = func_0x008e3f14(in_stack_00000190 + 0x28f,&stack0x000001c0,0);
              if (iVar23 == 0) {
                uVar19 = func_0x00a5a194(1,uVar30 & 0xffffffff);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
              }
              else {
                uVar19 = func_0x00a5a220(1,uVar30 & 0xffffffff);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
              }
              plVar38 = in_stack_00000150;
              if ((in_stack_000001c0 & 1) != 0) {
                func_0x00bc3350(in_stack_000001d0);
              }
              while (plVar26 = (long *)*plVar38, plVar28 = plVar38, (long *)*plVar38 != (long *)0x0)
              {
                while (plVar69 = plVar26, plVar38 = plVar69, (long)(int)plVar69[4] <= (long)uVar30)
                {
                  if ((long)uVar30 <= (long)(int)plVar69[4]) goto LAB_006c9eb4;
                  plVar26 = (long *)plVar69[1];
                  if ((long *)plVar69[1] == (long *)0x0) {
                    plVar38 = plVar69 + 1;
                    plVar28 = plVar69;
                    goto LAB_006c9e58;
                  }
                }
              }
LAB_006c9e58:
              plVar69 = (long *)func_0x00bc3330(0x40);
              plVar69[2] = (long)plVar28;
              *(int *)(plVar69 + 4) = (int)uVar30;
              plVar69[6] = 0;
              plVar69[7] = 0;
              plVar69[5] = 0;
              *plVar69 = 0;
              plVar69[1] = 0;
              *plVar38 = (long)plVar69;
              plVar26 = plVar69;
              if (*(long *)in_stack_000000e8[3] != 0) {
                in_stack_000000e8[3] = *(long *)in_stack_000000e8[3];
                plVar26 = (long *)*plVar38;
              }
              func_0x0040a8c0(in_stack_000000e8[4],plVar26);
              in_stack_000000e8[5] = in_stack_000000e8[5] + 1;
LAB_006c9eb4:
              piVar50 = (int *)plVar69[6];
              for (piVar52 = (int *)plVar69[5]; piVar52 != piVar50; piVar52 = piVar52 + 1) {
                iVar23 = func_0x0043ed6c((int)(*piVar52 * uVar19) / 100,1);
                func_0x00a60488(1,uVar30 & 0xffffffff,iVar23);  /* 0x960488:[slot*1000,team*51000|off=0x83954,0x83ac8,0x83b10,0x83b10,0x83b14|ldr w10, [x8, x9] ; str w10, [x8, x9] ; ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                uVar19 = uVar19 - iVar23 & ((int)(uVar19 - iVar23) >> 0x1f ^ 0xffffffffU);
              }
LAB_006c9f10:
              if ((((uVar30 == uVar32) && (uVar27 = func_0x005aaf3c(), (uVar27 & 1) != 0)) &&
                  (uVar27 = func_0x00a606ac(1,uVar32), (uVar27 & 1) != 0)) &&  /* 0x9606ac:[slot*1000,team*51000|off=0x83b90|ldr w8, [x8, x9]] */
                 (iVar23 = func_0x00a5a220(1,uVar32), 1 < iVar23)) {  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                iVar23 = func_0x00a5a220(1,uVar32);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                iVar24 = func_0x00a603d4(1,uVar32);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
                if (iVar23 <= iVar24) {
                  iVar23 = func_0x00a5a220(1,uVar32);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                  func_0x00a60414(1,uVar32,iVar23 + -1);  /* 0x960414:[slot*1000,team*51000|off=0x83954,0x83b90|str w19, [x8, x9] ; str w19, [x8, x9]] */
                }
              }
            }
            iVar23 = func_0x00a58874(lVar31,uVar30 & 0xffffffff);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            if ((iVar23 == 2) &&
               (uVar27 = func_0x00a606ac(lVar31,uVar30 & 0xffffffff), (uVar27 & 1) != 0)) {  /* 0x9606ac:[slot*1000,team*51000|off=0x83b90|ldr w8, [x8, x9]] */
              iVar23 = func_0x00a5fe34(lVar31,uVar30 & 0xffffffff);  /* 0x95fe34:[slot*1000,team*51000|off=0x83b10|ldr w0, [x8, x9]] */
              if ((0 < iVar23) || (iVar23 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff), 0 < iVar23)  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                 ) {
                iVar23 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff);  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                plVar38 = in_stack_00000188;
                if (0 < iVar23) {
                  while (plVar28 = (long *)*plVar38, plVar26 = plVar38,
                        (long *)*plVar38 != (long *)0x0) {
                    while (plVar38 = plVar28, (long)*(int *)((long)plVar38 + 0x1c) <= (long)uVar30)
                    {
                      if ((long)uVar30 <= (long)*(int *)((long)plVar38 + 0x1c)) goto LAB_006ca06c;
                      plVar28 = (long *)plVar38[1];
                      if ((long *)plVar38[1] == (long *)0x0) {
                        plVar26 = plVar38 + 1;
                        goto LAB_006ca014;
                      }
                    }
                  }
LAB_006ca014:
                  plVar28 = (long *)func_0x00bc3330(0x28);
                  plVar28[2] = (long)plVar38;
                  *(int *)((long)plVar28 + 0x1c) = (int)uVar30;
                  *(undefined1 *)(plVar28 + 4) = 0;
                  *plVar28 = 0;
                  plVar28[1] = 0;
                  *plVar26 = (long)plVar28;
                  lVar39 = **(long **)(&stack0x00000330 + lVar40);
                  plVar38 = plVar28;
                  if (lVar39 != 0) {
                    *(long *)(&stack0x00000330 + lVar40) = lVar39;
                    plVar38 = (long *)*plVar26;
                  }
                  func_0x0040a8c0(*(undefined8 *)(&stack0x00000338 + lVar40),plVar38);
                  *(long *)(&stack0x00000340 + lVar40) = *(long *)(&stack0x00000340 + lVar40) + 1;
                  plVar38 = plVar28;
LAB_006ca06c:
                  *(undefined1 *)(plVar38 + 4) = 1;
                  iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                  if (iVar23 == 0) {
                    iVar23 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff);  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                    iVar24 = func_0x00a603d4(lVar31,uVar30 & 0xffffffff);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
                    iVar23 = func_0x0043ed6c(iVar23 - iVar24,0);
                    func_0x00a617bc(lVar31,uVar30 & 0xffffffff,iVar23);  /* 0x9617bc:[slot*1000,team*51000|off=0x83c00|str w19, [x8, x9]] */
                    if (iVar23 < 1) {
                      func_0x00a61848(lVar31,uVar30 & 0xffffffff,1);  /* 0x961848:[slot*1000,team*51000|off=0x83c04|str w19, [x8, x9]] */
                    }
                  }
                }
                iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff);  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                if (iVar23 != 0) {
                  func_0x00a5fe74(lVar31,uVar30 & 0xffffffff,0);  /* 0x95fe74:[slot*1000,team*51000|off=0x83b10|str w19, [x8, x9]] */
                }
                iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                if (iVar23 != 0) {
                  func_0x00a617bc(lVar31,uVar30 & 0xffffffff,0);  /* 0x9617bc:[slot*1000,team*51000|off=0x83c00|str w19, [x8, x9]] */
                }
                iVar23 = func_0x00a5fe34(lVar31,uVar30 & 0xffffffff);  /* 0x95fe34:[slot*1000,team*51000|off=0x83b10|ldr w0, [x8, x9]] */
                if (((0 < iVar23) &&
                    (iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff), iVar23 == 0)) ||  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                   ((iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff), iVar23 == 1 ||  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                    (((iVar23 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff), 0 < iVar23 &&  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                      (iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff), iVar23 == 0)) ||  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                     (iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff), iVar23 == 1)))))) {  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                  func_0x00a60414(lVar31,uVar30 & 0xffffffff,0);  /* 0x960414:[slot*1000,team*51000|off=0x83954,0x83b90|str w19, [x8, x9] ; str w19, [x8, x9]] */
                  func_0x00a61d74(lVar31,uVar30 & 0xffffffff,0);  /* 0x961d74:[slot*1000,team*51000|off=0x83ce8|str w19, [x8, x9]] */
                  uVar25 = func_0x00a60a14(lVar31,uVar30 & 0xffffffff);  /* 0x960a14:[slot*1000,team*51000|off=0x83c78|ldr w0, [x8, x9]] */
                  func_0x00a608e8(lVar31,uVar30 & 0xffffffff,uVar25);  /* 0x9608e8:[slot*1000,team*51000|off=0x839fc|str w19, [x8, x9]] */
                  uVar25 = func_0x00a60c0c(lVar31,uVar30 & 0xffffffff);  /* 0x960c0c:[slot*1000,team*51000|off=0x83c7c|ldr w0, [x8, x9]] */
                  func_0x00a60ae0(lVar31,uVar30 & 0xffffffff,uVar25);  /* 0x960ae0:[slot*1000,team*51000|off=0x83a00|str w19, [x8, x9]] */
                  uVar25 = func_0x00a60e90(lVar31,uVar30 & 0xffffffff);  /* 0x960e90:[slot*1000,team*51000|off=0x83c80|ldr w0, [x8, x9]] */
                  func_0x00a60cd8(lVar31,uVar30 & 0xffffffff,uVar25);  /* 0x960cd8:[slot*1000,team*51000|off=0x83a34|str w19, [x8, x9]] */
                  uVar25 = func_0x00a6106c(lVar31,uVar30 & 0xffffffff);  /* 0x96106c:[slot*1000,team*51000|off=0x83c84|ldr w0, [x8, x9]] */
                  func_0x00a60f80(lVar31,uVar30 & 0xffffffff,uVar25);  /* 0x960f80:[slot*1000,team*51000|off=0x83b60|str w19, [x8, x9]] */
                  func_0x00a5a97c(lVar31,uVar30 & 0xffffffff,0);  /* 0x95a97c:[slot*1000,team*51000|off=0x83ca8|str w19, [x8, x9]] */
                }
                iVar23 = func_0x00a5fe34(lVar31,uVar30 & 0xffffffff);  /* 0x95fe34:[slot*1000,team*51000|off=0x83b10|ldr w0, [x8, x9]] */
                if ((0 < iVar23) ||
                   (iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff), iVar23 == 1)) {  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                  func_0x00a6073c(lVar31,uVar30 & 0xffffffff,0);  /* 0x96073c:[slot*1000,team*51000|off=0x839a0|str w21, [x8, x9]] */
                  func_0x00a614dc(lVar31,uVar30 & 0xffffffff,0);  /* 0x9614dc:[slot*1000,team*51000|off=0x83ba0|str w21, [x8, x9]] */
                  func_0x00a61730(lVar31,uVar30 & 0xffffffff,0);  /* 0x961730:[slot*1000,team*51000|off=0x83bbc|str w21, [x8, x9]] */
                  func_0x00a61c08(lVar31,uVar30 & 0xffffffff,0);  /* 0x961c08:[slot*1000,team*51000|off=0x83c74|str w21, [x8, x9]] */
                }
                iVar23 = func_0x00a5fe34(lVar31,uVar30 & 0xffffffff);  /* 0x95fe34:[slot*1000,team*51000|off=0x83b10|ldr w0, [x8, x9]] */
                if ((iVar23 < 1) ||
                   (iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff), iVar23 != 0)) {  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                  iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff);  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                  if ((iVar23 == 1) ||
                     (iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff), iVar23 == 2)) {  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                    func_0x00a61140(lVar31,uVar30 & 0xffffffff,0);  /* 0x961140:[slot*1000,team*51000|off=0x83b1c|str w21, [x8, x9]] */
                    iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff);  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                    if (iVar23 == 1) {
                      uVar33 = func_0x0044c16c();
                      uVar34 = 0x48;
LAB_006ca328:
                      func_0x0044e364(uVar33,uVar34);
                    }
                    else {
                      iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff);  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                      if (iVar23 == 2) {
                        uVar33 = func_0x0044c16c();
                        uVar34 = 0x46;
                        goto LAB_006ca328;
                      }
                    }
                    lVar39 = 0x1e;
                    plVar38 = in_stack_00000100;
                    do {
                      if ((char)*plVar38 == '\0') {
                        func_0x005aa6a8(plVar38);
                        *(char *)plVar38 = '\x01';
                        *(undefined4 *)((long)plVar38 + 4) =
                             *(undefined4 *)
                              ((long)in_stack_00000190 + uVar30 * 1000 + lVar31 * 51000 + 0x83914);
                        *(int *)(plVar38 + 1) =
                             (int)in_stack_00000190[lVar31 * 0x18e7 + uVar30 * 0x7d + 0x10723];
                        iVar23 = func_0x00a60620(lVar31,uVar30 & 0xffffffff);  /* 0x960620:[slot*1000,team*51000|off=0x83b14|ldr w0, [x8, x9]] */
                        *(bool *)(plVar38 + 3) = iVar23 == 2;
                        break;
                      }
                      lVar39 = lVar39 + -1;
                      plVar38 = (long *)((long)plVar38 + 0x1c);
                    } while (lVar39 != 0);
                  }
                }
                else {
                  uVar27 = func_0x00a610f8(lVar31,uVar30 & 0xffffffff);  /* 0x9610f8:[slot*1000,team*51000|off=0x83b1c|ldr w8, [x8, x9]] */
                  if ((uVar27 & 1) == 0) {
                    func_0x00a61140(lVar31,uVar30 & 0xffffffff,1);  /* 0x961140:[slot*1000,team*51000|off=0x83b1c|str w21, [x8, x9]] */
                  }
                  func_0x00a611cc(lVar31,uVar30 & 0xffffffff,0);  /* 0x9611cc:[slot*1000,team*51000|off=0x83b20|str w19, [x8, x9]] */
                  uVar33 = func_0x0044c16c();
                  func_0x0044e364(uVar33,0x47);
                }
                iVar23 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff);  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                if ((iVar23 < 1) ||
                   (iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff), iVar23 != 0)) {  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                  iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                  if ((iVar23 == 1) ||
                     (iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff), iVar23 == 2)) {  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                    func_0x00a618d4(lVar31,uVar30 & 0xffffffff,0);  /* 0x9618d4:[slot*1000,team*51000|off=0x83c08|str w19, [x8, x9]] */
                    iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                    if (iVar23 == 1) {
                      uVar33 = func_0x0044c16c();
                      uVar34 = 0x89;
LAB_006ca478:
                      func_0x0044e364(uVar33,uVar34);
                    }
                    else {
                      iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                      if (iVar23 == 2) {
                        uVar33 = func_0x0044c16c();
                        uVar34 = 0x8b;
                        goto LAB_006ca478;
                      }
                    }
                    lVar39 = 0x1e;
                    plVar38 = in_stack_00000180;
                    do {
                      if ((char)*plVar38 == '\0') {
                        func_0x005aa6c0(plVar38);
                        *(undefined1 *)plVar38 = 1;
                        *(int *)((long)plVar38 + 4) =
                             *(int *)((long)in_stack_00000190 +
                                     uVar30 * 1000 + lVar31 * 51000 + 0x83914);
                        *(int *)(plVar38 + 1) =
                             (int)in_stack_00000190[lVar31 * 0x18e7 + uVar30 * 0x7d + 0x10723] +
                             -0x1a4;
                        iVar23 = func_0x00a61808(lVar31,uVar30 & 0xffffffff);  /* 0x961808:[slot*1000,team*51000|off=0x83c04|ldr w0, [x8, x9]] */
                        *(bool *)(plVar38 + 3) = iVar23 == 2;
                        break;
                      }
                      lVar39 = lVar39 + -1;
                      plVar38 = (long *)((long)plVar38 + 0x1c);
                    } while (lVar39 != 0);
                  }
                }
                else {
                  iVar23 = func_0x00a61894(lVar31,uVar30 & 0xffffffff);  /* 0x961894:[slot*1000,team*51000|off=0x83c08|ldr w0, [x8, x9]] */
                  if (iVar23 == 0) {
                    iVar24 = func_0x00a6177c(lVar31,uVar30 & 0xffffffff);  /* 0x96177c:[slot*1000,team*51000|off=0x83c00|ldr w0, [x8, x9]] */
                    iVar23 = func_0x00a5fec0(lVar31,uVar30 & 0xffffffff);  /* 0x95fec0:[slot*1000,team*51000|off=0x83be8|ldr w0, [x8, x9]] */
                    if (iVar23 < 0) {
                      iVar23 = iVar23 + 1;
                    }
                    uVar25 = 1;
                    if (iVar24 < iVar23 >> 1) {
                      uVar25 = 2;
                    }
                    func_0x00a618d4(lVar31,uVar30 & 0xffffffff,uVar25);  /* 0x9618d4:[slot*1000,team*51000|off=0x83c08|str w19, [x8, x9]] */
                  }
                  func_0x00a61960(lVar31,uVar30 & 0xffffffff,0);  /* 0x961960:[slot*1000,team*51000|off=0x83c0c|str w19, [x8, x9]] */
                  uVar33 = func_0x0044c16c();
                  func_0x0044e364(uVar33,0x88);
                }
              }
              uVar27 = func_0x005ab294();
              if ((uVar27 & 1) != 0) {
                iVar23 = func_0x00a5a93c(lVar31,uVar30 & 0xffffffff);  /* 0x95a93c:[slot*1000,team*51000|off=0x83ca8|ldr w0, [x8, x9]] */
                *(int *)((long)in_stack_00000190 + 0x32cc) =
                     *(int *)((long)in_stack_00000190 + 0x32cc) + iVar23;
                func_0x00a5a97c(lVar31,uVar30 & 0xffffffff,0);  /* 0x95a97c:[slot*1000,team*51000|off=0x83ca8|str w19, [x8, x9]] */
              }
            }
            uVar30 = uVar30 + 1;
          } while (uVar30 != 0x33);
          bVar13 = true;
          lVar31 = 1;
          bVar12 = false;
        } while (bVar36);
        lVar31 = *in_stack_00000088;
        lVar40 = in_stack_00000088[1];
        if (lVar40 != lVar31) {
          uVar32 = 0;
          do {
            puVar51 = *(undefined4 **)(lVar31 + uVar32 * 8);
            if (puVar51[2] == 0) {
              iVar23 = func_0x00a603d4(*puVar51,puVar51[1]);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
              uVar25 = 1;
              if (0 < iVar23) {
                uVar25 = 2;
              }
              lVar31 = *in_stack_00000088;
              *(undefined4 *)(*(long *)(lVar31 + uVar32 * 8) + 8) = uVar25;
              lVar40 = in_stack_00000088[1];
            }
            uVar32 = uVar32 + 1;
          } while (uVar32 < (ulong)(lVar40 - lVar31 >> 3));
        }
        if (in_stack_000000e0[1] != *in_stack_000000e0) {
          lVar40 = 0;
          uVar32 = 0;
          lVar31 = 4;
          do {
            uVar30 = func_0x005aacc8();
            if (((uVar30 & 1) == 0) ||
               (iVar23 = func_0x005aacf0(),
               *(int *)((long)in_stack_00000190 + (long)__DT_JMPREL + (long)iVar23 * 0x1c4 + 0x723c)
               == 0)) {
              iVar24 = func_0x00a5a220(1,0);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
              iVar17 = func_0x00a603d4(1,0);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
              iVar23 = in_stack_000000b8[4];
              iVar21 = func_0x009cbcc8(*in_stack_000000e0 + lVar40);
              if (iVar24 - iVar17 <= (iVar21 * iVar23) / 100) goto LAB_006ca704;
            }
            else {
              uVar25 = func_0x005aad10();
              iVar23 = func_0x00a59b50(1,uVar25);  /* 0x959b50:[slot*1000,team*51000|off=0x83ac8|ldr w0, [x8, x9]] */
              iVar24 = func_0x009cbcc8(*in_stack_000000e0 + lVar40);
              if (iVar24 <= iVar23) {
LAB_006ca704:
                iVar23 = func_0x009cbca8(*in_stack_000000e0 + lVar40);
                if (((iVar23 == 0) ||
                    (iVar23 = *(int *)(*in_stack_000000e8 + lVar31),
                    iVar24 = func_0x009cbca8(*in_stack_000000e0 + lVar40), iVar23 < iVar24)) &&
                   (bVar14 = func_0x009cbce8(*in_stack_000000e0 + lVar40),
                   (bVar14 & 1 < in_stack_000000b8[5]) == 1)) {
                  *(undefined1 *)(in_stack_00000190 + 0x72501) = 1;
                }
              }
            }
            uVar32 = uVar32 + 1;
            lVar31 = lVar31 + 0xc;
            lVar40 = lVar40 + 0x38;
            uVar30 = (in_stack_000000e0[1] - *in_stack_000000e0 >> 3) * 0x6db6db6db6db6db7;
          } while (uVar32 <= uVar30 && uVar30 - uVar32 != 0);
        }
        uVar32 = func_0x005aacc8();
        if ((uVar32 & 1) != 0) {
          uVar25 = func_0x005aad10();
          uVar15 = func_0x00a5a220(1,uVar25);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
          func_0x00a5a260(1,0,uVar15);  /* 0x95a260:[slot*1000,team*51000|off=0x83928|str w19, [x8, x9]] */
          uVar15 = func_0x00a5a194(1,uVar25);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
          func_0x00a5a1d4(1,0,uVar15);  /* 0x95a1d4:[slot*1000,team*51000|off=0x83924|str w19, [x8, x9]] */
          uVar25 = func_0x00a603d4(1,uVar25);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
          func_0x00a60414(1,0,uVar25);  /* 0x960414:[slot*1000,team*51000|off=0x83954,0x83b90|str w19, [x8, x9] ; str w19, [x8, x9]] */
        }
        uVar53 = 0;
        lVar31 = 0;
        uVar19 = 0;
        iVar23 = 1;
        do {
          in_stack_00000188 = (long *)CONCAT44(in_stack_00000188._4_4_,iVar23);
          uVar32 = 0;
          lVar40 = lVar31 * 0x18;
          in_stack_00000300 = 0;
          in_stack_00000310 = 0;
          do {
            if ((int)in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10721] != 0) {
              iVar24 = func_0x00a603d4(lVar31,uVar32 & 0xffffffff);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
              if (iVar24 != 0) {
                uVar20 = func_0x005aacc8();
                if (((uVar53 & uVar20) != 0) &&
                   ((uVar32 == 0 || (uVar30 = func_0x005aad10(), uVar32 == (uVar30 & 0xffffffff)))))
                {
                  uVar25 = func_0x005aad10();
                  uVar30 = func_0x00a5fc78(1,uVar25);  /* 0x95fc78:[slot*1000,team*51000|off=0x83ac4|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) goto LAB_006ca938;
                }
                bVar13 = uVar32 == 0;
                if (!bVar13 && uVar53 == 1) {
                  uVar30 = func_0x005aad10();
                  bVar13 = uVar32 == (uVar30 & 0xffffffff);
                }
                uVar25 = 2;
                if (bVar13) {
                  uVar25 = 3;
                }
                func_0x006ee0f4(in_stack_00000190 + 0x1c,lVar31,uVar25);
              }
LAB_006ca938:
              iVar24 = func_0x00a603d4(lVar31,uVar32 & 0xffffffff);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
              puVar35 = (undefined8 *)(&stack0x00000338 + lVar40);
              if (iVar24 == 0) {
                while (puVar29 = (undefined8 *)*puVar35, puVar56 = puVar35,
                      (undefined8 *)*puVar35 != (undefined8 *)0x0) {
                  while (puVar35 = puVar29, (long)*(int *)((long)puVar35 + 0x1c) <= (long)uVar32) {
                    if ((long)uVar32 <= (long)*(int *)((long)puVar35 + 0x1c)) {
                      cVar4 = *(char *)(puVar35 + 4);
                      goto joined_r0x006ca9dc;
                    }
                    puVar29 = (undefined8 *)puVar35[1];
                    if ((undefined8 *)puVar35[1] == (undefined8 *)0x0) {
                      puVar56 = puVar35 + 1;
                      goto LAB_006ca978;
                    }
                  }
                }
LAB_006ca978:
                puVar29 = (undefined8 *)func_0x00bc3330(0x28);
                *(int *)((long)puVar29 + 0x1c) = (int)uVar32;
                *(undefined1 *)(puVar29 + 4) = 0;
                *puVar29 = 0;
                puVar29[1] = 0;
                puVar29[2] = puVar35;
                *puVar56 = puVar29;
                lVar39 = **(long **)(&stack0x00000330 + lVar40);
                puVar35 = puVar29;
                if (lVar39 != 0) {
                  *(long *)(&stack0x00000330 + lVar40) = lVar39;
                  puVar35 = (undefined8 *)*puVar56;
                }
                func_0x0040a8c0(*(undefined8 *)(&stack0x00000338 + lVar40),puVar35);
                *(long *)(&stack0x00000340 + lVar40) = *(long *)(&stack0x00000340 + lVar40) + 1;
                cVar4 = *(char *)(puVar29 + 4);
joined_r0x006ca9dc:
                if (cVar4 == '\0') goto LAB_006ca888;
              }
              if ((iVar23 != 0 || uVar32 != 0) || (uVar30 = func_0x005aacc8(), (uVar30 & 1) == 0)) {
                uVar30 = func_0x00a606f4(lVar31,uVar32 & 0xffffffff);  /* 0x9606f4:[slot*1000,team*51000|off=0x839a0|ldr w8, [x8, x9]] */
                if (((uVar30 & 1) == 0) &&
                   (((uVar30 = func_0x00a61494(lVar31,uVar32 & 0xffffffff), (uVar30 & 1) == 0 &&  /* 0x961494:[slot*1000,team*51000|off=0x83ba0|ldr w8, [x8, x9]] */
                     (uVar30 = func_0x00a616e8(lVar31,uVar32 & 0xffffffff), (uVar30 & 1) == 0)) &&  /* 0x9616e8:[slot*1000,team*51000|off=0x83bbc|ldr w8, [x8, x9]] */
                    (uVar30 = func_0x00a61bc0(lVar31,uVar32 & 0xffffffff), (uVar30 & 1) == 0)))) {  /* 0x961bc0:[slot*1000,team*51000|off=0x83c74|ldr w8, [x8, x9]] */
LAB_006cae10:
                  *(undefined4 *)(in_stack_00000190 + lVar31 * 0x70 + uVar32 * 2 + 0x138ef) = 0xc;
                }
                else {
                  uVar30 = func_0x00a606f4(lVar31,uVar32 & 0xffffffff);  /* 0x9606f4:[slot*1000,team*51000|off=0x839a0|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    unaff_x22 = (int *)0x0;
                    plVar38 = in_stack_00000108;
                    do {
                      if ((char)*plVar38 == '\0') {
                        pcVar1 = (char *)((long)plVar38 + 0xc);
                        pcVar1[0] = '\0';
                        pcVar1[1] = '\0';
                        pcVar1[2] = '\0';
                        pcVar1[3] = '\0';
                        *(char *)plVar38 = '\x01';
                        goto LAB_006caa80;
                      }
                      unaff_x22 = (int *)((long)unaff_x22 + 1);
                      plVar38 = plVar38 + 2;
                    } while (unaff_x22 != (int *)0xc8);
                    unaff_x22 = (int *)0x0;
                  }
LAB_006caa80:
                  uVar30 = func_0x00a61494(lVar31,uVar32 & 0xffffffff);  /* 0x961494:[slot*1000,team*51000|off=0x83ba0|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    if (uVar32 == 0) {
                      iVar24 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                      iVar21 = func_0x0043ea60(0x19);
                      iVar24 = iVar24 + iVar17 * 10 + -0x3a9;
                      iVar17 = (int)lVar39 + iVar21 * -10 + -0x497;
                    }
                    else {
                      iVar24 = *(int *)((long)in_stack_00000190 +
                                       uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                      iVar21 = func_0x0043ea60(0x1f);
                      iVar24 = iVar24 + iVar17 * -10 + -0x1b5;
                      iVar17 = (int)lVar39 + iVar21 * 10 + -0x52d;
                    }
                    lVar39 = func_0x00bc3330(0xc);
                    func_0x005aa6cc(lVar39,iVar24,iVar17);
                    plVar38 = (long *)in_stack_00000180[0x6a];
                    if (plVar38 < (long *)in_stack_00000180[0x6b]) {
                      in_stack_000001b8 = 0;
                      plVar26 = plVar38 + 1;
                      *plVar38 = lVar39;
                    }
                    else {
                      in_stack_000001b8 = lVar39;
                      plVar26 = (long *)func_0x006d4f44(in_stack_00000190 + 0x13c9a,&stack0x000001b8
                                                       );
                    }
                    lVar39 = in_stack_000001b8;
                    in_stack_000001b8 = 0;
                    in_stack_00000180[0x6a] = (long)plVar26;
                    if (lVar39 != 0) {
                      func_0x00bc3350(lVar39);
                    }
                  }
                  uVar30 = func_0x00a616e8(lVar31,uVar32 & 0xffffffff);  /* 0x9616e8:[slot*1000,team*51000|off=0x83bbc|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    if (uVar32 == 0) {
                      iVar24 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                      iVar21 = func_0x0043ea60(0x19);
                      iVar24 = iVar24 + iVar17 * 10 + -0x3a9;
                      iVar17 = (int)lVar39 + iVar21 * -10 + -0x497;
                    }
                    else {
                      iVar24 = *(int *)((long)in_stack_00000190 +
                                       uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                      iVar21 = func_0x0043ea60(0x1f);
                      iVar24 = iVar24 + iVar17 * -10 + -0x1b5;
                      iVar17 = (int)lVar39 + iVar21 * 10 + -0x52d;
                    }
                    lVar39 = func_0x00bc3330(0xc);
                    func_0x005aa6cc(lVar39,iVar24,iVar17);
                    plVar38 = (long *)in_stack_00000180[0x6d];
                    if (plVar38 < (long *)in_stack_00000180[0x6e]) {
                      in_stack_000001b8 = 0;
                      plVar26 = plVar38 + 1;
                      *plVar38 = lVar39;
                    }
                    else {
                      in_stack_000001b8 = lVar39;
                      plVar26 = (long *)func_0x006d4f44(in_stack_00000190 + 0x13c9d,&stack0x000001b8
                                                       );
                    }
                    lVar39 = in_stack_000001b8;
                    in_stack_000001b8 = 0;
                    in_stack_00000180[0x6d] = (long)plVar26;
                    if (lVar39 != 0) {
                      func_0x00bc3350(lVar39);
                    }
                  }
                  uVar30 = func_0x00a61bc0(lVar31,uVar32 & 0xffffffff);  /* 0x961bc0:[slot*1000,team*51000|off=0x83c74|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    if (uVar32 == 0) {
                      iVar24 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                      iVar21 = func_0x0043ea60(0x19);
                      iVar24 = iVar24 + iVar17 * 10 + -0x3a9;
                      iVar17 = (int)lVar39 + iVar21 * -10 + -0x497;
                    }
                    else {
                      iVar24 = *(int *)((long)in_stack_00000190 +
                                       uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                      iVar17 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                      iVar21 = func_0x0043ea60(0x1f);
                      iVar24 = iVar24 + iVar17 * -10 + -0x1b5;
                      iVar17 = (int)lVar39 + iVar21 * 10 + -0x52d;
                    }
                    lVar39 = func_0x00bc3330(0xc);
                    func_0x005aa6cc(lVar39,iVar24,iVar17);
                    plVar38 = (long *)in_stack_00000180[0x70];
                    if (plVar38 < (long *)in_stack_00000180[0x71]) {
                      in_stack_000001b8 = 0;
                      plVar26 = plVar38 + 1;
                      *plVar38 = lVar39;
                    }
                    else {
                      in_stack_000001b8 = lVar39;
                      plVar26 = (long *)func_0x006d4f44(in_stack_00000190 + 0x13ca0,&stack0x000001b8
                                                       );
                    }
                    lVar39 = in_stack_000001b8;
                    in_stack_000001b8 = 0;
                    in_stack_00000180[0x70] = (long)plVar26;
                    if (lVar39 != 0) {
                      func_0x00bc3350(lVar39);
                    }
                    goto LAB_006cae10;
                  }
                }
                iVar24 = (int)unaff_x22;
                if (uVar32 == 0) {
                  uVar30 = func_0x00a606f4(lVar31,0);  /* 0x9606f4:[slot*1000,team*51000|off=0x839a0|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    iVar17 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                    iVar21 = func_0x0043ea60(0x2e);
                    lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                    *(int *)((long)in_stack_00000190 + (long)iVar24 * 0x10 + 0x9cfe4) =
                         iVar17 + iVar21 * 10 + -0x3a9;
                    iVar17 = func_0x0043ea60(0x19);
                    *(int *)(in_stack_00000190 + (long)iVar24 * 2 + 0x139fd) =
                         (int)lVar39 + iVar17 * -10 + -0x497;
                  }
                  iVar24 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                  iVar17 = func_0x0043ea60(0x2e);
                  lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                  *(int *)((long)in_stack_00000190 + lVar31 * 0x380 + 0x9c77c) =
                       iVar24 + iVar17 * 10 + -0x3a9;
                  iVar24 = func_0x0043ea60(0x19);
                  lVar3 = in_stack_00000190[lVar31 * 0x18e7 + 0x10751];
                  uVar19 = *(uint *)((long)in_stack_00000190 + lVar31 * 51000 + 0x8390c);
                  *(int *)(in_stack_00000190 + lVar31 * 0x70 + 0x138f0) =
                       (int)lVar39 + iVar24 * -10 + -0x497;
                  *(uint *)((long)in_stack_00000190 + lVar31 * 0x380 + 0x9c784) =
                       (uint)((int)lVar3 == 1);
                  if (uVar19 < 2) {
                    *(undefined8 *)((long)in_stack_00000190 + lVar31 * 51000 + 0x8390c) = unaff_d10;
                  }
                  if (iVar23 != 0) {
                    func_0x005b095c(in_stack_00000190 + 0x21a,0);
                  }
                  uVar19 = 2;
                }
                else {
                  if (uVar19 < 2) {
                    uVar19 = 1;
                  }
                  if ((iVar23 == 0) && (uVar30 = func_0x005aad10(), uVar32 == (uVar30 & 0xffffffff))
                     ) {
                    func_0x00a61a40(1,uVar32 & 0xffffffff,4);  /* 0x961a40:[slot*1000,team*51000|off=0x83c14|str w19, [x8, x9]] */
                    uVar19 = 2;
                  }
                  uVar30 = func_0x00a606f4(lVar31,uVar32 & 0xffffffff);  /* 0x9606f4:[slot*1000,team*51000|off=0x839a0|ldr w8, [x8, x9]] */
                  if ((uVar30 & 1) != 0) {
                    iVar17 = *(int *)((long)in_stack_00000190 +
                                     uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                    iVar21 = func_0x0043ea60(0x2e);
                    lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                    *(int *)((long)in_stack_00000190 + (long)iVar24 * 0x10 + 0x9cfe4) =
                         iVar17 + iVar21 * -10 + -0x1b5;
                    iVar17 = func_0x0043ea60(0x1f);
                    *(int *)(in_stack_00000190 + (long)iVar24 * 2 + 0x139fd) =
                         (int)lVar39 + iVar17 * 10 + -0x52d;
                  }
                  iVar24 = *(int *)((long)in_stack_00000190 +
                                   uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                  iVar17 = func_0x0043ea60(0x2e);
                  lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                  *(int *)((long)in_stack_00000190 + uVar32 * 0x10 + lVar31 * 0x380 + 0x9c77c) =
                       iVar24 + iVar17 * -10 + -0x1b5;
                  iVar24 = func_0x0043ea60(0x1f);
                  *(int *)(in_stack_00000190 + lVar31 * 0x70 + uVar32 * 2 + 0x138f0) =
                       (int)lVar39 + iVar24 * 10 + -0x52d;
                  *(int *)((long)in_stack_00000190 + uVar32 * 0x10 + lVar31 * 0x380 + 0x9c784) =
                       (int)in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10751];
                }
                iVar24 = func_0x00a5a220(lVar31,uVar32 & 0xffffffff);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                uVar30 = func_0x00a5fc78(lVar31,uVar32 & 0xffffffff);  /* 0x95fc78:[slot*1000,team*51000|off=0x83ac4|ldr w8, [x8, x9]] */
                if ((uVar30 & 1) == 0) {
                  iVar17 = func_0x00a603d4(lVar31,uVar32 & 0xffffffff);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
                  func_0x00a5a2ac(lVar31,uVar32 & 0xffffffff,-iVar17);  /* 0x95a2ac:[slot*1000,team*51000|off=0x83928|ldr w10, [x8, x9] ; str w10, [x8, x9]] */
                }
                if ((iVar23 != 0) && (iVar17 = func_0x00a61d34(0,uVar32 & 0xffffffff), 0 < iVar17))  /* 0x961d34:[slot*1000,team*51000|off=0x83ce8|ldr w0, [x8, x9]] */
                {
                  uVar30 = BattleFn_0x004ab2d8(0,uVar32 & 0xffffffff);
                  uVar30 = uVar30 & 0xffffffff;
                  iVar17 = func_0x005b21ec(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,uVar30);
                  if (0 < iVar17) {
                    iVar17 = func_0x00a61d34(0,uVar32 & 0xffffffff);  /* 0x961d34:[slot*1000,team*51000|off=0x83ce8|ldr w0, [x8, x9]] */
                    uVar30 = -(uVar30 >> 0x1f) & 0xfffffffc00000000 | uVar30 << 2;
                    *(int *)(&stack0x00000300 + uVar30) =
                         *(int *)(&stack0x00000300 + uVar30) + iVar17;
                    if (uVar32 == 0) {
                      iVar17 = *(int *)((long)in_stack_00000190 + lVar31 * 51000 + 0x83914);
                      iVar21 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[lVar31 * 0x18e7 + 0x10723];
                      iVar22 = func_0x0043ea60(0x19);
                      iVar17 = iVar17 + iVar21 * 10 + -0x3a9;
                      iVar21 = (int)lVar39 + iVar22 * -10 + -0x497;
                    }
                    else {
                      iVar17 = *(int *)((long)in_stack_00000190 + uVar32 * 1000 + 0x83914);
                      iVar21 = func_0x0043ea60(0x2e);
                      lVar39 = in_stack_00000190[uVar32 * 0x7d + 0x10723];
                      iVar22 = func_0x0043ea60(0x1f);
                      iVar17 = iVar17 + iVar21 * -10 + -0x1b5;
                      iVar21 = (int)lVar39 + iVar22 * 10 + -0x52d;
                    }
                    lVar39 = func_0x00bc3330(0xc);
                    func_0x005aa6cc(lVar39,iVar17,iVar21);
                    plVar38 = (long *)in_stack_00000180[0x73];
                    if (plVar38 < (long *)in_stack_00000180[0x74]) {
                      in_stack_000001b8 = 0;
                      plVar26 = plVar38 + 1;
                      *plVar38 = lVar39;
                    }
                    else {
                      in_stack_000001b8 = lVar39;
                      plVar26 = (long *)func_0x006d4f44(in_stack_00000190 + 0x13ca3,&stack0x000001b8
                                                       );
                    }
                    lVar39 = in_stack_000001b8;
                    in_stack_000001b8 = 0;
                    in_stack_00000180[0x73] = (long)plVar26;
                    if (lVar39 != 0) {
                      func_0x00bc3350(lVar39);
                    }
                  }
                }
                if (((iVar23 == 0 && uVar32 == 0) && (char)in_stack_00000190[0x72501] != '\0') &&
                   (iVar17 = func_0x00a5a220(1,0), iVar17 < 1)) {  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                  func_0x00a5a260(1,0,1);  /* 0x95a260:[slot*1000,team*51000|off=0x83928|str w19, [x8, x9]] */
                }
                lVar39 = uVar32 * 1000 + lVar31 * 51000;
                if ((((0 < *(int *)((long)in_stack_00000190 + lVar39 + 0x83a2c)) &&
                     (uVar33 = func_0x0043ea60(100),
                     (int)uVar33 <= *(int *)((long)in_stack_00000190 + lVar39 + 0x83a2c))) &&
                    ((int)in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10725] < 1)) &&
                   (lVar39 = uVar32 * 1000 + lVar31 * 51000,
                   *(int *)((long)in_stack_00000190 + lVar39 + 0x83a3c) == 0)) {
                  *(undefined4 *)(in_stack_00000190 + lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10725) = 1
                  ;
                  *(undefined4 *)((long)in_stack_00000190 + lVar39 + 0x83a3c) = 1;
                  func_0x006ce4cc(uVar33,lVar31,uVar32 & 0xffffffff,3);
                  uVar33 = func_0x0044c16c();
                  func_0x0044e35c(uVar33,0x32,0);
                }
                plVar38 = in_stack_00000190 + lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10725;
                if ((int)*plVar38 < 1) {
                  *(int *)plVar38 = 0;
                  if (iVar23 != 0) {
                    *(int *)(in_stack_00000190 + 0x21f) = (int)in_stack_00000190[0x21f] + 1;
                    goto joined_r0x006cb4c0;
                  }
                  iVar17 = func_0x00a58934(1,uVar32 & 0xffffffff);  /* 0x958934:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
                  plVar28 = (long *)*in_stack_00000110;
                  plVar26 = in_stack_00000110;
                  if (plVar28 != (long *)0x0) {
                    do {
                      plVar69 = plVar28 + 1;
                      if (iVar17 <= *(int *)((long)plVar28 + 0x1c)) {
                        plVar26 = plVar28;
                        plVar69 = plVar28;
                      }
                      plVar28 = (long *)*plVar69;
                    } while (plVar28 != (long *)0x0);
                    if (plVar26 != in_stack_00000110) {
                      plVar28 = in_stack_00000110;
                      if (*(int *)((long)plVar26 + 0x1c) <= iVar17) {
                        plVar28 = plVar26;
                      }
                      if (in_stack_00000110 != plVar28) {
                        iVar17 = func_0x00a58934(1,uVar32 & 0xffffffff);  /* 0x958934:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
                        plVar26 = in_stack_00000110;
                        while (plVar28 = (long *)*plVar26, plVar69 = plVar26,
                              (long *)*plVar26 != (long *)0x0) {
                          while (plVar49 = plVar28, plVar26 = plVar49,
                                *(int *)((long)plVar49 + 0x1c) <= iVar17) {
                            if (iVar17 <= *(int *)((long)plVar49 + 0x1c)) goto LAB_006cb744;
                            plVar28 = (long *)plVar49[1];
                            if ((long *)plVar49[1] == (long *)0x0) {
                              plVar26 = plVar49 + 1;
                              plVar69 = plVar49;
                              goto LAB_006cb6e8;
                            }
                          }
                        }
LAB_006cb6e8:
                        plVar49 = (long *)func_0x00bc3330(0x28);
                        *(int *)((long)plVar49 + 0x1c) = iVar17;
                        *(undefined4 *)(plVar49 + 4) = 0;
                        *plVar49 = 0;
                        plVar49[1] = 0;
                        plVar49[2] = (long)plVar69;
                        *plVar26 = (long)plVar49;
                        plVar28 = plVar49;
                        if (*(long *)*in_stack_000000d0 != 0) {
                          *in_stack_000000d0 = *(long *)*in_stack_000000d0;
                          plVar28 = (long *)*plVar26;
                        }
                        func_0x0040a8c0(in_stack_000000d0[1],plVar28);
                        in_stack_000000d0[2] = in_stack_000000d0[2] + 1;
LAB_006cb744:
                        *(int *)(plVar49 + 4) = (int)plVar49[4] + 1;
                        goto joined_r0x006cb4c0;
                      }
                    }
                  }
                  iVar17 = func_0x00a58934(1,uVar32 & 0xffffffff);  /* 0x958934:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
                  plVar26 = in_stack_00000110;
                  while (plVar28 = (long *)*plVar26, plVar69 = plVar26,
                        (long *)*plVar26 != (long *)0x0) {
                    while (plVar49 = plVar28, plVar26 = plVar49,
                          *(int *)((long)plVar49 + 0x1c) <= iVar17) {
                      if (iVar17 <= *(int *)((long)plVar49 + 0x1c)) goto LAB_006cb7b4;
                      plVar28 = (long *)plVar49[1];
                      if ((long *)plVar49[1] == (long *)0x0) {
                        plVar26 = plVar49 + 1;
                        plVar69 = plVar49;
                        goto LAB_006cb564;
                      }
                    }
                  }
LAB_006cb564:
                  plVar49 = (long *)func_0x00bc3330(0x28);
                  *(int *)((long)plVar49 + 0x1c) = iVar17;
                  *(undefined4 *)(plVar49 + 4) = 0;
                  *plVar49 = 0;
                  plVar49[1] = 0;
                  plVar49[2] = (long)plVar69;
                  *plVar26 = (long)plVar49;
                  plVar28 = plVar49;
                  if (*(long *)*in_stack_000000d0 != 0) {
                    *in_stack_000000d0 = *(long *)*in_stack_000000d0;
                    plVar28 = (long *)*plVar26;
                  }
                  func_0x0040a8c0(in_stack_000000d0[1],plVar28);
                  in_stack_000000d0[2] = in_stack_000000d0[2] + 1;
LAB_006cb7b4:
                  *(undefined4 *)(plVar49 + 4) = 1;
                  if (uVar32 != 0) goto LAB_006cb3c8;
                }
                else {
joined_r0x006cb4c0:
                  if (uVar32 == 0) goto LAB_006cb918;
LAB_006cb3c8:
                  iVar17 = func_0x00a603d4(lVar31,uVar32 & 0xffffffff);  /* 0x9603d4:[slot*1000,team*51000|off=0x83954|ldr w0, [x8, x9]] */
                  if (iVar17 == 0) goto LAB_006cb918;
                  if (((iVar23 == 0) && (uVar30 = func_0x005aacc8(), (uVar30 & 1) != 0)) &&
                     (uVar30 = func_0x005aad10(), uVar32 == (uVar30 & 0xffffffff))) {
LAB_006cb924:
                    uVar30 = func_0x005aad10();
                    if (uVar32 == (uVar30 & 0xffffffff)) {
LAB_006cb930:
                      lVar39 = (long)in_stack_00000190 +
                               (long)(int)in_stack_00000190[0x777bd] * 0xbc;
                      if (CONCAT13((&UNK_00383803)[lVar39] ^ (&UNK_00383757)[lVar39],  /* field_off=0x383803 ; field_off=0x383757 */
                                   CONCAT12((&UNK_00383802)[lVar39] ^ (&UNK_00383756)[lVar39],  /* field_off=0x383802 ; field_off=0x383756 */
                                            CONCAT11((&UNK_00383801)[lVar39] ^  /* field_off=0x383801 */
                                                     (&UNK_00383755)[lVar39],  /* field_off=0x383755 */
                                                     (&UNK_00383800)[lVar39] ^  /* field_off=0x383800 */
                                                     (&UNK_00383754)[lVar39]))) - 1U < 99) {  /* field_off=0x383754 */
                        iVar17 = func_0x00a5a194(1,uVar32 & 0xffffffff);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
                        lVar39 = (long)in_stack_00000190 +
                                 (long)(int)in_stack_00000190[0x777bd] * 0xbc;
                        iVar17 = (int)(((uint)(byte)((&UNK_00383802)[lVar39] ^  /* field_off=0x383802 */
                                                    (&UNK_00383756)[lVar39]) << 0x10 |  /* field_off=0x383756 */
                                        (uint)(byte)((&UNK_00383803)[lVar39] ^  /* field_off=0x383803 */
                                                    (&UNK_00383757)[lVar39]) << 0x18 |  /* field_off=0x383757 */
                                        (uint)(byte)((&UNK_00383801)[lVar39] ^  /* field_off=0x383801 */
                                                    (&UNK_00383755)[lVar39]) << 8 |  /* field_off=0x383755 */
                                       (uint)(byte)((&UNK_00383800)[lVar39] ^  /* field_off=0x383800 */
                                                   (&UNK_00383754)[lVar39])) * iVar17) / 100;  /* field_off=0x383754 */
                        if ((iVar17 < iVar24) &&
                           (iVar24 = func_0x00a5a220(1,uVar32 & 0xffffffff), iVar24 <= iVar17)) {  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                          lVar39 = (long)in_stack_00000190 +
                                   (long)(int)in_stack_00000190[0x777bd] * 0xbc;
                          bVar14 = (&UNK_0038375a)[lVar39];  /* field_off=0x38375a */
                          bVar5 = (&UNK_00383802)[lVar39];  /* field_off=0x383802 */
                          bVar6 = (&UNK_0038375b)[lVar39];  /* field_off=0x38375b */
                          bVar7 = (&UNK_00383803)[lVar39];  /* field_off=0x383803 */
                          bVar8 = (&UNK_00383759)[lVar39];  /* field_off=0x383759 */
                          bVar9 = (&UNK_00383801)[lVar39];  /* field_off=0x383801 */
                          bVar10 = (&UNK_00383758)[lVar39];  /* field_off=0x383758 */
                          bVar11 = (&UNK_00383800)[lVar39];  /* field_off=0x383800 */
                          *(undefined8 *)in_stack_000000a0 = unaff_d8;
                          in_stack_000000a0[2] = 0x2d;
                          in_stack_000000a0[3] =
                               (uint)(bVar5 ^ bVar14) << 0x10 | (uint)(bVar7 ^ bVar6) << 0x18 |
                               (uint)(bVar9 ^ bVar8) << 8 | (uint)(bVar11 ^ bVar10);
                          in_stack_000000a0[4] = 1;
                          uVar33 = func_0x0044c16c();
                          func_0x0044e014(uVar33,0xffffffff);
                        }
                      }
                    }
                    goto LAB_006ca888;
                  }
                  iVar21 = func_0x00a5a194(lVar31,uVar32 & 0xffffffff);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
                  iVar22 = func_0x00a5a300(lVar31,uVar32 & 0xffffffff);  /* 0x95a300:[slot*1000,team*51000|off=0x8392c|ldr w0, [x8, x9]] */
                  lVar39 = uVar32 * 1000 + lVar31 * 51000;
                  iVar17 = *(int *)((long)in_stack_00000190 + lVar39 + 0x8392c);
                  if (iVar17 < 1) {
                    iVar47 = 0;
LAB_006cb5b8:
                    iVar46 = 0;
                  }
                  else {
                    iVar46 = 0;
                    do {
                      iVar47 = iVar46;
                      if ((float)(int)*plVar38 <= ((float)iVar21 / (float)iVar22) * (float)iVar46)
                      break;
                      iVar46 = iVar46 + 1;
                      iVar47 = iVar17;
                    } while (iVar17 != iVar46);
                    if (iVar17 < 1) goto LAB_006cb5b8;
                    iVar54 = 0;
                    do {
                      iVar46 = iVar54;
                      if ((float)iVar24 <= ((float)iVar21 / (float)iVar22) * (float)iVar54) break;
                      iVar54 = iVar54 + 1;
                      iVar46 = iVar17;
                    } while (iVar17 != iVar54);
                  }
                  iVar17 = func_0x00a58ba4(lVar31,uVar32 & 0xffffffff);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
                  if ((iVar17 != 4) &&
                     (iVar17 = func_0x00a58ba4(lVar31,uVar32 & 0xffffffff), iVar17 != 0x15)) {  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
                    if (((iVar47 == iVar46) ||
                        (iVar47 == *(int *)((long)in_stack_00000190 + lVar39 + 0x8392c))) &&
                       (*(int *)((long)in_stack_00000190 + uVar32 * 1000 + lVar31 * 51000 + 0x83a3c)
                        != 1)) {
                      iVar17 = func_0x00a6126c(lVar31,uVar32 & 0xffffffff);  /* 0x96126c:[slot*1000,team*51000|off=0x83b34|ldr w0, [x8, x9]] */
                      if ((0 < iVar17) &&
                         (iVar17 = func_0x00a5a220(lVar31,uVar32 & 0xffffffff), 0 < iVar17)) {  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                        func_0x00a58be4(lVar31,uVar32 & 0xffffffff,0x12);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                        func_0x00a590fc(lVar31,uVar32 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                        uVar33 = func_0x0044c16c();
                        func_0x0044e364(uVar33,0x49);
                        goto LAB_006cb918;
                      }
                      uVar30 = func_0x00a59908(lVar31,uVar32 & 0xffffffff);  /* 0x959908:[slot*1000,team*51000|off=0x83964|ldr w8, [x8, x9]] */
                      if ((uVar30 & 1) == 0) {
                        uVar30 = func_0x00a60788(lVar31,uVar32 & 0xffffffff);  /* 0x960788:[slot*1000,team*51000|off=0x839f8|ldr w8, [x8, x9]] */
                        if ((uVar30 & 1) == 0) goto LAB_006cb908;
                        uVar33 = 6;
                      }
                      else {
                        uVar33 = 5;
                      }
                      func_0x00a58be4(lVar31,uVar32 & 0xffffffff,uVar33);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                      func_0x00a590fc(lVar31,uVar32 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                    }
                    else {
                      func_0x00a58be4(lVar31,uVar32 & 0xffffffff,3);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                      func_0x00a590fc(lVar31,uVar32 & 0xffffffff,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
                      uVar30 = func_0x00a62554(lVar31,uVar32 & 0xffffffff);  /* 0x962554:[slot*1000,team*0x1f0,team*51000|off=0x83ab4|ldr w8, [x8, x9]] */
                      if (((uVar30 & 1) != 0) &&
                         (iVar17 = func_0x00a5a220(lVar31,uVar32 & 0xffffffff), iVar17 == 0)) {  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
                        func_0x00a626a4(lVar31,uVar32 & 0xffffffff,1);  /* 0x9626a4:[slot*1000,team*0x1f0,team*51000|off=0x83ad0|str w20, [x8, x9]] */
                        lVar39 = 0x1e;
                        plVar38 = in_stack_00000070;
                        do {
                          if ((char)*plVar38 == '\0') {
                            func_0x005aa690(plVar38);
                            *(char *)plVar38 = '\x01';
                            iVar17 = *(int *)((long)in_stack_00000190 +
                                             uVar32 * 1000 + lVar31 * 51000 + 0x83914);
                            iVar21 = func_0x0043ea60(0x2e);
                            *(int *)((long)plVar38 + 4) = iVar17 + iVar21 * -10 + 0xfa;
                            lVar39 = in_stack_00000190[lVar31 * 0x18e7 + uVar32 * 0x7d + 0x10723];
                            iVar17 = func_0x0043ea60(0x1f);
                            *(int *)(plVar38 + 1) = (int)lVar39 + iVar17 * 10 + -0x96;
                            uVar33 = func_0x0044c16c();
                            func_0x0044e364(uVar33,0x3b);
                            break;
                          }
                          lVar39 = lVar39 + -1;
                          plVar38 = plVar38 + 2;
                        } while (lVar39 != 0);
                      }
                      lVar39 = uVar32 * 1000 + lVar31 * 51000;
                      if (*(int *)((long)in_stack_00000190 + lVar39 + 0x83a04) == 1) {
                        *(undefined4 *)((long)in_stack_00000190 + lVar39 + 0x83a04) = 2;
                      }
                      lVar39 = uVar32 * 1000 + lVar31 * 51000;
                      if (*(int *)((long)in_stack_00000190 + lVar39 + 0x83a3c) == 1) {
                        *(undefined4 *)((long)in_stack_00000190 + lVar39 + 0x83a3c) = 2;
                      }
                    }
LAB_006cb908:
                    func_0x00a612ac(lVar31,uVar32 & 0xffffffff,0);  /* 0x9612ac:[slot*1000,team*51000|off=0x83b34|str w19, [x8, x9]] */
                  }
                }
LAB_006cb918:
                if (iVar23 == 0) {
                  if (uVar32 != 0) goto LAB_006cb924;
                  goto LAB_006cb930;
                }
              }
            }
LAB_006ca888:
            uVar32 = uVar32 + 1;
          } while (uVar32 != 0x33);
          uVar32 = 0;
          lVar40 = lVar31 * 0x1f0 + 0x27f0;
          do {
            uVar53 = *(uint *)(&stack0x00000300 + uVar32 * 4);
            unaff_x28 = (long *)(ulong)uVar53;
            if (uVar53 != 0) {
              iVar24 = func_0x0057aa0c(lVar31,uVar32 & 0xffffffff);
              iVar17 = func_0x005b21ec(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,uVar32 & 0xffffffff
                                      );
              if (*(int *)((long)in_stack_00000190 + uVar32 * 4 + lVar40) == 0) {
LAB_006cbb68:
                uVar25 = func_0x005b21ec(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,
                                         uVar32 & 0xffffffff);
                func_0x005b235c(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,uVar32 & 0xffffffff,uVar25
                               );
              }
              else {
                iVar21 = func_0x005b2314(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,
                                         uVar32 & 0xffffffff);
                iVar22 = func_0x005b21ec(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,
                                         uVar32 & 0xffffffff);
                if (iVar22 < iVar21) goto LAB_006cbb68;
              }
              iVar21 = (int)((ulong)((long)(int)((iVar24 - iVar17) * uVar53) * -0x51eb851f) >> 0x20)
              ;
              iVar17 = func_0x0043ed6c(((iVar21 >> 5) - (iVar21 >> 0x1f)) + (iVar24 - iVar17),0);
              func_0x005b2234(in_stack_00000190 + lVar31 * 0x3e + 0x4c9,uVar32 & 0xffffffff,
                              iVar24 - iVar17,0);
              in_stack_000001a0 = 0x2c;
              uStack00000000000001b7 = 0;
              in_stack_00000158[1] = 0x65677561675f6465;  /* ascii(0x65677561675f6465)='ed_gauge' */
              *in_stack_00000158 = 0x725f656c74746162;  /* ascii(0x725f656c74746162)='battle_r' */
              *(undefined8 *)((long)in_stack_00000158 + 0xe) = 0x656d6172665f6567;  /* ascii(0x656d6172665f6567)='ge_frame' */
              uVar25 = func_0x008e3f14(in_stack_00000190 + 0x28f,&stack0x000001a0,0xf);
              *(undefined4 *)((long)in_stack_00000190 + uVar32 * 4 + lVar40) = uVar25;
              if ((in_stack_000001a0 & 1) != 0) {
                func_0x00bc3350(CONCAT17(uStack00000000000001b7,uStack00000000000001b0));
              }
            }
            uVar32 = uVar32 + 1;
          } while (uVar32 != 10);
          uVar53 = 1;
          lVar31 = 1;
          bVar13 = iVar23 != 0;
          iVar23 = 0;
        } while (bVar13);
        iVar23 = func_0x005ab154();
        if (iVar23 == 0) {
          if (in_stack_000000b8[5] == 0) {
            in_stack_00000050[0xf] = 0;
            in_stack_00000050[0x10] = 0;
            *(undefined8 *)(in_stack_000000a0 + 2) = in_stack_00000008;
            *(undefined8 *)in_stack_000000a0 = in_stack_00000000;
            uVar33 = func_0x00a5a220(0,0);  /* 0x95a220:[slot*1000,team*51000|off=0x83928|ldr w0, [x8, x9]] */
            if ((int)uVar33 == 0) {
              func_0x00a5a260(uVar33,0,1);  /* 0x95a260:[slot*1000,team*51000|off=0x83928|str w19, [x8, x9]] */
            }
            BattleFn_0x004c9224(in_stack_00000190,0);
          }
          else {
            if ((int)in_stack_000000e8[10] != 0) goto LAB_006cbcac;
            in_stack_00000050[0xf] = 0;
            in_stack_00000050[0x10] = 0;
            *(undefined8 *)(in_stack_000000a0 + 2) = in_stack_00000008;
            *(undefined8 *)in_stack_000000a0 = in_stack_00000000;
            func_0x005cfa80(in_stack_00000190);
          }
          func_0x005d0b20(in_stack_00000190);
        }
LAB_006cbcac:
        iVar23 = func_0x005ab154();
        unaff_x19 = in_stack_00000190;
        if (iVar23 == 0) {
          if (uVar19 == 2) {
            uVar33 = func_0x0044c16c();
            iVar23 = 0x16;
LAB_006cbdb4:
            func_0x0044e35c(uVar33,iVar23,0);
          }
          else if (uVar19 == 1) {
            uVar33 = func_0x0044c16c();
            iVar23 = func_0x0043ea60(2);
            iVar23 = iVar23 + 0x14;
            goto LAB_006cbdb4;
          }
          unaff_x23 = 0;
          unaff_w20 = 1;
          break;
        }
      } while( true );
    }
    uVar32 = 0;
    lVar31 = unaff_x23 * 0x1f0 + 0x26b4;
    do {
      iVar23 = func_0x005b21ec(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff);
      if (iVar23 < 1) {
        if (unaff_w20 != 0) goto LAB_006cbea4;
      }
      else {
        iVar23 = func_0x0057aa0c(unaff_x23,uVar32 & 0xffffffff);
        iVar24 = func_0x005b21ec(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff);
        if (iVar23 < iVar24) {
          uVar25 = func_0x0057aa0c(unaff_x23,uVar32 & 0xffffffff);
          func_0x005b2234(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff,uVar25,1);
        }
        else {
          func_0x005b22a4(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff,0xffffffff);
        }
        if (unaff_w20 != 0) {
          iVar23 = func_0x005b21ec(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff);
          if (iVar23 == 0) {
            uVar33 = func_0x0044c16c();
            func_0x0044e35c(uVar33,0x1b,0);
          }
LAB_006cbea4:
          iVar23 = func_0x005abf1c(0,uVar32 & 0xffffffff);
          if ((((1 < iVar23) &&
               (uVar30 = func_0x005b26a4(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,0,uVar32 & 0xffffffff)
               , (uVar30 & 1) != 0)) &&
              (iVar23 = func_0x005b21ec(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar32 & 0xffffffff),
              iVar23 == 0)) &&
             (iVar23 = *(int *)((long)unaff_x19 + lVar31 + 0x9c),
             *(int *)((long)unaff_x19 + lVar31 + 0xec) <= iVar23)) {
            *(int *)((long)unaff_x19 + lVar31 + 0xec) = iVar23 + 1;
            uVar30 = func_0x005b23cc(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,0,uVar32 & 0xffffffff);
            if ((uVar30 & 1) != 0) {
              *(undefined4 *)((long)unaff_x19 + lVar31 + 0x114) = 0;
            }
          }
        }
      }
      if ((*(int *)((long)unaff_x19 + lVar31) == 1) &&
         (iVar23 = *(int *)((long)unaff_x19 + lVar31 + 0x28), 0 < iVar23)) {
        *(int *)((long)unaff_x19 + lVar31 + 0x28) = iVar23 + -1;
      }
      iVar23 = *(int *)((long)unaff_x19 + lVar31 + 0x13c);
      if (0 < iVar23) {
        *(int *)((long)unaff_x19 + lVar31 + 0x13c) = iVar23 + -1;
      }
      uVar32 = uVar32 + 1;
      lVar31 = lVar31 + 4;
    } while (uVar32 != 10);
    lVar31 = func_0x007fd748();
    uVar25 = func_0x007ac230(0);
    uVar32 = func_0x00633464(lVar31 + 0x668,uVar25,0);
    if ((uVar32 & 1) == 0) {
      uVar25 = func_0x005b2028(unaff_x19 + unaff_x23 * 0x3e + 0x4c9);
      BattleFn_0x004b1e64(unaff_x19 + unaff_x23 * 0x3e + 0x4c9,uVar25);
    }
  } while( true );
code_r0x006c8be0:
  iVar24 = func_0x00a5a494(0,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
  bVar13 = iVar24 <= iVar23;
  iVar23 = iVar23 + 1;
  if (bVar13) goto LAB_006c8afc;
  goto LAB_006c8bb4;
LAB_006c9440:
  uVar19 = (int)piVar52 + 1;
  piVar52 = (int *)(ulong)uVar19;
  iVar23 = func_0x00a5a494(1,(ulong)puVar51 & 0xffffffff);  /* 0x95a494:[slot*1000,team*51000|off=0x8395c,0x83aec,0x83af0|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
  if (iVar23 <= (int)uVar19) goto LAB_006c9388;
  goto LAB_006c9458;
}


