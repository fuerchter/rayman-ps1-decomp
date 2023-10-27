#include "obj/bb1.h"

/* reg swaps */
/* 57950 8017C150 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_TOTEM_COMMAND);*/

/*? GET_SPRITE_POS(Obj *, s16, u16 *, u16 *, u16 *, u16 *);
s32 myRand(?);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?);*/
s16 inter_box(s32, s32, s32, s32, s32, s32, s32, s32);
extern s16 IndAtak;
extern u16 IndSerie;
extern BB1Data bb1;

void DO_TOTEM_COMMAND(Obj *param_1)
{
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    Obj *var_s2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s32 temp_v1;
    s16 var_a0;
    s16 var_s4;
    u8 var_a0_2;
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_v0_4;
    s16 temp_v1_2;
    s16 var_v0_2;
    Obj *var_s1;
    u8 temp_v0_5;
    u8 var_v0;
    u8 var_v1;
    u8 nb_objs;
    u8 test_1;
    ObjFlags test_2;
    s32 test_3;

    temp_v0 = --param_1->field23_0x3c;
    if (temp_v0 < 0)
    {
        param_1->field23_0x3c = 0;
    }
    if (bb1.field2_0x4 == 3)
    {
        param_1->flags &= ~0x800;
        param_1->flags &= ~0x400;
        var_s2 = level.objects;
        var_a0 = 0;
        nb_objs = level.nb_objects;
        if (nb_objs != 0)
        {
            test_2 = ~0x4000;
            test_1 = 0x11;
            do
            {
                if (var_s2->type == 0xD3)
                {
                    var_s4 = 0;
                    var_s1 = var_s2;
                    do
                    {
                        GET_SPRITE_POS(param_1, var_s4, &x, &y, &w, &h);
                        var_s1->x_pos = x;
                        var_s1->y_pos = y;
                        var_s1->flags = (var_s1->flags | 0xC00);
                        if (var_s4 == 0)
                        {
                            var_s1->speed_x = 0;
                            var_s1->speed_y = 0;
                        }
                        else
                        {
                            temp_v1 = 2 - myRand(4);
                            var_s1->speed_x = temp_v1;
                            if ((s16)temp_v1 == 0)
                            {
                                var_s1->speed_x = 1;
                            }
                            var_s1->speed_y = (-4 - myRand(3));
                        }
                        var_s1->gravity_value_1 = 0;
                        var_s1->gravity_value_2 = 5;
                        switch (var_s4)
                        {
                        case 1:
                            set_main_and_sub_etat(var_s2, 2, 8);
                            var_s1->offset_by = 0x2B;
                            var_s1->offset_bx = 0x19;
                            var_s1->flags = (var_s1->flags & test_2);
                            var_s1->anim_index = 0x1F;
                            break;
                        case 2:
                            set_main_and_sub_etat(var_s2, 2, 0xA);
                            var_s1->offset_by = test_1;
                            var_s1->offset_bx = 0x0C;
                            var_s1->flags = (var_s1->flags & test_2);
                            var_s1->anim_index = 0x21;
                            break;
                        case 3:
                            set_main_and_sub_etat(var_s2, 2, 0xB);
                            var_s1->offset_by = 7;
                            var_s1->offset_bx = 7;
                            var_s1->flags = (var_s1->flags & test_2);
                            var_s1->anim_index = 0x22;
                            break;
                        case 4:
                            set_main_and_sub_etat(var_s2, 2, 9);
                            var_s1->offset_by = 0x1C;
                            var_s1->offset_bx = test_1;
                            var_s1->flags = (var_s1->flags & test_2);
                            var_s1->anim_index = 0x20;
                            break;
                        case 5:
                            set_main_and_sub_etat(var_s2, 2, 0xA);
                            var_s1->offset_by = test_1;
                            var_s1->offset_bx = 0x0C;
                            var_s1->flags = (var_s1->flags | 0x4000);
                            var_s1->anim_index = 0x21;
                            break;
                        case 0:
                            set_main_and_sub_etat(var_s2, 0, 0x15);
                            var_s1->flags = (var_s1->flags & test_2);
                            var_s1->anim_index = 0x25;
                            break;
                        }
                        var_s1 += 1;
                        temp_v0_3 = var_s4 + 1;
                        var_s4 = temp_v0_3;
                        var_s2 += 1;
                    } while (temp_v0_3 < 6);
                    return;
                }
                temp_v0_2 = var_a0 + 1;
                var_a0 = temp_v0_2;
                var_s2 += 1;
            } while(temp_v0_2 < (s32) nb_objs);
            return;
            
        }
    }
    else if ((u8)(param_1->sub_etat - 6) >= 2 && param_1->sub_etat != 3)
    {
        GET_SPRITE_POS(param_1, 6, &x, &y, &w, &h);
        temp_a0 = x + 5;
        x = temp_a0;
        temp_a1 = y + 5;
        y = temp_a1;
        test_3 = 0xA;
        temp_a2 = w - test_3;
        w = temp_a2;
        temp_a3 = h - test_3;
        h = temp_a3;
        if (((inter_box(temp_a0, temp_a1, temp_a2, temp_a3, bb1.sprite6_x, bb1.sprite6_y, 0x00000020, 0x00000020)) != 0) && (bb1.field2_0x4 == 0))
        {
            temp_v1_2 = IndSerie;
            bb1.field2_0x4 = 1;
            param_1->iframes_timer = 4;
            temp_v0_4 = temp_v1_2 + 1;
            IndSerie = temp_v0_4;
            if ((s16) temp_v0_4 >= 6)
            {
                IndSerie = temp_v1_2;
            }
            IndAtak = 0;
        }
        var_a0_2 = 0;
        if (param_1->anim_frame == (param_1->animations[param_1->anim_index].frames_count - 1))
        {
            var_a0_2 = horloge[param_1->eta[param_1->main_etat][param_1->sub_etat].anim_speed & 0xf] == 0;
        }
        temp_v0_5 = param_1->sub_etat;
        switch (temp_v0_5)
        {
        case 3:
        case 6:
        case 7:
            break;
        case 4:
            if (var_a0_2)
            {
                temp_v0_6 = param_1->iframes_timer + 1;
                param_1->iframes_timer = temp_v0_6;
                if (temp_v0_6 < 4)
                {
                    set_sub_etat(param_1, 5);
                    var_v0_2 = param_1->init_x_pos - 0x55;
                }
                else
                {
                    set_sub_etat(param_1, 6);
                    var_v0_2 = param_1->init_x_pos;
                }
                param_1->x_pos = var_v0_2;
            }
            break;
        case 5:
            if (var_a0_2)
            {
                temp_v0_7 = param_1->iframes_timer + 1;
                param_1->iframes_timer = temp_v0_7;
                if (temp_v0_7 < 4)
                {
                    set_sub_etat(param_1, 4);
                    var_v0_2 = param_1->init_x_pos + 0x47;
                }
                else
                {
                    set_sub_etat(param_1, 7);
                    var_v0_2 = param_1->init_x_pos;
                }
                param_1->x_pos = var_v0_2;
            }
            break;
        }
    }
}

