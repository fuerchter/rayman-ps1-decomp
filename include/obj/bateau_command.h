#ifndef BATEAU_COMMAND_H
#define BATEAU_COMMAND_H

#include "common.h"
#include "obj_update.h"
#include "obj/mama_pirate.h" /* TODO: circular? */
#include "obj/pirate_ngawe.h"

/**/
extern s16 bateau_obj_id;

void doShipCommand(Obj *obj);

#endif