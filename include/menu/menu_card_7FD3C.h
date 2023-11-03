#ifndef MENU_CARD_7FD3C_H
#define MENU_CARD_7FD3C_H

#include "common.h"

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

/* .data */
extern u8 *PS1_SettingStrings[8]; /* if creates conflict here, put in menu_82008 */

/**/
extern s16 PS1_Settings[6];
extern s16 D_801D7A50;
extern s16 basex;
extern s16 ecart_barre;
extern OptionsJeu options_jeu;
extern s16 debut_titre;
extern s16 debut_options;
extern s16 debut_sortie;
extern s16 ecarty;
extern s16 fichier_a_copier;
extern s16 positionx2;
extern s16 PS1_display_y1;
extern s16 PS1_display_y2;
extern s16 position;
extern s16 fichier_existant;
extern s16 fichier_selectionne;

#endif