#include "fond_10B3C.h"

/* BinarySerializer.Ray1/DataTypes/PS1/Vignette */

void FUN_8017b260(u32 param_1);
extern u8 D_801F51BF;
extern s32 D_801F8170;
extern s32 D_801F8174;
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
extern void *PS1_FondImages[6];
extern s16 PS1_FondImagesCount;
extern s16 PS1_FondWidth;
extern u8 D_801E4BC8;

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondSprites);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondDataAndPalettes);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFond);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135ab0);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135d5c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_8013613c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80136340); /* NEXT */

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_801366ac);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_DisplayFondSprites);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80137998);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_GetTileV);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_GetTileU);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", DRAW_MAP);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80137cc8);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", allume_vitraux);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138360);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138718);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80138b84);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_DisplayWorldMapBg2);

void FUN_801392c8(void) {}

void FUN_801392d0(void) {}

/* three parts of rodata with same length? */
INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_80127734);

INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_8012776C);

INCLUDE_RODATA("asm/nonmatchings/fond_10B3C", D_801277A4);
