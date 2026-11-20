// ELF VMA: 0x4af784
// Ghidra Addr: 0x005af784 (ImageBase=0x100000)
// Size: 56 bytes


bool BattleFn_0x004af784(int param_1)

{
  long lVar1;
  
  lVar1 = func_0x007fd748();
  return *(int *)(&UNK_00327ec0 + lVar1 + (long)param_1 * 4) != 0;  /* field_off=0x327ec0 */
}


