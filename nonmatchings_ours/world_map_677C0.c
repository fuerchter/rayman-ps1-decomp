#include "world_map_677C0.h"

/* matches, but WorldInfo.state casts... */
/* 67BE8 8018C3E8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_MEDAILLONS);*/

void DO_MEDAILLONS(void)
{
    s16 i;
    Obj *cur_obj;
    WorldInfo *cur_wi;
    u8 nb_cages;
    u8 flag_set;

    if (chemin_percent < 100 && horloge[2] != 0)
        chemin_percent++;
    i = 0;
    cur_obj = mapobj;
    cur_wi = &t_world_info[0];
    while(i < 24)
    {
        CalcObjPosInWorldMap(cur_obj);
        if ((*(u32 *)(&cur_wi->state) & 4) && chemin_percent > 98)
        {
            *(u32 *)(&cur_wi->state) = *(u32 *)(&cur_wi->state) & ~(1 << 2) | 1;
            set_sub_etat(cur_obj, 46);
        }
        if (
            i == 17 &&
            cur_obj->sub_etat != 59 && cur_obj->sub_etat != 46 &&
            *(u32 *)(&cur_wi->state) & 1
        )
            set_sub_etat(cur_obj, 59);
        else if (
            (i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23) &&
            !(cur_obj->sub_etat == 58 || cur_obj->sub_etat == 46) &&
            *(u32 *)(&cur_wi->state) & 1
        )
            set_sub_etat(cur_obj, 58);
        else
        {
            nb_cages = cur_wi->nb_cages;
            if (
                nb_cages > 5 && cur_obj->sub_etat == 51 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 52);
            else if (
                nb_cages > 4 && cur_obj->sub_etat == 50 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 51);
            else if (
                nb_cages > 3 && cur_obj->sub_etat == 49 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 50);
            else if (
                nb_cages > 2 && cur_obj->sub_etat == 48 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 49);
            else if (
                nb_cages > 1 && cur_obj->sub_etat == 47 &&
                (flag_set = cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].flags & 0x10,
                    (!flag_set || cur_obj->anim_frame == 0) &&
                    (flag_set || cur_obj->anim_frame == cur_obj->animations[cur_obj->anim_index].frames_count - 1) &&
                    horloge[cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_speed & 0xf] == 0
                )
            )
                set_sub_etat(cur_obj, 48);
        }
        DO_ANIM(cur_obj);
        cur_obj++;
        i++;
        cur_wi++;
    }
}

/* matches, but casts */
/* 683FC 8018CBFC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_STAGE_NAME);*/

void INIT_WORLD_STAGE_NAME(void)
{
    u8 new_color;
    u8 save_text[80];

    switch(t_world_info[num_world_choice].world)
    {
    case 7:
        new_color = t_world_info[num_world_choice].color;
        switch(fichier_selectionne)
        {
        case 0:
            if (NBRE_SAVE != 0)
                __builtin_memcpy(text_to_display[2].text, s___801cf0a4, sizeof(text_to_display[2].text));
            else
                __builtin_memcpy(text_to_display[2].text, s_password_8012ba1c, sizeof(s_password_8012ba1c));
            break;
        case 1:
            *(u16 *)&save_text[0] = *(u16 *)&s__801cf0a8[0];
            strcat(save_text, save_ray[fichier_selectionne]);
            strcat(save_text, s__801cf0a8);
            __builtin_memcpy(text_to_display[2].text, save_text, sizeof(text_to_display[2].text));
            break;
        case 2:
            *(u16 *)&save_text[0] = *(u16 *)&s__801cf0a8[0];
            strcat(save_text, save_ray[fichier_selectionne]);
            strcat(save_text, s__801cf0a8);
            __builtin_memcpy(text_to_display[2].text, save_text, sizeof(text_to_display[2].text));
            break;
        case 3:
            *(u16 *)&save_text[0] = *(u16 *)&s__801cf0a8[0];
            strcat(save_text, save_ray[fichier_selectionne]);
            strcat(save_text, s__801cf0a8);
            __builtin_memcpy(text_to_display[2].text, save_text, sizeof(text_to_display[2].text));
            break;
        }
        break;
    case 1:
        __builtin_memcpy(text_to_display[2].text, s_the_dream_forest_8012ba28, sizeof(text_to_display[2].text));
        new_color = 7;
        break;
    case 2:
        __builtin_memcpy(text_to_display[2].text, s_band_land_8012ba3c, sizeof(text_to_display[2].text));
        new_color = 4;
        break;
    case 3:
        __builtin_memcpy(text_to_display[2].text, s_blue_mountains_8012ba48, sizeof(text_to_display[2].text));
        new_color = 13;
        break;
    case 4:
        __builtin_memcpy(text_to_display[2].text, s_picture_city_8012ba5c, sizeof(text_to_display[2].text));
        new_color = 0;
        break;
    case 5:
        __builtin_memcpy(text_to_display[2].text, s_the_cave_of_skops_8012ba6c, sizeof(text_to_display[2].text));
        new_color = 2;
        break;
    case 6:
        __builtin_memcpy(text_to_display[2].text, s_candy_chateau_8012ba80, sizeof(text_to_display[2].text));
        new_color = 1;
        break;
    }
    
    text_to_display[2].font_size = 1;
    text_to_display[2].x_pos = 450;
    text_to_display[2].y_pos = 40;
    text_to_display[2].is_fond = false;
    text_to_display[2].field8_0x3d = true;
    text_to_display[2].color = new_color;
    INIT_TXT_BOX(&text_to_display[2]);
    text_to_display[2].width += 10;
    text_to_display[2].height += 2;
}
const u8 rodata_INIT_WORLD_STAGE_NAME[4] = {};

