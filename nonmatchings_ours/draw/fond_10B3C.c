#include "draw/fond_10B3C.h"

/*
score of 215
https://github.com/BinarySerializer/BinarySerializer.Ray1/blob/7da0e97301dd6502d027ff3c92ec2b5a00ef6e6e/src/BinarySerializer.Ray1/DataTypes/PS1/Vignette/FondSpriteData.cs
*/
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_LoadFondDataAndPalettes);*/

void PS1_LoadFondDataAndPalettes(void)
{
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    u16 var_s1_1;
    u8 *temp_s0_12;
    u32 *var_s0_2;
    s16 temp_t1; /* PalettesCount */
    u16 test_1; /* if i didn't use this, all the lhu's would be lbu's? */

    temp_s0_12 = D_801E4F50;
    test_1 = *(u16 *)temp_s0_12;
    NbSprite = test_1;
    temp_s0_12 += 2;
    PS1_BandeBackCount = *temp_s0_12++;
    PS1_BandeFrontCount = *temp_s0_12++;
    temp_t1 = *temp_s0_12;
    var_s1_1 = 0;
    temp_s0_12 += 4;
    while ((var_s1_1) < PS1_BandeBackCount)
    {
        test_1 = *(u16 *)temp_s0_12;
        D_801F8008[var_s1_1].unk_0 = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        D_801F8008[var_s1_1].unk_1 = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        PS1_FondSpritesIsSemiTrans[var_s1_1] = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        PS1_FondSpritesABR[var_s1_1] = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        (&D_801F5788)[var_s1_1] = test_1;
        var_s1_1 += 1;
        temp_s0_12 += 2;
    }
    var_s1_1 = 0;
    while (var_s1_1 < PS1_BandeFrontCount)
    {
        temp_v0_2 = var_s1_1 * 4;
        test_1 = *(u16 *)temp_s0_12;
        D_801E63F8[var_s1_1].unk_0 = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        D_801E63F8[var_s1_1].unk_1 = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        PS1_FondSpritesIsSemiTrans[PS1_BandeBackCount + var_s1_1] = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        PS1_FondSpritesABR[PS1_BandeBackCount + var_s1_1] = test_1;
        temp_s0_12 += 2;
        test_1 = *(u16 *)temp_s0_12;
        (&D_801F5788)[PS1_BandeBackCount + var_s1_1] = test_1;
        temp_s0_12 += 2;
        var_s1_1 += 1;
    }
    temp_v0_3 = PS1_BandeBackCount + PS1_BandeFrontCount;
    temp_s0_12 = temp_s0_12 + ((temp_v0_3 - (temp_v0_3 & 0x1FE)) * 2);
    var_s1_1 = 0;
    while ((u32) (var_s1_1) < temp_t1)
    {
        LoadClut((u32 *)temp_s0_12, 768, 503 - var_s1_1);
        var_s1_1 += 1;
        temp_s0_12 += 0x200;
    }
}

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_LoadFond);*/

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
  u8 *test_2;
  
  memset(&D_801F55B8,0,10);
  __builtin_memcpy(&test_1, &D_801F8180[0], sizeof(Fond));
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
  
  cur_src = &D_801F8180[sizeof(Fond)];
  i = 0;
  if (i < PS1_FondImagesCount) {
    fi_count = PS1_FondImagesCount;
    cur_dest = &PS1_FondImages[i];
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

/* score of 2810 */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80135d5c);*/

