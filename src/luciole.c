#include "luciole.h"

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

/* 3D44C 80161C4C -O2 -msoft-float */
void DO_LUCIOLE(void)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 unk_x_1;
    s16 unk_y_1;
    Obj *poing_obj = &level.objects[poing_obj_id];
    s16 x_ray_prev = x_ray[n_ray];
    s16 y_ray_prev = y_ray[n_ray];
    
    if (poing.is_active)
    {
        x_ray[n_ray] = poing_obj->x_pos + poing_obj->offset_bx;
        y_ray[n_ray] = poing_obj->y_pos + poing_obj->offset_by;
    }
    else
    {
        GET_SPRITE_POS(&ray, 2, &spr_x, &spr_y, &spr_w, &spr_h);
        x_ray[n_ray] = ray.x_pos + ray.offset_bx;
        y_ray[n_ray] = ray.y_pos + ray.offset_hy - 4;
        x_ray[n_ray] = spr_x + (spr_w < 2 ^ 1);
        y_ray[n_ray] = spr_y + (spr_h < 2 ^ 1);
    }
    n_ray++;
    n_ray &= LEN(x_ray) - 1;
    
    unk_x_1 = x_ray_prev - x_main_luc - vx_luc;
    if (unk_x_1 != 0)
        unk_x_1 = unk_x_1 > 0 ? 1 : -1;

    unk_y_1 = y_ray_prev - y_main_luc - vy_luc;
    if (unk_y_1 != 0)
        unk_y_1 = unk_y_1 > 0 ? 1 : -1;

    vx_luc += unk_x_1;
    MIN_2(vx_luc, 8);
    MAX_2(vx_luc, -8);

    vy_luc += unk_y_1;
    MIN_2(vy_luc, 8);
    MAX_2(vy_luc, -8);

    x_main_luc += vx_luc;
    y_main_luc += vy_luc;
    x_luc = x_main_luc - xmap;
    y_luc = y_main_luc - ymap;
}
