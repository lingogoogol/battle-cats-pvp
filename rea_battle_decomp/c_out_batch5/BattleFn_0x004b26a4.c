// ELF VMA: 0x4b26a4
// Ghidra Addr: 0x005b26a4 (ImageBase=0x100000)
// Size: 200 bytes


undefined8 BattleFn_0x004b26a4(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  uVar1 = func_0x005abf04(param_2,param_3);
  lVar4 = func_0x007fd748();
  iVar2 = func_0x00651310(lVar4 + 0x1538,uVar1);
  if (0 < iVar2) {
    iVar2 = 0;
    do {
      lVar4 = func_0x007fd748();
      iVar3 = func_0x00651898(lVar4 + 0x1538,uVar1,iVar2);
      if (iVar3 != -1) {
        lVar4 = func_0x007fd748();
        lVar4 = func_0x00650e34(lVar4 + 0x1538,iVar3);
        lVar5 = func_0x007fd748();
        uVar6 = func_0x006533bc(lVar5 + 0x1538,*(undefined4 *)(lVar4 + 0xc));
        if ((uVar6 & 1) != 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
      lVar4 = func_0x007fd748();
      iVar3 = func_0x00651310(lVar4 + 0x1538,uVar1);
    } while (iVar2 < iVar3);
  }
  return 0;
}


