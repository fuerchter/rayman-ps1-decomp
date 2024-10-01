#include "obj_init_kill.h"

extern u8 first_boss_meet; /* TODO: decide what to do with unknown/2539C */

/* 2A07C 8014E87C -O2 -msoft-float */
s32 Prio(Obj *obj)
{
    s32 res;

    switch(obj->type)
    {
    case TYPE_EAU:
    case TYPE_MEDAILLON_TOON:
        res = 1;
        break;
    case TYPE_AUDIOSTART:
    case TYPE_SPACE_MAMA:
    case TYPE_BLACK_RAY:
    case TYPE_SPACE_MAMA2:
    case TYPE_ANNULE_SORT_DARK:
    case TYPE_POING_FEE:
    case TYPE_DUNE:
        res = 0;
        break;
    case TYPE_MST_SCROLL:
        res = (obj->hit_points == 0) * 2;
        break;
    case TYPE_BOUM:
    case TYPE_SPLASH:
    case TYPE_PHOTOGRAPHE:
    case TYPE_OUYE:
    case TYPE_MOVE_OUYE:
    case TYPE_FLAMME2:
    case TYPE_STALAG:
    case TYPE_CAGE:
    case TYPE_CAGE2:
    case TYPE_STONECHIP:
    case TYPE_EXPLOSION:
    case TYPE_NOTE0:
    case TYPE_NOTE1:
    case TYPE_NOTE2:
    case TYPE_BONNE_NOTE:
    case TYPE_BNOTE:
    case TYPE_PI_BOUM:
    case TYPE_ECLAIR:
    case TYPE_BLACKTOON1:
    case TYPE_ETINC:
    case TYPE_NOVA2:
    case TYPE_FLASH:
    case TYPE_CLE_SOL:
    case TYPE_SCORPION:
    case TYPE_WIZ:
    case TYPE_CYMBAL1:
    case TYPE_RAYON:
    case TYPE_PIERREACORDE:
    case TYPE_CFUMEE:
    case TYPE_STOSKO_PINCE:
    case TYPE_LAVE:
    case TYPE_SKO_PINCE:
        res = 2;
        break;
    case TYPE_ONOFF_PLAT:
    case TYPE_CLASH:
    case TYPE_BB1:
    case TYPE_DARD:
    case TYPE_PIRATE_NGAWE:
    case TYPE_RING:
    case TYPE_SAXO:
    case TYPE_PIRATE_GUETTEUR:
    case TYPE_PIRATE_BOMB:
    case TYPE_MARACAS:
    case TYPE_BBL:
    case TYPE_TNT_BOMB:
    case TYPE_SUPERHELICO:
    case TYPE_ROULETTE:
    case TYPE_ROULETTE2:
    case TYPE_ROULETTE3:
    case TYPE_SAXO2:
    case TYPE_SAXO3:
    case TYPE_MAMA_PIRATE:
    case TYPE_COUTEAU:
    case TYPE_BB12:
    case TYPE_BB13:
    case TYPE_BB14:
    case TYPE_SMA_WEAPON:
    case TYPE_BOUT_TOTEM:
    case TYPE_PIRATE_GUETTEUR2:
    case TYPE_RIDEAU:
        res = 3;
        break;
    case TYPE_PLANCHES:
        
        if (bateau_obj_id != -1)
            res = 4;
        else
            res = 7;
        break;
    case TYPE_MORNINGSTAR:
    case TYPE_GENEBADGUY:
    case TYPE_PI:
    case TYPE_PI_MUS:
    case TYPE_WASHING_MACHINE:
    case TYPE_VAGUE_DEVANT:
        res = 5;
        break;
    case TYPE_POWERUP:
    case TYPE_MUS_WAIT:
    case TYPE_JAUGEUP:
    case TYPE_POING_POWERUP:
    case TYPE_REDUCTEUR:
    case TYPE_ONEUP:
    case TYPE_GRAP_BONUS:
    case TYPE_BATEAU:
        res = 6;
        break;
    case TYPE_NEUTRAL:
    case TYPE_SIGNPOST:
    case TYPE_TAMBOUR2:
    case TYPE_VAGUE_DERRIERE:
        res = 7;
        break;
    default:
        res = 4;
        break;
    }

    return res;
}

