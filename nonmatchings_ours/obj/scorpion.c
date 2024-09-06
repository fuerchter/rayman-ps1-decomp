#include "obj/scorpion.h"

/* matches, but too many unknowns, "test" var */
/*INCLUDE_ASM("asm/nonmatchings/obj/scorpion", do_sko_rayon);*/

void do_sko_rayon(void)
{
    Obj *ecroule_obj;
    s16 diff_y;
    s16 diff_x;
    s16 dist;
    s16 diff_x_abs;
    s16 diff_y_abs;
    s32 temp_v0_5;
    s16 var_v1_2;
    s16 test;

    if (sko_rayon_on != 0)
    {
        D_801E4E10 = 3;
        sko_rayon_on--;
        ecroule_obj = &level.objects[sko_ecroule_plat];
        diff_y = sko_final_y - sko_rayon_y;
        diff_x = sko_final_x - sko_rayon_x;
        diff_x_abs = __builtin_abs(diff_x);
        diff_y_abs = __builtin_abs(diff_y);
        dist = diff_x_abs + diff_y_abs;
        if (dist < 8)
        {
            set_main_etat(ecroule_obj, 2);
            set_sub_etat(ecroule_obj, 2);
        }
        if (dist > 0)
        {
            diff_x = ashl16(diff_x, D_801E4E10) / dist;
            diff_y = ashl16(diff_y, D_801E4E10) / dist;
        }
        var_v1_2 = horloge[4] == 0 && sko_rayon_on < 50;
        if (var_v1_2 != 0)
        {
            temp_v0_5 = diff_x - sko_rayon_dx;
            if (temp_v0_5 >= 0)
                sko_rayon_dx += (temp_v0_5 > 0);
            else
                sko_rayon_dx -= (test = 1);

            temp_v0_5 = diff_y - sko_rayon_dy;
            if (temp_v0_5 >= 0)
                sko_rayon_dy += (temp_v0_5 > 0);
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
    s32 temp_v0_5;
    s16 test;

    if (sko_rayon_on != 0)
    {
        sko_rayon_on--;
        if (poing.is_active)
        {
            D_801E4E10 = 3;
            poing_obj = &level.objects[poing_obj_id];
            sko_final_x = poing_obj->x_pos + poing_obj->offset_bx - 104;
            sko_final_y = poing_obj->y_pos + poing_obj->offset_hy - 120;
            timer_zero = horloge[2] == 0;
        }
        else
        {
            D_801E4E10 = 3;
            sko_final_x = ray.x_pos + ray.offset_bx - 120;
            sko_final_y = ray.y_pos + ray.offset_by - 140;
            timer_zero = horloge[8] == 0;
        }
        diff_y = sko_final_y - sko_rayon_y;
        diff_x = sko_final_x - sko_rayon_x;
        diff_x_abs = __builtin_abs(diff_x);
        diff_y_abs = __builtin_abs(diff_y);

        dist = diff_x_abs + diff_y_abs;
        if (dist > 0)
        {
            diff_x = ashl16(diff_x, (u32) D_801E4E10) / dist;
            diff_y = ashl16(diff_y, (u32) D_801E4E10) / dist;
        }

        if (timer_zero)
        {
            /* these are sgn() calls on android */
            temp_v0_5 = diff_x - sko_rayon_dx;
            if (temp_v0_5 >= 0)
                sko_rayon_dx += (temp_v0_5 > 0);
            else
                sko_rayon_dx -= (test = 1);
            temp_v0_5 = diff_y - sko_rayon_dy;
            if (temp_v0_5 >= 0)
                sko_rayon_dy += (temp_v0_5 > 0);
            else
                sko_rayon_dy -= (test = 1);
        }
        sko_rayon_x += sko_rayon_dx;
        sko_rayon_y += sko_rayon_dy;
        if (sko_rayon_x < -150)
        {
            sko_rayon_dx = -sko_rayon_dx;
            sko_rayon_x += sko_rayon_dx;
            sko_rayon_x += sko_rayon_dx;
        }

        timer_zero = horloge[3] == 0;
        if (timer_zero && dist != 0)
            allocate_rayon(sko_rayon_x, sko_rayon_y);
        if (sko_rayon_on == 0)
        {
            sko_rayon_x = -32000;
            sko_rayon_y = -32000;
        }
    }
}

/*
attempts: 2
matches, but goto
*/
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
  if (!(pixels_enfonce < 0x60 && sko_enfonce_enable == 1))
  {
      if (pixels_enfonce < 0xC4 && sko_enfonce_enable == 2)
      {
          goto block_19;
      }
  }
  else if (pixels_enfonce < 0x60 && sko_enfonce_enable == 1 && horloge[2] != 0)
  {
block_19:
      if (((s16) sko_enfonce_enable == 2) && (horloge[4] == 0))
      {
          goto block_21;
      }
  }
  else if (pixels_enfonce < 0x60 && sko_enfonce_enable == 1 && horloge[2] == 0)
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