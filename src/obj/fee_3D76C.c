#include "obj/fee_3D76C.h"

const u8 s_hello_rayman_8012a7e0[] = "/hello rayman/";
const u8 s_im_betilla_the_fairy_8012a7f0[] = "/i'm betilla the fairy/";
const u8 s_and_im_going_to_help_you_8012a808[] = "/and i'm going to help you/";
const u8 s_in_your_quest_8012a824[] = "/in your quest./";
const u8 s_i_can_give_you_a_new_power_8012a838[] = "/i can give you a new power./";
const u8 s_now_you_can_punch_with_your_fis_8012a858[] = "/now you can punch with your fist/";
const u8 s_good_luck__8012a87c[] = "/good luck !/";
const u8 s_press_the__button_to_punch_8012a88c[] = "/press the ? button to punch/";
const u8 s_the_longer_you_press_8012a8ac[] = "/the longer you press/";
const u8 s_the_further_you_punch_8012a8c4[] = "/the further you punch/";
const u8 s_youre_courageous_rayman_8012a8dc[] = "/you're courageous rayman/";
const u8 s_but_you_will_have_to_keep_at_it_8012a8f8[] = "/but you will have to keep at it/";
const u8 s_you_now_have_the_power_to_hang_8012a91c[] = "/you now have the power to hang/";
const u8 s_great_job_rayman_but_youll_be_g_8012a940[] = "/great job rayman but you'll be going/";
const u8 s_through_more_perilous_traps_8012a968[] = "/through more perilous traps!/";
const u8 s_i_hope_this_will_help_you_8012a988[] = "/i hope this will help you/";
const u8 s_to_avoid_the_worst_8012a9a4[] = "/to avoid the worst.../";
const u8 s_now_you_can_grab_things_8012a9bc[] = "/now you can grab things/";
const u8 s_with_your_fist_8012a9d8[] = "/with your fist./";
const u8 s_to_grab_use_the__button_8012a9ec[] = "/to grab use the ? button/";
const u8 s_things_are_not_going_to_get_8012aa08[] = "/things are not going to get/";
const u8 s_any_easier_for_you_rayman_8012aa28[] = "/any easier for you rayman/";
const u8 s_but_this_new_power__8012aa44[] = "/but this new power /";
const u8 s_will_make_you_stronger_8012aa5c[] = "/will make you stronger.../";
const u8 s_now_you_can_use_your_hair_8012aa78[] = "/now you can use your hair/";
const u8 s_as_a_helicopter_8012aa94[] = "/as a helicopter/";
const u8 s_to_do_it_press__twice_8012aaa8[] = "/to do it press ? twice/";
const u8 s_things_are_going_to_get_8012aac4[] = "/things are going to get/";
const u8 s_really_wild_from_now_on_rayman_8012aae0[] = "/really wild from now on rayman/";
const u8 s_youll_have_to_be_very_quick_8012ab04[] = "/you'll have to be very quick.../";
const u8 s_now_you_can_run_faster_8012ab28[] = "/now you can run faster/";
const u8 s_to_run_press__while_walking_8012ab44[] = "/to run press ? while walking/";

/* 3D76C 80161F6C -O2 -msoft-float */
/*? INIT_TXT_BOX(u8 *);*/
/*int strlen(char *s);*/ /* missing from 3.0 psyq .h but present in 3.3? */

void INIT_TXT_FEE(void)
{
  s16 i;

  for (i = 0; i < (s16) LEN(text_to_display); i++)
  {
    if (strlen(text_to_display[i].text) != 0)
    {
      text_to_display[i].font_size = 2;
      text_to_display[i].x_pos = 150;
      text_to_display[i].y_pos = 218;
      text_to_display[i].field8_0x3d = 0;
      text_to_display[i].is_fond = false;
      INIT_TXT_BOX(&text_to_display[i]);
      text_to_display[i].text[0] = ' ';
      text_to_display[i].x_pos = text_to_display[i].centered_x_pos;
    }
    else
      text_to_display[i].field8_0x3d = 0;
  }
  display_txt_fee = 0xff;
  old_txt_fee = 0xff;
}


/* 3D89C 8016209C -O2 -msoft-float */
void allocate_poing_or_fee(void)
{
  u8 nb_objs;
  s16 i;
  Obj *obj;
  
  nb_objs = level.nb_objects;
  i = 0;
  obj = level.objects;
  if (nb_objs != 0)
  {
    do {
      if (obj->type == TYPE_POING_FEE && !(obj->flags & FLG(OBJ_ALIVE)))
      {
        obj->flags &= ~FLG(OBJ_ALIVE);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->speed_x = 8;
        obj->speed_y = 0;
        obj->anim_frame = 0;
        obj->flags |= FLG(OBJ_FLIP_X);
        png_or_fee_id = obj->id;
        break;
      }
      i++;
      obj++;
    } while (i < nb_objs);
  }
}

