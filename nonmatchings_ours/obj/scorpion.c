#include "obj/scorpion.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", set_rubis_list);*/

void set_rubis_list(void)
{
  ObjType type;
  s16 rand_res;
  s32 obj_ind;
  Obj *cur_obj;
  s32 rubis_ind;
  u8 *pbVar6;
  s32 swapped;
  s32 nb_objs;
  s16 *new_var;
  
  cur_obj = &level.objects[0];
  nb_objs = level.nb_objects;
  rubis_list_calculated = true;
  rubis_ind = 0;
  sko_nb_lave = 0;
  obj_ind = 0;
  if (nb_objs > 0) {
    do {
      type = cur_obj->type;
      if (type == TYPE_RUBIS) {
        ecroule_rubis_list[rubis_ind] = cur_obj->id;
        rubis_ind = rubis_ind + 1;
      }
      else if (type == TYPE_SKO_PINCE) {
        sko_pince_obj_id = (s16)obj_ind;
      }
      else if (type == TYPE_LAVE) {
        sko_lave_obj[sko_nb_lave] = (u8)obj_ind;
        sko_nb_lave = sko_nb_lave + 1;
      }
      obj_ind = obj_ind + 1;
      cur_obj = cur_obj + 1;
    } while (obj_ind < nb_objs);
  }
  do {
    swapped = false;
    obj_ind = 0;
    rubis_ind = 1;
    do {
      if (
        level.objects[ecroule_rubis_list[obj_ind]].x_pos >
        level.objects[ecroule_rubis_list[rubis_ind]].x_pos
      )
      {
        swap(obj_ind,rubis_ind);
        swapped = true;
      }
      obj_ind = obj_ind + 1;
      rubis_ind = rubis_ind + 1;
    } while (obj_ind < 7);
  } while (swapped);
  if (ModeDemo != 0)
    ecroule_plat_index = 8;
  else {
    rand_res = myRand(0xb1);
    ecroule_plat_index = (u8)(rand_res % 3 << 3);
  }
  
  sko_ecroule_plat = ecroule_rubis_list[ecroule_rubis_order[ecroule_plat_index]];
  sko_enfonce_enable = 0;
  mp.height = 0x20;
  scroll_end_y = 0x110;
  ymapmax = 0x110;
  sko_ecran_tremble = 0;
  if (sko_nb_lave != 0) {
    new_var = &mp.height;
    pbVar6 = &sko_lave_obj[0];
    do {
      level.objects[*pbVar6].init_y_pos = (u16) (*new_var) * 0x10 + -0x3c;
      level.objects[*pbVar6].y_pos = level.objects[*pbVar6].init_y_pos;
      pbVar6 = pbVar6 + 1;
    } while ((int)pbVar6 < (int)&sko_lave_obj[sko_nb_lave]);
  }
}

/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", allocate_rayon);*/

