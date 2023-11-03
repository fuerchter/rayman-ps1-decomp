#include "obj/mama_pirate.h"

extern s16 bateau_obj_id;
extern CouteauxInfo CouteauxInfos[5];

/* 25D4C 8014A54C -O2 -msoft-float */
void pmamaFollowsShip(Obj *obj)
{
  if (bateau_obj_id != -1)
    snapToSprite(obj, &level.objects[bateau_obj_id], 6, -165, -94);
  else
  {
    obj->speed_x = 0;
    obj->speed_y = 0;
  }
}

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_couteaux);
#else
void init_couteaux(void)
{
  u8 cout_ind = 0;
  Obj *obj = level.objects;
  u8 i = 0;
  u8 nb_objs = level.nb_objects;

  if (nb_objs != 0) {
    do {
      if (cout_ind > 4)
        return;
      if (obj->type == TYPE_COUTEAU)
      {
        CouteauxInfos[cout_ind].x_pos = 0;
        CouteauxInfos[cout_ind].y_pos = 0;
        CouteauxInfos[cout_ind].field2_0x4 = 1;
        CouteauxInfos[cout_ind].field3_0x6 = 1;
        CouteauxInfos[cout_ind].field4_0x8 = 15;
        CouteauxInfos[cout_ind].field5_0xa = 0;
        CouteauxInfos[cout_ind].field6_0xc = 0;
        CouteauxInfos[cout_ind].field7_0xe = 0;
        CouteauxInfos[cout_ind].active = 0;
        CouteauxInfos[cout_ind].field9_0x10 = 5;
        CouteauxInfos[cout_ind].id = i;
        obj->flags &= ~FLG(OBJ_ALIVE);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->field23_0x3c = (u8)cout_ind;
        cout_ind++;
      }
      obj++;
      i++;
    } while (i < (s16)nb_objs);
  }

  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", reset_couteaux);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", check_couteaux);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", find_couteau);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", x_pos);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", y_pos);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", y_floor);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_move_couteau);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_lance_couteau);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", couteau_frame);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", update_couteau);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", get_cou_zdc);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", pma_attaque_suivante);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", convertspeed);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_parabolique);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_droit);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", retour_couteau);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", PS1_retour_couteau_old);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_lineaire);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", DO_COU_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", calc_pma_dir);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", DO_PMA_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_mama_pirate);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", PMA_SORT_DU_CANON);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", DO_PMA_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", pma_get_eject_sens);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", DO_COU_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", DO_PMA_ATTER);
