#include "obj/bb1.h"

/* reg swaps */
/* 57950 8017C150 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_TOTEM_COMMAND);*/

/*? GET_SPRITE_POS(Obj *, s16, u16 *, u16 *, u16 *, u16 *);
s32 myRand(?);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?);*/
s16 inter_box(s32, s32, s32, s32, s32, s32, s32, s32);

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

/* reg swaps */
/* 58278 8017CA78 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", allocateTir);*/

/*? GET_SPRITE_POS(Obj *, ?, s16 *, u16 *, u16 *, ? *);
? calc_obj_pos(Obj *);
? skipToLabel(Obj *, ?, ?);*/

void allocateTir(Obj *param_1,short param_2)
{
  u8 bVar1;
  s32 sVar2;
  s16 iVar3;
  s32 spriteIndex;
  Obj *obj;
  short local_30;
  short local_2e;
  short local_2c;
  s16 auStack_2a;
  u8 nb_objs;
  int new_var;
  s32 new_var2;
  
  iVar3 = 0;
  nb_objs = level.nb_objects;
  obj = level.objects;
  if (nb_objs != 0) {
    do {
      if ((obj->type == TYPE_BBL) && ((obj->flags & FLG(OBJ_ACTIVE)) == FLG_OBJ_NONE)) {
        spriteIndex = 9;
        if (param_2 != 0) {
          spriteIndex = 8;
        }
        obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
        GET_SPRITE_POS(param_1,spriteIndex,&local_30,&local_2e,&local_2c, &auStack_2a);
        if (param_2 == 1) {
          sVar2 = (local_30 - obj->offset_bx) + (local_2c >> 1);
          if ((param_1->flags & 0x4000)) {
            sVar2 = sVar2 + 0x40;
          }
          else {
            sVar2 = sVar2 + -0x40;
          }
          obj->x_pos = sVar2;
          obj->y_pos = local_2e + -0x28;
          if ((param_1->flags & 0x4000) != FLG_OBJ_NONE) {
            sVar2 = 0xc;
          }
          else
            sVar2 = -0xc;
          obj->speed_x = sVar2;
          obj->speed_y = 0;
          obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | param_1->flags & FLG(OBJ_FLIP_X);
        }
        else if (param_2 == 0) {
          sVar2 = (local_30 - obj->offset_bx) + (local_2c >> 1);
          if ((param_1->flags & FLG(OBJ_FLIP_X))) {
            sVar2 = sVar2 + 9;
          }
          else {
            sVar2 = sVar2 + -9;
          }
          obj->x_pos = sVar2;
          obj->y_pos = local_2e + -0x28;
          sVar2 = -2;
          if ((param_1->flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE) {
            sVar2 = 2;
          }
          obj->speed_x = sVar2;
          obj->speed_y = -5;
          obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | param_1->flags & FLG(OBJ_FLIP_X);
        }
        else {
          if (param_2 == 3) {
            new_var2 = param_1->x_pos;
            if ((param_1->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE)
                obj->x_pos = new_var2 - 0x24;
            else
                obj->x_pos = new_var2 + 0x78;

            obj->y_pos = param_1->y_pos - 0xb9;
            obj->speed_y = 4;  
          }
          else {
            if (9 >= param_2) {
              obj->x_pos = ray.x_pos;
              if (obj->x_pos < 0x28) {
                obj->x_pos = 0x28;
              }
              if (obj->x_pos > 0xc8) {
                obj->x_pos = 0xc8;
              }
              
            }
            else {
              if ((param_1->flags & FLG(OBJ_FLIP_X))) {
                sVar2 = 0xf0 - (bb1.field8_0xe * 0x32);
                
              }
              else {
                sVar2 = bb1.field8_0xe * 0x32 + -0x14;
              }
              obj->x_pos = sVar2;
            }
            obj->y_pos = param_1->y_pos + -200;
            obj->speed_y = 0;
            
          }
          obj->speed_x = 0;
        }
        obj->iframes_timer = 0x26;
        if (param_2 != 3) {
          obj->gravity_value_2 = 10;
        }
        else {
          obj->gravity_value_2 = 7;
        }

        if (param_2 == 0) {
          obj->gravity_value_2 = 3;
        }
        obj->main_etat = 2;
        obj->sub_etat = 6;
        skipToLabel(obj,1,true);
        calc_obj_pos(obj);
        obj->gravity_value_1 = 0;
        obj->flags = obj->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        if (9 >= param_2) {
          obj->field23_0x3c = param_2;
        }
        else {
          obj->field23_0x3c = 4;
        }
        if (param_2 == 3) {
          return;
        }
        PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = obj->id;
        PS1_AlwaysObjectsCount = PS1_AlwaysObjectsCount + 1;
        return;
      }
      obj = obj + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < nb_objs);
  }
  return;
}

/* reg swaps */
/* 5884C 8017D04C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBL_COMMAND);*/

void DO_BBL_COMMAND(Obj *obj)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int new_var2;
  
  if (PierreDoitExploser != 0) {
    DO_PI_EXPLOSION2(obj);
    obj->flags &= ~FLG(OBJ_ACTIVE);
    obj->flags &= ~FLG(OBJ_ALIVE);
    if (ray.field20_0x36 == obj->id) {
      ray.field20_0x36 = -1;
      obj->ray_dist = 1000;
      set_main_and_sub_etat(&ray,2,2);
    }
    PierreDoitExploser = 0;
    PosPierre = 9999;
    PS1_AlwaysObjectsCount = PS1_AlwaysObjectsCount + -1;
  }
  sVar2 = 0x14;
  if ((obj->field23_0x3c == 3))
  {
    sVar1 = --obj->iframes_timer;
    if(sVar1 == 0) {
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
    }
  }
  if (obj->speed_x < 0) {
    sVar2 = -0x14;
  }
  if ((block_flags
    [*(ushort *)
        (((((int) (obj->x_pos + obj->offset_bx + sVar2) >> 4) +
        mp.width * (obj->y_pos + 0x28 >> 4)) * 0x10000 >> 0xf) +
        (int)mp.map) >> 10
    ] >> 4 & 1) != 0)
  {
    switch(obj->field23_0x3c)
    {
    case 1:
        PlaySnd(200,obj->id);
        iVar4 = (int)obj->speed_x;
        iVar3 = iVar4;
        new_var2 = 12;
        if (iVar4 < 0) {
            iVar3 = -iVar3;
        }
        if (iVar3 == new_var2) {
            sVar2 = 0xd;
            if (iVar4 > 0) {
                sVar2 = -0xd;
            }
            obj->speed_x = sVar2;
            obj->speed_y = 0;
        }
        else if (iVar3 == 13) {
            sVar2 = 0xe;
            if (0 < iVar4) {
                sVar2 = -0xe;
            }
            obj->speed_x = sVar2;
            obj->speed_y = 0;
        }
        else if (iVar3 == 14) {
            sVar2 = 0xf;
            if (0 < iVar4) {
                sVar2 = -0xf;
            }
            obj->speed_x = sVar2;
            obj->speed_y = 0;
        }
        else if (iVar3 == 15)
        {
            DO_PI_EXPLOSION2(obj);
            obj->flags &= ~FLG(OBJ_ACTIVE);
            obj->flags &= ~FLG(OBJ_ALIVE);
            if (ray.field20_0x36 == obj->id) {
                ray.field20_0x36 = -1;
                obj->ray_dist = 1000;
                set_main_and_sub_etat(&ray,2,2);
            }
            PS1_AlwaysObjectsCount = PS1_AlwaysObjectsCount + -1;
            return;
        }
        break;
    case 0:
        PlaySnd(200,obj->id);
        obj->speed_x = 0;
        obj->field23_0x3c = 2;
        break;
    }
  }
  return;
}

/* matches, but too lazy to clean */
/* 58B04 8017D304 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ECLAIR);*/

void BBMONT_ECLAIR(Obj *obj)
{
  char cVar1;
  s32 sVar2;
  s16 iVar3;
  Obj *eclairObj;
  short local_18;
  short local_16;
  short local_14;
  s16 auStack_12;
  u8 nb_objs;
  
  iVar3 = 0;
  eclairObj = level.objects;
  nb_objs = level.nb_objects;
  if (nb_objs != 0) {
    do {
      if ((eclairObj->type == TYPE_ECLAIR) &&
         ((eclairObj->flags & FLG(OBJ_ACTIVE)) == FLG_OBJ_NONE)) {
        eclairObj->flags =
             eclairObj->flags & ~FLG(OBJ_FLIP_X) | obj->flags & FLG(OBJ_FLIP_X);
        eclairObj->speed_y = 0;
        if ((eclairObj->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          cVar1 = eclairObj->eta[eclairObj->main_etat][eclairObj->sub_etat].
                  speed_x_left;
        }
        else {
          cVar1 = eclairObj->eta[eclairObj->main_etat][eclairObj->sub_etat].
                  speed_x_right;
        }
        eclairObj->speed_x = (short)cVar1;
        GET_SPRITE_POS(obj,10,&local_18,&local_16,&local_14,&auStack_12);
        sVar2 = (local_18 + local_14) - eclairObj->offset_bx;
        if ((obj->flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE) {
          sVar2 = sVar2 + 0x10;
        }
        else {
          sVar2 = sVar2 + -0x10;
        }
        eclairObj->x_pos = sVar2;
        eclairObj->y_pos = local_16;
        eclairObj->init_x_pos = eclairObj->x_pos;
        eclairObj->init_y_pos = eclairObj->y_pos;
        skipToLabel(eclairObj,(u8)(eclairObj->flags >> 0xe) & 1,true);
        calc_obj_pos(eclairObj);
        eclairObj->flags = eclairObj->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        allocateExplosion(eclairObj);
        return;
      }
      eclairObj = eclairObj + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < nb_objs);
  }
  return;
}

/* matches, but too lazy to clean */
/* 58CC4 8017D4C4 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", BBMONT_ETINCELLES);*/

void BBMONT_ETINCELLES(Obj *param_1)
{
  short sVar1;
  s16 uVar2;
  s16 iVar3;
  Obj *pOVar4;
  short local_18;
  short local_16;
  short local_14;
  s16 auStack_12;
  u8 nb_objs;
  ObjFlags OVar3;
  ObjFlags new_var;
  
  iVar3 = 0;
  pOVar4 = level.objects;
  nb_objs = level.nb_objects;
  if (nb_objs != 0) {
    do {
      if ((pOVar4->type == TYPE_ETINC) && ((pOVar4->flags & FLG(OBJ_ACTIVE)) == FLG_OBJ_NONE)) {
        pOVar4->flags = pOVar4->flags & ~FLG(OBJ_FLIP_X) | param_1->flags & FLG(OBJ_FLIP_X);
        pOVar4->speed_y = 0;
        if ((pOVar4->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          pOVar4->speed_x = 7;
        }
        else {
          pOVar4->speed_x = -7;
        }

        GET_SPRITE_POS(param_1,3,&local_18,&local_16,&local_14,&auStack_12);
        if ((param_1->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          local_14 = 0;
        }
        pOVar4->x_pos = (local_18 + local_14) - (ushort)pOVar4->offset_bx; /* temp_a3 */
        pOVar4->y_pos = local_16 + -8;
        pOVar4->init_x_pos = pOVar4->x_pos;
        pOVar4->init_y_pos = pOVar4->y_pos;
        skipToLabel(pOVar4,(u8)(pOVar4->flags >> 0xe) & 1,true);
        calc_obj_pos(pOVar4);
        pOVar4->flags = pOVar4->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        pOVar4 = pOVar4 + 1;
        pOVar4->flags = pOVar4->flags & ~FLG(OBJ_FLIP_X) | param_1->flags & FLG(OBJ_FLIP_X);
        pOVar4->speed_y = 0;
        if ((pOVar4->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          pOVar4->speed_x = 7;
        }
        else {
          pOVar4->speed_x = -7;
        }

        GET_SPRITE_POS(param_1,2,&local_18,&local_16,&local_14,&auStack_12);
        if ((param_1->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          local_14 = 0;
        }
        pOVar4->x_pos = (local_18 + local_14) - (pOVar4->offset_bx);
        pOVar4->y_pos = local_16 + -8;
        pOVar4->init_x_pos = pOVar4->x_pos;
        pOVar4->init_y_pos = pOVar4->y_pos;
        skipToLabel(pOVar4,(u8)(pOVar4->flags >> 0xe) & 1,true);
        calc_obj_pos(pOVar4);
        pOVar4->flags = pOVar4->flags | (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        allocateExplosion(pOVar4);
        return;
      }
      pOVar4 = pOVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < nb_objs);
  }
  return;
}

/* 5908C 8017D88C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", Fin_BB_Attaque);*/

void Fin_BB_Attaque(Obj *obj)
{
  IndAtak = IndAtak + 1;
  if (IndAtak < 7) {
    NextAtak = SerieAtakBB[IndSerie][IndAtak].attack;
  }
  else
  {
    NextAtak = 0xff;
  }

  if (NextAtak == 0xff) {
    IndAtak = 0;
    NextAtak = SerieAtakBB[IndSerie][IndAtak].attack;
  }
  WaitForFinAtan = SerieAtakBB[IndSerie][IndAtak].wait_for_fin_atan;
  BB_Attaque(obj);
  return;
}