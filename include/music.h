#ifndef MUSIC_H
#define MUSIC_H

#include "common.h"
#include "LIBCD.H"
#include "LIBSND.H"
#include "LIBGPU.H"
#include "psyq_3_0_missing/LIBGPU.H"
#include "psyq_3_0_missing/STDLIB.H"
#include "psyq_3_0_missing/LIBAPI.H"
#include "psyq_3_0_missing/LIBETC.H"
#include "sound.h"
#include "loading_794DC.h"

typedef struct MusicCommand
{
    u8 cmd_and_flags;
    u8 param;
} MusicCommand;

/* .data */
extern MusicCommand PS1_LevelMusicTable[7][22][4];
extern s16 D_801C4948[92];
extern s16 D_801C4A00[92];
extern u8 PS1_Music_Vol[112];
extern s32 D_801C4B28[4];

/* .data */
extern s16 D_801CEEA4;
extern s16 D_801CEEA6;
extern s16 D_801CEEA8;
extern s16 PS1_Mark_counter;
extern s16 PS1_Music_access_num;
extern u8 PS1_Music_pcom;
extern s16 D_801CEEB8;
extern s16 D_801CEEBA;
extern s16 D_801CEEBC;
extern u8 s_s_801ceec0[4];
extern u8 s_idle_801ceec4[5];
extern u8 s_busy_801ceecc[5];
extern u8 s_yes_801ceed4[4];
extern u8 s_no_801ceed8[3];

/**/
extern s16 D_801E64B0;
extern s16 PS1_ScrollLockedAudio;
extern CdlLOC D_801F41D0[54];
extern s32 D_801F7CA8;
extern s16 PS1_LevelMusic_World;
extern s16 PS1_LevelMusic_Level;
extern s16 PS1_LevelMusic_CmdInd;
extern s16 D_801F9940; /* enum? */
extern s32 PS1_CurTrack;
extern u8 PS1_Music_etat;
extern u8 PS1_Music_track;
extern u8 PS1_Music_Amin;
extern u8 PS1_Music_Asec;
extern u8 PS1_Music_Aframe;
extern u8 PS1_Music_LevelHL;
extern s16 PS1_Music_Complete_data;
extern s16 PS1_Music_Fade;
extern s32 PS1_Music_Fin[54];
extern s16 PS1_Music_Ready_data;
extern s16 PS1_Music_fadeout;
extern s16 PS1_Music_ind_fade;
extern s32 PS1_Music_intr_compl;
extern s32 PS1_Music_intr_datar;
extern u8 PS1_Music_occupe;
extern s16 PS1_Music_will_anticip;
extern s16 D_801F5798;
extern s16 D_801E4D10; /* never read */
extern s32 D_801E5240;
extern s32 D_801E57C0[54];
extern s32 D_801F42A8[54];
extern s16 D_801F5248;
extern s16 D_801F7ED0;
extern s16 PS1_Mark_access_num;
extern s16 PS1_Mark_seq_num;
extern s16 PS1_Mark_data;
extern CdlLOC D_801F4E68; /* last time i checked held the data that was at 801f41dc? */
extern u8 PS1_CdMode;
extern s32 D_801F54B0[54];
extern s32 D_801F7AA8; /* type? */
extern s32 D_801F7D88[54];
extern u32 PS1_TrackSizes[54];
extern s16 PS1_TracksExist[54];
extern s16 D_801E4B78;
extern s16 D_801FAA50;
extern s16 D_801F7A90[4];
extern s16 D_801F7C80; /* volume related */
extern CdlLOC D_801E4EF8;
extern s32 D_801F4FA0;
extern s16 D_801FA570;

void FUN_80130048(void);
void PS1_CdReadyCallback(s32 status, u8 *result);
void PS1_CdSyncCallback(s32 status, u8 *result);
void PS1_Mark_Callback(s16 access_num, s16 seq_num, s16 data);
void FUN_8013045c(void);
void PS1_SsSetSerialVolA(s16 vol);
void FUN_80130540(void);
void PS1_Cd_Callbacks_Disable(void);
void PS1_Mark_Callback_Disable(void);
void PS1_Cd_Callbacks_Enable(void);
void PS1_Mark_Callback_Enable(void);
void PS1_InitMusic(void);
void FUN_8013066c(void);
void FUN_80130684(void);
void FUN_801309b0(void);
u8 FUN_801309b8(u8 param_1, u8 param_2, u8 *param_3, u8 param_4);
void FUN_80130a98(CdlLOC *param_1, CdlLOC *param_2, CdlLOC *param_3);
void FUN_80130b18(u32 param_1, CdlLOC *param_2);
s32 FUN_80130bc4(CdlLOC loc);
s32 FUN_80130c58(s32 param_1);
s32 FUN_80130d00(s32 param_1, s32 param_2);
u8 PS1_InitTracks(void);
s16 FUN_80131474(s16 *param_1, s16 param_2, s16 param_3);
void FUN_801314c4(void);
void PS1_PlayMusic(void);
void playLevelMusic(s16 world, s16 lvl);
void FUN_80131c28(void);
void start_cd_suspence(void);
void start_cd_replay(void);
void FUN_80131c94(void);
void FUN_80131cc0(void);
void start_cd_perdu(void);
void start_cd_rap(void);
void start_cd_gameover(void);
void start_cd_continue(void);
s32 FUN_80131db8(void);
void PS1_Cd_Pause(void);
void stop_cd(void);
void PS1_Volume_Zero(void);
void FUN_80131e40(void);
void FUN_80131e5c(void);
void PS1_Music_Apply_Fade(void);
void FUN_8013202c(void);
void change_audio_track_moskito_acc(void);
void change_audio_track_moskito_dec(void);
void change_audio_track_puit(void);
void FUN_80132110(void);
void FUN_80132148(void);
void FUN_80132150(void);
void FUN_80132158(void);
void FUN_80132160(void);
void PS1_SetMusicVolume(s16 param_1);
void FUN_801321fc(void);
void FUN_80132244(void);

#endif