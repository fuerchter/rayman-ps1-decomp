#include "obj_update.h"

/* matches, but case 3 and 4??? */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_PESANTEUR);*/

s32 DO_PESANTEUR(Obj *obj)
{
    s16 temp_v0;
    s16 y_accel;
    s32 res;
    u8 temp_v1_1;

    res = 0;
    y_accel = 0;
    temp_v1_1 = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    if (temp_v1_1 != 0)
    {
        if (obj->type == TYPE_TAMBOUR1 || obj->type == TYPE_TAMBOUR2)
        {
            if (obj->field56_0x69 != 0)
                obj->field56_0x69--;
            else if (obj->gravity_value_1 == 0)
            {
                obj->speed_y++;
                res = 1;
            }
        }
        else
        {
            switch (temp_v1_1)
            {
            case 6:
                if (horloge[2] == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 1:
                if (obj->gravity_value_1 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 2:
                if (obj->gravity_value_2 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 3:
                temp_v0 = obj->speed_y;
                if (temp_v0 > 0)
                {
                    if (temp_v0 > 1)
                    {
                        y_accel = -1;
                    }
                }
                else
                {
                    y_accel = 1;
                }
                break;
            case 4:
                temp_v0 = obj->speed_y;
                if (temp_v0 < -1)
                {
                    if (temp_v0 < -2)
                    {
                        y_accel = 1;
                    }
                }
                else
                {
                    y_accel = -1;
                }
                break;
            case 5:
                if (obj->gravity_value_1 == 0)
                    y_accel = -1;
                break;
            case 10:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 11:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = -1;
                    res = 1;
                }
                break;
            }
        }
        if (flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1)
            y_accel = ashl16(y_accel, 4);
        obj->speed_y += y_accel;
    }
    return res;
}

/* div garbage */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_THROWN_BOMB_REBOND);*/

void DO_THROWN_BOMB_REBOND(Obj *obj, s16 param_2, s16 param_3)
{
    s16 temp_a2;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s32 temp_v0_7;
    s16 temp_v1_2;
    s16 var_v0_2;
    s32 temp_lo_1;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 var_v0_1;
    s32 var_v1_2;
    s32 var_v1_3;
    u8 var_v1;
    u8 temp_s0;
    u8 under;
    u8 temp_v1_1;
    u8 test_1;

    test_1 = 1;
    if (obj->main_etat == 2)
    {
        temp_v1_1 = obj->sub_etat;
        if (temp_v1_1 == 1)
        {
            DO_STONE_EXPLOSION();
            return;
        }
        if (temp_v1_1 == 0)
        {
            temp_s0 = obj->type;
            obj->type = 0x2F;
            DO_STONEBOMB_REBOND(obj);
            obj->type = temp_s0;
            return;
        }
        goto block_5;
    }
block_5:
    if (obj->speed_y >= 0)
    {
        under = underSlope(obj);
        if (under)
        {
            var_v1 = obj->btypes[3] & 0xFF;
        }
        else
        {
            var_v1 = obj->btypes[0] & 0xFF;
        }
        
        switch (var_v1)
        {
        case 0:
        case 30:
            break;
        case 2:
        case 18:
            if (obj->speed_y == 0)
                obj->speed_y++;
            var_v1_2 = 5 * obj->speed_y / 1;
            obj->speed_x -= var_v1_2;
            break;
        case 3:
        case 19:
            if (obj->speed_y == 0)
                obj->speed_y++;
            var_v1_3 = 5 * obj->speed_y / 1;
            obj->speed_x += var_v1_3;
            break;
        case 4:
        case 5:
        case 20:
        case 21:
            if (obj->speed_y == 0)
                obj->speed_y++;
            var_v1_2 = 3 * obj->speed_y / 1;
            obj->speed_x -= var_v1_2;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            if (obj->speed_y == 0)
                obj->speed_y++;
            var_v1_3 = 3 * obj->speed_y / 1;
            obj->speed_x += var_v1_3;
            break;
        case 9:
            if (obj->speed_y == 0)
                obj->speed_y++;
            break;
        }
        if (param_3 > 0)
        {
            if (obj->speed_y >= 2)
            {
                obj->speed_y = param_3 - obj->speed_y;
                if (param_2 != 0)
                {
                    obj->speed_y++;
                }
            }
            else
            {
                obj->speed_y = 0;
            }
        }
        else
        {
            obj->speed_y = -3;
        }
        if (under)
        {
            while (PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx, obj->y_pos + obj->offset_by) == obj->btypes[0])
                obj->y_pos--;
            recale_position(obj);
            calc_btyp(obj);
        }
        else if ((block_flags[obj->btypes[0]] & 1) && (prof_in_bloc(obj) >= 4) && (temp_v1_2 = obj->speed_y, ((temp_v1_2 < 3) != 0)))
        {
            if (temp_v1_2 == 0)
            {
                obj->speed_y = 1;
            }
        }
        else
        {
            recale_position(obj);
        }
    }
    obj->gravity_value_1 = 0;
    if ((u32) (((u8) obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4) - 0xA) >= 2U)
    {
        obj->gravity_value_2 = 0;
    }
}

