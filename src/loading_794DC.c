#include "loading_794DC.h"

void PS1_LoadAllFixTextures(s32 length);
s32 PS1_LoadFiles(FileInfo *files, s32 fileIndex, s32 count, s32 a3);
void FUN_801393c8(s32 param_1);
void FUN_8013948c(s32 param_1);
void FUN_80139688(s32 tile_set_size);

extern s16 no_fnd;
extern u8 s_filefxs_801cf0d0[8];
extern s16 plan2_height;
extern s16 plan2_width;
extern AllFixData *PS1_AllFixData;

extern u8 D_801CF0CA;
extern u8 D_801E4B58;
extern u8 *D_801F4380;
extern void *D_801F4410;
extern void *D_801F5160;
extern void *D_801F7E90;
extern s32 D_80058674;
extern s32 D_80058678;
extern s32 D_8005867C;
extern s32 D_80058684;
extern s32 *D_801C4374[12]; /* just a guess for now */
extern s16 D_801CEE9A;
extern s16 D_801CEE9C;
extern s8 D_801CF0CC;
extern s8 D_801CF0CD;
extern void *D_801D7840;
extern void *D_801E5260;
extern void *D_801F59E0;
extern void *D_801F8190;

/*
before rodata even, what is this?
can write *(s32*)0x800D0004 instead of it e.g.
*/
extern s32 D_800D0004;
extern s32 D_80010004;
extern s32 D_80010008;
extern s32 D_8001000C;

const u8 s_img_file_8012c230[] = "img_file";
const u8 s_ldr_file_8012c23c[] = "ldr_file";
const u8 s_vdo_file_8012c248[] = "vdo_file";
const u8 s_trk_file_8012c254[] = "trk_file";
const u8 s_pre_file_8012c260[] = "pre_file";
const u8 s_crd_file_8012c26c[] = "crd_file";
const u8 s_gam_file_8012c278[] = "gam_file";
const u8 s_vig_wld_file_8012c284[] = "vig_wld_file";
const u8 s_wld_file_8012c294[] = "wld_file";
const u8 s_map_file0_8012c2a0[] = "map_file[0]";
const u8 s_fnd_file_8012c2ac[] = "fnd_file";
const u8 s_vab_file_8012c2b8[] = "vab_file";
const u8 s_big_file_8012c2c4[] = "big_file";
const u8 s_vab4sep_file_8012c2d0[] = "vab4sep_file";
const u8 s_ini_file_8012c2e0[] = "ini_file";

/* 794DC 8019DCDC -O2 -msoft-float */
void PS1_Init_ImgLdrVdoTrk_Files(void)
{
  PS1_FileTemp = PS1_InitFiles(PS1_ImgFiles, 3, s_img_file_8012c230);
  PS1_FileTemp = PS1_InitFiles(PS1_LdrFiles, 2, s_ldr_file_8012c23c);
  PS1_FileTemp = PS1_InitFiles(PS1_VdoFiles, 6, s_vdo_file_8012c248);
  PS1_FileTemp = PS1_InitFiles(PS1_TrkFiles, 53, s_trk_file_8012c254);
}

/* 79574 8019DD74 -O2 -msoft-float */
void FUN_8019dd74(void)
{
    PS1_InitFiles(PS1_PreFiles, 5, s_pre_file_8012c260);
    PS1_InitFiles(PS1_CrdFiles, 6, s_crd_file_8012c26c);
    PS1_InitFiles(PS1_GamFiles, 6, s_gam_file_8012c278);
    PS1_InitFiles(PS1_VigWldFiles, 6, s_vig_wld_file_8012c284);
    PS1_InitFiles(PS1_WldFiles, 6, s_wld_file_8012c294);
    PS1_InitFiles(PS1_MapFiles, 126, s_map_file0_8012c2a0);
    PS1_InitFiles(PS1_FndFiles, 31, s_fnd_file_8012c2ac);
    PS1_InitFiles(PS1_VabFiles, 7, s_vab_file_8012c2b8);
    PS1_InitFiles(PS1_BigFiles, 7, s_big_file_8012c2c4);
    PS1_InitFiles(PS1_Vab4sepFiles, 7, s_vab4sep_file_8012c2d0);
    PS1_InitFiles(PS1_FxsFiles, 2, s_filefxs_801cf0d0);
    PS1_InitFiles(PS1_IniFiles, 1, s_ini_file_8012c2e0);
}

