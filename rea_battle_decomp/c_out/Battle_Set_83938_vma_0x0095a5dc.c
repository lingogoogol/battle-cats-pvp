// ELF VMA: 0x95a5dc
// Ghidra Addr: 0x00a5a5dc (ImageBase=0x100000)
// Function: Battle_Set_83938
// Size: 76 bytes
// Callees (0): 


void Battle_Set_83938(int param_1,int param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = func_0x007fd748();
  *(undefined4 *)(lVar1 + (long)param_1 * 51000 + (long)param_2 * 1000 + 0x83938) = param_3;
  return;
}


