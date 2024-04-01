#include "collision/block_6E5E0.h"

/* 6E5E0 80192DE0 -O2 -msoft-float */
u8 MURDUR(s16 x, s16 y)
{
    return PS1_BTYPAbsPos(x, y) == BTYP_SOLID;
}

/* 6E618 80192E18 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", dist_to_bloc_floor);
#else
s16 dist_to_bloc_floor(s16 btyp, s16 x, s16 y)
{
    __asm__("nop");

    switch (btyp)
    {
    case BTYP_SOLID_RIGHT_45:
    case BTYP_SLIPPERY_RIGHT_45:
        x = 15 - x;
        break;
    case BTYP_SOLID_LEFT_45:
    case BTYP_SLIPPERY_LEFT_45:
        break;
    case BTYP_SOLID_RIGHT1_30:
    case BTYP_SLIPPERY_RIGHT1_30:
        x = 15 - (x >> 1);
        break;
    case BTYP_SOLID_RIGHT2_30:
    case BTYP_SLIPPERY_RIGHT2_30:
        x = 7 - (x >> 1);
        break;
    case BTYP_SOLID_LEFT1_30:
    case BTYP_SLIPPERY_LEFT1_30:
        x = x >> 1;
        break;
    case BTYP_SOLID_LEFT2_30:
    case BTYP_SLIPPERY_LEFT2_30:
        x = 8 + (x >> 1);
        break;
    case BTYP_RESSORT:
    case BTYP_SOLID_PASSTHROUGH:
    case BTYP_SOLID:
    case BTYP_SLIPPERY:
        x = 0;
        break;
    case BTYP_NONE:
    case BTYP_CHDIR:
    default:
        x = y;
        break;
    }
    return x - y;
}
#endif

/* 6E6BC 80192EBC -O2 -msoft-float */
s16 bloc_floor(s16 btyp, s16 x, s16 y)
{
    s16 lt_z = -(dist_to_bloc_floor(btyp, x, y) <= 0);
    return btyp & lt_z;
}

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", calc_typ_trav);

/* still pretty unreadable... */
/* 6EA38 80193238 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", calc_typ_travd);
#else
u8 calc_typ_travd(Obj *obj, u8 param_2)
{
    s16 spd_x_sgn = obj->speed_x; /* ??? */
    s16 x_offs_1;
    s32 unk_1;
    s16 x_saved;
    s16 x_offs_2;
    s16 foll_x; s16 foll_y; s16 foll_w; s16 foll_h;
    u8 unk_2;
    s32 res;

    /* sgn() on android */
    if (obj->speed_x >= 0)
        spd_x_sgn = obj->speed_x > 0;
    else
        spd_x_sgn = -1;

    if (spd_x_sgn != 0)
    {
        x_offs_1 = 14;
        if (obj->type == TYPE_RAYMAN)
        {
            unk_1 = 4;
            if (ray.scale != 0)
            {
                x_offs_1 = 8;
                unk_1 = 2;
            }

            if (ray.field23_0x3c != -1)
                x_offs_1 -= unk_1;
        }
        x_offs_1 *= spd_x_sgn;
        if (param_2)
            x_offs_1 = -x_offs_1;
        x_saved = obj->x_pos;
        obj->x_pos += x_offs_1;
        if (!param_2)
        {
            x_offs_2 = obj->speed_x;
            if (flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_X & 1)
                x_offs_2 /= 16;
            obj->x_pos -= x_offs_2;
        }

        if (obj->flags & FLG(OBJ_FOLLOW_ENABLED))
            GET_SPRITE_POS(obj, obj->follow_sprite, &foll_x, &foll_y, &foll_w, &foll_h);
        else
            foll_y = 0;
        
        unk_2 = ashr16(- (foll_y + obj->offset_hy) + obj->offset_by, 4);
        if (obj->type == TYPE_RAYMAN && ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40)
            unk_2 = ashr16(unk_2, 1);
        if (unk_2 != 0)
            unk_2--;
        res = calc_typ_trav(obj, unk_2);
        obj->x_pos = x_saved;
    }
    else
        res = 0;

    __asm__("nop");
    return res;
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_FIN_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", CALC_MOV_ON_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", recale_position);
