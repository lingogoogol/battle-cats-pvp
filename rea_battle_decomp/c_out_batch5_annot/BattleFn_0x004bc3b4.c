// ELF VMA: 0x4bc3b4
// Ghidra Addr: 0x005bc3b4 (ImageBase=0x100000)
// Size: 144 bytes


void BattleFn_0x004bc3b4(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  
  pcVar4 = (char *)(param_1 + 0x9cfe0);
  lVar5 = 200;
  do {
    if (*pcVar4 != '\0') {
      iVar3 = *(int *)(pcVar4 + 0xc);
      if (iVar3 == 0) {
        uVar2 = func_0x0044c16c();
        func_0x0044e364(uVar2,0x2c);
        iVar3 = *(int *)(pcVar4 + 0xc);
      }
      *(int *)(pcVar4 + 0xc) = iVar3 + 1;
      iVar1 = func_0x004400b4(param_2 + 0x10e8);
      if (iVar1 <= iVar3 + 1) {
        func_0x005aa5cc(pcVar4);
      }
    }
    lVar5 = lVar5 + -1;
    pcVar4 = pcVar4 + 0x10;
  } while (lVar5 != 0);
  return;
}


