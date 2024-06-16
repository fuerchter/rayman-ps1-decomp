#include "fond_10B3C.h"

/* give m2c another go? */
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondSprites);*/

void PS1_LoadFondSprites(void)

{
  u8 bVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  u_char uVar5;
  short sVar6;
  short sVar7;
  u_char uVar8;
  u_char uVar9;
  u_short uVar10;
  Sprite *puVar5;
  SPRT *pSVar11;
  SPRT *pSVar12;
  SPRT *p_01;
  SPRT *p_00;
  DR_ENV *dr_env;
  u8 bVar13;
  DR_ENV *local_30;
  Display *disp_1; Display *disp_2;
  
  PS1_BackgroundPositions = PS1_LevelBGBlock->sprite_positions;
  PS1_BackgroundSprites = PS1_LevelBGBlock->sprites;
  if (PS1_FondType == 6 || PS1_FondType == 7) {
    dr_env = PS1_Display1.field6_0x2b0;
    local_30 = ((Display *)&PS1_Display1 + 1)->field6_0x2b0;
    p_00 = PS1_Display1.sprites;
    p_01 = PS1_Display2.sprites;
    
    if (NbSprite != 0) {
      puVar5 = &PS1_LevelBGBlock->sprites[0]; /* this one is correct? */
      pSVar11 = PS1_Display1.sprites;
      pSVar12 = PS1_Display2.sprites;
      
      bVar13 = 0;
      do {
        bVar1 = puVar5->id;
        SetSemiTrans(p_00,(uint)(u8)(&D_801F51BF)[bVar1]);
        SetShadeTex(p_00,1);
        pSVar11[0].u0 = puVar5->page_x;
        pSVar11[0].v0 = puVar5->page_y;
        pSVar11[0].w = puVar5->width;
        pSVar11[0].h = puVar5->height;
        pSVar11[0].clut = puVar5->clut;
        __builtin_memcpy(&pSVar11[0x10], p_00, sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x20], &pSVar11[0x10], sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x10], p_00, sizeof(SPRT));
        __builtin_memcpy(&pSVar11[0x20], &pSVar11[0x10], sizeof(SPRT));
        SetSemiTrans(p_01,(uint)(u8)(&D_801F51BF)[bVar1]);
        SetShadeTex(p_01,1);
        pSVar12[0].u0 = puVar5->page_x;
        pSVar12[0].v0 = puVar5->page_y;
        pSVar12[0].w = puVar5->width;
        pSVar12[0].h = puVar5->height;
        pSVar12[0].clut = puVar5->clut;
        __builtin_memcpy(&pSVar12[0x10], p_01, sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x20], &pSVar12[0x10], sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x10], p_01, sizeof(SPRT));
        __builtin_memcpy(&pSVar12[0x20], &pSVar12[0x10], sizeof(SPRT));
        bVar13 = bVar13 + 1;
        pSVar11 = pSVar11 + 1;
        p_00 = p_00 + 1;
        pSVar12 = pSVar12 + 1;
        p_01 = p_01 + 1;
        FUN_8017b260((short)puVar5->tpage);
        PS1_Display1.drawing_environment.tpage =
             GetTPage(1,(uint)(u8)(&D_801FA55F)[bVar1],D_801F8170,D_801F8174);
        SetDrawEnv(dr_env,&PS1_Display1.drawing_environment);
        PS1_Display2.drawing_environment.tpage =
             GetTPage(1,(uint)(u8)(&D_801FA55F)[bVar1],D_801F8170,D_801F8174);
        puVar5 = puVar5 + 1;
        SetDrawEnv(local_30,&PS1_Display2.drawing_environment);
        dr_env = dr_env + 1;
        local_30 = local_30 + 1;
      } while (bVar13 < NbSprite);
    }
  }
  return;
}

/*
close?
https://github.com/BinarySerializer/BinarySerializer.Ray1/blob/7da0e97301dd6502d027ff3c92ec2b5a00ef6e6e/src/BinarySerializer.Ray1/DataTypes/PS1/Vignette/FondSpriteData.cs
*/
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondDataAndPalettes);*/

