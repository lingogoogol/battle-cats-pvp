// ELF VMA: 0x005dd600 | Ghidra Addr: 0x006dd600 | BodySize: 6344

void BattleFn_0x005dd600(long param_1,long param_2,int param_3)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  bool bVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  ulong uVar22;
  ulong uVar23;
  uint *puVar24;
  undefined8 *puVar25;
  int extraout_w1;
  int extraout_w1_00;
  undefined8 uVar26;
  long lVar27;
  long lVar28;
  int *piVar29;
  undefined8 *puVar30;
  long *plVar31;
  uint *puVar32;
  long *plVar33;
  undefined *puVar34;
  long lVar35;
  uint *puVar36;
  int iVar38;
  uint uVar39;
  int iStack_174;
  uint auStack_128 [4];
  undefined8 uStack_118;
  byte abStack_110 [16];
  undefined8 uStack_100;
  byte abStack_f8 [16];
  undefined8 uStack_e8;
  byte abStack_e0 [16];
  undefined8 uStack_d0;
  long lStack_c8;
  long lStack_c0;
  undefined8 uStack_b8;
  undefined1 uStack_a9;
  undefined8 uStack_a8;
  uint *puStack_a0;
  undefined8 uStack_98;
  long lStack_90;
  uint *puVar37;
  
  lVar7 = tpidr_el0;
  lStack_90 = *(long *)(lVar7 + 0x28);
  lStack_c8 = 0;
  lStack_c0 = 0;
  uStack_b8 = 0;
  uVar22 = func_0x005b1be4(param_1 + 0x2648 + (long)param_3 * 0x1f0);
  if ((uVar22 & 1) == 0) {
    plVar33 = (long *)(&UNK_00338900 + param_1);
    lVar35 = param_1 + (long)param_3 * 51000;
    iVar38 = 1 - param_3;
    lVar27 = param_1 + (long)param_3 * 0x1f0;
    uVar22 = 0;
    lVar1 = lVar27 + 0x2820;
LAB_006dd764:
    iVar13 = func_0x00a58874(param_3,uVar22 & 0xffffffff);
    if (iVar13 != 0) {
      func_0x00a60414(param_3,uVar22 & 0xffffffff,0);
      func_0x00a61d74(param_3,uVar22 & 0xffffffff,0);
      uVar14 = func_0x00a608a8(param_3,uVar22 & 0xffffffff);
      func_0x00a60a54(param_3,uVar22 & 0xffffffff,uVar14);
      uVar14 = func_0x00a60aa0(param_3,uVar22 & 0xffffffff);
      func_0x00a60c4c(param_3,uVar22 & 0xffffffff,uVar14);
      uVar14 = func_0x00a60c98(param_3,uVar22 & 0xffffffff);
      func_0x00a60ed0(param_3,uVar22 & 0xffffffff,uVar14);
      uVar14 = func_0x00a5b2b4(param_3,uVar22 & 0xffffffff);
      func_0x00a610ac(param_3,uVar22 & 0xffffffff,uVar14);
      func_0x00a5a97c(param_3,uVar22 & 0xffffffff,0);
      func_0x00a6073c(param_3,uVar22 & 0xffffffff,0);
      func_0x00a614dc(param_3,uVar22 & 0xffffffff,0);
      func_0x00a61730(param_3,uVar22 & 0xffffffff,0);
      func_0x00a61c08(param_3,uVar22 & 0xffffffff,0);
      iVar13 = func_0x00a61a00(param_3,uVar22 & 0xffffffff);
      if (0 < iVar13) {
        func_0x00a61a8c(param_3,uVar22 & 0xffffffff,0xffffffff);
      }
      if (uVar22 == 0) {
        iVar13 = func_0x00a578b4(param_3);
        if (iVar13 < 1) {
          iVar15 = *(int *)(lVar35 + 0x83914);
          iVar16 = *(int *)(param_1 + 0x83688);
          *(undefined4 *)(lVar35 + 0x8390c) = 2;
          uVar14 = func_0x005ab0a8();
          func_0x00646668(&UNK_00327fa0 + param_1,uVar14);
          uVar14 = func_0x005ab0a8();
          iVar13 = func_0x00646668(&UNK_00327fa0 + param_1,uVar14);
          uVar14 = func_0x005ab0a8();
          func_0x00646668(&UNK_00327fa0 + param_1,uVar14);
          iVar18 = (extraout_w1_00 * iVar13) / 100;
          iVar19 = (extraout_w1 * 0x49c) / 100;
          iVar13 = iVar18 + iVar19;
          if (iVar13 < 0 != SCARRY4(iVar18,iVar19)) {
            iVar13 = iVar13 + 1;
          }
          uVar23 = (ulong)(((iVar16 / 5) * 5 - iVar16) + 0x32);
          *(int *)(&UNK_00327db8 + param_1) = iVar15 - (iVar13 >> 1);
          *(undefined4 *)(param_1 + uVar23 * 0x10 + 0x9caf8) = 0xc;
          iVar13 = *(int *)(&UNK_00327db8 + param_1);
          iVar16 = func_0x0043ea60(0xf1);
          lVar28 = param_1 + uVar23 * 0x10;
          iVar15 = *(int *)(lVar35 + 0x83918);
          *(int *)(lVar28 + 0x9cafc) = iVar13 + iVar16 * 10 + -0x75f;
          iVar13 = func_0x0043ea60(0x143);
          *(int *)(lVar28 + 0x9cb00) = iVar15 + iVar13 * -10 + -0x24b;
          *(undefined4 *)(lVar28 + 0x9cb04) = 0;
        }
        else if ((*(int *)(lVar35 + 0x8390c) == 1) &&
                (iVar13 = *(int *)(lVar35 + 0x83910), iVar15 = iVar13 + -1,
                *(int *)(lVar35 + 0x83910) = iVar15, iVar15 == 0 || iVar13 < 1)) {
          *(undefined4 *)(lVar35 + 0x8390c) = 0;
          *(undefined4 *)(lVar35 + 0x83910) = 0;
        }
        goto LAB_006dd758;
      }
      lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
      piVar2 = (int *)(lVar28 + 0x83908);
      piVar29 = (int *)(lVar28 + 0x83950);
      iVar13 = *piVar29;
      if (0 < iVar13) {
        *piVar29 = iVar13 + -1;
      }
      lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
      *(undefined4 *)(lVar28 + 0x83964) = 0;
      func_0x005be388(param_1,param_3,uVar22 & 0xffffffff,iVar38);
      if ((*(int *)(&UNK_0032b738 + param_1) == 1) &&
         (uVar23 = func_0x00a58fe8(param_3,uVar22 & 0xffffffff,0xffffffff), (uVar23 & 1) != 0)) {
        iVar13 = func_0x00a57b7c(iVar38);
        func_0x00a60488(param_3,uVar22 & 0xffffffff,iVar13 * 3);
        *(undefined4 *)(lVar28 + 0x83964) = 1;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0) {
        iVar13 = 0;
        do {
          iVar15 = func_0x006ce084(param_1,param_3,uVar22 & 0xffffffff,iVar13,0);
          if (iVar15 == 1) goto LAB_006dd758;
          iVar13 = iVar13 + 1;
        } while (iVar13 != 0x33);
        iVar13 = func_0x00a608a8(param_3,uVar22 & 0xffffffff);
        if (iVar13 < 1) {
          uVar14 = func_0x00a58d4c(param_3,uVar22 & 0xffffffff);
          iVar13 = func_0x00a60aa0(param_3,uVar22 & 0xffffffff);
          if (0 < iVar13) {
            uVar14 = func_0x0043ed84(uVar14,1);
          }
          func_0x00a59228(param_3,uVar22 & 0xffffffff,uVar14);
          func_0x009b95b4(param_1,param_2,param_3,uVar22 & 0xffffffff);
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0xb) {
        iVar13 = func_0x00a608a8(param_3,uVar22 & 0xffffffff);
        if (iVar13 < 1) {
          func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        }
        iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
        if (0x1d < iVar13) {
          uVar26 = 0xc;
LAB_006ddac0:
          func_0x00a58be4(param_3,uVar22 & 0xffffffff,uVar26);
          func_0x00a590fc(param_3,uVar22 & 0xffffffff,0);
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0xc) {
        func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        iVar13 = func_0x00a5919c(param_3,uVar22 & 0xffffffff);
        iVar15 = func_0x00a62480(param_3,uVar22 & 0xffffffff);
        iVar16 = func_0x00a623ac(param_3,uVar22 & 0xffffffff);
        if (iVar16 + iVar15 < iVar13) {
          uVar26 = 0xd;
          goto LAB_006ddac0;
        }
        uVar14 = func_0x00a58d4c(param_3,uVar22 & 0xffffffff);
        iVar13 = func_0x00a60aa0(param_3,uVar22 & 0xffffffff);
        if (0 < iVar13) {
          uVar14 = func_0x0043ed84(uVar14,1);
        }
        func_0x00a59228(param_3,uVar22 & 0xffffffff,uVar14);
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0xd) {
        iVar13 = func_0x00a608a8(param_3,uVar22 & 0xffffffff);
        if (iVar13 < 1) {
          func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        }
        iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
        if (0x1d < iVar13) {
LAB_006ddc6c:
          uVar26 = 0;
LAB_006ddc70:
          func_0x00a58be4(param_3,uVar22 & 0xffffffff,uVar26);
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0xe) {
        func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        iVar13 = func_0x00a58d8c(param_3,uVar22 & 0xffffffff);
        if (0 < iVar13) {
          func_0x00a62190(param_3,uVar22 & 0xffffffff,0xffffffff);
          iVar13 = func_0x00a58d8c(param_3,uVar22 & 0xffffffff);
          if (iVar13 == 0) {
            uVar26 = 0xf;
            goto LAB_006ddac0;
          }
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0xf) {
        func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
        if (0x19 < iVar13) {
          uVar26 = 0x10;
          goto LAB_006ddc70;
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 0x10) {
        func_0x00a59148(param_3,uVar22 & 0xffffffff,1);
        iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
        if (0x27 < iVar13) goto LAB_006ddc6c;
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if (iVar13 == 3) {
        func_0x009b95b4(param_1,param_2,param_3,uVar22 & 0xffffffff);
        iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
        if (iVar13 == 0) {
          uVar26 = func_0x00a59c68(param_3,uVar22 & 0xffffffff);
          if ((int)uVar26 == 0) {
            BattleFn_0x005dd300(uVar26,param_3,uVar22 & 0xffffffff);
          }
          else {
            func_0x00a58be4(param_3,uVar22 & 0xffffffff,0);
          }
          iVar13 = func_0x00a5a220(param_3,uVar22 & 0xffffffff);
          if (iVar13 == 0) {
            if ((*(char *)(param_1 + 0x32c9) == '\0') || (iVar13 = func_0x005ab154(), iVar13 != 4))
            {
              uVar26 = func_0x0044c16c();
              func_0x0044e35c(uVar26,0x17,0);
            }
            uVar23 = func_0x00a5b960(param_3,uVar22 & 0xffffffff);
            if ((((uVar23 & 1) == 0) ||
                (iVar13 = func_0x00a61f9c(param_3,uVar22 & 0xffffffff), iVar13 == 0)) ||
               (uVar23 = func_0x00a62634(param_3,uVar22 & 0xffffffff), (uVar23 & 1) != 0)) {
              func_0x00a58be4(param_3,uVar22 & 0xffffffff,4);
              func_0x00a590fc(param_3,uVar22 & 0xffffffff,0);
              auStack_128[0] = 0xffffffff;
              iVar13 = func_0x00a5a068(param_3,uVar22 & 0xffffffff);
              plVar31 = *(long **)(lVar27 + 0x2828);
              if (plVar31 != (long *)0x0) {
LAB_006de3e4:
                if (iVar13 < (int)plVar31[4]) goto LAB_006de3dc;
                if ((int)plVar31[4] < iVar13) {
                  plVar31 = plVar31 + 1;
                  goto LAB_006de3dc;
                }
                uVar14 = func_0x00a5a068(param_3,uVar22 & 0xffffffff);
                uStack_a8 = (uint *)CONCAT44(uStack_a8._4_4_,uVar14);
                plVar31 = (long *)BattleFn_0x005defb4(lVar1,&uStack_a8);
                piVar29 = (int *)*plVar31;
                piVar5 = (int *)plVar31[1];
                if (piVar29 == piVar5) {
                  iStack_174 = 0;
                }
                else {
                  iStack_174 = 0;
                  do {
                    iVar13 = *piVar29;
                    uVar39 = 1;
                    do {
                      iVar15 = func_0x00a5a068(iVar38,uVar39);
                      if (iVar15 == iVar13) {
                        func_0x00a5a140(iVar38,uVar39,1);
                        iVar15 = func_0x00a62ebc(iVar38,uVar39);
                        if ((0 < iVar15) && (iStack_174 < iVar15)) {
                          iStack_174 = iVar15;
                          auStack_128[0] = uVar39;
                        }
                      }
                      uVar39 = uVar39 + 1;
                    } while (uVar39 != 0x33);
                    piVar29 = piVar29 + 1;
                  } while (piVar29 != piVar5);
                }
                uVar14 = func_0x00a5a068(param_3,uVar22 & 0xffffffff);
                uStack_a8 = (uint *)CONCAT44(uStack_a8._4_4_,uVar14);
                func_0x006e0618(lVar1,&uStack_a8);
                goto LAB_006de838;
              }
LAB_006de3d4:
              iStack_174 = 0;
LAB_006de838:
              uVar23 = func_0x005d0ad4(param_1);
              if (((uVar23 & 1) != 0) && (iVar13 = func_0x005ab154(), iVar13 != 4)) {
                *(undefined8 *)(param_1 + 0x32f0) = 1;
                iVar15 = func_0x005aaca0();
                iVar13 = 0;
                if (iVar15 != 0) {
                  iVar13 = ((iVar15 * 2 - *(int *)(param_1 + 0x32d0)) *
                           *(int *)(param_1 + (long)param_3 * 51000 + uVar22 * 1000 + 0x83acc)) /
                           iVar15;
                }
                iVar13 = *(int *)((long)__DT_JMPREL + param_1 + (long)*piVar2 * 0x1c4 + 0x7190) /
                         100 + *(int *)(param_1 + 0x32cc) + iVar13;
                if (0x3b9ac9fe < iVar13) {
                  iVar13 = 999999999;
                }
                *(int *)(param_1 + 0x32cc) = iVar13;
              }
              uVar23 = func_0x009d0178(*(undefined8 *)(param_1 + 0x7c0));
              if (((uVar23 & 1) != 0) && (iVar13 = func_0x005ab154(), iVar13 != 4)) {
                iVar13 = *(int *)((long)__DT_JMPREL + param_1 + (long)*piVar2 * 0x1c4 + 0x7190);
                uVar14 = func_0x00a59bdc(param_3,uVar22 & 0xffffffff);
                uStack_a8 = (uint *)CONCAT44(uVar14,iVar13 / 100);
                func_0x009d219c(*(undefined8 *)(param_1 + 0x7c0),1,uVar22 & 0xffffffff,&uStack_a8,2)
                ;
              }
              uVar23 = func_0x005d0ad4(param_1);
              if (((uVar23 & 1) == 0) ||
                 (uVar23 = func_0x00999ab8(param_1 + 0x400), (uVar23 & 1) != 0)) {
                lVar28 = func_0x007fd748();
                uVar14 = func_0x007ac230(0);
                uVar23 = func_0x00633464(lVar28 + 0x668,uVar14,0);
                if ((uVar23 & 1) == 0) {
                  uVar14 = func_0x0057a8a8(param_3,uVar22 & 0xffffffff,iStack_174);
                  BattleFn_0x004b1e64(param_1 + 0x2648,uVar14);
                  if (0 < iStack_174) {
                    func_0x0040cb78(&uStack_a8,&UNK_0029c499);
                    if (((ulong)uStack_a8 & 1) != 0) {
                      func_0x00bc3350(uStack_98);
                    }
                    func_0x006a5d58(&lStack_c8,auStack_128);
                  }
                }
              }
              lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
              *(undefined8 *)(lVar28 + 0x83a34) = 0;
              *(undefined8 *)(lVar28 + 0x839fc) = 0;
              *(undefined8 *)(lVar28 + 0x83a10) = 0;
              *(undefined4 *)(lVar28 + 0x83a3c) = 0;
              func_0x00a61434(param_3,uVar22 & 0xffffffff,0,0);
              func_0x00a61434(param_3,uVar22 & 0xffffffff,1,0);
              func_0x00a61434(param_3,uVar22 & 0xffffffff,2,0);
              func_0x00a61434(param_3,uVar22 & 0xffffffff,3,0);
              func_0x00a61434(param_3,uVar22 & 0xffffffff,4,0);
            }
            else {
              iVar13 = func_0x00a61f9c(param_3,uVar22 & 0xffffffff);
              if (0 < iVar13) {
                func_0x00a62070(param_3,uVar22 & 0xffffffff,0xffffffff);
              }
              func_0x00a58be4(param_3,uVar22 & 0xffffffff,0xe);
              func_0x00a590fc(param_3,uVar22 & 0xffffffff,0);
              uVar14 = func_0x00a622d8(param_3,uVar22 & 0xffffffff);
              func_0x00a62124(param_3,uVar22 & 0xffffffff,uVar14);
              iVar13 = func_0x00a5a194(param_3,uVar22 & 0xffffffff);
              iVar15 = func_0x00a62204(param_3,uVar22 & 0xffffffff);
              func_0x00a5a260(param_3,uVar22 & 0xffffffff,(iVar15 * iVar13) / 100);
            }
          }
          else {
            *(undefined4 *)(param_1 + (long)param_3 * 51000 + uVar22 * 1000 + 0x83a04) = 0;
            iVar13 = func_0x00a5fec0(param_3,uVar22 & 0xffffffff);
            if ((0 < iVar13) && (iVar13 = func_0x00a6177c(param_3,uVar22 & 0xffffffff), iVar13 == 0)
               ) {
              iVar13 = func_0x00a5fec0(param_3,uVar22 & 0xffffffff);
              iVar15 = func_0x00a5ff4c(param_3,uVar22 & 0xffffffff);
              func_0x00a617bc(param_3,uVar22 & 0xffffffff,(iVar15 * iVar13) / 100);
              func_0x00a61848(param_3,uVar22 & 0xffffffff,0);
              func_0x00a618d4(param_3,uVar22 & 0xffffffff,3);
              func_0x00a61960(param_3,uVar22 & 0xffffffff,0);
              uVar26 = func_0x0044c16c();
              func_0x0044e364(uVar26,0x8a);
            }
          }
        }
        else {
          uVar23 = func_0x00a595d0(param_2,param_3,uVar22 & 0xffffffff);
          if ((uVar23 & 1) != 0) {
            lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
            *(int *)(lVar28 + 0x83914) = *(int *)(lVar28 + 0x83914) + -0x3c;
            func_0x00a5967c(param_2,param_3,uVar22 & 0xffffffff);
          }
          lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
          iVar13 = *(int *)(lVar28 + 0x83910);
          puVar34 = &DAT_00c0aed4;
LAB_006dde3c:
          *(int *)(lVar28 + 0x83918) =
               *(int *)(lVar28 + 0x83918) + *(int *)(puVar34 + (long)iVar13 * 4);
        }
        goto LAB_006dd758;
      }
      iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
      if ((iVar13 != 4) && (iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff), iVar13 != 0x15))
      {
        iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
        if (iVar13 != 0x11) {
          iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
          if (iVar13 == 5) {
            func_0x009b95b4(param_1,param_2,param_3,uVar22 & 0xffffffff);
            iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
            if (iVar13 != 0) {
              uVar23 = func_0x00a595d0(param_2,param_3,uVar22 & 0xffffffff);
              if ((uVar23 & 1) != 0) {
                lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
                *(int *)(lVar28 + 0x83914) = *(int *)(lVar28 + 0x83914) + -0x14;
                func_0x00a5967c(param_2,param_3,uVar22 & 0xffffffff);
              }
              lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
              iVar13 = *(int *)(lVar28 + 0x83910);
              puVar34 = &DAT_00c0af34;
              goto LAB_006dde3c;
            }
            uVar26 = func_0x00a59c68(param_3,uVar22 & 0xffffffff);
LAB_006de800:
            if ((int)uVar26 != 0) goto LAB_006ddc6c;
            BattleFn_0x005dd300(uVar26,param_3,uVar22 & 0xffffffff);
          }
          else {
            iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
            if (iVar13 == 6) {
              func_0x009b95b4(param_1,param_2,param_3,uVar22 & 0xffffffff);
              iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
              if (iVar13 == 0) {
                uVar26 = func_0x00a59c68(param_3,uVar22 & 0xffffffff);
                goto LAB_006de800;
              }
              uVar23 = func_0x00a595d0(param_2,param_3,uVar22 & 0xffffffff);
              if ((uVar23 & 1) != 0) {
                if (1 < *piVar2) {
                  func_0x0040cb78(&uStack_a8,&UNK_0029306b);
                  func_0x00a589e0(abStack_110,param_3,uVar22 & 0xffffffff);
                  if ((abStack_110[0] & 1) != 0) {
                    func_0x00bc3350(uStack_100);
                  }
                  if (((ulong)uStack_a8 & 1) != 0) {
                    func_0x00bc3350(uStack_98);
                  }
                }
                uStack_a8 = (uint *)0x0;
                puStack_a0 = (uint *)0x0;
                uStack_98 = 0;
                uVar23 = func_0x00a5b3a4(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0xc);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b484(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0xe);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b564(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0xd);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b7a0(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0xf);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b644(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0x13);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b960(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0x14);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                uVar23 = func_0x00a5b880(param_3,uVar22 & 0xffffffff);
                if ((uVar23 & 1) == 0) {
                  auStack_128[0] = 0;
                }
                else {
                  auStack_128[0] = BattleFn_0x0091f9dc(&UNK_00290568 + param_1,0x15);
                }
                func_0x006df080(&uStack_a8,auStack_128);
                puVar24 = uStack_a8;
                if ((uStack_a8 != puStack_a0) && (uStack_a8 + 1 != puStack_a0)) {
                  puVar32 = uStack_a8;
                  puVar36 = uStack_a8 + 1;
                  uVar39 = *uStack_a8;
                  do {
                    puVar37 = puVar36 + 1;
                    uVar6 = *puVar36;
                    uVar4 = uVar39;
                    if ((int)uVar39 <= (int)uVar6) {
                      uVar4 = uVar6;
                    }
                    puVar24 = puVar36;
                    if ((int)uVar6 <= (int)uVar39) {
                      puVar24 = puVar32;
                    }
                    puVar32 = puVar24;
                    puVar36 = puVar37;
                    uVar39 = uVar4;
                  } while (puVar37 != puStack_a0);
                }
                uVar39 = *puVar24;
                iVar13 = *(int *)(param_1 + (long)param_3 * 51000 + uVar22 * 1000 + 0x83910);
                iVar15 = BattleFn_0x007700d4(param_1 + 0x4407e8,0x11,0xffffffff);
                iVar16 = func_0x00a6081c(param_3,uVar22 & 0xffffffff);
                iVar13 = ((0xc - iVar13) % 0xc) * 10;
                lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
                iVar13 = (int)((ulong)((long)((100 - iVar16) *
                                             ((((int)(iVar13 * uVar39) / 1000 + iVar13) *
                                              (iVar15 + 100)) / 100)) * -0x51eb851f) >> 0x20);
                *(int *)(lVar28 + 0x83914) =
                     *(int *)(lVar28 + 0x83914) + ((iVar13 >> 5) - (iVar13 >> 0x1f));
                func_0x0040cb78(auStack_128,&UNK_002a4683);
                BattleFn_0x007700d4(param_1 + 0x4407e8,0x11,0xffffffff);
                func_0x00a6081c(param_3,uVar22 & 0xffffffff);
                if ((auStack_128[0] & 1) != 0) {
                  func_0x00bc3350(uStack_118);
                }
                func_0x00a5967c(param_2,param_3,uVar22 & 0xffffffff);
                if (uStack_a8 != (uint *)0x0) {
                  puStack_a0 = uStack_a8;
                  func_0x00bc3350();
                }
              }
            }
            else {
              BattleFn_0x005dd3f0(param_1,param_2,param_3,uVar22 & 0xffffffff);
            }
          }
        }
        goto LAB_006dd758;
      }
      lVar28 = 200;
      piVar29 = (int *)(&UNK_00333e04 + param_1);
      do {
        if ((uVar22 == (uint)piVar29[-1]) && (*piVar29 == 2)) goto LAB_006ddf38;
        lVar28 = lVar28 + -1;
        piVar29 = piVar29 + 0xc;
      } while (lVar28 != 0);
      puVar30 = (undefined8 *)*plVar33;
      if (*(long *)(&UNK_00338908 + param_1) - (long)puVar30 != 0) {
        uVar23 = *(long *)(&UNK_00338908 + param_1) - (long)puVar30 >> 3;
        if (uVar23 < 2) {
          uVar23 = 1;
        }
        do {
          if ((*(int *)*puVar30 == param_3) && (uVar22 == (uint)((int *)*puVar30)[1]))
          goto LAB_006ddf38;
          uVar23 = uVar23 - 1;
          puVar30 = puVar30 + 1;
        } while (uVar23 != 0);
      }
      puVar30 = *(undefined8 **)(&UNK_00338918 + param_1);
      if (*(long *)(&UNK_00338920 + param_1) - (long)puVar30 != 0) {
        uVar23 = *(long *)(&UNK_00338920 + param_1) - (long)puVar30 >> 3;
        if (uVar23 < 2) {
          uVar23 = 1;
        }
        do {
          if ((*(int *)*puVar30 == param_3) && (uVar22 == (uint)((int *)*puVar30)[1]))
          goto LAB_006ddf38;
          uVar23 = uVar23 - 1;
          puVar30 = puVar30 + 1;
        } while (uVar23 != 0);
      }
      bVar12 = true;
      goto LAB_006ddf6c;
    }
    goto LAB_006dd758;
  }
  BattleFn_0x005dbc18(param_1,param_2,param_3);
LAB_006dd700:
  if (lStack_c8 != 0) {
    lStack_c0 = lStack_c8;
    func_0x00bc3350();
  }
  if (*(long *)(lVar7 + 0x28) == lStack_90) {
    return;
  }
LAB_006defb0:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
LAB_006de3dc:
  plVar31 = (long *)*plVar31;
  if (plVar31 == (long *)0x0) goto LAB_006de3d4;
  goto LAB_006de3e4;
LAB_006ddf38:
  bVar12 = false;
LAB_006ddf6c:
  iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
  if (iVar13 == 4) {
    iVar13 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
    if (iVar13 == 0) {
      func_0x006ee0f4(param_1 + 0xe0,param_3,1);
    }
    uVar23 = func_0x00a59fd4(param_3,uVar22 & 0xffffffff);
    if ((uVar23 & 1) == 0) {
      iVar15 = 1;
    }
    else {
      uVar14 = BattleFn_0x004ab2d8(param_3,uVar22 & 0xffffffff);
      func_0x005acf30(param_2,param_3,uVar14,8);
      iVar15 = func_0x0044003c();
      if (iVar15 < 2) {
        iVar15 = 1;
      }
    }
    iVar16 = func_0x00a59eb4(param_3,uVar22 & 0xffffffff);
    iVar13 = iVar15;
    if (-1 < iVar16) {
      iVar13 = func_0x00a59eb4(param_3,uVar22 & 0xffffffff);
      auStack_128[0] = iVar13 + 1000;
      uStack_a8 = auStack_128;
      lVar28 = func_0x0064bd28(param_2 + 0x33a8,auStack_128,&UNK_002afa25,&uStack_a8,&uStack_a9);
      iVar13 = func_0x0044003c(lVar28 + 0x28);
      if (iVar13 <= iVar15) {
        iVar13 = iVar15;
      }
    }
  }
  else {
    iVar13 = func_0x00a58ba4(param_3,uVar22 & 0xffffffff);
    if (iVar13 == 0x15) {
      func_0x0040cb78(abStack_e0,&UNK_002a1342);
      uVar14 = func_0x008e3f14(param_1 + 0x1478,abStack_e0,0x1e);
      uVar17 = func_0x0044003c(param_2 + (long)param_3 * 0x38 + 0x27f8);
      iVar13 = func_0x0043ed6c(uVar14,uVar17);
      if ((abStack_e0[0] & 1) != 0) {
        func_0x00bc3350(uStack_d0);
      }
      if (iVar13 < 2) {
        iVar13 = 1;
      }
      iVar15 = func_0x00a590bc(param_3,uVar22 & 0xffffffff);
      func_0x0040cb78(abStack_f8,&UNK_002a1342);
      iVar16 = func_0x008e3f14(param_1 + 0x1478,abStack_f8,0x1e);
      if ((abStack_f8[0] & 1) != 0) {
        func_0x00bc3350(uStack_e8);
      }
      if (iVar15 == iVar16) {
        func_0x006da618(param_1,param_3,uVar22 & 0xffffffff,0);
        uVar26 = *(undefined8 *)(&UNK_00388180 + param_1);
        iVar15 = *(int *)(&UNK_0038817c + param_1);
        uVar17 = *(undefined4 *)(&UNK_00388184 + param_1);
        uVar14 = *(undefined4 *)(&UNK_00388190 + param_1);
        uVar8 = *(undefined8 *)(&UNK_00388188 + param_1);
        uVar11 = *(undefined8 *)(&UNK_00388174 + param_1);
        uVar10 = *(undefined8 *)(&UNK_0038816c + param_1);
        uVar9 = *(undefined8 *)(&UNK_00388194 + param_1);
        puVar24 = (uint *)func_0x00bc3330(0x48);
        puVar24[0x10] = 0;
        puVar24[0x11] = 0;
        puVar30 = *(undefined8 **)(&UNK_00338908 + param_1);
        puVar25 = *(undefined8 **)(&UNK_00338910 + param_1);
        puVar24[2] = 0;
        puVar24[3] = 0;
        puVar24[0] = 0;
        puVar24[1] = 0;
        puVar24[6] = 0;
        puVar24[7] = 0;
        puVar24[4] = 0;
        puVar24[5] = 0;
        puVar24[10] = 0;
        puVar24[0xb] = 0;
        puVar24[8] = 0;
        puVar24[9] = 0;
        puVar24[0xe] = 0;
        puVar24[0xf] = 0;
        puVar24[0xc] = 0;
        puVar24[0xd] = 0;
        *(uint **)(puVar24 + 0xc) = puVar24 + 0xe;
        if (puVar30 < puVar25) {
          uStack_a8 = (uint *)0x0;
          puVar25 = puVar30 + 1;
          *puVar30 = puVar24;
        }
        else {
          uStack_a8 = puVar24;
          puVar25 = (undefined8 *)func_0x005c8c54(plVar33,&uStack_a8);
        }
        *(undefined8 **)(&UNK_00338908 + param_1) = puVar25;
        func_0x005c3ee4(&uStack_a8);
        if (*(long *)(&UNK_00338908 + param_1) != *plVar33) {
          piVar29 = *(int **)(*(long *)(&UNK_00338908 + param_1) + -8);
          *piVar29 = param_3;
          piVar29[1] = (int)uVar22;
          piVar29[2] = 0;
          iVar16 = func_0x00a5919c(param_3,uVar22 & 0xffffffff);
          iVar18 = func_0x00a5d468(param_3,uVar22 & 0xffffffff);
          func_0x00a5d4f4(param_3,uVar22 & 0xffffffff);
          func_0x0043ecf8();
          iVar19 = func_0x0043ea60();
          iVar20 = func_0x00a5d4f4(param_3,uVar22 & 0xffffffff);
          if (*(long *)(&UNK_00338908 + param_1) != *plVar33) {
            iVar3 = -iVar19;
            if (0 < iVar20) {
              iVar3 = iVar19;
            }
            *(int *)(*(long *)(*(long *)(&UNK_00338908 + param_1) + -8) + 0xc) =
                 iVar18 + iVar16 + iVar3;
            uVar21 = func_0x00a5d580(param_3,uVar22 & 0xffffffff);
            if (*(long *)(&UNK_00338908 + param_1) != *plVar33) {
              lVar28 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
              *(undefined4 *)(lVar28 + 0x10) = uVar21;
              *(undefined4 *)(lVar28 + 0x14) = 0;
              *(undefined4 *)(lVar28 + 0x24) = 0;
              uVar23 = (ulong)CONCAT16(-((int)((ulong)uVar9 >> 0x20) != 0),
                                       (uint6)CONCAT14(-((int)uVar9 != 0),
                                                       (uint)(CONCAT12(-((int)(CONCAT17((char)((uint
                                                  )uVar14 >> 0x18),
                                                  CONCAT16((char)((uint)uVar14 >> 0x10),
                                                           CONCAT15((char)((uint)uVar14 >> 8),
                                                                    CONCAT14((char)uVar14,
                                                                             (int)uVar26)))) >> 0x20
                                                  ) != 0),-(ushort)((int)uVar26 != 0)) & 0xff00ff)))
                       & 0x1000100010001;
              *(uint *)(lVar28 + 0x20) =
                   CONCAT13((char)(uVar23 >> 0x30),
                            CONCAT12((char)(uVar23 >> 0x20),
                                     CONCAT11((char)(uVar23 >> 0x10),(char)uVar23)));
              *(ulong *)(lVar28 + 0x18) =
                   CONCAT17(~-((int)uVar8 == 0),
                            CONCAT16(~-((int)((ulong)uVar8 >> 0x20) == 0),
                                     CONCAT15(~-((int)(CONCAT17((char)((uint)uVar17 >> 0x18),
                                                                CONCAT16((char)((uint)uVar17 >> 0x10
                                                                               ),CONCAT15((char)((
                                                  uint)uVar17 >> 8),CONCAT14((char)uVar17,iVar15))))
                                                  >> 0x20) == 0),
                                              CONCAT14(~-(iVar15 == 0),
                                                       CONCAT13(~-((int)((ulong)uVar11 >> 0x20) == 0
                                                                  ),CONCAT12(~-((int)uVar11 == 0),
                                                                             CONCAT11(~-((int)((
                                                  ulong)uVar10 >> 0x20) == 0),~-((int)uVar10 == 0)))
                                                  ))))) & 0x101010101010101;
              iVar15 = func_0x00a5d698(param_3,uVar22 & 0xffffffff);
              if (*(long *)(&UNK_00338908 + param_1) != *plVar33) {
                lVar28 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
                *(bool *)(lVar28 + 0x28) = iVar15 != 0;
                *(undefined4 *)(lVar28 + 0x2c) = 2;
                goto LAB_006de604;
              }
            }
          }
        }
        if (*(long *)(lVar7 + 0x28) == lStack_90) {
          uVar26 = func_0x005c8c40(plVar33);
          if ((auStack_128[0] & 1) != 0) {
            func_0x00bc3350(uStack_118);
          }
          if (uStack_a8 != (uint *)0x0) {
            puStack_a0 = uStack_a8;
            func_0x00bc3350();
          }
          if (lStack_c8 != 0) {
            lStack_c0 = lStack_c8;
            func_0x00bc3350(lStack_c8);
          }
          if (*(long *)(lVar7 + 0x28) == lStack_90) {
                    /* WARNING: Subroutine does not return */
            NoRet_0x00abf40c(uVar26);
          }
        }
        goto LAB_006defb0;
      }
    }
    else {
      iVar13 = 1;
    }
  }
LAB_006de604:
  if (*(int *)(param_1 + (long)param_3 * 51000 + uVar22 * 1000 + 0x83910) < iVar13) {
    func_0x009b95b4(param_1,param_2,param_3,uVar22 & 0xffffffff);
  }
  else if (bVar12) {
    *piVar2 = 0;
    lVar28 = param_1 + (long)param_3 * 51000 + uVar22 * 1000;
    *(undefined8 *)(lVar28 + 0x83978) = 0;
    *(undefined4 *)(lVar28 + 0x83974) = 0;
  }
LAB_006dd758:
  uVar22 = uVar22 + 1;
  if (uVar22 == 0x33) goto LAB_006ded74;
  goto LAB_006dd764;
LAB_006ded74:
  if (lStack_c0 != lStack_c8) {
    uVar22 = 0;
    do {
      func_0x00a62efc(iVar38,*(undefined4 *)(lStack_c8 + uVar22 * 4),0);
      uVar22 = uVar22 + 1;
    } while (uVar22 < (ulong)(lStack_c0 - lStack_c8 >> 2));
  }
  iVar38 = 1;
  do {
    iVar13 = func_0x00a58874(param_3,iVar38);
    if ((iVar13 != 0) && (iVar13 = func_0x00a5a220(param_3,iVar38), 0 < iVar13)) {
      iVar13 = func_0x00a5a068(param_3,iVar38);
      for (plVar33 = *(long **)(lVar27 + 0x2828); plVar33 != (long *)0x0; plVar33 = (long *)*plVar33
          ) {
        if (*(int *)(plVar33 + 4) <= iVar13) {
          if (iVar13 <= *(int *)(plVar33 + 4)) {
            uVar14 = func_0x00a5a068(param_3,iVar38);
            uStack_a8 = (uint *)CONCAT44(uStack_a8._4_4_,uVar14);
            func_0x006e0618(lVar1,&uStack_a8);
            break;
          }
          plVar33 = plVar33 + 1;
        }
      }
    }
    iVar38 = iVar38 + 1;
  } while (iVar38 != 0x33);
  goto LAB_006dd700;
}


