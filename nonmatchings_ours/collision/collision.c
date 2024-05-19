#include "collision/collision.h"

/* matches, but ???
0xA5 switch main_etat then if/else sub_etat
later case switch sub_etat then switch main_etat

BOX_IN_COLL_ZONES seems to need s16 return */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);*/

s16 in_coll_sprite_list(Obj *obj, s16 param_2)
{
    u8 sp[16];
    s16 i;
    u8 var_v0;
    s16 temp_a0;
    
    switch(obj->type)
    {
    case 0x14:
        sp[0] = 0;
        sp[1] = 1;
        sp[2] = 2;
        sp[3] = 0xFF;
        break;
    case 0xA5:
        switch (obj->main_etat)
        {
        case 0:
            if (obj->sub_etat == 0xF || obj->sub_etat == 0x10)
                sp[0] = 4;
            else if (obj->sub_etat == 0x11)
                sp[0] = 4;
            else
                sp[0] = 2;
            break;
        default:
            sp[0] = 2;
            break;
        }

        sp[1] = 0xFF;
        break;
    case 0xD9:
    case 0x64:
        sp[0] = 1;
        switch (obj->sub_etat)
        {
        case 0x0B:
            switch (obj->main_etat)
            {
            case 2:
                sp[1] = 3;
                break;
            default:
                if (obj->anim_frame >= 0x10U)
                    sp[1] = 2;
                else
                    sp[1] = 0xFF;
                break;
            }
            sp[2] = 0xFF;
            break;
        default:
            sp[1] = 0xFF;
            break;
        }
        break;
    default:
        sp[0] = 0;
        sp[1] = 0xFF;
        break;
    }
    i = 0;
    do
    {
        temp_a0 = param_2 == sp[i];
        i++;
        if(sp[i] == 0xFF) break;
    } while (temp_a0 != 1);

    return temp_a0;
}

/* matches, but cleanup
return is either s32 with cast or s16 */
/* 1C034 80140834 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_SPRITE_ZDC);*/

s32 GET_SPRITE_ZDC(Obj *obj, s16 index, s16 *param_3, s16 *param_4, s16 *param_5, s16 *param_6)
{
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    u16 sp1E;
    s16 *sp20;
    s32 temp_v1;
    s32 var_a1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s6;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    u16 var_v0_3;
    s16 temp_s5;
    u8 temp_v1_2;

    var_s7 = 0;
    var_s6 = 0;
    var_s2 = 0;
    temp_s5 = obj->type;
    var_s3 = 0;
    var_a1 = GET_SPRITE_POS(obj, index, &sp18, &sp1A, &sp1C, &sp1E);
    if ((s16) var_a1 != 0)
    {
        switch (temp_s5)
        {
        case 0x51:
            switch (index)
            {
            case 3:
                var_s3 = 4;
                var_s2 = 2;
                var_s6 = -4;
                var_s7 = -0xA;
                break;
            case 4:
                var_s3 = 0;
                var_s2 = 2;
                var_s6 = 0;
                var_s7 = -0xA;
                break;
            case 5:
                var_s3 = 0;
                var_s2 = 2;
                var_s6 = -4;
                var_s7 = -0xA;
                break;
            }
            break;
        case 0x14:
            temp_v1_2 = obj->main_etat;
            if (((temp_v1_2 == 0) && (obj->sub_etat == 0)) || ((temp_v1_2 == 1) && (obj->sub_etat == 0)))
            {
                switch (index)
                {
                case 0:
                    var_s3 = 0xA;
                    var_s2 = 0;
                    sp1C = 0x0022;
                    var_v0_3 = 0x0020;
                    sp1E = var_v0_3;
                    break;
                case 1:
                    var_s3 = 4;
                    var_s2 = 0;
                    sp1C = 0x001A;
                    break;
                case 2:
                    var_s3 = 4;
                    var_s2 = 0;
                    sp1C = 0x0030;
                    var_v0_3 = 0x0018;
                    sp1E = var_v0_3;
                    break;
                }
            }
            else if ((obj->main_etat == 0) && (obj->sub_etat == 1))
            {
                sp1C = 0x0020;
                sp1E = 0x0010;
                sp18 = (u16) obj->x_pos + 0x70;
                sp1A = (u16) obj->y_pos + 0xB8;
            }
            else
            {
                sp1C = 0;
                sp1E = 0;
                var_a1 = 0;
            }
            break;
        case 0xA5:
            if (index != 2)
            {
                if (index == 4)
                {
                    var_s3 = -3;
                    var_s2 = 0;
                    sp1C = 0x0015;
                    var_v0_3 = 0x000A;
                    sp1E = var_v0_3;
                    break;
                }
            }
            else
            {
                var_s3 = 1;
                var_s2 = -4;
                var_s6 = -2;
                var_s7 = 6;
            }
            break;
        case 0x64:
        case 0xD9:
            switch (index)
            {
            case 1:
                var_s3 = 1;
                if (obj->main_etat == 0)
                {
                    var_s3 = -8;
                    if (obj->sub_etat == 9 || obj->sub_etat == 0x0A || (obj->sub_etat == 0x0B))
                    {
                        var_s2 = 5;
                        sp1C = 0x001A;
                        var_v0_3 = 8;
                    }
                    else
                    {
                        var_s3 = 1; /* duplicate? */
                        var_s2 = -5;
                        sp1C = 0x0010;
                        var_v0_3 = 0x001E;
                    }
                }
                else
                {
                    var_s2 = -5;
                    sp1C = 0x0010;
                    var_v0_3 = 0x001E;
                }
                sp1E = var_v0_3;
                break;
            case 2:
                var_s3 = 0;
                var_s2 = 7;
                var_v0_3 = 0x0010;
                sp1C = 0x0010;
                sp1E = var_v0_3;
                break;
            case 3:
                var_s3 = 0;
                var_s2 = 2;
                sp1C = 0x000D;
                var_v0_3 = 9;
                sp1E = var_v0_3;
                break;
            }
            break;
        }
        *param_3 = var_s3 + (u16) sp18;
        *param_4 = var_s2 + (u16) sp1A;
        *param_5 = var_s6 + sp1C;
        *param_6 = var_s7 + sp1E;
    }
    return (s16)var_a1;
}

/* matches, but did not find a good place for missing_addiu nop */
/* 1C3F8 80140BF8 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_HIT_SPECIAL_ZDC);*/

/*void GET_BB1_ZDCs(Obj *obj,s16 *param_2,s16 *param_3,s16 *param_4,s16 *param_5,
                 s16 *param_6,s16 *param_7,s16 *param_8,s16 *param_9);*/

