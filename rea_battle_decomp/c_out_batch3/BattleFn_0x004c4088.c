// ELF VMA: 0x004c4088 | Ghidra Addr: 0x005c4088 | BodySize: 3036

/* WARNING: Type propagation algorithm not settling */

void BattleFn_0x004c4088(long param_1)

{
  bool bVar1;
  long *plVar2;
  ulong uVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 **ppuVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  ulong *puVar17;
  undefined8 uVar18;
  ulong uVar19;
  undefined8 *puVar20;
  int *piVar21;
  undefined8 *puVar22;
  long lVar23;
  long *plVar24;
  int iVar25;
  long *plVar26;
  ulong uVar27;
  undefined8 *puVar28;
  ulong uVar29;
  long *plVar30;
  long lVar31;
  ulong uVar32;
  undefined8 *puVar33;
  int iStack_2ac;
  ulong uStack_2a0;
  undefined8 uStack_298;
  undefined8 *puStack_290;
  ulong uStack_280;
  undefined8 uStack_278;
  undefined8 *puStack_270;
  ulong uStack_260;
  undefined8 uStack_258;
  undefined8 *puStack_250;
  ulong uStack_240;
  undefined8 uStack_238;
  undefined8 *puStack_230;
  ulong uStack_220;
  ulong uStack_218;
  ulong uStack_210;
  ulong uStack_200;
  undefined8 uStack_1f8;
  undefined8 *puStack_1f0;
  ulong uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 *puStack_1d0;
  ulong uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 *puStack_1b0;
  ulong uStack_1a0;
  undefined8 uStack_198;
  undefined8 *puStack_190;
  ulong uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  ulong uStack_160;
  undefined8 uStack_158;
  undefined8 *puStack_150;
  ulong uStack_140;
  undefined8 uStack_138;
  undefined8 *puStack_130;
  ulong uStack_120;
  undefined8 uStack_118;
  undefined8 *apuStack_110 [2];
  ulong uStack_100;
  undefined8 uStack_f8;
  undefined8 *puStack_f0;
  ulong uStack_e0;
  undefined8 uStack_d8;
  undefined8 *puStack_d0;
  byte abStack_c8 [16];
  undefined8 uStack_b8;
  ulong uStack_b0;
  ulong uStack_a8;
  ulong uStack_a0;
  ulong uStack_90;
  undefined8 uStack_88;
  undefined8 *puStack_80;
  long lStack_70;
  
  lVar7 = tpidr_el0;
  plVar2 = (long *)(&UNK_00338930 + param_1);
  lStack_70 = *(long *)(lVar7 + 0x28);
  lVar31 = *plVar2;
  if (*(long *)(&UNK_00338938 + param_1) != lVar31) {
    uVar27 = 0;
    iVar25 = 0;
    do {
      piVar21 = *(int **)(lVar31 + uVar27 * 8);
      iVar5 = piVar21[2];
      iVar16 = *piVar21;
      piVar21[2] = iVar5 + 1;
      puStack_80 = (undefined8 *)func_0x00bc3330(0x20);
      *(undefined1 *)((long)puStack_80 + 0x17) = 0;
      uStack_88 = 0x17;
      uStack_90 = 0x21;
      puStack_80[1] = 0x6e6f69736f6c7078;
      *puStack_80 = 0x655f656c74746162;
      *(undefined8 *)((long)puStack_80 + 0xf) = 0x34656d6172665f6e;
      iVar9 = func_0x008e3f14(param_1 + 0x1478,&uStack_90,0xf);
      iVar11 = 0;
      if (iVar9 != 0) {
        iVar11 = (iVar5 + 1) / iVar9;
      }
      uVar10 = func_0x0043ed84(iVar11 + 1,3);
      if ((uStack_90 & 1) != 0) {
        func_0x00bc3350(puStack_80);
      }
      if (0 < (int)uVar10) {
        iVar5 = 1 - iVar16;
        uVar29 = 0;
        do {
          uVar3 = uVar29 + 1;
          func_0x00bc33f0(abStack_c8);
          puVar17 = (ulong *)func_0x00bc3400(abStack_c8,0,&UNK_002a56a8);
          uStack_a0 = puVar17[2];
          uStack_a8 = puVar17[1];
          uStack_b0 = *puVar17;
          uVar6 = *(undefined4 *)(&UNK_002bef28 + uVar29 * 4);
          puVar17[1] = 0;
          puVar17[2] = 0;
          *puVar17 = 0;
          iVar11 = func_0x008e3f14(param_1 + 0x1478,&uStack_b0,uVar6);
          if ((uStack_b0 & 1) != 0) {
            func_0x00bc3350(uStack_a0);
          }
          if ((abStack_c8[0] & 1) != 0) {
            func_0x00bc3350(uStack_b8);
          }
          iVar9 = (int)uVar29;
          if (iVar9 == 2) {
            apuStack_110[0] = (undefined8 *)func_0x00bc3330(0x20);
            uStack_118 = 0x17;
            uStack_120 = 0x21;
            *(undefined1 *)((long)apuStack_110[0] + 0x17) = 0;
            apuStack_110[0][1] = 0x6e6f69736f6c7078;
            *apuStack_110[0] = 0x655f656c74746162;
            *(undefined8 *)((long)apuStack_110[0] + 0xf) = 0x3168746469775f6e;
            iVar12 = func_0x008e3f14(param_1 + 0x1478,&uStack_120,800);
            puStack_130 = (undefined8 *)func_0x00bc3330(0x20);
            uStack_138 = 0x17;
            uStack_140 = 0x21;
            puStack_130[1] = 0x6e6f69736f6c7078;
            *puStack_130 = 0x655f656c74746162;
            *(undefined8 *)((long)puStack_130 + 0xf) = 0x3268746469775f6e;
            *(undefined1 *)((long)puStack_130 + 0x17) = 0;
            iVar13 = func_0x008e3f14(param_1 + 0x1478,&uStack_140,500);
            puStack_150 = (undefined8 *)func_0x00bc3330(0x20);
            uStack_158 = 0x17;
            uStack_160 = 0x21;
            puStack_150[1] = 0x6e6f69736f6c7078;
            *puStack_150 = 0x655f656c74746162;
            *(undefined8 *)((long)puStack_150 + 0xf) = 0x3368746469775f6e;
            *(undefined1 *)((long)puStack_150 + 0x17) = 0;
            iStack_2ac = func_0x008e3f14(param_1 + 0x1478,&uStack_160,400);
            if ((uStack_160 & 1) != 0) {
              func_0x00bc3350(puStack_150);
            }
            if ((uStack_140 & 1) != 0) {
              func_0x00bc3350(puStack_130);
            }
            iStack_2ac = iVar12 + iVar13 * 2 + iStack_2ac;
            ppuVar8 = apuStack_110;
            uVar32 = uStack_120;
joined_r0x005c4460:
            if ((uVar32 & 1) != 0) {
              func_0x00bc3350(*ppuVar8);
            }
          }
          else {
            if (iVar9 == 1) {
              puStack_d0 = (undefined8 *)func_0x00bc3330(0x20);
              uStack_d8 = 0x17;
              uStack_e0 = 0x21;
              *(undefined1 *)((long)puStack_d0 + 0x17) = 0;
              puStack_d0[1] = 0x6e6f69736f6c7078;
              *puStack_d0 = 0x655f656c74746162;
              *(undefined8 *)((long)puStack_d0 + 0xf) = 0x3168746469775f6e;
              iVar12 = func_0x008e3f14(param_1 + 0x1478,&uStack_e0,800);
              puStack_f0 = (undefined8 *)func_0x00bc3330(0x20);
              uStack_f8 = 0x17;
              uStack_100 = 0x21;
              puStack_f0[1] = 0x6e6f69736f6c7078;
              *puStack_f0 = 0x655f656c74746162;
              *(undefined8 *)((long)puStack_f0 + 0xf) = 0x3268746469775f6e;
              *(undefined1 *)((long)puStack_f0 + 0x17) = 0;
              iStack_2ac = func_0x008e3f14(param_1 + 0x1478,&uStack_100,500);
              if ((uStack_100 & 1) != 0) {
                func_0x00bc3350(puStack_f0);
              }
              iStack_2ac = iStack_2ac + iVar12;
              ppuVar8 = &puStack_d0;
              uVar32 = uStack_e0;
              goto joined_r0x005c4460;
            }
            iStack_2ac = 0;
          }
          if ((ulong)(*(long *)(&UNK_00338938 + param_1) - *plVar2 >> 3) <= uVar27)
          goto LAB_005c4c24;
          iVar12 = *(int *)(*(long *)(*plVar2 + uVar27 * 8) + 8);
          puStack_170 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_170 + 0x17) = 0;
          uStack_178 = 0x17;
          uStack_180 = 0x21;
          puStack_170[1] = 0x6e6f69736f6c7078;
          *puStack_170 = 0x655f656c74746162;
          *(undefined8 *)((long)puStack_170 + 0xf) = 0x34656d6172665f6e;
          iVar13 = func_0x008e3f14(param_1 + 0x1478,&uStack_180,0xf);
          if ((uStack_180 & 1) != 0) {
            func_0x00bc3350(puStack_170);
          }
          puStack_190 = (undefined8 *)func_0x00bc3330(0x20);
          uStack_198 = 0x17;
          uStack_1a0 = 0x21;
          *(undefined1 *)((long)puStack_190 + 0x17) = 0;
          puStack_190[1] = 0x6e6f69736f6c7078;
          *puStack_190 = 0x655f656c74746162;
          *(undefined8 *)((long)puStack_190 + 0xf) = 0x31656d6172665f6e;
          iVar14 = func_0x008e3f14(param_1 + 0x1478,&uStack_1a0,0xf);
          if ((uStack_1a0 & 1) != 0) {
            func_0x00bc3350(puStack_190);
          }
          iVar12 = iVar12 - iVar13 * iVar9;
          if (iVar12 == iVar14) {
            uVar18 = func_0x0044c16c();
            func_0x0044e364(uVar18,iVar9 + 0xa7);
          }
          puStack_1b0 = (undefined8 *)func_0x00bc3330(0x20);
          *(undefined1 *)((long)puStack_1b0 + 0x17) = 0;
          uStack_1b8 = 0x17;
          uStack_1c0 = 0x21;
          puStack_1b0[1] = 0x6e6f69736f6c7078;
          *puStack_1b0 = 0x655f656c74746162;
          *(undefined8 *)((long)puStack_1b0 + 0xf) = 0x31656d6172665f6e;
          iVar9 = func_0x008e3f14(param_1 + 0x1478,&uStack_1c0,0xf);
          if (iVar12 < iVar9) {
            bVar1 = false;
joined_r0x005c4670:
            if ((uStack_1c0 & 1) != 0) goto LAB_005c4674;
LAB_005c465c:
            if (bVar1) goto LAB_005c4680;
          }
          else {
            puStack_1d0 = (undefined8 *)func_0x00bc3330(0x20);
            *(undefined1 *)((long)puStack_1d0 + 0x17) = 0;
            uStack_1d8 = 0x17;
            uStack_1e0 = 0x21;
            puStack_1d0[1] = 0x6e6f69736f6c7078;
            *puStack_1d0 = 0x655f656c74746162;
            *(undefined8 *)((long)puStack_1d0 + 0xf) = 0x31656d6172665f6e;
            iVar9 = func_0x008e3f14(param_1 + 0x1478,&uStack_1e0,0xf);
            puStack_1f0 = (undefined8 *)func_0x00bc3330(0x20);
            uStack_1f8 = 0x17;
            uStack_200 = 0x21;
            puStack_1f0[1] = 0x6e6f69736f6c7078;
            *puStack_1f0 = 0x655f656c74746162;
            *(undefined8 *)((long)puStack_1f0 + 0xf) = 0x32656d6172665f6e;
            *(undefined1 *)((long)puStack_1f0 + 0x17) = 0;
            iVar13 = func_0x008e3f14(param_1 + 0x1478,&uStack_200,0x14);
            bVar1 = iVar12 < iVar13 + iVar9;
            if ((uStack_200 & 1) != 0) {
              func_0x00bc3350(puStack_1f0);
            }
            if ((uStack_1e0 & 1) != 0) {
              func_0x00bc3350(puStack_1d0);
              goto joined_r0x005c4670;
            }
            if ((uStack_1c0 & 1) == 0) goto LAB_005c465c;
LAB_005c4674:
            func_0x00bc3350(puStack_1b0);
            if (bVar1) {
LAB_005c4680:
              uVar32 = 1;
              iVar9 = iStack_2ac;
              if (iStack_2ac < 0) {
                iVar9 = iStack_2ac + 1;
              }
              if (iVar11 < 0) {
                iVar11 = iVar11 + 1;
              }
              do {
                iVar12 = func_0x00a58874(iVar5,uVar32 & 0xffffffff);
                if (iVar12 != 0) {
                  if ((ulong)(*(long *)(&UNK_00338938 + param_1) - *plVar2 >> 3) <= uVar27)
                  goto LAB_005c4c24;
                  uVar19 = func_0x00a58df4(iVar5,uVar32 & 0xffffffff,
                                           *(undefined4 *)(*(long *)(*plVar2 + uVar27 * 8) + 4));
                  if ((uVar19 & 1) != 0) {
                    if (iVar16 == 1) {
                      iVar12 = func_0x00a5919c(0,uVar32 & 0xffffffff);
                      iVar12 = *(int *)(param_1 + uVar32 * 1000 + 0x83940) + iVar12;
                    }
                    else {
                      iVar12 = func_0x00a5919c(iVar5,uVar32 & 0xffffffff);
                      iVar12 = iVar12 - *(int *)(param_1 + (long)iVar5 * 51000 + uVar32 * 1000 +
                                                0x83940);
                    }
                    iVar13 = 0;
                    bVar1 = true;
LAB_005c47a4:
                    lVar31 = 0;
                    if (!bVar1) {
                      lVar31 = 2;
                    }
                    if (uVar27 < (ulong)(*(long *)(&UNK_00338938 + param_1) - *plVar2 >> 3)) {
                      lVar23 = *(long *)(*plVar2 + uVar27 * 8);
                      uVar19 = lVar31 + uVar29;
                      plVar24 = *(long **)(lVar23 + 0x30);
                      for (plVar26 = plVar24; plVar26 != (long *)0x0; plVar26 = (long *)*plVar26) {
                        if ((long)*(int *)((long)plVar26 + 0x1c) <= (long)uVar32) {
                          if ((long)uVar32 <= (long)*(int *)((long)plVar26 + 0x1c))
                          goto LAB_005c47fc;
                          plVar26 = plVar26 + 1;
                        }
                      }
                      goto LAB_005c482c;
                    }
                    goto LAB_005c4c24;
                  }
                }
LAB_005c46a8:
                uVar32 = uVar32 + 1;
              } while (uVar32 != 0x33);
            }
          }
          uVar29 = uVar3;
        } while (uVar3 != uVar10);
      }
      if ((ulong)(*(long *)(&UNK_00338938 + param_1) - *plVar2 >> 3) <= uVar27) {
LAB_005c4c24:
        if (*(long *)(lVar7 + 0x28) == lStack_70) {
          func_0x005c8e3c(plVar2);
LAB_005c4c40:
          if (*(long *)(lVar7 + 0x28) == lStack_70) {
                    /* WARNING: Subroutine does not return */
            NoRet_0x00311610(&UNK_0029c2ff);
          }
        }
        goto LAB_005c4e8c;
      }
      iVar5 = *(int *)(*(long *)(*plVar2 + uVar27 * 8) + 8);
      puStack_230 = (undefined8 *)func_0x00bc3330(0x20);
      *(undefined1 *)((long)puStack_230 + 0x17) = 0;
      uStack_238 = 0x17;
      uStack_240 = 0x21;
      puStack_230[1] = 0x6e6f69736f6c7078;
      *puStack_230 = 0x655f656c74746162;
      *(undefined8 *)((long)puStack_230 + 0xf) = 0x34656d6172665f6e;
      iVar16 = func_0x008e3f14(param_1 + 0x1478,&uStack_240,0xf);
      puStack_250 = (undefined8 *)func_0x00bc3330(0x20);
      uStack_258 = 0x17;
      uStack_260 = 0x21;
      puStack_250[1] = 0x6e6f69736f6c7078;
      *puStack_250 = 0x655f656c74746162;
      *(undefined8 *)((long)puStack_250 + 0xf) = 0x31656d6172665f6e;
      *(undefined1 *)((long)puStack_250 + 0x17) = 0;
      iVar11 = func_0x008e3f14(param_1 + 0x1478,&uStack_260,0xf);
      puStack_270 = (undefined8 *)func_0x00bc3330(0x20);
      uStack_278 = 0x17;
      uStack_280 = 0x21;
      puStack_270[1] = 0x6e6f69736f6c7078;
      *puStack_270 = 0x655f656c74746162;
      *(undefined8 *)((long)puStack_270 + 0xf) = 0x32656d6172665f6e;
      *(undefined1 *)((long)puStack_270 + 0x17) = 0;
      iVar9 = func_0x008e3f14(param_1 + 0x1478,&uStack_280,0x14);
      puStack_290 = (undefined8 *)func_0x00bc3330(0x20);
      uStack_298 = 0x17;
      uStack_2a0 = 0x21;
      puStack_290[1] = 0x6e6f69736f6c7078;
      *puStack_290 = 0x655f656c74746162;
      *(undefined8 *)((long)puStack_290 + 0xf) = 0x33656d6172665f6e;
      *(undefined1 *)((long)puStack_290 + 0x17) = 0;
      iVar12 = func_0x008e3f14(param_1 + 0x1478,&uStack_2a0,10);
      if ((uStack_2a0 & 1) != 0) {
        func_0x00bc3350(puStack_290);
      }
      if ((uStack_280 & 1) != 0) {
        func_0x00bc3350(puStack_270);
      }
      if ((uStack_260 & 1) != 0) {
        func_0x00bc3350(puStack_250);
      }
      if ((uStack_240 & 1) != 0) {
        func_0x00bc3350(puStack_230);
      }
      lVar31 = *plVar2;
      plVar26 = *(long **)(&UNK_00338938 + param_1);
      if (iVar11 + iVar16 * 2 + iVar9 + iVar12 <= iVar5) {
        plVar30 = (long *)(lVar31 + uVar27 * 8);
        plVar24 = plVar30 + 1;
        if (plVar24 != plVar26) {
          do {
            lVar31 = plVar24[-1];
            plVar24[-1] = *plVar24;
            *plVar24 = 0;
            if (lVar31 != 0) {
              func_0x005c8e50(lVar31 + 0x28,*(undefined8 *)(lVar31 + 0x30));
              func_0x00bc3350(lVar31);
            }
            plVar24 = plVar24 + 1;
            plVar30 = plVar30 + 1;
          } while (plVar24 != plVar26);
          plVar26 = *(long **)(&UNK_00338938 + param_1);
        }
        while (plVar26 != plVar30) {
          plVar26 = plVar26 + -1;
          lVar31 = *plVar26;
          *plVar26 = 0;
          if (lVar31 != 0) {
            func_0x005c8e50(lVar31 + 0x28,*(undefined8 *)(lVar31 + 0x30));
            func_0x00bc3350(lVar31);
          }
        }
        lVar31 = *plVar2;
        iVar25 = iVar25 + -1;
        *(long **)(&UNK_00338938 + param_1) = plVar30;
        plVar26 = plVar30;
      }
      iVar25 = iVar25 + 1;
      uVar27 = (ulong)iVar25;
    } while (uVar27 < (ulong)((long)plVar26 - lVar31 >> 3));
  }
  if (*(long *)(lVar7 + 0x28) == lStack_70) {
    return;
  }
