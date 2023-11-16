#include "bonus_343EC.h"

extern Obj *PS1_BonusNovas[2];
extern Obj *PS1_BonusOneUps[2];
extern u8 PS1_TimeString[24];
extern s16 allowed_time[192];
extern s16 loop_time;

/* 343EC 80158BEC -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/bonus_343EC", do_perfect_bonus);
#else
s32 do_perfect_bonus(void)
{
  s32 unk_1;
  s16 unk_2;
  s16 i;
  s16 done;

  FUN_8017a6f8();
  horloges();
  if (loop_time == 0)
  {
    INIT_FADE_IN();
    unk_1 = (left_time / 60) + 1;
    unk_2 = 33;
    sprintf(
      PS1_TimeString,
      "/%d : %-02d/",
      allowed_time[(s16) (((u16) num_world * 32) - unk_2 + num_level)] - unk_1,
      (map_time - 120) % 60
    );
  }

  if ((u8) get_bonus_map_complete(num_world, num_level))
  {
    display_text("/great !/", 160, 80, 0, 4);
    display_text("/your time:/", 160, 130, 2, 0);
    display_text(PS1_TimeString, 160, 170, 0, 5);
  }
  else
  {
    display_text("/perfect !/", 160, 90, 0, 6);
    if (loop_time == 62)
    {
      for (i = 0; i < 1; i++)
      {
        PS1_BonusNovas[i] = allocateNOVA();
        PS1_BonusNovas[i]->screen_x_pos = i * 32 + 80;
        PS1_BonusNovas[i]->screen_y_pos = 70;
        PS1_BonusNovas[i]->flags |= FLG(OBJ_ACTIVE);
        PS1_BonusOneUps[i] = findfirstInactiveObject(TYPE_ONEUP_ALWAYS);
        PS1_BonusOneUps[i]->flags |= FLG(OBJ_ACTIVE);
        PS1_BonusOneUps[i]->screen_x_pos = PS1_BonusNovas[i]->screen_x_pos;
        PS1_BonusOneUps[i]->screen_y_pos = PS1_BonusNovas[i]->screen_y_pos;
        DO_ANIM(PS1_BonusNovas[i]);
        DO_ANIM(PS1_BonusOneUps[i]);
        Add_One_RAY_lives();
      }
    }
    if (loop_time > 62)
    {
      
      for (i = 0; i < 1; i++)
      {
        DO_ANIM(PS1_BonusNovas[i]);
        DO_ANIM(PS1_BonusOneUps[i]);
        switchOff(PS1_BonusNovas[i]);
        if (PS1_BonusOneUps[i]->flags & FLG(OBJ_ACTIVE))
          display2(PS1_BonusOneUps[i]);
        if (PS1_BonusNovas[i]->flags & FLG(OBJ_ACTIVE))
          display2(PS1_BonusNovas[i]);
      }
    }
  }
  done = false;
  if (loop_time == 240)
  {
    done = true;
    INIT_FADE_IN();
    fix_numlevel(&ray);
  }

  if (fade != 0)
    DO_FADE();
  loop_time++;
  FUN_8013045c();

  __asm__("nop\nnop");

  return done;
}
#endif