/* 3D94C 8016214C -O2 -msoft-float */
void init_moustique(void)
{
    if (!fin_du_jeu)
    {
        if (rayman_obj_id != -1)
          NewMs = true;
        else
          NewMs = false;
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
    record.is_playing = false;
  is_fee = false;
  INIT_TEXT_TO_DISPLAY();

  switch(num_world)
  {
    case 1:
      switch(num_level)
      {
        case 3:
          is_fee = true;
          __builtin_memcpy(text_to_display[0].text, s_hello_rayman_8012a7e0, sizeof(s_hello_rayman_8012a7e0));
          __builtin_memcpy(text_to_display[1].text, s_im_betilla_the_fairy_8012a7f0, sizeof(s_im_betilla_the_fairy_8012a7f0));
          __builtin_memcpy(text_to_display[2].text, s_and_im_going_to_help_you_8012a808, sizeof(s_and_im_going_to_help_you_8012a808));
          __builtin_memcpy(text_to_display[3].text, s_in_your_quest_8012a824, sizeof(s_in_your_quest_8012a824));
          __builtin_memcpy(text_to_display[4].text, s_i_can_give_you_a_new_power_8012a838, sizeof(s_i_can_give_you_a_new_power_8012a838));
          __builtin_memcpy(text_to_display[5].text, s_now_you_can_punch_with_your_fis_8012a858, sizeof(s_now_you_can_punch_with_your_fis_8012a858));
          __builtin_memcpy(text_to_display[6].text, s_good_luck__8012a87c, sizeof(s_good_luck__8012a87c));
          __builtin_memcpy(text_to_display[7].text, s_press_the__button_to_punch_8012a88c, sizeof(s_press_the__button_to_punch_8012a88c));
          __builtin_memcpy(text_to_display[8].text, s_the_longer_you_press_8012a8ac, sizeof(s_the_longer_you_press_8012a8ac));
          __builtin_memcpy(text_to_display[9].text, s_the_further_you_punch_8012a8c4, sizeof(s_the_further_you_punch_8012a8c4));
          Deter_Option_Caract(&text_to_display[7].text, options_jeu.Fist, 0xb);
          break;
        case 8:
          is_fee = true;
          __builtin_memcpy(text_to_display[0].text, s_youre_courageous_rayman_8012a8dc, sizeof(s_youre_courageous_rayman_8012a8dc));
          __builtin_memcpy(text_to_display[1].text, s_but_you_will_have_to_keep_at_it_8012a8f8, sizeof(s_but_you_will_have_to_keep_at_it_8012a8f8));
          __builtin_memcpy(text_to_display[5].text, s_you_now_have_the_power_to_hang_8012a91c, sizeof(s_you_now_have_the_power_to_hang_8012a91c));
          break;
        case 17:
          is_fee = true;
          __builtin_memcpy(text_to_display[0].text, s_great_job_rayman_but_youll_be_g_8012a940, sizeof(s_great_job_rayman_but_youll_be_g_8012a940));
          __builtin_memcpy(text_to_display[1].text, s_through_more_perilous_traps_8012a968, sizeof(s_through_more_perilous_traps_8012a968));
          __builtin_memcpy(text_to_display[2].text, s_i_hope_this_will_help_you_8012a988, sizeof(s_i_hope_this_will_help_you_8012a988));
          __builtin_memcpy(text_to_display[3].text, s_to_avoid_the_worst_8012a9a4, sizeof(s_to_avoid_the_worst_8012a9a4));
          __builtin_memcpy(text_to_display[5].text, s_now_you_can_grab_things_8012a9bc, sizeof(s_now_you_can_grab_things_8012a9bc));
          __builtin_memcpy(text_to_display[6].text, s_with_your_fist_8012a9d8, sizeof(s_with_your_fist_8012a9d8));
          __builtin_memcpy(text_to_display[7].text, s_to_grab_use_the__button_8012a9ec, sizeof(s_to_grab_use_the__button_8012a9ec));
          Deter_Option_Caract(&text_to_display[7].text, options_jeu.Fist, 0x11);
          break;
      }
      break;
    case 2:
      switch(num_level)
      {
        case 11:
          is_fee = true;
          __builtin_memcpy(text_to_display[0].text, s_things_are_not_going_to_get_8012aa08, sizeof(s_things_are_not_going_to_get_8012aa08));
          __builtin_memcpy(text_to_display[1].text, s_any_easier_for_you_rayman_8012aa28, sizeof(s_any_easier_for_you_rayman_8012aa28));
          __builtin_memcpy(text_to_display[2].text, s_but_this_new_power__8012aa44, sizeof(s_but_this_new_power__8012aa44));
          __builtin_memcpy(text_to_display[3].text, s_will_make_you_stronger_8012aa5c, sizeof(s_will_make_you_stronger_8012aa5c));
          __builtin_memcpy(text_to_display[7].text, s_now_you_can_use_your_hair_8012aa78, sizeof(s_now_you_can_use_your_hair_8012aa78));
          __builtin_memcpy(text_to_display[8].text, s_as_a_helicopter_8012aa94, sizeof(s_as_a_helicopter_8012aa94));
          __builtin_memcpy(text_to_display[9].text, s_to_do_it_press__twice_8012aaa8, sizeof(s_to_do_it_press__twice_8012aaa8));
          Deter_Option_Caract(&text_to_display[9].text, options_jeu.Jump, 0x10);
          break;
      }
      break;
    case 3:
      switch(num_level)
      {
        case 11:
          is_fee = true;
          __builtin_memcpy(text_to_display[0].text, s_things_are_going_to_get_8012aac4, sizeof(s_things_are_going_to_get_8012aac4));
          __builtin_memcpy(text_to_display[1].text, s_really_wild_from_now_on_rayman_8012aae0, sizeof(s_really_wild_from_now_on_rayman_8012aae0));
          __builtin_memcpy(text_to_display[2].text, s_youll_have_to_be_very_quick_8012ab04, sizeof(s_youll_have_to_be_very_quick_8012ab04));
          __builtin_memcpy(text_to_display[5].text, s_now_you_can_run_faster_8012ab28, sizeof(s_now_you_can_run_faster_8012ab28));
          __builtin_memcpy(text_to_display[7].text, s_to_run_press__while_walking_8012ab44, sizeof(s_to_run_press__while_walking_8012ab44));
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
