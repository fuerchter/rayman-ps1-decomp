#include "common.h"

extern s16 PS1_ScrollLockedAudio;
extern s16 D_801F84B0;
extern s16 D_801F9A48;

/* D8D0 801320D0 */
void change_audio_track_puit(void) {
    if (D_801F9A48 > 0) {
        PS1_ScrollLockedAudio = 1;
        D_801F84B0 = 1;
        PS1_PlayMusic();
    }
}