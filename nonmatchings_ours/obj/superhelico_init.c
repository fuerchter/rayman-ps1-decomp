#include "obj/superhelico_init.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/obj/superhelico_init", allocateSupHelico);*/

/* 3EECC 801636CC -O2 */
void allocateSupHelico(Obj *mus_obj)
{
  u8 nb_objects;
  s16 i;
  Obj *cur_obj;
  s8 speed;
  
  nb_objects = level.nb_objects;
  i = 0;
  cur_obj = &level.objects[i];
  if (nb_objects != 0)
  {
    do
    {
      if (cur_obj->type == TYPE_SUPERHELICO && !(cur_obj->flags & OBJ_ACTIVE))
      {
        cur_obj->flags = cur_obj->flags | (OBJ_ALIVE | OBJ_ACTIVE);
        cur_obj->x_pos = mus_obj->x_pos;
        cur_obj->y_pos = mus_obj->y_pos;
        set_main_and_sub_etat(cur_obj, 2, 0x12);
        cur_obj->screen_x_pos = cur_obj->x_pos - xmap;
        cur_obj->screen_y_pos = cur_obj->y_pos - ymap;
        speed = -2;
        cur_obj->speed_y = speed;
        speed = 1;
        cur_obj->speed_x = speed;
        calc_obj_pos(cur_obj);
        break;
      }
      cur_obj++;
      i++;
    }
    while (i < nb_objects);
  }
}