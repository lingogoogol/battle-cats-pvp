// ELF VMA: 0x4b095c
// Ghidra Addr: 0x005b095c (ImageBase=0x100000)
// Size: 1708 bytes


void BattleFn_0x004b095c(long *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  
  plVar9 = param_1 + 1;
  plVar7 = (long *)*plVar9;
  plVar8 = plVar7;
  do {
    if (plVar8 == (long *)0x0) {
      return;
    }
    if (*(int *)((long)plVar8 + 0x1c) <= param_2) {
      if (param_2 <= *(int *)((long)plVar8 + 0x1c)) {
        iVar1 = (int)param_1[3];
        plVar8 = plVar7;
        plVar6 = plVar9;
        if (iVar1 != -1) break;
        goto joined_r0x005b0b0c;
      }
      plVar8 = plVar8 + 1;
    }
    plVar8 = (long *)*plVar8;
  } while( true );
LAB_005b09cc:
  plVar5 = plVar8;
  if (iVar1 < *(int *)((long)plVar5 + 0x1c)) {
    plVar8 = (long *)*plVar5;
    plVar4 = plVar5;
    if ((long *)*plVar5 == (long *)0x0) goto LAB_005b09f8;
    goto LAB_005b09cc;
  }
  if (iVar1 <= *(int *)((long)plVar5 + 0x1c)) goto LAB_005b0a50;
  plVar8 = (long *)plVar5[1];
  if ((long *)plVar5[1] == (long *)0x0) {
    plVar4 = plVar5 + 1;
LAB_005b09f8:
    plVar3 = (long *)func_0x00bc3330(0x40);
    *plVar3 = 0;
    plVar3[1] = 0;
    plVar3[2] = (long)plVar5;
    *(int *)((long)plVar3 + 0x1c) = iVar1;
    plVar3[5] = 0;
    plVar3[4] = 0;
    plVar3[7] = 0;
    plVar3[6] = 0;
    *plVar4 = (long)plVar3;
    plVar8 = plVar3;
    if (*(long *)*param_1 != 0) {
      *param_1 = *(long *)*param_1;
      plVar8 = (long *)*plVar4;
    }
    func_0x0040a8c0(param_1[1],plVar8);
    plVar7 = (long *)param_1[1];
    param_1[2] = param_1[2] + 1;
    plVar5 = plVar3;
LAB_005b0a50:
    iVar1 = *(int *)((long)plVar5 + 0x2c);
    plVar8 = plVar9;
    while (plVar5 = plVar8, plVar7 != (long *)0x0) {
      while (plVar4 = plVar7, plVar8 = plVar4, *(int *)((long)plVar4 + 0x1c) <= param_2) {
        if (param_2 <= *(int *)((long)plVar4 + 0x1c)) goto LAB_005b0ae4;
        plVar7 = (long *)plVar4[1];
        if ((long *)plVar4[1] == (long *)0x0) {
          plVar5 = plVar4 + 1;
          goto LAB_005b0a90;
        }
      }
      plVar7 = (long *)*plVar4;
    }
LAB_005b0a90:
    plVar4 = (long *)func_0x00bc3330(0x40);
    *plVar4 = 0;
    plVar4[1] = 0;
    plVar4[2] = (long)plVar8;
    *(int *)((long)plVar4 + 0x1c) = param_2;
    plVar4[5] = 0;
    plVar4[4] = 0;
    plVar4[7] = 0;
    plVar4[6] = 0;
    *plVar5 = (long)plVar4;
    plVar8 = plVar4;
    if (*(long *)*param_1 != 0) {
      *param_1 = *(long *)*param_1;
      plVar8 = (long *)*plVar5;
    }
    func_0x0040a8c0(param_1[1],plVar8);
    param_1[2] = param_1[2] + 1;
LAB_005b0ae4:
    if ((*(int *)((long)param_1 + 0x1c) != 0 || *(int *)((long)plVar4 + 0x2c) <= iVar1) &&
       (*(int *)((long)param_1 + 0x1c) < 1)) {
      plVar7 = (long *)*plVar9;
      plVar8 = plVar7;
joined_r0x005b0b0c:
      while (plVar5 = plVar6, plVar7 != (long *)0x0) {
        while (plVar6 = plVar7, *(int *)((long)plVar6 + 0x1c) <= param_2) {
          plVar7 = plVar6;
          if (param_2 <= *(int *)((long)plVar6 + 0x1c)) goto LAB_005b0b98;
          plVar7 = (long *)plVar6[1];
          if ((long *)plVar6[1] == (long *)0x0) {
            plVar5 = plVar6 + 1;
            goto LAB_005b0b44;
          }
        }
        plVar7 = (long *)*plVar6;
      }
LAB_005b0b44:
      plVar7 = (long *)func_0x00bc3330(0x40);
      *plVar7 = 0;
      plVar7[1] = 0;
      plVar7[2] = (long)plVar6;
      *(int *)((long)plVar7 + 0x1c) = param_2;
      plVar7[5] = 0;
      plVar7[4] = 0;
      plVar7[7] = 0;
      plVar7[6] = 0;
      *plVar5 = (long)plVar7;
      plVar8 = plVar7;
      if (*(long *)*param_1 != 0) {
        *param_1 = *(long *)*param_1;
        plVar8 = (long *)*plVar5;
      }
      func_0x0040a8c0(param_1[1],plVar8);
      plVar8 = (long *)param_1[1];
      param_1[2] = param_1[2] + 1;
LAB_005b0b98:
      plVar6 = plVar9;
      plVar5 = plVar8;
      plVar4 = plVar9;
      if (0 < *(int *)((long)plVar7 + 0x3c)) {
        while (plVar7 = plVar6, plVar5 != (long *)0x0) {
          while (plVar6 = plVar5, *(int *)((long)plVar6 + 0x1c) <= param_2) {
            plVar5 = plVar6;
            if (param_2 <= *(int *)((long)plVar6 + 0x1c)) goto LAB_005b0c38;
            plVar5 = (long *)plVar6[1];
            if ((long *)plVar6[1] == (long *)0x0) {
              plVar7 = plVar6 + 1;
              goto LAB_005b0be4;
            }
          }
          plVar5 = (long *)*plVar6;
        }
LAB_005b0be4:
        plVar5 = (long *)func_0x00bc3330(0x40);
        *plVar5 = 0;
        plVar5[1] = 0;
        plVar5[2] = (long)plVar6;
        *(int *)((long)plVar5 + 0x1c) = param_2;
        plVar5[5] = 0;
        plVar5[4] = 0;
        plVar5[7] = 0;
        plVar5[6] = 0;
        *plVar7 = (long)plVar5;
        plVar8 = plVar5;
        if (*(long *)*param_1 != 0) {
          *param_1 = *(long *)*param_1;
          plVar8 = (long *)*plVar7;
        }
        func_0x0040a8c0(param_1[1],plVar8);
        plVar8 = (long *)param_1[1];
        param_1[2] = param_1[2] + 1;
LAB_005b0c38:
        lVar2 = plVar5[7];
        plVar7 = plVar9;
        plVar6 = plVar8;
        while (plVar5 = plVar7, plVar6 != (long *)0x0) {
          while (plVar7 = plVar6, *(int *)((long)plVar7 + 0x1c) <= param_2) {
            plVar6 = plVar7;
            if (param_2 <= *(int *)((long)plVar7 + 0x1c)) goto LAB_005b0cd0;
            plVar6 = (long *)plVar7[1];
            if ((long *)plVar7[1] == (long *)0x0) {
              plVar5 = plVar7 + 1;
              goto LAB_005b0c7c;
            }
          }
          plVar6 = (long *)*plVar7;
        }
LAB_005b0c7c:
        plVar6 = (long *)func_0x00bc3330(0x40);
        *plVar6 = 0;
        plVar6[1] = 0;
        plVar6[2] = (long)plVar7;
        *(int *)((long)plVar6 + 0x1c) = param_2;
        plVar6[5] = 0;
        plVar6[4] = 0;
        plVar6[7] = 0;
        plVar6[6] = 0;
        *plVar5 = (long)plVar6;
        plVar8 = plVar6;
        if (*(long *)*param_1 != 0) {
          *param_1 = *(long *)*param_1;
          plVar8 = (long *)*plVar5;
        }
        func_0x0040a8c0(param_1[1],plVar8);
        plVar8 = (long *)param_1[1];
        param_1[2] = param_1[2] + 1;
LAB_005b0cd0:
        plVar7 = plVar9;
        plVar5 = plVar8;
        if (*(int *)((long)plVar6 + 0x3c) <= (int)lVar2) {
          while (plVar6 = plVar7, plVar5 != (long *)0x0) {
            while (plVar7 = plVar5, *(int *)((long)plVar7 + 0x1c) <= param_2) {
              plVar5 = plVar7;
              if (param_2 <= *(int *)((long)plVar7 + 0x1c)) goto LAB_005b0d70;
              plVar5 = (long *)plVar7[1];
              if ((long *)plVar7[1] == (long *)0x0) {
                plVar6 = plVar7 + 1;
                goto LAB_005b0d1c;
              }
            }
            plVar5 = (long *)*plVar7;
          }
LAB_005b0d1c:
          plVar5 = (long *)func_0x00bc3330(0x40);
          *plVar5 = 0;
          plVar5[1] = 0;
          plVar5[2] = (long)plVar7;
          *(int *)((long)plVar5 + 0x1c) = param_2;
          plVar5[5] = 0;
          plVar5[4] = 0;
          plVar5[7] = 0;
          plVar5[6] = 0;
          *plVar6 = (long)plVar5;
          plVar8 = plVar5;
          if (*(long *)*param_1 != 0) {
            *param_1 = *(long *)*param_1;
            plVar8 = (long *)*plVar6;
          }
          func_0x0040a8c0(param_1[1],plVar8);
          plVar8 = (long *)param_1[1];
          param_1[2] = param_1[2] + 1;
LAB_005b0d70:
          *(undefined4 *)(plVar5 + 7) = 0;
          *(undefined4 *)(plVar5 + 6) = 0;
        }
      }
      while (plVar7 = plVar4, plVar8 != (long *)0x0) {
        while (plVar6 = plVar8, plVar4 = plVar6, *(int *)((long)plVar6 + 0x1c) <= param_2) {
          if (param_2 <= *(int *)((long)plVar6 + 0x1c)) goto LAB_005b0e08;
          plVar8 = (long *)plVar6[1];
          if ((long *)plVar6[1] == (long *)0x0) {
            plVar7 = plVar6 + 1;
            goto LAB_005b0db4;
          }
        }
        plVar8 = (long *)*plVar6;
      }
LAB_005b0db4:
      plVar6 = (long *)func_0x00bc3330(0x40);
      *plVar6 = 0;
      plVar6[1] = 0;
      plVar6[2] = (long)plVar4;
      *(int *)((long)plVar6 + 0x1c) = param_2;
      plVar6[5] = 0;
      plVar6[4] = 0;
      plVar6[7] = 0;
      plVar6[6] = 0;
      *plVar7 = (long)plVar6;
      plVar8 = plVar6;
      if (*(long *)*param_1 != 0) {
        *param_1 = *(long *)*param_1;
        plVar8 = (long *)*plVar7;
      }
      func_0x0040a8c0(param_1[1],plVar8);
      param_1[2] = param_1[2] + 1;
LAB_005b0e08:
      if ((int)plVar6[6] == 0) {
        param_1[4] = 0;
        *(int *)(param_1 + 3) = param_2;
        *(undefined4 *)((long)param_1 + 0x1c) = 0;
      }
      plVar8 = (long *)*plVar9;
      plVar7 = plVar9;
      plVar6 = plVar8;
      while (plVar5 = plVar7, plVar6 != (long *)0x0) {
        while (plVar7 = plVar6, *(int *)((long)plVar7 + 0x1c) <= param_2) {
          plVar6 = plVar7;
          if (param_2 <= *(int *)((long)plVar7 + 0x1c)) goto LAB_005b0eb0;
          plVar6 = (long *)plVar7[1];
          if ((long *)plVar7[1] == (long *)0x0) {
            plVar5 = plVar7 + 1;
            goto LAB_005b0e5c;
          }
        }
        plVar6 = (long *)*plVar7;
      }
LAB_005b0e5c:
      plVar6 = (long *)func_0x00bc3330(0x40);
      *plVar6 = 0;
      plVar6[1] = 0;
      plVar6[2] = (long)plVar7;
      *(int *)((long)plVar6 + 0x1c) = param_2;
      plVar6[5] = 0;
      plVar6[4] = 0;
      plVar6[7] = 0;
      plVar6[6] = 0;
      *plVar5 = (long)plVar6;
      plVar8 = plVar6;
      if (*(long *)*param_1 != 0) {
        *param_1 = *(long *)*param_1;
        plVar8 = (long *)*plVar5;
      }
      func_0x0040a8c0(param_1[1],plVar8);
      plVar8 = (long *)param_1[1];
      param_1[2] = param_1[2] + 1;
LAB_005b0eb0:
      lVar2 = plVar6[6];
      *(int *)(plVar6 + 6) = (int)lVar2 + 1;
      plVar7 = plVar9;
      while (plVar6 = plVar7, plVar8 != (long *)0x0) {
        while (plVar5 = plVar8, plVar7 = plVar5, *(int *)((long)plVar5 + 0x1c) <= param_2) {
          if (param_2 <= *(int *)((long)plVar5 + 0x1c)) goto LAB_005b0f4c;
          plVar8 = (long *)plVar5[1];
          if ((long *)plVar5[1] == (long *)0x0) {
            plVar6 = plVar5 + 1;
            goto LAB_005b0ef8;
          }
        }
        plVar8 = (long *)*plVar5;
      }
LAB_005b0ef8:
      plVar5 = (long *)func_0x00bc3330(0x40);
      *plVar5 = 0;
      plVar5[1] = 0;
      plVar5[2] = (long)plVar7;
      *(int *)((long)plVar5 + 0x1c) = param_2;
      plVar5[5] = 0;
      plVar5[4] = 0;
      plVar5[7] = 0;
      plVar5[6] = 0;
      *plVar6 = (long)plVar5;
      plVar8 = plVar5;
      if (*(long *)*param_1 != 0) {
        *param_1 = *(long *)*param_1;
        plVar8 = (long *)*plVar6;
      }
      func_0x0040a8c0(param_1[1],plVar8);
      param_1[2] = param_1[2] + 1;
LAB_005b0f4c:
      if (*(int *)((long)plVar5 + 0x34) <= (int)lVar2) {
        plVar8 = (long *)*plVar9;
        while (plVar7 = plVar9, plVar8 != (long *)0x0) {
          while (plVar6 = plVar8, plVar9 = plVar6, *(int *)((long)plVar6 + 0x1c) <= param_2) {
            if (param_2 <= *(int *)((long)plVar6 + 0x1c)) goto LAB_005b0fe8;
            plVar8 = (long *)plVar6[1];
            if ((long *)plVar6[1] == (long *)0x0) {
              plVar7 = plVar6 + 1;
              goto LAB_005b0f94;
            }
          }
          plVar8 = (long *)*plVar6;
        }
LAB_005b0f94:
        plVar6 = (long *)func_0x00bc3330(0x40);
        *plVar6 = 0;
        plVar6[1] = 0;
        plVar6[2] = (long)plVar9;
        *(int *)((long)plVar6 + 0x1c) = param_2;
        plVar6[5] = 0;
        plVar6[4] = 0;
        plVar6[7] = 0;
        plVar6[6] = 0;
        *plVar7 = (long)plVar6;
        plVar8 = plVar6;
        if (*(long *)*param_1 != 0) {
          *param_1 = *(long *)*param_1;
          plVar8 = (long *)*plVar7;
        }
        func_0x0040a8c0(param_1[1],plVar8);
        param_1[2] = param_1[2] + 1;
LAB_005b0fe8:
        *(undefined4 *)(plVar6 + 7) = 0;
        *(undefined4 *)(plVar6 + 6) = 0;
      }
    }
    return;
  }
  goto LAB_005b09cc;
}


