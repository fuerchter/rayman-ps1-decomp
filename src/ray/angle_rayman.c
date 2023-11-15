#include "ray/angle_rayman.h"

#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap, missing_nop */
INCLUDE_ASM("asm/nonmatchings/ray/angle_rayman", ANGLE_RAYMAN);
#else
s16 ANGLE_RAYMAN(Obj *obj)
{
    s16 x;
    s16 y;
    u8 x_gt_0;
    u8 y_gt_0;
    u8 tab_val;
    s16 res;

    __asm__("nop\nnop\nnop\nnop\nnop\nnop");

    x = ray.offset_bx + (ray.x_pos - obj->x_pos - obj->offset_bx);
    y = ray.offset_by + (ray.y_pos - obj->y_pos - obj->offset_by);
    x_gt_0 = x > 0;
    y_gt_0 = y > 0;
    if (!x_gt_0)
        x = -x;
    if (!y_gt_0)
        y = -y;
    
    if (x > 200)
    {
        x = x >> 1;
        y = y >> 1;
    }

    if (y == 0)
    {
        if (x_gt_0)
            res = 384;
        else
            res = 128;
    }
    else
    {
        if (x < y)
            tab_val = angletab[(s16) ((x * 64) / y)];
        else
            tab_val = 128 - angletab[(s16) ((y * 64) / x)];
        if (x_gt_0)
        {
            if (y_gt_0)
                res = 384 - tab_val;
            else
                res = 384 + tab_val;
        }
        else
        {
            if (y_gt_0)
                res = 128 + tab_val;
            else
                res = 128 - tab_val;
        }

    }
    return res;
}
#endif