#ifndef MAMA_PIRATE_H
#define MAMA_PIRATE_H

#include "common.h"

typedef struct CouteauxInfo
{
    s16 x_pos;
    s16 y_pos;
    s16 field2_0x4;
    s16 field3_0x6;
    s16 field4_0x8;
    s16 field5_0xa;
    s16 field6_0xc;
    u8 field7_0xe;
    u8 active;
    u8 field9_0x10;
    u8 id; // Created by retype action
} CouteauxInfo;

#endif