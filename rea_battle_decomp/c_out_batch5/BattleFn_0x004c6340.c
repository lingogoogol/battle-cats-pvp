// ELF VMA: 0x4c6340
// Ghidra Addr: 0x005c6340 (ImageBase=0x100000)
// Size: 2484 bytes


void BattleFn_0x004c6340(long param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  long *plVar12;
  long lVar13;
  undefined8 *puVar14;
  undefined *puVar15;
  long lVar16;
  ulong uVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  byte abStack_d0 [16];
  undefined8 uStack_c0;
  undefined4 uStack_b4;
  byte abStack_b0 [16];
  undefined8 uStack_a0;
  byte abStack_98 [16];
  undefined8 uStack_88;
  byte abStack_80 [16];
  undefined8 uStack_70;
  long lStack_68;
  
  lVar13 = tpidr_el0;
  lStack_68 = *(long *)(lVar13 + 0x28);
  uVar17 = 1 - (long)param_2;
  iVar3 = func_0x00a57c8c(param_2);
  if (iVar3 == 5) {
    iVar3 = func_0x00a58ba4(uVar17 & 0xffffffff,param_3);
    bVar1 = iVar3 == 0xc;
  }
  else {
    bVar1 = false;
  }
  uVar9 = func_0x00a584d0(param_2);
  if (((uVar9 & 1) == 0) || (iVar3 = func_0x00a58ba4(uVar17 & 0xffffffff,param_3), iVar3 != 0xe)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 2;
  }
  *(undefined4 *)(param_1 + uVar17 * 51000 + (long)param_3 * 1000 + 0x83a88) = uVar7;
  uVar4 = func_0x00a58fe8(uVar17 & 0xffffffff,param_3,0);
  if ((bVar1 || (uVar4 & 1) != 0) &&
     (iVar3 = func_0x00a5987c(uVar17 & 0xffffffff,param_3), iVar3 < param_4)) {
    uVar9 = func_0x00a5ac18(uVar17 & 0xffffffff,param_3,0);
    iVar3 = (int)uVar17;
    if ((uVar9 & 1) != 0) {
      iVar5 = func_0x00a61528(uVar17 & 0xffffffff,param_3);
      if (0 < iVar5) goto LAB_005c6c1c;
      iVar5 = func_0x0043ea60(100);
      iVar6 = func_0x00a6006c(uVar17 & 0xffffffff,param_3);
      if (iVar5 < iVar6) {
        uVar7 = func_0x00a600f8(uVar17 & 0xffffffff,param_3);
        func_0x00a61568(uVar17 & 0xffffffff,param_3,uVar7);
        if (*(long *)(lVar13 + 0x28) == lStack_68) {
          lVar13 = func_0x007fd748();
          *(undefined4 *)(lVar13 + (long)iVar3 * 51000 + (long)param_3 * 1000 + 0x83bac) = 1;
          return;
        }
        goto LAB_005c6cd8;
      }
    }
    uVar9 = func_0x00a57c18(param_2);
    if (((uVar9 & 1) == 0) ||
       (uVar9 = func_0x00a5f994(uVar17 & 0xffffffff,param_3), (uVar9 & 1) == 0)) {
      uVar7 = func_0x00a57ab8(param_2);
      func_0x00a598bc(uVar17 & 0xffffffff,param_3,uVar7);
      uVar9 = func_0x00a57c18(param_2);
      if (((uVar9 & 1) == 0) ||
         (uVar9 = func_0x00a5f900(uVar17 & 0xffffffff,param_3), (uVar9 & 1) == 0)) {
        plVar12 = (long *)(&UNK_00428c70 + param_1);
        iVar3 = func_0x00a57c8c(param_2);
        if (iVar3 == 4) {
          iVar3 = func_0x00a57f14(param_2);
          if (iVar3 == 0) {
            iVar3 = func_0x00a5a220(uVar17 & 0xffffffff,param_3);
          }
          else {
            iVar3 = func_0x00a57f14(param_2);
            if (iVar3 == 1) {
              iVar3 = func_0x00a5a194(uVar17 & 0xffffffff,param_3);
            }
            else {
              iVar3 = 0;
            }
          }
          iVar5 = func_0x00a57c8c(param_2);
          puVar18 = (undefined8 *)(&UNK_00428c78 + param_1);
          puVar14 = (undefined8 *)*puVar18;
          puVar19 = puVar18;
          if ((undefined8 *)*puVar18 != (undefined8 *)0x0) {
            do {
              while (puVar11 = puVar14, puVar18 = puVar11, iVar5 < *(int *)(puVar11 + 4)) {
                puVar14 = (undefined8 *)*puVar11;
                puVar19 = puVar11;
                if ((undefined8 *)*puVar11 == (undefined8 *)0x0) goto LAB_005c670c;
              }
              if (iVar5 <= *(int *)(puVar11 + 4)) goto LAB_005c6768;
              puVar14 = (undefined8 *)puVar11[1];
            } while ((undefined8 *)puVar11[1] != (undefined8 *)0x0);
            puVar19 = puVar11 + 1;
          }
LAB_005c670c:
          puVar11 = (undefined8 *)func_0x00bc3330(0x40);
          *(int *)(puVar11 + 4) = iVar5;
          puVar11[6] = 0;
          puVar11[7] = 0;
          puVar11[5] = 0;
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = puVar18;
          *puVar19 = puVar11;
          puVar14 = puVar11;
          if (*(long *)*plVar12 != 0) {
            *plVar12 = *(long *)*plVar12;
            puVar14 = (undefined8 *)*puVar19;
          }
          func_0x0040a8c0(*(undefined8 *)(&UNK_00428c78 + param_1),puVar14);
          *(long *)(&UNK_00428c80 + param_1) = *(long *)(&UNK_00428c80 + param_1) + 1;
LAB_005c6768:
          func_0x00bc3540(abStack_80,&UNK_0029e556,puVar11 + 5);
          if ((abStack_80[0] & 1) != 0) {
            func_0x00bc3350(uStack_70);
          }
          func_0x00a589e0(abStack_98,uVar17 & 0xffffffff,param_3);
          if ((abStack_98[0] & 1) != 0) {
            func_0x00bc3350(uStack_88);
          }
          uVar9 = func_0x00a5b644(uVar17 & 0xffffffff,param_3);
          if ((uVar9 & 1) == 0) {
            iVar5 = func_0x00a5832c(param_2);
            iVar3 = (iVar5 * iVar3) / 1000;
            func_0x0043ed6c(iVar3,1);
            func_0x00a5832c(param_2);
          }
          else {
            iVar5 = func_0x00a5816c(param_2);
            iVar3 = (iVar5 * iVar3) / 1000;
            func_0x0043ed6c(iVar3,1);
            func_0x00a5816c(param_2);
          }
LAB_005c6b48:
          if (iVar3 < 2) {
            iVar3 = 1;
          }
          func_0x00a60488(uVar17 & 0xffffffff,param_3,iVar3);
        }
        else {
          iVar3 = func_0x00a57c8c(param_2);
          if (iVar3 == 5) {
            iVar3 = func_0x00a57f14(param_2);
            if (iVar3 == 0) {
              iVar3 = func_0x00a5a220(uVar17 & 0xffffffff,param_3);
            }
            else {
              iVar3 = func_0x00a57f14(param_2);
              if (iVar3 == 1) {
                iVar3 = func_0x00a5a194(uVar17 & 0xffffffff,param_3);
              }
              else {
                iVar3 = 0;
              }
            }
            iVar5 = func_0x00a57c8c(param_2);
            puVar18 = (undefined8 *)(&UNK_00428c78 + param_1);
            puVar14 = (undefined8 *)*puVar18;
            puVar19 = puVar18;
            if ((undefined8 *)*puVar18 != (undefined8 *)0x0) {
              do {
                while (puVar11 = puVar14, puVar18 = puVar11, iVar5 < *(int *)(puVar11 + 4)) {
                  puVar14 = (undefined8 *)*puVar11;
                  puVar19 = puVar11;
                  if ((undefined8 *)*puVar11 == (undefined8 *)0x0) goto LAB_005c69a8;
                }
                if (iVar5 <= *(int *)(puVar11 + 4)) goto LAB_005c6a04;
                puVar14 = (undefined8 *)puVar11[1];
              } while ((undefined8 *)puVar11[1] != (undefined8 *)0x0);
              puVar19 = puVar11 + 1;
            }
LAB_005c69a8:
            puVar11 = (undefined8 *)func_0x00bc3330(0x40);
            *(int *)(puVar11 + 4) = iVar5;
            puVar11[6] = 0;
            puVar11[7] = 0;
            puVar11[5] = 0;
            *puVar11 = 0;
            puVar11[1] = 0;
            puVar11[2] = puVar18;
            *puVar19 = puVar11;
            puVar14 = puVar11;
            if (*(long *)*plVar12 != 0) {
              *plVar12 = *(long *)*plVar12;
              puVar14 = (undefined8 *)*puVar19;
            }
            func_0x0040a8c0(*(undefined8 *)(&UNK_00428c78 + param_1),puVar14);
            *(long *)(&UNK_00428c80 + param_1) = *(long *)(&UNK_00428c80 + param_1) + 1;
LAB_005c6a04:
            func_0x00bc3540(abStack_80,&UNK_0029e556,puVar11 + 5);
            if ((abStack_80[0] & 1) != 0) {
              func_0x00bc3350(uStack_70);
            }
            func_0x00a589e0(abStack_b0,uVar17 & 0xffffffff,param_3);
            if ((abStack_b0[0] & 1) != 0) {
              func_0x00bc3350(uStack_a0);
            }
            uVar9 = func_0x00a5b960(uVar17 & 0xffffffff,param_3);
            if ((uVar9 & 1) == 0) {
              iVar5 = func_0x00a58398(param_2);
              iVar3 = (iVar5 * iVar3) / 1000;
              func_0x0040cb78(abStack_80,&UNK_002b1bd4);
              func_0x0043ed6c(iVar3,1);
              if ((abStack_80[0] & 1) != 0) {
                func_0x00bc3350(uStack_70);
              }
            }
            else {
              iVar5 = func_0x00a58ba4(uVar17 & 0xffffffff,param_3);
              if (((iVar5 == 0xb) ||
                  (iVar5 = func_0x00a58ba4(uVar17 & 0xffffffff,param_3), iVar5 == 0xc)) ||
                 (iVar5 = func_0x00a58ba4(uVar17 & 0xffffffff,param_3), iVar5 == 0xd)) {
                iVar5 = func_0x00a58404(param_2);
                iVar3 = (iVar5 * iVar3) / 1000;
                func_0x0040cb78(abStack_80,&UNK_002a6816);
                func_0x0043ed6c(iVar3,1);
              }
              else {
                iVar5 = func_0x00a581d8(param_2);
                iVar3 = (iVar5 * iVar3) / 1000;
                func_0x0040cb78(abStack_80,&UNK_0028ba5f);
                func_0x0043ed6c(iVar3,1);
              }
              if ((abStack_80[0] & 1) != 0) {
                func_0x00bc3350(uStack_70);
              }
              func_0x00a625c4(uVar17 & 0xffffffff,param_3,1);
            }
            goto LAB_005c6b48;
          }
          iVar3 = func_0x00a57c8c(param_2);
          if (iVar3 == 0) {
            func_0x0040cb78(abStack_80,&UNK_002a04dc);
          }
          else {
            uStack_b4 = func_0x00a57c8c(param_2);
            uVar10 = func_0x005c6cdc(&UNK_00428c70 + param_1,&uStack_b4);
            func_0x00bc3540(abStack_80,&UNK_0029e556,uVar10);
          }
          if ((abStack_80[0] & 1) != 0) {
            func_0x00bc3350(uStack_70);
          }
          func_0x00a589e0(abStack_d0,uVar17 & 0xffffffff,param_3);
          if ((abStack_d0[0] & 1) != 0) {
            func_0x00bc3350(uStack_c0);
          }
          iVar3 = func_0x00a57d64(param_2);
          if ((iVar3 < 1) ||
             (uVar9 = func_0x00a5b644(uVar17 & 0xffffffff,param_3), (uVar9 & 1) == 0)) {
            iVar3 = func_0x00a57d64(param_2);
            iVar5 = func_0x00a57c8c(param_2);
            if (iVar5 == 0) {
              uVar7 = func_0x007ac230();
              plVar12 = (long *)func_0x00633678(param_1 + 0x668,uVar7,9);
              if (plVar12 != (long *)0x0) {
                if ((int *)plVar12[1] == (int *)*plVar12) {
                  if (*(long *)(lVar13 + 0x28) == lStack_68) {
                    /* WARNING: Subroutine does not return */
                    NoRet_0x00370c38();
                  }
                  goto LAB_005c6cd8;
                }
                iVar3 = (*(int *)*plVar12 * iVar3) / 100;
              }
            }
            func_0x00a60488(uVar17 & 0xffffffff,param_3,iVar3);
            puVar15 = &UNK_002b1bd4;
          }
          else {
            func_0x00a60488(uVar17 & 0xffffffff,param_3,1);
            puVar15 = &UNK_0029454c;
          }
          func_0x0040cb78(abStack_80,puVar15);
          if ((abStack_80[0] & 1) != 0) {
            func_0x00bc3350(uStack_70);
          }
        }
        uVar9 = func_0x00a58244(param_2);
        if ((uVar9 & 1) != 0) {
          func_0x00a59950(uVar17 & 0xffffffff,param_3,1);
        }
        iVar3 = func_0x00a5fe34(uVar17 & 0xffffffff,param_3);
        if ((0 < iVar3) && (iVar3 = func_0x00a57c8c(param_2), iVar3 == 6)) {
          func_0x00a60660(uVar17 & 0xffffffff,param_3,2);
        }
        iVar3 = func_0x00a57c8c(param_2);
        uVar4 = func_0x00a58470(param_2);
        uVar8 = func_0x00a58490(param_2);
        bVar2 = func_0x00a584b0(param_2);
        func_0x006d6da0(param_1,param_2,0,param_3,0x19,iVar3 == 6,uVar4 & 1,uVar8 & 1,0,0,bVar2 & 1,
                        0,1);
        goto LAB_005c6c1c;
      }
      lVar16 = param_1 + (long)iVar3 * 51000 + (long)param_3 * 1000;
      uVar4 = 0x3a78;
    }
    else {
      func_0x00a578fc(0,0);
      func_0x00a57968(0,0);
      iVar5 = func_0x00a57c8c(param_2);
      if ((iVar5 == 0) || (iVar5 = func_0x00a57c8c(param_2), iVar5 == 5)) {
        lVar16 = param_1 + (long)param_2 * 0xb4;
        *(undefined4 *)(lVar16 + 0x9ce78) = 0;
        *(undefined4 *)(lVar16 + 0x9ce84) = 0;
        *(undefined4 *)(lVar16 + 0x9ce90) = 0;
        *(undefined4 *)(lVar16 + 0x9ce9c) = 0;
        *(undefined4 *)(lVar16 + 0x9cea8) = 0;
        *(undefined4 *)(lVar16 + 0x9ceb4) = 0;
        *(undefined4 *)(lVar16 + 0x9cec0) = 0;
        *(undefined4 *)(lVar16 + 0x9cecc) = 0;
        *(undefined4 *)(lVar16 + 0x9ced8) = 0;
        *(undefined4 *)(lVar16 + 0x9cee4) = 0;
        *(undefined4 *)(lVar16 + 0x9cef0) = 0;
        *(undefined4 *)(lVar16 + 0x9cefc) = 0;
        *(undefined4 *)(lVar16 + 0x9cf08) = 0;
        *(undefined4 *)(lVar16 + 0x9cf14) = 0;
        *(undefined4 *)(lVar16 + 0x9cf20) = 0;
      }
      lVar16 = param_1 + (long)iVar3 * 51000 + (long)param_3 * 1000;
      uVar4 = 0x3a80;
    }
    *(undefined8 *)(lVar16 + (ulong)(uVar4 | 0x80000)) = 0x100000000;
  }
LAB_005c6c1c:
  if (*(long *)(lVar13 + 0x28) == lStack_68) {
    return;
  }
LAB_005c6cd8:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


