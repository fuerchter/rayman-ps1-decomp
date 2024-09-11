#ifndef FADE_H
#define FADE_H

#include "common.h"
#include "common/display.h"
#include "unknown/draw_548CC.h"

typedef struct RGBAArray {
    u8 data[4];
} RGBAArray;

/* .data */
extern s16 D_801CF018;
extern u8 PS1_DisableInputs;

/**/
extern s16 fade;
extern u8 D_801F7FF0;

void FUN_80169420(Display *disp);
void FUN_80169564(u32 param_1, s16 param_2);
void FUN_801695ec(s16 param_1);
void FUN_80169a3c(RGBAArray *param_1, s16 param_2);
void FUN_80169ac8(RGBAArray *param_1, s16 param_2);
void FUN_80169b54(void);
void FUN_80169b5c(void);
void INIT_FADE_OUT(void);
void INIT_FADE_IN(void);
void DO_FADE(void);
s16 PS1_DO_FADE_OUT_PRG(void);
void DO_FADE_OUT(void);
void PS1_DO_PICTURE_IN_PICTURE(void);

#endif