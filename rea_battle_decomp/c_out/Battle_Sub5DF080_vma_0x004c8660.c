// ELF VMA: 0x4c8660
// Ghidra Addr: 0x006df080 (ImageBase=0x100000)
// Function: Battle_Sub5DF080
// Size: 8148 bytes
// Callees (2): Battle_Sub8B99A0@0x8b99a0, Battle_SpawnOrInitUnit@0x8b6dec, 


/* WARNING: Possible PIC construction at 0x0044d850: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d910: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d980: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c8ae8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c8b2c: Changing call to branch */
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
/* WARNING: Removing unreachable block (ram,0x0044d8c0) */
/* WARNING: Removing unreachable block (ram,0x005c8b30) */
/* WARNING: Removing unreachable block (ram,0x005c869c) */
/* WARNING: Removing unreachable block (ram,0x0044dad0) */

void Battle_Sub5DF080(long *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined1 **ppuVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  uint *puVar14;
  long *plVar15;
  long lVar16;
  ulong uVar17;
  byte *pbVar18;
  byte *pbVar19;
  long *plVar20;
  undefined1 *extraout_x8;
  undefined1 *puVar21;
  ulong uVar22;
  ulong uVar23;
  undefined4 *puVar24;
  undefined4 *puVar25;
  undefined8 *puVar26;
  byte *pbVar27;
  byte *pbVar28;
  byte *pbVar29;
  byte *pbVar30;
  int *piVar31;
  ulong uVar32;
  byte *pbVar33;
  byte *pbVar34;
  ulong unaff_x25;
  long *unaff_x26;
  undefined8 unaff_x27;
  undefined8 unaff_x28;
  undefined1 **ppuVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  byte abStack_240 [144];
  byte abStack_1b0 [256];
  undefined1 *puStack_b0;
  undefined8 uStack_a8;
  
  ppuVar2 = (undefined1 **)&stack0xffffffffffffffb0;
  pbVar30 = (byte *)param_1[1];
  if (pbVar30 < (byte *)param_1[2]) {
    pbVar29 = pbVar30 + 4;
    *(undefined4 *)pbVar30 = *param_2;
    goto LAB_006df1c8;
  }
  pbVar27 = (byte *)*param_1;
  pbVar34 = pbVar30 + -(long)pbVar27;
  uVar32 = (long)pbVar34 >> 2;
  uVar23 = uVar32 + 1;
  if (uVar23 >> 0x3e == 0) {
    uVar22 = param_1[2] - (long)pbVar27;
    unaff_x25 = (long)uVar22 >> 1;
    if (unaff_x25 <= uVar23) {
      unaff_x25 = uVar23;
    }
    if (0x7ffffffffffffffb < uVar22) {
      unaff_x25 = 0x3fffffffffffffff;
    }
    if (unaff_x25 == 0) {
      lVar16 = 0;
    }
    else {
      if (unaff_x25 >> 0x3e != 0) goto LAB_006df1ec;
      lVar16 = func_0x00bc3330(unaff_x25 << 2);
    }
    puVar25 = (undefined4 *)(lVar16 + uVar32 * 4);
    pbVar29 = (byte *)(puVar25 + 1);
    *puVar25 = *param_2;
    if ((long)pbVar30 - (long)pbVar27 != 0) {
      uVar23 = ((long)pbVar30 - (long)pbVar27) - 4;
      puVar24 = puVar25;
      if ((0x1b < uVar23) && ((byte *)0x1f < pbVar30 + (-(long)pbVar34 - lVar16))) {
        pbVar34 = pbVar30 + -0x10;
        uVar23 = (uVar23 >> 2) + 1;
        uVar22 = uVar23 & 0x7ffffffffffffff8;
        pbVar30 = pbVar30 + uVar22 * -4;
        puVar24 = puVar25 + -uVar22;
        puVar26 = (undefined8 *)(puVar25 + -4);
        uVar32 = uVar22;
        do {
          pbVar19 = pbVar34 + -8;
          uVar38 = *(undefined8 *)(pbVar34 + -0x10);
          uVar37 = *(undefined8 *)(pbVar34 + 8);
          uVar36 = *(undefined8 *)pbVar34;
          uVar32 = uVar32 - 8;
          pbVar34 = pbVar34 + -0x20;
          puVar26[-1] = *(undefined8 *)pbVar19;
          puVar26[-2] = uVar38;
          puVar26[1] = uVar37;
          *puVar26 = uVar36;
          puVar26 = puVar26 + -4;
        } while (uVar32 != 0);
        puVar25 = puVar24;
        if (uVar23 == uVar22) goto LAB_006df1b4;
      }
      do {
        pbVar30 = pbVar30 + -4;
        puVar25 = puVar24 + -1;
        *puVar25 = *(undefined4 *)pbVar30;
        puVar24 = puVar25;
      } while (pbVar30 != pbVar27);
    }
LAB_006df1b4:
    *param_1 = (long)puVar25;
    param_1[1] = (long)pbVar29;
    param_1[2] = lVar16 + unaff_x25 * 4;
    if (pbVar27 != (byte *)0x0) {
      func_0x00bc3350(pbVar27);
    }
LAB_006df1c8:
    param_1[1] = (long)pbVar29;
    return;
  }
  func_0x00441cdc(param_1);
LAB_006df1ec:
  auVar40 = func_0x0040fc1c();
  plVar20 = auVar40._0_8_;
  uStack_a8 = 0x6df1f0;
  uVar23 = auVar40._8_8_ & 0xffffffff;
  iVar4 = auVar40._8_4_;
  lVar16 = (long)iVar4;
  if ((&UNK_003285e8)[(long)plVar20 + lVar16] == '\0') {
    return;
  }
  plVar15 = plVar20 + 0x106d3;
  puStack_b0 = &stack0xffffffffffffffb0;
  func_0x009aa848(plVar20 + 0x6770a);
  lVar12 = (long)plVar20 + lVar16 * 4;
  if ((int)plVar20[0x520ac] < 1) {
    if (*(int *)(&UNK_003285ec + lVar12) == 0) goto LAB_006df278;
  }
  else {
    *(undefined4 *)(&UNK_003285ec + lVar12) = 0;
LAB_006df278:
    *(undefined8 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32868c) = 0xffffffffffffffff;
    *(undefined8 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x328674) = 0xffffffffffffffff;
    *(undefined8 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32866c) = 0xffffffffffffffff;
    *(undefined8 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x328684) = 0xffffffffffffffff;
    *(undefined8 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32867c) = 0xffffffffffffffff;
    iVar9 = func_0x00a58874(auVar40._8_8_ & 0xffffffff,1);
    if (iVar9 == 0) {
      bVar3 = false;
    }
    else {
      iVar9 = 2;
      do {
        iVar11 = iVar9;
        if (iVar11 == 0x33) break;
        iVar10 = func_0x00a58874(uVar23,iVar11);
        iVar9 = iVar11 + 1;
      } while (iVar10 != 0);
      bVar3 = 0x31 < iVar11 - 1U;
    }
    uVar22 = 0;
    do {
      uVar17 = func_0x005abee8(uVar23,uVar22 & 0xffffffff);
      if (((((uVar17 & 1) == 0) ||
           (uVar17 = func_0x005aba0c(uVar23,uVar22 & 0xffffffff,1), (uVar17 & 1) == 0)) ||
          (uVar17 = func_0x009aa8cc(plVar20 + 0x6770a,uVar22 & 0xffffffff), (uVar17 & 1) != 0)) ||
         (uVar17 = func_0x005aed30(uVar23,uVar22 & 0xffffffff), (uVar17 & 1) != 0)) {
LAB_006df37c:
        *(undefined4 *)(&UNK_003285fc + (long)(plVar20 + (long)iVar4 * 5) + uVar22 * 4) = 0xffffffff
        ;
      }
      else {
        iVar9 = func_0x005b21ec(plVar20 + (long)iVar4 * 0x3e + 0x4c9,uVar22 & 0xffffffff);
        bVar1 = bVar3;
        if (iVar9 != 0) {
          bVar1 = true;
        }
        if (bVar1) goto LAB_006df37c;
        *(int *)(&UNK_003285fc + (long)(plVar20 + (long)iVar4 * 5) + uVar22 * 4) = (int)uVar22;
      }
      uVar22 = uVar22 + 1;
    } while (uVar22 != 10);
    iVar9 = func_0x0043ea60(100);
    if ((iVar9 < 0x1e) || ((int)plVar20[0x520ac] == 1)) {
      iVar9 = func_0x005b1f30(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
      if (iVar9 == 7) {
        uVar22 = 0;
        iVar9 = 0;
        do {
          if (((*(int *)((long)plVar20 + (long)(&UNK_003285fc + uVar22 * 4 + (long)iVar4 * 0x28)) !=
                -1) && (uVar17 = func_0x005abee8(uVar23,uVar22 & 0xffffffff), (uVar17 & 1) != 0)) &&
             ((uVar17 = func_0x005aba0c(uVar23,uVar22 & 0xffffffff,1), (uVar17 & 1) != 0 &&
              (uVar17 = func_0x009aa8cc(plVar20 + 0x6770a,uVar22 & 0xffffffff), (uVar17 & 1) == 0)))
             ) {
            iVar11 = func_0x005b1cc8(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
            iVar10 = func_0x005ad22c(uVar23,uVar22 & 0xffffffff);
            if (iVar10 <= iVar11) {
              lVar13 = (long)iVar9;
              iVar9 = iVar9 + 1;
              *(int *)(&UNK_0032866c + (long)plVar20 + lVar13 * 4 + (long)iVar4 * 0x28) =
                   (int)uVar22;
            }
          }
          uVar22 = uVar22 + 1;
        } while (uVar22 != 10);
        if (iVar9 == 0) goto LAB_006df7e8;
        if ((int)plVar20[0x520ac] != 0) goto LAB_006df7f0;
        uVar8 = func_0x0043ea60(iVar9);
        *(undefined4 *)(&UNK_003285f4 + lVar12) = uVar8;
        iVar9 = 3;
      }
      else {
        iVar9 = 2;
      }
    }
    else {
      bVar3 = *(int *)((long)plVar20 + (long)iVar4 * 0x28 + 0x3285fc) != -1;
      if (bVar3) {
        *(undefined4 *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32866c) = 0;
      }
      uVar22 = (ulong)bVar3;
      if ((int)plVar20[(long)iVar4 * 5 + 0x650c0] != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)(bVar3 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 1;
      }
      if (*(int *)((long)plVar20 + (long)iVar4 * 0x28 + 0x328604) != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 2;
      }
      if ((int)plVar20[(long)iVar4 * 5 + 0x650c1] != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 3;
      }
      if (*(int *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32860c) != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 4;
      }
      if ((int)plVar20[(long)iVar4 * 5 + 0x650c2] != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 5;
      }
      if (*(int *)((long)plVar20 + (long)iVar4 * 0x28 + 0x328614) != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 6;
      }
      if ((int)plVar20[(long)iVar4 * 5 + 0x650c3] != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 7;
      }
      if (*(int *)((long)plVar20 + (long)iVar4 * 0x28 + 0x32861c) != -1) {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 8;
      }
      if ((int)plVar20[(long)iVar4 * 5 + 0x650c4] == -1) {
        if ((int)uVar22 != 0) goto LAB_006df748;
        *(undefined4 *)(&UNK_003285ec + lVar12) = 0;
LAB_006df7d8:
        iVar9 = func_0x005b1f30(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
        if (iVar9 == 7) {
LAB_006df7e8:
          iVar9 = 0;
        }
        else {
          iVar9 = func_0x005b2020(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
          if (iVar9 < 7) goto LAB_006df7f0;
          iVar9 = 2;
        }
      }
      else {
        lVar13 = uVar22 * 4;
        uVar22 = (ulong)((int)uVar22 + 1);
        *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar13 + (long)iVar4 * 0x28) = 9;
LAB_006df748:
        if ((int)plVar20[0x520ac] == 0) {
          uVar8 = func_0x0043ea60(uVar22);
          *(undefined4 *)(&UNK_003285f4 + lVar12) = uVar8;
          *(undefined4 *)(&UNK_003285ec + lVar12) = 3;
        }
        else if (*(int *)(&UNK_003285ec + lVar12) == 0) goto LAB_006df7d8;
        iVar9 = func_0x005b1cc8(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
        iVar11 = func_0x005ad22c(uVar23,*(undefined4 *)
                                         (&UNK_0032866c +
                                         (long)plVar20 +
                                         (long)*(int *)(&UNK_003285f4 + lVar12) * 4 +
                                         (long)iVar4 * 0x28));
        if (iVar11 <= iVar9) goto LAB_006df7f0;
        iVar9 = func_0x005b1f30(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
        iVar9 = (uint)(iVar9 != 7) << 1;
      }
    }
    *(int *)(&UNK_003285ec + lVar12) = iVar9;
  }
LAB_006df7f0:
  if (((int)plVar20[(long)iVar4 * 0x18e7 + 0x10727] == 0) &&
     (iVar9 = func_0x00a578c8(uVar23), iVar9 == 0)) {
    lVar13 = 0x32;
    piVar31 = (int *)((long)plVar20 + (long)iVar4 * -51000 + 0x90434);
    do {
      if ((piVar31[-3] != 0) && (piVar31[-2] != 4)) {
        *(int *)((long)plVar20 + 0x327dbc) = (*piVar31 - (int)*plVar15) / 10;
        uVar22 = func_0x005aebdc(uVar23);
        if (((uVar22 & 1) != 0) && (*(int *)(&UNK_00328654 + lVar12) == 0)) {
          *(undefined4 *)(&UNK_00328654 + lVar12) = 1;
        }
      }
      lVar13 = lVar13 + -1;
      piVar31 = piVar31 + 0xfa;
    } while (lVar13 != 0);
    lVar13 = 0x32;
    piVar31 = (int *)((long)plVar20 + (long)iVar4 * -51000 + 0x90434);
    do {
      iVar9 = func_0x005aeb6c(uVar23);
      *(int *)(plVar20 + 0x64fb7) = iVar9;
      if (piVar31[-3] != 0) {
        iVar11 = (*piVar31 - (int)*plVar15) / 10;
        *(int *)((long)plVar20 + 0x327dbc) = iVar11;
        if (iVar4 == 1) {
          if (iVar11 < iVar9 + -200) goto LAB_006dfa74;
        }
        else if ((iVar4 == 0) && (iVar9 + -200 < iVar11)) {
LAB_006dfa74:
          *(undefined4 *)(&UNK_00328654 + lVar12) = 0;
          *(undefined4 *)(&UNK_003285ec + lVar12) = 1;
        }
      }
      lVar13 = lVar13 + -1;
      piVar31 = piVar31 + 0xfa;
    } while (lVar13 != 0);
  }
  iVar9 = *(int *)(&UNK_00328654 + lVar12);
  if (iVar9 < 3) {
    if (iVar9 == 1) {
      uVar8 = func_0x0043ea60(0x96);
      *(undefined4 *)((long)plVar20 + lVar16 * 8 + 0x32865c) = uVar8;
      iVar9 = 2;
      goto LAB_006df8d8;
    }
    if ((iVar9 == 2) &&
       (iVar9 = *(int *)((long)plVar20 + lVar16 * 8 + 0x32865c), iVar11 = iVar9 + -1,
       *(int *)((long)plVar20 + lVar16 * 8 + 0x32865c) = iVar11, iVar11 == 0 || iVar9 < 1)) {
      iVar9 = func_0x0043ea60(2);
      iVar9 = iVar9 + 3;
      goto LAB_006df8d8;
    }
  }
  else {
    if (iVar9 == 3) {
      if (((int)plVar20[(long)iVar4 * 0x18e7 + 0x10727] == 0) &&
         (iVar9 = func_0x00a578c8(uVar23), iVar9 == 0)) {
        lVar16 = 0x32;
        piVar31 = (int *)((long)plVar20 + (long)iVar4 * -51000 + 0x90434);
        do {
          if ((piVar31[-3] != 0) && (piVar31[-2] != 4)) {
            *(int *)((long)plVar20 + 0x327dbc) = (*piVar31 - (int)*plVar15) / 10;
            uVar22 = func_0x005aebdc(uVar23);
            if ((uVar22 & 1) != 0) {
              *(undefined4 *)(&UNK_003285ec + lVar12) = 1;
            }
          }
          lVar16 = lVar16 + -1;
          piVar31 = piVar31 + 0xfa;
        } while (lVar16 != 0);
        iVar9 = 0;
        goto LAB_006df8d8;
      }
    }
    else if (iVar9 != 4) goto LAB_006df8dc;
    iVar9 = 0;
LAB_006df8d8:
    *(int *)(&UNK_00328654 + lVar12) = iVar9;
  }
LAB_006df8dc:
  if (-1 < *(int *)(&UNK_0032866c +
                   (long)plVar20 + (long)*(int *)(&UNK_003285f4 + lVar12) * 4 + (long)iVar4 * 0x28))
  {
    iVar9 = func_0x005b1bf4(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    iVar11 = func_0x005ad22c(uVar23,*(undefined4 *)
                                     (&UNK_0032866c +
                                     (long)plVar20 +
                                     (long)*(int *)(&UNK_003285f4 + lVar12) * 4 + (long)iVar4 * 0x28
                                     ));
    if (((iVar11 <= iVar9) &&
        (uVar7 = *(uint *)(&UNK_0032866c +
                          (long)plVar20 +
                          (long)*(int *)(&UNK_003285f4 + lVar12) * 4 + (long)iVar4 * 0x28),
        -1 < (int)uVar7)) &&
       (((iVar9 = (int)plVar20[0x64dfa], 4 < uVar7 && (iVar9 == 0)) || ((uVar7 < 5 && (iVar9 == 1)))
        ))) {
      if (*(char *)((long)plVar20 + 0x326fec) == '\0') {
        *(undefined4 *)((long)plVar20 + 0x32666c) = 1;
        *(undefined4 *)(plVar20 + 0x64dfd) = 1;
      }
      else if (*(int *)((long)plVar20 + 0x32666c) == -1) {
        uVar8 = 1;
        if ((int)plVar20[0x64dfd] == 1) goto LAB_006dfb2c;
      }
      else if ((*(int *)((long)plVar20 + 0x32666c) == 1) && ((int)plVar20[0x64dfd] == 0)) {
        uVar8 = 0xffffffff;
LAB_006dfb2c:
        *(undefined4 *)((long)plVar20 + 0x32666c) = uVar8;
      }
      *(undefined1 *)((long)plVar20 + 0x326fec) = 1;
    }
  }
  iVar9 = *(int *)(&UNK_003285ec + lVar12);
  if ((2 < iVar9) && (0 < (int)plVar20[0x520ac])) {
LAB_006dfb58:
    *(undefined4 *)(&UNK_003285ec + lVar12) = 0;
    return;
  }
  pbVar29 = pbVar30;
  if (iVar9 == 2) {
    iVar9 = func_0x005b1f30(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    if (iVar9 == 7) goto LAB_006dfb58;
    iVar9 = func_0x005b1cc8(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    iVar11 = func_0x005b1f74(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    if (iVar9 < iVar11) {
      *(undefined4 *)(&UNK_003285ec + lVar12) = 0;
    }
    iVar9 = func_0x005b1bf4(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    iVar11 = func_0x005b1f74(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    if (iVar9 < iVar11) {
      return;
    }
    iVar9 = 0;
    iVar11 = 0;
    *(undefined4 *)(&UNK_003285ec + lVar12) = 0;
    do {
      uVar22 = func_0x005abee8(uVar23,iVar9);
      if (((uVar22 & 1) != 0) && (uVar22 = func_0x005aba0c(uVar23,iVar9,1), (uVar22 & 1) != 0)) {
        uVar7 = func_0x009aa8cc(plVar20 + 0x6770a,iVar9);
        iVar11 = iVar11 + ((uVar7 ^ 0xffffffff) & 1);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 10);
    if (iVar11 == 0) {
      lVar16 = 0;
    }
    else {
      iVar9 = func_0x0043ea60(iVar11);
      lVar16 = (long)iVar9;
    }
    iVar9 = 0;
    *(undefined4 *)(&UNK_0032864c + lVar12) =
         *(undefined4 *)(&UNK_0032866c + (long)plVar20 + lVar16 * 4 + (long)iVar4 * 0x28);
    do {
      uVar22 = func_0x005abee8(uVar23,iVar9);
      if (((((uVar22 & 1) != 0) && (uVar22 = func_0x005aba0c(uVar23,iVar9,1), (uVar22 & 1) != 0)) &&
          (uVar22 = func_0x009aa8cc(plVar20 + 0x6770a,iVar9), (uVar22 & 1) == 0)) &&
         (iVar11 = *(int *)(&UNK_0032864c + lVar12), iVar10 = func_0x005ab37c(uVar23,iVar9),
         iVar11 == iVar10)) {
        iVar11 = func_0x005b1cc8(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
        iVar10 = func_0x005ad22c(uVar23,iVar9);
        if (iVar11 < iVar10) {
          *(undefined4 *)(&UNK_0032864c + lVar12) = 0xffffffff;
          break;
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 10);
    iVar9 = func_0x005b1f74(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
    func_0x005b1e64(plVar20 + (long)iVar4 * 0x3e + 0x4c9,-iVar9);
    func_0x005b217c(plVar20 + (long)iVar4 * 0x3e + 0x4c9,1);
    *(undefined4 *)(plVar20 + 0x106dd) = 0xe;
    plVar15 = (long *)func_0x0044c16c();
    uVar23 = 0x13;
    ppuVar35 = (undefined1 **)puStack_b0;
    uVar36 = uStack_a8;
  }
  else {
    if (iVar9 != 1) {
      if (iVar9 < 3) {
        return;
      }
      iVar9 = func_0x005b1bf4(plVar20 + (long)iVar4 * 0x3e + 0x4c9);
      iVar11 = func_0x005ad22c(uVar23,*(undefined4 *)
                                       (&UNK_0032866c +
                                       (long)plVar20 +
                                       (long)*(int *)(&UNK_003285f4 + lVar12) * 4 +
                                       (long)iVar4 * 0x28));
      if (iVar9 < iVar11) {
        return;
      }
      if (*(char *)((long)plVar20 + 0x326fec) != '\0') {
        return;
      }
      iVar9 = (int)plVar20[0x64dfa];
      if (iVar9 == 0) {
        uVar7 = *(uint *)(&UNK_0032866c +
                         (long)plVar20 +
                         (long)*(int *)(&UNK_003285f4 + lVar12) * 4 + (long)iVar4 * 0x28);
        if (4 < uVar7) {
          return;
        }
      }
      else {
        if (iVar9 != 1) {
          return;
        }
        uVar7 = *(uint *)(&UNK_0032866c +
                         (long)plVar20 +
                         (long)*(int *)(&UNK_003285f4 + lVar12) * 4 + (long)iVar4 * 0x28);
        if ((int)uVar7 < 5) {
          return;
        }
      }
      Battle_Sub8B99A0(plVar20,uVar23,uVar7,0);
      goto LAB_006dfb58;
    }
    ppuVar2 = &puStack_b0;
    pbVar27 = (byte *)0x0;
    iVar4 = func_0x00a57a4c(0);
    if ((iVar4 != 0) || (iVar4 = func_0x00a578c8(), iVar4 != 0)) {
      return;
    }
    *(undefined1 *)(plVar20 + 0x503) = 1;
    uVar36 = func_0x00a57c8c();
    param_1 = plVar20;
    if ((int)uVar36 == 0) {
      func_0x00a578fc(uVar36,1);
      func_0x00a57968(0,0);
      plVar15 = (long *)func_0x0044c16c();
      uVar23 = 0x19;
    }
    else {
      iVar4 = func_0x00a57c8c(0);
      if (iVar4 == 1) {
        func_0x00a578fc(0,3);
        func_0x00a57968(0,0);
        plVar15 = (long *)func_0x0044c16c();
        uVar23 = 0x3c;
      }
      else {
        iVar4 = func_0x00a57c8c(0);
        if (iVar4 == 7) {
          func_0x00a578fc(0,0xc);
          func_0x00a57968(0,0);
          plVar15 = (long *)func_0x0044c16c();
          uVar23 = 0x7c;
        }
        else {
          iVar4 = func_0x00a57c8c(0);
          if (iVar4 == 2) {
            uVar8 = func_0x005ab37c(0,10);
            iVar4 = func_0x005abf04(0,10);
            uVar5 = func_0x00a92ff4((long)plVar20 + (long)iVar4 * 8 + 0x47aac);
            iVar4 = func_0x005ab37c(0,10);
            iVar9 = func_0x005abf1c(0,10);
            unaff_x25 = 0x760;
            unaff_x27 = 0x1d8;
            unaff_x26 = plVar20 + 0x13caf;
            pbVar30 = (byte *)(ulong)*(uint *)(unaff_x26 +
                                              (long)iVar4 * 0xec + (long)iVar9 * 0x3b + 7);
            iVar4 = func_0x005ab37c(0,10);
            iVar9 = func_0x005abf1c(0,10);
            pbVar34 = (byte *)(ulong)*(uint *)((long)unaff_x26 +
                                              (long)iVar9 * 0x1d8 + (long)iVar4 * 0x760 + 0x3c);
            uVar6 = func_0x005abf1c(0,10);
            uVar7 = Battle_SpawnOrInitUnit(plVar20,0,uVar8,uVar5,pbVar30,pbVar34,uVar6,0);
            if ((int)uVar7 < 0) {
              return;
            }
            pbVar29 = (byte *)(ulong)uVar7;
            iVar4 = 0;
            iVar9 = 0xc80;
            do {
              iVar11 = func_0x00a58874(1,iVar4);
              if ((iVar11 == 2) && (iVar11 = func_0x00a5919c(1,iVar4), iVar9 < iVar11)) {
                iVar9 = func_0x00a5919c(1,iVar4);
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 != 0x33);
            iVar4 = func_0x00a58100(0);
            func_0x00a591dc(0,pbVar29,iVar4 + iVar9);
            uVar7 = func_0x00a5a194(0,pbVar29);
            pbVar27 = (byte *)(ulong)uVar7;
            iVar4 = func_0x00a57dd0(0);
            func_0x00a5a1d4(0,pbVar29,(int)(iVar4 * uVar7) / 100);
            uVar8 = func_0x00a5a194(0,pbVar29);
            func_0x00a5a260(0,pbVar29,uVar8);
            uVar8 = func_0x00a57ea8(0);
            func_0x00a59d88(0,pbVar29,uVar8);
            func_0x00a578fc(0,6);
            func_0x00a57968(0,0);
            plVar15 = (long *)func_0x0044c16c();
            uVar23 = 0x3d;
            uVar32 = 0x33;
          }
          else {
            pbVar27 = (byte *)0x9e538;
            iVar4 = func_0x00a57c8c(0);
            if (iVar4 == 3) {
              iVar4 = 0;
              pbVar27 = (byte *)(ulong)((int)plVar20[0x13ca7] - 0xc80);
              do {
                iVar9 = func_0x00a58874(0,iVar4);
                if (((iVar9 == 2) && (iVar9 = func_0x00a5919c(0,iVar4), iVar9 < (int)pbVar27)) &&
                   (uVar23 = func_0x00a58fec(0,iVar4), (uVar23 & 1) != 0)) {
                  uVar23 = func_0x00a5919c(0,iVar4);
                  pbVar27 = (byte *)(uVar23 & 0xffffffff);
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 != 0x33);
              func_0x00a578fc(0,4);
              func_0x00a57968(0,0);
              iVar4 = func_0x00a57e3c(0);
              if (iVar4 < 0) {
                iVar4 = iVar4 + 1;
              }
              func_0x00a57d2c(0,(int)pbVar27 - (iVar4 >> 1));
              plVar15 = (long *)func_0x0044c16c();
              uVar23 = 0x25;
              pbVar29 = (byte *)0x33;
            }
            else {
              iVar4 = func_0x00a57c8c(0);
              if (iVar4 == 4) {
                iVar4 = 0;
                pbVar27 = (byte *)(ulong)((int)plVar20[0x13ca7] - 0xc80);
                do {
                  iVar9 = func_0x00a58874(0,iVar4);
                  if (((iVar9 == 2) && (iVar9 = func_0x00a5919c(0,iVar4), iVar9 < (int)pbVar27)) &&
                     (uVar23 = func_0x00a58fec(0,iVar4), (uVar23 & 1) != 0)) {
                    uVar23 = func_0x00a5919c(0,iVar4);
                    pbVar27 = (byte *)(uVar23 & 0xffffffff);
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 != 0x33);
                func_0x00a578fc(0,7);
                func_0x00a57968(0,0);
                iVar4 = func_0x00a57e3c(0);
                if (iVar4 < 0) {
                  iVar4 = iVar4 + 1;
                }
                func_0x00a57d2c(0,(int)pbVar27 - (iVar4 >> 1));
                plVar15 = (long *)func_0x0044c16c();
                uVar23 = 0x41;
                pbVar29 = (byte *)0x33;
              }
              else {
                iVar4 = func_0x00a57c8c(0);
                if (iVar4 != 5) {
                  iVar4 = func_0x00a57c8c(0);
                  if (iVar4 == 6) {
                    iVar4 = 0;
                    iVar9 = 0xc80;
                    do {
                      iVar11 = func_0x00a58874(1,iVar4);
                      if ((iVar11 == 2) && (iVar11 = func_0x00a5919c(1,iVar4), iVar9 < iVar11)) {
                        iVar9 = func_0x00a5919c(1,iVar4);
                      }
                      iVar4 = iVar4 + 1;
                    } while (iVar4 != 0x33);
                    func_0x00a578fc(0,0xb);
                    func_0x00a57968(0,0);
                    func_0x00a57d2c(0,iVar9);
                  }
                  pbVar27 = &UNK_003bb790;
                  uVar8 = func_0x00a579e0(0);
                  func_0x00a57a80(0,uVar8);
                  uVar32 = 1;
                  func_0x00a57b24(0,1);
                  plVar15 = (long *)func_0x0044c16c();
                  uVar23 = 0x13;
                  pbVar29 = (byte *)((long)plVar20 + 0x32660c);
                  ppuVar35 = &puStack_b0;
                  uVar36 = 0x5c8b30;
                  goto LAB_0044d5c0;
                }
                func_0x00a578fc(0,9);
                func_0x00a57968(0,0);
                plVar15 = (long *)func_0x0044c16c();
                uVar23 = 0x54;
              }
            }
          }
        }
      }
    }
    ppuVar2 = &puStack_b0;
    ppuVar35 = &puStack_b0;
    uVar36 = 0x5c8aec;
  }
LAB_0044d5c0:
  pbVar19 = (byte *)0x0;
  *(undefined1 ***)((long)ppuVar2 + -0x60) = ppuVar35;
  *(undefined8 *)((long)ppuVar2 + -0x58) = uVar36;
  *(undefined8 *)((long)ppuVar2 + -0x50) = unaff_x28;
  *(undefined8 *)((long)ppuVar2 + -0x48) = unaff_x27;
  *(long **)((long)ppuVar2 + -0x40) = unaff_x26;
  *(ulong *)((long)ppuVar2 + -0x38) = unaff_x25;
  *(byte **)((long)ppuVar2 + -0x30) = pbVar34;
  *(byte **)((long)ppuVar2 + -0x28) = pbVar30;
  *(ulong *)((long)ppuVar2 + -0x20) = uVar32;
  *(byte **)((long)ppuVar2 + -0x18) = pbVar29;
  *(byte **)((long)ppuVar2 + -0x10) = pbVar27;
  *(long **)((long)ppuVar2 + -8) = param_1;
  lVar16 = tpidr_el0;
  *(undefined8 *)((long)ppuVar2 + -0x68) = *(undefined8 *)(lVar16 + 0x28);
  if ((ulong)(long)(int)uVar23 < (ulong)(plVar15[2] - plVar15[1] >> 2)) {
    pbVar27 = (byte *)0x0;
    pbVar28 = (byte *)0x0;
    pbVar18 = pbVar19;
    if ((int)uVar23 == 0x1d) {
      lVar12 = func_0x007fd748();
      if (*(int *)(&LAB_00440e50 + lVar12) != -1) {
        lVar12 = func_0x007fd748();
        lVar13 = func_0x007fd748();
        plVar20 = *(long **)(lVar12 + 0x2618);
        if (plVar20 != (long *)0x0) {
          do {
            if ((int)plVar20[4] <= *(int *)(&LAB_00440e50 + lVar13)) {
              if (*(int *)(&LAB_00440e50 + lVar13) <= (int)plVar20[4]) {
                lVar12 = func_0x007fd748();
                lVar13 = func_0x007fd748();
                iVar4 = *(int *)(&LAB_00440e50 + lVar13);
                pbVar29 = *(byte **)(lVar12 + 0x2618);
                if (*(byte **)(lVar12 + 0x2618) != (byte *)0x0) goto LAB_0044d6d8;
                pbVar33 = (byte *)(lVar12 + 0x2618);
                pbVar34 = (byte *)(lVar12 + 0x2618);
                goto LAB_0044d6fc;
              }
              plVar20 = plVar20 + 1;
            }
            plVar20 = (long *)*plVar20;
          } while (plVar20 != (long *)0x0);
        }
      }
      goto LAB_0044d7dc;
    }
    goto LAB_0044d7e0;
  }
  *(undefined2 *)((long)ppuVar2 + -0x80) = 0;
  func_0x0056a6f0((undefined1 *)((long)ppuVar2 + -0x80),3);
  pbVar18 = pbVar19;
  plVar15 = param_1;
  if ((*(byte *)((long)ppuVar2 + -0x80) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)ppuVar2 + -0x70));
    pbVar18 = pbVar19;
  }
  goto LAB_0044dd88;
  while (pbVar29 = *(byte **)pbVar30, pbVar34 = pbVar30, *(byte **)pbVar30 != (byte *)0x0) {
LAB_0044d6d8:
    pbVar30 = pbVar29;
    pbVar33 = pbVar30;
    if (*(int *)(pbVar30 + 0x20) <= iVar4) {
      if (iVar4 <= *(int *)(pbVar30 + 0x20)) goto LAB_0044d7a0;
      pbVar29 = *(byte **)(pbVar30 + 8);
      if (*(byte **)(pbVar30 + 8) == (byte *)0x0) {
        pbVar34 = pbVar30 + 8;
        break;
      }
      goto LAB_0044d6d8;
    }
  }
LAB_0044d6fc:
  pbVar30 = (byte *)func_0x00bc3330(0x160);
  pbVar30[0x158] = 0;
  pbVar30[0x159] = 0;
  pbVar30[0x15a] = 0;
  pbVar30[0x15b] = 0;
  pbVar30[0x15c] = 0;
  pbVar30[0x15d] = 0;
  pbVar30[0x15e] = 0;
  pbVar30[0x15f] = 0;
  *(int *)(pbVar30 + 0x20) = iVar4;
  pbVar30[0] = 0;
  pbVar30[1] = 0;
  pbVar30[2] = 0;
  pbVar30[3] = 0;
  pbVar30[4] = 0;
  pbVar30[5] = 0;
  pbVar30[6] = 0;
  pbVar30[7] = 0;
  pbVar30[8] = 0;
  pbVar30[9] = 0;
  pbVar30[10] = 0;
  pbVar30[0xb] = 0;
  pbVar30[0xc] = 0;
  pbVar30[0xd] = 0;
  pbVar30[0xe] = 0;
  pbVar30[0xf] = 0;
  *(byte **)(pbVar30 + 0x10) = pbVar33;
  pbVar30[0x110] = 0;
  pbVar30[0x111] = 0;
  pbVar30[0x112] = 0;
  pbVar30[0x113] = 0;
  pbVar30[0x114] = 0;
  pbVar30[0x115] = 0;
  pbVar30[0x116] = 0;
  pbVar30[0x117] = 0;
  pbVar30[0x108] = 0;
  pbVar30[0x109] = 0;
  pbVar30[0x10a] = 0;
  pbVar30[0x10b] = 0;
  pbVar30[0x10c] = 0;
  pbVar30[0x10d] = 0;
  pbVar30[0x10e] = 0;
  pbVar30[0x10f] = 0;
  pbVar30[0x120] = 0;
  pbVar30[0x121] = 0;
  pbVar30[0x122] = 0;
  pbVar30[0x123] = 0;
  pbVar30[0x124] = 0;
  pbVar30[0x125] = 0;
  pbVar30[0x126] = 0;
  pbVar30[0x127] = 0;
  pbVar30[0x118] = 0;
  pbVar30[0x119] = 0;
  pbVar30[0x11a] = 0;
  pbVar30[0x11b] = 0;
  pbVar30[0x11c] = 0;
  pbVar30[0x11d] = 0;
  pbVar30[0x11e] = 0;
  pbVar30[0x11f] = 0;
  pbVar30[0x40] = 0;
  pbVar30[0x41] = 0;
  pbVar30[0x42] = 0;
  pbVar30[0x43] = 0;
  pbVar30[0x44] = 0;
  pbVar30[0x45] = 0;
  pbVar30[0x46] = 0;
  pbVar30[0x47] = 0;
  pbVar30[0x38] = 0;
  pbVar30[0x39] = 0;
  pbVar30[0x3a] = 0;
  pbVar30[0x3b] = 0;
  pbVar30[0x3c] = 0;
  pbVar30[0x3d] = 0;
  pbVar30[0x3e] = 0;
  pbVar30[0x3f] = 0;
  pbVar30[0x50] = 0;
  pbVar30[0x51] = 0;
  pbVar30[0x52] = 0;
  pbVar30[0x53] = 0;
  pbVar30[0x54] = 0;
  pbVar30[0x55] = 0;
  pbVar30[0x56] = 0;
  pbVar30[0x57] = 0;
  pbVar30[0x48] = 0;
  pbVar30[0x49] = 0;
  pbVar30[0x4a] = 0;
  pbVar30[0x4b] = 0;
  pbVar30[0x4c] = 0;
  pbVar30[0x4d] = 0;
  pbVar30[0x4e] = 0;
  pbVar30[0x4f] = 0;
  pbVar30[0x60] = 0;
  pbVar30[0x61] = 0;
  pbVar30[0x62] = 0;
  pbVar30[99] = 0;
  pbVar30[100] = 0;
  pbVar30[0x65] = 0;
  pbVar30[0x66] = 0;
  pbVar30[0x67] = 0;
  pbVar30[0x58] = 0;
  pbVar30[0x59] = 0;
  pbVar30[0x5a] = 0;
  pbVar30[0x5b] = 0;
  pbVar30[0x5c] = 0;
  pbVar30[0x5d] = 0;
  pbVar30[0x5e] = 0;
  pbVar30[0x5f] = 0;
  pbVar30[0x70] = 0;
  pbVar30[0x71] = 0;
  pbVar30[0x72] = 0;
  pbVar30[0x73] = 0;
  pbVar30[0x74] = 0;
  pbVar30[0x75] = 0;
  pbVar30[0x76] = 0;
  pbVar30[0x77] = 0;
  pbVar30[0x68] = 0;
  pbVar30[0x69] = 0;
  pbVar30[0x6a] = 0;
  pbVar30[0x6b] = 0;
  pbVar30[0x6c] = 0;
  pbVar30[0x6d] = 0;
  pbVar30[0x6e] = 0;
  pbVar30[0x6f] = 0;
  pbVar30[0x80] = 0;
  pbVar30[0x81] = 0;
  pbVar30[0x82] = 0;
  pbVar30[0x83] = 0;
  pbVar30[0x84] = 0;
  pbVar30[0x85] = 0;
  pbVar30[0x86] = 0;
  pbVar30[0x87] = 0;
  pbVar30[0x78] = 0;
  pbVar30[0x79] = 0;
  pbVar30[0x7a] = 0;
  pbVar30[0x7b] = 0;
  pbVar30[0x7c] = 0;
  pbVar30[0x7d] = 0;
  pbVar30[0x7e] = 0;
  pbVar30[0x7f] = 0;
  pbVar30[0x90] = 0;
  pbVar30[0x91] = 0;
  pbVar30[0x92] = 0;
  pbVar30[0x93] = 0;
  pbVar30[0x94] = 0;
  pbVar30[0x95] = 0;
  pbVar30[0x96] = 0;
  pbVar30[0x97] = 0;
  pbVar30[0x88] = 0;
  pbVar30[0x89] = 0;
  pbVar30[0x8a] = 0;
  pbVar30[0x8b] = 0;
  pbVar30[0x8c] = 0;
  pbVar30[0x8d] = 0;
  pbVar30[0x8e] = 0;
  pbVar30[0x8f] = 0;
  pbVar30[0xa0] = 0;
  pbVar30[0xa1] = 0;
  pbVar30[0xa2] = 0;
  pbVar30[0xa3] = 0;
  pbVar30[0xa4] = 0;
  pbVar30[0xa5] = 0;
  pbVar30[0xa6] = 0;
  pbVar30[0xa7] = 0;
  pbVar30[0x98] = 0;
  pbVar30[0x99] = 0;
  pbVar30[0x9a] = 0;
  pbVar30[0x9b] = 0;
  pbVar30[0x9c] = 0;
  pbVar30[0x9d] = 0;
  pbVar30[0x9e] = 0;
  pbVar30[0x9f] = 0;
  pbVar30[0xb0] = 0;
  pbVar30[0xb1] = 0;
  pbVar30[0xb2] = 0;
  pbVar30[0xb3] = 0;
  pbVar30[0xb4] = 0;
  pbVar30[0xb5] = 0;
  pbVar30[0xb6] = 0;
  pbVar30[0xb7] = 0;
  pbVar30[0xa8] = 0;
  pbVar30[0xa9] = 0;
  pbVar30[0xaa] = 0;
  pbVar30[0xab] = 0;
  pbVar30[0xac] = 0;
  pbVar30[0xad] = 0;
  pbVar30[0xae] = 0;
  pbVar30[0xaf] = 0;
  pbVar30[0xc0] = 0;
  pbVar30[0xc1] = 0;
  pbVar30[0xc2] = 0;
  pbVar30[0xc3] = 0;
  pbVar30[0xc4] = 0;
  pbVar30[0xc5] = 0;
  pbVar30[0xc6] = 0;
  pbVar30[199] = 0;
  pbVar30[0xb8] = 0;
  pbVar30[0xb9] = 0;
  pbVar30[0xba] = 0;
  pbVar30[0xbb] = 0;
  pbVar30[0xbc] = 0;
  pbVar30[0xbd] = 0;
  pbVar30[0xbe] = 0;
  pbVar30[0xbf] = 0;
  pbVar30[0xd0] = 0;
  pbVar30[0xd1] = 0;
  pbVar30[0xd2] = 0;
  pbVar30[0xd3] = 0;
  pbVar30[0xd4] = 0;
  pbVar30[0xd5] = 0;
  pbVar30[0xd6] = 0;
  pbVar30[0xd7] = 0;
  pbVar30[200] = 0;
  pbVar30[0xc9] = 0;
  pbVar30[0xca] = 0;
  pbVar30[0xcb] = 0;
  pbVar30[0xcc] = 0;
  pbVar30[0xcd] = 0;
  pbVar30[0xce] = 0;
  pbVar30[0xcf] = 0;
  pbVar30[0xe0] = 0;
  pbVar30[0xe1] = 0;
  pbVar30[0xe2] = 0;
  pbVar30[0xe3] = 0;
  pbVar30[0xe4] = 0;
  pbVar30[0xe5] = 0;
  pbVar30[0xe6] = 0;
  pbVar30[0xe7] = 0;
  pbVar30[0xd8] = 0;
  pbVar30[0xd9] = 0;
  pbVar30[0xda] = 0;
  pbVar30[0xdb] = 0;
  pbVar30[0xdc] = 0;
  pbVar30[0xdd] = 0;
  pbVar30[0xde] = 0;
  pbVar30[0xdf] = 0;
  pbVar30[0xf0] = 0;
  pbVar30[0xf1] = 0;
  pbVar30[0xf2] = 0;
  pbVar30[0xf3] = 0;
  pbVar30[0xf4] = 0;
  pbVar30[0xf5] = 0;
  pbVar30[0xf6] = 0;
  pbVar30[0xf7] = 0;
  pbVar30[0xe8] = 0;
  pbVar30[0xe9] = 0;
  pbVar30[0xea] = 0;
  pbVar30[0xeb] = 0;
  pbVar30[0xec] = 0;
  pbVar30[0xed] = 0;
  pbVar30[0xee] = 0;
  pbVar30[0xef] = 0;
  pbVar30[0x100] = 0;
  pbVar30[0x101] = 0;
  pbVar30[0x102] = 0;
  pbVar30[0x103] = 0;
  pbVar30[0x104] = 0;
  pbVar30[0x105] = 0;
  pbVar30[0x106] = 0;
  pbVar30[0x107] = 0;
  pbVar30[0xf8] = 0;
  pbVar30[0xf9] = 0;
  pbVar30[0xfa] = 0;
  pbVar30[0xfb] = 0;
  pbVar30[0xfc] = 0;
  pbVar30[0xfd] = 0;
  pbVar30[0xfe] = 0;
  pbVar30[0xff] = 0;
  pbVar30[0x30] = 0;
  pbVar30[0x31] = 0;
  pbVar30[0x32] = 0;
  pbVar30[0x33] = 0;
  pbVar30[0x34] = 0;
  pbVar30[0x35] = 0;
  pbVar30[0x36] = 0;
  pbVar30[0x37] = 0;
  pbVar30[0x28] = 0;
  pbVar30[0x29] = 0;
  pbVar30[0x2a] = 0;
  pbVar30[0x2b] = 0;
  pbVar30[0x2c] = 0;
  pbVar30[0x2d] = 0;
  pbVar30[0x2e] = 0;
  pbVar30[0x2f] = 0;
  pbVar30[0x130] = 0;
  pbVar30[0x131] = 0;
  pbVar30[0x132] = 0;
  pbVar30[0x133] = 0;
  pbVar30[0x134] = 0;
  pbVar30[0x135] = 0;
  pbVar30[0x136] = 0;
  pbVar30[0x137] = 0;
  pbVar30[0x128] = 0;
  pbVar30[0x129] = 0;
  pbVar30[0x12a] = 0;
  pbVar30[299] = 0;
  pbVar30[300] = 0;
  pbVar30[0x12d] = 0;
  pbVar30[0x12e] = 0;
  pbVar30[0x12f] = 0;
  pbVar30[0x140] = 0;
  pbVar30[0x141] = 0;
  pbVar30[0x142] = 0;
  pbVar30[0x143] = 0;
  pbVar30[0x144] = 0;
  pbVar30[0x145] = 0;
  pbVar30[0x146] = 0;
  pbVar30[0x147] = 0;
  pbVar30[0x138] = 0;
  pbVar30[0x139] = 0;
  pbVar30[0x13a] = 0;
  pbVar30[0x13b] = 0;
  pbVar30[0x13c] = 0;
  pbVar30[0x13d] = 0;
  pbVar30[0x13e] = 0;
  pbVar30[0x13f] = 0;
  pbVar30[0x150] = 0;
  pbVar30[0x151] = 0;
  pbVar30[0x152] = 0;
  pbVar30[0x153] = 0;
  pbVar30[0x154] = 0;
  pbVar30[0x155] = 0;
  pbVar30[0x156] = 0;
  pbVar30[0x157] = 0;
  pbVar30[0x148] = 0;
  pbVar30[0x149] = 0;
  pbVar30[0x14a] = 0;
  pbVar30[0x14b] = 0;
  pbVar30[0x14c] = 0;
  pbVar30[0x14d] = 0;
  pbVar30[0x14e] = 0;
  pbVar30[0x14f] = 0;
  *(byte **)pbVar34 = pbVar30;
  pbVar29 = pbVar30;
  if (**(long **)(lVar12 + 0x2610) != 0) {
    *(long *)(lVar12 + 0x2610) = **(long **)(lVar12 + 0x2610);
    pbVar29 = *(byte **)pbVar34;
  }
  func_0x0040a8c0(*(undefined8 *)(lVar12 + 0x2618),pbVar29);
  *(long *)(lVar12 + 0x2620) = *(long *)(lVar12 + 0x2620) + 1;
LAB_0044d7a0:
  if (*(int *)(pbVar30 + 0x150) == -1) {
LAB_0044d7dc:
    uVar23 = 0x1d;
  }
  else {
    lVar12 = func_0x007fd748();
    lVar13 = func_0x007fd748();
    iVar4 = *(int *)(&LAB_00440e50 + lVar13);
    pbVar29 = *(byte **)(lVar12 + 0x2618);
    if (*(byte **)(lVar12 + 0x2618) == (byte *)0x0) {
      pbVar33 = (byte *)(lVar12 + 0x2618);
      pbVar34 = (byte *)(lVar12 + 0x2618);
    }
    else {
      do {
        while (pbVar30 = pbVar29, pbVar33 = pbVar30, *(int *)(pbVar30 + 0x20) <= iVar4) {
          if (iVar4 <= *(int *)(pbVar30 + 0x20)) goto LAB_0044dbc8;
          pbVar29 = *(byte **)(pbVar30 + 8);
          if (*(byte **)(pbVar30 + 8) == (byte *)0x0) {
            pbVar34 = pbVar30 + 8;
            goto LAB_0044db24;
          }
        }
        pbVar29 = *(byte **)pbVar30;
        pbVar34 = pbVar30;
      } while (*(byte **)pbVar30 != (byte *)0x0);
    }
LAB_0044db24:
    pbVar30 = (byte *)func_0x00bc3330(0x160);
    pbVar30[0x158] = 0;
    pbVar30[0x159] = 0;
    pbVar30[0x15a] = 0;
    pbVar30[0x15b] = 0;
    pbVar30[0x15c] = 0;
    pbVar30[0x15d] = 0;
    pbVar30[0x15e] = 0;
    pbVar30[0x15f] = 0;
    *(int *)(pbVar30 + 0x20) = iVar4;
    pbVar30[0] = 0;
    pbVar30[1] = 0;
    pbVar30[2] = 0;
    pbVar30[3] = 0;
    pbVar30[4] = 0;
    pbVar30[5] = 0;
    pbVar30[6] = 0;
    pbVar30[7] = 0;
    pbVar30[8] = 0;
    pbVar30[9] = 0;
    pbVar30[10] = 0;
    pbVar30[0xb] = 0;
    pbVar30[0xc] = 0;
    pbVar30[0xd] = 0;
    pbVar30[0xe] = 0;
    pbVar30[0xf] = 0;
    *(byte **)(pbVar30 + 0x10) = pbVar33;
    pbVar30[0x110] = 0;
    pbVar30[0x111] = 0;
    pbVar30[0x112] = 0;
    pbVar30[0x113] = 0;
    pbVar30[0x114] = 0;
    pbVar30[0x115] = 0;
    pbVar30[0x116] = 0;
    pbVar30[0x117] = 0;
    pbVar30[0x108] = 0;
    pbVar30[0x109] = 0;
    pbVar30[0x10a] = 0;
    pbVar30[0x10b] = 0;
    pbVar30[0x10c] = 0;
    pbVar30[0x10d] = 0;
    pbVar30[0x10e] = 0;
    pbVar30[0x10f] = 0;
    pbVar30[0x120] = 0;
    pbVar30[0x121] = 0;
    pbVar30[0x122] = 0;
    pbVar30[0x123] = 0;
    pbVar30[0x124] = 0;
    pbVar30[0x125] = 0;
    pbVar30[0x126] = 0;
    pbVar30[0x127] = 0;
    pbVar30[0x118] = 0;
    pbVar30[0x119] = 0;
    pbVar30[0x11a] = 0;
    pbVar30[0x11b] = 0;
    pbVar30[0x11c] = 0;
    pbVar30[0x11d] = 0;
    pbVar30[0x11e] = 0;
    pbVar30[0x11f] = 0;
    pbVar30[0x40] = 0;
    pbVar30[0x41] = 0;
    pbVar30[0x42] = 0;
    pbVar30[0x43] = 0;
    pbVar30[0x44] = 0;
    pbVar30[0x45] = 0;
    pbVar30[0x46] = 0;
    pbVar30[0x47] = 0;
    pbVar30[0x38] = 0;
    pbVar30[0x39] = 0;
    pbVar30[0x3a] = 0;
    pbVar30[0x3b] = 0;
    pbVar30[0x3c] = 0;
    pbVar30[0x3d] = 0;
    pbVar30[0x3e] = 0;
    pbVar30[0x3f] = 0;
    pbVar30[0x50] = 0;
    pbVar30[0x51] = 0;
    pbVar30[0x52] = 0;
    pbVar30[0x53] = 0;
    pbVar30[0x54] = 0;
    pbVar30[0x55] = 0;
    pbVar30[0x56] = 0;
    pbVar30[0x57] = 0;
    pbVar30[0x48] = 0;
    pbVar30[0x49] = 0;
    pbVar30[0x4a] = 0;
    pbVar30[0x4b] = 0;
    pbVar30[0x4c] = 0;
    pbVar30[0x4d] = 0;
    pbVar30[0x4e] = 0;
    pbVar30[0x4f] = 0;
    pbVar30[0x60] = 0;
    pbVar30[0x61] = 0;
    pbVar30[0x62] = 0;
    pbVar30[99] = 0;
    pbVar30[100] = 0;
    pbVar30[0x65] = 0;
    pbVar30[0x66] = 0;
    pbVar30[0x67] = 0;
    pbVar30[0x58] = 0;
    pbVar30[0x59] = 0;
    pbVar30[0x5a] = 0;
    pbVar30[0x5b] = 0;
    pbVar30[0x5c] = 0;
    pbVar30[0x5d] = 0;
    pbVar30[0x5e] = 0;
    pbVar30[0x5f] = 0;
    pbVar30[0x70] = 0;
    pbVar30[0x71] = 0;
    pbVar30[0x72] = 0;
    pbVar30[0x73] = 0;
    pbVar30[0x74] = 0;
    pbVar30[0x75] = 0;
    pbVar30[0x76] = 0;
    pbVar30[0x77] = 0;
    pbVar30[0x68] = 0;
    pbVar30[0x69] = 0;
    pbVar30[0x6a] = 0;
    pbVar30[0x6b] = 0;
    pbVar30[0x6c] = 0;
    pbVar30[0x6d] = 0;
    pbVar30[0x6e] = 0;
    pbVar30[0x6f] = 0;
    pbVar30[0x80] = 0;
    pbVar30[0x81] = 0;
    pbVar30[0x82] = 0;
    pbVar30[0x83] = 0;
    pbVar30[0x84] = 0;
    pbVar30[0x85] = 0;
    pbVar30[0x86] = 0;
    pbVar30[0x87] = 0;
    pbVar30[0x78] = 0;
    pbVar30[0x79] = 0;
    pbVar30[0x7a] = 0;
    pbVar30[0x7b] = 0;
    pbVar30[0x7c] = 0;
    pbVar30[0x7d] = 0;
    pbVar30[0x7e] = 0;
    pbVar30[0x7f] = 0;
    pbVar30[0x90] = 0;
    pbVar30[0x91] = 0;
    pbVar30[0x92] = 0;
    pbVar30[0x93] = 0;
    pbVar30[0x94] = 0;
    pbVar30[0x95] = 0;
    pbVar30[0x96] = 0;
    pbVar30[0x97] = 0;
    pbVar30[0x88] = 0;
    pbVar30[0x89] = 0;
    pbVar30[0x8a] = 0;
    pbVar30[0x8b] = 0;
    pbVar30[0x8c] = 0;
    pbVar30[0x8d] = 0;
    pbVar30[0x8e] = 0;
    pbVar30[0x8f] = 0;
    pbVar30[0xa0] = 0;
    pbVar30[0xa1] = 0;
    pbVar30[0xa2] = 0;
    pbVar30[0xa3] = 0;
    pbVar30[0xa4] = 0;
    pbVar30[0xa5] = 0;
    pbVar30[0xa6] = 0;
    pbVar30[0xa7] = 0;
    pbVar30[0x98] = 0;
    pbVar30[0x99] = 0;
    pbVar30[0x9a] = 0;
    pbVar30[0x9b] = 0;
    pbVar30[0x9c] = 0;
    pbVar30[0x9d] = 0;
    pbVar30[0x9e] = 0;
    pbVar30[0x9f] = 0;
    pbVar30[0xb0] = 0;
    pbVar30[0xb1] = 0;
    pbVar30[0xb2] = 0;
    pbVar30[0xb3] = 0;
    pbVar30[0xb4] = 0;
    pbVar30[0xb5] = 0;
    pbVar30[0xb6] = 0;
    pbVar30[0xb7] = 0;
    pbVar30[0xa8] = 0;
    pbVar30[0xa9] = 0;
    pbVar30[0xaa] = 0;
    pbVar30[0xab] = 0;
    pbVar30[0xac] = 0;
    pbVar30[0xad] = 0;
    pbVar30[0xae] = 0;
    pbVar30[0xaf] = 0;
    pbVar30[0xc0] = 0;
    pbVar30[0xc1] = 0;
    pbVar30[0xc2] = 0;
    pbVar30[0xc3] = 0;
    pbVar30[0xc4] = 0;
    pbVar30[0xc5] = 0;
    pbVar30[0xc6] = 0;
    pbVar30[199] = 0;
    pbVar30[0xb8] = 0;
    pbVar30[0xb9] = 0;
    pbVar30[0xba] = 0;
    pbVar30[0xbb] = 0;
    pbVar30[0xbc] = 0;
    pbVar30[0xbd] = 0;
    pbVar30[0xbe] = 0;
    pbVar30[0xbf] = 0;
    pbVar30[0xd0] = 0;
    pbVar30[0xd1] = 0;
    pbVar30[0xd2] = 0;
    pbVar30[0xd3] = 0;
    pbVar30[0xd4] = 0;
    pbVar30[0xd5] = 0;
    pbVar30[0xd6] = 0;
    pbVar30[0xd7] = 0;
    pbVar30[200] = 0;
    pbVar30[0xc9] = 0;
    pbVar30[0xca] = 0;
    pbVar30[0xcb] = 0;
    pbVar30[0xcc] = 0;
    pbVar30[0xcd] = 0;
    pbVar30[0xce] = 0;
    pbVar30[0xcf] = 0;
    pbVar30[0xe0] = 0;
    pbVar30[0xe1] = 0;
    pbVar30[0xe2] = 0;
    pbVar30[0xe3] = 0;
    pbVar30[0xe4] = 0;
    pbVar30[0xe5] = 0;
    pbVar30[0xe6] = 0;
    pbVar30[0xe7] = 0;
    pbVar30[0xd8] = 0;
    pbVar30[0xd9] = 0;
    pbVar30[0xda] = 0;
    pbVar30[0xdb] = 0;
    pbVar30[0xdc] = 0;
    pbVar30[0xdd] = 0;
    pbVar30[0xde] = 0;
    pbVar30[0xdf] = 0;
    pbVar30[0xf0] = 0;
    pbVar30[0xf1] = 0;
    pbVar30[0xf2] = 0;
    pbVar30[0xf3] = 0;
    pbVar30[0xf4] = 0;
    pbVar30[0xf5] = 0;
    pbVar30[0xf6] = 0;
    pbVar30[0xf7] = 0;
    pbVar30[0xe8] = 0;
    pbVar30[0xe9] = 0;
    pbVar30[0xea] = 0;
    pbVar30[0xeb] = 0;
    pbVar30[0xec] = 0;
    pbVar30[0xed] = 0;
    pbVar30[0xee] = 0;
    pbVar30[0xef] = 0;
    pbVar30[0x100] = 0;
    pbVar30[0x101] = 0;
    pbVar30[0x102] = 0;
    pbVar30[0x103] = 0;
    pbVar30[0x104] = 0;
    pbVar30[0x105] = 0;
    pbVar30[0x106] = 0;
    pbVar30[0x107] = 0;
    pbVar30[0xf8] = 0;
    pbVar30[0xf9] = 0;
    pbVar30[0xfa] = 0;
    pbVar30[0xfb] = 0;
    pbVar30[0xfc] = 0;
    pbVar30[0xfd] = 0;
    pbVar30[0xfe] = 0;
    pbVar30[0xff] = 0;
    pbVar30[0x30] = 0;
    pbVar30[0x31] = 0;
    pbVar30[0x32] = 0;
    pbVar30[0x33] = 0;
    pbVar30[0x34] = 0;
    pbVar30[0x35] = 0;
    pbVar30[0x36] = 0;
    pbVar30[0x37] = 0;
    pbVar30[0x28] = 0;
    pbVar30[0x29] = 0;
    pbVar30[0x2a] = 0;
    pbVar30[0x2b] = 0;
    pbVar30[0x2c] = 0;
    pbVar30[0x2d] = 0;
    pbVar30[0x2e] = 0;
    pbVar30[0x2f] = 0;
    pbVar30[0x130] = 0;
    pbVar30[0x131] = 0;
    pbVar30[0x132] = 0;
    pbVar30[0x133] = 0;
    pbVar30[0x134] = 0;
    pbVar30[0x135] = 0;
    pbVar30[0x136] = 0;
    pbVar30[0x137] = 0;
    pbVar30[0x128] = 0;
    pbVar30[0x129] = 0;
    pbVar30[0x12a] = 0;
    pbVar30[299] = 0;
    pbVar30[300] = 0;
    pbVar30[0x12d] = 0;
    pbVar30[0x12e] = 0;
    pbVar30[0x12f] = 0;
    pbVar30[0x140] = 0;
    pbVar30[0x141] = 0;
    pbVar30[0x142] = 0;
    pbVar30[0x143] = 0;
    pbVar30[0x144] = 0;
    pbVar30[0x145] = 0;
    pbVar30[0x146] = 0;
    pbVar30[0x147] = 0;
    pbVar30[0x138] = 0;
    pbVar30[0x139] = 0;
    pbVar30[0x13a] = 0;
    pbVar30[0x13b] = 0;
    pbVar30[0x13c] = 0;
    pbVar30[0x13d] = 0;
    pbVar30[0x13e] = 0;
    pbVar30[0x13f] = 0;
    pbVar30[0x150] = 0;
    pbVar30[0x151] = 0;
    pbVar30[0x152] = 0;
    pbVar30[0x153] = 0;
    pbVar30[0x154] = 0;
    pbVar30[0x155] = 0;
    pbVar30[0x156] = 0;
    pbVar30[0x157] = 0;
    pbVar30[0x148] = 0;
    pbVar30[0x149] = 0;
    pbVar30[0x14a] = 0;
    pbVar30[0x14b] = 0;
    pbVar30[0x14c] = 0;
    pbVar30[0x14d] = 0;
    pbVar30[0x14e] = 0;
    pbVar30[0x14f] = 0;
    *(byte **)pbVar34 = pbVar30;
    pbVar29 = pbVar30;
    if (**(long **)(lVar12 + 0x2610) != 0) {
      *(long *)(lVar12 + 0x2610) = **(long **)(lVar12 + 0x2610);
      pbVar29 = *(byte **)pbVar34;
    }
    func_0x0040a8c0(*(undefined8 *)(lVar12 + 0x2618),pbVar29);
    *(long *)(lVar12 + 0x2620) = *(long *)(lVar12 + 0x2620) + 1;
LAB_0044dbc8:
    uVar23 = (ulong)*(uint *)(pbVar30 + 0x150);
  }
LAB_0044d7e0:
  uVar32 = (ulong)(int)uVar23;
  uVar7 = *(uint *)(plVar15[1] + (long)(int)uVar23 * 4);
  if (((uVar7 & 1) == 0) || ((char)plVar15[0x10] != '\0')) {
    pbVar29 = pbVar28;
    if (((uVar7 >> 1 & 1) == 0) || (*(char *)((long)plVar15 + 0x81) != '\0')) {
LAB_0044dd5c:
      pbVar29 = pbVar19;
      if ((*(uint *)(plVar15[1] + uVar32 * 4) >> 2 & 1) != 0) {
        uVar23 = uVar32 >> 3 & 0x1ffffffffffffff8;
        *(ulong *)(plVar15[0x11] + uVar23) =
             *(ulong *)(plVar15[0x11] + uVar23) | 1L << (uVar32 & 0x3f);
        pbVar29 = pbVar28;
      }
    }
    else {
      pbVar30 = (byte *)(uVar32 * 0x10);
      if (*(long *)(pbVar30 + plVar15[8]) != 0) {
        *(undefined4 *)(plVar15[0x15] + uVar32 * 4) = 100;
        if (*(long **)(pbVar30 + plVar15[0xb]) != (long *)0x0) {
          uVar23 = (**(code **)(**(long **)(pbVar30 + plVar15[0xb]) + 0x70))();
          lVar12 = plVar15[0xb];
          if ((uVar23 & 1) != 0) {
            (**(code **)(**(long **)(pbVar30 + lVar12) + 0x90))();
            lVar12 = plVar15[0xb];
          }
LAB_0044dcf0:
          if ((*(uint *)(plVar15[1] + uVar32 * 4) >> 2 & 1) != 0) {
            (**(code **)(**(long **)(pbVar30 + lVar12) + 0xb8))(*(long **)(pbVar30 + lVar12),1);
            lVar12 = plVar15[0xb];
          }
          (**(code **)(**(long **)(pbVar30 + lVar12) + 0xe8))
                    ((float)(*(int *)(plVar15[0x15] + uVar32 * 4) * *(int *)((long)plVar15 + 0xc4))
                     / 10000.0);
          (**(code **)(**(long **)(pbVar30 + plVar15[0xb]) + 0x90))();
          goto LAB_0044dd5c;
        }
        uVar23 = func_0x0044d358(plVar15,*(undefined4 *)(plVar15[4] + uVar32 * 4));
        if ((uVar23 & 1) != 0) {
          func_0x00bc3570(0xc0b818);
          func_0x00521e78((undefined1 *)((long)ppuVar2 + -0x80),plVar15[8] + uVar32 * 0x10,
                          *(undefined4 *)(plVar15[4] + uVar32 * 4));
          func_0x0044e2b0(pbVar30 + plVar15[0xb],(undefined1 *)((long)ppuVar2 + -0x80));
          func_0x0044e30c((undefined1 *)((long)ppuVar2 + -0x80));
          func_0x00bc3580(0xc0b818);
          lVar12 = plVar15[0xb];
          if (*(long *)(pbVar30 + lVar12) != 0) goto LAB_0044dcf0;
        }
      }
    }
LAB_0044dd88:
    pbVar19 = pbVar29;
    if (*(long *)(lVar16 + 0x28) == *(long *)((long)ppuVar2 + -0x68)) {
      return;
    }
    uVar36 = 0x44def0;
    auVar40 = func_0x00bc3380();
    puVar21 = extraout_x8;
  }
  else {
    *(undefined8 *)((long)ppuVar2 + -0x80) = 0;
    *(undefined8 *)((long)ppuVar2 + -0x78) = 0;
    *(undefined8 *)((long)ppuVar2 + -0x70) = 0;
    func_0x005220d0((undefined1 *)((long)ppuVar2 + -0xb8));
    *(undefined1 *)((long)ppuVar2 + -0xe8) = 0x14;
    *(undefined1 *)((long)ppuVar2 + -0x100) = 6;
    *(undefined2 *)((long)ppuVar2 + -0xdf) = 0x7325;
    *(undefined8 *)((long)ppuVar2 + -0xe7) = 0x2e64333025646e73;
    *(undefined1 *)((long)ppuVar2 + -0xdd) = 0;
    *(undefined4 *)((long)ppuVar2 + -0xff) = 0x67676f;
    puVar21 = (undefined1 *)((long)ppuVar2 + -0xd0);
    auVar40._8_8_ = uVar23;
    auVar40._0_8_ = (undefined1 *)((long)ppuVar2 + -0xe8);
    pbVar18 = (byte *)((long)ppuVar2 + -0x100);
    uVar36 = 0x44d854;
  }
  *(undefined1 **)((long)ppuVar2 + -0x150) = (undefined1 *)((long)ppuVar2 + -0x60);
  *(undefined8 *)((long)ppuVar2 + -0x148) = uVar36;
  *(ulong *)((long)ppuVar2 + -0x140) = uVar32;
  *(byte **)((long)ppuVar2 + -0x138) = pbVar19;
  *(byte **)((long)ppuVar2 + -0x130) = pbVar27;
  *(long **)((long)ppuVar2 + -0x128) = plVar15;
  lVar16 = tpidr_el0;
  uVar23 = auVar40._8_8_ & 0xffffffff;
  *(undefined8 *)((long)ppuVar2 + -0x158) = *(undefined8 *)(lVar16 + 0x28);
  if ((*pbVar18 & 1) == 0) {
    uVar37 = *(undefined8 *)pbVar18;
    uVar36 = *(undefined8 *)(pbVar18 + 0x10);
    *(undefined8 *)((long)ppuVar2 + -0x188) = *(undefined8 *)(pbVar18 + 8);
    *(undefined8 *)((long)ppuVar2 + -400) = uVar37;
    *(undefined8 *)((long)ppuVar2 + -0x180) = uVar36;
    if ((*(byte *)((long)ppuVar2 + -400) & 1) != 0) goto LAB_0044df3c;
LAB_0044df60:
    *(undefined8 *)((long)ppuVar2 + -0x168) = *(undefined8 *)((long)ppuVar2 + -0x188);
    *(undefined8 *)((long)ppuVar2 + -0x170) = *(undefined8 *)((long)ppuVar2 + -400);
    *(undefined8 *)((long)ppuVar2 + -0x160) = *(undefined8 *)((long)ppuVar2 + -0x180);
  }
  else {
    func_0x0040a850((undefined1 *)((long)ppuVar2 + -400),*(undefined8 *)(pbVar18 + 0x10),
                    *(undefined8 *)(pbVar18 + 8));
    if ((*(byte *)((long)ppuVar2 + -400) & 1) == 0) goto LAB_0044df60;
LAB_0044df3c:
    func_0x0040a850((undefined1 *)((long)ppuVar2 + -0x170),*(undefined8 *)((long)ppuVar2 + -0x180),
                    *(undefined8 *)((long)ppuVar2 + -0x188));
  }
  func_0x0044ede8(puVar21,auVar40._0_8_,0,uVar23,(undefined1 *)((long)ppuVar2 + -0x170));
  if ((*(byte *)((long)ppuVar2 + -0x170) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)ppuVar2 + -0x160));
  }
  if ((*(byte *)((long)ppuVar2 + -400) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)ppuVar2 + -0x180));
  }
  if (*(long *)(lVar16 + 0x28) == *(long *)((long)ppuVar2 + -0x158)) {
    return;
  }
  auVar39 = func_0x00bc3380();
  uVar32 = auVar39._8_8_;
  puVar14 = auVar39._0_8_;
  *(undefined1 **)((long)ppuVar2 + -0x1d0) = (undefined1 *)((long)ppuVar2 + -0x150);
  *(undefined8 *)((long)ppuVar2 + -0x1c8) = 0x44e014;
  *(byte **)((long)ppuVar2 + -0x1c0) = pbVar34;
  *(byte **)((long)ppuVar2 + -0x1b8) = pbVar30;
  *(long *)((long)ppuVar2 + -0x1b0) = lVar16;
  *(undefined1 **)((long)ppuVar2 + -0x1a8) = puVar21;
  *(long *)((long)ppuVar2 + -0x1a0) = auVar40._0_8_;
  *(ulong *)((long)ppuVar2 + -0x198) = uVar23;
  if (((auVar39._8_4_ ^ 0xffffffff) & 0xfffffffd) == 0) {
LAB_0044e048:
    plVar20 = *(long **)(puVar14 + 0x1c);
    if (plVar20 != (long *)0x0) {
      for (puVar26 = *(undefined8 **)(puVar14 + 0x16); puVar26 != *(undefined8 **)(puVar14 + 0x18);
          puVar26 = puVar26 + 2) {
        if ((long *)*puVar26 == plVar20) {
          uVar32 = uVar32 & 0xffffffff;
          (**(code **)(*plVar20 + 0xf8))();
          plVar20 = (long *)puVar26[1];
          *puVar26 = 0;
          puVar26[1] = 0;
          if ((plVar20 != (long *)0x0) &&
             (lVar16 = func_0x00bbf1b0(0xffffffffffffffff,plVar20 + 1), lVar16 == 0)) {
            (**(code **)(*plVar20 + 0x10))(plVar20);
            func_0x00bc3320(plVar20);
          }
          plVar20 = *(long **)(puVar14 + 0x1e);
          puVar14[0x1c] = 0;
          puVar14[0x1d] = 0;
          puVar14[0x1e] = 0;
          puVar14[0x1f] = 0;
          if ((plVar20 != (long *)0x0) &&
             (lVar16 = func_0x00bbf1b0(0xffffffffffffffff,plVar20 + 1), lVar16 == 0)) {
            (**(code **)(*plVar20 + 0x10))(plVar20);
            func_0x00bc3320(plVar20);
          }
          break;
        }
      }
    }
    uVar7 = *puVar14;
    if (0 < (int)uVar7) {
      lVar16 = *(long *)(puVar14 + 2);
      lVar12 = *(long *)(puVar14 + 0x22);
      uVar23 = 0;
      do {
        if ((*(uint *)(lVar16 + uVar23 * 4) & 1) != 0) {
          uVar22 = uVar23 >> 3 & 0x1ffffffffffffff8;
          *(ulong *)(lVar12 + uVar22) =
               *(ulong *)(lVar12 + uVar22) & (1L << (uVar23 & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar23 = uVar23 + 1;
      } while (uVar7 != uVar23);
    }
  }
  else if (-1 < (int)auVar39._8_4_) {
    uVar7 = *(uint *)(*(long *)(puVar14 + 2) + (uVar32 & 0xffffffff) * 4);
    if ((uVar7 & 1) == 0) goto LAB_0044e194;
    goto LAB_0044e048;
  }
  if ((int)uVar32 + 3U < 2) {
    uVar7 = *puVar14;
    if ((int)uVar7 < 1) {
      return;
    }
    lVar16 = 0;
    lVar12 = 0;
    uVar23 = 0;
    do {
      if (((*(byte *)(*(long *)(puVar14 + 2) + lVar12) >> 1 & 1) != 0) &&
         (*(long **)(*(long *)(puVar14 + 0x16) + lVar16) != (long *)0x0)) {
        (**(code **)(**(long **)(*(long *)(puVar14 + 0x16) + lVar16) + 0xf8))();
        puVar26 = (undefined8 *)(*(long *)(puVar14 + 0x16) + lVar16);
        plVar20 = (long *)puVar26[1];
        *puVar26 = 0;
        puVar26[1] = 0;
        if ((plVar20 != (long *)0x0) &&
           (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar20 + 1), lVar13 == 0)) {
          (**(code **)(*plVar20 + 0x10))(plVar20);
          func_0x00bc3320(plVar20);
        }
        uVar32 = uVar23 >> 3 & 0x1ffffffffffffff8;
        uVar7 = *puVar14;
        *(ulong *)(*(long *)(puVar14 + 0x22) + uVar32) =
             *(ulong *)(*(long *)(puVar14 + 0x22) + uVar32) &
             (1L << (uVar23 & 0x3f) ^ 0xffffffffffffffffU);
      }
      uVar23 = uVar23 + 1;
      lVar16 = lVar16 + 0x10;
      lVar12 = lVar12 + 4;
    } while ((long)uVar23 < (long)(int)uVar7);
    return;
  }
  if ((int)uVar32 < 0) {
    return;
  }
  uVar7 = *(uint *)(*(long *)(puVar14 + 2) + (uVar32 & 0xffffffff) * 4);
LAB_0044e194:
  uVar23 = uVar32 & 0xffffffff;
  if (((uVar7 >> 1 & 1) != 0) &&
     (plVar20 = *(long **)(*(long *)(puVar14 + 0x16) + uVar23 * 0x10), plVar20 != (long *)0x0)) {
    (**(code **)(*plVar20 + 0xf8))();
    puVar26 = (undefined8 *)(*(long *)(puVar14 + 0x16) + uVar23 * 0x10);
    plVar20 = (long *)puVar26[1];
    *puVar26 = 0;
    puVar26[1] = 0;
    if ((plVar20 != (long *)0x0) &&
       (lVar16 = func_0x00bbf1b0(0xffffffffffffffff,plVar20 + 1), lVar16 == 0)) {
      (**(code **)(*plVar20 + 0x10))(plVar20);
      func_0x00bc3320(plVar20);
    }
    uVar23 = uVar23 >> 3 & 0x1ffffff8;
    *(ulong *)(*(long *)(puVar14 + 0x22) + uVar23) =
         *(ulong *)(*(long *)(puVar14 + 0x22) + uVar23) &
         (1L << (uVar32 & 0x3f) ^ 0xffffffffffffffffU);
  }
  return;
}


