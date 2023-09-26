#ifndef DEMO_9FD4_H
#define DEMO_9FD4_H

#include "common.h"

typedef struct {
    s32 current_offset;
    s32 repeat_length;
    s32 repeat_index;
    s32 length;
    u8 * data;
    u8 is_recording;
    u8 is_playing;
    u8 is_finished;
} Record;

extern Record record;

#endif