#include "world_map_677C0.h"

/* 677C0 8018BFC0 -O2 */
void CalcObjPosInWorldMap(Obj *obj) {
    obj->screen_x_pos = obj->x_pos - xmap + 52;
    obj->screen_y_pos = obj->y_pos - ymap + 55;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DoScrollInWorldMap);

/* 678DC 8018C0DC -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPts);
#else
void PS1_DisplayPts(s16 from, s16 to, s16 from_x, s16 from_y)
{
    u32 state;

    if (to != from)
    {
        state = *(u32*)&t_world_info[to].state;
        if(!(state >> 1 & 1))
        {
            if (state & 1)
            {
                DISPLAY_PTS_TO_PLAN2(
                    from_x,
                    from_y,
                    t_world_info[to].x_pos,
                    t_world_info[to].y_pos,
                    100
                );
            }
            else if (state >> 2 & 1)
            {
                DISPLAY_PTS_TO_PLAN2(
                    from_x,
                    from_y,
                    t_world_info[to].x_pos,
                    t_world_info[to].y_pos,
                    chemin_percent
                );
            }
        }
    }

    __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DISPLAY_PLAT_WAY);

/* 67B0C 8018C30C -O2 */
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPlateau);

/* 67BE8 8018C3E8 -O2 */
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_MEDAILLONS);

/* 68220 8018CA20 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_LEVEL_STAGE_NAME);
#else
/*? INIT_TXT_BOX(s8 *);
? PS1_GenerateAndDisplayPassword();*/

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

/* 683FC 8018CBFC -O2 */
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
? INIT_WORLD_STAGE_NAME(s32, s32, ? *, void *);*/

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

/* 68EF4 8018D6F4 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_CardDisplayPassword);
#else
void PS1_CardDisplayPassword(void)
{
  u8 color;

  __builtin_memcpy(&text_to_display[1], &text_to_display[0], sizeof(TextToDisplay));
  __builtin_memcpy(&text_to_display[3], &text_to_display[2], sizeof(TextToDisplay));

  PS1_GenerateAndDisplayPassword();

  color = t_world_info[num_world_choice].color;
  text_to_display[2].font_size = 1;
  text_to_display[2].color = color;
  text_to_display[2].x_pos = 450;
  text_to_display[2].y_pos = 40;
  text_to_display[2].is_fond = 0;
  text_to_display[2].field8_0x3d = 0;
  INIT_TXT_BOX(&text_to_display[2]);

  text_to_display[0].font_size = 2;
  text_to_display[0].x_pos = 450;
  text_to_display[0].y_pos = 220;
  text_to_display[0].is_fond = 0;
  text_to_display[0].field8_0x3d = 0;
  text_to_display[2].width += 10;
  text_to_display[2].height += 2;
  INIT_TXT_BOX(&text_to_display[0]);

  text_to_display[0].centered_y_pos -= 6;
  text_to_display[0].width += 10;
  text_to_display[0].height += 6;
  text_to_display[0].color = t_world_info[num_world_choice].color;
  text_to_display[1].x_pos = 160;
  text_to_display[1].y_pos = 250;
  text_to_display[1].field8_0x3d = 0;
  text_to_display[1].is_fond = 0;
  text_to_display[3].x_pos = 160;
  text_to_display[3].y_pos = -50;
  text_to_display[3].field8_0x3d = 0;
  text_to_display[3].is_fond = 0;

  __asm__("nop\nnop");
}
#endif

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

/* 69468 8018DC68 -O2 */
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_CHEMIN);

/* https://decomp.me/scratch/6ivxi PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 698B4 8018E0B4 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_UP);
#else
void RESPOND_TO_UP(void)
{
    num_world_choice = t_world_info[num_world_choice].index_up;

    __asm__("nop");
}
#endif

/* 698F0 8018E0F0 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_DOWN);
#else
void RESPOND_TO_DOWN(void)
{
    num_world_choice = t_world_info[num_world_choice].index_down;

    __asm__("nop");
}
#endif

/* 6992C 8018E12C -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_RIGHT);
#else
void RESPOND_TO_RIGHT(void)
{
    num_world_choice = t_world_info[num_world_choice].index_right;

    __asm__("nop");
}
#endif

/* 69968 8018E168 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_LEFT);
#else
void RESPOND_TO_LEFT(void)
{
    num_world_choice = t_world_info[num_world_choice].index_left;

    __asm__("nop");
}
#endif

/* 699A4 8018E1A4 -O2 */
void MoveRayInWorldMap(void)
{
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

/* 6A130 8018E930 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PASTILLES_SAUVE_SAVED);
#else
/*? INIT_PASTILLES_SAUVE();*/

void PASTILLES_SAUVE_SAVED(s16 wld)
{
    INIT_PASTILLES_SAUVE();
    t_world_info[wld].level_name = PTR_s_game_saved_801c3540;

    __asm__("nop");
}
#endif

/* 6A180 8018E980 -O2 */
/*void INIT_PASTILLES_SAUVE(void);*/

void FIN_WORLD_CHOICE(void)
{
    xwldmapsave = xmap;
    ywldmapsave = ymap;
    xmap = xmapinit;
    ymap = ymapinit;

    dir_on_wldmap = ray.flags >> 0xE & 1;
    RESTORE_RAY();
    INIT_PASTILLES_SAUVE();
    PROC_EXIT = FALSE;
    if (ray.hit_points == 0xFF)
        ray.hit_points = 0;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DETER_WORLD_AND_LEVEL);