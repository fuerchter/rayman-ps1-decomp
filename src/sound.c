#include "sound.h"

extern s16 PS1_CurrentAudio;
extern s16 PS1_AudioTable[14];
extern s32 PS1_FileTemp;
extern s16 PS1_AllFix_VabId1;
extern s16 PS1_AllFix_VabId2;
extern s16 PS1_AllFix_SepAcc;
extern FileInfo PS1_VabFiles[7];
extern FileInfo PS1_BigFiles[7];
extern FileInfo PS1_Vab4sepFiles[7];
extern s16 PS1_World_VabId1;
extern s16 PS1_World_VabId2;
extern s16 PS1_World_SepAcc;
extern s16 PS1_SoundVolume;
extern u8 voice_is_working[24];
extern s16 indice_ray_wait;
extern s16 stk_obj[20];
extern s16 stk_snd[20];
extern u8 snd_sqrt_table[128];

extern VoiceTableEntry voice_table[24];
extern u8 D_801F6850;
extern s16 D_801CEFCC;
extern s32 D_801D8B50;
extern s32 D_801D8B54;
extern s32 D_801D8B58;
extern s32 D_801D8B5C;
extern s16 D_801CEFDC;
extern s16 D_801C7C78;
extern s32 *D_801D7840;
extern s16 PS1_SepVols[25];
extern SepInfo PS1_SepInfos[25];
/*extern s16 *D_801C7CBE;*/
extern s16 D_801F7C80;
extern s16 indice_trz_wait;
extern s16 pt_pile_snd;
extern u8 D_801F7D41;
extern u8 D_801F7D42;
extern u8 D_801F7D43;
extern s16 D_801FA578;
/* structs unclear, number of elements unclear*/
extern u8 D_801CEFD0[8];
extern Unk_801f7d40 D_801F7D40[8];
extern Unk_801f62a0 pile_snd[10];

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

INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadAllFixSound);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadWorldSound);

/* 416B4 80165EB4 -O2 -msoft-float */
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

/* 41778 80165F78 -O2 -msoft-float */
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

/* 417CC 80165FCC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/sound", PS1_SongIsPlaying);
#else
s16 PS1_SongIsPlaying(s16 sep_ind)
{
  __asm__("nop\nnop");
  return SsIsEos(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num);
}
#endif

/* 41818 80166018 -O2 -msoft-float */
void FUN_80166018(void)
{
  SsSetTableSize(&D_801F6850, 2, 10);
  SsSetTickMode(SS_TICK120);
  SsStart();
  SsSetMVol(127, 127);
}

/* 41860 80166060 -O2 -msoft-float */
void SetVolumeSound(s16 vol)
{
  SsSetSerialAttr(SS_SERIAL_B, SS_MIX, SS_SON);
  SsSetSerialVol(SS_SERIAL_B, vol, vol);
  PS1_SoundVolume = vol;
}

/* 418AC 801660AC -O2 -msoft-float */
void FUN_801660ac(void)
{
  CdlATV vol;
  
  vol.val0 = 128;
  vol.val1 = 0;
  vol.val2 = 128;
  vol.val3 = 0;
  CdMix(&vol);
  SsSetStereo();
}

/* 418E8 801660E8 -O2 -msoft-float */
void FUN_801660e8(void)
{
  CdlATV vol;
  
  SsSetMono();
  vol.val0 = 90;
  vol.val1 = 90;
  vol.val2 = 90;
  vol.val3 = 90;
  CdMix(&vol);
}

/* 41924 80166124 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/sound", stop_all_snd);
#else
void stop_all_snd(void)
{
  s16 i;

  __asm__("nop");
  SsUtAllKeyOff(0);
  for (i = 0; i < 24; i++)
    voice_is_working[i] = false;
}
#endif

INCLUDE_ASM("asm/nonmatchings/sound", FUN_8016617c);

/* 41A0C 8016620C -O2 -msoft-float */
u8 get_pan_snd(Obj *obj)
{
  s16 screen_x;
  s16 res;
  
  screen_x = obj->offset_bx + obj->screen_x_pos;
  if (screen_x < -96)
    res = 0;
  else if (screen_x >= 417)
    res = 127;
  else
    res = (screen_x + 96U) / 4;

  if (res > 127)
    res = 127;
  return res;
}

/* 41A6C 8016626C -O2 -msoft-float */
u8 get_vol_snd(Obj *obj)
{
  s16 x, y, w, h;
  s32 diff_x, diff_y;
  s32 unk_1;
  s16 res;
  
  GET_ANIM_POS(obj, &x, &y, &w, &h);
  diff_x = (x + (w >> 1)) - (ray.x_pos + ray.offset_bx);
  diff_x = __builtin_abs(diff_x);
  unk_1 = 40;
  diff_y = (y + (h >> 1) + unk_1) - (ray.y_pos + ray.offset_by);
  diff_y = __builtin_abs(diff_y);
  res = 127 - ((s16)diff_x + (s16)diff_y >> 2);

  if (res < 0)
    res = 0;
  return res;
}

