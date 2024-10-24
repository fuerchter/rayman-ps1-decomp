#include "password.h"

/*
pre-bitfield version found in https://github.com/fuerchter/rayman-ps1-decomp/tree/41e4fcfbed817cea65fb049787fa27c8e40988b4

TODO:
uses of 0x1f are either based on LEN(display_table) or LEN(translate_table) ??? or default char, see PS1_ClearPassword
replace x_pos 160 with macro?
*/

const u8 s_x__validate_password_8012c3b0[] = "/x : validate password/";
const u8 s_left__right__move_8012c3c8[] = "/left | right : move/";
const u8 s_up__down__browse_8012c3e0[] = "/up | down : browse/";
const u8 s_x__validate_letter_8012c3f8[] = "/x : validate letter/";
const u8 s_wrong_password_8012c410[] = "/wrong password/";
const u8 s_enter_password_8012c424[] = "/enter password/";
const u8 s_select__return_8012c438[] = "/select : return/";

INCLUDE_ASM("asm/nonmatchings/password", PS1_EncryptPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_VerifyDecryptPassword);

/* thanks! https://decomp.me/scratch/LRbGF */
/* 7CFC8 801A17C8 -O2 -msoft-float */
void FUN_801a17c8(u8 param_1)
{
    PS1_CurrentPassword[4].bit_2 = param_1 >> 0 & 1;
    PS1_CurrentPassword[2].bit_2 = param_1 >> 1 & 1;
    PS1_CurrentPassword[3].bit_2 = param_1 >> 2 & 1;
    PS1_CurrentPassword[1].bit_2 = param_1 >> 3 & 1;
    PS1_CurrentPassword[0].bit_2 = param_1 >> 4 & 1;
}

/* 7D070 801A1870 -O2 -msoft-float */
u8 PS1_GetLevelFromPassword(void)
{
    return
        (PS1_CurrentPassword[4].bit_2 << 0) +
        (PS1_CurrentPassword[2].bit_2 << 1) +
        (PS1_CurrentPassword[3].bit_2 << 2) +
        (PS1_CurrentPassword[1].bit_2 << 3) +
        (PS1_CurrentPassword[0].bit_2 << 4);
}

/* 7D0D0 801A18D0 -O2 -msoft-float */
void PS1_GeneratePassword_LivesCount(u8 lives_count)
{
    PS1_CurrentPassword[3].bit_3 = lives_count >> 0 & 1;
    PS1_CurrentPassword[2].bit_3 = lives_count >> 1 & 1;
    PS1_CurrentPassword[5].bit_3 = lives_count >> 2 & 1;
    PS1_CurrentPassword[1].bit_3 = lives_count >> 3 & 1;
    PS1_CurrentPassword[4].bit_3 = lives_count >> 4 & 1;
    PS1_CurrentPassword[0].bit_3 = lives_count >> 5 & 1;
    PS1_CurrentPassword[7].bit_3 = lives_count >> 6 & 1;
}

/* 7D1B8 801A19B8 -O2 -msoft-float */
u8 PS1_GetLivesFromPassword(void)
{
    return
        (PS1_CurrentPassword[3].bit_3 << 0) +
        (PS1_CurrentPassword[2].bit_3 << 1) +
        (PS1_CurrentPassword[5].bit_3 << 2) +
        (PS1_CurrentPassword[1].bit_3 << 3) +
        (PS1_CurrentPassword[4].bit_3 << 4) +
        (PS1_CurrentPassword[0].bit_3 << 5) +
        (PS1_CurrentPassword[7].bit_3 << 6);
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_nbContinue);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GetContinuesFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_ValidatePassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_LoadSaveFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_AttemptLoadSaveFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_UnusedGenerateAndPrintPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_ClearPassword);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a2c78);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a2d40);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3064);

INCLUDE_ASM("asm/nonmatchings/password", PS1_MenuPassword);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3550);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);

INCLUDE_ASM("asm/nonmatchings/password", DEPART_INIT_LOOP);
