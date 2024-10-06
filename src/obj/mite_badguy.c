#include "obj/mite_badguy.h"

INCLUDE_ASM("asm/nonmatchings/obj/mite_badguy", calc_esquive_poing);

/* 3C7F4 80160FF4 -O2 -msoft-float */
void DO_PTI_ESQUIVE(Obj *bg3_obj)
{
    s16 diff_x; s16 diff_y; s16 unk_1;
    Obj *poing_obj;
    u8 label;

    DO_ONE_CMD(bg3_obj);
    if (poing.is_active || poing.is_charging)
    {
        poing_obj = &level.objects[poing_obj_id];
        calc_esquive_poing(bg3_obj, &diff_x, &diff_y, &unk_1);
        if (__builtin_abs(diff_x) <= unk_1 && diff_y < 15)
        {
            if (
                (
                    (bg3_obj->main_etat == 0 && (bg3_obj->sub_etat == 0 || bg3_obj->sub_etat == 2)) ||
                    bg3_obj->main_etat == 1
                ) && (poing_obj->flags & FLG(OBJ_FLIP_X)) != (bg3_obj->flags & FLG(OBJ_FLIP_X))
            )
            {
                bg3_obj->speed_x = 0;
                bg3_obj->speed_y = 0;
                set_main_and_sub_etat(bg3_obj, 0, 15);
                bg3_obj->flags &= ~FLG(OBJ_READ_CMDS);
                
                if (bg3_obj->flags & FLG(OBJ_FLIP_X))
                    label = 3;
                else
                    label = 2;
                skipToLabel(bg3_obj, label, true);
                
            }
            return; /* TODO: different control flow?? */
        }
    }

    if (bg3_obj->main_etat == 0 && bg3_obj->sub_etat == 16)
        set_sub_etat(bg3_obj, 17);
}

/* 3C96C 8016116C -O2 -msoft-float */
void DO_MITE2_ESQUIVE(Obj *mit2_obj)
{
    Obj *poing_obj;
    s16 diff_x; s16 diff_y; s16 unk_1;

    if (poing.is_active || poing.is_charging)
    {
        poing_obj = &level.objects[poing_obj_id];
        calc_esquive_poing(mit2_obj, &diff_x, &diff_y, &unk_1);
        if (
            __builtin_abs(diff_x) <= unk_1 && diff_y < 35 &&
            mit2_obj->main_etat == 1 &&
            (
                (!(mit2_obj->flags & FLG(OBJ_FLIP_X)) && diff_x < 0) ||
                (mit2_obj->flags & FLG(OBJ_FLIP_X) && diff_x > 0)
            ) &&
            SGN(mit2_obj->speed_x) == -SGN(poing_obj->speed_x)
        )
        {
            mit2_obj->speed_x = 0;
            mit2_obj->speed_y = 0;
            if (ray.main_etat != 2)
                mit2_obj->field20_0x36 = 0x01F5;
            else
            {
                if (mit2_obj->eta[mit2_obj->main_etat][mit2_obj->sub_etat].flags & 4)
                {
                    set_main_and_sub_etat(mit2_obj, 0, 9);
                    skipToLabel(mit2_obj, 7, true);
                }
            }
        }
    }
    else
    {
        if (mit2_obj->main_etat == 0 && mit2_obj->sub_etat == 10)
        {
            mit2_obj->field20_0x36 = 0;
            set_sub_etat(mit2_obj, 12);
            skipToLabel(mit2_obj, 8, true);
        }
    }
}