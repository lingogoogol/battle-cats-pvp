// ELF VMA: 0x8b99a0
// Ghidra Addr: 0x009b99a0 (ImageBase=0x100000)
// Function: Battle_Sub8B99A0
// Size: 3088 bytes
// Callees (2): Battle_Set_83ad4@0x959ca8, Battle_SpawnOrInitUnit@0x8b6dec, 


/* WARNING: Possible PIC construction at 0x009b9dcc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x009ba33c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x009ba4a0: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d850: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d910: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d980: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0044d854) */
/* WARNING: Removing unreachable block (ram,0x0044d870) */
/* WARNING: Removing unreachable block (ram,0x0044d878) */
/* WARNING: Removing unreachable block (ram,0x0044dbd0) */
/* WARNING: Removing unreachable block (ram,0x0044d894) */
/* WARNING: Removing unreachable block (ram,0x0044dbe0) */
/* WARNING: Removing unreachable block (ram,0x0044d89c) */
/* WARNING: Removing unreachable block (ram,0x0044dbf0) */
/* WARNING: Removing unreachable block (ram,0x0044dc00) */
/* WARNING: Removing unreachable block (ram,0x0044d8a4) */
/* WARNING: Removing unreachable block (ram,0x0044d8ac) */
/* WARNING: Removing unreachable block (ram,0x0044d8b4) */
/* WARNING: Removing unreachable block (ram,0x0044d8c0) */
/* WARNING: Removing unreachable block (ram,0x009ba4a4) */
/* WARNING: Removing unreachable block (ram,0x009ba340) */
/* WARNING: Removing unreachable block (ram,0x0044d914) */
/* WARNING: Removing unreachable block (ram,0x0044d92c) */
/* WARNING: Removing unreachable block (ram,0x0044d934) */
/* WARNING: Removing unreachable block (ram,0x0044dc04) */
/* WARNING: Removing unreachable block (ram,0x0044d950) */
/* WARNING: Removing unreachable block (ram,0x0044dc14) */
/* WARNING: Removing unreachable block (ram,0x0044d958) */
/* WARNING: Removing unreachable block (ram,0x0044dc24) */
/* WARNING: Removing unreachable block (ram,0x0044dc34) */
/* WARNING: Removing unreachable block (ram,0x0044d960) */
/* WARNING: Removing unreachable block (ram,0x0044d968) */
/* WARNING: Removing unreachable block (ram,0x0044d970) */
/* WARNING: Removing unreachable block (ram,0x0044d984) */
/* WARNING: Removing unreachable block (ram,0x0044d998) */
/* WARNING: Removing unreachable block (ram,0x0044d9c4) */
/* WARNING: Removing unreachable block (ram,0x0044d9d4) */
/* WARNING: Removing unreachable block (ram,0x0044d9ec) */
/* WARNING: Removing unreachable block (ram,0x0044d9f4) */
/* WARNING: Removing unreachable block (ram,0x0044da04) */
/* WARNING: Removing unreachable block (ram,0x0044da1c) */
/* WARNING: Removing unreachable block (ram,0x0044dad8) */
/* WARNING: Removing unreachable block (ram,0x0044da2c) */
/* WARNING: Removing unreachable block (ram,0x0044da38) */
/* WARNING: Removing unreachable block (ram,0x0044da54) */
/* WARNING: Removing unreachable block (ram,0x0044da60) */
/* WARNING: Removing unreachable block (ram,0x0044da6c) */
/* WARNING: Removing unreachable block (ram,0x0044da78) */
/* WARNING: Removing unreachable block (ram,0x0044da88) */
/* WARNING: Removing unreachable block (ram,0x0044daa0) */
/* WARNING: Removing unreachable block (ram,0x0044dc38) */
/* WARNING: Removing unreachable block (ram,0x0044ddb8) */
/* WARNING: Removing unreachable block (ram,0x0044dc3c) */
/* WARNING: Removing unreachable block (ram,0x0044ddbc) */
/* WARNING: Removing unreachable block (ram,0x0044daa4) */
/* WARNING: Removing unreachable block (ram,0x0044ddc0) */
/* WARNING: Removing unreachable block (ram,0x0044de10) */
/* WARNING: Removing unreachable block (ram,0x0044dae4) */
/* WARNING: Removing unreachable block (ram,0x0044daec) */
/* WARNING: Removing unreachable block (ram,0x0044daf0) */
/* WARNING: Removing unreachable block (ram,0x0044d978) */
/* WARNING: Removing unreachable block (ram,0x0044dad0) */

long * Battle_Sub8B99A0(long *param_1,uint param_2,uint param_3,ulong param_4,ulong *param_5,
                       undefined *param_6,ulong param_7)

