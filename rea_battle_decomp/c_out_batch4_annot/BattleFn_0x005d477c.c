// ELF VMA: 0x5d477c
// Ghidra Addr: 0x006d477c (ImageBase=0x100000)
// Size: 372 bytes


/* WARNING: Possible PIC construction at 0x006d47c0: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006d47ec: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006d4818: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006d4844: Changing call to branch */

void BattleFn_0x005d477c(undefined8 param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  uint uVar5;
  long lVar6;
  int iVar7;
  ulong unaff_x19;
  ulong uVar8;
  ulong unaff_x20;
  ulong uVar9;
  ulong unaff_x21;
  ulong uVar10;
  undefined8 unaff_x22;
  undefined1 *unaff_x29;
  undefined8 unaff_x30;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar1 = &stack0xffffffffffffffd0;
  puVar2 = &stack0xffffffffffffffd0;
  puVar3 = &stack0xffffffffffffffd0;
  puVar4 = &stack0xffffffffffffffd0;
  uVar8 = (ulong)param_3;
  uVar9 = (ulong)param_2;
  uVar10 = (ulong)param_4;
  uVar5 = func_0x00a613d8(param_2,param_3,0);  /* 0x9613d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
  if (uVar5 == param_4) {
    iVar7 = 0;
    unaff_x30 = 0x6d47c4;
    register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffd0;
    unaff_x19 = uVar8;
    unaff_x20 = uVar9;
    unaff_x21 = uVar10;
    unaff_x29 = puVar1;
  }
  else {
    uVar5 = func_0x00a613d8(uVar9,uVar8,1);  /* 0x9613d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
    if (uVar5 == param_4) {
      iVar7 = 1;
      unaff_x30 = 0x6d47f0;
      register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffd0;
      unaff_x19 = uVar8;
      unaff_x20 = uVar9;
      unaff_x21 = uVar10;
      unaff_x29 = puVar2;
    }
    else {
      uVar5 = func_0x00a613d8(uVar9,uVar8,2);  /* 0x9613d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
      if (uVar5 == param_4) {
        iVar7 = 2;
        unaff_x30 = 0x6d481c;
        register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffd0;
        unaff_x19 = uVar8;
        unaff_x20 = uVar9;
        unaff_x21 = uVar10;
        unaff_x29 = puVar3;
      }
      else {
        uVar5 = func_0x00a613d8(uVar9,uVar8,3);  /* 0x9613d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
        if (uVar5 == param_4) {
          iVar7 = 3;
          unaff_x30 = 0x6d4848;
          register0x00000008 = (BADSPACEBASE *)&stack0xffffffffffffffd0;
          unaff_x19 = uVar8;
          unaff_x20 = uVar9;
          unaff_x21 = uVar10;
          unaff_x29 = puVar4;
        }
        else {
          uVar5 = func_0x00a613d8(uVar9,uVar8,4);  /* 0x9613d8:[slot*1000,team*51000|off=0x83908|ldr w0, [x8, x9]] */
          if (uVar5 != param_4) {
            return;
          }
          iVar7 = 4;
        }
      }
    }
  }
  *(undefined1 **)((long)register0x00000008 + -0x30) = unaff_x29;
  *(undefined8 *)((long)register0x00000008 + -0x28) = unaff_x30;
  *(undefined8 *)((long)register0x00000008 + -0x20) = unaff_x22;
  *(ulong *)((long)register0x00000008 + -0x18) = unaff_x21;
  *(ulong *)((long)register0x00000008 + -0x10) = unaff_x20;
  *(ulong *)((long)register0x00000008 + -8) = unaff_x19;
  lVar6 = func_0x007fd748();
  *(undefined4 *)
   (lVar6 + (long)(int)param_2 * 51000 + (long)(int)param_3 * 1000 +
    (long)*(int *)(&UNK_002ea900 + (long)iVar7 * 4) * 4 + 0x83908) = 0;  /* UNK_2ea900(vma=0x1ea900)='Q' */
  return;
}


