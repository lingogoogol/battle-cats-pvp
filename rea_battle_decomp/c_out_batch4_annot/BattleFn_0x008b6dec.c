// ELF VMA: 0x8b6dec
// Ghidra Addr: 0x009b6dec (ImageBase=0x100000)
// Size: 8992 bytes


ulong BattleFn_0x008b6dec(long param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                         int param_7,int param_8)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  int extraout_w1;
  int extraout_w1_00;
  int extraout_w1_01;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  ulong auStack_a0 [2];
  undefined8 *puStack_90;
  ulong auStack_80 [2];
  undefined8 *puStack_70;
  long lStack_68;
  
  lVar1 = tpidr_el0;
  lStack_68 = *(long *)(lVar1 + 0x28);
  if (param_3 == -1) {
    uVar14 = 0xfffffffe;
  }
  else {
    iVar9 = param_3 + -2;
    uVar14 = 1;
    do {
      iVar4 = func_0x00a58874(param_2,uVar14);  /* 0x958874:[slot*1000,team*51000|off=0x83908,0x83908|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
      iVar7 = (int)uVar14;
      if (iVar4 == 0) {
        func_0x00a58978(param_2,uVar14,2,iVar9);  /* 0x958978:[slot*1000,team*51000|off=0x83908|str w20, [x8, x9]] */
        func_0x00a590fc(param_2,uVar14,0);  /* 0x9590fc:[slot*1000,team*51000|off=0x83910|str w19, [x8, x9]] */
        if ((param_2 == 1) && (iVar4 = BattleFn_0x004aad10(), iVar4 == iVar7)) {
          iVar4 = 0xc80;
          iVar8 = 1;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x9e538) + -0xaf0;
          iVar8 = param_2;
          if (param_2 != 0) {
            iVar4 = 0xaf0;
          }
        }
        func_0x00a591dc(iVar8,uVar14,iVar4);  /* 0x9591dc:[slot*1000,team*51000|off=0x83914|str w19, [x8, x9]] */
        func_0x00a597a4(param_2,uVar14,0x1180);  /* 0x9597a4:[slot*1000,team*51000|off=0x83918|str w19, [x8, x9]] */
        lVar12 = param_1 + (long)param_2 * 51000 + uVar14 * 1000;
        *(int *)(lVar12 + 0x8391c) = param_5;
        iVar4 = func_0x0043ea60((param_6 - param_5 & (param_6 - param_5 >> 0x1f ^ 0xffffffffU)) + 1)
        ;
        *(int *)(lVar12 + 0x8391c) = *(int *)(lVar12 + 0x8391c) + iVar4;
        *(int *)(lVar12 + 0x83920) = param_4;
        func_0x00a59830(param_2,uVar14,0);  /* 0x959830:[slot*1000,team*51000|off=0x83950|str w19, [x8, x9]] */
        func_0x00a60414(param_2,uVar14,0);  /* 0x960414:[slot*1000,team*51000|off=0x83954,0x83b90|str w19, [x8, x9] ; str w19, [x8, x9]] */
        func_0x00a61d74(param_2,uVar14,0);  /* 0x961d74:[slot*1000,team*51000|off=0x83ce8|str w19, [x8, x9]] */
        func_0x00a598bc(param_2,uVar14,0);  /* 0x9598bc:[slot*1000,team*51000|off=0x83960|str w19, [x8, x9]] */
        func_0x00a59950(param_2,uVar14,0);  /* 0x959950:[slot*1000,team*51000|off=0x83964|str w21, [x8, x9]] */
        func_0x00a59b90(param_2,uVar14,0);  /* 0x959b90:[slot*1000,team*51000|off=0x83ac8|str w19, [x8, x9]] */
        uVar5 = func_0x00a6548c(param_2,iVar9,param_7);  /* 0x96548c:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a59ca8(param_2,uVar14,uVar5);  /* 0x959ca8:[slot*1000,team*51000|off=0x83ad4|str w19, [x8, x9]] */
        uVar5 = func_0x00a65514(param_2,iVar9,param_7);  /* 0x965514:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a59d88(param_2,uVar14,uVar5);  /* 0x959d88:[slot*1000,team*51000|off=0x83adc|str w19, [x8, x9]] */
        uVar5 = func_0x00a656d8(param_2,iVar9,param_7);  /* 0x9656d8:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a59e68(param_2,uVar14,uVar5);  /* 0x959e68:[slot*1000,team*51000|off=0x83b00|str w19, [x8, x9]] */
        uVar5 = func_0x00a65760(param_2,iVar9,param_7);  /* 0x965760:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a59ef4(param_2,uVar14,uVar5);  /* 0x959ef4:[slot*1000,team*51000|off=0x83b04|str w19, [x8, x9]] */
        uVar6 = func_0x00a657e8(param_2,iVar9,param_7);  /* 0x9657e8:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a59f88(param_2,uVar14,uVar6 & 1);  /* 0x959f88:[slot*1000,team*51000|off=0x83b08|str w21, [x8, x9]] */
        uVar6 = func_0x00a65878(param_2,iVar9,param_7);  /* 0x965878:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5a01c(param_2,uVar14,uVar6 & 1);  /* 0x95a01c:[slot*1000,team*51000|off=0x83b0c|str w21, [x8, x9]] */
        uVar5 = func_0x00a632d8(param_2,iVar9,param_7,param_4 + 1,param_8);  /* 0x9632d8:[team*0x1f0|off=0x327f0c,0x32c658,0x327f0c,0x233118,0x9e560,0x70a3d70b|ldr w8, [x0, x8] ; ldrb w8, [x0, x8] ; ldr w20, [x0, x8] ; ldr x8, [x0, x8]] */
        func_0x00a5a1d4(param_2,uVar14,uVar5);  /* 0x95a1d4:[slot*1000,team*51000|off=0x83924|str w19, [x8, x9]] */
        uVar5 = func_0x00a5a194(param_2,uVar14);  /* 0x95a194:[slot*1000,team*51000|off=0x83924|ldr w0, [x8, x9]] */
        func_0x00a5a260(param_2,uVar14,uVar5);  /* 0x95a260:[slot*1000,team*51000|off=0x83928|str w19, [x8, x9]] */
        uVar5 = func_0x00a64374(param_2,iVar9,param_7);  /* 0x964374:[team*0x1f0|off=0x23311c,0x9e57c|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5a340(param_2,uVar14,uVar5);  /* 0x95a340:[slot*1000,team*51000|off=0x8392c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6441c(param_2,iVar9,param_7);  /* 0x96441c:[team*0x1f0|off=0x233120,0x9e580,0x51eb851f|ldr w20, [x8, x9] ; ldr w22, [x8, x9] ; ldr w11, [x8, x10, lsl #2] ; ldr w8, [x8, x10, lsl #2]] */
        func_0x00a5a38c(param_2,uVar14,uVar5);  /* 0x95a38c:[slot*1000,team*51000|off=0x83930|str w19, [x8, x9]] */
        uVar5 = func_0x00a64d60(param_2,iVar9,param_7);  /* 0x964d60:[team*0x1f0|off=0x233128,0x9e588,0x51eb851f|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5a5dc(param_2,uVar14,uVar5);  /* 0x95a5dc:[slot*1000,team*51000|off=0x83938|str w19, [x8, x9]] */
        uVar5 = func_0x00a64e28(param_2,iVar9,param_7);  /* 0x964e28:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a5a668(param_2,uVar14,uVar5);  /* 0x95a668:[slot*1000,team*51000|off=0x8393c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6537c(param_2,iVar9,param_7);  /* 0x96537c:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a5a6f4(param_2,uVar14,uVar5);  /* 0x95a6f4:[slot*1000,team*51000|off=0x83940|str w19, [x8, x9]] */
        uVar5 = func_0x00a65404(param_2,iVar9,param_7);  /* 0x965404:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a5a740(param_2,uVar14,uVar5);  /* 0x95a740:[slot*1000,team*51000|off=0x83944|str w19, [x8, x9]] */
        uVar5 = func_0x00a6559c(param_2,iVar9,param_7);  /* 0x96559c:[team*0x1f0|off=|ldr w0, [x8]] */
        func_0x00a5a82c(param_2,uVar14,uVar5);  /* 0x95a82c:[slot*1000,team*51000|off=0x83ae0|str w19, [x8, x9]] */
        if (param_2 == 1) {
          iVar4 = BattleFn_0x004aad10();
          uVar5 = BattleFn_0x009645a8(1,iVar9,param_7,param_4 + 1,param_8,0,0,iVar7 == iVar4);
          func_0x00a5a434(1,uVar14,0,uVar5);  /* 0x95a434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
          uVar5 = BattleFn_0x00964cb4(1,iVar9,param_7,0);
          func_0x00a5a78c(1,uVar14,0,uVar5);  /* 0x95a78c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
          uVar6 = func_0x00a65624(1,iVar9,param_7,0);  /* 0x965624:[team*0x1f0|off=|ldr w8, [x8]] */
          func_0x00a5a8dc(1,uVar14,0,uVar6 & 1);  /* 0x95a8dc:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
          iVar4 = BattleFn_0x004aad10();
          bVar2 = iVar7 == iVar4;
        }
        else {
          uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,0,0,0);
          func_0x00a5a434(param_2,uVar14,0,uVar5);  /* 0x95a434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
          uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,0);
          func_0x00a5a78c(param_2,uVar14,0,uVar5);  /* 0x95a78c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
          uVar6 = func_0x00a65624(param_2,iVar9,param_7,0);  /* 0x965624:[team*0x1f0|off=|ldr w8, [x8]] */
          func_0x00a5a8dc(param_2,uVar14,0,uVar6 & 1);  /* 0x95a8dc:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
          bVar2 = false;
        }
        uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,1,0,bVar2);
        func_0x00a5a434(param_2,uVar14,1,uVar5);  /* 0x95a434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,1);
        func_0x00a5a78c(param_2,uVar14,1,uVar5);  /* 0x95a78c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar6 = func_0x00a65624(param_2,iVar9,param_7,1);  /* 0x965624:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5a8dc(param_2,uVar14,1,uVar6 & 1);  /* 0x95a8dc:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
        bVar2 = false;
        if (param_2 == 1) {
          iVar4 = BattleFn_0x004aad10();
          bVar2 = iVar7 == iVar4;
        }
        uVar5 = BattleFn_0x009645a8(param_2,iVar9,param_7,param_4 + 1,param_8,2,0,bVar2);
        func_0x00a5a434(param_2,uVar14,2,uVar5);  /* 0x95a434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = BattleFn_0x00964cb4(param_2,iVar9,param_7,2);
        func_0x00a5a78c(param_2,uVar14,2,uVar5);  /* 0x95a78c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar6 = func_0x00a65624(param_2,iVar9,param_7,2);  /* 0x965624:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5a8dc(param_2,uVar14,2,uVar6 & 1);  /* 0x95a8dc:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
        uVar6 = func_0x00a67af0(param_2,iVar9,param_7,1);  /* 0x967af0:[team*0x1f0|off=0x233140|ldr w8, [x8, x9]] */
        func_0x00a5bb90(param_2,uVar14,uVar6 & 1);  /* 0x95bb90:[slot*1000,team*0x1f0,team*51000|off=0x83948|str w19, [x8, x9]] */
        uVar6 = func_0x00a67bb0(param_2,iVar9,param_7,1);  /* 0x967bb0:[team*0x1f0|off=0x23314c|ldr w8, [x8, x9]] */
        func_0x00a5bc10(param_2,uVar14,uVar6 & 1);  /* 0x95bc10:[slot*1000,team*51000|off=0x839ac|str w21, [x8, x9]] */
        uVar6 = func_0x00a67c70(param_2,iVar9,param_7,1);  /* 0x967c70:[team*0x1f0|off=0x233150|ldr w8, [x8, x9]] */
        func_0x00a5bc5c(param_2,uVar14,uVar6 & 1);  /* 0x95bc5c:[slot*1000,team*51000|off=0x839b0|str w21, [x8, x9]] */
        uVar6 = func_0x00a67d30(param_2,iVar9,param_7,1);  /* 0x967d30:[team*0x1f0|off=0x233154|ldr w8, [x8, x9]] */
        func_0x00a5bca8(param_2,uVar14,uVar6 & 1);  /* 0x95bca8:[slot*1000,team*51000|off=0x839b4|str w21, [x8, x9]] */
        uVar6 = func_0x00a66964(param_2,iVar9,param_7);  /* 0x966964:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5bcf4(param_2,uVar14,uVar6 & 1);  /* 0x95bcf4:[slot*1000,team*0x1f0,team*51000|off=0x83a30|str w19, [x8, x9]] */
        uVar6 = func_0x00a68030(param_2,iVar9,param_7,1);  /* 0x968030:[team*0x1f0|off=0x233158|ldr w8, [x8, x9]] */
        func_0x00a5bd74(param_2,uVar14,uVar6 & 1);  /* 0x95bd74:[slot*1000,team*51000|off=0x839b8|str w21, [x8, x9]] */
        uVar6 = func_0x00a67df0(param_2,iVar9,param_7,1);  /* 0x967df0:[team*0x1f0|off=0x23315c|ldr w8, [x8, x9]] */
        func_0x00a5bdc0(param_2,uVar14,uVar6 & 1);  /* 0x95bdc0:[slot*1000,team*51000|off=0x839bc|str w21, [x8, x9]] */
        uVar6 = func_0x00a64258(param_2,iVar9,param_7,1);  /* 0x964258:[team*0x1f0|off=0x233160|ldr w8, [x8, x9]] */
        func_0x00a5be0c(param_2,uVar14,uVar6 & 1);  /* 0x95be0c:[slot*1000,team*51000|off=0x839c0|str w21, [x8, x9]] */
        uVar5 = func_0x00a64318(param_2,iVar9,param_7,1);  /* 0x964318:[team*0x1f0|off=0x2335b4|ldr w0, [x8, x9]] */
        func_0x00a5be58(param_2,uVar14,uVar5);  /* 0x95be58:[slot*1000,team*51000|off=0x83b40|str w19, [x8, x9]] */
        uVar6 = func_0x00a67eb0(param_2,iVar9,param_7,1);  /* 0x967eb0:[team*0x1f0|off=0x233164|ldr w8, [x8, x9]] */
        func_0x00a5bea4(param_2,uVar14,uVar6 & 1);  /* 0x95bea4:[slot*1000,team*51000|off=0x839c4|str w21, [x8, x9]] */
        uVar6 = func_0x00a695b8(param_2,iVar9,param_7,1);  /* 0x9695b8:[team*0x1f0|off=0x2331d8|ldr w8, [x8, x9]] */
        func_0x00a5bef0(param_2,uVar14,uVar6 & 1);  /* 0x95bef0:[slot*1000,team*51000|off=0x83abc|str w21, [x8, x9]] */
        uVar6 = func_0x00a69678(param_2,iVar9,param_7,1);  /* 0x969678:[team*0x1f0|off=0x233234|ldr w8, [x8, x9]] */
        func_0x00a5bf3c(param_2,uVar14,uVar6 & 1);  /* 0x95bf3c:[slot*1000,team*51000|off=0x83b48|str w21, [x8, x9]] */
        uVar6 = func_0x00a67f70(param_2,iVar9,param_7,1);  /* 0x967f70:[team*0x1f0|off=0x233238|ldr w8, [x8, x9]] */
        func_0x00a5bf88(param_2,uVar14,uVar6 & 1);  /* 0x95bf88:[slot*1000,team*51000|off=0x83b50|str w21, [x8, x9]] */
        uVar6 = func_0x00a68634(param_2,iVar9,param_7,1);  /* 0x968634:[team*0x1f0|off=0x23328c|ldr w8, [x8, x9]] */
        func_0x00a5bfd4(param_2,uVar14,uVar6 & 1);  /* 0x95bfd4:[slot*1000,team*51000|off=0x83c10|str w21, [x8, x9]] */
        uVar6 = func_0x00a6948c(param_2,iVar9,param_7);  /* 0x96948c:[team*0x1f0|off=0x233618|ldr w8, [x8, x9]] */
        func_0x00a5c090(param_2,uVar14,uVar6 & 1);  /* 0x95c090:[slot*1000,team*51000|off=0x83c18|str w21, [x8, x9]] */
        uVar6 = func_0x00a694f0(param_2,iVar9,param_7);  /* 0x9694f0:[team*0x1f0|off=0x233634|ldr w8, [x8, x9]] */
        func_0x00a5c14c(param_2,uVar14,uVar6 & 1);  /* 0x95c14c:[slot*1000,team*51000|off=0x83c40|str w21, [x8, x9]] */
        uVar6 = func_0x00a69554(param_2,iVar9,param_7);  /* 0x969554:[team*0x1f0|off=0x233640|ldr w8, [x8, x9]] */
        func_0x00a5c208(param_2,uVar14,uVar6 & 1);  /* 0x95c208:[slot*1000,team*51000|off=0x83c64|str w21, [x8, x9]] */
        uVar6 = func_0x00a69738(param_2,iVar9,param_7);  /* 0x969738:[team*0x1f0|off=0x233658|ldr w8, [x8, x9]] */
        func_0x00a5c29c(param_2,uVar14,uVar6 & 1);  /* 0x95c29c:[slot*1000,team*51000|off=0x83cd8|str w21, [x8, x9]] */
        uVar6 = func_0x00a66aac(param_2,iVar9,param_7);  /* 0x966aac:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5c330(param_2,uVar14,uVar6 & 1);  /* 0x95c330:[slot*1000,team*51000|off=0x83958|str w21, [x8, x9]] */
        uVar5 = func_0x00a668c0(param_2,iVar9,param_7);  /* 0x9668c0:[team*0x1f0|off=0x2335f8,0x9f5b0|ldr w0, [x8, x9]] */
        func_0x00a5c3bc(param_2,uVar14,uVar5);  /* 0x95c3bc:[slot*1000,team*51000|off=0x83be0|str w19, [x8, x9]] */
        uVar5 = func_0x00a66748(param_2,iVar9,param_7,0xffffffff);  /* 0x966748:[team*0x1f0|off=0x2335f8,0x9f5b0,0x233184,0x9e604|ldr w8, [x8, x9] ; ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5c408(param_2,uVar14,uVar5);  /* 0x95c408:[slot*1000,team*51000|off=0x839a4|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a110(param_2,iVar9,param_7,0xffffffff);  /* 0x96a110:[team*0x1f0|off=0x2335f8,0x9f5b0,0x233188,0x9e608|ldr w8, [x8, x9] ; ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5c454(param_2,uVar14,uVar5);  /* 0x95c454:[slot*1000,team*51000|off=0x839a8|str w19, [x8, x9]] */
        uVar5 = func_0x00a666a0(param_2,iVar9,param_7);  /* 0x9666a0:[team*0x1f0|off=0x233168,0x9e5d8|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5c5a8(param_2,uVar14,uVar5);  /* 0x95c5a8:[slot*1000,team*51000|off=0x839cc|str w19, [x8, x9]] */
        uVar6 = func_0x00a663bc(param_2,iVar9,param_7);  /* 0x9663bc:[team*0x1f0|off=0x9f4b8|ldr w8, [x8, x9]] */
        func_0x00a5c664(param_2,uVar14,uVar6 & 1);  /* 0x95c664:[slot*1000,team*0x1f0,team*51000|off=0x839ec|str w20, [x8, x9]] */
        uVar6 = func_0x00a66578(param_2,iVar9,param_7);  /* 0x966578:[team*0x1f0|off=0x9f4bc|ldr w8, [x8, x9]] */
        func_0x00a5c744(param_2,uVar14,uVar6 & 1);  /* 0x95c744:[slot*1000,team*0x1f0,team*51000|off=0x839f0|str w20, [x8, x9]] */
        bVar3 = param_2 != 0;
        uVar5 = 0;
        bVar2 = param_7 < 2;
        if (!bVar3 && 1 < param_7) {
          uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x00653738(param_1 + 0x1538,iVar9,7,0,0);
          }
        }
        func_0x00a5c81c(param_2,uVar14,uVar5);  /* 0x95c81c:[slot*1000,team*0x1f0,team*51000|off=0x83ca4|str w19, [x8, x9]] */
        uVar5 = func_0x00a66184(param_2,iVar9,param_7);  /* 0x966184:[team*0x1f0|off=0x2331a0,0x9e620|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5c888(param_2,uVar14,uVar5);  /* 0x95c888:[slot*1000,team*51000|off=0x83a2c|str w19, [x8, x9]] */
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,0);  /* 0x966b3c:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5c9b8(param_2,uVar14,0,uVar6 & 1);  /* 0x95c9b8:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,0);  /* 0x96a288:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cb2c(param_2,uVar14,0,uVar5);  /* 0x95cb2c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,0);  /* 0x96a344:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cca0(param_2,uVar14,0,uVar5);  /* 0x95cca0:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,1);  /* 0x966b3c:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5c9b8(param_2,uVar14,1,uVar6 & 1);  /* 0x95c9b8:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,1);  /* 0x96a288:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cb2c(param_2,uVar14,1,uVar5);  /* 0x95cb2c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,1);  /* 0x96a344:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cca0(param_2,uVar14,1,uVar5);  /* 0x95cca0:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar6 = func_0x00a66b3c(param_2,iVar9,param_7,2);  /* 0x966b3c:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5c9b8(param_2,uVar14,2,uVar6 & 1);  /* 0x95c9b8:[slot*1000,team*51000|off=0x83908|str w22, [x8, x9]] */
        uVar5 = func_0x00a6a288(param_2,iVar9,param_7,2);  /* 0x96a288:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cb2c(param_2,uVar14,2,uVar5);  /* 0x95cb2c:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a344(param_2,iVar9,param_7,2);  /* 0x96a344:[team*0x1f0|off=|ldr w8, [x8]] */
        func_0x00a5cca0(param_2,uVar14,2,uVar5);  /* 0x95cca0:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        uVar5 = func_0x00a6756c(param_2,iVar9,param_7);  /* 0x96756c:[team*0x1f0|off=0x23321c,0x9e694|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5cd88(param_2,uVar14,uVar5);  /* 0x95cd88:[slot*1000,team*51000|off=0x83b24|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a400(param_2,iVar9,param_7);  /* 0x96a400:[team*0x1f0|off=0x233220,0x9e698|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5ce14(param_2,uVar14,uVar5);  /* 0x95ce14:[slot*1000,team*51000|off=0x83b28|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a4a8(param_2,iVar9,param_7);  /* 0x96a4a8:[team*0x1f0|off=0x233224,0x9e69c|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5cea0(param_2,uVar14,uVar5);  /* 0x95cea0:[slot*1000,team*51000|off=0x83b2c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a550(param_2,iVar9,param_7);  /* 0x96a550:[team*0x1f0|off=0x233228,0x9e6a0|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5cf2c(param_2,uVar14,uVar5);  /* 0x95cf2c:[slot*1000,team*51000|off=0x83b30|str w19, [x8, x9]] */
        uVar5 = func_0x00a68b54(param_2,iVar9,param_7);  /* 0x968b54:[team*0x1f0|off=0x2335dc|ldr w0, [x8, x9]] */
        func_0x00a5d088(param_2,uVar14,uVar5);  /* 0x95d088:[slot*1000,team*51000|off=0x83bb4|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a5f8(param_2,iVar9,param_7);  /* 0x96a5f8:[team*0x1f0|off=0x2335e0|ldr w0, [x8, x9]] */
        func_0x00a5d114(param_2,uVar14,uVar5);  /* 0x95d114:[slot*1000,team*51000|off=0x83bb8|str w19, [x8, x9]] */
        uVar5 = func_0x00a68240(param_2,iVar9,param_7);  /* 0x968240:[team*0x1f0|off=0x23325c,0x9e6d0|ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5d1e0(param_2,uVar14,uVar5);  /* 0x95d1e0:[slot*1000,team*51000|off=0x83bc0|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a654(param_2,iVar9,param_7);  /* 0x96a654:[team*0x1f0|off=0x233260,0x9e6d4|ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5d26c(param_2,uVar14,uVar5);  /* 0x95d26c:[slot*1000,team*51000|off=0x83bc4|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a724(param_2,iVar9,param_7);  /* 0x96a724:[team*0x1f0|off=0x233264,0x9e6d8|ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5d2f8(param_2,uVar14,uVar5);  /* 0x95d2f8:[slot*1000,team*51000|off=0x83bc8|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a7f4(param_2,iVar9,param_7);  /* 0x96a7f4:[team*0x1f0|off=0x233268,0x9e6dc|ldr w0, [x8, x9] ; ldr w23, [x8, x9]] */
        func_0x00a5d384(param_2,uVar14,uVar5);  /* 0x95d384:[slot*1000,team*51000|off=0x83bcc|str w19, [x8, x9]] */
        uVar5 = func_0x00a68310(param_2,iVar9,param_7);  /* 0x968310:[team*0x1f0|off=0x233638,0x9f5e8|ldr w0, [x8, x9]] */
        func_0x00a5d3d0(param_2,uVar14,uVar5);  /* 0x95d3d0:[slot*1000,team*51000|off=0x83c54|str w19, [x8, x9]] */
        uVar5 = func_0x00a68bb0(param_2,iVar9,param_7);  /* 0x968bb0:[team*0x1f0|off=0x233604|ldr w0, [x8, x9]] */
        func_0x00a5d41c(param_2,uVar14,uVar5);  /* 0x95d41c:[slot*1000,team*51000|off=0x83bf0|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a8c4(param_2,iVar9,param_7);  /* 0x96a8c4:[team*0x1f0|off=0x233608|ldr w0, [x8, x9]] */
        func_0x00a5d4a8(param_2,uVar14,uVar5);  /* 0x95d4a8:[slot*1000,team*51000|off=0x83bf4|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a920(param_2,iVar9,param_7);  /* 0x96a920:[team*0x1f0|off=0x23360c|ldr w0, [x8, x9]] */
        func_0x00a5d534(param_2,uVar14,uVar5);  /* 0x95d534:[slot*1000,team*51000|off=0x83bf8|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a97c(param_2,iVar9,param_7);  /* 0x96a97c:[team*0x1f0|off=0x233610|ldr w0, [x8, x9]] */
        func_0x00a5d5c0(param_2,uVar14,uVar5);  /* 0x95d5c0:[slot*1000,team*51000|off=0x83bfc|str w19, [x8, x9]] */
        func_0x00a5d64c(param_2,uVar14,100);  /* 0x95d64c:[slot*1000,team*51000|off=0x83c98|str w19, [x8, x9]] */
        func_0x00a5d6d8(param_2,uVar14,0);  /* 0x95d6d8:[slot*1000,team*51000|off=0x83cac|str w19, [x8, x9]] */
        if (bVar3 || bVar2) {
          uVar6 = func_0x00a688b0(param_2,iVar9,param_7);  /* 0x9688b0:[team*0x1f0|off=0x2332b4,0x9e72c|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          func_0x00a5d76c(param_2,uVar14,uVar6 & 1);  /* 0x95d76c:[slot*1000,team*51000|off=0x83c58|str w21, [x8, x9]] */
          func_0x00a5d7f8(param_2,uVar14,100);  /* 0x95d7f8:[slot*1000,team*51000|off=0x83cc0|str w19, [x8, x9]] */
          uVar11 = 0;
          iVar4 = param_2;
LAB_009b7b78:
          func_0x00a5d88c(iVar4,uVar14,uVar11);  /* 0x95d88c:[slot*1000,team*51000|off=0x83cc4|str w21, [x8, x9]] */
        }
        else {
          lVar12 = param_1 + (long)param_2 * 0x1f0;
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          if (((uVar10 & 1) != 0) &&
             (iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,5,0,0), 0 < iVar4)) {
            func_0x00a5d41c(0,uVar14,100);  /* 0x95d41c:[slot*1000,team*51000|off=0x83bf0|str w19, [x8, x9]] */
            puStack_70 = (undefined8 *)func_0x00bc3330(0x30);
            auStack_80[1] = 0x20;
            auStack_80[0] = 0x31;
            puStack_70[1] = 0x5f68746165645f66;  /* ascii(0x5f68746165645f66)='f_death_' */
            *puStack_70 = 0x615f656c74746162;  /* ascii(0x615f656c74746162)='battle_a' */
            puStack_70[3] = 0x65636e6174736964;  /* ascii(0x65636e6174736964)='distance' */
            puStack_70[2] = 0x5f6f6e61636c6f76;  /* ascii(0x5f6f6e61636c6f76)='volcano_' */
            *(undefined1 *)(puStack_70 + 4) = 0;
            uVar5 = func_0x008e3f14(auStack_80,param_1 + 0x1478,auStack_80,600);
            func_0x00a5d4a8(0,uVar14,uVar5);  /* 0x95d4a8:[slot*1000,team*51000|off=0x83bf4|str w19, [x8, x9]] */
            if ((auStack_80[0] & 1) != 0) {
              func_0x00bc3350(puStack_70);
            }
            puStack_90 = (undefined8 *)func_0x00bc3330(0x20);
            puStack_90[1] = 0x5f68746165645f66;  /* ascii(0x5f68746165645f66)='f_death_' */
            *puStack_90 = 0x615f656c74746162;  /* ascii(0x615f656c74746162)='battle_a' */
            *(undefined8 *)((long)puStack_90 + 0x15) = 0x68746469775f6f6e;  /* ascii(0x68746469775f6f6e)='no_width' */
            *(undefined8 *)((long)puStack_90 + 0xd) = 0x61636c6f765f6874;  /* ascii(0x61636c6f765f6874)='th_volca' */
            auStack_a0[1] = 0x1d;
            auStack_a0[0] = 0x21;
            *(undefined1 *)((long)puStack_90 + 0x1d) = 0;
            uVar5 = func_0x008e3f14(param_1 + 0x1478,auStack_a0,4000);
            func_0x00a5d534(0,uVar14,uVar5);  /* 0x95d534:[slot*1000,team*51000|off=0x83bf8|str w19, [x8, x9]] */
            if ((auStack_a0[0] & 1) != 0) {
              func_0x00bc3350(puStack_90);
            }
            func_0x00a5d5c0(0,uVar14,1);  /* 0x95d5c0:[slot*1000,team*51000|off=0x83bfc|str w19, [x8, x9]] */
            func_0x00a5d64c(0,uVar14,iVar4 * 5);  /* 0x95d64c:[slot*1000,team*51000|off=0x83c98|str w19, [x8, x9]] */
            func_0x00a5d6d8(0,uVar14,1);  /* 0x95d6d8:[slot*1000,team*51000|off=0x83cac|str w19, [x8, x9]] */
          }
          uVar6 = func_0x00a688b0(0,iVar9,param_7);  /* 0x9688b0:[team*0x1f0|off=0x2332b4,0x9e72c|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
          func_0x00a5d76c(0,uVar14,uVar6 & 1);  /* 0x95d76c:[slot*1000,team*51000|off=0x83c58|str w21, [x8, x9]] */
          func_0x00a5d7f8(0,uVar14,100);  /* 0x95d7f8:[slot*1000,team*51000|off=0x83cc0|str w19, [x8, x9]] */
          func_0x00a5d88c(0,uVar14,0);  /* 0x95d88c:[slot*1000,team*51000|off=0x83cc4|str w21, [x8, x9]] */
          uVar10 = func_0x00a5d724(0,uVar14);  /* 0x95d724:[slot*1000,team*51000|off=0x83c58|ldr w8, [x8, x9]] */
          if ((((uVar10 & 1) == 0) &&
              (uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14), (uVar10 & 1) != 0)) &&
             (iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,0x11,0,0), 0 < iVar4)) {
            func_0x00a5d76c(0,uVar14,1);  /* 0x95d76c:[slot*1000,team*51000|off=0x83c58|str w21, [x8, x9]] */
            func_0x00a5d7f8(0,uVar14,iVar4);  /* 0x95d7f8:[slot*1000,team*51000|off=0x83cc0|str w19, [x8, x9]] */
            iVar4 = 0;
            uVar11 = 1;
            goto LAB_009b7b78;
          }
        }
        uVar5 = func_0x00a68cc4(param_2,iVar9,param_7);  /* 0x968cc4:[team*0x1f0|off=0x2332c0,0x9e73c|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5d918(param_2,uVar14,uVar5);  /* 0x95d918:[slot*1000,team*51000|off=0x83c88|str w19, [x8, x9]] */
        uVar5 = func_0x00a6a9d8(param_2,iVar9,param_7);  /* 0x96a9d8:[team*0x1f0|off=0x2332c4,0x9e740|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5d9a4(param_2,uVar14,uVar5);  /* 0x95d9a4:[slot*1000,team*51000|off=0x83c8c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6aa80(param_2,iVar9,param_7);  /* 0x96aa80:[team*0x1f0|off=0x2332c8,0x9e744|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5da30(param_2,uVar14,uVar5);  /* 0x95da30:[slot*1000,team*51000|off=0x83c90|str w19, [x8, x9]] */
        uVar5 = func_0x00a68968(param_2,iVar9,param_7);  /* 0x968968:[team*0x1f0|off=|] */
        func_0x00a5dabc(param_2,uVar14,uVar5);  /* 0x95dabc:[slot*1000,team*51000|off=0x83c5c|str w19, [x8, x9]] */
        func_0x00a5db08(param_2,uVar14,0xffffffff);  /* 0x95db08:[slot*1000,team*51000|off=0x83c60|str w19, [x8, x9]] */
        uVar5 = func_0x00a66034(param_2,iVar9,param_7);  /* 0x966034:[team*0x1f0|off=0x23316c,0x9e5dc|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5dc24(param_2,uVar14,uVar5);  /* 0x95dc24:[slot*1000,team*51000|off=0x839d0|str w19, [x8, x9]] */
        uVar5 = func_0x00a6ab28(param_2,iVar9,param_7);  /* 0x96ab28:[team*0x1f0|off=0x233170,0x9e5e0|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5dcb0(param_2,uVar14,uVar5);  /* 0x95dcb0:[slot*1000,team*51000|off=0x839d4|str w19, [x8, x9]] */
        uVar5 = func_0x00a660dc(param_2,iVar9,param_7);  /* 0x9660dc:[team*0x1f0|off=0x233174,0x9e5e4|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5dd84(param_2,uVar14,uVar5);  /* 0x95dd84:[slot*1000,team*51000|off=0x839d8|str w19, [x8, x9]] */
        uVar5 = func_0x00a6abd0(param_2,iVar9,param_7);  /* 0x96abd0:[team*0x1f0|off=0x233178,0x9e5e8|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5de10(param_2,uVar14,uVar5);  /* 0x95de10:[slot*1000,team*51000|off=0x839dc|str w19, [x8, x9]] */
        uVar5 = func_0x00a65e64(param_2,iVar9,param_7);  /* 0x965e64:[team*0x1f0|off=0x23318c,0x9e60c|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5dee4(param_2,uVar14,uVar5);  /* 0x95dee4:[slot*1000,team*51000|off=0x83a18|str w19, [x8, x9]] */
        uVar5 = func_0x00a6ac78(param_2,iVar9,param_7);  /* 0x96ac78:[team*0x1f0|off=0x233190,0x9e610|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5df70(param_2,uVar14,uVar5);  /* 0x95df70:[slot*1000,team*51000|off=0x83a1c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6ad20(param_2,iVar9,param_7);  /* 0x96ad20:[team*0x1f0|off=0x233194|ldr w0, [x8, x9]] */
        func_0x00a5dffc(param_2,uVar14,uVar5);  /* 0x95dffc:[slot*1000,team*51000|off=0x83a20|str w19, [x8, x9]] */
        uVar5 = func_0x00a68448(param_2,iVar9,param_7);  /* 0x968448:[team*0x1f0|off=0x23323c,0x9e6e8|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5e0d0(param_2,uVar14,uVar5);  /* 0x95e0d0:[slot*1000,team*51000|off=0x83b54|str w19, [x8, x9]] */
        uVar5 = func_0x00a6ae2c(param_2,iVar9,param_7);  /* 0x96ae2c:[team*0x1f0|off=0x233240,0x9e6ec|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5e15c(param_2,uVar14,uVar5);  /* 0x95e15c:[slot*1000,team*51000|off=0x83b58|str w19, [x8, x9]] */
        uVar5 = func_0x00a65f0c(param_2,iVar9,param_7);  /* 0x965f0c:[team*0x1f0|off=0x233198|ldr w0, [x8, x9]] */
        func_0x00a5e1e8(param_2,uVar14,uVar5);  /* 0x95e1e8:[slot*1000,team*51000|off=0x83a24|str w19, [x8, x9]] */
        uVar5 = func_0x00a6aed4(param_2,iVar9,param_7);  /* 0x96aed4:[team*0x1f0|off=0x23319c,0x9e61c|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5e274(param_2,uVar14,uVar5);  /* 0x95e274:[slot*1000,team*51000|off=0x83a28|str w19, [x8, x9]] */
        uVar6 = func_0x00a66450(param_2,iVar9,param_7);  /* 0x966450:[team*0x1f0|off=0x9f494|ldr w8, [x8, x9]] */
        func_0x00a5e570(param_2,uVar14,uVar6 & 1);  /* 0x95e570:[slot*1000,team*0x1f0,team*51000|off=0x839c8|str w20, [x8, x9]] */
        uVar6 = func_0x00a664e4(param_2,iVar9,param_7);  /* 0x9664e4:[team*0x1f0|off=0x9f4ac|ldr w8, [x8, x9]] */
        func_0x00a5e650(param_2,uVar14,uVar6 & 1);  /* 0x95e650:[slot*1000,team*0x1f0,team*51000|off=0x839e0|str w20, [x8, x9]] */
        uVar6 = func_0x00a6660c(param_2,iVar9,param_7);  /* 0x96660c:[team*0x1f0|off=0x9f4b0|ldr w8, [x8, x9]] */
        func_0x00a5e730(param_2,uVar14,uVar6 & 1);  /* 0x95e730:[slot*1000,team*0x1f0,team*51000|off=0x839e4|str w20, [x8, x9]] */
        uVar6 = func_0x00a67a78(param_2,iVar9,param_7);  /* 0x967a78:[team*0x1f0|off=0x9f578|ldr w8, [x8, x9]] */
        func_0x00a5e810(param_2,uVar14,uVar6 & 1);  /* 0x95e810:[slot*1000,team*0x1f0,team*51000|off=0x83b88|str w20, [x8, x9]] */
        uVar6 = func_0x00a67a00(param_2,iVar9,param_7);  /* 0x967a00:[team*0x1f0|off=0x9f57c|ldr w8, [x8, x9]] */
        func_0x00a5e8f0(param_2,uVar14,uVar6 & 1);  /* 0x95e8f0:[slot*1000,team*0x1f0,team*51000|off=0x83b8c|str w20, [x8, x9]] */
        uVar5 = func_0x00a662e4(param_2,iVar9,param_7);  /* 0x9662e4:[team*0x1f0|off=0x23317c,0x9e5f4|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5e9e8(param_2,uVar14,uVar5);  /* 0x95e9e8:[slot*1000,team*51000|off=0x839e8|str w19, [x8, x9]] */
        uVar6 = func_0x00a6622c(param_2,iVar9,param_7);  /* 0x96622c:[team*0x1f0|off=0x233180,0x9e600|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        func_0x00a5ea7c(param_2,uVar14,uVar6 & 1);  /* 0x95ea7c:[slot*1000,team*51000|off=0x839f4|str w21, [x8, x9]] */
        uVar6 = func_0x00a671ac(param_2,iVar9,param_7);  /* 0x9671ac:[team*0x1f0|off=0x9f508|ldr w8, [x8, x9]] */
        func_0x00a5eb38(param_2,uVar14,uVar6 & 1);  /* 0x95eb38:[slot*1000,team*0x1f0,team*51000|off=0x83ab8|str w20, [x8, x9]] */
        uVar6 = func_0x00a67134(param_2,iVar9,param_7);  /* 0x967134:[team*0x1f0|off=0x9f50c|ldr w8, [x8, x9]] */
        func_0x00a5ec18(param_2,uVar14,uVar6 & 1);  /* 0x95ec18:[slot*1000,team*0x1f0,team*51000|off=0x83ac0|str w20, [x8, x9]] */
        uVar6 = func_0x00a6743c(param_2,iVar9,param_7);  /* 0x96743c:[team*0x1f0|off=0x9f56c|ldr w8, [x8, x9]] */
        func_0x00a5ecf8(param_2,uVar14,uVar6 & 1);  /* 0x95ecf8:[slot*1000,team*0x1f0,team*51000|off=0x83b4c|str w20, [x8, x9]] */
        uVar6 = func_0x00a686f4(param_2,iVar9,param_7);  /* 0x9686f4:[team*0x1f0|off=0x9f5bc|ldr w8, [x8, x9]] */
        func_0x00a5edd8(param_2,uVar14,uVar6 & 1);  /* 0x95edd8:[slot*1000,team*0x1f0,team*51000|off=0x83c1c|str w20, [x8, x9]] */
        func_0x00a5ef28(param_2,uVar14,0,0);  /* 0x95ef28:[slot*1000,team*0x1f0,team*51000|off=0x83c9c,0x83ca0|str w21, [x8, x9] ; str w19, [x8, x9]] */
        if (((!bVar3 && !bVar2) && (uVar6 & 1) == 0) &&
           (uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14),
           (uVar10 & 1) != 0)) {
          iVar4 = func_0x006535d4(param_1 + 0x1538,iVar9,10,0,0);
          iVar7 = func_0x006535d4(param_1 + 0x1538,iVar9,10,1,0);
          if ((0 < iVar4) && (0 < iVar7)) {
            func_0x00a5edd8(0,uVar14,1);  /* 0x95edd8:[slot*1000,team*0x1f0,team*51000|off=0x83c1c|str w20, [x8, x9]] */
            func_0x00a5ef28(0,uVar14,iVar4,iVar7);  /* 0x95ef28:[slot*1000,team*0x1f0,team*51000|off=0x83c9c,0x83ca0|str w21, [x8, x9] ; str w19, [x8, x9]] */
          }
        }
        uVar5 = func_0x00a672f8(param_2,iVar9,param_7);  /* 0x9672f8:[team*0x1f0|off=0x9f550|ldr w22, [x8, x9]] */
        func_0x00a5f120(param_2,uVar14,uVar5);  /* 0x95f120:[slot*1000,team*51000|off=0x83b18|str w19, [x8, x9]] */
        uVar5 = func_0x00a685a8(param_2,iVar9,param_7);  /* 0x9685a8:[team*0x1f0|off=0x9f5b4|ldr w22, [x8, x9]] */
        func_0x00a5f1f4(param_2,uVar14,uVar5);  /* 0x95f1f4:[slot*1000,team*51000|off=0x83be4|str w19, [x8, x9]] */
        uVar5 = func_0x00a680f0(param_2,iVar9,param_7);  /* 0x9680f0:[team*0x1f0|off=0x233244,0x9e6c0|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5f240(param_2,uVar14,uVar5);  /* 0x95f240:[slot*1000,team*51000|off=0x83b94|str w19, [x8, x9]] */
        uVar5 = func_0x00a6af7c(param_2,iVar9,param_7);  /* 0x96af7c:[team*0x1f0|off=0x233248,0x9e6c4|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a5f2cc(param_2,uVar14,uVar5);  /* 0x95f2cc:[slot*1000,team*51000|off=0x83b98|str w19, [x8, x9]] */
        uVar6 = func_0x00a68788(param_2,iVar9,param_7);  /* 0x968788:[team*0x1f0|off=0x9f5c0|ldr w8, [x8, x9]] */
        func_0x00a5f318(param_2,uVar14,uVar6 & 1);  /* 0x95f318:[slot*1000,team*51000|off=0x83c20|str w21, [x8, x9]] */
        uVar6 = func_0x00a6881c(param_2,iVar9,param_7);  /* 0x96881c:[team*0x1f0|off=0x9f5dc|ldr w8, [x8, x9]] */
        func_0x00a5f3d4(param_2,uVar14,uVar6 & 1);  /* 0x95f3d4:[slot*1000,team*0x1f0,team*51000|off=0x83c44|str w20, [x8, x9]] */
        uVar5 = func_0x00a6b024(param_2,iVar9,param_7);  /* 0x96b024:[team*0x1f0|off=0x9f5e0|ldr w22, [x8, x9]] */
        func_0x00a5f4ac(param_2,uVar14,uVar5);  /* 0x95f4ac:[slot*1000,team*0x1f0,team*51000|off=0x83c48|str w19, [x8, x9]] */
        uVar5 = func_0x00a6b0b0(param_2,iVar9,param_7);  /* 0x96b0b0:[team*0x1f0|off=0x9f5e4|ldr w22, [x8, x9]] */
        func_0x00a5f580(param_2,uVar14,uVar5);  /* 0x95f580:[slot*1000,team*0x1f0,team*51000|off=0x83c4c|str w19, [x8, x9]] */
        uVar6 = func_0x00a689ec(param_2,iVar9,param_7);  /* 0x9689ec:[team*0x1f0|off=0x9f5f4|ldr w8, [x8, x9]] */
        func_0x00a5f65c(param_2,uVar14,uVar6 & 1);  /* 0x95f65c:[slot*1000,team*0x1f0,team*51000|off=0x83c68|str w20, [x8, x9]] */
        uVar5 = func_0x00a68a80(param_2,iVar9,param_7);  /* 0x968a80:[team*0x1f0|off=0x9f5f8|ldr w0, [x8, x9]] */
        func_0x00a5f734(param_2,uVar14,uVar5);  /* 0x95f734:[slot*1000,team*0x1f0,team*51000|off=0x83c70|str w19, [x8, x9]] */
        uVar5 = func_0x00a6b13c(param_2,iVar9,param_7);  /* 0x96b13c:[team*0x1f0|off=0x23365c|ldr w0, [x8, x9]] */
        func_0x00a5f828(param_2,uVar14,uVar5);  /* 0x95f828:[slot*1000,team*51000|off=0x83ce0|str w19, [x8, x9]] */
        uVar5 = func_0x00a6b198(param_2,iVar9,param_7);  /* 0x96b198:[team*0x1f0|off=0x233660|ldr w0, [x8, x9]] */
        func_0x00a5f8b4(param_2,uVar14,uVar5);  /* 0x95f8b4:[slot*1000,team*51000|off=0x83ce4|str w19, [x8, x9]] */
        uVar6 = func_0x00a67240(param_2,iVar9,param_7);  /* 0x967240:[team*0x1f0|off=0x2331b0,0x9e634|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        func_0x00a5f9dc(param_2,uVar14,uVar6 & 1);  /* 0x95f9dc:[slot*1000,team*51000|off=0x83a64|str w21, [x8, x9]] */
        uVar6 = func_0x00a68af0(param_2,iVar9,param_7);  /* 0x968af0:[team*0x1f0|off=0x233564|ldr w8, [x8, x9]] */
        func_0x00a5fcc0(param_2,uVar14,uVar6 & 1);  /* 0x95fcc0:[slot*1000,team*51000|off=0x83ac4|str w21, [x8, x9]] */
        uVar6 = func_0x00a6b1f4(param_2,iVar9,param_7);  /* 0x96b1f4:[team*0x1f0|off=0x9f518|ldr w8, [x8, x9]] */
        func_0x00a5fde8(param_2,uVar14,uVar6 & 1);  /* 0x95fde8:[slot*1000,team*51000|off=0x83ad8|str w21, [x8, x9]] */
        uVar5 = func_0x00a68c0c(param_2,iVar9,param_7);  /* 0x968c0c:[team*0x1f0|off=0x2335a0|ldr w0, [x8, x9]] */
        func_0x00a5fe74(param_2,uVar14,uVar5);  /* 0x95fe74:[slot*1000,team*51000|off=0x83b10|str w19, [x8, x9]] */
        uVar5 = func_0x00a6b348(param_2,iVar9,param_7,param_8);  /* 0x96b348:[team*0x1f0|off=0x327f0c,0x32c658,0x327f0c,0x2335fc,0x9e560,0x51eb851f,0x2335fc|ldr w8, [x0, x8] ; ldrb w8, [x0, x8] ; ldr w22, [x0, x8] ; ldr w20, [x8, x9]] */
        func_0x00a5ff00(param_2,uVar14,uVar5);  /* 0x95ff00:[slot*1000,team*51000|off=0x83be8|str w19, [x8, x9]] */
        uVar5 = func_0x00a68c68(param_2,iVar9,param_7);  /* 0x968c68:[team*0x1f0|off=0x233600|ldr w0, [x8, x9]] */
        func_0x00a5ff8c(param_2,uVar14,uVar5);  /* 0x95ff8c:[slot*1000,team*51000|off=0x83bec|str w19, [x8, x9]] */
        uVar6 = func_0x00a67384(param_2,iVar9,param_7);  /* 0x967384:[team*0x1f0|off=0x233230,0x9e6a4|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        func_0x00a60020(param_2,uVar14,uVar6 & 1);  /* 0x960020:[slot*1000,team*51000|off=0x83b44|str w21, [x8, x9]] */
        uVar5 = func_0x00a68198(param_2,iVar9,param_7);  /* 0x968198:[team*0x1f0|off=0x23324c,0x9e6c8|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a600ac(param_2,uVar14,uVar5);  /* 0x9600ac:[slot*1000,team*51000|off=0x83b9c|str w19, [x8, x9]] */
        uVar5 = func_0x00a6b4d0(param_2,iVar9,param_7);  /* 0x96b4d0:[team*0x1f0|off=0x233250,0x9e6cc|ldr w0, [x8, x9] ; ldr w22, [x8, x9]] */
        func_0x00a60138(param_2,uVar14,uVar5);  /* 0x960138:[slot*1000,team*51000|off=0x83ba8|str w19, [x8, x9]] */
        func_0x00a62ccc(param_2,uVar14,0);  /* 0x962ccc:[slot*1000,team*51000|off=0x83cb4|str w19, [x8, x9]] */
        func_0x00a62d58(param_2,uVar14,0);  /* 0x962d58:[slot*1000,team*51000|off=0x83cb8|str w19, [x8, x9]] */
        if (((!bVar3 && !bVar2) &&
            (uVar10 = func_0x005b2394(param_1 + (long)param_2 * 0x1f0 + 0x2648,0,uVar14),
            (uVar10 & 1) != 0)) &&
           (uVar10 = func_0x006532b8(param_1 + 0x1538,iVar9,0xd), (uVar10 & 1) != 0)) {
          uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xd,0,0);
          func_0x00a62ccc(0,uVar14,uVar5);  /* 0x962ccc:[slot*1000,team*51000|off=0x83cb4|str w19, [x8, x9]] */
          uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xd,1,0);
          func_0x00a62d58(0,uVar14,uVar5);  /* 0x962d58:[slot*1000,team*51000|off=0x83cb8|str w19, [x8, x9]] */
        }
        func_0x00a6073c(param_2,uVar14,0);  /* 0x96073c:[slot*1000,team*51000|off=0x839a0|str w21, [x8, x9]] */
        func_0x00a607d0(param_2,uVar14,0);  /* 0x9607d0:[slot*1000,team*51000|off=0x839f8|str w21, [x8, x9]] */
        func_0x00a608e8(param_2,uVar14,0);  /* 0x9608e8:[slot*1000,team*51000|off=0x839fc|str w19, [x8, x9]] */
        func_0x00a609c8(param_2,uVar14,0);  /* 0x9609c8:[slot*1000,team*51000|off=0x83a10|str w19, [x8, x9]] */
        func_0x00a60a54(param_2,uVar14,0);  /* 0x960a54:[slot*1000,team*51000|off=0x83c78|str w19, [x8, x9]] */
        func_0x00a60ae0(param_2,uVar14,0);  /* 0x960ae0:[slot*1000,team*51000|off=0x83a00|str w19, [x8, x9]] */
        func_0x00a60bc0(param_2,uVar14,0);  /* 0x960bc0:[slot*1000,team*51000|off=0x83a14|str w19, [x8, x9]] */
        func_0x00a60c4c(param_2,uVar14,0);  /* 0x960c4c:[slot*1000,team*51000|off=0x83c7c|str w19, [x8, x9]] */
        lVar12 = param_1 + (long)param_2 * 51000 + uVar14 * 1000;
        *(undefined4 *)(lVar12 + 0x83a04) = 0;
        func_0x00a59ab0(param_2,uVar14,0);  /* 0x959ab0:[slot*1000,team*51000|off=0x83a0c|str w19, [x8, x9]] */
        func_0x00a60cd8(param_2,uVar14,0);  /* 0x960cd8:[slot*1000,team*51000|off=0x83a34|str w19, [x8, x9]] */
        func_0x00a60db8(param_2,uVar14,0);  /* 0x960db8:[slot*1000,team*51000|off=0x83a38|str w19, [x8, x9]] */
        func_0x00a60ed0(param_2,uVar14,0);  /* 0x960ed0:[slot*1000,team*51000|off=0x83c80|str w19, [x8, x9]] */
        func_0x00a60e44(param_2,uVar14,0);  /* 0x960e44:[slot*1000,team*51000|off=0x83a44|str w19, [x8, x9]] */
        *(undefined4 *)(lVar12 + 0x83a40) = 0;
        *(undefined4 *)(lVar12 + 0x83a3c) = 0;
        *(undefined4 *)(lVar12 + 0x83a48) = 0;
        func_0x00a614dc(param_2,uVar14,0);  /* 0x9614dc:[slot*1000,team*51000|off=0x83ba0|str w21, [x8, x9]] */
        func_0x00a61568(param_2,uVar14,0);  /* 0x961568:[slot*1000,team*51000|off=0x83ba4|str w19, [x8, x9]] */
        func_0x00a61730(param_2,uVar14,0);  /* 0x961730:[slot*1000,team*51000|off=0x83bbc|str w21, [x8, x9]] */
        uVar5 = func_0x00a6b348(param_2,iVar9,param_7,param_8);  /* 0x96b348:[team*0x1f0|off=0x327f0c,0x32c658,0x327f0c,0x2335fc,0x9e560,0x51eb851f,0x2335fc|ldr w8, [x0, x8] ; ldrb w8, [x0, x8] ; ldr w22, [x0, x8] ; ldr w20, [x8, x9]] */
        func_0x00a617bc(param_2,uVar14,uVar5);  /* 0x9617bc:[slot*1000,team*51000|off=0x83c00|str w19, [x8, x9]] */
        func_0x00a618d4(param_2,uVar14,0);  /* 0x9618d4:[slot*1000,team*51000|off=0x83c08|str w19, [x8, x9]] */
        func_0x00a61b20(param_2,uVar14,0);  /* 0x961b20:[slot*1000,team*51000|off=0x83c50|str w19, [x8, x9]] */
        func_0x00a61c08(param_2,uVar14,0);  /* 0x961c08:[slot*1000,team*51000|off=0x83c74|str w21, [x8, x9]] */
        func_0x00a61c94(param_2,uVar14,0);  /* 0x961c94:[slot*1000,team*51000|off=0x83cb0|str w19, [x8, x9]] */
        func_0x00a61434(param_2,uVar14,0,0);  /* 0x961434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        func_0x00a61434(param_2,uVar14,1,0);  /* 0x961434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        func_0x00a61434(param_2,uVar14,2,0);  /* 0x961434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        func_0x00a61434(param_2,uVar14,3,0);  /* 0x961434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        func_0x00a61434(param_2,uVar14,4,0);  /* 0x961434:[slot*1000,team*51000|off=0x83908|str w19, [x8, x9]] */
        *(undefined8 *)(lVar12 + 0x83a78) = 0;
        *(undefined8 *)(lVar12 + 0x83a80) = 0;
        *(undefined4 *)(lVar12 + 0x83a88) = 0;
        func_0x00a61140(param_2,uVar14,0);  /* 0x961140:[slot*1000,team*51000|off=0x83b1c|str w21, [x8, x9]] */
        func_0x00a612ac(param_2,uVar14,0);  /* 0x9612ac:[slot*1000,team*51000|off=0x83b34|str w19, [x8, x9]] */
        func_0x00a60f80(param_2,uVar14,0);  /* 0x960f80:[slot*1000,team*51000|off=0x83b60|str w19, [x8, x9]] */
        func_0x00a61020(param_2,uVar14,0);  /* 0x961020:[slot*1000,team*51000|off=0x83b64|str w19, [x8, x9]] */
        func_0x00a610ac(param_2,uVar14,0);  /* 0x9610ac:[slot*1000,team*51000|off=0x83c84|str w19, [x8, x9]] */
        uVar10 = func_0x00a66e54(param_2,iVar9,param_7);  /* 0x966e54:[team*0x1f0|off=0x2331c0,0x9e644|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x12,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x15,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fc2c(param_2,uVar14,0);  /* 0x95fc2c:[slot*1000,team*51000|off=0x83a74|str w21, [x8, x9]] */
        func_0x00a62754(param_2,uVar14,0);  /* 0x962754:[slot*1000,team*51000|off=0x83b6c|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a62754(param_2,uVar14,iVar4);  /* 0x962754:[slot*1000,team*51000|off=0x83b6c|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5fc2c(param_2,uVar14,1);  /* 0x95fc2c:[slot*1000,team*51000|off=0x83a74|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a66f0c(param_2,iVar9,param_7);  /* 0x966f0c:[team*0x1f0|off=0x2331b8,0x9e63c|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x13,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x14,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fb04(param_2,uVar14,0);  /* 0x95fb04:[slot*1000,team*51000|off=0x83a6c|str w21, [x8, x9]] */
        func_0x00a627e0(param_2,uVar14,0);  /* 0x9627e0:[slot*1000,team*51000|off=0x83b70|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a627e0(param_2,uVar14,iVar4);  /* 0x9627e0:[slot*1000,team*51000|off=0x83b70|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5fb04(param_2,uVar14,1);  /* 0x95fb04:[slot*1000,team*51000|off=0x83a6c|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a66fc4(param_2,iVar9,param_7);  /* 0x966fc4:[team*0x1f0|off=0x2331bc,0x9e640|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x14,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xe,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fb98(param_2,uVar14,0);  /* 0x95fb98:[slot*1000,team*51000|off=0x83a70|str w21, [x8, x9]] */
        func_0x00a6286c(param_2,uVar14,0);  /* 0x96286c:[slot*1000,team*51000|off=0x83b74|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a6286c(param_2,uVar14,iVar4);  /* 0x96286c:[slot*1000,team*51000|off=0x83b74|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5fb98(param_2,uVar14,1);  /* 0x95fb98:[slot*1000,team*51000|off=0x83a70|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a6707c(param_2,iVar9,param_7);  /* 0x96707c:[team*0x1f0|off=0x2331b4,0x9e638|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x15,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,8,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fa70(param_2,uVar14,0);  /* 0x95fa70:[slot*1000,team*51000|off=0x83a68|str w21, [x8, x9]] */
        func_0x00a628f8(param_2,uVar14,0);  /* 0x9628f8:[slot*1000,team*51000|off=0x83b78|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a628f8(param_2,uVar14,iVar4);  /* 0x9628f8:[slot*1000,team*51000|off=0x83b78|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5fa70(param_2,uVar14,1);  /* 0x95fa70:[slot*1000,team*51000|off=0x83a68|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a669f4(param_2,iVar9,param_7);  /* 0x9669f4:[team*0x1f0|off=0x2331ac,0x9e630|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x16,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (bVar3 || bVar2) goto LAB_009b8a18;
          iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,6,0,0);
          iVar4 = iVar7 + iVar4;
LAB_009b8a40:
          iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x1a,iVar9);
          iVar7 = iVar4 + 100;
          if (iVar8 < 1) {
            iVar7 = iVar4;
          }
        }
        else {
          iVar4 = 100;
LAB_009b8a18:
          iVar7 = iVar4;
          if (param_2 == 0) goto LAB_009b8a40;
        }
        func_0x00a5f948(param_2,uVar14,0);  /* 0x95f948:[slot*1000,team*51000|off=0x83a60|str w21, [x8, x9]] */
        func_0x00a62984(param_2,uVar14,0);  /* 0x962984:[slot*1000,team*51000|off=0x83b7c|str w19, [x8, x9]] */
        if (iVar7 < 100) {
          func_0x00a62984(param_2,uVar14,iVar7);  /* 0x962984:[slot*1000,team*51000|off=0x83b7c|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5f948(param_2,uVar14,1);  /* 0x95f948:[slot*1000,team*51000|off=0x83a60|str w21, [x8, x9]] */
        }
        uVar5 = func_0x00a63984(param_2,iVar9,param_7,0x18,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
        func_0x00a62a10(param_2,uVar14,uVar5);  /* 0x962a10:[slot*1000,team*51000|off=0x83b80|str w19, [x8, x9]] */
        uVar10 = func_0x00a674b4(param_2,iVar9,param_7);  /* 0x9674b4:[team*0x1f0|off=0x2332bc,0x9e6b4|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x1e,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xf,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a5fd54(param_2,uVar14,0);  /* 0x95fd54:[slot*1000,team*51000|off=0x83b5c|str w21, [x8, x9]] */
        func_0x00a62a9c(param_2,uVar14,0);  /* 0x962a9c:[slot*1000,team*51000|off=0x83b84|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a62a9c(param_2,uVar14,iVar4);  /* 0x962a9c:[slot*1000,team*51000|off=0x83b84|str w19, [x8, x9]] */
        }
        else {
          func_0x00a5fd54(param_2,uVar14,1);  /* 0x95fd54:[slot*1000,team*51000|off=0x83b5c|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a683b4(param_2,iVar9,param_7);  /* 0x9683b4:[team*0x1f0|off=0x9f5a0|ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x34,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (!bVar3 && !bVar2) {
            iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0xc,0,0);
            iVar4 = iVar7 + iVar4;
          }
        }
        else {
          iVar4 = 100;
        }
        func_0x00a601cc(param_2,uVar14,0);  /* 0x9601cc:[slot*1000,team*51000|off=0x83bd0|str w21, [x8, x9]] */
        func_0x00a62b28(param_2,uVar14,0);  /* 0x962b28:[slot*1000,team*51000|off=0x83bd8|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a62b28(param_2,uVar14,iVar4);  /* 0x962b28:[slot*1000,team*51000|off=0x83bd8|str w19, [x8, x9]] */
        }
        else {
          func_0x00a601cc(param_2,uVar14,1);  /* 0x9601cc:[slot*1000,team*51000|off=0x83bd0|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a684f0(param_2,iVar9,param_7);  /* 0x9684f0:[team*0x1f0|off=0x23326c,0x9e6e4|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        if ((uVar10 & 1) == 0) {
          iVar4 = func_0x00a63984(param_2,iVar9,param_7,0x36,0);  /* 0x963984:[|off=|ldr x8, [x26, #0xc0]! ; ldr x8, [x22] ; ldr w8, [x8, #0x1c] ; ldr x8, [x22, #8]] */
          if (bVar3 || bVar2) goto LAB_009b8c48;
          iVar7 = func_0x00653738(param_1 + 0x1538,iVar9,0x17,0,0);
          iVar4 = iVar7 + iVar4;
LAB_009b8c70:
          iVar8 = func_0x008700d4(param_1 + 0x4407e8,0x1c,iVar9);
          iVar7 = iVar4 + 100;
          if (iVar8 < 1) {
            iVar7 = iVar4;
          }
        }
        else {
          iVar4 = 100;
LAB_009b8c48:
          iVar7 = iVar4;
          if (param_2 == 0) goto LAB_009b8c70;
        }
        func_0x00a60260(param_2,uVar14,0);  /* 0x960260:[slot*1000,team*51000|off=0x83bd4|str w21, [x8, x9]] */
        func_0x00a62bb4(param_2,uVar14,0);  /* 0x962bb4:[slot*1000,team*51000|off=0x83bdc|str w19, [x8, x9]] */
        if (iVar7 < 100) {
          func_0x00a62bb4(param_2,uVar14,iVar7);  /* 0x962bb4:[slot*1000,team*51000|off=0x83bdc|str w19, [x8, x9]] */
        }
        else {
          func_0x00a60260(param_2,uVar14,1);  /* 0x960260:[slot*1000,team*51000|off=0x83bd4|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a68d6c(param_2,iVar9,param_7);  /* 0x968d6c:[team*0x1f0|off=0x2332cc,0x9e748|ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        iVar4 = 100;
        if ((uVar10 & 1) == 0) {
          iVar4 = 0;
        }
        if ((!bVar3 && !bVar2) && (uVar10 & 1) == 0) {
          iVar4 = func_0x00653738(param_1 + 0x1538,iVar9,0x19,0,0);
        }
        func_0x00a602f4(param_2,uVar14,0);  /* 0x9602f4:[slot*1000,team*51000|off=0x83c94|str w21, [x8, x9]] */
        func_0x00a62c40(param_2,uVar14,0);  /* 0x962c40:[slot*1000,team*51000|off=0x83cdc|str w19, [x8, x9]] */
        if (iVar4 < 100) {
          func_0x00a62c40(param_2,uVar14,iVar4);  /* 0x962c40:[slot*1000,team*51000|off=0x83cdc|str w19, [x8, x9]] */
        }
        else {
          func_0x00a602f4(param_2,uVar14,1);  /* 0x9602f4:[slot*1000,team*51000|off=0x83c94|str w21, [x8, x9]] */
        }
        uVar10 = func_0x00a6b26c(param_2,iVar9,param_7);  /* 0x96b26c:[team*0x1f0|off=0x9f60c|ldr w8, [x8, x9]] */
        func_0x00a60388(param_2,uVar14,0);  /* 0x960388:[slot*1000,team*51000|off=0x83cec|str w21, [x8, x9]] */
        if ((uVar10 & 1) != 0) {
          func_0x00a60388(param_2,uVar14,1);  /* 0x960388:[slot*1000,team*51000|off=0x83cec|str w21, [x8, x9]] */
        }
        lVar12 = param_1 + (long)param_2 * 0x1f0;
        uVar10 = func_0x005b1be4(lVar12 + 0x2648);
        if ((uVar10 & 1) == 0) {
          uVar5 = func_0x009cbce0(*(long *)(param_1 + 0x9e560) + (long)param_8 * 0x38);
          func_0x00a59a04(param_2,uVar14,uVar5);  /* 0x959a04:[slot*1000,team*0x1f0,team*51000|off=0x83a08|str w19, [x8, x9]] */
          uVar10 = func_0x00a59560(param_2,uVar14);  /* 0x959560:[slot*1000,team*0x1f0,team*51000|off=0x83a08|ldr w8, [x8, x9]] */
          if ((uVar10 & 1) != 0) {
            iVar7 = func_0x00a5780c(1);  /* 0x95780c:[team*51000|off=0x83920|ldr w0, [x8, x9]] */
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);  /* field_off=0x327fa0 */
            iVar4 = (int)((ulong)((long)(extraout_w1 * 0x49c) * -0x51eb851f) >> 0x20);
            uVar5 = BattleFn_0x004ab0a8();
            iVar8 = func_0x00646668(&UNK_00327fa0 + param_1,uVar5);  /* field_off=0x327fa0 */
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);  /* field_off=0x327fa0 */
            uVar5 = BattleFn_0x004ab0a8();
            func_0x00646668(&UNK_00327fa0 + param_1,uVar5);  /* field_off=0x327fa0 */
            func_0x00a591dc(param_2,uVar14,  /* 0x9591dc:[slot*1000,team*51000|off=0x83914|str w19, [x8, x9]] */
                            ((iVar4 >> 5) - (iVar4 >> 0x1f)) + iVar7 +
                            (extraout_w1_00 * iVar8) / 10 + (extraout_w1_01 * 0x7f) / 10);
          }
          lVar13 = param_1 + (long)param_3 * 0x1c4;
          func_0x00a61e7c(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7224));  /* 0x961e7c:[slot*1000,team*0x1f0,team*51000|off=0x83a8c|str w19, [x8, x9]] */
          func_0x00a62004(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x722c));  /* 0x962004:[slot*1000,team*0x1f0,team*51000|off=0x83aa4|str w19, [x8, x9]] */
          func_0x00a62124(param_2,uVar14,0);  /* 0x962124:[slot*1000,team*0x1f0,team*51000|off=0x83c3c|str w19, [x8, x9]] */
          func_0x00a6226c(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7234));  /* 0x96226c:[slot*1000,team*0x1f0,team*51000|off=0x83aa8|str w19, [x8, x9]] */
          func_0x00a62340(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7230));  /* 0x962340:[slot*1000,team*0x1f0,team*51000|off=0x83aac|str w19, [x8, x9]] */
          func_0x00a62414(param_2,uVar14,*(undefined4 *)((long)__DT_JMPREL + lVar13 + 0x7228));  /* 0x962414:[slot*1000,team*0x1f0,team*51000|off=0x83ab0|str w19, [x8, x9]] */
          func_0x00a625c4(param_2,uVar14,0);  /* 0x9625c4:[slot*1000,team*0x1f0,team*51000|off=0x83ab4|str w20, [x8, x9]] */
          func_0x00a626a4(param_2,uVar14,0);  /* 0x9626a4:[slot*1000,team*0x1f0,team*51000|off=0x83ad0|str w20, [x8, x9]] */
          uVar5 = func_0x009cbd14(*(long *)(param_1 + 0x9e560) + (long)param_8 * 0x38);
          func_0x00a59c1c(param_2,uVar14,uVar5);  /* 0x959c1c:[slot*1000,team*51000|off=0x83acc|str w19, [x8, x9]] */
          if (!bVar3 && !bVar2) goto LAB_009b8f94;
