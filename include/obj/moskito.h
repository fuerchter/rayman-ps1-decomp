#ifndef MOSKITO_H
#define MOSKITO_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "num_level_36260.h"
#include "boss.h"
#include "collision/collision.h"

/* 801c8050 - 801c84d8 might be general boss data? */
/* same with 801cf0bc - 801cf0ca though */
/* .data */
extern u8 dyingSequence[8];
extern u8 hitSequence[8];
extern u8 arrivalSequence[4];
extern u8 firstEncounterSequence[40];
extern u8 secondEncounterSequence1[16];
extern u8 secondEncounterSequenceSuite[12];
extern u8 secondEncounterSequence2[24];
extern u8 secondEncounterSequence3[20];
extern u8 secondEncounterSequence4[24];
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
void prepareNewMoskitoAttack(Obj *mst_obj);
Obj *allocateMoskitoFruit(Obj *mst2_obj);
void moskitoDropFruitOnRay(Obj *obj);
void doMoskitoCommand(Obj *obj);
u8 tellNextMoskitoAction(Obj *obj);
void changeMoskitoPhase(Obj *obj);
void doMoskitoHit(Obj *obj);

#endif