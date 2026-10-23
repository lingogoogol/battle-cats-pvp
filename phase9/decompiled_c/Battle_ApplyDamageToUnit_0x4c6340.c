// Target Address: 0x4c6340
// Function: Battle_ApplyDamageToUnit_0x4c6340
// Decompiled by Ghidra 12.1.4 Headless

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong Battle_ApplyDamageToUnit_0x4c6340(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  ulong uVar7;
  code *in_x9;
  long unaff_x19;
  ulong unaff_x21;
  long lVar8;
  long unaff_x23;
  long unaff_x24;
  ulong unaff_x25;
  long unaff_x29;
  long in_stack_00000008;
  long in_stack_00000010;
  long in_stack_00000018;
  long in_stack_00000028;
  long in_stack_00000030;
  long in_stack_00000038;
  long in_stack_00000048;
  long in_stack_00000050;
  long in_stack_00000058;
  long in_stack_00000068;
  long in_stack_00000070;
  long in_stack_00000078;
  long in_stack_00000088;
  long in_stack_00000090;
  long in_stack_00000098;
  
  (*in_x9)(param_1,0);
  func_0x00bc3ae0();
  lVar8 = in_stack_00000088;
  if (in_stack_00000088 != 0) {
    in_stack_00000090 = in_stack_00000088;
    (**(code **)(unaff_x24 + 0xa58))(in_stack_00000088,0,in_stack_00000098 - in_stack_00000088);
    func_0x00bc3ae0(lVar8);
  }
  lVar8 = *(long *)(unaff_x29 + -0x68);
  if (lVar8 != 0) {
    *(long *)(unaff_x29 + -0x60) = lVar8;
    (**(code **)(unaff_x24 + 0xa58))(lVar8,0,*(long *)(unaff_x29 + -0x58) - lVar8);
    func_0x00bc3ae0(lVar8);
  }
  lVar8 = *(long *)(unaff_x29 + -0x48);
  if (lVar8 != 0) {
    *(long *)(unaff_x29 + -0x40) = lVar8;
    (**(code **)(unaff_x24 + 0xa58))(lVar8,0,*(long *)(unaff_x29 + -0x38) - lVar8);
    func_0x00bc3ae0(lVar8);
  }
  lVar8 = *(long *)(unaff_x29 + -0x28);
  if (lVar8 != 0) {
    *(long *)(unaff_x29 + -0x20) = lVar8;
    (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x18) - lVar8);
    func_0x00bc3ae0(lVar8);
  }
  if ((unaff_x25 & 1) == 0) {
    func_0x00bc3db0(unaff_x29 + -0x68,1);
    func_0x00bc4150(unaff_x29 + -0x48,unaff_x19 + 0x70,unaff_x29 + -0x68);
    func_0x00bc4130(unaff_x29 + -0x28,unaff_x19 + 0x50,unaff_x29 + -0x48);
    bVar3 = true;
    iVar4 = func_0x00bc3fb0(unaff_x19 + 0xb0,unaff_x29 + -0x28,1);
    if (iVar4 == 0) {
      func_0x00bc3db0(&stack0x00000048,1);
      func_0x00bc4150(&stack0x00000068,unaff_x19 + 0x90,&stack0x00000048);
      func_0x00bc4130(&stack0x00000088,unaff_x19 + 0x50,&stack0x00000068);
      iVar4 = func_0x00bc3fb0(unaff_x19 + 0xd0,&stack0x00000088,1);
      if (iVar4 == 0) {
        func_0x00bc4840(&stack0x00000028,unaff_x19 + 0x90,unaff_x19 + 0x70);
        iVar4 = func_0x00bc3fb0(unaff_x19 + 0xf0,&stack0x00000028,1);
        lVar8 = in_stack_00000028;
        bVar3 = iVar4 != 0;
        if (in_stack_00000028 != 0) {
          in_stack_00000030 = in_stack_00000028;
          (*_UNK_00bd2a58)(in_stack_00000028,0,in_stack_00000038 - in_stack_00000028);
          func_0x00bc3ae0(lVar8);
        }
      }
      lVar8 = in_stack_00000088;
      if (in_stack_00000088 != 0) {
        in_stack_00000090 = in_stack_00000088;
        (*_UNK_00bd2a58)(in_stack_00000088,0,in_stack_00000098 - in_stack_00000088);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000068;
      if (in_stack_00000068 != 0) {
        in_stack_00000070 = in_stack_00000068;
        (*_UNK_00bd2a58)(in_stack_00000068,0,in_stack_00000078 - in_stack_00000068);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000048;
      if (in_stack_00000048 != 0) {
        in_stack_00000050 = in_stack_00000048;
        (*_UNK_00bd2a58)(in_stack_00000048,0,in_stack_00000058 - in_stack_00000048);
        func_0x00bc3ae0(lVar8);
      }
    }
    lVar8 = *(long *)(unaff_x29 + -0x28);
    if (lVar8 != 0) {
      *(long *)(unaff_x29 + -0x20) = lVar8;
      (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x18) - lVar8);
      func_0x00bc3ae0(lVar8);
    }
    lVar8 = *(long *)(unaff_x29 + -0x48);
    if (lVar8 != 0) {
      *(long *)(unaff_x29 + -0x40) = lVar8;
      (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x38) - lVar8);
      func_0x00bc3ae0(lVar8);
    }
    lVar8 = *(long *)(unaff_x29 + -0x68);
    if (lVar8 != 0) {
      *(long *)(unaff_x29 + -0x60) = lVar8;
      (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x58) - lVar8);
      func_0x00bc3ae0(lVar8);
    }
    if (!bVar3) {
      uVar7 = func_0x00bc4740(unaff_x19 + 0x70);
      uVar5 = 0;
      if ((((uVar7 & 1) == 0) || (uVar5 = func_0x00bc4740(unaff_x19 + 0x90), (uVar5 & 1) == 0)) ||
         ((unaff_x21 & 1) == 0)) goto LAB_004c660c;
      func_0x00bc40e0(unaff_x29 + -0x48,unaff_x19 + 0x30,unaff_x19 + 0x50);
      func_0x00bc3db0(&stack0x00000068,1);
      func_0x00bc4150(&stack0x00000088,unaff_x19 + 0x70,&stack0x00000068);
      func_0x00bc3db0(&stack0x00000028,1);
      func_0x00bc4150(&stack0x00000048,unaff_x19 + 0x90,&stack0x00000028);
      func_0x00bc4810(unaff_x29 + -0x68,&stack0x00000088,&stack0x00000048);
      func_0x00bc4130(unaff_x29 + -0x28,unaff_x29 + -0x48,unaff_x29 + -0x68);
      func_0x00bc3db0(&stack0x00000008,1);
      iVar4 = func_0x00bc3fb0(unaff_x29 + -0x28,&stack0x00000008,1);
      lVar8 = in_stack_00000008;
      if (in_stack_00000008 != 0) {
        in_stack_00000010 = in_stack_00000008;
        (*_UNK_00bd2a58)(in_stack_00000008,0,in_stack_00000018 - in_stack_00000008);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = *(long *)(unaff_x29 + -0x28);
      if (lVar8 != 0) {
        *(long *)(unaff_x29 + -0x20) = lVar8;
        (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x18) - lVar8);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = *(long *)(unaff_x29 + -0x68);
      if (lVar8 != 0) {
        *(long *)(unaff_x29 + -0x60) = lVar8;
        (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x58) - lVar8);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000048;
      if (in_stack_00000048 != 0) {
        in_stack_00000050 = in_stack_00000048;
        (*_UNK_00bd2a58)(in_stack_00000048,0,in_stack_00000058 - in_stack_00000048);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000028;
      if (in_stack_00000028 != 0) {
        in_stack_00000030 = in_stack_00000028;
        (*_UNK_00bd2a58)(in_stack_00000028,0,in_stack_00000038 - in_stack_00000028);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000088;
      if (in_stack_00000088 != 0) {
        in_stack_00000090 = in_stack_00000088;
        (*_UNK_00bd2a58)(in_stack_00000088,0,in_stack_00000098 - in_stack_00000088);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = in_stack_00000068;
      if (in_stack_00000068 != 0) {
        in_stack_00000070 = in_stack_00000068;
        (*_UNK_00bd2a58)(in_stack_00000068,0,in_stack_00000078 - in_stack_00000068);
        func_0x00bc3ae0(lVar8);
      }
      lVar8 = *(long *)(unaff_x29 + -0x48);
      if (lVar8 != 0) {
        *(long *)(unaff_x29 + -0x40) = lVar8;
        (*_UNK_00bd2a58)(lVar8,0,*(long *)(unaff_x29 + -0x38) - lVar8);
        func_0x00bc3ae0(lVar8);
      }
      if (iVar4 == 0) {
        uVar1 = CONCAT26(_UNK_00299232,_UNK_0029922c);
        *(undefined1 *)(unaff_x29 + -0x28) = 0x1c;
        uVar2 = CONCAT62(_UNK_00299234,_UNK_00299232);
        *(undefined1 *)(unaff_x29 + -0x19) = 0;
        *(undefined8 *)(unaff_x29 + -0x27) = uVar1;
        *(undefined8 *)(unaff_x29 + -0x21) = uVar2;
        uVar5 = func_0x00bc46a0();
        if ((*(byte *)(unaff_x29 + -0x28) & 1) != 0) {
          func_0x00bc3350(*(undefined8 *)(unaff_x29 + -0x18));
        }
        goto LAB_004c660c;
      }
    }
  }
  uVar5 = 0;
LAB_004c660c:
  if (*(long *)(unaff_x23 + 0x28) == *(long *)(unaff_x29 + -8)) {
    return (ulong)(uVar5 & 1);
  }
  func_0x00bc3380();
  plVar6 = (long *)func_0x0040f948();
  uVar7 = (*(code *)PTR__ZNK5Botan14RSA_PrivateKey9check_keyERNS_21RandomNumberGeneratorEb_00c03b40)
                    ((long)plVar6 + *(long *)(*plVar6 + -0x40));
  return uVar7;
}


