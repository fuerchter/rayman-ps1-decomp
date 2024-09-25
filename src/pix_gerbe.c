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
void start_pix_gerbe(s32 x_pos, s32 y_pos) /* struct access??? */
{
    s16 *cur_data;
    s16 i;
    s16 spd_x; s16 spd_y;
    s16 grb = allocate_gerbe();
    
    if (grb != -1)
    {
        cur_data = &pix_gerbe[grb];
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

INCLUDE_ASM("asm/nonmatchings/pix_gerbe", do_pix_gerbes);
