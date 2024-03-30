#include "collision/block_22C84.h"

s16 PS1_BTYPAbsPos(s32, s32); /* see on_block_chdir() */

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_x);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_y);

/* 22F80 80147780 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", on_block_chdir);
#else
u8 on_block_chdir(Obj *obj, s16 offs_bx, s16 offs_by)
{
    __asm__("nop");

    return block_flags[PS1_BTYPAbsPos(obj->x_pos + offs_bx, obj->y_pos + offs_by)] >> BLOCK_CH_DIR & 1;
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", CALC_FOLLOW_SPRITE_SPEED);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_SPRITE_POS);

/* 23204 80147A04 -O2 -msoft-float */
void GET_RAY_ZDC(Obj *ray, s16 *x, s16 *y, s16 *w, s16 *h)
{
    u8 main_etat = ray->main_etat;
    s32 frame;

    if (ray->eta[main_etat][ray->sub_etat].flags & 0x40)
    {
        *x = ray->x_pos + 72;
        *y = ray->y_pos + 64;
        *w = 16;
        *h = 14;
    }
    else if (main_etat == 5)
    {
        *x = ray->x_pos + 72;
        *y = ray->y_pos + 40;
        *w = 16;
        *h = 46;
    }
    else if (main_etat == 7)
    {
        frame = ray->anim_frame;
        if (frame > 32)
            frame -= 32;
        frame -= 10;
        if ((s16) frame < 13U)
        {
            *x = ray->x_pos + 64;
            *y = ray->y_pos + 54;
            *w = 36;
            *h = 20;
        }
        else
        {
            *x = ray->x_pos + 70;
            *y = ray->y_pos + 40;
            *w = 20;
            *h = 40;
        }
    }
    else
    {
        *x = ray->x_pos + 72;
        *y = ray->y_pos + 24;
        *w = 16;
        *h = 54;
    }
    if (ray->scale != 0)
    {
        set_proj_center(ray->x_pos + ray->offset_bx, ray->y_pos + ray->offset_by);
        *x = get_proj_x(ray->scale, *x);
        *y = get_proj_y(ray->scale, *y);
        *w = get_proj_dist2(ray->scale, *w);
        *h = get_proj_dist2(ray->scale, *h);
        set_proj_center(ray->screen_x_pos + ray->offset_bx, ray->screen_y_pos + ray->offset_by);
    }
}

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_BB1_ZDCs);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", myRand);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_obj_dir);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", OBJ_IN_ZONE);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_obj_pos);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", makeUturn);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", BTYP);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", DO_OBJ_REBOND_EN_X);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp);
