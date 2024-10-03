#include "obj/pirate_guetteur.h"

/* 5C304 80180B04 -O2 -msoft-float */
void FUN_80180b04(Obj *obj, u8 param_2)
{
    if (param_2)
        obj->type = TYPE_PIRATE_GUETTEUR;
    else
        obj->type = TYPE_PIRATE_GUETTEUR2;
    
    obj->zdc = type_zdc[obj->type];
}

/* 5C33C 80180B3C -O2 -msoft-float */
void guetteurFollowsShip(Obj *obj)
{
    if (bateau_obj_id != -1)
        snapToSprite(obj, &level.objects[bateau_obj_id], 1, -51, -63);
    else
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", DO_ONE_PAR_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", hasGuetteurABomb);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", allocatePirateGuetteurBomb);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", DO_PAR_TIR);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", DO_PAR_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", PAR_REACT_TO_RAY_IN_ZONE);
