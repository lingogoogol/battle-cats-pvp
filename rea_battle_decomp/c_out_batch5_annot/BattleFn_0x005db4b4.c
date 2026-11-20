// ELF VMA: 0x5db4b4
// Ghidra Addr: 0x006db4b4 (ImageBase=0x100000)
// Size: 460 bytes


void BattleFn_0x005db4b4(long param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  byte abStack_98 [16];
  undefined8 uStack_88;
  byte abStack_80 [16];
  undefined8 uStack_70;
  long lStack_68;
  
  lVar2 = tpidr_el0;
  lVar5 = param_1 + (long)param_2 * 0x30;
  lStack_68 = *(long *)(lVar2 + 0x28);
  uVar1 = *(undefined4 *)(&UNK_00333e00 + lVar5);  /* field_off=0x333e00 */
  func_0x00a589e0(abStack_80,1,uVar1);  /* 0x9589e0:[slot*1000,team*0x1f0,team*51000|off=0x83908,0x83908,0x8e9fe5,0x83908,0x83908,0x656e6f4e|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldrb w9, [x8]] */
  func_0x00a589e0(abStack_98,0,param_3);  /* 0x9589e0:[slot*1000,team*0x1f0,team*51000|off=0x83908,0x83908,0x8e9fe5,0x83908,0x83908,0x656e6f4e|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldrb w9, [x8]] */
  if ((abStack_98[0] & 1) != 0) {
    func_0x00bc3350(uStack_88);
  }
  if ((abStack_80[0] & 1) != 0) {
    func_0x00bc3350(uStack_70);
  }
  lVar4 = param_1 + (long)param_2 * 0x30;
  uVar3 = func_0x006d8464(param_1,1,uVar1,param_3,param_4,(&UNK_00333e28)[lVar5],  /* field_off=0x333e28 */
                          (&UNK_00333e18)[lVar4],(&UNK_00333e20)[lVar4],(&UNK_00333e19)[lVar4],  /* field_off=0x333e18 ; field_off=0x333e20 ; field_off=0x333e19 */
                          (&UNK_00333e1a)[lVar4],(&UNK_00333e1b)[lVar4],(&UNK_00333e1c)[lVar4],  /* field_off=0x333e1a ; field_off=0x333e1b ; field_off=0x333e1c */
                          (&UNK_00333e1d)[lVar4],(&UNK_00333e1e)[lVar4],(&UNK_00333e1f)[lVar4],  /* field_off=0x333e1d ; field_off=0x333e1e ; field_off=0x333e1f */
                          (&UNK_00333e21)[lVar4],(&UNK_00333e22)[lVar4],(&UNK_00333e23)[lVar4],100);  /* field_off=0x333e21 ; field_off=0x333e22 ; field_off=0x333e23 */
  if (((uVar3 & 1) != 0) && (uVar3 = func_0x00a5f994(0,param_3), (uVar3 & 1) != 0)) {  /* 0x95f994:[slot*1000,team*51000|off=0x83a64|ldr w8, [x8, x9]] */
    *(undefined4 *)(&UNK_00333dfc + lVar5) = 0;  /* field_off=0x333dfc */
    lVar5 = param_1 + (long)param_2 * 0x30;
    *(undefined4 *)(&UNK_00333e08 + lVar5) = 0;  /* field_off=0x333e08 */
    *(undefined4 *)(&UNK_00333e10 + lVar5) = 0;  /* field_off=0x333e10 */
    *(undefined4 *)(&UNK_0033637c + lVar5) = 0;  /* field_off=0x33637c */
    *(undefined4 *)(&UNK_00336384 + lVar5) = 0;  /* field_off=0x336384 */
    *(undefined4 *)(&UNK_0033638c + lVar5) = 0;  /* field_off=0x33638c */
    *(undefined4 *)(&UNK_00336394 + lVar5) = 0;  /* field_off=0x336394 */
    *(undefined4 *)(&UNK_0033639c + lVar5) = 0;  /* field_off=0x33639c */
    *(undefined4 *)(&UNK_003363a4 + lVar5) = 0;  /* field_off=0x3363a4 */
    *(undefined8 *)(param_1 + (long)param_3 * 1000 + 0x83a80) = 0x100000000;
  }
  if (*(long *)(lVar2 + 0x28) == lStack_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


