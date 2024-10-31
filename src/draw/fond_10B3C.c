#include "draw/fond_10B3C.h"

/* BinarySerializer.Ray1/DataTypes/PS1/Vignette */

/* here or with LOAD_FND? */
extern u8 *D_801E4F50; /* or u8 * ??? */
extern u8 *D_801F8180; /* pointer to something for sure, sometimes set to 801f4380 */

/* 801f4380 is passed at 801807ec as LoadImage param_2, also used as some FileInfo.dest's see 8019df64, frequently points to &DAT_8005866c*/
/* here or loading_tex.h? */
extern u16 D_801F5440;
extern u16 D_801F55D8;

/* 10B3C 8013533C -O2 -msoft-float */
void PS1_LoadFondSprites(void)
{
    DR_ENV *dr_env_0; DR_ENV *dr_env_1;
    SPRT *cur_sprt_0; SPRT *cur_sprt_1;
    Sprite *cur_sprite_bg;
    u8 i;
    u8 bg_id;

    PS1_BackgroundPositions = &PS1_LevelBGBlock->sprite_positions[0];
    PS1_BackgroundSprites = &PS1_LevelBGBlock->sprites[0];
    if (PS1_FondType == 6 || PS1_FondType == 7)
    {
        dr_env_0 = &PS1_Displays[0].map_drawing_environment_primitives[9];
        dr_env_1 = &PS1_Displays[1].map_drawing_environment_primitives[9];
        cur_sprt_0 = PS1_Displays[0].sprites;
        cur_sprt_1 = PS1_Displays[1].sprites;
        cur_sprite_bg = &PS1_LevelBGBlock->sprites[0];
        i = 0;
        while (i < NbSprite)
        {
            bg_id = cur_sprite_bg->id;

            SetSemiTrans(cur_sprt_0, PS1_FondSpritesIsSemiTrans[bg_id - 1]);
            SetShadeTex(cur_sprt_0, true);
            cur_sprt_0[0].u0 = cur_sprite_bg->page_x;
            cur_sprt_0[0].v0 = cur_sprite_bg->page_y;
            cur_sprt_0[0].w = cur_sprite_bg->width;
            cur_sprt_0[0].h = cur_sprite_bg->height;
            cur_sprt_0[0].clut = cur_sprite_bg->clut;
            __builtin_memcpy(&cur_sprt_0[0x10], &cur_sprt_0[0], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_0[0x20], &cur_sprt_0[0x10], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_0[0x10], &cur_sprt_0[0], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_0[0x20], &cur_sprt_0[0x10], sizeof(SPRT));

            SetSemiTrans(cur_sprt_1, PS1_FondSpritesIsSemiTrans[bg_id - 1]);
            SetShadeTex(cur_sprt_1, true);
            cur_sprt_1[0].u0 = cur_sprite_bg->page_x;
            cur_sprt_1[0].v0 = cur_sprite_bg->page_y;
            cur_sprt_1[0].w = cur_sprite_bg->width;
            cur_sprt_1[0].h = cur_sprite_bg->height;
            cur_sprt_1[0].clut = cur_sprite_bg->clut;
            __builtin_memcpy(&cur_sprt_1[0x10], &cur_sprt_1[0], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_1[0x20], &cur_sprt_1[0x10], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_1[0x10], &cur_sprt_1[0], sizeof(SPRT));
            __builtin_memcpy(&cur_sprt_1[0x20], &cur_sprt_1[0x10], sizeof(SPRT));

            FUN_8017b260((s16) cur_sprite_bg->tpage);
            PS1_Displays[0].drawing_environment.tpage =
                GetTPage(1, PS1_FondSpritesABR[bg_id - 1], PS1_TPage_x, PS1_TPage_y);
            SetDrawEnv(dr_env_0, &PS1_Displays[0].drawing_environment);
            PS1_Displays[1].drawing_environment.tpage =
                GetTPage(1, PS1_FondSpritesABR[bg_id - 1], PS1_TPage_x, PS1_TPage_y);
            SetDrawEnv(dr_env_1, &PS1_Displays[1].drawing_environment);

            cur_sprt_0++;
            cur_sprt_1++;
            cur_sprite_bg++;
            dr_env_0++;
            dr_env_1++;
            i++;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_LoadFondDataAndPalettes);

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_LoadFond);

/* 112B0 80135AB0 -O2 -msoft-float */
void FUN_80135ab0(s16 param_1, s16 *param_2)
{
    u8 i;
    DVECTOR *cur_pos;
    DR_ENV *cur_dr_env;
    SPRT *cur_sprt;
    Sprite *cur_bg_sprite;
    u16 unk_1;
    s16 unk_x_1; s16 unk_y_1;

    i = 0;
    cur_pos = &PS1_BackgroundPositions[i];
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[i];
    cur_dr_env = &PS1_CurrentDisplay->map_drawing_environment_primitives[9];
    cur_sprt = &PS1_CurrentDisplay->sprites[D_801E4BC8];
    cur_bg_sprite = &PS1_BackgroundSprites[i];
    while (i < NbSprite)
    {
        unk_1 = param_2[cur_bg_sprite->id - 1];
        unk_x_1 = cur_pos->vx - param_1;
        unk_y_1 = cur_pos->vy - (unk_1 % PS1_FondHeight);
        if (PS1_BandeBackCount < cur_bg_sprite->id)
            PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[8];
        
        PS1_CurrentDisplay->drawing_environment.tpage = cur_bg_sprite->tpage;
        SetDrawEnv(cur_dr_env, &PS1_CurrentDisplay->drawing_environment);
        AddPrim(PS1_PrevPrim, cur_dr_env);
        PS1_PrevPrim = cur_dr_env;
        cur_dr_env++;

        cur_sprt->u0 = cur_bg_sprite->page_x;
        cur_sprt->v0 = cur_bg_sprite->page_y;
        cur_sprt->w = cur_bg_sprite->width;
        cur_sprt->h = cur_bg_sprite->height;
        cur_sprt->clut = cur_bg_sprite->clut;
        cur_sprt->code = cur_sprt->code & ~FLG(1) | FLG(0);
        cur_sprt->x0 = unk_x_1;
        cur_sprt->y0 = unk_y_1;
        AddPrim(PS1_PrevPrim, cur_sprt);
        PS1_PrevPrim = cur_sprt;
        cur_sprt++;
        D_801E4BC8++;
        if (PS1_FondHeight < unk_1 + SCREEN_HEIGHT)
        {
            __builtin_memcpy(cur_sprt, cur_sprt - 1, sizeof(SPRT));
            cur_sprt->y0 += PS1_FondHeight;
            AddPrim(PS1_PrevPrim, cur_sprt);
            PS1_PrevPrim = cur_sprt;
            cur_sprt++;
            D_801E4BC8++;
        }
        i++;
        cur_pos++;
        cur_bg_sprite++;
    }
}

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80135d5c);

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_8013613c);
#else
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
#endif

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80136340);

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_801366ac);

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_DisplayFondSprites);

