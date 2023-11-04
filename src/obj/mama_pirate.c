#include "obj/mama_pirate.h"

extern s16 bateau_obj_id;
extern CouteauxInfo CouteauxInfos[5];
extern u8 pma_attaque;
extern u8 pma_couteaux[6];
extern u8 pma_groupe;
extern u8 pma_sequence[4][2];
extern s16 mama_pirate_obj_id;
extern u8 pma_type_attaque;

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

/* 25DB0 8014A5B0 -O2 -msoft-float */
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
        CouteauxInfos[cout_ind].active = false;
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

/* 25EFC 8014A6FC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", reset_couteaux);
#else
void reset_couteaux(void)
{
  u8 i;

  for(i = 0; i < 5; i++)
    CouteauxInfos[i].active = false;

  __asm__("nop");
}
#endif

/* 25F3C 8014A73C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", check_couteaux);
#else
u8 check_couteaux(void)
{
  u8 nb_active;
  u8 i;

  __asm__("nop\nnop");

  nb_active = 0;
  for(i = 0; i < 5; i++)
    if (CouteauxInfos[i].active == true)
      nb_active++;
  
  return nb_active == pma_couteaux[pma_sequence[pma_groupe][pma_attaque]];
}
#endif

/* 25FD4 8014A7D4 -O2 -msoft-float */
u8 find_couteau(Obj *obj)
{
  u8 bVar1 = obj->field23_0x3c;

  if (bVar1 > 4)
    bVar1 = 0xff;
  return bVar1;
}

/* 25FF4 8014A7F4 -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", x_pos);
#else
s32 x_pos(u8 param_1, u8 nb_couteau)
{
  s16 x;
  
  __asm__("nop");

  if (nb_couteau == 0)
    x = 0;
  else
  {
    x = (param_1 * 2 + 1) * (240 / (nb_couteau * 2));
    if (level.objects[mama_pirate_obj_id].flags & FLG(OBJ_FLIP_X))
      x += 80;
  }
  return x;
}
#endif

/* 26090 8014A890 -O2 -msoft-float */
s32 y_pos(s16 param_1, s16 param_2)
{
  s16 y;
  
  if (param_2 == 0)
    y = 44;
  else
    y = param_1 * 16 + 44;
  return y;
}

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", y_floor);
#else
s16 y_floor(s16 x, s16 y)
{
  u8 btyp;
  
  btyp = PS1_BTYPAbsPos(x, y);
  while (!(block_flags[btyp] >> BLOCK_SOLID & 1))
  {
    y += 16;
    btyp = PS1_BTYPAbsPos(x, y);
  }

  __asm__("nop");
  return dist_to_bloc_floor(btyp, x & 0xf, 0) + (y & ~0xf); /* TODO: what do these &s do? */
}
#endif

/* 26174 8014A974 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_move_couteau);
#else
void init_move_couteau(Obj *obj)
{
  u8 cout_ind;
  Obj cout_obj;
  s16 x;
  s16 y;
  u8 test_1;
  
  cout_ind = find_couteau(obj);
  if (cout_ind != 0xff)
  {
    __builtin_memcpy(&cout_obj, &level.objects[CouteauxInfos[cout_ind].id], sizeof(Obj));
    x = cout_obj.x_pos + cout_obj.offset_bx; /* how should i have known this, given that 0x2c on stack was x_pos? */
    y = cout_obj.y_pos + cout_obj.offset_by;
    CouteauxInfos[cout_ind].active = false;

    switch(pma_type_attaque)
    {
    case 0:
    case 1:
    case 2:
    case 5:
      CouteauxInfos[cout_ind].x_pos = x;
      CouteauxInfos[cout_ind].y_pos = y;
      CouteauxInfos[cout_ind].field9_0x10 = 2;
      CouteauxInfos[cout_ind].field2_0x4 = 1;
      CouteauxInfos[cout_ind].field3_0x6 = 1;
      break;
    case 3:
    case 4:
      test_1 = (pma_type_attaque == 3) * 4; /* TODO: this/x_pos param is what? */
      if (cout_ind == 1)
        CouteauxInfos[cout_ind].x_pos = x_pos(test_1, 6);
      else
        CouteauxInfos[cout_ind].x_pos = x_pos(4 - test_1, 6);
      CouteauxInfos[cout_ind].y_pos = y_pos(11 - cout_ind, 1) + 8;
      CouteauxInfos[cout_ind].field9_0x10 = 0;
      if (cout_ind == 0)
        CouteauxInfos[0].field2_0x4 = 50;
      else
        CouteauxInfos[cout_ind].field2_0x4 = 50;
      CouteauxInfos[cout_ind].field3_0x6 = 70;
      break;
    }
  }

  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_lance_couteau); /* larger */

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
