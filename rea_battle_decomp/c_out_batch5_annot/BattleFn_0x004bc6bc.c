// ELF VMA: 0x4bc6bc
// Ghidra Addr: 0x005bc6bc (ImageBase=0x100000)
// Size: 140 bytes


void BattleFn_0x004bc6bc(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  
  lVar5 = 0x1e;
  pcVar4 = (char *)(param_1 + 0x9de40);
  do {
    if (*pcVar4 != '\0') {
      iVar2 = *(int *)(pcVar4 + 0xc);
      lVar1 = 0x38;
      if (pcVar4[0x18] != '\0') {
        lVar1 = 0x70;
      }
      *(int *)(pcVar4 + 0xc) = iVar2 + 1;
      iVar3 = func_0x004400b4(param_2 + 9000 + lVar1);
      if (iVar3 <= iVar2 + 1) {
        *pcVar4 = '\0';
      }
    }
    lVar5 = lVar5 + -1;
    pcVar4 = pcVar4 + 0x1c;
  } while (lVar5 != 0);
  return;
}


