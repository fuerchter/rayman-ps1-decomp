#ifndef COLLISION_BLOCK_H
#define COLLISION_BLOCK_H

#include "common.h"

/*TODO: bitfields?*/
typedef u8 BlockFlags;
#define BLOCK_FULLY_SOLID 0
#define BLOCK_SOLID 1
#define BLOCK_HURT 2
#define BLOCK_SLIPPERY 3
#define BLOCK_FLAG_4 4
#define BLOCK_CH_DIR 5
#define BLOCK_SLOPE 6
#define BLOCK_FLAG_7 7

#define FLG_BLOCK_NONE 0

typedef u8 BlockType;
#define BTYP_NONE 0
#define BTYP_CHDIR 1 /*reactionary*/
#define BTYP_SOLID_RIGHT_45 2
#define BTYP_SOLID_LEFT_45 3
#define BTYP_SOLID_RIGHT1_30 4
#define BTYP_SOLID_RIGHT2_30 5
#define BTYP_SOLID_LEFT1_30 6
#define BTYP_SOLID_LEFT2_30 7
#define BTYP_HURT 8
#define BTYP_RESSORT 9 /*bounce*/
#define BTYP_WATER 10
#define BTYP_LIANE 12 /*climb*/
#define BTYP_SOLID_PASSTHROUGH 14
#define BTYP_SOLID 15
#define BTYP_SLIPPERY_RIGHT_45 18
#define BTYP_SLIPPERY_LEFT_45 19
#define BTYP_SLIPPERY_RIGHT1_30 20
#define BTYP_SLIPPERY_RIGHT2_30 21
#define BTYP_SLIPPERY_LEFT1_30 22
#define BTYP_SLIPPERY_LEFT2_30 23
#define BTYP_SPIKES 24
#define BTYP_CLIFF 25
#define BTYP_SLIPPERY 30

typedef struct MapData {
    s16 width;
    s16 height;
    s32 length;
    s16 * map;
} MapData;

extern MapData mp;
extern BlockFlags block_flags[32];

#endif