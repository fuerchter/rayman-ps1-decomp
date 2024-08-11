#include "input_ED20.h"

extern u8 PS1_DisableInputs;
extern s16 D_801E4C08;
extern s16 joy_rec_left;
extern s16 joy_rec_right;
extern s16 joy_rec_down;

/* ED20 80133520 -O2 -msoft-float */
s32 readinput(void)
{
    return (s16) TOUCHE(INPUT_READ);
}

/* ED44 80133544 -O2 -msoft-float */
s32 upjoy(void)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) D_801E4C08;
        else
            res = TOUCHE(INPUT_UP);
        return res;
    }
    else
        return false;
}

/* EDA4 801335A4 -O2 -msoft-float */
s32 leftjoy(void)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) joy_rec_left;
        else
            res = TOUCHE(INPUT_LEFT);
        return res;
    }
    else
        return false;
}

/* EE04 80133604 -O2 -msoft-float */
s32 rightjoy(void)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) joy_rec_right;
        else
            res = TOUCHE(INPUT_RIGHT);
        return res;
    }
    else
        return false;
}

/* EE64 80133664 -O2 -msoft-float */
s32 downjoy(void)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) joy_rec_down;
        else
            res = TOUCHE(INPUT_DOWN);
        return res;
    }
    else
        return false;
}

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_801336c4);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133714);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133764);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_801337b4);

INCLUDE_ASM("asm/nonmatchings/input_ED20", but0pressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", but1pressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", but2pressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", but3pressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133984);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_801339f4);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_IsInputtingCheatCode);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133acc);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133b08);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133b44);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133b80);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133bd0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133c20);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133c70);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133cc0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133d10);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133d60);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133db0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133e00);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133e50);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133ea0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133ef0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x9);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133f90);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80133fe0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0xA);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134080);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0xE);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0xC);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0xB);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0xF);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x12);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x13);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x14);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x15);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x16);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x17);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x18);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134440);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134490);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_TOUCHE_0x10);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134530);

INCLUDE_ASM("asm/nonmatchings/input_ED20", ValidButPressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", StartButPressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_801345c8);

INCLUDE_ASM("asm/nonmatchings/input_ED20", SelectButPressed);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134610);
/* actual functions start */

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_8013491c);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_DoDemo);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134be0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", TOUCHE);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_SingleTOUCHE);
