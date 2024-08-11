#include "ray/ray_30A64.h"

/* 30A64 80155264 -O2 -msoft-float */
s16 RayCoince(s16 dir)
{
    s16 x_pos;
    s16 y_pos;
    s32 pos_to_check;
    s32 map_ind;
    u8 res = false;
    
    if (ray.flags & FLG(OBJ_FLIP_X))
        x_pos = ray.x_pos + 70;
    else
        x_pos = ray.x_pos + 58;
    y_pos = ray.y_pos + 32;
    
    switch (dir)
    {
    case 2:
        pos_to_check = y_pos - (y_pos / 16 * 16);
        if ((s16) pos_to_check < 3)
        {
            map_ind = (x_pos >> 4) + (mp.width * (y_pos >> 4));
            if (block_flags[mp.map[map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
        }
        break;
    case 3:
        pos_to_check = y_pos - (y_pos / 16 * 16);
        if ((s16) pos_to_check > 12)
        {
            map_ind = (x_pos >> 4) + (mp.width * ((y_pos + 64) >> 4));
            if (block_flags[mp.map[map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[++map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
        }
        break;
    case 0:
        pos_to_check = x_pos - (x_pos / 16 * 16);
        if ((s16) pos_to_check < 3)
        {
            map_ind = ((x_pos >> 4) + (mp.width * ((y_pos + 16) >> 4))) - 1;
            if (block_flags[mp.map[map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
        }
        break;
    case 1:
        pos_to_check = x_pos - (x_pos / 16 * 16);
        if ((s16) pos_to_check > 12)
        {
            map_ind = ((x_pos >> 4) + (mp.width * ((y_pos + 16) >> 4))) + 3;
            if (block_flags[mp.map[map_ind] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
            if (block_flags[mp.map[map_ind += mp.width] >> 10] & FLG(BLOCK_FULLY_SOLID))
                res = true;
        }
        break;
    }

    return res;
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", move_up_ray);

/* 30E34 80155634 -O2 -msoft-float */
void move_down_ray(void)
{
    if (ray_mode == MODE_RAY_ON_MS && RayCoince(3))
        ray.speed_y = 0;
    
    ray.y_pos += ray.speed_y;
    calc_obj_pos(&ray);
    if (ray.main_etat == 2)
    {
        if ((scroll_end_y - ymap > ray.speed_y) && ray.screen_y_pos >= 100)
            v_scroll_speed = ray.speed_y;
        else
            v_scroll_speed = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", RecaleRayPosInJumelle);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", RAY_TO_THE_RIGHT);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", RAY_TO_THE_LEFT);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", FUN_80156040);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", TEST_FIN_FOLLOW);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", RAY_FOLLOW);

INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", DO_FIXE);