/* 13198 80137998 -O2 -msoft-float */
u8 FUN_80137998(u8 param_1, u8 param_2, s32 param_3)
{
    s16 unk_1 = ((param_1 - 8) << 8) + param_2 + (param_3 & ~0xF);

    if (param_1 < 10 && unk_1 >= 480)
        unk_1 += 32;
    return (unk_1 >> 8) + 8;
}

/* 131F8 801379F8 -O2 -msoft-float */
u8 PS1_GetTileV(u8 param_1, u8 param_2, s32 tile)
{
    s16 unk_1 = ((param_1 - 8) << 8) + param_2 + (tile & ~0xF);

    if (param_1 < 10 && unk_1 >= 480)
        unk_1 += 32;
    return unk_1 & 0xF0;
}

/* 1324C 80137A4C -O2 -msoft-float */
u8 PS1_GetTileU(s32 param_1)
{
    return (param_1 & 0xF) * 16;
}

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", DRAW_MAP);

const u8 D_80127734[] __attribute__((aligned(2))) =
{
    5,   6,   7,   5,   6,   7,   3,   4,   3,   4, 
    0,   1,   2,   0,   1,   2,   3,   4,   3,   4, 
    5,   6,   7,   5,   6,   7,  14,   5,   6,   7, 
    5,   6,   7,   3,   4,   3,   4,   0,   1,   2, 
    0,   1,   2,   3,   4,   3,   4,   5,   6,   7, 
    5,   6,   7
};

