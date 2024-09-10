#ifndef MENU_CARD_7C028_H
#define MENU_CARD_7C028_H

#include "common.h"
#include "sound.h"
#include "synchro_loop.h"

/* .data */
extern u8 *PS1_CardStrings[13];

/**/
extern u8 NBRE_SAVE;
extern u8 positiony_mc;

void PS1_PromptCardInput(void);
s16 PS1_PromptCardYesNo(void);
s16 PS1_PromptCardContinue(void);
s16 PS1_PleaseInsertPad(void);
void PS1_CheckCardChanged(void);
void FUN_801a0c68(void);
void PS1_SetNoCard(void);
void PS1_DoYouHaveCard(void);
void PS1_PromptFormatCard(void);
void PS1_GetNbreSave1(void);
void FUN_801a10a4(void);
u8 PS1_ReadingMemoryCard(void);
void FUN_801a1110(void);
void PS1_PromptPad(void);
void FUN_801a1324(void);
u8 PS1_SaveWldMap(void);
u8 FUN_801a141c(void);

#endif