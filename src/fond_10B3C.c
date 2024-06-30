#include "fond_10B3C.h"

/* BinarySerializer.Ray1/DataTypes/PS1/Vignette */

void FUN_8017b260(u32 param_1);
extern u8 D_801F51BF;
extern s32 PS1_TPage_x;
extern s32 PS1_TPage_y;
extern u8 D_801FA55F;
extern u8 NbSprite;
extern BackgroundPosition *PS1_BackgroundPositions;
extern Sprite *PS1_BackgroundSprites;
extern u8 PS1_FondType;

/* TODO: types of all of these??? */
extern u8 *D_801E4F50; /* or u8 * ??? */
extern u8 D_801E63F8;
extern u8 D_801E63FA;
extern u8 D_801F51C0;
extern u8 D_801F5788;
extern u8 D_801F8008; /* D_801F8008 and D_801F800A part of the same array? */
extern u8 D_801F800A;
extern u8 D_801FA560;
extern u8 PS1_BandeBackCount;
extern u8 PS1_BandeFrontCount;

extern u8 D_801F4F58;
extern s16 D_801F55B8; /* u8[10] based on 801f55b8? but then there is 80137450 */
extern u8 *D_801F8180; /* pointer to something for sure, sometimes set to 801f4380 */
/* 801f4380 is passed at 801807ec as LoadImage param_2, also used as some FileInfo.dest's see 8019df64, frequently points to &DAT_8005866c*/
extern u8 D_801F84E0;
extern u8 D_801F9900;
extern s16 PS1_FondHeight;
extern void *PS1_FondImages[6]; /* 0th five bits: r, 1st five bits: g, 2nd five bits b (see 8013726c) */
extern s16 PS1_FondImagesCount;
extern s16 PS1_FondWidth;
extern u8 D_801E4BC8; /* used as index into PS1_CurrentDisplay->sprites */
extern u8 PS1_CurrentVitrailClignotement[5];
extern u8 D_801F4A40[944]; /* see also loading_DA64.c */
extern u16 D_801F5440;
extern u16 D_801F55D8;
extern u16 D_801C71C0[5];
extern u8 PS1_Glass_brightness[5];
extern u8 PS1_Glass_brightness_diff[5];
extern u8 D_801CEF51;

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondSprites);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondDataAndPalettes);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFond);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135ab0);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135d5c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_8013613c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80136340);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_801366ac);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_DisplayFondSprites);

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

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", DRAW_MAP);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80137cc8);

/* 13B38 80138338 -O2 -msoft-float */
void allume_vitraux(u8 (*param_1)[5])
{
    __builtin_memcpy(PS1_CurrentVitrailClignotement, param_1, sizeof(*param_1));
}

/* 13B60 80138360 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138360);
#else
void FUN_80138360(u8 *vitrail_clignotement)
{
    u8 i;
    BackgroundPosition *bg_pos;
    Sprite *bg_sprite;
    DR_ENV *dr_env = PS1_CurrentDisplay->field6_0x2b0;

    for (i = 0; i < NbSprite; i++)
    {
        if (vitrail_clignotement[i] != 0)
        {
            bg_pos = &PS1_BackgroundPositions[i];
            bg_sprite = &PS1_BackgroundSprites[i];
            /* gross... */
            SetSemiTrans((PS1_CurrentDisplay->sprites + D_801E4BC8), 1);
            SetShadeTex((PS1_CurrentDisplay->sprites + D_801E4BC8), 0);
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->r0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->g0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->b0 = PS1_Glass_brightness[i];
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->u0 = bg_sprite->page_x;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->v0 = bg_sprite->page_y;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->w = bg_sprite->width;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->h = bg_sprite->height;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->clut = bg_sprite->clut;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->x0 = bg_pos->x;
            (PS1_CurrentDisplay->sprites + D_801E4BC8)->y0 = bg_pos->y;
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
                vitrail_clignotement[i] = 0;
                D_801C71C0[i] = 0;
            }
            else
                D_801C71C0[i]++;
        }
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138718);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138b84);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_DisplayWorldMapBg2);

void FUN_801392c8(void) {}

void FUN_801392d0(void) {}

/* three parts of rodata with same length? */
INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_80127734);

INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_8012776C);

INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_801277A4);
