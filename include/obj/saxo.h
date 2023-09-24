#ifndef SAXO_H
#define SAXO_H

#include "common.h"

typedef struct {
    u8 next_note;
    u8 time;
    s16 field2_0x2;
} SaxAttackEntry;

typedef struct {
    u8 type;
    s16 speed_x;
    s16 speed_y;
    s16 initial_iframes;
    s16 field4_0x8; // unused
} SaxNoteEntry;

typedef struct {
    s16 x_pos;
    s16 y_pos;
    s16 note_box_coll_x;
    s16 note_box_coll_y;
    s16 sprite2_x;
    s16 sprite2_y;
    u8 coup;
    u8 saved_hp;
    u8 field8_0xe;
    u8 field9_0xf;
    s16 field10_0x10;
} SaxData;

#endif