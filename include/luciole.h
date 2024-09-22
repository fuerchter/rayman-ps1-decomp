#ifndef LUCIOLE_H
#define LUCIOLE_H

#include "common.h"
#include "collision/block_22C84.h"

/**/
extern s16 x_luc;
extern s16 y_luc;
extern s16 n_ray;
extern s16 vx_luc;
extern s16 vy_luc;
extern s16 x_main_luc;
extern s16 y_main_luc;
extern s16 x_ray[4];
extern s16 y_ray[4];

void INIT_LUCIOLE(void);
void DO_LUCIOLE(void);

#endif