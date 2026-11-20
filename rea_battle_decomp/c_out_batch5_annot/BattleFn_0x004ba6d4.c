// ELF VMA: 0x4ba6d4
// Ghidra Addr: 0x005ba6d4 (ImageBase=0x100000)
// Size: 280 bytes


void BattleFn_0x004ba6d4(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  byte abStack_70 [17];
  undefined4 uStack_5f;
  undefined1 uStack_5b;
  undefined2 uStack_5a;
  long lStack_58;
  
  lVar5 = tpidr_el0;
  lStack_58 = *(long *)(lVar5 + 0x28);
  uVar1 = *(undefined4 *)(param_1 + 0x341c);
  iVar2 = *(int *)(param_1 + 0x3484);
  abStack_70[0] = 0x28;
  uStack_5f = 0x795f656c;  /* ascii(0x795f656c)='le_y' */
  *(undefined4 *)(param_1 + 0x341c) = 10000;
  abStack_70[9] = 0x6f;
  abStack_70[10] = 0x6f;
  abStack_70[0xb] = 0x6d;
  abStack_70[0xc] = 0x5f;
  abStack_70[0xd] = 99;
  abStack_70[0xe] = 0x61;
  abStack_70[0xf] = 0x73;
  abStack_70[0x10] = 0x74;
  abStack_70[1] = 0x62;
  abStack_70[2] = 0x61;
  abStack_70[3] = 0x74;
  abStack_70[4] = 0x74;
  abStack_70[5] = 0x6c;
  abStack_70[6] = 0x65;
  abStack_70[7] = 0x5f;
  abStack_70[8] = 0x7a;
  uStack_5b = 0;
  iVar6 = func_0x008e3f14(param_1 + 0x1478,abStack_70,0);
  if (*(char *)(param_1 + 0x13dd) == '\0') {
    iVar7 = 0;
  }
  else {
    iVar7 = func_0x005b8008(param_1);
  }
  iVar3 = *(int *)(param_1 + 0x3484);
  iVar4 = *(int *)(&UNK_00327f80 + param_1);  /* field_off=0x327f80 */
  if ((abStack_70[0] & 1) != 0) {
    func_0x00bc3350(CONCAT26(uStack_5a,CONCAT15(uStack_5b,CONCAT41(uStack_5f,abStack_70[0x10]))));
  }
  *(undefined4 *)(param_1 + 0x341c) = uVar1;
  iVar7 = (iVar7 - iVar3) + iVar4 + 0x8a;
  iVar3 = 0;
  if (iVar7 != 0) {
    iVar3 = ((iVar6 - iVar2) * 10000 + 0x11da50) / iVar7;
  }
  if (9999 < iVar3) {
    iVar3 = 10000;
  }
  if (*(long *)(lVar5 + 0x28) == lStack_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380(iVar3);
}


