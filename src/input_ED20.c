#include "input_ED20.h"

extern u8 PS1_DisableInputs;
extern s16 D_801E4C08;
extern s16 joy_rec_left;
extern s16 joy_rec_right;
extern s16 joy_rec_down;
extern s16 D_801F8428;
extern s16 D_801F8438;
extern s16 D_801F8448;
extern s16 D_801F8430;

/* ED20 80133520 -O2 -msoft-float */
s32 readinput(void)
{
    return (s16) TOUCHE(INPUT_READ);
}

/* ED44 80133544 -O2 -msoft-float */
s32 upjoy(s32 param_1)
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
s32 leftjoy(s32 param_1)
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
s32 rightjoy(s32 param_1)
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
s32 downjoy(s32 param_1)
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

/* EEC4 801336C4 -O2 -msoft-float */
s32 FUN_801336c4(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_UP);
    else
        return false;
}

/* EF14 80133714 -O2 -msoft-float */
s32 FUN_80133714(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_LEFT);
    else
        return false;
}

/* EF64 80133764 -O2 -msoft-float */
s32 FUN_80133764(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_RIGHT);
    else
        return false;
}

/* EFB4 801337B4 -O2 -msoft-float */
s32 FUN_801337b4(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_DOWN);
    else
        return false;
}

/* F004 80133804 -O2 -msoft-float */
s32 but0pressed(s32 param_1)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) D_801F8428;
        else
            res = TOUCHE(INPUT_SQUARE);
        return res;
    }
    else
        return false;
}

/* F064 80133864 -O2 -msoft-float */
s32 but1pressed(s32 param_1)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) D_801F8438;
        else
            res = TOUCHE(INPUT_CROSS);
        return res;
    }
    else
        return false;
}

/* F0C4 801338C4 -O2 -msoft-float */
s32 but2pressed(s32 param_1)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) D_801F8448;
        else
            res = TOUCHE(INPUT_TRIANGLE);
        return res;
    }
    else
        return false;
}

/* F124 80133924 -O2 -msoft-float */
s32 but3pressed(s32 param_1)
{
    s16 res;

    if (!PS1_DisableInputs)
    {
        if (record.is_playing)
            res = (u16) D_801F8430;
        else
            res = TOUCHE(INPUT_CIRCLE);
        return res;
    }
    else
        return false;
}

/* F184 80133984 -O2 -msoft-float */
s32 FUN_80133984(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return TOUCHE(INPUT_L1) || TOUCHE(INPUT_L2);
    else
        return false;
}

/* F1F4 801339F4 -O2 -msoft-float */
s32 FUN_801339f4(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return TOUCHE(INPUT_R1) || TOUCHE(INPUT_R2);
    else
        return false;
}

/* F264 80133A64 -O2 -msoft-float */
u8 PS1_IsInputtingCheatCode(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return TOUCHE(INPUT_R1) && TOUCHE(INPUT_R2);
    else
        return false;
}

/* could also write this with ternary op instead */
/* F2CC 80133ACC -O2 -msoft-float */
s32 FUN_80133acc(s32 param_1)
{
    if (PS1_DisableInputs)
        return false;
    else
        return (s16) TOUCHE(INPUT_L1);
}

/* F308 80133B08 -O2 -msoft-float */
s32 FUN_80133b08(s32 param_1)
{
    if (PS1_DisableInputs)
        return false;
    else
        return (s16) TOUCHE(INPUT_R1); 
}

/* F344 80133B44 -O2 -msoft-float */
s32 FUN_80133b44(s32 param_1)
{
    if (PS1_DisableInputs)
        return false;
    else
        return (s16) TOUCHE(INPUT_SELECT); 
}

/* F380 80133B80 -O2 -msoft-float */
s32 FUN_80133b80(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_L1);
    else
        return false;
}

/* F3D0 80133BD0 -O2 -msoft-float */
s32 FUN_80133bd0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_L2);
    else
        return false;
}

