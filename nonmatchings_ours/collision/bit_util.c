#include "collision/bit_util.h"

/*INCLUDE_ASM("asm/nonmatchings/collision/bit_util", snapToSprite);*/

void snapToSprite(Obj *obj1, Obj *obj2, u8 param_3, s32 param_4, u16 param_5)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    ObjState *temp_t0;
    ObjState *temp_v1;
    s16 temp_v0_1;
    s16 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s16 var_a0_2;
    s16 var_a0_3;
    s16 var_s0;
    s16 var_s1;
    s16 var_v0_3;
    s16 var_v0_6;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_a0_1;
    s32 temp_a0_2;
    s32 temp_s4;
    s32 var_v0_1;
    s32 var_v0_2;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_7;
    s32 var_v1_1;
    u8 temp_s0;
    u8 temp_s1;
    s32 var_a0_1;
    u8 var_t1;
    s32 test_1;
    /*volatile char new_var;*/
    s16 test_2;
    u8 new_var;

    var_a0_1 = obj2->anim_frame;
    temp_t0 = &obj2->eta[obj2->main_etat][obj2->sub_etat];
    var_t1 = temp_t0->anim_index;
    if (horloge[temp_t0->anim_speed & 0xF] == 0)
    {
        new_var = obj2->animations[var_t1].frames_count;
        if (!(temp_t0->flags & 0x10))
        {
            var_v1_1 = var_a0_1 + 1;
        }
        else
        {
            var_v1_1 = var_a0_1 - 1;
        }

        var_a0_1 = var_v1_1;
        if (var_v1_1 < 0 || (new_var - 1 < var_v1_1))
        {
            temp_v1 = &obj2->eta[temp_t0->next_main_etat][temp_t0->next_sub_etat];
            var_t1 = temp_v1->anim_index;
            new_var = obj2->animations[var_t1].frames_count;
            
            if (!(temp_v1->flags & 0x10))
            {
                var_a0_1 = 0;
            }
            else
                var_a0_1 = new_var - 1;
        }

            
    }
    temp_s1 = obj2->anim_frame;
    temp_s0 = obj2->anim_index;
    obj2->anim_frame = var_a0_1;
    obj2->anim_index = var_t1;
    GET_SPRITE_POS(obj2, param_3, &sp18, &sp1A, &sp1C, &sp1E);
    obj2->anim_index = temp_s0;
    obj2->anim_frame = temp_s1;
    temp_v0_1 = (param_4 + sp18) - obj1->x_pos;
    /* sgn() calls on android. dunno how to deal with yet */
    while (__builtin_abs(temp_v0_1) >= 0x10)
    {
        temp_v1_2 = obj1->x_pos;
        if (temp_v0_1 >= 0)
        {
            var_a0_2 = temp_v1_2;
            if (temp_v0_1 > 0)
            {
                var_a0_2 = temp_v1_2 + 0x10;
            }
            obj1->x_pos = var_a0_2;
        }
        else
        {
            obj1->x_pos = temp_v1_2 - 0x10;
        }
        if (temp_v0_1 >= 0)
        {
            var_v1_2 = temp_v0_1;
            if (temp_v0_1 > 0)
            {
                var_v1_2 = temp_v0_1 - 0x10;
            }
            var_v0_3 = var_v1_2;
        }
        else
        {
            var_v0_3 = temp_v0_1 + 0x10;
        }
        temp_v0_1 = var_v0_3;
    }
    temp_v0_2 = (param_5 + sp1A) - obj1->y_pos;
    while (__builtin_abs(temp_v0_2) >= 0x10)
    {
        temp_v1_3 = obj1->y_pos;
        if (temp_v0_2 >= 0)
        {
            var_a0_3 = temp_v1_3;
            if (temp_v0_2 > 0)
            {
                var_a0_3 = temp_v1_3 + 0x10;
            }
            obj1->y_pos = var_a0_3;
        }
        else
        {
            obj1->y_pos = temp_v1_3 - 0x10;
        }

        if (temp_v0_2 >= 0)
        {
            var_v1_3 = temp_v0_2;
            if (temp_v0_2 > 0)
            {
                var_v1_3 = temp_v0_2 - 0x10;
            }
            var_v0_6 = var_v1_3;
        }
        else
        {
            var_v0_6 = temp_v0_2 + 0x10;
        }
        temp_v0_2 = var_v0_6;
    }

    if (temp_v0_1 != 0)
    {
        temp_a0_1 = (((u8) flags[obj1->type].flags1 >> 4) & 1) + (((u8) flags[obj2->type].flags1 >> 3) & 2);
        switch (temp_a0_1)
        {
        case 0:
            temp_v0_1 += obj2->speed_x;
            break;
        case 3:
            temp_v0_1 = instantSpeed(obj2->speed_x) + (temp_v0_1 * 0x10);
            break;
        case 1:
            temp_v0_1 = (temp_v0_1 + obj2->speed_x) * 0x10;
            break;
        case 2:
            temp_v0_1 += instantSpeed(obj2->speed_x);
            break;
        }
    }

    if (temp_v0_2 != 0)
    {
        temp_a0_2 = (((u8) flags[obj1->type].flags1 >> 5) & 1) + (((u8) flags[obj2->type].flags1 >> 4) & 2);
        switch (temp_a0_2)
        {
        case 0:
            temp_v0_2 += obj2->speed_y;
            break;
        case 3:
            temp_v0_2 = instantSpeed(obj2->speed_y) + (temp_v0_2 * 0x10);
            break;
        case 1:
            temp_v0_2 = (temp_v0_2 + obj2->speed_y) * 0x10;
            break;
        case 2:
            temp_v0_2 += instantSpeed(obj2->speed_y);
            break;

        }
    }
    obj1->speed_x = temp_v0_1;
    obj1->speed_y = temp_v0_2;
}