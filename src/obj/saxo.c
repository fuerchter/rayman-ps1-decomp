#include "obj/saxo.h"

/* 50CDC 801754DC -O2 -msoft-float */
extern s16 IndexSerie;
extern u8 IsBossThere;
extern u8 Phase;
extern s16 D_801F7FA0;

void INIT_SAXO(Obj *sax_obj)
{
  sax_obj->y_pos = firstFloorBelow(sax_obj) - sax_obj->offset_by;
  calc_obj_pos(sax_obj);
  sax_obj->speed_x = 0;
  sax_obj->speed_y = 0;
  Phase = 0;
  IsBossThere = 0;
  IndexSerie = 0;
  sax_obj->flags = (sax_obj->flags | OBJ_ALIVE) & ~OBJ_ACTIVE;
  if (sax_obj->type == TYPE_SAXO)
    sax_obj->hit_points = Sax.saved_hp;
  Sax.coup = 0;
  D_801F7FA0 = 0;
  Sax.field10_0x10 = 0;
}

/* TODO: param_2, locals */
/* 50D7C 8017557C -O2 -msoft-float */
void allocateNote2(Obj *note_obj, s16 param_2)
{
  Obj *cur_obj;
  s16 i;
  u8 nb_objs;
  u8 offs_half;
  u16 offs_x;
  
  if (note_obj->iframes_timer > 0)
  {
    cur_obj = level.objects;
    i = 0;
    nb_objs = level.nb_objects;
    if (nb_objs != 0)
    {
      do {
        if (cur_obj->type == TYPE_NOTE2 && !(cur_obj->flags & OBJ_ACTIVE))
        {
          cur_obj->flags &= ~OBJ_FLIP_X;
          cur_obj->speed_y = 0;
          cur_obj->speed_x = 0;

          offs_half = note_obj->offset_bx / 2;
          offs_x = offs_half;
          if (param_2 != 0)
            offs_x = -offs_half;
          cur_obj->x_pos = offs_x + note_obj->x_pos;
          cur_obj->y_pos = note_obj->y_pos;
          
          cur_obj->main_etat = 0;
          cur_obj->sub_etat = param_2 + 2;
          cur_obj->init_x_pos = cur_obj->x_pos;
          cur_obj->init_y_pos = cur_obj->y_pos;
          skipToLabel(cur_obj,1,TRUE);
          calc_obj_pos(cur_obj);
          cur_obj->flags = (cur_obj->flags | OBJ_ALIVE) & ~OBJ_FLAG_9 | OBJ_ACTIVE;
          cur_obj->gravity_value_1 = 0;
          cur_obj->iframes_timer = note_obj->iframes_timer - 1;
          calc_obj_pos(cur_obj);
          cur_obj->field23_0x3c = 10;
          allocateExplosion(cur_obj);
          return;
        }
        cur_obj++;
        i++;
      } while (i < nb_objs);
    }
  }
}

/* 50EE0 801756E0 -O2 -msoft-float */
void DO_EXPLOSE_NOTE2(Obj *obj)
{
  obj->speed_x = 0;
  obj->speed_y = 0;
  calc_obj_pos(obj);
  set_main_and_sub_etat(obj, 0, 1);
  PlaySnd(0xf6, obj->id);
  allocateExplosion(obj);
  obj->field23_0x3c = 10;
  obj->iframes_timer = 3;
}

/* 50F40 80175740 -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_NOTE_CMD);
#else
/*? PlaySnd(?, s16, s16);
? allocateExplosion(Obj *);
? set_main_and_sub_etat(Obj *, ?, ?);*/
s16 inter_box(s32, s32, s32, s32, s32, s32, s32, s32);

