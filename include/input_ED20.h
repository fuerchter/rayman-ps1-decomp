#ifndef INPUT_ED20_H
#define INPUT_ED20_H

#include "common.h"

typedef u32 Input;
#define INPUT_NONE 0
#define INPUT_LEFT 1
#define INPUT_RIGHT 2
#define INPUT_UP 3
#define INPUT_DOWN 4
#define INPUT_CROSS 5
#define INPUT_CIRCLE 6
#define INPUT_SQUARE 7
#define INPUT_TRIANGLE 8
#define INPUT_START 9
#define INPUT_SELECT 10
#define INPUT_R1 11
#define INPUT_R2 12
#define INPUT_L1 13
#define INPUT_L2 14
#define INPUT_DISABLE_DEBUG 15 // unused
#define INPUT_ENABLE_DEBUG 16 // unused
#define INPUT_START_SELECT 17
#define INPUT_UNUSED_12 18
#define INPUT_13 19
#define INPUT_14 20
#define INPUT_UNUSED_15 21
#define INPUT_UNUSED_16 22
#define INPUT_17 23
#define INPUT_18 24
#define INPUT_UNUSED_19 25
#define INPUT_UNUSED_1A 26
#define INPUT_READ 255

/* TODO: these are also defined in libetc.h */
typedef u32 PsxPadButtonStates;
#define PAD_NONE 0
#define PAD_L2 1
#define PAD_R2 2
#define PAD_L1 4
#define PAD_R1 8
#define PAD_TRIANGLE 16
#define PAD_CIRCLE 32
#define PAD_CROSS 64
#define PAD_SQUARE 128
#define PAD_SELECT 256
#define PAD_L3 512
#define PAD_R3 1024
#define PAD_START 2048
#define PAD_UP 4096
#define PAD_RIGHT 8192
#define PAD_DOWN 16384
#define PAD_LEFT 32768

extern s32 PS1_GlobalTimer;

s32 but0pressed();
s32 but1pressed();
s32 but2pressed();
s32 but3pressed();

#endif