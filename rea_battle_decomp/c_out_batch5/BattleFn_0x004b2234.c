// ELF VMA: 0x4b2234
// Ghidra Addr: 0x005b2234 (ImageBase=0x100000)
// Size: 112 bytes


void BattleFn_0x004b2234(long param_1,ulong param_2,undefined4 param_3,uint param_4)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  
  bVar2 = *(byte *)(param_1 + 0x3d);
  bVar3 = *(byte *)(param_1 + 0x3e);
  bVar4 = *(byte *)(param_1 + 0x3f);
  bVar6 = (byte)((uint)param_3 >> 8);
  lVar1 = param_1 + (-(param_2 >> 0x1f & 1) & 0xfffffffc00000000 | (param_2 & 0xffffffff) << 2);
  *(byte *)(lVar1 + 0x14) = *(byte *)(param_1 + 0x3c) ^ (byte)param_3;
  bVar7 = (byte)((uint)param_3 >> 0x10);
  *(byte *)(lVar1 + 0x15) = bVar2 ^ bVar6;
  bVar2 = (byte)((uint)param_3 >> 0x18);
  *(byte *)(lVar1 + 0x16) = bVar3 ^ bVar7;
  *(byte *)(lVar1 + 0x17) = bVar4 ^ bVar2;
  if ((param_4 & 1) != 0) {
    bVar3 = *(byte *)(param_1 + 0x69);
    bVar4 = *(byte *)(param_1 + 0x6a);
    bVar5 = *(byte *)(param_1 + 0x6b);
    *(byte *)(lVar1 + 0x40) = *(byte *)(param_1 + 0x68) ^ (byte)param_3;
    *(byte *)(lVar1 + 0x41) = bVar3 ^ bVar6;
    *(byte *)(lVar1 + 0x42) = bVar4 ^ bVar7;
    *(byte *)(lVar1 + 0x43) = bVar5 ^ bVar2;
  }
  return;
}


