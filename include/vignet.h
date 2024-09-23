#ifndef VIGNET_H
#define VIGNET_H

#include "common.h"
#include "draw/text_18118.h"

/**/
extern s16 loop_nb_trames;
extern u8 Vignet_To_Display; /* sir, are you a boolean? */

void DISPLAY_TXT_VIGNET(void);
s16 display_vignet_prg(void);
void DISPLAY_GAME_VIGNET(void);

#endif