// Target Address: 0x960488
// Function: Unit_ApplyHPChange_0x960488
// Decompiled by Ghidra 12.1.4 Headless

/* WARNING: Possible PIC construction at 0x009604a8: Changing call to branch */
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
/* WARNING: Removing unreachable block (ram,0x009604ac) */
/* WARNING: Removing unreachable block (ram,0x00866804) */
/* WARNING: Removing unreachable block (ram,0x00866878) */
/* WARNING: Removing unreachable block (ram,0x00866888) */
/* WARNING: Removing unreachable block (ram,0x00866840) */
/* WARNING: Removing unreachable block (ram,0x0086688c) */
/* WARNING: Removing unreachable block (ram,0x00866868) */
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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Unit_ApplyHPChange_0x960488(undefined8 param_1,long *param_2,undefined8 param_3,int *param_4)

{
  int iVar1;
  long lVar2;
  uint *puVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  int in_w8;
  long *plVar11;
  undefined1 *extraout_x8;
  undefined1 *puVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  undefined8 unaff_x20;
  byte *pbVar16;
  byte *unaff_x21;
  ulong unaff_x22;
  undefined8 *puVar17;
  undefined8 *unaff_x23;
  undefined8 *unaff_x24;
  undefined8 unaff_x25;
  undefined8 unaff_x26;
  undefined8 unaff_x27;
  undefined8 unaff_x28;
  undefined8 unaff_x29;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  if ((in_w8 == 2) && (*param_4 == 0)) {
    lVar15 = *param_2;
    lVar5 = func_0x0044c16c();
    uVar7 = 0xb;
    uVar18 = 0x9604ac;
  }
  else {
    if (in_w8 != 1) {
      return;
    }
    lVar5 = func_0x0044c16c();
    uVar7 = 0x1d;
    register0x00000008 = (BADSPACEBASE *)&stack0x00000020;
    lVar15 = in_stack_00000010;
    unaff_x29 = in_stack_00000000;
    uVar18 = in_stack_00000008;
  }
  pbVar9 = (byte *)0x0;
  *(undefined8 *)((long)register0x00000008 + -0x60) = unaff_x29;
  *(undefined8 *)((long)register0x00000008 + -0x58) = uVar18;
  *(undefined8 *)((long)register0x00000008 + -0x50) = unaff_x28;
  *(undefined8 *)((long)register0x00000008 + -0x48) = unaff_x27;
  *(undefined8 *)((long)register0x00000008 + -0x40) = unaff_x26;
  *(undefined8 *)((long)register0x00000008 + -0x38) = unaff_x25;
  *(undefined8 **)((long)register0x00000008 + -0x30) = unaff_x24;
  *(undefined8 **)((long)register0x00000008 + -0x28) = unaff_x23;
  *(ulong *)((long)register0x00000008 + -0x20) = unaff_x22;
  *(byte **)((long)register0x00000008 + -0x18) = unaff_x21;
  *(undefined8 *)((long)register0x00000008 + -0x10) = unaff_x20;
  *(long *)((long)register0x00000008 + -8) = lVar15;
  lVar4 = tpidr_el0;
  *(undefined8 *)((long)register0x00000008 + -0x68) = *(undefined8 *)(lVar4 + 0x28);
  if ((ulong)(long)(int)uVar7 < (ulong)(*(long *)(lVar5 + 0x10) - *(long *)(lVar5 + 8) >> 2)) {
    unaff_x20 = 0;
    pbVar16 = (byte *)0x0;
    pbVar8 = pbVar9;
    if ((int)uVar7 == 0x1d) {
      lVar15 = func_0x007fd748();
      if (*(int *)(&LAB_00440e50 + lVar15) != -1) {
        lVar15 = func_0x007fd748();
        lVar2 = func_0x007fd748();
        plVar11 = *(long **)(lVar15 + 0x2618);
        if (plVar11 != (long *)0x0) {
          do {
            if ((int)plVar11[4] <= *(int *)(&LAB_00440e50 + lVar2)) {
              if (*(int *)(&LAB_00440e50 + lVar2) <= (int)plVar11[4]) {
                lVar15 = func_0x007fd748();
                lVar2 = func_0x007fd748();
                iVar1 = *(int *)(&LAB_00440e50 + lVar2);
                puVar6 = *(undefined8 **)(lVar15 + 0x2618);
                if (*(undefined8 **)(lVar15 + 0x2618) != (undefined8 *)0x0) goto LAB_0044d6d8;
                puVar17 = (undefined8 *)(lVar15 + 0x2618);
                unaff_x24 = (undefined8 *)(lVar15 + 0x2618);
                goto LAB_0044d6fc;
              }
              plVar11 = plVar11 + 1;
            }
            plVar11 = (long *)*plVar11;
          } while (plVar11 != (long *)0x0);
        }
      }
      goto LAB_0044d7dc;
    }
    goto LAB_0044d7e0;
  }
  *(undefined2 *)((long)register0x00000008 + -0x80) = 0;
  func_0x0056a6f0((undefined1 *)((long)register0x00000008 + -0x80),3);
  pbVar8 = pbVar9;
  lVar5 = lVar15;
  if ((*(byte *)((long)register0x00000008 + -0x80) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x70));
    pbVar8 = pbVar9;
  }
  goto LAB_0044dd88;
  while( true ) {
    if (iVar1 <= *(int *)(unaff_x23 + 4)) goto LAB_0044d7a0;
    puVar6 = (undefined8 *)unaff_x23[1];
    if ((undefined8 *)unaff_x23[1] == (undefined8 *)0x0) break;
LAB_0044d6d8:
    unaff_x23 = puVar6;
    puVar17 = unaff_x23;
    if (iVar1 < *(int *)(unaff_x23 + 4)) {
      puVar6 = (undefined8 *)*unaff_x23;
      unaff_x24 = unaff_x23;
      if ((undefined8 *)*unaff_x23 == (undefined8 *)0x0) goto LAB_0044d6fc;
      goto LAB_0044d6d8;
    }
  }
  unaff_x24 = unaff_x23 + 1;
