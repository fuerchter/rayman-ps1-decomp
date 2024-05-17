#include "draw.h"

extern u8 PS1_DrawSpriteSemiTrans;
extern void *PS1_PrevPrim; /* should this be labelled as ordering table instead? */
extern s16 D_801CEF78;
extern s16 D_801CF600[16]; /* list of angles? */
extern u8 D_801E4C20;
extern Obj *PS1_BossObj;

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawColoredSprite);

/* 15340 80139B40 -O2 -msoft-float */
void PS1_DrawSprite(Sprite *sprite, s16 x, s16 y, u8 param_4)
{
    PS1_DrawColoredSprite(sprite, x, y, param_4);
}

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawScaledSprite);

/* 1555C 80139D5C -O2 -msoft-float */
void FUN_80139d5c(s16 *p_poly_x, s16 *p_poly_y, s16 param_3, s16 param_4, s16 angle)
{
    s16 old_poly_x = *p_poly_x;
    s16 old_poly_y = *p_poly_y;

    *p_poly_x = 
        (old_poly_x * rcos(angle) >> 12) -
        (old_poly_y * rsin(angle) >> 12) +
        (
            (param_3 - (param_3 * rcos(angle) >> 12)) +
            (param_4 * rsin(angle) >> 12)
        );
    *p_poly_y =
        (old_poly_x * rsin(angle) >> 12) +
        (old_poly_y * rcos(angle) >> 12) +
        (
            (param_4 - (param_4 * rcos(angle) >> 12)) -
            (param_3 * rsin(angle) >> 12)
        );
}

INCLUDE_ASM("asm/nonmatchings/draw", PS1_DrawRay);

/* 15C54 8013A454 -O2 -msoft-float */
void display_sprite(Obj *param_1, u8 sprite, s16 x, s16 y, u8 param_5)
{
    PS1_DrawSprite(&param_1->sprites[sprite], x, y, param_5);
}

/* 15C9C 8013A49C -O2 -msoft-float */
void display2(Obj *obj)
{
    u8 flip_x;
    s16 i;
    u8 sprite_ind;
    Sprite *sprite;
    s16 x_pos; s16 y_pos;
    s16 unk_1;
    s16 scale = obj->scale;
    Animation *anim = &obj->animations[obj->anim_index];
    s32 layers_count = anim->layers_count & 0x3FFF;
    AnimationLayer *layer = &anim->layers[layers_count * obj->anim_frame];

    if ((u16) (obj->screen_x_pos + 320) <= 640 && (u16) (obj->screen_y_pos + 240) <= 480)
    {
        flip_x = (obj->flags >> OBJ_FLIP_X) & 1;
        for (i = 0; i < (anim->layers_count & 0x3FFF); i++)
        {
            sprite_ind = layer[i].sprite;
            if (sprite_ind != 0)
            {
                sprite = &obj->sprites[sprite_ind];
                if (!flip_x)
                    x_pos = obj->screen_x_pos + layer[i].x_pos;
                else
                {
                    unk_1 = 0;
                    if (obj->scale == 0x100 && i == 5)
                        unk_1 = -(obj->anim_index - 14 <= 2U) & 0xFFF0;
                    x_pos = unk_1 + (obj->screen_x_pos + obj->offset_bx * 2 - layer[i].x_pos - sprite->width);
                }
                y_pos = layer[i].y_pos + obj->screen_y_pos;
                if (obj == &ray)
                    PS1_DrawRay(
                        sprite,
                        (s16) get_proj_x(ray.scale, x_pos), (s16) get_proj_y(ray.scale, y_pos),
                        flip_x ^ layer[i].flip_x,
                        i
                    );
                else
                {
                    if (scale == 0)
                        PS1_DrawSprite(
                            sprite,
                            x_pos, y_pos,
                            flip_x ^ layer[i].flip_x
                        );
                    else
                        PS1_DrawScaledSprite(
                            sprite,
                            (s16) get_proj_x(scale, x_pos), (s16) get_proj_y(scale, y_pos),
                            flip_x ^ layer[i].flip_x,
                            scale
                        );
                }
            }
        }
        PS1_DrawSpriteSemiTrans = 0;
    }
}

/* 15F70 8013A770 -O2 -msoft-float */
void DISPLAY_POING(void)
{
    if (poing.is_active)
        display2(&level.objects[poing_obj_id]);
}

