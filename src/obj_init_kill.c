#include "obj_init_kill.h"

void FUN_80180b04(s32 param_1, u8 param_2);
s32 vblToEOA(Obj *param_1, u32 factor);

/* 2A07C 8014E87C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_init_kill", Prio);
#else
s32 Prio(Obj *obj)
{
    s32 res;
    __asm__("nop");

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
#endif

/* 2A12C 8014E92C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj_init_kill", first_obj_init);
#else
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

    __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", obj_init);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", instantSpeed);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_X_SPEED);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", REINIT_OBJECT);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", make_active);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", in_action_zone);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", kill_obj);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);