LAB_0044d6fc:
  unaff_x23 = (undefined8 *)func_0x00bc3330(0x160);
  unaff_x23[0x2b] = 0;
  *(int *)(unaff_x23 + 4) = iVar1;
  *unaff_x23 = 0;
  unaff_x23[1] = 0;
  unaff_x23[2] = puVar17;
  unaff_x23[0x22] = 0;
  unaff_x23[0x21] = 0;
  unaff_x23[0x24] = 0;
  unaff_x23[0x23] = 0;
  unaff_x23[8] = 0;
  unaff_x23[7] = 0;
  unaff_x23[10] = 0;
  unaff_x23[9] = 0;
  unaff_x23[0xc] = 0;
  unaff_x23[0xb] = 0;
  unaff_x23[0xe] = 0;
  unaff_x23[0xd] = 0;
  unaff_x23[0x10] = 0;
  unaff_x23[0xf] = 0;
  unaff_x23[0x12] = 0;
  unaff_x23[0x11] = 0;
  unaff_x23[0x14] = 0;
  unaff_x23[0x13] = 0;
  unaff_x23[0x16] = 0;
  unaff_x23[0x15] = 0;
  unaff_x23[0x18] = 0;
  unaff_x23[0x17] = 0;
  unaff_x23[0x1a] = 0;
  unaff_x23[0x19] = 0;
  unaff_x23[0x1c] = 0;
  unaff_x23[0x1b] = 0;
  unaff_x23[0x1e] = 0;
  unaff_x23[0x1d] = 0;
  unaff_x23[0x20] = 0;
  unaff_x23[0x1f] = 0;
  unaff_x23[6] = 0;
  unaff_x23[5] = 0;
  unaff_x23[0x26] = 0;
  unaff_x23[0x25] = 0;
  unaff_x23[0x28] = 0;
  unaff_x23[0x27] = 0;
  unaff_x23[0x2a] = 0;
  unaff_x23[0x29] = 0;
  *unaff_x24 = unaff_x23;
  puVar6 = unaff_x23;
  if (**(long **)(lVar15 + 0x2610) != 0) {
    *(long *)(lVar15 + 0x2610) = **(long **)(lVar15 + 0x2610);
    puVar6 = (undefined8 *)*unaff_x24;
  }
  func_0x0040a8c0(*(undefined8 *)(lVar15 + 0x2618),puVar6);
  *(long *)(lVar15 + 0x2620) = *(long *)(lVar15 + 0x2620) + 1;
