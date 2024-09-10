#include "menu/menu_card_7C028.h"

const u8 s_press_x_button_to_continue_8012c378[] = "/press x button to continue/";
const u8 s_reading_memory_card_8012c398[] = "/reading memory card/";

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PromptCardInput);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PromptCardYesNo);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PromptCardContinue);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PleaseInsertPad);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_CheckCardChanged);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", FUN_801a0c68);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_SetNoCard);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_DoYouHaveCard);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PromptFormatCard);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_GetNbreSave1);

void FUN_801a10a4(void) {}

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_ReadingMemoryCard);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", FUN_801a1110);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_PromptPad);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", FUN_801a1324);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", PS1_SaveWldMap);

INCLUDE_ASM("asm/nonmatchings/menu/menu_card_7C028", FUN_801a141c);