/* F420 80133C20 -O2 -msoft-float */
s32 FUN_80133c20(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_R1);
    else
        return false;
}

/* F470 80133C70 -O2 -msoft-float */
s32 FUN_80133c70(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_R2);
    else
        return false;
}

/* F4C0 80133CC0 -O2 -msoft-float */
s32 FUN_80133cc0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_L1);
    else
        return false;
}

/* F510 80133D10 -O2 -msoft-float */
s32 FUN_80133d10(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_L2);
    else
        return false;
}

/* F560 80133D60 -O2 -msoft-float */
s32 FUN_80133d60(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_R1);
    else
        return false;
}

/* F5B0 80133DB0 -O2 -msoft-float */
s32 FUN_80133db0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_R2);
    else
        return false;
}

/* F600 80133E00 -O2 -msoft-float */
s32 FUN_80133e00(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_SQUARE);
    else
        return false;
}

/* F650 80133E50 -O2 -msoft-float */
s32 FUN_80133e50(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_CROSS);
    else
        return false;
}

/* F6A0 80133EA0 -O2 -msoft-float */
s32 FUN_80133ea0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_TRIANGLE);
    else
        return false;
}

/* F6F0 80133EF0 -O2 -msoft-float */
s32 FUN_80133ef0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_CIRCLE);
    else
        return false;
}

/* F740 80133F40 -O2 -msoft-float */
s32 PS1_TOUCHE_0x9(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_START);
    else
        return false;
}

/* F790 80133F90 -O2 -msoft-float */
s32 FUN_80133f90(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_SELECT);
    else
        return false;
}

/* F7E0 80133FE0 -O2 -msoft-float */
s32 FUN_80133fe0(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_NONE);
    else
        return false;
}

/* F830 80134030 -O2 -msoft-float */
s32 PS1_TOUCHE_0xA(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_SELECT);
    else
        return false;
}

/* F880 80134080 -O2 -msoft-float */
s32 FUN_80134080(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_L1);
    else
        return false;
}

/* F8D0 801340D0 -O2 -msoft-float */
s32 PS1_TOUCHE_0xE(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_L2);
    else
        return false;
}

/* F920 80134120 -O2 -msoft-float */
s32 PS1_TOUCHE_0xC(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_R2);
    else
        return false;
}

/* F970 80134170 -O2 -msoft-float */
s32 PS1_TOUCHE_0xB(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) PS1_SingleTOUCHE(INPUT_R1);
    else
        return false;
}

/* F9C0 801341C0 -O2 -msoft-float */
s32 PS1_TOUCHE_0xF(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_DISABLE_DEBUG);
    else
        return false;
}

/* FA10 80134210 -O2 -msoft-float */
s32 PS1_TOUCHE_0x12(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_UNUSED_12);
    else
        return false;
}

/* FA60 80134260 -O2 -msoft-float */
s32 PS1_TOUCHE_0x13(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_13);
    else
        return false;
}

/* FAB0 801342B0 -O2 -msoft-float */
s32 PS1_TOUCHE_0x14(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_14);
    else
        return false;
}

/* FB00 80134300 -O2 -msoft-float */
s32 PS1_TOUCHE_0x15(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_UNUSED_15);
    else
        return false;
}

/* FB50 80134350 -O2 -msoft-float */
s32 PS1_TOUCHE_0x16(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_UNUSED_16);
    else
        return false;
}

/* FBA0 801343A0 -O2 -msoft-float */
s32 PS1_TOUCHE_0x17(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_17);
    else
        return false;
}

/* FBF0 801343F0 -O2 -msoft-float */
s32 PS1_TOUCHE_0x18(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_18);
    else
        return false;
}

/* FC40 80134440 -O2 -msoft-float */
s32 FUN_80134440(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_UNUSED_19);
    else
        return false;
}

/* FC90 80134490 -O2 -msoft-float */
s32 FUN_80134490(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_UNUSED_1A);
    else
        return false;
}

/* FCE0 801344E0 -O2 -msoft-float */
s32 PS1_TOUCHE_0x10(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_ENABLE_DEBUG);
    else
        return false;
}

