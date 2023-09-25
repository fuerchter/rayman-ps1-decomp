#ifndef DARK_729F0_H
#define DARK_729F0_H

#include "common.h"

typedef struct {
    s16 x_pos;
    s16 y_pos;
    u8 obj_id;
    u8 index; // 0-4
    u8 field4_0x6;
    u8 mode; // 0 is inactive, 1 is getting less bright and 2 is getting brighter
    u16 value; // goes from 100 to 0
} VitrauxInfo;

#endif