// ELF VMA: 0x5d3c94
// Ghidra Addr: 0x006d3c94 (ImageBase=0x100000)
// Size: 2556 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BattleFn_0x005d3c94(long param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  long lVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  long lVar11;
  undefined4 uVar12;
  long lVar13;
  byte *pbVar14;
  ulong uVar15;
  undefined4 auStack_140 [2];
  undefined *puStack_138;
  undefined *puStack_128;
  undefined4 auStack_120 [2];
  undefined8 uStack_118;
  undefined *puStack_108;
  undefined4 auStack_100 [2];
  undefined8 uStack_f8;
  undefined *puStack_e8;
  undefined4 auStack_e0 [2];
  undefined8 uStack_d8;
  undefined *puStack_c8;
  undefined4 auStack_c0 [2];
  undefined8 uStack_b8;
  undefined *puStack_a8;
  undefined4 auStack_a0 [2];
  undefined8 uStack_98;
  undefined *puStack_88;
  undefined4 auStack_80 [2];
  undefined8 uStack_78;
  long lStack_68;
  
  lVar6 = tpidr_el0;
  lStack_68 = *(long *)(lVar6 + 0x28);
  uVar15 = -(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2;
  lVar13 = (long)*(int *)(param_1 + 0x83684) * 0xbc + param_1;
  pbVar14 = &UNK_00383748 + uVar15 + lVar13;  /* field_off=0x383748 */
  iVar8 = BattleFn_0x005e437c((uint)((&UNK_00383748)[lVar13 + 0xba] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 0xbb] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 0xb9] ^ pbVar14[1]) << 8 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 0xb8] ^ *pbVar14));  /* field_off=0x383748 */
  lVar13 = (long)*(int *)(param_1 + 0x83684) * 0xbc + param_1;
  pbVar14 = &UNK_00383748 + uVar15 + lVar13;  /* field_off=0x383748 */
  bVar2 = (&UNK_00383748)[lVar13 + 0xba];  /* field_off=0x383748 */
  bVar3 = (&UNK_00383748)[lVar13 + 0xbb];  /* field_off=0x383748 */
  bVar4 = (&UNK_00383748)[lVar13 + 0xb9];  /* field_off=0x383748 */
  bVar5 = (&UNK_00383748)[lVar13 + 0xb8];  /* field_off=0x383748 */
  uVar1 = (uint)(bVar2 ^ pbVar14[2]) << 0x10 | (uint)(bVar3 ^ pbVar14[3]) << 0x18 |
          (uint)(bVar4 ^ pbVar14[1]) << 8 | (uint)(bVar5 ^ *pbVar14);
  if (iVar8 == -1) {
    if (999 < (int)uVar1) {
      lVar11 = (long)(int)param_2;
      if (_DAT_00c0ebd4 < (int)uVar1) {
        if (uVar1 != 0x3ea) {
          if (1099 < uVar1) {
            if ((int)uVar1 <= _DAT_00c0ebd0) {
LAB_006d440c:
              iVar8 = func_0x006efb14();
              lVar13 = param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc;
              pbVar14 = &UNK_00383748 + uVar15 + lVar13;  /* field_off=0x383748 */
              iVar9 = func_0x006efca4((uint)((&UNK_00383802)[lVar13] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383802 */
                                      (uint)((&UNK_00383803)[lVar13] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383803 */
                                      (uint)((&UNK_00383801)[lVar13] ^ pbVar14[1]) << 8 |  /* field_off=0x383801 */
                                      (uint)((&UNK_00383800)[lVar13] ^ *pbVar14));  /* field_off=0x383800 */
              lVar13 = param_1 + (long)iVar8 * 4;
              if (*(int *)(&UNK_0038efd4 + lVar13) == 0) goto LAB_006d45d0;  /* field_off=0x38efd4 */
              lVar13 = param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc;
              pbVar14 = &UNK_00383748 + lVar13 + uVar15;  /* field_off=0x383748 */
              if (((int)((uint)((&UNK_00383802)[lVar13] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383802 */
                         (uint)((&UNK_00383803)[lVar13] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383803 */
                         (uint)((&UNK_00383801)[lVar13] ^ pbVar14[1]) << 8 |  /* field_off=0x383801 */
                        (uint)((&UNK_00383800)[lVar13] ^ *pbVar14)) < 0x44c) ||  /* field_off=0x383800 */
                 (iVar8 = func_0x005cf74c(&UNK_00383748 + lVar13,lVar11), _DAT_00c0ebd0 < iVar8)) {  /* field_off=0x383748 */
                lVar13 = param_1 + (long)iVar9 * 8;
                iVar8 = func_0x00a92e2c(lVar13 + 0x47aac);
                param_1 = param_1 + (long)iVar9 * 0x100;
                if ((int)((uint)(*(byte *)(param_1 + 0x4b016) ^ *(byte *)(param_1 + 0x4af66)) <<
                          0x10 | (uint)(*(byte *)(param_1 + 0x4b017) ^ *(byte *)(param_1 + 0x4af67))
                                 << 0x18 |
                          (uint)(*(byte *)(param_1 + 0x4b015) ^ *(byte *)(param_1 + 0x4af65)) << 8 |
                         (uint)(*(byte *)(param_1 + 0x4b014) ^ *(byte *)(param_1 + 0x4af64))) <=
                    iVar8) goto LAB_006d45f0;
                iVar8 = func_0x00a92e2c(lVar13 + 0x47aac);
                iVar9 = func_0x005cf5fc(param_1 + 0x4af18,0x13);
                bVar7 = SBORROW4(iVar8,iVar9 + -1);
                iVar8 = iVar8 - (iVar9 + -1);
                goto LAB_006d4594;
              }
              goto LAB_006d429c;
            }
            if (0x270 < uVar1 >> 4) {
              if (uVar1 >> 4 < 0x753) {
                lVar13 = 0;
                pbVar14 = (byte *)(param_1 + 0x4af74);
                do {
                  if (((uint)(pbVar14[0xa2] ^ pbVar14[2]) << 0x10 |
                       (uint)(pbVar14[0xa3] ^ pbVar14[3]) << 0x18 |
                       (uint)(pbVar14[0xa1] ^ pbVar14[1]) << 8 | (uint)(pbVar14[0xa0] ^ *pbVar14))
                      == uVar1) {
                    if (*(int *)(&UNK_003a9438 + lVar13 + param_1) != 0) goto LAB_006d429c;  /* field_off=0x3a9438 */
                    *(undefined4 *)(&UNK_003a9438 + lVar13 + param_1) = 1;  /* field_off=0x3a9438 */
                    uVar12 = 6;
                    break;
                  }
                  if (((uint)(pbVar14[6] ^ pbVar14[0xa2]) << 0x10 |
                       (uint)(pbVar14[7] ^ pbVar14[0xa3]) << 0x18 |
                       (uint)(pbVar14[5] ^ pbVar14[0xa1]) << 8 | (uint)(pbVar14[4] ^ pbVar14[0xa0]))
                      == uVar1) {
                    if (*(int *)(&UNK_003aa1e8 + param_1 + lVar13) != 0) goto LAB_006d429c;  /* field_off=0x3aa1e8 */
                    *(undefined4 *)(&UNK_003aa1e8 + param_1 + lVar13) = 1;  /* field_off=0x3aa1e8 */
                    uVar12 = 6;
                    break;
                  }
                  lVar13 = lVar13 + 4;
                  uVar12 = 0;
                  pbVar14 = pbVar14 + 0x100;
                } while (lVar13 != 0xdb0);
                goto LAB_006d4258;
              }
              lVar13 = (long)(int)param_2 * 4 + lVar13;
              func_0x00653260(param_1 + 0x1538,uVar1 - 30000,
                              (uint)((&UNK_00383748)[lVar13 + 6] ^ bVar2) << 0x10 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 7] ^ bVar3) << 0x18 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 5] ^ bVar4) << 8 |  /* field_off=0x383748 */
                              (uint)((&UNK_00383748)[lVar13 + 4] ^ bVar5));  /* field_off=0x383748 */
            }
          }
          goto LAB_006d4254;
        }
LAB_006d428c:
        if (*(int *)(&UNK_0032cc54 + param_1) == 0) {  /* field_off=0x32cc54 */
          *(undefined4 *)(&UNK_0032cc54 + param_1) = 1;  /* field_off=0x32cc54 */
          lVar13 = func_0x007fd748();
          *(undefined4 *)(lVar13 + 0x4a418) = 1;
          uVar12 = 2;
          goto LAB_006d4258;
        }
      }
      else {
        if (uVar1 == 0x3ea) goto LAB_006d428c;
        if (uVar1 == 9999) {
          if (0x270e < _DAT_00c0ebd0) goto LAB_006d440c;
          goto LAB_006d4254;
        }
        iVar8 = func_0x006efb14();
        lVar13 = param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc;
        pbVar14 = &UNK_00383748 + uVar15 + lVar13;  /* field_off=0x383748 */
        iVar9 = func_0x006efca4((uint)((&UNK_00383802)[lVar13] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383802 */
                                (uint)((&UNK_00383803)[lVar13] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383803 */
                                (uint)((&UNK_00383801)[lVar13] ^ pbVar14[1]) << 8 |  /* field_off=0x383801 */
                                (uint)((&UNK_00383800)[lVar13] ^ *pbVar14));  /* field_off=0x383800 */
        lVar13 = param_1 + (long)iVar8 * 4;
        if (*(int *)(&UNK_0038efd4 + lVar13) == 0) {  /* field_off=0x38efd4 */
LAB_006d45d0:
          *(undefined4 *)(&UNK_0038efd4 + lVar13) = 1;  /* field_off=0x38efd4 */
          lVar13 = func_0x007fd748();
          *(undefined4 *)(lVar13 + 0x4a418) = 1;
          uVar12 = 2;
          goto LAB_006d4258;
        }
        iVar8 = func_0x005cf74c(&UNK_00383748 + param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc,  /* field_off=0x383748 */
                                lVar11);
        if ((iVar8 < 1000) ||
           (iVar8 = func_0x005cf74c(&UNK_00383748 +  /* field_off=0x383748 */
                                    param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc,lVar11),
           _DAT_00c0ebd4 < iVar8)) {
          lVar13 = param_1 + (long)iVar9 * 8;
          iVar8 = func_0x00a92e2c(lVar13 + 0x47aac);
          param_1 = param_1 + (long)iVar9 * 0x100;
          iVar9 = func_0x005cf5fc(param_1 + 0x4af18,0x13);
          if (iVar9 <= iVar8) {
LAB_006d45f0:
            uVar12 = 5;
            goto LAB_006d4258;
          }
          iVar8 = func_0x00a92e2c(lVar13 + 0x47aac);
          iVar9 = func_0x005cf5fc(param_1 + 0x4af18,0x13);
          bVar7 = SBORROW4(iVar8,iVar9 + -1);
          iVar8 = iVar8 - (iVar9 + -1);
LAB_006d4594:
          uVar12 = 3;
          if (iVar8 < 0 == bVar7) {
            uVar12 = 4;
          }
          func_0x00a92f68(lVar13 + 0x47aac,1);
          lVar13 = func_0x007fd748();
          func_0x007d78f4(&UNK_0032c0b8 + lVar13,0x11,0,1,0,0);  /* field_off=0x32c0b8 */
          goto LAB_006d4258;
        }
      }
LAB_006d429c:
      if ((param_3 & 1) == 0) {
        uVar15 = BattleFn_0x004af784(1);
        uVar12 = 1;
        if ((uVar15 & 1) != 0) {
          (&UNK_0038f61c)[param_1] = 1;  /* field_off=0x38f61c */
        }
      }
      else {
        uVar12 = 1;
      }
      goto LAB_006d4258;
    }
  }
  else {
    uVar10 = BattleFn_0x005e437c();
    lVar11 = (long)*(int *)(param_1 + 0x83684) * 0xbc + param_1;
    lVar13 = (-(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2) + 4;
    pbVar14 = &UNK_00383748 + lVar13 + lVar11;  /* field_off=0x383748 */
    BattleFn_0x005e3770(uVar10,(uint)((&UNK_00383748)[lVar11 + 0xba] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383748 */
                               (uint)((&UNK_00383748)[lVar11 + 0xbb] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383748 */
                               (uint)((&UNK_00383748)[lVar11 + 0xb9] ^ pbVar14[1]) << 8 |  /* field_off=0x383748 */
                               (uint)((&UNK_00383748)[lVar11 + 0xb8] ^ *pbVar14),0);  /* field_off=0x383748 */
    lVar11 = (long)*(int *)(param_1 + 0x83684) * 0xbc + param_1;
    pbVar14 = &UNK_00383748 + uVar15 + lVar11;  /* field_off=0x383748 */
    iVar8 = BattleFn_0x005e437c((uint)((&UNK_00383748)[lVar11 + 0xba] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383748 */
                                (uint)((&UNK_00383748)[lVar11 + 0xbb] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383748 */
                                (uint)((&UNK_00383748)[lVar11 + 0xb9] ^ pbVar14[1]) << 8 |  /* field_off=0x383748 */
                                (uint)((&UNK_00383748)[lVar11 + 0xb8] ^ *pbVar14));  /* field_off=0x383748 */
    uVar12 = 0;
    if (iVar8 != 0x16) goto LAB_006d4258;
    puStack_128 = &UNK_002974c3;  /* UNK_2974c3(vma=0x1974c3)='sec1_type' */
    auStack_120[0] = 0;
    uStack_118 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,4);
    puStack_138 = &UNK_0029f72d;  /* UNK_29f72d(vma=0x19f72d)='MapID' */
    func_0x00bc5cd0(auStack_120,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    iVar8 = func_0x007ac230(0);
    puStack_108 = &UNK_0029a3d5;  /* UNK_29a3d5(vma=0x19a3d5)='sec1_id' */
    auStack_100[0] = 0;
    uStack_f8 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,1);
    puStack_138 = (undefined *)(long)iVar8;
    func_0x00bc5cd0(auStack_100,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    puStack_e8 = &UNK_00290d7a;  /* UNK_290d7a(vma=0x190d7a)='sec2_type' */
    auStack_e0[0] = 0;
    uStack_d8 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,4);
    puStack_138 = &UNK_0029a3dd;  /* UNK_29a3dd(vma=0x19a3dd)='StageIdx' */
    func_0x00bc5cd0(auStack_e0,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    iVar8 = func_0x007ac380();
    puStack_c8 = &UNK_00298462;  /* UNK_298462(vma=0x198462)='sec2_id' */
    auStack_c0[0] = 0;
    uStack_b8 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,1);
    puStack_138 = (undefined *)(long)iVar8;
    func_0x00bc5cd0(auStack_c0,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    puStack_a8 = &UNK_00291fc1;  /* UNK_291fc1(vma=0x191fc1)='ex_type' */
    auStack_a0[0] = 0;
    uStack_98 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,4);
    puStack_138 = &UNK_002a7798;  /* UNK_2a7798(vma=0x1a7798)='StageLv' */
    func_0x00bc5cd0(auStack_a0,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    iVar8 = func_0x007ac5b8();
    puStack_88 = &UNK_002a6836;  /* UNK_2a6836(vma=0x1a6836)='ex_id' */
    auStack_80[0] = 0;
    uStack_78 = 0;
    auStack_140[0] = 0;
    func_0x00bc5cc0(auStack_140,1);
    puStack_138 = (undefined *)(long)iVar8;
    func_0x00bc5cd0(auStack_80,auStack_140);
    func_0x00bc5cc0(auStack_140,0);
    lVar11 = func_0x007fd748();
    param_1 = param_1 + (long)*(int *)(param_1 + 0x83684) * 0xbc;
    pbVar14 = &UNK_00383748 + lVar13 + param_1;  /* field_off=0x383748 */
    uVar12 = 0x98c17f;
    if ((param_3 & 1) != 0) {
      uVar12 = 0x98c180;
    }
    func_0x0082572c(*(undefined8 *)(lVar11 + 0x21a0),uVar12,
                    (uint)((&UNK_00383802)[param_1] ^ pbVar14[2]) << 0x10 |  /* field_off=0x383802 */
                    (uint)((&UNK_00383803)[param_1] ^ pbVar14[3]) << 0x18 |  /* field_off=0x383803 */
                    (uint)((&UNK_00383801)[param_1] ^ pbVar14[1]) << 8 |  /* field_off=0x383801 */
                    (uint)((&UNK_00383800)[param_1] ^ *pbVar14),0,&puStack_128,6);  /* field_off=0x383800 */
    func_0x00bc5cc0(auStack_80,0);
    func_0x00bc5cc0(auStack_a0,0);
    func_0x00bc5cc0(auStack_c0,0);
    func_0x00bc5cc0(auStack_e0,0);
    func_0x00bc5cc0(auStack_100,0);
    func_0x00bc5cc0(auStack_120,0);
  }
LAB_006d4254:
  uVar12 = 0;
LAB_006d4258:
  if (*(long *)(lVar6 + 0x28) != lStack_68) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return uVar12;
}


