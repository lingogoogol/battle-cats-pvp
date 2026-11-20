// ELF VMA: 0x4bce6c
// Ghidra Addr: 0x005bce6c (ImageBase=0x100000)
// Size: 276 bytes


void BattleFn_0x004bce6c(long param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  long *plVar11;
  
  plVar3 = (long *)(param_1 + 0x9e500);
  uVar6 = *(long *)(param_1 + 0x9e508) - *plVar3;
  if (0 < (int)(uVar6 >> 3)) {
    uVar6 = uVar6 >> 3 & 0xffffffff;
    lVar7 = uVar6 * 8;
    do {
      lVar7 = lVar7 + -8;
      uVar9 = uVar6 - 1;
      lVar8 = *(long *)(*plVar3 + uVar9 * 8);
      iVar2 = *(int *)(lVar8 + 8) + 1;
      *(int *)(lVar8 + 8) = iVar2;
      iVar5 = func_0x0044003c(param_2 + 0x16300);
      if (iVar5 <= iVar2) {
        lVar8 = *plVar3;
        plVar4 = *(long **)(param_1 + 0x9e508);
        plVar10 = (long *)(lVar8 + uVar6 * 8);
        if (plVar10 == plVar4) {
          plVar11 = (long *)(lVar8 + uVar9 * 8);
        }
        else {
          plVar11 = (long *)(lVar8 + lVar7);
          do {
            lVar8 = plVar10[-1];
            plVar10[-1] = *plVar10;
            *plVar10 = 0;
            if (lVar8 != 0) {
              func_0x00bc3350();
            }
            plVar10 = plVar10 + 1;
            plVar11 = plVar11 + 1;
          } while (plVar10 != plVar4);
          plVar10 = *(long **)(param_1 + 0x9e508);
        }
        while (plVar10 != plVar11) {
          plVar10 = plVar10 + -1;
          lVar8 = *plVar10;
          *plVar10 = 0;
          if (lVar8 != 0) {
            func_0x00bc3350();
          }
        }
        *(long **)(param_1 + 0x9e508) = plVar11;
      }
      bVar1 = 1 < (long)uVar6;
      uVar6 = uVar9;
    } while (bVar1);
  }
  return;
}


