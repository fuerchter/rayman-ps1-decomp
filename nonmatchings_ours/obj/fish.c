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