void allocate_rayon(s16 x, s16 y)
{
  s16 found;
  u8 nb_objs;
  s16 i;
  Obj *cur_obj;
  s32 new_var;

  found = false;
  nb_objs = level.nb_objects;
  i = 0;
  cur_obj = &level.objects[0];
  do {
    if (cur_obj->type == TYPE_RAYON && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
      found = true;
    cur_obj++;
    i++;
  } while (!found && i < nb_objs);
  nb_objs = 1; /* ??? */
  if (found)
  {
    cur_obj--;
    new_var = cur_obj->flags & ~(FLG(OBJ_FLAG_9));
    cur_obj->flags = new_var | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    cur_obj->x_pos = x;
    cur_obj->y_pos = y;
    cur_obj->speed_x = 0;
    cur_obj->speed_y = 0;
    set_main_etat(cur_obj, 3);
    set_sub_etat(cur_obj, 0);
  }
}

/* matches, but too many unknowns, "test" var */
/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", do_sko_rayon);*/

void do_sko_rayon(void)
{
    Obj *ecroule_obj;
    s16 diff_y_1;
    s16 diff_x_1;
    s16 dist;
    s16 diff_x_2;
    s16 diff_y_2;
    s16 diff_x_abs;
    s16 diff_y_abs;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s16 var_v1_2;
    s16 test;

    if (sko_rayon_on != 0)
    {
        D_801E4E10 = 3;
        sko_rayon_on--;
        ecroule_obj = &level.objects[sko_ecroule_plat];
        diff_x_1 = sko_final_x - sko_rayon_x;
        diff_x_abs = __builtin_abs(diff_x_1);
        diff_y_1 = sko_final_y - sko_rayon_y;
        diff_y_abs = __builtin_abs(diff_y_1);
        diff_y_2 = diff_y_1;
        diff_x_2 = diff_x_1;
        dist = diff_x_abs + diff_y_abs;
        if (dist < 8)
        {
            set_main_etat(ecroule_obj, 2);
            set_sub_etat(ecroule_obj, 2);
        }
        if (dist > 0)
        {
            temp_v0_3 = ashl16(diff_x_1, D_801E4E10);
            temp_lo = temp_v0_3 / dist;
            diff_x_2 = temp_lo;
            temp_v0_4 = ashl16(diff_y_1, D_801E4E10);
            temp_lo_2 = temp_v0_4 / dist;
            diff_y_2 = temp_lo_2;
        }
        var_v1_2 = horloge[4] == 0 && sko_rayon_on < 50;
        if (var_v1_2 != 0)
        {
            temp_v0_5 = diff_x_2 - sko_rayon_dx;
            if (temp_v0_5 >= 0)
                sko_rayon_dx += (temp_v0_5 > 0);
            else
                sko_rayon_dx -= (test = 1);
            temp_v0_6 = diff_y_2 - sko_rayon_dy;
            if (temp_v0_6 >= 0)
                sko_rayon_dy += (temp_v0_6 > 0);
            else
                sko_rayon_dy -= (test = 1);
        }
        sko_rayon_x += sko_rayon_dx;
        sko_rayon_y += sko_rayon_dy;
        if (horloge[3] == 0 && dist != 0)
            allocate_rayon(sko_rayon_x, sko_rayon_y);
    }
}

/* matches, but too many unknowns, "test" var */
/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", do_sko_rayon2);*/

void do_sko_rayon2(void)
{
    Obj *poing_obj;
    s16 timer_zero;
    s16 diff_x; s16 diff_y;
    s16 diff_x_abs; s16 diff_y_abs;
    s16 dist;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s16 test;

    if (sko_rayon_on != 0)
    {
        sko_rayon_on--;
        if (poing.is_active)
        {
            D_801E4E10 = 3;
            poing_obj = &level.objects[poing_obj_id];
            sko_final_x = poing_obj->offset_bx + poing_obj->x_pos - 104;
            sko_final_y = poing_obj->offset_hy + poing_obj->y_pos - 120;
            timer_zero = horloge[2] == 0;
        }
        else
        {
            D_801E4E10 = 3;
            sko_final_x = ray.offset_bx + ray.x_pos - 120;
            sko_final_y = ray.offset_by + ray.y_pos - 140;
            timer_zero = horloge[8] == 0;
        }
        diff_y = sko_final_y - sko_rayon_y;
        diff_x = sko_final_x - sko_rayon_x;
        diff_x_abs = __builtin_abs(diff_x);
        diff_y_abs = __builtin_abs(diff_y);

        dist = diff_x_abs + diff_y_abs;
        if (dist > 0)
        {
            temp_v0_3 = ashl16(diff_x, (u32) D_801E4E10);
            temp_lo = temp_v0_3 / dist;
            diff_x = (s16) temp_lo;
            temp_v0_4 = ashl16(diff_y, (u32) D_801E4E10);
            temp_lo_2 = temp_v0_4 / dist;
            diff_y = (s16) temp_lo_2;
        }

        if (timer_zero)
        {
            temp_v0_5 = diff_x - sko_rayon_dx;
            if (temp_v0_5 >= 0)
                sko_rayon_dx += (temp_v0_5 > 0);
            else
                sko_rayon_dx -= (test = 1);
            temp_v0_6 = diff_y - sko_rayon_dy;
            if (temp_v0_6 >= 0)
                sko_rayon_dy += (temp_v0_6 > 0);
            else
                sko_rayon_dy -= (test = 1);
        }
        sko_rayon_x += sko_rayon_dx;
        sko_rayon_y += sko_rayon_dy;
        if (sko_rayon_x < -150)
        {
            sko_rayon_dx = -sko_rayon_dx;
            /* ??? can't even do += instead */
            sko_rayon_x = sko_rayon_x + sko_rayon_dx + sko_rayon_dx;
        }
        if (horloge[3] == 0 && dist != 0)
            allocate_rayon(sko_rayon_x, sko_rayon_y);
        if (sko_rayon_on == 0)
        {
            sko_rayon_x = -32000;
            sko_rayon_y = -32000;
        }
    }
}

/* matches, but goto */
/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SOL_ENFONCE);*/

