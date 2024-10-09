#include "draw/draw_hud.h"
#include "rayconst.h"

/* matches, but do{}while(0); */
/* 1A04C 8013E84C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/draw/draw_hud", DisplayJumellesNormal);*/

void DisplayJumellesNormal(void)
{
    s32 x_3;
    s32 x_5;
    s16 y_4;
    s32 y_1;
    s32 y_2;
    s32 y_3;
    s32 x_6;
    s32 x_4;
    s32 w_1;
    s32 w_h;
    s32 x_2;
    Sprite *sprite;
    s32 x_1;
    s32 width_2;
    s32 height_1;
    s32 width_1;
    s16 height_2;
    Sprite *sprites;

    sprites = mapobj[24].sprites;
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[9];
    sprite = &sprites[1];
    
    height_1 = sprite->height;
    width_1 = sprite->width;
    do {
        x_4 = 160 - width_1 * 2;
        PS1_DrawColoredSprite(sprite, x_4, 53, 1);
    } while (0);
    x_3 = x_4 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 0);
    x_3 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 1);
    x_3 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 0);
    x_1 = (x_4 - height_1) + 5;
    x_3 += sprite->width;
    y_1 = height_1 + 48;
    PS1_DrawColoredSprite(sprite, x_1, y_1, 4);
    PS1_DrawColoredSprite(sprite, x_1, sprite->width + y_1, 6);
    x_2 = x_3 - 5;
    PS1_DrawColoredSprite(sprite, x_2, y_1, 7);
    y_2 = y_1 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_2, y_2, 5);
    w_h = height_1 - 5;
    DISPLAY_BLACKBOX(x_1, 53, w_h, w_h, 0, 0);
    DISPLAY_BLACKBOX(x_3, 53, w_h, w_h, 0, 0);
    y_2 += sprite->width;
    DISPLAY_BLACKBOX(x_1, y_2, w_h, w_h, 0, 0);
    DISPLAY_BLACKBOX(x_3, y_2, w_h, w_h, 0, 0);
    y_3 = y_2 - 5;
    PS1_DrawColoredSprite(sprite, x_4, y_3, 3);
    x_5 = x_4 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 2);
    x_5 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 3);
    PS1_DrawColoredSprite(sprite, sprite->width + x_5, y_3, 2);
    
    height_2 = sprite->height;
    w_1 = x_4 - height_2;
    width_2 = sprite->width;
    x_6 = w_1 + (height_2 + width_2 * 2) * 2;
    y_4 = (width_2 + height_2) * 2 + 53;
    DISPLAY_BLACKBOX(0, 0, SCREEN_WIDTH, 53, 0, 0);
    DISPLAY_BLACKBOX(0, y_4 - 10, SCREEN_WIDTH, 250 - y_4, 0, 0);
    DISPLAY_BLACKBOX(0, 53, w_1 + 5, y_4 - 58, 0, 0);
    DISPLAY_BLACKBOX(x_6 - 5, 53, x_6 - w_1, y_4 - 58, 0, 0);
}