const u8 D_8012776C[] __attribute__((aligned(2))) =
{
    1,   1,   1,   1,   1,   1,   1,   1,   1,   1, 
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   0,   1,   1,   1, 
    1,   1,   1,   1,   1,   1,   1,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   0,   0
};

const u8 D_801277A4[] __attribute__((aligned(2))) =
{
    0,   0,   0,   0,   0,   1,   0,   0,   0,   1, 
    0,   0,   0,   0,   0,   1,   0,   0,   0,   1, 
    0,   0,   0,   0,   0,   1,   1,   0,   0,   0, 
    0,   0,   1,   0,   0,   0,   1,   0,   0,   0, 
    0,   0,   1,   0,   0,   0,   1,   0,   0,   0, 
    0,   0,   1
};

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80137cc8);
#else
/*
matches, but clean up
sizeof() uses unclear?
*/
/*INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80137cc8);*/

void FUN_80137cc8(s16 param_1, s16 *param_2)
{
    POLY_FT4 *var_s3;
    Sprite *temp_s0;
    s16 temp_a2;
    s16 temp_v0_1;
    s16 var_s4;
    u8 var_s5;
    u16 temp_s7;
    u8 temp_a0_1;
    s16 temp_a0_2;
    s16 var_s6;
    u8 sp10[53];
    u8 sp48[53];
    u8 sp80[53];

    __builtin_memcpy(sp10, D_80127734, sizeof(D_80127734));
    __builtin_memcpy(sp48, D_8012776C, sizeof(D_8012776C));
    __builtin_memcpy(sp80, D_801277A4, sizeof(D_801277A4));
    var_s4 = 0x18;
    var_s6 = 0;
    var_s3 = &PS1_CurrentDisplay->polygons[PS1_PolygonsCount];
    for (var_s5 = 0; var_s5 < 0x35U; var_s5 += 1)
    {
        temp_a0_1 = sp10[var_s5];
        if (temp_a0_1 < 0xAU)
        {
            
            temp_s0 = &PS1_BackgroundSprites[temp_a0_1];
            temp_s7 = param_2[temp_s0->id - 1];
            temp_a0_2 = temp_s0->width;
            temp_v0_1 = var_s4 - param_1;
            temp_a2 = var_s6 - (temp_s7 % PS1_FondHeight);
            
            if ((temp_v0_1 < (temp_a0_2 + 0x140)) && (-temp_a0_2 < temp_v0_1))
            {
                if (sp48[var_s5] != 0)
                {
                    var_s3->u0 = ((temp_s0->page_x + temp_s0->width) - 1);
                    var_s3->v0 = temp_s0->page_y;
                    var_s3->u1 = (temp_s0->page_x + 0xFF);
                    var_s3->v1 = temp_s0->page_y;
                    var_s3->u2 = ((temp_s0->page_x + temp_s0->width) - 1);
                    var_s3->v2 = (temp_s0->page_y + temp_s0->height);
                    var_s3->u3 = temp_s0->page_x + 0xFF;
                    var_s3->v3 = (temp_s0->page_y + temp_s0->height);
                }
                else
                {
                    var_s3->u0 = temp_s0->page_x;
                    var_s3->v0 = temp_s0->page_y;
                    var_s3->u1 = (temp_s0->page_x + temp_s0->width);
                    var_s3->v1 = temp_s0->page_y;
                    var_s3->u2 = temp_s0->page_x;
                    var_s3->v2 = (temp_s0->page_y + temp_s0->height);
                    var_s3->u3 = temp_s0->page_x + temp_s0->width;
                    var_s3->v3 = (temp_s0->page_y + temp_s0->height);
                }
                
                var_s3->x0 = temp_v0_1;
                var_s3->y0 = temp_a2;
                var_s3->x1 = (temp_v0_1 + temp_s0->width);
                var_s3->y1 = temp_a2;
                var_s3->x2 = temp_v0_1;
                var_s3->y2 = (temp_a2 + temp_s0->height);
                var_s3->x3 = (temp_v0_1 + temp_s0->width);
                var_s3->y3 = temp_a2 + temp_s0->height;
                var_s3->clut = temp_s0->clut;
                var_s3->tpage = temp_s0->tpage;
                AddPrim(PS1_CurrentDisplay->ordering_table, var_s3);
                var_s3 += 1;
                PS1_PolygonsCount = PS1_PolygonsCount + 1;
                if (PS1_FondHeight < (temp_s7 + 0xF0))
                {
                    __builtin_memcpy(var_s3, var_s3 - 1, sizeof(POLY_FT4));

                    var_s3->x0 = temp_v0_1;
                    var_s3->y0 = ((var_s3 - 1)->y0 + PS1_FondHeight);
                    var_s3->x1 = (temp_v0_1 + temp_s0->width);
                    var_s3->y1 = ((var_s3 - 1)->y0 + PS1_FondHeight);
                    var_s3->x2 = temp_v0_1;
                    var_s3->y2 = (temp_s0->height + ((var_s3 - 1)->y0 + PS1_FondHeight));
                    var_s3->x3 = (temp_v0_1 + temp_s0->width);
                    var_s3->y3 = temp_s0->height + ((var_s3 - 1)->y0 + PS1_FondHeight);
                    AddPrim(PS1_CurrentDisplay->ordering_table, var_s3);
                    var_s3 += 1;
                    PS1_PolygonsCount = PS1_PolygonsCount + 1;
                }
            }
            if (sp80[var_s5] != 0)
            {
                var_s4 = var_s4 + temp_s0->width;
                if (sp10[var_s5] < 3U)
                {
                    var_s4 = var_s4 - 2;
                }
            }
            var_s6 = var_s6 + temp_s0->height;
            if (var_s6 == PS1_FondHeight)
            {
                var_s6 = 0;
            }
        }
        else
        {
            var_s6 = 0;
            var_s4 += sp10[var_s5];
        }
    }
}
#endif

