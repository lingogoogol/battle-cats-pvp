// Target Address: 0x957c8c
// Function: Unit_GetTargetType_0x957c8c
// Decompiled by Ghidra 12.1.4 Headless

void thunk_FUN_00957c3c(void)

{
  byte bVar1;
  long unaff_x24;
  long unaff_x29;
  byte in_stack_00000000;
  undefined8 in_stack_00000010;
  byte in_stack_00000018;
  undefined8 in_stack_00000028;
  byte in_stack_00000030;
  undefined8 in_stack_00000040;
  byte in_stack_00000050;
  undefined8 in_stack_00000060;
  byte in_stack_00000070;
  undefined8 in_stack_00000080;
  byte in_stack_00000090;
  undefined8 in_stack_000000a0;
  
FUN_00957c3c:
  func_0x00bc3350(in_stack_00000060);
  if ((in_stack_00000030 & 1) == 0) goto LAB_00957ba8;
LAB_00957c4c:
  func_0x00bc3350(in_stack_00000040);
  if ((in_stack_00000018 & 1) == 0) goto LAB_00957bb0;
  do {
    func_0x00bc3350(in_stack_00000028);
    bVar1 = *(byte *)(unaff_x29 + -0xa8);
    while( true ) {
      if ((bVar1 & 1) != 0) {
        func_0x00bc3350(*(undefined8 *)(unaff_x29 + -0x98));
      }
      if (*(long *)(unaff_x24 + 0x28) == *(long *)(unaff_x29 + -8)) {
        func_0x00bbf40c();
      }
      func_0x00bc3380();
      func_0x00bc3350(*(undefined8 *)(unaff_x29 + -0x30));
      if ((in_stack_00000090 & 1) != 0) {
        func_0x00bc3350(in_stack_000000a0);
      }
      if ((in_stack_00000000 & 1) != 0) {
        func_0x00bc3350(in_stack_00000010);
      }
      if ((in_stack_00000070 & 1) != 0) {
        func_0x00bc3350(in_stack_00000080);
      }
      if ((in_stack_00000050 & 1) != 0) goto FUN_00957c3c;
      if ((in_stack_00000030 & 1) != 0) goto LAB_00957c4c;
LAB_00957ba8:
      if ((in_stack_00000018 & 1) != 0) break;
LAB_00957bb0:
      bVar1 = *(byte *)(unaff_x29 + -0xa8);
    }
  } while( true );
}


