#include "obj_update.h"

/* matches, but case 3 and 4??? */
/*INCLUDE_ASM("asm/nonmatchings/obj_update", DO_PESANTEUR);*/

s32 DO_PESANTEUR(Obj *obj)
{
    s16 temp_v0;
    s16 y_accel;
    s32 res;
    u8 temp_v1_1;

    res = 0;
    y_accel = 0;
    temp_v1_1 = obj->eta[obj->main_etat][obj->sub_etat].anim_speed >> 4;
    if (temp_v1_1 != 0)
    {
        if (obj->type == TYPE_TAMBOUR1 || obj->type == TYPE_TAMBOUR2)
        {
            if (obj->field56_0x69 != 0)
                obj->field56_0x69--;
            else if (obj->gravity_value_1 == 0)
            {
                obj->speed_y++;
                res = 1;
            }
        }
        else
        {
            switch (temp_v1_1)
            {
            case 6:
                if (horloge[2] == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 1:
                if (obj->gravity_value_1 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 2:
                if (obj->gravity_value_2 == 0)
                {
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 3:
                temp_v0 = obj->speed_y;
                if (temp_v0 > 0)
                {
                    if (temp_v0 > 1)
                    {
                        y_accel = -1;
                    }
                }
                else
                {
                    y_accel = 1;
                }
                break;
            case 4:
                temp_v0 = obj->speed_y;
                if (temp_v0 < -1)
                {
                    if (temp_v0 < -2)
                    {
                        y_accel = 1;
                    }
                }
                else
                {
                    y_accel = -1;
                }
                break;
            case 5:
                if (obj->gravity_value_1 == 0)
                    y_accel = -1;
                break;
            case 10:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = 1;
                    res = 1;
                }
                break;
            case 11:
                obj->gravity_value_1++;
                if (obj->gravity_value_1 >= obj->gravity_value_2)
                {
                    obj->gravity_value_1 = 0;
                    y_accel = -1;
                    res = 1;
                }
                break;
            }
        }
        if (flags[obj->type].flags1 >> OBJ1_USE_INSTANT_SPEED_Y & 1)
            y_accel = ashl16(y_accel, 4);
        obj->speed_y += y_accel;
    }
    return res;
}