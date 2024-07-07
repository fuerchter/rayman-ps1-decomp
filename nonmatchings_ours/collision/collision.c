#include "collision/collision.h"

/*INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_v_line);*/
/* ??? think param_6 and 7 might be s32 ??? */

s32 box_inter_v_line(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7)
{
  s32 res = false;
  if ((param_1 >= param_5) || (param_2 <= param_5)) {

  }
  else if ((param_6 < param_3) && (param_7 > param_3)) {
    res = true;
  }
  else if (param_7 > param_4 && param_6 < param_4)
  {
    res = true;
  }
  return res;
}

/*INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_h_line);*/

s32 box_inter_h_line(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7)
{
  s32 res = false;
  if ((param_3 >= param_5) || (param_4 <= param_5)) {
  }
  else if ((param_6 < param_1) && (param_7 > param_1)) {
    res = true;
  }
  else if(param_7 > param_2 && param_6 < param_2)
  {
    res = true;
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
    s16 temp_v1_6;
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
    s32 test_2;

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
                    test_2 = (temp_v1_3->layers_count & 0x3FFF) * obj->anim_frame + temp_a1_2 * 4;
                    if (temp_v1_3->layers[test_2].sprite != 0)
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
            var_v0_1 = inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26);
            if (!var_v0_1)
                var_v0_1 = -1;
        }
        else
        {
            /*var_v0_1 = -1;*/
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
                        do { } while (0); /* TODO: ??? */
                    }
                    var_s2_2++;
                }
            }
        }
    }
    return var_v0_1;
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

