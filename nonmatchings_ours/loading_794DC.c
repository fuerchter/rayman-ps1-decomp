#include "loading_794DC.h"

/* would match, if return set to s16... */
/*INCLUDE_ASM("asm/nonmatchings/loading_794DC", load_level);*/

void load_level(void)
{
    s16 temp_v0;
    s32 var_v0;

    FUN_80133018();
    D_801F4410 = D_801F59E0;
    D_801F5160 = D_801F59E0;
    PS1_FileTemp = PS1_LoadFiles(&PS1_MapFiles[num_world * 21 - 21], num_level - 1, 1, 0);
    PS1_LevelBGBlock = D_801F4410 + *(((s32 *) D_801F5160) + 1);
    PS1_LevelObjBlock = D_801F4410 + *(((s32 *) D_801F5160) + 2);
    PS1_LevelMapBlock = D_801F4410 + *(((s32 *) D_801F5160) + 3);
    D_801F4380 = D_801F4410 + *(((s32 *) D_801F5160) + 4);
    if (
        (num_world == 4 && (num_level == 11 || num_level == 4)) ||
        (num_world == 6 && num_level == 4)
    )
        FUN_801395a8(*(((s32 *) D_801F5160) + 5) - *(((s32 *) D_801F5160) + 4));
    else
        FUN_80139514(*(((s32 *) D_801F5160) + 5) - *(((s32 *) D_801F5160) + 4));
    PS1_LoadLevelMapBlock(&mp);
    PS1_LoadLevelEventBlock();
    PS1_LoadFondSprites();
    PS1_HasLoadedFont = false;
    D_801CEE9A = num_level;
    temp_v0 = num_world - 1;
    switch (temp_v0)
    {
    case 0:
        if (num_level >= 18)
            PS1_LoadFont();
        break;
    case 1:
        if (num_level >= 17)
            PS1_LoadFont();
        break;
    case 2:
        if (num_level >= 12)
            PS1_LoadFont();
        break;
    case 3:
        if (num_level >= 12)
            PS1_LoadFont();
        break;
    case 4:
        if (num_level >= 12)
            PS1_LoadFont();
        break;
    }
}