void PS1_LoadFondDataAndPalettes(void)
{
    s32 temp_a0;
    s32 temp_v0_1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    u16 var_s1_1;
    u16 var_s1_2;
    u16 var_s1_3;
    u8 *temp_s0_12;
    u16 *temp_s0_10;
    u16 *temp_s0_11;
    u16 *temp_s0_4;
    u16 *temp_s0_5;
    u16 *temp_s0_6;
    u16 *temp_s0_7;
    u16 *temp_s0_8;
    u16 *temp_s0_9;
    u8 *var_s0_1;
    u32 *var_s0_2;
    u8 *temp_s0_2;
    u8 *temp_s0_3;
    s16 temp_t1; /* PalettesCount */
    u16 test_1;

    temp_s0_12 = D_801E4F50;
    test_1 = *(u16 *)temp_s0_12;
    NbSprite = test_1;
    temp_s0_12 += 2;
    PS1_BandeBackCount = *temp_s0_12;
    temp_s0_12 = temp_s0_12 + 1;
    PS1_BandeFrontCount = *temp_s0_12;
    temp_s0_12 = temp_s0_12 + 1;
    temp_t1 = *temp_s0_12;
    var_s1_1 = 0;
    temp_s0_12 = temp_s0_12 + 4;
    if (PS1_BandeBackCount != 0)
    {
        do
        {
            temp_v0_1 = var_s1_1 * 4;
            test_1 = *(u16 *)temp_s0_12;
            *(&D_801F8008 + temp_v0_1) = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            *(&D_801F800A + temp_v0_1) = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801F51C0)[var_s1_1] = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801FA560)[var_s1_1] = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801F5788)[var_s1_1] = test_1;
            var_s1_1 += 1;
            temp_s0_12 = temp_s0_12 + 2;
        } while ((var_s1_1) < PS1_BandeBackCount);
    }
    var_s1_1 = 0;
    if (PS1_BandeFrontCount != 0)
    {
        do
        {
            temp_v0_2 = var_s1_1 * 4;
            test_1 = *(u16 *)temp_s0_12;
            *(&D_801E63F8 + temp_v0_2) = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            *(&D_801E63FA + temp_v0_2) = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801F51C0)[PS1_BandeBackCount + var_s1_1] = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801FA560)[PS1_BandeBackCount + var_s1_1] = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            test_1 = *(u16 *)temp_s0_12;
            (&D_801F5788)[PS1_BandeBackCount + var_s1_1] = test_1;
            temp_s0_12 = temp_s0_12 + 2;
            var_s1_1 += 1;
        } while (var_s1_1 < PS1_BandeFrontCount);
    }
    temp_v0_3 = PS1_BandeBackCount + PS1_BandeFrontCount;
    temp_s0_12 = temp_s0_12 + ((temp_v0_3 - (temp_v0_3 & 0x1FE)) * 2);
    var_s1_1 = 0;
    if (temp_t1 != 0)
    {
        do
        {
            LoadClut((u_long *)temp_s0_12, 0x00000300, 0x1F7 - (var_s1_1));
            var_s1_1 += 1;
            temp_s0_12 += 0x200;
        } while ((u32) (var_s1_1) < temp_t1);
    }
}

/* close */
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFond);*/

typedef struct Fond
{
    u8 unk_0;
    u8 unk_1;
    s16 width;
    s16 height;
    u8 unk_6;
    u8 type;
} Fond;

void PS1_LoadFond(void)

{
  s32 value1;
  int i;
  s32 value2;
  int fi_count;
  void **cur_dest;
  u8 *cur_src;
  u8 uStack_18;
  u8 uStack_17;
  short width;
  short height;
  u8 uStack_12;
  u8 bStack_11;
  Fond test_1;
  s32 inc;
  u8 *new_var;
  
  memset(&D_801F55B8,0,10);
  __builtin_memcpy(&test_1, D_801F8180, sizeof(Fond));
  D_801F84E0 = test_1.unk_0;
  D_801F9900 = test_1.unk_1;
  PS1_FondWidth = test_1.width;
  PS1_FondHeight = test_1.height;
  D_801F4F58 = test_1.unk_6;
  PS1_FondType = test_1.type;

  if (PS1_FondType == 0xc) {
    PS1_FondImagesCount = 2;
  }
  else {
    PS1_FondImagesCount = PS1_FondWidth >> 6;
  }
  
  cur_src = D_801F8180 + sizeof(Fond);
  i = 0;
  if (i < PS1_FondImagesCount) {
    fi_count = PS1_FondImagesCount;
    cur_dest = &PS1_FondImages[0];
    inc = PS1_FondHeight << 7;
    while (i < fi_count) {
      *cur_dest = cur_src;
      cur_dest = cur_dest + 1;
      i = i + 1;
      cur_src = cur_src + inc;
    }
  }
  
  if ((((PS1_FondType == 6 || PS1_FondType == 7) || (PS1_FondType == 8)) || (PS1_FondType == 0xb)) ||
     ((PS1_FondType == 9 || PS1_FondType == 10 || (PS1_FondType == 0xc)))) {
    PS1_LoadFondSprites();
    PS1_LoadFondDataAndPalettes();
  }
  else {
    NbSprite = 0;
  }
}

/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135ab0);*/

