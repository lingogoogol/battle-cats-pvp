// ELF VMA: 0x4c5e0c
// Ghidra Addr: 0x005c5e0c (ImageBase=0x100000)
// Size: 1332 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004c5e0c(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  int *piVar13;
  long lVar14;
  int iStack_70;
  int iStack_6c;
  
  iVar1 = 1 - param_2;
  iVar2 = func_0x00a57c8c(param_2);
  if ((iVar2 == 0) || (iVar2 = func_0x00a57c8c(param_2), iVar2 == 5)) {
    iVar2 = func_0x00a57c8c(param_2);
    if (iVar2 == 0) {
      iStack_70 = 4;
      iStack_6c = 8;
    }
    else {
      iVar2 = func_0x00a57c8c(param_2);
      if (iVar2 == 5) {
        iVar2 = func_0x0044003c(param_1 + 0x2d40);
        iStack_6c = iVar2 + -4;
        iStack_70 = iVar2 + -8;
      }
    }
    lVar14 = 0;
    do {
      lVar11 = param_1 + (long)param_2 * 0xb4 + lVar14 * 0xc;
      iVar2 = *(int *)(lVar11 + 0x9ce78);
      if ((0 < iVar2) &&
         (*(int *)(lVar11 + 0x9ce78) = iVar2 + -1, iStack_70 < iVar2 && iVar2 + -1 <= iStack_6c)) {
        uVar12 = 1;
        lVar11 = param_1 + (long)param_2 * 0xb4 + lVar14 * 0xc;
        piVar13 = (int *)(param_1 + (long)param_2 * -51000 + 0x90460);
        do {
          iVar2 = func_0x00a58874(iVar1,uVar12 & 0xffffffff);
          if (iVar2 == 2) {
            if (param_2 == 1) {
              if (piVar13[-0xb] - *piVar13 <= *(int *)(lVar11 + 0x9ce7c)) goto LAB_005c60bc;
            }
            else if (((param_2 == 0) &&
                     (uVar10 = func_0x005aad10(), uVar12 != (uVar10 & 0xffffffff))) &&
                    (*(int *)(lVar11 + 0x9ce7c) <= piVar13[-0xb] - *piVar13)) {
LAB_005c60bc:
              iVar2 = func_0x00a57c8c(param_2);
              if (((iVar2 != 5) ||
                  (uVar10 = func_0x00a5b960(iVar1,uVar12 & 0xffffffff), (uVar10 & 1) != 0)) ||
                 (iVar2 = func_0x00a58398(param_2), iVar2 != 0)) {
                BattleFn_0x004c6340(param_1,param_2,uVar12 & 0xffffffff,
                                    *(undefined4 *)(lVar11 + 0x9ce80));
              }
            }
          }
          uVar12 = uVar12 + 1;
          piVar13 = piVar13 + 0xfa;
        } while (uVar12 != 0x33);
      }
      lVar14 = lVar14 + 1;
    } while (lVar14 != 0xf);
  }
  else {
    iVar2 = func_0x00a578c8(param_2);
    if ((iVar2 == 3) || (iVar2 = func_0x00a578c8(param_2), iVar2 == 0xc)) {
      iVar3 = func_0x005aecec(param_2);
      iVar4 = func_0x00a57834(param_2);
      iVar2 = _DAT_00c0b310;
      iVar5 = func_0x00a57934(param_2);
      iVar4 = iVar4 * iVar2 * iVar5 * 10;
      iVar2 = iVar4 + 0x1f;
      if (-1 < iVar4) {
        iVar2 = iVar4;
      }
      iVar4 = -(iVar2 >> 5);
      if (param_2 != 0) {
        iVar4 = iVar2 >> 5;
      }
      iVar2 = 1;
      do {
        iVar5 = func_0x00a58874(iVar1,iVar2);
        if ((iVar5 == 2) && ((param_2 != 0 || (iVar5 = func_0x005aad10(), iVar2 != iVar5)))) {
          iVar5 = func_0x00a5919c(iVar1,iVar2);
          iVar6 = func_0x00a5a6b4(iVar1,iVar2);
          if (iVar4 + iVar3 <= iVar5 - iVar6) {
            uVar7 = func_0x00a57ab8(param_2);
            BattleFn_0x004c6340(param_1,param_2,iVar2,uVar7);
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x33);
    }
    else {
      iVar2 = func_0x00a578c8(param_2);
      if ((((iVar2 == 5) && (iVar2 = func_0x00a57934(param_2), 4 < iVar2)) &&
          (iVar2 = func_0x00a57934(param_2), iVar2 < 0x10)) ||
         (((iVar2 = func_0x00a578c8(param_2), iVar2 == 0xb &&
           (iVar2 = func_0x00a57934(param_2), 9 < iVar2)) &&
          (iVar2 = func_0x00a57934(param_2), iVar2 < 0x15)))) {
        iVar2 = 1;
        do {
          iVar4 = func_0x00a58874(iVar1,iVar2);
          if ((iVar4 == 2) && ((param_2 != 0 || (iVar4 = func_0x005aad10(), iVar2 != iVar4)))) {
            iVar3 = func_0x00a5919c(iVar1,iVar2);
            iVar5 = func_0x00a5a6b4(iVar1,iVar2);
            iVar6 = func_0x00a578c8(param_2);
            iVar8 = func_0x00a57cf8(param_2);
            iVar4 = func_0x00a57e3c(0);
            if (iVar6 == 0xb) {
              iVar4 = (int)((ulong)((long)(iVar4 << 3) * -0x66666667) >> 0x20);
              iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
            }
            else {
              if (iVar4 < 0) {
                iVar4 = iVar4 + 1;
              }
              iVar4 = -(iVar4 >> 1);
            }
            iVar6 = func_0x00a57e3c(0);
            if ((iVar4 + iVar8 <= iVar3 - iVar5) && (iVar3 - iVar5 < iVar6 + iVar4 + iVar8)) {
              uVar7 = func_0x00a57ab8(param_2);
              BattleFn_0x004c6340(param_1,param_2,iVar2,uVar7);
            }
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x33);
      }
      else {
        iVar2 = func_0x00a578c8(param_2);
        if ((iVar2 == 8) && (iVar2 = func_0x00a57934(param_2), 4 < iVar2)) {
          iVar2 = 1;
          do {
            iVar4 = func_0x00a58874(iVar1,iVar2);
            if ((iVar4 == 2) && ((param_2 != 0 || (iVar4 = func_0x005aad10(), iVar2 != iVar4)))) {
              iVar3 = func_0x00a5919c(iVar1,iVar2);
              iVar5 = func_0x00a5a6b4(iVar1,iVar2);
              iVar6 = func_0x00a57cf8(param_2);
              iVar4 = func_0x00a57e3c(0);
              if (iVar4 < 0) {
                iVar4 = iVar4 + 1;
              }
              iVar9 = func_0x00a57cf8(param_2);
              iVar8 = func_0x00a57e3c(0);
              if (iVar6 - (iVar4 >> 1) <= iVar3 - iVar5) {
                if (iVar8 < 0) {
                  iVar8 = iVar8 + 1;
                }
                if (iVar3 - iVar5 < iVar9 + (iVar8 >> 1)) {
                  uVar7 = func_0x00a57ab8(param_2);
                  BattleFn_0x004c6340(param_1,param_2,iVar2,uVar7);
                }
              }
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 != 0x33);
        }
      }
    }
  }
  return;
}


