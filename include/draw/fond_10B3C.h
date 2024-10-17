#ifndef FOND_10B3C_H
#define FOND_10B3C_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "psyq_3_0/MEMORY.H"
#include "common/display.h"
#include "common/obj.h"
#include "common/rayconst.h"
#include "draw/draw_548CC.h" /* TODO: circular? requires forward declaration... */

typedef struct BackgroundPosition BackgroundPosition;

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
extern BackgroundPosition *PS1_BackgroundPositions;
extern Sprite *PS1_BackgroundSprites;
extern u8 PS1_FondType;
extern u8 PS1_Tile_clut_y_offs[944]; /* see also loading_DA64.c */

/* types of all of these? */
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
extern u8 D_801F84E0;
extern u8 D_801F9900;
extern s16 PS1_FondHeight;
extern void *PS1_FondImages[6]; /* 0th five bits: r, 1st five bits: g, 2nd five bits b (see 8013726c) */
extern s16 PS1_FondImagesCount;
extern s16 PS1_FondWidth;
extern u8 D_801E4BC8; /* used as index into PS1_CurrentDisplay->sprites */
extern u8 PS1_CurrentVitrailClignotement[5];

void PS1_LoadFondSprites(void);
void PS1_LoadFondDataAndPalettes(void);
void PS1_LoadFond(void);
void FUN_80135ab0(s16 param_1, s16 *param_2); /* param_2 is pointer? see PS1_DisplayFondSprites */
void FUN_80135d5c(s32 param_1, s16 *param_2, s32 param_3, s16 param_4); /* param_2 is pointer? see PS1_DisplayFondSprites */
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
void PS1_DisplayWorldMapBg2(u16 param_1, u16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6);
void FUN_801392c8(void);
void FUN_801392d0(void);

#endif