void FUN_80135ab0(s16 param_1, s16 *param_2)
{
    s32 sp18;
    BackgroundPosition *var_s5;
    DR_ENV *var_s4;
    SPRT *var_s1;
    SPRT *var_s0;
    s16 temp_s6;
    s16 temp_s7;
    u32 var_fp;
    Sprite *var_s2;
    u16 temp_s3;
    u8 temp_a1;

    /*sp18 = param_2;*/
    var_s5 = PS1_BackgroundPositions;
    var_fp = 0;
    PS1_PrevPrim = PS1_CurrentDisplay->ordering_table;
    var_s4 = PS1_CurrentDisplay->field6_0x2b0;
    var_s1 = &PS1_CurrentDisplay->sprites[D_801E4BC8];
    var_s2 = PS1_BackgroundSprites;
    if (NbSprite != 0)
    {
        
        var_s0 = var_s1;
        do
        {
            temp_a1 = var_s2->id;
            temp_s3 = *(ushort *)((temp_a1 * 2) + param_2 - 2);
            temp_s7 = var_s5->y - (temp_s3 % PS1_FondHeight);
            temp_s6 = var_s5->x - param_1;
            if (PS1_BandeBackCount < temp_a1)
            {
                PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[8];
            }
            PS1_CurrentDisplay->drawing_environment.tpage = var_s2->tpage;
            SetDrawEnv(var_s4, &PS1_CurrentDisplay->drawing_environment);
            AddPrim(PS1_PrevPrim, var_s4);
            PS1_PrevPrim = var_s4;
            var_s0->u0 = var_s2->page_x;
            var_s0->v0 = var_s2->page_y;
            var_s0->w = var_s2->width;
            var_s0->h = var_s2->height;
            var_s0->code = ((var_s0->code & 0xFD) | 1);
            var_s0->x0 = temp_s6;
            var_s0->y0 = temp_s7;
            var_s0->clut = var_s2->clut;
            
            var_s4 += 1;
            AddPrim(PS1_PrevPrim, var_s1);
            PS1_PrevPrim = var_s1;
            var_s0 += 1;
            D_801E4BC8 += 1;
            var_s1 += 1;
            if (PS1_FondHeight < (temp_s3 + 0xF0))
            {
                __builtin_memcpy(var_s1, var_s0, sizeof(SPRT));
                var_s0->h = var_s0->h + PS1_FondHeight;
                AddPrim(PS1_PrevPrim, var_s1);
                PS1_PrevPrim = var_s1;
                /*var_s0 = var_s1;*/ /* ??? */
                var_s0 += 1;
                var_s1 += 1;
                D_801E4BC8 += 1;
            }
            var_fp += 1;
            var_s5 += 1;
            var_s2 += 1;
        } while ((var_fp & 0xFF) < NbSprite);
    }
}

/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135d5c);*/

void FUN_80135d5c(s32 param_1, s16 *param_2, s32 param_3, s16 param_4)
{
  short sVar1_1;
  Display *pDVar2;
  u8 **ppuVar3;
  u8 bVar4;
  ushort uVar5;
  s16 iVar6;
  uint uVar7;
  int iVar8;
  short sVar9;
  SPRT *pSVar10;
  SPRT *cur_sprite;
  DR_ENV *dr_env;
  int iVar13;
  short *psVar14;
  BackgroundPosition *bg_pos;
  int iVar16;
  Sprite *bg_sprite;
  u8 cnt_1;
  s16 test_1;
  
  uVar5 = PS1_FondWidth;
  pDVar2 = PS1_CurrentDisplay;
  cnt_1 = 0;
  iVar13 = PS1_FondWidth * 2;
  test_1 = ((NbSprite + 0xffff) << 0x10) >> 0x10;
  bg_pos = PS1_BackgroundPositions + test_1;
  dr_env = PS1_CurrentDisplay->field6_0x2b0 + test_1;
  bg_sprite = PS1_BackgroundSprites + test_1;
  PS1_PrevPrim = PS1_CurrentDisplay->ordering_table + 8;
  cur_sprite = PS1_CurrentDisplay->sprites + test_1;
  if (NbSprite != 0) {
    /*iVar16 = param_4;*/
    iVar6 = ((PS1_FondWidth - 0x140) << 0x10) >> 0x10;
    pSVar10 = cur_sprite; /* should be the same??? */
    psVar14 = &bg_pos->y; /* ??? */
    do {
      
      uVar7 = bg_sprite->id - 1 & 0xff;
      if (uVar7 == PS1_BandeBackCount) {
        uVar7 = *(ushort *)(uVar7 * 2 + param_2);
        sVar1_1 = ((int)uVar7 % param_4);
        sVar9 = 1000;
        if ((((ushort)*psVar14 - param_3) << 0x10) >> 0x10 < 1000) {
          sVar9 = (*psVar14 - param_3);
        }
        pSVar10[0].x0 = bg_pos->x - sVar1_1;
        pSVar10[0].y0 = sVar9;
        ppuVar3 = PS1_PrevPrim;
        cur_sprite->tag = cur_sprite->tag & 0xff000000 | (uint)*ppuVar3 & 0xffffff;
        *ppuVar3 = (u8 *)((uint)*ppuVar3 & 0xff000000 | (uint)cur_sprite & 0xffffff);
        if (iVar6 < sVar1_1) {
          pSVar10[0x10].x0 = param_4 + pSVar10[0].x0;
          pSVar10[0x10].y0 = pSVar10[0].y0;
          pSVar10[0x10].tag = pSVar10[0x10].tag & 0xff000000 | (uint)*ppuVar3 & 0xffffff;
          *ppuVar3 = (u8 *)((uint)*ppuVar3 & 0xff000000 | (uint)(cur_sprite + 0x10) & 0xffffff);
        }
      }
      else {
        uVar7 = *(ushort *)(uVar7 * 2 + param_2);
        iVar8 = (short)uVar5;
        PS1_PrevPrim = pDVar2->ordering_table;
        sVar1_1 = ((int)uVar7 % iVar8);
        sVar9 = 1000;
        if ((((ushort)*psVar14 - param_1) << 0x10) >> 0x10 < 1000) {
          sVar9 = (*psVar14 - param_1);
        }
        pSVar10[0].x0 = bg_pos->x - sVar1_1;
        pSVar10[0].y0 = sVar9;
        cur_sprite->tag = cur_sprite->tag & 0xff000000 | (uint)pDVar2->ordering_table[0] & 0xffffff;
        pDVar2->ordering_table[0] =
             (u8 *)((uint)pDVar2->ordering_table[0] & 0xff000000 | (uint)cur_sprite & 0xffffff);
        if (iVar6 < sVar1_1) {
          pSVar10[0x10].x0 = pSVar10[0].x0 + uVar5;
          pSVar10[0x10].y0 = pSVar10[0].y0;
          pSVar10[0x10].tag =
               pSVar10[0x10].tag & 0xff000000 | (uint)pDVar2->ordering_table[0] & 0xffffff;
          pDVar2->ordering_table[0] =
               (u8 *)
               ((uint)pDVar2->ordering_table[0] & 0xff000000 | (uint)(cur_sprite + 0x10) & 0xffffff);
          if (((iVar13) + -0x140) << 0x10 >> 0x10 < sVar1_1) {
            pSVar10[0x20].x0 = pSVar10[0].x0 + iVar13;
            pSVar10[0x20].y0 = pSVar10[0].y0;
            pSVar10[0x20].tag = pSVar10[0x20].tag & 0xff000000 | (uint)pDVar2->ordering_table[0] & 0xffffff;
            pDVar2->ordering_table[0] =
                 (u8 *)
                 ((uint)pDVar2->ordering_table[0] & 0xff000000 | (uint)(cur_sprite + 0x20) & 0xffffff);
          }
        }
      }
      bVar4 = NbSprite;
      ppuVar3 = PS1_PrevPrim;
      cnt_1 = cnt_1 + 1;
      psVar14 = psVar14 + -2;
      bg_pos = bg_pos + -1;
      bg_sprite = bg_sprite + -1;
      pSVar10 = pSVar10 + -1;
      cur_sprite = cur_sprite + -1;
      dr_env->tag = dr_env->tag & 0xff000000 | (uint)*(s32 *)PS1_PrevPrim & 0xffffff;
      *ppuVar3 = (u8 *)((uint)*ppuVar3 & 0xff000000 | (uint)dr_env & 0xffffff);
      dr_env = dr_env + -1;
    } while (cnt_1 < bVar4);
  }
  return;
}

