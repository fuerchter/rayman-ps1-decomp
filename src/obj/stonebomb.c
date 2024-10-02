#include "obj/stonebomb.h"

/* 38118 8015C918 -O2 -msoft-float */
void setStoneChipPos(Obj *param_1, Obj *param_2, u8 *param_3)
{
    if (!*param_3)
    {
        param_2->x_pos = (param_1->x_pos + param_1->offset_bx) - param_2->offset_bx;
        param_2->y_pos = (param_1->y_pos + param_1->offset_by) - param_2->offset_by;
        switch (param_2->sub_etat)
        {
        case 9:
            param_2->x_pos -= (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos -= param_2->offset_by + param_2->offset_by / 3;
            break;
        case 10:
            param_2->x_pos += (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos -= param_2->offset_by + param_2->offset_by / 3;
            break;
        case 11:
            param_2->x_pos -= (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos -= param_2->offset_by;
            break;
        case 12:
            param_2->x_pos += (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos -= param_2->offset_by;
            break;
        case 13:
            param_2->x_pos -= (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos += param_2->offset_by / 3 - param_2->offset_by;
            break;
        case 14:
            param_2->x_pos += (param_2->offset_bx >> 1) - param_2->offset_bx;
            param_2->y_pos += param_2->offset_by / 3 - param_2->offset_by;
            break;
        }
        calc_obj_pos(param_2);
        param_2->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
        param_2->flags &= ~FLG(OBJ_FLAG_9);
        *param_3 = true;
    }
}

/* 383B0 8015CBB0 -O2 -msoft-float */
void allocateStoneChips(Obj *in_obj)
{
    u8 se_1;
    u8 se_2;
    u8 se_3;
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;
    u8 sub_etat;
    u8 unk_par_3 = false;
    u8 unk_par_2 = false;
    u8 unk_par_1 = false;

    switch (in_obj->speed_x > 0)
    {
    case false:
        se_1 = 10;
        se_2 = 12;
        se_3 = 14;
        break;
    case true:
        se_1 = 9;
        se_2 = 11;
        se_3 = 13;
        break;
    }
    
    i = 0;
    cur_obj = &level.objects[i];
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_STONECHIP && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            sub_etat = cur_obj->sub_etat;
            if (sub_etat == se_1)
                setStoneChipPos(in_obj, cur_obj, &unk_par_1);
            else if (sub_etat == se_2)
                setStoneChipPos(in_obj, cur_obj, &unk_par_2);
            else if (sub_etat == se_3)
                setStoneChipPos(in_obj, cur_obj, &unk_par_3);
        }
        cur_obj++;
        i++;
    }
}

/* 38514 8015CD14 -O2 -msoft-float */
void DO_STONE_EXPLOSION(Obj *obj)
{
    PlaySnd_old(84);
    if (obj->flags & FLG(OBJ_ACTIVE))
    {
        if (obj->main_etat == 2 && obj->sub_etat == 1)
        {
            obj->x_pos += 20;
            obj->speed_x = -1;
            allocateStoneChips(obj);
            obj->x_pos -= 20;
            obj->speed_x = 1;
            allocateStoneChips(obj);
            obj->x_pos += 10;
        }
        else
            allocateStoneChips(obj);

        obj->flags &= ~FLG(OBJ_ACTIVE);
        if (obj->type == TYPE_STONEBOMB)
            obj->flags &= ~FLG(OBJ_ALIVE);
        else
            obj->y_pos = ymap + 484;
        
        allocateExplosion(obj);
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/stonebomb", DO_TIR);

INCLUDE_ASM("asm/nonmatchings/obj/stonebomb", allocateStonemanStone);

/* 38CDC 8015D4DC -O2 -msoft-float */
void DO_STONEMAN1_TIR(Obj *obj)
{
    u8 flag_set;

    DO_STONEMAN_COMMAND(obj);
    if (obj->main_etat == 0)
    {
        if (!(obj->sub_etat == 2 && obj->anim_frame >= 144))
            obj->field24_0x3e = 0;
        
        if (obj->sub_etat == 1 || obj->sub_etat == 2)
        {
            flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
            if(
                ((flag_set && obj->anim_frame == 0) ||
                (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
            )
            {
                if (obj->detect_zone_flag != 0)
                    skipToLabel(obj, 7, true);
                else
                    skipToLabel(obj, 8, true);
            }
        }

        if (
            obj->sub_etat == 2 && obj->field24_0x3e == 0 && obj->anim_frame == 144 &&
            horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
        )
        {
            allocateStonemanStone(obj, -2, true);
            obj->field24_0x3e = 1;
        }
    }
    else
        obj->field24_0x3e = 0;
}

/* 38EC0 8015D6C0 -O2 -msoft-float */
void DO_STONEMAN2_TIR(Obj *obj)
{
    u8 flag_set;
    s32 unk_1;

    DO_STONEMAN_COMMAND(obj);
    if (obj->main_etat == 0)
    {
        if (obj->sub_etat != 6)
            obj->field24_0x3e = 0;
        
        if (obj->sub_etat == 1 || obj->sub_etat == 6)
        {
            flag_set = obj->eta[obj->main_etat][obj->sub_etat].flags & 0x10;
            if(
                ((flag_set && obj->anim_frame == 0) ||
                (!flag_set && obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1)) &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
            )
            {
                    if (obj->detect_zone_flag != 0)
                        skipToLabel(obj, 7, true);
                    else
                        skipToLabel(obj, 8, true);
            }

            if ((obj->sub_etat == 6) && (obj->field24_0x3e == 0))
            {
                unk_1 = obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf;
                if (horloge[unk_1] == unk_1 - 1)
                {
                    allocateStonemanStone(obj, 0, true);
                    obj->field24_0x3e = 1;
                }
            }
        }
    }
    else
        obj->field24_0x3e = 0;
}

/* 3907C 8015D87C -O2 -msoft-float */
void allocateStonewomanStone(Obj *stwmn_obj, s16 param_2)
{
    s16 sprite;
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 spd_x; s16 spd_y;
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;
    
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_STONEBOMB && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->timer = 200;
            if (param_2 != 0)
                cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLIP_X)) | (stwmn_obj->flags & FLG(OBJ_FLIP_X));
            else
                cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLIP_X)) | (((stwmn_obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X);
            
            sprite = -1;
            if (stwmn_obj->main_etat == 0)
            {
                if (stwmn_obj->sub_etat == 13)
                {
                    if (stwmn_obj->anim_frame - 52 < 50U)
                        sprite = 3;
                }
                else if (stwmn_obj->sub_etat == 9)
                {
                    if (stwmn_obj->anim_frame - 16 < 40U)
                        sprite = 3;
                }
            }
            
            if (sprite != -1)
            {
                GET_SPRITE_POS(stwmn_obj, sprite, &spr_x, &spr_y, &spr_w, &spr_h);
                switch (param_2)
                {
                case 0:
                    spd_y = -2;
                    stwmn_obj->hit_points += poing.damage - 1;
                    break;
                case 1:
                    spd_y = 1;
                    break;
                case 2:
                    if (ray.main_etat == 2)
                    {
                        cur_obj->follow_x = D_801E51E8;
                        cur_obj->follow_y = D_801E51F8;
                    }
                    else
                    {
                        cur_obj->follow_x = ray.x_pos;
                        cur_obj->follow_y = ray.y_pos;
                    }
                    break;
                }
                cur_obj->x_pos = spr_x - cur_obj->offset_bx + (spr_w >> 1);
                cur_obj->y_pos = spr_y - cur_obj->offset_hy;
                cur_obj->init_x_pos = cur_obj->x_pos;
                cur_obj->init_y_pos = cur_obj->y_pos;
                if (param_2 != 2)
                {
                    if (!(cur_obj->flags & FLG(OBJ_FLIP_X)))
                        spd_x = (s16) cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].speed_x_left;
                    else
                        spd_x = (s16) cur_obj->eta[cur_obj->main_etat][cur_obj->sub_etat].speed_x_right;
                    SET_X_SPEED(cur_obj);
                    set_sub_etat(cur_obj, 0);
                }
                else
                {
                    set_sub_etat(cur_obj, 1);
                    Projectil_to_RM(cur_obj, &spd_x, &spd_y, 30, 3);
                }

                cur_obj->speed_x = spd_x;
                cur_obj->speed_y = spd_y;
                calc_obj_pos(cur_obj);
                cur_obj->gravity_value_1 = 0;
                cur_obj->gravity_value_2 = 7;
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                cur_obj->flags &= ~FLG(OBJ_FLAG_9);
            }
            break;
        }
        cur_obj++;
        i++;
    }
}

/* 393E4 8015DBE4 -O2 -msoft-float */
void DO_STONEWOMAN_TIR(Obj *obj)
{
    if (obj->main_etat == 0)
    {
        if (
            !(obj->sub_etat == 13 && obj->anim_frame > 100) &&
            !(obj->sub_etat == 9 && obj->anim_frame > 54)
        )
            obj->field24_0x3e = 0;
        
        if (
            (obj->sub_etat == 0 || obj->sub_etat == 14 || obj->sub_etat == 8) &&
            obj->anim_frame == 0
        )
        {
            if (obj->detect_zone_flag > 1)
                skipToLabel(obj, 7, true);
            else
                skipToLabel(obj, 12, true);
        }

        if (obj->sub_etat == 13)
        {
            if (
                obj->field24_0x3e == 0 && obj->anim_frame == 101 &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
            )
            {
                allocateStonewomanStone(obj, 1);
                obj->field24_0x3e = 1;
            }
        }
        else if (obj->sub_etat == 9)
        {
            if (
                obj->field24_0x3e == 0 && obj->anim_frame == 55 &&
                horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
            )
            {
                allocateStonewomanStone(obj, 2);
                obj->field24_0x3e = 1;
            }
        }
    }
    else
        obj->field24_0x3e = 0;
}
