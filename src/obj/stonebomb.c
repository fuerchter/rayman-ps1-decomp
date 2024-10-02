#include "obj/stonebomb.h"

void DO_STONEMAN_COMMAND(Obj *obj);

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

INCLUDE_ASM("asm/nonmatchings/obj/stonebomb", allocateStonewomanStone);

INCLUDE_ASM("asm/nonmatchings/obj/stonebomb", DO_STONEWOMAN_TIR);
