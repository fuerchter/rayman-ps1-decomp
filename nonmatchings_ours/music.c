#include "music.h"

/*
matches, but ...
unk_1, weird / 16 calculation (similar to * 0.64???)
*/
/*INCLUDE_ASM("asm/nonmatchings/music", FUN_801300ac);*/

void FUN_801300ac(s32 status, u8 *result)
{
    s32 unk_1 = 0xf;

    PS1_Music_intr_datar = status;
    switch (status)
    {
    case CdlDataReady:
        D_801E4D10 = false;
        PS1_Music_Ready_data++;
        PS1_Music_etat = result[0];
        PS1_Music_track = result[1];
        PS1_Music_Amin = result[3];
        PS1_Music_Asec = result[4];
        PS1_Music_Aframe = result[5];
        PS1_Music_LevelHL = result[6] + result[7];
        D_801F7CA8 =
            (((PS1_Music_Amin / 16) * 10 + (PS1_Music_Amin & unk_1)) << 16) +
            (((PS1_Music_Asec / 16) * 10 + (PS1_Music_Asec & unk_1)) << 8) +
            ((PS1_Music_Aframe / 16) * 10 + (PS1_Music_Aframe & unk_1));
        if (PS1_Music_fadeout && D_801F7CA8 > D_801F42A8[PS1_CurTrack])
        {
            PS1_Music_fadeout = false;
            FUN_80131e40();
        }
        if (PS1_Music_will_anticip && D_801F7CA8 > D_801E57C0[PS1_CurTrack])
        {
            PS1_Music_will_anticip = false;
            PS1_PlayMusic();
        }
        if (D_801F7ED0 && D_801F7CA8 > D_801E5240)
        {
            D_801F7ED0 = false;
            FUN_80131e40();
        }
        if (D_801CEFD8)
            CdControl(CdlPause, null, null);
        break;
    case CdlDiskError:
        D_801E4D10 = true;
        D_801CEEBC = true;
        break;
    case CdlDataEnd:
        D_801CEEBC = true;
        if (D_801F5248)
        {
            D_801F5248 = false;
            D_801F9940 = 0;
        }
        if (D_801F9940 == 1)
            PS1_PlayMusic();
        break;
    }
}

/*
matches, but ...
unk_1, D_801F41D0 duplicate loads, weird / 16 calculation (similar to * 0.64???)
*/
/*INCLUDE_ASM("asm/nonmatchings/music", FUN_80130684);*/

void FUN_80130684(void)
{
  u8 *occupe_str;
  u8 *anticip_str;
  u8 *fadeout_str;
  s32 unk_1 = 0xf;
  
  FntPrint(s__CDPlayer_TEST_80125c28);
  FntPrint(s_Fade02d_80125c40, PS1_Music_Fade);
  FntPrint(s_ind_faded_80125c4c, PS1_Music_ind_fade);
  FntPrint(
    s_stat_02x_trackd_80125c5c,
    (PS1_Music_etat / 16) * 10 + (PS1_Music_etat & unk_1),
    PS1_Music_track
  );
  
  if (PS1_Music_occupe)
    occupe_str = s_idle_801ceec4;
  else
    occupe_str = s_busy_801ceecc;
  FntPrint(s_s_801ceec0, occupe_str);
  FntPrint(s_Ready_data_d_Complete_d_80125c74, PS1_Music_Ready_data, PS1_Music_Complete_data);
  FntPrint(s_occuped_etat_d_pcomd_80125c94, PS1_Music_occupe, PS1_Music_etat, PS1_Music_pcom);
  FntPrint(s_intr_datar3d_intr_compl3d_80125cb4, PS1_Music_intr_datar, PS1_Music_intr_compl);
  FntPrint(
    s_Deb_2d2d2d_80125cd4,
    (D_801F41D0[PS1_CurTrack].minute / 16) * 10 + (D_801F41D0[PS1_CurTrack].minute & unk_1), 
    (D_801F41D0[PS1_CurTrack].second / 16) * 10 + (D_801F41D0[PS1_CurTrack].second & unk_1),
    (D_801F41D0[PS1_CurTrack].sector / 16) * 10 + (D_801F41D0[PS1_CurTrack].sector & unk_1)
  );
  FntPrint(
    s_Pos_2d2d2d_08x_80125ce8,
    (PS1_Music_Amin / 16) * 10 + (PS1_Music_Amin & unk_1), 
    (PS1_Music_Asec / 16) * 10 + (PS1_Music_Asec & unk_1), 
    (PS1_Music_Aframe / 16) * 10 + (PS1_Music_Aframe & unk_1),
    D_801F7CA8
  );
  FntPrint(s_Fin_08x_80125d04, PS1_Music_Fin[PS1_CurTrack]);
  FntPrint(s_Num_seqddd_typd_80125d10, PS1_LevelMusic_World, PS1_LevelMusic_Level, 
           D_801F84B0, D_801F9940);
  FntPrint(s_iseosd_80125d2c, SsIsEos(PS1_Music_access_num, 0));
  
  if (PS1_Music_will_anticip)
    anticip_str = s_yes_801ceed4;
  else
    anticip_str = s_no_801ceed8;
  
  if (PS1_Music_fadeout)
    fadeout_str = s_yes_801ceed4;
  else
    fadeout_str = s_no_801ceed8;
  FntPrint(s_will_anticips_fadeouts_80125d38, anticip_str, fadeout_str);
}