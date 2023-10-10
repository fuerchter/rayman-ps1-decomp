#ifndef OBJ_INIT_KILL_H
#define OBJ_INIT_KILL_H

#include "common.h"

/*TODO: bitfields?*/
typedef enum ObjTypeFlags_0
{
    OBJ0_NONE=0,
    OBJ0_ALWAYS=1,
    OBJ0_BALLE=2,
    OBJ0_NO_COLLISION=4,
    OBJ0_HIT_RAY=8,
    OBJ0_KEEP_ACTIVE=16,
    OBJ0_DETECT_ZONE=32,
    OBJ0_FLAG6=64,
    OBJ0_BOSS=128
} ObjTypeFlags_0;

typedef enum ObjTypeFlags_1
{
    OBJ1_NONE=0,
    OBJ1_KEEP_LINKED_OBJECTS_ACTIVE=1,
    OBJ1_BONUS=2,
    OBJ1_BIG_RAY_HIT_KNOCKBACK=4,
    OBJ1_RAY_DIST_MULTISPR_CANTHANGE=8,
    OBJ1_USE_INSTANT_SPEED_X=16,
    OBJ1_USE_INSTANT_SPEED_Y=32,
    OBJ1_SPECIAL_PLATFORM=64,
    OBJ1_READ_CMD=128
} ObjTypeFlags_1;

typedef enum ObjTypeFlags_2
{
    OBJ2_NONE=0,
    OBJ2_MOVE_ON_BLOCK=1,
    OBJ2_FALL_IN_WATER=2,
    OBJ2_BLOCKS_RAY=4,
    OBJ2_JUMP_ON_RESSORT_BLOCK=8,
    OBJ2_DO_NOT_CHECK_RAY_COLLISION=16,
    OBJ2_KILL_IF_OUTSIDE_ACTIVE_ZONE=32,
    OBJ2_UTURN_ON_BLOCK=64,
    OBJ2_INCREASE_SPEED_X=128
} ObjTypeFlags_2;

typedef enum ObjTypeFlags_3
{
    OBJ3_NONE=0,
    OBJ3_POING_COLLISION_SND=1,
    OBJ3_DIE_IN_WATER=2,
    OBJ3_STOP_MOVING_UP_WHEN_HIT_BLOCK=4,
    OBJ3_SWITCH_OFF=8,
    OBJ3_FLAG4=16,
    OBJ3_FLAG5=32,
    OBJ3_FLAG6=64,
    OBJ3_FLAG7=128
} ObjTypeFlags_3;

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

typedef enum ObjActiveFlag
{
    ACTIVE_ALIVE=0,
    ACTIVE_DEAD=1,
    ACTIVE_REINIT=2,
    ACTIVE_SPECIAL=4
} ObjActiveFlag;

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

typedef enum ObjFlags
{
    OBJ_NONE=0,
    OBJ_ANIM_COUNT_MASK=0xFF,
    OBJ_FLAG_0=0x100,
    OBJ_CMD_TEST=0x200,
    OBJ_ALIVE=0x400,
    OBJ_ACTIVE=0x800,
    OBJ_LINKED=0x1000,
    OBJ_FLAG_5=0x2000,
    OBJ_FLIP_X=0x4000,
    OBJ_READ_CMDS=0x8000,
    OBJ_FOLLOW_ENABLED=0x10000,
    OBJ_FLAG_9=0x20000,
    OBJ_FLAG_A=0x40000,
    OBJ_FLAG_B=0x80000
} ObjFlags;

#endif