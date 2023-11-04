#include "obj/mama_pirate.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_lance_couteau);*/

/* matches, but clean up to do */
/* 263E8 8014ABE8 -O2 -msoft-float */

void init_lance_couteau(u8 index)
{
  u8 bVar1;
  u8 bVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  Obj *obj;
  short x;
  short y;
  short w;
  short h;
  u8 test_1;
  
  uVar3 = index;
  if ((uVar3 < pma_nb_couteau) && (uVar3 < 5)) {
    obj = level.objects + (u8)CouteauxInfos[uVar3].id;
    if ((obj->flags & FLG(OBJ_ACTIVE)) == FLG_OBJ_NONE) {
      obj->display_prio = 0;
      obj->flags = obj->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
      CouteauxInfos[uVar3].active = 0;
      if ((pma_type_attaque == 0) || ((s16)pma_type_attaque - 3 < 2U)) {
        set_main_and_sub_etat(obj,2,10);
        obj->anim_index = obj->eta[2][10].anim_index;
        CouteauxInfos[uVar3].field9_0x10 = 4;
        CouteauxInfos[uVar3].x_pos = x_pos(uVar3,pma_nb_couteau);
        bVar1 = level.objects[mama_pirate_obj_id].offset_by;
        bVar2 = obj->offset_by;
        CouteauxInfos[uVar3].y_pos = ((ushort)bVar1 + level.objects[mama_pirate_obj_id].screen_y_pos) - (ushort)bVar2;
        CouteauxInfos[uVar3].field2_0x4 = 1;
        obj->anim_frame = 0;
      }
      else {
        set_main_and_sub_etat(obj,2,0xb);
        obj->anim_index = obj->eta[2][0xb].anim_index;
        if (pma_type_attaque == 5) {
          CouteauxInfos[uVar3].x_pos = x_pos(uVar3,pma_nb_couteau);
          CouteauxInfos[uVar3].y_pos = y_pos(0,0);
          CouteauxInfos[uVar3].field9_0x10 = 1;
          CouteauxInfos[uVar3].field2_0x4 = cou_tempo;
          obj->anim_frame = 0;
        }
        else {

          if (place_sequence[cou_place] <= uVar3) {
            CouteauxInfos[uVar3].x_pos = x_pos(uVar3 + 1,pma_nb_couteau + 1);
          }
          else
          {
            CouteauxInfos[uVar3].x_pos = x_pos(uVar3,pma_nb_couteau + 1);
          }
          
          CouteauxInfos[index].x_pos = CouteauxInfos[index].x_pos + index * -4;
          CouteauxInfos[index].y_pos = y_pos(0,0);
          CouteauxInfos[index].field9_0x10 = 3;
          if (index == 0) {
            CouteauxInfos[0].field2_0x4 = cou_tempo;
            obj->anim_frame = 0;
          }
          else {
            CouteauxInfos[index].field2_0x4 = 1;
            obj->anim_frame = 0;
          }
        }
      }
      GET_SPRITE_POS(level.objects + mama_pirate_obj_id,6,&x,&y,&w,&h);
      if ((level.objects[mama_pirate_obj_id].flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE) {
        x = x + w;
      }
      obj->x_pos = x - (ushort)obj->offset_bx;
      obj->y_pos = y - (ushort)obj->offset_by;
      obj->init_x_pos = obj->x_pos;
      obj->init_y_pos = obj->y_pos;
    }
  }
  return;
}