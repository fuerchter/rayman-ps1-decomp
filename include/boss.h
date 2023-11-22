#ifndef BOSS_H
#define BOSS_H

#include "common.h"
#include "collision/collision_block.h"
#include "timers.h"
#include "moteur_init_end.h"

extern s16 bossScrollStartX;
extern s16 bossScrollStartY;
extern s16 bossScrollEndX;
extern s16 bossScrollEndY;
extern s16 floorLine;
extern s32 bossSpeedFactor;
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

extern u8 Phase;
extern u8 WaitForFinAtan;
extern u8 FinAnim;
extern u8 WaitForAnim;

void setBossReachingSpeeds(Obj *obj, u8 param_2, u8 param_3, u8 param_4);
s16 testActionEnd(Obj *obj);
void FUN_8018b78c(s16 *param_1, s16 *param_2, s16 *param_3, s16 *param_4, u8 param_5);
/*s16 firstFloorBelow(Obj *obj);*/

#endif