/* 580F8 8017C8F8 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", allocateDog);*/

/*? calc_obj_pos(Obj *);
? obj_init(Obj *, s16, u8);
? skipToLabel(Obj *, ?, ?);*/
/*void skipToLabel(Obj *obj,u8 label,u8 param_3);*/
extern u8 D_801D7AE4;
extern s16 YaDesChiens;
extern s16 niveau;

void allocateDog(Obj *bb1Obj)
{
  ObjFlags OVar1;
  s16 iVar2;
  Obj *obj;
  short sVar3;
  u8 nb_objs;

  iVar2 = 0;
  nb_objs = level.nb_objects;
  obj = level.objects;
  if (nb_objs != 0) {
    do {
      if ((obj->type == TYPE_STONEDOG2) &&
         (OVar1 = obj->flags, (OVar1 & FLG(OBJ_ACTIVE)) == FLG_OBJ_NONE)) {
        sVar3 = 0x104;
        if (((bb1Obj->flags >> 0xe & 1) + (int)YaDesChiens & 1) == 0) {
          sVar3 = -0x14;
          OVar1 = OVar1 | FLG(OBJ_FLIP_X);
        }
        else {
          OVar1 = OVar1 & ~FLG(OBJ_FLIP_X);
        }
        obj->flags = OVar1;
        obj_init(obj);
        obj->cmd_offset = -1;
        obj->x_pos = sVar3;
        obj->y_pos = bb1Obj->y_pos - 0x14;
        obj->flags = obj->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        obj->flags = obj->flags & ~FLG(OBJ_FLAG_9);
        obj->speed_x = 0;
        obj->speed_y = 0;
        obj->main_etat = 2;
        obj->sub_etat = 2;
        skipToLabel(obj, (u8)(obj->flags & FLG(OBJ_FLIP_X)),true);
        calc_obj_pos(obj);
        if (niveau == 0) {
          obj->hit_points = 1;
        }
        return;
      }
      obj = obj + 1;
      iVar2 = iVar2 + 1;

    } while (iVar2 < nb_objs);
  }
  return;
}