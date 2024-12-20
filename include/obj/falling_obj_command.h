#ifndef FALLING_OBJ_COMMAND_H
#define FALLING_OBJ_COMMAND_H

#include "common.h"
#include "common/obj.h"
#include "common/ray.h"
#include "common/mapdata.h"
#include "collision/collision.h"

void move_fruit_in_water(Obj *obj);
void DO_FALLING_OBJ_CMD(Obj *obj);

#endif