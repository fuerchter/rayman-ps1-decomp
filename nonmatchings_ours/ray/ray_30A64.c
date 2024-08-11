#include "ray/ray_30A64.h"

/*INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", move_up_ray);*/

void move_up_ray(void)
{
    s32 temp_v1;
    s32 var_a1;
    s16 temp_v0;
    s16 test_1;

    if (ray_mode == 2 && RayCoince(2))
    {
        ray.speed_y = 0;
    }
    
    if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) && (ray.scale == 0))
    {
        var_a1 = 0x19;
    }
    else
        var_a1 = 0x28;
    
    ray.y_pos += ray.speed_y;
    test_1 = scroll_start_y;
    temp_v1 = var_a1 + 0x14;
    if ((s16) ray.y_pos < (test_1 - temp_v1))
    {
        ray.y_pos = test_1 - temp_v1;
        ray.speed_y = 0;
        if (ray.field20_0x36 != -1)
        {
            RAY_HIT(~ray.iframes_timer == 0, null);
        }
    }
    calc_obj_pos(&ray);
    v_scroll_speed = 0;
}