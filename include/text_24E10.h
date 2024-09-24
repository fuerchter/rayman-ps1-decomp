#ifndef TEXT_24E10_H
#define TEXT_24E10_H

#include "common.h"
/*#include "draw/text_18118.h"*/ /* circular! */

typedef struct TextToDisplay
{
    u8 text[48];
    s16 centered_x_pos;
    s16 centered_y_pos;
    s16 width;
    s16 height;
    s16 x_pos;
    s16 y_pos;
    u8 font_size;
    u8 field8_0x3d;
    u8 is_fond;
    u8 color;
} TextToDisplay;

/**/
extern TextToDisplay text_to_display[10];

void INIT_TEXT_TO_DISPLAY(void);
u8 deter_num_let(u8 param_1);
void calc_num_let_spr(u8 param_1, u8 *param_2);
s32 calc_largmax_text(u8 *param_1, s32 param_2, s16 space_width, s16 param_4, u8 param_5);
void INIT_TXT_BOX(TextToDisplay *param_1);

#endif