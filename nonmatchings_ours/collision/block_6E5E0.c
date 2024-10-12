#include "collision/block_6E5E0.h"

/* score of 440 */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", calc_typ_trav);*/

s32 calc_typ_trav(Obj *obj, u8 param_2)
{
    s16 temp_v0_0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v1_0;
    s16 var_a0_2;
    s32 temp_a0;
    s32 temp_s0;
    s32 var_a0_0;
    s32 var_s0_1;
    s32 var_s0_2;
    s32 var_s2;
    u8 var_s3_2;
    s32 var_v0_1;
    s32 var_v0_2;
    s16 temp_s1;
    s32 temp_v1_2;
    u8 var_s3_1;
    s16 test_3;

    var_s3_1 = param_2;
    var_v0_1 = 0;
    var_s0_1 = 0;
    if ((obj->type == 0x17) && (obj->scale != 0))
    {
        var_s3_1 = ashr16(var_s3_1 & 0xFF, 1U);
        if (
            !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) && !(test_3 & 0xFF))
        {
            var_s3_1 = 1;
        }
    }
    temp_v1_0 = obj->offset_bx + (u16) obj->x_pos;
    temp_v0_0 = obj->offset_by + (u16) obj->y_pos;
    var_v0_2 = 0 << 0x10;
    switch (PS1_BTYPAbsPos((s32) temp_v1_0, (s32) temp_v0_0))
    {
    case BTYP_NONE:
    case BTYP_CHDIR:
    case BTYP_HURT:
    case BTYP_WATER:
    case BTYP_SPIKES:
    case BTYP_CLIFF:
        var_s0_1 += 8 - (u16) obj->speed_y;
        break;
    case BTYP_SOLID_RIGHT_45:
    case BTYP_SLIPPERY_RIGHT_45:
        if (obj->speed_x >= 0)
        {
            var_s0_1 += 0x11;
        }
        break;
    case BTYP_SOLID_LEFT_45:
    case BTYP_SLIPPERY_LEFT_45:
        if (obj->speed_x <= 0)
        {
            var_s0_1 += 0x11;
        }
        break;
    case BTYP_SOLID_RIGHT1_30:
    case BTYP_SOLID_RIGHT2_30:
    case BTYP_SLIPPERY_RIGHT1_30:
    case BTYP_SLIPPERY_RIGHT2_30:
        if (obj->speed_x >= 0)
        {
            var_s0_1 += 0x11;
            
        }
        else
        {
            var_s0_1 += 2;
        }
        break;
    case BTYP_SOLID_LEFT1_30:
    case BTYP_SOLID_LEFT2_30:
    case BTYP_SLIPPERY_LEFT1_30:
    case BTYP_SLIPPERY_LEFT2_30:
        if (obj->speed_x <= 0)
        {
            var_s0_1 += 0x11;
            
        }
        else
        {
            var_s0_1 += 2;
        }
        break;
    case BTYP_RESSORT:
    case BTYP_SOLID_PASSTHROUGH:
    case BTYP_SOLID:
    case BTYP_SLIPPERY:
        temp_v1_2 = obj->btypes[0];
        if ((s32) temp_v1_2 >= 2)
        {
            if ((s32) temp_v1_2 >= 4)
            {
                if ((s32) temp_v1_2 < 0x14)
                {
                    if ((s32) temp_v1_2 >= 0x12)
                    {
                        var_s0_1 += 8;
                    }
                }
            }
            else
            {
                var_s0_1 += 8;
            }
        }
        switch (PS1_BTYPAbsPos(temp_v1_0, temp_v0_0 - 0x10))
        {
        case BTYP_NONE:
        case BTYP_CHDIR:
        case BTYP_HURT:
        case BTYP_WATER:
        case BTYP_SPIKES:
        case BTYP_CLIFF:
            var_s0_1 += 9;
            break;
        case BTYP_SOLID_RIGHT_45:
        case BTYP_SLIPPERY_RIGHT_45:
            if (obj->speed_x >= 0)
            {
                var_s0_1 += 0x19;
            }
            break;
        case BTYP_SOLID_LEFT_45:
        case BTYP_SLIPPERY_LEFT_45:
            if (obj->speed_x <= 0)
            {
                var_s0_1 += 0x19;
            }
            break;
        case BTYP_SOLID_RIGHT1_30:
        case BTYP_SOLID_RIGHT2_30:
        case BTYP_SLIPPERY_RIGHT1_30:
        case BTYP_SLIPPERY_RIGHT2_30:
            if (obj->speed_x >= 0)
            {
                var_s0_1 += 0x11;
                
            }
            else
            {
                var_s0_1 += 2;
            }
            break;
        case BTYP_SOLID_LEFT1_30:
        case BTYP_SOLID_LEFT2_30:
        case BTYP_SLIPPERY_LEFT1_30:
        case BTYP_SLIPPERY_LEFT2_30:
            if (obj->speed_x <= 0)
            {
                var_s0_1 += 0x11;
                
            }
            else
            {
                var_s0_1 += 2;
            }
            break;
        case BTYP_LIANE:
            var_s0_1 += 1;
            break;
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        default:
            var_s0_1 += 8;
            break;
        }
        break;
    case 11:
    case 12:
    case 13:
    case 16:
    case 17:
    case 26:
    case 27:
    case 28:
    case 29:
    default:
        /* on android default case has 0 */
        break;
    }
    temp_s0 = (s16) var_s0_1;
    var_s3_1 = var_s3_1 - ashr16(temp_s0, 4U);
    if ((var_s3_1) >= 0x81U)
    {
        var_s3_1 = 0;
    }
    ashr16(temp_v1_0, 4U);
    ashr16(temp_v0_0 - temp_s0, 4U);
    var_s0_2 = 0;
    var_s2 = 0;
    while (var_s3_1 >= var_s0_2)
    {
        
        if (((s16) MURDUR(temp_v1_0, (temp_v0_0 - temp_s0) - ((var_s3_1 - var_s0_2) * 0x10))) != 0)
        {
            var_s2 += 1;
        }
        var_s0_2 += 1;
    }
    
    if (var_s2 & 0xFF)
    {
        var_v0_1 = 0x0000000F;
    }
    return var_v0_1;
}

