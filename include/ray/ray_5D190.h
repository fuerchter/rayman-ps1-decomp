#ifndef RAY_5D190_H
#define RAY_5D190_H

#include "common.h"

/* TODO: bitfields? */
typedef enum {
    RAYEVTS0_NONE=0,
    RAYEVTS0_POING=1,
    RAYEVTS0_HANG=2,
    RAYEVTS0_HELICO=4,
    RAYEVTS0_SUPER_HELICO=8,
    RAYEVTS0_HANDSTAND_DASH=16,
    RAYEVTS0_HANDSTAND=32,
    RAYEVTS0_GRAIN=64,
    RAYEVTS0_GRAP=128
} RayEvts_0;

typedef enum {
    RAYEVTS1_NONE=0,
    RAYEVTS1_RUN=1,
    RAYEVTS1_DEMI=2,
    RAYEVTS1_LUCIOLE=4,
    RAYEVTS1_FORCE_RUN_TOGGLE=8,
    RAYEVTS1_FORCE_RUN=16,
    RAYEVTS1_REVERSE=32,
    RAYEVTS1_FLAG6=64,
    RAYEVTS1_UNUSED_DEATH=128
} RayEvts_1;

typedef struct {
    RayEvts_0 flags0;
    RayEvts_1 flags1;
} RaymanEvents;

typedef enum {
    MODE_NONE=0,
    MODE_RAYMAN=1,
    MODE_RAY_ON_MS=2,
    MODE_MORT_DE_RAYMAN=3,
    MODE_MORT_DE_RAYMAN_ON_MS=4
} RayMode;

extern s16 decalage_en_cours;

#endif