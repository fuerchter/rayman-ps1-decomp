#ifndef CHEATS_H
#define CHEATS_H

#include "common.h"
#include "common/ray.h"
#include "ray/ray_5D190.h"

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