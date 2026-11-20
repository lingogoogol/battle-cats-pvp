// ELF VMA: 0x5c731c
// Ghidra Addr: 0x006c731c (ImageBase=0x100000)
// Function: Battle_MainUpdateLoop
// Size: 27916 bytes
// Callees (8): Battle_Get_83938@0x95a59c, Battle_CheckUnitCanMove@0x95a494, Battle_Sub5DBC18@0x5dbc18, Battle_Add_83ad4@0x959cf4, Battle_AttackTrigger_95c5f4@0x95c5f4, Battle_AttackHitDispatch@0x4c5e0c, Battle_Sub8B99A0@0x8b99a0, Battle_SpawnOrInitUnit@0x8b6dec, 


/* WARNING: Possible PIC construction at 0x006c75f8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c89e8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c9510: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006cd614: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006cd6ac: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c9954: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c99c4: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c8d54: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c8e2c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c8c4c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c909c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c90e0: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c8c9c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x006c8a0c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x006c8ca0) */
/* WARNING: Removing unreachable block (ram,0x006c8ca4) */
/* WARNING: Removing unreachable block (ram,0x006c8cb4) */
/* WARNING: Removing unreachable block (ram,0x006c8c78) */
/* WARNING: Removing unreachable block (ram,0x006c8c7c) */
/* WARNING: Removing unreachable block (ram,0x006c8cc4) */
/* WARNING: Removing unreachable block (ram,0x006c8cc8) */
/* WARNING: Removing unreachable block (ram,0x006c8ce0) */
/* WARNING: Removing unreachable block (ram,0x006c8cc0) */
/* WARNING: Removing unreachable block (ram,0x006c90e4) */
/* WARNING: Removing unreachable block (ram,0x006c90e8) */
/* WARNING: Removing unreachable block (ram,0x006c90f4) */
/* WARNING: Removing unreachable block (ram,0x006c90a0) */
/* WARNING: Removing unreachable block (ram,0x006c90a4) */
/* WARNING: Removing unreachable block (ram,0x006c90b4) */
/* WARNING: Removing unreachable block (ram,0x006c9058) */
/* WARNING: Removing unreachable block (ram,0x006c90c0) */
/* WARNING: Removing unreachable block (ram,0x006c8c50) */
/* WARNING: Removing unreachable block (ram,0x006c904c) */
/* WARNING: Removing unreachable block (ram,0x006c8c54) */
/* WARNING: Removing unreachable block (ram,0x006c9110) */
/* WARNING: Removing unreachable block (ram,0x006c911c) */
/* WARNING: Removing unreachable block (ram,0x006c9120) */
/* WARNING: Removing unreachable block (ram,0x006c8c64) */
/* WARNING: Removing unreachable block (ram,0x006c9050) */
/* WARNING: Removing unreachable block (ram,0x006c9068) */
/* WARNING: Removing unreachable block (ram,0x006c907c) */
/* WARNING: Removing unreachable block (ram,0x006c905c) */
/* WARNING: Removing unreachable block (ram,0x006c90c4) */
/* WARNING: Removing unreachable block (ram,0x006c90c8) */
/* WARNING: Removing unreachable block (ram,0x006c90cc) */
/* WARNING: Removing unreachable block (ram,0x006c9088) */
/* WARNING: Removing unreachable block (ram,0x006c8e30) */
/* WARNING: Removing unreachable block (ram,0x006c8e34) */
/* WARNING: Removing unreachable block (ram,0x006c8e44) */
/* WARNING: Removing unreachable block (ram,0x006c8e58) */
/* WARNING: Removing unreachable block (ram,0x006c8dcc) */
/* WARNING: Removing unreachable block (ram,0x006c8e64) */
/* WARNING: Removing unreachable block (ram,0x006c8e08) */
/* WARNING: Removing unreachable block (ram,0x006c8e68) */
/* WARNING: Removing unreachable block (ram,0x006c8e78) */
/* WARNING: Removing unreachable block (ram,0x006c9140) */
/* WARNING: Removing unreachable block (ram,0x006c9168) */
/* WARNING: Removing unreachable block (ram,0x006c91cc) */
/* WARNING: Removing unreachable block (ram,0x006c9178) */
/* WARNING: Removing unreachable block (ram,0x006c91e0) */
/* WARNING: Removing unreachable block (ram,0x006c91f4) */
/* WARNING: Removing unreachable block (ram,0x006c91fc) */
/* WARNING: Removing unreachable block (ram,0x006c9204) */
/* WARNING: Removing unreachable block (ram,0x006c9210) */
/* WARNING: Removing unreachable block (ram,0x006c917c) */
/* WARNING: Removing unreachable block (ram,0x006c9214) */
/* WARNING: Removing unreachable block (ram,0x006c92d8) */
/* WARNING: Removing unreachable block (ram,0x006c921c) */
/* WARNING: Removing unreachable block (ram,0x006c922c) */
/* WARNING: Removing unreachable block (ram,0x006c9238) */
/* WARNING: Removing unreachable block (ram,0x006c9244) */
/* WARNING: Removing unreachable block (ram,0x006c92dc) */
/* WARNING: Removing unreachable block (ram,0x006c934c) */
/* WARNING: Removing unreachable block (ram,0x006c8e88) */
/* WARNING: Removing unreachable block (ram,0x006c929c) */
/* WARNING: Removing unreachable block (ram,0x006c8ea4) */
/* WARNING: Removing unreachable block (ram,0x006c8ee0) */
/* WARNING: Removing unreachable block (ram,0x006c8eb8) */
/* WARNING: Removing unreachable block (ram,0x006c8eec) */
/* WARNING: Removing unreachable block (ram,0x006c8f00) */
/* WARNING: Removing unreachable block (ram,0x006c8f0c) */
/* WARNING: Removing unreachable block (ram,0x006c8f1c) */
/* WARNING: Removing unreachable block (ram,0x006c8f50) */
/* WARNING: Removing unreachable block (ram,0x006c8f24) */
/* WARNING: Removing unreachable block (ram,0x006c8f30) */
/* WARNING: Removing unreachable block (ram,0x006c8f54) */
/* WARNING: Removing unreachable block (ram,0x006c8f9c) */
/* WARNING: Removing unreachable block (ram,0x006c8f74) */
/* WARNING: Removing unreachable block (ram,0x006c8fc8) */
/* WARNING: Removing unreachable block (ram,0x006c8fe8) */
/* WARNING: Removing unreachable block (ram,0x006c8ff4) */
/* WARNING: Removing unreachable block (ram,0x006c9004) */
/* WARNING: Removing unreachable block (ram,0x006c9028) */
/* WARNING: Removing unreachable block (ram,0x006c9040) */
/* WARNING: Removing unreachable block (ram,0x006c9048) */
/* WARNING: Removing unreachable block (ram,0x006c8f80) */
/* WARNING: Removing unreachable block (ram,0x006c8f88) */
/* WARNING: Removing unreachable block (ram,0x006c8f98) */
/* WARNING: Removing unreachable block (ram,0x006c8fa0) */
/* WARNING: Removing unreachable block (ram,0x006c8fb4) */
/* WARNING: Removing unreachable block (ram,0x006c8fbc) */
/* WARNING: Removing unreachable block (ram,0x006c8ec8) */
/* WARNING: Removing unreachable block (ram,0x006c924c) */
/* WARNING: Removing unreachable block (ram,0x006c9264) */
/* WARNING: Removing unreachable block (ram,0x006c9268) */
/* WARNING: Removing unreachable block (ram,0x006c9294) */
/* WARNING: Removing unreachable block (ram,0x006c92ac) */
/* WARNING: Removing unreachable block (ram,0x006c92c8) */
/* WARNING: Removing unreachable block (ram,0x006c92d0) */
/* WARNING: Removing unreachable block (ram,0x006c9354) */
/* WARNING: Removing unreachable block (ram,0x006c92d4) */
/* WARNING: Removing unreachable block (ram,0x006c8d58) */
/* WARNING: Removing unreachable block (ram,0x006c8d5c) */
/* WARNING: Removing unreachable block (ram,0x006c8d6c) */
/* WARNING: Removing unreachable block (ram,0x006c8d7c) */
/* WARNING: Removing unreachable block (ram,0x006c8dc0) */
/* WARNING: Removing unreachable block (ram,0x006c8e18) */
/* WARNING: Removing unreachable block (ram,0x006c99c8) */
/* WARNING: Removing unreachable block (ram,0x006c99cc) */
/* WARNING: Removing unreachable block (ram,0x006c99dc) */
/* WARNING: Removing unreachable block (ram,0x006c99ec) */
/* WARNING: Removing unreachable block (ram,0x006c99f0) */
/* WARNING: Removing unreachable block (ram,0x006c9990) */
/* WARNING: Removing unreachable block (ram,0x006c9a04) */
/* WARNING: Removing unreachable block (ram,0x006c99a4) */
/* WARNING: Removing unreachable block (ram,0x006c9a24) */
/* WARNING: Removing unreachable block (ram,0x006c9a28) */
/* WARNING: Removing unreachable block (ram,0x006c9a3c) */
/* WARNING: Removing unreachable block (ram,0x006c9a00) */
/* WARNING: Removing unreachable block (ram,0x006c9a60) */
/* WARNING: Removing unreachable block (ram,0x006c9a74) */
/* WARNING: Removing unreachable block (ram,0x006c9a84) */
/* WARNING: Removing unreachable block (ram,0x006c9958) */
/* WARNING: Removing unreachable block (ram,0x006c9984) */
/* WARNING: Removing unreachable block (ram,0x006c995c) */
/* WARNING: Removing unreachable block (ram,0x006c9970) */
/* WARNING: Removing unreachable block (ram,0x006c9a14) */
/* WARNING: Removing unreachable block (ram,0x006c9a48) */
/* WARNING: Removing unreachable block (ram,0x006c9980) */
/* WARNING: Removing unreachable block (ram,0x006c9988) */
/* WARNING: Removing unreachable block (ram,0x006c99b0) */
/* WARNING: Removing unreachable block (ram,0x006cd6b0) */
/* WARNING: Removing unreachable block (ram,0x006cd6b4) */
/* WARNING: Removing unreachable block (ram,0x006cd860) */
/* WARNING: Removing unreachable block (ram,0x006cd618) */
/* WARNING: Removing unreachable block (ram,0x006cd61c) */
/* WARNING: Removing unreachable block (ram,0x006c9514) */
/* WARNING: Removing unreachable block (ram,0x006c9518) */
/* WARNING: Removing unreachable block (ram,0x006c94ec) */
/* WARNING: Removing unreachable block (ram,0x006c9558) */
/* WARNING: Removing unreachable block (ram,0x006c9568) */
/* WARNING: Removing unreachable block (ram,0x006c972c) */
/* WARNING: Removing unreachable block (ram,0x006c9754) */
/* WARNING: Removing unreachable block (ram,0x006c97b8) */
/* WARNING: Removing unreachable block (ram,0x006c9764) */
/* WARNING: Removing unreachable block (ram,0x006c97cc) */
/* WARNING: Removing unreachable block (ram,0x006c97e0) */
/* WARNING: Removing unreachable block (ram,0x006c97e8) */
/* WARNING: Removing unreachable block (ram,0x006c97f0) */
/* WARNING: Removing unreachable block (ram,0x006c97fc) */
/* WARNING: Removing unreachable block (ram,0x006c9768) */
/* WARNING: Removing unreachable block (ram,0x006c9800) */
/* WARNING: Removing unreachable block (ram,0x006c98b4) */
/* WARNING: Removing unreachable block (ram,0x006c9808) */
/* WARNING: Removing unreachable block (ram,0x006c9818) */
/* WARNING: Removing unreachable block (ram,0x006c9824) */
/* WARNING: Removing unreachable block (ram,0x006c9830) */
/* WARNING: Removing unreachable block (ram,0x006c98b8) */
/* WARNING: Removing unreachable block (ram,0x006c9920) */
/* WARNING: Removing unreachable block (ram,0x006c9578) */
/* WARNING: Removing unreachable block (ram,0x006c9880) */
/* WARNING: Removing unreachable block (ram,0x006c9598) */
/* WARNING: Removing unreachable block (ram,0x006c95d0) */
/* WARNING: Removing unreachable block (ram,0x006c95a8) */
/* WARNING: Removing unreachable block (ram,0x006c95dc) */
/* WARNING: Removing unreachable block (ram,0x006cc888) */
/* WARNING: Removing unreachable block (ram,0x006cc89c) */
/* WARNING: Removing unreachable block (ram,0x006c95f0) */
/* WARNING: Removing unreachable block (ram,0x006c95fc) */
/* WARNING: Removing unreachable block (ram,0x006c960c) */
/* WARNING: Removing unreachable block (ram,0x006c9628) */
/* WARNING: Removing unreachable block (ram,0x006c9614) */
/* WARNING: Removing unreachable block (ram,0x006cc99c) */
/* WARNING: Removing unreachable block (ram,0x006cc9b0) */
/* WARNING: Removing unreachable block (ram,0x006c961c) */
/* WARNING: Removing unreachable block (ram,0x006c962c) */
/* WARNING: Removing unreachable block (ram,0x006c9678) */
/* WARNING: Removing unreachable block (ram,0x006c964c) */
/* WARNING: Removing unreachable block (ram,0x006c96a8) */
/* WARNING: Removing unreachable block (ram,0x006c96c8) */
/* WARNING: Removing unreachable block (ram,0x006c96d4) */
/* WARNING: Removing unreachable block (ram,0x006c96e4) */
/* WARNING: Removing unreachable block (ram,0x006c9708) */
/* WARNING: Removing unreachable block (ram,0x006c9720) */
/* WARNING: Removing unreachable block (ram,0x006c9728) */
/* WARNING: Removing unreachable block (ram,0x006c965c) */
/* WARNING: Removing unreachable block (ram,0x006c9664) */
/* WARNING: Removing unreachable block (ram,0x006c9674) */
/* WARNING: Removing unreachable block (ram,0x006c9680) */
/* WARNING: Removing unreachable block (ram,0x006c9694) */
/* WARNING: Removing unreachable block (ram,0x006c969c) */
/* WARNING: Removing unreachable block (ram,0x006c95b8) */
/* WARNING: Removing unreachable block (ram,0x006c9838) */
/* WARNING: Removing unreachable block (ram,0x006c984c) */
/* WARNING: Removing unreachable block (ram,0x006ccc14) */
/* WARNING: Removing unreachable block (ram,0x006ccc28) */
/* WARNING: Removing unreachable block (ram,0x006ccc30) */
/* WARNING: Removing unreachable block (ram,0x006ccc44) */
/* WARNING: Removing unreachable block (ram,0x006ccc4c) */
/* WARNING: Removing unreachable block (ram,0x006ccc60) */
/* WARNING: Removing unreachable block (ram,0x006c9850) */
/* WARNING: Removing unreachable block (ram,0x006c9878) */
/* WARNING: Removing unreachable block (ram,0x006c9888) */
/* WARNING: Removing unreachable block (ram,0x006c98a4) */
/* WARNING: Removing unreachable block (ram,0x006c98ac) */
/* WARNING: Removing unreachable block (ram,0x006c9438) */
/* WARNING: Removing unreachable block (ram,0x006c98b0) */
/* WARNING: Removing unreachable block (ram,0x006c89ec) */
/* WARNING: Removing unreachable block (ram,0x006c89f0) */
/* WARNING: Removing unreachable block (ram,0x006c8870) */
/* WARNING: Removing unreachable block (ram,0x006c75fc) */
/* WARNING: Removing unreachable block (ram,0x006c8a10) */
/* WARNING: Removing unreachable block (ram,0x006c8a24) */
/* WARNING: Removing unreachable block (ram,0x006c8a28) */
/* WARNING: Removing unreachable block (ram,0x006c8a38) */
/* WARNING: Removing unreachable block (ram,0x006c8a48) */
/* WARNING: Removing unreachable block (ram,0x006c8a4c) */
/* WARNING: Removing unreachable block (ram,0x006c88a8) */
/* WARNING: Removing unreachable block (ram,0x006c8a5c) */
/* WARNING: Removing unreachable block (ram,0x006c8a70) */
/* WARNING: Removing unreachable block (ram,0x006c8a80) */
/* WARNING: Removing unreachable block (ram,0x006c8a14) */
/* WARNING: Removing unreachable block (ram,0x006c8a20) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ***** Battle_MainUpdateLoop(undefined *****param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  undefined1 auVar8 [16];
  undefined ****ppppuVar9;
  bool bVar10;
  byte bVar11;
  uint uVar12;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar24;
  undefined *****pppppuVar25;
  int *piVar26;
  uint *puVar27;
  long lVar28;
  ulong uVar29;
  long lVar30;
  undefined *****pppppuVar31;
  undefined *****pppppuVar32;
  ulong uVar33;
  undefined8 uVar34;
  undefined *****pppppuVar35;
  undefined1 uVar36;
  undefined ****ppppuVar37;
  undefined ****ppppuVar38;
  undefined ***pppuVar39;
  undefined *****pppppuVar40;
  long *plVar41;
  undefined *****pppppuVar42;
  undefined *****unaff_x22;
  long *plVar43;
  ulong uVar44;
  undefined *****unaff_x23;
  undefined *****pppppuVar45;
  ulong uVar46;
  undefined *****unaff_x25;
  undefined *****unaff_x26;
  undefined *****unaff_x27;
  uint *puVar47;
  undefined8 *******pppppppuVar48;
  undefined8 uVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  undefined1 auVar60 [16];
  byte abStack_610 [88];
  undefined8 uStack_5b8;
  undefined8 uStack_5b0;
  long *plStack_5a8;
  long lStack_598;
  undefined8 *******pppppppuStack_590;
  undefined8 uStack_588;
  undefined *****pppppuStack_580;
  undefined *****pppppuStack_578;
  undefined *****pppppuStack_570;
  undefined *****pppppuStack_568;
  undefined *****pppppuStack_560;
  undefined *****pppppuStack_558;
  undefined ****ppppuStack_550;
  undefined ****ppppuStack_548;
  undefined *****pppppuStack_538;
  undefined *****pppppuStack_530;
  uint *puStack_528;
  undefined *****pppppuStack_520;
  undefined *****pppppuStack_518;
  undefined *****pppppuStack_510;
  undefined *****pppppuStack_508;
  undefined *****pppppuStack_500;
  undefined *****pppppuStack_4f8;
  undefined *****pppppuStack_4f0;
  int iStack_4e4;
  undefined *****pppppuStack_4e0;
  uint *puStack_4d8;
  uint *puStack_4d0;
  undefined *****pppppuStack_4c8;
  undefined *****pppppuStack_4c0;
  undefined *****pppppuStack_4b8;
  undefined *****pppppuStack_4b0;
  undefined *****pppppuStack_4a8;
  long lStack_4a0;
  undefined *****pppppuStack_498;
  undefined *****pppppuStack_490;
  undefined *****pppppuStack_488;
  undefined *****pppppuStack_480;
  undefined *****pppppuStack_478;
  undefined *****pppppuStack_470;
  undefined *****pppppuStack_468;
  ulong uStack_460;
  undefined8 uStack_458;
  undefined *****pppppuStack_450;
  undefined *****pppppuStack_448;
  undefined *****pppppuStack_440;
  undefined *****pppppuStack_438;
  undefined *****pppppuStack_430;
  undefined *****pppppuStack_428;
  uint uStack_41c;
  undefined8 uStack_418;
  uint uStack_40c;
  long lStack_408;
  undefined *****pppppuStack_400;
  undefined8 *puStack_3f8;
  undefined *****pppppuStack_3f0;
  undefined *****pppppuStack_3e8;
  undefined *****pppppuStack_3e0;
  undefined *****pppppuStack_3d8;
  undefined *****pppppuStack_3d0;
  undefined *****pppppuStack_3c8;
  undefined *****pppppuStack_3c0;
  undefined8 uStack_3b8;
  byte abStack_3b0 [16];
  undefined7 uStack_3a0;
  undefined1 uStack_399;
  undefined *****pppppuStack_398;
  ulong uStack_390;
  undefined8 uStack_388;
  undefined8 *puStack_380;
  undefined1 auStack_348 [48];
  byte abStack_318 [16];
  undefined8 uStack_308;
  byte abStack_300 [16];
  undefined8 uStack_2f0;
  byte abStack_2e8 [16];
  undefined8 uStack_2d8;
  byte abStack_2d0 [16];
  undefined8 uStack_2c0;
  byte abStack_2b8 [16];
  undefined8 uStack_2a8;
  undefined *****pppppuStack_2a0;
  undefined8 uStack_298;
  undefined8 *puStack_290;
  undefined1 uStack_280;
  undefined8 uStack_27f;
  undefined7 uStack_277;
  undefined1 uStack_270;
  undefined4 uStack_26f;
  undefined1 uStack_26b;
  undefined2 uStack_26a;
  byte bStack_268;
  undefined5 uStack_267;
  undefined3 uStack_262;
  undefined5 uStack_25f;
  undefined1 uStack_25a;
  undefined8 uStack_258;
  ulong uStack_250;
  undefined8 uStack_248;
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined *****apppppuStack_220 [4];
  undefined ****appppuStack_200 [2];
  undefined ****ppppuStack_1f0;
  undefined *****pppppuStack_1e8;
  long lStack_1e0;
  undefined *****pppppuStack_1d0;
  undefined ****ppppuStack_1c0;
  undefined *****pppppuStack_1b8;
  undefined *****pppppuStack_1a0;
  undefined ****ppppuStack_190;
  undefined *****pppppuStack_188;
  long lStack_180;
  undefined *****pppppuStack_170;
  undefined ****ppppuStack_160;
  undefined *****pppppuStack_158;
  undefined *****pppppuStack_140;
  undefined ****ppppuStack_130;
  undefined *****pppppuStack_128;
  long lStack_120;
  undefined *****pppppuStack_110;
  undefined ****ppppuStack_100;
  undefined *****pppppuStack_f8;
  undefined *****pppppuStack_e0;
  undefined ****ppppuStack_d0;
  undefined *****pppppuStack_c8;
  undefined *****pppppuStack_b0;
  long lStack_98;
  
  pppppppuVar48 = (undefined8 *******)&stack0xffffffffffffffa0;
  ppppuVar9 = (undefined ****)&ppppuStack_550;
  ppppuVar37 = (undefined ****)&ppppuStack_550;
  lStack_4a0 = tpidr_el0;
  lStack_98 = *(long *)(lStack_4a0 + 0x28);
  pppppuVar42 = (undefined *****)&uStack_280;
  bStack_268 = 0x1a;
  uStack_267 = 0x6c74746162;
  uStack_262 = 0x7a5f65;
  uStack_25f = 0x795f6d6f6f;
  uStack_25a = 0;
  uVar12 = func_0x008e3f14(param_1 + 0x28f,&bStack_268,0x208);
  puVar47 = (uint *)((long)param_1 + 0x13dc);
  if (*(char *)((long)param_1 + 0x13dd) == '\0') {
    *(uint *)((long)param_1 + 0x3484) = uVar12;
  }
  else {
    uStack_280 = 0x28;
    uStack_26f = 0x795f7365;
    uStack_277 = 0x696c325f746f6c;
    uStack_270 = 0x6e;
    uStack_27f = 0x735f656c74746162;
    uStack_26b = 0;
    iVar13 = func_0x008e3f14(param_1 + 0x28f,&uStack_280,0xffffffd8);
    *(uint *)((long)param_1 + 0x3484) = iVar13 + uVar12;
    if ((uStack_280 & 1) != 0) {
      func_0x00bc3350(CONCAT26(uStack_26a,CONCAT15(uStack_26b,CONCAT41(uStack_26f,uStack_270))));
    }
  }
  if ((bStack_268 & 1) != 0) {
    func_0x00bc3350(uStack_258);
  }
  if (lRam0000000000c0b8b8 == 0) {
    lStack_408 = 0;
  }
  else {
    lStack_408 = func_0x00bc3a90(lRam0000000000c0b8b8,
                                 &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                                 &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
  }
  _DAT_00c0aed0 = func_0x0043df2c(&DAT_00c0bbc8);
  pppppuVar45 = (undefined *****)&DAT_00c0aed0;
  _DAT_00c0aed0 = 0x220 - _DAT_00c0aed0;
  func_0x007fd748();
  uVar24 = func_0x00805fcc();
  if ((uVar24 & 1) == 0) {
    func_0x007fd748();
    uVar24 = func_0x00807844();
    if ((uVar24 & 1) == 0) {
      *(undefined1 *)puVar47 = 0;
      *(uint *)(param_1 + 0x27a) = 0;
    }
  }
  if (*(char *)puVar47 == '\0') {
    uVar12 = *(uint *)(param_1 + 0x27b) - 1;
    if ((0 < (int)*(uint *)(param_1 + 0x27b)) && (*(uint *)(param_1 + 0x27b) = uVar12, uVar12 == 0))
    {
      *(uint *)((long)param_1 + 0x13d4) = 0xffffffff;
    }
  }
  pppppuVar40 = param_1 + 0x64cc5;
  pppppuStack_488 = (undefined *****)((long)param_1 + 0x327db4);
  func_0x005b1008(param_1 + 0x21a);
  iVar13 = func_0x005ab154();
  if (iVar13 == 0) {
    func_0x006ee2c0(param_1 + 0x1c);
  }
  pppppuStack_4a8 = pppppuVar40;
  if (*(char *)(param_1 + 0x122) == '\0') {
    unaff_x27 = param_1 + 0x64b89;
    if (*(char *)((long)param_1 + 0x326634) != '\0') {
      if (*(char *)pppppuVar40 != '\0') goto LAB_006c7678;
      func_0x008de1dc(param_1 + 0x8d337);
      goto LAB_006c7690;
    }
    unaff_x25 = param_1 + 0x6569b;
    if ((*(char *)unaff_x25 != '\0') || (*(char *)(param_1 + 0x656a4) != '\0')) {
LAB_006c7678:
      if ((*(char *)(param_1 + 0x656a4) == '\0') ||
         (uVar24 = func_0x006e721c(param_1,lStack_408), pppppuVar31 = param_1, (uVar24 & 1) != 0))
      goto LAB_006c7690;
      goto LAB_006c7a20;
    }
    pppppuStack_4b0 = (undefined *****)((long)param_1 + 0x29024c);
    pppppuVar42 = param_1 + 0x656cd;
    unaff_x22 = param_1 + 0x650b3;
    pppppuStack_4f8 = param_1 + 0x64dfa;
    pppppuStack_508 = param_1 + 0x64ccc;
    pppppuVar40 = param_1 + 0x13ca7;
    uVar12 = 0x14a;
    if ((int)*(uint *)(param_1 + 0x65905) < 0x149) {
      uVar12 = *(uint *)(param_1 + 0x65905) + 1;
    }
    pppppuStack_500 = (undefined *****)((long)param_1 + 0x83684);
    unaff_x26 = (undefined *****)&UNK_00392808;
    *(uint *)(param_1 + 0x65905) = uVar12;
    pppppuStack_510 = param_1 + 0x656a4;
    iVar13 = func_0x0043dc7c(param_1);
    fVar50 = (float)(int)*(uint *)((long)param_1 + 0x341c) / 10000.0;
    *(float *)((long)param_1 + 0x3434) = (float)(int)*(uint *)((long)param_1 + 0x3484);
    *(float *)(param_1 + 0x686) = (float)(iVar13 + -0x3c0) / 2.0;
    *(float *)(param_1 + 0x684) = fVar50;
    *(float *)((long)param_1 + 0x342c) = fVar50;
    *(float *)((long)param_1 + 0x3424) = fVar50 * 0.0;
    *(float *)(param_1 + 0x685) = fVar50 * 0.0;
    iVar13 = func_0x0043dc7c(param_1);
    uVar12 = *(uint *)((long)param_1 + 0x3484);
    pppppuStack_3c0 = (undefined *****)(ulong)(uint)((float)(0x3c0 - iVar13) / 2.0);
    uStack_3b8 = 0;
    iVar13 = func_0x005b8008(param_1);
    fVar50 = (float)(int)(iVar13 - uVar12);
    param_1[0x686] =
         (undefined ****)
         CONCAT44((float)((ulong)param_1[0x686] >> 0x20) +
                  (float)((ulong)param_1[0x685] >> 0x20) * fVar50 +
                  (float)((ulong)param_1[0x684] >> 0x20) * SUB84(pppppuStack_3c0,0),
                  SUB84(param_1[0x686],0) +
                  SUB84(param_1[0x685],0) * fVar50 +
                  SUB84(param_1[0x684],0) * SUB84(pppppuStack_3c0,0));
    func_0x007ebd18(param_1 + 0x67d);
    uVar12 = *(uint *)((long)param_1 + 0x341c);
    *(undefined1 *)(param_1 + 0x72501) = 0;
    puStack_4d0 = (uint *)((long)param_1 + 0x38816c);
    ((uint *)((long)param_1 + 0x388184))[0] = 0;
    ((uint *)((long)param_1 + 0x388184))[1] = 0;
    ((uint *)((long)param_1 + 0x38817c))[0] = 0;
    ((uint *)((long)param_1 + 0x38817c))[1] = 0;
    ((uint *)((long)param_1 + 0x388194))[0] = 0;
    ((uint *)((long)param_1 + 0x388194))[1] = 0;
    ((uint *)((long)param_1 + 0x38818c))[0] = 0;
    ((uint *)((long)param_1 + 0x38818c))[1] = 0;
    ((uint *)((long)param_1 + 0x388174))[0] = 0;
    ((uint *)((long)param_1 + 0x388174))[1] = 0;
    puStack_4d0[0] = 0;
    puStack_4d0[1] = 0;
    uVar12 = (int)uVar12 / 100;
    *(uint *)((long)pppppuStack_488 + 4) = uVar12;
    pppppuStack_3c0 = param_1;
    iVar13 = func_0x005ab108();
    unaff_x23 = param_1;
    if (iVar13 != 0) {
      iVar13 = func_0x005ab108();
      if (iVar13 == 1) {
        fVar50 = (float)(int)uVar12 / 100.0;
        uVar12 = (int)((fVar50 * (float)(int)*(uint *)pppppuVar40 + -9600.0) / fVar50) -
                 *(uint *)((long)pppppuStack_500 + 0x14);
        unaff_x23 = (undefined *****)(ulong)uVar12;
        iVar13 = func_0x005ab154();
        if (iVar13 == 0) {
          if ((int)uVar12 < 0x52) {
            uVar12 = *(uint *)pppppuVar40;
            goto LAB_006c79c0;
          }
          *(uint *)((long)pppppuStack_500 + 0x14) =
               *(uint *)((long)pppppuStack_500 + 0x14) + (uVar12 >> 1);
        }
        else if (((int)uVar12 < 0x52) &&
                (uVar15 = *(uint *)((long)pppppuStack_3c0 + 0x341c),
                iVar13 = func_0x005ba6d4(pppppuStack_3c0), pppppuVar31 = pppppuStack_3c0,
                iVar13 <= (int)uVar15)) {
          uVar15 = func_0x005ba6d4(pppppuStack_3c0);
          uVar12 = *(uint *)pppppuVar40;
          *(uint *)((long)pppppuVar31 + 0x341c) = uVar15;
LAB_006c79c0:
          *(uint *)((long)pppppuStack_500 + 0x14) = uVar12 - 0x2580;
LAB_006c79cc:
          func_0x005ab128(0);
        }
        else {
          uVar15 = *(uint *)pppppuVar40;
          if ((int)uVar12 < 0) {
            uVar12 = uVar12 + 1;
          }
          uVar12 = *(uint *)((long)pppppuStack_500 + 0x14) + ((int)uVar12 >> 1);
          *(uint *)((long)pppppuStack_500 + 0x14) = uVar12;
          if ((int)uVar12 < (int)((fVar50 * (float)(int)uVar15 + -9600.0) / fVar50)) {
            if (*(char *)((long)pppppuStack_488 + 0x1c4) == '\0') goto LAB_006c79d4;
          }
          else {
            *(undefined1 *)((long)pppppuStack_488 + 0x1c4) = 1;
          }
          *(uint *)((long)pppppuStack_500 + 0x14) = uVar15 - 0x2580;
        }
      }
      else {
        iVar13 = func_0x005ab108();
        if (iVar13 == 2) {
          uVar12 = *(uint *)((long)pppppuStack_500 + 0x14);
          iVar13 = func_0x005ab154();
          if (iVar13 == 0) {
            if ((int)uVar12 < 0x52) {
LAB_006c798c:
              *(uint *)((long)pppppuStack_500 + 0x14) = 0;
              goto LAB_006c79cc;
            }
            *(uint *)((long)pppppuStack_500 + 0x14) =
                 *(uint *)((long)pppppuStack_500 + 0x14) - (uVar12 >> 1);
          }
          else {
            if ((int)uVar12 < 0x52) {
              uVar15 = *(uint *)((long)pppppuStack_3c0 + 0x341c);
              unaff_x23 = (undefined *****)(ulong)uVar15;
              iVar13 = func_0x005ba6d4();
              if (iVar13 <= (int)uVar15) goto LAB_006c798c;
            }
            if ((int)uVar12 < 0) {
              uVar12 = uVar12 + 1;
            }
            *(uint *)((long)pppppuStack_500 + 0x14) =
                 *(uint *)((long)pppppuStack_500 + 0x14) - ((int)uVar12 >> 1);
          }
        }
      }
    }
LAB_006c79d4:
    iVar13 = func_0x005ab154();
    pppppuVar31 = pppppuStack_3c0;
    if (iVar13 == 1) {
      if (*(char *)(param_1 + 0x64cc5) != '\0') goto LAB_006c7adc;
      uVar24 = func_0x005d1124(pppppuStack_3c0);
joined_r0x006c7ab4:
      if ((uVar24 & 1) != 0) goto LAB_006c7adc;
      goto LAB_006c7a20;
    }
    iVar13 = func_0x005ab154();
    pppppuVar31 = pppppuStack_3c0;
    if (iVar13 == 2) {
      if (*(char *)(param_1 + 0x64cc5) != '\0') goto LAB_006c7adc;
      uVar24 = func_0x005da550(pppppuStack_3c0);
      goto joined_r0x006c7ab4;
    }
    iVar13 = func_0x005ab154();
    if (iVar13 == 3) {
      *(uint *)unaff_x22 = *(uint *)unaff_x22 + 1;
      if (*(char *)(param_1 + 0x64cc5) == '\0') {
        *(uint *)((long)pppppuStack_488 + 0x154) = 0;
        func_0x005ab174(0);
        *(uint *)unaff_x22 = 0;
      }
      goto LAB_006c7ae4;
    }
    iVar13 = func_0x005ab154();
    if (iVar13 == 4) {
      if (*(char *)(param_1 + 0x64cc5) != '\0') goto LAB_006c7adc;
      uVar24 = func_0x005dd010(pppppuVar31);
      goto joined_r0x006c7ab4;
    }
    iVar13 = func_0x005ab154();
    if (iVar13 == 7) {
      if (*(char *)(param_1 + 0x64cc5) != '\0') goto LAB_006c7adc;
      uVar24 = func_0x005de4fc(pppppuVar31);
      goto joined_r0x006c7ab4;
    }
    unaff_x26 = pppppuVar31 + 0x185d;
    unaff_x23 = (undefined *****)((long)pppppuVar31 + 0x4a4ac);
    pppppuStack_3d0 = unaff_x26;
    pppppuStack_3c8 = unaff_x23;
    if (*(uint *)unaff_x26 == 0) {
      uVar12 = *(uint *)((long)pppppuStack_500 + 4);
      func_0x0040cb78(abStack_2b8,&UNK_002a5804);
      iVar13 = func_0x008e3f14(pppppuVar31 + 0x28f,abStack_2b8,0x96);
      unaff_x23 = pppppuVar31;
      if ((int)uVar12 < iVar13) {
        if ((abStack_2b8[0] & 1) != 0) {
          func_0x00bc3350(uStack_2a8);
        }
      }
      else {
        uVar12 = *(uint *)((long)pppppuStack_3c0 + 0x224);
        if ((abStack_2b8[0] & 1) != 0) {
          func_0x00bc3350(uStack_2a8);
        }
        if (uVar12 == 0) {
          func_0x0040cb78(&uStack_250,&UNK_002a1309);
          func_0x0045e320(apppppuStack_220,&uStack_250);
          pppppuVar31 = &ppppuStack_d0;
          ppppuStack_d0 = (undefined ****)&UNK_00be1e28;
          pppppuStack_c8 = pppppuStack_3c0;
          pppppuStack_b0 = pppppuVar31;
          func_0x00868168(pppppuStack_3c0 + 0x5bd,apppppuStack_220,0,0,0,&ppppuStack_d0);
          pppppuVar25 = pppppuStack_b0;
          if (pppppuStack_b0 == pppppuVar31) {
            lVar28 = 4;
            pppppuVar25 = &ppppuStack_d0;
            goto LAB_006ccaa8;
          }
          goto LAB_006ccaa0;
        }
      }
      uVar12 = *(uint *)((long)pppppuStack_500 + 4);
      func_0x0040cb78(abStack_2d0,&UNK_002a5817);
      iVar13 = func_0x008e3f14(pppppuStack_3c0 + 0x28f,abStack_2d0,0x1c2);
      if (iVar13 <= (int)uVar12) {
        unaff_x23 = (undefined *****)0x2de8;
        lVar28 = func_0x00868790(pppppuStack_3c0 + 0x5bd);
        if (lVar28 == 0) {
          uVar12 = *(uint *)((long)pppppuStack_3c0 + 0x224);
          if ((abStack_2d0[0] & 1) != 0) {
            func_0x00bc3350(uStack_2c0);
          }
          if (uVar12 != 1) goto LAB_006cc3c8;
          func_0x0040cb78(&uStack_250,&UNK_002985a1);
          func_0x0045e320(apppppuStack_220,&uStack_250);
          ppppuStack_100 = (undefined ****)&UNK_00be1ea8;
          pppppuStack_f8 = pppppuStack_3c0;
          pppppuStack_e0 = &ppppuStack_100;
          uVar49 = func_0x00868168(pppppuStack_3c0 + 0x5bd,apppppuStack_220,0,0,0x24,&ppppuStack_100
                                  );
          pppppuVar31 = &ppppuStack_130;
          ppppuStack_130 = (undefined ****)&UNK_00be1f28;
          pppppuStack_128 = pppppuStack_3c0;
          lStack_120 = lStack_408;
          pppppuStack_110 = pppppuVar31;
          func_0x00866ca4(uVar49,&ppppuStack_130);
          if (pppppuStack_110 == pppppuVar31) {
            lVar28 = 4;
            pppppuVar25 = &ppppuStack_130;
LAB_006cc974:
            (*(code *)(*pppppuVar25)[lVar28])();
          }
          else if (pppppuStack_110 != (undefined *****)0x0) {
            lVar28 = 5;
            pppppuVar25 = pppppuStack_110;
            goto LAB_006cc974;
          }
          pppppuVar25 = pppppuStack_e0;
          if (pppppuStack_e0 != &ppppuStack_100) goto LAB_006ccaa0;
          lVar28 = 4;
          pppppuVar25 = &ppppuStack_100;
          goto LAB_006ccaa8;
        }
      }
      if ((abStack_2d0[0] & 1) != 0) {
        func_0x00bc3350(uStack_2c0);
      }
    }
    else {
      iVar13 = func_0x007ac230(0);
      if ((((iVar13 == 3000) && (iVar13 = func_0x007ac380(), iVar13 == 1)) &&
          (iVar13 = func_0x009cd640(0xfffffffe,0,1,0,0), iVar13 == 0)) &&
         ((0x17 < (int)*(uint *)((long)pppppuStack_500 + 4) &&
          (*(uint *)((long)pppppuStack_3c0 + 0x224) == 0)))) {
        func_0x0040cb78(&uStack_250,&UNK_0028ad6b);
        func_0x0045e320(apppppuStack_220,&uStack_250);
        ppppuStack_160 = (undefined ****)&UNK_00be1fa8;
        pppppuStack_158 = pppppuStack_3c0;
        pppppuStack_140 = &ppppuStack_160;
        uVar49 = func_0x00868168(pppppuStack_3c0 + 0x5bd,apppppuStack_220,0,0,4,&ppppuStack_160);
        pppppuVar31 = &ppppuStack_190;
        ppppuStack_190 = (undefined ****)&UNK_00be2028;
        pppppuStack_188 = pppppuStack_3c0;
        lStack_180 = lStack_408;
        pppppuStack_170 = pppppuVar31;
        func_0x00866ca4(uVar49,&ppppuStack_190);
        if (pppppuStack_170 == pppppuVar31) {
          lVar28 = 4;
          pppppuVar25 = &ppppuStack_190;
LAB_006cca84:
          (*(code *)(*pppppuVar25)[lVar28])();
        }
        else if (pppppuStack_170 != (undefined *****)0x0) {
          lVar28 = 5;
          pppppuVar25 = pppppuStack_170;
          goto LAB_006cca84;
        }
        pppppuVar25 = pppppuStack_140;
        if (pppppuStack_140 == &ppppuStack_160) {
          lVar28 = 4;
          pppppuVar25 = &ppppuStack_160;
LAB_006ccaa8:
          (*(code *)(*pppppuVar25)[lVar28])();
        }
        else {
LAB_006ccaa0:
          if (pppppuVar25 != (undefined *****)0x0) {
            lVar28 = 5;
            goto LAB_006ccaa8;
          }
        }
        if (((ulong)apppppuStack_220[0] & 1) != 0) {
          func_0x00bc3350(apppppuStack_220[2]);
        }
        if ((uStack_250 & 1) != 0) {
          func_0x00bc3350(uStack_240);
        }
        *(undefined1 *)unaff_x25 = 1;
        *(uint *)((long)pppppuStack_3c0 + 0x224) = *(uint *)((long)pppppuStack_3c0 + 0x224) + 1;
        (*(code *)(*pppppuStack_3c0)[7])();
        goto LAB_006c7a20;
      }
      iVar13 = func_0x007ac230(0);
      if (((iVar13 == 3000) && (iVar13 = func_0x007ac380(), iVar13 == 2)) &&
         (iVar13 = func_0x009cd640(0xfffffffe,0,2,0,0), iVar13 == 0)) {
        uVar12 = *(uint *)((long)pppppuStack_500 + 4);
        func_0x0040cb78(abStack_2e8,&UNK_002a79af);
        iVar13 = func_0x008e3f14(pppppuStack_3c0 + 0x28f,abStack_2e8,0x1e);
        uVar15 = *(uint *)((long)pppppuStack_3c0 + 0x224);
        if ((abStack_2e8[0] & 1) != 0) {
          func_0x00bc3350(uStack_2d8);
        }
        if (iVar13 <= (int)uVar12 && uVar15 == 0) {
          func_0x0040cb78(&uStack_250,&UNK_002a2633);
          func_0x0045e320(apppppuStack_220,&uStack_250);
          ppppuStack_1c0 = (undefined ****)&UNK_00be20a8;
          pppppuStack_1a0 = &ppppuStack_1c0;
          pppppuStack_1b8 = pppppuStack_3c0;
          uVar49 = func_0x00868168(pppppuStack_3c0 + 0x5bd,apppppuStack_220,0,0,4,&ppppuStack_1c0);
          pppppuVar31 = &ppppuStack_1f0;
          ppppuStack_1f0 = (undefined ****)&UNK_00be2128;
          pppppuStack_1e8 = pppppuStack_3c0;
          lStack_1e0 = lStack_408;
          pppppuStack_1d0 = pppppuVar31;
          func_0x00866ca4(uVar49,&ppppuStack_1f0);
          if (pppppuStack_1d0 == pppppuVar31) {
            lVar28 = 4;
            pppppuVar25 = &ppppuStack_1f0;
LAB_006cc944:
            (*(code *)(*pppppuVar25)[lVar28])();
          }
          else if (pppppuStack_1d0 != (undefined *****)0x0) {
            lVar28 = 5;
            pppppuVar25 = pppppuStack_1d0;
            goto LAB_006cc944;
          }
          pppppuVar25 = pppppuStack_1a0;
          if (pppppuStack_1a0 != &ppppuStack_1c0) goto LAB_006ccaa0;
          lVar28 = 4;
          pppppuVar25 = &ppppuStack_1c0;
          goto LAB_006ccaa8;
        }
      }
      pppppuVar31 = pppppuStack_3c0;
      if (*(uint *)unaff_x23 == 0) {
        unaff_x26 = (undefined *****)0x0;
        unaff_x23 = (undefined *****)0x0;
        do {
          iVar13 = func_0x005ab37c(0,unaff_x23);
          uVar12 = (uint)unaff_x26;
          if (iVar13 != -1) {
            uVar12 = uVar12 + 1;
          }
          unaff_x26 = (undefined *****)(ulong)uVar12;
          if ((5 < uVar12) &&
             ((((uVar24 = func_0x00805fcc(pppppuVar31), (uVar24 & 1) != 0 ||
                (uVar24 = func_0x00807838(pppppuVar31), (uVar24 & 1) != 0)) ||
               (uVar24 = func_0x00807844(pppppuVar31), (uVar24 & 1) != 0)) ||
              (uVar12 = *(uint *)((long)param_1 + 0x32b4dc),
              *(uint *)((long)param_1 + 0x32b4dc) = uVar12 + 1, 0x16 < (int)uVar12)))) {
            pppppuVar25 = (undefined *****)(*(code *)(*pppppuVar31)[7])(pppppuVar31);
            ((uint *)((long)param_1 + 0x32b4e4))[0] = 0;
            ((uint *)((long)param_1 + 0x32b4e4))[1] = 0;
            *(undefined1 *)unaff_x25 = 1;
            *(uint *)pppppuStack_3c8 = 1;
            ((uint *)((long)param_1 + 0x32b4dc))[0] = 0;
            ((uint *)((long)param_1 + 0x32b4dc))[1] = 0;
            uVar12 = *(uint *)pppppuStack_4b0;
            goto joined_r0x006cc348;
          }
          uVar12 = (int)unaff_x23 + 1;
          unaff_x23 = (undefined *****)(ulong)uVar12;
        } while (uVar12 != 10);
      }
      if (*(uint *)((long)pppppuStack_3c8 + 0x54) == 0) {
        unaff_x26 = (undefined *****)0x0;
        unaff_x23 = (undefined *****)0x0;
        do {
          iVar13 = func_0x005ab37c(0,unaff_x23);
          uVar12 = (uint)unaff_x26;
          if (iVar13 != -1) {
            uVar12 = uVar12 + 1;
          }
          unaff_x26 = (undefined *****)(ulong)uVar12;
          if ((5 < uVar12) &&
             (((uVar24 = func_0x00805fcc(pppppuVar31), (uVar24 & 1) != 0 ||
               (uVar24 = func_0x00807838(pppppuVar31), (uVar24 & 1) != 0)) ||
              ((uVar24 = func_0x00807844(pppppuVar31), (uVar24 & 1) != 0 ||
               (uVar12 = *(uint *)((long)param_1 + 0x32b4dc),
               *(uint *)((long)param_1 + 0x32b4dc) = uVar12 + 1, 0x16 < (int)uVar12)))))) {
            (*(code *)(*pppppuVar31)[7])(pppppuVar31);
            pppppuVar31 = (undefined *****)0x1;
            ((uint *)((long)param_1 + 0x32b4e4))[0] = 0;
            ((uint *)((long)param_1 + 0x32b4e4))[1] = 0;
            *(undefined1 *)unaff_x25 = 1;
            *(uint *)((long)pppppuStack_3c8 + 0x54) = 1;
            ((uint *)((long)param_1 + 0x32b4dc))[0] = 0;
            ((uint *)((long)param_1 + 0x32b4dc))[1] = 0;
            if (*(uint *)pppppuStack_4b0 == 0) {
              uVar49 = func_0x0044c16c();
              func_0x0044e744(uVar49,0x32);
            }
            pppppuVar25 = (undefined *****)0x0;
            *(undefined1 *)((long)param_1 + 0x13dd) = 1;
            goto LAB_006c7a24;
          }
          uVar12 = (int)unaff_x23 + 1;
          unaff_x23 = (undefined *****)(ulong)uVar12;
        } while (uVar12 != 10);
      }
    }
LAB_006cc3c8:
    if (((*(uint *)unaff_x27 != 0x30) && (*(uint *)(pppppuStack_488 + 0x2b) != 3)) &&
       ((((*(uint *)(pppppuStack_488 + 0x2b) != 99 &&
          (((*(char *)(param_1 + 0x658cb) == '\0' && (*(char *)((long)param_1 + 0x32c666) == '\0'))
           && (*(char *)((long)param_1 + 0x32c667) == '\0')))) &&
         (((iVar13 = func_0x007abd78(0), iVar13 != -7 ||
           (iVar13 = func_0x007ac380(), iVar13 != 0x2f)) &&
          (*(uint *)((long)pppppuStack_3c8 + 4) == 0)))) &&
        (0 < (int)*(uint *)((long)pppppuStack_3d0 + 0x1c))))) {
      uVar24 = func_0x00805fcc(pppppuStack_3c0);
      if ((((uVar24 & 1) == 0) && (uVar24 = func_0x00807838(pppppuStack_3c0), (uVar24 & 1) == 0)) &&
         (uVar24 = func_0x00807844(pppppuStack_3c0), (uVar24 & 1) == 0)) {
        pppppuVar31 = (undefined *****)((long)param_1 + 0x32b4dc);
        uVar12 = *(uint *)pppppuVar31;
        *(uint *)pppppuVar31 = uVar12 + 1;
        if ((int)uVar12 < 0x17) goto LAB_006cc42c;
        pppppuVar25 = (undefined *****)(*(code *)(*pppppuStack_3c0)[7])();
        *pppppuVar31 = (undefined ****)0x0;
        ((uint *)((long)param_1 + 0x32b4e4))[0] = 0;
        ((uint *)((long)param_1 + 0x32b4e4))[1] = 0;
        *(undefined1 *)unaff_x25 = 1;
        *(uint *)((long)pppppuStack_3c8 + 4) = 1;
        uVar12 = *(uint *)pppppuStack_4b0;
      }
      else {
        pppppuVar31 = pppppuStack_3c0;
        pppppuVar25 = (undefined *****)(*(code *)(*pppppuStack_3c0)[7])(pppppuStack_3c0);
        *(undefined1 *)unaff_x25 = 1;
        *(uint *)((long)pppppuStack_3c8 + 4) = 1;
        uVar12 = *(uint *)pppppuStack_4b0;
        ((uint *)((long)pppppuVar31 + 0x32b4e4))[0] = 0;
        ((uint *)((long)pppppuVar31 + 0x32b4e4))[1] = 0;
        ((uint *)((long)pppppuVar31 + 0x32b4dc))[0] = 0;
        ((uint *)((long)pppppuVar31 + 0x32b4dc))[1] = 0;
      }
joined_r0x006cc348:
      if (uVar12 == 0) {
LAB_006cc530:
        uVar49 = func_0x0044c16c(pppppuVar25);
        func_0x0044e744(uVar49,0x32);
      }
      goto LAB_006c7a20;
    }
LAB_006cc42c:
    pppppuVar31 = pppppuStack_3c0;
    uVar12 = *(uint *)(param_1 + 0x656e1);
    if ((int)uVar12 < 1) {
      unaff_x23 = (undefined *****)((long)pppppuStack_3c0 + 0x328214);
      uVar12 = *(uint *)(pppppuStack_3c0 + 0x6506e);
      if ((int)uVar12 < 1) {
        uVar12 = *(uint *)(pppppuStack_488 + 0x1c);
        if ((int)uVar12 < 1) {
          uVar12 = *(uint *)((long)pppppuStack_488 + 0xec);
          if ((int)uVar12 < 1) {
            uVar12 = *(uint *)((long)pppppuStack_488 + 0xf4);
            if ((int)uVar12 < 1) {
              if ((((((int)*(uint *)(pppppuStack_3c0 + 0x65077) < 1) &&
                    ((int)*(uint *)((long)pppppuStack_3c0 + 0x3283bc) < 1)) &&
                   (((int)*(uint *)(pppppuStack_3c0 + 0x65078) < 1 &&
                    (((((int)*(uint *)((long)pppppuStack_3c0 + 0x3283c4) < 1 &&
                       ((int)*(uint *)(pppppuStack_3c0 + 0x65079) < 1)) &&
                      ((int)*(uint *)((long)pppppuStack_3c0 + 0x3283cc) < 1)) &&
                     (((int)*(uint *)(pppppuStack_3c0 + 0x6507a) < 1 &&
                      ((int)*(uint *)((long)pppppuStack_3c0 + 0x3283d4) < 1)))))))) &&
                  ((int)*(uint *)(pppppuStack_3c0 + 0x6507b) < 1)) &&
                 ((int)*(uint *)((long)pppppuStack_3c0 + 0x3283dc) < 1)) goto LAB_006ccce4;
              uVar24 = 0;
              uVar12 = 5;
              if (*(char *)((long)param_1 + 0x13dd) != '\0') {
                uVar12 = 10;
              }
              uVar33 = (ulong)uVar12;
              do {
                if (0 < (int)*(uint *)((long)pppppuStack_3c0 + (uVar24 + 0xca0ee) * 4)) {
                  uVar33 = uVar24 & 0xffffffff;
                  uVar29 = uVar24;
                  break;
                }
                uVar24 = uVar24 + 1;
                uVar29 = uVar33;
              } while (uVar33 != uVar24);
              uVar12 = *(uint *)((long)pppppuStack_3c0 + (uVar33 + 0xca0ee) * 4) + 1;
              *(uint *)((long)pppppuStack_3c0 + (uVar33 + 0xca0ee) * 4) = uVar12;
              if (5 < uVar12) {
                *(uint *)((long)pppppuStack_3c0 + (uVar33 + 0xca0ee) * 4) = 0;
                func_0x009aa848(pppppuStack_3c0 + 0x6770a);
                pppppuVar31 = pppppuStack_3c0;
                if ((*(uint *)pppppuStack_4f8 == 0) || (*(char *)((long)param_1 + 0x13dd) != '\0'))
                {
                  uVar29 = uVar29 & 0xffffffff;
                }
                else {
                  if (*(uint *)pppppuStack_4f8 != 1) goto LAB_006c7ae4;
                  uVar29 = (ulong)((int)uVar29 + 5);
                }
                Battle_Sub8B99A0(pppppuStack_3c0,0,uVar29,1);
              }
            }
            else {
              *(uint *)((long)pppppuStack_488 + 0xf4) = uVar12 + 1;
              if (4 < uVar12) {
                *(uint *)((long)pppppuStack_488 + 0xf4) = 0;
                uVar12 = func_0x005af784(5);
                func_0x005af72c(5,(uVar12 ^ 0xffffffff) & 1);
              }
            }
          }
          else {
            *(uint *)((long)pppppuStack_488 + 0xec) = uVar12 + 1;
            if (4 < uVar12) {
              *(uint *)((long)pppppuStack_488 + 0xec) = 0;
              uVar12 = func_0x005af784(3);
              func_0x005af72c(3,(uVar12 ^ 0xffffffff) & 1);
            }
          }
        }
        else {
          *(uint *)(pppppuStack_488 + 0x1c) = uVar12 + 1;
          if (4 < uVar12) {
            *(uint *)(pppppuStack_488 + 0x1c) = 0;
            uVar24 = func_0x005af658();
            if ((((uVar24 & 1) == 0) || (uVar24 = func_0x005af784(0), (uVar24 & 1) == 0)) ||
               (*(char *)((long)pppppuStack_488 + 0x14b) != '\0')) {
              uVar12 = func_0x005af784(0);
              func_0x005af72c(0,(uVar12 ^ 0xffffffff) & 1);
              *(undefined1 *)((long)pppppuStack_488 + 0x14b) = 0;
            }
            else {
              *(undefined1 *)((long)pppppuStack_488 + 0x14b) = 1;
            }
            pppppuVar31 = pppppuStack_3c0;
            if ((*(uint *)pppppuStack_3d0 == 0) && (*(uint *)((long)pppppuStack_3c0 + 0x224) == 3))
            {
              *(uint *)((long)pppppuStack_3c0 + 0x224) = 4;
            }
          }
        }
      }
      else {
        *(uint *)(pppppuStack_3c0 + 0x6506e) = uVar12 + 1;
        if (4 < uVar12) {
          *(uint *)(pppppuStack_3c0 + 0x6506e) = 0;
          (*(code *)(*pppppuStack_3c0)[7])(pppppuStack_3c0);
          *(undefined1 *)((long)param_1 + 0x326634) = 1;
          func_0x008003f4(pppppuVar31,1);
          func_0x008de0f0(pppppuVar31 + 0x8d337);
          pppppuVar25 = (undefined *****)0x0;
          if (*(uint *)pppppuStack_4b0 == 0) goto LAB_006cc530;
          goto LAB_006c7a24;
        }
      }
LAB_006c7ae4:
      do {
        do {
          uVar24 = func_0x005af784(0);
          if ((uVar24 & 1) == 0) {
            uVar12 = 1;
LAB_006c7b48:
            *(uint *)(pppppuStack_4f8 + 0x1bc) = uVar12;
          }
          else {
            if (*(char *)((long)pppppuStack_488 + 0x14b) == '\0') {
              uVar12 = 2;
              goto LAB_006c7b48;
            }
            func_0x0040cb78(abStack_318,&UNK_00290f39);
            uVar12 = func_0x008e3f14(pppppuVar31 + 0x28f,abStack_318,3);
            *(uint *)(pppppuStack_4f8 + 0x1bc) = uVar12;
            if ((abStack_318[0] & 1) != 0) {
              func_0x00bc3350(uStack_308);
            }
          }
          bVar11 = func_0x005af784(3);
          pppppuVar25 = pppppuStack_488;
          uVar12 = *(uint *)((long)pppppuVar42 + 0xcc);
          *(byte *)(unaff_x22 + 10) = bVar11 & 1;
          if (uVar12 == 1) {
            *(uint *)((long)pppppuStack_500 + 0x2a4) = *(uint *)(pppppuStack_500 + 0x54);
            pppppuVar35 = pppppuVar31 + 0x107a2;
            lVar28 = 0x32;
            do {
              if ((*(uint *)(pppppuVar35 + -4) != 0) && (*(uint *)pppppuVar35 != 0)) {
                *(uint *)pppppuVar35 = *(uint *)((long)pppppuVar35 + -4);
              }
              lVar28 = lVar28 + -1;
              pppppuVar35 = pppppuVar35 + 0x7d;
            } while (lVar28 != 0);
            *(uint *)((long)pppppuVar42 + 0xcc) = 0;
          }
          if (*(uint *)(pppppuVar42 + 0x1b) == 1) {
            pppppuVar45 = (undefined *****)0x2648;
            *(uint *)(pppppuStack_488 + 0x2a) = *(uint *)(pppppuStack_488 + 0x2a) + 1;
            func_0x005b2234(pppppuVar31 + 0x4c9,0,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,1,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,2,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,3,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,4,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,5,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,6,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,7,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,8,0,1);
            func_0x005b2234(pppppuVar31 + 0x4c9,9,0,1);
            unaff_x25 = pppppuVar25;
            if (0x707 < (int)*(uint *)(pppppuVar25 + 0x2a)) {
              *(uint *)(pppppuVar42 + 0x1b) = 0;
              *(uint *)(pppppuStack_488 + 0x2a) = 0;
            }
          }
          iVar13 = func_0x005ab154();
          if (iVar13 != 0) {
            *(undefined1 *)(unaff_x22 + 10) = 0;
            *(uint *)(pppppuStack_4f8 + 0x1bc) = 1;
            *(uint *)(pppppuVar42 + 0x1b) = 0;
            *(uint *)(pppppuStack_488 + 0x2a) = 0;
          }
          func_0x005bf8e8(pppppuVar31,*(uint *)(pppppuStack_4f8 + 3));
          uVar12 = *(uint *)((long)pppppuVar31 + 0x341c);
          uVar15 = *(uint *)(pppppuStack_500 + 0xe) * 100;
          if ((int)uVar12 < (int)uVar15) {
            *(uint *)((long)pppppuVar31 + 0x341c) = uVar15;
            unaff_x22 = pppppuStack_4b0;
          }
          else {
            iVar13 = func_0x005ba6d4(pppppuVar31);
            unaff_x22 = pppppuStack_4b0;
            if (iVar13 < (int)uVar12) {
              uVar15 = func_0x005ba6d4(pppppuVar31);
              *(uint *)((long)pppppuVar31 + 0x341c) = uVar15;
            }
            else {
              uVar15 = *(uint *)((long)pppppuVar31 + 0x341c);
            }
          }
          *(int *)((long)pppppuStack_488 + 4) = (int)uVar15 / 100;
          fVar50 = (float)(int)*(uint *)pppppuVar40 +
                   -9600.0 / (((float)(int)uVar15 / 100.0) / 100.0);
          if ((float)(int)*(uint *)((long)pppppuStack_500 + 0x14) <= fVar50) {
            if ((int)*(uint *)((long)pppppuStack_500 + 0x14) < 0) {
              uVar12 = 0;
              goto LAB_006c7db0;
            }
          }
          else {
            uVar12 = (uint)fVar50;
LAB_006c7db0:
            *(uint *)((long)pppppuStack_500 + 0x14) = uVar12;
            *(uint *)pppppuStack_508 = 0;
            iVar13 = func_0x005ab154();
            if (iVar13 == 0) {
              func_0x005ab128();
            }
          }
          pppppuStack_538 = pppppuVar31 + 0x67129;
          if (*(uint *)(pppppuVar31 + 0x1079e) == 0) {
            uVar12 = 0;
          }
          else {
            pppppuVar42 = pppppuVar31 + 0x1081b;
            uVar24 = 1;
            do {
              uVar33 = uVar24;
              if (uVar33 == 0x32) break;
              uVar12 = *(uint *)pppppuVar42;
              pppppuVar42 = pppppuVar42 + 0x7d;
              uVar24 = uVar33 + 1;
            } while (uVar12 != 0);
            uVar12 = (uint)(0x31 < uVar33);
          }
          uVar15 = func_0x009aafb8(pppppuStack_3c0 + 0x6770a);
          pppppuVar32 = (undefined *****)(ulong)(uVar12 | uVar15);
          unaff_x23 = (undefined *****)func_0x007fd748();
          uVar19 = func_0x007ac230(0);
          pppppuVar25 = (undefined *****)func_0x00633678(unaff_x23 + 0xcd,uVar19,7);
          pppppuVar35 = pppppuStack_3c0;
          if (pppppuVar25 == (undefined *****)0x0) {
            if (uVar12 == 0 && (uVar15 & 1) == 0) goto LAB_006c7e8c;
LAB_006c7e70:
            ((uint *)((long)unaff_x22 + 0x314))[0] = 0;
            ((uint *)((long)unaff_x22 + 0x314))[1] = 1;
LAB_006c7ebc:
            uVar12 = *(uint *)(pppppuStack_3c0 + 0x39c);
            if (-1 < (int)uVar12) {
              uVar15 = 0xffffffff;
              if (uVar12 < 0x32) {
                uVar15 = uVar12 + 1;
              }
              *(uint *)(pppppuStack_3c0 + 0x39c) = uVar15;
            }
            pppppuVar40 = pppppuStack_3c0 + 0x704b3;
            pppppuStack_4c8 = pppppuStack_3c0 + 0x67123;
            pppppuVar42 = (undefined *****)((long)pppppuStack_3c0 + 0x28bcac);
            pppppuStack_470 = pppppuStack_3c0 + 0x13cac;
            pppppuStack_3d0 = pppppuStack_3c0 + 0x13c31;
            unaff_x22 = (undefined *****)((long)pppppuStack_3c0 + 0x9004c);
            pppppuStack_448 = pppppuStack_3c0 + 0x139fc;
            pppppuStack_468 = pppppuStack_3c0 + 0x1071b;
            pppppuStack_478 = pppppuStack_3c0 + 0x10721;
            func_0x005c5d04(pppppuStack_3c0);
            if (*(uint *)(pppppuVar35 + 599) == 0xffffffff) {
              func_0x005c51bc(pppppuVar35);
            }
            lVar28 = 0;
            bVar10 = true;
            do {
              bVar7 = bVar10;
              puVar27 = (uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c1) * 4);
              if ((*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9ad) * 4) == 1) &&
                 (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9b7) * 4) == 0)) {
                *puVar27 = *puVar27 + 1;
              }
              if ((*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4d7) == 1) &&
                 (*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4dc) == 0)) {
                *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e1) =
                     *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e1) + 1;
              }
              if ((*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9af) * 4) == 1) &&
                 (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9b9) * 4) == 0)) {
                *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c3) * 4) =
                     *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c3) * 4) + 1;
              }
              if ((*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4d8) == 1) &&
                 (*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4dd) == 0)) {
                *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e2) =
                     *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e2) + 1;
              }
              if ((*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9b1) * 4) == 1) &&
                 (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9bb) * 4) == 0)) {
                *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c5) * 4) =
                     *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c5) * 4) + 1;
              }
              if ((*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4d9) == 1) &&
                 (*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4de) == 0)) {
                *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e3) =
                     *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e3) + 1;
              }
              if ((*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9b3) * 4) == 1) &&
                 (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9bd) * 4) == 0)) {
                *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c7) * 4) =
                     *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c7) * 4) + 1;
              }
              if ((*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4da) == 1) &&
                 (*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4df) == 0)) {
                *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e4) =
                     *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e4) + 1;
              }
              if ((*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9b5) * 4) == 1) &&
                 (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9bf) * 4) == 0)) {
                *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c9) * 4) =
                     *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + 0x9c9) * 4) + 1;
              }
              if ((*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4db) == 1) &&
                 (*(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e0) == 0)) {
                *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e5) =
                     *(uint *)(pppppuVar35 + lVar28 * 0x3e + 0x4e5) + 1;
              }
              lVar28 = 1;
              bVar10 = false;
            } while (bVar7);
            pppppuStack_498 = unaff_x22;
            pppppuStack_480 = pppppuVar40;
            pppppuStack_3e0 = pppppuVar42;
            uVar24 = func_0x009d0178(pppppuVar35[0xf8]);
            if ((uVar24 & 1) != 0) {
              func_0x00634980(pppppuVar35 + 0xcd);
            }
            if (0 < (int)*(uint *)(pppppuStack_4f8 + 0x1bc)) {
              pppppuStack_4b8 = pppppuVar35 + 0x4ea;
              iVar13 = 0;
              pppppuStack_518 = (undefined *****)(apppppuStack_220 + 1);
              pppppuStack_520 = (undefined *****)(apppppuStack_220 + 4);
              pppppuStack_3f0 = (undefined *****)(lStack_408 + 0x2478);
              pppppuStack_400 = pppppuStack_468 + 4;
              pppppuStack_440 = pppppuStack_480 + 1;
              puStack_3f8 = (undefined8 *)((ulong)abStack_3b0 | 1);
              puStack_4d8 = (uint *)((long)pppppuStack_3e0 + 0x194);
              pppppuStack_4f0 = pppppuStack_3e0 + 1;
              pppppuStack_490 = pppppuStack_468 + 0xd;
              pppppuStack_530 = pppppuStack_498 + 0x7d;
              pppppuStack_450 = pppppuStack_448 + 0x1cc;
              pppppuStack_4e0 = pppppuStack_448 + 400;
              puStack_528 = (uint *)((long)pppppuStack_4a8 + 0x4f4);
              ppppuStack_548 = (undefined ****)0xffffffff00000000;
              ppppuStack_550 = (undefined ****)0x0;
              pppppuStack_4c0 = pppppuVar35 + 0x13caf;
              uStack_458 = 0x1b;
              uStack_460 = 0x21;
              do {
                iStack_4e4 = iVar13;
                iVar13 = func_0x005ab154();
                if ((iVar13 == 0) &&
                   (uVar24 = func_0x009d0178(pppppuVar35[0xf8]), (uVar24 & 1) != 0)) {
                  uVar19 = func_0x009d095c(pppppuVar35[0xf8]);
                  func_0x006347c4(pppppuVar35 + 0xcd,uVar19);
                }
                uVar24 = (long)pppppuVar35[0x4e8] - (long)pppppuVar35[0x4e7];
                if ((uVar24 != 0) && (0 < (int)(uVar24 >> 3))) {
                  uVar24 = uVar24 >> 3 & 0xffffffff;
                  puVar47 = (uint *)(uVar24 + 1);
                  pppppuVar42 = (undefined *****)(uVar24 * -8);
                  lVar28 = uVar24 * 8;
                  do {
                    lVar30 = lVar28 + -8;
                    ppppuVar37 = pppppuVar35[0x4e7];
                    iVar13 = *(int *)((long)ppppuVar37 + lVar28 + -4);
                    if (iVar13 < 1) {
                      iVar13 = *(int *)((long)ppppuVar37 + lVar30);
                      lVar28 = (long)iVar13;
                      iVar14 = func_0x005abf04(0,iVar13);
                      uVar19 = func_0x00a92ff4((uint *)((long)pppppuVar35 +
                                                       ((long)iVar14 * 2 + 0x11eab) * 4));
                      unaff_x25 = pppppuStack_4b8;
                      pppppuStack_3c8 = (undefined *****)(lVar28 * 4);
                      pppppuStack_3d8 = (undefined *****)CONCAT44(pppppuStack_3d8._4_4_,uVar19);
                      *(uint *)((long)pppppuStack_4b8 + lVar28 * 4) =
                           *(uint *)((long)pppppuStack_4b8 + lVar28 * 4) - 1;
                      uVar19 = func_0x005ab37c(0,iVar13);
                      pppppuStack_3e8 = (undefined *****)CONCAT44(pppppuStack_3e8._4_4_,uVar19);
                      iVar14 = func_0x005ab37c(0,iVar13);
                      iVar20 = func_0x005abf1c(0,iVar13);
                      pppppuVar45 = pppppuStack_4c0;
                      unaff_x26 = (undefined *****)
                                  (ulong)*(uint *)(pppppuStack_4c0 +
                                                  (long)iVar20 * 0x3b + (long)iVar14 * 0xec + 7);
                      iVar14 = func_0x005ab37c(0,iVar13);
                      iVar20 = func_0x005abf1c(0,iVar13);
                      unaff_x27 = (undefined *****)
                                  (ulong)*(uint *)((long)pppppuVar45 +
                                                  ((long)iVar14 * 0x1d8 + (long)iVar20 * 0x76 + 0xf)
                                                  * 4);
                      uVar19 = func_0x005abf1c(0,iVar13);
                      Battle_SpawnOrInitUnit
                                (pppppuVar35,0,(ulong)pppppuStack_3e8 & 0xffffffff,
                                 (ulong)pppppuStack_3d8 & 0xffffffff,unaff_x26,unaff_x27,uVar19,0);
                      *(int *)((long)unaff_x25 + (long)pppppuStack_3c8) =
                           *(int *)((long)unaff_x25 + (long)pppppuStack_3c8) + 1;
                      lVar28 = (long)pppppuVar35[0x4e7] + lVar30;
                      pppppuVar45 = (undefined *****)
                                    ((long)pppppuVar42 +
                                    ((long)pppppuVar35[0x4e8] - (long)pppppuVar35[0x4e7]));
                      if ((undefined ****)(lVar28 + 8) != pppppuVar35[0x4e8]) {
                        func_0x00bc33e0(lVar28,(undefined ****)(lVar28 + 8),pppppuVar45);
                      }
                      pppppuVar35[0x4e8] = (undefined ****)(lVar28 + (long)pppppuVar45);
                    }
                    else {
                      *(int *)((long)ppppuVar37 + lVar28 + -4) = iVar13 + -1;
                    }
                    puVar47 = (uint *)((long)puVar47 + -1);
                    pppppuVar42 = pppppuVar42 + 1;
                    lVar28 = lVar30;
                  } while ((uint *)0x1 < puVar47);
                }
                iVar13 = 0;
                do {
                  func_0x00a625c4(0,iVar13,0);
                  func_0x00a60660(0,iVar13,0);
                  func_0x00a61848(0,iVar13,0);
                  iVar13 = iVar13 + 1;
                } while (iVar13 != 0x33);
                iVar13 = 0;
                do {
                  func_0x00a625c4(1,iVar13,0);
                  func_0x00a60660(1,iVar13,0);
                  func_0x00a61848(1,iVar13,0);
                  iVar13 = iVar13 + 1;
                } while (iVar13 != 0x33);
                iVar13 = func_0x005ab154();
                unaff_x23 = (undefined *****)0x33;
                if (((iVar13 == 0) && (uVar24 = func_0x005d0ad4(pppppuVar35), (uVar24 & 1) != 0)) &&
                   (*(uint *)(pppppuVar35 + 0x65a) != 0x7fffffff)) {
                  uVar12 = *(uint *)(pppppuVar35 + 0x65a) + 1;
                  *(uint *)(pppppuStack_3c0 + 0x65a) = uVar12;
                  iVar13 = func_0x005aaca0();
                  pppppuVar35 = pppppuStack_3c0;
                  if ((iVar13 <= (int)uVar12) && (iVar13 = func_0x005ab154(), iVar13 != 4)) {
                    uVar49 = func_0x0044c16c();
                    func_0x0044e014(uVar49,0xffffffff);
                    uVar49 = func_0x0044c16c();
                    uVar24 = func_0x00999ab8(pppppuVar35 + 0x80);
                    uVar19 = 0xbd;
                    if ((uVar24 & 1) == 0) {
                      uVar19 = 0x39;
                    }
                    func_0x0044e35c(uVar49,uVar19,0);
                    func_0x006ee0d0(pppppuVar35 + 0x1c);
                    pppppuVar42 = pppppuStack_500;
                    unaff_x25 = (undefined *****)&UNK_00383744;
                    uVar12 = *(uint *)((long)pppppuVar35 + 0x383744);
                    *(uint *)(pppppuStack_500 + 0xc) = 0;
                    uVar49 = func_0x007a95b8(uVar12);
                    pppppuVar45 = pppppuStack_538;
                    iVar13 = func_0x009cd640(uVar49,*(uint *)pppppuStack_538,*(uint *)pppppuVar42,
                                             *(uint *)((long)pppppuVar35 + 0x38ff5c),0);
                    func_0x00a0b124(0x1e,iVar13 < 1,0,0,0);
                    uVar49 = func_0x007a95b8(*(uint *)((long)pppppuVar35 + 0x383744));
                    func_0x009ce358(uVar49,*(uint *)pppppuVar45,*(uint *)pppppuVar42,
                                    *(uint *)((long)pppppuVar35 + 0x38ff5c),1,0);
                    uVar49 = func_0x007a95b8(*(uint *)((long)pppppuVar35 + 0x383744));
                    iVar13 = func_0x009cd640(uVar49,*(uint *)pppppuVar45,*(uint *)pppppuVar42,
                                             *(uint *)((long)pppppuVar35 + 0x38ff5c),0);
                    if (9999 < iVar13) {
                      uVar49 = func_0x007a95b8(*(uint *)((long)pppppuVar35 + 0x383744));
                      func_0x009cdc30(uVar49,*(uint *)pppppuStack_538,*(uint *)pppppuVar42,
                                      *(uint *)((long)pppppuVar35 + 0x38ff5c),9999,0);
                    }
                    func_0x005cf794(pppppuVar35);
                    func_0x005ab174(4);
                    uVar12 = func_0x007ac230(0);
                    unaff_x23 = (undefined *****)(ulong)uVar12;
                    pppppuVar45 = (undefined *****)&UNK_0032c0b8;
                    func_0x007d78f4(pppppuVar35 + 0x65817,0,unaff_x23,1,0,0);
                    func_0x007d78f4(pppppuVar35 + 0x65817,1,*(uint *)pppppuVar42 + uVar12 * 100,1,0,
                                    0);
                    func_0x007d78f4(pppppuVar35 + 0x65817,9,(int)uVar12 / 1000,1,0,0);
                    func_0x007d78f4(pppppuVar35 + 0x65817,0x15,*(uint *)pppppuVar42 + uVar12 * 100,
                                    *(uint *)((long)pppppuVar35 + 0x32cc),0,0);
                    iVar13 = func_0x007abd78(0);
                    if (iVar13 == 4) {
                      iVar13 = func_0x0095baa8(pppppuVar35[0x42b],*(uint *)pppppuStack_538);
                      if (iVar13 < (int)*(uint *)((long)pppppuVar35 + 0x32cc)) {
LAB_006c8730:
                        *(uint *)((long)pppppuStack_500 + 0x5c) = 1;
                      }
                    }
                    else {
                      uVar49 = func_0x00590bb8(pppppuVar35 + 0x65b,pppppuStack_538);
                      piVar26 = (int *)func_0x005cf538(uVar49,pppppuVar42);
                      uVar12 = *(uint *)((long)pppppuVar35 + 0x32cc);
                      if (*piVar26 < (int)uVar12) {
                        uVar49 = func_0x00590bb8(pppppuVar35 + 0x65b,pppppuStack_538);
                        puVar27 = (uint *)func_0x005cf538(uVar49,pppppuStack_500);
                        *puVar27 = uVar12;
                        goto LAB_006c8730;
                      }
                    }
                    func_0x005d0b20(pppppuVar35);
                    func_0x00a50034(pppppuVar35);
                  }
                }
                else {
                  iVar13 = func_0x005ab154();
                  if ((iVar13 == 0) &&
                     (uVar24 = func_0x009d0178(pppppuVar35[0xf8]), (uVar24 & 1) != 0)) {
                    func_0x009d1f6c(pppppuVar35[0xf8]);
                    uVar24 = func_0x009d2228(pppppuVar35[0xf8]);
                    if (((uVar24 & 1) != 0) &&
                       ((uVar24 = func_0x009d1f90(pppppuVar35[0xf8]), (uVar24 & 1) != 0 &&
                        (iVar13 = func_0x005ab154(), iVar13 == 0)))) {
                      *(uint *)((long)pppppuStack_500 + 0x3c) = 0;
                      *(uint *)(pppppuStack_500 + 8) = 0;
                      pppppuStack_4b0[1] = ppppuStack_548;
                      *pppppuStack_4b0 = ppppuStack_550;
                      func_0x005c9224(pppppuVar35,0);
                      func_0x005d0b20(pppppuVar35);
                    }
                  }
                }
                *(float *)((long)pppppuStack_508 + 0x34) =
                     *(float *)((long)pppppuStack_508 + 0x34) + 6.0;
                iVar13 = func_0x005ab154();
                if (iVar13 != 3) {
                  *(uint *)((long)pppppuStack_500 + 4) = *(uint *)((long)pppppuStack_500 + 4) + 1;
                  iVar13 = func_0x005ab154();
                  if (iVar13 == 0) {
                    uVar12 = 30000;
                    if ((int)*(uint *)(pppppuStack_500 + 0xf) < 29999) {
                      uVar12 = *(uint *)(pppppuStack_500 + 0xf) + 1;
                    }
                    *(uint *)(pppppuStack_500 + 0xf) = uVar12;
                  }
                  func_0x006dfef0(pppppuVar35);
                  lVar28 = lStack_408;
                  func_0x005bd678(pppppuVar35,lStack_408);
                  Battle_Sub5DBC18(pppppuVar35,lVar28,0);
                  func_0x005bdba0(pppppuVar35);
                  unaff_x26 = (undefined *****)0x1;
                  func_0x006dd600(pppppuVar35,lVar28,1);
                  uVar12 = 0;
                  do {
                    uVar24 = func_0x00a59560(1,uVar12);
                    if (((uVar24 & 1) != 0) && (iVar13 = func_0x00a59a70(1,uVar12), iVar13 == 0))
                    break;
                    bVar10 = uVar12 < 0x32;
                    uVar12 = uVar12 + 1;
                    unaff_x26 = (undefined *****)(ulong)bVar10;
                  } while (uVar12 != 0x33);
                  lVar28 = -0x32;
                  pppppuVar40 = (undefined *****)0x83cf0;
                  do {
                    if ((*(int *)((long)pppppuStack_3c0 + (long)pppppuVar40) != 0) &&
                       (iVar13 = func_0x00a58ba4(0,(int)lVar28 + 0x33), iVar13 == 7)) {
                      unaff_x26 = (undefined *****)0x1;
                      break;
                    }
                    bVar10 = lVar28 != -1;
                    lVar28 = lVar28 + 1;
                    pppppuVar40 = pppppuVar40 + 0x7d;
                  } while (bVar10);
                  pppppuVar31 = pppppuStack_3c0;
                  uVar24 = 0;
                  uVar12 = 1;
                  do {
                    auVar60._8_8_ = uVar24;
                    auVar60._0_8_ = pppppuVar31;
                    auVar8._8_8_ = uVar24;
                    auVar8._0_8_ = pppppuVar31;
                    pppppuVar42 = (undefined *****)(ulong)uVar12;
                    pppppuVar25 = (undefined *****)0x1;
                    do {
                      iVar13 = func_0x00a58874(uVar24,pppppuVar25);
                      if (iVar13 != 0) {
                        iVar13 = func_0x00a58ba4(uVar24,pppppuVar25);
                        if ((iVar13 == 1) ||
                           (iVar13 = func_0x00a58ba4(uVar24,pppppuVar25), iVar13 == 0)) {
                          iVar13 = func_0x00a59d48(uVar24,pppppuVar25);
                          if (iVar13 < 1) {
                            iVar13 = func_0x00a59c68(uVar24,pppppuVar25);
                            if (iVar13 == 0) {
                              func_0x006dd300(pppppuVar31,uVar24,pppppuVar25);
                            }
                          }
                          else {
                            func_0x00a59dd4(uVar24,pppppuVar25,0xffffffff);
                            iVar13 = func_0x00a59d48(uVar24,pppppuVar25);
                            if (iVar13 == 0) {
                              func_0x00a58be4(uVar24,pppppuVar25,4);
                              func_0x00a590fc(uVar24,pppppuVar25,0);
                            }
                          }
                          iVar13 = func_0x00a58ba4(uVar24,pppppuVar25);
                          if ((iVar13 == 0) &&
                             (iVar13 = func_0x00a58d4c(uVar24,pppppuVar25), iVar13 == 0)) {
                            func_0x00a58be4(uVar24,pppppuVar25,1);
                          }
                        }
                        iVar13 = func_0x00a58ba4(uVar24,pppppuVar25);
                        pppppuVar45 = pppppuVar25;
                        if (iVar13 == 0) {
                          unaff_x25 = (undefined *****)0x0;
                          uVar33 = 0;
                          pppppuVar35 = (undefined *****)0x0;
                          uVar49 = 0x6c8a10;
                          goto SUB_006ce084;
                        }
                        iVar13 = func_0x00a58ba4(uVar24,pppppuVar25);
                        if (iVar13 == 0xc) {
                          uVar33 = 0;
                          pppppuVar35 = (undefined *****)0x0;
                          uVar49 = 0x6c89ec;
                          ppppuVar9 = (undefined ****)&ppppuStack_550;
                          auVar60 = auVar8;
                          goto SUB_006ce084;
                        }
                      }
                      uVar15 = (int)pppppuVar25 + 1;
                      pppppuVar25 = (undefined *****)(ulong)uVar15;
                    } while (uVar15 != 0x33);
                    uVar24 = 1;
                    bVar10 = uVar12 != 0;
                    uVar12 = 0;
                  } while (bVar10);
                  if (*(uint *)(pppppuStack_510 + 0x43) == 1) {
                    *(uint *)(pppppuStack_510 + 0x43) = 0;
                  }
                  uVar24 = 1;
                  pppppuStack_3c8 = (undefined *****)CONCAT44(pppppuStack_3c8._4_4_,(int)unaff_x26);
                  pppppuVar32 = pppppuVar31;
                  pppppuVar45 = pppppuVar25;
                  do {
                    pppppuVar31 = pppppuStack_3c0;
                    pppppuVar35 = pppppuVar45;
                    if (*(uint *)(pppppuStack_478 + uVar24 * 0x7d) != 0) {
                      if ((*(uint *)((long)pppppuStack_478 + (uVar24 * 0xfa + 1) * 4) == 1) &&
                         ((int)*(uint *)((long)pppppuStack_478 + (uVar24 * 0xfa + 0x3d) * 4) < 1)) {
                        func_0x009b95b4(pppppuStack_3c0,lStack_408,0,uVar24 & 0xffffffff);
                        uVar33 = Battle_AttackTrigger_95c5f4(0,uVar24 & 0xffffffff);
                        if ((uVar33 & 1) == 0) {
                          pppppuVar31 = (undefined *****)0x0;
                          auVar60._8_8_ = 0;
                          auVar60._0_8_ = pppppuStack_3c0;
                          pppppuVar25 = (undefined *****)(uVar24 & 0xffffffff);
                          uVar33 = 0;
                          pppppuVar35 = (undefined *****)0x0;
                          uVar49 = 0x6c8ca0;
                          ppppuVar9 = (undefined ****)&ppppuStack_550;
                          pppppuVar45 = (undefined *****)0x0;
                        }
                        else {
                          func_0x00a5ac18(0,uVar24 & 0xffffffff,0);
                          auVar60._8_8_ = 0;
                          auVar60._0_8_ = pppppuVar31;
                          pppppuVar25 = (undefined *****)(uVar24 & 0xffffffff);
                          uVar33 = 0;
                          pppppuVar35 = (undefined *****)0x0;
                          uVar49 = 0x6c8c50;
                          ppppuVar9 = (undefined ****)&ppppuStack_550;
                        }
                        goto SUB_006ce084;
                      }
                      iVar13 = func_0x00a58ba4(0,uVar24 & 0xffffffff);
                      pppppuVar31 = pppppuStack_3c0;
                      pppppuVar32 = pppppuVar31;
                      if ((iVar13 == 2) &&
                         (iVar13 = func_0x00a608a8(0,uVar24 & 0xffffffff), iVar13 < 1)) {
                        func_0x009b95b4(pppppuVar31,lStack_408,0,uVar24 & 0xffffffff);
                        uVar49 = func_0x00a590bc(0,uVar24 & 0xffffffff);
                        if ((int)uVar49 == 0) {
                          iVar13 = func_0x00a59c68(uVar49,uVar24 & 0xffffffff);
                          if (iVar13 == 0) {
                            func_0x006dd300(pppppuVar31,0,uVar24 & 0xffffffff);
                          }
                          else {
                            func_0x00a58be4(0,uVar24 & 0xffffffff,1);
                          }
                        }
                        else {
                          iVar13 = Battle_CheckUnitCanMove(0,uVar24 & 0xffffffff);
                          if (0 < iVar13) {
                            pppppuVar40 = (undefined *****)0x1;
                            do {
                              iVar13 = (int)pppppuVar40;
                              pppppuVar35 = (undefined *****)(ulong)(iVar13 - 1);
                              uVar12 = func_0x00a590bc(0,uVar24 & 0xffffffff);
                              unaff_x25 = (undefined *****)(ulong)uVar12;
                              uVar15 = func_0x00a5a540(0,uVar24 & 0xffffffff,pppppuVar35);
                              if (uVar12 == uVar15) {
                                iVar14 = Battle_CheckUnitCanMove(0,uVar24 & 0xffffffff);
                                if (iVar14 == iVar13) {
                                  uVar19 = Battle_Get_83938(0,uVar24 & 0xffffffff);
                                  func_0x00a59830(0,uVar24 & 0xffffffff,uVar19);
                                  iVar13 = func_0x00a59c68(0,uVar24 & 0xffffffff);
                                  if (0 < iVar13) {
                                    Battle_Add_83ad4(0,uVar24 & 0xffffffff,0xffffffff);
                                  }
                                }
                                auVar60._8_8_ = 0;
                                auVar60._0_8_ = pppppuVar31;
                                pppppuVar25 = (undefined *****)(uVar24 & 0xffffffff);
                                uVar33 = 0;
                                *(uint *)((long)pppppuStack_3e0 + 0x19c) = 0;
                                uVar49 = 0x6c8d58;
                                ppppuVar9 = (undefined ****)&ppppuStack_550;
                                pppppuVar45 = pppppuVar35;
                                goto SUB_006ce084;
                              }
                              iVar14 = Battle_CheckUnitCanMove(0,uVar24 & 0xffffffff);
                              pppppuVar40 = (undefined *****)(ulong)(iVar13 + 1);
                            } while (iVar13 < iVar14);
                          }
                        }
                      }
                    }
                    pppppuVar31 = pppppuVar32;
                    uVar24 = uVar24 + 1;
                    pppppuVar32 = pppppuVar31;
                    pppppuVar45 = pppppuVar35;
                  } while (uVar24 != 0x33);
                  uVar24 = 1;
                  do {
                    if (*(uint *)(pppppuVar31 + uVar24 * 0x7d + 0x12008) != 0) {
                      uVar49 = func_0x00a58ba4(1,uVar24 & 0xffffffff);
                      if (((int)uVar49 == 1) &&
                         (iVar13 = func_0x00a608a8(uVar49,uVar24 & 0xffffffff), iVar13 < 1)) {
                        func_0x009b95b4(pppppuVar31,lStack_408,1,uVar24 & 0xffffffff);
                        auVar60._8_8_ = 1;
                        auVar60._0_8_ = pppppuVar31;
                        pppppuVar25 = (undefined *****)(uVar24 & 0xffffffff);
                        uVar33 = 0;
                        pppppuVar35 = (undefined *****)0x0;
                        uVar49 = 0x6c9958;
                        ppppuVar9 = (undefined ****)&ppppuStack_550;
                        goto SUB_006ce084;
                      }
                      iVar13 = func_0x00a58ba4(1,uVar24 & 0xffffffff);
                      if ((iVar13 == 2) &&
                         (iVar13 = func_0x00a608a8(1,uVar24 & 0xffffffff), iVar13 < 1)) {
                        func_0x009b95b4(pppppuVar31,lStack_408,1,uVar24 & 0xffffffff);
                        iVar13 = func_0x00a590bc(1,uVar24 & 0xffffffff);
                        if (iVar13 == 0) {
                          iVar13 = func_0x00a59c68(1,uVar24 & 0xffffffff);
                          if (iVar13 == 0) {
                            func_0x006dd300(pppppuVar31,1,uVar24 & 0xffffffff);
                          }
                          else {
                            func_0x00a58be4(1,uVar24 & 0xffffffff,1);
                          }
                        }
                        else {
                          iVar13 = Battle_CheckUnitCanMove(1,uVar24 & 0xffffffff);
                          if (0 < iVar13) {
                            pppppuVar35 = (undefined *****)0x0;
                            do {
                              uVar12 = func_0x00a590bc(1,uVar24 & 0xffffffff);
                              unaff_x25 = (undefined *****)(ulong)uVar12;
                              uVar15 = func_0x00a5a540(1,uVar24 & 0xffffffff,pppppuVar35);
                              if (uVar12 == uVar15) {
                                iVar13 = Battle_CheckUnitCanMove(1,uVar24 & 0xffffffff);
                                if ((int)pppppuVar35 == iVar13 + -1) {
                                  uVar19 = Battle_Get_83938(1,uVar24 & 0xffffffff);
                                  func_0x00a59830(1,uVar24 & 0xffffffff,uVar19);
                                  iVar13 = func_0x00a59c68(1,uVar24 & 0xffffffff);
                                  if (0 < iVar13) {
                                    Battle_Add_83ad4(1,uVar24 & 0xffffffff,0xffffffff);
                                  }
                                }
                                unaff_x25 = (undefined *****)0x0;
                                *(uint *)((long)pppppuStack_3e0 + 0x19c) = 0;
                                auVar60._8_8_ = 1;
                                auVar60._0_8_ = pppppuVar31;
                                pppppuVar25 = (undefined *****)(uVar24 & 0xffffffff);
                                uVar33 = 0;
                                uVar49 = 0x6c9514;
                                ppppuVar9 = (undefined ****)&ppppuStack_550;
                                pppppuVar40 = pppppuStack_490;
                                pppppuVar45 = pppppuVar35;
                                goto SUB_006ce084;
                              }
                              uVar12 = (int)pppppuVar35 + 1;
                              pppppuVar45 = (undefined *****)(ulong)uVar12;
                              iVar13 = Battle_CheckUnitCanMove(1,uVar24 & 0xffffffff);
                              pppppuVar35 = pppppuVar45;
                            } while ((int)uVar12 < iVar13);
                          }
                        }
                      }
                    }
                    uVar24 = uVar24 + 1;
                  } while (uVar24 != 0x33);
                  iVar13 = 0;
                  do {
                    uVar24 = func_0x00a59560(1,iVar13);
                    if ((uVar24 & 1) != 0) {
                      iVar14 = func_0x00a59a70(1,iVar13);
                      if (iVar14 == 0) {
                        iVar14 = func_0x00a5999c(1,iVar13);
                        if (iVar14 == 2) {
                          func_0x005b095c(pppppuVar31 + 0x21a,1);
                        }
                        uVar49 = func_0x0044c16c();
                        func_0x0044e35c(uVar49,0x2d,0);
                        iVar14 = 1;
                        do {
                          uVar24 = func_0x00a58fe8(0,iVar14,0xffffffff);
                          if (((uVar24 & 1) != 0) &&
                             (uVar24 = func_0x00a5fda0(0,iVar14), (uVar24 & 1) == 0)) {
                            func_0x00a58be4(0,iVar14,7);
                            func_0x00a590fc(0,iVar14,0);
                          }
                          iVar14 = iVar14 + 1;
                        } while (iVar14 != 0x33);
                      }
                      func_0x00a59afc(1,iVar13,1);
                      iVar14 = func_0x00a59a70(1,iVar13);
                      iVar20 = func_0x004400b4(lStack_408 + 0x1040);
                      if (iVar20 <= iVar14) {
                        uVar19 = func_0x004400b4(lStack_408 + 0x1040);
                        func_0x00a59ab0(1,iVar13,uVar19);
                      }
                    }
                    iVar13 = iVar13 + 1;
                  } while (iVar13 != 0x33);
                  func_0x005c1e04(pppppuVar31);
                  func_0x005c2188(pppppuVar31);
                  func_0x005c32c4(pppppuVar31);
                  func_0x005c3918(pppppuVar31);
                  func_0x005c4088(pppppuVar31);
                  Battle_AttackHitDispatch(pppppuVar31,0);
                  Battle_AttackHitDispatch(pppppuVar31,1);
                  *pppppuStack_518 = (undefined ****)0x0;
                  pppppuStack_518[1] = (undefined ****)0x0;
                  *pppppuStack_520 = (undefined ****)0x0;
                  pppppuStack_520[1] = (undefined ****)0x0;
                  apppppuStack_220[0] = pppppuStack_518;
                  apppppuStack_220[3] = pppppuStack_520;
                  uVar24 = func_0x005aacc8();
                  if ((uVar24 & 1) == 0) {
                    uVar24 = 0;
                  }
                  else {
                    uVar24 = func_0x005aad10();
                  }
                  bVar10 = false;
                  lVar28 = 0;
                  uVar24 = uVar24 & 0xffffffff;
                  uVar12 = 1;
                  do {
                    uVar33 = 0;
                    pppppuStack_3d8 = (undefined *****)(apppppuStack_220 + lVar28 * 3);
                    pppppuStack_3e8 = pppppuVar31 + lVar28 * 0x18e7;
                    pppppuStack_3c8 = (undefined *****)(apppppuStack_220 + lVar28 * 3 + 1);
                    uStack_40c = uVar12;
                    do {
                      uVar29 = func_0x00a610f8(lVar28,uVar33 & 0xffffffff);
                      if ((uVar29 & 1) != 0) {
                        func_0x00a61218(lVar28,uVar33 & 0xffffffff,1);
                        uVar12 = func_0x00a6118c(lVar28,uVar33 & 0xffffffff);
                        unaff_x26 = (undefined *****)(ulong)uVar12;
                        iVar13 = func_0x0044003c(lStack_408 + 9000);
                        if (iVar13 <= (int)uVar12) {
                          func_0x00a61140(lVar28,uVar33 & 0xffffffff,0);
                        }
                      }
                      iVar13 = func_0x00a61894(lVar28,uVar33 & 0xffffffff);
                      if (iVar13 != 0) {
                        func_0x00a619ac(lVar28,uVar33 & 0xffffffff,1);
                        uVar12 = func_0x00a61920(lVar28,uVar33 & 0xffffffff);
                        unaff_x26 = (undefined *****)(ulong)uVar12;
                        iVar13 = func_0x00a61894(lVar28,uVar33 & 0xffffffff);
                        iVar13 = func_0x0044003c(pppppuStack_3f0 + (long)iVar13 * 7 + -7);
                        if (iVar13 <= (int)uVar12) {
                          func_0x00a618d4(lVar28,uVar33 & 0xffffffff,0);
                        }
                      }
                      pppppuVar42 = pppppuStack_400;
                      if (bVar10) {
LAB_006c9d90:
                        do {
                          pppppuVar42 = (undefined *****)*pppppuVar42;
                          if (pppppuVar42 == (undefined *****)0x0) goto LAB_006c9f10;
                        } while ((long)uVar33 < (long)(int)*(uint *)(pppppuVar42 + 4));
                        if ((long)(int)*(uint *)(pppppuVar42 + 4) < (long)uVar33) {
                          pppppuVar42 = pppppuVar42 + 1;
                          goto LAB_006c9d90;
                        }
                        puStack_380 = (undefined8 *)func_0x00bc3330(0x20);
                        uStack_388 = uStack_458;
                        uStack_390 = uStack_460;
                        puStack_380[1] = 0x6c696b5f6c617465;
                        *puStack_380 = 0x6d5f656c74746162;
                        *(undefined8 *)((long)puStack_380 + 0x13) = 0x657079745f70685f;
                        *(undefined8 *)((long)puStack_380 + 0xb) = 0x72656c6c696b5f6c;
                        *(undefined1 *)((long)puStack_380 + 0x1b) = 0;
                        iVar13 = func_0x008e3f14(pppppuVar31 + 0x28f,&uStack_390,0);
                        if (iVar13 == 0) {
                          uVar29 = func_0x00a5a194(1,uVar33 & 0xffffffff);
                        }
                        else {
                          uVar29 = func_0x00a5a220(1,uVar33 & 0xffffffff);
                        }
                        unaff_x26 = (undefined *****)(uVar29 & 0xffffffff);
                        pppppuVar42 = pppppuStack_400;
                        if ((uStack_390 & 1) != 0) {
                          func_0x00bc3350(puStack_380);
                          pppppuVar42 = pppppuStack_400;
                        }
                        while (pppppuVar45 = (undefined *****)*pppppuVar42,
                              pppppuVar40 = pppppuVar42,
                              (undefined *****)*pppppuVar42 != (undefined *****)0x0) {
                          while (pppppuVar25 = pppppuVar45, pppppuVar42 = pppppuVar25,
                                (long)(int)*(uint *)(pppppuVar25 + 4) <= (long)uVar33) {
                            unaff_x27 = pppppuVar25;
                            if ((long)uVar33 <= (long)(int)*(uint *)(pppppuVar25 + 4))
                            goto LAB_006c9eb4;
                            pppppuVar45 = (undefined *****)pppppuVar25[1];
                            if ((undefined *****)pppppuVar25[1] == (undefined *****)0x0) {
                              pppppuVar42 = pppppuVar25 + 1;
                              pppppuVar40 = pppppuVar25;
                              goto LAB_006c9e58;
                            }
                          }
                        }
LAB_006c9e58:
                        pppppuVar25 = (undefined *****)func_0x00bc3330(0x40);
                        unaff_x27 = pppppuStack_468;
                        pppppuVar25[2] = (undefined ****)pppppuVar40;
                        *(uint *)(pppppuVar25 + 4) = (uint)uVar33;
                        pppppuVar25[6] = (undefined ****)0x0;
                        pppppuVar25[7] = (undefined ****)0x0;
                        pppppuVar25[5] = (undefined ****)0x0;
                        *pppppuVar25 = (undefined ****)0x0;
                        pppppuVar25[1] = (undefined ****)0x0;
                        *pppppuVar42 = (undefined ****)pppppuVar25;
                        pppppuVar45 = pppppuVar25;
                        if ((undefined ****)*pppppuStack_468[3] != (undefined ****)0x0) {
                          pppppuStack_468[3] = (undefined ****)*pppppuStack_468[3];
                          pppppuVar45 = (undefined *****)*pppppuVar42;
                        }
                        func_0x0040a8c0(pppppuStack_468[4],pppppuVar45);
                        unaff_x27[5] = (undefined ****)((long)unaff_x27[5] + 1);
LAB_006c9eb4:
                        ppppuVar38 = pppppuVar25[6];
                        for (ppppuVar37 = pppppuVar25[5]; ppppuVar37 != ppppuVar38;
                            ppppuVar37 = (undefined ****)((long)ppppuVar37 + 4)) {
                          uVar12 = func_0x0043ed6c((*(int *)ppppuVar37 * (int)unaff_x26) / 100,1);
                          unaff_x27 = (undefined *****)(ulong)uVar12;
                          func_0x00a60488(1,uVar33 & 0xffffffff,unaff_x27);
                          uVar12 = (int)unaff_x26 - uVar12;
                          unaff_x26 = (undefined *****)
                                      (ulong)(uVar12 & ((int)uVar12 >> 0x1f ^ 0xffffffffU));
                        }
LAB_006c9f10:
                        if ((((uVar33 == uVar24) && (uVar29 = func_0x005aaf3c(), (uVar29 & 1) != 0))
                            && (uVar29 = func_0x00a606ac(1,uVar24), (uVar29 & 1) != 0)) &&
                           (iVar13 = func_0x00a5a220(1,uVar24), 1 < iVar13)) {
                          uVar12 = func_0x00a5a220(1,uVar24);
                          unaff_x26 = (undefined *****)(ulong)uVar12;
                          iVar13 = func_0x00a603d4(1,uVar24);
                          if ((int)uVar12 <= iVar13) {
                            iVar13 = func_0x00a5a220(1,uVar24);
                            func_0x00a60414(1,uVar24,iVar13 + -1);
                          }
                        }
                      }
                      iVar13 = func_0x00a58874(lVar28,uVar33 & 0xffffffff);
                      if ((iVar13 == 2) &&
                         (uVar29 = func_0x00a606ac(lVar28,uVar33 & 0xffffffff), (uVar29 & 1) != 0))
                      {
                        iVar13 = func_0x00a5fe34(lVar28,uVar33 & 0xffffffff);
                        if ((0 < iVar13) ||
                           (iVar13 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff), 0 < iVar13)) {
                          iVar13 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff);
                          pppppuVar42 = pppppuStack_3c8;
                          if (0 < iVar13) {
                            while (unaff_x27 = pppppuVar42,
                                  pppppuVar42 = (undefined *****)*unaff_x27, unaff_x26 = unaff_x27,
                                  (undefined *****)*unaff_x27 != (undefined *****)0x0) {
                              while (unaff_x26 = pppppuVar42, pppppuVar42 = unaff_x26,
                                    (long)(int)*(uint *)((long)unaff_x26 + 0x1c) <= (long)uVar33) {
                                if ((long)uVar33 <= (long)(int)*(uint *)((long)unaff_x26 + 0x1c))
                                goto LAB_006ca06c;
                                pppppuVar42 = (undefined *****)unaff_x26[1];
                                if ((undefined *****)unaff_x26[1] == (undefined *****)0x0) {
                                  unaff_x27 = unaff_x26 + 1;
                                  goto LAB_006ca014;
                                }
                              }
                            }
LAB_006ca014:
                            pppppuVar40 = (undefined *****)func_0x00bc3330(0x28);
                            pppppuVar42 = pppppuStack_3d8;
                            pppppuVar40[2] = (undefined ****)unaff_x26;
                            *(uint *)((long)pppppuVar40 + 0x1c) = (uint)uVar33;
                            *(undefined1 *)(pppppuVar40 + 4) = 0;
                            *pppppuVar40 = (undefined ****)0x0;
                            pppppuVar40[1] = (undefined ****)0x0;
                            *unaff_x27 = (undefined ****)pppppuVar40;
                            pppppuVar45 = pppppuVar40;
                            if ((undefined ****)**pppppuStack_3d8 != (undefined ****)0x0) {
                              *pppppuStack_3d8 = (undefined ****)**pppppuStack_3d8;
                              pppppuVar45 = (undefined *****)*unaff_x27;
                            }
                            func_0x0040a8c0(pppppuStack_3d8[1],pppppuVar45);
                            pppppuVar42[2] = (undefined ****)((long)pppppuVar42[2] + 1);
                            unaff_x26 = pppppuVar40;
LAB_006ca06c:
                            *(undefined1 *)(unaff_x26 + 4) = 1;
                            iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                            if (iVar13 == 0) {
                              iVar13 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff);
                              iVar14 = func_0x00a603d4(lVar28,uVar33 & 0xffffffff);
                              uVar12 = func_0x0043ed6c(iVar13 - iVar14,0);
                              unaff_x26 = (undefined *****)(ulong)uVar12;
                              func_0x00a617bc(lVar28,uVar33 & 0xffffffff,unaff_x26);
                              if ((int)uVar12 < 1) {
                                func_0x00a61848(lVar28,uVar33 & 0xffffffff,1);
                              }
                            }
                          }
                          iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff);
                          if (iVar13 != 0) {
                            func_0x00a5fe74(lVar28,uVar33 & 0xffffffff,0);
                          }
                          iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                          if (iVar13 != 0) {
                            func_0x00a617bc(lVar28,uVar33 & 0xffffffff,0);
                          }
                          iVar13 = func_0x00a5fe34(lVar28,uVar33 & 0xffffffff);
                          if (((0 < iVar13) &&
                              (iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff), iVar13 == 0))
                             || ((iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff), iVar13 == 1
                                 || (((iVar13 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff),
                                      0 < iVar13 &&
                                      (iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff),
                                      iVar13 == 0)) ||
                                     (iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff),
                                     iVar13 == 1)))))) {
                            func_0x00a60414(lVar28,uVar33 & 0xffffffff,0);
                            func_0x00a61d74(lVar28,uVar33 & 0xffffffff,0);
                            uVar19 = func_0x00a60a14(lVar28,uVar33 & 0xffffffff);
                            func_0x00a608e8(lVar28,uVar33 & 0xffffffff,uVar19);
                            uVar19 = func_0x00a60c0c(lVar28,uVar33 & 0xffffffff);
                            func_0x00a60ae0(lVar28,uVar33 & 0xffffffff,uVar19);
                            uVar19 = func_0x00a60e90(lVar28,uVar33 & 0xffffffff);
                            func_0x00a60cd8(lVar28,uVar33 & 0xffffffff,uVar19);
                            uVar19 = func_0x00a6106c(lVar28,uVar33 & 0xffffffff);
                            func_0x00a60f80(lVar28,uVar33 & 0xffffffff,uVar19);
                            func_0x00a5a97c(lVar28,uVar33 & 0xffffffff,0);
                          }
                          iVar13 = func_0x00a5fe34(lVar28,uVar33 & 0xffffffff);
                          if ((0 < iVar13) ||
                             (iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff), iVar13 == 1)) {
                            func_0x00a6073c(lVar28,uVar33 & 0xffffffff,0);
                            func_0x00a614dc(lVar28,uVar33 & 0xffffffff,0);
                            func_0x00a61730(lVar28,uVar33 & 0xffffffff,0);
                            func_0x00a61c08(lVar28,uVar33 & 0xffffffff,0);
                          }
                          iVar13 = func_0x00a5fe34(lVar28,uVar33 & 0xffffffff);
                          if ((iVar13 < 1) ||
                             (iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff), iVar13 != 0)) {
                            iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff);
                            if ((iVar13 == 1) ||
                               (iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff), iVar13 == 2))
                            {
                              func_0x00a61140(lVar28,uVar33 & 0xffffffff,0);
                              iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff);
                              if (iVar13 == 1) {
                                uVar49 = func_0x0044c16c();
                                uVar34 = 0x48;
LAB_006ca328:
                                func_0x0044e364(uVar49,uVar34);
                              }
                              else {
                                iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff);
                                if (iVar13 == 2) {
                                  uVar49 = func_0x0044c16c();
                                  uVar34 = 0x46;
                                  goto LAB_006ca328;
                                }
                              }
                              lVar30 = 0x1e;
                              unaff_x26 = pppppuStack_450;
                              do {
                                if (*(char *)unaff_x26 == '\0') {
                                  func_0x005aa6a8(unaff_x26);
                                  *(undefined1 *)unaff_x26 = 1;
                                  *(uint *)((long)unaff_x26 + 4) =
                                       *(uint *)((long)pppppuVar31 +
                                                (lVar28 * 0x31ce + uVar33 * 0xfa + 0x20e45) * 4);
                                  *(uint *)(unaff_x26 + 1) =
                                       *(uint *)(pppppuVar31 +
                                                uVar33 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                                  iVar13 = func_0x00a60620(lVar28,uVar33 & 0xffffffff);
                                  *(bool *)(unaff_x26 + 3) = iVar13 == 2;
                                  break;
                                }
                                lVar30 = lVar30 + -1;
                                unaff_x26 = (undefined *****)((long)unaff_x26 + 0x1c);
                              } while (lVar30 != 0);
                            }
                          }
                          else {
                            uVar29 = func_0x00a610f8(lVar28,uVar33 & 0xffffffff);
                            if ((uVar29 & 1) == 0) {
                              func_0x00a61140(lVar28,uVar33 & 0xffffffff,1);
                            }
                            func_0x00a611cc(lVar28,uVar33 & 0xffffffff,0);
                            uVar49 = func_0x0044c16c();
                            func_0x0044e364(uVar49,0x47);
                          }
                          iVar13 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff);
                          if ((iVar13 < 1) ||
                             (iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff), iVar13 != 0)) {
                            iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                            if ((iVar13 == 1) ||
                               (iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff), iVar13 == 2))
                            {
                              func_0x00a618d4(lVar28,uVar33 & 0xffffffff,0);
                              iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                              if (iVar13 == 1) {
                                uVar49 = func_0x0044c16c();
                                uVar34 = 0x89;
LAB_006ca478:
                                func_0x0044e364(uVar49,uVar34);
                              }
                              else {
                                iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                                if (iVar13 == 2) {
                                  uVar49 = func_0x0044c16c();
                                  uVar34 = 0x8b;
                                  goto LAB_006ca478;
                                }
                              }
                              lVar30 = 0x1e;
                              unaff_x26 = pppppuStack_3d0;
                              do {
                                if (*(char *)unaff_x26 == '\0') {
                                  func_0x005aa6c0(unaff_x26);
                                  *(undefined1 *)unaff_x26 = 1;
                                  *(uint *)((long)unaff_x26 + 4) =
                                       *(uint *)((long)pppppuStack_3e8 +
                                                (uVar33 * 0xfa + 0x20e45) * 4);
                                  *(uint *)(unaff_x26 + 1) =
                                       *(uint *)(pppppuStack_3e8 + uVar33 * 0x7d + 0x10723) - 0x1a4;
                                  iVar13 = func_0x00a61808(lVar28,uVar33 & 0xffffffff);
                                  *(bool *)(unaff_x26 + 3) = iVar13 == 2;
                                  break;
                                }
                                lVar30 = lVar30 + -1;
                                unaff_x26 = (undefined *****)((long)unaff_x26 + 0x1c);
                              } while (lVar30 != 0);
                            }
                          }
                          else {
                            iVar13 = func_0x00a61894(lVar28,uVar33 & 0xffffffff);
                            if (iVar13 == 0) {
                              uVar12 = func_0x00a6177c(lVar28,uVar33 & 0xffffffff);
                              unaff_x26 = (undefined *****)(ulong)uVar12;
                              iVar13 = func_0x00a5fec0(lVar28,uVar33 & 0xffffffff);
                              if (iVar13 < 0) {
                                iVar13 = iVar13 + 1;
                              }
                              uVar19 = 1;
                              if ((int)uVar12 < iVar13 >> 1) {
                                uVar19 = 2;
                              }
                              func_0x00a618d4(lVar28,uVar33 & 0xffffffff,uVar19);
                            }
                            func_0x00a61960(lVar28,uVar33 & 0xffffffff,0);
                            uVar49 = func_0x0044c16c();
                            func_0x0044e364(uVar49,0x88);
                          }
                        }
                        uVar29 = func_0x005ab294();
                        if ((uVar29 & 1) != 0) {
                          iVar13 = func_0x00a5a93c(lVar28,uVar33 & 0xffffffff);
                          *(uint *)((long)pppppuVar31 + 0x32cc) =
                               *(uint *)((long)pppppuVar31 + 0x32cc) + iVar13;
                          func_0x00a5a97c(lVar28,uVar33 & 0xffffffff,0);
                        }
                      }
                      uVar33 = uVar33 + 1;
                    } while (uVar33 != 0x33);
                    uVar12 = 0;
                    bVar10 = true;
                    lVar28 = 1;
                  } while ((uStack_40c & 1) != 0);
                  ppppuVar37 = *pppppuStack_4c8;
                  ppppuVar38 = pppppuStack_4c8[1];
                  if (ppppuVar38 != ppppuVar37) {
                    uVar24 = 0;
                    do {
                      pppuVar39 = ppppuVar37[uVar24];
                      if (*(int *)(pppuVar39 + 1) == 0) {
                        iVar13 = func_0x00a603d4(*(undefined4 *)pppuVar39,
                                                 *(undefined4 *)((long)pppuVar39 + 4));
                        uVar19 = 1;
                        if (0 < iVar13) {
                          uVar19 = 2;
                        }
                        ppppuVar37 = *pppppuStack_4c8;
                        *(undefined4 *)(ppppuVar37[uVar24] + 1) = uVar19;
                        ppppuVar38 = pppppuStack_4c8[1];
                      }
                      uVar24 = uVar24 + 1;
                    } while (uVar24 < (ulong)((long)ppppuVar38 - (long)ppppuVar37 >> 3));
                  }
                  unaff_x25 = (undefined *****)0x33;
                  if (pppppuStack_470[1] != *pppppuStack_470) {
                    lVar28 = 0;
                    uVar24 = 0;
                    unaff_x25 = (undefined *****)0x4;
                    do {
                      uVar33 = func_0x005aacc8();
                      if (((uVar33 & 1) == 0) ||
                         (iVar13 = func_0x005aacf0(),
                         *(uint *)((long)pppppuStack_3c0 + ((long)iVar13 * 0x71 + 0x8cc77) * 4) == 0
                         )) {
                        iVar13 = func_0x00a5a220(1,0);
                        iVar14 = func_0x00a603d4(1,0);
                        uVar12 = *(uint *)(pppppuStack_498 + 2);
                        iVar20 = func_0x009cbcc8((long)*pppppuStack_470 + lVar28);
                        if (iVar13 - iVar14 <= (int)(iVar20 * uVar12) / 100) goto LAB_006ca704;
                      }
                      else {
                        uVar19 = func_0x005aad10();
                        iVar13 = func_0x00a59b50(1,uVar19);
                        iVar14 = func_0x009cbcc8((long)*pppppuStack_470 + lVar28);
                        if (iVar14 <= iVar13) {
LAB_006ca704:
                          iVar13 = func_0x009cbca8((long)*pppppuStack_470 + lVar28);
                          if (((iVar13 == 0) ||
                              (iVar13 = *(int *)((long)*pppppuStack_468 + (long)unaff_x25),
                              iVar14 = func_0x009cbca8((long)*pppppuStack_470 + lVar28),
                              iVar13 < iVar14)) &&
                             (bVar11 = func_0x009cbce8((long)*pppppuStack_470 + lVar28),
                             (bVar11 & 1 < (int)*(uint *)((long)pppppuStack_498 + 0x14)) == 1)) {
                            *(undefined1 *)(pppppuStack_3c0 + 0x72501) = 1;
                          }
                        }
                      }
                      uVar24 = uVar24 + 1;
                      unaff_x25 = (undefined *****)((long)unaff_x25 + 0xc);
                      lVar28 = lVar28 + 0x38;
                      uVar33 = ((long)pppppuStack_470[1] - (long)*pppppuStack_470 >> 3) *
                               0x6db6db6db6db6db7;
                    } while (uVar24 <= uVar33 && uVar33 - uVar24 != 0);
                  }
                  uVar24 = func_0x005aacc8();
                  pppppuVar35 = pppppuStack_3c0;
                  if ((uVar24 & 1) != 0) {
                    uVar19 = func_0x005aad10();
                    uVar16 = func_0x00a5a220(1,uVar19);
                    func_0x00a5a260(1,0,uVar16);
                    uVar16 = func_0x00a5a194(1,uVar19);
                    func_0x00a5a1d4(1,0,uVar16);
                    uVar19 = func_0x00a603d4(1,uVar19);
                    func_0x00a60414(1,0,uVar19);
                  }
                  uVar49 = 0;
                  lVar28 = 0;
                  uVar19 = 1;
                  pppppuStack_3e8 = (undefined *****)((ulong)pppppuStack_3e8 & 0xffffffff00000000);
                  do {
                    pppppuStack_3c8 = (undefined *****)CONCAT44(pppppuStack_3c8._4_4_,uVar19);
                    uVar24 = 0;
                    pppppuStack_438 = (undefined *****)(apppppuStack_220 + lVar28 * 3);
                    uStack_230 = 0;
                    pppppuStack_3d8 = pppppuVar35 + lVar28 * 0x18e7 + 0x10721;
                    uStack_248 = 0;
                    uStack_250 = 0;
                    uStack_238 = 0;
                    uStack_240 = 0;
                    pppppuVar42 = pppppuVar35 + lVar28 * 0x3e;
                    uStack_41c = (uint)uVar49 ^ 1;
                    pppppuStack_430 = (undefined *****)(apppppuStack_220 + lVar28 * 3 + 1);
                    pppppuStack_428 = pppppuVar35 + lVar28 * 0x70 + 0x138ef;
                    uStack_418 = uVar49;
                    do {
                      if (*(uint *)(pppppuVar35 + uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10721) != 0) {
                        iVar13 = func_0x00a603d4(lVar28,uVar24 & 0xffffffff);
                        if (iVar13 != 0) {
                          uVar12 = func_0x005aacc8();
                          if ((((uint)uStack_418 & uVar12 & 1) != 0) &&
                             ((uVar24 == 0 ||
                              (uVar33 = func_0x005aad10(), uVar24 == (uVar33 & 0xffffffff))))) {
                            uVar19 = func_0x005aad10();
                            uVar33 = func_0x00a5fc78(1,uVar19);
                            if ((uVar33 & 1) != 0) goto LAB_006ca938;
                          }
                          bVar10 = uVar24 == 0;
                          if (!bVar10 && (uStack_41c & 1) == 0) {
                            uVar33 = func_0x005aad10();
                            bVar10 = uVar24 == (uVar33 & 0xffffffff);
                          }
                          uVar19 = 2;
                          if (bVar10) {
                            uVar19 = 3;
                          }
                          func_0x006ee0f4(pppppuStack_3c0 + 0x1c,lVar28,uVar19);
                        }
LAB_006ca938:
                        iVar13 = func_0x00a603d4(lVar28,uVar24 & 0xffffffff);
                        pppppuVar45 = pppppuStack_430;
                        if (iVar13 == 0) {
                          while (unaff_x26 = pppppuVar45, pppppuVar40 = (undefined *****)*unaff_x26,
                                pppppuVar45 = unaff_x26,
                                (undefined *****)*unaff_x26 != (undefined *****)0x0) {
                            while (pppppuVar45 = pppppuVar40,
                                  (long)(int)*(uint *)((long)pppppuVar45 + 0x1c) <= (long)uVar24) {
                              if ((long)uVar24 <= (long)(int)*(uint *)((long)pppppuVar45 + 0x1c)) {
                                cVar1 = *(char *)(pppppuVar45 + 4);
                                unaff_x25 = pppppuVar45;
                                goto joined_r0x006ca9dc;
                              }
                              pppppuVar40 = (undefined *****)pppppuVar45[1];
                              if ((undefined *****)pppppuVar45[1] == (undefined *****)0x0) {
                                unaff_x26 = pppppuVar45 + 1;
                                goto LAB_006ca978;
                              }
                            }
                          }
LAB_006ca978:
                          unaff_x25 = (undefined *****)func_0x00bc3330(0x28);
                          pppppuVar40 = pppppuStack_438;
                          *(uint *)((long)unaff_x25 + 0x1c) = (uint)uVar24;
                          *(undefined1 *)(unaff_x25 + 4) = 0;
                          *unaff_x25 = (undefined ****)0x0;
                          unaff_x25[1] = (undefined ****)0x0;
                          unaff_x25[2] = (undefined ****)pppppuVar45;
                          *unaff_x26 = (undefined ****)unaff_x25;
                          pppppuVar45 = unaff_x25;
                          if ((undefined ****)**pppppuStack_438 != (undefined ****)0x0) {
                            *pppppuStack_438 = (undefined ****)**pppppuStack_438;
                            pppppuVar45 = (undefined *****)*unaff_x26;
                          }
                          func_0x0040a8c0(pppppuStack_438[1],pppppuVar45);
                          pppppuVar40[2] = (undefined ****)((long)pppppuVar40[2] + 1);
                          cVar1 = *(char *)(unaff_x25 + 4);
joined_r0x006ca9dc:
                          if (cVar1 == '\0') goto LAB_006ca888;
                        }
                        pppppuVar45 = pppppuStack_3c8;
                        if ((((ulong)pppppuStack_3c8 & 1) != 0 || uVar24 != 0) ||
                           (uVar33 = func_0x005aacc8(), (uVar33 & 1) == 0)) {
                          uVar33 = func_0x00a606f4(lVar28,uVar24 & 0xffffffff);
                          if (((uVar33 & 1) == 0) &&
                             (((uVar33 = func_0x00a61494(lVar28,uVar24 & 0xffffffff),
                               (uVar33 & 1) == 0 &&
                               (uVar33 = func_0x00a616e8(lVar28,uVar24 & 0xffffffff),
                               (uVar33 & 1) == 0)) &&
                              (uVar33 = func_0x00a61bc0(lVar28,uVar24 & 0xffffffff),
                              pppppuVar40 = pppppuStack_3c0, (uVar33 & 1) == 0)))) {
LAB_006cae10:
                            *(uint *)(pppppuVar40 + uVar24 * 2 + lVar28 * 0x70 + 0x138ef) = 0xc;
                          }
                          else {
                            uVar33 = func_0x00a606f4(lVar28,uVar24 & 0xffffffff);
                            if ((uVar33 & 1) != 0) {
                              unaff_x22 = (undefined *****)0x0;
                              pppppuVar40 = pppppuStack_448;
                              do {
                                if (*(char *)pppppuVar40 == '\0') {
                                  *(uint *)((long)pppppuVar40 + 0xc) = 0;
                                  *(undefined1 *)pppppuVar40 = 1;
                                  goto LAB_006caa80;
                                }
                                unaff_x22 = (undefined *****)((long)unaff_x22 + 1);
                                pppppuVar40 = pppppuVar40 + 2;
                              } while (unaff_x22 != (undefined *****)0xc8);
                              unaff_x22 = (undefined *****)0x0;
                            }
LAB_006caa80:
                            uVar33 = func_0x00a61494(lVar28,uVar24 & 0xffffffff);
                            if ((uVar33 & 1) != 0) {
                              if (uVar24 == 0) {
                                uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                                iVar14 = func_0x0043ea60(0x19);
                                uVar17 = (uVar12 + iVar13 * 10) - 0x3a9;
                                uVar12 = (uVar15 + iVar14 * -10) - 0x497;
                              }
                              else {
                                uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                  (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45) * 4);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3c0 +
                                                  uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                                iVar14 = func_0x0043ea60(0x1f);
                                uVar17 = (uVar12 + iVar13 * -10) - 0x1b5;
                                uVar12 = (uVar15 + iVar14 * 10) - 0x52d;
                              }
                              unaff_x27 = (undefined *****)(ulong)uVar12;
                              unaff_x26 = (undefined *****)(ulong)uVar17;
                              unaff_x25 = (undefined *****)func_0x00bc3330(0xc);
                              pppppuVar40 = pppppuStack_3c0;
                              func_0x005aa6cc(unaff_x25,unaff_x26,unaff_x27);
                              ppppuVar37 = pppppuStack_3d0[0x6a];
                              if (ppppuVar37 < pppppuStack_3d0[0x6b]) {
                                pppppuStack_398 = (undefined *****)0x0;
                                ppppuVar38 = ppppuVar37 + 1;
                                *ppppuVar37 = (undefined ***)unaff_x25;
                              }
                              else {
                                pppppuStack_398 = unaff_x25;
                                ppppuVar38 = (undefined ****)
                                             func_0x006d4f44(pppppuVar40 + 0x13c9a,&pppppuStack_398)
                                ;
                              }
                              pppppuVar40 = pppppuStack_398;
                              pppppuStack_398 = (undefined *****)0x0;
                              pppppuStack_3d0[0x6a] = ppppuVar38;
                              if (pppppuVar40 != (undefined *****)0x0) {
                                func_0x00bc3350(pppppuVar40);
                              }
                            }
                            uVar33 = func_0x00a616e8(lVar28,uVar24 & 0xffffffff);
                            if ((uVar33 & 1) != 0) {
                              if (uVar24 == 0) {
                                uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                                iVar14 = func_0x0043ea60(0x19);
                                uVar17 = (uVar12 + iVar13 * 10) - 0x3a9;
                                uVar12 = (uVar15 + iVar14 * -10) - 0x497;
                              }
                              else {
                                uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                  (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45) * 4);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3c0 +
                                                  uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                                iVar14 = func_0x0043ea60(0x1f);
                                uVar17 = (uVar12 + iVar13 * -10) - 0x1b5;
                                uVar12 = (uVar15 + iVar14 * 10) - 0x52d;
                              }
                              unaff_x27 = (undefined *****)(ulong)uVar12;
                              unaff_x26 = (undefined *****)(ulong)uVar17;
                              unaff_x25 = (undefined *****)func_0x00bc3330(0xc);
                              pppppuVar40 = pppppuStack_3c0;
                              func_0x005aa6cc(unaff_x25,unaff_x26,unaff_x27);
                              ppppuVar37 = pppppuStack_3d0[0x6d];
                              if (ppppuVar37 < pppppuStack_3d0[0x6e]) {
                                pppppuStack_398 = (undefined *****)0x0;
                                ppppuVar38 = ppppuVar37 + 1;
                                *ppppuVar37 = (undefined ***)unaff_x25;
                              }
                              else {
                                pppppuStack_398 = unaff_x25;
                                ppppuVar38 = (undefined ****)
                                             func_0x006d4f44(pppppuVar40 + 0x13c9d,&pppppuStack_398)
                                ;
                              }
                              pppppuVar40 = pppppuStack_398;
                              pppppuStack_398 = (undefined *****)0x0;
                              pppppuStack_3d0[0x6d] = ppppuVar38;
                              if (pppppuVar40 != (undefined *****)0x0) {
                                func_0x00bc3350(pppppuVar40);
                              }
                            }
                            uVar33 = func_0x00a61bc0(lVar28,uVar24 & 0xffffffff);
                            if ((uVar33 & 1) != 0) {
                              if (uVar24 == 0) {
                                uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                                iVar14 = func_0x0043ea60(0x19);
                                uVar12 = (uVar12 + iVar13 * 10) - 0x3a9;
                                uVar15 = (uVar15 + iVar14 * -10) - 0x497;
                              }
                              else {
                                uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                  (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45) * 4);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3c0 +
                                                  uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                                iVar14 = func_0x0043ea60(0x1f);
                                uVar12 = (uVar12 + iVar13 * -10) - 0x1b5;
                                uVar15 = (uVar15 + iVar14 * 10) - 0x52d;
                              }
                              unaff_x27 = (undefined *****)(ulong)uVar15;
                              unaff_x26 = (undefined *****)(ulong)uVar12;
                              unaff_x25 = (undefined *****)func_0x00bc3330(0xc);
                              pppppuVar40 = pppppuStack_3c0;
                              func_0x005aa6cc(unaff_x25,unaff_x26,unaff_x27);
                              ppppuVar37 = pppppuStack_3d0[0x70];
                              if (ppppuVar37 < pppppuStack_3d0[0x71]) {
                                pppppuStack_398 = (undefined *****)0x0;
                                ppppuVar38 = ppppuVar37 + 1;
                                *ppppuVar37 = (undefined ***)unaff_x25;
                              }
                              else {
                                pppppuStack_398 = unaff_x25;
                                ppppuVar38 = (undefined ****)
                                             func_0x006d4f44(pppppuVar40 + 0x13ca0,&pppppuStack_398)
                                ;
                              }
                              pppppuVar31 = pppppuStack_398;
                              pppppuStack_398 = (undefined *****)0x0;
                              pppppuStack_3d0[0x70] = ppppuVar38;
                              if (pppppuVar31 != (undefined *****)0x0) {
                                func_0x00bc3350(pppppuVar31);
                              }
                              goto LAB_006cae10;
                            }
                          }
                          iVar13 = (int)unaff_x22;
                          if (uVar24 == 0) {
                            uVar33 = func_0x00a606f4(lVar28,0);
                            if ((uVar33 & 1) != 0) {
                              uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                              iVar14 = func_0x0043ea60(0x2e);
                              uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                              *(uint *)((long)pppppuStack_3c0 + ((long)iVar13 * 4 + 0x273f9) * 4) =
                                   (uVar12 + iVar14 * 10) - 0x3a9;
                              iVar14 = func_0x0043ea60(0x19);
                              *(uint *)(pppppuStack_3c0 + (long)iVar13 * 2 + 0x139fd) =
                                   (uVar15 + iVar14 * -10) - 0x497;
                            }
                            uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                            iVar13 = func_0x0043ea60(0x2e);
                            uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                            *(uint *)((long)pppppuStack_428 + 4) = (uVar12 + iVar13 * 10) - 0x3a9;
                            iVar13 = func_0x0043ea60(0x19);
                            uVar12 = *(uint *)(pppppuStack_3d8 + 0x30);
                            uVar17 = *(uint *)((long)pppppuStack_3d8 + 4);
                            *(uint *)(pppppuStack_428 + 1) = (uVar15 + iVar13 * -10) - 0x497;
                            *(uint *)((long)pppppuStack_428 + 0xc) = (uint)(uVar12 == 1);
                            if (uVar17 < 2) {
                              ((uint *)((long)pppppuStack_3d8 + 4))[0] = 1;
                              ((uint *)((long)pppppuStack_3d8 + 4))[1] = 4;
                            }
                            if (((ulong)pppppuStack_3c8 & 1) != 0) {
                              func_0x005b095c(pppppuStack_3c0 + 0x21a,0);
                            }
                            pppppuStack_3e8 = (undefined *****)CONCAT44(pppppuStack_3e8._4_4_,2);
                          }
                          else {
                            uVar12 = (uint)pppppuStack_3e8;
                            if ((uint)pppppuStack_3e8 < 2) {
                              uVar12 = 1;
                            }
                            pppppuStack_3e8 =
                                 (undefined *****)CONCAT44(pppppuStack_3e8._4_4_,uVar12);
                            if ((((ulong)pppppuStack_3c8 & 1) == 0) &&
                               (uVar33 = func_0x005aad10(), uVar24 == (uVar33 & 0xffffffff))) {
                              func_0x00a61a40(1,uVar24 & 0xffffffff,4);
                              pppppuStack_3e8 = (undefined *****)CONCAT44(pppppuStack_3e8._4_4_,2);
                            }
                            uVar33 = func_0x00a606f4(lVar28,uVar24 & 0xffffffff);
                            if ((uVar33 & 1) != 0) {
                              uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45) * 4);
                              iVar14 = func_0x0043ea60(0x2e);
                              uVar15 = *(uint *)(pppppuStack_3c0 +
                                                uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                              *(uint *)((long)pppppuStack_3c0 + ((long)iVar13 * 4 + 0x273f9) * 4) =
                                   (uVar12 + iVar14 * -10) - 0x1b5;
                              iVar14 = func_0x0043ea60(0x1f);
                              *(uint *)(pppppuStack_3c0 + (long)iVar13 * 2 + 0x139fd) =
                                   (uVar15 + iVar14 * 10) - 0x52d;
                            }
                            uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                              (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45) * 4);
                            iVar13 = func_0x0043ea60(0x2e);
                            uVar15 = *(uint *)(pppppuStack_3c0 +
                                              uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723);
                            *(uint *)((long)pppppuStack_3c0 +
                                     (lVar28 * 0xe0 + uVar24 * 4 + 0x271df) * 4) =
                                 (uVar12 + iVar13 * -10) - 0x1b5;
                            iVar13 = func_0x0043ea60(0x1f);
                            *(uint *)(pppppuStack_3c0 + uVar24 * 2 + lVar28 * 0x70 + 0x138f0) =
                                 (uVar15 + iVar13 * 10) - 0x52d;
                            *(uint *)((long)pppppuStack_3c0 +
                                     (lVar28 * 0xe0 + uVar24 * 4 + 0x271e1) * 4) =
                                 *(uint *)(pppppuStack_3c0 +
                                          uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10751);
                          }
                          uStack_40c = func_0x00a5a220(lVar28,uVar24 & 0xffffffff);
                          uVar33 = func_0x00a5fc78(lVar28,uVar24 & 0xffffffff);
                          if ((uVar33 & 1) == 0) {
                            iVar13 = func_0x00a603d4(lVar28,uVar24 & 0xffffffff);
                            func_0x00a5a2ac(lVar28,uVar24 & 0xffffffff,-iVar13);
                          }
                          pppppuVar40 = pppppuStack_3c0;
                          if ((((ulong)pppppuStack_3c8 & 1) != 0) &&
                             (iVar13 = func_0x00a61d34(0,uVar24 & 0xffffffff),
                             pppppuVar40 = pppppuStack_3c0, 0 < iVar13)) {
                            uVar33 = func_0x005ab2d8(0,uVar24 & 0xffffffff);
                            unaff_x26 = (undefined *****)(uVar33 & 0xffffffff);
                            iVar13 = func_0x005b21ec(pppppuVar42 + 0x4c9,unaff_x26);
                            if (0 < iVar13) {
                              iVar13 = func_0x00a61d34(0,uVar24 & 0xffffffff);
                              uVar33 = -((ulong)unaff_x26 >> 0x1f) & 0xfffffffc00000000 |
                                       (long)unaff_x26 << 2;
                              *(int *)((long)&uStack_250 + uVar33) =
                                   *(int *)((long)&uStack_250 + uVar33) + iVar13;
                              if (uVar24 == 0) {
                                uVar12 = *(uint *)((long)pppppuStack_3d8 + 0xc);
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3d8 + 2);
                                iVar14 = func_0x0043ea60(0x19);
                                uVar12 = (uVar12 + iVar13 * 10) - 0x3a9;
                                iVar13 = uVar15 + iVar14 * -10 + -0x497;
                              }
                              else {
                                uVar12 = *(uint *)((long)pppppuVar40 + (uVar24 * 0xfa + 0x20e45) * 4
                                                  );
                                iVar13 = func_0x0043ea60(0x2e);
                                uVar15 = *(uint *)(pppppuStack_3c0 + uVar24 * 0x7d + 0x10723);
                                iVar14 = func_0x0043ea60(0x1f);
                                uVar12 = (uVar12 + iVar13 * -10) - 0x1b5;
                                iVar13 = uVar15 + iVar14 * 10 + -0x52d;
                              }
                              unaff_x27 = (undefined *****)(ulong)uVar12;
                              unaff_x25 = (undefined *****)(ulong)uVar15;
                              unaff_x26 = (undefined *****)func_0x00bc3330(0xc);
                              pppppuVar40 = pppppuStack_3c0;
                              func_0x005aa6cc(unaff_x26,unaff_x27,iVar13);
                              ppppuVar37 = pppppuStack_3d0[0x73];
                              if (ppppuVar37 < pppppuStack_3d0[0x74]) {
                                pppppuStack_398 = (undefined *****)0x0;
                                ppppuVar38 = ppppuVar37 + 1;
                                *ppppuVar37 = (undefined ***)unaff_x26;
                              }
                              else {
                                pppppuStack_398 = unaff_x26;
                                ppppuVar38 = (undefined ****)
                                             func_0x006d4f44(pppppuVar40 + 0x13ca3,&pppppuStack_398)
                                ;
                              }
                              pppppuVar31 = pppppuStack_398;
                              pppppuStack_398 = (undefined *****)0x0;
                              pppppuStack_3d0[0x73] = ppppuVar38;
                              if (pppppuVar31 != (undefined *****)0x0) {
                                func_0x00bc3350(pppppuVar31);
                              }
                            }
                          }
                          if (((((ulong)pppppuVar45 & 1) == 0 && uVar24 == 0) &&
                               *(char *)(pppppuVar40 + 0x72501) != '\0') &&
                             (iVar13 = func_0x00a5a220(1,0), iVar13 < 1)) {
                            func_0x00a5a260(1,0,1);
                          }
                          pppppuVar45 = pppppuStack_3c0;
                          if ((((0 < (int)*(uint *)((long)pppppuStack_3c0 +
                                                   (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8b) * 4))
                               && (uVar49 = func_0x0043ea60(100),
                                  (int)uVar49 <=
                                  (int)*(uint *)((long)pppppuVar45 +
                                                (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8b) * 4)))
                              && ((int)*(uint *)(pppppuStack_3c0 +
                                                uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10725) < 1)) &&
                             (*(uint *)((long)pppppuStack_3c0 +
                                       (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8f) * 4) == 0)) {
                            *(uint *)(pppppuStack_3c0 + uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10725) =
                                 1;
                            *(uint *)((long)pppppuStack_3c0 +
                                     (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8f) * 4) = 1;
                            func_0x006ce4cc(uVar49,lVar28,uVar24 & 0xffffffff,3);
                            uVar49 = func_0x0044c16c();
                            func_0x0044e35c(uVar49,0x32,0);
                          }
                          pppppuVar45 = pppppuStack_3c0 + uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10725;
                          if ((int)*(uint *)pppppuVar45 < 1) {
                            *(uint *)pppppuVar45 = 0;
                            if (((ulong)pppppuStack_3c8 & 1) != 0) {
                              *(uint *)(pppppuStack_3c0 + 0x21f) =
                                   *(uint *)(pppppuStack_3c0 + 0x21f) + 1;
                              goto joined_r0x006cb4c0;
                            }
                            iVar13 = func_0x00a58934(1,uVar24 & 0xffffffff);
                            pppppuVar31 = (undefined *****)*pppppuStack_440;
                            pppppuVar40 = pppppuStack_440;
                            if (pppppuVar31 != (undefined *****)0x0) {
                              do {
                                pppppuVar25 = pppppuVar31 + 1;
                                if (iVar13 <= (int)*(uint *)((long)pppppuVar31 + 0x1c)) {
                                  pppppuVar40 = pppppuVar31;
                                  pppppuVar25 = pppppuVar31;
                                }
                                pppppuVar31 = (undefined *****)*pppppuVar25;
                              } while (pppppuVar31 != (undefined *****)0x0);
                              if (pppppuVar40 != pppppuStack_440) {
                                pppppuVar31 = pppppuStack_440;
                                if ((int)*(uint *)((long)pppppuVar40 + 0x1c) <= iVar13) {
                                  pppppuVar31 = pppppuVar40;
                                }
                                if (pppppuStack_440 != pppppuVar31) {
                                  uVar12 = func_0x00a58934(1,uVar24 & 0xffffffff);
                                  unaff_x26 = (undefined *****)(ulong)uVar12;
                                  unaff_x27 = pppppuStack_440;
                                  while (unaff_x25 = unaff_x27,
                                        pppppuVar40 = (undefined *****)*unaff_x25,
                                        pppppuVar31 = unaff_x25,
                                        (undefined *****)*unaff_x25 != (undefined *****)0x0) {
                                    while (unaff_x27 = pppppuVar40,
                                          (int)*(uint *)((long)unaff_x27 + 0x1c) <= (int)uVar12) {
                                      if ((int)uVar12 <= (int)*(uint *)((long)unaff_x27 + 0x1c))
                                      goto LAB_006cb744;
                                      pppppuVar40 = (undefined *****)unaff_x27[1];
                                      if ((undefined *****)unaff_x27[1] == (undefined *****)0x0) {
                                        unaff_x25 = unaff_x27 + 1;
                                        pppppuVar31 = unaff_x27;
                                        goto LAB_006cb6e8;
                                      }
                                    }
                                  }
LAB_006cb6e8:
                                  unaff_x27 = (undefined *****)func_0x00bc3330(0x28);
                                  pppppuVar40 = pppppuStack_480;
                                  *(uint *)((long)unaff_x27 + 0x1c) = uVar12;
                                  *(uint *)(unaff_x27 + 4) = 0;
                                  *unaff_x27 = (undefined ****)0x0;
                                  unaff_x27[1] = (undefined ****)0x0;
                                  unaff_x27[2] = (undefined ****)pppppuVar31;
                                  *unaff_x25 = (undefined ****)unaff_x27;
                                  pppppuVar31 = unaff_x27;
                                  if ((undefined ****)**pppppuStack_480 != (undefined ****)0x0) {
                                    *pppppuStack_480 = (undefined ****)**pppppuStack_480;
                                    pppppuVar31 = (undefined *****)*unaff_x25;
                                  }
                                  func_0x0040a8c0(pppppuStack_480[1],pppppuVar31);
                                  pppppuVar40[2] = (undefined ****)((long)pppppuVar40[2] + 1);
LAB_006cb744:
                                  *(uint *)(unaff_x27 + 4) = *(uint *)(unaff_x27 + 4) + 1;
                                  goto joined_r0x006cb4c0;
                                }
                              }
                            }
                            uVar12 = func_0x00a58934(1,uVar24 & 0xffffffff);
                            unaff_x26 = (undefined *****)(ulong)uVar12;
                            unaff_x27 = pppppuStack_440;
                            while (unaff_x25 = unaff_x27, pppppuVar40 = (undefined *****)*unaff_x25,
                                  pppppuVar31 = unaff_x25,
                                  (undefined *****)*unaff_x25 != (undefined *****)0x0) {
                              while (unaff_x27 = pppppuVar40,
                                    (int)*(uint *)((long)unaff_x27 + 0x1c) <= (int)uVar12) {
                                if ((int)uVar12 <= (int)*(uint *)((long)unaff_x27 + 0x1c))
                                goto LAB_006cb7b4;
                                pppppuVar40 = (undefined *****)unaff_x27[1];
                                if ((undefined *****)unaff_x27[1] == (undefined *****)0x0) {
                                  unaff_x25 = unaff_x27 + 1;
                                  pppppuVar31 = unaff_x27;
                                  goto LAB_006cb564;
                                }
                              }
                            }
LAB_006cb564:
                            unaff_x27 = (undefined *****)func_0x00bc3330(0x28);
                            pppppuVar40 = pppppuStack_480;
                            *(uint *)((long)unaff_x27 + 0x1c) = uVar12;
                            *(uint *)(unaff_x27 + 4) = 0;
                            *unaff_x27 = (undefined ****)0x0;
                            unaff_x27[1] = (undefined ****)0x0;
                            unaff_x27[2] = (undefined ****)pppppuVar31;
                            *unaff_x25 = (undefined ****)unaff_x27;
                            pppppuVar31 = unaff_x27;
                            if ((undefined ****)**pppppuStack_480 != (undefined ****)0x0) {
                              *pppppuStack_480 = (undefined ****)**pppppuStack_480;
                              pppppuVar31 = (undefined *****)*unaff_x25;
                            }
                            func_0x0040a8c0(pppppuStack_480[1],pppppuVar31);
                            pppppuVar40[2] = (undefined ****)((long)pppppuVar40[2] + 1);
LAB_006cb7b4:
                            *(uint *)(unaff_x27 + 4) = 1;
                            if (uVar24 != 0) goto LAB_006cb3c8;
LAB_006cb918:
                            if (((ulong)pppppuStack_3c8 & 1) == 0) {
                              if (uVar24 != 0) goto LAB_006cb924;
                              goto LAB_006cb930;
                            }
                          }
                          else {
joined_r0x006cb4c0:
                            if (uVar24 == 0) goto LAB_006cb918;
LAB_006cb3c8:
                            iVar13 = func_0x00a603d4(lVar28,uVar24 & 0xffffffff);
                            if (iVar13 == 0) goto LAB_006cb918;
                            if (((((ulong)pppppuStack_3c8 & 1) != 0) ||
                                (uVar33 = func_0x005aacc8(), (uVar33 & 1) == 0)) ||
                               (uVar33 = func_0x005aad10(), uVar24 != (uVar33 & 0xffffffff))) {
                              iVar13 = func_0x00a5a194(lVar28,uVar24 & 0xffffffff);
                              iVar14 = func_0x00a5a300(lVar28,uVar24 & 0xffffffff);
                              unaff_x27 = pppppuStack_3c0 + uVar24 * 0x7d + lVar28 * 0x18e7;
                              uVar12 = *(uint *)((long)unaff_x27 + 0x8392c);
                              if ((int)uVar12 < 1) {
                                uVar15 = 0;
LAB_006cb5b8:
                                unaff_x26 = (undefined *****)0x0;
                              }
                              else {
                                uVar17 = 0;
                                do {
                                  uVar15 = uVar17;
                                  if ((float)(int)*(uint *)pppppuVar45 <=
                                      ((float)iVar13 / (float)iVar14) * (float)(int)uVar17) break;
                                  uVar17 = uVar17 + 1;
                                  uVar15 = uVar12;
                                } while (uVar12 != uVar17);
                                if ((int)uVar12 < 1) goto LAB_006cb5b8;
                                pppppuVar45 = (undefined *****)0x0;
                                do {
                                  unaff_x26 = pppppuVar45;
                                  if ((float)(int)uStack_40c <=
                                      ((float)iVar13 / (float)iVar14) * (float)(int)pppppuVar45)
                                  break;
                                  uVar17 = (int)pppppuVar45 + 1;
                                  pppppuVar45 = (undefined *****)(ulong)uVar17;
                                  unaff_x26 = (undefined *****)(ulong)uVar12;
                                } while (uVar12 != uVar17);
                              }
                              iVar13 = func_0x00a58ba4(lVar28,uVar24 & 0xffffffff);
                              if ((iVar13 != 4) &&
                                 (iVar13 = func_0x00a58ba4(lVar28,uVar24 & 0xffffffff),
                                 iVar13 != 0x15)) {
                                if (((uVar15 == (uint)unaff_x26) ||
                                    (uVar15 == *(uint *)((long)unaff_x27 + 0x8392c))) &&
                                   (*(uint *)((long)pppppuStack_3c0 +
                                             (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8f) * 4) != 1))
                                {
                                  iVar13 = func_0x00a6126c(lVar28,uVar24 & 0xffffffff);
                                  if ((0 < iVar13) &&
                                     (iVar13 = func_0x00a5a220(lVar28,uVar24 & 0xffffffff),
                                     0 < iVar13)) {
                                    func_0x00a58be4(lVar28,uVar24 & 0xffffffff,0x12);
                                    func_0x00a590fc(lVar28,uVar24 & 0xffffffff,0);
                                    uVar49 = func_0x0044c16c();
                                    func_0x0044e364(uVar49,0x49);
                                    goto LAB_006cb918;
                                  }
                                  uVar33 = func_0x00a59908(lVar28,uVar24 & 0xffffffff);
                                  if ((uVar33 & 1) == 0) {
                                    uVar33 = func_0x00a60788(lVar28,uVar24 & 0xffffffff);
                                    if ((uVar33 & 1) == 0) goto LAB_006cb908;
                                    uVar49 = 6;
                                  }
                                  else {
                                    uVar49 = 5;
                                  }
                                  func_0x00a58be4(lVar28,uVar24 & 0xffffffff,uVar49);
                                  func_0x00a590fc(lVar28,uVar24 & 0xffffffff,0);
                                }
                                else {
                                  func_0x00a58be4(lVar28,uVar24 & 0xffffffff,3);
                                  func_0x00a590fc(lVar28,uVar24 & 0xffffffff,0);
                                  uVar33 = func_0x00a62554(lVar28,uVar24 & 0xffffffff);
                                  if (((uVar33 & 1) != 0) &&
                                     (iVar13 = func_0x00a5a220(lVar28,uVar24 & 0xffffffff),
                                     iVar13 == 0)) {
                                    func_0x00a626a4(lVar28,uVar24 & 0xffffffff,1);
                                    lVar30 = 0x1e;
                                    unaff_x26 = pppppuStack_4e0;
                                    do {
                                      if (*(char *)unaff_x26 == '\0') {
                                        func_0x005aa690(unaff_x26);
                                        *(undefined1 *)unaff_x26 = 1;
                                        uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                          (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e45
                                                          ) * 4);
                                        iVar13 = func_0x0043ea60(0x2e);
                                        *(uint *)((long)unaff_x26 + 4) =
                                             uVar12 + iVar13 * -10 + 0xfa;
                                        uVar12 = *(uint *)(pppppuStack_3c0 +
                                                          uVar24 * 0x7d + lVar28 * 0x18e7 + 0x10723)
                                        ;
                                        iVar13 = func_0x0043ea60(0x1f);
                                        *(uint *)(unaff_x26 + 1) = (uVar12 + iVar13 * 10) - 0x96;
                                        uVar49 = func_0x0044c16c();
                                        func_0x0044e364(uVar49,0x3b);
                                        break;
                                      }
                                      lVar30 = lVar30 + -1;
                                      unaff_x26 = unaff_x26 + 2;
                                    } while (lVar30 != 0);
                                  }
                                  if (*(uint *)((long)pppppuStack_3c0 +
                                               (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e81) * 4) == 1
                                     ) {
                                    *(uint *)((long)pppppuStack_3c0 +
                                             (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e81) * 4) = 2;
                                  }
                                  if (*(uint *)((long)pppppuStack_3c0 +
                                               (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8f) * 4) == 1
                                     ) {
                                    *(uint *)((long)pppppuStack_3c0 +
                                             (lVar28 * 0x31ce + uVar24 * 0xfa + 0x20e8f) * 4) = 2;
                                  }
                                }
LAB_006cb908:
                                func_0x00a612ac(lVar28,uVar24 & 0xffffffff,0);
                              }
                              goto LAB_006cb918;
                            }
LAB_006cb924:
                            uVar33 = func_0x005aad10();
                            if (uVar24 == (uVar33 & 0xffffffff)) {
LAB_006cb930:
                              uVar12 = *(uint *)(pppppuStack_3c0 + 0x777bd);
                              if (CONCAT13(*(byte *)((long)pppppuStack_3c0 +
                                                    (long)(int)uVar12 * 0xbc + 0x383803) ^
                                           *(byte *)((long)pppppuStack_3c0 +
                                                    (long)(int)uVar12 * 0xbc + 0x383757),
                                           CONCAT12(*(byte *)((long)pppppuStack_3c0 +
                                                             (long)(int)uVar12 * 0xbc + 0x383802) ^
                                                    *(byte *)((long)pppppuStack_3c0 +
                                                             (long)(int)uVar12 * 0xbc + 0x383756),
                                                    CONCAT11(*(byte *)((long)pppppuStack_3c0 +
                                                                      (long)(int)uVar12 * 0xbc +
                                                                      0x383801) ^
                                                             *(byte *)((long)pppppuStack_3c0 +
                                                                      (long)(int)uVar12 * 0xbc +
                                                                      0x383755),
                                                             (byte)*(uint *)((long)pppppuStack_3c0 +
                                                                            ((long)(int)uVar12 *
                                                                             0x2f + 0xe0e00) * 4) ^
                                                             (byte)*(uint *)((long)pppppuStack_3c0 +
                                                                            ((long)(int)uVar12 *
                                                                             0x2f + 0xe0dd5) * 4))))
                                  - 1U < 99) {
                                iVar13 = func_0x00a5a194(1,uVar24 & 0xffffffff);
                                uVar12 = *(uint *)(pppppuStack_3c0 + 0x777bd);
                                iVar13 = (int)(((uint)(*(byte *)((long)pppppuStack_3c0 +
                                                                (long)(int)uVar12 * 0xbc + 0x383802)
                                                      ^ *(byte *)((long)pppppuStack_3c0 +
                                                                 (long)(int)uVar12 * 0xbc + 0x383756
                                                                 )) << 0x10 |
                                                (uint)(*(byte *)((long)pppppuStack_3c0 +
                                                                (long)(int)uVar12 * 0xbc + 0x383803)
                                                      ^ *(byte *)((long)pppppuStack_3c0 +
                                                                 (long)(int)uVar12 * 0xbc + 0x383757
                                                                 )) << 0x18 |
                                                (uint)(*(byte *)((long)pppppuStack_3c0 +
                                                                (long)(int)uVar12 * 0xbc + 0x383801)
                                                      ^ *(byte *)((long)pppppuStack_3c0 +
                                                                 (long)(int)uVar12 * 0xbc + 0x383755
                                                                 )) << 8 |
                                               (uint)(byte)((byte)*(uint *)((long)pppppuStack_3c0 +
                                                                           ((long)(int)uVar12 * 0x2f
                                                                           + 0xe0e00) * 4) ^
                                                           (byte)*(uint *)((long)pppppuStack_3c0 +
                                                                          ((long)(int)uVar12 * 0x2f
                                                                          + 0xe0dd5) * 4))) * iVar13
                                              ) / 100;
                                if ((iVar13 < (int)uStack_40c) &&
                                   (iVar14 = func_0x00a5a220(1,uVar24 & 0xffffffff),
                                   iVar14 <= iVar13)) {
                                  uVar12 = *(uint *)(pppppuStack_3c0 + 0x777bd);
                                  bVar11 = *(byte *)((long)pppppuStack_3c0 +
                                                    (long)(int)uVar12 * 0xbc + 0x38375a);
                                  bVar2 = *(byte *)((long)pppppuStack_3c0 +
                                                   (long)(int)uVar12 * 0xbc + 0x383802);
                                  bVar3 = *(byte *)((long)pppppuStack_3c0 +
                                                   (long)(int)uVar12 * 0xbc + 0x38375b);
                                  bVar4 = *(byte *)((long)pppppuStack_3c0 +
                                                   (long)(int)uVar12 * 0xbc + 0x383803);
                                  bVar5 = *(byte *)((long)pppppuStack_3c0 +
                                                   (long)(int)uVar12 * 0xbc + 0x383759);
                                  bVar6 = *(byte *)((long)pppppuStack_3c0 +
                                                   (long)(int)uVar12 * 0xbc + 0x383801);
                                  uVar15 = *(uint *)((long)pppppuStack_3c0 +
                                                    ((long)(int)uVar12 * 0x2f + 0xe0dd6) * 4);
                                  uVar12 = *(uint *)((long)pppppuStack_3c0 +
                                                    ((long)(int)uVar12 * 0x2f + 0xe0e00) * 4);
                                  *pppppuStack_4b0 = (undefined ****)0x1;
                                  *(uint *)(pppppuStack_4b0 + 1) = 0x2d;
                                  *(uint *)((long)pppppuStack_4b0 + 0xc) =
                                       (uint)(bVar2 ^ bVar11) << 0x10 |
                                       (uint)(bVar4 ^ bVar3) << 0x18 | (uint)(bVar6 ^ bVar5) << 8 |
                                       (uint)(byte)((byte)uVar12 ^ (byte)uVar15);
                                  *(uint *)(pppppuStack_4b0 + 2) = 1;
                                  uVar49 = func_0x0044c16c();
                                  func_0x0044e014(uVar49,0xffffffff);
                                }
                              }
                            }
                          }
                        }
                      }
LAB_006ca888:
                      pppppuVar35 = pppppuStack_3c0;
                      uVar24 = uVar24 + 1;
                    } while (uVar24 != 0x33);
                    uVar24 = 0;
                    do {
                      uVar12 = *(uint *)((long)&uStack_250 + uVar24 * 4);
                      puVar47 = (uint *)(ulong)uVar12;
                      if (uVar12 != 0) {
                        uVar15 = func_0x0057aa0c(lVar28,uVar24 & 0xffffffff);
                        unaff_x25 = (undefined *****)(ulong)uVar15;
                        uVar17 = func_0x005b21ec(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff);
                        unaff_x26 = (undefined *****)(ulong)uVar17;
                        if (*(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + uVar24 + 0x9fc) * 4) == 0
                           ) {
LAB_006cbb68:
                          uVar19 = func_0x005b21ec(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff);
                          func_0x005b235c(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff,uVar19);
                        }
                        else {
                          uVar18 = func_0x005b2314(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff);
                          unaff_x27 = (undefined *****)(ulong)uVar18;
                          iVar13 = func_0x005b21ec(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff);
                          if (iVar13 < (int)uVar18) goto LAB_006cbb68;
                        }
                        iVar13 = (int)((ulong)((long)(int)((uVar15 - uVar17) * uVar12) * -0x51eb851f
                                              ) >> 0x20);
                        iVar13 = func_0x0043ed6c(((iVar13 >> 5) - (iVar13 >> 0x1f)) +
                                                 (uVar15 - uVar17),0);
                        func_0x005b2234(pppppuVar42 + 0x4c9,uVar24 & 0xffffffff,uVar15 - iVar13,0);
                        abStack_3b0[0] = 0x2c;
                        uStack_399 = 0;
                        puStack_3f8[1] = 0x65677561675f6465;
                        *puStack_3f8 = 0x725f656c74746162;
                        *(undefined8 *)((long)puStack_3f8 + 0xe) = 0x656d6172665f6567;
                        uVar12 = func_0x008e3f14(pppppuVar35 + 0x28f,abStack_3b0,0xf);
                        *(uint *)((long)pppppuVar35 + (lVar28 * 0x7c + uVar24 + 0x9fc) * 4) = uVar12
                        ;
                        if ((abStack_3b0[0] & 1) != 0) {
                          func_0x00bc3350(CONCAT17(uStack_399,uStack_3a0));
                        }
                      }
                      uVar24 = uVar24 + 1;
                    } while (uVar24 != 10);
                    uVar19 = 0;
                    uVar49 = 1;
                    lVar28 = 1;
                  } while (((ulong)pppppuStack_3c8 & 1) != 0);
                  iVar14 = func_0x005ab154();
                  iVar13 = (uint)pppppuStack_3e8;
                  if (iVar14 == 0) {
                    if (*(uint *)((long)pppppuStack_498 + 0x14) == 0) {
                      *(uint *)((long)pppppuStack_500 + 0x3c) = 0;
                      *(uint *)(pppppuStack_500 + 8) = 0;
                      pppppuStack_4b0[1] = ppppuStack_548;
                      *pppppuStack_4b0 = ppppuStack_550;
                      uVar49 = func_0x00a5a220(0,0);
                      if ((int)uVar49 == 0) {
                        func_0x00a5a260(uVar49,0,1);
                      }
                      func_0x005c9224(pppppuVar35,0);
                    }
                    else {
                      if (*(uint *)(pppppuStack_468 + 10) != 0) goto LAB_006cbcac;
                      *(uint *)((long)pppppuStack_500 + 0x3c) = 0;
                      *(uint *)(pppppuStack_500 + 8) = 0;
                      pppppuStack_4b0[1] = ppppuStack_548;
                      *pppppuStack_4b0 = ppppuStack_550;
                      func_0x005cfa80(pppppuVar35);
                    }
                    func_0x005d0b20(pppppuVar35);
                  }
LAB_006cbcac:
                  iVar14 = func_0x005ab154();
                  pppppuVar45 = (undefined *****)0xa;
                  if (iVar14 == 0) {
                    if (iVar13 == 2) {
                      uVar49 = func_0x0044c16c();
                      iVar13 = 0x16;
LAB_006cbdb4:
                      func_0x0044e35c(uVar49,iVar13,0);
                    }
                    else if (iVar13 == 1) {
                      uVar49 = func_0x0044c16c();
                      iVar13 = func_0x0043ea60(2);
                      iVar13 = iVar13 + 0x14;
                      goto LAB_006cbdb4;
                    }
                    lVar28 = 0;
                    bVar10 = true;
                    do {
                      bVar7 = bVar10;
                      unaff_x26 = pppppuVar35 + 0x4c9;
                      uVar24 = 0;
                      pppppuVar42 = (undefined *****)(lVar28 * 0x1f0);
                      unaff_x27 = (undefined *****)((long)pppppuVar42 + 0x26b4);
                      do {
                        iVar13 = func_0x005b21ec(unaff_x26 + lVar28 * 0x3e,uVar24 & 0xffffffff);
                        if (iVar13 < 1) {
                          if (bVar7) goto LAB_006cbea4;
                        }
                        else {
                          uVar12 = func_0x0057aa0c(lVar28,uVar24 & 0xffffffff);
                          unaff_x25 = (undefined *****)(ulong)uVar12;
                          iVar13 = func_0x005b21ec(unaff_x26 + lVar28 * 0x3e,uVar24 & 0xffffffff);
                          if ((int)uVar12 < iVar13) {
                            uVar19 = func_0x0057aa0c(lVar28,uVar24 & 0xffffffff);
                            func_0x005b2234(unaff_x26 + lVar28 * 0x3e,uVar24 & 0xffffffff,uVar19,1);
                          }
                          else {
                            func_0x005b22a4(unaff_x26 + lVar28 * 0x3e,uVar24 & 0xffffffff,0xffffffff
                                           );
                          }
                          if (bVar7) {
                            iVar13 = func_0x005b21ec(unaff_x26 + lVar28 * 0x3e,uVar24 & 0xffffffff);
                            if (iVar13 == 0) {
                              uVar49 = func_0x0044c16c();
                              func_0x0044e35c(uVar49,0x1b,0);
                            }
LAB_006cbea4:
                            iVar13 = func_0x005abf1c(0,uVar24 & 0xffffffff);
                            if (((1 < iVar13) &&
                                (uVar33 = func_0x005b26a4(unaff_x26 + lVar28 * 0x3e,0,
                                                          uVar24 & 0xffffffff), (uVar33 & 1) != 0))
                               && (iVar13 = func_0x005b21ec(unaff_x26 + lVar28 * 0x3e,
                                                            uVar24 & 0xffffffff), iVar13 == 0)) {
                              lVar30 = (long)pppppuVar35 + (long)unaff_x27;
                              if (*(int *)(lVar30 + 0xec) <= *(int *)(lVar30 + 0x9c)) {
                                *(int *)(lVar30 + 0xec) = *(int *)(lVar30 + 0x9c) + 1;
                                uVar33 = func_0x005b23cc(unaff_x26 + lVar28 * 0x3e,0,
                                                         uVar24 & 0xffffffff);
                                if ((uVar33 & 1) != 0) {
                                  *(undefined4 *)((long)pppppuVar35 + (long)unaff_x27 + 0x114) = 0;
                                }
                              }
                            }
                          }
                        }
                        if (*(int *)((long)pppppuVar35 + (long)unaff_x27) == 1) {
                          iVar13 = *(int *)((long)pppppuVar35 + (long)unaff_x27 + 0x28);
                          if (0 < iVar13) {
                            *(int *)((long)pppppuVar35 + (long)unaff_x27 + 0x28) = iVar13 + -1;
                          }
                        }
                        iVar13 = *(int *)((long)pppppuVar35 + (long)unaff_x27 + 0x13c);
                        if (0 < iVar13) {
                          *(int *)((long)pppppuVar35 + (long)unaff_x27 + 0x13c) = iVar13 + -1;
                        }
                        uVar24 = uVar24 + 1;
                        unaff_x27 = (undefined *****)((long)unaff_x27 + 4);
                      } while (uVar24 != 10);
                      pppppuVar45 = (undefined *****)func_0x007fd748();
                      uVar19 = func_0x007ac230(0);
                      uVar24 = func_0x00633464(pppppuVar45 + 0xcd,uVar19,0);
                      if ((uVar24 & 1) == 0) {
                        uVar19 = func_0x005b2028(unaff_x26 + lVar28 * 0x3e);
                        func_0x005b1e64(unaff_x26 + lVar28 * 0x3e,uVar19);
                      }
                      uVar24 = func_0x005c14c8(pppppuVar35);
                      if ((((uVar24 & 1) != 0) &&
                          (uVar12 = *(uint *)(pppppuVar35 + lVar28 * 0x18e7 + 0x10727) - 1,
                          0 < (int)*(uint *)(pppppuVar35 + lVar28 * 0x18e7 + 0x10727))) &&
                         (*(uint *)(pppppuVar35 + lVar28 * 0x18e7 + 0x10727) = uVar12,
                         (bool)(bVar7 & uVar12 == 0))) {
                        uVar49 = func_0x0044c16c();
                        func_0x0044e35c(uVar49,0x1c,0);
                      }
                      lVar28 = 1;
                      bVar10 = false;
                    } while (bVar7);
                  }
                  unaff_x23 = (undefined *****)0x1;
                  if (0 < (int)*(uint *)(pppppuVar35 + 0x106dd)) {
                    *(uint *)(pppppuVar35 + 0x106dd) = *(uint *)(pppppuVar35 + 0x106dd) - 1;
                  }
                  lVar28 = 0x32;
                  puVar27 = puStack_528;
                  do {
                    if (0 < (int)*puVar27) {
                      *puVar27 = *puVar27 - 1;
                    }
                    if (0 < (int)puVar27[3]) {
                      puVar27[3] = puVar27[3] - 1;
                    }
                    lVar28 = lVar28 + -1;
                    puVar27 = puVar27 + 6;
                  } while (lVar28 != 0);
                  func_0x005bbf4c(pppppuVar35);
                  func_0x005bc3b4(pppppuVar35,lStack_408);
                  func_0x005bc54c(pppppuVar35,lStack_408);
                  func_0x005bc6bc(pppppuVar35,lStack_408);
                  func_0x005bc854(pppppuVar35,lStack_408);
                  func_0x005bc9ec(pppppuVar35,lStack_408);
                  func_0x005bcc2c(pppppuVar35,lStack_408);
                  func_0x005bce6c(pppppuVar35,lStack_408);
                  func_0x005bd09c(pppppuVar35,lStack_408);
                  func_0x005aa700(pppppuVar35 + 0x10e,lStack_408);
                  func_0x0063fdd4(apppppuStack_220 + 3,appppuStack_200[0]);
                  func_0x0063fdd4(apppppuStack_220,apppppuStack_220[1]);
                }
                iVar13 = iStack_4e4 + 1;
              } while (iVar13 < (int)*(uint *)(pppppuStack_4f8 + 0x1bc));
            }
            func_0x005b69a4(pppppuVar35);
            pppppuVar40 = pppppuStack_4b0;
            uVar15 = *(uint *)(pppppuStack_488 + 0x3b);
            uVar12 = uVar15 + 1;
            *(uint *)(pppppuStack_488 + 0x3c) = *(uint *)(pppppuStack_488 + 0x3c) + 1;
            *(uint *)(pppppuStack_488 + 0x3b) = uVar12;
            if (uVar12 == 3) {
              uVar12 = 1;
LAB_006cc038:
              *(uint *)(pppppuStack_4a8 + 0x32d) = uVar12;
            }
            else if (4 < (int)uVar15) {
              uVar12 = 0;
              *(uint *)(pppppuStack_488 + 0x3b) = 0;
              goto LAB_006cc038;
            }
            if (*(uint *)pppppuStack_4b0 == 0) {
LAB_006cc0a0:
              *pppppuVar40 = (undefined ****)0x0;
              *(uint *)(pppppuVar40 + 1) = 0;
              *(uint *)((long)pppppuVar40 + 0xc) = 0xffffffff;
              param_1 = pppppuStack_3c0;
            }
            else {
              param_1 = pppppuVar35;
              if ((*(uint *)pppppuStack_4b0 == 1) &&
                 (uVar12 = *(uint *)((long)pppppuStack_4b0 + 4) + 1,
                 *(uint *)((long)pppppuStack_4b0 + 4) = uVar12,
                 uVar12 == *(uint *)(pppppuStack_4b0 + 1))) {
                uVar49 = func_0x0044c16c();
                func_0x0044e014(uVar49,0xffffffff);
                if (*(uint *)((long)pppppuVar40 + 0xc) != 0xffffffff) {
                  func_0x005b1674(pppppuStack_3c0 + 0x8d742,0,1);
                }
                goto LAB_006cc0a0;
              }
            }
            *(float *)((long)pppppuStack_510 + 4) = *(float *)((long)pppppuStack_510 + 4) + 0.5;
            *(float *)((long)pppppuStack_510 + 0xc) = *(float *)((long)pppppuStack_510 + 0xc) + 0.5;
            goto LAB_006c7690;
          }
          if (pppppuVar25[1] != *pppppuVar25) {
            if ((uVar12 != 0 || (uVar15 & 1) != 0) ||
                *(int *)*pppppuVar25 <= (int)*(uint *)(pppppuStack_538 + 0x5ea)) goto LAB_006c7e70;
LAB_006c7e8c:
            if ((((ulong)unaff_x22[99] & 0xfffffffe) != 2) ||
               (uVar12 = *(uint *)((long)unaff_x22 + 0x314), uVar15 = uVar12 - 1,
               *(uint *)((long)unaff_x22 + 0x314) = uVar15, uVar15 == 0 || (int)uVar12 < 1)) {
              *(uint *)(unaff_x22 + 99) = 0;
            }
            goto LAB_006c7ebc;
          }
          if ((*(long *)(lStack_4a0 + 0x28) != lStack_98) ||
             (pppppuVar25 = (undefined *****)func_0x00470c38(),
             *(long *)(lStack_4a0 + 0x28) != lStack_98)) goto LAB_006cdcd8;
          func_0x00441cdc(auStack_348);
          pppppuVar42 = pppppuVar31;
LAB_006ccce4:
          if (*(char *)((long)param_1 + 0x32660c) == '\0') {
            func_0x009b9144(pppppuStack_3c0);
          }
          pppppuVar31 = pppppuStack_3c0;
          func_0x006df1f0(pppppuStack_3c0,0);
          uVar12 = *(uint *)pppppuVar40;
          uVar15 = *(uint *)((long)pppppuStack_500 + 0x14);
          if ((int)uVar12 < 0) {
            uVar12 = uVar12 + 1;
          }
          iVar14 = func_0x0043dc7c(pppppuVar31);
          iVar13 = *(int *)(&DAT_00c0b3ac + (long)(int)*(uint *)(pppppuVar42 + 0x14) * 4);
          if (iVar13 < 0) {
            iVar13 = iVar13 + 1;
          }
          fVar50 = (float)((int)(((int)uVar12 >> 1) - uVar15) / 10 + -0x41) +
                   (float)(iVar14 + -0x3c0) * 0.5;
          fVar53 = (float)(int)(-0x18 - (*(uint *)((long)pppppuStack_488 + 0x1cc) +
                                         *(uint *)((long)unaff_x25 + 0xd4) +
                                         *(uint *)(pppppuStack_488 + 5) + (iVar13 >> 1)));
          fVar56 = SUB84(pppppuVar31[0x685],0);
          fVar58 = (float)((ulong)pppppuVar31[0x685] >> 0x20);
          fVar57 = SUB84(pppppuVar31[0x684],0);
          fVar59 = (float)((ulong)pppppuVar31[0x684] >> 0x20);
          fVar51 = SUB84(pppppuVar31[0x686],0);
          fVar54 = fVar51 + fVar56 * fVar53 + fVar57 * fVar50;
          fVar52 = (float)((ulong)pppppuVar31[0x686] >> 0x20);
          fVar55 = fVar52 + fVar58 * fVar53 + fVar59 * fVar50;
          *(int *)pppppuVar42 = (int)fVar54;
          *(int *)((long)pppppuVar42 + 4) = (int)fVar55;
          pppppuVar42[1] =
               (undefined ****)
               CONCAT44((int)((fVar52 + fVar58 * (fVar53 + 131.0) + fVar59 * (fVar50 + 131.0)) -
                             fVar55),
                        (int)((fVar51 + fVar56 * (fVar53 + 131.0) + fVar57 * (fVar50 + 131.0)) -
                             fVar54));
          uVar24 = func_0x00805fcc(pppppuVar31);
          if ((uVar24 & 1) == 0) {
            uVar24 = func_0x00807844(pppppuStack_3c0);
            if ((uVar24 & 1) == 0) {
              uVar36 = 0;
              goto LAB_006cce28;
            }
          }
          else if ((*(char *)((long)pppppuStack_4f8 + 0x1c) != '\0') ||
                  (*(char *)(pppppuStack_4f8 + 4) != '\0')) {
            uVar36 = 1;
LAB_006cce28:
            *(undefined1 *)((long)pppppuStack_4f8 + 0x1d) = uVar36;
          }
          pppppuVar31 = pppppuStack_3c0;
        } while (*(uint *)pppppuStack_508 != 0);
        pppppuStack_3d8 = (undefined *****)((long)pppppuStack_3c0 + 0x32a48c);
        if (*(char *)((long)pppppuStack_4f8 + 0x1f) == '\0') {
          uVar24 = 0;
          pppppuStack_3e8 = pppppuStack_3c0 + 0xe6c;
          pppppuStack_3f0 = pppppuStack_3c0 + 0xe6e;
          do {
            uVar33 = func_0x00805fcc(pppppuStack_3c0);
            if ((((uVar33 & 1) != 0) &&
                (uVar33 = func_0x0098aef0(pppppuStack_3c0,
                                          *(uint *)((long)pppppuStack_3c0 +
                                                   (uVar24 * 4 + 0xc9f79) * 4),
                                          *(uint *)(pppppuStack_3c0 + uVar24 * 2 + 0x64fbd),
                                          *(uint *)((long)pppppuStack_3c0 +
                                                   (uVar24 * 4 + 0xc9f7b) * 4),
                                          *(uint *)(pppppuStack_3c0 + uVar24 * 2 + 0x64fbe)),
                (uVar33 & 1) != 0)) &&
               (uVar33 = func_0x005af168(uVar24 & 0xffffffff), (uVar33 & 1) != 0)) {
              if ((uVar24 != *(uint *)(param_1 + 0x64cc2)) ||
                 (*(char *)((long)param_1 + 0x32660c) == '\0')) {
                *(uint *)(param_1 + 0x64cc2) = (uint)uVar24;
                uVar49 = func_0x005ace18();
                func_0x006e437c(*(uint *)(param_1 + 0x64cc2));
                func_0x006e5ed0(apppppuStack_220);
                func_0x0044fe48(&uStack_250,uVar49,apppppuStack_220,&DAT_00c0bf30,0x1e,1,0,0);
                func_0x005ace98(pppppuStack_3e8 + (long)(int)*(uint *)(pppppuStack_3d8 + 0xe) * 2,
                                &uStack_250);
                func_0x0043f7ec(&uStack_250);
                if (((ulong)apppppuStack_220[0] & 1) != 0) {
                  func_0x00bc3350(apppppuStack_220[2]);
                }
                lVar28 = (long)(int)*(uint *)(pppppuStack_3d8 + 0xe);
                unaff_x26 = (undefined *****)(lVar28 + -1);
                pppppuStack_3c8 = (undefined *****)(lVar28 * 0x18);
                unaff_x25 = pppppuStack_3f0 + lVar28 * 2;
                do {
                  pppppuStack_3e0 = (undefined *****)func_0x005ace18();
                  func_0x006e437c(*(uint *)(param_1 + 0x64cc2));
                  func_0x006e5f48(apppppuStack_220);
                  func_0x0044fe48(&uStack_250,pppppuStack_3e0,
                                  (long)(apppppuStack_220[0] +
                                        (long)(int)*(uint *)(pppppuStack_3d8 + 0xe) * -3) +
                                  (long)pppppuStack_3c8,&DAT_00c0bf30,0x1e,1,0,0);
                  func_0x005ace98(unaff_x25,&uStack_250);
                  func_0x0043f7ec(&uStack_250);
                  func_0x0040f80c(apppppuStack_220);
                  unaff_x26 = (undefined *****)((long)unaff_x26 + 1);
                  unaff_x25 = unaff_x25 + 2;
                  pppppuStack_3c8 = pppppuStack_3c8 + 3;
                } while ((long)unaff_x26 < (long)(int)*(uint *)(pppppuStack_3d8 + 0xe) + 2);
                if ((*(uint *)(param_1 + 0x64cc2) == 0) &&
                   (*(char *)((long)pppppuStack_488 + 0x14b) == '\0')) {
                  func_0x009ea87c(pppppuStack_3c0 + 0x5eb,0);
                  func_0x0040cb78(&uStack_250,&UNK_0029b4e1);
                  func_0x0045e320(apppppuStack_220,&uStack_250);
                  func_0x009eaa70(pppppuStack_3c0 + 0x5eb,0,apppppuStack_220,0x1e,0x2c6);
                  if (((ulong)apppppuStack_220[0] & 1) != 0) {
                    func_0x00bc3350(apppppuStack_220[2]);
                  }
                  if ((uStack_250 & 1) != 0) {
                    func_0x00bc3350(uStack_240);
                  }
                }
              }
              *(undefined1 *)((long)param_1 + 0x32660c) = 1;
            }
            uVar24 = uVar24 + 1;
          } while (uVar24 != 6);
          if (*(char *)((long)param_1 + 0x32660c) != '\0') {
            *(uint *)((long)pppppuStack_3d8 + 0x74) = 5;
          }
        }
        pppppuVar31 = pppppuStack_3c0;
      } while ((*(uint *)pppppuStack_508 != 0) || (*(char *)((long)pppppuStack_4f8 + 0x1f) != '\0'))
      ;
      if (*(char *)(unaff_x22 + 10) == '\0') {
        uVar24 = func_0x005c14c8(pppppuStack_3c0);
        if ((((uVar24 & 1) == 0) || (uVar24 = func_0x00805fcc(pppppuStack_3c0), (uVar24 & 1) == 0))
           || (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)unaff_x23,
                                        *(uint *)((long)unaff_x23 + 4),*(uint *)(unaff_x23 + 1),
                                        *(uint *)((long)unaff_x23 + 0xc)), (uVar24 & 1) == 0)) {
          *(undefined1 *)pppppuStack_3d8 = 0;
        }
        else if (*(char *)pppppuStack_3d8 == '\0') {
          uVar49 = func_0x0044c16c();
          func_0x0044e35c(uVar49,10,0);
          *(undefined1 *)pppppuStack_3d8 = 1;
        }
        uVar24 = func_0x005c1960(pppppuStack_3c0);
        if ((((uVar24 & 1) == 0) || (uVar24 = func_0x00805fcc(pppppuStack_3c0), (uVar24 & 1) == 0))
           || (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(unaff_x23 + 2),
                                        *(uint *)((long)unaff_x23 + 0x14),*(uint *)(unaff_x23 + 3),
                                        *(uint *)((long)unaff_x23 + 0x1c)), (uVar24 & 1) == 0)) {
          *(undefined1 *)((long)pppppuStack_3d8 + 1) = 0;
        }
        else if (*(char *)((long)pppppuStack_3d8 + 1) == '\0') {
          uVar49 = func_0x0044c16c();
          func_0x0044e35c(uVar49,10,0);
          *(undefined1 *)((long)pppppuStack_3d8 + 1) = 1;
        }
      }
      uVar24 = func_0x00805fcc(pppppuStack_3c0);
      if (((uVar24 & 1) == 0) ||
         (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(unaff_x23 + 6),
                                   *(uint *)((long)unaff_x23 + 0x34),*(uint *)(unaff_x23 + 7),
                                   *(uint *)((long)unaff_x23 + 0x3c)), (uVar24 & 1) == 0)) {
        *(undefined1 *)((long)pppppuStack_3d8 + 3) = 0;
      }
      else if (*(char *)((long)pppppuStack_3d8 + 3) == '\0') {
        uVar49 = func_0x0044c16c();
        func_0x0044e35c(uVar49,10,0);
        *(undefined1 *)((long)pppppuStack_3d8 + 3) = 1;
      }
      uVar24 = func_0x005c14c8(pppppuStack_3c0);
      if (((((uVar24 & 1) != 0) && (uVar24 = func_0x00807844(pppppuStack_3c0), (uVar24 & 1) != 0))
          && (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)unaff_x23,
                                       *(uint *)((long)unaff_x23 + 4),*(uint *)(unaff_x23 + 1),
                                       *(uint *)((long)unaff_x23 + 0xc)),
             pppppuVar31 = pppppuStack_3c0, (uVar24 & 1) != 0)) &&
         (*(char *)((long)param_1 + 0x32660c) == '\0')) {
        func_0x005c8660(pppppuStack_3c0,1);
        goto LAB_006c7ae4;
      }
      uVar24 = func_0x005c1960(pppppuStack_3c0);
      if ((((uVar24 & 1) == 0) || (uVar24 = func_0x00807844(pppppuStack_3c0), (uVar24 & 1) == 0)) ||
         ((uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(unaff_x23 + 2),
                                    *(uint *)((long)unaff_x23 + 0x14),*(uint *)(unaff_x23 + 3),
                                    *(uint *)((long)unaff_x23 + 0x1c)), (uVar24 & 1) == 0 ||
          (*(char *)((long)param_1 + 0x32660c) != '\0')))) {
        uVar24 = func_0x00807844(pppppuStack_3c0);
        if (((((uVar24 & 1) != 0) &&
             (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(unaff_x23 + 6),
                                       *(uint *)((long)unaff_x23 + 0x34),*(uint *)(unaff_x23 + 7),
                                       *(uint *)((long)unaff_x23 + 0x3c)), (uVar24 & 1) != 0)) ||
            (uVar24 = func_0x00807850(pppppuStack_3c0), (uVar24 & 1) != 0)) &&
           (*(char *)((long)param_1 + 0x32660c) == '\0')) {
          uVar49 = func_0x0044c16c();
          func_0x0044e35c(uVar49,0xb,0);
          uVar12 = *(uint *)((long)unaff_x23 + 0x15c);
          *(undefined1 *)((long)param_1 + 0x32660c) = 0;
          *(uint *)((long)pppppuStack_3d8 + 0x74) = 0;
          *(uint *)((long)unaff_x23 + 0x15c) = uVar12 + 1;
          pppppuVar31 = pppppuStack_3c0;
          goto LAB_006c7ae4;
        }
        uVar24 = func_0x00807844(pppppuStack_3c0);
        if ((((uVar24 & 1) == 0) ||
            (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(pppppuStack_488 + 6),
                                      *(uint *)((long)pppppuStack_488 + 0x34),
                                      *(uint *)(pppppuStack_488 + 7),
                                      *(uint *)((long)pppppuStack_488 + 0x3c)), (uVar24 & 1) == 0))
           || (uVar24 = func_0x005af168(0), (uVar24 & 1) == 0)) {
          uVar24 = func_0x00807844(pppppuStack_3c0);
          if ((((uVar24 & 1) == 0) ||
              (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(pppppuStack_488 + 0xc),
                                        *(uint *)((long)pppppuStack_488 + 100),
                                        *(uint *)(pppppuStack_488 + 0xd),
                                        *(uint *)((long)pppppuStack_488 + 0x6c)), (uVar24 & 1) == 0)
              ) || (uVar24 = func_0x005af0d8(3), (uVar24 & 1) == 0)) {
            uVar24 = func_0x00807844(pppppuStack_3c0);
            if ((((uVar24 & 1) == 0) ||
                (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)(pppppuStack_488 + 0x10),
                                          *(uint *)((long)pppppuStack_488 + 0x84),
                                          *(uint *)(pppppuStack_488 + 0x11),
                                          *(uint *)((long)pppppuStack_488 + 0x8c)),
                (uVar24 & 1) == 0)) || (uVar24 = func_0x005af0d8(5), (uVar24 & 1) == 0)) {
              uVar24 = func_0x00807844(pppppuStack_3c0);
              if ((((((uVar24 & 1) != 0) &&
                    (uVar24 = func_0x0098aef0(pppppuStack_3c0,*(uint *)pppppuVar42,
                                              *(uint *)((long)pppppuVar42 + 4),
                                              *(uint *)(pppppuVar42 + 1),
                                              *(uint *)((long)pppppuVar42 + 0xc)), (uVar24 & 1) != 0
                    )) && (*(char *)((long)param_1 + 0x32660c) == '\0')) &&
                  (((*(uint *)unaff_x27 != 0x30 && (*(uint *)(pppppuStack_488 + 0x2b) != 3)) &&
                   ((*(uint *)(pppppuStack_488 + 0x2b) != 99 &&
                    ((*(char *)(pppppuVar42 + 0x1fe) == '\0' &&
                     (*(char *)((long)pppppuVar42 + 0xffe) == '\0')))))))) &&
                 ((*(char *)((long)pppppuVar42 + 0xfff) == '\0' &&
                  ((iVar13 = func_0x007abd78(0), iVar13 != -7 ||
                   (iVar13 = func_0x007ac380(), iVar13 != 0x2f)))))) {
                pppppuVar31 = pppppuStack_3c0;
                if (0 < (int)*(uint *)((long)pppppuStack_3d0 + 0x1c)) {
                  *(undefined1 *)((long)param_1 + 0x32660c) = 0;
                  *(uint *)((long)pppppuStack_3d8 + 0x74) = 0;
                  uVar49 = func_0x0044c16c();
                  func_0x0044e35c(uVar49,0xb,0);
                  *(uint *)(pppppuVar42 + 0x14) = *(uint *)(pppppuVar42 + 0x14) + 1;
LAB_006c7adc:
                  func_0x005c5990(pppppuVar31);
                }
                goto LAB_006c7ae4;
              }
              pppppuVar31 = pppppuStack_3c0;
              if ((((*(char *)((long)pppppuStack_4f8 + 0x1c) != '\0') ||
                   (*(uint *)pppppuStack_508 != 0)) ||
                  (*(char *)((long)pppppuStack_4f8 + 0x1d) != '\0')) ||
                 (*(char *)((long)pppppuStack_4f8 + 0x1e) != '\0')) goto LAB_006c7ae4;
              uVar12 = 0;
              if (*(uint *)pppppuStack_4f8 != 0) {
                if (*(uint *)pppppuStack_4f8 != 1) goto LAB_006cd4d0;
                uVar12 = 5;
              }
              *(uint *)pppppuStack_488 = uVar12;
LAB_006cd4d0:
              unaff_x25 = (undefined *****)0x0;
              bVar10 = *(char *)((long)param_1 + 0x13dd) == '\0';
              pppppuStack_3c8 = pppppuStack_3c0 + 0x65492;
              do {
                unaff_x26 = (undefined *****)0x0;
                if ((unaff_x25 < (undefined *****)0x5) && (!bVar10)) {
                  func_0x0040cb78(abStack_300,&UNK_0028fc2d);
                  iVar13 = func_0x008e3f14(pppppuStack_3c0 + 0x28f,abStack_300,0x5a);
                  unaff_x26 = (undefined *****)(ulong)(uint)-iVar13;
                  if ((abStack_300[0] & 1) != 0) {
                    func_0x00bc3350(uStack_2f0);
                  }
                }
                uVar12 = *(uint *)pppppuStack_488;
                if (*(char *)((long)param_1 + 0x13dd) != '\0') {
                  uVar12 = 0;
                }
                uVar24 = (long)unaff_x25 + (ulong)uVar12;
                uVar33 = func_0x00805fcc(pppppuStack_3c0);
                pppppuVar31 = pppppuStack_3c0;
                uVar12 = (uint)uVar24;
                if ((uVar33 & 1) == 0) {
LAB_006cd634:
                  *(undefined1 *)((long)pppppuStack_3c8 + (long)unaff_x25) = 0;
                }
                else {
                  iVar13 = *(int *)(&DAT_00c0aea8 + (long)(int)uVar12 * 4);
                  iVar14 = func_0x0043dc7c(pppppuStack_3c0);
                  uVar33 = 0x6e;
                  pppppuVar35 = (undefined *****)0x58;
                  pppppuVar25 = (undefined *****)
                                (ulong)(((int)unaff_x26 + *(uint *)((long)pppppuStack_488 + 0x1cc) +
                                        *(uint *)pppppuVar45) - 1);
                  uVar29 = func_0x0098aef0(pppppuVar31,
                                           (int)((double)iVar13 + (double)(iVar14 + -0x3c0) * 0.5),
                                           pppppuVar25,0x6e,0x58);
                  if ((uVar29 & 1) == 0) goto LAB_006cd634;
                  if (*(char *)((long)pppppuStack_3c8 + (long)unaff_x25) == '\0') {
                    uVar49 = func_0x0044c16c();
                    func_0x0044e35c(uVar49,10,0);
                    *(undefined1 *)((long)pppppuStack_3c8 + (long)unaff_x25) = 1;
                    iVar13 = func_0x005abf04(0,uVar24 & 0xffffffff);
                    uVar19 = func_0x005abf1c(0,uVar24 & 0xffffffff);
                    pppppuStack_3e0 = (undefined *****)CONCAT44(pppppuStack_3e0._4_4_,uVar19);
                    pppppuStack_3d0 = (undefined *****)CONCAT44(pppppuStack_3d0._4_4_,iVar13);
                    if ((-1 < iVar13) && (uVar12 != *(uint *)((long)pppppuStack_3c0 + 0x13d4))) {
                      *(uint *)((long)pppppuStack_3c0 + 0x13d4) = uVar12;
                      uVar49 = func_0x005ace18();
                      func_0x0062d830(apppppuStack_220,(ulong)pppppuStack_3d0 & 0xffffffff,
                                      (ulong)pppppuStack_3e0 & 0xffffffff);
                      func_0x0044fe48(&uStack_250,uVar49,apppppuStack_220,&DAT_00c0bf30,0x1e,1,0,0);
                      func_0x005ace98(lStack_408 + 0x16008,&uStack_250);
                      func_0x0043f7ec(&uStack_250);
                      if (((ulong)apppppuStack_220[0] & 1) != 0) {
                        func_0x00bc3350(apppppuStack_220[2]);
                      }
                      lVar28 = lStack_408;
                      func_0x00606b54(lStack_408 + 0x16018);
                      func_0x00606b54(lVar28 + 0x16028);
                      func_0x00606b54(lVar28 + 0x16038);
                      func_0x00a51138(pppppuStack_3c0,lVar28 + 0x16018,
                                      (ulong)pppppuStack_3d0 & 0xffffffff,0);
                    }
                  }
                  else if (uVar12 == *(uint *)((long)pppppuStack_3c0 + 0x13d4)) {
                    *(uint *)(pppppuStack_3c0 + 0x27a) = *(uint *)(pppppuStack_3c0 + 0x27a) + 1;
                    uVar49 = 0x6cd618;
                    ppppuVar37 = (undefined ****)&ppppuStack_550;
                    pppppuVar32 = pppppuStack_3c0;
                    goto SUB_006cdfa4;
                  }
                }
                uVar33 = func_0x00807844(pppppuStack_3c0);
                pppppuVar31 = pppppuStack_3c0;
                if ((uVar33 & 1) != 0) {
                  iVar13 = *(int *)(&DAT_00c0aea8 + (long)(int)uVar12 * 4);
                  iVar14 = func_0x0043dc7c(pppppuStack_3c0);
                  uVar33 = 0x6e;
                  pppppuVar35 = (undefined *****)0x58;
                  pppppuVar25 = (undefined *****)
                                (ulong)(((int)unaff_x26 + *(uint *)((long)pppppuStack_488 + 0x1cc) +
                                        *(uint *)pppppuVar45) - 1);
                  uVar29 = func_0x0098aef0(pppppuVar31,
                                           (int)((double)iVar13 + (double)(iVar14 + -0x3c0) * 0.5),
                                           pppppuVar25,0x6e,0x58);
                  if (((uVar29 & 1) != 0) && (*(char *)((long)param_1 + 0x32660c) == '\0')) {
                    uVar49 = 0x6cd6b0;
                    pppppuVar32 = pppppuStack_3c0;
                    goto SUB_006cdfa4;
                  }
                }
                unaff_x25 = (undefined *****)((long)unaff_x25 + 1);
                bVar10 = *(char *)((long)param_1 + 0x13dd) == '\0';
                pppppuVar25 = (undefined *****)0xa;
                if (bVar10) {
                  pppppuVar25 = (undefined *****)0x5;
                }
                pppppuVar31 = pppppuStack_3c0;
              } while (unaff_x25 < pppppuVar25);
              goto LAB_006c7ae4;
            }
            *(uint *)((long)pppppuStack_488 + 0xf4) = *(uint *)((long)pppppuStack_488 + 0xf4) + 1;
          }
          else {
            *(uint *)((long)pppppuStack_488 + 0xec) = *(uint *)((long)pppppuStack_488 + 0xec) + 1;
          }
        }
        else {
          *(uint *)(pppppuStack_488 + 0x1c) = *(uint *)(pppppuStack_488 + 0x1c) + 1;
        }
        uVar49 = func_0x0044c16c();
        uVar34 = 0xb;
      }
      else {
        pppppuVar45 = (undefined *****)0x2648;
        *(undefined1 *)((long)param_1 + 0x32660c) = 0;
        *(uint *)((long)pppppuStack_3d8 + 0x74) = 0;
        iVar13 = func_0x005b1f30(pppppuStack_3c0 + 0x4c9);
        pppppuVar31 = pppppuStack_3c0;
        if (iVar13 != 7) {
          iVar13 = func_0x005b1bf4(pppppuStack_3c0 + 0x4c9);
          iVar14 = func_0x005b1f74(pppppuVar31 + 0x4c9);
          pppppuVar31 = pppppuStack_3c0;
          if (iVar14 <= iVar13) {
            *(uint *)((long)unaff_x22 + 0x54) = 0;
            iVar13 = func_0x005b1f74(pppppuStack_3c0 + 0x4c9);
            func_0x005b1e64(pppppuVar31 + 0x4c9,-iVar13);
            func_0x005b217c(pppppuVar31 + 0x4c9,1);
            *(uint *)((long)pppppuStack_500 + 100) = 0xe;
            uVar49 = func_0x0044c16c();
            func_0x0044e35c(uVar49,0x13,0);
            goto LAB_006c7ae4;
          }
        }
        uVar49 = func_0x0044c16c();
        uVar34 = 0xf;
      }
      func_0x0044e35c(uVar49,uVar34,0);
      pppppuVar31 = pppppuStack_3c0;
      goto LAB_006c7ae4;
    }
    *(uint *)(param_1 + 0x656e1) = uVar12 + 1;
    if ((((uVar12 < 5) || (*(uint *)(param_1 + 0x656e1) = 0, *(uint *)unaff_x27 == 0x30)) ||
        (*(uint *)(pppppuStack_488 + 0x2b) == 3)) || (*(uint *)(pppppuStack_488 + 0x2b) == 99))
    goto LAB_006c7ae4;
    (*(code *)(*pppppuStack_3c0)[7])(pppppuStack_3c0);
    *(undefined1 *)(param_1 + 0x656a4) = 1;
    func_0x005b1674(pppppuVar31 + 0x8d742,1,1);
    if (1 < *(uint *)(pppppuStack_3c8 + 3) - 1) goto LAB_006c7a20;
    pppppuVar25 = (undefined *****)0x0;
    *(uint *)(pppppuStack_3c8 + 3) = 0;
  }
  else {
    pppppuVar40 = (undefined *****)0x0;
    pppppuVar42 = (undefined *****)&UNK_0028fc2d;
    unaff_x23 = (undefined *****)0xa;
    unaff_x25 = (undefined *****)0x5;
    uStack_3b8 = 0x17;
    pppppuStack_3c0 = (undefined *****)0x21;
    unaff_x22 = (undefined *****)&DAT_00c0aea8;
    do {
      iVar13 = func_0x005abf04(0,(ulong)pppppuVar40 & 0xffffffff);
      if (iVar13 < 0) break;
      if (pppppuVar40 < (undefined *****)0x5) {
        puStack_290 = (undefined8 *)func_0x00bc3330(0x20);
        *(undefined1 *)((long)puStack_290 + 0x17) = 0;
        uStack_298 = uStack_3b8;
        pppppuStack_2a0 = pppppuStack_3c0;
        puStack_290[1] = 0x6e696c325f746f6c;
        *puStack_290 = 0x735f656c74746162;
        *(undefined8 *)((long)puStack_290 + 0xf) = 0x656e696c5f73656e;
        iVar13 = func_0x008e3f14(param_1 + 0x28f,&pppppuStack_2a0,0x5a);
        unaff_x26 = (undefined *****)(ulong)(uint)-iVar13;
        if (((ulong)pppppuStack_2a0 & 1) != 0) {
          func_0x00bc3350(puStack_290);
        }
      }
      else {
        unaff_x26 = (undefined *****)0x0;
      }
      uVar24 = func_0x00805fcc(param_1);
      if ((uVar24 & 1) != 0) {
        iVar13 = *(int *)(&DAT_00c0aea8 + (long)pppppuVar40 * 4);
        iVar14 = func_0x0043dc7c(param_1);
        uVar24 = func_0x0098aef0(param_1,(int)((double)iVar13 + (double)(iVar14 + -0x3c0) * 0.5),
                                 (int)unaff_x26 + *(uint *)((long)pppppuStack_488 + 0x1cc) +
                                 _DAT_00c0aed0 + -1,0x6e,0x58);
        if (((uVar24 & 1) != 0) &&
           (pppppuVar40 != (undefined *****)(ulong)*(uint *)((long)param_1 + 0x914))) {
          uVar33 = (ulong)pppppuVar40 & 0xffffffff;
          *(uint *)((long)param_1 + 0x914) = (uint)pppppuVar40;
          uVar49 = 0x6c75fc;
          pppppuVar32 = param_1;
          pppppuVar31 = pppppuVar42;
          goto SUB_006cdcdc;
        }
      }
      pppppuVar40 = (undefined *****)((long)pppppuVar40 + 1);
      pppppuVar31 = (undefined *****)0x5;
      if (*(char *)((long)param_1 + 0x13dd) != '\0') {
        pppppuVar31 = (undefined *****)0xa;
      }
    } while (pppppuVar40 < pppppuVar31);
LAB_006c7690:
    pppppuVar40 = pppppuStack_4a8;
    *(uint *)((long)pppppuStack_4a8 + 0x1f84) = *(uint *)((long)pppppuStack_4a8 + 0x1f84) + 1;
    iVar13 = func_0x005ab154();
    if (iVar13 == 0) {
      func_0x005b1608(param_1 + 0x8d742);
    }
    uVar24 = func_0x00685844(param_1,*(uint *)(pppppuVar40 + 1));
    pppppuVar31 = param_1;
    if ((uVar24 & 1) == 0) {
LAB_006c7a20:
      pppppuVar25 = (undefined *****)0x0;
    }
    else {
      pppppuVar25 = (undefined *****)0x1;
      uVar12 = 0;
      if (1 < (int)*(uint *)(pppppuVar40 + 0x7db)) {
        uVar12 = *(uint *)(pppppuVar40 + 0x7db) - 1;
      }
      *(uint *)(pppppuVar40 + 0x7db) = uVar12;
    }
  }
LAB_006c7a24:
  pppppuVar32 = pppppuVar31;
  pppppuVar31 = pppppuVar42;
  if (*(long *)(lStack_4a0 + 0x28) == lStack_98) {
    return pppppuVar25;
  }
LAB_006cdcd8:
  uVar49 = 0x6cdcdc;
  auVar60 = func_0x00bc3380(pppppuVar25);
  uVar33 = auVar60._8_8_;
  param_1 = auVar60._0_8_;
SUB_006cdcdc:
  uVar24 = tpidr_el0;
  lStack_598 = *(long *)(uVar24 + 0x28);
  pppppppuStack_590 = pppppppuVar48;
  uStack_588 = uVar49;
  pppppuStack_580 = pppppuVar45;
  pppppuStack_578 = unaff_x23;
  pppppuStack_570 = unaff_x22;
  pppppuStack_568 = pppppuVar31;
  pppppuStack_560 = pppppuVar40;
  pppppuStack_558 = pppppuVar32;
  if (lRam0000000000c0b8b8 == 0) {
    lVar28 = 0;
  }
  else {
    lVar28 = func_0x00bc3a90(lRam0000000000c0b8b8,
                             &PTR__ZTVN10__cxxabiv117__class_type_infoE_16__00bd1178,
                             &PTR__ZTVN10__cxxabiv120__si_class_type_infoE_16__00bdc208,0);
  }
  uVar29 = func_0x005abf04(0,uVar33 & 0xffffffff);
  pppppuVar40 = (undefined *****)(uVar29 & 0xffffffff);
  uVar19 = func_0x005abf1c(0,uVar33 & 0xffffffff);
  if (((bRam0000000000c0be90 & 1) == 0) && (iVar13 = func_0x00bc32f0(0xc0be90,uVar19), iVar13 != 0))
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
  func_0x0062d830(abStack_610 + 0x48,pppppuVar40,uVar19);
  pppppuVar35 = (undefined *****)0x1;
  func_0x0044fe48(&uStack_5b0,0xc0be58,abStack_610 + 0x48,&DAT_00c0bf30,0x1e,1,0,0);
  plVar43 = plStack_5a8;
  uVar49 = uStack_5b0;
  uStack_5b0 = 0;
  plStack_5a8 = (long *)0x0;
  pppppuVar45 = (undefined *****)(lVar28 + 0x16000);
  plVar41 = *(long **)(lVar28 + 0x16010);
  *(long **)(lVar28 + 0x16010) = plVar43;
  *(undefined8 *)(lVar28 + 0x16008) = uVar49;
  if ((plVar41 != (long *)0x0) &&
     (lVar30 = func_0x00bbf1b0(0xffffffffffffffff,plVar41 + 1), lVar30 == 0)) {
    (**(code **)(*plVar41 + 0x10))(plVar41);
    func_0x00bc3320(plVar41);
  }
  plVar43 = plStack_5a8;
  if ((plStack_5a8 != (long *)0x0) &&
     (lVar30 = func_0x00bbf1b0(0xffffffffffffffff,plStack_5a8 + 1), lVar30 == 0)) {
    (**(code **)(*plVar43 + 0x10))(plVar43);
    func_0x00bc3320(plVar43);
  }
  if ((abStack_610[0x48] & 1) != 0) {
    func_0x00bc3350(uStack_5b8);
  }
  pppppuVar42 = (undefined *****)(lVar28 + 0x16018);
  *pppppuVar42 = (undefined ****)0x0;
  plVar43 = *(long **)(lVar28 + 0x16020);
  *(undefined8 *)(lVar28 + 0x16020) = 0;
  if ((plVar43 != (long *)0x0) &&
     (lVar30 = func_0x00bbf1b0(0xffffffffffffffff,plVar43 + 1), lVar30 == 0)) {
    (**(code **)(*plVar43 + 0x10))(plVar43);
    func_0x00bc3320(plVar43);
  }
  plVar43 = *(long **)(lVar28 + 0x16030);
  *(undefined8 *)(lVar28 + 0x16028) = 0;
  *(undefined8 *)(lVar28 + 0x16030) = 0;
  if ((plVar43 != (long *)0x0) &&
     (lVar30 = func_0x00bbf1b0(0xffffffffffffffff,plVar43 + 1), lVar30 == 0)) {
    (**(code **)(*plVar43 + 0x10))(plVar43);
    func_0x00bc3320(plVar43);
  }
  unaff_x22 = *(undefined ******)(lVar28 + 0x16040);
  *(undefined8 *)(lVar28 + 0x16038) = 0;
  *(undefined8 *)(lVar28 + 0x16040) = 0;
  if ((unaff_x22 != (undefined *****)0x0) &&
     (lVar28 = func_0x00bbf1b0(0xffffffffffffffff,unaff_x22 + 1), lVar28 == 0)) {
    (*(code *)(*unaff_x22)[2])(unaff_x22);
    func_0x00bc3320(unaff_x22);
  }
  uVar33 = 0;
  pppppuVar25 = pppppuVar40;
  pppppuVar31 = (undefined *****)func_0x00a51138(param_1,pppppuVar42);
  if (*(long *)(uVar24 + 0x28) == lStack_598) {
    return pppppuVar31;
  }
  uVar49 = 0x6cdfa4;
  pppppuVar32 = (undefined *****)func_0x00bc3380();
  ppppuVar37 = (undefined ****)(abStack_610 + 0x40);
  pppppuVar31 = param_1;
  pppppppuVar48 = &pppppppuStack_590;
SUB_006cdfa4:
  *(undefined8 ********)((long)ppppuVar37 + -0x20) = pppppppuVar48;
  *(undefined8 *)((long)ppppuVar37 + -0x18) = uVar49;
  *(undefined ******)((long)ppppuVar37 + -0x10) = pppppuVar40;
  *(undefined ******)((long)ppppuVar37 + -8) = pppppuVar31;
  pppppppuVar48 = (undefined8 *******)((long)ppppuVar37 + -0x20);
  pppppuVar40 = (undefined *****)tpidr_el0;
  *(undefined *****)((long)ppppuVar37 + -0x28) = pppppuVar40[5];
  if (*(uint *)((long)pppppuVar32 + 0x13d4) == 0xffffffff) {
    pppppuVar32 = (undefined *****)0x0;
  }
  else {
    uVar12 = *(uint *)(pppppuVar32 + 0x27a);
    *(undefined1 *)((long)ppppuVar37 + -0x40) = 0x2a;
    *(undefined8 *)((long)ppppuVar37 + -0x37) = 0x637365645f746f6c;
    *(undefined8 *)((long)ppppuVar37 + -0x3f) = 0x735f656c74746162;
    *(undefined8 *)((long)ppppuVar37 + -0x32) = 0x746961775f637365;
    *(undefined1 *)((long)ppppuVar37 + -0x2a) = 0;
    pppppuVar25 = (undefined *****)0x6;
    iVar13 = func_0x008e3f14(pppppuVar32 + 0x28f,(undefined1 *)((long)ppppuVar37 + -0x40));
    pppppuVar32 = (undefined *****)(ulong)(iVar13 <= (int)uVar12);
    pppppuVar31 = (undefined *****)(ulong)uVar12;
    if ((*(byte *)((long)ppppuVar37 + -0x40) & 1) != 0) {
      func_0x00bc3350(*(undefined8 *)((long)ppppuVar37 + -0x30));
      pppppuVar31 = pppppuVar32;
    }
  }
  if (pppppuVar40[5] == *(undefined *****)((long)ppppuVar37 + -0x28)) {
    return pppppuVar32;
  }
  uVar49 = 0x6ce084;
  auVar60 = func_0x00bc3380(pppppuVar32);
  ppppuVar9 = (undefined ****)((long)ppppuVar37 + -0x40);
SUB_006ce084:
  pppppuVar32 = auVar60._0_8_;
  *(undefined8 ********)((long)ppppuVar9 + -0x60) = pppppppuVar48;
  *(undefined8 *)((long)ppppuVar9 + -0x58) = uVar49;
  *(uint **)((long)ppppuVar9 + -0x50) = puVar47;
  *(undefined ******)((long)ppppuVar9 + -0x48) = unaff_x27;
  *(undefined ******)((long)ppppuVar9 + -0x40) = unaff_x26;
  *(undefined ******)((long)ppppuVar9 + -0x38) = unaff_x25;
  *(undefined ******)((long)ppppuVar9 + -0x30) = pppppuVar45;
  *(ulong *)((long)ppppuVar9 + -0x28) = uVar24;
  *(undefined ******)((long)ppppuVar9 + -0x20) = unaff_x22;
  *(undefined ******)((long)ppppuVar9 + -0x18) = pppppuVar42;
  *(undefined ******)((long)ppppuVar9 + -0x10) = pppppuVar40;
  *(undefined ******)((long)ppppuVar9 + -8) = pppppuVar31;
  iVar13 = auVar60._8_4_;
  bVar10 = iVar13 == 0;
  uVar46 = (ulong)pppppuVar35 & 0xffffffff;
  uVar24 = uVar33 & 0xffffffff;
  uVar44 = (ulong)pppppuVar25 & 0xffffffff;
  uVar29 = auVar60._8_8_ & 0xffffffff;
  iVar14 = (int)uVar33;
  pppppuVar42 = pppppuVar32;
  if ((iVar14 == 0 && iVar13 == 0) &&
     (pppppuVar42 = (undefined *****)func_0x005aacc8(), ((ulong)pppppuVar42 & 1) != 0)) {
    iVar20 = func_0x00a5a220(1,0);
    pppppuVar42 = (undefined *****)0x0;
    if (0 < iVar20) {
      return (undefined *****)0x0;
    }
  }
  iVar20 = (int)pppppuVar25;
  if (((iVar14 == 0) || ((iVar13 == 0 && (iVar21 = func_0x005aad10(pppppuVar42), iVar21 == iVar14)))
      ) && ((iVar21 = func_0x00a58ba4(uVar29,uVar44), iVar21 != 2 &&
            (uVar33 = func_0x00a5c8d4(uVar29,uVar44,0), (uVar33 & 1) != 0)))) {
    if (iVar13 != 0) {
      iVar13 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x24013) * 4);
      iVar20 = func_0x00a5ca20(uVar29,uVar44,0);
      uVar24 = func_0x00a58df4(0,uVar24,uVar44);
      if ((uVar24 & 1) == 0) {
        return (undefined *****)0x0;
      }
      if (*(int *)((long)pppppuVar32 + ((long)iVar14 * 0xfa + 0x20e45) * 4) <= iVar20 + iVar13) {
        return (undefined *****)0x1;
      }
      return (undefined *****)0x0;
    }
    iVar13 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e45) * 4);
    iVar20 = func_0x00a5ca20(0,(ulong)pppppuVar25 & 0xffffffff,0);
    uVar24 = func_0x00a58df4(1,uVar24,uVar44);
    if ((uVar24 & 1) == 0) {
      return (undefined *****)0x0;
    }
    if (*(int *)((long)pppppuVar32 + ((long)iVar14 * 0xfa + 0x24013) * 4) < iVar13 - iVar20) {
      return (undefined *****)0x0;
    }
    return (undefined *****)0x1;
  }
  iVar21 = func_0x00a58ba4(uVar29,uVar44);
  if ((iVar21 != 2) || (uVar33 = func_0x00a5c8d4(uVar29,uVar44,uVar46), (uVar33 & 1) == 0)) {
    if (iVar13 == 0) {
      iVar21 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e45) * 4);
      iVar23 = iVar21 - *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e4f) * 4);
    }
    else {
      iVar23 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x24013) * 4);
      iVar21 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x2401d) * 4) + iVar23;
    }
    iVar20 = func_0x00a58874(bVar10,uVar24);
    if (iVar20 == 0) {
      return (undefined *****)0x0;
    }
    uVar24 = func_0x00a58df4(bVar10,uVar24,uVar44);
    if ((uVar24 & 1) == 0) {
      return (undefined *****)0x0;
    }
    if (iVar13 == 0) {
      iVar13 = *(int *)((long)pppppuVar32 + ((long)iVar14 * 0xfa + 0x24013) * 4);
      uVar49 = CONCAT44(iVar13 - (int)((ulong)pppppuVar32[(long)iVar14 * 0x7d + 0x1200f] >> 0x20),
                        iVar13 - (int)pppppuVar32[(long)iVar14 * 0x7d + 0x1200f]);
    }
    else {
      iVar13 = *(int *)((long)pppppuVar32 + ((long)iVar14 * 0xfa + 0x20e45) * 4);
      uVar49 = NEON_rev64(CONCAT44((int)((ulong)pppppuVar32[(long)iVar14 * 0x7d + 0x10728] >> 0x20)
                                   + iVar13,(int)pppppuVar32[(long)iVar14 * 0x7d + 0x10728] + iVar13
                                  ),4);
    }
    if ((int)uVar49 < iVar23) {
      return (undefined *****)0x0;
    }
    if (iVar21 < (int)((ulong)uVar49 >> 0x20)) {
      return (undefined *****)0x0;
    }
    return (undefined *****)0x1;
  }
  iVar21 = func_0x00a58874(bVar10,uVar24);
  if (iVar21 == 0) {
    return (undefined *****)0x0;
  }
  if (iVar13 == 0) {
    iVar23 = func_0x00a5cb8c(0,(ulong)pppppuVar25 & 0xffffffff,uVar46);
    iVar21 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e45) * 4);
    iVar22 = func_0x00a5ca20(0,(ulong)pppppuVar25 & 0xffffffff,uVar46);
    if (iVar23 < 1) {
      iVar23 = func_0x00a5cb8c(0,uVar44,uVar46);
      iVar20 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e45) * 4);
      iVar21 = iVar21 - (iVar22 + iVar23);
      iVar23 = func_0x00a5ca20(0,uVar44,uVar46);
      iVar20 = iVar20 - iVar23;
    }
    else {
      iVar20 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x20e45) * 4);
      iVar21 = iVar21 - iVar22;
      iVar23 = func_0x00a5ca20(0,uVar44,uVar46);
      iVar22 = func_0x00a5cb8c(0,uVar44,uVar46);
      iVar20 = iVar20 - (iVar23 + iVar22);
    }
  }
  else {
    iVar22 = func_0x00a5cb8c(uVar29,(ulong)pppppuVar25 & 0xffffffff,uVar46);
    iVar23 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x24013) * 4);
    iVar21 = func_0x00a5ca20(uVar29,(ulong)pppppuVar25 & 0xffffffff,uVar46);
    iVar21 = iVar21 + iVar23;
    if (iVar22 < 1) {
      iVar22 = func_0x00a5cb8c(uVar29,(ulong)pppppuVar25 & 0xffffffff,uVar46);
      iVar23 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x24013) * 4);
      iVar21 = iVar21 + iVar22;
      iVar20 = func_0x00a5ca20(uVar29,uVar44,uVar46);
      iVar20 = iVar20 + iVar23;
    }
    else {
      iVar20 = *(int *)((long)pppppuVar32 + ((long)iVar20 * 0xfa + 0x24013) * 4);
      iVar23 = func_0x00a5ca20(uVar29,uVar44,uVar46);
      iVar22 = func_0x00a5cb8c(uVar29,uVar44,uVar46);
      iVar20 = iVar23 + iVar22 + iVar20;
    }
  }
  uVar24 = func_0x00a58df4(bVar10,uVar24,uVar44);
  if ((uVar24 & 1) == 0) {
    return (undefined *****)0x0;
  }
  iVar23 = *(int *)((long)pppppuVar32 +
                   ((ulong)(iVar13 == 0) * 0x31ce + (long)iVar14 * 0xfa + 0x20e45) * 4);
  if (iVar14 == 0) {
    if (iVar13 != 0) goto joined_r0x006ce4c4;
  }
  else {
    iVar22 = iVar20;
    if ((iVar13 != 0) ||
       (iVar13 = func_0x005aad10(), iVar22 = iVar21, iVar21 = iVar20, iVar13 != iVar14)) {
      iVar20 = iVar22;
      if (iVar23 < iVar21) {
        return (undefined *****)0x0;
      }
joined_r0x006ce4c4:
      if (iVar20 < iVar23) {
        return (undefined *****)0x0;
      }
      return (undefined *****)0x1;
    }
  }
  if (iVar23 < iVar20) {
    return (undefined *****)0x0;
  }
  return (undefined *****)0x1;
}


