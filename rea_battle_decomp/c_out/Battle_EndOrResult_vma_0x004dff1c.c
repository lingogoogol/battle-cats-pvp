// ELF VMA: 0x4dff1c
// Ghidra Addr: 0x005dff1c (ImageBase=0x100000)
// Function: Battle_EndOrResult
// Size: 852 bytes
// Callees (0): 


/* WARNING: Possible PIC construction at 0x0044d850: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d910: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0044d980: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0044d854) */
/* WARNING: Removing unreachable block (ram,0x0044d870) */
/* WARNING: Removing unreachable block (ram,0x0044d878) */
/* WARNING: Removing unreachable block (ram,0x0044dbd0) */
/* WARNING: Removing unreachable block (ram,0x0044d894) */
/* WARNING: Removing unreachable block (ram,0x0044dbe0) */
/* WARNING: Removing unreachable block (ram,0x0044d89c) */
/* WARNING: Removing unreachable block (ram,0x0044dbf0) */
/* WARNING: Removing unreachable block (ram,0x0044dc00) */
/* WARNING: Removing unreachable block (ram,0x0044d8a4) */
/* WARNING: Removing unreachable block (ram,0x0044d8ac) */
/* WARNING: Removing unreachable block (ram,0x0044d8b4) */
/* WARNING: Removing unreachable block (ram,0x0044d8c0) */
/* WARNING: Removing unreachable block (ram,0x0044d914) */
/* WARNING: Removing unreachable block (ram,0x0044d92c) */
/* WARNING: Removing unreachable block (ram,0x0044d934) */
/* WARNING: Removing unreachable block (ram,0x0044dc04) */
/* WARNING: Removing unreachable block (ram,0x0044d950) */
/* WARNING: Removing unreachable block (ram,0x0044dc14) */
/* WARNING: Removing unreachable block (ram,0x0044d958) */
/* WARNING: Removing unreachable block (ram,0x0044dc24) */
/* WARNING: Removing unreachable block (ram,0x0044dc34) */
/* WARNING: Removing unreachable block (ram,0x0044d960) */
/* WARNING: Removing unreachable block (ram,0x0044d968) */
/* WARNING: Removing unreachable block (ram,0x0044d970) */
/* WARNING: Removing unreachable block (ram,0x0044d984) */
/* WARNING: Removing unreachable block (ram,0x0044d998) */
/* WARNING: Removing unreachable block (ram,0x0044d9c4) */
/* WARNING: Removing unreachable block (ram,0x0044d9d4) */
/* WARNING: Removing unreachable block (ram,0x0044d9ec) */
/* WARNING: Removing unreachable block (ram,0x0044d9f4) */
/* WARNING: Removing unreachable block (ram,0x0044da04) */
/* WARNING: Removing unreachable block (ram,0x0044da1c) */
/* WARNING: Removing unreachable block (ram,0x0044dad8) */
/* WARNING: Removing unreachable block (ram,0x0044da2c) */
/* WARNING: Removing unreachable block (ram,0x0044da38) */
/* WARNING: Removing unreachable block (ram,0x0044da54) */
/* WARNING: Removing unreachable block (ram,0x0044da60) */
/* WARNING: Removing unreachable block (ram,0x0044da6c) */
/* WARNING: Removing unreachable block (ram,0x0044da78) */
/* WARNING: Removing unreachable block (ram,0x0044da88) */
/* WARNING: Removing unreachable block (ram,0x0044daa0) */
/* WARNING: Removing unreachable block (ram,0x0044dc38) */
/* WARNING: Removing unreachable block (ram,0x0044ddb8) */
/* WARNING: Removing unreachable block (ram,0x0044dc3c) */
/* WARNING: Removing unreachable block (ram,0x0044ddbc) */
/* WARNING: Removing unreachable block (ram,0x0044daa4) */
/* WARNING: Removing unreachable block (ram,0x0044ddc0) */
/* WARNING: Removing unreachable block (ram,0x0044de10) */
/* WARNING: Removing unreachable block (ram,0x0044dae4) */
/* WARNING: Removing unreachable block (ram,0x0044daec) */
/* WARNING: Removing unreachable block (ram,0x0044daf0) */
/* WARNING: Removing unreachable block (ram,0x0044d978) */
/* WARNING: Removing unreachable block (ram,0x0044dad0) */
/* WARNING: Type propagation algorithm not settling */

