#include "draw.h"

extern u8 PS1_DrawSpriteSemiTrans;
extern void *PS1_PrevPrim;
extern s32 PS1_CurrentDisplay; /* TODO: see synchro_loop.c, main.c and others */
extern u8 PS1_Display1;

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawColoredSprite);

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawSprite);

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawScaledSprite);

INCLUDE_ASM("asm/nonmatchings/draw", FUN_80139d5c);

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawRay);

INCLUDE_ASM("asm/nonmatchings/draw", display_sprite);

INCLUDE_ASM("asm/nonmatchings/draw", display2);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_POING);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_CLING);

INCLUDE_ASM("asm/nonmatchings/draw", display_bar_boss);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_FIXE);

INCLUDE_ASM("asm/nonmatchings/draw", FUN_8013ad54);

INCLUDE_ASM("asm/nonmatchings/draw", DrawWldPointPlan2Normal);

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DisplayPtsPrim);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_POINT);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_PTS_TO_PLAN2);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_PLATEAU);

INCLUDE_ASM("asm/nonmatchings/draw", draw_flocon1_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_flocon2_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_flocon3_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_flocon4_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_flocon5_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", FUN_8013b294);

INCLUDE_ASM("asm/nonmatchings/draw", FUN_8013b304);

INCLUDE_ASM("asm/nonmatchings/draw", draw_pluie4_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_pluie5_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", draw_pluie6_Normal);

INCLUDE_ASM("asm/nonmatchings/draw", FUN_8013b4d4);

INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_behind);

INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_before);

INCLUDE_ASM("asm/nonmatchings/draw", display_pix_gerbes);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_CYMBALE);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_ALL_OBJECTS);
