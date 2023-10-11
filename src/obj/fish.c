#include "obj/fish.h"

/* 37A9C 8015C29C -O2 */
INCLUDE_ASM("asm/nonmatchings/obj/fish", allocate_splash);

/* 37C18 8015C418 -O2 */
u8 can_free_fish(Obj *fish)
{
  u8 res;
  u8 nb_obj;
  s16 i;
  Obj *obj;
  
  res = TRUE;
  nb_obj = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_obj != 0) {
    do {
      if (
        obj->type == TYPE_FISH &&
        obj->init_x_pos == fish->init_x_pos &&
        (obj->flags & OBJ_ACTIVE) &&
        obj->timer < 100
      )
      {
        res = FALSE;
        break;
      }
      i++;
      obj++;
    } while (i < nb_obj);
  }
  return res;
}

/* 37CB8 8015C4B8 -O2 */
INCLUDE_ASM("asm/nonmatchings/obj/fish", DESACTIVE_FISH_COLLIS);

/* next */
INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);
