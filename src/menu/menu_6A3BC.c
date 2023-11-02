#include "menu/menu_6A3BC.h"

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_NEW_GAME); /* skipping for now due to WorldInfo.state */

/* 6A5F0 8018EDF0 -O2 -msoft-float */
void POINTEUR_BOUTONS_OPTIONS_BIS(void)
{
  s32 (*but0)() = &but0pressed;
  s32 val0 = 0;
  s32 (*but1)() = &but1pressed;
  s32 val1 = 0;
  s32 (*but2)() = &but2pressed;
  s32 val2 = 0;
  s32 (*but3)() = &but3pressed;
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
/*void set_zoom_mode(u8 zoomMode);
? set_main_etat(s16 *, ?);
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
#ifndef NONMATCHINGS /* missing_addiu */
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

/* 6B6A0 8018FEA0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_VIGNET);
#else
/*void Deter_Option_Caract(char *param_1,short param_2,uint param_3);
void start_cd_suspence(void);*/

void INIT_VIGNET(void)
{
  s32 base;
  s32 i;

  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");

  loop_nb_frames = 0;
  loop_timing = 5;
  new_txt_fee = 0;
  INIT_TEXT_TO_DISPLAY();
  if (You_Win)
  {
    INIT_CREDITS();
    return;
  }

  switch(num_world)
  {
  case 1:
    __builtin_strcpy(text_to_display[0].text, "/tarayzan gives rayman a magic seed/");
    __builtin_strcpy(text_to_display[1].text, "/press the ? button to use the seed/");
    Deter_Option_Caract(text_to_display[1].text,options_jeu.Action, 11);
    break;
  case 3:
    __builtin_strcpy(text_to_display[0].text, "/the musician gives rayman/");
    __builtin_strcpy(text_to_display[1].text, "/a super helicopter power/");
    __builtin_strcpy(text_to_display[2].text, "/press the ? button to use it/");
    __builtin_strcpy(text_to_display[3].text, "/press ? again to go higher/");
    Deter_Option_Caract(text_to_display[2].text,options_jeu.Jump, 11);
    Deter_Option_Caract(text_to_display[3].text,options_jeu.Jump, 7);
    break;
  case 4:
    start_cd_suspence();
    __builtin_strcpy(text_to_display[0].text, "/mr dark kidnaps betilla the fairy/");
    break;
  case 5:
    if (num_level == 3)
    {
      __builtin_strcpy(text_to_display[0].text, "/joe offers rayman a firefly /");
      __builtin_strcpy(text_to_display[1].text, "/to light up the dark/");
    }
    if (num_level == 11)
      __builtin_strcpy(text_to_display[0].text, "/rayman please help me! hurry!/");
    break;
  }

  base = 0;
  i = 0;
  while (i < 5)
  {
    if (text_to_display[base].text[0] != '\0')
    {
        text_to_display[base].x_pos = 160;
        text_to_display[base].y_pos = 203;
        text_to_display[base].font_size = 2;
    }
    if (text_to_display[base + 1].text[0] != '\0')
    {
        text_to_display[base + 1].x_pos = 160;
        text_to_display[base + 1].y_pos = 218;
        text_to_display[base + 1].font_size = 2;
    }
    base += 2;
    i++;
  }
}
#endif

/* 6BE68 80190668 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_CREDITS);
#else
/*? SaveGameOnDisk(s16);*/

void INIT_CREDITS(void)
{
  s16 i = -1;

  dans_la_map_monde = false;
  SaveGameOnDisk(fichier_selectionne);
  first_credit = 0;
  last_credit = 0;
  nb_credits_lines = 0;
  PROC_EXIT = false;
  display_Vignet = 0;
  menuEtape = 0;
  do {
    i++;
    credits[i].y_pos = 260;
  } while (credits[i].cmd != 0xff);

  __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_CREDITS);

/* 6C198 80190998 -O2 -msoft-float */
void INIT_LOADER_ANIM(void)
{
  bigray.offset_bx = 200;
  bigray.offset_by = 240;
  bigray.screen_x_pos = 120;
  bigray.screen_y_pos = -32;
  bigray.main_etat = 1;
  bigray.sub_etat = 0;
  bigray.flags &= ~FLG(OBJ_FLIP_X);
  bigray.cmd = GO_LEFT;
  bigray.flags &= ~FLG(OBJ_FLIP_X);
}

/* 6C210 80190A10 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", DO_LOADER_ANIM);
#else
void DO_LOADER_ANIM(void)
{
  u8 anim_speed;
  u8 flag_set;

  __asm__("nop\nnop\nnop");

  anim_speed = bigray.eta[bigray.main_etat][bigray.sub_etat].anim_speed;
  bigray.speed_x = 0;
  if (((anim_speed & 0xf) != 0) && (horloge[anim_speed & 0xf] == 0))
    SET_X_SPEED(&bigray);
  
  bigray.screen_x_pos += bigray.speed_x;
  if (PROC_EXIT == true)
  {
    bigray.cmd = GO_SUBSTATE;
    set_main_and_sub_etat(&bigray, 0, 2);
    bigray.timer = 2;
    bigray.screen_x_pos = 144 - bigray.offset_bx;
    bigray.flags &= ~FLG(OBJ_FLIP_X);
    PROC_EXIT = false;
  }

  switch(bigray.cmd)
  {
  case GO_LEFT:
    if ((s32)(bigray.screen_x_pos + bigray.offset_bx) <= -101 )
    {
      bigray.cmd += GO_RIGHT;
      set_main_and_sub_etat(&bigray, 1, 1);
      bigray.screen_x_pos = -bigray.offset_bx - 60;
      bigray.flags |= FLG(OBJ_FLIP_X);
    }
    break;
  case GO_RIGHT:
    if ((s32)(bigray.screen_x_pos + bigray.offset_bx) >= 401)
    {
      bigray.cmd += GO_RIGHT;
      set_main_and_sub_etat(&bigray, 1, 2);
      bigray.anim_frame = 0;
      bigray.screen_x_pos = -bigray.offset_bx + 350;
      bigray.flags &= ~FLG(OBJ_FLIP_X);
    }
    break;
  case GO_WAIT:
    if (bigray.main_etat == 0 && bigray.sub_etat == 0)
      bigray.cmd += GO_RIGHT;
    break;
  case GO_UP:
    flag_set = bigray.eta[bigray.main_etat][bigray.sub_etat].flags & 0x10;
    if (
      (!flag_set || bigray.anim_frame == 0) &&
      (flag_set || bigray.anim_frame == bigray.animations[bigray.anim_index].frames_count - 1) &&
      horloge[bigray.eta[bigray.main_etat][bigray.sub_etat].anim_speed & 0xf] == 0
    )
    {
      bigray.cmd += GO_RIGHT;
      set_main_and_sub_etat(&bigray, 1, 3);
      bigray.screen_x_pos = -60 - bigray.offset_bx;
      bigray.flags |= FLG(OBJ_FLIP_X);
    }
    break;
  case GO_DOWN:
    if ((s32)(bigray.screen_x_pos + bigray.offset_bx) >= 0x191)
    {
      bigray.cmd += GO_RIGHT;
      set_main_and_sub_etat(&bigray, 0, 1);
      bigray.screen_x_pos = 144 - bigray.offset_bx;
      bigray.flags &= ~FLG(OBJ_FLIP_X);
    }
    break;
  case GO_SUBSTATE:
    if (bigray.main_etat == 0 && bigray.sub_etat == 2)
    {
      if (bigray.timer == 0)
        PROC_EXIT = true;
      else
        bigray.timer--;
    }
  }
  DO_ANIM(&bigray);
}
#endif

/* 6C6A0 80190EA0 -O2 -msoft-float */
void SPECIAL_INIT(void)
{
    dark_phase = 0;
    if (ray_on_poelle == true)
    {
      PS1_RestoreSauveRayEvts();
      ray_on_poelle = false;
    }
}
