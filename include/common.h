#ifndef COMMON_H
#define COMMON_H

#include "SYS/TYPES.H"
#include "include_asm.h"

/*#define NUGGET*/
#define MATCHES_BUT

#ifdef NUGGET
#define BSS_DEFS
#define MATCHES_BUT
#define NONMATCHINGS
#endif

#define FLG(x) (1 << x)
#define LEN(x) (sizeof(x) / sizeof(x[0]))
#define MAX_1(x, y) ((x) > (y) ? (x) : (y))
#define MAX_2(x, y) if (x < y) x = y;
#define MAX_3(x, y) if (y > x) x = y;
#define MIN_1(x, y) ((x) < (y) ? (x) : (y))
#define MIN_2(x, y) if (x > y) x = y;
#define MIN_3(x, y) if (y < x) x = y;
#define ABS(x) (x >= 0 ? (x) : -(x))
#define SGN(x) (x >= 0 ? (x > 0 ? 1 : 0) : -1)

#define true 1
#define false 0
#define null 0

typedef unsigned char u8; /* unsigned  8-bit */
typedef unsigned short u16; /* unsigned 16-bit */
typedef unsigned long u32; /* unsigned 32-bit */

typedef signed char s8; /* signed  8-bit */
typedef short s16; /* signed 16-bit */
typedef long s32; /* signed 32-bit */

typedef volatile unsigned char vu8; /* unsigned  8-bit */
typedef volatile unsigned short vu16; /* unsigned 16-bit */
typedef volatile unsigned long vu32; /* unsigned 32-bit */

typedef volatile signed char vs8; /* signed  8-bit */
typedef volatile short vs16; /* signed 16-bit */
typedef volatile long vs32; /* signed 32-bit */

#endif