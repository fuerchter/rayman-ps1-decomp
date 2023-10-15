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

/* no idea... */
/* 1A9D8 8013F1D8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", display_time);*/

/*? PS1_sprintf(u8, ? *, ?, s32 *);
? display_sprite(Obj *, s32, ?, ?, s32);
? display_text(u16 *, ?, ?, ?, s32);
? strcat(u16 *, ? *);*/
extern u8 *D_801CEF88;
extern s16 D_801CEF90[1];

extern s32 *D_801CEF94;
extern s16 *D_801CEF98;
extern s8 D_801CEF9A;
extern s16 D_801CF018;
extern u8 D_801F4EC0;
extern s32 D_801F620C;
extern s32 map_time;
extern u8 nb_wiz;
extern s16 sbar_obj_id;
extern u8 D_801CEF86;
extern u8 D_801CEF87;

void display_time(s16 arg0)
{
    u8 sp18[12];
    s16 sp1C;
    s8 sp1E;
    u8 sp30[8];
    Obj *temp_s1;
    s32 temp_lo;
    s32 temp_v0;
    u32 temp_a0;
    u32 temp_v1;
    u8 var_v0;
    u8 *new_var;

    temp_s1 = &level.objects[sbar_obj_id];
    if (arg0 != -2)
    {
        if (D_801CF018 == -1)
        {
            display_text(&D_801CEF88, 0x10C, 0xCA, 2, 7);
            temp_lo = arg0 / 60;
            display_sprite(temp_s1, (temp_lo / 10) + 0x1C, 0x10E, 0xCC, 0);
            display_sprite(temp_s1, (temp_lo % 10) + 0x1C, 0x11D, 0xCC, 0);
        }
        if (map_time < 0x65)
        {
            /*sp18[0]=D_801CEF90[0];*/
            temp_v1 = ray.flags & (~0x800);
            ray.flags = temp_v1;
            __builtin_memcpy(sp18, D_801CEF90, sizeof(D_801CEF90));
            PS1_sprintf(nb_wiz, &sp30, 0xA);
            strcat(&sp18, &sp30);
            strcat(&sp18, " tings to get/");
            if ((u8) D_801F4EC0 < 4U)
            {
                temp_a0 = D_801CEF86;
                temp_v1 = D_801CEF87;
                D_801CEF86 = temp_a0 + temp_v1;
                temp_v0 = -D_801CEF87;
                if (D_801CEF86 >= 6U)
                {
                    D_801CEF87 = (u8) temp_v0;
                    D_801CEF86 = 5;
                }
                else if (D_801CEF86 == 0)
                {
                    D_801CEF87 = (u8) temp_v0;
                    D_801CEF86 = 1;
                }
                if (D_801CF018 == -1)
                {
                    display_text(&sp18, 0xA0, 0x78, 2, D_801CEF86);
                }
            }
        }
        else if ((u32) (map_time - 0x79) < 0x28U)
        {
            __builtin_memcpy(sp18, D_801CEF94, 7);
            display_text(&sp18, 0xA0, 0x78, 0, 8);
        }
    }
}

/* psyq 3.0 cc1psx.exe, see Makefile. modulo but no tge... */
/* 1AFFC 8013F7FC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_CONTINUE_SPR);*/

/*? display2(Obj *);
? display_sprite(Obj *, s32, ?, ?, s32);
? display_text(? *, ?, ?, ?, s32);*/

void DISPLAY_CONTINUE_SPR(void)
{
    u32 dig_0;
    u32 dig_1;

    dig_0 = nb_continue / 10;
    dig_1 = nb_continue % 10;
    if (loop_timing == 0x00FF)
        display_text(&s_the_end_801cef9c, 177, 182, 2, 0);
    else
    {
        display_sprite(&div_obj, dig_0 + 28, 184, 162, 0);
        display_sprite(&div_obj, dig_1 + 28, 199, 162, 0);
    }
    display2(&ray);
    display2(&clock_obj);
    if (mapobj->flags & OBJ_ALIVE)
        display2(mapobj);
}