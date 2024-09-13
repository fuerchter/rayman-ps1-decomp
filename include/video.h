#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"
#include "psyq_3_0/LIBCD.H"

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

/**/
extern VideoState PS1_VideoState;

void PS1_PlayVideo(Video video);
void FUN_80132980(void);
void PS1_PlayVideoFile(Video video);
void FUN_80132d74(s32 *param_1);
void FUN_80132e04(CdlLOC *lba, u32 param_2);
void FUN_80132ea0(u32 *param_1, Video video);
void FUN_80133010(void);

#endif