s32 BOX_HIT_SPECIAL_ZDC(s16 in_x, s16 in_y, s16 in_w, s16 in_h, Obj *obj)
{
  u8 frame;
  s16 d;
  s16 bb1_x_1; s16 bb1_y_1; s16 bb1_w_1; s16 bb1_h_1;
  s16 bb1_x_2; s16 bb1_y_2; s16 bb1_w_2; s16 bb1_h_2;
  s16 res = -1;

  switch(obj->type)
  {
  case TYPE_BAG1:
    frame = obj->anim_frame;
    d = bagD[frame];
    if (d != -1)
    {
      if ((s16) inter_box(
        in_x, in_y, in_w, in_h,
        obj->x_pos + obj->offset_bx - (bagW[frame] >> 0x1),
        obj->y_pos + obj->offset_by + d - bagH[frame],
        bagW[frame],
        bagH[frame]
      ))
        res = 1;
    }
    break;
  case TYPE_BB1:
  case TYPE_BB12: 
  case TYPE_BB13:
  case TYPE_BB14:
    if (in_h == ray_zdc_h)
    {
      GET_BB1_ZDCs(
        obj,
        &bb1_x_1, &bb1_y_1, &bb1_w_1, &bb1_h_1,
        &bb1_x_2, &bb1_y_2, &bb1_w_2, &bb1_h_2
      );
      
      /* TODO: write a bit nicer, not sure how yet */
      if (!(s16) inter_box(
        in_x, in_y, in_w, in_h,
        bb1_x_1, bb1_y_1, bb1_w_1, bb1_h_1
      ))
      {
        if ((s16) inter_box(
          in_x, in_y, in_w, in_h,
          bb1_x_2, bb1_y_2, bb1_w_2, bb1_h_2
        ))
          res = 1;
      }
      else
        res = 1;
    }
    else {
      GET_BB1_ZDCs(
        obj,
        &bb1_x_1, &bb1_y_1, &bb1_w_1, &bb1_h_1,
        &bb1_x_2, &bb1_y_2, &bb1_w_2, &bb1_h_2
      );

      if ((s16) inter_box(
        in_x, in_y, in_w, in_h,
        bb1_x_1, bb1_y_1, bb1_w_1, bb1_h_1
      ))
        res = 6;
      if ((s16) inter_box(
        in_x, in_y, in_w, in_h,
        bb1_x_2, bb1_y_2, bb1_w_2, bb1_h_2
      ))
        res = 1;
      
      if (obj->main_etat == 0 && obj->sub_etat == 10)
      {
        GET_SPRITE_POS(obj, 9, &bb1_x_1, &bb1_y_1, &bb1_h_1, &bb1_w_1);
        if ((s16) inter_box(
          in_x, in_y, in_w, in_h,
          bb1_x_1, bb1_y_1, bb1_w_1, bb1_h_1
        ))
          res = 9;
      }
    }
    break;
  }
  return res;
}

/* made some ok progress
previous comment:
??? tried gotos-only, both m2c and ghidra
param_1 is ObjType */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_IN_COLL_ZONES);*/

s32 BOX_IN_COLL_ZONES(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, Obj *obj)
{
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    s16 sp28;
    s16 sp30;
    Animation *temp_v1_3;
    ZDC *temp_v0_1;
    s16 temp_a1_3;
    s16 temp_v1_4;
    s16 var_s2_1;
    s16 var_s2_2;
    s16 var_v0_3;
    s16 temp_v0_2;
    s32 temp_v1_6;
    s32 var_s5;
    s16 var_v0_1;
    s32 var_v0_2;
    u16 temp_a1_1;
    s16 nb_zdc;
    u8 temp_a0;
    u8 temp_a1_2;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_5;
    s32 test_1;

    sp26 = 0;
    sp24 = 0;
    sp22 = 0;
    sp20 = 0;
    var_v0_1 = -1;
    if (obj->zdc != 0)
    {
        nb_zdc = get_nb_zdc(obj);
        if (num_world == 1)
        {
            if (
              ((obj->type == 0x32 || obj->type == 0xE3) && !(obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)) ||
              (obj->type == 0xA5 && obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
            )
                nb_zdc--;
        }
        var_s2_1 = 0;
        /* load param_1 into test_1 here instead? */
        while (var_s2_1 < nb_zdc)
        {
            temp_v0_1 = get_zdc(obj, var_s2_1);
            temp_v1_2 = temp_v0_1->flags;
            if (!(temp_v1_2 & 4) || (param_1 == 0x005E))
            {
                if (temp_v1_2 & 2)
                {
                    temp_v1_3 = &obj->animations[obj->anim_index];
                    temp_a1_2 = temp_v0_1->sprite;
                    if (temp_v1_3->layers[(temp_v1_3->layers_count & 0x3FFF) * obj->anim_frame + temp_a1_2].sprite != 0)
                    {
                        GET_SPRITE_POS(obj, temp_a1_2, &sp20, &sp22, &sp24, &sp26);
                        if (obj->flags & 0x4000)
                        {
                            sp20 = sp20 + ((sp24 - temp_v0_1->width) - temp_v0_1->x_pos);
                        }
                        else
                        {
                            sp20 = sp20 + temp_v0_1->x_pos;
                        }
                        sp22 = sp22 + temp_v0_1->y_pos;
                        sp24 = temp_v0_1->width;
                        sp26 = temp_v0_1->height;
                    }
                }
                else
                {
                    temp_a1_3 = obj->x_pos + temp_v0_1->x_pos;
                    sp20 = temp_a1_3;
                    sp22 = obj->y_pos + temp_v0_1->y_pos;
                    temp_a0 = temp_v0_1->width;
                    sp24 = temp_a0;
                    sp26 = temp_v0_1->height;
                    if (obj->flags & 0x4000)
                    {
                        sp20 = ((obj->offset_bx + obj->x_pos)) + ((obj->offset_bx + obj->x_pos)) - (temp_a1_3 + temp_a0);
                    }
                }
                if ((s16) inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26))
                {
                    var_v0_1 = temp_v0_1->sprite;
                    break;
                }
            }
            var_s2_1++;
        }
    }
    else
    {
        temp_v1_5 = obj->hit_sprite;
        if (temp_v1_5 == 0xFE)
        {
            GET_OBJ_ZDC(obj, &sp20, &sp22, &sp24, &sp26);
            if (obj->flags & 0x4000)
            {
                sp20 = ((obj->offset_bx + obj->x_pos)) + ((obj->offset_bx + obj->x_pos)) - (sp20 + sp24);
            }

            /* check pc? */
            temp_v0_2 = inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26);
            if (!temp_v0_2)
                var_v0_1 = -1;
            else
                var_v0_1 = temp_v0_2;
        }
        else
        {
            var_v0_1 = -1;
            if (temp_v1_5 == 0xFF)
            {
                var_s2_2 = 0;
                temp_v1_6 = obj->animations[obj->anim_index].layers_count & 0x3FFF;
                while (var_s2_2 < temp_v1_6)
                {
                    if (
                        in_coll_sprite_list(obj, var_s2_2) &&
                        (s16) GET_SPRITE_ZDC(obj, var_s2_2, &sp20, &sp22, &sp24, &sp26) != 0 &&
                        ((s16) inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26))
                    )
                    {
                        var_v0_1 = var_s2_2;
                        break;
                    }
                    var_s2_2++;
                }
            }
        }
    }
    return var_v0_1;
}

/* matches, but clean up */
/* 1D66C 80141E6C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_BAG);*/

void SET_RAY_DIST_BAG(Obj *obj)
{
  s16 x; s16 y; s16 w; s16 h;
  s16 temp_v0;
  s16 new_dist = 0;
  if (obj->sub_etat == 3 || (obj->sub_etat == 6 && obj->anim_frame < 12))
  {
    GET_SPRITE_POS(obj, obj->follow_sprite, &x, &y, &w, &h);
    y += obj->offset_hy;
    temp_v0 = w;
    w = 45;
    x += ((s16) (temp_v0 - w) >> 1);
    new_dist = setToleranceDist(x, w, y);
  }
  else
    new_dist = 10000;
  
  if (ray.field20_0x36 == obj->id && obj->sub_etat == 6 && obj->anim_frame == 11)
  {
    ray.field20_0x36 = -1;
    set_main_and_sub_etat(&ray, 2, 0);
    new_dist = 10000;
    ray.speed_y -= 10;
  }
  obj->ray_dist = new_dist;
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_POING_COLLISION);*/

