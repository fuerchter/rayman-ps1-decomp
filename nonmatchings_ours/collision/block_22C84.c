#include "collision/block_22C84.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_x);*/

s16 get_center_x(Obj *obj)
{
    s16 res;

    switch(obj->type)
    {

    case 0x6a:
        res = 0x46;
        break;
    case 0x16:
        switch (num_world)
        {
        case 1:
            res = 0x28;
            break;
        case 2:
            res = 0x40;
            break;
        default:
            res = 0x28;
            break;
        }
        break;
    case 0x2d:
        /* i'm so confused..., why does this work? */
        switch (num_world)
        {
        case 1:
            res = 0x28;
            break;
        case 2:
            res = 0x40;
            break;
        default:
            res = 0x28;
            break;
        }
        res = 0x12;
        break;
    case 0xbd:
        res = 0x12;
        break;
    case 0x31:
        res = 0x80;
        break;
    case 0x7b:
        switch(obj->follow_sprite)
        {
        case 5:
        case 6:
        case 7:
            res = 0x50;
            break;
        default:
            res = 0x28;
            break;
        }
        break;
    case 0xe1:
    case 0xe2:
    case 0xb8:
    case 0xae:
        res = 0x50;
        break;
    case 0x9a:
    case 0x9b:
    case 0x8a:
        res = 0x68;
        break;
    case 0x8c:
        res = 0x24;
        break;
    default:
        res = 0x28;
        break;
    }

    return res;
}

/* num attempts: 2 */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_y);*/

s16 get_center_y(Obj *obj)
{
    u8 bVar1;
    s16 in_a1;
    s16 res;

    switch(obj->type)
    {
    case 0xc3:
        res = 0x5a;
        break;
    case 0x6a:
        res = 0x28;
        break;
    case 0x16:
        break;
    case 0x2d:
        switch (num_world) /* tiny improvement */
        {
        case 1:
            res = 0x28;
            break;
        case 2:
            res = 0x40;
            break;
        default:
            res = 0x28;
            break;
        }
        res = 0x12;
        break;
    case 0xbd:
        res = 0x12;
        break;
    case 0x31:
        res = 0x40;
        break;
    case 0x7b:
        /* moving 0x48 to default case instead gets us to ~925 */
        switch(obj->follow_sprite)
        {
        case 5:
            res = 0x48;
            break;
        case 6:
        case 7:
            if (obj->speed_y >= 1) {
                res = 0x40;
            }
            else
                res = 0x4e;
            break;
        default:
            res = in_a1;
            break;
        }
        break;
    case 0xe1:
    case 0xe2:
    case 0xb8:
    case 0xae:
        res = 0x60;
        break;
    case 0x9a:
    case 0x9b:
    case 0x8a:
        res = 0x68;
        break;
    case 0x8c:
        res = 0x20;
        break;
    default:
        res = 0x28;
        break;
    }
    return res;
}

/*
matches, but remove x_2???
num attempts: 2?
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