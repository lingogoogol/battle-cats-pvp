// ELF VMA: 0x4bc9ec
// Ghidra Addr: 0x005bc9ec (ImageBase=0x100000)
// Size: 300 bytes


void BattleFn_0x004bc9ec(long param_1,long param_2)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  long *plVar11;
  long *plVar12;
  
  plVar2 = (long *)(param_1 + 0x9e4d0);
  uVar6 = *(long *)(param_1 + 0x9e4d8) - *plVar2;
  if (0 < (int)(uVar6 >> 3)) {
    uVar6 = uVar6 >> 3 & 0xffffffff;
    lVar7 = uVar6 * 8;
    do {
      lVar7 = lVar7 + -8;
      uVar10 = uVar6 - 1;
      lVar8 = *(long *)(*plVar2 + uVar10 * 8);
      iVar9 = *(int *)(lVar8 + 8);
      if (iVar9 == 0) {
        uVar5 = func_0x0044c16c();
        func_0x0044e364(uVar5,0x5a);
        lVar8 = *(long *)(*plVar2 + uVar10 * 8);
        iVar9 = *(int *)(lVar8 + 8);
      }
      *(int *)(lVar8 + 8) = iVar9 + 1;
      iVar4 = func_0x0044003c(param_2 + 0x35b8);
      if (iVar4 <= iVar9 + 1) {
        lVar8 = *plVar2;
        plVar3 = *(long **)(param_1 + 0x9e4d8);
        plVar11 = (long *)(lVar8 + uVar6 * 8);
        if (plVar11 == plVar3) {
          plVar12 = (long *)(lVar8 + uVar10 * 8);
        }
        else {
          plVar12 = (long *)(lVar8 + lVar7);
          do {
            lVar8 = plVar11[-1];
            plVar11[-1] = *plVar11;
            *plVar11 = 0;
            if (lVar8 != 0) {
              func_0x00bc3350();
            }
            plVar11 = plVar11 + 1;
            plVar12 = plVar12 + 1;
          } while (plVar11 != plVar3);
          plVar11 = *(long **)(param_1 + 0x9e4d8);
        }
        while (plVar11 != plVar12) {
          plVar11 = plVar11 + -1;
          lVar8 = *plVar11;
          *plVar11 = 0;
          if (lVar8 != 0) {
            func_0x00bc3350();
          }
        }
        *(long **)(param_1 + 0x9e4d8) = plVar12;
      }
      bVar1 = 1 < (long)uVar6;
      uVar6 = uVar10;
    } while (bVar1);
  }
  return;
}


