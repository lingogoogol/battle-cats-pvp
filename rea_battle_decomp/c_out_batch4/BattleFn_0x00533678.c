// ELF VMA: 0x533678
// Ghidra Addr: 0x00633678 (ImageBase=0x100000)
// Size: 592 bytes


void BattleFn_0x00533678(long param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long *plVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined4 uStack_58;
  undefined1 uStack_51;
  undefined4 *puStack_50;
  long lStack_48;
  
  lVar1 = tpidr_el0;
  lStack_48 = *(long *)(lVar1 + 0x28);
  uStack_58 = param_2;
  uVar3 = func_0x00633464();
  if ((uVar3 & 1) == 0) {
    puVar5 = (undefined8 *)0x0;
    goto LAB_00633818;
  }
  func_0x007fd748();
  iVar2 = func_0x00800104();
  if ((iVar2 == 300) && (0 < *(int *)(param_1 + 0x6c))) {
    puStack_50 = &uStack_58;
    lVar4 = func_0x00634d18(param_1,&uStack_58,&UNK_002afa25,&puStack_50,&uStack_51);
    for (plVar7 = *(long **)(lVar4 + 0x48); plVar7 != (long *)0x0; plVar7 = (long *)*plVar7) {
      if (*(int *)(plVar7 + 4) <= param_3) {
        if (param_3 <= *(int *)(plVar7 + 4)) {
          puStack_50 = &uStack_58;
          lVar4 = func_0x00634d18(param_1,&uStack_58,&UNK_002afa25,&puStack_50,&uStack_51);
          puVar9 = (undefined8 *)(lVar4 + 0x48);
          puVar6 = (undefined8 *)*puVar9;
          puVar8 = puVar9;
          if ((undefined8 *)*puVar9 != (undefined8 *)0x0) goto LAB_0063384c;
          goto LAB_0063386c;
        }
        plVar7 = plVar7 + 1;
      }
    }
  }
  puStack_50 = &uStack_58;
  lVar4 = func_0x00634d18(param_1,&uStack_58,&UNK_002afa25,&puStack_50,&uStack_51);
  puVar8 = *(undefined8 **)(lVar4 + 0x30);
  puVar6 = (undefined8 *)(lVar4 + 0x30);
  while (puVar9 = puVar6, puVar8 != (undefined8 *)0x0) {
    while (puVar5 = puVar8, puVar6 = puVar5, *(int *)(puVar5 + 4) <= param_3) {
      if (param_3 <= *(int *)(puVar5 + 4)) goto LAB_006337b4;
      puVar8 = (undefined8 *)puVar5[1];
      if ((undefined8 *)puVar5[1] == (undefined8 *)0x0) {
        puVar9 = puVar5 + 1;
        goto LAB_00633760;
      }
    }
    puVar8 = (undefined8 *)*puVar5;
  }
LAB_00633760:
  puVar5 = (undefined8 *)func_0x00bc3330(0x40);
  *(int *)(puVar5 + 4) = param_3;
  puVar5[6] = 0;
  puVar5[7] = 0;
  puVar5[5] = 0;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = puVar6;
  *puVar9 = puVar5;
  puVar6 = puVar5;
  if (**(long **)(lVar4 + 0x28) != 0) {
    *(long *)(lVar4 + 0x28) = **(long **)(lVar4 + 0x28);
    puVar6 = (undefined8 *)*puVar9;
  }
  func_0x0040a8c0(*(undefined8 *)(lVar4 + 0x30),puVar6);
  *(long *)(lVar4 + 0x38) = *(long *)(lVar4 + 0x38) + 1;
  goto LAB_006337b4;
  while( true ) {
    if (param_3 <= *(int *)(puVar5 + 4)) goto LAB_006337b4;
    puVar6 = (undefined8 *)puVar5[1];
    if ((undefined8 *)puVar5[1] == (undefined8 *)0x0) break;
LAB_0063384c:
    puVar5 = puVar6;
    puVar9 = puVar5;
    if (param_3 < *(int *)(puVar5 + 4)) {
      puVar6 = (undefined8 *)*puVar5;
      puVar8 = puVar5;
      if ((undefined8 *)*puVar5 == (undefined8 *)0x0) goto LAB_0063386c;
      goto LAB_0063384c;
    }
  }
  puVar8 = puVar5 + 1;
LAB_0063386c:
  puVar5 = (undefined8 *)func_0x00bc3330(0x40);
  *(int *)(puVar5 + 4) = param_3;
  puVar5[6] = 0;
  puVar5[7] = 0;
  puVar5[5] = 0;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = puVar9;
  *puVar8 = puVar5;
  puVar6 = puVar5;
  if (**(long **)(lVar4 + 0x40) != 0) {
    *(long *)(lVar4 + 0x40) = **(long **)(lVar4 + 0x40);
    puVar6 = (undefined8 *)*puVar8;
  }
  func_0x0040a8c0(*(undefined8 *)(lVar4 + 0x48),puVar6);
  *(long *)(lVar4 + 0x50) = *(long *)(lVar4 + 0x50) + 1;
LAB_006337b4:
  puVar5 = puVar5 + 5;
LAB_00633818:
  if (*(long *)(lVar1 + 0x28) != lStack_48) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380(puVar5);
  }
  return;
}


