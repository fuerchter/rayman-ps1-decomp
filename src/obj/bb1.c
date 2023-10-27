#include "obj/bb1.h"

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
extern s16 PS1_AlwaysObjectsCount;
extern s16 PosPierre;

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
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", CreateFirstBBL);*/

extern s16 PS1_AlwaysObjects[100];

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
}



INCLUDE_ASM("asm/nonmatchings/obj/bb1", INIT_BBMONT);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBL_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ECLAIR);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ETINCELLES);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_TIRE);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", Cree_BBL);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BB_Attaque);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", Fin_BB_Attaque);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", BB_Atan);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_TOUCHE);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_MARCHE);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT3_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT3_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT4_COMMAND);
