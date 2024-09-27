#include "cheats.h"

/* 7ABA0 8019F3A0 -O2 -msoft-float */
void PS1_CheckPauseAndCheatInputs(void)
{
    if (PS1_Ingame && PS1_TOUCHE_0x9(0))
    {
        if (in_pause == true)
        {
            in_pause = false;
            PS1_OnPauseOff();
        }
        else
        {
            in_pause = true;
            PS1_OnPauseOn();
        }
    }
    if (PS1_DebugMode)
    {
        if (PS1_TOUCHE_0xA(0))
            PS1_MemoryUsageDisplayMode = (PS1_MemoryUsageDisplayMode + 1) % 3;
        if (PS1_DebugMode)
        {
            if (PS1_TOUCHE_0xE(0))
            {
                ray.main_etat = 2;
                ray.sub_etat = 2;
                dead_time = 64;
                ray.field20_0x36 = -1;
                ray_mode = -ray_mode;
            }
            if (PS1_DebugMode)
            {
                if (PS1_TOUCHE_0xC(0))
                {
                    D_801CF0D8++;
                    if (D_801CF0D8 == 8)
                        D_801CF0D8 = 0;
                }
                if (PS1_DebugMode && PS1_TOUCHE_0xB(0))
                    D_801CEFC8 = !D_801CEFC8;
            }
        }
    }
    if (PS1_TOUCHE_0xF(0))
        PS1_DebugMode = true;
    
    if (in_pause)
    {
        if (PS1_TOUCHE_0x12(0))
        {
            if (ray.hit_points != 0xFF && !fin_du_jeu)
            {
                ray.hit_points = 4;
                status_bar.max_hp = 4;
            }
            in_pause = false;
            PS1_OnPauseOff();
        }
        if (in_pause)
        {
            if (PS1_TOUCHE_0x17(0))
            {
                if (ray.hit_points != 0xFF && !fin_du_jeu)
                {
                    status_bar.num_lives = 5;
                    status_bar.max_hp = ray.hit_points;
                }
                in_pause = false;
                PS1_OnPauseOff();
            }
            if (in_pause)
            {
                if (PS1_TOUCHE_0x18(0))
                {
                    if (ray.hit_points != 0xFF && !fin_du_jeu)
                    {
                        status_bar.num_lives = 99;
                        ray.hit_points = 4;
                        status_bar.max_hp = 4;
                    }
                    in_pause = false;
                    PS1_OnPauseOff();
                }
                if (in_pause)
                {
                    if (PS1_TOUCHE_0x14(0))
                    {
                        in_pause = false;
                        PS1_PictureInPicture = 1 - PS1_PictureInPicture;
                        PS1_OnPauseOff();
                    }
                    if (in_pause)
                    {
                        if (PS1_TOUCHE_0x16(0))
                        {
                            in_pause = false;
                            PS1_15fps = 1 - PS1_15fps;
                            PS1_OnPauseOff();
                        }
                        if (in_pause)
                        {
                            if (PS1_TOUCHE_0x15(0))
                            {
                                in_pause = false;
                                fin_boss = 1 - fin_boss;
                                PS1_OnPauseOff();
                            }
                            if (in_pause && PS1_TOUCHE_0x13(0))
                            {
                                in_pause = false;
                                RayEvts.poing = true;
                                RayEvts.helico = true;
                                RayEvts.run = true;
                                RayEvts.hang = true;
                                RayEvts.handstand_dash = true;
                                RayEvts.grap = true;
                                PS1_OnPauseOff();
                            }
                        }
                    }
                }
            }
        }
    }
    if (PS1_TOUCHE_0x10(0))
    {
        PS1_DebugMode = false;
        D_801CF0D8 = 0;
        D_801CEFC8 = 0;
        PS1_MemoryUsageDisplayMode = 0;
    }
}