/* close */
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_8013613c);*/

void FUN_8013613c(u8 param_1, u32 param_2, u8 param_3, u32 param_4)

{
  u8 bVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  u8 bVar5;
  int iVar6;
  u8 uVar7;
  RECT local_48;
  uint local_40;
  int local_38;
  int local_30;
  s16 test_1;
  
  param_4 &= 0xffff;
  uVar7 = param_4 & 0x3f;
  if (((param_3 & 0xff) < 0xf0) && ((param_1) != 0)) {
    
    if (0xf0 < ((param_3) + (param_1))) {
      param_1 = 0xf0 - param_3;
    }
    local_40 = (param_4) >> 6;
    bVar5 = test_1 = 6; /* removing test_1 seems more "correct" */
    local_38 = (param_2 & 0xffff) << 7;
    do {
      if (bVar5 == test_1) {
        bVar1 = 0;
        sVar4 = 100;
      }
      else
      {
        sVar4 = 0;
        bVar1 = bVar5;
      }
      
      if ((bVar1 != 5) || (sVar4 = -100, uVar7 != 0)) {
        iVar2 = PS1_FondImagesCount;
        iVar6 = bVar1 * 0x40 - uVar7;
        local_48.x = iVar6 + (PS1_CurrentDisplay->drawing_environment).clip.x + sVar4;
        local_48.y = (PS1_CurrentDisplay->drawing_environment).clip.y + param_3;
        local_48.w = 0x40;
        local_48.h = param_1;
        
        LoadImage(&local_48,(u_long *)(PS1_FondImages[(int)(local_40 + bVar1) % iVar2] + local_38));
        if (bVar1 == 0) {
          local_48.x = (PS1_CurrentDisplay->drawing_environment).clip.x + sVar4;
          local_48.w = 0x40 - uVar7;
          MoveImage(&local_48,(PS1_CurrentDisplay->drawing_environment).clip.x,local_48.y)
          ;
        }
        if (sVar4 == -100) {
          local_48.w = (short)uVar7;
          MoveImage(&local_48,iVar6 + (PS1_CurrentDisplay->drawing_environment).clip.x,
                    local_48.y);
        }
      }
      bVar5 = bVar5 - 1;
    } while (bVar5 != 0);
  }
  return;
}

