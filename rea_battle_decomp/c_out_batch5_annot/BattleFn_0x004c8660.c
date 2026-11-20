// ELF VMA: 0x4c8660
// Ghidra Addr: 0x005c8660 (ImageBase=0x100000)
// Size: 3560 bytes


/* WARNING: Possible PIC construction at 0x005c8ae8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c8b2c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x005c8b30) */
/* WARNING: Removing unreachable block (ram,0x0044daa4) */
/* WARNING: Removing unreachable block (ram,0x0044dc3c) */
/* WARNING: Removing unreachable block (ram,0x0044dad0) */

void BattleFn_0x004c8660(long param_1,ulong param_2)

{
  long lVar1;
  byte bVar2;
  bool bVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  ulong uVar15;
  long lVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  long *plVar19;
  long unaff_x19;
  undefined *unaff_x20;
  undefined *puVar20;
  undefined *unaff_x21;
  ulong uVar21;
  undefined8 unaff_x22;
  undefined8 *puVar22;
  ulong unaff_x23;
  long *plVar23;
  undefined8 *puVar24;
  ulong unaff_x24;
  undefined8 unaff_x25;
  long unaff_x26;
  undefined8 unaff_x27;
  undefined8 unaff_x28;
  undefined1 *puVar25;
  undefined1 *unaff_x29;
  undefined8 unaff_x30;
  undefined8 uVar26;
  byte abStack_178 [280];
  
  puVar4 = &stack0xffffffffffffffa0;
  puVar25 = &stack0xffffffffffffffa0;
  puVar20 = (undefined *)(param_2 & 0xffffffff);
  iVar5 = func_0x00a57a4c(0);  /* 0x957a4c:[team*51000|off=0x83938|ldr w0, [x8, x9]] */
  if ((iVar5 == 0) && (iVar5 = func_0x00a578c8(), iVar5 == 0)) {  /* 0x9578c8:[team*51000|off=0x8392c|ldr w0, [x8, x9]] */
    *(undefined1 *)(param_1 + 0x2818) = 1;
    uVar17 = func_0x00a57c8c();  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
    if ((int)uVar17 == 0) {
      func_0x00a578fc(uVar17,1);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
      func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
      lVar16 = func_0x0044c16c();
      iVar5 = 0x19;
    }
    else {
      iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
      if (iVar5 == 1) {
        func_0x00a578fc(0,3);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
        func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
        lVar16 = func_0x0044c16c();
        iVar5 = 0x3c;
      }
      else {
        iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
        if (iVar5 == 7) {
          func_0x00a578fc(0,0xc);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
          func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
          lVar16 = func_0x0044c16c();
          iVar5 = 0x7c;
        }
        else {
          iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
          if (iVar5 == 2) {
            uVar11 = func_0x005ab37c(0,10);
            iVar5 = func_0x005abf04(0,10);
            uVar6 = func_0x00a92ff4(param_1 + (long)iVar5 * 8 + 0x47aac);
            iVar5 = func_0x005ab37c(0,10);
            iVar7 = func_0x005abf1c(0,10);
            lVar1 = param_1 + 0x9e578;
            uVar21 = (ulong)*(uint *)(lVar1 + (long)iVar5 * 0x760 + (long)iVar7 * 0x1d8 + 0x38);
            iVar5 = func_0x005ab37c(0,10);
            iVar7 = func_0x005abf1c(0,10);
            uVar15 = (ulong)*(uint *)(lVar1 + (long)iVar5 * 0x760 + (long)iVar7 * 0x1d8 + 0x3c);
            uVar8 = func_0x005abf1c(0,10);
            uVar9 = func_0x009b6dec(param_1,0,uVar11,uVar6,uVar21,uVar15,uVar8,0);
            if ((int)uVar9 < 0) goto LAB_005c8698;
            unaff_x21 = (undefined *)(ulong)uVar9;
            iVar5 = 0;
            iVar7 = 0xc80;
            do {
              iVar10 = func_0x00a58874(1,iVar5);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
              if ((iVar10 == 2) && (iVar10 = func_0x00a5919c(1,iVar5), iVar7 < iVar10)) {  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                iVar7 = func_0x00a5919c(1,iVar5);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 != 0x33);
            iVar5 = func_0x00a58100(0);
            func_0x00a591dc(0,unaff_x21,iVar5 + iVar7);  /* 0x9591dc:[slot*1000,team*51000|off=0x83914|str w19, [x8, x9]] */
            uVar9 = func_0x00a5a194(0,unaff_x21);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
            puVar20 = (undefined *)(ulong)uVar9;
            iVar5 = func_0x00a57dd0(0);
            func_0x00a5a1d4(0,unaff_x21,(int)(iVar5 * uVar9) / 100);  /* 0x95a1d4:[slot*1000,team*51000|off=0x83924|str w19, [x8, x9]] */
            uVar11 = func_0x00a5a194(0,unaff_x21);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
            func_0x00a5a260(0,unaff_x21,uVar11);  /* 0x95a260:[slot*1000,team*51000|off=0x83928|str w19, [x8, x9]] */
            uVar11 = func_0x00a57ea8(0);
            func_0x00a59d88(0,unaff_x21,uVar11);  /* 0x959d88:[slot*1000,team*51000|off=0x83adc|str w19, [x8, x9]] */
            func_0x00a578fc(0,6);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
            func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
            lVar16 = func_0x0044c16c();
            iVar5 = 0x3d;
            unaff_x22 = 0x33;
            unaff_x23 = uVar21;
            unaff_x24 = uVar15;
            unaff_x25 = 0x760;
            unaff_x26 = lVar1;
            unaff_x27 = 0x1d8;
          }
          else {
            puVar20 = (undefined *)0x9e538;
            iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
            if (iVar5 == 3) {
              iVar5 = 0;
              puVar20 = (undefined *)(ulong)(*(int *)(param_1 + 0x9e538) - 0xc80);
              do {
                iVar7 = func_0x00a58874(0,iVar5);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                if (((iVar7 == 2) && (iVar7 = func_0x00a5919c(0,iVar5), iVar7 < (int)puVar20)) &&  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                   (uVar21 = func_0x00a58fec(0,iVar5), (uVar21 & 1) != 0)) {
                  uVar21 = func_0x00a5919c(0,iVar5);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                  puVar20 = (undefined *)(uVar21 & 0xffffffff);
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 != 0x33);
              func_0x00a578fc(0,4);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
              func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
              iVar5 = func_0x00a57e3c(0);  /* 0x957e3c:[team*51000|off=0x8395c|ldr w0, [x8, x9]] */
              if (iVar5 < 0) {
                iVar5 = iVar5 + 1;
              }
              func_0x00a57d2c(0,(int)puVar20 - (iVar5 >> 1));
              lVar16 = func_0x0044c16c();
              iVar5 = 0x25;
              unaff_x21 = (undefined *)0x33;
            }
            else {
              iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
              if (iVar5 == 4) {
                iVar5 = 0;
                puVar20 = (undefined *)(ulong)(*(int *)(param_1 + 0x9e538) - 0xc80);
                do {
                  iVar7 = func_0x00a58874(0,iVar5);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                  if (((iVar7 == 2) && (iVar7 = func_0x00a5919c(0,iVar5), iVar7 < (int)puVar20)) &&  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                     (uVar21 = func_0x00a58fec(0,iVar5), (uVar21 & 1) != 0)) {
                    uVar21 = func_0x00a5919c(0,iVar5);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                    puVar20 = (undefined *)(uVar21 & 0xffffffff);
                  }
                  iVar5 = iVar5 + 1;
                } while (iVar5 != 0x33);
                func_0x00a578fc(0,7);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
                func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
                iVar5 = func_0x00a57e3c(0);  /* 0x957e3c:[team*51000|off=0x8395c|ldr w0, [x8, x9]] */
                if (iVar5 < 0) {
                  iVar5 = iVar5 + 1;
                }
                func_0x00a57d2c(0,(int)puVar20 - (iVar5 >> 1));
                lVar16 = func_0x0044c16c();
                iVar5 = 0x41;
                unaff_x21 = (undefined *)0x33;
              }
              else {
                iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
                if (iVar5 != 5) {
                  iVar5 = func_0x00a57c8c(0);  /* 0x957c8c:[team*51000|off=0x8394c|ldr w0, [x8, x9]] */
                  if (iVar5 == 6) {
                    iVar5 = 0;
                    iVar7 = 0xc80;
                    do {
                      iVar10 = func_0x00a58874(1,iVar5);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
                      if ((iVar10 == 2) && (iVar10 = func_0x00a5919c(1,iVar5), iVar7 < iVar10)) {  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                        iVar7 = func_0x00a5919c(1,iVar5);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
                      }
                      iVar5 = iVar5 + 1;
                    } while (iVar5 != 0x33);
                    func_0x00a578fc(0,0xb);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
                    func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
                    func_0x00a57d2c(0,iVar7);
                  }
                  puVar20 = &UNK_003bb790;  /* field_off=0x3bb790 */
                  unaff_x21 = &UNK_0032660c + param_1;  /* field_off=0x32660c */
                  uVar11 = func_0x00a579e0(0);  /* 0x9579e0:[team*51000|off=0x83934|ldr w0, [x8, x9]] */
                  func_0x00a57a80(0,uVar11);
                  unaff_x22 = 1;
                  func_0x00a57b24(0,1);
                  lVar16 = func_0x0044c16c();
                  iVar5 = 0x13;
                  unaff_x30 = 0x5c8b30;
                  goto SUB_0044e35c;
                }
                func_0x00a578fc(0,9);  /* 0x9578fc:[team*51000|off=0x8392c|str w19, [x8, x9]] */
                func_0x00a57968(0,0);  /* 0x957968:[team*51000|off=0x83930|str w19, [x8, x9]] */
                lVar16 = func_0x0044c16c();
                iVar5 = 0x54;
              }
            }
          }
        }
      }
    }
    unaff_x30 = 0x5c8aec;
    puVar4 = &stack0xffffffffffffffa0;
    puVar25 = &stack0xffffffffffffffa0;
  }
  else {
LAB_005c8698:
    if ((param_2 & 1) == 0) {
      return;
    }
    lVar16 = func_0x0044c16c();
    iVar5 = 0xf;
    puVar4 = (undefined1 *)register0x00000008;
    param_1 = unaff_x19;
    puVar20 = unaff_x20;
    puVar25 = unaff_x29;
  }
SUB_0044e35c:
  *(undefined1 **)(puVar4 + -0x60) = puVar25;
  *(undefined8 *)(puVar4 + -0x58) = unaff_x30;
  *(undefined8 *)(puVar4 + -0x50) = unaff_x28;
  *(undefined8 *)(puVar4 + -0x48) = unaff_x27;
  *(long *)(puVar4 + -0x40) = unaff_x26;
  *(undefined8 *)(puVar4 + -0x38) = unaff_x25;
  *(ulong *)(puVar4 + -0x30) = unaff_x24;
  *(ulong *)(puVar4 + -0x28) = unaff_x23;
  *(undefined8 *)(puVar4 + -0x20) = unaff_x22;
  *(undefined **)(puVar4 + -0x18) = unaff_x21;
  *(undefined **)(puVar4 + -0x10) = puVar20;
  *(long *)(puVar4 + -8) = param_1;
  lVar1 = tpidr_el0;
  *(undefined8 *)(puVar4 + -0x68) = *(undefined8 *)(lVar1 + 0x28);
  if ((ulong)(*(long *)(lVar16 + 0x10) - *(long *)(lVar16 + 8) >> 2) <= (ulong)(long)iVar5) {
    *(undefined2 *)(puVar4 + -0x80) = 0;
    func_0x0056a6f0(puVar4 + -0x80,3);
    if ((puVar4[-0x80] & 1) != 0) {
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0x70));
    }
    goto LAB_0044dd88;
  }
  if (iVar5 == 0x1d) {
    lVar12 = func_0x007fd748();
    if (*(int *)(&LAB_00440e50 + lVar12) != -1) {
      lVar12 = func_0x007fd748();
      lVar13 = func_0x007fd748();
      plVar19 = *(long **)(lVar12 + 0x2618);
      if (plVar19 != (long *)0x0) {
        do {
          if ((int)plVar19[4] <= *(int *)(&LAB_00440e50 + lVar13)) {
            if (*(int *)(&LAB_00440e50 + lVar13) <= (int)plVar19[4]) {
              lVar12 = func_0x007fd748();
              lVar13 = func_0x007fd748();
              iVar5 = *(int *)(&LAB_00440e50 + lVar13);
              puVar18 = *(undefined8 **)(lVar12 + 0x2618);
              if (*(undefined8 **)(lVar12 + 0x2618) != (undefined8 *)0x0) goto LAB_0044d6d8;
              puVar22 = (undefined8 *)(lVar12 + 0x2618);
              puVar24 = (undefined8 *)(lVar12 + 0x2618);
              goto LAB_0044d6fc;
            }
            plVar19 = plVar19 + 1;
          }
          plVar19 = (long *)*plVar19;
        } while (plVar19 != (long *)0x0);
      }
    }
    goto LAB_0044d7dc;
  }
  goto LAB_0044d7e0;
  while( true ) {
    if (iVar5 <= *(int *)(puVar14 + 4)) goto LAB_0044d7a0;
    puVar18 = (undefined8 *)puVar14[1];
    if ((undefined8 *)puVar14[1] == (undefined8 *)0x0) break;
LAB_0044d6d8:
    puVar14 = puVar18;
    puVar22 = puVar14;
    if (iVar5 < *(int *)(puVar14 + 4)) {
      puVar18 = (undefined8 *)*puVar14;
      puVar24 = puVar14;
      if ((undefined8 *)*puVar14 == (undefined8 *)0x0) goto LAB_0044d6fc;
      goto LAB_0044d6d8;
    }
  }
  puVar24 = puVar14 + 1;
LAB_0044d6fc:
  puVar14 = (undefined8 *)func_0x00bc3330(0x160);
  puVar14[0x2b] = 0;
  *(int *)(puVar14 + 4) = iVar5;
  *puVar14 = 0;
  puVar14[1] = 0;
  puVar14[2] = puVar22;
  puVar14[0x22] = 0;
  puVar14[0x21] = 0;
  puVar14[0x24] = 0;
  puVar14[0x23] = 0;
  puVar14[8] = 0;
  puVar14[7] = 0;
  puVar14[10] = 0;
  puVar14[9] = 0;
  puVar14[0xc] = 0;
  puVar14[0xb] = 0;
  puVar14[0xe] = 0;
  puVar14[0xd] = 0;
  puVar14[0x10] = 0;
  puVar14[0xf] = 0;
  puVar14[0x12] = 0;
  puVar14[0x11] = 0;
  puVar14[0x14] = 0;
  puVar14[0x13] = 0;
  puVar14[0x16] = 0;
  puVar14[0x15] = 0;
  puVar14[0x18] = 0;
  puVar14[0x17] = 0;
  puVar14[0x1a] = 0;
  puVar14[0x19] = 0;
  puVar14[0x1c] = 0;
  puVar14[0x1b] = 0;
  puVar14[0x1e] = 0;
  puVar14[0x1d] = 0;
  puVar14[0x20] = 0;
  puVar14[0x1f] = 0;
  puVar14[6] = 0;
  puVar14[5] = 0;
  puVar14[0x26] = 0;
  puVar14[0x25] = 0;
  puVar14[0x28] = 0;
  puVar14[0x27] = 0;
  puVar14[0x2a] = 0;
  puVar14[0x29] = 0;
  *puVar24 = puVar14;
  puVar18 = puVar14;
  if (**(long **)(lVar12 + 0x2610) != 0) {
    *(long *)(lVar12 + 0x2610) = **(long **)(lVar12 + 0x2610);
    puVar18 = (undefined8 *)*puVar24;
  }
  func_0x0040a8c0(*(undefined8 *)(lVar12 + 0x2618),puVar18);
  *(long *)(lVar12 + 0x2620) = *(long *)(lVar12 + 0x2620) + 1;
LAB_0044d7a0:
  if (*(int *)(puVar14 + 0x2a) == -1) {
LAB_0044d7dc:
    iVar5 = 0x1d;
  }
  else {
    lVar12 = func_0x007fd748();
    lVar13 = func_0x007fd748();
    iVar5 = *(int *)(&LAB_00440e50 + lVar13);
    puVar18 = *(undefined8 **)(lVar12 + 0x2618);
    if (*(undefined8 **)(lVar12 + 0x2618) == (undefined8 *)0x0) {
      puVar22 = (undefined8 *)(lVar12 + 0x2618);
      puVar24 = (undefined8 *)(lVar12 + 0x2618);
    }
    else {
      do {
        while (puVar14 = puVar18, puVar22 = puVar14, iVar5 < *(int *)(puVar14 + 4)) {
          puVar18 = (undefined8 *)*puVar14;
          puVar24 = puVar14;
          if ((undefined8 *)*puVar14 == (undefined8 *)0x0) goto LAB_0044db24;
        }
        if (iVar5 <= *(int *)(puVar14 + 4)) goto LAB_0044dbc8;
        puVar18 = (undefined8 *)puVar14[1];
      } while ((undefined8 *)puVar14[1] != (undefined8 *)0x0);
      puVar24 = puVar14 + 1;
    }
LAB_0044db24:
    puVar14 = (undefined8 *)func_0x00bc3330(0x160);
    puVar14[0x2b] = 0;
    *(int *)(puVar14 + 4) = iVar5;
    *puVar14 = 0;
    puVar14[1] = 0;
    puVar14[2] = puVar22;
    puVar14[0x22] = 0;
    puVar14[0x21] = 0;
    puVar14[0x24] = 0;
    puVar14[0x23] = 0;
    puVar14[8] = 0;
    puVar14[7] = 0;
    puVar14[10] = 0;
    puVar14[9] = 0;
    puVar14[0xc] = 0;
    puVar14[0xb] = 0;
    puVar14[0xe] = 0;
    puVar14[0xd] = 0;
    puVar14[0x10] = 0;
    puVar14[0xf] = 0;
    puVar14[0x12] = 0;
    puVar14[0x11] = 0;
    puVar14[0x14] = 0;
    puVar14[0x13] = 0;
    puVar14[0x16] = 0;
    puVar14[0x15] = 0;
    puVar14[0x18] = 0;
    puVar14[0x17] = 0;
    puVar14[0x1a] = 0;
    puVar14[0x19] = 0;
    puVar14[0x1c] = 0;
    puVar14[0x1b] = 0;
    puVar14[0x1e] = 0;
    puVar14[0x1d] = 0;
    puVar14[0x20] = 0;
    puVar14[0x1f] = 0;
    puVar14[6] = 0;
    puVar14[5] = 0;
    puVar14[0x26] = 0;
    puVar14[0x25] = 0;
    puVar14[0x28] = 0;
    puVar14[0x27] = 0;
    puVar14[0x2a] = 0;
    puVar14[0x29] = 0;
    *puVar24 = puVar14;
    puVar18 = puVar14;
    if (**(long **)(lVar12 + 0x2610) != 0) {
      *(long *)(lVar12 + 0x2610) = **(long **)(lVar12 + 0x2610);
      puVar18 = (undefined8 *)*puVar24;
    }
    func_0x0040a8c0(*(undefined8 *)(lVar12 + 0x2618),puVar18);
    *(long *)(lVar12 + 0x2620) = *(long *)(lVar12 + 0x2620) + 1;
LAB_0044dbc8:
    iVar5 = *(int *)(puVar14 + 0x2a);
  }
LAB_0044d7e0:
  uVar21 = (ulong)iVar5;
  uVar9 = *(uint *)(*(long *)(lVar16 + 8) + (long)iVar5 * 4);
  if (((uVar9 & 1) == 0) || (*(char *)(lVar16 + 0x80) != '\0')) {
    if (((uVar9 >> 1 & 1) != 0) && (*(char *)(lVar16 + 0x81) == '\0')) {
      lVar12 = uVar21 * 0x10;
      if (*(long *)(*(long *)(lVar16 + 0x40) + lVar12) == 0) goto LAB_0044dd88;
      *(undefined4 *)(*(long *)(lVar16 + 0xa8) + uVar21 * 4) = 100;
      plVar19 = *(long **)(*(long *)(lVar16 + 0x58) + lVar12);
      if (plVar19 == (long *)0x0) {
        uVar15 = func_0x0044d358(lVar16,*(undefined4 *)(*(long *)(lVar16 + 0x20) + uVar21 * 4));
        if ((uVar15 & 1) == 0) goto LAB_0044dd88;
        func_0x00bc3570(0xc0b818);
        func_0x00521e78(puVar4 + -0x80,*(long *)(lVar16 + 0x40) + uVar21 * 0x10,
                        *(undefined4 *)(*(long *)(lVar16 + 0x20) + uVar21 * 4));
        func_0x0044e2b0(*(long *)(lVar16 + 0x58) + lVar12,puVar4 + -0x80);
        func_0x0044e30c(puVar4 + -0x80);
        func_0x00bc3580(0xc0b818);
        lVar13 = *(long *)(lVar16 + 0x58);
        if (*(long *)(lVar13 + lVar12) == 0) goto LAB_0044dd88;
      }
      else {
        uVar15 = (**(code **)(*plVar19 + 0x70))();
        lVar13 = *(long *)(lVar16 + 0x58);
        if ((uVar15 & 1) != 0) {
          (**(code **)(**(long **)(lVar13 + lVar12) + 0x90))();
          lVar13 = *(long *)(lVar16 + 0x58);
        }
      }
      if ((*(uint *)(*(long *)(lVar16 + 8) + uVar21 * 4) >> 2 & 1) != 0) {
        (**(code **)(**(long **)(lVar13 + lVar12) + 0xb8))(*(long **)(lVar13 + lVar12),1);
        lVar13 = *(long *)(lVar16 + 0x58);
      }
      (**(code **)(**(long **)(lVar13 + lVar12) + 0xe8))
                ((float)(*(int *)(*(long *)(lVar16 + 0xa8) + uVar21 * 4) * *(int *)(lVar16 + 0xc4))
                 / 10000.0);
      (**(code **)(**(long **)(*(long *)(lVar16 + 0x58) + lVar12) + 0x90))();
    }
  }
  else {
    *(undefined8 *)(puVar4 + -0x80) = 0;
    *(undefined8 *)(puVar4 + -0x78) = 0;
    *(undefined8 *)(puVar4 + -0x70) = 0;
    func_0x005220d0(puVar4 + -0xb8);
    puVar4[-0xe8] = 0x14;
    puVar4[-0x100] = 6;
    *(undefined2 *)(puVar4 + -0xdf) = 0x7325;
    *(undefined8 *)(puVar4 + -0xe7) = 0x2e64333025646e73;  /* ascii(0x2e64333025646e73)='snd%03d.' */
    puVar4[-0xdd] = 0;
    *(undefined4 *)(puVar4 + -0xff) = 0x67676f;
    func_0x0044def0(puVar4 + -0xd0,puVar4 + -0xe8,iVar5,puVar4 + -0x100);
    func_0x0040c944(puVar4 + -0xa0,puVar4 + -0xb8,puVar4 + -0xd0);
    if ((puVar4[-0x80] & 1) != 0) {
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0x70));
    }
    uVar17 = *(undefined8 *)(puVar4 + -0xa0);
    *(undefined2 *)(puVar4 + -0xa0) = 0;
    *(undefined8 *)(puVar4 + -0x78) = *(undefined8 *)(puVar4 + -0x98);
    *(undefined8 *)(puVar4 + -0x80) = uVar17;
    *(undefined8 *)(puVar4 + -0x70) = *(undefined8 *)(puVar4 + -0x90);
    if ((puVar4[-0xd0] & 1) == 0) {
      if ((puVar4[-0x100] & 1) != 0) goto LAB_0044dbe0;
LAB_0044d89c:
      if ((puVar4[-0xe8] & 1) != 0) goto LAB_0044dbf0;
LAB_0044d8a4:
      bVar2 = puVar4[-0xb8];
    }
    else {
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0xc0));
      if ((puVar4[-0x100] & 1) == 0) goto LAB_0044d89c;
