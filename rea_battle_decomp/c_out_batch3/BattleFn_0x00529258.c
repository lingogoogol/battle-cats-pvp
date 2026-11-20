// ELF VMA: 0x00529258 | Ghidra Addr: 0x00629258 | BodySize: 1488

int BattleFn_0x00529258(long param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  ulong uVar15;
  undefined8 *puVar16;
  int iVar17;
  float fVar18;
  
  puVar14 = (undefined8 *)(param_1 + 0x18);
  puVar10 = (undefined8 *)*puVar14;
  puVar13 = puVar10;
  do {
    if (puVar13 == (undefined8 *)0x0) {
      return 0;
    }
    if (*(int *)(puVar13 + 4) <= param_2) {
      if (param_2 <= *(int *)(puVar13 + 4)) {
        uVar15 = 0;
        iVar17 = 1;
        puVar13 = puVar14;
joined_r0x006292f8:
        do {
          puVar9 = puVar13;
          if (puVar10 != (undefined8 *)0x0) {
            do {
              puVar7 = puVar10;
              puVar13 = puVar7;
              if (param_2 < *(int *)(puVar7 + 4)) {
                puVar10 = (undefined8 *)*puVar7;
                goto joined_r0x006292f8;
              }
              if (param_2 <= *(int *)(puVar7 + 4)) goto LAB_00629380;
              puVar10 = (undefined8 *)puVar7[1];
            } while ((undefined8 *)puVar7[1] != (undefined8 *)0x0);
            puVar9 = puVar7 + 1;
          }
          puVar7 = (undefined8 *)func_0x00bc3330(0x40);
          puVar7[6] = 0;
          puVar7[7] = 0;
          puVar7[5] = 0;
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = puVar13;
          *puVar9 = puVar7;
          plVar11 = *(long **)(param_1 + 0x10);
          *(int *)(puVar7 + 4) = param_2;
          puVar13 = puVar7;
          if (*plVar11 != 0) {
            *(long *)(param_1 + 0x10) = *plVar11;
            puVar13 = (undefined8 *)*puVar9;
          }
          func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
          *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_00629380:
          uVar12 = ((long)(puVar7[6] - puVar7[5]) >> 2) * -0x3333333333333333;
          if (uVar12 < uVar15 || uVar12 - uVar15 == 0) {
            return 0;
          }
          puVar13 = (undefined8 *)*puVar14;
          iVar6 = param_3 - iVar17;
          puVar9 = puVar14;
          puVar10 = puVar13;
          puVar7 = puVar14;
          if (iVar17 <= param_3) {
            while (puVar16 = puVar9, puVar10 != (undefined8 *)0x0) {
              while (puVar9 = puVar10, *(int *)(puVar9 + 4) <= param_2) {
                puVar8 = puVar9;
                if (param_2 <= *(int *)(puVar9 + 4)) goto LAB_00629444;
                puVar10 = (undefined8 *)puVar9[1];
                if ((undefined8 *)puVar9[1] == (undefined8 *)0x0) {
                  puVar16 = puVar9 + 1;
                  goto LAB_006293f0;
                }
              }
              puVar10 = (undefined8 *)*puVar9;
            }
LAB_006293f0:
            puVar8 = (undefined8 *)func_0x00bc3330(0x40);
            puVar8[6] = 0;
            puVar8[7] = 0;
            puVar8[5] = 0;
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = puVar9;
            *puVar16 = puVar8;
            plVar11 = *(long **)(param_1 + 0x10);
            *(int *)(puVar8 + 4) = param_2;
            puVar13 = puVar8;
            if (*plVar11 != 0) {
              *(long *)(param_1 + 0x10) = *plVar11;
              puVar13 = (undefined8 *)*puVar16;
            }
            func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
            puVar13 = *(undefined8 **)(param_1 + 0x18);
            *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_00629444:
            puVar9 = puVar14;
            puVar10 = puVar13;
            if (param_3 <= *(int *)(puVar8[5] + uVar15 * 0x14 + 8)) {
              while (puVar7 = puVar9, puVar10 != (undefined8 *)0x0) {
                while (puVar7 = puVar10, *(int *)(puVar7 + 4) <= param_2) {
                  puVar10 = puVar7;
                  if (param_2 <= *(int *)(puVar7 + 4)) goto LAB_00629574;
                  puVar10 = (undefined8 *)puVar7[1];
                  if ((undefined8 *)puVar7[1] == (undefined8 *)0x0) {
                    puVar9 = puVar7 + 1;
                    goto LAB_00629520;
                  }
                }
                puVar9 = puVar7;
                puVar10 = (undefined8 *)*puVar7;
              }
LAB_00629520:
              puVar10 = (undefined8 *)func_0x00bc3330(0x40);
              puVar10[6] = 0;
              puVar10[7] = 0;
              puVar10[5] = 0;
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = puVar7;
              *puVar9 = puVar10;
              plVar11 = *(long **)(param_1 + 0x10);
              *(int *)(puVar10 + 4) = param_2;
              puVar13 = puVar10;
              if (*plVar11 != 0) {
                *(long *)(param_1 + 0x10) = *plVar11;
                puVar13 = (undefined8 *)*puVar9;
              }
              func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
              puVar13 = *(undefined8 **)(param_1 + 0x18);
              *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_00629574:
              iVar1 = *(int *)(puVar10[5] + uVar15 * 0x14 + 4);
              puVar10 = puVar14;
              puVar9 = puVar13;
              while (puVar7 = puVar10, puVar9 != (undefined8 *)0x0) {
                while (puVar10 = puVar9, *(int *)(puVar10 + 4) <= param_2) {
                  puVar9 = puVar10;
                  if (param_2 <= *(int *)(puVar10 + 4)) goto LAB_00629618;
                  puVar9 = (undefined8 *)puVar10[1];
                  if ((undefined8 *)puVar10[1] == (undefined8 *)0x0) {
                    puVar7 = puVar10 + 1;
                    goto LAB_006295c4;
                  }
                }
                puVar9 = (undefined8 *)*puVar10;
              }
LAB_006295c4:
              puVar9 = (undefined8 *)func_0x00bc3330(0x40);
              puVar9[6] = 0;
              puVar9[7] = 0;
              puVar9[5] = 0;
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = puVar10;
              *puVar7 = puVar9;
              plVar11 = *(long **)(param_1 + 0x10);
              *(int *)(puVar9 + 4) = param_2;
              puVar13 = puVar9;
              if (*plVar11 != 0) {
                *(long *)(param_1 + 0x10) = *plVar11;
                puVar13 = (undefined8 *)*puVar7;
              }
              func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
              puVar13 = *(undefined8 **)(param_1 + 0x18);
              *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_00629618:
              iVar2 = *(int *)(puVar9[5] + uVar15 * 0x14 + 8);
              puVar10 = puVar14;
              puVar9 = puVar13;
              while (puVar7 = puVar10, puVar9 != (undefined8 *)0x0) {
                while (puVar10 = puVar9, *(int *)(puVar10 + 4) <= param_2) {
                  puVar9 = puVar10;
                  if (param_2 <= *(int *)(puVar10 + 4)) goto LAB_006296bc;
                  puVar9 = (undefined8 *)puVar10[1];
                  if ((undefined8 *)puVar10[1] == (undefined8 *)0x0) {
                    puVar7 = puVar10 + 1;
                    goto LAB_00629668;
                  }
                }
                puVar9 = (undefined8 *)*puVar10;
              }
LAB_00629668:
              puVar9 = (undefined8 *)func_0x00bc3330(0x40);
              puVar9[6] = 0;
              puVar9[7] = 0;
              puVar9[5] = 0;
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = puVar10;
              *puVar7 = puVar9;
              plVar11 = *(long **)(param_1 + 0x10);
              *(int *)(puVar9 + 4) = param_2;
              puVar13 = puVar9;
              if (*plVar11 != 0) {
                *(long *)(param_1 + 0x10) = *plVar11;
                puVar13 = (undefined8 *)*puVar7;
              }
              func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
              puVar13 = *(undefined8 **)(param_1 + 0x18);
              *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_006296bc:
              iVar3 = *(int *)(puVar9[5] + uVar15 * 0x14 + 0xc);
              do {
                puVar10 = puVar14;
                if (puVar13 == (undefined8 *)0x0) {
LAB_00629704:
                  puVar9 = (undefined8 *)func_0x00bc3330(0x40);
                  puVar9[6] = 0;
                  puVar9[7] = 0;
                  puVar9[5] = 0;
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = puVar10;
                  *puVar14 = puVar9;
                  plVar11 = *(long **)(param_1 + 0x10);
                  *(int *)(puVar9 + 4) = param_2;
                  puVar13 = puVar9;
                  if (*plVar11 != 0) {
                    *(long *)(param_1 + 0x10) = *plVar11;
                    puVar13 = (undefined8 *)*puVar14;
                  }
                  func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar13);
                  *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_00629758:
                  iVar4 = *(int *)(puVar9[5] + uVar15 * 0x14 + 0x10);
                  if (iVar1 == 2) {
                    fVar18 = (float)func_0x0043ecf4((float)iVar6 / (float)(iVar2 - iVar17) + -1.0,
                                                    0x40400000);
                    fVar18 = fVar18 + 1.0;
                  }
                  else {
                    if (iVar1 != 1) {
                      if (iVar1 != 0) {
                        return 0;
                      }
                      iVar1 = 0;
                      if (iVar2 - iVar17 != 0) {
                        iVar1 = ((iVar4 - iVar3) * iVar6) / (iVar2 - iVar17);
                      }
                      return iVar1 + iVar3;
                    }
                    fVar18 = (float)func_0x0043ecf4((float)iVar6 / (float)(iVar2 - iVar17),
                                                    0x40400000);
                  }
                  return (int)((float)iVar3 + fVar18 * (float)(iVar4 - iVar3));
                }
                while (puVar9 = puVar13, *(int *)(puVar9 + 4) <= param_2) {
                  if (param_2 <= *(int *)(puVar9 + 4)) goto LAB_00629758;
                  puVar13 = (undefined8 *)puVar9[1];
                  if ((undefined8 *)puVar9[1] == (undefined8 *)0x0) {
                    puVar14 = puVar9 + 1;
                    puVar10 = puVar9;
                    goto LAB_00629704;
                  }
                }
                puVar13 = (undefined8 *)*puVar9;
                puVar14 = puVar9;
              } while( true );
            }
          }
          while (puVar9 = puVar7, puVar13 != (undefined8 *)0x0) {
            while (puVar7 = puVar13, *(int *)(puVar7 + 4) <= param_2) {
              puVar13 = puVar7;
              if (param_2 <= *(int *)(puVar7 + 4)) goto LAB_006292dc;
              puVar13 = (undefined8 *)puVar7[1];
              if ((undefined8 *)puVar7[1] == (undefined8 *)0x0) {
                puVar9 = puVar7 + 1;
                goto LAB_0062949c;
              }
            }
            puVar13 = (undefined8 *)*puVar7;
          }
LAB_0062949c:
          puVar13 = (undefined8 *)func_0x00bc3330(0x40);
          puVar13[6] = 0;
          puVar13[7] = 0;
          puVar13[5] = 0;
          *puVar13 = 0;
          puVar13[1] = 0;
          puVar13[2] = puVar7;
          *puVar9 = puVar13;
          plVar11 = *(long **)(param_1 + 0x10);
          *(int *)(puVar13 + 4) = param_2;
          puVar10 = puVar13;
          if (*plVar11 != 0) {
            *(long *)(param_1 + 0x10) = *plVar11;
            puVar10 = (undefined8 *)*puVar9;
          }
          func_0x0040a8c0(*(undefined8 *)(param_1 + 0x18),puVar10);
          puVar10 = *(undefined8 **)(param_1 + 0x18);
          *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
LAB_006292dc:
          lVar5 = uVar15 * 0x14;
          uVar15 = uVar15 + 1;
          iVar17 = *(int *)(puVar13[5] + lVar5 + 8);
          puVar13 = puVar14;
        } while( true );
      }
      puVar13 = puVar13 + 1;
    }
    puVar13 = (undefined8 *)*puVar13;
  } while( true );
}


