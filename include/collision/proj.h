#ifndef PROJ_H
#define PROJ_H

#include "common.h"

/**/
extern s16 PROJ_CENTER_X;
extern s16 PROJ_CENTER_Y;
extern u8 zoom_mode;

void set_proj_center(s16 param_1, s16 param_2);
s32 get_proj_dist(s16 param_1, s16 param_2);
s32 get_proj_dist2(s16 param_1, s16 param_2);
s32 get_proj_x(s16 param_1, s16 param_2);
s32 get_proj_y(s16 param_1, s16 param_2);
void set_zoom_mode(u8 mode);
s32 inverse_proj_x(s16 param_1, s16 param_2);
s32 inverse_proj_y(s16 param_1, s16 param_2);

#endif