#include "loading_794DC.h"

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

void PS1_Init_ImgLdrVdoTrk_Files(void)
{
  PS1_FileTemp = PS1_InitFiles(PS1_ImgFiles, 3, s_img_file_8012c230);
  PS1_FileTemp = PS1_InitFiles(PS1_LdrFiles, 2, s_ldr_file_8012c23c);
  PS1_FileTemp = PS1_InitFiles(PS1_VdoFiles, 6, s_vdo_file_8012c248);
  PS1_FileTemp = PS1_InitFiles(PS1_TrkFiles, 53, s_trk_file_8012c254);
}

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019dd74);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019deac);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", FUN_8019df1c);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_BIG_RAYMAN);

INCLUDE_ASM("asm/nonmatchings/loading_794DC", LOAD_ALL_FIX);

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
