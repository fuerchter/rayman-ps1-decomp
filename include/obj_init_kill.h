#ifndef OBJ_INIT_KILL_H
#define OBJ_INIT_KILL_H

#include "common.h"

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
#define OBJ1_RAY_DIST_MULTISPR_CANTHANGE 3
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

typedef u8 ObjActiveFlag;
#define ACTIVE_DEAD 0
#define ACTIVE_REINIT 1
#define ACTIVE_SPECIAL 2

#define FLG_ACTIVE_ALIVE 0

/* couldn't get 6A180 8018E980 FIN_WORLD_CHOICE, handle_RESERVED_GO_BRANCHTRUE or skipToLabel to match with actual bitfields */
typedef u32 ObjFlags;
#define OBJ_FLAG_0 8
#define OBJ_CMD_TEST 9
#define OBJ_ALIVE 10
#define OBJ_ACTIVE 11
#define OBJ_LINKED 12
#define OBJ_FLAG_5 13
#define OBJ_FLIP_X 14
#define OBJ_READ_CMDS 15
#define OBJ_FOLLOW_ENABLED 16
#define OBJ_FLAG_9 17
#define OBJ_FLAG_A 18
#define OBJ_FLAG_B 19

#define FLG_OBJ_NONE 0
#define FLG_OBJ_ANIM_COUNT_MASK 0xFF

extern s16 rayman_obj_id;
extern u8 IsBossThere;

#endif