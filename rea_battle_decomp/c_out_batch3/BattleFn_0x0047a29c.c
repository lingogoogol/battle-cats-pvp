// ELF VMA: 0x0047a29c | Ghidra Addr: 0x0057a29c | BodySize: 264

int BattleFn_0x0047a29c(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  
  iVar2 = func_0x0057a024(1);
  lVar5 = func_0x007fd748();
  iVar3 = BattleFn_0x0091f9dc(&UNK_00290568 + lVar5,0x11);
  lVar5 = func_0x007fd748();
  if (*(int *)(&UNK_00327f0c + lVar5) < 3) {
    lVar5 = func_0x007fd748();
    iVar6 = *(int *)(&UNK_00327f0c + lVar5) * 0x1c2;
  }
  else {
    iVar6 = 0x546;
  }
  uVar1 = iVar2 * 0x32 - iVar3;
  iVar2 = func_0x0057a024(3);
  lVar5 = func_0x007fd748();
  iVar3 = BattleFn_0x0091f9dc(&UNK_00290568 + lVar5,1);
  lVar5 = func_0x007fd748();
  iVar4 = BattleFn_0x007700d4(lVar5 + 0x4407e8,7,0xffffffff);
  iVar2 = (int)(((((uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU)) + iVar6 + iVar2 * -0x32) - iVar3) +
                0x5dc) * (100 - iVar4)) / 100;
  if (iVar2 < 0x3b7) {
    iVar2 = 0x3b6;
  }
  return iVar2;
}


