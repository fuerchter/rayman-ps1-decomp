#include "moteur_init_end.h"

void init_flocons(void);

/* 347C4 80158FC4 -O2 -msoft-float */
void INIT_MOTEUR(u8 new_lvl)
{
    s16 i; s16 j; s16 *cur_data;
    u8 prev_num_wiz;

    for (i = 0; i < (s16) LEN(pix_gerbe); i++)
    {
        pix_gerbe[i].is_active = false;

        cur_data = &pix_gerbe[i].items[0];
        j = 0;
        while (j < (s16) (sizeof(pix_gerbe[i].items) / sizeof(s16)))
        {
            *cur_data = 0;
            cur_data++;
            j++;
        }
    }

    init_flocons();
    if (num_world == 1 && num_level == 9)
        set_SNSEQ_list(11);
    
    scrollLocked = false;
    Vignet_To_Display = 0;
    loop_time = 0;
    dans_la_map_monde = false;
    sko_rayon_on = 0;
    rubis_list_calculated = false;
    sko_last_action = 0;
    sko_enfonce_enable = 0;
    pixels_enfonce = 0;
    joe_exp_probleme = finBosslevel[1] >> 2 & 1;
    if (num_world == 5 && num_level == 10)
    {
        mp.height = 32;
        ymapmax = scroll_end_y = 312;
    }
    map_time = 0;
    left_time = -2;
    INIT_HORLOGES();
    ray.id = -1;
    actobj.num_active_objects = 0;
    actobj.objects[0] = -1;
    xmap = 0;
    ymap = 0;
    ymapmax = (mp.height * 16) - 240;
    xmapmax = ((u16) mp.width * 16) - (320 + 1);
    MAX_2(xmapmax, 0);
    MAX_2(ymapmax, 0);
    v_scroll_speed = 0;
    h_scroll_speed = 0;
    dvspeed = 0;
    dhspeed = 0;
    scroll_start_x = 0;
    scroll_start_y = 0;
    jump_time = 0;
    gerbe = false;
    PS1_MoteurTime = 0;
    decalage_en_cours = 0;
    ray_wind_force = 0;
    weather_wind = 0;
    screen_trembling = 0;
    lidol_to_allocate = 0;
    helico_time = -1;
    fin_boss = false;
    scroll_end_x = xmapmax;
    scroll_end_y = ymapmax;
    if (!fin_du_jeu)
        dead_time = 64;
    
    INIT_RAY(new_lvl);
    if (!bonus_map && departlevel && save1.has_saved)
    {
        prev_num_wiz = status_bar.num_wiz;
        restoreGameState(&save1);
        status_bar.num_wiz = prev_num_wiz;
    }

    if (!departlevel)
    {
        ray.flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
        ray.x_pos = ray_X_main_pos_init;
        ray.y_pos = ray_Y_main_pos_init;
        xmap = xmapsave;
        ymap = ymapsave;
    }
    else
        nb_wiz_collected = 0;
    
    INIT_OBJECTS(new_lvl);
    correct_link();
    deactivate_ship_links();
    special_flags_init();
    if (RayEvts.flags1 & FLG(RAYEVTS1_LUCIOLE))
        INIT_LUCIOLE();
    
    DO_OBJECTS();
    PS1_PhotographerCollision();
}

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", INIT_MOTEUR_BEGIN);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", INIT_MOTEUR_WORLD);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", INIT_MOTEUR_LEVEL);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", restore_gendoor_link);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", DONE_MOTEUR_LEVEL);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", INIT_MOTEUR_DEAD);

INCLUDE_ASM("asm/nonmatchings/moteur_init_end", INIT_RAY_ON_MS);
