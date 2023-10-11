#include "obj/fish.h"

/* 37A9C 8015C29C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/fish", allocate_splash);*/

/*extern ? D_20001;*/
extern u16 D_801F4432;
extern s16 PS1_SplashAlwaysObjects[12];
extern u8 PS1_SplashAlwaysObjectsCount;
/*extern s32 level;*/
extern MapData mp;

void allocate_splash(Obj *baseObj)
{
  short sVar1;
  u8 uVar3;
  s16 iVar4;
  Obj *obj;
  
  iVar4 = 0;
  if (PS1_SplashAlwaysObjectsCount != 0) {
    do {
      /*obj = level.objects + *(s16 *)((s32)PS1_SplashAlwaysObjects + (iVar4 >> 0xf));*/
      obj = &level.objects[PS1_SplashAlwaysObjects[iVar4]];
      /*obj = level.objects;
      obj = &obj[PS1_SplashAlwaysObjects[iVar4]];*/

      if (!(obj->flags & OBJ_ACTIVE)) {
        obj->flags = obj->flags | OBJ_ALIVE;
        make_active(obj, FALSE);
        obj->x_pos = (baseObj->offset_bx + baseObj->x_pos) - obj->offset_bx;
        if (baseObj->btypes[0] == 10) {
          sVar1 = (baseObj->offset_by + baseObj->y_pos) - obj->offset_by;
        }
        else {
          if ((block_flags[baseObj->btypes[0]] >> 1 & 1) == 0) {
            sVar1 = (*(u16*)&mp.height + -1) * 0x10 - obj->offset_by;
          }
          else {
            sVar1 = (*(u16*)&mp.height + -1) * 0x10 - obj->offset_by - 10;
          }
        }
        obj->y_pos = sVar1;
        calc_obj_pos(obj);
        set_main_and_sub_etat(obj, 0, 0);
        obj->anim_frame = 0;
        baseObj->flags = baseObj->flags | OBJ_FLAG_9; /* bad disassembly */
        break;
      }
        iVar4 = iVar4 + 1;
    } while (iVar4 < PS1_SplashAlwaysObjectsCount);
  }
}

/* 37CB8 8015C4B8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/fish", DESACTIVE_FISH_COLLIS);*/

extern u8 *link_init;

void DESACTIVE_FISH_COLLIS(Obj *fish)
{
  u8 obj_index;
  Obj *obj;

  obj_index = link_init[fish->id];
  obj = &level.objects[obj_index];
  if (obj->y_pos == fish->y_pos) {
    obj->y_pos = ymap + 240;
    /* already tried doing same as below, saving one of the flags to var, retyping */
    obj->flags &= ~(OBJ_ALIVE|OBJ_ACTIVE);
  }

  obj_index = link_init[obj->id];
  obj = &level.objects[obj_index];
  if (obj->y_pos == fish->y_pos) {
    obj->flags &= ~OBJ_ACTIVE;
    obj->y_pos = ymap + 240;
    obj->flags &= ~OBJ_ALIVE;
  }
}

/* 37DA4 8015C5A4 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/fish", DO_PYRANHA);*/

extern MapData mp;

void DO_PYRANHA(Obj *obj)
{
  u8 bVar1;
  char can_free;
  int iVar4;
  int iVar5;
  Obj *pOVar6;
  s16 test;
  u8 nb_obj;
  s16 new_var;
  s32 new_var2;
  
  DO_ONE_CMD(obj);
  can_free = FALSE;
  if (obj->main_etat == 0) {
    if ((obj->y_pos + obj->offset_by + 0x14) < ymap + 0xf0) {
      obj->timer = obj->timer + 1;
    }
    if (obj->sub_etat == 3) {
      obj->speed_y = 0;
    }
    else if (obj->sub_etat == 9) {
      iVar4 = obj->y_pos;
      new_var2 = (iVar4 + obj->offset_hy);
      iVar5 = ymap + 0xf0;
      obj->speed_y = 6;
      if (
        (iVar5 < new_var2) ||
        ((iVar4 + obj->offset_by + 0xe) > mp.height * 16)
      )
      {
        if ((iVar4 + obj->offset_by + 0xe) > mp.height * 16) {
          allocate_splash(obj);
        }
        obj->timer = 0;
        obj->flags = obj->flags & ~OBJ_ACTIVE;
        obj->y_pos = ymap + 0xf0;
        obj->flags = obj->flags & ~OBJ_ALIVE;
        can_free = can_free_fish(obj);
      }
    }
    else if ((obj->y_pos + obj->offset_by) < ymap) {
      obj->flags = obj->flags & ~OBJ_ACTIVE;
      obj->y_pos = ymap + 0xf0;
      obj->flags = obj->flags & ~OBJ_ALIVE;
      can_free = can_free_fish(obj);
    }
  }
  if (obj->timer == 100) {
    can_free = can_free_fish(obj);
  }
  if (can_free) {
    test = 0;
    nb_obj = level.nb_objects;
    pOVar6 = level.objects; /* 0x6c */
    if (nb_obj != 0) {
      do {
        if (
          pOVar6->type == TYPE_FISH &&
          pOVar6->init_x_pos == obj->init_x_pos &&
          !(pOVar6->flags & OBJ_ACTIVE)
        )
        {
          pOVar6->flags = pOVar6->flags | (OBJ_ALIVE|OBJ_ACTIVE);
          (pOVar6->y_pos) = ymap + 0xf0;
          (pOVar6->x_pos) = obj->init_x_pos;
          if (((mp.height & 0xFFFF) + -1) * 0x10 < pOVar6->y_pos + pOVar6->offset_by) {
            (pOVar6->y_pos) = (mp.height + -1) * 0x10 - pOVar6->offset_by;
            allocate_splash(pOVar6);
          }
          (pOVar6->main_etat) = obj->init_main_etat;
          (pOVar6->sub_etat) = obj->init_sub_etat;
          bVar1 = obj->init_hit_points;
          (pOVar6->timer) = 0;
          (pOVar6->hit_points) = bVar1;
          pOVar6->flags = pOVar6->flags | OBJ_READ_CMDS;
          calc_obj_pos(pOVar6);
          skipToLabel(pOVar6,1,TRUE);
          break;
        }
        pOVar6 = pOVar6 + 1;
        test = test + 1;
      } while (nb_obj > test);
    }
  }
}