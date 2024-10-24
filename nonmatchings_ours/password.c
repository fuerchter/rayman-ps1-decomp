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
    u8 level = PS1_GetLevelFromPassword();

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
        level < LEN(PS1_PasswordTables.temp_cage_counts) &&
        !(level == 2 || level == 3) &&
        !(level == 6 || level == 7);
    
    if (!is_valid)
        return 2;

    if (PS1_GetLivesFromPassword() >= 100)
        return 3;

    if (PS1_GetContinuesFromPassword() >= 10)
        return 4;

    if (PS1_CurrentPassword[9].bit_3)
        is_valid =
            PS1_CurrentPassword[8].bit_2 &&
            level >= 4;
    else
        is_valid = level < 9;
    
    if (!is_valid)
        return 5;

    if (PS1_CurrentPassword[8].bit_3)
        is_valid =
            PS1_CurrentPassword[9].bit_2 &&
            level >= 8;

    if (!is_valid)
        return 6;

    if (PS1_CurrentPassword[8].bit_4)
        is_valid = level >= 10;
    else
        is_valid =
            level < 11 && 
            PS1_PasswordTables.temp_cage_counts[11] == 0;

    if (!is_valid)
        return 7;

    if (PS1_CurrentPassword[6].bit_3)
        is_valid =
            level > 15 &&
            PS1_CurrentPassword[8].bit_4 &&
            PS1_CurrentPassword[9].bit_3;
    else
        is_valid =
            level < 17 &&
            PS1_PasswordTables.temp_cage_counts[17] == 0;

    if (!is_valid)
        return 8;

    if (PS1_CurrentPassword[8].bit_2)
        is_valid = level >= 4;
    else
        is_valid =
            PS1_PasswordTables.temp_cage_counts[3] == 0 &&
            !PS1_CurrentPassword[9].bit_3;
    
    if (!is_valid)
        return 0x0F;

    if (PS1_CurrentPassword[9].bit_2)
        is_valid = level >= 8;
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
    for (i = level + 1; i < LEN(PS1_PasswordTables.temp_cage_counts); i++)
        cc_sum += PS1_PasswordTables.temp_cage_counts[i];
    
    is_valid = cc_sum == 0;
    if (!is_valid)
        return 0x0E;
    
    if (level > 8)
        is_valid =
            PS1_CurrentPassword[9].bit_3 &&
            PS1_CurrentPassword[8].bit_2;

    if (!is_valid)
        return 9;

    if (level > 10)
    {
        is_valid = PS1_CurrentPassword[8].bit_4;
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