#include "luciole.h"

/* matches, but clean up further? */
/*INCLUDE_ASM("asm/nonmatchings/luciole", DO_LUCIOLE);*/

void DO_LUCIOLE(void)
{
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 *x_ray_2;
    s16 *y_ray_2;
    s16 unk_x_1;
    s16 unk_y_1;
    s32 test_1;
    s32 test_2;
    s32 test_3;
    s32 test_4;
    Obj *poing_obj = &level.objects[poing_obj_id];
    s16 *x_ray_1 = &x_ray[n_ray];
    s16 *y_ray_1 = &y_ray[n_ray];
    s16 x_ray_val = *x_ray_1;
    s16 y_ray_val = *y_ray_1;
    
    if (poing.is_active)
    {
        *x_ray_1 = poing_obj->x_pos + poing_obj->offset_bx;
        *y_ray_1 = poing_obj->y_pos + poing_obj->offset_by;
    }
    else
    {
        GET_SPRITE_POS(&ray, 2, &spr_x, &spr_y, &spr_w, &spr_h);
        x_ray_2 = &x_ray[n_ray];
        y_ray_2 = &y_ray[n_ray];
        *x_ray_2 = ray.offset_bx + ray.x_pos;
        test_1 = ((spr_w < 2) ^ 1);
        *y_ray_2 = (ray.offset_hy + ray.y_pos) - 4;
        test_2 = ((spr_h < 2) ^ 1);
        test_3 = spr_x + test_1;
        *x_ray_2 = test_3;
        test_4 = spr_y + test_2;
        *y_ray_2 = test_4;
    }
    n_ray++;
    n_ray &= LEN(x_ray) - 1;
    
    unk_x_1 = x_ray_val - x_main_luc - vx_luc;
    if (unk_x_1 != 0)
        unk_x_1 = unk_x_1 > 0 ? 1 : -1;

    unk_y_1 = y_ray_val - y_main_luc - vy_luc;
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