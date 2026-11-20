// ELF VMA: 0x004bdba0 | Ghidra Addr: 0x005bdba0 | BodySize: 2024

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
  
  piVar1 = (int *)(&UNK_00327db4 + param_1);  /* field_off=0x327db4 */
  *(undefined4 *)(&UNK_00326690 + param_1) = 0;  /* field_off=0x326690 */
  puVar2 = (undefined8 *)(&UNK_00326acc + param_1);  /* field_off=0x326acc */
  *piVar1 = 0;
  uVar5 = func_0x005af784(5);
  if ((uVar5 & 1) == 0) {
    pcVar8 = &UNK_003268f8 + param_1;  /* field_off=0x3268f8 */
    lVar9 = 0x30;
    (&UNK_00326fcc)[param_1] = 0;  /* field_off=0x326fcc */
    (&UNK_00326ac0)[param_1] = 0;  /* field_off=0x326ac0 */
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
    if ((&UNK_00326928)[param_1] != '\0') {  /* field_off=0x326928 */
      (&UNK_00326928)[param_1] = 0;  /* field_off=0x326928 */
    }
    if ((&UNK_00326929)[param_1] == '\0') {  /* field_off=0x326929 */
      return;
    }
    (&UNK_00326929)[param_1] = 0;  /* field_off=0x326929 */
    return;
  }
  iVar3 = func_0x005ab154();
  if (iVar3 == 0) {
    uVar5 = 1;
    piVar12 = (int *)(param_1 + 0x90434);
    do {
      if ((((piVar12[-3] != 0) &&
           (uVar6 = func_0x00a58df4(1,uVar5 & 0xffffffff,0xffffffff), (uVar6 & 1) != 0)) &&  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          (uVar6 = func_0x005aad10(), uVar5 != (uVar6 & 0xffffffff))) && (*piVar1 <= *piVar12)) {
        *piVar1 = *piVar12;
        *(int *)(&UNK_00326690 + param_1) = (int)uVar5;  /* field_off=0x326690 */
      }
      uVar5 = uVar5 + 1;
      piVar12 = piVar12 + 0xfa;
    } while (uVar5 != 0x33);
    iVar3 = func_0x00a5780c(0);  /* 0x95780c:[team*51000|off=0x83920|ldr w0, [x8, x9]] */
    *(int *)(&UNK_00327db8 + param_1) = (iVar3 - *(int *)(param_1 + 0x83698)) / 10 + 0xcb;  /* field_off=0x327db8 */
    iVar3 = func_0x00a57820(0);  /* 0x957820:[team*51000|off=0x83920|ldr w0, [x8, x9]] */
    fVar15 = (float)func_0x0043ec24();
    *(int *)(&UNK_00327dbc + param_1) = (int)((float)(iVar3 / 10 + -0x171) + fVar15 * 10.0);  /* field_off=0x327dbc */
  }
  fVar15 = 0.0;
  if (0 < (int)*(uint *)(&UNK_00326690 + param_1)) {  /* field_off=0x326690 */
    lVar9 = param_1 + (ulong)*(uint *)(&UNK_00326690 + param_1) * 1000;  /* field_off=0x326690 */
    iVar3 = (int)((ulong)((long)*(int *)(lVar9 + 0x90050) * -0x66666667) >> 0x20);  /* ascii(0x66666667)='gfff' */
    iVar4 = (int)((ulong)((long)(*(int *)(lVar9 + 0x9004c) - *(int *)(param_1 + 0x83698)) *
                         -0x66666667) >> 0x20);  /* ascii(0x66666667)='gfff' */
    fVar16 = (float)func_0x0043ec94((float)(*(int *)(&UNK_00327dbc + param_1) +  /* field_off=0x327dbc */
                                            ((iVar3 >> 2) - (iVar3 >> 0x1f)) +
                                            *(int *)(lVar9 + 0x90054) * -4 + 0x3a),
                                    (float)(((iVar4 >> 2) - (iVar4 >> 0x1f)) +
                                           *(int *)(&UNK_00327db8 + param_1)));  /* field_off=0x327db8 */
    if (0.0 < 360.0 - fVar16) {
      fVar15 = -(360.0 - fVar16);
    }
  }
  fVar16 = *(float *)(&UNK_00326698 + param_1);  /* field_off=0x326698 */
  *(float *)(&UNK_0032669c + param_1) = fVar15;  /* field_off=0x32669c */
  *piVar1 = 0;
  if (fVar15 <= fVar16) {
    *(float *)(&UNK_00326698 + param_1) = fVar16 + -1.0;  /* field_off=0x326698 */
    if (fVar16 + -1.0 <= fVar15) goto LAB_005bdf40;
  }
  else if ((fVar16 <= fVar15) &&
          (*(float *)(&UNK_00326698 + param_1) = fVar16 + 1.0, fVar15 <= fVar16 + 1.0)) {  /* field_off=0x326698 */
LAB_005bdf40:
    *(float *)(&UNK_00326698 + param_1) = fVar15;  /* field_off=0x326698 */
    *piVar1 = 1;
  }
  if (*(int *)(&UNK_00326690 + param_1) == 0) {  /* field_off=0x326690 */
    *piVar1 = 0;
  }
  iVar3 = func_0x00a5780c(0);  /* 0x95780c:[team*51000|off=0x83920|ldr w0, [x8, x9]] */
  *(int *)(&UNK_00327db8 + param_1) = iVar3 + 0x6ea;  /* field_off=0x327db8 */
  iVar4 = func_0x00a57820(0);  /* 0x957820:[team*51000|off=0x83920|ldr w0, [x8, x9]] */
  fVar15 = (float)func_0x0043ec24();
  iVar3 = 300;
  if (*(int *)(&UNK_00326abc + param_1) < 299) {  /* field_off=0x326abc */
    iVar3 = *(int *)(&UNK_00326abc + param_1) + 1;  /* field_off=0x326abc */
  }
  *(int *)(&UNK_00326abc + param_1) = iVar3;  /* field_off=0x326abc */
  *(int *)(&UNK_00327dbc + param_1) = (int)((float)(iVar4 + -0xf76) + fVar15 * 10.0 * 10.0);  /* field_off=0x327dbc */
  if ((*piVar1 == 1) && (299 < iVar3)) {
    if ((&UNK_00326ac0)[param_1] == '\0') {  /* field_off=0x326ac0 */
      *(undefined4 *)(&UNK_00326abc + param_1) = 0;  /* field_off=0x326abc */
      (&UNK_00326ac0)[param_1] = 1;  /* field_off=0x326ac0 */
      *(undefined4 *)(&UNK_00326ac4 + param_1) = 0;  /* field_off=0x326ac4 */
    }
  }
  else if ((&UNK_00326ac0)[param_1] == '\0') goto LAB_005be2c4;  /* field_off=0x326ac0 */
  iVar4 = *(int *)(&UNK_00326ac4 + param_1);  /* field_off=0x326ac4 */
  iVar3 = iVar4 + 1;
  *(int *)(&UNK_00326ac4 + param_1) = iVar3;  /* field_off=0x326ac4 */
  if (iVar4 != 3) {
    if (iVar4 == 2) {
      *(undefined4 *)(&UNK_00326ac8 + param_1) = 0xfffffff6;  /* field_off=0x326ac8 */
      goto LAB_005be2c4;
    }
    if (iVar4 != 1) {
      *(undefined4 *)(&UNK_00326ac8 + param_1) = 0;  /* field_off=0x326ac8 */
      if (iVar3 == 0xb) {
        fVar15 = *(float *)(&UNK_0032669c + param_1);  /* field_off=0x32669c */
        *(uint *)(&UNK_00327dc0 + param_1) = (uint)(*(float *)(&UNK_00326698 + param_1) == fVar15);  /* field_off=0x327dc0 ; field_off=0x326698 */
        if ((((*(float *)(&UNK_00326698 + param_1) != fVar15) ||  /* field_off=0x326698 */
             (iVar3 = *(int *)(&UNK_00326690 + param_1),  /* field_off=0x326690 */
             *(int *)(param_1 + (long)iVar3 * 1000 + 0x90040) == 0)) || (iVar3 == 0)) ||
           (2 < *(int *)(param_1 + (long)iVar3 * 1000 + 0x90044))) {
          *piVar1 = 0;
          (&UNK_00326ac0)[param_1] = 0;  /* field_off=0x326ac0 */
          *(undefined4 *)(&UNK_00326ac4 + param_1) = 0;  /* field_off=0x326ac4 */
          *(undefined4 *)(&UNK_00326abc + param_1) = 300;  /* field_off=0x326abc */
          goto LAB_005be2c4;
        }
        lVar9 = 0;
        *piVar1 = 1;
        puVar10 = (undefined4 *)(&UNK_003266a0 + param_1);  /* field_off=0x3266a0 */
        do {
          if ((&UNK_003268f8)[lVar9 + param_1] == '\0') {  /* field_off=0x3268f8 */
            puVar10[0xa3] = 0x5dc;
            uVar7 = *(undefined4 *)(&UNK_00327db8 + param_1);  /* field_off=0x327db8 */
            (&UNK_003268f8)[param_1 + lVar9] = 1;  /* field_off=0x3268f8 */
            *puVar10 = uVar7;
            uVar7 = *(undefined4 *)(&UNK_00327dbc + param_1);  /* field_off=0x327dbc */
            puVar10[0xd5] = (int)fVar15;
            puVar10[100] = iVar3;
            puVar10[0x32] = uVar7;
            *(undefined8 *)(&UNK_00326ad4 + param_1) = 0x1e00000000;  /* field_off=0x326ad4 */
            *puVar2 = 0;
            *(undefined4 *)(&UNK_00326abc + param_1) = 0;  /* field_off=0x326abc */
            *(undefined8 *)(&UNK_00326af4 + param_1) = 0;  /* field_off=0x326af4 */
            *(undefined8 *)(&UNK_00326aec + param_1) = 0xffffffe2;  /* field_off=0x326aec */
            *(undefined8 *)(&UNK_00326b04 + param_1) = 0x1e;  /* field_off=0x326b04 */
            *(undefined8 *)(&UNK_00326afc + param_1) = 0;  /* field_off=0x326afc */
            auVar18 = _UNK_002a9900;  /* UNK_2a9900(vma=0x1a9900)='u32=0x0(0) f32=0' */
            iVar3 = *(int *)(&UNK_00326ac4 + param_1);  /* field_off=0x326ac4 */
            *(undefined8 *)(&UNK_00326adc + param_1) = 0;  /* field_off=0x326adc */
            *(undefined8 *)(&UNK_00326ae4 + param_1) = 0;  /* field_off=0x326ae4 */
            *(long *)(&UNK_00326b14 + param_1) = auVar18._8_8_;  /* field_off=0x326b14 */
            *(long *)(&UNK_00326b0c + param_1) = auVar18._0_8_;  /* field_off=0x326b0c */
            (&UNK_00326fcc)[param_1] = 1;  /* field_off=0x326fcc */
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
        if ((0xb < iVar3) && ((&UNK_00326fcc)[param_1] != '\0')) {  /* field_off=0x326fcc */
          auVar18 = NEON_fmov(0x3fe0000000000000,8);
          iVar4 = *(int *)(&UNK_00326ad4 + param_1);  /* field_off=0x326ad4 */
          iVar13 = (int)*(undefined8 *)(&UNK_00326ad8 + param_1);  /* field_off=0x326ad8 */
          auVar20._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326ad8 + param_1) >> 0x20);  /* field_off=0x326ad8 */
          auVar20._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326ad4 + param_1) = iVar4 + 1;  /* field_off=0x326ad4 */
          auVar20 = NEON_scvtf(auVar20,8);
          *puVar2 = CONCAT44((int)((ulong)*puVar2 >> 0x20) + iVar14,(int)*puVar2 + iVar13);
          dVar17 = auVar18._0_8_;
          dVar19 = auVar18._8_8_;
          *(ulong *)(&UNK_00326ad8 + param_1) =  /* field_off=0x326ad8 */
               CONCAT44((int)(long)(auVar20._8_8_ * dVar19),(int)(long)(auVar20._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;  /* field_off=0x326fcc */
          }
          iVar4 = *(int *)(&UNK_00326ae8 + param_1);  /* field_off=0x326ae8 */
          iVar13 = (int)*(undefined8 *)(&UNK_00326aec + param_1);  /* field_off=0x326aec */
          auVar18._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326aec + param_1) >> 0x20);  /* field_off=0x326aec */
          auVar18._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326ae8 + param_1) = iVar4 + 1;  /* field_off=0x326ae8 */
          auVar18 = NEON_scvtf(auVar18,8);
          *(ulong *)(&UNK_00326ae0 + param_1) =  /* field_off=0x326ae0 */
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326ae0 + param_1) >> 0x20) + iVar14,  /* field_off=0x326ae0 */
                        (int)*(undefined8 *)(&UNK_00326ae0 + param_1) + iVar13);  /* field_off=0x326ae0 */
          *(ulong *)(&UNK_00326aec + param_1) =  /* field_off=0x326aec */
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;  /* field_off=0x326fcc */
          }
          iVar4 = *(int *)(&UNK_00326afc + param_1);  /* field_off=0x326afc */
          iVar13 = (int)*(undefined8 *)(&UNK_00326b00 + param_1);  /* field_off=0x326b00 */
          auVar21._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326b00 + param_1) >> 0x20);  /* field_off=0x326b00 */
          auVar21._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326afc + param_1) = iVar4 + 1;  /* field_off=0x326afc */
          auVar18 = NEON_scvtf(auVar21,8);
          *(ulong *)(&UNK_00326af4 + param_1) =  /* field_off=0x326af4 */
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326af4 + param_1) >> 0x20) + iVar14,  /* field_off=0x326af4 */
                        (int)*(undefined8 *)(&UNK_00326af4 + param_1) + iVar13);  /* field_off=0x326af4 */
          *(ulong *)(&UNK_00326b00 + param_1) =  /* field_off=0x326b00 */
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;  /* field_off=0x326fcc */
          }
          iVar4 = *(int *)(&UNK_00326b10 + param_1);  /* field_off=0x326b10 */
          iVar13 = (int)*(undefined8 *)(&UNK_00326b14 + param_1);  /* field_off=0x326b14 */
          auVar22._0_8_ = (long)iVar13;
          iVar14 = (int)((ulong)*(undefined8 *)(&UNK_00326b14 + param_1) >> 0x20);  /* field_off=0x326b14 */
          auVar22._8_8_ = (long)iVar14;
          *(int *)(&UNK_00326b10 + param_1) = iVar4 + 1;  /* field_off=0x326b10 */
          auVar18 = NEON_scvtf(auVar22,8);
          *(ulong *)(&UNK_00326b08 + param_1) =  /* field_off=0x326b08 */
               CONCAT44((int)((ulong)*(undefined8 *)(&UNK_00326b08 + param_1) >> 0x20) + iVar14,  /* field_off=0x326b08 */
                        (int)*(undefined8 *)(&UNK_00326b08 + param_1) + iVar13);  /* field_off=0x326b08 */
          *(ulong *)(&UNK_00326b14 + param_1) =  /* field_off=0x326b14 */
               CONCAT44((int)(long)(auVar18._8_8_ * dVar19),(int)(long)(auVar18._0_8_ * dVar17));
          if (8 < iVar4) {
            (&UNK_00326fcc)[param_1] = 0;  /* field_off=0x326fcc */
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
              *(undefined4 *)(&UNK_00326670 + param_1) = 0;  /* field_off=0x326670 */
              goto LAB_005be2c4;
            }
