// ELF VMA: 0x703318
// Ghidra Addr: 0x00803318 (ImageBase=0x100000)
// Function: Battle_SceneUpdateCaller
// Size: 8584 bytes
// Callees (1): Battle_MainUpdateLoop@0x5c731c, 


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint Battle_SceneUpdateCaller(long *param_1)

{
  long *plVar1;
  long *plVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  long lVar6;
  undefined ***pppuVar7;
  undefined ***pppuVar8;
  int iVar9;
  uint uVar10;
  ulong uVar11;
  undefined ***pppuVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  int iVar15;
  undefined4 uVar16;
  long lVar17;
  undefined ***pppuVar18;
  undefined ***unaff_x22;
  undefined ***unaff_x26;
  double dVar19;
  int iVar20;
  int iVar21;
  undefined1 auStack_358 [16];
  byte abStack_348 [16];
  undefined8 uStack_338;
  byte abStack_330 [16];
  undefined8 uStack_320;
  byte abStack_318 [16];
  undefined8 uStack_308;
  ulong uStack_300;
  undefined8 uStack_2f8;
  undefined8 uStack_2f0;
  byte abStack_2e8 [16];
  undefined8 uStack_2d8;
  ulong uStack_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  byte abStack_2b0 [16];
  undefined8 uStack_2a0;
  byte abStack_298 [16];
  undefined8 uStack_288;
  byte abStack_280 [16];
  undefined8 uStack_270;
  byte abStack_268 [16];
  undefined8 uStack_258;
  undefined ***pppuStack_250;
  undefined ***pppuStack_248;
  undefined8 *puStack_240;
  undefined ***pppuStack_230;
  long *plStack_228;
  undefined8 *puStack_220;
  byte bStack_218;
  undefined7 uStack_217;
  undefined ***pppuStack_210;
  undefined ***pppuStack_208;
  ulong uStack_200;
  long *plStack_1f8;
  undefined8 *puStack_1f0;
  byte abStack_1e8 [16];
  undefined8 uStack_1d8;
  ulong uStack_1d0;
  long *plStack_1c8;
  undefined8 *puStack_1c0;
  byte abStack_1b8 [16];
  undefined8 uStack_1a8;
  ulong uStack_1a0;
  long *plStack_198;
  undefined8 *puStack_190;
  byte abStack_188 [16];
  undefined8 uStack_178;
  undefined **ppuStack_170;
  long *plStack_168;
  undefined ***pppuStack_150;
  undefined **ppuStack_140;
  long *plStack_138;
  undefined ***pppuStack_120;
  undefined **ppuStack_110;
  long *plStack_108;
  undefined ***pppuStack_f0;
  undefined **ppuStack_e0;
  long *plStack_d8;
  undefined ***pppuStack_c0;
  undefined **ppuStack_b0;
  long *plStack_a8;
  undefined ***pppuStack_90;
  undefined ***pppuStack_80;
  undefined ***pppuStack_78;
  undefined8 *puStack_70;
  long lStack_68;
  
  lVar6 = tpidr_el0;
  lStack_68 = *(long *)(lVar6 + 0x28);
  plVar1 = param_1 + 0x778a2;
  if (*(char *)((long)param_1 + 0x3bc521) != '\0') {
    func_0x00444220();
    func_0x00445498();
  }
  if ((param_1[0x433] == 0) || (uVar11 = func_0x0083f1a0(), (uVar11 & 1) == 0)) {
    uVar16 = *(undefined4 *)((long)param_1 + 0x343c);
    *(int *)((long)param_1 + 0x3444) = (int)param_1[0x687];
    uVar3 = *(undefined4 *)((long)param_1 + 0x344c);
    *(int *)((long)param_1 + 0x3454) = (int)param_1[0x689];
    *(undefined4 *)(param_1 + 0x687) = uVar16;
    *(undefined4 *)(param_1 + 0x689) = uVar3;
    if (*(char *)((long)param_1 + 0x345c) == '\0') {
      if (*(char *)((long)param_1 + 0x3459) == '\0') {
        *(undefined1 *)((long)param_1 + 0x345b) = 0;
        *(undefined1 *)(param_1 + 0x68b) = 0;
      }
      else {
        *(undefined4 *)((long)param_1 + 0x3444) = uVar16;
        *(undefined4 *)(param_1 + 0x688) = uVar16;
        *(undefined4 *)((long)param_1 + 0x3454) = uVar3;
        *(undefined1 *)((long)param_1 + 0x345d) = 1;
        *(undefined4 *)(param_1 + 0x68b) = 0x10001;
        *(undefined4 *)(param_1 + 0x68a) = uVar3;
      }
    }
    else {
      *(undefined2 *)((long)param_1 + 0x345c) = 0;
      *(undefined4 *)(param_1 + 0x68b) = 0x1000000;
    }
    cVar5 = *(char *)((long)param_1 + 0x345f);
    *(undefined1 *)((long)param_1 + 0x345f) = 0;
    *(char *)((long)param_1 + 0x345e) = cVar5;
    if (cVar5 != '\0') {
      func_0x0045e1c4();
      uVar11 = func_0x0045f0d4();
      if ((uVar11 & 1) != 0) {
        func_0x0045e1c4();
        func_0x0045f140();
        *(undefined1 *)((long)param_1 + 0x345e) = 0;
      }
      *(undefined1 *)(param_1 + 0x68b) = 0;
      *(undefined2 *)((long)param_1 + 0x345a) = 0;
    }
  }
  else {
    *(undefined1 *)((long)param_1 + 0x345c) = 0;
    *(undefined1 *)((long)param_1 + 0x3459) = 0;
    *(undefined1 *)((long)param_1 + 0x345f) = 0;
  }
  *(undefined8 *)((long)param_1 + 0x327dd4) = 0;
  *(undefined8 *)((long)param_1 + 0x327dbc) = 0;
  *(undefined8 *)((long)param_1 + 0x327db4) = 0;
  *(undefined8 *)((long)param_1 + 0x327dcc) = 0;
  *(undefined8 *)((long)param_1 + 0x327dc4) = 0;
  if ((*(char *)((long)param_1 + 0x3bc521) != '\0') &&
     (func_0x009ec8c4(param_1 + 0x182e), (char)param_1[0x64d] == '\0')) {
    unaff_x22 = (undefined ***)&UNK_00425388;
    *(char *)(param_1 + 0x64d) = '\x01';
    iVar9 = func_0x008d748c(param_1 + 0x31e);
    if ((iVar9 != -1) && (dVar19 = (double)func_0x008d74e8(0xc10810), 0.0 < dVar19)) {
      func_0x008d7540(param_1 + 0x31e,1,1);
    }
    if ((int)param_1[0x84a71] == 1) {
      unaff_x22 = (undefined ***)0x421a50;
      if (0.0 < dRam0000000001030980) {
        func_0x00680ba0(param_1 + 0x8434a,0,1,1);
      }
      if (0.0 < dRam0000000001030988) {
        func_0x00680ba0(param_1 + 0x8434a,1,1,1);
      }
    }
    if ((*(char *)((long)param_1 + 0x3269) != '\0') &&
       (iVar9 = func_0x009ede44(param_1 + 0x182e), 0 < iVar9)) {
      func_0x00800498(param_1,1,1);
    }
    func_0x00800704(param_1,1,1);
    uVar11 = func_0x0066887c(param_1 + 0x39e);
    if ((uVar11 & 1) == 0) {
      func_0x0066888c(param_1 + 0x39e,1,1);
    }
  }
  iVar15 = *(int *)((long)param_1 + 0x336c);
  iVar9 = 0;
  if (-1 < *(int *)((long)param_1 + 0x246c)) {
    iVar9 = *(int *)((long)param_1 + 0x246c) + 1;
  }
  *(int *)((long)param_1 + 0x246c) = iVar9;
  if (iVar15 == 0) {
    if ((char)param_1[0x66e] == '\0') goto LAB_0080429c;
    iVar9 = (int)param_1[0x66d];
    *(undefined1 *)(param_1 + 0x66e) = 0;
    if (4 < iVar9) {
      if (iVar9 < 9) {
        if (iVar9 == 5) {
          uVar11 = func_0x0045e31c();
          if ((uVar11 & 1) != 0) {
            *(undefined4 *)((long)param_1 + 0x336c) = 1;
            uVar14 = func_0x0045e1c4();
            func_0x0041ba9c(&pppuStack_80);
            if ((DAT_00c0c0a0 & 1) == 0) {
              pppuStack_230 = (undefined ***)CONCAT71(uRam0000000000c0c0a1,DAT_00c0c0a0);
              plStack_228 = plRam0000000000c0c0a8;
              puStack_220 = puRam0000000000c0c0b0;
            }
            else {
              func_0x0040a850(&pppuStack_230,puRam0000000000c0c0b0,plRam0000000000c0c0a8);
            }
            unaff_x26 = (undefined ***)&pppuStack_230;
            func_0x0040cb78(&bStack_218,&UNK_002a13f2);
            if ((DAT_00c0c070 & 1) == 0) {
              plStack_1f8 = plRam0000000000c0c078;
              uStack_200 = CONCAT71(uRam0000000000c0c071,DAT_00c0c070);
              puStack_1f0 = puRam0000000000c0c080;
            }
            else {
              func_0x0040a850(&uStack_200,puRam0000000000c0c080,plRam0000000000c0c078);
            }
            func_0x0040cb78(abStack_1e8,&UNK_0028f779);
            if ((DAT_00c0c0b8 & 1) == 0) {
              plStack_1c8 = plRam0000000000c0c0c0;
              uStack_1d0 = CONCAT71(uRam0000000000c0c0b9,DAT_00c0c0b8);
              puStack_1c0 = puRam0000000000c0c0c8;
            }
            else {
              func_0x0040a850(&uStack_1d0,puRam0000000000c0c0c8,plRam0000000000c0c0c0);
            }
            unaff_x22 = (undefined ***)abStack_1b8;
            func_0x0040cb78(unaff_x22,&UNK_0028aea8);
            func_0x004449bc(&pppuStack_250,&pppuStack_230,6);
            func_0x00461fbc(uVar14,&pppuStack_80,&pppuStack_250,0);
            func_0x0040f80c(&pppuStack_250);
            if ((abStack_1b8[0] & 1) != 0) {
              func_0x00bc3350(uStack_1a8);
            }
            if ((uStack_1d0 & 1) != 0) {
              func_0x00bc3350(puStack_1c0);
            }
            if ((abStack_1e8[0] & 1) != 0) {
              func_0x00bc3350(uStack_1d8);
            }
            pppuVar18 = pppuStack_208;
            if ((uStack_200 & 1) != 0) {
              func_0x00bc3350(puStack_1f0);
              pppuVar18 = pppuStack_208;
            }
            pppuStack_208 = pppuVar18;
            if ((bStack_218 & 1) != 0) goto LAB_00803e84;
            goto LAB_0080427c;
          }
          uVar14 = func_0x0045e1c4();
          func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
          func_0x0045e320(&pppuStack_230,&pppuStack_80);
          func_0x004643c8(uVar14,&pppuStack_230);
        }
        else {
          if (iVar9 != 7) goto LAB_00803660;
          uVar11 = func_0x0045e31c();
          if ((uVar11 & 1) != 0) {
            *(undefined4 *)((long)param_1 + 0x336c) = 1;
            *(undefined1 *)(param_1 + 0xc3) = 1;
            uVar14 = func_0x0045e1c4();
            func_0x0040cb78(&pppuStack_250,&UNK_0028a069);
            func_0x004641a4(&pppuStack_80,&pppuStack_250);
            if ((DAT_00c0c0a0 & 1) == 0) {
              pppuStack_230 = (undefined ***)CONCAT71(uRam0000000000c0c0a1,DAT_00c0c0a0);
              plStack_228 = plRam0000000000c0c0a8;
              puStack_220 = puRam0000000000c0c0b0;
            }
            else {
              func_0x0040a850(&pppuStack_230,puRam0000000000c0c0b0,plRam0000000000c0c0a8);
            }
            unaff_x26 = (undefined ***)&pppuStack_230;
            func_0x0040cb78(&bStack_218,&UNK_002a13f2);
            if ((DAT_00c0c070 & 1) == 0) {
              plStack_1f8 = plRam0000000000c0c078;
              uStack_200 = CONCAT71(uRam0000000000c0c071,DAT_00c0c070);
              puStack_1f0 = puRam0000000000c0c080;
            }
            else {
              func_0x0040a850(&uStack_200,puRam0000000000c0c080,plRam0000000000c0c078);
            }
            func_0x0040cb78(abStack_1e8,&UNK_0028f779);
            if ((DAT_00c0c0b8 & 1) == 0) {
              plStack_1c8 = plRam0000000000c0c0c0;
              uStack_1d0 = CONCAT71(uRam0000000000c0c0b9,DAT_00c0c0b8);
              puStack_1c0 = puRam0000000000c0c0c8;
            }
            else {
              func_0x0040a850(&uStack_1d0,puRam0000000000c0c0c8,plRam0000000000c0c0c0);
            }
            unaff_x22 = (undefined ***)abStack_1b8;
            func_0x0040cb78(unaff_x22,&UNK_0028aea8);
            func_0x004449bc(abStack_268,&pppuStack_230,6);
            func_0x00461fbc(uVar14,&pppuStack_80,abStack_268,0);
            func_0x0040f80c(abStack_268);
            if ((abStack_1b8[0] & 1) != 0) {
              func_0x00bc3350(uStack_1a8);
            }
            if ((uStack_1d0 & 1) != 0) {
              func_0x00bc3350(puStack_1c0);
            }
            if ((abStack_1e8[0] & 1) != 0) {
              func_0x00bc3350(uStack_1d8);
            }
            if ((uStack_200 & 1) != 0) {
              func_0x00bc3350(puStack_1f0);
            }
            if ((bStack_218 & 1) != 0) {
              func_0x00bc3350(pppuStack_208);
            }
            if (((ulong)pppuStack_230 & 1) != 0) {
              func_0x00bc3350(puStack_220);
            }
            puVar13 = puStack_240;
            pppuVar18 = pppuStack_250;
            if (((ulong)pppuStack_80 & 1) != 0) {
              func_0x00bc3350(puStack_70);
              puVar13 = puStack_240;
              pppuVar18 = pppuStack_250;
            }
            goto joined_r0x00803ef8;
          }
          uVar14 = func_0x0045e1c4();
          func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
          func_0x0045e320(&pppuStack_230,&pppuStack_80);
          func_0x004643c8(uVar14,&pppuStack_230);
        }
        goto LAB_00803a5c;
      }
      if (iVar9 == 9) {
        *(undefined4 *)((long)param_1 + 0x336c) = 1;
        uVar14 = func_0x0045e1c4();
        puStack_70 = (undefined8 *)func_0x00bc3330(0x20);
        puStack_70[1] = 0x7973696b5f32305f;
        *puStack_70 = 0x6e6568757973696b;
        *(undefined8 *)((long)puStack_70 + 0x14) = 0x656c7469745f3330;
        *(undefined8 *)((long)puStack_70 + 0xc) = 0x6e6568757973696b;
        pppuStack_78 = (undefined ***)0x1c;
        pppuStack_80 = (undefined ***)0x21;
        *(undefined1 *)((long)puStack_70 + 0x1c) = 0;
        func_0x004641a4(&pppuStack_230,&pppuStack_80);
        pppuStack_250 = (undefined ***)0x0;
        pppuStack_248 = (undefined ***)0x0;
        puStack_240 = (undefined8 *)0x0;
        func_0x00461fbc(uVar14,&pppuStack_230,&pppuStack_250,0);
        pppuVar12 = pppuStack_250;
        pppuVar18 = pppuStack_250;
        pppuVar8 = pppuStack_248;
        if (pppuStack_250 != (undefined ***)0x0) {
          while (pppuVar7 = pppuVar8, pppuStack_250 = pppuVar18, pppuVar7 != pppuVar12) {
            unaff_x22 = pppuVar7 + -3;
            pppuVar8 = unaff_x22;
            if (((ulong)*unaff_x22 & 1) != 0) {
              func_0x00bc3350(pppuVar7[-1]);
              pppuVar18 = pppuStack_250;
              pppuVar8 = unaff_x22;
            }
          }
          pppuStack_248 = pppuVar12;
LAB_00803e84:
          func_0x00bc3350(pppuVar18);
        }
LAB_0080427c:
        puVar13 = puStack_70;
        pppuVar18 = pppuStack_80;
        if (((ulong)pppuStack_230 & 1) != 0) {
          func_0x00bc3350(puStack_220);
          puVar13 = puStack_70;
          pppuVar18 = pppuStack_80;
        }
joined_r0x00803ef8:
        if (((ulong)pppuVar18 & 1) != 0) {
          func_0x00bc3350(puVar13);
        }
LAB_0080429c:
        iVar15 = *(int *)((long)param_1 + 0x336c);
        if (iVar15 != 2) goto LAB_008042a8;
        goto LAB_0080441c;
      }
      if (iVar9 == 0x14) {
        lVar17 = func_0x00868790(param_1 + 0x5bd);
        if (lVar17 != 0) {
          iVar9 = (int)param_1[0x66d];
          goto LAB_00803660;
        }
        uVar11 = func_0x0045e31c();
        if ((uVar11 & 1) == 0) {
          func_0x0040cb78(&pppuStack_80,&UNK_0028ff79);
          func_0x0045e320(&pppuStack_230,&pppuStack_80);
          unaff_x22 = &ppuStack_b0;
          ppuStack_b0 = (undefined **)&UNK_00be8130;
          plStack_a8 = param_1;
          pppuStack_90 = unaff_x22;
          uVar14 = func_0x00868168(param_1 + 0x5bd,&pppuStack_230,0,0,4,&ppuStack_b0);
          func_0x00866e34(uVar14,0);
          pppuVar18 = pppuStack_90;
          if (pppuStack_90 != &ppuStack_b0) goto LAB_00804268;
          lVar17 = 4;
          pppuVar18 = &ppuStack_b0;
          goto LAB_00804270;
        }
        *(undefined4 *)((long)param_1 + 0x336c) = 1;
        func_0x0041d330(&pppuStack_230);
        uVar14 = func_0x0045e1c4();
        pppuStack_80 = (undefined ***)0x0;
        pppuStack_78 = (undefined ***)0x0;
        puStack_70 = (undefined8 *)0x0;
        func_0x00462864(uVar14,&pppuStack_230,&pppuStack_80,0);
        goto LAB_00803fb0;
      }
LAB_00803660:
      if (iVar9 < 0x21) {
        if (0x15 < iVar9) {
          if (iVar9 == 0x16) {
            uVar11 = func_0x0045e31c();
            if ((uVar11 & 1) != 0) {
              *(undefined4 *)((long)param_1 + 0x336c) = 1;
              uVar14 = func_0x0045e1c4();
              func_0x0041ea80(&pppuStack_230);
              pppuStack_80 = (undefined ***)0x0;
              pppuStack_78 = (undefined ***)0x0;
              puStack_70 = (undefined8 *)0x0;
              func_0x00462864(uVar14,&pppuStack_230,&pppuStack_80,0);
LAB_00803fb0:
              func_0x0040f80c(&pppuStack_80);
              puVar13 = puStack_220;
              pppuVar18 = pppuStack_230;
              goto joined_r0x00803ef8;
            }
            func_0x0040cb78(&pppuStack_80,&UNK_00295981);
            func_0x0045e320(&pppuStack_230,&pppuStack_80);
            pppuStack_120 = &ppuStack_140;
            ppuStack_140 = (undefined **)&UNK_00be82b0;
            plStack_138 = param_1;
            uVar14 = func_0x00868168(param_1 + 0x5bd,&pppuStack_230,0,0,4,&ppuStack_140);
            func_0x00866e34(uVar14,0);
            pppuVar18 = pppuStack_120;
            if (pppuStack_120 == &ppuStack_140) {
              lVar17 = 4;
              pppuVar18 = &ppuStack_140;
            }
            else {
LAB_00804268:
              if (pppuVar18 == (undefined ***)0x0) goto LAB_0080427c;
              lVar17 = 5;
            }
          }
          else {
            if (iVar9 != 0x20) goto LAB_0080429c;
            uVar11 = func_0x0045e31c();
            if ((uVar11 & 1) != 0) {
              *(undefined4 *)((long)param_1 + 0x336c) = 1;
              uVar14 = func_0x0045e1c4();
              func_0x0041e670(&pppuStack_230);
              pppuStack_80 = (undefined ***)0x0;
              pppuStack_78 = (undefined ***)0x0;
              puStack_70 = (undefined8 *)0x0;
              func_0x00462864(uVar14,&pppuStack_230,&pppuStack_80,0);
              goto LAB_00803fb0;
            }
            func_0x0040cb78(&pppuStack_80,&UNK_00295981);
            func_0x0045e320(&pppuStack_230,&pppuStack_80);
            pppuStack_c0 = &ppuStack_e0;
            ppuStack_e0 = (undefined **)&UNK_00be81b0;
            plStack_d8 = param_1;
            uVar14 = func_0x00868168(param_1 + 0x5bd,&pppuStack_230,0,0,4,&ppuStack_e0);
            func_0x00866e34(uVar14,0);
            pppuVar18 = pppuStack_c0;
            if (pppuStack_c0 != &ppuStack_e0) goto LAB_00804268;
            lVar17 = 4;
            pppuVar18 = &ppuStack_e0;
          }
LAB_00804270:
          (*(code *)(*pppuVar18)[lVar17])();
          goto LAB_0080427c;
        }
        if (iVar9 != 0x10) {
          if (iVar9 == 0x15) {
            uVar11 = func_0x0045e31c();
            if ((uVar11 & 1) == 0) {
              func_0x0040cb78(&pppuStack_80,&UNK_00295981);
              func_0x0045e320(&pppuStack_230,&pppuStack_80);
              pppuStack_f0 = &ppuStack_110;
              ppuStack_110 = (undefined **)&UNK_00be8230;
              plStack_108 = param_1;
              uVar14 = func_0x00868168(param_1 + 0x5bd,&pppuStack_230,0,0,4,&ppuStack_110);
              func_0x00866e34(uVar14,0);
              pppuVar18 = pppuStack_f0;
              if (pppuStack_f0 != &ppuStack_110) goto LAB_00804268;
              lVar17 = 4;
              pppuVar18 = &ppuStack_110;
              goto LAB_00804270;
            }
            *(undefined4 *)((long)param_1 + 0x336c) = 1;
            uVar14 = func_0x0045e1c4();
            func_0x0041e878(&pppuStack_230);
            pppuStack_80 = (undefined ***)0x0;
            pppuStack_78 = (undefined ***)0x0;
            puStack_70 = (undefined8 *)0x0;
            func_0x00462864(uVar14,&pppuStack_230,&pppuStack_80,0);
            goto LAB_00803fb0;
          }
          goto LAB_0080429c;
        }
      }
      else if ((1 < iVar9 - 100U) && (iVar9 != 0x21)) {
        if (iVar9 == 0x35) {
          uVar11 = func_0x0045e31c();
          if ((uVar11 & 1) == 0) {
            func_0x0040cb78(&pppuStack_80,&UNK_00295981);
            func_0x0045e320(&pppuStack_230,&pppuStack_80);
            pppuStack_150 = &ppuStack_170;
            ppuStack_170 = (undefined **)&UNK_00be8330;
            plStack_168 = param_1;
            uVar14 = func_0x00868168(param_1 + 0x5bd,&pppuStack_230,0,0,4,&ppuStack_170);
            func_0x00866e34(uVar14,0);
            pppuVar18 = pppuStack_150;
            if (pppuStack_150 != &ppuStack_170) goto LAB_00804268;
            lVar17 = 4;
            pppuVar18 = &ppuStack_170;
            goto LAB_00804270;
          }
          *(undefined4 *)((long)param_1 + 0x336c) = 1;
          if ((DAT_00c0c070 & 1) == 0) {
            plStack_228 = plRam0000000000c0c078;
            pppuStack_230 = (undefined ***)CONCAT71(uRam0000000000c0c071,DAT_00c0c070);
            puStack_220 = puRam0000000000c0c080;
          }
          else {
            func_0x0040a850(&pppuStack_230,puRam0000000000c0c080,plRam0000000000c0c078);
          }
          unaff_x22 = (undefined ***)&pppuStack_230;
          func_0x0040cb78(&bStack_218,&UNK_002a13f2);
          if ((DAT_00c0c070 & 1) == 0) {
            plStack_1f8 = plRam0000000000c0c078;
            uStack_200 = CONCAT71(uRam0000000000c0c071,DAT_00c0c070);
            puStack_1f0 = puRam0000000000c0c080;
          }
          else {
            func_0x0040a850(&uStack_200,puRam0000000000c0c080,plRam0000000000c0c078);
          }
          func_0x0040cb78(abStack_1e8,&UNK_0028ddd5);
          if ((DAT_00c0c0a0 & 1) == 0) {
            plStack_1c8 = plRam0000000000c0c0a8;
            uStack_1d0 = CONCAT71(uRam0000000000c0c0a1,DAT_00c0c0a0);
            puStack_1c0 = puRam0000000000c0c0b0;
          }
          else {
            func_0x0040a850(&uStack_1d0,puRam0000000000c0c0b0,plRam0000000000c0c0a8);
          }
          unaff_x26 = (undefined ***)&pppuStack_230;
          func_0x0040cb78(abStack_1b8,&UNK_0028aea8);
          if ((DAT_00c0c0b8 & 1) == 0) {
            plStack_198 = plRam0000000000c0c0c0;
            uStack_1a0 = CONCAT71(uRam0000000000c0c0b9,DAT_00c0c0b8);
            puStack_190 = puRam0000000000c0c0c8;
          }
          else {
            func_0x0040a850(&uStack_1a0,puRam0000000000c0c0c8,plRam0000000000c0c0c0);
          }
          func_0x0040cb78(abStack_188,&UNK_0028f779);
          func_0x004449bc(&pppuStack_80,&pppuStack_230,8);
          if ((abStack_188[0] & 1) != 0) {
            func_0x00bc3350(uStack_178);
          }
          if ((uStack_1a0 & 1) != 0) {
            func_0x00bc3350(puStack_190);
          }
          if ((abStack_1b8[0] & 1) != 0) {
            func_0x00bc3350(uStack_1a8);
          }
          if ((uStack_1d0 & 1) != 0) {
            func_0x00bc3350(puStack_1c0);
          }
          if ((abStack_1e8[0] & 1) != 0) {
            func_0x00bc3350(uStack_1d8);
          }
          if ((uStack_200 & 1) != 0) {
            func_0x00bc3350(puStack_1f0);
          }
          if ((bStack_218 & 1) != 0) {
            func_0x00bc3350(pppuStack_208);
          }
          if (((ulong)pppuStack_230 & 1) != 0) {
            func_0x00bc3350(puStack_220);
          }
          uVar14 = func_0x0045e1c4();
          func_0x0040cb78(abStack_298,&UNK_0029fa62);
          func_0x0041fdc4(&pppuStack_230,abStack_298);
          func_0x00462864(uVar14,&pppuStack_230,&pppuStack_80,0);
          if (((ulong)pppuStack_230 & 1) != 0) {
            func_0x00bc3350(puStack_220);
          }
          if ((abStack_298[0] & 1) != 0) {
            func_0x00bc3350(uStack_288);
          }
          func_0x0040f80c(&pppuStack_80);
        }
        goto LAB_0080429c;
      }
      uVar11 = func_0x0045e31c();
      if ((uVar11 & 1) == 0) {
        uVar14 = func_0x0045e1c4();
        func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
        func_0x0045e320(&pppuStack_230,&pppuStack_80);
        func_0x004643c8(uVar14,&pppuStack_230);
        puVar13 = puStack_70;
        pppuVar18 = pppuStack_80;
        if (((ulong)pppuStack_230 & 1) != 0) {
          func_0x00bc3350(puStack_220);
          puVar13 = puStack_70;
          pppuVar18 = pppuStack_80;
        }
joined_r0x00803b60:
        if (((ulong)pppuVar18 & 1) != 0) {
          func_0x00bc3350(puVar13);
        }
        *(undefined4 *)((long)param_1 + 0x336c) = 0;
        func_0x0045e1c4();
        uVar11 = func_0x0045f0d4();
        if ((uVar11 & 1) == 0) {
          *(undefined4 *)(param_1 + 0x66d) = 0xffffffff;
        }
      }
      else {
        uVar11 = func_0x0044480c();
        iVar9 = iRam0000000000c12288;
        if ((uVar11 & 1) == 0) {
          uVar14 = func_0x0045e1c4();
          func_0x0040cb78(&pppuStack_250,&UNK_0028dd75);
          func_0x0045e320(&pppuStack_80,&pppuStack_250);
          func_0x0040cb78(abStack_268,&UNK_002a44d2);
          func_0x0040cb78(abStack_280,&UNK_0029d009);
          func_0x0073b8bc(&pppuStack_230,&pppuStack_80,abStack_268,abStack_280,0);
          func_0x004643c8(uVar14,&pppuStack_230);
          if (((ulong)pppuStack_230 & 1) != 0) {
            func_0x00bc3350(puStack_220);
          }
          if ((abStack_280[0] & 1) != 0) {
            func_0x00bc3350(uStack_270);
          }
          if ((abStack_268[0] & 1) != 0) {
            func_0x00bc3350(uStack_258);
          }
          puVar13 = puStack_240;
          pppuVar18 = pppuStack_250;
          if (((ulong)pppuStack_80 & 1) != 0) {
            func_0x00bc3350(puStack_70);
            puVar13 = puStack_240;
            pppuVar18 = pppuStack_250;
          }
          goto joined_r0x00803b60;
        }
        *(undefined4 *)((long)param_1 + 0x336c) = 1;
        if (iVar9 - 100U < 2) {
          lVar17 = func_0x006ffa70(param_1 + 0x5c7,iVar9 != 100);
          if (lVar17 != 0) {
            uVar14 = func_0x0045e1c4();
            func_0x0041a048(abStack_268);
            puVar13 = (undefined8 *)func_0x00bc3410(abStack_268,&UNK_0028e830);
            puStack_240 = (undefined8 *)puVar13[2];
            pppuStack_248 = (undefined ***)puVar13[1];
            pppuStack_250 = (undefined ***)*puVar13;
            puVar13[1] = 0;
            puVar13[2] = 0;
            *puVar13 = 0;
            func_0x00420eb0(&pppuStack_80,&pppuStack_250,lVar17 + 0x28);
            puVar13 = (undefined8 *)func_0x00bc3410(&pppuStack_80,&UNK_0029be49);
            puStack_220 = (undefined8 *)puVar13[2];
            plStack_228 = (long *)puVar13[1];
            pppuStack_230 = (undefined ***)*puVar13;
            puVar13[1] = 0;
            puVar13[2] = 0;
            *puVar13 = 0;
            func_0x0040cb78(abStack_280,&UNK_002a06d1);
            func_0x004635c0(uVar14,&pppuStack_230,abStack_280);
            if ((abStack_280[0] & 1) != 0) {
              func_0x00bc3350(uStack_270);
            }
            if (((ulong)pppuStack_230 & 1) != 0) {
              func_0x00bc3350(puStack_220);
            }
            if (((ulong)pppuStack_80 & 1) != 0) {
              func_0x00bc3350(puStack_70);
            }
            if (((ulong)pppuStack_250 & 1) != 0) {
              func_0x00bc3350(puStack_240);
            }
            if ((abStack_268[0] & 1) != 0) {
              func_0x00bc3350(uStack_258);
            }
          }
        }
        else if (iVar9 == 0x10) {
          uVar11 = func_0x006ff154(0xc11d58);
          if ((uVar11 & 1) != 0) {
            uVar14 = func_0x0045e1c4();
            func_0x0040cb78(&pppuStack_80,&UNK_0028cc43);
            func_0x0041a048(abStack_2b0);
            func_0x006ff164(0xc11d58);
            lVar17 = func_0x006fb438();
            if ((*(byte *)(lVar17 + 0x28) & 1) == 0) {
              uStack_2c8 = *(undefined8 *)(lVar17 + 0x30);
              uStack_2d0 = *(ulong *)(lVar17 + 0x28);
              uStack_2c0 = *(undefined8 *)(lVar17 + 0x38);
            }
            else {
              func_0x0040a850(&uStack_2d0,*(undefined8 *)(lVar17 + 0x38),
                              *(undefined8 *)(lVar17 + 0x30));
            }
            func_0x0040d5b8(&pppuStack_230,&pppuStack_80,abStack_2b0,&uStack_2d0);
            func_0x0040cb78(&pppuStack_250,&UNK_002a06d1);
            func_0x004635c0(uVar14,&pppuStack_230,&pppuStack_250);
            if (((ulong)pppuStack_250 & 1) != 0) {
              func_0x00bc3350(puStack_240);
            }
            if (((ulong)pppuStack_230 & 1) != 0) {
              func_0x00bc3350(puStack_220);
            }
            uStack_2d8 = uStack_2a0;
            abStack_2e8[0] = abStack_2b0[0];
            if ((uStack_2d0 & 1) != 0) {
              func_0x00bc3350(uStack_2c0);
              uStack_2d8 = uStack_2a0;
              abStack_2e8[0] = abStack_2b0[0];
            }
            goto joined_r0x00805154;
          }
        }
        else if (iVar9 == 0x21) {
          uVar14 = func_0x0045e1c4();
          func_0x0040cb78(&pppuStack_80,&UNK_0028cc43);
          func_0x0041a048(abStack_2e8);
          lVar17 = func_0x006fb464(param_1 + 0x5c7,0x327);
          if ((*(byte *)(lVar17 + 0x28) & 1) == 0) {
            uStack_2f8 = *(undefined8 *)(lVar17 + 0x30);
            uStack_300 = *(ulong *)(lVar17 + 0x28);
            uStack_2f0 = *(undefined8 *)(lVar17 + 0x38);
          }
          else {
            func_0x0040a850(&uStack_300,*(undefined8 *)(lVar17 + 0x38),
                            *(undefined8 *)(lVar17 + 0x30));
          }
          func_0x0040d5b8(&pppuStack_230,&pppuStack_80,abStack_2e8,&uStack_300);
          func_0x0040cb78(&pppuStack_250,&UNK_002a06d1);
          func_0x004635c0(uVar14,&pppuStack_230,&pppuStack_250);
          if (((ulong)pppuStack_250 & 1) != 0) {
            func_0x00bc3350(puStack_240);
          }
          if (((ulong)pppuStack_230 & 1) != 0) {
            func_0x00bc3350(puStack_220);
          }
          if ((uStack_300 & 1) != 0) {
            func_0x00bc3350(uStack_2f0);
          }
joined_r0x00805154:
          if ((abStack_2e8[0] & 1) != 0) {
            func_0x00bc3350(uStack_2d8);
          }
          if (((ulong)pppuStack_80 & 1) != 0) {
            func_0x00bc3350(puStack_70);
          }
        }
      }
      goto LAB_0080441c;
    }
    if (iVar9 == 0) {
      uVar11 = func_0x0045e31c();
      if ((uVar11 & 1) == 0) {
        uVar14 = func_0x0045e1c4();
        func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
        func_0x0045e320(&pppuStack_230,&pppuStack_80);
        func_0x004643c8(uVar14,&pppuStack_230);
        goto LAB_00803a5c;
      }
      uVar11 = func_0x0044480c();
      if ((uVar11 & 1) != 0) {
        *(undefined4 *)((long)param_1 + 0x336c) = 1;
        uVar14 = func_0x0045e1c4();
        func_0x0040cb78(&pppuStack_80,&UNK_002a8999);
        func_0x0045e320(&pppuStack_230,&pppuStack_80);
        func_0x00464b30(uVar14,&pppuStack_230);
        if (((ulong)pppuStack_230 & 1) != 0) {
          func_0x00bc3350(puStack_220);
        }
        if (((ulong)pppuStack_80 & 1) != 0) {
          func_0x00bc3350(puStack_70);
        }
        uVar14 = func_0x00444220();
        func_0x00444b0c(uVar14,&DAT_0107a988);
        if (param_1[0x433] != 0) {
          func_0x0083df10();
        }
        func_0x00a0b124(0xd,0,0,0,0);
        goto LAB_0080441c;
      }
      uVar14 = func_0x0045e1c4();
      func_0x0040cb78(&pppuStack_250,&UNK_0028dd75);
      func_0x0045e320(&pppuStack_80,&pppuStack_250);
      func_0x0040cb78(abStack_268,&UNK_002a44d2);
      func_0x0040cb78(abStack_280,&UNK_0029d009);
      func_0x0073b8bc(&pppuStack_230,&pppuStack_80,abStack_268,abStack_280,0);
      func_0x004643c8(uVar14,&pppuStack_230);
      if (((ulong)pppuStack_230 & 1) != 0) {
        func_0x00bc3350(puStack_220);
      }
      if ((abStack_280[0] & 1) != 0) {
        func_0x00bc3350(uStack_270);
      }
      if ((abStack_268[0] & 1) != 0) {
        func_0x00bc3350(uStack_258);
      }
      puVar13 = puStack_240;
      pppuVar18 = pppuStack_250;
      if (((ulong)pppuStack_80 & 1) != 0) {
        func_0x00bc3350(puStack_70);
        puVar13 = puStack_240;
        pppuVar18 = pppuStack_250;
      }
    }
    else {
      if (iVar9 == 2) {
        uVar11 = func_0x0045e31c();
        if ((uVar11 & 1) != 0) {
          *(undefined4 *)((long)param_1 + 0x336c) = 1;
          uRam0000000000c0ffd0 = 0;
          uVar14 = func_0x0041b894(&pppuStack_230);
          func_0x007ebde4(uVar14,&pppuStack_230,1);
          puVar13 = puStack_220;
          pppuVar18 = pppuStack_230;
          goto joined_r0x00803ef8;
        }
        uVar14 = func_0x0045e1c4();
        func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
        func_0x0045e320(&pppuStack_230,&pppuStack_80);
        func_0x004643c8(uVar14,&pppuStack_230);
      }
      else {
        if (iVar9 != 3) goto LAB_00803660;
        uVar11 = func_0x0045e31c();
        if ((uVar11 & 1) != 0) {
          *(undefined4 *)((long)param_1 + 0x336c) = 1;
          goto LAB_0080441c;
        }
        uVar14 = func_0x0045e1c4();
        func_0x0040cb78(&pppuStack_80,&UNK_0029cfd3);
        func_0x0045e320(&pppuStack_230,&pppuStack_80);
        func_0x004643c8(uVar14,&pppuStack_230);
      }
LAB_00803a5c:
      puVar13 = puStack_70;
      pppuVar18 = pppuStack_80;
      if (((ulong)pppuStack_230 & 1) != 0) {
        func_0x00bc3350(puStack_220);
        puVar13 = puStack_70;
        pppuVar18 = pppuStack_80;
      }
    }
    if (((ulong)pppuVar18 & 1) != 0) {
      func_0x00bc3350(puVar13);
    }
    lVar17 = *param_1;
    *(undefined4 *)((long)param_1 + 0x336c) = 0;
    goto LAB_00804420;
  }
  if (iVar15 == 2) goto LAB_0080441c;
LAB_008042a8:
  if (iVar15 == 1) goto LAB_0080441c;
  unaff_x22 = (undefined ***)((long)param_1 + 0x3bb904);
  unaff_x26 = (undefined ***)(param_1 + 0x6569b);
  func_0x0056a654(&pppuStack_230);
  param_1[0x6503b] = (long)plStack_228;
  param_1[0x6503a] = (long)pppuStack_230;
  param_1[0x6503d] = CONCAT71(uStack_217,bStack_218);
  param_1[0x6503c] = (long)puStack_220;
  param_1[0x6503f] = (long)pppuStack_208;
  param_1[0x6503e] = (long)pppuStack_210;
  param_1[0x65041] = (long)plStack_1f8;
  param_1[0x65040] = uStack_200;
  if (((*(char *)((long)param_1 + 0x32a4cc) == '\0') && (*(byte *)unaff_x26 == 0)) &&
     (*(char *)((long)param_1 + 0x3bc521) != '\0')) {
    func_0x009ef104(param_1);
  }
  iVar15 = 2000000000;
  iVar20 = (int)param_1[0x71fa9];
  iVar21 = (int)((ulong)param_1[0x71fa9] >> 0x20);
  uVar11 = CONCAT44(iVar21 + 1,iVar20 + 1);
  iVar9 = 0;
  if ((int)param_1[0x658da] < 0x1d) {
    iVar9 = (int)param_1[0x658da] + 1;
  }
  *(int *)(param_1 + 0x658da) = iVar9;
  if (*(int *)unaff_x22 < 2000000000) {
    iVar15 = *(int *)unaff_x22 + 1;
  }
  *(int *)unaff_x22 = iVar15;
  param_1[0x71fa9] =
       uVar11 ^ (uVar11 ^ 0x1a5e00001a5e0) &
                CONCAT44(-(uint)(0x1a5de < iVar21),-(uint)(0x1a5de < iVar20));
  if (((param_1[0x77722] != -0x8000000000000000) &&
      (lVar17 = func_0x00bc3a00(), lVar17 < param_1[0x77722])) || ((int)param_1[0x68c] - 0x65U < 3))
  goto LAB_00804398;
  iVar9 = (int)param_1[0x77721];
  if (iVar9 < 5) {
    if (iVar9 == 1) {
      *(undefined4 *)(param_1 + 0x77721) = 2;
      uVar14 = func_0x00420ad4();
      func_0x0072cd44(&pppuStack_230,param_1);
      func_0x00420f00(uVar14,&pppuStack_230);
LAB_00804604:
      if (((ulong)pppuStack_230 & 1) != 0) {
        func_0x00bc3350(puStack_220);
      }
    }
    else if (iVar9 == 3) {
      uVar11 = func_0x00805ea8(param_1);
      if ((uVar11 & 1) == 0) {
        *(undefined4 *)(param_1 + 0x77721) = 4;
        func_0x005332dc(&pppuStack_250);
        pppuStack_78 = pppuStack_248;
        pppuStack_80 = pppuStack_250;
        pppuStack_250 = (undefined ***)0x0;
        pppuStack_248 = (undefined ***)0x0;
        pppuStack_230 = (undefined ***)&UNK_00be83b0;
        plStack_228 = param_1;
        pppuStack_210 = (undefined ***)&pppuStack_230;
        func_0x0082e060(param_1 + 0x71ec8,&pppuStack_80,&pppuStack_230);
        if ((undefined ****)pppuStack_210 == &pppuStack_230) {
          lVar17 = 4;
          pppuVar18 = (undefined ***)&pppuStack_230;
LAB_00804830:
          (*(code *)(*pppuVar18)[lVar17])();
        }
        else if (pppuStack_210 != (undefined ***)0x0) {
          lVar17 = 5;
          pppuVar18 = pppuStack_210;
          goto LAB_00804830;
        }
        func_0x004453f8(&pppuStack_80);
        func_0x00445448(&pppuStack_250);
      }
      else {
        uVar16 = 5;
LAB_00804704:
        *(undefined4 *)(param_1 + 0x77721) = uVar16;
      }
    }
  }
  else {
    if (iVar9 != 5) {
      if (iVar9 == 7) {
        bVar4 = *(byte *)(param_1 + 0x77726);
        uVar11 = (ulong)(bVar4 >> 1);
        if ((bVar4 & 1) != 0) {
          uVar11 = param_1[0x77727];
        }
        if (uVar11 == 0) {
          uVar16 = 9;
          goto LAB_00804704;
        }
        *(undefined4 *)(param_1 + 0x77721) = 8;
        param_1[0x48d] = 0;
        unaff_x22 = (undefined ***)func_0x00420ad4();
        func_0x0072cd44(&pppuStack_230,param_1);
        func_0x0072d8b8(&pppuStack_80,param_1);
        func_0x00730388(&pppuStack_250,param_1);
        func_0x00428100(unaff_x22,&pppuStack_230,&pppuStack_80,param_1 + 0x77726,&pppuStack_250);
        func_0x004218fc(&pppuStack_250);
        if (((ulong)pppuStack_80 & 1) != 0) {
          func_0x00bc3350(puStack_70);
        }
        goto LAB_00804604;
      }
      goto LAB_00804398;
    }
    *(undefined4 *)(param_1 + 0x77721) = 6;
    uVar14 = func_0x00420ad4();
    func_0x0072cd44(&pppuStack_80,param_1);
    func_0x0072d8b8(&pppuStack_250,param_1);
    unaff_x22 = (undefined ***)&pppuStack_230;
    pppuStack_230 = (undefined ***)&UNK_00be8430;
    plStack_228 = param_1;
    pppuStack_210 = unaff_x22;
    func_0x0042752c(uVar14,&pppuStack_80,&pppuStack_250,&pppuStack_230);
    if (pppuStack_210 == unaff_x22) {
      lVar17 = 4;
      pppuVar18 = (undefined ***)&pppuStack_230;
LAB_00804714:
      (*(code *)(*pppuVar18)[lVar17])();
    }
    else if (pppuStack_210 != (undefined ***)0x0) {
      lVar17 = 5;
      pppuVar18 = pppuStack_210;
      goto LAB_00804714;
    }
    if (((ulong)pppuStack_250 & 1) != 0) {
      func_0x00bc3350(puStack_240);
    }
    if (((ulong)pppuStack_80 & 1) != 0) {
      func_0x00bc3350(puStack_70);
    }
  }
LAB_00804398:
  uVar10 = func_0x0068dcf4(param_1 + 0x803f2);
  func_0x00835b80(param_1[0x432]);
  uVar11 = func_0x008357b8(param_1[0x432]);
  if ((uVar11 & 1) != 0) goto LAB_0080441c;
  unaff_x22 = (undefined ***)0x2de8;
  func_0x008687bc(param_1 + 0x5bd);
  func_0x00864ab8(param_1 + 0x5c3);
  func_0x00a256d0(param_1 + 0x32e);
  func_0x007d6d24(param_1 + 0x657f7);
  if ((*(char *)((long)param_1 + 0x32a4cc) != '\0') ||
     ((uVar10 & 1) != 0 || *(byte *)unaff_x26 != 0)) goto LAB_0080440c;
  iVar9 = (int)param_1[0x68c];
  plVar2 = param_1 + 0x650b3;
  if (iVar9 < 99) {
    if (0x5d < iVar9) {
      if (iVar9 != 0x5e) {
        if (iVar9 == 0x61) {
          uVar11 = func_0x0046692c();
          if (((uVar11 & 1) == 0) && (lVar17 = func_0x00868790(param_1 + 0x5bd), lVar17 == 0)) {
            param_1[0x68c] = 0x6200000062;
            func_0x009f9ff4(param_1);
          }
        }
        else if (iVar9 != 0x62) goto LAB_0080440c;
        uVar11 = func_0x008d28f0(param_1);
        goto joined_r0x00804a9c;
      }
      lVar17 = *plVar2;
      *(int *)plVar2 = (int)lVar17 + 1;
      if (0x1c < (int)lVar17) {
        uVar10 = 1;
        *(undefined1 *)(param_1 + 0x66e) = 1;
        *(undefined4 *)(param_1 + 0x66d) = 9;
        goto LAB_0080442c;
      }
      goto LAB_0080440c;
    }
    if (iVar9 == 5) {
      iVar9 = func_0x0045e1ac(param_1 + 0x65988);
      if (iVar9 != 0) goto LAB_0080440c;
      uVar14 = func_0x0045e1c4();
      func_0x0040cb78(&pppuStack_80,&UNK_00292e8f);
      func_0x0045e320(&pppuStack_230,&pppuStack_80);
      func_0x0045f0e8(uVar14,&pppuStack_230);
      if (((ulong)pppuStack_230 & 1) != 0) {
        func_0x00bc3350(puStack_220);
      }
      if (((ulong)pppuStack_80 & 1) != 0) {
        func_0x00bc3350(puStack_70);
      }
      func_0x0040cb78(&pppuStack_250,&UNK_002987f0);
      func_0x0040cb78(abStack_280,&UNK_0028af60);
      func_0x0045e320(abStack_268,abStack_280);
      func_0x0040cb78(abStack_330,&UNK_002a6472);
      func_0x0040cb78(abStack_348,&UNK_0029d009);
      func_0x0073b8bc(abStack_318,abStack_268,abStack_330,abStack_348,0);
      func_0x005a5ed4(&pppuStack_80,&pppuStack_250,abStack_318,0x24c49,(int)param_1[0x6592e]);
      func_0x0045e320(&pppuStack_230,&pppuStack_80);
      if (((ulong)pppuStack_80 & 1) != 0) {
        func_0x00bc3350(puStack_70);
      }
      if ((abStack_318[0] & 1) != 0) {
        func_0x00bc3350(uStack_308);
      }
      if ((abStack_348[0] & 1) != 0) {
        func_0x00bc3350(uStack_338);
      }
      if ((abStack_330[0] & 1) != 0) {
        func_0x00bc3350(uStack_320);
      }
      if ((abStack_268[0] & 1) != 0) {
        func_0x00bc3350(uStack_258);
      }
      if ((abStack_280[0] & 1) != 0) {
        func_0x00bc3350(uStack_270);
      }
      if (((ulong)pppuStack_250 & 1) != 0) {
        func_0x00bc3350(puStack_240);
      }
      uVar14 = func_0x0045e1c4();
      func_0x0040cb78(&pppuStack_250,&UNK_0028ff93);
      func_0x0045e320(&pppuStack_80,&pppuStack_250);
      func_0x004644a8(auStack_358,uVar14,&pppuStack_230,&pppuStack_80,1,param_1 + 0x65988);
      func_0x0044ba30(auStack_358);
      if (((ulong)pppuStack_80 & 1) != 0) {
        func_0x00bc3350(puStack_70);
      }
      if (((ulong)pppuStack_250 & 1) != 0) {
        func_0x00bc3350(puStack_240);
      }
      if (((ulong)pppuStack_230 & 1) != 0) {
        func_0x00bc3350(puStack_220);
      }
    }
    else {
      if ((iVar9 != 0x5a) ||
         (lVar17 = *plVar2, *(int *)plVar2 = (int)lVar17 + 1, (int)lVar17 < 0x96))
      goto LAB_0080440c;
      (**(code **)(*param_1 + 0x38))(param_1);
      func_0x007fdc0c(param_1,0x61);
      func_0x00606b54(param_1 + 0xe70);
      func_0x00606b54(param_1 + 0xe72);
    }
    goto LAB_00804548;
  }
  if (0x65 < iVar9) {
    if (iVar9 == 0x66) {
      iVar9 = (int)*plVar2;
      *(int *)plVar2 = iVar9 + 1;
      *(undefined8 *)((long)param_1 + 0x3285a4) = 0xa0000000a;
      *(undefined8 *)((long)param_1 + 0x32859c) = 0x500000064;
      *(undefined4 *)((long)param_1 + 0x3285ac) = 5;
      if ((*(char *)((long)param_1 + 0x345a) == '\0') || (0x53 < iVar9)) {
        if (0x62 < iVar9) {
          (**(code **)(*param_1 + 0x38))(param_1);
          func_0x007fdc0c(param_1,0x65);
          goto LAB_00804548;
        }
      }
      else {
        *(int *)plVar2 = 0x55;
      }
      goto LAB_0080440c;
    }
    if (iVar9 == 300) {
      uVar11 = Battle_MainUpdateLoop(param_1);
      goto joined_r0x00804a9c;
    }
    if (iVar9 != 999) goto LAB_0080440c;
    goto LAB_0080475c;
  }
  if (iVar9 == 99) {
    uVar11 = func_0x00641b88(param_1);
    goto joined_r0x00804a9c;
  }
  if (iVar9 != 100) {
    if (iVar9 == 0x65) {
      if ((long *)*plVar1 != (long *)0x0) {
        uVar11 = (**(code **)(*(long *)*plVar1 + 0x20))();
        if ((uVar11 & 1) != 0) {
          *(undefined1 *)((long)param_1 + 0x3bc521) = 1;
          func_0x009ec4d8(param_1 + 0x182e);
          uVar14 = func_0x00420ad4();
          func_0x00420b1c(uVar14,param_1 + 0x71ec8);
          func_0x00420ad4();
          func_0x00420b24();
          unaff_x22 = (undefined ***)param_1[0x46a];
          for (pppuVar18 = (undefined ***)param_1[0x469]; pppuVar18 != unaff_x22;
              pppuVar18 = pppuVar18 + 6) {
            func_0x00805f10(&pppuStack_230,pppuVar18);
            if (pppuStack_210 == (undefined ***)0x0) {
              if (*(long *)(lVar6 + 0x28) == lStack_68) {
                uVar14 = func_0x0042af50();
                if (((ulong)pppuStack_250 & 1) != 0) {
                  func_0x00bc3350(puStack_240);
                }
                if (((ulong)pppuStack_230 & 1) != 0) {
                  func_0x00bc3350(puStack_220);
                }
                if ((uStack_2d0 & 1) != 0) {
                  func_0x00bc3350(uStack_2c0);
                }
                if ((abStack_2b0[0] & 1) != 0) {
                  func_0x00bc3350(uStack_2a0);
                }
                puVar13 = puStack_70;
                if (((ulong)pppuStack_80 & 1) == 0) goto LAB_00805e28;
                goto LAB_00805e24;
              }
              goto LAB_00805e40;
            }
            (*(code *)(*pppuStack_210)[6])();
            if ((undefined ****)pppuStack_210 == &pppuStack_230) {
              pppuVar12 = (undefined ***)&pppuStack_230;
              lVar17 = 4;
LAB_00804778:
              (*(code *)(*pppuVar12)[lVar17])();
            }
            else if (pppuStack_210 != (undefined ***)0x0) {
              lVar17 = 5;
              pppuVar12 = pppuStack_210;
              goto LAB_00804778;
            }
          }
          uVar16 = 0x5a;
          if (*(char *)((long)param_1 + 0x10b1) != '\0') {
            uVar16 = 0x68;
          }
          func_0x007fdc0c(param_1,uVar16);
          func_0x00805f78(plVar1);
          goto LAB_00804548;
        }
        if ((*plVar1 != 0) && (*(char *)(*plVar1 + 9) != '\0')) {
          *(undefined4 *)((long)param_1 + 0x3304) = 7;
          func_0x007fdc0c(param_1,4);
          func_0x00805f78(plVar1);
        }
      }
      goto LAB_0080441c;
    }
    goto LAB_0080440c;
  }
  if (*(int *)((long)param_1 + 0x328564) != -1) {
    if (*(int *)((long)param_1 + 0x328564) < 1) goto LAB_0080475c;
    goto LAB_0080531c;
  }
  iVar9 = *(int *)((long)param_1 + 0x32855c);
  if (0x270e < iVar9) {
    if (iVar9 < 0x186a1) {
      if (iVar9 != 9999) {
        if (iVar9 == 99999) {
          func_0x009c8f30(param_1);
        }
        else if (iVar9 == 100000) {
          func_0x0071be88(param_1);
          goto LAB_00805310;
        }
        goto LAB_00805314;
      }
      func_0x009d4c34(param_1);
    }
    else if (iVar9 == 0x186a1) {
      func_0x008bfb70(param_1);
    }
    else if (iVar9 == 0x186a2) {
      func_0x009da764(param_1);
    }
    else {
      if (iVar9 != 999999) goto LAB_00805314;
      func_0x006368b4(param_1);
    }
    goto LAB_00805310;
  }
  switch(iVar9) {
  case 0:
    func_0x009f17bc(param_1);
    break;
  default:
    goto LAB_00805314;
  case 3:
    func_0x00a36a70(param_1);
    break;
  case 5:
    func_0x00727608(param_1,1);
    break;
  case 6:
    func_0x00a19d48(param_1);
    break;
  case 7:
    func_0x0093294c(param_1);
    break;
  case 8:
    func_0x00647d88(param_1);
    break;
  case 9:
    uVar11 = func_0x0076b4a8(param_1);
    if ((uVar11 & 1) == 0) goto LAB_00804548;
    break;
  case 10:
    func_0x00877c78(param_1);
    break;
  case 0xb:
    func_0x008a42bc(param_1);
    break;
  case 0xc:
    func_0x0067d2d0(param_1);
    break;
  case 0xd:
    func_0x0096bacc(param_1);
    break;
  case 0xe:
    func_0x005f3a28(param_1);
    goto LAB_00805314;
  case 0xf:
    func_0x007d7be8(param_1);
    break;
  case 0x10:
    func_0x0087eca0(param_1);
    break;
  case 0x11:
    func_0x0088af7c(param_1);
    break;
  case 0x12:
    func_0x00a26454(param_1);
    break;
  case 0x13:
    func_0x009a5c50(param_1);
    break;
  case 0x14:
    func_0x0075125c(param_1);
    break;
  case 0x15:
    func_0x00704518(param_1);
    break;
  case 0x16:
    func_0x008ac560(param_1);
  }
LAB_00805310:
  func_0x006885dc();
LAB_00805314:
  *(undefined4 *)((long)param_1 + 0x328564) = 1;
LAB_0080531c:
  iVar9 = *(int *)((long)param_1 + 0x32855c);
  if (0x270e < iVar9) {
    if (iVar9 < 0x186a1) {
      if (iVar9 == 9999) {
        uVar11 = func_0x009d5278(param_1);
      }
      else if (iVar9 == 99999) {
        uVar11 = func_0x009c94ec(param_1);
      }
      else {
        if (iVar9 != 100000) goto LAB_00805508;
        uVar11 = func_0x0071c624(param_1);
      }
    }
    else if (iVar9 == 0x186a1) {
      uVar11 = func_0x008c2e30(param_1);
    }
    else if (iVar9 == 0x186a2) {
      uVar11 = func_0x009dd138(param_1);
    }
    else {
      if (iVar9 != 999999) goto LAB_00805508;
      uVar11 = func_0x006390a8(param_1);
    }
    goto joined_r0x008054f0;
  }
  switch(iVar9) {
  case 0:
    uVar11 = func_0x009f5878(param_1);
    break;
  default:
    goto LAB_00805508;
  case 3:
    uVar11 = func_0x00a3cc0c(param_1);
    break;
  case 5:
    uVar11 = func_0x00731fa4(param_1);
    break;
  case 6:
    uVar11 = func_0x00a1a1c4(param_1);
    break;
  case 7:
    uVar11 = func_0x0093b018(param_1);
    break;
  case 8:
    uVar11 = func_0x00649600(param_1);
    break;
  case 9:
    uVar11 = func_0x00779e58(param_1);
    break;
  case 10:
    uVar11 = func_0x008783fc(param_1);
    break;
  case 0xb:
    uVar11 = func_0x008a4660(param_1);
    break;
  case 0xc:
    uVar11 = func_0x0067d664(param_1);
    break;
  case 0xd:
    uVar11 = func_0x0096bed4(param_1);
    break;
  case 0xe:
    uVar11 = func_0x005f3a54(param_1);
    break;
  case 0xf:
    uVar11 = func_0x007d7eec(param_1);
    break;
  case 0x10:
    uVar11 = func_0x00880268(param_1);
    break;
  case 0x15:
    uVar11 = func_0x00705484(param_1);
  }
joined_r0x008054f0:
  if ((uVar11 & 1) != 0) {
    iVar9 = *(int *)((long)param_1 + 0x32855c);
LAB_00805508:
    if (iVar9 < 0x13) {
      if (iVar9 == 0x11) {
        uVar11 = func_0x0088b284(param_1);
        goto joined_r0x00805580;
      }
      if (iVar9 == 0x12) {
        uVar11 = func_0x00a268fc(param_1);
        goto joined_r0x00805580;
      }
    }
    else {
      if (iVar9 == 0x13) {
        uVar11 = func_0x009a6014(param_1);
      }
      else {
        if (iVar9 != 0x14) {
          if ((iVar9 != 0x16) || (uVar11 = func_0x008ac8ac(param_1), (uVar11 & 1) != 0))
          goto LAB_0080475c;
          goto LAB_00804548;
        }
        uVar11 = func_0x00752218(param_1);
      }
joined_r0x00805580:
      if ((uVar11 & 1) == 0) goto LAB_00804548;
    }
LAB_0080475c:
    uVar11 = func_0x00685844(param_1,(int)param_1[0x64cc6]);
joined_r0x00804a9c:
    if ((uVar11 & 1) != 0) {
LAB_0080440c:
      if (*(byte *)unaff_x26 == 0) {
        func_0x008f4a10(param_1);
        if ((char)param_1[0x6598b] != '\0') {
          *(undefined1 *)(param_1 + 0x6598b) = 0;
          goto LAB_00804548;
        }
      }
      else {
        func_0x00a29e7c(param_1);
      }
LAB_0080441c:
      lVar17 = *param_1;
LAB_00804420:
      uVar10 = (**(code **)(lVar17 + 0x38))(param_1);
      goto LAB_0080442c;
    }
  }
LAB_00804548:
  uVar10 = 1;
LAB_0080442c:
  if (*(long *)(lVar6 + 0x28) == lStack_68) {
    return uVar10 & 1;
  }
LAB_00805e40:
  do {
    uVar14 = func_0x00bc3380();
    pppuVar18 = unaff_x22;
    do {
      unaff_x22 = pppuVar18 + -3;
      if (((ulong)*unaff_x22 & 1) != 0) {
        func_0x00bc3350(pppuVar18[-1]);
      }
      pppuVar18 = unaff_x22;
    } while (unaff_x22 != unaff_x26);
    if (((ulong)pppuStack_80 & 1) != 0) {
      func_0x00bc3350(puStack_70);
    }
    puVar13 = puStack_240;
    if (((ulong)pppuStack_250 & 1) != 0) {
LAB_00805e24:
      func_0x00bc3350(puVar13);
    }
LAB_00805e28:
    if (*(long *)(lVar6 + 0x28) == lStack_68) {
      func_0x00bbf40c(uVar14);
    }
  } while( true );
}


