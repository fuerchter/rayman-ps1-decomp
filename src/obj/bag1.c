#include "obj/bag1.h"

/* 4C2C8 80170AC8 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/bag1", DO_BAG1_COMMAND);
#else
/*? DO_ONE_CMD();
? allocateLandingSmoke(Obj *);*/

void DO_BAG1_COMMAND(Obj *obj)
{
  DO_ONE_CMD(obj);
  if (
    obj->sub_etat == 4 &&
    obj->anim_frame == 14 &&
    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
    (u16)(obj->screen_x_pos + 0x9f) < 409 &&
    obj->screen_y_pos < 140
  )
  {
    obj->y_pos += 86;
    allocateLandingSmoke(obj);
    obj->y_pos -= 86;
  }

  __asm__("nop");
}
#endif