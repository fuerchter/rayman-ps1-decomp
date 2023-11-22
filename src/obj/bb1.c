#include "obj/bb1.h"

/* TODO: check rodata padding once everything is matching */

/* 5783C 8017C03C -O2 -msoft-float */
/*? set_sub_etat(Obj *, ?);*/

void DO_TOTEM_TOUCHE(Obj *obj, s16 sprite)
{
    s16 x_pos;

    if (sprite == 6 && obj->field23_0x3c == 0)
    {
        if (level.objects[poing_obj_id].speed_x > 0)
        {
            set_sub_etat(obj, 4);
            x_pos = obj->init_x_pos + 71;
        }
        else
        {
            set_sub_etat(obj, 5);
            x_pos = obj->init_x_pos - 85;
        }
        obj->x_pos = x_pos;
        obj->iframes_timer = 0;
        obj->field23_0x3c = 0x00FF;
        obj->anim_frame = 0xFF;
    }
    else if (sprite >= 2)
    {
        if (level.objects[poing_obj_id].speed_x > 0)
            set_sub_etat(obj, 7);
        else
            set_sub_etat(obj, 6);
    }
}

/* 57950 8017C150 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_TOTEM_COMMAND);
#else
void DO_TOTEM_COMMAND(Obj *tot_obj)
{
    s16 x; s16 y; s16 w; s16 h;
    u8 nb_objs;
    s16 i;
    s16 j;
    Obj *cur_obj;
    s16 new_spd_x;
    u8 unk_1;
    s16 new_x;

    tot_obj->field23_0x3c--;
    if (tot_obj->field23_0x3c < 0)
        tot_obj->field23_0x3c = 0;
    if (bb1.field2_0x4 == 3)
    {
        tot_obj->flags &= ~FLG(OBJ_ACTIVE);
        tot_obj->flags &= ~FLG(OBJ_ALIVE);
        nb_objs = level.nb_objects;
        i = 0;
        cur_obj = level.objects;
        if (nb_objs != 0)
        {
            do
            {
                if (cur_obj->type == TYPE_BOUT_TOTEM)
                {
                    
                    for (j = 0; j < 6; cur_obj++, j++)
                    {
                        GET_SPRITE_POS(tot_obj, j, &x, &y, &w, &h);
                        cur_obj->x_pos = x;
                        cur_obj->y_pos = y;
                        cur_obj->flags |= FLG(OBJ_ACTIVE)|FLG(OBJ_ALIVE);
                        if (j == 0)
                        {
                            cur_obj->speed_x = 0;
                            cur_obj->speed_y = 0;
                        }
                        else
                        {
                            new_spd_x = 2 - myRand(4);
                            cur_obj->speed_x = new_spd_x;
                            if (new_spd_x == 0)
                                cur_obj->speed_x = 1;
                            cur_obj->speed_y = -4 - myRand(3);
                        }
                        cur_obj->gravity_value_1 = 0;
                        cur_obj->gravity_value_2 = 5;
                        switch (j)
                        {
                        case 1:
                            set_main_and_sub_etat(cur_obj, 2, 8);
                            cur_obj->offset_by = 43;
                            cur_obj->offset_bx = 25;
                            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                            cur_obj->anim_index = 31;
                            break;
                        case 2:
                            set_main_and_sub_etat(cur_obj, 2, 10);
                            cur_obj->offset_by = 17;
                            cur_obj->offset_bx = 12;
                            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                            cur_obj->anim_index = 33;
                            break;
                        case 3:
                            set_main_and_sub_etat(cur_obj, 2, 11);
                            cur_obj->offset_by = 7;
                            cur_obj->offset_bx = 7;
                            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                            cur_obj->anim_index = 34;
                            break;
                        case 4:
                            set_main_and_sub_etat(cur_obj, 2, 9);
                            cur_obj->offset_by = 28;
                            cur_obj->offset_bx = 17;
                            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                            cur_obj->anim_index = 32;
                            break;
                        case 5:
                            set_main_and_sub_etat(cur_obj, 2, 10);
                            cur_obj->offset_by = 17;
                            cur_obj->offset_bx = 12;
                            cur_obj->flags = (cur_obj->flags | FLG(OBJ_FLIP_X));
                            cur_obj->anim_index = 33;
                            break;
                        case 0:
                            set_main_and_sub_etat(cur_obj, 0, 21);
                            cur_obj->flags &= ~FLG(OBJ_FLIP_X);
                            cur_obj->anim_index = 37;
                            break;
                        }
                    }
                    break;
                }
                i++;
                cur_obj++;
            } while(i < nb_objs);
            
        }
    }
    else if (!(tot_obj->sub_etat == 6 || tot_obj->sub_etat == 7 || tot_obj->sub_etat == 3))
    {
        GET_SPRITE_POS(tot_obj, 6, &x, &y, &w, &h);
        x += 5; y += 5; w -= 10; h -= 10;
        if ((s16) inter_box(x, y, w, h, bb1.sprite6_x, bb1.sprite6_y, 32, 32) && bb1.field2_0x4 == 0)
        {

            bb1.field2_0x4 = 1;
            tot_obj->iframes_timer = 4;
            IndSerie++;
            if (IndSerie > 5)
                IndSerie--;
            IndAtak = 0;
        }
        
        if (tot_obj->anim_frame == (tot_obj->animations[tot_obj->anim_index].frames_count - 1))
            unk_1 = horloge[tot_obj->eta[tot_obj->main_etat][tot_obj->sub_etat].anim_speed & 0xf] == 0;
        else
            unk_1 = false;
        
        switch (tot_obj->sub_etat)
        {
        case 3:
        case 6:
        case 7:
            break;
        case 4:
            if (unk_1)
            {
                if (++tot_obj->iframes_timer < 4)
                {
                    set_sub_etat(tot_obj, 5);
                    new_x = tot_obj->init_x_pos - 85;
                }
                else
                {
                    set_sub_etat(tot_obj, 6);
                    new_x = tot_obj->init_x_pos;
                }
                tot_obj->x_pos = new_x;
            }
            break;
        case 5:
            if (unk_1)
            {
                if (++tot_obj->iframes_timer < 4)
                {
                    set_sub_etat(tot_obj, 4);
                    new_x = tot_obj->init_x_pos + 71;
                }
                else
                {
                    set_sub_etat(tot_obj, 7);
                    new_x = tot_obj->init_x_pos;
                }
                tot_obj->x_pos = new_x;
            }
            break;
        }
    }

    __asm__("nop\nnop\nnop");
}
#endif

/* 57EC4 8017C6C4 -O2 -msoft-float */
void DO_TOTBT_REBOND(Obj *obj)
{
    if (obj->speed_y > 0 && obj->y_pos + obj->offset_by >= 265)
    {
        obj->speed_x /= 2;
        obj->speed_y = -obj->speed_y / 2;
        if (obj->speed_y == 0)
            obj->gravity_value_2 = 0xFF;
        obj->gravity_value_1 = 5 - obj->gravity_value_1;
    }
}

