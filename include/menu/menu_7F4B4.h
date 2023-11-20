#ifndef MENU_7F4B4_H
#define MENU_7F4B4_H

#include "common.h"
#include "text_24E10.h"
#include "menu/menu_7EEE4.h"
#include "fade.h"
#include "demo_7F2BC.h"

/* .data */
extern u8 s_start_801cf118[8];

/**/
extern s16 PS1_SaveMode;
extern u8 button_released; /* TODO: not a bool? based on RAY_HELICO */
extern s16 compteur;
extern s16 max_compteur;
extern s16 repetition;
extern s16 delai_repetition;
extern s16 positiony;

void PS1_TextBoxCardOrPassword(void);
void PS1_InputCardOrPassword(void);
void PS1_DisplayCardOrPassword(void);
u8 PS1_MenuCardOrPassword(void);
void PS1_InitCardOrPassword(void);

#endif