void FUN_80135d5c(s32 param_1, u16 *param_2, s32 param_3, s16 param_4)
{
    s16 sVar1_1;
    Display *pDVar2;
    u32 *ppuVar3;
    u8 bVar4;
    s32 fw_1;
    s32 fw_2;
    s16 fw_3;
    s16 fw_4;
    u8 uVar7;
    s16 sVar9;
    SPRT *pSVar10;
    SPRT *cur_sprt;
    DR_ENV *cur_dr_env;
    DVECTOR *cur_pos;
    Sprite *cur_bg_sprite;
    u8 cnt_1;
    s16 test_1;
    s16 temp_v0_4;
    u32 *new_var_1; /* ??? was permuter sugg. */
    s16 new_var_2;
    
    cnt_1 = 0;
    fw_1 = PS1_FondWidth;
    fw_2 = PS1_FondWidth * 2;
    fw_4 = ((PS1_FondWidth * 2 - 0x140));
    fw_3 = ((PS1_FondWidth - 0x140));
    /*test_1 = ((NbSprite + 0xffff) << 0x10) >> 0x10;*/
    test_1 = ((NbSprite - 1));
    cur_pos = &PS1_BackgroundPositions[test_1];
    pDVar2 = PS1_CurrentDisplay;
    cur_bg_sprite = &PS1_BackgroundSprites[test_1];
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[8];
    cur_dr_env = &PS1_CurrentDisplay->map_drawing_environment_primitives[9 + test_1];
    
    cur_sprt = &PS1_CurrentDisplay->sprites[test_1];
    bVar4 = NbSprite;
    while (cnt_1 < bVar4) {
        uVar7 = cur_bg_sprite->id - 1;
        sVar9 = 1000;
        if (uVar7 == PS1_BandeBackCount) {
            sVar1_1 = param_2[uVar7] % param_4;
            new_var_2 = cur_pos->vx - sVar1_1;
            temp_v0_4 = cur_pos->vy - param_3;
            if (sVar9 > temp_v0_4) {
                sVar9 = temp_v0_4;
            }
            cur_sprt[0].x0 = new_var_2;
            cur_sprt[0].y0 = sVar9;
            ppuVar3 = PS1_PrevPrim;
            cur_sprt[0].tag = cur_sprt[0].tag & 0xff000000 | *ppuVar3 & 0xffffff;
            *ppuVar3 = (*ppuVar3 & 0xff000000 | (uint)&cur_sprt[0] & 0xffffff);
            if (fw_3 < sVar1_1) {
                cur_sprt[0x10].x0 = param_4 + cur_sprt[0].x0;
                cur_sprt[0x10].y0 = cur_sprt[0].y0;
                new_var_1 = &cur_sprt[0x10].tag;
                cur_sprt[0x10].tag = *new_var_1 & 0xff000000 | *ppuVar3 & 0xffffff;
                *ppuVar3 = (*ppuVar3 & 0xff000000 | (uint)(&cur_sprt[0x10]) & 0xffffff);
            }
        }
        else {
            PS1_PrevPrim = pDVar2->ordering_table;
            ppuVar3 = PS1_PrevPrim;
            sVar1_1 = param_2[uVar7] % (s16) fw_1;
            new_var_2 = cur_pos->vx - sVar1_1;
            temp_v0_4 = cur_pos->vy - param_1;
            if (sVar9 > temp_v0_4) {
                sVar9 = temp_v0_4;
            }
            cur_sprt[0].x0 = new_var_2;
            cur_sprt[0].y0 = sVar9;
            cur_sprt[0].tag = cur_sprt[0].tag & 0xff000000 | *ppuVar3 & 0xffffff;
            *ppuVar3 =
                (*ppuVar3 & 0xff000000 | (uint)&cur_sprt[0] & 0xffffff);
            if (fw_3 < sVar1_1) {
                cur_sprt[0x10].x0 = cur_sprt[0].x0 + fw_1;
                cur_sprt[0x10].y0 = cur_sprt[0].y0;
                new_var_1 = &cur_sprt[0x10].tag;
                cur_sprt[0x10].tag =
                    *new_var_1 & 0xff000000 | *ppuVar3 & 0xffffff;
                *ppuVar3 =
                    (*ppuVar3 & 0xff000000 | (uint)(&cur_sprt[0x10]) & 0xffffff);
                if (fw_4 < sVar1_1) {
                    cur_sprt[0x20].x0 = cur_sprt[0].x0 + fw_2;
                    cur_sprt[0x20].y0 = cur_sprt[0].y0;
                    cur_sprt[0x20].tag = cur_sprt[0x20].tag & 0xff000000 | *ppuVar3 & 0xffffff;
                    *ppuVar3 =
                        (*ppuVar3 & 0xff000000 | (uint)(&cur_sprt[0x20]) & 0xffffff);
                }
            }
        }
        
        cnt_1++;
        cur_pos--;
        cur_bg_sprite--;
        pSVar10--;
        cur_sprt--;
        ppuVar3 = PS1_PrevPrim;
        bVar4 = NbSprite;
        cur_dr_env->tag = cur_dr_env->tag & 0xff000000 | *ppuVar3 & 0xffffff;
        *ppuVar3 = (*ppuVar3 & 0xff000000 | (uint)cur_dr_env & 0xffffff);
        cur_dr_env--;
    }
}

/* matches, but ... */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_8013613c);*/

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
    int new_var;

    param_4 &= 0xffff;
    uVar7 = param_4 & 0x3f;
    if (param_3 < 0xf0 && param_1 != 0)
    {
        if (0xf0 < param_3 + param_1)
            param_1 = 0xf0 - param_3;
        
        local_40 = (param_4) >> 6;
        bVar5 = test_1 = 6;
        local_38 = (param_2 & 0xffff) << 7;
        while (bVar5 != 0) {
            new_var = 5;
            if (bVar5 == test_1) {
                bVar1 = 0;
                sVar4 = 100;
            }
            else
            {
                sVar4 = 0;
                bVar1 = bVar5;
            }
            
            if (bVar1 == new_var)
            {
                sVar4 = -100;
            }
            
            if ((bVar1 != new_var) || uVar7 != 0)
            {
                iVar2 = PS1_FondImagesCount;
                iVar6 = bVar1 * 0x40 - uVar7;
                local_48.x = iVar6 + (PS1_CurrentDisplay->drawing_environment).clip.x + sVar4;
                local_48.y = (PS1_CurrentDisplay->drawing_environment).clip.y + param_3;
                local_48.w = 0x40;
                local_48.h = param_1;
                
                LoadImage(&local_48,(u_long *)(PS1_FondImages[(int)((local_40) + bVar1) % iVar2] + local_38));
                if (bVar1 == 0)
                {
                    local_48.x = (PS1_CurrentDisplay->drawing_environment).clip.x + sVar4;
                    local_48.w = 0x40 - uVar7;
                    MoveImage(&local_48,(PS1_CurrentDisplay->drawing_environment).clip.x,local_48.y);
                }
                if (sVar4 == -100)
                {
                    local_48.w = (short)uVar7;
                    MoveImage(&local_48,iVar6 + (PS1_CurrentDisplay->drawing_environment).clip.x,
                            local_48.y);
                }
            }
            bVar5 = bVar5 - 1;
        }
    }
}

