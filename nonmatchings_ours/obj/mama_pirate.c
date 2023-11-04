#include "obj/mama_pirate.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_lance_couteau);*/

/* matches, but clean up to do. cou_tempo changed u16 -> s16 in the meantime */
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

/* matches, but how to remove/clean up locals? */
/* 26F08 8014B708 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_parabolique);*/

void lance_couteau_parabolique(Obj *obj)
{
    u8 cout_ind;
    s16 diff_x;
    s16 diff_y;
    s16 speed_x;
    s16 speed_y;
    s32 dividend;
    s32 divisor;

    s16 test_1;
    int new_var3;

    cout_ind = find_couteau(obj);
    if (cout_ind != 0xFF)
    {
        diff_x = (xmap + CouteauxInfos[cout_ind].x_pos) - (obj->offset_bx + obj->x_pos);
        diff_y = (ymap + CouteauxInfos[cout_ind].y_pos) - (obj->offset_by + obj->y_pos);
        if (CouteauxInfos[cout_ind].field2_0x4 != 0)
        {
            CouteauxInfos[cout_ind].field2_0x4 = 0;
            if (diff_x == 0)
            {
                obj->speed_x = convertspeed(0);
                obj->speed_y = convertspeed(-1);
            }
            else
            {
                if (diff_x >= 0)
                    speed_x = 2;
                else
                    speed_x = -2;
                test_1 = 0x10;
                new_var3 = diff_x * 8;
                dividend = -(diff_y * (speed_x * test_1) * 8 + diff_x * new_var3);
                divisor = diff_x * speed_x * 8;
                speed_y = dividend / divisor;
                obj->speed_x = convertspeed(speed_x) - 10;
                obj->speed_y = speed_y;
            }
            update_couteau(obj);
            obj->display_prio = 3;
            return;
        }
        obj->speed_y += 4;
        if (obj->speed_x * diff_x < 0)
            obj->speed_x = 0;
        update_couteau(obj);
    }
    __asm__("nop\nnop\nnop\nnop\nnop");
}