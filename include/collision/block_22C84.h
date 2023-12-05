#ifndef BLOCK_22C84_H
#define BLOCK_22C84_H

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

/* .data */
extern s16 RandArray[256];

/**/
extern MapData mp;
extern u8 ray_last_ground_btyp;

s32 OBJ_IN_ZONE(Obj *obj); /* ret: s32 or s16 (based on what, handle_GO_TEST?) */
s32 myRand(s32 param_1);  /* ret: s32 or s16 (based on what?) */
s16 GET_SPRITE_POS(Obj *obj, s32 index, s16 *x ,s16 *y, u16 *w, u16 *h);

#endif