// ELF VMA: 0x5dbc18
// Ghidra Addr: 0x006dbc18 (ImageBase=0x100000)
// Function: Battle_Sub5DBC18
// Size: 6216 bytes
// Callees (0): 


/* WARNING: Possible PIC construction at 0x006dd3ac: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006dc710: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006dc6ac: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006dce8c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006dcf98: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006dce90) */
/* WARNING: Removing unreachable block (ram,0x006dc714) */
/* WARNING: Removing unreachable block (ram,0x006dc728) */
/* WARNING: Removing unreachable block (ram,0x006dc73c) */
/* WARNING: Removing unreachable block (ram,0x006dc758) */
/* WARNING: Removing unreachable block (ram,0x006dd3b0) */
/* WARNING: Removing unreachable block (ram,0x00a5a38c) */
/* WARNING: Removing unreachable block (ram,0x006dcf9c) */
/* WARNING: Removing unreachable block (ram,0x006dc7a8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Battle_Sub5DBC18(long param_1,long param_2,undefined *param_3)

{
  uint uVar1;
  undefined1 **ppuVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ulong uVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  ulong extraout_x1;
  undefined *puVar16;
  long lVar17;
  int *piVar18;
  undefined8 *puVar19;
  undefined *puVar20;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;
  undefined8 *puVar24;
  ulong uVar25;
  long *plVar26;
  long *plVar27;
  undefined1 **ppuVar28;
  undefined8 uVar29;
  undefined1 *puStack_260;
  undefined8 uStack_258;
  ulong uStack_250;
  ulong uStack_248;
  undefined1 auStack_240 [4];
  int iStack_23c;
  int iStack_238;
  int iStack_234;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  int *piStack_1f0;
  int *piStack_1e8;
  int *piStack_1e0;
  int *piStack_1d8;
  int *piStack_1d0;
  int *piStack_1c8;
  int *piStack_1c0;
  int *piStack_1b8;
  int *piStack_1b0;
  int *piStack_1a8;
  int iStack_19c;
  int *piStack_198;
  int *piStack_190;
  long lStack_188;
  undefined8 *puStack_180;
  long lStack_178;
  int *piStack_170;
  long lStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ulong uStack_150;
  ulong uStack_148;
  int *piStack_138;
  long lStack_130;
  int iStack_124;
  int *piStack_120;
  int iStack_114;
  ulong uStack_110;
  undefined8 uStack_108;
  long lStack_f8;
  ulong uStack_f0;
  int *piStack_e8;
  int iStack_dc;
  long lStack_d8;
  ulong uStack_d0;
  undefined8 uStack_c8;
  ulong *puStack_c0;
  ulong uStack_b0;
  undefined8 uStack_a8;
  undefined8 *puStack_a0;
  int iStack_90;
  undefined1 uStack_89;
  int *piStack_88;
  long lStack_80;
  
  ppuVar28 = (undefined1 **)&stack0xffffffffffffffa0;
  ppuVar2 = (undefined1 **)auStack_240;
  uVar23 = tpidr_el0;
  lStack_80 = *(long *)(uVar23 + 0x28);
  puStack_180 = (undefined8 *)(&UNK_0038816c + param_1);
  uVar22 = (ulong)param_3 & 0xffffffff;
  puVar24 = (undefined8 *)(param_1 + 0x838f8);
  piStack_e8 = (int *)(&UNK_00333e04 + param_1);
  plVar27 = (long *)(&UNK_00338900 + param_1);
  puVar16 = param_3;
  func_0x0058e72c((undefined8 *)(param_1 + 0x838f0),*puVar24);
  *(undefined8 *)(param_1 + 0x838f0) = puVar24;
  iVar12 = (int)param_3;
  bVar3 = iVar12 == 0;
  *(undefined8 *)(param_1 + 0x83900) = 0;
  iStack_114 = -0x3c;
  if (bVar3) {
    iStack_114 = 0x3c;
  }
  iStack_19c = -0x14;
  if (bVar3) {
    iStack_19c = 0x14;
  }
  lStack_d8 = param_1 + (long)iVar12 * 51000 + 0x83908;
  lStack_188 = param_1 + (long)iVar12 * 0x1f0;
  lStack_130 = param_2 + (long)iVar12 * 0x38;
  uVar21 = (ulong)iVar12;
  uVar25 = 0;
  lStack_178 = lStack_188 + 0x26b4;
  iStack_124 = 0;
  if (!bVar3) {
    iStack_124 = -0x73a;
  }
  lVar17 = param_1 + (long)iVar12 * 0xb4;
  lStack_f8 = param_1 + 0x9c778;
  *puVar24 = 0;
  piStack_120 = (int *)(lVar17 + 0x9ce78);
  piStack_138 = (int *)(lVar17 + 0x9ce84);
  piStack_170 = (int *)(lVar17 + 0x9ce90);
  piStack_190 = (int *)(lVar17 + 0x9ce9c);
  piStack_198 = (int *)(lVar17 + 0x9cea8);
  piStack_1a8 = (int *)(lVar17 + 0x9ceb4);
  piStack_1b0 = (int *)(lVar17 + 0x9cec0);
  piStack_1b8 = (int *)(lVar17 + 0x9cecc);
  piStack_1c0 = (int *)(lVar17 + 0x9ced8);
  piStack_1c8 = (int *)(lVar17 + 0x9cee4);
  piStack_1d0 = (int *)(lVar17 + 0x9cef0);
  piStack_1d8 = (int *)(lVar17 + 0x9cefc);
  piStack_1e0 = (int *)(lVar17 + 0x9cf08);
  piStack_1e8 = (int *)(lVar17 + 0x9cf14);
  piStack_1f0 = (int *)(lVar17 + 0x9cf20);
  uStack_108 = 0x19;
  uStack_110 = 0x21;
  uStack_f0 = uVar21;
LAB_006dbe6c:
  iVar4 = func_0x00a58874(uVar22,uVar25 & 0xffffffff);
  if (iVar4 == 0) goto LAB_006dbe60;
  func_0x00a60414((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  func_0x00a61d74((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  uVar5 = func_0x00a608a8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  func_0x00a60a54((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,uVar5);
  uVar5 = func_0x00a60aa0((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  func_0x00a60c4c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,uVar5);
  uVar5 = func_0x00a60c98((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  func_0x00a60ed0(uVar22,uVar25 & 0xffffffff,uVar5);
  uVar5 = func_0x00a5b2b4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  func_0x00a610ac((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,uVar5);
  func_0x00a5a97c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  func_0x00a6073c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  func_0x00a614dc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  func_0x00a61730((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,0);
  puVar16 = (undefined *)0x0;
  func_0x00a61c08((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  iVar4 = (int)uVar21;
  if (uVar25 == 0) {
    iVar6 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
    if (iVar6 == 1) {
      func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
      iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
      if (0x10 < iVar4) {
        func_0x00a578fc((ulong)param_3 & 0xffffffff,2);
        func_0x00a57968((ulong)param_3 & 0xffffffff,0);
        uVar29 = func_0x0044c16c();
        func_0x0044e014(uVar29,0x19);
      }
      goto LAB_006dd1f8;
    }
    iVar6 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
    if ((iVar6 == 2) || (iVar6 = func_0x00a578c8((ulong)param_3 & 0xffffffff), iVar6 == 10)) {
      func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
      uVar13 = func_0x00a57934((ulong)param_3 & 0xffffffff);
      if ((uVar13 & 3) != 0) goto LAB_006dd1f8;
      if (*piStack_120 == 0) {
        lVar17 = 0;
        piVar18 = piStack_120;
      }
      else if (*piStack_138 == 0) {
        lVar17 = 1;
        piVar18 = piStack_138;
      }
      else if (*piStack_170 == 0) {
        lVar17 = 2;
        piVar18 = piStack_170;
      }
      else if (*piStack_190 == 0) {
        lVar17 = 3;
        piVar18 = piStack_190;
      }
      else if (*piStack_198 == 0) {
        lVar17 = 4;
        piVar18 = piStack_198;
      }
      else if (*piStack_1a8 == 0) {
        lVar17 = 5;
        piVar18 = piStack_1a8;
      }
      else if (*piStack_1b0 == 0) {
        lVar17 = 6;
        piVar18 = piStack_1b0;
      }
      else if (*piStack_1b8 == 0) {
        lVar17 = 7;
        piVar18 = piStack_1b8;
      }
      else if (*piStack_1c0 == 0) {
        lVar17 = 8;
        piVar18 = piStack_1c0;
      }
      else if (*piStack_1c8 == 0) {
        lVar17 = 9;
        piVar18 = piStack_1c8;
      }
      else if (*piStack_1d0 == 0) {
        lVar17 = 10;
        piVar18 = piStack_1d0;
      }
      else if (*piStack_1d8 == 0) {
        lVar17 = 0xb;
        piVar18 = piStack_1d8;
      }
      else if (*piStack_1e0 == 0) {
        lVar17 = 0xc;
        piVar18 = piStack_1e0;
      }
      else if (*piStack_1e8 == 0) {
        lVar17 = 0xd;
        piVar18 = piStack_1e8;
      }
      else {
        if (*piStack_1f0 != 0) goto LAB_006dd1f8;
        lVar17 = 0xe;
        piVar18 = piStack_1f0;
      }
      iVar6 = func_0x005ab154();
      if (iVar6 == 0) {
        iVar6 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
        if (iVar6 == 2) {
          uVar29 = 0x1a;
        }
        else {
          iVar6 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
          if (iVar6 != 10) goto LAB_006dd0fc;
          uVar29 = 0x55;
        }
        uVar15 = func_0x0044c16c();
        puVar16 = (undefined *)0x0;
        func_0x0044e35c(uVar15,uVar29);
      }
LAB_006dd0fc:
      iVar6 = func_0x00a57c8c((ulong)param_3 & 0xffffffff);
      if (iVar6 == 0) {
        iVar6 = func_0x0044003c(param_2 + 0x30d8);
        iVar6 = iVar6 + -1;
LAB_006dd138:
        *piVar18 = iVar6;
      }
      else {
        iVar6 = func_0x00a57c8c((ulong)param_3 & 0xffffffff);
        if (iVar6 == 5) {
          iVar6 = func_0x0044003c(param_1 + 0x2d40);
          goto LAB_006dd138;
        }
      }
      iVar8 = func_0x005aecec((ulong)param_3 & 0xffffffff);
      iVar11 = func_0x00a57934((ulong)param_3 & 0xffffffff);
      iVar6 = iVar11 + 3;
      if (-1 < iVar11) {
        iVar6 = iVar11;
      }
      iVar6 = _DAT_00c0b310 * (iVar6 >> 2);
      lVar17 = param_1 + (long)iVar4 * 0xb4 + lVar17 * 0xc;
      iVar4 = iVar6 * -10;
      if (iVar12 != 0) {
        iVar4 = iVar6 * 10;
      }
      *(int *)(lVar17 + 0x9ce7c) = iVar8 + iStack_124 + iVar4;
      uVar5 = func_0x00a57ab8((ulong)param_3 & 0xffffffff);
      *(undefined4 *)(lVar17 + 0x9ce80) = uVar5;
      uVar10 = func_0x00a57934((ulong)param_3 & 0xffffffff);
      uVar9 = uVar10 + 3;
      if (-1 < (int)uVar10) {
        uVar9 = uVar10;
      }
      puVar24 = (undefined8 *)(ulong)uVar9;
      iVar4 = func_0x00a57834((ulong)param_3 & 0xffffffff);
      if (iVar4 <= (int)uVar9 >> 2) {
        func_0x00a578fc((ulong)param_3 & 0xffffffff,0);
        uVar13 = (ulong)param_3 & 0xffffffff;
LAB_006dd1f0:
        func_0x00a57968(uVar13,0);
      }
    }
    else {
      iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
      if ((iVar4 == 3) || (iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff), iVar4 == 0xc)) {
        func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
        iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
        if (0x20 < iVar4) {
LAB_006dc620:
          func_0x00a578fc(0,0);
          uVar13 = 0;
          goto LAB_006dd1f0;
        }
      }
      else {
        iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
        if (iVar4 == 4) {
          func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
          iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
          iVar6 = func_0x0044003c(param_1 + 0x2d40);
          if (iVar6 < iVar4) {
            func_0x00a578fc(0,5);
            func_0x00a57968(0,0);
            uVar29 = func_0x0044c16c();
            uVar15 = 0x24;
LAB_006dce78:
            puVar16 = (undefined *)0x0;
            func_0x0044e35c(uVar29,uVar15);
          }
        }
        else {
          iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
          if (iVar4 == 7) {
            func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
            iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
            iVar6 = func_0x0044003c(param_1 + 0x2d40);
            if (iVar6 < iVar4) {
              func_0x00a578fc(0,8);
              func_0x00a57968(0,0);
              uVar29 = func_0x0044c16c();
              uVar15 = 0x53;
              goto LAB_006dce78;
            }
          }
          else {
            iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
            if ((iVar4 == 5) || (iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff), iVar4 == 8))
            {
              func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
              iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
              lVar17 = 0x2d40;
            }
            else {
              iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
              if (iVar4 != 6) {
                iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
                if (iVar4 == 9) {
                  func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
                  iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
                  if (0x10 < iVar4) {
                    func_0x00a578fc((ulong)param_3 & 0xffffffff,10);
                    func_0x00a57968((ulong)param_3 & 0xffffffff,0);
                    uVar29 = func_0x0044c16c();
                    func_0x0044e014(uVar29,0x54);
                  }
                }
                else {
                  iVar4 = func_0x00a578c8((ulong)param_3 & 0xffffffff);
                  if (iVar4 == 0xb) {
                    func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
                    iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
                    if (iVar4 == 5) {
                      uVar29 = func_0x0044c16c();
                      uVar15 = 0x56;
                      goto LAB_006dce78;
                    }
                    iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
                    puVar24 = (undefined8 *)(ulong)(iVar4 - 10U);
                    iVar6 = func_0x0044003c(param_1 + 0x2d78);
                    if (iVar6 < (int)(iVar4 - 10U)) goto LAB_006dc620;
                  }
                }
                goto LAB_006dd1f8;
              }
              func_0x00a579a0((ulong)param_3 & 0xffffffff,1);
              iVar4 = func_0x00a57934((ulong)param_3 & 0xffffffff);
              lVar17 = 0x2d08;
            }
            iVar6 = func_0x0044003c(param_1 + lVar17);
            if (iVar6 < iVar4) goto LAB_006dc620;
          }
        }
      }
    }
LAB_006dd1f8:
    iVar4 = func_0x00a578b4((ulong)param_3 & 0xffffffff);
    lVar17 = lStack_d8;
    if (iVar4 < 1) {
      iVar4 = *(int *)(lStack_d8 + 0xc);
      puVar24 = (undefined8 *)(lStack_f8 + (ulong)(*(int *)(param_1 + 0x83688) % 5 + 0x32) * 0x10);
      *(undefined4 *)(lStack_d8 + 4) = 2;
      *(undefined4 *)puVar24 = 0xc;
      iVar8 = func_0x0043ea60(0xf1);
      iVar6 = *(int *)(lVar17 + 0x10);
      *(int *)((long)puVar24 + 4) = iVar4 + iVar8 * 10 + -0x43f;
      iVar4 = func_0x0043ea60(0x143);
      *(int *)(puVar24 + 1) = iVar6 + iVar4 * -10 + -0x24b;
      *(undefined4 *)((long)puVar24 + 0xc) = 0;
    }
    else if ((*(int *)(lStack_d8 + 4) == 1) &&
            (iVar4 = *(int *)(lStack_d8 + 8), iVar6 = iVar4 + -1, *(int *)(lStack_d8 + 8) = iVar6,
            iVar6 == 0 || iVar4 < 1)) {
      *(undefined4 *)(lStack_d8 + 4) = 0;
      *(undefined4 *)(lStack_d8 + 8) = 0;
    }
    goto LAB_006dbe60;
  }
  lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
  puVar24 = (undefined8 *)(lVar17 + 0x83908);
  piVar18 = (int *)(lVar17 + 0x83950);
  iVar6 = *piVar18;
  if (0 < iVar6) {
    *piVar18 = iVar6 + -1;
  }
  *(undefined4 *)(param_1 + (long)iVar4 * 51000 + uVar25 * 1000 + 0x83964) = 0;
  iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  if (iVar6 == 0) {
    iVar4 = 0;
    do {
      puVar16 = (undefined *)(uVar25 & 0xffffffff);
      iVar6 = func_0x006ce084(param_1,(ulong)param_3 & 0xffffffff,puVar16,iVar4,0);
      if (iVar6 == 1) goto LAB_006dbe60;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x33);
    iVar4 = func_0x00a608a8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if (iVar4 < 1) {
      iVar4 = func_0x00a58d4c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      iVar6 = func_0x00a60aa0((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (0 < iVar6) {
        iVar4 = func_0x0043ed84(iVar4,1);
      }
      iVar6 = -iVar4;
      if (iVar12 != 0) {
        iVar6 = iVar4;
      }
      func_0x00a59228((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,iVar6);
      puVar16 = (undefined *)((ulong)param_3 & 0xffffffff);
      func_0x009b95b4(param_1,param_2,puVar16,uVar25 & 0xffffffff);
    }
    goto LAB_006dbe60;
  }
  iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  if (iVar6 == 3) {
    func_0x009b95b4(param_1,param_2,(ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    iVar6 = func_0x00a590bc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if (iVar6 == 0) {
      iVar6 = func_0x00a59c68((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (iVar6 == 0) {
        uVar13 = (ulong)param_3 & 0xffffffff;
        puVar16 = (undefined *)(uVar25 & 0xffffffff);
        uVar29 = 0x6dc6b0;
        goto SUB_006dd300;
      }
      puVar16 = (undefined *)0x0;
      func_0x00a58be4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      puVar24 = (undefined8 *)0x3e8;
      if (*(int *)(param_1 + (long)iVar4 * 51000 + uVar25 * 1000 + 0x83928) != 0) goto LAB_006dbe60;
      if ((*(char *)(param_1 + 0x32c9) == '\0') || (iVar12 = func_0x005ab154(), iVar12 != 4)) {
        uVar29 = func_0x0044c16c();
        func_0x0044e35c(uVar29,0x18,0);
      }
      func_0x00a58be4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,4);
      uVar23 = (ulong)param_3 & 0xffffffff;
      uVar25 = uVar25 & 0xffffffff;
      uVar29 = 0x6dc714;
      ppuVar2 = (undefined1 **)auStack_240;
      goto SUB_00a590fc;
    }
    puVar16 = (undefined *)(uVar25 & 0xffffffff);
    uVar13 = func_0x00a595d0(param_2,(ulong)param_3 & 0xffffffff);
    if ((uVar13 & 1) != 0) {
      lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
      puVar16 = (undefined *)(uVar25 & 0xffffffff);
      *(int *)(lVar17 + 0x83914) = *(int *)(lVar17 + 0x83914) + iStack_114;
      func_0x00a5967c(param_2,(ulong)param_3 & 0xffffffff);
    }
    lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
    iVar4 = *(int *)(lVar17 + 0x83910);
    puVar20 = &DAT_00c0aed4;
LAB_006dc054:
    iVar4 = *(int *)(puVar20 + (long)iVar4 * 4);
LAB_006dc058:
    *(int *)(lVar17 + 0x83918) = *(int *)(lVar17 + 0x83918) + iVar4;
  }
  else {
    iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if ((iVar6 == 4) ||
       (iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff), iVar6 == 0x15)) {
      lVar17 = 200;
      piVar18 = piStack_e8;
      do {
        if ((uVar25 == (uint)piVar18[-1]) && (*piVar18 == 1)) goto LAB_006dc2fc;
        lVar17 = lVar17 + -1;
        piVar18 = piVar18 + 0xc;
      } while (lVar17 != 0);
      puVar19 = (undefined8 *)*plVar27;
      if (*(long *)(&UNK_00338908 + param_1) - (long)puVar19 != 0) {
        uVar21 = *(long *)(&UNK_00338908 + param_1) - (long)puVar19 >> 3;
        if (uVar21 < 2) {
          uVar21 = 1;
        }
        do {
          if ((*(int *)*puVar19 == iVar12) && (uVar25 == (uint)((int *)*puVar19)[1]))
          goto LAB_006dc2fc;
          uVar21 = uVar21 - 1;
          puVar19 = puVar19 + 1;
        } while (uVar21 != 0);
      }
      iVar4 = 1;
      goto LAB_006dc308;
    }
    iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if (iVar6 == 5) {
      func_0x009b95b4(param_1,param_2,(ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      iVar6 = func_0x00a590bc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (iVar6 != 0) {
        puVar16 = (undefined *)(uVar25 & 0xffffffff);
        uVar13 = func_0x00a595d0(param_2,(ulong)param_3 & 0xffffffff);
        if ((uVar13 & 1) != 0) {
          lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
          puVar16 = (undefined *)(uVar25 & 0xffffffff);
          *(int *)(lVar17 + 0x83914) = *(int *)(lVar17 + 0x83914) + iStack_19c;
          func_0x00a5967c(param_2,(ulong)param_3 & 0xffffffff);
        }
        lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
        iVar4 = *(int *)(lVar17 + 0x83910);
        puVar20 = &DAT_00c0af34;
        goto LAB_006dc054;
      }
LAB_006dc984:
      iVar4 = func_0x00a59c68((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (iVar4 == 0) {
        uVar13 = (ulong)param_3 & 0xffffffff;
        puVar16 = (undefined *)(uVar25 & 0xffffffff);
        uVar29 = 0x6dce90;
        goto SUB_006dd300;
      }
      puVar16 = (undefined *)0x0;
      func_0x00a58be4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    }
    else {
      puVar24 = (undefined8 *)0x3e8;
      iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (iVar6 == 6) {
        func_0x009b95b4(param_1,param_2,(ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        iVar6 = func_0x00a590bc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        if (iVar6 == 0) goto LAB_006dc984;
        puVar16 = (undefined *)(uVar25 & 0xffffffff);
        uVar13 = func_0x00a595d0(param_2,(ulong)param_3 & 0xffffffff);
        if ((uVar13 & 1) != 0) {
          lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
          puVar24 = (undefined8 *)(lVar17 + 0x83908);
          iVar6 = (0xc - *(int *)(lVar17 + 0x83910)) % 0xc;
          iVar4 = iVar6 * -10;
          if (iVar12 == 0) {
            iVar4 = iVar6 * 10;
          }
          iVar6 = func_0x00a628b8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          iVar8 = func_0x00a6081c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          puVar16 = (undefined *)(uVar25 & 0xffffffff);
          *(int *)(lVar17 + 0x83914) =
               (((iVar4 * (100 - iVar6)) / 100) * (100 - iVar8)) / 100 + *(int *)(lVar17 + 0x83914);
          func_0x00a5967c(param_2,(ulong)param_3 & 0xffffffff);
          func_0x00a628b8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          func_0x00a6081c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        }
        goto LAB_006dbe60;
      }
      iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      if (iVar6 == 7) {
        func_0x009b95b4(param_1,param_2,(ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        iVar6 = func_0x00a590bc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        if (iVar6 != 0) {
          puVar16 = (undefined *)(uVar25 & 0xffffffff);
          uVar13 = func_0x00a595d0(param_2,(ulong)param_3 & 0xffffffff);
          puVar24 = (undefined8 *)0x3e8;
          if ((uVar13 & 1) != 0) {
            lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
            puVar16 = (undefined *)(uVar25 & 0xffffffff);
            *(int *)(lVar17 + 0x83914) = *(int *)(lVar17 + 0x83914) + iStack_114;
            func_0x00a5967c(param_2,(ulong)param_3 & 0xffffffff);
          }
          lVar17 = param_1 + (long)iVar4 * 51000 + uVar25 * 1000;
          iVar4 = *(int *)(lVar17 + 0x83910);
          if (iVar4 < 0) {
            iVar4 = iVar4 + 1;
          }
          iVar4 = *(int *)(&DAT_00c0aed4 + (long)(iVar4 >> 1) * 4);
          goto LAB_006dc058;
        }
        uVar29 = func_0x00a59c68((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        if ((int)uVar29 == 0) {
          puVar16 = (undefined *)(uVar25 & 0xffffffff);
          func_0x006dd300(uVar29,(ulong)param_3 & 0xffffffff);
        }
        else {
          puVar16 = (undefined *)0x0;
          func_0x00a58be4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        }
        puVar24 = (undefined8 *)0x3e8;
        if (*(int *)(param_1 + (long)iVar4 * 51000 + uVar25 * 1000 + 0x83928) == 0) {
          if ((*(char *)(param_1 + 0x32c9) == '\0') || (iVar12 = func_0x005ab154(), iVar12 != 4)) {
            uVar29 = func_0x0044c16c();
            func_0x0044e35c(uVar29,0x18,0);
          }
          func_0x00a58be4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff,4);
          uVar23 = (ulong)param_3 & 0xffffffff;
          uVar25 = uVar25 & 0xffffffff;
          uVar29 = 0x6dcf9c;
          goto SUB_00a590fc;
        }
      }
      else {
        puVar16 = (undefined *)((ulong)param_3 & 0xffffffff);
        func_0x006dd3f0(param_1,param_2,puVar16,uVar25 & 0xffffffff);
      }
    }
  }
  goto LAB_006dbe60;
LAB_006dc2fc:
  iVar4 = 0;
LAB_006dc308:
  iVar6 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
  iStack_dc = iVar4;
  if (iVar6 == 4) {
    iVar4 = func_0x00a590bc();
    if (iVar4 == 0) {
      puVar16 = (undefined *)0x1;
      func_0x006ee0f4(param_1 + 0xe0,(ulong)param_3 & 0xffffffff);
    }
    uVar21 = func_0x00a59fd4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if ((uVar21 & 1) == 0) {
      iVar6 = 1;
    }
    else {
      uVar21 = func_0x005ab2d8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      puVar16 = (undefined *)(uVar21 & 0xffffffff);
      func_0x005acf30(param_2,(ulong)param_3 & 0xffffffff,puVar16,8);
      iVar6 = func_0x0044003c();
      if (iVar6 < 2) {
        iVar6 = 1;
      }
    }
    iVar8 = func_0x00a59eb4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    iVar4 = iVar6;
    if (-1 < iVar8) {
      iStack_90 = func_0x00a59eb4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      piStack_88 = &iStack_90;
      iStack_90 = iStack_90 + 1000;
      puVar16 = &UNK_002afa25;
      lVar17 = func_0x0064bd28(param_2 + 0x33a8,&iStack_90,&UNK_002afa25,&piStack_88,&uStack_89);
      iVar4 = func_0x0044003c(lVar17 + 0x28);
      if (iVar4 <= iVar6) {
        iVar4 = iVar6;
      }
    }
  }
  else {
    iVar4 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if (iVar4 == 0x15) {
      puStack_a0 = (undefined8 *)func_0x00bc3330(0x20);
      uStack_a8 = uStack_108;
      uStack_b0 = uStack_110;
      *(undefined1 *)((long)puStack_a0 + 0x19) = 0;
      uStack_158 = 0x656d69745f6f6e61;
      uStack_160 = 0x636c6f765f687461;
      uStack_148 = 0x6c6f765f68746165;
      uStack_150 = 0x645f656c74746162;
      puStack_a0[1] = 0x6c6f765f68746165;
      *puStack_a0 = 0x645f656c74746162;
      *(undefined8 *)((long)puStack_a0 + 0x11) = 0x656d69745f6f6e61;
      *(undefined8 *)((long)puStack_a0 + 9) = 0x636c6f765f687461;
      uVar5 = func_0x008e3f14(param_1 + 0x1478,&uStack_b0,0x1e);
      uVar7 = func_0x0044003c(lStack_130 + 0x27f8);
      iVar4 = func_0x0043ed6c(uVar5,uVar7);
      uVar21 = 51000;
      lStack_168 = param_2;
      if ((uStack_b0 & 1) != 0) {
        func_0x00bc3350(puStack_a0);
      }
      if (iVar4 < 2) {
        iVar4 = 1;
      }
      iVar6 = func_0x00a590bc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      puStack_c0 = (ulong *)func_0x00bc3330(0x20);
      *(undefined1 *)((long)puStack_c0 + 0x19) = 0;
      uStack_c8 = uStack_108;
      uStack_d0 = uStack_110;
      puStack_c0[1] = uStack_148;
      *puStack_c0 = uStack_150;
      *(undefined8 *)((long)puStack_c0 + 0x11) = uStack_158;
      *(undefined8 *)((long)puStack_c0 + 9) = uStack_160;
      puVar16 = (undefined *)0x1e;
      iVar8 = func_0x008e3f14(param_1 + 0x1478,&uStack_d0);
      if ((uStack_d0 & 1) != 0) {
        func_0x00bc3350(puStack_c0);
      }
      param_2 = lStack_168;
      if (iVar6 == iVar8) {
        puVar16 = (undefined *)(uVar25 & 0xffffffff);
        func_0x006da618(param_1,(ulong)param_3 & 0xffffffff,puVar16,0);
        uStack_1f8 = *(undefined8 *)((long)puStack_180 + 0x1c);
        uStack_200 = *(undefined8 *)((long)puStack_180 + 0x14);
        uStack_208 = puStack_180[1];
        uStack_210 = *puStack_180;
        iStack_23c = *(int *)(puStack_180 + 2);
        iStack_238 = *(int *)(puStack_180 + 3);
        iVar6 = *(int *)((long)puStack_180 + 0x24);
        uStack_220 = *(undefined8 *)((long)puStack_180 + 0x1c);
        uStack_218 = 0;
        uStack_228 = puStack_180[6];
        uStack_230 = puStack_180[5];
        uVar5 = func_0x00a5f6cc((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
        piVar18 = (int *)func_0x00bc3330(0x48);
        puVar19 = *(undefined8 **)(&UNK_00338908 + param_1);
        puVar14 = *(undefined8 **)(&UNK_00338910 + param_1);
        piVar18[0x10] = 0;
        piVar18[0x11] = 0;
        uStack_160 = CONCAT44(uStack_160._4_4_,uVar5);
        piVar18[2] = 0;
        piVar18[3] = 0;
        piVar18[0] = 0;
        piVar18[1] = 0;
        piVar18[6] = 0;
        piVar18[7] = 0;
        piVar18[4] = 0;
        piVar18[5] = 0;
        piVar18[10] = 0;
        piVar18[0xb] = 0;
        piVar18[8] = 0;
        piVar18[9] = 0;
        piVar18[0xe] = 0;
        piVar18[0xf] = 0;
        piVar18[0xc] = 0;
        piVar18[0xd] = 0;
        *(int **)(piVar18 + 0xc) = piVar18 + 0xe;
        iStack_234 = iVar6;
        if (puVar19 < puVar14) {
          piStack_88 = (int *)0x0;
          puVar14 = puVar19 + 1;
          *puVar19 = piVar18;
        }
        else {
          piStack_88 = piVar18;
          puVar14 = (undefined8 *)func_0x005c8c54(plVar27,&piStack_88);
        }
        piVar18 = piStack_88;
        *(undefined8 **)(&UNK_00338908 + param_1) = puVar14;
        piStack_88 = (int *)0x0;
        if (piVar18 != (int *)0x0) {
          func_0x0058c04c(piVar18 + 0xc,*(undefined8 *)(piVar18 + 0xe));
          func_0x00bc3350(piVar18);
          puVar14 = *(undefined8 **)(&UNK_00338908 + param_1);
        }
        plVar26 = plVar27;
        uStack_150 = uVar23;
        if (puVar14 == (undefined8 *)*plVar27) {
LAB_006dd26c:
          if (*(long *)(uStack_150 + 0x28) != lStack_80) goto LAB_006dd2fc;
          func_0x005c8c40(plVar27);
          plVar27 = plVar26;
        }
        else {
          piVar18 = (int *)puVar14[-1];
          *piVar18 = iVar12;
          piVar18[1] = (int)uVar25;
          piVar18[2] = 0;
          iVar6 = func_0x00a5919c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          uVar9 = func_0x00a5d468((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          uVar23 = (ulong)uVar9;
          func_0x00a5d4f4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          func_0x0043ecf8();
          uVar10 = func_0x0043ea60();
          plVar26 = (long *)(ulong)uVar10;
          iVar8 = func_0x00a5d4f4((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          if (*(long *)(&UNK_00338908 + param_1) == *plVar27) goto LAB_006dd26c;
          uVar1 = -uVar10;
          if (iVar8 < 1) {
            uVar1 = uVar10;
          }
          *(uint *)(*(long *)(*(long *)(&UNK_00338908 + param_1) + -8) + 0xc) =
               (iVar6 - uVar9) + uVar1;
          uVar5 = func_0x00a5d580((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          if (*(long *)(&UNK_00338908 + param_1) == *plVar27) {
            lVar17 = *(long *)(uStack_150 + 0x28);
            goto LAB_006dd298;
          }
          lVar17 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
          *(undefined4 *)(lVar17 + 0x10) = uVar5;
          *(undefined4 *)(lVar17 + 0x14) = 0;
          *(undefined4 *)(lVar17 + 0x24) = (undefined4)uStack_160;
          uVar23 = (ulong)CONCAT16(-((int)((ulong)uStack_230 >> 0x20) != 0),
                                   (uint6)CONCAT14(-((int)uStack_230 != 0),
                                                   (uint)(CONCAT12(-(iStack_234 != 0),
                                                                   -(ushort)((int)uStack_200 != 0))
                                                         & 0xff00ff))) & 0x1000100010001;
          *(uint *)(lVar17 + 0x20) =
               CONCAT13((char)(uVar23 >> 0x30),
                        CONCAT12((char)(uVar23 >> 0x20),
                                 CONCAT11((char)(uVar23 >> 0x10),(char)uVar23)));
          *(ulong *)(lVar17 + 0x18) =
               CONCAT17(~-((int)uStack_220 == 0),
                        CONCAT16(~-((int)((ulong)uStack_220 >> 0x20) == 0),
                                 CONCAT15(~-(iStack_238 == 0),
                                          CONCAT14(~-(iStack_23c == 0),
                                                   CONCAT13(~-((int)((ulong)uStack_208 >> 0x20) == 0
                                                              ),CONCAT12(~-((int)uStack_208 == 0),
                                                                         CONCAT11(~-((int)((ulong)
                                                  uStack_210 >> 0x20) == 0),~-((int)uStack_210 == 0)
                                                  ))))))) & 0x101010101010101;
          iVar6 = func_0x00a5d698((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          uVar23 = uStack_150;
          if (*(long *)(&UNK_00338908 + param_1) != *plVar27) {
            lVar17 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
            *(bool *)(lVar17 + 0x28) = iVar6 != 0;
            *(undefined4 *)(lVar17 + 0x2c) = 2;
            param_2 = lStack_168;
            goto LAB_006dcc44;
          }
        }
        lVar17 = *(long *)(uVar23 + 0x28);
LAB_006dd298:
        if (lVar17 == lStack_80) {
          uVar21 = func_0x005c8c40(plVar27);
          func_0x005c3ee4(&piStack_88);
          if (*(long *)(uVar23 + 0x28) == lStack_80) {
            func_0x00bbf40c(uVar21);
          }
        }
        goto LAB_006dd2fc;
      }
    }
    else {
      iVar4 = 1;
    }
  }
LAB_006dcc44:
  uVar21 = uStack_f0;
  iVar6 = (int)uStack_f0;
  if (*(int *)(param_1 + (long)iVar6 * 51000 + uVar25 * 1000 + 0x83910) < iVar4) {
    puVar16 = (undefined *)((ulong)param_3 & 0xffffffff);
    func_0x009b95b4(param_1,param_2,puVar16,uVar25 & 0xffffffff);
  }
  else if (iStack_dc != 0) {
    iVar4 = func_0x00a5da7c((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
    if (-1 < iVar4) {
      uVar13 = 0;
      do {
        if ((uVar25 != uVar13) &&
           (iVar4 = func_0x00a58874((ulong)param_3 & 0xffffffff,uVar13 & 0xffffffff), iVar4 != 0)) {
          iVar4 = func_0x00a58934((ulong)param_3 & 0xffffffff,uVar13 & 0xffffffff);
          iVar8 = func_0x00a58934((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
          if ((iVar4 == iVar8) &&
             (iVar4 = func_0x00a58ba4((ulong)param_3 & 0xffffffff,uVar13 & 0xffffffff), iVar4 != 4))
          goto LAB_006dcd2c;
        }
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 != 0x33);
      iVar4 = func_0x005ab2d8((ulong)param_3 & 0xffffffff,uVar25 & 0xffffffff);
      *(undefined4 *)(lStack_178 + (long)iVar4 * 4) = 0;
    }
LAB_006dcd2c:
    if (((iVar12 == 0) && (iVar4 = func_0x00a62da4(0,uVar25 & 0xffffffff), 0 < iVar4)) &&
       (0 < *(int *)(lStack_d8 + 0x30))) {
      iVar4 = func_0x00a579e0(0);
      iVar8 = func_0x00a62da4(0,uVar25 & 0xffffffff);
      iVar4 = (iVar8 * iVar4) / 1000;
      func_0x00a579e0(0);
      func_0x00a62da4(0,uVar25 & 0xffffffff);
      lVar17 = lStack_d8;
      func_0x0043ed6c(*(int *)(lStack_d8 + 0x30) - iVar4,1);
      iVar4 = *(int *)(lVar17 + 0x30) - iVar4;
      if (iVar4 < 2) {
        iVar4 = 1;
      }
      *(int *)(lVar17 + 0x30) = iVar4;
    }
    *(undefined4 *)puVar24 = 0;
    lVar17 = param_1 + (long)iVar6 * 51000 + uVar25 * 1000;
    *(undefined8 *)(lVar17 + 0x83978) = 0;
    *(undefined4 *)(lVar17 + 0x83974) = 0;
  }
LAB_006dbe60:
  uVar25 = uVar25 + 1;
  if (uVar25 == 0x33) {
    if (*(long *)(uVar23 + 0x28) == lStack_80) {
      return;
    }
LAB_006dd2fc:
    uVar29 = 0x6dd300;
    func_0x00bc3380();
    uVar13 = extraout_x1;
SUB_006dd300:
    uVar23 = uVar13 & 0xffffffff;
    uVar25 = (ulong)puVar16 & 0xffffffff;
    puStack_260 = (undefined1 *)ppuVar28;
    uStack_258 = uVar29;
    uStack_250 = uVar22;
    uStack_248 = uVar21;
    iVar12 = func_0x00a5a7ec(uVar13 & 0xffffffff,(ulong)puVar16 & 0xffffffff);
    if ((iVar12 == 0) &&
       ((iVar12 = func_0x00a58ba4(uVar23,uVar25), iVar12 != 1 ||
        (iVar12 = func_0x00a58d4c(uVar23,uVar25), iVar12 != 0)))) {
      func_0x00a58be4(uVar23,uVar25,1);
      uVar29 = 0x6dd3b0;
      ppuVar2 = &puStack_260;
      uVar21 = uVar25;
      uVar22 = uVar23;
      ppuVar28 = &puStack_260;
    }
    else {
      iVar12 = func_0x00a5a7ec(uVar23,uVar25);
      if ((iVar12 != 2) ||
         ((iVar12 = func_0x00a58ba4(uVar23,uVar25), iVar12 == 4 ||
          (iVar12 = func_0x00a58ba4(uVar23,uVar25), iVar12 == 0x15)))) {
        return;
      }
      func_0x00a58be4(uVar23,uVar25,4);
      ppuVar2 = (undefined1 **)auStack_240;
      uVar21 = uStack_248;
      uVar22 = uStack_250;
      ppuVar28 = (undefined1 **)puStack_260;
      uVar29 = uStack_258;
    }
SUB_00a590fc:
    *(undefined1 ***)((long)ppuVar2 + -0x30) = ppuVar28;
    *(undefined8 *)((long)ppuVar2 + -0x28) = uVar29;
    *(undefined8 **)((long)ppuVar2 + -0x20) = puVar24;
    *(ulong *)((long)ppuVar2 + -0x10) = uVar22;
    *(ulong *)((long)ppuVar2 + -8) = uVar21;
    lVar17 = func_0x007fd748();
    *(undefined4 *)(lVar17 + (long)(int)uVar23 * 51000 + (long)(int)uVar25 * 1000 + 0x83910) = 0;
    return;
  }
  goto LAB_006dbe6c;
}


