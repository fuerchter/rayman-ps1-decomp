#include "collision/proj.h"

extern u8 zoom_mode;

/* 22754 80146F54 -O2 -msoft-float */
void set_proj_center(s16 param_1, s16 param_2)
{
    PROJ_CENTER_X = param_1;
    PROJ_CENTER_Y = param_2;
}

/* 2276C 80146F6C -O2 -msoft-float */
s32 get_proj_dist(s16 param_1, s16 param_2)
{
    if (zoom_mode == 0)
        return param_2;
    else
        return (s16) (0x10000 / (param_1 + 256) * param_2 / 256);
}

INCLUDE_ASM("asm/nonmatchings/collision/proj", get_proj_dist2);

INCLUDE_ASM("asm/nonmatchings/collision/proj", get_proj_x);

INCLUDE_ASM("asm/nonmatchings/collision/proj", get_proj_y);

INCLUDE_ASM("asm/nonmatchings/collision/proj", set_zoom_mode);

INCLUDE_ASM("asm/nonmatchings/collision/proj", inverse_proj_x);

INCLUDE_ASM("asm/nonmatchings/collision/proj", inverse_proj_y);
