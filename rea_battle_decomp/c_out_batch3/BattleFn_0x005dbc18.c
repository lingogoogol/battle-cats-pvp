// ELF VMA: 0x005dbc18 | Ghidra Addr: 0x006dbc18 | BodySize: 5824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x005dbc18(long param_1,long param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  bool bVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  ulong uVar20;
  undefined8 uVar21;
  undefined8 *puVar22;
  undefined8 uVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  int *piVar27;
  long lVar28;
  int iVar29;
  long lVar30;
  undefined *puVar31;
  undefined8 *puVar32;
  ulong uVar33;
  long *plVar34;
  long *plVar35;
  ulong auStack_d0 [2];
  undefined8 *puStack_c0;
  ulong auStack_b0 [2];
  undefined8 *puStack_a0;
  int iStack_90;
  undefined1 uStack_89;
  int *piStack_88;
  long lStack_80;
  
  uVar6 = tpidr_el0;
  lStack_80 = *(long *)(uVar6 + 0x28);
  puVar32 = (undefined8 *)(param_1 + 0x838f8);
  plVar35 = (long *)(&UNK_00338900 + param_1);
  func_0x0058e72c((undefined8 *)(param_1 + 0x838f0),*puVar32);
  *(undefined8 *)(param_1 + 0x838f0) = puVar32;
  bVar10 = param_3 == 0;
  *(undefined8 *)(param_1 + 0x83900) = 0;
  lVar24 = param_1 + (long)param_3 * 51000;
  iVar2 = -0x3c;
  if (bVar10) {
    iVar2 = 0x3c;
  }
  iVar3 = -0x14;
  if (bVar10) {
    iVar3 = 0x14;
  }
  lVar30 = param_1 + (long)param_3 * 0x1f0;
  uVar33 = 0;
  iVar29 = 0;
  if (!bVar10) {
    iVar29 = -0x73a;
  }
  lVar25 = param_1 + (long)param_3 * 0xb4;
  *puVar32 = 0;
