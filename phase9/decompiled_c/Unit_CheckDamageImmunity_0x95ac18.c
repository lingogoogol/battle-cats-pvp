// Target Address: 0x95ac18
// Function: Unit_CheckDamageImmunity_0x95ac18
// Decompiled by Ghidra 12.1.4 Headless

void Unit_CheckDamageImmunity_0x95ac18(undefined8 param_1,undefined8 param_2,ulong *param_3)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  long *plVar15;
  long lVar16;
  ulong *puVar17;
  ulong *puVar18;
  ulong uVar19;
  ulong uVar20;
  ulong *puVar21;
  long *unaff_x19;
  ulong *puVar22;
  ulong *puVar23;
  long *plVar24;
  long *unaff_x21;
  long *plVar25;
  undefined8 *puVar26;
  long *unaff_x24;
  long *unaff_x25;
  ulong unaff_x27;
  ulong *puVar27;
  long unaff_x29;
  ulong uVar28;
  ulong uVar29;
  undefined8 uVar30;
  ulong uVar31;
  undefined1 auVar32 [16];
  undefined1 auVar33 [12];
  long in_stack_00000000;
  long *in_stack_00000008;
  long *in_stack_00000010;
  long in_stack_00000018;
  ulong *in_stack_00000020;
  ulong *in_stack_00000028;
  ulong *in_stack_00000030;
  long *plStack_78;
  long *plStack_70;
  long lStack_68;
  
code_r0x0095ac18:
  func_0x00bc3320(unaff_x21);
  plVar25 = unaff_x24;
