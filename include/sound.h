#ifndef SOUND_H
#define SOUND_H

#include "common.h"
#include "psyq_3_0/LIBSND.H"
#include "obj_update.h"
#include "loading_794DC.h"
#include "menu/menu_card_7FD3C.h"
#include "ray/ray_32398.h"

typedef struct SoundTableEntry
{
    u8 note;
    u8 prog;
    u8 tone;
    u8 volume;
    u8 flags;
} SoundTableEntry;

typedef struct VoiceTableEntry
{
    s16 field0_0x0;
    s16 field1_0x2;
    s16 field2_0x4;
    s16 field3_0x6;
    u8 field4_0x8;
    u8 field5_0x9;
    u8 field6_0xa;
    u8 field7_0xb;
} VoiceTableEntry;

typedef struct SepInfo
{
    s16 access_num;
    s16 seq_num;
} SepInfo;

typedef struct Unk_801f7d40
{
    u8 field0_0x0;
    s8 field1_0x1;
    u8 field2_0x2;
    u8 field3_0x3;
    u8 field4_0x4;
} Unk_801f7d40;

typedef struct Unk_801f62a0
{
    s16 field0_0x0;
    s16 index;
    s16 prog;
    s16 tone;
    s16 note;
    s16 vol;
    /* not sure about these, but every acces would otherwise be multiplied by 2 */
    s16 field6_0xc;
    s16 field7_0xe;
    s32 field8_0x10;
    s16 field9_0x14;
    s16 field10_0x16;
} Unk_801f62a0;

/* .data */
extern s16 D_801C7D20[8];

void PS1_StopPlayingAllSnd(void);
void FUN_801658e0(void);
void manage_snd_event(Obj *obj);
void PS1_LoadAllFixSound(void);
void PS1_LoadWorldSound(s16 param_1);
void PS1_PlaySnd(s16 sep_ind, s16 l_count);
void PS1_StopPlayingSnd(s16 sep_ind);
s16 PS1_SongIsPlaying(s16 sep_ind);
void FUN_80166018(void);
void SetVolumeSound(s16 vol);
void FUN_801660ac(void);
void FUN_801660e8(void);
void stop_all_snd(void);
void FUN_8016617c(void);
u8 get_pan_snd(Obj *obj);
u8 get_vol_snd(Obj *obj);
void PS1_SetSoundVolume(s16 vol);
void PS1_SetStereoEnabled(s16 enabled);
void InitSnd(void);
void FUN_80166578(void);
s32 last_snd(s16 param_1);
s32 get_pile_obj(s16 param_1);
s32 FUN_80166724(s16 param_1);
s32 FUN_80166790(s16 param_1);
s32 get_voice_obj_snd(s16 param_1, s16 param_2);
void erase_pile_snd(s16 param_1);
void nettoie_pile_snd(void);
void FUN_80166d20(s16 param_1);
u16 FUN_80166d88(s16 param_1);
s32 vol_r(s16 param_1, s16 param_2);
s32 vol_l(s16 param_1, s16 param_2);
void PlaySnd(s16 snd, s16 objId);
void PlaySnd_old(s16 snd);
void setvol(u16 param_1);
void setpan(s16 param_1);
void FUN_80168f38(s16 param_1);
void FUN_80168f40(void);
void FUN_80168f48(void);
void FUN_80169194(void);
void FUN_8016924c(void);
void PS1_OnPauseOn(void);
void PS1_OnPauseOff(void);

#endif