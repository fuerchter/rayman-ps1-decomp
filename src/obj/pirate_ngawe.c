#include "obj/pirate_ngawe.h"

/* 78988 8019D188 -O2 -msoft-float */
void ngaweFollowsShip(Obj *obj)
{
    if (bateau_obj_id != -1)
        snapToSprite(obj, &level.objects[bateau_obj_id], 2, 21, -51);
}

/* 789DC 8019D1DC -O2 -msoft-float */
void ngaweTriesToGrabShip(Obj *obj)
{
    s16 ship_x; s16 ship_y; s16 ship_w; s16 ship_h;

    if (bateau_obj_id != -1)
    {
        GET_SPRITE_POS(&level.objects[bateau_obj_id], 2, &ship_x, &ship_y, &ship_w, &ship_h);
        obj->x_pos = ship_x + 21;
        ship_h = ship_y - 67;
        if ((obj->y_pos >= ship_h - obj->speed_y) && (obj->y_pos <= ship_h + obj->speed_y))
            set_main_and_sub_etat(obj, 2, 2);
    }
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", allocatePirateNgaweRing);
#else
/* matches, but clean up */
/*INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", allocatePirateNgaweRing);*/

void allocatePirateNgaweRing(Obj *param_1, s16 param_2, u8 param_3)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    Obj *cur_obj;
    Obj *var_s0;
    s16 temp_v0;
    s16 i;
    s32 var_v0;
    s32 var_v0_2;
    s32 temp_a2;
    u16 temp_v1;
    u32 temp_a0;
    s16 nb_objs;
    
    i = 0;
    cur_obj = &level.objects[i];
    nb_objs = level.nb_objects;
    while (i < nb_objs)
    {
        if (cur_obj->type == 0x49)
        {
            temp_a0 = cur_obj->flags;
            if (!(temp_a0 & 0x800))
            {
                if (param_3 & 0xFF)
                {
                    cur_obj->flags = ((temp_a0 & ~0x4000) | (param_1->flags & 0x4000));
                }
                else
                {
                    cur_obj->flags = ((temp_a0 & ~0x4000) | ((((param_1->flags >> 0xE) ^ 1) & 1) << 0xE));
                }
                cur_obj->speed_y = param_2;
                GET_SPRITE_POS(param_1, 6, &sp18, &sp1A, &sp1C, &sp1E);
                temp_v1 = sp18 - cur_obj->offset_bx;
                cur_obj->x_pos = temp_v1;
                if (param_1->flags & 0x4000)
                {
                    cur_obj->x_pos = (temp_v1 + sp1C);
                }
                cur_obj->y_pos = (sp1A - ((cur_obj->offset_hy + cur_obj->offset_by) >> 1));
                skipToLabel(cur_obj, (cur_obj->flags >> 0xE) & 1, 1U);
                calc_obj_pos(cur_obj);
                cur_obj->flags |= 0xC00;
                cur_obj->flags = (cur_obj->flags & ~FLG(OBJ_FLAG_9));
                var_v0 = (s16) (((ray.offset_bx + ray.x_pos) - cur_obj->x_pos) - cur_obj->offset_bx);
                if (!(cur_obj->flags & 0x4000))
                {
                    var_v0 = -var_v0;
                }
                var_v0 = (s16) var_v0; /* ??? */
                if (var_v0 < 0)
                {
                    var_v0 = 0;
                }
                cur_obj->field24_0x3e = (var_v0 + 0xF);
                cur_obj->flags &= ~0x100;
                cur_obj->flags &= ~0x200;
                cur_obj->field23_0x3c = param_1->id;
                param_1->field56_0x69--;
                break;
            }
        }
        cur_obj += 1;
        i = i + 1;
    }
}
#endif

