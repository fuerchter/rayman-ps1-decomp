#ifndef OBJ_INIT_KILL_H
#define OBJ_INIT_KILL_H

#include "common.h"

/*TODO: bitfields?*/
typedef u8 ObjTypeFlags_0;
#define OBJ0_NONE 0
#define OBJ0_ALWAYS 1
#define OBJ0_BALLE 2
#define OBJ0_NO_COLLISION 4
#define OBJ0_HIT_RAY 8
#define OBJ0_KEEP_ACTIVE 16
#define OBJ0_DETECT_ZONE 32
#define OBJ0_FLAG6 64
#define OBJ0_BOSS 128

typedef u8 ObjTypeFlags_1;
#define OBJ1_NONE 0
#define OBJ1_KEEP_LINKED_OBJECTS_ACTIVE 1
#define OBJ1_BONUS 2
#define OBJ1_BIG_RAY_HIT_KNOCKBACK 4
#define OBJ1_RAY_DIST_MULTISPR_CANTHANGE 8
#define OBJ1_USE_INSTANT_SPEED_X 16
#define OBJ1_USE_INSTANT_SPEED_Y 32
#define OBJ1_SPECIAL_PLATFORM 64
#define OBJ1_READ_CMD 128

typedef u8 ObjTypeFlags_2;
#define OBJ2_NONE 0
#define OBJ2_MOVE_ON_BLOCK 1
#define OBJ2_FALL_IN_WATER 2
#define OBJ2_BLOCKS_RAY 4
#define OBJ2_JUMP_ON_RESSORT_BLOCK 8
#define OBJ2_DO_NOT_CHECK_RAY_COLLISION 16
#define OBJ2_KILL_IF_OUTSIDE_ACTIVE_ZONE 32
#define OBJ2_UTURN_ON_BLOCK 64
#define OBJ2_INCREASE_SPEED_X 128

typedef u8 ObjTypeFlags_3;
#define OBJ3_NONE 0
#define OBJ3_POING_COLLISION_SND 1
#define OBJ3_DIE_IN_WATER 2
#define OBJ3_STOP_MOVING_UP_WHEN_HIT_BLOCK 4
#define OBJ3_SWITCH_OFF 8
#define OBJ3_FLAG4 16
#define OBJ3_FLAG5 32
#define OBJ3_FLAG6 64
#define OBJ3_FLAG7 128

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
#define ACTIVE_ALIVE 0
#define ACTIVE_DEAD 1
#define ACTIVE_REINIT 2
#define ACTIVE_SPECIAL 4

/* TODO: can't get 6A180 8018E980 FIN_WORLD_CHOICE, handle_RESERVED_GO_BRANCHTRUE or skipToLabel to match with these */
/*typedef struct {
    u8 none: 1;
    u8 padding1: 1;
    u8 padding2: 1;
    u8 padding3: 1;
    u8 padding4: 1;
    u8 padding5: 1;
    u8 padding6: 1;
    u8 padding7: 1;
    u8 flag_0: 1;
    u8 cmd_test: 1;
    u8 alive: 1;
    u8 active: 1;
    u8 linked: 1;
    u8 flag_5: 1;
    u8 flip_x: 1;
    u8 read_cmds: 1;
    u8 follow_enabled: 1;
    u8 flag_9: 1;
    u8 flag_a: 1;
    u8 flag_b: 1;
} ObjFlags;*/

typedef u32 ObjFlags;
#define OBJ_NONE 0
#define OBJ_ANIM_COUNT_MASK 0xFF
#define OBJ_FLAG_0 0x100
#define OBJ_CMD_TEST 0x200
#define OBJ_ALIVE 0x400
#define OBJ_ACTIVE 0x800
#define OBJ_LINKED 0x1000
#define OBJ_FLAG_5 0x2000
#define OBJ_FLIP_X 0x4000
#define OBJ_READ_CMDS 0x8000
#define OBJ_FOLLOW_ENABLED 0x10000
#define OBJ_FLAG_9 0x20000
#define OBJ_FLAG_A 0x40000
#define OBJ_FLAG_B 0x80000

#endif