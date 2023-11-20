#ifndef COLLISION_H
#define COLLISION_H

#include "common.h"
#include "obj_update.h"

typedef struct ZDC
{
    s16 x_pos;
    s16 y_pos;
    u8 width;
    u8 height;
    u8 flags;
    u8 sprite;
} ZDC;

extern s16 ray_zdc_x;
extern s16 ray_zdc_y;
extern s16 ray_zdc_w;
extern s16 ray_zdc_h;
extern u8 in_air_because_hit;

s16 COLL_RAY_PIC(void);
void set_main_and_sub_etat(Obj *obj, u8 main_etat, u8 sub_etat);
void set_main_etat(Obj *param_1, u8 main_etat);
void set_sub_etat(Obj *obj, u8 sub_etat);

#endif