#ifndef ROLLUP_TRANS_H
#define ROLLUP_TRANS_H

#include "common.h"
#include "common/display.h"
#include "psyq_3_0/LIBGPU.H"
#include "draw/draw_548CC.h"

/* .data */
extern DVECTOR D_801CEDE4;
extern DVECTOR D_801CEDE8;
extern DVECTOR D_801CEDEC[2];

/**/
extern s16 PS1_RollUpPosition;
extern SVECTOR D_801F3EC0[82];
extern SVECTOR D_801F56B8;
extern VECTOR D_801F57D0;
extern s16 D_801F84D8;
extern s16 D_801F98F8;
extern s16 D_801F9930;
extern s16 D_801F9938;
extern s32 D_801F6390;

void FUN_8012d030(DVECTOR tpage_pos, DVECTOR param_2, s16 step_width, s16 step_height, s16 poly_count);
void FUN_8012d27c(void);
void FUN_8012d2b0(s16 rollup_pos);
void PS1_RollUpTransition(s16 rollup_pos, s16 left_to_right);
s16 PS1_RollUpRToL(void);
s16 PS1_RollUpLToR(void);
void FUN_8012da14(void);

#endif