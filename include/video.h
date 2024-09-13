#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"
#include "psyq_3_0/LIBCD.H"
#include "psyq_3_0_missing/LIBCD.H"
#include "psyq_3_0/LIBPRESS.H"
#include "psyq_3_0_missing/LIBPRESS.H"
#include "draw/fade.h"

typedef s16 Video;
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

/* based on FUN_80132d74 */
typedef struct Unk_801cf5e0 {
    u8 * field0_0x0;
    u8 * field1_0x4;
    u8 * field2_0x8;
    RECT field3_0xc;
    u8 field4_0x14;
    u8 field5_0x15;
    u8 field6_0x16;
    u8 field7_0x17;
    s16 frame_count;
} Unk_801cf5e0;

/**/
extern VideoState PS1_VideoState;

void PS1_PlayVideo(Video video);
void FUN_80132980(void);
void PS1_PlayVideoFile(Video video);
void FUN_80132d74(Unk_801cf5e0 *param_1);
void FUN_80132e04(CdlLOC *lba, u32 param_2);
void FUN_80132ea0(u32 *param_1, Video video);
void FUN_80132f8c(void);
void FUN_80133010(void);

#endif