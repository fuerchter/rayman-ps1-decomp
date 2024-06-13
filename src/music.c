#include "music.h"

extern u8 s_s_801ceec0[4];
extern u8 s_idle_801ceec4[5];
extern u8 s_busy_801ceecc[5];
extern u8 s_yes_801ceed4[4];
extern u8 s_no_801ceed8[3];
extern CdlLOC D_801F41D0[54];
extern s32 D_801F7CA8;
extern s16 D_801F84B0;
extern s16 D_801F9940; /* enum? */
extern s32 PS1_CurTrack;
extern s16 PS1_LevelMusic_Level;
extern s16 PS1_LevelMusic_World;
extern u8 PS1_Music_Aframe;
extern u8 PS1_Music_Amin;
extern u8 PS1_Music_Asec;
extern s16 PS1_Music_Complete_data;
extern s16 PS1_Music_Fade;
extern s32 PS1_Music_Fin[54];
extern s16 PS1_Music_Ready_data;
extern s16 PS1_Music_access_num;
extern u8 PS1_Music_etat;
extern s16 PS1_Music_fadeout;
extern s16 PS1_Music_ind_fade;
extern s32 PS1_Music_intr_compl;
extern s32 PS1_Music_intr_datar;
extern u8 PS1_Music_occupe;
extern u8 PS1_Music_pcom;
extern u8 PS1_Music_track;
extern s16 PS1_Music_will_anticip;
extern s16 D_801F5798;
extern s16 D_801CEEBC;
extern s16 D_801E4D10; /* never read */
extern s32 D_801E5240;
extern s32 D_801E57C0[54];
extern s32 D_801F42A8[54];
extern s16 D_801F5248;
extern s16 D_801F7ED0;
extern u8 PS1_Music_LevelHL;
extern s16 D_801CEEAA;
extern s16 D_801D7A70;
extern s16 D_801E4BD0;
extern s16 D_801F8198;
extern s16 D_801CEEA6;
extern s16 D_801CEEA8;
extern CdlLOC D_801F4E68; /* last time i checked held the data that was at 801f41dc? */

/* no StopPAD or StopCallback in psyq 3.0 headers... */
void StopPAD(void);
void StopCallback(void);

const u8 s__CDPlayer_TEST_80125c28[] = "\n\n\n\t\t CD-Player TEST\n";
const u8 s_Fade02d_80125c40[] = "Fade:%02d ";
const u8 s_ind_faded_80125c4c[] = "ind_fade:%d\n";
const u8 s_stat_02x_trackd_80125c5c[] = "stat  =%02x track=%d";
const u8 s_Ready_data_d_Complete_d_80125c74[] = "Ready data #%d, Complete #%d\n";
const u8 s_occuped_etat_d_pcomd_80125c94[] = "occupe=%d, etat= %d, pcom=%d\n";
const u8 s_intr_datar3d_intr_compl3d_80125cb4[] = "intr_datar=%3d intr_compl=%3d\n";
const u8 s_Deb_2d2d2d_80125cd4[] = "Deb: %2d:%2d:%2d\n";
const u8 s_Pos_2d2d2d_08x_80125ce8[] = "Pos: %2d:%2d:%2d (%08x)\n";
const u8 s_Fin_08x_80125d04[] = "Fin: %08x\n";
const u8 s_Num_seqddd_typd_80125d10[] = "Num_seq:%d-%d-%d typ:%d\n";
const u8 s_iseosd_80125d2c[] = "iseos:%d\n";
const u8 s_will_anticips_fadeouts_80125d38[] = "will anticip:%s  fadeout:%s\n";
const u8 s_2d_markddd_80125d58[] = "%2d mark:%d-%d-%d\n";

/* B848 80130048 -O2 -msoft-float */
void FUN_80130048(void)
{
    FUN_801a7ae4();
    StopPAD();
    ResetGraph(3);
    stop_cd();
    CdSync(null, null);
    SsVabClose(D_801F5798);
    SsEnd();
    StopCallback();
}

/* B8AC 801300AC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/music", PS1_CdReadyCallback);
#else
void PS1_CdReadyCallback(s32 status, u8 *result)
{
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
        D_801F7CA8 = (btoi(PS1_Music_Amin) << 16) + (btoi(PS1_Music_Asec) << 8) + btoi(PS1_Music_Aframe);
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

    __asm__("nop\nnop");
}
#endif

/* BB6C 8013036C -O2 -msoft-float */
void PS1_CdSyncCallback(s32 status, u8 *result)
{
    PS1_Music_Complete_data++;
    PS1_Music_intr_compl = status;
    if (status == CdlComplete)
    {
        D_801E4D10 = false;
        PS1_Music_Ready_data = 0;
        if (D_801F9940 == 1 && PS1_Music_pcom == CdlPause && !D_801CEFD8)
        {
            if (D_801F5248)
            {
                D_801F9940 = 0;
                D_801F5248 = false;
            }
            else
                PS1_PlayMusic();
        }
    }
}

