#include "obj_init_kill.h"

/* matches, but the ones that have "TODO:" are still rough */
/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);*/

void INIT_OBJECTS(u8 new_lvl)
{
    s16 unk_1;
    s16 unk_2;
    s16 cnt_1;
    Obj *cur_obj;
    u8 nb_objs;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;
    s16 unk_6;
    u16 unk_7;
    s16 unk_8;
    u16 unk_9;
    s32 unk_10;
    s32 unk_11;
    s16 unk_12;
    Obj *prev_obj;
    Obj *pa_obj;
    Obj *eau_obj_1;
    Obj *eau_obj_2;
    
    unk_1 = -1;
    unk_2 = -1;
    ray_on_poelle = false;
    nb_cymbal_in_map = 0;
    PS1_SplashAlwaysObjectsCount = 0;
    IsBossThere = false;
    PS1_AlwaysObjectsCount = 0;
    Mus_obj_id = unk_1;
    NumScrollObj = 0;
    rayman_obj_id = unk_1;
    reduced_rayman_id = unk_1;
    id_Cling_1up = unk_1;
    id_Cling_Pow = unk_1;
    fee_obj_id = unk_1;
    eau_obj_id = unk_1;
    mst_scroll_obj_id = unk_1;
    bateau_obj_id = unk_1;
    mama_pirate_obj_id = unk_1;
    black_ray_obj_id = unk_1;
    pierreAcorde_obj_id = unk_1;
    nb_wiz = 0;
    stosko_obj_id = unk_1;
    moskitomama_droite_obj_id = unk_1;
    moskitomama_gauche_obj_id = unk_1;
    moskitosaxo_obj_id = unk_1;
    corde_dark_obj_id = unk_1;

    cnt_1 = 0;
    cur_obj = &level.objects[cnt_1];
    nb_objs = level.nb_objects;
    while (cnt_1 < nb_objs)
    {
        cur_obj->id = cnt_1;
        if (new_lvl)
            first_obj_init(cur_obj);
        
        cur_obj->active_timer = 0;
        if (cur_obj->type == TYPE_INDICATOR)
        {
            cur_obj->main_etat = cur_obj->init_main_etat;
            cur_obj->sub_etat = cur_obj->init_sub_etat;
        }

        obj_init(cur_obj);
        if (flags[cur_obj->type].flags0 & FLG(OBJ0_ALWAYS))
        {
            cur_obj->x_pos = -32000;
            cur_obj->y_pos = -32000;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
        }
        else
            cur_obj->flags |= FLG(OBJ_ALIVE);
        
        switch (cur_obj->type)
        {
        case TYPE_PLANCHES:
            cur_obj->x_pos = 1;
            break;
        case TYPE_VAGUE_DERRIERE:
            cur_obj->x_pos += 2;
            break;
        case TYPE_SUPERHELICO:
            if (!(RayEvts.super_helico))
            {
                unk_3 = cur_obj->flags & ~FLG(OBJ_ALIVE);
                unk_4 = (finBosslevel[1] << 7) & FLG(OBJ_ALIVE);
                cur_obj->flags = unk_3 | unk_4;
            }
            else
                cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_TOTEM:
            cur_obj->field23_0x3c = 0;
            cur_obj->iframes_timer = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_CORDE_DARK:
            corde_dark_obj_id = cur_obj->id;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_HYBRIDE_STOSKO:
            cur_obj->field23_0x3c = 0;
            stosko_obj_id = cur_obj->id;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_HYBRIDE_MOSAMS:
            cur_obj->field23_0x3c = 0;
            moskitosaxo_obj_id = cur_obj->id;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_HYB_BBF2_D:
            unk_1 = cur_obj->id;
            cur_obj->field23_0x3c = 0;
            moskitomama_droite_obj_id = cur_obj->id;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_HYB_BBF2_G:
            unk_2 = cur_obj->id;
            cur_obj->field23_0x3c = 0;
            moskitomama_gauche_obj_id = cur_obj->id;
            cur_obj->flags |= FLG(OBJ_FLIP_X);
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_STOSKO_PINCE:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_PIERREACORDE:
            pierreAcorde_obj_id = cnt_1;
            cur_obj->iframes_timer = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_CORDE:
            cur_obj->hit_points = (cur_obj->init_hit_points >> 2);
            cur_obj->flags |= FLG(OBJ_ALIVE);
            if (pierreAcorde_obj_id != -1)
            {
                /* TODO: ??? */
                pa_obj = &level.objects[pierreAcorde_obj_id];
                if (cur_obj->x_pos < pa_obj->x_pos)
                    cur_obj->y_pos = pa_obj->y_pos + 112;
                else
                    cur_obj->y_pos = pa_obj->y_pos + 120;
                
                cur_obj->y_pos = cur_obj->init_y_pos;
            }
            break;
        case TYPE_SMA_WEAPON:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_HERSE_BAS_NEXT:
        case TYPE_HERSE_HAUT_NEXT:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_EAU:
            if (cur_obj->hit_points != 0)
            {
                /* TODO: ??? */
                unk_5 = cur_obj->offset_bx;
                unk_6 = xmap - unk_5;
                cur_obj->x_pos = unk_6;
                if (num_world == 1)
                {
                    if (RayEvts.grain)
                        cur_obj->hit_points = 1;
                    cur_obj->y_pos = ymapmax + SCREEN_HEIGHT;
                }
                else
                {
                    cur_obj->hit_points = 0;
                    cur_obj->field23_0x3c = unk_6;
                    if (!(num_world == 3 && num_level == 7))
                    {
                        cur_obj->init_y_pos =
                        cur_obj->y_pos =
                            ymapmax + 160;
                        if (
                            (num_world == 5 && num_level == 8) ||
                            num_world == 4
                        )
                        {
                            cur_obj->init_y_pos =
                            cur_obj->y_pos =
                                ymapmax + 170;
                        }
                    }
                    else
                    {
                        /* TODO: ??? */
                        unk_7 = cur_obj->init_y_pos;
                        cur_obj->field12_0x26 = 0;
                        cur_obj->init_y_pos = unk_7;
                    }
                }
                eau_obj_id = cnt_1;
                cur_obj->iframes_timer = 0;
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                calc_obj_pos(cur_obj);
            }
            else if (!(eau_obj_id == -1 || num_world == 1))
            {
                cur_obj->speed_y = 0;
                cur_obj->speed_x = 0;
                cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLIP_X));
                eau_obj_1 = &level.objects[eau_obj_id];
                unk_8 = eau_obj_1->field23_0x3c + 101;
                eau_obj_1->field23_0x3c = unk_8;
                cur_obj->x_pos = unk_8;
                cur_obj->y_pos = level.objects[eau_obj_id].y_pos;
                if (!(num_world == 3 && num_level == 7))
                {
                    cur_obj->init_y_pos = ymapmax + 160;
                    if (num_world == 4)
                        cur_obj->init_y_pos = ymapmax + 170;
                    
                    if (num_world == 5 && num_level == 8)
                    {
                        unk_9 = (level.objects[eau_obj_id].y_pos + eau_obj_id) - cur_obj->id;
                        cur_obj->y_pos = unk_9;
                        cur_obj->init_y_pos = unk_9;
                    }
                }
                else
                {
                    cur_obj->init_y_pos = cur_obj->y_pos;
                    cur_obj->field12_0x26 = 0;
                }
                calc_obj_pos(cur_obj);
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                eau_obj_2 = &level.objects[eau_obj_id];
                cur_obj->sub_etat = ++eau_obj_2->hit_points;
                if (cur_obj->sub_etat >= 4)
                    cur_obj->sub_etat -= 4;
                cur_obj->iframes_timer = 0;
            }
            else
            {
                cur_obj->flags &= ~FLG(OBJ_ALIVE);
                cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            }
            break;
        case TYPE_TARZAN:
            unk_10 = cur_obj->flags & ~FLG(OBJ_ALIVE);
            unk_11 = !RayEvts.grain;
            cur_obj->flags = unk_10 | (unk_11 << OBJ_ALIVE);
            break;
        case TYPE_FEE:
            fee_obj_id = cnt_1;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_MST_SCROLL:
            if (cur_obj->hit_points == 0)
            {
                cur_obj->x_pos =
                cur_obj->init_x_pos =
                    ray.x_pos - 200;
                cur_obj->y_pos = ray.y_pos - 50;
                set_main_and_sub_etat(cur_obj, 0, 9);
                cur_obj->speed_x = 2;
                cur_obj->speed_y = 0;
                cur_obj->field23_0x3c = 0;
                cur_obj->field24_0x3e = 0;
                cur_obj->timer = 0;
                mst_scroll_obj_id = cnt_1;
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                cur_obj->flags |= FLG(OBJ_FLIP_X);
            }
            else
                cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_DEMI_RAYMAN:
            reduced_rayman_id = cnt_1;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_RAY_POS:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_SCROLL:
            scroll_obj_id[NumScrollObj] = cnt_1;
            NumScrollObj++;
            cur_obj->y_pos = cur_obj->init_y_pos;
            cur_obj->x_pos = cur_obj->init_x_pos;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_FALLING_OBJ:
        case TYPE_FALLING_OBJ2:
        case TYPE_FALLING_OBJ3:
        case TYPE_FALLING_YING:
        case TYPE_FALLING_YING_OUYE:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_BADGUY2:
        case TYPE_BADGUY3:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_STONEDOG2:
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_CYMBALE:
            cymbal_obj_id[nb_cymbal_in_map++] = cnt_1;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_RAYMAN:
            rayman_obj_id = cnt_1;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_BLACK_FIST:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            black_fist_obj_id = cur_obj->id;
            break;
        case TYPE_POING:
            cur_obj->sub_etat =
            cur_obj->init_sub_etat =
                poing.sub_etat;
            poing_obj_id = cnt_1;
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_BOUM:
            sbar_obj_id = cnt_1;
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_KILLING_EYES:
            cur_obj->iframes_timer = 40;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_PHOTOGRAPHE:
            cur_obj->timer = 0;
            break;
        case TYPE_SPLASH:
            PS1_SplashAlwaysObjects[PS1_SplashAlwaysObjectsCount++] = cnt_1;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_NEN_GRAINE:
            cur_obj->iframes_timer = 0;
        case TYPE_GRAINE:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_SPIDER:
            cur_obj->field24_0x3e = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_PAILLETTE:
        case TYPE_DESTROYING_DOOR:
            unk_12 = (
                cur_obj->animations[
                    cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_index
                ].frames_count - 1) *
                (cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf);
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->field23_0x3c = unk_12;
            cur_obj->field24_0x3e = unk_12;
            break;
        case TYPE_BB1_PLAT:
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_GENEBADGUY:
            cur_obj->init_flag = 7;
            cur_obj->timer = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_CAGE:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_BALLE1:
        case TYPE_BALLE2:
        case TYPE_DARK2_SORT:
        case TYPE_STONEBOMB:
        case TYPE_CLASH:
        case TYPE_MST_FRUIT1:
        case TYPE_MST_FRUIT2:
        case TYPE_CAGE2:
        case TYPE_DROP:
        case TYPE_DARD:
        case TYPE_NOTE:
        case TYPE_RING:
        case TYPE_PIRATE_BOMB:
        case TYPE_STONECHIP:
        case TYPE_EXPLOSION:
        case TYPE_NOTE0:
        case TYPE_NOTE1:
        case TYPE_NOTE2:
        case TYPE_BONNE_NOTE:
        case TYPE_BBL:
        case TYPE_BNOTE:
        case TYPE_DARK2_PINK_FLY:
        case TYPE_PI_BOUM:
        case TYPE_WASHING_MACHINE:
        case TYPE_TNT_BOMB:
        case TYPE_ECLAIR:
        case TYPE_BLACKTOON_EYES:
        case TYPE_ETINC:
        case TYPE_MARACAS_BAS:
        case TYPE_NOVA2:
        case TYPE_FLASH:
        case TYPE_POELLE_ALWAYS:
        case TYPE_SMA_GRAND_LASER:
        case TYPE_SMA_BOMB:
        case TYPE_SMA_BOMB_CHIP:
        case TYPE_DARD_PLAFOND:
        case TYPE_MEDAILLON_TOON:
        case TYPE_PIEDS_RAYMAN:
        case TYPE_FIRE_LEFT:
        case TYPE_FIRE_RIGHT:
        case TYPE_DARK_SORT:
        case TYPE_HYB_BBF2_LAS:
        case TYPE_SMA_PETIT_LASER:
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_BLACK_RAY:
            cur_obj->animations = ray.animations;
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            black_ray_obj_id = cur_obj->id;
            break;
        case TYPE_COUTEAU:
            cur_obj->field20_0x36 = 1;
            cur_obj->iframes_timer = 1;
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        case TYPE_LIDOLPINK:
            cur_obj->init_flag = 7;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_FISH:
            if (cnt_1 > 0)
            {
                prev_obj = &level.objects[cnt_1 - 1];
                cur_obj->flags |= FLG(OBJ_ALIVE);
                if (prev_obj->type == TYPE_FISH && prev_obj->x_pos == cur_obj->x_pos)
                {
                    cur_obj->flags &= ~FLG(OBJ_ACTIVE);
                    cur_obj->flags &= ~FLG(OBJ_ALIVE);
                }
            }
            break;
        case TYPE_BB1:
        case TYPE_BB12:
        case TYPE_BB13:
            INIT_BBMONT(cur_obj);
            break;
        case TYPE_POI1:
        case TYPE_POI2:
        case TYPE_POI3:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_FLAMME2:
        case TYPE_CLE_SOL:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_PI_MUS:
            if (finBosslevel[1] & FLG(3))
            {
                set_sub_etat(cur_obj, 10);
                cur_obj->init_sub_etat = 10;
            }
        case TYPE_PI:
            cur_obj->init_flag = 7;
            PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = cur_obj->id;
            PS1_AlwaysObjectsCount++;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_MUS_WAIT:
            cur_obj->init_flag = 7;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            Mus_obj_id = cur_obj->id;
            if (finBosslevel[1] & FLG(3))
            {
                cur_obj->init_sub_etat = 4;
                set_main_and_sub_etat(cur_obj, 0, 4);
            }
            break;
        case TYPE_JAUGEUP:
        case TYPE_ONEUP:
        case TYPE_GRAP_BONUS:
            cur_obj->init_flag = 7;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_NEUTRAL:
        case TYPE_TAMBOUR2:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_TIBETAIN_6:
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_BATEAU:
            cur_obj->field23_0x3c = -1;
            cur_obj->field24_0x3e = 0;
            cur_obj->timer = 0;
            bateau_obj_id = cnt_1;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_MAMA_PIRATE:
            mama_pirate_obj_id = cnt_1;
            cur_obj->flags |= FLG(OBJ_ALIVE);
            break;
        case TYPE_POING_FEE:
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            break;
        case TYPE_DARK_PHASE2:
            cur_obj->init_x_pos = 0;
            cur_obj->x_pos = 0;
            cur_obj->init_y_pos = 0;
            cur_obj->y_pos = 0;
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        }

        if (t_world_info[world_index].nb_cages == 6 && cur_obj->type == TYPE_CAGE)
        {
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            take_bonus(cur_obj->id);
        }

        if (
            (
                !bonus_map &&
                flags[cur_obj->type].flags1 >> OBJ1_BONUS & 1 &&
                bonus_taken(cur_obj->id)
            ) || (cur_obj->type == TYPE_PALETTE_SWAPPER))
        {
            cur_obj->flags &= ~FLG(OBJ_ACTIVE);
            cur_obj->flags &= ~FLG(OBJ_ALIVE);
        }

        if (bonus_map && cur_obj->type == TYPE_WIZ)
            nb_wiz++;
        
        cnt_1++;
        cur_obj++;
    }

    if (!(unk_1 == -1 || unk_2 == -1))
    {
        level.objects[unk_1].field24_0x3e = unk_2;
        level.objects[unk_2].field24_0x3e = unk_1;
    }

    if (bonus_map)
    {
        nb_wiz_save = status_bar.num_wiz;
        status_bar.num_wiz = 0;
    }
}
const u8 rodata_INIT_OBJECTS[4] = {};

