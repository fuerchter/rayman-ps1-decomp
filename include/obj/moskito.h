#ifndef MOSKITO_H
#define MOSKITO_H

#include "common.h"
#include "obj_update.h"
#include "num_level_36260.h"
#include "obj/poing.h"
#include "demo_9FD4.h"
#include "collision/collision.h"
#include "moteur_init_end.h"
#include "world_map_677C0.h"
#include "ray/ray_32398.h"
#include "demo_9FD4.h"
#include "obj/poing.h"

/* TODO: general boss.h? see space mama */
extern s16 bossScrollStartX;
extern s16 bossScrollStartY;
extern s16 bossScrollEndX;
extern s16 bossScrollEndY;
extern s16 floorLine;
extern s32 alternateBossSpeedFactor;

extern u8 bossEncounter;
extern u8 saveBossEncounter;
extern u8 bossReachingAccuracyX;
extern u8 bossReachingAccuracyY;
extern u8 bossReachingTimer;
extern u8 bossSafeTimer;
extern s16 bossXToReach;
extern s16 bossYToReach;

extern u8 curAct;
extern u8 currentBossAction;
extern u8 saveCurrentBossAction;
extern u8 currentBossActionIsOver;

extern u8 fistAvoided;
extern u8 *moskitoActionSequences[10];
extern u8 mstMustLeaveScreenToProceed;
extern s16 PS1_MsAnimIndex;

void getIdealStingCoords(Obj *obj, s16 *out_x, s16 *out_y);
u8 closeEnoughToSting(Obj *arg0, u16 arg1, u16 arg2);
void PS1_setBossScrollLimits_moskito(Obj *obj);
u8 moskitoCanAttak(Obj *obj);
s16 setMoskitoAtScrollBorder(Obj *obj, u8 param_2);
void prepareNewMoskitoAttack(Obj *obj);
Obj * allocateMoskitoFruit(Obj *param_1);
void moskitoDropFruitOnRay(Obj *param_1);
void doMoskitoCommand(Obj *obj);
u8 tellNextMoskitoAction(void);
void changeMoskitoPhase(Obj *obj);
void doMoskitoHit(Obj *obj);

#endif