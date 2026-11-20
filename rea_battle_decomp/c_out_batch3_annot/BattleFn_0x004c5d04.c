// ELF VMA: 0x004c5d04 | Ghidra Addr: 0x005c5d04 | BodySize: 132

void BattleFn_0x004c5d04(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if (lRam0000000000c0b8b8 == 0) {
    lVar3 = 0;
    iVar1 = *(int *)(param_1 + 0x12b8);
  }
  else {
    lVar3 = func_0x00bc3a90(lRam0000000000c0b8b8,
                            &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                            &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
    iVar1 = *(int *)(param_1 + 0x12b8);
  }
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x12b8) = iVar1 + 1;
    iVar2 = func_0x0044003c(lVar3 + 0x16220);
    if (iVar2 + 0x1d <= iVar1) {
      *(undefined4 *)(param_1 + 0x12b8) = 0xffffffff;
    }
  }
  return;
}


