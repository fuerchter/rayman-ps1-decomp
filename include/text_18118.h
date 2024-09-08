#ifndef TEXT_18118_H
#define TEXT_18118_H

#include "common.h"
#include "text_24E10.h"

/* .data */
extern u8 D_801CEE10;
extern u8 let_shadow;

/**/
extern u8 colour;
extern s16 D_801F81B0;

u8 PS1_deter_num_let_old(s32 param_1);
u8 PS1_calc_let_Width(s16 sprite, u8 font);
s32 calc_let_Width(u8 param_1, s16 param_2);
s32 PS1_CalcTextWidth(u8 *str, u8 font);
void PS1_DisplayCenteredText(u8 *str, u16 param_2, u32 color);
void PS1_DisplayMultipleCenteredText(u32 param_1, s32 param_2);
void DrawFondBoxNormal(s16 param_1, s16 param_2, s16 param_3, s16 param_4, u8 param_5);
void DrawBlackBoxNormal(s16 param_1, s16 param_2, s16 param_3, s16 param_4, u8 param_5);
void DISPLAY_BLACKBOX(s16 param_1, s16 param_2, s16 param_3, s16 param_4, u8 param_5, u8 isFond);
void display_text_sin(u8 *param_1, u16 param_2, s16 param_3, s16 param_4, u8 param_5, u8 param_6);
void display_text(u8 *text, s16 x_pos, s16 y_pos, u8 font_size, u32 param_5);
void display_box_text(TextToDisplay *txt);

#endif