/* matches, but WorldInfo.state */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_INFO);*/

/* 692CC 8018DACC -O2 */
/*? INIT_PASTILLES_SAUVE(s32, s16, s32);*/
extern u8 D_801C3364;

void INIT_WORLD_INFO(void)
{
    s16 var_a1;
    s32 var_a0;
    s32 var_a2;
    u32 test_1;
    u8 *new_var;
    if (D_801F3EA0 != 0)
    {
        var_a1 = 0;
        var_a2 = ~FLG(2);
        while (var_a1 < (s16) LEN(t_world_info))
        {
            var_a0 = var_a1;
            var_a0 = var_a0 * 0x14;
            *(s32 *) (&D_801C3364 + var_a0) = (*(s32 *) (&D_801C3364 + var_a0) | 1) & var_a2;
            /**(u32 *)&t_world_info[var_a1].state |= 1;
            *(u32 *)&t_world_info[var_a1].state &= var_a2;*/
            var_a1 = var_a1 + 1;
        }
    }
    num_world = 0;
    num_level = 0;
    new_world = true;
    new_level = true;
    world_index = 0;
    xwldmapsave = 0;
    ywldmapsave = 158;
    dir_on_wldmap = 1;
    You_Win = false;
    fin_du_jeu = false;
    INIT_PASTILLES_SAUVE();
}

/* matches, but WorldInfo.state */
/* 69468 8018DC68 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_CHEMIN);*/

void INIT_CHEMIN(void)
{
    Obj *cur_obj;
    u8 world_ind;
    s16 i;

    PROC_EXIT = false;
    dans_la_map_monde = true;
    gele = 0;

    if (ModeDemo == 0)
    {
        new_world = false;
        num_world_choice = world_index;
    }
    old_num_world = num_world_choice;
    
    INIT_LITTLE_RAY();
    set_main_and_sub_etat(&ray, 0, 0);
    ray.x_pos = t_world_info[num_world_choice].x_pos - ray.offset_bx + 4;
    ray.y_pos = t_world_info[num_world_choice].y_pos - ray.offset_by + 8;
    ray.speed_x = 0;
    ray.speed_y = 0;
    set_zoom_mode(0);
    chemin_percent = 0;
    Nb_total_cages = 0;

    world_ind = 0; /* why does this exist? */
    cur_obj = mapobj;
    i = 0;
    while (i < (s16) LEN(t_world_info))
    {
        cur_obj->type = TYPE_MEDAILLON;
        cur_obj->init_x_pos = t_world_info[world_ind].x_pos - 78;
        cur_obj->init_y_pos = t_world_info[world_ind].y_pos - 64;
        cur_obj->init_main_etat = 5;

        if (!(*(u32*)&t_world_info[world_ind].state >> 2 & 1))
        {
            if (t_world_info[world_ind].nb_cages != 0)
            {
                Nb_total_cages += t_world_info[world_ind].nb_cages;
                
                if (t_world_info[world_ind].nb_cages == 6)
                    cur_obj->init_sub_etat = 52;
                else
                    cur_obj->init_sub_etat = 47;
            }
            else
            {
                if (i == 17)
                    cur_obj->init_sub_etat = cur_obj->sub_etat = 59;
                else
                    cur_obj->init_sub_etat = 39;
            }
        }
        else
            cur_obj->init_sub_etat = 46;

        cur_obj->scale = 0;
        cur_obj->offset_bx = 80;
        cur_obj->offset_by = 64;
        obj_init(cur_obj);
        CalcObjPosInWorldMap(cur_obj);
        cur_obj->anim_frame =
            i % cur_obj->animations[
                cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].anim_index
            ].frames_count;

        world_ind++;
        MIN_2(world_ind, LEN(t_world_info));
        cur_obj++;
        i++;
    }

    if (!(*(u32*)&t_world_info[17].state >> 0 & 1) && Nb_total_cages >= 102)
        *(u32*)&t_world_info[17].state |= FLG(2);

    scroll_end_x = 156;
    scroll_end_y = 158;
    scroll_x = -1;
    scroll_y = -1;
    special_ray_mov_win_x_left = 30;
    special_ray_mov_win_x_right = 30;
    scroll_start_x = 0;
    scroll_start_y = 0;
    xmapinit = xmap;
    ymapinit = ymap;
    xmap = xwldmapsave;
    ymap = ywldmapsave;
    ray.flags = ray.flags & ~FLG(OBJ_FLIP_X) | (dir_on_wldmap & 1) << OBJ_FLIP_X;
    INIT_PASTILLES_SAUVE();
    INIT_STAGE_NAME();
    if (nouvelle_partie)
    {
        if (NBRE_SAVE != 0)
            SaveGameOnDisk(fichier_selectionne);
        nouvelle_partie = false;
    }
}