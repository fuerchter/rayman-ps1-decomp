#include "obj/maracas.h"

/* default settings permuter doesn't find anything */
/* 3AB5C 8015F35C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/maracas", MARACAS_GO);*/

void MARACAS_GO(Obj *obj)
{
  ObjFlags OVar1;
  s16 iVar2;
  Obj *basObj;

  u8 nb_obj;
  int new_var;
  u8 new_var2;
  
  iVar2 = 0;
  basObj = level.objects;
  nb_obj = level.nb_objects;
  if (nb_obj != 0) {
    new_var2 = nb_obj;
    do {

      if ((basObj->type == TYPE_MARACAS_BAS) &&
         ((basObj->flags & OBJ_ACTIVE) == OBJ_NONE)) {
        OVar1 = obj->flags;
        new_var = ~OBJ_FLIP_X;
        new_var = basObj->flags & new_var;
        basObj->speed_y = 0;
        basObj->speed_x = 0;
        basObj->flags = new_var;
        basObj->flags = basObj->flags | (OVar1 & OBJ_FLIP_X);
        basObj->x_pos = obj->x_pos;
        basObj->y_pos = obj->y_pos;
        calc_obj_pos(basObj);
        basObj->gravity_value_1 = 0;
        new_var = basObj->flags;
        new_var = new_var | (OBJ_ALIVE | OBJ_ACTIVE);
        basObj->flags = new_var;
        basObj->gravity_value_2 = 7;
        break;
      }
      basObj = basObj + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < new_var2);
  }
  skipToLabel(obj,99,TRUE);
  if (obj->cmd == GO_SPEED) {
    obj->speed_x = basObj->iframes_timer;
    obj->speed_y = basObj->field20_0x36;
  }
  set_main_and_sub_etat(obj,0,0xc);
}