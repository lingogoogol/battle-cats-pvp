// ELF VMA: 0x4bf8e8
// Ghidra Addr: 0x005bf8e8 (ImageBase=0x100000)
// Size: 688 bytes


void BattleFn_0x004bf8e8(long param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (uint *)(&UNK_00326fd0 + param_1);  /* field_off=0x326fd0 */
  if ((&UNK_00326fec)[param_1] == '\0') {  /* field_off=0x326fec */
    *(undefined4 *)(&UNK_00326fe4 + param_1) = 0;  /* field_off=0x326fe4 */
    goto LAB_005bfa9c;
  }
  iVar3 = *(int *)(&UNK_00326fe4 + param_1) + *(int *)(&UNK_0032666c + param_1);  /* field_off=0x326fe4 ; field_off=0x32666c */
  *(int *)(&UNK_00326fe4 + param_1) = iVar3;  /* field_off=0x326fe4 */
  if (param_2 != 1) {
    if (param_2 != 0) goto LAB_005bfa9c;
    if (iVar3 < 1) {
      uVar2 = *puVar1;
      *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
      *(undefined8 *)(&UNK_00326fd4 + param_1) = 0;  /* field_off=0x326fd4 */
      *(undefined4 *)(&UNK_00326fe4 + param_1) = 0;  /* field_off=0x326fe4 */
      if (uVar2 < 2) {
LAB_005bf990:
        *puVar1 = uVar2;
      }
LAB_005bf994:
      (&UNK_00326fec)[param_1] = 0;  /* field_off=0x326fec */
    }
    else {
      if (iVar3 < 3) {
        if (iVar3 != 1) {
          if (iVar3 == 2) goto LAB_005bf9d0;
LAB_005bfa48:
          *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
          *(undefined8 *)(&UNK_00326fd4 + param_1) = 0;  /* field_off=0x326fd4 */
          *(undefined4 *)(&UNK_00326fe4 + param_1) = 0;  /* field_off=0x326fe4 */
          if (*puVar1 == 0) {
            uVar2 = 1;
          }
          else {
            if (*puVar1 != 1) goto LAB_005bf994;
            uVar2 = 0;
          }
          goto LAB_005bf990;
        }
      }
      else {
        if (iVar3 == 3) {
          *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
          *(undefined8 *)(&UNK_00326fd4 + param_1) = 0x50ffffffb0;  /* field_off=0x326fd4 */
          goto LAB_005bfa9c;
        }
        if (iVar3 == 4) {
LAB_005bf9d0:
          *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
          *(undefined8 *)(&UNK_00326fd4 + param_1) = 0x28ffffffd8;  /* field_off=0x326fd4 */
          goto LAB_005bfa9c;
        }
        if (iVar3 != 5) goto LAB_005bfa48;
      }
      *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
      *(undefined8 *)(&UNK_00326fd4 + param_1) = 0x14ffffffec;  /* field_off=0x326fd4 */
    }
    goto LAB_005bfa9c;
  }
  if (iVar3 < 1) {
    (&UNK_00326fec)[param_1] = 0;  /* field_off=0x326fec */
    *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
    *(undefined8 *)(&UNK_00326fd4 + param_1) = 0;  /* field_off=0x326fd4 */
    *(undefined4 *)(&UNK_00326fe4 + param_1) = 0;  /* field_off=0x326fe4 */
    if (*puVar1 == 1) {
      *puVar1 = 1;
      goto LAB_005bfa9c;
    }
    if (*puVar1 != 0) goto LAB_005bfa9c;
LAB_005bfa98:
    *puVar1 = 0;
  }
  else {
    if (iVar3 < 3) {
      if (iVar3 != 1) {
        if (iVar3 == 2) goto LAB_005bf9f0;
LAB_005bfa6c:
        (&UNK_00326fec)[param_1] = 0;  /* field_off=0x326fec */
        *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
        *(undefined8 *)(&UNK_00326fd4 + param_1) = 0;  /* field_off=0x326fd4 */
        *(undefined4 *)(&UNK_00326fe4 + param_1) = 0;  /* field_off=0x326fe4 */
        if (*puVar1 != 1) {
          if (*puVar1 == 0) {
            *puVar1 = 1;
          }
          goto LAB_005bfa9c;
        }
        goto LAB_005bfa98;
      }
    }
    else {
      if (iVar3 == 3) {
        *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
        *(undefined8 *)(&UNK_00326fd4 + param_1) = 0xffffffb000000050;  /* field_off=0x326fd4 */
        goto LAB_005bfa9c;
      }
      if (iVar3 == 4) {
LAB_005bf9f0:
        *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
        *(undefined8 *)(&UNK_00326fd4 + param_1) = 0xffffffd800000028;  /* field_off=0x326fd4 */
        goto LAB_005bfa9c;
      }
      if (iVar3 != 5) goto LAB_005bfa6c;
    }
    *(undefined8 *)(&UNK_00326fdc + param_1) = 0;  /* field_off=0x326fdc */
    *(undefined8 *)(&UNK_00326fd4 + param_1) = 0xffffffec00000014;  /* field_off=0x326fd4 */
  }
LAB_005bfa9c:
  uVar2 = *(uint *)(param_1 + 0x27c8);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27c8) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27cc);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27cc) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27d0);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27d0) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27d4);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27d4) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27d8);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27d8) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27dc);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27dc) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27e0);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27e0) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27e4);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27e4) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27e8);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27e8) = iVar3;
  }
  uVar2 = *(uint *)(param_1 + 0x27ec);
  if (-1 < (int)uVar2) {
    iVar3 = -1;
    if (uVar2 < 9) {
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x27ec) = iVar3;
  }
  return;
}


