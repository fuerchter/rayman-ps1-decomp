#ifndef FOND_10B3C_H
#define FOND_10B3C_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "psyq_3_0/MEMORY.H"
#include "common/display.h"
#include "common/obj.h"
#include "common/rayconst.h"
#include "draw/draw_548CC.h" /* TODO: circular? */

typedef struct Unk_801f8008
{
    s16 unk_0;
    u8 unk_1;
    u8 unk_2; /* packed? */
} Unk_801f8008;

/*
see 8013726c,
BinarySerializer.Ray1/DataTypes/PS1/Vignette
if each field is u8, sizeof(RGBA5551Color) becomes 3
*/
typedef struct RGBA5551Color
{
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 a : 1;
} RGBA5551Color;

/* .data */
extern u16 D_801C71C0[5];

/* .data */
extern u8 PS1_Glass_brightness[5];
extern u8 PS1_Glass_brightness_diff[5];
extern u8 D_801CEF51;
extern u8 D_801CEF54[8];
extern u8 D_801CEF5C[8];
extern u8 D_801CEF64[8];
extern u8 D_801CEF6C[8];

/**/
extern u8 PS1_FondSpritesIsSemiTrans[16];
extern u8 PS1_FondSpritesABR[16];
extern u8 NbSprite;
extern DVECTOR *PS1_BackgroundPositions;
extern Sprite *PS1_BackgroundSprites;
extern u8 PS1_FondType;
extern u8 PS1_Tile_clut_y_offs[944]; /* see also loading_DA64.c */

/* types of all of these? */
extern Unk_801f8008 D_801E63F8[6]; /* size correct? */
extern u8 D_801F51C0;
extern u8 D_801F5788;
extern Unk_801f8008 D_801F8008[6]; /* size correct? */
extern u8 D_801FA560;
extern u8 PS1_BandeBackCount;
extern u8 PS1_BandeFrontCount;
extern u8 D_801F4F58;
extern s16 D_801F55B8[5]; /* 10 bytes, based on 80135944 */
extern u8 D_801F84E0;
extern u8 D_801F9900;
extern s16 PS1_FondHeight;

/*
u16 * or u32 * or RGBA5551Color * doesn't seem to work (see FUN_8013613c LoadImage call e.g.)?
*/
extern u8 *PS1_FondImages[6];

extern s16 PS1_FondImagesCount;
extern s16 PS1_FondWidth;
extern u8 D_801E4BC8; /* used as index into PS1_CurrentDisplay->sprites */
extern u8 PS1_CurrentVitrailClignotement[5];

void PS1_LoadFondSprites(void);
void PS1_LoadFondDataAndPalettes(void);
void PS1_LoadFond(void);
void FUN_80135ab0(s16 param_1, s16 *param_2); /* param_2 is pointer? see PS1_DisplayFondSprites */
void FUN_80135d5c(s32 param_1, u16 *param_2, s32 param_3, s16 param_4); /* param_2 is pointer? see PS1_DisplayFondSprites */
void FUN_8013613c(u8 param_1, u32 param_2, u8 param_3, u32 param_4);
void FUN_80136340(s16 *param_1, u32 param_2); /* param_1 is pointer? see PS1_DisplayFondSprites */
void FUN_801366ac(void);
void PS1_DisplayFondSprites(void);
u8 FUN_80137998(u8 param_1, u8 param_2, s32 param_3);
u8 PS1_GetTileV(u8 param_1, u8 param_2, s32 tile);
u8 PS1_GetTileU(s32 param_1);
void DRAW_MAP(void);
void FUN_80137cc8(s32 param_1, s16 *param_2); /* param_2 is pointer? see PS1_DisplayFondSprites */
void allume_vitraux(u8 (*param_1) [5]);
void FUN_80138360(u8 *vit_clig);
void FUN_80138718(u8 param_1);
void FUN_80138b84(s16 in_h_1, s16 *param_2, s16 in_h_2, s16 in_w_1);
void PS1_DisplayWorldMapBg2(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6);
void FUN_801392c8(void);
void FUN_801392d0(void);

#endif