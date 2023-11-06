#ifndef CAM_SCROLL_H
#define CAM_SCROLL_H

#include "common.h"

extern s16 h_scroll_speed;
extern s16 v_scroll_speed;
extern s16 scroll_start_x;
extern s16 scroll_start_y;
extern s16 scroll_end_x;
extern s16 scroll_end_y;
extern u8 scrollLocked;
extern s16 screen_trembling;
extern s16 screen_trembling2;
extern s16 screen_trembling3;

/* maybe with DO_AUTO_SCROLL instead? */
extern s16 scroll_y;
extern s16 NumScrollObj;
extern s16 scroll_x;

#endif