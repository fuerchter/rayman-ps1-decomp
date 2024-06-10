#ifndef OBJ_UPDATE_H
#define OBJ_UPDATE_H

#include "common.h"
#include "common/obj.h"
#include "collision/bit_util.h"
#include "timers.h"
#include "obj_init_kill.h"
#include "collision/block_22C84.h"
/* TODO: CIRCULAR, YAY!!! */
/*#include "sound.h"*/
/*#include "moteur_update.h"*/
/*#include "collision/block_6E5E0.h"*/

typedef struct ObjHandlers
{
    void (* do_obj)(Obj *);
} ObjHandlers;

/**/
extern s16 id_Cling_1up;
extern s16 id_Cling_Pow;
extern u8 ray_in_fee_zone;

s32 DO_PESANTEUR(Obj *obj);
void FUN_80150c5c(Obj *obj, u8 param_2); /* obj is always ray, param_2 is always 1 */
void DO_ANIM(Obj *obj);
s16 prof_in_bloc(Obj *obj);
void do_boing(Obj *obj, u8 main_etat, u8 sub_etat);
u8 underSlope(Obj *obj);
void DO_STONEBOMB_REBOND(Obj *obj);
void DO_THROWN_BOMB_REBOND(Obj *obj, s16 pesanteur, s16 param_3);
void DO_FRUIT_REBOND(Obj *obj, s16 pesanteur, s16 param_3);
void Drop_Atter(Obj *obj);
void BadGuyAtter(Obj *obj);
void MiteAtter(Obj *obj);
void Clown_Music_Atter(Obj *obj);
void LidolPinkAtter(Obj *obj);
void stoneDogAtter(Obj *obj);
void stoneDogBounces(s32 param_1);
void Spider_Atter(Obj *obj);
void trompetteAtter(Obj *obj);
void NormalAtter(Obj *param_1);
void OBJ_IN_THE_AIR(Obj *obj);
void test_fall_in_water(Obj *obj);
void MOVE_OBJECT(Obj *obj);
void DO_RAY_IN_ZONE(Obj *obj);
void DO_ONE_OBJECT(Obj *obj);
void fptr_init(void);
void build_active_table(void);
void Add_One_RAY_lives(void);
void DO_CLING_ANIMS(void);
void DO_OBJECTS_ANIMS(void);
void DO_OBJECTS(void);
void MOVE_OBJECTS(void);
void RECALE_ALL_OBJECTS(void);

#endif