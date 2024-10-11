#include "sound.h"

const u8 snd_sqrt_table[] =
{
   40,  46,  51,  55,  60,  64,  67,  70,  72,  74, 
   77,  80,  83,  86,  89,  91,  93,  95,  96,  98, 
  101, 104, 107, 109, 111, 113, 115, 117, 120, 122, 
  124, 125, 127, 129, 131, 133, 135, 137, 138, 140, 
  142, 144, 145, 147, 149, 150, 152, 153, 155, 156, 
  158, 160, 161, 163, 164, 166, 167, 168, 170, 171, 
  173, 174, 176, 177, 178, 180, 181, 182, 184, 185, 
  186, 187, 189, 190, 191, 193, 194, 195, 196, 198, 
  199, 200, 201, 202, 203, 205, 206, 207, 208, 210, 
  211, 212, 213, 214, 215, 217, 218, 219, 220, 222, 
  223, 224, 225, 226, 227, 229, 230, 231, 232, 233, 
  234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 
  244, 245, 246, 247, 248, 249, 250, 251
};

/* too much unknown? */
extern u8 D_801F7D41;
extern u8 D_801F7D42;
extern u8 D_801F7D43;
extern u8 place_sequence[5];
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

/* 410E0 801658E0 -O2 -msoft-float */
void FUN_801658e0(void)
{
    s16 seq_num; s16 acc_num;

    D_801CEFCC = 0;
    for (acc_num = 0; acc_num < 2; acc_num++)
        for (seq_num = 0; seq_num < 10; seq_num++)
            if (SsIsEos(acc_num, seq_num))
                SsSepStop(acc_num, seq_num);
}

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
void PS1_PlaySnd(s16 sep_ind, s16 l_count)
{
  s16 vol = D_801F7C80 * PS1_SepVols[sep_ind] >> 7;

  SsSepSetVol(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num, vol, vol);
  SsSeqCalledTbyT();
  SsSepPlay(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num, SSPLAY_PLAY, l_count);
}

/* 41778 80165F78 -O2 -msoft-float */
void PS1_StopPlayingSnd(s16 sep_ind)
{
  if (sep_ind != 25)
    SsSepStop(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num);
}

/* 417CC 80165FCC -O2 -msoft-float */
s32 PS1_SongIsPlaying(s16 sep_ind)
{
  return SsIsEos(PS1_SepInfos[sep_ind].access_num, PS1_SepInfos[sep_ind].seq_num);
}

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
  Volume_Snd = vol;
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
void stop_all_snd(void)
{
  s16 i;

  SsUtAllKeyOff(0);
  for (i = 0; i < (s16) LEN(voice_is_working); i++)
    voice_is_working[i] = false;
}

/* 4197C 8016617C -O2 -msoft-float */
void FUN_8016617c(void)
{
  s16 i;
  s16 unk_1;

  for (i = 0; i < (s16) LEN(voice_table); i++)
  {
    unk_1 = voice_table[i].field3_0x6;
    if (unk_1 == 6 || unk_1 == 245 || unk_1 == 2)
      SsUtSetVVol(i, 0, 0);
  }
}

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
void PS1_SetSoundVolume(s16 vol)
{
  SetVolumeSound(vol * 127 / 20);
}

/* 41B9C 8016639C -O2 -msoft-float */
void PS1_SetStereoEnabled(s16 enabled)
{
  if (enabled)
    FUN_801660ac();
  else
    FUN_801660e8();
}

