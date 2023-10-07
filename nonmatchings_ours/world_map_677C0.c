#include "world_map_677C0.h"

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_UP);*/
/* https://decomp.me/scratch/6ivxi PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 698B4 8018E0B4 */
extern s16 num_world_choice;
extern WorldInfo t_world_info[24];

void RESPOND_TO_UP(void)
{
    num_world_choice = t_world_info[num_world_choice].index_up;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_PASTILLES_SAUVE);*/
/* https://decomp.me/scratch/Y1VKk PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 6A0C8 8018E8C8 */
extern s32 D_801C34D4;
extern s32 D_801C34E8;
extern s32 D_801C34FC;
extern s32 D_801C3510;
extern s32 D_801C3524;
extern s32 D_801C3538;
extern s32 D_801C353C;
extern s32 D_801C3544;
extern u8 NBRE_SAVE;

void INIT_PASTILLES_SAUVE(void)
{
    s32 var_v0;

    if (NBRE_SAVE != 0)
    {
        var_v0 = D_801C353C;
    } else {
        var_v0 = D_801C3544;
    }
    D_801C34D4 = var_v0;
    t_world_info[19].level_name = var_v0;
    D_801C34FC = var_v0;
    D_801C3510 = var_v0;
    D_801C3524 = var_v0;
    D_801C3538 = var_v0;
}

/* matching, but... */
/* 6A180 8018E980 */
void INIT_PASTILLES_SAUVE(void);
extern s8 PROC_EXIT;
extern s8 dir_on_wldmap;
extern u16 xmapinit;
extern u16 xwldmapsave;
extern u16 ymapinit;
extern u16 ywldmapsave;

extern u8 D_801F6200;
extern u32 D_801F620C;

void FIN_WORLD_CHOICE(void)
{
    xwldmapsave = xmap;
    ywldmapsave = ymap;
    xmap = xmapinit;
    ymap = ymapinit;
    /*
    tried ray.flags & OBJ_FLIP_X,
    tried ray.flags & OBJ_FLIP_X != 0
    and bitfield
    */
    dir_on_wldmap = D_801F620C >> 0xE & 1;
    RESTORE_RAY();
    INIT_PASTILLES_SAUVE();
    PROC_EXIT = FALSE;
    if (D_801F6200 == 0xFF)
    {
        D_801F6200 = 0; /* this is also ray.hit_points */
    }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DoScrollInWorldMap);*/

/* 677F4 8018BFF4 -O2 */
extern s16 dhspeed;
extern s16 dvspeed;
extern s16 scroll_end_x;
extern s16 scroll_end_y;
extern s16 scroll_start_x;
extern s16 scroll_start_y;

void DoScrollInWorldMap(s32 arg0, s32 arg1)
{
    /* ??? */
    u8 test[16];
    s16 temp_v1;
    s16 var_a0;
    s16 var_v1;

    ymap = (u16) ymap + arg1;
    temp_v1 = (u16) xmap + arg0;
    xmap = temp_v1;
    if ((temp_v1 < scroll_start_x) || (var_a0 = scroll_end_x, ((scroll_end_x < temp_v1) != 0)))
    {
        xmap = var_a0;
        dhspeed = 0;
    }
    if ((scroll_start_y > ymap) || (var_v1 = scroll_end_y, ((scroll_end_y < ymap) != 0)))
    {
        ymap = var_v1;
        dvspeed = 0;
    }
    CalcObjPosInWorldMap(&ray);
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_WORLD_INFO);*/

/* 692CC 8018DACC -O2 */
/*? INIT_PASTILLES_SAUVE(s32, s16, s32);*/
extern u8 D_801C3364;
extern u8 D_801F3EA0;
extern s8 You_Win;
extern s8 dir_on_wldmap;
extern s8 fin_du_jeu;
extern s16 new_level;
extern s16 num_level;
extern s16 num_world;
extern s8 world_index;
extern s16 xwldmapsave;
extern s16 ywldmapsave;

void INIT_WORLD_INFO(void)
{
  s16 var_a1;
  s32 var_a0;
  s32 var_a2;
  if (D_801F3EA0 != 0)
  {
    var_a1 = 0;
    var_a2 = 0xfffffffb;
    do
    {
      var_a0 = var_a1;
      var_a0 = var_a0 * 0x14;
      *(s32 *) (&D_801C3364 + var_a0) = (*(s32 *) (&D_801C3364 + var_a0) | 1) & var_a2;
      var_a1 = var_a1 + 1;
    }
    while (var_a1 < 0x18);

  }
  num_world = 0;
  num_level = 0;
  new_world = 1;
  new_level = 1;
  world_index = 0;
  xwldmapsave = 0;
  ywldmapsave = 0x9E;
  dir_on_wldmap = 1;
  You_Win = 0;
  fin_du_jeu = 0;
  INIT_PASTILLES_SAUVE(var_a0);
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PASTILLES_SAUVE_SAVED);*/

