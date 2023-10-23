#include "display_ui.h"

/*
presumably need to finish display_time first?

mips-linux-gnu-ld: build/src/display_ui.c.o: in function `display_time':
src/display_ui.c:(.text+0x11d0): undefined reference to `D_801CEF98'
mips-linux-gnu-ld: src/display_ui.c:(.text+0x11d4): undefined reference to `D_801CEF98'
*/
/*u8 PS1_star_spr[8] = {0x15, 0x16, 0x17, 0x18, 0x15, 0x19, 0x16, 0x15};
u8 s__801cef84[] = "%";
u8 PS1_TingsToGet_Col = 1;
u8 PS1_TingsToGet_ColAdd = 1;
u8 s_time_801cef88[] = "time";
u8 s__801cef90[] = "/";
u8 s_go__801cef94[] = "/go !/";
u8 s_the_end_801cef9c[] = "the end";*/

/* TODO: Display struct */
extern s32 PS1_CurrentDisplay;

/* 19A38 8013E238 -O2 */
/*? ClearImage(s32, ?, ?, ?);*/

void CLRSCR(void)
{
    ClearImage(PS1_CurrentDisplay + 0x14, 0, 0, 0);
}

/* 19A6C 8013E26C -O2 */
/*? PS1_DrawSprite(Sprite *, s16, s16, ?);
u8 myRand(?, ? *);*/

void display_etoile(s32 in_x, s32 in_y)
{
    u8 loc_star_spr[8];
    GrpStar *temp;
    GrpStar *star;
    u8 rand_res;
    s16 draw_x;
    s16 draw_y;
    u8 sprite;

    __builtin_memcpy(&loc_star_spr, &PS1_star_spr, sizeof(PS1_star_spr));
    
    temp = &grp_stars[current_star];
    star = temp;
    star->timer++;
    if (star->timer > star->length)
    {
        rand_res = myRand(7);
        star->timer = 0;
        star->length = myRand(5);
        star->dist = rand_res;
        star->sprite_table_index = rand_res;
    }
    draw_x = star->dist + (in_x - xmap) - 8;
    draw_y = star->dist + (in_y - ymap);
    if (
        draw_x > 0 && 320 - draw_x > 0 &&
        draw_y > 0 && 240 - draw_y > 0
    )
    {
        sprite = loc_star_spr[star->sprite_table_index];
        PS1_DrawSprite(
            &level.objects[poing_obj_id].sprites[sprite],
            draw_x,
            draw_y,
            0
        );
    }
    if (current_star < 30)
        current_star++;
}

/* 19C08 8013E408
/*? Bresenham(void (*)(s32, s32), s16, s16, s16, s32, s32, s32);
? GET_SPRITE_POS(u8 *, ?, u16 *, u16 *, u16 *, u16 *);*/

void display_grp_stars(void)
{
    Obj *grapped;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 cen_x;
    s16 grapped_x;

    if (ray.main_etat == 7 && (ray.flags & OBJ_ALIVE))
    {
        current_star = 0;
        grapped = &level.objects[id_obj_grapped];
        GET_SPRITE_POS(&ray, 1, &x, &y, &w, &h);

        cen_x = x + (w >> 1);
        grapped_x = grapped->offset_bx + grapped->x_pos;
        Bresenham(
            display_etoile,
            cen_x,
            (s16) (y + (h >> 1) - 6),
            grapped_x,
            (s16) (grapped->offset_hy + grapped->y_pos),
            5,
            100
        );
    }
}

/* 19D20 8013E520 -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_TEXT_FEE);

/* 1A04C 8013E84C -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DisplayJumellesNormal);

/* 1A338 8013EB38 -O2 */
/*? FUN_80139014(s16, s16, s16, s16, s32, s32);*/

void PS1_DisplayWorldMapBg1(s16 x1, s16 y1, s16 x2, s16 y2)
{
    PS1_DisplayWorldMapBg2(x1, y1, x2, y2, 130, 320 - x2);
}

/* trap */
/* 1A388 8013EB88 -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_SAVE_SPRITES);

/* 1A8C0 8013F0C0 -O2 */
/*? display_sprite(Obj *, ?, s32, s32, s32);*/

