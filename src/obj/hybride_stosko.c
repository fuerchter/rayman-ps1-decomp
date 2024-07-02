#include "obj/hybride_stosko.h"

/* 75600 80199E00 -O2 -msoft-float */
void allocateStoskoClaw(Obj *stosko_obj)
{
    Obj *cur_obj;
    s16 i;
    s16 nb_objs;

    stosko_obj->field24_0x3e = -1;
    cur_obj = level.objects;
    i = 0;
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_STOSKO_PINCE && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->x_pos = stosko_obj->x_pos;
            cur_obj->y_pos = stosko_obj->y_pos;
            cur_obj->speed_x = 0;
            calc_obj_pos(cur_obj);
            cur_obj->cmd_offset = -1;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            cur_obj->nb_cmd = 0;
            stosko_obj->field24_0x3e = i;
            break;
        }
        cur_obj++;
        i++;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/hybride_stosko", doSTOSKOcommand);
