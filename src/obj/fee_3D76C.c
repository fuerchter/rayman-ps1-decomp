#include "obj/fee_3D76C.h"

/* 3D76C 80161F6C -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/fee_3D76C", INIT_TXT_FEE);
#else
/*? INIT_TXT_BOX(u8 *);*/
/*int strlen(char *s);*/ /* missing from 3.0 psyq .h but present in 3.3? */

void INIT_TXT_FEE(void)
{
  s16 i;
  
  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");

  i = 0;
  while (i < 10)
  {
    if (strlen(text_to_display[i].text) != 0)
    {
      text_to_display[i].font_size = 2;
      text_to_display[i].x_pos = 150;
      text_to_display[i].y_pos = 218;
      text_to_display[i].field8_0x3d = 0;
      text_to_display[i].is_fond = FALSE;
      INIT_TXT_BOX(&text_to_display[i]);
      text_to_display[i].text[0] = ' ';
      text_to_display[i].x_pos = text_to_display[i].centered_x_pos;
    }
    else
      text_to_display[i].field8_0x3d = 0;
    i++;
  }
  display_txt_fee = 0xff;
  old_txt_fee = 0xff;
}
#endif

/* 3D89C 8016209C -O2 -msoft-float */
void allocate_poing_or_fee(void)
{
  u8 nb_objects;
  s16 i;
  Obj *obj;
  
  nb_objects = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_objects != 0)
  {
    do {
      if (obj->type == TYPE_POING_FEE && !(obj->flags & OBJ_ALIVE))
      {
        obj->flags &= ~OBJ_ALIVE;
        obj->flags &= ~OBJ_ACTIVE;
        obj->speed_x = 8;
        obj->speed_y = 0;
        obj->anim_frame = 0;
        obj->flags |= OBJ_FLIP_X;
        png_or_fee_id = obj->id;
        break;
      }
      i++;
      obj++;
    } while (i < nb_objects);
  }
}

/* 3D94C 8016214C -O2 -msoft-float */
void init_moustique(void)
{
    if (!fin_du_jeu)
    {
        if (rayman_obj_id != -1)
          NewMs = TRUE;
        else
          NewMs = FALSE;
    }
}

/* TODO: remove symbols in addrs-u.txt (gives splat warnings currently) */
/* 3D994 80162194 -O2 -msoft-float */
/*? Deter_Option_Caract(TextToDisplay *, u16, ?, TextToDisplay *);
? INIT_TEXT_TO_DISPLAY();
? INIT_TXT_FEE();*/

void init_fee(void)
{  
  display_txt_fee = 0xff;
  if (ModeDemo == 0)
    record.is_playing = FALSE;
  is_fee = FALSE;
  INIT_TEXT_TO_DISPLAY();

  switch(num_world)
  {
    case 1:
      switch(num_level)
      {
        case 3:
          is_fee = TRUE;
          __builtin_strcpy(text_to_display[0].text, "/hello rayman/");
          __builtin_strcpy(text_to_display[1].text, "/i'm betilla the fairy/");
          __builtin_strcpy(text_to_display[2].text, "/and i'm going to help you/");
          __builtin_strcpy(text_to_display[3].text, "/in your quest./");
          __builtin_strcpy(text_to_display[4].text, "/i can give you a new power./");
          __builtin_strcpy(text_to_display[5].text, "/now you can punch with your fist/");
          __builtin_strcpy(text_to_display[6].text, "/good luck !/");
          __builtin_strcpy(text_to_display[7].text, "/press the ? button to punch/");
          __builtin_strcpy(text_to_display[8].text, "/the longer you press/");
          __builtin_strcpy(text_to_display[9].text, "/the further you punch/");
          Deter_Option_Caract(&text_to_display[7].text,options_jeu.Fist,0xb);
          break;
        case 8:
          is_fee = TRUE;
          __builtin_strcpy(text_to_display[0].text, "/you're courageous rayman/");
          __builtin_strcpy(text_to_display[1].text, "/but you will have to keep at it/");
          __builtin_strcpy(text_to_display[5].text, "/you now have the power to hang/");
          break;
        case 17:
          is_fee = TRUE;
          __builtin_strcpy(text_to_display[0].text, "/great job rayman but you'll be going/");
          __builtin_strcpy(text_to_display[1].text, "/through more perilous traps!/");
          __builtin_strcpy(text_to_display[2].text, "/i hope this will help you/");
          __builtin_strcpy(text_to_display[3].text, "/to avoid the worst.../");
          __builtin_strcpy(text_to_display[5].text, "/now you can grab things/");
          __builtin_strcpy(text_to_display[6].text, "/with your fist./");
          __builtin_strcpy(text_to_display[7].text, "/to grab use the ? button/");
          Deter_Option_Caract(&text_to_display[7].text,options_jeu.Fist,0x11);
          break;
      }
      break;
    case 2:
      switch(num_level)
      {
        case 11:
          is_fee = TRUE;
          __builtin_strcpy(text_to_display[0].text, "/things are not going to get/");
          __builtin_strcpy(text_to_display[1].text, "/any easier for you rayman/");
          __builtin_strcpy(text_to_display[2].text, "/but this new power /");
          __builtin_strcpy(text_to_display[3].text, "/will make you stronger.../");
          __builtin_strcpy(text_to_display[7].text, "/now you can use your hair/");
          __builtin_strcpy(text_to_display[8].text, "/as a helicopter/");
          __builtin_strcpy(text_to_display[9].text, "/to do it press ? twice/");
          Deter_Option_Caract(&text_to_display[9].text,options_jeu.Jump,0x10);
          break;
      }
      break;
    case 3:
      switch(num_level)
      {
        case 11:
          is_fee = TRUE;
          __builtin_strcpy(text_to_display[0].text, "/things are going to get/");
          __builtin_strcpy(text_to_display[1].text, "/really wild from now on rayman/");
          __builtin_strcpy(text_to_display[2].text, "/you'll have to be very quick.../");
          __builtin_strcpy(text_to_display[5].text, "/now you can run faster/");
          __builtin_strcpy(text_to_display[7].text, "/to run press ? while walking/");
          Deter_Option_Caract(&text_to_display[7].text,options_jeu.Action,0xe);
          break; 
      }
      break;
  }

  if(is_fee)
  {
    INIT_TXT_FEE();
    allocate_poing_or_fee();
  }
}
