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