void DISPLAY_SAVE_POING(void)
{
  Obj *obj;
  s16 temp;
  
  obj = mapobj;
  display_sprite(obj, 2, 10, debut_options + (positiony - 1) * (ecarty + 23) - 23, 1);
  temp = 11;
  display_sprite(obj, 2, (positionx2 - 1) * 100, debut_sortie - ((obj->sprites[2].height >> 1) + temp), 1);
  if (fichier_a_copier != 0)
    display_sprite(obj, 1, 10, debut_options + (fichier_a_copier - 1) * (ecarty + 23) - 23, 1);
}

/* 1A9D8 8013F1D8 -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", display_time);

/* 1AC60 8013F460 -O2 */
void PS1_LoadPts(void)
{
  u8 image [250];
  RECT rect;
  u8 *pixel_1;
  u8 *pixel_2;
  s32 i;
  
  rect.x = 320; rect.y = 0; rect.w = 40; rect.h = 8;
  ClearImage(&rect, 0, 0, 0);
  i = 63;
  pixel_1 = image + i;
  while (i >= 0)
  {
    *pixel_1 = 0;
    i--;
    pixel_1--;
  }

  rect.w = 4;
  image[1] = 4; image[8] = 5;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[0] = 6; image[8] = 7; image[1] = 7; image[9] = 8;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);
  
  image[0] = 0; image[17] = 6; image[10] = 6; image[8] = 6;
  image[1] = 6; image[9] = 8;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[10] = 2; image[1] = 2; image[17] = 3; image[8]= 3;
  image[2] = 4; image[9] = 5;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[8] = 0; image[1] = 0; image[11] = 2; image[2] = 2;
  image[18] = 3; image[9] = 3; image[3] = 3; image[25] = 4;
  image[16] = 4; image[10] = 4; image[17] = 5; image[24] = 6;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[3] = 0; image[24] = 0; image[26] = 6; image[25] = 6;
  image[19] = 6; image[16] = 6; image[11] = 6; image[8] = 6;
  image[2] = 6; image[1] = 6; image[18] = 7; image[17] = 7;
  image[10] = 7; image[9] = 7;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[26] = 6; image[25] = 6; image[19] = 6; image[16] = 6;
  image[11] = 6; image[8] = 6; image[2] = 6; image[1] = 6;
  image[18] = 8; image[17] = 8; image[10] = 8; image[9] = 8;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);

  image[8] = 0; image[1] = 0; image[43] = 6; image[42] = 6;
  image[29] = 6; image[24] = 6; image[21] = 6; image[16] = 6;
  image[3] = 6; image[2] = 6; image[36] = 7; image[33] = 7;
  image[12] = 7; image[9] = 7; image[20] = 8; image[19] = 8;
  image[18] = 8; image[17] = 8; image[11] = 8; image[10] = 8;
  image[35] = 8; image[34] = 8; image[28] = 8; image[27] = 8;
  image[26] = 8; image[25] = 8;
  rect.x = rect.x + rect.w;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);
  i = 63;
  pixel_2 = image + i;
  rect.x = rect.x + rect.w;
  while (i > -1)
  {
    *pixel_2 = 0;
    i--;
    pixel_2--;
  }

  image[8] = 12; image[1] = 12; image[26] = 80; image[25] = 80;
  image[19] = 80; image[16] = 80; image[11] = 80; image[2] = 80;
  image[9] = 14; image[18] = 9; image[17] = 10; image[10] = 10;
  LoadImage(&rect, (u32 *)&image);
  DrawSync(0);
}

/* 1AFFC 8013F7FC -O2 */
INCLUDE_ASM("asm/nonmatchings/display_ui", DISPLAY_CONTINUE_SPR);

/* 1B0F8 8013F8F8 -O2 */
/*? display_sprite(Obj *, ?, ?, s32, s32);*/

void PS1_PromptCardDisplayPoing(void)
{
    display_sprite(mapobj, 2, 120, ((positiony_mc - 1) * 22) + 157, 1);
}

/* 1B150 8013F950 -O2 */
/*? display_sprite(Obj *, ?, s32, s32, s32);*/

void DISPLAY_OPTIONS_POING(void)
{
    Obj *obj;

    obj = mapobj;
    if (position == 7)
        display_sprite(obj, 2, text_to_display[7].centered_x_pos - 35, PS1_display_y1 - 14, 1);
    else
        display_sprite(obj, 2, 20, debut_sortie + position * (PS1_display_y2 + 0xF) - 0xF, 1);
}
