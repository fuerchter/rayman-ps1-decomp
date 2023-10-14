#include "display_ui.h"

/* tge and an instruction swap */
/* 19D20 8013E520 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_TEXT_FEE);*/

/*? DISPLAY_BLACKBOX(s16, s32, ?, ?, s32, s32);
? display2(Obj *);
? display_box_text(u8 *, u16, TextToDisplay *, u8 *);*/

void DISPLAY_TEXT_FEE(void)
{
  u8 txt_fee;
  Obj *obj;
  TextToDisplay ttd;
  s16 cen_x;
  s16 obj_x;
  s16 marg_x;
  
  DISPLAY_BLACKBOX(0, 0, 320, 20, 0, FALSE);
  DISPLAY_BLACKBOX(0, 190, 320, 50, 0, FALSE);
  txt_fee = display_txt_fee;
  if (txt_fee != 0xff)
  {
    obj = &level.objects[png_or_fee_id];
    __builtin_memcpy(&ttd, &text_to_display[txt_fee], sizeof(TextToDisplay));
    if (ttd.text[0] != '\0')
    {
        if (obj->flags & OBJ_ALIVE)
        {
            obj->screen_y_pos = 220 - obj->offset_by;
            cen_x = ttd.centered_x_pos;
            obj_x = obj->offset_bx + obj->screen_x_pos;
            marg_x = 8;
            if (cen_x < obj_x - marg_x)
            {
                if (cen_x + ttd.width > obj_x)
                {
                    /* tge */
                    ttd.text[(s16)((obj_x - (cen_x + marg_x)) / 7)] = '\0';
                    display_box_text(&ttd);
                }
                else
                    display_box_text(&ttd);
            }
            else if (cen_x + ttd.width <= obj_x)
                display_box_text(&ttd);
            
            DISPLAY_BLACKBOX(
                obj_x,
                obj->screen_y_pos + obj->offset_by - 20,
                30,
                18,
                0,
                FALSE
            );
            display2(obj);
        }
        else
            display_box_text(&ttd);
    }
  }

  txt_fee = old_txt_fee;
  if (txt_fee != 0xff) {
    __builtin_memcpy(&ttd, &text_to_display[txt_fee].text, sizeof(TextToDisplay));
    if (ttd.text[0] != '\0')
      display_box_text(&ttd);
  }
}

/*
reg swaps
that's not actually mapobj, right?
every local var ever
*/
/* 1A04C 8013E84C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DisplayJumellesNormal);*/

/*? DISPLAY_BLACKBOX(s32, s32, s32, s32, s32, s32);
? FUN_801397f4(s32, s32, s32, ?);*/
extern s32 PS1_PrevPrim;
extern Obj *mapobj;

void DisplayJumellesNormal(void)
{
    s32 width_plus;
    s32 width_plus_2;
    s16 temp_s0_8;
    s32 temp_s0_9;
    s32 height_plus;
    s32 temp_s1_2;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 minus_width;
    s32 temp_s3_2;
    s32 temp_s4_2;
    s32 temp_s5;
    Sprite *sprite;
    s32 temp_s7;
    u8 temp_s0_7;
    u8 height;
    u8 width;
    s16 temp_v0;
    Sprite *temp_s2;
    s32 new_var;

    temp_s2 = mapobj[0x18].sprites;
    PS1_PrevPrim = PS1_CurrentDisplay + 0x814;
    sprite = &temp_s2[1];
    height = sprite->height;
    new_var = height + 48;
    minus_width = 160 - (sprite->width * 2);
    PS1_DrawColoredSprite(sprite, minus_width, 53, 1);
    width_plus = minus_width + sprite->width;
    PS1_DrawColoredSprite(sprite, width_plus, 53, 0);
    width_plus = width_plus + sprite->width;
    PS1_DrawColoredSprite(sprite, width_plus, 53, 1);
    width_plus = width_plus + sprite->width;
    PS1_DrawColoredSprite(sprite, width_plus, 53, 0);
    temp_s7 = (minus_width - height) + 5;
    height_plus = new_var;
    width_plus = width_plus + sprite->width;
    PS1_DrawColoredSprite(sprite, temp_s7, height_plus, 4);
    PS1_DrawColoredSprite(sprite, temp_s7, sprite->width + height_plus, 6);
    temp_s5 = width_plus - 5;
    PS1_DrawColoredSprite(sprite, temp_s5, height_plus, 7);
    new_var = 2;
    temp_s1_2 = height_plus + sprite->width;
    PS1_DrawColoredSprite(sprite, temp_s5, temp_s1_2, 5);
    temp_s4_2 = height - 5;
    DISPLAY_BLACKBOX(temp_s7, 53, temp_s4_2, temp_s4_2, 0, 0);
    DISPLAY_BLACKBOX(width_plus, 53, temp_s4_2, temp_s4_2, 0, 0);
    temp_s1_2 = temp_s1_2 + sprite->width;
    DISPLAY_BLACKBOX(temp_s7, temp_s1_2, temp_s4_2, temp_s4_2, 0, 0);
    DISPLAY_BLACKBOX(width_plus, temp_s1_2, temp_s4_2, temp_s4_2, 0, 0);
    temp_s1_4 = temp_s1_2 - 5;
    PS1_DrawColoredSprite(sprite, minus_width, temp_s1_4, 3);
    width_plus_2 = minus_width + sprite->width;
    PS1_DrawColoredSprite(sprite, width_plus_2, temp_s1_4, 2);
    width_plus_2 = width_plus_2 + sprite->width;
    PS1_DrawColoredSprite(sprite, width_plus_2, temp_s1_4, 3);
    PS1_DrawColoredSprite(sprite, sprite->width + width_plus_2, temp_s1_4, 2);
    temp_v0 = sprite->height;
    temp_s0_7 = sprite->width;
    temp_s0_8 = minus_width - temp_v0;
    temp_s3_2 = temp_s0_8;
    temp_s1_5 = temp_s3_2 + ((temp_v0 + (temp_s0_7 * 2)) * new_var);
    temp_s0_8 = ((temp_s0_7 + temp_v0) * 2) + 53;
    DISPLAY_BLACKBOX(0, 0, 0x140, 53, 0, 0);
    DISPLAY_BLACKBOX(0, temp_s0_8 - 0xA, 0x140, 0xFA - temp_s0_8, 0, 0);
    temp_s0_9 = temp_s0_8 - 0x3A;
    DISPLAY_BLACKBOX(0, 53, temp_s3_2 + 5, temp_s0_9, 0, 0);
    DISPLAY_BLACKBOX(temp_s1_5 - 5, 53, temp_s1_5 - temp_s3_2, temp_s0_9, 0, 0);
}