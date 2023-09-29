#include "world_map_95CC.h"

/* 95CC 8012DDCC -O2 */
/* matching, but how to resolve goto block_6; */

/*? DISPLAY_FOND_SELECT();
? atoi(s16, ? *, ?);
s32 but0pressed(?);
s32 but1pressed(?);
? display_text(? *, ?, ?, ?, s32);
s32 leftjoy(?);
? readinput();
s32 rightjoy(?);*/

extern u8 s_level_801cedf4;
extern u8 colour;

s32 select_level_prg(void)
{
  u8 sp18[16];
  s16 temp_v0;
  s16 var_v0_2;
  u8 new_var;
  u8 var_v0;

  readinput();
  DISPLAY_FOND_SELECT();
  display_text(&s_level_801cedf4, 100, 100, 0, colour);
  PS1_sprintf(level_select, &sp18, 10);
  display_text(&sp18, 200, 100, 0, colour);
  if (rightjoy(0) && !inter_select) /* do rightjoy/leftjoy take param? */
  {
    var_v0_2 = level_select + 1;
    goto block_6;
  }
  if (leftjoy(0) && !inter_select)
  {
    var_v0_2 = level_select - 1;
    block_6:
    level_select = var_v0_2;
  }
  if (level_select >= 31){ level_select = 30; }
  if (level_select <= 0){ level_select = 1; }
  temp_v0 = inter_select + 1;
  inter_select = temp_v0;

  if (temp_v0 >= 4){ inter_select = 0; }
  var_v0 = 0;
  new_var = new_var;
  if (((but0pressed(0) << 16) != 0) || ((new_var, (but1pressed(0) << 16) != 0)))
  {
    var_v0 = 1;
  }
  return var_v0;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DISPLAY_STAGE_NAMES);*/

/* 979C 8012DF9C -O2 */
/* matches, but won't let me fill in text_to_display */
/*? display_box_text(? *);*/
extern TextToDisplay D_801E4F98;

void DISPLAY_STAGE_NAMES(void)
{
  s32 *temp_a0;
  s32 *temp_a0_2;
  s32 *var_a0;

  if ((&D_801E4F98) != 0)
  {
    display_box_text(&D_801E4F98);
  }
  var_a0 = (&D_801E4F98) - 1;

  if (var_a0 != 0)
  {
    display_box_text(var_a0);
  }
  temp_a0 = (&D_801E4F98) + 2;
  if (temp_a0)
  {
    display_box_text(temp_a0);
  }
  temp_a0_2 = (&D_801E4F98) + 1;
  if (temp_a0_2 != 0)
  {
    display_box_text(temp_a0_2);
  }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_95CC", WORLD_CHOICE);*/

/* 980C 8012E00C */
/*? DISPLAY_PLAT_WAY();
? DISPLAY_STAGE_NAMES();
? DO_CHEMIN();
? DO_FADE();
? DisplayJumellesNormal();
? FUN_8013af14();
? FUN_8013eb38(s16, s16, ?, ?);
? PS1_DisplayWorldMapObjects();
s32 SelectButPressed();
? display2(? *);
? readinput();*/
extern u8 PROC_EXIT;
extern s8 let_shadow;
extern s16 new_world;

s32 WORLD_CHOICE(void) {
    s32 var_a0;

    let_shadow = 0;
    DO_FADE();
    FUN_8013eb38(xmap, ymap, 0x2C, 0x37);
    DISPLAY_PLAT_WAY();
    PS1_WldMapGraphEdges();
    display2(&ray);
    DO_CHEMIN();
    PS1_DisplayWorldMapObjects();
    DisplayJumellesNormal();
    DISPLAY_STAGE_NAMES();
    readinput();
    PROC_EXIT = SelectButPressed() != 0;
    var_a0 = new_world;
    if (var_a0 || PROC_EXIT) {
        var_a0 = 1;
    }
    return var_a0;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DO_WORLD_MAP);*/

/* 98D4 8012E0D4 */
/* single instruction is incorrect */
/*? DETER_WORLD_AND_LEVEL();
? FIN_WORLD_CHOICE();
? FUN_8019e770();
? INIT_CHEMIN();
? INIT_FADE_IN();
? INIT_FADE_OUT();
? INIT_RAY(s16);
? PS1_PlayCDTrack_0_3();
? PlaySnd_old(?, u16, u16);
? SYNCHRO_LOOP(? *);
? readinput();
? stop_cd();*/
extern u8 ModeDemo;
extern u8 PROC_EXIT;
/*extern ? WORLD_CHOICE;*/
extern s8 fin_du_jeu;
extern s8 menuEtape;
extern s16 new_level;
extern u16 num_level;
extern u16 num_level_choice;
extern u16 num_world;
extern s16 num_world_choice;
extern u8 world_index;

void DO_WORLD_MAP(void) {
    u16 temp_a1;
    u16 nlev;

    if (ModeDemo == 0) {
        FUN_8019e770();
    }
    PS1_PlayCDTrack_0_3();
    INIT_FADE_IN();
    INIT_RAY(new_level);
    INIT_CHEMIN();
    if (ModeDemo == 0) {
        readinput();
        if (ModeDemo == 0) {
            SYNCHRO_LOOP(&WORLD_CHOICE);
        }
    }
    if (PROC_EXIT != 0) {
        world_index = num_world_choice;
        temp_a1 = num_world;
        fin_du_jeu = 1;
        menuEtape = 4;
        num_world = 0;
        num_world_choice = temp_a1;
        nlev = num_level;
        num_level_choice = nlev;
        PlaySnd_old(0x4D, temp_a1, nlev);
    } else {
        DETER_WORLD_AND_LEVEL();
        if (ModeDemo == 0) {
            PlaySnd_old(0x45);
        }
    }
    INIT_FADE_OUT();
    FIN_WORLD_CHOICE();
    stop_cd();
}