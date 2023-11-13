#include "obj/fish.h"

/* 37DA4 8015C5A4 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);*/

void DO_PYRANHA(Obj *obj)
{
  u8 can_free;
  int iVar4;
  Obj *pOVar6;
  s16 test;
  u8 nb_obj;
  s32 new_var2;
  
  DO_ONE_CMD(obj);
  can_free = false;
  if (obj->main_etat == 0)
  {
    if ((obj->y_pos + obj->offset_by + 20) < ymap + 240)
      obj->timer++;
    if (obj->sub_etat == 3)
      obj->speed_y = 0;
    else if (obj->sub_etat == 9)
    {
      iVar4 = obj->y_pos;
      new_var2 = iVar4 + obj->offset_hy;
      obj->speed_y = 6;
      if (
        ymap + 240 < new_var2 ||
        (iVar4 + obj->offset_by + 14) > mp.height * 16
      )
      {
        if ((iVar4 + obj->offset_by + 14) > mp.height * 16)
          allocate_splash(obj);
        obj->timer = 0;
        obj->flags = obj->flags & ~FLG(OBJ_ACTIVE);
        obj->y_pos = ymap + 240;
        obj->flags = obj->flags & ~FLG(OBJ_ALIVE);
        can_free = can_free_fish(obj);
      }
    }
    else if (obj->y_pos + obj->offset_by < ymap)
    {
      obj->flags = obj->flags & ~FLG(OBJ_ACTIVE);
      obj->y_pos = ymap + 240;
      obj->flags = obj->flags & ~FLG(OBJ_ALIVE);
      can_free = can_free_fish(obj);
    }
  }
  if (obj->timer == 100)
    can_free = can_free_fish(obj);
  if (can_free)
  {
    test = 0;
    nb_obj = level.nb_objects;
    pOVar6 = level.objects; /* 0x6c */
    if (nb_obj != 0)
    {
      do {
        if (
          pOVar6->type == TYPE_FISH &&
          pOVar6->init_x_pos == obj->init_x_pos &&
          !(pOVar6->flags & FLG(OBJ_ACTIVE))
        )
        {
          pOVar6->flags = pOVar6->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
          pOVar6->y_pos = ymap + 240;
          pOVar6->x_pos = obj->init_x_pos;
          if ((mp.height + -1) * 0x10 < pOVar6->y_pos + pOVar6->offset_by) {
            pOVar6->y_pos = (mp.height + -1) * 0x10 - pOVar6->offset_by;
            allocate_splash(pOVar6);
          }
          pOVar6->main_etat = obj->init_main_etat;
          pOVar6->sub_etat = obj->init_sub_etat;
          pOVar6->hit_points = obj->init_hit_points;
          pOVar6->timer = 0;
          pOVar6->flags = pOVar6->flags | FLG(OBJ_READ_CMDS);
          calc_obj_pos(pOVar6);
          skipToLabel(pOVar6,1,true);
          break;
        }
        pOVar6++;
        test++;
      } while (nb_obj > test);
    }
  }
}