{
  undefined8 *puVar1;
  ulong *puVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  long *plVar14;
  long lVar15;
  ulong uVar16;
  undefined8 uVar17;
  long *plVar18;
  ulong uVar19;
  int extraout_w1;
  byte *pbVar20;
  byte *pbVar21;
  undefined8 uVar22;
  int *piVar23;
  undefined *puVar24;
  int iVar25;
  long *plVar26;
  undefined1 *extraout_x8;
  undefined1 *puVar27;
  uint *puVar28;
  ulong uVar29;
  ulong uVar30;
  ulong *puVar31;
  long *unaff_x19;
  ulong unaff_x20;
  ulong uVar32;
  byte *pbVar33;
  byte *unaff_x21;
  ulong unaff_x22;
  ulong uVar34;
  ulong *unaff_x23;
  ulong *puVar35;
  ulong *unaff_x24;
  ulong *puVar36;
  ulong *unaff_x25;
  ulong *unaff_x26;
  ulong uVar37;
  ulong *unaff_x27;
  ulong *puVar38;
  undefined *unaff_x28;
  undefined1 *unaff_x29;
  undefined8 unaff_x30;
  ulong uVar39;
  long lVar40;
  ulong uVar41;
  ulong uVar42;
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  byte abStack_260 [404];
  uint uStack_cc;
  ulong *puStack_c8;
  ulong uStack_c0;
  long *plStack_b8;
  uint uStack_ac;
  ulong *puStack_a8;
  ulong uStack_a0;
  uint uStack_94;
  ulong *puStack_90;
  byte abStack_88 [16];
  undefined1 uStack_78;
  undefined7 uStack_77;
  int iStack_6c;
  long lStack_68;
  
  puVar27 = &stack0xffffffffffffffa0;
  pbVar21 = (byte *)tpidr_el0;
  uVar32 = (ulong)param_3;
  uVar34 = (ulong)param_2;
  lStack_68 = *(long *)(pbVar21 + 0x28);
  iVar7 = 1;
  uVar10 = (uint)param_4;
  uVar16 = func_0x005aba0c(param_2,param_3,1);
  iVar25 = (int)param_7;
  iVar8 = (int)param_4;
  iVar12 = (int)param_6;
  iVar9 = (int)param_5;
  if ((uVar16 & 1) == 0) {
    lVar40 = 0x20000001e;
LAB_009b9be4:
    param_1[0x520ac] = lVar40;
LAB_009b9be8:
    plVar18 = (long *)func_0x0044c16c();
    if (*(long *)(pbVar21 + 0x28) != lStack_68) {
LAB_009ba588:
      func_0x00bc3380();
      return (long *)(ulong)((uint)((extraout_w1 - iVar9) * (extraout_w1 - iVar9) +
                                   (iVar7 - iVar12) * (iVar7 - iVar12)) <=
                            (uint)((iVar25 + iVar8) * (iVar25 + iVar8)));
    }
    uVar16 = 0xf;
  }
  else {
    uVar16 = func_0x005abee8(uVar34,uVar32);
    iVar25 = (int)param_7;
    iVar8 = (int)param_4;
    iVar12 = (int)param_6;
    iVar9 = (int)param_5;
    if ((uVar16 & 1) == 0) goto LAB_009b9be8;
    uVar4 = func_0x005ad22c(uVar34,uVar32);
    puVar36 = (ulong *)(ulong)uVar4;
    uVar5 = func_0x005aed30(uVar34,uVar32);
    iVar25 = (int)param_7;
    iVar8 = (int)param_4;
    iVar12 = (int)param_6;
    iVar9 = (int)param_5;
    if (((uVar5 & 1) != 0) &&
       (0 < *(int *)((long)param_1 + ((long)(int)param_2 * 0x7c + (long)(int)param_3 + 0x9b7) * 4)))
    goto LAB_009b9be8;
    puVar38 = (ulong *)(param_1 + (long)(int)param_2 * 0x3e);
    puStack_90 = (ulong *)(long)(int)param_2;
    iVar6 = func_0x005b21ec(puVar38 + 0x4c9,uVar32);
    iVar25 = (int)param_7;
    iVar8 = (int)param_4;
    iVar12 = (int)param_6;
    iVar9 = (int)param_5;
    if ((uVar5 & 1) == 0 && iVar6 != 0) goto LAB_009b9be8;
    iVar6 = func_0x005b1bf4(puVar38 + 0x4c9);
    iVar25 = (int)param_7;
    iVar8 = (int)param_4;
    iVar12 = (int)param_6;
    iVar9 = (int)param_5;
    if ((uVar5 & 1) == 0 && iVar6 < (int)uVar4) goto LAB_009b9be8;
    uVar16 = func_0x009aa8cc(param_1 + 0x6770a,uVar32);
    iVar25 = (int)param_7;
    iVar8 = (int)param_4;
    iVar12 = (int)param_6;
    iVar9 = (int)param_5;
    if ((uVar16 & 1) != 0) {
      if ((uVar5 & 1) != 0) {
        iVar7 = 1;
        uVar16 = func_0x005aedfc(param_2,param_3,1);
        iVar25 = (int)param_7;
        iVar8 = (int)param_4;
        iVar12 = (int)param_6;
        iVar9 = (int)param_5;
        if ((uVar16 & 1) != 0) goto LAB_009b9ab8;
      }
      goto LAB_009b9be8;
    }
LAB_009b9ab8:
    uStack_cc = uVar10;
    puStack_c8 = puVar38;
    uStack_ac = uVar5;
    iVar7 = func_0x005aacf0();
    uVar16 = func_0x0063fc5c(param_1 + 0x259,iVar7 + -2);
    puVar38 = (ulong *)0x3e7;
    iVar6 = 999;
    if ((uVar16 & 1) == 0) {
      iVar7 = func_0x005aacf0();
      iVar7 = func_0x0063ebb8(param_1 + 0x259,iVar7 + -2);
      iVar6 = 999;
      if (iVar7 != -1) {
        iVar6 = iVar7;
      }
      puVar38 = (ulong *)0x0;
    }
    uStack_94 = uVar4;
    if ((uStack_ac & 1) == 0) {
      iVar7 = func_0x005abf04(param_2,param_3);
      uVar22 = func_0x00a92ebc((long)param_1 + ((long)iVar7 * 2 + 0x11eab) * 4);
      iVar7 = func_0x0043ed84(uVar22,iVar6);
      iVar8 = func_0x005abf04(param_2,param_3);
      uVar22 = func_0x00a92e2c((long)param_1 + ((long)iVar8 * 2 + 0x11eab) * 4);
      iVar8 = func_0x0043ed84(uVar22,puVar38);
      uVar16 = func_0x008b18c4(param_1 + 0x8d,0xffffffff,0xffffffff,0xffffffff);
      if (((uVar16 & 1) != 0) && (lVar40 = param_1[0x90], param_1[0x91] != lVar40)) {
        lVar15 = 0;
        uVar16 = 0;
        do {
          iVar9 = *(int *)(lVar40 + lVar15);
          iVar12 = func_0x005abf04(param_2,uVar32);
          if (iVar9 == iVar12) {
            uStack_a0 = CONCAT44(uStack_a0._4_4_,
                                 *(int *)(param_1[0x90] + lVar15 + 0xc) +
                                 *(int *)(param_1[0x90] + lVar15 + 8));
            goto LAB_009b9f10;
          }
          lVar40 = param_1[0x90];
          uVar16 = uVar16 + 1;
          lVar15 = lVar15 + 0x10;
        } while (uVar16 < (ulong)(param_1[0x91] - lVar40 >> 4));
      }
      uStack_a0 = CONCAT44(uStack_a0._4_4_,iVar8 + iVar7);
LAB_009b9f10:
      uVar16 = func_0x005ab37c(param_2,uVar32);
      unaff_x26 = (ulong *)(uVar16 & 0xffffffff);
      iVar7 = func_0x005ab37c(param_2,uVar32);
      iVar8 = func_0x005abf1c(param_2,uVar32);
      unaff_x23 = (ulong *)0x760;
      unaff_x27 = (ulong *)(ulong)*(uint *)(param_1 +
                                           (long)iVar8 * 0x3b + (long)iVar7 * 0xec + 0x13cb6);
      iVar7 = func_0x005ab37c(param_2,uVar32);
      iVar8 = func_0x005abf1c(param_2,uVar32);
      unaff_x28 = (undefined *)
                  (ulong)*(uint *)((long)param_1 +
                                  ((long)iVar7 * 0x1d8 + (long)iVar8 * 0x76 + 0x2796d) * 4);
      uVar16 = func_0x005abf1c(param_2,uVar32);
      uVar19 = uStack_a0 & 0xffffffff;
      uVar16 = uVar16 & 0xffffffff;
      puVar36 = unaff_x26;
      puVar38 = unaff_x27;
      puVar24 = unaff_x28;
      plVar18 = (long *)Battle_SpawnOrInitUnit
                                  (param_1,param_2,unaff_x26,uVar19,unaff_x27,unaff_x28,uVar16,0);
      iVar25 = (int)uVar16;
      iVar8 = (int)uVar19;
      iVar12 = (int)puVar24;
      iVar7 = (int)puVar36;
      iVar9 = (int)puVar38;
      puVar36 = (ulong *)(ulong)uStack_94;
      unaff_x25 = (ulong *)((ulong)plVar18 & 0xffffffff);
      if ((param_2 == 0) && (-1 < (int)plVar18)) {
        uStack_c0 = CONCAT44(uStack_c0._4_4_,(int)plVar18);
        uVar11 = func_0x007ac230(0);
        uVar22 = 8;
        plVar18 = (long *)func_0x00633678(param_1 + 0xcd,uVar11,8);
        iVar25 = (int)uVar16;
        iVar12 = (int)puVar24;
        iVar8 = (int)uVar19;
        iVar9 = (int)puVar38;
        if (plVar18 != (long *)0x0) {
          func_0x005abf04(0,uVar32);
          uVar10 = func_0x0062d750();
          iVar7 = (int)uVar22;
          iVar25 = (int)uVar16;
          iVar12 = (int)puVar24;
          iVar8 = (int)uVar19;
          iVar9 = (int)puVar38;
          puVar28 = (uint *)*plVar18;
          uVar37 = plVar18[1] - (long)puVar28;
          plStack_b8 = plVar18;
          if (uVar37 != 0) {
            if ((*puVar28 >> (ulong)(uVar10 & 0x1f) & 1) == 0) goto LAB_009ba1f8;
            if (4 < uVar37) {
              unaff_x28 = (undefined *)0x0;
              uStack_a0 = uVar32;
              do {
                iVar25 = (int)uVar16;
                iVar12 = (int)puVar24;
                iVar7 = (int)uVar22;
                iVar8 = (int)uVar19;
                iVar9 = (int)puVar38;
                if ((int)puVar28[1] <= (int)unaff_x28) goto LAB_009ba1f8;
                if (uVar37 == 8) break;
                uVar10 = (int)unaff_x28 + 1;
                unaff_x28 = (undefined *)(ulong)uVar10;
                unaff_x27 = (ulong *)param_1[0x4e8];
                uVar37 = (ulong)(puVar28[2] * uVar10);
                if (unaff_x27 < (ulong *)param_1[0x4e9]) {
                  unaff_x26 = unaff_x27 + 1;
                  *unaff_x27 = uStack_a0 | uVar37 << 0x20;
                  unaff_x27 = unaff_x26;
                }
                else {
                  unaff_x23 = (ulong *)param_1[0x4e7];
                  lVar40 = (long)unaff_x27 - (long)unaff_x23 >> 3;
                  puVar36 = (ulong *)(lVar40 + 1);
                  if ((ulong)puVar36 >> 0x3d != 0) goto LAB_009ba52c;
                  uVar29 = param_1[0x4e9] - (long)unaff_x23;
                  puStack_a8 = (ulong *)((long)uVar29 >> 2);
                  if (puStack_a8 <= puVar36) {
                    puStack_a8 = puVar36;
                  }
                  if (0x7ffffffffffffff7 < uVar29) {
                    puStack_a8 = (ulong *)0x1fffffffffffffff;
                  }
                  if (puStack_a8 == (ulong *)0x0) {
                    lVar15 = 0;
                  }
                  else {
                    if ((ulong)puStack_a8 >> 0x3d != 0) goto LAB_009ba548;
                    lVar15 = func_0x00bc3330((long)puStack_a8 << 3);
                  }
                  plVar18 = plStack_b8;
                  puVar35 = (ulong *)(lVar15 + lVar40 * 8);
                  unaff_x26 = puVar35 + 1;
                  *puVar35 = uStack_a0 | uVar37 << 0x20;
                  if ((long)unaff_x27 - (long)unaff_x23 != 0) {
                    uVar37 = ((long)unaff_x27 - (long)unaff_x23) - 8;
                    if ((uVar37 < 0x38) ||
                       ((ulong)((long)unaff_x27 + (-((long)unaff_x27 - (long)unaff_x23) - lVar15)) <
                        0x20)) {
LAB_009ba17c:
                      do {
                        unaff_x27 = unaff_x27 + -1;
                        puVar36 = puVar35 + -1;
                        *puVar36 = *unaff_x27;
                        puVar35 = puVar36;
                      } while (unaff_x27 != unaff_x23);
                    }
                    else {
                      puVar31 = unaff_x27 + -2;
                      uVar37 = (uVar37 >> 3) + 1;
                      uVar30 = uVar37 & 0x3ffffffffffffffc;
                      unaff_x27 = unaff_x27 + -uVar30;
                      puVar36 = puVar35 + -uVar30;
                      puVar35 = puVar35 + -2;
                      uVar29 = uVar30;
                      do {
                        puVar2 = puVar31 + -1;
                        uVar42 = puVar31[-2];
                        uVar41 = puVar31[1];
                        uVar39 = *puVar31;
                        uVar29 = uVar29 - 4;
                        puVar31 = puVar31 + -4;
                        puVar35[-1] = *puVar2;
                        puVar35[-2] = uVar42;
                        puVar35[1] = uVar41;
                        *puVar35 = uVar39;
                        puVar35 = puVar35 + -4;
                      } while (uVar29 != 0);
                      puVar35 = puVar36;
                      if (uVar37 != uVar30) goto LAB_009ba17c;
                    }
                    unaff_x27 = (ulong *)param_1[0x4e7];
                    puVar35 = puVar36;
                  }
                  puVar36 = (ulong *)(ulong)uStack_94;
                  param_1[0x4e7] = (long)puVar35;
                  param_1[0x4e8] = (long)unaff_x26;
                  param_1[0x4e9] = lVar15 + (long)puStack_a8 * 8;
                  if (unaff_x27 != (ulong *)0x0) {
                    func_0x00bc3350(unaff_x27);
                  }
                }
                iVar25 = (int)uVar16;
                iVar8 = (int)uVar19;
                iVar12 = (int)puVar24;
                iVar7 = (int)uVar22;
                iVar9 = (int)puVar38;
                puVar28 = (uint *)*plVar18;
                lVar40 = plVar18[1];
                param_1[0x4e8] = (long)unaff_x26;
                uVar37 = lVar40 - (long)puVar28;
              } while (4 < uVar37);
            }
          }
          if (*(long *)(pbVar21 + 0x28) == lStack_68) {
            func_0x00470c38(plStack_b8);
LAB_009ba52c:
            if (*(long *)(pbVar21 + 0x28) == lStack_68) {
              func_0x009c7160(param_1 + 0x4e7);
LAB_009ba548:
              if (*(long *)(pbVar21 + 0x28) == lStack_68) {
                uVar22 = func_0x0040fc1c();
                if ((abStack_88[0] & 1) != 0) {
                  func_0x00bc3350(CONCAT71(uStack_77,uStack_78));
                }
                if (*(long *)(pbVar21 + 0x28) == lStack_68) {
                  func_0x00bbf40c(uVar22);
                }
              }
            }
          }
          goto LAB_009ba588;
        }
LAB_009ba1f8:
        unaff_x25 = (ulong *)(uStack_c0 & 0xffffffff);
        puVar38 = puVar36;
        func_0x00a62e70(0,unaff_x25,puVar36);
        iVar7 = (int)puVar38;
        plVar18 = (long *)func_0x009d0178(param_1[0xf8]);
        if (((ulong)plVar18 & 1) != 0) {
          unaff_x23 = (ulong *)&UNK_003880b8;
          uVar10 = func_0x005abf04(0,uVar32);
          unaff_x26 = (ulong *)(ulong)uVar10;
          iVar7 = func_0x005abf1c(0,uVar32);
          piVar23 = &iStack_6c;
          iVar9 = 1;
          iStack_6c = ((int)param_1[0x71017] + 2) *
                      ((int)param_1[(long)iVar7 * 0x3b + (long)(int)uVar10 * 0xec + 0x13e8a] / 100);
          if (iStack_6c < 0) {
            iStack_6c = iStack_6c + 1;
          }
          iStack_6c = iStack_6c >> 1;
          puVar38 = unaff_x25;
          plVar18 = (long *)func_0x009d219c(param_1[0xf8],0,unaff_x25,piVar23,1);
          iVar8 = (int)piVar23;
          iVar7 = (int)puVar38;
        }
      }
      if ((int)unaff_x25 < 0) goto LAB_009ba328;
      uVar11 = func_0x005abf04(param_2,uVar32);
      uVar13 = func_0x005abf1c(param_2,uVar32);
      iVar7 = func_0x00a68968(param_2,uVar11,uVar13);
      unaff_x25 = puStack_90;
      iVar8 = (int)puStack_90;
      if (-1 < iVar7) {
        lVar15 = (long)iVar8;
        lVar40 = (long)(int)param_3;
        *(undefined1 *)((long)param_1 + (long)(int)param_3 + lVar15 * 0x1f0 + 0x272c) = 0;
        *(undefined4 *)((long)param_1 + (lVar15 * 0x7c + lVar40 + 0x9ad) * 4) = 1;
        *(undefined4 *)((long)param_1 + (lVar15 * 0x7c + lVar40 + 0x9b7) * 4) = 0xf;
        *(undefined4 *)((long)param_1 + (lVar15 * 0x7c + lVar40 + 0x9c1) * 4) = 0;
      }
      lVar15 = (long)(int)param_3;
      uVar11 = func_0x005ad22c(param_2,uVar32);
      lVar40 = (long)iVar8;
      puVar36 = (ulong *)(ulong)uStack_94;
      iVar7 = *(int *)((long)param_1 + (lVar40 * 0x7c + lVar15 + 0x9d4) * 4);
      *(undefined4 *)((long)param_1 + (lVar40 * 0x7c + lVar15 + 0x9de) * 4) = uVar11;
      *(int *)((long)param_1 + (lVar40 * 0x7c + lVar15 + 0x9d4) * 4) = iVar7 + 1;
      *(int *)(param_1 + 0x67713) = (int)param_1[0x67713] + 1;
LAB_009ba388:
      puVar38 = puStack_c8;
      unaff_x23 = (ulong *)((long)param_1 + 0x3285ec);
      *(undefined4 *)unaff_x23 = 0;
      if ((uStack_ac & 1) == 0) {
        unaff_x26 = (ulong *)0x2648;
        func_0x005b1e64(puStack_c8 + 0x4c9,-(int)puVar36);
        unaff_x23 = (ulong *)0x0;
        if ((int)param_1[0x656e8] != 1) {
          uVar16 = func_0x0057aa0c(param_2,uVar32);
          unaff_x23 = (ulong *)(uVar16 & 0xffffffff);
          uVar19 = func_0x0043ed84(uVar16,0x3c);
          if (param_2 == 0) {
            uVar34 = uVar19 & 0xffffffff;
            iVar7 = func_0x005abf1c(0,uVar32);
            if ((1 < iVar7) &&
               (uVar19 = func_0x005b23cc(puVar38 + 0x4c9,0,uVar32), (uVar19 & 1) != 0)) {
              uVar11 = func_0x007ac230(0);
              uVar19 = func_0x00633464(param_1 + 0xcd,uVar11,1);
              if ((uVar19 & 1) == 0) {
                uVar11 = func_0x005abf04(0,uVar32);
                puVar36 = (ulong *)(ulong)uStack_94;
                iVar7 = func_0x006535d4(param_1 + 0x2a7,uVar11,0x13,0,0);
                uVar16 = func_0x0043ed6c(((100 - iVar7) * (int)uVar16) / 100,uVar34);
                unaff_x23 = (ulong *)(uVar16 & 0xffffffff);
              }
            }
          }
        }
        func_0x005b2234(puVar38 + 0x4c9,uVar32,unaff_x23,1);
        unaff_x25 = puVar38;
      }
      plVar18 = (long *)func_0x0044c16c();
      uVar16 = 0x13;
      unaff_x30 = 0x9ba4a4;
      register0x00000008 = (BADSPACEBASE *)(abStack_260 + 400);
      unaff_x19 = param_1;
      unaff_x20 = uVar32;
      unaff_x21 = pbVar21;
      unaff_x22 = uVar34;
      unaff_x24 = puVar36;
      unaff_x29 = puVar27;
    }
    else {
      uVar22 = 1;
      uVar16 = func_0x005aedfc(param_2,uVar32,1);
      iVar25 = (int)param_7;
      iVar8 = (int)param_4;
      iVar12 = (int)param_6;
      iVar7 = (int)uVar22;
      iVar9 = (int)param_5;
      if ((uVar16 & 1) == 0) {
        iVar6 = func_0x005b21ec(puStack_c8 + 0x4c9,uVar32);
        if ((iVar6 == 0) &&
           (*(char *)((long)param_1 + (long)(int)param_3 + (long)(int)puStack_90 * 0x1f0 + 0x272c)
            != '\0')) {
          lVar40 = 0x30000001e;
          goto LAB_009b9be4;
        }
        goto LAB_009b9be8;
      }
      iVar7 = func_0x005abf04(param_2,uVar32);
      uVar17 = func_0x00a92ebc((long)param_1 + ((long)iVar7 * 2 + 0x11eab) * 4);
      iVar7 = func_0x0043ed84(uVar17,iVar6);
      iVar8 = func_0x005abf04(param_2,uVar32);
      uVar17 = func_0x00a92e2c((long)param_1 + ((long)iVar8 * 2 + 0x11eab) * 4);
      iVar8 = func_0x0043ed84(uVar17,puVar38);
      func_0x005abf04(param_2,param_3 + 0xb);
      iVar9 = func_0x0062dab4();
      uStack_a0 = CONCAT44(uStack_a0._4_4_,iVar8 + iVar7);
      if (iVar9 <= iVar8 + iVar7) {
        func_0x005abf04(param_2,param_3 + 0xb);
        iVar7 = func_0x0062dab4();
        uStack_a0 = CONCAT44(uStack_a0._4_4_,iVar7 + -1);
      }
      puVar35 = (ulong *)0x0;
      unaff_x26 = (ulong *)0x1;
      plStack_b8 = (long *)((ulong)abStack_88 | 1);
      puStack_a8 = (ulong *)(param_1 + 0x13caf);
      uStack_c0 = (long)param_1 + ((long)(int)puStack_90 * 0x7c + 0x9cb) * 4;
      unaff_x25 = (ulong *)0x2648;
      unaff_x27 = puVar38;
      unaff_x28 = &UNK_00290560;
      do {
        plVar18 = (long *)func_0x00a58874(0,unaff_x26);
        if ((int)plVar18 != 0) {
          uVar10 = func_0x00a58934(param_2,unaff_x26);
          unaff_x25 = (ulong *)(ulong)uVar10;
          plVar18 = (long *)func_0x005abf04(param_2,uVar32);
          if (uVar10 == (uint)plVar18) {
            uVar11 = func_0x005ab37c(param_2,param_3 + 0xb);
            puStack_90 = (ulong *)CONCAT44(puStack_90._4_4_,uVar11);
            iVar7 = func_0x005ab37c(param_2,param_3 + 0xb);
            iVar8 = func_0x005abf1c(param_2,param_3 + 0xb);
            unaff_x23 = puStack_a8;
            unaff_x27 = (ulong *)(ulong)(uint)puStack_a8
                                              [(long)iVar7 * 0xec + (long)iVar8 * 0x3b + 7];
            iVar7 = func_0x005ab37c(param_2,param_3 + 0xb);
            iVar8 = func_0x005abf1c(param_2,param_3 + 0xb);
            unaff_x28 = (undefined *)
                        (ulong)*(uint *)((long)unaff_x23 +
                                        (long)iVar8 * 0x1d8 + (long)iVar7 * 0x760 + 0x3c);
            param_7 = func_0x005abf1c(param_2,param_3 + 0xb);
            iVar7 = (int)puStack_90;
            param_4 = uStack_a0 & 0xffffffff;
            param_7 = param_7 & 0xffffffff;
            param_5 = unaff_x27;
            param_6 = unaff_x28;
            plVar18 = (long *)Battle_SpawnOrInitUnit
                                        (param_1,param_2,(ulong)puStack_90 & 0xffffffff,param_4,
                                         unaff_x27,unaff_x28,param_7,0);
            iVar25 = (int)param_7;
            iVar8 = (int)param_4;
            iVar12 = (int)param_6;
            iVar9 = (int)param_5;
            unaff_x25 = puVar35;
            if ((int)plVar18 == -1) goto LAB_009ba328;
            unaff_x27 = (ulong *)((ulong)plVar18 & 0xffffffff);
            *(undefined1 *)(uStack_c0 + (long)(int)param_3) = 1;
            func_0x00a5db08(param_2,unaff_x27,uVar32);
            if ((int)puVar35 == 0) {
              plVar18 = (long *)func_0x0044c16c();
              uVar16 = 0xa2;
              unaff_x30 = 0x9b9dd0;
              register0x00000008 = (BADSPACEBASE *)(abStack_260 + 400);
              unaff_x19 = param_1;
              unaff_x20 = uVar32;
              unaff_x21 = pbVar21;
              unaff_x22 = uVar34;
              unaff_x24 = puVar36;
              unaff_x29 = puVar27;
              goto LAB_0044d5c0;
            }
            uVar10 = func_0x00a5919c(param_2,unaff_x26);
            abStack_88[0] = 0x1e;
            unaff_x28 = (undefined *)(ulong)uVar10;
            uStack_78 = 0;
            *plStack_b8 = 0x705f6e6f6d6d7573;
            *(undefined8 *)((long)plStack_b8 + 7) = 0x6e6f697469736f70;
            uVar4 = func_0x008e3f14(param_1 + 0x28f,abStack_88,0);
            unaff_x25 = (ulong *)(ulong)uVar4;
            if ((abStack_88[0] & 1) != 0) {
              func_0x00bc3350(CONCAT71(uStack_77,uStack_78));
            }
            iVar7 = uVar10 + uVar4 * -4;
            iVar8 = func_0x00a5a628(param_2,unaff_x27);
            if (iVar7 - iVar8 < 0xc80) {
              iVar7 = func_0x00a5a628(param_2,unaff_x27);
              iVar7 = iVar7 + 0xc80;
            }
            iVar8 = (int)param_1[0x13ca7] + -0xc80;
            if (iVar8 <= iVar7) {
              iVar7 = iVar8;
            }
            func_0x00a591dc(param_2,unaff_x27,iVar7);
            puVar35 = (ulong *)0x1;
            Battle_Set_83ad4(param_2,unaff_x27,1);
            func_0x00a5a82c(param_2,unaff_x27,2);
            func_0x00a600ac(param_2,unaff_x27,100);
            func_0x00a60138(param_2,unaff_x27,10000);
            func_0x00a5fde8(param_2,unaff_x27,1);
            uVar22 = 2;
            plVar18 = (long *)func_0x00a58be4(param_2,unaff_x27,2);
          }
        }
        iVar25 = (int)param_7;
        iVar8 = (int)param_4;
        iVar12 = (int)param_6;
        iVar7 = (int)uVar22;
        iVar9 = (int)param_5;
        uVar10 = (int)unaff_x26 + 1;
        unaff_x26 = (ulong *)(ulong)uVar10;
      } while (uVar10 != 0x33);
      unaff_x23 = puVar35;
      if (-1 < (int)unaff_x27) goto LAB_009ba388;
LAB_009ba328:
      if ((uStack_cc & 1) == 0) {
        if (*(long *)(pbVar21 + 0x28) == lStack_68) {
          return plVar18;
        }
        goto LAB_009ba588;
      }
      plVar18 = (long *)func_0x0044c16c();
      uVar16 = 0xf;
      unaff_x30 = 0x9ba340;
      register0x00000008 = (BADSPACEBASE *)(abStack_260 + 400);
      unaff_x19 = param_1;
      unaff_x20 = uVar32;
      unaff_x21 = pbVar21;
      unaff_x22 = uVar34;
      unaff_x24 = puVar36;
      unaff_x29 = puVar27;
    }
  }
LAB_0044d5c0:
  pbVar21 = (byte *)0x0;
  *(undefined1 **)((long)register0x00000008 + -0x60) = unaff_x29;
  *(undefined8 *)((long)register0x00000008 + -0x58) = unaff_x30;
  *(undefined **)((long)register0x00000008 + -0x50) = unaff_x28;
  *(ulong **)((long)register0x00000008 + -0x48) = unaff_x27;
  *(ulong **)((long)register0x00000008 + -0x40) = unaff_x26;
  *(ulong **)((long)register0x00000008 + -0x38) = unaff_x25;
  *(ulong **)((long)register0x00000008 + -0x30) = unaff_x24;
  *(ulong **)((long)register0x00000008 + -0x28) = unaff_x23;
  *(ulong *)((long)register0x00000008 + -0x20) = unaff_x22;
  *(byte **)((long)register0x00000008 + -0x18) = unaff_x21;
  *(ulong *)((long)register0x00000008 + -0x10) = unaff_x20;
  *(long **)((long)register0x00000008 + -8) = unaff_x19;
  lVar40 = tpidr_el0;
  *(undefined8 *)((long)register0x00000008 + -0x68) = *(undefined8 *)(lVar40 + 0x28);
  if ((ulong)(long)(int)uVar16 < (ulong)(plVar18[2] - plVar18[1] >> 2)) {
    unaff_x20 = 0;
    pbVar33 = (byte *)0x0;
    plVar14 = plVar18;
    pbVar20 = pbVar21;
    if ((int)uVar16 == 0x1d) {
      plVar14 = (long *)func_0x007fd748();
      if ((int)plVar14[0x881ca] != -1) {
        lVar15 = func_0x007fd748();
        plVar14 = (long *)func_0x007fd748();
        plVar26 = *(long **)(lVar15 + 0x2618);
        if (plVar26 != (long *)0x0) {
          do {
            if ((int)plVar26[4] <= (int)plVar14[0x881ca]) {
              if ((int)plVar14[0x881ca] <= (int)plVar26[4]) {
                lVar15 = func_0x007fd748();
                plVar14 = (long *)func_0x007fd748();
                iVar7 = (int)plVar14[0x881ca];
                puVar36 = *(ulong **)(lVar15 + 0x2618);
                if (*(ulong **)(lVar15 + 0x2618) != (ulong *)0x0) goto LAB_0044d6d8;
                puVar38 = (ulong *)(lVar15 + 0x2618);
                unaff_x24 = (ulong *)(lVar15 + 0x2618);
                goto LAB_0044d6fc;
              }
              plVar26 = plVar26 + 1;
            }
            plVar26 = (long *)*plVar26;
          } while (plVar26 != (long *)0x0);
        }
      }
      goto LAB_0044d7dc;
    }
    goto LAB_0044d7e0;
  }
  *(undefined2 *)((long)register0x00000008 + -0x80) = 0;
  plVar14 = (long *)func_0x0056a6f0((undefined1 *)((long)register0x00000008 + -0x80),3);
  pbVar20 = pbVar21;
  plVar18 = unaff_x19;
  if ((*(byte *)((long)register0x00000008 + -0x80) & 1) != 0) {
    plVar14 = (long *)func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x70));
    pbVar20 = pbVar21;
  }
  goto LAB_0044dd88;
  while (puVar36 = (ulong *)*unaff_x23, unaff_x24 = unaff_x23, (ulong *)*unaff_x23 != (ulong *)0x0)
  {
LAB_0044d6d8:
    unaff_x23 = puVar36;
    puVar38 = unaff_x23;
    if ((int)unaff_x23[4] <= iVar7) {
      if (iVar7 <= (int)unaff_x23[4]) goto LAB_0044d7a0;
      puVar36 = (ulong *)unaff_x23[1];
      if ((ulong *)unaff_x23[1] == (ulong *)0x0) {
        unaff_x24 = unaff_x23 + 1;
        break;
      }
      goto LAB_0044d6d8;
    }
  }
