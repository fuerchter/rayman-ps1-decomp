#include "obj/hybride_stosko.h"

/*
gotos-only matches
cannot figure out the case(s) that just set obj->timer = 0x32 and return
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/hybride_stosko", doSTOSKOcommand);*/

void doSTOSKOcommand(Obj *obj)
{
    Obj *temp_a2_2;
    s16 var_v0;
    s32 temp_v1;
    u8 temp_a1;
    u8 temp_a2;
    u8 flag_set;
    s32 test_1;

    scrollLocked = 1;
    test_1 = (obj->main_etat << 8) + obj->sub_etat;
    switch (test_1)
    {
    case 0x100:
        if (obj->x_pos <= obj->init_x_pos)
        {
            set_main_and_sub_etat(obj, 0U, 0U);
            set_main_and_sub_etat(&ray, 0U, 0U);
            remoteRayXToReach = -0x7D00;
        }
        else
        {
            remoteRayXToReach = (s16) (u16) scroll_start_x;
            if ((ray.main_etat == 3) && (ray.sub_etat == 0x14))
            {
                ray.flags |= 0x4000;
            }
        }
        SET_X_SPEED(obj);
        return;
    case 0x8:
        obj->speed_x = 0;
        obj->speed_y = -8;
        return;
    case 0x0:
        if ((poing.is_active == 0) && (ray.main_etat != 2))
        {
            if (obj->timer != 0)
            {
                obj->timer--;
                return;
            }
            set_sub_etat(obj, 1U);
            return;
        }
        set_sub_etat(obj, 5U);
        return;
    case 0x1:
        if (poing.is_active != 0)
        {
            var_v0 = ((ray.offset_by + ray.y_pos) - (u16) obj->y_pos) - obj->offset_by;
            if ((__builtin_abs(var_v0) < 0x30) || ((u8) obj->anim_frame >= 0xAU))
            {
                set_sub_etat(obj, 0x0AU);
                obj->anim_index = obj->eta[0][10].anim_index;
                return;
            }
            set_sub_etat(obj, 5U);
            return;
        }

        flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
        if(
            ((flag_set && obj->anim_frame == 0) ||
            (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
        )
        {
                allocateStoskoClaw(obj);
                return;
        }
        break;
    case 0x4:
        obj->timer = 0x32;
    case 0x2:
        temp_a2_2 = &level.objects[obj->field24_0x3e];
        if ((temp_a2_2->speed_x > 0) && (temp_a2_2->x_pos >= obj->x_pos))
        {
            obj->field24_0x3e = -1;
            temp_a2_2->flags &= ~0x400;
            set_sub_etat(obj, 3U);
            
            return;
        }
        break;
    case 3:
    case 7:
        obj->timer = 0x32;
        return;
    case 0xC:
        obj->timer = 0x32;
        return;
    case 0xD:
        obj->timer = 0x32;
        return;
    case 0xB:
        if (poing.is_active == 0)
        {
            set_sub_etat(obj, 0x0CU);
            return;
        }
        break;
    case 0x6:
        if ((ray.main_etat != 2) && (poing.is_active == 0))
        {
            set_sub_etat(obj, 7U);
        }
        break;
    }
}

void doSTOSKOcommand(Obj *obj)
{
    Obj *temp_a2_2;
    s16 var_v0;
    s32 temp_v1;
    u8 temp_a1;
    u8 temp_a2;
    u8 flag_set;

    scrollLocked = 1;
    temp_v1 = (obj->main_etat << 8) + obj->sub_etat;
    if (temp_v1 == 6)
    {
        goto block_52;
    }
    if (temp_v1 >= 7)
    {
        goto block_10;
    }
    if (temp_v1 == 2)
    {
        goto block_45;
    }
    if (temp_v1 >= 3)
    {
        goto block_7;
    }
    if (temp_v1 == 0)
    {
        goto block_25;
    }
    if (temp_v1 == 1)
    {
        goto block_30;
    }
    return;
block_7:
    if (temp_v1 == 4)
    {
        goto block_44;
    }
    if (temp_v1 >= 5)
    {
        goto block_55;
    }
    goto block_49;
block_10:
    if (temp_v1 == 0xB)
    {
        goto block_50;
    }
    if (temp_v1 >= 0xC)
    {
        goto block_15;
    }
    if (temp_v1 == 8)
    {
        goto block_24;
    }
    if (temp_v1 < 8)
    {
        goto block_49;
    }
    return;
block_15:
    if (temp_v1 == 0xD)
    {
        goto block_48;
    }
    if (temp_v1 < 0xD)
    {
        goto block_49;
    }
    if (temp_v1 != 0x100)
    {
        goto block_55;
    }
    if (obj->x_pos <= obj->init_x_pos)
    {
        set_main_and_sub_etat(obj, 0U, 0U);
        set_main_and_sub_etat(&ray, 0U, 0U);
        remoteRayXToReach = -0x7D00;
    }
    else
    {
        remoteRayXToReach = (s16) (u16) scroll_start_x;
        if ((ray.main_etat == 3) && (ray.sub_etat == 0x14))
        {
            ray.flags |= 0x4000;
        }
    }
    SET_X_SPEED(obj);
    return;
block_24:
    obj->speed_x = 0;
    obj->speed_y = -8;
    return;
block_25:
    if ((poing.is_active == 0) && (ray.main_etat != 2))
    {
        if (obj->timer != 0)
        {
            obj->timer--;
            return;
        }
        set_sub_etat(obj, 1U);
        return;
    }
    set_sub_etat(obj, 5U);
    return;
block_30:
    if (poing.is_active != 0)
    {
        var_v0 = ((ray.offset_by + ray.y_pos) - (u16) obj->y_pos) - obj->offset_by;
        if ((__builtin_abs(var_v0) < 0x30) || ((u8) obj->anim_frame >= 0xAU))
        {
            set_sub_etat(obj, 0x0AU);
            obj->anim_index = obj->eta[0][10].anim_index;
            return;
        }
        set_sub_etat(obj, 5U);
        return;
    }

    flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
    if(
        ((flag_set && obj->anim_frame == 0) ||
        (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
    )
    {
            allocateStoskoClaw(obj);
            return;
    }
    return;
block_44:
    obj->timer = 0x32;
block_45:
    temp_a2_2 = &level.objects[obj->field24_0x3e];
    if ((temp_a2_2->speed_x > 0) && (temp_a2_2->x_pos >= obj->x_pos))
    {
        obj->field24_0x3e = -1;
        temp_a2_2->flags &= ~0x400;
        set_sub_etat(obj, 3U);
        
        return;
    }
    return;
block_48:
block_49:
    /* TODO: case??? it's not default */
    obj->timer = 0x32;
    return;
block_50:
    if (poing.is_active == 0)
    {
        set_sub_etat(obj, 0x0CU);
        return;
    }
    return;
block_52:
    if ((ray.main_etat != 2) && (poing.is_active == 0))
    {
        set_sub_etat(obj, 7U);
    }
block_55:
    return;
}