/* score of 2125 */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_6E5E0", CALC_MOV_ON_BLOC);*/

void CALC_MOV_ON_BLOC(Obj *obj)
{
    s16 temp_s0_1;
    s16 temp_s0_3;
    s32 temp_s1_1;
    s16 temp_s1_2;
    u8 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v1_6;
    s32 var_s1;
    s16 var_v0_2;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_s4;
    s32 var_s0;
    s32 var_s2_1;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;

    /*var_s2_1 = saved_reg_s2;*/
    temp_v1 = obj->type;
    temp_a0 = temp_v1 * 4;
    if ((flags[temp_v1].flags2 & 1) || (temp_v1 == 0x17))
    {
        if ((((u8) flags[temp_v1].flags1 >> 4) & 1) && (temp_v1 != 0x17))
        {
            var_s5 = instantSpeed(obj->speed_x);
        }
        else
        {
            var_s5 = (s32) (u16) obj->speed_x;
        }
        var_s0 = var_s5 + ((obj->offset_bx + (u16) obj->x_pos) & 0xF);
        var_s4 = (obj->offset_by + (u16) obj->y_pos) & 0xF;
        if ((obj->type == 0x17) && (ray.field23_0x3c != -1))
        {
            if ((s16) var_s5 > 0)
            {
                var_s0 = 0x0000000F;
            }
            else if ((s16) var_s5 < 0)
            {
                var_s0 = 0;
            }
            temp_v1_2 = obj->btypes[0];
            switch (temp_v1_2)
            {
            case 0:
            case 1:
            case 8:
            case 10:
            case 24:
            case 25:
                var_s2_1 = var_s4 + 1;
                break;
            case 2:
            case 18:
                var_s2_1 = 0xF - var_s0;
                break;
            case 3:
            case 19:
                var_s2_1 = var_s0;
                break;
            case 4:
            case 20:
                var_s2_1 = 0xF - (((s16) var_s0) >> 1);
                break;
            case 5:
            case 21:
                var_s2_1 = 7 - (((s16) var_s0) >> 1);
                break;
            case 6:
            case 22:
                var_s2_1 = (((s16) var_s0) >> 1);
                break;
            case 7:
            case 23:
                var_s2_1 = (((s16) var_s0) >> 1) + 8;
                break;
            case 12:
                var_s2_1 = var_s4;
                break;
            case 9:
            case 14:
            case 15:
            case 30:
                var_s2_1 = 0;
                break;
            }
            var_s4 = var_s2_1;
            

        }
        else
        {
            temp_v1_3 = obj->btypes[0];
            /*var_s1 = saved_reg_s2 - var_s4;*/
            switch (temp_v1_3)
            {
            case 0:
            case 1:
            case 8:
            case 10:
            case 24:
            case 25:
                var_s2_1 = var_s4 + 1;
                break;
            case 2:
            case 18:
                var_s2_1 = 0xF - var_s0;
                break;
            case 3:
            case 19:
                var_s2_1 = var_s0;
                break;
            case 4:
            case 20:
                var_s2_1 = 0xF - (((s16) var_s0) >> 1);
                break;
            case 5:
            case 21:
                var_s2_1 = 7 - (((s16) var_s0) >> 1);
                break;
            case 6:
            case 22:
                var_s2_1 = (((s16) var_s0) >> 1);
                break;
            case 7:
            case 23:
                var_s2_1 = (((s16) var_s0) >> 1) + 8;
                break;
            case 12:
                var_s2_1 = var_s4;
                break;
            case 9:
            case 14:
            case 15:
            case 30:
                var_s2_1 = 0;
                break;
            }
        }
        var_s1 = var_s2_1 - var_s4;
        var_s0 = var_s5 + (obj->x_pos + obj->offset_bx);
        temp_s1_1 = var_s1 + (obj->y_pos + obj->offset_by);
        temp_v0_1 = PS1_BTYPAbsPos((s16) var_s0, (s16) temp_s1_1);
        var_s0 = var_s0 & 0xF;
        var_s4 = temp_s1_1 & 0xF;
        switch (temp_v0_1)
        {
        case 0:
        case 1:
        case 8:
        case 10:
        case 24:
        case 25:
            temp_s1_2 = var_s5 + (obj->x_pos + obj->offset_bx);
            temp_s0_3 = var_s1 + (obj->y_pos + obj->offset_by) + 0x10;
            temp_v0_2 = dist_to_bloc_floor(PS1_BTYPAbsPos((s16) temp_s1_2, (s16) temp_s0_3), temp_s1_2 & 0xF, temp_s0_3 | ~0xF);
            if (temp_v0_2 >= 3)
            {
            case 12:
                var_s2_1 = var_s4;
            }
            else
            {
                var_s2_1 = var_s4 + temp_v0_2;
            }
            break;
        case 2:
        case 18:
            var_s2_1 = 0xF - var_s0;
            break;
        case 3:
        case 19:
            var_s2_1 = var_s0;
            break;
        case 4:
        case 20:
            var_s2_1 = 0xF - (((s16) var_s0) >> 1);
            break;
        case 5:
        case 21:
            var_s2_1 = 7 - (((s16) var_s0) >> 1);
            break;
        case 6:
        case 22:
            var_s2_1 = (((s16) var_s0) >> 1);
            break;
        case 7:
        case 23:
            var_s2_1 = (((s16) var_s0) >> 1) + 8;
            break;
        case 9:
        case 14:
        case 15:
        case 30:
            temp_v1_5 = PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx + (s16) var_s5, (obj->y_pos + obj->offset_by + (s16) var_s1) - 0x10) & 0xFF;
            var_s2_2 = 0;
            switch (temp_v1_5)
            {
            case 2:
            case 18:
                var_s2_2 = 0xF - var_s0;
                break;
            case 3:
            case 19:
                var_s2_2 = var_s0;
                break;
            case 4:
            case 20:
                var_s2_2 = 0xF - (((s16) var_s0) >> 1);
                break;
            case 5:
            case 21:
                var_s2_2 = 7 - (((s16) var_s0) >> 1);
                break;
            case 6:
            case 22:
                var_s2_2 = (((s16) var_s0) >> 1);
                break;
            case 7:
            case 23:
                var_s2_2 = (((s16) var_s0) >> 1) + 8;
                break;
            case 0:
            case 1:
            case 8:
            case 10:
            case 12:
            case 24:
            case 25:
                var_s2_2 = 0x00000010;
                break;
            case 9:
            case 11:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
                var_s2_2 = 0;
                break;
            }
            var_s2_1 = (var_s2_2 - 0x10);
            var_s2_1 = var_s4 + var_s2_1;
            break;
        }
        if (!(IS_ON_RESSORT_BLOC(obj) & 0xFF))
        {
            if (obj->type == 0x17)
            {
                if (
                    (ray.field20_0x36 == -1 && ray.main_etat != 2) &&
                    (
                        temp_v1_6 = obj->speed_y,
                        ((u32) (__builtin_abs(temp_v1_6) - 3) < 0xDU) &&
                        !(((u8) block_flags[temp_v0_1 & 0xFF] >> 1) & 1)
                    )
                )
                {
                    set_main_and_sub_etat(&ray, 0U, 0U);
                    button_released = 1;
                    ray_jump();
                    obj->speed_y = temp_v1_6;
                }
                else
                {
                    if (
                        ((ray.main_etat != 3) || ((ray.sub_etat != 0x20)) &&
                        (ray.sub_etat != 0x26) &&
                        ((ray.sub_etat != 0x16)))
                    )
                    {
                        obj->speed_y = (var_s1 + var_s2_1) - var_s4;
                        TEST_FIN_BLOC(obj);
                    }
                }

            }
            else
            {
block_72:
                obj->speed_y = (var_s1 + var_s2_1) - var_s4;
                TEST_FIN_BLOC(obj);
            }
        }
    }
}