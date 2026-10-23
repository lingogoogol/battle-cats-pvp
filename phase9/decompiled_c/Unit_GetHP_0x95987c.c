// Target Address: 0x95987c
// Function: Unit_GetHP_0x95987c
// Decompiled by Ghidra 12.1.4 Headless

long Unit_GetHP_0x95987c(undefined8 param_1)

{
  long lVar1;
  long unaff_x20;
  long unaff_x29;
  undefined1 auVar2 [16];
  byte in_stack_00000008;
  undefined8 in_stack_00000018;
  byte in_stack_00000020;
  undefined8 in_stack_00000030;
  
  if ((in_stack_00000008 & 1) != 0) {
    func_0x00bc3350(in_stack_00000018);
  }
  if ((in_stack_00000020 & 1) != 0) {
    func_0x00bc3350(in_stack_00000030);
  }
  func_0x004218fc(unaff_x29 + -0x18);
  if (*(long *)(unaff_x20 + 0x28) == *(long *)(unaff_x29 + -8)) {
    func_0x00bbf40c(param_1);
  }
  auVar2 = func_0x00bc3380();
  lVar1 = auVar2._0_8_ + 8;
  if (*(undefined **)(auVar2._8_8_ + 8) != &UNK_002e309b) {
    lVar1 = 0;
  }
  return lVar1;
}


