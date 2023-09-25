#ifndef TEXT_24E10_H
#define TEXT_24E10_H

#include "common.h"

typedef struct {
    u8 text[48];
    s16 centered_x_pos;
    s16 centered_y_pos;
    s16 width;
    s16 height;
    s16 x_pos;
    s16 y_pos;
    u8 font_size;
    u8 field8_0x3d;
    u8 is_fond;
    u8 color;
} TextToDisplay;

#endif