#include "password.h"

/* uses of 0x1f are either based on LEN(PS1_PasswordDisplayTable) or LEN(PS1_PasswordDisplayTranslateTable) ??? */

const u8 s_x__validate_password_8012c3b0[] = "/x : validate password/";
const u8 s_left__right__move_8012c3c8[] = "/left | right : move/";
const u8 s_up__down__browse_8012c3e0[] = "/up | down : browse/";
const u8 s_x__validate_letter_8012c3f8[] = "/x : validate letter/";
const u8 s_wrong_password_8012c410[] = "/wrong password/";
const u8 s_enter_password_8012c424[] = "/enter password/";
const u8 s_select__return_8012c438[] = "/select : return/";

void display_text(u8 *text, s16 x_pos, s16 y_pos, u8 font_size, u32 param_5);
s32 StartButPressed(void);

extern u8 PS1_CurrentPassword[10];
extern u8 PS1_PasswordVerificationTable[10];
extern u8 PS1_PasswordXORTable[10];
extern u8 PS1_Password_TempCageCounts[18];
extern u8 PS1_IsPasswordValid;
extern u8 PS1_PasswordDisplayTable[32];
extern u8 PS1_CurrentTypingPassword[10];
extern s16 D_801E4E40;
extern s16 D_801E4E48;
extern u8 D_801E57A8;
extern u8 PS1_ValidPassword;
extern u8 PS1_PasswordDisplayTranslateTable[32];

/* .data */
extern u8 s_ok_801cf108[5];

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

/* 7E2F0 801A2AF0 -O2 -msoft-float */
u8 PS1_AttemptLoadSaveFromPassword(void)
{
    if (
        (PS1_IsPasswordValid = PS1_VerifyDecryptPassword()) == true &&
        (PS1_IsPasswordValid = PS1_ValidatePassword()) == true
    )
        PS1_LoadSaveFromPassword();
    return PS1_IsPasswordValid;
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_UnusedGenerateAndPrintPassword);

/* 7E35C 801A2B5C -O2 -msoft-float */
void PS1_ClearPassword(void)
{
    memset(&PS1_CurrentTypingPassword, 0x1F, LEN(PS1_CurrentTypingPassword));
}

/* 7E478 801A2C78 -O2 -msoft-float */
void FUN_801a2c78(void)
{
    basex = 75;
    debut_titre = 35;
    debut_options = 95;
    PS1_display_y1 = 131;
    D_801E4E40 = 174;
    D_801E4E48 = 215;
    PS1_CharXSpacing = 21;
    positionx = 0;
    MENU_RETURN = false;
    positiony = 0;
    D_801E57A8 = 0;
    PS1_ValidPassword = false;
    max_compteur = 100;
    delai_repetition = 25;
    if (PS1_ShouldClearPassword == true)
        PS1_ClearPassword();
}

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a2d40);

/* 7E864 801A3064 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3064);
#else
void FUN_801a3064(void)
{
    s32 char_ind;
    u8 valid_prs = ValidButPressed();

    if ((compteur > delai_repetition || button_released != 0) && positiony != 2)
    {
        if ((positiony == 1 && valid_prs) || StartButPressed())
        {
            PlaySnd_old(69);
            for (char_ind = 0; char_ind < (s16) LEN(PS1_CurrentTypingPassword); char_ind++)
            {
                PS1_CurrentPassword[char_ind] =
                    PS1_PasswordDisplayTranslateTable[
                        PS1_CurrentTypingPassword[char_ind]
                    ];
            }
            if (PS1_AttemptLoadSaveFromPassword() != true)
                positiony = 2;
            else
                PS1_ValidPassword = true;
        }

        if (!upjoy(0) && !downjoy(0))
        {
            if (leftjoy(0))
            {
                compteur = 0;
                if (positiony == 0)
                {
                    if (positionx <= 0)
                    {
                        positiony = 1;
                        positionx = 0;
                    }
                    else
                        positionx--;
                }
                else
                {
                    positiony = 0;
                    positionx = ((s16) LEN(PS1_CurrentTypingPassword) - 1);
                }
                PlaySnd_old(68);
            }
            else if (rightjoy(0) || (valid_prs && positiony == 0))
            {
                compteur = 0;
                if (positiony == 0)
                {
                    if (positionx >= ((s16) LEN(PS1_CurrentTypingPassword) - 1))
                    {
                        positionx = ((s16) LEN(PS1_CurrentTypingPassword) - 1);
                        positiony = 1;
                    }
                    else
                        positionx++;
                }
                else
                {
                    positiony = 0;
                    positionx = 0;
                }

                if (valid_prs && positiony == 0)
                    PlaySnd_old(69);
                else
                    PlaySnd_old(68);
            }
            D_801E57A8 = PS1_CurrentTypingPassword[positionx];
        }
        if (!rightjoy(0) && !leftjoy(0) && positiony == 0)
        {
            if (upjoy(0))
            {
                D_801E57A8++;
                D_801E57A8 &= 0x1F;
                if (button_released != 0)
                    PlaySnd_old(68);
            }
            else if (downjoy(0))
            {
                D_801E57A8 += 0x1F;
                D_801E57A8 &= 0x1F;
                if (button_released != 0)
                    PlaySnd_old(68);
            }
            PS1_CurrentTypingPassword[positionx] = D_801E57A8;
        }
    }
    if (
        !upjoy(0) && !downjoy(0) &&
        !rightjoy(0) && !leftjoy(0) &&
        !valid_prs && !PS1_ValidPassword
    )
    {
        button_released = 1;
        D_801F5448 = 1;
        compteur = 0;
    }
    else
    {
        button_released = 0;
        D_801F5448 = 0;
    }

    __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3458);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3550);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);

INCLUDE_ASM("asm/nonmatchings/password", DEPART_INIT_LOOP);
