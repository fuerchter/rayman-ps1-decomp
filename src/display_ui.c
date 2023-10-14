#include "display_ui.h"

/* TODO: Display struct */

/* 19A38 8013E238 -O2 */
/*? ClearImage(s32, ?, ?, ?);*/
extern s32 PS1_CurrentDisplay;

void CLRSCR(void)
{
    ClearImage(PS1_CurrentDisplay + 0x14, 0, 0, 0);
}

/* 19A6C 8013E26C -O2 */
/*? PS1_DrawSprite(Sprite *, s16, s16, ?);
u8 myRand(?, ? *);*/

void display_etoile(s32 in_x, s32 in_y)
{
    u8 loc_star_spr[8];
    GrpStar *temp;
    GrpStar *star;
    u8 rand_res;
    s16 draw_x;
    s16 draw_y;
    u8 sprite;

    __builtin_memcpy(&loc_star_spr, &PS1_star_spr, sizeof(PS1_star_spr));
    
    temp = &grp_stars[current_star];
    star = temp;
    star->timer++;
    if (star->timer > star->length)
    {
        rand_res = myRand(7);
        star->timer = 0;
        star->length = myRand(5);
        star->dist = rand_res;
        star->sprite_table_index = rand_res;
    }
    draw_x = star->dist + (in_x - xmap) - 8;
    draw_y = star->dist + (in_y - ymap);
    if (
        draw_x > 0 && 320 - draw_x > 0 &&
        draw_y > 0 && 240 - draw_y > 0
    )
    {
        sprite = loc_star_spr[star->sprite_table_index];
        PS1_DrawSprite(
            &level.objects[poing_obj_id].sprites[sprite],
            draw_x,
            draw_y,
            0
        );
    }
    if (current_star < 30)
        current_star++;
}

/* 19C08 8013E408
/*? Bresenham(void (*)(s32, s32), s16, s16, s16, s32, s32, s32);
? GET_SPRITE_POS(u8 *, ?, u16 *, u16 *, u16 *, u16 *);*/

void display_grp_stars(void)
{
    Obj *grapped;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 cen_x;
    s16 grapped_x;

    if (ray.main_etat == 7 && (ray.flags & OBJ_ALIVE))
    {
        current_star = 0;
        grapped = &level.objects[id_obj_grapped];
        GET_SPRITE_POS(&ray, 1, &x, &y, &w, &h);

        cen_x = x + (w >> 1);
        grapped_x = grapped->offset_bx + grapped->x_pos;
        Bresenham(
            display_etoile,
            cen_x,
            (s16) (y + (h >> 1) - 6),
            grapped_x,
            (s16) (grapped->offset_hy + grapped->y_pos),
            5,
            100
        );
    }
}

/* 19D20 8013E520 -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_TEXT_FEE);

/* 1A04C 8013E84C -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DisplayJumellesNormal);

INCLUDE_ASM("asm/nonmatchings/display_ui", FUN_8013eb38);

INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_SAVE_SPRITES);

INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_SAVE_POING);

INCLUDE_ASM("asm/nonmatchings/display_ui", display_time);

INCLUDE_ASM("asm/nonmatchings/display_ui", FUN_8013f460);

INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_CONTINUE_SPR);

INCLUDE_ASM("asm/nonmatchings/display_ui", PS1_PromptCardDisplayPoing);

INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_OPTIONS_POING);
