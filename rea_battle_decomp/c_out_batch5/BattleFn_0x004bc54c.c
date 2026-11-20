// ELF VMA: 0x4bc54c
// Ghidra Addr: 0x005bc54c (ImageBase=0x100000)
// Size: 120 bytes


void BattleFn_0x004bc54c(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  
  piVar3 = (int *)(param_1 + 0x9dc6c);
  lVar4 = 0x1e;
  do {
    if ((char)piVar3[-3] != '\0') {
      iVar1 = *piVar3;
      *piVar3 = iVar1 + 1;
      iVar2 = func_0x004400b4(param_2 + 0x2248);
      if (iVar2 <= iVar1 + 1) {
        *(undefined1 *)(piVar3 + -3) = 0;
      }
    }
    lVar4 = lVar4 + -1;
    piVar3 = piVar3 + 4;
  } while (lVar4 != 0);
  return;
}


