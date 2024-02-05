#ifndef MEDAILLON_TOON_H
#define MEDAILLON_TOON_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "obj_update.h"
#include "obj_init_kill.h"
#include "main_moteur.h"
#include "sound.h"

/* .data */
extern s16 snd_flag_medaillon;

void DO_MEDAILLON_TOON(Obj *obj);
void DO_MEDAILLON_TOON_GELE(void);
void ALLOCATE_MEDAILLON_TOON(void);

#endif