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

#ifdef BSS_DEFS
s16 PS1_AllFix_Ray_VabId;
s16 PS1_AllFix_Sep_VabId;
s16 PS1_AllFix_SepAcc;
s16 PS1_World_Ray_VabId;
s16 PS1_World_Sep_VabId;
s16 PS1_World_SepAcc;
s16 indice_ray_wait;
s16 indice_trz_wait;
s16 stk_obj[20];
s16 stk_snd[20];
VoiceTableEntry voice_table[24];
u8 D_801F6850[SS_SEQ_TABSIZ * 2 * 10];
SndFileInfo D_801D8B50;
s32 D_801D8B54;
s32 D_801D8B58;
s32 D_801D8B5C;
s16 D_801FA578;
Unk_801f7d40 D_801F7D40[8];
Unk_801f62a0 pile_snd[10];
s16 pt_pile_snd;
SndFileInfo *D_801D7840;
#endif

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

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadAllFixSound);
#else
/* matches, but clean up/figure out unknowns */
/*INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadAllFixSound);*/

/* 41224 80165A24 -O2 -msoft-float */
/*s32 PS1_LoadVabBody(FileInfo param_1, s16 param_2, u8 *param_3);*/
/*s32 PS1_LoadFiles(FileInfo *files,s32 fileIndex,s32 count, s32 a3);*/

void PS1_LoadAllFixSound(void)
{
  if (D_801CEFDC == 0)
  {
    SsUtReverbOff();
    /* load RAY\SND\BIGFIX.ALL to 801D8B50 */
    PS1_BigFiles[0].dest = (u8 *) &D_801D8B50;
    PS1_FileTemp = PS1_LoadFiles(PS1_BigFiles, 0, 1, 0);
    if (D_801D8B50.field0_0x0 == 3)
    {
      PS1_AllFix_Ray_VabId = 0;
      PS1_AllFix_Ray_VabId = SsVabOpenHead(((u8 *) &D_801D8B50) + D_801D8B50.ray_vh_offs, 0);
      if (PS1_AllFix_Ray_VabId != -1)
        PS1_FileTemp = PS1_LoadVabBody(PS1_VabFiles[0], PS1_AllFix_Ray_VabId, 0);
      PS1_AllFix_Sep_VabId = 2;
      PS1_AllFix_Sep_VabId = SsVabOpenHead(((u8 *) &D_801D8B50) + D_801D8B50.sep_vh_offs, 2);
      if (PS1_AllFix_Sep_VabId != -1)
        PS1_FileTemp = PS1_LoadVabBody(PS1_Vab4sepFiles[0], PS1_AllFix_Sep_VabId, 0);
      PS1_AllFix_SepAcc = 0;
      if (PS1_AllFix_Sep_VabId != -1)
        PS1_AllFix_SepAcc = SsSepOpen(((u8 *) &D_801D8B50) + D_801D8B50.seq_offs, PS1_AllFix_Sep_VabId, D_801C7C78[0]);
    }
    SsUtReverbOn();
    LOAD_CONFIG();
    PS1_SetSoundVolume(options_jeu.Soundfx);
    PS1_SetStereoEnabled(options_jeu.StereoEnabled);
    PS1_SetMusicVolume(options_jeu.Music);
    D_801CEFDC = 1;
  }
}
#endif

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadWorldSound);
#else
/* matches, but clean up/figure out unknowns */
/*INCLUDE_ASM("asm/nonmatchings/sound", PS1_LoadWorldSound);*/

/* 4145C 80165C5C -O2 -msoft-float */
/*s32 PS1_LoadVabBody(FileInfo param_1, s16 param_2, u8 *param_3);*/

