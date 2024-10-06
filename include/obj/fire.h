#ifndef FIRE_H
#define FIRE_H

#include "common.h"
#include "boss.h"

/**/
extern s16 flamme_droite_id;
extern s16 flamme_gauche_id;
extern u8 flammes_actives;

void DoFlammeCommand(Obj *obj);
void AllocateFlammes(s16 param_1);

#endif