/*
score of ???
similar to FUN_8013613c
*/
INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80136340);

/* score of 1905 */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_801366ac);*/

void FUN_801366ac(void)
{
    RECT local_88;
    u16 sp30;
    short local_80[12];
    s16 var_s5;
    s32 temp_a0_2;
    s32 temp_hi;
    s32 temp_lo_1;
    s32 temp_lo_7;
    s32 temp_s7;
    s32 var_a0_1;
    s16 var_a0_2;
    u8 var_fp;
    u8 var_s0_1;
    u8 var_s0_3;
    s16 var_s2;
    s16 var_s3;
    s32 var_s4;
    u16 var_s6;
    s32 var_v1_1;
    u16 temp_s1_1;
    s16 new_var2;
    
    u8 test_2;
    s32 new_var = 0xF0;

    /*var_s3 = saved_reg_s3;*/
    switch (PS1_FondType)
    {
    case 2:
        if (
            num_world == 1 &&
            (num_level == 0x14 || num_level == 0x15 || num_level == 0x12 || num_level == 0x13)
        )
        {
    case 0:
            var_s3 = 0;
            var_s6 = 0;
            var_s2 = 0;
            var_s5 = 0;
        }
        else
        {
            var_s3 = (-((ymapmax - ymap) + 0xf0) + PS1_FondHeight) / D_801F9900;
            if ((PS1_FondHeight < 0xF0) && ((s16) var_s3 > (PS1_FondHeight - 0xF0)))
            {
                var_s2 = 0xF0 - PS1_FondHeight;
                var_s6 = 0;
            }
            else
            {
                var_s6 = var_s3;
                if (var_s3 >= 0)
                {
                    var_s2 = 0;
                }
                else
                {
                    var_s3 = -var_s3;
                    MIN_2(var_s3, 0xf0);
                    var_s2 = var_s3;
                    var_s6 = 0;
                }
            }
            var_s5 = 0;
            var_s3 = 0;
        }
        break;
    case 3:
        /* never sets var_s3 */
        var_s6 = ymap / D_801F9900;
        if (var_s6 > PS1_FondHeight)
        {
            var_s5 = 0x00F0;
        }
        else
        {
            if (var_s6 >= (PS1_FondHeight - 0xF0))
            {
                var_s5 = 0xF0 - (PS1_FondHeight - var_s6);
            }
            else
                var_s5 = 0;
        }
        var_s2 = 0;
        break;
    case 4:
        var_s6 = (ymap / D_801F9900) % PS1_FondHeight;
        var_s3 = 0;
        var_s2 = 0;
        var_s5 = 0;
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
        var_s5 = 0;
        var_s3 = (u16) PS1_FondHeight - 0xF0;

        temp_s1_1 = PS1_FondWidth;
        PS1_FondWidth = 0x0180;
        var_s0_1 = 0;
        while ((var_s0_1) < PS1_BandeBackCount)
        {
            local_80[var_s0_1] =
                ((xmap + D_801F55B8[var_s0_1]) /
                D_801F8008[var_s0_1].unk_1);
            D_801F55B8[var_s0_1] =
                ((D_801F55B8[var_s0_1] + (&D_801F5788)[var_s0_1]) %
                (PS1_FondWidth * D_801F8008[var_s0_1].unk_1));
            var_s0_1 += 1;
        }
        var_s0_1 = 0;
        while ((var_s0_1) < PS1_BandeFrontCount)
        {
            temp_a0_2 = PS1_BandeBackCount + var_s0_1;
            local_80[temp_a0_2] =
                (xmap + (D_801F55B8[temp_a0_2] / D_801E63F8[var_s0_1].unk_1));
            D_801F55B8[temp_a0_2] =
                ((D_801F55B8[var_s0_1] + (&D_801F5788)[var_s0_1]) %
                (PS1_FondWidth * D_801E63F8[var_s0_1].unk_1));
            var_s0_1 += 1;
        }
        FUN_80138b84(var_s3, local_80, (var_s3 - ymapmax) + ymap, PS1_FondWidth);
        PS1_FondWidth = temp_s1_1;
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
        sp30 = xmap;
        xmap = 0;
        var_s6 = 0;
        var_s2 = 0;
        var_s5 = 0;
        var_s3 = (u16) PS1_FondHeight - 0xF0;
        FUN_80138360(PS1_CurrentVitrailClignotement);
        break;
    default:
        var_s6 = 0;
        var_s2 = 0;
        var_s5 = 0;
        var_s3 = (ymap * (PS1_FondHeight - 0xF0)) / ymapmax;
        break;
    }
    
    /*sp48 = var_s6;*/
    /*sp50 = var_s2 < 0xF0;*/
    /*sp58 = (0xF0 - var_s6) - var_s2;*/
    /*sp60 = 0xF0 - (s16) var_s2;*/
    /*sp68 = 0xF0 - var_s2; */
    /*var_v1_1 = 6 & 0xFF;*/
    new_var2 = (s16) var_s2;
    for (var_fp = 6; var_fp & 0xFF; var_fp--)
    {
        
        if (var_fp == 6)
        {
            var_s0_1 = 0;
            var_s4 = 0x64;
        }
        else
        {
            var_s4 = 0;
            var_s0_1 = var_fp;
        }

        if (var_s0_1 != 5 || (var_s4 = -0x64, (xmap / D_801F84E0) & 0x3F))
        {
            var_a0_1 = xmap / D_801F84E0;
            temp_s7 = (var_s0_1 << 6) - (var_a0_1 - ((var_a0_1 / 64) << 6));
            local_88.x = var_s4 + (temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x);
            local_88.w = 0x0040;
            temp_hi = (var_s0_1 + (var_a0_1 / 64)) % PS1_FondImagesCount;
            if (
                var_s6 != 0 ||
                (PS1_FondType == 2 && (new_var2 < 0xF0)) || /* var_s2 < 0xf0 not placed in sp50? */
                (PS1_FondType == 3 && (s16) var_s5 < 0xF0)
            )
            {
                local_88.y = var_s2 + PS1_CurrentDisplay->drawing_environment.clip.y;
                if ((PS1_FondType == 2) && (PS1_FondHeight < 0xF0))
                {
                    local_88.h = (0xF0 - var_s6) - var_s2; /* sp58 */
                }
                else
                {
                    local_88.h = (PS1_FondHeight - var_s6) - var_s2;
                }
                if ((0xF0 - new_var2) < local_88.h) /* ??? */
                {
                    local_88.h = 0xF0 - (new_var2);
                }
                LoadImage(&local_88, &PS1_FondImages[temp_hi][((var_s3 + var_s6) << 7)]);
                var_a0_2 = var_s5 + (var_s2 + (u16) local_88.h);
            }
            else
            {
                var_a0_2 = 0;
            }
            if ((u16) var_a0_2 < 0xF0U)
            {
                if (var_s6 == 0)
                {
                    local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
                    local_88.h = 0x00F0;
                }
                else
                {
                    local_88.y = var_a0_2 + PS1_CurrentDisplay->drawing_environment.clip.y;
                    local_88.h = 0xF0 - var_a0_2;
                }
                if (local_88.h > 0xF0)
                {
                    local_88.h = 0x00F0;
                }
                LoadImage(&local_88, &PS1_FondImages[temp_hi][((var_s3 << 7))]);
            }
            if (var_s0_1 == 5)
            {
                temp_lo_7 = xmap / D_801F84E0;
                local_88.x = var_s4 + (temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x);
                local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
                local_88.w = temp_lo_7 - ((temp_lo_7 / 64) << 6);
                local_88.h = 0x00F0;
                MoveImage(&local_88, temp_s7 + PS1_CurrentDisplay->drawing_environment.clip.x, local_88.y);
            }
            if (var_s0_1 == 0)
            {
                temp_lo_7 = xmap / D_801F84E0;
                local_88.x = var_s4 + PS1_CurrentDisplay->drawing_environment.clip.x;
                local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
                local_88.w = 0x40 - (temp_lo_7 - ((temp_lo_7 / 64) << 6));
                local_88.h = 0x00F0;
                MoveImage(&local_88, PS1_CurrentDisplay->drawing_environment.clip.x, local_88.y);
            }
        }
    }

    if (var_s2 != 0)
    {
        local_88.x = PS1_CurrentDisplay->drawing_environment.clip.x;
        local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y;
        local_88.w = 0x0140;
        local_88.h = var_s2;
        /*ClearImage(&local_88, (PS1_FondImages[0][0].r * 8),
                   (PS1_FondImages[0][0].g * 8),
                   (PS1_FondImages[0][0].b * 8));*/
        ClearImage(&local_88, (u8)((*(ushort *)PS1_FondImages[0] & (0x1f << 0)) << 3),
                   (u8)((*(ushort *)PS1_FondImages[0] & (0x1f << 5)) >> 2),
                   (u8)((*(ushort *)PS1_FondImages[0] & (0x1f << 10)) >> 7));
        
    }
    if (var_s5 != 0)
    {
        local_88.x = PS1_CurrentDisplay->drawing_environment.clip.x;
        local_88.y = PS1_CurrentDisplay->drawing_environment.clip.y - (var_s5 - new_var); /* TODO: new_var??? */
        local_88.w = 0x0140;
        local_88.h = var_s5;
        /*ClearImage(&local_88, (PS1_FondImages[1][-1].r * 8),
                   (PS1_FondImages[1][-1].g * 8),
                   (PS1_FondImages[1][-1].b * 8));*/ /* -1 index??? */
        ClearImage(&local_88, (u8)((*(ushort *)(PS1_FondImages[1] + -2) & (0x1f << 0)) << 3),
                   (u8)((*(ushort *)(PS1_FondImages[1] + -2) & (0x1f << 5)) >> 2),
                   (u8)((*(ushort *)(PS1_FondImages[1] + -2) & (0x1f << 10)) >> 7));
    }
    if (PS1_FondType == 0x0B)
    {
        xmap = sp30;
    }
}

