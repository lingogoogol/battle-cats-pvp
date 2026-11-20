// ELF VMA: 0x5d9d6c
// Ghidra Addr: 0x006d9d6c (ImageBase=0x100000)
// Size: 2168 bytes


/* WARNING: Possible PIC construction at 0x006da9bc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006da9e4: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006da9c0) */
/* WARNING: Removing unreachable block (ram,0x006da9dc) */
/* WARNING: Removing unreachable block (ram,0x006da9e8) */

ulong BattleFn_0x005d9d6c(long param_1,undefined4 param_2,long *param_3,uint param_4)

{
  long *plVar1;
  uint *puVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  ulong uVar24;
  undefined8 *puVar25;
  undefined8 *puVar26;
  undefined8 uVar27;
  long lVar28;
  ulong uVar29;
  undefined1 *puVar30;
  undefined4 *puVar31;
  long lVar32;
  long lVar33;
  undefined *puVar34;
  ulong uVar35;
  ulong uVar36;
  undefined1 auVar37 [16];
  byte abStack_d0 [16];
  undefined8 uStack_c0;
  byte bStack_b8;
  undefined7 uStack_b7;
  undefined1 uStack_b0;
  undefined2 uStack_af;
  undefined1 uStack_ad;
  undefined8 uStack_a8;
  ushort auStack_a0 [8];
  undefined8 uStack_90;
  byte abStack_88 [16];
  undefined8 uStack_78;
  long lStack_70;
  
  lVar28 = tpidr_el0;
  lStack_70 = *(long *)(lVar28 + 0x28);
  func_0x00a589e0(abStack_88,0);  /* 0x9589e0:[slot*1000,team*0x1f0,team*51000|off=0x83908,0x83908,0x8e9fe5,0x83908,0x83908,0x656e6f4e|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldrb w9, [x8]] */
  if ((int)param_4 < 1) {
    auStack_a0[0] = 0;
  }
  else {
    bStack_b8 = 0x14;
    uStack_af = 0x29ae;
    uStack_b7 = 0xe79e9be5642528;
    uStack_b0 = 0x9b;
    uStack_ad = 0;
    func_0x00416d84(auStack_a0,&bStack_b8,0,param_4 + 1);
    if ((auStack_a0[0] & 1) != 0) {
      func_0x00bc3350(uStack_90);
    }
    if ((bStack_b8 & 1) != 0) {
      func_0x00bc3350(uStack_a8);
    }
  }
  if ((abStack_88[0] & 1) != 0) {
    func_0x00bc3350(uStack_78);
  }
  uVar29 = (ulong)param_4;
  uVar35 = (ulong)param_4;
  BattleFn_0x005da618(param_1,0,param_2,uVar29);
  iVar20 = *(int *)(&UNK_0038816c + param_1);  /* field_off=0x38816c */
  iVar21 = *(int *)(&UNK_00388180 + param_1);  /* field_off=0x388180 */
  bVar6 = iVar20 != 0;
  bVar7 = iVar21 != 0;
  bVar8 = *(int *)(&UNK_00388170 + param_1) != 0;  /* field_off=0x388170 */
  bVar9 = *(int *)(&UNK_00388174 + param_1) != 0;  /* field_off=0x388174 */
  bVar10 = *(int *)(&UNK_00388178 + param_1) != 0;  /* field_off=0x388178 */
  bVar11 = *(int *)(&UNK_0038817c + param_1) != 0;  /* field_off=0x38817c */
  bVar12 = *(int *)(&UNK_00388184 + param_1) != 0;  /* field_off=0x388184 */
  bVar13 = *(int *)(&UNK_0038818c + param_1) != 0;  /* field_off=0x38818c */
  bVar14 = *(int *)(&UNK_00388188 + param_1) != 0;  /* field_off=0x388188 */
  bVar15 = *(int *)(&UNK_00388190 + param_1) != 0;  /* field_off=0x388190 */
  bVar16 = *(int *)(&UNK_00388194 + param_1) != 0;  /* field_off=0x388194 */
  bVar17 = *(int *)(&UNK_00388198 + param_1) != 0;  /* field_off=0x388198 */
  uVar18 = func_0x00a5f6cc(0,param_2);  /* 0x95f6cc:[slot*1000,team*0x1f0,team*51000|off=0x83c70|ldr w0, [x8, x9]] */
  lVar33 = *param_3;
  if (param_3[1] != lVar33) {
    uVar36 = 0;
    do {
      uVar5 = *(uint *)(lVar33 + uVar36 * 4);
      func_0x00a589e0(abStack_d0,1,uVar5);  /* 0x9589e0:[slot*1000,team*0x1f0,team*51000|off=0x83908,0x83908,0x8e9fe5,0x83908,0x83908,0x656e6f4e|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldrb w9, [x8]] */
      if ((abStack_d0[0] & 1) != 0) {
        func_0x00bc3350(uStack_c0);
      }
      uVar29 = (ulong)uVar5;
      uVar24 = BattleFn_0x005d5498(param_1,0,param_2,uVar29,uVar35,0,iVar20 != 0,iVar21 != 0);
      if ((uVar24 & 1) != 0) {
        uVar24 = func_0x00a58fa0(0,param_2);  /* 0x958fa0:[slot*1000,team*51000|off=0x83c20|ldr w8, [x8, x9]] */
        if (((uVar24 & 1) == 0) || (iVar19 = func_0x00a58ba4(1,uVar5), iVar19 != 0xe)) {  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
          uVar24 = func_0x00a5c8d4(0,param_2,uVar35);  /* 0x95c8d4:[slot*1000,team*51000|off=0x83908,0x83908,0x83a58|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          lVar33 = param_1 + (long)(int)uVar5 * 1000;
          if ((uVar24 & 1) == 0) {
            *(undefined4 *)(lVar33 + 0x901c0) = 0;
          }
          else {
            *(undefined4 *)(lVar33 + 0x901c0) = 1;
          }
        }
        else {
          *(undefined4 *)(param_1 + (long)(int)uVar5 * 1000 + 0x901c0) = 2;
        }
      }
      lVar33 = *param_3;
      uVar36 = uVar36 + 1;
    } while (uVar36 < (ulong)(param_3[1] - lVar33 >> 2));
  }
  uVar36 = func_0x00a5a878(0,param_2);  /* 0x95a878:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
  if ((uVar36 & 1) != 0) {
    plVar1 = (long *)(&UNK_00338900 + param_1);  /* field_off=0x338900 */
    iVar20 = func_0x00a5c4a0(0,param_2);  /* 0x95c4a0:[slot*1000,team*51000|off=0x839a4|ldr w0, [x8, x9]] */
    if (0 < iVar20) {
      iVar20 = func_0x0043ea60(100);
      func_0x00a5c37c(0,param_2);  /* 0x95c37c:[slot*1000,team*51000|off=0x83be0|ldr w0, [x8, x9]] */
      func_0x00a5c4a0(0,param_2);  /* 0x95c4a0:[slot*1000,team*51000|off=0x839a4|ldr w0, [x8, x9]] */
      func_0x00a5c4a0(0,param_2);  /* 0x95c4a0:[slot*1000,team*51000|off=0x839a4|ldr w0, [x8, x9]] */
      iVar21 = func_0x00a5c4a0(0,param_2);  /* 0x95c4a0:[slot*1000,team*51000|off=0x839a4|ldr w0, [x8, x9]] */
      if (iVar20 < iVar21) {
        lVar33 = 0;
        puVar34 = &UNK_00333e28 + param_1;  /* field_off=0x333e28 */
LAB_006da144:
        if ((*(int *)(puVar34 + -0x2c) != 0) || (*(int *)(puVar34 + -0x24) != 0)) goto LAB_006da134;
        iVar20 = func_0x00a5c37c(0,param_2);  /* 0x95c37c:[slot*1000,team*51000|off=0x83be0|ldr w0, [x8, x9]] */
        *(undefined4 *)(puVar34 + -0x2c) = 1;
        *(undefined4 *)(puVar34 + -0x28) = param_2;
        *puVar34 = iVar20 == 1;
        *(undefined8 *)(puVar34 + -0x24) = 1;
        uVar22 = func_0x00a5919c(0,param_2);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
        *(undefined4 *)(puVar34 + -0x1c) = uVar22;
        uVar22 = func_0x00a5c4e0(0,param_2);  /* 0x95c4e0:[slot*1000,team*51000|off=0x839a8|ldr w0, [x8, x9]] */
        *(undefined4 *)(puVar34 + -0x18) = uVar22;
        *(uint *)(puVar34 + -0x14) = param_4;
        puVar34[-0x10] = bVar6;
        puVar34[-8] = bVar7;
        *(undefined4 *)(puVar34 + -4) = uVar18;
        puVar34[-0xf] = bVar8;
        puVar34[-0xe] = bVar9;
        puVar34[-0xd] = bVar10;
        puVar34[-0xc] = bVar11;
        puVar34[-0xb] = bVar12;
        puVar34[-10] = bVar13;
        puVar34[-9] = bVar14;
        puVar34[-7] = bVar15;
        puVar34[-6] = bVar16;
        lVar32 = 0x33;
        puVar34[-5] = bVar17;
        puVar30 = &UNK_003881a0 + (param_1 - lVar33);  /* field_off=0x3881a0 */
        do {
          lVar32 = lVar32 + -1;
          *puVar30 = 0;
          puVar30 = puVar30 + 200;
        } while (lVar32 != 0);
      }
    }
LAB_006da204:
    iVar20 = func_0x00a5d1a0(0,param_2);  /* 0x95d1a0:[slot*1000,team*51000|off=0x83bc0|ldr w0, [x8, x9]] */
    if (0 < iVar20) {
      iVar20 = func_0x0043ea60(100);
      func_0x00a5d1a0(0,param_2);  /* 0x95d1a0:[slot*1000,team*51000|off=0x83bc0|ldr w0, [x8, x9]] */
      func_0x00a5d1a0(0,param_2);  /* 0x95d1a0:[slot*1000,team*51000|off=0x83bc0|ldr w0, [x8, x9]] */
      iVar21 = func_0x00a5d1a0(0,param_2);  /* 0x95d1a0:[slot*1000,team*51000|off=0x83bc0|ldr w0, [x8, x9]] */
      if (iVar20 < iVar21) {
        puVar25 = (undefined8 *)func_0x00bc3330(0x48);
        puVar25[8] = 0;
        bStack_b8 = (byte)puVar25;
        uStack_b7 = (undefined7)((ulong)puVar25 >> 8);
        puVar25[1] = 0;
        *puVar25 = 0;
        puVar25[3] = 0;
        puVar25[2] = 0;
        puVar4 = *(undefined8 **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
        puVar26 = *(undefined8 **)(&UNK_00338910 + param_1);  /* field_off=0x338910 */
        puVar25[5] = 0;
        puVar25[4] = 0;
        puVar25[7] = 0;
        puVar25[6] = 0;
        puVar25[6] = puVar25 + 7;
        if (puVar4 < puVar26) {
          puVar26 = puVar4 + 1;
          *puVar4 = puVar25;
          *(undefined8 **)(&UNK_00338908 + param_1) = puVar26;  /* field_off=0x338908 */
        }
        else {
          puVar26 = (undefined8 *)func_0x005c8c54(plVar1,&bStack_b8);
          lVar33 = CONCAT71(uStack_b7,bStack_b8);
          *(undefined8 **)(&UNK_00338908 + param_1) = puVar26;  /* field_off=0x338908 */
          bStack_b8 = 0;
          uStack_b7 = 0;
          if (lVar33 != 0) {
            func_0x0058c04c(lVar33 + 0x30,*(undefined8 *)(lVar33 + 0x38));
            func_0x00bc3350(lVar33);
            puVar26 = *(undefined8 **)(&UNK_00338908 + param_1);  /* field_off=0x338908 */
          }
        }
        if (puVar26 != (undefined8 *)*plVar1) {
          puVar31 = (undefined4 *)puVar26[-1];
          *puVar31 = 0;
          puVar31[1] = param_2;
          puVar31[2] = 0;
          iVar20 = func_0x00a5919c(0,param_2);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
          iVar21 = func_0x00a5d22c(0,param_2);  /* 0x95d22c:[slot*1000,team*51000|off=0x83bc4|ldr w0, [x8, x9]] */
          func_0x00a5d2b8(0,param_2);  /* 0x95d2b8:[slot*1000,team*51000|off=0x83bc8|ldr w0, [x8, x9]] */
          func_0x0043ecf8();
          iVar19 = func_0x0043ea60();
          iVar23 = func_0x00a5d2b8(0,param_2);  /* 0x95d2b8:[slot*1000,team*51000|off=0x83bc8|ldr w0, [x8, x9]] */
          if (*(long *)(&UNK_00338908 + param_1) != *plVar1) {  /* field_off=0x338908 */
            iVar3 = -iVar19;
            if (iVar23 < 1) {
              iVar3 = iVar19;
            }
            *(int *)(*(long *)(*(long *)(&UNK_00338908 + param_1) + -8) + 0xc) =  /* field_off=0x338908 */
                 (iVar20 - iVar21) + iVar3;
            uVar22 = func_0x00a5d344(0,param_2);  /* 0x95d344:[slot*1000,team*51000|off=0x83bcc|ldr w0, [x8, x9]] */
            if (*(long *)(&UNK_00338908 + param_1) != *plVar1) {  /* field_off=0x338908 */
              lVar33 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);  /* field_off=0x338908 */
              *(bool *)(lVar33 + 0x18) = bVar6;
              *(bool *)(lVar33 + 0x20) = bVar7;
              *(undefined4 *)(lVar33 + 0x10) = uVar22;
              *(uint *)(lVar33 + 0x14) = param_4;
              *(bool *)(lVar33 + 0x19) = bVar8;
              *(bool *)(lVar33 + 0x1a) = bVar9;
              *(bool *)(lVar33 + 0x1b) = bVar10;
              *(bool *)(lVar33 + 0x1c) = bVar11;
              *(bool *)(lVar33 + 0x1d) = bVar12;
              *(bool *)(lVar33 + 0x1e) = bVar13;
              *(bool *)(lVar33 + 0x1f) = bVar14;
              *(bool *)(lVar33 + 0x21) = bVar15;
              *(bool *)(lVar33 + 0x23) = bVar17;
              *(bool *)(lVar33 + 0x22) = bVar16;
              *(undefined4 *)(lVar33 + 0x24) = uVar18;
              iVar20 = func_0x00a5d160(0,param_2);  /* 0x95d160:[slot*1000,team*51000|off=0x83c54|ldr w0, [x8, x9]] */
              if (*(long *)(&UNK_00338908 + param_1) != *plVar1) {  /* field_off=0x338908 */
                lVar33 = *(long *)(*(long *)(&UNK_00338908 + param_1) + -8);  /* field_off=0x338908 */
                *(bool *)(lVar33 + 0x28) = iVar20 != 0;
                *(undefined4 *)(lVar33 + 0x2c) = 0;
                goto LAB_006da3e0;
              }
            }
          }
        }
        if (*(long *)(lVar28 + 0x28) == lStack_70) {
          uVar27 = func_0x005c8c40(plVar1);
          BattleFn_0x005daa18(&bStack_b8);
          if (*(long *)(lVar28 + 0x28) == lStack_70) {
            func_0x00bbf40c(uVar27);
          }
        }
        goto LAB_006da614;
      }
    }
LAB_006da3e0:
    uVar36 = func_0x00a5d8d8(0,param_2);  /* 0x95d8d8:[slot*1000,team*51000|off=0x83c88|ldr w0, [x8, x9]] */
    if (0 < (int)uVar36) {
      iVar20 = func_0x0043ea60(100);
      func_0x00a5d8d8(0,param_2);  /* 0x95d8d8:[slot*1000,team*51000|off=0x83c88|ldr w0, [x8, x9]] */
      func_0x00a5d8d8(0,param_2);  /* 0x95d8d8:[slot*1000,team*51000|off=0x83c88|ldr w0, [x8, x9]] */
      uVar36 = func_0x00a5d8d8(0,param_2);  /* 0x95d8d8:[slot*1000,team*51000|off=0x83c88|ldr w0, [x8, x9]] */
      if (iVar20 < (int)uVar36) {
        puVar25 = (undefined8 *)func_0x00bc3330(0x40);
        bStack_b8 = (byte)puVar25;
        uStack_b7 = (undefined7)((ulong)puVar25 >> 8);
        puVar25[5] = 0;
        puVar25[4] = 0;
        puVar25[1] = 0;
        *puVar25 = 0;
        puVar4 = *(undefined8 **)(&UNK_00338938 + param_1);  /* field_off=0x338938 */
        puVar26 = *(undefined8 **)(&UNK_00338940 + param_1);  /* field_off=0x338940 */
        puVar25[3] = 0;
        puVar25[2] = 0;
        puVar25[7] = 0;
        puVar25[6] = 0;
        puVar25[5] = puVar25 + 6;
        if (puVar4 < puVar26) {
          puVar26 = puVar4 + 1;
          *puVar4 = puVar25;
          *(undefined8 **)(&UNK_00338938 + param_1) = puVar26;  /* field_off=0x338938 */
        }
        else {
          puVar26 = (undefined8 *)func_0x006e0280(&UNK_00338930 + param_1,&bStack_b8);  /* field_off=0x338930 */
          lVar33 = CONCAT71(uStack_b7,bStack_b8);
          *(undefined8 **)(&UNK_00338938 + param_1) = puVar26;  /* field_off=0x338938 */
          bStack_b8 = 0;
          uStack_b7 = 0;
          if (lVar33 != 0) {
            func_0x005c8e50(lVar33 + 0x28,*(undefined8 *)(lVar33 + 0x30));
            func_0x00bc3350(lVar33);
            puVar26 = *(undefined8 **)(&UNK_00338938 + param_1);  /* field_off=0x338938 */
          }
        }
        puVar31 = (undefined4 *)puVar26[-1];
        *puVar31 = 0;
        puVar31[1] = param_2;
        puVar31[2] = 0;
        iVar21 = func_0x00a5919c(0,param_2);  /* 0x95919c:[slot*1000,team*51000|off=0x83914|ldr w0, [x8, x9]] */
        iVar19 = func_0x00a5d964(0,param_2);  /* 0x95d964:[slot*1000,team*51000|off=0x83c8c|ldr w0, [x8, x9]] */
        func_0x00a5d9f0(0,param_2);  /* 0x95d9f0:[slot*1000,team*51000|off=0x83c90|ldr w0, [x8, x9]] */
        func_0x0043ecf8();
        iVar23 = func_0x0043ea60();
        uVar36 = func_0x00a5d9f0(0,param_2);  /* 0x95d9f0:[slot*1000,team*51000|off=0x83c90|ldr w0, [x8, x9]] */
        iVar20 = -iVar23;
        if ((int)uVar36 < 1) {
          iVar20 = iVar23;
        }
        lVar33 = *(long *)(*(long *)(&UNK_00338938 + param_1) + -8);  /* field_off=0x338938 */
        *(int *)(lVar33 + 0xc) = (iVar21 - iVar19) + iVar20;
        *(uint *)(lVar33 + 0x10) = param_4;
        *(bool *)(lVar33 + 0x14) = bVar6;
        *(bool *)(lVar33 + 0x1c) = bVar7;
        *(bool *)(lVar33 + 0x15) = bVar8;
        *(bool *)(lVar33 + 0x16) = bVar9;
        *(bool *)(lVar33 + 0x17) = bVar10;
        *(bool *)(lVar33 + 0x18) = bVar11;
        *(bool *)(lVar33 + 0x19) = bVar12;
        *(bool *)(lVar33 + 0x1a) = bVar13;
        *(bool *)(lVar33 + 0x1b) = bVar14;
        *(bool *)(lVar33 + 0x1d) = bVar15;
        *(bool *)(lVar33 + 0x1f) = bVar17;
        *(bool *)(lVar33 + 0x1e) = bVar16;
        *(undefined4 *)(lVar33 + 0x20) = uVar18;
      }
    }
  }
  if (*(long *)(lVar28 + 0x28) == lStack_70) {
    return uVar36;
  }
LAB_006da614:
  auVar37 = func_0x00bc3380();
  lVar28 = auVar37._0_8_;
  uVar36 = uVar35 & 0xffffffff;
  uVar24 = auVar37._8_8_ & 0xffffffff;
  puVar2 = (uint *)(&UNK_0038816c + lVar28);  /* field_off=0x38816c */
  *(undefined8 *)(&UNK_00388184 + lVar28) = 0;  /* field_off=0x388184 */
  *(undefined8 *)(&UNK_0038817c + lVar28) = 0;  /* field_off=0x38817c */
  *(undefined8 *)(&UNK_00388194 + lVar28) = 0;  /* field_off=0x388194 */
  *(undefined8 *)(&UNK_0038818c + lVar28) = 0;  /* field_off=0x38818c */
  *(undefined8 *)(&UNK_00388174 + lVar28) = 0;  /* field_off=0x388174 */
  puVar2[0] = 0;
  puVar2[1] = 0;
  uVar29 = func_0x00a5a878(auVar37._8_8_ & 0xffffffff,uVar35 & 0xffffffff,uVar29 & 0xffffffff);  /* 0x95a878:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
  if ((uVar29 & 1) != 0) {
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5e9a8(uVar24,uVar36);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
    *puVar2 = (uint)(iVar20 < iVar21);
    uVar29 = func_0x00a5e960(uVar24,uVar36);  /* 0x95e960:[slot*1000,team*51000|off=0x839e8|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5e9a8(uVar24,uVar36);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
      func_0x00a5e9a8(uVar24,uVar36);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5c568(uVar24,uVar36);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388170 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388170 */
    uVar29 = func_0x00a5c520(uVar24,uVar36);  /* 0x95c520:[slot*1000,team*51000|off=0x839cc|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5c568(uVar24,uVar36);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
      func_0x00a5c568(uVar24,uVar36);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5dbe4(uVar24,uVar36);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388174 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388174 */
    uVar29 = func_0x00a5db9c(uVar24,uVar36);  /* 0x95db9c:[slot*1000,team*51000|off=0x839d0|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5dbe4(uVar24,uVar36);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
      func_0x00a5dbe4(uVar24,uVar36);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5dd44(uVar24,uVar36);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388178 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388178 */
    uVar29 = func_0x00a5dcfc(uVar24,uVar36);  /* 0x95dcfc:[slot*1000,team*51000|off=0x839d8|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5dd44(uVar24,uVar36);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
      func_0x00a5dd44(uVar24,uVar36);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5dea4(uVar24,uVar36);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_0038817c + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x38817c */
    uVar29 = func_0x00a5de5c(uVar24,uVar36);  /* 0x95de5c:[slot*1000,team*51000|off=0x83a18|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5dea4(uVar24,uVar36);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
      func_0x00a5dea4(uVar24,uVar36);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5cfc0(uVar24,uVar36);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388180 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388180 */
    uVar29 = func_0x00a5cf78(uVar24,uVar36);  /* 0x95cf78:[slot*1000,team*51000|off=0x83b94|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5cfc0(uVar24,uVar36);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
      func_0x00a5cfc0(uVar24,uVar36);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5cd48(uVar24,uVar36);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388184 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388184 */
    uVar29 = func_0x00a5cd00(uVar24,uVar36);  /* 0x95cd00:[slot*1000,team*51000|off=0x83b24|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5cd48(uVar24,uVar36);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
      func_0x00a5cd48(uVar24,uVar36);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5f0e0(uVar24,uVar36);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388188 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388188 */
    uVar29 = func_0x00a5f098(uVar24,uVar36);  /* 0x95f098:[slot*1000,team*51000|off=0x83b18|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5f0e0(uVar24,uVar36);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
      func_0x00a5f0e0(uVar24,uVar36);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5e090(uVar24,uVar36);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_0038818c + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x38818c */
    uVar29 = func_0x00a5e048(uVar24,uVar36);  /* 0x95e048:[slot*1000,team*51000|off=0x83b54|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5e090(uVar24,uVar36);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
      func_0x00a5e090(uVar24,uVar36);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5d048(uVar24,uVar36);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388190 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388190 */
    uVar29 = func_0x00a5d000(uVar24,uVar36);  /* 0x95d000:[slot*1000,team*51000|off=0x83bb4|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5d048(uVar24,uVar36);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
      func_0x00a5d048(uVar24,uVar36);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
    }
    iVar20 = func_0x0043ea60(100);
    iVar21 = func_0x00a5f1b4(uVar24,uVar36);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388194 + lVar28) = (uint)(iVar20 < iVar21);  /* field_off=0x388194 */
    uVar29 = func_0x00a5f16c(uVar24,uVar36);  /* 0x95f16c:[slot*1000,team*51000|off=0x83be4|ldr w8, [x8, x9]] */
    if ((uVar29 & 1) != 0) {
      func_0x00a5f1b4(uVar24,uVar36);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
      func_0x00a5f1b4(uVar24,uVar36);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
    }
    func_0x0043ea60(100);
    lVar28 = func_0x007fd748();
    return (ulong)*(uint *)(lVar28 + (long)auVar37._8_4_ * 51000 + (long)(int)uVar35 * 1000 +
                           0x83ce0);
  }
  return uVar29;
LAB_006da134:
  lVar33 = lVar33 + -1;
  puVar34 = puVar34 + 0x30;
  if (lVar33 == -200) goto LAB_006da204;
  goto LAB_006da144;
}