LAB_005c4e8c:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
LAB_005c47fc:
  if ((long)uVar32 < (long)*(int *)((long)plVar24 + 0x1c)) {
    plVar24 = (long *)*plVar24;
  }
  else {
    if ((long)uVar32 <= (long)*(int *)((long)plVar24 + 0x1c)) goto LAB_005c4818;
    plVar24 = (long *)plVar24[1];
  }
  if (plVar24 == (long *)0x0) {
    if (*(long *)(lVar7 + 0x28) == lStack_70) {
                    /* WARNING: Subroutine does not return */
      NoRet_0x00311610(&UNK_00289c18);
    }
    goto LAB_005c4e8c;
  }
  goto LAB_005c47fc;
LAB_005c4818:
  if (4 < uVar19) goto LAB_005c4c40;
  if (*(char *)((long)plVar24 + uVar19 + 0x20) == '\0') {
LAB_005c482c:
    iVar13 = (iVar13 * iStack_2ac - (iVar9 >> 1)) + *(int *)(lVar23 + 0xc);
    if ((iVar13 - (iVar11 >> 1) <= iVar12) && (iVar12 < iVar13 + (iVar11 >> 1))) {
      uVar6 = *(undefined4 *)(lVar23 + 0x10);
      func_0x00bc33f0(abStack_c8,uVar3);
      puVar17 = (ulong *)func_0x00bc3400(abStack_c8,0,&UNK_002a04c4);
      uStack_210 = puVar17[2];
      uStack_218 = puVar17[1];
      uStack_220 = *puVar17;
      uVar15 = *(undefined4 *)(&UNK_002bef34 + uVar29 * 4);
      puVar17[1] = 0;
      puVar17[2] = 0;
      *puVar17 = 0;
      uVar15 = func_0x008e3f14(param_1 + 0x1478,&uStack_220,uVar15);
      func_0x006dbabc(param_1,iVar25,uVar32 & 0xffffffff,uVar6,uVar15);
      if ((uStack_220 & 1) != 0) {
        func_0x00bc3350(uStack_210);
      }
      if ((abStack_c8[0] & 1) != 0) {
        func_0x00bc3350(uStack_b8);
      }
      if ((ulong)(*(long *)(&UNK_00338938 + param_1) - *plVar2 >> 3) <= uVar27) goto LAB_005c4c24;
      lVar31 = *(long *)(*plVar2 + uVar27 * 8);
      puVar22 = *(undefined8 **)(lVar31 + 0x30);
      puVar28 = (undefined8 *)(lVar31 + 0x30);
      while (puVar33 = puVar28, puVar22 != (undefined8 *)0x0) {
        while (puVar20 = puVar22, (long)*(int *)((long)puVar20 + 0x1c) <= (long)uVar32) {
          if ((long)uVar32 <= (long)*(int *)((long)puVar20 + 0x1c)) goto LAB_005c4774;
          puVar22 = (undefined8 *)puVar20[1];
          if ((undefined8 *)puVar20[1] == (undefined8 *)0x0) {
            puVar28 = puVar20 + 1;
            puVar33 = puVar20;
            goto LAB_005c4940;
          }
        }
        puVar28 = puVar20;
        puVar22 = (undefined8 *)*puVar20;
      }
LAB_005c4940:
      puVar20 = (undefined8 *)func_0x00bc3330(0x28);
      *(int *)((long)puVar20 + 0x1c) = (int)uVar32;
      *(undefined4 *)(puVar20 + 4) = 0;
      *(undefined1 *)((long)puVar20 + 0x24) = 0;
      *puVar20 = 0;
      puVar20[1] = 0;
      puVar20[2] = puVar33;
      *puVar28 = puVar20;
      puVar22 = puVar20;
      if (**(long **)(lVar31 + 0x28) != 0) {
        *(long *)(lVar31 + 0x28) = **(long **)(lVar31 + 0x28);
        puVar22 = (undefined8 *)*puVar28;
      }
      func_0x0040a8c0(*(undefined8 *)(lVar31 + 0x30),puVar22);
      *(long *)(lVar31 + 0x38) = *(long *)(lVar31 + 0x38) + 1;
LAB_005c4774:
      *(undefined1 *)((long)puVar20 + uVar19 + 0x20) = 1;
    }
  }
  bVar4 = (bool)(uVar29 != 0 & bVar1);
  iVar13 = 1;
  bVar1 = false;
  if (!bVar4) goto LAB_005c46a8;
  goto LAB_005c47a4;
}


