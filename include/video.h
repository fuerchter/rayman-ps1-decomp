#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"

typedef enum Video {
    VIDEO_NONE=0,
    VIDEO_PRES=1,
    VIDEO_INTRO=2,
    VIDEO_DEMO=3,
    VIDEO_MAP_INTRO=4, /* Same as the normal intro, but only plays the end, */
    VIDEO_WIN=5
} Video;

typedef enum VideoState {
    VIDEOST_NOT_PLAYING=0,
    VIDEOST_PLAYING=1,
    VIDEOST_INTERRUPTED=2
} VideoState;

extern VideoState PS1_VideoState;

#endif