#include "luciole.h"

extern s16 n_ray;
extern s16 vx_luc;
extern s16 vy_luc;
extern s16 x_main_luc;
extern s16 y_main_luc;
extern s16 x_ray[4];
extern s16 y_ray[4];

/* 3D384 80161B84 -O2 -msoft-float */
void INIT_LUCIOLE(void)
{
    u8 i;

    vx_luc = 0;
    vy_luc = 0;
    x_main_luc = ray.x_pos + ray.offset_bx;
    y_main_luc = ray.y_pos + ray.offset_hy - 16;
    x_luc = x_main_luc - xmap;
    y_luc = y_main_luc - ymap;
    for (i = 0; i < LEN(x_ray); i++)
    {
        x_ray[i] = x_main_luc;
        y_ray[i] = y_main_luc;
    }
    n_ray = 0;
}

INCLUDE_ASM("asm/nonmatchings/luciole", DO_LUCIOLE);
