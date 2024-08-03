#include "password.h"

const u8 s_x__validate_password_8012c3b0[] = "/x : validate password/";
const u8 s_left__right__move_8012c3c8[] = "/left | right : move/";
const u8 s_up__down__browse_8012c3e0[] = "/up | down : browse/";
const u8 s_x__validate_letter_8012c3f8[] = "/x : validate letter/";
const u8 s_wrong_password_8012c410[] = "/wrong password/";
const u8 s_enter_password_8012c424[] = "/enter password/";
const u8 s_select__return_8012c438[] = "/select : return/";

extern u8 PS1_CurrentPassword[10];
extern u8 PS1_PasswordVerificationTable[10];
extern u8 PS1_PasswordXORTable[10];

INCLUDE_ASM("asm/nonmatchings/password", PS1_EncryptPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_VerifyDecryptPassword);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a17c8);

/* 7D070 801A1870 -O2 -msoft-float */
u8 PS1_GetLevelFromPassword(void)
{
    return
        (PS1_CurrentPassword[4] >> 2 & (1 << 0)) +
        (PS1_CurrentPassword[2] >> 1 & (1 << 1)) +
        (PS1_CurrentPassword[3] & (1 << 2)) +
        (PS1_CurrentPassword[1] << 1 & (1 << 3)) +
        (PS1_CurrentPassword[0] << 2 & (1 << 4));
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_LivesCount);

/* 7D1B8 801A19B8 -O2 -msoft-float */
u8 PS1_GetLivesFromPassword(void)
{
    return
        (PS1_CurrentPassword[3] >> 3 & (1 << 0)) +
        (PS1_CurrentPassword[2] >> 2 & (1 << 1)) +
        (PS1_CurrentPassword[5] >> 1 & (1 << 2)) +
        (PS1_CurrentPassword[1] & (1 << 3)) +
        (PS1_CurrentPassword[4] << 1 & (1 << 4)) +
        (PS1_CurrentPassword[0] << 2 & (1 << 5)) +
        (PS1_CurrentPassword[7] << 3 & (1 << 6));
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_nbContinue);

/* 7D2C8 801A1AC8 -O2 -msoft-float */
u8 PS1_GetContinuesFromPassword(void)
{
    return
        (PS1_CurrentPassword[5] >> 2 & (1 << 0)) +
        (PS1_CurrentPassword[7] >> 1 & (1 << 1)) +
        (PS1_CurrentPassword[6] & (1 << 2)) +
        (PS1_CurrentPassword[9] >> 1 & (1 << 3));
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_ValidatePassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_LoadSaveFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_AttemptLoadSaveFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_UnusedGenerateAndPrintPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_ClearPassword);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a2c78);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a2d40);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3064);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3458);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3550);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);

INCLUDE_ASM("asm/nonmatchings/password", DEPART_INIT_LOOP);
