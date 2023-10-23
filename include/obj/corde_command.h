#ifndef CORDE_COMMAND_H
#define CORDE_COMMAND_H

#include "common.h"
#include "obj_update.h"
#include "timers.h"
#include "ray/ray_32398.h"

extern s16 pierreAcorde_obj_id;

void DO_CORDE_COMMAND(Obj *obj);
void DO_PAC_COMMAND(Obj *obj);
void DO_CFUMEE_COMMAND(Obj *obj);

#endif