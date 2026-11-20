// ELF VMA: 0x4bdba0
// Ghidra Addr: 0x005bdba0 (ImageBase=0x100000)
// Size: 604 bytes


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004bdba0(long param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  undefined4 uVar7;
  char *pcVar8;
  long lVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  double dVar17;
  undefined1 auVar18 [16];
  double dVar19;
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  
  piVar1 = (int *)(&UNK_00327db4 + param_1);
  *(undefined4 *)(&UNK_00326690 + param_1) = 0;
  puVar2 = (undefined8 *)(&UNK_00326acc + param_1);
  *piVar1 = 0;
  uVar5 = func_0x005af784(5);
  if ((uVar5 & 1) == 0) {
    pcVar8 = &UNK_003268f8 + param_1;
    lVar9 = 0x30;
    (&UNK_00326fcc)[param_1] = 0;
    (&UNK_00326ac0)[param_1] = 0;
    do {
      if (*pcVar8 != '\0') {
        *pcVar8 = '\0';
      }
      if (pcVar8[1] != '\0') {
        pcVar8[1] = '\0';
      }
      if (pcVar8[2] != '\0') {
        pcVar8[2] = '\0';
      }
      if (pcVar8[3] != '\0') {
        pcVar8[3] = '\0';
      }
      if (pcVar8[4] != '\0') {
        pcVar8[4] = '\0';
      }
      if (pcVar8[5] != '\0') {
        pcVar8[5] = '\0';
      }
      if (pcVar8[6] != '\0') {
        pcVar8[6] = '\0';
      }
      if (pcVar8[7] != '\0') {
        pcVar8[7] = '\0';
      }
      if (pcVar8[8] != '\0') {
        pcVar8[8] = '\0';
      }
      if (pcVar8[9] != '\0') {
        pcVar8[9] = '\0';
      }
      if (pcVar8[10] != '\0') {
        pcVar8[10] = '\0';
      }
      if (pcVar8[0xb] != '\0') {
        pcVar8[0xb] = '\0';
      }
      if (pcVar8[0xc] != '\0') {
        pcVar8[0xc] = '\0';
      }
      if (pcVar8[0xd] != '\0') {
        pcVar8[0xd] = '\0';
      }
      if (pcVar8[0xe] != '\0') {
        pcVar8[0xe] = '\0';
      }
      if (pcVar8[0xf] != '\0') {
        pcVar8[0xf] = '\0';
      }
      lVar9 = lVar9 + -0x10;
      pcVar8 = pcVar8 + 0x10;
    } while (lVar9 != 0);
    if ((&UNK_00326928)[param_1] != '\0') {
      (&UNK_00326928)[param_1] = 0;
    }
    if ((&UNK_00326929)[param_1] == '\0') {
      return;
    }
    (&UNK_00326929)[param_1] = 0;
    return;
  }
  iVar3 = func_0x005ab154();
  if (iVar3 == 0) {
    uVar5 = 1;
    piVar12 = (int *)(param_1 + 0x90434);
    do {
      if ((((piVar12[-3] != 0) &&
           (uVar6 = func_0x00a58df4(1,uVar5 & 0xffffffff,0xffffffff), (uVar6 & 1) != 0)) &&
          (uVar6 = func_0x005aad10(), uVar5 != (uVar6 & 0xffffffff))) && (*piVar1 <= *piVar12)) {
        *piVar1 = *piVar12;
        *(int *)(&UNK_00326690 + param_1) = (int)uVar5;
      }
      uVar5 = uVar5 + 1;
      piVar12 = piVar12 + 0xfa;
    } while (uVar5 != 0x33);
    iVar3 = func_0x00a5780c(0);
    *(int *)(&UNK_00327db8 + param_1) = (iVar3 - *(int *)(param_1 + 0x83698)) / 10 + 0xcb;
    iVar3 = func_0x00a57820(0);
    fVar15 = (float)func_0x0043ec24();
    *(int *)(&UNK_00327dbc + param_1) = (int)((float)(iVar3 / 10 + -0x171) + fVar15 * 10.0);
  }
  fVar15 = 0.0;
  if (0 < (int)*(uint *)(&UNK_00326690 + param_1)) {
    lVar9 = param_1 + (ulong)*(uint *)(&UNK_00326690 + param_1) * 1000;
    iVar3 = (int)((ulong)((long)*(int *)(lVar9 + 0x90050) * -0x66666667) >> 0x20);
    iVar4 = (int)((ulong)((long)(*(int *)(lVar9 + 0x9004c) - *(int *)(param_1 + 0x83698)) *
                         -0x66666667) >> 0x20);
    fVar16 = (float)func_0x0043ec94((float)(*(int *)(&UNK_00327dbc + param_1) +
                                            ((iVar3 >> 2) - (iVar3 >> 0x1f)) +
                                            *(int *)(lVar9 + 0x90054) * -4 + 0x3a),
                                    (float)(((iVar4 >> 2) - (iVar4 >> 0x1f)) +
                                           *(int *)(&UNK_00327db8 + param_1)));
    if (0.0 < 360.0 - fVar16) {
      fVar15 = -(360.0 - fVar16);
    }
  }
  fVar16 = *(float *)(&UNK_00326698 + param_1);
  *(float *)(&UNK_0032669c + param_1) = fVar15;
  *piVar1 = 0;
  if (fVar15 <= fVar16) {
    *(float *)(&UNK_00326698 + param_1) = fVar16 + -1.0;
    if (fVar16 + -1.0 <= fVar15) goto LAB_005bdf40;
  }
  else if ((fVar16 <= fVar15) &&
          (*(float *)(&UNK_00326698 + param_1) = fVar16 + 1.0, fVar15 <= fVar16 + 1.0)) {
LAB_005bdf40:
    *(float *)(&UNK_00326698 + param_1) = fVar15;
    *piVar1 = 1;
  }
  if (*(int *)(&UNK_00326690 + param_1) == 0) {
    *piVar1 = 0;
  }
  iVar3 = func_0x00a5780c(0);
  *(int *)(&UNK_00327db8 + param_1) = iVar3 + 0x6ea;
  iVar4 = func_0x00a57820(0);
  fVar15 = (float)func_0x0043ec24();
  iVar3 = 300;
  if (*(int *)(&UNK_00326abc + param_1) < 299) {
    iVar3 = *(int *)(&UNK_00326abc + param_1) + 1;
  }
  *(int *)(&UNK_00326abc + param_1) = iVar3;
  *(int *)(&UNK_00327dbc + param_1) = (int)((float)(iVar4 + -0xf76) + fVar15 * 10.0 * 10.0);
  if ((*piVar1 == 1) && (299 < iVar3)) {
    if ((&UNK_00326ac0)[param_1] == '\0') {
      *(undefined4 *)(&UNK_00326abc + param_1) = 0;
      (&UNK_00326ac0)[param_1] = 1;
      *(undefined4 *)(&UNK_00326ac4 + param_1) = 0;
    }
  }
  else if ((&UNK_00326ac0)[param_1] == '\0') goto LAB_005be2c4;
  iVar4 = *(int *)(&UNK_00326ac4 + param_1);
  iVar3 = iVar4 + 1;
  *(int *)(&UNK_00326ac4 + param_1) = iVar3;
  if (iVar4 != 3) {
    if (iVar4 == 2) {
      *(undefined4 *)(&UNK_00326ac8 + param_1) = 0xfffffff6;
      goto LAB_005be2c4;
    }
    if (iVar4 != 1) {
      *(undefined4 *)(&UNK_00326ac8 + param_1) = 0;
      if (iVar3 == 0xb) {
        fVar15 = *(float *)(&UNK_0032669c + param_1);
        *(uint *)(&UNK_00327dc0 + param_1) = (uint)(*(float *)(&UNK_00326698 + param_1) == fVar15);
        if ((((*(float *)(&UNK_00326698 + param_1) != fVar15) ||
             (iVar3 = *(int *)(&UNK_00326690 + param_1),
             *(int *)(param_1 + (long)iVar3 * 1000 + 0x90040) == 0)) || (iVar3 == 0)) ||
           (2 < *(int *)(param_1 + (long)iVar3 * 1000 + 0x90044))) {
          *piVar1 = 0;
          (&UNK_00326ac0)[param_1] = 0;
          *(undefined4 *)(&UNK_00326ac4 + param_1) = 0;
          *(undefined4 *)(&UNK_00326abc + param_1) = 300;
          goto LAB_005be2c4;
        }
        lVar9 = 0;
        *piVar1 = 1;
        puVar10 = (undefined4 *)(&UNK_003266a0 + param_1);
        do {
          if ((&UNK_003268f8)[lVar9 + param_1] == '\0') {
            puVar10[0xa3] = 0x5dc;
            uVar7 = *(undefined4 *)(&UNK_00327db8 + param_1);
            (&UNK_003268f8)[param_1 + lVar9] = 1;
            *puVar10 = uVar7;
            uVar7 = *(undefined4 *)(&UNK_00327dbc + param_1);
            puVar10[0xd5] = (int)fVar15;
            puVar10[100] = iVar3;
            puVar10[0x32] = uVar7;
            *(undefined8 *)(&UNK_00326ad4 + param_1) = 0x1e00000000;
            *puVar2 = 0;
            *(undefined4 *)(&UNK_00326abc + param_1) = 0;
            *(undefined8 *)(&UNK_00326af4 + param_1) = 0;
            *(undefined8 *)(&UNK_00326aec + param_1) = 0xffffffe2;
            *(undefined8 *)(&UNK_00326b04 + param_1) = 0x1e;
            *(undefined8 *)(&UNK_00326afc + param_1) = 0;
            auVar18 = _UNK_002a9900;
            iVar3 = *(int *)(&UNK_00326ac4 + param_1);
            *(undefined8 *)(&UNK_00326adc + param_1) = 0;
            *(undefined8 *)(&UNK_00326ae4 + param_1) = 0;
            *(long *)(&UNK_00326b14 + param_1) = auVar18._8_8_;
            *(long *)(&UNK_00326b0c + param_1) = auVar18._0_8_;
            (&UNK_00326fcc)[param_1] = 1;
            goto LAB_005be138;
          }
          lVar9 = lVar9 + 1;
          puVar10 = puVar10 + 1;
        } while (lVar9 != 0x32);
LAB_005be294:
        uVar7 = 0x14;
      }
      else {
LAB_005be138:
        if ((0xb < iVar3) && ((&UNK_00326fcc)[param_1] != '\0')) {
          auVar18 = NEON_fmov(0x3fe0000000000000,8);
          iVar4 = *(int *)(&UNK_00326ad4 + param_1);
          iVar13 = (int)*(undefined8 *)(&UNK_00326ad8 + param_1);
          auVar20._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326ad8 + param_1) >> 0x20);
          auVar20._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326ad4 + param_1) = iVar4 + 1;
          auVar20 = NEON_scvtf(auVar20,8);
          *puVar2 = CONCAT44((int)((ulong)*puVar2 >> 0x20) + iVar14,(int)*puVar2 + iVar13);
          dVar17 = auVar18._0_8_;
          dVar19 = auVar18._8_8_;
          *(ulong *)(&UNK_00326ad8 + param_1) =
               CONCAT44((int)(long)(auVar20._8_8_ * dVar19),(int)(long)(auVar20._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;
          }
          iVar4 = *(int *)(&UNK_00326ae8 + param_1);
          iVar13 = (int)*(undefined8 *)(&UNK_00326aec + param_1);
          auVar18._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326aec + param_1) >> 0x20);
          auVar18._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326ae8 + param_1) = iVar4 + 1;
          auVar18 = NEON_scvtf(auVar18,8);
          *(ulong *)(&UNK_00326ae0 + param_1) =
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326ae0 + param_1) >> 0x20) + iVar14,
                        (int)*(undefined8 *)(&UNK_00326ae0 + param_1) + iVar13);
          *(ulong *)(&UNK_00326aec + param_1) =
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;
          }
          iVar4 = *(int *)(&UNK_00326afc + param_1);
          iVar13 = (int)*(undefined8 *)(&UNK_00326b00 + param_1);
          auVar21._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326b00 + param_1) >> 0x20);
          auVar21._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326afc + param_1) = iVar4 + 1;
          auVar18 = NEON_scvtf(auVar21,8);
          *(ulong *)(&UNK_00326af4 + param_1) =
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326af4 + param_1) >> 0x20) + iVar14,
                        (int)*(undefined8 *)(&UNK_00326af4 + param_1) + iVar13);
          *(ulong *)(&UNK_00326b00 + param_1) =
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;
          }
          iVar4 = *(int *)(&UNK_00326b10 + param_1);
          iVar13 = (int)*(undefined8 *)(&UNK_00326b14 + param_1);
          auVar22._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326b14 + param_1) >> 0x20);
          auVar22._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326b10 + param_1) = iVar4 + 1;
          auVar18 = NEON_scvtf(auVar22,8);
          *(ulong *)(&UNK_00326b08 + param_1) =
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326b08 + param_1) >> 0x20) + iVar14,
                        (int)*(undefined8 *)(&UNK_00326b08 + param_1) + iVar13);
          *(ulong *)(&UNK_00326b14 + param_1) =
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;
          }
        }
        if (iVar3 < 0xe) {
          if (iVar3 == 0xb) goto LAB_005be294;
          if (iVar3 == 0xc) {
            uVar7 = 0xfffffff6;
          }
          else {
            if (iVar3 != 0xd) goto LAB_005be2a4;
            uVar7 = 5;
          }
        }
        else if (iVar3 == 0xe) {
          uVar7 = 0xfffffffe;
        }
        else {
          if (iVar3 != 0xf) {
            if (iVar3 == 0x10) {
              *(undefined4 *)(&UNK_00326670 + param_1) = 0;
              goto LAB_005be2c4;
            }
LAB_005be2a4:
            if (0x1b < iVar3) {
              (&UNK_00326ac0)[param_1] = 0;
            }
            goto LAB_005be2c4;
          }
          uVar7 = 1;
        }
      }
      *(undefined4 *)(&UNK_00326670 + param_1) = uVar7;
      goto LAB_005be2c4;
    }
  }
  *(undefined4 *)(&UNK_00326ac8 + param_1) = 0xfffffffa;
LAB_005be2c4:
  lVar9 = 0;
  puVar11 = &UNK_003266a0;
  do {
    if ((&UNK_003268f8)[lVar9 + param_1] != '\0') {
      piVar1 = (int *)(puVar11 + param_1);
      iVar3 = piVar1[0xa3];
      fVar15 = (float)func_0x0043ec5c((float)piVar1[0xd5],piVar1[0xd5]);
      iVar4 = piVar1[0xa3];
      *piVar1 = (int)((float)*piVar1 - fVar15 * (float)iVar3);
      fVar15 = (float)func_0x0043ec24();
      iVar4 = (int)((float)piVar1[0x32] - fVar15 * (float)iVar4);
      piVar1[0x32] = iVar4;
      iVar3 = func_0x0043dd3c(param_1);
      if (iVar3 <= iVar4 / 10) {
        (&UNK_003268f8)[lVar9 + param_1] = 0;
      }
      if (*(int *)(puVar11 + param_1) < -999) {
        (&UNK_003268f8)[lVar9 + param_1] = 0;
      }
    }
    lVar9 = lVar9 + 1;
    puVar11 = puVar11 + 4;
  } while (lVar9 != 0x32);
                    /* WARNING: Read-only address (ram,0x002a9900) is written */
  return;
}