/* 2A12C 8014E92C -O2 -msoft-float */
void first_obj_init(Obj *obj)
{
    ObjType type = obj->type;
    
    if (
        flags[type].flags0 & FLG(OBJ0_ALWAYS) ||
        (
            (type == TYPE_BADGUY1 || type == TYPE_BADGUY2) &&
            obj->x_pos < 0
        )
    )
    {
        obj->x_pos = -32000;
        obj->y_pos = -32000;
    }
    obj->scale = 0;
    obj->active_flag = ACTIVE_DEAD;
    obj->init_x_pos = obj->x_pos;
    obj->init_y_pos = obj->y_pos;
    obj->init_main_etat = obj->main_etat;
    obj->init_sub_etat = obj->sub_etat;
    obj->init_hit_points = obj->hit_points;

    switch (obj->type)
    {
    case TYPE_SPACE_MAMA:
    case TYPE_SPACE_MAMA2:
        findMereDenisWeapon();
        obj->field24_0x3e = 0;
        break;
    case TYPE_FEE:
        obj->detect_zone = 200;
        obj->field24_0x3e = 0;
        break;
    case TYPE_TROMPETTE:
    case TYPE_MITE2:
        obj->detect_zone = 160;
        obj->field24_0x3e = 0;
        break;
    case TYPE_MOSKITO:
    case TYPE_MOSKITO2:        
    case TYPE_WIZARD1:
    case TYPE_SPIDER:
        obj->detect_zone = 60;
        obj->field24_0x3e = 0;
        break;
    case TYPE_CHASSEUR1:
    case TYPE_CHASSEUR2:
    case TYPE_GENEBADGUY:
    case TYPE_SAXO3:
        obj->detect_zone = 180;
        obj->field24_0x3e = 0;
        break;
    case TYPE_STONEWOMAN:
    case TYPE_STONEWOMAN2:
    case TYPE_BIG_CLOWN:
    case TYPE_MITE:
        obj->detect_zone = 220;
        obj->field24_0x3e = 0;
        break;
    case TYPE_STONEMAN1:
    case TYPE_STONEDOG:
    case TYPE_STONEMAN2:
    case TYPE_MUS_WAIT:
    case TYPE_PIRATE_NGAWE:
    case TYPE_BATTEUR_FOU:
    case TYPE_STONEDOG2:
        obj->detect_zone = 100;
        obj->field24_0x3e = 0;
        break;
    case TYPE_PIRATE_POELLE:
    case TYPE_PIRATE_P_45:
        obj->detect_zone = 150;
        obj->field24_0x3e = 0;
        break;
    case TYPE_PIRATE_POELLE_D:
    case TYPE_PIRATE_P_D_45:
        obj->detect_zone = 50;
        obj->field24_0x3e = 0;
        break;
    case TYPE_CLOWN_TNT:
        obj->detect_zone = 200;
        obj->field24_0x3e = 0;
        break;
    case TYPE_STALAG:
        obj->detect_zone = 250;
        obj->field24_0x3e = 0;
        break;
    case TYPE_CYMBALE:
    case TYPE_CYMBAL1:
    case TYPE_CYMBAL2:
        obj->detect_zone = 0;
        obj->field24_0x3e = 0;
        break;
    case TYPE_BAG1:
        obj->field23_0x3c = 0;
        obj->field24_0x3e = 0;
        break;
    case TYPE_SCORPION:
        obj->detect_zone = 160;
        obj->field24_0x3e = 0;
        break;
    case TYPE_WAT_CLOWN:
    case TYPE_MAMA_PIRATE:
        obj->detect_zone = 150;
        obj->field24_0x3e = 0;
        break;
    case TYPE_DARK_PHASE2:
    case TYPE_DARK:
        obj->detect_zone = 150;
        obj->field24_0x3e = 0;
        break;
    default:
        obj->detect_zone = 40;
        obj->field24_0x3e = 0;
        break;
    }
}

