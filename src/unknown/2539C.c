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

/* 254AC 80149CAC -O2 -msoft-float */
void Bresenham(void (*draw)(s16, s16), s16 x0, s16 y0, s16 x1, s16 y1, s16 param_6, s16 param_7) {
    s32 x, y;
    s16 var_s3;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_s6_1;
    s16 var_s0_1;
    s32 D;
    s32 dx, dy;
    s32 xi, yi;
    s16 temp_p6;

    var_s0_1 = 0;
    dx = x1 - x0;
    dy = y1 - y0;
    temp_p6 = param_6;
    if (dx == 0) {
        var_s3 = 0;
    } else {
        var_s3 = __builtin_abs(dy / dx) < 1;
    }
    if (var_s3 == 1) {
        if (dx < 0) {
            var_s0_1 = 1;
            SwapAB(&x0, &x1);
            SwapAB(&y0, &y1);
            dx = -dx;
            dy = -dy;
        } else if (dx == 0 && dy < 0) {
            var_s0_1 = 1;
            SwapAB(&y0, &y1);
            dy = -dy;
        }

        if (dy <= 0) {
            yi = dy >> 31;
        } else {
            yi = 1;
        }

        dy = __builtin_abs(dy);
        D = (dy * 2) - dx;
        temp_a3 = dy - dx;
        if (var_s0_1) {
            x = x1;
            temp_s6_1 = x + ((x0 - x) * param_7 / 100);
            x++;
            y = y1;
            
            yi = -yi;
            while (x >= temp_s6_1) {
                var_s3++;
                if (D > 0) {
                    y += yi;
                    D += (s16) (temp_a3 * 2);
                } else {
                    D += (s16) (dy * 2);
                }
                
                if (temp_p6 < var_s3) {
                    draw(x, y);
                    var_s3 = 0;
                }
                x--;
            }
        } else {
            x = x0;
            temp_s6_1 = x + ((x1 - x) * param_7 / 100);
            x++;
            y = y0;
            
            while (x <= temp_s6_1) {
                var_s3++;
                if (D > 0) {
                    y += yi;
                    D += (s16) (temp_a3 * 2);
                } else {
                    D += (s16) (dy * 2);
                }
                if (temp_p6 < var_s3) {
                    draw(x, y);
                    var_s3 = 0;
                }
                x++;
            }
        }
    }
    else
    {
        if (dy < 0) {
            var_s0_1 = 1;
            SwapAB(&x0, &x1);
            SwapAB(&y0, &y1);
            dx = -dx;
            dy = -dy;
        } else if ((dy == 0) && (dx < 0)) {
            var_s0_1 = 1;
            SwapAB(&x0, &x1);
            dx = -dx;
        }
        
        if (dx <= 0) {
            xi = dx >> 0x1F;
        } else {
            xi = 1;
        }
        dx = __builtin_abs(dx);
        D = (dx * 2) - dy;
        temp_a0 = dx - dy;
        if (var_s0_1) {
            y = y1;
            temp_s6_1 = y + ((y0 - y) * param_7 / 100);
            y++;
            x = x1;
            xi = -xi;
            while (y >= temp_s6_1) {
                var_s3++;
                if (D > 0) {
                    x += xi;
                    D += (s16) (temp_a0 * 2);
                } else {
                    D += (s16) (dx * 2);
                }
                if (temp_p6 < var_s3) {
                    draw(x, y);
                    var_s3 = 0;
                }
                y--;
            }
        } else {
            y = y0;
            temp_s6_1 = y + ((y1 - y) * param_7 / 100);
            y++;
            x = x0;
            while (y <= temp_s6_1) {
                var_s3++;
                if (D > 0) {
                    x += xi;
                    D += (s16) (temp_a0 * 2);
                } else {
                    D += (s16) (dx * 2);
                }
                if (temp_p6 < var_s3) {
                    draw(x, y);
                    var_s3 = 0;
                }
                y++;
            }
        }
    }
}

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
