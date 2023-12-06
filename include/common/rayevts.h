#ifndef RAYEVTS_H
#define RAYEVTS_H

#include "common.h"

/* TODO: bitfields? */
typedef u8 RayEvts_0;
#define RAYEVTS0_POING 0
#define RAYEVTS0_HANG 1
#define RAYEVTS0_HELICO 2
#define RAYEVTS0_SUPER_HELICO 3
#define RAYEVTS0_HANDSTAND_DASH 4
#define RAYEVTS0_HANDSTAND 5
#define RAYEVTS0_GRAIN 6
#define RAYEVTS0_GRAP 7

#define FLG_RAYEVTS0_NONE 0

typedef u8 RayEvts_1;
#define RAYEVTS1_RUN 0
#define RAYEVTS1_DEMI 1
#define RAYEVTS1_LUCIOLE 2
#define RAYEVTS1_FORCE_RUN_TOGGLE 3
#define RAYEVTS1_FORCE_RUN 4
#define RAYEVTS1_REVERSE 5
#define RAYEVTS1_FLAG6 6
#define RAYEVTS1_UNUSED_DEATH 7

#define FLG_RAYEVTS1_NONE 0

typedef struct RaymanEvents
{
    RayEvts_0 flags0;
    RayEvts_1 flags1;
} RaymanEvents;

extern RaymanEvents RayEvts;

#endif