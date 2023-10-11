#ifndef FALLING_OBJ_COMMAND_H
#define FALLING_OBJ_COMMAND_H

#include "common.h"
#include "obj_update.h"
#include "ray/ray_32398.h"
#include "collision/collision_block.h"

void move_fruit_in_water(Obj *obj);
void DO_FALLING_OBJ_CMD(Obj *obj);

#endif