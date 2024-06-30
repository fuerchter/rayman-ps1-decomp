#ifndef GENDOOR_H
#define GENDOOR_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "obj/bateau_command.h"
#include "obj_init_kill.h"

/**/
extern u8 *link_init; /* not sure if this should be here? since non-gendoor things use links? */

void deactivate_ship_links(void);
s32 linkListHoldsAGendoor(Obj *obj);
s32 FUN_8015666c(Obj *obj);
s32 FUN_80156710(Obj *obj);
void correct_gendoor_link(void);
void suppressFromLinkList(Obj *obj);
void correct_link(void);

#endif