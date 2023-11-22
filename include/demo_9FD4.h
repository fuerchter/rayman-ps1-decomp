#ifndef DEMO_9FD4_H
#define DEMO_9FD4_H

#include "common.h"
#include "ray/ray_5D190.h"
#include "ray/ray_32398.h"
#include "ray/ray_30A64.h"
#include "video.h"
#include "demo_7F2BC.h"
#include "world_map_95CC.h"
#include "num_level_36260.h"
#include "menu/menu_7F4B4.h"

typedef struct Record
{
    s32 current_offset;
    s32 repeat_length;
    s32 repeat_index;
    s32 length;
    u8 * data;
    u8 is_recording;
    u8 is_playing;
    u8 is_finished;
} Record;

/* .data */
extern u8 DemoRecord[6][300];
extern s16 DemoRecordSize[6];
extern s16 DemoRecordWorld[6];
extern s16 DemoRecordMap[6];

/**/
extern Record record;
extern u8 ModeDemo; /* TODO: enum also? */
extern u16 RunTimeDemo;
extern s16 NumDemo;

void InitDemoJeu(void);
void FinDemoJeu(void);

#endif