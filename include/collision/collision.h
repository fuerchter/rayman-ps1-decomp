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

void PS1_SetZDC(s16 x, s16 y, u8 w, u8 h, u8 flags, u8 sprite);
void PS1_SetTypeZDC(ObjType type, u16 param_2, s32 param_3);
u16 get_nb_zdc(Obj *param_1);
u16 get_zdc_index(Obj *obj);
ZDC * get_zdc(Obj *obj, s16 param_2);
s32 get_ZDCPTR(void);
u8 in_coll_sprite_list(Obj *obj, u16 param_2);
s32 box_inter_v_line(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7);
s32 box_inter_h_line(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7);
u8 inter_box(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s16 param_5, s16 param_6, s32 param_7, s32 param_8);
void GET_OBJ_ZDC(Obj *obj, s16 *x, s16 *y, s16 *w, s16 *h);
s32 GET_SPRITE_ZDC(Obj *param_1, s16 param_2, s16 *param_3, s16 *param_4, s16 *param_5, s16 *param_6);
s32 BOX_HIT_SPECIAL_ZDC(s16 param_1, s16 param_2, s16 param_3, s16 param_4, Obj *param_5);
s32 BOX_IN_COLL_ZONES(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, Obj *obj);
u32 COLL_BOX_SPRITE(s16 param_1, s16 param_2, s16 param_3, s16 param_4, Obj *param_5);
s32 CHECK_BOX_COLLISION(s16 param_1, s16 x, s16 y, s16 w, s16 h, Obj *obj);
s32 possible_sprite(Obj *obj, s32 index);
s32 setToleranceDist(s32 param_1, s32 param_2, s16 param_3);
void SET_RAY_DIST_MULTISPR_CANTCHANGE(Obj *obj);
void SET_RAY_DIST_PI(Obj *obj);
void SET_RAY_DIST_BAG(Obj *obj);
void SET_RAY_DIST(Obj *obj);
void do_boum(void);
void DO_PNG_COLL_STONEMAN(Obj *obj);
void DO_PNG_COLL_STONEWOMAN(Obj *obj);
void DO_POING_COLLISION(void);
s32 COLL_BOX_ALL_SPRITES(s16 param_1, s16 param_2, s16 param_3, s16 param_4, Obj *param_5);
s16 COLL_RAY_PIC(void);
void COLL_RAY_BLK_MORTEL(void);
void RAY_KO(void);
void RAY_HIT(u8 hurt, Obj *obj);
void standard_frontZone(Obj *obj, s16 *x, s16 *w);
void SET_DETECT_ZONE_FLAG(Obj *obj);
void goToRay(Obj *obj);
void unleashMonsterHost(Obj *obj);
void DO_COLL_RAY_CYMBALE(Obj *param_1);
void DoAudioStartRaymanCollision(Obj *param_1);
void PS1_DoRaymanCollision(void);
void DO_COLLISIONS(void);
void DO_OBJ_COLLISIONS(Obj *param_1, s16 param_2);

#endif