long * Battle_EndOrResult(long *param_1,undefined8 *param_2,int *param_3)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  undefined1 auVar4 [16];
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  long *plVar9;
  undefined **ppuVar10;
  undefined8 *puVar11;
  ulong uVar12;
  ulong *puVar13;
  uint uVar14;
  long *plVar15;
  long lVar16;
  undefined **extraout_x8;
  long lVar17;
  ulong uVar18;
  long *unaff_x19;
  undefined8 unaff_x20;
  undefined8 uVar19;
  undefined8 unaff_x21;
  undefined8 uVar20;
  ulong unaff_x22;
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  ulong uStack_190;
  ulong uStack_188;
  ulong uStack_180;
  ulong uStack_170;
  ulong uStack_168;
  ulong uStack_160;
  long lStack_158;
  undefined8 uStack_150;
  ulong uStack_148;
  ulong uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  long *plStack_128;
  byte abStack_118 [16];
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f0;
  byte abStack_e8 [16];
  undefined8 uStack_d8;
  undefined *puStack_d0;
  long lStack_c8;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [8];
  undefined **ppuStack_b0;
  byte bStack_98;
  undefined8 uStack_97;
  undefined2 uStack_8f;
  undefined1 uStack_8d;
  undefined8 uStack_88;
  ulong uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  long lStack_68;
  uint *puVar8;
  
  lVar17 = tpidr_el0;
  lStack_68 = *(long *)(lVar17 + 0x28);
  iVar2 = *param_3;
  if (iVar2 == 4) {
    bStack_98 = 0x14;
    uVar19 = *param_2;
    lVar6 = param_1[1];
    uStack_97 = 0x5058656c74746142;
    uStack_8f = 0x3278;
    uStack_8d = 0;
    puStack_d0 = (undefined *)((ulong)puStack_d0 & 0xffffffffffff0000);
    func_0x00a0a85c(0x66,&bStack_98,&puStack_d0);
    if (((ulong)puStack_d0 & 1) == 0) {
      if ((bStack_98 & 1) == 0) goto LAB_005e0010;
LAB_005e0050:
      func_0x00bc3350(uStack_88);
      if ((char)param_1[2] == '\0') goto LAB_005e0060;
LAB_005e0018:
      func_0x00864534(uVar19,0);
      func_0x00868790(lVar6 + 0x2de8);
      func_0x00866804();
      cVar3 = (char)param_1[2];
      uVar20 = 0x24;
    }
    else {
      func_0x00bc3350(uStack_c0);
      if ((bStack_98 & 1) != 0) goto LAB_005e0050;
LAB_005e0010:
      if ((char)param_1[2] != '\0') goto LAB_005e0018;
LAB_005e0060:
      cVar3 = '\0';
      uVar20 = 4;
    }
    lVar16 = 0x10;
    if (cVar3 != '\0') {
      lVar16 = 0x12;
    }
    puVar1 = &UNK_0028fc76;
    if (cVar3 != '\0') {
      puVar1 = &UNK_0028fc87;
    }
    abStack_118[0] = (byte)((int)lVar16 << 1);
    func_0x00bc35f0((ulong)abStack_118 | 1,puVar1,lVar16);
    *(undefined1 *)(((ulong)abStack_118 | 1) + lVar16) = 0;
    func_0x0045e320(&uStack_100,abStack_118);
    func_0x00bc33f0(&uStack_148,*(undefined4 *)(lVar6 + 0x836c8));
    bStack_98 = 4;
    uStack_97 = CONCAT53(uStack_97._3_5_,0x7078);
    uStack_78 = uStack_140;
    uStack_80 = uStack_148;
    uStack_70 = uStack_138;
    uStack_148 = 0;
    uStack_140 = 0;
    uStack_138 = 0;
    func_0x004fed18(&uStack_130,&bStack_98,1,(long)&uStack_150 + 7);
    func_0x00597524(abStack_e8,&uStack_100,&uStack_130);
    puStack_d0 = &UNK_00bdc2b8;
    auStack_b8[0] = (undefined1)param_1[2];
    ppuStack_b0 = &puStack_d0;
    lStack_c8 = lVar6;
    uStack_c0 = uVar19;
    uVar19 = func_0x0086847c(lVar6 + 0x2de8,abStack_e8,0,0,uVar20,&puStack_d0);
    func_0x00866e34(uVar19,1);
    if (ppuStack_b0 == &puStack_d0) {
      lVar6 = 4;
      ppuVar10 = &puStack_d0;
LAB_005e0184:
      (**(code **)(*ppuVar10 + lVar6 * 8))();
    }
    else if (ppuStack_b0 != (undefined **)0x0) {
      lVar6 = 5;
      ppuVar10 = ppuStack_b0;
      goto LAB_005e0184;
    }
    if ((abStack_e8[0] & 1) != 0) {
      func_0x00bc3350(uStack_d8);
    }
    param_1 = (long *)func_0x0043e748(&uStack_130,plStack_128);
    if ((uStack_80 & 1) != 0) {
      param_1 = (long *)func_0x00bc3350(uStack_70);
    }
    if ((bStack_98 & 1) != 0) {
      param_1 = (long *)func_0x00bc3350(uStack_88);
    }
    if ((uStack_148 & 1) != 0) {
      param_1 = (long *)func_0x00bc3350(uStack_138);
    }
    if (((byte)uStack_100 & 1) != 0) {
      param_1 = (long *)func_0x00bc3350(uStack_f0);
    }
    if ((abStack_118[0] & 1) != 0) {
      param_1 = (long *)func_0x00bc3350(uStack_108);
    }
LAB_005e01dc:
    if (*(long *)(lVar17 + 0x28) == lStack_68) {
      return param_1;
    }
LAB_005e0358:
    auVar23 = func_0x00bc3380();
    plVar9 = (long *)(auVar23._0_8_ + 8);
    if (*(undefined **)(auVar23._8_8_ + 8) != &UNK_002bf596) {
      plVar9 = (long *)0x0;
    }
    return plVar9;
  }
  if (iVar2 == 3) {
    plVar9 = (long *)func_0x0044c16c();
    if (*(long *)(lVar17 + 0x28) != lStack_68) goto LAB_005e0358;
    uVar12 = 0xb;
  }
  else {
    if (iVar2 != 0) goto LAB_005e01dc;
    plVar9 = (long *)func_0x0044c16c();
    if (*(long *)(lVar17 + 0x28) != lStack_68) goto LAB_005e0358;
    uVar12 = 10;
  }
  puVar13 = (ulong *)0x0;
  lVar17 = tpidr_el0;
  lStack_68 = *(long *)(lVar17 + 0x28);
  if ((ulong)(long)(int)uVar12 < (ulong)(plVar9[2] - plVar9[1] >> 2)) {
    unaff_x20 = 0;
    unaff_x21 = 0;
    plVar5 = plVar9;
    if ((int)uVar12 == 0x1d) {
      plVar5 = (long *)func_0x007fd748();
      if ((int)plVar5[0x881ca] != -1) {
        lVar6 = func_0x007fd748();
        plVar5 = (long *)func_0x007fd748();
        plVar15 = *(long **)(lVar6 + 0x2618);
        if (plVar15 != (long *)0x0) {
          do {
            if ((int)plVar15[4] <= (int)plVar5[0x881ca]) {
              if ((int)plVar5[0x881ca] <= (int)plVar15[4]) {
                lVar6 = func_0x007fd748();
                plVar5 = (long *)func_0x007fd748();
                iVar2 = (int)plVar5[0x881ca];
                puVar11 = *(undefined8 **)(lVar6 + 0x2618);
                if (*(undefined8 **)(lVar6 + 0x2618) != (undefined8 *)0x0) goto LAB_0044d6d8;
                puVar21 = (undefined8 *)(lVar6 + 0x2618);
                puVar22 = (undefined8 *)(lVar6 + 0x2618);
                goto LAB_0044d6fc;
              }
              plVar15 = plVar15 + 1;
            }
            plVar15 = (long *)*plVar15;
          } while (plVar15 != (long *)0x0);
        }
      }
      goto LAB_0044d7dc;
    }
    goto LAB_0044d7e0;
  }
  uStack_80 = uStack_80 & 0xffffffffffff0000;
  plVar5 = (long *)func_0x0056a6f0(&uStack_80,3);
  plVar9 = unaff_x19;
  if ((uStack_80 & 1) != 0) {
    plVar5 = (long *)func_0x00bc3350(uStack_70);
  }
  goto LAB_0044dd88;
  while (puVar11 = (undefined8 *)*puVar7, puVar22 = puVar7,
        (undefined8 *)*puVar7 != (undefined8 *)0x0) {
LAB_0044d6d8:
    puVar7 = puVar11;
    puVar21 = puVar7;
    if (*(int *)(puVar7 + 4) <= iVar2) {
      if (iVar2 <= *(int *)(puVar7 + 4)) goto LAB_0044d7a0;
      puVar11 = (undefined8 *)puVar7[1];
      if ((undefined8 *)puVar7[1] == (undefined8 *)0x0) {
        puVar22 = puVar7 + 1;
        break;
      }
      goto LAB_0044d6d8;
    }
  }
