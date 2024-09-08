#ifndef TEXT_18118_H
#define TEXT_18118_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "text_24E10.h"
#include "draw.h"

typedef struct MenuText {
    u8 *header;
    u8 *rows[6];
    RECT vignette_rect;
    s32 vignette;
    s32 music;
    u8 rows_count;
    u8 selected_row;
    u8 color;
    /*u8 unk_1;*/ /* packed? */
} MenuText;

/* .data */
extern u8 D_801CEE10;
extern u8 let_shadow;

/**/
extern u8 colour;
extern s16 D_801F81B0;

u8 PS1_deter_num_let_old(s32 param_1);
s16 PS1_calc_let_Width(s16 sprite, u8 font);
s32 calc_let_Width(u8 param_1, s16 param_2);
s16 PS1_CalcTextWidth(u8 *str, u8 font);
void PS1_DisplayCenteredText(u8 *str, u8 param_2, u8 color);
void PS1_DisplayMultipleCenteredText(u8 index, MenuText *in_menus); /* unused */
void DrawFondBoxNormal(s16 x, s16 y, s16 w, s16 h, u8 brightness);
void DrawBlackBoxNormal(s16 x, s16 y, s16 w, s16 h, u8 brightness);
void DISPLAY_BLACKBOX(u16 x, u16 y, u16 w, u16 h, u8 param_5, u8 is_fond);
void display_text_sin(u8 *param_1, u16 param_2, s16 param_3, s16 param_4, u8 param_5, u8 param_6);
void display_text(u8 *text, s16 x_pos, s16 y_pos, u8 font_size, u32 param_5);
void display_box_text(TextToDisplay *txt);

#endif