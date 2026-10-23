// Address: 0x6f74a0
// Function: AssetCatalog_RegisterPacks_0x6f74a0
// Decompiled by Ghidra 12.1.4 Headless

/* WARNING: Removing unreachable block (ram,0x007b0c10) */
/* WARNING: Removing unreachable block (ram,0x007b0c48) */
/* WARNING: Removing unreachable block (ram,0x007b0c58) */
/* WARNING: Removing unreachable block (ram,0x007b0c60) */
/* WARNING: Removing unreachable block (ram,0x007b0c68) */
/* WARNING: Removing unreachable block (ram,0x007b0c3c) */
/* WARNING: Removing unreachable block (ram,0x007b0c34) */
/* WARNING: Removing unreachable block (ram,0x007b0c6c) */
/* WARNING: Removing unreachable block (ram,0x007b0ca0) */
/* WARNING: Removing unreachable block (ram,0x007b0ca8) */
/* WARNING: Removing unreachable block (ram,0x007b0cbc) */
/* WARNING: Type propagation algorithm not settling */

ulong AssetCatalog_RegisterPacks_0x6f74a0
                (long *param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 *******pppppppuVar7;
  undefined8 *******pppppppuVar8;
  undefined8 *puVar9;
  long *plVar10;
  undefined8 *******pppppppuVar11;
  ulong extraout_x1;
  undefined8 *puVar12;
  long *plVar13;
  long *plVar14;
  undefined8 *puVar15;
  long *plVar16;
  long lVar17;
  undefined1 *puVar18;
  long *in_x9;
  long extraout_x9;
  long lVar19;
  long extraout_x11;
  long extraout_x11_00;
  long extraout_x11_01;
  int unaff_w20;
  int unaff_w21;
  int iVar20;
  long *unaff_x22;
  ulong uVar21;
  long *plVar22;
  undefined8 *******pppppppuVar23;
  undefined8 *puVar24;
  ulong uVar25;
  ulong uVar26;
  long *unaff_x26;
  ulong uVar27;
  ulong unaff_x27;
  long *plVar28;
  long unaff_x29;
  undefined1 auVar29 [16];
  undefined8 *in_stack_00000008;
  long *in_stack_00000010;
  undefined8 *in_stack_00000018;
  long in_stack_00000020;
  undefined8 *in_stack_00000030;
  long *plStack_b8;
  long *plStack_b0;
  undefined8 *******pppppppuStack_80;
  undefined8 *******pppppppuStack_78;
  long lStack_70;
  long lStack_68;
  
  for (; in_x9 != (long *)0x0; in_x9 = (long *)*in_x9) {
LAB_006f74a4:
    if ((int)in_x9[4] <= unaff_w20) {
      if ((int)in_x9[4] < unaff_w20) {
        in_x9 = (long *)in_x9[1];
        goto joined_r0x006f7490;
      }
      plVar16 = (long *)in_x9[6];
      while( true ) {
        while( true ) {
          if (plVar16 == (long *)0x0) goto LAB_006f7a00;
          if (*(int *)(plVar16 + 4) <= unaff_w21) break;
          plVar16 = (long *)*plVar16;
        }
        if (unaff_w21 <= *(int *)(plVar16 + 4)) break;
        plVar16 = (long *)plVar16[1];
      }
      if (unaff_x27 < (ulong)(((long *)plVar16[5])[1] - *(long *)plVar16[5] >> 2)) {
        do {
          if (unaff_w20 < (int)param_1[4]) {
            param_1 = (long *)*param_1;
          }
          else {
            if (unaff_w20 <= (int)param_1[4]) goto LAB_006f7538;
            param_1 = (long *)param_1[1];
          }
          if (param_1 == (long *)0x0) goto LAB_006f7a20;
        } while( true );
      }
      if (*(long *)(unaff_x29 + -0x10) == 0) goto LAB_006f79ec;
      uVar21 = 0;
      plVar16 = param_1;
      goto LAB_006f77d0;
    }
  }
LAB_006f7a00:
  if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
    func_0x00411610(&UNK_00289c18);
LAB_006f7a20:
    if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
      func_0x00411610(&UNK_00289c18);
LAB_006f7a40:
      if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
        func_0x00411610(&UNK_00289c18);
LAB_006f7a60:
        if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
          func_0x00411610(&UNK_00289c18);
LAB_006f7a80:
          if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
            func_0x00411610(&UNK_00289c18);
LAB_006f7aa0:
            if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
              func_0x006f9a98(*(long *)(unaff_x29 + -0x28) + 0x48);
LAB_006f7ac0:
              if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
                func_0x00470c38();
LAB_006f7ad8:
                if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
                  func_0x00470c38();
                  lVar6 = extraout_x9;
LAB_006f7af0:
                  if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
                    uVar4 = func_0x00470c38(lVar6 + 0x18);
                    func_0x0063fdd4(unaff_x29 + -0x20,*(undefined8 *)(unaff_x29 + -0x18));
                    if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
                      func_0x00bbf40c(uVar4);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_006f7b60:
  auVar29 = func_0x00bc3380();
  plVar10 = auVar29._8_8_;
  plVar5 = auVar29._0_8_;
  plVar16 = (long *)tpidr_el0;
  lStack_68 = plVar16[5];
  plVar13 = plVar5 + 0xc;
  if (plVar5[0xd] != *plVar13) {
    uVar21 = 0;
    uVar25 = 0;
    do {
      lVar6 = func_0x007fd748();
      plVar28 = plVar16;
      if ((ulong)(plVar5[0xd] - plVar5[0xc] >> 2) <= uVar21) goto LAB_006f8238;
      uVar2 = func_0x00a23008(lVar6 + 0x1970,*(undefined4 *)(plVar5[0xc] + uVar21 * 4));
      uVar21 = uVar21 + 1;
      uVar2 = (int)uVar25 + (uVar2 & 1);
      uVar25 = (ulong)uVar2;
    } while (uVar21 < (ulong)(plVar5[0xd] - plVar5[0xc] >> 2));
    if ((uVar2 != 0) && (uVar25 <= (ulong)(plVar5[1] - *plVar5 >> 3))) {
      if ((int)plVar5[0x16] < (int)uVar2) {
        *(undefined4 *)((long)plVar5 + 0xac) = 0;
      }
      *(uint *)(plVar5 + 0x16) = uVar2;
      plStack_b8 = plVar5 + 3;
      lVar6 = *plStack_b8;
      uVar21 = (ulong)(int)(uVar2 - 1);
      pppppppuStack_78 = (undefined8 *******)0x0;
      lStack_70 = 0;
      plStack_b0 = plVar16;
      pppppppuStack_80 = &pppppppuStack_78;
      if (uVar21 < (ulong)(plVar5[4] - lVar6 >> 3)) {
        uVar25 = 0;
        plVar28 = param_4 + 1;
LAB_006f7ce4:
        plVar13 = *(long **)(lVar6 + uVar21 * 8);
        lVar6 = *plVar13;
        if (uVar25 < (ulong)(plVar13[1] - lVar6 >> 2)) {
          iVar3 = *(int *)(lVar6 + uVar25 * 4);
          plVar14 = (long *)plVar10[1];
          plVar13 = plVar10 + 1;
          while (plVar22 = plVar13, plVar14 != (long *)0x0) {
            while (plVar13 = plVar14, *(int *)((long)plVar13 + 0x1c) <= iVar3) {
              if (iVar3 <= *(int *)((long)plVar13 + 0x1c)) {
                cVar1 = (char)plVar13[4];
                goto joined_r0x006f7d9c;
              }
              plVar14 = (long *)plVar13[1];
              if ((long *)plVar13[1] == (long *)0x0) {
                plVar22 = plVar13 + 1;
                goto LAB_006f7d3c;
              }
            }
            plVar14 = (long *)*plVar13;
          }
LAB_006f7d3c:
          puVar15 = (undefined8 *)func_0x00bc3330(0x28);
          *puVar15 = 0;
          puVar15[1] = 0;
          puVar15[2] = plVar13;
          *plVar22 = (long)puVar15;
          plVar14 = (long *)*plVar10;
          *(int *)((long)puVar15 + 0x1c) = iVar3;
          *(undefined1 *)(puVar15 + 4) = 0;
          puVar12 = puVar15;
          if (*plVar14 != 0) {
            *plVar10 = *plVar14;
            puVar12 = (undefined8 *)*plVar22;
          }
          func_0x0040a8c0(plVar10[1],puVar12);
          plVar10[2] = plVar10[2] + 1;
          cVar1 = *(char *)(puVar15 + 4);
joined_r0x006f7d9c:
          if (cVar1 == '\0') goto LAB_006f7cc4;
          lVar6 = plVar5[9];
          uVar27 = (ulong)iVar3;
          if (uVar27 < (ulong)(plVar5[10] - lVar6 >> 3)) {
            uVar26 = 0;
            while (lVar17 = *(long *)(lVar6 + uVar27 * 8), lVar6 = *(long *)(lVar17 + 0x10),
                  uVar26 < (ulong)(*(long *)(lVar17 + 0x18) - lVar6 >> 2)) {
              iVar20 = *(int *)(lVar6 + uVar26 * 4);
              plVar14 = (long *)*plVar28;
              plVar13 = plVar28;
              while (plVar22 = plVar13, plVar14 != (long *)0x0) {
                while (plVar13 = plVar14, *(int *)((long)plVar13 + 0x1c) <= iVar20) {
                  if (iVar20 <= *(int *)((long)plVar13 + 0x1c)) {
                    cVar1 = (char)plVar13[4];
                    goto joined_r0x006f7e8c;
                  }
                  plVar14 = (long *)plVar13[1];
                  if ((long *)plVar13[1] == (long *)0x0) {
                    plVar22 = plVar13 + 1;
                    goto LAB_006f7e48;
                  }
                }
                plVar14 = (long *)*plVar13;
              }
LAB_006f7e48:
              puVar15 = (undefined8 *)func_0x00bc3330(0x28);
              *puVar15 = 0;
              puVar15[1] = 0;
              puVar15[2] = plVar13;
              *plVar22 = (long)puVar15;
              plVar14 = (long *)*param_4;
              *(int *)((long)puVar15 + 0x1c) = iVar20;
              *(undefined1 *)(puVar15 + 4) = 0;
              puVar12 = puVar15;
              if (*plVar14 != 0) {
                *param_4 = *plVar14;
                puVar12 = (undefined8 *)*plVar22;
              }
              func_0x0040a8c0(param_4[1],puVar12);
              param_4[2] = param_4[2] + 1;
              cVar1 = *(char *)(puVar15 + 4);
joined_r0x006f7e8c:
              pppppppuVar11 = pppppppuStack_78;
              pppppppuVar8 = &pppppppuStack_78;
              if (cVar1 == '\0') goto LAB_006f7ea0;
              lVar6 = plVar5[9];
              uVar26 = uVar26 + 1;
              if ((ulong)(plVar5[10] - lVar6 >> 3) <= uVar27) goto LAB_006f821c;
            }
            goto LAB_006f7cc4;
          }
LAB_006f821c:
          if (plVar16[5] == lStack_68) {
            func_0x006f9a98(plVar5 + 9);
LAB_006f8238:
            if (plVar28[5] == lStack_68) {
              func_0x00470c38(plVar13);
              goto LAB_006f8250;
            }
          }
          goto LAB_006f83a8;
        }
        if (lStack_70 == 0) {
          uVar25 = 0xffffffff;
          goto LAB_006f820c;
        }
        lVar6 = *plVar5;
        lVar17 = plVar5[1];
        if ((ulong)(lVar17 - lVar6 >> 3) <= uVar21) goto LAB_006f826c;
        uVar25 = 0;
        goto LAB_006f7f48;
      }
LAB_006f8250:
      plVar16 = plVar28;
      if (plStack_b0[5] == lStack_68) {
        func_0x006f9aac(plStack_b8);
        goto LAB_006f826c;
      }
      goto LAB_006f83a8;
    }
  }
  uVar25 = 0xffffffff;
LAB_006f7c0c:
  if (plVar16[5] == lStack_68) {
    return uVar25;
  }
  goto LAB_006f83a8;
LAB_006f7538:
  plVar16 = (long *)param_1[6];
  while( true ) {
    while( true ) {
      if (plVar16 == (long *)0x0) goto LAB_006f7a20;
      if (*(int *)(plVar16 + 4) <= unaff_w21) break;
      plVar16 = (long *)*plVar16;
    }
    if (unaff_w21 <= *(int *)(plVar16 + 4)) break;
    plVar16 = (long *)plVar16[1];
  }
  lVar6 = *(long *)plVar16[5];
  if ((ulong)(((long *)plVar16[5])[1] - lVar6 >> 2) <= unaff_x27) goto LAB_006f7ac0;
  iVar3 = *(int *)(lVar6 + unaff_x27 * 4);
  puVar15 = (undefined8 *)*in_stack_00000018;
  puVar12 = in_stack_00000018;
  while (puVar24 = puVar12, puVar15 != (undefined8 *)0x0) {
    while (puVar24 = puVar15, *(int *)((long)puVar24 + 0x1c) <= iVar3) {
      if (iVar3 <= *(int *)((long)puVar24 + 0x1c)) {
        cVar1 = *(char *)(puVar24 + 4);
        goto joined_r0x006f762c;
      }
      puVar15 = (undefined8 *)puVar24[1];
      if ((undefined8 *)puVar24[1] == (undefined8 *)0x0) {
        puVar12 = puVar24 + 1;
        goto LAB_006f75cc;
      }
    }
    puVar12 = puVar24;
    puVar15 = (undefined8 *)*puVar24;
  }
LAB_006f75cc:
  puVar9 = (undefined8 *)func_0x00bc3330(0x28);
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = puVar24;
  *puVar12 = puVar9;
  plVar16 = (long *)*unaff_x26;
  *(int *)((long)puVar9 + 0x1c) = iVar3;
  *(undefined1 *)(puVar9 + 4) = 0;
  puVar15 = puVar9;
  if (*plVar16 != 0) {
    *unaff_x26 = *plVar16;
    puVar15 = (undefined8 *)*puVar12;
  }
  func_0x0040a8c0(unaff_x26[1],puVar15);
  unaff_x26[2] = unaff_x26[2] + 1;
  cVar1 = *(char *)(puVar9 + 4);
joined_r0x006f762c:
  if (cVar1 != '\0') {
    uVar21 = (ulong)iVar3;
    lVar6 = *(long *)(*(long *)(unaff_x29 + -0x28) + 0x48);
    if (uVar21 < (ulong)(*(long *)(*(long *)(unaff_x29 + -0x28) + 0x50) - lVar6 >> 3)) {
      uVar25 = 0;
LAB_006f7684:
      lVar17 = *(long *)(lVar6 + uVar21 * 8);
      lVar6 = *(long *)(lVar17 + 0x10);
      if (uVar25 < (ulong)(*(long *)(lVar17 + 0x18) - lVar6 >> 2)) {
        iVar20 = *(int *)(lVar6 + uVar25 * 4);
        puVar15 = (undefined8 *)*in_stack_00000030;
        puVar12 = in_stack_00000030;
        while (puVar24 = puVar12, puVar15 != (undefined8 *)0x0) {
          while (puVar24 = puVar15, *(int *)((long)puVar24 + 0x1c) <= iVar20) {
            if (iVar20 <= *(int *)((long)puVar24 + 0x1c)) {
              cVar1 = *(char *)(puVar24 + 4);
              goto joined_r0x006f771c;
            }
            puVar15 = (undefined8 *)puVar24[1];
            if ((undefined8 *)puVar24[1] == (undefined8 *)0x0) {
              puVar12 = puVar24 + 1;
              goto LAB_006f76d8;
            }
          }
          puVar12 = puVar24;
          puVar15 = (undefined8 *)*puVar24;
        }
LAB_006f76d8:
        puVar9 = (undefined8 *)func_0x00bc3330(0x28);
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = puVar24;
        *puVar12 = puVar9;
        plVar16 = (long *)*unaff_x22;
        *(int *)((long)puVar9 + 0x1c) = iVar20;
        *(undefined1 *)(puVar9 + 4) = 0;
        puVar15 = puVar9;
        if (*plVar16 != 0) {
          *unaff_x22 = *plVar16;
          puVar15 = (undefined8 *)*puVar12;
        }
        func_0x0040a8c0(unaff_x22[1],puVar15);
        unaff_x22[2] = unaff_x22[2] + 1;
        cVar1 = *(char *)(puVar9 + 4);
joined_r0x006f771c:
        if (cVar1 != '\0') goto LAB_006f766c;
        puVar15 = *(undefined8 **)(unaff_x29 + -0x18);
        puVar12 = in_stack_00000008;
        while (puVar24 = puVar12, puVar15 != (undefined8 *)0x0) {
          while (puVar24 = puVar15, *(int *)((long)puVar24 + 0x1c) <= iVar3) {
            if (iVar3 <= *(int *)((long)puVar24 + 0x1c)) goto LAB_006f7474;
            puVar15 = (undefined8 *)puVar24[1];
            if ((undefined8 *)puVar24[1] == (undefined8 *)0x0) {
              puVar12 = puVar24 + 1;
              goto LAB_006f775c;
            }
          }
          puVar12 = puVar24;
          puVar15 = (undefined8 *)*puVar24;
        }
LAB_006f775c:
        puVar9 = (undefined8 *)func_0x00bc3330(0x28);
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = puVar24;
        *puVar12 = puVar9;
        plVar16 = *(long **)(unaff_x29 + -0x20);
        *(int *)((long)puVar9 + 0x1c) = iVar3;
        *(undefined1 *)(puVar9 + 4) = 0;
        puVar15 = puVar9;
        if (*plVar16 != 0) {
          *(long *)(unaff_x29 + -0x20) = *plVar16;
          puVar15 = (undefined8 *)*puVar12;
        }
        func_0x0040a8c0(*(undefined8 *)(unaff_x29 + -0x18),puVar15);
        *(long *)(unaff_x29 + -0x10) = *(long *)(unaff_x29 + -0x10) + 1;
        puVar24 = puVar9;
LAB_006f7474:
        *(undefined1 *)(puVar24 + 4) = 1;
      }
      goto LAB_006f747c;
    }
    goto LAB_006f7aa0;
  }
LAB_006f747c:
  in_x9 = *(long **)(*(long *)(unaff_x29 + -0x28) + 0x38);
  unaff_x27 = unaff_x27 + 1;
  param_1 = in_x9;
  unaff_x26 = in_stack_00000010;
joined_r0x006f7490:
  if (in_x9 == (long *)0x0) goto LAB_006f7a00;
  goto LAB_006f74a4;
LAB_006f766c:
  uVar25 = uVar25 + 1;
  lVar6 = *(long *)(*(long *)(unaff_x29 + -0x28) + 0x48);
  if ((ulong)(*(long *)(*(long *)(unaff_x29 + -0x28) + 0x50) - lVar6 >> 3) <= uVar21)
  goto LAB_006f7aa0;
  goto LAB_006f7684;
LAB_006f77d0:
  if (unaff_w20 < (int)param_1[4]) {
    param_1 = (long *)*param_1;
    goto joined_r0x006f77cc;
  }
  if ((int)param_1[4] < unaff_w20) {
    param_1 = (long *)param_1[1];
    goto joined_r0x006f77cc;
  }
  plVar13 = (long *)param_1[6];
  while( true ) {
    while( true ) {
      if (plVar13 == (long *)0x0) goto LAB_006f7a40;
      if (*(int *)(plVar13 + 4) <= unaff_w21) break;
      plVar13 = (long *)*plVar13;
    }
    if (unaff_w21 <= *(int *)(plVar13 + 4)) break;
    plVar13 = (long *)plVar13[1];
  }
  if (uVar21 < (ulong)(*(long *)(plVar13[5] + 0x20) - *(long *)(plVar13[5] + 0x18) >> 2)) {
    do {
      if (unaff_w20 < (int)plVar16[4]) {
        plVar16 = (long *)*plVar16;
      }
      else {
        if (unaff_w20 <= (int)plVar16[4]) goto LAB_006f7864;
        plVar16 = (long *)plVar16[1];
      }
      if (plVar16 == (long *)0x0) goto LAB_006f7a60;
    } while( true );
  }
LAB_006f79ec:
  uVar25 = 0xffffffff;
LAB_006f73d8:
  func_0x0063fdd4(unaff_x29 + -0x20,*(undefined8 *)(unaff_x29 + -0x18));
  if (*(long *)(in_stack_00000020 + 0x28) == *(long *)(unaff_x29 + -8)) {
    return uVar25;
  }
  goto LAB_006f7b60;
LAB_006f7864:
  plVar16 = (long *)plVar16[6];
  while( true ) {
    while( true ) {
      if (plVar16 == (long *)0x0) goto LAB_006f7a60;
      if (*(int *)(plVar16 + 4) <= unaff_w21) break;
      plVar16 = (long *)*plVar16;
    }
    if (unaff_w21 <= *(int *)(plVar16 + 4)) break;
    plVar16 = (long *)plVar16[1];
  }
  lVar6 = *(long *)plVar16[5];
  if ((ulong)(((long *)plVar16[5])[1] - lVar6 >> 2) <= uVar21) goto LAB_006f7ad8;
  uVar2 = *(uint *)(lVar6 + uVar21 * 4);
  uVar25 = (ulong)uVar2;
  puVar12 = *(undefined8 **)(unaff_x29 + -0x18);
  puVar15 = in_stack_00000008;
  while (puVar24 = puVar15, puVar12 != (undefined8 *)0x0) {
    while (puVar15 = puVar12, *(int *)((long)puVar15 + 0x1c) <= (int)uVar2) {
      if ((int)uVar2 <= *(int *)((long)puVar15 + 0x1c)) {
        cVar1 = *(char *)(puVar15 + 4);
        goto joined_r0x006f794c;
      }
      puVar12 = (undefined8 *)puVar15[1];
      if ((undefined8 *)puVar15[1] == (undefined8 *)0x0) {
        puVar24 = puVar15 + 1;
        goto LAB_006f78ec;
      }
    }
    puVar12 = (undefined8 *)*puVar15;
  }
LAB_006f78ec:
  puVar9 = (undefined8 *)func_0x00bc3330(0x28);
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = puVar15;
  *puVar24 = puVar9;
  plVar16 = *(long **)(unaff_x29 + -0x20);
  *(uint *)((long)puVar9 + 0x1c) = uVar2;
  *(undefined1 *)(puVar9 + 4) = 0;
  puVar12 = puVar9;
  if (*plVar16 != 0) {
    *(long *)(unaff_x29 + -0x20) = *plVar16;
    puVar12 = (undefined8 *)*puVar24;
  }
  func_0x0040a8c0(*(undefined8 *)(unaff_x29 + -0x18),puVar12);
  *(long *)(unaff_x29 + -0x10) = *(long *)(unaff_x29 + -0x10) + 1;
  cVar1 = *(char *)(puVar9 + 4);
joined_r0x006f794c:
  if (cVar1 == '\0') {
    param_1 = *(long **)(*(long *)(unaff_x29 + -0x28) + 0x38);
  }
  else {
    iVar3 = func_0x0043ea60(100);
    param_1 = *(long **)(*(long *)(unaff_x29 + -0x28) + 0x38);
    plVar16 = param_1;
    while( true ) {
      while( true ) {
        if (plVar16 == (long *)0x0) goto LAB_006f7a80;
        if ((int)plVar16[4] <= unaff_w20) break;
        plVar16 = (long *)*plVar16;
      }
      if (unaff_w20 <= (int)plVar16[4]) break;
      plVar16 = (long *)plVar16[1];
    }
    plVar16 = (long *)plVar16[6];
    while( true ) {
      while( true ) {
        if (plVar16 == (long *)0x0) goto LAB_006f7a80;
        if (*(int *)(plVar16 + 4) <= unaff_w21) break;
        plVar16 = (long *)*plVar16;
      }
      if (unaff_w21 <= *(int *)(plVar16 + 4)) break;
      plVar16 = (long *)plVar16[1];
    }
    lVar6 = plVar16[5];
    if ((ulong)(*(long *)(lVar6 + 0x20) - *(long *)(lVar6 + 0x18) >> 2) <= uVar21)
    goto LAB_006f7af0;
    if (iVar3 < *(int *)(*(long *)(lVar6 + 0x18) + uVar21 * 4)) goto LAB_006f73d8;
  }
  uVar21 = uVar21 + 1;
  plVar16 = param_1;
joined_r0x006f77cc:
  if (param_1 == (long *)0x0) goto LAB_006f7a40;
  goto LAB_006f77d0;
LAB_006f7ea0:
  while (pppppppuVar23 = pppppppuVar8, pppppppuVar11 != (undefined8 *******)0x0) {
    while (pppppppuVar8 = pppppppuVar11, *(int *)((long)pppppppuVar8 + 0x1c) <= iVar3) {
      if (iVar3 <= *(int *)((long)pppppppuVar8 + 0x1c)) goto LAB_006f7cbc;
      pppppppuVar11 = (undefined8 *******)pppppppuVar8[1];
      if ((undefined8 *******)pppppppuVar8[1] == (undefined8 *******)0x0) {
        pppppppuVar23 = pppppppuVar8 + 1;
        goto LAB_006f7ecc;
      }
    }
    pppppppuVar11 = (undefined8 *******)*pppppppuVar8;
  }
LAB_006f7ecc:
  pppppppuVar7 = (undefined8 *******)func_0x00bc3330(0x28);
  *pppppppuVar7 = (undefined8 ******)0x0;
  pppppppuVar7[1] = (undefined8 ******)0x0;
  pppppppuVar7[2] = pppppppuVar8;
  *pppppppuVar23 = pppppppuVar7;
  *(int *)((long)pppppppuVar7 + 0x1c) = iVar3;
  *(undefined1 *)(pppppppuVar7 + 4) = 0;
  pppppppuVar11 = pppppppuVar7;
  if ((undefined8 *******)*pppppppuStack_80 != (undefined8 *******)0x0) {
    pppppppuVar11 = (undefined8 *******)*pppppppuVar23;
    pppppppuStack_80 = (undefined8 *******)*pppppppuStack_80;
  }
  func_0x0040a8c0(pppppppuStack_78,pppppppuVar11);
  lStack_70 = lStack_70 + 1;
  pppppppuVar8 = pppppppuVar7;
LAB_006f7cbc:
  *(undefined1 *)(pppppppuVar8 + 4) = 1;
LAB_006f7cc4:
  lVar6 = plVar5[3];
  uVar25 = uVar25 + 1;
  if ((ulong)(plVar5[4] - lVar6 >> 3) <= uVar21) goto LAB_006f8250;
  goto LAB_006f7ce4;
  while (uVar25 = uVar25 + 1, uVar21 < uVar27) {
LAB_006f7f48:
    plVar13 = *(long **)(lVar6 + uVar21 * 8);
    lVar19 = *plVar13;
    if ((ulong)(plVar13[1] - lVar19 >> 2) <= uVar25) {
      iVar3 = (int)plVar5[0x15];
LAB_006f80d0:
      uVar25 = 0xffffffff;
      goto LAB_006f8208;
    }
    iVar20 = *(int *)(lVar19 + uVar25 * 4);
    if (*(int *)((long)plVar5 + 0xac) < iVar20) {
      iVar3 = (int)plVar5[0x15];
      if (iVar3 < iVar20) goto LAB_006f80d0;
      iVar3 = func_0x0043ea60(1000);
      lVar6 = *plVar5;
      lVar17 = plVar5[1];
      uVar27 = lVar17 - lVar6 >> 3;
      if (uVar27 <= uVar21) goto LAB_006f8284;
      lVar19 = *(long *)(lVar6 + uVar21 * 8);
      if ((ulong)(*(long *)(lVar19 + 0x20) - *(long *)(lVar19 + 0x18) >> 2) <= uVar25)
      goto LAB_006f829c;
      if (iVar3 < *(int *)(*(long *)(lVar19 + 0x18) + uVar25 * 4)) {
        lVar6 = plVar5[3];
        lVar17 = plVar5[4];
        if ((ulong)(lVar17 - lVar6 >> 3) <= uVar21) goto LAB_006f82b4;
        uVar25 = 0;
        iVar3 = 0;
        goto LAB_006f7fdc;
      }
    }
    else {
      uVar27 = lVar17 - lVar6 >> 3;
    }
  }
LAB_006f826c:
  if (plVar16[5] == lStack_68) {
    func_0x006f9ac0(plVar5);
LAB_006f8284:
    if (plVar16[5] == lStack_68) {
      func_0x006f9ac0(plVar5);
      lVar19 = extraout_x11;
LAB_006f829c:
      if (plVar16[5] == lStack_68) {
        func_0x00470c38(lVar19 + 0x18);
        goto LAB_006f82b4;
      }
    }
  }
  goto LAB_006f83a8;
LAB_006f7fdc:
  do {
    plVar13 = *(long **)(lVar6 + uVar21 * 8);
    lVar19 = *plVar13;
    if ((ulong)(plVar13[1] - lVar19 >> 2) <= uVar25) {
      iVar3 = func_0x0043ea60(iVar3);
      lVar6 = plVar5[3];
      lVar17 = plVar5[4];
      if ((ulong)(lVar17 - lVar6 >> 3) <= uVar21) goto LAB_006f82cc;
      uVar27 = 0;
      iVar20 = 0;
      goto LAB_006f810c;
    }
    iVar20 = *(int *)(lVar19 + uVar25 * 4);
    pppppppuVar11 = pppppppuStack_78;
    pppppppuVar8 = &pppppppuStack_78;
    while (pppppppuVar7 = pppppppuVar8, pppppppuVar23 = pppppppuVar8,
          pppppppuVar11 != (undefined8 *******)0x0) {
      while (pppppppuVar8 = pppppppuVar11, *(int *)((long)pppppppuVar8 + 0x1c) <= iVar20) {
        if (iVar20 <= *(int *)((long)pppppppuVar8 + 0x1c)) goto LAB_006f8088;
        pppppppuVar11 = (undefined8 *******)pppppppuVar8[1];
        if ((undefined8 *******)pppppppuVar8[1] == (undefined8 *******)0x0) {
          pppppppuVar23 = pppppppuVar8 + 1;
          pppppppuVar7 = pppppppuVar8;
          goto LAB_006f8030;
        }
      }
      pppppppuVar11 = (undefined8 *******)*pppppppuVar8;
    }
LAB_006f8030:
    pppppppuVar8 = (undefined8 *******)func_0x00bc3330(0x28);
    *pppppppuVar8 = (undefined8 ******)0x0;
    pppppppuVar8[1] = (undefined8 ******)0x0;
    pppppppuVar8[2] = pppppppuVar7;
    *pppppppuVar23 = pppppppuVar8;
    *(int *)((long)pppppppuVar8 + 0x1c) = iVar20;
    *(undefined1 *)(pppppppuVar8 + 4) = 0;
    pppppppuVar11 = pppppppuVar8;
    if ((undefined8 *******)*pppppppuStack_80 != (undefined8 *******)0x0) {
      pppppppuVar11 = (undefined8 *******)*pppppppuVar23;
      pppppppuStack_80 = (undefined8 *******)*pppppppuStack_80;
    }
    func_0x0040a8c0(pppppppuStack_78,pppppppuVar11);
    lStack_70 = lStack_70 + 1;
    lVar6 = plVar5[3];
    lVar17 = plVar5[4];
LAB_006f8088:
    uVar27 = lVar17 - lVar6 >> 3;
    if (*(char *)(pppppppuVar8 + 4) != '\0') {
      if (uVar27 <= uVar21) goto LAB_006f82e4;
      lVar19 = *(long *)(lVar6 + uVar21 * 8);
      if ((ulong)(*(long *)(lVar19 + 0x20) - *(long *)(lVar19 + 0x18) >> 2) <= uVar25)
      goto LAB_006f82fc;
      iVar3 = *(int *)(*(long *)(lVar19 + 0x18) + uVar25 * 4) + iVar3;
    }
    uVar25 = uVar25 + 1;
  } while (uVar21 < uVar27);
LAB_006f82b4:
  if (plVar16[5] == lStack_68) {
    func_0x006f9aac(plStack_b8);
    goto LAB_006f82cc;
  }
  goto LAB_006f83a8;
LAB_006f810c:
  do {
    plVar13 = *(long **)(lVar6 + uVar21 * 8);
    lVar19 = *plVar13;
    if ((ulong)(plVar13[1] - lVar19 >> 2) <= uVar27) {
      uVar25 = 0xffffffff;
LAB_006f8200:
      iVar3 = 0;
      *(undefined4 *)(plVar5 + 0x15) = 0;
LAB_006f8208:
      *(int *)((long)plVar5 + 0xac) = iVar3;
LAB_006f820c:
      func_0x0063fdd4(&pppppppuStack_80,pppppppuStack_78);
      goto LAB_006f7c0c;
    }
    uVar2 = *(uint *)(lVar19 + uVar27 * 4);
    uVar25 = (ulong)uVar2;
    pppppppuVar11 = pppppppuStack_78;
    pppppppuVar8 = &pppppppuStack_78;
    while (pppppppuVar7 = pppppppuVar8, pppppppuVar23 = pppppppuVar8,
          pppppppuVar11 != (undefined8 *******)0x0) {
      while (pppppppuVar8 = pppppppuVar11, *(int *)((long)pppppppuVar8 + 0x1c) <= (int)uVar2) {
        if ((int)uVar2 <= *(int *)((long)pppppppuVar8 + 0x1c)) goto LAB_006f81b8;
        pppppppuVar11 = (undefined8 *******)pppppppuVar8[1];
        if ((undefined8 *******)pppppppuVar8[1] == (undefined8 *******)0x0) {
          pppppppuVar23 = pppppppuVar8 + 1;
          pppppppuVar7 = pppppppuVar8;
          goto LAB_006f8160;
        }
      }
      pppppppuVar11 = (undefined8 *******)*pppppppuVar8;
    }
LAB_006f8160:
    pppppppuVar8 = (undefined8 *******)func_0x00bc3330(0x28);
    *pppppppuVar8 = (undefined8 ******)0x0;
    pppppppuVar8[1] = (undefined8 ******)0x0;
    pppppppuVar8[2] = pppppppuVar7;
    *pppppppuVar23 = pppppppuVar8;
    *(uint *)((long)pppppppuVar8 + 0x1c) = uVar2;
    *(undefined1 *)(pppppppuVar8 + 4) = 0;
    pppppppuVar11 = pppppppuVar8;
    if ((undefined8 *******)*pppppppuStack_80 != (undefined8 *******)0x0) {
      pppppppuVar11 = (undefined8 *******)*pppppppuVar23;
      pppppppuStack_80 = (undefined8 *******)*pppppppuStack_80;
    }
    func_0x0040a8c0(pppppppuStack_78,pppppppuVar11);
    lStack_70 = lStack_70 + 1;
    lVar6 = plVar5[3];
    lVar17 = plVar5[4];
LAB_006f81b8:
    uVar26 = lVar17 - lVar6 >> 3;
    if (*(char *)(pppppppuVar8 + 4) != '\0') {
      if (uVar21 < uVar26) {
        lVar19 = *(long *)(lVar6 + uVar21 * 8);
        if (uVar27 < (ulong)(*(long *)(lVar19 + 0x20) - *(long *)(lVar19 + 0x18) >> 2)) {
          iVar20 = *(int *)(*(long *)(lVar19 + 0x18) + uVar27 * 4) + iVar20;
          if (iVar3 < iVar20) goto LAB_006f8200;
          goto LAB_006f8100;
        }
        goto LAB_006f832c;
      }
      goto LAB_006f8314;
    }
LAB_006f8100:
    uVar27 = uVar27 + 1;
  } while (uVar21 < uVar26);
LAB_006f82cc:
  if (plVar16[5] == lStack_68) {
    func_0x006f9aac(plStack_b8);
LAB_006f82e4:
    if (plVar16[5] == lStack_68) {
      func_0x006f9aac(plStack_b8);
      lVar19 = extraout_x11_00;
LAB_006f82fc:
      if (plVar16[5] == lStack_68) {
        func_0x00470c38(lVar19 + 0x18);
LAB_006f8314:
        if (plVar16[5] == lStack_68) {
          func_0x006f9aac(plStack_b8);
          lVar19 = extraout_x11_01;
LAB_006f832c:
          if (plVar16[5] == lStack_68) {
            uVar4 = func_0x00470c38(lVar19 + 0x18);
            func_0x0063fdd4(&pppppppuStack_80,pppppppuStack_78);
            if (plVar16[5] == lStack_68) {
              func_0x00bbf40c(uVar4);
            }
          }
        }
      }
    }
  }
LAB_006f83a8:
  func_0x00bc3380();
  uVar21 = extraout_x1 & 0xffffffff;
  uVar2 = func_0x007a9764(extraout_x1 & 0xffffffff);
  uVar25 = (ulong)uVar2;
  iVar3 = func_0x007a9a18(uVar21);
  func_0x007adc58(uVar21);
  lVar6 = func_0x007fd748();
  uVar21 = func_0x007ab618(&UNK_0032b898 + lVar6,uVar21);
  if ((uVar21 & 1) != 0) {
    lVar6 = func_0x007fd748();
    iVar20 = (int)extraout_x1;
    puVar15 = *(undefined8 **)(&UNK_0038fc48 + lVar6);
    puVar12 = (undefined8 *)(&UNK_0038fc48 + lVar6);
    while (puVar24 = puVar12, puVar15 != (undefined8 *)0x0) {
      while (puVar9 = puVar15, puVar12 = puVar9, *(int *)((long)puVar9 + 0x1c) <= iVar20) {
        if (iVar20 <= *(int *)((long)puVar9 + 0x1c)) goto LAB_006f8498;
        puVar15 = (undefined8 *)puVar9[1];
        if ((undefined8 *)puVar9[1] == (undefined8 *)0x0) {
          puVar24 = puVar9 + 1;
          goto LAB_006f844c;
        }
      }
      puVar15 = (undefined8 *)*puVar9;
    }
LAB_006f844c:
    puVar9 = (undefined8 *)func_0x00bc3330(0x28);
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = puVar12;
    *puVar24 = puVar9;
    plVar16 = *(long **)(&UNK_0038fc40 + lVar6);
    *(int *)((long)puVar9 + 0x1c) = iVar20;
    *(undefined4 *)(puVar9 + 4) = 0;
    lVar17 = *plVar16;
    puVar12 = puVar9;
    if (lVar17 != 0) {
      *(long *)(&UNK_0038fc40 + lVar6) = lVar17;
      puVar12 = (undefined8 *)*puVar24;
    }
    func_0x0040a8c0(*(undefined8 *)(&UNK_0038fc48 + lVar6),puVar12);
    *(long *)(&UNK_0038fc50 + lVar6) = *(long *)(&UNK_0038fc50 + lVar6) + 1;
LAB_006f8498:
    *(undefined4 *)(puVar9 + 4) = 0;
  }
  if (uVar2 < 5) {
    uVar21 = func_0x007fd748();
    (&UNK_0033b8a0)[uVar21 + (ulong)uVar2 * 2000 + (long)iVar3 * 4] = 0;
    return uVar21;
  }
  switch(uVar2) {
  case 0xffffffe6:
    uVar25 = func_0x007fd748();
    lVar6 = *(long *)(uVar25 + 0x20);
    goto code_r0x007b0db4;
  case 0xffffffe8:
    uVar25 = func_0x007fd748();
    lVar6 = *(long *)(uVar25 + 0x510);
    goto code_r0x007b0db4;
  case 0xffffffe9:
    uVar25 = func_0x007fd748();
    lVar6 = *(long *)(uVar25 + 0x700);
    goto code_r0x007b0db4;
  case 0xffffffea:
    uVar25 = func_0x007fd748();
    lVar6 = *(long *)(uVar25 + 0x968);
code_r0x007b0db4:
    puVar18 = *(undefined1 **)(lVar6 + (long)iVar3 * 0x18);
code_r0x007b0e34:
    *puVar18 = 0;
    break;
  case 0xffffffec:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe050;
    goto code_r0x007b0e28;
  case 0xffffffed:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe080;
    goto code_r0x007b0dd4;
  case 0xffffffee:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe038;
    goto code_r0x007b0e28;
  case 0xffffffef:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe068;
code_r0x007b0dd4:
    puVar18 = (undefined1 *)(*(long *)(uVar25 + (uVar2 | 0x330000)) + (long)iVar3);
    goto code_r0x007b0e34;
  case 0xfffffff0:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe020;
    goto code_r0x007b0e28;
  case 0xfffffff5:
    uVar25 = func_0x007fd748();
    uVar2 = 0xe008;
code_r0x007b0e28:
    puVar18 = (undefined1 *)(*(long *)(uVar25 + (uVar2 | 0x330000)) + (long)iVar3 * 4);
    goto code_r0x007b0e34;
  case 0xfffffff6:
    uVar25 = func_0x007fd748();
    uVar2 = 0xdff0;
    goto code_r0x007b0dec;
  case 0xfffffff7:
    uVar25 = func_0x007fd748();
    uVar2 = 0xdfd8;
    goto code_r0x007b0dec;
  case 0xfffffff9:
    uVar25 = func_0x007fd748();
    *(undefined4 *)(uVar25 + (long)iVar3 * 4 + 0xc950) = 0;
    break;
  case 0xfffffffa:
    uVar25 = func_0x007fd748();
    *(undefined4 *)(&UNK_0033dfc8 + uVar25 + (long)iVar3 * 0x10) = 0;
    break;
  case 0xfffffffc:
    uVar25 = func_0x007fd748();
    uVar2 = 0xdfb0;
code_r0x007b0dec:
    *(undefined4 *)(*(long *)(uVar25 + (uVar2 | 0x330000)) + (long)iVar3 * 0x10) = 0;
    break;
  case 0xfffffffd:
    uVar25 = func_0x007fd748();
    *(undefined4 *)(uVar25 + (long)iVar3 * 4 + 0xc944) = 0;
    break;
  case 0xfffffffe:
    uVar25 = func_0x007fd748();
    *(undefined4 *)(uVar25 + (long)iVar3 * 4 + 0xc934) = 0;
  }
  return uVar25;
}


