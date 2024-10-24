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