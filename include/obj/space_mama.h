#ifndef SPACE_MAMA_H
#define SPACE_MAMA_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "common/ray.h"
#include "boss.h"
#include "timers.h"
#include "cam_scroll_29B5C.h"
#include "command_56AF0.h"
#include "collision/collision.h"

void findMereDenisWeapon(void);
void PS1_setBossScrollLimits_spacemama(Obj *obj);
s32 mereDenisCanAttak(Obj *obj);
s32 setMereDenisAtScrollBorder(Obj *obj, u8 flip_x);
void setCirclePointToReach(void);
void allocateMereDenisBombChips(Obj *param_1);
void mereDenisExplodeBombs(void);
void mereDenisDropBomb(Obj *smama_obj);
void snapWeaponAnimState(Obj *obj, u8 sub_etat);
void swapMereDenisCollZones(Obj *obj, u8 smama2);
u8 prepareNewMereDenisAttack(Obj *param_1);
void snapLaserToWeapon(Obj *param_1, u8 param_2);
void allocateSpaceMamaLaser(Obj *param_1, ObjType param_2);
void doMereDenisCommand(Obj *obj);
void changeMereDenisPhase(void);
void fitSaveCurrentAction(void);
void doMereDenisHit(Obj *obj, s16 sprite);
void mereDenisBigLaserCommand(Obj *obj, u8 param_2);
void mereDenisBombCommand(Obj *obj);

#endif