/*
score of 405
FUN_8013613c param_4???
*/
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_DisplayFondSprites);*/

void PS1_DisplayFondSprites(void)
{
    s16 sp10[12];
    s16 sp28[12];
    Unk_801f8008 *var_s3_1;
    s16 *temp_a1_1;
    s16 *temp_a2_2;
    s16 *var_s0_1;
    s16 *var_s2;
    s16 temp_hi;
    u8 var_a1;
    u8 var_s1_1;
    u8 var_s1_2;
    s16 var_s5;
    u8 temp_a2_1;
    u8 temp_s2_1;
    s16 var_s6;
    s16 *test_2;
    s32 test_3;
    s16 var_s7[PS1_FondImagesCount]; /* see https://decomp.me/scratch/sMPT6 */
    s16 *new_var_1;
    s16 *new_var_2;

    var_s3_1 = &D_801F8008[0];
    var_s6 = 0;
    if (PS1_FondType == 6)
    {
        
        D_801E4BC8 = 0;
        
        if (ymapmax >= (PS1_FondHeight >> 2))
        {
            var_s5 = (ymap * (PS1_FondHeight - 0xF0)) / ymapmax;
        }
        else
            var_s5 = PS1_FondHeight - 0xF0;


        var_s0_1 = &sp28[0];
        if ((u8) var_s3_1->unk_1 < 0xFFU)
        {
            test_2 = &D_801F55B8[0]; /* cannot make duplicates of this use test_2 also??? */
            *var_s0_1 = ((xmap + *test_2) / var_s3_1->unk_1);
            *test_2 = ((*test_2 + D_801F5788) % (PS1_FondWidth * var_s3_1->unk_1));
        }
        else
        {
            *var_s0_1 = 0;
        }
        temp_s2_1 = var_s3_1->unk_0;
        var_s3_1++;
        
        FUN_8013613c(temp_s2_1 - var_s5, var_s5, var_s6, *var_s0_1);
        var_s6 += temp_s2_1;
        var_s0_1++;
        var_s1_1 = 1;
        new_var_2 = &D_801E63F8[0].unk_0; /* i don't even */
        while (var_s1_1 < (u8) PS1_BandeBackCount)
        {
            temp_a2_1 = var_s3_1->unk_1;
            if (temp_a2_1 < 0xFFU)
            {
                *var_s0_1 = ((xmap + D_801F55B8[var_s1_1]) / temp_a2_1);
                D_801F55B8[var_s1_1] = ((D_801F55B8[var_s1_1] + (&D_801F5788)[var_s1_1]) % (PS1_FondWidth * var_s3_1->unk_1));
            }
            else
            {
                *var_s0_1 = 0;
            }
            temp_s2_1 = var_s3_1->unk_0;
            var_s3_1 += 1;            
            FUN_8013613c(temp_s2_1, var_s6, var_s6 - var_s5, *var_s0_1);
            var_s6 += temp_s2_1;
            var_s0_1 += 1;
            var_s1_1 += 1;
        }


        *var_s0_1 = (xmap + D_801F55B8[var_s1_1]) * D_801E63F8[0].unk_1;
        D_801F55B8[var_s1_1] = ((D_801F55B8[var_s1_1] + (&D_801F5788)[var_s1_1]) % PS1_FondWidth);
        FUN_80135d5c(var_s5, sp28, (var_s5 - ymapmax) + ymap, *new_var_2);
    }
    else if ((PS1_FondType == 7) || (PS1_FondType == 0x0C))
    {
        var_s1_1 = 0;
        D_801E4BC8 = 0;
        var_s2 = sp10;
        var_s0_1 = &var_s7[0];
        while (var_s1_1 < (u8) PS1_BandeBackCount)
        {
            var_a1 = 0;
            temp_hi = (ymap / var_s3_1->unk_1) % PS1_FondHeight;
            *var_s2 = temp_hi;
            
            var_s2 += 1;
            
            while (var_a1 < var_s3_1->unk_0)
            {
                *var_s0_1 = temp_hi;
                var_s0_1 += 1;
                var_a1 += 1;
            }
            var_s1_1 += 1;
            var_s3_1 += 1;
        }
        if (PS1_FondType == 7)
        {
            FUN_80136340(&var_s7[0], ((xmap) >> 3));
        }
        else
        {
            CLRSCR();
        }

        if (PS1_BandeFrontCount != 0)
        {
            *var_s2 = ((ymap * D_801E63F8[0].unk_1) % PS1_FondHeight);
        }

        if (PS1_FondType == 7)
        {
            FUN_80135ab0(xmap >> 3, sp10);
        }
        else
        {
            FUN_80137cc8(xmap >> 3, sp10);
        }
    }
    else if ((PS1_FondType == 8) || (PS1_FondType == 0x0B) || (PS1_FondType == 9 || PS1_FondType == 10))
    {
        D_801E4BC8 = 0;
        FUN_801366ac();
    }
    else
        FUN_801366ac();
}

