#ifndef RAY_5D190_H
#define RAY_5D190_H

#include "common.h"

/* TODO: bitfields? */
typedef u8 RayEvts_0;
#define RAYEVTS0_NONE 0
#define RAYEVTS0_POING 1
#define RAYEVTS0_HANG 2
#define RAYEVTS0_HELICO 4
#define RAYEVTS0_SUPER_HELICO 8
#define RAYEVTS0_HANDSTAND_DASH 16
#define RAYEVTS0_HANDSTAND 32
#define RAYEVTS0_GRAIN 64
#define RAYEVTS0_GRAP 128

typedef u8 RayEvts_1;
#define RAYEVTS1_NONE 0
#define RAYEVTS1_RUN 1
#define RAYEVTS1_DEMI 2
#define RAYEVTS1_LUCIOLE 4
#define RAYEVTS1_FORCE_RUN_TOGGLE 8
#define RAYEVTS1_FORCE_RUN 16
#define RAYEVTS1_REVERSE 32
#define RAYEVTS1_FLAG6 64
#define RAYEVTS1_UNUSED_DEATH 128

typedef struct RaymanEvents
{
    RayEvts_0 flags0;
    RayEvts_1 flags1;
} RaymanEvents;

typedef u16 RayMode;
#define MODE_NONE 0
#define MODE_RAYMAN 1
#define MODE_RAY_ON_MS 2
#define MODE_MORT_DE_RAYMAN 3
#define MODE_MORT_DE_RAYMAN_ON_MS 4

extern RaymanEvents RayEvts;
extern s16 decalage_en_cours;
extern s16 remoteRayXToReach;

#endif