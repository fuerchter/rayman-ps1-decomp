#include "draw.h"

extern u8 PS1_DrawSpriteSemiTrans;
extern void *PS1_PrevPrim;
extern s16 D_801CEF78;
extern s16 D_801CF600[16]; /* list of angles? */
extern u8 D_801E4C20;

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawColoredSprite);

/* 15340 80139B40 -O2 -msoft-float */
void PS1_DrawSprite(Sprite *sprite, s16 x, s16 y, u8 param_4)
{
    PS1_DrawColoredSprite(sprite, x, y, param_4);
}

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawScaledSprite);

/* 1555C 80139D5C -O2 -msoft-float */
void FUN_80139d5c(s16 *p_poly_x, s16 *p_poly_y, s16 param_3, s16 param_4, s16 angle)
{
    s16 old_poly_x = *p_poly_x;
    s16 old_poly_y = *p_poly_y;

    *p_poly_x = 
        (old_poly_x * rcos(angle) >> 12) -
        (old_poly_y * rsin(angle) >> 12) +
        (
            (param_3 - (param_3 * rcos(angle) >> 12)) +
            (param_4 * rsin(angle) >> 12)
        );
    *p_poly_y =
        (old_poly_x * rsin(angle) >> 12) +
        (old_poly_y * rcos(angle) >> 12) +
        (
            (param_4 - (param_4 * rcos(angle) >> 12)) -
            (param_3 * rsin(angle) >> 12)
        );
}

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
