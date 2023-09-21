#include "common.h"

/* D518 80131D18 */
void PS1_PlayDeathMusic(void) {
    FUN_8016617c();
    PS1_StopPlayingAllSnd();
    playLevelMusic(0, 1);
}