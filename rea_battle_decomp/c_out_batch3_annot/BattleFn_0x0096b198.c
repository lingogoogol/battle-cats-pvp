// ELF VMA: 0x0096b198 | Ghidra Addr: 0x00a6b198 | BodySize: 92

undefined4 BattleFn_0x0096b198(int param_1,int param_2)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = func_0x007fd748();
  uVar3 = func_0x005b1be4(lVar2 + (long)param_1 * 0x1f0 + 0x2648);
  if ((uVar3 & 1) == 0) {
    lVar2 = func_0x007fd748();
    uVar1 = *(undefined4 *)((long)__DT_JMPREL + lVar2 + (long)param_2 * 0x1c4 + 0x76c0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


