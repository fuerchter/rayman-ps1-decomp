#ifndef BLOCK_22C84_H
#define BLOCK_22C84_H

#include "common.h"
#include "common/obj.h"

typedef struct MapData {
    s16 width;
    s16 height;
    s32 length;
    u16 *map;
} MapData;

/* .data */
extern BlockFlags block_flags[32];

/* .data */
extern s16 RandArray[256];

/**/
extern MapData mp;
extern u8 ray_last_ground_btyp;

s16 get_center_x(Obj *obj);
s16 get_center_y(Obj *obj);
u8 on_block_chdir(Obj *obj, s16 param_2, s16 param_3);
void CALC_FOLLOW_SPRITE_SPEED(Obj *obj, Animation *anim1, Animation *anim2, s16 param_4);
s16 GET_SPRITE_POS(Obj *obj, s32 index, s16 *x ,s16 *y, u16 *w, u16 *h);
void GET_RAY_ZDC(Obj *ray, s16 *x, s16 *y, s16 *w, s16 *h);
void GET_BB1_ZDCs(Obj *obj, s16 *param_2, s16 *param_3, s16 *param_4, s16 *param_5, s16 *param_6, s16 *param_7, s16 *param_8, s16 *param_9);
s32 myRand(s32 param_1);  /* ret: s32 or s16 (based on what?) */
void calc_obj_dir(Obj *obj);
s32 OBJ_IN_ZONE(Obj *obj); /* ret: s32 or s16 (based on what, handle_GO_TEST?) */
void calc_obj_pos(Obj *obj);
void makeUturn(Obj *obj);
u16 BTYP(s16 xPos, s16 yPos);
void calc_btyp_square(Obj *obj);
void DO_OBJ_REBOND_EN_X(Obj *obj);
u32 calc_btyp(Obj *obj);

#endif