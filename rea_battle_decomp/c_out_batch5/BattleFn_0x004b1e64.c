// ELF VMA: 0x4b1e64
// Ghidra Addr: 0x005b1e64 (ImageBase=0x100000)
// Size: 204 bytes


void BattleFn_0x004b1e64(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iStack_40;
  undefined4 uStack_3c;
  long lStack_38;
  
  lVar2 = tpidr_el0;
  lStack_38 = *(long *)(lVar2 + 0x28);
  iVar1 = (uint)(*(byte *)(param_1 + 0xb) ^ *(byte *)(param_1 + 4)) + param_2 +
          (uint)(*(byte *)(param_1 + 10) ^ *(byte *)(param_1 + 5)) * 0x100 +
          (uint)(*(byte *)(param_1 + 9) ^ *(byte *)(param_1 + 6)) * 0x10000 +
          (uint)(*(byte *)(param_1 + 8) ^ *(byte *)(param_1 + 7)) * 0x1000000;
  if (iVar1 < 0) {
    iStack_40 = 0;
  }
  else {
    iVar3 = func_0x005b1cc8(param_1);
    iStack_40 = iVar1;
    if (iVar3 < iVar1) {
      iStack_40 = func_0x005b1cc8(param_1);
    }
  }
  func_0x005b2884(&iStack_40);
  *(ulong *)(param_1 + 4) = CONCAT44(uStack_3c,iStack_40);
  if (*(long *)(lVar2 + 0x28) != lStack_38) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return;
}