void PS1_LoadWorldSound(s16 param_1)
{
  SndFileInfo *piVar1;
  s32 new_var;
  
  stop_all_snd();
  PS1_SetStereoEnabled(options_jeu.StereoEnabled);
  SetVolumeSound(options_jeu.Soundfx * 127 / 20);
  piVar1 = D_801D7840; /* .XXX loaded in load_world */
  if (piVar1->field0_0x0 != 0)
  {
    PS1_World_Ray_VabId = 1;
    SsVabClose(PS1_World_Ray_VabId);
    PS1_World_Sep_VabId = 3;
    SsVabClose(PS1_World_Sep_VabId);
    PS1_World_Ray_VabId = SsVabOpenHead(((u8 *) piVar1) + piVar1->ray_vh_offs, PS1_World_Ray_VabId);
    if (PS1_World_Ray_VabId != -1)
      PS1_FileTemp = PS1_LoadVabBody(PS1_VabFiles[param_1], PS1_World_Ray_VabId, 0);
    PS1_World_Sep_VabId = SsVabOpenHead(((u8 *) piVar1) + piVar1->sep_vh_offs, PS1_World_Sep_VabId);
    if (PS1_World_Sep_VabId != -1)
      PS1_FileTemp = PS1_LoadVabBody(PS1_Vab4sepFiles[param_1], PS1_World_Sep_VabId, 0);
    PS1_World_SepAcc = 1;
    SsSepClose(PS1_World_SepAcc);
    PS1_World_SepAcc = SsSepOpen(
        ((u8 *) piVar1) + piVar1->seq_offs,
        PS1_World_Sep_VabId,
        D_801C7C78[param_1]
    );
  }
}
#endif

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
  SsSetTableSize(D_801F6850, 2, 10);
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

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166790);
#else
/* matches, but... */
/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166790);*/

/* 41F90 80166790 -O2 -msoft-float */
s32 FUN_80166790(s16 id)
{
  s16 i = 0;
  s16 *cur = &voice_table[i].field3_0x6;
  
  while (*cur != id && i < 24)
  {
    cur += sizeof(VoiceTableEntry) / sizeof(s16); /* this is almost certainly incorrect */
    i++;
  }
  if (i == 24)
    i = -1;
  return i;
}
#endif

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", get_voice_obj_snd);
#else
/*
matches, but...
became s16 in the meantime (PlaySnd)
*/
/*INCLUDE_ASM("asm/nonmatchings/sound", get_voice_obj_snd);*/

/* 41FFC 801667FC -O2 -msoft-float */
s16 get_voice_obj_snd(s16 id, s16 param_2)
{
  s16 *psVar1 = &voice_table[0].field3_0x6;
  VoiceTableEntry *pVVar4 = voice_table;
  s16 i = 0;
  
  while(*psVar1 != param_2 && pVVar4->id != id && i < 24)
  {
    i++;
    psVar1 += 6;
    pVVar4++;
  }
  if (i == 24)
    i = -1;
  return i;
}
#endif

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

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d88);
#else
/* matches, but same issues as FUN_80166790, get_voice_obj_snd */
/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_80166d88);*/

/* 42588 80166D88 -O2 -msoft-float */
s16 FUN_80166d88(s16 index)
{
  s16 i;
  s16 *psVar1;
  
  i = 0;
  if (pt_pile_snd != 0)
  {
    psVar1 = &pile_snd[0].index;
    while (*psVar1 != index && i < pt_pile_snd)
    {
        i++;
        psVar1 += 0xc;
    }
    i = i != pt_pile_snd;
  }
  return i;
}
#endif

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

#ifndef NONMATCHINGS
INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd);
#else
/*
score of ???
attempts: 3
*/
/*INCLUDE_ASM("asm/nonmatchings/sound", PlaySnd);*/