LAB_009b9038:
          func_0x00a62de4(param_2,uVar14,0);  /* 0x962de4:[slot*1000,team*51000|off=0x83cbc|str w19, [x8, x9]] */
          func_0x00a62e70(param_2,uVar14,0);  /* 0x962e70:[slot*1000,team*51000|off=0x83cd0|str w19, [x8, x9]] */
          uVar5 = 0;
        }
        else {
          func_0x00a59a04(param_2,uVar14,0);  /* 0x959a04:[slot*1000,team*0x1f0,team*51000|off=0x83a08|str w19, [x8, x9]] */
          if (bVar3 || bVar2) goto LAB_009b9038;
LAB_009b8f94:
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0xb,0,0);
          }
          func_0x00a62de4(0,uVar14,uVar5);  /* 0x962de4:[slot*1000,team*51000|off=0x83cbc|str w19, [x8, x9]] */
          func_0x00a62e70(0,uVar14,0);  /* 0x962e70:[slot*1000,team*51000|off=0x83cd0|str w19, [x8, x9]] */
          uVar10 = func_0x005b2394(lVar12 + 0x2648,0,uVar14);
          uVar5 = 0;
          if ((uVar10 & 1) != 0) {
            uVar5 = func_0x006535d4(param_1 + 0x1538,iVar9,0x18,0,0);
          }
        }
        func_0x00a62efc(param_2,uVar14,uVar5);  /* 0x962efc:[slot*1000,team*51000|off=0x83cd4|str w19, [x8, x9]] */
        param_1 = param_1 + (long)param_2 * 0x1f0;
        *(int *)(param_1 + 0x281c) = *(int *)(param_1 + 0x281c) + 1;
        func_0x00a5a0a8(param_2,uVar14);  /* 0x95a0a8:[slot*1000,team*51000|off=0x83cc8|str w19, [x8, x9]] */
        func_0x00a5a0f4(param_2,uVar14,0);  /* 0x95a0f4:[slot*1000,team*51000|off=0x83ccc|str w19, [x8, x9]] */
        uVar10 = func_0x00a59f40(param_2,uVar14);  /* 0x959f40:[slot*1000,team*51000|off=0x83b08|ldr w8, [x8, x9]] */
        uVar5 = 10;
        if ((uVar10 & 1) == 0) {
          iVar9 = func_0x00a59e28(param_2,uVar14);  /* 0x959e28:[slot*1000,team*51000|off=0x83b00|ldr w0, [x8, x9]] */
          uVar5 = 0;
          if (-1 < iVar9) {
            uVar5 = 10;
          }
        }
        func_0x00a58be4(param_2,uVar14,uVar5);  /* 0x958be4:[slot*1000,team*0x1f0,team*51000|off=0x83bf0,0x83bf0,0x83930,0x83c3c|ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9] ; ldr w8, [x8, x9]] */
        goto LAB_009b90d4;
      }
      uVar14 = (ulong)(iVar7 + 1U);
    } while (iVar7 + 1U != 0x33);
    uVar14 = 0xffffffff;
  }
LAB_009b90d4:
  if (*(long *)(lVar1 + 0x28) == lStack_68) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  NoRet_0x00ac3380();
}