LAB_0044d6fc:
  unaff_x23 = (ulong *)func_0x00bc3330(0x160);
  unaff_x23[0x2b] = 0;
  *(int *)(unaff_x23 + 4) = iVar7;
  *unaff_x23 = 0;
  unaff_x23[1] = 0;
  unaff_x23[2] = (ulong)puVar38;
  unaff_x23[0x22] = 0;
  unaff_x23[0x21] = 0;
  unaff_x23[0x24] = 0;
  unaff_x23[0x23] = 0;
  unaff_x23[8] = 0;
  unaff_x23[7] = 0;
  unaff_x23[10] = 0;
  unaff_x23[9] = 0;
  unaff_x23[0xc] = 0;
  unaff_x23[0xb] = 0;
  unaff_x23[0xe] = 0;
  unaff_x23[0xd] = 0;
  unaff_x23[0x10] = 0;
  unaff_x23[0xf] = 0;
  unaff_x23[0x12] = 0;
  unaff_x23[0x11] = 0;
  unaff_x23[0x14] = 0;
  unaff_x23[0x13] = 0;
  unaff_x23[0x16] = 0;
  unaff_x23[0x15] = 0;
  unaff_x23[0x18] = 0;
  unaff_x23[0x17] = 0;
  unaff_x23[0x1a] = 0;
  unaff_x23[0x19] = 0;
  unaff_x23[0x1c] = 0;
  unaff_x23[0x1b] = 0;
  unaff_x23[0x1e] = 0;
  unaff_x23[0x1d] = 0;
  unaff_x23[0x20] = 0;
  unaff_x23[0x1f] = 0;
  unaff_x23[6] = 0;
  unaff_x23[5] = 0;
  unaff_x23[0x26] = 0;
  unaff_x23[0x25] = 0;
  unaff_x23[0x28] = 0;
  unaff_x23[0x27] = 0;
  unaff_x23[0x2a] = 0;
  unaff_x23[0x29] = 0;
  *unaff_x24 = (ulong)unaff_x23;
  puVar36 = unaff_x23;
  if (**(long **)(lVar15 + 0x2610) != 0) {
    *(long *)(lVar15 + 0x2610) = **(long **)(lVar15 + 0x2610);
    puVar36 = (ulong *)*unaff_x24;
  }
  plVar14 = (long *)func_0x0040a8c0(*(undefined8 *)(lVar15 + 0x2618),puVar36);
  *(long *)(lVar15 + 0x2620) = *(long *)(lVar15 + 0x2620) + 1;
