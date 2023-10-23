#include "command_494FC.h"

/* 494FC 8016DCFC -O2 */
void DO_ONE_CMD_WAIT(Obj *obj)
{
    if (obj->main_etat == 1)
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
        set_main_and_sub_etat(obj, 0, 0);
    }
    else if (obj->type == TYPE_FISH && obj->main_etat == 0 && obj->sub_etat == 0)
        obj->speed_y = 0;
}

INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD_LR_ATTENTE);

/* 496EC 8016DEEC -O2 -msoft-float */
void DO_ONE_CMD_UPDOWN(Obj *obj)
{
  switch(obj->type)
  {
    case TYPE_FISH:
      if (obj->main_etat == 0 && obj->sub_etat == 0)
      {
        if (obj->cmd == GO_UP)
          obj->speed_y = -2;
        else
          obj->speed_y = 2;
      }
      break;

    case TYPE_PLATFORM:
      if(obj->cmd == GO_UP)
        obj->speed_y = -2;
      else if(obj->cmd == GO_DOWN)
        obj->speed_y = 2;
      break;
      
    case TYPE_INTERACTPLT:
      obj->nb_cmd--;
      if (obj->nb_cmd > 0)
      {
        if(obj->cmd == GO_UP)
          obj->speed_y = -1;
        else if(obj->cmd == GO_DOWN)
          obj->speed_y = 1;
      }
      else
      {
        obj->speed_y = 0;
        obj->type = TYPE_PLATFORM;
        obj->nb_cmd = 0;
        obj->cmd = GO_WAIT;
        obj->init_y_pos = obj->y_pos;
      }
      break;
  }
}

/* 497FC 8016DFFC -O2 */
void special_pour_liv(Obj *obj)
{
    if (obj->type == TYPE_BADGUY1 && obj->main_etat == 1 && obj->sub_etat == 0xb)
        obj->flags &= ~OBJ_READ_CMDS;
}

/* 49844 8016E044 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD);
#else
/*? CALC_MOV_ON_BLOC(Obj *);
? DO_ONE_CMD_LR_ATTENTE(Obj *);
? DO_ONE_CMD_UPDOWN(Obj *);
? SET_X_SPEED(Obj *);
? special_pour_liv();*/

void DO_ONE_CMD(Obj *obj)
{
  s16 etat;

  __asm__("nop");
  
  etat = obj->main_etat;
  special_pour_liv(obj);
  switch (obj->cmd)
  {
    case GO_WAIT:
      DO_ONE_CMD_WAIT(obj);
      break;
    case GO_LEFT:
    case GO_RIGHT:
      if (obj->cmd == GO_LEFT)
        obj->flags &= ~OBJ_FLIP_X;
      else
        obj->flags |= OBJ_FLIP_X;
      
      if (etat == 1)
      {
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
      }
      else if (etat == 2)
        SET_X_SPEED(obj);
      else if (etat == 0)
        DO_ONE_CMD_LR_ATTENTE(obj);
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
const u8 rodata_command_494FC[4] = {};
#endif