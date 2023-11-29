#include "collision/collision.h"

/* 10000 (dist) could be a #define */

s16 GET_SPRITE_POS(Obj *obj,s32 spriteIndex,s16 *x,s16 *y,u16 *w,u16 *h);

extern s16 ZDCPTR;
extern ZDC zdc_tab[512];
extern u16 type_zdc[256];
extern s16 bagD[20];
extern s16 bagW[20];
extern s16 bagH[20];
extern s16 Mus_obj_id;
extern u8 Nb_total_cages;
extern s16 prise_branchee;

/* 1B1F0 8013F9F0 -O2 -msoft-float */
void PS1_SetZDC(s16 x, s16 y, u8 w, u8 h, u8 flags, u8 sprite)
{
    ZDC *zdc = &zdc_tab[ZDCPTR];

    zdc->x_pos = x;
    zdc->y_pos = y;
    zdc->width = w;
    zdc->height = h;
    zdc->flags = flags;
    zdc->sprite = sprite + 0xFF; /* ??? */
    ZDCPTR++;
}

/* 1B248 8013FA48 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_SetTypeZDC);
#else
void PS1_SetTypeZDC(ObjType type, u16 param_2, s32 param_3)
{
    type_zdc[type] = param_2 | (param_3 << 11);
    
    __asm__("nop");
}
#endif

/* 1B270 8013FA70 -O2 -msoft-float */
u16 get_nb_zdc(Obj *obj)
{
    return obj->zdc >> 11;
}

/*
first 11 bits, see
https://github.com/BinarySerializer/BinarySerializer.Ray1/blob/0323431715346d65200f898664351932b86deb8b/src/BinarySerializer.Ray1/DataTypes/Collision/ZDCReference.cs#L6
*/
/* 1B27C 8013FA7C -O2 -msoft-float */
u16 get_zdc_index(Obj *obj)
{
    return obj->zdc & 0x7ff;
}

/* 1B288 8013FA88 -O2 -msoft-float */
ZDC *get_zdc(Obj *obj, s16 param_2)
{
    return &zdc_tab[(s16) get_zdc_index(obj) + param_2];
}

/* 1B2D0 8013FAD0 -O2 -msoft-float */
s16 get_ZDCPTR(void)
{
    return ZDCPTR;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_v_line);
/* ??? think param_6 and 7 might be s32 ??? */

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_h_line);

/* 1B57C 8013FD7C -O2 -msoft-float */
s32 inter_box(s32 x_1, s32 y_1, s32 w_1, s32 h_1, s16 x_2, s16 y_2, s32 w_2, s32 h_2)
{
    s16 unk_1 = x_1 - w_2;
    s16 unk_2 = y_1 - h_2;
    s16 unk_3 = w_1 + w_2;
    s16 unk_4 = h_1 + h_2;
    u8 res = false;

    if (x_2 >= unk_1 && y_2 >= unk_2 && (unk_1 + unk_3 >= x_2))
        res = (unk_2 + unk_4 < y_2) ^ 1;
    return res;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_OBJ_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_SPRITE_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_HIT_SPECIAL_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_IN_COLL_ZONES);

/* 1CD38 80141538 -O2 -msoft-float */
s32 COLL_BOX_SPRITE(s16 in_x, s16 in_y, s16 in_w, s16 in_h, Obj *obj)
{
  s16 unk_1;
  s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
  s32 spr;
  
  unk_1 = GET_SPRITE_POS(obj, obj->hit_sprite, &spr_x, &spr_y, &spr_w, &spr_h);
  if (unk_1 != 0)
    unk_1 = inter_box(in_x, in_y, in_w, in_h, spr_x, spr_y, spr_w, spr_h);
  if (unk_1 != 0)
    spr = obj->hit_sprite;
  else
    spr = -1;
  return spr;
}

/* 1CE18 80141618 -O2 -msoft-float */
s16 CHECK_BOX_COLLISION(s16 obj_type, s16 x, s16 y, s16 w, s16 h, Obj *obj)
{
    s32 h_spr;
    s16 res;

    if (obj->hit_sprite == 0xFD)
        res = BOX_HIT_SPECIAL_ZDC(x, y, w, h, obj);
    else if (((h_spr = obj->hit_sprite) >= 0xFD) && h_spr < 0x100)
        res = BOX_IN_COLL_ZONES(obj_type, x, y, w, h, obj);
    else
        res = COLL_BOX_SPRITE(x, y, w, h, obj);
    return res;
}

