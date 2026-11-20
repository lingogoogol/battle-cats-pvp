// ELF VMA: 0x9157fc
// Ghidra Addr: 0x00a157fc (ImageBase=0x100000)
// Size: 1 bytes


/* WARNING: Type propagation algorithm not settling */

void _INIT_219(void)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 auStack_150 [2];
  byte bStack_148;
  undefined8 uStack_147;
  undefined7 uStack_13f;
  undefined1 uStack_138;
  undefined2 uStack_137;
  undefined1 uStack_135;
  undefined4 uStack_134;
  undefined4 auStack_130 [2];
  byte bStack_128;
  undefined8 uStack_127;
  undefined7 uStack_11f;
  undefined1 uStack_118;
  undefined2 uStack_117;
  undefined1 uStack_115;
  undefined4 uStack_114;
  undefined4 auStack_110 [2];
  byte bStack_108;
  undefined8 uStack_107;
  undefined7 uStack_ff;
  undefined1 uStack_f8;
  undefined2 uStack_f7;
  undefined1 uStack_f5;
  undefined4 uStack_f4;
  undefined4 auStack_f0 [2];
  byte bStack_e8;
  undefined8 uStack_e7;
  undefined7 uStack_df;
  undefined1 uStack_d8;
  undefined2 uStack_d7;
  undefined1 uStack_d5;
  undefined4 uStack_d4;
  undefined4 auStack_d0 [2];
  byte bStack_c8;
  undefined8 uStack_c7;
  undefined7 uStack_bf;
  undefined1 uStack_b8;
  undefined2 uStack_b7;
  undefined1 uStack_b5;
  undefined4 uStack_b4;
  undefined4 auStack_b0 [2];
  byte bStack_a8;
  undefined8 uStack_a7;
  undefined7 uStack_9f;
  undefined1 uStack_98;
  undefined2 uStack_97;
  undefined1 uStack_95;
  undefined4 uStack_94;
  undefined4 auStack_90 [2];
  byte bStack_88;
  undefined8 uStack_87;
  undefined7 uStack_7f;
  undefined1 uStack_78;
  undefined2 uStack_77;
  undefined1 uStack_75;
  undefined4 uStack_74;
  long lStack_70;
  
  lVar1 = tpidr_el0;
  lStack_70 = *(long *)(lVar1 + 0x28);
  uStack_137 = 0x6741;
  auStack_130[0] = 1;
  uStack_13f = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_138 = 0x51;
  uStack_147 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_117 = 0x4142;
  auStack_110[0] = 2;
  uStack_11f = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_118 = 0x51;
  uStack_127 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_f7 = 0x6742;
  auStack_f0[0] = 3;
  uStack_ff = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_f8 = 0x51;
  uStack_107 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_d7 = 0x7741;
  auStack_d0[0] = 4;
  uStack_df = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_d8 = 0x51;
  uStack_e7 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_b7 = 0x5142;
  auStack_b0[0] = 5;
  uStack_bf = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_b8 = 0x51;
  uStack_c7 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_97 = 0x7742;
  auStack_90[0] = 6;
  uStack_9f = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_98 = 0x51;
  uStack_a7 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  bStack_148 = 0x24;
  bStack_128 = 0x24;
  bStack_108 = 0x24;
  bStack_e8 = 0x24;
  bStack_c8 = 0x24;
  bStack_a8 = 0x24;
  bStack_88 = 0x24;
  auStack_150[0] = 0;
  uStack_135 = 0;
  uStack_115 = 0;
  uStack_f5 = 0;
  uStack_d5 = 0;
  uStack_b5 = 0;
  uStack_95 = 0;
  uStack_77 = 0x4143;
  uStack_7f = 0x49414561515a5f;  /* ascii(0x49414561515a5f)='_ZQaEAI' */
  uStack_78 = 0x51;
  uStack_87 = 0x79334d6a496b6743;  /* ascii(0x79334d6a496b6743)='CgkIjM3y' */
  uStack_75 = 0;
  uRam000000000107d138 = 0;
  uRam000000000107d130 = 0;
  uRam000000000107d128 = 0x107d130;
  func_0x0040a528(0x107d128,0x107d130,auStack_150,auStack_150);
  func_0x0040a528(0x107d128,0x107d130,auStack_130,auStack_130);
  func_0x0040a528(0x107d128,0x107d130,auStack_110,auStack_110);
  func_0x0040a528(0x107d128,0x107d130,auStack_f0,auStack_f0);
  func_0x0040a528(0x107d128,0x107d130,auStack_d0,auStack_d0);
  func_0x0040a528(0x107d128,0x107d130,auStack_b0,auStack_b0);
  func_0x0040a528(0x107d128,0x107d130,auStack_90,auStack_90);
  if ((bStack_88 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_74,CONCAT13(uStack_75,CONCAT21(uStack_77,uStack_78))));
  }
  if ((bStack_a8 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_94,CONCAT13(uStack_95,CONCAT21(uStack_97,uStack_98))));
  }
  if ((bStack_c8 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_b4,CONCAT13(uStack_b5,CONCAT21(uStack_b7,uStack_b8))));
  }
  if ((bStack_e8 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_d4,CONCAT13(uStack_d5,CONCAT21(uStack_d7,uStack_d8))));
  }
  if ((bStack_108 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_f4,CONCAT13(uStack_f5,CONCAT21(uStack_f7,uStack_f8))));
  }
  if ((bStack_128 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_114,CONCAT13(uStack_115,CONCAT21(uStack_117,uStack_118))));
  }
  if ((bStack_148 & 1) != 0) {
    func_0x00bc3350(CONCAT44(uStack_134,CONCAT13(uStack_135,CONCAT21(uStack_137,uStack_138))));
  }
  func_0x00bc32d0(&UNK_00409ba0,0x107d128,&DAT_00bce2b0);  /* field_off=0x409ba0 */
  uRam000000000107d140 = 0xe;
  uRam000000000107d148 = 0;
  uRam000000000107d141 = 0x646e6173;  /* ascii(0x646e6173)='sand' */
  uRam000000000107d145 = 0x786f62;
  func_0x00bc32d0(_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev,0x107d140,
                  &DAT_00bce2b0);
  uRam000000000107d158 = 0x14;
  uRam000000000107d161 = 0x6e6f;
  uRam000000000107d159 = 0x69746375646f7270;  /* ascii(0x69746375646f7270)='producti' */
  uRam000000000107d163 = 0;
  func_0x00bc32d0(_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev,0x107d158,
                  &DAT_00bce2b0);
  uRam000000000107d191 = 0x7261;
  uRam000000000107d171 = 0x6c6169726f747554;  /* ascii(0x6c6169726f747554)='Tutorial' */
  uRam000000000107d189 = 0x656c436567617453;  /* ascii(0x656c436567617453)='StageCle' */
  uRam000000000107d1b9 = 0x617453746e657645;  /* ascii(0x617453746e657645)='EventSta' */
  uRam000000000107d1a1 = 0x53646e6567654c;  /* ascii(0x53646e6567654c)='LegendS' */
  uRam000000000107d1a8 = 0x65676174;  /* ascii(0x65676174)='tage' */
  uRam000000000107d1c1 = 0x6567;
  uRam000000000107d1d9 = 0x65676174;  /* ascii(0x65676174)='tage' */
  uRam000000000107d249 = 0x617469766f6b654e;  /* ascii(0x617469766f6b654e)='Nekovita' */
  uRam000000000107d1d1 = 0x536f62616c6c6f43;  /* ascii(0x536f62616c6c6f43)='CollaboS' */
  uRam000000000107d1f1 = 0x7261656c;  /* ascii(0x7261656c)='lear' */
  uRam000000000107d1e9 = 0x4365676174535845;  /* ascii(0x4365676174535845)='EXStageC' */
  uRam000000000107d201 = 0xe3a282e3ac83e3;
  uRam000000000107d208 = 0x82;
  uRam000000000107d209 = 0xa383e38183e3ac;
  uRam000000000107d221 = 0x6168;
  uRam000000000107d219 = 0x636147746e657645;  /* ascii(0x636147746e657645)='EventGac' */
  uRam000000000107d235 = 0x6576;
  uRam000000000107d230 = 0xc;
  uRam000000000107d231 = 0x6c6f7645;  /* ascii(0x6c6f7645)='Evol' */
  uRam000000000107d248 = 0x12;
  uRam000000000107d251 = 0x6e;
  uRam000000000107d2d8 = 0xc;
  uRam000000000107d320 = 0xc;
  uRam000000000107d170 = 0x10;
  uRam000000000107d261 = 0x6f746f74616d6147;  /* ascii(0x6f746f74616d6147)='Gamatoto' */
  uRam000000000107d278 = 6;
  uRam000000000107d279 = 0x646f47;
  uRam000000000107d299 = 0x7265;
  uRam000000000107d291 = 0x776f6c466f6b654e;  /* ascii(0x776f6c466f6b654e)='NekoFlow' */
  uRam000000000107d179 = 0;
  uRam000000000107d2a9 = 0x706f68536e65704f;  /* ascii(0x706f68536e65704f)='OpenShop' */
  uRam000000000107d2c9 = 0x796f;
  uRam000000000107d2c1 = 0x6a7061546e65704f;  /* ascii(0x6a7061546e65704f)='OpenTapj' */
  uRam000000000107d2dd = 0x7469;
  uRam000000000107d188 = 0x14;
  uRam000000000107d2d9 = 0x6e557845;  /* ascii(0x6e557845)='ExUn' */
  uRam000000000107d2f0 = 8;
  uRam000000000107d2f1 = 0x746f6c53;  /* ascii(0x746f6c53)='Slot' */
  uRam000000000107d193 = 0;
  uRam000000000107d1a0 = 0x16;
  uRam000000000107d1ac = 0;
  uRam000000000107d309 = 0x706f68536d657449;  /* ascii(0x706f68536d657449)='ItemShop' */
  uRam000000000107d325 = 0x7967;
  uRam000000000107d1b8 = 0x14;
  uRam000000000107d321 = 0x72656e45;  /* ascii(0x72656e45)='Ener' */
  uRam000000000107d1c3 = 0;
  uRam000000000107d1d0 = 0x18;
  uRam000000000107d341 = 0x70556c657665;  /* ascii(0x70556c657665)='evelUp' */
  uRam000000000107d339 = 0x794573746143;  /* ascii(0x794573746143)='CatsEy' */
  uRam000000000107d33f = 0x4c65;
  uRam000000000107d1dd = 0;
  uRam000000000107d1e8 = 0x18;
  uRam000000000107d351 = 0x65756e69746e6f43;  /* ascii(0x65756e69746e6f43)='Continue' */
  uRam000000000107d1f5 = 0;
  uRam000000000107d200 = 0x1e;
  uRam000000000107d371 = 0x6168636147;  /* ascii(0x6168636147)='Gacha' */
  uRam000000000107d369 = 0x6974616c50;  /* ascii(0x6974616c50)='Plati' */
  uRam000000000107d36e = 0x6d756e;
  uRam000000000107d210 = 0;
  uRam000000000107d381 = 0x47705570657453;  /* ascii(0x47705570657453)='StepUpG' */
  uRam000000000107d388 = 0x61686361;  /* ascii(0x61686361)='acha' */
  uRam000000000107d3a1 = 0x6e69;
  uRam000000000107d399 = 0x676f4c796c696144;  /* ascii(0x676f4c796c696144)='DailyLog' */
  uRam000000000107d218 = 0x14;
  uRam000000000107d3b9 = 0x64416f65646956;  /* ascii(0x64416f65646956)='VideoAd' */
  uRam000000000107d3b1 = 0x746f74616d6147;  /* ascii(0x746f74616d6147)='Gamatot' */
  uRam000000000107d3b8 = 0x6f;
  uRam000000000107d223 = 0;
  uRam000000000107d237 = 0;
  uRam000000000107d260 = 0x10;
  uRam000000000107d269 = 0;
  uRam000000000107d290 = 0x14;
  uRam000000000107d29b = 0;
  uRam000000000107d2a8 = 0x10;
  uRam000000000107d2b1 = 0;
  uRam000000000107d2c0 = 0x14;
  uRam000000000107d2cb = 0;
  uRam000000000107d2df = 0;
  uRam000000000107d2f5 = 0;
  uRam000000000107d308 = 0x10;
  uRam000000000107d311 = 0;
  uRam000000000107d327 = 0;
  uRam000000000107d338 = 0x1c;
  uRam000000000107d347 = 0;
  uRam000000000107d350 = 0x10;
  uRam000000000107d359 = 0;
  uRam000000000107d368 = 0x1a;
  uRam000000000107d376 = 0;
  uRam000000000107d380 = 0x16;
  uRam000000000107d38c = 0;
  uRam000000000107d398 = 0x14;
  uRam000000000107d3a3 = 0;
  uRam000000000107d3b0 = 0x1e;
  uRam000000000107d3c0 = 0;
  uRam000000000107d3c8 = 0x1a;
  uRam000000000107d3d1 = 0x64416f6564;  /* ascii(0x64416f6564)='deoAd' */
  uRam000000000107d3c9 = 0x6772656e45;  /* ascii(0x6772656e45)='Energ' */
  uRam000000000107d3ce = 0x695679;
  uRam000000000107d3d6 = 0;
  puRam000000000107d3f0 = (undefined8 *)func_0x00bc3330(0x20);
  uRam000000000107d418 = 0x61686361;  /* ascii(0x61686361)='acha' */
  puRam000000000107d3f0[2] = 0x656d695479726576;  /* ascii(0x656d695479726576)='veryTime' */
  puRam000000000107d3f0[1] = 0x457261656c436567;  /* ascii(0x457261656c436567)='geClearE' */
  *puRam000000000107d3f0 = 0x617453746e657645;  /* ascii(0x617453746e657645)='EventSta' */
  uRam000000000107d431 = 0x7261;
  uRam000000000107d411 = 0x476c616d726f4e;  /* ascii(0x476c616d726f4e)='NormalG' */
  uRam000000000107d418 = CONCAT31(uRam000000000107d418._1_3_,0x61);
  uRam000000000107d401 = 0x726566736e617254;  /* ascii(0x726566736e617254)='Transfer' */
  uRam000000000107d3f9 = 0x6174614465766153;  /* ascii(0x6174614465766153)='SaveData' */
  uRam000000000107d4e8 = 0x1e;
  uRam000000000107d429 = 0x656c436c61697254;  /* ascii(0x656c436c61697254)='TrialCle' */
  uRam000000000107d441 = 0x6d69546c61697254;  /* ascii(0x6d69546c61697254)='TrialTim' */
  uRam000000000107d449 = 0x70557365;  /* ascii(0x70557365)='esUp' */
  uRam000000000107d481 = 0x6b;
  uRam000000000107d488 = 0x26;
  uRam000000000107d461 = 0x7261656c43656761;  /* ascii(0x7261656c43656761)='ageClear' */
  uRam000000000107d459 = 0x74536569626d6f5a;  /* ascii(0x74536569626d6f5a)='ZombieSt' */
  uRam000000000107d479 = 0x6e694c6572616853;  /* ascii(0x6e694c6572616853)='ShareLin' */
  uRam000000000107d471 = 0x6b6f6f6265636146;  /* ascii(0x6b6f6f6265636146)='Facebook' */
  uRam000000000107d470 = 0x22;
  uRam000000000107d4a1 = 0x656c6c616843;  /* ascii(0x656c6c616843)='Challe' */
  uRam000000000107d4a7 = 0x676e;
  uRam000000000107d4a9 = 0x747261745365;  /* ascii(0x747261745365)='eStart' */
  uRam000000000107d548 = 0x22;
  uRam000000000107d4c1 = 0x6e695765;  /* ascii(0x6e695765)='eWin' */
  uRam000000000107d4b9 = 0x676e656c6c616843;  /* ascii(0x676e656c6c616843)='Challeng' */
  uRam000000000107d491 = 0x79726576457261;  /* ascii(0x79726576457261)='arEvery' */
  uRam000000000107d498 = 0x656d6954;  /* ascii(0x656d6954)='Time' */
  uRam000000000107d489 = 0x656c436567617453;  /* ascii(0x656c436567617453)='StageCle' */
  uRam000000000107d4d9 = 0x65736f4c65;  /* ascii(0x65736f4c65)='eLose' */
  uRam000000000107d4d1 = 0x6c6c616843;  /* ascii(0x6c6c616843)='Chall' */
  uRam000000000107d4d6 = 0x676e65;
  uRam000000000107d4e9 = 0x6e656c6c616843;  /* ascii(0x6e656c6c616843)='Challen' */
  uRam000000000107d4f0 = 0x67;
  uRam000000000107d4f1 = 0x65726974655265;  /* ascii(0x65726974655265)='eRetire' */
  uRam000000000107d3e8 = 0x18;
  uRam000000000107d3e0 = 0x21;
  *(undefined1 *)(puRam000000000107d3f0 + 3) = 0;
  uRam000000000107d501 = 0x6c75736552;  /* ascii(0x6c75736552)='Resul' */
  uRam000000000107d506 = 0x775474;
  uRam000000000107d509 = 0x7265747469;  /* ascii(0x7265747469)='itter' */
  uRam000000000107d3f8 = 0x20;
  uRam000000000107d521 = 0x656e;
  uRam000000000107d519 = 0x694c746c75736552;  /* ascii(0x694c746c75736552)='ResultLi' */
  uRam000000000107d409 = 0;
  uRam000000000107d539 = 0x656e;
  uRam000000000107d531 = 0x694c6e6f6974704f;  /* ascii(0x694c6e6f6974704f)='OptionLi' */
  uRam000000000107d559 = 0x72;
  uRam000000000107d410 = 0x16;
  uRam000000000107d41c = 0;
  uRam000000000107d428 = 0x14;
  uRam000000000107d433 = 0;
  uRam000000000107d440 = 0x18;
  uRam000000000107d44d = 0;
  uRam000000000107d458 = 0x20;
  uRam000000000107d469 = 0;
  uRam000000000107d49c = 0;
  uRam000000000107d4a0 = 0x1c;
  uRam000000000107d4af = 0;
  uRam000000000107d4b8 = 0x18;
  uRam000000000107d4c5 = 0;
  uRam000000000107d4d0 = 0x1a;
  uRam000000000107d4de = 0;
  uRam000000000107d4f8 = 0;
  uRam000000000107d500 = 0x1a;
  uRam000000000107d50e = 0;
  uRam000000000107d518 = 0x14;
  uRam000000000107d523 = 0;
  uRam000000000107d530 = 0x14;
  uRam000000000107d53b = 0;
  uRam000000000107d551 = 0x6574636172616843;  /* ascii(0x6574636172616843)='Characte' */
  uRam000000000107d549 = 0x7465476168636147;  /* ascii(0x7465476168636147)='GachaGet' */
  uRam000000000107d560 = 0x10;
  uRam000000000107d561 = 0x6b6e615272657355;  /* ascii(0x6b6e615272657355)='UserRank' */
  uRam000000000107d569 = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x20);
  puRam000000000107d588 = puVar2;
  puVar2[1] = 0x7261656c43656761;  /* ascii(0x7261656c43656761)='ageClear' */
  *puVar2 = 0x7453646e6567654c;  /* ascii(0x7453646e6567654c)='LegendSt' */
  *(undefined8 *)((long)puVar2 + 0x11) = 0x656d695479726576;  /* ascii(0x656d695479726576)='veryTime' */
  *(undefined8 *)((long)puVar2 + 9) = 0x457261656c436567;  /* ascii(0x457261656c436567)='geClearE' */
  uRam000000000107d580 = 0x19;
  uRam000000000107d578 = 0x21;
  *(undefined1 *)((long)puVar2 + 0x19) = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x20);
  uRam000000000107d5b1 = 0x6d6f7473;  /* ascii(0x6d6f7473)='stom' */
  uRam000000000107d5a9 = 0x7543656c74736143;  /* ascii(0x7543656c74736143)='CastleCu' */
  uRam000000000107d5c1 = 0x43656974726f53;  /* ascii(0x43656974726f53)='SortieC' */
  uRam000000000107d5c8 = 0x61;
  uRam000000000107d5c9 = 0x6e6f6e6e614374;  /* ascii(0x6e6f6e6e614374)='tCannon' */
  uRam000000000107d5d8 = 10;
  puVar2[1] = 0x7261656c43656761;  /* ascii(0x7261656c43656761)='ageClear' */
  *puVar2 = 0x745362616c6c6f43;  /* ascii(0x745362616c6c6f43)='CollabSt' */
  uRam000000000107d5d9 = 0x65776f54;  /* ascii(0x65776f54)='Towe' */
  uRam000000000107d5dd = 0x72;
  uRam000000000107d598 = 0x19;
  uRam000000000107d590 = 0x21;
  uRam000000000107d5f1 = 0x697373694d;  /* ascii(0x697373694d)='Missi' */
  uRam000000000107d5f6 = 0x4e6e6f;
  uRam000000000107d5f9 = 0x6c616d726f;  /* ascii(0x6c616d726f)='ormal' */
  uRam000000000107d5a8 = 0x18;
  uRam000000000107d5b5 = 0;
  uRam000000000107d609 = 0x697373694d;  /* ascii(0x697373694d)='Missi' */
  uRam000000000107d60e = 0x576e6f;
  uRam000000000107d611 = 0x796c6b6565;  /* ascii(0x796c6b6565)='eekly' */
  uRam000000000107d5c0 = 0x1e;
  uRam000000000107d621 = 0x456e6f697373694d;  /* ascii(0x456e6f697373694d)='MissionE' */
  uRam000000000107d629 = 0x746e6576;  /* ascii(0x746e6576)='vent' */
  uRam000000000107d638 = 0x1c;
  uRam000000000107d641 = 0x796c68746e6f;  /* ascii(0x796c68746e6f)='onthly' */
  uRam000000000107d639 = 0x6f697373694d;  /* ascii(0x6f697373694d)='Missio' */
  uRam000000000107d63f = 0x4d6e;
  uRam000000000107d650 = 0x14;
  uRam000000000107d659 = 0x6d65;
  uRam000000000107d680 = 0x14;
  uRam000000000107d651 = 0x74496e6f63616542;  /* ascii(0x74496e6f63616542)='BeaconIt' */
  uRam000000000107d5d0 = 0;
  uRam000000000107d5f0 = 0x1a;
  uRam000000000107d5fe = 0;
  uRam000000000107d608 = 0x1a;
  uRam000000000107d616 = 0;
  uRam000000000107d620 = 0x18;
  uRam000000000107d62d = 0;
  uRam000000000107d647 = 0;
  uRam000000000107d65b = 0;
  uRam000000000107d668 = 0x1e;
  uRam000000000107d669 = 0x436e6f63616542;  /* ascii(0x436e6f63616542)='BeaconC' */
  uRam000000000107d670 = 0x68;
  uRam000000000107d671 = 0x72657463617261;  /* ascii(0x72657463617261)='aracter' */
  uRam000000000107d678 = 0;
  uRam000000000107d698 = 0x18;
  uRam000000000107d681 = 0x656e614d6f6b654e;  /* ascii(0x656e614d6f6b654e)='NekoMane' */
  uRam000000000107d689 = 0x696b;
  puRam000000000107d5a0 = puVar2;
  *(undefined8 *)((long)puVar2 + 0x11) = 0x656d695479726576;  /* ascii(0x656d695479726576)='veryTime' */
  *(undefined8 *)((long)puVar2 + 9) = 0x457261656c436567;  /* ascii(0x457261656c436567)='geClearE' */
  *(undefined1 *)((long)puVar2 + 0x19) = 0;
  uRam000000000107d68b = 0;
  uRam000000000107d6a1 = 0x6e6f6974;  /* ascii(0x6e6f6974)='tion' */
  uRam000000000107d699 = 0x6172656e65476441;  /* ascii(0x6172656e65476441)='AdGenera' */
  uRam000000000107d6a5 = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x30);
  *(undefined1 *)((long)puVar2 + 0x2d) = 0;
  puRam000000000107d6c0 = puVar2;
  puVar2[1] = 0xe38d83e3a782e3b8;
  *puVar2 = 0x82e38983e3a282e3;
  puVar2[3] = 0x82e38683e3b383e3;
  puVar2[2] = 0xbb82e3b383e3a482;
  *(undefined8 *)((long)puVar2 + 0x25) = 0xbc83e3a983e3a882;
  *(undefined8 *)((long)puVar2 + 0x1d) = 0xe39683e3a382e386;
  uRam000000000107d6b8 = 0x2d;
  uRam000000000107d6b0 = 0x31;
  uRam000000000107d6c9 = 0x63536c7255;  /* ascii(0x63536c7255)='UrlSc' */
  uRam000000000107d6ce = 0x6d6568;
  uRam000000000107d6d1 = 0x646e655365;  /* ascii(0x646e655365)='eSend' */
  uRam000000000107d6c8 = 0x1a;
  uRam000000000107d6d6 = 0;
  uRam000000000107d6e9 = 0x64656c69614665;  /* ascii(0x64656c69614665)='eFailed' */
  uRam000000000107d6e1 = 0x656863536c7255;  /* ascii(0x656863536c7255)='UrlSche' */
  uRam000000000107d6e8 = 0x6d;
  uRam000000000107d6f8 = 0x22;
  uRam000000000107d6e0 = 0x1e;
  uRam000000000107d6f0 = 0;
  uRam000000000107d709 = 100;
  uRam000000000107d701 = 0x6576696563655265;  /* ascii(0x6576696563655265)='eReceive' */
  uRam000000000107d6f9 = 0x6d656863536c7255;  /* ascii(0x6d656863536c7255)='UrlSchem' */
  puVar2 = (undefined8 *)func_0x00bc3330(0x30);
  uRam000000000107d718 = 0x27;
  uRam000000000107d710 = 0x31;
  puRam000000000107d720 = puVar2;
  puVar2[1] = 0xe3b383e3a782e3b8;
  *puVar2 = 0x82e3ac83e39f9ce7;
  puVar2[3] = 0x82e3b882e3bc83e3;
  puVar2[2] = 0x8683e3b982e38983;
  *(undefined8 *)((long)puVar2 + 0x1f) = 0xa282e3aa83e3af82;
  *(undefined1 *)((long)puVar2 + 0x27) = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x30);
  puRam000000000107d738 = puVar2;
  *(undefined4 *)(puVar2 + 4) = 0xa282e3aa;
  uRam000000000107d730 = 0x24;
  uRam000000000107d728 = 0x31;
  puVar2[1] = 0xe3b383e3bf82e393;
  *puVar2 = 0x83e3b382e38d83e3;
  puVar2[3] = 0x83e3af82e3b882e3;
  puVar2[2] = 0xbc83e38683e3b982;
  *(undefined1 *)((long)puVar2 + 0x24) = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x40);
  uRam000000000107d748 = 0x30;
  uRam000000000107d740 = 0x41;
  puRam000000000107d750 = puVar2;
  puVar2[1] = 0xe3a482e3a182e395;
  *puVar2 = 0x83e398ade59dbfe4;
  puVar2[3] = 0x82e38183e3ba82e3;
  puVar2[2] = 0xa482e3b582e3ab83;
  puVar2[5] = 0xbc83e3a983e3a882;
  puVar2[4] = 0xe3af82e38383e3a7;
  *(undefined1 *)(puVar2 + 6) = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x40);
  *(undefined1 *)((long)puVar2 + 0x33) = 0;
  puVar2[1] = 0xe3bc83e38783e396;
  *puVar2 = 0x83e3bc83e3bb82e3;
  puVar2[3] = 0x82e3ab83e3a482e3;
  puVar2[2] = 0xa182e39583e3bf82;
  uRam000000000107d760 = 0x33;
  uRam000000000107d758 = 0x41;
  puRam000000000107d768 = puVar2;
  *(undefined4 *)((long)puVar2 + 0x2f) = 0xbc83e3a9;
  puVar2[5] = 0xa983e3a882e3b383;
  puVar2[4] = 0xe39783e3bc83e3aa;
  puVar2 = (undefined8 *)func_0x00bc3330(0x40);
  *(undefined1 *)((long)puVar2 + 0x39) = 0;
  uRam000000000107d778 = 0x39;
  uRam000000000107d770 = 0x41;
  puVar2[1] = 0xe3bc83e38783e396;
  *puVar2 = 0x83e3bc83e3bb82e3;
  puVar2[3] = 0xade5ab83e3a482e3;
  puVar2[2] = 0xa182e39583e3bf82;
  puRam000000000107d780 = puVar2;
  puVar2[5] = 0xaf82e38383e3a782;
  puVar2[4] = 0xe38183e3a89ce598;
  *(undefined8 *)((long)puVar2 + 0x31) = 0xbc83e3a983e3a882;
  *(undefined8 *)((long)puVar2 + 0x29) = 0xe3af82e38383e3a7;
  puVar2 = (undefined8 *)func_0x00bc3330(0x30);
  uRam000000000107d790 = 0x2d;
  uRam000000000107d788 = 0x31;
  puRam000000000107d798 = puVar2;
  *(undefined1 *)((long)puVar2 + 0x2d) = 0;
  puVar2[1] = 0xe3bc83e38783e396;
  *puVar2 = 0x83e3bc83e3bb82e3;
  puVar2[3] = 0xa4e6ab83e3a482e3;
  puVar2[2] = 0xa182e39583e3bf82;
  *(undefined8 *)((long)puVar2 + 0x25) = 0xbc83e3a983e3a882;
  *(undefined8 *)((long)puVar2 + 0x1d) = 0xe3bca8e89ca4e6ab;
  puVar2 = (undefined8 *)func_0x00bc3330(0x40);
  uRam000000000107d7a8 = 0x30;
  uRam000000000107d7a0 = 0x41;
  puRam000000000107d7b0 = puVar2;
  *(undefined1 *)(puVar2 + 6) = 0;
  puVar2[1] = 0xe3af82e39381e393;
  *puVar2 = 0x82e38382e3ab81e3;
  puVar2[3] = 0x83e39a83e38e98e6;
  puVar2[2] = 0xacaae89683e3a983;
  puVar2[5] = 0xbaa4e7a8a1e89e9b;
  puVar2[4] = 0xe59d88e5b882e3bc;
  puRam000000000107d7c8 = (undefined8 *)func_0x00bc3330(0x20);
  puRam000000000107d7c8[1] = 0xe3af82e39381e393;
  *puRam000000000107d7c8 = 0x82e38382e3ab81e3;
  uRam000000000107d7d1 = 0x9b8fe689a4e5504e;
  *(undefined8 *)((long)puRam000000000107d7c8 + 0x16) = 0xbfa8e7958ae6534e;
  *(undefined8 *)((long)puRam000000000107d7c8 + 0xe) = 0x539683e3a983e3af;
  uRam000000000107d7f0 = 0x65676174;  /* ascii(0x65676174)='tage' */
  uRam000000000107d7c0 = 0x1e;
  uRam000000000107d7b8 = 0x21;
  *(undefined1 *)((long)puRam000000000107d7c8 + 0x1e) = 0;
  uRam000000000107d7d0 = 0x10;
  uRam000000000107d7d9 = 0;
  uRam000000000107d7e8 = 0x16;
  uRam000000000107d7e9 = 0x536d6f646e6152;  /* ascii(0x536d6f646e6152)='RandomS' */
  uRam000000000107d7f0 = CONCAT31(uRam000000000107d7f0._1_3_,0x74);
  uRam000000000107d7f4 = 0;
  puRam000000000107d810 = (undefined8 *)func_0x00bc3330(0x30);
  *(undefined2 *)(puRam000000000107d810 + 4) = 0xa5;
  uRam000000000107d808 = 0x21;
  uRam000000000107d800 = 0x31;
  uRam000000000107d819 = 0x4d746143746547;  /* ascii(0x4d746143746547)='GetCatM' */
  uRam000000000107d820 = 0x6c616465;  /* ascii(0x6c616465)='edal' */
  uRam000000000107d830 = 0x1e;
  puRam000000000107d810[1] = 0xe3ab82e38883e3b3;
  *puRam000000000107d810 = 0x83e39983e3a482e3;
  puRam000000000107d810[3] = 0x9fe79a80e9bc83e3;
  puRam000000000107d810[2] = 0x8083e3b383e3ac83;
  uRam000000000107d839 = 0x746f6c53797261;  /* ascii(0x746f6c53797261)='arySlot' */
  uRam000000000107d860 = 10;
  uRam000000000107d851 = 0x53746f6c53797261;  /* ascii(0x53746f6c53797261)='arySlotS' */
  uRam000000000107d849 = 0x73726576696e6e41;  /* ascii(0x73726576696e6e41)='Annivers' */
  uRam000000000107d861 = 0x72617453;  /* ascii(0x72617453)='Star' */
  uRam000000000107d865 = 0x74;
  uRam000000000107d8b1 = 0x776f5073746e656c;  /* ascii(0x776f5073746e656c)='lentsPow' */
  uRam000000000107d8a9 = 0x61546c6165766552;  /* ascii(0x61546c6165766552)='RevealTa' */
  uRam000000000107d831 = 0x726576696e6e41;  /* ascii(0x726576696e6e41)='Anniver' */
  uRam000000000107d838 = 0x73;
  uRam000000000107d878 = 0x10;
  uRam000000000107d879 = 0x73736572676f7250;  /* ascii(0x73736572676f7250)='Progress' */
  uRam000000000107d890 = 6;
  uRam000000000107d8c1 = 0x6761745364696152;  /* ascii(0x6761745364696152)='RaidStag' */
  uRam000000000107d891 = 0x646e45;
  uRam000000000107d8a8 = 0x28;
  uRam000000000107d859 = 0x534e;
  uRam000000000107d8b9 = 0x70557265;  /* ascii(0x70557265)='erUp' */
  uRam000000000107d8c0 = 0x12;
  uRam000000000107d8c9 = 0x65;
  uRam000000000107d8d9 = 0x72446e6564646948;  /* ascii(0x72446e6564646948)='HiddenDr' */
  uRam000000000107d8e1 = 0x706f;
  uRam000000000107d8f1 = 0x436e6564646948;  /* ascii(0x436e6564646948)='HiddenC' */
  uRam000000000107d8f8 = 0x7261656c;  /* ascii(0x7261656c)='lear' */
  uRam000000000107d818 = 0x16;
  uRam000000000107d909 = 0x6d75696d657250;  /* ascii(0x6d75696d657250)='Premium' */
  uRam000000000107d910 = 0x656c6153;  /* ascii(0x656c6153)='Sale' */
  uRam000000000107d920 = 0x1c;
  uRam000000000107da58 = 0x1c;
  uRam000000000107d929 = 0x746c75617373;  /* ascii(0x746c75617373)='ssault' */
  uRam000000000107d921 = 0x62616c6c6f43;  /* ascii(0x62616c6c6f43)='Collab' */
  uRam000000000107d927 = 0x416f;
  uRam000000000107d824 = 0;
  uRam000000000107d941 = 0x7069;
  uRam000000000107d939 = 0x687372656461654c;  /* ascii(0x687372656461654c)='Leadersh' */
  uRam000000000107d840 = 0;
  uRam000000000107d951 = 0x6772656e45;  /* ascii(0x6772656e45)='Energ' */
  uRam000000000107d956 = 0x654e79;
  uRam000000000107d959 = 0x6e616b6f6b;  /* ascii(0x6e616b6f6b)='kokan' */
  uRam000000000107d979 = 0x746e;
  uRam000000000107d971 = 0x656d656369747265;  /* ascii(0x656d656369747265)='erticeme' */
  uRam000000000107d969 = 0x7664416569766f4d;  /* ascii(0x7664416569766f4d)='MovieAdv' */
  uRam000000000107d980 = 0x26;
  uRam000000000107d989 = 0x76654c656c706d;  /* ascii(0x76654c656c706d)='mpleLev' */
  uRam000000000107d990 = 0x70556c65;  /* ascii(0x70556c65)='elUp' */
  uRam000000000107d981 = 0x65546f6b6e61794e;  /* ascii(0x65546f6b6e61794e)='NyankoTe' */
  uRam000000000107d998 = 0x18;
  uRam000000000107d9a1 = 0x74656b63;  /* ascii(0x74656b63)='cket' */
  uRam000000000107d999 = 0x6954646e6567654c;  /* ascii(0x6954646e6567654c)='LegendTi' */
  uRam000000000107d950 = 0x1a;
  uRam000000000107d9b9 = 0x696a756b69;  /* ascii(0x696a756b69)='ikuji' */
  uRam000000000107d9b1 = 0x6b6e61794e;  /* ascii(0x6b6e61794e)='Nyank' */
  uRam000000000107d9b6 = 0x6d4f6f;
  uRam000000000107d9c8 = 0xe;
  uRam000000000107da28 = 0xe;
  uRam000000000107d9c9 = 0x61726353;  /* ascii(0x61726353)='Scra' */
  uRam000000000107d9cd = 0x686374;
  uRam000000000107d9e9 = 0x534e;
  uRam000000000107d9e1 = 0x5368637461726353;  /* ascii(0x5368637461726353)='ScratchS' */
  uRam000000000107da01 = 0x6567;
  uRam000000000107d9f9 = 0x6174536e6f6d6544;  /* ascii(0x6174536e6f6d6544)='DemonSta' */
  uRam000000000107d9b0 = 0x1a;
  uRam000000000107da19 = 0x6567;
  uRam000000000107da11 = 0x6174537473616542;  /* ascii(0x6174537473616542)='BeastSta' */
  uRam000000000107da40 = 0x1a;
  uRam000000000107da29 = 0x64616f4c;  /* ascii(0x64616f4c)='Load' */
  uRam000000000107da2d = 0x646e45;
  uRam000000000107d848 = 0x24;
  uRam000000000107d85b = 0;
  uRam000000000107da41 = 0x43706f7244;  /* ascii(0x43706f7244)='DropC' */
  uRam000000000107da46 = 0x726168;
  uRam000000000107da49 = 0x7265746361;  /* ascii(0x7265746361)='acter' */
  uRam000000000107d881 = 0;
  uRam000000000107d8bd = 0;
  uRam000000000107d8d8 = 0x14;
  uRam000000000107d8e3 = 0;
  uRam000000000107d8f0 = 0x16;
  uRam000000000107d8fc = 0;
  uRam000000000107d908 = 0x16;
  uRam000000000107d914 = 0;
  uRam000000000107d92f = 0;
  uRam000000000107d938 = 0x14;
  uRam000000000107d943 = 0;
  uRam000000000107d95e = 0;
  uRam000000000107d968 = 0x24;
  uRam000000000107d97b = 0;
  uRam000000000107d994 = 0;
  uRam000000000107d9a5 = 0;
  uRam000000000107d9be = 0;
  uRam000000000107d9d0 = 0;
  uRam000000000107d9e0 = 0x14;
  uRam000000000107d9eb = 0;
  uRam000000000107d9f8 = 0x14;
  uRam000000000107da03 = 0;
  uRam000000000107da10 = 0x14;
  uRam000000000107da1b = 0;
  uRam000000000107da30 = 0;
  uRam000000000107da4e = 0;
  uRam000000000107da61 = 0x656761745368;  /* ascii(0x656761745368)='hStage' */
  uRam000000000107da59 = 0x69727962614c;  /* ascii(0x69727962614c)='Labyri' */
  uRam000000000107da5f = 0x746e;
  uRam000000000107da67 = 0;
  puRam000000000107da80 = (undefined8 *)func_0x00bc3330(0x40);
  *(undefined1 *)((long)puRam000000000107da80 + 0x36) = 0;
  puRam000000000107da80[1] = 0xe38983e3b383e3a7;
  *puRam000000000107da80 = 0x82e3b882e3ac83e3;
  puRam000000000107da80[3] = 0xbcefbc83e3aa83e3;
  puRam000000000107da80[2] = 0xbc83e38883e3b982;
  pbVar4 = (byte *)0x107dae8;
  uRam000000000107da78 = 0x36;
  uRam000000000107da70 = 0x41;
  puRam000000000107da80[5] = 0xaf82e3b882e3bc83;
  puRam000000000107da80[4] = 0xe38683e3b982e390;
  *(undefined8 *)((long)puRam000000000107da80 + 0x2e) = 0xa282e3aa83e3af82;
  uRam000000000107da99 = 0x7473;
  uRam000000000107daa9 = 0x6d6f;
  uRam000000000107daa1 = 0x7473754365736142;  /* ascii(0x7473754365736142)='BaseCust' */
  uRam000000000107dac1 = 0x6d6f;
  uRam000000000107dab9 = 0x747375436f636544;  /* ascii(0x747375436f636544)='DecoCust' */
  uRam000000000107da88 = 0x24;
  uRam000000000107da91 = 0x72694673746e656c;  /* ascii(0x72694673746e656c)='lentsFir' */
  uRam000000000107da89 = 0x61546c6165766552;  /* ascii(0x61546c6165766552)='RevealTa' */
  uRam000000000107da9b = 0;
  uRam000000000107daa0 = 0x14;
  uRam000000000107daab = 0;
  uRam000000000107dab8 = 0x14;
  uRam000000000107dac3 = 0;
  uRam000000000107dad0 = 0x16;
  uRam000000000107dad1 = 0x61437265707553;  /* ascii(0x61437265707553)='SuperCa' */
  uRam000000000107dad8 = 0x55504374;  /* ascii(0x55504374)='tCPU' */
  uRam000000000107dadc = 0;
  puVar2 = (undefined8 *)func_0x00bc3330(0x20);
  uRam000000000107daf0 = 0x18;
  uRam000000000107dae8 = 0x21;
  puRam000000000107daf8 = puVar2;
  *(undefined1 *)(puVar2 + 3) = 0;
  puVar2[2] = 0x7463656a6552746e;  /* ascii(0x7463656a6552746e)='ntReject' */
  puVar2[1] = 0x656d656369747265;  /* ascii(0x656d656369747265)='erticeme' */
  *puVar2 = 0x7664416569766f4d;  /* ascii(0x7664416569766f4d)='MovieAdv' */
  uRam000000000107db01 = 0x656c74746142;  /* ascii(0x656c74746142)='Battle' */
  uRam000000000107db07 = 0x6441;
  uRam000000000107db09 = 0x6e6f74747542;  /* ascii(0x6e6f74747542)='Button' */
  uRam000000000107db19 = 0x4774656c74754f;  /* ascii(0x4774656c74754f)='OutletG' */
  uRam000000000107db20 = 0x61686361;  /* ascii(0x61686361)='acha' */
  uRam000000000107db00 = 0x1c;
  uRam000000000107db30 = 0x1c;
  uRam000000000107db31 = 0x75696d657250;  /* ascii(0x75696d657250)='Premiu' */
  uRam000000000107db37 = 0x536d;
  uRam000000000107db39 = 0x646441656c61;  /* ascii(0x646441656c61)='aleAdd' */
  uRam000000000107db48 = 0x1a;
  uRam000000000107db49 = 0x696d657250;  /* ascii(0x696d657250)='Premi' */
  uRam000000000107db4e = 0x536d75;
  uRam000000000107db51 = 0x6552656c61;  /* ascii(0x6552656c61)='aleRe' */
  uRam000000000107db0f = 0;
  uRam000000000107db18 = 0x16;
  uRam000000000107db24 = 0;
  uRam000000000107db3f = 0;
  uRam000000000107db56 = 0;
  uRam000000000107db60 = 0x20;
  uRam000000000107db69 = 0x647261776552746e;  /* ascii(0x647261776552746e)='ntReward' */
  uRam000000000107db61 = 0x696f50746e657645;  /* ascii(0x696f50746e657645)='EventPoi' */
  uRam000000000107db71 = 0;
  func_0x00bc32d0(&UNK_00a0a814,0x107d170,&DAT_00bce2b0);  /* field_off=0xa0a814 */
  if (*(long *)(lVar1 + 0x28) == lStack_70) {
    return;
  }
  do {
    uVar3 = func_0x00bc3380();
    pbVar5 = pbVar4;
    do {
      pbVar4 = pbVar5 + -0x18;
      if ((*pbVar4 & 1) != 0) {
        func_0x00bc3350(*(undefined8 *)(pbVar5 + -8));
      }
      pbVar5 = pbVar4;
    } while (pbVar4 != (byte *)0x107d170);
    if (*(long *)(lVar1 + 0x28) == lStack_70) {
      func_0x00bbf40c(uVar3);
    }
  } while( true );
}


