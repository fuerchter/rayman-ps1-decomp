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

/* 7D240 801A1A40 -O2 -msoft-float */
void PS1_GeneratePassword_nbContinue(u8 param_1)
{
    PS1_CurrentPassword[5].bit_2 = param_1 >> 0 & 1;
    PS1_CurrentPassword[7].bit_2 = param_1 >> 1 & 1;
    PS1_CurrentPassword[6].bit_2 = param_1 >> 2 & 1;
    PS1_CurrentPassword[9].bit_4 = param_1 >> 3 & 1;
}

/* 7D2C8 801A1AC8 -O2 -msoft-float */
u8 PS1_GetContinuesFromPassword(void)
{
    return
        (PS1_CurrentPassword[5].bit_2 << 0) +
        (PS1_CurrentPassword[7].bit_2 << 1) +
        (PS1_CurrentPassword[6].bit_2 << 2) +
        (PS1_CurrentPassword[9].bit_4 << 3);
}

INCLUDE_ASM("asm/nonmatchings/password", PS1_ValidatePassword);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GeneratePassword);

/* thanks! https://decomp.me/scratch/5n1p8 */
/* 7DDEC 801A25EC -O2 -msoft-float */
void PS1_LoadSaveFromPassword(void)
{
    u8 lvl;
    u8 i;

    INIT_NEW_GAME();
    lvl = PS1_GetLevelFromPassword();

    for (i = 0; i <= lvl; i++)
        t_world_info[i].is_unlocked = true;
    
    t_world_info[7].is_unlocked = PS1_CurrentPassword[9].bit_2;
    t_world_info[3].is_unlocked = PS1_CurrentPassword[8].bit_2;
    t_world_info[18].is_unlocked = lvl > 0;
    t_world_info[19].is_unlocked = lvl > 4;
    t_world_info[20].is_unlocked = lvl > 6 && PS1_CurrentPassword[9].bit_2;
    t_world_info[21].is_unlocked = lvl > 9;
    t_world_info[22].is_unlocked = lvl > 13;
    t_world_info[23].is_unlocked = lvl > 15;
    t_world_info[0].nb_cages = PS1_CurrentPassword[0].bit_1 ? 6 : 0; /* TODO: macro */
    t_world_info[1].nb_cages = PS1_CurrentPassword[2].bit_1 ? 6 : 0;
    t_world_info[2].nb_cages = PS1_CurrentPassword[4].bit_1 ? 6 : 0;
    t_world_info[3].nb_cages = PS1_CurrentPassword[1].bit_1 ? 6 : 0;
    t_world_info[4].nb_cages = PS1_CurrentPassword[3].bit_1 ? 6 : 0;
    t_world_info[5].nb_cages = PS1_CurrentPassword[5].bit_1 ? 6 : 0;
    t_world_info[6].nb_cages = PS1_CurrentPassword[7].bit_1 ? 6 : 0;
    t_world_info[7].nb_cages = PS1_CurrentPassword[6].bit_1 ? 6 : 0;
    t_world_info[8].nb_cages = PS1_CurrentPassword[8].bit_1 ? 6 : 0;
    t_world_info[9].nb_cages = PS1_CurrentPassword[9].bit_1 ? 6 : 0;
    t_world_info[10].nb_cages = PS1_CurrentPassword[4].bit_4 ? 6 : 0;
    t_world_info[11].nb_cages = PS1_CurrentPassword[0].bit_4 ? 6 : 0;
    t_world_info[12].nb_cages = PS1_CurrentPassword[2].bit_4 ? 6 : 0;
    t_world_info[13].nb_cages = PS1_CurrentPassword[1].bit_4 ? 6 : 0;
    t_world_info[14].nb_cages = PS1_CurrentPassword[5].bit_4 ? 6 : 0;
    t_world_info[15].nb_cages = PS1_CurrentPassword[3].bit_4 ? 6 : 0;
    t_world_info[16].nb_cages = PS1_CurrentPassword[7].bit_4 ? 6 : 0;
    t_world_info[17].nb_cages = 0;
    
    memset(&RayEvts, 0, sizeof(RayEvts));
    RayEvts.poing = lvl > 0;
    RayEvts.hang = lvl > 3;
    RayEvts.grap = PS1_CurrentPassword[9].bit_3;
    RayEvts.helico = lvl > 7;
    RayEvts.run = lvl > 10;
    
    memset(&finBosslevel, 0, sizeof(finBosslevel));
    finBosslevel.bzzit = lvl > 3;
    finBosslevel.moskito = PS1_CurrentPassword[9].bit_3;
    finBosslevel.mr_sax = PS1_CurrentPassword[8].bit_3;
    finBosslevel.mr_stone = lvl > 10;
    finBosslevel.viking_mama = lvl > 11;
    finBosslevel.space_mama = lvl > 13;
    finBosslevel.mr_skops = PS1_CurrentPassword[6].bit_3;
    finBosslevel.mr_dark = PS1_CurrentPassword[6].bit_4;
    finBosslevel.helped_musician = PS1_CurrentPassword[8].bit_4;

    status_bar.num_lives = PS1_GetLivesFromPassword();
    nb_continue = PS1_GetContinuesFromPassword();
    world_index = 0;
    xwldmapsave = 0;
    ywldmapsave = 158;
    dir_on_wldmap = 1;
}

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

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3064);

INCLUDE_ASM("asm/nonmatchings/password", PS1_MenuPassword);

INCLUDE_ASM("asm/nonmatchings/password", FUN_801a3550);

INCLUDE_ASM("asm/nonmatchings/password", PS1_GenerateAndDisplayPassword);

INCLUDE_ASM("asm/nonmatchings/password", DEPART_INIT_LOOP);
