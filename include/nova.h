#ifndef NOVA_H
#define NOVA_H

#include "common.h"
#include "collision/etat.h"

Obj * allocateNOVA(void);
void DO_NOVA(Obj *obj);
void DO_NOVA2(Obj *obj);
int NOVA_STATUS_BAR(void);

#endif