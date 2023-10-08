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

/* 68220 8018CA20 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_LEVEL_STAGE_NAME);
#else
/*? INIT_TXT_BOX(s8 *);
? PS1_GenerateAndDisplayPassword();
extern ? D_801C3366;
extern ? D_801C3368;
extern ? D_801C336C;
extern u16 D_801E4F8A;
extern u16 D_801E4F8C;
extern s16 D_801E4F90;
extern s16 D_801E4F92;
extern s8 D_801E4F94;
extern s8 D_801E4F95;
extern s8 D_801E4F96;
extern u8 D_801E4F97;*/

void INIT_LEVEL_STAGE_NAME(void)
{
  if (t_world_info[num_world_choice].world == 7 && NBRE_SAVE == 0)
    PS1_GenerateAndDisplayPassword();
  else
    __builtin_memcpy(&text_to_display[0], t_world_info[num_world_choice].level_name, 48);

  text_to_display[0].font_size = 2;
  text_to_display[0].x_pos = 450;
  text_to_display[0].y_pos = 220;
  text_to_display[0].is_fond = FALSE;
  text_to_display[0].field8_0x3d = TRUE;
  INIT_TXT_BOX(text_to_display);
  text_to_display[0].centered_y_pos -= 6;
  text_to_display[0].width += 10;
  text_to_display[0].height += 6;
  text_to_display[0].color = t_world_info[num_world_choice].color;

  __asm__("nop\nnop\nnop");
}
#endif

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

/* 68D34 8018D534 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", CHANGE_STAGE_NAMES);
#else
/*? INIT_LEVEL_STAGE_NAME(s32, s32, ? *, void *);
? INIT_WORLD_STAGE_NAME(s32, s32, ? *, void *);
extern ? D_801C3366;
extern ? D_801E4F98;
extern ? D_801E5018;*/

void CHANGE_STAGE_NAMES(void)
{    
    __builtin_memcpy(&text_to_display[1], &text_to_display[0], sizeof(TextToDisplay));
    INIT_LEVEL_STAGE_NAME();
    if (t_world_info[num_world_choice].world != t_world_info[old_num_world].world)
    {
        __builtin_memcpy(&text_to_display[3], &text_to_display[2], sizeof(TextToDisplay));
        INIT_WORLD_STAGE_NAME();
    }

    __asm__("nop\nnop");
}
#endif


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

/* 693B4 8018DBB4 -O2 */
void INIT_LITTLE_RAY(void)
{
    __builtin_memcpy(&raytmp, &ray, sizeof(Obj));
    ray.scale = 0x100;
    ray.sprites = raylittle.sprites;
    ray.img_buffer = raylittle.img_buffer;
}

/* 69428 8018DC28 -O2 */
void RESTORE_RAY(void)
{
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