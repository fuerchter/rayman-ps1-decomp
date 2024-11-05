#include "obj/balle.h"

/* 380A0 8015C8A0 -O2 -msoft-float */
void DO_BALLE(Obj *obj)
{
    ObjState *obj_eta = &obj->eta[obj->main_etat][obj->sub_etat];

    if (obj->type == TYPE_BALLE2)
    {
        obj_eta->speed_x_left = -1;
        obj_eta->speed_x_right = 1;
        obj_eta->anim_speed = obj_eta->anim_speed & 0xF | 0xA0;
    }
    else if (obj->type == TYPE_BALLE1)
    {
        obj_eta->speed_x_left = -2;
        obj_eta->speed_x_right = 2;
        obj_eta->anim_speed = obj_eta->anim_speed & 0xF;
    }
}
