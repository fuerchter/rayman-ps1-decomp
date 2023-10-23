#include "obj/caisse_claire_command.h"

/* 4D6EC 80171EEC -O2 */
void DO_CCL_COMMAND(Obj *obj)
{
  u8 hp;

  switch(obj->cmd)
  {
    case GO_WAIT:
    case GO_NOP:
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        if (obj->main_etat == 0 && obj->sub_etat == 2)
        {
            hp = obj->hit_points;
            if (hp != (obj->flags >> 0xe & 1))
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | (hp & 1) << 0xe;
        }
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        break;
  }
}