LAB_0044d6fc:
  puVar7 = (undefined8 *)func_0x00bc3330(0x160);
  puVar7[0x2b] = 0;
  *(int *)(puVar7 + 4) = iVar2;
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = puVar21;
  puVar7[0x22] = 0;
  puVar7[0x21] = 0;
  puVar7[0x24] = 0;
  puVar7[0x23] = 0;
  puVar7[8] = 0;
  puVar7[7] = 0;
  puVar7[10] = 0;
  puVar7[9] = 0;
  puVar7[0xc] = 0;
  puVar7[0xb] = 0;
  puVar7[0xe] = 0;
  puVar7[0xd] = 0;
  puVar7[0x10] = 0;
  puVar7[0xf] = 0;
  puVar7[0x12] = 0;
  puVar7[0x11] = 0;
  puVar7[0x14] = 0;
  puVar7[0x13] = 0;
  puVar7[0x16] = 0;
  puVar7[0x15] = 0;
  puVar7[0x18] = 0;
  puVar7[0x17] = 0;
  puVar7[0x1a] = 0;
  puVar7[0x19] = 0;
  puVar7[0x1c] = 0;
  puVar7[0x1b] = 0;
  puVar7[0x1e] = 0;
  puVar7[0x1d] = 0;
  puVar7[0x20] = 0;
  puVar7[0x1f] = 0;
  puVar7[6] = 0;
  puVar7[5] = 0;
  puVar7[0x26] = 0;
  puVar7[0x25] = 0;
  puVar7[0x28] = 0;
  puVar7[0x27] = 0;
  puVar7[0x2a] = 0;
  puVar7[0x29] = 0;
  *puVar22 = puVar7;
  puVar11 = puVar7;
  if (**(long **)(lVar6 + 0x2610) != 0) {
    *(long *)(lVar6 + 0x2610) = **(long **)(lVar6 + 0x2610);
    puVar11 = (undefined8 *)*puVar22;
  }
  plVar5 = (long *)func_0x0040a8c0(*(undefined8 *)(lVar6 + 0x2618),puVar11);
  *(long *)(lVar6 + 0x2620) = *(long *)(lVar6 + 0x2620) + 1;
