#include "obj/fish.h"

INCLUDE_ASM("asm/nonmatchings/obj/fish", allocate_splash);

/* 37C18 8015C418 -O2 */
u8 can_free_fish(Obj *fish)
{
  u8 res;
  u8 nb_objs;
  s16 i;
  Obj *obj;
  
  res = true;
  nb_objs = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_objs != 0) {
    do {
      if (
        obj->type == TYPE_FISH &&
        obj->init_x_pos == fish->init_x_pos &&
        (obj->flags & FLG(OBJ_ACTIVE)) &&
        obj->timer < 100
      )
      {
        res = false;
        break;
      }
      i++;
      obj++;
    } while (i < nb_objs);
  }
  return res;
}

INCLUDE_ASM("asm/nonmatchings/obj/fish", DESACTIVE_FISH_COLLIS);

INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);