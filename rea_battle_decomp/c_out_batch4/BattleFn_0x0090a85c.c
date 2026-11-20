// ELF VMA: 0x90a85c
// Ghidra Addr: 0x00a0a85c (ImageBase=0x100000)
// Size: 7116 bytes


void BattleFn_0x0090a85c(int param_1,undefined8 param_2)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  undefined *puVar13;
  ulong uVar14;
  long lVar15;
  undefined1 auStack_198 [24];
  undefined1 auStack_180 [24];
  undefined1 auStack_168 [8];
  undefined4 auStack_160 [2];
  undefined *puStack_158;
  undefined1 auStack_150 [8];
  undefined *puStack_148;
  undefined4 auStack_140 [2];
  undefined8 auStack_138 [2];
  undefined *puStack_128;
  undefined4 auStack_120 [2];
  undefined8 uStack_118;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long lStack_70;
  undefined *puStack_68;
  
  lVar10 = tpidr_el0;
  lStack_70 = *(long *)(lVar10 + 0x28);
  if (param_1 < 0x44) {
    if (param_1 - 0x39U < 3) {
      puStack_f0 = &UNK_002974c3;
      uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
      uStack_e0 = 0;
      uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
      func_0x00bc5cc0(&uStack_108,4);
      uStack_100 = &UNK_00298aa1;
      func_0x00bc5cd0(&uStack_e8,&uStack_108);
      func_0x00bc5cc0(&uStack_108,0);
      func_0x0074c7e0(auStack_120,param_2);
      uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
      puStack_d0 = &UNK_0029a3d5;
      uStack_c0 = 0;
      func_0x00bc5d80(&uStack_c8,auStack_120);
      puStack_b0 = &UNK_00290d7a;
      uStack_a8 = (undefined *)((ulong)uStack_a8._4_4_ << 0x20);
      uStack_a0 = 0;
      uStack_108 = (undefined *)((ulong)uStack_108 & 0xffffffff00000000);
      func_0x00bc5cc0(&uStack_108,4);
      uStack_100 = &UNK_002a097c;
      func_0x00bc5cd0(&uStack_a8,&uStack_108);
      func_0x00bc5cc0(&uStack_108,0);
      lVar12 = func_0x007fd748(&puStack_f0);
      bVar2 = *(byte *)(lVar12 + 0xc95c);
      bVar3 = *(byte *)(lVar12 + 0xc984);
      bVar4 = *(byte *)(lVar12 + 0xc95d);
      bVar5 = *(byte *)(lVar12 + 0xc985);
      bVar6 = *(byte *)(lVar12 + 0xc95e);
      bVar7 = *(byte *)(lVar12 + 0xc986);
      bVar8 = *(byte *)(lVar12 + 0xc95f);
      bVar9 = *(byte *)(lVar12 + 0xc987);
      uStack_88 = (undefined *)((ulong)uStack_88._4_4_ << 0x20);
      puStack_90 = &UNK_00298462;
      uStack_80 = 0;
      uStack_108 = (undefined *)((ulong)uStack_108 & 0xffffffff00000000);
      func_0x00bc5cc0(&uStack_108,1);
      uStack_100 = (undefined *)
                   (ulong)(6 < (int)((uint)(bVar7 ^ bVar6) << 0x10 | (uint)(bVar9 ^ bVar8) << 0x18 |
                                     (uint)(bVar5 ^ bVar4) << 8 | (uint)(bVar3 ^ bVar2)));
      func_0x00bc5cd0(&uStack_88,&uStack_108);
      func_0x00bc5cc0(&uStack_108,0);
      func_0x00bc5cc0(auStack_120,0);
      lVar12 = func_0x007fd748();
      puVar13 = &UNK_0028c086;
      if (param_1 != 0x3b) {
        puVar13 = &UNK_0029c8ce;
      }
      puVar1 = &UNK_0028b1dc;
      if (param_1 != 0x3a) {
        puVar1 = puVar13;
      }
      func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),puVar1,&puStack_f0,4);
      func_0x00bc5cc0(&uStack_88,0);
      func_0x00bc5cc0(&uStack_a8,0);
      func_0x00bc5cc0(&uStack_c8,0);
      func_0x00bc5cc0(&uStack_e8,0);
    }
    else {
      if (param_1 == 1) {
        if (*(long *)(lVar10 + 0x28) == lStack_70) {
          puVar13 = &UNK_002a1828;
LAB_00a0af10:
          lVar10 = tpidr_el0;
          lVar12 = *(long *)(lVar10 + 0x28);
          puStack_148 = &UNK_002974c3;
          auStack_140[0] = 0;
          auStack_138[0] = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,4);
          puStack_158 = &UNK_0029f72d;
          func_0x00bc5cd0(auStack_140,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          iVar11 = func_0x007ac230(0);
          puStack_128 = &UNK_0029a3d5;
          auStack_120[0] = 0;
          uStack_118 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,1);
          puStack_158 = (undefined *)(long)iVar11;
          func_0x00bc5cd0(auStack_120,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          uStack_108 = &UNK_00290d7a;
          uStack_100 = (undefined *)((ulong)uStack_100._4_4_ << 0x20);
          uStack_f8 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,4);
          puStack_158 = &UNK_0029b8a8;
          func_0x00bc5cd0(&uStack_100,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          iVar11 = func_0x007ac380();
          uStack_e8 = &UNK_00298462;
          uStack_e0 = (ulong)uStack_e0._4_4_ << 0x20;
          uStack_d8 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,1);
          puStack_158 = (undefined *)(long)iVar11;
          func_0x00bc5cd0(&uStack_e0,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          uStack_c8 = &UNK_002914a8;
          uStack_c0 = (ulong)uStack_c0._4_4_ << 0x20;
          uStack_b8 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,4);
          puStack_158 = &UNK_0028e17f;
          func_0x00bc5cd0(&uStack_c0,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          uVar14 = func_0x007ad45c(&puStack_148);
          if ((uVar14 & 1) == 0) {
            iVar11 = func_0x007ac5b8();
          }
          else {
            iVar11 = func_0x007ac5b8();
            iVar11 = iVar11 + 10;
          }
          uStack_a8 = &UNK_00299a16;
          uStack_a0 = (ulong)uStack_a0._4_4_ << 0x20;
          uStack_98 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,1);
          puStack_158 = (undefined *)(long)iVar11;
          func_0x00bc5cd0(&uStack_a0,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          uStack_88 = &UNK_00291fc1;
          uStack_80 = (ulong)uStack_80._4_4_ << 0x20;
          uStack_78 = 0;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,4);
          puStack_158 = &UNK_00297a07;
          func_0x00bc5cd0(&uStack_80,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          iVar11 = func_0x007abd78(0);
          puStack_68 = &UNK_002a6836;
          auStack_160[0] = 0;
          func_0x00bc5cc0(auStack_160,1);
          puStack_158 = (undefined *)(long)iVar11;
          func_0x00bc5cd0(&stack0xffffffffffffffa0,auStack_160);
          func_0x00bc5cc0(auStack_160,0);
          lVar15 = func_0x007fd748();
          func_0x008265dc(*(undefined8 *)(lVar15 + 0x21a0),puVar13,&puStack_148,8);
          func_0x00bc5cc0(&stack0xffffffffffffffa0,0);
          func_0x00bc5cc0(&uStack_80,0);
          func_0x00bc5cc0(&uStack_a0,0);
          func_0x00bc5cc0(&uStack_c0,0);
          func_0x00bc5cc0(&uStack_e0,0);
          func_0x00bc5cc0(&uStack_100,0);
          func_0x00bc5cc0(auStack_120,0);
          func_0x00bc5cc0(auStack_140,0);
          if (*(long *)(lVar10 + 0x28) == lVar12) {
            return;
          }
                    /* WARNING: Subroutine does not return */
          NoRet_0x00ac3380();
        }
        goto LAB_00a0b11c;
      }
      if (param_1 == 0x21) {
        if (*(long *)(lVar10 + 0x28) == lStack_70) {
          puVar13 = &UNK_0029db09;
          goto LAB_00a0af10;
        }
        goto LAB_00a0b11c;
      }
    }
  }
  else if (param_1 < 0x55) {
    if (param_1 == 0x44) {
      puStack_f0 = &UNK_002974c3;
      uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
      uStack_e0 = 0;
      uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
      func_0x00bc5cc0(&uStack_108,4);
      uStack_100 = &UNK_0028a342;
      func_0x00bc5cd0(&uStack_e8,&uStack_108);
      func_0x00bc5cc0(&uStack_108,0);
      func_0x0074c7e0(auStack_138,param_2);
      uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
      puStack_d0 = &UNK_0029a3d5;
      uStack_c0 = 0;
      func_0x00bc5d80(&uStack_c8,auStack_138);
      func_0x00bc5cc0(auStack_138,0);
      lVar12 = func_0x007fd748();
      func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),&UNK_0028c09d,&puStack_f0,2);
      func_0x00bc5cc0(&uStack_c8,0);
      func_0x00bc5cc0(&uStack_e8,0);
    }
    else if (param_1 == 0x46) {
      puStack_f0 = &UNK_002974c3;
      uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
      uStack_e0 = 0;
      uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
      func_0x00bc5cc0(&uStack_108,4);
      uStack_100 = &UNK_0029b843;
      func_0x00bc5cd0(&uStack_e8,&uStack_108);
      func_0x00bc5cc0(&uStack_108,0);
      func_0x0074c7e0(auStack_150,param_2);
      uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
      puStack_d0 = &UNK_0029a3d5;
      uStack_c0 = 0;
      func_0x00bc5d80(&uStack_c8,auStack_150);
      func_0x00bc5cc0(auStack_150,0);
      lVar12 = func_0x007fd748();
      func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),&UNK_0029c8e1,&puStack_f0,2);
      func_0x00bc5cc0(&uStack_c8,0);
      func_0x00bc5cc0(&uStack_e8,0);
    }
  }
  else if (param_1 == 0x55) {
    puStack_f0 = &UNK_002974c3;
    uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
    uStack_e0 = 0;
    uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
    func_0x00bc5cc0(&uStack_108,4);
    uStack_100 = &UNK_002a17d1;
    func_0x00bc5cd0(&uStack_e8,&uStack_108);
    func_0x00bc5cc0(&uStack_108,0);
    func_0x0074c7e0(auStack_168,param_2);
    uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
    puStack_d0 = &UNK_0029a3d5;
    uStack_c0 = 0;
    func_0x00bc5d80(&uStack_c8,auStack_168);
    func_0x00bc5cc0(auStack_168,0);
    lVar12 = func_0x007fd748();
    func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),&UNK_002a3ae6,&puStack_f0,2);
    func_0x00bc5cc0(&uStack_c8,0);
    func_0x00bc5cc0(&uStack_e8,0);
  }
  else if (param_1 == 0x65) {
    puStack_f0 = &UNK_002974c3;
    uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
    uStack_e0 = 0;
    uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
    func_0x00bc5cc0(&uStack_108,4);
    uStack_100 = &UNK_002a17d1;
    func_0x00bc5cd0(&uStack_e8,&uStack_108);
    func_0x00bc5cc0(&uStack_108,0);
    func_0x0074c7e0(auStack_180,param_2);
    uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
    puStack_d0 = &UNK_0029a3d5;
    uStack_c0 = 0;
    func_0x00bc5d80(&uStack_c8,auStack_180);
    func_0x00bc5cc0(auStack_180,0);
    lVar12 = func_0x007fd748();
    func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),&UNK_00292531,&puStack_f0,2);
    func_0x00bc5cc0(&uStack_c8,0);
    func_0x00bc5cc0(&uStack_e8,0);
  }
  else if (param_1 == 0x66) {
    puStack_f0 = &UNK_002974c3;
    uStack_e8 = (undefined *)((ulong)uStack_e8._4_4_ << 0x20);
    uStack_e0 = 0;
    uStack_108 = (undefined *)((ulong)uStack_108._4_4_ << 0x20);
    func_0x00bc5cc0(&uStack_108,4);
    uStack_100 = &UNK_002a17d1;
    func_0x00bc5cd0(&uStack_e8,&uStack_108);
    func_0x00bc5cc0(&uStack_108,0);
    func_0x0074c7e0(auStack_198,param_2);
    uStack_c8 = (undefined *)((ulong)uStack_c8._4_4_ << 0x20);
    puStack_d0 = &UNK_0029a3d5;
    uStack_c0 = 0;
    func_0x00bc5d80(&uStack_c8,auStack_198);
    func_0x00bc5cc0(auStack_198,0);
    lVar12 = func_0x007fd748();
    func_0x008265dc(*(undefined8 *)(lVar12 + 0x21a0),&UNK_0029b84d,&puStack_f0,2);
    func_0x00bc5cc0(&uStack_c8,0);
    func_0x00bc5cc0(&uStack_e8,0);
  }
  if (*(long *)(lVar10 + 0x28) == lStack_70) {
    return;
  }
LAB_00a0b11c:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


