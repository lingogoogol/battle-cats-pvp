// ELF VMA: 0x959cf4
// Ghidra Addr: 0x00a59cf4 (ImageBase=0x100000)
// Function: Battle_Add_83ad4
// Size: 84 bytes
// Callees (0): 


void Battle_Add_83ad4(int param_1,int param_2,int param_3)

{
  long lVar1;
  
  lVar1 = func_0x007fd748();
  lVar1 = lVar1 + (long)param_1 * 51000 + (long)param_2 * 1000;
  *(int *)(lVar1 + 0x83ad4) = *(int *)(lVar1 + 0x83ad4) + param_3;
  return;
}


