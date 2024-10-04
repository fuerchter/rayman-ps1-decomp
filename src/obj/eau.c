#include "obj/eau.h"

/* 4D908 80172108 -O2 -msoft-float */
void ACTIVE_L_EAU(Obj *eau_obj)
{
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;

    eau_obj->field23_0x3c = 130;
    eau_obj->y_pos = ymapmax + 230;
    eau_obj->x_pos = xmap - eau_obj->offset_bx;
    i = 0;
    cur_obj = level.objects;
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_EAU && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
            cur_obj->speed_y = 0;
            cur_obj->speed_x = 0;
            cur_obj->x_pos = eau_obj->x_pos + 101 * 1;
            cur_obj->y_pos = eau_obj->y_pos;
            calc_obj_pos(cur_obj);
            cur_obj->field23_0x3c = 130;
            cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
            cur_obj->sub_etat = 1;
            break;
        }
        cur_obj++;
        i++;
    }
    cur_obj++;
    cur_obj->flags &= ~FLG(OBJ_FLIP_X);
    cur_obj->speed_y = 0;
    cur_obj->speed_x = 0;
    cur_obj->x_pos = eau_obj->x_pos + 101 * 2;
    cur_obj->y_pos = eau_obj->y_pos;
    calc_obj_pos(cur_obj);
    cur_obj->field23_0x3c = 130;
    cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    cur_obj->sub_etat = 2;

    cur_obj++;
    cur_obj->flags &= ~FLG(OBJ_FLIP_X);
    cur_obj->speed_y = 0;
    cur_obj->speed_x = 0;
    cur_obj->x_pos = eau_obj->x_pos + 101 * 3;
    cur_obj->y_pos = eau_obj->y_pos;
    calc_obj_pos(cur_obj);
    cur_obj->field23_0x3c = 130;
    cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    cur_obj->sub_etat = 3;
}

INCLUDE_ASM("asm/nonmatchings/obj/eau", DO_EAU_QUI_MONTE);
