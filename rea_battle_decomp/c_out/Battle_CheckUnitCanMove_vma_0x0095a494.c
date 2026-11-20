// ELF VMA: 0x95a494
// Ghidra Addr: 0x00a5a494 (ImageBase=0x100000)
// Function: Battle_CheckUnitCanMove
// Size: 172 bytes
// Callees (0): 


undefined4 Battle_CheckUnitCanMove(int param_1,int param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = func_0x007fd748();
  if (*(int *)(lVar1 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x8395c) == 0) {
    uVar2 = 0;
  }
  else {
    lVar1 = func_0x007fd748();
    if (*(int *)(lVar1 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x83aec) == 0) {
      uVar2 = 1;
    }
    else {
      lVar1 = func_0x007fd748();
      uVar2 = 2;
      if (*(int *)(lVar1 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x83af0) != 0) {
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


