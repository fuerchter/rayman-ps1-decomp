#ifndef INPUT_ED20_H
#define INPUT_ED20_H

#include "common.h"

typedef enum {
    INPUT_NONE=0,
    INPUT_LEFT=1,
    INPUT_RIGHT=2,
    INPUT_UP=3,
    INPUT_DOWN=4,
    INPUT_CROSS=5,
    INPUT_CIRCLE=6,
    INPUT_SQUARE=7,
    INPUT_TRIANGLE=8,
    INPUT_START=9,
    INPUT_SELECT=10,
    INPUT_R1=11,
    INPUT_R2=12,
    INPUT_L1=13,
    INPUT_L2=14,
    INPUT_DISABLE_DEBUG=15, // unused,
    INPUT_ENABLE_DEBUG=16, // unused,
    INPUT_START_SELECT=17,
    INPUT_UNUSED_12=18,
    INPUT_13=19,
    INPUT_14=20,
    INPUT_UNUSED_15=21,
    INPUT_UNUSED_16=22,
    INPUT_17=23,
    INPUT_18=24,
    INPUT_UNUSED_19=25,
    INPUT_UNUSED_1A=26,
    INPUT_READ=255
} Input;

//TODO: these are also defined in libetc.h
typedef enum {
    PAD_NONE=0,
    PAD_L2=1,
    PAD_R2=2,
    PAD_L1=4,
    PAD_R1=8,
    PAD_TRIANGLE=16,
    PAD_CIRCLE=32,
    PAD_CROSS=64,
    PAD_SQUARE=128,
    PAD_SELECT=256,
    PAD_L3=512,
    PAD_R3=1024,
    PAD_START=2048,
    PAD_UP=4096,
    PAD_RIGHT=8192,
    PAD_DOWN=16384,
    PAD_LEFT=32768
} PsxPadButtonStates;

#endif