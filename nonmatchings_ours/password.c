#include "password.h"

/* matches, but casts, new_var */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_EncryptPassword);*/

void PS1_EncryptPassword(void)
{
    uint uVar1;
    u8 bVar3;
    u16 uVar4;
    uint uVar2;
    s32 test_1;
    short new_var;

    uVar4 = 0;
    bVar3 = 0;
    while (bVar3 < 10)
    {
        *(u8 *)&PS1_CurrentPassword[bVar3] ^= PS1_PasswordTables.xor_table[bVar3];
        uVar4 = uVar4 + ((*(u8 *)&PS1_CurrentPassword[bVar3] >> 1) * PS1_PasswordTables.verification_table[bVar3]);
        bVar3 = bVar3 + 1;
    }
    
    new_var = uVar4 >> 0;
    PS1_CurrentPassword[9].bit_0 = (new_var);
    PS1_CurrentPassword[7].bit_0 = (uVar4 >> 1);
    PS1_CurrentPassword[6].bit_0 = (uVar4 >> 2);
    PS1_CurrentPassword[8].bit_0 = (uVar4 >> 3);
    PS1_CurrentPassword[5].bit_0 = (uVar4 >> 4);
    PS1_CurrentPassword[0].bit_0 = (uVar4 >> 5);
    PS1_CurrentPassword[1].bit_0 = (uVar4 >> 6);
    PS1_CurrentPassword[3].bit_0 = (uVar4 >> 7);
    PS1_CurrentPassword[2].bit_0 = (uVar4 >> 8);
    PS1_CurrentPassword[4].bit_0 = (uVar4 >> 9);
}

/* matches, but casts, new_var */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_VerifyDecryptPassword);*/

s32 PS1_VerifyDecryptPassword(void)
{
    u16 temp_lo;
    u8 var_a2;
    u16 var_t4;
    u16 new_var;
    s32 test_1;

    var_t4 = 0;
    var_a2 = 0;
    do
    {
        var_t4 += (*(u8 *)&PS1_CurrentPassword[var_a2] >> 1) * PS1_PasswordTables.verification_table[var_a2];
        *(u8 *)&PS1_CurrentPassword[var_a2] ^= PS1_PasswordTables.xor_table[var_a2];
        var_a2 += 1;
    } while (var_a2 < 10);
    
    new_var = (PS1_CurrentPassword[9].bit_0 << 0);
    temp_lo = 
        new_var +
        (PS1_CurrentPassword[7].bit_0 << 1) +
        (PS1_CurrentPassword[6].bit_0 << 2) +
        (PS1_CurrentPassword[8].bit_0 << 3) +
        (PS1_CurrentPassword[5].bit_0 << 4) +
        (PS1_CurrentPassword[0].bit_0 << 5) +
        (PS1_CurrentPassword[1].bit_0 << 6) +
        (PS1_CurrentPassword[3].bit_0 << 7) +
        (PS1_CurrentPassword[2].bit_0 << 8) +
        (PS1_CurrentPassword[4].bit_0 << 9);

    return var_t4 == temp_lo;
}

/* matches, but is_valid as ternaries? */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_ValidatePassword);*/

