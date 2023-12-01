#include "collision/collision.h"

/* 10000 (dist) could be a #define */

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

/* 1F3D0 80143BD0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_RAY_BLK_MORTEL);
#else
void COLL_RAY_BLK_MORTEL(void)
{
  u16 mp_map;
  
  if ((ray.y_pos + ray.offset_by) < (mp.height * 16))
  {
    mp_map = mp.map[ray.ray_dist] & 0xfc00;
    if (mp_map == 0x6000) {
      set_main_and_sub_etat(&ray, 3, 32);
      dead_time = 1;
      ray.speed_y = 0;
      ray.speed_x = 0;
      ray.y_pos += 5;
      stop_all_snd();
    }
    else if (ray.btypes[3] == BTYP_SPIKES) {
      set_main_and_sub_etat(&ray, 3, 32);
      dead_time = 1;
      ray.speed_y = 0;
      ray.speed_x = 0;
      stop_all_snd();
    }
    else if (mp_map == 0x6400) {
      set_main_and_sub_etat(&ray, 2, 31);
      scroll_end_y = ymap;
      scroll_start_y = ymap;
    }
    else if (
        RayEvts.flags1 & FLG(RAYEVTS1_UNUSED_DEATH) &&
        block_flags[mp.map[ray.ray_dist] >> 10] >> BLOCK_SOLID & 1 &&
        !(ray.main_etat == 3 && ray.sub_etat == 38)
    )
    {
      set_main_and_sub_etat(&ray, 3, 38);
      dead_time = 1;
      ray.speed_y = 0;
      ray.speed_x = 0;
    }
  }

  __asm__("nop");
}
#endif

/* 1F5B0 80143DB0 -O2 -msoft-float */
void RAY_KO(void)
{
  set_main_and_sub_etat(&ray, 3, 0);
  ray.speed_y = 0;
  ray.speed_x = 0;
  ray.field56_0x69 = 0;
}

/* 1F5F4 80143DF4 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", RAY_HIT);
#else
void RAY_HIT(u8 hurt, Obj *obj)
{
  u16 ray_x_pos;
  s16 ray_offset_bx;
  u8 typ_trav;
  ObjType obj_type;
  s16 eject_sens;
  s32 diff_spd_x;
  s16 new_speed;

  if (hurt)
  {
    RAY_HURT();
    ray_x_pos = ray.x_pos;
    ray_offset_bx = ray.offset_bx;
    /* not sure how to change into cast... */
    while ((s16) PS1_BTYPAbsPos((ray_offset_bx + ray_x_pos) << 0x10 >> 0x10, ray.y_pos + ray.offset_by) == BTYP_WATER)
      ray.y_pos--;
    ray.btypes[0] = BTYP_NONE;
  }

  if (ray.main_etat == 6)
  {
    set_main_and_sub_etat(&ray, 6, 8);
    ray.speed_x = 0;
    ray.speed_y = 0;
    poing.is_charging = false;
  }
  else if (
    ray.flags & FLG(OBJ_ALIVE) &&
    !(ray.main_etat == 3 && (ray.sub_etat == 22 || ray.sub_etat == 32 || ray.sub_etat == 38)) &&
    !(ray.main_etat == 2 && ray.sub_etat == 31)
  )
  {
    if (
      ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40 &&
      (typ_trav = calc_typ_trav(&ray, 2), block_flags[typ_trav] >> BLOCK_FLAG_4 & 1)
    )
      set_main_and_sub_etat(&ray, 0, 61);
    else
      set_main_and_sub_etat(&ray, 2, 8);
    
    ray_speed_inv = 0;
    if (!obj && !(ray.main_etat == 0 && ray.sub_etat == 61))
    {
      if (ray.flags & FLG(OBJ_FLIP_X))
        ray.speed_x = -2;
      else
        ray.speed_x = 2;
      ray.speed_y = -3;
    }
    else if (!(ray.main_etat == 0 && ray.sub_etat == 61))
    {
      obj_type = obj->type;
      if (obj_type == TYPE_SAXO2)
        eject_sens = saxo2_get_eject_sens();
      else if (obj_type == TYPE_SCORPION)
        eject_sens = sko_get_eject_sens();
      else if (obj_type == TYPE_BB12)
        eject_sens = 1;
      else if (obj_type == TYPE_BB13)
        eject_sens = -1;
      else if (obj_type == TYPE_MITE)
      {
        if (obj->flags & FLG(OBJ_FLIP_X))
          eject_sens = 1;
        else
          eject_sens = -1;
      }
      else if (obj_type == TYPE_BATTEUR_FOU)
        eject_sens = bat_get_eject_sens(obj);
      else if (obj_type == TYPE_MAMA_PIRATE)
        eject_sens = pma_get_eject_sens(obj);
      else if (obj_type == TYPE_FIRE_LEFT)
        eject_sens = 1;
      else if (obj_type == TYPE_FIRE_RIGHT)
        eject_sens = -1;
      else
      {
        diff_spd_x = obj->speed_x - ray.speed_x;
        if (diff_spd_x >= 0)
          eject_sens = diff_spd_x > 0;
        else
          eject_sens = -1;
        if (eject_sens == 0)
        {
          if (ray.flags & FLG(OBJ_FLIP_X))
            eject_sens = -1;
          else
            eject_sens = 1;
        }
      }

      if (flags[obj->type].flags1 >> OBJ1_BIG_RAY_HIT_KNOCKBACK & 1)
        new_speed = 5;
      else if (obj->type == TYPE_SAXO2)
        new_speed = 4;
      else
        new_speed = 2;

      if (eject_sens == 1)
        ray.speed_x = new_speed;
      else if (eject_sens == -1)
        ray.speed_x = -new_speed;
      ray.speed_y = ~new_speed;
    }

    in_air_because_hit = true;
    jump_time = 0;
    helico_time = -1;
    ray.gravity_value_1 = 0;
    ray.gravity_value_2 = 0;
    ray.field20_0x36 = -1;
    poing.is_charging = false;
    decalage_en_cours = 0;
    ray.nb_cmd = 0;
    if (RayEvts.flags0 & FLG(RAYEVTS0_SUPER_HELICO))
      button_released = 1;
    Reset_air_speed(false);
  }

  __asm__("nop\nnop");
}
#endif

