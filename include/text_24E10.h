#ifndef TEXT_24E10_H
#define TEXT_24E10_H

#include "common.h"
#include "common/text_to_display.h"
#include "draw/text_18118.h" /* TODO: circular? */

/* .data */
extern u8 D_801CEFA4;

void INIT_TEXT_TO_DISPLAY(void);
u8 deter_num_let(u8 param_1);
void calc_num_let_spr(u8 param_1, u8 *param_2);
s32 calc_largmax_text(u8 *param_1, s32 param_2, s16 space_width, s16 param_4, u8 param_5);
void INIT_TXT_BOX(TextToDisplay *param_1);

#endif