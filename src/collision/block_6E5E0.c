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

/* 6EC34 80193434 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_FIN_BLOC);
#else
void TEST_FIN_BLOC(Obj *obj)
{
    __asm__("nop");

    if (!(block_flags[obj->btypes[0]] >> BLOCK_SOLID & 1))
    {
        switch (obj->type)
        {
        case TYPE_RAYMAN:
            if (ray.main_etat == 1 && ray.sub_etat == 1)
                set_main_and_sub_etat(obj, 2, 6);
            else if (ray.main_etat == 1 && ray.sub_etat == 6)
                set_main_and_sub_etat(obj, 2, 23);
            else
            {
                IS_RAY_ON_LIANE();
                if (
                    !(hand_btyp == BTYP_LIANE || hand_btypd == BTYP_LIANE || hand_btypg == BTYP_LIANE ||
                    ray.main_etat == 5)
                )
                {
                    if (ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40)
                    {
                        ray.speed_y = 0;
                        ray.y_pos += 16;
                        ray.screen_y_pos += 16;
                    }

                    if (ray_on_poelle)
                    {
                        if (ray.main_etat == 0 && ray.sub_etat == 40)
                            set_main_and_sub_etat(obj, 2, 26);
                        else
                            set_main_and_sub_etat(obj, 2, 28);
                    }
                    else
                    {
                        if (ray.main_etat == 1 && (ray.sub_etat == 9 || ray.sub_etat == 11))
                            ray.flags = (ray.flags & ~FLG(OBJ_FLIP_X)) | ((ray.flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
                        if (__builtin_abs(ray.speed_x) < 3)
                        {
                            Reset_air_speed(false);
                            if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40))
                                set_main_and_sub_etat(obj, 2, 24);
                            else
                                set_main_and_sub_etat(obj, 2, 33);
                        }
                        else
                        {
                            Reset_air_speed(true);
                            set_main_and_sub_etat(obj, 2, 32);
                        }
                    }
                    jump_time = 0;
                    if (ray_last_ground_btyp == false || ray_wind_force != 0)
                        ray.nb_cmd = 1;
                    else
                        ray.nb_cmd = 0;
                }
            }
            break;
        case TYPE_LIDOLPINK:
            set_main_and_sub_etat(obj, 2, 2);
            skipToLabel(obj, 2, true);
            break;
        case TYPE_BADGUY1:
            set_main_etat(obj, 2);
            if (obj->sub_etat != 2)
                set_sub_etat(obj, 2);
            else
                set_sub_etat(obj, 10);
            break;
        case TYPE_BADGUY2:
        case TYPE_BADGUY3:
            set_main_and_sub_etat(obj, 2, 2);
            break;
        case TYPE_STONEDOG:
        case TYPE_STONEDOG2:
            skipToLabel(obj, 2, true);
            obj->gravity_value_2 = 7;
            obj->speed_y = 0;
            break;
        case TYPE_MITE:
            skipToLabel(obj, 0, true);
            break;
        case TYPE_SPIDER:
            obj->cmd_context_index = 0xFF;
            set_main_and_sub_etat(obj, 2, 0);
            skipToLabel(obj, 8, true);
            obj->speed_x = 0;
            obj->speed_y = 0;
            break;
        case TYPE_STONEWOMAN:
            set_main_and_sub_etat(obj, 2, 4);
            skipToLabel(obj, 15, false);
            break;
        }
        obj->field24_0x3e = 0;
        obj->gravity_value_1 = 0;
        if (!(obj->type == TYPE_STONEDOG || obj->type == TYPE_STONEDOG2))
            obj->gravity_value_2 = 0;
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", TEST_IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", IS_ON_RESSORT_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", CALC_MOV_ON_BLOC);

INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", recale_position);