/* 1FA54 80144254 -O2 -msoft-float */
void standard_frontZone(Obj *obj, s16 *x, s16 *w)
{
  if (!(obj->flags & FLG(OBJ_FLIP_X)))
    *x -= obj->detect_zone;
  else
    *x += (*w >> 1);
  *w = obj->detect_zone + (*w >> 1);
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_DETECT_ZONE_FLAG);

INCLUDE_ASM("asm/nonmatchings/collision/collision", goToRay);

/* 20304 80144B04 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", unleashMonsterHost);
#else
void unleashMonsterHost(Obj *in_obj)
{
    Obj *linked_obj;
    s16 prev_id;
    s16 linked_id = in_obj->field24_0x3e;

    if (linked_id != in_obj->id)
    {
        do
        {
            linked_obj = &level.objects[linked_id];
            if (!((flags[linked_obj->type].flags1 >> OBJ1_BONUS & 1) && ((u8) bonus_taken(linked_obj->id))))
            {
                obj_init(linked_obj);
                linked_obj->flags |= FLG(OBJ_ALIVE);
                make_active(linked_obj, true);
                goToRay(linked_obj);
            }
            prev_id = linked_id;
            linked_id = link_init[linked_obj->id];
            suppressFromLinkList(linked_obj);
        } while (prev_id != linked_id);
    }

    __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLL_RAY_CYMBALE);

/* 2081C 8014501C -O2 -msoft-float */
void DoAudioStartRaymanCollision(Obj *obj)
{
  manage_snd_event(obj);
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_DoRaymanCollision);

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLLISIONS);
#else
void DO_COLLISIONS(void)
{
    s16 i;
    Obj *cur_obj;
    Obj *poing_obj;
    ObjType obj_type;
    s16 ray_collided;

    if (ray.field56_0x69 != 0)
        RAY_KO();
    else if (ray.iframes_timer == -1 && ray.eta[ray.main_etat][ray.sub_etat].flags & 8)
    {
        i = 0;
        cur_obj = &level.objects[actobj.objects[i]];
        while (i < actobj.num_active_objects)
        {
            if (new_world || new_level || fin_boss)
                break;
            
            obj_type = cur_obj->type;
            if (
                !(flags[obj_type].flags0 >> OBJ0_NO_COLLISION & 1) &&
                cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x20
            )
            {
                if (!((flags[obj_type].flags2 >> OBJ2_DO_NOT_CHECK_RAY_COLLISION) & 1))
                {
                    ray_collided = CHECK_BOX_COLLISION(TYPE_RAYMAN, ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h, cur_obj);
                    obj_type = cur_obj->type; /* ??? */
                    if (
                        (obj_type == TYPE_RAYON && (cur_obj->anim_frame > 3 || cur_obj->anim_frame == 0)) ||
                        (cur_obj->type == TYPE_MST_SCROLL && cur_obj->hit_points != 0)
                    )
                        ray_collided = -1;
                    
                    if (ray_collided != -1)
                    {
                        switch (cur_obj->type)
                        {
                        case TYPE_DARK2_PINK_FLY:
                            ToonDonnePoing(cur_obj);
                            break;
                        case TYPE_ANNULE_SORT_DARK:
                            if (
                                RayEvts.flags1 & (FLG(RAYEVTS1_DEMI)|FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|
                                                FLG(RAYEVTS1_FORCE_RUN)|FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6))
                            )
                            {
                                DO_NOVA(&ray);
                                if (RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN)))
                                    RayEvts.flags1 |= FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN);
                                if (RayEvts.flags1 & (FLG(RAYEVTS1_REVERSE)|FLG(RAYEVTS1_FLAG6)))
                                    RAY_REVERSE_COMMANDS();
                                if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
                                    RAY_DEMIRAY();
                                cur_obj->flags &= ~FLG(OBJ_ALIVE);
                                cur_obj->flags &= ~FLG(OBJ_ACTIVE);
                            }
                            break;
                        case TYPE_HYB_BBF2_LAS:
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
                            break;
                        case TYPE_BLACK_RAY:
                        case TYPE_BLACK_FIST:
                            if (ray_stack_is_full == true)
                                ray.hit_points = 0;
                            break;
                        case TYPE_TNT_BOMB:
                        case TYPE_PIRATE_BOMB:
                            BombExplosion(cur_obj);
                            break;
                        case TYPE_CYMBAL2:
                        case TYPE_CYMBALE:
                            DO_COLL_RAY_CYMBALE(cur_obj);
                            break;
                        case TYPE_GRAP_BONUS:
                            DO_NOVA(cur_obj);
                            RayEvts.flags0 |= FLG(RAYEVTS0_GRAP);
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            break;
                        case TYPE_POING_POWERUP:
                            poing_obj = &level.objects[poing_obj_id];
                            if (cur_obj->sub_etat == 7)
                            {
                                if (!(RayEvts.flags0 & FLG(RAYEVTS0_POING)))
                                    poing_obj->init_sub_etat = 8;
                                else
                                {
                                    switch(poing_obj->init_sub_etat)
                                    {
                                    case 1:
                                        poing_obj->init_sub_etat = 8;
                                        break;
                                    case 3:
                                        poing_obj->init_sub_etat = 10;
                                        break;
                                    case 5:
                                        poing_obj->init_sub_etat = 12;
                                        break;
                                    }
                                }
                            }
                            else if (cur_obj->sub_etat == 14)
                            {
                                if (RayEvts.flags0 & FLG(RAYEVTS0_POING))
                                {
                                    switch (poing_obj->init_sub_etat)
                                    {
                                    case 1:
                                        poing_obj->init_sub_etat = 3;
                                        break;
                                    case 3:
                                        poing_obj->init_sub_etat = 5;
                                        break;
                                    case 5:
                                        poing_obj->init_sub_etat = 5;
                                        break;
                                    case 8:
                                        poing_obj->init_sub_etat = 10;
                                        break;
                                    case 10:
                                    case 12:
                                        poing_obj->init_sub_etat = 12;
                                        break;
                                    }
                                }
                                else
                                    poing_obj->init_sub_etat = 1;
                            }
                            DO_NOVA(cur_obj);
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            RayEvts.flags0 |= FLG(RAYEVTS0_POING);
                            poing_obj->sub_etat = poing_obj->init_sub_etat;
                            poing.sub_etat = poing_obj->init_sub_etat;
                            PlaySnd(11, cur_obj->id);
                            break;
                        case TYPE_POWERUP:
                            DO_NOVA(cur_obj);
                            ray.hit_points += cur_obj->hit_points;
                            if (ray.hit_points > status_bar.max_hp)
                                ray.hit_points = status_bar.max_hp;
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            PlaySnd(8, cur_obj->id);
                            break;
                        case TYPE_ONEUP:
                            DO_NOVA(cur_obj);
                            PlaySnd(194, cur_obj->id);
                            id_Cling_1up = NOVA_STATUS_BAR();
                            if (id_Cling_1up == -1)
                                Add_One_RAY_lives();
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            take_bonus(cur_obj->id);
                            break;
                        case TYPE_SUPERHELICO:
                            PlaySnd(213, cur_obj->id);
                            DO_NOVA(cur_obj);
                            RayEvts.flags0 |= FLG(RAYEVTS0_SUPER_HELICO);
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            break;
                        case TYPE_GRAINE:
                            RayEvts.flags0 |= FLG(RAYEVTS0_GRAIN);
                            cur_obj->flags &= ~FLG(OBJ_ALIVE);
                            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
                            PlaySnd(10, cur_obj->id);
                            break;
                        case TYPE_DARK_SORT:
                            DO_DARK_SORT_COLLISION(cur_obj);
                            break;
                        }

                        if (
                            flags[cur_obj->type].flags0 >> OBJ0_HIT_RAY & 1 &&
                            ray.iframes_timer == -1 &&
                            !(ray.main_etat == 3 && ray.sub_etat == 32) &&
                            !(RayEvts.flags1 & FLG(RAYEVTS1_UNUSED_DEATH))
                        )
                        {
                            RAY_HIT(true, cur_obj);
                            break;
                        }
                    }
                }
            }
            i++;
            cur_obj = &level.objects[actobj.objects[i]];
        }
    }
    else if (ray.iframes_timer >= 0)
        ray.iframes_timer--;
    PS1_DoRaymanCollision();

    __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_OBJ_COLLISIONS);
