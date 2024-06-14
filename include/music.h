#ifndef MUSIC_H
#define MUSIC_H

#include "common.h"
#include "psyq_3_0/LIBCD.H"
#include "psyq_3_0/LIBSND.H"
#include "psyq_3_0/LIBGPU.H"
#include "sound.h"
#include "loading_794DC.h"

/**/
extern s16 D_801E64B0;
extern s16 PS1_ScrollLockedAudio;

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
void PS1_InitTracks(void);
u8 FUN_80131474(s16 *param_1, s16 param_2, s16 param_3);
void FUN_801314c4(void);
void PS1_PlayMusic(void);
void playLevelMusic(s16 world, s16 level);
void start_cd_gros_rayman(void);
void start_cd_suspence(void);
void start_cd_credits(void);
void FUN_80131c94(void);
void start_cd_gagne(void);
void PS1_PlayDeathMusic(void);
void PS1_PlayCDTrack_0_3(void);
void start_cd_gameover(void);
void start_cd_continue(void);
s32 FUN_80131db8(void);
void FUN_80131dc8(void);
void stop_cd(void);
void FUN_80131e18(void);
void FUN_80131e40(void);
void FUN_80131e5c(void);
void FUN_80131e94(void);
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