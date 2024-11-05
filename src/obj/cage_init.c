#include "obj/cage_init.h"

/* 361A0 8015A9A0 -O2 */
void allocateGrille(Obj *obj)
{
    u8 nb_objs;
    s16 i;
    Obj *cur_obj;

    nb_objs = level.nb_objects;
    i = 0;
    cur_obj = level.objects;
    if (nb_objs != 0)
    {
        /* TODO: how to make this a matching for-loop? */
        do
        {
            if (cur_obj->type == TYPE_CAGE2 && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
            {
                cur_obj->flags = cur_obj->flags | (FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE));
                cur_obj->x_pos = obj->x_pos;
                cur_obj->y_pos = obj->y_pos;
                cur_obj->screen_x_pos = cur_obj->x_pos - xmap;
                cur_obj->screen_y_pos = cur_obj->y_pos - ymap;
                cur_obj->speed_y = -4;
                break;
            }
            i++;
            cur_obj++;
        } while (i < nb_objs);
    }
}