#ifndef FIRST_INIT_H
#define FIRST_INIT_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "psyq_3_0_missing/LIBCD.H"
#include "draw/fade.h"
#include "draw/rollup_trans.h"

/* .data */
extern RECT D_801CF0E0;
extern RECT D_801CF0E8;

/* .data */
extern u8 D_801CF438;
extern u8 D_801CF440;

s16 FUN_8019f848(void);
s16 FUN_8019f88c(void);
void FUN_8019f8d0(void);
u8 PS1_OldLoadingScreen(void);
void FUN_8019fa94(u8 param_1);
void FUN_8019fb84(void);
void FUN_8019fd40(void);
u8 FUN_8019fda0(void);
void FUN_8019fdd0(void);
void FUN_8019fe8c(void);
void PS1_SetLevelto_4_1(void);
void FIRST_INIT(void);

#endif