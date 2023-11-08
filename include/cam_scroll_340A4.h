#ifndef CAM_SCROLL_340A4_H
#define CAM_SCROLL_340A4_H

#include "common.h"
#include "ray/ray_32398.h"
#include "timers.h"
#include "cam_scroll_29B5C.h"
#include "obj/eau.h"
#include "obj_update.h"

/**/
extern s16 NumScrollObj;
extern s16 scroll_obj_id[100];
extern s16 scroll_x;
extern s16 scroll_y;

void DO_AUTO_SCROLL(void);

#endif