/* 42694 80166E94 -O2 -msoft-float */
void PlaySnd(short snd,short obj_id)
{
  u8 bVar1;
  short sVar3;
  s32 sVar4;
  s32 voll;
  s32 volr;
  s32 sVar5;
  int iVar6; /* still used for too many different things? */
  int iVar7;
  s16 *stack_obj_p;
  s16 uVar10;
  int cnt_3;
  s32 uVar12;
  s16 tone;
  s16 unaff_s6;
  u8 local_48;
  u8 local_40;
  s32 test_1;
  s16 uVar9; /* unused currently */
  s16 test_2;
  s16 test_3;
  s16 cnt_4;
  s16 test_4;
  
  #ifdef NUGGET
  printf("PlaySnd\n");
  #endif
  if ((ray.scale != 0) && (obj_id == reduced_rayman_id)) {
    obj_id = 0xffff;
  }
  if (obj_id == rayman_obj_id) {
    obj_id = 0xffff;
  }
  if ((obj_id == -1) && (snd != 0xf)) {
    indice_ray_wait = 0;
  }
  sVar3 = last_snd(obj_id);
  if ((snd != sVar3) && ((hard_sound_table[sVar3].flags >> 3 & 1) != 0)) {
    erase_pile_snd(obj_id);
    sVar4 = get_voice_obj_snd(obj_id,sVar3);
    iVar6 = sVar4;
    if (-1 < iVar6) {
      sVar4 = voice_table[iVar6].field3_0x6;
      SsUtKeyOff(iVar6,bank_to_use[sVar4],hard_sound_table[sVar4].prog,hard_sound_table[sVar4].tone,
                 hard_sound_table[sVar4].note);
      voice_table[iVar6].id = -2;
      voice_table[iVar6].field3_0x6 = -1;
      voice_is_working[iVar6] = 0;
    }
  }
  if (((dans_la_map_monde == false) && (snd != 0)) &&
     ((sVar3 != snd || ((hard_sound_table[sVar3].flags >> 2 & 1) != 0)))) {
    if ((obj_id == -1) || (obj_id == rayman_obj_id)) {
      local_40 = get_pan_snd(&ray);
      local_48 = 0x7f;
    }
    else {
      local_40 = get_pan_snd(&level.objects[obj_id]);
      if ((hard_sound_table[snd].flags & 1) == 0)
      {
        local_48 = 0x7f;
      }
      else
      {
        local_48 = get_vol_snd(level.objects + obj_id);
      }
    }
    uVar10 = hard_sound_table[0].prog;
    tone = hard_sound_table[0].tone;
    switch(snd)
    {
    case 0x35:
      if (level.objects[obj_id].type != TYPE_POING_FEE) {
        uVar10 = hard_sound_table[53].prog;
        tone = hard_sound_table[53].tone;
        unaff_s6 = hard_sound_table[53].note;
      }
      else {
        unaff_s6 = hard_sound_table[0].note;
      }
      break;
    case 0x2f:
      if (num_world != 5) {
        uVar10 = hard_sound_table[47].prog;
        tone = hard_sound_table[47].tone;
        unaff_s6 = hard_sound_table[47].note;
      }
      else {
        uVar10 = hard_sound_table[170].prog;
        tone = hard_sound_table[170].tone;
        unaff_s6 = hard_sound_table[170].note;
      }
      break;
    case 0xf:
      indice_ray_wait = indice_ray_wait + 1;
      if (!(2 >= indice_ray_wait)) {
        indice_ray_wait = 0;
        uVar10 = hard_sound_table[15].prog;
        tone = hard_sound_table[15].tone;
        unaff_s6 = hard_sound_table[15].note;
      }
      erase_pile_snd(0xffffffff);
      break;
    case 0x50:
      indice_trz_wait = indice_trz_wait + 1;
      if (!(1 >= indice_trz_wait)) {
        uVar10 = hard_sound_table[80].prog;
        tone = hard_sound_table[80].tone;
        unaff_s6 = hard_sound_table[80].note;
        indice_trz_wait = 0;
      }
      break;
    case 0xe:
      uVar10 = hard_sound_table[14].prog;
      tone = hard_sound_table[14].tone;
      unaff_s6 = D_801CEFD0[level.objects[obj_id].sub_etat - 24];
      break;
    case 0x13:
      uVar10 = hard_sound_table[19].prog;
      tone = hard_sound_table[19].tone;
      unaff_s6 = hard_sound_table[19].note;
      break;
    case 0xf5:
      uVar10 = hard_sound_table[245].prog;
      tone = hard_sound_table[245].tone;
      unaff_s6 = hard_sound_table[245].note;
      break;
    case 0x37:
      uVar10 = 0xffff;
      if ((s16) PS1_SongIsPlaying(0xc) == 0) {
        PS1_PlaySnd(0xc,0);
      }
      break;
    case 0x39:
      uVar10 = 0xffff;
      PS1_StopPlayingSnd(0xc);
      break;
    case 0x67:
      uVar10 = 0xffff;
      if (SsIsEos(PS1_SepInfos[22].access_num,PS1_SepInfos[22].seq_num) == 0) {
        PS1_PlaySnd(0x16,0);
        D_801CEFCC = 1;
        D_801CEFCE = obj_id;
      }
      break;
    default:
      uVar10 = hard_sound_table[snd].prog;
      tone = hard_sound_table[snd].tone;
      unaff_s6 = hard_sound_table[snd].note;
      break;
    }
    if (uVar10 != -1) {
      erase_pile_snd(obj_id);
      vol_l(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe,local_40);
      vol_r(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe,local_40);
      if (frame_snd[snd] == 0) {

        if (options_jeu.StereoEnabled != 0) {
          voll = vol_l(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe,
                       local_40);
          volr = vol_r(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe,
                       local_40);
          test_2 = SsUtKeyOn(bank_to_use[snd],uVar10,tone,unaff_s6,0,voll,volr);
          SsUtSetVVol(
            test_2,
            vol_l(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe, local_40),
            vol_r(Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe, local_40)
          );
        }
        else {
          test_2 = SsUtKeyOn(bank_to_use[snd],uVar10,tone,unaff_s6,0,
                            (Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe),
                            (Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe));
          test_1 = Volume_Snd * local_48 * hard_sound_table[snd].volume >> 0xe;
          SsUtSetVVol(test_2,test_1,test_1);
        }
        if (test_2 != -1) {
          FUN_80166d20(obj_id);
          voice_table[test_2].id = obj_id;
          voice_table[test_2].field1_0x2 = local_48;
          voice_table[test_2].field2_0x4 = local_40;
          voice_table[test_2].field3_0x6 = snd;
          if ((hard_sound_table[snd].flags >> 4 & 1) != 0) {
            voice_is_working[test_2] = 1;
          }
        }
      }
      else {
        nettoie_pile_snd();
        erase_pile_snd(obj_id);
        pile_snd[pt_pile_snd].id = obj_id;
        pile_snd[pt_pile_snd].index = snd;
        pile_snd[pt_pile_snd].prog = uVar10;
        pile_snd[pt_pile_snd].tone = tone;
        pile_snd[pt_pile_snd].note = unaff_s6;
        pile_snd[pt_pile_snd].vol = hard_sound_table[snd].volume;
        pile_snd[pt_pile_snd].field6_0xc = local_48;
        pile_snd[pt_pile_snd].field7_0xe = local_40;
        pile_snd[pt_pile_snd].field8_0x10 = frame_snd[snd] + map_time;
        if (snd_bis[snd] != 0) {
          pile_snd[pt_pile_snd].field9_0x14 = 1;
        }
        else {
          pile_snd[pt_pile_snd].field9_0x14 = 0;
        }
        if (pt_pile_snd < 9) {
          pt_pile_snd = pt_pile_snd + 1;
        }
      }
    }
    if (((((snd == 0xcb) || (snd == 0xed)) || (snd == 0xd1)) || ((snd == 0xe1 || (snd == 0xec)))) &&
       ((dead_time == 0x40 || (dead_time == 0x80)))) {
      FUN_80132110();
    }
  }
  /* somewhat similar to last_snd */
  cnt_4 = 0;
  do {
    if (cnt_4 == 0x14) {
        goto block_1;
    }
    test_4 = stk_obj[cnt_4];
    if (test_4 == obj_id) {
        /* improves score */
        /*iVar6 = obj_id;
        stk_obj[cnt_4] = iVar6;*/
        stk_obj[cnt_4] = obj_id;
        stk_snd[cnt_4] = snd;
        return;
    }
    cnt_4 = cnt_4 + 1;
  } while (test_4 != -2);
  goto block_2;
block_1: 
  if (snd != 0)
  {
    do {
        cnt_4 = cnt_4 + -1;
        if (cnt_4 == -1) break;
    } while ((level.objects[stk_obj[cnt_4]].flags & FLG(OBJ_ACTIVE)) != FLG_OBJ_NONE);
    if (cnt_4 == -1) {
        cnt_4 = 0;
    }
block_2:
    stk_obj[cnt_4] = obj_id;
    stk_snd[cnt_4] = snd;
    return;
  }
}
#endif

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

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", setvol);
#else
/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/sound", setvol);*/

