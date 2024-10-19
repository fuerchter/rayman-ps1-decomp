#include "obj/scorpion.h"

/*
attempts: 2
matches, but goto (partially gotos-only)
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