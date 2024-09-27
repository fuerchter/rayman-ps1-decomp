#ifndef RAYEVTS_H
#define RAYEVTS_H

#include "common.h"

typedef struct RaymanEvents
{
    u8 poing : 1;
    u8 hang : 1;
    u8 helico : 1;
    u8 super_helico : 1;
    u8 handstand_dash : 1;
    u8 handstand : 1;
    u8 grain : 1;
    u8 grap : 1;

    u8 run : 1;
    u8 demi : 1;
    u8 luciole : 1;
    u8 force_run : 2;
    u8 reverse : 2;
    u8 unused_death : 1;
} RaymanEvents;

/**/
extern RaymanEvents RayEvts;

#endif