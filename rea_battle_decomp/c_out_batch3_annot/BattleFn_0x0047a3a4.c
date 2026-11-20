// ELF VMA: 0x0047a3a4 | Ghidra Addr: 0x0057a3a4 | BodySize: 92

uint BattleFn_0x0047a3a4(int param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = func_0x007fd748();
  iVar2 = BattleFn_0x007700d4(lVar3 + 0x4407e8,3,0xffffffff);
  uVar1 = ((100 - iVar2) * param_1) / 100;
  return uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU);
}