/* 6D438 80191C38 -O2 -msoft-float */
void DO_SOL_ENFONCE(void)
{
  u8 bVar1;
  int iVar2;
  s16 iVar3;
  
  if (((ray_mode == MODE_MORT_DE_RAYMAN) || ((ray.main_etat == 2 && (ray.sub_etat == 9)))) ||
     ((ray.main_etat == 3 && ((ray.sub_etat == 0x17 || (ray.sub_etat == 0x34)))))) {
    sko_enfonce_enable = 0;
    pixels_enfonce = 0;
  }
  if (sko_ecran_tremble != 0) {
    sko_ecran_tremble--;
    if (horloge[4] >= 2)
      xmap += 2;
    else
      xmap -= 2;
  }
  if ((pixels_enfonce >= 0x60) || (sko_enfonce_enable != 1))
  {
      if (pixels_enfonce < 0xC4 && sko_enfonce_enable == 2)
      {
          goto block_19;
      }
  }
  else if (horloge[2] != 0)
  {
block_19:
      if (((s16) sko_enfonce_enable == 2) && (horloge[4] == 0))
      {
          goto block_21;
      }
  }
  else if (horloge[2] == 0)
  {
    block_21:
      if (horloge[4] >= 2) {
        xmap += 3;
      }
      else {
        xmap -= 3;
      }
      ymapmax = ymapmax + -1;
      scroll_end_y = scroll_end_y + -1;
      pixels_enfonce = pixels_enfonce + 1;
      iVar3 = 0;
      if ((pixels_enfonce & 0xf) == 0) {
        mp.height = mp.height + -1;
      }
      iVar2 = 0;
      if (sko_nb_lave != 0) {
        do {
          iVar2 = iVar2 >> 0x10;
          level.objects[sko_lave_obj[iVar3]].y_pos = level.objects[sko_lave_obj[iVar3]].y_pos + -1;
          level.objects[sko_lave_obj[iVar3]].init_y_pos =
              level.objects[sko_lave_obj[iVar3]].init_y_pos + -1;
          if ((sko_enfonce_enable == 1) && (horloge[10] == 0)) {
            level.objects[sko_lave_obj[iVar3]].y_pos = level.objects[sko_lave_obj[iVar3]].y_pos + -1;
            level.objects[sko_lave_obj[iVar3]].init_y_pos =
                level.objects[sko_lave_obj[iVar3]].init_y_pos + -1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < sko_nb_lave);
      }
  }
  if ((pixels_enfonce == 0x60) && (sko_enfonce_enable == 1)) {
    pixels_enfonce = 0;
    sko_enfonce_enable = 0;
    sko_ecran_tremble = 0x3c;
  }
  if ((pixels_enfonce == 0xc4) && (sko_enfonce_enable == 2)) {
    pixels_enfonce = 0;
    sko_enfonce_enable = 0;
    sko_ecran_tremble = 0x3c;
  }
}

/* matches, but sko_phase??? */
/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", SKO_ray_in_zone);*/

/* 6E3F0 80192BF0 -O2 -msoft-float */
void SKO_ray_in_zone(Obj *obj)
{
    s16 main_etat = obj->main_etat;
    s16 sub_etat = obj->sub_etat;
    if (sko_phase != 1 && sko_phase < 2 && sko_phase == 0)
    {
        if (main_etat == 0)
        {
            switch(sub_etat)
            {
            case 0:
                set_sub_etat(obj, 1);
                skipToLabel(obj, 2, true);
                sko_nb_frap = 0;
                break;
            case 2:
            case 3:
                set_sub_etat(obj, 4);
                skipToLabel(obj, 3, true);
                break;
            }
        }
    }
}