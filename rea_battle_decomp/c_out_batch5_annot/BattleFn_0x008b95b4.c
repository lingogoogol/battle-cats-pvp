// ELF VMA: 0x8b95b4
// Ghidra Addr: 0x009b95b4 (ImageBase=0x100000)
// Size: 1164 bytes


/* WARNING: Possible PIC construction at 0x009b9970: Changing call to branch */

void BattleFn_0x008b95b4(undefined8 param_1,long param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong unaff_x19;
  ulong uVar8;
  ulong unaff_x20;
  ulong uVar9;
  long unaff_x21;
  undefined1 *unaff_x29;
  undefined8 unaff_x30;
  undefined1 auStack_60 [8];
  undefined4 uStack_58;
  undefined1 uStack_51;
  undefined4 *puStack_50;
  long lStack_48;
  
  puVar1 = &stack0xffffffffffffffc0;
  lVar7 = tpidr_el0;
  lStack_48 = *(long *)(lVar7 + 0x28);
  uVar8 = (ulong)param_4;
  uVar9 = (ulong)param_3;
  uVar2 = func_0x005ab2d8(param_3,param_4);
  iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
  if (iVar3 != 0) {
    iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
    if (iVar3 != 1) {
      iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
      if (iVar3 == 2) {
        func_0x005acf30(param_2,uVar9,uVar2,2);
        iVar3 = func_0x0044003c();
        if ((param_3 == 0) && (iVar3 == -1)) {
          iVar3 = func_0x00a590bc(0,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          func_0x005acf30(param_2,0,uVar2,2);
          iVar4 = func_0x004400b4();
          if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
          iVar5 = 0;
          if (iVar4 != 0) {
            iVar5 = (iVar3 + 1) / iVar4;
          }
          iVar3 = (iVar3 + 1) - iVar5 * iVar4;
          param_3 = 0;
        }
        else {
          iVar3 = func_0x00a590bc(param_3,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          func_0x005acf30(param_2,uVar9,uVar2,2);
          iVar4 = func_0x0044003c();
          if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
          iVar5 = 0;
          if (iVar4 != 0) {
            iVar5 = (iVar3 + 1) / iVar4;
          }
          iVar3 = (iVar3 + 1) - iVar5 * iVar4;
        }
        goto SUB_00a590fc;
      }
      iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
      if (iVar3 == 3) {
        iVar3 = func_0x00a590bc(uVar9,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
        if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
        iVar3 = iVar3 + 1;
        iVar4 = iVar3 / 0x18;
        iVar5 = 0x18;
      }
      else {
        iVar3 = func_0x00a58ba4(param_3,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
        if ((iVar3 == 4) || (iVar3 = func_0x00a58ba4(param_3,uVar8), iVar3 == 0x15))  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
        goto LAB_009b9634;
        iVar3 = func_0x00a58ba4(param_3,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
        if ((iVar3 == 5) || (iVar3 = func_0x00a58ba4(uVar9,uVar8), iVar3 == 6)) {  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
          iVar3 = func_0x00a590bc(uVar9,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
          iVar3 = iVar3 + 1;
          iVar4 = iVar3 / 0xc;
          iVar5 = 0xc;
        }
        else {
          iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
          if (iVar3 != 7) {
            iVar3 = func_0x00a58ba4(uVar9,uVar8);  /* 0x958ba4:[slot*1000,team*51000|off=0x8390c|ldr w0, [x8, x9]] */
            if (iVar3 == 10) {
              uVar6 = func_0x00a59f40(uVar9,uVar8);  /* 0x959f40:[slot*1000,team*51000|off=0x83b08|ldr w8, [x8, x9]] */
              if ((uVar6 & 1) == 0) {
                iVar3 = 1;
              }
              else {
                func_0x005acf30(param_2,uVar9,uVar2,7);
                iVar3 = func_0x0044003c();
                if (iVar3 < 2) {
                  iVar3 = 1;
                }
              }
              iVar5 = func_0x00a59e28(uVar9,uVar8);  /* 0x959e28:[slot*1000,team*51000|off=0x83b00|ldr w0, [x8, x9]] */
              iVar4 = iVar3;
              if (-1 < iVar5) {
                uStack_58 = func_0x00a59e28(uVar9,uVar8);  /* 0x959e28:[slot*1000,team*51000|off=0x83b00|ldr w0, [x8, x9]] */
                puStack_50 = &uStack_58;
                lVar7 = func_0x0064bd28(param_2 + 0x33a8,&uStack_58,&UNK_002afa25,&puStack_50,  /* UNK_2afa25(vma=0x1afa25)='u32=0x74534e00(1951616512) f32=6.697e+31' */
                                        &uStack_51);
                iVar4 = func_0x0044003c(lVar7 + 0x28);
                if (iVar4 <= iVar3) {
                  iVar4 = iVar3;
                }
              }
              iVar5 = func_0x00a590bc(uVar9,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
              iVar3 = 0;
              if (iVar4 != 0) {
                iVar3 = (iVar5 + 1) / iVar4;
              }
              iVar3 = (iVar5 + 1) - iVar3 * iVar4;
              unaff_x30 = 0x9b9974;
              register0x00000008 = (BADSPACEBASE *)auStack_60;
              unaff_x19 = uVar8;
              unaff_x20 = uVar9;
              unaff_x21 = param_2;
              unaff_x29 = puVar1;
              goto SUB_00a590fc;
            }
            if (*(long *)(lVar7 + 0x28) == lStack_48) {
              return;
            }
            goto LAB_009b999c;
          }
          iVar3 = func_0x00a590bc(uVar9,uVar8);  /* 0x9590bc:[slot*1000,team*51000|off=0x83910|ldr w0, [x8, x9]] */
          if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
          iVar3 = iVar3 + 1;
          iVar4 = iVar3 / 0x30;
          iVar5 = 0x30;
        }
      }
      iVar3 = iVar3 - iVar4 * iVar5;
SUB_00a590fc:
      *(undefined1 **)((long)register0x00000008 + -0x30) = unaff_x29;
      *(undefined8 *)((long)register0x00000008 + -0x28) = unaff_x30;
      *(long *)((long)register0x00000008 + -0x20) = unaff_x21;
      *(ulong *)((long)register0x00000008 + -0x10) = unaff_x20;
      *(ulong *)((long)register0x00000008 + -8) = unaff_x19;
      lVar7 = func_0x007fd748();
      *(int *)(lVar7 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000 + 0x83910) = iVar3;
      return;
    }
    func_0x005acf30(param_2,uVar9,uVar2,1);
    iVar3 = func_0x004400b4();
    if (iVar3 == 0) {
      if (*(long *)(lVar7 + 0x28) != lStack_48) goto LAB_009b999c;
      iVar3 = 0;
      goto SUB_00a590fc;
    }
  }
LAB_009b9634:
  if (*(long *)(lVar7 + 0x28) == lStack_48) {
    lVar7 = func_0x007fd748();
    lVar7 = lVar7 + (long)(int)param_3 * 51000 + (long)(int)param_4 * 1000;
    *(int *)(lVar7 + 0x83910) = *(int *)(lVar7 + 0x83910) + 1;
    return;
  }
LAB_009b999c:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


