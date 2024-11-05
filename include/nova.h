#ifndef NOVA_H
#define NOVA_H

#include "common.h"
#include "collision/etat.h"

Obj *allocateNOVA(void);
void DO_NOVA(Obj *in_obj);
void DO_NOVA2(Obj *in_obj);
s32 NOVA_STATUS_BAR(void);

#endif