#ifndef BLOCK_22C84_H
#define BLOCK_22C84_H

#include "common.h"
#include "common/obj.h"
#include "common/world_map.h"
#include "common/ray.h"
#include "common/rayevts.h"
#include "common/mapdata.h"
#include "collision/bit_util.h"
#include "collision/etat.h"

/* .data */
extern s16 RandArray[256];

/**/
extern u8 ray_last_ground_btyp; /* bool or enum with only 0 and 1, not sure*/
extern u16 PS1_RandSum;
extern s16 RandomIndex;

s16 get_center_x(Obj *obj);
s16 get_center_y(Obj *obj);
u8 on_block_chdir(Obj *obj, s16 offs_bx, s16 offs_by);
void CALC_FOLLOW_SPRITE_SPEED(Obj *obj, Animation *anim1, Animation *anim2, s16 param_4);
s16 GET_SPRITE_POS(Obj *obj, s16 index, s16 *x, s16 *y, s16 *w, s16 *h);
void GET_RAY_ZDC(Obj *ray, s16 *x, s16 *y, s16 *w, s16 *h);
void GET_BB1_ZDCs(Obj *obj, s16 *x_1, s16 *y_1, s16 *w_1, s16 *h_1, s16 *x_2, s16 *y_2, s16 *w_2, s16 *h_2);
s32 myRand(s16 max_incl); /* ret: s32 (based on DO_MAIN_LOOP?) */
void calc_obj_dir(Obj *obj);
s32 OBJ_IN_ZONE(Obj *obj); /* ret: s32 or s16 (based on what, handle_GO_TEST?) */
void calc_obj_pos(Obj *obj);
void makeUturn(Obj *obj);
u16 BTYP(s16 x, s16 y);
void calc_btyp_square(Obj *obj);
void DO_OBJ_REBOND_EN_X(Obj *obj);
u32 calc_btyp(Obj *obj);

#endif