/* matches, but cleanup*/
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_FRUIT_REBOND);*/

void DO_FRUIT_REBOND(Obj *obj, s16 param_2, s16 param_3)
{
    s16 temp_a0;
    s16 temp_a2;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v1;
    s16 temp_v1_3;
    s16 var_v0;
    s16 var_v0_3;
    s16 var_v0_4;
    s32 temp_lo_1;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s16 var_a0;
    s16 var_a1;
    s32 var_s1;
    u8 var_s2;
    s32 var_s3;
    s32 var_v0_2;
    s32 var_v1_2;
    s32 var_v1_3;
    u8 var_v1;
    u8 temp_v0_1;
    u8 temp_v1_2;
    u8 var_s4;

    if (obj->type == 0x26)
    {
        var_a0 = 1;
        var_a1 = 1;
        var_s3 = 1;
        var_s1 = 1;
        var_s4 = 1;
        var_s2 = 2;
    }
    else
    {
        var_a0 = 5;
        var_a1 = 4;
        var_s3 = 5;
        var_s1 = 3;
        var_s4 = 1;
        var_s2 = 1;
    }
    if (obj->speed_y >= 0)
    {
        temp_v1 = obj->speed_x;
        if (obj->speed_x > 0)
        {
            obj->speed_x = obj->speed_x - var_a0;
        }
        else if (obj->speed_x < 0)
        {
            obj->speed_x = obj->speed_x + var_a0;
        }
        temp_a0 = obj->speed_x;
        if ((-var_a1 <= temp_a0) && (var_a1 >= temp_a0))
        {
            obj->speed_x = 0;
        }
        temp_v0_1 = underSlope(obj);
        if (temp_v0_1)
        {
            var_v1 = obj->btypes[3];
        }
        else
        {
            var_v1 = obj->btypes[0];
        }
        switch (var_v1)
        {
        case 0:
        case 30:
            break;
        case 2:
        case 18:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= var_s3 * obj->speed_y / var_s4;
            break;
        case 3:
        case 19:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += var_s3 * obj->speed_y / var_s4;
            break;
        case 4:
        case 5:
        case 20:
        case 21:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x -= var_s1 * obj->speed_y / var_s2;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            if (obj->speed_y == 0)
                obj->speed_y++;
            obj->speed_x += var_s1 * obj->speed_y / var_s2;
            break;
        case 9:
            if (obj->speed_y == 0)
                obj->speed_y++;
            break;
        }
        if (param_3 > 0)
        {
            temp_v0_7 = obj->speed_y;
            if (temp_v0_7 >= 2)
            {
                temp_a2 = param_3 - temp_v0_7;
                obj->speed_y = temp_a2;
                if ((param_2 << 0x10) != 0)
                {
                    var_v0_3 = temp_a2 + 1;
                    obj->speed_y = var_v0_3;
                }
            }
            else
            {
                obj->speed_y = 0;
                obj->hit_points = 2;
            }
        }
        else
        {
            temp_v1_2 = obj->type;
            if ((temp_v1_2 == 8) || (temp_v1_2 == 0x86) || (temp_v1_2 == 0xA7) || (temp_v1_2 == 0xB1) || ((temp_v1_2 == 6)))
            {
                
                if (ray.field20_0x36 == obj->id)
                {
                    
                    if (ray.scale == 0)
                    {
                        obj->speed_y = -3;
                    }
                    else
                        obj->speed_y = -4;
                }
                else
                    obj->speed_y = -5;
                if (obj->type == 6)
                {
                    obj->speed_y++;
                }
            }
            else
            {
                obj->speed_y = -3;
            }
        }
        if (temp_v0_1)
        {
loop_62:
            if (PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx, obj->y_pos + obj->offset_by) == obj->btypes[0])
            {
                obj->y_pos = (u16) obj->y_pos - 1;
                goto loop_62;
            }
            calc_btyp(obj);
            recale_position(obj);
        }
        else
        {
            if ((block_flags[obj->btypes[0]] & 1) && (prof_in_bloc(obj) >= 4) && (temp_v1_3 = obj->speed_y, ((temp_v1_3 < 3) != 0)))
            {
                if (temp_v1_3 == 0)
                {
                    obj->speed_y = 1;
                }
            }
            else
            {
                recale_position(obj);
            }
        }

    }
    obj->gravity_value_1 = 0;
    if ((u32) (((u8) obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4) - 0xA) >= 2U)
    {
        obj->gravity_value_2 = 0;
    }
}