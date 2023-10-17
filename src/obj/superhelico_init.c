#include "obj/superhelico_init.h"

/* 3EECC 801636CC -O2 */
void allocateSupHelico(Obj *mus_obj)
{
  Obj *cur_obj;
  s16 i;
  u8 nb_objects;
  s32 type;
  s8 speed;
  
  cur_obj = level.objects;
  i = 0;
  nb_objects = level.nb_objects;
  if (nb_objects != 0)
  {
    do
    {
      type = TYPE_SUPERHELICO;
      if (cur_obj->type == type && !(cur_obj->flags & OBJ_ACTIVE))
      {
        cur_obj->flags |= (OBJ_ALIVE | OBJ_ACTIVE);
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
      type = TYPE_SUPERHELICO;
    }
    while (nb_objects > i);
  }
}