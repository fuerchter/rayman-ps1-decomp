#include "world_map_677C0.h"

const u8 s_password_8012ba1c[] = "/password/";
const u8 s_the_dream_forest_8012ba28[] = "/the dream forest/";
const u8 s_band_land_8012ba3c[] = "/band land/";
const u8 s_blue_mountains_8012ba48[] = "/blue mountains/";
const u8 s_picture_city_8012ba5c[] = "/picture city/";
const u8 s_the_cave_of_skops_8012ba6c[] = "/the cave of skops/";
const u8 s_candy_chateau_8012ba80[] = "/candy chateau/";

/* 677C0 8018BFC0 -O2 */
void CalcObjPosInWorldMap(Obj *obj) {
    obj->screen_x_pos = obj->x_pos - xmap + 52;
    obj->screen_y_pos = obj->y_pos - ymap + 55;
}

/* 677F4 8018BFF4 -O2 -msoft-float */
void DoScrollInWorldMap(s16 h_speed, s16 v_speed)
{
  ymap += v_speed;
  xmap += h_speed;

  if(xmap < scroll_start_x)
  {
    xmap = scroll_start_x;
    dhspeed = 0;
  }
  else if(xmap > scroll_end_x)
  {
    xmap = scroll_end_x;
    dhspeed = 0;
  }
  if (ymap < scroll_start_y)
  {
    ymap = scroll_start_y;
    dvspeed = 0;
  }
  else if(ymap > scroll_end_y)
  {
    ymap = scroll_end_y;
    dvspeed = 0;
  }
  CalcObjPosInWorldMap(&ray);
}

/* 678DC 8018C0DC -O2 */
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
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DISPLAY_PLAT_WAY);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPlateau);

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_MEDAILLONS);

/* 68220 8018CA20 -O2 */
/*? INIT_TXT_BOX(s8 *);
? PS1_GenerateAndDisplayPassword();*/

void INIT_LEVEL_STAGE_NAME(void)
{
  if (t_world_info[num_world_choice].world == 7 && NBRE_SAVE == 0)
    PS1_GenerateAndDisplayPassword();
  else
    __builtin_memcpy(&text_to_display[0].text, t_world_info[num_world_choice].level_name, sizeof(text_to_display[0].text));

  text_to_display[0].font_size = 2;
  text_to_display[0].x_pos = 450;
  text_to_display[0].y_pos = 220;
  text_to_display[0].is_fond = false;
  text_to_display[0].field8_0x3d = true;
  INIT_TXT_BOX(text_to_display);
  text_to_display[0].centered_y_pos -= 6;
  text_to_display[0].width += 10;
  text_to_display[0].height += 6;
  text_to_display[0].color = t_world_info[num_world_choice].color;
}

INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_STAGE_NAME);

/* 68CB8 8018D4B8 -O2 */
void INIT_STAGE_NAME(void) {
    INIT_TEXT_TO_DISPLAY();
    INIT_LEVEL_STAGE_NAME();
    INIT_WORLD_STAGE_NAME();

    text_to_display[1].x_pos = 160;
    text_to_display[1].y_pos = 250;
    text_to_display[1].field8_0x3d = false;
    text_to_display[1].is_fond = false;

    text_to_display[3].x_pos = 160;
    text_to_display[3].y_pos = -50;
    text_to_display[3].field8_0x3d = false;
    text_to_display[3].is_fond = false;
}

/* 68D34 8018D534 -O2 */
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
}

/* 68EF4 8018D6F4 -O2 */
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
  text_to_display[2].is_fond = false;
  text_to_display[2].field8_0x3d = 0;
  INIT_TXT_BOX(&text_to_display[2]);

  text_to_display[0].font_size = 2;
  text_to_display[0].x_pos = 450;
  text_to_display[0].y_pos = 220;
  text_to_display[0].is_fond = false;
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
  text_to_display[1].is_fond = false;
  text_to_display[3].x_pos = 160;
  text_to_display[3].y_pos = -50;
  text_to_display[3].field8_0x3d = 0;
  text_to_display[3].is_fond = false;
}

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

