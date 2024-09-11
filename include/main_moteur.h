#ifndef MAIN_MOTEUR_H
#define MAIN_MOTEUR_H

#include "common.h"
#include "common/display.h"
#include "common/record.h"
#include "cheats.h"
#include "draw/draw_14FF4.h"
#include "input_ED20.h"
#include "obj/fee_3D76C.h"
#include "music.h"
#include "vignet.h"
#include "moteur_init_end.h"

/* .data */
extern RECT PS1_MemoryUsageRect;

/* .data */
extern RECT *PTR_PS1_MemoryUsageRect_801cee70;
extern u8 PS1_MemoryUsageDisplayMode;

/* .data */
extern u8 in_pause;
extern u8 PS1_Ingame;

/* .data, BAD ALIGNMENT */
extern s16 PS1_CanPlayDeathMusic;
extern s16 D_801CEEA0;
extern u8 D_801CEEA2;

/**/
extern u8 gele;

void DO_GROS_MOTEUR_NORMAL(void);
void DO_MAIN_LOOP(void);

#endif