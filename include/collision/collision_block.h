#ifndef COLLISION_BLOCK_H
#define COLLISION_BLOCK_H

#include "common.h"
#include "obj_update.h"

typedef struct MapData {
    s16 width;
    s16 height;
    s32 length;
    s16 * map;
} MapData;

/* .data */
extern BlockFlags block_flags[32];

/**/
extern MapData mp;
extern u8 ray_last_ground_btyp;

s32 OBJ_IN_ZONE(Obj *obj); /* ret: s32 or s16 */
s32 myRand(s32 param_1);  /* ret: s32 or s16 */

#endif