/*void DO_BAT_POING_COLLISION(Obj *obj);
void DO_BBMONT_TOUCHE(Obj *obj);
void DO_DARK_POING_COLLISION(Obj *obj);
void DO_HYB_BBF2_POING_COLLISION(Obj *obj);
void DO_LEV_POING_COLLISION(Obj *obj);
void DO_NGW_POING_COLLISION(Obj *obj);
void DO_NOTE_TOUCHEE(Obj *obj);
void DO_PAR_POING_COLLISION(Obj *obj,s16 param_2);
void DO_PIRATE_POELLE_POING_COLLISION(Obj *obj);
void DO_PMA_POING_COLLISION(Obj *obj);
void DO_SKO_HIT(Obj *obj);
void DO_SPIDER_PLAFOND_POING_COLLISION(Obj *obj);
void DO_TOTEM_TOUCHE(Obj *obj,s16 param_2);
void doMoskitoHit(Obj *obj);
void fin_poing_follow(Obj *obj,u8 param_2);
u8 PS1_BTYPAbsPos(s32 x,s32 y);*/
s16 ANGLE_RAYMAN(Obj *obj);

void DO_POING_COLLISION(void)
{
    s16 pspr_x;
    s16 pspr_y;
    s16 pspr_w;
    s16 pspr_h;
    u8 var_a1_2;
    u8 var_a1_3;
    u8 var_a1_4;
    u8 var_a2;
    u8 var_a2_2;
    Obj *poing_obj;
    Obj *temp_v0_3;
    Obj *other_obj;
    s16 temp_a0;
    s16 temp_v0_1;
    s32 sprite;
    s32 temp_v0_5;
    s16 pspeed_x;
    s16 var_a1;
    s32 var_s2_2;
    s16 i;
    s16 var_v0_2;
    s32 test_4;
    s32 temp_v0_4;
    s32 temp_v1_2;
    u8 btyp;
    s32 var_v0_5;
    s32 var_v1;
    u32 temp_v1_3;
    u32 var_v0_3;
    u8 temp_a1_2;
    u8 old_hp;
    u8 temp_v0_8;
    u8 temp_v1_1;
    s32 temp_v1_4;
    u8 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 fall_x_accel;
    s16 test_1;
    s32 test_2;
    s32 test_3;
    int new_var;
    u8 correct_pos;

    poing_obj = &level.objects[poing_obj_id];
    btyp = 0;
    /* TODO: already being weird in multiple ways */
    GET_SPRITE_POS(poing_obj, 0, &pspr_x, &pspr_y, &pspr_w, &pspr_h);
    if ((temp_v0_1 = poing_obj->speed_x) > 0 || poing_obj->speed_x < 0)
        btyp = PS1_BTYPAbsPos(
            poing_obj->x_pos + poing_obj->offset_bx,
            poing_obj->y_pos + ((poing_obj->offset_by + poing_obj->offset_hy) >> 1)
        );
    if (block_flags[btyp] >> BLOCK_SOLID & 1)
    {
        do_boum();
        fin_poing_follow(poing_obj, true);
    }
    else
    {
        i = 0;
        other_obj = &level.objects[actobj.objects[i]];
        while (i < actobj.num_active_objects)
        {
            if (new_world != 0 || new_level != 0 || fin_boss != 0)
                break;
        
            if (
                other_obj->display_prio != 0 && other_obj->hit_points != 0 &&
                other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & (1 << 3)
            )
            {
                sprite = CHECK_BOX_COLLISION(TYPE_POING, pspr_x, pspr_y, pspr_w, pspr_h, other_obj);
                if (sprite != -1)
                {
                    old_hp = other_obj->hit_points;
                    switch (other_obj->type)
                    {
                    case TYPE_HYBRIDE_STOSKO:
                        if (
                            sprite == 6 && !poing.is_returning &&
                            other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & (1 << 0)
                        )
                        {
                            poing.damage = 1;
                            obj_hurt(other_obj);
                            if (other_obj->hit_points != 0)
                            {
                                if (other_obj->sub_etat == 2)
                                    set_sub_etat(other_obj, 4);
                                else
                                    set_sub_etat(other_obj, 13);
                            }
                            else
                            {
                                if (other_obj->sub_etat == 2)
                                {
                                    level.objects[other_obj->field24_0x3e].flags &= ~FLG(OBJ_ALIVE);
                                    DO_NOVA(&level.objects[other_obj->field24_0x3e]);
                                }
                                set_sub_etat(other_obj, 8);
                                other_obj->field23_0x3c = 1;
                            }
                        }
                        break;
                    case TYPE_HYBRIDE_MOSAMS:
                        if (
                            other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & (1 << 0) &&
                            (sprite == 3 || sprite == 6)
                        )
                        {
                            poing.damage = 1;
                            obj_hurt(other_obj);
                            if (other_obj->hit_points == 0)
                            {
                                skipToLabel(other_obj, 2, true);
                                other_obj->field23_0x3c = 1;
                            }
                            else
                                skipToLabel(other_obj, 4, true);
                        }
                        break;
                    case TYPE_SPACE_MAMA:
                    case TYPE_SPACE_MAMA2:
                        doMereDenisHit(other_obj, sprite);
                        break;
                    case TYPE_DARK:
                        DO_DARK_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_BATTEUR_FOU:
                        if (sprite == 2)
                            DO_BAT_POING_COLLISION(other_obj);
                        break;
                    case TYPE_MAMA_PIRATE:
                        if (sprite == 5)
                            DO_PMA_POING_COLLISION(other_obj);
                        break;
                    case TYPE_MOSKITO:
                    case TYPE_MOSKITO2:
                        doMoskitoHit(other_obj, sprite);
                        break;
                    case TYPE_ONEUP:
                        if (RayEvts.flags0 & FLG(RAYEVTS0_GRAP) && ray_mode != MODE_MORT_DE_RAYMAN)
                            poing_obj->field20_0x36 = other_obj->id;
                        break;
                    case TYPE_PT_GRAPPIN:
                        if (RayEvts.flags0 & FLG(RAYEVTS0_GRAP) && ray_mode != MODE_MORT_DE_RAYMAN)
                        {
                            temp_a1_2 = other_obj->offset_by;
                            temp_v1_2 = (ray.y_pos + ray.offset_by) - other_obj->y_pos;
                            /* TODO: how is this not __builtin_abs??? */
                            if (temp_v1_2 - temp_a1_2 >= 0)
                            {
                                if (temp_v1_2 - temp_a1_2 < 0xFA)
                                {
                                    goto block_47;
                                }
                            }
                            else if (temp_v1_2 - temp_a1_2 < 0 && -(temp_v1_2 - temp_a1_2) < 0xFA)
                            {
block_47:
                                SET_RAY_BALANCE();
                                id_obj_grapped = other_obj->id;
                                temp_v0_5 = ANGLE_RAYMAN(other_obj);
                                other_obj->follow_x = temp_v0_5;
                                if (temp_v0_5 > 256) /* sub 256 then sgn? */
                                    other_obj->field24_0x3e = -1;
                                else if (temp_v0_5 <= 256)
                                {
                                    if(temp_v0_5 == 256 && !(ray.flags & FLG(OBJ_FLIP_X)))
                                        other_obj->field24_0x3e = -1;
                                    else
                                        other_obj->field24_0x3e = 1;
                                }
                                else /* TODO: ??? */
                                    other_obj->field24_0x3e = 1;
                                
                                if ((other_obj->main_etat == 0) && (other_obj->sub_etat == 0))
                                {
                                    skipToLabel(other_obj, 0, true);
                                }
                                poing.is_active = 0;
                                poing.is_returning = 0;
                                poing_obj->flags &= ~FLG(OBJ_ALIVE);
                                poing_obj->flags &= ~FLG(OBJ_ACTIVE);
                                fin_poing_follow(poing_obj, false);
                            }
                        }
                        break;
                    case TYPE_CAISSE_CLAIRE:
                        if (!(other_obj->main_etat == 0 && other_obj->sub_etat == 2))
                        {
                            set_main_and_sub_etat(other_obj, 1, 1);
                            if (!(other_obj->flags & FLG(OBJ_FLIP_X)))
                            {
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                                skipToLabel(other_obj, 3, true);
                            }
                            else
                            {
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                                skipToLabel(other_obj, 2, true);
                            }
                        }
                        break;
                    case TYPE_BLACKTOON1:
                        obj_hurt(other_obj);
                        if (other_obj->hit_points == 0)
                        {
                            set_main_and_sub_etat(other_obj, 0, 4);
                            other_obj->speed_y = 0;
                            /* TODO: rewriting this like TYPE_MORNINGSTAR_MOUNTAI didn't work */
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x >= 0)
                            {
                                if (pspeed_x > 0)
                                    other_obj->flags &= ~FLG(OBJ_FLIP_X);
                                else /* temp_v0_6 == 0 */
                                {
                                    if (poing_obj->flags & FLG(OBJ_FLIP_X))
                                        other_obj->flags &= ~FLG(OBJ_FLIP_X);
                                    else
                                        other_obj->flags |= FLG(OBJ_FLIP_X);
                                }
                            }
                            else if (pspeed_x < 0)
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                            
                            allocateBlacktoonEyes(other_obj);
                            if (other_obj->flags & FLG(OBJ_FLIP_X))
                                skipToLabel(other_obj, 2, true);
                            else
                                skipToLabel(other_obj, 3, true);
                            break;
                        }
                        break;
                    case TYPE_MORNINGSTAR_MOUNTAI:
                        if (sprite == 4 && other_obj->sub_etat == 5)
                        {
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x >= 0 && (pspeed_x > 0 || poing_obj->flags & FLG(OBJ_FLIP_X)))
                                set_sub_etat(other_obj, 9);
                            else
                                set_sub_etat(other_obj, 6);
                        }
                        break;
                    case TYPE_KILLING_EYES:
                        if (--other_obj->hit_points)
                        {
                            set_sub_etat(other_obj, 5);
                            other_obj->iframes_timer = 50;
                        }
                        else
                            set_sub_etat(other_obj, 6);
                        break;
                    case TYPE_PIRATE_GUETTEUR:
                    case TYPE_PIRATE_GUETTEUR2:
                        DO_PAR_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_PIRATE_NGAWE:
                        DO_NGW_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_CAGE:
                        obj_hurt(other_obj);
                        if (other_obj->hit_points == 0)
                        {
                            other_obj->init_main_etat = 0;
                            other_obj->init_sub_etat = 8;
                            other_obj->init_x_pos = other_obj->x_pos;
                            other_obj->init_y_pos = other_obj->y_pos;
                            set_sub_etat(other_obj, 12);
                            other_obj->init_flag = 7;
                            ALLOCATE_MEDAILLON_TOON();
                            lidol_to_allocate = 5;
                            lidol_source_obj = other_obj;
                            Nb_total_cages++;
                            take_bonus(other_obj->id);
                        }
                        else
                            set_sub_etat(other_obj, 10);
                        break;
                    case TYPE_BB1:
                        if (sprite == 9)
                            DO_BBMONT_TOUCHE(other_obj);
                        break;
                    case TYPE_NOTE0:
                    case TYPE_NOTE1:
                    case TYPE_NOTE2:
                    case TYPE_BONNE_NOTE:
                    case TYPE_NOTE3:
                        DO_NOTE_TOUCHEE(other_obj, sprite);
                        break;
                    case TYPE_TOTEM:
                        DO_TOTEM_TOUCHE(other_obj, sprite);
                        break;
                    case TYPE_PI_MUS:
                        if (other_obj->main_etat == 0 && Mus_obj_id >= 0)
                        {
                            PlaySnd(83, other_obj->id);
                            other_obj->hit_points--;
                            switch (other_obj->hit_points)
                            {
                            case 3:
                                set_sub_etat(other_obj, 4);
                                allocateEclatPS(other_obj, 7);
                                set_sub_etat(&level.objects[Mus_obj_id], 6);
                                break;
                            case 2:
                                set_sub_etat(other_obj, 6);
                                allocateEclatPS(other_obj, 8);
                                break;
                            case 1:
                                set_sub_etat(other_obj, 8);
                                allocateEclatPS(other_obj, 9);
                                break;
                            case 0:
                                if (level.objects[Mus_obj_id].sub_etat == 6)
                                {
                                    PlaySnd(83, other_obj->id);
                                    set_sub_etat(other_obj, 9);
                                    level.objects[Mus_obj_id].sub_etat = 3;
                                    level.objects[Mus_obj_id].init_sub_etat = 4;
                                    other_obj->init_sub_etat = 10;
                                }
                                break;
                            }
                        }
                        break;
                    case TYPE_PI:
                        if (other_obj->main_etat == 0)
                        {
                            obj_hurt(other_obj);
                            if (other_obj->hit_points == 0)
                            {
                                DO_PI_EXPLOSION(other_obj);
                                other_obj->flags &= ~FLG(OBJ_ACTIVE);
                                if (ray.field20_0x36 == other_obj->id)
                                {
                                    ray.field20_0x36 = -1;
                                    other_obj->ray_dist = 1000;
                                    set_main_and_sub_etat(&ray, 2, 2);
                                }
                                other_obj->flags &= ~FLG(OBJ_ALIVE);
                            }
                            else
                            {
                                set_sub_etat(other_obj, 1);
                                other_obj->anim_frame = 0;
                            }
                        }
                        break;
                    case TYPE_LEVIER:
                        DO_LEV_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_SPIDER:
                        obj_hurt(other_obj);
                        if (other_obj->hit_points == 0)
                        {
                            set_main_and_sub_etat(other_obj, 0, 7);
                            other_obj->anim_frame = 0;
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                        }
                        else
                        {
                            if (
                                other_obj->main_etat == 0 &&
                                (other_obj->sub_etat == 2 || other_obj->sub_etat == 3 || other_obj->sub_etat == 4 || other_obj->sub_etat == 5)
                            )
                                other_obj->cmd_context_index = 0xFF;
                            other_obj->field23_0x3c = 0;
                            if (level.objects[poing_obj_id].speed_x > 0)
                            {
                                skipToLabel(other_obj, 3, true);
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                            }
                            else
                            {
                                skipToLabel(other_obj, 1, true);
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                            }
                            pushToLabel(other_obj, 6, true);
                            other_obj->anim_frame = 0;
                            pushToLabel(other_obj, 7, true);
                        }
                        break;
                    case TYPE_STONEDOG:
                    case TYPE_STONEDOG2:
                        obj_hurt(other_obj);
                        if (other_obj->hit_points != 0)
                        {
                            skipToLabel(other_obj, 5, true);
                            other_obj->gravity_value_2 = 7;
                            other_obj->change_anim_mode = ANIMMODE_RESET;
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x > 0)
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                            else if (pspeed_x < 0)
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                        }
                        else
                        {
                            set_main_and_sub_etat(other_obj, 0, 3);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            break;
                        }
                        break;
                    case TYPE_STONEBOMB:
                    case TYPE_STONEBOMB2:
                    case TYPE_STONEBOMB3:
                        set_sub_etat(other_obj, 1);
                        DO_STONE_EXPLOSION(other_obj);
                        break;
                    case TYPE_STONEMAN1:
                    case TYPE_STONEMAN2:
                        DO_PNG_COLL_STONEMAN(other_obj);
                        break;
                    case TYPE_STONEWOMAN2:
                    case TYPE_STONEWOMAN:
                        DO_PNG_COLL_STONEWOMAN(other_obj);
                        break;
                    case TYPE_PLATFORM:
                        if (sprite == other_obj->hit_sprite) /* tempted to rename "sprite" */
                        {
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x > 0)
                                set_sub_etat(other_obj, 25);
                            else if (pspeed_x < 0)
                                set_sub_etat(other_obj, 26);
                        }
                        break;
                    case TYPE_FALLING_OBJ:
                    case TYPE_FALLING_OBJ2:
                    case TYPE_FALLING_OBJ3:
                    case TYPE_FALLING_YING:
                    case TYPE_FALLING_YING_OUYE:
                        switch (other_obj->type)
                        {
                        case TYPE_FALLING_OBJ:
                        case TYPE_FALLING_OBJ2:
                        case TYPE_FALLING_OBJ3:
                            PlaySnd(44, other_obj->id);
                            break;
                        case TYPE_FALLING_YING:
                        case TYPE_FALLING_YING_OUYE:
                            PlaySnd(139, other_obj->id);
                            break;
                        }
                        
                        switch (poing.sub_etat)
                        {
                        case 1:
                        case 3:
                        case 5:
                            fall_x_accel = poing.damage;
                            break;
                        case 8:
                        case 10:
                        case 12:
                            fall_x_accel = poing.damage - 2;
                        case 2:
                        case 4:
                        case 6:
                        case 7:
                        case 9:
                        case 11:
                            break;
                        }
                        fall_x_accel = fall_x_accel * 5 + 10;
                        if (poing_obj->speed_x < 0)
                            fall_x_accel = -fall_x_accel;
                        make_my_fruit_go_down(other_obj, fall_x_accel);
                        break;
                    case TYPE_TARZAN:
                        set_main_and_sub_etat(other_obj, 0, 1);
                        other_obj->cmd = GO_LEFT;
                        break;
                    case TYPE_GENEBADGUY:
                        if (sprite == 0)
                        {
                            poing.damage = 1;
                            obj_hurt(other_obj);
                            if (other_obj->hit_points == 0)
                                skipToLabel(other_obj, 4, true);
                            else
                                skipToLabel(other_obj, 3, true);
                        }
                        else
                            skipToLabel(other_obj, 2, true);
                        break;
                    case TYPE_CHASSEUR1:
                    case TYPE_CHASSEUR2:
                        /* CLEANUP: NEXT */
                        if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 1)
                        {
                    case TYPE_FISH: /* TODO: fall-through? */
                            obj_hurt(other_obj);
                            if (other_obj->hit_points != 0)
                            {
                                other_obj->speed_x = 0;
                                other_obj->speed_y = 0;
                                set_main_and_sub_etat(other_obj, 0, 1);
                            }
                            else
                            {
                                set_main_and_sub_etat(other_obj, 0, 3);
                            }
                            if (other_obj->type == TYPE_FISH)
                            {
                                DESACTIVE_FISH_COLLIS(other_obj);
                            }
                            if (!(other_obj->flags & 0x4000))
                            {
                                other_obj->cmd = 0;
                            }
                            else
                            {
                                other_obj->cmd = 1;
                            }
                        }
                        break;
                    case TYPE_BADGUY2:
                    case TYPE_BADGUY3:
                        if ((sprite == 0x00FF) || (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 1))
                        {
                            obj_hurt(other_obj);
                            if (other_obj->hit_points == 0)
                            {
                                set_main_and_sub_etat(other_obj, 0, 3);
                                skipToLabel(other_obj, 2, true);
                                other_obj->y_pos = (u16) other_obj->y_pos - 2;
                                other_obj->flags &= 0xFFFF7FFF;
                            }
                            else
                            {
                                if (poing_obj->flags & 0x4000)
                                {
                                    pspeed_x = poing_obj->speed_x;
                                    if (pspeed_x >= 0)
                                    {
                                        var_a1_3 = 3;
                                        skipToLabel(other_obj, var_a1_3, true);
                                    }
                                    else if (pspeed_x < -1)
                                    {
                                        var_a1_3 = 2;
                                        skipToLabel(other_obj, var_a1_3, true);
                                    }
                                }
                                else
                                {
                                    pspeed_x = poing_obj->speed_x;
                                    var_a1_3 = 3;
                                    if (pspeed_x >= 2)
                                    {
                                        skipToLabel(other_obj, var_a1_3, true);
                                    }
                                    else if (pspeed_x <= 0)
                                    {
                                        var_a1_3 = 2;
                                        skipToLabel(other_obj, var_a1_3, true);
                                    }
                                }
                                other_obj->speed_x = 0;
                                other_obj->speed_y = -4;
                                other_obj->y_pos = (u16) other_obj->y_pos - 2;
                                set_main_and_sub_etat(other_obj, 2, 2);
                                PlaySnd(0x001C, other_obj->id);
                            }
                        }
                        break;
                    case TYPE_BADGUY1:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                        {
                            skipToLabel(other_obj, 3, true);
                        }
                        else if (pspeed_x < 0)
                        {
                            skipToLabel(other_obj, 2, true);
                        }
                        other_obj->speed_x = 0;
                        other_obj->y_pos = (u16) other_obj->y_pos - 2;
                        if (other_obj->hit_points != 0)
                        {
                            other_obj->speed_y = -4;
                            var_a2 = 2;
                            if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 0x40)
                            {
                                var_a2 = 0xA;
                            }
                            set_main_and_sub_etat(other_obj, 2, var_a2);
                            PlaySnd(0x001C, other_obj->id);
                            break;
                        }
                        other_obj->speed_y = -8;
                        var_a2_2 = 3;
                        if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 0x40)
                        {
                            var_a2_2 = 6;
                        }
                        set_main_and_sub_etat(other_obj, 0, var_a2_2);
                        break;
                    case TYPE_TROMPETTE:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                        {
                            var_v0_3 = other_obj->flags;
                            var_v0_3 &= ~0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        else if (pspeed_x < 0)
                        {
                            var_v0_3 = other_obj->flags | 0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        if (other_obj->hit_points == 0)
                        {
                            set_main_and_sub_etat(other_obj, 0, 1);
                            var_v1 = 0xFFFF7FFF;
                            other_obj->cmd = 2;
                            other_obj->flags &= var_v1;
                            break;
                        }
                        other_obj->y_pos = (u16) other_obj->y_pos - 2;
                        skipToLabel(other_obj, 4, true);
                        break;
                    case TYPE_BIG_CLOWN:
                    case TYPE_WAT_CLOWN:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                        {
                            var_v0_3 = other_obj->flags;
                            var_v0_3 &= ~0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        else if (pspeed_x < 0)
                        {
                            var_v0_3 = other_obj->flags | 0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        if (other_obj->hit_points != 0)
                        {
                            other_obj->y_pos = (u16) other_obj->y_pos - 2;
                            skipToLabel(other_obj, 4, true);
                            break;
                        }
                        set_main_and_sub_etat(other_obj, 0, 3);
                        var_v1 = 0xFFFF7FFF;
                        other_obj->cmd = 0;
                        other_obj->flags &= var_v1;
                        break;
                    case TYPE_CLOWN_TNT:
                    case TYPE_CLOWN_TNT2:
                    case TYPE_CLOWN_TNT3:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                        {
                            var_v0_3 = other_obj->flags;
                            var_v0_3 &= ~0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        else if (pspeed_x < 0)
                        {
                            var_v0_3 = other_obj->flags | 0x4000;
                            other_obj->flags = var_v0_3;
                        }
                        if (other_obj->hit_points != 0)
                        {
                            var_a1_2 = 5;
                            if (!(other_obj->flags & 0x4000))
                            {
                                var_a1_2 = 6;
                            }
                            skipToLabel(other_obj, var_a1_2, true);
                            break;
                        }
                        set_main_and_sub_etat(other_obj, 0, 2);
                        var_v1 = 0xFFFF7FFF;
                        other_obj->flags &= var_v1;
                        break;
                    case TYPE_MITE2:
                        if (sprite == 1)
                        {
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x > 0)
                            {
                                var_v0_3 = other_obj->flags;
                                var_v0_3 &= ~0x4000;
                                other_obj->flags = var_v0_3;
                            }
                            else if (pspeed_x < 0)
                            {
                                var_v0_3 = other_obj->flags | 0x4000;
                                other_obj->flags = var_v0_3;
                            }
                    case TYPE_MITE: /* TODO: fall-through? */
                            if (sprite == 1)
                            {
                                obj_hurt(other_obj);
                                if (other_obj->hit_points != 0)
                                {
                                    var_a1_2 = 4;
                                    skipToLabel(other_obj, 4, true);
                                    break;
                                }
                                set_main_and_sub_etat(other_obj, 0, 3);
                                var_v1 = 0xFFFF7FFF;
                                other_obj->flags &= var_v1;
                                break;
                            }
                        }
                        break;
                    case TYPE_SCORPION:
                        DO_SKO_HIT(other_obj, sprite);
                        break;
                    case TYPE_PIRATE_POELLE:
                    case TYPE_PIRATE_POELLE_D:
                    case TYPE_PIRATE_P_45:
                    case TYPE_PIRATE_P_D_45:
                        DO_PIRATE_POELLE_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_HYB_BBF2_D:
                    case TYPE_HYB_BBF2_G:
                        DO_HYB_BBF2_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_SPIDER_PLAFOND:
                        DO_SPIDER_PLAFOND_POING_COLLISION(other_obj, sprite);
                        break;
                    case TYPE_PRI:
                        if ((other_obj->screen_x_pos < (poing_obj->screen_x_pos + 0x1E)) && (other_obj->main_etat == 0) && (other_obj->sub_etat == 0))
                        {
                            skipToLabel(other_obj, 2, true);
                            other_obj->init_sub_etat = 2;
                            prise_branchee = 1;
                            finBosslevel[1] |= 4;
                        }
                        break;
                    case TYPE_POI3:
                        if ((other_obj->main_etat != 2) || (other_obj->sub_etat != 0x12))
                        {
                            skipToLabel(other_obj, 0xC, true);
                            other_obj->speed_x = 0;
                            other_obj->speed_y = 0;
                            other_obj->hit_points = 0;
                        }
                        break;
                    case TYPE_PETIT_COUTEAU:
                        temp_v1_7 = other_obj->hit_points;
                        if ((temp_v1_7 == 2) || (temp_v1_7 == 4))
                        {
                            other_obj->hit_points--;
                        }
                        break;
                    }
                    do_boum();
                    other_obj->gravity_value_1 = 0;
                    temp_v0_5 = other_obj->eta[other_obj->main_etat][other_obj->sub_etat].anim_speed >> 4;
                    if ((u32) ((temp_v0_5) - 0xA) >= 2U)
                    {
                        other_obj->gravity_value_2 = 0;
                    }
                    if ((other_obj->hit_points == old_hp) && (flags[other_obj->type].flags3 & 1))
                    {
                        PlaySnd(0x00D6, other_obj->id);
                    }
                    break;
                }
            }
            i++;
            other_obj = &level.objects[actobj.objects[i]];
        }
    }
    
}