/* 2A2A0 8014EAA0 -O2 -msoft-float */
void obj_init(Obj *obj)
{
    s16 unk_1;
    s16 unk_2;

    obj->nb_cmd = 0;
    obj->flags &= ~FLG(OBJ_ACTIVE);
    obj->display_prio = Prio(obj);
    obj->zdc = type_zdc[obj->type];
    if (obj->type != TYPE_INDICATOR)
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
    obj->flags &= ~FLG(OBJ_FLIP_X);
    obj->change_anim_mode = ANIMMODE_NONE;
    obj->gravity_value_1 = 0;
    obj->gravity_value_2 = 0;
    obj->detect_zone_flag = 0;
    obj->iframes_timer = -1;
    obj->field20_0x36 = -1;
    obj->cmd_offset = -1;
    unk_1 = obj->cmds != null;
    obj->flags = (obj->flags & ~FLG(OBJ_READ_CMDS)) | (unk_1 << OBJ_READ_CMDS);
    memset(obj->btypes, 0, 5);
    GET_OBJ_CMD(obj);
    obj->test_block_index = 0;
    obj->cmd_context_index = 0xFF;
    obj->active_flag = ACTIVE_DEAD;
    obj->timer = 0;
    obj->field56_0x69 = 0;
    obj->hit_points = obj->init_hit_points;
    obj->flags &= ~FLG(OBJ_FLAG_9);
    obj->flags &= ~FLG(OBJ_FLAG_A);
    obj->flags &= ~FLG(OBJ_FLAG_B);
    
    switch (obj->type)
    {
    case TYPE_SAXO:
    case TYPE_SAXO2:
    case TYPE_SAXO3:
        INIT_SAXO(obj);
        break;
    case TYPE_PRI:
        if (finBosslevel[1] & FLG(2))
        {
            prise_branchee = true;
            set_main_and_sub_etat(obj, 0, 2);
            obj->init_sub_etat = 2;
            skipToLabel(obj, 1, true);
            break;
        }
        break;
    case TYPE_VAGUE_DEVANT:
    case TYPE_VAGUE_DERRIERE:
        obj->x_pos = obj->init_x_pos = -15;
        break;
    case TYPE_HYBRIDE_MOSAMS:
        bossXToReach = obj->x_pos;
        bossYToReach = firstFloorBelow(&ray) - obj->offset_by + 16;
        bossSpeedFactor = 0x4000;
        alternateBossSpeedFactor = 0;
        break;
    case TYPE_CRAYON_BAS:
    case TYPE_CRAYON_HAUT:
        obj->anim_frame = myRand(obj->animations[obj->anim_index].frames_count - 1);
        break;
    case TYPE_FALLING_CRAYON:
    case TYPE_PUNAISE4:
        obj->anim_frame = obj->hit_points;
        break;
    case TYPE_PUNAISE1:
    case TYPE_PUNAISE2:
    case TYPE_PUNAISE3:
    case TYPE_PUNAISE5:
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (obj->hit_points & 1) << OBJ_FLIP_X;
        break;
    case TYPE_MST_FRUIT1:
    case TYPE_MST_SHAKY_FRUIT:
        obj->gravity_value_2 = 5;
        break;
    case TYPE_MST_FRUIT2:
        obj->gravity_value_2 = 10;
        break;
    case TYPE_SPACE_MAMA:
        obj->type = TYPE_SPACE_MAMA2;
    case TYPE_SPACE_MAMA2:
        swapMereDenisCollZones(obj, true);
        PS1_setBossScrollLimits_spacemama(obj);
        bossSpeedFactor = 0x4000;
        alternateBossSpeedFactor = 0;
        laserSourceSprNumInAnim = 0xFF;
        IsBossThere = false;
        scrollLocked = false;
        obj->timer = 180;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = false;
        bossEncounter = 0;
        break;
    case TYPE_MOSKITO2:
        bossEncounter = 2;
        PS1_setBossScrollLimits_moskito(obj);
        bossSpeedFactor = 0x4000;
        alternateBossSpeedFactor = 0;
        IsBossThere = false;
        scrollLocked = false;
        obj->timer = 100;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = false;
        break;
    case TYPE_MOSKITO:
        bossEncounter = 0;
        PS1_setBossScrollLimits_moskito(obj);
        bossSpeedFactor = 0x4000;
        alternateBossSpeedFactor = 0;
        IsBossThere = false;
        scrollLocked = false;
        obj->timer = 100;
        saveBossEncounter = 0xFF;
        currentBossAction = 0;
        currentBossActionIsOver = false;
        break;
    case TYPE_BADGUY1:
        obj->offset_hy = 30;
        obj->flags &= ~FLG(OBJ_FOLLOW_ENABLED);
        break;
    case TYPE_LIDOLPINK2:
        obj->iframes_timer = 0;
        break;
    case TYPE_BLACKTOON1:
        switch (obj->follow_sprite)
        {
        case 1:
            obj->field56_0x69 = 2;
            obj->detect_zone = 0;
            break;
        case 2:
            obj->field56_0x69 = 8;
            obj->detect_zone = 60;
            break;
        case 3:
            obj->field56_0x69 = 24;
            obj->detect_zone = 170;
            break;
        case 4:
            obj->field56_0x69 = 10;
            obj->detect_zone = 100;
            break;
        case 5:
            obj->field20_0x36 = 0;
            obj->field56_0x69 = 1;
            obj->detect_zone = 0;
            break;
        case 6:
            obj->field56_0x69 = 4;
            obj->detect_zone = 60;
            break;
        case 7:
            obj->field56_0x69 = 36;
            obj->detect_zone = 120;
            break;
        }
        break;
    case TYPE_KILLING_EYES:
        obj->iframes_timer = obj->field23_0x3c = 40;
        break;
    case TYPE_PIRATE_NGAWE:
        obj->field56_0x69 = 1;
        break;
    case TYPE_PIRATE_GUETTEUR:
    case TYPE_PIRATE_GUETTEUR2:
        FUN_80180b04(obj, obj->init_sub_etat == 14);
        obj->iframes_timer = 0;
        obj->detect_zone = 80;
        break;
    case TYPE_ONOFF_PLAT:
        obj->iframes_timer = obj->field20_0x36 = 100;
        obj->flags |= FLG(OBJ_ALIVE);
        break;
    case TYPE_CRUMBLE_PLAT:
        if (num_world != 1)
        {
            unk_2 = vblToEOA(obj, 1U) - 2;
            obj->field23_0x3c = unk_2;
            obj->iframes_timer = unk_2;
        }
        else
        {
            obj->field23_0x3c = 40;
            obj->iframes_timer = 20;
        }
        obj->field24_0x3e = 20;
        obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_FOLLOW_ENABLED);
        break;
    case TYPE_INST_PLAT:
        obj->iframes_timer = obj->field20_0x36 = 15;
        obj->flags |= FLG(OBJ_ALIVE);
        break;
    case TYPE_AUTOJUMP_PLAT:
    case TYPE_MOVE_AUTOJUMP_PLAT:
    case TYPE_CAISSE_CLAIRE:
    case TYPE_GOMME:
    case TYPE_MARK_AUTOJUMP_PLAT:
        obj->iframes_timer = obj->field20_0x36 = 1;
        obj->flags |= FLG(OBJ_ALIVE);
        break;
    case TYPE_CLOWN_TNT:
    case TYPE_CLOWN_TNT2:
    case TYPE_CLOWN_TNT3:
        obj->field56_0x69 = 0;
        obj->field24_0x3e = 0;
        break;
    case TYPE_CYMBAL1:
    case TYPE_CYMBAL2:
    case TYPE_HERSE_BAS:
    case TYPE_HERSE_HAUT:
        obj->field24_0x3e = 0;
        break;
    case TYPE_SCORPION:
        obj->detect_zone = 160;
        sko_phase = 0;
        break;
    case TYPE_PHOTOGRAPHE:
        obj->flags |= FLG(OBJ_ALIVE);
        break;
    case TYPE_MORNINGSTAR:
        obj->flags |= FLG(OBJ_ALIVE);
        break;
    case TYPE_PIRATE_POELLE_D:
    case TYPE_PIRATE_P_D_45:
        obj->flags |= FLG(OBJ_FLIP_X);
        break;
    case TYPE_DARK:
        obj->field23_0x3c = 0;
        break;
    case TYPE_MITE2:
        obj->eta[1][0].flags &= 0xef;
        obj->eta[1][2].flags &= 0xef;
        obj->field20_0x36 = 0;
        break;
    case TYPE_RAY_ETOILES:
        if (obj->main_etat == 0 && obj->sub_etat == 57)
            star_ray_der = obj;
        else
            star_ray_dev = obj;
        obj->display_prio = 3;
    case TYPE_RAYON:
    case TYPE_MEDAILLON_TOON:
        obj->flags &= ~FLG(OBJ_ALIVE);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);