LAB_0044d7a0:
  if (*(int *)(puVar7 + 0x2a) == -1) {
LAB_0044d7dc:
    uVar12 = 0x1d;
  }
  else {
    lVar6 = func_0x007fd748();
    plVar5 = (long *)func_0x007fd748();
    iVar2 = (int)plVar5[0x881ca];
    puVar11 = *(undefined8 **)(lVar6 + 0x2618);
    if (*(undefined8 **)(lVar6 + 0x2618) == (undefined8 *)0x0) {
      puVar21 = (undefined8 *)(lVar6 + 0x2618);
      puVar22 = (undefined8 *)(lVar6 + 0x2618);
    }
    else {
      do {
        while (puVar7 = puVar11, puVar21 = puVar7, *(int *)(puVar7 + 4) <= iVar2) {
          if (iVar2 <= *(int *)(puVar7 + 4)) goto LAB_0044dbc8;
          puVar11 = (undefined8 *)puVar7[1];
          if ((undefined8 *)puVar7[1] == (undefined8 *)0x0) {
            puVar22 = puVar7 + 1;
            goto LAB_0044db24;
          }
        }
        puVar11 = (undefined8 *)*puVar7;
        puVar22 = puVar7;
      } while ((undefined8 *)*puVar7 != (undefined8 *)0x0);
    }
LAB_0044db24:
    puVar7 = (undefined8 *)func_0x00bc3330(0x160);
    puVar7[0x2b] = 0;
    *(int *)(puVar7 + 4) = iVar2;
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = puVar21;
    puVar7[0x22] = 0;
    puVar7[0x21] = 0;
    puVar7[0x24] = 0;
    puVar7[0x23] = 0;
    puVar7[8] = 0;
    puVar7[7] = 0;
    puVar7[10] = 0;
    puVar7[9] = 0;
    puVar7[0xc] = 0;
    puVar7[0xb] = 0;
    puVar7[0xe] = 0;
    puVar7[0xd] = 0;
    puVar7[0x10] = 0;
    puVar7[0xf] = 0;
    puVar7[0x12] = 0;
    puVar7[0x11] = 0;
    puVar7[0x14] = 0;
    puVar7[0x13] = 0;
    puVar7[0x16] = 0;
    puVar7[0x15] = 0;
    puVar7[0x18] = 0;
    puVar7[0x17] = 0;
    puVar7[0x1a] = 0;
    puVar7[0x19] = 0;
    puVar7[0x1c] = 0;
    puVar7[0x1b] = 0;
    puVar7[0x1e] = 0;
    puVar7[0x1d] = 0;
    puVar7[0x20] = 0;
    puVar7[0x1f] = 0;
    puVar7[6] = 0;
    puVar7[5] = 0;
    puVar7[0x26] = 0;
    puVar7[0x25] = 0;
    puVar7[0x28] = 0;
    puVar7[0x27] = 0;
    puVar7[0x2a] = 0;
    puVar7[0x29] = 0;
    *puVar22 = puVar7;
    puVar11 = puVar7;
    if (**(long **)(lVar6 + 0x2610) != 0) {
      *(long *)(lVar6 + 0x2610) = **(long **)(lVar6 + 0x2610);
      puVar11 = (undefined8 *)*puVar22;
    }
    plVar5 = (long *)func_0x0040a8c0(*(undefined8 *)(lVar6 + 0x2618),puVar11);
    *(long *)(lVar6 + 0x2620) = *(long *)(lVar6 + 0x2620) + 1;
LAB_0044dbc8:
    uVar12 = (ulong)*(uint *)(puVar7 + 0x2a);
  }
