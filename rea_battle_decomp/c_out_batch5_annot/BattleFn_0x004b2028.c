// ELF VMA: 0x4b2028
// Ghidra Addr: 0x005b2028 (ImageBase=0x100000)
// Size: 220 bytes


int BattleFn_0x004b2028(long param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  
  iVar9 = func_0x0057a024(4);
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar2 = *(byte *)(param_1 + 0x13);
  bVar3 = *(byte *)(param_1 + 0xd);
  bVar4 = *(byte *)(param_1 + 0x12);
  bVar5 = *(byte *)(param_1 + 0xe);
  bVar6 = *(byte *)(param_1 + 0x11);
  bVar7 = *(byte *)(param_1 + 0xf);
  bVar8 = *(byte *)(param_1 + 0x10);
  lVar12 = func_0x007fd748();
  iVar10 = func_0x00a1f9dc(&UNK_00290568 + lVar12,3);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
  lVar12 = func_0x007fd748();
  iVar11 = func_0x008700d4(&UNK_004407e8 + lVar12,8,0xffffffff);  /* field_off=0x4407e8 */
  return ((((CONCAT13(bVar8 ^ bVar7,CONCAT12(bVar6 ^ bVar5,CONCAT11(bVar4 ^ bVar3,bVar2 ^ bVar1))) +
            10) * (iVar9 * 10 + 0x19)) / 10 + iVar10) * (iVar11 + 100)) / 100;
}


