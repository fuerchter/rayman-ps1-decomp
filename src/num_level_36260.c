#include "num_level_36260.h"

#ifdef BSS_DEFS
s16 departlevel;
FinBosslevel finBosslevel;
u8 fin_boss;
#endif

/* 36260 8015AA60 -O2 -msoft-float */
void new_level_init(void)
{
    departlevel = true;
    ray_X_main_pos_init = ray.x_pos;
    ray_Y_main_pos_init = ray.y_pos;
    xmapsave = xmap;
    ymapsave = ymap;
}

/* 362B4 8015AAB4 -O2 -msoft-float */
void fix_numlevel(Obj *obj)
{
    s16 unk_1 = false;

    if (departlevel && (new_level_init(), obj->type != TYPE_WIZARD1))
    {
        switch (num_world)
        {
        case 1:
            if (num_level == 2 && RayEvts.poing)
                num_level_choice++;

            if (num_level == 5 && finBosslevel.bzzit)
                num_level_choice++;

            if (num_level == 7 && RayEvts.hang)
                new_world = true;

            if (num_level == 13 && finBosslevel.moskito)
                num_level_choice++;

            if (num_level == 15 && finBosslevel.moskito)
                new_world = true;

            if (num_level == 16 && RayEvts.grap)
                new_world = true;
            break;
        case 2:
            if (num_level == 5 && finBosslevel.crazy_drummer)
                new_world = true;

            if (num_level == 9 && finBosslevel.mr_sax)
                new_world = true;

            if (num_level == 10 && RayEvts.helico)
                new_world = true;

            if (num_level == 14 && finBosslevel.mr_sax)
                new_world = true;
            break;
        case 3:
            if (num_level == 1 && finBosslevel.mr_stone)
                new_world = true;

            if (num_level == 9 && finBosslevel.mr_stone)
                new_world = true;

            if (num_level == 10 && RayEvts.run)
                new_world = true;
            break;
        case 4:
            if (num_level == 3 && finBosslevel.viking_mama)
                new_world = true;

            if (num_level == 10 && finBosslevel.space_mama)
                new_world = true;
            break;
        case 5:
            if (num_level == 9 && finBosslevel.mr_skops)
                new_world = true;
            break;
        case 6:
            if (num_level == 1 && finBosslevel.mr_dark)
                new_world = true;
            break;
        }
    }

    switch (num_world)
    {
    case 1:
        switch (num_level)
        {
        case 2:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 21;
                unk_1 = true;
            }
            break;
        case 4:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 20;
                unk_1 = true;
                break;
            }
            else
            {
                new_world = true;
                if (!t_world_info[1].is_unlocked)
                {
                    t_world_info[1].is_unlocking = true;
                    t_world_info[18].is_unlocking = true;
                }
            }
            break;
        case 8:
            new_world = true;
            if (!t_world_info[2].is_unlocked)
                t_world_info[2].is_unlocking = true;

            if (!t_world_info[4].is_unlocked)
                t_world_info[4].is_unlocking = true;
            break;
        case 11:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 18;
                unk_1 = true;
            }
            else
            {
                new_world = true;
                if (!t_world_info[3].is_unlocked)
                    t_world_info[3].is_unlocking = true;
            }
            break;
        case 12:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 19;
                unk_1 = true;
            }
            break;
        case 17:
            new_world = true;
            break;
        case 18:
            num_level_choice = 11;
            unk_1 = true;
            break;
        case 19:
            num_level_choice = 12;
            unk_1 = true;
            break;
        case 20:
            num_level_choice = 4;
            unk_1 = true;
            break;
        case 21:
            num_level_choice = 2;
            unk_1 = true;
            break;
        }
        break;
    case 2:
        switch (num_level)
        {
        case 4:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 17;
                unk_1 = true;
            }
            break;
        case 6:
            new_world = true;
            if (!t_world_info[5].is_unlocked)
            {
                t_world_info[5].is_unlocking = true;
                t_world_info[19].is_unlocking = true;
            }
            break;
        case 9:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 18;
                unk_1 = true;
            }
            break;
        case 11:
            new_world = true;
            if (!t_world_info[6].is_unlocked)
                t_world_info[6].is_unlocking = true;

            if (!t_world_info[8].is_unlocked)
                t_world_info[8].is_unlocking = true;
            break;
        case 13:
            new_world = true;
            if (!(t_world_info[7].is_unlocked))
            {
                t_world_info[7].is_unlocking = true;
                t_world_info[20].is_unlocking = true;
            }
            break;
        case 16:
            new_world = true;
            break;
        case 17:
            num_level_choice = 4;
            unk_1 = true;
            break;
        case 18:
            num_level_choice = 9;
            unk_1 = true;
            break;
        }
        break;
    case 3:
        switch (num_level)
        {
        case 2:
            new_world = true;
            if (!t_world_info[9].is_unlocked)
                t_world_info[9].is_unlocking = true;
            break;
        case 4:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 12;
                unk_1 = true;
            }
            break;
        case 5:
            new_world = true;
            if (!t_world_info[10].is_unlocked)
            {
                t_world_info[10].is_unlocking = true;
                t_world_info[21].is_unlocking = true;
            }
            break;
        case 9:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 13;
                unk_1 = true;
            }
            break;
        case 11:
            new_world = true;
            if (!t_world_info[11].is_unlocked)
                t_world_info[11].is_unlocking = true;
            break;
        case 12:
            num_level_choice = 4;
            unk_1 = true;
            break;
        case 13:
            num_level_choice = 9;
            unk_1 = true;
            break;
        }
        break;
    case 4:
        switch (num_level)
        {
        case 3:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 12;
                unk_1 = true;
            }
            break;
        case 4:
            new_world = true;
            if (!t_world_info[12].is_unlocked)
                t_world_info[12].is_unlocking = true;
            break;
        case 7:
            new_world = true;
            if (!t_world_info[13].is_unlocked)
                t_world_info[13].is_unlocking = true;
            break;
        case 9:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 13;
                unk_1 = true;
            }
            break;
        case 11:
            new_world = true;
            if (!t_world_info[14].is_unlocked)
            {
                Vignet_To_Display = 1;
                t_world_info[14].is_unlocking = true;
                t_world_info[22].is_unlocking = true;
            }
            break;
        case 12:
            num_level_choice = 3;
            unk_1 = true;
            break;
        case 13:
            num_level_choice = 9;
            unk_1 = true;
            break;
        }
        break;
    case 5:
        switch (num_level)
        {
        case 2:
            if (obj->type == TYPE_WIZARD1)
            {
                num_level_choice = 12;
                unk_1 = true;
            }
            else
            {
                new_world = true;
                if (!t_world_info[15].is_unlocked)
                {
                    t_world_info[15].is_unlocking = true;
                    t_world_info[22].is_unlocking = true;
                }
            }
            break;
        case 8:
            new_world = true;
            if (!t_world_info[16].is_unlocked)
            {
                t_world_info[16].is_unlocking = true;
                t_world_info[23].is_unlocking = true;
            }
            break;
        case 11:
            new_world = true;
            Vignet_To_Display = 1;
            break;
        case 12:
            num_level_choice = 2;
            unk_1 = true;
            break;
        }
        break;
    case 6:
        if (num_level == 4)
        {
            new_world = true;
            You_Win = true;
            fin_du_jeu = true;
            fin_dark = true;
        }
        break;
    }

    if (!t_world_info[17].is_unlocked && Nb_total_cages >= 102)
        t_world_info[17].is_unlocking = true;

    if (!new_world && !unk_1)
        num_level_choice++;

    new_level = true;
}
const u8 rodata_fix_numlevel[4] = {};

