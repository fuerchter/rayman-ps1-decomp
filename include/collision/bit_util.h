#ifndef BIT_UTIL_H
#define BIT_UTIL_H

#include "common.h"

/* .data */
extern s16 costab[258]; /* size correct? */

s32 ashl16(s16 param_1, u32 param_2); /* TODO: is this related with collision at all? */
s16 ashr16(u16 param_1, u32 param_2);

#endif