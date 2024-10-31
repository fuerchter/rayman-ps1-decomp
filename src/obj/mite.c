#include "obj/mite.h"

/* 4A85C 8016F05C -O2 -msoft-float */
void mite_esquive_poing(Obj *mit_obj, s16 *out_diff_x)
{
    s16 unk_x_1; s16 unk_y_1;
    s16 unk_y_2;    
    Obj *poing_obj = &level.objects[poing_obj_id];
    
    if (!(poing_obj->flags & FLG(OBJ_ACTIVE)))
    {
        unk_x_1 = ray.x_pos + ray.offset_bx;
        unk_y_1 = ray.y_pos + ((ray.offset_by + ray.offset_hy) >> 1) - 10;
        poing_obj->speed_x = 0;
        poing_obj->speed_y = 0;
    }
    else
    {
        unk_x_1 = poing_obj->x_pos + poing_obj->offset_bx;
        unk_y_1 = poing_obj->y_pos + ((poing_obj->offset_by + poing_obj->offset_hy) >> 1) - 3;
    }
    unk_y_2 = mit_obj->y_pos + ((mit_obj->offset_hy + mit_obj->offset_by) >> 1) - unk_y_1;
    *out_diff_x = unk_x_1 - mit_obj->x_pos - mit_obj->offset_bx;
    
    if (unk_y_2 < 0)
    {
        if (poing_obj->speed_y > 0)
        {
            if (unk_y_2 > -30)
                mit_obj->speed_y += 2;
            else if (unk_y_2 > -48)
                mit_obj->speed_y += 1;
        }
        else
        {
            if (unk_y_2 > -30)
                mit_obj->speed_y -= 2;
            else if (unk_y_2 > -48)
                mit_obj->speed_y -= 1;
        }
    }
    else
    {
        if (poing_obj->speed_y >= 0)
        {
            if (unk_y_2 < 30)
                mit_obj->speed_y += 2;
            else if (unk_y_2 < 48)
                mit_obj->speed_y += 1;
        }
        else
        {
            if (unk_y_2 < 30)
                mit_obj->speed_y -= 2;
            else if (unk_y_2 < 48)
                mit_obj->speed_y -= 1;
        }
    }
}

/* 4AA1C 8016F21C -O2 -msoft-float */
u8 HAS_MIT_JUMP(Obj *obj)
{
    u8 res = false;
    
    if (obj->main_etat != 2)
    {
        if (obj->eta[obj->main_etat][obj->sub_etat].flags & 1)
            skipToLabel(obj, 1, true);
    }
    else
    {
        if (obj->sub_etat == 1 && obj->anim_frame == 0)
        {
            obj->speed_y = -5;
            obj->gravity_value_1 = 0;
            obj->gravity_value_2 = 0;
            obj->y_pos -= 14;
        }
        else
            res = true;
    }

    return res;
}

/* 4AACC 8016F2CC -O2 -msoft-float */
u8 ray_over_mit(Obj *obj, s16 param_2)
{
    return
        (!(obj->flags & FLG(OBJ_FLIP_X)) && param_2 > 0) ||
        (obj->flags & FLG(OBJ_FLIP_X) && param_2 < 0);
}

/* 4AB0C 8016F30C -O2 -msoft-float */
void fix_mit_Xspeed(Obj *obj, s16 param_2)
{
    s16 spd_x;
    ObjState *eta;
    s32 unk_1;

    if (obj->main_etat == 1 || obj->main_etat == 2)
    {
        if (ray_over_mit(obj, param_2))
        {
            if (obj->main_etat == 2 && obj->speed_y < -2 && obj->sub_etat != 0)
                obj->speed_y++;
            else
                HAS_MIT_JUMP(obj);
            
            if (!(obj->flags & FLG(OBJ_FLIP_X)))
                spd_x = 4;
            else
                spd_x = -4;
            obj->speed_x = spd_x;
        }
        else
        {
            obj->speed_x = -ray.speed_x;
            if (obj->x_pos < obj->init_x_pos && (obj->flags & FLG(OBJ_FLIP_X)))
            {
                if (obj->speed_x < 0)
                    obj->speed_x = 0;
                else
                    obj->speed_x *= 2;
                    
            }
            else if ((obj->x_pos > obj->init_x_pos) && !(obj->flags & FLG(OBJ_FLIP_X)))
            {
                if (obj->speed_x > 0)
                    obj->speed_x = 0;
                else
                    obj->speed_x *= 2;
            }
        }

        if (obj->main_etat == 1)
        {
            eta = &obj->eta[obj->main_etat][obj->sub_etat];
            unk_1 =
                (!(obj->flags & FLG(OBJ_FLIP_X)) && obj->speed_x > 0) ||
                (obj->flags & FLG(OBJ_FLIP_X) && obj->speed_x < 0);
            eta->flags = eta->flags & ~FLG(4) | (unk_1 << 4);
        }

        if (obj->speed_x > 4)
            obj->speed_x = 4;
        else if (obj->speed_x < -4)
            obj->speed_x = -4;
    }
    else
        SET_X_SPEED(obj);
}

INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_ATTAK);

/* 4B154 8016F954 -O2 -msoft-float */
u8 IS_MIT_PAF(Obj *obj)
{
    s16 unk_x_1;
    s16 unk_x_2;
    s16 unk_x_3;
    s16 spd_x;
    s32 res = false;
    
    if (obj->main_etat == 0 && obj->sub_etat == 3)
    {
        obj->speed_y = -4;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        res = true;
    }
    else if (
        (obj->main_etat == 1 && obj->sub_etat == 2) ||
        (obj->main_etat == 0 && (obj->sub_etat == 2 || obj->sub_etat == 4)) ||
        (obj->main_etat == 2 && obj->sub_etat == 2)
    )
    {
        res = true;
        if(EOA(obj))
            obj->field20_0x36 = 0;
        else
        {
            if (obj->main_etat != 2)
                SET_X_SPEED(obj);
            else
            {
                obj->speed_y = 0;
                if (obj->field20_0x36 >= 500)
                {
                    unk_x_1 = obj->x_pos;
                    unk_x_2 = obj->follow_x;
                    if (unk_x_1 - unk_x_2 >= 0)
                        unk_x_3 = unk_x_1 - unk_x_2;
                    else
                        unk_x_3 = unk_x_2 - unk_x_1;
                    
                    if (unk_x_3 < 8)
                    {
                        if (!(obj->flags & FLG(OBJ_FLIP_X)))
                            obj->speed_x--;
                        else
                            obj->speed_x++;
                    }
                    else
                    {
                        if (!(obj->flags & FLG(OBJ_FLIP_X)))
                            spd_x = 4;
                        else
                            spd_x = -4;
                        obj->speed_x = spd_x;
                    }
                }
            }
        }
    }

    return res;
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_COMMAND);
#else
/* matches, but new_var */
/*INCLUDE_ASM("asm/nonmatchings/obj/mite", DO_MIT_COMMAND);*/