LAB_006dbe6c:
  iVar11 = func_0x00a58874(param_3,uVar33 & 0xffffffff);
  if (iVar11 == 0) goto LAB_006dbe60;
  func_0x00a60414(param_3,uVar33 & 0xffffffff,0);
  func_0x00a61d74(param_3,uVar33 & 0xffffffff,0);
  uVar12 = func_0x00a608a8(param_3,uVar33 & 0xffffffff);
  func_0x00a60a54(param_3,uVar33 & 0xffffffff,uVar12);
  uVar12 = func_0x00a60aa0(param_3,uVar33 & 0xffffffff);
  func_0x00a60c4c(param_3,uVar33 & 0xffffffff,uVar12);
  uVar12 = func_0x00a60c98(param_3,uVar33 & 0xffffffff);
  func_0x00a60ed0(param_3,uVar33 & 0xffffffff,uVar12);
  uVar12 = func_0x00a5b2b4(param_3,uVar33 & 0xffffffff);
  func_0x00a610ac(param_3,uVar33 & 0xffffffff,uVar12);
  func_0x00a5a97c(param_3,uVar33 & 0xffffffff,0);
  func_0x00a6073c(param_3,uVar33 & 0xffffffff,0);
  func_0x00a614dc(param_3,uVar33 & 0xffffffff,0);
  func_0x00a61730(param_3,uVar33 & 0xffffffff,0);
  func_0x00a61c08(param_3,uVar33 & 0xffffffff,0);
  if (uVar33 != 0) {
    lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
    piVar27 = (int *)(lVar26 + 0x83950);
    iVar11 = *piVar27;
    if (0 < iVar11) {
      *piVar27 = iVar11 + -1;
    }
    *(undefined4 *)(param_1 + (long)param_3 * 51000 + uVar33 * 1000 + 0x83964) = 0;
    iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
    if (iVar11 == 0) {
      iVar11 = 0;
      do {
        iVar15 = func_0x006ce084(param_1,param_3,uVar33 & 0xffffffff,iVar11,0);
        if (iVar15 == 1) goto LAB_006dbe60;
        iVar11 = iVar11 + 1;
      } while (iVar11 != 0x33);
      iVar11 = func_0x00a608a8(param_3,uVar33 & 0xffffffff);
      if (iVar11 < 1) {
        iVar11 = func_0x00a58d4c(param_3,uVar33 & 0xffffffff);
        iVar15 = func_0x00a60aa0(param_3,uVar33 & 0xffffffff);
        if (0 < iVar15) {
          iVar11 = func_0x0043ed84(iVar11,1);
        }
        iVar15 = -iVar11;
        if (param_3 != 0) {
          iVar15 = iVar11;
        }
        func_0x00a59228(param_3,uVar33 & 0xffffffff,iVar15);
        func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
      }
      goto LAB_006dbe60;
    }
    iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
    if (iVar11 == 3) {
      func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
      iVar11 = func_0x00a590bc(param_3,uVar33 & 0xffffffff);
      if (iVar11 == 0) {
        uVar21 = func_0x00a59c68(param_3,uVar33 & 0xffffffff);
        if ((int)uVar21 == 0) {
          BattleFn_0x005dd300(uVar21,param_3,uVar33 & 0xffffffff);
        }
        else {
          func_0x00a58be4(param_3,uVar33 & 0xffffffff,0);
        }
        if (*(int *)(param_1 + (long)param_3 * 51000 + uVar33 * 1000 + 0x83928) == 0) {
          if ((*(char *)(param_1 + 0x32c9) == '\0') || (iVar11 = func_0x005ab154(), iVar11 != 4)) {
            uVar21 = func_0x0044c16c();
            func_0x0044e35c(uVar21,0x18,0);
          }
          func_0x00a58be4(param_3,uVar33 & 0xffffffff,4);
          func_0x00a590fc(param_3,uVar33 & 0xffffffff,0);
          iVar11 = func_0x00a5c7b4(param_3,uVar33 & 0xffffffff);
          if (0 < iVar11) {
            iVar11 = func_0x00a62e30(param_3,uVar33 & 0xffffffff);
            if (iVar11 == 0) {
              uVar12 = BattleFn_0x004ab2d8(param_3,uVar33 & 0xffffffff);
              iVar11 = func_0x005ad22c(param_3,uVar12);
            }
            iVar15 = func_0x00a5c7b4(param_3,uVar33 & 0xffffffff);
            uVar12 = func_0x0043ed6c((iVar15 * iVar11) / 100,1);
            BattleFn_0x004b1e64(lVar30 + 0x2648,uVar12);
            func_0x00a5c7b4(param_3,uVar33 & 0xffffffff);
          }
LAB_006dc7a8:
          lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
          *(undefined8 *)(lVar26 + 0x83a34) = 0;
          *(undefined8 *)(lVar26 + 0x839fc) = 0;
          *(undefined8 *)(lVar26 + 0x83a10) = 0;
          *(undefined4 *)(lVar26 + 0x83a3c) = 0;
          func_0x00a61434(param_3,uVar33 & 0xffffffff,0,0);
          func_0x00a61434(param_3,uVar33 & 0xffffffff,1,0);
          func_0x00a61434(param_3,uVar33 & 0xffffffff,2,0);
          func_0x00a61434(param_3,uVar33 & 0xffffffff,3,0);
          func_0x00a61434(param_3,uVar33 & 0xffffffff,4,0);
        }
      }
      else {
        uVar20 = func_0x00a595d0(param_2,param_3,uVar33 & 0xffffffff);
        if ((uVar20 & 1) != 0) {
          lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
          *(int *)(lVar26 + 0x83914) = *(int *)(lVar26 + 0x83914) + iVar2;
          func_0x00a5967c(param_2,param_3,uVar33 & 0xffffffff);
        }
        lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
        iVar11 = *(int *)(lVar26 + 0x83910);
        puVar31 = &DAT_00c0aed4;
LAB_006dc054:
        iVar11 = *(int *)(puVar31 + (long)iVar11 * 4);
LAB_006dc058:
        *(int *)(lVar26 + 0x83918) = *(int *)(lVar26 + 0x83918) + iVar11;
      }
      goto LAB_006dbe60;
    }
    iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
    if ((iVar11 != 4) && (iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff), iVar11 != 0x15)) {
      iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
      if (iVar11 == 5) {
        func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
        iVar11 = func_0x00a590bc(param_3,uVar33 & 0xffffffff);
        if (iVar11 != 0) {
          uVar20 = func_0x00a595d0(param_2,param_3,uVar33 & 0xffffffff);
          if ((uVar20 & 1) != 0) {
            lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
            *(int *)(lVar26 + 0x83914) = *(int *)(lVar26 + 0x83914) + iVar3;
            func_0x00a5967c(param_2,param_3,uVar33 & 0xffffffff);
          }
          lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
          iVar11 = *(int *)(lVar26 + 0x83910);
          puVar31 = &DAT_00c0af34;
          goto LAB_006dc054;
        }
LAB_006dc984:
        uVar21 = func_0x00a59c68(param_3,uVar33 & 0xffffffff);
        if ((int)uVar21 == 0) {
          BattleFn_0x005dd300(uVar21,param_3,uVar33 & 0xffffffff);
        }
        else {
          func_0x00a58be4(param_3,uVar33 & 0xffffffff,0);
        }
      }
      else {
        iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
        if (iVar11 == 6) {
          func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
          iVar11 = func_0x00a590bc(param_3,uVar33 & 0xffffffff);
          if (iVar11 == 0) goto LAB_006dc984;
          uVar20 = func_0x00a595d0(param_2,param_3,uVar33 & 0xffffffff);
          if ((uVar20 & 1) != 0) {
            lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
            iVar15 = (0xc - *(int *)(lVar26 + 0x83910)) % 0xc;
            iVar11 = iVar15 * -10;
            if (param_3 == 0) {
              iVar11 = iVar15 * 10;
            }
            iVar15 = func_0x00a628b8(param_3,uVar33 & 0xffffffff);
            iVar14 = func_0x00a6081c(param_3,uVar33 & 0xffffffff);
            *(int *)(lVar26 + 0x83914) =
                 (((iVar11 * (100 - iVar15)) / 100) * (100 - iVar14)) / 100 +
                 *(int *)(lVar26 + 0x83914);
            func_0x00a5967c(param_2,param_3,uVar33 & 0xffffffff);
            func_0x00a628b8(param_3,uVar33 & 0xffffffff);
            func_0x00a6081c(param_3,uVar33 & 0xffffffff);
          }
        }
        else {
          iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
          if (iVar11 == 7) {
            func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
            iVar11 = func_0x00a590bc(param_3,uVar33 & 0xffffffff);
            if (iVar11 != 0) {
              uVar20 = func_0x00a595d0(param_2,param_3,uVar33 & 0xffffffff);
              if ((uVar20 & 1) != 0) {
                lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
                *(int *)(lVar26 + 0x83914) = *(int *)(lVar26 + 0x83914) + iVar2;
                func_0x00a5967c(param_2,param_3,uVar33 & 0xffffffff);
              }
              lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
              iVar11 = *(int *)(lVar26 + 0x83910);
              if (iVar11 < 0) {
                iVar11 = iVar11 + 1;
              }
              iVar11 = *(int *)(&DAT_00c0aed4 + (long)(iVar11 >> 1) * 4);
              goto LAB_006dc058;
            }
            uVar21 = func_0x00a59c68(param_3,uVar33 & 0xffffffff);
            if ((int)uVar21 == 0) {
              BattleFn_0x005dd300(uVar21,param_3,uVar33 & 0xffffffff);
            }
            else {
              func_0x00a58be4(param_3,uVar33 & 0xffffffff,0);
            }
            if (*(int *)(param_1 + (long)param_3 * 51000 + uVar33 * 1000 + 0x83928) == 0) {
              if ((*(char *)(param_1 + 0x32c9) == '\0') || (iVar11 = func_0x005ab154(), iVar11 != 4)
                 ) {
                uVar21 = func_0x0044c16c();
                func_0x0044e35c(uVar21,0x18,0);
              }
              func_0x00a58be4(param_3,uVar33 & 0xffffffff,4);
              func_0x00a590fc(param_3,uVar33 & 0xffffffff,0);
              goto LAB_006dc7a8;
            }
          }
          else {
            BattleFn_0x005dd3f0(param_1,param_2,param_3,uVar33 & 0xffffffff);
          }
        }
      }
      goto LAB_006dbe60;
    }
    lVar28 = 200;
    piVar27 = (int *)(&UNK_00333e04 + param_1);
    do {
      if ((uVar33 == (uint)piVar27[-1]) && (*piVar27 == 1)) goto LAB_006dc2fc;
      lVar28 = lVar28 + -1;
      piVar27 = piVar27 + 0xc;
    } while (lVar28 != 0);
    puVar32 = (undefined8 *)*plVar35;
    if (*(long *)(&UNK_00338908 + param_1) - (long)puVar32 != 0) {
      uVar20 = *(long *)(&UNK_00338908 + param_1) - (long)puVar32 >> 3;
      if (uVar20 < 2) {
        uVar20 = 1;
      }
      do {
        if ((*(int *)*puVar32 == param_3) && (uVar33 == (uint)((int *)*puVar32)[1]))
        goto LAB_006dc2fc;
        uVar20 = uVar20 - 1;
        puVar32 = puVar32 + 1;
      } while (uVar20 != 0);
    }
    bVar10 = true;
    goto LAB_006dc308;
  }
  iVar11 = func_0x00a578c8(param_3);
  if (iVar11 == 1) {
    func_0x00a579a0(param_3,1);
    iVar11 = func_0x00a57934(param_3);
    if (0x10 < iVar11) {
      func_0x00a578fc(param_3,2);
      func_0x00a57968(param_3,0);
      uVar21 = func_0x0044c16c();
      func_0x0044e014(uVar21,0x19);
    }
    goto LAB_006dd1f8;
  }
  iVar11 = func_0x00a578c8(param_3);
  if ((iVar11 == 2) || (iVar11 = func_0x00a578c8(param_3), iVar11 == 10)) {
    func_0x00a579a0(param_3,1);
    uVar20 = func_0x00a57934(param_3);
    if ((uVar20 & 3) != 0) goto LAB_006dd1f8;
    if (*(int *)(lVar25 + 0x9ce78) == 0) {
      lVar26 = 0;
      piVar27 = (int *)(lVar25 + 0x9ce78);
    }
    else if (*(int *)(lVar25 + 0x9ce84) == 0) {
      lVar26 = 1;
      piVar27 = (int *)(lVar25 + 0x9ce84);
    }
    else if (*(int *)(lVar25 + 0x9ce90) == 0) {
      lVar26 = 2;
      piVar27 = (int *)(lVar25 + 0x9ce90);
    }
    else if (*(int *)(lVar25 + 0x9ce9c) == 0) {
      lVar26 = 3;
      piVar27 = (int *)(lVar25 + 0x9ce9c);
    }
    else if (*(int *)(lVar25 + 0x9cea8) == 0) {
      lVar26 = 4;
      piVar27 = (int *)(lVar25 + 0x9cea8);
    }
    else if (*(int *)(lVar25 + 0x9ceb4) == 0) {
      lVar26 = 5;
      piVar27 = (int *)(lVar25 + 0x9ceb4);
    }
    else if (*(int *)(lVar25 + 0x9cec0) == 0) {
      lVar26 = 6;
      piVar27 = (int *)(lVar25 + 0x9cec0);
    }
    else if (*(int *)(lVar25 + 0x9cecc) == 0) {
      lVar26 = 7;
      piVar27 = (int *)(lVar25 + 0x9cecc);
    }
    else if (*(int *)(lVar25 + 0x9ced8) == 0) {
      lVar26 = 8;
      piVar27 = (int *)(lVar25 + 0x9ced8);
    }
    else if (*(int *)(lVar25 + 0x9cee4) == 0) {
      lVar26 = 9;
      piVar27 = (int *)(lVar25 + 0x9cee4);
    }
    else if (*(int *)(lVar25 + 0x9cef0) == 0) {
      lVar26 = 10;
      piVar27 = (int *)(lVar25 + 0x9cef0);
    }
    else if (*(int *)(lVar25 + 0x9cefc) == 0) {
      lVar26 = 0xb;
      piVar27 = (int *)(lVar25 + 0x9cefc);
    }
    else if (*(int *)(lVar25 + 0x9cf08) == 0) {
      lVar26 = 0xc;
      piVar27 = (int *)(lVar25 + 0x9cf08);
    }
    else if (*(int *)(lVar25 + 0x9cf14) == 0) {
      lVar26 = 0xd;
      piVar27 = (int *)(lVar25 + 0x9cf14);
    }
    else {
      if (*(int *)(lVar25 + 0x9cf20) != 0) goto LAB_006dd1f8;
      lVar26 = 0xe;
      piVar27 = (int *)(lVar25 + 0x9cf20);
    }
    iVar11 = func_0x005ab154();
    if (iVar11 == 0) {
      iVar11 = func_0x00a578c8(param_3);
      if (iVar11 == 2) {
        uVar21 = 0x1a;
      }
      else {
        iVar11 = func_0x00a578c8(param_3);
        if (iVar11 != 10) goto LAB_006dd0fc;
        uVar21 = 0x55;
      }
      uVar23 = func_0x0044c16c();
      func_0x0044e35c(uVar23,uVar21,0);
    }
LAB_006dd0fc:
    iVar11 = func_0x00a57c8c(param_3);
    if (iVar11 == 0) {
      iVar11 = func_0x0044003c(param_2 + 0x30d8);
      iVar11 = iVar11 + -1;
LAB_006dd138:
      *piVar27 = iVar11;
    }
    else {
      iVar11 = func_0x00a57c8c(param_3);
      if (iVar11 == 5) {
        iVar11 = func_0x0044003c(param_1 + 0x2d40);
        goto LAB_006dd138;
      }
    }
    iVar15 = func_0x005aecec(param_3);
    iVar14 = func_0x00a57934(param_3);
    iVar11 = iVar14 + 3;
    if (-1 < iVar14) {
      iVar11 = iVar14;
    }
    iVar14 = _DAT_00c0b310 * (iVar11 >> 2);
    lVar26 = param_1 + (long)param_3 * 0xb4 + lVar26 * 0xc;
    iVar11 = iVar14 * -10;
    if (param_3 != 0) {
      iVar11 = iVar14 * 10;
    }
    *(int *)(lVar26 + 0x9ce7c) = iVar15 + iVar29 + iVar11;
    uVar12 = func_0x00a57ab8(param_3);
    *(undefined4 *)(lVar26 + 0x9ce80) = uVar12;
    iVar15 = func_0x00a57934(param_3);
    iVar11 = iVar15 + 3;
    if (-1 < iVar15) {
      iVar11 = iVar15;
    }
    iVar15 = func_0x00a57834(param_3);
    if (iVar15 <= iVar11 >> 2) {
      func_0x00a578fc(param_3,0);
      iVar11 = param_3;
LAB_006dd1f0:
      func_0x00a57968(iVar11,0);
    }
  }
  else {
    iVar11 = func_0x00a578c8(param_3);
    if ((iVar11 == 3) || (iVar11 = func_0x00a578c8(param_3), iVar11 == 0xc)) {
      func_0x00a579a0(param_3,1);
      iVar11 = func_0x00a57934(param_3);
      if (0x20 < iVar11) {
LAB_006dc620:
        func_0x00a578fc(0,0);
        iVar11 = 0;
        goto LAB_006dd1f0;
      }
    }
    else {
      iVar11 = func_0x00a578c8(param_3);
      if (iVar11 == 4) {
        func_0x00a579a0(param_3,1);
        iVar11 = func_0x00a57934(param_3);
        iVar15 = func_0x0044003c(param_1 + 0x2d40);
        if (iVar15 < iVar11) {
          func_0x00a578fc(0,5);
          func_0x00a57968(0,0);
          uVar21 = func_0x0044c16c();
          uVar23 = 0x24;
LAB_006dce78:
          func_0x0044e35c(uVar21,uVar23,0);
        }
      }
      else {
        iVar11 = func_0x00a578c8(param_3);
        if (iVar11 == 7) {
          func_0x00a579a0(param_3,1);
          iVar11 = func_0x00a57934(param_3);
          iVar15 = func_0x0044003c(param_1 + 0x2d40);
          if (iVar15 < iVar11) {
            func_0x00a578fc(0,8);
            func_0x00a57968(0,0);
            uVar21 = func_0x0044c16c();
            uVar23 = 0x53;
            goto LAB_006dce78;
          }
        }
        else {
          iVar11 = func_0x00a578c8(param_3);
          if ((iVar11 == 5) || (iVar11 = func_0x00a578c8(param_3), iVar11 == 8)) {
            func_0x00a579a0(param_3,1);
            iVar11 = func_0x00a57934(param_3);
            lVar26 = 0x2d40;
          }
          else {
            iVar11 = func_0x00a578c8(param_3);
            if (iVar11 != 6) {
              iVar11 = func_0x00a578c8(param_3);
              if (iVar11 == 9) {
                func_0x00a579a0(param_3,1);
                iVar11 = func_0x00a57934(param_3);
                if (0x10 < iVar11) {
                  func_0x00a578fc(param_3,10);
                  func_0x00a57968(param_3,0);
                  uVar21 = func_0x0044c16c();
                  func_0x0044e014(uVar21,0x54);
                }
              }
              else {
                iVar11 = func_0x00a578c8(param_3);
                if (iVar11 == 0xb) {
                  func_0x00a579a0(param_3,1);
                  iVar11 = func_0x00a57934(param_3);
                  if (iVar11 == 5) {
                    uVar21 = func_0x0044c16c();
                    uVar23 = 0x56;
                    goto LAB_006dce78;
                  }
                  iVar11 = func_0x00a57934(param_3);
                  iVar15 = func_0x0044003c(param_1 + 0x2d78);
                  if (iVar15 < iVar11 + -10) goto LAB_006dc620;
                }
              }
              goto LAB_006dd1f8;
            }
            func_0x00a579a0(param_3,1);
            iVar11 = func_0x00a57934(param_3);
            lVar26 = 0x2d08;
          }
          iVar15 = func_0x0044003c(param_1 + lVar26);
          if (iVar15 < iVar11) goto LAB_006dc620;
        }
      }
    }
  }
