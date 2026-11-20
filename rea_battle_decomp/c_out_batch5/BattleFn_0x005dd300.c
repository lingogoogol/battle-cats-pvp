// ELF VMA: 0x5dd300
// Ghidra Addr: 0x006dd300 (ImageBase=0x100000)
// Size: 316 bytes


/* WARNING: Possible PIC construction at 0x006dd3ac: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006dd3b0) */
/* WARNING: Removing unreachable block (ram,0x00a5a38c) */

void BattleFn_0x005dd300(undefined8 param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  long lVar3;
  ulong unaff_x19;
  ulong uVar4;
  ulong unaff_x20;
  ulong uVar5;
  undefined8 unaff_x21;
  undefined1 *unaff_x29;
  undefined1 *puVar6;
  undefined8 unaff_x30;
  
  puVar1 = &stack0xffffffffffffffe0;
  puVar6 = &stack0xffffffffffffffe0;
  uVar5 = (ulong)param_2;
  uVar4 = (ulong)param_3;
  iVar2 = func_0x00a5a7ec(param_2,param_3);
  if ((iVar2 == 0) &&
     ((iVar2 = func_0x00a58ba4(uVar5,uVar4), iVar2 != 1 ||
      (iVar2 = func_0x00a58d4c(uVar5,uVar4), iVar2 != 0)))) {
    func_0x00a58be4(uVar5,uVar4,1);
    unaff_x30 = 0x6dd3b0;
  }
  else {
    iVar2 = func_0x00a5a7ec(uVar5,uVar4);
    if (((iVar2 != 2) || (iVar2 = func_0x00a58ba4(uVar5,uVar4), iVar2 == 4)) ||
       (iVar2 = func_0x00a58ba4(uVar5,uVar4), iVar2 == 0x15)) {
      return;
    }
    func_0x00a58be4(uVar5,uVar4,4);
    puVar1 = (undefined1 *)register0x00000008;
    uVar4 = unaff_x19;
    uVar5 = unaff_x20;
    puVar6 = unaff_x29;
  }
  *(undefined1 **)(puVar1 + -0x30) = puVar6;
  *(undefined8 *)(puVar1 + -0x28) = unaff_x30;
  *(undefined8 *)(puVar1 + -0x20) = unaff_x21;
  *(ulong *)(puVar1 + -0x10) = uVar5;
  *(ulong *)(puVar1 + -8) = uVar4;
  lVar3 = func_0x007fd748();
  *(undefined4 *)(lVar3 + (long)(int)param_2 * 51000 + (long)(int)param_3 * 1000 + 0x83910) = 0;
  return;
}


