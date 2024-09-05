#include "obj_util.h"

/*INCLUDE_ASM("asm/nonmatchings/obj_util", Projectil_to_RM);*/

/* 249D0 801491D0 -O2 -msoft-float */
void Projectil_to_RM(Obj *obj, s16 *speed_x, s16 *speed_y, s16 param_4, s16 param_5)
{
    s16 diff_y;
    s32 temp_v1_2;
    s16 diff_x;
    s16 abs_diff_x;
    s16 abs_diff_y;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 var_a0_2;
    s32 var_t5;
    s16 var_v0;

    *speed_x = 0;
    *speed_y = 0;
    diff_x = ((ray.offset_bx + obj->follow_x) - obj->x_pos) - obj->offset_bx;
    diff_y = ((ray.offset_by + obj->follow_y) - obj->y_pos) - obj->offset_by;
    abs_diff_x = __builtin_abs(diff_x);
    abs_diff_y = __builtin_abs(diff_y);
    if (diff_x != 0 && diff_y != 0)
    {
        if (abs_diff_y < abs_diff_x)
        {
            temp_lo_2 = diff_y / abs_diff_y;
            var_a0_2 = diff_x / abs_diff_y;
            var_t5 = temp_lo_2;
            *speed_x = param_4;
            if (diff_x <= 0)
                *speed_x = -param_4;
            temp_lo_2 = diff_y * param_5 / abs_diff_x;
            *speed_y = temp_lo_2;
            if ((s16) temp_lo_2 == 0)
            {
                temp_v1_2 = *speed_x;
                if (diff_x > 0)
                    var_v0 = temp_v1_2 + 0x10;
                else
                    var_v0 = temp_v1_2 - 0x10;
                *speed_x = var_v0;
            }
        }
        else
        {
            var_t5 = diff_y / abs_diff_x;
            var_a0_2 = diff_x / abs_diff_x;
            *speed_y = param_5;
            if (diff_y <= 0)
                *speed_y = -param_5;
            temp_lo_3 = diff_x * param_4;
            var_v0 = temp_lo_3 / abs_diff_y;
            *speed_x = var_v0;
        }
    }
    else if (diff_y == 0)
    {
        *speed_x = param_4;
        if (diff_x > 0)
            *speed_x = -param_4;
        var_a0_2 = -1;
        if (diff_x > 0)
            var_a0_2 = 1;
        var_t5 = 0;
    }
    else
    {
        *speed_y = param_5;
        if (diff_y <= 0)
        {
            *speed_y = -param_5;
        }
        var_a0_2 = 0;
        var_t5 = -1;
        if (diff_y > 0)
        {
            var_t5 = 1;
        }
    }

    if ((!(obj->flags & 0x4000) && *speed_x > 0) || (obj->flags & 0x4000 && *speed_x < 0))
    {
        *speed_x = -*speed_x;
        if (*speed_y == 0)
        {
            *speed_y = 2;
        }
    }
    obj->follow_x = obj->follow_x + ((var_a0_2 << 0x10) >> 0xF);
    obj->follow_y = obj->follow_y + ((var_t5 << 0x10) >> 0xF);
}