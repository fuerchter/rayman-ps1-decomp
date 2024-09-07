#include "unknown/draw_548CC.h"

typedef struct Vec2 {
    s16 x;
    s16 y;
} Vec2;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 unk_0x3;
} Color;

extern Vec2 D_801E4E60[16];
extern Vec2 D_801E4EA8[16];

/* 548CC 801790CC -O2 -msoft-float */
void FUN_801790cc(Display *display)
{
    u16 i;
    u16 unk_2;
    u16 unk_1 = 0x100;
    
    for (i = 0; i < LEN(display->field5461_0x66dc); i++)
    {
        SetTile(display->field5461_0x66dc + i);
        (display->field5461_0x66dc + i)->r0 = 0;
        (display->field5461_0x66dc + i)->g0 = 0;
        (display->field5461_0x66dc + i)->b0 = 0;
    }

    i = 0;
    unk_2 = 0;
    while (i < LEN(D_801E4E60))
    {
        D_801E4E60[i].x = rcos(unk_2) * 45 >> 12;
        D_801E4E60[i].y = rsin(unk_2) * 45 >> 12;
        D_801E4EA8[i].x = (u32) rcos(unk_2) * 5 >> 8;
        D_801E4EA8[i].y = (u32) rsin(unk_2) * 5 >> 8;
        i++;
        unk_2 -= unk_1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", Display_and_free_luciole);

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", FUN_8017a6f8);

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", DISPLAY_FOND_MENU);

INCLUDE_ASM("asm/nonmatchings/unknown/draw_548CC", FUN_8017b260);
