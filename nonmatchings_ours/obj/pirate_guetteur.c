#include "obj/pirate_guetteur.h"

/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj/pirate_guetteur", allocatePirateGuetteurBomb);*/

/* 5C8CC 801810CC -O2 -msoft-float */
void allocatePirateGuetteurBomb(Obj *obj, s32 param_2, u8 param_3, u8 param_4)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    Obj *cur_obj;
    s32 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1_2;
    s16 var_a0;
    s16 i;
    s16 var_s1;
    s16 var_v0_2;
    s32 var_s3;
    s32 var_v0_1;
    u16 temp_a1;
    Obj *var_s0;
    u32 temp_a0;
    u8 temp_v1_1;
    ObjState *temp_a0_2;
    ObjState *temp_a0_3;
    ObjState *temp_v1_3;
    s16 nb_objs;

    temp_v0 = hasGuetteurABomb(obj, param_2);
    if (((s16) temp_v0 != -1))
    {
        
        i = 0;
        cur_obj = &level.objects[i];
        nb_objs = level.nb_objects;
        while (i < nb_objs)
        {
            if (cur_obj->type == 0x4E)
            {
                temp_a0 = cur_obj->flags;
                if (!(temp_a0 & 0x800))
                {
                    if (param_3)
                    {
                        cur_obj->flags = (temp_a0 & ~0x4000) | (obj->flags & 0x4000);
                    }
                    else
                    {
                        cur_obj->flags = (temp_a0 & ~0x4000) | (((((u32) obj->flags >> 0xE) ^ 1) & 1) << 0xE);
                    }
                    cur_obj->speed_y = (s16) param_2;
                    GET_SPRITE_POS(obj, (s16) temp_v0, &sp18, &sp1A, &sp1C, &sp1E);
                    cur_obj->x_pos = (u16) (((u16) sp18 - cur_obj->offset_bx) + ((s32) ((u16) sp1C << 0x10) >> 0x11));
                    temp_a1 = ((u16) sp1A + (u16) sp1E) - cur_obj->offset_by;
                    cur_obj->y_pos = temp_a1;
                    temp_v1_1 = obj->sub_etat;
                    switch (temp_v1_1)
                    {
                    case 2:
                    case 0x12:
                        cur_obj->y_pos = (u16) (cur_obj->y_pos - 1);
                        temp_a0_2 = &cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat];
                        var_s1 = 0x0030;
                        var_s3 = 3;
                        temp_a0_2->anim_speed = (u8) ((temp_a0_2->anim_speed & 0xF) | 0xA0);
                        cur_obj->gravity_value_1 = 0;
                        cur_obj->gravity_value_2 = 0x0A;
                        break;
                    case 5:
                        cur_obj->y_pos = (u16) (temp_a1 + 0x18);
                        temp_a0_3 = &cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat];
                        var_s1 = 0x0020;
                        var_s3 = 3;
                        temp_a0_3->anim_speed = (u8) ((temp_a0_3->anim_speed & 0xF) | 0x20);
                        cur_obj->gravity_value_1 = 0;
                        cur_obj->gravity_value_2 = 0;
                        break;
                    case 0x0D:
                        temp_v1_2 = 8 - myRand(0x0020);
                        temp_v1_2 +=
                            temp_v1_2 >= 0 ?
                                (temp_v1_2 > 0 ? 8 : 0) : -8;
                        temp_v1_3 = &cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat];
                        temp_v1_3->anim_speed = (u8) ((temp_v1_3->anim_speed & 0xF) | 0x20);
                        var_s1 = temp_v1_2;
                        var_s3 = 0;
                        cur_obj->gravity_value_1 = 0;
                        cur_obj->gravity_value_2 = 0;
                        cur_obj->y_pos = (u16) (cur_obj->y_pos - 0x14);
                        break;
                    }
                    if (param_3 == 0)
                    {
                        var_s1 = 0x0010;
                    }
                    if (obj->flags & 0x4000)
                    {
                        cur_obj->speed_x = var_s1;
                    }
                    else
                    {
                        cur_obj->speed_x = (s16) -var_s1;
                    }
                    cur_obj->x_pos = (u16) (cur_obj->x_pos + ((var_s3 & 0xFF) * ashr16(cur_obj->speed_x, 4U)));
                    skipToLabel(cur_obj, ((u32) cur_obj->flags >> 0xE) & 1, 1U);
                    calc_obj_pos(cur_obj);
                    cur_obj->flags |= 0xC00;
                    cur_obj->timer = param_4;
                    cur_obj->flags &= 0xFFFDFFFF;
                    break;
                }
            }
            cur_obj++;
            i++;
        }
    }
}