// ELF VMA: 0x4df9b8
// Ghidra Addr: 0x005df9b8 (ImageBase=0x100000)
// Size: 392 bytes


undefined8 * BattleFn_0x004df9b8(long *param_1,undefined8 *param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  long *plVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  lVar12 = param_1[1] - *param_1;
  lVar7 = lVar12 >> 3;
  uVar1 = lVar7 * -0x5555555555555555 + 1;
  if (uVar1 < 0xaaaaaaaaaaaaaab) {
    lVar8 = param_1[2] - *param_1 >> 3;
    uVar9 = lVar8 * 0x5555555555555556;
    if (uVar9 < uVar1 || uVar9 - uVar1 == 0) {
      uVar9 = uVar1;
    }
    if (0x555555555555554 < (ulong)(lVar8 * -0x5555555555555555)) {
      uVar9 = 0xaaaaaaaaaaaaaaa;
    }
    if (uVar9 < 0xaaaaaaaaaaaaaab) {
      lVar8 = func_0x00bc3330(uVar9 * 0x18);
      uVar14 = param_2[2];
      uVar13 = param_2[1];
      param_2[1] = 0;
      param_2[2] = 0;
      lVar7 = lVar8 + lVar7 * 8;
      uVar10 = *param_2;
      *param_2 = 0;
      puVar3 = (undefined8 *)(lVar8 + lVar12);
      plVar4 = (long *)*param_1;
      plVar5 = (long *)param_1[1];
      lVar8 = lVar8 + uVar9 * 0x18;
      puVar2 = puVar3 + 3;
      *puVar3 = uVar10;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined8 *)(lVar7 + 0x10) = uVar14;
      *(undefined8 *)(lVar7 + 8) = uVar13;
      if (plVar5 == plVar4) {
        *param_1 = (long)puVar3;
        param_1[1] = (long)puVar2;
        param_1[2] = lVar8;
      }
      else {
        lVar7 = 0;
        do {
          lVar12 = lVar7 + -0x18;
          uVar10 = *(undefined8 *)((long)plVar5 + lVar7 + -0x18);
          *(undefined8 *)((long)puVar3 + lVar7 + -0x10) =
               *(undefined8 *)((long)plVar5 + lVar7 + -0x10);
          *(undefined8 *)((long)puVar3 + lVar7 + -0x18) = uVar10;
          *(undefined8 *)((long)puVar3 + lVar7 + -8) = *(undefined8 *)((long)plVar5 + lVar7 + -8);
          *(undefined8 *)((long)plVar5 + lVar7 + -0x18) = 0;
          *(undefined8 *)((long)plVar5 + lVar7 + -0x10) = 0;
          *(undefined8 *)((long)plVar5 + lVar7 + -8) = 0;
          lVar7 = lVar12;
        } while ((long *)((long)plVar5 + lVar12) != plVar4);
        plVar4 = (long *)*param_1;
        plVar5 = (long *)param_1[1];
        *param_1 = (long)puVar3 + lVar12;
        param_1[1] = (long)puVar2;
        param_1[2] = lVar8;
        plVar11 = plVar5;
        while (plVar6 = plVar11, plVar6 != plVar4) {
          plVar11 = plVar6 + -3;
          lVar7 = *plVar11;
          plVar5 = plVar4;
          if (lVar7 != 0) {
            plVar6[-2] = lVar7;
            func_0x00bc3350(lVar7);
          }
        }
      }
      if (plVar5 != (long *)0x0) {
        func_0x00bc3350();
      }
      return puVar2;
    }
  }
  else {
    func_0x005dfbb0(param_1);
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x0030fc1c();
}


