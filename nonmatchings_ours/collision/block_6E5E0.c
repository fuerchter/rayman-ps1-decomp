#include "collision/block_6E5E0.h"

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
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s3_2;
    s32 var_v0_1;
    s32 var_v0_2;
    s16 temp_s1;
    s32 temp_v1_2;
    u8 var_s3;

    var_s3 = param_2;
    var_s0 = 0;
    if ((obj->type == 0x17) && (obj->scale != 0))
    {
        var_s3 = ashr16(var_s3 & 0xFF, 1U);
        if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) && !(var_s3 & 0xFF))
        {
            var_s3 = 1;
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
        var_s0 += 8 - (u16) obj->speed_y;
        var_v0_2 = var_s0 << 0x10;
        break;
    case BTYP_SOLID_RIGHT_45:
    case BTYP_SLIPPERY_RIGHT_45:
        var_v0_2 = var_s0 << 0x10;
        if (obj->speed_x >= 0)
        {
            var_s0 += 0x11;
            var_v0_2 = var_s0 << 0x10;
        }
        break;
    case BTYP_SOLID_LEFT_45:
    case BTYP_SLIPPERY_LEFT_45:
        var_v0_2 = var_s0 << 0x10;
        if (obj->speed_x <= 0)
        {
            var_s0 += 0x11;
            var_v0_2 = var_s0 << 0x10;
        }
        break;
    case BTYP_SOLID_RIGHT1_30:
    case BTYP_SOLID_RIGHT2_30:
    case BTYP_SLIPPERY_RIGHT1_30:
    case BTYP_SLIPPERY_RIGHT2_30:
    /*case 36:
    case 37:
    case 52:
    case 53:*/
        if (obj->speed_x < 0)
        {
            var_s0 += 2;
        }
        else
        {
            var_s0 += 0x11;
        }
        var_v0_2 = var_s0 << 0x10;
        break;
    /*case BTYP_SOLID_LEFT1_30:
    case BTYP_SOLID_LEFT2_30:
    case BTYP_SLIPPERY_LEFT1_30:
    case BTYP_SLIPPERY_LEFT2_30:
        if (obj->speed_x > 0)
        {
            var_s0 += 2;
        }
        else
        {
            var_s0 += 0x11;
        }
        var_v0_2 = var_s0 << 0x10;
        break;*/
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
                        var_s0 += 8;
                    }
                }
            }
            else
            {
                var_s0 += 8;
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
            var_s0 += 9;
            var_v0_2 = var_s0 << 0x10;
            break;
        case BTYP_SOLID_RIGHT_45:
        case BTYP_SLIPPERY_RIGHT_45:
            var_v0_2 = var_s0 << 0x10;
            if (obj->speed_x >= 0)
            {
                var_s0 += 0x19;
                var_v0_2 = var_s0 << 0x10;
            }
            break;
        case BTYP_SOLID_LEFT_45:
        case BTYP_SLIPPERY_LEFT_45:
            var_v0_2 = var_s0 << 0x10;
            if (obj->speed_x <= 0)
            {
                var_s0 += 0x19;
                var_v0_2 = var_s0 << 0x10;
            }
            break;
        case BTYP_SOLID_RIGHT1_30:
        case BTYP_SOLID_RIGHT2_30:
        case BTYP_SLIPPERY_RIGHT1_30:
        case BTYP_SLIPPERY_RIGHT2_30:
            if (obj->speed_x < 0)
            {
                var_s0 += 2;
            }
            else
            {
                var_s0 += 0x11;
            }
            var_v0_2 = var_s0 << 0x10;
            break;
        /*case BTYP_SOLID_LEFT1_30:
        case BTYP_SOLID_LEFT2_30:
        case BTYP_SLIPPERY_LEFT1_30:
        case BTYP_SLIPPERY_LEFT2_30:
            if (obj->speed_x > 0)
            {
                var_s0 += 2;
            }
            else
            {
                var_s0 += 0x11;
            }
            var_v0_2 = var_s0 << 0x10;
            break;*/
        case BTYP_LIANE:
            var_s0 += 1;
            var_v0_2 = var_s0 << 0x10;
            break;
        default:
            var_s0 += 8;
            var_v0_2 = var_s0 << 0x10;
            break;
        }
        break;
    /*case 11:
    case BTYP_LIANE:
    case 13:
    case 16:
    case 17:
    case 26:
    case 27:
    case 28:
    case 29:*/
    default:
        var_v0_2 = var_s0 << 0x10;
        /* on android default case has 0 */
        break;
    }
    temp_s0 = var_v0_2 >> 0x10;
    var_s3_2 = var_s3 - ashr16(temp_s0, 4U);
    if ((var_s3_2 & 0xFF) >= 0x81U)
    {
        var_s3_2 = 0;
    }
    ashr16(temp_v1_0, 4U);
    temp_s1 = temp_v0_0 - temp_s0;
    ashr16(temp_s1, 4U);
    var_s0_2 = 0;
    temp_a0 = var_s3_2 & 0xFF;
    var_s2 = 0;
    if (temp_a0 >= 0)
    {
        do
        {
            var_s0_2 += 1;
            if ((MURDUR(temp_v1_0, temp_s1 - ((temp_a0 - var_s0_2) * 0x10)) << 0x10) != 0)
            {
                var_s2 += 1;
            }
        } while (temp_a0 >= var_s0_2);
    }
    var_v0_1 = 0;
    if (var_s2 & 0xFF)
    {
        var_v0_1 = 0x0000000F;
    }
    return var_v0_1;
}