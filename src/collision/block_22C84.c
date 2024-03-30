#include "collision/block_22C84.h"

/**/
extern u16 PS1_RandSum;
extern s16 RandomIndex;

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

/* 2344C 80147C4C -O2 -msoft-float */
void GET_BB1_ZDCs(Obj *obj, s16 *x_1, s16 *y_1, s16 *w_1, s16 *h_1, s16 *x_2, s16 *y_2, s16 *w_2, s16 *h_2)
{
    s16 spr_ind = 6;
    s16 h_loc;

    GET_ANIM_POS(obj, x_1, y_1, w_1, &h_loc);
    if (obj->main_etat == 2 && (obj->sub_etat == 0 || obj->sub_etat == 4))
        spr_ind = 3;
    GET_SPRITE_POS(obj, spr_ind, x_1, y_1, w_1, h_1);
    *x_2 = *x_1 - 7;
    *y_2 = *y_1 + *h_1;
    *w_2 = *w_1 + 14;
    *h_2 = h_loc >> 1;
    *x_1 += 4;
    *w_1 -= 8;
    *y_1 += 4;
    *h_1 -= 8;
    if (obj->main_etat == 0 && (obj->sub_etat == 16 || obj->sub_etat == 19))
        GET_SPRITE_POS(obj, 0, x_1, y_1, w_1, h_1);
}

#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", myRand);
#else
s32 myRand(s16 max_incl)
{
  s16 max_loc;
  
  __asm__("nop\nnop");

  max_loc = max_incl + 1;
  PS1_RandSum += RandArray[RandomIndex & (sizeof(RandArray) / sizeof(s16) - 1)];
  RandomIndex++;
  return (s16) (PS1_RandSum % (max_loc));
}
#endif

/* 23674 80147E74 -O2 -msoft-float */
void calc_obj_dir(Obj *obj)
{
    if (ray.x_pos + ray.offset_bx - obj->x_pos - obj->offset_bx > 0)
        obj->flags |= FLG(OBJ_FLIP_X);
    else
        obj->flags &= ~FLG(OBJ_FLIP_X);
}

/* 236C4 80147EC4 -O2 -msoft-float */
s32 OBJ_IN_ZONE(Obj *obj)
{
    switch(obj->type)
    {
    case TYPE_BADGUY2:
    case TYPE_BADGUY3:
    case TYPE_LIDOLPINK:
    case TYPE_LIDOLPINK2:
        return obj->detect_zone_flag == 1;
    default:
        return obj->detect_zone_flag != 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_obj_pos);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", makeUturn);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", BTYP);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", DO_OBJ_REBOND_EN_X);

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp);