/* score of ??? */
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
          if ((puVar5 != 0) && (PS1_Tile_clut_y_offs[puVar5] != 0xff)) {
            pSVar7->clut = GetClut(0x300,PS1_Tile_clut_y_offs[puVar5] + 504);
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

/*
score of ???
completely off and don't feel like working on this rn
*/
/*INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80137cc8);*/

extern u8 D_80127734[56];
extern u8 D_8012776C[56];
extern u8 D_801277A4[56];

void FUN_80137cc8(s32 param_1, s16 *param_2)
{
  u8 bVar1;
  u_char uVar2;
  u_char uVar3;
  u_char uVar4;
  short sVar5;
  u_char uVar6;
  u_char uVar7;
  u_short uVar8;
  Display *pDVar9;
  Sprite *pSVar10;
  POLY_FT4 *pPVar11;
  POLY_FT4 *pPVar12;
  u_char uVar13;
  int iVar14;
  s32 uVar15;
  s32 uVar16;
  uint uVar17;
  s32 uVar18;
  uint uVar19;
  short sVar20;
  u8 *pbVar21;
  POLY_FT4 *pPVar22;
  s32 *puVar23;
  POLY_FT4 *pPVar24;
  POLY_FT4 *psVar25;
  POLY_FT4 *psVar43;
  short sVar26;
  POLY_FT4 *p;
  POLY_FT4 *p_00;
  int iVar27;
  u8 bVar28;
  int iVar29;
  uint uVar30;
  s32 local_d8 [5];
  u8 local_c4 [36];
  s32 local_a0 [5];
  u8 local_8c [36];
  s32 local_68 [5];
  u8 local_54 [36];
  short *local_30;
  
  local_30 = param_2;
  puVar23 = local_d8;
  pbVar21 = D_80127734;
  if (true) {
    __builtin_memcpy(puVar23, pbVar21, 53);
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_80127734 + 0x30);*/
  }
  else {
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_80127734 + 0x30);
    pbVar21 = D_80127734 + 48;*/
  }
  puVar23 = local_a0;
  pbVar21 = D_8012776C;
  if (true) {
    __builtin_memcpy(puVar23, pbVar21, 53);
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_8012776C + 0x30);*/
  }
  else {
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_8012776C + 0x30);
    pbVar21 = D_8012776C + 0x30;*/
  }
  puVar23 = local_68;
  pbVar21 = D_801277A4;
  if (true) {
    __builtin_memcpy(puVar23, pbVar21, 53);
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_801277A4 + 0x30);*/
  }
  else {
    /*do {
      uVar15 = *(s32 *)((int)pbVar21 + 4);
      uVar16 = *(s32 *)((int)pbVar21 + 8);
      uVar18 = *(s32 *)((int)pbVar21 + 0xc);
      *puVar23 = *(s32 *)pbVar21;
      puVar23[1] = uVar15;
      puVar23[2] = uVar16;
      puVar23[3] = uVar18;
      pbVar21 = (u8 *)((int)pbVar21 + 0x10);
      puVar23 = puVar23 + 4;
    } while (pbVar21 != D_801277A4 + 0x30);
    pbVar21 = D_801277A4 + 0x30;*/
  }
  iVar27 = 0x18;
  iVar29 = 0;
  bVar28 = 0;
  p_00 = PS1_CurrentDisplay->polygons + PS1_PolygonsCount;
  psVar43 = p_00;
  uVar19 = 0;
  do {
    pSVar10 = PS1_BackgroundSprites;
    uVar17 = (uint)*(u8 *)((int)local_d8 + uVar19);
    if (uVar17 < 10) {
      uVar30 = (uint)(ushort)local_30[PS1_BackgroundSprites[uVar17].id - 1];
      iVar14 = (int)PS1_FondHeight;
      sVar20 = (short)iVar29 - (short)((int)uVar30 % iVar14);
      iVar14 = (s16) (iVar27 - param_1);
      psVar25 = psVar43;
      p = p_00;
      if ((iVar14 < (int)(PS1_BackgroundSprites[uVar17].width + 0x140)) &&
         ((int)-(uint)PS1_BackgroundSprites[uVar17].width < iVar14)) {
        if (*(char *)((int)local_a0 + uVar19) == '\0') {
          psVar43->u0 = PS1_BackgroundSprites[uVar17].page_x;
          psVar43->v0 = pSVar10[uVar17].page_y;
          psVar43->u1 = pSVar10[uVar17].page_x + pSVar10[uVar17].width;
          psVar43->v1 = pSVar10[uVar17].page_y;
          psVar43->u2 = pSVar10[uVar17].page_x;
          psVar43->v2 = pSVar10[uVar17].page_y + pSVar10[uVar17].height;
          uVar13 = pSVar10[uVar17].page_x + pSVar10[uVar17].width;
        }
        else {
          psVar43->u0 =
               PS1_BackgroundSprites[uVar17].page_x + PS1_BackgroundSprites[uVar17].width + 0xff;
          psVar43->v0 = pSVar10[uVar17].page_y;
          psVar43->u1 = pSVar10[uVar17].page_x - 1;
          psVar43->v1 = pSVar10[uVar17].page_y;
          psVar43->u2 = pSVar10[uVar17].page_x + pSVar10[uVar17].width + 0xff;
          psVar43->v2 = pSVar10[uVar17].page_y + pSVar10[uVar17].height;
          uVar13 = pSVar10[uVar17].page_x - 1;
        }
        psVar43->u3 = uVar13;
        psVar43->v3 = pSVar10[uVar17].page_y + pSVar10[uVar17].height;
        sVar26 = (short)(iVar27 - param_1);
        psVar43->x0 = sVar26;
        psVar43->y0 = sVar20;
        bVar1 = pSVar10[uVar17].width;
        psVar43->y1 = sVar20;
        psVar43->x2 = sVar26;
        psVar43->x1 = sVar26 + (ushort)bVar1;
        psVar43->y2 = sVar20 + (ushort)pSVar10[uVar17].height;
        psVar43->x3 = sVar26 + (ushort)pSVar10[uVar17].width;
        pDVar9 = PS1_CurrentDisplay;
        psVar43->y3 = sVar20 + (ushort)pSVar10[uVar17].height;
        psVar43->clut = pSVar10[uVar17].clut;
        p = p_00 + 1;
        psVar43->tpage = pSVar10[uVar17].tpage;
        AddPrim(pDVar9->ordering_table,p_00);
        PS1_PolygonsCount = PS1_PolygonsCount + 1;
        psVar25 = psVar43 + 1;
        if ((int)PS1_FondHeight < (int)(uVar30 + 0xf0)) {
          pPVar11 = p_00;
          pPVar12 = p;
          __builtin_memcpy(pPVar12, pPVar11, sizeof(POLY_FT4));
          /*do {
            pPVar24 = pPVar12;
            pPVar22 = pPVar11;
            uVar13 = pPVar22->r0;
            uVar2 = pPVar22->g0;
            uVar3 = pPVar22->b0;
            uVar4 = pPVar22->code;
            sVar20 = pPVar22->x0;
            sVar5 = pPVar22->y0;
            uVar6 = pPVar22->u0;
            uVar7 = pPVar22->v0;
            uVar8 = pPVar22->clut;
            pPVar24->tag = pPVar22->tag;
            pPVar24->r0 = uVar13;
            pPVar24->g0 = uVar2;
            pPVar24->b0 = uVar3;
            pPVar24->code = uVar4;
            pPVar24->x0 = sVar20;
            pPVar24->y0 = sVar5;
            pPVar24->u0 = uVar6;
            pPVar24->v0 = uVar7;
            pPVar24->clut = uVar8;
            pPVar11 = (POLY_FT4 *)&pPVar22->x1;
            pPVar12 = (POLY_FT4 *)&pPVar24->x1;
          } while (&pPVar22->x1 != &p_00->x3);*/
          /*sVar20 = pPVar22->y1;
          uVar13 = pPVar22->u1;
          uVar2 = pPVar22->v1;
          uVar8 = pPVar22->tpage;
          pPVar24->x1 = pPVar22->x1;
          pPVar24->y1 = sVar20;
          pPVar24->u1 = uVar13;
          pPVar24->v1 = uVar2;
          pPVar24->tpage = uVar8;*/
          sVar20 = PS1_FondHeight;
          psVar43->x0 = sVar26;
          psVar43->y0 = psVar43->y0 + sVar20;
          bVar1 = pSVar10[uVar17].width;
          psVar43->u1 = sVar26;
          psVar43->x1 = psVar43->y0 + sVar20;
          psVar43->y1 = sVar26 + (ushort)bVar1;
          psVar43->v1 = (ushort)pSVar10[uVar17].height + psVar43->y0 + sVar20;
          pDVar9 = PS1_CurrentDisplay;
          psVar43->y2 = sVar26 + (ushort)pSVar10[uVar17].width;
          psVar25->y3 = (ushort)pSVar10[uVar17].height + psVar43->y0 + sVar20;
          AddPrim(pDVar9->ordering_table,p);
          p = p_00 + 2;
          psVar25 = psVar43 + 0x28;
          PS1_PolygonsCount = PS1_PolygonsCount + 1;
        }
      }
      if ((*(char *)((int)local_68 + (uint)bVar28) != '\0') &&
         (iVar27 = iVar27 + (uint)pSVar10[uVar17].width, *(u8 *)((int)local_d8 + (uint)bVar28) < 3
         )) {
        iVar27 = iVar27 + -2;
      }
      iVar29 = iVar29 + (uint)pSVar10[uVar17].height;
      psVar43 = psVar25;
      p_00 = p;
      if ((s16) iVar29 == (int)PS1_FondHeight) {
        iVar29 = 0;
      }
    }
    else {
      iVar29 = 0;
      iVar27 = (uint)*(u8 *)((int)local_d8 + uVar19) + iVar27;
    }
    bVar28 = bVar28 + 1;
    uVar19 = (uint)bVar28;
  } while (bVar28 < 0x35);
  return;
}

