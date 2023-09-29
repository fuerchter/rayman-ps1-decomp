#ifndef MENU_CARD_7FD3C_H
#define MENU_CARD_7FD3C_H

#include "common.h"

/* but0pressed etc. return int in ghidra */
typedef struct {
    u8 * Fire1ButtonFunc;
    u8 * Fire0ButtonFunc;
    u8 * Button4Func;
    u8 * Button3Func;
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

#endif