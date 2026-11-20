// ELF VMA: 0x4bbf4c
// Ghidra Addr: 0x005bbf4c (ImageBase=0x100000)
// Size: 320 bytes


void BattleFn_0x004bbf4c(long param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  lVar1 = 0x34;
  piVar2 = (int *)(param_1 + 0x9c778);
  do {
    lVar1 = lVar1 + -4;
    iVar7 = *piVar2 + -1;
    iVar8 = piVar2[4] + -1;
    iVar9 = piVar2[8] + -1;
    iVar10 = piVar2[0xc] + -1;
    iVar3 = -(uint)(0 < *piVar2);
    iVar4 = -(uint)(0 < piVar2[4]);
    iVar5 = -(uint)(0 < piVar2[8]);
    iVar6 = -(uint)(0 < piVar2[0xc]);
    *piVar2 = CONCAT13((byte)((uint)iVar7 >> 0x18) & (byte)((uint)iVar3 >> 0x18),
                       CONCAT12((byte)((uint)iVar7 >> 0x10) & (byte)((uint)iVar3 >> 0x10),
                                CONCAT11((byte)((uint)iVar7 >> 8) & (byte)((uint)iVar3 >> 8),
                                         (byte)iVar7 & (byte)iVar3)));
    piVar2[0xc] = CONCAT13((byte)((uint)iVar10 >> 0x18) & (byte)((uint)iVar6 >> 0x18),
                           CONCAT12((byte)((uint)iVar10 >> 0x10) & (byte)((uint)iVar6 >> 0x10),
                                    CONCAT11((byte)((uint)iVar10 >> 8) & (byte)((uint)iVar6 >> 8),
                                             (byte)iVar10 & (byte)iVar6)));
    piVar2[4] = CONCAT13((byte)((uint)iVar8 >> 0x18) & (byte)((uint)iVar4 >> 0x18),
                         CONCAT12((byte)((uint)iVar8 >> 0x10) & (byte)((uint)iVar4 >> 0x10),
                                  CONCAT11((byte)((uint)iVar8 >> 8) & (byte)((uint)iVar4 >> 8),
                                           (byte)iVar8 & (byte)iVar4)));
    piVar2[8] = CONCAT13((byte)((uint)iVar9 >> 0x18) & (byte)((uint)iVar5 >> 0x18),
                         CONCAT12((byte)((uint)iVar9 >> 0x10) & (byte)((uint)iVar5 >> 0x10),
                                  CONCAT11((byte)((uint)iVar9 >> 8) & (byte)((uint)iVar5 >> 8),
                                           (byte)iVar9 & (byte)iVar5)));
    piVar2 = piVar2 + 0x10;
  } while (lVar1 != 0);
  iVar4 = *(int *)(param_1 + 0x9cab8);
  iVar3 = iVar4 + -1;
  if (iVar4 < 1) {
    iVar3 = 0;
  }
  iVar4 = *(int *)(param_1 + 0x9cac8) + -1;
  *(int *)(param_1 + 0x9cab8) = iVar3;
  if (*(int *)(param_1 + 0x9cac8) < 1) {
    iVar4 = 0;
  }
  iVar3 = *(int *)(param_1 + 0x9cad8) + -1;
  *(int *)(param_1 + 0x9cac8) = iVar4;
  if (*(int *)(param_1 + 0x9cad8) < 1) {
    iVar3 = 0;
  }
  iVar4 = *(int *)(param_1 + 0x9cae8) + -1;
  *(int *)(param_1 + 0x9cad8) = iVar3;
  if (*(int *)(param_1 + 0x9cae8) < 1) {
    iVar4 = 0;
  }
  *(int *)(param_1 + 0x9cae8) = iVar4;
  lVar1 = 0x34;
  piVar2 = (int *)(param_1 + 0x9caf8);
  do {
    lVar1 = lVar1 + -4;
    iVar7 = *piVar2 + -1;
    iVar8 = piVar2[4] + -1;
    iVar9 = piVar2[8] + -1;
    iVar10 = piVar2[0xc] + -1;
    iVar3 = -(uint)(0 < *piVar2);
    iVar4 = -(uint)(0 < piVar2[4]);
    iVar5 = -(uint)(0 < piVar2[8]);
    iVar6 = -(uint)(0 < piVar2[0xc]);
    *piVar2 = CONCAT13((byte)((uint)iVar7 >> 0x18) & (byte)((uint)iVar3 >> 0x18),
                       CONCAT12((byte)((uint)iVar7 >> 0x10) & (byte)((uint)iVar3 >> 0x10),
                                CONCAT11((byte)((uint)iVar7 >> 8) & (byte)((uint)iVar3 >> 8),
                                         (byte)iVar7 & (byte)iVar3)));
    piVar2[0xc] = CONCAT13((byte)((uint)iVar10 >> 0x18) & (byte)((uint)iVar6 >> 0x18),
                           CONCAT12((byte)((uint)iVar10 >> 0x10) & (byte)((uint)iVar6 >> 0x10),
                                    CONCAT11((byte)((uint)iVar10 >> 8) & (byte)((uint)iVar6 >> 8),
                                             (byte)iVar10 & (byte)iVar6)));
    piVar2[4] = CONCAT13((byte)((uint)iVar8 >> 0x18) & (byte)((uint)iVar4 >> 0x18),
                         CONCAT12((byte)((uint)iVar8 >> 0x10) & (byte)((uint)iVar4 >> 0x10),
                                  CONCAT11((byte)((uint)iVar8 >> 8) & (byte)((uint)iVar4 >> 8),
                                           (byte)iVar8 & (byte)iVar4)));
    piVar2[8] = CONCAT13((byte)((uint)iVar9 >> 0x18) & (byte)((uint)iVar5 >> 0x18),
                         CONCAT12((byte)((uint)iVar9 >> 0x10) & (byte)((uint)iVar5 >> 0x10),
                                  CONCAT11((byte)((uint)iVar9 >> 8) & (byte)((uint)iVar5 >> 8),
                                           (byte)iVar9 & (byte)iVar5)));
    piVar2 = piVar2 + 0x10;
  } while (lVar1 != 0);
  iVar3 = *(int *)(param_1 + 0x9ce38) + -1;
  if (*(int *)(param_1 + 0x9ce38) < 1) {
    iVar3 = 0;
  }
  iVar4 = *(int *)(param_1 + 0x9ce48) + -1;
  *(int *)(param_1 + 0x9ce38) = iVar3;
  if (*(int *)(param_1 + 0x9ce48) < 1) {
    iVar4 = 0;
  }
  *(int *)(param_1 + 0x9ce48) = iVar4;
  iVar3 = *(int *)(param_1 + 0x9ce58) + -1;
  if (*(int *)(param_1 + 0x9ce58) < 1) {
    iVar3 = 0;
  }
  iVar4 = *(int *)(param_1 + 0x9ce68) + -1;
  if (*(int *)(param_1 + 0x9ce68) < 1) {
    iVar4 = 0;
  }
  *(int *)(param_1 + 0x9ce58) = iVar3;
  *(int *)(param_1 + 0x9ce68) = iVar4;
  return;
}