LAB_0095aa5c:
  puVar23 = in_stack_00000020;
  unaff_x24 = plVar25 + 2;
  if (unaff_x24 != unaff_x25) {
    plVar24 = (long *)*unaff_x24;
    unaff_x21 = (long *)plVar25[3];
    in_stack_00000008 = plVar24;
    in_stack_00000010 = unaff_x21;
    puVar17 = in_stack_00000020;
    puVar22 = in_stack_00000028;
    if (unaff_x21 != (long *)0x0) {
      func_0x00bbf180(1,unaff_x21 + 1);
      puVar23 = in_stack_00000020;
      puVar17 = in_stack_00000020;
      puVar22 = in_stack_00000028;
    }
    for (; puVar27 = in_stack_00000028, puVar5 = in_stack_00000020, in_stack_00000020 = puVar17,
        puVar23 != in_stack_00000028; puVar23 = puVar23 + 1) {
      uVar9 = *puVar23;
      in_stack_00000028 = puVar22;
      iVar6 = func_0x00961dd4(plVar24);
      puVar17 = in_stack_00000028;
      if ((int)uVar9 == iVar6) goto LAB_0095abf4;
      puVar17 = in_stack_00000020;
      puVar22 = in_stack_00000028;
      in_stack_00000028 = puVar27;
      in_stack_00000020 = puVar5;
    }
    in_stack_00000028 = puVar22;
    iVar6 = func_0x009636d8(plVar24);
    puVar17 = in_stack_00000028;
    if (iVar6 != 0) {
      uVar9 = func_0x00961dd4(plVar24);
      lVar10 = func_0x009636c8(plVar24);
      uVar9 = uVar9 & 0xffffffff | lVar10 << 0x20;
      if (puVar27 < in_stack_00000030) {
        *puVar27 = uVar9;
        unaff_x21 = in_stack_00000010;
        puVar17 = puVar27 + 1;
      }
      else {
        lVar10 = (long)puVar27 - (long)puVar5;
        uVar12 = (lVar10 >> 3) + 1;
        if (uVar12 >> 0x3d != 0) {
          if (*(long *)(in_stack_00000000 + 0x28) == *(long *)(unaff_x29 + -8)) {
            func_0x00682730(&stack0x00000020);
LAB_0095af24:
            if (*(long *)(in_stack_00000000 + 0x28) == *(long *)(unaff_x29 + -8)) {
              func_0x0040fc1c();
              in_stack_00000000 = lVar10;
              goto LAB_0095af3c;
            }
          }
          goto LAB_0095afc8;
        }
        uVar19 = (long)in_stack_00000030 - (long)puVar5 >> 2;
        if (uVar19 <= uVar12) {
          uVar19 = uVar12;
        }
        if (0x7ffffffffffffff7 < (ulong)((long)in_stack_00000030 - (long)puVar5)) {
          uVar19 = unaff_x27;
        }
        if (uVar19 == 0) {
          lVar11 = 0;
        }
        else {
          if (uVar19 >> 0x3d != 0) goto LAB_0095af24;
          lVar11 = func_0x00bc3330(uVar19 << 3);
        }
        puVar23 = (ulong *)(lVar11 + (lVar10 >> 3) * 8);
        *puVar23 = uVar9;
        puVar17 = puVar23;
        puVar22 = puVar5;
        if (puVar5 != puVar27) {
          puVar22 = in_stack_00000020;
          if ((0x37 < lVar10 - 8U) && (0x1f < (ulong)((long)puVar27 + (-lVar10 - lVar11)))) {
            puVar21 = puVar27 + -2;
            uVar9 = (lVar10 - 8U >> 3) + 1;
            uVar20 = uVar9 & 0x3ffffffffffffffc;
            puVar27 = puVar27 + -uVar20;
            puVar17 = puVar23 + -uVar20;
            puVar18 = puVar23 + -2;
            uVar12 = uVar20;
            do {
              puVar4 = puVar21 + -1;
              uVar31 = puVar21[-2];
              uVar29 = puVar21[1];
              uVar28 = *puVar21;
              uVar12 = uVar12 - 4;
              puVar21 = puVar21 + -4;
              puVar18[-1] = *puVar4;
              puVar18[-2] = uVar31;
              puVar18[1] = uVar29;
              *puVar18 = uVar28;
              puVar18 = puVar18 + -4;
            } while (uVar12 != 0);
            if (uVar9 == uVar20) goto LAB_0095abd4;
          }
          do {
            puVar27 = puVar27 + -1;
            puVar17 = puVar17 + -1;
            *puVar17 = *puVar27;
          } while (puVar27 != puVar5);
        }
LAB_0095abd4:
        in_stack_00000030 = (ulong *)(lVar11 + uVar19 * 8);
        unaff_x21 = in_stack_00000010;
        in_stack_00000020 = puVar17;
        puVar17 = puVar23 + 1;
        if (puVar22 != (ulong *)0x0) {
          func_0x00bc3350(puVar22);
          unaff_x21 = in_stack_00000010;
        }
      }
    }
LAB_0095abf4:
    in_stack_00000028 = puVar17;
    plVar25 = unaff_x24;
    if ((unaff_x21 == (long *)0x0) ||
       (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,unaff_x21 + 1), lVar10 != 0)) goto LAB_0095aa5c;
    (**(code **)(*unaff_x21 + 0x10))(unaff_x21);
    goto code_r0x0095ac18;
  }
  lVar10 = 0;
  if (in_stack_00000028 != in_stack_00000020) {
    lVar10 = LZCOUNT((long)in_stack_00000028 - (long)in_stack_00000020 >> 3) * -2 + 0x7e;
  }
  param_3 = in_stack_00000020;
  func_0x0095e9d0(in_stack_00000028,in_stack_00000028,in_stack_00000020,in_stack_00000020,lVar10,1);
  plVar25 = (long *)*unaff_x19;
  plVar24 = (long *)unaff_x19[1];
  in_stack_00000008 = (long *)0x0;
  in_stack_00000010 = (long *)0x0;
  in_stack_00000018 = 0;
  lVar10 = (long)plVar24 - (long)plVar25;
  *(long ***)(unaff_x29 + -0x18) = &stack0x00000008;
  *(undefined1 *)(unaff_x29 + -0x10) = 0;
  if (lVar10 == 0) goto LAB_0095ad34;
  if (lVar10 < 0) {
LAB_0095af3c:
    if (*(long *)(in_stack_00000000 + 0x28) == *(long *)(unaff_x29 + -8)) {
      uVar13 = func_0x0095e9bc(&stack0x00000008);
      func_0x0095fa50(unaff_x29 + -0x18);
      if (in_stack_00000020 != (ulong *)0x0) {
        in_stack_00000028 = in_stack_00000020;
        func_0x00bc3350();
      }
      if (*(long *)(in_stack_00000000 + 0x28) == *(long *)(unaff_x29 + -8)) {
        func_0x00bbf40c(uVar13);
      }
    }
  }
  else {
    plVar15 = (long *)func_0x00bc3330(lVar10);
    in_stack_00000018 = (long)plVar15 + lVar10;
    in_stack_00000008 = plVar15;
    in_stack_00000010 = plVar15;
    do {
      *plVar15 = *plVar25;
      lVar10 = plVar25[1];
      plVar15[1] = lVar10;
      if (lVar10 != 0) {
        func_0x00bbf180(1,lVar10 + 8);
      }
      plVar25 = plVar25 + 2;
      plVar15 = plVar15 + 2;
    } while (plVar25 != plVar24);
    plVar25 = (long *)*unaff_x19;
    in_stack_00000010 = plVar15;
    for (plVar24 = (long *)unaff_x19[1]; plVar24 != plVar25; plVar24 = plVar24 + -2) {
      plVar15 = (long *)plVar24[-1];
      if ((plVar15 != (long *)0x0) &&
         (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar10 == 0)) {
        (**(code **)(*plVar15 + 0x10))(plVar15);
        func_0x00bc3320(plVar15);
      }
      puVar23 = in_stack_00000020;
    }
LAB_0095ad34:
    puVar17 = in_stack_00000028;
    unaff_x19[1] = (long)plVar25;
    plVar25 = in_stack_00000008;
    plVar24 = in_stack_00000010;
    for (; in_stack_00000008 = plVar25, in_stack_00000010 = plVar24, puVar23 != puVar17;
        puVar23 = puVar23 + 1) {
      if (plVar25 != plVar24) {
        uVar9 = *puVar23;
        do {
          lVar11 = *plVar25;
          *(long *)(unaff_x29 + -0x18) = lVar11;
          lVar10 = plVar25[1];
          *(long *)(unaff_x29 + -0x10) = lVar10;
          if (lVar10 != 0) {
            func_0x00bbf180(1,lVar10 + 8);
          }
          iVar6 = func_0x00961dd4(lVar11);
          if ((int)uVar9 == iVar6) {
            uVar7 = func_0x009636c8(*(undefined8 *)(unaff_x29 + -0x18));
            uVar12 = func_0x007b03c4(4,uVar7);
            if ((uVar12 & 1) != 0) {
              puVar26 = (undefined8 *)unaff_x19[1];
              if (puVar26 < (undefined8 *)unaff_x19[2]) {
                *puVar26 = *(undefined8 *)(unaff_x29 + -0x18);
                lVar10 = *(long *)(unaff_x29 + -0x10);
                puVar26[1] = lVar10;
                if (lVar10 != 0) {
                  func_0x00bbf180(1,lVar10 + 8);
                }
                puVar26 = puVar26 + 2;
              }
              else {
                puVar26 = (undefined8 *)func_0x0095e85c();
              }
              plVar25 = *(long **)(unaff_x29 + -0x10);
              unaff_x19[1] = (long)puVar26;
              if ((plVar25 != (long *)0x0) &&
                 (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,plVar25 + 1), lVar10 == 0)) {
                (**(code **)(*plVar25 + 0x10))(plVar25);
                func_0x00bc3320(plVar25);
              }
              break;
            }
          }
          plVar15 = *(long **)(unaff_x29 + -0x10);
          if ((plVar15 != (long *)0x0) &&
             (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar10 == 0)) {
            (**(code **)(*plVar15 + 0x10))(plVar15);
            func_0x00bc3320(plVar15);
          }
          plVar25 = plVar25 + 2;
        } while (plVar25 != plVar24);
      }
      plVar25 = in_stack_00000008;
      plVar24 = in_stack_00000010;
    }
    if (plVar25 != (long *)0x0) {
      for (; plVar24 != plVar25; plVar24 = plVar24 + -2) {
        plVar15 = (long *)plVar24[-1];
        if ((plVar15 != (long *)0x0) &&
           (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar10 == 0)) {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          func_0x00bc3320(plVar15);
        }
      }
      in_stack_00000010 = plVar25;
      func_0x00bc3350(in_stack_00000008);
    }
    if (in_stack_00000020 != (ulong *)0x0) {
      func_0x00bc3350();
    }
    if (*(long *)(in_stack_00000000 + 0x28) == *(long *)(unaff_x29 + -8)) {
      return;
    }
  }
