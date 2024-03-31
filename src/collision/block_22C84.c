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

/* 235E8 80147DE8 -O2 -msoft-float */
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

/* 23730 80147F30 -O2 -msoft-float */
void calc_obj_pos(Obj *obj)
{
    obj->screen_y_pos = obj->y_pos - ymap;
    obj->screen_x_pos = obj->x_pos - xmap;
}

/* 2375C 80147F5C -O2 -msoft-float */
void makeUturn(Obj *obj)
{
    u8 label = 0xFF;
    u8 foll_spr;
    Obj *unk_1;
    
    switch(obj->type)
    {
    case TYPE_BLACKTOON1:
        foll_spr = obj->follow_sprite;
        if (foll_spr == 1 || foll_spr == 2 || obj->follow_sprite == 4 || obj->follow_sprite == 7)
        {
            if (obj->cmd == GO_LEFT)
            {
                label = 3;
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            else if (obj->cmd == GO_RIGHT)
            {
                label = 2;
                obj->flags &= ~FLG(OBJ_FLIP_X);
            }
        }
        break;
    case TYPE_MITE:
        if (!(obj->main_etat == 0 && obj->sub_etat == 3))
        {
            label = 3;
            obj->field20_0x36 = 0;
        }
        break;
    case TYPE_BADGUY1:
        if (
            !(obj->main_etat == 0 &&
            (obj->sub_etat == 3 || obj->sub_etat == 1 || obj->sub_etat == 4 ||
            obj->sub_etat == 5 || obj->sub_etat == 6))
        )
        {
            if (obj->cmd == GO_LEFT)
            {
                label = 1;
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            else if (obj->cmd == GO_RIGHT)
            {
                label = 0;
                obj->flags &= ~FLG(OBJ_FLIP_X);
            }
        }
        break;
    case TYPE_BADGUY2:
    case TYPE_BADGUY3:
        if (!(obj->main_etat == 0 && (obj->sub_etat == 3 || obj->sub_etat == 1)))
        {
            if (obj->flags & FLG(OBJ_READ_CMDS))
            {
                if (obj->cmd == GO_LEFT)
                {
                    label = 1;
                    obj->flags |= FLG(OBJ_FLIP_X);

                }
                else if (obj->cmd == GO_RIGHT)
                {
                    label = 0;
                    obj->flags &= ~FLG(OBJ_FLIP_X);
                }
            }
            else
            {
                if (obj->cmd == GO_LEFT)
                {
                    label = 6;
                    obj->flags |= FLG(OBJ_FLIP_X);
                }
                else if (obj->cmd == GO_RIGHT)
                {
                    label = 5;
                    obj->flags &= ~FLG(OBJ_FLIP_X);
                }
            }
        }
        break;
    case TYPE_GENEBADGUY:
        if (!(obj->main_etat == 0 && obj->sub_etat == 3))
        {
            if (obj->cmd == GO_LEFT)
            {
                label = 1;
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            else if (obj->cmd == GO_RIGHT)
            {
                label = 0;
                obj->flags &= ~FLG(OBJ_FLIP_X);
            }
        }
        break;
    case TYPE_STONEMAN1:
    case TYPE_STONEMAN2:
        if (obj->cmd == GO_LEFT)
        {
            label = 5;
            obj->flags |= FLG(OBJ_FLIP_X);
        }
        else if (obj->cmd == GO_RIGHT)
        {
            label = 4;
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        break;
    case TYPE_TROMPETTE:
        if (!(obj->main_etat == 0 && obj->sub_etat == 1))
        {
            if (obj->flags & FLG(OBJ_READ_CMDS))
            {
                if (obj->cmd == GO_LEFT)
                {
                    label = 1;
                    obj->flags |= FLG(OBJ_FLIP_X);
                }
                else if (obj->cmd == GO_RIGHT)
                {
                    label = 0;
                    obj->flags &= ~FLG(OBJ_FLIP_X);
                }
            }
        }
        break;
    case TYPE_BIG_CLOWN:
    case TYPE_WAT_CLOWN:
        if (obj->flags & FLG(OBJ_READ_CMDS))
        {
            if (obj->cmd == GO_LEFT)
            {
                label = 1;
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            else if (obj->cmd == GO_RIGHT)
            {
                label = 0;
                obj->flags &= ~FLG(OBJ_FLIP_X);
            }
        }
        break;
    case TYPE_SPIDER:
        if (obj->cmd == GO_LEFT)
        {
            label = 2;
            obj->flags |= FLG(OBJ_FLIP_X);
        }
        else
        {
            label = 0;
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        break; 
    case TYPE_MITE2:
        if (!(obj->flags & FLG(OBJ_FLIP_X)))
            obj->flags |= FLG(OBJ_FLIP_X);
        else
            obj->flags &= ~FLG(OBJ_FLIP_X);

        if (!(obj->main_etat == 0 && obj->sub_etat == 3))
        {
            label = 3;
            obj->field20_0x36 = 0;
        }
        break;
    case TYPE_CAISSE_CLAIRE:
        if (!(obj->main_etat == 0 && obj->sub_etat == 2))
        {
            set_main_and_sub_etat(obj, 1, 1);
            if (!(obj->flags & FLG(OBJ_FLIP_X)))
            {
                obj->flags |= FLG(OBJ_FLIP_X);
                label = 3;
            }
            else
            {
                obj->flags &= ~FLG(OBJ_FLIP_X);
                label = 2;
            }
        }
        break;
    case TYPE_WALK_NOTE_1:
        if (obj->cmd == GO_LEFT)
        {
            label = 2;
            obj->flags |= FLG(OBJ_FLIP_X);
        }
        else if (obj->cmd == GO_RIGHT)
        {
            label = 1;
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        break;
    case TYPE_SPIDER_PLAFOND:
        /* TODO: clean up somehow? */
        unk_1 = obj;
        if (!(obj->main_etat == 0 && (obj->sub_etat == 24 || unk_1->sub_etat == 18 || obj->sub_etat == 19)))
        {
            set_main_and_sub_etat(obj, 0, 24);
            obj->speed_y = 0;
            obj->speed_x = 0;
            obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | ((1 - (obj->flags >> OBJ_FLIP_X & 1) & 1) << OBJ_FLIP_X);
        }
        break;
    }

    if (label != 0xFF)
    {
        obj->x_pos -= obj->speed_x;
        obj->speed_x = 0;
        skipToLabel(obj, label, true);
    }
}

/* 23CAC 801484AC -O2 -msoft-float */
u16 BTYP(s16 x, s16 y)
{
    if (x >= 0 && (x <= mp.width - 1) && y >= 0 && (y <= mp.height - 1))
        return mp.map[x + y * mp.width] >> 10;
    return BTYP_NONE;
}

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);

/* 23F10 80148710 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", DO_OBJ_REBOND_EN_X);
#else
void DO_OBJ_REBOND_EN_X(Obj *obj)
{
  __asm__("nop\nnop");

  if (
    block_flags[obj->btypes[2]] >> BLOCK_FLAG_4 & 1 ||
    block_flags[obj->btypes[1]] >> BLOCK_FLAG_4 & 1
  )
    obj->speed_x = -obj->speed_x;
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp);