/* 41BD4 801663D4 -O2 -msoft-float */
void InitSnd(void)
{
    s32 i = 0;
    s16 unk_1 = -2;
    s16 *cur_stk_obj = stk_obj;
    s16 *cur_stk_snd = stk_snd;

    while (i < (s16) LEN(stk_obj))
    {
        *cur_stk_snd = 0;
        *cur_stk_obj = unk_1;
        cur_stk_obj++;
        cur_stk_snd++;
        i++;
    }

    pt_pile_snd = 0;
    D_801FA578 = 0;
    indice_ray_wait = 0;
    indice_trz_wait = 2;
    for(i = 0; i < (s16) LEN(D_801F7D40); i++)
    {
        D_801F7D40[i].field0_0x0 = D_801CEFD0[i];
        D_801F7D40[i].field1_0x1 = -1;
        D_801F7D40[i].field2_0x2 = 0;
        D_801F7D40[i].field3_0x3 = 0;
    }
    
    for(i = 0; i < (s16) LEN(voice_table); i++)
        voice_table[i].id = -2;
    
    SsSetSerialAttr(SS_SERIAL_A, SS_MIX, SS_SON);
    SetVolumeSound(options_jeu.Soundfx * 127 / 20);
    PS1_SetStereoEnabled(options_jeu.StereoEnabled);
    SsUtSetReverbType(SS_REV_TYPE_STUDIO_A);
    SsUtReverbOn();
    for(i = 0; i < 200; i++)
        VSync(0);
    SsUtSetReverbDepth(20, 20);
}

/* 41D78 80166578 -O2 -msoft-float */
void FUN_80166578(void)
{
  SsUtReverbOff();
  SsVabClose(0);
  SsEnd();
}

/* 41DA8 801665A8 -O2 -msoft-float */
s32 last_snd(s16 obj_id)
{
    s16 i;
    s16 res;

    for (
        i = 0;
        i != (s16) LEN(stk_obj) && stk_obj[i] != obj_id;
        i++
    ) {}

    if (i == (s16) LEN(stk_obj))
    {
        do {
            i--;
        } while (i != -1 && stk_snd[i] != 0);
        if (i == -1)
            i = 0;
    }

    if (i == -1)
        res = -1;
    else
        res = stk_snd[i];
    return res;
}

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
  s16 i = 0;
  VoiceTableEntry *cur = &voice_table[i];
  
  while (cur->id != id && i < (s16) LEN(voice_table))
  {
    cur++;
    i++;
  }
  if (i == (s16) LEN(voice_table))
    i = -1;
  return i;
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166790);

INCLUDE_ASM("asm/nonmatchings/sound", get_voice_obj_snd);

/* 42094 80166894 -O2 -msoft-float */
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
}

/* 422AC 80166AAC -O2 -msoft-float */
void nettoie_pile_snd(void)
{  
  s16 cur;
  s32 next;
  s16 i = 0;

  while (i < pt_pile_snd)
  {
    if ((u32) pile_snd[i].field8_0x10 < map_time && pile_snd[i].field8_0x10 != 0)
    {
      
      for (cur = i; cur < pt_pile_snd; cur++)
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
    else
      i++;
  }
}

/* 42520 80166D20 -O2 -msoft-float */
void FUN_80166d20(s16 id)
{
  s16 i = 0;
  VoiceTableEntry *cur = &voice_table[i];
  
  while (cur->id != id && i < (s16) LEN(voice_table))
  {
      cur++;
      i++;
  }
  if (i != (s16) LEN(voice_table))
    cur->id = -2;
}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d88);

/* 4261C 80166E1C -O2 -msoft-float */
s16 vol_r(s16 param_1, s16 param_2)
{
  return param_1 * (u32) snd_sqrt_table[param_2] / 256;
}

/* 42658 80166E58 -O2 -msoft-float */
s16 vol_l(s16 param_1, s16 param_2)
{
  return param_1 * (u32) snd_sqrt_table[127 - param_2] / 256;
}

INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd);

