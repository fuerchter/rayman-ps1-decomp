#include "unknown/2539C.h"

#ifdef BSS_DEFS
u8 D_801E4D48;
u8 first_boss_meet;
RaymanEvents SauveRayEvts;
#endif

/* 2539C 80149B9C -O2 -msoft-float */
void Deter_Option_Caract(u8 *str, s16 param_2, u32 param_3)
{
    u8 i;
    s16 unk_1 = param_3;
    
    if (unk_1 == 0xff)
        for (i = 0; str[i] != '\0'; i++)
            if (str[i] == '$')
                unk_1 = i;
                
    switch (param_2) /* see also menu_AA8AC.c */
    {
    case 0:
        str[unk_1] = 0x23;
        break;
    case 1:
        str[unk_1] = 0x2A;
        break;
    case 2:
        str[unk_1] = 0x5E;
        break;
    case 3:
        str[unk_1] = 0xF8;
        break;
    }
}

/* 25498 80149C98 -O2 -msoft-float */
void SwapAB(s16 *param_1, s16 *param_2)
{
    s16 prev_2;

    prev_2 = *param_2;
    *param_2 = *param_1;
    *param_1 = prev_2;
}

#ifndef NONMATCHINGS
INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Bresenham);
#else
/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/unknown/2539C", Bresenham);*/

void Bresenham(void (*param_1)(s32, s32), s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6, s16 param_7)
{
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;
    void (*sp18)(s16, s16);
    s16 sp20;
    s32 var_s0_2;
    s16 var_s0_3;
    s16 var_s0_4;
    s16 var_s0_5;
    s32 var_s1_1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_s1_4;
    s16 var_s3;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_lo_1;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_lo_4;
    s32 temp_s6_1;
    s32 temp_s6_2;
    s32 temp_s6_3;
    s32 temp_s6_4;
    s16 var_s0_1;
    s32 var_s2_1;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_s7_1;
    s32 var_s7_2;
    s32 var_v0;
    s32 test_1;
    s32 test_2;

    /*sp18 = param_1;*/
    sp10 = param_2;
    sp14 = param_3;
    sp12 = param_4;
    var_s0_1 = 0;
    var_s5 = param_4 - param_2;
    sp16 = param_5;
    var_s4 = param_5 - param_3;
    test_1 = param_6;
    sp20 = test_1;
    temp_s6_1 = param_7;
    if (var_s5 == 0)
    {
        var_s3 = 0;
    }
    else
    {
        var_s3 = __builtin_abs(var_s4 / var_s5) < 1;
    }
    if (var_s3 == 1)
    {
        if (var_s5 < 0)
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            SwapAB(&sp14, &sp16);
            var_s5 = -var_s5;
            var_s4 = -var_s4;
        }
        else if ((var_s5 == 0) && (var_s4 < 0))
        {
            var_s0_1 = 1;
            SwapAB(&sp14, &sp16);
            var_s4 = -var_s4;
        }

        
        if (var_s4 <= 0)
        {
            var_s7_1 = var_s4 >> 0x1F;
        }
        else
            var_s7_1 = 1;

        var_s4 = __builtin_abs(var_s4);
        var_s2_1 = (var_s4 * 2) - var_s5;
        temp_a3 = var_s4 - var_s5;
        if (var_s0_1 != 0)
        {
            var_s0_2 = sp12;
            temp_s6_1 = var_s0_2 + ((sp10 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp16;
            
            var_s7_1 = -var_s7_1;
            while (var_s0_2 >= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a3 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s4 * 2);
                }
                
                if (sp20 < var_s3)
                {
                    param_1(var_s0_2, var_s1_1);
                    var_s3 = 0;
                }
                var_s0_2 -= 1;
            }
        }
        else
        {
            var_s0_2 = sp10;
            temp_s6_1 = var_s0_2 + ((sp12 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2 = var_s0_2 + 1;
            var_s1_1 = sp14;
            
            while (var_s0_2 <= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a3 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s4 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s0_2, var_s1_1);
                    var_s3 = 0;
                }
                var_s0_2 += 1;
            }
        }
    }
    else
    {
        if (var_s4 < 0)
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            SwapAB(&sp14, &sp16);
            var_s5 = -var_s5;
            var_s4 = -var_s4;
        }
        else if ((var_s4 == 0) && (var_s5 < 0))
        {
            var_s0_1 = 1;
            SwapAB(&sp10, &sp12);
            var_s5 = -var_s5;
        }
        
        if (var_s5 <= 0)
        {
            var_s7_1 = var_s5 >> 0x1F;
        }
        else
            var_s7_1 = 1;
        var_s5 = __builtin_abs(var_s5);
        var_s2_1 = (var_s5 * 2) - var_s4;
        temp_a0 = var_s5 - var_s4;
        if (var_s0_1 != 0)
        {
            var_s0_2 = sp16;
            temp_s6_1 = var_s0_2 + ((sp14 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp12;
            var_s7_1 = -var_s7_1;
            while (var_s0_2 >= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a0 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s5 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s1_1, var_s0_2);
                    var_s3 = 0;
                }
                var_s0_2 -= 1;
            }
        }
        else
        {
            var_s0_2 = sp14;
            temp_s6_1 = var_s0_2 + ((sp16 - var_s0_2) * (s16) temp_s6_1 / 100);
            var_s0_2++;
            var_s1_1 = sp10;
            while (var_s0_2 <= temp_s6_1)
            {
                var_s3 += 1;
                if (var_s2_1 > 0)
                {
                    var_s1_1 += var_s7_1;
                    var_s2_1 += (s16) (temp_a0 * 2);
                }
                else
                {
                    var_s2_1 += (s16) (var_s5 * 2);
                }
                if (sp20 < var_s3)
                {
                    param_1(var_s1_1, var_s0_2);
                    var_s3 = 0;
                }
                var_s0_2 += 1;
            }
        }
    }
}
#endif

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
    finBosslevel.bzzit = false;
    finBosslevel.moskito = false;
    finBosslevel.mr_sax = false;
    finBosslevel.mr_stone = false;
    finBosslevel.viking_mama = false;
    finBosslevel.space_mama = false;
    finBosslevel.mr_skops = false;
    finBosslevel.mr_dark = false;
    finBosslevel.crazy_drummer = false;
    finBosslevel.helped_joe_1 = false;
    finBosslevel.helped_joe_2 = false;
    finBosslevel.helped_musician = false;
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

