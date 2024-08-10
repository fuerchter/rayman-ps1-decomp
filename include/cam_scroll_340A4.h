#ifndef CAM_SCROLL_340A4_H
#define CAM_SCROLL_340A4_H

#include "common.h"
#include "common/ray.h"
#include "common/level.h"
#include "cam_scroll_29B5C.h"
#include "obj/eau.h"
#include "timers.h"

/**/
extern s16 NumScrollObj;
extern s16 scroll_obj_id[100];
extern s16 scroll_x;
extern s16 scroll_y;

void DO_AUTO_SCROLL(void);

#endif