#else
void DO_OBJ_COLLISIONS(Obj *in_obj, s32 offs)
{
  s16 in_x; s16 in_y; s16 in_w; s16 in_h;
  u8 done;
  s16 i;
  Obj *cur_obj;
  s16 cur_x; s16 cur_y; s16 cur_w; s16 cur_h;
  
  GET_ANIM_POS(in_obj, &in_x, &in_y, &in_w, &in_h);
  done = false;
  if (in_obj->type == TYPE_FALLING_OBJ || in_obj->type == TYPE_FALLING_OBJ2 || in_obj->type == TYPE_FALLING_OBJ3)
  {
    in_x += 10;
    in_y += 20;
    in_w += -20;
    in_h += -25;
  }
  else
  {
    in_x = offs + in_x;
    in_y = offs + in_y;
    in_w -= offs * 2;
    in_h -= offs * 2;
  }
  i = 0;
  cur_obj = &level.objects[actobj.objects[i]];
  if (i < actobj.num_active_objects)
  {
    do {
      if (in_obj != cur_obj)
      {
        switch(cur_obj->type)
        {
        case TYPE_BADGUY1:
          if (
            !(cur_obj->main_etat == 2 || (cur_obj->main_etat == 0 && cur_obj->sub_etat == 3)) &&
            (
              !(cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x40) &&
              GET_SPRITE_POS(cur_obj, cur_obj->follow_sprite, &cur_x, &cur_y, &cur_w, &cur_h) &&
              (s16) inter_box(cur_x, cur_y, cur_w, cur_h, in_x, in_y, in_w, in_h)
            )
          )
          {
            set_main_and_sub_etat(cur_obj, 0, 4);
            cur_obj->follow_sprite = 4;
            cur_obj->follow_y = 0;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->offset_hy = 11;
            cur_obj->flags |= FLG(OBJ_FOLLOW_ENABLED);
            if (ray.field20_0x36 == in_obj->id)
              RAY_TOMBE();
            if (cur_obj->cmd == GO_WAIT)
            {
              if ((cur_obj->flags & FLG(OBJ_FLIP_X)))
                skipToLabel(cur_obj, 3, true);
              else
                skipToLabel(cur_obj, 2, true);
            }
            set_sub_etat(in_obj, 9);
            in_obj->flags &= ~FLG(OBJ_ACTIVE);
            done = true;
          }
          break;
        case TYPE_BOUEE_JOE:
          if (
            GET_SPRITE_POS(cur_obj, cur_obj->follow_sprite, &cur_x, &cur_y, &cur_w, &cur_h) &&
            in_obj->type == TYPE_POI2 &&
            (s16) inter_box(cur_x, cur_y, cur_w, cur_h, in_x, in_y, in_w, in_h) &&
            !(cur_obj->main_etat == 2 && cur_obj->sub_etat == 6)
          )
          {
            if (
              in_obj->flags & FLG(OBJ_FLIP_X) &&
              (cur_obj->x_pos + cur_obj->offset_bx) - in_obj->x_pos - in_obj->offset_bx > -1
            )
            {
              cur_obj->field56_0x69 = 1;
              skipToLabel(in_obj, 3, true);
              cur_obj->speed_x = 8;
            }
            if (
              !(in_obj->flags & FLG(OBJ_FLIP_X)) &&
              (cur_obj->x_pos + cur_obj->offset_bx) - in_obj->x_pos - in_obj->offset_bx < 0
            )
            {
              cur_obj->field56_0x69 = 1;
              skipToLabel(in_obj, 4, true);
              cur_obj->speed_x = -8;
            }
          }
          break;
        }

        if (done)
          break;
      }
      i++;
      cur_obj = &level.objects[actobj.objects[i]];
    } while (i < actobj.num_active_objects);
  }

  __asm__("nop");
}
#endif