/*
some bad instructions and reg swaps. not sure if i botched something
only got to ~3740 score with m2c
*/
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_DETECT_ZONE_FLAG);*/

void SET_DETECT_ZONE_FLAG(Obj *obj)
{
  s16 uVar1;
  short sVar2;
  u8 bVar3;
  short sVar4;
  u16 bVar5;
  short x;
  short y;
  s16 w;
  s16 h;
  s32 new_var1;
  s32 new_var2;
  s32 test_1;
  s32 test_2;
  s32 test_3;
  
  GET_ANIM_POS(obj,&x,&y,&w,&h);
  /*if (0xea < obj->type - 5) {
LAB_801448fc:
    standard_frontZone(obj,&x,&w);
    goto switchD_80144310_caseD_15;
  }*/
  sVar4 = h >> 1;
  sVar2 = w >> 1;
  switch(obj->type) {
  case 0x99:
    x = x + ((h >> 1) - (obj->detect_zone >> 1));
    y = y + -0x10;
    w = obj->detect_zone;
    h = h + 0x40;
    break;
  case 0x35:
    y = y + h;
    h = h + 0xf0;
    break;
  case 0x4d:
  case 0xef:
    standard_frontZone(obj,&x,&w);
    if ((obj->main_etat == 0) && (obj->sub_etat == 4)) {
      test_1 = (h >> 1);
      y = y + test_1;
      h = h + obj->detect_zone * 4 + test_1;
    }
    break;
  case 0x7b:
    new_var2 = -1;
    switch(obj->follow_sprite)
    {
    case 3:
      if ((obj->main_etat == 0) && (obj->sub_etat == 0)) {
        h = obj->detect_zone + h;
        y = y - obj->detect_zone;
        w = obj->detect_zone + w;
        x = x - (obj->detect_zone >> 1);
      }
      break;
    case 7:
      if (((obj->main_etat == 1)) && (obj->sub_etat == 1)) {
        x = x + new_var2 + (w >> 1);
        y = y + (h >> 1);
        w = 0x14;
        h = obj->detect_zone + h;
        if ((obj->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          x = x + -w;
        }
      }
      break;
    case 4:
      y = y - (obj->detect_zone + h);
      test_1 = w >> 1;
      w = w * 2;
      x = x - test_1;
      h = obj->detect_zone + h;
      break;
    case 2:
      y = y - (obj->detect_zone + h);
      h = obj->detect_zone + h;
      w = w + obj->detect_zone * 2;
      x = x - obj->detect_zone;
      break;
    }
    break;
  case 0x84:
    new_var1 = x;
    if ((obj->flags & FLG(OBJ_FLIP_X))) {
      new_var1 = x + w;
    }
    else
      new_var1 = x - w;
    x = new_var1;
    y = y + -0x32;
    h = h + 0x32;
    break;
  case 0x93:
    if (obj->hit_points != 0) {
      y = 0;
      h = mp.height << 4;
    }
    break;
  case 0xb5:
  case 199:
    x = obj->offset_bx + obj->x_pos;
    w = 0x10;
    y = 0;
    h = mp.height << 4;
    break;
  case 0x3d:
    h = (obj->detect_zone >> 1) + h;
    y = y - (obj->detect_zone >> 1);
    standard_frontZone(obj,&x,&w);
    break;
  case 0xe:
    h = obj->detect_zone;
    y = y - (obj->detect_zone >> 1);
    w = w + obj->detect_zone * 2;
    x = x - obj->detect_zone;
    break;
  case 5:
  case 0xc:
  case 0x14:
  case 0x51:
  case 0xa8:
  case 0xa9:
    w = w + obj->detect_zone * 2;
    x = x - obj->detect_zone;
    break;
  case 0x74:
    if (!(obj->flags & 0x4000))
    {
        x = x + ((w >> 0x1) - ((u8) obj->detect_zone >> 1));
    }
    else
    {
        x = x + (w >> 0x1);
    }
    w = (obj->detect_zone >> 1);
    y = y + (h >> 1);
    h = obj->detect_zone + (h >> 1);
    break;
  case 0x38:
  case 0xac:
    standard_frontZone(obj,&x,&w);
    h = h << 1;
    break;
  case 100:
    bVar3 = 0x96;
    if ((obj->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
      x = x - obj->detect_zone;
    }
    else {
      x = x + -bVar3 + (w >> 1);
    }
    w = obj->detect_zone + 0x96;
    y = y - ((obj->detect_zone - h) >> 1);
    h = obj->detect_zone;
    break;
  case 0xae:
  case 0xe1:
    standard_frontZone(obj,&x,&w);
    h = 0x96;
    break;
  case 0xb8:
  case 0xe2:
    standard_frontZone(obj,&x,&w);
    h = 0x96;
    x = x + 0x46;
    y = y + 0x32;
    break;
  case 0xc3:
    if (((obj->main_etat == 0) &&
        (((bVar5 = obj->sub_etat, bVar5 == 0x18 || (bVar5 == 0x1e)) || (bVar5 == 0xb)))) ||
       ((obj->main_etat == 1 && (obj->sub_etat == 2)))) {
      h = 10;
      x = x + -0x28;
      w = w + 0x50;
    }
    else {
      h = 200;
      x = x + -0x82;
      w = w + 0x104;
    }
    break;
  case 0xd4:
    standard_frontZone(obj,&x,&w);
    h = 0xfa;
    break;
  case 0x59:
    h = h + 0x14;
    break;
  case 0x15:
    break;
  default:
    standard_frontZone(obj,&x,&w);
    break;
  }
  sVar4 = inter_box(x,y,w,h,ray_zdc_x,ray_zdc_y,
                    ray_zdc_w,ray_zdc_h);
  if (sVar4 != 0) {
    bVar5 = obj->detect_zone_flag;
    if (bVar5 == 0 || bVar5 == 1) {
      if (bVar5 == 0) {
        obj->detect_zone_flag = 1;
      }
      else if (bVar5 == 1) {
        obj->detect_zone_flag = 2;
      }
    }
    else {
      obj->detect_zone_flag = obj->detect_zone_flag + 1;
      bVar5 = obj->detect_zone_flag;
      if (bVar5 == 0x14) {
        obj->detect_zone_flag = 2;
      }
    }
  }
  else {
    obj->detect_zone_flag = 0;
    if (obj->type == 0x15) {
      obj->flags = obj->flags & ~FLG(OBJ_FLAG_0);
    }
  }
  return;
}

/*INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLL_RAY_CYMBALE);*/

void DO_COLL_RAY_CYMBALE(Obj *param_1)
{
    Obj *temp_s0;
    s16 temp_s1;
    s16 temp_v0;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_s1;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_4;
    s16 var_s3;
    u8 temp_a0;

    /*var_s3 = saved_reg_s3;*/
    var_s1 = 0;
    if (param_1->type == 0xA9)
    {
        temp_v1 = param_1->id;
        temp_a0 = link_init[temp_v1];
        var_s4 = 0xA;
        if (temp_a0 != temp_v1)
        {
            temp_s0 = &level.objects[temp_a0];
            var_v0 = 0 << 0x10;
            if (temp_s0->type == 0xA8)
            {
                temp_v1_2 = temp_s0->speed_y;
                if (temp_v1_2 >= 0x81)
                {
                    temp_s0->speed_y = 1;
                }
                else if (temp_v1_2 < -0x80)
                {
                    temp_s0->speed_y = -1;
                }
                temp_s0->y_pos = (u16) temp_s0->y_pos + ((u16) temp_s0->speed_y * 2);
                var_s1 = BOX_IN_COLL_ZONES(0x0017, ray_zdc_x, ray_zdc_y, ray_zdc_w, (s16) (s32) ray_zdc_h, temp_s0);
                temp_s0->y_pos = (u16) temp_s0->y_pos - ((u16) temp_s0->speed_y * 2);
                var_s3 = (u16) temp_s0->speed_y * 2;
            }
        }
    }
    else
    {
        var_s1 = BOX_IN_COLL_ZONES(0x0017, ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h, param_1);
        var_s4 = 1;
        var_s3 = param_1->speed_y;
    }
    if (var_s1 != -1)
    {
        temp_s1 = var_s1 - 1;
        if (ray.main_etat == 2)
        {
            if (ray.sub_etat != 1 && ray.sub_etat != 2)
            {
                if (ray.sub_etat != 8)
                {
                    set_sub_etat(&ray, 1U);
                }
                if ((s16) var_s3 >= 0x81)
                {
                    var_s3 = 1;
                }
                else if ((s16) var_s3 < -0x80)
                {
                    var_s3 = -1;
                }
                ray.y_pos += var_s3;
                ray.field24_0x3e = 0;
                ray.speed_y = 0;
            }
        }
        if(ray.main_etat != 2 || !(ray.main_etat == 2 && ray.sub_etat == 8))
        {
            if (
              ((ray.main_etat != 0) || (ray.sub_etat != 0x3D)) &&
              ((u32) (param_1->anim_frame - 0x14) < 3U) &&
              (param_1->main_etat == 0) && (param_1->sub_etat == var_s4)
            )
            {
                if (
                  ((param_1->follow_sprite == 1) || (temp_s1 == (s16) 1U)) &&
                  (ray.flags & 0x400) &&
                  ((ray.main_etat != 2) || (ray.sub_etat != 8)) &&
                  ((ray.main_etat != 0) || (ray.sub_etat != 0x3D)))
                {
                    temp_v0 = ((ray.offset_bx + ray.x_pos) - param_1->x_pos) - param_1->offset_bx;
                    if (__builtin_abs(temp_v0) < 0x19)
                    {
                        ray.speed_x = 0;
                        ray.speed_y = 0;
                        decalage_en_cours = 0;
                        ray.flags = ray.flags & ~0x800;
                        ray.iframes_timer = -1;
                        set_main_and_sub_etat(&ray, 0U, 0U);
                        ray.field20_0x36 = param_1->id;
                        return;
                    }
                    if (temp_v0 < 0)
                    {
                        ray.flags = ray.flags | 0x4000;
                    }
                    else
                    {
                        ray.flags = ray.flags & ~0x4000;
                    }
                }
                else if ((param_1->follow_sprite == 0) || ((temp_s1) == 0))
                {
                    ray.flags |= 0x4000;
                }
                else
                {
                    ray.flags &= ~0x4000;
                }
                RAY_HIT(1U, param_1);
            }
        }
    }
}

/* cases 0xd1/0xd2 and default are optimized together somehow
did not yet try gotos-only for both
DoFlammeRaymanCollision, DoRaymanCollisionDefault on android */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_DoRaymanCollision);*/

/*void DO_NOVA(Obj *obj);
int NOVA_STATUS_BAR(void);
void restoreGameState(SaveState *save);
void set_SNSEQ_list(short param_1);*/

void PS1_DoRaymanCollision(void)
{
    Obj *temp_v1_2;
    Obj *temp_v1_3;
    Obj *var_s0;
    s16 *temp_s3;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s16 var_v0;
    s32 temp_a0;
    s32 var_a0;
    s32 var_a1;
    s16 var_s6;
    u8 temp_a0_2;
    u8 temp_v0_3;
    u8 temp_v1;
    u8 temp_v1_4;
    s16 test_1;

    var_s6 = 0;
    var_s0 = &level.objects[actobj.objects[0]];
    if (actobj.num_active_objects > 0)
    {
        /* iframes_timer actually loaded around here */
        do
        {
            temp_a0_2 = var_s0->type;
            if (
                (((u8) flags[temp_a0_2].flags2 >> 4) & 1) &&
                (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 0x20) &&
                ((ray.main_etat != 3) || (ray.sub_etat != 0x20))
            )
            {
                if ((temp_a0_2 == 0x51) || (temp_a0_2 == 0xA9))
                {
                    var_v0 = 0;
                }
                else
                {
                    var_v0 = CHECK_BOX_COLLISION(0x0017, ray_zdc_x, ray_zdc_y, ray_zdc_w, (s16) (s32) ray_zdc_h, var_s0);
                }
                if (var_v0 != -1)
                {
                    temp_v1 = var_s0->type;
                    switch (temp_v1)
                    {
                    case 0x1E:
                        DoAudioStartRaymanCollision(var_s0);
                        
                        break;
                    case 0xA1:
                        PlaySnd(0x000E, var_s0->id);
                        set_sub_etat(var_s0, 0x17);
                        if (bonus_map != 0)
                        {
                            nb_wiz--;
                            temp_v0_3 = nb_wiz_collected + 1;
                            nb_wiz_collected = temp_v0_3;
                            status_bar.num_wiz = temp_v0_3;
                            if (nb_wiz == 0)
                            {
                                loop_time = -0x0020;
                                INIT_FADE_OUT();
                            }
                        }
                        else
                        {
                            status_bar.num_wiz += 1;
                        }
                        if ((u8) status_bar.num_wiz >= 0x64U)
                        {
                            DO_NOVA(var_s0);
                            if (bonus_map != 0)
                            {
                                id_Cling_1up = -1;
                            }
                            else
                            {
                                id_Cling_1up = NOVA_STATUS_BAR();
                            }
                            if (id_Cling_1up == -1)
                            {
                                Add_One_RAY_lives();
                            }
                            life_becoz_wiz = 1;
                            status_bar.num_wiz += 0x9C;
                        }
                        start_pix_gerbe(var_s0->screen_x_pos + 0xA, var_s0->screen_y_pos + 0xA);
                        
                        break;
                    case 0x8E:
                        DO_NOVA(var_s0);
                        PlaySnd(0x00C2, var_s0->id);
                        if (id_Cling_1up != -1)
                        {
                            Add_One_RAY_lives();
                            temp_v1_3 = &level.objects[id_Cling_1up];
                            temp_v1_3->flags &= ~0x400;
                        }
                        temp_v0_4 = NOVA_STATUS_BAR();
                        id_Cling_1up = temp_v0_4;
                        if (temp_v0_4 == -1)
                        {
                            Add_One_RAY_lives();
                        }
                        var_s0->flags &= ~0x400;
                        take_bonus(var_s0->id);
                        
                        break;
                    case 0x52:
                        DO_NOVA(var_s0);
                        if (id_Cling_Pow != -1)
                        {
                            ray.hit_points = 4;
                            status_bar.max_hp = 4;
                            temp_v1_2 = &level.objects[id_Cling_Pow];
                            temp_v1_2->flags &= ~0x400;
                        }
                        temp_v0 = NOVA_STATUS_BAR();
                        id_Cling_Pow = temp_v0;
                        if (temp_v0 == -1)
                        {
                            ray.hit_points = 4;
                            status_bar.max_hp = 4;
                        }
                        var_s0->flags &= ~0x400;
                        PlaySnd(0x000C, var_s0->id);
                        
                        break;
                    case 0x8D:
                        temp_v1_4 = var_s0->sub_etat;
                        var_s0->flags &= ~0x400;
                        
                        switch (temp_v1_4)
                        {
                        case 32:
                            set_SNSEQ_list(0);
                            
                            break;
                        case 21:
                            set_SNSEQ_list(1);
                            
                            break;
                        case 22:
                            set_SNSEQ_list(2);
                            
                            break;
                        case 23:
                            set_SNSEQ_list(3);
                            
                            break;
                        case 24:
                            set_SNSEQ_list(4);
                            
                            break;
                        case 25:
                            set_SNSEQ_list(5);
                            
                            break;
                        case 26:
                            set_SNSEQ_list(6);
                            
                            break;
                        case 27:
                            set_SNSEQ_list(7);
                            
                            break;
                        case 28:
                            set_SNSEQ_list(8);
                            
                            break;
                        case 29:
                            set_SNSEQ_list(9);
                            
                            break;
                        case 30:
                            set_SNSEQ_list(0x000A);
                            
                            break;
                        }
                        break;
                    case 0xA4:
                        var_s0->flags &= ~0x800;
                        var_s0->flags &= ~0x400;
                        unleashMonsterHost(var_s0);
                        
                        break;
                    case 0x89:
                        
                        if (reduced_rayman_id != -1)
                        {
                            if (var_s0->hit_points == var_s0->init_hit_points)
                            {
                                DO_NOVA(var_s0);
                                var_s0->speed_x = 0;
                                var_s0->speed_y = 0;
                                var_s0->hit_points--;
                                RAY_DEMIRAY();
                                
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                        break;
                    case 0x2A:
                        TEST_SIGNPOST();
                        life_becoz_wiz = 0;
                        break;
                    case 0xA9:
                    case 0x51:
                        DO_COLL_RAY_CYMBALE(var_s0);
                        break;
                    case 0x6C:
                        ToonDonnePoing(var_s0);
                        break;
                    case 0xd1:
                    case 0xd2:
                        test_1 = ray.iframes_timer;
                        if ((test_1 >= 0xa) || (test_1 == -1))
                        {
                            RAY_HIT(1, var_s0);
                            if (ray_mode != 3)
                            {
                                ray.iframes_timer = 0xa;
                            }
                        }
                        else
                        {
                            RAY_HIT(0, var_s0);
                            ray.iframes_timer = test_1;
                            /**temp_s3 = (s16) (u16) *temp_s3;*/
                        }
                        break;
                    case 0x7C:
                        if (bonus_map != 0)
                        {
                            status_bar.num_wiz = nb_wiz_save;
                            nb_wiz_save = 0;
                            departlevel = 0;
                            fix_numlevel(&ray);
                            break;
                        }
                        if (((ray.main_etat != 2) || ((ray.sub_etat != 8))) && ((ray.hit_points != 0xFF)))
                        {
                            if (gele == 0)
                            {
                                restoreGameState(&save2);
                                new_world = 1;
                                if (life_becoz_wiz != 0)
                                {
                                    if (--status_bar.num_lives == -1)
                                    {
                                        status_bar.num_lives = 0;
                                    }
                                    life_becoz_wiz = 0;
                                }
                            }
                        }
                        break;
                    default:
                        test_1 = ray.iframes_timer;
                        if ((test_1 >= 0x3c) || (test_1 == -1))
                        {
                            RAY_HIT(1, var_s0);
                            if (ray_mode != 3 && ray_mode != 4)
                            {
                                ray.iframes_timer = 0x3c;
                            }
                        }
                        else
                        {
                            RAY_HIT(0, var_s0);
                            ray.iframes_timer = test_1;
                            /**temp_s3 = (s16) (u16) *temp_s3;*/
                        }
                        break;
                    }
                }
            }
            var_s6 = var_s6 + 1;
            var_s0 = &level.objects[actobj.objects[var_s6]];
        } while (var_s6 < actobj.num_active_objects);
    }
}