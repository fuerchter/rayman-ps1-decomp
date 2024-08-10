#ifndef BLACK_RAY_COMMAND_H
#define BLACK_RAY_COMMAND_H

#include "common.h"

typedef struct RayStack
{
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

/**/
extern RayStack rayStack[100];
extern u8 black_pos_in_stack;
extern s16 black_ray_obj_id;
extern s16 black_fist_obj_id;

#endif