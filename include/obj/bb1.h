#ifndef BB1_H
#define BB1_H

#include "common.h"

typedef struct BB1Data
{
    s16 speed_x;
    s16 field1_0x2;
    u8 field2_0x4;
    u8 saved_main_etat;
    u8 saved_sub_etat;
    s16 saved_cmd;
    s16 sprite6_x;
    s16 sprite6_y;
    u8 field8_0xe;
} BB1Data;

typedef struct BBAttackEntry
{
    s16 attack;
    u8 wait_for_fin_atan;
} BBAttackEntry;

#endif