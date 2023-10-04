#include "obj/cage.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/cage", DO_CAGE);*/

/* 3CF18 80161718 -O2 */
extern u8 horloge[28];

void DO_CAGE(Obj *obj)
{
  if (
    obj->main_etat == 0 &&
    obj->sub_etat == 7 &&
    obj->anim_frame == 0 &&
    horloge[(*obj->eta)[7].anim_speed & 0xf] == 0
    ) {
    obj->display_prio = 5;
    allocateGrille(obj);
  }
}