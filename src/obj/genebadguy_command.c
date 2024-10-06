#include "obj/genebadguy_command.h"

void allocate_badguy(Obj *param_1, u8 param_2, s16 param_3, s32 param_4);

/* 4A5BC 8016EDBC -O2 -msoft-float */
void DO_TEN_COMMAND(Obj *obj)
{
    u8 i;
    s16 unk_1;
    u8 unk_2;

    if (obj->cmd == GO_LEFT)
        obj->flags &= ~FLG(OBJ_FLIP_X);
    else if (obj->cmd == GO_RIGHT)
        obj->flags |= FLG(OBJ_FLIP_X);

    if (obj->main_etat == 0 && obj->sub_etat == 11)
    {
        if (obj->anim_frame >= 5 && obj->timer == 0)
        {
            obj->timer++;
            if (++obj->field56_0x69 > 2)
                obj->field56_0x69 = 1;
            
            if (obj->hit_points != 1)
                allocate_badguy(obj, obj->field56_0x69, 1, -1);
            else
            {
                allocate_badguy(obj, 2U, 1, -2);
                allocate_badguy(obj, 1, 2, -1);
            }
        }
        else if (obj->anim_frame < 2)
            obj->timer = 0;
    }
    else if (obj->main_etat == 0 && obj->sub_etat == 21)
    {
        if (obj->anim_frame >= 5 && obj->timer == 0)
        {
            unk_1 = -4;
            i = 0;
            obj->timer++;
            while (i < 4)
            {
                unk_2 = (i & 1) + 1;
                allocate_badguy(obj, 3 - unk_2, unk_1, -unk_2);

                unk_1++;
                if (unk_1 == -2)
                    unk_1 = 3;
                i++;
            }
        }
        else if (obj->anim_frame < 2)
            obj->timer = 0;
    }
    else if (obj->main_etat == 0 && obj->sub_etat == 3)
    {
        obj->timer++;
        if (obj->field56_0x69 != 3 && obj->timer > 252)
            obj->field56_0x69 = 3;
        
        obj->speed_x = 0;
        obj->speed_y = 0;
        if (obj->anim_frame > 12)
            obj->anim_frame = 3;
        else if (obj->anim_frame < 2)
            obj->timer = 0;
    }
    else if (obj->main_etat == 1)
    {
        if (obj->field24_0x3e != 0)
            obj->timer++;
        
        if (obj->timer > 253)
            skipToLabel(obj, 2, true);
        
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
    }
}
