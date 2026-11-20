// ELF VMA: 0x004c5990 | Ghidra Addr: 0x005c5990 | BodySize: 308

void BattleFn_0x004c5990(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  undefined8 *puVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0xb848);
  *(undefined8 *)(&UNK_00440c90 + param_1) = 0;
  *(undefined8 *)(&UNK_00440c88 + param_1) = 0;
  *(undefined8 *)(param_1 + 0x440c9c) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x440ca4) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x440cac) = 0xffffffff;
  *(undefined8 *)(param_1 + 0xb848) = 0;
  *(undefined8 *)(param_1 + 0xb840) = 0;
  if ((plVar5 != (long *)0x0) &&
     (lVar2 = func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), lVar2 == 0)) {
    (**(code **)(*plVar5 + 0x10))(plVar5);
    func_0x00bc3320(plVar5);
  }
  plVar5 = *(long **)(param_1 + 0xb858);
  *(undefined8 *)(param_1 + 0xb850) = 0;
  *(undefined8 *)(param_1 + 0xb858) = 0;
  if ((plVar5 != (long *)0x0) &&
     (lVar2 = func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), lVar2 == 0)) {
    (**(code **)(*plVar5 + 0x10))(plVar5);
    func_0x00bc3320(plVar5);
  }
  plVar5 = *(long **)(param_1 + 0xb868);
  *(undefined8 *)(param_1 + 0xb860) = 0;
  *(undefined8 *)(param_1 + 0xb868) = 0;
  if ((plVar5 != (long *)0x0) &&
     (lVar2 = func_0x00bbf1b0(0xffffffffffffffff,plVar5 + 1), lVar2 == 0)) {
    (**(code **)(*plVar5 + 0x10))(plVar5);
    func_0x00bc3320(plVar5);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x4407f0);
  for (puVar4 = *(undefined8 **)(param_1 + 0x4407e8); puVar4 != puVar1; puVar4 = puVar4 + 2) {
    uVar3 = func_0x00877c64(*puVar4);
    if ((uVar3 & 1) != 0) {
      func_0x00877c6c(*puVar4,0);
    }
  }
  return;
}


