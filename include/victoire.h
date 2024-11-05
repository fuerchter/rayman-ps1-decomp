#ifndef VICTOIRE_H
#define VICTOIRE_H

#include "common.h"
#include "draw/text_18118.h"

typedef struct Credit
{
    u8 *text;
    s16 x_pos;
    s16 y_pos;
    u8 font;
    u8 cmd;
    u8 color;
} Credit;

/* .data */
extern Credit credits[135]; /* only hint for this being 135 instead of 109 is empty space after it */

/**/
extern u8 You_Win;
extern u8 display_Vignet;
extern u8 first_credit;
extern u8 last_credit;
extern s16 nb_credits_lines;

void DISPLAY_TXT_CREDITS(void);
s16 display_credits_prg(void);
void DISPLAY_CREDITS(void);
void DISPLAY_PROTOON_BACK(void);
void DO_VICTOIRE(void);

#endif