#ifndef BLACK_RAY_COMMAND_H
#define BLACK_RAY_COMMAND_H

#include "common.h"

typedef struct {
    s16 x_pos;
    s16 y_pos;
    s16 poing_x_pos;
    s16 poing_y_pos;
    u8 main_etat;
    u8 sub_etat;
    u8 anim_index;
    u8 anim_frame;
    u8 flip_x;
    u8 poing_anim_index;
    u8 poing_anim_frame;
    u8 poing_flip_x;
    u8 poing_is_active;
    u8 scale;
} RayStack;

#endif