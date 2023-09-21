#include "common.h"

extern s16 D_801F5248;

/* D4C0 80131CC0 */
//play "yeah" sound
//TODO: this seems to lead down a rabbit hole of new funcs/dats to label
void start_cd_gagne(void) {
    D_801F5248 = 1;
    FUN_80131e40();
    if (PS1_SongIsPlaying(0x15) == 0) {
        PS1_StopPlayingAllSnd();
        stop_all_snd();
        PS1_PlaySnd(0xD, 1);
    }
}