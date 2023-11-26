#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"

typedef u16 Video;
#define VIDEO_NONE 0
#define VIDEO_PRES 1
#define VIDEO_INTRO 2
#define VIDEO_DEMO 3
#define VIDEO_MAP_INTRO 4 /* Same as the normal intro, but only plays the end */
#define VIDEO_WIN 5

typedef u8 VideoState;
#define VIDEOST_NOT_PLAYING 0
#define VIDEOST_PLAYING 1
#define VIDEOST_SKIPPED 2

extern VideoState PS1_VideoState;

void FUN_80133018(void);

#endif