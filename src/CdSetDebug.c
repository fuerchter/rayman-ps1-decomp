#include "common.h"

extern s32 PS1_cd_dbg_lvl;

/* 841FC 801A89FC */
s32 CdSetDebug(s32 level) {
    s32 prev_level;

    prev_level = PS1_cd_dbg_lvl;
    PS1_cd_dbg_lvl = level;
    return prev_level;
}