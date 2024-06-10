#ifndef MAPDATA_H
#define MAPDATA_H

#include "common.h"
#include "common/obj.h"

typedef struct MapData {
    s16 width;
    s16 height;
    s32 length;
    u16 *map;
} MapData;

/* .data */
extern BlockFlags block_flags[32];

/**/
extern MapData mp;

#endif