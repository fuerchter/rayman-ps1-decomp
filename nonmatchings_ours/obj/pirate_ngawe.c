#include "obj/pirate_ngawe.h"

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