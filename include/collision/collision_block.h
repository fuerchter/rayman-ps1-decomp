#ifndef COLLISION_BLOCK_H
#define COLLISION_BLOCK_H

#include "common.h"

//TODO: bitfields?
typedef enum {
    BLOCK_NONE=0,
    BLOCK_FULLY_SOLID=1,
    BLOCK_SOLID=2,
    BLOCK_HURT=4,
    BLOCK_SLIPPERY=8,
    BLOCK_FLAG_4=16,
    BLOCK_CH_DIR=32,
    BLOCK_SLOPE=64,
    BLOCK_FLAG_7=128
} BlockFlags;

typedef enum {
    BTYP_NONE=0,
    BTYP_CHDIR=1, // reactionary,
    BTYP_SOLID_RIGHT_45=2,
    BTYP_SOLID_LEFT_45=3,
    BTYP_SOLID_RIGHT1_30=4,
    BTYP_SOLID_RIGHT2_30=5,
    BTYP_SOLID_LEFT1_30=6,
    BTYP_SOLID_LEFT2_30=7,
    BTYP_HURT=8,
    BTYP_RESSORT=9, // bounce,
    BTYP_WATER=10,
    BTYP_LIANE=12, // climb,
    BTYP_SOLID_PASSTHROUGH=14,
    BTYP_SOLID=15,
    BTYP_SLIPPERY_RIGHT_45=18,
    BTYP_SLIPPERY_LEFT_45=19,
    BTYP_SLIPPERY_RIGHT1_30=20,
    BTYP_SLIPPERY_RIGHT2_30=21,
    BTYP_SLIPPERY_LEFT1_30=22,
    BTYP_SLIPPERY_LEFT2_30=23,
    BTYP_SPIKES=24,
    BTYP_CLIFF=25,
    BTYP_SLIPPERY=30
} BlockType;

typedef struct {
    s16 width;
    s16 height;
    s32 length;
    s16 * map;
} MapData;

#endif