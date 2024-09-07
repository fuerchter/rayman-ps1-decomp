#include "collision/block_22C84.h"

/*
matches, but remove x_2???
attempts: 2?
not sure there is a good solution
*/
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);*/

void calc_btyp_square(Obj *obj)
{
  u8 x_offs;
  s16 x_1;
  int y_1;
  short x_3;
  short y_2;
  short x_4;
  short x_5;
  int x_2;
  
  if (obj->type == TYPE_RAYMAN)
  {
    if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
      x_offs = 4;
    else
      x_offs = 8;
  }
  else
    x_offs = 16;

  x_1 = (s16) (obj->x_pos + obj->offset_bx);
  y_1 = (s16) ((obj->y_pos + obj->offset_by));
  y_2 = ashr16(y_1,4);
  x_2 = x_1;
  x_3 = ashr16(x_2,4);
  x_4 = ashr16(x_2 - x_offs,4);
  x_5 = ashr16(x_2 + x_offs,4);
  obj->btypes[3] = BTYP(x_3,y_2 + -1);
  obj->btypes[1] = BTYP(x_4,y_2);
  if (obj->main_etat == 2) {
    obj->btypes[0] = bloc_floor((u8) BTYP(x_3,y_2),(s16)(x_2 + (x_2 / 16) * -0x10),
                       (s16)(y_1 + (y_1 / 16) * -0x10));
  }
  else {
    obj->btypes[0] = BTYP(x_3,y_2);
  }
  obj->btypes[2] = BTYP(x_5,y_2);
  obj->btypes[4] = BTYP(x_3,y_2 + 1);
}