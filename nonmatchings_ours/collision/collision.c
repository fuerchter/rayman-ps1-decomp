#include "collision/collision.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_POING_COLLISION);*/

void DO_POING_COLLISION(void)
{
    s16 pspr_x; s16 pspr_y; s16 pspr_w; s16 pspr_h;
    u8 label;
    u8 sub_etat;
    Obj *poing_obj;
    Obj *other_obj;
    s16 temp_v0_1;
    s32 sprite;
    s32 unk_1;
    s16 png_spd_x;
    s16 i;
    u8 btyp;
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
                            other_obj->eta[other_obj->main_etat][other_obj->sub_etat].flags & FLG(0) &&
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
                        if (RayEvts.grap && ray_mode != MODE_MORT_DE_RAYMAN)
                            poing_obj->field20_0x36 = other_obj->id;
                        break;
                    case TYPE_PT_GRAPPIN:
                        if (RayEvts.grap && ray_mode != MODE_MORT_DE_RAYMAN)
                        {
                            if (
                                ABS_LT(
                                    (ray.y_pos + ray.offset_by) -
                                    other_obj->y_pos - other_obj->offset_by, 250)
                            )
                            {
                                SET_RAY_BALANCE();
                                id_obj_grapped = other_obj->id;
                                
                                other_obj->follow_x =
                                unk_1 =
                                    ANGLE_RAYMAN(other_obj);
                                if (unk_1 > 256)
                                    other_obj->field24_0x3e = -1;
                                else if (unk_1 <= 256)
                                {
                                    if(unk_1 == 256 && !(ray.flags & FLG(OBJ_FLIP_X)))
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
                            png_spd_x = poing_obj->speed_x;
                            if (png_spd_x >= 0)
                            {
                                if (png_spd_x > 0)
                                    other_obj->flags &= ~FLG(OBJ_FLIP_X);
                                else /* png_spd_x == 0 */
                                {
                                    if (poing_obj->flags & FLG(OBJ_FLIP_X))
                                        other_obj->flags &= ~FLG(OBJ_FLIP_X);
                                    else
                                        other_obj->flags |= FLG(OBJ_FLIP_X);
                                }
                            }
                            else if (png_spd_x < 0)
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
                            if (poing_obj->speed_x >= 0 && (poing_obj->speed_x > 0 || poing_obj->flags & FLG(OBJ_FLIP_X)))
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
                        DO_NGW_POING_COLLISION(other_obj);
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
                                (other_obj->sub_etat == 2 || other_obj->sub_etat == 3 ||
                                other_obj->sub_etat == 4 || other_obj->sub_etat == 5)
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
                            if (poing_obj->speed_x > 0)
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                            else if (poing_obj->speed_x < 0)
                                other_obj->flags |= FLG(OBJ_FLIP_X);
                        }
                        else
                        {
                            set_main_and_sub_etat(other_obj, 0, 3);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
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
                            if (poing_obj->speed_x > 0)
                                set_sub_etat(other_obj, 25);
                            else if (poing_obj->speed_x < 0)
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
                                    if (poing_obj->speed_x >= 0)
                                        skipToLabel(other_obj, 3, true);
                                    else if (poing_obj->speed_x < -1)
                                        skipToLabel(other_obj, 2, true);
                                }
                                else
                                {
                                    if (poing_obj->speed_x >= 2)
                                        skipToLabel(other_obj, 3, true);
                                    else if (poing_obj->speed_x <= 0)
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
                        if (poing_obj->speed_x > 0)
                            skipToLabel(other_obj, 3, true);
                        else if (poing_obj->speed_x < 0)
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
                        if (poing_obj->speed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (poing_obj->speed_x < 0)
                            other_obj->flags |= FLG(OBJ_FLIP_X);
                        
                        if (other_obj->hit_points == 0)
                        {
                            set_main_and_sub_etat(other_obj, 0, 1);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                            other_obj->cmd = GO_WAIT;
                        }
                        else
                        {
                            other_obj->y_pos -= 2;
                            skipToLabel(other_obj, 4, true);
                        }
                        break;
                    case TYPE_BIG_CLOWN:
                    case TYPE_WAT_CLOWN:
                        obj_hurt(other_obj);
                        if (poing_obj->speed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (poing_obj->speed_x < 0)
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
                        if (poing_obj->speed_x > 0)
                            other_obj->flags &= ~FLG(OBJ_FLIP_X);
                        else if (poing_obj->speed_x < 0)
                            other_obj->flags |= FLG(OBJ_FLIP_X);
                        
                        if (other_obj->hit_points != 0)
                        {
                            if (!(other_obj->flags & FLG(OBJ_FLIP_X)))
                                label = 6;
                            else
                                label = 5;
                            skipToLabel(other_obj, label, true);
                        }
                        else
                        {
                            set_main_and_sub_etat(other_obj, 0, 2);
                            other_obj->flags &= ~FLG(OBJ_READ_CMDS);
                        }
                        break;
                    case TYPE_MITE2:
                        if (sprite == 1)
                        {
                            if (poing_obj->speed_x > 0)
                                other_obj->flags &= ~FLG(OBJ_FLIP_X);
                            else if (poing_obj->speed_x < 0)
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
                            other_obj->screen_x_pos < poing_obj->screen_x_pos + 30 &&
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
                    /* TODO: unk_1 is strange (see other use above) */
                    unk_1 = other_obj->eta[other_obj->main_etat][other_obj->sub_etat].anim_speed >> 4;
                    if (!(unk_1 == 10 || unk_1 == 11))
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

/* matches, but unk_1 */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_DETECT_ZONE_FLAG);*/

void SET_DETECT_ZONE_FLAG(Obj *obj)
{
    s16 obj_x; s16 obj_y; s16 obj_w; s16 obj_h;
    s32 unk_1;
    u16 det_zn_flg;
    
    GET_ANIM_POS(obj, &obj_x, &obj_y, &obj_w, &obj_h);
    switch(obj->type)
    {
    case TYPE_FEE:
        obj_x += (obj_h >> 1) - (obj->detect_zone >> 1);
        obj_y -= 16;
        obj_w = obj->detect_zone;
        obj_h += 64;
        break;
    case TYPE_MST_SHAKY_FRUIT:
        obj_y += obj_h;
        obj_h += 240;
        break;
    case TYPE_PIRATE_GUETTEUR:
    case TYPE_PIRATE_GUETTEUR2:
        standard_frontZone(obj, &obj_x, &obj_w);
        if (obj->main_etat == 0 && obj->sub_etat == 4)
        {
            obj_y += (obj_h >> 1);
            obj_h += (obj->detect_zone << 2) + (obj_h >> 1);
        }
        break;
    case TYPE_BLACKTOON1:
        unk_1 = -1;
        switch(obj->follow_sprite)
        {
        case 3:
            if (obj->main_etat == 0 && obj->sub_etat == 0)
            {
                obj_h += obj->detect_zone;
                obj_y -= obj->detect_zone;
                obj_w += obj->detect_zone;
                obj_x -= (obj->detect_zone >> 1);
            }
            break;
        case 7:
            if (obj->main_etat == 1 && obj->sub_etat == 1)
            {
                obj_x = obj_x + unk_1 + (obj_w >> 1);
                obj_y += (obj_h >> 1);
                obj_w = 20;
                obj_h += obj->detect_zone;
                if (!(obj->flags & FLG(OBJ_FLIP_X)))
                    obj_x -= obj_w;
            }
            break;
        case 4:
            obj_y -= obj->detect_zone + obj_h;
            obj_x -= (obj_w >> 1);
            obj_w += obj_w;
            obj_h += obj->detect_zone;
            break;
        case 2:
            obj_y -= obj->detect_zone + obj_h;
            obj_h = obj->detect_zone + obj_h;
            obj_w += obj->detect_zone * 2;
            obj_x -= obj->detect_zone;
            break;
        }
        break;
    case TYPE_POI3:
        obj_x += (obj->flags & FLG(OBJ_FLIP_X)) ? obj_w : -obj_w;
        obj_y -= 50;
        obj_h += 50;
        break;
    case TYPE_MST_SCROLL:
        if (obj->hit_points != 0)
        {
            obj_y = 0;
            obj_h = mp.height << 4;
        }
        break;
    case TYPE_SCROLL_SAX:
    case TYPE_BB1_VIT:
        obj_x = obj->x_pos + obj->offset_bx;
        obj_w = 16;
        obj_y = 0;
        obj_h = mp.height << 4;
        break;
    case TYPE_WAT_CLOWN:
        obj_h += (obj->detect_zone >> 1);
        obj_y -= (obj->detect_zone >> 1);
        standard_frontZone(obj, &obj_x, &obj_w);
        break;
    case TYPE_CHASSEUR2:
        obj_h = obj->detect_zone;
        obj_y -= (obj->detect_zone >> 1);
        obj_w += obj->detect_zone * 2;
        obj_x -= obj->detect_zone;
        break;
    case TYPE_WIZARD1:
    case TYPE_CHASSEUR1:
    case TYPE_GENEBADGUY:
    case TYPE_CYMBALE:
    case TYPE_CYMBAL1:
    case TYPE_CYMBAL2:
        obj_w += obj->detect_zone * 2;
        obj_x -= obj->detect_zone;
        break;
    case TYPE_CLOWN_TNT:
        if (!(obj->flags & FLG(OBJ_FLIP_X)))
            obj_x += (obj_w >> 1) - (obj->detect_zone >> 1);
        else
            obj_x += (obj_w >> 1);
        
        obj_w = (obj->detect_zone >> 1);
        obj_y += (obj_h >> 1);
        obj_h = (obj_h >> 1) + obj->detect_zone;
        break;
    case TYPE_STONEWOMAN:
    case TYPE_STONEWOMAN2:
        standard_frontZone(obj, &obj_x, &obj_w);
        obj_h = (obj_h << 1);
        break;
    case TYPE_MITE:
        unk_1 = 150;
        if (!(obj->flags & FLG(OBJ_FLIP_X)))
            obj_x -= obj->detect_zone;
        else
            obj_x = obj_x + -unk_1 + (obj_w >> 1);
        
        obj_w = obj->detect_zone + unk_1;
        obj_y -= ((obj->detect_zone - obj_h) >> 1);
        obj_h = obj->detect_zone;
        break;
    case TYPE_PIRATE_POELLE:
    case TYPE_PIRATE_P_45:
        standard_frontZone(obj, &obj_x, &obj_w);
        obj_h = 150;
        break;
    case TYPE_PIRATE_POELLE_D:
    case TYPE_PIRATE_P_D_45:
        standard_frontZone(obj, &obj_x, &obj_w);
        obj_h = 150;
        obj_x += 70;
        obj_y += 50;
        break;
    case TYPE_SPIDER_PLAFOND:
        if (
            (
                obj->main_etat == 0 &&
                (obj->sub_etat == 24 || obj->sub_etat == 30 || obj->sub_etat == 11)
            ) ||
            (obj->main_etat == 1 && obj->sub_etat == 2)
        )
        {
            obj_h = 10;
            obj_x -= 40;
            obj_w += 80;
        }
        else
        {
            obj_h = 200;
            obj_x -= 130;
            obj_w += 260;
        }
        break;
    case TYPE_DARK:
        standard_frontZone(obj, &obj_x, &obj_w);
        obj_h = 250;
        break;
    case TYPE_JOE:
        obj_h += 20;
        break;
    case TYPE_PHOTOGRAPHE:
        break;
    default:
        standard_frontZone(obj, &obj_x, &obj_w);
        break;
    }

    if (inter_box(obj_x, obj_y, obj_w, obj_h, ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h))
    {
        det_zn_flg = obj->detect_zone_flag;
        if (det_zn_flg == 0 || det_zn_flg == 1)
        {
            if (det_zn_flg == 0)
                obj->detect_zone_flag = 1;
            else if (det_zn_flg == 1)
                obj->detect_zone_flag = 2;
        }
        else
        {
            obj->detect_zone_flag++;
            if (obj->detect_zone_flag == 20)
                obj->detect_zone_flag = 2;
        }
    }
    else
    {
        obj->detect_zone_flag = 0;
        if (obj->type == TYPE_PHOTOGRAPHE)
            obj->flags &= ~FLG(OBJ_FLAG_0);
    }
}