/* https://decomp.me/scratch/6ivxi PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 698B4 8018E0B4 -O2 */
void RESPOND_TO_UP(void)
{
    num_world_choice = t_world_info[num_world_choice].index_up;
}

/* 698F0 8018E0F0 -O2 */
void RESPOND_TO_DOWN(void)
{
    num_world_choice = t_world_info[num_world_choice].index_down;
}

/* 6992C 8018E12C -O2 */
void RESPOND_TO_RIGHT(void)
{
    num_world_choice = t_world_info[num_world_choice].index_right;
}

/* 69968 8018E168 -O2 */
void RESPOND_TO_LEFT(void)
{
    num_world_choice = t_world_info[num_world_choice].index_left;
}

/* 699A4 8018E1A4 -O2 */
void MoveRayInWorldMap(void)
{
    h_scroll_speed = ray.speed_x;
    v_scroll_speed = ray.speed_y;
    ray.x_pos += ray.speed_x;
    decalage_en_cours = ray.speed_x;
    ray.y_pos += ray.speed_y;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DO_RAYMAN_IN_WLD_MAP);*/

void DO_RAYMAN_IN_WLD_MAP(void)
{
    s16 diff_x;
    s16 diff_y;
    s16 unk_0;
    s16 unk_1;
    s32 unk_2;
    s16 unk_3;
    s32 unk_4;
    s16 unk_5;
    Obj *unk_6;

    if (num_world_choice == old_num_world)
    {
        if (
            (s16) but0pressed(0) || (s16) but1pressed(0) ||
            (s16) but2pressed(0) || (s16) but3pressed(0)
        )
        {
            if (
                num_world_choice == 18 || num_world_choice == 19 ||
                num_world_choice == 20 || num_world_choice == 21 ||
                num_world_choice == 22 || num_world_choice == 23
            )
            {
                if (
                    NBRE_SAVE != 0 &&
                    t_world_info[num_world_choice].level_name == PTR_s_save_game_801c353c
                )
                {
                    if (PS1_SaveWldMap())
                    {
                        SaveGameOnDisk(fichier_selectionne);
                        PASTILLES_SAUVE_SAVED(num_world_choice);
                        CHANGE_STAGE_NAMES();
                    }
                    else
                        PS1_CardDisplayPassword();
                }
            }
            else
                new_world = true;
        }
        else if (rightjoy(0))
            RESPOND_TO_RIGHT();
        else if (leftjoy(0))
            RESPOND_TO_LEFT();
        else if (downjoy(0))
            RESPOND_TO_DOWN();
        else if (upjoy(0))
            RESPOND_TO_UP();

        if (num_world_choice != old_num_world)
        {
            if (*(u32*)&t_world_info[num_world_choice].state & (1 << 0))
            {
                ray.timer = 0;
                set_main_and_sub_etat(&ray, 1, 0);
                CHANGE_STAGE_NAMES();
            }
            else
                num_world_choice = old_num_world;
        }
    }
    else
    {
        diff_x = t_world_info[num_world_choice].x_pos - t_world_info[old_num_world].x_pos;
        diff_y = t_world_info[num_world_choice].y_pos - t_world_info[old_num_world].y_pos;
        if (diff_x < 0)
            ray.flags &= ~FLG(OBJ_FLIP_X);
        else
            ray.flags |= FLG(OBJ_FLIP_X);
        
        if (diff_x != 0 && diff_y != 0)
        {
            if (__builtin_abs(diff_y) > __builtin_abs(diff_x))
            {
                unk_0 = __builtin_abs(ray.timer * diff_x / diff_y);
                unk_1 = ray.timer;
            }
            else
            {
                unk_1 = __builtin_abs(ray.timer * diff_y / diff_x);
                unk_0 = ray.timer;
            }
        }
        else if (diff_x == 0)
            unk_1 = ray.timer;
        else if (diff_y == 0)
            unk_0 = ray.timer;
        ray.timer++;

        unk_2 = unk_0;
        if (diff_x >= 0)
            unk_3 = -(diff_x > 0) & unk_2;
        else
            unk_3 = -unk_2;
        unk_4 = unk_1;
        if (diff_y >= 0)
            unk_5 = -(diff_y > 0) & unk_4;
        else
            unk_5 = -unk_4;
        
        ray.speed_x = t_world_info[old_num_world].x_pos + unk_3 - ray.offset_bx - ray.x_pos;
        ray.speed_y = t_world_info[old_num_world].y_pos + unk_5 - ray.offset_by - (s16) (ray.y_pos - 8);
        if (
            __builtin_abs(unk_0) >= __builtin_abs(diff_x) &&
            __builtin_abs(unk_1) >= __builtin_abs(diff_y)
        )
        {
            old_num_world = num_world_choice;
            if (ray.main_etat != 0)
            {
                set_main_and_sub_etat(&ray, 0, 0);
                ray.speed_x = 0;
                ray.speed_y = 0;
                ray.x_pos = t_world_info[num_world_choice].x_pos - ray.offset_bx;
                ray.y_pos = t_world_info[num_world_choice].y_pos - ray.offset_by + 8;
            }
        }
    }
    
    MoveRayInWorldMap();
    CalcObjPosInWorldMap(&ray);
    unk_6 = &ray; /* TODO: clean up somehow */
    set_proj_center(ray.screen_x_pos + ray.offset_bx, ray.screen_y_pos + ray.offset_by);
    DO_ANIM(unk_6);
}

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