void DO_NOTE_CMD(Obj *obj)
{
    s16 calc_x;
    s32 offs_x;
    u8 var_v1;
    u8 temp_v0_2;

    __asm__("nop");

    switch (obj->type)
    {
    case TYPE_NOTE3:
        if (obj->speed_x == 0)
        {
            calc_x = obj->offset_bx + obj->x_pos - Sax.note_box_coll_x;
            if (calc_x < 20)
            {
                set_main_and_sub_etat(obj, 2, 0);
                obj->speed_x = 3;
                obj->flags |= OBJ_FLIP_X;
            }
            else if (calc_x < 200)
            {
                /* vibrate back and forth the closer sax gets */
                var_v1 = (calc_x >> 3) - 2;
                offs_x = 1;
                if (var_v1 < 2)
                    var_v1 = 2;
                temp_v0_2 = var_v1;
                if (calc_x < 50)
                    offs_x = 2;
                
                if (horloge[temp_v0_2] < (temp_v0_2 / 2))
                    obj->x_pos = obj->init_x_pos + offs_x;
                else
                    obj->x_pos = obj->init_x_pos;
            }
        }
        break;
    case TYPE_NOTE2:
        if (obj->main_etat == 0)
        {
            obj->field23_0x3c--;
            if(obj->field23_0x3c == 0)
            {
                switch (obj->sub_etat)
                {
                case 1:
                    allocateNote2(obj, 1);
                    /* fall through */
                case 2:
                    allocateNote2(obj, 0);
                    obj->flags &= ~OBJ_ACTIVE;
                    obj->flags &= ~OBJ_ALIVE;
                    break;
                case 3:
                    allocateNote2(obj, 1);
                    obj->flags &= ~OBJ_ACTIVE;
                    obj->flags &= ~OBJ_ALIVE;
                    break;
                }
            }
        }
        break;
    case TYPE_BONNE_NOTE:
        if (
            inter_box(
                obj->x_pos + obj->offset_bx - 8,
                obj->y_pos + obj->offset_by - 8,
                16,
                16,
                Sax.note_box_coll_x,
                Sax.note_box_coll_y,
                20,
                140
            )
        )
        {
            if (Sax.coup == 0)
                Sax.coup = 1;
            obj->flags &= ~OBJ_ACTIVE;
            obj->flags &= ~OBJ_ALIVE;
            obj->y_pos += 30;
            PlaySnd(0xF3, obj->id);
            allocateExplosion(obj);
        }
        break;
    }
}
#endif

/* 511C4 801759C4 -O2 -msoft-float */
/*? calc_obj_pos(Obj *);
? skipToLabel(Obj *, ?, ?);*/

void Cree_Eclat_Note(Obj *bnote, Obj *note1, s16 index)
{
  s16 speed_x;
  
  if (bnote->type == TYPE_BNOTE)
  {
    if (bnote->flags & OBJ_ACTIVE)
    {
        do {
            bnote++;
            if (bnote->type != TYPE_BNOTE)
                return;
        } while (bnote->flags & OBJ_ACTIVE);
    }
  }

  if (bnote->type == TYPE_BNOTE)
  {
    if (index < 4)
    {
        bnote->flags = (bnote->flags & ~OBJ_FLIP_X) | ((index % 2) & 1) << 14;
        if (index < 2)
            bnote->speed_y = -1;
        else
            bnote->speed_y = 1;

        if (bnote->flags & OBJ_FLIP_X)
            speed_x = 1;
        else
            speed_x = -1;
        bnote->speed_x = speed_x;
    }
    else
    {
        bnote->flags = (bnote->flags & ~OBJ_FLIP_X) | ((index % 2) & 1) << 14;
        switch(index)
        {
        case 4:
            bnote->speed_y = 0;
            bnote->speed_x = -2;
            break;
        case 5:
            bnote->speed_x = 2;
            bnote->speed_y = 0;
            break;
        case 6:
            bnote->speed_x = 0;
            bnote->speed_y = -2;
            break;
        case 7:
            bnote->speed_x = 0;
            bnote->speed_y = 2;
            break;
        }
    }
    bnote->x_pos = note1->x_pos;
    bnote->y_pos = note1->y_pos;
    bnote->main_etat = 2;
    bnote->sub_etat = 5;
    skipToLabel(bnote, 1, TRUE);
    calc_obj_pos(bnote);
    bnote->flags |= (OBJ_ALIVE|OBJ_ACTIVE);
    calc_obj_pos(bnote);
  }
  
}

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_EXPLOSE_NOTE1);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", BonneNote);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_NOTE_TOUCHEE);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_NOTE_REBOND);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", allocateNote);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", PrepareAtak);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", SAXO_TIRE);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_COUP);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO2_COUP);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", SetSaxoCollNoteBox);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO2_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO2_ATTER);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_MARCHE);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO3_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO3_DEBUT);

INCLUDE_ASM("asm/nonmatchings/obj/saxo", saxo2_get_eject_sens);
