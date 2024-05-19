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

/* ??? tried gotos-only, both m2c and ghidra
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
    ZDC *temp_v0;
    s16 temp_a1_3;
    s16 temp_v1_4;
    s16 var_s2;
    s16 var_s2_2;
    s16 var_v0_3;
    s32 temp_v0_2;
    s32 temp_v1_6;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a1;
    u16 var_s3;
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
    var_s5 = -1;
    temp_a1 = obj->zdc;
    if (temp_a1 != 0)
    {
        var_s3 = get_nb_zdc(obj);
        if (num_world == 1)
        {
            temp_v1 = obj->type;
            if ((temp_v1 == 0x32) || (temp_v1 == 0xE3))
            {
                if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
                {
                    goto block_6;
                }
                goto block_8;
            }
block_6:
            if (obj->type == 0xA5)
            {
        
                if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
                {
block_8:
                    var_s3 -= 1;
                }
            }
        }
        var_s2 = 0;
        if ((s16) var_s3 > 0)
        {
            /* load param_1 into test_1 here instead? */
loop_11:
            temp_v0 = get_zdc(obj, var_s2);
            temp_v1_2 = temp_v0->flags;
            if (!(temp_v1_2 & 4) || (param_1 == 0x005E))
            {
                if (temp_v1_2 & 2)
                {
                    temp_v1_3 = &obj->animations[obj->anim_index];
                    temp_a1_2 = temp_v0->sprite;
                    if (temp_v1_3->layers[(temp_v1_3->layers_count & 0x3FFF) * obj->anim_frame + temp_a1_2].sprite != 0)
                    {
                        GET_SPRITE_POS(obj, (s32) temp_a1_2, &sp20, &sp22, &sp24, &sp26);
                        if (obj->flags & 0x4000)
                        {
                            sp20 = (u16) sp20 + ((sp24 - temp_v0->width) - (u16) temp_v0->x_pos);
                        }
                        else
                        {
                            sp20 = (u16) sp20 + (u16) temp_v0->x_pos;
                        }
                        sp22 = (u16) sp22 + (u16) temp_v0->y_pos;
                        sp24 = (u16) temp_v0->width;
                        sp26 = (u16) temp_v0->height;
                    }
                }
                else
                {
                    temp_a1_3 = (u16) obj->x_pos + (u16) temp_v0->x_pos;
                    sp20 = temp_a1_3;
                    sp22 = (u16) obj->y_pos + (u16) temp_v0->y_pos;
                    temp_a0 = temp_v0->width;
                    sp24 = (u16) temp_a0;
                    sp26 = (u16) temp_v0->height;
                    if (obj->flags & 0x4000)
                    {
                        sp20 = ((obj->offset_bx + (u16) obj->x_pos)) + ((obj->offset_bx + (u16) obj->x_pos)) - (temp_a1_3 + temp_a0);
                    }
                }
                if ((s16) inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26) == 0)
                {
                    goto block_22;
                }
                else
                    var_v0 = temp_v0->sprite << 0x10;
            }
            else
            {
block_22:
                temp_v1_4 = var_s2 + 1;
                var_s2 = temp_v1_4;
                if (temp_v1_4 >= (s16) var_s3)
                {
                    var_v0 = var_s5 << 0x10;
                }
                else
                {
                    goto loop_11;
                }
            }
        }
        else
        {
            goto block_38;
        }
    }
    else
    {
        temp_v1_5 = obj->hit_sprite;
        if (temp_v1_5 == 0xFE)
        {
            GET_OBJ_ZDC(obj, &sp20, &sp22, (s16 *) &sp24, (s16 *) &sp26);
            if (obj->flags & 0x4000)
            {
                sp20 = ((obj->offset_bx + (u16) obj->x_pos)) + ((obj->offset_bx + (u16) obj->x_pos)) - ((u16) sp20 + sp24);
            }
            temp_v0_2 = inter_box((s32) param_2, (s32) param_3, (s32) param_4, (s32) (s16) (s32) param_5, (s16) (s32) sp20, (s16) (s32) sp22, (s32) (s16) sp24, (s32) (s16) sp26);
            
            if ((temp_v0_2 << 0x10) == 0)
            {
                var_s5 = -1;
            }
            else
                var_s5 = temp_v0_2;
            goto block_38;
        }
        var_v0 = -1 << 0x10;
        if (temp_v1_5 == 0xFF)
        {
            temp_v1_6 = obj->animations[obj->anim_index].layers_count & 0x3FFF;
            var_s2_2 = 0;
            if ((s32) temp_a1 < temp_v1_6)
            {
loop_34:
                var_v0_3 = var_s2_2 + 1;
                if (((in_coll_sprite_list(obj, var_s2_2) << 0x10) == 0) || (var_v0_3 = var_s2_2 + 1, ((GET_SPRITE_ZDC(obj, var_s2_2, &sp20, &sp22, (s16 *) &sp24, (s16 *) &sp26) << 0x10) == 0)) || (var_v0_3 = var_s2_2 + 1, ((inter_box((s32) (s16) (u16) param_2, (s32) param_3, (s32) param_4, (s32) (s16) (s32) param_5, (s16) (s32) sp20, (s16) (s32) sp22, (s32) (s16) sp24, (s32) (s16) sp26) << 0x10) == 0)))
                {
                    var_s2_2 = var_v0_3;
                    if (var_v0_3 < temp_v1_6)
                    {
                        goto loop_34;
                    }
                }
                else
                {
                    var_s5 = (s32) var_s2_2;
                }
            }
block_38:
            var_v0 = var_s5 << 0x10;
        }
    }
    return var_v0 >> 0x10;
}

/* matches, but do{}while(0); */
/* 1D228 80141A28 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_MULTISPR_CANTCHANGE);*/

