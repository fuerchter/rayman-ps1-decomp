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
    s16 temp_a0;
    s16 temp_a1;
    s32 new_var2;
    short new_var;

    temp_a0 = obj->sub_etat;
    temp_a1 = obj->type;
    if (
      ((temp_a0 - 1) >= 2U) && (temp_a0 != 0x0B) && (temp_a0 != 0x16) &&
      (temp_a0 != 3) && (temp_a0 != 9) && ((temp_a0 - 4) >= 2U) &&
      (temp_a0 != 6) && ((temp_a0 - 0xF) >= 2U) && (temp_a0 != 0x11)
    )
    {
      if ((temp_a1 != 0x0C) && (temp_a1 != 0x0E))
      {
          set_main_and_sub_etat(obj, 1, 0);
      }
      SET_X_SPEED(obj);
      CALC_MOV_ON_BLOC(obj);
    }
    else if ((temp_a0 == 3) || (temp_a0 == 6))
    {
      new_var2 = 0xFFFF7FFF;
      obj->speed_y = -8;
      obj->flags &= new_var2;
    }
    else if ((temp_a0 == 0x0B) || (temp_a0 == 2) || (temp_a0 == 0x16))
    {
        switch (temp_a1)
        {
        case 0xE:
        case 0xC:
            DO_TIR(obj);
            break;
        case 0x3C:
            DO_BIG_CLOWN_ATTAK(obj);
            break;
        case 0x3D:
            DO_WAT_CLOWN_ATTAK(obj);
            break;
        }
    }
}