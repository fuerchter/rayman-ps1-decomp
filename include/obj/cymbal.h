#ifndef CYMBAL_H
#define CYMBAL_H

#include "common.h"
#include "common/obj.h"
#include "common/ray.h"
#include "common/level.h"
#include "gendoor.h"

/*
code for:
TYPE_CYMBALE
TYPE_CYMBAL1
TYPE_CYMBAL2
*/

/**/
extern s16 cymbal_obj_id[12];
extern u8 nb_cymbal_in_map;

void DO_CYMBAL_COMMAND(Obj *obj);
void DO_2_PARTS_CYMBAL(Obj *arg0);

#endif