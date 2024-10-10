#ifndef LOADING_TEX_H
#define LOADING_TEX_H

#include "common.h"
#include "common/world_map.h"
#include "vram.h"

/* .data */
extern s16 D_801C4468[8];

/**/
extern s32 D_801E4D30;
extern s16 D_801E5930;
extern s16 D_801E63D0;
extern s32 D_801E4D28;
extern s16 D_801E5928;
extern s16 D_801E63C8;
extern s32 D_801E4D78;
extern s16 D_801E5A08;
extern s16 D_801E6410;
extern s16 D_801E5558;
extern s16 D_801E59B8;

void FUN_801392d8(s32 param_1, s16 *param_2, s16 *param_3);
void FUN_80139330(u32 param_1, s16 *param_2, s16 *param_3);
void FUN_801393c8(s32 param_1);
void PS1_LoadAllFixTextures(s32 length);
void FUN_8013948c(s32 param_1);
void FUN_80139514(s32 param_1);
void FUN_801395a8(s32 param_1);
void FUN_80139624(s32 param_1);
void FUN_80139688(s32 tile_set_size);

#endif