u8 PS1_ValidatePassword(void)
{
    u8 is_valid;
    u8 cc_sum;
    u8 i;
    u8 lvl = PS1_GetLevelFromPassword();

    PS1_PasswordTables.temp_cage_counts[0] = PS1_CurrentPassword[0].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[1] = PS1_CurrentPassword[2].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[2] = PS1_CurrentPassword[4].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[3] = PS1_CurrentPassword[1].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[4] = PS1_CurrentPassword[3].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[5] = PS1_CurrentPassword[5].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[6] = PS1_CurrentPassword[7].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[7] = PS1_CurrentPassword[6].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[8] = PS1_CurrentPassword[8].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[9] = PS1_CurrentPassword[9].bit_1 & 1;
    PS1_PasswordTables.temp_cage_counts[10] = PS1_CurrentPassword[4].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[11] = PS1_CurrentPassword[0].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[12] = PS1_CurrentPassword[2].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[13] = PS1_CurrentPassword[1].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[14] = PS1_CurrentPassword[5].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[15] = PS1_CurrentPassword[3].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[16] = PS1_CurrentPassword[7].bit_4 & 1;
    PS1_PasswordTables.temp_cage_counts[17] = PS1_CurrentPassword[6].bit_4 & 1;
    
    is_valid =
        lvl < LEN(PS1_PasswordTables.temp_cage_counts) &&
        !(lvl == 2 || lvl == 3) &&
        !(lvl == 6 || lvl == 7);
    
    if (!is_valid)
        return 2;

    if (PS1_GetLivesFromPassword() >= 100)
        return 3;

    if (PS1_GetContinuesFromPassword() >= 10)
        return 4;

    if (PS1_CurrentPassword[9].bit_3)
        is_valid =
            PS1_CurrentPassword[8].bit_2 &&
            lvl >= 4;
    else
        is_valid = lvl < 9;
    
    if (!is_valid)
        return 5;

    if (PS1_CurrentPassword[8].bit_3)
        is_valid =
            PS1_CurrentPassword[9].bit_2 &&
            lvl >= 8;

    if (!is_valid)
        return 6;

    if (PS1_CurrentPassword[8].bit_4)
        is_valid = lvl >= 10;
    else
        is_valid =
            lvl < 11 && 
            PS1_PasswordTables.temp_cage_counts[11] == 0;

    if (!is_valid)
        return 7;

    if (PS1_CurrentPassword[6].bit_3)
        is_valid =
            lvl > 15 &&
            PS1_CurrentPassword[8].bit_4 &&
            PS1_CurrentPassword[9].bit_3;
    else
        is_valid =
            lvl < 17 &&
            PS1_PasswordTables.temp_cage_counts[17] == 0;

    if (!is_valid)
        return 8;

    if (PS1_CurrentPassword[8].bit_2)
        is_valid = lvl >= 4;
    else
        is_valid =
            PS1_PasswordTables.temp_cage_counts[3] == 0 &&
            !PS1_CurrentPassword[9].bit_3;
    
    if (!is_valid)
        return 0x0F;

    if (PS1_CurrentPassword[9].bit_2)
        is_valid = lvl >= 8;
    else
        is_valid =
            (PS1_PasswordTables.temp_cage_counts[7] == 0) &&
            !PS1_CurrentPassword[8].bit_3;
    
    if (!is_valid)
        return 0x10;

    if (PS1_PasswordTables.temp_cage_counts[3] != 0)
        is_valid = PS1_CurrentPassword[8].bit_2;

    if (!is_valid)
        return 0x0C;

    if (PS1_PasswordTables.temp_cage_counts[7] != 0)
    {
        is_valid = (PS1_CurrentPassword[9].bit_2);
        if (!is_valid)
            return 0x0D;
    }

    cc_sum = 0;
    for (i = lvl + 1; i < LEN(PS1_PasswordTables.temp_cage_counts); i++)
        cc_sum += PS1_PasswordTables.temp_cage_counts[i];
    
    is_valid = cc_sum == 0;
    if (!is_valid)
        return 0x0E;
    
    if (lvl > 8)
        is_valid =
            PS1_CurrentPassword[9].bit_3 &&
            PS1_CurrentPassword[8].bit_2;

    if (!is_valid)
        return 9;

    if (lvl > 10)
    {
        is_valid = PS1_CurrentPassword[8].bit_4;
        if (!is_valid)
            return 0x0A;
    }

    if (lvl == 17 || PS1_PasswordTables.temp_cage_counts[17] != 0)
    {
        cc_sum = 0;
        for (i = 0; i < 17; i++)
            cc_sum += PS1_PasswordTables.temp_cage_counts[i];
        
        is_valid =
            cc_sum == 17 &&
            PS1_CurrentPassword[6].bit_3 &&
            PS1_CurrentPassword[9].bit_2 &&
            PS1_CurrentPassword[8].bit_2;
    }
    
    if (is_valid)
        return is_valid;
    else
        return 0x0B;
}

/* matches, but check the do{}while? */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword);*/

