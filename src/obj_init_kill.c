#include "obj_init_kill.h"

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

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", first_obj_init);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", obj_init);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", INIT_OBJECTS);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", instantSpeed);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_X_SPEED);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", REINIT_OBJECT);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", make_active);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", in_action_zone);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", kill_obj);

INCLUDE_ASM("asm/nonmatchings/obj_init_kill", SET_ACTIVE_FLAG);