/* 57F48 8017C748 -O2 -msoft-float */
/*? PlaySnd_old(?);
? allocateExplosion(Obj *);
? allocateStoneChips(Obj *);*/

void DO_PI_EXPLOSION2(Obj *obj)
{
    PlaySnd_old(0x54);
    obj->speed_x = -1;
    obj->x_pos += 20;
    allocateStoneChips(obj);
    obj->speed_x = 1;
    obj->x_pos -= 40;
    allocateStoneChips(obj);
    obj->x_pos += 20;
    allocateExplosion(obj);
}

/* 57FBC 8017C7BC -O2 -msoft-float */
/*? PlaySnd(?, s16);
? recale_position(Obj *);
? set_main_and_sub_etat(s16 *, ?, ?);*/

void DO_BBL_REBOND(Obj *obj)
{
    s32 x_pos;
    s16 x_pierre;

    PlaySnd(0xC8, obj->id);
    switch (obj->field23_0x3c)
    {
    case 0:
        obj->speed_y = -5;
        obj->gravity_value_1 = 3 - obj->gravity_value_1;
        break;
    case 2:
        obj->speed_y = -5;
        obj->gravity_value_1 = 3 - obj->gravity_value_1;
        x_pos = obj->x_pos;
        if (obj->flags & FLG(OBJ_FLIP_X))
            x_pierre = x_pos - 130;
        else
            x_pierre = x_pos + 25;
        PosPierre = x_pierre;
        break;
    case 4:
        DO_PI_EXPLOSION2(obj);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
        if (ray.field20_0x36 == obj->id)
        {
            ray.field20_0x36 = -1;
            obj->ray_dist = 1000;
            set_main_and_sub_etat(&ray, 2, 2);
        }
        PS1_AlwaysObjectsCount -= 1;
        break;
    }
    recale_position(obj);
}