/* 15FB8 8013A7B8 -O2 -msoft-float */
void DISPLAY_CLING(void)
{
    Obj *c_1up;
    Obj *c_pow;

    if (id_Cling_1up != -1)
    {
        c_1up = &level.objects[id_Cling_1up];
        c_1up->screen_x_pos = 53 - c_1up->offset_bx;
        c_1up->screen_y_pos = 10 - c_1up->offset_hy;
        if (c_1up->timer == 0)
            display2(c_1up);
    }
    if (id_Cling_Pow != -1)
    {
        c_pow = &level.objects[id_Cling_Pow];
        c_pow->screen_x_pos = 58 - c_pow->offset_bx;
        c_pow->screen_y_pos = 19 - c_pow->offset_hy;
        if (c_pow->timer == 0)
            display2(c_pow);
    }
}

INCLUDE_ASM("asm/nonmatchings/draw", display_bar_boss);

/* 16314 8013AB14 -O2 -msoft-float */
void DISPLAY_FIXE(s16 left_time)
{
    Obj *div_obj;

    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[10];
    div_obj = &level.objects[sbar_obj_id];
    if (left_time == -2)
    {
        display_sprite(div_obj, 27, 8, 10, 0);
        display_sprite(div_obj, 56, 252, 10, 0);
        display_sprite(div_obj, status_bar.lives_digits[0] + 28, 47, 10, 0);
        display_sprite(div_obj, status_bar.lives_digits[1] + 28, 62, 10, 0);
        if (ray.hit_points != 0xff && !fin_du_jeu)
        {
            display_sprite(div_obj, status_bar.hp_sprites[1] + 17, 27, 32, 0);
            if (status_bar.max_hp == 4)
                display_sprite(div_obj, status_bar.hp_sprites[0] + 20, 51, 32, 0);
        }
        display_sprite(div_obj, status_bar.wiz_digits[0] + 28, 284, 10, 0);
        display_sprite(div_obj, status_bar.wiz_digits[1] + 28, 298, 10, 0);
    }
    else
    {
        if (D_801CF018 == -1)
        {
            display_sprite(div_obj, 56, 14, 202, 0);
            display_sprite(div_obj, status_bar.wiz_digits[0] + 28, 46, 202, 0);
            display_sprite(div_obj, status_bar.wiz_digits[1] + 28, 60, 202, 0);
        }
    }

    if (id_Cling_1up != -1 || id_Cling_Pow != -1)
        DISPLAY_CLING();
    DO_DARK2_AFFICHE_TEXT();
    if (PS1_BossObj)
        display_bar_boss(PS1_BossObj);
}

/* 16554 8013AD54 -O2 -msoft-float */
#ifndef NONMATCHINGS /* div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/draw", FUN_8013ad54);
#else
void FUN_8013ad54(s16 param_1, s16 param_2, s16 param_3)
{
    Obj *sbar_obj = &level.objects[sbar_obj_id];
    u8 spr_3 = (param_1 % 10);
    u8 spr_2 = (param_1 / 10) % 10;
    u8 spr_1 = (param_1 / 100);
    s32 spr_add = 28; /* TODO: did not get this in DISPLAY_FIXE, so define instead? */
    s32 display_mode = 0;
    
    display_sprite(sbar_obj, spr_1 + spr_add, param_2, param_3, display_mode);
    display_sprite(sbar_obj, spr_2 + spr_add, param_2 + 16, param_3, display_mode);
    display_sprite(sbar_obj, spr_3 + spr_add, param_2 + 32, param_3, display_mode);

    __asm__("nop");
}
#endif

/* 166AC 8013AEAC -O2 -msoft-float */
void DrawWldPointPlan2Normal(s16 x0, s16 y0)
{
    SPRT_8 *p = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    p->x0 = x0; p->y0 = y0;
    p->u0 = 64; p->v0 = 0;
    AddPrim(&PS1_CurrentDisplay->ordering_table[5], p);
}

/* 16714 8013AF14 -O2 -msoft-float */
void PS1_DisplayPtsPrim(void)
{
    AddPrim(&PS1_CurrentDisplay->ordering_table[5], &PS1_CurrentDisplay->field3_0x1f0);
}

