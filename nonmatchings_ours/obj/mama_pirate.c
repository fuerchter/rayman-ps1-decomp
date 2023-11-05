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

/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_droit);*/

/* 270D8 8014B8D8 -O2 -msoft-float */
/*extern ? D_801F75D2;
extern ? D_801F75DF;*/

void lance_couteau_droit(Obj *param_1)
{
    s16 temp_v0_2;
    s16 temp_v1_2;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    s32 temp_lo;
    u8 temp_v0;

    temp_v0 = find_couteau(param_1);
    if (temp_v0 == 0xFF)
    {
        goto block_28;
    }
    temp_v0_2 = xmap; /* ? */
    temp_v0_2 = (xmap + CouteauxInfos[temp_v0].x_pos) - (param_1->offset_bx + param_1->x_pos);
    temp_v1_2 = (ymap + CouteauxInfos[temp_v0].y_pos) - (param_1->offset_by + param_1->y_pos);
    var_a0 = temp_v0_2;
    if (temp_v0_2 >= 0)
    {
        goto block_3;
    }
    var_a0 = -var_a0;
block_3:
    if (var_a0 >= 4)
    {
        goto block_7;
    }
    var_v0 = temp_v1_2;
    if (var_v0 >= 0)
    {
        goto block_6;
    }
    var_v0 = -var_v0;
block_6:
    if (var_v0 < 4)
    {
        goto block_21;
    }
block_7:
    CouteauxInfos[temp_v0].active = 0;
    var_v1 = temp_v1_2;
    if (temp_v1_2 >= 0)
    {
        goto block_9;
    }
    var_v1 = -var_v1;
block_9:
    if (var_a0 >= var_v1)
    {
        goto block_11;
    }
    var_a0 = var_v1;
block_11:
    temp_lo = 4;
    temp_lo = ashl16(var_a0, 4U) / temp_lo;
    param_1->speed_x = convertspeed(ashl16(temp_v0_2, 4U) / (s16) temp_lo);
    param_1->speed_y = convertspeed(ashl16(temp_v1_2, 4U) / (s16) temp_lo);
    update_couteau(param_1);
    param_1->display_prio = 3;
    return;
block_21:
    CouteauxInfos[temp_v0].active = 1;
    if ((u32) (pma_type_attaque - 1) < 2U)
    {
        goto block_25;
    }
    if (param_1->main_etat != 2)
    {
        goto block_24;
    }
    if (param_1->sub_etat == 0x0D)
    {
        goto block_26;
    }
block_24:
    param_1->main_etat = 2;
    param_1->sub_etat = 0x0D;
    goto block_26;
block_25:
    param_1->anim_frame = couteau_frame(0, 1);
block_26:
    param_1->speed_x = 0;
    param_1->speed_y = 0;
    param_1->x_pos = (xmap + CouteauxInfos[temp_v0].x_pos) - param_1->offset_bx;
    param_1->y_pos = (ymap + CouteauxInfos[temp_v0].y_pos) - param_1->offset_by;
    if (!(check_couteaux()))
    {
        goto block_28;
    }
    pma_phase = 3;
    reset_couteaux();
block_28:
    return;
}

/*INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", retour_couteau);*/

/* 273C4 8014BBC4 -O2 -msoft-float */
void retour_couteau(Obj *obj)
{
    s16 temp_v0;
    s32 var_a0;
    s16 var_a1;
    s32 var_v0;
    s16 var_v1;
    s32 var_v1_2;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;

    temp_a0 = find_couteau(obj) & 0xFF;
    if (temp_a0 == 0xFF)
    {
        goto block_31;
    }
    if (temp_a0 == 0)
    {
        goto block_3;
    }
    if (CouteauxInfos[temp_a0 - 1].field3_0x6 != 0)
    {
        goto block_31;
    }
block_3:
    temp_s0 = temp_a0;
    temp_v0 = CouteauxInfos[temp_s0].field3_0x6;
    if (temp_v0 != 0)
    {
        goto block_30;
    }
    var_a1 = 0;
    var_v1 = 0;
    temp_lo = 2;
    if (CouteauxInfos[temp_s0].field9_0x10 == (u8) 2)
    {
        goto block_6;
    }
    
    var_a1 = ((u16) xmap + (u16) CouteauxInfos[temp_a0].x_pos) - (obj->offset_bx + (u16) obj->x_pos);
    var_v1 = ((u16) ymap + CouteauxInfos[temp_s0].y_pos) - (obj->offset_by + (u16) obj->y_pos);
block_6:
    var_a0 = var_a1;
    if (var_a1 >= 0)
    {
        goto block_8;
    }
    var_a0 = -var_a0;
block_8:
    if (var_a0 >= 2)
    {
        goto block_12;
    }
    var_v0 = var_v1;
    if (var_v0 >= 0)
    {
        goto block_11;
    }
    var_v0 = -var_v0;
block_11:
    if (var_v0 < 2)
    {
        goto block_26;
    }
block_12:
    CouteauxInfos[temp_s0].active = 0;
    var_v1_2 = var_v1;
    if (var_v1 >= 0)
    {
        goto block_14;
    }
    var_v1_2 = -var_v1_2;
block_14:
    if (var_a0 >= var_v1_2)
    {
        goto block_16;
    }
    var_a0 = var_v1_2;
block_16:
    temp_v0_2 = ashl16(var_a0, 4U);
    
    temp_lo = temp_v0_2 / temp_lo;
block_19:
    temp_v0_3 = ashl16(var_a1, 4U);
    temp_lo_2 = temp_v0_3 / (s16) temp_lo;
block_22:
    obj->speed_x = convertspeed(temp_lo_2);
    temp_v0_4 = ashl16(var_v1, 4U);
    temp_lo_3 = temp_v0_4 / (s16) temp_lo;
block_25:
    obj->speed_y = convertspeed(temp_lo_3);
    return;
block_26:
    CouteauxInfos[temp_s0].active = 1;
    obj->speed_x = convertspeed(0);
    obj->speed_y = convertspeed(0);
    if (CouteauxInfos[temp_s0].field9_0x10 == (u8) 2)
    {
        goto block_28;
    }
    obj->x_pos = ((u16) xmap + (u16) CouteauxInfos[temp_a0].x_pos) - obj->offset_bx;
    obj->y_pos = ((u16) ymap + CouteauxInfos[temp_s0].y_pos) - obj->offset_by;
block_28:
    if (!(check_couteaux() & 0xFF))
    {
        goto block_31;
    }
    pma_phase = 3;
    reset_couteaux();
    return;
block_30:
    CouteauxInfos[temp_s0].field3_0x6 = temp_v0 - 1;
block_31:
    return;
}
