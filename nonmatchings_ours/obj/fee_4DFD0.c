#include "obj/fee_4DFD0.h"

/* 
replacing some obj->field56_0x69 = 0; with new_var improves score.
adding it at end of case 4 does so as well. not been successful with gotos
gotos-only version has same issue
*/
/* 4E2D0 80172AD0 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/fee_4DFD0", DO_FEE);*/

/*? DO_FEE_ETAPE(void *);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(void *, ?);
? skipToLabel(void *, ?, ?);*/
/*extern ? D_801E4F92;*/
extern s8 D_801F61F5;
/*extern ? D_801F61F6;*/
extern s32 D_801F620C;
extern u8 new_txt_fee;
extern s8 ray_in_fee_zone;
extern s16 remoteRayXToReach;

void DO_FEE(Obj *obj)
{
    Obj *temp_s1;
    s16 temp_v0;
    s16 temp_v0_2;
    s32 temp_a0;
    s32 var_v0;
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_v1;
    Obj *new_var;
    u8 new_var3;
    u8 test;
    int new_var2;
    u8 new_var4;
    s16 new_var5;

    temp_s4 = display_txt_fee;
    temp_v1 = obj->sub_etat;
    temp_s1 = &level.objects[png_or_fee_id];
    
    switch (temp_v1)
    {
    case 0:
        if (obj->detect_zone_flag != 0)
        {
            var_v0 = ((ray.x_pos + ray.offset_bx) - obj->x_pos) + 2;
            temp_s3 = 0x15;
            if (var_v0 < 0)
            {
                var_v0 = -var_v0;
            }
            if ((var_v0 < 3) && (((new_var4 = (u8) ray.main_etat) < 2U) || ((ray.main_etat == 3) && ((ray.sub_etat == 0x14) || (ray.sub_etat == temp_s3)))))
            {
                set_sub_etat(obj, 1);
                skipToLabel(obj, 0, 1);
                set_main_and_sub_etat(&ray, 3, 0x22);
                remoteRayXToReach = -0x7D00;
                ray.flags |= 0x4000;
            }
            
            obj->field56_0x69 = 0;
        }
        else
        {
            ray_in_fee_zone = 0;
            obj->field56_0x69 = 0;
        }
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
        new_var3 = ray.main_etat;
        if (((u8) new_var3) >= 2U)
        {
            if (ray.main_etat == 3)
            {
                if (ray.sub_etat == 0x22)
                {
                    set_main_and_sub_etat(&ray, 3, 0x23);
                }
                goto block_18;
            }
        }
        else
        {
            set_main_and_sub_etat(&ray, 3, 0x23);
block_18:
            if ((ray.main_etat == 3) && (ray.sub_etat == 0x24))
            {
                ray.anim_frame = -1;
            }
        }
        break;
    case 4:
        if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10)
        {
            if (obj->anim_frame != 0)
            {
                obj->field56_0x69 = 0;
            }
            else
            {
                goto block_25;
            }
        }
        else if (obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1))
        {
block_25:
            if (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0)
            {
                fee_gives_super_evts();
                obj->field56_0x69 = 2;
                display_txt_fee = 5;
                obj->timer = 0;
            }
            else
            {
                obj->field56_0x69 = 0;
            }
        }
        else
        {
            obj->field56_0x69 = 0;
        }
        break;
    case 6:
        if (ray.main_etat == 3) {
            if (ray.sub_etat == 0x24) {
                set_sub_etat(&ray,0x25);
            }
            if (((ray.main_etat == 3) && (ray.sub_etat == 0x14)) &&
                (remoteRayXToReach = ray.x_pos, obj->field56_0x69 == 4)) {
                set_main_and_sub_etat(&ray,0,0);
                remoteRayXToReach = -32000;
            }
        }
        break;
    }
    DO_FEE_ETAPE(obj);
    if (display_txt_fee != temp_s4)
    {
        new_txt_fee = 1;
        if (display_txt_fee != 0xFF)
        {
            temp_s1->active_timer = 0;
            temp_s1->flags |= 0x4400;
            
            temp_s1->x_pos = (u16) xmap - temp_s1->offset_bx;
            temp_v0 = ((u16) ymap) - (temp_s1->offset_by - 0xDC);        
            temp_s1->y_pos = temp_v0;
            new_var3 = temp_s1->offset_bx;
            new_var5 = (s16) new_var3;
            new_var2 = 0xDC - temp_s1->offset_by;
            old_txt_fee = temp_s4;
            temp_s1->screen_x_pos = -new_var5;
            temp_s1->screen_y_pos = new_var2;
            temp_s1->init_x_pos = (s16) (u16) temp_s1->x_pos;
            temp_s1->init_y_pos = (s16) (u16) temp_s1->y_pos;
        }
    }
    if (new_txt_fee != 0)
    {
        temp_a0 = old_txt_fee << 6;
        /*temp_v0 = *(&D_801E4F92 + temp_a0);*/
        if (text_to_display[old_txt_fee].y_pos < 0x104)
        {
            text_to_display[old_txt_fee].y_pos = text_to_display[old_txt_fee].y_pos + 1;
        }
        else
        {
            new_txt_fee = 0;
        }
    }
    if (temp_s1->flags & 0x400)
    {
        temp_s1->x_pos = (u16) temp_s1->x_pos + 4;
        temp_v0_2 = (u16) temp_s1->screen_x_pos + 4;
        temp_s1->screen_x_pos = temp_v0_2;
        if (temp_v0_2 >= 0x137)
        {
            temp_s1->anim_frame = 0;
            temp_s1->flags &= ~0x400;
            temp_s1->flags &= ~0x800;
        }
    }
}