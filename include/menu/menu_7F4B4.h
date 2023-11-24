#ifndef MENU_7F4B4_H
#define MENU_7F4B4_H

#include "common.h"
#include "psyq_3_0/STRINGS.H"
#include "text_24E10.h"
#include "menu/menu_7EEE4.h"
#include "fade.h"
#include "demo_7F2BC.h"
#include "menu/menu_82008.h"
#include "card.h"

/* but0pressed etc. return int in ghidra */
typedef struct OptionsJeu
{
    s16 (* Fire1ButtonFunc)();
    s16 (* Fire0ButtonFunc)();
    s16 (* Button4Func)();
    s16 (* Button3Func)();
    u16 Jump;
    u16 Fist;
    u16 field6_0x14;
    u16 Action;
    u16 Music;
    u16 Soundfx;
    u16 StereoEnabled;
    s16 field11_0x1e;
    s16 field12_0x20;
    s16 field13_0x22;
    s16 field14_0x24;
} OptionsJeu;

/* .rodata */
extern const u8 s_x__validate_8012c4bc[];
extern const u8 s_select__return_8012c4cc[];
extern const u8 s_choose_a_game_8012c4e0[];
extern const u8 s_up__down__browse_8012c4f0[];
extern const u8 s_x__validate_letter_8012c508[];
extern const u8 s_press_wished_button_8012c520[];
extern const u8 s_left__right__modify_options_8012c538[];
extern const u8 s_up__down__choose_options_8012c558[];
extern const u8 s_x_validate_select_quit_game_8012c578[];

/* .data */
extern u8 *PS1_SettingStrings[8]; /* if creates conflict here, put in menu_82008 */

/* .data */
extern u8 s_start_801cf118[8];
extern u8 s__801cf120[1];
extern u8 s_copy_801cf124[5];
extern u8 s_erase_801cf12c[6];
extern u8 s_start_801cf134[6];
extern u8 s__801cf13c[2];
extern u8 s_801cf141[1];
extern u8 s_empty_801cf144[6];
extern u8 s_options_801cf14c[8];
extern u8 s__801cf154[2];
extern u8 s_aaa_801cf158[4];

/**/
extern s16 PS1_SaveMode;
extern u8 button_released; /* TODO: not a bool? based on RAY_HELICO */
extern s16 compteur;
extern s16 max_compteur;
extern s16 repetition;
extern s16 delai_repetition;
extern s16 positionx;
extern s16 positiony;
extern s16 PS1_Settings[6];
extern s16 D_801D7A50;
extern s16 basex;
extern s16 ecart_barre;
extern OptionsJeu options_jeu;
extern OptionsJeu options_jeu_save; /* from include/demo_9FD4.h, move back? */
extern s16 debut_titre;
extern s16 debut_options;
extern s16 debut_sortie;
extern s16 ecarty;
extern s16 fichier_a_copier;
extern s16 positionx2;
extern s16 positiony2;
extern s16 PS1_display_y1;
extern s16 PS1_display_y2;
extern s16 position;
extern s16 fichier_existant;
extern s16 fichier_selectionne;
extern s16 realisation_effectuee;
extern u8 D_801F7F68[4];
extern s16 action;
extern s16 fin_saisie_nom;
extern u8 save_ray[4][4];
extern s16 sortie_save;
extern s16 compteur_clignote;
extern s16 D_801F5448;
extern s16 D_801E5748;
extern s16 selection_effectuee;
extern s16 affiche_bon_ecran;

void PS1_TextBoxCardOrPassword(void);
void PS1_InputCardOrPassword(void);
void PS1_DisplayCardOrPassword(void);
u8 PS1_MenuCardOrPassword(void);
void PS1_InitCardOrPassword(void);
s32 saisie_nom_prg(void);
s32 selection_save_option_prg(void);
void DO_SAVE_CHOICE(void);
void AFFICHE_ECRAN_SAVE(void);
s32 PS1_DoGameOptionsLoop(void);
void PS1_DoGameOptions(void);
void AFFICHE_PAD_SCREEN(void);
void INIT_SAVE_CHOICE(void);
void INIT_SAVE_CONTINUE(void);
void DO_COMMANDE_SAVE(void);
void SELECTION_SAVE_OPTION(void);
void INIT_AFFICHE_ECRAN_SAVE(void);
void SAISIE_NOM(void);
void REALISATION_ACTION(void);

#endif