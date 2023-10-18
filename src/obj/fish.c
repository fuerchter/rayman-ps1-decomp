#include "obj/fish.h"

/* 37A9C 8015C29C -O2 */
INCLUDE_ASM("asm/nonmatchings/obj/fish", allocate_splash);

/* 37C18 8015C418 -O2 */
u8 can_free_fish(Obj *fish)
{
  u8 res;
  u8 nb_objs;
  s16 i;
  Obj *obj;
  
  res = TRUE;
  nb_objs = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_objs != 0) {
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
    } while (i < nb_objs);
  }
  return res;
}

/* 37CB8 8015C4B8 -O2 */
INCLUDE_ASM("asm/nonmatchings/obj/fish", DESACTIVE_FISH_COLLIS);

/* 37DA4 8015C5A4 -O2 */
INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);