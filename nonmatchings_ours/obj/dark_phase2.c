#include "obj/dark_phase2.h"

/*
attempts: 2
matches, but goto, sgn-like (not on android) garbage
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_SORT_COMMAND);*/

void DO_DARK2_SORT_COMMAND(Obj *ds2_obj)
{
    s16 unk_1;
    s32 unk_x_1;
    s16 unk_y_1;
    s16 unk_y_2;
    s16 unk_4;
    s16 unk_x_2;
    s32 unk_2;
    s16 unk_3;

    if (ds2_obj->hit_points != 0)
    {
        if (ds2_obj->sub_etat == 35 || ds2_obj->sub_etat == 36)
        {
            if (ds2_obj->x_pos < -ds2_obj->offset_bx)
            {
                sinus_actif = 2;
                ds2_obj->hit_points = 0;
            }
            else
            {
                if (ds2_obj->iframes_timer != 0)
                {
                    if (sens_sinus_1 != 0)
                    {
                        dark2_rayon_dy_1 += 3;
                        if (dark2_rayon_dy_1 > 76)
                            sens_sinus_1 = 0;
                    }
                    else
                    {
                        dark2_rayon_dy_1 -= 3;
                        if (dark2_rayon_dy_1 < -76)
                            sens_sinus_1 = 1;
                    }
                    PosXSin1 += ashr16(dark2_rayon_dx_1, 4);
                    unk_y_1 = PosYSin1 + ashr16(dark2_rayon_dy_1, 4);
                    PosYSin1 = unk_y_1;
                    if (ds2_obj->anim_frame == 1)
                    {
                        unk_x_1 = PosXSin1;
    block_1:
                        allocate_DARK2_SORT(unk_x_1, unk_y_1, ds2_obj->sub_etat, ds2_obj->iframes_timer);
                        ds2_obj->hit_points = 0;
                    }
                }
                else
                {
                    if (sens_sinus_2 != 0)
                    {
                        dark2_rayon_dy_2 += 3;
                        if (dark2_rayon_dy_2 > 76)
                            sens_sinus_2 = 0;
                    }
                    else
                    {
                        dark2_rayon_dy_2 -= 3;
                        if (dark2_rayon_dy_2 < -76)
                            sens_sinus_2 = 1;
                    }
                    PosXSin2 += ashr16(dark2_rayon_dx_2, 4);
                    unk_y_1 = PosYSin2 + ashr16(dark2_rayon_dy_2, 4);
                    PosYSin2 = unk_y_1;
                    if (ds2_obj->anim_frame == 1)
                    {
                        unk_x_1 = PosXSin2;
    goto block_1;
                    }
                }
            }
        }
        else if (ds2_obj->sub_etat == 37)
        {
            if (ds2_obj->iframes_timer != 0)
                unk_x_2 = 240 - (ds2_obj->x_pos + ds2_obj->offset_bx);
            else
                unk_x_2 = 5 - (ds2_obj->x_pos + ds2_obj->offset_bx);
            unk_y_2 = firstFloorBelow(ds2_obj) - (ds2_obj->y_pos + ds2_obj->offset_by);
            unk_1 = __builtin_abs(unk_x_2) + __builtin_abs(unk_y_2);

            if (unk_1 < 10)
            {
                ds2_obj->hit_points = 0;
                AllocateFlammes(ds2_obj->iframes_timer);
            }
            else
            {
                if (unk_1 > 0)
                {
                    unk_x_2 = ashl16(unk_x_2, 4) / unk_1;
                    unk_y_2 = ashl16(unk_y_2, 4) / unk_1;
                }

                if (ds2_obj->anim_frame == 1)
                {
                    if (ds2_obj->iframes_timer != 0)
                    {
                        dark2_rayon_dx_1 += SGN(unk_x_2 - dark2_rayon_dx_1);
                        dark2_rayon_dy_1 += SGN(unk_y_2 - dark2_rayon_dy_1);
                        
                        allocate_DARK2_SORT(
                            ds2_obj->x_pos + dark2_rayon_dx_1,
                            ds2_obj->y_pos + dark2_rayon_dy_1,
                            ds2_obj->sub_etat,
                            ds2_obj->iframes_timer
                        );
                        ds2_obj->hit_points = 0;
                    }
                    else
                    {
                        dark2_rayon_dx_2 += SGN(unk_x_2 - dark2_rayon_dx_2);
                        dark2_rayon_dy_2 += SGN(unk_y_2 - dark2_rayon_dy_2);

                        allocate_DARK2_SORT(
                            ds2_obj->x_pos + dark2_rayon_dx_2,
                            ds2_obj->y_pos + dark2_rayon_dy_2,
                            ds2_obj->sub_etat,
                            ds2_obj->iframes_timer
                        );
                        ds2_obj->hit_points = 0;
                    }
                }
            }
        }
    }
}

/*
score of ???
attempts: 3
looked at android
looked at allocate_DARK_SORT
*/
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", allocate_DARK2_SORT);*/

void allocate_DARK2_SORT(s32 param_1, s16 param_2, s16 param_3, s16 param_4)
{
    Obj *temp_t6;
    Obj *cur_obj_1;
    Obj *cur_obj_2;
    Obj *cur_obj_3;
    Obj *var_a0_4;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 cnt_1;
    s16 check_1;
    s32 check_2;
    s32 check_3;
    Obj *var_v1_1;
    Obj *var_v1_2;
    Obj *var_v1_3;
    s16 nb_objs;
    int new_var;

    check_1 = 0;
    cnt_1 = 0;
    cur_obj_1 = level.objects;
    nb_objs = level.nb_objects;
    do
    {
        if ((cur_obj_1->type == 0x21) && !(cur_obj_1->flags & 0x800))
        {
            check_1 = 1;
        }
        cur_obj_1 += 1;
        cnt_1 = cnt_1 + 1;
    } while ((check_1 == 0) && (cnt_1 < nb_objs));
    cur_obj_1 = cur_obj_1 - 1;
    
    if (check_1 == 0)
        return;
    
    temp_t6 = cur_obj_1;
    check_1 = 0;
    do
    {
        if ((cur_obj_1->type == 0x21) && (cur_obj_1->flags & 0x800))
        {
            check_1 = 1;
        }
        cur_obj_1 += 1;
        cnt_1 = cnt_1 + 1;
    } while ((check_1 == 0) && (cnt_1 < nb_objs));
    cur_obj_1 = cur_obj_1 - 1;

    if (check_1 == 0)
    {
        check_1 = 1;
        cur_obj_1 = temp_t6;
    }
    else
    {
        check_1 = 0;
        do
        {
            if ((cur_obj_1->type == 0x21) && !(cur_obj_1->flags & 0x800))
            {
                check_1 = 1;
            }
            cur_obj_1 += 1;
            cnt_1 = cnt_1 + 1;
        } while ((check_1 == 0) && (cnt_1 < nb_objs));
        cur_obj_1 = cur_obj_1 - 1;
        if (check_1 == 0)
        {
            check_1 = 1;
            cur_obj_1 = temp_t6;
        }
    }

    if (check_1 == 0)
        return;
    
    cur_obj_1->x_pos = param_1;
    cur_obj_1->y_pos = param_2;
    cur_obj_1->hit_points = 1;
    cur_obj_1->iframes_timer = param_4;
    cur_obj_1->field23_0x3c = 0;
    cur_obj_1->flags |= 0xC00;
    set_main_and_sub_etat(cur_obj_1, 0, param_3);
}