void DO_POING_COLLISION(void)
{
    s16 pspr_x; s16 pspr_y; s16 pspr_w; s16 pspr_h;
    u8 label;
    u8 sub_etat;
    Obj *poing_obj;
    Obj *other_obj;
    s16 temp_v0_1;
    s32 sprite;
    s32 temp_v0_5;
    s16 pspeed_x;
    s16 i;
    s32 temp_v1_2;
    u8 btyp;
    u8 temp_a1_2;
    u8 old_hp;
    s32 fall_x_accel;

    poing_obj = &level.objects[poing_obj_id];
    btyp = 0;
    /* TODO: already being weird in multiple ways */
    GET_SPRITE_POS(poing_obj, 0, &pspr_x, &pspr_y, &pspr_w, &pspr_h);
    if ((temp_v0_1 = poing_obj->speed_x) > 0 || poing_obj->speed_x < 0)
        btyp = PS1_BTYPAbsPos(
            poing_obj->x_pos + poing_obj->offset_bx,
            poing_obj->y_pos + (poing_obj->offset_by + poing_obj->offset_hy >> 1)
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
            if (new_world || new_level || fin_boss)
                break;
        
            if (
                other_obj->display_prio != 0 && other_obj->hit_points != 0 &&
                other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & FLG(3)
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
                            other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & FLG(0)
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
                        DO_DARK_POING_COLLISION(other_obj);
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
                        doMoskitoHit(other_obj);
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
                                
                                if (other_obj->main_etat == 0 && other_obj->sub_etat == 0)
                                    skipToLabel(other_obj, 0, true);
                                poing.is_active = false;
                                poing.is_returning = false;
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
                                else /* pspeed_x == 0 */
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
                        if (--other_obj->hit_points != 0)
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
                        DO_NOTE_TOUCHEE(other_obj);
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
                        if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 1)
                        {
                    case TYPE_FISH: /* TODO: kinda gross fall-through? */
                            obj_hurt(other_obj);
                            if (other_obj->hit_points != 0)
                            {
                                other_obj->speed_x = 0;
                                other_obj->speed_y = 0;
                                set_main_and_sub_etat(other_obj, 0, 1);
                            }
                            else
                                set_main_and_sub_etat(other_obj, 0, 3);

                            if (other_obj->type == TYPE_FISH)
                                DESACTIVE_FISH_COLLIS(other_obj);

                            if (!(other_obj->flags & FLG(OBJ_FLIP_X)))
                                other_obj->cmd = GO_LEFT;
                            else
                                other_obj->cmd = GO_RIGHT;
                        }
                        break;
                    case TYPE_BADGUY2:
                    case TYPE_BADGUY3:
                        if (
                            (sprite == 0xFF) ||
                            (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & FLG(0))
                        )
                        {
                            obj_hurt(other_obj);
                            if (other_obj->hit_points == 0)
                            {
                                set_main_and_sub_etat(other_obj, 0, 3);
                                skipToLabel(other_obj, 2, true);
                                other_obj->y_pos -= 2;
                                other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            }
                            else
                            {
                                if (poing_obj->flags & FLG(OBJ_FLIP_X))
                                {
                                    pspeed_x = poing_obj->speed_x;
                                    if (pspeed_x >= 0)
                                        skipToLabel(other_obj, 3, true);
                                    else if (pspeed_x < -1)
                                        skipToLabel(other_obj, 2, true);
                                }
                                else
                                {
                                    pspeed_x = poing_obj->speed_x;
                                    if (pspeed_x >= 2)
                                        skipToLabel(other_obj, 3, true);
                                    else if (pspeed_x <= 0)
                                        skipToLabel(other_obj, 2, true);
                                }
                                other_obj->speed_x = 0;
                                other_obj->speed_y = -4;
                                other_obj->y_pos -= 2;
                                set_main_and_sub_etat(other_obj, 2, 2);
                                PlaySnd(28, other_obj->id);
                            }
                        }
                        break;
                    case TYPE_BADGUY1:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                            skipToLabel(other_obj, 3, true);
                        else if (pspeed_x < 0)
                            skipToLabel(other_obj, 2, true);
                        other_obj->speed_x = 0;
                        other_obj->y_pos -= 2;
                        if (other_obj->hit_points != 0)
                        {
                            other_obj->speed_y = -4;
                            if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 0x40)
                                sub_etat = 10;
                            else
                                sub_etat = 2;
                            set_main_and_sub_etat(other_obj, 2, sub_etat);
                            PlaySnd(28, other_obj->id);
                            break;
                        }
                        else
                        {
                            other_obj->speed_y = -8;
                            if (other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & 0x40)
                                sub_etat = 6;
                            else
                                sub_etat = 3;
                            set_main_and_sub_etat(other_obj, 0, sub_etat);
                        }
                        break;
                    case TYPE_TROMPETTE:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (pspeed_x < 0)
                            other_obj->flags |= FLG(OBJ_FLIP_X);
                        
                        if (other_obj->hit_points == 0)
                        {
                            set_main_and_sub_etat(other_obj, 0, 1);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            other_obj->cmd = GO_WAIT;
                            break;
                        }
                        other_obj->y_pos -= 2;
                        skipToLabel(other_obj, 4, true);
                        break;
                    case TYPE_BIG_CLOWN:
                    case TYPE_WAT_CLOWN:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (pspeed_x < 0)
                            other_obj->flags |= FLG(OBJ_FLIP_X);
                        
                        if (other_obj->hit_points != 0)
                        {
                            other_obj->y_pos -= 2;
                            skipToLabel(other_obj, 4, true);
                        }
                        else
                        {
                            set_main_and_sub_etat(other_obj, 0, 3);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            other_obj->cmd = GO_LEFT;
                        }
                        break;
                    case TYPE_CLOWN_TNT:
                    case TYPE_CLOWN_TNT2:
                    case TYPE_CLOWN_TNT3:
                        obj_hurt(other_obj);
                        pspeed_x = poing_obj->speed_x;
                        if (pspeed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (pspeed_x < 0)
                            other_obj->flags |= FLG(OBJ_FLIP_X);
                        
                        if (other_obj->hit_points != 0)
                        {
                            
                            if (!(other_obj->flags & FLG(OBJ_FLIP_X)))
                            {
                                label = 6;
                            }
                            else
                                label = 5;
                            skipToLabel(other_obj, label, true);
                            break;
                        }
                        set_main_and_sub_etat(other_obj, 0, 2);
                        other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                        break;
                    case TYPE_MITE2:
                        if (sprite == 1)
                        {
                            pspeed_x = poing_obj->speed_x;
                            if (pspeed_x > 0)
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                            else if (pspeed_x < 0)
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                        }
                    case TYPE_MITE:
                        if (sprite == 1)
                        {
                            obj_hurt(other_obj);
                            if (other_obj->hit_points != 0)
                                skipToLabel(other_obj, 4, true);
                            else
                            {
                                set_main_and_sub_etat(other_obj, 0, 3);
                                other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            }
                        }
                        break;
                    case TYPE_SCORPION:
                        DO_SKO_HIT(other_obj);
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
                        if (
                            other_obj->screen_x_pos < (poing_obj->screen_x_pos + 30) &&
                            other_obj->main_etat == 0 && other_obj->sub_etat == 0
                        )
                        {
                            skipToLabel(other_obj, 2, true);
                            other_obj->init_sub_etat = 2;
                            prise_branchee = true;
                            finBosslevel[1] |= FLG(2);
                        }
                        break;
                    case TYPE_POI3:
                        if (!(other_obj->main_etat == 2 && other_obj->sub_etat == 18))
                        {
                            skipToLabel(other_obj, 12, true);
                            other_obj->speed_x = 0;
                            other_obj->speed_y = 0;
                            other_obj->hit_points = 0;
                        }
                        break;
                    case TYPE_PETIT_COUTEAU:
                        if (other_obj->hit_points == 2 || other_obj->hit_points == 4)
                            other_obj->hit_points--;
                        break;
                    }
                    do_boum();
                    other_obj->gravity_value_1 = 0;
                    /* TODO: temp_v0_5 is strange (see other use above) */
                    temp_v0_5 = other_obj->eta[other_obj->main_etat][other_obj->sub_etat].anim_speed >> 4;
                    if (!(temp_v0_5 == 10 || temp_v0_5 == 11))
                        other_obj->gravity_value_2 = 0;
                    
                    if (other_obj->hit_points == old_hp && (flags[other_obj->type].flags3 & FLG(OBJ3_POING_COLLISION_SND)))
                        PlaySnd(214, other_obj->id);
                    break;
                }
            }
            i++;
            other_obj = &level.objects[actobj.objects[i]];
        }
    }
}

/* matches, but cleanup */
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
  s32 new_var3;
  s32 test_1;
  s32 test_2;
  s32 test_3;
  s32 test_4;
  
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
      y = y + (h >> 1);
      test_4 = obj->detect_zone * 4 + (h >> 1);
      h = h + test_4;
    }
    break;
  case 0x7b:
    new_var2 = -1;
    switch(obj->follow_sprite)
    {
    case 3:
      if ((obj->main_etat == 0) && (obj->sub_etat == 0)) {
        h = h + obj->detect_zone;
        y = y - obj->detect_zone;
        w = w + obj->detect_zone;
        x = x - (obj->detect_zone >> 1);
      }
      break;
    case 7:
      if (((obj->main_etat == 1)) && (obj->sub_etat == 1)) {
        x = x + new_var2 + (w >> 1);
        y = y + (h >> 1);
        w = 0x14;
        h = h + obj->detect_zone;
        if ((obj->flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE) {
          x = x + -w;
        }
      }
      break;
    case 4:
      y = y - (obj->detect_zone + h);
      x = x - (w >> 1);
      w += w;
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
      new_var3 = new_var1 + w;
    }
    else
    {
      new_var3 = new_var1 - w;
    }
    x = new_var3;
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