/* 13B38 80138338 -O2 -msoft-float */
void allume_vitraux(u8 (*param_1)[5])
{
    __builtin_memcpy(PS1_CurrentVitrailClignotement, param_1, sizeof(*param_1));
}

/* 13B60 80138360 -O2 -msoft-float */
void FUN_80138360(u8 *vit_clig)
{
    u8 i;
    DVECTOR *bg_pos;
    Sprite *bg_sprite;
    DR_ENV *dr_env = &PS1_CurrentDisplay->map_drawing_environment_primitives[9];

    for (i = 0; i < NbSprite; i++)
    {
        if (vit_clig[i] != 0)
        {
            bg_pos = &PS1_BackgroundPositions[i];
            bg_sprite = &PS1_BackgroundSprites[i];
            /* gross... */
            SetSemiTrans((PS1_CurrentDisplay->sprites + D_801E4BC8), true);
            SetShadeTex((PS1_CurrentDisplay->sprites + D_801E4BC8), false);
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->r0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->g0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->b0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->u0 = bg_sprite->page_x;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->v0 = bg_sprite->page_y;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->w = bg_sprite->width;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->h = bg_sprite->height;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->clut = bg_sprite->clut;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->x0 = bg_pos->vx;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->y0 = bg_pos->vy;
            FUN_8017b260((s16) bg_sprite->tpage);
            AddPrim(PS1_CurrentDisplay->ordering_table, (PS1_CurrentDisplay->sprites + D_801E4BC8));
            D_801E4BC8++;
            PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 1, PS1_TPage_x, PS1_TPage_y);
            SetDrawEnv(dr_env, &PS1_CurrentDisplay->drawing_environment);
            AddPrim(PS1_CurrentDisplay->ordering_table, dr_env);
            dr_env++;
            if (PS1_Glass_brightness[i] == 0xFF)
                PS1_Glass_brightness_diff[i] = -5;
            else if (PS1_Glass_brightness[i] == 0)
                PS1_Glass_brightness_diff[i] = 5;
            PS1_Glass_brightness[i] += PS1_Glass_brightness_diff[i];
            if (D_801C71C0[i] == 100)
            {
                vit_clig[i] = 0;
                D_801C71C0[i] = 0;
            }
            else
                D_801C71C0[i]++;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", FUN_80138718);

/* 14384 80138B84 -O2 -msoft-float */
void FUN_80138b84(s16 in_h_1, s16 *param_2, s16 in_h_2, s16 in_w_1)
{
    u8 unk_1[8];
    u8 i;
    DVECTOR *cur_pos;
    DR_ENV *cur_dr_env;
    SPRT *cur_sprt;
    Sprite *cur_bg_sprite;
    u8 bg_id;
    s16 unk_2;
    s16 unk_w_1; s16 unk_h_1;
    s16 unk_3;
    s16 unk_x_1; s16 unk_y_1;

    __builtin_memcpy(unk_1, D_801CEF6C, sizeof(D_801CEF6C));
    i = 0;
    cur_pos = &PS1_BackgroundPositions[i];
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[i];
    cur_dr_env = &PS1_CurrentDisplay->map_drawing_environment_primitives[9];
    cur_sprt = &PS1_CurrentDisplay->sprites[i];
    cur_bg_sprite = &PS1_BackgroundSprites[i];
    while (i < NbSprite)
    {
        bg_id = cur_bg_sprite->id - 1;
        unk_2 = param_2[bg_id];
        SetSemiTrans(cur_sprt, PS1_FondSpritesIsSemiTrans[bg_id]);
        SetShadeTex(cur_sprt, false);
        cur_sprt->r0 = D_801CEF54[bg_id];
        cur_sprt->g0 = D_801CEF54[bg_id];
        cur_sprt->b0 = D_801CEF54[bg_id];
        if (unk_1[bg_id] == 0 && (map_time & 129) == 0)
        {
            if (D_801CEF54[bg_id] == D_801CEF5C[bg_id])
            {
                D_801CEF5C[bg_id] = rand() & 129;
                D_801CEF64[bg_id] =
                    D_801CEF5C[bg_id] > D_801CEF54[bg_id] ? 1 : 0xFF;
            }
            else
                D_801CEF54[bg_id] += D_801CEF64[bg_id];
            
            unk_1[bg_id] = 1;
        }
        FUN_8017b260((s16) cur_bg_sprite->tpage);
        cur_bg_sprite->tpage = GetTPage(1, PS1_FondSpritesABR[bg_id], PS1_TPage_x, PS1_TPage_y);
        if (bg_id >= PS1_BandeBackCount)
        {
            unk_w_1 = in_w_1;
            unk_h_1 = in_h_2;
            PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[8];
        }
        else
        {
            unk_w_1 = PS1_FondWidth;
            unk_h_1 = in_h_1;
        }
        unk_3 = unk_2 % unk_w_1;
        unk_x_1 = cur_pos->vx - unk_3;
        unk_y_1 = cur_pos->vy - unk_h_1;
        PS1_CurrentDisplay->drawing_environment.tpage = cur_bg_sprite->tpage;
        SetDrawEnv(cur_dr_env, &PS1_CurrentDisplay->drawing_environment);
        AddPrim(PS1_PrevPrim, cur_dr_env);
        PS1_PrevPrim = cur_dr_env;
        cur_dr_env++;

        cur_sprt->u0 = cur_bg_sprite->page_x;
        cur_sprt->v0 = cur_bg_sprite->page_y;
        cur_sprt->w = cur_bg_sprite->width;
        cur_sprt->h = cur_bg_sprite->height;
        cur_sprt->clut = cur_bg_sprite->clut;
        cur_sprt->x0 = unk_x_1;
        cur_sprt->y0 = unk_y_1;
        AddPrim(PS1_PrevPrim, cur_sprt);
        PS1_PrevPrim = cur_sprt;
        cur_sprt++;
        D_801E4BC8++;
        if (PS1_FondWidth < unk_3 + SCREEN_WIDTH)
        {
            __builtin_memcpy(cur_sprt, cur_sprt - 1, sizeof(SPRT));
            cur_sprt->x0 += unk_w_1;
            AddPrim(PS1_PrevPrim, cur_sprt);
            PS1_PrevPrim = cur_sprt;
            cur_sprt++;
            D_801E4BC8++;
        }
        i++;
        cur_pos++;
        cur_bg_sprite++;
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/draw/fond_10B3C", PS1_DisplayWorldMapBg2);
#else
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
#endif

void FUN_801392c8(void) {}

void FUN_801392d0(void) {}
