#ifndef PIRATE_NGAWE_H
#define PIRATE_NGAWE_H

#include "common.h"
#include "collision/bit_util.h"

void ngaweFollowsShip(Obj *obj);
void ngaweTriesToGrabShip(Obj *obj);
void allocatePirateNgaweRing(Obj *param_1, s16 param_2, u8 param_3);
void DO_NGW_TIR(Obj *obj);
void NGW_REACT_TO_RAY_IN_ZONE(Obj *obj);
void DO_ONE_NGW_COMMAND(Obj *obj);
void DO_NGW_POING_COLLISION(Obj *ngw_obj);

#endif