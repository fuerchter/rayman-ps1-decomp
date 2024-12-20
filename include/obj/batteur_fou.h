#ifndef BATTEUR_FOU_H
#define BATTEUR_FOU_H

#include "common.h"
#include "collision/bit_util.h"
#include "obj/eyes_3C3A8.h"

/**/
extern s16 bat_nb_frap;

void DO_BAT_FLASH(s32 in_x, s32 in_y);
void DO_BAT_LEFT_FLASH(Obj *obj);
void DO_BAT_RIGHT_FLASH(Obj *obj);
void DO_BAT_LEFT_RIGHT_FLASH(Obj *obj);
s16 bat_dir(Obj *obj);
void bat_init_scroll(Obj *obj);
void bat_done_scroll(void);
void DO_BAT_COMMAND(Obj *obj);
void BAT_ray_in_zone(Obj *obj);
void DO_BAT_POING_COLLISION(Obj *bat_obj);
s32 bat_get_eject_sens(Obj *obj);

#endif