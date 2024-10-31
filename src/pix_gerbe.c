#include "pix_gerbe.h"

/* 3CB5C 8016135C -O2 -msoft-float */
s32 allocate_gerbe(void)
{
    s16 i;
    s16 res = -1;
    
    for (i = 0; i < (s16) LEN(pix_gerbe); i++)
    {
        if (!pix_gerbe[i].is_active)
        {
            pix_gerbe[i].is_active = true;
            res = i;
            break;
        }
    }

    return res;
}

/* 3CBE0 801613E0 -O2 -msoft-float */
void start_pix_gerbe(s32 x_pos, s32 y_pos)
{
    s16 *cur_data;
    s16 i;
    s16 spd_x; s16 spd_y;
    s16 grb = allocate_gerbe();
    
    if (grb != -1)
    {
        cur_data = (s16 *)&pix_gerbe[grb]; /* struct access instead??? */
        for (
            i = 0;
            i < (s16) LEN(pix_gerbe[grb].items) - grb * (s16) LEN(pix_gerbe);
            i++
        )
        {
            *cur_data++ = x_pos << 6;
            *cur_data++ = y_pos << 6;
            spd_y = myRand((i << 2) + 128) - 256;
            spd_y -= i << 1;
            spd_x = myRand((i << 2) + 64) - 32;
            spd_x -= i << 1;
            *cur_data++ = spd_x;
            *cur_data++ = spd_y;
            ((u8 *)cur_data)[0] = myRand(8) + 8; /* y_accel */
            ((u8 *)cur_data)[1] = 128; /* unk_1 */
            cur_data++;
        }
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/pix_gerbe", do_pix_gerbes);
#else
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
#endif