/* score of 425 */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80138718);*/

void FUN_80138718(u8 param_1) /* param_1 = PS1_FondType */
{
    DVECTOR *temp_s1;
    DR_ENV *var_s4;
    Sprite *temp_s2;
    s16 temp_s1_2;
    s32 temp_hi;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    u8 var_s0;
    u8 var_s3;
    u16 temp_s5;
    void *temp_v0_3;
    u16 new_var;
    SPRT *test_1;

    var_s3 = 0;
    var_s4 = &PS1_CurrentDisplay->map_drawing_environment_primitives[9];
    if (NbSprite != 0)
    {
        do
        {
            temp_s1 = &PS1_BackgroundPositions[var_s3];
            temp_s2 = &PS1_BackgroundSprites[var_s3];
            if (param_1 == 0xA)
            {
                var_s0 = rand() % param_1;
            }
            else
            {
                var_s0 = 0;
            }
            temp_hi = xmap / (D_801F84E0 + 2) % PS1_FondWidth;
            temp_s5 = temp_s1->vy;
            temp_s1_2 = temp_s1->vx - temp_hi;
            temp_s6 = temp_hi;
            SetSemiTrans(&PS1_CurrentDisplay->sprites[D_801E4BC8], 1);
            
            if (var_s3 != 3)
            {
                
                var_a0 = D_801E4BC8;
                var_a1 = 0;
            }
            else
            {
                
                var_a0 = D_801E4BC8;
                var_a1 = 1;
            }
            SetShadeTex(&PS1_CurrentDisplay->sprites[var_a0], var_a1);
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->r0 = var_s0 + D_801CEF51;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->g0 = var_s0 + D_801CEF51;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->b0 = var_s0 + D_801CEF51;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->u0 = temp_s2->page_x;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->v0 = temp_s2->page_y;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->w = temp_s2->width;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->h = temp_s2->height;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->clut = temp_s2->clut;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->x0 = temp_s1_2;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->y0 = temp_s5;
            
            AddPrim(PS1_CurrentDisplay->ordering_table, &PS1_CurrentDisplay->sprites[D_801E4BC8]);
            D_801E4BC8 += 1;
            if (PS1_FondWidth < ((s16) temp_s6 + 0x140))
            {
                /*test_1 = &PS1_CurrentDisplay->sprites[D_801E4BC8];*/
                /*test_1 = &PS1_CurrentDisplay->sprites[0];*/
                __builtin_memcpy(&PS1_CurrentDisplay->sprites[D_801E4BC8], &PS1_CurrentDisplay->sprites[D_801E4BC8 - 1], sizeof(SPRT));
                /*temp_v0_3 = (D_801E4BC8 * 0x14) + PS1_CurrentDisplay;
                PS1_CurrentDisplay->sprites[D_801E4BC8].tag = PS1_CurrentDisplay->sprites[D_801E4BC8 - 1].tag;
                PS1_CurrentDisplay->sprites[D_801E4BC8].r0 = PS1_CurrentDisplay->sprites[D_801E4BC8 - 1].r0;
                PS1_CurrentDisplay->sprites[D_801E4BC8].x0 = PS1_CurrentDisplay->sprites[D_801E4BC8 - 1].x0;
                PS1_CurrentDisplay->sprites[D_801E4BC8].u0 = PS1_CurrentDisplay->sprites[D_801E4BC8 - 1].u0;
                PS1_CurrentDisplay->sprites[D_801E4BC8].w = PS1_CurrentDisplay->sprites[D_801E4BC8 - 1].w;*/
                PS1_CurrentDisplay->sprites[D_801E4BC8].x0 = PS1_CurrentDisplay->sprites[D_801E4BC8].x0 + PS1_FondWidth;
                AddPrim(PS1_CurrentDisplay->ordering_table, &PS1_CurrentDisplay->sprites[D_801E4BC8]);
                D_801E4BC8 += 1;
            }
            var_s3 += 1;
            FUN_8017b260((s16) temp_s2->tpage);
            PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 1, PS1_TPage_x, PS1_TPage_y);
            SetDrawEnv(var_s4, &PS1_CurrentDisplay->drawing_environment);
            AddPrim(PS1_CurrentDisplay->ordering_table, var_s4);
            var_s4 += 1;
        } while (var_s3 < NbSprite);
    }
}

