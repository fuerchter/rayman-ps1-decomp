#include "sound.h"

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
        PS1_AllFix_SepAcc = SsSepOpen((u8 *)((int)&D_801D8B50 + D_801D8B5C), PS1_AllFix_VabId2, D_801C7C78[0]);
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
        D_801C7C78[param_1]
    );
  }
}

/* matches, but test_1, the loop with < 8 */
/*INCLUDE_ASM("asm/nonmatchings/sound", InitSnd);*/

/* 41BD4 801663D4 -O2 -msoft-float */
void InitSnd(void)
{
    s16 *var_a0;
    s16 *var_v1;
    s32 i;
    s16 test_1;

    i = 0;
    test_1 = -2;
    var_a0 = stk_obj;
    var_v1 = stk_snd;
    while (i < 20)
    {
        *var_v1 = 0;
        *var_a0 = test_1;
        var_a0++;
        i++;
        var_v1++;
    }
    pt_pile_snd = 0;
    D_801FA578 = 0;
    indice_ray_wait = 0;
    indice_trz_wait = 2;
    for(i = 0; i < 8; i++)
    {
        D_801F7D40[i].field0_0x0 = D_801CEFD0[i];
        D_801F7D40[i].field1_0x1 = -1;
        D_801F7D40[i].field2_0x2 = 0;
        D_801F7D40[i].field3_0x3 = 0;
    }
    for(i = 0; i < (s16) LEN(voice_table); i++)
        voice_table[i].id = -2;
    
    SsSetSerialAttr(0, 0, 1);
    SetVolumeSound(options_jeu.Soundfx * 127 / 20);
    PS1_SetStereoEnabled(options_jeu.StereoEnabled);
    SsUtSetReverbType(2);
    SsUtReverbOn();
    for(i = 0; i < 200; i++)
        VSync(0);
    SsUtSetReverbDepth(20, 20);
}

/* matches, but gotos */
/*INCLUDE_ASM("asm/nonmatchings/sound", last_snd);*/

/* 41DA8 801665A8 -O2 -msoft-float */
s32 last_snd(s16 param_1)
{
  short sVar1;
  s16 iVar2;
  s16 iVar3;
  
  iVar3 = 0;
  while (iVar3 != 0x14 && stk_obj[iVar3] != param_1) {
    iVar3 = iVar3 + 1;
  }

  if ((short)iVar3 == 0x14) {
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 == -1) {
        iVar3 = 0;
        goto LAB_80166650;
      }
    } while (stk_snd[iVar3] != 0);
  }
  else {
LAB_80166650:
    if (iVar3 == -1) {
      sVar1 = -1; /* unreachable? */
      goto code_r0x80166684;
    }
  }
  sVar1 = stk_snd[iVar3];