/* FD30 80134530 -O2 -msoft-float */
s32 FUN_80134530(s32 param_1)
{
    if (!PS1_DisableInputs && !record.is_playing)
        return (s16) TOUCHE(INPUT_START_SELECT);
    else
        return false;
}

/* FD80 80134580 -O2 -msoft-float */
s32 ValidButPressed(void)
{
    return (s16) FUN_80133e50(0);
}

/* FDA4 801345A4 -O2 -msoft-float */
s32 StartButPressed(void)
{
    return (s16) PS1_TOUCHE_0x9(0);
}

/* FDC8 801345C8 -O2 -msoft-float */
s32 FUN_801345c8(void)
{
    return (s16) PS1_TOUCHE_0x9(0);
}

/* FDEC 801345EC -O2 -msoft-float */
s32 SelectButPressed(void)
{
    return (s16) FUN_80133f90(0);
}

/* FE10 80134610 -O2 -msoft-float */
void FUN_80134610(u8 param_1)
{
    D_801F8448 = false;
    D_801F8430 = false;
    D_801F8438 = false;
    D_801F8428 = false;

    if (param_1 & FLG(0))
    {
        switch (options_jeu.Fist)
        {
        case 0:
            D_801F8428 = true;
            break;
        case 1:
            D_801F8438 = true;
            break;
        case 2:
            D_801F8430 = true;
            break;
        case 3:
            D_801F8448 = true;
            break;
        }
    }

    if (param_1 & FLG(1))
    {
        switch (options_jeu.Jump)
        {
        case 0:
            D_801F8428 = true;
            break;
        case 1:
            D_801F8438 = true;
            break;
        case 2:
            D_801F8430 = true;
            break;
        case 3:
            D_801F8448 = true;
            break;
        }
    }

    if (param_1 & FLG(2))
    {
        switch (options_jeu.Action)
        {
        case 0:
            D_801F8428 = true;
            break;
        case 1:
            D_801F8438 = true;
            break;
        case 2:
            D_801F8430 = true;
            break;
        case 3:
            D_801F8448 = true;
            break;
        }
    }

    if (param_1 & FLG(3))
    {
        switch (options_jeu.field6_0x14)
        {
        case 0:
            D_801F8428 = true;
            break;
        case 1:
            D_801F8438 = true;
            break;
        case 2:
            D_801F8430 = true;
            break;
        case 3:
            D_801F8448 = true;
            break;
        }
    }

    if (param_1 & FLG(4))
        joy_rec_left = true;
    else
        joy_rec_left = false;
    
    if (param_1 & FLG(5))
        joy_rec_right = true;
    else
        joy_rec_right = false;
    
    if (param_1 & FLG(6))
        D_801E4C08 = true;
    else
        D_801E4C08 = false;

    if (param_1 & FLG(7))
        joy_rec_down = true;
    else
        joy_rec_down = false;
}

/* 1011C 8013491C -O2 -msoft-float */
u8 FUN_8013491c(void)
{
    s32 unk_1 = 0;
    s32 res = unk_1;
    
    if ((s16) but0pressed(0))
        res |= FLG(0);
    if ((s16) but1pressed(0))
        res |= FLG(1);
    if ((s16) but2pressed(0))
        res |= FLG(2);
    if ((s16) but3pressed(0))
        res |= FLG(3);
    if ((s16) leftjoy(0))
        res |= FLG(4);
    if ((s16) rightjoy(0))
        res |= FLG(5);
    if ((s16) upjoy(0))
        res |= FLG(6);
    if ((s16) downjoy(0))
        res |= FLG(7);

    return res;
}

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_DoDemo);

INCLUDE_ASM("asm/nonmatchings/input_ED20", FUN_80134be0);

INCLUDE_ASM("asm/nonmatchings/input_ED20", TOUCHE);

INCLUDE_ASM("asm/nonmatchings/input_ED20", PS1_SingleTOUCHE);