LAB_0095afc8:
  auVar32 = func_0x00bc3380();
  puVar14 = auVar32._0_8_;
  lVar10 = tpidr_el0;
  lStack_68 = *(long *)(lVar10 + 0x28);
  puVar26 = (undefined8 *)*puVar14;
  puVar3 = (undefined8 *)puVar14[1];
  plStack_78 = (long *)0x0;
  plStack_70 = (long *)0x0;
  if (puVar26 != puVar3) {
    do {
      plVar25 = (long *)*puVar26;
      plVar24 = (long *)puVar26[1];
      if (plVar24 != (long *)0x0) {
        func_0x00bbf180(1,plVar24 + 1);
      }
      iVar6 = func_0x00961dd4(plVar25);
      iVar8 = func_0x0099f98c(auVar32._8_8_);
      if (iVar6 == iVar8) {
        if (plVar24 != (long *)0x0) {
          func_0x00bbf180(1,plVar24 + 1);
        }
        plVar15 = plStack_70;
        plStack_78 = plVar25;
        plVar25 = plVar24;
        if ((plStack_70 != (long *)0x0) &&
           (plVar25 = plStack_70 + 1, plStack_70 = plVar24,
           lVar11 = func_0x00bbf1b0(0xffffffffffffffff,plVar25), plVar25 = plStack_70, lVar11 == 0))
        {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          func_0x00bc3320(plVar15);
          plVar25 = plStack_70;
        }
        plStack_70 = plVar25;
        if ((plVar24 != (long *)0x0) &&
           (lVar11 = func_0x00bbf1b0(0xffffffffffffffff,plVar24 + 1), lVar11 == 0)) {
          (**(code **)(*plVar24 + 0x10))(plVar24);
          func_0x00bc3320(plVar24);
        }
        break;
      }
      if ((plVar24 != (long *)0x0) &&
         (lVar11 = func_0x00bbf1b0(0xffffffffffffffff,plVar24 + 1), lVar11 == 0)) {
        (**(code **)(*plVar24 + 0x10))(plVar24);
        func_0x00bc3320(plVar24);
      }
      puVar26 = puVar26 + 2;
    } while (puVar26 != puVar3);
    plVar25 = plStack_78;
    if (plStack_78 != (long *)0x0) goto LAB_0095b1b4;
  }
  plVar15 = (long *)func_0x00bc3330(0x20);
  plVar25 = plVar15 + 3;
  plVar15[1] = 0;
  plVar15[2] = 0;
  *plVar15 = (long)&UNK_00bf18e0;
  func_0x00961780(plVar25);
  plVar24 = plStack_70;
  plStack_78 = plVar25;
  if ((plStack_70 != (long *)0x0) &&
     (plVar25 = plStack_70 + 1, plStack_70 = plVar15,
     lVar11 = func_0x00bbf1b0(0xffffffffffffffff,plVar25), plVar15 = plStack_70, lVar11 == 0)) {
    (**(code **)(*plVar24 + 0x10))(plVar24);
    func_0x00bc3320(plVar24);
    plVar15 = plStack_70;
  }
  plStack_70 = plVar15;
  plVar25 = plStack_78;
  puVar26 = (undefined8 *)puVar14[1];
  if (puVar26 < (undefined8 *)puVar14[2]) {
    *puVar26 = plStack_78;
    puVar26[1] = plStack_70;
    if (plStack_70 != (long *)0x0) {
      func_0x00bbf180(1,plStack_70 + 1);
    }
    puVar26 = puVar26 + 2;
  }
  else {
    puVar26 = (undefined8 *)func_0x0095e85c(puVar14,&plStack_78);
    plVar25 = plStack_78;
  }
  puVar14[1] = puVar26;