LAB_006dd1f8:
  iVar11 = func_0x00a578b4(param_3);
  if (iVar11 < 1) {
    iVar11 = *(int *)(lVar24 + 0x83914);
    puVar1 = (undefined4 *)
             (param_1 + 0x9c778 + (ulong)(*(int *)(param_1 + 0x83688) % 5 + 0x32) * 0x10);
    *(undefined4 *)(lVar24 + 0x8390c) = 2;
    *puVar1 = 0xc;
    iVar14 = func_0x0043ea60(0xf1);
    iVar15 = *(int *)(lVar24 + 0x83918);
    puVar1[1] = iVar11 + iVar14 * 10 + -0x43f;
    iVar11 = func_0x0043ea60(0x143);
    puVar1[2] = iVar15 + iVar11 * -10 + -0x24b;
    puVar1[3] = 0;
  }
  else if ((*(int *)(lVar24 + 0x8390c) == 1) &&
          (iVar11 = *(int *)(lVar24 + 0x83910), iVar15 = iVar11 + -1,
          *(int *)(lVar24 + 0x83910) = iVar15, iVar15 == 0 || iVar11 < 1)) {
    *(undefined4 *)(lVar24 + 0x8390c) = 0;
    *(undefined4 *)(lVar24 + 0x83910) = 0;
  }
  goto LAB_006dbe60;
