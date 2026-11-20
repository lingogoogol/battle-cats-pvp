// ELF VMA: 0x004c3918 | Ghidra Addr: 0x005c3918 | BodySize: 1424

void BattleFn_0x004c3918(long param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulong uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  long lVar19;
  undefined8 uVar20;
  undefined8 *puVar21;
  long lVar22;
  undefined8 *puVar23;
  long *plVar24;
  int *piVar25;
  long lVar26;
  long *plVar27;
  long *plVar28;
  int iVar29;
  ulong uVar30;
  ulong auStack_e0 [2];
  undefined8 *puStack_d0;
  undefined8 *puStack_c8;
  ulong auStack_c0 [2];
  undefined8 *puStack_b0;
  ulong auStack_a0 [2];
  undefined8 *puStack_90;
  long lStack_80;
  
  lVar8 = tpidr_el0;
  lStack_80 = *(long *)(lVar8 + 0x28);
  plVar1 = (long *)(&UNK_00338900 + param_1);  /* field_off=0x338900 */
  lVar19 = 0;
  if (lRam0000000000c0b8b8 != 0) {
    lVar19 = func_0x00bc3a90(lRam0000000000c0b8b8,
                             &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                             &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
  }
  plVar24 = *(long **)(&UNK_00338918 + param_1);  /* field_off=0x338918 */
  plVar27 = *(long **)(&UNK_00338920 + param_1);  /* field_off=0x338920 */
  if (plVar27 != plVar24) {
    uVar30 = 0;
    iVar29 = 0;
    do {
      plVar24 = plVar24 + uVar30;
      if (*(int *)(*plVar24 + 8) == 1) {
        plVar28 = plVar24 + 1;
        if (plVar28 != plVar27) {
          do {
            lVar22 = plVar28[-1];
            plVar28[-1] = *plVar28;
            *plVar28 = 0;
            if (lVar22 != 0) {
              func_0x00bc3350();
            }
            plVar28 = plVar28 + 1;
            plVar24 = plVar24 + 1;
          } while (plVar28 != plVar27);
          plVar27 = *(long **)(&UNK_00338920 + param_1);  /* field_off=0x338920 */
        }
        while (plVar27 != plVar24) {
          plVar27 = plVar27 + -1;
          lVar22 = *plVar27;
          *plVar27 = 0;
          if (lVar22 != 0) {
            func_0x00bc3350();
          }
        }
LAB_005c39e0:
        *(long **)(&UNK_00338920 + param_1) = plVar24;  /* field_off=0x338920 */
        iVar29 = iVar29 + -1;
      }
      else {
        iVar5 = *(int *)(*plVar24 + 0xc);
        puStack_90 = (undefined8 *)func_0x00bc3330(0x20);
        *(undefined1 *)((long)puStack_90 + 0x1c) = 0;
        auStack_a0[1] = 0x1c;
        auStack_a0[0] = 0x21;
        puStack_90[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
        *puStack_90 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
        *(undefined8 *)((long)puStack_90 + 0x14) = 0x656d6172665f6573;  /* ascii(0x656d6172665f6573)='se_frame' */
        *(undefined8 *)((long)puStack_90 + 0xc) = 0x5f6e6f6d6d75735f;  /* ascii(0x5f6e6f6d6d75735f)='_summon_' */
        iVar14 = func_0x008e3f14(param_1 + 0x1478,auStack_a0,0);
        if ((auStack_a0[0] & 1) != 0) {
          func_0x00bc3350(puStack_90);
        }
        if (iVar5 == iVar14) {
          uVar20 = func_0x0044c16c();
          func_0x0044e35c(uVar20,0x9f,0);
        }
        piVar25 = *(int **)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
        iVar5 = piVar25[3];
        iVar14 = *piVar25;
        piVar25[3] = iVar5 + 1;
        puStack_b0 = (undefined8 *)func_0x00bc3330(0x20);
        *(undefined1 *)((long)puStack_b0 + 0x19) = 0;
        auStack_c0[1] = 0x19;
        auStack_c0[0] = 0x21;
        puStack_b0[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
        *puStack_b0 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
        *(undefined8 *)((long)puStack_b0 + 0x11) = 0x656d6172665f6e6f;  /* ascii(0x656d6172665f6e6f)='on_frame' */
        *(undefined8 *)((long)puStack_b0 + 9) = 0x6d6d75735f6e6f6d;  /* ascii(0x6d6d75735f6e6f6d)='mon_summ' */
        iVar15 = func_0x008e3f14(param_1 + 0x1478,auStack_c0,0x1e);
        if ((auStack_c0[0] & 1) != 0) {
          func_0x00bc3350(puStack_b0);
        }
        lVar22 = *(long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
        if (iVar5 + 1 == iVar15) {
          iVar5 = *(int *)(lVar22 + 4);
          func_0x006da618(param_1,iVar14,iVar5,0);
          uVar12 = *(undefined8 *)(&UNK_00388180 + param_1);  /* field_off=0x388180 */
          uVar11 = *(undefined8 *)(&UNK_00388174 + param_1);  /* field_off=0x388174 */
          uVar20 = *(undefined8 *)(&UNK_0038816c + param_1);  /* field_off=0x38816c */
          iVar15 = *(int *)(&UNK_0038817c + param_1);  /* field_off=0x38817c */
          iVar6 = *(int *)(&UNK_00388184 + param_1);  /* field_off=0x388184 */
          iVar7 = *(int *)(&UNK_00388190 + param_1);  /* field_off=0x388190 */
          uVar9 = *(undefined8 *)(&UNK_00388188 + param_1);  /* field_off=0x388188 */
          uVar10 = *(undefined8 *)(&UNK_00388194 + param_1);  /* field_off=0x388194 */
          puVar21 = (undefined8 *)func_0x00bc3330(0x48);
          puVar4 = *(undefined8 **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
          puVar23 = *(undefined8 **)(&UNK_00338910 + param_1);  /* field_off=0x338910 */
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
          if (puVar4 < puVar23) {
            puStack_c8 = (undefined8 *)0x0;
            puVar23 = puVar4 + 1;
            *puVar4 = puVar21;
          }
          else {
            puStack_c8 = puVar21;
            puVar23 = (undefined8 *)func_0x005c8c54(plVar1,&puStack_c8);
          }
          puVar4 = puStack_c8;
          *(undefined8 **)(&UNK_00338908 + param_1) = puVar23;  /* field_off=0x338908 */
          puStack_c8 = (undefined8 *)0x0;
          if (puVar4 != (undefined8 *)0x0) {
            func_0x0058c04c(puVar4 + 6,puVar4[7]);
            func_0x00bc3350(puVar4);
            puVar23 = *(undefined8 **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
          }
          if (puVar23 != (undefined8 *)*plVar1) {
            piVar25 = (int *)puVar23[-1];
            *piVar25 = iVar14;
            piVar25[1] = iVar5;
            piVar25[2] = 0;
            iVar16 = func_0x00a5919c(iVar14,iVar5);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
            lVar22 = *(long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
            iVar3 = *(int *)(lVar22 + 0x18);
            func_0x0043ecf8(*(undefined4 *)(lVar22 + 0x1c));
            iVar17 = func_0x0043ea60();
            if (*(long *)(&UNK_00338908 + param_1) != *plVar1) {  /* field_off=0x338908 */
              lVar22 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);  /* field_off=0x338908 */
              lVar26 = *(long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
              *(undefined4 *)(lVar22 + 0x14) = 0;
              uVar18 = *(undefined4 *)(lVar26 + 0x14);
              iVar2 = -iVar17;
              if (0 < *(int *)(lVar26 + 0x1c)) {
                iVar2 = iVar17;
              }
              iVar2 = iVar2 + iVar3;
              iVar3 = -iVar2;
              if (iVar14 == 1) {
                iVar3 = iVar2;
              }
              *(int *)(lVar22 + 0xc) = iVar3 + iVar16;
              *(undefined4 *)(lVar22 + 0x10) = uVar18;
              uVar13 = (ulong)CONCAT16(-((int)((ulong)uVar10 >> 0x20) != 0),
                                       (uint6)CONCAT14(-((int)uVar10 != 0),
                                                       (uint)(CONCAT12(-(iVar7 != 0),
                                                                       -(ushort)((int)uVar12 != 0))
                                                             & 0xff00ff))) & 0x1000100010001;
              *(uint *)(lVar22 + 0x20) =
                   CONCAT13((char)(uVar13 >> 0x30),
                            CONCAT12((char)(uVar13 >> 0x20),
                                     CONCAT11((char)(uVar13 >> 0x10),(char)uVar13)));
              *(ulong *)(lVar22 + 0x18) =
                   CONCAT17(~-((int)uVar9 == 0),
                            CONCAT16(~-((int)((ulong)uVar9 >> 0x20) == 0),
                                     CONCAT15(~-(iVar6 == 0),
                                              CONCAT14(~-(iVar15 == 0),
                                                       CONCAT13(~-((int)((ulong)uVar11 >> 0x20) == 0
                                                                  ),CONCAT12(~-((int)uVar11 == 0),
                                                                             CONCAT11(~-((int)((
                                                  ulong)uVar20 >> 0x20) == 0),~-((int)uVar20 == 0)))
                                                  ))))) & 0x101010101010101;
              uVar18 = func_0x00a5f6cc(iVar14,iVar5);  /* 0x95f6cc:[slot*1000,team*0x1f0,team*51000|off=0x83c70|ldr w0, [x8, x9]] */
              if (*(long *)(&UNK_00338908 + param_1) != *plVar1) {  /* field_off=0x338908 */
                lVar22 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);  /* field_off=0x338908 */
                lVar26 = *(long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
                *(undefined4 *)(lVar22 + 0x24) = uVar18;
                *(undefined1 *)(lVar22 + 0x28) = *(undefined1 *)(lVar26 + 0x20);
                *(undefined4 *)(lVar22 + 0x2c) = 1;
                goto LAB_005c39e8;
              }
            }
          }
          if (*(long *)(lVar8 + 0x28) == lStack_80) {
            uVar20 = func_0x005c8c40(plVar1);
            func_0x005c3ee4(&puStack_c8);
            if (*(long *)(lVar8 + 0x28) == lStack_80) {
                    /* WARNING: Subroutine does not return */
              NoRet_0x00abf40c(uVar20);
            }
          }
          goto LAB_005c3ee0;
        }
        iVar5 = *(int *)(lVar22 + 0xc);
        puStack_d0 = (undefined8 *)func_0x00bc3330(0x20);
        *(undefined1 *)((long)puStack_d0 + 0x19) = 0;
        puStack_d0[1] = 0x6d75735f6e6f6d65;  /* ascii(0x6d75735f6e6f6d65)='emon_sum' */
        *puStack_d0 = 0x645f656c74746162;  /* ascii(0x645f656c74746162)='battle_d' */
        auStack_e0[1] = 0x19;
        auStack_e0[0] = 0x21;
        *(undefined8 *)((long)puStack_d0 + 0x11) = 0x656d6172665f6e6f;  /* ascii(0x656d6172665f6e6f)='on_frame' */
        *(undefined8 *)((long)puStack_d0 + 9) = 0x6d6d75735f6e6f6d;  /* ascii(0x6d6d75735f6e6f6d)='mon_summ' */
        iVar15 = func_0x008e3f14(param_1 + 0x1478,auStack_e0,0x1e);
        if (iVar5 < iVar15) {
          if ((auStack_e0[0] & 1) != 0) {
            func_0x00bc3350(puStack_d0);
          }
        }
        else {
          iVar5 = *(int *)(*(long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8) + 0xc);  /* field_off=0x338918 */
          iVar14 = func_0x0044003c(lVar19 + 0x29d8 + (long)iVar14 * 0x38);
          if ((auStack_e0[0] & 1) != 0) {
            func_0x00bc3350(puStack_d0);
          }
          if (iVar14 <= iVar5) {
            plVar28 = *(long **)(&UNK_00338920 + param_1);  /* field_off=0x338920 */
            plVar24 = (long *)(*(long *)(&UNK_00338918 + param_1) + uVar30 * 8);  /* field_off=0x338918 */
            plVar27 = plVar24 + 1;
            if (plVar27 != plVar28) {
              do {
                lVar22 = plVar27[-1];
                plVar27[-1] = *plVar27;
                *plVar27 = 0;
                if (lVar22 != 0) {
                  func_0x00bc3350();
                }
                plVar27 = plVar27 + 1;
                plVar24 = plVar24 + 1;
              } while (plVar27 != plVar28);
              plVar27 = *(long **)(&UNK_00338920 + param_1);  /* field_off=0x338920 */
            }
            while (plVar27 != plVar24) {
              plVar27 = plVar27 + -1;
              lVar22 = *plVar27;
              *plVar27 = 0;
              if (lVar22 != 0) {
                func_0x00bc3350();
              }
            }
            goto LAB_005c39e0;
          }
        }
      }
LAB_005c39e8:
      plVar24 = *(long **)(&UNK_00338918 + param_1);  /* field_off=0x338918 */
      plVar27 = *(long **)(&UNK_00338920 + param_1);  /* field_off=0x338920 */
      iVar29 = iVar29 + 1;
      uVar30 = (ulong)iVar29;
    } while (uVar30 < (ulong)((long)plVar27 - (long)plVar24 >> 3));
  }
  if (*(long *)(lVar8 + 0x28) == lStack_80) {
    return;
  }
LAB_005c3ee0:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


