#include "world_map_677C0.h"

/* 677C0 8018BFC0 -O2 */
void CalcObjPosInWorldMap(Obj *obj) {
    obj->screen_x_pos = obj->x_pos - xmap + 52;
    obj->screen_y_pos = obj->y_pos - ymap + 55;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DoScrollInWorldMap);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPts);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DISPLAY_PLAT_WAY);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayWorldMapObjects);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_MEDAILLONS);

/* M2C_ERROR( Unable to handle lwr; missing a corresponding lwl ); */
/* also on other functions in this file */
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_LEVEL_STAGE_NAME);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_STAGE_NAME);

/* 68CB8 8018D4B8 -O2 */
void INIT_STAGE_NAME(void) {
    INIT_TEXT_TO_DISPLAY();
    INIT_LEVEL_STAGE_NAME();
    INIT_WORLD_STAGE_NAME();

    text_to_display[1].x_pos = 160;
    text_to_display[1].y_pos = 250;
    text_to_display[1].field8_0x3d = FALSE;
    text_to_display[1].is_fond = FALSE;

    text_to_display[3].x_pos = 160;
    text_to_display[3].y_pos = -50;
    text_to_display[3].field8_0x3d = FALSE;
    text_to_display[3].is_fond = FALSE;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", CHANGE_STAGE_NAMES);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_CardDisplayPassword);

/* 691E0 8018D9E0 -O2 */
void PS1_WorldMapMoveText(void)
{
    if (text_to_display[0].x_pos > 160)
    {
        text_to_display[0].x_pos -= 6;
        text_to_display[0].centered_x_pos -= 6;
    }
    if (text_to_display[2].x_pos > 160)
    {
        text_to_display[2].x_pos -= 6;
        text_to_display[2].centered_x_pos -= 6;
    }
    if (text_to_display[1].y_pos < 320)
    {
        text_to_display[1].y_pos += 2;
        text_to_display[1].centered_y_pos += 2;
    }
    if (text_to_display[3].y_pos > -60)
    {
        text_to_display[3].y_pos -= 2;
        text_to_display[3].centered_y_pos -= 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_INFO);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_LITTLE_RAY);

/* 69428 8018DC28 -O2 */
void RESTORE_RAY(void) {
    ray.scale = 0;
    ray.sprites = raytmp.sprites;
    ray.img_buffer = raytmp.img_buffer;
    ray.nb_sprites = raytmp.nb_sprites;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_CHEMIN);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_UP);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_DOWN);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_RIGHT);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_LEFT);

/* 699A4 8018E1A4 -O2 */
void MoveRayInWorldMap(void) {
    h_scroll_speed = ray.speed_x;
    v_scroll_speed = ray.speed_y;
    ray.x_pos += ray.speed_x;
    decalage_en_cours = ray.speed_x;
    ray.y_pos += ray.speed_y;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_RAYMAN_IN_WLD_MAP);

/* 6A070 8018E870 -O2 */
void DO_CHEMIN(void)
{
    horloges();
    DO_RAYMAN_IN_WLD_MAP();
    DO_MEDAILLONS();
    RecaleRayPosInJumelle();
    DoScrollInWorldMap(h_scroll_speed, v_scroll_speed);
    PS1_WorldMapMoveText();
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_PASTILLES_SAUVE);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PASTILLES_SAUVE_SAVED);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", FIN_WORLD_CHOICE);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DETER_WORLD_AND_LEVEL);