#include "obj/pi_boum.h"

/* 3A27C 8015EA7C -O2 -msoft-float */
void allocateEclatPS(Obj *in_obj, s16 param_2)
{
    s16 spd_x;
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;

    switch (param_2)
    {
    case 7:
        spd_x = -3;
        break;
    case 8:
        spd_x = 2;
        break;
    case 9:
        spd_x = -1;
        break;
    }
    i = 0;
    cur_obj = &level.objects[i];
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_PI_BOUM && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            set_main_and_sub_etat(cur_obj, 2, param_2);
            cur_obj->speed_x = spd_x;
            cur_obj->speed_y = -6;
            cur_obj->x_pos = in_obj->x_pos;
            cur_obj->y_pos = in_obj->y_pos;
            skipToLabel(cur_obj, 1, true);
            calc_obj_pos(cur_obj);
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            cur_obj->flags &= ~FLG(OBJ_FLAG_9);
            cur_obj->gravity_value_1 = 0;
            cur_obj->gravity_value_2 = 5;
            break;
        }
        cur_obj++;
        i++;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/pi_boum", DO_PI_EXPLOSION);
