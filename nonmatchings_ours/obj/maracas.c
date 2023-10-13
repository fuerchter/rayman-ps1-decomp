#include "obj/maracas.h"

/* 3AB5C 8015F35C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/maracas", MARACAS_GO);*/

void MARACAS_GO(Obj *obj)
{
  ObjFlags OVar1;
  s16 iVar2;
  Obj *_basObj;
  Obj *basObj;
  u8 nb_obj;
  int new_var;
  
  iVar2 = 0;
  basObj = level.objects;
  nb_obj = level.nb_objects;
  if (nb_obj != 0) {
    _basObj = level.objects;
    do {
      new_var = TYPE_MARACAS_BAS;
      if ((_basObj->type == new_var) &&
         ((_basObj->flags & OBJ_ACTIVE) == OBJ_NONE)) {
        OVar1 = obj->flags;
        new_var = ~OBJ_FLIP_X;
        new_var = _basObj->flags & new_var;
        _basObj->speed_y = 0;
        _basObj->speed_x = 0;
        _basObj->flags = new_var;
        _basObj->flags = _basObj->flags | (OVar1 & OBJ_FLIP_X);
        _basObj->x_pos = obj->x_pos;
        _basObj->y_pos = obj->y_pos;
        calc_obj_pos(basObj);
        _basObj->gravity_value_1 = 0;
        OVar1 = 7;
        new_var = _basObj->flags;
        new_var = new_var | (OBJ_ALIVE | OBJ_ACTIVE);
        _basObj->flags = new_var;
        _basObj->gravity_value_2 = OVar1;
        break;
      }
      _basObj = _basObj + 1;
      iVar2 = iVar2 + 1;
      basObj = basObj + 1;
    } while (iVar2 < nb_obj);
  }
  skipToLabel(obj,99,TRUE);
  if (obj->cmd == GO_SPEED) {
    obj->speed_x = basObj->iframes_timer;
    obj->speed_y = basObj->field20_0x36;
  }
  set_main_and_sub_etat(obj,0,0xc);
}