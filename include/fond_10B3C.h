#ifndef FOND_10B3C_H
#define FOND_10B3C_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "psyq_3_0/MEMORY.H"
#include "common/display.h"
#include "common/obj.h"
#include "loading_794DC.h"

void PS1_LoadFondSprites(void);
void PS1_LoadFondDataAndPalettes(void);
void PS1_LoadFond(void);
void FUN_80135ab0(s16 param_1, s16 *param_2); /* param_2 is pointer? see PS1_DisplayFondSprites */
void FUN_80135d5c(s32 param_1, s16 *param_2, s32 param_3, s16 param_4); /* param_2 is pointer? see PS1_DisplayFondSprites */
void FUN_8013613c(u8 param_1, u32 param_2, u8 param_3, u32 param_4);
void FUN_80136340(s16 *param_1, u32 param_2); /* param_1 is pointer? see PS1_DisplayFondSprites */
void FUN_801366ac(void);
void PS1_DisplayFondSprites(void);
u8 FUN_80137998(u8 param_1, u8 param_2, s32 param_3);
u8 PS1_GetTileV(u8 param_1, u8 param_2, s32 tile);
u8 PS1_GetTileU(s32 param_1);
void DRAW_MAP(void);
void FUN_80137cc8(s32 param_1, s16 *param_2); /* param_2 is pointer? see PS1_DisplayFondSprites */
void allume_vitraux(u8 (*param_1) [5]);
void FUN_80138360(u8 *vitrailClignotement);
void FUN_80138718(u8 param_1);
void FUN_80138b84(s16 param_1, s16 *param_2, s16 param_3, s16 param_4); /* param_2 is pointer? see caller */
void PS1_DisplayWorldMapBg2(u16 param_1, u16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6);
void FUN_801392c8(void);
void FUN_801392d0(void);

#endif