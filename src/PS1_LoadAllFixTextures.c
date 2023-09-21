#include "common.h"

extern s32 D_801E4D30;
extern s16 D_801E5930;
extern s16 D_801E63D0;
extern s32 D_801F4380;

/* 14C24 80139424 */
void PS1_LoadAllFixTextures(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 + 0x400;
    D_801E4D30 = temp_a0;
    FUN_801392d8(temp_a0, &D_801E5930, &D_801E63D0);
    PS1_LoadVRAMBlock(0, D_801E5930, 8, D_801E63D0, 0, D_801F4380);
}