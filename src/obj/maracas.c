#include "obj/maracas.h"

/* 3AB5C 8015F35C -O2 */
void MARACAS_GO(Obj *obj)
{
  Obj *basObj;
  s16 i;
  u8 nb_obj_1;
  u8 nb_obj_2;
  ObjFlags basObj_not_flip;
  ObjFlags obj_get_flip;

  i = 0;
  basObj = level.objects;
  nb_obj_1 = level.nb_objects;
  if (nb_obj_1 != 0) {
    nb_obj_2 = nb_obj_1;
    do {

      if ((basObj->type == TYPE_MARACAS_BAS) && !(basObj->flags & FLG(OBJ_ACTIVE))) {
        basObj_not_flip = ~FLG(OBJ_FLIP_X);
        basObj_not_flip &= basObj->flags;
        obj_get_flip = obj->flags & FLG(OBJ_FLIP_X);
        basObj->flags = basObj_not_flip | obj_get_flip;
        
        basObj->speed_y = 0;
        basObj->speed_x = 0;
        basObj->x_pos = obj->x_pos;
        basObj->y_pos = obj->y_pos;
        calc_obj_pos(basObj);
        basObj->flags = basObj->flags | (FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE));
        basObj->gravity_value_1 = 0;
        basObj->gravity_value_2 = 7;
        break;
      }
      basObj++;
      i++;
    } while (i < nb_obj_2);
  }
  skipToLabel(obj, 99, true);
  if (obj->cmd == GO_SPEED) {
    obj->speed_x = basObj->iframes_timer;
    obj->speed_y = basObj->field20_0x36;
  }
  set_main_and_sub_etat(obj, 0, 12);
}