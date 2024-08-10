#include "obj_init_kill.h"

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", obj_init);*/

void obj_init(Obj *obj)
{
    s16 temp_v0_1;
    s16 var_v0_5;
    s32 var_v1;
    u32 temp_a3;
    u32 var_v0;
    u32 var_v0_2;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 var_v0_3;
    u8 var_v0_4;
    void *temp_v1_2;
    void *temp_v1_3;
    u8 new_var;

    obj->nb_cmd = 0;
    obj->flags &= ~0x800;
    obj->display_prio = Prio(obj);
    obj->zdc = type_zdc[obj->type];
    if (obj->type != 0xA3)
    {
        obj->main_etat = obj->init_main_etat;
        obj->sub_etat = obj->init_sub_etat;
    }
    obj->anim_frame = 0;
    obj->speed_x = 0;
    
    obj->speed_y = 0;
    
    obj->x_pos = obj->init_x_pos;
    obj->y_pos = obj->init_y_pos;
    obj->anim_index = obj->eta[obj->main_etat][obj->sub_etat].anim_index;
    obj->flags &= ~0x4000;
    obj->change_anim_mode = 0;
    obj->gravity_value_1 = 0;
    obj->gravity_value_2 = 0;
    obj->detect_zone_flag = 0;
    obj->iframes_timer = -1;
    
    obj->field20_0x36 = -1;
    obj->cmd_offset = -1;
    temp_v0_1 = obj->cmds != null;
    temp_a3 = (obj->flags & ~FLG(OBJ_READ_CMDS)) | ((temp_v0_1) << OBJ_READ_CMDS);
    obj->flags = temp_a3;
    memset(obj->btypes, 0, 5);
    GET_OBJ_CMD(obj);
    
    obj->test_block_index = 0;
    obj->cmd_context_index = 0xFF;
    obj->active_flag = 1;
    obj->timer = 0;
    obj->field56_0x69 = 0;
    obj->hit_points = obj->init_hit_points;

    obj->flags &= 0xFFFDFFFF;
    obj->flags &= 0xFFFBFFFF;
    obj->flags &= 0xFFF7FFFF;
    
    switch (obj->type)
    {
    case 0x4A:
    case 0xB4:
    case 0xB7:
        INIT_SAXO(obj);
        return;
    case 0xE4:
        if (finBosslevel[1] & 4)
        {
            prise_branchee = 1;
            set_main_and_sub_etat(obj, 0U, 2U);
            obj->init_sub_etat = 2;
            skipToLabel(obj, 1U, 1U);
            return;
        }
    default:
    /*default:*/
        return;
    case 0xFB:
    case 0xFC:
        obj->init_x_pos = -0x000F;
        obj->x_pos = -0x000F;
        return;
    case 0xDA:
        bossXToReach = (s16) (u16) obj->x_pos;
        bossYToReach = (firstFloorBelow(&ray) - obj->offset_by) + 0x10;
        bossSpeedFactor = 0x00004000;
        alternateBossSpeedFactor = 0;
        return;
    case 0xB0:
    case 0xF0:
        obj->anim_frame = myRand(obj->animations[obj->anim_index].frames_count - 1);
        return;
    case 0xBF:
    case 0xEB:
        obj->anim_frame = obj->hit_points;
        return;
    case 0xAF:
    case 0xE5:
    case 0xE6:
    case 0xFA:
        var_v0 = (obj->flags & ~0x4000) | ((obj->hit_points & 1) << 0xE);
block_57:
        obj->flags = var_v0;
        break;
    case 0x33:
    case 0x35:
        obj->gravity_value_2 = 5;
        return;
    case 0x34:
        obj->gravity_value_2 = 0x0A;
        return;
    case 0x62:
        obj->type = 0xD5;
        
    case 0xD5:
        swapMereDenisCollZones(obj, 1U);
        PS1_setBossScrollLimits_spacemama(obj);
        bossSpeedFactor = 0x00004000;
        alternateBossSpeedFactor = 0;
        laserSourceSprNumInAnim = 0xFF;
        IsBossThere = 0;
        scrollLocked = 0;
        obj->timer = 0xB4;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = 0;
        bossEncounter = 0;
        return;
    case 0xE3:
        bossEncounter = 2;
        PS1_setBossScrollLimits_moskito(obj);
        bossSpeedFactor = 0x00004000;
        alternateBossSpeedFactor = 0;
        IsBossThere = 0;
        scrollLocked = 0;
        obj->timer = 0x64;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = 0;
        return;
    case 0x32:
        bossEncounter = 0;
        PS1_setBossScrollLimits_moskito(obj);
        bossSpeedFactor = 0x00004000;
        alternateBossSpeedFactor = 0;
        IsBossThere = 0;
        scrollLocked = 0;
        obj->timer = 0x64;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = 0;
        return;
    case 0x0:
        obj->offset_hy = 0x1E;
        obj->flags &= 0xFFFEFFFF;
        break;
    case 0x90:
        obj->iframes_timer = 0;
        return;
    case 0x7B:
        temp_v0_2 = obj->follow_sprite;
        switch (temp_v0_2)
        {
        case 1:
            var_v0_3 = 2;
            obj->field56_0x69 = var_v0_3;
            obj->detect_zone = 0;
            return;
        case 2:
            var_v0_4 = 8;
            obj->field56_0x69 = var_v0_4;
            obj->detect_zone = 0x3C;
            return;
        case 3:
            obj->field56_0x69 = 0x18;
            obj->detect_zone = 0xAA;
            return;
        case 4:
            obj->field56_0x69 = 0x0A;
            obj->detect_zone = 0x64;
            return;
        case 5:
            obj->field20_0x36 = 0;
            var_v0_3 = 1;
            obj->field56_0x69 = var_v0_3;
            obj->detect_zone = 0;
            return;
        case 6:
            var_v0_4 = 4;
            obj->field56_0x69 = var_v0_4;
            obj->detect_zone = 0x3C;
            return;
        case 7:
            obj->field56_0x69 = 0x24;
            obj->detect_zone = 0x78;
            return;
        }
        break;
    case 0x91:
        obj->field23_0x3c = 0x0028;
        obj->iframes_timer = 0x0028;
        return;
    case 0x48:
        obj->field56_0x69 = 1;
        return;
    case 0x4D:
    case 0xEF:
        FUN_80180b04((s32) obj, obj->init_sub_etat == 0x0E);
        obj->iframes_timer = 0;
        obj->detect_zone = 0x50;
        return;
    case 0x1C:
        obj->field20_0x36 = 0x0064;
        obj->iframes_timer = 0x0064;
        obj->flags |= 0x400;
        break;
    case 0x1A:
        if (num_world != 1)
        {
            var_v0_5 = vblToEOA(obj, 1U) - 2;
            obj->field23_0x3c = var_v0_5;
        }
        else
        {
            obj->field23_0x3c = 0x0028;
            var_v0_5 = 0x0014;
        }
        obj->iframes_timer = var_v0_5;
        obj->field24_0x3e = 0x0014;
        obj->flags |= 0x10400;
        break;
    case 0x19:
        obj->field20_0x36 = 0x000F;
        obj->iframes_timer = 0x000F;
        obj->flags |= 0x400;
        break;
    case 0x1D:
    case 0x22:
    case 0x98:
    case 0xED:
    case 0xF3:
        obj->field20_0x36 = 1;
        obj->iframes_timer = 1;
        obj->flags |= 0x400;
        break;
    case 0x74:
    case 0x75:
    case 0x76:
        obj->field56_0x69 = 0;
        
    case 0xA8:
    case 0xA9:
    case 0xB2:
    case 0xF1:
        obj->field24_0x3e = 0;
        return;
    case 0x96:
        obj->detect_zone = 0xA0;
        sko_phase = 0;
        return;
    case 0x15:
        var_v0 = obj->flags | 0x400;
        obj->flags = var_v0;
        break;
    case 0x7:
        var_v0 = obj->flags | 0x400;
        obj->flags = var_v0;
        break;
    case 0xB8:
    case 0xE2:
        var_v0 = obj->flags | 0x4000;
        obj->flags = var_v0;
        break;
    case 0xD4:
        obj->field23_0x3c = 0;
        return;
    case 0xD9:
        obj->eta[1]->flags = obj->eta[1]->flags & 0xef;
        obj->eta[1][2].flags = obj->eta[1][2].flags & 0xef;
        obj->field20_0x36 = 0;
        return;
    case 0xCA:
        if ((obj->main_etat == 0) && (obj->sub_etat == 0x39))
        {
            star_ray_der = obj;
        }
        else
        {
            star_ray_dev = obj;
        }
        obj->display_prio = 3;
        
    case 0xAA:
    case 0xC5:
        obj->flags &= ~0x400;
        obj->flags &= ~0x800;
        break;
    }
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);*/

