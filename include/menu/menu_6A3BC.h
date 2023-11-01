#ifndef MENU_6A3BC_H
#define MENU_6A3BC_H

#include "common.h"
#include "obj_update.h"
#include "menu/menu_card_7FD3C.h"
#include "menu/menu_7EEE4.h"
#include "menu/menu_7F4B4.h"
#include "world_map_677C0.h"
#include "victoire.h"

extern Obj clock_obj;
extern s16 loop_timing;
extern u8 nb_continue;

void INIT_NEW_GAME(void);
void POINTEUR_BOUTONS_OPTIONS_BIS(void);
void PS1_DisplayPadButton(s16 button, s16 x, s16 y, u8 font_size);
void INIT_CONTINUE(void);
void CHEAT_MODE_CONTINUE(void);
void MAIN_CONTINUE_PRG(void);
void FIN_CONTINUE_PRG(void);
void MAIN_NO_MORE_CONTINUE_PRG(void);
void INIT_VIGNET(void);
void INIT_CREDITS(void);
void DO_CREDITS(void);
void INIT_LOADER_ANIM(void);
void DO_LOADER_ANIM(void);
void SPECIAL_INIT(void);

#endif