// ELF VMA: 0x004bd678 | Ghidra Addr: 0x005bd678 | BodySize: 1320

void BattleFn_0x004bd678(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  lVar7 = 0;
  lVar1 = param_1 + 0x83a78;
  bVar4 = true;
  do {
    bVar3 = bVar4;
    uVar8 = 0;
    lVar9 = lVar7 * 51000;
    do {
      func_0x00a607d0(lVar7,uVar8 & 0xffffffff,0);
      iVar5 = func_0x00a61528(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a615b4(lVar7,uVar8 & 0xffffffff,0xffffffff);
        func_0x006ce4cc(param_1,lVar7,uVar8 & 0xffffffff,5);
        iVar5 = func_0x00a61528(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a61648(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a61ae0(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a61b6c(lVar7,uVar8 & 0xffffffff,0xffffffff);
        func_0x006ce4cc(param_1,lVar7,uVar8 & 0xffffffff,5);
        iVar5 = func_0x00a61ae0(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a61648(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a61c54(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a61ce0(lVar7,uVar8 & 0xffffffff,0xffffffff);
        func_0x006ce4cc(param_1,lVar7,uVar8 & 0xffffffff,5);
        iVar5 = func_0x00a61c54(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a61648(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a608a8(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a60934(lVar7,uVar8 & 0xffffffff,0xffffffff);
        iVar5 = func_0x00a608a8(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a609c8(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a60aa0(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a60b2c(lVar7,uVar8 & 0xffffffff,0xffffffff);
        iVar5 = func_0x00a60aa0(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a60bc0(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a608a8(lVar7,uVar8 & 0xffffffff);
      if ((iVar5 == 0) && (iVar5 = func_0x00a60aa0(lVar7,uVar8 & 0xffffffff), iVar5 == 0)) {
        func_0x006d477c(param_1,lVar7,uVar8 & 0xffffffff,1);
      }
      iVar5 = func_0x00a60c98(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a60d24(lVar7,uVar8 & 0xffffffff,0xffffffff);
        iVar5 = func_0x00a60c98(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a60db8(lVar7,uVar8 & 0xffffffff,0);
        }
      }
      iVar5 = func_0x00a5e2c0(lVar7,uVar8 & 0xffffffff);
      lVar2 = lVar1 + lVar9;
      if (iVar5 < 1) {
        *(undefined4 *)(lVar2 + -0x30) = 0;
      }
      else {
        *(int *)(lVar2 + -0x30) = *(int *)(lVar2 + -0x30) + 1;
        func_0x006ce4cc(param_1,lVar7,uVar8 & 0xffffffff,2);
      }
      iVar6 = func_0x00a60c98(lVar7,uVar8 & 0xffffffff);
      if (iVar6 == 0 && iVar5 == 0) {
        func_0x006d477c(param_1,lVar7,uVar8 & 0xffffffff,2);
      }
      lVar2 = lVar1 + lVar9;
      if (0 < *(int *)(lVar2 + -0x3c)) {
        *(int *)(lVar2 + -0x38) = *(int *)(lVar2 + -0x38) + 1;
        iVar6 = func_0x0044003c(param_2 + 0x1de8);
        iVar5 = *(int *)(lVar2 + -0x38);
        if (iVar6 == -1) {
          iVar6 = func_0x004400b4(param_2 + 0x1de8);
        }
        else {
          iVar6 = func_0x0044003c(param_2 + 0x1de8);
        }
        if (iVar6 <= iVar5) {
          func_0x006d477c(param_1,lVar7,uVar8 & 0xffffffff,3);
        }
      }
      if (0 < *(int *)(lVar2 + 4)) {
        *(int *)(lVar1 + lVar9) = *(int *)(lVar1 + lVar9) + 1;
        iVar6 = func_0x0044003c(param_2 + 0x1de8);
        iVar5 = *(int *)(lVar1 + lVar9);
        if (iVar6 == -1) {
          iVar6 = func_0x004400b4(param_2 + 0x1988);
        }
        else {
          iVar6 = func_0x0044003c(param_2 + 0x1988);
        }
        if (iVar6 <= iVar5) {
          *(undefined8 *)(lVar1 + lVar9) = 0;
        }
      }
      lVar2 = lVar1 + lVar9;
      if (0 < *(int *)(lVar2 + 0xc)) {
        *(int *)(lVar2 + 8) = *(int *)(lVar2 + 8) + 1;
        iVar6 = func_0x0044003c(param_2 + 0x1de8);
        iVar5 = *(int *)(lVar2 + 8);
        if (iVar6 == -1) {
          iVar6 = func_0x004400b4(param_2 + 0x1a68);
        }
        else {
          iVar6 = func_0x0044003c(param_2 + 0x1a68);
        }
        if (iVar6 <= iVar5) {
          *(undefined8 *)(lVar2 + 8) = 0;
        }
      }
      if (0 < *(int *)(lVar2 + 0x28)) {
        lVar2 = lVar1 + lVar9;
        *(int *)(lVar2 + 0x24) = *(int *)(lVar2 + 0x24) + 1;
        iVar6 = func_0x0044003c(param_2 + 0x2168);
        iVar5 = *(int *)(lVar2 + 0x24);
        if (iVar6 == -1) {
          iVar6 = func_0x004400b4(param_2 + 0x2168);
        }
        else {
          iVar6 = func_0x0044003c(param_2 + 0x2168);
        }
        if (iVar6 <= iVar5) {
          *(undefined4 *)(lVar2 + 0x24) = 0;
          *(undefined4 *)(lVar2 + 0x28) = 0;
        }
      }
      iVar5 = func_0x00a61608(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a61694(lVar7,uVar8 & 0xffffffff,1);
      }
      if (*(int *)(lVar1 + lVar9 + -0x74) == 1) {
        *(undefined4 *)(lVar1 + lVar9 + -0x74) = 0;
      }
      iVar5 = func_0x00a5b2b4(lVar7,uVar8 & 0xffffffff);
      if (0 < iVar5) {
        func_0x00a60fcc(lVar7,uVar8 & 0xffffffff,0xffffffff);
        iVar5 = func_0x00a5b2b4(lVar7,uVar8 & 0xffffffff);
        if (iVar5 == 0) {
          func_0x00a61020(lVar7,uVar8 & 0xffffffff,0);
          func_0x006d477c(param_1,lVar7,uVar8 & 0xffffffff,4);
        }
      }
      uVar8 = uVar8 + 1;
      lVar9 = lVar9 + 1000;
    } while (uVar8 != 0x33);
    lVar7 = 1;
    bVar4 = false;
  } while (bVar3);
  return;
}


