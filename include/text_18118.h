#ifndef TEXT_18118_H
#define TEXT_18118_H

#include "common.h"

/* .data */
extern u8 D_801CEE10;
extern u8 let_shadow;

/**/
extern u8 colour;
extern s16 D_801F81B0;

void display_text(u8 *text, s16 x_pos, s16 y_pos, u8 font_size, u32 param_5);

#endif