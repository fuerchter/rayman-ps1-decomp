#ifndef MST_SCROLL_H
#define MST_SCROLL_H

#include "common.h"
#include "cam_scroll_29B5C.h"

/**/
extern s16 mst_scroll_obj_id;

void DO_MST_SCROLL_COMMAND(Obj *obj, s16 param_2);
void DO_MST_CHANGE_COMMAND(s32 hp);

#endif