/* 580F8 8017C8F8 -O2 -msoft-float */
void allocateDog(Obj *bb1_obj)
{
    s16 new_x;
    s16 nb_objs = level.nb_objects;
    Obj *cur = level.objects;
    s16 i = 0;

    if (nb_objs != 0)
    {
        do
        {
            if (cur->type == TYPE_STONEDOG2 && !(cur->flags & FLG(OBJ_ACTIVE)))
            {
                if (!((((bb1_obj->flags >> OBJ_FLIP_X) & 1) + YaDesChiens) & 1))
                {
                    new_x = -20;
                    cur->flags |= FLG(OBJ_FLIP_X);
                }
                else
                {
                    new_x = 260;
                    cur->flags &= ~FLG(OBJ_FLIP_X);
                }
                obj_init(cur);
                cur->cmd_offset = -1;
                cur->x_pos = new_x;
                cur->y_pos = bb1_obj->y_pos - 20;
                cur->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
                cur->speed_x = 0;
                cur->speed_y = 0;
                cur->main_etat = 2;
                cur->flags = cur->flags & ~FLG(OBJ_FLAG_9);
                cur->sub_etat = 2;
                if (cur->flags & FLG(OBJ_FLIP_X))
                    skipToLabel(cur, 1, 1);
                else
                    skipToLabel(cur, 0, 1);
                calc_obj_pos(cur);
                if (niveau == 0)
                    cur->hit_points = 1;
                break;
            }
            cur++;
            i++;
        } while (i < nb_objs);
    }
}