/* 2B698 8014FE98 -O2 -msoft-float */
s32 instantSpeed(s16 spd_in)
{
    s32 to_add;
    s32 spd_shr = (s16) ashr16(spd_in, 4);
    s32 spd_abs_max = __builtin_abs(spd_in) & 15;
    
    if (spd_abs_max != 0)
    {
        to_add =
            ashr32(spd_abs_max * map_time, 4) -
            ashr32(spd_abs_max * map_time - spd_abs_max, 4);
        if (spd_in >= 0)
        {
            if (spd_in > 0)
                spd_shr += to_add;
        }
        else
            spd_shr -= to_add;
    }

    return (s16) spd_shr;
}

/* 2B764 8014FF64 -O2 -msoft-float */
void SET_X_SPEED(Obj *obj)
{
    ObjState *cur_eta;
    s16 spd_x;
    u8 unk_1 = (obj->animations[obj->anim_index].layers_count >> 0xe) + 1;

    if (horloge[unk_1] == 0)
    {
        cur_eta = &obj->eta[obj->main_etat][obj->sub_etat];
        switch (obj->flags >> OBJ_FLIP_X & 1)
        {
        case false:
            spd_x = cur_eta->speed_x_left * unk_1;
            break;
        case true:
            spd_x = cur_eta->speed_x_right * unk_1;
            break;
        }
    }
    else
        spd_x = 0;

    if (obj->type == TYPE_RAYMAN && RayEvts.demi)
        spd_x = ashr16(spd_x, 1);

    obj->speed_x = spd_x;
}

