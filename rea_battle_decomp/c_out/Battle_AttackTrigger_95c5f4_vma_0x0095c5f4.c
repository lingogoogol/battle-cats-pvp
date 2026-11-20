// ELF VMA: 0x95c5f4
// Ghidra Addr: 0x00a5c5f4 (ImageBase=0x100000)
// Function: Battle_AttackTrigger_95c5f4
// Size: 112 bytes
// Callees (0): 


bool Battle_AttackTrigger_95c5f4(int param_1,int param_2)

{
  bool bVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = func_0x007fd748();
  uVar3 = func_0x005b1be4(lVar2 + (long)param_1 * 0x1f0 + 0x2648);
  if ((uVar3 & 1) == 0) {
    bVar1 = false;
  }
  else {
    lVar2 = func_0x007fd748();
    bVar1 = *(int *)(lVar2 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x839ec) != 0;
  }
  return bVar1;
}


