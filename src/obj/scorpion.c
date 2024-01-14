#include "obj/scorpion.h"

extern u8 ecroule_rubis_list[8];
extern u8 ecroule_plat_index;
extern u8 ecroule_rubis_order[24];
extern s16 rubis_list_calculated;
extern s32 sko_ecran_tremble;
extern s16 sko_ecroule_plat;
extern u8 sko_enfonce_enable;
extern u8 sko_lave_obj[20];
extern u8 sko_nb_lave;
extern s16 sko_pince_obj_id;
extern s16 D_801C83A4[8];
extern s16 D_801C83B4[8];

extern s16 D_801E4E10;
extern s16 sko_final_x;
extern s16 sko_final_y;
extern s16 sko_rayon_dx;
extern s16 sko_rayon_dy;
extern s16 sko_rayon_on;
extern s16 sko_rayon_x;
extern s16 sko_rayon_y;

s32 myRand(s32 param_1);
Obj * allocateNOVA(void);
void calc_obj_pos(Obj *obj);
Obj * findfirstObject(ObjType objType);
void start_pix_gerbe(s32 param_1, s32 param_2);
void set_main_etat(Obj *param_1, u8 etat);
void set_sub_etat(Obj *obj, u8 subEtat);

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/scorpion", swap);
#else
void swap(s32 ind_1, s32 ind_2)
{
  u8 temp = ecroule_rubis_list[ind_1];
  ecroule_rubis_list[ind_1] = ecroule_rubis_list[ind_2];
  ecroule_rubis_list[ind_2] = temp;
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", set_rubis_list);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", allocate_rayon);

/* 6CAE0 801912E0 -O2 -msoft-float */
void allocate_8_petits_rayons(s16 x, s16 y)
{
  Obj *found_obj;
  s16 i;
  Obj *rayon_obj;
  
  found_obj = allocateNOVA();
  if (found_obj != null)
  {
    found_obj->x_pos = x + 64;
    found_obj->y_pos = y + 64;
    found_obj->display_prio = 1;
    found_obj->field23_0x3c = 0;
    found_obj->flags |= FLG(OBJ_ACTIVE);
    calc_obj_pos(found_obj);
  }
  start_pix_gerbe(x + 140, y + 32);
  found_obj = findfirstObject(TYPE_RAYON);
  i = 0;
  rayon_obj = &found_obj[10];
  while (i < 8)
  {
    rayon_obj->x_pos = x + 8;
    rayon_obj->y_pos = y;
    rayon_obj->main_etat = 3;
    rayon_obj->sub_etat = 2;
    rayon_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    rayon_obj->speed_x = D_801C83A4[i];
    rayon_obj->speed_y = D_801C83B4[i];
    rayon_obj->anim_frame = 2;
    i++;
    rayon_obj++;
  }
}

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", do_sko_rayon);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", do_sko_rayon2);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", start_sko_rayon);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", start_sko_rayon2);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", lance_pince);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", sko_get_eject_sens);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SOL_ENFONCE);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_0);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_1);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_2);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_3);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PINCE);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SCORPION_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SCORPION_MORT);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", SKO_ray_in_zone);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_HIT);