/* 58278 8017CA78 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", allocateTir);
#else
void allocateTir(Obj *bb1_obj, s16 param_2)
{
  s32 sprite_ind;
  s16 x; s16 y; s16 w; s16 h;
  s32 new_x_1;
  s32 bb1_x;
  s32 new_spd_x;
  s32 new_x_2;
  u8 nb_objs = level.nb_objects;
  s16 i = 0;
  Obj *cur_obj = level.objects;

  if (nb_objs != 0)
  {
    do {
      if (cur_obj->type == TYPE_BBL && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
      {
        if (param_2 != 0)
          sprite_ind = 8;
        else
          sprite_ind = 9;
        cur_obj->flags &= ~FLG(OBJ_FLIP_X);
        GET_SPRITE_POS(bb1_obj, sprite_ind, &x, &y, &w, &h);
        if (param_2 == 1)
        {
          new_x_1 = x - cur_obj->offset_bx + (w >> 1);
          if (bb1_obj->flags & FLG(OBJ_FLIP_X))
            new_x_1 += 64;
          else
            new_x_1 -= 64;
          cur_obj->x_pos = new_x_1;
          cur_obj->y_pos = y - 40;
          if (bb1_obj->flags & FLG(OBJ_FLIP_X))
            new_spd_x = 12;
          else
            new_spd_x = -12;
          cur_obj->speed_x = new_spd_x;
          cur_obj->speed_y = 0;
          cur_obj->flags = cur_obj->flags & ~FLG(OBJ_FLIP_X) | bb1_obj->flags & FLG(OBJ_FLIP_X);
        }
        else if (param_2 == 0)
        {
          new_x_1 = (x - cur_obj->offset_bx) + (w >> 1);
          if (bb1_obj->flags & FLG(OBJ_FLIP_X))
            new_x_1 += 9;
          else
            new_x_1 -= 9;
          cur_obj->x_pos = new_x_1;
          cur_obj->y_pos = y - 40;
          if (bb1_obj->flags & FLG(OBJ_FLIP_X))
            new_spd_x = 2;
          else
            new_spd_x = -2;
          cur_obj->speed_x = new_spd_x;
          cur_obj->speed_y = -5;
          cur_obj->flags = cur_obj->flags & ~FLG(OBJ_FLIP_X) | bb1_obj->flags & FLG(OBJ_FLIP_X);
        }
        else
        {
          if (param_2 == 3)
          {
            bb1_x = bb1_obj->x_pos;
            if (!(bb1_obj->flags & FLG(OBJ_FLIP_X)))
                cur_obj->x_pos = bb1_x - 36;
            else
                cur_obj->x_pos = bb1_x + 120;
            cur_obj->y_pos = bb1_obj->y_pos - 185;
            cur_obj->speed_y = 4;  
          }
          else
          {
            if (param_2 < 10)
            {
              cur_obj->x_pos = ray.x_pos;
              if (cur_obj->x_pos < 40)
                cur_obj->x_pos = 40;
              if (cur_obj->x_pos > 200)
                cur_obj->x_pos = 200;              
            }
            else
            {
              if (bb1_obj->flags & FLG(OBJ_FLIP_X))
                new_x_2 = 240 - bb1.field8_0xe * 50;
              else {
                new_x_2 = bb1.field8_0xe * 50 - 20;
              }
              cur_obj->x_pos = new_x_2;
            }
            cur_obj->y_pos = bb1_obj->y_pos - 200;
            cur_obj->speed_y = 0;
          }
          cur_obj->speed_x = 0;
        }
        cur_obj->iframes_timer = 38;
        if (param_2 != 3)
          cur_obj->gravity_value_2 = 10;
        else
          cur_obj->gravity_value_2 = 7;

        if (param_2 == 0)
          cur_obj->gravity_value_2 = 3;
        cur_obj->main_etat = 2;
        cur_obj->sub_etat = 6;
        skipToLabel(cur_obj, 1, true);
        calc_obj_pos(cur_obj);
        cur_obj->gravity_value_1 = 0;
        cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        if (param_2 < 10)
          cur_obj->field23_0x3c = param_2;
        else
          cur_obj->field23_0x3c = 4;
        if (param_2 != 3) {
          PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = cur_obj->id;
          PS1_AlwaysObjectsCount++;
        }
        break;
      }
      cur_obj++;
      i++;
    } while (i < nb_objs);
  }

  __asm__("nop");
}
#endif

/* 58644 8017CE44 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", CreateFirstBBL);
#else
void CreateFirstBBL(void)
{
  Obj *obj;
  s16 i;
  u8 nb_objs;
  
  obj = level.objects;
  i = 0;
  nb_objs = level.nb_objects;
  if (nb_objs != 0) {
    do {
      if (obj->type == TYPE_BBL && !(obj->flags & FLG(OBJ_ACTIVE))) {
        obj->x_pos = -40;
        PosPierre = -15;
        obj->y_pos = 160;
        obj->speed_x = 0;
        obj->speed_y = 0;
        obj->iframes_timer = 38;
        obj->gravity_value_2 = 3;
        obj->main_etat = 2;
        obj->sub_etat = 6;
        obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
        skipToLabel(obj, 1, true);
        calc_obj_pos(obj);
        obj->gravity_value_1 = 0;
        obj->field23_0x3c = 2;
        obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = obj->id;
        PS1_AlwaysObjectsCount++;
        break;
      }
      obj++;
      i++;
    } while (nb_objs > i);
  }

  __asm__("nop");
}
#endif

/* 58784 8017CF84 -O2 -msoft-float */
void INIT_BBMONT(Obj *obj)
{
  calc_obj_pos(obj);
  obj->field23_0x3c = 0;
  obj->gravity_value_2 = 10;
  Phase = 0;
  WaitForAnim = false;
  WaitForFinAtan = 10;
  PosPierre = 9999;
  PierreDoitExploser = 0;
  IndSerie = 0;
  IndAtak = 0;
  RMrepere = 0;
  YaDesChiens = 0;
  screen_trembling2 = 0;
  obj->flags |= FLG(OBJ_ALIVE);
  obj->flags &= ~FLG(OBJ_ACTIVE);
  bb1.field1_0x2 = -1;
  bb1.speed_x = 0;
  bb1.saved_cmd = 0;
  bb1.field2_0x4 = 0;
  bb1.field8_0xe = 1;
}

