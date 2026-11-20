// ELF VMA: 0x4ace18
// Ghidra Addr: 0x005ace18 (ImageBase=0x100000)
// Size: 128 bytes


undefined8 BattleFn_0x004ace18(void)

{
  int iVar1;
  
  if (((bRam0000000000c0be90 & 1) == 0) && (iVar1 = func_0x00bc32f0(0xc0be90), iVar1 != 0)) {
    uRam0000000000c0be60 = 0;
    uRam0000000000c0be58 = 0xc0be60;
    uRam0000000000c0be80 = 0;
    uRam0000000000c0be88 = 0;
    uRam0000000000c0be78 = 0;
    uRam0000000000c0be68 = 0;
    uRam0000000000c0be70 = 0xc0be78;
    func_0x00bc32d0(&UNK_00450320,0xc0be58,&DAT_00bce2b0);  /* field_off=0x450320 */
    func_0x00bc3310(0xc0be90);
  }
  return 0xc0be58;
}


