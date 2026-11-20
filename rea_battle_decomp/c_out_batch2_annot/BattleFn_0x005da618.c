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
  
  puVar1 = (uint *)(&UNK_0038816c + param_1);  /* field_off=0x38816c */
  *(undefined8 *)(&UNK_00388184 + param_1) = 0;  /* field_off=0x388184 */
  *(undefined8 *)(&UNK_0038817c + param_1) = 0;  /* field_off=0x38817c */
  *(undefined8 *)(&UNK_00388194 + param_1) = 0;  /* field_off=0x388194 */
  *(undefined8 *)(&UNK_0038818c + param_1) = 0;  /* field_off=0x38818c */
  *(undefined8 *)(&UNK_00388174 + param_1) = 0;  /* field_off=0x388174 */
  puVar1[0] = 0;
  puVar1[1] = 0;
  uVar4 = func_0x00a5a878(param_2,param_3,param_4);  /* 0x95a878:[slot*1000,team*51000|off=0x83908|ldr w8, [x8, x9]] */
  if ((uVar4 & 1) != 0) {
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5e9a8(param_2,param_3);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
    *puVar1 = (uint)(iVar2 < iVar3);
    uVar4 = func_0x00a5e960(param_2,param_3);  /* 0x95e960:[slot*1000,team*51000|off=0x839e8|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5e9a8(param_2,param_3);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
      func_0x00a5e9a8(param_2,param_3);  /* 0x95e9a8:[slot*1000,team*51000|off=0x839e8|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5c568(param_2,param_3);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388170 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388170 */
    uVar4 = func_0x00a5c520(param_2,param_3);  /* 0x95c520:[slot*1000,team*51000|off=0x839cc|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5c568(param_2,param_3);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
      func_0x00a5c568(param_2,param_3);  /* 0x95c568:[slot*1000,team*51000|off=0x839cc|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dbe4(param_2,param_3);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388174 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388174 */
    uVar4 = func_0x00a5db9c(param_2,param_3);  /* 0x95db9c:[slot*1000,team*51000|off=0x839d0|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5dbe4(param_2,param_3);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
      func_0x00a5dbe4(param_2,param_3);  /* 0x95dbe4:[slot*1000,team*51000|off=0x839d0|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dd44(param_2,param_3);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388178 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388178 */
    uVar4 = func_0x00a5dcfc(param_2,param_3);  /* 0x95dcfc:[slot*1000,team*51000|off=0x839d8|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5dd44(param_2,param_3);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
      func_0x00a5dd44(param_2,param_3);  /* 0x95dd44:[slot*1000,team*51000|off=0x839d8|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5dea4(param_2,param_3);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_0038817c + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x38817c */
    uVar4 = func_0x00a5de5c(param_2,param_3);  /* 0x95de5c:[slot*1000,team*51000|off=0x83a18|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5dea4(param_2,param_3);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
      func_0x00a5dea4(param_2,param_3);  /* 0x95dea4:[slot*1000,team*51000|off=0x83a18|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5cfc0(param_2,param_3);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388180 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388180 */
    uVar4 = func_0x00a5cf78(param_2,param_3);  /* 0x95cf78:[slot*1000,team*51000|off=0x83b94|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5cfc0(param_2,param_3);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
      func_0x00a5cfc0(param_2,param_3);  /* 0x95cfc0:[slot*1000,team*51000|off=0x83b94|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5cd48(param_2,param_3);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388184 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388184 */
    uVar4 = func_0x00a5cd00(param_2,param_3);  /* 0x95cd00:[slot*1000,team*51000|off=0x83b24|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5cd48(param_2,param_3);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
      func_0x00a5cd48(param_2,param_3);  /* 0x95cd48:[slot*1000,team*51000|off=0x83b24|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5f0e0(param_2,param_3);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388188 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388188 */
    uVar4 = func_0x00a5f098(param_2,param_3);  /* 0x95f098:[slot*1000,team*51000|off=0x83b18|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5f0e0(param_2,param_3);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
      func_0x00a5f0e0(param_2,param_3);  /* 0x95f0e0:[slot*1000,team*51000|off=0x83b18|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5e090(param_2,param_3);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_0038818c + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x38818c */
    uVar4 = func_0x00a5e048(param_2,param_3);  /* 0x95e048:[slot*1000,team*51000|off=0x83b54|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5e090(param_2,param_3);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
      func_0x00a5e090(param_2,param_3);  /* 0x95e090:[slot*1000,team*51000|off=0x83b54|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5d048(param_2,param_3);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388190 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388190 */
    uVar4 = func_0x00a5d000(param_2,param_3);  /* 0x95d000:[slot*1000,team*51000|off=0x83bb4|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5d048(param_2,param_3);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
      func_0x00a5d048(param_2,param_3);  /* 0x95d048:[slot*1000,team*51000|off=0x83bb4|ldr w0, [x8, x9]] */
    }
    iVar2 = func_0x0043ea60(100);
    iVar3 = func_0x00a5f1b4(param_2,param_3);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
    *(uint *)(&UNK_00388194 + param_1) = (uint)(iVar2 < iVar3);  /* field_off=0x388194 */
    uVar4 = func_0x00a5f16c(param_2,param_3);  /* 0x95f16c:[slot*1000,team*51000|off=0x83be4|ldr w8, [x8, x9]] */
    if ((uVar4 & 1) != 0) {
      func_0x00a5f1b4(param_2,param_3);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
      func_0x00a5f1b4(param_2,param_3);  /* 0x95f1b4:[slot*1000,team*51000|off=0x83be4|ldr w0, [x8, x9]] */
    }
    func_0x0043ea60(100);
    lVar5 = func_0x007fd748();
    return (ulong)*(uint *)(lVar5 + (long)param_2 * 51000 + (long)param_3 * 1000 + 0x83ce0);
  }
  return uVar4;
}


