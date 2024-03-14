#ifndef CARD_H
#define CARD_H

#include "common.h"
#include "psyq_3_0/KERNEL.H"
#include "menu/menu_7F4B4.h"

typedef struct CardFrame0
{
    u8 sc_magic[2];
    u8 icon_display_flag;
    u8 block_num;
    u8 Rayman_save_ray_pct[64];
    u8 Maga[28];
} CardFrame0;

typedef struct LoadInfoRay {
    u8 num_lives;
    u8 num_wiz;
    u8 num_cages;
    u8 num_continues;
} LoadInfoRay;

extern LoadInfoRay loadInfoRay[6];

u8 PS1_InitPAD(void);
s32 PS1_TestSwCARD(void);
void PS1_TestSwCARDOnce(void);
s32 PS1_TestHwCARD(void);
void PS1_TestHwCARDOnce(void);
u8 PS1_TestCard(u8 par_chan);
s32 PS1_GetNbreFiles(u8 *name_start, struct DIRENTRY *dir);
s32 PS1_CardFilenameChecksum(u8 chan);
void PS1_InitializeCard(u8 chan);
u8 PS1_FormatFs(u8 param_1);
void PS1_InitSaveRayAndFilenames(u8 param_1);
s32 PS1_WriteSave(u8 chan_par, u32 slot_par);
u8 * FUN_8016b2e8(u32 param_1, u8 param_2, u8 *param_3);
u8 SaveGameOnDisk(u32 param_1);
s32 SaveFileRead(s32 fd, void *buf, s16 n);
void PS1_LoadSave(s32 param_1, u8 *param_2);
void LoadGameOnDisk(u32 param_1);
s32 LoadInfoGame(u32 save);
void FUN_8016bbe4(void);
u8 PS1_GetNbreSave3(u32 param_1);
u8 PS1_CardFilenameChecksumChanged(void);
u8 PS1_TestCardZero(void);
u8 PS1_CardUnformatted(void);
u8 PS1_GetNbreSave2(void);
s32 FUN_8016be9c(void);
void FUN_8016bec0(void);

#endif