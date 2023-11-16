#ifndef NUM_LEVEL_36260_H
#define NUM_LEVEL_36260_H

#include "common.h"
#include "obj_update.h"
#include "ray/ray_32398.h"
#include "ray/ray_5D190.h"
#include "world_map_677C0.h"
#include "obj/poing.h"
#include "moteur_init_end.h"
#include "main_moteur.h"
#include "cam_scroll_340A4.h"

extern s16 departlevel;
extern u8 finBosslevel[2];
extern u8 fin_boss;

void new_level_init(void);
void fix_numlevel(Obj *obj);
void TEST_SIGNPOST(void);

#endif