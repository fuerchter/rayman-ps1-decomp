#include "music.h"

/*
matches, but ... unknowns?
any common.h return type seems to work
c89 3.6.6.4 The return statement: behavior is undefined
*/
/*INCLUDE_ASM("asm/nonmatchings/music", PS1_InitTracks);*/

u8 PS1_InitTracks(void)
{
  u32 size;
  s32 unk_1;
  CdlLOC unk_2;
  s32 unk_3 [54];
  s32 unk_4;
  s32 unk_5;
  CdlLOC *unk_6;
  s32 unk_7;
  s32 unk_8 = true;
  s32 *track_sizes = PS1_TrackSizes;
  s16 *tracks_exist = PS1_TracksExist;
  s32 i = 0;

  while (i < (s16) LEN(PS1_TrkFiles))
  {
    size = PS1_TrkFiles[i].file.size;
    if (size != 0)
    {
      *track_sizes = (size >> 11) - 40;
      *tracks_exist = unk_8;
    }
    else
    {
      *tracks_exist = false;
      *track_sizes = 0;
    }
    track_sizes++;
    tracks_exist++;
    i++;
  }

  for (i = 0; i < (s16) LEN(PS1_TrkFiles); i++)
  {
    if (PS1_TracksExist[i] != 0)
    {
      D_801F41D0[i] = PS1_TrkFiles[i].file.pos;
      unk_1 = (PS1_TrkFiles[i].file.size >> 11) - 40;
      PS1_TrackSizes[i] = unk_1;
      FUN_80130b18(unk_1, &unk_2);
      unk_3[i] = FUN_80130bc4(unk_2);
    }
  }
  
  unk_4 = FUN_80130c58(1500);
  for (i = 0; i < (s16) LEN(PS1_TrkFiles); i++)
  {
    if (PS1_TracksExist[i] != 0)
    {
      PS1_Music_Fin[i] = FUN_80130d00(FUN_80130bc4(D_801F41D0[i]), unk_3[i]);
      if (PS1_TrackSizes[i] < 1500)
        D_801F7D88[i] = FUN_80130d00(FUN_80130bc4(D_801F41D0[i]), unk_3[i]);
      else
        D_801F7D88[i] = FUN_80130d00(FUN_80130bc4(D_801F41D0[i]), unk_4);
    }
  }

  unk_5 = FUN_80130c58(1388);
  for (i = 0; i < (s16) LEN(PS1_TrkFiles); i++)
  {
    if (PS1_TracksExist[i] != 0)
    {
      unk_3[i] = FUN_80130c58(PS1_TrackSizes[i] - 112);
      unk_6 = &D_801F41D0[i];
      D_801F42A8[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_3[i]);
      if (PS1_TrackSizes[i] < 1500)
        (&D_801F7AA8)[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_3[i]);
      else
        (&D_801F7AA8)[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_5);      
    }
    
  }

  unk_7 = FUN_80130c58(1404);
  for (i = 0; i < (s16) LEN(PS1_TrkFiles); i++)
  {
    if (PS1_TracksExist[i] != 0)
    {
      unk_3[i] = FUN_80130c58(PS1_TrackSizes[i] - 96);
      unk_6 = &D_801F41D0[i];
      D_801E57C0[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_3[i]);
      if (PS1_TrackSizes[i] < 1500)
        D_801F54B0[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_3[i]);
      else
        D_801F54B0[i] = FUN_80130d00(FUN_80130bc4(*unk_6), unk_7);      
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