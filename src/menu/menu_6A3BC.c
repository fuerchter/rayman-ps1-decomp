#include "menu/menu_6A3BC.h"

/* .data */
extern s32 PS1_Button_Text_Square;
extern s32 PS1_Button_Text_Cross;
extern s32 PS1_Button_Text_Triangle;
extern s32 PS1_Button_Text_Circle;

u8 but0pressed();
u8 but1pressed();
u8 but2pressed();
u8 but3pressed();
void set_main_and_sub_etat(Obj *obj,u8 main_etat,u8 sub_etat);
void set_zoom_mode(u8 zoomMode);

extern u8 Etape_History;
extern u8 fin_continue;
extern u8 joy_done;
extern s16 loop_nb_frames;

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_NEW_GAME); /* skipping for now due to WorldInfo.state */

/* 6A5F0 8018EDF0 -O2 -msoft-float */
void POINTEUR_BOUTONS_OPTIONS_BIS(void)
{
  u8 (*but0)() = &but0pressed;
  s32 val0 = 0;
  u8 (*but1)() = &but1pressed;
  s32 val1 = 0;
  u8 (*but2)() = &but2pressed;
  s32 val2 = 0;
  u8 (*but3)() = &but3pressed;
  s32 val3 = 0;

  switch (options_jeu.Jump)
  {
    case 0:
      options_jeu.Fire1ButtonFunc = but0;
      options_jeu.field11_0x1e = val0;
      break;
    case 1:
      options_jeu.Fire1ButtonFunc = but1;
      options_jeu.field11_0x1e = val1;
      break;
    case 2:
      options_jeu.Fire1ButtonFunc = but2;
      options_jeu.field11_0x1e = val2;
      break;
    case 3:
      options_jeu.Fire1ButtonFunc = but3;
      options_jeu.field11_0x1e = val3;
      break;
  }

  switch (options_jeu.Fist)
  {
    case 0:
      options_jeu.Fire0ButtonFunc = but0;
      options_jeu.field12_0x20 = val0;
      break;
    case 1:
      options_jeu.Fire0ButtonFunc = but1;
      options_jeu.field12_0x20 = val1;
      break;
    case 2:
      options_jeu.Fire0ButtonFunc = but2;
      options_jeu.field12_0x20 = val2;
      break;
    case 3:
      options_jeu.Fire0ButtonFunc = but3;
      options_jeu.field12_0x20 = val3;
      break;
    default:
      break;
  }

  switch (options_jeu.field6_0x14)
  {
    case 0:
      options_jeu.Button4Func = but0;
      options_jeu.field13_0x22 = val0;
      break;
    case 1:
      options_jeu.Button4Func = but1;
      options_jeu.field13_0x22 = val1;
      break;
    case 2:
      options_jeu.Button4Func = but2;
      options_jeu.field13_0x22 = val2;
      break;
    case 3:
      options_jeu.Button4Func = but3;
      options_jeu.field13_0x22 = val3;
      break;

  }

  switch (options_jeu.Action)
  {
    case 0:
      options_jeu.Button3Func = but0;
      options_jeu.field14_0x24 = val0;
      break;
    case 1:
      options_jeu.Button3Func = but1;
      options_jeu.field14_0x24 = val1;
      break;
    case 2:
      options_jeu.Button3Func = but2;
      options_jeu.field14_0x24 = val2;
      break;
    case 3:
      options_jeu.Button3Func = but3;
      options_jeu.field14_0x24 = val3;
      break;
  }
}

/* 6A890 8018F090 -O2 -msoft-float */
/*? display_text(? *, s16, s16, s32);*/

void PS1_DisplayPadButton(s16 button, s16 x, s16 y, u8 font_size)
{
    switch (button)
    {
    case 0:
        display_text(&PS1_Button_Text_Square, x, y, font_size, 0);
        return;
    case 1:
        display_text(&PS1_Button_Text_Cross, x, y, font_size, 14);
        return;
    case 2:
        display_text(&PS1_Button_Text_Triangle, x, y, font_size, 8);
        return;
    case 3:
        display_text(&PS1_Button_Text_Circle, x, y, font_size, 2);
        return;
    }
}

/* 6A948 8018F148 -O2 -msoft-float */
/*? set_main_etat(s16 *, ?);
? set_sub_etat(s16 *, ?);*/

