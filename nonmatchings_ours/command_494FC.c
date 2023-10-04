#include "command_494FC.h"

/*INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD_LR_ATTENTE);*/

/* 4956C 8016DD6C -O2 */
/*? CALC_MOV_ON_BLOC(void *);
? DO_BIG_CLOWN_ATTAK(void *, u8);
? DO_TIR(void *, u8);
? DO_WAT_CLOWN_ATTAK(void *, u8);
? SET_X_SPEED(void *);
? set_main_and_sub_etat(void *, ?, ?);*/

void DO_ONE_CMD_LR_ATTENTE(Obj *obj)
{
    s32 new_var2;
    s32 new_var3;
  s16 temp_a0;
  u8 new_var;
  s32 temp_a1;
  s16 test;

  temp_a0 = obj->sub_etat;
  new_var3 = temp_a0 - 1;
  
  temp_a1 = obj->type;
  new_var = temp_a1;
  if (
    temp_a0 - 1 >= 2U &&
    temp_a0 != 0xB &&
    temp_a0 != 0x16 &&
    temp_a0 != 3 &&
    temp_a0 != 9 &&
    temp_a0 - 4 >= 2U &&
    temp_a0 != 6 &&
    temp_a0 - 0xF >= 2U &&
    temp_a0 != 0x11
    )
  {
    /* here's the bad guy, officer! */
    if (temp_a1 != TYPE_CHASSEUR1 && temp_a1 != TYPE_CHASSEUR2)
      set_main_and_sub_etat(obj, 1, 0);
    SET_X_SPEED(obj);
    CALC_MOV_ON_BLOC(obj);
  }
  else if (temp_a0 == 3 || temp_a0 == 6)
  {
    new_var2 = 0xFFFF7FFF;
    obj->speed_y = -8;
    obj->flags &= new_var2;
  }
  else if (temp_a0 == 0xB || temp_a0 == 2 || temp_a0 == 0x16)
  {
    switch ((s16)new_var)
    {
      case TYPE_CHASSEUR1:
      case TYPE_CHASSEUR2:
        DO_TIR(obj, temp_a1);
        break;

      case TYPE_BIG_CLOWN:
        DO_BIG_CLOWN_ATTAK(obj, temp_a1);
        break;

      case TYPE_WAT_CLOWN:
        DO_WAT_CLOWN_ATTAK(obj, temp_a1);
        break;
    }
  }
}

/*INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD_UPDOWN);*/

/* might not be using switch */
/* 496EC 8016DEEC -O2 */
void DO_ONE_CMD_UPDOWN(Obj *obj)
{
    u16 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;

    temp_v1 = obj->type;
    switch (temp_v1)
    {
    case 10:
        if ((obj->main_etat == 0) && (obj->sub_etat == 0))
        {
            if (obj->cmd != 3)
            {
                obj->speed_y = 2;
                return;
            }
        }
        return;
    case 1:
        temp_v1_2 = obj->cmd;
        switch (temp_v1_2)
        {
        case 3:
            obj->speed_y = -2;
            return;
        }
        break;
    case 24:
        temp_v0 = obj->nb_cmd - 1;
        obj->nb_cmd = temp_v0;
        if ((temp_v0 << 0x10) > 0)
        {
            temp_v1_3 = obj->cmd;
            switch (temp_v1_3)
            {
            case 3:
                obj->speed_y = -1;
                return;
            case 4:
                return;
            }
            obj->speed_y = 1;
        }
        else
        {
            obj->speed_y = 0;
            obj->type = 1U;
            obj->nb_cmd = 0U;
            obj->cmd = 2U;
            obj->init_y_pos = (u16) obj->y_pos;
        }
        break;
    }
}

/*INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD);*/

/* 49844 8016E044 -O2 */
/*? CALC_MOV_ON_BLOC(Obj *);
? DO_ONE_CMD_LR_ATTENTE(Obj *);
? DO_ONE_CMD_UPDOWN(Obj *);
? SET_X_SPEED(Obj *);
? special_pour_liv();*/

void DO_ONE_CMD(Obj *obj)
{
  ObjFlags flags;
  s16 etat;
  s32 new_var;

  etat = obj->main_etat;
  special_pour_liv(obj);
  switch (obj->cmd)
  {
    case GO_WAIT:
      DO_ONE_CMD_WAIT(obj);
      break;
    case GO_LEFT:
    case GO_RIGHT:
      new_var = ~OBJ_FLIP_X;
      if (obj->cmd == GO_LEFT)
      {
        flags = obj->flags & new_var;
      }
      else
      {
        flags = obj->flags | OBJ_FLIP_X;
      }
      obj->flags = flags;
      if (etat == 1)
      {
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
      }
    else
      if (etat == 2)
      {
        SET_X_SPEED(obj);
      }
    else
      if (etat == 0)
      {
        DO_ONE_CMD_LR_ATTENTE(obj);
      }
      break;
    case GO_UP:
    case GO_DOWN:
      DO_ONE_CMD_UPDOWN(obj);
      break;
    case GO_SPEED:
      obj->speed_x = obj->iframes_timer;
      obj->speed_y = obj->field20_0x36;
    case GO_NOP:
      break;
  }
}