LAB_0044dbe0:
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0xf0));
      if ((puVar4[-0xe8] & 1) == 0) goto LAB_0044d8a4;
LAB_0044dbf0:
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0xd8));
      bVar2 = puVar4[-0xb8];
    }
    if ((bVar2 & 1) != 0) {
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0xa8));
    }
    uVar15 = func_0x005220cc(puVar4 + -0x80);
    if ((uVar15 & 1) == 0) {
      func_0x005220d4(puVar4 + -0xb8);
      puVar4[-0xe0] = 0;
      puVar4[-0xe8] = 0xe;
      *(undefined4 *)(puVar4 + -0xe7) = 0x64333025;  /* ascii(0x64333025)='%03d' */
      *(undefined4 *)(puVar4 + -0xe4) = 0x73252e64;  /* ascii(0x73252e64)='d.%s' */
      puVar4[-0x118] = 6;
      *(undefined4 *)(puVar4 + -0x117) = 0x67676f;
      func_0x0044def0(puVar4 + -0xd0,puVar4 + -0xe8,iVar5,puVar4 + -0x118);
      func_0x0040c944(puVar4 + -0xa0,puVar4 + -0xb8,puVar4 + -0xd0);
      if ((puVar4[-0x80] & 1) != 0) {
        func_0x00bc3350(*(undefined8 *)(puVar4 + -0x70));
      }
      uVar17 = *(undefined8 *)(puVar4 + -0xa0);
      *(undefined2 *)(puVar4 + -0xa0) = 0;
      *(undefined8 *)(puVar4 + -0x78) = *(undefined8 *)(puVar4 + -0x98);
      *(undefined8 *)(puVar4 + -0x80) = uVar17;
      *(undefined8 *)(puVar4 + -0x70) = *(undefined8 *)(puVar4 + -0x90);
      if ((puVar4[-0xd0] & 1) == 0) {
        if ((puVar4[-0x118] & 1) != 0) goto LAB_0044dc14;
LAB_0044d958:
        if ((puVar4[-0xe8] & 1) != 0) goto LAB_0044dc24;
LAB_0044d960:
        bVar2 = puVar4[-0xb8];
      }
      else {
        func_0x00bc3350(*(undefined8 *)(puVar4 + -0xc0));
        if ((puVar4[-0x118] & 1) == 0) goto LAB_0044d958;
LAB_0044dc14:
        func_0x00bc3350(*(undefined8 *)(puVar4 + -0x108));
        if ((puVar4[-0xe8] & 1) == 0) goto LAB_0044d960;
LAB_0044dc24:
        func_0x00bc3350(*(undefined8 *)(puVar4 + -0xd8));
        bVar2 = puVar4[-0xb8];
      }
      if ((bVar2 & 1) != 0) {
        func_0x00bc3350(*(undefined8 *)(puVar4 + -0xa8));
      }
    }
    if (*(long *)(lVar16 + 0x70) != 0) {
      func_0x0044e014(lVar16,0xffffffff);
    }
    uVar15 = func_0x0044d358(lVar16,*(undefined4 *)(*(long *)(lVar16 + 0x20) + uVar21 * 4));
    if ((uVar15 & 1) == 0) {
LAB_0044dad8:
      bVar3 = false;
      bVar2 = puVar4[-0x80];
    }
    else {
      func_0x00521e74(puVar4 + -0xa0,puVar4 + -0x80,1);
      lVar12 = *(long *)(lVar16 + 0x58);
      uVar26 = *(undefined8 *)(puVar4 + -0x98);
      uVar17 = *(undefined8 *)(puVar4 + -0xa0);
      *(undefined8 *)(puVar4 + -0xa0) = 0;
      *(undefined8 *)(puVar4 + -0x98) = 0;
      puVar18 = (undefined8 *)(lVar12 + uVar21 * 0x10);
      plVar19 = (long *)puVar18[1];
      puVar18[1] = uVar26;
      *puVar18 = uVar17;
      if ((plVar19 != (long *)0x0) &&
         (lVar12 = func_0x00bbf1b0(0xffffffffffffffff,plVar19 + 1), lVar12 == 0)) {
        (**(code **)(*plVar19 + 0x10))(plVar19);
        func_0x00bc3320(plVar19);
      }
      plVar19 = *(long **)(puVar4 + -0x98);
      if ((plVar19 != (long *)0x0) &&
         (lVar12 = func_0x00bbf1b0(0xffffffffffffffff,plVar19 + 1), lVar12 == 0)) {
        (**(code **)(*plVar19 + 0x10))(plVar19);
        func_0x00bc3320(plVar19);
      }
      lVar12 = *(long *)(lVar16 + 0x58);
      lVar13 = uVar21 * 0x10;
      plVar19 = *(long **)(lVar12 + lVar13);
      if (plVar19 == (long *)0x0) goto LAB_0044dad8;
      if ((*(uint *)(*(long *)(lVar16 + 8) + uVar21 * 4) >> 2 & 1) != 0) {
        (**(code **)(*plVar19 + 0xb8))(plVar19,1);
        lVar12 = *(long *)(lVar16 + 0x58);
        plVar19 = *(long **)(lVar12 + lVar13);
      }
      lVar12 = *(long *)(lVar12 + uVar21 * 0x10 + 8);
      if (lVar12 != 0) {
        func_0x00bbf180(1,lVar12 + 8);
      }
      plVar23 = *(long **)(lVar16 + 0x78);
      *(long **)(lVar16 + 0x70) = plVar19;
      *(long *)(lVar16 + 0x78) = lVar12;
      if ((plVar23 != (long *)0x0) &&
         (lVar12 = func_0x00bbf1b0(0xffffffffffffffff,plVar23 + 1), lVar12 == 0)) {
        (**(code **)(*plVar23 + 0x10))(plVar23);
        func_0x00bc3320(plVar23);
      }
      *(undefined4 *)(lVar16 + 0xa0) = 100;
      (**(code **)(**(long **)(*(long *)(lVar16 + 0x58) + lVar13) + 0xe8))
                ((float)(*(int *)(lVar16 + 0xc0) * 100) / 10000.0);
      (**(code **)(**(long **)(*(long *)(lVar16 + 0x58) + lVar13) + 0x90))();
      bVar3 = true;
      bVar2 = puVar4[-0x80];
    }
    if ((bVar2 & 1) != 0) {
      func_0x00bc3350(*(undefined8 *)(puVar4 + -0x70));
    }
    if (!bVar3) goto LAB_0044dd88;
  }
  if ((*(uint *)(*(long *)(lVar16 + 8) + uVar21 * 4) >> 2 & 1) != 0) {
    uVar15 = uVar21 >> 3 & 0x1ffffffffffffff8;
    *(ulong *)(*(long *)(lVar16 + 0x88) + uVar15) =
         *(ulong *)(*(long *)(lVar16 + 0x88) + uVar15) | 1L << (uVar21 & 0x3f);
  }
LAB_0044dd88:
  if (*(long *)(lVar1 + 0x28) != *(long *)(puVar4 + -0x68)) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return;
}