/* 5884C 8017D04C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBL_COMMAND);
#else
void DO_BBL_COMMAND(Obj *obj)
{
    s16 new_spd_x;
    s32 spd_x_abs;
    s32 spd_x;
    s32 bb1_x;
    s16 unk_x;

    if (PierreDoitExploser)
    {
        DO_PI_EXPLOSION2(obj);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
        if (ray.field20_0x36 == obj->id)
        {
            ray.field20_0x36 = -1;
            obj->ray_dist = 1000;
            set_main_and_sub_etat(&ray, 2, 2);
        }
        PierreDoitExploser = false;
        PosPierre = 9999;
        PS1_AlwaysObjectsCount--;
    }

    if (obj->field23_0x3c == 3 && --obj->iframes_timer == 0)
    {
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
    }

    if (obj->speed_x < 0)
        unk_x = -20;
    else
        unk_x = 20;

    if (
        block_flags [
            (u16) mp.map [
                (s16) (((obj->x_pos + obj->offset_bx + unk_x) >> 4) + mp.width * ((obj->y_pos + 40) >> 4))
            ] >> 10
        ] >> BLOCK_FLAG_4 & 1
    )
    {
        switch(obj->field23_0x3c)
        {
        case 1:
            PlaySnd(200, obj->id);
            spd_x = obj->speed_x;
            spd_x_abs = __builtin_abs(spd_x);
            if (spd_x_abs == 12)
            {
                
                if (spd_x > 0)
                    new_spd_x = -13;
                else
                    new_spd_x = 13;
                obj->speed_x = new_spd_x;
                obj->speed_y = 0;
            }
            else if (spd_x_abs == 13)
            {
                if (spd_x > 0)
                    new_spd_x = -14;
                else
                    new_spd_x = 14;
                obj->speed_x = new_spd_x;
                obj->speed_y = 0;
            }
            else if (spd_x_abs == 14)
            {
                if (spd_x > 0)
                    new_spd_x = -15;
                else
                    new_spd_x = 15;
                obj->speed_x = new_spd_x;
                obj->speed_y = 0;
            }
            else if (spd_x_abs == 15)
            {
                DO_PI_EXPLOSION2(obj);
                obj->flags &= ~FLG(OBJ_ACTIVE);
                obj->flags &= ~FLG(OBJ_ALIVE);
                if (ray.field20_0x36 == obj->id)
                {
                    ray.field20_0x36 = -1;
                    obj->ray_dist = 1000;
                    set_main_and_sub_etat(&ray, 2, 2);
                }
                PS1_AlwaysObjectsCount--;
                return;
            }
            break;
        case 0:
            PlaySnd(200, obj->id);
            obj->speed_x = 0;
            obj->field23_0x3c = 2;
            break;
        }
    }

    __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ECLAIR);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ETINCELLES);

/* 58F14 8017D714 -O2 -msoft-float */
void BBMONT_TIRE(Obj *obj)
{
    allocateTir(obj, 1);
}