LAB_0044d7a0:
  if (*(int *)(unaff_x23 + 0x2a) == -1) {
LAB_0044d7dc:
    uVar7 = 0x1d;
  }
  else {
    lVar15 = func_0x007fd748();
    lVar2 = func_0x007fd748();
    iVar1 = *(int *)(&LAB_00440e50 + lVar2);
    puVar6 = *(undefined8 **)(lVar15 + 0x2618);
    if (*(undefined8 **)(lVar15 + 0x2618) == (undefined8 *)0x0) {
      puVar17 = (undefined8 *)(lVar15 + 0x2618);
      unaff_x24 = (undefined8 *)(lVar15 + 0x2618);
    }
    else {
      do {
        while (unaff_x23 = puVar6, puVar17 = unaff_x23, iVar1 < *(int *)(unaff_x23 + 4)) {
          puVar6 = (undefined8 *)*unaff_x23;
          unaff_x24 = unaff_x23;
          if ((undefined8 *)*unaff_x23 == (undefined8 *)0x0) goto LAB_0044db24;
        }
        if (iVar1 <= *(int *)(unaff_x23 + 4)) goto LAB_0044dbc8;
        puVar6 = (undefined8 *)unaff_x23[1];
      } while ((undefined8 *)unaff_x23[1] != (undefined8 *)0x0);
      unaff_x24 = unaff_x23 + 1;
    }
LAB_0044db24:
    unaff_x23 = (undefined8 *)func_0x00bc3330(0x160);
    unaff_x23[0x2b] = 0;
    *(int *)(unaff_x23 + 4) = iVar1;
    *unaff_x23 = 0;
    unaff_x23[1] = 0;
    unaff_x23[2] = puVar17;
    unaff_x23[0x22] = 0;
    unaff_x23[0x21] = 0;
    unaff_x23[0x24] = 0;
    unaff_x23[0x23] = 0;
    unaff_x23[8] = 0;
    unaff_x23[7] = 0;
    unaff_x23[10] = 0;
    unaff_x23[9] = 0;
    unaff_x23[0xc] = 0;
    unaff_x23[0xb] = 0;
    unaff_x23[0xe] = 0;
    unaff_x23[0xd] = 0;
    unaff_x23[0x10] = 0;
    unaff_x23[0xf] = 0;
    unaff_x23[0x12] = 0;
    unaff_x23[0x11] = 0;
    unaff_x23[0x14] = 0;
    unaff_x23[0x13] = 0;
    unaff_x23[0x16] = 0;
    unaff_x23[0x15] = 0;
    unaff_x23[0x18] = 0;
    unaff_x23[0x17] = 0;
    unaff_x23[0x1a] = 0;
    unaff_x23[0x19] = 0;
    unaff_x23[0x1c] = 0;
    unaff_x23[0x1b] = 0;
    unaff_x23[0x1e] = 0;
    unaff_x23[0x1d] = 0;
    unaff_x23[0x20] = 0;
    unaff_x23[0x1f] = 0;
    unaff_x23[6] = 0;
    unaff_x23[5] = 0;
    unaff_x23[0x26] = 0;
    unaff_x23[0x25] = 0;
    unaff_x23[0x28] = 0;
    unaff_x23[0x27] = 0;
    unaff_x23[0x2a] = 0;
    unaff_x23[0x29] = 0;
    *unaff_x24 = unaff_x23;
    puVar6 = unaff_x23;
    if (**(long **)(lVar15 + 0x2610) != 0) {
      *(long *)(lVar15 + 0x2610) = **(long **)(lVar15 + 0x2610);
      puVar6 = (undefined8 *)*unaff_x24;
    }
    func_0x0040a8c0(*(undefined8 *)(lVar15 + 0x2618),puVar6);
    *(long *)(lVar15 + 0x2620) = *(long *)(lVar15 + 0x2620) + 1;
LAB_0044dbc8:
    uVar7 = (ulong)*(uint *)(unaff_x23 + 0x2a);
  }
