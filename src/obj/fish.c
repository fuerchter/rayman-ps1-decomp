#include "obj/fish.h"

/* 37A9C 8015C29C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/fish", allocate_splash);
#else
void allocate_splash(Obj *baseObj)
{
  short y;
  u8 uVar3;
  s16 i;
  Obj *obj;
  s16 offset_by;
  s32 height;

  i = 0;
  if (PS1_SplashAlwaysObjectsCount != 0)
  {
    do {
      obj = &level.objects[PS1_SplashAlwaysObjects[i]];
      if (!(obj->flags & FLG(OBJ_ACTIVE)))
      {
        obj->flags |= FLG(OBJ_ALIVE);
        make_active(obj, false);
        obj->x_pos = baseObj->offset_bx + baseObj->x_pos - obj->offset_bx;
        if (baseObj->btypes[0] == BTYP_WATER)
          y = baseObj->offset_by + baseObj->y_pos - obj->offset_by;
        else
        {
          if (!(block_flags[baseObj->btypes[0]] >> BLOCK_SOLID & 1))
          {
            offset_by = obj->offset_by;
            height = (*(u16*)&mp.height - 1) * 16;
          }
          else
          {
            height = (*(u16*)&mp.height - 1) * 16;
            offset_by = obj->offset_by - 10;
          }
          y = height - offset_by;
        }
        obj->y_pos = y;
        calc_obj_pos(obj);
        set_main_and_sub_etat(obj, 0, 0);
        obj->anim_frame = 0;
        baseObj->flags |= FLG(OBJ_FLAG_9); /* bad disassembly */
        break;
      }
      i++;
    } while (i < PS1_SplashAlwaysObjectsCount);
  }

  __asm__("nop\nnop");
}
#endif

/* 37C18 8015C418 -O2 */
u8 can_free_fish(Obj *fish)
{
  u8 res;
  u8 nb_objs;
  s16 i;
  Obj *obj;
  
  res = true;
  nb_objs = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_objs != 0) {
    do {
      if (
        obj->type == TYPE_FISH &&
        obj->init_x_pos == fish->init_x_pos &&
        (obj->flags & FLG(OBJ_ACTIVE)) &&
        obj->timer < 100
      )
      {
        res = false;
        break;
      }
      i++;
      obj++;
    } while (i < nb_objs);
  }
  return res;
}

/* 37CB8 8015C4B8 -O2 -msoft-float */
void DESACTIVE_FISH_COLLIS(Obj *fish)
{
  u8 index;
  Obj *obj;

  index = link_init[fish->id];
  obj = &level.objects[index];
  if (obj->y_pos == fish->y_pos)
  {
    obj->y_pos = ymap + 240;
    obj->flags &= ~FLG(OBJ_ALIVE);
    obj->flags &= ~FLG(OBJ_ACTIVE);
  }

  index = link_init[obj->id];
  obj = &level.objects[index];
  if (obj->y_pos == fish->y_pos)
  {
    obj->flags &= ~FLG(OBJ_ACTIVE);
    obj->y_pos = ymap + 240;
    obj->flags &= ~FLG(OBJ_ALIVE);
  }
}

INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);