/* thanks :) https://decomp.me/scratch/UZKQ3 */
/* 25B2C 8014A32C -O2 -msoft-float */
void PS1_SetSauveRayEvts(void)
{
    SauveRayEvts.poing = RayEvts.poing;
    SauveRayEvts.hang = RayEvts.hang;
    SauveRayEvts.helico = RayEvts.helico;
    SauveRayEvts.super_helico = RayEvts.super_helico;
    SauveRayEvts.handstand_dash = RayEvts.handstand_dash;
    SauveRayEvts.handstand = RayEvts.handstand;
    SauveRayEvts.grain = RayEvts.grain;
    SauveRayEvts.grap = RayEvts.grap;
    
    SauveRayEvts.run = RayEvts.run;
    SauveRayEvts.demi = RayEvts.demi;
    SauveRayEvts.luciole = RayEvts.luciole;
    SauveRayEvts.force_run = RayEvts.force_run;
    SauveRayEvts.reverse = RayEvts.reverse;
    SauveRayEvts.unused_death = RayEvts.unused_death;
}

/* 25C3C 8014A43C -O2 -msoft-float */
void PS1_RestoreSauveRayEvts(void)
{
    RayEvts.poing = SauveRayEvts.poing;
    RayEvts.hang = SauveRayEvts.hang;
    RayEvts.helico = SauveRayEvts.helico;
    RayEvts.super_helico = SauveRayEvts.super_helico;
    RayEvts.handstand_dash = SauveRayEvts.handstand_dash;
    RayEvts.handstand = SauveRayEvts.handstand;
    RayEvts.grain = SauveRayEvts.grain;
    RayEvts.grap = SauveRayEvts.grap;
    
    RayEvts.run = SauveRayEvts.run;
    RayEvts.demi = SauveRayEvts.demi;
    RayEvts.luciole = SauveRayEvts.luciole;
    RayEvts.force_run = SauveRayEvts.force_run;
    RayEvts.reverse = SauveRayEvts.reverse;
    RayEvts.unused_death = SauveRayEvts.unused_death;
}
