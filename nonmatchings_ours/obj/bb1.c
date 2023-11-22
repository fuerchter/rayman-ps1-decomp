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

/* goal is around 1600? case GO_RIGHT is still bad, a reg swap further down */
/* 59248 8017DA48 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_COMMAND);*/

/*? CALC_MOV_ON_BLOC(Obj *);
? GET_SPRITE_POS(Obj *, ?, ? *, void *, u16 *, u16 *);
? PlaySnd(?, s16);
s32 calc_typ_travd(Obj *, ?);
? set_main_and_sub_etat(Obj *, u8, u8);
? set_sub_etat(Obj *, ?);
? skipToLabel(Obj *, ?, ?);*/
void SET_X_SPEED(Obj *obj);

void DO_BBMONT_COMMAND(Obj *obj)
{
  ObjCommand OVar1;
  u8 bVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  s32 bVar6;
  u8 uVar7;
  short local_18;
  short local_16;
  s16 temp_v0_2;
s32 temp_a0;
s32 temp_a0_2;
int new_var;
s16 temp_v0_7;
    s16 var_v0_2;
    s16 var_v1;
    s16 var_v1_2;
    u8 new_var2;
  
  scrollLocked = true;
  if ((YaDesChiens != 0) && (horlogeDog = horlogeDog - 1, (int)((uint)horlogeDog << 0x10) < 0)) {
    horlogeDog = 0x32;
    allocateDog(obj);
    YaDesChiens = YaDesChiens + -1;
  }
  GET_SPRITE_POS(obj,6,&bb1.sprite6_x,&bb1.sprite6_y,&local_18,&local_16);
  local_18 = obj->x_pos;
  local_16 = obj->y_pos;
  if (((uint)obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1) &&
     (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0)) {
    FinAnim = true;
  }
  else {
    FinAnim = false;
  }
  if ((bb1.field2_0x4 == 2) && (FinAnim != false)) {
    if ((uint)obj->hit_points == obj->init_hit_points - 1) {
      skipToLabel(obj,4,true);
      Phase = 7;
    }
    set_main_and_sub_etat(obj,bb1.saved_main_etat,bb1.saved_sub_etat);
    WaitForFinAtan = 1;
    obj->cmd = (ObjCommand)bb1.saved_cmd;
  }
  if (bb1.field2_0x4 == 1) {
    if ((obj->main_etat != 0) || (obj->sub_etat != 9)) {
      bb1.saved_main_etat = obj->main_etat;
      bb1.saved_sub_etat = obj->sub_etat;
      set_main_and_sub_etat(obj,0,9);
      bb1.field2_0x4 = 2;
      FinAnim = false;
      obj->speed_x = 0;
      obj->hit_points--;
      bb1.saved_cmd = (short)obj->cmd;
      if (obj->hit_points == 0) {
        bb1.field2_0x4 = 3;
        set_main_and_sub_etat(obj,0,0x14);
        obj->speed_x = 0;
        bb1.saved_cmd = 0x1a4;
      }

    }
    else {
      bb1.field2_0x4 = 0;
    }
  }
    if (bb1.field2_0x4 == 3)
    {
        temp_v0_2 = --bb1.saved_cmd;
        if ((temp_v0_2 << 0x10) <= 0)
        {
            fin_boss = 1;
            bb1.saved_cmd = 0x03E7;
            *finBosslevel |= 8;
        }
    }
    else
    {
        OVar1 = obj->cmd;
        switch(OVar1)
        {
        case GO_RIGHT:
            obj->flags = obj->flags | FLG(OBJ_FLIP_X);
        LAB_8017dd9c:
            SET_X_SPEED(obj);
            uVar4 = calc_typ_travd(obj,false);
            if ((block_flags[uVar4 & 0xff] >> 4 & 1) != 0) {
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | ((obj->flags >> 0xe ^ 1) & 1) << 0xe;
                skipToLabel(obj,6,true);
                if (3 < IndSerie) {
                    WaitForFinAtan = 2;
                }
                Phase = 8;
            }
            if (Phase == 7) {
                temp_a0 = obj->x_pos;
                new_var = PosPierre + 0xE;
                if (!(obj->flags & 0x4000))
                {
                    goto block_38;
                }
                if (temp_a0 >= (new_var))
                {
                    goto block_45;
                }
                goto block_40;
            block_38:
                if (temp_a0 >= (PosPierre - 6))
                {
                    goto block_45;
                }
            block_40:
                temp_a0_2 = obj->x_pos;
                new_var = PosPierre + 6;
                if (!(obj->flags & 0x4000))
                {
                    goto block_43;
                }
                if ((new_var) < temp_a0_2)
                {
                    goto block_44;
                }
                goto block_45;
            block_43:
                if ((PosPierre - 0xE) >= temp_a0_2)
                {
                    goto block_45;
                }
            block_44:
                set_main_and_sub_etat(obj, 0U, 2U);
                skipToLabel(obj, 0, 1);
                Phase = 9;
            }
block_45:
            CALC_MOV_ON_BLOC(obj);
            break;
        case GO_LEFT:
            obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
            goto LAB_8017dd9c;
            break;
        case GO_WAIT:
            switch(Phase) {
            case 0:
                if (bb1.field8_0xe != 0) {
                    CreateFirstBBL();
                    WaitForAnim = true;
                    bb1.field8_0xe = 0;
                }
                if (FinAnim != false) {
                    if (WaitForAnim != false) {
                        obj->anim_frame = 0;
                        IndSerie = 0;
                        IndAtak = 0;
                        WaitForFinAtan = SerieAtakBB[0][0].wait_for_fin_atan;
                        NextAtak = SerieAtakBB[0][0].attack;
                        BB_Attaque(obj);
                    }
                }
                break;
            case 1:
                if ((((obj->sub_etat == 4) && (obj->anim_frame == 0xe)) &&
                    (horloge[obj->eta[obj->main_etat][4].anim_speed & 0xf] == 0)) && (screen_trembling2 == 0)) {
                    screen_trembling2 = 1;
                    allocateTir(obj,4);
                }
                if (FinAnim == false) {
                    return;
                }
                BB_Atan(obj);
                break;
            case 2:
                bVar6 = obj->sub_etat;
                if (obj->sub_etat == 0xb) {
                    if ((obj->anim_frame == 0x17) &&
                        (horloge[obj->eta[obj->main_etat][0xb].anim_speed & 0xf] == 0)) {
                        allocateTir(obj,1);
                    }
                    bVar6 = obj->sub_etat;
                }
                if (((bVar6 == 3) && (obj->anim_frame == 0xe)) &&
                ((horloge[obj->eta[obj->main_etat][3].anim_speed & 0xf] == 0 && (screen_trembling2 == 0)))) {
                    screen_trembling2 = 1;
                    allocateTir(obj,3);
                    bVar2 = WaitForFinAtan;
                    if (niveau == 0) {
                        WaitForFinAtan = bVar2 + 3;
                    }
                    else
                    {
                        WaitForFinAtan = bVar2 + 1;
                    }

                }
                bVar6 = obj->sub_etat;
                if ((bVar6 == 10) && (FinAnim != false)) {
                    WaitForFinAtan--;
                    new_var2 = WaitForFinAtan;
                    if (new_var2 != 0) {
                        obj->anim_frame = 0;
                        set_sub_etat(obj,10);
                    }
                    bVar6 = obj->sub_etat;
                }
                if (bVar6 == 0xb) {
                    if (FinAnim != false) {
                        Phase = 0xb;
                        obj->iframes_timer = 0x23;
                    }
                }
                break;
            case 3:
                if (((obj->sub_etat == 6) && (obj->anim_frame == 0x40)) &&
                (horloge[obj->eta[obj->main_etat][6].anim_speed & 0xf] == 0)) {
                    
                    if (niveau == 0) {
                        YaDesChiens = 3;
                    }
                    else
                    {
                        YaDesChiens = 4;
                    }
                    horlogeDog = 0;
                }
                if (FinAnim != false) {
                    BB_Atan(obj);
                }
                break;
            case 4:
                if (((obj->sub_etat == 7) && (obj->anim_frame == 0x2c)) &&
                (horloge[obj->eta[obj->main_etat][7].anim_speed & 0xf] == 0)) {
                BBMONT_ETINCELLES(obj);
                PlaySnd(0x72,obj->id);
                }
                if (FinAnim == false) {
                    return;
                }
                BB_Atan(obj);
                break;
            case 5:
                if (((obj->sub_etat == 2) && (obj->anim_frame == 0x15)) &&
                (horloge[obj->eta[obj->main_etat][2].anim_speed & 0xf] == 0)) {
                BBMONT_ECLAIR(obj);
                PlaySnd(0x72,obj->id);
                }
                if (FinAnim == false) {
                return;
                }
                obj->anim_frame = 0;
                set_sub_etat(obj,1);
                Phase = 10;
                break;
            case 6:
                if (FinAnim == false) {
                    return;
                }
                WaitForFinAtan--;
                new_var2 = WaitForFinAtan;
                if (new_var2 == 0) {
                    Fin_BB_Attaque(obj);
                }
                break;
            case 7:
                if (((obj->sub_etat == 8) && (obj->anim_frame == 0xe)) &&
                (horloge[obj->eta[obj->main_etat][8].anim_speed & 0xf] == 0)) {
                    allocateTir(obj,0);
                    break;
                }
                if (FinAnim != false) {
                    WaitForFinAtan--;
                    new_var2 = WaitForFinAtan;
                    if (new_var2 == 0) {
                        set_main_and_sub_etat(obj,1,2);
                        if ((obj->flags & FLG(OBJ_FLIP_X)))
                        {
                            skipToLabel(obj,5,true);
                        }
                        else
                        {
                            skipToLabel(obj,4,true);
                        }
                    }
                    else
                    {
                        set_sub_etat(obj,1);
                        break;
                    }
                }
                break;
            case 8:
                if (FinAnim == false) {
                return;
                }
                if (obj->sub_etat != 9) {
                if (WaitForFinAtan == 2) {
                    set_main_and_sub_etat(obj,0,1);
                    WaitForFinAtan--;
                }
                else if (bb1.field8_0xe == 0) {
                    WaitForFinAtan = SerieAtakBB[IndSerie][0].wait_for_fin_atan;
                    NextAtak = SerieAtakBB[IndSerie][0].attack;
                    IndAtak = 0;
                    BB_Attaque(obj);
                }
                else {
                    Fin_BB_Attaque(obj);
                    bb1.field8_0xe = 0;
                }
                }
                break;
            case 9:
                if (((obj->anim_frame == 0x14) &&
                    (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0)) &&
                (obj->sub_etat != 9)) {
                    PierreDoitExploser = 1;
                }
                if (FinAnim != false) {
                    if (bb1.field2_0x4 != 2) {
                        set_main_and_sub_etat(obj,1,0);
                        if ((obj->flags & FLG(OBJ_FLIP_X))) {
                            skipToLabel(obj,5,true);
                        }
                        else {
                            skipToLabel(obj,4,true);
                        }
                        PierreDoitExploser = 0;
                    }
                }
                break;
            case 10:
                if (FinAnim != false) {
                    obj->anim_frame = 0;
                    set_main_and_sub_etat(obj,1,1);
                    if ((obj->flags & FLG(OBJ_FLIP_X))) {
                        skipToLabel(obj,5,true);
                    }
                    else {
                        skipToLabel(obj,4,true);
                    }
                }
                break;
            case 0xb:
                bVar6 = obj->sub_etat;
                switch(bVar6)
                {
                case 3:
                case 0:
                    temp_v0_7 = obj->iframes_timer - 1;
                    obj->iframes_timer = temp_v0_7;
                    if (temp_v0_7 >= 2)
                    {
                        obj->speed_y = -8;
                        obj->gravity_value_1 = 0;
                        var_v0_2 = -4;
                        if (obj->flags & 0x4000)
                        {
                            var_v0_2 = 4;
                        }
                        obj->speed_x = var_v0_2;
                    }
                    else
                    {
                        set_sub_etat(obj, 4);
                        var_v1_2 = -2;
                        if (obj->flags & 0x4000)
                        {
                            var_v1_2 = 2;
                        }
                        obj->speed_x = var_v1_2;
                    }
                    break;
                case 6:
                    if (FinAnim != false) {
                        set_main_and_sub_etat(obj,1,0);
                        if ((obj->flags & FLG(OBJ_FLIP_X)))
                        {
                            skipToLabel(obj,5,true);
                        }
                        else
                        {
                            skipToLabel(obj,4,true);
                        }
                    }
                    break;
                }
                break;
            case 0xc:
                if (((obj->sub_etat == 4) && (obj->anim_frame == 0xe)) &&
                ((horloge[obj->eta[obj->main_etat][4].anim_speed & 0xf] == 0 && (screen_trembling2 == 0)))) {
                screen_trembling2 = 1;
                allocateTir(obj,bb1.field8_0xe + 10);
                bb1.field8_0xe = bb1.field8_0xe + 1;
                }
                if (FinAnim == false) {
                return;
                }
                if (bb1.field8_0xe != 3) break;
                bb1.field8_0xe = 0;
                BB_Atan(obj);
                break;
            case 0xd:
                if (obj->sub_etat == 0x16) {
                bVar6 = obj->anim_frame;
                if (bVar6 == 0x3f) {
                    if (horloge[obj->eta[obj->main_etat][0x16].anim_speed & 0xf] == 0) {
                    allocateTir(obj,1);
                    }
                    bVar6 = obj->anim_frame;
                }
                if (((bVar6 == 0xe) &&
                    (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0)) &&
                    (screen_trembling2 == 0)) {
                    screen_trembling2 = 1;
                    allocateTir(obj,3);
                }
                if (FinAnim == false) {
                    return;
                }
                Phase = 0xb;
                obj->iframes_timer = 0x23;
                bb1.field8_0xe = 1;
                }
            }
            break;
        }
        if ((FinAnim != false) && (bb1.field2_0x4 == 2)) {
            bb1.field2_0x4 = 0;
        }
  }
  return;
}