LAB_0044d7a0:
  if ((int)unaff_x23[0x2a] == -1) {
LAB_0044d7dc:
    uVar16 = 0x1d;
  }
  else {
    lVar15 = func_0x007fd748();
    plVar14 = (long *)func_0x007fd748();
    iVar7 = (int)plVar14[0x881ca];
    puVar36 = *(ulong **)(lVar15 + 0x2618);
    if (*(ulong **)(lVar15 + 0x2618) == (ulong *)0x0) {
      puVar38 = (ulong *)(lVar15 + 0x2618);
      unaff_x24 = (ulong *)(lVar15 + 0x2618);
    }
    else {
      do {
        while (unaff_x23 = puVar36, puVar38 = unaff_x23, (int)unaff_x23[4] <= iVar7) {
          if (iVar7 <= (int)unaff_x23[4]) goto LAB_0044dbc8;
          puVar36 = (ulong *)unaff_x23[1];
          if ((ulong *)unaff_x23[1] == (ulong *)0x0) {
            unaff_x24 = unaff_x23 + 1;
            goto LAB_0044db24;
          }
        }
        puVar36 = (ulong *)*unaff_x23;
        unaff_x24 = unaff_x23;
      } while ((ulong *)*unaff_x23 != (ulong *)0x0);
    }
LAB_0044db24:
    unaff_x23 = (ulong *)func_0x00bc3330(0x160);
    unaff_x23[0x2b] = 0;
    *(int *)(unaff_x23 + 4) = iVar7;
    *unaff_x23 = 0;
    unaff_x23[1] = 0;
    unaff_x23[2] = (ulong)puVar38;
    unaff_x23[0x22] = 0;
    unaff_x23[0x21] = 0;
    unaff_x23[0x24] = 0;
    unaff_x23[0x23] = 0;
    unaff_x23[8] = 0;
    unaff_x23[7] = 0;
    unaff_x23[10] = 0;
    unaff_x23[9] = 0;
    unaff_x23[0xc] = 0;
    unaff_x23[0xb] = 0;
    unaff_x23[0xe] = 0;
    unaff_x23[0xd] = 0;
    unaff_x23[0x10] = 0;
    unaff_x23[0xf] = 0;
    unaff_x23[0x12] = 0;
    unaff_x23[0x11] = 0;
    unaff_x23[0x14] = 0;
    unaff_x23[0x13] = 0;
    unaff_x23[0x16] = 0;
    unaff_x23[0x15] = 0;
    unaff_x23[0x18] = 0;
    unaff_x23[0x17] = 0;
    unaff_x23[0x1a] = 0;
    unaff_x23[0x19] = 0;
    unaff_x23[0x1c] = 0;
    unaff_x23[0x1b] = 0;
    unaff_x23[0x1e] = 0;
    unaff_x23[0x1d] = 0;
    unaff_x23[0x20] = 0;
    unaff_x23[0x1f] = 0;
    unaff_x23[6] = 0;
    unaff_x23[5] = 0;
    unaff_x23[0x26] = 0;
    unaff_x23[0x25] = 0;
    unaff_x23[0x28] = 0;
    unaff_x23[0x27] = 0;
    unaff_x23[0x2a] = 0;
    unaff_x23[0x29] = 0;
    *unaff_x24 = (ulong)unaff_x23;
    puVar36 = unaff_x23;
    if (**(long **)(lVar15 + 0x2610) != 0) {
      *(long *)(lVar15 + 0x2610) = **(long **)(lVar15 + 0x2610);
      puVar36 = (ulong *)*unaff_x24;
    }
    plVar14 = (long *)func_0x0040a8c0(*(undefined8 *)(lVar15 + 0x2618),puVar36);
    *(long *)(lVar15 + 0x2620) = *(long *)(lVar15 + 0x2620) + 1;
LAB_0044dbc8:
    uVar16 = (ulong)(uint)unaff_x23[0x2a];
  }