LAB_005be2a4:
            if (0x1b < iVar3) {
              (&UNK_00326ac0)[param_1] = 0;  /* field_off=0x326ac0 */
            }
            goto LAB_005be2c4;
          }
          uVar7 = 1;
        }
      }
      *(undefined4 *)(&UNK_00326670 + param_1) = uVar7;  /* field_off=0x326670 */
      goto LAB_005be2c4;
    }
  }
  *(undefined4 *)(&UNK_00326ac8 + param_1) = 0xfffffffa;  /* field_off=0x326ac8 */
LAB_005be2c4:
  lVar9 = 0;
  puVar11 = &UNK_003266a0;  /* field_off=0x3266a0 */
  do {
    if ((&UNK_003268f8)[lVar9 + param_1] != '\0') {  /* field_off=0x3268f8 */
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
        (&UNK_003268f8)[lVar9 + param_1] = 0;  /* field_off=0x3268f8 */
      }
      if (*(int *)(puVar11 + param_1) < -999) {
        (&UNK_003268f8)[lVar9 + param_1] = 0;  /* field_off=0x3268f8 */
      }
    }
    lVar9 = lVar9 + 1;
    puVar11 = puVar11 + 4;
  } while (lVar9 != 0x32);
                    /* WARNING: Read-only address (ram,0x002a9900) is written */
  return;
}


