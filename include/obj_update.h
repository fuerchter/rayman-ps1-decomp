#ifndef OBJ_UPDATE_H
#define OBJ_UPDATE_H

#include "common.h"

typedef struct {
    u8 flip_x;
    u8 x_pos;
    u8 y_pos;
    u8 sprite;
} AnimationLayer;

typedef struct {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} AnimationFrame;

typedef struct {
    AnimationLayer * layers;
    AnimationFrame * frames;
    u16 layers_count;
    u16 frames_count;
} Animation;

typedef enum {
    ANIMMODE_NONE=0,
    ANIMMODE_RESET_IF_NEW=1,
    ANIMMODE_RESET=2
} ChangeAnimMode;

#endif