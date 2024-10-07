#include "obj/nen_graine.h"

/* 39B90 8015E390 -O2 -msoft-float */
void DO_GROWING_PLATFORM(void)
{
    Obj *oldest_obj;
    u8 main_etat; u8 sub_etat;

    if (D_801CF408 != true)
        D_801CF408 = false;
    
    if (ray.anim_frame == ray.animations[ray.anim_index].frames_count - 1)
    {
        if (D_801CF408 == false)
        {
            oldest_obj = oldest_planted();
            if (oldest_obj->flags & FLG(OBJ_ACTIVE))
                DO_NOVA(oldest_obj);
            
            oldest_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            main_etat = 0;
            sub_etat = 38;
            set_main_and_sub_etat(oldest_obj, main_etat, sub_etat);
            oldest_obj->anim_frame = 0;
            oldest_obj->anim_index = oldest_obj->eta[main_etat][sub_etat].anim_index;
            oldest_obj->x_pos = (ray.x_pos + ray.offset_bx) - oldest_obj->offset_bx;
            oldest_obj->y_pos = (ray.y_pos + ray.offset_by) - oldest_obj->offset_by;
            calc_obj_pos(oldest_obj);
            D_801CF408 = true;
        }
    }
    else
        D_801CF408 = false;
}
