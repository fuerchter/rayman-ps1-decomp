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

INCLUDE_ASM("asm/nonmatchings/password", PS1_GetLevelFromPassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword_LivesCount);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GetLivesFromPassword);

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

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3458);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3550);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);

INCLUDE_ASM("asm/nonmatchings/password", DEPART_INIT_LOOP);