/* matches, but gotos and other cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);*/

void SET_ACTIVE_FLAG(s16 x, s16 y, Obj *obj)
{
    Obj *temp_s0_2;
    Obj *temp_s0_4;
    u8 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 temp_a0;
    u32 temp_v1_1;
    u8 temp_s0_1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 var_a0;
    u8 var_a0_2;
    u8 var_a0_3;
    u8 var_a1;
    u8 var_a1_2;
    Obj *temp_s0_3;
    u32 test_1;

    ot = obj->type;
    temp_s0_1 = (obj->flags >> 0xB) & 1;
    obj->flags &= ~0x800;
    if (obj->flags & 0x400)
    {
        if (in_action_zone(x, y, obj, temp_s0_1))
        {
            if (
                obj->active_timer == 0 &&
                ((flags[ot].flags1 & 1) || (obj->active_flag != 2 && (obj->active_flag != 4 || ot == 0x0A)))
            )
            {
                test_1 = obj->flags & ~0x800;
                test_1 |= temp_s0_1 << 0xB;
                obj->flags = test_1;
                if (flags[ot].flags0 & 1)
                {
                    var_a1 = 0;
                    if (!(obj->flags & 0x800))
                    {
                        var_a1 = flags[obj->type].flags1 & 1;
                    }
                    make_active(obj, var_a1);
                }
                else
                {
                    var_a0 = obj->id;
                    do
                    {
                        temp_s0_2 = &level.objects[var_a0];
                        var_a1 = 0;
                        if (!(temp_s0_2->flags & 0x800))
                        {
                            var_a1 = flags[obj->type].flags1 & 1;
                        }
                        make_active(temp_s0_2, var_a1);
                        var_a0 = link_init[temp_s0_2->id];
                    } while (var_a0 != obj->id);
                }
            }
            else if (obj->active_timer > 0)
            {
                obj->active_timer -= 1;
            }
        }
        else
        {
            obj->active_timer = 0;
            if (((u8) flags[ot].flags2 >> 5) & 1)
            {
                kill_obj(obj);
            }
            else
            {
                temp_v1_3 = obj->active_flag;
                if (temp_v1_3 == 2)
                {
                    obj->active_flag = 1;
                }
                else if (temp_v1_3 == 0 || obj->active_flag == 4)
                {
                    if (flags[ot].flags0 & 1)
                    {
                        REINIT_OBJECT(obj);
                        return;
block_1:
                        var_t0 = 1;
                        goto block_2;
                    }
                    else
                    {
                        obj->active_flag = 4;
                        var_a0 = obj->id;
                        obj->flags |= 0x800;
                        var_t0 = 0;
                        if (ot != 0x0A)
                        {
                            while (true)
                            {
                                
                                temp_s0_2 = &level.objects[var_a0];
                                if (temp_s0_2->active_flag == 4)
                                {
                                    var_a0 = link_init[temp_s0_2->id];
                                    if (var_a0 == obj->id)
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    goto block_1;
                                    break;
                                }
                            }
                        }
block_2:                        
                        if ((obj->y_pos + obj->offset_by) < -0x1E)
                        {
                            obj->flags &= ~0x800;
                        }
                        if (!var_t0)
                        {
                            var_a0 = obj->id;
                            do
                            {
                                temp_s0_2 = &level.objects[var_a0];
                                REINIT_OBJECT(temp_s0_2);
                                var_a0 = link_init[temp_s0_2->id];
                            } while (var_a0 != obj->id);
                        }
                    }
                }
            }
        }
    }
}