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

extern u8 You_Win;

#endif