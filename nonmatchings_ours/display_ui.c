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
  
  DISPLAY_BLACKBOX(0, 0, 320, 20, 0, false);
  DISPLAY_BLACKBOX(0, 190, 320, 50, 0, false);
  txt_fee = display_txt_fee;
  if (txt_fee != 0xff)
  {
    obj = &level.objects[png_or_fee_id];
    __builtin_memcpy(&ttd, &text_to_display[txt_fee], sizeof(TextToDisplay));
    if (ttd.text[0] != '\0')
    {
        if (obj->flags & FLG(OBJ_ALIVE))
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
                false
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

/* matches, but do{}while(0); */
/* 1A04C 8013E84C -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DisplayJumellesNormal);*/

/*? DISPLAY_BLACKBOX(s32, s32, s32, s32, s32, s32);
? FUN_801397f4(s32, s32, s32, ?);*/
extern s32 PS1_PrevPrim;
extern Obj *mapobj;

void DisplayJumellesNormal(void)
{
    s32 x_3;
    s32 x_5;
    s16 temp_s0_8;
    s32 temp_s0_9;
    s32 y_1;
    s32 y_2;
    s32 y_3;
    s32 temp_s1_5;
    s32 x_4;
    s32 temp_s3_2;
    s32 size;
    s32 x_2;
    Sprite *sprite;
    s32 x_1;
    u8 width_1;
    s32 height_1;
    u8 width;
    s16 height_2;
    Sprite *sprites;
    s32 new_var;

    sprites = mapobj[24].sprites;
    PS1_PrevPrim = PS1_CurrentDisplay + 0x814;

    sprite = &sprites[1];
    height_1 = sprite->height;
    do {
        x_4 = 0xa0 - (sprite->width * 2);
        PS1_DrawColoredSprite(sprite, x_4, 53, 1);
    } while (0);
    x_3 = x_4 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 0);
    x_3 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 1);
    x_3 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_3, 53, 0);
    x_1 = (x_4 - height_1) + 5;
    x_3 += sprite->width;
    y_1 = height_1 + 0x30;
    PS1_DrawColoredSprite(sprite, x_1, y_1, 4);
    PS1_DrawColoredSprite(sprite, x_1, sprite->width + y_1, 6);
    x_2 = x_3 - 5;
    PS1_DrawColoredSprite(sprite, x_2, y_1, 7);
    y_2 = y_1 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_2, y_2, 5);
    size = height_1 - 5;
    DISPLAY_BLACKBOX(x_1, 53, size, size, 0, 0);
    DISPLAY_BLACKBOX(x_3, 53, size, size, 0, 0);
    y_2 += sprite->width;
    DISPLAY_BLACKBOX(x_1, y_2, size, size, 0, 0);
    DISPLAY_BLACKBOX(x_3, y_2, size, size, 0, 0);
    y_3 = y_2 - 5;
    PS1_DrawColoredSprite(sprite, x_4, y_3, 3);
    x_5 = x_4 + sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 2);
    x_5 += sprite->width;
    PS1_DrawColoredSprite(sprite, x_5, y_3, 3);
    PS1_DrawColoredSprite(sprite, sprite->width + x_5, y_3, 2);
    
    height_2 = sprite->height;
    width_1 = sprite->width;
    temp_s0_8 = x_4 - height_2;
    temp_s3_2 = temp_s0_8;
    temp_s1_5 = temp_s3_2 + ((height_2 + (width_1 * 2)) * 2);
    temp_s0_8 = ((width_1 + height_2) * 2) + 53;
    DISPLAY_BLACKBOX(0, 0, 0x140, 53, 0, 0);
    DISPLAY_BLACKBOX(0, temp_s0_8 - 0xA, 0x140, 0xFA - temp_s0_8, 0, 0);
    temp_s0_9 = temp_s0_8 - 0x3A;
    DISPLAY_BLACKBOX(0, 53, temp_s3_2 + 5, temp_s0_9, 0, 0);
    DISPLAY_BLACKBOX(temp_s1_5 - 5, 53, temp_s1_5 - temp_s3_2, temp_s0_9, 0, 0);
}