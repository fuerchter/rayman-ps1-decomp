#include "loading_tex.h"

extern u8 *D_801F4380;
extern s32 D_801E4D30;
extern s16 D_801E5930;
extern s16 D_801E63D0;
extern s32 D_801E4D28;
extern s16 D_801E5928;
extern s16 D_801E63C8;

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_801392d8);

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_80139330);

/* 14BC8 801393C8 -O2 -msoft-float */
void FUN_801393c8(s32 param_1)
{
    s16 start_pos = 6;
    s16 end_pos = 0;

    FUN_801392d8(param_1 + 0x50000, &start_pos, &end_pos);
    PS1_LoadVRAMBlock(6, start_pos, 0, end_pos, 0, D_801F4380);
}

/* 14C24 80139424 -O2 -msoft-float */
void PS1_LoadAllFixTextures(s32 length)
{
    D_801E4D30 = length + 0x400;
    FUN_801392d8(D_801E4D30, &D_801E5930, &D_801E63D0);
    PS1_LoadVRAMBlock(0, D_801E5930, 8, D_801E63D0, 0, D_801F4380);
}

/* 14C8C 8013948C -O2 -msoft-float */
void FUN_8013948c(s32 param_1)
{
    D_801E4D28 = param_1 + D_801E4D30;
    FUN_801392d8(D_801E4D28, &D_801E5928, &D_801E63C8);
    if (param_1 != 0)
        PS1_LoadVRAMBlock(D_801E5930, D_801E5928, D_801E63D0, D_801E63C8, 0, D_801F4380);
}

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_80139514);

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_801395a8);

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_80139624);

INCLUDE_ASM("asm/nonmatchings/loading_tex", FUN_80139688);
