#ifndef UNK_2539C_H
#define UNK_2539C_H

#include "common.h"
#include "menu/menu_7F4B4.h"

/**/
extern u8 D_801E4D48;
extern u8 first_boss_meet;
extern RaymanEvents SauveRayEvts;

void Deter_Option_Caract(u8 *str, s16 param_2, u32 param_3);
void SwapAB(s16 *param_1, s16 *param_2);
void Bresenham(void (*param_1)(s32, s32), s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7);
void LOAD_CONFIG(void);
void init_finBossLevel(void);
void Change_Wait_Anim(void);
void PS1_SetSauveRayEvts(void);
void PS1_RestoreSauveRayEvts(void);

#endif