LAB_0044d7e0:
  unaff_x22 = (ulong)(int)uVar12;
  uVar14 = *(uint *)(plVar9[1] + (long)(int)uVar12 * 4);
  if (((uVar14 & 1) == 0) || ((char)plVar9[0x10] != '\0')) {
    if (((uVar14 >> 1 & 1) == 0) || (*(char *)((long)plVar9 + 0x81) != '\0')) {
LAB_0044dd5c:
      if ((*(uint *)(plVar9[1] + unaff_x22 * 4) >> 2 & 1) != 0) {
        uVar12 = unaff_x22 >> 3 & 0x1ffffffffffffff8;
        *(ulong *)(plVar9[0x11] + uVar12) =
             *(ulong *)(plVar9[0x11] + uVar12) | 1L << (unaff_x22 & 0x3f);
      }
    }
    else {
      lVar6 = unaff_x22 * 0x10;
      if (*(long *)(plVar9[8] + lVar6) != 0) {
        *(undefined4 *)(plVar9[0x15] + unaff_x22 * 4) = 100;
        if (*(long **)(plVar9[0xb] + lVar6) != (long *)0x0) {
          uVar12 = (**(code **)(**(long **)(plVar9[0xb] + lVar6) + 0x70))();
          lVar16 = plVar9[0xb];
          if ((uVar12 & 1) != 0) {
            (**(code **)(**(long **)(lVar16 + lVar6) + 0x90))();
            lVar16 = plVar9[0xb];
          }
LAB_0044dcf0:
          if ((*(uint *)(plVar9[1] + unaff_x22 * 4) >> 2 & 1) != 0) {
            (**(code **)(**(long **)(lVar16 + lVar6) + 0xb8))(*(long **)(lVar16 + lVar6),1);
            lVar16 = plVar9[0xb];
          }
          (**(code **)(**(long **)(lVar16 + lVar6) + 0xe8))
                    ((float)(*(int *)(plVar9[0x15] + unaff_x22 * 4) * *(int *)((long)plVar9 + 0xc4))
                     / 10000.0);
          plVar5 = (long *)(**(code **)(**(long **)(plVar9[0xb] + lVar6) + 0x90))();
          goto LAB_0044dd5c;
        }
        plVar5 = (long *)func_0x0044d358(plVar9,*(undefined4 *)(plVar9[4] + unaff_x22 * 4));
        if (((ulong)plVar5 & 1) != 0) {
          func_0x00bc3570(0xc0b818);
          func_0x00521e78(&uStack_80,plVar9[8] + unaff_x22 * 0x10,
                          *(undefined4 *)(plVar9[4] + unaff_x22 * 4));
          func_0x0044e2b0(plVar9[0xb] + lVar6,&uStack_80);
          func_0x0044e30c(&uStack_80);
          plVar5 = (long *)func_0x00bc3580(0xc0b818);
          lVar16 = plVar9[0xb];
          if (*(long *)(lVar16 + lVar6) != 0) goto LAB_0044dcf0;
        }
      }
    }
LAB_0044dd88:
    if (*(long *)(lVar17 + 0x28) == lStack_68) {
      return plVar5;
    }
    uVar12 = 0x44def0;
    auVar23 = func_0x00bc3380();
    ppuVar10 = extraout_x8;
  }
  else {
    uStack_80 = 0;
    uStack_78 = 0;
    uStack_70 = 0;
    func_0x005220d0(auStack_b8);
    abStack_e8[0] = 0x14;
    uStack_100._0_1_ = 6;
    abStack_e8[9] = 0x25;
    abStack_e8[10] = 0x73;
    abStack_e8[1] = 0x73;
    abStack_e8[2] = 0x6e;
    abStack_e8[3] = 100;
    abStack_e8[4] = 0x25;
    abStack_e8[5] = 0x30;
    abStack_e8[6] = 0x33;
    abStack_e8[7] = 100;
    abStack_e8[8] = 0x2e;
    abStack_e8[0xb] = 0;
    uStack_100._1_4_ = 0x67676f;
    ppuVar10 = &puStack_d0;
    auVar23._8_8_ = uVar12;
    auVar23._0_8_ = abStack_e8;
    puVar13 = &uStack_100;
    uVar12 = 0x44d854;
  }
  lVar17 = tpidr_el0;
  lStack_158 = *(long *)(lVar17 + 0x28);
  uStack_150 = &stack0xffffffffffffffa0;
  uStack_148 = uVar12;
  uStack_140 = unaff_x22;
  uStack_138 = unaff_x21;
  uStack_130 = unaff_x20;
  plStack_128 = plVar9;
  if ((*puVar13 & 1) == 0) {
    uStack_188 = puVar13[1];
    uStack_190 = *puVar13;
    uStack_180 = puVar13[2];
    if ((uStack_190 & 1) != 0) goto LAB_0044df3c;
LAB_0044df60:
    uStack_168 = uStack_188;
    uStack_170 = uStack_190;
    uStack_160 = uStack_180;
  }
  else {
    func_0x0040a850(&uStack_190,puVar13[2],puVar13[1]);
    if ((uStack_190 & 1) == 0) goto LAB_0044df60;
LAB_0044df3c:
    func_0x0040a850(&uStack_170,uStack_180,uStack_188);
  }
  plVar9 = (long *)func_0x0044ede8(ppuVar10,auVar23._0_8_,0,auVar23._8_8_ & 0xffffffff,&uStack_170);
  if ((uStack_170 & 1) != 0) {
    plVar9 = (long *)func_0x00bc3350(uStack_160);
  }
  if ((uStack_190 & 1) != 0) {
    plVar9 = (long *)func_0x00bc3350(uStack_180);
  }
  if (*(long *)(lVar17 + 0x28) == lStack_158) {
    return plVar9;
  }
  auVar24 = func_0x00bc3380();
  uVar12 = auVar24._8_8_;
  puVar8 = auVar24._0_8_;
  if (((auVar24._8_4_ ^ 0xffffffff) & 0xfffffffd) == 0) {
LAB_0044e048:
    plVar9 = *(long **)(puVar8 + 0x1c);
    if (plVar9 != (long *)0x0) {
      for (puVar11 = *(undefined8 **)(puVar8 + 0x16); puVar11 != *(undefined8 **)(puVar8 + 0x18);
          puVar11 = puVar11 + 2) {
        if ((long *)*puVar11 == plVar9) {
          uVar12 = uVar12 & 0xffffffff;
          plVar9 = (long *)(**(code **)(*plVar9 + 0xf8))();
          plVar5 = (long *)puVar11[1];
          *puVar11 = 0;
          puVar11[1] = 0;
          if ((plVar5 != (long *)0x0) &&
             (plVar9 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), plVar9 == (long *)0x0
             )) {
            (**(code **)(*plVar5 + 0x10))(plVar5);
            plVar9 = (long *)func_0x00bc3320(plVar5);
          }
          plVar5 = *(long **)(puVar8 + 0x1e);
          puVar8[0x1c] = 0;
          puVar8[0x1d] = 0;
          puVar8[0x1e] = 0;
          puVar8[0x1f] = 0;
          if ((plVar5 != (long *)0x0) &&
             (plVar9 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), plVar9 == (long *)0x0
             )) {
            (**(code **)(*plVar5 + 0x10))(plVar5);
            plVar9 = (long *)func_0x00bc3320(plVar5);
          }
          break;
        }
      }
    }
    auVar4._8_8_ = uVar12;
    auVar4._0_8_ = plVar9;
    auVar24._8_8_ = uVar12;
    auVar24._0_8_ = plVar9;
    uVar14 = *puVar8;
    if (0 < (int)uVar14) {
      lVar17 = *(long *)(puVar8 + 2);
      lVar6 = *(long *)(puVar8 + 0x22);
      uVar12 = 0;
      do {
        if ((*(uint *)(lVar17 + uVar12 * 4) & 1) != 0) {
          uVar18 = uVar12 >> 3 & 0x1ffffffffffffff8;
          *(ulong *)(lVar6 + uVar18) =
               *(ulong *)(lVar6 + uVar18) & (1L << (uVar12 & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar12 = uVar12 + 1;
        auVar24 = auVar4;
      } while (uVar14 != uVar12);
    }
  }
  else if (-1 < (int)auVar24._8_4_) {
    uVar14 = *(uint *)(*(long *)(puVar8 + 2) + (uVar12 & 0xffffffff) * 4);
    if ((uVar14 & 1) == 0) goto LAB_0044e194;
    goto LAB_0044e048;
  }
  plVar9 = auVar24._0_8_;
  if (auVar24._8_4_ + 3U < 2) {
    uVar14 = *puVar8;
    if ((int)uVar14 < 1) {
      return plVar9;
    }
    lVar17 = 0;
    lVar6 = 0;
    uVar12 = 0;
    do {
      if (((*(byte *)(*(long *)(puVar8 + 2) + lVar6) >> 1 & 1) != 0) &&
         (plVar9 = *(long **)(*(long *)(puVar8 + 0x16) + lVar17), plVar9 != (long *)0x0)) {
        plVar9 = (long *)(**(code **)(*plVar9 + 0xf8))();
        puVar11 = (undefined8 *)(*(long *)(puVar8 + 0x16) + lVar17);
        plVar5 = (long *)puVar11[1];
        *puVar11 = 0;
        puVar11[1] = 0;
        if ((plVar5 != (long *)0x0) &&
           (plVar9 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), plVar9 == (long *)0x0))
        {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          plVar9 = (long *)func_0x00bc3320(plVar5);
        }
        uVar18 = uVar12 >> 3 & 0x1ffffffffffffff8;
        uVar14 = *puVar8;
        *(ulong *)(*(long *)(puVar8 + 0x22) + uVar18) =
             *(ulong *)(*(long *)(puVar8 + 0x22) + uVar18) &
             (1L << (uVar12 & 0x3f) ^ 0xffffffffffffffffU);
      }
      uVar12 = uVar12 + 1;
      lVar17 = lVar17 + 0x10;
      lVar6 = lVar6 + 4;
    } while ((long)uVar12 < (long)(int)uVar14);
    return plVar9;
  }
  if (auVar24._8_4_ < 0) {
    return plVar9;
  }
  uVar14 = *(uint *)(*(long *)(puVar8 + 2) + (auVar24._8_8_ & 0xffffffff) * 4);
LAB_0044e194:
  plVar9 = auVar24._0_8_;
  uVar12 = auVar24._8_8_ & 0xffffffff;
  if ((uVar14 >> 1 & 1) != 0) {
    plVar5 = *(long **)(*(long *)(puVar8 + 0x16) + uVar12 * 0x10);
    plVar9 = (long *)0x0;
    if (plVar5 != (long *)0x0) {
      plVar9 = (long *)(**(code **)(*plVar5 + 0xf8))();
      puVar11 = (undefined8 *)(*(long *)(puVar8 + 0x16) + uVar12 * 0x10);
      plVar5 = (long *)puVar11[1];
      *puVar11 = 0;
      puVar11[1] = 0;
      if ((plVar5 != (long *)0x0) &&
         (plVar9 = (long *)func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), plVar9 == (long *)0x0)) {
        (**(code **)(*plVar5 + 0x10))(plVar5);
        plVar9 = (long *)func_0x00bc3320(plVar5);
      }
      uVar12 = uVar12 >> 3 & 0x1ffffff8;
      *(ulong *)(*(long *)(puVar8 + 0x22) + uVar12) =
           *(ulong *)(*(long *)(puVar8 + 0x22) + uVar12) &
           (1L << (auVar24._8_8_ & 0x3f) ^ 0xffffffffffffffffU);
    }
  }
  return plVar9;
}