void INIT_CONTINUE(void)
{
  Obj *mapobj_1;
  Obj *mapobj_2;
  Obj *mapobj_3;
  
  loop_nb_frames = 0;
  loop_timing = 10;
  fin_continue = 0;
  compteur = 0;
  joy_done = 0;
  Etape_History = 0;
  ray.y_pos = 135 - ray.offset_by;
  ray.anim_frame = 0;
  if (nb_continue != 0)
  {
    set_main_and_sub_etat(&ray, 3, 24);
    ray.x_pos = 225 - ray.offset_bx;
  }
  else
  {
    ray.x_pos = 80 - ray.offset_bx;
    set_main_etat(&ray, 3);
    loop_timing = 0xff;
    if (horloge[20] >= 11)
      set_sub_etat(&ray, 51);
    else
      set_sub_etat(&ray, 50);
  }

  ray.flags &= ~FLG(OBJ_FLIP_X);
  ray.speed_x = 0;
  ray.speed_y = 0;
  set_zoom_mode(0);
  clock_obj.x_pos = 80;
  clock_obj.y_pos = 130;
  set_main_and_sub_etat(&clock_obj, 0, 0);
  mapobj_1 = mapobj;
  mapobj_1->offset_bx = 80;
  mapobj_1->screen_x_pos = 120;
  mapobj_1->screen_y_pos = 110;
  mapobj_2 = mapobj;
  mapobj_2->offset_by = 64;
  mapobj_3 = mapobj;
  mapobj_3->timer = 0;
  mapobj_3->flags &= ~FLG(OBJ_ALIVE);
  set_main_and_sub_etat(mapobj, 5, 20);
  xmapinit = xmap;
  ymapinit = ymap;
  xmap = 0;
  ymap = 0;
  PROC_EXIT = false;
}

/* 6AB48 8018F348 -O2 -msoft-float */
void CHEAT_MODE_CONTINUE(void)
{
    if (joy_done == 0 && ++compteur >= 6)
      compteur = 0;

    if (compteur == 0)
    {
      if(upjoy(0))
        joy_done = 1;
      else if(downjoy(0))
        joy_done = 2;
      else if(rightjoy(0))
        joy_done = 3;
      else if(leftjoy(0))
        joy_done = 4;
    }

    switch (Etape_History)
    {
    case 0:
        if ((joy_done == 1) && (nb_continue < 4))
        {
          joy_done = 0;
          Etape_History++;
          return;
        }
        if (joy_done != 0)
          Etape_History = 0;
        break;
    case 1:
        if (joy_done == 2) {
          joy_done = 0;
          Etape_History++;
          return;
        }
        if (joy_done != 0)
          Etape_History = 0;
        break;
    case 2:
        if (joy_done == 3)
        {
          joy_done = 0;
          Etape_History++;
          return;
        }
        if (joy_done != 0)
          Etape_History = 0;
        break;
    case 3:
        if (joy_done == 4) {
          nb_continue = 10;
          return;
        }
        if (joy_done != 0)
          Etape_History = 0;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_CONTINUE_PRG);

/* 6B4C4 8018FCC4 -O2 -msoft-float */
void FIN_CONTINUE_PRG(void)
{
  if (loop_timing == 0xff)
  {
    fin_du_jeu = true;
    menuEtape = 0;
  }
  else if (loop_timing != -1)
  {
    status_bar.num_lives = 3;
    ray.hit_points = 2;
    status_bar.max_hp = 2;
    fin_du_jeu = false;
    LOAD_VIGNET_GAME();
  }
  else
    menuEtape = 0;
  xmap = xmapinit;
  ymap = ymapinit;
}

/* 6B568 8018FD68 -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", MAIN_NO_MORE_CONTINUE_PRG);
#else
void MAIN_NO_MORE_CONTINUE_PRG(void)
{
  u8 flag_set;

  __asm__("nop");

  PROC_EXIT = SelectButPressed() != false;
  flag_set = ray.eta[ray.main_etat][ray.sub_etat].flags & 0x10;
  if (
    (flag_set && ray.anim_frame == 0) ||
    (!flag_set && ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
  )
    if(horloge[ray.eta[ray.main_etat][ray.sub_etat].anim_speed & 0xf] == 0)
      PROC_EXIT = true;

  if (PROC_EXIT)
    fin_continue = true;
}
#endif

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_VIGNET);

/* 6B6A0 8018FEA0 -O2 -msoft-float */

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_CREDITS);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_CREDITS);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_LOADER_ANIM);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_LOADER_ANIM);

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", SPECIAL_INIT);