LAB_0044d7e0:
  unaff_x22 = (ulong)(int)uVar7;
  uVar10 = *(uint *)(*(long *)(lVar5 + 8) + (long)(int)uVar7 * 4);
  if (((uVar10 & 1) == 0) || (*(char *)(lVar5 + 0x80) != '\0')) {
    unaff_x21 = pbVar16;
    if (((uVar10 >> 1 & 1) == 0) || (*(char *)(lVar5 + 0x81) != '\0')) {
LAB_0044dd5c:
      unaff_x21 = pbVar9;
      if ((*(uint *)(*(long *)(lVar5 + 8) + unaff_x22 * 4) >> 2 & 1) != 0) {
        uVar7 = unaff_x22 >> 3 & 0x1ffffffffffffff8;
        *(ulong *)(*(long *)(lVar5 + 0x88) + uVar7) =
             *(ulong *)(*(long *)(lVar5 + 0x88) + uVar7) | 1L << (unaff_x22 & 0x3f);
        unaff_x21 = pbVar16;
      }
    }
    else {
      unaff_x23 = (undefined8 *)(unaff_x22 * 0x10);
      if (*(long *)(*(long *)(lVar5 + 0x40) + (long)unaff_x23) != 0) {
        *(undefined4 *)(*(long *)(lVar5 + 0xa8) + unaff_x22 * 4) = 100;
        plVar11 = *(long **)(*(long *)(lVar5 + 0x58) + (long)unaff_x23);
        if (plVar11 != (long *)0x0) {
          uVar7 = (**(code **)(*plVar11 + 0x70))();
          lVar15 = *(long *)(lVar5 + 0x58);
          if ((uVar7 & 1) != 0) {
            (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0x90))();
            lVar15 = *(long *)(lVar5 + 0x58);
          }
LAB_0044dcf0:
          if ((*(uint *)(*(long *)(lVar5 + 8) + unaff_x22 * 4) >> 2 & 1) != 0) {
            (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0xb8))
                      (*(long **)(lVar15 + (long)unaff_x23),1);
            lVar15 = *(long *)(lVar5 + 0x58);
          }
          (**(code **)(**(long **)(lVar15 + (long)unaff_x23) + 0xe8))
                    ((float)(*(int *)(*(long *)(lVar5 + 0xa8) + unaff_x22 * 4) *
                            *(int *)(lVar5 + 0xc4)) / 10000.0);
          (**(code **)(**(long **)(*(long *)(lVar5 + 0x58) + (long)unaff_x23) + 0x90))();
          goto LAB_0044dd5c;
        }
        uVar7 = func_0x0044d358(lVar5,*(undefined4 *)(*(long *)(lVar5 + 0x20) + unaff_x22 * 4));
        if ((uVar7 & 1) != 0) {
          func_0x00bc3570(0xc0b818);
          func_0x00521e78((undefined1 *)((long)register0x00000008 + -0x80),
                          *(long *)(lVar5 + 0x40) + unaff_x22 * 0x10,
                          *(undefined4 *)(*(long *)(lVar5 + 0x20) + unaff_x22 * 4));
          func_0x0044e2b0(*(long *)(lVar5 + 0x58) + (long)unaff_x23,
                          (undefined1 *)((long)register0x00000008 + -0x80));
          func_0x0044e30c((undefined1 *)((long)register0x00000008 + -0x80));
          func_0x00bc3580(0xc0b818);
          lVar15 = *(long *)(lVar5 + 0x58);
          if (*(long *)(lVar15 + (long)unaff_x23) != 0) goto LAB_0044dcf0;
        }
      }
    }
