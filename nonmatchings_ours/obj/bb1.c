#include "obj/bb1.h"

/* still very rough */
/* 5A2A4 8017EAA4 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_COMMAND);*/

/*? CALC_MOV_ON_BLOC(Obj *);
? SET_X_SPEED(Obj *);*/
void set_main_and_sub_etat(Obj *, u8, u8);
/*extern s32 D_801F4438;
extern u8 D_801F4EBD;
extern ? D_801F4EDA;
extern s16 bb1.saved_cmd;
extern ? D_801F4EE2;
extern s16 bb1.sprite6_y;
extern s16 ray.speed_x;*/

extern inline void test_123(Obj *obj)
{
    switch (bb1.speed_x)
    {
    case 2:
        set_main_and_sub_etat(obj, 1U, 1U);
        break;
    case 3:
        set_main_and_sub_etat(obj, 1U, 2U);
        break;
    case 0:
    default:
        set_main_and_sub_etat(obj, 1U, 0U);
        break;
    }
}

void DO_BBMONT2_COMMAND(Obj *obj)
{
    s16 temp_s2;
    s16 temp_s3;
    s32 temp_v0_2;
    s16 temp_v0_3;
    s16 var_v0_2;
    s16 var_v1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v1_2;
    u16 temp_v0_4;
    u16 var_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    BB1Data *test_1;
    s32 test_2;
    s32 test_3;
    u8 test_4;
    u8 test_5;
    u32 test_6;

    temp_s2 = (u16) obj->x_pos + obj->offset_bx;
    temp_s3 = obj->offset_hy + (u16) obj->y_pos + 0x40;
    if ((obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1)) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
    {
        FinAnim = 1;
    }
    else
    {
        FinAnim = 0;
    }
    if (((u8) Phase < 2U) && (obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U) && (ray_zdc_y < (temp_s3 - 0x20)))
    {
        set_main_and_sub_etat(obj, 0U, 0x10U);
        obj->speed_x = 0;
        obj->speed_y = 0;
    }
    
    if (obj->main_etat == 1)
    {
        if (Phase == 0)
        {
            Phase = 1;
        }
        SET_X_SPEED(obj);
        if ((u8) Phase < 4U)
        {
            CALC_MOV_ON_BLOC(obj);
        }
        if ((FinAnim != 0) && (bb1.speed_x != (obj->sub_etat + 1)))
        {
            test_123(obj);
        }
    }
    if ((bb1.field1_0x2 < 8) && (Phase != 0) && (Phase != 5))
    {
        if (scroll_end_x == xmapmax)
        {
            scroll_end_x = xmap;
            if (xmap < temp_s2)
            {
                scroll_end_x = temp_s2;
            }
        }
        else if (scroll_end_x < temp_s2)
        {
            bb1.saved_cmd = 1;
        }
        if (bb1.saved_cmd != 0)
        {
            if (obj->main_etat == 1)
            {
                scroll_end_x = (u16) scroll_end_x + (obj->sub_etat + 1);
            }
            else
            {
                scroll_end_x = scroll_end_x + (u16) obj->speed_x;
            }
        }
    }
    else
    {
        scroll_end_x = xmapmax;
    }
    switch (Phase)
    {
    case 0:
        /* gotos-only does not fix this case */
        temp_v0 = ((u8) block_flags[obj->btypes[0]] >> 1) & 1;
        var_a0 = 0x28;
        if ((temp_v0 == 0) && (var_a0 = 0x3C, (temp_v0 == 0)))
        {
            if (((temp_s2 + var_a0) < ray_zdc_x) && (obj->main_etat == 0) && (bb1.speed_x != 0))
            {
                obj->flags |= 0x4000;
                set_main_and_sub_etat(obj, 2U, 1U);
                obj->speed_y = 2;
                return;
            }
        }
        else if ((obj->main_etat == 0) && (obj->sub_etat == 0) && ((var_a0 + temp_s2) < ray_zdc_x))
        {
            Phase = 1;
            test_123(obj);
        }
        break;
    case 1:
        if (
            (obj->main_etat == 1) &&
            !(block_flags [
                (u16) mp.map [
                    (s16) (((obj->x_pos + obj->offset_bx) >> 4) + mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                ] >> 10
            ] >> 1 & 1)
        ) {
            set_main_and_sub_etat(obj, 2U, 4U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = -8;
            obj->speed_x = 3;
        }
        break;
    case 2:
        if (
            (obj->main_etat == 1) &&
            !(block_flags [
                (u16) mp.map [
                    (s16) (((obj->x_pos + (obj->offset_bx - 8)) >> 4) + mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                ] >> 10
            ] >> 1 & 1)
        ) {
            set_main_and_sub_etat(obj, 2U, 1U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = 0;
            obj->speed_x = 0;
            bb1.field1_0x2 = -1;
        }
        break;
    case 3:
        scroll_end_x = MAX_1(scroll_end_x, 0x15cc);
        
        if (((temp_s2 + 0x20) < ray_zdc_x) && (bb1.field1_0x2 == -1) && (temp_s3 < ray_zdc_y))
        {
            if (bb1.speed_x != -1)
            {
                test_123(obj);
                bb1.field1_0x2 = 0;
            }
            else
            {
                if (obj->field23_0x3c < 0xC8)
                {
                    if (++obj->field23_0x3c == 0x00C8)
                    {
                        bb1.speed_x = 1;
                        set_main_and_sub_etat(obj, 1U, 0U);
                        bb1.field1_0x2 = 0;
                        obj->field23_0x3c = 0x00FF;
                    }
                }
                scroll_end_x = xmap;
                if (scroll_end_x < temp_s2)
                {
                    test_2 = ray.speed_x;
                    if (test_2 < 1)
                        test_2 = 1;
                    scroll_end_x = scroll_end_x + test_2;
                }
            }
        }
        if (FinAnim != 0)
        {
            if ((obj->main_etat == 0) && (obj->sub_etat == 0x10))
            {
                test_123(obj);
            }
            if ((FinAnim != 0) && (obj->main_etat == 0) && (obj->sub_etat == 1))
            {
                test_123(obj);
            }
        }
        if (obj->main_etat == 1)
        {
            if (
                !(block_flags [
                    (u16) mp.map [
                        (s16) (((obj->x_pos + (obj->offset_bx - 8)) >> 4) + mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                    ] >> 10
                ] >> 1 & 1)
            ) {
                obj->speed_y = -6;
                obj->speed_x = 3;
                set_main_and_sub_etat(obj, 2U, 4U);
                obj->gravity_value_2 = 5;
                obj->gravity_value_1 = 0;
            }
            if ((obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U))
            {
                if (ray_zdc_y < (temp_s3 - 0x20))
                {
                    set_main_and_sub_etat(obj, 0U, 0x10U);
                    obj->speed_y = 0;
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 1U);
                    obj->speed_y = 0;
                }
                obj->speed_x = 0;
            }
        }
        break;
    case 4:
        if (bb1.sprite6_y < scroll_end_y)
        {
            scroll_end_y -= 1;
        }
        if (FinAnim != 0)
        {
            if ((obj->main_etat == 2) && (obj->sub_etat == 2))
            {
                bb1.speed_x = 1;
                set_main_and_sub_etat(obj, 1U, 0U);
            }
            else if ((obj->main_etat == 0) && (obj->sub_etat == 5))
            {
                if (++bb1.sprite6_x < 3)
                {
                    bb1.speed_x = 1;
                    set_main_and_sub_etat(obj, 1U, 0U);
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 2U);
                    Phase = 5;
                    bb1.sprite6_y = ymap;
                }
            }
        }
        if (obj->main_etat == 1)
        {
            if (
                !(block_flags [
                    (u16) mp.map [
                        (s16) (((obj->x_pos + obj->offset_bx + (!(obj->flags & 0x4000) ? -0x10 : 0x10)) >> 4) + mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                    ] >> 10
                ] >> 1 & 1)
            ) {
                obj->speed_y = 0;
                obj->speed_x = 0;
                /* see also: makeUturn() case TYPE_SPIDER_PLAFOND */
                obj->flags = obj->flags & ~0x4000 | (((1 - ((obj->flags >> 0xE) & 1)) & 1) << 0xE);
                set_main_and_sub_etat(obj, 0U, 5U);
            }
        }
        if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0xFB)
            {
                goto block_172;
            }
            return;
        }
        if (((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) >= 0xFB)
        {
block_172:
            obj->flags &= ~0x400;
            IsBossThere = 0;
            Phase = 0;
            scroll_end_x = xmapmax;
            scroll_end_y = ymapmax;
            obj->flags &= ~0x800;
        }
        break;
    case 5:
        if (bb1.field1_0x2 < 0)
        {
            scroll_end_y = bb1.sprite6_y - horloge[5];
            bb1.field1_0x2 = bb1.field1_0x2 + 1;
        }
        if (FinAnim != 0)
        {
            if (obj->main_etat == 0)
            {
                if (obj->sub_etat == 5)
                {
                    do { } while (0); /* TODO: ??? */
                    bb1.speed_x = 3;
                    test_123(obj);
                }
                goto block_147;
            }
        }
        else
        {
block_147:
            if ((obj->main_etat == 0) && (obj->sub_etat == 2))
            {
                if (FinAnim != 0)
                {
                    bb1.speed_x = 2;
                    test_123(obj);
                }
                else
                {
                    /* already knows main_etat and sub_etat ... */
                    if ((obj->anim_frame == 0x15) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
                    {
                        bb1.field1_0x2 = -0x001E;
                    }
                }

            }
        }
        if (obj->main_etat == 1)
        {
            if (
                !(block_flags [
                    (u16) mp.map [
                        (s16) (((obj->x_pos + obj->offset_bx + (!(obj->flags & 0x4000) ? -0x10 : 0x10)) >> 4) + mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                    ] >> 10
                ] >> 1 & 1)
            ) {
                if (bb1.speed_x == 3)
                {
                    set_main_and_sub_etat(obj, 2U, 4U);
                    obj->gravity_value_2 = 0xFF;
                    obj->gravity_value_1 = 0;
                    obj->speed_y = -2;
                    obj->speed_x = 4;
                    scroll_end_y = ymapmax;
                    scroll_end_x = xmapmax;
                }
                else
                {
                    obj->speed_y = 0;
                    obj->speed_x = 0;
                    obj->flags = obj->flags & ~0x4000 | (((1 - ((obj->flags >> 0xE) & 1)) & 1) << 0xE);
                    set_main_and_sub_etat(obj, 0U, 5U);
                }
            }
        }
        if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0x191)
            {
                goto block_173;
            }
            return;
            
        }
        if (((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) >= 0x191)
        {
block_173:
            obj->flags &= ~0x400;
            IsBossThere = 0;
            Phase = 0;
            scroll_end_x = xmapmax;
            scroll_end_y = ymapmax;
            obj->flags &= ~0x800;
        }
        break;
    }
}