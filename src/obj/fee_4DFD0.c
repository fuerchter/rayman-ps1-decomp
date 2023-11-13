#include "obj/fee_4DFD0.h"

/* 4DFD0 801727D0 -O2 -msoft-float */
void wait_for_dialogue_fee(Obj *obj, s16 time)
{
  if (obj->timer < time)
    obj->timer++;
  else
  {
    obj->timer = 0;
    display_txt_fee++;
  }
}

/* 4E020 80172820 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/fee_4DFD0", DO_FEE_ETAPE);
#else
/*? skipToLabel(Obj *, ?, ?);*/

void DO_FEE_ETAPE(Obj *obj)
{
    u8 state;

    __asm__("nop\nnop\nnop");

    state = obj->field56_0x69;
    switch (state)
    {
    case 1:
        wait_for_dialogue_fee(obj, 100);
        if (display_txt_fee == 5 || text_to_display[display_txt_fee].text[0] == '\0')
        {
            skipToLabel(obj, 1, 0);
            obj->field56_0x69 = 0;
            display_txt_fee = 0xFF;
            obj->timer = 0;
        }
        break;
    case 2:
        wait_for_dialogue_fee(obj, 100);
        if (display_txt_fee == 7)
        {
            display_txt_fee = 0xFF;
            obj->field56_0x69 = 3;
            obj->timer = 0;
        }
        break;
    case 3:
        obj->timer++;
        if (obj->timer >= 51)
        {
            obj->field56_0x69 = 4;
            display_txt_fee = 7;
            obj->timer = 0;
        }
        break;
    case 4:
        if (horloge[2] != 0)
            obj->speed_y = -1;
        else
            obj->speed_y = 0;
        
        if (display_txt_fee < 9 && text_to_display[display_txt_fee + 1].text[0] != '\0')
            wait_for_dialogue_fee(obj, 120);
        break;
    case 0:
    default:
        display_txt_fee = 0xFF;
        break;
    }
}
const u8 rodata_DO_FEE_ETAPE[4] = {};
#endif

/* 4E1B4 801729B4 -O2 -msoft-float */
void fee_gives_super_evts(void)
{
    switch (num_world)
    {
    case 1:
        if (num_level == 3)
            RayEvts.flags0 |= FLG(RAYEVTS0_POING);
        if (num_level == 8)
            RayEvts.flags0 |= FLG(RAYEVTS0_HANG);
        if (num_level == 17)
            RayEvts.flags0 |= FLG(RAYEVTS0_GRAP);
        break;
    case 2:
        if (num_level == 11)
            RayEvts.flags0 |= FLG(RAYEVTS0_HELICO);
        break;
    case 3:
        if (num_level == 11)
            RayEvts.flags1 |= FLG(RAYEVTS1_RUN);
        break;
    }
}

/* 4E2D0 80172AD0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/fee_4DFD0", DO_FEE);
#else
void DO_FEE(Obj *obj)
{
    u8 old_txt;
    Obj *png_or_fee;
    u8 ray_main_etat;
    u8 unk_1;
    u8 flag_set;
    s16 y;

    __asm__("nop\nnop\nnop\nnop");

    old_txt = display_txt_fee;
    png_or_fee = &level.objects[png_or_fee_id];
    switch (obj->sub_etat)
    {
    case 0:
        if (obj->detect_zone_flag != 0)
        {
            if (__builtin_abs(ray.x_pos + ray.offset_bx - obj->x_pos + 2) < 3)
            {
                ray_main_etat = ray.main_etat;
                unk_1 = 21;
                if(
                    ray_main_etat < 2 ||
                    (ray.main_etat == 3 && (ray.sub_etat == 20 || ray.sub_etat == unk_1))
                )
                {
                    set_sub_etat(obj, 1);
                    skipToLabel(obj, 0, 1);
                    set_main_and_sub_etat(&ray, 3, 34);
                    remoteRayXToReach = -32000;
                    ray.flags |= FLG(OBJ_FLIP_X);
                }
            }
        }
        else
            ray_in_fee_zone = false;
        obj->field56_0x69 = 0;
        break;
    case 1:
        if (display_txt_fee == 0xFF)
        {
            obj->field56_0x69 = 1;
            display_txt_fee = 0;
            obj->timer = 0;
        }
        break;
    case 2:
    case 3:
        ray_main_etat = ray.main_etat;
        if(ray_main_etat < 2 || (ray.main_etat == 3 && ray.sub_etat == 34))
            set_main_and_sub_etat(&ray, 3, 35);
        if (ray.main_etat == 3 && ray.sub_etat == 36)
            ray.anim_frame = -1;
        break;
    case 4:
        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if (
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
        )
        {
            fee_gives_super_evts();
            obj->field56_0x69 = 2;
            display_txt_fee = 5;
            obj->timer = 0;
        }
        else
            obj->field56_0x69 = 0;
        break;
    case 6:
        if (ray.main_etat == 3)
        {
            if (ray.sub_etat == 36)
                set_sub_etat(&ray, 37);
            if (ray.main_etat == 3 && ray.sub_etat == 20)
            {
                remoteRayXToReach = ray.x_pos;
                if(obj->field56_0x69 == 4)
                {
                    set_main_and_sub_etat(&ray, 0, 0);
                    remoteRayXToReach = -32000;
                }
            }
        }
        break;
    }
    DO_FEE_ETAPE(obj);
    if (display_txt_fee != old_txt)
    {
        new_txt_fee = 1;
        if (display_txt_fee != 0xFF)
        {
            png_or_fee->active_timer = 0;
            png_or_fee->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_FLIP_X);
            png_or_fee->x_pos = xmap - png_or_fee->offset_bx;
            y = ymap - (png_or_fee->offset_by - 220);
            png_or_fee->y_pos = y;
            png_or_fee->screen_x_pos = -png_or_fee->offset_bx;
            png_or_fee->screen_y_pos = 220 - png_or_fee->offset_by;
            old_txt_fee = old_txt;
            png_or_fee->init_x_pos = png_or_fee->x_pos;
            png_or_fee->init_y_pos = png_or_fee->y_pos;
        }
    }
    if (new_txt_fee != 0)
    {
        if (text_to_display[old_txt_fee].y_pos < 260)
            text_to_display[old_txt_fee].y_pos++;
        else
            new_txt_fee = 0;
    }
    if (png_or_fee->flags & FLG(OBJ_ALIVE))
    {
        png_or_fee->x_pos += 4;
        png_or_fee->screen_x_pos += 4;
        if (png_or_fee->screen_x_pos > 310)
        {
            png_or_fee->anim_frame = 0;
            png_or_fee->flags &= ~FLG(OBJ_ALIVE);
            png_or_fee->flags &= ~FLG(OBJ_ACTIVE);
        }
    }
}
#endif