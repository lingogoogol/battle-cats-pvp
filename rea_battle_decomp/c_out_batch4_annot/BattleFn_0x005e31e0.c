// ELF VMA: 0x5e31e0
// Ghidra Addr: 0x006e31e0 (ImageBase=0x100000)
// Size: 1728 bytes


ulong BattleFn_0x005e31e0(int param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  byte *pbVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  
  lVar3 = func_0x007fd748();
  lVar9 = (long)param_1;
  iVar1 = *(int *)(&UNK_0038aa6c + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa6c */
  while (iVar1 != -1) {
    lVar3 = func_0x007fd748();
    param_1 = *(int *)(&UNK_0038aa6c + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa6c */
    lVar3 = func_0x007fd748();
    lVar9 = (long)param_1;
    iVar1 = *(int *)(&UNK_0038aa6c + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa6c */
  }
  lVar3 = func_0x007fd748();
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 4) {
    uVar2 = *(uint *)(&UNK_0038aa68 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa68 */
    if (-1 < (int)uVar2) {
      lVar9 = func_0x007fd748();
      if ((int)uVar2 <
          (int)((ulong)(*(long *)(&UNK_00402210 + lVar9) - *(long *)(&UNK_00402208 + lVar9)) >> 3))  /* field_off=0x402210 ; field_off=0x402208 */
      {
        lVar9 = func_0x007fd748();
        uVar6 = (ulong)*(uint *)(*(long *)(&UNK_00402208 + lVar9) + (ulong)uVar2 * 8 + 4);  /* field_off=0x402208 */
      }
      else {
        uVar6 = 0;
      }
      return uVar6;
    }
    return 0;
  }
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 5) {
    lVar4 = func_0x007fd748();
    pbVar5 = (byte *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 + 0x4403a4);  /* field_off=0x38aa68 */
LAB_006e334c:
    return (ulong)((uint)(pbVar5[5] ^ pbVar5[2]) << 0x10 | (uint)(pbVar5[4] ^ pbVar5[3]) << 0x18 |
                   (uint)(pbVar5[6] ^ pbVar5[1]) << 8 | (uint)(pbVar5[7] ^ *pbVar5));
  }
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 6) {
    lVar4 = func_0x007fd748();
    pbVar5 = (byte *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 + 0x4403d4);  /* field_off=0x38aa68 */
    goto LAB_006e334c;
  }
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 7) {
    lVar4 = func_0x007fd748();
    pbVar5 = (byte *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 + 0x4403ec);  /* field_off=0x38aa68 */
    goto LAB_006e334c;
  }
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 3) {
    lVar4 = func_0x007fd748();
    pbVar5 = (byte *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 + 0x4a470);  /* field_off=0x38aa68 */
    goto LAB_006e33dc;
  }
  iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
  lVar3 = func_0x007fd748();
  if (iVar1 == 8) {
    lVar4 = func_0x007fd748();
    pbVar5 = (byte *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 + 0x3488);  /* field_off=0x38aa68 */
    goto LAB_006e3490;
  }
  if (param_1 < 0x14) {
    if (param_1 == 6) {
      lVar9 = 0xc2d8;
    }
    else if (param_1 == 7) {
      lVar9 = 0xc2e0;
    }
    else {
LAB_006e34a0:
      iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
      lVar3 = func_0x007fd748();
      if (iVar1 == 1) {
        lVar4 = func_0x007fd748();
        return (ulong)*(uint *)(&UNK_0032cd04 +  /* field_off=0x32cd04 */
                               lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 4);  /* field_off=0x38aa68 */
      }
      if (param_1 < 0x7b) {
        if (param_1 == 0x1d) {
          lVar9 = 0x2628;
        }
        else {
          if (param_1 == 0x5c) {
            pbVar5 = &UNK_00427ae8 + lVar3;  /* field_off=0x427ae8 */
LAB_006e33dc:
            return (ulong)((uint)(pbVar5[5] ^ pbVar5[2]) << 0x10 |
                           (uint)(pbVar5[4] ^ pbVar5[3]) << 0x18 |
                           (uint)(pbVar5[6] ^ pbVar5[1]) << 8 | (uint)(pbVar5[7] ^ *pbVar5));
          }
          if (param_1 == 0x69) {
            return (long)*(short *)(lVar3 + 0x1ec2);
          }
LAB_006e3544:
          iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
          lVar3 = func_0x007fd748();
          if (iVar1 == 9) {
            lVar4 = func_0x007fd748();
            return (long)*(char *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) *  /* field_off=0x38aa68 */
                                           0x18 + 0x13e2);
          }
          iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
          lVar3 = func_0x007fd748();
          if (iVar1 == 10) {
            lVar4 = func_0x007fd748();
            if (1 < *(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40)) goto LAB_006e3724;  /* field_off=0x38aa68 */
            pbVar5 = (byte *)(lVar3 + (ulong)*(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 +  /* field_off=0x38aa68 */
                             0x3640);
            goto LAB_006e3490;
          }
          iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
          lVar3 = func_0x007fd748();
          if (iVar1 == 0xb) {
            lVar4 = func_0x007fd748();
            if (*(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) < 4) {  /* field_off=0x38aa68 */
              return (ulong)*(uint *)(lVar3 + (ulong)*(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40)  /* field_off=0x38aa68 */
                                              * 4 + 0x1084);
            }
LAB_006e3724:
                    /* WARNING: Subroutine does not return */
            NoRet_0x00311610(&UNK_0029c2ff);  /* UNK_29c2ff(vma=0x19c2ff)='array::at' */
          }
          iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
          lVar3 = func_0x007fd748();
          if (iVar1 == 0xc) {
            lVar4 = func_0x007fd748();
            if (*(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) < 0x2a) {  /* field_off=0x38aa68 */
              pbVar5 = (byte *)(lVar3 + (ulong)*(uint *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) * 8 +  /* field_off=0x38aa68 */
                               0x3650);
              goto LAB_006e3490;
            }
            goto LAB_006e3724;
          }
          if (param_1 == 0xf7) {
            return (ulong)*(uint *)(lVar3 + 0x6c8);
          }
          if (param_1 != 0xd4) {
            if (param_1 == 0xcf) {
              return (ulong)*(uint *)(lVar3 + 0x450);
            }
            iVar1 = *(int *)(&UNK_0038aa64 + lVar3 + lVar9 * 0x40);  /* field_off=0x38aa64 */
            lVar3 = func_0x007fd748();
            if (iVar1 == 0xd) {
              lVar4 = func_0x007fd748();
              return (ulong)*(uint *)(lVar3 + (long)*(int *)(&UNK_0038aa68 + lVar4 + lVar9 * 0x40) *  /* field_off=0x38aa68 */
                                              4 + 0x188);
            }
            uVar6 = func_0x009d18e0(*(undefined8 *)(lVar3 + 0x7c0),param_1);
            if ((uVar6 & 1) == 0) {
              return 0;
            }
            lVar9 = func_0x007fd748();
            plVar7 = *(long **)(*(long *)(lVar9 + 0x7c0) + 8);
            plVar8 = plVar7;
            do {
              if (plVar8 == (long *)0x0) {
                return 0;
              }
              if ((int)plVar8[4] <= param_1) {
                if (param_1 <= (int)plVar8[4]) {
                  do {
                    if (param_1 < (int)plVar7[4]) {
                      plVar7 = (long *)*plVar7;
                    }
                    else {
                      if (param_1 <= (int)plVar7[4]) {
                        return (ulong)*(uint *)plVar7[5];
                      }
                      plVar7 = (long *)plVar7[1];
                    }
                  } while (plVar7 != (long *)0x0);
                    /* WARNING: Subroutine does not return */
                  NoRet_0x00311610(&UNK_00289c18);  /* UNK_289c18(vma=0x189c18)='map::at:  key not found' */
                }
                plVar8 = plVar8 + 1;
              }
              plVar8 = (long *)*plVar8;
            } while( true );
          }
          lVar9 = 0x2640;
        }
      }
      else {
        if (param_1 == 0x7b) {
          return (long)*(char *)(lVar3 + 0x1cc5);
        }
        if (param_1 == 0x91) {
          lVar9 = 0x2630;
        }
        else {
          if (param_1 != 0x9d) goto LAB_006e3544;
          lVar9 = 0x2638;
        }
      }
    }
  }
  else {
    if (param_1 == 0x14) {
      pbVar5 = &UNK_0032ccf4 + lVar3;  /* field_off=0x32ccf4 */
      goto LAB_006e3490;
    }
    if (param_1 == 0x15) {
      pbVar5 = &UNK_0032ccfc + lVar3;  /* field_off=0x32ccfc */
      goto LAB_006e3490;
    }
    if (param_1 != 0x16) goto LAB_006e34a0;
    lVar9 = 0xc168;
  }
  pbVar5 = (byte *)(lVar3 + lVar9);
LAB_006e3490:
  return (ulong)((uint)(pbVar5[5] ^ pbVar5[2]) << 0x10 | (uint)(pbVar5[4] ^ pbVar5[3]) << 0x18 |
                 (uint)(pbVar5[6] ^ pbVar5[1]) << 8 | (uint)(pbVar5[7] ^ *pbVar5));
}


