#ifndef PIRATE_GUETTEUR_H
#define PIRATE_GUETTEUR_H

#include "common.h"
#include "collision/collision.h"
#include "obj/explosion.h"

void FUN_80180b04(Obj *obj, u8 param_2);
void guetteurFollowsShip(Obj *obj);
void DO_ONE_PAR_COMMAND(Obj *obj);
s32 hasGuetteurABomb(Obj *obj, s32 param_2);
void allocatePirateGuetteurBomb(Obj *obj, s32 param_2, u8 param_3, u8 param_4);
void DO_PAR_TIR(Obj *obj);
void DO_PAR_POING_COLLISION(Obj *obj, s16 param_2);
void PAR_REACT_TO_RAY_IN_ZONE(Obj *obj);
void DO_PAR_BOMB_COMMAND(Obj *obj);

#endif