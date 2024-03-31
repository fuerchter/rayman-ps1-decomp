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

/* matches, but var_a2, the whole if/else suck */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", CALC_FOLLOW_SPRITE_SPEED);*/

void CALC_FOLLOW_SPRITE_SPEED(Obj *obj, Animation *anim1, Animation *anim2, s16 param_4)
{
  AnimationLayer *layer2;
  AnimationLayer *layer1;
  s32 temp_v1;
  s32 var_a2;
  s32 var_a3;
  u16 temp_a0;
  u8 foll_spr;
  u8 new_var;

  foll_spr = obj->follow_sprite;
  layer1 = &anim1->layers[(anim1->layers_count & 0x3FFF) * obj->anim_frame];
  layer2 = &anim2->layers[(anim2->layers_count & 0x3FFF) * param_4];
  
  new_var = obj->sprites[layer1[foll_spr].sprite].width;
  if (obj->flags & FLG(OBJ_FLIP_X))
  {
    temp_v1 = (u16) obj->x_pos + (obj->offset_bx * 2) - new_var;
    var_a2 = temp_v1 - layer1[foll_spr].x_pos;
    var_a3 = temp_v1 - layer2[foll_spr].x_pos;
  }
  else
  {
    temp_a0 = obj->x_pos;
    var_a2 = temp_a0;
    var_a2 = var_a2 + layer1[foll_spr].x_pos;
    var_a3 = temp_a0 + layer2[foll_spr].x_pos;
  }
  obj->follow_y = (layer1[foll_spr].y_pos + obj->y_pos) - (layer2[foll_spr].y_pos + obj->y_pos);
  obj->follow_x = var_a2 - var_a3;
}

/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", GET_SPRITE_POS);*/

s16 GET_SPRITE_POS(Obj *obj, s16 index, s16 *x, s16 *y, u16 *w, u16 *h)
{
    Animation *temp_v0;
    Sprite *temp_t0;
    s16 var_a1;
    s32 var_v0;
    u8 var_v1;
    u8 temp_v1;
    AnimationLayer *temp_t2;
    s16 new_var;
    s32 new_var2;

    temp_v0 = &obj->animations[obj->anim_index];
    temp_t2 = &(&temp_v0->layers[(temp_v0->layers_count & 0x3FFF) * obj->anim_frame])[index];
    temp_v1 = temp_t2->sprite;
    temp_t0 = &obj->sprites[temp_v1];
    if ((temp_v1 != 0) && (temp_t0->id != 0))
    {
        *w = temp_t0->sprite_width;
        *h = temp_t0->sprite_height;
        if (obj->flags & 0x4000)
        {
            new_var2 = temp_t0->sprite_pos & 0xF;
            var_v1 = obj->x_pos;
            var_v0 = ((obj->offset_bx * 2) - (new_var2 + temp_t2->x_pos)) - temp_t0->width;
        }
        else
        {
            var_v1 = temp_t0->sprite_pos & 0xF;
            var_v0 = temp_t2->x_pos + (u16) obj->x_pos;
        }
        *x = var_v1 + var_v0;
        var_a1 = 1;
        new_var = obj->y_pos;
        *y = temp_t2->y_pos + (temp_t0->sprite_pos >> 4) + new_var;
    }
    else
    {
        var_a1 = 0;
    }
    return var_a1;
}

/* matches, but... */
/*INCLUDE_ASM("asm/nonmatchings/collision/block_22C84", calc_btyp_square);*/

void calc_btyp_square(Obj *obj)
{
  u8 bVar1;
  ushort uVar2;
  BlockType BVar3;
  u8 uVar4;
  short y_2;
  short x_3;
  short x_4;
  short x_5;
  u8 x_offs;
  int x_2;
  int y_offs;
  int y_1;
  s16 x_1;
  s16 x_test;
  
  x_3 = obj->type;
  if (x_3 == TYPE_RAYMAN)
  {
    if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
      x_offs = 4;
    else
      x_offs = 8;
  }
  else
    x_offs = 16;

  y_1 = (s16) ((obj->offset_by + (ushort)obj->y_pos));
  x_1 = (s16) (obj->offset_bx + obj->x_pos);
  y_2 = ashr16(y_1,4);
  x_2 = x_1;
  x_3 = ashr16(x_2,4);
  x_4 = ashr16(x_2 - x_offs,4);
  x_5 = ashr16(x_2 + x_offs,4);
  obj->btypes[3] = BTYP(x_3,y_2 + -1);
  obj->btypes[1] = BTYP(x_4,y_2);
  if (obj->main_etat == 2) {
    uVar4 = BTYP(x_3,y_2);
    obj->btypes[0] = bloc_floor(uVar4,(s16)(x_2 + (x_2 / 16) * -0x10),
                       (s16)(y_1 + (y_1 / 16) * -0x10));
  }
  else {
    obj->btypes[0] = BTYP(x_3,y_2);
  }
  obj->btypes[2] = BTYP(x_5,y_2);
  obj->btypes[4] = BTYP(x_3,y_2 + 1);
}