#include "collision/bit_util.h"

/* matches, but yet unknown flags[] use */
/*INCLUDE_ASM("asm/nonmatchings/collision/bit_util", snapToSprite);*/

void snapToSprite(Obj *obj_1, Obj *obj_2, u8 obj_2_spr, s32 x_offs, u16 y_offs)
{
    u8 obj_2_frames_count;
    ObjState *obj_2_eta_2;
    u8 prev_frame;
    u8 prev_index;
    s16 obj_2_x; s16 obj_2_y; s16 obj_2_w; s16 obj_2_h;
    s16 new_spd_x; s16 new_spd_y;
    s16 obj_2_anim_frame = obj_2->anim_frame;
    ObjState *obj_2_eta_1 = &obj_2->eta[obj_2->main_etat][obj_2->sub_etat];
    u8 obj_2_anim_index = obj_2_eta_1->anim_index;

    if (horloge[obj_2_eta_1->anim_speed & 0xF] == 0)
    {
        obj_2_frames_count = obj_2->animations[obj_2_anim_index].frames_count;
        obj_2_anim_frame += (obj_2_eta_1->flags & 0x10) ? -1 : 1; /* requires ternary to match? */
        if (obj_2_anim_frame < 0 || obj_2_anim_frame > obj_2_frames_count - 1)
        {
            obj_2_eta_2 = &obj_2->eta[obj_2_eta_1->next_main_etat][obj_2_eta_1->next_sub_etat];
            obj_2_anim_index = obj_2_eta_2->anim_index;
            obj_2_frames_count = obj_2->animations[obj_2_anim_index].frames_count;
            
            obj_2_anim_frame = (obj_2_eta_2->flags & 0x10) ? (obj_2_frames_count - 1) : 0;
        }
    }
    prev_frame = obj_2->anim_frame;
    prev_index = obj_2->anim_index;
    obj_2->anim_frame = obj_2_anim_frame;
    obj_2->anim_index = obj_2_anim_index;
    GET_SPRITE_POS(obj_2, obj_2_spr, &obj_2_x, &obj_2_y, &obj_2_w, &obj_2_h);
    obj_2->anim_index = prev_index;
    obj_2->anim_frame = prev_frame;

    new_spd_x = x_offs + obj_2_x - obj_1->x_pos;
    while (__builtin_abs(new_spd_x) >= 16)
    {
        obj_1->x_pos += SGN(new_spd_x) * 16;
        new_spd_x += SGN(new_spd_x) * -16;
    }

    new_spd_y = y_offs + obj_2_y - obj_1->y_pos;
    while (__builtin_abs(new_spd_y) >= 16)
    {
        obj_1->y_pos += SGN(new_spd_y) * 16;
        new_spd_y += SGN(new_spd_y) * -16;
    }

    if (new_spd_x != 0)
    {
        /* TODO: ??? */
        switch (
            (flags[obj_1->type].flags1 >> 4 & 1) +
            (flags[obj_2->type].flags1 >> 3 & 2)
        )
        {
        case 0:
            new_spd_x += obj_2->speed_x;
            break;
        case 3:
            new_spd_x = instantSpeed(obj_2->speed_x) + new_spd_x * 16;
            break;
        case 1:
            new_spd_x = (new_spd_x + obj_2->speed_x) * 16;
            break;
        case 2:
            new_spd_x += instantSpeed(obj_2->speed_x);
            break;
        }
    }

    if (new_spd_y != 0)
    {
        switch (
            (flags[obj_1->type].flags1 >> 5 & 1) +
            (flags[obj_2->type].flags1 >> 4 & 2)
        )
        {
        case 0:
            new_spd_y += obj_2->speed_y;
            break;
        case 3:
            new_spd_y = instantSpeed(obj_2->speed_y) + new_spd_y * 16;
            break;
        case 1:
            new_spd_y = (new_spd_y + obj_2->speed_y) * 16;
            break;
        case 2:
            new_spd_y += instantSpeed(obj_2->speed_y);
            break;
        }
    }

    obj_1->speed_x = new_spd_x;
    obj_1->speed_y = new_spd_y;
}