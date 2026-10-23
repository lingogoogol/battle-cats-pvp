// Target Address: 0x4cecc0
// Function: MyApplication_battle_initWin_0x4cecc0
// Decompiled by Ghidra 12.1.4 Headless

uint MyApplication_battle_initWin_0x4cecc0(void)

{
  byte bVar1;
  undefined1 in_ZR;
  undefined1 in_CY;
  uint in_w8;
  byte *in_x9;
  byte *in_x10;
  long in_x11;
  ulong in_x12;
  ulong in_x13;
  
  while( true ) {
    if ((bool)in_CY && !(bool)in_ZR || in_x13 == 0) {
      return 0;
    }
    in_x10 = in_x10 + 1;
    if (in_x10 == in_x9) break;
    bVar1 = *in_x10;
    in_CY = 0x1f < bVar1;
    in_ZR = bVar1 == 0x20;
    in_x13 = in_x11 << ((ulong)bVar1 & 0x3f) & in_x12;
  }
  return in_w8 & 1;
}


