#include "obj/mama_pirate.h"

extern s16 bateau_obj_id;
extern CouteauxInfo CouteauxInfos[5];
extern u8 pma_attaque;
extern u8 pma_couteaux[6];
extern u8 pma_groupe;
extern u8 pma_sequence[4][2];
extern s16 mama_pirate_obj_id;
extern u8 pma_type_attaque;
extern u8 cou_place;
extern s16 cou_tempo;
extern u8 place_sequence[5];
extern u8 pma_nb_couteau;
extern u8 pma_phase;
extern s16 pma_tempo;
extern u8 pma_touched;

s32 ashl16(s16, u32);

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
        CouteauxInfos[cout_ind].field2_0x4 = 50;
      else
        CouteauxInfos[cout_ind].field2_0x4 = 50;
      CouteauxInfos[cout_ind].field3_0x6 = 70;
      break;
    }
  }

  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", init_lance_couteau);

/* 267EC 8014AFEC -O2 -msoft-float */
u8 couteau_frame(s16 speed_x, s16 speed_y)
{
    u8 frame;
    s32 loc_speed_x;
    s32 loc_speed_y;
    s32 speed_x_check;
    s16 diff;

    if (speed_x == 0)
        frame = ((u32)speed_y / 4096) & 8;
    else
    {
        loc_speed_y = speed_y;
        if (loc_speed_y == 0)
        {
            frame = 12;
            loc_speed_x = speed_x;
            if (loc_speed_x > 0)
              frame = 4;
        }
        else
        {
            speed_x_check = speed_x < 0;
            loc_speed_x = speed_x;
            if (speed_x_check)
                loc_speed_x *= -1;
            if (loc_speed_y < 0)
                loc_speed_y *= -1;
            diff = loc_speed_x - loc_speed_y;
            if (diff != 0)
            {
                frame = 7;
                if (diff >= 0)
                    frame = 5;
            }
            else
                frame = 6;
            
            if (speed_x > 0)
            {
                if (speed_y > 0)
                    frame = 8 - frame;
            }
            else if (speed_y < 0)
                frame = 16 - frame;
            else
                frame += 8;
        }
    }
    return frame;
}

/* 268AC 8014B0AC -O2 -msoft-float */
void update_couteau(Obj *obj)
{
    obj->anim_frame = couteau_frame(obj->speed_x, obj->speed_y);
}

/* 268E0 8014B0E0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", get_cou_zdc);
#else
void get_cou_zdc(Obj *obj, s16 *x, s16 *y, s16 *w, s16 *h)
{
  s16 spr_x;
  s16 spr_y;
  s16 spr_w;
  s16 spr_h;
  u8 sub_etat;
  
  __asm__("nop"); /* move instruction moved... */

  GET_SPRITE_POS(obj, 0, &spr_x, &spr_y, &spr_w, &spr_h);
  *w = 6;
  *h = 6;
  if (obj->main_etat == 2)
  {
    sub_etat = obj->sub_etat;
    if (sub_etat - 10 <= 1U)
    {
      switch(obj->anim_frame)
      {
      case 0:
        *x = spr_x + (spr_w - *w >> 1);
        *y = spr_y + spr_h - *h;
        return;
      case 1:
      case 2:
      case 3:
        *x = spr_x + spr_w - *w;
        *y = spr_y + spr_h - *h;
        return;
      case 4:
        *w = spr_w;
        *x = spr_x + spr_w - *w;
        *y = spr_y + (spr_h - *h >> 1);
        return;
      case 5:
      case 6:
      case 7:
        *x = spr_x + spr_w - *w;
        *y = spr_y;
        return;
      case 8:
        *x = spr_x + (spr_w - *w >> 1);
        *y = spr_y;
        return;
      case 9:
      case 10:
      case 11:
        *x = spr_x;
        *y = spr_y;
        return;
      case 12:
        *w = spr_w;
        *x = spr_x;
        *y = spr_y + (spr_h - *h >> 1);
        return;
      case 13:
      case 14:
      case 15:
        *x = spr_x;
        *y = spr_y + spr_h - *h;
        return;
      default:
        *x = spr_x + (spr_w - *w >> 1);
        *y = spr_y + spr_h - *h;
        return;
      }
    }
    else
    {
      if (obj->sub_etat == 14 && !(obj->eta[2][obj->sub_etat].anim_speed & 0xf))
      {
        *h = spr_h;
        *x = spr_x + (spr_w - *w >> 1);
        *y = spr_y;
        return;
      }
      if (obj->main_etat == 2)
      {
        if (
          (obj->sub_etat == 13) ||
          (obj->sub_etat == 14 && obj->eta[2][obj->sub_etat].anim_speed & 0xf)
        )
        {
          *x = - ((*w >> 1) + -0x80) + obj->x_pos;
          *y = - ((*h >> 1) + -0x60) + obj->y_pos;
          return;
        }
        if (obj->main_etat == 2 && obj->sub_etat == 12)
        {
          *x = spr_x + (spr_w - *w >> 1);
          *y = spr_y + spr_h - *h;
          return;
        }
      }
    }
  }
  *x = -*w;
  *y = -*h;
}
#endif

