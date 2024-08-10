#ifndef OBJ_INIT_KILL_H
#define OBJ_INIT_KILL_H

#include "common.h"
#include "common/obj.h"
#include "obj/bateau_command.h"
#include "obj/space_mama.h"
#include "obj/black_ray_command.h"
#include "obj/fee_4DFD0.h"
#include "obj/mst_scroll.h"
#include "obj/pirate_guetteur.h"

/*TODO: bitfields?*/
typedef u8 ObjTypeFlags_0;
#define OBJ0_ALWAYS 0
#define OBJ0_BALLE 1
#define OBJ0_NO_COLLISION 2
#define OBJ0_HIT_RAY 3
#define OBJ0_KEEP_ACTIVE 4
#define OBJ0_DETECT_ZONE 5
#define OBJ0_FLAG6 6
#define OBJ0_BOSS 7

#define FLG_OBJ0_NONE 0

typedef u8 ObjTypeFlags_1;
#define OBJ1_KEEP_LINKED_OBJECTS_ACTIVE 0
#define OBJ1_BONUS 1
#define OBJ1_BIG_RAY_HIT_KNOCKBACK 2
#define OBJ1_RAY_DIST_MULTISPR_CANTCHANGE 3
#define OBJ1_USE_INSTANT_SPEED_X 4
#define OBJ1_USE_INSTANT_SPEED_Y 5
#define OBJ1_SPECIAL_PLATFORM 6
#define OBJ1_READ_CMD 7

#define FLG_OBJ1_NONE 0

typedef u8 ObjTypeFlags_2;
#define OBJ2_MOVE_ON_BLOCK 0
#define OBJ2_FALL_IN_WATER 1
#define OBJ2_BLOCKS_RAY 2
#define OBJ2_JUMP_ON_RESSORT_BLOCK 3
#define OBJ2_DO_NOT_CHECK_RAY_COLLISION 4
#define OBJ2_KILL_IF_OUTSIDE_ACTIVE_ZONE 5
#define OBJ2_UTURN_ON_BLOCK 6
#define OBJ2_INCREASE_SPEED_X 7

#define FLG_OBJ2_NONE 0

typedef u8 ObjTypeFlags_3;
#define OBJ3_POING_COLLISION_SND 0
#define OBJ3_DIE_IN_WATER 1
#define OBJ3_STOP_MOVING_UP_WHEN_HIT_BLOCK 2
#define OBJ3_SWITCH_OFF 3
#define OBJ3_FLAG4 4
#define OBJ3_FLAG5 5
#define OBJ3_FLAG6 6
#define OBJ3_FLAG7 7

#define FLG_OBJ3_NONE 0

typedef struct ObjTypeFlags
{
    ObjTypeFlags_0 flags0;
    ObjTypeFlags_1 flags1;
    ObjTypeFlags_2 flags2;
    ObjTypeFlags_3 flags3;
} ObjTypeFlags;

typedef struct ActiveObjects
{
    s16 objects[100];
    s16 num_active_objects;
} ActiveObjects;

/* .data */
extern ObjTypeFlags flags[256];
extern s16 zonediffx[256];
extern s16 zonediffy[256];

/**/
extern ActiveObjects actobj;
extern s16 rayman_obj_id;
extern u8 IsBossThere;

s32 Prio(Obj *obj);
void first_obj_init(Obj *obj);
void obj_init(Obj *obj);
void INIT_OBJECTS(u8 newLevel);
s32 instantSpeed(s16 spd_in); /* return? s16? */
void SET_X_SPEED(Obj *obj);
void REINIT_OBJECT(Obj *obj);
void make_active(Obj *obj, u8 do_nova);
s16 in_action_zone(s16 x, s16 y, Obj *obj, u8 param_4);
void kill_obj(Obj *obj);
void SET_ACTIVE_FLAG(s16 x, s16 y, Obj *obj);

#endif