LAB_006dc2fc:
  bVar10 = false;
LAB_006dc308:
  iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
  if (iVar11 == 4) {
    iVar11 = func_0x00a590bc();
    if (iVar11 == 0) {
      func_0x006ee0f4(param_1 + 0xe0,param_3,1);
    }
    uVar20 = func_0x00a59fd4(param_3,uVar33 & 0xffffffff);
    if ((uVar20 & 1) == 0) {
      iVar11 = 1;
    }
    else {
      uVar12 = BattleFn_0x004ab2d8(param_3,uVar33 & 0xffffffff);
      func_0x005acf30(param_2,param_3,uVar12,8);
      iVar11 = func_0x0044003c();
      if (iVar11 < 2) {
        iVar11 = 1;
      }
    }
    iVar14 = func_0x00a59eb4(param_3,uVar33 & 0xffffffff);
    iVar15 = iVar11;
    if (-1 < iVar14) {
      iStack_90 = func_0x00a59eb4(param_3,uVar33 & 0xffffffff);
      piStack_88 = &iStack_90;
      iStack_90 = iStack_90 + 1000;
      lVar28 = func_0x0064bd28(param_2 + 0x33a8,&iStack_90,&UNK_002afa25,&piStack_88,&uStack_89);
      iVar15 = func_0x0044003c(lVar28 + 0x28);
      if (iVar15 <= iVar11) {
        iVar15 = iVar11;
      }
    }
LAB_006dcc44:
    if (*(int *)(param_1 + (long)param_3 * 51000 + uVar33 * 1000 + 0x83910) < iVar15) {
      func_0x009b95b4(param_1,param_2,param_3,uVar33 & 0xffffffff);
    }
    else if (bVar10) {
      iVar11 = func_0x00a5da7c(param_3,uVar33 & 0xffffffff);
      if (-1 < iVar11) {
        uVar20 = 0;
        do {
          if ((uVar33 != uVar20) &&
             (iVar11 = func_0x00a58874(param_3,uVar20 & 0xffffffff), iVar11 != 0)) {
            iVar11 = func_0x00a58934(param_3,uVar20 & 0xffffffff);
            iVar15 = func_0x00a58934(param_3,uVar33 & 0xffffffff);
            if ((iVar11 == iVar15) &&
               (iVar11 = func_0x00a58ba4(param_3,uVar20 & 0xffffffff), iVar11 != 4))
            goto LAB_006dcd2c;
          }
          uVar20 = uVar20 + 1;
        } while ((int)uVar20 != 0x33);
        iVar11 = BattleFn_0x004ab2d8(param_3,uVar33 & 0xffffffff);
        *(undefined4 *)(lVar30 + 0x26b4 + (long)iVar11 * 4) = 0;
      }
LAB_006dcd2c:
      if (((param_3 == 0) && (iVar11 = func_0x00a62da4(0,uVar33 & 0xffffffff), 0 < iVar11)) &&
         (0 < *(int *)(lVar24 + 0x83938))) {
        iVar11 = func_0x00a579e0(0);
        iVar15 = func_0x00a62da4(0,uVar33 & 0xffffffff);
        iVar11 = (iVar15 * iVar11) / 1000;
        func_0x00a579e0(0);
        func_0x00a62da4(0,uVar33 & 0xffffffff);
        func_0x0043ed6c(*(int *)(lVar24 + 0x83938) - iVar11,1);
        iVar11 = *(int *)(lVar24 + 0x83938) - iVar11;
        if (iVar11 < 2) {
          iVar11 = 1;
        }
        *(int *)(lVar24 + 0x83938) = iVar11;
      }
      *(undefined4 *)(lVar26 + 0x83908) = 0;
      lVar26 = param_1 + (long)param_3 * 51000 + uVar33 * 1000;
      *(undefined8 *)(lVar26 + 0x83978) = 0;
      *(undefined4 *)(lVar26 + 0x83974) = 0;
    }
LAB_006dbe60:
    uVar33 = uVar33 + 1;
    if (uVar33 == 0x33) {
      if (*(long *)(uVar6 + 0x28) == lStack_80) {
        return;
      }
LAB_006dd2fc:
                    /* WARNING: Subroutine does not return */
      NoRet_0x00ac3380();
    }
    goto LAB_006dbe6c;
  }
  iVar11 = func_0x00a58ba4(param_3,uVar33 & 0xffffffff);
  if (iVar11 != 0x15) {
    iVar15 = 1;
    goto LAB_006dcc44;
  }
  puStack_a0 = (undefined8 *)func_0x00bc3330(0x20);
  auStack_b0[1] = 0x19;
  auStack_b0[0] = 0x21;
  *(undefined1 *)((long)puStack_a0 + 0x19) = 0;
  puStack_a0[1] = 0x6c6f765f68746165;
  *puStack_a0 = 0x645f656c74746162;
  *(undefined8 *)((long)puStack_a0 + 0x11) = 0x656d69745f6f6e61;
  *(undefined8 *)((long)puStack_a0 + 9) = 0x636c6f765f687461;
  uVar12 = func_0x008e3f14(param_1 + 0x1478,auStack_b0,0x1e);
  uVar13 = func_0x0044003c(param_2 + (long)param_3 * 0x38 + 0x27f8);
  iVar15 = func_0x0043ed6c(uVar12,uVar13);
  if ((auStack_b0[0] & 1) != 0) {
    func_0x00bc3350(puStack_a0);
  }
  if (iVar15 < 2) {
    iVar15 = 1;
  }
  iVar11 = func_0x00a590bc(param_3,uVar33 & 0xffffffff);
  puStack_c0 = (undefined8 *)func_0x00bc3330(0x20);
  *(undefined1 *)((long)puStack_c0 + 0x19) = 0;
  auStack_d0[1] = 0x19;
  auStack_d0[0] = 0x21;
  puStack_c0[1] = 0x6c6f765f68746165;
  *puStack_c0 = 0x645f656c74746162;
  *(undefined8 *)((long)puStack_c0 + 0x11) = 0x656d69745f6f6e61;
  *(undefined8 *)((long)puStack_c0 + 9) = 0x636c6f765f687461;
  iVar14 = func_0x008e3f14(param_1 + 0x1478,auStack_d0,0x1e);
  if ((auStack_d0[0] & 1) != 0) {
    func_0x00bc3350(puStack_c0);
  }
  if (iVar11 != iVar14) goto LAB_006dcc44;
  func_0x006da618(param_1,param_3,uVar33 & 0xffffffff,0);
  uVar9 = *(undefined8 *)(&UNK_00388180 + param_1);
  uVar8 = *(undefined8 *)(&UNK_00388174 + param_1);
  uVar21 = *(undefined8 *)(&UNK_0038816c + param_1);
  iVar11 = *(int *)(&UNK_0038817c + param_1);
  iVar14 = *(int *)(&UNK_00388184 + param_1);
  iVar5 = *(int *)(&UNK_00388190 + param_1);
  uVar23 = *(undefined8 *)(&UNK_00388188 + param_1);
  uVar7 = *(undefined8 *)(&UNK_00388194 + param_1);
  uVar12 = func_0x00a5f6cc(param_3,uVar33 & 0xffffffff);
  piVar27 = (int *)func_0x00bc3330(0x48);
  puVar32 = *(undefined8 **)(&UNK_00338908 + param_1);
  puVar22 = *(undefined8 **)(&UNK_00338910 + param_1);
  piVar27[0x10] = 0;
  piVar27[0x11] = 0;
  piVar27[2] = 0;
  piVar27[3] = 0;
  piVar27[0] = 0;
  piVar27[1] = 0;
  piVar27[6] = 0;
  piVar27[7] = 0;
  piVar27[4] = 0;
  piVar27[5] = 0;
  piVar27[10] = 0;
  piVar27[0xb] = 0;
  piVar27[8] = 0;
  piVar27[9] = 0;
  piVar27[0xe] = 0;
  piVar27[0xf] = 0;
  piVar27[0xc] = 0;
  piVar27[0xd] = 0;
  *(int **)(piVar27 + 0xc) = piVar27 + 0xe;
  if (puVar32 < puVar22) {
    piStack_88 = (int *)0x0;
    puVar22 = puVar32 + 1;
    *puVar32 = piVar27;
  }
  else {
    piStack_88 = piVar27;
    puVar22 = (undefined8 *)func_0x005c8c54(plVar35,&piStack_88);
  }
  piVar27 = piStack_88;
  *(undefined8 **)(&UNK_00338908 + param_1) = puVar22;
  piStack_88 = (int *)0x0;
  if (piVar27 != (int *)0x0) {
    func_0x0058c04c(piVar27 + 0xc,*(undefined8 *)(piVar27 + 0xe));
    func_0x00bc3350(piVar27);
    puVar22 = *(undefined8 **)(&UNK_00338908 + param_1);
  }
  uVar20 = uVar6;
  plVar34 = plVar35;
  if (puVar22 == (undefined8 *)*plVar35) {
LAB_006dd26c:
    if (*(long *)(uVar6 + 0x28) != lStack_80) goto LAB_006dd2fc;
    func_0x005c8c40(plVar35);
    plVar35 = plVar34;
  }
  else {
    piVar27 = (int *)puVar22[-1];
    *piVar27 = param_3;
    piVar27[1] = (int)uVar33;
    piVar27[2] = 0;
    iVar16 = func_0x00a5919c(param_3,uVar33 & 0xffffffff);
    uVar17 = func_0x00a5d468(param_3,uVar33 & 0xffffffff);
    uVar20 = (ulong)uVar17;
    func_0x00a5d4f4(param_3,uVar33 & 0xffffffff);
    func_0x0043ecf8();
    uVar18 = func_0x0043ea60();
    plVar34 = (long *)(ulong)uVar18;
    iVar19 = func_0x00a5d4f4(param_3,uVar33 & 0xffffffff);
    if (*(long *)(&UNK_00338908 + param_1) == *plVar35) goto LAB_006dd26c;
    uVar4 = -uVar18;
    if (iVar19 < 1) {
      uVar4 = uVar18;
    }
    *(uint *)(*(long *)(*(long *)(&UNK_00338908 + param_1) + -8) + 0xc) = (iVar16 - uVar17) + uVar4;
    uVar13 = func_0x00a5d580(param_3,uVar33 & 0xffffffff);
    if (*(long *)(&UNK_00338908 + param_1) == *plVar35) {
      lVar24 = *(long *)(uVar6 + 0x28);
      goto LAB_006dd298;
    }
    lVar28 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
    *(undefined4 *)(lVar28 + 0x10) = uVar13;
    *(undefined4 *)(lVar28 + 0x14) = 0;
    *(undefined4 *)(lVar28 + 0x24) = uVar12;
    uVar20 = (ulong)CONCAT16(-((int)((ulong)uVar7 >> 0x20) != 0),
                             (uint6)CONCAT14(-((int)uVar7 != 0),
                                             (uint)(CONCAT12(-(iVar5 != 0),
                                                             -(ushort)((int)uVar9 != 0)) & 0xff00ff)
                                            )) & 0x1000100010001;
    *(uint *)(lVar28 + 0x20) =
         CONCAT13((char)(uVar20 >> 0x30),
                  CONCAT12((char)(uVar20 >> 0x20),CONCAT11((char)(uVar20 >> 0x10),(char)uVar20)));
    *(ulong *)(lVar28 + 0x18) =
         CONCAT17(~-((int)uVar23 == 0),
                  CONCAT16(~-((int)((ulong)uVar23 >> 0x20) == 0),
                           CONCAT15(~-(iVar14 == 0),
                                    CONCAT14(~-(iVar11 == 0),
                                             CONCAT13(~-((int)((ulong)uVar8 >> 0x20) == 0),
                                                      CONCAT12(~-((int)uVar8 == 0),
                                                               CONCAT11(~-((int)((ulong)uVar21 >>
                                                                                0x20) == 0),
                                                                        ~-((int)uVar21 == 0))))))))
         & 0x101010101010101;
    iVar11 = func_0x00a5d698(param_3,uVar33 & 0xffffffff);
    uVar20 = uVar6;
    if (*(long *)(&UNK_00338908 + param_1) != *plVar35) {
      lVar28 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);
      *(bool *)(lVar28 + 0x28) = iVar11 != 0;
      *(undefined4 *)(lVar28 + 0x2c) = 2;
      goto LAB_006dcc44;
    }
  }
  lVar24 = *(long *)(uVar20 + 0x28);
LAB_006dd298:
  if (lVar24 == lStack_80) {
    uVar21 = func_0x005c8c40(plVar35);
    func_0x005c3ee4(&piStack_88);
    if (*(long *)(uVar20 + 0x28) == lStack_80) {
                    /* WARNING: Subroutine does not return */
      NoRet_0x00abf40c(uVar21);
    }
  }
  goto LAB_006dd2fc;
}


