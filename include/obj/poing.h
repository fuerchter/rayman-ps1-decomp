#ifndef POING_H
#define POING_H

#include "common.h"

typedef struct Poing
{
    s32 field0_0x0;
    s16 field1_0x4;
    s16 speed_x;
    s16 charge;
    s16 field4_0xa;
    u8 sub_etat;
    u8 is_returning;
    u8 is_active;
    u8 damage;
    u8 is_charging;
    u8 is_boum;
} Poing;

#endif