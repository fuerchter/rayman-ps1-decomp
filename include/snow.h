#ifndef SNOW_H
#define SNOW_H

#include "common.h"

typedef struct FloconTableEntry
{
    s16 field0_0x0;
    s16 field1_0x2;
    s16 field2_0x4;
    u8 field3_0x6;
    u8 field4_0x7;
} FloconTableEntry;

/**/
extern s16 floc_ind[8];
extern FloconTableEntry flocon_tab[512];
extern s16 nb_floc[8];
extern s16 VENT_X;
extern s16 VENT_Y;

#endif