#include "obj/batteur_fou.h"

/* similar with OBJ_ACTIVE loop in DO_PI_EXPLOSION? */
/*INCLUDE_ASM("asm/nonmatchings/obj/batteur_fou", bat_init_scroll);*/

void bat_init_scroll(Obj *obj)
{
    s16 temp_s2;
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v1_1;
    s16 temp_v1_2;
    s16 var_s2;
    s16 var_v0_1;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;

    temp_v0_1 = obj->offset_bx + obj->x_pos;
    temp_v1_1 = obj->offset_by + obj->y_pos + 0x18;
    if (((u8) block_flags[PS1_BTYPAbsPos(temp_v0_1, temp_v1_1) & 0xFF] >> 1) & 1)
    {
        if (temp_v0_1 >= 0)
        {
            do
            {
                temp_v0_1 = temp_v0_1 - 0x10;
            } while (
                ((u8) block_flags[PS1_BTYPAbsPos(temp_v0_1, temp_v1_1) & 0xFF] >> 1) & 1 &&
                temp_v0_1 >= 0
            );
        }
    }
    bossScrollStartX = temp_v0_1 - 0x40;
    if (bossScrollStartX < 0)
    {
        bossScrollStartX = 0;
    }
    if (bossScrollStartX > xmapmax)
    {
        bossScrollStartX = xmapmax;
    }
    temp_v0_1 = obj->offset_bx + obj->x_pos;
    temp_v1_1 = obj->offset_by + obj->y_pos + 0x18;
    if (((u8) block_flags[PS1_BTYPAbsPos(temp_v0_1, temp_v1_1) & 0xFF] >> 1) & 1)
    {
        if (xmapmax >= temp_v0_1)
        {
            temp_v0_1 = temp_v0_1 + 0x10;
            while (
                ((u8) block_flags[PS1_BTYPAbsPos(temp_v0_1, temp_v1_1) & 0xFF] >> 1) & 1 &&
                temp_v0_1 <= xmapmax
            )
            {
                temp_v0_1 = temp_v0_1 + 0x10;
            }
            

        }
    }
    bossScrollEndX = temp_v0_1 + 0x20;
    if (bossScrollEndX < 0)
    {
        bossScrollEndX = 0;
    }
    if (bossScrollEndX > xmapmax)
    {
        bossScrollEndX = xmapmax;
    }
    special_ray_mov_win_x_left = 0x0040;
    special_ray_mov_win_x_right = -0x0060;
    scroll_start_x = bossScrollStartX;
    scroll_end_x = bossScrollEndX;
}