void INIT_OBJECTS(u8 newLevel)
{
    Obj *temp_a0_4;
    Obj *temp_a0;
    Obj *temp_v0_5;
    Obj *temp_v1_2;
    Obj *var_s4;
    s16 temp_v0_3;
    s32 temp_a1;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 var_v1_2;
    s16 temp_lo;
    u16 temp_v0_2;
    u16 temp_v0_4;
    u16 temp_v0_6;
    s16 temp_v1_1;
    s32 test_1;
    u16 temp_v1_3;
    s16 var_s2;
    s16 var_s5;
    s16 var_s7;
    u16 var_v0_1;
    u16 var_v0_6;
    u16 var_v0_7;
    u8 temp_a0_2;
    u8 temp_fp;
    u8 temp_v0;
    u8 temp_v1_4;
    u8 temp_v1_5;
    void *temp_a0_3;

    var_s4 = level.objects;
    temp_fp = level.nb_objects;
    var_s5 = -1;
    var_s7 = -1;
    ray_on_poelle = 0;
    nb_cymbal_in_map = 0;
    PS1_SplashAlwaysObjectsCount = 0;
    IsBossThere = 0;
    PS1_AlwaysObjectsCount = 0;
    Mus_obj_id = -1;
    NumScrollObj = 0;
    rayman_obj_id = -1;
    reduced_rayman_id = -1;
    id_Cling_1up = -1;
    id_Cling_Pow = -1;
    fee_obj_id = -1;
    eau_obj_id = -1;
    mst_scroll_obj_id = -1;
    bateau_obj_id = -1;
    mama_pirate_obj_id = -1;
    black_ray_obj_id = -1;
    pierreAcorde_obj_id = -1;
    nb_wiz = 0;
    stosko_obj_id = -1;
    moskitomama_droite_obj_id = -1;
    moskitomama_gauche_obj_id = -1;
    moskitosaxo_obj_id = -1;
    corde_dark_obj_id = -1;
    var_s2 = 0;
    while ((s16) var_s2 < (s32) temp_fp)
    {
        var_s4->id = var_s2;
        if (newLevel != 0)
        {
            first_obj_init(var_s4);
        }
        var_s4->active_timer = 0;
        if (var_s4->type == 0xA3)
        {
            var_s4->main_etat = (u8) var_s4->init_main_etat;
            var_s4->sub_etat = (u8) var_s4->init_sub_etat;
        }
        obj_init(var_s4);
        if (flags[var_s4->type].flags0 & 1)
        {
            var_s4->x_pos = -0x7D00;
            var_s4->y_pos = -0x7D00;
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
        }
        else
        {
            var_s4->flags = (s32) (var_s4->flags | 0x400);
        }
        temp_v0 = var_s4->type;
        switch (temp_v0)
        {
        case 0xFD:
            var_s4->x_pos = 1U;
            break;
        case 0xFC:
            var_s4->x_pos = (u16) (var_s4->x_pos + 2);
            break;
        case 0x85:
            if (!(RayEvts.flags0 & 8))
            {
                var_v1 = var_s4->flags & ~0x400;
                var_v0_2 = (finBosslevel[1] << 7) & 0x400;
                var_s4->flags = (s32) (var_v1 | var_v0_2);
            }
            else
            {
                var_v0_3 = var_s4->flags & ~0x400;
                var_s4->flags = var_v0_3;
            }
            break;
        case 0x60:
            var_s4->field23_0x3c = 0U;
            var_s4->iframes_timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xF6:
            corde_dark_obj_id = (s16) var_s4->id;
            var_s4->flags |= 0x400;
            break;
        case 0xDF:
            var_s4->field23_0x3c = 0U;
            stosko_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xDA:
            var_s4->field23_0x3c = 0U;
            moskitosaxo_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE7:
            var_s5 = var_s4->id;
            var_s4->field23_0x3c = 0U;
            moskitomama_droite_obj_id = (s16) var_s4->id;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE8:
            var_s7 = var_s4->id;
            var_s4->field23_0x3c = 0U;
            moskitomama_gauche_obj_id = (s16) var_s4->id;
            var_s4->flags |= 0x4000;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0xE0:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xDC:
            pierreAcorde_obj_id = (s16) var_s2;
            var_s4->iframes_timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xDB:
            var_s4->hit_points = (u8) ((u8) var_s4->init_hit_points >> 2);
            var_s4->flags = (s32) (var_s4->flags | 0x400);
            if (pierreAcorde_obj_id != -1)
            {
                temp_a0 = &level.objects[pierreAcorde_obj_id];
                if ((s16) var_s4->x_pos < temp_a0->x_pos)
                {
                    var_s4->y_pos = (u16) temp_a0->y_pos + 0x70;
                }
                else
                {
                    var_s4->y_pos = (u16) temp_a0->y_pos + 0x78;
                }
                var_s4->y_pos = (u16) var_s4->init_y_pos;
            }
            break;
        case 0xCB:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xB3:
        case 0xF2:
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x9D:
            if (var_s4->hit_points != 0)
            {
                test_1 = var_s4->offset_bx;
                temp_v1_1 = xmap - test_1;
                var_s4->x_pos = temp_v1_1;
                if (num_world == 1)
                {
                    if (RayEvts.flags0 & 0x40)
                    {
                        var_s4->hit_points = 1U;
                    }
                    var_s4->y_pos = (u16) ((u16) ymapmax + 0xF0);
                }
                else
                {
                    var_s4->hit_points = 0U;
                    var_s4->field23_0x3c = temp_v1_1;
                    if ((num_world != 3) || (num_level != 7))
                    {
                        temp_v0_2 = (u16) ymapmax + 0xA0;
                        var_s4->y_pos = temp_v0_2;
                        var_s4->init_y_pos = temp_v0_2;
                        if (((num_world == 5) && (num_level == 8)) || (num_world == 4))
                        {
                            var_v0_7 = (u16) ymapmax + 0xAA;
                            var_s4->y_pos = var_v0_7;
                            var_s4->init_y_pos = var_v0_7;
                        }
                    }
                    else
                    {
                        var_v0_7 = var_s4->init_y_pos;
                        var_s4->field12_0x26 = 0;
                        var_s4->init_y_pos = var_v0_7;
                    }
                }
                eau_obj_id = (s16) var_s2;
                var_s4->iframes_timer = 0;
                var_s4->flags = (s32) (var_s4->flags | 0xC00);
                calc_obj_pos(var_s4);
            }
            else if ((eau_obj_id != -1) && (num_world != 1))
            {
                var_s4->speed_y = 0;
                var_s4->speed_x = 0;
                var_s4->flags = (s32) (var_s4->flags & ~0x4000);
                temp_v1_2 = &level.objects[eau_obj_id];
                temp_v0_3 = (u16) temp_v1_2->field23_0x3c + 0x65;
                temp_v1_2->field23_0x3c = temp_v0_3;
                var_s4->x_pos = (u16) temp_v0_3;
                temp_v1_3 = (u16) level.objects[eau_obj_id].y_pos;
                var_s4->y_pos = temp_v1_3;
                if ((num_world != 3) || (num_level != 7))
                {
                    var_s4->init_y_pos = (u16) ((u16) ymapmax + 0xA0);
                    if (num_world == 4)
                    {
                        var_s4->init_y_pos = (u16) ((u16) ymapmax + 0xAA);
                    }
                    if ((num_world == 5) && (num_level == 8))
                    {
                        temp_v0_4 = ((u16) level.objects[eau_obj_id].y_pos + eau_obj_id) - var_s4->id;
                        var_s4->y_pos = temp_v0_4;
                        var_s4->init_y_pos = temp_v0_4;
                    }
                }
                else
                {
                    var_s4->init_y_pos = temp_v1_3;
                    var_s4->field12_0x26 = 0;
                }
                calc_obj_pos(var_s4);
                var_s4->flags = (s32) (var_s4->flags | 0xC00);
                temp_v0_5 = &level.objects[eau_obj_id];
                temp_a0_2 = temp_v0_5->hit_points;
                temp_v1_4 = temp_a0_2 + 1;
                temp_v0_5->hit_points = temp_v1_4;
                var_s4->sub_etat = temp_v1_4;
                if ((u8) var_s4->sub_etat >= 4U)
                {
                    var_s4->sub_etat = (u8) (temp_a0_2 + 0xFD);
                }
                var_s4->iframes_timer = 0;
            }
            else
            {
                var_v0_4 = var_s4->flags & ~0x400;
                var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
            }
            break;
        case 0x25:
            var_s4->flags = (var_s4->flags & ~0x400 | (((((u8) RayEvts.flags0 >> 6) ^ 1) & 1) << 0xA));
            break;
        case 0x99:
            fee_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x93:
            if (var_s4->hit_points == 0)
            {
                temp_v0_6 = ray.x_pos - 0xC8;
                var_s4->init_x_pos = temp_v0_6;
                var_s4->x_pos = temp_v0_6;
                var_s4->y_pos = (u16) (ray.y_pos - 0x32);
                set_main_and_sub_etat(var_s4, 0U, 9U);
                var_s4->speed_x = 2;
                var_s4->speed_y = 0;
                var_s4->field23_0x3c = 0U;
                var_s4->field24_0x3e = 0U;
                var_s4->timer = 0;
                mst_scroll_obj_id = (s16) var_s2;
                var_s4->flags = (s32) (var_s4->flags | 0x4C00);
            }
            else
            {
                var_v0_3 = var_s4->flags | 0x400;
                var_s4->flags = var_v0_3; break;
            }
            break;
        case 0x88:
            reduced_rayman_id = (s16) var_s2;
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x63:
            var_v0_4 = var_s4->flags & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x40:
            scroll_obj_id[NumScrollObj] = (s16) var_s2;
            NumScrollObj += 1;
            var_s4->y_pos = var_s4->init_y_pos;
            var_s4->x_pos = var_s4->init_x_pos;
            var_s4->flags &= ~0x400;
            break;
        case 0x6:
        case 0x8:
        case 0x86:
        case 0xA7:
        case 0xB1:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x9:
        case 0xA5:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x7A:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x51:
            cymbal_obj_id[nb_cymbal_in_map++] = (s16) var_s2;
            /*nb_cymbal_in_map += 1;*/
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0x17:
            rayman_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xCD:
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            black_fist_obj_id = (s16) var_s4->id;
            break;
        case 0x5E:
            var_s4->sub_etat =
            var_s4->init_sub_etat =
                poing.sub_etat;
            poing_obj_id = var_s2;
            var_s4->init_flag = 7;
            var_s4->flags = (var_s4->flags & ~0x400);
            break;
        case 0xB:
            sbar_obj_id = (s16) var_s2;
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x91:
            var_s4->iframes_timer = 0x0028;
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0x15:
            var_s4->timer = 0;
            break;
        case 0x13:
            PS1_SplashAlwaysObjects[PS1_SplashAlwaysObjectsCount++] = (s16) var_s2;
            /*PS1_SplashAlwaysObjectsCount += 1;*/
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            break;
        case 0x27:
            var_s4->iframes_timer = 0;
            
        case 0x26:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x41:
            var_s4->field24_0x3e = 0U;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x4B:
        case 0x4C:
            /*temp_a0_3 = (var_s4->sub_etat * 8) + *((var_s4->main_etat * 4) + var_s4->unk-57);
            temp_lo = (((temp_a0_3->unk2 * 0xC) + var_s4->animations)->unkA - 1) * (temp_a0_3->unk5 & 0xF);*/
            temp_lo = (var_s4->animations
            [var_s4->eta[var_s4->main_etat][var_s4->sub_etat].anim_index].frames_count -
            1) * (var_s4->eta[var_s4->main_etat][var_s4->sub_etat].anim_speed & 0xf);
            var_s4->init_flag = 7;
            var_s4->flags = (s32) (var_s4->flags & ~0x400);
            var_s4->field23_0x3c = temp_lo;
            var_s4->field24_0x3e = temp_lo;
            break;
        case 0x73:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0x14:
            var_s4->init_flag = 7;
            var_s4->timer = 0;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x3A:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xD:
        case 0xF:
        case 0x21:
        case 0x24:
        case 0x2C:
        case 0x33:
        case 0x34:
        case 0x3B:
        case 0x3E:
        case 0x42:
        case 0x47:
        case 0x49:
        case 0x4E:
        case 0x4F:
        case 0x53:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x61:
        case 0x66:
        case 0x6C:
        case 0x6E:
        case 0x70:
        case 0x77:
        case 0x79:
        case 0x82:
        case 0x87:
        case 0x8B:
        case 0x8F:
        case 0x92:
        case 0xBA:
        case 0xC0:
        case 0xC1:
        case 0xC2:
        case 0xC4:
        case 0xC5:
        case 0xCE:
        case 0xD1:
        case 0xD2:
        case 0xD7:
        case 0xE9:
        case 0xF4:
            var_v0_5 = var_s4->flags;
            var_s4->init_flag = 7;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        case 0xCC:
            var_s4->animations = ray.animations;
            var_s4->init_flag = 7;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            black_ray_obj_id = var_s4->id;
            break;
        case 0xBE:
            var_s4->field20_0x36 = 1;
            var_s4->iframes_timer = 1;
            var_s4->init_flag = 7;
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            break;
        case 0x3:
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0xA:
            if (var_s2 > 0)
            {
                temp_a0_4 = &level.objects[var_s2 - 1];
                var_s4->flags = var_s4->flags | 0x400;
                if ((temp_a0_4->type == 0x0A) && (temp_a0_4->x_pos == var_s4->x_pos))
                {
                    var_s4->flags &= ~0x800;
                    var_s4->flags &= ~0x400;
                }
            }
            break;
        case 0x2E:
        case 0xC6:
        case 0xC8:
            INIT_BBMONT(var_s4);
            break;
        case 0x67:
        case 0x68:
        case 0x84:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x30:
        case 0x95:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x6F:
            if (finBosslevel[1] & 8)
            {
                set_sub_etat(var_s4, 0x0AU);
                var_s4->init_sub_etat = 0x0AU;
            }
            
        case 0x6D:
            var_s4->init_flag = 7;
            PS1_AlwaysObjects[PS1_AlwaysObjectsCount] = (s16) var_s4->id;
            PS1_AlwaysObjectsCount += 1;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x37:
            var_s4->init_flag = 7;
            var_s4->flags = (s32) (var_s4->flags | 0x400);
            Mus_obj_id = (s16) var_s4->id;
            if (finBosslevel[1] & 8)
            {
                var_s4->init_sub_etat = 4U;
                set_main_and_sub_etat(var_s4, 0U, 4U);
            }
            break;
        case 0x52:
        case 0x8E:
        case 0x94:
            var_s4->init_flag = 7;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x4:
        case 0x58:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0x9F:
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xAD:
            var_s4->field23_0x3c = -1;
            var_s4->field24_0x3e = 0U;
            var_s4->timer = 0;
            bateau_obj_id = (s16) var_s2;
            var_v1_2 = var_s4->flags | 0x400;
            var_s4->flags = var_v1_2;
            break;
        case 0xBB:
            mama_pirate_obj_id = (s16) var_s2;
            var_v0_3 = var_s4->flags | 0x400;
            var_s4->flags = var_v0_3; break;
        case 0xEE:
            var_v0_3 = var_s4->flags & ~0x400;
            var_s4->flags = var_v0_3; break;
        case 0x20:
            var_v0_5 = var_s4->flags;
            var_s4->init_x_pos = 0U;
            var_s4->x_pos = 0U;
            var_s4->init_y_pos = 0U;
            var_s4->y_pos = 0U;
            var_v0_4 = var_v0_5 & ~0x400;
            var_v0_3 = var_v0_4 & ~0x800;
            var_s4->flags = var_v0_3; break;
        }
        if ((t_world_info[world_index].nb_cages == 6) && (var_s4->type == 0x3A))
        {
            var_s4->flags &= ~0x400;
            var_s4->flags &= ~0x800;
            take_bonus((s16) var_s4->id);
        }
        if (((bonus_map == 0) && (((u8) flags[var_s4->type].flags1 >> 1) & 1) && (bonus_taken((s16) var_s4->id) & 0xFF)) || (var_s4->type == 0x9E))
        {
            var_s4->flags &= ~0x800;
            var_s4->flags &= ~0x400;
        }
        if (bonus_map != 0)
        {
            if (var_s4->type == 0xA1)
            {
                nb_wiz += 1;
            }
        }
        var_s2 = var_s2 + 1;
        var_s4 += 1;
    }

    if (((s16) var_s5 != -1) && ((s16) var_s7 != -1))
    {
        level.objects[(s16) var_s5].field24_0x3e = (s16) var_s7;
        level.objects[(s16) var_s7].field24_0x3e = (s16) var_s5;
    }
    if (bonus_map != 0)
    {
        temp_v1_5 = status_bar.num_wiz;
        status_bar.num_wiz = 0;
        nb_wiz_save = (s32) temp_v1_5;
    }
}
const u8 rodata_INIT_OBJECTS[4] = {};