/* 58F34 8017D734 -O2 -msoft-float */
void Cree_BBL(Obj *obj)
{
    allocateTir(obj, 0);
}

/* 58F54 8017D754 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", BB_Attaque);
#else
void BB_Attaque(Obj *obj)
{
  switch(NextAtak)
  {
  case 0:
    set_main_and_sub_etat(obj, 0, 4);
    Phase = 1;
    break;
  case 1:
    set_main_and_sub_etat(obj, 0, 3);
    Phase = 2;
    break;
  case 2:
    set_main_and_sub_etat(obj, 0, 6);
    Phase = 3;
    break;
  case 3:
    set_main_and_sub_etat(obj, 0, 7);
    Phase = 4;
    break;
  case 4:
    set_main_and_sub_etat(obj, 0, 2);
    Phase = 5;
    break;
  case 5:
    set_main_and_sub_etat(obj, 0, 4);
    Phase = 12;
    break;
  case 6:
    set_main_and_sub_etat(obj, 2, 3);
    obj->iframes_timer = 35;
    Phase = 11;
    bb1.field8_0xe = 1;
    break;
  case 7:
    set_main_and_sub_etat(obj, 0, 22);
    Phase = 13;
  }

  __asm__("nop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/bb1", Fin_BB_Attaque);

/* 59198 8017D998 -O2 -msoft-float */
void BB_Atan(Obj *obj)
{
    if (WaitForFinAtan != 0)
    {
        set_main_and_sub_etat(obj, 0, 0);
        skipToLabel(obj, 0, 1);
        Phase = 6;
    }
    else
        Fin_BB_Attaque(obj);
}

/* 591FC 8017D9FC -O2 -msoft-float */
/*? allocateLandingSmoke(Obj *);
? recale_position();
? set_sub_etat(Obj *, ?);*/

void DO_BBMONT_ATTER(Obj *obj)
{
    obj->speed_y = 0;
    obj->speed_x = 0;
    recale_position(obj);
    set_sub_etat(obj, 6);
    allocateLandingSmoke(obj);
    screen_trembling3 = 1;
}

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_COMMAND);

/* 5A260 8017EA60 -O2 -msoft-float */
void DO_BBMONT_TOUCHE(Obj *obj)
{
  set_sub_etat(obj, 8);
  obj->anim_frame = 0;
  Phase = 7;
  WaitForFinAtan = 2;
}

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_COMMAND);

/* 5B388 8017FB88 -O2 -msoft-float */
void DO_BBMONT2_MARCHE(s16 hp)
{
    bb1.speed_x = hp;
}

/* 5B398 8017FB98 -O2 -msoft-float */
/*? recale_position();
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?);*/

void DO_BBMONT2_ATTER(Obj *obj)
{
    if (obj->speed_y >= 2)
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
        recale_position(obj);
        switch (Phase)
        {
        case 0:
            set_sub_etat(obj, 2);
            break;
        case 1:
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1, 1);
                break;
            case 3:
                set_main_and_sub_etat(obj, 1, 2);
                break;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1, 0);
                break;
            }
            Phase = 2;
            obj->speed_x = bb1.speed_x;
            break;
        case 2:
            set_sub_etat(obj, 2);
            Phase = 3;
            obj->x_pos -= 32;
            bb1.speed_x = -1;
            obj->field23_0x3c = 0;
            break;
        case 3:
            bb1.field1_0x2 += 1;
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_x = 2;
            set_sub_etat(obj, 2);
            obj->speed_x = 0;
            bb1.sprite6_y = 691;
            bb1.sprite6_x = 0;
            scroll_end_y = ymap;
            if (ymap < 691)
            {
                scroll_end_y = 691;
            }
            Phase = 4;
            obj->speed_y = 0;
            break;
        }
    }
}

