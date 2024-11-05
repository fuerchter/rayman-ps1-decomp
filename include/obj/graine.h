#ifndef GRAINE_H
#define GRAINE_H

#include "common.h"
#include "collision/block_22C84.h"

/* .data */
extern s32 D_801CF408;

void DO_TARZAN(Obj *tz_obj);
Obj *oldest_planted(void);
void DO_GROWING_PLATFORM(void);

#endif