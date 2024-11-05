#include "obj/fire.h"

#ifdef BSS_DEFS
s16 flamme_droite_id;
s16 flamme_gauche_id;
u8 flammes_actives;
#endif

/* 77E14 8019C614 -O2 -msoft-float */
void DoFlammeCommand(Obj *obj)
{
    if (obj->main_etat == 0 && obj->sub_etat == 5)
    {
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
    }
    else
        DO_ONE_CMD(obj);
}

/* 77E70 8019C670 -O2 -msoft-float */
void AllocateFlammes(s16 param_1)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (
            param_1 == 0 &&
            cur_obj->type == TYPE_FIRE_LEFT && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_y_pos =
            cur_obj->y_pos = 100;
            cur_obj->init_x_pos =
            cur_obj->x_pos = 5 - cur_obj->offset_bx;
            cur_obj->init_y_pos =
            cur_obj->y_pos = firstFloorBelow(cur_obj) - cur_obj->offset_by;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
            flammes_actives = 2;
            flamme_gauche_id = cur_obj->id;
            break;
        }
        if (
            param_1 == 1 &&
            cur_obj->type == TYPE_FIRE_RIGHT && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_y_pos =
            cur_obj->y_pos = 100;
            cur_obj->init_x_pos =
            cur_obj->x_pos = 240 - cur_obj->offset_bx;
            cur_obj->init_y_pos =
            cur_obj->y_pos = firstFloorBelow(cur_obj) - cur_obj->offset_by;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
            flammes_actives = 2;
            flamme_droite_id = cur_obj->id;
            break;
        }
        cur_obj++;
        i++;
    }
}
