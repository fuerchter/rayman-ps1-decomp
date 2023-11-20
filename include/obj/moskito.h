#ifndef MOSKITO_H
#define MOSKITO_H

#include "common.h"
#include "num_level_36260.h"
#include "obj/poing.h"
#include "demo_9FD4.h"
#include "collision/collision.h"
#include "moteur_init_end.h"
#include "world_map_677C0.h"
#include "ray/ray_32398.h"
#include "demo_9FD4.h"
#include "obj/poing.h"
#include "boss.h"

/* 801c8050 - 801c84d8 might be general boss data? */
/* same with 801cf0bc - 801cf0ca though */
/* .data */
extern u8 *moskitoActionSequences[10];

/* .data */
extern s16 PS1_MsAnimIndex;

/**/
extern u8 fistAvoided;
extern u8 mstMustLeaveScreenToProceed;

void getIdealStingCoords(Obj *obj, s16 *out_x, s16 *out_y);
u8 closeEnoughToSting(Obj *arg0, u16 arg1, u16 arg2);
void PS1_setBossScrollLimits_moskito(Obj *obj);
u8 moskitoCanAttak(Obj *obj);
s16 setMoskitoAtScrollBorder(Obj *obj, u8 param_2);
void prepareNewMoskitoAttack(Obj *obj);
Obj * allocateMoskitoFruit(Obj *param_1);
void moskitoDropFruitOnRay(Obj *obj);
void doMoskitoCommand(Obj *obj);
u8 tellNextMoskitoAction(Obj *obj);
void changeMoskitoPhase(Obj *obj);
void doMoskitoHit(Obj *obj);

#endif