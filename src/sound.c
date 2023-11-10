#include "sound.h"

extern s16 PS1_CurrentAudio;
extern s16 D_801CEFCC;
extern s16 PS1_AudioTable[14];
extern s32 PS1_FileTemp;
extern s16 PS1_AllFix_VabId1;
extern s16 PS1_AllFix_VabId2;
extern s16 PS1_AllFix_SepAcc;
extern s32 D_801D8B50;
extern s32 D_801D8B54;
extern s32 D_801D8B58;
extern s32 D_801D8B5C;
extern s16 D_801CEFDC;
extern s16 D_801C7C78;
extern FileInfo PS1_VabFiles[7];
extern FileInfo PS1_BigFiles[7];
extern FileInfo PS1_Vab4sepFiles[7];
extern s16 PS1_World_VabId1;
extern s16 PS1_World_VabId2;
extern s16 PS1_World_SepAcc;

extern s32 *D_801D7840;
extern s16 PS1_SepVols[25];
extern SepInfo PS1_SepInfos[25];
/*extern s16 *D_801C7CBE;*/
extern s16 D_801F7C80;

/* 41084 80165884 -O2 -msoft-float */
void PS1_StopPlayingAllSnd(void)
{
  PS1_StopPlayingSnd(PS1_CurrentAudio);
  PS1_CurrentAudio = 25;
  PS1_StopPlayingSnd(21);
  PS1_StopPlayingSnd(12);
  PS1_StopPlayingSnd(22);
  D_801CEFCC = 0;
  PS1_StopPlayingSnd(6);
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_801658e0);

/* 41190 80165990 -O2 -msoft-float */
void manage_snd_event(Obj *obj)
{
    u8 hp = obj->hit_points;

    if (hp == 0)
    {
        PS1_StopPlayingSnd(PS1_CurrentAudio);
        PS1_CurrentAudio = 0;
    }
    else if (PS1_AudioTable[hp] != PS1_CurrentAudio)
    {
        PS1_StopPlayingSnd(PS1_CurrentAudio);
        PS1_PlaySnd(PS1_AudioTable[hp], 0);
        PS1_CurrentAudio = PS1_AudioTable[hp];
    }
}

/*
PS1_LoadAllFixSound:
    D_801C6E6C: loads the _contents_ of CdlLOC pos in a3
    D_801C6E70: saves file.size, file.name on stack?
FUN_80133498:
    PS1_LoadFiles call with FileInfo*
    SsVabTransBody call with dest, stack value past FileInfo? (zero)
*/

INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadAllFixSound);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadWorldSound);

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/sound", PS1_PlaySnd);
#else
void PS1_PlaySnd(s16 sep_ind, s16 l_count)
{
  s16 vol = D_801F7C80 * PS1_SepVols[sep_ind] >> 7;

  SsSepSetVol(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num, vol, vol);
  SsSeqCalledTbyT();
  SsSepPlay(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num, SSPLAY_PLAY, l_count);

  __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/sound", PS1_StopPlayingSnd);
#else
void PS1_StopPlayingSnd(s16 sep_ind)
{
  if (sep_ind != 25)
    SsSepStop(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num);

  __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/sound", PS1_SongIsPlaying);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166018);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166060);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_801660ac);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_801660e8);

INCLUDE_ASM("asm/nonmatchings/sound", stop_all_snd);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_8016617c);

INCLUDE_ASM("asm/nonmatchings/sound", get_pan_snd);

INCLUDE_ASM("asm/nonmatchings/sound", get_vol_snd);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_SetSoundVolume);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_SetStereoEnabled);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_801663d4);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166578);

INCLUDE_ASM("asm/nonmatchings/sound", last_snd);

INCLUDE_ASM("asm/nonmatchings/sound", get_pile_obj);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166724);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166790);

INCLUDE_ASM("asm/nonmatchings/sound", get_voice_obj_snd);

INCLUDE_ASM("asm/nonmatchings/sound", erase_pile_snd);

INCLUDE_ASM("asm/nonmatchings/sound", nettoie_pile_snd);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d20);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d88);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166e1c);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166e58);

INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd);

INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd_old);

INCLUDE_ASM("asm/nonmatchings/sound", setvol);

INCLUDE_ASM("asm/nonmatchings/sound", setpan);

void FUN_80168f38(s16 sep_ind) {
}

void FUN_80168f40(void) {
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80169194);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_8016924c);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_OnPauseOn);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_OnPauseOff);

INCLUDE_RODATA("asm/nonmatchings/sound", D_8012AB94);