LAB_0044d7e0:
  unaff_x22 = (ulong)(int)uVar16;
  uVar10 = *(uint *)(plVar18[1] + (long)(int)uVar16 * 4);
  if (((uVar10 & 1) == 0) || ((char)plVar18[0x10] != '\0')) {
    unaff_x21 = pbVar33;
    if (((uVar10 >> 1 & 1) == 0) || (*(char *)((long)plVar18 + 0x81) != '\0')) {
LAB_0044dd5c:
      unaff_x21 = pbVar21;
      if ((*(uint *)(plVar18[1] + unaff_x22 * 4) >> 2 & 1) != 0) {
        uVar16 = unaff_x22 >> 3 & 0x1ffffffffffffff8;
        *(ulong *)(plVar18[0x11] + uVar16) =
             *(ulong *)(plVar18[0x11] + uVar16) | 1L << (unaff_x22 & 0x3f);
        unaff_x21 = pbVar33;
      }
    }
    else {
      unaff_x23 = (ulong *)(unaff_x22 * 0x10);
      if (*(long *)(plVar18[8] + (long)unaff_x23) != 0) {
        *(undefined4 *)(plVar18[0x15] + unaff_x22 * 4) = 100;
        if (*(long **)(plVar18[0xb] + (long)unaff_x23) != (long *)0x0) {
          uVar16 = (**(code **)(**(long **)(plVar18[0xb] + (long)unaff_x23) + 0x70))();
          lVar15 = plVar18[0xb];
          if ((uVar16 & 1) != 0) {
            (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0x90))();
            lVar15 = plVar18[0xb];
          }
LAB_0044dcf0:
          if ((*(uint *)(plVar18[1] + unaff_x22 * 4) >> 2 & 1) != 0) {
            (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0xb8))
                      (*(long **)(lVar15 + (long)unaff_x23),1);
            lVar15 = plVar18[0xb];
          }
          (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0xe8))
                    ((float)(*(int *)(plVar18[0x15] + unaff_x22 * 4) *
                            *(int *)((long)plVar18 + 0xc4)) / 10000.0);
          plVar14 = (long *)(**(code **)(**(long **)(plVar18[0xb] + (long)unaff_x23) + 0x90))();
          goto LAB_0044dd5c;
        }
        plVar14 = (long *)func_0x0044d358(plVar18,*(undefined4 *)(plVar18[4] + unaff_x22 * 4));
        if (((ulong)plVar14 & 1) != 0) {
          func_0x00bc3570(0xc0b818);
          func_0x00521e78((undefined1 *)((long)register0x00000008 + -0x80),
                          plVar18[8] + unaff_x22 * 0x10,*(undefined4 *)(plVar18[4] + unaff_x22 * 4))
          ;
          func_0x0044e2b0(plVar18[0xb] + (long)unaff_x23,
                          (undefined1 *)((long)register0x00000008 + -0x80));
          func_0x0044e30c((undefined1 *)((long)register0x00000008 + -0x80));
          plVar14 = (long *)func_0x00bc3580(0xc0b818);
          lVar15 = plVar18[0xb];
          if (*(long *)(lVar15 + (long)unaff_x23) != 0) goto LAB_0044dcf0;
        }
      }
    }
