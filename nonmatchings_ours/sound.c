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

/* matches, but too much unknown */
/*INCLUDE_ASM("asm/nonmatchings/sound", InitSnd);*/

/* 41BD4 801663D4 -O2 -msoft-float */
void InitSnd(void)
{
    s16 *var_a0;
    s16 *var_v1;
    s32 var_s0;
    s16 test_1;

    var_s0 = 0;
    test_1 = -2;
    var_a0 = stk_obj;
    var_v1 = stk_snd;
    while (var_s0 < 20)
    {
        *var_v1 = 0;
        *var_a0 = test_1;
        var_a0++;
        var_s0++;
        var_v1++;
    }
    pt_pile_snd = 0;
    D_801FA578 = 0;
    indice_ray_wait = 0;
    indice_trz_wait = 2;
    for(var_s0 = 0; var_s0 < 8; var_s0++)
    {
        D_801F7D40[var_s0].field0_0x0 = D_801CEFD0[var_s0];
        D_801F7D40[var_s0].field1_0x1 = -1;
        D_801F7D40[var_s0].field2_0x2 = 0;
        D_801F7D40[var_s0].field3_0x3 = 0;
    }
    for(var_s0 = 0; var_s0 < 24; var_s0++)
        voice_table[var_s0].field0_0x0 = -2;
    
    SsSetSerialAttr(0, 0, 1);
    FUN_80166060(options_jeu.Soundfx * 127 / 20);
    PS1_SetStereoEnabled(options_jeu.StereoEnabled);
    SsUtSetReverbType(2);
    SsUtReverbOn();
    for(var_s0 = 0; var_s0 < 200; var_s0++)
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
      sVar1 = -1;
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
s32 get_voice_obj_snd(s16 id, s16 param_2)
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

/*INCLUDE_ASM("asm/nonmatchings/sound", nettoie_pile_snd);*/

/* 422AC 80166AAC -O2 -msoft-float */
void nettoie_pile_snd(void)
{
  int iVar3;
  s16 iVar4;
  s16 iVar5;
  s16 new_var;
  
  iVar5 = 0;
  if (0 < pt_pile_snd) {
    do {
      if (((uint)pile_snd[iVar5].field8_0x10 < map_time) &&
         (pile_snd[iVar5].field8_0x10 != 0)) {
        iVar4 = iVar5;
        while (iVar4 < pt_pile_snd) {
          iVar3 = iVar4 + 1;
          pile_snd[iVar4].id = pile_snd[iVar3].id;
          pile_snd[iVar4].index = pile_snd[iVar3].index;
          pile_snd[iVar4].prog = pile_snd[iVar3].prog;
          pile_snd[iVar4].tone = pile_snd[iVar3].tone;
          pile_snd[iVar4].note = pile_snd[iVar3].note;
          pile_snd[iVar4].vol = pile_snd[iVar3].vol;
          pile_snd[iVar4].field6_0xc = pile_snd[iVar3].field6_0xc;
          pile_snd[iVar4].field7_0xe = pile_snd[iVar3].field7_0xe;
          pile_snd[iVar4].field8_0x10 = pile_snd[iVar3].field8_0x10;
          pile_snd[iVar4].field9_0x14 = pile_snd[iVar3].field9_0x14;
          iVar4++;
        }
        if (0 < pt_pile_snd) {
          pt_pile_snd = pt_pile_snd + -1;
        }
      }
      else {
        iVar5 = iVar5 + 1;
      }
    } while (iVar5 < pt_pile_snd);
  }
  return;
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

/*INCLUDE_ASM("asm/nonmatchings/sound", FUN_80168f48);*/

/* 44748 80168F48 -O2 -msoft-float */
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
  do {
    iVar3 = pVVar5->id;
    if (
      (
        (-1 < iVar3 && !(level.objects[iVar3].flags & FLG(OBJ_ACTIVE))) ||
        (iVar3 == -2 && *psVar4 != -1)
      ) &&
      ((sound_table[voice_table[iVar6].field3_0x6].flags >> 4 & 1) != 0)
    )
    {
      sVar2 = *psVar4;
      SsUtKeyOff(iVar6,PS1_SoundVabIds[sVar2],sound_table[sVar2].prog,sound_table[sVar2].tone,
                 sound_table[sVar2].note);
      voice_is_working[iVar6] = 0;
      sVar2 = 0;
      new_var = pVVar5->id;
      cur_stk_obj = &stk_obj[sVar2];
      if (stk_obj[sVar2] != new_var) {
        sVar1 = 1;
        do {
          sVar2 = sVar1;
          if (sVar2 == 0x14) break;
          sVar1 = sVar2 + 1;
        } while (stk_obj[sVar2] != new_var);
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
  } while( 0x18 >= iVar6 * 0x10000 >> 0x10 );
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