/* TODO: must be macro/inlining going on, surely? */
/* 43400 80167C00 -O2 -msoft-float */
void PlaySnd_old(s16 snd)
{
  s16 new_id;
  s32 voll_1;
  s32 volr_1;
  s16 voice_ind;
  s32 voll_2;
  s32 volr_2;
  s32 vol_both;

  new_id = -2;
  if (options_jeu.StereoEnabled)
  {
    vol_l(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    vol_r(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    voll_1 = vol_l(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    volr_1 = vol_r(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    voice_ind = SsUtKeyOn(
      bank_to_use[snd], hard_sound_table[snd].prog,
      hard_sound_table[snd].tone, hard_sound_table[snd].note,
      0,
      voll_1, volr_1
    );
    voll_2 = vol_l(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    volr_2 = vol_r(Volume_Snd * hard_sound_table[snd].volume >> 7, 64);
    SsUtSetVVol(voice_ind, voll_2, volr_2);
  }
  else
  {
    voice_ind = SsUtKeyOn(
      bank_to_use[snd], hard_sound_table[snd].prog,
      hard_sound_table[snd].tone, hard_sound_table[snd].note,
      0,
      Volume_Snd * hard_sound_table[snd].volume >> 7, Volume_Snd * hard_sound_table[snd].volume >> 7
    );
    vol_both = Volume_Snd * hard_sound_table[snd].volume >> 7;
    SsUtSetVVol(voice_ind, vol_both, vol_both);
  }
  if (voice_ind != -1)
  {
    voice_table[voice_ind].id = new_id;
    voice_table[voice_ind].field1_0x2 = 64;
    voice_table[voice_ind].field2_0x4 = 64;
    if (hard_sound_table[snd].flags >> 4 & 1)
      voice_is_working[voice_ind] = true;
  }
}

INCLUDE_ASM("asm/nonmatchings/sound", setvol);

/* 445D0 80168DD0 -O2 -msoft-float */
void setpan(s16 obj_id, u8 param_2)
{
  s16 voice_ind;
  s16 pile_ind;
  u8 pan;
  
  if (ray.scale != 0 && obj_id == reduced_rayman_id)
    obj_id = -1;
  voice_ind = FUN_80166724(obj_id);
  if (voice_ind != -1)
  {
    if (obj_id == -1)
      pan = get_pan_snd(&ray);
    else
      pan = get_pan_snd(&level.objects[obj_id]);
    voice_table[voice_ind].field2_0x4 = pan;
  }
  else
  {
    if (obj_id == -1)
      pan = get_pan_snd(&ray);
    else
      pan = get_pan_snd(&level.objects[obj_id]);
    pile_ind = get_pile_obj(obj_id);
    if (pile_ind != -1)
      pile_snd[pile_ind].field7_0xe = pan;
  }
}

void FUN_80168f38(s16 param_1) {}

void FUN_80168f40(void) {}

INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);

/* 44994 80169194 -O2 -msoft-float */
void FUN_80169194(void)
{
    s16 i;
    s16 sound_ind;

    for (i = 0; i < (s16) LEN(voice_table); i++)
    {
        sound_ind = voice_table[i].field3_0x6;
        if (
          sound_ind == 6 || sound_ind == 245 ||
          sound_ind == 2 || hard_sound_table[sound_ind].flags >> 4 & 1
        )
            SsUtSetVVol(i, 0, 0);
    }
}

/* 44A4C 8016924C -O2 -msoft-float */
void FUN_8016924c(void)
{
  s16 i;
  
  for (i = 0; i < 24; i++)
    SsUtSetVVol(i, 0, 0);
}

/* 44A9C 8016929C -O2 -msoft-float */
void PS1_OnPauseOn(void)
{
  s16 sep_access_num;
  s16 seq_num;
  
  FUN_8016924c();
  D_801CEFD8 = true;
  *(s16*)&PS1_Music_pcom = CdlPause; /* TODO: s16? */
  CdControlB(CdlPause, null, null);
  
  for (sep_access_num = 0; sep_access_num < 2; sep_access_num++)
    for (seq_num = 0; seq_num < 10; seq_num++)
      SsSepSetVol(sep_access_num, seq_num, 0, 0);
}

/* 44B50 80169350 -O2 -msoft-float */
void PS1_OnPauseOff(void)
{
  s16 i;
  s16 vol;

  if (D_801CEFD8)
    CdControl(CdlPlay, null, null);
  for (i = 0; i <= 24; i++)
  {
    vol = D_801F7C80 * PS1_SepVols[i] >> 7;
    SsSepSetVol(PS1_SepInfos[i].access_num, PS1_SepInfos[i].seq_num, vol, vol);
  }
  D_801CEFD8 = false;
}