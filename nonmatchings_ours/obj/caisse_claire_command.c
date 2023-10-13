#include "obj/caisse_claire_command.h"

/* two versions */
/* 4D6EC 80171EEC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/caisse_claire_command", DO_CCL_COMMAND);*/

/*? CALC_MOV_ON_BLOC(Obj *);
? SET_X_SPEED(Obj *);*/

void DO_CCL_COMMAND(Obj *obj)
{
    u32 var_v0;
    u8 temp_a0;
    s16 temp_v1;
    u32 temp_a1;

    temp_v1 = obj->cmd;
    if (temp_v1 == 2)
    {
        goto block_5;
    }
    else if (temp_v1 >= 3)
    {
        if (temp_v1 != 0x1E)
        {
            return;
        }
        goto block_5;
    }
    else if (temp_v1 < 0)
    {
        return;
    }
    else
    {
        goto block_9;
    }
block_5:
    SET_X_SPEED(obj);
    CALC_MOV_ON_BLOC(obj);
    if (obj->main_etat != 0 || obj->sub_etat != 2)
    {
        return;
    }
    temp_a1 = obj->flags;
    temp_a0 = obj->hit_points;
    if (temp_a0 == ((temp_a1 >> 0xE) & 1))
    {
        return;
    }
    obj->flags = (temp_a1 & ~0x4000) | ((temp_a0 & 1) << 0xE);
    return;
block_9:
    if (obj->cmd != 0)
    {
        goto block_11;
    }
    else
    {
        var_v0 = ~0x4000;
        var_v0 = obj->flags & var_v0;
        goto block_12;
    }
block_11:
    var_v0 = obj->flags | 0x4000;
block_12:
    obj->flags = var_v0;
    SET_X_SPEED(obj);
    CALC_MOV_ON_BLOC(obj);
block_13:
    return;
}

void DO_CCL_COMMAND(Obj *obj)
{
  s16 OVar1;
  ObjFlags OVar2;
  s32 new_var;
  u8 hp;

  OVar1 = obj->cmd;
  if(OVar1 == 2 || OVar1 >= 3 || OVar1 == 30)
  {
    SET_X_SPEED(obj);
    CALC_MOV_ON_BLOC(obj);
    if ((obj->main_etat == 0) && (obj->sub_etat == 2)) {
        hp = obj->hit_points;
        if ((u32)hp != (obj->flags >> 0xe & 1)) {
            obj->flags = obj->flags & ~OBJ_FLIP_X | (hp & 1) << 0xe;
        }
    }
    return;
  }
  else {
      new_var = ~OBJ_FLIP_X;
      if (obj->cmd == 0) {
        OVar2 = obj->flags & new_var;
      }
      else {
        OVar2 = obj->flags | OBJ_FLIP_X;
      }
      obj->flags = OVar2;
      SET_X_SPEED(obj);
      CALC_MOV_ON_BLOC(obj);
      return;
  }
}