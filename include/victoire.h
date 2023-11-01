#ifndef VICTOIRE_H
#define VICTOIRE_H

#include "common.h"

typedef struct Credit
{
    u8 * text;
    s16 x_pos;
    s16 y_pos;
    u8 font;
    u8 cmd;
    u8 color;
} Credit;

/* .data */
extern Credit credits[109];

/**/
extern u8 You_Win;
extern u8 display_Vignet;
extern u8 first_credit;
extern u8 last_credit;
extern s16 nb_credits_lines;

#endif