/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_801366ac);*/

void FUN_801366ac(void)
{
    u16 sp30;
    s32 sp48;
    s32 sp50;
    s32 sp58;
    s32 sp60;
    s32 sp68;
    s16 *temp_a3_1;
    s16 *temp_a3_2;
    s16 temp_v1_2;
    s16 var_s5;
    s32 temp_a0_1;
    s32 temp_a0_2;
    s32 temp_a1_1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a3_3;
    s32 temp_hi;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_lo_5;
    s32 temp_lo_6;
    s32 temp_lo_7;
    s32 temp_lo_8;
    s32 temp_s1_2;
    s32 temp_s7;
    s32 temp_v0_1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_fp;
    u8 var_s0;
    s32 var_s0_2;
    u8 var_s0_3;
    s32 var_s2;
    s16 var_s3; /* s16 or s32? */
    s32 var_s4;
    u16 var_s6;
    s32 var_t6;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v1_1;
    s32 var_v1_2;
    s16 temp_a2_3;
    s16 temp_a2_4;
    u16 temp_s1;
    u16 temp_t6;
    u32 var_v0;
    u8 temp_v0_4;
    u8 temp_v1;
    short local_80[12];
    RECT local_88;
    u16 test_1;
    u8 test_2;
    u8 test_3;
    s32 new_var = 0xF0;

    /*var_s3 = saved_reg_s3;*/
    switch (PS1_FondType)
    {
    case 2:
        if (num_world == 1)
        {
            var_s3 = 0;
            if ((num_level != 0x14 && num_level != 0x15))
            {
                if (num_level == 0x12 || num_level == 0x13)
                {
                case 0:
                    var_s3 = 0;
                    goto block_6;
                }
                goto block_7;
            }
block_6:
            var_s6 = 0;
block_41:
            var_s2 = 0;
            var_s5 = 0;
        }
        else
        {
block_7:
            temp_lo = (PS1_FondHeight - ((ymapmax - ymap) + new_var)) / D_801F9900;
            if ((PS1_FondHeight < 0xF0) && ((PS1_FondHeight - 0xF0) < (s16) temp_lo))
            {
                var_s2 = 0xF0 - PS1_FondHeight;
                var_s6 = 0;
            }
            else
            {
                var_s6 = temp_lo;
                if ((temp_lo << 0x10) >= 0)
                {
                    var_s2 = 0;
                }
                else
                {
                    var_s2 = -temp_lo;
                    if ((s16) (temp_lo * -1) >= 0xF1)
                    {
                        var_s2 = 0x000000F0;
                    }
                    var_s6 = 0;
                }
            }

            var_s5 = 0;
            var_s3 = 0;
        }
        
        
        break;
    case 3:
        temp_lo_2 = ymap / D_801F9900;
        var_s6 = temp_lo_2;
        temp_a0_1 = var_s6 & 0xFFFF;
        if (PS1_FondHeight < var_s6)
        {
            var_s5 = 0x00F0;
        }
        else
        {
            var_s5 = 0;
            if (var_s6 >= (PS1_FondHeight - 0xF0))
            {
                var_s5 = 0xF0 - (PS1_FondHeight - temp_lo_2);
            }
        }
        var_s2 = 0;
        
        
        break;
    case 4:
        temp_lo_3 = ymap / D_801F9900;
        var_s3 = 0;
        var_s2 = 0;
        var_s5 = 0;
        var_s6 = temp_lo_3 % PS1_FondHeight;
        
        
        break;
    case 1:
        var_s6 = 0;
        if ((num_world == 3) && (num_level == 0x000A))
        {
            var_s3 = ymap / D_801F9900;
        }
        else
        {
            var_s3 = (u16) PS1_FondHeight - 0xF0;
        }
        var_s2 = 0;
        var_s5 = 0;
        
        
        break;
    case 8:
        var_s6 = 0;
        var_s2 = 0;
        temp_s1 = PS1_FondWidth;
        var_s5 = 0;
        PS1_FondWidth = 0x0180;
        var_s0 = 0;
        var_s3 = (u16) PS1_FondHeight - 0xF0;
        test_2 = PS1_BandeBackCount;
        if (test_2 != 0)
        {
            do
            {
                temp_v0_2 = xmap + *&(&D_801F55B8)[var_s0];
                temp_a2 = var_s0 * 4;
                temp_v1 = *(&D_801F800A + temp_a2);
                local_80[var_s0] = (temp_v0_2 / temp_v1);
                temp_lo_4 = PS1_FondWidth * *(&D_801F800A + temp_a2); /* was 0x0180 instead of PS1_FondWidth */
                temp_v0_3 = *&(&D_801F55B8)[var_s0] + (&D_801F5788)[var_s0];
                *&(&D_801F55B8)[var_s0] = (temp_v0_3 % temp_lo_4);
                var_s0 += 1;
            } while ((var_s0) < test_2);
        }
        var_s0 = 0;
        test_3 = PS1_BandeFrontCount;
        if (test_2 != 0)
        {
            do
            {
                temp_a0_2 = PS1_BandeBackCount + var_s0;
                temp_v1_2 = *&(&D_801F55B8)[temp_a0_2];
                temp_a2_2 = var_s0 * 4;
                temp_v0_4 = *(&D_801E63FA + temp_a2_2);
                local_80[temp_a0_2] = (xmap + (temp_v1_2 / temp_v0_4));
                temp_lo_5 = PS1_FondWidth * *(&D_801E63FA + temp_a2_2);
                temp_v0_5 = (&D_801F55B8)[var_s0] + (&D_801F5788)[var_s0];
                *&(&D_801F55B8)[temp_a0_2] = (temp_v0_5 % temp_lo_5);
                var_s0 += 1;
            } while ((var_s0) < test_3);
        }
        /* TODO: arg 2? */
        FUN_80138b84(var_s3, local_80, (var_s3 - ymapmax) + ymap, PS1_FondWidth);
        PS1_FondWidth = temp_s1;
        
        break;
    case 9:
    case 10:
        var_s3 = 0;
        var_s6 = 0;
        var_s2 = 0;
        var_s5 = 0;
        if ((num_world != 2) || ((num_level != 4)))
        {
            FUN_80138718(PS1_FondType);
        }
        break;
    case 11:
        temp_t6 = xmap;
        xmap = 0;
        var_s6 = 0;
        var_s2 = 0;
        var_s5 = 0;
        sp30 = temp_t6;
        var_s3 = (u16) PS1_FondHeight - 0xF0;
        FUN_80138360(PS1_CurrentVitrailClignotement);
        
        break;
    default:
        temp_lo_6 = ymap * (PS1_FondHeight - 0xF0);
        var_s6 = 0;
        var_s2 = 0;
        var_s5 = 0;
        var_s3 = temp_lo_6 / ymapmax;
        
        break;
    }
    var_fp = 6;

    /*sp58 = (0xF0 - var_s6) - var_s2;*/
    /*sp60 = 0xF0 - (s16) var_s2;*/
    sp68 = 0xF0 - var_s2;
    /*var_v1_1 = 6 & 0xFF;*/
    
    do
    {
        
        if (var_fp == 6)
        {
            var_s0_3 = 0;
            var_s4 = 0x64;
        }
        else
        {
            var_s4 = 0;
            var_s0_3 = var_fp;
        }
        temp_a3_3 = var_s0_3 & 0xFF;

        if (temp_a3_3 != 5 || (var_s4 = -0x64, (xmap / D_801F84E0) & 0x3F))
        {
            var_a0 = xmap / D_801F84E0;
            temp_s7 = (temp_a3_3 << 6) - (var_a0 - ((var_a0 / 64) << 6));
            local_88.x = var_s4 + (temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x);
            local_88.w = 0x0040;
            temp_s1_2 = temp_a3_3 + (var_a0 / 64);
            temp_hi = temp_s1_2 % PS1_FondImagesCount;
            if ((var_s6 == 0) && ((PS1_FondType != 2) || (var_s2 < 0xF0 == 0)))
            {
                var_a0_2 = 0;
                if (PS1_FondType == 3)
                {
                    var_v0 = 0 & 0xFFFF;
                    if (var_s5 < 0xF0)
                    {
                        goto block_95;
                    }
                }
            }
            else
            {
block_95:
                local_88.y = var_s2 + PS1_CurrentDisplay->drawing_environment.clip.y;
                if ((PS1_FondType == 2) && (PS1_FondHeight < 0xF0))
                {
                    local_88.h = (0xF0 - var_s6) - var_s2; /* sp58 */
                }
                else
                {
                    local_88.h = (PS1_FondHeight - var_s6) - var_s2;
                }
                if ((sp68) < local_88.h)
                {
                    local_88.h = 0xF0 - var_s2;
                }
                LoadImage(&local_88, ((var_s3 + var_s6) << 7) + PS1_FondImages[temp_hi]);
                var_a0_2 = var_s5 + (var_s2 + (u16) local_88.h);
            }
            if ((u16) var_a0_2 < 0xF0U)
            {
                if (var_s6 == 0)
                {
                    local_88.h = 0x00F0;
                    local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
                }
                else
                {
                    local_88.h = 0xF0 - var_a0_2;
                    local_88.y = var_a0_2 + PS1_CurrentDisplay->drawing_environment.clip.y;
                }
                if (local_88.h >= 0xF1)
                {
                    local_88.h = 0x00F0;
                }
                LoadImage(&local_88, ((var_s3 << 0x10) >> 9) + PS1_FondImages[temp_hi]);
            }
            if (var_s0_3 == 5)
            {
                temp_lo_7 = xmap / D_801F84E0;
                local_88.x = var_s4 + (temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x);
                temp_a2_3 = PS1_CurrentDisplay->drawing_environment.clip.y;
                local_88.y = temp_a2_3;
                local_88.w = temp_lo_7 - ((temp_lo_7 / 64) << 6);
                local_88.h = 0x00F0;
                MoveImage(&local_88, temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x, temp_a2_3);
            }
            if (!(var_s0_3 & 0xFF))
            {
                temp_lo_8 = xmap / D_801F84E0;
                local_88.x = var_s4 + PS1_CurrentDisplay->drawing_environment.clip.x;
                temp_a2_3 = PS1_CurrentDisplay->drawing_environment.clip.y;
                local_88.y = temp_a2_3;
                local_88.w = 0x40 - (temp_lo_8 - ((temp_lo_8 / 64) << 6));
                local_88.h = 0x00F0;
                MoveImage(&local_88, PS1_CurrentDisplay->drawing_environment.clip.x, temp_a2_3);
            }
        }
        var_fp -= 1;
    } while (var_fp & 0xFF);
    if ((var_s2 << 0x10) != 0)
    {
        local_88.x = PS1_CurrentDisplay->drawing_environment.clip.x;
        local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
        local_88.w = 0x0140;
        local_88.h = var_s2;
        
        ClearImage(&local_88, (u8)((*(ushort *)PS1_FondImages[0] & 0x1f) << 3),
                   (u8)((*(ushort *)PS1_FondImages[0] & 0x3e0) >> 2),
                   (u8)((*(ushort *)PS1_FondImages[0] & 0x7c00) >> 7));
        
    }
    var_v0_4 = var_s5 << 0x10;
    if (var_v0_4 != 0)
    {
        local_88.x = PS1_CurrentDisplay->drawing_environment.clip.x;
        local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y - (var_s5 - new_var);
        local_88.w = 0x0140;
        local_88.h = var_s5;
        ClearImage(&local_88, (u8)((*(ushort *)(PS1_FondImages[1] + -2) & 0x1f) << 3),
                   (u8)((*(ushort *)(PS1_FondImages[1] + -2) & 0x3e0) >> 2),
                   (u8)((*(ushort *)(PS1_FondImages[1] + -2) & 0x7c00) >> 7));
    }
    if (PS1_FondType == 0x0B)
    {
        xmap = sp30;
    }
}

