// ELF VMA: 0x004c51bc | Ghidra Addr: 0x005c51bc | BodySize: 1968

/* WARNING: Possible PIC construction at 0x005c527c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c52b8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c5460: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c549c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c54d8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c55dc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c560c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c5698: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c56c8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c5768: Changing call to branch */
/* WARNING: Possible PIC construction at 0x005c5798: Changing call to branch */

void BattleFn_0x004c51bc(long param_1)

{
  long *plVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  undefined8 *puVar14;
  long *plVar15;
  byte abStack_98 [16];
  undefined8 uStack_88;
  undefined8 uStack_80;
  long *plStack_78;
  long lStack_68;
  
  lVar6 = tpidr_el0;
  lStack_68 = *(long *)(lVar6 + 0x28);
  plVar1 = (long *)(param_1 + 0x4407e8);
  puVar14 = (undefined8 *)*plVar1;
  puVar4 = *(undefined8 **)(param_1 + 0x4407f0);
  puVar3 = (undefined8 *)(param_1 + 0xb848);
  if (puVar14 != puVar4) {
    do {
      uVar12 = func_0x00877c64(*puVar14);
      if ((uVar12 & 1) != 0) {
        iVar11 = *(int *)(&UNK_00440c88 + param_1);
        iVar9 = *(int *)(param_1 + 0x440c78);
        *(int *)(&UNK_00440c88 + param_1) = iVar11 + 1;
        *(int *)(&LAB_00440c98 + param_1) = *(int *)(&LAB_00440c98 + param_1) + 1;
        if (iVar11 + 1 < iVar9) goto LAB_005c5828;
        iVar11 = *(int *)(&UNK_00440c94 + param_1);
        piVar2 = (int *)(&UNK_00440c8c + param_1);
        *(int *)(&UNK_00440c88 + param_1) = iVar9;
        *(int *)(&UNK_00440c8c + param_1) = *(int *)(&UNK_00440c8c + param_1) + 1;
        *(int *)(&UNK_00440c94 + param_1) = iVar11 + 1;
        if (*(int *)(&UNK_00440c84 + param_1) <= iVar11 + 1) {
          iVar11 = *(int *)(param_1 + 0x440c80);
          *(int *)(&UNK_00440c94 + param_1) = *(int *)(&UNK_00440c84 + param_1);
          iVar11 = *(int *)(&UNK_00440c90 + param_1) + iVar11;
          *(int *)(&UNK_00440c90 + param_1) = iVar11;
          iVar9 = func_0x0043dc7c(param_1);
          if (iVar9 <= iVar11) {
            uVar10 = func_0x0043dc7c(param_1);
            *(undefined4 *)(&UNK_00440c90 + param_1) = uVar10;
          }
        }
        iVar11 = *piVar2;
        if (iVar11 != 1) goto LAB_005c5420;
        plVar15 = (long *)*plVar1;
        plVar5 = *(long **)(param_1 + 0x4407f0);
        *(undefined4 *)(param_1 + 0x440cac) = 0xffffffff;
        *(undefined8 *)(param_1 + 0x440c9c) = 0xffffffffffffffff;
        *(undefined8 *)(param_1 + 0x440ca4) = 0xffffffffffffffff;
        if (plVar15 != plVar5) goto LAB_005c53cc;
        iVar11 = 1;
        goto LAB_005c5420;
      }
      puVar14 = puVar14 + 2;
    } while (puVar14 != puVar4);
  }
  plVar15 = (long *)*puVar3;
  *(undefined8 *)(param_1 + 0x440c9c) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x440ca4) = 0xffffffffffffffff;
  *(undefined8 *)(&UNK_00440c90 + param_1) = 0;
  *(undefined8 *)(&UNK_00440c88 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x440cac) = 0xffffffff;
  *(undefined8 *)(param_1 + 0xb848) = 0;
  *(undefined8 *)(param_1 + 0xb840) = 0;
  if ((plVar15 != (long *)0x0) &&
     (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
    (**(code **)(*plVar15 + 0x10))(plVar15);
SUB_00bc3320:
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(plVar15);
    return;
  }
  plVar15 = *(long **)(param_1 + 0xb858);
  *(undefined8 *)(param_1 + 0xb850) = 0;
  *(undefined8 *)(param_1 + 0xb858) = 0;
  if ((plVar15 != (long *)0x0) &&
     (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
    (**(code **)(*plVar15 + 0x10))(plVar15);
    goto SUB_00bc3320;
  }
  plVar15 = *(long **)(param_1 + 0xb868);
  *(undefined8 *)(param_1 + 0xb860) = 0;
  *(undefined8 *)(param_1 + 0xb868) = 0;
  if ((plVar15 != (long *)0x0) &&
     (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
    (**(code **)(*plVar15 + 0x10))(plVar15);
    if (*(long *)(lVar6 + 0x28) == lStack_68) goto SUB_00bc3320;
    goto LAB_005c598c;
  }
  goto LAB_005c5828;
  while (plVar15 = plVar15 + 2, plVar15 != plVar5) {
LAB_005c53cc:
    uVar12 = func_0x00877c64(*plVar15);
    if ((uVar12 & 1) != 0) {
      lVar13 = *plVar15;
      *(undefined4 *)(param_1 + 0x440c9c) = *(undefined4 *)(lVar13 + 0x3c);
      *(undefined4 *)(param_1 + 0x440ca0) = *(undefined4 *)(lVar13 + 0x40);
      *(undefined4 *)(param_1 + 0x440ca4) = *(undefined4 *)(lVar13 + 0x44);
      *(undefined4 *)(param_1 + 0x440ca8) = *(undefined4 *)(lVar13 + 0x48);
      *(undefined4 *)(param_1 + 0x440cac) = *(undefined4 *)(lVar13 + 0x4c);
      break;
    }
  }
  iVar11 = *piVar2;
LAB_005c5420:
  if (iVar11 == *(int *)(&UNK_00440c84 + param_1)) {
    plVar15 = (long *)*puVar3;
    *(undefined8 *)(param_1 + 0xb848) = 0;
    *(undefined8 *)(param_1 + 0xb840) = 0;
    if ((plVar15 != (long *)0x0) &&
       (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
      (**(code **)(*plVar15 + 0x10))(plVar15);
      goto SUB_00bc3320;
    }
    plVar15 = *(long **)(param_1 + 0xb858);
    *(undefined8 *)(param_1 + 0xb850) = 0;
    *(undefined8 *)(param_1 + 0xb858) = 0;
    if ((plVar15 != (long *)0x0) &&
       (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
      (**(code **)(*plVar15 + 0x10))(plVar15);
      goto SUB_00bc3320;
    }
    plVar15 = *(long **)(param_1 + 0xb868);
    *(undefined8 *)(param_1 + 0xb860) = 0;
    *(undefined8 *)(param_1 + 0xb868) = 0;
    if ((plVar15 != (long *)0x0) &&
       (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
      (**(code **)(*plVar15 + 0x10))(plVar15);
      goto SUB_00bc3320;
    }
    plVar15 = *(long **)(param_1 + 0x4407f0);
    for (plVar5 = (long *)*plVar1; plVar5 != plVar15; plVar5 = plVar5 + 2) {
      uVar12 = func_0x00877c64(*plVar5);
      if ((uVar12 & 1) != 0) {
        if (((bRam0000000000c0be90 & 1) == 0) && (iVar11 = func_0x00bc32f0(0xc0be90), iVar11 != 0))
        {
          uRam0000000000c0be60 = 0;
          uRam0000000000c0be58 = 0xc0be60;
          uRam0000000000c0be80 = 0;
          uRam0000000000c0be88 = 0;
          uRam0000000000c0be78 = 0;
          uRam0000000000c0be68 = 0;
          uRam0000000000c0be70 = 0xc0be78;
          func_0x00bc32d0(&UNK_00450320,0xc0be58,&DAT_00bce2b0);
          func_0x00bc3310(0xc0be90);
        }
        func_0x0086f220(abStack_98,*plVar5,0);
        func_0x0044fe48(&uStack_80,0xc0be58,abStack_98,&DAT_00c0bf30,0x28,1,0,0);
        plVar8 = plStack_78;
        uVar7 = uStack_80;
        plVar15 = (long *)*puVar3;
        uStack_80 = 0;
        plStack_78 = (long *)0x0;
        *(long **)(param_1 + 0xb848) = plVar8;
        *(undefined8 *)(param_1 + 0xb840) = uVar7;
        if ((plVar15 != (long *)0x0) &&
           (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          goto SUB_00bc3320;
        }
        plVar15 = plStack_78;
        if ((plStack_78 != (long *)0x0) &&
           (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plStack_78 + 1), lVar13 == 0)) {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          goto SUB_00bc3320;
        }
        if ((abStack_98[0] & 1) != 0) {
          func_0x00bc3350(uStack_88);
        }
        if (((bRam0000000000c0be90 & 1) == 0) && (iVar11 = func_0x00bc32f0(0xc0be90), iVar11 != 0))
        {
          uRam0000000000c0be60 = 0;
          uRam0000000000c0be58 = 0xc0be60;
          uRam0000000000c0be80 = 0;
          uRam0000000000c0be88 = 0;
          uRam0000000000c0be78 = 0;
          uRam0000000000c0be68 = 0;
          uRam0000000000c0be70 = 0xc0be78;
          func_0x00bc32d0(&UNK_00450320,0xc0be58,&DAT_00bce2b0);
          func_0x00bc3310(0xc0be90);
        }
        func_0x0086f220(abStack_98,*plVar5,1);
        func_0x0044fe48(&uStack_80,0xc0be58,abStack_98,&DAT_00c0bf30,0x1a,1,0,0);
        plVar8 = plStack_78;
        uVar7 = uStack_80;
        plVar15 = *(long **)(param_1 + 0xb858);
        uStack_80 = 0;
        plStack_78 = (long *)0x0;
        *(long **)(param_1 + 0xb858) = plVar8;
        *(undefined8 *)(param_1 + 0xb850) = uVar7;
        if ((plVar15 != (long *)0x0) &&
           (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          goto SUB_00bc3320;
        }
        plVar15 = plStack_78;
        if ((plStack_78 != (long *)0x0) &&
           (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plStack_78 + 1), lVar13 == 0)) {
          (**(code **)(*plVar15 + 0x10))(plVar15);
          goto SUB_00bc3320;
        }
        if ((abStack_98[0] & 1) != 0) {
          func_0x00bc3350(uStack_88);
        }
        if (*(int *)(*plVar5 + 0x10) != -1) {
          if (((bRam0000000000c0be90 & 1) == 0) && (iVar11 = func_0x00bc32f0(0xc0be90), iVar11 != 0)
             ) {
            uRam0000000000c0be60 = 0;
            uRam0000000000c0be58 = 0xc0be60;
            uRam0000000000c0be80 = 0;
            uRam0000000000c0be88 = 0;
            uRam0000000000c0be78 = 0;
            uRam0000000000c0be68 = 0;
            uRam0000000000c0be70 = 0xc0be78;
            func_0x00bc32d0(&UNK_00450320,0xc0be58,&DAT_00bce2b0);
            func_0x00bc3310(0xc0be90);
          }
          func_0x0086f220(abStack_98,*plVar5,2);
          func_0x0044fe48(&uStack_80,0xc0be58,abStack_98,&DAT_00c0bf30,0x1a,1,0,0);
          plVar5 = plStack_78;
          uVar7 = uStack_80;
          plVar15 = *(long **)(param_1 + 0xb868);
          uStack_80 = 0;
          plStack_78 = (long *)0x0;
          *(long **)(param_1 + 0xb868) = plVar5;
          *(undefined8 *)(param_1 + 0xb860) = uVar7;
          if ((plVar15 != (long *)0x0) &&
             (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plVar15 + 1), lVar13 == 0)) {
            (**(code **)(*plVar15 + 0x10))(plVar15);
            goto SUB_00bc3320;
          }
          plVar15 = plStack_78;
          if ((plStack_78 != (long *)0x0) &&
             (lVar13 = func_0x00bbf1b0(0xffffffffffffffff,plStack_78 + 1), lVar13 == 0)) {
            (**(code **)(*plVar15 + 0x10))(plVar15);
            goto SUB_00bc3320;
          }
          if ((abStack_98[0] & 1) != 0) {
            func_0x00bc3350(uStack_88);
          }
        }
        break;
      }
    }
  }
  if (*(int *)(param_1 + 0x440c7c) <= *(int *)(&UNK_00440c8c + param_1)) {
    puVar14 = (undefined8 *)*plVar1;
    puVar3 = *(undefined8 **)(param_1 + 0x4407f0);
    piVar2[0] = 0;
    piVar2[1] = 0;
    *(undefined4 *)(&UNK_00440c94 + param_1) = 0;
    *(undefined8 *)(param_1 + 0x440c9c) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x440ca4) = 0xffffffffffffffff;
    *(undefined4 *)(param_1 + 0x440cac) = 0xffffffff;
    for (; puVar14 != puVar3; puVar14 = puVar14 + 2) {
      uVar12 = func_0x00877c64(*puVar14);
      if ((uVar12 & 1) != 0) {
        func_0x00877c6c(*puVar14,0);
        break;
      }
    }
  }
  plVar15 = *(long **)(param_1 + 0x4407f0);
  for (plVar1 = (long *)*plVar1; plVar1 != plVar15; plVar1 = plVar1 + 2) {
    uVar12 = func_0x00877c64(*plVar1);
    if ((uVar12 & 1) != 0) {
      iVar11 = 0;
      if (*(int *)(*plVar1 + 0x10) != -1) {
        iVar11 = 0xf;
      }
      goto LAB_005c57fc;
    }
  }
  iVar11 = 0;
LAB_005c57fc:
  uVar12 = func_0x00807844(param_1);
  if (((uVar12 & 1) != 0) &&
     (uVar12 = func_0x0098aef0(param_1,*(undefined4 *)(&UNK_00328234 + param_1),
                               *(int *)(&UNK_00328238 + param_1) + iVar11,
                               *(undefined4 *)(&UNK_0032823c + param_1),
                               *(undefined4 *)(&UNK_00328240 + param_1)), (uVar12 & 1) != 0)) {
    BattleFn_0x004c5990(param_1);
  }
LAB_005c5828:
  if (*(long *)(lVar6 + 0x28) == lStack_68) {
    return;
  }
LAB_005c598c:
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