/* 78CA4 8019D4A4 -O2 -msoft-float */
void DO_NGW_TIR(Obj *obj)
{
    if (obj->anim_frame < 26)
        obj->field24_0x3e = 0;
    
    if (
        obj->field24_0x3e == 0 && obj->anim_frame == 26 &&
        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
    {
        allocatePirateNgaweRing(obj, 0, 1);
        obj->field24_0x3e = 1;
    }
}

/* 78D58 8019D558 -O2 -msoft-float */
void NGW_REACT_TO_RAY_IN_ZONE(Obj *obj)
{
    if (
        (
            (obj->main_etat == 0 && obj->sub_etat == 0) ||
            (obj->main_etat == 1 && obj->sub_etat == 0)
        ) && obj->field56_0x69 != 0
    )
        set_main_and_sub_etat(obj, 0, 2);
}

/* 78DC0 8019D5C0 -O2 -msoft-float */
void DO_ONE_NGW_COMMAND(Obj *obj)
{
    s32 prev_flip_x = obj->flags >> OBJ_FLIP_X & 1;
    
    calc_obj_dir(obj);
    switch (obj->main_etat * 0x100 + obj->sub_etat)
    {
    case 0x3:
        obj->speed_y = -8;
        obj->speed_x = 0;
        break;
    case 0x205:
    case 0x5:
        obj->speed_x = 0;
        break;
    case 0x0:
        obj->speed_x = 0;
        if (!poing.is_active)
        {
            if (obj->field56_0x69 == 1)
            {
                if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                    set_sub_etat(obj, 6);
                else
                    set_main_and_sub_etat(obj, 1, 0);
            }
            else
                obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        }
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x2:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (!poing.is_active)
            DO_NGW_TIR(obj);
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x100:
        if (!poing.is_active)
        {
            if (obj->field56_0x69 == 1)
            {
                if (
                    (block_flags[calc_typ_travd(obj, true)] >> BLOCK_FULLY_SOLID & 1) ||
                    !((u8) block_flags[
                        PS1_BTYPAbsPos(obj->x_pos + obj->offset_bx + obj->speed_x, obj->y_pos + obj->offset_by)
                    ] >> BLOCK_SOLID & 1)
                )
                    if (prev_flip_x == (obj->flags >> OBJ_FLIP_X & 1))
                        prev_flip_x = (obj->flags >> OBJ_FLIP_X ^ 1) & 1;
                
                if ((obj->flags >> OBJ_FLIP_X & 1) != prev_flip_x)
                    set_main_and_sub_etat(obj, 0, 6);
                
                SET_X_SPEED(obj);
                CALC_MOV_ON_BLOC(obj);
            }
            else
                set_main_and_sub_etat(obj, 0, 0);
        }
        else
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x207:
        ngaweTriesToGrabShip(obj);
        break;
    case 0x202:
    case 0x203:
    case 0x204:
        ngaweFollowsShip(obj);
        break;
    case 0x6:
    case 0x4:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (poing.is_active)
            set_main_and_sub_etat(obj, 0, 7);
        break;
    case 0x8:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        if (!poing.is_active)
            set_sub_etat(obj, 4);
        break;
    case 0x7:
        obj->speed_x = 0;
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (prev_flip_x << OBJ_FLIP_X);
        break;
    case 0x1:
        obj->timer = 100;
        obj->speed_x = 0;
        break;
    }

    if (obj->timer != 0)
        obj->timer--;
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", DO_NGW_POING_COLLISION);
#else
/* matches, but merge the two ~0x4000s somehow? */
/*INCLUDE_ASM("asm/nonmatchings/obj/pirate_ngawe", DO_NGW_POING_COLLISION);*/

void DO_NGW_POING_COLLISION(Obj *ngw_obj)
{
    Obj *poing_obj = &level.objects[poing_obj_id];

    if (ngw_obj->timer == 0)
    {
        poing.damage = true;
        obj_hurt(ngw_obj);
        if (ngw_obj->hit_points == 0)
        {
            set_main_and_sub_etat(ngw_obj, 0, 3);
            if (bateau_obj_id != -1)
            {
                skipOneCommand(&level.objects[bateau_obj_id]);
                level.objects[bateau_obj_id].nb_cmd = 0;
            }
        }
        else
        {
            if (poing_obj->speed_x > 0)
                ngw_obj->flags &= ~0x4000;
            else if ((poing_obj->speed_x >= 0) && (poing_obj->flags & 0x4000))
                ngw_obj->flags &= ~0x4000;
            else
                ngw_obj->flags |= 0x4000;
            set_main_and_sub_etat(ngw_obj, 0, 1);
        }
    }
}
#endif

/* 79290 8019DA90 -O2 -msoft-float */
void DO_ONE_NGW_RING_COMMAND(Obj *ring_obj)
{
    Obj *unk_obj = &level.objects[ring_obj->field23_0x3c];
    
    if (!(unk_obj->flags & FLG(OBJ_ACTIVE)))
    {
        ring_obj->flags = ring_obj->flags & ~FLG(OBJ_ALIVE);
        DO_NOVA(ring_obj);
        return;
    }

    if (ring_obj->field24_0x3e <= 0)
    {
        if (ring_obj->flags & FLG(OBJ_FLAG_0))
        {
            ring_obj->flags &= ~FLG(OBJ_ACTIVE);
            ring_obj->flags &= ~FLG(OBJ_ALIVE);
            unk_obj->field56_0x69++;
        }
        else
        {
            ring_obj->flags |= FLG(OBJ_FLAG_0)|FLG(OBJ_CMD_TEST);
            ring_obj->field24_0x3e = __builtin_abs(
                (s16) ((ring_obj->offset_bx + ring_obj->x_pos) - unk_obj->x_pos - unk_obj->offset_bx)
            );
        }
        return;
    }

    ring_obj->flags &= ~FLG(OBJ_CMD_TEST);
    if (ring_obj->cmd == GO_SPEED)
    {
        ring_obj->speed_x = ring_obj->iframes_timer;
        if (ring_obj->field20_0x36 != 0)
            ring_obj->speed_y = ring_obj->field20_0x36;
        else
        {
            if (ring_obj->flags & FLG(OBJ_FLAG_0))
            {
                unk_obj = &level.objects[ring_obj->field23_0x3c];
                ring_obj->field24_0x3e =
                    (unk_obj->offset_bx + unk_obj->x_pos) - ring_obj->x_pos - ring_obj->offset_bx;
                ring_obj->speed_y =
                    (
                        unk_obj->y_pos + ((unk_obj->offset_by + unk_obj->offset_hy) >> 1) -
                        (ring_obj->y_pos + ((ring_obj->offset_by + ring_obj->offset_hy) >> 1))
                    ) * ring_obj->speed_x;
                if (ring_obj->field24_0x3e != 0)
                    ring_obj->speed_y /= ring_obj->field24_0x3e;

                ring_obj->field24_0x3e = __builtin_abs(ring_obj->field24_0x3e);
            }
            ring_obj->field24_0x3e -= instantSpeed(__builtin_abs(ring_obj->speed_x));
        }
    }
}
