#include "obj/drop_command.h"

/* 506E8 80174EE8 -O2 -msoft-float */
void DO_DROP_COMMAND(Obj *obj)
{
    if (obj->speed_y > 2)
        set_main_and_sub_etat(obj, 2, 2);
    else if (obj->speed_y > 1)
        set_main_and_sub_etat(obj, 2, 1);

    if (
        __builtin_abs(obj->speed_x) > 1 &&
        !(obj->main_etat == 2 && obj->sub_etat == 0)
    )
    {
        if (!(obj->flags & FLG(OBJ_FLIP_X)))
            obj->speed_x++;
        else
            obj->speed_x--;
    }

    if (obj->main_etat == 2 && obj->sub_etat == 3)
    {
        if (EOA(obj))
        {
            obj->flags &= ~FLG(OBJ_ACTIVE);
            obj->flags &= ~FLG(OBJ_ALIVE);
        }
    }
}
