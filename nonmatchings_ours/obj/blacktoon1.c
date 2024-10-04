#include "obj/blacktoon1.h"

/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj/blacktoon1", DO_BLK_NOP_COMMAND);*/

void DO_BLK_NOP_COMMAND(Obj *obj)
{
    s16 temp_a0_2;
    s16 temp_a0_4;
    s16 temp_a1;
    s16 temp_v1_2;
    s16 temp_v1_3;
    u8 temp_a0;
    u8 temp_a0_3;
    u8 temp_v1_1;
    u8 var_a1;
    u8 var_a1_2;
    u8 var_v0;

    if (
        (obj->field56_0x69 & 0x10) &&
        (
            ((temp_a0 = obj->main_etat, (temp_a0 == 0)) && (obj->sub_etat == 2)) ||
            ((temp_a0 == 2) && (obj->sub_etat == 3))
        )
    )
    {
        temp_v1_1 = obj->timer;
        if (temp_v1_1 == 0xFF)
        {
            temp_a0_2 = obj->y_pos;
            temp_a1 = obj->speed_y;
            temp_v1_2 = obj->field23_0x3c;
            if ((temp_v1_2 < (temp_a0_2 + temp_a1)) || (((temp_a0_2 < temp_v1_2) != 0)))
            {
                if (temp_a1 == 0)
                {
                    obj->timer = 0x3C;
                }
            }
            else
            {
                obj->timer = 0x3C;
            }
        }
        else if (temp_v1_1 == 0)
        {
            set_main_and_sub_etat(obj, 2U, 0U);
            if (obj->flags & 0x4000)
            {
                skipToLabel(obj, 3, 1U);
            }
            else
            {
                skipToLabel(obj, 2, 1U);
            }
            
            obj->speed_y = 0;
        }
        else
        {
            obj->speed_y = 0;
            var_v0 = obj->timer - 1;
            obj->timer = var_v0;
        }
    }
    if ((obj->follow_sprite == 4) && (((temp_a0_3 = obj->main_etat, (temp_a0_3 == 0)) && (obj->sub_etat == 2)) || ((temp_a0_3 == 2) && (obj->sub_etat == 3))))
    {
        if (obj->detect_zone_flag != 0)
        {
            temp_a0_4 = obj->y_pos;
            temp_v1_3 = obj->field23_0x3c;
            if ((temp_v1_3 >= (temp_a0_4 + obj->speed_y)) && (temp_a0_4 >= temp_v1_3))
            {
                set_main_and_sub_etat(obj, 0U, 3U);
                obj->speed_y = 0;
            }
        }
        else
        {
            set_main_and_sub_etat(obj, 2U, 1U);
        }
    }
    if ((obj->field56_0x69 & 2) && (obj->speed_x != 0) && (block_flags[calc_typ_travd(obj, 0U) & 0xFF] & 1))
    {
        if (obj->cmd == 0)
        {
            skipToLabel(obj, 3, 1U);
        }
        else
        {
            skipToLabel(obj, 2, 1U);
        }
    }
}