/* 796AC 8019DEAC -O2 -msoft-float */
void FUN_8019deac(void)
{
    PS1_ImgFiles[0].dest = D_801F4380;
    PS1_FileTemp = PS1_LoadFiles(PS1_ImgFiles, 0, 1, 0);
    plan2_width = 320;
    plan2_height = 240;
    D_801E4B58 = 0;
    D_801CF0CA = 0;
}

/* 7971C 8019DF1C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019df1c);
#else
void FUN_8019df1c(s16 param_1)
{
    s32 index_1;
    s16 index_2;

    index_1 = param_1 - 1;
    PS1_VigWldFiles[index_1].dest = D_801F4380;
    PS1_FileTemp = PS1_LoadFiles(PS1_VigWldFiles, index_1, 1, 0);
    index_2 = param_1 - 1;
    switch (index_2)
    {
    case 0:
        plan2_width = 219;
        plan2_height = 180;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    case 1:
        plan2_width = 231;
        plan2_height = 214;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    case 2:
        plan2_width = 257;
        plan2_height = 180;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    case 3:
        plan2_width = 200;
        plan2_height = 180;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    case 4:
        plan2_width = 146;
        plan2_height = 180;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    case 5:
        plan2_width = 203;
        plan2_height = 180;
        D_801E4B58 = 0;
        D_801CF0CA = 0;
        break;
    }

    __asm__("nop\nnop");
}
#endif

/* 7981C 8019E01C -O2 -msoft-float */
void LOAD_BIG_RAYMAN(void)
{
    u8 *unk_1 = D_801F4380;
    PS1_FileTemp = PS1_LoadFiles(PS1_IniFiles, 0, 1, 0);
    D_801F4410 = (void *)0x800D0000;
    D_801F5160 = (void *)0x800D0000;
    D_801F7E90 = D_800D0004 + (void *)0x800D0000;
    FUN_80132424();
    D_801F4380 = D_801F4410 + *(((s32 *) D_801F5160) + 2);
    FUN_801393c8(*(((s32 *) D_801F5160) + 3) - *(((s32 *) D_801F5160) + 2));
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 3), 768, 490);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 4), 768, 491);
    DrawSync(0);
    D_801F4380 = unk_1;
}

/* 79918 8019E118 -O2 -msoft-float */
void LOAD_ALL_FIX(void)
{
    u8 *unk_1 = D_801F4380;
    PS1_FileTemp = PS1_LoadFiles(PS1_FxsFiles, 0, 1, 0);
    D_801F4410 = (void *)0x80010000;
    D_801F5160 = (void *)0x80010000;
    PS1_AllFixData = D_80010004 + (void *)0x80010000;
    D_801F4380 = D_80010008 + (void *)0x80010000;
    PS1_LoadAllFixTextures(D_8001000C - D_80010008);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 3), 768, 492);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 4), 768, 495);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 5), 768, 490);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 6), 768, 491);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 7), 768, 493);
    LoadClut(D_801F4410 + *(((s32 *) D_801F5160) + 8), 768, 494);
    DrawSync(0);
    D_801F4380 = unk_1;
    PS1_LoadAllFixSound();
}

INCLUDE_ASM("asm/nonmatchings/loading_794DC", load_world);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", load_level);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_FND);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", PS1_LoadImgWorld);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", PS1_LoadVideoTables);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", PS1_LoadFont);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_SCREEN);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019e914);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_CONTINUE_SCREEN);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", PS1_LoadImgSplash);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_SAVE_SCREEN);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019eb30);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019ebc0);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_CREDITS_VIGNET);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_VIGNET_GAME);
