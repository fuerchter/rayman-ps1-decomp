#ifndef FALLING_OBJ_COMMAND_H
#define FALLING_OBJ_COMMAND_H

#include "common.h"
#include "common/obj.h"
#include "common/ray.h"
#include "collision/block_22C84.h"

void move_fruit_in_water(Obj *obj);
void DO_FALLING_OBJ_CMD(Obj *obj);

#endif