/* matches, but */
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_DisplayWorldMapBg2);*/

/* applying these would let us remove new_var_1, test_6? */
extern inline s32 test_123(s32 param_1)
{
    return param_1 / 0x40;
}

extern inline s32 test_1234(s16 param_1)
{
    return param_1 + test_123(param_1) * -0x40;
}

void PS1_DisplayWorldMapBg2(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6)
{
    int iVar2;
    int iVar7;
    short var_s3;
    u8 uVar9;
    u8 uVar10;
    RECT local_58;
    ushort local_48;
    short local_40;
    short local_38;
    short local_30;
    s32 test_1;
    s32 new_var_1;
    int new_var_2;
    s32 test_6;
    
    for (uVar10 = (param_6 / 0x40) + 1; uVar10 != 0; uVar10 = uVar10 - 1) {
        var_s3 = 0;
        
        if (uVar10 == (param_6 / 0x40) + 1U) {
            uVar9 = 0;
            var_s3 = 0x40;
        }
        else
        {
            uVar9 = uVar10;
        }
        
        if (((uVar9 != (param_6 / 0x40)) || (var_s3 = -0x40, (param_1 & (0x40 - 1)) != 0))) {
            new_var_2 = uVar9 * 0x40;
            new_var_1 = (param_1 + (param_1 / 0x40) * -0x40);
            iVar7 = new_var_2 - ((s16) new_var_1);
            local_58.x = iVar7 + (PS1_CurrentDisplay->drawing_environment).clip.x + param_3 + var_s3;
            local_58.y = (PS1_CurrentDisplay->drawing_environment).clip.y + param_4;
            local_58.w = 0x40;
            local_58.h = param_5;
            iVar2 = uVar9 + (param_1 / 0x40);
            
            LoadImage(&local_58,
                    &PS1_FondImages[(iVar2) % PS1_FondImagesCount][((param_2 << 7))]);
            if (uVar9 == 0) {
                local_58.x = (PS1_CurrentDisplay->drawing_environment).clip.x + param_3 + var_s3;
                test_6 = (param_1 + (param_1 / 0x40) * -0x40);
                local_58.w = 0x40 - test_6;
                MoveImage(&local_58,(PS1_CurrentDisplay->drawing_environment).clip.x + param_3,
                        local_58.y);
            }
            if ((uVar9) == (param_6 / 0x40)) {
                local_58.x = iVar7 + (PS1_CurrentDisplay->drawing_environment).clip.x + var_s3 + param_3;
                local_58.w = param_6 - iVar7;
                MoveImage(&local_58,
                        iVar7 + (PS1_CurrentDisplay->drawing_environment).clip.x + param_3,
                        local_58.y);
            }
        }
    }
    DrawSync(0);
}