void DO_MIT_COMMAND(Obj *obj)
{
    s16 diff_x_1;
    s16 diff_x_2;
    s16 diff_y_1;
    Obj *poing_obj;
    s16 esquive_x;
    s32 prev_flip_x;
    s32 new_var;
    ObjState *obj_eta = &obj->eta[obj->main_etat][obj->sub_etat];
    
    if (!IS_MIT_PAF(obj))
    {
        if (obj->field20_0x36 >= 500)
        {
            DO_MIT_ATTAK(obj);
            return;
        }

        if (!(obj->main_etat == 0 && obj->sub_etat == 7))
        {
            if (obj->cmd == GO_LEFT)
                obj->flags &= ~FLG(OBJ_FLIP_X);
            else if (obj->cmd == GO_RIGHT)
                obj->flags |= FLG(OBJ_FLIP_X);
            
            if (obj->detect_zone_flag != 0)
            {
                diff_x_1 = (ray.x_pos + ray.offset_bx) - obj->x_pos - obj->offset_bx;
                diff_x_2 = __builtin_abs(diff_x_1) >> 1;
                diff_y_1 = (obj->y_pos + obj->offset_by) - ray.y_pos - ray.offset_by;
                obj->field20_0x36++;
                if (ray_over_mit(obj, diff_x_1))
                {
                    if (obj->main_etat == 0 && obj->sub_etat == 10)
                        set_sub_etat(obj, 12);
                    else
                        HAS_MIT_JUMP(obj);
                }
                else if (poing.is_active || poing.is_charging)
                {
                    poing_obj = &level.objects[poing_obj_id];
                    mite_esquive_poing(obj, &esquive_x);
                    /* TODO: ??? readable ??? */
                    if (
                        !(obj->flags & FLG(OBJ_FLIP_X)) ?
                            (diff_x_1 < -10 && (-diff_x_2 < esquive_x || poing_obj->speed_x >= 0)) :
                            (diff_x_1 > 10 && (diff_x_2 > esquive_x || poing_obj->speed_x <= 0))
                    )
                    {
                        if (obj->speed_y < 0)
                            HAS_MIT_JUMP(obj);
                        else if (obj_eta->flags & FLG(2))
                            set_main_and_sub_etat(obj, 0, 9);
                    }
                    else
                    {
                        if (obj->main_etat == 0 && obj->sub_etat == 10)
                            set_sub_etat(obj, 12);
                    }

                    MAX_2(obj->speed_y, -3);
                    MIN_2(obj->speed_y, 3);
                }
                else
                {
                    switch (ray.main_etat)
                    {
                    case 0:
                    case 3:
                        if (
                            obj->main_etat == 1 ||
                            (obj->main_etat == 0 && obj->sub_etat == 10)
                        )
                            set_main_and_sub_etat(obj, 0, 8);
                        
                        obj->speed_x = 0;
                        break;
                    case 1:
                        /* TODO: ??? */
                        if (
                            !(
                                obj->main_etat == 2 ||
                                (obj->main_etat == 0 && (obj->sub_etat == 9 || (obj->sub_etat == (new_var = 0x0A)) || obj->sub_etat == 0x0B))
                            )
                        )
                            set_main_and_sub_etat(obj, 1, 0);
                        break;
                    case 2:
                        if (HAS_MIT_JUMP(obj))
                        {
                            if (diff_y_1 > 0)
                            {
                                if (obj->gravity_value_1 == 1)
                                {
                                    obj->speed_y--;
                                    MAX_2(obj->speed_y, -3);
                                }
                            }
                            else
                                MIN_2(obj->speed_y, 1);
                        }
                        break;
                    }
                }

                if (
                    diff_x_2 < 40 && diff_y_1 < 10 &&
                    obj->field24_0x3e == 0 && obj_eta->flags & FLG(1)
                )
                {
                    if (obj->main_etat == 1)
                        set_main_etat(obj, 0);
                    
                    set_sub_etat(obj, 11);
                    obj->field24_0x3e = 1;
                    obj->timer = 0;
                }

                if (obj->field24_0x3e == 1)
                {
                    obj->timer++;
                    if (obj->timer > 40)
                        obj->field24_0x3e = 0;
                }

                if (obj->y_pos + obj->offset_hy < ymap - 50)
                    obj->speed_y += 2;
                
                fix_mit_Xspeed(obj, diff_x_1);
            }
            else
            {
                obj->speed_x = 0;
                if (obj->main_etat != 2)
                {
                    if (obj->main_etat == 1)
                    {
                        set_main_and_sub_etat(obj, 0, 8);
                        skipToLabel(obj, 7, true);
                    }

                    prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
                    calc_obj_dir(obj);
                    if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                        skipToLabel(obj, 3, true);
                }
            }

            if (block_flags[obj->btypes[3]] >> BLOCK_FULLY_SOLID & 1)
                obj->speed_y = 0;
            
            if (block_flags[calc_typ_travd(obj, false)] >> BLOCK_FULLY_SOLID & 1)
                obj->speed_x = 0;
            
            if (obj->main_etat != 2)
                CALC_MOV_ON_BLOC(obj);
        }
    }
}
#endif

/* 4BA08 80170208 -O2 -msoft-float */
void DO_MITE2_COMMAND(Obj *obj)
{
    s16 unk_1;

    if (obj->main_etat == 0 && obj->sub_etat == 3)
    {
        obj->speed_x = 0;
        obj->speed_y = -8;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
    }
    else
    {
        DO_MITE2_ESQUIVE(obj);
        if (obj->field20_0x36 != 0 && HAS_MIT_JUMP(obj))
        {
            if (!(obj->flags & FLG(OBJ_FLIP_X)))
                obj->speed_x = -2;
            else
                obj->speed_x = 2;
        }

        if (obj->main_etat != 2)
        {
            if (on_block_chdir(obj, obj->offset_bx, obj->offset_by - 16))
            {
                obj->field20_0x36 = 502;
                obj->speed_x = 0;
            }
            SET_X_SPEED(obj);
            CALC_MOV_ON_BLOC(obj);
        }
        
        unk_1 = calc_typ_travd(obj, false);
        if (obj->main_etat == 2)
        {
            if (
                block_flags[
                    PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx, obj->y_pos + obj->offset_hy)
                ] >> BLOCK_FULLY_SOLID & 1 &&
                obj->speed_y < 0
            )
                obj->speed_y = 1;
        }
        else
        {
            if (!(block_flags[obj->btypes[4]] >> BLOCK_SOLID & 1))
            {
                set_main_and_sub_etat(obj, 2, 0);
                skipToLabel(obj, 7, true);
            }
        }

        if (block_flags[unk_1] & 1)
        {
            if (obj->main_etat == 1)
                makeUturn(obj);
            else
            {
                obj->flags =
                    (obj->flags & ~FLG(OBJ_FLIP_X)) |
                    (((1 - (obj->flags >> OBJ_FLIP_X & 1)) & 1) << OBJ_FLIP_X);
                obj->speed_x = -obj->speed_x;
            }
        }
    }
}
