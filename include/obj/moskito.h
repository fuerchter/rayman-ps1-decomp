#ifndef MOSKITO_H
#define MOSKITO_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "num_level_36260.h"
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
u8 closeEnoughToSting(Obj *obj, u16 min_x, u16 min_y);
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