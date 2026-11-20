// ELF VMA: 0x004c2188 | Ghidra Addr: 0x005c2188 | BodySize: 3800

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004c2188(long param_1)

{
  uint uVar1;
  long lVar2;
  ulong *puVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 *******pppppppuVar12;
  undefined8 *******pppppppuVar13;
  undefined8 *******pppppppuVar14;
  undefined8 uVar15;
  undefined8 *******pppppppuVar16;
  undefined8 *******pppppppuVar17;
  undefined8 *puVar18;
  int *piVar19;
  ulong *puVar20;
  long lVar21;
  ulong *puVar22;
  ulong uVar23;
  undefined8 *puVar24;
  ulong uVar25;
  ulong *puVar26;
  ulong uVar27;
  long lVar28;
  ulong *puVar29;
  undefined4 uVar30;
  ulong uVar31;
  int *piVar32;
  ulong *puVar33;
  ulong *puVar34;
  long lVar35;
  undefined4 *puVar36;
  char *pcVar37;
  ulong *puVar38;
  long lVar39;
  long lVar40;
  ulong uVar41;
  ulong uVar42;
  ulong uVar43;
  char *pcStack_120;
  byte abStack_e8 [16];
  undefined5 uStack_d8;
  undefined1 uStack_d3;
  undefined2 uStack_d2;
  byte abStack_d0 [16];
  undefined5 uStack_c0;
  undefined1 uStack_bb;
  undefined2 uStack_ba;
  byte abStack_b8 [16];
  undefined5 uStack_a8;
  undefined1 uStack_a3;
  undefined2 uStack_a2;
  undefined8 *******pppppppuStack_a0;
  undefined8 *******pppppppuStack_98;
  long lStack_90;
  ulong *puStack_88;
  ulong *puStack_80;
  ulong *puStack_78;
  long lStack_70;
  
  lVar2 = tpidr_el0;
  lVar39 = 0;
  lStack_70 = *(long *)(lVar2 + 0x28);
  puStack_88 = (ulong *)0x0;
  puStack_80 = (ulong *)0x0;
  puStack_78 = (ulong *)0x0;
  puVar24 = (undefined8 *)((ulong)abStack_b8 | 1);
  puVar18 = (undefined8 *)((ulong)abStack_d0 | 1);
  pcStack_120 = &UNK_00388268 + param_1;  /* field_off=0x388268 */
  pppppppuStack_98 = (undefined8 *******)0x0;
  lStack_90 = 0;
  pppppppuStack_a0 = &pppppppuStack_98;
  do {
    lVar21 = 0;
    lVar40 = param_1 + lVar39 * 0x30;
    do {
      lVar28 = lRam0000000000c0b8b8;
      lVar35 = param_1 + lVar39 * 0x30 + lVar21 * 8;
      if (0 < *(int *)(&UNK_0033637c + lVar35)) {  /* field_off=0x33637c */
        *(int *)(&UNK_0033637c + lVar35) = *(int *)(&UNK_0033637c + lVar35) + -1;  /* field_off=0x33637c ; field_off=0x33637c */
        lVar9 = 0;
        if (lVar28 != 0) {
          lVar9 = func_0x00bc3a90(lVar28,&PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                  &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
        }
        lVar28 = lVar9 + 0x30d8;
        if ((&UNK_00333e28)[lVar40] != '\0') {  /* field_off=0x333e28 */
          lVar28 = lVar9 + 0x3148;
        }
        iVar5 = func_0x0044003c(lVar28);
        uVar1 = *(uint *)(&UNK_0033637c + lVar35);  /* field_off=0x33637c */
        if ((&UNK_00333e28)[lVar40] == '\0') {  /* field_off=0x333e28 */
          iVar6 = 3;
LAB_005c23c0:
          iVar7 = 7;
        }
        else {
          uStack_a3 = 0;
          abStack_b8[0] = 0x28;
          *(undefined4 *)(puVar24 + 2) = 0x31656d61;  /* ascii(0x31656d61)='ame1' */
          puVar24[1] = 0x72665f735f657661;  /* ascii(0x72665f735f657661)='ave_s_fr' */
          *puVar24 = 0x775f656c74746162;  /* ascii(0x775f656c74746162)='battle_w' */
          iVar6 = func_0x008e3f14(param_1 + 0x1478,abStack_b8,3);
          if ((abStack_b8[0] & 1) != 0) {
            func_0x00bc3350(CONCAT26(uStack_a2,CONCAT15(uStack_a3,uStack_a8)));
          }
          if ((&UNK_00333e28)[lVar40] == '\0') goto LAB_005c23c0;  /* field_off=0x333e28 */
          uStack_bb = 0;
          abStack_d0[0] = 0x28;
          *(undefined4 *)(puVar18 + 2) = 0x32656d61;  /* ascii(0x32656d61)='ame2' */
          puVar18[1] = 0x72665f735f657661;  /* ascii(0x72665f735f657661)='ave_s_fr' */
          *puVar18 = 0x775f656c74746162;  /* ascii(0x775f656c74746162)='battle_w' */
          iVar7 = func_0x008e3f14(param_1 + 0x1478,abStack_d0,7);
          if ((abStack_d0[0] & 1) != 0) {
            func_0x00bc3350(CONCAT26(uStack_ba,CONCAT15(uStack_bb,uStack_c0)));
          }
        }
        if (iVar6 < (int)(iVar5 + ~uVar1) && (int)(iVar5 + ~uVar1 + -1) <= iVar7) {
          lVar35 = -0x32;
          lVar28 = 1;
          lVar9 = param_1 + lVar39 * 0x30 + lVar21 * 8;
          piVar32 = (int *)(param_1 + 0x83cf0);
          puVar36 = (undefined4 *)(param_1 + 0x905a0);
          pcVar37 = pcStack_120;
          do {
            if (((puVar36[-0x5e] != 0) || (*(int *)(&UNK_00333e04 + lVar40) != 1)) &&  /* field_off=0x333e04 */
               ((*piVar32 != 0 || (*(int *)(&UNK_00333e04 + lVar40) != 2)))) {  /* field_off=0x333e04 */
              uVar31 = lVar35 + 0x33;
              uVar10 = func_0x00a58df4(1,uVar31 & 0xffffffff,*(undefined4 *)(&UNK_00333e00 + lVar40)  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] ; field_off=0x333e00 */
                                      );
              iVar5 = _DAT_00c0b310;
              if ((((uVar10 & 1) == 0) || (*(int *)(&UNK_00333e04 + lVar40) != 1)) ||  /* field_off=0x333e04 */
                 (*pcVar37 != '\0')) {
                uVar10 = func_0x00a58df4(0,uVar31 & 0xffffffff,  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                                         *(undefined4 *)(&UNK_00333e00 + lVar40));  /* field_off=0x333e00 */
                iVar5 = _DAT_00c0b310;
                if ((((uVar10 & 1) == 0) || (*(int *)(&UNK_00333e04 + lVar40) != 2)) ||  /* field_off=0x333e04 */
                   (*pcVar37 != '\0')) goto LAB_005c241c;
                iVar6 = *(int *)(&UNK_00336380 + lVar9);  /* field_off=0x336380 */
                iVar7 = func_0x00a5919c(0,uVar31 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                iVar7 = piVar32[0xe] + iVar7 + _DAT_00c0b310 * -5;
              }
              else {
                iVar6 = *(int *)(&UNK_00336380 + lVar9);  /* field_off=0x336380 */
                iVar7 = func_0x00a5919c(1,uVar31 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                iVar7 = iVar7 - puVar36[-0x50];
              }
              if (((iVar6 + iVar5 * -5 <= iVar7) && (iVar7 < iVar5 * 5 + iVar6)) &&
                 (*pcVar37 == '\0')) {
                if (*(int *)(&UNK_00333e04 + lVar40) == 2) {  /* field_off=0x333e04 */
                  if (piVar32[0x57] == 1) {
                    *(undefined4 *)(&UNK_00333dfc + lVar40) = 0;  /* field_off=0x333dfc */
                    *(undefined4 *)(&UNK_00333e08 + lVar40) = 0;  /* field_off=0x333e08 */
                    *(undefined4 *)(&UNK_00333e10 + lVar40) = 0;  /* field_off=0x333e10 */
                    *(undefined4 *)(&UNK_0033637c + lVar40) = 0;  /* field_off=0x33637c */
                    *(undefined4 *)(&UNK_00336384 + lVar40) = 0;  /* field_off=0x336384 */
                    *(undefined4 *)(&UNK_0033638c + lVar40) = 0;  /* field_off=0x33638c */
                    *(undefined4 *)(&UNK_00336394 + lVar40) = 0;  /* field_off=0x336394 */
                    *(undefined4 *)(&UNK_0033639c + lVar40) = 0;  /* field_off=0x33639c */
                    *(undefined4 *)(&UNK_003363a4 + lVar40) = 0;  /* field_off=0x3363a4 */
                    piVar19 = piVar32 + 0x5f;
                    piVar32[0x5e] = 0;
                    goto LAB_005c2414;
                  }
                }
                else if ((*(int *)(&UNK_00333e04 + lVar40) == 1) && (puVar36[-7] == 1)) {  /* field_off=0x333e04 */
                  *(undefined4 *)(&UNK_00333dfc + lVar40) = 0;  /* field_off=0x333dfc */
                  *(undefined4 *)(&UNK_00333e08 + lVar40) = 0;  /* field_off=0x333e08 */
                  *(undefined4 *)(&UNK_00333e10 + lVar40) = 0;  /* field_off=0x333e10 */
                  *(undefined4 *)(&UNK_0033637c + lVar40) = 0;  /* field_off=0x33637c */
                  *(undefined4 *)(&UNK_00336384 + lVar40) = 0;  /* field_off=0x336384 */
                  *(undefined4 *)(&UNK_0033638c + lVar40) = 0;  /* field_off=0x33638c */
                  *(undefined4 *)(&UNK_00336394 + lVar40) = 0;  /* field_off=0x336394 */
                  *(undefined4 *)(&UNK_0033639c + lVar40) = 0;  /* field_off=0x33639c */
                  *(undefined4 *)(&UNK_003363a4 + lVar40) = 0;  /* field_off=0x3363a4 */
                  *puVar36 = 0;
                  piVar19 = (int *)(param_1 + lVar28 * 1000 + 0x901bc);
LAB_005c2414:
                  *piVar19 = 1;
                }
              }
            }
LAB_005c241c:
            puVar36 = puVar36 + 0xfa;
            bVar4 = lVar35 != -1;
            lVar35 = lVar35 + 1;
            lVar28 = lVar28 + 1;
            piVar32 = piVar32 + 0xfa;
            pcVar37 = pcVar37 + 200;
          } while (bVar4);
        }
      }
      lVar21 = lVar21 + 1;
    } while (lVar21 != 6);
    lVar39 = lVar39 + 1;
    pcStack_120 = pcStack_120 + 1;
  } while (lVar39 != 200);
  uVar31 = 0;
  puVar18 = (undefined8 *)((ulong)abStack_e8 | 1);
  do {
    lVar39 = 0;
    lVar21 = param_1 + uVar31 * 0x30;
    do {
      lVar40 = param_1 + uVar31 * 0x30 + lVar39 * 8;
      if (0 < *(int *)(&UNK_0033637c + lVar40)) {  /* field_off=0x33637c */
        lVar35 = 0;
        if (lRam0000000000c0b8b8 != 0) {
          lVar35 = func_0x00bc3a90(lRam0000000000c0b8b8,
                                   &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                   &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
        }
        lVar28 = lVar35 + 0x30d8;
        if ((&UNK_00333e28)[lVar21] != '\0') {  /* field_off=0x333e28 */
          lVar28 = lVar35 + 0x3148;
        }
        iVar5 = func_0x0044003c(lVar28);
        uVar1 = *(uint *)(&UNK_0033637c + lVar40);  /* field_off=0x33637c */
        if ((&UNK_00333e28)[lVar21] == '\0') {  /* field_off=0x333e28 */
          iVar6 = 7;
        }
        else {
          uStack_d3 = 0;
          abStack_e8[0] = 0x28;
          *(undefined4 *)(puVar18 + 2) = 0x32656d61;  /* ascii(0x32656d61)='ame2' */
          puVar18[1] = 0x72665f735f657661;  /* ascii(0x72665f735f657661)='ave_s_fr' */
          *puVar18 = 0x775f656c74746162;  /* ascii(0x775f656c74746162)='battle_w' */
          iVar6 = func_0x008e3f14(param_1 + 0x1478,abStack_e8,7);
          if ((abStack_e8[0] & 1) != 0) {
            func_0x00bc3350(CONCAT26(uStack_d2,CONCAT15(uStack_d3,uStack_d8)));
          }
        }
        if (iVar5 + ~uVar1 + -1 == iVar6) {
          uVar10 = 1;
          lVar40 = param_1 + uVar31 * 0x30 + lVar39 * 8;
LAB_005c282c:
          if ((((*(int *)(param_1 + uVar10 * 1000 + 0x90040) != 0) &&
               (uVar11 = func_0x005aad10(), uVar10 != (uVar11 & 0xffffffff))) ||
              (puVar29 = puStack_80, *(int *)(&UNK_00333e04 + lVar21) != 1)) &&  /* field_off=0x333e04 */
             ((*(int *)(param_1 + 0x83908 + uVar10 * 1000) != 0 ||
              (puVar29 = puStack_80, *(int *)(&UNK_00333e04 + lVar21) != 2)))) {  /* field_off=0x333e04 */
            uVar11 = func_0x00a58df4(1,uVar10 & 0xffffffff,*(undefined4 *)(&UNK_00333e00 + lVar21));  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] ; field_off=0x333e00 */
            iVar5 = _DAT_00c0b310;
            if (((uVar11 & 1) == 0) ||
               ((*(int *)(&UNK_00333e04 + lVar21) != 1 ||  /* field_off=0x333e04 */
                ((&UNK_003881a0)[param_1 + uVar10 * 200 + uVar31] != '\0')))) {  /* field_off=0x3881a0 */
              uVar11 = func_0x00a58df4(0,uVar10 & 0xffffffff,*(undefined4 *)(&UNK_00333e00 + lVar21)  /* 0x958df4:[slot*1000,team*51000|off=0x8390c,0x8390c,0x8390c,0x8390c,0x8390c,0x8390c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] ; field_off=0x333e00 */
                                      );
              iVar5 = _DAT_00c0b310;
              puVar29 = puStack_80;
              if (((uVar11 & 1) == 0) ||
                 ((*(int *)(&UNK_00333e04 + lVar21) != 2 ||  /* field_off=0x333e04 */
                  ((&UNK_003881a0)[param_1 + uVar10 * 200 + uVar31] != '\0')))) goto LAB_005c2820;  /* field_off=0x3881a0 */
              iVar6 = *(int *)(&UNK_00336380 + lVar40);  /* field_off=0x336380 */
              iVar7 = func_0x00a5919c(0,uVar10 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
              iVar7 = *(int *)(param_1 + 0x83908 + uVar10 * 1000 + 0x38) + iVar7 +
                      _DAT_00c0b310 * -5;
            }
            else {
              iVar6 = *(int *)(&UNK_00336380 + lVar40);  /* field_off=0x336380 */
              iVar7 = func_0x00a5919c(1,uVar10 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
              iVar7 = iVar7 - *(int *)(param_1 + uVar10 * 1000 + 0x90078);
            }
            puVar29 = puStack_80;
            if (((iVar7 < iVar6 + iVar5 * -5) || (iVar5 * 5 + iVar6 <= iVar7)) ||
               ((&UNK_003881a0)[param_1 + uVar10 * 200 + uVar31] != '\0')) goto LAB_005c2820;  /* field_off=0x3881a0 */
            uVar8 = 1;
            if (*(int *)(&UNK_00333e04 + lVar21) == 1) {  /* field_off=0x333e04 */
LAB_005c29d4:
              uVar11 = func_0x00a5f994(uVar8,uVar10 & 0xffffffff);  /* 0x95f994:[slot*1000,team*51000|off=0x83a64|ldr w8, [x8, x9]] */
              if ((uVar11 & 1) == 0) goto LAB_005c2b4c;
              uVar30 = (undefined4)uVar31;
              pppppppuVar16 = pppppppuStack_98;
              pppppppuVar14 = &pppppppuStack_98;
              if (pppppppuStack_98 != (undefined8 *******)0x0) {
LAB_005c2a10:
                if ((long)uVar31 < (long)*(int *)((long)pppppppuVar16 + 0x1c)) goto LAB_005c2a08;
                if ((long)*(int *)((long)pppppppuVar16 + 0x1c) < (long)uVar31) {
                  pppppppuVar16 = pppppppuVar16 + 1;
                  goto LAB_005c2a08;
                }
                iVar5 = func_0x00a5919c(uVar8,uVar10 & 0xffffffff);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                pppppppuVar16 = pppppppuStack_98;
                pppppppuVar17 = &pppppppuStack_98;
                while (pppppppuVar13 = pppppppuVar17, pppppppuVar16 != (undefined8 *******)0x0) {
                  while (pppppppuVar17 = pppppppuVar16,
                        (long)*(int *)((long)pppppppuVar17 + 0x1c) <= (long)uVar31) {
                    if ((long)uVar31 <= (long)*(int *)((long)pppppppuVar17 + 0x1c))
                    goto LAB_005c2c84;
                    pppppppuVar16 = (undefined8 *******)pppppppuVar17[1];
                    if ((undefined8 *******)pppppppuVar17[1] == (undefined8 *******)0x0) {
                      pppppppuVar13 = pppppppuVar17 + 1;
                      goto LAB_005c2aac;
                    }
                  }
                  pppppppuVar16 = (undefined8 *******)*pppppppuVar17;
                }
LAB_005c2aac:
                pppppppuVar12 = (undefined8 *******)func_0x00bc3330(0x28);
                *pppppppuVar12 = (undefined8 ******)0x0;
                pppppppuVar12[1] = (undefined8 ******)0x0;
                pppppppuVar12[2] = pppppppuVar17;
                *pppppppuVar13 = pppppppuVar12;
                *(undefined4 *)((long)pppppppuVar12 + 0x1c) = uVar30;
                *(undefined4 *)(pppppppuVar12 + 4) = 0;
                pppppppuVar16 = pppppppuVar12;
                if ((undefined8 *******)*pppppppuStack_a0 != (undefined8 *******)0x0) {
                  pppppppuVar16 = (undefined8 *******)*pppppppuVar13;
                  pppppppuStack_a0 = (undefined8 *******)*pppppppuStack_a0;
                }
                func_0x0040a8c0(pppppppuStack_98,pppppppuVar16);
                lStack_90 = lStack_90 + 1;
                pppppppuVar17 = pppppppuVar12;
LAB_005c2c84:
                puVar29 = puStack_88;
                uVar8 = func_0x00a73150(puStack_88 + *(int *)(pppppppuVar17 + 4));
                pppppppuVar17 = pppppppuStack_98;
                pppppppuVar16 = &pppppppuStack_98;
                while (pppppppuVar13 = pppppppuVar16, pppppppuVar17 != (undefined8 *******)0x0) {
                  while (pppppppuVar12 = pppppppuVar17,
                        (long)*(int *)((long)pppppppuVar12 + 0x1c) <= (long)uVar31) {
                    if ((long)uVar31 <= (long)*(int *)((long)pppppppuVar12 + 0x1c))
                    goto LAB_005c2d28;
                    pppppppuVar17 = (undefined8 *******)pppppppuVar12[1];
                    if ((undefined8 *******)pppppppuVar12[1] == (undefined8 *******)0x0) {
                      pppppppuVar16 = pppppppuVar12 + 1;
                      pppppppuVar13 = pppppppuVar12;
                      goto LAB_005c2cd4;
                    }
                  }
                  pppppppuVar16 = pppppppuVar12;
                  pppppppuVar17 = (undefined8 *******)*pppppppuVar12;
                }
LAB_005c2cd4:
                pppppppuVar12 = (undefined8 *******)func_0x00bc3330(0x28);
                *pppppppuVar12 = (undefined8 ******)0x0;
                pppppppuVar12[1] = (undefined8 ******)0x0;
                pppppppuVar12[2] = pppppppuVar13;
                *pppppppuVar16 = pppppppuVar12;
                *(undefined4 *)((long)pppppppuVar12 + 0x1c) = uVar30;
                *(undefined4 *)(pppppppuVar12 + 4) = 0;
                pppppppuVar17 = pppppppuVar12;
                if ((undefined8 *******)*pppppppuStack_a0 != (undefined8 *******)0x0) {
                  pppppppuVar17 = (undefined8 *******)*pppppppuVar16;
                  pppppppuStack_a0 = (undefined8 *******)*pppppppuStack_a0;
                }
                func_0x0040a8c0(pppppppuStack_98,pppppppuVar17);
                lStack_90 = lStack_90 + 1;
                puVar29 = puStack_88;
LAB_005c2d28:
                iVar6 = func_0x00a5919c(uVar8,*(undefined4 *)  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                                               ((long)puVar29 +
                                               (long)*(int *)(pppppppuVar12 + 4) * 8 + 4));
                if (iVar5 < iVar6) {
                  uVar8 = (undefined4)((ulong)((long)puStack_80 - (long)puVar29) >> 3);
                  pppppppuVar16 = pppppppuStack_98;
                  while (pppppppuVar17 = pppppppuVar14, pppppppuVar16 != (undefined8 *******)0x0) {
                    while (pppppppuVar13 = pppppppuVar16,
                          (long)*(int *)((long)pppppppuVar13 + 0x1c) <= (long)uVar31) {
                      if ((long)uVar31 <= (long)*(int *)((long)pppppppuVar13 + 0x1c))
                      goto LAB_005c2b48;
                      pppppppuVar16 = (undefined8 *******)pppppppuVar13[1];
                      if ((undefined8 *******)pppppppuVar13[1] == (undefined8 *******)0x0) {
                        pppppppuVar14 = pppppppuVar13 + 1;
                        pppppppuVar17 = pppppppuVar13;
                        goto LAB_005c2d8c;
                      }
                    }
                    pppppppuVar14 = pppppppuVar13;
                    pppppppuVar16 = (undefined8 *******)*pppppppuVar13;
                  }
LAB_005c2d8c:
                  pppppppuVar13 = (undefined8 *******)func_0x00bc3330(0x28);
                  goto LAB_005c2b08;
                }
                goto LAB_005c2b4c;
              }
              uVar8 = (undefined4)((long)puStack_80 - (long)puStack_88 >> 3);
              pppppppuVar17 = &pppppppuStack_98;
              goto LAB_005c2afc;
            }
            if (*(int *)(&UNK_00333e04 + lVar21) == 2) {  /* field_off=0x333e04 */
              uVar8 = 0;
              goto LAB_005c29d4;
            }
            goto LAB_005c2b4c;
          }
          goto LAB_005c2820;
        }
      }
LAB_005c26f0:
      puVar29 = puStack_80;
      lVar39 = lVar39 + 1;
    } while (lVar39 != 6);
    uVar31 = uVar31 + 1;
    puVar33 = puStack_88;
    puVar38 = puStack_88;
  } while (uVar31 != 200);
joined_r0x005c2da4:
  if (puVar33 == puVar29) {
    func_0x0058c04c(&pppppppuStack_a0,pppppppuStack_98);
    if (puVar38 != (ulong *)0x0) {
      puStack_80 = puVar38;
      func_0x00bc3350(puVar38);
    }
    if (*(long *)(lVar2 + 0x28) == lStack_70) {
      return;
    }
LAB_005c30c4:
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  uVar31 = *puVar33;
  uVar10 = uVar31 >> 0x20;
  iVar5 = (int)uVar31;
  iVar6 = (int)(uVar31 >> 0x20);
  for (pppppppuVar16 = pppppppuStack_98; pppppppuVar16 != (undefined8 *******)0x0;
      pppppppuVar16 = (undefined8 *******)*pppppppuVar16) {
    if (*(int *)((long)pppppppuVar16 + 0x1c) <= iVar5) {
      pppppppuVar14 = pppppppuStack_98;
      if (iVar5 <= *(int *)((long)pppppppuVar16 + 0x1c)) goto LAB_005c2e30;
      pppppppuVar16 = pppppppuVar16 + 1;
    }
  }
  goto LAB_005c2f30;
LAB_005c2a08:
  pppppppuVar16 = (undefined8 *******)*pppppppuVar16;
  if (pppppppuVar16 == (undefined8 *******)0x0) goto LAB_005c2a28;
  goto LAB_005c2a10;
LAB_005c2a28:
  uVar8 = (undefined4)((long)puStack_80 - (long)puStack_88 >> 3);
  pppppppuVar16 = pppppppuStack_98;
  do {
    while (pppppppuVar13 = pppppppuVar16, pppppppuVar17 = pppppppuVar13,
          (long)uVar31 < (long)*(int *)((long)pppppppuVar13 + 0x1c)) {
      pppppppuVar16 = (undefined8 *******)*pppppppuVar13;
      pppppppuVar14 = pppppppuVar13;
      if ((undefined8 *******)*pppppppuVar13 == (undefined8 *******)0x0) goto LAB_005c2afc;
    }
    if ((long)uVar31 <= (long)*(int *)((long)pppppppuVar13 + 0x1c)) goto LAB_005c2b48;
    pppppppuVar16 = (undefined8 *******)pppppppuVar13[1];
  } while ((undefined8 *******)pppppppuVar13[1] != (undefined8 *******)0x0);
  pppppppuVar14 = pppppppuVar13 + 1;
LAB_005c2afc:
  pppppppuVar13 = (undefined8 *******)func_0x00bc3330(0x28);
LAB_005c2b08:
  *pppppppuVar13 = (undefined8 ******)0x0;
  pppppppuVar13[1] = (undefined8 ******)0x0;
  pppppppuVar13[2] = pppppppuVar17;
  *pppppppuVar14 = pppppppuVar13;
  *(undefined4 *)((long)pppppppuVar13 + 0x1c) = uVar30;
  *(undefined4 *)(pppppppuVar13 + 4) = 0;
  pppppppuVar16 = pppppppuVar13;
  if ((undefined8 *******)*pppppppuStack_a0 != (undefined8 *******)0x0) {
    pppppppuVar16 = (undefined8 *******)*pppppppuVar14;
    pppppppuStack_a0 = (undefined8 *******)*pppppppuStack_a0;
  }
  func_0x0040a8c0(pppppppuStack_98,pppppppuVar16);
  lStack_90 = lStack_90 + 1;
LAB_005c2b48:
  *(undefined4 *)(pppppppuVar13 + 4) = uVar8;
LAB_005c2b4c:
  puVar33 = puStack_80;
  puVar29 = puStack_88;
  if (puStack_80 < puStack_78) {
    *puStack_80 = uVar31 | uVar10 << 0x20;
    puVar29 = puStack_80 + 1;
    goto LAB_005c2820;
  }
  lVar35 = (long)puStack_80 - (long)puStack_88;
  lVar28 = lVar35 >> 3;
  uVar11 = lVar28 + 1;
  if (uVar11 >> 0x3d != 0) {
    if (*(long *)(lVar2 + 0x28) != lStack_70) goto LAB_005c30c4;
    func_0x005c8c2c(&puStack_88);
LAB_005c3004:
    if (*(long *)(lVar2 + 0x28) == lStack_70) {
      uVar15 = func_0x0040fc1c();
      func_0x0058c04c(&pppppppuStack_a0,pppppppuStack_98);
      if (puStack_88 != (ulong *)0x0) {
        puStack_80 = puStack_88;
        func_0x00bc3350();
      }
      if (*(long *)(lVar2 + 0x28) == lStack_70) {
                    /* WARNING: Subroutine does not return */
        NoRet_0x00abf40c(uVar15);
      }
    }
    goto LAB_005c30c4;
  }
  uVar23 = (long)puStack_78 - (long)puStack_88 >> 2;
  if (uVar23 <= uVar11) {
    uVar23 = uVar11;
  }
  if (0x7ffffffffffffff7 < (ulong)((long)puStack_78 - (long)puStack_88)) {
    uVar23 = 0x1fffffffffffffff;
  }
  if (uVar23 == 0) {
    lVar9 = 0;
  }
  else {
    if (uVar23 >> 0x3d != 0) goto LAB_005c3004;
    lVar9 = func_0x00bc3330(uVar23 << 3);
  }
  puVar38 = (ulong *)(lVar9 + lVar28 * 8);
  lVar28 = (long)puVar33 - (long)puVar29;
  *puVar38 = uVar31 | uVar10 << 0x20;
  puVar20 = puVar38;
  puVar34 = puVar33;
  if (lVar28 != 0) {
    uVar11 = lVar28 - 8;
    puVar34 = puStack_88;
    if ((0x37 < uVar11) && (0x1f < (ulong)((long)puVar33 + (-lVar35 - lVar9)))) {
      puVar26 = puVar33 + -2;
      uVar11 = (uVar11 >> 3) + 1;
      uVar25 = uVar11 & 0x3ffffffffffffffc;
      puVar33 = puVar33 + -uVar25;
      puVar20 = puVar38 + -uVar25;
      puVar22 = puVar38 + -2;
      uVar27 = uVar25;
      do {
        puVar3 = puVar26 + -1;
        uVar43 = puVar26[-2];
        uVar42 = puVar26[1];
        uVar41 = *puVar26;
        uVar27 = uVar27 - 4;
        puVar26 = puVar26 + -4;
        puVar22[-1] = *puVar3;
        puVar22[-2] = uVar43;
        puVar22[1] = uVar42;
        *puVar22 = uVar41;
        puVar22 = puVar22 + -4;
      } while (uVar27 != 0);
      if (uVar11 == uVar25) goto LAB_005c2c64;
    }
    do {
      puVar33 = puVar33 + -1;
      puVar20 = puVar20 + -1;
      *puVar20 = *puVar33;
    } while (puVar33 != puVar29);
  }
LAB_005c2c64:
  puStack_78 = (ulong *)(lVar9 + uVar23 * 8);
  puStack_88 = puVar20;
  puVar29 = puVar38 + 1;
  if (puVar34 != (ulong *)0x0) {
    func_0x00bc3350(puVar34);
  }
LAB_005c2820:
  puStack_80 = puVar29;
  uVar10 = uVar10 + 1;
  if (uVar10 == 0x33) goto LAB_005c26f0;
  goto LAB_005c282c;
  while( true ) {
    if (iVar5 <= *(int *)((long)pppppppuVar16 + 0x1c)) goto LAB_005c2ea8;
    pppppppuVar14 = (undefined8 *******)pppppppuVar16[1];
    if ((undefined8 *******)pppppppuVar16[1] == (undefined8 *******)0x0) break;
LAB_005c2e30:
    pppppppuVar16 = pppppppuVar14;
    if (iVar5 < *(int *)((long)pppppppuVar16 + 0x1c)) {
      pppppppuVar14 = (undefined8 *******)*pppppppuVar16;
      pppppppuVar17 = pppppppuVar16;
      if ((undefined8 *******)*pppppppuVar16 == (undefined8 *******)0x0) goto LAB_005c2e58;
      goto LAB_005c2e30;
    }
  }
  pppppppuVar17 = pppppppuVar16 + 1;
LAB_005c2e58:
  pppppppuVar14 = (undefined8 *******)func_0x00bc3330(0x28);
  *pppppppuVar14 = (undefined8 ******)0x0;
  pppppppuVar14[1] = (undefined8 ******)0x0;
  pppppppuVar14[2] = pppppppuVar16;
  *pppppppuVar17 = pppppppuVar14;
  *(int *)((long)pppppppuVar14 + 0x1c) = iVar5;
  *(undefined4 *)(pppppppuVar14 + 4) = 0;
  pppppppuVar16 = pppppppuVar14;
  if ((undefined8 *******)*pppppppuStack_a0 != (undefined8 *******)0x0) {
    pppppppuVar16 = (undefined8 *******)*pppppppuVar17;
    pppppppuStack_a0 = (undefined8 *******)*pppppppuStack_a0;
  }
  func_0x0040a8c0(pppppppuStack_98,pppppppuVar16);
  lStack_90 = lStack_90 + 1;
  puVar38 = puStack_88;
  pppppppuVar16 = pppppppuVar14;
LAB_005c2ea8:
  if (*(int *)((long)puVar38 + (long)*(int *)(pppppppuVar16 + 4) * 8 + 4) != iVar6) {
    if (*(int *)(&UNK_00333e04 + param_1 + (long)iVar5 * 0x30) == 2) {  /* field_off=0x333e04 */
      iVar7 = func_0x00a5919c(0,iVar6);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
      if (*(int *)(&UNK_00333e0c + param_1 + (long)iVar5 * 0x30) < iVar7) goto LAB_005c2de0;  /* field_off=0x333e0c */
    }
    else if ((*(int *)(&UNK_00333e04 + param_1 + (long)iVar5 * 0x30) == 1) &&  /* field_off=0x333e04 */
            (iVar7 = func_0x00a5919c(1,uVar10),  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
            iVar7 < *(int *)(&UNK_00333e0c + param_1 + (long)iVar5 * 0x30))) goto LAB_005c2de0;  /* field_off=0x333e0c */
  }
LAB_005c2f30:
  iVar7 = *(int *)(&UNK_00333e04 + param_1 + (long)iVar5 * 0x30);  /* field_off=0x333e04 */
  (&UNK_003881a0)[param_1 + (long)iVar6 * 200 + (long)iVar5] = 1;  /* field_off=0x3881a0 */
  if (iVar7 == 2) {
    func_0x006db4b4(param_1,uVar31 & 0xffffffff,uVar10,
                    *(undefined4 *)(&UNK_00333e14 + param_1 + (long)iVar5 * 0x30));  /* field_off=0x333e14 */
  }
  else if (iVar7 == 1) {
    func_0x006db2c0(param_1,uVar31 & 0xffffffff,uVar10,
                    *(undefined4 *)(&UNK_00333e14 + param_1 + (long)iVar5 * 0x30));  /* field_off=0x333e14 */
  }
LAB_005c2de0:
  puVar33 = puVar33 + 1;
  goto joined_r0x005c2da4;
}


