#ifndef ROLLUP_TRANS_H
#define ROLLUP_TRANS_H

#include "common.h"
#include "common/display.h"
#include "psyq_3_0/LIBGPU.H"
#include "draw/draw_548CC.h"

void FUN_8012d030(Vec2 tpage_pos, Vec2 param_2, s16 step_width, s16 step_height, s16 poly_count);
void FUN_8012d27c(void);
void FUN_8012d2b0(s16 param_1);
void PS1_RollUpTransition(s16 param_1, s16 left_to_right);
u8 PS1_RollUpRToL(void);
u8 PS1_RollUpLToR(void);
void FUN_8012da14(void);

#endif