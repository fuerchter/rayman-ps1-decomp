#include "loading_794DC.h"

/* matches, but s16 without return (see c89 3.6.6.4 The return statement) */
/*INCLUDE_ASM("asm/nonmatchings/loading_794DC", load_level);*/

s16 load_level(void)
{
    s16 temp_v0;
    s32 var_v0;

    PS1_Disable_all_Callbacks();
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
    PS1_LoadLevelObjBlock();
    PS1_LoadFondSprites();
    PS1_HasLoadedFont = false;
    D_801CEE9A = num_level;
    switch (num_world)
    {
    case 1:
        if (num_level >= 18)
            PS1_LoadFont();
        break;
    case 2:
        if (num_level >= 17)
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
    case 5:
        if (num_level >= 12)
            PS1_LoadFont();
        break;
    }
}

/* matches, but s16 without return (see c89 3.6.6.4 The return statement) */
/* 7A3C0 8019EBC0 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019ebc0);*/

s16 FUN_8019ebc0(void)
{
    if (PS1_ShouldClearPassword != false)
    {
        switch (Etape_History)
        {
        case 1:
            D_801F4380 = (void *)0x8005866C;
            PS1_PreFiles[0].dest = (void *)0x8005866C;
            PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 0, 1, 0);
            D_801F4380 += 0x19000;
            PS1_PreFiles[1].dest = D_801F4380;
            PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 1, 1, 0);
            D_801F4380 += 0x19000;
            PS1_PreFiles[2].dest = D_801F4380;
            PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 2, 1, 0);
            D_801F4380 += 0x19000;
            PS1_PreFiles[3].dest = D_801F4380;
            PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 3, 1, 0);
            D_801F4380 += 0x19000;
            PS1_PreFiles[4].dest = D_801F4380;
            PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 4, 1, 0);
            D_801F4380 = (void *)0x8005866C;
            plan2_width = 254;
            plan2_height = 180;
            D_801E4B58 = 0;
            D_801CF0CA = 0;
            return;
        case 2:
            D_801F4380 += 0x19000;
            plan2_width = 208;
            plan2_height = 180;
            D_801E4B58 = 0;
            D_801CF0CA = 0;
            break;
        case 3:
            D_801F4380 += 0x19000;
            plan2_width = 200;
            plan2_height = 200;
            D_801E4B58 = 0;
            D_801CF0CA = 0;
            break;
        case 4:
            D_801F4380 += 0x19000;
            plan2_width = 200;
            plan2_height = 180;
            D_801E4B58 = 0;
            D_801CF0CA = 0;
            break;
        case 5:
            D_801F4380 += 0x19000;
            plan2_width = 146;
            plan2_height = 150;
            D_801E4B58 = 0;
            D_801CF0CA = 0;
            break;
        }
    }
    else
    {
        D_801F4380 = (void *)0x8005866C;
        PS1_PreFiles[4].dest = (void *)0x8005866C;
        PS1_FileTemp = PS1_LoadFiles(PS1_PreFiles, 4, 1, 0);
        plan2_width = 146;
        plan2_height = 150;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
    }
}