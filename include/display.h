#ifndef DISPLAY_H
#define DISPLAY_H

#include "common.h"

typedef struct {
    s32 img_buffer_offset; // unused for final release
    u8 id; // 0 is invalid
    u8 width; // full width
    u8 height; // full height
    u8 sprite_width; // sprite width
    u8 sprite_height; // sprite height
    u8 sprite_pos; // x and y as 4-bit values
    u8 field7_0xa;
    u8 field8_0xb;
    u16 clut; // palette
    u16 tpage; // texture page
    u8 page_x;
    u8 page_y;
} Sprite;

#endif