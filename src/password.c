#include "password.h"

/*
TODO:
uses of 0x1f are either based on LEN(display_table) or LEN(translate_table) ???
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

/* 7D314 801A1B14 -O2 -msoft-float */
u8 PS1_ValidatePassword(void)
{
    u8 is_valid;
    u8 cc_sum;
    u8 i;
    u8 level = PS1_GetLevelFromPassword();

    PS1_PasswordTables.temp_cage_counts[0] = PS1_CurrentPassword[0] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[1] = PS1_CurrentPassword[2] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[2] = PS1_CurrentPassword[4] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[3] = PS1_CurrentPassword[1] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[4] = PS1_CurrentPassword[3] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[5] = PS1_CurrentPassword[5] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[6] = PS1_CurrentPassword[7] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[7] = PS1_CurrentPassword[6] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[8] = PS1_CurrentPassword[8] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[9] = PS1_CurrentPassword[9] >> 1 & 1;
    PS1_PasswordTables.temp_cage_counts[10] = PS1_CurrentPassword[4] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[11] = PS1_CurrentPassword[0] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[12] = PS1_CurrentPassword[2] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[13] = PS1_CurrentPassword[1] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[14] = PS1_CurrentPassword[5] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[15] = PS1_CurrentPassword[3] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[16] = PS1_CurrentPassword[7] >> 4 & 1;
    PS1_PasswordTables.temp_cage_counts[17] = PS1_CurrentPassword[6] >> 4 & 1;
    
    is_valid =
        level < LEN(PS1_PasswordTables.temp_cage_counts) &&
        !(level == 2 || level == 3) &&
        (level == 6 || level == 7) ^ 1;
    
    if (!is_valid)
        return 2;

    if (PS1_GetLivesFromPassword() >= 100)
        return 3;

    if (PS1_GetContinuesFromPassword() >= 10)
        return 4;

    if (PS1_CurrentPassword[9] & 8)
        is_valid =
            PS1_CurrentPassword[8] & 4 &&
            (level < 4) ^ 1;
    else
        is_valid = level < 9;
    
    if (!is_valid)
        return 5;

    if (PS1_CurrentPassword[8] & 8)
        is_valid =
            PS1_CurrentPassword[9] & 4 &&
            (level < 8) ^ 1;

    if (!is_valid)
        return 6;

    if (PS1_CurrentPassword[8] & 0x10)
        is_valid = (level < 10) ^ 1;
    else
        is_valid =
            level < 11 && 
            PS1_PasswordTables.temp_cage_counts[11] == 0;

    if (!is_valid)
        return 7;

    if (PS1_CurrentPassword[6] & 8)
        is_valid =
            level > 15 &&
            PS1_CurrentPassword[8] & 0x10 &&
            PS1_CurrentPassword[9] >> 3 & 1;
    else
        is_valid =
            level < 17 &&
            PS1_PasswordTables.temp_cage_counts[17] == 0;

    if (!is_valid)
        return 8;

    if (PS1_CurrentPassword[8] & 4)
        is_valid = (level < 4) ^ 1;
    else
        is_valid =
            PS1_PasswordTables.temp_cage_counts[3] == 0 &&
            !(PS1_CurrentPassword[9] & 1 << 3);
    
    if (!is_valid)
        return 0x0F;

    if (PS1_CurrentPassword[9] & 4)
        is_valid = (level < 8) ^ 1;
    else
        is_valid =
            (PS1_PasswordTables.temp_cage_counts[7] == 0) &&
            (PS1_CurrentPassword[8] & 1 << 3) == 0;
    
    if (!is_valid)
        return 0x10;

    if (PS1_PasswordTables.temp_cage_counts[3] != 0)
        is_valid = PS1_CurrentPassword[8] >> 2 & 1;

    if (!is_valid)
        return 0x0C;

    if (
        !(
            PS1_PasswordTables.temp_cage_counts[7] == 0 ||
            (PS1_CurrentPassword[9] >> 2 & 1)
        )
    )
        return 0x0D;

    cc_sum = 0;
    for (i = level + 1; i < LEN(PS1_PasswordTables.temp_cage_counts); i++)
        cc_sum += PS1_PasswordTables.temp_cage_counts[i];
    
    is_valid = cc_sum == 0;
    if (!is_valid)
        return 0x0E;
    
    if (level > 8)
        is_valid =
            PS1_CurrentPassword[9] & 8 &&
            PS1_CurrentPassword[8] >> 2 & 1;

    if (!is_valid)
        return 9;

    if (level > 10)
    {
        is_valid = PS1_CurrentPassword[8] >> 4 & 1;
        if (!is_valid)
            return 0x0A;
    }

    if (level == 17 || PS1_PasswordTables.temp_cage_counts[17] != 0)
    {
        cc_sum = 0;
        for (i = 0; i < 17; i++)
            cc_sum += PS1_PasswordTables.temp_cage_counts[i];
        
        is_valid =
            cc_sum == 17 &&
            PS1_CurrentPassword[6] & 8 &&
            PS1_CurrentPassword[9] & 4 &&
            PS1_CurrentPassword[8] >> 2 & 1;
    }
    
    if (is_valid)
        return is_valid;
    else
        return 0x0B;
}

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

