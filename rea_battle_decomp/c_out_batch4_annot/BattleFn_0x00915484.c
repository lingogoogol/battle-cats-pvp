// ELF VMA: 0x915484
// Ghidra Addr: 0x00a15484 (ImageBase=0x100000)
// Size: 268 bytes


undefined8 *
BattleFn_0x00915484(long *param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  byte bVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined1 auStack_70 [8];
  undefined8 uStack_68;
  undefined8 *puStack_60;
  long *plStack_58;
  undefined1 uStack_50;
  long lStack_48;
  
  lVar2 = tpidr_el0;
  lStack_48 = *(long *)(lVar2 + 0x28);
  puVar3 = (undefined8 *)func_0x00a155b4(param_1,param_2,&uStack_68,auStack_70,param_3);
  puVar6 = (undefined8 *)*puVar3;
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = (undefined8 *)func_0x00bc3330(0x40);
    bVar1 = *(byte *)(param_4 + 2);
    uStack_50 = 0;
    *(undefined4 *)(puVar6 + 4) = *param_4;
    puStack_60 = puVar6;
    plStack_58 = param_1 + 1;
    if ((bVar1 & 1) == 0) {
      uVar7 = *(undefined8 *)(param_4 + 2);
      uVar4 = *(undefined8 *)(param_4 + 6);
      puVar6[6] = *(undefined8 *)(param_4 + 4);
      puVar6[5] = uVar7;
      puVar6[7] = uVar4;
    }
    else {
      func_0x0040a850(puVar6 + 5,*(undefined8 *)(param_4 + 6),*(undefined8 *)(param_4 + 4));
    }
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = uStack_68;
    *puVar3 = puVar6;
    puVar5 = puVar6;
    if (*(long *)*param_1 != 0) {
      *param_1 = *(long *)*param_1;
      puVar5 = (undefined8 *)*puVar3;
    }
    puVar3 = (undefined8 *)func_0x0040a8c0(param_1[1],puVar5);
    uVar4 = 1;
    param_1[2] = param_1[2] + 1;
  }
  else {
    uVar4 = 0;
  }
  if (*(long *)(lVar2 + 0x28) == lStack_48) {
    return puVar6;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380(puVar3,uVar4);
}


