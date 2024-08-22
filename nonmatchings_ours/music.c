#include "music.h"

/* attempts: 2 */
/*INCLUDE_ASM("asm/nonmatchings/music", FUN_801309b8);*/

u8 FUN_801309b8(u8 param_1, u8 param_2, u8 *param_3, u8 param_4)
{
    u8 temp_v1_1;
    u8 var_v0;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a1;
    u8 temp_v1_2;
    u8 var_a0;
    u8 var_v1;
    u8 temp_t0;
    u8 var_a2;
    int new_var;

    temp_v1_1 = btoi(param_1) + btoi(param_2) + btoi(*param_3);
    new_var = temp_v1_1 + 0xFF;
    if (param_4 >= temp_v1_1)
    {
        *param_3 = itob(temp_v1_1);
        var_v0 = 0;
    }
    else
    {
        temp_v1_1 = ((new_var) - param_4);
        *param_3 = itob(temp_v1_1);
        var_v0 = 1;
    }
    return var_v0;
}

u8 FUN_801309b8(u8 param_1, u8 param_2, u8 *param_3, u8 param_4)
{
    u8 temp_v1_1;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;
    u8 temp_v1_2;
    u32 var_a0;
    u32 var_v1;
    u8 temp_t0;
    u8 var_a2;
    u8 var_v0;

    temp_v1_1 =
        ((param_1)/16*10 + (param_1)%16) +
        ((param_2)/16*10 + (param_2)%16) +
        ((*param_3)/16*10 + (*param_3)%16);

    temp_a0_2 = temp_v1_1 & 0xFF;
    if ((param_4) >= temp_v1_1)
    {
        var_v0 = 0;
        var_v1 = temp_a0_2 / 10U;
        var_a0 = temp_a0_2 % 10U;
    }
    else
    {
        var_v0 = 1;
        temp_v1_2 = (((u8) temp_v1_1 + 0xFF) - param_4) & 0xFF;
        var_v1 = temp_v1_2 / 10U;
        var_a0 = temp_v1_2 % 10U;
    }
    *param_3 = (var_v1 * 0x10) + var_a0;
    return var_v0;
}

/* too many nops somehow... and even worse on current maspsx/decomp.me */
/*INCLUDE_ASM("asm/nonmatchings/music", FUN_80130b18);*/

void FUN_80130b18(u32 param_1, CdlLOC *param_2)
{
    u32 temp_hi_1;
    u32 temp_hi_2;
    u32 temp_lo_1;
    u32 temp_lo_2;

    param_2->sector = itob(param_1 % 75);
    temp_lo_1 = param_1 / 75;
    param_2->second = itob(temp_lo_1 % 60);
    param_2->minute = itob(temp_lo_1 / 60);
}

/*
close, but dunno what to do about the remaining issues
permuter "fixed" the ending by returning volatile unsigned short
*/
/*INCLUDE_ASM("asm/nonmatchings/music", PS1_InitTracks);*/

void PS1_InitTracks(void)
{
  uint uVar2;
  uint *puVar3;
  CdlLOC *uVar4;
  u_long size;
  s32 uVar5;
  s32 uVar6;
  short *tracksExist;
  int iVar7;
  s32 *trackSizes;
  CdlLOC *pCVar8;
  s32 cnt_1;
  CdlLOC local_118;
  s32 local_110 [54];
  s32 local_38;
  s32 local_30;
  
  trackSizes = PS1_TrackSizes;
  tracksExist = PS1_TracksExist;
  cnt_1 = 0;
  do {
    size = PS1_TrkFiles[cnt_1].file.size;
    if (size != 0) {
      *trackSizes = (size >> 0xb) - 0x28;
      *tracksExist = 1;
    }
    else {
      *tracksExist = 0;
      *trackSizes = 0;
    }
    trackSizes = trackSizes + 1;
    cnt_1 = cnt_1 + 1;
    tracksExist = tracksExist + 1;
  } while (cnt_1 < 53);
  cnt_1 = 0;
  do {
    if (PS1_TracksExist[cnt_1] != 0) {
      D_801F41D0[cnt_1] = PS1_TrkFiles[cnt_1].file.pos;
      iVar7 = ((PS1_TrkFiles[cnt_1].file.size) >> 0xb) - 0x28;
      PS1_TrackSizes[cnt_1] = iVar7;
      FUN_80130b18(iVar7,&local_118);
      local_110[cnt_1] = FUN_80130bc4(local_118);
    }
    cnt_1 = cnt_1 + 1;
  } while (cnt_1 < 0x35);
  uVar5 = FUN_80130c58(0x5dc);
  cnt_1 = 0;
  do {
    if (PS1_TracksExist[cnt_1] != 0) {
      PS1_Music_Fin[cnt_1] = FUN_80130d00(FUN_80130bc4(D_801F41D0[cnt_1]),local_110[cnt_1]);
      if ((uint)PS1_TrackSizes[cnt_1] < 0x5dc) {
        D_801F7D88[cnt_1] = FUN_80130d00(FUN_80130bc4(D_801F41D0[cnt_1]),local_110[cnt_1]);
      }
      else {
        D_801F7D88[cnt_1] = FUN_80130d00(FUN_80130bc4(D_801F41D0[cnt_1]),uVar5);
      }
    }
    cnt_1 = cnt_1 + 1;
  } while (cnt_1 < 0x35);
  local_38 = FUN_80130c58(0x56c);
  cnt_1 = 0;
  do {
    if (PS1_TracksExist[cnt_1] != 0) {
      local_110[cnt_1] = FUN_80130c58(PS1_TrackSizes[cnt_1] - 112);
      pCVar8 = &D_801F41D0[cnt_1];
      D_801F42A8[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_110[cnt_1]);
      if ((uint)PS1_TrackSizes[cnt_1] < 0x5dc) {
        (&D_801F7AA8)[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_110[cnt_1]);
      }
      else {
        (&D_801F7AA8)[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_38);
      }
      
    }
    cnt_1 = cnt_1 + 1;
  } while (cnt_1 < 0x35);
  local_30 = FUN_80130c58(0x57c);
  
  for (cnt_1 = 0; cnt_1 < 0x35; cnt_1++) {
    if (PS1_TracksExist[cnt_1] != 0) {
      local_110[cnt_1] = FUN_80130c58(PS1_TrackSizes[cnt_1] - 96);
      pCVar8 = &D_801F41D0[cnt_1];
      D_801E57C0[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_110[cnt_1]);
      if ((uint)PS1_TrackSizes[cnt_1] < 0x5dc) {
        D_801F54B0[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_110[cnt_1]);
      }
      else {
        D_801F54B0[cnt_1] = FUN_80130d00(FUN_80130bc4(*pCVar8),local_30);
      }
      
    }
  }
}

