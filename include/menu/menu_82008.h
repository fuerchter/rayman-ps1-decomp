#ifndef MENU_82008_H
#define MENU_82008_H

#include "common.h"
#include "psyq_3_0/STRINGS.H"
#include "menu/menu_7EEE4.h"
#include "menu/menu_7F4B4.h"
#include "menu/menu_card_7FD3C.h"
#include "menu/menu_card_7C028.h"
#include "demo_7F2BC.h"
#include "input_ED20.h"

extern s16 D_801D7AA0;
extern s16 D_801F5498; /* used as loop bound */
extern s16 PS1_Music_Max;
extern s16 PS1_Soundfx_Max;
extern s16 delai_barre;
extern s16 delai_stereo;

void FUN_801a6808(void);
void FUN_801a6984(void);
void FUN_801a6a04(u8 param_1);
void DO_COMMANDE_PAD(void);
void FUN_801a76e4(void);

#endif