/* still very rough */
/* 5A2A4 8017EAA4 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_COMMAND);*/

/*? CALC_MOV_ON_BLOC(Obj *);
? SET_X_SPEED(Obj *);*/
void set_main_and_sub_etat(Obj *, u8, u8);
/*extern s32 D_801F4438;
extern u8 D_801F4EBD;
extern ? D_801F4EDA;
extern s16 bb1.saved_cmd;
extern ? D_801F4EE2;
extern s16 bb1.sprite6_y;
extern s16 ray.speed_x;*/

void DO_BBMONT2_COMMAND(Obj *obj)
{
    s16 temp_s2;
    s16 temp_s3;
    s32 temp_v0_2;
    s16 temp_v0_3;
    s16 var_v0_2;
    s16 var_v1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v1_2;
    u16 temp_v0_4;
    u16 var_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;

    temp_s2 = (u16) obj->x_pos + obj->offset_bx;
    temp_s3 = obj->offset_hy + (u16) obj->y_pos + 0x40;
    if ((obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1)) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
    {
        FinAnim = 1;
    }
    else
    {
        FinAnim = 0;
    }
    if (((u8) Phase < 2U) && (obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U) && (ray_zdc_y < (temp_s3 - 0x20)))
    {
        set_main_and_sub_etat(obj, 0U, 0x10U);
        obj->speed_x = 0;
        obj->speed_y = 0;
    }
    if (obj->main_etat == 1)
    {
        if (Phase == 0)
        {
            Phase = 1;
        }
        SET_X_SPEED(obj);
        if ((u8) Phase < 4U)
        {
            CALC_MOV_ON_BLOC(obj);
        }
        if ((FinAnim != 0) && (bb1.speed_x != (obj->sub_etat + 1)))
        {
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1U, 1U);
                break;
            case 3:
                set_main_and_sub_etat(obj, 1U, 2U);
                break;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1U, 0U);
                break;
            }
        }
    }
    if ((bb1.field1_0x2 < 8) && (Phase != 0) && (Phase != 5))
    {
        if (scroll_end_x == xmapmax)
        {
            scroll_end_x = (s16) (u16) xmap;
            if ((s16) (u16) xmap < temp_s2)
            {
                scroll_end_x = temp_s2;
            }
        }
        else if (scroll_end_x < temp_s2)
        {
            bb1.saved_cmd = 1;
        }
        if (bb1.saved_cmd != 0)
        {
            if (obj->main_etat == 1)
            {
                scroll_end_x = (u16) scroll_end_x + (obj->sub_etat + 1);
            }
            else
            {
                var_v0 = (u16) scroll_end_x + (u16) obj->speed_x;
                goto block_37;
            }
        }
    }
    else
    {
        var_v0 = (u16) xmapmax;
block_37:
        scroll_end_x = (s16) var_v0;
    }
    switch (Phase)
    {
    case 0:
        temp_v0 = ((u8) block_flags[obj->btypes[0]] >> 1) & 5;
        var_a0 = 0x28;
        if ((temp_v0 == 0) && (var_a0 = 0x3C, (temp_v0 == 0)))
        {
            if (((temp_s2 + var_a0) < ray_zdc_x) && (obj->main_etat == 0) && (bb1.speed_x != 0))
            {
                obj->flags |= 0x4000;
                set_main_and_sub_etat(obj, 2U, 1U);
                obj->speed_y = 2;
                return;
            }
        }
        else if ((obj->main_etat == 0) && (obj->sub_etat == 0) && ((var_a0 + temp_s2) < ray_zdc_x))
        {
            Phase = 1;
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1, 1);
                return;
            case 3:
                set_main_and_sub_etat(obj, 1, 2);
                return;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1, 0);
                return;
            }
        }
        else
        {
            return;
        }
        break;
    case 1:
        if ((obj->main_etat == 1) &&
          ((block_flags
            [*(ushort *)
              (((((int)((int)obj->x_pos + (uint)obj->offset_bx) >> 4) +
                (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000 >>
                0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0)) {
            set_main_and_sub_etat(obj, 2U, 4U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = -8;
            obj->speed_x = 3;
            return;
        }
        break;
    case 2:
        if ((obj->main_etat == 1) &&
          ((block_flags
            [*(ushort *)
              (((((int)((int)obj->x_pos + (obj->offset_bx - 8)) >> 4) +
                (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000 >>
                0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0)) {
            set_main_and_sub_etat(obj, 2U, 1U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = 0;
            obj->speed_x = 0;
            bb1.field1_0x2 = -1;
            return;
        }
        break;
    case 3:
        if (scroll_end_x < 0x15CC)
        {
            var_v1 = 0x15CC;
        }
        scroll_end_x = var_v1;
        
        if (((temp_s2 + 0x20) < ray_zdc_x) && (bb1.field1_0x2 == -1) && (temp_s3 < ray_zdc_y))
        {
            if (bb1.speed_x != bb1.field1_0x2)
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
                bb1.field1_0x2 = 0;
            }
            else
            {
                temp_v0_2 = obj->field23_0x3c;
                temp_v0_3 = temp_v0_2 + 1; /* remove temp_v0_3 ? */
                if (temp_v0_2 < 0xC8)
                {
                    obj->field23_0x3c = temp_v0_3;
                    if (temp_v0_3 == 0x00C8)
                    {
                        bb1.speed_x = 1;
                        set_main_and_sub_etat(obj, 1U, 0U);
                        bb1.field1_0x2 = 0;
                        obj->field23_0x3c = 0x00FF;
                    }
                }
                scroll_end_x = xmap;
                if (xmap < temp_s2)
                {
                    var_v0_2 = xmap + ray.speed_x;
                    if (ray.speed_x <= 0)
                    {
                        var_v0_2 = xmap + 1;
                    }
                    scroll_end_x = var_v0_2;
                }
            }
        }
        if (FinAnim != 0)
        {
            if ((obj->main_etat == 0) && (obj->sub_etat == 0x10))
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
            }
            if ((FinAnim != 0) && (obj->main_etat == 0) && (obj->sub_etat == 1))
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
            }
        }
        if (obj->main_etat == 1)
        {
            if ((block_flags
                [*(ushort *)
                  (((((int)((int)obj->x_pos + (obj->offset_bx - 8)) >> 4) +
                    (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
                    >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                obj->speed_y = -6;
                obj->speed_x = 3;
                set_main_and_sub_etat(obj, 2U, 4U);
                obj->gravity_value_2 = 5;
                obj->gravity_value_1 = 0;
            }
            if ((obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U))
            {
                if (ray_zdc_y < (temp_s3 - 0x20))
                {
                    set_main_and_sub_etat(obj, 0U, 0x10U);
                    obj->speed_y = 0;
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 1U);
                    obj->speed_y = 0;
                }
                obj->speed_x = 0;
                return;
            }
        }
        break;
    case 4:
        if (bb1.sprite6_y < scroll_end_y)
        {
            scroll_end_y -= 1;
        }
        if (FinAnim != 0)
        {
            temp_v1 = obj->main_etat;
            if ((temp_v1 == 2) && (obj->sub_etat == temp_v1))
            {
                bb1.speed_x = 1;
                goto block_124;
            }
            if ((obj->main_etat == 0) && (obj->sub_etat == 5))
            {
                temp_v0_4 = bb1.sprite6_x + 1;
                bb1.sprite6_x = temp_v0_4;
                if ((s16) temp_v0_4 < 3)
                {
                    bb1.speed_x = 1;
block_124:
                    set_main_and_sub_etat(obj, 1U, 0U);
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 2U);
                    Phase = 5;
                    bb1.sprite6_y = ymap;
                }
            }
        }
        var_v0_3 = temp_s2 << 0x10;
        if (obj->main_etat == 1)
        {
            temp_v1_2 = obj->offset_bx;
            var_v0_4 = temp_v1_2 + 0x10;
            if (!(obj->flags & 0x4000))
            {
                var_v0_4 = temp_v1_2 - 0x10;
            }
            var_v0_3 = temp_s2 << 0x10;
            if ((block_flags
                [*(ushort *)
                  ((((obj->x_pos + var_v0_4 >> 4) +
                    (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
                    >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                obj->speed_y = 0;
                obj->speed_x = 0;
                obj->flags = (obj->flags & ~0x4000) | (((1 - (((u32) obj->flags >> 0xE) & 1)) & 1) << 0xE);
                set_main_and_sub_etat(obj, 0U, 5U);
                var_v0_3 = temp_s2 << 0x10;
            }
        }
        if (((var_v0_3 >> 0x10) - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) < 0xFB)
            {
                return;
            }
            goto block_172;
        }
        var_v1_2 = ((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) < 0xFB;
block_171:
        if (var_v1_2 == 0)
        {
block_172:
            obj->flags &= ~0x400;
            IsBossThere = 0;
            Phase = 0;
            scroll_end_x = (s16) (u16) xmapmax;
            scroll_end_y = (s16) (u16) ymapmax;
            obj->flags &= ~0x800;
        }
        break;
    case 5:
        if (bb1.field1_0x2 < 0)
        {
            scroll_end_y = (u16) bb1.sprite6_y - horloge[5];
            bb1.field1_0x2 = (s16) ((u16) bb1.field1_0x2 + 1);
        }
        if (FinAnim != 0)
        {
            if (obj->main_etat == 0)
            {
                if (obj->sub_etat == 5)
                {
                    bb1.speed_x = 3;
                    switch (bb1.speed_x)
                    {
                    case 2:
                        set_main_and_sub_etat(obj, 1U, 1U);
                        break;
                    case 3:
                        set_main_and_sub_etat(obj, 1U, 2U);
                        break;
                    default:
                        set_main_and_sub_etat(obj, 1U, 0U);
                        break;
                    }
                }
                goto block_147;
            }
        }
        else
        {
block_147:
            if ((obj->main_etat == 0) && (obj->sub_etat == 2))
            {
                if (FinAnim != 0)
                {
                    bb1.speed_x = 2;
                    switch (bb1.speed_x)
                    {
                    case 2:
                        set_main_and_sub_etat(obj, 1U, 1U);
                        break;
                    case 3:
                        set_main_and_sub_etat(obj, 1U, 2U);
                        break;
                    default:
                        set_main_and_sub_etat(obj, 1U, 0U);
                        break;
                    }
                }
                else if ((obj->anim_frame == 0x15) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
                {
                    bb1.field1_0x2 = -0x001E;
                }
            }
        }
        var_v0_5 = temp_s2 << 0x10;
        if (obj->main_etat == 1)
        {
            temp_v1_3 = obj->offset_bx;
            var_v0_6 = temp_v1_3 + 0x10;
            if (!(obj->flags & 0x4000))
            {
                var_v0_6 = temp_v1_3 - 0x10;
            }
            var_v0_5 = temp_s2 << 0x10;
            if ((block_flags
           [*(ushort *)
             ((((obj->x_pos + var_v0_6 >> 4) +
               (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
              >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                if (bb1.speed_x == 3)
                {
                    set_main_and_sub_etat(obj, 2U, 4U);
                    obj->gravity_value_2 = 0xFF;
                    obj->gravity_value_1 = 0;
                    obj->speed_y = -2;
                    obj->speed_x = 4;
                    scroll_end_y = (s16) (u16) ymapmax;
                    scroll_end_x = (s16) (u16) xmapmax;
                    var_v0_5 = temp_s2 << 0x10;
                }
                else
                {
                    obj->speed_y = 0;
                    obj->speed_x = 0;
                    obj->flags = (obj->flags & ~0x4000) | (((1 - (((u32) obj->flags >> 0xE) & 1)) & 1) << 0xE);
                    set_main_and_sub_etat(obj, 0U, 5U);
                    var_v0_5 = temp_s2 << 0x10;
                }
            }
        }
        if (((var_v0_5 >> 0x10) - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) < 0x191)
            {
                return;
            }
            goto block_172;
        }
        var_v1_2 = ((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) < 0x191;
        goto block_171;
    }
}