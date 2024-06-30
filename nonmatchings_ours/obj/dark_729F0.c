#include "obj/dark_729F0.h"

/* matches, but cursed */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_vitraux);*/

void init_vitraux(void)
{
    u8 bVar1;
    s16 sVar2;
    s32 boss_index_2;
    Obj *cur_obj;
    u8 boss_index_1;
    u8 i;
    s16 nb_objs;

    cur_obj = &level.objects[0];
    nb_objs = level.nb_objects;

    boss_index_1 = 0;
    i = 0;

    while (i < nb_objs)
    {
        boss_index_2 = boss_index_1;
        if (boss_index_1 > 4)
            return;
        
        if (cur_obj->type == TYPE_VITRAIL)
        {
            VitrauxInfos[boss_index_2].obj_id = i;
            VitrauxInfos[boss_index_2].x_pos = cur_obj->offset_bx + cur_obj->x_pos;
            bVar1 = cur_obj->offset_by;
            sVar2 = cur_obj->y_pos;
            VitrauxInfos[boss_index_2].index = boss_index_1;
            VitrauxInfos[boss_index_2].y_pos = bVar1;
            VitrauxInfos[boss_index_2].y_pos += sVar2;
            VitrauxInfos[boss_index_1].field4_0x6 = 0;
            VitrauxInfos[boss_index_1].mode = 0;
            VitrauxInfos[boss_index_1].value = 0;
            cur_obj->field23_0x3c = boss_index_1;
            boss_index_1++;
        }
        i++;
        cur_obj++;
    }
}

/* matches, but cursed */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", poing_face_obj);*/

s32 poing_face_obj(Obj *obj)
{
    Obj *temp_v0;
    s32 temp_a2;
    s32 var_a3;

    temp_v0 = &level.objects[poing_obj_id];
    var_a3 = 0;
    temp_a2 = temp_v0->flags >> 0xE;
    temp_a2 &= 1;
    if (((obj->x_pos + obj->offset_bx) - (temp_v0->x_pos + temp_v0->offset_bx)) > 0)
    {
        if (temp_a2 == 1)
        {
            goto block_4;
        }
    }
    else if (temp_a2 == 0)
    {
block_4:
        var_a3 = 1;
    }
    return var_a3;
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase1);*/

