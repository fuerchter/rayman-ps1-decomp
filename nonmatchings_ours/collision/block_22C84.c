#include "collision/block_22C84.h"

/* num_world loads that don't do anything? */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_x);*/

s16 get_center_x(Obj *obj)
{
  switch(obj->type)
  {
  case 0x2d:
    return 0x12;
  case 0x6a:
    return 0x46;
  case 0x16:
    /* switch instead? */
    if (num_world != 1) {
      if (num_world == 2) {
        return 0x40;
      }
      return 0x28;
    }
    return 0x28; 
  case 0xbd:
    return 0x12;
  case 0x31:
    return 0x80;
  case 0x7b:
    switch(obj->follow_sprite)
    {
    case 5:
    case 6:
    case 7:
        return 0x50;
    default:
        return 0x28;
    }
  case 0xe1:
  case 0xe2:
  case 0xb8:
  case 0xae:
    return 0x50;
  case 0x9a:
  case 0x9b:
  case 0x8a:
    return 0x68;
  case 0x8c:
    return 0x24;
  default:
    return 0x28;
  }
}

/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", get_center_y);*/

s16 get_center_y(Obj *obj)
{
    u8 bVar1;
    s16 in_a1;

    switch(obj->type)
    {
    case 0x2d:
        return 0x12;
    case 0x6a:
        return 0x28;
    case 0xbd:
        return 0x12;
    case 0x31:
        return 0x40;
    case 0xc3:
        return 0x5a;
    case 0xe1:
    case 0xe2:
    case 0xb8:
    case 0xae:
        return 0x60;
    case 0x8c:
        return 0x20;
    case 0x7b:
        switch(obj->follow_sprite)
        {
        case 5:
            return 0x48;
        case 6:
        case 7:
            if (obj->speed_y >= 1) {
                return 0x40;
            }
            else
                return 0x4e;
        default:
            return in_a1;
        }
    case 0x9a:
    case 0x9b:
    case 0x8a:
        return 0x68;
    default:
        return 0x28;
    }
}