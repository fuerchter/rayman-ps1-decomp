#include "obj/corde.h"

#ifdef BSS_DEFS
s16 pierreAcorde_obj_id;
#endif

/* 3EB50 80163350 -O2 -msoft-float */
void DO_CORDE_CASSE(Obj *obj)
{
    s16 i;
    Obj *cur_obj;
    u8 nb_objs;

    set_sub_etat(obj, 21);
    if (level.objects[pierreAcorde_obj_id].hit_points == 10)
        level.objects[pierreAcorde_obj_id].hit_points = 5;
    else
    {
        level.objects[pierreAcorde_obj_id].hit_points = 1;
        set_main_and_sub_etat(level.objects + pierreAcorde_obj_id, 0, 23);
    }

    i = 0;
    cur_obj = &level.objects[i];
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_CORDEBAS && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->x_pos = obj->x_pos;
            cur_obj->y_pos = obj->y_pos;
            cur_obj->speed_y = 1;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
            cur_obj->gravity_value_2 = 4;
            break;
        }
        cur_obj++;
        i++;
    }
}

/* 3EC84 80163484 -O2 -msoft-float */
void DO_FUMEE_CORDE(s16 x, s16 y)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    u8 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_CFUMEE && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->x_pos = x - 142;
            cur_obj->y_pos = y - 128;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
            break;
        }
        cur_obj++;
        i++;
    }
}