LAB_0044dd88:
    pbVar9 = unaff_x21;
    if (*(long *)(lVar4 + 0x28) == *(long *)((long)register0x00000008 + -0x68)) {
      return;
    }
    uVar18 = 0x44def0;
    auVar20 = func_0x00bc3380();
    puVar12 = extraout_x8;
  }
  else {
    *(undefined8 *)((long)register0x00000008 + -0x80) = 0;
    *(undefined8 *)((long)register0x00000008 + -0x78) = 0;
    *(undefined8 *)((long)register0x00000008 + -0x70) = 0;
    func_0x005220d0((undefined1 *)((long)register0x00000008 + -0xb8));
    *(undefined1 *)((long)register0x00000008 + -0xe8) = 0x14;
    *(undefined1 *)((long)register0x00000008 + -0x100) = 6;
    *(undefined2 *)((long)register0x00000008 + -0xdf) = 0x7325;
    *(undefined8 *)((long)register0x00000008 + -0xe7) = _UNK_00289988;
    *(undefined1 *)((long)register0x00000008 + -0xdd) = 0;
    *(undefined4 *)((long)register0x00000008 + -0xff) = 0x67676f;
    puVar12 = (undefined1 *)((long)register0x00000008 + -0xd0);
    auVar20._8_8_ = uVar7;
    auVar20._0_8_ = (undefined1 *)((long)register0x00000008 + -0xe8);
    pbVar8 = (byte *)((long)register0x00000008 + -0x100);
    uVar18 = 0x44d854;
  }
  *(undefined1 **)((long)register0x00000008 + -0x150) =
       (undefined1 *)((long)register0x00000008 + -0x60);
  *(undefined8 *)((long)register0x00000008 + -0x148) = uVar18;
  *(ulong *)((long)register0x00000008 + -0x140) = unaff_x22;
  *(byte **)((long)register0x00000008 + -0x138) = pbVar9;
  *(undefined8 *)((long)register0x00000008 + -0x130) = unaff_x20;
  *(long *)((long)register0x00000008 + -0x128) = lVar5;
  lVar5 = tpidr_el0;
  uVar7 = auVar20._8_8_ & 0xffffffff;
  *(undefined8 *)((long)register0x00000008 + -0x158) = *(undefined8 *)(lVar5 + 0x28);
  if ((*pbVar8 & 1) == 0) {
    uVar19 = *(undefined8 *)pbVar8;
    uVar18 = *(undefined8 *)(pbVar8 + 0x10);
    *(undefined8 *)((long)register0x00000008 + -0x188) = *(undefined8 *)(pbVar8 + 8);
    *(undefined8 *)((long)register0x00000008 + -400) = uVar19;
    *(undefined8 *)((long)register0x00000008 + -0x180) = uVar18;
    if ((*(byte *)((long)register0x00000008 + -400) & 1) == 0) goto LAB_0044df60;
LAB_0044df3c:
    func_0x0040a850((undefined1 *)((long)register0x00000008 + -0x170),
                    *(undefined8 *)((long)register0x00000008 + -0x180),
                    *(undefined8 *)((long)register0x00000008 + -0x188));
  }
  else {
    func_0x0040a850((undefined1 *)((long)register0x00000008 + -400),*(undefined8 *)(pbVar8 + 0x10),
                    *(undefined8 *)(pbVar8 + 8));
    if ((*(byte *)((long)register0x00000008 + -400) & 1) != 0) goto LAB_0044df3c;
LAB_0044df60:
    *(undefined8 *)((long)register0x00000008 + -0x168) =
         *(undefined8 *)((long)register0x00000008 + -0x188);
    *(undefined8 *)((long)register0x00000008 + -0x170) =
         *(undefined8 *)((long)register0x00000008 + -400);
    *(undefined8 *)((long)register0x00000008 + -0x160) =
         *(undefined8 *)((long)register0x00000008 + -0x180);
  }
  func_0x0044ede8(puVar12,auVar20._0_8_,0,uVar7,(undefined1 *)((long)register0x00000008 + -0x170));
  if ((*(byte *)((long)register0x00000008 + -0x170) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x160));
  }
  if ((*(byte *)((long)register0x00000008 + -400) & 1) != 0) {
    func_0x00bc3350(*(undefined8 *)((long)register0x00000008 + -0x180));
  }
  if (*(long *)(lVar5 + 0x28) == *(long *)((long)register0x00000008 + -0x158)) {
    return;
  }
  auVar21 = func_0x00bc3380();
  uVar13 = auVar21._8_8_;
  puVar3 = auVar21._0_8_;
  *(undefined1 **)((long)register0x00000008 + -0x1d0) =
       (undefined1 *)((long)register0x00000008 + -0x150);
  *(undefined8 *)((long)register0x00000008 + -0x1c8) = 0x44e014;
  *(undefined8 **)((long)register0x00000008 + -0x1c0) = unaff_x24;
  *(undefined8 **)((long)register0x00000008 + -0x1b8) = unaff_x23;
  *(long *)((long)register0x00000008 + -0x1b0) = lVar5;
  *(undefined1 **)((long)register0x00000008 + -0x1a8) = puVar12;
  *(long *)((long)register0x00000008 + -0x1a0) = auVar20._0_8_;
  *(ulong *)((long)register0x00000008 + -0x198) = uVar7;
  if (((auVar21._8_4_ ^ 0xffffffff) & 0xfffffffd) == 0) {
LAB_0044e048:
    plVar11 = *(long **)(puVar3 + 0x1c);
    if (plVar11 != (long *)0x0) {
      for (puVar6 = *(undefined8 **)(puVar3 + 0x16); puVar6 != *(undefined8 **)(puVar3 + 0x18);
          puVar6 = puVar6 + 2) {
        if ((long *)*puVar6 == plVar11) {
          uVar13 = uVar13 & 0xffffffff;
          (**(code **)(*plVar11 + 0xf8))();
          plVar11 = (long *)puVar6[1];
          *puVar6 = 0;
          puVar6[1] = 0;
          if ((plVar11 != (long *)0x0) &&
             (lVar5 = func_0x00bbf1b0(0xffffffffffffffff,plVar11 + 1), lVar5 == 0)) {
            (**(code **)(*plVar11 + 0x10))(plVar11);
            func_0x00bc3320(plVar11);
          }
          plVar11 = *(long **)(puVar3 + 0x1e);
          puVar3[0x1c] = 0;
          puVar3[0x1d] = 0;
          puVar3[0x1e] = 0;
          puVar3[0x1f] = 0;
          if ((plVar11 != (long *)0x0) &&
             (lVar5 = func_0x00bbf1b0(0xffffffffffffffff,plVar11 + 1), lVar5 == 0)) {
            (**(code **)(*plVar11 + 0x10))(plVar11);
            func_0x00bc3320(plVar11);
          }
          break;
        }
      }
    }
    uVar10 = *puVar3;
    if (0 < (int)uVar10) {
      lVar5 = *(long *)(puVar3 + 2);
      lVar15 = *(long *)(puVar3 + 0x22);
      uVar7 = 0;
      do {
        if ((*(uint *)(lVar5 + uVar7 * 4) & 1) != 0) {
          uVar14 = uVar7 >> 3 & 0x1ffffffffffffff8;
          *(ulong *)(lVar15 + uVar14) =
               *(ulong *)(lVar15 + uVar14) & (1L << (uVar7 & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar7 = uVar7 + 1;
      } while (uVar10 != uVar7);
    }
  }
  else if (-1 < (int)auVar21._8_4_) {
    uVar10 = *(uint *)(*(long *)(puVar3 + 2) + (uVar13 & 0xffffffff) * 4);
    if ((uVar10 & 1) == 0) goto LAB_0044e194;
    goto LAB_0044e048;
  }
  if ((int)uVar13 + 3U < 2) {
    uVar10 = *puVar3;
    if ((int)uVar10 < 1) {
      return;
    }
    lVar5 = 0;
    lVar15 = 0;
    uVar7 = 0;
    do {
      if (((*(byte *)(*(long *)(puVar3 + 2) + lVar15) >> 1 & 1) != 0) &&
         (*(long **)(*(long *)(puVar3 + 0x16) + lVar5) != (long *)0x0)) {
        (**(code **)(**(long **)(*(long *)(puVar3 + 0x16) + lVar5) + 0xf8))();
        puVar6 = (undefined8 *)(*(long *)(puVar3 + 0x16) + lVar5);
        plVar11 = (long *)puVar6[1];
        *puVar6 = 0;
        puVar6[1] = 0;
        if ((plVar11 != (long *)0x0) &&
           (lVar4 = func_0x00bbf1b0(0xffffffffffffffff,plVar11 + 1), lVar4 == 0)) {
          (**(code **)(*plVar11 + 0x10))(plVar11);
          func_0x00bc3320(plVar11);
        }
        uVar13 = uVar7 >> 3 & 0x1ffffffffffffff8;
        uVar10 = *puVar3;
        *(ulong *)(*(long *)(puVar3 + 0x22) + uVar13) =
             *(ulong *)(*(long *)(puVar3 + 0x22) + uVar13) &
             (1L << (uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      }
      uVar7 = uVar7 + 1;
      lVar5 = lVar5 + 0x10;
      lVar15 = lVar15 + 4;
    } while ((long)uVar7 < (long)(int)uVar10);
    return;
  }
  if ((int)uVar13 < 0) {
    return;
  }
  uVar10 = *(uint *)(*(long *)(puVar3 + 2) + (uVar13 & 0xffffffff) * 4);
LAB_0044e194:
  uVar7 = uVar13 & 0xffffffff;
  if (((uVar10 >> 1 & 1) != 0) &&
     (plVar11 = *(long **)(*(long *)(puVar3 + 0x16) + uVar7 * 0x10), plVar11 != (long *)0x0)) {
    (**(code **)(*plVar11 + 0xf8))();
    puVar6 = (undefined8 *)(*(long *)(puVar3 + 0x16) + uVar7 * 0x10);
    plVar11 = (long *)puVar6[1];
    *puVar6 = 0;
    puVar6[1] = 0;
    if ((plVar11 != (long *)0x0) &&
       (lVar5 = func_0x00bbf1b0(0xffffffffffffffff,plVar11 + 1), lVar5 == 0)) {
      (**(code **)(*plVar11 + 0x10))(plVar11);
      func_0x00bc3320(plVar11);
    }
    uVar7 = uVar7 >> 3 & 0x1ffffff8;
    *(ulong *)(*(long *)(puVar3 + 0x22) + uVar7) =
         *(ulong *)(*(long *)(puVar3 + 0x22) + uVar7) &
         (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
  }
  return;
}