void setvol(s16 param_1, u8 param_2)
{
    s32 temp_s0_1;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_8;
    s16 temp_s3_1;
    s16 temp_s3_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_7;
    s16 temp_v0_9;
    s16 var_a2;
    s32 temp_a0_1;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s16 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_lo;
    s32 temp_s0_2;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s2_1;
    s32 temp_s2_2;
    s32 temp_s5;
    s32 temp_s7;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_8;
    s32 temp_v1_2;
    s16 var_a0;
    s32 var_v0_1;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v1;
    s16 temp_s3_3;
    s16 temp_v0_6;
    u16 var_s5;
    u32 temp_s1_1;
    u8 temp_v0_1;
    u8 temp_v1_1;
    u8 var_s4_1;
    u8 var_s4_2;
    s16 test_1;
    s16 *new_var;
    s32 new_var2;

    if ((D_801CEFCC != 0) && (param_1 == D_801CEFCE))
    {
        temp_s3_1 = get_pan_snd(&level.objects[param_1]);
        var_s4_1 = get_vol_snd(&level.objects[param_1]);
        if (var_s4_1 >= 6U)
        {
            SsSepSetVol(
                PS1_SepInfos[22].access_num,
                PS1_SepInfos[22].seq_num,
                vol_l(((Volume_Snd * var_s4_1) >> 7), temp_s3_1),
                vol_r(((Volume_Snd * var_s4_1) >> 7), temp_s3_1)
            );
            temp_v0_2 = pt_pile_snd;
            pile_snd[temp_v0_2].field6_0xc = var_s4_1;
            pile_snd[temp_v0_2].field7_0xe = temp_s3_1;
            pile_snd[temp_v0_2].field8_0x10 = map_time + 0xA;
        }
        else
        {
            PS1_StopPlayingSnd(0x0016);
            D_801CEFCC = 0;
        }
    }
    if ((ray.scale != 0) && (param_1 == reduced_rayman_id))
    {
        param_1 = -1;
    }
    if (param_1 == rayman_obj_id)
    {
        param_1 = -1;
    }
    temp_v0_3 = get_pile_obj(param_1);
    if (temp_v0_3 != -1)
    {
        if (
            (param_1 == -1) ||
            (param_1 == rayman_obj_id) ||
            (temp_v1_1 = hard_sound_table[pile_snd[temp_v0_3].index].flags,
              (!(temp_v1_1 >> 0 & 1)) ||
              !((temp_v1_1 >> 1) & 1)
            )
        )
        {
            var_s4_1 = 0x7F;
        }
        else
        {
            var_s4_1 = get_vol_snd(&level.objects[param_1]);
        }
        temp_s7 = map_time;
        pile_snd[temp_v0_3].field6_0xc = var_s4_1;
        if (pile_snd[temp_v0_3].field8_0x10 == temp_s7)
        {
            if (options_jeu.StereoEnabled != 0)
            {
                vol_l(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe);
                vol_r(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe);
                temp_s3_2 = SsUtKeyOn(
                    bank_to_use[pile_snd[temp_v0_3].index],
                    pile_snd[temp_v0_3].prog,
                    pile_snd[temp_v0_3].tone,
                    pile_snd[temp_v0_3].note,
                    0x0040,
                    vol_l(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe),
                    vol_r(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe)
                );
                SsUtSetVVol(
                    temp_s3_2,
                    vol_l(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe),
                    vol_r(((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe)
                );
            }
            else
            {
                temp_s3_2 = SsUtKeyOn(bank_to_use[pile_snd[temp_v0_3].index], pile_snd[temp_v0_3].prog, pile_snd[temp_v0_3].tone, pile_snd[temp_v0_3].note, 0x0040, ((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), ((Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE));
                SsUtSetVVol(temp_s3_2, (Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE, (Volume_Snd * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE);
            }
            if (temp_s3_2 != -1)
            {
                FUN_80166d20(param_1);
                voice_table[temp_s3_2].id = param_1;
                voice_table[temp_s3_2].field1_0x2 = var_s4_1;
                voice_table[temp_s3_2].field2_0x4 = pile_snd[temp_v0_3].field7_0xe;
                voice_table[temp_s3_2].field3_0x6 = pile_snd[temp_v0_3].index;
                if (((u8) hard_sound_table[pile_snd[temp_v0_3].index].flags >> 4) & 1)
                {
                    voice_is_working[temp_s3_2] = 1;
                }
            }
            
            if (pile_snd[temp_v0_3].field9_0x14 != 0)
            {
                /* TODO: still bad */
                pile_snd[temp_v0_3].field8_0x10 = temp_s7 + frame_snd_bis[pile_snd[temp_v0_3].index];
                temp_v0_6 = snd_bis[pile_snd[temp_v0_3].index];
                pile_snd[temp_v0_3].index = temp_v0_6;
                pile_snd[temp_v0_3].prog = hard_sound_table[pile_snd[temp_v0_3].index].prog;
                pile_snd[pt_pile_snd].tone = hard_sound_table[pile_snd[temp_v0_3].index].tone;
                pile_snd[pt_pile_snd].note = hard_sound_table[pile_snd[temp_v0_3].index].note;
                pile_snd[pt_pile_snd].vol = hard_sound_table[pile_snd[temp_v0_3].index].volume;
                pile_snd[temp_v0_3].field9_0x14 = 0; /* TODO: ??? */
            }
            else
            {
                var_a2 = temp_v0_3;
                while (var_a2 < pt_pile_snd)
                {
                    new_var2 = var_a2;
                    temp_v0_8 = new_var2 + 1;
                    pile_snd[var_a2].id = pile_snd[temp_v0_8].id;
                    pile_snd[var_a2].index = pile_snd[temp_v0_8].index;
                    pile_snd[var_a2].prog = pile_snd[temp_v0_8].prog;
                    pile_snd[var_a2].tone = pile_snd[temp_v0_8].tone;
                    pile_snd[var_a2].note = pile_snd[temp_v0_8].note;
                    pile_snd[var_a2].vol = pile_snd[temp_v0_8].vol;
                    pile_snd[var_a2].field6_0xc = pile_snd[temp_v0_8].field6_0xc;
                    pile_snd[var_a2].field7_0xe = pile_snd[temp_v0_8].field7_0xe;
                    pile_snd[var_a2].field8_0x10 = pile_snd[temp_v0_8].field8_0x10;
                    
                    pile_snd[var_a2].field9_0x14 = pile_snd[temp_v0_8].field9_0x14;
                    var_a2 = var_a2 + 1;
                }
                if (pt_pile_snd > 0)
                {
                    pt_pile_snd -= 1;
                }
              
            }
        }
    }
    temp_s3_2 = FUN_80166724(param_1);
    if (temp_s3_2 != -1)
    {

        if (((param_1 == -1) || (param_1 == rayman_obj_id) || (voice_table[temp_s3_2].field3_0x6 == 0x00CC)))
        {
          var_s4_1 = 0x7F;
        }
        else
        {
          var_s4_1 = get_vol_snd(&level.objects[param_1]);
        }
        voice_table[temp_s3_2].field1_0x2 = var_s4_1;
        temp_s3_1 = voice_table[temp_s3_2].field2_0x4;
        if (voice_is_working[temp_s3_2] != 0)
        {
            if (options_jeu.StereoEnabled != 0)
            {
                vol_l(((Volume_Snd * var_s4_1 * hard_sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1);
                vol_r(((Volume_Snd * var_s4_1 * hard_sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1);
                SsUtSetVVol(
                    temp_s3_2,
                    vol_l(((Volume_Snd * var_s4_1 * hard_sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1),
                    vol_r(((Volume_Snd * var_s4_1 * hard_sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1)
                );
            }
            else
            {
                temp_a1_3 = (Volume_Snd * (var_s4_1) * hard_sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE;
                SsUtSetVVol(temp_s3_2, temp_a1_3, temp_a1_3);
            }

        }
    }
}
#endif

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

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);
#else
/*
matches, but ... yeah ... slightly more believable version below?
attempts: 3
tried gotos-only also
*/
/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);*/

void FUN_80168f48(void)
{
    s16 *var_s1;
    s16 *var_s2;
    s16 temp_a0;
    s16 temp_v0;
    s16 temp_v1_2;
    s16 var_a0;
    s16 var_s3;
    s16 var_v0;
    s16 var_v0_3;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_v0_2;

    if ((D_801CEFCC != 0) && !(level.objects[D_801CEFCE].flags & 0x800))
    {
        PS1_StopPlayingSnd(0x0016);
    }

    for (
        var_s1 = &voice_table[0].field3_0x6,
        var_s2 = &voice_table[0].id,
        var_s3 = 0;
        var_s3 <= 0x18;
        var_s3 = var_s3 + 1,
        var_s1 += sizeof(VoiceTableEntry) / sizeof(s16),
        var_s2 += sizeof(VoiceTableEntry) / sizeof(s16)
    )
    {
        if (
            (*var_s2 > -1 && !(level.objects[*var_s2].flags & 0x800)) ||
            (*var_s2 == -2 && *var_s1 != -1)
        )
        {
            if (hard_sound_table[voice_table[var_s3].field3_0x6].flags >> 4 & 1)
            {
                SsUtKeyOff(
                    var_s3,
                    bank_to_use[*var_s1],
                    hard_sound_table[*var_s1].prog,
                    hard_sound_table[*var_s1].tone,
                    hard_sound_table[*var_s1].note
                );
                voice_is_working[var_s3] = 0;
                var_a0 = 0;
                while (var_a0 != 0x0014 && stk_obj[var_a0] != *var_s2)
                {
                    var_a0 = var_a0 + 1;
                }
                if (var_a0 < 0x14)
                {
                    stk_snd[var_a0] = -1;
                }
                *var_s2 = -2;
                *var_s1 = -1;
            }
        }
    }
}

/*void FUN_80168f48(void)
{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  VoiceTableEntry *pVVar5;
  s16 iVar6;
  s16 new_var;
  s16 test_1;
  s32 test_2;
  s16 *cur_stk_obj;
  s16 test_3;
  
  if ((D_801CEFCC != 0) && !((level.objects[D_801CEFCE].flags & FLG(OBJ_ACTIVE)))) {
    PS1_StopPlayingSnd(0x16);
  }
  
  for (
    pVVar5 = &voice_table[0], iVar6 = 0;
    iVar6 <= 0x18;
    iVar6 = iVar6 + 1, pVVar5 = pVVar5 + 1
  )
  {
    iVar3 = pVVar5->id;
    if (
      (
        (-1 < iVar3 && !(level.objects[iVar3].flags & FLG(OBJ_ACTIVE))) ||
        (iVar3 == -2 && pVVar5->field3_0x6 != -1)
      ) &&
      ((hard_sound_table[voice_table[iVar6].field3_0x6].flags >> 4 & 1) != 0)
    )
    {
      test_3 = pVVar5->field3_0x6;
      SsUtKeyOff(iVar6,bank_to_use[test_3],hard_sound_table[test_3].prog,hard_sound_table[test_3].tone,
                 hard_sound_table[test_3].note);
      voice_is_working[iVar6] = 0;
      sVar2 = 0;
      while (sVar2 != 0x14 && stk_obj[sVar2] != pVVar5->id) {
        sVar2++;
      }
      if (sVar2 < 0x14) {
        stk_snd[sVar2] = -1;
      }
      pVVar5->id = -2;
      do{ pVVar5->field3_0x6 = -1; } while (0);
    }
  }
}*/
#endif

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