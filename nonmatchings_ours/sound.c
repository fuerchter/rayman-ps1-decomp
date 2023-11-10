#include "sound.h"

/* functionally the same as far as i can tell */
/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_801658e0);*/

/* 410E0 801658E0 -O2 -msoft-float */
void FUN_801658e0(void)
{
    s16 temp_v0;
    s16 var_s1;
    s16 var_s3;
    s16 var_v0;

    D_801CEFCC = 0;
    var_s3 = 0;
    do
    {
        var_s1 = 0;
        do {
            if ((SsIsEos(var_s3, var_s1)) != 0)
            {
                SsSepStop(var_s3, var_s1);
            }
            var_s1 = var_s1 + 1;
        } while (var_s1 < 0xA);
        var_s3 = var_s3 + 1;
    } while (var_s3 < 2);
}

/* matches, but clean up/figure out unknowns */
/*INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadAllFixSound);*/

/* 41224 80165A24 -O2 -msoft-float */
s32 FUN_80133498(FileInfo param_1, s16 param_2, u8 *param_3);
s32 PS1_LoadFiles(FileInfo *files,s32 fileIndex,s32 count, s32 a3);

void PS1_LoadAllFixSound(void)
{
  s32 *new_var;

  if (D_801CEFDC == 0)
  {
    SsUtReverbOff();
    PS1_BigFiles[0].dest = (u8 *)&D_801D8B50;
    new_var = &D_801D8B50;
    PS1_FileTemp = PS1_LoadFiles(PS1_BigFiles,0,1, 0);
    if (*new_var == 3)
    {
      PS1_AllFix_VabId1 = 0;
      PS1_AllFix_VabId1 = SsVabOpenHead((u8 *)((int)&D_801D8B50 + D_801D8B54), 0);
      if (PS1_AllFix_VabId1 != -1)
        PS1_FileTemp = FUN_80133498(PS1_VabFiles[0], PS1_AllFix_VabId1, 0);
      PS1_AllFix_VabId2 = 2;
      PS1_AllFix_VabId2 = SsVabOpenHead((u8 *)((int)&D_801D8B50 + D_801D8B58), 2);
      if (PS1_AllFix_VabId2 != -1)
        PS1_FileTemp = FUN_80133498(PS1_Vab4sepFiles[0], PS1_AllFix_VabId2, 0);
      PS1_AllFix_SepAcc = 0;
      if (PS1_AllFix_VabId2 != -1)
        PS1_AllFix_SepAcc = SsSepOpen((u8 *)((int)&D_801D8B50 + D_801D8B5C), PS1_AllFix_VabId2, D_801C7C78);
    }
    SsUtReverbOn();
    LOAD_CONFIG();
    PS1_SetSoundVolume(options_jeu.Soundfx);
    PS1_SetStereoEnabled(options_jeu.StereoEnabled);
    PS1_SetMusicVolume(options_jeu.Music);
    D_801CEFDC = 1;
  }
}

/* matches, but clean up/figure out unknowns */
/*INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadWorldSound);*/

/* 4145C 80165C5C -O2 -msoft-float */
s32 FUN_80133498(FileInfo param_1, s16 param_2, u8 *param_3);

void PS1_LoadWorldSound(s16 param_1)
{
  int *piVar1;
  int new_var;
  
  stop_all_snd();
  PS1_SetStereoEnabled(options_jeu.StereoEnabled);
  FUN_80166060(options_jeu.Soundfx * 127 / 20);
  piVar1 = D_801D7840;
  if (*piVar1 != 0)
  {
    PS1_World_VabId1 = 1;
    SsVabClose(PS1_World_VabId1);
    PS1_World_VabId2 = 3;
    SsVabClose(PS1_World_VabId2);
    PS1_World_VabId1 = SsVabOpenHead((int)piVar1 + piVar1[1], PS1_World_VabId1);
    if (PS1_World_VabId1 != -1)
      PS1_FileTemp = FUN_80133498(PS1_VabFiles[param_1], PS1_World_VabId1, 0);
    PS1_World_VabId2 = SsVabOpenHead((int)piVar1 + piVar1[2], PS1_World_VabId2);
    if (PS1_World_VabId2 != -1)
      PS1_FileTemp = FUN_80133498(PS1_Vab4sepFiles[param_1], PS1_World_VabId2, 0);
    PS1_World_SepAcc = 1;
    SsSepClose(PS1_World_SepAcc);
    PS1_World_SepAcc = SsSepOpen(
        (int)piVar1 + piVar1[3],
        PS1_World_VabId2,
        *(s16 *)((int)&D_801C7C78 + param_1 * 2)
    );
  }
}

/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_8016617c);*/

/* 4197C 8016617C -O2 -msoft-float */
void FUN_8016617c(void)
{
  s16 i;
  short sVar1;
  
  for (i = 0; i < 24; i++)
  {
    sVar1 = voice_table[i].field3_0x6; /* TODO: this is being read as s16 instead */
    if (sVar1 == 6 || sVar1 == 0xf5 || sVar1 == 2)
      SsUtSetVVol(i, 0, 0);
  }
}