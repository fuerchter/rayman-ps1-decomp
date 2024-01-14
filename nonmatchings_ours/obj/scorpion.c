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