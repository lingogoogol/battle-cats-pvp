// ELF VMA: 0x4c6340
// Ghidra Addr: 0x005c6340 (ImageBase=0x100000)
// Function: Battle_DamageEngine
// Size: 2736 bytes
// Callees (0): 


/* WARNING: Possible PIC construction at 0x005c6688: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x005c668c) */

long * Battle_DamageEngine(long param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  long *plVar14;
  long *plVar15;
  undefined8 *puVar16;
  undefined *puVar17;
  long lVar18;
  long *plVar19;
  ulong uVar20;
  long *plVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  undefined1 auVar24 [16];
  byte abStack_d0 [16];
  undefined8 uStack_c0;
  int iStack_b4;
  byte abStack_b0 [16];
  undefined8 uStack_a0;
  byte abStack_98 [16];
  undefined8 uStack_88;
  byte abStack_80 [16];
  undefined8 uStack_70;
  long lStack_68;
  
  lVar1 = tpidr_el0;
  lStack_68 = *(long *)(lVar1 + 0x28);
  uVar20 = 1 - (long)param_2;
  iVar4 = func_0x00a57c8c(param_2);
  if (iVar4 == 5) {
    iVar4 = func_0x00a58ba4(uVar20 & 0xffffffff,param_3);
    bVar2 = iVar4 == 0xc;
  }
  else {
    bVar2 = false;
  }
  uVar10 = func_0x00a584d0(param_2);
  if (((uVar10 & 1) == 0) || (iVar4 = func_0x00a58ba4(uVar20 & 0xffffffff,param_3), iVar4 != 0xe)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 2;
  }
  *(undefined4 *)(param_1 + uVar20 * 51000 + (long)param_3 * 1000 + 0x83a88) = uVar7;
  plVar11 = (long *)func_0x00a58fe8(uVar20 & 0xffffffff,param_3,0);
  if ((bVar2 || ((ulong)plVar11 & 1) != 0) &&
     (plVar11 = (long *)func_0x00a5987c(uVar20 & 0xffffffff,param_3), (int)plVar11 < param_4)) {
    uVar10 = func_0x00a5ac18(uVar20 & 0xffffffff,param_3,0);
    iVar4 = (int)uVar20;
    if ((uVar10 & 1) == 0) {
LAB_005c64c8:
      uVar10 = func_0x00a57c18(param_2);
      if (((uVar10 & 1) == 0) ||
         (uVar10 = func_0x00a5f994(uVar20 & 0xffffffff,param_3), (uVar10 & 1) == 0)) {
        uVar7 = func_0x00a57ab8(param_2);
        func_0x00a598bc(uVar20 & 0xffffffff,param_3,uVar7);
        uVar10 = func_0x00a57c18(param_2);
        if (((uVar10 & 1) == 0) ||
           (plVar11 = (long *)func_0x00a5f900(uVar20 & 0xffffffff,param_3),
           ((ulong)plVar11 & 1) == 0)) {
          plVar11 = (long *)(&UNK_00428c70 + param_1);
          iVar4 = func_0x00a57c8c(param_2);
          if (iVar4 == 4) {
            iVar4 = func_0x00a57f14(param_2);
            if (iVar4 == 0) {
              iVar4 = func_0x00a5a220(uVar20 & 0xffffffff,param_3);
            }
            else {
              iVar4 = func_0x00a57f14(param_2);
              if (iVar4 == 1) {
                iVar4 = func_0x00a5a194(uVar20 & 0xffffffff,param_3);
              }
              else {
                iVar4 = 0;
              }
            }
            iVar5 = func_0x00a57c8c(param_2);
            puVar22 = (undefined8 *)(&UNK_00428c78 + param_1);
            puVar16 = (undefined8 *)*puVar22;
            puVar23 = puVar22;
            if ((undefined8 *)*puVar22 != (undefined8 *)0x0) {
              do {
                while (puVar12 = puVar16, puVar22 = puVar12, iVar5 < *(int *)(puVar12 + 4)) {
                  puVar16 = (undefined8 *)*puVar12;
                  puVar23 = puVar12;
                  if ((undefined8 *)*puVar12 == (undefined8 *)0x0) goto LAB_005c670c;
                }
                if (iVar5 <= *(int *)(puVar12 + 4)) goto LAB_005c6768;
                puVar16 = (undefined8 *)puVar12[1];
              } while ((undefined8 *)puVar12[1] != (undefined8 *)0x0);
              puVar23 = puVar12 + 1;
            }
LAB_005c670c:
            puVar12 = (undefined8 *)func_0x00bc3330(0x40);
            *(int *)(puVar12 + 4) = iVar5;
            puVar12[6] = 0;
            puVar12[7] = 0;
            puVar12[5] = 0;
            *puVar12 = 0;
            puVar12[1] = 0;
            puVar12[2] = puVar22;
            *puVar23 = puVar12;
            puVar16 = puVar12;
            if (*(long *)*plVar11 != 0) {
              *plVar11 = *(long *)*plVar11;
              puVar16 = (undefined8 *)*puVar23;
            }
            func_0x0040a8c0(*(undefined8 *)(&UNK_00428c78 + param_1),puVar16);
            *(long *)(&UNK_00428c80 + param_1) = *(long *)(&UNK_00428c80 + param_1) + 1;
LAB_005c6768:
            func_0x00bc3540(abStack_80,&UNK_0029e556,puVar12 + 5);
            if ((abStack_80[0] & 1) != 0) {
              func_0x00bc3350(uStack_70);
            }
            func_0x00a589e0(abStack_98,uVar20 & 0xffffffff,param_3);
            if ((abStack_98[0] & 1) != 0) {
              func_0x00bc3350(uStack_88);
            }
            uVar10 = func_0x00a5b644(uVar20 & 0xffffffff,param_3);
            if ((uVar10 & 1) == 0) {
              iVar5 = func_0x00a5832c(param_2);
              iVar4 = (iVar5 * iVar4) / 1000;
              func_0x0043ed6c(iVar4,1);
              func_0x00a5832c(param_2);
            }
            else {
              iVar5 = func_0x00a5816c(param_2);
              iVar4 = (iVar5 * iVar4) / 1000;
              func_0x0043ed6c(iVar4,1);
              func_0x00a5816c(param_2);
            }
LAB_005c6b48:
            if (iVar4 < 2) {
              iVar4 = 1;
            }
            func_0x00a60488(uVar20 & 0xffffffff,param_3,iVar4);
          }
          else {
            iVar4 = func_0x00a57c8c(param_2);
            if (iVar4 == 5) {
              iVar4 = func_0x00a57f14(param_2);
              if (iVar4 == 0) {
                iVar4 = func_0x00a5a220(uVar20 & 0xffffffff,param_3);
              }
              else {
                iVar4 = func_0x00a57f14(param_2);
                if (iVar4 == 1) {
                  iVar4 = func_0x00a5a194(uVar20 & 0xffffffff,param_3);
                }
                else {
                  iVar4 = 0;
                }
              }
              iVar5 = func_0x00a57c8c(param_2);
              puVar22 = (undefined8 *)(&UNK_00428c78 + param_1);
              puVar16 = (undefined8 *)*puVar22;
              puVar23 = puVar22;
              if ((undefined8 *)*puVar22 != (undefined8 *)0x0) {
                do {
                  while (puVar12 = puVar16, puVar22 = puVar12, iVar5 < *(int *)(puVar12 + 4)) {
                    puVar16 = (undefined8 *)*puVar12;
                    puVar23 = puVar12;
                    if ((undefined8 *)*puVar12 == (undefined8 *)0x0) goto LAB_005c69a8;
                  }
                  if (iVar5 <= *(int *)(puVar12 + 4)) goto LAB_005c6a04;
                  puVar16 = (undefined8 *)puVar12[1];
                } while ((undefined8 *)puVar12[1] != (undefined8 *)0x0);
                puVar23 = puVar12 + 1;
              }
LAB_005c69a8:
              puVar12 = (undefined8 *)func_0x00bc3330(0x40);
              *(int *)(puVar12 + 4) = iVar5;
              puVar12[6] = 0;
              puVar12[7] = 0;
              puVar12[5] = 0;
              *puVar12 = 0;
              puVar12[1] = 0;
              puVar12[2] = puVar22;
              *puVar23 = puVar12;
              puVar16 = puVar12;
              if (*(long *)*plVar11 != 0) {
                *plVar11 = *(long *)*plVar11;
                puVar16 = (undefined8 *)*puVar23;
              }
              func_0x0040a8c0(*(undefined8 *)(&UNK_00428c78 + param_1),puVar16);
              *(long *)(&UNK_00428c80 + param_1) = *(long *)(&UNK_00428c80 + param_1) + 1;
LAB_005c6a04:
              func_0x00bc3540(abStack_80,&UNK_0029e556,puVar12 + 5);
              if ((abStack_80[0] & 1) != 0) {
                func_0x00bc3350(uStack_70);
              }
              func_0x00a589e0(abStack_b0,uVar20 & 0xffffffff,param_3);
              if ((abStack_b0[0] & 1) != 0) {
                func_0x00bc3350(uStack_a0);
              }
              uVar10 = func_0x00a5b960(uVar20 & 0xffffffff,param_3);
              if ((uVar10 & 1) == 0) {
                iVar5 = func_0x00a58398(param_2);
                iVar4 = (iVar5 * iVar4) / 1000;
                func_0x0040cb78(abStack_80,&UNK_002b1bd4);
                func_0x0043ed6c(iVar4,1);
                if ((abStack_80[0] & 1) != 0) {
                  func_0x00bc3350(uStack_70);
                }
              }
              else {
                iVar5 = func_0x00a58ba4(uVar20 & 0xffffffff,param_3);
                if (((iVar5 == 0xb) ||
                    (iVar5 = func_0x00a58ba4(uVar20 & 0xffffffff,param_3), iVar5 == 0xc)) ||
                   (iVar5 = func_0x00a58ba4(uVar20 & 0xffffffff,param_3), iVar5 == 0xd)) {
                  iVar5 = func_0x00a58404(param_2);
                  iVar4 = (iVar5 * iVar4) / 1000;
                  func_0x0040cb78(abStack_80,&UNK_002a6816);
                  func_0x0043ed6c(iVar4,1);
                }
                else {
                  iVar5 = func_0x00a581d8(param_2);
                  iVar4 = (iVar5 * iVar4) / 1000;
                  func_0x0040cb78(abStack_80,&UNK_0028ba5f);
                  func_0x0043ed6c(iVar4,1);
                }
                if ((abStack_80[0] & 1) != 0) {
                  func_0x00bc3350(uStack_70);
                }
                func_0x00a625c4(uVar20 & 0xffffffff,param_3,1);
              }
              goto LAB_005c6b48;
            }
            iVar4 = func_0x00a57c8c(param_2);
            if (iVar4 != 0) {
              iStack_b4 = func_0x00a57c8c(param_2);
              auVar24._8_8_ = &iStack_b4;
              auVar24._0_8_ = &UNK_00428c70 + param_1;
              goto SUB_005c6cdc;
            }
            func_0x0040cb78(abStack_80,&UNK_002a04dc);
            if ((abStack_80[0] & 1) != 0) {
              func_0x00bc3350(uStack_70);
            }
            func_0x00a589e0(abStack_d0,uVar20 & 0xffffffff,param_3);
            if ((abStack_d0[0] & 1) != 0) {
              func_0x00bc3350(uStack_c0);
            }
            iVar4 = func_0x00a57d64(param_2);
            if ((iVar4 < 1) ||
               (uVar10 = func_0x00a5b644(uVar20 & 0xffffffff,param_3), (uVar10 & 1) == 0)) {
              iVar4 = func_0x00a57d64(param_2);
              iVar5 = func_0x00a57c8c(param_2);
              if (iVar5 == 0) {
                uVar7 = func_0x007ac230();
                plVar11 = (long *)func_0x00633678(param_1 + 0x668,uVar7,9);
                if (plVar11 != (long *)0x0) {
                  if ((int *)plVar11[1] == (int *)*plVar11) {
                    if (*(long *)(lVar1 + 0x28) == lStack_68) {
                      uVar13 = func_0x00470c38();
                      if ((abStack_80[0] & 1) != 0) {
                        func_0x00bc3350(uStack_70);
                      }
                      if (*(long *)(lVar1 + 0x28) == lStack_68) {
                        func_0x00bbf40c(uVar13);
                      }
                    }
                    goto LAB_005c6cd8;
                  }
                  iVar4 = (*(int *)*plVar11 * iVar4) / 100;
                }
              }
              func_0x00a60488(uVar20 & 0xffffffff,param_3,iVar4);
              puVar17 = &UNK_002b1bd4;
            }
            else {
              func_0x00a60488(uVar20 & 0xffffffff,param_3,1);
              puVar17 = &UNK_0029454c;
            }
            func_0x0040cb78(abStack_80,puVar17);
            if ((abStack_80[0] & 1) != 0) {
              func_0x00bc3350(uStack_70);
            }
          }
          uVar10 = func_0x00a58244(param_2);
          if ((uVar10 & 1) != 0) {
            func_0x00a59950(uVar20 & 0xffffffff,param_3,1);
          }
          iVar4 = func_0x00a5fe34(uVar20 & 0xffffffff,param_3);
          if ((0 < iVar4) && (iVar4 = func_0x00a57c8c(param_2), iVar4 == 6)) {
            func_0x00a60660(uVar20 & 0xffffffff,param_3,2);
          }
          iVar4 = func_0x00a57c8c(param_2);
          uVar8 = func_0x00a58470(param_2);
          uVar9 = func_0x00a58490(param_2);
          bVar3 = func_0x00a584b0(param_2);
          plVar11 = (long *)func_0x006d6da0(param_1,param_2,0,param_3,0x19,iVar4 == 6,uVar8 & 1,
                                            uVar9 & 1,0,0,bVar3 & 1,0,1);
          goto LAB_005c6c1c;
        }
        lVar18 = param_1 + (long)iVar4 * 51000 + (long)param_3 * 1000;
        uVar8 = 0x3a78;
      }
      else {
        func_0x00a578fc(0,0);
        func_0x00a57968(0,0);
        plVar11 = (long *)func_0x00a57c8c(param_2);
        if (((int)plVar11 == 0) || (plVar11 = (long *)func_0x00a57c8c(param_2), (int)plVar11 == 5))
        {
          lVar18 = param_1 + (long)param_2 * 0xb4;
          *(undefined4 *)(lVar18 + 0x9ce78) = 0;
          *(undefined4 *)(lVar18 + 0x9ce84) = 0;
          *(undefined4 *)(lVar18 + 0x9ce90) = 0;
          *(undefined4 *)(lVar18 + 0x9ce9c) = 0;
          *(undefined4 *)(lVar18 + 0x9cea8) = 0;
          *(undefined4 *)(lVar18 + 0x9ceb4) = 0;
          *(undefined4 *)(lVar18 + 0x9cec0) = 0;
          *(undefined4 *)(lVar18 + 0x9cecc) = 0;
          *(undefined4 *)(lVar18 + 0x9ced8) = 0;
          *(undefined4 *)(lVar18 + 0x9cee4) = 0;
          *(undefined4 *)(lVar18 + 0x9cef0) = 0;
          *(undefined4 *)(lVar18 + 0x9cefc) = 0;
          *(undefined4 *)(lVar18 + 0x9cf08) = 0;
          *(undefined4 *)(lVar18 + 0x9cf14) = 0;
          *(undefined4 *)(lVar18 + 0x9cf20) = 0;
        }
        lVar18 = param_1 + (long)iVar4 * 51000 + (long)param_3 * 1000;
        uVar8 = 0x3a80;
      }
      *(undefined8 *)(lVar18 + (ulong)(uVar8 | 0x80000)) = 0x100000000;
      goto LAB_005c6c1c;
    }
    plVar11 = (long *)func_0x00a61528(uVar20 & 0xffffffff,param_3);
    if (0 < (int)plVar11) goto LAB_005c6c1c;
    iVar5 = func_0x0043ea60(100);
    iVar6 = func_0x00a6006c(uVar20 & 0xffffffff,param_3);
    if (iVar6 <= iVar5) goto LAB_005c64c8;
    uVar7 = func_0x00a600f8(uVar20 & 0xffffffff,param_3);
    func_0x00a61568(uVar20 & 0xffffffff,param_3,uVar7);
    if (*(long *)(lVar1 + 0x28) == lStack_68) {
      plVar11 = (long *)func_0x007fd748();
      *(undefined4 *)((long)plVar11 + (long)param_3 * 1000 + (long)iVar4 * 51000 + 0x83bac) = 1;
      return plVar11;
    }
  }
  else {
LAB_005c6c1c:
    if (*(long *)(lVar1 + 0x28) == lStack_68) {
      return plVar11;
    }
  }
LAB_005c6cd8:
  auVar24 = func_0x00bc3380();
SUB_005c6cdc:
  plVar14 = auVar24._0_8_;
  iVar4 = *auVar24._8_8_;
  plVar19 = plVar14 + 1;
  plVar11 = (long *)*plVar19;
  plVar21 = plVar19;
  if ((long *)*plVar19 != (long *)0x0) {
    do {
      while (plVar15 = plVar11, plVar19 = plVar15, iVar4 < (int)plVar15[4]) {
        plVar11 = (long *)*plVar15;
        plVar21 = plVar15;
        if ((long *)*plVar15 == (long *)0x0) goto LAB_005c6d3c;
      }
      if (iVar4 <= (int)plVar15[4]) goto LAB_005c6d90;
      plVar11 = (long *)plVar15[1];
    } while ((long *)plVar15[1] != (long *)0x0);
    plVar21 = plVar15 + 1;
  }
LAB_005c6d3c:
  plVar15 = (long *)func_0x00bc3330(0x40);
  plVar15[6] = 0;
  plVar15[7] = 0;
  plVar15[5] = 0;
  *plVar15 = 0;
  plVar15[1] = 0;
  plVar15[2] = (long)plVar19;
  *plVar21 = (long)plVar15;
  plVar19 = (long *)*plVar14;
  *(int *)(plVar15 + 4) = iVar4;
  plVar11 = plVar15;
  if (*plVar19 != 0) {
    *plVar14 = *plVar19;
    plVar11 = (long *)*plVar21;
  }
  func_0x0040a8c0(plVar14[1],plVar11);
  plVar14[2] = plVar14[2] + 1;
LAB_005c6d90:
  return plVar15 + 5;
}