LAB_0044dd88:
    pbVar21 = unaff_x21;
    if (*(long *)(lVar40 + 0x28) == *(long *)((long)register0x00000008 + -0x68)) {
      return plVar14;
    }
    uVar22 = 0x44def0;
    auVar43 = func_0x00bc3380();
    puVar27 = extraout_x8;
  }
  else {
    *(undefined8 *)((long)register0x00000008 + -0x80) = 0;
    *(undefined8 *)((long)register0x00000008 + -0x78) = 0;
    *(undefined8 *)((long)register0x00000008 + -0x70) = 0;
    func_0x005220d0((undefined1 *)((long)register0x00000008 + -0xb8));
    *(undefined1 *)((long)register0x00000008 + -0xe8) = 0x14;
    *(undefined1 *)((long)register0x00000008 + -0x100) = 6;
    *(undefined2 *)((long)register0x00000008 + -0xdf) = 0x7325;
    *(undefined8 *)((long)register0x00000008 + -0xe7) = 0x2e64333025646e73;
    *(undefined1 *)((long)register0x00000008 + -0xdd) = 0;
    *(undefined4 *)((long)register0x00000008 + -0xff) = 0x67676f;
    puVar27 = (undefined1 *)((long)register0x00000008 + -0xd0);
    auVar43._8_8_ = uVar16;
    auVar43._0_8_ = (undefined1 *)((long)register0x00000008 + -0xe8);
    pbVar20 = (byte *)((long)register0x00000008 + -0x100);
    uVar22 = 0x44d854;
  }
  *(undefined1 **)((long)register0x00000008 + -0x150) =
       (undefined1 *)((long)register0x00000008 + -0x60);
  *(undefined8 *)((long)register0x00000008 + -0x148) = uVar22;
  *(ulong *)((long)register0x00000008 + -0x140) = unaff_x22;
  *(byte **)((long)register0x00000008 + -0x138) = pbVar21;
  *(ulong *)((long)register0x00000008 + -0x130) = unaff_x20;
  *(long **)((long)register0x00000008 + -0x128) = plVar18;
  lVar40 = tpidr_el0;
  uVar16 = auVar43._8_8_ & 0xffffffff;
  *(undefined8 *)((long)register0x00000008 + -0x158) = *(undefined8 *)(lVar40 + 0x28);
  if ((*pbVar20 & 1) == 0) {
    uVar17 = *(undefined8 *)pbVar20;
    uVar22 = *(undefined8 *)(pbVar20 + 0x10);
    *(undefined8 *)((long)register0x00000008 + -0x188) = *(undefined8 *)(pbVar20 + 8);
    *(undefined8 *)((long)register0x00000008 + -400) = uVar17;
    *(undefined8 *)((long)register0x00000008 + -0x180) = uVar22;
    if ((*(byte *)((long)register0x00000008 + -400) & 1) != 0) goto LAB_0044df3c;
LAB_0044df60:
    *(undefined8 *)((long)register0x00000008 + -0x168) =
         *(undefined8 *)((long)register0x00000008 + -0x188);
    *(undefined8 *)((long)register0x00000008 + -0x170) =
         *(undefined8 *)((long)register0x00000008 + -400);
    *(undefined8 *)((long)register0x00000008 + -0x160) =
         *(undefined8 *)((long)register0x00000008 + -0x180);
  }
  else {
    func_0x0040a850((undefined1 *)((long)register0x00000008 + -400),*(undefined8 *)(pbVar20 + 0x10),
                    *(undefined8 *)(pbVar20 + 8));
    if ((*(byte *)((long)register0x00000008 + -400) & 1) == 0) goto LAB_0044df60;
LAB_0044df3c:
    func_0x0040a850((undefined1 *)((long)register0x00000008 + -0x170),
                    *(undefined8 *)((long)register0x00000008 + -0x180),
                    *(undefined8 *)((long)register0x00000008 + -0x188));
  }
  plVar18 = (long *)func_0x0044ede8(puVar27,auVar43._0_8_,0,uVar16,
                                    (undefined1 *)((long)register0x00000008 + -0x170));
  if ((*(byte *)((long)register0x00000008 + -0x170) & 1) != 0) {
    plVar18 = (long *)func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x160));
  }
  if ((*(byte *)((long)register0x00000008 + -400) & 1) != 0) {
    plVar18 = (long *)func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x180));
  }
  if (*(long *)(lVar40 + 0x28) == *(long *)((long)register0x00000008 + -0x158)) {
    return plVar18;
  }
  auVar44 = func_0x00bc3380();
  uVar32 = auVar44._8_8_;
  puVar28 = auVar44._0_8_;
  *(undefined1 **)((long)register0x00000008 + -0x1d0) =
       (undefined1 *)((long)register0x00000008 + -0x150);
  *(undefined8 *)((long)register0x00000008 + -0x1c8) = 0x44e014;
  *(ulong **)((long)register0x00000008 + -0x1c0) = unaff_x24;
  *(ulong **)((long)register0x00000008 + -0x1b8) = unaff_x23;
  *(long *)((long)register0x00000008 + -0x1b0) = lVar40;
  *(undefined1 **)((long)register0x00000008 + -0x1a8) = puVar27;
  *(long *)((long)register0x00000008 + -0x1a0) = auVar43._0_8_;
  *(ulong *)((long)register0x00000008 + -0x198) = uVar16;
  if (((auVar44._8_4_ ^ 0xffffffff) & 0xfffffffd) == 0) {
LAB_0044e048:
    plVar18 = *(long **)(puVar28 + 0x1c);
    if (plVar18 != (long *)0x0) {
      for (puVar1 = *(undefined8 **)(puVar28 + 0x16); puVar1 != *(undefined8 **)(puVar28 + 0x18);
          puVar1 = puVar1 + 2) {
        if ((long *)*puVar1 == plVar18) {
          uVar32 = uVar32 & 0xffffffff;
          plVar18 = (long *)(**(code **)(*plVar18 + 0xf8))();
          plVar14 = (long *)puVar1[1];
          *puVar1 = 0;
          puVar1[1] = 0;
          if ((plVar14 != (long *)0x0) &&
             (plVar18 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar14 + 1),
             plVar18 == (long *)0x0)) {
            (**(code **)(*plVar14 + 0x10))(plVar14);
            plVar18 = (long *)func_0x00bc3320(plVar14);
          }
          plVar14 = *(long **)(puVar28 + 0x1e);
          puVar28[0x1c] = 0;
          puVar28[0x1d] = 0;
          puVar28[0x1e] = 0;
          puVar28[0x1f] = 0;
          if ((plVar14 != (long *)0x0) &&
             (plVar18 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar14 + 1),
             plVar18 == (long *)0x0)) {
            (**(code **)(*plVar14 + 0x10))(plVar14);
            plVar18 = (long *)func_0x00bc3320(plVar14);
          }
          break;
        }
      }
    }
    auVar3._8_8_ = uVar32;
    auVar3._0_8_ = plVar18;
    auVar44._8_8_ = uVar32;
    auVar44._0_8_ = plVar18;
    uVar10 = *puVar28;
    if (0 < (int)uVar10) {
      lVar40 = *(long *)(puVar28 + 2);
      lVar15 = *(long *)(puVar28 + 0x22);
      uVar16 = 0;
      do {
        if ((*(uint *)(lVar40 + uVar16 * 4) & 1) != 0) {
          uVar32 = uVar16 >> 3 & 0x1ffffffffffffff8;
          *(ulong *)(lVar15 + uVar32) =
               *(ulong *)(lVar15 + uVar32) & (1L << (uVar16 & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar16 = uVar16 + 1;
        auVar44 = auVar3;
      } while (uVar10 != uVar16);
    }
  }
  else if (-1 < (int)auVar44._8_4_) {
    uVar10 = *(uint *)(*(long *)(puVar28 + 2) + (uVar32 & 0xffffffff) * 4);
    if ((uVar10 & 1) == 0) goto LAB_0044e194;
    goto LAB_0044e048;
  }
  plVar18 = auVar44._0_8_;
  if (auVar44._8_4_ + 3U < 2) {
    uVar10 = *puVar28;
    if ((int)uVar10 < 1) {
      return plVar18;
    }
    lVar40 = 0;
    lVar15 = 0;
    uVar16 = 0;
    do {
      if (((*(byte *)(*(long *)(puVar28 + 2) + lVar15) >> 1 & 1) != 0) &&
         (plVar18 = *(long **)(*(long *)(puVar28 + 0x16) + lVar40), plVar18 != (long *)0x0)) {
        plVar18 = (long *)(**(code **)(*plVar18 + 0xf8))();
        puVar1 = (undefined8 *)(*(long *)(puVar28 + 0x16) + lVar40);
        plVar14 = (long *)puVar1[1];
        *puVar1 = 0;
        puVar1[1] = 0;
        if ((plVar14 != (long *)0x0) &&
           (plVar18 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar14 + 1),
           plVar18 == (long *)0x0)) {
          (**(code **)(*plVar14 + 0x10))(plVar14);
          plVar18 = (long *)func_0x00bc3320(plVar14);
        }
        uVar32 = uVar16 >> 3 & 0x1ffffffffffffff8;
        uVar10 = *puVar28;
        *(ulong *)(*(long *)(puVar28 + 0x22) + uVar32) =
             *(ulong *)(*(long *)(puVar28 + 0x22) + uVar32) &
             (1L << (uVar16 & 0x3f) ^ 0xffffffffffffffffU);
      }
      uVar16 = uVar16 + 1;
      lVar40 = lVar40 + 0x10;
      lVar15 = lVar15 + 4;
    } while ((long)uVar16 < (long)(int)uVar10);
    return plVar18;
  }
  if (auVar44._8_4_ < 0) {
    return plVar18;
  }
  uVar10 = *(uint *)(*(long *)(puVar28 + 2) + (auVar44._8_8_ & 0xffffffff) * 4);
LAB_0044e194:
  plVar18 = auVar44._0_8_;
  uVar16 = auVar44._8_8_ & 0xffffffff;
  if ((uVar10 >> 1 & 1) != 0) {
    plVar14 = *(long **)(*(long *)(puVar28 + 0x16) + uVar16 * 0x10);
    plVar18 = (long *)0x0;
    if (plVar14 != (long *)0x0) {
      plVar18 = (long *)(**(code **)(*plVar14 + 0xf8))();
      puVar1 = (undefined8 *)(*(long *)(puVar28 + 0x16) + uVar16 * 0x10);
      plVar14 = (long *)puVar1[1];
      *puVar1 = 0;
      puVar1[1] = 0;
      if ((plVar14 != (long *)0x0) &&
         (plVar18 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar14 + 1), plVar18 == (long *)0x0)
         ) {
        (**(code **)(*plVar14 + 0x10))(plVar14);
        plVar18 = (long *)func_0x00bc3320(plVar14);
      }
      uVar16 = uVar16 >> 3 & 0x1ffffff8;
      *(ulong *)(*(long *)(puVar28 + 0x22) + uVar16) =
           *(ulong *)(*(long *)(puVar28 + 0x22) + uVar16) &
           (1L << (auVar44._8_8_ & 0x3f) ^ 0xffffffffffffffffU);
    }
  }
  return plVar18;
}