/* 16740 8013AF40 -O2 -msoft-float */
void DISPLAY_POINT(s32 x0, s32 y0)
{
    if (((u16) (x0 - 43) <= 240) && ((u16) (y0 - 54) <= 134))
        DrawWldPointPlan2Normal((s16) x0, (s16) y0 - 2);
}

/* 16790 8013AF90 -O2 -msoft-float */
void DISPLAY_PTS_TO_PLAN2(s32 x1, s32 y1, s32 x2, s32 y2, s16 percentage)
{
    s16 x_offs = 52;
    s16 y_offs = 55;
    s16 new_x1 = x1 + x_offs - xmap;
    s16 new_x2 = x2 + x_offs - xmap;
    s16 new_y1 = y1 + y_offs - ymap;
    s16 new_y2 = y2 + y_offs - ymap;
    
    Bresenham(
        DISPLAY_POINT,
        new_x1, new_y1,
        new_x2, new_y2,
        7,
        percentage
    );
}

/* 16820 8013B020 -O2 -msoft-float */
void DISPLAY_PLATEAU(Obj *obj)
{
    display2(obj);
}

/* 16840 8013B040 -O2 -msoft-float */
void draw_flocon1_Normal(s16 x0, s16 y0)
{
    TILE_1 *tile = &PS1_CurrentDisplay->tile1s[(u16) D_801FA690++];

    tile->r0 = 187; tile->g0 = 187; tile->b0 = 251;
    tile->x0 = x0; tile->y0 = y0;
    AddPrim(PS1_PrevPrim, tile);
    PS1_PrevPrim = tile;
}

/* 168C0 8013B0C0 -O2 -msoft-float */
void draw_flocon2_Normal(s16 x0, s16 y0)
{
    TILE_1 *tile = &PS1_CurrentDisplay->tile1s[(u16) D_801FA690++];
    
    tile->r0 = 199; tile->g0 = 223; tile->b0 = 247;
    tile->x0 = x0; tile->y0 = y0;
    AddPrim(PS1_PrevPrim, tile);
    PS1_PrevPrim = tile;
}

/* 16944 8013B144 -O2 -msoft-float */
void draw_flocon3_Normal(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];
    
    sprt->u0 = 8; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 169B4 8013B1B4 -O2 -msoft-float */
void draw_flocon4_Normal(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    sprt->u0 = 16; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16A24 8013B224 -O2 -msoft-float */
void draw_flocon5_Normal(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];
    
    sprt->u0 = 40; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16A94 8013B294 -O2 -msoft-float */
void FUN_8013b294(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    sprt->u0 = 48; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16B04 8013B304 -O2 -msoft-float */
void FUN_8013b304(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];
    
    sprt->u0 = 56; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16B74 8013B374 -O2 -msoft-float */
void draw_pluie4_Normal(s16 x0, s16 y0)
{
    TILE_1 *tile = &PS1_CurrentDisplay->tile1s[(u16) D_801FA690++];

    tile->r0 = 95; tile->g0 = 107; tile->b0 = 167;
    tile->x0 = x0; tile->y0 = y0;
    AddPrim(PS1_PrevPrim, tile);
    PS1_PrevPrim = tile;
}

/* 16BF8 8013B3F8 -O2 -msoft-float */
void draw_pluie5_Normal(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    sprt->u0 = 0; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16C64 8013B464 -O2 -msoft-float */
void draw_pluie6_Normal(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    sprt->u0 = 24; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

/* 16CD4 8013B4D4 -O2 -msoft-float */
void FUN_8013b4d4(s16 x0, s16 y0)
{
    SPRT_8 *sprt = &PS1_CurrentDisplay->field_0x1e9c_0x321b[(u16) D_801F4A28++];

    sprt->u0 = 32; sprt->v0 = 0;
    sprt->x0 = x0; sprt->y0 = y0;
    AddPrim(PS1_PrevPrim, sprt);
    PS1_PrevPrim = sprt;
}

INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_behind);

INCLUDE_ASM("asm/nonmatchings/draw", display_flocons_before);

INCLUDE_ASM("asm/nonmatchings/draw", display_pix_gerbes);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_CYMBALE);

INCLUDE_ASM("asm/nonmatchings/draw", DISPLAY_ALL_OBJECTS);