/* 1CF08 80141708 -O2 -msoft-float */
s16 possible_sprite(Obj *obj, s16 index)
{
    s16 spr[12];
    
    switch(obj->type)
    {
    case TYPE_BON3:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 2;
        spr[3] = 3;
        spr[4] = 4;
        spr[5] = 0x00FF;
        break;
    case TYPE_CYMBALE:
    case TYPE_CYMBAL2:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 2;
        spr[3] = 0x00FF;
        break;
    case TYPE_ROULETTE:
        spr[0] = 5;
        spr[1] = 6;
        spr[2] = 7;
        spr[3] = 8;
        spr[4] = 0x00FF;
        break;
    case TYPE_ROULETTE2:
        spr[0] = 1;
        spr[1] = 2;
        spr[2] = 3;
        spr[3] = 4;
        spr[4] = 0x00FF;
        break;
    case TYPE_ROULETTE3:
        spr[0] = 1;
        spr[1] = 2;
        spr[2] = 3;
        spr[3] = 0x00FF;
        break;
    case TYPE_FALLPLAT:
    case TYPE_LIFTPLAT:
    case TYPE_INTERACTPLT:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 0x00FF;
        break;
    case TYPE_TIBETAIN_6:
        if (ray.flags & FLG(OBJ_FLIP_X))
        {
            spr[0] = 4;
            spr[1] = 5;
            spr[2] = 6;
            spr[3] = 7;
            spr[4] = 8;
            spr[5] = 9;
        }
        else
        {
            spr[0] = 9;
            spr[1] = 8;
            spr[2] = 7;
            spr[3] = 6;
            spr[4] = 5;
            spr[5] = 4;
        }
        spr[6] = 0x00FF;
        break;
    case TYPE_TIBETAIN_2:
        spr[0] = 4;
        spr[1] = 5;
        spr[2] = 0x00FF;
        break;
    }
    return spr[index];
}

/* 1D11C 8014191C -O2 -msoft-float */
s16 setToleranceDist(s16 in_x, s16 in_w, s16 in_y)
{
    s16 unk_2;
    s16 dist;
    s16 ray_x = ray.x_pos + ray.offset_bx;
    s16 ray_y = ray.y_pos + ray.offset_by;
    s16 unk_1 = in_x + in_w - 1;

    if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
        unk_2 = 4;
    else
        unk_2 = 8;
    
    if ((ray_x >= in_x - unk_2) && (ray_x <= unk_1 + unk_2))
    {
        if (ray_x >= in_x && ray_x <= unk_1)
        {
            /* abs??? */
            if (ray_y - in_y >= 0)
                dist = ray_y - in_y;
            else
                dist = in_y - ray_y;
        }
        else
        {
            if (ray_y - in_y < 0)
                dist = ray_y - in_y;
            else
                dist = in_y - ray_y;
            dist--;
        }
    }
    else
        dist = 10000;
    return dist;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_MULTISPR_CANTCHANGE);

/* 1D594 80141D94 -O2 -msoft-float */
void SET_RAY_DIST_PI(Obj *obj)
{
  s16 x; s16 y; s16 w; s16 h;
  s16 new_dist;
  s16 prev_flip_x = (obj->flags >> OBJ_FLIP_X & 1) << OBJ_FLIP_X;
  
  obj->flags &= ~FLG(OBJ_FLIP_X);
  GET_SPRITE_POS(obj, 2, &x, &y, &w, &h);
  obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | prev_flip_x;
  y += obj->offset_hy;
  x += 4;
  w = 55;
  new_dist = setToleranceDist(x, w, y);
  if (new_dist != 10000)
    obj->follow_sprite = 2;
  obj->ray_dist = new_dist;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_BAG);

/* 1D798 80141F98 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST);
#else
void SET_RAY_DIST(Obj *obj)
{
  ObjType type;
  s16 x; s16 y; s16 w; s16 h;
  
  type = obj->type;
  if (flags[type].flags1 >> OBJ1_RAY_DIST_MULTISPR_CANTCHANGE & 1)
    SET_RAY_DIST_MULTISPR_CANTCHANGE(obj);
  else
  {
    if (type == TYPE_PI || type == TYPE_BBL)
      SET_RAY_DIST_PI(obj);
    else if (type == TYPE_BAG3)
      SET_RAY_DIST_BAG(obj);
    else
    {
      GET_SPRITE_POS(obj, obj->follow_sprite, &x, &y, &w, &h);
      y += obj->offset_hy;
      type = obj->type;
      if (
        type == TYPE_FALLING_OBJ || type == TYPE_FALLING_OBJ2 || type == TYPE_FALLING_OBJ3 ||
        type == TYPE_FALLING_YING || type == TYPE_FALLING_YING_OUYE
      )
      {
        x -= 2;
        w += 4;
      }
      else if (type == TYPE_MOVE_START_NUA || (type == TYPE_PLATFORM && num_world == 2))
        w -= 8;
      
      obj->ray_dist = setToleranceDist(x, w, y);
    }
  }

  __asm__("nop");
}
#endif

/* 1D8FC 801420FC -O2 -msoft-float */
void do_boum(void)
{
  Obj *obj;
  
  allocatePoingBoum();
  poing.is_boum = true;
  obj = &level.objects[poing_obj_id];
  if (!poing.is_returning)
  {
    poing.is_returning = true;
    poing.charge = 0;
    obj->speed_x = 0;
    fist_U_turn(obj, true);
    obj->anim_index = obj->eta[obj->main_etat][obj->sub_etat].anim_index;
  }
}

