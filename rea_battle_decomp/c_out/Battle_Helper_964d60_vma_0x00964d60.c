// ELF VMA: 0x964d60
// Ghidra Addr: 0x00a64d60 (ImageBase=0x100000)
// Function: Battle_Helper_964d60
// Size: 200 bytes
// Callees (0): 


int Battle_Helper_964d60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = func_0x007fd748();
  uVar4 = func_0x005b1be4(lVar3 + (long)param_1 * 0x1f0 + 0x2648);
  lVar3 = func_0x007fd748();
  if ((uVar4 & 1) == 0) {
    iVar1 = *(int *)((long)__DT_JMPREL + lVar3 + ((long)param_2 + 2) * 0x1c4 + 0x7188);
  }
  else {
    iVar1 = *(int *)(lVar3 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 + 0x9e588);
    iVar2 = func_0x00a63984(param_1,param_2,param_3,0x3d,0);
    iVar1 = ((100 - iVar2) * iVar1) / 100;
  }
  return iVar1;
}