/* 26C98 8014B498 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", pma_attaque_suivante);
#else
void pma_attaque_suivante(void)
{
  u8 i;
  
  __asm__("nop\nnop\nnop");
  if ((pma_type_attaque - 1 < 2U) && (cou_place++, cou_place > 4))
    cou_place = 0;
  
  if (pma_touched || (pma_attaque++, pma_attaque == 2))
  {
    pma_groupe++;
    pma_attaque = 0;
    if (pma_groupe == 4)
    {
      pma_tempo -= 10;
      cou_tempo -= 10;
      pma_groupe = 0;
    }
  }
  if (pma_tempo < 100)
    pma_tempo = 100;

  if (cou_tempo < 50)
    cou_tempo = 50;
  pma_phase = 0;
  pma_type_attaque = pma_sequence[pma_groupe][pma_attaque];
  pma_nb_couteau = pma_couteaux[pma_type_attaque];
  pma_touched = false;
  
  for(i = 0; i < 5; i++)
  {
    level.objects[CouteauxInfos[i].id].flags &= ~FLG(OBJ_ACTIVE);
    level.objects[CouteauxInfos[i].id].flags &= ~FLG(OBJ_ALIVE);
  }
}
#endif

/* TODO: ashl16 return has changed
/* 26EDC 8014B6DC -O2 -msoft-float */
s16 convertspeed(s16 speed)
{
  return ashl16(speed, 4);
}

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_parabolique);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", lance_couteau_droit);

INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", retour_couteau);

/* 276F4 8014BEF4 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/obj/mama_pirate", PS1_retour_couteau_old);
#else
void PS1_retour_couteau_old(Obj *obj)
{
    u8 cout_ind;
    s16 diff_x;
    s16 diff_y;
    s32 abs_x;
    s32 abs_y;
    s32 divisor;

    cout_ind = find_couteau(obj);
    if (cout_ind != 0xFF)
    {
        diff_x = 0;
        diff_y = 0;
        if (CouteauxInfos[cout_ind].field9_0x10 != 2)
        {
            /* addressing is a little weird */
            diff_x = (xmap + CouteauxInfos[cout_ind].x_pos) - (obj->offset_bx + obj->x_pos);
            diff_y = (ymap + (&CouteauxInfos[cout_ind])->y_pos) - (obj->offset_by + obj->y_pos);
        }

        if (__builtin_abs(diff_x) >= 2 || __builtin_abs(diff_y) >= 2)
        {
            CouteauxInfos[cout_ind].active = false;
            abs_x = __builtin_abs(diff_x);
            abs_y = __builtin_abs(diff_y);
            if (abs_x < abs_y)
                abs_x = abs_y;
            divisor = 2;
            divisor = ashl16(abs_x, 4) / divisor;
            obj->speed_x = convertspeed(ashl16(diff_x, 4) / (s16) divisor);
            obj->speed_y = convertspeed(ashl16(diff_y, 4) / (s16) divisor);
        }
        else
        {
            CouteauxInfos[cout_ind].active = true;
            obj->speed_x = convertspeed(0);
            obj->speed_y = convertspeed(0);
            if (CouteauxInfos[cout_ind].field9_0x10 != 2)
            {
                obj->x_pos = xmap + CouteauxInfos[cout_ind].x_pos - obj->offset_bx;
                obj->y_pos = ymap + CouteauxInfos[cout_ind].y_pos - obj->offset_by;
            }
            if (check_couteaux())
            {
                pma_phase = 3;
                reset_couteaux();
            }
        }
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

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