/* 1D9A0 801421A0 -O2 -msoft-float */
void DO_PNG_COLL_STONEMAN(Obj *obj)
{
  u8 prev_flip_x;
  
  if (!(obj->main_etat == 0 && obj->sub_etat == 1))
    obj_hurt(obj);
  prev_flip_x = (obj->flags >> OBJ_FLIP_X & 1);
  calc_obj_dir(obj);
  skipToLabel(obj, 8, true);
  if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
  {
    skipToLabel(obj, 1, true);
    if (obj->type == TYPE_STONEMAN1)
      allocateStonemanStone(obj, -2, 0);
  }
  if (obj->hit_points < 3)
  {
    if (obj->type == TYPE_STONEMAN1)
      allocateStonemanStone(obj, -2, 0);
    if (obj->hit_points == 0)
    {
      obj->hit_points = obj->init_hit_points;
      skipToLabel(obj, 0, true);
    }
    else
    {
      skipToLabel(obj, 1, true);
      obj->change_anim_mode = ANIMMODE_RESET;
    }
  }
}

/* 1DAC4 801422C4 -O2 -msoft-float */
void DO_PNG_COLL_STONEWOMAN(Obj *obj)
{
    u8 prev_flip_x;

    obj_hurt(obj);
    obj->timer = 0;
    prev_flip_x = (obj->flags >> OBJ_FLIP_X) & 1;
    calc_obj_dir(obj);
    PlaySnd(86, obj->id);
    if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
    {
        allocateStonewomanStone(obj, 0);
        skipToLabel(obj, 1, true);
        return;
    }
    if (obj->hit_points < 15)
    {
        allocateStonewomanStone(obj, 0);
        if (obj->hit_points == 0)
        {
            obj->hit_points = obj->init_hit_points;
            skipToLabel(obj, 0, true);
        }
        else
        {
            if (obj->main_etat != 1)
                skipToLabel(obj, 1, true);
            obj->change_anim_mode = 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_POING_COLLISION);

/* 1F06C 8014386C -O2 -msoft-float */
s32 COLL_BOX_ALL_SPRITES(s16 in_x, s16 in_y, s16 in_w, s16 in_h, Obj *obj)
{
    s16 i;
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 res;

    for (i = 0; i < (obj->animations[obj->anim_index].layers_count & 0x3FFF); i++)
    {
        GET_SPRITE_POS(obj, i, &spr_x, &spr_y, &spr_w, &spr_h);
        if ((s16) inter_box(in_x, in_y, in_w, in_h, spr_x, spr_y, spr_w, spr_h))
        {
            res = i;
            break;
        }
    }
    return res;
}

/* 0xFC00, 0x2000 usages? macro? */
/* 1F1B4 801439B4 -O2 -msoft-float */
s16 COLL_RAY_PIC(void)
{
    s32 ray_dist;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;
    s16 res = false;

    if ((ray.y_pos + ray.offset_by) < (mp.height * 16))
    {
        ray_dist = ray.ray_dist;
        if (ray.field20_0x36 == -1)
            res = (mp.map[ray_dist] & 0xFC00) == 0x2000;
        if (!res)
        {
            unk_1 = ray_dist - mp.width;
            res = (mp.map[unk_1] & 0xFC00) == 0x2000;
            if (!res)
            {
                unk_2 = unk_1 + 1;
                unk_3 = unk_1 - 1;
                if (ray.main_etat != 2 || ray.speed_x != 0)
                {
                    res = false;
                    if (
                        (mp.map[unk_3] & 0xFC00) == 0x2000 ||
                        (mp.map[unk_2] & 0xFC00) == 0x2000
                    )
                        res = true;                        
                }

                if (
                    !res && !(RayEvts.flags1 & FLG(RAYEVTS1_DEMI)) &&
                    !(ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40)
                )
                {
                    unk_4 = unk_1 - mp.width;
                    unk_5 = unk_4 - mp.width;
                    while (unk_5 < 0)
                        unk_5 += mp.width;
                    while (unk_4 < 0)
                        unk_4 += mp.width;
                    res = false;
                    if (
                        (mp.map[unk_5] & 0xFC00) == 0x2000 ||
                        (mp.map[unk_4] & 0xFC00) == 0x2000
                    )
                        res = true;
                }
            }
        }
    }
    return res;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_RAY_BLK_MORTEL);

INCLUDE_ASM("asm/nonmatchings/collision/collision", RAY_KO);

INCLUDE_ASM("asm/nonmatchings/collision/collision", RAY_HIT); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", standard_frontZone);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_DETECT_ZONE_FLAG); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", goToRay);

INCLUDE_ASM("asm/nonmatchings/collision/collision", unleashMonsterHost);

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLL_RAY_CYMBALE); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DoAudioStartRaymanCollision);

INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_DoRaymanCollision); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLLISIONS); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_OBJ_COLLISIONS); /**/
