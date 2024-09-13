#ifndef UNK_2539C_H
#define UNK_2539C_H

#include "common.h"

void Deter_Option_Caract(u8 *param_1, s16 param_2, u32 param_3);
void SwapAB(s16 *param_1, s16 *param_2);
void Bresenham(void (*param_1)(s16 param_1, s16 param_2), s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7);
void LOAD_CONFIG(void);
void init_finBossLevel(void);
void Change_Wait_Anim(void);
void PS1_SetSauveRayEvts(void);
void PS1_RestoreSauveRayEvts(void);

#endif