void SET_RAY_DIST_MULTISPR_CANTCHANGE(Obj *obj)
{
  s32 unk_1;
  s16 i;
  s16 new_dist;
  s16 ray_x; s16 ray_y;
  s16 foll_x; s16 foll_y; s16 foll_w; s16 foll_h;
  s16 diff_x;
  s16 sprite;
  
do
{
  if (RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
    unk_1 = 4;
  else
    unk_1 = 8;
  i = 0;
  new_dist = 10000;
} while (0);
  ray_x = ray.x_pos + ray.offset_bx;
  ray_y = ray.y_pos + ray.offset_by;
  if (ray.field20_0x36 == obj->id)
  {
    GET_SPRITE_POS(obj, obj->follow_sprite, &foll_x, &foll_y, &foll_w, &foll_h);
    foll_y += obj->offset_hy;
    if (obj->type == TYPE_ROULETTE || obj->type == TYPE_ROULETTE2 || obj->type == TYPE_ROULETTE3)
    {
      foll_w -= 10;
      foll_x += 5;
    }
    if (obj->type == TYPE_TIBETAIN_6 && ray.main_etat == 0 && (obj->anim_frame - 10 < 30U))
    {
      diff_x = (ray.x_pos + ray.offset_bx) - (foll_x + (foll_w >> 1));
      if (diff_x > 0)
        ray.x_pos--;
      else if(diff_x < 0)
        ray.x_pos++;
      ray_x = ray.x_pos + ray.offset_bx;
    }
    new_dist = setToleranceDist(foll_x, foll_w, foll_y);
  }
  if (new_dist == 10000) {
    sprite = possible_sprite(obj, i++);
    while (sprite != 0xff)
    {
      GET_SPRITE_POS(obj, sprite, &foll_x, &foll_y, &foll_w, &foll_h);
      foll_y = obj->offset_hy + foll_y;
      if (obj->type == TYPE_ROULETTE || obj->type == TYPE_ROULETTE2 || obj->type == TYPE_ROULETTE3)
      {
        foll_w -= 10;
        foll_x += 5;
      }

      if ((ray_x <= foll_x + foll_w + unk_1) && (ray_x >= foll_x - unk_1))
      {
        new_dist = ray_y - foll_y;
        if (obj->type == TYPE_TIBETAIN_6 && ((u16)(new_dist - 8) < 3))
          new_dist = 0;
      }
      else
        new_dist = 10000;
      
      if (new_dist != 10000)
        obj->follow_sprite = sprite;

      sprite = possible_sprite(obj, i++);
      if((__builtin_abs(new_dist) <= 7)) break;
    }
  }
  obj->ray_dist = new_dist;
}

/* matches, but clean up */
/* 1D66C 80141E6C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_BAG);*/

void SET_RAY_DIST_BAG(Obj *obj)
{
  s16 sp18;
  s16 sp1A;
  s16 sp1C;
  s16 sp1E;
  s16 var_a1;
  s16 temp_v0;

  var_a1 = 0;
  if (obj->sub_etat == 3 || (obj->sub_etat == 6 && obj->anim_frame <= 11))
  {
    GET_SPRITE_POS(obj, obj->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
    sp1A += obj->offset_hy;
    temp_v0 = sp1C;
    sp1C = 45;
    sp18 += ((s16) (temp_v0 - sp1C) >> 1);
    var_a1 = setToleranceDist(sp18, sp1C, sp1A);
  }
  else
  {
    var_a1 = 0x2710;
  }
  if (ray.field20_0x36 == obj->id && obj->sub_etat == 6 && obj->anim_frame == 11)
  {
    ray.field20_0x36 = -1;
    set_main_and_sub_etat(&ray, 2, 0);
    var_a1 = 0x2710;
    ray.speed_y -= 10;
  }
  obj->ray_dist = var_a1;
}

/* standard version, then gotos-only below... no idea yet how to fix remaining issue */
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
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    u16 sp1E;
    u8 var_a1_2;
    u8 var_a1_3;
    u8 var_a1_4;
    u8 var_a2;
    u8 var_a2_2;
    Obj *temp_s1;
    Obj *temp_v0_3;
    Obj *var_s0;
    s16 temp_a0;
    s16 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s16 temp_v0_6;
    s16 var_a1;
    s32 var_s2_2;
    s16 var_s5;
    s16 var_v0_2;
    s32 temp_a1;
    s32 temp_v0_4;
    s32 temp_v1_2;
    u8 var_v0;
    s32 var_v0_5;
    s32 var_v1;
    u32 temp_v1_3;
    u32 var_v0_3;
    u8 temp_a1_2;
    u8 temp_s5;
    u8 temp_v0_8;
    u8 temp_v1;
    s32 temp_v1_4;
    u8 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_s2;
    s16 test_1;
    s32 test_2;
    s32 test_3;
    int new_var;

    /*var_s2 = saved_reg_s2;*/
    temp_s1 = &level.objects[poing_obj_id];
    var_v0 = 0;
    GET_SPRITE_POS(temp_s1, 0, &sp18, &sp1A, &sp1C, &sp1E);
    if ((temp_v0 = temp_s1->speed_x) > 0 || temp_s1->speed_x < 0)
    {
        var_v0 = PS1_BTYPAbsPos(temp_s1->x_pos + temp_s1->offset_bx, temp_s1->y_pos + ((s32) (temp_s1->offset_by + temp_s1->offset_hy) >> 1));
    }
    temp_a1 = ((u8) block_flags[var_v0] >> 1) & 1;
    var_s5 = 0;
    if (temp_a1 != 0)
    {
        do_boum();
        fin_poing_follow(temp_s1, 1);
        return;
    }
    var_s0 = &level.objects[actobj.objects[var_s5]];
    if (temp_a1 < actobj.num_active_objects)
    {
        test_1 = 2;
        test_2 = ~0x4000;
        test_3 = 1;
        do
        {
            if ((new_world != 0) || (new_level != 0) || (fin_boss != 0))
                break;
        
            if ((var_s0->display_prio != 0) && (var_s0->hit_points != 0) && (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 8))
            {
                temp_v0_2 = CHECK_BOX_COLLISION(0x005E, sp18, sp1A, (s16) sp1C, (s16) (s32) (s16) sp1E, var_s0);
                if (temp_v0_2 != -1)
                {
                    temp_v1 = var_s0->type;
                    temp_s5 = var_s0->hit_points;
                    switch (temp_v1)
                    {
                    case 0xDF:
                        if ((temp_v0_2 == 6) && (poing.is_returning == 0) && (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
                        {
                            poing.damage = 1;
                            obj_hurt(var_s0);
                            if (var_s0->hit_points != 0)
                            {
                                if (var_s0->sub_etat == 2)
                                {
                                    set_sub_etat(var_s0, 4);
                                }
                                else
                                {
                                    set_sub_etat(var_s0, 0xD);
                                }
                            }
                            else
                            {
                                if (var_s0->sub_etat == 2)
                                {
                                    level.objects[var_s0->field24_0x3e].flags &= ~0x400;
                                    DO_NOVA(&level.objects[var_s0->field24_0x3e]);
                                }
                                set_sub_etat(var_s0, 8);
                                var_s0->field23_0x3c = 1;
                            }
                        }
                        break;
                    case 0xDA:
                        if ((var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1) && ((temp_v0_2 == 3) || (temp_v0_2 == 6)))
                        {
                            poing.damage = 1;
                            obj_hurt(var_s0);
                            if (var_s0->hit_points == 0)
                            {
                                skipToLabel(var_s0, 2, 1);
                                var_s0->field23_0x3c = 1;
                            }
                            else
                            {
                                var_a1_2 = 4;
                                skipToLabel(var_s0, var_a1_2, 1);
                            }
                        }
                        break;
                    case 0x62:
                    case 0xD5:
                        doMereDenisHit(var_s0, temp_v0_2);
                        break;
                    case 0xD4:
                        DO_DARK_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0x78:
                        if (temp_v0_2 == (s16) 2)
                        {
                            DO_BAT_POING_COLLISION(var_s0);
                        }
                        break;
                    case 0xBB:
                        if (temp_v0_2 == 5)
                        {
                            DO_PMA_POING_COLLISION(var_s0);
                        }
                        break;
                    case 0x32:
                    case 0xE3:
                        doMoskitoHit(var_s0, temp_v0_2);
                        break;
                    case 0x8E:
                        if ((RayEvts.flags0 & 0x80) && (ray_mode != 3))
                        {
                            temp_s1->field20_0x36 = (s16) (u16) var_s0->id;
                        }
                        break;
                    case 0x8C:
                        if ((RayEvts.flags0 & 0x80) && (ray_mode != 3))
                        {
                            temp_a1_2 = var_s0->offset_by;
                            temp_v1_2 = (ray.y_pos + ray.offset_by) - var_s0->y_pos;
                            temp_v0_4 = temp_v1_2 - temp_a1_2;
                            if (temp_v0_4 >= 0)
                            {
                                if (temp_v0_4 < 0xFA)
                                {
                                    goto block_47;
                                }
                            }
                            else if ((temp_a1_2 - temp_v1_2) < 0xFA)
                            {
block_47:
                                SET_RAY_BALANCE();
                                id_obj_grapped = (s16) (u16) var_s0->id;
                                temp_v0_5 = ANGLE_RAYMAN(var_s0);
                                var_s0->follow_x = temp_v0_5;
                                if (temp_v0_5 >= 0x101)
                                    var_s0->field24_0x3e = -1;
                                else if (temp_v0_5 < 0x101)
                                {
                                    if(temp_v0_5 == 0x0100 && !(ray.flags & 0x4000))
                                        var_s0->field24_0x3e = -1;
                                    else
                                        var_s0->field24_0x3e = 1;
                                }
                                else /* ??? */
                                    var_s0->field24_0x3e = 1;
                                
                                if ((var_s0->main_etat == 0) && (var_s0->sub_etat == 0))
                                {
                                    skipToLabel(var_s0, 0, 1);
                                }
                                poing.is_active = 0;
                                poing.is_returning = 0;
                                temp_s1->flags &= ~0x400;
                                temp_s1->flags &= ~0x800;
                                fin_poing_follow(temp_s1, 0U);
                            }
                        }
                        break;
                    case 0x98:
                        if ((var_s0->main_etat != 0) || (var_s0->sub_etat != 2))
                        {
                            set_main_and_sub_etat(var_s0, 1, 1);
                            temp_v1_3 = var_s0->flags;
                            if (!(temp_v1_3 & 0x4000))
                            {
                                var_s0->flags = temp_v1_3 | 0x4000;
                                skipToLabel(var_s0, 3, 1);
                            }
                            else
                            {
                                var_s0->flags = temp_v1_3 & ~0x4000;
                                skipToLabel(var_s0, 2, 1);
                            }
                            
                        }
                        break;
                    case 0x7B:
                        obj_hurt(var_s0);
                        if (var_s0->hit_points == 0)
                        {
                            set_main_and_sub_etat(var_s0, 0, 4);
                            var_s0->speed_y = 0;
                            temp_v0_6 = temp_s1->speed_x;
                            if (temp_v0_6 >= 0)
                            {
                                if (temp_v0_6 > 0)
                                {
                                    var_v0_3 = var_s0->flags;
                                    var_v0_3 = var_v0_3 & ~0x4000;
                                }
                                else if ((temp_s1->flags & 0x4000))
                                {
                                    var_v0_3 = var_s0->flags & ~0x4000;
                                }
                                else
                                {
                                    var_v0_3 = var_s0->flags | 0x4000;
                                }
                            }
                            else
                                var_v0_3 = var_s0->flags | 0x4000;
                        block_67:
                            var_s0->flags = var_v0_3;
                            allocateBlacktoonEyes(var_s0);
                            if (var_s0->flags & 0x4000)
                            {
                                skipToLabel(var_s0, 2, 1);
                            }
                            else
                            {
                                skipToLabel(var_s0, 3, 1);
                            }
                            break;
                        }
                        break;
                    case 0x65:
                        if ((temp_v0_2 == 4) && (var_s0->sub_etat == 5))
                        {
                            temp_v0_6 = temp_s1->speed_x;
                            if ((temp_v0_6 >= 0) && ((temp_v0_6 > 0) || (temp_s1->flags & 0x4000)))
                            {
                                set_sub_etat(var_s0, 9);
                            }
                            else
                            {
                                set_sub_etat(var_s0, 6);
                            }
                        }
                        break;
                    case 0x91:
                        if (--var_s0->hit_points)
                        {
                            set_sub_etat(var_s0, 5);
                            var_s0->iframes_timer = 0x0032;
                        }
                        else
                        {
                            set_sub_etat(var_s0, 6);
                        }
                        break;
                    case 0x4D:
                    case 0xEF:
                        DO_PAR_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0x48:
                        DO_NGW_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0x3A:
                        obj_hurt(var_s0);
                        if (var_s0->hit_points == 0)
                        {
                            var_s0->init_main_etat = 0;
                            var_s0->init_sub_etat = 8;
                            var_s0->init_x_pos = (s16) (u16) var_s0->x_pos;
                            var_s0->init_y_pos = (s16) (u16) var_s0->y_pos;
                            set_sub_etat(var_s0, 0xC);
                            var_s0->init_flag = 7;
                            ALLOCATE_MEDAILLON_TOON();
                            lidol_to_allocate = 5;
                            lidol_source_obj = var_s0;
                            Nb_total_cages += 1;
                            take_bonus(var_s0->id);
                        }
                        else
                        {
                            set_sub_etat(var_s0, 0xA);
                        }
                        break;
                    case 0x2E:
                        if (temp_v0_2 == 9)
                        {
                            DO_BBMONT_TOUCHE(var_s0);
                        }
                        break;
                    case 0x5A:
                    case 0x5B:
                    case 0x5C:
                    case 0x5D:
                    case 0xB6:
                        DO_NOTE_TOUCHEE(var_s0, temp_v0_2);
                        break;
                    case 0x60:
                        DO_TOTEM_TOUCHE(var_s0, temp_v0_2);
                        break;
                    case 0x6F:
                        if ((var_s0->main_etat == 0) && (Mus_obj_id >= 0))
                        {
                            PlaySnd(0x0053, var_s0->id);
                            var_s0->hit_points--;
                            switch (var_s0->hit_points)
                            {
                            case 3:
                                set_sub_etat(var_s0, 4);
                                allocateEclatPS(var_s0, 7);
                                set_sub_etat(&level.objects[Mus_obj_id], 6);
                                break;
                            case 2:
                                set_sub_etat(var_s0, 6);
                                allocateEclatPS(var_s0, 8);
                                break;
                            case 1:
                                set_sub_etat(var_s0, 8);
                                allocateEclatPS(var_s0, 9);
                                break;
                            case 0:
                                if (level.objects[Mus_obj_id].sub_etat == 6)
                                {
                                    PlaySnd(0x0053, var_s0->id);
                                    set_sub_etat(var_s0, 9);
                                    level.objects[Mus_obj_id].sub_etat = 3;
                                    level.objects[Mus_obj_id].init_sub_etat = 4;
                                    var_s0->init_sub_etat = 0x0A;
                                }
                                break;
                            }
                        }
                        break;
                    case 0x6D:
                        if (var_s0->main_etat == 0)
                        {
                            obj_hurt(var_s0);
                            if (var_s0->hit_points == 0)
                            {
                                DO_PI_EXPLOSION(var_s0);
                                var_s0->flags &= ~0x800;
                                if (ray.field20_0x36 == var_s0->id)
                                {
                                    ray.field20_0x36 = -1;
                                    var_s0->ray_dist = 0x03E8;
                                    set_main_and_sub_etat(&ray, 2, 2);
                                }
                                var_v1 = -0x401;
                                var_s0->flags &= var_v1;
                            }
                            else
                            {
                                set_sub_etat(var_s0, 1);
                                var_s0->anim_frame = 0;
                            }
                        }
                        break;
                    case 0xA6:
                        DO_LEV_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0x41:
                        obj_hurt(var_s0);
                        if (var_s0->hit_points == 0)
                        {
                            set_main_and_sub_etat(var_s0, 0, 7);
                            var_s0->anim_frame = 0;
                            var_v1 = 0xFFFF7FFF;
                            var_s0->flags &= var_v1;
                            break;
                        }
                        if ((var_s0->main_etat == 0) && ((temp_v1_5 = var_s0->sub_etat, (((u32) (temp_v1_5 - 2) < 2U) != 0)) || ((u32) (temp_v1_5 - 4) < 2U)))
                        {
                            var_s0->cmd_context_index = 0xFF;
                        }
                        var_s0->field23_0x3c = 0;
                        if (level.objects[poing_obj_id].speed_x > 0)
                        {
                            skipToLabel(var_s0, 3, 1);
                            var_v0_3 = var_s0->flags | 0x4000;
                        }
                        else
                        {
                            skipToLabel(var_s0, 1, 1);
                            var_v0_3 = var_s0->flags;
                            var_v0_3 &= ~0x4000;
                        }
                        var_s0->flags = var_v0_3;
                        pushToLabel(var_s0, 6, 1);
                        var_s0->anim_frame = 0;
                        pushToLabel(var_s0, 7, 1);
                        break;
                    case 0x28:
                    case 0x7A:
                        obj_hurt(var_s0);
                        if (var_s0->hit_points != 0)
                        {
                            skipToLabel(var_s0, 5, 1);
                            var_s0->gravity_value_2 = 7;
                            var_s0->change_anim_mode = 2;
                            temp_v0_6 = temp_s1->speed_x;
                            if (temp_v0_6 > 0)
                            {
                                var_v0_3 = var_s0->flags;
                                var_v0_3 &= ~0x4000;
                                var_s0->flags = var_v0_3;
                            }
                            else if (temp_v0_6 < 0)
                            {
                                var_s0->flags |= 0x4000;
                            }
                        }
                        else
                        {
                            set_main_and_sub_etat(var_s0, 0, 3);
                            var_v1 = 0xFFFF7FFF;
                            var_s0->flags &= var_v1;
                            break;
                        }
                        break;
                    case 0x24:
                    case 0x2F:
                    case 0x45:
                        set_sub_etat(var_s0, 1);
                        DO_STONE_EXPLOSION(var_s0);
                        break;
                    case 0x23:
                    case 0x2B:
                        DO_PNG_COLL_STONEMAN(var_s0);
                        break;
                    case 0x38:
                    case 0xAC:
                        DO_PNG_COLL_STONEWOMAN(var_s0);
                        break;
                    case 0x1:
                        if (temp_v0_2 == var_s0->hit_sprite)
                        {
                            temp_v0_6 = temp_s1->speed_x;
                            if (temp_v0_6 > 0)
                            {
                                set_sub_etat(var_s0, 0x19);
                            }
                            else if (temp_v0_6 < 0)
                            {
                                set_sub_etat(var_s0, 0x1A);
                            }
                        }
                        break;
                    case 0x6:
                    case 0x8:
                    case 0x86:
                    case 0xA7:
                    case 0xB1:
                        temp_v1_6 = var_s0->type;
                        switch (temp_v1_6)
                        {
                        case 0x86:
                        case 0xA7:
                        case 0x8:
                            PlaySnd(0x002C, var_s0->id);
                            break;
                        case 0xB1:
                        case 0x6:
                            PlaySnd(0x008B, var_s0->id);
                            break;
                        }
                        
                        switch (poing.sub_etat)
                        {
                        case 1:
                        case 3:
                        case 5:
                            var_s2 = poing.damage;
                            break;
                        case 8:
                        case 10:
                        case 12:
                            var_s2 = poing.damage - 2;
                        case 2:
                        case 4:
                        case 6:
                        case 7:
                        case 9:
                        case 11:
                            break;
                        }
                        var_v0_5 = var_s2 * 4;
                        var_s2 = var_v0_5 + var_s2 + 0xA;
                        if (temp_s1->speed_x < 0)
                        {
                            var_s2 = -var_s2;
                        }
                        make_my_fruit_go_down(var_s0, var_s2);
                        break;
                    case 0x25:
                        set_main_and_sub_etat(var_s0, 0, 1);
                        var_s0->cmd = 0;
                        break;
                    case 0x14:
                        if (temp_v0_2 == 0)
                        {
                            poing.damage = 1;
                            obj_hurt(var_s0);
                            if (var_s0->hit_points == 0)
                            {
                                var_a1_2 = 4;
                                skipToLabel(var_s0, 4, 1);
                                break;
                            }
                            var_a1_2 = 3;
                            skipToLabel(var_s0, 3, 1);
                            break;
                        }
                        var_a1_2 = 2;
                        skipToLabel(var_s0, 2, 1);
                        break;
                    case 0xC:
                    case 0xE:
                        if (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1)
                        {
                        case 0xA:
                            obj_hurt(var_s0);
                            if (var_s0->hit_points != 0)
                            {
                                var_s0->speed_x = 0;
                                var_s0->speed_y = 0;
                                set_main_and_sub_etat(var_s0, 0, 1);
                            }
                            else
                            {
                                set_main_and_sub_etat(var_s0, 0, 3);
                            }
                            if (var_s0->type == 0x0A)
                            {
                                DESACTIVE_FISH_COLLIS(var_s0);
                            }
                            if (!(var_s0->flags & 0x4000))
                            {
                                var_s0->cmd = 0;
                            }
                            else
                            {
                                var_s0->cmd = 1;
                            }
                        }
                        break;
                    case 0x9:
                    case 0xA5:
                        if ((temp_v0_2 == 0x00FF) || (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
                        {
                            obj_hurt(var_s0);
                            if (var_s0->hit_points == 0)
                            {
                                set_main_and_sub_etat(var_s0, 0, 3);
                                skipToLabel(var_s0, 2, 1);
                                var_s0->y_pos = (u16) var_s0->y_pos - 2;
                                var_s0->flags &= 0xFFFF7FFF;
                            }
                            else
                            {
                                if (temp_s1->flags & 0x4000)
                                {
                                    temp_v0_6 = temp_s1->speed_x;
                                    if (temp_v0_6 >= 0)
                                    {
                                        var_a1_3 = 3;
                                        skipToLabel(var_s0, var_a1_3, 1);
                                    }
                                    else if (temp_v0_6 < -1)
                                    {
                                        var_a1_3 = 2;
                                        skipToLabel(var_s0, var_a1_3, 1);
                                    }
                                }
                                else
                                {
                                    temp_v0_6 = temp_s1->speed_x;
                                    var_a1_3 = 3;
                                    if (temp_v0_6 >= 2)
                                    {
                                        skipToLabel(var_s0, var_a1_3, 1);
                                    }
                                    else if (temp_v0_6 <= 0)
                                    {
                                        var_a1_3 = 2;
                                        skipToLabel(var_s0, var_a1_3, 1);
                                    }
                                }
                                var_s0->speed_x = 0;
                                var_s0->speed_y = -4;
                                var_s0->y_pos = (u16) var_s0->y_pos - 2;
                                set_main_and_sub_etat(var_s0, 2, 2);
                                PlaySnd(0x001C, var_s0->id);
                            }
                        }
                        break;
                    case 0x0:
                        obj_hurt(var_s0);
                        temp_v0_6 = temp_s1->speed_x;
                        if (temp_v0_6 > 0)
                        {
                            skipToLabel(var_s0, 3, 1);
                        }
                        else if (temp_v0_6 < 0)
                        {
                            skipToLabel(var_s0, 2, 1);
                        }
                        var_s0->speed_x = 0;
                        var_s0->y_pos = (u16) var_s0->y_pos - 2;
                        if (var_s0->hit_points != 0)
                        {
                            var_s0->speed_y = -4;
                            var_a2 = 2;
                            if (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 0x40)
                            {
                                var_a2 = 0xA;
                            }
                            set_main_and_sub_etat(var_s0, 2, var_a2);
                            PlaySnd(0x001C, var_s0->id);
                            break;
                        }
                        var_s0->speed_y = -8;
                        var_a2_2 = 3;
                        if (var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 0x40)
                        {
                            var_a2_2 = 6;
                        }
                        set_main_and_sub_etat(var_s0, 0, var_a2_2);
                        break;
                    case 0x46:
                        obj_hurt(var_s0);
                        temp_v0_6 = temp_s1->speed_x;
                        if (temp_v0_6 > 0)
                        {
                            var_v0_3 = var_s0->flags;
                            var_v0_3 &= ~0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        else if (temp_v0_6 < 0)
                        {
                            var_v0_3 = var_s0->flags | 0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        if (var_s0->hit_points == 0)
                        {
                            set_main_and_sub_etat(var_s0, 0, 1);
                            var_v1 = 0xFFFF7FFF;
                            var_s0->cmd = 2;
                            var_s0->flags &= var_v1;
                            break;
                        }
                        var_s0->y_pos = (u16) var_s0->y_pos - 2;
                        skipToLabel(var_s0, 4, 1);
                        break;
                    case 0x3C:
                    case 0x3D:
                        obj_hurt(var_s0);
                        temp_v0_6 = temp_s1->speed_x;
                        if (temp_v0_6 > 0)
                        {
                            var_v0_3 = var_s0->flags;
                            var_v0_3 &= ~0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        else if (temp_v0_6 < 0)
                        {
                            var_v0_3 = var_s0->flags | 0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        if (var_s0->hit_points != 0)
                        {
                            var_s0->y_pos = (u16) var_s0->y_pos - 2;
                            skipToLabel(var_s0, 4, 1);
                            break;
                        }
                        set_main_and_sub_etat(var_s0, 0, 3);
                        var_v1 = 0xFFFF7FFF;
                        var_s0->cmd = 0;
                        var_s0->flags &= var_v1;
                        break;
                    case 0x74:
                    case 0x75:
                    case 0x76:
                        obj_hurt(var_s0);
                        temp_v0_6 = temp_s1->speed_x;
                        if (temp_v0_6 > 0)
                        {
                            var_v0_3 = var_s0->flags;
                            var_v0_3 &= ~0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        else if (temp_v0_6 < 0)
                        {
                            var_v0_3 = var_s0->flags | 0x4000;
                            var_s0->flags = var_v0_3;
                        }
                        if (var_s0->hit_points != 0)
                        {
                            var_a1_2 = 5;
                            if (!(var_s0->flags & 0x4000))
                            {
                                var_a1_2 = 6;
                            }
                            skipToLabel(var_s0, var_a1_2, 1);
                            break;
                        }
                        set_main_and_sub_etat(var_s0, 0, 2);
                        var_v1 = 0xFFFF7FFF;
                        var_s0->flags &= var_v1;
                        break;
                    case 0xD9:
                        if (temp_v0_2 == 1)
                        {
                            temp_v0_6 = temp_s1->speed_x;
                            if (temp_v0_6 > 0)
                            {
                                var_v0_3 = var_s0->flags;
                                var_v0_3 &= ~0x4000;
                                var_s0->flags = var_v0_3;
                            }
                            else if (temp_v0_6 < 0)
                            {
                                var_v0_3 = var_s0->flags | 0x4000;
                                var_s0->flags = var_v0_3;
                            }
                        case 0x64:
                            if (temp_v0_2 == 1)
                            {
                                obj_hurt(var_s0);
                                if (var_s0->hit_points != 0)
                                {
                                    var_a1_2 = 4;
                                    skipToLabel(var_s0, 4, 1);
                                    break;
                                }
                                set_main_and_sub_etat(var_s0, 0, 3);
                                var_v1 = 0xFFFF7FFF;
                                var_s0->flags &= var_v1;
                                break;
                            }
                        }
                        break;
                    case 0x96:
                        DO_SKO_HIT(var_s0, temp_v0_2);
                        break;
                    case 0xAE:
                    case 0xB8:
                    case 0xE1:
                    case 0xE2:
                        DO_PIRATE_POELLE_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0xE7:
                    case 0xE8:
                        DO_HYB_BBF2_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0xC3:
                        DO_SPIDER_PLAFOND_POING_COLLISION(var_s0, temp_v0_2);
                        break;
                    case 0xE4:
                        if ((var_s0->screen_x_pos < (temp_s1->screen_x_pos + 0x1E)) && (var_s0->main_etat == 0) && (var_s0->sub_etat == 0))
                        {
                            skipToLabel(var_s0, 2, 1);
                            var_s0->init_sub_etat = 2;
                            prise_branchee = 1;
                            finBosslevel[1] |= 4;
                        }
                        break;
                    case 0x84:
                        if ((var_s0->main_etat != 2) || (var_s0->sub_etat != 0x12))
                        {
                            skipToLabel(var_s0, 0xC, 1);
                            var_s0->speed_x = 0;
                            var_s0->speed_y = 0;
                            var_s0->hit_points = 0;
                        }
                        break;
                    case 0x81:
                        temp_v1_7 = var_s0->hit_points;
                        if ((temp_v1_7 == 2) || (temp_v1_7 == 4))
                        {
                            var_s0->hit_points--;
                        }
                        break;
                    }
                    do_boum();
                    var_s0->gravity_value_1 = 0;
                    temp_v0_5 = var_s0->eta[var_s0->main_etat][var_s0->sub_etat].anim_speed >> 4;
                    if ((u32) ((temp_v0_5) - 0xA) >= 2U)
                    {
                        var_s0->gravity_value_2 = 0;
                    }
                    if ((var_s0->hit_points == temp_s5) && (flags[var_s0->type].flags3 & 1))
                    {
                        PlaySnd(0x00D6, var_s0->id);
                    }
                    break;
                }
            }
            var_s5++;
            var_s0 = &level.objects[actobj.objects[var_s5]];
        } while (var_s5 < actobj.num_active_objects);
        
    }
}

void DO_POING_COLLISION(void)
{
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    u16 sp1E;
    u8 var_a1_2;
    u8 var_a1_3;
    u8 var_a1_4;
    u8 var_a2;
    u8 var_a2_2;
    Obj *temp_s1;
    Obj *temp_v0_3;
    Obj *var_s0;
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v0_10;
    s16 temp_v0_11;
    s16 temp_v0_12;
    s16 temp_v0_13;
    s16 temp_v0_14;
    s16 temp_v0_15;
    s16 temp_v0_16;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_9;
    s16 var_a1;
    s32 var_s2_2;
    s16 var_s5;
    s16 var_v0_2;
    s32 temp_a1;
    s32 temp_v0_4;
    s32 temp_v1_2;
    u8 var_v0;
    s32 var_v0_5;
    s32 var_v1;
    u32 temp_v1_3;
    u32 var_v0_3;
    u8 temp_a1_2;
    u8 temp_s5;
    u8 temp_v0_8;
    u8 temp_v1;
    s32 temp_v1_4;
    u8 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_s2;
    s16 test_1;
    s32 test_2;
    s32 test_3;

    /*var_s2 = saved_reg_s2;*/
    temp_s1 = &level.objects[poing_obj_id];
    var_v0 = 0;
    GET_SPRITE_POS(temp_s1, 0, &sp18, &sp1A, &sp1C, &sp1E);
    temp_v0 = temp_s1->speed_x;
    
    if (temp_v0 > 0)
    {
        goto block_2;
    }
    if (temp_v0 >= 0)
    {
        goto block_3;
    }
block_2:
    var_v0 = PS1_BTYPAbsPos(temp_s1->x_pos + temp_s1->offset_bx, temp_s1->y_pos + ((s32) (temp_s1->offset_by + temp_s1->offset_hy) >> 1));
block_3:
    temp_a1 = ((u8) block_flags[var_v0] >> 1) & 1;
    var_s5 = 0;
    if (temp_a1 == 0)
    {
        goto block_5;
    }
    do_boum();
    fin_poing_follow(temp_s1, 1U);
    return;
block_5:
    var_s0 = &level.objects[actobj.objects[var_s5]];
    if (temp_a1 >= actobj.num_active_objects)
    {
        goto block_249;
    }
    test_1 = 2;
    test_2 = ~0x4000;
    test_3 = 1;
loop_7:
    if (new_world != 0)
    {
        goto block_249;
    }
    if (new_level != 0)
    {
        goto block_249;
    }
    if (fin_boss != 0)
    {
        goto block_249;
    }
    if (var_s0->display_prio == 0)
    {
        goto block_248;
    }
    if (var_s0->hit_points == 0)
    {
        goto block_248;
    }
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 8))
    {
        goto block_248;
    }
    temp_v0_2 = CHECK_BOX_COLLISION(0x005E, sp18, sp1A, (s16) sp1C, (s16) (s32) (s16) sp1E, var_s0);
    if (temp_v0_2 == -1)
    {
        goto block_247;
    }
    temp_v1 = var_s0->type;
    temp_s5 = var_s0->hit_points;
    switch (temp_v1)
    {
case 0xDF:
    if (temp_v0_2 != 6)
    {
        goto block_242;
    }
    if (poing.is_returning != 0)
    {
        goto block_242;
    }
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
    {
        goto block_242;
    }
    poing.damage = 1;
    obj_hurt(var_s0);
    if (var_s0->hit_points == 0)
    {
        goto block_23;
    }
    if (var_s0->sub_etat != test_1)
    {
        goto block_22;
    }
    set_sub_etat(var_s0, 4);
    goto block_242;
block_22:
    set_sub_etat(var_s0, 0xD);
    goto block_242;
block_23:
    if (var_s0->sub_etat != test_1)
    {
        goto block_25;
    }
    level.objects[var_s0->field24_0x3e].flags &= ~0x400;
    DO_NOVA(&level.objects[var_s0->field24_0x3e]);
block_25:
    set_sub_etat(var_s0, 8);
    var_s0->field23_0x3c = test_3;
    goto block_242;
case 0xDA:
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
    {
        goto block_242;
    }
    if (temp_v0_2 == 3)
    {
        goto block_29;
    }
    if (temp_v0_2 != 6)
    {
        goto block_242;
    }
block_29:
    poing.damage = 1;
    obj_hurt(var_s0);
    if (var_s0->hit_points == 0)
    {
        skipToLabel(var_s0, 2, 1);
        var_s0->field23_0x3c = 1;
        goto block_242;
    }
    else
    {
        skipToLabel(var_s0, 4, 1);
        goto block_242;
    }
case 0x62:
case 0xD5:
    doMereDenisHit(var_s0, temp_v0_2);
    goto block_242;
case 0xD4:
    DO_DARK_POING_COLLISION(var_s0);
    goto block_242;
case 0x78:
    if (temp_v0_2 != test_1)
    {
        goto block_242;
    }
    DO_BAT_POING_COLLISION(var_s0);
    goto block_242;
case 0xBB:
    if (temp_v0_2 != 5)
    {
        goto block_242;
    }
    DO_PMA_POING_COLLISION(var_s0);
    goto block_242;
case 0x32:
case 0xE3:
    doMoskitoHit(var_s0);
    goto block_242;
case 0x8E:
    if (!(RayEvts.flags0 & 0x80))
    {
        goto block_242;
    }
    if (ray_mode == 3)
    {
        goto block_242;
    }
    temp_s1->field20_0x36 = (s16) (u16) var_s0->id;
    goto block_242;
case 0x8C:
    if ((RayEvts.flags0 & 0x80) && (ray_mode != 3))
    {
        temp_a1_2 = var_s0->offset_by;
        temp_v1_2 = (ray.y_pos + ray.offset_by) - var_s0->y_pos;
        temp_v0_4 = temp_v1_2 - temp_a1_2;
        /* should be abs, see DoPTGRAPPINPoingCollision of android */
        if (temp_v0_4 >= 0)
        {
            if (temp_v0_4 < 0xFA)
            {
                goto block_47;
            }
        }
        else if ((temp_a1_2 - temp_v1_2) < 0xFA)
        {
block_47:
            SET_RAY_BALANCE();
            id_obj_grapped = (s16) (u16) var_s0->id;
            temp_v0_5 = ANGLE_RAYMAN(var_s0);
            var_s0->follow_x = temp_v0_5;
            if (temp_v0_5 >= 0x101)
                var_s0->field24_0x3e = -1;
            else if (temp_v0_5 < 0x101)
            {
                if(temp_v0_5 == 0x0100 && !(ray.flags & 0x4000))
                    var_s0->field24_0x3e = -1;
                else
                    var_s0->field24_0x3e = 1;
            }
            else /* ??? */
                var_s0->field24_0x3e = 1;
            
            if ((var_s0->main_etat == 0) && (var_s0->sub_etat == 0))
            {
                skipToLabel(var_s0, 0, 1);
            }
            poing.is_active = 0;
            poing.is_returning = 0;
            temp_s1->flags &= ~0x400;
            temp_s1->flags &= ~0x800;
            fin_poing_follow(temp_s1, 0U);
        }
    }
    goto block_242;
case 0x98:
    if (var_s0->main_etat != 0)
    {
        goto block_57;
    }
    if (var_s0->sub_etat == test_1)
    {
        goto block_242;
    }
block_57:
    set_main_and_sub_etat(var_s0, 1, 1);
    temp_v1_3 = var_s0->flags;
    if (temp_v1_3 & 0x4000)
    {
        goto block_59;
    }
    var_s0->flags = temp_v1_3 | 0x4000;
    var_a1_2 = 3;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
block_59:
    var_s0->flags = temp_v1_3 & test_2;
    var_a1_2 = 2;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
case 0x7B:
    obj_hurt(var_s0);
    if (var_s0->hit_points != 0)
    {
        goto block_242;
    }
    set_main_and_sub_etat(var_s0, 0, 4);
    var_s0->speed_y = 0;
    temp_v0_6 = temp_s1->speed_x;
    if (temp_v0_6 < 0)
    {
        goto block_66;
    }
    if (temp_v0_6 <= 0)
    {
        goto block_64;
    }
    var_v0_3 = var_s0->flags;
    var_v0_3 = var_v0_3 & test_2;
    goto block_67;
block_64:
    if (!(temp_s1->flags & 0x4000))
    {
        goto block_66;
    }
    var_v0_3 = var_s0->flags & test_2;
    goto block_67;
block_66:
    var_v0_3 = var_s0->flags | 0x4000;
block_67:
    var_s0->flags = var_v0_3;
    allocateBlacktoonEyes(var_s0);
    if (!(var_s0->flags & 0x4000))
    {
        goto block_69;
    }
    var_a1_2 = 2;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
block_69:
    var_a1_2 = 3;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
case 0x65:
    if (temp_v0_2 != 4)
    {
        goto block_242;
    }
    if (var_s0->sub_etat != 5)
    {
        goto block_242;
    }
    temp_v0_7 = temp_s1->speed_x;
    if (temp_v0_7 < 0)
    {
        goto block_78;
    }
    if (temp_v0_7 > 0)
    {
        goto block_75;
    }
    if (!(temp_s1->flags & 0x4000))
    {
        goto block_78;
    }
block_75:
    set_sub_etat(var_s0, 9);
    goto block_242;
case 0x91:
    temp_v0_8 = var_s0->hit_points - 1;
    var_s0->hit_points = temp_v0_8;
    if (!(temp_v0_8 & 0xFF))
    {
        goto block_78;
    }
    set_sub_etat(var_s0, 5);
    var_s0->iframes_timer = 0x0032;
    goto block_242;
block_78:
    set_sub_etat(var_s0, 6);
    goto block_242;
case 0x4D:
case 0xEF:
    DO_PAR_POING_COLLISION(var_s0, temp_v0_2);
    goto block_242;
case 0x48:
    DO_NGW_POING_COLLISION(var_s0);
    goto block_242;
case 0x3A:
    obj_hurt(var_s0);
    if (var_s0->hit_points != 0)
    {
        goto block_83;
    }
    var_s0->init_main_etat = 0;
    var_s0->init_sub_etat = 8;
    var_s0->init_x_pos = (s16) (u16) var_s0->x_pos;
    var_s0->init_y_pos = (s16) (u16) var_s0->y_pos;
    set_sub_etat(var_s0, 0xC);
    var_s0->init_flag = 7;
    ALLOCATE_MEDAILLON_TOON();
    lidol_to_allocate = 5;
    lidol_source_obj = var_s0;
    Nb_total_cages += 1;
    take_bonus(var_s0->id);
    goto block_242;
block_83:
    set_sub_etat(var_s0, 0xA);
    goto block_242;
case 0x2E:
    if (temp_v0_2 != 9)
    {
        goto block_242;
    }
    DO_BBMONT_TOUCHE(var_s0);
    goto block_242;
case 0x5A:
case 0x5B:
case 0x5C:
case 0x5D:
case 0xB6:
    DO_NOTE_TOUCHEE(var_s0);
    goto block_242;
case 0x60:
    DO_TOTEM_TOUCHE(var_s0, temp_v0_2);
    goto block_242;
case 0x6F:
    if (var_s0->main_etat != 0)
    {
        goto block_242;
    }
    if (Mus_obj_id < 0)
    {
        goto block_242;
    }
    PlaySnd(0x0053, var_s0->id);
    var_s0->hit_points--;
    temp_v1_4 = var_s0->hit_points;
    if (temp_v1_4 == test_2)
    {
        goto block_98;
    }
    if ((s32) temp_v1_4 >= 2)
    {
        goto block_94;
    }
    if (temp_v1_4 == 0)
    {
        goto block_99;
    }
    goto block_242;
block_94:
    if (temp_v1_4 == test_1)
    {
        goto block_97;
    }
    if (temp_v1_4 != 3)
    {
        goto block_242;
    }
    set_sub_etat(var_s0, 4);
    allocateEclatPS(var_s0, 7);
    set_sub_etat(&level.objects[Mus_obj_id], 6);
    goto block_242;
block_97:
    set_sub_etat(var_s0, 6);
    allocateEclatPS(var_s0, 8);
    goto block_242;
block_98:
    set_sub_etat(var_s0, 8);
    allocateEclatPS(var_s0, 9);
    goto block_242;
block_99:
    if (level.objects[Mus_obj_id].sub_etat != 6)
    {
        goto block_242;
    }
    PlaySnd(0x0053, var_s0->id);
    set_sub_etat(var_s0, 9);
    level.objects[Mus_obj_id].sub_etat = 3;
    level.objects[Mus_obj_id].init_sub_etat = 4;
    var_s0->init_sub_etat = 0x0A;
    goto block_242;
case 0x6D:
    if (var_s0->main_etat != 0)
    {
        goto block_242;
    }
    obj_hurt(var_s0);
    if (var_s0->hit_points != 0)
    {
        goto block_106;
    }
    DO_PI_EXPLOSION(var_s0);
    var_s0->flags &= ~0x800;
    if (ray.field20_0x36 != var_s0->id)
    {
        goto block_105;
    }
    ray.field20_0x36 = -1;
    var_s0->ray_dist = 0x03E8;
    set_main_and_sub_etat(&ray, 2, 2);
block_105:
    var_v1 = -0x401;
    var_s0->flags &= var_v1;
    goto block_242; /* supposed to go somewhere in case 0x64 instead */
block_106:
    set_sub_etat(var_s0, 1);
    var_s0->anim_frame = 0;
    goto block_242;
case 0xA6:
    DO_LEV_POING_COLLISION(var_s0);
    goto block_242;
case 0x41:
    obj_hurt(var_s0);
    if (var_s0->hit_points != 0)
    {
        goto block_110;
    }
    set_main_and_sub_etat(var_s0, 0, 7);
    var_s0->anim_frame = 0;
    goto block_226;
block_110:
    if (var_s0->main_etat != 0)
    {
        goto block_114;
    }
    temp_v1_5 = var_s0->sub_etat;
    if ((u32) (temp_v1_5 - 2) < 2U)
    {
        goto block_113;
    }
    if ((u32) (temp_v1_5 - 4) >= 2U)
    {
        goto block_114;
    }
block_113:
    var_s0->cmd_context_index = 0xFF;
block_114:
    var_s0->field23_0x3c = 0;
    if (level.objects[poing_obj_id].speed_x <= 0)
    {
        goto block_116;
    }
    skipToLabel(var_s0, 3, 1);
    var_v0_3 = var_s0->flags | 0x4000;
    goto block_117;
block_116:
    skipToLabel(var_s0, 1, 1);
    var_v0_3 = var_s0->flags;
    var_v0_3 &= test_2;
block_117:
    var_s0->flags = var_v0_3;
    pushToLabel(var_s0, 6, 1);
    var_s0->anim_frame = 0;
    pushToLabel(var_s0, 7, 1);
    goto block_242;
case 0x28:
case 0x7A:
    obj_hurt(var_s0);
    if (var_s0->hit_points == 0)
    {
        goto block_225;
    }
    skipToLabel(var_s0, 5, 1);
    var_s0->gravity_value_2 = 7;
    var_s0->change_anim_mode = test_1;
    temp_v0_9 = temp_s1->speed_x;
    if (temp_v0_9 <= 0)
    {
        goto block_121;
    }
    var_s0->flags &= test_2;
    goto block_242;
block_121:
    if (temp_v0_9 >= 0)
    {
        goto block_242;
    }
    var_s0->flags |= 0x4000;
    goto block_242;
case 0x24:
case 0x2F:
case 0x45:
    set_sub_etat(var_s0, 1);
    DO_STONE_EXPLOSION(var_s0);
    goto block_242;
case 0x23:
case 0x2B:
    DO_PNG_COLL_STONEMAN(var_s0);
    goto block_242;
case 0x38:
case 0xAC:
    DO_PNG_COLL_STONEWOMAN(var_s0);
    goto block_242;
case 0x1:
    if (temp_v0_2 != var_s0->hit_sprite)
    {
        goto block_242;
    }
    temp_v0_10 = temp_s1->speed_x;
    if (temp_v0_10 <= 0)
    {
        goto block_129;
    }
    set_sub_etat(var_s0, 0x19);
    goto block_242;
block_129:
    if (temp_v0_10 >= 0)
    {
        goto block_242;
    }
    set_sub_etat(var_s0, 0x1A);
    goto block_242;
case 0x6:
case 0x8:
case 0x86:
case 0xA7:
case 0xB1:
    temp_v1_6 = var_s0->type;
    if (temp_v1_6 == 0x86)
    {
        goto block_139;
    }
    if ((s32) temp_v1_6 >= 0x87)
    {
        goto block_136;
    }
    if (temp_v1_6 == 6)
    {
        goto block_140;
    }
    if (temp_v1_6 == 8)
    {
        goto block_139;
    }
    goto block_141;
block_136:
    if (temp_v1_6 == 0xA7)
    {
        goto block_139;
    }
    if (temp_v1_6 == 0xB1)
    {
        goto block_140;
    }
    goto block_141;
block_139:
    PlaySnd(0x002C, var_s0->id);
    goto block_141;
block_140:
    PlaySnd(0x008B, var_s0->id);
block_141:
    var_v0_5 = var_s2 * 4;
    switch (poing.sub_etat)
    {
case 1:
case 3:
case 5:
    var_s2 = poing.damage;
    var_v0_5 = var_s2 * 4;
    break;
case 8:
case 10:
case 12:
    var_s2 = poing.damage - 2;
case 2:
case 4:
case 6:
case 7:
case 9:
case 11:
    var_v0_5 = var_s2 * 4;
    }
    var_s2 = var_v0_5 + var_s2 + 0xA;
    if (temp_s1->speed_x < 0)
    {
        var_s2 = -var_s2;
    }
    make_my_fruit_go_down(var_s0, var_s2);
    goto block_242;
case 0x25:
    set_main_and_sub_etat(var_s0, 0, 1);
    var_s0->cmd = 0;
    goto block_242;
case 0x14:
    if (temp_v0_2 == 0)
    {
        poing.damage = 1;
        obj_hurt(var_s0);
        if (var_s0->hit_points == 0)
        {
            var_a1_2 = 4;
            skipToLabel(var_s0, 4, 1);
            goto block_242;
        }
        var_a1_2 = 3;
        skipToLabel(var_s0, 3, 1);
        goto block_242;
    }
block_153:
    var_a1_2 = test_1;
    skipToLabel(var_s0, 2, 1);
    goto block_242;
case 0xC:
case 0xE:
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
    {
        goto block_242;
    }
case 0xA:
    obj_hurt(var_s0);
    if (var_s0->hit_points == 0)
    {
        goto block_157;
    }
    var_s0->speed_x = 0;
    var_s0->speed_y = 0;
    set_main_and_sub_etat(var_s0, 0, 1);
    goto block_158;
block_157:
    set_main_and_sub_etat(var_s0, 0, 3);
block_158:
    if (var_s0->type != 0x0A)
    {
        goto block_160;
    }
    DESACTIVE_FISH_COLLIS(var_s0);
block_160:
    if (var_s0->flags & 0x4000)
    {
        goto block_162;
    }
    var_s0->cmd = 0;
    goto block_242;
block_162:
    var_s0->cmd = 1;
    goto block_242;
case 0x9:
case 0xA5:
    if (temp_v0_2 == 0x00FF)
    {
        goto block_165;
    }
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 1))
    {
        goto block_242;
    }
block_165:
    obj_hurt(var_s0);
    if (var_s0->hit_points != 0)
    {
        goto block_167;
    }
    set_main_and_sub_etat(var_s0, 0, 3);
    skipToLabel(var_s0, 2, 1);
    var_s0->y_pos = (u16) var_s0->y_pos - 2;
    var_s0->flags &= 0xFFFF7FFF;
    goto block_242;
block_167:
    if (!(temp_s1->flags & 0x4000))
    {
        goto block_172;
    }
    temp_v0_11 = temp_s1->speed_x;
    if (temp_v0_11 < 0)
    {
        goto block_170;
    }
    var_a1_3 = 3;
    skipToLabel(var_s0, var_a1_3, 1);
    goto block_177;
block_170:
    if (temp_v0_11 >= -1)
    {
        goto block_177;
    }
    var_a1_3 = 2;
    skipToLabel(var_s0, var_a1_3, 1);
    goto block_177;
block_172:
    temp_a0 = temp_s1->speed_x;
    var_a1_3 = 3;
    if (temp_a0 < 2)
    {
        goto block_174;
    }
    skipToLabel(var_s0, var_a1_3, 1);
    goto block_177;
block_174:
    if (temp_a0 > 0)
    {
        goto block_177;
    }
block_175:
    var_a1_3 = 2;
block_176:
    skipToLabel(var_s0, var_a1_3, 1);
block_177:
    var_s0->speed_x = 0;
    var_s0->speed_y = -4;
    var_s0->y_pos = (u16) var_s0->y_pos - 2;
    set_main_and_sub_etat(var_s0, 2, 2);
    PlaySnd(0x001C, var_s0->id);
    goto block_242;
case 0x0:
    obj_hurt(var_s0);
    temp_v0_12 = temp_s1->speed_x;
    if (temp_v0_12 <= 0)
    {
        goto block_180;
    }
    var_a1_4 = 3;
    skipToLabel(var_s0, var_a1_4, 1);
    goto block_182;
block_180:
    var_a1_4 = 2;
    if (temp_v0_12 >= 0)
    {
        goto block_182;
    }
block_181:
    skipToLabel(var_s0, var_a1_4, 1);
block_182:
    var_s0->speed_x = 0;
    var_s0->y_pos = (u16) var_s0->y_pos - 2;
    if (var_s0->hit_points == 0)
    {
        goto block_187;
    }
    var_s0->speed_y = -4;
    var_a2 = 2;
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 0x40))
    {
        goto block_185;
    }
    var_a2 = 0xA;
block_185:
    set_main_and_sub_etat(var_s0, 2, var_a2);
block_186:
    PlaySnd(0x001C, var_s0->id);
    goto block_242;
block_187:
    var_s0->speed_y = -8;
    var_a2_2 = 3;
    if (!(var_s0->eta[var_s0->main_etat][var_s0->sub_etat].flags & 0x40))
    {
        goto block_189;
    }
    var_a2_2 = 6;
block_189:
    set_main_and_sub_etat(var_s0, 0, var_a2_2);
    goto block_242;
case 0x46:
    obj_hurt(var_s0);
    temp_v0_13 = temp_s1->speed_x;
    if (temp_v0_13 <= 0)
    {
        goto block_192;
    }
    var_v0_3 = var_s0->flags;
    var_v0_3 &= test_2;
    goto block_194;
block_192:
    if (temp_v0_13 >= 0)
    {
        goto block_195;
    }
    var_v0_3 = var_s0->flags | 0x4000;
block_194:
    var_s0->flags = var_v0_3;
block_195:
    if (var_s0->hit_points != 0)
    {
        goto block_203;
    }
    set_main_and_sub_etat(var_s0, 0, 1);
    var_v1 = 0xFFFF7FFF;
    var_s0->cmd = test_1;
    var_s0->flags &= var_v1;
    goto block_242;
case 0x3C:
case 0x3D:
    obj_hurt(var_s0);
    temp_v0_14 = temp_s1->speed_x;
    if (temp_v0_14 <= 0)
    {
        goto block_199;
    }
    var_v0_3 = var_s0->flags;
    var_v0_3 &= test_2;
    goto block_201;
block_199:
    if (temp_v0_14 >= 0)
    {
        goto block_202;
    }
    var_v0_3 = var_s0->flags | 0x4000;
block_201:
    var_s0->flags = var_v0_3;
block_202:
    if (var_s0->hit_points == 0)
    {
        goto block_204;
    }
block_203:
    var_s0->y_pos = (u16) var_s0->y_pos - 2;
    skipToLabel(var_s0, 4, 1);
    goto block_242;
block_204:
    set_main_and_sub_etat(var_s0, 0, 3);
    var_v1 = 0xFFFF7FFF;
    var_s0->cmd = 0;
    var_s0->flags &= var_v1;
    goto block_242;
case 0x74:
case 0x75:
case 0x76:
    obj_hurt(var_s0);
    temp_v0_15 = temp_s1->speed_x;
    if (temp_v0_15 <= 0)
    {
        goto block_207;
    }
    var_v0_3 = var_s0->flags;
    var_v0_3 &= test_2;
    goto block_209;
block_207:
    if (temp_v0_15 >= 0)
    {
        goto block_210;
    }
    var_v0_3 = var_s0->flags | 0x4000;
block_209:
    var_s0->flags = var_v0_3;
block_210:
    if (var_s0->hit_points == 0)
    {
        goto block_213;
    }
    var_a1_2 = 5;
    if (var_s0->flags & 0x4000)
    {
        skipToLabel(var_s0, var_a1_2, 1);
        goto block_242;
    }
    var_a1_2 = 6;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
block_213:
    set_main_and_sub_etat(var_s0, 0, 2);
    goto block_226;
case 0xD9:
    if (temp_v0_2 != test_3)
    {
        goto block_242;
    }
    temp_v0_16 = temp_s1->speed_x;
    if (temp_v0_16 <= 0)
    {
        goto block_217;
    }
    var_v0_3 = var_s0->flags;
    var_v0_3 &= test_2;
    goto block_219;
block_217:
    if (temp_v0_16 >= 0)
    {
        goto block_220;
    }
    var_v0_3 = var_s0->flags | 0x4000;
block_219:
    var_s0->flags = var_v0_3;
case 0x64:
block_220:
    if (temp_v0_2 != test_3)
    {
        goto block_242;
    }
    obj_hurt(var_s0);
    if (var_s0->hit_points == 0)
    {
        goto block_225;
    }
    var_a1_2 = 4;
    skipToLabel(var_s0, var_a1_2, 1);
    goto block_242;
block_225:
    set_main_and_sub_etat(var_s0, 0, 3);
block_226:
    var_v1 = 0xFFFF7FFF;
block_227:
    var_s0->flags &= var_v1;
    goto block_242;
case 0x96:
    DO_SKO_HIT(var_s0);
    goto block_242;
case 0xAE:
case 0xB8:
case 0xE1:
case 0xE2:
    DO_PIRATE_POELLE_POING_COLLISION(var_s0);
    goto block_242;
case 0xE7:
case 0xE8:
    DO_HYB_BBF2_POING_COLLISION(var_s0);
    goto block_242;
case 0xC3:
    DO_SPIDER_PLAFOND_POING_COLLISION(var_s0);
    goto block_242;
case 0xE4:
    if (var_s0->screen_x_pos >= (temp_s1->screen_x_pos + 0x1E))
    {
        goto block_242;
    }
    if (var_s0->main_etat != 0)
    {
        goto block_242;
    }
    if (var_s0->sub_etat != 0)
    {
        goto block_242;
    }
    skipToLabel(var_s0, 2, 1);
    var_s0->init_sub_etat = test_1;
    prise_branchee = 1;
    finBosslevel[1] |= 4;
    goto block_242;
case 0x84:
    if (var_s0->main_etat != test_1)
    {
        goto block_238;
    }
    if (var_s0->sub_etat == 0x12)
    {
        goto block_242;
    }
block_238:
    skipToLabel(var_s0, 0xC, 1);
    var_s0->speed_x = 0;
    var_s0->speed_y = 0;
    var_s0->hit_points = 0;
    goto block_242;
case 0x81:
    temp_v1_7 = var_s0->hit_points;
    if (temp_v1_7 == test_1)
    {
        goto block_241;
    }
    if (temp_v1_7 != 4)
    {
        goto block_242;
    }
block_241:
    var_s0->hit_points--;
    }
block_242:
    do_boum();
    var_s0->gravity_value_1 = 0;
    if ((u32) (((u8) var_s0->eta[var_s0->main_etat][var_s0->sub_etat].anim_speed >> 4) - 0xA) < 2U)
    {
        goto block_244;
    }
    var_s0->gravity_value_2 = 0;
block_244:
    if (var_s0->hit_points != temp_s5)
    {
        goto block_249;
    }
    if (!(flags[var_s0->type].flags3 & 1))
    {
        goto block_249;
    }
    PlaySnd(0x00D6, var_s0->id);
    return;
block_247:
block_248:
    var_s5 = var_s5 + 1;
    var_s0 = &level.objects[actobj.objects[var_s5]];
    if (var_s5 < actobj.num_active_objects)
    {
        goto loop_7;
    }
block_249:
    return;
}

/* some bad instructions and reg swaps. not sure if i botched something */
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
  s32 new_var;
  s32 new_var2;
  
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
    x = x + (((s16) h >> 1) - (obj->detect_zone >> 1));
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
      y = y + (h >> 1);
      h = h + obj->detect_zone * 4 + (h >> 1);
    }
    break;
  case 0x7b:
    new_var2 = -1;
    bVar5 = obj->follow_sprite;
    switch(bVar5)
    {
    case 3:
      if ((obj->main_etat == 0) && (obj->sub_etat == 0)) {
        h = obj->detect_zone + h;
        y = y - (ushort)obj->detect_zone;
        w = obj->detect_zone + w;
        x = x - (ushort)(obj->detect_zone >> 1);
      }
      break;
    case 7:
      if (((obj->main_etat == 1)) && (obj->sub_etat == 1)) {
        x = x + new_var2 + (w >> 1);
        y = y + ((s16) h >> 1);
        w = 0x14;
        h = obj->detect_zone + h;
        if ((obj->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          x = x + -w;
        }
      }
      break;
    case 4:
      y = y - (obj->detect_zone + h);
      w = (u16) w * 2;
      x = x - ((s16) w >> 1);
      h = obj->detect_zone + h;
      break;
    case 2:
      y = y - (obj->detect_zone + h);
      h = obj->detect_zone + h;
      w = w + (ushort)obj->detect_zone * 2;
      x = x - (ushort)obj->detect_zone;
      break;
    }
    break;
  case 0x84:
    new_var = x;
    if ((obj->flags & FLG(OBJ_FLIP_X))) {
      new_var = x + w;
    }
    else
      new_var = x - w;
    x = new_var;
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
    x = (ushort)obj->offset_bx + obj->x_pos;
    w = 0x10;
    y = 0;
    h = mp.height << 4;
    break;
  case 0x3d:
    h = (obj->detect_zone >> 1) + h;
    y = y - (ushort)(obj->detect_zone >> 1);
    standard_frontZone(obj,&x,&w);
    break;
  case 0xe:
    h = (ushort)obj->detect_zone;
    y = y - (ushort)(obj->detect_zone >> 1);
    w = w + (ushort)obj->detect_zone * 2;
    x = x - (ushort)obj->detect_zone;
    break;
  case 5:
  case 0xc:
  case 0x14:
  case 0x51:
  case 0xa8:
  case 0xa9:
    w = w + (ushort)obj->detect_zone * 2;
    x = x - (ushort)obj->detect_zone;
    break;
  case 0x74:
    if (!(obj->flags & 0x4000))
    {
        x = (u16) x + (((s32) (w) >> 0x1) - ((u8) obj->detect_zone >> 1));
    }
    else
    {
        x = (u16) x + ((s32) (w) >> 0x1);
    }
    w = (ushort)(obj->detect_zone >> 1);
    y = y + ((s16) h >> 1);
    h = (ushort)obj->detect_zone + ((s16) h >> 1);
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
  sVar4 = inter_box((int)x,(int)y,(int)(short)w,(int)(short)h,(int)ray_zdc_x,(int)ray_zdc_y,
                    (int)ray_zdc_w,(int)ray_zdc_h);
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