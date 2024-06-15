#include "fond_10B3C.h"

void FUN_8017b260(u32 param_1);
extern u8 D_801F51BF;
extern s32 D_801F8170;
extern s32 D_801F8174;
extern u8 D_801FA55F;
extern u8 NbSprite;
extern BackgroundPosition *PS1_BackgroundPositions;
extern Sprite *PS1_BackgroundSprites;
extern u8 PS1_FondType;

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondSprites);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFondDataAndPalettes);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", PS1_LoadFond);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135ab0);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80135d5c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_8013613c);

INCLUDE_ASM("asm/nonmatchings/fond_10B3C", FUN_80136340);

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
