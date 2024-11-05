#include "obj/black_ray_command.h"

#ifdef BSS_DEFS
RayStack rayStack[101];
u8 black_pos_in_stack;
s16 black_ray_obj_id;
s16 black_fist_obj_id;
#endif

/* 4F364 80173B64 -O2 -msoft-float */
void doBlackRaymanCommand(Obj *br_obj)
{
    Obj *fist_obj;
    RayStack *br_stack;

    if (br_obj->main_etat == 0 && br_obj->sub_etat == 54)
    {
        if (EOA(br_obj))
        {
            br_obj->flags &= ~FLG(OBJ_ACTIVE);
            br_obj->flags &= ~FLG(OBJ_ALIVE);
        }
        else if (br_obj->anim_frame == 0)
        {
            DO_NOVA(br_obj);
        }
        DO_ANIM(br_obj);
        return;
    }

    if (
        (ray.main_etat == 3 && ray.sub_etat == 23) ||
        (ray_mode == MODE_MORT_DE_RAYMAN && !(ray.main_etat == 2 && ray.sub_etat == 31))
    )
    {
        if (firstFloorBelow(br_obj) - br_obj->offset_by - br_obj->y_pos <= 32)
        {
            br_obj->y_pos = firstFloorBelow(br_obj) - br_obj->offset_by;
            set_main_and_sub_etat(br_obj, 0, 54);
            br_obj->anim_index = 107;
            br_obj->anim_frame = 0;
        }
        else
        {
            br_obj->flags &= ~FLG(OBJ_ACTIVE);
            br_obj->flags &= ~FLG(OBJ_ALIVE);
        }
        br_obj->speed_x = 0;
        br_obj->speed_y = 0;
        DO_NOVA(br_obj);
        fist_obj = &level.objects[black_fist_obj_id];
        fist_obj->flags &= ~FLG(OBJ_ACTIVE);
        fist_obj->flags &= ~FLG(OBJ_ALIVE);
        return;
    }

    if (ray_stack_is_full)
    {
        if (black_pos_in_stack == ray_pos_in_stack - 1)
        {
            fist_obj = &level.objects[black_fist_obj_id];
            br_obj->flags &= ~FLG(OBJ_ALIVE);
            fist_obj->flags &= ~FLG(OBJ_ALIVE);
            DO_NOVA(br_obj);
            if (fist_obj->flags & FLG(OBJ_ACTIVE))
                DO_NOVA(fist_obj);
        }
        else
        {
            br_stack = &rayStack[black_pos_in_stack];
            br_obj->x_pos = br_stack->x_pos;
            br_obj->y_pos = br_stack->y_pos;
            br_obj->main_etat = br_stack->main_etat;
            br_obj->sub_etat = br_stack->sub_etat;
            br_obj->anim_index = br_stack->anim_index;
            br_obj->anim_frame = br_stack->anim_frame;
            br_obj->flags = (br_obj->flags & ~FLG(OBJ_FLIP_X)) | ((br_stack->flip_x & 1) << OBJ_FLIP_X);
            br_obj->scale = br_stack->scale;
            br_obj->speed_x = 0;
            br_obj->speed_y = 0;
            if (br_obj->display_prio == 0)
                DO_NOVA(br_obj);

            br_obj->display_prio = 4;
            fist_obj = &level.objects[black_fist_obj_id];
            if (br_stack->poing_is_active)
            {
                fist_obj->display_prio = 4;
                fist_obj->flags |= FLG(OBJ_ALIVE);
                fist_obj->x_pos = br_stack->poing_x_pos;
                fist_obj->y_pos = br_stack->poing_y_pos;
                fist_obj->anim_index = br_stack->poing_anim_index;
                fist_obj->anim_frame = br_stack->poing_anim_frame;
                fist_obj->flags = (fist_obj->flags & ~FLG(OBJ_FLIP_X)) | ((br_stack->poing_flip_x & 1) << OBJ_FLIP_X);
                fist_obj->speed_x = 0;
                fist_obj->speed_y = 0;
            }
            else
                fist_obj->flags &= ~FLG(OBJ_ALIVE);

            black_pos_in_stack++;
            if (black_pos_in_stack > LEN(rayStack) - 1)
                black_pos_in_stack = 0;
        }
    }
    else
    {
        br_obj->display_prio = 0;
        level.objects[black_fist_obj_id].flags &= ~FLG(OBJ_ALIVE);
    }
}
