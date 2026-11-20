// ELF VMA: 0x9645a8
// Ghidra Addr: 0x00a645a8 (ImageBase=0x100000)
// Size: 1804 bytes


ulong BattleFn_0x009645a8(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,
                         uint param_7,uint param_8)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar11;
  long lVar12;
  uint uVar13;
  undefined *puVar10;
  
  lVar6 = func_0x007fd748();
  uVar7 = func_0x005b1be4(lVar6 + (long)param_1 * 0x1f0 + 0x2648);
  if ((uVar7 & 1) != 0) {
    if ((int)param_4 < 1) {
      uVar7 = 0;
    }
    else {
      lVar6 = func_0x007fd748();
      lVar6 = (long)*(int *)(lVar6 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 +
                             (long)*(int *)(&UNK_002ea9cc + (long)param_6 * 4) * 4 + 0x9e578) * 100;  /* UNK_2ea9cc(vma=0x1ea9cc)='u32=0x3(3) f32=4.204e-45' */
      if (param_4 != 1) {
        uVar13 = 1;
        do {
          func_0x007fd748();
          if (uVar13 < 200) {
            lVar8 = func_0x007fd748();
            iVar4 = *(int *)(lVar8 + ((long)param_2 + 2) * 0x760 + (long)param_3 * 0x1d8 +
                             (long)*(int *)(&UNK_002ea9cc + (long)param_6 * 4) * 4 + 0x9e578);  /* UNK_2ea9cc(vma=0x1ea9cc)='u32=0x3(3) f32=4.204e-45' */
            lVar8 = func_0x007fd748();
            lVar6 = lVar6 + (long)*(int *)(&UNK_00447634 +  /* field_off=0x447634 */
                                          lVar8 + (long)param_2 * 0x50 +
                                          (ulong)((uVar13 & 0xff) / 10) * 4) * (long)iVar4;
          }
          uVar13 = uVar13 + 1;
        } while (param_4 != uVar13);
      }
      uVar7 = (lVar6 + 0x32) / 100;
    }
    if ((param_7 & 1) != 0) goto LAB_00a64c90;
    lVar6 = func_0x007fd748();
    iVar4 = func_0x00a1f9dc(&UNK_00290568 + lVar6,10);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
    lVar6 = func_0x007fd748();
    iVar5 = func_0x008700d4(lVar6 + 0x4407e8,0,param_2);
    uVar7 = (long)(((long)(uVar7 * (long)iVar4) / 100 + uVar7) * (long)(iVar5 + 100)) / 100;
    iVar4 = func_0x00a63984(param_1,param_2,param_3,0x1f,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
    if (1 < param_3) {
      iVar5 = func_0x007abd78(0);
      if (iVar5 == 0) {
LAB_00a6481c:
        uVar11 = 9;
      }
      else {
        func_0x007fd748();
        uVar9 = func_0x00769620();
        if ((uVar9 & 1) != 0) goto LAB_00a6481c;
        iVar5 = func_0x007abd78(0);
        if (iVar5 != -9) {
          func_0x007fd748();
          uVar9 = func_0x007696a4();
          if ((uVar9 & 1) == 0) {
            func_0x007fd748();
            uVar9 = func_0x0079b9f4();
            if ((uVar9 & 1) == 0) goto LAB_00a64c6c;
          }
        }
        uVar11 = 0x10;
      }
      lVar6 = func_0x007fd748();
      iVar5 = func_0x006535d4(lVar6 + 0x1538,param_2,uVar11,1,0);
      iVar4 = iVar5 + iVar4;
    }
LAB_00a64c6c:
    if (0 < iVar4) {
      uVar7 = (long)(uVar7 * (iVar4 + 100)) / 100;
    }
    goto LAB_00a64c90;
  }
  lVar6 = func_0x007fd748();
  if ((*(int *)(&UNK_00327f0c + lVar6) < 3) &&  /* field_off=0x327f0c */
     (lVar6 = func_0x007fd748(), (&UNK_0032c658)[lVar6] == '\0')) {  /* field_off=0x32c658 */
    lVar8 = func_0x007fd748();
    lVar6 = (long)param_2 + 2;
    iVar4 = *(int *)((long)__DT_JMPREL +
                    lVar8 + lVar6 * 0x1c4 + (long)*(int *)(&UNK_002ea9d8 + (long)param_6 * 4) * 4 +  /* UNK_2ea9d8(vma=0x1ea9d8)='u32=0x3(3) f32=4.204e-45' */
                    0x7178);
    lVar8 = func_0x007fd748();
    lVar8 = ((long)*(int *)(&DAT_00c0b464 + (long)*(int *)(&UNK_00327f0c + lVar8) * 4) + 10) *  /* field_off=0x327f0c */
            (long)iVar4 + 5;
    lVar12 = SUB168(SEXT816(lVar8) * SEXT816(0x6666666666666667),8);  /* ascii(0x6666666666666667)='gfffffff' */
    lVar8 = lVar8 / 10 + (lVar8 >> 0x3f);
LAB_00a64960:
    uVar7 = lVar8 - (lVar12 >> 0x3f);
  }
  else {
    lVar6 = func_0x007fd748();
    iVar4 = *(int *)(&UNK_00327f0c + lVar6);  /* field_off=0x327f0c */
    lVar8 = func_0x007fd748();
    lVar6 = (long)param_2 + 2;
    iVar5 = *(int *)((long)__DT_JMPREL +
                    lVar8 + lVar6 * 0x1c4 + (long)*(int *)(&UNK_002ea9d8 + (long)param_6 * 4) * 4 +  /* UNK_2ea9d8(vma=0x1ea9d8)='u32=0x3(3) f32=4.204e-45' */
                    0x7178);
    lVar8 = func_0x007fd748();
    iVar1 = func_0x009cbd00(*(long *)(lVar8 + 0x9e560) + (long)param_5 * 0x38);
    uVar7 = ((long)iVar5 * (long)iVar1 + 0x32) / 100;
    if (iVar4 == 3) {
      if ((param_8 & 1) == 0) {
        lVar8 = func_0x007fd748();
        uVar2 = func_0x007ac230(0);
        uVar3 = func_0x007ac5b8();
        iVar4 = func_0x007ab460(&UNK_0032b898 + lVar8,uVar2,uVar3);  /* field_off=0x32b898 */
        lVar8 = (long)iVar4;
      }
      else {
        lVar8 = 100;
      }
      lVar8 = lVar8 * uVar7;
      lVar12 = SUB168(SEXT816(lVar8) * ZEXT816(0xa3d70a3d70a3d70b),8);
      lVar8 = lVar8 / 100 + (lVar8 >> 0x3f);
      goto LAB_00a64960;
    }
  }
  lVar8 = func_0x007fd748();
  uVar9 = func_0x005b1be4(lVar8 + 0x2838);
  lVar8 = func_0x007fd748();
  if ((uVar9 & 1) == 0) {
    if (*(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x71c0) == 0) goto LAB_00a64a14;
LAB_00a649b4:
    lVar8 = func_0x007fd748();
    uVar9 = func_0x005b1be4(lVar8 + 0x2838);
    if (((uVar9 & 1) == 0) &&
       (lVar8 = func_0x007fd748(), *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) != 0
       )) goto LAB_00a64a14;
    lVar6 = func_0x007fd748();
    iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x10);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
    lVar6 = func_0x007fd748();
    puVar10 = &UNK_00290568 + lVar6;  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
    uVar11 = 0x10;
  }
  else {
    if (*(int *)(lVar8 + lVar6 * 0x760 + 0x9e5cc) != 0) goto LAB_00a649b4;
    func_0x007fd748();
LAB_00a64a14:
    lVar8 = func_0x007fd748();
    uVar9 = func_0x005b1be4(lVar8 + 0x2838);
    lVar8 = func_0x007fd748();
    if ((uVar9 & 1) == 0) {
      if (*(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x71c0) != 0) {
LAB_00a64a64:
        lVar8 = func_0x007fd748();
        uVar9 = func_0x005b1be4(lVar8 + 0x2838);
        if (((uVar9 & 1) == 0) &&
           (lVar8 = func_0x007fd748(),
           *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 1)) {
          lVar6 = func_0x007fd748();
          iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x12);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
          lVar6 = func_0x007fd748();
          puVar10 = &UNK_00290568 + lVar6;  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
          uVar11 = 0x12;
          goto LAB_00a64be4;
        }
      }
    }
    else {
      if (*(int *)(lVar8 + lVar6 * 0x760 + 0x9e5cc) != 0) goto LAB_00a64a64;
      func_0x007fd748();
    }
    lVar8 = func_0x007fd748();
    uVar9 = func_0x005b1be4(lVar8 + 0x2838);
    if (((uVar9 & 1) == 0) &&
       (lVar8 = func_0x007fd748(), *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 2
       )) {
      lVar6 = func_0x007fd748();
      iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x16);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
      lVar6 = func_0x007fd748();
      puVar10 = &UNK_00290568 + lVar6;  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
      uVar11 = 0x16;
    }
    else {
      lVar8 = func_0x007fd748();
      uVar9 = func_0x005b1be4(lVar8 + 0x2838);
      if (((uVar9 & 1) == 0) &&
         (lVar8 = func_0x007fd748(),
         *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) == 3)) {
        lVar6 = func_0x007fd748();
        iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x17);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        lVar6 = func_0x007fd748();
        puVar10 = &UNK_00290568 + lVar6;  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        uVar11 = 0x17;
      }
      else {
        lVar8 = func_0x007fd748();
        uVar9 = func_0x005b1be4(lVar8 + 0x2838);
        if (((uVar9 & 1) != 0) ||
           (lVar8 = func_0x007fd748(),
           *(int *)((long)__DT_JMPREL + lVar8 + lVar6 * 0x1c4 + 0x728c) != 4)) goto LAB_00a64c90;
        lVar6 = func_0x007fd748();
        iVar4 = func_0x00a1fc48(&UNK_00290568 + lVar6,0x18);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        lVar6 = func_0x007fd748();
        puVar10 = &UNK_00290568 + lVar6;  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        uVar11 = 0x18;
      }
    }
  }
LAB_00a64be4:
  iVar5 = func_0x00a1f9dc(puVar10,uVar11);
  uVar7 = (long)(uVar7 * (long)(iVar4 - iVar5)) / 100 + uVar7;
LAB_00a64c90:
  return uVar7 & 0xffffffff;
}


