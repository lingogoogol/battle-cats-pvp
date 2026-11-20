// ELF VMA: 0x920824
// Ghidra Addr: 0x00a20824 (ImageBase=0x100000)
// Size: 684 bytes


bool BattleFn_0x00920824(int param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  bool bVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  long lVar10;
  int iVar11;
  int aiStack_98 [2];
  long lStack_90;
  long lStack_88;
  long lStack_68;
  
  lVar1 = tpidr_el0;
  lStack_68 = *(long *)(lVar1 + 0x28);
  if (param_1 == 3) {
    bVar7 = false;
  }
  else {
    lVar10 = 0;
    do {
      lVar2 = func_0x007fd748();
      func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar2,param_1,param_2);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
      lVar2 = (long)aiStack_98[0];
      bVar7 = lVar2 <= lVar10;
      if (lStack_90 != 0) {
        lStack_88 = lStack_90;
        func_0x00bc3350();
      }
      if (lVar2 <= lVar10) {
        bVar7 = true;
        break;
      }
      lVar2 = func_0x007fd748();
      func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar2,param_1,param_2);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
      iVar11 = *(int *)(lStack_90 + lVar10 * 4);
      lStack_88 = lStack_90;
      func_0x00bc3350();
      if (iVar11 < 0x2e) {
        lVar2 = func_0x007fd748();
        func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar2,param_1,param_2);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        iVar11 = 0x2d - *(int *)(lStack_90 + lVar10 * 4);
      }
      else {
        lVar2 = func_0x007fd748();
        func_0x00a1f908(aiStack_98,&UNK_00290568 + lVar2,param_1,param_2);  /* UNK_290568(vma=0x190568)='alloc can only be used with a table or struct definition' */
        iVar11 = *(int *)(lStack_90 + lVar10 * 4);
      }
      lStack_88 = lStack_90;
      func_0x00bc3350();
      lVar2 = func_0x007fd748();
      puVar8 = (undefined8 *)(&UNK_0032c648 + lVar2);  /* field_off=0x32c648 */
      puVar5 = (undefined8 *)*puVar8;
      puVar9 = puVar8;
      if ((undefined8 *)*puVar8 != (undefined8 *)0x0) {
        do {
          while (puVar3 = puVar5, puVar9 = puVar3, param_1 < *(int *)(puVar3 + 4)) {
            puVar5 = (undefined8 *)*puVar3;
            puVar8 = puVar3;
            if ((undefined8 *)*puVar3 == (undefined8 *)0x0) goto LAB_00a209b0;
          }
          if (param_1 <= *(int *)(puVar3 + 4)) goto LAB_00a20a0c;
          puVar5 = (undefined8 *)puVar3[1];
        } while ((undefined8 *)puVar3[1] != (undefined8 *)0x0);
        puVar8 = puVar3 + 1;
      }
LAB_00a209b0:
      puVar3 = (undefined8 *)func_0x00bc3330(0x40);
      *(int *)(puVar3 + 4) = param_1;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[5] = puVar3 + 6;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = puVar9;
      *puVar8 = puVar3;
      lVar6 = **(long **)(&UNK_0032c640 + lVar2);  /* field_off=0x32c640 */
      puVar5 = puVar3;
      if (lVar6 != 0) {
        *(long *)(&UNK_0032c640 + lVar2) = lVar6;  /* field_off=0x32c640 */
        puVar5 = (undefined8 *)*puVar8;
      }
      func_0x0040a8c0(*(undefined8 *)(&UNK_0032c648 + lVar2),puVar5);  /* field_off=0x32c648 */
      *(long *)(&UNK_0032c650 + lVar2) = *(long *)(&UNK_0032c650 + lVar2) + 1;  /* field_off=0x32c650 ; field_off=0x32c650 */
LAB_00a20a0c:
      puVar8 = puVar3 + 6;
      puVar5 = (undefined8 *)*puVar8;
      puVar9 = puVar8;
      if ((undefined8 *)*puVar8 != (undefined8 *)0x0) {
        do {
          while (puVar4 = puVar5, puVar9 = puVar4, iVar11 < *(int *)((long)puVar4 + 0x1c)) {
            puVar5 = (undefined8 *)*puVar4;
            puVar8 = puVar4;
            if ((undefined8 *)*puVar4 == (undefined8 *)0x0) goto LAB_00a20a50;
          }
          if (iVar11 <= *(int *)((long)puVar4 + 0x1c)) goto LAB_00a20890;
          puVar5 = (undefined8 *)puVar4[1];
        } while ((undefined8 *)puVar4[1] != (undefined8 *)0x0);
        puVar8 = puVar4 + 1;
      }
LAB_00a20a50:
      puVar4 = (undefined8 *)func_0x00bc3330(0x28);
      *(int *)((long)puVar4 + 0x1c) = iVar11;
      *(undefined1 *)(puVar4 + 4) = 0;
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = puVar9;
      *puVar8 = puVar4;
      puVar5 = puVar4;
      if (*(long *)puVar3[5] != 0) {
        puVar3[5] = *(long *)puVar3[5];
        puVar5 = (undefined8 *)*puVar8;
      }
      func_0x0040a8c0(puVar3[6],puVar5);
      puVar3[7] = puVar3[7] + 1;
LAB_00a20890:
      lVar10 = lVar10 + 1;
    } while (*(char *)(puVar4 + 4) != '\0');
  }
  if (*(long *)(lVar1 + 0x28) != lStack_68) {
                    /* WARNING: Subroutine does not return */
    NoRet_0x00ac3380();
  }
  return bVar7;
}