/* 41B3C 8016633C -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/sound", PS1_SetSoundVolume);
#else
void PS1_SetSoundVolume(s16 vol)
{
  SetVolumeSound(vol * 127 / 20);
}
#endif

/* 41B9C 8016639C -O2 -msoft-float */
void PS1_SetStereoEnabled(s16 enabled)
{
  if (enabled)
    FUN_801660ac();
  else
    FUN_801660e8();
}

INCLUDE_ASM("asm/nonmatchings/sound", InitSnd);

/* 41D78 80166578 -O2 -msoft-float */
void FUN_80166578(void)
{
  SsUtReverbOff();
  SsVabClose(0);
  SsEnd();
}

INCLUDE_ASM("asm/nonmatchings/sound", last_snd);

/* TODO: still lots to figure out */
/* 41E90 80166690 -O2 -msoft-float */
s16 get_pile_obj(s16 id)
{
  s16 i;
  Unk_801f62a0 *cur;
  
  i = -1;
  if (pt_pile_snd != 0)
  {
    cur = pile_snd;
    i = 0;
    while (cur->id != id && i < pt_pile_snd)
    {
      cur++;
      i++;
    }
    if (i == pt_pile_snd)
      i = -1;
  }
  return i;
}

/* 41F24 80166724 -O2 -msoft-float */
s16 FUN_80166724(s16 id)
{
  VoiceTableEntry *cur = &voice_table[0];
  s16 i = 0;
  
  while (cur->id != id && i < 24)
  {
    cur++;
    i++;
  }
  if (i == 24)
    i = -1;
  return i;
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166790);

INCLUDE_ASM("asm/nonmatchings/sound", get_voice_obj_snd);

/* 42094 80166894 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */ 
INCLUDE_ASM("asm/nonmatchings/sound", erase_pile_snd);
#else
void erase_pile_snd(s16 id)
{
    s16 pile_obj;
    s16 cur;
    s32 next;

    pile_obj = get_pile_obj(id);
    if (pile_obj != -1)
    {
        for (cur = pile_obj; cur < pt_pile_snd; cur++)
        {
            next = cur + 1;
            pile_snd[cur].id = pile_snd[next].id;
            pile_snd[cur].index = pile_snd[next].index;
            pile_snd[cur].prog = pile_snd[next].prog;
            pile_snd[cur].tone = pile_snd[next].tone;
            pile_snd[cur].note = pile_snd[next].note;
            pile_snd[cur].vol = pile_snd[next].vol;
            pile_snd[cur].field6_0xc = pile_snd[next].field6_0xc;
            pile_snd[cur].field7_0xe = pile_snd[next].field7_0xe;
            pile_snd[cur].field8_0x10 = pile_snd[next].field8_0x10;
            pile_snd[cur].field9_0x14 = pile_snd[next].field9_0x14;
        }
        if (pt_pile_snd > 0)
            pt_pile_snd--;
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/sound", nettoie_pile_snd);

/* 42520 80166D20 -O2 -msoft-float */
void FUN_80166d20(s16 id)
{
  VoiceTableEntry *cur = &voice_table[0];
  s16 i = 0;
  
  while (cur->id != id && i < 24)
  {
      cur++;
      i++;
  }
  if (i != 24)
    cur->id = -2;
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d88);

/* 4261C 80166E1C -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/sound", vol_r);
#else
s16 vol_r(s16 param_1, s16 param_2)
{
  __asm__("nop");
  return param_1 * (u32) snd_sqrt_table[param_2] / 256;
}
#endif

/* 42658 80166E58 -O2 -msoft-float */
s16 vol_l(s16 param_1, s16 param_2)
{
  return param_1 * (u32) snd_sqrt_table[127 - param_2] / 256;
}

INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd);

INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd_old);

INCLUDE_ASM("asm/nonmatchings/sound", setvol);

INCLUDE_ASM("asm/nonmatchings/sound", setpan);

void FUN_80168f38(s16 param_1) {}

void FUN_80168f40(void) {}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80169194);

INCLUDE_ASM("asm/nonmatchings/sound", FUN_8016924c);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_OnPauseOn);

INCLUDE_ASM("asm/nonmatchings/sound", PS1_OnPauseOff);

INCLUDE_RODATA("asm/nonmatchings/sound", snd_sqrt_table);
