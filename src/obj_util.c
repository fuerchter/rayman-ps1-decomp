#include "obj_util.h"

/* 243B8 80148BB8 -O2 -msoft-float */
void init_obj_in_the_air(Obj *obj)
{
  obj->gravity_value_1 = 0;
  obj->gravity_value_2 = 0;
}

/* 243C4 80148BC4 -O2 -msoft-float */
void make_my_fruit_go_down(Obj *obj, s16 x_accel)
{
  if (obj->main_etat == 2 && __builtin_abs(obj->speed_x) < 32)
    obj->speed_x += x_accel;
  if (obj->type == TYPE_FALLING_YING_OUYE)
  {
    if (obj->main_etat != 2 || obj->sub_etat != 0)
    {
        set_main_and_sub_etat(obj, 2, 0);
        init_obj_in_the_air(obj);
    }
  }
  else
  {
    if (obj->main_etat != 2 || obj->sub_etat != 2)
    {
        set_main_and_sub_etat(obj, 2, 2);
        init_obj_in_the_air(obj);
    }
  }
}

/* 24494 80148C94 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/obj_util", allocate_toons);
#else
void allocate_toons(Obj *src_obj, u8 count)
{
  Obj *obj;
  s16 i;
  Obj *max_obj;
  u8 layers;
  s16 spr_x;
  s16 spr_y;
  s16 spr_w;
  s16 spr_h;

  obj = findfirstObject(TYPE_LIDOLPINK);
  i = 0;
  max_obj = &obj[14];
  if (src_obj->type == TYPE_RAYMAN)
    layers = ray.animations[ray.anim_index].layers_count; /* u16 loaded into u8? */
  else
    layers = 1;
  
  while(obj < max_obj)
  {
    if (!(obj->flags & FLG(OBJ_ACTIVE)) && obj->type == TYPE_LIDOLPINK)
    {
      set_main_and_sub_etat(obj, 2, 0);
      obj->iframes_timer = 20;
      obj->gravity_value_1 = 0;
      obj->gravity_value_2 = 5;
      obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
      obj->speed_y = PS1_Toon_Speeds_y[i];
      obj->speed_x = PS1_Toon_Speeds_x[i];
      if (obj->speed_x >= 1)
      {
        obj->eta[2][0].speed_x_right = obj->speed_x;
        obj->eta[2][0].speed_x_left = -obj->speed_x;
        obj->flags |= FLG(OBJ_FLIP_X);
        skipToLabel(obj, 2, true);
      }
      else
      {
        obj->eta[2][0].speed_x_right = -obj->speed_x;
        obj->eta[2][0].speed_x_left = obj->speed_x;
        obj->flags &= ~FLG(OBJ_FLIP_X);
        skipToLabel(obj, 2, true);
      }
      obj->eta[2][1].speed_x_right = obj->eta[2][0].speed_x_right;
      obj->eta[2][1].speed_x_left = obj->eta[2][0].speed_x_left;
      GET_SPRITE_POS(src_obj, i % layers, &spr_x, &spr_y, &spr_w, &spr_h);
      obj->x_pos = spr_x + (spr_w >> 1) - obj->offset_bx;
      obj->y_pos = spr_y + (spr_h >> 1) - obj->offset_by;
      calc_obj_pos(obj);
      obj->anim_frame = 0;
      obj->anim_index = obj->eta[obj->main_etat][obj->sub_etat].anim_index;
      obj->flags &= ~FLG(OBJ_FLAG_9);
      i++;
      if (i == count)
        break;
    }
    obj++;
  }

  __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj_util", special_flags_init);

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_util", switchOff);
#else
void switchOff(Obj *obj)
{
  u8 flag_set;

  flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
  if (
    (flag_set && obj->anim_frame == 0 ||
    !flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1) &&
    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
  )
  {
    obj->flags &= ~FLG(OBJ_ACTIVE);
    obj->flags &= ~FLG(OBJ_ALIVE);
    if(obj->type == TYPE_RAYON) 
    {
      obj->x_pos = -32000;
      obj->y_pos = -32000;
    }
  }

  __asm__("nop");
}
#endif

/* 2498C 8014918C -O2 -msoft-float */
void obj_hurt(Obj *obj)
{
  if (obj->hit_points < poing.damage)
    obj->hit_points = 0;
  else
    obj->hit_points -= poing.damage;
}

INCLUDE_ASM("asm/nonmatchings/obj_util", Projectil_to_RM);

INCLUDE_ASM("asm/nonmatchings/obj_util", del_actobj); /* ??? */