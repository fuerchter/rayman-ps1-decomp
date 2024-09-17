#include "unknown/2539C.h"

extern u8 D_801E4D48;
extern u8 first_boss_meet;
extern RaymanEvents SauveRayEvts;

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Deter_Option_Caract);

/* 25498 80149C98 -O2 -msoft-float */
void SwapAB(s16 *param_1, s16 *param_2)
{
    s16 prev_2;

    prev_2 = *param_2;
    *param_2 = *param_1;
    *param_1 = prev_2;
}

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Bresenham);

/* 25A0C 8014A20C -O2 -msoft-float */
void LOAD_CONFIG(void)
{
    fichier_selectionne = 0;
    if (D_801E4D48 == 0)
    {
        options_jeu.Jump = 1;
        options_jeu.Fist = 0;
        options_jeu.field6_0x14 = 2;
        options_jeu.Action = 3;
        options_jeu.Music = 13;
        options_jeu.Soundfx = 13;
        options_jeu.StereoEnabled = true;
        options_jeu.field11_0x1e = 0;
        options_jeu.field12_0x20 = 0;
        options_jeu.field14_0x24 = 0;
        options_jeu.field13_0x22 = 0;
        POINTEUR_BOUTONS_OPTIONS_BIS();
    }
}

/* 25AA8 8014A2A8 -O2 -msoft-float */
void init_finBossLevel(void)
{
    finBosslevel[0] = 0;
    finBosslevel[1] &= 0xf0;
}

/* 25ACC 8014A2CC -O2 -msoft-float */
void Change_Wait_Anim(void)
{
    ObjState **ray_eta = ray.eta;
    u8 prev_00 = ray_eta[0][0].anim_index;

    ray_eta[3][20].anim_index = ray_eta[0][56].anim_index;
    ray_eta[0][0].anim_index = ray_eta[0][56].anim_index;
    ray_eta[0][56].anim_index = prev_00;
    first_boss_meet = 1 - first_boss_meet;
}

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", PS1_SetSauveRayEvts);

INCLUDE_ASM("asm/nonmatchings/unknown/2539C", PS1_RestoreSauveRayEvts);