/* matches, but too many unknowns, hard to read, unsure about some labels */
/*INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayMusic);*/

void PS1_PlayMusic(void)
{
    s16 done;
    u8 *mode;
    CdlLOC unk_3;
    CdlLOC unk_4;
    CdlLOC unk_1;
    CdlLOC *unk_2;

    D_801FA570 = false;
    done = false;
    if (++PS1_LevelMusic_CmdInd == 4) /* TODO: what should i take LEN() of? */
        PS1_LevelMusic_CmdInd = 0;
    
    while (!done)
    {
        mode = &PS1_CdMode;
        D_801F9940 = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0xF;
        PS1_Music_will_anticip = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0x10;
        PS1_Music_fadeout = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0x80;
        D_801F7ED0 = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0x20;
        switch (D_801F9940)
        {
        case 1:
            D_801CEEBC = false;
            *mode = CdlModeRept | CdlModeAP | CdlModeDA;
            PS1_CurTrack = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].param;
            if (PS1_TracksExist[PS1_CurTrack])
            {
                PS1_Music_pcom = CdlSetmode;
                CdControl(PS1_Music_pcom, mode, null);
                unk_2 = &unk_1;
                if (D_801F7ED0)
                {
                    FUN_80130b18(D_801C4B28[D_801CEEA4++], unk_2);
                    FUN_80130a98(&D_801F41D0[PS1_CurTrack], unk_2, &D_801E4EF8);
                    if (D_801CEEA4 == (s16) LEN(D_801C4B28))
                        D_801CEEA4 = 0;
                    FUN_80130b18(1410, &unk_3);
                    FUN_80130a98(&D_801E4EF8, &unk_3, &unk_4);
                    D_801E5240 = FUN_80130bc4(unk_4);
                    PS1_Music_pcom = CdlSetloc;
                    CdControl(PS1_Music_pcom, &D_801E4EF8, null);
                }
                else
                {
                    PS1_Music_pcom = CdlSetloc;
                    CdControl(PS1_Music_pcom, (u_char *)&D_801F41D0[PS1_CurTrack], null);
                }

                done = true;
                if (D_801CEFD8 == 0)
                {
                    PS1_Music_pcom = CdlPlay;
                    CdControl(PS1_Music_pcom, null, null);
                }

                if (PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0x40)
                    FUN_80131e5c();
                else
                {
                    PS1_Music_Fade = 0;
                    PS1_SsSetSerialVolA(PS1_Music_Vol[PS1_CurTrack] * D_801F7C80 >> 7);
                }
            }
            else
            {
                D_801F9940 = 0;
                D_801CEEBC = true;
                done = true;
            }
            break;
        case 2:
            D_801F4FA0 = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].param;
            D_801CEEA6 = true;
            SsSeqPlay(PS1_Music_access_num, SSPLAY_PLAY, 1);
            PS1_Mark_Callback_Enable();
            if (PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].cmd_and_flags & 0x40)
            {
                SsSeqSetVol(PS1_Music_access_num, 0, 0);
                SsSeqSetCrescendo(PS1_Music_access_num, 127, 240);
            }
            FUN_801314c4();
            done = true;
            break;
        case 3:
            PS1_LevelMusic_CmdInd = PS1_LevelMusicTable[PS1_LevelMusic_World][PS1_LevelMusic_Level][PS1_LevelMusic_CmdInd].param;
            break;
        case 0:
            done = true;
            break;
        }
    }
}