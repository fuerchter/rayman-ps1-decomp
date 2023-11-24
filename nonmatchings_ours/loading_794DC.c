#include "loading_794DC.h"

/* stack */
/* 79A98 8019E298 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/loading_794DC", load_world);*/

void load_world(s16 worldIndex)
{
    FUN_80133018();
    PS1_FileTemp = PS1_LoadFiles(PS1_VigWldFiles + worldIndex + 5, 0, 1, 0);
    D_801F4410 = (void *)0x8005866C;
    D_801F5160 = (void *)0x8005866C;
    D_801D7840 = D_80058674 + (void *)0x8005866C;
    D_801F4380 = D_80058678 + (void *)0x8005866C;
    D_801F8190 = D_80058684 + (void *)0x8005866C;
    FUN_8013948c(D_8005867C - D_80058678);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 4), 0x00000300, 0x000001EA);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 5), 0x00000300, 0x000001EB);
    FUN_80139688(*(((s32 *) D_801F5160) + 7) - *(((s32 *) D_801F5160) + 6));
    D_801CF0CC = 0;
    D_801CF0CD = 0;
    FUN_80132304(D_801F4410 + *(((s32 *) D_801F5160) + 7), (u8) ((u32) (*((s32 *) D_801F5160 + 8) - *(((s32 *) D_801F5160) + 7)) >> 9));
    FUN_8013234c(D_801F4410 + *(((s32 *) D_801F5160) + 8));
    D_801CEE9C = worldIndex;
    D_801CEE9A = 0;
    no_fnd = -1;
    D_801E5260 = D_801C4374[worldIndex + 5];
    D_801F59E0 = D_801C4374[worldIndex - 1];
    PS1_LoadWorldSound(worldIndex);
}