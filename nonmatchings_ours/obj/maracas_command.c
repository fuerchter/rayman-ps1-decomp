#include "obj/maracas_command.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/maracas_command", MarCoince);*/

/* 4CB88 80171388 -O2 */
s16 MarCoince(Obj *arg0, s16 arg1)
{
    s16 temp_a2;
    s16 temp_a3;
    s16 var_t0;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_v0_2;
    s32 var_v1;
    s16 new_var;

    var_t0 = 0;
    temp_a3 = (arg0->offset_bx + arg0->x_pos) - 0x19;
    temp_a2 = arg0->offset_hy + arg0->y_pos;
    switch (arg1)
    {
    case 2:
        var_v0 = temp_a2;
        if (temp_a2 < 0)
        {
            var_v0 = temp_a2 + 0xF;
        }
        if ((s16) (temp_a2 - ((var_v0 >> 4) * 0x10)) < 3)
        {
            temp_v1 = ((temp_a3 >> 4)) + (mp.width * ((temp_a2 << 0x10) >> 0x14));
            temp_v1_2 = temp_v1 + 1;
            if ((block_flags[(u16) mp.map[temp_v1] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            if ((block_flags[(u16) mp.map[temp_v1_2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            var_v0_2 = (temp_v1_2 + 1) * 2;
            if ((block_flags[(u16) mp.map[var_v0_2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
        }
        break;
    case 3:
        var_v0 = temp_a2;
        if (temp_a2 < 0)
        {
            var_v0 = temp_a2 + 0xF;
        }
        if ((s16) (temp_a2 - ((var_v0 >> 4) * 0x10)) >= 0xD)
        {
            temp_v1 = ((temp_a3 >> 4)) + (mp.width * ((temp_a2 + 0x30) >> 4));
            temp_v1_2 = temp_v1 + 1;
            if ((block_flags[(u16) mp.map[temp_v1] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            if ((block_flags[(u16) mp.map[temp_v1_2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            var_v0_2 = (temp_v1_2 + 1) * 2;
            if ((block_flags[(u16) *(var_v0_2 + mp.map) >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
        }
        break;
    case 0:
        var_v0 = temp_a3;
        if (temp_a3 < 0)
        {
            var_v0 = temp_a3 + 0xF;
        }
        if ((s16) (temp_a3 - ((var_v0 >> 4) * 0x10)) < 3)
        {
            temp_v1 = (((temp_a3 >> 4)) + (mp.width * ((temp_a2 + 0x10) >> 4))) - 1;
            temp_v1_2 = temp_v1 + mp.width;
            if ((block_flags[(u16) mp.map[temp_v1 * 2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            if ((block_flags[(u16) mp.map[temp_v1_2 * 2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            var_v0_2 = (temp_v1_2 + mp.width) * 2;
            if ((block_flags[(u16) mp.map[var_v0_2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
        }
        break;
    case 1:
        var_v0 = temp_a3;
        if (temp_a3 < 0)
        {
            var_v0 = temp_a3 + 0xF;
        }
        if ((s16) (temp_a3 - ((var_v0 >> 4) * 0x10)) >= 0xD)
        {
            temp_v1 = ((temp_a3 << 0x10) >> 0x14) + (mp.width * ((temp_a2 + 0x10) >> 4)) + 3;
            temp_v1_2 = temp_v1 + mp.width;
            if ((block_flags[(u16) mp.map[temp_v1 * 2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            if ((block_flags[(u16) mp.map[temp_v1_2 * 2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
            var_v0_2 = (temp_v1_2 + mp.width) * 2;
            if ((block_flags[(u16) mp.map[var_v0_2] >> 0xA] >> 1) & 1)
            {
                var_t0 = 1;
            }
        }
        break;
    }
    return var_t0;
}