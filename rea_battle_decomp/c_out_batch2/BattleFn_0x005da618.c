// ELF VMA: 0x5da618
// Ghidra Addr: 0x006da618 (ImageBase=0x100000)
// Size: 1088 bytes


/* WARNING: Possible PIC construction at 0x006da9bc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006da9e4: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006da9c0) */
/* WARNING: Removing unreachable block (ram,0x006da9dc) */
/* WARNING: Removing unreachable block (ram,0x006da9e8) */

ulong BattleFn_0x005da618(long param_1,int param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  
  puVar1 = (uint *)(&UNK_0038816c + param_1);
  *(undefined8 *)(&UNK_00388184 + param_1) = 0;
  *(undefined8 *)(&UNK_0038817c + param_1) = 0;
  *(undefined8 *)(&UNK_00388194 + param_1) = 0;
  *(undefined8 *)(&UNK_0038818c + param_1) = 0;
  *(undefined8 *)(&UNK_00388174 + param_1) = 0;
  puVar1[0] = 0;
  puVar1[1] = 0;
  uVar4 = func_0x00a5a878(param_2,param_3,param_4);
  if ((uVar4 & 1) != 0) {
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5e9a8(param_2,param_3);
    *puVar1 = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5e960(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5e9a8(param_2,param_3);
      func_0x00a5e9a8(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5c568(param_2,param_3);
    *(uint *)(&UNK_00388170 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5c520(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5c568(param_2,param_3);
      func_0x00a5c568(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dbe4(param_2,param_3);
    *(uint *)(&UNK_00388174 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5db9c(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5dbe4(param_2,param_3);
      func_0x00a5dbe4(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dd44(param_2,param_3);
    *(uint *)(&UNK_00388178 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5dcfc(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5dd44(param_2,param_3);
      func_0x00a5dd44(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dea4(param_2,param_3);
    *(uint *)(&UNK_0038817c + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5de5c(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5dea4(param_2,param_3);
      func_0x00a5dea4(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5cfc0(param_2,param_3);
    *(uint *)(&UNK_00388180 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5cf78(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5cfc0(param_2,param_3);
      func_0x00a5cfc0(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5cd48(param_2,param_3);
    *(uint *)(&UNK_00388184 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5cd00(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5cd48(param_2,param_3);
      func_0x00a5cd48(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5f0e0(param_2,param_3);
    *(uint *)(&UNK_00388188 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5f098(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5f0e0(param_2,param_3);
      func_0x00a5f0e0(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5e090(param_2,param_3);
    *(uint *)(&UNK_0038818c + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5e048(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5e090(param_2,param_3);
      func_0x00a5e090(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5d048(param_2,param_3);
    *(uint *)(&UNK_00388190 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5d000(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5d048(param_2,param_3);
      func_0x00a5d048(param_2,param_3);
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5f1b4(param_2,param_3);
    *(uint *)(&UNK_00388194 + param_1) = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5f16c(param_2,param_3);
    if ((uVar4 & 1) != 0) {
      func_0x00a5f1b4(param_2,param_3);
      func_0x00a5f1b4(param_2,param_3);
    }
    func_0x0043ea60(100);
    lVar5 = func_0x007fd748();
    return (ulong)*(uint *)(lVar5 + (long)param_2 * 51000 + (long)param_3 * 1000 + 0x83ce0);
  }
  return uVar4;
}


