#ifndef ETAT_H
#define ETAT_H

#include "common.h"
#include "obj_update.h"

void set_main_and_sub_etat(Obj *obj, u8 main_etat, u8 sub_etat);
void set_main_etat(Obj *param_1, u8 main_etat);
void set_sub_etat(Obj *obj, u8 sub_etat);

#endif