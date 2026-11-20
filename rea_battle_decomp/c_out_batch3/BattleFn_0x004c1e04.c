// ELF VMA: 0x004c1e04 | Ghidra Addr: 0x005c1e04 | BodySize: 852

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattleFn_0x004c1e04(long param_1)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  long lVar10;
  int *piVar11;
  int *piVar12;
  long lVar13;
  undefined8 *puVar14;
  int *piVar15;
  long lVar16;
  byte abStack_80 [16];
  undefined4 uStack_70;
  uint uStack_6c;
  long lStack_68;
  
  lVar3 = tpidr_el0;
  lStack_68 = *(long *)(lVar3 + 0x28);
  piVar15 = (int *)(&UNK_00333dfc + param_1);
  piVar12 = (int *)(&UNK_0033637c + param_1);
  lVar7 = 0;
  if (lRam0000000000c0b8b8 != 0) {
    lVar7 = func_0x00bc3a90(lRam0000000000c0b8b8,
                            &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                            &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
  }
  puVar14 = (undefined8 *)((ulong)abStack_80 | 1);
  lVar13 = 0;
  lVar10 = 200;
  piVar11 = piVar15;
  do {
    if ((char)piVar11[0xb] == '\0') {
      iVar4 = 4;
    }
    else {
      abStack_80[0] = 0x26;
      uStack_6c = uStack_6c & 0xffffff00;
      *(undefined4 *)((long)puVar14 + 0xf) = 0x7265746e;
      puVar14[1] = 0x6e695f735f657661;
      *puVar14 = 0x775f656c74746162;
      iVar4 = func_0x008e3f14(param_1 + 0x1478,abStack_80,4);
      if ((abStack_80[0] & 1) != 0) {
        func_0x00bc3350(CONCAT44(uStack_6c,uStack_70));
      }
    }
    if (*piVar11 - 1U < 2) {
      iVar5 = piVar11[3] + 1;
      iVar6 = 0;
      if (iVar4 != 0) {
        iVar6 = iVar5 / iVar4;
      }
      piVar11[3] = iVar5;
      if (iVar5 == iVar6 * iVar4) {
        if (piVar11[0x960] == 0) {
          lVar16 = 0;
          iVar5 = func_0x005ab154();
          piVar1 = piVar12;
        }
        else {
          if (piVar11[0x962] == 0) {
            uVar9 = 0x6384;
            lVar16 = 1;
          }
          else if (piVar11[0x964] == 0) {
            uVar9 = 0x638c;
            lVar16 = 2;
          }
          else if (piVar11[0x966] == 0) {
            uVar9 = 0x6394;
            lVar16 = 3;
          }
          else if (piVar11[0x968] == 0) {
            uVar9 = 0x639c;
            lVar16 = 4;
          }
          else {
            if (piVar11[0x96a] != 0) goto LAB_005c1ea4;
            uVar9 = 0x63a4;
            lVar16 = 5;
          }
          piVar1 = (int *)(param_1 + lVar13 * 0x30 + (ulong)(uVar9 | 0x330000));
          iVar5 = func_0x005ab154();
        }
        if (iVar5 == 0) {
          uVar8 = func_0x0044c16c();
          func_0x0044e35c(uVar8,0x1a,0);
        }
        lVar2 = lVar7 + 0x30d8;
        if ((char)piVar11[0xb] != '\0') {
          lVar2 = lVar7 + 0x3148;
        }
        iVar6 = func_0x0044003c(lVar2);
        iVar5 = *piVar11;
        *piVar1 = iVar6 + -1;
        if (iVar5 == 1) {
          piVar11[2] = 1;
          iVar5 = 0;
          if (iVar4 != 0) {
            iVar5 = piVar11[3] / iVar4;
          }
          iVar4 = piVar11[4] + iVar5 * _DAT_00c0b310 * -5;
LAB_005c2078:
          piVar11[lVar16 * 2 + 0x961] = iVar4 + 0x10e;
        }
        else {
          if (iVar5 == 2) {
            piVar11[2] = 2;
            iVar5 = 0;
            if (iVar4 != 0) {
              iVar5 = piVar11[3] / iVar4;
            }
            iVar4 = piVar11[4] + _DAT_00c0b310 * -5 + _DAT_00c0b310 * 5 * iVar5;
            goto LAB_005c2078;
          }
          iVar5 = 0;
          if (iVar4 != 0) {
            iVar5 = piVar11[3] / iVar4;
          }
        }
        if (piVar11[5] <= iVar5) {
          *piVar11 = 0;
          piVar11[3] = 0;
        }
      }
    }
LAB_005c1ea4:
    lVar10 = lVar10 + -1;
    lVar13 = lVar13 + 1;
    piVar11 = piVar11 + 0xc;
    piVar12 = piVar12 + 0xc;
    if (lVar10 == 0) {
      lVar7 = 200;
      do {
        if (((((piVar15[0x960] < 1) && (piVar15[0x962] < 1)) && (piVar15[0x964] < 1)) &&
            ((piVar15[0x966] < 1 && (piVar15[0x968] < 1)))) &&
           ((piVar15[0x96a] < 1 && ((*piVar15 == 0 && (piVar15[2] != 0)))))) {
          piVar15[2] = 0;
        }
        lVar7 = lVar7 + -1;
        piVar15 = piVar15 + 0xc;
      } while (lVar7 != 0);
      if (*(long *)(lVar3 + 0x28) == lStack_68) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      NoRet_0x00ac3380();
    }
  } while( true );
}