/* 5B568 8017FD68 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT3_COMMAND);
#else 
/*? CALC_MOV_ON_BLOC(Obj *);
? SET_X_SPEED(Obj *);
? set_main_and_sub_etat(Obj *, ?, ?);
extern s32 D_801F4438;*/

void DO_BBMONT3_COMMAND(Obj *obj)
{
    u8 eight;
    __asm__("nop\nnop\nnop");
    if (
      obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1) &&
      horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
        FinAnim = true;
    else
        FinAnim = false;
    
    if (obj->main_etat == 1)
    {
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        if (FinAnim && (bb1.speed_x != obj->sub_etat + 1))
        {
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1, 1);
                break;
            case 3:
                set_main_and_sub_etat(obj, 1, 2);
                break;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1, 0);
                break;
            }
        }
    }
    switch (Phase)
    {
    case 0:
        obj->flags &= ~FLG(OBJ_FLIP_X);
        if (obj->main_etat != 2)
            CALC_MOV_ON_BLOC(obj);
        
        if (FinAnim && obj->main_etat == 0)
        {
            bb1.speed_x = 2;
            set_main_and_sub_etat(obj, 1, 1);
        }
        eight = 8;
        if (
          (obj->main_etat == 1) &&
          ((block_flags
            [
              *(u16 *)(
                (
                  (s16)(
                    ((obj->x_pos + (obj->offset_bx - eight)) >> 4) +
                    mp.width * ((obj->y_pos + obj->offset_by + eight) >> 4)
                  ) << 1
                ) + (s32)mp.map
              ) >> 10
            ] >> 1 & 1) == 0
          )
        )
        {
            set_main_and_sub_etat(obj, 2, 4);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = -8;
            obj->speed_x = -2;
        }
        break;
    case 1:
        if (
          (obj->main_etat == 1) &&
          ((block_flags
            [
              *(u16 *)(
                (
                  (s16)(
                    ((obj->x_pos + (obj->offset_bx)) >> 4) +
                    mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4)
                  ) << 1
                ) + (s32)mp.map
              ) >> 10
            ] >> 1 & 1) == 0
          )
        )
        {
            set_main_and_sub_etat(obj, 0, 1);
            obj->speed_y = 0;
            obj->speed_x = 0;
            Phase = 2;
        }
        break;
    }
}
#endif

/* 5B8C0 801800C0 -O2 -msoft-float */
/*? CALC_MOV_ON_BLOC();
? set_main_and_sub_etat(Obj *, ?, ?);*/

void DO_BBMONT3_ATTER(Obj *obj)
{
    if (obj->speed_y >= 2)
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
        CALC_MOV_ON_BLOC(obj);
        if (Phase == 0)
        {
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1, 1);
                break;
            case 3:
                set_main_and_sub_etat(obj, 1, 2);
                break;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1, 0);
                break;
            }
            Phase = 1;
        }
    }
}

/* 5B984 80180184 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT4_COMMAND);
#else
/*? set_sub_etat(Obj *, ?);*/

void DO_BBMONT4_COMMAND(Obj *obj)
{
    __asm__("nop\nnop");

    obj->flags |= FLG(OBJ_FLIP_X);
    if (
      obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1) &&
      horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
        FinAnim = true;
    else
        FinAnim = false;
    
    if (obj->main_etat == 0)
    {
        if (
          obj->sub_etat == 7 &&
          obj->anim_frame == 0x2C &&
          horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
            BBMONT_ETINCELLES(obj);
        if (FinAnim && obj->sub_etat == 0)
            set_sub_etat(obj, 7);
    }
}
#endif
