// ELF VMA: 0x964cb4
// Ghidra Addr: 0x00a64cb4 (ImageBase=0x100000)
// Size: 172 bytes


undefined4 BattleFn_0x00964cb4(int param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  ulong uVar2;
  undefined4 *puVar3;
  
  lVar1 = func_0x007fd748();
  uVar2 = BattleFn_0x004b1be4(lVar1 + (long)param_1 * 0x1f0 + 0x2648);
  lVar1 = func_0x007fd748();
  if ((uVar2 & 1) == 0) {
    puVar3 = (undefined4 *)
             ((long)__DT_JMPREL +
             lVar1 + ((long)param_2 + 2) * 0x1c4 +
             (long)*(int *)(&UNK_002ea9f0 + (long)param_4 * 4) * 4 + 0x7178);
  }
  else {
    puVar3 = (undefined4 *)
             (lVar1 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 +
              (long)*(int *)(&UNK_002ea9e4 + (long)param_4 * 4) * 4 + 0x9e578);
  }
  return *puVar3;
}


