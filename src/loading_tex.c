#include "loading_tex.h"

extern u8 *D_801F4380;

/* see fond_10B3C */
extern u16 D_801F5440;
extern u16 D_801F55D8;

extern void *D_801F8190; /* see loading_794DC */

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

/* 14D14 80139514 -O2 -msoft-float */
void FUN_80139514(s32 param_1)
{
    D_801E4D78 = param_1 + D_801E4D28;
    FUN_801392d8(D_801E4D78, &D_801E5A08, &D_801E6410);
    PS1_LoadVRAMBlock(D_801E5928, D_801E5A08, D_801E63C8, D_801E6410, D_801C4468[num_world - 1], D_801F4380);
}

/* 14DA8 801395A8 -O2 -msoft-float */
void FUN_801395a8(s32 param_1)
{
    D_801E4D78 = param_1 + D_801E4D28;
    FUN_80139330(D_801E4D78, &D_801E5A08, &D_801E6410);
    PS1_LoadVRAMBlock(D_801E5928, D_801E5A08, D_801E63C8, D_801E6410, 256, D_801F4380);
}

/* 14E24 80139624 -O2 -msoft-float */
void FUN_80139624(s32 param_1)
{
    s16 start_pos = 7;
    s16 end_pos = 80;
    
    FUN_801392d8(param_1 + 0x65000, &start_pos, &end_pos);
    PS1_LoadVRAMBlock(7, start_pos, 80, end_pos, 0, D_801F4380);
}

/* 14E88 80139688 -O2 -msoft-float */
void FUN_80139688(s32 tile_set_size)
{
    s32 unk_1 = 15;
    
    FUN_801392d8(0xAC000 - tile_set_size, &D_801F5440, &D_801F55D8);
    if (D_801F5440 < 8)
    {
        D_801F5440 = 8;
        D_801F55D8 = 0;
    }
    else if (D_801F55D8 & unk_1)
    {
        D_801F55D8 = (D_801F55D8 + 15) & 65520;
        if (D_801F55D8 >= 256)
        {
            D_801F55D8 = 0;
            D_801F5440++;
        }

        if (D_801F5440 == 9 && (D_801F55D8 > 224))
        {
            D_801F5440++;
            D_801F55D8 = (D_801F55D8 + 32) & 240;
        }
    }
    D_801E5558 = 11;
    D_801E59B8 = 224;
    PS1_LoadVRAMBlock(D_801F5440, 11, D_801F55D8, 224, 0, D_801F8190);
}
