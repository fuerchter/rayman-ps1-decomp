#include "obj/saxo.h"

/* 51774 80175F74 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_NOTE_REBOND);*/

/*? calc_obj_pos();*/

void DO_NOTE_REBOND(Obj *arg0)
{
  s32 var_v0;
  
  switch (arg0->type)
  {
    case TYPE_NOTE2:
        DO_EXPLOSE_NOTE2(arg0);
        break;
    case TYPE_NOTE0:
    case TYPE_NOTE3:
    case TYPE_BONNE_NOTE:
        var_v0 = arg0->speed_y;
        if (var_v0 < 0)
            var_v0 = -var_v0;
        arg0->speed_y = -var_v0;
        if (-2 <= arg0->speed_y)
            arg0->speed_y = (-var_v0) - 1;

        arg0->gravity_value_1 = 0xA - arg0->gravity_value_1;
        calc_obj_pos();
        break;
  }

}