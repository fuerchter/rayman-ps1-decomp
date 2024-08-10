#include "obj/cage.h"

/* 3CF08 80161708 -O2 -msoft-float */
void DO_CAGE2(Obj *obj)
{
    obj->speed_x = 0;
    obj->speed_y = -8;
}

/* 3CF18 80161718 -O2 */
void DO_CAGE(Obj *obj)
{
  if (
    obj->main_etat == 0 &&
    obj->sub_etat == 7 &&
    obj->anim_frame == 0 &&
    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0x0f] == 0
    ) {
    obj->display_prio = 5;
    allocateGrille(obj);
  }
}