/* thanks! https://decomp.me/scratch/6aOG2 */
/* 7D948 801A2148 -O2 -msoft-float */
u8 PS1_GeneratePassword(void)
{
    u8 i;

    memset(&PS1_CurrentPassword, 0, sizeof(PS1_CurrentPassword));
    PS1_CurrentPassword[0].bit_1 = t_world_info[0].nb_cages == 6;
    PS1_CurrentPassword[2].bit_1 = t_world_info[1].nb_cages == 6;
    PS1_CurrentPassword[4].bit_1 = t_world_info[2].nb_cages == 6;
    PS1_CurrentPassword[1].bit_1 = t_world_info[3].nb_cages == 6;
    PS1_CurrentPassword[3].bit_1 = t_world_info[4].nb_cages == 6;
    PS1_CurrentPassword[5].bit_1 = t_world_info[5].nb_cages == 6;
    PS1_CurrentPassword[7].bit_1 = t_world_info[6].nb_cages == 6;
    PS1_CurrentPassword[6].bit_1 = t_world_info[7].nb_cages == 6;
    PS1_CurrentPassword[8].bit_1 = t_world_info[8].nb_cages == 6;
    PS1_CurrentPassword[9].bit_1 = t_world_info[9].nb_cages == 6;
    PS1_CurrentPassword[4].bit_4 = t_world_info[10].nb_cages == 6;
    PS1_CurrentPassword[0].bit_4 = t_world_info[11].nb_cages == 6;
    PS1_CurrentPassword[2].bit_4 = t_world_info[12].nb_cages == 6;
    PS1_CurrentPassword[1].bit_4 = t_world_info[13].nb_cages == 6;
    PS1_CurrentPassword[5].bit_4 = t_world_info[14].nb_cages == 6;
    PS1_CurrentPassword[3].bit_4 = t_world_info[15].nb_cages == 6;
    PS1_CurrentPassword[7].bit_4 = t_world_info[16].nb_cages == 6;
    PS1_CurrentPassword[6].bit_4 = finBosslevel.mr_dark;
    PS1_CurrentPassword[8].bit_2 = t_world_info[3].is_unlocked || t_world_info[3].is_unlocking;
    PS1_CurrentPassword[9].bit_2 = t_world_info[7].is_unlocked || t_world_info[7].is_unlocking;
    
    i = 18;
    do {
        i--;
        if (i == 3 || i == 7)
            i -= 2;
    } while (!(t_world_info[i].is_unlocked == true || t_world_info[i].is_unlocking == true));
    
    FUN_801a17c8(i);
    PS1_CurrentPassword[9].bit_3 = finBosslevel.moskito;
    PS1_CurrentPassword[6].bit_3 = finBosslevel.mr_skops;
    PS1_CurrentPassword[8].bit_4 = finBosslevel.helped_musician;
    PS1_CurrentPassword[8].bit_3 = finBosslevel.mr_sax;
    PS1_GeneratePassword_LivesCount((u8) status_bar.num_lives);
    PS1_GeneratePassword_nbContinue(nb_continue);

    PS1_IsPasswordValid = PS1_ValidatePassword();
    if (PS1_IsPasswordValid == true)
        PS1_EncryptPassword();
    
    return PS1_IsPasswordValid;
}

/* matches, but casts */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_UnusedGenerateAndPrintPassword);*/

/* 7E35C 801A2B5C -O2 -msoft-float */
void PS1_UnusedGenerateAndPrintPassword(s16 param_1, s16 param_2, u8 param_3, u8 param_4)
{
    u8 i;
    u8 pass[16];

    PS1_IsPasswordValid = PS1_GeneratePassword();
    for (i = 0; i < LEN(PS1_CurrentPassword); i++)
        pass[i] = PS1_PasswordTables.display_table[*(u8 *)&PS1_CurrentPassword[i] & 0x1F];
    
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

/* matches, but casts*/
/*INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3064);*/

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
                *(u8 *)&PS1_CurrentPassword[char_ind] =
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

/* matches, but casts */
/*INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);*/

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
        pass[i * 2] = PS1_PasswordTables.display_table[*(u8 *)&PS1_CurrentPassword[i] & 0x1f];
        pass[i * 2 + 1] = ' ';
    }

    if (PS1_IsPasswordValid == true)
        pass[20] = '\0';
    sprintf(pass_cen, s_s_801cf110, pass);
    strcpy(text_to_display[0].text, pass_cen);
}