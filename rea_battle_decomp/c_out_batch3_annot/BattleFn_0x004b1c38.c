// ELF VMA: 0x004b1c38 | Ghidra Addr: 0x005b1c38 | BodySize: 144

void BattleFn_0x004b1c38(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  int iStack_40;
  undefined4 uStack_3c;
  long lStack_38;
  
  lVar1 = tpidr_el0;
  lStack_38 = *(long *)(lVar1 + 0x28);
  if (param_2 < 0) {
    iStack_40 = 0;
  }
  else {
    iVar2 = BattleFn_0x004b1cc8(param_1);
    iStack_40 = param_2;
    if (iVar2 < param_2) {
      iStack_40 = BattleFn_0x004b1cc8(param_1);
    }
  }
  func_0x005b2884(&iStack_40);
  *(ulong *)(param_1 + 4) = CONCAT44(uStack_3c,iStack_40);
  if (*(long *)(lVar1 + 0x28) != lStack_38) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return;
}


