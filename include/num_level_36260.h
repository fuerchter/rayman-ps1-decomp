#ifndef NUM_LEVEL_36260_H
#define NUM_LEVEL_36260_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "common/ray.h"
#include "obj_update.h"
#include "ray/ray_32398.h"
#include "obj/poing.h"
#include "cam_scroll_340A4.h"

extern s16 departlevel;
extern u8 finBosslevel[2];
extern u8 fin_boss;

void new_level_init(void);
void fix_numlevel(Obj *obj);
void TEST_SIGNPOST(void);

#endif