/* 6A0C8 8018E8C8 -O2 -msoft-float */
void INIT_PASTILLES_SAUVE(void)
{
  u8 *name;
  
  if (NBRE_SAVE != 0)
    name = PTR_s_save_game_801c353c;
  else
    name = PTR_s_no_save_available_801c3544;
  t_world_info[18].level_name = name;
  t_world_info[19].level_name = name;
  t_world_info[20].level_name = name;
  t_world_info[21].level_name = name;
  t_world_info[22].level_name = name;
  t_world_info[23].level_name = name;
}

/* 6A130 8018E930 -O2 */
void PASTILLES_SAUVE_SAVED(s16 wld)
{
    INIT_PASTILLES_SAUVE();
    t_world_info[wld].level_name = PTR_s_game_saved_801c3540;
}

/* 6A180 8018E980 -O2 */
/*void INIT_PASTILLES_SAUVE(void);*/

void FIN_WORLD_CHOICE(void)
{
    xwldmapsave = xmap;
    ywldmapsave = ymap;
    xmap = xmapinit;
    ymap = ymapinit;

    dir_on_wldmap = ray.flags >> OBJ_FLIP_X & 1;
    RESTORE_RAY();
    INIT_PASTILLES_SAUVE();
    PROC_EXIT = false;
    if (ray.hit_points == 0xFF)
        ray.hit_points = 0;
}

/* early returns kinda gross compared to android */
/* 6A224 8018EA24 -O2 */
void DETER_WORLD_AND_LEVEL(void)
{
  world_index = num_world_choice;
  if (ModeDemo == 0)
  {
    num_level_choice = t_world_info[num_world_choice].level;
    num_world_choice = t_world_info[num_world_choice].world;
  }
  if (num_world_choice == 5)
  {
    if (num_level_choice == 3 && finBosslevel[1] & FLG(1))
    {
      num_level_choice++;
      RayEvts.flags1 |= FLG(RAYEVTS1_LUCIOLE);
      return;
    }
    else if (num_world_choice == 5 && num_level_choice == 4 && finBosslevel[1] & FLG(1) && ModeDemo != 0)
    {
      RayEvts.flags1 |= FLG(RAYEVTS1_LUCIOLE);
      return;
    }
  }
  if (num_world_choice == 6 && finBosslevel[0] & FLG(7))
  {
    You_Win = true;
    fin_du_jeu = true;
    fin_dark = true;
    new_world = true;
  }
}