// ELF VMA: 0x005dd3f0 | Ghidra Addr: 0x006dd3f0 | BodySize: 964

/* WARNING: Possible PIC construction at 0x006dd55c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006dd534: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006dd560) */
/* WARNING: Removing unreachable block (ram,0x006dd580) */
/* WARNING: Removing unreachable block (ram,0x006dd5c0) */
/* WARNING: Removing unreachable block (ram,0x006dd538) */

void BattleFn_0x005dd3f0(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong unaff_x19;
  ulong uVar6;
  ulong unaff_x20;
  ulong uVar7;
  undefined8 unaff_x21;
  undefined1 *unaff_x29;
  undefined8 unaff_x30;
  undefined1 *puVar2;
  
  puVar1 = &stack0xffffffffffffffc0;
  puVar2 = &stack0xffffffffffffffc0;
  uVar6 = (ulong)param_4;
  uVar7 = (ulong)param_3;
  iVar3 = func_0x00a58ba4(param_3,param_4);
  if (iVar3 == 10) {
    func_0x009b95b4(param_1,param_2,uVar7,uVar6);
    iVar3 = func_0x00a590bc(uVar7,uVar6);
    if (iVar3 != 0) {
      return;
    }
    iVar3 = 0;
  }
  else {
    iVar3 = func_0x00a58ba4(uVar7,uVar6);
    if (iVar3 == 0x12) {
      func_0x00a59148(uVar7,uVar6,1);
      iVar3 = func_0x00a590bc(uVar7,uVar6);
      if (iVar3 < 0x1e) {
        return;
      }
      iVar3 = 0x13;
    }
    else {
      iVar3 = func_0x00a58ba4(uVar7,uVar6);
      unaff_x19 = uVar6;
      unaff_x20 = uVar7;
      unaff_x21 = param_2;
      if (iVar3 == 0x13) {
        iVar3 = func_0x00a6126c(uVar7,uVar6);
        if (0 < iVar3) {
          func_0x00a612f8(uVar7,uVar6,0xffffffff);
          lVar4 = func_0x007fd748();
          *(undefined4 *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83910)
               = 0;
          return;
        }
        iVar3 = 0x14;
        unaff_x30 = 0x6dd560;
        register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffc0;
        unaff_x29 = puVar1;
      }
      else {
        iVar3 = func_0x00a58ba4(uVar7,uVar6);
        if (iVar3 != 0x14) {
          return;
        }
        func_0x00a59148(uVar7,uVar6,1);
        iVar3 = func_0x00a590bc(uVar7,uVar6);
        if (iVar3 < 0x14) {
          return;
        }
        iVar3 = 0;
        unaff_x30 = 0x6dd538;
        register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffc0;
        unaff_x29 = puVar2;
      }
    }
  }
  *(undefined1 **)((long)register0x00000008 + -0x30) = unaff_x29;
  *(undefined8 *)((long)register0x00000008 + -0x28) = unaff_x30;
  *(undefined8 *)((long)register0x00000008 + -0x20) = unaff_x21;
  *(ulong *)((long)register0x00000008 + -0x10) = unaff_x20;
  *(ulong *)((long)register0x00000008 + -8) = unaff_x19;
  if (iVar3 == 0) {
    lVar4 = func_0x007fd748();
    if (*(int *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83930) == 0) {
      iVar3 = 1;
    }
    else {
      lVar4 = func_0x007fd748();
      uVar6 = func_0x005b1be4(lVar4 + (long)(int)param_3 * 0x1f0 + 0x2648);
      if ((uVar6 & 1) == 0) {
        lVar4 = func_0x007fd748();
        iVar3 = 0xe;
        if (*(int *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83c3c) < 1)
        {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = 0;
      }
    }
  }
  else if (iVar3 == 4) {
    lVar4 = func_0x007fd748();
    if (*(int *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83bf0) != 0) {
      iVar3 = func_0x0043ea60(100);
      lVar4 = func_0x007fd748();
      if (iVar3 < *(int *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83bf0)
         ) {
        uVar5 = func_0x0044c16c();
        func_0x0044e35c(uVar5,0x8f,0);
        iVar3 = 0x15;
        goto LAB_00a58d1c;
      }
    }
    iVar3 = 4;
  }
LAB_00a58d1c:
  lVar4 = func_0x007fd748();
  *(int *)(lVar4 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x8390c) = iVar3;
  return;
}


