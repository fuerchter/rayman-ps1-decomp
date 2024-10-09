#include "pix_gerbe.h"
#include "rayconst.h"

/* matches, but clean up further? */
/*INCLUDE_ASM("asm/nonmatchings/pix_gerbe", do_pix_gerbes);*/

void do_pix_gerbes(void)
{
    s16 i;
    s32 unk_1;
    s16 new_active;
    PixGerbeItem *cur_item;
    s16 j;
    s16 x_old; s16 y_old;
    s16 h_speed = h_scroll_speed * 64;
    s16 v_speed = v_scroll_speed * 64;

    i = 0;
    unk_1 = 0xffff;
    while (i < (s16) LEN(pix_gerbe))
    {
        if (pix_gerbe[i].is_active == true)
        {
            new_active = false;
            cur_item = &pix_gerbe[i].items[0];
            j = 0;
            while (j < (s16) LEN(pix_gerbe[i].items))
            {
                if (cur_item->unk_1 >= 128)
                {
                    x_old = cur_item->x_pos;
                    cur_item->x_pos = cur_item->speed_x - h_speed;
                    cur_item->x_pos += x_old;

                    y_old = cur_item->y_pos;
                    cur_item->y_pos = cur_item->speed_y - v_speed;
                    cur_item->y_pos += y_old;
                    if ((((u16) (cur_item->x_pos + unk_1) >= SCREEN_WIDTH * 64) || (cur_item->y_pos > SCREEN_HEIGHT * 64)))
                        cur_item->unk_1 = 0;
                    else
                        new_active = true;
                    
                    cur_item->speed_y += cur_item->y_accel;
                }
                cur_item++;
                j++;
            }
            pix_gerbe[i].is_active = new_active;
        }
        i++;
    }
}