code_r0x80166684:
  return (int)sVar1;
}

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
  s16 *puVar8;
  s16 uVar10;
  int iVar11;
  s32 uVar12;
  s16 tone;
  s16 unaff_s6;
  u8 local_48;
  u8 local_40;
  s32 test_1;
  s16 uVar9; /* unused currently */
  
  if ((ray.scale != 0) && (obj_id == reduced_rayman_id)) {
    obj_id = 0xffff;
  }
  if (obj_id == rayman_obj_id) {
    obj_id = 0xffff;
  }
  if ((obj_id == -1) && (snd != 0xf)) {
    indice_ray_wait = 0;
  }
  iVar11 = obj_id;
  sVar3 = last_snd(iVar11);
  if ((snd != sVar3) && ((sound_table[sVar3].flags >> 3 & 1) != 0)) {
    erase_pile_snd(iVar11);
    sVar4 = get_voice_obj_snd(iVar11,sVar3);
    iVar6 = sVar4;
    if (-1 < iVar6) {
      sVar4 = voice_table[iVar6].field3_0x6;
      SsUtKeyOff(iVar6,PS1_SoundVabIds[sVar4],sound_table[sVar4].prog,sound_table[sVar4].tone,
                 sound_table[sVar4].note);
      voice_table[iVar6].id = -2;
      voice_table[iVar6].field3_0x6 = -1;
      voice_is_working[iVar6] = 0;
    }
  }
  if (((dans_la_map_monde == false) && (snd != 0)) &&
     ((sVar3 != snd || ((sound_table[sVar3].flags >> 2 & 1) != 0)))) {
    iVar11 = obj_id;
    if ((iVar11 == -1) || (iVar11 == rayman_obj_id)) {
      local_40 = get_pan_snd(&ray);
      local_48 = 0x7f;
    }
    else {
      local_40 = get_pan_snd(level.objects + iVar11);
      if ((sound_table[snd].flags & 1) == 0)
      {
        local_48 = 0x7f;
      }
      else
      {
        local_48 = get_vol_snd(level.objects + iVar11);
      }
    }
    uVar10 = sound_table[0].prog;
    tone = sound_table[0].tone;
    switch(snd)
    {
    case 0x35:
      if (level.objects[obj_id].type != TYPE_POING_FEE) {
        uVar10 = sound_table[53].prog;
        tone = sound_table[53].tone;
        unaff_s6 = sound_table[53].note;
      }
      else {
        unaff_s6 = sound_table[0].note;
      }
      break;
    case 0x2f:
      if (num_world != 5) {
        uVar10 = sound_table[47].prog;
        tone = sound_table[47].tone;
        unaff_s6 = sound_table[47].note;
      }
      else {
        uVar10 = sound_table[170].prog;
        tone = sound_table[170].tone;
        unaff_s6 = sound_table[170].note;
      }
      break;
    case 0xf:
      indice_ray_wait = indice_ray_wait + 1;
      if (!(2 >= indice_ray_wait)) {
        indice_ray_wait = 0;
        uVar10 = sound_table[15].prog;
        tone = sound_table[15].tone;
        unaff_s6 = sound_table[15].note;
      }
      erase_pile_snd(0xffffffff);
      break;
    case 0x50:
      indice_trz_wait = indice_trz_wait + 1;
      if (!(1 >= indice_trz_wait)) {
        uVar10 = sound_table[80].prog;
        tone = sound_table[80].tone;
        unaff_s6 = sound_table[80].note;
        indice_trz_wait = 0;
      }
      break;
    case 0xe:
      uVar10 = sound_table[14].prog;
      tone = sound_table[14].tone;
      unaff_s6 = place_sequence[level.objects[obj_id].sub_etat];
      break;
    case 0x13:
      uVar10 = sound_table[19].prog;
      tone = sound_table[19].tone;
      unaff_s6 = sound_table[19].note;
      break;
    case 0xf5:
      uVar10 = sound_table[245].prog;
      tone = sound_table[245].tone;
      unaff_s6 = sound_table[245].note;
      break;
    case 0x37:
      uVar10 = 0xffff;
      sVar3 = PS1_SongIsPlaying(0xc);
      if (sVar3 == 0) {
        PS1_PlaySnd(0xc,0);
      }
      break;
    case 0x39:
      uVar10 = 0xffff;
      PS1_StopPlayingSnd(0xc);
      break;
    case 0x67:
      uVar10 = 0xffff;
      sVar3 = SsIsEos(PS1_SepInfos[22].access_num,PS1_SepInfos[22].seq_num);
      if (sVar3 == 0) {
        PS1_PlaySnd(0x16,0);
        D_801CEFCC = 1;
        D_801CEFCE = obj_id;
      }
      break;
    default:
      uVar10 = sound_table[snd].prog;
      tone = sound_table[snd].tone;
      unaff_s6 = sound_table[snd].note;
      break;
    }
    if (uVar10 != -1) {
      erase_pile_snd(obj_id);
      uVar12 = local_48;
      vol_l(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,local_40);
      vol_r(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,local_40);
      if (frame_snd[snd] == 0) {

        if (options_jeu.StereoEnabled != 0) {
          voll = vol_l(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,
                       local_40);
          volr = vol_r(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,
                       local_40);
          uVar10 = SsUtKeyOn(PS1_SoundVabIds[snd],uVar10,tone,unaff_s6,0,voll,volr);
          sVar4 = vol_l(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,
                        local_40);
          sVar5 = vol_r(PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe,
                        local_40);
          SsUtSetVVol(uVar10,sVar4,sVar5);
        }
        else {
          uVar10 = SsUtKeyOn(PS1_SoundVabIds[snd],uVar10,tone,unaff_s6,0,
                            (PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe),
                            (PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe));
          test_1 = PS1_SoundVolume * uVar12 * sound_table[snd].volume >> 0xe;
          SsUtSetVVol(uVar10,test_1,test_1);
        }
        if (uVar10 != -1) {
          FUN_80166d20(obj_id);
          voice_table[uVar10].id = obj_id;
          voice_table[uVar10].field1_0x2 = local_48;
          voice_table[uVar10].field2_0x4 = local_40;
          voice_table[uVar10].field3_0x6 = snd;
          if ((sound_table[snd].flags >> 4 & 1) != 0) {
            voice_is_working[uVar10] = 1;
          }
        }
      }
      else {
        nettoie_pile_snd();
        erase_pile_snd(obj_id);
        iVar6 = pt_pile_snd;
        pile_snd[iVar6].id = obj_id;
        pile_snd[iVar6].index = snd;
        pile_snd[iVar6].prog = uVar10;
        pile_snd[iVar6].tone = tone;
        pile_snd[iVar6].note = unaff_s6;
        bVar1 = sound_table[snd].volume;
        pile_snd[iVar6].field6_0xc = local_48;
        pile_snd[iVar6].vol = bVar1;
        pile_snd[iVar6].field7_0xe = local_40;
        pile_snd[iVar6].field8_0x10 = frame_snd[snd] + map_time;
        if (snd_bis[snd] != 0) {
          pile_snd[iVar6].field9_0x14 = 1;
        }
        else {
          pile_snd[iVar6].field9_0x14 = 0;
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
  iVar6 = 0;
  do {
    iVar11 = iVar6;
    iVar7 = iVar11 * 2;
    if (iVar11 == 0x14) {
      if (snd == 0) {
        return;
      }
      goto LAB_80167b40;
    }
    puVar8 = (s16 *)(stk_obj + iVar11);
    if (*puVar8 == obj_id) {
      *puVar8 = obj_id;
      goto LAB_80167bb8;
    }
    iVar6 = iVar6 + 1;
  } while (*puVar8 != -2);
  *puVar8 = obj_id;
LAB_80167bb8:
  *(short *)((int)stk_snd + iVar7) = snd;
  return;
  while ((level.objects[stk_obj[iVar11]].flags & FLG(OBJ_ACTIVE)) != FLG_OBJ_NONE) {
LAB_80167b40:
    iVar6 = iVar6 + -1;
    iVar11 = iVar6 * 0x10000 >> 0x10;
    if (iVar11 == -1) goto LAB_80167b90;
  }
  iVar6 = iVar6 * 0x10000;
  if (iVar11 == -1) {
LAB_80167b90:
    iVar6 = 0;
  }
  iVar7 = iVar6 >> 0xf;
  *(short *)((int)stk_obj + iVar7) = obj_id;
  goto LAB_80167bb8;
}

/* m2c gotos-only */
void PlaySnd(s16 snd, s16 obj_id)
{
    s32 sp38;
    s16 *temp_a0_1;
    s16 iVar11_2;
    s16 temp_a1_3;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s1_2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_7;
    s16 temp_v1_4;
    s16 iVar11_1;
    s16 obj_id_sav;
    s16 var_v0_8;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_fp;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 iVar7;
    s32 var_v0_9;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u8 var_s0;
    u8 var_s4;
    u8 var_s6;
    u8 local_48;
    u8 local_40;

    obj_id_sav = obj_id;
    if (ray.scale == 0)
    {
        goto block_3;
    }
    if (obj_id != reduced_rayman_id)
    {
        goto block_3;
    }
    obj_id_sav = -1;
block_3:
    var_v0 = obj_id_sav << 0x10;
    if (obj_id_sav != rayman_obj_id)
    {
        goto block_5;
    }
    obj_id_sav = -1;
    var_v0 = -1 << 0x10;
block_5:
    var_v0_2 = obj_id_sav << 0x10;
    if ((var_v0 >> 0x10) != -1)
    {
        goto block_8;
    }
    var_v0_2 = obj_id_sav << 0x10;
    if ((s16) snd == 0x000F)
    {
        goto block_8;
    }
    indice_ray_wait = 0;
block_8:
    temp_s1 = var_v0_2 >> 0x10;
    temp_v0 = last_snd((s16) temp_s1);
    if ((s16) snd == temp_v0)
    {
        goto block_12;
    }
    if (!(((u8) (sound_table[(temp_v0 * 5)].flags) >> 3) & 1))
    {
        goto block_12;
    }
    erase_pile_snd((s16) temp_s1);
    temp_v0_2 = get_voice_obj_snd((s16) temp_s1, temp_v0);
    if (temp_v0_2 < 0)
    {
        goto block_12;
    }
    temp_s0 = temp_v0_2 * 0xC;
    temp_v0_3 = voice_table[temp_s0].field3_0x6;
    temp_v1 = temp_v0_3 * 5;
    SsUtKeyOff(temp_v0_2, (s16) PS1_SoundVabIds[temp_v0_3], sound_table[temp_v0_3].prog, sound_table[temp_v0_3].tone, (s16) (s32) sound_table[temp_v0_3].note);
    voice_table[temp_v0_2].id = -2;
    voice_table[temp_s0].field3_0x6 = -1;
    voice_is_working[temp_v0_2] = 0;
block_12:
    iVar11_1 = 0;
    if (dans_la_map_monde != 0)
    {
        goto block_81;
    }
    if ((s16) snd == 0)
    {
        goto block_81;
    }
    var_v0_3 = obj_id_sav << 0x10;
    if (temp_v0 != (s16) snd)
    {
        goto block_16;
    }
    var_v0_3 = obj_id_sav << 0x10;
    if (!(((u8) (sound_table[temp_v0].flags) >> 2) & 1))
    {
        goto block_81;
    }
block_16:
    temp_v1_2 = var_v0_3 >> 0x10;
    if (temp_v1_2 == -1)
    {
        goto block_18;
    }
    if (temp_v1_2 != rayman_obj_id)
    {
        goto block_19;
    }
block_18:
    local_40 = get_pan_snd(&ray);
    goto block_20;
block_19:
    local_40 = get_pan_snd(&level.objects[temp_v1_2]);
    if (sound_table[snd].flags & 1)
    {
        goto block_21;
    }
block_20:
    local_48 = 0x7f;
    goto block_22;
block_21:
    local_48 = get_vol_snd(&level.objects[temp_v1_2]);
block_22:
    var_s0 = sound_table[0].prog;
    var_s4 = sound_table[0].tone;
    if ((s16) snd == 0x0035)
    {
        goto block_39;
    }
    if ((s16) snd >= 0x36)
    {
        goto block_31;
    }
    if ((s16) snd == 0x000F)
    {
        goto block_45;
    }
    if ((s16) snd >= 0x10)
    {
        goto block_28;
    }
    if ((s16) snd == 0x000E)
    {
        goto block_50;
    }
    var_v0_4 = snd << 0x10;
    goto block_59;
block_28:
    if ((s16) snd == 0x0013)
    {
        goto block_51;
    }
    if ((s16) snd == 0x002F)
    {
        goto block_42;
    }
    goto block_58;
block_31:
    if ((s16) snd == 0x0050)
    {
        goto block_48;
    }
    if ((s16) snd >= 0x51)
    {
        goto block_36;
    }
    if ((s16) snd == 0x0037)
    {
        goto block_53;
    }
    var_s0 = -1U;
    if ((s16) snd == 0x0039)
    {
        goto block_55;
    }
    goto block_58;
block_36:
    if ((s16) snd == 0x0067)
    {
        goto block_56;
    }
    if ((s16) snd == 0x00F5)
    {
        goto block_52;
    }
    goto block_58;
block_39:
    if (level.objects[obj_id_sav].type == 0xEE)
    {
        goto block_41;
    }
    var_s0 = sound_table[53].prog;
    var_s4 = sound_table[53].tone;
    var_s6 = sound_table[53].note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_41:
    var_s6 = sound_table->note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_42:
    if (num_world == 5)
    {
        goto block_44;
    }
    var_s0 = sound_table[47].prog;
    var_s4 = sound_table[47].tone;
    var_s6 = sound_table[47].note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_44:
    var_s0 = sound_table[170].prog;
    var_s4 = sound_table[170].tone;
    var_s6 = sound_table[170].note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_45:
    temp_v0_4 = (u16) indice_ray_wait;
    indice_ray_wait = temp_v0_4 + 1;
    if ((s16) temp_v0_4 < 3)
    {
        goto block_47;
    }
    indice_ray_wait = 0;
    var_s0 = sound_table[15].prog;
    var_s4 = sound_table[15].tone;
    var_s6 = sound_table[15].note;
block_47:
    erase_pile_snd(-1);
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_48:
    temp_v0_5 = (u16) indice_trz_wait;
    indice_trz_wait = temp_v0_5 + 1;
    var_v0_5 = var_s0 << 0x10;
    if ((s16) temp_v0_5 < 2)
    {
        goto block_60;
    }
    var_s0 = sound_table[80].prog;
    var_s4 = sound_table[80].tone;
    var_s6 = sound_table[80].note;
    indice_trz_wait = 0;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_50:
    var_s0 = sound_table[14].prog;
    var_s4 = sound_table[14].tone;
    var_s6 = place_sequence[level.objects[obj_id_sav].sub_etat];
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_51:
    var_s0 = sound_table[19].prog;
    var_s4 = sound_table[19].tone;
    var_s6 = sound_table[19].note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_52:
    var_s0 = sound_table[245].prog;
    var_s4 = sound_table[245].tone;
    var_s6 = sound_table[245].note;
    var_v0_5 = var_s0 << 0x10;
    goto block_60;
block_53:
    var_s0 = -1U;
    var_v0_5 = -1 << 0x10;
    if ((PS1_SongIsPlaying(0x000C) << 0x10) != 0)
    {
        goto block_60;
    }
    PS1_PlaySnd(0x000C, 0);
    var_v0_5 = -1 << 0x10;
    goto block_60;
block_55:
    PS1_StopPlayingSnd(0x000C);
    var_v0_5 = -1 << 0x10;
    goto block_60;
block_56:
    var_s0 = -1U;
    var_v0_5 = -1 << 0x10;
    if ((SsIsEos(PS1_SepInfos[22].access_num, PS1_SepInfos[22].seq_num) << 0x10) != 0)
    {
        goto block_60;
    }
    PS1_PlaySnd(0x0016, 0);
    D_801CEFCC = 1;
    D_801CEFCE = obj_id_sav;
    var_v0_5 = -1 << 0x10;
    goto block_60;
block_58:
    var_v0_4 = snd << 0x10;
block_59:
    temp_v0_6 = var_v0_4 >> 0x10;
    temp_v1_3 = temp_v0_6 * 5;
    var_s0 = sound_table[temp_v0_6].prog;
    var_s4 = sound_table[temp_v0_6].tone;
    var_s6 = sound_table[temp_v0_6].note;
    var_v0_5 = var_s0 << 0x10;
block_60:
    temp_fp = var_v0_5 >> 0x10;
    if (temp_fp == -1)
    {
        goto block_73;
    }
    sp38 = (s32) obj_id_sav;
    erase_pile_snd((s16) sp38);
    temp_s2 = (s16) snd * 5;
    vol_l((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40);
    vol_r((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40);
    if (frame_snd[(s16) snd] != 0)
    {
        goto block_68;
    }
    if (options_jeu.StereoEnabled == 0)
    {
        goto block_64;
    }
    temp_s0_2 = vol_l((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40);
    temp_s1_2 = SsUtKeyOn((s16) PS1_SoundVabIds[(s16) snd], (s16) temp_fp, (s16) var_s4, (s16) var_s6, 0, (s16) (s32) temp_s0_2, (s16) (s32) vol_r((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40));
    temp_s0_3 = vol_l((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40);
    SsUtSetVVol(temp_s1_2, temp_s0_3, vol_r((s16) ((s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE), (s16) local_40));
    var_v0_6 = temp_s1_2 << 0x10;
    goto block_65;
block_64:
    temp_lo = PS1_SoundVolume * local_48;
    temp_v0_7 = SsUtKeyOn((s16) PS1_SoundVabIds[(s16) snd], (s16) temp_fp, (s16) var_s4, (s16) var_s6, 0, (s16) ((s32) (temp_lo * sound_table[snd].volume) >> 0xE), (s16) ((s32) (temp_lo * sound_table[snd].volume) >> 0xE));
    temp_a1 = (s32) (PS1_SoundVolume * local_48 * sound_table[snd].volume) >> 0xE;
    SsUtSetVVol(temp_v0_7, (s16) temp_a1, (s16) temp_a1);
    var_v0_6 = temp_v0_7 << 0x10;
block_65:
    temp_s0_4 = var_v0_6 >> 0x10;
    if (temp_s0_4 == -1)
    {
        goto block_73;
    }
    FUN_80166d20(obj_id_sav);
    temp_v0_8 = temp_s0_4 * 0xC;
    voice_table[temp_s0_4].id = obj_id_sav;
    voice_table[temp_s0_4].field1_0x2 = (s16) local_48;
    voice_table[temp_s0_4].field2_0x4 = (s16) local_40;
    voice_table[temp_s0_4].field3_0x6 = snd;
    if (!(((u8) sound_table[snd].flags >> 4) & 1))
    {
        goto block_73;
    }
    voice_is_working[temp_s0_4] = 1;
    goto block_73;
block_68:
    nettoie_pile_snd();
    erase_pile_snd((s16) sp38);
    temp_a1_2 = pt_pile_snd * 0x18;
    pile_snd[pt_pile_snd].id = obj_id_sav;
    pile_snd[pt_pile_snd].index = snd;
    pile_snd[pt_pile_snd].prog = (s16) var_s0;
    pile_snd[pt_pile_snd].tone = (s16) var_s4;
    pile_snd[pt_pile_snd].note = (s16) var_s6;
    pile_snd[pt_pile_snd].field6_0xc = (s16) local_48;
    pile_snd[pt_pile_snd].vol = sound_table[snd].volume;
    pile_snd[pt_pile_snd].field7_0xe = (s16) local_40;
    pile_snd[pt_pile_snd].field8_0x10 = frame_snd[(s16) snd] + map_time;
    if (snd_bis[(s16) snd] == 0)
    {
        goto block_70;
    }
    pile_snd[pt_pile_snd].field9_0x14 = 1;
    goto block_71;
block_70:
    pile_snd[pt_pile_snd].field9_0x14 = 0;
block_71:
    if (pt_pile_snd >= 9)
    {
        goto block_73;
    }
    pt_pile_snd += 1;
block_73:
    if ((s16) snd == 0x00CB)
    {
        goto block_78;
    }
    if ((s16) snd == 0x00ED)
    {
        goto block_78;
    }
    if ((s16) snd == 0x00D1)
    {
        goto block_78;
    }
    if ((s16) snd == 0x00E1)
    {
        goto block_78;
    }
    iVar11_1 = 0;
    if ((s16) snd != 0x00EC)
    {
        goto block_81;
    }
block_78:
    if (dead_time == 0x40)
    {
        goto block_80;
    }
    iVar11_1 = 0;
    if (dead_time != 0x80)
    {
        goto block_81;
    }
block_80:
    FUN_80132110();
    iVar11_1 = 0;
block_81:
loop_82:
    iVar7 = iVar11_1 * 2;
    if (iVar11_1 == 0x0014)
    {
        goto block_86;
    }
    temp_a0_1 = &stk_obj[iVar11_1];
    temp_v1_4 = *temp_a0_1;
    if (temp_v1_4 == obj_id_sav)
    {
        goto block_93;
    }
    iVar11_1 += 1;
    if (temp_v1_4 != -2)
    {
        goto loop_82;
    }
    *temp_a0_1 = obj_id_sav;
    goto block_94;
block_86:
    if ((snd << 0x10) == 0)
    {
        goto block_95;
    }
    var_v0_8 = iVar11_1 - 1;
loop_88:
    temp_a1_3 = var_v0_8;
    iVar11_2 = var_v0_8;
    if (iVar11_2 == -1)
    {
        goto block_91;
    }
    var_v0_8 = temp_a1_3 - 1;
    if (level.objects[stk_obj[iVar11_2]].flags & 0x800)
    {
        goto loop_88;
    }
    var_v0_9 = temp_a1_3 << 0x10;
    if (iVar11_2 != -1)
    {
        goto block_92;
    }
block_91:
    var_v0_9 = 0 << 0x10;
block_92:
    iVar7 = var_v0_9 >> 0xF;
    *(stk_obj + iVar7) = obj_id_sav;
    goto block_94;
block_93:
    *temp_a0_1 = obj_id_sav;
block_94:
    *(stk_snd + iVar7) = snd;
block_95:
    return;
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/sound", setvol);*/

void setvol(s16 param_1)
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
                vol_l(((PS1_SoundVolume * var_s4_1) >> 7), temp_s3_1),
                vol_r(((PS1_SoundVolume * var_s4_1) >> 7), temp_s3_1)
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
            (temp_v1_1 = sound_table[pile_snd[temp_v0_3].index].flags,
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
                vol_l(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe);
                vol_r(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe);
                temp_s3_2 = SsUtKeyOn(
                    PS1_SoundVabIds[pile_snd[temp_v0_3].index],
                    pile_snd[temp_v0_3].prog,
                    pile_snd[temp_v0_3].tone,
                    pile_snd[temp_v0_3].note,
                    0x0040,
                    vol_l(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe),
                    vol_r(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe)
                );
                SsUtSetVVol(
                    temp_s3_2,
                    vol_l(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe),
                    vol_r(((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), pile_snd[temp_v0_3].field7_0xe)
                );
            }
            else
            {
                temp_s3_2 = SsUtKeyOn(PS1_SoundVabIds[pile_snd[temp_v0_3].index], pile_snd[temp_v0_3].prog, pile_snd[temp_v0_3].tone, pile_snd[temp_v0_3].note, 0x0040, ((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE), ((PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE));
                SsUtSetVVol(temp_s3_2, (PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE, (PS1_SoundVolume * var_s4_1 * pile_snd[temp_v0_3].vol) >> 0xE);
            }
            if (temp_s3_2 != -1)
            {
                FUN_80166d20(param_1);
                voice_table[temp_s3_2].id = param_1;
                voice_table[temp_s3_2].field1_0x2 = var_s4_1;
                voice_table[temp_s3_2].field2_0x4 = pile_snd[temp_v0_3].field7_0xe;
                voice_table[temp_s3_2].field3_0x6 = pile_snd[temp_v0_3].index;
                if (((u8) sound_table[pile_snd[temp_v0_3].index].flags >> 4) & 1)
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
                pile_snd[temp_v0_3].prog = sound_table[pile_snd[temp_v0_3].index].prog;
                pile_snd[pt_pile_snd].tone = sound_table[pile_snd[temp_v0_3].index].tone;
                pile_snd[pt_pile_snd].note = sound_table[pile_snd[temp_v0_3].index].note;
                pile_snd[pt_pile_snd].vol = sound_table[pile_snd[temp_v0_3].index].volume;
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
                vol_l(((PS1_SoundVolume * var_s4_1 * sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1);
                vol_r(((PS1_SoundVolume * var_s4_1 * sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1);
                SsUtSetVVol(
                    temp_s3_2,
                    vol_l(((PS1_SoundVolume * var_s4_1 * sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1),
                    vol_r(((PS1_SoundVolume * var_s4_1 * sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE), temp_s3_1)
                );
            }
            else
            {
                temp_a1_3 = (PS1_SoundVolume * (var_s4_1) * sound_table[voice_table[temp_s3_2].field3_0x6].volume) >> 0xE;
                SsUtSetVVol(temp_s3_2, temp_a1_3, temp_a1_3);
            }

        }
    }
}

/*
attempts: 2
tried gotos-only also
*/
/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);*/

void FUN_80168f48(void)
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
  
  if ((D_801CEFCC != 0) && !((level.objects[D_801CEFCE].flags & FLG(OBJ_ACTIVE)))
     ) {
    PS1_StopPlayingSnd(0x16);
  }
  psVar4 = &voice_table[0].field3_0x6;
  pVVar5 = &voice_table[0];
  iVar6 = 0;
  while (iVar6 <= 0x18) {
    iVar3 = pVVar5->id;
    if (
      (
        (-1 < iVar3 && !(level.objects[iVar3].flags & FLG(OBJ_ACTIVE))) ||
        (iVar3 == -2 && *psVar4 != -1)
      ) &&
      ((sound_table[voice_table[iVar6].field3_0x6].flags >> 4 & 1) != 0)
    )
    {
      sVar2 = *psVar4; /* ??? */
      SsUtKeyOff(iVar6,PS1_SoundVabIds[*psVar4],sound_table[*psVar4].prog,sound_table[*psVar4].tone,
                 sound_table[*psVar4].note);
      voice_is_working[iVar6] = 0;
      sVar2 = 0;
      while (sVar2 != 0x14 && stk_obj[sVar2] != pVVar5->id) {
        sVar2++;
      }
      if (sVar2 < 0x14) {
        stk_snd[sVar2] = -1;
      }
      pVVar5->id = -2;
      *psVar4 = -1;
    }
    iVar6 = iVar6 + 1;
    psVar4 = psVar4 + 6;
    pVVar5 = pVVar5 + 1;
  }
}