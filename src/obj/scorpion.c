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
extern s32 pixels_enfonce;
extern s16 sko_last_action;
extern s16 sko_nb_frap;
extern s16 sko_nb_hit;
extern s16 sko_phase;

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

/* 6D1D0 801919D0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/scorpion", start_sko_rayon);
#else
void start_sko_rayon(s16 obj_x, s16 obj_y)
{
    Obj *ecroule_obj;

    ecroule_plat_index++;
    sko_ecroule_plat = ecroule_rubis_list[ecroule_rubis_order[ecroule_plat_index]];
    ecroule_obj = &level.objects[sko_ecroule_plat];
    if (sko_rayon_on != 0xFF)
        sko_rayon_on = 60;
    sko_rayon_x = obj_x - 80;
    sko_rayon_dx = -4;
    sko_rayon_y = obj_y - 10;
    sko_rayon_dy = 4;
    sko_final_x = ecroule_obj->offset_bx + ecroule_obj->x_pos - 120;
    sko_final_y = ecroule_obj->offset_hy + ecroule_obj->y_pos - 120;
    allocate_rayon(sko_rayon_x, sko_rayon_y);

    __asm__("nop\nnop");
}
#endif

/* 6D2E0 80191AE0 -O2 -msoft-float */
void start_sko_rayon2(s16 obj_x, s16 obj_y)
{
    Obj* final_obj;

    if (poing.is_active)
        final_obj = &level.objects[poing_obj_id];
    else
        final_obj = &ray;
    sko_rayon_on = 120;
    sko_rayon_x = obj_x - 80;
    sko_rayon_dx = -4;
    sko_rayon_y = obj_y - 10;
    sko_rayon_dy = 2;
    sko_final_x = final_obj->offset_bx + final_obj->x_pos - 120;
    sko_final_y = final_obj->offset_hy + final_obj->y_pos - 120;
    allocate_rayon(sko_rayon_x, sko_rayon_y);
}

/* 6D3B4 80191BB4 -O2 -msoft-float */
void lance_pince(Obj *sko_obj)
{
    Obj *pince_obj = &level.objects[sko_pince_obj_id];
    pince_obj->flags |= FLG(OBJ_ALIVE);
    pince_obj->x_pos = sko_obj->x_pos;
    pince_obj->y_pos = sko_obj->y_pos;
    pince_obj->speed_x = -128;
    pince_obj->speed_y = 0;
    calc_obj_pos(pince_obj);
}

/* 6D424 80191C24 -O2 -msoft-float */
s32 sko_get_eject_sens(void)
{
    ray.iframes_timer = 40;
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SOL_ENFONCE);

/* 6D7FC 80191FFC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_0);
#else
void DO_SKO_PHASE_0(Obj *sko_obj)
{
    s16 sko_sub_etat;
    Obj *ecroule_obj;

    sko_sub_etat = sko_obj->sub_etat;
    ecroule_obj = &level.objects[sko_ecroule_plat];
    if (sko_obj->main_etat == 0 && sko_sub_etat >= 2)
    {
        if (sko_sub_etat >= 4)
        {
            if (sko_sub_etat == 4 && sko_obj->anim_frame == 27 && screen_trembling == 0)
            {
                screen_trembling = 1;
                sko_nb_frap++;
                if (ecroule_obj->sub_etat == 7)
                {
                    set_main_etat(ecroule_obj, 2);
                    set_sub_etat(ecroule_obj, 2);
                    ecroule_plat_index++;
                    sko_ecroule_plat = ecroule_rubis_list[ecroule_rubis_order[ecroule_plat_index]];
                }
                if (sko_nb_frap == sko_sub_etat)
                    skipToLabel(sko_obj, 4, 1);
                if (sko_nb_frap == 5)
                {
                    sko_nb_frap = 0;
                    sko_nb_hit = 0;
                    sko_phase++;
                    skipToLabel(sko_obj, 5, 1);
                    ecroule_plat_index--;
                }
            }
        }
        else
        {
            if (sko_last_action == 4)
            {
                set_sub_etat(sko_obj, 8);
                sko_last_action = 8;
            }
            else
            {
                set_sub_etat(sko_obj, 4);
                skipToLabel(sko_obj, 3, 1);
                sko_last_action = 4;
            }
        }
    }

    __asm__("nop\nnop");
}
#endif

/* 6D9FC 801921FC -O2 -msoft-float */
void DO_SKO_PHASE_1(Obj *obj)
{
    s16 sub_etat = obj->sub_etat;
    if (
      obj->main_etat == 0 && sub_etat == 4 &&
      obj->anim_frame == 27 && screen_trembling == 0
    )
    {
        screen_trembling = 1;
        sko_nb_frap++;
        if (ray.main_etat == 5)
        {
            set_main_etat(&ray, 2);
            set_sub_etat(&ray, 2);
        }
        if (sko_nb_frap == 3)
        {
            sko_rayon_on = 0;
            sko_phase++;
            skipToLabel(obj, 6, 1);
            sko_nb_frap = 0;
            obj->anim_frame = 0;
        }
    }
}

/* 6DAF0 801922F0 -O2 -msoft-float */
void DO_SKO_PHASE_2(Obj *obj)
{
    s16 main_etat;
    s16 sub_etat;

    main_etat = obj->main_etat;
    sub_etat = obj->sub_etat;
    do_sko_rayon();
    switch (main_etat)
    {
    case 0:
        switch (sub_etat)
        {
        case 4:
            switch (sko_nb_frap)
            {
            case 0:
                if (obj->anim_frame == 27)
                {
                    sko_nb_frap++;
                    sko_enfonce_enable = 1;
                }
                break;
            case 1:
                if (obj->anim_frame == 27)
                {
                    sko_nb_frap++;
                    screen_trembling = 1;
                }
                break;
            }
            break;
        case 2:
        case 3:
            set_sub_etat(obj, 5);
            break;
        case 7:
            if (obj->anim_frame == 9 && sko_rayon_on == 0)
            {
                start_sko_rayon(obj->x_pos, obj->y_pos);
                if (++sko_nb_frap == 5)
                {
                    skipToLabel(obj, 7, 1);
                    sko_nb_frap = 0;
                    sko_phase++;
                }
            }
            break;
        }
        break;
    default:
        if (
            main_etat == 1 && sub_etat == 15 &&
            obj->nb_cmd == sko_nb_hit
        )
            obj->nb_cmd = 0;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PHASE_3);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_PINCE);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SCORPION_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SCORPION_MORT);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", SKO_ray_in_zone);

INCLUDE_ASM("asm/nonmatchings/obj/scorpion", DO_SKO_HIT);
