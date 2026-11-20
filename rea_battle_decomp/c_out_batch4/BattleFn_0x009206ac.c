// ELF VMA: 0x9206ac
// Ghidra Addr: 0x00a206ac (ImageBase=0x100000)
// Size: 376 bytes


void BattleFn_0x009206ac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  int aiStack_98 [2];
  long lStack_90;
  long lStack_88;
  long lStack_68;
  
  lVar3 = tpidr_el0;
  lStack_68 = *(long *)(lVar3 + 0x28);
  if ((param_1 == 3) ||
     (uVar4 = func_0x007fd748(), lVar6 = uVar4 + (long)param_1 * 0x18,
     (int)((ulong)(*(long *)(&UNK_00290570 + lVar6) - *(long *)(&UNK_00290568 + lVar6)) >> 4) *
     -0x55555555 < 1)) {
    uVar4 = 0;
  }
  else {
    uVar7 = 0;
    do {
      lVar6 = 0;
      while( true ) {
        lVar5 = func_0x007fd748(uVar4);
        func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar5,param_1,uVar7);
        lVar5 = (long)aiStack_98[0];
        if (lStack_90 != 0) {
          lStack_88 = lStack_90;
          func_0x00bc3350();
        }
        if (lVar5 <= lVar6) break;
        lVar5 = func_0x007fd748();
        func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar5,param_1,uVar7);
        iVar1 = *(int *)(&DAT_00c0b0b4 + (long)param_2 * 4);
        iVar2 = *(int *)(lStack_90 + lVar6 * 4);
        lStack_88 = lStack_90;
        uVar4 = func_0x00bc3350();
        lVar6 = lVar6 + 1;
        if (iVar2 == iVar1) {
          uVar4 = (ulong)uVar7;
          goto LAB_00a207f0;
        }
      }
      uVar7 = uVar7 + 1;
      lVar6 = func_0x007fd748();
      lVar6 = lVar6 + (long)param_1 * 0x18;
      uVar4 = 0;
    } while ((int)uVar7 <
             (int)((ulong)(*(long *)(&UNK_00290570 + lVar6) - *(long *)(&UNK_00290568 + lVar6)) >> 4
                  ) * -0x55555555);
  }
LAB_00a207f0:
  if (*(long *)(lVar3 + 0x28) != lStack_68) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380(uVar4);
  }
  return;
}


