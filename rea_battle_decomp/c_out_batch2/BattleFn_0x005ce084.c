// ELF VMA: 0x5ce084
// Ghidra Addr: 0x006ce084 (ImageBase=0x100000)
// Size: 1096 bytes


/* WARNING: Type propagation algorithm not settling */

undefined8 BattleFn_0x005ce084(ulong param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  
  bVar1 = param_2 == 0;
  uVar7 = param_1;
  if ((param_4 == 0 && param_2 == 0) && (uVar7 = func_0x005aacc8(), (uVar7 & 1) != 0)) {
    iVar2 = func_0x00a5a220(1,0);
    uVar7 = 0;
    if (0 < iVar2) {
      return 0;
    }
  }
  if ((((param_4 == 0) || ((param_2 == 0 && (iVar2 = func_0x005aad10(uVar7), iVar2 == param_4)))) &&
      (iVar2 = func_0x00a58ba4(param_2,param_3), iVar2 != 2)) &&
     (uVar7 = func_0x00a5c8d4(param_2,param_3,0), (uVar7 & 1) != 0)) {
    lVar8 = param_1 + (long)param_3 * 1000;
    if (param_2 != 0) {
      iVar2 = *(int *)(lVar8 + 0x9004c);
      iVar3 = func_0x00a5ca20(param_2,param_3,0);
      uVar7 = func_0x00a58df4(0,param_4,param_3);
      if ((uVar7 & 1) == 0) {
        return 0;
      }
      if (*(int *)(param_1 + (long)param_4 * 1000 + 0x83914) <= iVar3 + iVar2) {
        return 1;
      }
      return 0;
    }
    iVar2 = *(int *)(lVar8 + 0x83914);
    iVar3 = func_0x00a5ca20(0,param_3,0);
    uVar7 = func_0x00a58df4(1,param_4,param_3);
    if ((uVar7 & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_1 + (long)param_4 * 1000 + 0x9004c) < iVar2 - iVar3) {
      return 0;
    }
    return 1;
  }
  iVar2 = func_0x00a58ba4(param_2,param_3);
  if ((iVar2 != 2) || (uVar7 = func_0x00a5c8d4(param_2,param_3,param_5), (uVar7 & 1) == 0)) {
    lVar8 = param_1 + (long)param_3 * 1000;
    if (param_2 == 0) {
      iVar2 = *(int *)(lVar8 + 0x83914);
      iVar3 = iVar2 - *(int *)(lVar8 + 0x8393c);
    }
    else {
      iVar3 = *(int *)(lVar8 + 0x9004c);
      iVar2 = *(int *)(lVar8 + 0x90074) + iVar3;
    }
    iVar4 = func_0x00a58874(bVar1,param_4);
    if (iVar4 == 0) {
      return 0;
    }
    uVar7 = func_0x00a58df4(bVar1,param_4,param_3);
    if ((uVar7 & 1) == 0) {
      return 0;
    }
    lVar8 = param_1 + (long)param_4 * 1000;
    if (param_2 == 0) {
      uVar9 = CONCAT44(*(int *)(lVar8 + 0x9004c) -
                       (int)((ulong)*(undefined8 *)(lVar8 + 0x90078) >> 0x20),
                       *(int *)(lVar8 + 0x9004c) - (int)*(undefined8 *)(lVar8 + 0x90078));
    }
    else {
      uVar9 = NEON_rev64(CONCAT44((int)((ulong)*(undefined8 *)(lVar8 + 0x83940) >> 0x20) +
                                  *(int *)(lVar8 + 0x83914),
                                  (int)*(undefined8 *)(lVar8 + 0x83940) + *(int *)(lVar8 + 0x83914))
                         ,4);
    }
    if ((int)uVar9 < iVar3) {
      return 0;
    }
    if (iVar2 < (int)((ulong)uVar9 >> 0x20)) {
      return 0;
    }
    return 1;
  }
  iVar2 = func_0x00a58874(bVar1,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    iVar3 = func_0x00a5cb8c(0,param_3,param_5);
    lVar8 = param_1 + (long)param_3 * 1000;
    iVar2 = *(int *)(lVar8 + 0x83914);
    iVar4 = func_0x00a5ca20(0,param_3,param_5);
    if (iVar3 < 1) {
      iVar5 = func_0x00a5cb8c(0,param_3,param_5);
      iVar3 = *(int *)(lVar8 + 0x83914);
      iVar2 = iVar2 - (iVar4 + iVar5);
      iVar4 = func_0x00a5ca20(0,param_3,param_5);
      iVar3 = iVar3 - iVar4;
    }
    else {
      iVar3 = *(int *)(lVar8 + 0x83914);
      iVar2 = iVar2 - iVar4;
      iVar4 = func_0x00a5ca20(0,param_3,param_5);
      iVar5 = func_0x00a5cb8c(0,param_3,param_5);
      iVar3 = iVar3 - (iVar4 + iVar5);
    }
  }
  else {
    iVar4 = func_0x00a5cb8c(param_2,param_3,param_5);
    lVar8 = param_1 + (long)param_3 * 1000;
    iVar3 = *(int *)(lVar8 + 0x9004c);
    iVar2 = func_0x00a5ca20(param_2,param_3,param_5);
    iVar2 = iVar2 + iVar3;
    if (iVar4 < 1) {
      iVar3 = func_0x00a5cb8c(param_2,param_3,param_5);
      iVar4 = *(int *)(lVar8 + 0x9004c);
      iVar2 = iVar2 + iVar3;
      iVar3 = func_0x00a5ca20(param_2,param_3,param_5);
      iVar3 = iVar3 + iVar4;
    }
    else {
      iVar3 = *(int *)(lVar8 + 0x9004c);
      iVar4 = func_0x00a5ca20(param_2,param_3,param_5);
      iVar5 = func_0x00a5cb8c(param_2,param_3,param_5);
      iVar3 = iVar4 + iVar5 + iVar3;
    }
  }
  uVar7 = func_0x00a58df4(bVar1,param_4,param_3);
  if ((uVar7 & 1) == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + (ulong)(param_2 == 0) * 51000 + (long)param_4 * 1000 + 0x83914);
  if (param_4 == 0) {
    if (param_2 != 0) goto joined_r0x006ce4c4;
  }
  else {
    iVar5 = iVar3;
    if ((param_2 != 0) ||
       (iVar6 = func_0x005aad10(), iVar5 = iVar2, iVar2 = iVar3, iVar6 != param_4)) {
      iVar3 = iVar5;
      if (iVar4 < iVar2) {
        return 0;
      }
joined_r0x006ce4c4:
      if (iVar3 < iVar4) {
        return 0;
      }
      return 1;
    }
  }
  if (iVar4 < iVar3) {
    return 0;
  }
  return 1;
}