/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_DisplayFondSprites);*/

void PS1_DisplayFondSprites(void)

{
  u8 bVar1_1;
  short sVar2;
  s16 *puVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  short *psVar8;
  s16 *puVar9;
  u8 bVar10;
  s16 *puVar11;
  short *psVar12;
  u8 *pbVar13;
  s16 uVar14;
  short sVar15;
  int iVar16;
  s16 local_58 [12];
  short local_40;
  short local_3e [11];
  
  psVar12 = (short *)&D_801F8008;
  puVar3 = (s16 *)((int)local_58 - (PS1_FondImagesCount * 2 + 0xeU & 0xfffffff8));
  if (PS1_FondType == 6) {
    D_801E4BC8 = 0;
    sVar15 = PS1_FondHeight - 0xf0;
    if ((int)(PS1_FondHeight << 0x10) >> 0x12 <= ymapmax) {
      sVar15 = ((ymap * (((PS1_FondHeight << 0x10) >> 0x10) + -0xf0)) / ymapmax);
    }
    uVar5 = D_801F800A;
    if (uVar5 < 0xff) {
      local_40 = ((D_801F55B8 + xmap) / (int)uVar5);
      D_801F55B8 = ((D_801F55B8 + D_801F5788) % (PS1_FondWidth * D_801F800A));
    }
    else {
      local_40 = 0;
    }
    uVar5 = D_801F8008;
    iVar4 = sVar15;
    psVar8 = local_3e;
    bVar10 = 1;
    FUN_8013613c(uVar5 - iVar4,iVar4,0,local_40);
    if (1 < PS1_BandeBackCount) {
      pbVar13 = &(&D_801F8008)[4]; /* had extra .unk2 */
      do {
        psVar12 = psVar12 + 2;
        uVar7 = *pbVar13;
        if (uVar7 < 0xff) {
          psVar6 = &D_801F55B8 + bVar10;
          *psVar8 = ((xmap + *psVar6) / (int)uVar7);
          *psVar6 = ((int)(*psVar6 + (&D_801F5788)[bVar10]) % (PS1_FondWidth * *pbVar13));
        }
        else {
          *psVar8 = 0;
        }
        bVar1_1 = *(u8 *)psVar12;
        pbVar13 = pbVar13 + 4;
        FUN_8013613c(bVar1_1,(short)uVar5,(short)uVar5 - iVar4,*psVar8);
                psVar8 = psVar8 + 1;
        bVar10 = bVar10 + 1;
        uVar5 = bVar1_1 + uVar5;
      } while (bVar10 < PS1_BandeBackCount);
    }
    psVar12 = &D_801F55B8 + bVar10;
    *psVar8 = (xmap + *psVar12) * D_801E63FA;
    iVar16 = ymapmax;
    *psVar12 = ((int)(*psVar12 + (&D_801F5788)[bVar10]) % PS1_FondWidth);
    FUN_80135d5c(sVar15,&local_40,(sVar15 - iVar16) + ymap,*(s16 *)&D_801E63F8);
  }
  else {
    bVar10 = 0;
    if ((PS1_FondType == 7) || (PS1_FondType == 0xc)) {
      D_801E4BC8 = 0;
      puVar11 = local_58;
      puVar9 = puVar3;
      if (PS1_BandeBackCount != 0) {
        do {
          uVar5 = *(u8 *)(psVar12 + 1);
          iVar4 = ymap / (int)uVar5;
          uVar14 = (s16)((iVar4) % PS1_FondHeight);
          *puVar11 = uVar14;
          uVar5 = 0;
          puVar11 = puVar11 + 1;
          if (0 < *psVar12) {
            do {
              *puVar9 = uVar14;
              uVar5 = uVar5 + 1;
              puVar9 = puVar9 + 1;
            } while ((int)(uVar5 & 0xff) < *psVar12);
          }
          bVar10 = bVar10 + 1;
          psVar12 = psVar12 + 2;
        } while (bVar10 < PS1_BandeBackCount);
      }
      if (PS1_FondType == 7) {
        FUN_80136340(puVar3,(int)((ushort)xmap << 0x10) >> 0x13);
      }
      else {
        CLRSCR();
      }
      if (PS1_BandeFrontCount != '\0') {
        *puVar11 = ((int)(ymap * D_801E63FA) % PS1_FondHeight);
      }
      if (PS1_FondType == 7) {
        FUN_80135ab0((int)((ushort)xmap << 0x10) >> 0x13,local_58);
      }
      else {
        FUN_80137cc8((int)((ushort)xmap << 0x10) >> 0x13,local_58);
      }
    }
    else {
      if (((PS1_FondType == 8) || (PS1_FondType == 0xb)) || (PS1_FondType == 9 || PS1_FondType == 10)) {
        D_801E4BC8 = 0;
      }
      FUN_801366ac();
    }
  }
  return;
}

