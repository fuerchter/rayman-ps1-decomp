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

/* div/nop swap, otherwise "matches, but..." */
/* 1A9D8 8013F1D8 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", display_time);*/

/*? PS1_sprintf(u8, ? *, ?, s32 *);
? display_sprite(Obj *, s32, ?, ?, s32);
? display_text(u16 *, ?, ?, ?, s32);
? strcat(u16 *, ? *);*/

void display_time(s16 time)
{
    Obj *sbar_obj;
    u8 text[24];
    u8 nb_wiz_text[8];
    s32 time_div;
    u32 col;
    u32 col_add;

    sbar_obj = &level.objects[sbar_obj_id];
    if (time != -2)
    {
        if (D_801CF018 == -1)
        {
            display_text(&s_time_801cef88, 0x10C, 0xCA, 2, 7);
            time_div = time / 60;
            display_sprite(sbar_obj, (time_div / 10) + 0x1C, 0x10E, 0xCC, 0);
            display_sprite(sbar_obj, (time_div % 10) + 0x1C, 0x11D, 0xCC, 0);
        }
        if (map_time < 0x65)
        {
            __builtin_memcpy(text, s__801cef90, sizeof(s__801cef90));
            ray.flags &= ~FLG(OBJ_ACTIVE);
            PS1_sprintf(nb_wiz, &nb_wiz_text, 0xA);
            strcat(&text, &nb_wiz_text);
            strcat(&text, " tings to get/");
            if (horloge[8] < 4)
            {
                col = PS1_TingsToGet_Col;
                col_add = PS1_TingsToGet_ColAdd;
                PS1_TingsToGet_Col = col + col_add;
                if (PS1_TingsToGet_Col >= 6)
                {
                    PS1_TingsToGet_ColAdd *= -1;
                    PS1_TingsToGet_Col = 5;
                }
                else if (PS1_TingsToGet_Col == 0)
                {
                    PS1_TingsToGet_ColAdd *= -1;
                    PS1_TingsToGet_Col = 1;
                }

                if (D_801CF018 == -1)
                    display_text(&text, 0xA0, 0x78, 2, PS1_TingsToGet_Col);
            }
        }
        else if (map_time - 0x79 < 0x28U)
        {
            __builtin_memcpy(text, s_go__801cef94, 7);
            display_text(&text, 0xA0, 0x78, 0, 8);
        }
    }
}

/* div/nop swap, otherwise "matches, but..." modulo but no tge... */
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
    if (mapobj->flags & FLG(OBJ_ALIVE))
        display2(mapobj);
}

/* div/nop swap, missing addiu, otherwise "matches, but..." */
/*INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_SAVE_SPRITES);*/

/* 1A388 8013EB88 -O2 -msoft-float */
/*? display_sprite(Obj *, s16, s16, s32, s32);
? display_text(u8 *, s16, s32, ?, s32);
extern ? D_801E4D62;
extern ? D_801E4D63;*/

void DISPLAY_SAVE_SPRITES(s16 x, s16 y)
{
    Obj *loc_mapobj;
    u8 num_lives;
    s32 pct;
    s16 sprite_ind_1;
    s16 sprite_ind_2;
    s16 sprite_ind_3;

    loc_mapobj = mapobj;
    num_lives = loadInfoRay[y].num_lives;
    sprite_ind_1 = ((s32) num_lives / 10) + 28;
    sprite_ind_2 = (num_lives % 10) + 28;
    /* TODO: macro for y? */
    display_sprite(&div_obj, 27, x, (debut_options + y * (ecarty + 23) - 23), 0);
    x += div_obj.sprites[27].width;
    display_sprite(&div_obj, sprite_ind_1, x, (debut_options + y * (ecarty + 23)) - 23, 0);
    x += div_obj.sprites[sprite_ind_1].width;
    display_sprite(&div_obj, sprite_ind_2, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    x = x + div_obj.sprites[28].width + 10;

    sprite_ind_1 = (loadInfoRay[y].num_continues % 10) + 28;
    display_sprite(loc_mapobj, 57, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    x += loc_mapobj->sprites[57].width;
    display_sprite(&div_obj, sprite_ind_1, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    
    pct = loadInfoRay[y].num_cages * 100 / 102;
    sprite_ind_1 = ((s16) pct / 100) + 28;
    sprite_ind_2 = ((s16) pct / 10 % 10) + 28;
    sprite_ind_3 = ((s16) pct % 10) + 28;
    x = x + div_obj.sprites[37].width + 10;
    display_sprite(&div_obj, sprite_ind_1, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    x += div_obj.sprites[sprite_ind_1].width;
    display_sprite(&div_obj, sprite_ind_2, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    x += div_obj.sprites[sprite_ind_2].width;
    display_sprite(&div_obj, sprite_ind_3, x, (debut_options + (y * (ecarty + 23))) - 23, 0);
    display_text(s__801cef84, (s16) (x + div_obj.sprites[sprite_ind_3].width), debut_options + (y * (ecarty + 23)), 1, (s32) colour);
}