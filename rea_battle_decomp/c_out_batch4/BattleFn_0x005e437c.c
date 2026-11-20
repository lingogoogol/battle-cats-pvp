// ELF VMA: 0x5e437c
// Ghidra Addr: 0x006e437c (ImageBase=0x100000)
// Size: 160 bytes


ulong BattleFn_0x005e437c(uint param_1)

{
  byte *pbVar1;
  long lVar2;
  ulong uVar3;
  undefined *puVar4;
  
  func_0x007fd748();
  uVar3 = 0;
  puVar4 = &UNK_0038aa57;
  do {
    lVar2 = func_0x007fd748();
    pbVar1 = puVar4 + lVar2;
    if (((uint)(pbVar1[-2] ^ pbVar1[-5]) << 0x10 | (uint)(pbVar1[-3] ^ pbVar1[-4]) << 0x18 |
         (uint)(pbVar1[-1] ^ pbVar1[-6]) << 8 | (uint)(*pbVar1 ^ pbVar1[-7])) == param_1)
    goto LAB_006e4408;
    uVar3 = uVar3 + 1;
    func_0x007fd748();
    puVar4 = puVar4 + 0x40;
  } while (uVar3 != 0x113);
  uVar3 = 0xffffffff;
LAB_006e4408:
  return uVar3 & 0xffffffff;
}


