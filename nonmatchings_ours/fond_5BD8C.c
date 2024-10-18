#include "fond_5BD8C.h"

/*
score of ???
strange diff to target. functionally the same though
*/
/*INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_8018058c);*/

void FUN_8018058c(u32 *param_1, s32 param_2, s32 param_3, s16 x, s16 y, s16 h, s16 w)
{
    RECT sp10;
    RECT sp18;
    RECT sp20;
    RECT sp28;
    RECT sp30;

    sp10.x = x;
    sp10.y = y;
    sp10.w = w;
    sp10.h = h;
    if (w == 0) {
        w = 0x140;
    }
    if (h == 0) {
        h = 0xf0;
    }
    sp10.x = (PS1_CurrentDisplay->drawing_environment).clip.x + x;
    sp10.y = (PS1_CurrentDisplay->drawing_environment).clip.y + y;
    sp10.w = w;
    sp10.h = h;
    LoadImage(&sp10,param_1);
    sp18.x = 0;
    sp18.y = (PS1_CurrentDisplay->drawing_environment).clip.y;
    sp18.w = 0x140;
    sp18.h = y;
    if (sp18.h != 0) {
        ClearImage(&sp18,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp20.x = 0;
    sp20.y = (PS1_CurrentDisplay->drawing_environment).clip.y + y + h;
    sp20.w = 0x140;
    sp20.h = (0xf0 - y) - h;
    if (sp20.h != 0) {
        ClearImage(&sp20,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp28.x = 0;
    sp28.y = (PS1_CurrentDisplay->drawing_environment).clip.y + y;
    sp28.w = x;
    sp28.h = h;
    if (sp28.w != 0) {
        ClearImage(&sp28,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp30.x = x + w;
    sp30.y = (PS1_CurrentDisplay->drawing_environment).clip.y + y;
    sp30.w = (0x140 - x) - w;
    sp30.h = h;
    if (sp30.w != 0) {
        ClearImage(&sp30,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
}

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/fond_5BD8C", FUN_80180804);*/

void FUN_80180804(u32 *param_1, s32 param_2, s32 param_3, s16 x, s16 y, s16 h, s16 w)
{
    RECT sp10;
    RECT sp18;
    RECT sp20;
    RECT sp28;
    RECT sp30;

    sp10.x = x;
    sp10.y = y;
    sp10.w = w;
    sp10.h = h;
    if (w == 0) {
        w = 0x280;
    }
    if (h == 0) {
        h = 0x1e0;
    }
    sp10.x = x + (PS1_CurrentDisplay->drawing_environment).clip.x;
    sp10.y = y + (PS1_CurrentDisplay->drawing_environment).clip.y;
    sp10.w = w;
    sp10.h = h;
    LoadImage(&sp10,param_1);
    sp18.x = 0;
    sp18.y = (PS1_CurrentDisplay->drawing_environment).clip.y;
    sp18.w = 0x280;
    sp18.h = y;
    if (y != 0) {
        ClearImage(&sp18,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp20.x = 0;
    sp20.y = (PS1_CurrentDisplay->drawing_environment).clip.y + y + h;
    sp20.w = 0x280;
    sp20.h = (0x1e0 - y) - h;
    if (sp20.h != 0) {
        ClearImage(&sp20,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp28.x = 0;
    sp28.y = y + (PS1_CurrentDisplay->drawing_environment).clip.y;
    sp28.w = x;
    sp28.h = h;
    if (x != 0) {
        ClearImage(&sp28,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    sp30.x = x + w;
    sp30.y = y + (PS1_CurrentDisplay->drawing_environment).clip.y;
    sp30.w = (0x280 - x) - w;
    sp30.h = h;
    if (sp30.w != 0) {
        ClearImage(&sp30,D_801CF0CA,D_801CF0CA,D_801CF0CA);
    }
    return;
}