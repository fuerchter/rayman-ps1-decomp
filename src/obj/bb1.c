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
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_TOTEM_COMMAND);

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
INCLUDE_ASM("asm/nonmatchings/obj/bb1", allocateDog);

/* 58278 8017CA78 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", allocateTir);

/* 58644 8017CE44 -O2 -msoft-float */
#ifndef MISSING_ADDIU
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
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBL_COMMAND);

/* 58B04 8017D304 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ECLAIR);

/* 58CC4 8017D4C4 -O2 -msoft-float */
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
#ifndef MISSING_ADDIU
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

/* 5908C 8017D88C -O2 -msoft-float */
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

/* 59248 8017DA48 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_COMMAND);

/* 5A260 8017EA60 -O2 -msoft-float */
void DO_BBMONT_TOUCHE(Obj *obj)
{
  set_sub_etat(obj, 8);
  obj->anim_frame = 0;
  Phase = 7;
  WaitForFinAtan = 2;
}

/* 5A2A4 8017EAA4 -O2 -msoft-float */
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
#ifndef MISSING_ADDIU
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
                ) + (int)mp.map
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
                ) + (int)mp.map
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
#ifndef MISSING_ADDIU
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
