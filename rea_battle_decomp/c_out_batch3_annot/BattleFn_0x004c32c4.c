// ELF VMA: 0x004c32c4 | Ghidra Addr: 0x005c32c4 | BodySize: 1620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004c32c4(long param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  ulong uVar18;
  undefined8 *puVar19;
  long lVar20;
  undefined8 *puVar21;
  long lVar22;
  undefined8 *puVar23;
  long *plVar24;
  undefined8 *puVar25;
  long *plVar26;
  long lVar27;
  long lVar28;
  int *piVar29;
  long lVar30;
  long lVar31;
  ulong uVar32;
  long *plVar33;
  ulong uVar34;
  int iVar35;
  undefined1 auVar36 [16];
  ulong auStack_1f0 [2];
  undefined8 *puStack_1e0;
  undefined8 *puStack_1d8;
  ulong auStack_1d0 [2];
  undefined8 *puStack_1c0;
  ulong auStack_1b0 [2];
  undefined8 *puStack_1a0;
  long lStack_190;
  
  plVar2 = (long *)(&UNK_00338900 + param_1);  /* field_off=0x338900 */
  plVar26 = (long *)*plVar2;
  plVar24 = *(long **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
  if (plVar24 != plVar26) {
    uVar32 = 0;
    iVar35 = 0;
    do {
      iVar13 = _DAT_00c0ad7c;
      plVar33 = plVar26 + uVar32;
      lVar27 = *plVar33;
      iVar11 = *(int *)(lVar27 + 8);
      iVar1 = iVar11 + 1;
      *(int *)(lVar27 + 8) = iVar1;
      iVar1 = iVar1 - iVar13;
      if (iVar1 < 0) {
        if (iVar11 == 0) {
          uVar17 = func_0x0044c16c();
          func_0x0044e364(uVar17,0x6f);
        }
      }
      else {
        iVar11 = *(int *)(lVar27 + 0x10) * _DAT_00c0ad80;
        if (iVar1 < iVar11) {
          iVar11 = 0;
          if (_DAT_00c0ad80 != 0) {
            iVar11 = iVar1 / _DAT_00c0ad80;
          }
          if (iVar1 == iVar11 * _DAT_00c0ad80) {
            func_0x005b095c(param_1 + 0x10d0,2);
            uVar17 = func_0x0044c16c();
            func_0x0044e364(uVar17,0x70);
            plVar26 = (long *)*plVar2;
            plVar24 = *(long **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
          }
          iVar13 = (int)param_4;
          iVar11 = (int)param_3;
          if (uVar32 < (ulong)((long)plVar24 - (long)plVar26 >> 3)) {
            uVar34 = 1;
            iVar4 = *(int *)plVar26[uVar32];
            iVar12 = 0;
            if (_DAT_00c0ad80 != 0) {
              iVar12 = iVar1 / _DAT_00c0ad80;
            }
            iVar1 = 1 - iVar4;
LAB_005c3450:
            iVar10 = func_0x00a58874(iVar1,uVar34 & 0xffffffff);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
            iVar13 = (int)param_4;
            iVar11 = (int)param_3;
            if (iVar10 == 0) goto LAB_005c3444;
            if (uVar32 < (ulong)(*(long *)(&UNK_00338908 + param_1) - *plVar2 >> 3)) {  /* field_off=0x338908 */
              param_3 = (ulong)*(uint *)(*(long *)(*plVar2 + uVar32 * 8) + 4);
              uVar18 = func_0x00a58df4(iVar1,uVar34 & 0xffffffff);  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
              iVar13 = (int)param_4;
              iVar11 = (int)param_3;
              if ((uVar18 & 1) == 0) goto LAB_005c3444;
              if (uVar32 < (ulong)(*(long *)(&UNK_00338908 + param_1) - *plVar2 >> 3)) {  /* field_off=0x338908 */
                plVar24 = *(long **)(*(long *)(*plVar2 + uVar32 * 8) + 0x38);
                for (plVar26 = plVar24; plVar26 != (long *)0x0; plVar26 = (long *)*plVar26) {
                  if ((long)*(int *)((long)plVar26 + 0x1c) <= (long)uVar34) {
                    if ((long)uVar34 <= (long)*(int *)((long)plVar26 + 0x1c)) goto LAB_005c34d4;
                    plVar26 = plVar26 + 1;
                  }
                }
                goto LAB_005c3500;
              }
            }
          }
LAB_005c3724:
          auVar36 = func_0x005c8c40(plVar2);
          lVar22 = auVar36._8_8_;
          lVar20 = auVar36._0_8_;
          plVar2 = (long *)(&UNK_00338900 + lVar20);  /* field_off=0x338900 */
          uVar17 = func_0x00438a58();
          lVar27 = *plVar2;
          lVar30 = *(long *)(&UNK_00338908 + lVar20);  /* field_off=0x338908 */
          if (lVar30 == lVar27) {
            return;
          }
          lVar28 = lVar22 + (long)iVar11 * 0xa8;
          uVar32 = 0;
          goto LAB_005c386c;
        }
        if (_DAT_00c0ad84 + iVar11 <= iVar1) {
          plVar26 = plVar33 + 1;
          if (plVar26 != plVar24) {
            do {
              lVar27 = plVar26[-1];
              plVar26[-1] = *plVar26;
              *plVar26 = 0;
              if (lVar27 != 0) {
                func_0x0058c04c(lVar27 + 0x30,*(undefined8 *)(lVar27 + 0x38));
                func_0x00bc3350(lVar27);
              }
              plVar26 = plVar26 + 1;
              plVar33 = plVar33 + 1;
            } while (plVar26 != plVar24);
            plVar24 = *(long **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
          }
          while (plVar24 != plVar33) {
            plVar24 = plVar24 + -1;
            lVar27 = *plVar24;
            *plVar24 = 0;
            if (lVar27 != 0) {
              func_0x0058c04c(lVar27 + 0x30,*(undefined8 *)(lVar27 + 0x38));
              func_0x00bc3350(lVar27);
            }
          }
          *(long **)(&UNK_00338908 + param_1) = plVar33;  /* field_off=0x338908 */
          iVar35 = iVar35 + -1;
        }
      }
LAB_005c332c:
      plVar26 = (long *)*plVar2;
      plVar24 = *(long **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
      iVar35 = iVar35 + 1;
      uVar32 = (ulong)iVar35;
    } while (uVar32 < (ulong)((long)plVar24 - (long)plVar26 >> 3));
  }
  return;
LAB_005c34d4:
  if ((long)uVar34 < (long)*(int *)((long)plVar24 + 0x1c)) {
    plVar24 = (long *)*plVar24;
  }
  else {
    if ((long)uVar34 <= (long)*(int *)((long)plVar24 + 0x1c)) goto LAB_005c34f0;
    plVar24 = (long *)plVar24[1];
  }
  if (plVar24 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00311610(&UNK_00289c18);  /* UNK_289c18(vma=0x189c18)='map::at:  key not found' */
  }
  goto LAB_005c34d4;
LAB_005c34f0:
  if ((int)plVar24[4] != iVar12) {
LAB_005c3500:
    if (iVar4 == 1) {
      iVar11 = func_0x00a5919c(0,uVar34 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
      iVar10 = (*(int *)(param_1 + uVar34 * 1000 + 0x83940) + iVar11) - _DAT_00c0ad88;
    }
    else {
      iVar11 = func_0x00a5919c(iVar1,uVar34 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
      iVar10 = (iVar11 - *(int *)(param_1 + (long)iVar1 * 51000 + uVar34 * 1000 + 0x83940)) +
               _DAT_00c0ad88;
    }
    iVar13 = (int)param_4;
    iVar11 = (int)param_3;
    if ((ulong)(*(long *)(&UNK_00338908 + param_1) - *plVar2 >> 3) <= uVar32) goto LAB_005c3724;  /* field_off=0x338908 */
    lVar27 = *(long *)(*plVar2 + uVar32 * 8);
    iVar13 = *(int *)(lVar27 + 0xc);
    iVar11 = _DAT_00c0ad78;
    if (_DAT_00c0ad78 < 0) {
      iVar11 = _DAT_00c0ad78 + 1;
    }
    if (iVar13 - (iVar11 >> 1) <= iVar10) {
      iVar11 = _DAT_00c0ad78;
      if (_DAT_00c0ad78 < 0) {
        iVar11 = _DAT_00c0ad78 + 1;
      }
      if (iVar10 < iVar13 + (iVar11 >> 1)) {
        param_4 = (ulong)*(uint *)(lVar27 + 0x14);
        param_3 = uVar34 & 0xffffffff;
        func_0x006db6ac(param_1,iVar35);
        iVar13 = (int)param_4;
        iVar11 = (int)param_3;
        if ((ulong)(*(long *)(&UNK_00338908 + param_1) - *plVar2 >> 3) <= uVar32) goto LAB_005c3724;  /* field_off=0x338908 */
        lVar27 = *(long *)(*plVar2 + uVar32 * 8);
        puVar25 = *(undefined8 **)(lVar27 + 0x38);
        puVar23 = (undefined8 *)(lVar27 + 0x38);
        while (puVar21 = puVar23, puVar25 != (undefined8 *)0x0) {
          while (puVar19 = puVar25, puVar23 = puVar19,
                (long)*(int *)((long)puVar19 + 0x1c) <= (long)uVar34) {
            if ((long)uVar34 <= (long)*(int *)((long)puVar19 + 0x1c)) goto LAB_005c3424;
            puVar25 = (undefined8 *)puVar19[1];
            if ((undefined8 *)puVar19[1] == (undefined8 *)0x0) {
              puVar21 = puVar19 + 1;
              goto LAB_005c3614;
            }
          }
          puVar25 = (undefined8 *)*puVar19;
        }
LAB_005c3614:
        puVar19 = (undefined8 *)func_0x00bc3330(0x28);
        *puVar19 = 0;
        puVar19[1] = 0;
        puVar19[2] = puVar23;
        *puVar21 = puVar19;
        plVar26 = *(long **)(lVar27 + 0x30);
        *(int *)((long)puVar19 + 0x1c) = (int)uVar34;
        *(undefined4 *)(puVar19 + 4) = 0;
        puVar23 = puVar19;
        if (*plVar26 != 0) {
          *(long *)(lVar27 + 0x30) = *plVar26;
          puVar23 = (undefined8 *)*puVar21;
        }
        func_0x0040a8c0(*(undefined8 *)(lVar27 + 0x38),puVar23);
        *(long *)(lVar27 + 0x40) = *(long *)(lVar27 + 0x40) + 1;
LAB_005c3424:
        *(int *)(puVar19 + 4) = iVar12;
      }
    }
  }
LAB_005c3444:
  uVar34 = uVar34 + 1;
  if (uVar34 == 0x33) goto LAB_005c332c;
  goto LAB_005c3450;
LAB_005c386c:
  piVar29 = *(int **)(lVar27 + uVar32 * 8);
  if ((*piVar29 == iVar11) && (piVar29[1] == iVar13)) {
    iVar1 = piVar29[3];
    iVar4 = *(int *)(lVar20 + 0x83698);
    iVar12 = func_0x0043dc7c(lVar20);
    iVar35 = iVar12 + -0x3bf;
    if (0x3bf < iVar12) {
      iVar35 = iVar12 + -0x3c0;
    }
    if ((ulong)(*(long *)(&UNK_00338908 + lVar20) - *plVar2 >> 3) <= uVar32) {  /* field_off=0x338908 */
      lVar20 = func_0x005c8c40(plVar2);
      lVar27 = tpidr_el0;
      lStack_190 = *(long *)(lVar27 + 0x28);
      plVar2 = (long *)(&UNK_00338900 + lVar20);  /* field_off=0x338900 */
      lVar30 = 0;
      if (lRam0000000000c0b8b8 != 0) {
        lVar30 = func_0x00bc3a90(lRam0000000000c0b8b8,
                                 &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                 &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
      }
      plVar26 = *(long **)(&UNK_00338918 + lVar20);  /* field_off=0x338918 */
      plVar24 = *(long **)(&UNK_00338920 + lVar20);  /* field_off=0x338920 */
      if (plVar24 == plVar26) goto LAB_005c3e24;
      uVar32 = 0;
      iVar35 = 0;
      goto LAB_005c3a00;
    }
    lVar30 = *(long *)(*plVar2 + uVar32 * 8);
    iVar12 = *(int *)(lVar30 + 8);
    lVar27 = lVar28 + 0x3660;
    if (*(char *)(lVar30 + 0x28) != '\0') {
      lVar27 = lVar28 + 0x37b0;
    }
    iVar10 = iVar12 - _DAT_00c0ad7c;
    if (iVar12 < _DAT_00c0ad7c) {
      lVar31 = 0;
    }
    else {
      iVar14 = *(int *)(lVar30 + 0x10) * _DAT_00c0ad80;
      iVar12 = 0;
      if (iVar14 <= iVar10) {
        iVar12 = iVar14;
      }
      lVar31 = 1;
      if (iVar14 <= iVar10) {
        lVar31 = 2;
      }
      iVar12 = iVar10 - iVar12;
    }
    iVar10 = *(int *)(lVar20 + (long)iVar11 * 51000 + (long)iVar13 * 1000 + 0x8391c);
    lVar9 = lVar22 + 0x3900;
    if (*(char *)(lVar30 + 0x28) != '\0') {
      lVar9 = lVar22 + 0x39a8;
    }
    func_0x00441474(lVar27,lVar9 + lVar31 * 0x38,iVar12,0);
    func_0x0043cfc4(uVar17,lVar27,(iVar1 - iVar4) / 10 + (iVar35 >> 1),iVar10 * 4 + 0x1cc);
    lVar27 = *plVar2;
    lVar30 = *(long *)(&UNK_00338908 + lVar20);  /* field_off=0x338908 */
  }
  uVar32 = uVar32 + 1;
  if ((ulong)(lVar30 - lVar27 >> 3) <= uVar32) {
    return;
  }
  goto LAB_005c386c;
LAB_005c3a00:
  plVar26 = plVar26 + uVar32;
  if (*(int *)(*plVar26 + 8) == 1) {
    plVar33 = plVar26 + 1;
    if (plVar33 != plVar24) {
      do {
        lVar22 = plVar33[-1];
        plVar33[-1] = *plVar33;
        *plVar33 = 0;
        if (lVar22 != 0) {
          func_0x00bc3350();
        }
        plVar33 = plVar33 + 1;
        plVar26 = plVar26 + 1;
      } while (plVar33 != plVar24);
      plVar24 = *(long **)(&UNK_00338920 + lVar20);  /* field_off=0x338920 */
    }
    while (plVar24 != plVar26) {
      plVar24 = plVar24 + -1;
      lVar22 = *plVar24;
      *plVar24 = 0;
      if (lVar22 != 0) {
        func_0x00bc3350();
      }
    }
LAB_005c39e0:
    *(long **)(&UNK_00338920 + lVar20) = plVar26;  /* field_off=0x338920 */
    iVar35 = iVar35 + -1;
  }
  else {
    iVar1 = *(int *)(*plVar26 + 0xc);
    puStack_1a0 = (undefined8 *)func_0x00bc3330(0x20);
    *(undefined1 *)((long)puStack_1a0 + 0x1c) = 0;
    auStack_1b0[1] = 0x1c;
    auStack_1b0[0] = 0x21;
    puStack_1a0[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
    *puStack_1a0 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
    *(undefined8 *)((long)puStack_1a0 + 0x14) = 0x656d6172665f6573;  /* ascii(0x656d6172665f6573)='se_frame' */
    *(undefined8 *)((long)puStack_1a0 + 0xc) = 0x5f6e6f6d6d75735f;  /* ascii(0x5f6e6f6d6d75735f)='_summon_' */
    iVar11 = func_0x008e3f14(lVar20 + 0x1478,auStack_1b0,0);
    if ((auStack_1b0[0] & 1) != 0) {
      func_0x00bc3350(puStack_1a0);
    }
    if (iVar1 == iVar11) {
      uVar17 = func_0x0044c16c();
      func_0x0044e35c(uVar17,0x9f,0);
    }
    piVar29 = *(int **)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
    iVar1 = piVar29[3];
    iVar11 = *piVar29;
    piVar29[3] = iVar1 + 1;
    puStack_1c0 = (undefined8 *)func_0x00bc3330(0x20);
    *(undefined1 *)((long)puStack_1c0 + 0x19) = 0;
    auStack_1d0[1] = 0x19;
    auStack_1d0[0] = 0x21;
    puStack_1c0[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
    *puStack_1c0 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
    *(undefined8 *)((long)puStack_1c0 + 0x11) = 0x656d6172665f6e6f;  /* ascii(0x656d6172665f6e6f)='on_frame' */
    *(undefined8 *)((long)puStack_1c0 + 9) = 0x6d6d75735f6e6f6d;  /* ascii(0x6d6d75735f6e6f6d)='mon_summ' */
    iVar13 = func_0x008e3f14(lVar20 + 0x1478,auStack_1d0,0x1e);
    if ((auStack_1d0[0] & 1) != 0) {
      func_0x00bc3350(puStack_1c0);
    }
    lVar22 = *(long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
    if (iVar1 + 1 == iVar13) {
      iVar1 = *(int *)(lVar22 + 4);
      func_0x006da618(lVar20,iVar11,iVar1,0);
      uVar8 = *(undefined8 *)(&UNK_00388180 + lVar20);  /* field_off=0x388180 */
      uVar7 = *(undefined8 *)(&UNK_00388174 + lVar20);  /* field_off=0x388174 */
      uVar17 = *(undefined8 *)(&UNK_0038816c + lVar20);  /* field_off=0x38816c */
      iVar13 = *(int *)(&UNK_0038817c + lVar20);  /* field_off=0x38817c */
      iVar4 = *(int *)(&UNK_00388184 + lVar20);  /* field_off=0x388184 */
      iVar12 = *(int *)(&UNK_00388190 + lVar20);  /* field_off=0x388190 */
      uVar5 = *(undefined8 *)(&UNK_00388188 + lVar20);  /* field_off=0x388188 */
      uVar6 = *(undefined8 *)(&UNK_00388194 + lVar20);  /* field_off=0x388194 */
      puVar21 = (undefined8 *)func_0x00bc3330(0x48);
      puVar23 = *(undefined8 **)(&UNK_00338908 + lVar20);  /* field_off=0x338908 */
      puVar25 = *(undefined8 **)(&UNK_00338910 + lVar20);  /* field_off=0x338910 */
      puVar21[8] = 0;
      puVar21[1] = 0;
      *puVar21 = 0;
      puVar21[3] = 0;
      puVar21[2] = 0;
      puVar21[5] = 0;
      puVar21[4] = 0;
      puVar21[7] = 0;
      puVar21[6] = 0;
      puVar21[6] = puVar21 + 7;
      if (puVar23 < puVar25) {
        puStack_1d8 = (undefined8 *)0x0;
        puVar25 = puVar23 + 1;
        *puVar23 = puVar21;
      }
      else {
        puStack_1d8 = puVar21;
        puVar25 = (undefined8 *)func_0x005c8c54(plVar2,&puStack_1d8);
      }
      puVar23 = puStack_1d8;
      *(undefined8 **)(&UNK_00338908 + lVar20) = puVar25;  /* field_off=0x338908 */
      puStack_1d8 = (undefined8 *)0x0;
      if (puVar23 != (undefined8 *)0x0) {
        func_0x0058c04c(puVar23 + 6,puVar23[7]);
        func_0x00bc3350(puVar23);
        puVar25 = *(undefined8 **)(&UNK_00338908 + lVar20);  /* field_off=0x338908 */
      }
      if (puVar25 != (undefined8 *)*plVar2) {
        piVar29 = (int *)puVar25[-1];
        *piVar29 = iVar11;
        piVar29[1] = iVar1;
        piVar29[2] = 0;
        iVar14 = func_0x00a5919c(iVar11,iVar1);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
        lVar22 = *(long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
        iVar10 = *(int *)(lVar22 + 0x18);
        func_0x0043ecf8(*(undefined4 *)(lVar22 + 0x1c));
        iVar15 = func_0x0043ea60();
        if (*(long *)(&UNK_00338908 + lVar20) != *plVar2) {  /* field_off=0x338908 */
          lVar22 = *(long *)(*(long *)(&UNK_00338908 + lVar20) + -8);  /* field_off=0x338908 */
          lVar28 = *(long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
          *(undefined4 *)(lVar22 + 0x14) = 0;
          uVar16 = *(undefined4 *)(lVar28 + 0x14);
          iVar3 = -iVar15;
          if (0 < *(int *)(lVar28 + 0x1c)) {
            iVar3 = iVar15;
          }
          iVar3 = iVar3 + iVar10;
          iVar10 = -iVar3;
          if (iVar11 == 1) {
            iVar10 = iVar3;
          }
          *(int *)(lVar22 + 0xc) = iVar10 + iVar14;
          *(undefined4 *)(lVar22 + 0x10) = uVar16;
          uVar34 = (ulong)CONCAT16(-((int)((ulong)uVar6 >> 0x20) != 0),
                                   (uint6)CONCAT14(-((int)uVar6 != 0),
                                                   (uint)(CONCAT12(-(iVar12 != 0),
                                                                   -(ushort)((int)uVar8 != 0)) &
                                                         0xff00ff))) & 0x1000100010001;
          *(uint *)(lVar22 + 0x20) =
               CONCAT13((char)(uVar34 >> 0x30),
                        CONCAT12((char)(uVar34 >> 0x20),
                                 CONCAT11((char)(uVar34 >> 0x10),(char)uVar34)));
          *(ulong *)(lVar22 + 0x18) =
               CONCAT17(~-((int)uVar5 == 0),
                        CONCAT16(~-((int)((ulong)uVar5 >> 0x20) == 0),
                                 CONCAT15(~-(iVar4 == 0),
                                          CONCAT14(~-(iVar13 == 0),
                                                   CONCAT13(~-((int)((ulong)uVar7 >> 0x20) == 0),
                                                            CONCAT12(~-((int)uVar7 == 0),
                                                                     CONCAT11(~-((int)((ulong)uVar17
                                                                                      >> 0x20) == 0)
                                                                              ,~-((int)uVar17 == 0))
                                                                    )))))) & 0x101010101010101;
          uVar16 = func_0x00a5f6cc(iVar11,iVar1);  /* 0x95f6cc:[slot*1000,team*0x1f0,team*51000|off=0x83c70|ldr w0, [x8, x9]] */
          if (*(long *)(&UNK_00338908 + lVar20) != *plVar2) {  /* field_off=0x338908 */
            lVar22 = *(long *)(*(long *)(&UNK_00338908 + lVar20) + -8);  /* field_off=0x338908 */
            lVar28 = *(long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
            *(undefined4 *)(lVar22 + 0x24) = uVar16;
            *(undefined1 *)(lVar22 + 0x28) = *(undefined1 *)(lVar28 + 0x20);
            *(undefined4 *)(lVar22 + 0x2c) = 1;
            goto LAB_005c39e8;
          }
        }
      }
      if (*(long *)(lVar27 + 0x28) == lStack_190) {
        uVar17 = func_0x005c8c40(plVar2);
        func_0x005c3ee4(&puStack_1d8);
        if (*(long *)(lVar27 + 0x28) == lStack_190) {
                    /* WARNING: Subroutine does not return */
          NoRet_0x00abf40c(uVar17);
        }
      }
      goto LAB_005c3ee0;
    }
    iVar1 = *(int *)(lVar22 + 0xc);
    puStack_1e0 = (undefined8 *)func_0x00bc3330(0x20);
    *(undefined1 *)((long)puStack_1e0 + 0x19) = 0;
    puStack_1e0[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
    *puStack_1e0 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
    auStack_1f0[1] = 0x19;
    auStack_1f0[0] = 0x21;
    *(undefined8 *)((long)puStack_1e0 + 0x11) = 0x656d6172665f6e6f;  /* ascii(0x656d6172665f6e6f)='on_frame' */
    *(undefined8 *)((long)puStack_1e0 + 9) = 0x6d6d75735f6e6f6d;  /* ascii(0x6d6d75735f6e6f6d)='mon_summ' */
    iVar13 = func_0x008e3f14(lVar20 + 0x1478,auStack_1f0,0x1e);
    if (iVar1 < iVar13) {
      if ((auStack_1f0[0] & 1) != 0) {
        func_0x00bc3350(puStack_1e0);
      }
    }
    else {
      iVar1 = *(int *)(*(long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8) + 0xc);  /* field_off=0x338918 */
      iVar11 = func_0x0044003c(lVar30 + 0x29d8 + (long)iVar11 * 0x38);
      if ((auStack_1f0[0] & 1) != 0) {
        func_0x00bc3350(puStack_1e0);
      }
      if (iVar11 <= iVar1) {
        plVar33 = *(long **)(&UNK_00338920 + lVar20);  /* field_off=0x338920 */
        plVar26 = (long *)(*(long *)(&UNK_00338918 + lVar20) + uVar32 * 8);  /* field_off=0x338918 */
        plVar24 = plVar26 + 1;
        if (plVar24 != plVar33) {
          do {
            lVar22 = plVar24[-1];
            plVar24[-1] = *plVar24;
            *plVar24 = 0;
            if (lVar22 != 0) {
              func_0x00bc3350();
            }
            plVar24 = plVar24 + 1;
            plVar26 = plVar26 + 1;
          } while (plVar24 != plVar33);
          plVar24 = *(long **)(&UNK_00338920 + lVar20);  /* field_off=0x338920 */
        }
        while (plVar24 != plVar26) {
          plVar24 = plVar24 + -1;
          lVar22 = *plVar24;
          *plVar24 = 0;
          if (lVar22 != 0) {
            func_0x00bc3350();
          }
        }
        goto LAB_005c39e0;
      }
    }
  }
LAB_005c39e8:
  plVar26 = *(long **)(&UNK_00338918 + lVar20);  /* field_off=0x338918 */
  plVar24 = *(long **)(&UNK_00338920 + lVar20);  /* field_off=0x338920 */
  iVar35 = iVar35 + 1;
  uVar32 = (ulong)iVar35;
  if ((ulong)((long)plVar24 - (long)plVar26 >> 3) <= uVar32) {
LAB_005c3e24:
    if (*(long *)(lVar27 + 0x28) == lStack_190) {
      return;
    }
LAB_005c3ee0:
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  goto LAB_005c3a00;
}