/* 36D54 8015B554 -O2 -msoft-float */
void TEST_SIGNPOST(void)
{
    s32 poing_id;
    u32 sub_etat;

    if (ray.main_etat == 2 && ray.sub_etat != 8)
    {
        if (ray.speed_x != 0 && decalage_en_cours == 0)
            ray.x_pos -= ray.speed_x;

        no_ray_landing_smoke = true;
        ray.speed_x = 0;
        decalage_en_cours = 0;
        if (ray.speed_y <= -1)
            ray.speed_y = 0;
    }
    else if (ray.main_etat < 2 && ray.iframes_timer == -1 && gele == 0)
    {
        if (fin_boss)
            set_main_and_sub_etat(&ray, 3, 52);
        else
            set_main_and_sub_etat(&ray, 3, 23);
        ray.anim_frame = 0;
        if (poing.is_active)
        {
            poing_id = poing_obj_id;
            poing.is_active = false;
            level.objects[poing_id].flags &= ~FLG(OBJ_ALIVE);
            DO_NOVA(&level.objects[poing_id]);
            fin_poing_follow(&level.objects[poing_obj_id], false);
        }
        if (ray_on_poelle == true)
        {
            PS1_RestoreSauveRayEvts();
            decalage_en_cours = 0;
            Reset_air_speed(false);
            Reset_air_speed(true);
            ray_on_poelle = false;
        }
        test_fin_cling();
        decalage_en_cours = 0;
        ray.speed_x = 0;
        if (!fin_boss && !ray_on_poelle && num_world != 6)
            gele = 2;
        start_cd_gagne();
    }
    else if (ray.main_etat == 3 && (sub_etat = ray.sub_etat, sub_etat == 23 || sub_etat == 52))
    {
        if (EOA(&ray))
        {
            ChangeLevel();
            gele = 0;
        }
        else
        {
            ray.speed_x = 0;
            ray.speed_y = 0;
            decalage_en_cours = 0;
            NumScrollObj = 0;
            if (ray.field20_0x36 != -1)
            {
                level.objects[ray.field20_0x36].speed_y = 0;
                level.objects[ray.field20_0x36].speed_x = 0;
                level.objects[ray.field20_0x36].gravity_value_1 = 0;
                level.objects[ray.field20_0x36].gravity_value_2 = 0;
            }
        }
    }
    else if (ray.main_etat == 6) /* on moskito, al3? */
    {
        if (ray.sub_etat != 14)
        {
            start_cd_gagne();
            set_sub_etat(&ray, 14);
            ray.anim_frame = 0;
        }
        gele = 2;
        decalage_en_cours = 0;
        ray.speed_x = 0;
        ray.speed_y = 0;
        if (ray.sub_etat == 14)
        {
            if (EOA(&ray))
            {
                ChangeLevel();
                gele = 0;
            }
        }
    }
}