/* BC28 80130428 -O2 -msoft-float */
void FUN_80130428(s16 param_1, s16 param_2, s16 param_3)
{
    D_801D7A70 = param_1;
    D_801E4BD0 = param_2;
    D_801F8198 = param_3;
    D_801CEEAA++;
}

/* BC5C 8013045C -O2 -msoft-float */
void FUN_8013045c(void)
{
    if (D_801CEEA6 && !SsIsEos(PS1_Music_access_num, 0))
    {
        PS1_PlayMusic();
        D_801CEEA6 = false;
    }
    if (D_801CEEA8)
    {
        D_801CEEA8 = false;
        PS1_Music_pcom = CdlSetloc;
        CdControl(PS1_Music_pcom, &D_801F4E68, null);
    }
    if (PS1_Music_Fade != 0 && !D_801CEFD8)
        FUN_80131e94();
}

/* BD14 80130514 -O2 -msoft-float */
void PS1_SsSetSerialVolA(s16 vol)
{
    SsSetSerialVol(SS_SERIAL_A, vol, vol);
}

/* BD40 80130540 -O2 -msoft-float */
void FUN_80130540(void)
{
    ResetCallback();
}

/* BD60 80130560 -O2 -msoft-float */
void PS1_Cd_Callbacks_Disable(void)
{
    CdSyncCallback(null);
    CdReadyCallback(null);
}

/* BD88 80130588 -O2 -msoft-float */
void FUN_80130588(void)
{
    SsSetMarkCallback(PS1_Music_access_num, 0, null);
}

/*INCLUDE_ASM("asm/nonmatchings/music", FUN_801305b4);*/

/* BDB4 801305B4 -O2 -msoft-float */
void PS1_Cd_Callbacks_Enable(void)
{
    CdSyncCallback(PS1_CdSyncCallback);
    CdReadyCallback(PS1_CdReadyCallback);
}

INCLUDE_ASM("asm/nonmatchings/music", FUN_801305ec);

INCLUDE_ASM("asm/nonmatchings/music", PS1_InitMusic);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013066c);

/* BE84 80130684 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/music", FUN_80130684);
#else
void FUN_80130684(void)
{
  u8 *occupe_str;
  u8 *anticip_str;
  u8 *fadeout_str;
  
  FntPrint(s__CDPlayer_TEST_80125c28);
  FntPrint(s_Fade02d_80125c40, PS1_Music_Fade);
  FntPrint(s_ind_faded_80125c4c, PS1_Music_ind_fade);
  FntPrint(s_stat_02x_trackd_80125c5c, btoi(PS1_Music_etat), PS1_Music_track);
  
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
    btoi(D_801F41D0[PS1_CurTrack].minute), 
    btoi(D_801F41D0[PS1_CurTrack].second),
    btoi(D_801F41D0[PS1_CurTrack].sector)
  );
  FntPrint(
    s_Pos_2d2d2d_08x_80125ce8,
    btoi(PS1_Music_Amin), 
    btoi(PS1_Music_Asec), 
    btoi(PS1_Music_Aframe),
    D_801F7CA8
  );
  FntPrint(s_Fin_08x_80125d04, PS1_Music_Fin[PS1_CurTrack]);
  FntPrint(s_Num_seqddd_typd_80125d10, PS1_LevelMusic_World, PS1_LevelMusic_Level, D_801F84B0, D_801F9940);
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

  __asm__("nop\nnop\nnop\nnop");
}
#endif

void FUN_801309b0(void) {}

INCLUDE_ASM("asm/nonmatchings/music", FUN_801309b8);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130a98);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130b18);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130bc4);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130c58);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130d00);

INCLUDE_ASM("asm/nonmatchings/music", PS1_InitTracks);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131474);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801314c4);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayMusic);

INCLUDE_ASM("asm/nonmatchings/music", playLevelMusic);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gros_rayman);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_suspence);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_credits);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131c94);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gagne);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayDeathMusic);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayCDTrack_0_3);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gameover);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_continue);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131db8);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131dc8);

INCLUDE_ASM("asm/nonmatchings/music", stop_cd);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e18);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e40);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e5c);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e94);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013202c);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_moskito_acc);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_moskito_dec);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_puit);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80132110);

void FUN_80132148(void) {}

void FUN_80132150(void) {}

void FUN_80132158(void) {}

void FUN_80132160(void) {}

INCLUDE_ASM("asm/nonmatchings/music", PS1_SetMusicVolume);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801321fc);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80132244);
