// ELF VMA: 0x4b217c
// Ghidra Addr: 0x005b217c (ImageBase=0x100000)
// Size: 484 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004b217c(long param_1)

{
  long lVar1;
  undefined1 uVar2;
  byte bVar3;
  byte *pbVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined8 uStack_13d0;
  undefined1 auStack_13c4 [4];
  ulong uStack_13c0;
  undefined1 uStack_13b8;
  undefined4 uStack_13b7;
  undefined1 uStack_13b3;
  undefined8 uStack_13b0;
  undefined8 uStack_40;
  long lStack_38;
  
  pbVar4 = (byte *)(param_1 + 0xc);
  uVar5 = *(undefined8 *)pbVar4;
  auVar8._8_8_ = uVar5;
  auVar8._0_8_ = uVar5;
  auVar9 = NEON_ushl(auVar8,_UNK_002aa1d0,8);  /* UNK_2aa1d0(vma=0x1aa1d0)='u32=0xfffffff8(4294967288) f32=nan' */
  auVar8 = NEON_ushl(auVar8,_UNK_002a9cb0,8);  /* UNK_2a9cb0(vma=0x1a9cb0)='u32=0xffffffd0(4294967248) f32=nan' */
  uVar7 = NEON_ushl(CONCAT44(CONCAT13(auVar8[0xb] ^ auVar9[0xb],
                                      CONCAT12(auVar8[10] ^ auVar9[10],
                                               CONCAT11(auVar8[9] ^ auVar9[9],auVar8[8] ^ auVar9[8])
                                              )),
                             CONCAT13(auVar8[3] ^ auVar9[3],
                                      CONCAT12(auVar8[2] ^ auVar9[2],
                                               CONCAT11(auVar8[1] ^ auVar9[1],auVar8[0] ^ auVar9[0])
                                              ))),0x1000000008,4);
  *(uint *)pbVar4 =
       (((uint)(byte)((ulong)uVar5 >> 0x38) ^ (uint)uVar5) & 0xff |
        ((uint)((ulong)uVar5 >> 0x20) ^ (uint)uVar5 >> 0x18) << 0x18 |
        (uint)(uVar7 & 0xff00000000ff00) | (uint)((uVar7 & 0xff00000000ff00) >> 0x20)) + 1;
  lVar1 = tpidr_el0;
  lStack_38 = *(long *)(lVar1 + 0x28);
  uStack_13c0._0_1_ = 0x18;
  uStack_13b7 = 0x6d6f646e;  /* ascii(0x6d6f646e)='ndom' */
  uStack_13c0._1_7_ = 0x72752f7665642f;  /* ascii(0x72752f7665642f)='/dev/ur' */
  uStack_13b8 = 0x61;
  uStack_13b3 = 0;
  func_0x00bc3840(auStack_13c4,&uStack_13c0);
  if (((byte)uStack_13c0 & 1) != 0) {
    func_0x00bc3350(uStack_13b0);
  }
  uVar7 = func_0x00bc3850(auStack_13c4);
  uVar7 = uVar7 & 0xffffffff;
  lVar6 = 1;
  uStack_13c0._0_1_ = (byte)uVar7;
  uStack_13c0._1_7_ = (undefined7)(uVar7 >> 8);
  do {
    uVar7 = (ulong)((int)lVar6 + ((uint)(uVar7 >> 0x1e) ^ (uint)uVar7) * 0x6c078965);
    (&uStack_13c0)[lVar6] = uVar7;
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x270);
  uStack_40 = 0;
  uStack_13d0 = 0xff00000000;
  uVar2 = func_0x0043edb0(&uStack_13d0,&uStack_13c0,&uStack_13d0);
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  uVar2 = func_0x0043edb0(&uStack_13d0,&uStack_13c0,&uStack_13d0);
  *(undefined1 *)(param_1 + 0x11) = uVar2;
  uVar2 = func_0x0043edb0(&uStack_13d0,&uStack_13c0,&uStack_13d0);
  *(undefined1 *)(param_1 + 0x12) = uVar2;
  bVar3 = func_0x0043edb0(&uStack_13d0,&uStack_13c0,&uStack_13d0);
  *(byte *)(param_1 + 0x13) = bVar3;
  *pbVar4 = *pbVar4 ^ bVar3;
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0x12) ^ *(byte *)(param_1 + 0xd);
  *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0x11) ^ *(byte *)(param_1 + 0xe);
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0x10) ^ *(byte *)(param_1 + 0xf);
  func_0x00bc3870(auStack_13c4);
  if (*(long *)(lVar1 + 0x28) == lStack_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


