#include "obj/platform.h"

/* 3979C 8015DF9C -O2 -msoft-float */
void DO_INTERACT_PLAT(Obj *unk_obj)
{
    ObjType obj_type;
    s16 diff_x;
    Obj *found_obj;
    s16 diff_y;
    s16 unk_x = xmapmax;
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;
    
    while (i < nb_objs)
    {
        obj_type = cur_obj->type;
        if (
            obj_type == TYPE_LIFTPLAT || obj_type == TYPE_PLATFORM ||
            obj_type == TYPE_FALLPLAT || obj_type == TYPE_INTERACTPLT
        )
        {
            diff_x = (cur_obj->x_pos + cur_obj->offset_bx) - unk_obj->x_pos - unk_obj->offset_bx;
            if (diff_x > 0 && diff_x < unk_x)
            {
                found_obj = cur_obj;
                unk_x = diff_x;
            }
        }
        i++;
        cur_obj++;
    }

    if (unk_x != xmapmax)
    {
        found_obj->type = TYPE_INTERACTPLT;
        found_obj->flags &= ~FLG(OBJ_READ_CMDS);

        diff_y = (found_obj->y_pos + found_obj->offset_by) - unk_obj->y_pos - unk_obj->offset_by;
        if (diff_y < 1)
            found_obj->cmd = GO_DOWN;
        else
            found_obj->cmd = GO_UP;
        found_obj->nb_cmd = __builtin_abs(diff_y);
    }
}
