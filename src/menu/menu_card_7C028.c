#include "menu/menu_card_7C028.h"

const u8 s_press_x_button_to_continue_8012c378[] = "/press x button to continue/";
const u8 s_reading_memory_card_8012c398[] = "/reading memory card/";

extern u8 PS1_CardStringDisplayed;
extern s16 compteur_mc;
extern u8 s_yes_801cf0f4[6];
extern u8 s_no_801cf0fc[5];
extern u8 PS1_DisplayCardContinueText;
extern u8 PS1_NoCard;

/* 7C028 801A0828 -O2 -msoft-float */
void PS1_PromptCardInput(void)
{
    if (downjoy(0) && inter_select == 0)
    {
        positiony_mc++;
        if (positiony_mc < 3)
            PlaySnd_old(68);
    }
    else if (upjoy(0) && inter_select == 0)
    {
        positiony_mc--;
        if (positiony_mc != 0)
            PlaySnd_old(68);
    }

    MIN_2(positiony_mc, 2);
    if (positiony_mc == 0)
        positiony_mc = 1;
    
    if (++inter_select > 5)
        inter_select = 0;
}

/* 7C164 801A0964 -O2 -msoft-float */
s16 PS1_PromptCardYesNo(void)
{
    s16 done;

    DO_FADE();
    CLRSCR();
    display_text(PS1_CardStrings[PS1_CardStringDisplayed], 160, 140, 2, 0);
    display_text(s_yes_801cf0f4, 160, 173, 2, 0);
    display_text(s_no_801cf0fc, 160, 195, 2, 0);
    PS1_PromptCardDisplayPoing();
    PS1_PromptCardInput();
    readinput();
    if (compteur_mc != 0)
        compteur_mc--;

    done = false;
    if (ValidButPressed())
        done = compteur_mc == 0;
    if (done)
        PlaySnd_old(69);

    return done;
}

/* 7C264 801A0A64 -O2 -msoft-float */
s16 PS1_PromptCardContinue(void)
{
    s16 done;

    DO_FADE();
    CLRSCR();
    display_text(PS1_CardStrings[PS1_CardStringDisplayed], 160, 145, 2, 0);
    if (PS1_DisplayCardContinueText)
        display_text(s_press_x_button_to_continue_8012c378, 160, 195, 2, 0);
    readinput();
    if (compteur_mc != 0)
        compteur_mc--;
    
    done = false;
    if (ValidButPressed())
        done = compteur_mc == 0;
    
    return done;
}

/* 7C338 801A0B38 -O2 -msoft-float */
s16 PS1_PleaseInsertPad(void)
{
    s16 done;

    DO_FADE();
    CLRSCR();
    display_text(PS1_CardStrings[PS1_CardStringDisplayed], 160, 145, 2, 0);
    readinput();
    if (compteur_mc != 0)
        compteur_mc--;

    done = false;
    if (PS1_InitPAD())
        done = compteur_mc == 0;
    
    return done;
}

/* 7C3E0 801A0BE0 -O2 -msoft-float */
void PS1_CheckCardChanged(void)
{
    if (PS1_CardFilenameChecksumChanged())
    {
        PS1_ClearScreen();
        DO_FADE_OUT();
        INIT_FADE_IN();
        while (FUN_8016be9c())
        {
            PS1_CardStringDisplayed = 8;
            PS1_DisplayCardContinueText = false;
            SYNCHRO_LOOP(PS1_PromptCardContinue);
        }
        DO_FADE_OUT();
        INIT_FADE_IN();
    }
}

/* 7C468 801A0C68 -O2 -msoft-float */
void FUN_801a0c68(void)
{
    if (PS1_CardFilenameChecksumChanged())
        PS1_NoCard = true;
}

/* 7C498 801A0C98 -O2 -msoft-float */
void PS1_SetNoCard(void)
{
    if (PS1_TestCardZero())
        PS1_NoCard = true;
    else
        PS1_NoCard = false;
}

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
