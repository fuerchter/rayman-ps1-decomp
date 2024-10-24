#ifndef DEMO_9FD4_H
#define DEMO_9FD4_H

#include "common.h"
#include "common/rayevts.h"
#include "common/record.h"
#include "video.h"
#include "num_level_36260.h"
#include "menu/menu_7F4B4.h"
#include "ray/ray_5D190.h"

/* .data */
extern u8 DemoRecord[6][300];
extern s16 DemoRecordSize[6];
extern s16 DemoRecordWolrd[6];
extern s16 DemoRecordMap[6];

/**/
extern u8 ModeDemo; /* TODO: enum also? */
extern u16 RunTimeDemo;
extern s16 NumDemo;

void InitDemoJeu(void);
void FinDemoJeu(void);

#endif