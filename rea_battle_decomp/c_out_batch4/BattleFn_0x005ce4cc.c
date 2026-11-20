// ELF VMA: 0x5ce4cc
// Ghidra Addr: 0x006ce4cc (ImageBase=0x100000)
// Size: 320 bytes


void BattleFn_0x005ce4cc(undefined8 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = func_0x00a613d8(param_2,param_3,0);
  if ((((iVar1 != param_4) && (iVar1 = func_0x00a613d8(param_2,param_3,1), iVar1 != param_4)) &&
      (iVar1 = func_0x00a613d8(param_2,param_3,2), iVar1 != param_4)) &&
     ((iVar1 = func_0x00a613d8(param_2,param_3,3), iVar1 != param_4 &&
      (iVar1 = func_0x00a613d8(param_2,param_3,4), iVar1 != param_4)))) {
    iVar1 = func_0x00a613d8(param_2,param_3,0);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      iVar2 = func_0x00a613d8(param_2,param_3,1);
      if (iVar2 != 0) {
        iVar1 = 2;
        iVar2 = func_0x00a613d8(param_2,param_3,2);
        if (iVar2 != 0) {
          iVar1 = 3;
          iVar2 = func_0x00a613d8(param_2,param_3,3);
          if (iVar2 != 0) {
            iVar1 = 4;
            iVar2 = func_0x00a613d8(param_2,param_3,4);
            if (iVar2 != 0) {
              return;
            }
          }
        }
      }
    }
    lVar3 = func_0x007fd748();
    *(int *)(lVar3 + (long)param_2 * 51000 + (long)param_3 * 1000 +
             (long)*(int *)(&UNK_002ea900 + (long)iVar1 * 4) * 4 + 0x83908) = param_4;
    return;
  }
  return;
}