LAB_0095b1b4:
  func_0x00963660(plVar25,auVar32._8_8_,param_3);
  plVar25 = plStack_70;
  if ((plStack_70 != (long *)0x0) &&
     (lVar11 = func_0x00bbf1b0(0xffffffffffffffff,plStack_70 + 1), lVar11 == 0)) {
    (**(code **)(*plVar25 + 0x10))(plVar25);
    func_0x00bc3320(plVar25);
  }
  if (*(long *)(lVar10 + 0x28) != lStack_68) {
    auVar33 = func_0x00bc3380();
    plVar25 = auVar33._0_8_;
    lVar10 = *plVar25;
    if (plVar25[1] != lVar10) {
      lVar11 = 0;
      uVar9 = 0;
      do {
        iVar6 = func_0x00961dd4(*(undefined8 *)(lVar10 + lVar11));
        if (iVar6 == auVar33._8_4_) {
          lVar2 = *plVar25;
          puVar3 = (undefined8 *)plVar25[1];
          lVar1 = lVar2 + lVar11;
          puVar26 = (undefined8 *)(lVar1 + 0x10);
          lVar10 = lVar1;
          if (puVar26 != puVar3) {
            do {
              uVar30 = puVar26[1];
              uVar13 = *puVar26;
              plVar24 = (long *)puVar26[-1];
              *puVar26 = 0;
              puVar26[1] = 0;
              puVar26[-1] = uVar30;
              puVar26[-2] = uVar13;
              if ((plVar24 != (long *)0x0) &&
                 (lVar16 = func_0x00bbf1b0(0xffffffffffffffff,plVar24 + 1), lVar16 == 0)) {
                (**(code **)(*plVar24 + 0x10))(plVar24);
                func_0x00bc3320(plVar24);
              }
              puVar26 = puVar26 + 2;
              lVar10 = lVar10 + 0x10;
            } while (puVar26 != puVar3);
            puVar26 = (undefined8 *)plVar25[1];
          }
          puVar3 = (undefined8 *)(lVar1 + ((lVar10 - lVar2) - lVar11));
          for (; puVar26 != puVar3; puVar26 = puVar26 + -2) {
            plVar24 = (long *)puVar26[-1];
            if ((plVar24 != (long *)0x0) &&
               (lVar10 = func_0x00bbf1b0(0xffffffffffffffff,plVar24 + 1), lVar10 == 0)) {
              (**(code **)(*plVar24 + 0x10))(plVar24);
              func_0x00bc3320(plVar24);
            }
          }
          plVar25[1] = (long)puVar3;
          return;
        }
        lVar10 = *plVar25;
        uVar9 = uVar9 + 1;
        lVar11 = lVar11 + 0x10;
      } while (uVar9 < (ulong)(plVar25[1] - lVar10 >> 4));
    }
    return;
  }
  return;
}


