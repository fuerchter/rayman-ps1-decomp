#include "world_map_677C0.h"

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
