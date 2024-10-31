#include "collision/proj.h"

#ifdef BSS_DEFS
s16 PROJ_CENTER_X;
s16 PROJ_CENTER_Y;
u8 zoom_mode;
#endif

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

/* 227F0 80146FF0 -O2 -msoft-float */
s32 get_proj_dist2(s16 param_1, s16 param_2)
{
    return (s16) (0x10000 / (param_1 + 256) * param_2 >> 8);
}

/* 22850 80147050 -O2 -msoft-float */
s32 get_proj_x(s16 param_1, s16 param_2)
{
    return (s16) (0x10000 / (param_1 + 256) * (param_2 - PROJ_CENTER_X) / 256 + PROJ_CENTER_X);
}

/* 228D4 801470D4 -O2 -msoft-float */
s32 get_proj_y(s16 param_1, s16 param_2)
{
    return (s16) (0x10000 / (param_1 + 256) * (param_2 - PROJ_CENTER_Y) / 256 + PROJ_CENTER_Y);
}

/* 22958 80147158 -O2 -msoft-float */
void set_zoom_mode(u8 mode)
{
    zoom_mode = mode;
}

/* 22968 80147168 -O2 -msoft-float */
s32 inverse_proj_x(s16 param_1, s16 param_2)
{
    return (s16) ((param_2 - PROJ_CENTER_X) * 256 / (0x10000 / (param_1 + 256)) + PROJ_CENTER_X);
}

/* 22A00 80147200 -O2 -msoft-float */
s32 inverse_proj_y(s16 param_1, s16 param_2)
{
    return (s16) ((param_2 - PROJ_CENTER_Y) * 256 / (0x10000 / (param_1 + 256)) + PROJ_CENTER_Y);
}