/*INCLUDE_ASM("asm/nonmatchings/obj_init_kill", in_action_zone);*/

u8 in_action_zone(s16 x, s16 y, Obj *obj, u8 param_4)
{
    Obj *temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s32 var_s0;
    s32 var_v0;
    s16 var_v0_2;
    s32 var_v1;
    u16 var_s3;
    u16 var_s4;
    u8 temp_v1;
    u8 var_s6;
    ObjType new_var;

    var_s0 = 0;
    var_s4 = (u16) zonediffx[ot];
    var_s3 = (u16) zonediffy[ot];
    temp_v1 = flags[ot].flags0;
    var_s6 = obj->offset_bx;
    if ((temp_v1 >> 4) & 1)
    {
        if ((((temp_v1 >> 7) == 0) || (IsBossThere == 0)))
        {
            switch (new_var = ot)
            {
            case 0x5E:
            case 0x99:
            case 0xD7:
            case 0xBE:
            case 0x78:
            case 0x8F:
                var_s0 = 1;
                break;
            case 0x0a:
            case 0x61:
                var_v0_2 = x + 0x11B;
                if ((var_v0_2) < 0x2D7U)
                {
                    var_s0 = 1;
                }
                break;
            case 0xDC:
                if (((y + (s16) var_s3) >= -0x31) && (((x + 0x11B) & 0xFFFF) < 0x30FU))
                {
                    temp_v1_2 = &level.objects[pierreAcorde_obj_id];
                    if (temp_v1_2->hit_points == 0)
                    {
                        temp_v1_2->hit_points = 0x0A;
                        set_main_and_sub_etat(&level.objects[pierreAcorde_obj_id], 2U, 4U);
                    }
                }
                break;
            case 0xDB:
                if (level.objects[pierreAcorde_obj_id].hit_points != 0)
                {
                    var_s0 = 1;
                }
                break;
            case 0x9D:
                if (((x + 0x11B) & 0xFFFF) < 0x30FU)
                {
                    var_s0 = 1;
                }
                break;
            case 0x7a:
                if ((((x + 0x11B) & 0xFFFF) < 0x2D7U) && (((y + 0x63) & 0xFFFF) < 0x15DU))
                {
                    var_s0 = 1;
                }
                break;
            case 0xF4:
            case 0xC0:
                var_s6 = 0x80;
                break;
            default: /* maybe? */
                if ((((u16) obj->y_pos - 0x32) >= 0x141U) || (var_s0 = 1, (IsBossThere == 0)))
                {
                    var_s0 = 2;
                    if (ray.field20_0x36 == obj->id)
                    {
                        ray.field20_0x36 = -1;
                        obj->ray_dist = 0x03E8;
                        set_main_and_sub_etat(&ray, 2U, 2U);
                    }
                }
            }
        }
    }
    var_v1 = var_s0;
    if (var_s0 == 0)
    {
        var_s0 = 1;
        if (param_4 & 0xFF)
        {
            var_s4 += 0x3C;
            var_s3 += 0x3C;
        }
        if (
            (x < (-0x11C - (s16) var_s4)) || (((s16) var_s4 + 0x1BC) < x) ||
            (y < (-0x90 - (s16) var_s3)) || (((s16) var_s3 + 0x130) < y) ||
            (temp_v1_3 = obj->y_pos, (((temp_v1_3 + obj->offset_by) < -0x1E) != 0)) ||
            (((mp.height * 0x10) + 0x1E) < temp_v1_3) ||
            (temp_v1_4 = obj->x_pos, ((temp_v1_4 + (var_s6 * 2)) < 0)) ||
            (var_v1 = 1, (((mp.width * 0x10) < temp_v1_4) != 0))
        )
        {
            var_s0 = 0;
            var_v1 = 0;
        }
    }
    
    if (var_v1 == 1)
    {
        if (((u8) flags[ot].flags0 >> 7) != 0)
        {
            IsBossThere = 1;
            if (
                (first_boss_meet == 0 && obj->hit_points != 0 && scrollLocked != 0) ||
                (first_boss_meet != 0 && obj->hit_points == 0)
            )
            {
                Change_Wait_Anim();
            }
        }
    }
    var_v0 = var_s0 ^ 1;
    return var_v0 == 0;
}