/* 7E35C 801A2B5C -O2 -msoft-float */
void PS1_UnusedGenerateAndPrintPassword(s16 param_1, s16 param_2, u8 param_3, u8 param_4)
{
    u8 i;
    u8 pass[16];

    PS1_IsPasswordValid = PS1_GeneratePassword();
    for (i = 0; i < LEN(PS1_CurrentPassword); i++)
        pass[i] = PS1_PasswordTables.display_table[PS1_CurrentPassword[i] & 0x1F];
    
    if (PS1_IsPasswordValid == true)
        pass[10] = '\0';
    else
    {
        pass[10] = ' ';
        pass[11] = 'e';
        pass[12] = '\0';
    }
    display_text(pass, param_1, param_2, param_3, param_4);
}

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
    if (PS1_ShouldClearPassword == 1)
        PS1_ClearPassword();
}

/* 7E540 801A2D40 -O2 -msoft-float */
void FUN_801a2d40(void)
{
    s32 char_ind;
    u8 character[2];
    s16 max_clignote = 40;
    
    if (compteur < max_compteur)
    {
        if (button_released == 0)
            compteur++;
        else
            compteur = 0;
    }
    else if (button_released == 0)
        compteur = delai_repetition + 1;
    else
        compteur = 0;

    if (compteur_clignote < max_clignote)
        compteur_clignote++;
    else
        compteur_clignote = 0;
    
    for (char_ind = 0; char_ind < (s16) LEN(PS1_CurrentTypingPassword); char_ind++)
    {
        character[0] =
            PS1_PasswordTables.display_table[
                PS1_PasswordTables.translate_table[
                    PS1_CurrentTypingPassword[char_ind] & 0x1F
                ]
            ];
        character[1] = '\0';
        
        if (positionx == char_ind && positiony == 0)
        {
            if (!(D_801F5448 && (compteur_clignote > max_clignote >> 1)))
                display_text(
                    character,
                    basex + (char_ind - 1) * PS1_CharXSpacing,
                    debut_options, 1, 6
                );
        }
        else
            display_text(
                character,
                basex + (char_ind - 1) * PS1_CharXSpacing,
                debut_options,
                1, 1
            );
    }
 
    if (positiony == 1)
    {
        
        if (!(D_801F5448 && (compteur_clignote > max_clignote >> 1)))
            display_text(s_ok_801cf108, 160, PS1_display_y1, 1, 6);
        display_text(s_x__validate_password_8012c3b0, 160, D_801E4E40, 2, 10);
        display_text(s_left__right__move_8012c3c8, 160, D_801E4E48, 2, 10);
    }
    else if (positiony == 0)
    {
        display_text(s_ok_801cf108, 160, PS1_display_y1, 1, 1);
        display_text(s_up__down__browse_8012c3e0, 160, D_801E4E40, 2, 10);
        display_text(s_x__validate_letter_8012c3f8, 160, D_801E4E40 + 15, 2, 10);
        display_text(s_left__right__move_8012c3c8, 160, D_801E4E48, 2, 10);
    }
    else
        display_text(s_wrong_password_8012c410, 160, D_801E4E40, 1, 1);
}

/* 7E864 801A3064 -O2 -msoft-float */
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
                    PS1_PasswordTables.translate_table[
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
}

/* 7EC58 801A3458 -O2 -msoft-float */
s16 PS1_MenuPassword(void)
{
    s16 x_pos;
    u8 should_ret = false;
    
    CLRSCR();
    DISPLAY_FOND_MENU();
    DO_FADE();
    readinput();

    x_pos = 160;
    display_text(s_enter_password_8012c424, x_pos, debut_titre, 1, 1);
    display_text(s_select__return_8012c438, x_pos, D_801E4E48 + 15, 2, 10);
    FUN_801a3064();
    FUN_801a2d40();
    
    if (SelectButPressed() != 0)
    {
        should_ret = true;
        MENU_RETURN = true;

        while (SelectButPressed())
            readinput();
    }

    return should_ret || PS1_ValidPassword;
}

/* 7ED50 801A3550 -O2 -msoft-float */
void FUN_801a3550(void)
{
    LOAD_SAVE_SCREEN();
    INIT_FADE_IN();
    FUN_801a2c78();
    SYNCHRO_LOOP(PS1_MenuPassword);
    DO_FADE_OUT();
    if (PS1_ValidPassword || MENU_RETURN)
    {
        if (positiony == 2)
        {
            PS1_SaveMode = 2;
            MENU_RETURN = false;
        }
        else
            PS1_SaveMode = 1;
    }
}

/* 7EDF8 801A35F8 -O2 -msoft-float */
void PS1_GenerateAndDisplayPassword(void)
{
    /* TODO: correct sizes? */
    u8 i;
    u8 pass[21]; 
    u8 pass_cen[32];

    PS1_IsPasswordValid = PS1_GeneratePassword();
    for (i = 0; i < LEN(PS1_CurrentPassword); i++)
    {
        pass[i * 2] = PS1_PasswordTables.display_table[PS1_CurrentPassword[i] & 0x1f];
        pass[i * 2 + 1] = ' ';
    }

    if (PS1_IsPasswordValid == true)
        pass[20] = '\0';
    sprintf(pass_cen, s_s_801cf110, pass);
    strcpy(text_to_display[0].text, pass_cen);
}

/* TODO: bad split? here or menu_7EEE4? */
/* 7EEB4 801A36B4 -O2 -msoft-float */
void DEPART_INIT_LOOP(void)
{
    menuEtape = 0;
    dans_la_map_monde = false;
    PS1_ClearPassword();
}
