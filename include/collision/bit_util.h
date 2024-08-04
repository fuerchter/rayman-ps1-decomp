#ifndef BIT_UTIL_H
#define BIT_UTIL_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"

/* TODO: is this related with collision at all? */

/* .data */
extern s16 costab[258]; /* size correct? */

void set2bits(s32 *param_1, u8 pos, s32 param_3);
void read2bits(s32 *value, u8 pos, s32 *b1, s32 *b0);
void save_objects_flags(void);
void restore_objects_flags(void);
void snapToSprite(Obj *obj1, Obj *obj2, u32 param_3, s32 param_4, u16 param_5);
Obj * findfirstObject(ObjType obj_type);
Obj * findfirstInactiveObject(ObjType param_1);
void setbit(u8 *buffer, u32 bit_index);
void clearbit(s32 param_1, u32 param_2);
u32 getbit(u8 *buffer, u32 bit_index);
s16 cosinus(s16 param_1);
s16 sinus(s16 param_1);
s32 sinYspeed(Obj *obj, s32 param_2, s16 param_3, u16 *param_4);
s32 ashl16(s16 param_1, u32 param_2); 
s32 ashr16(u16 param_1, u32 param_2);
s32 ashl32(u32 param_1, u32 param_2);
s32 ashr32(u32 value, u32 shift);

#endif