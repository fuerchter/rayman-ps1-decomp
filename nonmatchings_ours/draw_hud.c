#include "draw_hud.h"

/* matches, but do{}while(0); */
/* 1A04C 8013E84C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DisplayJumellesNormal);*/

/*? DISPLAY_BLACKBOX(s32, s32, s32, s32, s32, s32);
? FUN_801397f4(s32, s32, s32, ?);*/
extern s32 PS1_PrevPrim;
extern Obj *mapobj;

void DisplayJumellesNormal(void)
{
    s32 x_3;
    s32 x_5;
    s16 temp_s0_8;
    s32 temp_s0_9;
    s32 y_1;
    s32 y_2;
    s32 y_3;
    s32 temp_s1_5;
    s32 x_4;
    s32 temp_s3_2;
    s32 size;
    s32 x_2;
    Sprite *sprite;
    s32 x_1;
    u8 width_1;
    s32 height_1;
    u8 width;
    s16 height_2;
    Sprite *sprites;
    s32 new_var;

    sprites = mapobj[24].sprites;
    PS1_PrevPrim = PS1_CurrentDisplay + 0x814;

    sprite = &sprites[1];
    height_1 = sprite->height;
    do {
        x_4 = 0xa0 - (sprite->width * 2);
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
    y_1 = height_1 + 0x30;
    PS1_DrawColoredSprite(sprite, x_1, y_1, 4);
    PS1_DrawColoredSprite(sprite, x_1, sprite->width + y_1, 6);
    x_2 = x_3 - 5;
    PS1_DrawColoredSprite(sprite, x_2, y_1, 7);
    y_2 = y_1 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_2, y_2, 5);
    size = height_1 - 5;
    DISPLAY_BLACKBOX(x_1, 53, size, size, 0, 0);
    DISPLAY_BLACKBOX(x_3, 53, size, size, 0, 0);
    y_2 += sprite->width;
    DISPLAY_BLACKBOX(x_1, y_2, size, size, 0, 0);
    DISPLAY_BLACKBOX(x_3, y_2, size, size, 0, 0);
    y_3 = y_2 - 5;
    PS1_DrawColoredSprite(sprite, x_4, y_3, 3);
    x_5 = x_4 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 2);
    x_5 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 3);
    PS1_DrawColoredSprite(sprite, sprite->width + x_5, y_3, 2);
    
    height_2 = sprite->height;
    width_1 = sprite->width;
    temp_s0_8 = x_4 - height_2;
    temp_s3_2 = temp_s0_8;
    temp_s1_5 = temp_s3_2 + ((height_2 + (width_1 * 2)) * 2);
    temp_s0_8 = ((width_1 + height_2) * 2) + 53;
    DISPLAY_BLACKBOX(0, 0, 0x140, 53, 0, 0);
    DISPLAY_BLACKBOX(0, temp_s0_8 - 0xA, 0x140, 0xFA - temp_s0_8, 0, 0);
    temp_s0_9 = temp_s0_8 - 0x3A;
    DISPLAY_BLACKBOX(0, 53, temp_s3_2 + 5, temp_s0_9, 0, 0);
    DISPLAY_BLACKBOX(temp_s1_5 - 5, 53, temp_s1_5 - temp_s3_2, temp_s0_9, 0, 0);
}