void DARK_phase1(Obj *obj)
{
    Obj *temp_s1;
    Obj *var_s2;
    s16 temp_a0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 var_a1;
    s32 var_v0;
    s16 var_v1;
    s32 temp_a1_1;
    s32 var_a2;
    u32 temp_a1_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 flag_set;

    /*var_s2 = saved_reg_s2;*/
    if ((corde_dark_obj_id != -1) && (obj->main_etat == 0))
    {
        temp_s1 = &level.objects[corde_dark_obj_id];
        if (poing_obj_id != -1)
        {
            var_s2 = &level.objects[poing_obj_id];
            set_main_and_sub_etat(var_s2, 5U, 0x40U);
            var_s2->x_pos = (temp_s1->offset_bx + (u16) temp_s1->x_pos) - var_s2->offset_bx;
            var_s2->y_pos = ((temp_s1->offset_by + (u16) temp_s1->y_pos) - var_s2->offset_by) - 5;
            var_s2->flags |= 0xC00;
        }
        temp_v0 = obj->sub_etat;
        switch (temp_v0)
        {
        case 40:
            flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
            if(
                ((flag_set && obj->anim_frame == 0) ||
                (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
            )
            {
                    goto_phase2(obj);
                    return;
            }
            break;
        case 27:
            temp_s1->y_pos = temp_s1->y_pos - 8;
            if (temp_s1->y_pos < corde_y_haut)
            {
                temp_s1->y_pos = corde_y_haut;
            }
            if (poing_obj_id != -1)
            {
                var_s2->y_pos = ((temp_s1->offset_by + (u16) temp_s1->y_pos) - var_s2->offset_by) - 5;
            }
            
            flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
            if(
                ((flag_set && obj->anim_frame == 0) ||
                (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
            )
            {

                    temp_s1->field23_0x3c--;
                    if ((temp_s1->field23_0x3c) == 0)
                    {
                        set_main_and_sub_etat(obj, 0U, 0x28U);
                        return;
                    }
                    temp_s1->iframes_timer = 0;
                    set_main_and_sub_etat(obj, 0U, 0x1CU);
                    return;
            }
            break;
        case 29:
            temp_s1->y_pos = temp_s1->y_pos + 6;
            if (temp_s1->y_pos > corde_y_bas)
            {
                temp_s1->y_pos = corde_y_bas;
            }
            if (poing_obj_id != -1)
            {
                var_s2->y_pos = ((temp_s1->offset_by + (u16) temp_s1->y_pos) - var_s2->offset_by) - 5;
            }
            
            flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
            if(
                ((flag_set && obj->anim_frame == 0) ||
                (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
            )
            {
                temp_s1->iframes_timer = 0;
                set_main_and_sub_etat(obj, 0U, 0x1AU);
                return;
            }

            if (ray.main_etat == 2)
            {
block_53:
                set_main_and_sub_etat(obj, 0U, 0x1BU);
                return;
            }
            break;
        case 26:
        case 28:
            var_v1 = (ray.offset_bx + ray.x_pos) - (temp_s1->offset_bx + (u16) corde_x);
            temp_a0 = (ray.offset_by + ray.y_pos) - (temp_s1->offset_by + (u16) corde_y_bas);
            temp_a1_1 = var_v1 * var_v1;

            var_a2 = 0;
            temp_a1_2 = temp_a1_1 + (temp_a0 * temp_a0);
            if ((__builtin_abs(var_v1) < 0x28) || (temp_a1_2 < 0xBB8U))
            {
                var_a2 = 1;
            }
            temp_v1 = obj->sub_etat;
            switch (temp_v1)
            {
            case 26:
                if (!(!(var_a2 & 0xFF) && ((ray.main_etat != 2) || (ray.sub_etat != 0))))
                {
                    set_main_and_sub_etat(obj, 0U, 0x1BU);
                    return;
                }
                else
                {
                    if (ray.eta[ray.main_etat][ray.sub_etat].flags & 0x40)
                    {
                        if ((__builtin_abs(temp_a0) < 0x1E) && (temp_a1_2 < 0xBB8U))
                        {
                            set_main_and_sub_etat(obj, 0U, 0x1BU);
                            return;
                        }
                        goto block_54;
                    }
block_54:
                    if (temp_s1->iframes_timer < 0x1D)
                    {
                        var_a1 = (u16) corde_y_bas - (u16) oscille[temp_s1->iframes_timer];
                        temp_s1->y_pos = var_a1;
                        if (poing_obj_id != -1)
                        {
                            var_s2->y_pos = ((temp_s1->offset_by + var_a1) - var_s2->offset_by) - 5;
                        }
                        temp_s1->iframes_timer = (u16) temp_s1->iframes_timer + 1;
                    }
                }
                break;
            case 28:
                if (!(var_a2 & 0xFF) && (ray.main_etat != 2))
                {
                    set_main_and_sub_etat(obj, 0U, 0x1DU);
                    return;
                }
                temp_v1_3 = temp_s1->iframes_timer;
                if (temp_v1_3 < 0x1D)
                {
                    var_a1 = (u16) corde_y_haut + (u16) oscille[temp_v1_3];
                    temp_s1->y_pos = var_a1;
                    if (poing_obj_id != -1)
                    {
                        var_s2->y_pos = ((temp_s1->offset_by + var_a1) - var_s2->offset_by) - 5;
                    }
                    temp_s1->iframes_timer = (u16) temp_s1->iframes_timer + 1;
                }
                break;
            }
            break;
        }
    }
}