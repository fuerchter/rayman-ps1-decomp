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

/* https://github.com/BinarySerializer/BinarySerializer.Ray1/blob/7da0e97301dd6502d027ff3c92ec2b5a00ef6e6e/src/BinarySerializer.Ray1/DataTypes/PS1/Vignette/FondSpriteData.cs */
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

void FUN_80135ab0(s16 param_1, s32 param_2)
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