/* close */
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", DRAW_MAP);*/

void DRAW_MAP(void)

{
  u32 uVar1;
  u32 uVar2;
  u_short uVar3;
  int iVar4;
  int y_pos;
  u32 puVar5;
  int tile_index;
  uint uVar6;
  SPRT_8 *puVar7;
  int x_pos;
  SPRT_8 *p;
  SPRT_8 *pSVar7;
  int iVar8;
  s16 test_1;
  u8 **new_var;
  int new_var2;
  s32 test_2;
  
  iVar4 = -(((((u16) xmap << 0x10) >> 0x10) + ((((u16) xmap << 0x10) >> 0x10) / 16) * -0x10) << 0x10 >> 0x10);
  y_pos = -(new_var2 = ((((((ushort) ymap) << 0x10) >> 0x10) + ((((((ushort) ymap) << 0x10) >> 0x10) / 16) * (-0x10))) << 0x10) >> 0x10);
  iVar8 = (((ushort)ymap << 0x10) >> 0x14) * mp.width;
  test_2 = ((u16) xmap << 0x10) >> 0x14;
  pSVar7 = PS1_CurrentDisplay->tiles;
    while (y_pos < (PS1_CurrentDisplay->drawing_environment).clip.h) {
      tile_index = test_2 + iVar8;
      x_pos = iVar4;
        while (x_pos < 0x140) {
          puVar5 = mp.map[tile_index] & 0x3ff;
          tile_index = tile_index + 1;
          if ((puVar5 != 0) && (D_801F4A40[puVar5] != 0xff)) {
            pSVar7->clut = GetClut(0x300,D_801F4A40[puVar5] + 504);
            pSVar7->x0 = x_pos;
            pSVar7->y0 = y_pos;
            uVar1 = PS1_GetTileU(puVar5);
            uVar2 = PS1_GetTileV(D_801F5440,D_801F55D8,puVar5);
            test_1 = FUN_80137998(D_801F5440,D_801F55D8,puVar5);
            pSVar7->u0 = uVar1;
            pSVar7->v0 = uVar2;
            /*new_var = PS1_CurrentDisplay->ordering_table;*/
            AddPrim(PS1_CurrentDisplay->ordering_table + (test_1 - 6),pSVar7);
            pSVar7 = pSVar7 + 1;
          }
          x_pos = x_pos + 0x10;
        }
      y_pos = y_pos + 0x10;
      iVar8 = iVar8 + mp.width;
    }
  AddPrim(PS1_CurrentDisplay->ordering_table + 2,
          PS1_CurrentDisplay->map_drawing_environment_primitives);
  AddPrim(PS1_CurrentDisplay->ordering_table + 3,
          PS1_CurrentDisplay->map_drawing_environment_primitives + 1);
  AddPrim(PS1_CurrentDisplay->ordering_table + 4,
          PS1_CurrentDisplay->map_drawing_environment_primitives + 2);
  AddPrim(PS1_CurrentDisplay->ordering_table + 5,
          PS1_CurrentDisplay->map_drawing_environment_primitives + 3);
  return;
}