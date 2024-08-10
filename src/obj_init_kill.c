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

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", obj_init);

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

    if (obj->type == TYPE_RAYMAN && RayEvts.flags1 & FLG(RAYEVTS1_DEMI))
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
            DO_NOVA();
    }
}

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", in_action_zone);

/* 2BE38 80150638 -O2 -msoft-float */
void kill_obj(Obj *obj)
{
    obj->x_pos = -32000;
    obj->y_pos = -32000;
    obj->active_flag = 1;
    obj->flags &= ~FLG(OBJ_ALIVE);
}

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);