/* 6A130 8018E930 -O2 */
/*? INIT_PASTILLES_SAUVE();*/
extern s32 D_801C336C;
extern s32 D_801C3540;

void PASTILLES_SAUVE_SAVED(s16 arg0)
{
    u8 *test;

    INIT_PASTILLES_SAUVE();
    test = &(t_world_info[0].level_name);
    *(u32*)(test + arg0 * sizeof(WorldInfo)) = D_801C3540;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DETER_WORLD_AND_LEVEL);*/

/* 6A224 8018EA24 -O2 */
extern u8 D_801C3366;
extern u8 D_801C3367;
extern u8 D_801F43D1;
extern u8 D_801F4EE9;
extern u8 ModeDemo;
extern s8 You_Win;
extern u8 finBosslevel;
extern s8 fin_dark;
extern s8 fin_du_jeu;
extern s16 num_level_choice;
extern s16 num_world_choice;
extern u8 world_index;

void DETER_WORLD_AND_LEVEL(void)
{
  s16 temp_v0;
  world_index = *(u8*)&num_world_choice;
  if (ModeDemo == 0)
  {
    temp_v0 = num_world_choice;
    num_level_choice = t_world_info[temp_v0].level;
    num_world_choice = t_world_info[temp_v0].world;
  }
  if (num_world_choice == 5)
  {
    if ((num_level_choice == 3) && (finBosslevel[1] & 2))
    {
      num_level_choice += 1;
      D_801F43D1 |= 4;
      return;
    }
    if (num_world_choice == 5)
    {
      if (((num_level_choice == 4) && (finBosslevel[1] & 2)) && (ModeDemo != 0))
      {
        D_801F43D1 |= 4;
        return;
      }
    }
  }
  if ((num_world_choice == 6) && (finBosslevel[0] & 0x80))
  {
    You_Win = 1;
    fin_du_jeu = 1;
    fin_dark = 1;
    new_world = 1;
    return;
  }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", PS1_DisplayPts);*/

/* 678DC 8018C0DC -O2 */
/*? DISPLAY_PTS_TO_PLAN2(s16, s16, s16, s16, s32);*/
extern s16 D_801C335E;
extern u8 D_801C3364;
extern u8 chemin_percent;

void PS1_DisplayPts(s16 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    s32 temp_a1;
    u32 temp_v1;

    if (arg1 != arg0 && (temp_v1 = *(u32*)&t_world_info[arg1].state, (temp_v1 >> 1 & 1) == 0))
    {
        if (temp_v1 & 1)
        {
            DISPLAY_PTS_TO_PLAN2(
                arg2,
                arg3,
                t_world_info[arg1].x_pos,
                t_world_info[arg1].y_pos,
                0x64);
            return;
        }
        if ((temp_v1 >> 2) & 1)
        {
            DISPLAY_PTS_TO_PLAN2(
                arg2,
                arg3,
                t_world_info[arg1].x_pos,
                t_world_info[arg1].y_pos,
                (s32) chemin_percent
            );
        }
    }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DISPLAY_PLAT_WAY);*/

/* 679D4 8018C1D4 -O2 */
void DISPLAY_PLAT_WAY(void)
{
  WorldInfo *var_s4;
  s32 new_var;
  s16 var_s5;
  s16 var_s5_2;
  s16 temp_s0;
  s16 temp_s1;
  s32 *var_a0;
  s32 *var_s3;
  s32 new_var2;

  var_s5 = 0;
  new_var = ~2;
  var_a0 = &t_world_info->state;
  do
  {
    new_var2 = *var_a0;
    var_s5 = var_s5 + 1;
    *var_a0 = new_var2 & new_var;
    var_a0 += 5;
  }
  while (var_s5 < 0x18);

  var_s5_2 = 0;
  var_s4 = &t_world_info;
  var_s3 = &t_world_info->state;
  do
  {
    temp_s1 = var_s4->x_pos;
    var_a0 = var_s3;
    var_s5 = *(((u16 *) var_a0) - 3);
    temp_s0 = var_s5;
    var_s4 += 1;
    var_s5 = 1;
    if ((*var_a0) & 1)
    {
      PS1_DisplayPts(var_s5_2, *(((u8 *) var_s3) - 4), temp_s1, temp_s0);
      PS1_DisplayPts(var_s5_2, *(((u8 *) var_a0) - 3), temp_s1, temp_s0);
      PS1_DisplayPts(var_s5_2, *(((u8 *) var_a0) - 1), temp_s1, temp_s0);
      PS1_DisplayPts(var_s5_2, *(((u8 *) var_a0) - 2), temp_s1, temp_s0);
      *var_a0 = (*var_s3) | 2;
    }
    var_s5_2++;
    var_s4++;
  }
  while (var_s5_2 < 0x18);
}