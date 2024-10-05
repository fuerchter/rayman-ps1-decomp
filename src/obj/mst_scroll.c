#include "obj/mst_scroll.h"

/* 4D354 80171B54 -O2 -msoft-float */
void DO_MST_SCROLL_COMMAND(Obj *obj, s16 param_2)
{
    s16 unk_x; s16 unk_y;

    unk_x = param_2;
    if (obj->hit_points == 0)
    {
        switch (obj->timer)
        {
        case 0:
            obj->field20_0x36 = ray.x_pos - 50;
            obj->iframes_timer = ray.y_pos - 80;
            unk_x = 1;
            unk_y = 1;
            break;
        case 1:
            if (scroll_x == -1)
                obj->timer = 2;
            obj->field20_0x36 = xmap + obj->field23_0x3c - 100;
            obj->iframes_timer = ymap + obj->field24_0x3e - 10;
            unk_x = h_scroll_speed + 1;
            unk_y = 2;
            break;
        case 2:
            obj->field23_0x3c = 500;
            obj->field20_0x36 = xmap + 1000;
            obj->iframes_timer = ray.y_pos - 125;
            unk_y = 1;
            unk_x = 3;
            break;
        }

        if (!(scroll_x == -1 || obj->timer == 2))
            obj->timer = 1;
        
        if (horloge[5] != 0)
        {
            if (obj->field20_0x36 > obj->x_pos)
            {
                obj->speed_x++;
                MIN_2(obj->speed_x, unk_x);

                if (obj->field20_0x36 < (obj->x_pos + obj->speed_x))
                    obj->speed_x = unk_x - 1;
            }
            else
            {
                obj->speed_x--;
                MAX_2(obj->speed_x, -1);
            }

            if (obj->y_pos + obj->speed_y < obj->iframes_timer)
            {
                obj->speed_y++;
                MIN_2(obj->speed_y, unk_y);
            }
            else if (obj->y_pos + obj->speed_y - unk_y > obj->iframes_timer)
            {
                obj->speed_y--;
                MAX_2(obj->speed_y, -unk_y);
            }
            else
                obj->speed_y = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/mst_scroll", DO_MST_CHANGE_COMMAND);
