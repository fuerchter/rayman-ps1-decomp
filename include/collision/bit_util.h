#ifndef BIT_UTIL_H
#define BIT_UTIL_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "collision/block_22C84.h"

/* TODO: is this related with collision at all? */

/* .data */
extern s16 costab[258]; /* size correct? */

/**/
extern s32 saveobj[16];

void set2bits(s32 *param_1, u8 pos, s32 param_3);
void read2bits(s32 *value, u8 pos, s32 *b1, s32 *b0);
void save_objects_flags(void);
void restore_objects_flags(void);
void snapToSprite(Obj *obj_1, Obj *obj_2, u8 obj_2_spr, s32 x_offs, u16 y_offs);
Obj *findfirstObject(ObjType obj_type);
Obj *findfirstInactiveObject(ObjType param_1);
void setbit(u8 *buffer, u16 index);
void clearbit(u8 *buffer, u16 index);
u8 getbit(u8 *buffer, u16 index);
s16 cosinus(s16 param_1);
s16 sinus(s16 param_1);
s16 sinYspeed(Obj *obj, s32 param_2, s16 param_3, s16 *param_4);
s32 ashl16(s16 value, u8 shift); /* s32? says itself, MOVE_OBJECT*/
s16 ashr16(s16 value, u8 shift); /* get_offset_in_save_zone and calc_btyp_square made me check return type */
s32 ashl32(s32 value, u8 shift);
s32 ashr32(s32 value, u8 shift);

#endif