/* 2B878 80150078 -O2 -msoft-float */
void REINIT_OBJECT(Obj *obj)
{
    obj_init(obj);
    obj->active_flag = ACTIVE_REINIT;
    obj->flags |= FLG(OBJ_ALIVE);
    calc_obj_pos(obj);
    obj->active_timer = 120;
    obj->flags &= ~FLG(OBJ_ACTIVE);
}

/* 2B8D0 801500D0 -O2 -msoft-float */
void make_active(Obj *obj, u8 do_nova)
{
    if (obj->flags & FLG(OBJ_ALIVE))
    {
        obj->flags |= FLG(OBJ_ACTIVE)|FLG(OBJ_FLAG_5);
        obj->active_flag = ACTIVE_ALIVE;
        if (do_nova)
            DO_NOVA(obj);
    }
}

/* 2B914 80150114 -O2 -msoft-float */
s16 in_action_zone(s32 in_x, s32 in_y, Obj *obj, u8 param_4)
{
    s32 unk_3;
    s32 unk_1 = 0;
    s16 zdiff_x = zonediffx[ot];
    s16 zdiff_y = zonediffy[ot];
    u8 offset_bx = obj->offset_bx;
    s32 unk_x = in_x;
    s32 unk_y = in_y;
    u8 unk_param_4 = param_4;
    
    if (flags[ot].flags0 >> OBJ0_KEEP_ACTIVE & 1)
    {
        if (flags[ot].flags0 >> OBJ0_BOSS && IsBossThere)
            unk_1 = 1;
        else
        {
            switch (ot)
            {
            case TYPE_FEE:
            case TYPE_POING:
            case TYPE_BATTEUR_FOU:
            case TYPE_BLACK_RAY:
            case TYPE_BLACK_FIST:
            case TYPE_COUTEAU:
            case TYPE_DARK_SORT:
            case TYPE_NOVA2:
                unk_1 = 1;
                break;
            case TYPE_FISH:
            case TYPE_BBL:
                if ((u16) (unk_x + 283) < 727)
                    unk_1 = 1;
                break;
            case TYPE_PIERREACORDE:
                if (((s16) unk_y + zdiff_y > -50) && (u16) (unk_x + 283) < 783)
                {
                    if (level.objects[pierreAcorde_obj_id].hit_points == 0)
                    {
                        level.objects[pierreAcorde_obj_id].hit_points = 10;
                        set_main_and_sub_etat(&level.objects[pierreAcorde_obj_id], 2, 4);
                    }
                }
            case TYPE_CORDE:
                if (level.objects[pierreAcorde_obj_id].hit_points != 0)
                    unk_1 = 1;
                break;
            case TYPE_EAU:
                if ((u16) (unk_x + 283) < 783)
                    unk_1 = 1;
                break;
            case TYPE_STONEDOG2:
                if (((u16) (unk_x + 283) < 727) && ((u16) (unk_y + 99) < 349))
                    unk_1 = 1;
                break;
            case TYPE_SMA_PETIT_LASER:
            case TYPE_SMA_GRAND_LASER:
                offset_bx = 128;
                break;
            case TYPE_PAILLETTE:
            case TYPE_DESTROYING_DOOR:
                if (((u16) (obj->y_pos - 50) > 320) || !IsBossThere)
                {
                    if (ray.field20_0x36 == obj->id)
                    {
                        ray.field20_0x36 = -1;
                        obj->ray_dist = 1000;
                        set_main_and_sub_etat(&ray, 2, 2);
                    }
                    unk_1 = 2;
                }
                else
                    unk_1 = 1;
                break;
            }
        }
    }

    unk_3 = unk_1;
    if (unk_1 == 0)
    {
        if (unk_param_4)
        {
            zdiff_x += 60;
            zdiff_y += 60;
        }

        unk_1 = 1;
        if (
            ((s16) unk_x < -284 - zdiff_x) || ((s16) unk_x > zdiff_x + 444) ||
            ((s16) unk_y < -144 - zdiff_y) || ((s16) unk_y > zdiff_y + 304) ||
            (obj->y_pos + obj->offset_by < -30) || (obj->y_pos > mp.height * 16 + 30) ||
            (obj->x_pos + offset_bx * 2 < 0) || (obj->x_pos > mp.width * 16)
        )
            unk_1 = 0;
        unk_3 = unk_1;
    }
    
    if (unk_3 == 1)
    {
        if (flags[ot].flags0 >> OBJ0_BOSS & 1)
        {
            IsBossThere = true;
            if (
                (!first_boss_meet && obj->hit_points != 0 && scrollLocked) ||
                (first_boss_meet && obj->hit_points == 0)
            )
                Change_Wait_Anim();
        }
    }
    return !(unk_1 ^ 1);
}

/* 2BE38 80150638 -O2 -msoft-float */
void kill_obj(Obj *obj)
{
    obj->x_pos = -32000;
    obj->y_pos = -32000;
    obj->active_flag = ACTIVE_DEAD;
    obj->flags &= ~FLG(OBJ_ALIVE);
}

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);
