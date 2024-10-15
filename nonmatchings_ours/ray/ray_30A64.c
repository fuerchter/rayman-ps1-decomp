#include "ray/ray_30A64.h"

/* matches, but unk_y_2 */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_30A64", move_up_ray);*/

void move_up_ray(void)
{
    s16 unk_y_1;
    s16 unk_y_2;

    if (ray_mode == MODE_RAY_ON_MS && RayCoince(2))
        ray.speed_y = 0;
    
    if (!(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40) && ray.scale == 0)
        unk_y_1 = 25;
    else
        unk_y_1 = 40;
    
    ray.y_pos += ray.speed_y;
    unk_y_2 = 20;
    if (ray.y_pos < scroll_start_y - (unk_y_1 + unk_y_2))
    {
        ray.y_pos = scroll_start_y - (unk_y_1 + unk_y_2);
        ray.speed_y = 0;
        if (ray.field20_0x36 != -1)
            RAY_HIT(ray.iframes_timer == -1, null);
    }
    calc_obj_pos(&ray);
    v_scroll_speed = 0;
}