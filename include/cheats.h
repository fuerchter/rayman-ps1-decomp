#ifndef CHEATS_H
#define CHEATS_H

#include "common.h"
#include "ray/ray_5D190.h"
#include "main_moteur.h"
#include "num_level_36260.h"
#include "main.h"
#include "main_moteur.h"
#include "ray/ray_30A64.h"

/* .data */
extern s16 D_801CEFC8;

/* .data */
extern u8 D_801CF0D8;
extern u8 PS1_PictureInPicture;
extern u8 PS1_15fps;

/**/
extern u8 PS1_DebugMode;

void PS1_CheckPauseAndCheatInputs(void);

#endif